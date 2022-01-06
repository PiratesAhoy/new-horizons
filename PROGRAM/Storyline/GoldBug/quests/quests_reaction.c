
GetTime(){ return stf(Environment.time); }

void QuestComplete(string sQuestName)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
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

	int gp;
	int pb;
	int pg;
	int mb;
	
	int iNation = sti(PChar.nation);

	float u, v, w;
	float kx, ky, kz;	//Kidd pos

	int na, peg;
	

	//Log_SetStringToLog("Quest " + sQuestName + " completed");
	//trace("=============================================== QUEST " + sQuestName + " CHECKED");

	switch(sQuestName)
	{
		case "box_enabled":
			LAi_QuestDelay("box_enabled1", 1.0);
		break;

		case "box_enabled1":
			Pchar.quest.box_blocked = "no";
		break;

		case "bessop_plantation_no_reinc":
			if(pchar.location == "bessop_plantation")
			{
				if(LAi_IsDead(Pchar))
				{
					LAi_QuestDelay("delay_no_reinc", 3.0);
				}
				else LAi_QuestDelay("bessop_plantation_no_reinc", 1.0);
			}
			else return;
		break;

		case "delay_no_reinc":
			GameOverOrg("land");
		break;

		case "quicksave":
			DoQuickSave();
		break;

		case "Pchar_laytype":
			LAi_SetLayType(Pchar);
		break;

		case "Pchar_poortype":
			LAi_SetPoorType(Pchar);
		break;
			
		case "Pchar_sittype":
			LAi_SetSitType(Pchar);
		break;

		case "Pchar_staytype":
			LAi_SetStayType(Pchar);
		break;

		case "Pchar_playertype":
			LAi_SetPlayerType(Pchar);
		break;

		case "pchar_huh":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		break;

		case "pchar_hah":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		break;

		case "pchar_yah":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
		break;

		case "pchar_sigh":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		break;

		case "pchar_oh":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
		break;

		case "pchar_ohoh":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		break;

		case "pchar_oooh":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		break;

		case "pchar_puh":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		break;

		case "pchar_very_nice":
			PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		break;

		case "pchar_lets_go":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
		break;

		case "pchar_lead_way_out":
			PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
		break;

		case "pchar_1":
			PlaySound("VOICE\ENGLISH\blaze_1.wav");
		break;

		case "pchar_2":
			PlaySound("VOICE\ENGLISH\blaze_2.wav");
		break;

		case "pchar_3":
			PlaySound("VOICE\ENGLISH\blaze_3.wav");
		break;

		case "pchar_4":
			PlaySound("VOICE\ENGLISH\blaze_4.wav");
		break;

		case "pchar_5":
			PlaySound("VOICE\ENGLISH\blaze_5.wav");
		break;

		case "pchar_6":
			PlaySound("VOICE\ENGLISH\blaze_6.wav");
		break;

		case "drink":
			PlaySound("INTERFACE\drink.wav");
		break;

		case "Poe_very_nice":
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
		break;

		case "Poe_go_on":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
		break;

		case "Poe_look":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
		break;

		case "Poe_simplicity":
			PlaySound("VOICE\ENGLISH\Poe_simplicity.wav");
		break;

		case "Poe_promising":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
		break;

		case "Poe_result":
			PlaySound("VOICE\ENGLISH\Poe_result.wav");
		break;

		case "Poe_ooh":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
		break;

		case "Poe_ok":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
		break;

		case "Poe_and":
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
		break;

		case "Poe_try_again":
			PlaySound("VOICE\ENGLISH\Poe_try_again.wav");
		break;

		case "Poe_obvious":
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
		break;

		case "Poe_trophy":
			PlaySound("VOICE\ENGLISH\Poe_trophy.wav");
		break;

		case "Jupiter_thats_it":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
		break;

		case "Jupiter_bad":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
		break;

		case "Fort_label_2":
			pchar.quest.Fort_label_2B.win_condition.l1 = "locator";
			pchar.quest.Fort_label_2B.win_condition.l1.location = "Fort_M_tower2B";
			pchar.quest.Fort_label_2B.win_condition.l1.locator_group = "box";
			pchar.quest.Fort_label_2B.win_condition.l1.locator = "box1";
			pchar.quest.Fort_label_2B.win_condition = "Fort_label_2B";
		break;

		case "Fort_label_2B":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Fort Moultrie"));
			LAi_QuestDelay("Fort_label_2", 0.1);
		break;

		case "Fort_label_3":
			pchar.quest.Fort_label_3B.win_condition.l1 = "locator";
			pchar.quest.Fort_label_3B.win_condition.l1.location = "Fort_M_tower3B";
			pchar.quest.Fort_label_3B.win_condition.l1.locator_group = "box";
			pchar.quest.Fort_label_3B.win_condition.l1.locator = "box1";
			pchar.quest.Fort_label_3B.win_condition = "Fort_label_3B";
		break;

		case "Fort_label_3B":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Fort Moultrie"));
			LAi_QuestDelay("Fort_label_3", 0.1);
		break;

		case "Tower_label_2":
			pchar.quest.Tower_label_2B.win_condition.l1 = "locator";
			pchar.quest.Tower_label_2B.win_condition.l1.location = "Fort_Moultrie";
			pchar.quest.Tower_label_2B.win_condition.l1.locator_group = "box";
			pchar.quest.Tower_label_2B.win_condition.l1.locator = "box16";
			pchar.quest.Tower_label_2B.win_condition = "Tower_label_2B";
		break;

		case "Tower_label_2B":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"East tower"));
			LAi_QuestDelay("Tower_label_2", 0.1);
		break;

		case "Tower_label_3":
			pchar.quest.Tower_label_3B.win_condition.l1 = "locator";
			pchar.quest.Tower_label_3B.win_condition.l1.location = "Fort_Moultrie";
			pchar.quest.Tower_label_3B.win_condition.l1.locator_group = "box";
			pchar.quest.Tower_label_3B.win_condition.l1.locator = "box11";
			pchar.quest.Tower_label_3B.win_condition = "Tower_label_3B";
		break;

		case "Tower_label_3B":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"South tower"));
			LAi_QuestDelay("Tower_label_2", 0.1);
		break;

		case "prison_stop":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_prison", "goto", "back");
			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\knock.wav");

			LAi_QuestDelay("prison_stop1", 0.5);
		break;

		case "prison_stop1":
			LAi_SetPlayerType(Pchar);

			pchar.quest.prison_stop.win_condition.l1 = "locator";
			pchar.quest.prison_stop.win_condition.l1.location = "Fort_Moultrie_prison";
			pchar.quest.prison_stop.win_condition.l1.locator_group = "goto";
			pchar.quest.prison_stop.win_condition.l1.locator = "stop";
			pchar.quest.prison_stop.win_condition = "prison_stop";	
		break;

		case "look_rock":
			if(Locations[FindLocation(Pchar.location)].type == "deserted_seashore")
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_mountains";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rock_land", "rock_land", 5.5);
			}
			else
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_seashore";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rock_sea", "rock_sea", 5.5);
			}
		break;

		case "look_rockB":
			if(Locations[FindLocation(Pchar.location)].type == "deserted_seashore")
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_mountains";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rockB_land", "rockB_land", 3.5);
			}
			else
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_seashore";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rockB_sea", "rockB_sea", 3.5);
			}
		break;

		case "look_rockC":
			if(Locations[FindLocation(Pchar.location)].type == "deserted_seashore")
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_mountains";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rockC_land", "rockC_land", 5.5);
			}
			else
			{
				PauseAllSounds();
				Locations[FindLocation(Pchar.location)].type = "deserted_seashore";
				PostEvent("LoadSceneSound", 0);

				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "look_rockC_sea", "rockC_sea", 5.5);
			}
		break;

		case "rock_land":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rock_land");
			
			LAi_QuestDelay("BH_sound_type", 0.01);
		break;

		case "rock_sea":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rock_sea");
			
			LAi_QuestDelay("BH_sound_type", 0.01);
		break;

		case "rockB_land":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rockB_land");
			
			LAi_QuestDelay("BH_sound_type", 0.01);
		break;

		case "rockB_sea":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rockB_sea");
			
			LAi_QuestDelay("BH_sound_type", 0.01);
		break;

		case "rockC_land":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rockC_land");
			
			if(CheckAttribute(Pchar,"quest.sketch_cliff_found") && Pchar.quest.sketch_cliff_found == "yes")
			{
				LAi_QuestDelay("BH_sound_type1", 0.01);
			}
			else
			{
				LAi_SetActorType(Pchar);
				LAi_ActorTurnToLocator(Pchar, "goto", "look_rockC");

				LAi_QuestDelay("BH_sound_type", 1.0);
			}
		break;

		case "rockC_sea":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "look_rockC_sea");
			
			LAi_QuestDelay("BH_sound_type", 0.01);
		break;

		case "BH_sound_type":
			if(CheckAttribute(Pchar,"quest.sketch_cliff_found") && Pchar.quest.sketch_cliff_found == "yes")
			{
				LAi_QuestDelay("BH_sound_type1", 0.01);
			}
			else LAi_QuestDelay("sketch_cliff_found", 0.01);
		break;

		case "sketch_cliff_found":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "sketch_cliff_found";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "sketch_cliff_found_done":
			AddQuestRecord("Bishop's_Hostel","5");
	
			LAi_QuestDelay("BH_sound_type1", 0.01);
		break;

		case "BH_sound_type1":
			LAi_SetPlayerType(Pchar);

			pchar.quest.look_rock.win_condition.l1 = "locator";
			pchar.quest.look_rock.win_condition.l1.location = "Bishops_hostel";
			pchar.quest.look_rock.win_condition.l1.locator_group = "goto";
			pchar.quest.look_rock.win_condition.l1.locator = "look_rock";
			pchar.quest.look_rock.win_condition = "look_rock";

			pchar.quest.look_rockB.win_condition.l1 = "locator";
			pchar.quest.look_rockB.win_condition.l1.location = "Bishops_hostel";
			pchar.quest.look_rockB.win_condition.l1.locator_group = "goto";
			pchar.quest.look_rockB.win_condition.l1.locator = "look_rockB";
			pchar.quest.look_rockB.win_condition = "look_rockB";

			pchar.quest.look_rockC.win_condition.l1 = "locator";
			pchar.quest.look_rockC.win_condition.l1.location = "Bishops_hostel";
			pchar.quest.look_rockC.win_condition.l1.locator_group = "goto";
			pchar.quest.look_rockC.win_condition.l1.locator = "look_rockC";
			pchar.quest.look_rockC.win_condition = "look_rockC";	
		break;
	



		case "gov_office_ticking":
			Pchar.quest.gov_office_clock = "silent";
			LAi_SetPlayerType(Pchar);
		break;

		case "FM_exit_stones_turn_around":
			pchar.quest.FM_exit_stones_turn_aroundA.win_condition.l1 = "locator";
			pchar.quest.FM_exit_stones_turn_aroundA.win_condition.l1.location = "Fort_Moultrie_exit";
			pchar.quest.FM_exit_stones_turn_aroundA.win_condition.l1.locator_group = "goto";
			pchar.quest.FM_exit_stones_turn_aroundA.win_condition.l1.locator = "box1";
			pchar.quest.FM_exit_stones_turn_aroundA.win_condition = "FM_exit_stones_turn_aroundA";
		break;

		case "FM_exit_stones_turn_aroundA":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "FM_exit_stones":
			Pchar.quest.FM_exit_stones = "phase1";
			
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);//restarts turn around loop
		break;

		//....................................................

		case "Sull_sh1_turn_to_box2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box2");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		//....................................................
	
		case "Sull_sh2_turn_to_ri1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem1");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Sull_sh2_turn_to_box1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box1");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		//....................................................

		case "Sull_sh2_turn_to_bear":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "bear");
			
			LAi_QuestDelay("Sull_sh2_turn_to_bear1", 1.0);
		break;

		case "Sull_sh2_turn_to_bear1":	
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Sull_sh2_turn_to_bear2", 1.0);
		break;

		case "Sull_sh2_turn_to_bear2":
			PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
			
			LAi_QuestDelay("Sull_sh2_turn_to_bear3", 1.5);
		break;

		case "Sull_sh2_turn_to_bear3":
			Pchar.quest.sh2_bear = "phase1";
		break;

		case "run_from_bear":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box8");
			
			
			LAi_QuestDelay("run_from_bear1", 1.0);
		break;

		case "run_from_bear1":
			PlaySound("PEOPLE\run_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "Sullivan_shore2", "goto", "box8");
			LAi_SetPlayerType(Pchar);
			
			LAi_QuestDelay("run_from_bear2", 0.5);
		break;

		case "run_from_bear2":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Logit(TranslateString("","That was close - I'll remember not to go there again!"));
		break;

		//....................................................

		case "Sull_sh3_turn_to_look1":	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Sull_sh3_turn_to_look2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Legrands_house_entre":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");

			pchar.quest.pchar_playertype.win_condition.l1 = "location";
			pchar.quest.pchar_playertype.win_condition.l1.location = "Legrands_house";
			pchar.quest.pchar_playertype.win_condition = "pchar_playertype";
		break;
//----------------------------------------------------------------------------------------------------------------------

		case "Legrands_kitchen_plank_oxygen":
			LAi_SetPlayerType(Pchar);
			PlaySound("INTERFACE\oxygen.wav");

			if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "extinct")
			{
				CreateParticleSystemX("blast_dirt_black", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);
				CreateParticleSystemX("blast_dirt_black", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);

				LAi_QuestDelay("Pchar_coughing", 1.0);
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "no_wood")
				{
					CreateParticleSystemX("blast_dirt_gray", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);
					CreateParticleSystemX("blast_dirt_gray", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);

					LAi_QuestDelay("Pchar_coughing", 1.0);
				}
			}
			else LAi_QuestDelay("Legrands_kitchen_plank_down", 1.0);
		break;

		case "Legrands_kitchen_plank_down":
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace"))
			{
				switch(Pchar.quest.Legrands_fireplace)
			    	{
					case "fire2":
					
					break;	

					case "fire1":
						if(CheckAttribute(Pchar,"quest.Legrands_damper") && Pchar.quest.Legrands_damper == "open")
						{
							Locations[FindLocation(Pchar.location)].models.always.locators = "mediumhouse01_locators_GB2";
							Locations[FindLocation("Legrands_kitchen")].image = "";
							Pchar.quest.Legrands_fireplace = "fire2";

							if(CheckAttribute(Pchar,"quest.Legrands_cauldron_w") && Pchar.quest.Legrands_cauldron_w == "in_fireplace")
							{
								if(CheckAttribute(Pchar,"quest.Legrands_parchment_place") && Pchar.quest.Legrands_parchment_place == "in_cauldron")
								{
									locations[FindLocation(Pchar.location)].models.always.l5 = "crypto_roll_clean";	
									Pchar.quest.Legrands_crypto_roll = "clean";					//cleaned nere & now!
								}
							}

							DoQuestReloadToLocation("Legrands_kitchen", "goto", "box3", "Legrands_kitchen_plank_down1");
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");
						}						
					break;	

					case "glowing":
						if(CheckAttribute(Pchar,"quest.Legrands_damper") && Pchar.quest.Legrands_damper == "closed")
						{
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");
						}
						else
						{
							Locations[FindLocation(Pchar.location)].models.always.locators = "mediumhouse01_locators_GB1";
							locations[FindLocation(Pchar.location)].models.always.l2 = "wood3";
							Locations[FindLocation("Legrands_kitchen")].image = "";
							Pchar.quest.Legrands_fireplace = "fire1";

							DoQuestReloadToLocation("Legrands_kitchen", "goto", "box3", "Legrands_kitchen_plank_down1");
						}
					break;
				
					case "extinct":
						//done already above
					break;

					case "unlit":
					
					break;

					case "no_wood":
					
					break;
				}
			   	return;
			}
		break;

		case "Pchar_coughing":
			PlaySound("AMBIENT\JAIL\cough.wav");

			LAi_QuestDelay("Poe_coughing", 1.0);
		break;

		case "Poe_coughing":
			if(Characters[GetCharacterIndex("Edgar Allan Poe")].location == "Legrands_kitchen")
			{
				PlaySound("VOICE\ENGLISH\Poe_smoke.wav");
			}
		break;

		case "Legrands_kitchen_plank_down1":
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			if(Locations[FindLocation(Pchar.location)].models.always.locators == "mediumhouse01_locators_GB1")
			{
				PlaySound("INTERFACE\fire_on.wav");

				LAi_QuestDelay("Legrands_kitchen_fire_low", 1.0);
			}

			if(Locations[FindLocation("Legrands_kitchen")].models.always.locators == "mediumhouse01_locators_GB2")
			{
				LAi_QuestDelay("Legrands_kitchen_fire_high", 0.1);

				if(CheckAttribute(Pchar,"quest.Legrands_cauldron_w") && Pchar.quest.Legrands_cauldron_w == "in_fireplace")
				{
					Pchar.quest.Legrands_cauldron_water = "hot";
					Pchar.quest.Legrands_fryingpan_temp = "hot";

					LAi_QuestDelay("Legrands_kitchen_boiling_loop", 1.0);
				}				
			}
		break;

		case "Legrands_kitchen_fire_low":
			if(Pchar.location == "Legrands_kitchen")
			{
				if(Locations[FindLocation("Legrands_kitchen")].models.always.locators == "mediumhouse01_locators_GB1")
				{
					PlaySound3D("NATURE\fireplace2.wav", 1.4, 0.77, 0.89);
					LAi_QuestDelay("Legrands_kitchen_fire_low", 5.0);
				}
				else return;
			}
			else return;
		break;

		case "Legrands_kitchen_fire_high":
			if(Pchar.location == "Legrands_kitchen")
			{
				if(Locations[FindLocation("Legrands_kitchen")].models.always.locators == "mediumhouse01_locators_GB2")
				{
					PlaySound3D("NATURE\fireplace3.wav", 1.4, 0.77, 0.89);
					LAi_QuestDelay("Legrands_kitchen_fire_high", 4.8);
				}
				else return;
			}
			else return;
		break;

		case "Legrands_kitchen_boiling_loop":
			if(Pchar.location == "Legrands_kitchen")
			{
				if(Locations[FindLocation("Legrands_kitchen")].models.always.locators == "mediumhouse01_locators_GB2")
				{
					PlaySound("INTERFACE\rumble1.wav");
					LAi_QuestDelay("Legrands_kitchen_boiling_loop", 5.0);
				}
				else return;
			}
			else
			{
				Pchar.quest.Legrands_cauldron_water = "cold";
			 	return;
			}
		break;

		case "stay_at_Legrands_fireplace":
			//from itemlogic Legrands_kitchen box4
			if(!LAi_IsFightMode(Pchar))
			{
				ChangeCharacterAddressGroup(Pchar, "Legrands_kitchen", "goto", "fireplace");
				LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			}
			else LAi_QuestDelay("stay_at_Legrands_fireplace", 1.0);//loops until not fightmode
		break;

		case "end_of_tinderbox":
			//from LAi_events
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_tinderbox1");
		break;

		case "end_of_tinderbox1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
			
			Logit(TranslateString("","Hmm, it's only glowing...?"));
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		break;

		case "place_dirty_parchment_in_hot_water":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "place_dirty_parchment_in_hot_water2");
		break;

		case "place_dirty_parchment_in_hot_water2":
			PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
			Logit(TranslateString("","That really helped - now let's see if there are more secrets to be found on the parchment."));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "take_dirty_parchment_from_hot_water":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "take_dirty_parchment_from_hot_water2");
		break;

		case "take_dirty_parchment_from_hot_water2":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","Now when it's clean, maybe I should heat it up again?"));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
			AddQuestRecord("The_parchment", "9");
		break;

		case "dirty_parchment_in_cold_water2":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Logit(TranslateString("","No, the water isn't warm enough."));	
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;
	
		case "end_of_placing_woodsack":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";

			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_placing_woodsack2");
		break;

		case "end_of_placing_crypto_on_pan":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_placing_crypto_on_pan2");
		break;

		case "end_of_placing_crypto_on_pan2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			if(CheckAttribute(Pchar,"quest.driftwood") && Pchar.quest.driftwood == "yes")
			{
				//second wood expedition (shores)

			}
			else 
			{
				//first wood expedition (boathouse)
				Pchar.quest.fireplace_disabled = "yes";
				LAi_QuestDelay("wonder_where_Jupiter_is", 1.0);
			}
		break;

		case "end_of_placing_cauldron":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_placing_cauldron2");
		break;

		case "end_of_placing_cauldron2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "fire2")
			{
				Pchar.quest.Legrands_cauldron_water = "hot";
				LAi_QuestDelay("Legrands_kitchen_boiling_loop", 1.0);
			}
		break;

		case "end_of_placing_fryingpan":
			//from LAi_events
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_placing_fryingpan2");
		break;

		case "end_of_placing_fryingpan2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "fire2")
			{
				Pchar.quest.Legrands_fryingpan_temp = "hot";
				LAi_QuestDelay("Legrands_kitchen_boiling_loop", 1.0);
			}

			AddQuestRecord("Useful_items", "7");
			CloseQuestHeader("Useful_items");
		break;

		case "end_of_tinderbox2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "end_of_tinderbox3":
			//from LAi_events
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		break;

		case "end_of_tinderbox4":
			//from LAi_events
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		break;

		case "end_of_visible_skull_dirty":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Logit(TranslateString("","So that's how it happened! The heat revealed a death's-head on the other side of the parchment!"));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "end_of_visible_skullgoat_dirty":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Logit(TranslateString("","More heat and now there's a goat together with a death's-head!"));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "end_of_visible_skullgoat_clean":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","Okay, there's the goat and the death's-head again!"));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "end_of_visible_parttext_clean":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
		break;

		case "end_of_visible_text_clean":
			Locations[FindLocation("Legrands_kitchen")].image = "";
		
			if(CheckCharacterItem(Pchar,"inkpen") && CheckCharacterItem(Pchar,"letter_paper"))
			{
				DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "copy_full_code");
			}
			else DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "end_of_visible_text_clean2");
		break;

		case "end_of_visible_text_clean2":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Logit(TranslateString("","Yes yes yes. I knew there was more. A lot of characters are rudely traced between the Death's-head and the Goat!"));
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
			AddQuestRecord("The_parchment", "8");

			if(CheckAttribute(Pchar,"quest.crypto_full_text") && Pchar.quest.crypto_full_text == "first_time")
			{
				Pchar.quest.fireplace_disabled = "yes";
				Pchar.quest.crypto_full_text = "first_time_done";
				
				LAi_QuestDelay("send_Jupiter_to_Moultrie", 3.0);
			}
		break;

		//....................................................

		case "Legrands_damper":
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "damper", "Legrands_damper1");
		break;

		case "Legrands_damper1":
			Locations[FindLocation("Legrands_kitchen")].image = "Legrands_kitchen.tga";
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, false);

			if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "fire1")
			{
				LAi_QuestDelay("Legrands_kitchen_fire_low", 1.0);
			}
		break;

		//....................................................

		case "Legrands_damper_closed":
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "damper", "Legrands_damper_closed1");
		break;

		case "Legrands_damper_closed1":
			Locations[FindLocation("Legrands_kitchen")].image = "Legrands_kitchen.tga";
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, false);
		break;

		//....................................................

		case "Legrands_damper_closed_smoke":
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "damper", "Legrands_damper_closed_smoke1");
		break;

		case "Legrands_damper_closed_smoke1":
			Locations[FindLocation("Legrands_kitchen")].image = "Legrands_kitchen.tga";
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, false);

			CreateParticleSystemX("blast_dirt_black", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);
			CreateParticleSystemX("blast_dirt_black", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);

			LAi_QuestDelay("Pchar_coughing", 1.0);
		break;

		//....................................................

		case "Legrands_kitchen_fire_level_down":
			pchar.quest.Legrands_kitchen_fire_level_down1.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down1.win_condition.l1.location = "Legrands_kitchen";
			pchar.quest.Legrands_kitchen_fire_level_down1.win_condition = "Legrands_kitchen_fire_level_down1";
		break;

		case "Legrands_kitchen_fire_level_down1":
			pchar.quest.Legrands_kitchen_fire_level_down2.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down2.win_condition.l1.location = "Legrands_house";
			pchar.quest.Legrands_kitchen_fire_level_down2.win_condition = "Legrands_kitchen_fire_level_down2";
		break;

		case "Legrands_kitchen_fire_level_down2":
			Pchar.quest.Legrands_cauldron_water = "cold";
			Pchar.quest.Legrands_fryingpan_temp = "cold";

			if(CheckAttribute(Pchar,"quest.Legrands_fireplace"))
			{
			    	switch(Pchar.quest.Legrands_fireplace)
			    	{
					case "fire2":
						Locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB1";
						Pchar.quest.Legrands_fireplace = "fire1";

						pchar.quest.Legrands_kitchen_fire_low.win_condition.l1 = "location";
						pchar.quest.Legrands_kitchen_fire_low.win_condition.l1.location = "Legrands_kitchen";
						pchar.quest.Legrands_kitchen_fire_low.win_condition = "Legrands_kitchen_fire_low";
					break;	

					case "fire1":
						Locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
						locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood3";
						Pchar.quest.Legrands_fireplace = "glowing";
					break;	

					case "glowing":
						locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood5";
						Pchar.quest.Legrands_fireplace = "extinct";
					break;
				}
			}
		
			if(CheckCharacterItem(Pchar,"bladecrypto_ds"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_ds"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_ds");
					GiveItem2Character(Pchar, "bladecrypto_dl");
					EquipCharacterByItem(Pchar, "bladecrypto_dl");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_ds");
					GiveItem2Character(Pchar, "bladecrypto_dl");
				}
			} 

			if(CheckCharacterItem(Pchar,"bladecrypto_dsk"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_dsk"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_dsk");
					GiveItem2Character(Pchar, "bladecrypto_ds");
					EquipCharacterByItem(Pchar, "bladecrypto_ds");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_dsk");
					GiveItem2Character(Pchar, "bladecrypto_ds");
				}
			} 

			if(CheckCharacterItem(Pchar,"bladecrypto_csk"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_csk"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
					EquipCharacterByItem(Pchar, "bladecrypto_cl");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
				}
			} 

			if(CheckCharacterItem(Pchar,"bladecrypto_cskp"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_cskp"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_cskp");
					GiveItem2Character(Pchar, "bladecrypto_csk");
					EquipCharacterByItem(Pchar, "bladecrypto_csk");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_cskp");
					GiveItem2Character(Pchar, "bladecrypto_csk");
				}
			} 

			if(CheckCharacterItem(Pchar,"bladecrypto_cskt"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_cskt"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_cskt");
					GiveItem2Character(Pchar, "bladecrypto_cskp");
					EquipCharacterByItem(Pchar, "bladecrypto_cskp");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_cskt");
					GiveItem2Character(Pchar, "bladecrypto_cskp");
				}
			} 

			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);

			pchar.quest.Legrands_kitchen_fire_level_down3A.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down3A.win_condition.l1.location = "Sullivan_jungle1";
			pchar.quest.Legrands_kitchen_fire_level_down3A.win_condition = "Legrands_kitchen_fire_level_down3";

			pchar.quest.Legrands_kitchen_fire_level_down3B.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down3B.win_condition.l1.location = "Legrands_backyard";
			pchar.quest.Legrands_kitchen_fire_level_down3B.win_condition = "Legrands_kitchen_fire_level_down3";

			pchar.quest.Legrands_kitchen_fire_level_down3C.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down3C.win_condition.l1.location = "Legrands_grot";
			pchar.quest.Legrands_kitchen_fire_level_down3C.win_condition = "Legrands_kitchen_fire_level_down3";
		break;

		case "Legrands_kitchen_fire_level_down3":
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace"))
			{
			    	switch(Pchar.quest.Legrands_fireplace)
			    	{
					case "fire1":
						Locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
						locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood3";
						Pchar.quest.Legrands_fireplace = "glowing";
					break;	

					case "glowing":
						locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood5";
						Pchar.quest.Legrands_fireplace = "extinct";
					break;
				}
			}

			if(CheckCharacterItem(Pchar,"bladecrypto_ds"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_ds"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_ds");
					GiveItem2Character(Pchar, "bladecrypto_dl");
					EquipCharacterByItem(Pchar, "bladecrypto_dl");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_ds");
					GiveItem2Character(Pchar, "bladecrypto_dl");
				}
			} 
		
			if(CheckCharacterItem(Pchar,"bladecrypto_csk"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_csk"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
					EquipCharacterByItem(Pchar, "bladecrypto_cl");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
				}
			} 

			if(CheckCharacterItem(Pchar,"bladecrypto_cskp"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_cskp"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_cskp");
					GiveItem2Character(Pchar, "bladecrypto_csk");
					EquipCharacterByItem(Pchar, "bladecrypto_csk");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_cskp");
					GiveItem2Character(Pchar, "bladecrypto_csk");
				}
			} 	

			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);

			pchar.quest.Legrands_kitchen_fire_level_down4A.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down4A.win_condition.l1.location = "Sullivan_jungle2";
			pchar.quest.Legrands_kitchen_fire_level_down4A.win_condition = "Legrands_kitchen_fire_level_down4";

			pchar.quest.Legrands_kitchen_fire_level_down4B.win_condition.l1 = "location";
			pchar.quest.Legrands_kitchen_fire_level_down4B.win_condition.l1.location = "Sullivan_shore1";
			pchar.quest.Legrands_kitchen_fire_level_down4B.win_condition = "Legrands_kitchen_fire_level_down4";
		break;

		case "Legrands_kitchen_fire_level_down4":
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace"))
			{
			    	switch(Pchar.quest.Legrands_fireplace)
			    	{
					case "glowing":
						locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood5";
						Pchar.quest.Legrands_fireplace = "extinct";
					break;
				}
			}

			if(CheckCharacterItem(Pchar,"bladecrypto_csk"))
			{
				if(IsEquipCharacterByItem(Pchar, "bladecrypto_csk"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
					EquipCharacterByItem(Pchar, "bladecrypto_cl");
				}
				else
				{	
					TakeItemFromCharacter(Pchar, "bladecrypto_csk");
					GiveItem2Character(Pchar, "bladecrypto_cl");
				}
			} 

			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
		break;

//----------------------------------------------------------------------------------------------------------------------

		case "Legrands_house_backdoor":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "way_to_well1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box4");
			Pchar.quest.go_to_well = "phase2";

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "ready_to_pick_up_filled_cauldron":
			Pchar.quest.go_to_well = "phase6";
		break;		
	
		case "pick_up_filled_cauldron1":
			LAi_SetFightMode(Pchar, false);

			LAi_QuestDelay("pick_up_filled_cauldron2", 1.0);
		break;

		case "pick_up_filled_cauldron2":
			Pchar.quest.go_to_well = "phase7";
		break;

		case "return_from_well1":
			PlaySound("PEOPLE\run_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "Legrands_backyard", "goto", "box3");

			LAi_QuestDelay("return_from_well2", 0.5);
		break;

		case "return_from_well2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "return_from_well3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");
		break;
	//--------------------------------------------------------------------------
		case "way_to_attic1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem5");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "way_to_attic2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look6");

			if(Locations[FindLocation(Pchar.location)].models.always.locators == "qcexit_l_GB_tree")
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");		
			}
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "way_to_attic3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem18");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "way_to_attic4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_stairs");
			
			LAi_QuestDelay("pchar_staytype", 0.5);
			LAi_QuestDelay("way_to_attic4_A", 0.7);
		break;

		case "way_to_attic4_A":
			Pchar.quest.backyard_box8 = "enabled";
		break;

		case "return_from_attic0":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_stairs");
			
			LAi_QuestDelay("pchar_staytype", 0.5);
		break;

		case "return_from_attic1":
			PlaySound("PEOPLE\jump_stone.wav");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("way_to_attic3", 0.5);
		break;

		case "return_from_attic2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box2");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "return_from_attic3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "fort_closed":
			LAi_SetPlayerType(Pchar);
			Characters[GetCharacterIndex("Moultrie_guard2")].dialog.CurrentNode  = "First time";
			ChangeCharacterAddressGroup(characterFromID("Moultrie_guard2"), "Fort_Moultrie_village", "goto", "guard2");
			LAi_SetStayType(characterFromID("Moultrie_guard2"));

			pchar.quest.fort_closed1.win_condition.l1 = "locator";
			pchar.quest.fort_closed1.win_condition.l1.location = "Fort_Moultrie_village";
			pchar.quest.fort_closed1.win_condition.l1.locator_group = "goto";
			pchar.quest.fort_closed1.win_condition.l1.locator = "closed";
			pchar.quest.fort_closed1.win_condition = "fort_closed1";
		break;

		case "fort_closed1":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_village", "reload", "reload12");
			LAi_SetStayType(Pchar);

			Characters[GetCharacterIndex("Moultrie_guard2")].dialog.CurrentNode  = "password";
			LAi_SetActorType(characterFromID("Moultrie_guard2"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_guard2"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_guard2"), pchar, "", 0.01);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_guard2"));
		break;

		case "fort_open":
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "SmL_l_GB_open_smoke2";
			DoQuestReloadToLocation("Fort_Moultrie_stairs", "goto", "goto1", "pchar_playertype");
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "tipi1_backloop":
			pchar.quest.tipi1_backloopA.win_condition.l1 = "locator";
			pchar.quest.tipi1_backloopA.win_condition.l1.location = "Fort_Moultrie_exit";
			pchar.quest.tipi1_backloopA.win_condition.l1.locator_group = "reload";
			pchar.quest.tipi1_backloopA.win_condition.l1.locator = "tipi1";
			pchar.quest.tipi1_backloopA.win_condition = "tipi1_backloopA";
		break;

		case "tipi1_backloopA":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_exit", "reload", "tipi1");
			LAi_SetStayType(Pchar);
			PlaySound("VOICE\ENGLISH\pir_capHH.wav");
			
			LAi_QuestDelay("tipi1_backloopB", 2.0);
		break;

		case "tipi1_backloopB":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_exit", "goto", "get_out1");
			LAi_SetPlayerType(Pchar);			

			LAi_QuestDelay("tipi1_backloop", 0.1);
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "tipi2_backloop":
			pchar.quest.tipi2_backloopA.win_condition.l1 = "locator";
			pchar.quest.tipi2_backloopA.win_condition.l1.location = "Fort_Moultrie_exit";
			pchar.quest.tipi2_backloopA.win_condition.l1.locator_group = "reload";
			pchar.quest.tipi2_backloopA.win_condition.l1.locator = "tipi2";
			pchar.quest.tipi2_backloopA.win_condition = "tipi2_backloopA";
		break;

		case "tipi2_backloopA":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_exit", "reload", "tipi2");
			LAi_SetStayType(Pchar);
			PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom4.wav");
			
			LAi_QuestDelay("tipi2_backloopB", 1.0);
		break;

		case "tipi2_backloopB":
			LAi_SetPoorType(Pchar);
			PlaySound("PEOPLE\jump_stone.wav");
			LAi_ApplyCharacterDamage(Pchar, 5);
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_exit", "goto", "get_out2");
			
			LAi_QuestDelay("tipi2_backloopC", 2.0);
		break;

		case "tipi2_backloopC":
			LAi_SetPlayerType(Pchar);
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");

			LAi_QuestDelay("tipi2_backloop", 0.1);
		break;
//----------------------------------------------------------------------------------------------------------------------

		case "fort_shore_pier":
			pchar.quest.fort_shore_pier1.win_condition.l1 = "locator";
			pchar.quest.fort_shore_pier1.win_condition.l1.location = "Fort_Moultrie_shore";
			pchar.quest.fort_shore_pier1.win_condition.l1.locator_group = "goto";
			pchar.quest.fort_shore_pier1.win_condition.l1.locator = "pier3";
			pchar.quest.fort_shore_pier1.win_condition = "fort_shore_pier1";
		break;

		case "fort_shore_pier1":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_shore", "goto", "box2");
	
			LAi_QuestDelay("fort_shore_pier", 0.5);			//loop
			LAi_QuestDelay("fort_shore_pier2", 0.5);	
		break;

		case "fort_shore_pier2":
			Logit(TranslateString("","Charleston..."));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");	
		break;

		//....................................................

		case "fort_shore_pier_boat":
			pchar.quest.fort_shore_pier_boat1.win_condition.l1 = "locator";
			pchar.quest.fort_shore_pier_boat1.win_condition.l1.location = "Fort_Moultrie_shore";
			pchar.quest.fort_shore_pier_boat1.win_condition.l1.locator_group = "goto";
			pchar.quest.fort_shore_pier_boat1.win_condition.l1.locator = "pier1";
			pchar.quest.fort_shore_pier_boat1.win_condition = "fort_shore_pier_boat1";
		break;

		case "fort_shore_pier_boat1":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_shore", "goto", "pier2");
	
			LAi_QuestDelay("fort_shore_pier_boat", 0.5);		//loop
		break;

		//....................................................

		case "FM_sh_go_to_return":
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie_shore", "goto", "return");
		break;

		case "FM_sh_turn_to_cit1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "citizen01");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_port_turn_to_ship_1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ship_1");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_port_box9":
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_port", "goto", "return");	

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Charleston_steam_frigate":
			pchar.quest.Charleston_steam_frigate1.win_condition.l1 = "locator";
			pchar.quest.Charleston_steam_frigate1.win_condition.l1.location = "GB_Charleston_port";
			pchar.quest.Charleston_steam_frigate1.win_condition.l1.locator_group = "goto";
			pchar.quest.Charleston_steam_frigate1.win_condition.l1.locator = "steam";
			pchar.quest.Charleston_steam_frigate1.win_condition = "Charleston_steam_frigate1";
		break;

		case "Charleston_steam_frigate1":
			Pchar.quest.steam_sounds = "on";

			pchar.quest.Charleston_steam_frigate2.win_condition.l1 = "locator";
			pchar.quest.Charleston_steam_frigate2.win_condition.l1.location = "GB_Charleston_port";
			pchar.quest.Charleston_steam_frigate2.win_condition.l1.locator_group = "goto";
			pchar.quest.Charleston_steam_frigate2.win_condition.l1.locator = "steam_off";
			pchar.quest.Charleston_steam_frigate2.win_condition = "Charleston_steam_frigate2";

			LAi_QuestDelay("Charleston_steam_frigate3", 0.01);
		break;

		case "Charleston_steam_frigate2":
			Pchar.quest.steam_sounds = "off";

			LAi_QuestDelay("Charleston_steam_frigate", 0.01);	//restarts loop
		break;

		case "Charleston_steam_frigate3":
			if(CheckAttribute(Pchar,"quest.steam_sounds") && Pchar.quest.steam_sounds == "on")
			{
				PlaySound("AMBIENT\SEASHORE\steam_engine.wav");

				LAi_QuestDelay("Charleston_steam_frigate3", 5.4);	//was 5.5
			}
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Charleston_steam_frigate_sailaway":
			characters[GetCharacterIndex("Lieutenant G")].sailaway = true;
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Charleston_prisoner":
			int prisonervoice = rand(2);

			switch (prisonervoice)
			{
				case 0:
					PlaySound("VOICE\ENGLISH\blaze_dont_leave_me.wav");
				break;

				case 1:
					PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
				break;

				case 2:
					PlaySound("VOICE\ENGLISH\blaze_help.wav");
				break;
			}
		break;

		case "Ch_port_box4_phase1":
			Pchar.quest.Ch_port_box4 = "phase1";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ship_1");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_port_box4_phase2":
			Pchar.quest.Ch_port_box4 = "phase2";
		break;

		case "Ch_port_box4_phase3":
			Pchar.quest.Ch_port_box4 = "phase3";
			LAi_SetPlayerType(Pchar);
		break;


		case "Ch_port_box6_phase1":
			Pchar.quest.Ch_port_box6 = "phase1";
			
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_port_box6_phase2":
			Pchar.quest.Ch_port_box6 = "phase2";
		break;

		case "Ch_port_box6_phase3":
			Pchar.quest.Ch_port_box6 = "phase3";
			LAi_SetPlayerType(Pchar);
		break;

		case "Ch_port_box11_phase1":
			Pchar.quest.Ch_port_box11 = "phase1";

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_port_box11_phase2":
			Pchar.quest.Ch_port_box11 = "phase2";
		break;

		case "Ch_port_box11_phase3":
			Pchar.quest.Ch_port_box11 = "phase3";
			LAi_SetPlayerType(Pchar);
		break;
//----------------------------------------------------------------------------------------------------------------------

		case "town_exit_closed":
			LAi_SetPlayerType(Pchar);
			Characters[GetCharacterIndex("Charleston_guard2")].dialog.CurrentNode  = "First time";
			ChangeCharacterAddressGroup(characterFromID("Charleston_guard2"), "GB_Charleston_town", "goto", "guard3");
			LAi_SetStayType(characterFromID("Charleston_guard2"));

			pchar.quest.town_exit_closed1.win_condition.l1 = "locator";
			pchar.quest.town_exit_closed1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.town_exit_closed1.win_condition.l1.locator_group = "reload";
			pchar.quest.town_exit_closed1.win_condition.l1.locator = "reload2";
			pchar.quest.town_exit_closed1.win_condition = "town_exit_closed1";
		break;

		case "town_exit_closed1":
			if(CheckAttribute(Pchar,"quest.town_exit_closed") && Pchar.quest.town_exit_closed == "yes")
			{
				ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "goto", "closed_gate");
				LAi_SetStayType(Pchar);

				Characters[GetCharacterIndex("Charleston_guard2")].dialog.CurrentNode  = "closed_gate";
				LAi_SetActorType(characterFromID("Charleston_guard2"));
				LAi_ActorTurnToCharacter(characterFromID("Charleston_guard2"), PChar);
				LAi_ActorDialogNow(characterFromID("Charleston_guard2"), pchar, "", 0.01);
				LAi_ActorWaitDialog(Pchar, characterFromID("Charleston_guard2"));
			}
			else return;
		break;

//----------------------------------------------------------------------------------------------------------------------

		case "Chinatown_malaria":
			LAi_SetPlayerType(Pchar);
			Characters[GetCharacterIndex("Charleston_doctor")].dialog.CurrentNode  = "First time";
			LAi_SetStayType(characterFromID("Charleston_doctor"));

			pchar.quest.Chinatown_malaria1.win_condition.l1 = "locator";
			pchar.quest.Chinatown_malaria1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Chinatown_malaria1.win_condition.l1.locator_group = "reload";
			pchar.quest.Chinatown_malaria1.win_condition.l1.locator = "reload5";
			pchar.quest.Chinatown_malaria1.win_condition = "Chinatown_malaria1";
		break;

		case "Chinatown_malaria1":
			if(CheckAttribute(Pchar,"quest.Chinatown_malaria") && Pchar.quest.Chinatown_malaria == "yes")
			{
				ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "goto", "malaria");
				LAi_SetStayType(Pchar);

				Characters[GetCharacterIndex("Charleston_doctor")].dialog.CurrentNode  = "malaria";
				LAi_SetActorType(characterFromID("Charleston_doctor"));
				LAi_ActorTurnToCharacter(characterFromID("Charleston_doctor"), PChar);
				LAi_ActorDialogNow(characterFromID("Charleston_doctor"), pchar, "", 0.01);
				LAi_ActorWaitDialog(Pchar, characterFromID("Charleston_doctor"));
			}
			else return;
		break;

//----------------------------------------------------------------------------------------------------------------------
		case "church_sounds_first":
			pchar.quest.church_sounds_first1.win_condition.l1 = "locator";
			pchar.quest.church_sounds_first1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.church_sounds_first1.win_condition.l1.locator_group = "goto";
			pchar.quest.church_sounds_first1.win_condition.l1.locator = "church2";
			pchar.quest.church_sounds_first1.win_condition = "church_sounds_first1";
		break;

		case "church_sounds_first1":
			float fTime = GetTime();
			fTime = GetTime();
			
			if(fTime > 10.0 && fTime < 18.00)
			{
				int churchrepairsound1 = rand(2);

				switch (churchrepairsound1)
				{
					case 0:
						PlaySound("AMBIENT\SHIPYARD\patter.wav");
					break;

					case 1:
						PlaySound("AMBIENT\SHIPYARD\hammer.wav");
					break;

					case 2:
						PlaySound("AMBIENT\SHIPYARD\hammer.wav");
					break;
				}
			}
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Charleston_priest":
			pchar.quest.Charleston_priest1.win_condition.l1 = "locator";
			pchar.quest.Charleston_priest1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Charleston_priest1.win_condition.l1.locator_group = "goto";
			pchar.quest.Charleston_priest1.win_condition.l1.locator = "church";
			pchar.quest.Charleston_priest1.win_condition = "Charleston_priest1";
		break;

		case "Charleston_priest1":
			if(CheckAttribute(Pchar,"church_entre") && Pchar.church_entre == "yes")
			{
				return;
			}
			else
			{

				fTime = GetTime();
			
				if(fTime > 10.0 && fTime < 18.00)
				{
					LAi_QuestDelay("church_repair_sounds", 0.01);
				}

				LAi_SetOfficerType(characterFromID("Claude Frollo"));

				Pchar.quest.Charleston_priest_exit.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.Charleston_priest_exit.win_condition.l1.location = "GB_Charleston_town";
				Pchar.quest.Charleston_priest_exit.win_condition = "Charleston_priest_exit";
			}
		break;

		case "Charleston_priest_exit":
			fTime = GetTime();

			if(fTime > 10.0 && fTime < 18.00)
			{
				LAi_QuestDelay("Charleston_priest3", 0.1);
			}
			else LAi_QuestDelay("Charleston_priest", 0.1);
		break;

		case "Charleston_priest2":
			//from Frollo dialog
			LAi_QuestDelay("church_repair_sounds", 0.01);

			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorGoToLocator(characterFromID("Claude Frollo"), "goto", "priest", "Charleston_priest3", 14.0);
		break;

		case "Charleston_priest3":
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo"), "GB_Charleston_town", "goto", "priest");
			LAi_SetStayType(characterFromID("Claude Frollo"));

			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);
		break;

		case "church_repair_sounds":
			int churchrepairsound = rand(9);

			switch (churchrepairsound)
			{
				case 0:
					PlaySound("AMBIENT\SHIPYARD\patter.wav");
				break;

				case 1:
					PlaySound("AMBIENT\SHIPYARD\hammer.wav");
				break;

				case 2:
					PlaySound("PEOPLE\axe_saw.wav");
				break;

				case 3:
					PlaySound("PEOPLE\roof_creak.wav");
				break;

				case 4:
					PlaySound("PEOPLE\roof_broken1.wav");
				break;

				case 5:
					PlaySound("AMBIENT\SHIPYARD\patter.wav");
				break;

				case 6:
					PlaySound("AMBIENT\SHIPYARD\hammer.wav");
				break;

				case 7:
					PlaySound("PEOPLE\axe_saw.wav");
				break;

				case 8:
					PlaySound("AMBIENT\SHIPYARD\hammer.wav");
				break;

				case 9:
					PlaySound("AMBIENT\SHIPYARD\hammer.wav");
				break;

			}
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Ch_town_box11_phase2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box10");

			LAi_QuestDelay("Ch_town_box11_phase3", 0.5);
		break;
	
		case "Ch_town_box11_phase3":
			Pchar.quest.Ch_town_box11 = "phase3";
			LAi_SetPlayerType(Pchar);
		break;

		case "Ch_town_box12_turn_to_look_b12":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_b12");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_town_box15_turn_to_box8":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box8");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		//....................................................
	
		case "Ch_town_box19_1":
			Pchar.quest.Ch_town_box19 = "turn_back";
			LAi_SetPlayerType(Pchar);
		break;

		case "Ch_town_box19_2":
			Pchar.quest.Ch_town_box19 = "go_back";
			LAi_SetPlayerType(Pchar);
		break;

		//....................................................

		case "Ch_town_box62":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r23");

			LAi_QuestDelay("pchar_playertype", 0.5);
		
			pchar.quest.Ch_town_box63.win_condition.l1 = "locator";
			pchar.quest.Ch_town_box63.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Ch_town_box63.win_condition.l1.locator_group = "goto";
			pchar.quest.Ch_town_box63.win_condition.l1.locator = "box63";
			pchar.quest.Ch_town_box63.win_condition = "Ch_town_box63";
		break;
	
		case "Ch_town_box63":
	//LogIt("loginedcharacters = " + LAi_numloginedcharacters);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "reload23_1");

			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
	//LogIt("Jup is officer");
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload3_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		//....................................................

		case "Ch_town_box20":
			//used twice!
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box23");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_town_box21":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookR18");

			LAi_QuestDelay("pchar_playertype", 0.5);
		
			pchar.quest.Ch_town_box20.win_condition.l1 = "locator";
			pchar.quest.Ch_town_box20.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Ch_town_box20.win_condition.l1.locator_group = "goto";
			pchar.quest.Ch_town_box20.win_condition.l1.locator = "box22";
			pchar.quest.Ch_town_box20.win_condition = "Ch_town_box20";
		break;

		case "Ch_town_box22":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box43");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		//....................................................

		case "Ch_town_box27":
			Pchar.quest.Ch_town_box27 = "phase2";
		break;
	
		case "Ch_PH":
			PlaySound("INTERFACE\key_lock.wav");
		break;

		case "Ch_town_box28":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "penthouse");

			LAi_QuestDelay("Ch_town_box28_1", 0.1);
		break;

		case "Ch_town_box28_1":
			LAi_SetSitType(Pchar);
		break;

		case "Ch_town_box29":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "penthouse");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		case "Ch_town_box32":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			LAi_SetPlayerType(Pchar);
		break;

		case "Ch_town_box33":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"It's getting worse and worse..."));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			LAi_SetPlayerType(Pchar);
		break;
	
		case "Ch_town_box33_1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookb31");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Ch_town_box35_1":
			Pchar.quest.Ch_town_box35 = "phase2";
			LAi_SetPlayerType(Pchar);
		break;
	
		case "Ch_town_box35_2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookb35");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;
	
		case "Ch_town_box36":
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "goto", "box38");

			LAi_QuestDelay("Ch_town_box35_2", 0.5);
		break;

		case "Ch_town_box43":
			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "goto", "box50");

			LAi_QuestDelay("Ch_town_box43_1", 0.5);
		break;

		case "Ch_town_box43_1":
			LAi_SetActorType(Pchar);

			LAi_QuestDelay("Ch_town_box43_2", 0.5);
		break;

		case "Ch_town_box43_2":
			LAi_ActorTurnToLocator(Pchar, "box", "box51");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box51":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload4");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box56":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box58");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box57":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload17");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box58":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r17");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box59":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box57");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Ch_town_box61":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload23");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		

		case "Ch_town_box64":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "reload19_1");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

//----------------------------------------------------------------------------------------------------------------------

		case "Chinatown_box2":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				//LogIt("Jup is officer");
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinatown", "officers", "reload7_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}
		break;

		case "Chinatown_box3":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				//LogIt("Jup is officer");
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinatown", "officers", "reload10_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "Chinatown_box5":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Chinatown", "goto", "box2");
		break;

		case "Chinatown_box6":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Chinatown", "goto", "box3");
		break;
//----------------------------------------------------------------------------------------------------------------------
		case "plant_turn_to_look1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		case "BH_turn_to_box20":
			Pchar.quest.maroons_on_cliff_turn = "not_yet";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box20");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "pass_turn_to_box1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box1");

			LAi_QuestDelay("pchar_playertype", 0.5);

			if(CheckAttribute(Pchar, "quest.maroons_on_cliff") && Pchar.quest.maroons_on_cliff == "yes")
			{
				LAi_QuestDelay("pchar_ohoh", 0.5);
			}
		break;

		case "maroons_on_cliff_turn":
			Pchar.quest.maroons_on_cliff_turn = "done";
			LAi_SetPlayerType(Pchar);
		break;

		case "BH_turn_to_box10":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");	//oh oh
			LAi_SetPlayerType(Pchar);
		break;

		case "BH_turn_to_ground":
			LAi_SetActorType(Pchar);

			LAi_QuestDelay("BH_turn_to_ground1", 1.0);
		break;

		case "BH_turn_to_ground1":
			LAi_ActorTurnToLocator(Pchar, "goto", "ground");

			LAi_QuestDelay("BH_turn_to_ground2", 1.0);
		break;

		case "BH_turn_to_ground2":
			Pchar.quest.box_blocked = "no";
			LAi_SetPlayerType(Pchar);
		break;

		case "BH_too_steep":
			Logit(TranslateString("","No, it's to steep - I have to find another way up."));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			LAi_SetPlayerType(Pchar);
		break;
	
		//....................................................
		
		case "plantation_lake":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.plantation_lake = "way_back";
		break;

		//....................................................

//----------------------------------------------------------------------------------------------------------
//JRH intro
	











//----------------------------------------------------------------------------------------------------------
		case "hunting_birds":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "hunting_birds";
			CreateParticleSystem("gunfire" , 8.0, 6.5, -8.9, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , 8.5, 6.5, -8.9, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\DUEL\pistol_mtoon.wav");

			LAi_QuestDelay("hunting_birds1", 1.0);
		break;

		case "hunting_birds1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look3");

			PlaySound("NATURE\BirdsDisperse.wav");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			LAi_QuestDelay("extra_doves", 3.0);
			LAi_QuestDelay("hunting_birds2", 5.0);		
		break;

		case "extra_doves":
			PlaySound("NATURE\doves.wav");	
			PlaySound("NATURE\doves.wav");
			PlaySound("NATURE\doves.wav");
		break;

		case "hunting_birds2":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "hunting_birds3":
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			SetQuestHeader("Searching_the_shores");
			AddQuestRecord("Searching_the_shores", "1");
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Pchar.quest.Jupiter_equip = "case1";

			LAi_QuestDelay("Jupiter_equip_check", 1.0);
		break;
	
		case "Jupiter_equip_check":
			//Log_SetStringToLog("0000");
			if(CheckAttribute(Pchar,"quest.Jupiter_equip") && Pchar.quest.Jupiter_equip == "case1")
			{
				//Log_SetStringToLog("1111");
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladeX4"))
				{
					//Log_SetStringToLog("2222");
					if(!CheckCharacterItem(characterFromID("Jupiter"),"bladeX4"))
					{
						//Log_SetStringToLog("3333");
						GiveItem2Character(characterFromID("Jupiter"), "bladeX4");
					}
					
					RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
					EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");
				}

				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon"))
				{
					//Log_SetStringToLog("4444");
					RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
					EquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon");
				}

				LAi_QuestDelay("Jupiter_equip_check", 5.0);
			}

			if(CheckAttribute(Pchar,"quest.Jupiter_equip") && Pchar.quest.Jupiter_equip == "case2")
			{
				//Log_SetStringToLog("5555");
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladebirdsack"))
				{
					//Log_SetStringToLog("6666");
					RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
					EquipCharacterByItem(characterFromID("Jupiter"), "bladebirdsack");
				}

				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon"))
				{
					//Log_SetStringToLog("7777");
					RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
					EquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon");
				}

				LAi_QuestDelay("Jupiter_equip_check", 5.0);
			}
		break;

		case "So_that's_how it_happened":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");			
		break;

		case "delete_4_marsh_hens":
			TakeNItems(Pchar,"marsh_hen", -4);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");

			LAi_QuestDelay("delete_4_marsh_hens1", 2.0);
		break;

		case "delete_4_marsh_hens1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "home_via_wreck";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "through_the_wreck":
			AddQuestRecord("Searching_the_shores", "2");
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");

			LAi_SetOfficerType(characterFromID("Jupiter"));
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebirdsack");
			EquipCharacterByItem(Pchar, "bladeX4");
			
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			GiveItem2Character(characterFromID("Jupiter"), "bladebirdsack");
			EquipCharacterByItem(characterFromID("Jupiter"), "bladebirdsack");
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon");
			Pchar.quest.Jupiter_equip = "case2";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box2", 1.0);
			Locations[FindLocation("Sullivan_shore3")].locators_radius.box.box2 = 1.0;

	//Pchar.quest.JRH_sky = "C_St2";

	//		pchar.quest.black_sky.win_condition.l1 = "location";
	//		pchar.quest.black_sky.win_condition.l1.location = "Sullivan_shore2";
	//		pchar.quest.black_sky.win_condition = "black_sky";
		break;

		case "black_sky":
			Pchar.quest.JRH_sky = "C_Ni2";			
		break;

		case "delete_6_shells":
			AddQuestRecord("Searching_the_shores", "6");
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			TakeItemFromCharacter(Pchar, "shell1"); TakeItemFromCharacter(Pchar, "shell2");
			TakeItemFromCharacter(Pchar, "shell3"); TakeItemFromCharacter(Pchar, "shell4");
			TakeItemFromCharacter(Pchar, "shell5"); TakeItemFromCharacter(Pchar, "shell6");
			GiveItem2Character(Pchar, "shell_collection");
			Logit(TranslateString("","I've got a collection of shells - let's go home!"));

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box4", 1.0);
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box4 = 1.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 1.0);
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box5 = 1.0;

			LAi_QuestDelay("crypto_check", 1.0);

			LAi_QuestDelay("Sull_sh1_stop_point", 1.0);
		break;

		case "crypto_check":
			if(CheckCharacterItem(Pchar,"crypto"))
			{
				AddQuestRecord("Searching_the_shores", "5");
				SetQuestHeader("The_parchment");
				AddQuestRecord("The_parchment", "1");
				PlaySound("INTERFACE\paper.wav");

				TakeItemFromCharacter(Pchar, "crypto");
				GiveItem2Character(Pchar, "bladecrypto_d");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladecrypto_d");

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem7", 1.5);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.randitem.randitem7 = 1.5;
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 0.001);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.box.box5 = 0.001;

				LAi_QuestDelay("goldbug_check", 0.5);				
				LAi_QuestDelay("Jup_what_is_it", 0.1);
				return;
			}
			else
			{
				LAi_QuestDelay("crypto_check", 0.5);//loop check
			}
		break;

		case "goldbug_check":
			if(CheckCharacterItem(Pchar,"goldbug"))
			{
				CloseQuestHeader("Searching_the_shores");
				PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "stop", 0.001);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.goto.stop = 0.001;
				ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Sullivan_shore1", "reload", "reload2");
				LAi_SetStayType(characterFromID("Lieutenant G"));

				LAi_QuestDelay("Jupiter_aha", 1.0);
				
				pchar.quest.G_dialog_bug.win_condition.l1 = "locator";
				pchar.quest.G_dialog_bug.win_condition.l1.location = "Sullivan_shore1";
				pchar.quest.G_dialog_bug.win_condition.l1.locator_group = "goto";
				pchar.quest.G_dialog_bug.win_condition.l1.locator = "dialog";
				pchar.quest.G_dialog_bug.win_condition = "G_dialog_bug";
				
				return;
			}
			else
			{
				LAi_QuestDelay("goldbug_check", 0.5);//loop check
			}
		break;

		case "Jup_what_is_it":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "what_is_it";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jupiter_a_Goldbug":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");

			LAi_QuestDelay("Jupiter_a_Goldbug1", 1.0);
		break;

		case "Jupiter_a_Goldbug1":
			LAi_SetOfficerType(characterFromID("Jupiter"));
		break;

		case "Jupiter_aha":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
		break;

		case "Sull_sh1_stop_point":
			pchar.quest.Sull_sh1_stop_point1.win_condition.l1 = "locator";
			pchar.quest.Sull_sh1_stop_point1.win_condition.l1.location = "Sullivan_shore1";
			pchar.quest.Sull_sh1_stop_point1.win_condition.l1.locator_group = "goto";
			pchar.quest.Sull_sh1_stop_point1.win_condition.l1.locator = "stop";
			pchar.quest.Sull_sh1_stop_point1.win_condition = "Sull_sh1_stop_point1";
		break;

		case "Sull_sh1_stop_point1":
			if(CheckAttribute(Pchar,"quest.detected_goldbug") && Pchar.quest.detected_goldbug == "seen")
			{
				Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "stop_goldbug_seen";
			}

			if(CheckAttribute(Pchar,"quest.detected_goldbug") && Pchar.quest.detected_goldbug == "nothing")
			{
				Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "stop_goldbug_nothing";
			}
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "end_stop_goldbug_nothing":
			AddQuestRecord("Searching_the_shores", "3");
			ChangeCharacterAddressGroup(Pchar, "Sullivan_shore1", "goto", "stop2");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Sull_sh1_stop_point", 0.1);	//restart loop
		break;

		case "end_stop_goldbug_seen":
			ChangeCharacterAddressGroup(Pchar, "Sullivan_shore1", "goto", "stop2");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Sull_sh1_stop_point", 0.1);	//restart loop
		break;

		case "G_dialog_bug":
			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "borrow_goldbug";
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToCharacter(characterFromID("Lieutenant G"), PChar);
			LAi_ActorDialogNow(characterFromID("Lieutenant G"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Lieutenant G"));
		break;

		case "G_takes_bug":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			LAi_SetStayType(Pchar);
			TakeItemFromCharacter(Pchar, "goldbug");
			GiveItem2Character(characterFromID("Lieutenant G"), "goldbug");

			LAi_QuestDelay("G_takes_bug1", 1.0);
		break;

		case "G_takes_bug1":
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToLocator(characterFromID("Lieutenant G"), "reload", "reload2_back");
	
			LAi_QuestDelay("G_takes_bug2", 1.0);
		break;

		case "G_takes_bug2":
			LAi_ActorGoToLocator(characterFromID("Lieutenant G"), "goto", "walk", "G_takes_bug3", 4.0);	//was 3
		break;

		case "G_takes_bug3":
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");
			LAi_SetPlayerType(Pchar);

			pchar.quest.chimney_smoke.win_condition.l1 = "location";
			pchar.quest.chimney_smoke.win_condition.l1.location = "Sullivan_jungle1";
			pchar.quest.chimney_smoke.win_condition = "chimney_smoke";
		break;

		case "chimney_smoke":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "chimney_smoke";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "chimney_smoke_done":
			LAi_SetPlayerType(Pchar);

			pchar.quest.visitor.win_condition.l1 = "location";
			pchar.quest.visitor.win_condition.l1.location = "Legrands_house";
			pchar.quest.visitor.win_condition = "visitor";
		break;
//#1 from here
		case "visitor":
			if(!IsEquipCharacterByItem(Pchar, "bladecrypto_d"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladecrypto_d");
			}

			locations[FindLocation(Pchar.location)].box1.items.bladecauldron = 1;

			//reset soundtypes
			locations[FindLocation("Sullivan_shore1")].type = "Sullivan_seashore";
			locations[FindLocation("Sullivan_shore2")].type = "Sullivan_seashore";
			locations[FindLocation("Sullivan_shore3")].type = "Sullivan_seashore";
			locations[FindLocation("Sullivan_jungle1")].type = "Sullivan_jungle";
			locations[FindLocation("Sullivan_jungle2")].type = "Sullivan_jungle";
			locations[FindLocation("Fort_Moultrie_exit")].type = "Sullivan_jungle";

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "take_guns";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "take_guns_done":
			PlaySound("OBJECTS\DUEL\reload1.wav");
			PlaySound("OBJECTS\DUEL\reload1.wav");
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolmtoon");
			
			LAi_QuestDelay("take_guns_done1", 1.0);
		break;

		case "take_guns_done1":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "box", "box2");

			LAi_QuestDelay("take_guns_done2", 1.0);
		break;

		case "take_guns_done2":
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			PlaySound("OBJECTS\DUEL\sword_fallen.wav");

			LAi_QuestDelay("take_guns_done3", 1.5);
		break;

		case "take_guns_done3":
			PlaySound("INTERFACE\key_lock.wav");

			LAi_QuestDelay("take_guns_done4", 1.0);
		break;

		case "take_guns_done4":
			LAi_SetOfficerType(characterFromID("Jupiter"));

			pchar.quest.visitor1.win_condition.l1 = "location";
			pchar.quest.visitor1.win_condition.l1.location = "Legrands_kitchen";
			pchar.quest.visitor1.win_condition = "visitor1";
		break;

		case "visitor1":
		//Pchar.quest.exchange_items = "yes";

			if(!IsEquipCharacterByItem(Pchar, "bladecrypto_d"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladecrypto_d");
			}

			LAi_QuestDelay("Legrands_kitchen_fire_level_down1", 0.1);
			LAi_QuestDelay("tinderbox_autoequip", 0.1);

			locations[FindLocation(Pchar.location)].box1.items.pistoltinderbox = 1;
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "mixtable", "visitor2", 4.0);
		break;

		//.....................................................................................

		case "tinderbox_autoequip":
			Pchar.quest.tinderbox_autoequip1.win_condition.l1 = "item";
			Pchar.quest.tinderbox_autoequip1.win_condition.l1.character = Pchar.id;
			Pchar.quest.tinderbox_autoequip1.win_condition.l1.item = "pistoltinderbox";
			Pchar.quest.tinderbox_autoequip1.win_condition = "tinderbox_autoequip1";
		break;

		case "tinderbox_autoequip1":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "pistoltinderbox");
		break;

		//.....................................................................................

		case "visitor2":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "visitor";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "visitor_done":
			PlaySound("PEOPLE\counter_open.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "reload", "reload1");
			LAi_SetStayType(characterFromID("Jupiter"));

			LAi_QuestDelay("visitor3", 1.0);
		break;

		case "visitor3":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "who_are_you";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "who_are_you_done":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");

			LAi_QuestDelay("visitor4", 1.0);
		break;

		case "visitor4":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "new_shells";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "new_shells_done":
			PlaySound("AMBIENT\TAVERN\tinkle2.wav");
			PlaySound("AMBIENT\TAVERN\tinkle2.wav");
			TakeItemFromCharacter(Pchar, "shell_collection");
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "shell_collection");
	
			LAi_QuestDelay("visitor5", 1.0);
		break;

		case "visitor5":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "goldbug";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_goldbug_done":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "goldbug";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jupiter_goldbug_done":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "officers", "reload2_1");
			PlaySound("INTERFACE\closed_locked_door.wav");
			Locations[FindLocation("Legrands_kitchen")].reload.l1.disable = 1;	
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "bladebirdsack");
			LAi_SetOfficerType(characterFromID("Jupiter"));	
			
			LAi_QuestDelay("visitor6", 1.0);	
		break;

		case "visitor6":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "goldbug_describe";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_goldbug_describe_done":
			ChangeCharacterAddressGroup(CharacterFromID("Edgar Allan Poe"), "Legrands_kitchen", "sit", "sit3");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items", "1");
			DeleteQuestHeader("Searching_the_shores");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("inkpen_check", 0.1);	
		break;

		case "inkpen_check":
			if(CheckCharacterItem(Pchar,"inkpen"))
			{
				AddQuestRecord("Useful_items", "2");
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
				Pchar.quest.inkpen = "picked_up";
				CloseQuestHeader("Useful_items");

				if(!IsEquipCharacterByItem(Pchar, "bladecrypto_d"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladecrypto_d");
				}
				
				LAi_QuestDelay("inkpen_picked_up", 1.0);
				return;
			}
			else
			{
				LAi_QuestDelay("inkpen_check", 0.5);//loop check
			}
		break;

		//.................................................................................		

		case "down_from_bench":
			//from itemlogic
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Legrands_kitchen", "goto", "box7");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("Pchar_playertype", 0.5);
		break;

		//.................................................................................	

		case "inkpen_picked_up":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Legrands_kitchen", "goto", "box7");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("inkpen_picked_up1", 0.5);
		break;

		case "inkpen_picked_up1":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("inkpen_picked_up2", 1.0);
		break;

		case "inkpen_picked_up2":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "stay5", "inkpen_picked_up2A", 4.0);
		break;

		case "inkpen_picked_up2A":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box2");

			LAi_QuestDelay("inkpen_picked_up3", 1.0);
		break;

		case "inkpen_picked_up3":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "goldbug_drawing";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "goldbug_drawing_done":
			ChangeCharacterAddressGroup(Pchar, "Legrands_kitchen", "sit", "sit4");
			LAi_SetSitType(Pchar);
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			
			LAi_QuestDelay("goldbug_drawing_done1", 3.0);
		break;

		case "goldbug_drawing_done1":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladecrypto_d");
			GiveItem2Character(Pchar, "bladecrypto_dl");
			EquipCharacterByItem(Pchar, "bladecrypto_dl");
			AddQuestRecord("The_parchment", "2");
			
			LAi_QuestDelay("visitor7", 3.0);
		break;

		case "visitor7":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "show_me_drawing";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "show_me_drawing_done":
			ChangeCharacterAddressGroup(Pchar, "Legrands_kitchen", "goto", "stay4");
			LAi_SetActorType(Pchar);

			LAi_QuestDelay("show_me_drawing_done00", 1.0);				
		break;

		case "show_me_drawing_done00":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "close", "show_me_drawing_done0", 3.0);			
		break;

		case "show_me_drawing_done0":
			LAi_QuestDelay("show_me_drawing_done1", 1.0);			
		break;
		
		case "show_me_drawing_done1":
			PlaySound("INTERFACE\paper.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");
			TakeItemFromCharacter(Pchar, "bladecrypto_dl");
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "bladecrypto_dl");
			EquipCharacterByItem(characterFromID("Edgar Allan Poe"), "bladecrypto_dl");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Poe_checks_drawing", 1.0);
		break;

		case "Poe_checks_drawing":
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace"))
			{
			    	switch(Pchar.quest.Legrands_fireplace)
			    	{
					case "fire2":
						Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "less_fire";
						LAi_SetActorType(characterFromID("Edgar Allan Poe"));
						LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
						LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
						LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
					break;

					case "fire1":
						LAi_QuestDelay("Poe_checks_drawing0", 0.1);
					break;

					case "glowing":
						Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "more_fire";
						LAi_SetActorType(characterFromID("Edgar Allan Poe"));
						LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
						LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
						LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
					break;

					case "extinct":
						Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "light_fire";
						LAi_SetActorType(characterFromID("Edgar Allan Poe"));
						LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
						LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
						LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
					break;
				}
			}
		break;
	
		case "Poe_sittype":
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Legrands_kitchen", "sit", "sit3");

			LAi_QuestDelay("fire1_check", 0.1);
		break;

		case "fire1_check":
			if(CheckAttribute(Pchar,"quest.Legrands_fireplace") && Pchar.quest.Legrands_fireplace == "fire1")
			{
				LAi_QuestDelay("Poe_checks_drawing00", 0.1);
				return;
			}
			else  LAi_QuestDelay("fire1_check", 1.0);	//loops
		break;
	
		case "Poe_checks_drawing00":
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("Poe_checks_drawing0", 1.0);
		break;

		case "Poe_checks_drawing0":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Legrands_kitchen", "goto", "fireplace");

			LAi_QuestDelay("Poe_checks_drawing1", 2.0);
		break;
	
		case "Poe_checks_drawing1":
			PlaySound("INTERFACE\paper.wav");
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], false);
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);

			LAi_QuestDelay("Poe_checks_drawing2", 2.0);
		break;

		case "Poe_checks_drawing2":
			if(LAi_IsFightMode(characterFromID("Edgar Allan Poe"))) LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			
			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladecrypto_dl");
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "bladecrypto_ds");
			EquipCharacterByItem(characterFromID("Edgar Allan Poe"), "bladecrypto_ds");

			LAi_QuestDelay("Poe_checks_drawing3", 2.0);
		break;

		case "Poe_checks_drawing3":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "a_skull";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "a_skull_done":
			PlaySound("INTERFACE\paper.wav");
			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "bladecrypto_ds");
			GiveItem2Character(Pchar, "bladecrypto_ds");
			EquipCharacterByItem(Pchar, "bladecrypto_ds");
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			AddQuestRecord("The_parchment", "3");
			
			LAi_QuestDelay("a_skull_done1", 2.0);
		break;

		case "a_skull_done1":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "a_skull_on_the_parchment";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "a_skull_on_the_parchment_done":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "reload", "reload1");
			LAi_SetStayType(characterFromID("Jupiter"));
			PlaySound("INTERFACE\key_unlock.wav");
			Locations[FindLocation("Legrands_kitchen")].reload.l1.disable = 0;

			LAi_QuestDelay("supper", 1.0);
		break;

		case "supper":
			PlaySound("INTERFACE\Bell2.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "reload", "reload1");

			LAi_QuestDelay("supper1", 1.0);
		break;

		case "supper1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "supper";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "supper_done":
			SetCurrentTime(18.00, 0);
			SetNextWeather("Clear");

			int i;
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Legrands_house", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "officers", "reload1_2");
			LAi_SetStayType(characterFromID("Jupiter"));

			Pchar.quest.backyard = "open";
			Locations[FindLocation("Legrands_house")].locators_radius.box.box4 = 1.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box4", 1.0);

			Locations[FindLocation("Legrands_house")].image = "";			//sign telling: later that evening...
			DoQuestReloadToLocation("Legrands_house", "goto", "goto10", "visitor_leaves1");
		break;

		case "visitor_leaves1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "goto10");

			Locations[FindLocation("Legrands_house")].image = "GB_Legrands_hut_inside.tga";
			
			LAi_QuestDelay("visitor_leaves1A", 0.5);
		break;

		case "visitor_leaves1A":
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("visitor_leaves2", 1.5);
		break;

		case "visitor_leaves2":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "good_night";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "good_night_done":
			PlaySound("PEOPLE\counter_openclose.wav");
			
			LAi_QuestDelay("good_night_done1", 1.0);
		break;

		case "good_night_done1":			
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			LAi_QuestDelay("examine_parchment_closely", 2.0);	
		break;

		case "examine_parchment_closely":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "examine_parchment_closely";
			LAi_ActorSelfDialog(pchar, "");	
		break;

		case "examine_parchment_closely_done":
			PlaySound("INTERFACE\paper.wav");

			LAi_QuestDelay("good_night_done2", 1.5);
		break;

		case "good_night_done2":			
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "examine_parchment_closely_again";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "examine_parchment_closely_again2_done":
			AddQuestRecord("The_parchment", "5");
			LAi_SetPlayerType(pchar);

			LAi_QuestDelay("bladecrypto_dsk_check", 10.0);			
		break;
	
		case "bladecrypto_dsk_check":
			if(CheckCharacterItem(Pchar,"bladecrypto_dsk"))
			{
				LAi_QuestDelay("parchment_is_dirty", 3.0);
				return;
			}
			else
			{
				LAi_QuestDelay("bladecrypto_dsk_check", 1.0);//loop check
			}
		break;

		case "parchment_is_dirty":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "parchment_is_dirty";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "parchment_is_dirty_done":
			AddQuestRecord("The_parchment", "6");
			PlaySound("PEOPLE\step_iron.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			
			LAi_QuestDelay("parchment_is_dirty_done1", 1.0);
		break;

		case "parchment_is_dirty_done1":
			PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
			
			LAi_QuestDelay("parchment_is_dirty_done2", 1.0);
		break;

		case "parchment_is_dirty_done2":
			PlaySound("INTERFACE\closet_open.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "reload", "reload1");
			LAi_SetStayType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("parchment_is_dirty_done3", 1.0);
		break;

		case "parchment_is_dirty_done3":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "sleep";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "sleep_done":
			OpenQuestHeader("Useful_items");
			AddQuestRecord("Useful_items", "3");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "mixtable", "Jupiter_sleeps", 3.0);

			LAi_QuestDelay("Jupiter_sleeps1", 2.0);
		break;

		case "Jupiter_sleeps1":
			PlaySound("PEOPLE\yawn.wav");
		break;

		case "Jupiter_sleeps":
			PlaySound("PEOPLE\creak2.wav");
			
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "goto", "sleep");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorSetLayMode(characterFromID("Jupiter"));

			LAi_SetPlayerType(Pchar);
			
			Pchar.quest.house_box1 = "open";
			Locations[FindLocation("Legrands_house")].reload.l1.disable = 1;	//front door

			LAi_QuestDelay("bladecauldron_check", 1.0);
		break;

		case "bladecauldron_check":
			if(CheckCharacterItem(Pchar,"bladecauldron"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladecauldron");
				PlaySound("INTERFACE\wheel_take.wav");
				OpenQuestHeader("Useful_items");
				AddQuestRecord("Useful_items", "4");

				LAi_QuestDelay("bladecrypto_cskp_check", 1.0);
				return;
			}
			else
			{
				LAi_QuestDelay("bladecauldron_check", 1.0);//loop check
			}
		break;

		case "bladecrypto_cskp_check":
			if(CheckCharacterItem(Pchar,"bladecrypto_cskp"))
			{
				AddQuestRecord("The_parchment", "7");
				LAi_QuestDelay("Legrand_sleepy", 1.0);

				return;
			}
			else
			{
				LAi_QuestDelay("bladecrypto_cskp_check", 1.0);//loop check
			}
		break;

		case "gotobed_day1":
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "goto", "bed");
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);
			PlaySound("PEOPLE\snoring.wav");

			LAi_QuestDelay("boathouse_day", 2.0);
		break;

		case "Legrand_sleepy":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Legrand_sleepy";
			LAi_ActorSelfDialog(pchar, "");
		break;
//#2 from here
		case "Legrand_sleepy_done":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Locations[FindLocation("Legrands_house")].locators_radius.box.box8 = 1.0;
			LAi_SetPlayerType(pchar);
			
			pchar.quest.day1_end.win_condition.l1 = "locator";
			pchar.quest.day1_end.win_condition.l1.location = "Legrands_house";
			pchar.quest.day1_end.win_condition.l1.locator_group = "goto";
			pchar.quest.day1_end.win_condition.l1.locator = "bed";
			pchar.quest.day1_end.win_condition = "day1_end";
		break;

		case "day1_end":
			LAi_QuestDelay("day1_endA", 2.0);
		break;

		case "day1_endA":
			SetNextWeather("Clear");
			Locations[FindLocation("Legrands_house")].locators_radius.box.box8 = 0.0001;
			locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
			SetCurrentTime(7.00, 0);

			Locations[FindLocation("Legrands_house")].image = "";			//sign telling: ...
			DoQuestReloadToLocation("Legrands_house", "goto", "goto10", "day2_start");
		break;

		case "day2_start":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			SetCurrentTime(7.00, 0);
			
			LAi_SetSitType(pchar);
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "sit", "sitbed");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "goto", "sleep");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorSetLayMode(characterFromID("Jupiter"));

			LAi_QuestDelay("day2_startA", 2.0);
		break;

		case "day2_startA":
			SetCurrentTime(7.00, 0);
			Locations[FindLocation("Legrands_house")].image = "GB_Legrands_hut_inside.tga";
			Pchar.quest.Legrands_fireplace = "no_wood";
			locations[FindLocation("Legrands_kitchen")].models.always.l2 = "";		//no wood
			locations[FindLocation("Legrands_kitchen")].models.always.l10 = "ashes1";
			locations[FindLocation("Legrands_kitchen")].models.always.l11 = "ashes2";
			locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "goto", "staybed");
			
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "new_day";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "new_day_done":
			LAi_SetPlayerType(pchar);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
	
			pchar.quest.no_wood_first.win_condition.l1 = "locator";
			pchar.quest.no_wood_first.win_condition.l1.location = "Legrands_kitchen";
			pchar.quest.no_wood_first.win_condition.l1.locator_group = "goto";
			pchar.quest.no_wood_first.win_condition.l1.locator = "fireplace";
			pchar.quest.no_wood_first.win_condition = "no_wood_first";
		break;

		case "no_wood_first":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "no_wood_first";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "no_wood_first_done":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Locations[FindLocation("Legrands_kitchen")].locators_radius.goto.wake_up = 1.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "wake_up", 1.5);
			LAi_SetPlayerType(Pchar);

			pchar.quest.wake_up_Jup.win_condition.l1 = "locator";
			pchar.quest.wake_up_Jup.win_condition.l1.location = "Legrands_kitchen";
			pchar.quest.wake_up_Jup.win_condition.l1.locator_group = "goto";
			pchar.quest.wake_up_Jup.win_condition.l1.locator = "wake_up";
			pchar.quest.wake_up_Jup.win_condition = "wake_up_Jup";
		break;

		case "wake_up_Jup":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");

			LAi_QuestDelay("wake_up_Jup1", 2.0);
		break;

		case "wake_up_Jup1":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "sit", "sit4");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("wake_up_Jup1A", 2.0);
		break;

		case "wake_up_Jup1A":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "goto", "stay4");
			LAi_SetStayType(characterFromID("Jupiter"));

			LAi_QuestDelay("wake_up_Jup2", 1.0);
		break;

		case "wake_up_Jup2":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "wake_up_Jup";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "wake_up_Jup_done":
			OpenQuestHeader("Useful_items");
			AddQuestRecord("Useful_items", "5");

			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "close", "", "");
			
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "exit", "wake_up_Jup_done1", 3.0);
		break;

		case "wake_up_Jup_done1":
			PlaySound("INTERFACE\closed_door.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			locations[FindLocation("Legrands_house")].models.always.locators = "pirh_l_GB_key";
			Locations[FindLocation("Legrands_house")].reload.l1.disable = 0;	//front door

			LAi_QuestDelay("key20_check", 0.1);
		break;

		case "key20_check":
			if(CheckCharacterItem(Pchar,"key20"))
			{
				PlaySound("INTERFACE\took_item.wav");

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload3", 0.001);
				Locations[FindLocation("Legrands_house")].locators_radius.reload.reload3 = 0.001;
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 1.0);
				Locations[FindLocation("Legrands_house")].locators_radius.box.box9 = 1.0;

				return;
			}
			else
			{
				LAi_QuestDelay("key20_check", 0.5);//loop check
			}
		break;

		case "unlock_Legrands_grot":
			Locations[FindLocation("Legrands_house")].locators_radius.box.box9 = 0.0001;
			Locations[FindLocation("Legrands_house")].locators_radius.reload.reload3 = 1.0;
			Locations[FindLocation("Legrands_house")].reload.l3.disable = 0;
			locations[FindLocation("Legrands_grot")].id.label = "Legrands food cellar";
			
			DoQuestReloadToLocation("Legrands_grot", "reload", "reload1", "fill_grot_chests");
		break;

		case "fill_grot_chests":
			TakenItems(Pchar, "key20", -1);

			locations[FindLocation(Pchar.location)].box1.items.2winebottles = 1;

			locations[FindLocation(Pchar.location)].box2.items.bread = 5;
			locations[FindLocation(Pchar.location)].box2.items.fish = 2;

			locations[FindLocation(Pchar.location)].box4.items.tankard = 2;
			locations[FindLocation(Pchar.location)].box4.items.indian3 = 4;
			locations[FindLocation(Pchar.location)].box4.items.indian16 = 1;
			locations[FindLocation(Pchar.location)].box4.items.bladefryingpan = 1;

			LAi_QuestDelay("grot_remove_basket", 0.1);
			LAi_QuestDelay("bladefryingpan_autoequip", 1.0);
		break;

		case "empty_barrel":
			PlaySound("INTERFACE\rum_barrel_drip.wav");
		break;

		case "grot_take_food":			
			if(CheckCharacterItem(Pchar,"bread") || CheckCharacterItem(Pchar,"fish") 
			|| CheckCharacterItem(Pchar,"2winebottles"))
			{
				if(CheckCharacterItem(Pchar,"bread") || CheckCharacterItem(Pchar,"fish"))
				{ PlaySound("PEOPLE\clothes1.wav"); }

				if(CheckCharacterItem(Pchar,"2winebottles"))
				{ PlaySound("INTERFACE\glass1.wav"); }

				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
							
					
				TakenItems(Pchar, "bread", -5); TakenItems(Pchar, "fish", -2);
				TakenItems(Pchar, "2winebottles", -1);

				locations[FindLocation(Pchar.location)].box1.items.2winebottles = 0;
				locations[FindLocation(Pchar.location)].box2.items.bread = 0;
				locations[FindLocation(Pchar.location)].box2.items.fish = 0;
					
				locations[FindLocation(Pchar.location)].box1.items.2winebottles = 1;
				locations[FindLocation(Pchar.location)].box2.items.bread = 5;
				locations[FindLocation(Pchar.location)].box2.items.fish = 2;
			}
		break;

		case "grot_take_dishes":
			if(CheckCharacterItem(Pchar,"bladefryingpan"))
			{
			    if(CheckCharacterItem(Pchar,"indian3") || CheckCharacterItem(Pchar,"indian16") 
			    || CheckCharacterItem(Pchar,"tankard"))
			    {
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I only keep the tin can."));
				PlaySound("OBJECTS\duel\sword_fallen.wav");

				TakenItems(Pchar, "indian3", -4); TakenItems(Pchar, "indian16", -1);
				TakenItems(Pchar, "tankard", -2);
					
				locations[FindLocation(Pchar.location)].box4.items.tankard = 0;
				locations[FindLocation(Pchar.location)].box4.items.indian3 = 0;
				locations[FindLocation(Pchar.location)].box4.items.indian16 = 0;

				locations[FindLocation(Pchar.location)].box4.items.tankard = 2;
				locations[FindLocation(Pchar.location)].box4.items.indian3 = 4;
				locations[FindLocation(Pchar.location)].box4.items.indian16 = 1;				
			    }
			}
			else
			{
				if(CheckCharacterItem(Pchar,"indian3") || CheckCharacterItem(Pchar,"indian16") 
			    	|| CheckCharacterItem(Pchar,"tankard"))
			    	{
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
					PlaySound("OBJECTS\duel\sword_fallen.wav");

					TakenItems(Pchar, "indian3", -4); TakenItems(Pchar, "indian16", -1);
					TakenItems(Pchar, "tankard", -2);
					
					locations[FindLocation(Pchar.location)].box4.items.tankard = 0;
					locations[FindLocation(Pchar.location)].box4.items.indian3 = 0;
					locations[FindLocation(Pchar.location)].box4.items.indian16 = 0;

					locations[FindLocation(Pchar.location)].box4.items.tankard = 2;
					locations[FindLocation(Pchar.location)].box4.items.indian3 = 4;
					locations[FindLocation(Pchar.location)].box4.items.indian16 = 1;				
			    	}
			}
		break;

		case "grot_remove_basket":
			if(CheckCharacterItem(Pchar,"basket"))
			{
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box4", 1.2);	
				Locations[FindLocation(Pchar.location)].locators_radius.box.box4 = 1.2;
				TakeItemFromCharacter(Pchar, "basket");
				PlaySound("PEOPLE\jump.wav");
				PlaySound("PEOPLE\basket.wav");
				return;
			}
			else LAi_QuestDelay("grot_remove_basket", 0.5);//loop check
		break;
	
		case "bladefryingpan_autoequip":
			if(CheckCharacterItem(Pchar,"bladefryingpan"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladefryingpan");
				AddQuestRecord("Useful_items", "6");
				return;
			}
			else LAi_QuestDelay("bladefryingpan_autoequip", 1.0);//loop check
		break;

		case "wonder_where_Jupiter_is":
			Logit(TranslateString("","Okay, the parchment is in place - now it's only to wait for Jupiter and more wood."));
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");

			LAi_QuestDelay("wonder_where_Jupiter_is_done", 4.0);
		break;

		case "wonder_where_Jupiter_is_done":
			LAi_SetPlayerType(pchar);

			Locations[FindLocation("Sullivan_jungle1")].image = "";
			DoQuestReloadToLocation("Sullivan_jungle1", "goto", "goto6", "boathouse1");
		break;

		case "boathouse1":
			Locations[FindLocation("Sullivan_jungle1")].image = "GB_Legrands_hut_outside.tga";
			Pchar.quest.boathouse = "wood";	
		
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "Legrands_kitchen", "goto", "close");
			LAi_SetStayType(characterFromID("Legrand_copy"));

			LAi_QuestDelay("switch_to_Jupiter", 0.1);
			LAi_QuestDelay("bladewoodsack_autoequip", 1.0);
		break;

		case "bladewoodsack_autoequip":
			if(CheckCharacterItem(Pchar,"bladewoodsack"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladewoodsack");
				LAi_SetPlayerType(pchar);			
				Pchar.quest.boathouse = "return";
				ChangeCharacterAddressGroup(Pchar, "Legrands_boathouse", "goto", "box8");
				Locations[FindLocation("Legrands_kitchen")].locators_radius.goto.close = 2.0;
				CloseQuestHeader("Jupiters_wood_mission");
				Pchar.quest.fireplace_disabled = "no";
				
				pchar.quest.Jup_with_wood.win_condition.l1 = "locator";
				pchar.quest.Jup_with_wood.win_condition.l1.location = "Legrands_kitchen";
				pchar.quest.Jup_with_wood.win_condition.l1.locator_group = "goto";
				pchar.quest.Jup_with_wood.win_condition.l1.locator = "close";
				pchar.quest.Jup_with_wood.win_condition = "Jup_with_wood";
				return;
			}
			else
			{
				LAi_QuestDelay("bladewoodsack_autoequip", 1.0);//loop check
			}
		break;

		case "return_from_boathouse":
			CreateParticleSystemX("ball_splash", 17.1, -0.3, 0.6, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
			ChangeCharacterAddressGroup(Pchar, "Legrands_boathouse", "goto", "box1");
			LAi_SetSitType(pchar);
			Pchar.quest.boathouse = "return";

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Jup_with_wood":
			//from "bladewoodsack_autoequip"
			Characters[GetCharacterIndex("Legrand_copy")].dialog.CurrentNode  = "Jup_with_wood";
			LAi_SetActorType(characterFromID("Legrand_copy"));
			LAi_ActorTurnToCharacter(characterFromID("Legrand_copy"), PChar);
			LAi_ActorDialogNow(characterFromID("Legrand_copy"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Legrand_copy"));
		break;

		case "Jup_with_wood_done":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			LAi_SetStayType(characterFromID("Legrand_copy"));
		break;

		case "end_of_placing_woodsack2":
			//from  "end_of_placing_woodsack"
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			LAi_QuestDelay("end_of_placing_woodsack3", 1.0);
		break;

		case "end_of_placing_woodsack3":
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "close", "end_of_placing_woodsack4");
		break;

		case "end_of_placing_woodsack4":
		//Pchar.quest.exchange_items = "yes";

			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "goto", "fireplace");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "exit", "end_of_placing_woodsack5", 4.0);

			LAi_SetStayType(Pchar);

			LAi_QuestDelay("switch_to_Legrand", 0.1);	//1.0 was ok
		break;

		case "end_of_placing_woodsack5":
			PlaySound("INTERFACE\closed_door.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
		break;

		case "send_Jupiter_to_Moultrie":
			//from  "end_of_visible_text_clean2"
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_to_moultrie";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_to_moultrie_done":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_grot", "goto", "jupiter");

			pchar.quest.Jup_mission2.win_condition.l1 = "locator";
			pchar.quest.Jup_mission2.win_condition.l1.location = "Legrands_grot";
			pchar.quest.Jup_mission2.win_condition.l1.locator_group = "goto";
			pchar.quest.Jup_mission2.win_condition.l1.locator = "jupiter";
			pchar.quest.Jup_mission2.win_condition = "Jup_mission2";
		break;

		case "Jup_mission2":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_mission2";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;		

		case "Jup_mission2_done":
			LAi_SetPlayerType(Pchar);
			LAi_SetStayType(characterFromID("Jupiter"));
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");

			LAi_QuestDelay("Jup_mission2_doneA", 2.0);
		break;	

		case "Jup_mission2_doneA":
			Locations[FindLocation("Legrands_grot")].image = "";
			DoQuestReloadToLocation("Legrands_grot", "goto", "jupiter", "Jup_paper_mission");
		break;	

		case "Jup_paper_mission":
			Locations[FindLocation("Legrands_grot")].image = "GB_Legrands_storeroom.tga";
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "Legrands_grot", "goto", "legrand");
			LAi_SetStayType(characterFromID("Legrand_copy"));
			LAi_SetPlayerType(Pchar);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem15", 1.5);
			Locations[FindLocation("Legrands_house")].locators_radius.randitem.randitem15 = 1.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 0.001);
			Locations[FindLocation("Legrands_house")].locators_radius.box.box8 = 0.001;
			Pchar.quest.Jupiter_switch2 = "yes";
			Pchar.quest.Jupiter_paper_mission = "on";
			Pchar.quest.Jupiter_bug_mission = "on";
			Pchar.quest.Jupiter_cognac_sold = "no";
			Pchar.quest.Jupiter_fish_sold = "no";
			Characters[GetCharacterIndex("Moultrie_hotel_owner")].dialog.CurrentNode  = "first time";

			LAi_QuestDelay("switch_to_Jupiter", 0.1);
			LAi_QuestDelay("bladefish_autoequip", 1.0);
			LAi_QuestDelay("step_back_store", 2.0);
		break;

		case "bladefish_autoequip":
			if(CheckCharacterItem(Pchar,"bigfish"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "bigfish");
				GiveItem2Character(Pchar, "bladefish");
				EquipCharacterByItem(Pchar, "bladefish");

				LAi_QuestDelay("open_village", 0.1);
				return;
			}
			else
			{
				LAi_QuestDelay("bladefish_autoequip", 1.0);//loop check
			}
		break;

		case "open_village":
			Pchar.quest.bar_rum = "0";
			Pchar.quest.bar_wine = "0";
			Pchar.quest.bar_beer = "0";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "SmLexit_l_GB_smoke1";
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "Sml_l_GB_closed_smoke1";
			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.disable = 0;		//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l6.disable = 0;		//hotel
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.disable = 0;		//store
		//	Locations[FindLocation("Fort_Moultrie_village")].reload.l9.disable = 0;		//restaurant kitchen
			Locations[FindLocation("Fort_Moultrie_village")].reload.l10.disable = 0;	//restaurant
			locations[FindLocation("Fort_Moultrie_village")].type = "Fort_Moultrie_village";//music

			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.close_for_night = 1;	//store
			Locations[FindLocation("Fort_Moultrie_village")].reload.l13.close_for_night = 1;//restaurant
			//hotel always open

			locations[FindLocation("Moultrie_hotel")].id.label = "Fort Moultrie hotel";
			locations[FindLocation("Moultrie_restaurant")].id.label = "Fort Moultrie restaurant";
			locations[FindLocation("Moultrie_store")].id.label = "Fort Moultrie store";

			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Moultrie_restaurant", "sit", "sit1");
			LAi_SetSitType(characterFromID("Lieutenant G"));
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist1"), "Fort_Moultrie_village", "goto", "goto25");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist2"), "Fort_Moultrie_village", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist3"), "Fort_Moultrie_village", "goto", "goto26");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist4"), "Fort_Moultrie_village", "goto", "goto13");

			LAi_QuestDelay("empty_bottle_check", 0.5);
		break;

		case "paper_linen_info":
			AddQuestRecord("Jupiters_Moultrie_mission","8");
		break;

		case "liquor_info":
			AddQuestRecord("Jupiters_Moultrie_mission","9");
		break;

		case "step_back_store":
			LAi_SetPlayerType(Pchar);
			LAi_SetMerchantType(characterFromID("Moultrie_store_owner"));

			pchar.quest.step_back_store1.win_condition.l1 = "locator";
			pchar.quest.step_back_store1.win_condition.l1.location = "Moultrie_store";
			pchar.quest.step_back_store1.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_store1.win_condition.l1.locator = "stop";
			pchar.quest.step_back_store1.win_condition = "step_back_store1";
		break;

		case "step_back_store1":
			ChangeCharacterAddressGroup(Pchar, "Moultrie_store", "goto", "back");
			LAi_SetStayType(Pchar);
			PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");
			PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");

			Characters[GetCharacterIndex("Moultrie_store_owner")].dialog.CurrentNode  = "stop";
			LAi_SetActorType(characterFromID("Moultrie_store_owner"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_store_owner"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_store_owner"), pchar, "", 0.01);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_store_owner"));
		break;

		case "unlock_restaurant_kitchen":
			//from itemlogic
			Locations[FindLocation("Moultrie_restaurant_kitchen")].locators_radius.box.box1 = 0.0001;
			Locations[FindLocation("Moultrie_restaurant_kitchen")].locators_radius.reload.reload1 = 1.0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l9.disable = 0;
			
			DoQuestReloadToLocation("Fort_Moultrie_village", "reload", "reload9", "");
		break;

		case "empty_bottle_check":
			if(CheckCharacterItem(Pchar,"empty_bottle"))
			{
				AddQuestRecord("Jupiters_Moultrie_mission","6");
				PlaySound("INTERFACE\button2.wav");

				TakeItemFromCharacter(Pchar, "empty_bottle");
				GiveItem2Character(Pchar, "bladebottle_CE0");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladebottle_CE0");

				return;
			}
			else
			{
				LAi_QuestDelay("empty_bottle_check", 0.5);//loop check
			}
		break;

		case "restaurant_running_cognac":
			//from itemlogic
			if(CheckAttribute(Pchar,"quest.restaurant_cognac") && Pchar.quest.restaurant_cognac == "off")
			{
				return;
			}
			else
			{
				PlaySound("INTERFACE\running_water_short.wav");

				LAi_QuestDelay("restaurant_running_cognac", 1.1);
			}
		break;

		case "restaurant_bouncer_arrives":
			LAi_SetOfficerType(characterFromID("Moultrie_bouncer"));

			LAi_QuestDelay("restaurant_bouncer_arrives1", 1.0);
		break;

		case "restaurant_bouncer_arrives1":
			if(CheckAttribute(Pchar,"quest.restaurant_cognac") && Pchar.quest.restaurant_cognac == "on")
			{
				Characters[GetCharacterIndex("Moultrie_bouncer")].dialog.CurrentNode  = "turn_off_cognac";
				LAi_SetActorType(characterFromID("Moultrie_bouncer"));
				LAi_ActorTurnToCharacter(characterFromID("Moultrie_bouncer"), PChar);
				LAi_ActorDialogNow(characterFromID("Moultrie_bouncer"), pchar, "", 0.1);
				LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_bouncer"));
			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Moultrie_bouncer"), "Moultrie_restaurant", "goto", "thug");
				LAi_SetStayType(characterFromID("Moultrie_bouncer"));
			}
		break;

		case "bouncer_warning_done":
			LAi_QuestDelay("bouncer_warning_done1", 2.0);
		break;

		case "bouncer_warning_done1":
			if(CheckAttribute(Pchar,"quest.restaurant_cognac") && Pchar.quest.restaurant_cognac == "on")
			{
				Pchar.quest.restaurant_cognac = "off";
				PlaySound("OBJECTS\DUEL\punch1.wav");
				LAi_SetPoorType(Pchar);
				float Php;
				Php = LAi_GetCharacterHP(Pchar);
				LAi_ApplyCharacterDamage(Pchar, Php/2);

				LAi_QuestDelay("bouncer_knocking", 0.5);
			}
			else 
			{
				ChangeCharacterAddressGroup(characterFromID("Moultrie_bouncer"), "Moultrie_restaurant", "goto", "thug");
				LAi_SetStayType(characterFromID("Moultrie_bouncer"));
			}
		break;

		case "bouncer_knocking":
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);

			LAi_QuestDelay("bouncer_knocking1", 1.0);
		break;

		case "bouncer_knocking1":
			Locations[FindLocation("Fort_Moultrie_village")].image = "";
			DoQuestReloadToLocation("Fort_Moultrie_village", "officers", "reload10_3", "bouncer_knocking2");
		break;

		case "bouncer_knocking2":
			PlaySound("PEOPLE\jump.wav");
			Php = LAi_GetCharacterHP(Pchar);
			LAi_ApplyCharacterDamage(Pchar, Php/2);
			Locations[FindLocation("Fort_Moultrie_village")].image = "GB_Moultrie_village.tga";

			LAi_QuestDelay("bouncer_knocking3", 2.0);
		break;

		case "bouncer_knocking3":
			LAi_SetPoorType(Pchar);
			//float u, v, w;
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");

			LAi_QuestDelay("bouncer_knocking4", 3.0);
		break;

		case "bouncer_knocking4":
			LAi_SetPlayerType(Pchar);

			ChangeCharacterAddressGroup(characterFromID("Moultrie_bouncer"), "Moultrie_restaurant", "goto", "thug");
			LAi_SetStayType(characterFromID("Moultrie_bouncer"));
		break;


		case "restaurant_fill_cognacbottle":
			PlaySound("AMBIENT\TAVERN\tinkle1.wav");

			LAi_QuestDelay("restaurant_fill_cognacbottle1", 3.0);
		break;

		case "restaurant_fill_cognacbottle1":
			Pchar.quest.restaurant_fillbottle = "off";
			PlaySound("AMBIENT\TAVERN\open_bottle.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebottle_CE0");
			GiveItem2Character(Pchar,"bladebottle_CB2");
			EquipCharacterByItem(Pchar, "bladebottle_CB2");

			LAi_SetPlayerType(Pchar);
		break;

		case "G_returns_bug":
			GiveItem2Character(Pchar, "goldbug2");
			TakeItemFromCharacter(characterFromID("Lieutenant G"), "goldbug");
			AddQuestRecord("Jupiters_Moultrie_mission","4");
			Pchar.quest.Jupiter_bug_mission = "off";

			if(CheckCharacterItem(Pchar,"letter_paper"))
			{
				LAi_QuestDelay("Jup_paper_bug_mission_complete", 0.5);
			}
		break;	

		case "sell_fish_done":
			PlaySound("PEOPLE\clothes3.wav");
			PlaySound("PEOPLE\clothes3.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladefish");
			GiveItem2Character(characterFromID("Moultrie_restaurant_owner"), "bladefish");
			EquipCharacterByItem(characterFromID("Moultrie_restaurant_owner"), "bladefish");
			AddQuestRecord("Jupiters_Moultrie_mission","7");
			Pchar.quest.Jupiter_fish_sold = "yes";
		break;

		case "cognac_sold":
			PlaySound("INTERFACE\button2.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebottle_CB2");
			Pchar.quest.Jupiter_cognac_sold = "yes";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "stop", 0.0001);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload2", 0.8);
			Locations[FindLocation("Moultrie_store")].locators_radius.goto.stop = 0.0001;
			Locations[FindLocation("Moultrie_store")].locators_radius.reload.reload2 = 0.8;

			LAi_QuestDelay("pistolbedlinen_check", 1.0);
			LAi_QuestDelay("Pym_drunk", 1.0);
			
			pchar.quest.fill_store_room_chests.win_condition.l1 = "location";
			pchar.quest.fill_store_room_chests.win_condition.l1.location = "Moultrie_store_room";
			pchar.quest.fill_store_room_chests.win_condition = "fill_store_room_chests";
		break;

		case "fill_store_room_chests":
			locations[FindLocation(Pchar.location)].box5.items.tobacco = 2;
		break;

		case "Pym_drunk":
			LAi_SetActorType(characterFromID("Moultrie_store_owner"));
			LAi_ActorGoToLocator(characterFromID("Moultrie_store_owner"), "goto", "near_chair", "Pym_drunk1", 2.0);
		break;

		case "Pym_drunk1":
			ChangeCharacterAddressGroup(characterFromID("Moultrie_store_owner"), "Moultrie_store", "sit", "sit1");
	
			LAi_QuestDelay("Pym_drunk2", 1.0);
		break;

		case "Pym_drunk2":
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetSitType(characterFromID("Moultrie_store_owner"));

			LAi_QuestDelay("Pym_drunk3", 1.0);
		break;

		case "Pym_drunk3":
			PlaySound("AMBIENT\TAVERN\open_bottle.wav");

			LAi_QuestDelay("Pym_drunk4", 1.0);
		break;

		case "Pym_drunk4":
			PlaySound("AMBIENT\TAVERN\man6.wav");
		break;

		case "pistolbedlinen_check":
			if(CheckCharacterItem(Pchar,"pistolbedlinen"))
			{
				PlaySound("PEOPLE\clothes1.wav");
				EquipCharacterByItem(Pchar, "bladeX4");
				EquipCharacterByItem(Pchar, "pistolbedlinen");

				return;
			}
			else
			{
				LAi_QuestDelay("pistolbedlinen_check", 0.5);//loop check
			}
		break;

		case "linen_sold":
			PlaySound("PEOPLE\clothes1.wav");
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolbedlinen");
			GiveItem2Character(characterFromID("Moultrie_hotel_owner"), "pistolbedlinen");

			LAi_QuestDelay("linen_sold1", 1.5);
		break;

		case "linen_sold1":
			Characters[GetCharacterIndex("Moultrie_hotel_owner")].dialog.CurrentNode  = "key";
			LAi_SetActorType(characterFromID("Moultrie_hotel_owner"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_hotel_owner"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_hotel_owner"), pchar, "", 0.01);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_hotel_owner"));
		break;

		case "room_key":
			LAi_SetWaitressType(characterFromID("Moultrie_hotel_owner"));

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.8);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "locator1", 0.0001);
			Locations[FindLocation("Moultrie_hotel")].locators_radius.box.box1 = 0.8;
			Locations[FindLocation("Moultrie_hotel")].locators_radius.reload.locator1 = 0.0001;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box2", 0.8);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload4", 0.0001);
			Locations[FindLocation("Moultrie_hotel")].locators_radius.box.box2 = 0.8;
			Locations[FindLocation("Moultrie_hotel")].locators_radius.reload.reload4 = 0.0001;
		break;

		case "unlock_hotel_room1":
			Locations[FindLocation("Moultrie_hotel")].reload.l2.disable = 0;		//to room1	
			Locations[FindLocation("Moultrie_hotel")].locators_radius.box.box1 = 0.0001;
			Locations[FindLocation("Moultrie_hotel")].locators_radius.reload.locator1 = 1.0;

			Locations[FindLocation("Moultrie_hotel")].locators_radius.box.box2 = 0.0001;
			Locations[FindLocation("Moultrie_hotel")].locators_radius.reload.reload4 = 1.0;
			
			DoQuestReloadToLocation("Moultrie_hotel_room1", "reload", "reload1", "fill_hotel_room1_chests");
		break;

		case "fill_hotel_room1_chests":
			locations[FindLocation(Pchar.location)].box4.items.letter_paper = 1;
			TakeItemFromCharacter(Pchar, "key21");	

			LAi_QuestDelay("letter_paper_check", 0.5);
		break;

		case "letter_paper_check":
			if(CheckCharacterItem(Pchar,"letter_paper"))
			{
				AddQuestRecord("Jupiters_Moultrie_mission","5");
				PlaySound("INTERFACE\paper.wav");
				Pchar.quest.Jupiter_paper_mission = "off";

				pchar.quest.lock_room1.win_condition.l1 = "location";
				pchar.quest.lock_room1.win_condition.l1.location = "Moultrie_hotel";
				pchar.quest.lock_room1.win_condition = "lock_room1";

				if(CheckCharacterItem(Pchar,"goldbug2"))
				{
					LAi_QuestDelay("Jup_paper_bug_mission_complete", 0.5);
				}

				return;
			}
			else
			{
				LAi_QuestDelay("letter_paper_check", 0.5);//loop check
			}
		break;

		case "lock_room1":
			PlaySound("INTERFACE\key_lock.wav");
			Locations[FindLocation("Moultrie_hotel")].reload.l2.disable = 1;		//to room1	
		break;
	
		case "restore_hp_Moultrie":
			LAi_SetCurHPMax(pchar);

			pchar.quest.lock_room2_A.win_condition.l1 = "location";
			pchar.quest.lock_room2_A.win_condition.l1.location = "Moultrie_hotel";
			pchar.quest.lock_room2_A.win_condition = "lock_room2_A";
		break;

		case "lock_room2_A":
			PlaySound("INTERFACE\key_lock.wav");			
		break;

		case "Jup_paper_bug_mission_complete":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"I got de papers and de bug. I'll return home now."));
			CloseQuestHeader("Jupiters_Moultrie_mission");
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");

			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "Legrands_house", "goto", "staybed");
			Locations[FindLocation("Legrands_house")].locators_radius.goto.staybed = 2.5;

			RemoveCharacterEquip(characterFromID("Moultrie_restaurant_owner"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Moultrie_restaurant_owner"), "bladefish");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_store_owner"), "Moultrie_store", "barmen", "stay");
			LAi_SetMerchantType(characterFromID("Moultrie_store_owner"));

			Locations[FindLocation("Moultrie_store")].locators_radius.goto.stop = 0.8;
			Locations[FindLocation("Moultrie_store")].locators_radius.reload.reload2 = 0.0001;

			Pchar.quest.Legrands_fireplace = "no_wood";
			locations[FindLocation("Legrands_kitchen")].models.always.l2 = "";		//no wood
			Locations[FindLocation("Legrands_kitchen")].models.always.l6 = "fryingpan";
			locations[FindLocation("Legrands_kitchen")].models.always.l10 = "ashes1";
			locations[FindLocation("Legrands_kitchen")].models.always.l11 = "ashes2";
			locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
			Pchar.quest.Legrands_fryingpan = "in_fireplace";
			Pchar.quest.Legrands_cauldron_water = "cold";
			Pchar.quest.Legrands_fryingpan_temp = "cold";
			Pchar.quest.Legrands_fryingpan = "in_fireplace";

			pchar.quest.return_paper_bug.win_condition.l1 = "locator";
			pchar.quest.return_paper_bug.win_condition.l1.location = "Legrands_house";
			pchar.quest.return_paper_bug.win_condition.l1.locator_group = "goto";
			pchar.quest.return_paper_bug.win_condition.l1.locator = "staybed";
			pchar.quest.return_paper_bug.win_condition = "return_paper_bug";
		break;	

		case "return_paper_bug":
			Characters[GetCharacterIndex("Legrand_copy")].dialog.CurrentNode  = "Jup_with_paper_bug";
			LAi_SetActorType(characterFromID("Legrand_copy"));
			LAi_ActorTurnToCharacter(characterFromID("Legrand_copy"), PChar);
			LAi_ActorDialogNow(characterFromID("Legrand_copy"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Legrand_copy"));
		break;	

		case "Jup_with_paper_bug_done":
			LAi_SetPlayerType(Pchar);

			Locations[FindLocation("Sullivan_shore1")].models.always.locators = "shore10_l_GB_wood";
			Locations[FindLocation("Sullivan_shore2")].models.always.locators = "Shore02_l_GB_wood";
			Locations[FindLocation("Sullivan_shore3")].models.always.locators = "ShoreShip_l_GB_wood";

			locations[FindLocation("Sullivan_shore1")].type = "Sullivan_seashore";
			locations[FindLocation("Sullivan_shore2")].type = "Sullivan_seashore";
			locations[FindLocation("Sullivan_shore3")].type = "Sullivan_seashore";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload2");
			
			LAi_QuestDelay("wood_shores", 1.0);
		break;	

		case "wood_shores":
		//Pchar.quest.exchange_items = "no";

			int pearl = GetCharacterItem(Pchar, "jewelry12");
			if(pearl > 1) 
			{
				TakenItems(Pchar, "jewelry12", -100);   
				TakenItems(Pchar, "jewelry12", 1); 
			}

			int tinder = GetCharacterItem(characterFromID("Legrand_copy"), "pistoltinderbox");
			if(tinder > 1) 
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), GUN_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "pistoltinderbox", -100);     
				TakenItems(characterFromID("Legrand_copy"), "pistoltinderbox", 1); 
				EquipCharacterByItem(characterFromID("Legrand_copy"), "pistoltinderbox");	
			}

			AddPassenger(Pchar, characterFromID("Legrand_copy"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Legrand_copy"));
			LAi_SetPlayerType(characterFromID("Legrand_copy"));
			LAi_SetOfficerType(characterFromID("Legrand_copy"));
		AddMoneyToCharacter(characterFromID("Legrand_copy"), -1000);

			LAi_QuestDelay("wood_shores1", 0.1);
			LAi_QuestDelay("Legrand_copy_equip_check", 1.0);
		break;

		case "wood_shores1":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			LAi_SetPlayerType(Pchar);
		break;

		case "delete_9_driftwood":
			Pchar.quest.driftwood = "yes";
			TakeNItems(Pchar,"1_log", -9);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			TakeNItems(characterFromID("Legrand_copy"),"1_log", 9);
	Pchar.quest.fireplace_disabled = "no";
		break;

		case "Legrand_copy_equip_check":
			if(Pchar.model == "William Legrand") return;

			if(CheckCharacterItem(characterFromID("Legrand_copy"), "bladeemptysack_B"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Legrand_copy"), "bladeemptysack_B"))
				{
					RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
					EquipCharacterByItem(characterFromID("Legrand_copy"), "bladeemptysack_B");
				}

				if(CheckCharacterItem(characterFromID("Legrand_copy"), "pistoltinderbox"))
				{
					if(!IsEquipCharacterByItem(characterFromID("Legrand_copy"), "pistoltinderbox"))
					{
						RemoveCharacterEquip(characterFromID("Legrand_copy"), GUN_ITEM_TYPE);
						EquipCharacterByItem(characterFromID("Legrand_copy"), "pistoltinderbox");
					}
				}

				LAi_QuestDelay("Legrand_copy_equip_check", 5.0);
			}
			else return;
		break;

		case "second_placing_woodsack":
			//from itemlogic
			Locations[FindLocation("Legrands_kitchen")].image = "";
	
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "fireplace", "second_placing_woodsack1");
		break;

		case "second_placing_woodsack1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";

			LAi_QuestDelay("second_placing_woodsack2", 1.0);
		break;

		case "second_placing_woodsack2":
			Locations[FindLocation("Legrands_kitchen")].image = "";
			DoQuestReloadToLocation("Legrands_kitchen", "goto", "close", "second_placing_woodsack3");
		break;

		case "second_placing_woodsack3":
	//Pchar.quest.exchange_items = "yes";

			Locations[FindLocation("Legrands_kitchen")].image = "GB_Legrands_kitchen.tga";
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_kitchen", "goto", "fireplace");
		
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("switch_to_Legrand", 0.1);	//1.0 was ok
			LAi_QuestDelay("second_placing_woodsack4", 1.0);
		break;

		case "second_placing_woodsack4":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_takes_sack_in_kitchen";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "second_placing_woodsack5":
			//from Jup dialog
			PlaySound("PEOPLE\clothes1.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakenItems(Pchar, "bladewoodsack", -1);
			if(CheckCharacterItem(Pchar,"bladecrypto_cl")) EquipCharacterByItem(Pchar, "bladecrypto_cl");
			if(CheckCharacterItem(Pchar,"bladecrypto_csk")) EquipCharacterByItem(Pchar, "bladecrypto_csk");
			if(CheckCharacterItem(Pchar,"bladecrypto_cskp")) EquipCharacterByItem(Pchar, "bladecrypto_cskp");
			if(CheckCharacterItem(Pchar,"bladecrypto_cskt")) EquipCharacterByItem(Pchar, "bladecrypto_cskt");

			TakenItems(characterFromID("Jupiter"), "bladewoodsack", 1);
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Jupiter"), "bladewoodsack");
		
			LAi_QuestDelay("second_placing_woodsack6", 2.0);
		break;
	
		case "second_placing_woodsack6":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "exit", "second_placing_woodsack7", 4.0);
		break;

		case "second_placing_woodsack7":
			PlaySound("INTERFACE\closed_door.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
		break;

		case "copy_full_code":
			//from "end_of_visible_text_clean"

			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "copy_full_code";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "copy_full_code_now":
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
		
			LAi_QuestDelay("copy_full_code_done", 5.0);
		break;
//JRH add selfdialog about lut G in fort
		case "copy_full_code_done":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			CloseQuestHeader("The_parchment");
			SetQuestHeader("The_message");
			AddQuestRecord("The_message","1");
			TakenItems(Pchar, "letter_paper", -1);	//maybe keep (1) paper for write down clear text in the future
			TakenItems(Pchar, "crypto1", 1);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "goto", "goto10");
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			TakenItems(characterFromID("Jupiter"), "bladewoodsack", -1);
			
			Locations[FindLocation("Legrands_house")].locators_radius.goto.goto10 = 2.0;
			Pchar.quest.fireplace_disabled = "yes";			//maybe never enabled again?

			LAi_SetStayType(pchar);

			LAi_QuestDelay("launch_items_inventory", 1.0);
		break;

		case "Lut_G_cipher":
			//from checking crypto1 items.c

			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Lut_G_cipher";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "copy_full_code_done1":
			AddQuestRecord("The_message","2");
			LAi_SetPlayerType(pchar);

			pchar.quest.copy_full_code_done2.win_condition.l1 = "locator";
			pchar.quest.copy_full_code_done2.win_condition.l1.location = "Legrands_house";
			pchar.quest.copy_full_code_done2.win_condition.l1.locator_group = "goto";
			pchar.quest.copy_full_code_done2.win_condition.l1.locator = "goto10";
			pchar.quest.copy_full_code_done2.win_condition = "copy_full_code_done2";
		break;

		case "copy_full_code_done2":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Legrand_to_fort";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Legrand_to_fort_done":
			//from Jupiter dialog
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "wrinkled_paper", 1);
			TakenItems(characterFromID("Jupiter"), "wrinkled_paper", -1);
			LAi_SetStayType(pchar);
			Pchar.quest.Fort_visit = "1";
			LAi_SetStayType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("open_village_full", 1.0);
			LAi_QuestDelay("launch_items_inventory", 3.0);
		break;

		case "launch_items_inventory":
			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
		break;

		case "open_village_full":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");		

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2";
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "sml_l_GB_closed_smoke2";

			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.disable = 0;		//finehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.disable = 0;		//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.disable = 0;		//largehouse

			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.close_for_night = 1;	//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.close_for_night = 1;	//largehouse

			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist5"), "Moultrie_restaurant", "sit", "sit7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist7"), "Moultrie_restaurant", "sit", "sit5");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist9"), "Moultrie_restaurant", "sit", "sit8");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist10"), "Moultrie_restaurant", "sit", "sit23");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist11"), "Moultrie_restaurant", "sit", "sit21");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist6"), "Fort_Moultrie_village", "reload", "reload7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist8"), "Moultrie_finehouse", "goto", "locator1");
		ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_M_tower1A", "goto", "goto4");
		LAi_SetStayType(characterFromID("Lieutenant G"));

			pchar.quest.G_dialog_visit1.win_condition.l1 = "locator";
			pchar.quest.G_dialog_visit1.win_condition.l1.location = "Fort_M_tower1A";
			pchar.quest.G_dialog_visit1.win_condition.l1.locator_group = "goto";
			pchar.quest.G_dialog_visit1.win_condition.l1.locator = "goto3";
			pchar.quest.G_dialog_visit1.win_condition = "G_dialog_visit1";
		break;

		case "open_village_full_jumpstart4":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");		

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2";
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "sml_l_GB_open_smoke2";

			locations[FindLocation("Fort_Moultrie_village")].type = "Fort_Moultrie_village";

			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.disable = 0;	
			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.disable = 0;		//finehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.disable = 0;		//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l6.disable = 0;	
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.disable = 0;		//largehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.disable = 0;	
			Locations[FindLocation("Fort_Moultrie_village")].reload.l9.disable = 0;	
			Locations[FindLocation("Fort_Moultrie_village")].reload.l10.disable = 0;	

			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.close_for_night = 1;	//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.close_for_night = 1;	//largehouse

			locations[FindLocation("Moultrie_hotel")].id.label = "Fort Moultrie hotel";
			locations[FindLocation("Moultrie_restaurant")].id.label = "Fort Moultrie restaurant";
			locations[FindLocation("Moultrie_store")].id.label = "Fort Moultrie store";

			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist1"), "Fort_Moultrie_village", "goto", "goto25");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist2"), "Fort_Moultrie_village", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist3"), "Fort_Moultrie_village", "goto", "goto26");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist4"), "Fort_Moultrie_village", "goto", "goto13");			
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist6"), "Fort_Moultrie_village", "reload", "reload7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist8"), "Moultrie_finehouse", "goto", "locator1");
		ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_M_tower1A", "goto", "goto4");
		LAi_SetStayType(characterFromID("Lieutenant G"));

			pchar.quest.G_dialog_visit1.win_condition.l1 = "locator";
			pchar.quest.G_dialog_visit1.win_condition.l1.location = "Fort_M_tower1A";
			pchar.quest.G_dialog_visit1.win_condition.l1.locator_group = "goto";
			pchar.quest.G_dialog_visit1.win_condition.l1.locator = "goto3";
			pchar.quest.G_dialog_visit1.win_condition = "G_dialog_visit1";
		break;
	//-------------------------------------------------------------------------------------------------------
		case "unlock_Moultrie_armory":
			//from itemlogic
			Locations[FindLocation("Fort_Moultrie_armory")].locators_radius.box.box1 = 0.0001;
			Locations[FindLocation("Fort_Moultrie_armory")].locators_radius.reload.reload2 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].reload.l13.disable = 0;
			
			DoQuestReloadToLocation("Fort_Moultrie", "reload", "reload13", "");
		break;

		case "Fort_M_high_wall1":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box7");

			LAi_QuestDelay("pchar_staytype", 0.5);
		break;

		case "Fort_M_turn_to_look1":
			Locations[FindLocation("Fort_Moultrie")].image = "GB_Fort_Moultrie.tga";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
	//--------------------------------------------------------------------------------------------

		case "Fort_M_turn_to_look2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_look3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look3");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_look4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look4");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_look5":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look5");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_ri8":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem8");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_box18":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box18");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		case "Fort_M_go_to_box26":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box26");
		break;
	
		case "Fort_M_turn_to_box21":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box21");
			
			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Fort_M_go_to_box27":
			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box27");
	
			LAi_QuestDelay("Fort_M_turn_to_reload6", 1.0);
		break;

		case "Fort_M_turn_to_reload6":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload6");
			
			LAi_QuestDelay("pchar_playertype", 0.5);
		break;
	
		case "Fort_M_go_to_box20":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box20");

			if(CheckAttribute(Pchar, "quest.Fort_M_south_wall") && Pchar.quest.Fort_M_south_wall == "right")
			{
				LAi_QuestDelay("Fort_M_turn_to_box16", 1.0);
			}
		break;
	
		case "Fort_M_go_to_box24":
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box24");
		break;

		case "Fort_M_go_to_box28":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box28");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_prepare_to_box21":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("Fort_M_go_to_box21", 1.0);
		break;

		case "Fort_M_go_to_box21":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box21");

			LAi_QuestDelay("Fort_M_turn_to_box22", 1.0);
		break;

		case "Fort_M_go_to_box25":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box25");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Fort_M_turn_to_ship1":
			Pchar.quest.Fort_M_turn_to_ship = "done";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ship_1");
			
			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("pchar_hah", 2.0);
		break;

	//--------------------------------------------------------------------------------------------

		case "place_usa_flag":
			Locations[FindLocation("Fort_Moultrie")].image = "";
			Locations[FindLocation(Pchar.location)].models.always.locators = "fort2_locators_GB2";	
			Locations[FindLocation("Fort_Moultrie")].type = "silent_town";		

			DoQuestReloadToLocation("Fort_Moultrie", "goto", "box35", "place_usa_flag2");
		break;
	
		case "place_usa_flag2":
			PlaySound("INTERFACE\pinion_place.wav");
			Pchar.quest.Fort_M_flag_pos = "down";
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Fort_Moultrie")], true);
			Locations[FindLocation("Fort_Moultrie")].image = "GB_Fort_Moultrie.tga";
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("place_usa_flag3", 1.0);
		break;

		case "place_usa_flag3":
			PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
		break;

		case "raise_usa_flag":
			LAi_SetSitType(Pchar);
			PlaySound("PEOPLE\creak.wav");

			LAi_QuestDelay("raise_usa_flag2", 1.0);
		break;

		case "raise_usa_flag2":
			Pchar.quest.Fort_M_flag_pos = "up";
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Fort_Moultrie")].image = "";
			Locations[FindLocation(Pchar.location)].models.always.locators = "fort2_locators_GB3";	

			DoQuestReloadToLocation("Fort_Moultrie", "goto", "box35", "raise_usa_flag3");
			Locations[FindLocation("Fort_Moultrie")].image = "GB_Fort_Moultrie.tga";
		break;

		case "raise_usa_flag3":
			PlaySound("AMBIENT\SEASHORE\fanfare2.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box34");		

			LAi_QuestDelay("pchar_playertype", 0.5);
			LAi_QuestDelay("equip_bladespyglass6", 0.1);

			Pchar.quest.reset_fort_music.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.reset_fort_music.win_condition.l1.location = "Fort_Moultrie";
			Pchar.quest.reset_fort_music.win_condition = "reset_fort_music";
		break;

		case "reset_fort_music":
			Locations[FindLocation("Fort_Moultrie")].type = "Fort_Moultrie";
		break;

	//--------------------------------------------------------------------------------------------
	/*
		case "unlock_FM_barracks":
			Locations[FindLocation("Fort_Moultrie")].locators_radius.box.box36 = 0.0001;
			Locations[FindLocation("Fort_Moultrie")].locators_radius.reload.reload10 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].reload.l10.disable = 0;
			locations[FindLocation("Fort_Moultrie_barracks_entre")].id.label = "Fort Moultrie barracks";	
			
			DoQuestReloadToLocation("Fort_Moultrie_barracks_entre", "reload", "reload1", "unlock_FM_barracks2");
		break;

		case "unlock_FM_barracks2":
			TakenItems(Pchar, "key5", -1);


		break;

		case "unlock_FM_prison":
			Locations[FindLocation("Fort_Moultrie")].locators_radius.box.box37 = 0.0001;
			Locations[FindLocation("Fort_Moultrie")].locators_radius.reload.reload2 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].reload.l2.disable = 0;
			locations[FindLocation("Fort_Moultrie_prison")].id.label = "Fort Moultrie prison";
			
			DoQuestReloadToLocation("Fort_Moultrie_prison", "goto", "goto130", "unlock_FM_prison2");
		break;

		case "unlock_FM_prison2":
			TakenItems(Pchar, "key6", -1);

			
		break;
	*/
		case "unlock_FM_Ghouse":
			Locations[FindLocation("Fort_Moultrie")].locators_radius.box.box38 = 0.0001;
			Locations[FindLocation("Fort_Moultrie")].locators_radius.reload.reload5 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].reload.l5.disable = 0;
			locations[FindLocation("Lieutenant_G_kitchen")].id.label = "Lieutenant G:s house";
			
			DoQuestReloadToLocation("Lieutenant_G_kitchen", "reload", "reload1", "unlock_FM_Ghouse2");
		break;

		case "unlock_FM_Ghouse2":
			TakenItems(Pchar, "key7", -1);
		break;

		case "unlock_FM_GateTower":
			DoQuestReloadToLocation("Fort_M_tower5A", "goto", "goto4", "unlock_FM_GateTower2");
		break;

		case "unlock_FM_GateTower2":
			Pchar.quest.Fort_M_gate_wall = "right";
			TakenItems(Pchar, "key31", -1);
			Pchar.quest.fort_box17 = "open";
		break;

	//--------------------------------------------------------------------------------------------

		case "fort_tower_spyglass":
			if(CheckCharacterItem(Pchar,"spyglass6"))
			{
				TakeItemFromCharacter(Pchar, "spyglass6");
				GiveItem2Character(Pchar, "bladespyglass6");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterbyItem(Pchar, "bladespyglass6");
				PlaySound("INTERFACE\button1.wav");
			}
			else LAi_QuestDelay("fort_tower_spyglass", 0.5);
		break;

	//--------------------------------------------------------------------------------------------

		case "fort_ladder_check":
			if(CheckCharacterItem(Pchar,"ladder_big_45"))
			{
				TakeItemFromCharacter(Pchar, "ladder_big_45");
				GiveItem2Character(Pchar, "bladeladder2");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladeladder2");
				Pchar.quest.Fort_M_ladder_wall = "right";
			
				LAi_QuestDelay("fort_ladder_check2", 1.0);	
				return;
			}
			else
			{
				LAi_QuestDelay("fort_ladder_check", 0.5);//loop check
			}
		break;

		case "fort_ladder_check2":
			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "goto", "box18");


		break;

//--------------------------------------------------------------------------------------------------------------------
//story continues here

		case "Fort_visit_neutral":
			AddQuestRecord("The_message","5");
			Pchar.quest.Fort_visit = "neutral";
		break;

		case "Fort_visit_neutral2":
			AddQuestRecord("Navigation_items","11");
			Pchar.quest.Fort_visit = "neutral";
		break;

		case "Fort_visit_neutral3":
			AddQuestRecord("Weapons","4");
			AddQuestRecord("Useful_items","15");
			Pchar.quest.Fort_visit = "neutral";
		break;

		case "G_dialog_visit1":
			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "key7";
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToCharacter(characterFromID("Lieutenant G"), PChar);
			LAi_ActorDialogNow(characterFromID("Lieutenant G"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Lieutenant G"));
		break;

		case "key7_given":
			PlaySound("INTERFACE\took_item.wav");
			TakenItems(Pchar, "key7", 1);
			Locations[FindLocation("Fort_Moultrie")].locators_radius.box.box38 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].locators_radius.reload.reload5 = 0.0001;
			Pchar.quest.Fort_visit = "neutral";	//reset soldiers

			LAi_SetStayType(Pchar);
			
			LAi_QuestDelay("key7_given0", 1.0);
		break;
		case "key7_given0":
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToLocator(characterFromID("Lieutenant G"), "reload", "reload7");

			LAi_QuestDelay("key7_given1", 1.0);
		break;

		case "key7_given1":
			PlaySound("INTERFACE\key_unlock.wav");

			LAi_QuestDelay("key7_given2", 1.0);
		break;

		case "key7_given2":
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorGoToLocator(characterFromID("Lieutenant G"), "goto", "goto3", "key7_given3", 1.0);
		break;

		case "key7_given3":
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorGoToLocator(characterFromID("Lieutenant G"), "reload", "reload7", "key7_given4", 1.0);
		break;

		case "key7_given4":
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Fort_Moultrie")].reload.l3.disable = 0;

			LAi_QuestDelay("book52_check", 0.1);
		break;
	//---------------------------------------------------------------------------------------------------------
		case "return_G_food":			
			if(CheckCharacterItem(Pchar,"bread") || CheckCharacterItem(Pchar,"meat") || CheckCharacterItem(Pchar,"bladebarrel")
			|| CheckCharacterItem(Pchar,"copper_cauldron") || CheckCharacterItem(Pchar,"pistolsalt"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				
				if(CheckCharacterItem(Pchar,"bread") || CheckCharacterItem(Pchar,"meat") || CheckCharacterItem(Pchar,"bladebarrel")
				|| CheckCharacterItem(Pchar,"pistolsalt")) {PlaySound("PEOPLE\clothes1.wav");}
								
				if(CheckCharacterItem(Pchar,"copper_cauldron")) {PlaySound("INTERFACE\wheel_place.wav");}
	
				TakenItems(Pchar, "bread", -2); TakenItems(Pchar, "meat", -2); TakenItems(Pchar, "bladebarrel", -1);
				TakenItems(Pchar, "copper_cauldron", -1); TakenItems(Pchar, "pistolsalt", -1);

				locations[FindLocation(Pchar.location)].box1.items.copper_cauldron = 0;
				locations[FindLocation(Pchar.location)].box1.items.bread = 0;
				locations[FindLocation(Pchar.location)].box1.items.meat = 0;
				locations[FindLocation(Pchar.location)].box1.items.bladebarrel = 0;
				locations[FindLocation(Pchar.location)].box1.items.pistolsalt = 0;

				locations[FindLocation(Pchar.location)].box1.items.copper_cauldron = 1;
				locations[FindLocation(Pchar.location)].box1.items.bread = 2;
				locations[FindLocation(Pchar.location)].box1.items.meat = 2;
				locations[FindLocation(Pchar.location)].box1.items.bladebarrel = 1;
				locations[FindLocation(Pchar.location)].box1.items.pistolsalt = 1;
			}
		break;

		case "return_G_plates":			
			if(CheckCharacterItem(Pchar,"barmansknife") || CheckCharacterItem(Pchar,"plate") 
			|| CheckCharacterItem(Pchar,"indian16") || CheckCharacterItem(Pchar,"tin_jug")
			|| CheckCharacterItem(Pchar,"indian8") || CheckCharacterItem(Pchar,"bladeoilbottle"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));			
				PlaySound("OBJECTS\DUEL\sword_fallen.wav");

				TakenItems(Pchar, "indian8", -4); TakenItems(Pchar, "plate", -6); TakenItems(Pchar, "indian16", -2);
				TakenItems(Pchar, "tin_jug", -1); TakenItems(Pchar, "bladeoilbottle", -2); TakenItems(Pchar, "barmansknife", -1);
	
				locations[FindLocation(Pchar.location)].box2.items.indian8 = 0;
				locations[FindLocation(Pchar.location)].box2.items.plate = 0;
				locations[FindLocation(Pchar.location)].box2.items.indian16 = 0;
				locations[FindLocation(Pchar.location)].box3.items.tin_jug = 0;
				locations[FindLocation(Pchar.location)].box3.items.bladeoilbottle = 0;
				locations[FindLocation(Pchar.location)].box3.items.barmansknife = 0;

				locations[FindLocation(Pchar.location)].box2.items.indian8 = 4;
				locations[FindLocation(Pchar.location)].box2.items.plate = 6;
				locations[FindLocation(Pchar.location)].box2.items.indian16 = 2;
				locations[FindLocation(Pchar.location)].box3.items.tin_jug = 1;
				locations[FindLocation(Pchar.location)].box3.items.bladeoilbottle = 2;
				locations[FindLocation(Pchar.location)].box3.items.barmansknife = 1;
			}
		break;

		case "return_G_books":
			if(CheckCharacterItem(Pchar,"book52"))
			{
			    if(CheckCharacterItem(Pchar,"book2") || CheckCharacterItem(Pchar,"book26") 
			    || CheckCharacterItem(Pchar,"book27") || CheckCharacterItem(Pchar,"book33")
			    || CheckCharacterItem(Pchar,"book11"))
			    {
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I only keep the Cipher Book."));
				PlaySound("INTERFACE\book_close.wav"); PlaySound("INTERFACE\book_close.wav");

				TakenItems(Pchar, "book2", -1); TakenItems(Pchar, "book26", -1); TakenItems(Pchar, "book27", -1);
				TakenItems(Pchar, "book33", -1); TakenItems(Pchar, "book11", -1);
					
				locations[FindLocation(Pchar.location)].box1.items.book2 = 0;
				locations[FindLocation(Pchar.location)].box1.items.book26 = 0;
				locations[FindLocation(Pchar.location)].box1.items.book27 = 0;
				locations[FindLocation(Pchar.location)].box1.items.book33 = 0;
				locations[FindLocation(Pchar.location)].box1.items.book11 = 0;
				
				locations[FindLocation(Pchar.location)].box1.items.book2 = 1;
				locations[FindLocation(Pchar.location)].box1.items.book26 = 1;
				locations[FindLocation(Pchar.location)].box1.items.book27 = 1;
				locations[FindLocation(Pchar.location)].box1.items.book33 = 1;
				locations[FindLocation(Pchar.location)].box1.items.book11 = 1;				
			    }
			}
			else
			{
				if(CheckCharacterItem(Pchar,"book2") || CheckCharacterItem(Pchar,"book26") 
			    	|| CheckCharacterItem(Pchar,"book27") || CheckCharacterItem(Pchar,"book33")
			    	|| CheckCharacterItem(Pchar,"book11"))
			    	{
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
					PlaySound("INTERFACE\book_close.wav"); PlaySound("INTERFACE\book_close.wav");

					TakenItems(Pchar, "book2", -1); TakenItems(Pchar, "book26", -1); TakenItems(Pchar, "book27", -1);
					TakenItems(Pchar, "book33", -1); TakenItems(Pchar, "book11", -1);
					
					locations[FindLocation(Pchar.location)].box1.items.book2 = 0;
					locations[FindLocation(Pchar.location)].box1.items.book26 = 0;
					locations[FindLocation(Pchar.location)].box1.items.book27 = 0;
					locations[FindLocation(Pchar.location)].box1.items.book33 = 0;
					locations[FindLocation(Pchar.location)].box1.items.book11 = 0;
				
					locations[FindLocation(Pchar.location)].box1.items.book2 = 1;
					locations[FindLocation(Pchar.location)].box1.items.book26 = 1;
					locations[FindLocation(Pchar.location)].box1.items.book27 = 1;
					locations[FindLocation(Pchar.location)].box1.items.book33 = 1;
					locations[FindLocation(Pchar.location)].box1.items.book11 = 1;					
			    	}
			}
		break;
	//---------------------------------------------------------------------------------------------------------
		case "book52_check":
			if(CheckCharacterItem(Pchar,"book52"))
			{
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
				
				LAi_QuestDelay("book52_picked_up", 1.0);
				return;
			}
			else
			{
				LAi_QuestDelay("book52_check", 0.5);//loop check
			}
		break;

		case "book52_picked_up":
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";
			Characters[GetCharacterIndex("Medicine Woman")].dialog.CurrentNode  = "medicine_bag";

			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
		break;

		case "medicine_bag_done":
			GiveItem2Character(Pchar, "med_bag1_doc_NO");

			pchar.quest.enable_medbag.win_condition.l1 = "location";
			pchar.quest.enable_medbag.win_condition.l1.location = "Legrands_house";
			pchar.quest.enable_medbag.win_condition = "enable_medbag";
		break;
		
		case "enable_medbag":
			TakeItemFromCharacter(Pchar, "med_bag1_doc_NO");
			GiveItem2Character(Pchar, "med_bag1_doc_YES");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Sullivan_jungle1", "officers", "box1_3");

			LAi_QuestDelay("check_medicine_bag_equipped", 0.5);

			Pchar.Lhouse_box1 = "temp_blocked";

			pchar.quest.lutG_checks_the.win_condition.l1 = "locator";
			pchar.quest.lutG_checks_the.win_condition.l1.location = "Sullivan_jungle1";
			pchar.quest.lutG_checks_the.win_condition.l1.locator_group = "box";
			pchar.quest.lutG_checks_the.win_condition.l1.locator = "box1";
			pchar.quest.lutG_checks_the.win_condition = "lutG_checks_the";
		break;

		case "med_woman_sees_all":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"I can't believe it! She's knows what I'm trying to do!"));
		break;

		case "check_medicine_bag_equipped":
			if(IsEquipCharacterByItem(Pchar, "med_bag1_out"))
			{
				Pchar.skill.Sneak = makeint(Pchar.skill.Sneak) + 2;

				LAi_QuestDelay("check_medicine_bag_released", 0.5);
				return;
			}
			else LAi_QuestDelay("check_medicine_bag_equipped", 0.5);
		break;

		case "check_medicine_bag_released":
			if(!IsEquipCharacterByItem(Pchar, "med_bag1_out"))
			{
				Pchar.skill.Sneak = makeint(Pchar.skill.Sneak) - 2;

				LAi_QuestDelay("check_medicine_bag_equipped", 0.5);
				return;
			}
			else LAi_QuestDelay("check_medicine_bag_released", 0.5);
		break;

		case "lutG_checks_the":
			LAi_SetActorType(Pchar);

			if(CheckAttribute(Pchar,"quest.message7") && Pchar.quest.message7 == "done")
			{
			    if(CheckAttribute(Pchar,"quest.book53") && Pchar.quest.book53 == "yes")
			    {
				if(CheckAttribute(Pchar,"quest.letter_T") && Pchar.quest.letter_T == "ok")
				{
					Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "letter_H";
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.letter_E") && Pchar.quest.letter_E == "ok")
					{
						Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "letter_T";
					}
				}
				else Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "letter_E";
			    }
			    else Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "book53";
			}
			else Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "med_bag";

			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToCharacter(characterFromID("Lieutenant G"), PChar);
			LAi_ActorDialogNow(characterFromID("Lieutenant G"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Lieutenant G"));
		break;

		case "no_idea_done":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");

			pchar.quest.try_crypto_again.win_condition.l1 = "location";
			pchar.quest.try_crypto_again.win_condition.l1.location = "Legrands_house";
			pchar.quest.try_crypto_again.win_condition = "try_crypto_again";
		break;

		case "try_crypto_again":
			LAi_SetPlayerType(Pchar);		

			Pchar.Lhouse_box1 = "temp_blocked";

			pchar.quest.lutG_checks_the.win_condition.l1 = "locator";
			pchar.quest.lutG_checks_the.win_condition.l1.location = "Sullivan_jungle1";
			pchar.quest.lutG_checks_the.win_condition.l1.locator_group = "box";
			pchar.quest.lutG_checks_the.win_condition.l1.locator = "box1";
			pchar.quest.lutG_checks_the.win_condition = "lutG_checks_the";
		break;

		case "THE_ok":
			TakeItemFromCharacter(Pchar, "book52");
			TakeItemFromCharacter(Pchar, "book53");
			TakeItemFromCharacter(Pchar, "book54");
			GiveItem2Character(characterFromID("Lieutenant G"), "book52");

			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "First time";
			LAi_SetCitizenType(characterFromID("Lieutenant G"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Sullivan_jungle1", "officers", "box1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			
			Pchar.quest.Jupiter_equip = "case1";
			LAi_QuestDelay("Jupiter_equip_check", 1.0);

			if (makeint(environment.time) > 15.0)
			{
				//too late
				Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Charleston_too_late";
				LAi_SetActorType(characterFromID("Jupiter"));
				LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
				LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
				LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
			}
			else
			{
				if (makeint(environment.time) < 6.0)
				{
					//too early
					Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Charleston_too_early";
					LAi_SetActorType(characterFromID("Jupiter"));
					LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
					LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
					LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
				}
			}
			else LAi_QuestDelay("to_Charleston", 0.1);
		break;

		case "to_Charleston":
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.Jupiter_equip = "case1";		

			Pchar.quest.remove_lieutenant.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.remove_lieutenant.win_condition.l1.location = "Sullivan_jungle1";
			Pchar.quest.remove_lieutenant.win_condition = "remove_lieutenant";
		break;

		case "remove_lieutenant":
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");
			Locations[FindLocation("Fort_Moultrie_shore")].models.always.locators = "Shore01_l_GB2";
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay1");		

			pchar.quest.Poe_house_where.win_condition.l1 = "location";
			pchar.quest.Poe_house_where.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Poe_house_where.win_condition = "Poe_house_where";
		break;
	//----------------------------------------------------------------------------------------------------------
		case "Charleston_too_early_done":
			DoQuestReloadToLocation("Legrands_house", "sit", "sit1", "Charleston_too_early_done1");
		break;

		case "Charleston_too_early_done1":
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");

			PlaySound("AMBIENT\JAIL\sigh2.wav");
			LAi_SetSitType(Pchar);

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "reload", "reload2");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "sit", "sit2");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Charleston_too_early_done2", 2.0);
		break;

		case "Charleston_too_early_done2":
			Locations[FindLocation("Legrands_house")].image = "";			//sign telling: ...
			DoQuestReloadToLocation("Legrands_house", "goto", "goto2", "Charleston_too_early_done3");
		break;

		case "Charleston_too_early_done3":
			Locations[FindLocation("Legrands_house")].image = "GB_Legrands_hut_inside.tga";
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.Jupiter_equip = "case1";
			
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "goto", "goto1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			SetCurrentTime(7.00, 0);

			LAi_QuestDelay("remove_lieutenant", 0.1);
		break;
	//----------------------------------------------------------------------------------------------------------
		case "Charleston_too_late_done":
			DoQuestReloadToLocation("Legrands_house", "goto", "staybed", "Charleston_too_late_done1");
		break;

		case "Charleston_too_late_done1":
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			LAi_QuestDelay("Charleston_too_late_done2", 1.0);
		break;

		case "Charleston_too_late_done2":
			PlaySound("PEOPLE\yawn.wav");
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "sit", "sitbed");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("Charleston_too_late_done3", 2.0);
		break;

		case "Charleston_too_late_done3":
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "goto", "bed");
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);
			PlaySound("PEOPLE\snoring.wav");

			LAi_QuestDelay("Charleston_too_late_done4", 2.0);
		break;

		case "Charleston_too_late_done4":
			Locations[FindLocation("Legrands_house")].image = "";			//sign telling: ...
			DoQuestReloadToLocation("Legrands_house", "sit", "sitbed", "Charleston_too_late_done5");
		break;

		case "Charleston_too_late_done5":
			Locations[FindLocation("Legrands_house")].image = "GB_Legrands_hut_inside.tga";
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			SetCurrentTime(7.00, 0);
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("Charleston_too_late_done6", 2.0);
		break;

		case "Charleston_too_late_done6":
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "goto", "staybed");
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.Jupiter_equip = "case1";

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "reload", "reload2");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			LAi_QuestDelay("remove_lieutenant", 0.1);
		break;

	//----------------------------------------------------------------------------------------------------------
	

	//....................................................................................
	//Charleston tour 2

		case "roofs_too_high":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box33");

			LAi_QuestDelay("roofs_too_high1", 1.0);
		break;

		case "roofs_too_high1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I can never climb up the way I came down."));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

			LAi_QuestDelay("roofs_too_high2", 3.0);
		break;
	
		case "roofs_too_high2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r12");

			LAi_QuestDelay("roofs_too_high3", 1.0);
		break;

		case "roofs_too_high3":
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "reload", "reload12");
			LAi_SetPlayerType(Pchar);
		break;
	/*
	//not used
		case "unlock_Pym_house":
			//from itemlogic
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_drawing_room")], true);

			LAi_QuestDelay("unlock_Pym_house1", 1.0);
		break;

		case "unlock_Pym_house1":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakenItems(Pchar, "bladelockpick", -1);
			EquipCharacterByItem(Pchar, "bladeX4");

			Locations[FindLocation("Pym_drawing_room")].locators_radius.box.box2 = 0.0001;
			Locations[FindLocation("Pym_drawing_room")].locators_radius.reload.reload1 = 1.0;
			
			DoQuestReloadToLocation("GB_Charleston_town", "goto", "box55", "");
		break;
	*/
	//....................................................................................
	//Charleston tour 3
/*
		case "step_back_church1":
			pchar.quest.step_back_church1_A.win_condition.l1 = "locator";
			pchar.quest.step_back_church1_A.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.step_back_church1_A.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_church1_A.win_condition.l1.locator = "plank1A";
			pchar.quest.step_back_church1_A.win_condition = "step_back_church1_A";
		break;

		case "step_back_church1_A":
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_church", "goto", "plank1B");
			
			LAi_QuestDelay("step_back_church1", 0.1);
		break;
*/
/*
		case "step_back_church2":
			pchar.quest.step_back_church2_A.win_condition.l1 = "locator";
			pchar.quest.step_back_church2_A.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.step_back_church2_A.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_church2_A.win_condition.l1.locator = "plank2A";
			pchar.quest.step_back_church2_A.win_condition = "step_back_church2_A";
		break;

		case "step_back_church2_A":
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_church", "goto", "plank2B");
			
			LAi_QuestDelay("step_back_church2", 0.1);
		break;

		case "step_back_church3":
			pchar.quest.step_back_church3_A.win_condition.l1 = "locator";
			pchar.quest.step_back_church3_A.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.step_back_church3_A.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_church3_A.win_condition.l1.locator = "plank3A";
			pchar.quest.step_back_church3_A.win_condition = "step_back_church3_A";
		break;

		case "step_back_church3_A":
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_church", "goto", "plank3B");
			
			LAi_QuestDelay("step_back_church3", 0.1);
		break;
*/
		case "magnet_key":
			Logit(TranslateString("","Yes, with the Magnet I got a Key out of the collection box."));
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			LAi_QuestDelay("stop_church_repairs", 2.0);
		break;

		case "stop_church_repairs":
			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "silent_residence";
			PostEvent("LoadSceneSound", 0);
	
			LAi_QuestDelay("stop_church_repairs1", 2.0);
		break;

		case "stop_church_repairs1":
			Logit(TranslateString("","Finally, they have stopped the repairs."));
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
		break;
	
//--------------------------------------------------------------------------------------------------------------------

		case "Poe_house_where":
			//story continues here from remove_lieutenant
			locations[FindLocation(Pchar.location)].box65.items.D_scalpel = 1;

			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload1_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Poe_house_where";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
		
		case "Poe_house_where_done":
	//LogIt("loginedcharacters = " + LAi_numloginedcharacters);
			
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("The_message","9");
			LAi_SetPlayerType(Pchar);
			pchar.quest.Landlady.win_condition.l1 = "location";
			pchar.quest.Landlady.win_condition.l1.location = "Poe_entre";
			pchar.quest.Landlady.win_condition = "Landlady";
		break;

		case "Landlady":
			Pchar.quest.Poe_home = "yes";

			Characters[GetCharacterIndex("Landlady")].dialog.CurrentNode  = "First time";
			LAi_SetActorType(characterFromID("Landlady"));
			LAi_ActorTurnToCharacter(characterFromID("Landlady"), PChar);
			LAi_ActorDialogNow(characterFromID("Landlady"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Landlady"));

			pchar.quest.Poe_bedroom.win_condition.l1 = "locator";
			pchar.quest.Poe_bedroom.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Poe_bedroom.win_condition.l1.locator_group = "goto";
			pchar.quest.Poe_bedroom.win_condition.l1.locator = "start";
			pchar.quest.Poe_bedroom.win_condition = "Poe_bedroom";
		break;

		case "Poe_bedroom":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_bedroom";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Legrand_to_armchair":
			pchar.quest.Legrand_to_armchair1.win_condition.l1 = "locator";
			pchar.quest.Legrand_to_armchair1.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Legrand_to_armchair1.win_condition.l1.locator_group = "goto";
			pchar.quest.Legrand_to_armchair1.win_condition.l1.locator = "stay2";
			pchar.quest.Legrand_to_armchair1.win_condition = "Legrand_to_armchair1";
		break;

		case "Legrand_to_armchair1":
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "goto", "stay2");

			LAi_QuestDelay("Legrand_to_armchair2", 1.0);
		break;

		case "Legrand_to_armchair2":
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "sit", "sit2");
			LAi_SetSitType(Pchar);
			PlaySound("AMBIENT\CHURCH\bench1.wav");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "sit", "sit3");
			LAi_SetSitType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("Poe_bedroom1", 1.0);
		break;

		case "Poe_bedroom1":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_bedroom1";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Legrand_tells_story":
			Locations[FindLocation("Poe_bedroom")].image = "";
			DoQuestReloadToLocation("Poe_bedroom", "sit", "sit2", "Poe_bedroom2");
		break;

		case "Poe_bedroom2":
			Locations[FindLocation("Poe_bedroom")].image = "GB_Poe_bedroom.tga";

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "sit", "sit3");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			LAi_SetSitType(characterFromID("Jupiter"));
			Pchar.quest.Jupiter_sits = "yes";
			
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_bedroom2";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_takes_document":
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("Poe_takes_document1", 2.0);
		break;

		case "Poe_takes_document1":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");

			LAi_QuestDelay("Poe_takes_document2", 1.5);
		break;

		case "Poe_takes_document2":
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto1", -1);
			TakenItems(characterFromID("Edgar Allan Poe"), "crypto1", 1);
		
			LAi_QuestDelay("Poe_takes_document3", 1.0);
		break;

		case "Poe_takes_document3":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "goto", "stay1", "Poe_takes_document4", 2.0);
		break;

		case "Poe_takes_document4":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), characterFromID("Jupiter"));

			LAi_QuestDelay("Poe_takes_document5", 1.0);
		break;

		case "Poe_takes_document5":
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "sit", "sit1");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			PlaySound("AMBIENT\JAIL\sigh2.wav");

			LAi_QuestDelay("Poe_bedroom3", 5.0);
		break;

		case "Poe_bedroom3":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay1");

			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_bedroom3";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;
	
		case "Through_word":
			AddQuestRecord("The_message","11");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "sit", "sit1");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			PlaySound("AMBIENT\JAIL\sigh2.wav");

			LAi_QuestDelay("Through_word1", 1.0);
		break;

		case "Through_word1":
			PlaySound("AMBIENT\CHURCH\bench2.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "goto", "stay2");

			LAi_QuestDelay("Poe_checks_oug", 0.1);
		break;

		case "Poe_checks_oug":
			if(CheckAttribute(Pchar,"quest.letter_U") && Pchar.quest.letter_U == "ok")
			{
				Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_letter_G";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.letter_O") && Pchar.quest.letter_O == "ok")
				{
					Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_letter_U";
				}
			}
			else Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_letter_O";
		break;

		case "Jupiter_degree":
			Pchar.quest.Jupiter_sits = "no";

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jupiter_degree";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Poe_leaves_bedroom":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_leaves_bedroom";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));

		break;

		case "Dupin_house":
			AddQuestRecord("The_message","12");
			LAi_SetStayType(Pchar);
			
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
		//	ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay1");
			
			LAi_QuestDelay("Dupin_house1", 1.0);
		break;
	
		case "Dupin_house1":
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto1", 1);
			TakenItems(characterFromID("Edgar Allan Poe"), "crypto1", -1);

			LAi_QuestDelay("Dupin_house2", 1.0);
		break;

		case "Dupin_house2":
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "reload", "reload1", "Dupin_house3", 4.0);
		break;
//JRH dupin start
		case "Dupin_house3":
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			Pchar.quest.Poe_home = "no";
			Locations[FindLocation("GB_Charleston_town")].reload.l3.disable = 0;
			PlaySound("INTERFACE\closed_door.wav");


			pchar.quest.dupin_office_boxes.win_condition.l1 = "locator";
			pchar.quest.dupin_office_boxes.win_condition.l1.location = "Dupin_office";
			pchar.quest.dupin_office_boxes.win_condition.l1.locator_group = "goto";
			pchar.quest.dupin_office_boxes.win_condition.l1.locator = "start_L";
			pchar.quest.dupin_office_boxes.win_condition = "dupin_office_boxes";
		/*
			pchar.quest.dupin_office_boxes.win_condition.l1 = "location";
			pchar.quest.dupin_office_boxes.win_condition.l1.location = "Dupin_office";
			pchar.quest.dupin_office_boxes.win_condition = "dupin_office_boxes";
		*/
			pchar.quest.Charleston_opium_boxes.win_condition.l2 = "location";
			pchar.quest.Charleston_opium_boxes.win_condition.l2.location = "GB_Charleston_opium";
			pchar.quest.Charleston_opium_boxes.win_condition = "Charleston_opium_boxes";
		break;

		case "dupin_office_boxes":
			locations[FindLocation(Pchar.location)].box7.items.book21 = 1;
			locations[FindLocation(Pchar.location)].box7.items.chain = 1;
			locations[FindLocation(Pchar.location)].box9.items.D_feather = 1;
			locations[FindLocation(Pchar.location)].box2.items.D_scissors = 1;

			Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "welcome";
			LAi_SetActorType(characterFromID("Auguste Dupin"));
			LAi_ActorTurnToCharacter(characterFromID("Auguste Dupin"), PChar);
			LAi_ActorDialogNow(characterFromID("Auguste Dupin"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Auguste Dupin"));
		break;

		case "dupin_gives_kit":
			//from Dupin dialog
			LAi_SetOfficerType(characterFromID("Auguste Dupin"));

			LAi_QuestDelay("dupin_gives_kit1", 3.0);
		break;

		case "dupin_gives_kit1":
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto1", -1);
			TakenItems(characterFromID("Auguste Dupin"), "crypto1", 1);		
			TakenItems(Pchar, "detective_kit1", 1);
			TakenItems(characterFromID("Auguste Dupin"), "detective_kit1", -1);
			Logit(TranslateString("","You take item"));
			PlayStereoSound("interface\important_item.wav");

			LAi_QuestDelay("dupin_gives_kit2", 2.0);
		break;

		case "dupin_gives_kit2":
			Pchar.quest.detective_kit = "keys";
			
			LAi_SetActorType(characterFromID("Auguste Dupin"));
			LAi_ActorGoToLocator(characterFromID("Auguste Dupin"), "goto", "goto2", "dupin_gives_kit3", 5.0);//was 4

			pchar.quest.dupin_private_boxes.win_condition.l1 = "location";
			pchar.quest.dupin_private_boxes.win_condition.l1.location = "Dupin_private";
			pchar.quest.dupin_private_boxes.win_condition = "dupin_private_boxes";
		break;

		case "dupin_gives_kit3":
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Auguste Dupin"), "Dupin_office", "sit", "sit1");
			LAi_SetSitType(characterFromID("Auguste Dupin"));
			Pchar.quest.Dupin_pos = "sit";
			AddQuestRecord("Useful_items", "8");
		break;

		case "dupin_private_boxes":
			locations[FindLocation(Pchar.location)].box7.items.revolver = 1;
			locations[FindLocation(Pchar.location)].box1.items.D_compasses = 1;
			locations[FindLocation(Pchar.location)].box7.items.D_hairpin = 1;

			LAi_QuestDelay("hairpin_check", 0.5);
		break;

		case "Charleston_opium_boxes":
			locations[FindLocation(Pchar.location)].box5.items.medicine_leaves = 1;
			locations[FindLocation(Pchar.location)].box2.items.D_magnifying = 1;
			locations[FindLocation(Pchar.location)].box4.items.D_tweezers = 1;
		break;

		case "return_to_Dupin":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box58");

			LAi_QuestDelay("return_to_Dupin1", 1.0);
		break;

		case "return_to_Dupin1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I'm not going back. The metal door locked behind me."));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

			LAi_QuestDelay("return_to_Dupin2", 3.0);
		break;

		case "return_to_Dupin2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r17");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "hairpin_check":
			if(CheckCharacterItem(Pchar,"D_hairpin"))
			{
				PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"A hairpin - what use can I have of this little thing?"));
				AddQuestRecord("Useful_items", "9");				

				return;
			}
			else
			{
				LAi_QuestDelay("hairpin_check", 0.5);//loop check
			}
		break;

		case "Dupin_private_hatch_unlock":
			Locations[FindLocation("Dupin_private")].locators_radius.box.box5 = 0.001;			
			Locations[FindLocation("Dupin_private")].locators_radius.reload.reload2 = 0.7;
			Locations[FindLocation("GB_Charleston_opium")].locators_radius.box.box7 = 0.001;			
			Locations[FindLocation("GB_Charleston_opium")].locators_radius.reload.reload2 = 0.6;

			Locations[FindLocation("Dupin_private")].image = "";
			DoQuestReloadToLocation("Dupin_private", "goto", "lever", "Dupin_private_hatch_unlock1");
		break;

		case "Dupin_private_hatch_unlock1":
			Locations[FindLocation("Dupin_private")].image = "Inside_mh10.tga";
			PlaySound("INTERFACE\closet_open.wav");
			Locations[FindLocation("Dupin_private")].reload.l2.disable = 0;
			Locations[FindLocation("GB_Charleston_opium")].reload.l2.disable = 0;
		break;

		case "Dupin_private_hatch_lock":
			Locations[FindLocation("Dupin_private")].image = "";
			DoQuestReloadToLocation("Dupin_private", "goto", "lever", "Dupin_private_hatch_lock1");
		break;

		case "Dupin_private_hatch_lock1":
			Locations[FindLocation("Dupin_private")].image = "Inside_mh10.tga";
			PlaySound("INTERFACE\closed_locked_door.wav");
			Locations[FindLocation("Dupin_private")].reload.l2.disable = 1;
			Locations[FindLocation("GB_Charleston_opium")].reload.l2.disable = 1;
		break;
	//---------------------------------------------------------------------------------------------------
		case "return_Poe_items":
			if(CheckCharacterItem(Pchar,"Poes_clothes") || CheckCharacterItem(Pchar,"2winebottles") 
			|| CheckCharacterItem(Pchar,"Poes_urn"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));

				if(CheckCharacterItem(Pchar,"Poes_urn"))
				{ PlaySound("OBJECTS\DUEL\spyglass.wav"); }
				
				if(CheckCharacterItem(Pchar,"Poes_clothes")) 
				{ PlaySound("PEOPLE\clothes1.wav"); }

				if(CheckCharacterItem(Pchar,"2winebottles"))
				{ PlaySound("INTERFACE\glass1.wav"); }

				TakenItems(Pchar, "Poes_clothes", -1); TakenItems(Pchar, "2winebottles", -1);
				TakenItems(Pchar, "Poes_urn", -1);
				
				locations[FindLocation(Pchar.location)].box1.items.Poes_clothes = 0;
				locations[FindLocation(Pchar.location)].box1.items.2winebottles = 0;
				locations[FindLocation(Pchar.location)].box1.items.Poes_urn = 0;

				locations[FindLocation(Pchar.location)].box1.items.Poes_clothes = 1;
				locations[FindLocation(Pchar.location)].box1.items.2winebottles = 1;
				locations[FindLocation(Pchar.location)].box1.items.Poes_urn = 1;
			}
		break;		

		case "return_Poe_books":
			if(CheckCharacterItem(Pchar,"Poes_books"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				PlaySound("INTERFACE\book_close.wav"); PlaySound("INTERFACE\book_close.wav");
		
				TakenItems(Pchar, "Poes_books", -1);
				locations[FindLocation(Pchar.location)].box2.items.Poes_books = 0;
				locations[FindLocation(Pchar.location)].box2.items.Poes_books = 1;
			}
		break;

		case "return_Dupin_items":
			if(CheckCharacterItem(Pchar,"book21") || CheckCharacterItem(Pchar,"chain"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));

				if(CheckCharacterItem(Pchar,"book21"))
				{ PlaySound("INTERFACE\book_close.wav"); PlaySound("INTERFACE\book_close.wav"); }
				
				if(CheckCharacterItem(Pchar,"chain")) 
				{ PlaySound("AMBIENT\JAIL\chains2.wav"); }				

				TakenItems(Pchar, "book21", -1); TakenItems(Pchar, "chain", -1);
				
				locations[FindLocation(Pchar.location)].box7.items.book21 = 0;
				locations[FindLocation(Pchar.location)].box7.items.chain = 0;

				locations[FindLocation(Pchar.location)].box7.items.book21 = 1;
				locations[FindLocation(Pchar.location)].box7.items.chain = 1;
			}
		break;

		case "return_Dupin_revolver":
			if(CheckCharacterItem(Pchar,"D_hairpin"))
			{
				if(CheckCharacterItem(Pchar,"revolver"))
				{
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I only keep the Hairpin."));
					PlaySound("OBJECTS\DUEL\sword_fallen.wav");				
					TakenItems(Pchar, "revolver", -1);
				
					locations[FindLocation(Pchar.location)].box7.items.revolver = 0;
					locations[FindLocation(Pchar.location)].box7.items.revolver = 1;
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"revolver"))
				{
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
					PlaySound("OBJECTS\DUEL\sword_fallen.wav");				
					TakenItems(Pchar, "revolver", -1);
				
					locations[FindLocation(Pchar.location)].box7.items.revolver = 0;
					locations[FindLocation(Pchar.location)].box7.items.revolver = 1;
				}	
			}
		break;

		case "return_medicine_leaves":
			if(CheckCharacterItem(Pchar,"medicine_leaves"))
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				PlaySound("PEOPLE\step_grass.wav");
		
				TakenItems(Pchar, "medicine_leaves", -1);
				locations[FindLocation(Pchar.location)].box5.items.medicine_leaves = 0;
				locations[FindLocation(Pchar.location)].box5.items.medicine_leaves = 1;
			}
		break;
	//---------------------------------------------------------------------------------------------------
		case "D_feather_check":
			if(CheckAttribute(Pchar,"quest.D_feather") && Pchar.quest.D_feather == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_feather"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_feather = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "D_scissors_check":
			if(CheckAttribute(Pchar,"quest.D_scissors") && Pchar.quest.D_scissors == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_scissors"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_scissors = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "D_compasses_check":
			if(CheckAttribute(Pchar,"quest.D_compasses") && Pchar.quest.D_compasses == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_compasses"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_compasses = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "D_scalpel_check":
			if(CheckAttribute(Pchar,"quest.D_scalpel") && Pchar.quest.D_scalpel == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_scalpel"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_scalpel = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "D_magnifying_check":
			if(CheckAttribute(Pchar,"quest.D_magnifying") && Pchar.quest.D_magnifying == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_magnifying"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_magnifying = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "D_tweezers_check":
			if(CheckAttribute(Pchar,"quest.D_tweezers") && Pchar.quest.D_tweezers == "picked_up")
			{
				return;
			}
			else
			{
				if(CheckCharacterItem(Pchar,"D_tweezers"))
				{
					Logit(TranslateString("","You take item"));
					PlayStereoSound("interface\important_item.wav");
					Pchar.quest.Dupin_toolbox = sti(Pchar.quest.Dupin_toolbox) + 1;
					Pchar.quest.D_tweezers = "picked_up";
				
					LAi_QuestDelay("counting_Dupin_items", 0.1);
					return;
				}
			}
		break;

		case "counting_Dupin_items":
			if(CheckAttribute(Pchar, "quest.Dupin_toolbox"))
			{
				switch(Pchar.quest.Dupin_toolbox)
				{
					case "1": PlaySound("VOICE\ENGLISH\blaze_1.wav"); break;
					case "2": PlaySound("VOICE\ENGLISH\blaze_2.wav"); break;
					case "3": PlaySound("VOICE\ENGLISH\blaze_3.wav"); break;
					case "4": PlaySound("VOICE\ENGLISH\blaze_4.wav"); break;
					case "5": PlaySound("VOICE\ENGLISH\blaze_5.wav"); break;	
					case "6": PlaySound("VOICE\ENGLISH\blaze_6.wav");
								  
						  LAi_QuestDelay("Dupin_6_items_found", 1.0);
					break;
				}
			}
		break;

		case "Dupin_6_items_found":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Dupin_6_items_found";
			LAi_ActorSelfDialog(pchar, "");

			ChangeCharacterAddressGroup(characterFromID("Auguste Dupin"), "Dupin_office", "goto", "goto2");
			LAi_SetStayType(characterFromID("Auguste Dupin"));
			Pchar.quest.Dupin_pos = "stay";
			AddQuestRecord("Useful_items", "10");
			CloseQuestHeader("Useful_items");
			Locations[FindLocation("Dupin_office")].reload.l1.disable = 1;	//to balcony
		break;

		case "kit_to_Dupin":
			//from selfdialog

			LAi_QuestDelay("pchar_playertype", 0.1);
		break;
//------------------------------------------------------------------------------------------------------------
		case "Dkit1_prepared":
			//1

			if(pchar.location == "Dupin_office")
			{
				LAi_SetActorType(Pchar);
				LAi_ActorGoToLocator(Pchar, "goto", "stay2", "Dkit1_check", 5.0);
			}
			else
			{
				pchar.quest.Dkit1_check.win_condition.l1 = "locator";
				pchar.quest.Dkit1_check.win_condition.l1.location = "Dupin_office";
				pchar.quest.Dkit1_check.win_condition.l1.locator_group = "goto";
				pchar.quest.Dkit1_check.win_condition.l1.locator = "sit2";
				pchar.quest.Dkit1_check.win_condition = "Dkit1_check";
			}
		break;

		case "Dkit1_check":
			//2

			if(CheckCharacterItem(Pchar,"Detective_kit1"))
			{
				LAi_QuestDelay("Dkit1_filled", 0.1);
			}
			else
			{
				Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "Dkit1_not_finished_yet";
				LAi_SetActorType(characterFromID("Auguste Dupin"));
				LAi_ActorTurnToCharacter(characterFromID("Auguste Dupin"), PChar);
				LAi_ActorDialogNow(characterFromID("Auguste Dupin"), pchar, "", 0.1);
				LAi_ActorWaitDialog(Pchar, characterFromID("Auguste Dupin"));
			}
		break;

		case "Dkit1_not_finished_yet":
			//4
			//LAi_SetPlayerType(Pchar);
			LAi_SetStayType(Pchar);

			if(CheckCharacterItem(Pchar,"Detective_kit1"))
			{
				LAi_QuestDelay("Dkit1_filled", 0.1);
				return;
			}
			else LAi_QuestDelay("Dkit1_not_finished_yet", 0.5);
		break;

		case "Dkit1_filled":
			//3

			Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "Dkit1_filled";
			LAi_SetActorType(characterFromID("Auguste Dupin"));
			LAi_ActorTurnToCharacter(characterFromID("Auguste Dupin"), PChar);
			LAi_ActorDialogNow(characterFromID("Auguste Dupin"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Auguste Dupin"));
		break;
//------------------------------------------------------------------------------------------------------------
		case "Dupin_takes_kit":
			PlaySound("INTERFACE\collection_box.wav"); PlaySound("INTERFACE\collection_box.wav");
			PlaySound("AMBIENT\JAIL\chains2.wav");
			RemoveCharacterEquip(Pchar, OUTFIT_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "Detective_kit1");
			TakeItemFromCharacter(Pchar, "D_key23");
			TakeItemFromCharacter(Pchar, "D_hairpin");
			DeleteQuestHeader("Useful_items");
			
			LAi_QuestDelay("letter_A", 2.0);
		break;

		case "letter_A":
			Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "letter_A";
			LAi_SetActorType(characterFromID("Auguste Dupin"));
			LAi_ActorTurnToCharacter(characterFromID("Auguste Dupin"), PChar);
			LAi_ActorDialogNow(characterFromID("Auguste Dupin"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Auguste Dupin"));
		break;

		case "Dupin_checks_l_&_m_&_f":
			LAi_SetPlayerType(Pchar);
			LAi_SetStayType(characterFromID("Auguste Dupin"));

			if(CheckAttribute(Pchar,"quest.letter_F") && Pchar.quest.letter_F == "ok")
			{
				Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "Dupin_letter_Y";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.letter_L") && Pchar.quest.letter_L == "ok")
				{
					Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "Dupin_letter_M";
				}
				else Characters[GetCharacterIndex("Auguste Dupin")].dialog.CurrentNode  = "Dupin_letter_L";
			}
		break;

		case "Dupins_work_over":
			PlaySound("VOICE\ENGLISH\Dupin_know.wav");
			LAi_SetPlayerType(pchar);
			AddQuestRecord("The_message","17");
			
			ChangeCharacterAddressGroup(characterFromID("Auguste Dupin"), "Dupin_office", "sit", "sit1");

			LAi_QuestDelay("Dupins_work_over1", 2.5);
		break;

		case "Dupins_work_over1":
			LAi_SetPlayerType(pchar);
			AddQuestRecord("The_message","17");
			
			LAi_SetSitType(characterFromID("Auguste Dupin"));
			Pchar.quest.Dupin_pos = "sit";
			PlaySound("PEOPLE\creak2.wav");
			locations[FindLocation("GB_Charleston_town")].type = "silent_town";

			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Axel von Fersen"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("client1"), "GB_Charleston_town", "sit", "client1");
			ChangeCharacterAddressGroup(characterFromID("client2"), "GB_Charleston_town", "sit", "client2");
			ChangeCharacterAddressGroup(characterFromID("client3"), "GB_Charleston_town", "sit", "client3");
			ChangeCharacterAddressGroup(characterFromID("client4"), "GB_Charleston_town", "sit", "fersen");
			Locations[FindLocation("GB_Charleston_town")].reload.l3.disable = 1;

			pchar.quest.lock_Dupin_stairs.win_condition.l1 = "location";
			pchar.quest.lock_Dupin_stairs.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.lock_Dupin_stairs.win_condition = "lock_Dupin_stairs";
		break;

		case "lock_Dupin_stairs":
			PlaySound("INTERFACE\key_lock.wav");

			pchar.quest.Fersen_checks_letters.win_condition.l1 = "locator";
			pchar.quest.Fersen_checks_letters.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Fersen_checks_letters.win_condition.l1.locator_group = "sit";
			pchar.quest.Fersen_checks_letters.win_condition.l1.locator = "fersen";
			pchar.quest.Fersen_checks_letters.win_condition = "Fersen_checks_letters";
		break;

		case "Fersen_checks_letters":
			Characters[GetCharacterIndex("client4")].dialog.CurrentNode  = "start";
			LAi_SetActorType(characterFromID("client4"));
			LAi_ActorTurnToCharacter(characterFromID("client4"), PChar);
			LAi_ActorDialogNow(characterFromID("client4"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("client4"));
		break;

		case "Dupin_pardon":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
		break;

		case "Dupin_good_day":
			PlaySound("VOICE\ENGLISH\Dupin_good_day.wav");
		break;

		case "Fersen_checks_v_&_b_&_p_&_c":
			LAi_SetPlayerType(Pchar);

			if(CheckAttribute(Pchar,"quest.letter_C") && Pchar.quest.letter_C == "ok")
			{
				
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.letter_P") && Pchar.quest.letter_P == "ok")
				{
					Characters[GetCharacterIndex("client4")].dialog.CurrentNode  = "Fersen_letter_C";
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.letter_B") && Pchar.quest.letter_B == "ok")
					{
						Characters[GetCharacterIndex("client4")].dialog.CurrentNode  = "Fersen_letter_P";
					}
					else
					{
						if(CheckAttribute(Pchar,"quest.letter_V") && Pchar.quest.letter_V == "ok")
						{
							Characters[GetCharacterIndex("client4")].dialog.CurrentNode  = "Fersen_letter_B";
						}
						else Characters[GetCharacterIndex("client4")].dialog.CurrentNode  = "Fersen_letter_V";
					}
				}
			}
		break;

		case "Fersens_work_over":
			ChangeCharacterAddressGroup(characterFromID("client4"), "GB_Charleston_town", "sit", "fersen");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay3");
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));

			Pchar.quest.Poe_home = "yes";

			LAi_QuestDelay("restart_Charleston_music", 9.0);

			pchar.quest.Poe_second_time.win_condition.l1 = "locator";
			pchar.quest.Poe_second_time.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Poe_second_time.win_condition.l1.locator_group = "goto";
			pchar.quest.Poe_second_time.win_condition.l1.locator = "start";
			pchar.quest.Poe_second_time.win_condition = "Poe_second_time";
		break;

		case "restart_Charleston_music":
			PostEvent("LoadSceneSound", 5);//restarts location sounds
			locations[FindLocation("GB_Charleston_town")].type = "Charleston_town";
		break;

		case "Poe_second_time":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "visitor_again";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "visitor_again_done":
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "sit", "sit3");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			PlaySound("PEOPLE\creak2.wav");

			pchar.quest.Poe_second_time_sit.win_condition.l1 = "locator";
			pchar.quest.Poe_second_time_sit.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Poe_second_time_sit.win_condition.l1.locator_group = "goto";
			pchar.quest.Poe_second_time_sit.win_condition.l1.locator = "stay1";
			pchar.quest.Poe_second_time_sit.win_condition = "Poe_second_time_sit";
		break;

		case "Poe_second_time_sit":
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "goto", "stay1");

			LAi_QuestDelay("Poe_second_time_sit2", 1.0);
		break;

		case "Poe_second_time_sit2":
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "sit", "sit1");
			LAi_SetSitType(Pchar);
			PlaySound("AMBIENT\CHURCH\bench1.wav");

			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "stay2", "Jup_goes_to_stay2", 3.0);
			
			LAi_QuestDelay("sentences", 1.0);
		break;

		case "Jup_goes_to_stay2":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "sit", "sit2");
			LAi_SetSitType(characterFromID("Jupiter"));
			Pchar.quest.Jupiter_sits = "yes";
		break;

		case "sentences":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "sentences";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_last_paper":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "goto", "stay1");

			pchar.quest.Poe_last_paper1.win_condition.l1 = "locator";
			pchar.quest.Poe_last_paper1.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Poe_last_paper1.win_condition.l1.locator_group = "goto";
			pchar.quest.Poe_last_paper1.win_condition.l1.locator = "stay4";
			pchar.quest.Poe_last_paper1.win_condition = "Poe_last_paper1";
		break;

		case "Poe_last_paper1":
			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto1", -1);
			TakenItems(characterFromID("Edgar Allan Poe"), "crypto1", 1);

			LAi_QuestDelay("Poe_last_paper2", 1.5);
		break;

		case "Poe_last_paper2":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			
			LAi_QuestDelay("Poe_last_paper3", 1.0);
		break;

		case "Poe_last_paper3":
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			
			LAi_QuestDelay("Poe_last_paper4", 5.0);
		break;

		case "Poe_last_paper4":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "sentences4";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_last_paper5":
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto2", 1);
			LAi_SetPlayerType(Pchar);
			
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "goto", "stay2");
			LAi_SetStayType(characterFromID("Jupiter"));
			Pchar.quest.Jupiter_sits = "no";
			
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;	//open to plantation
			Pchar.quest.town_exit_closed = "no";
			
			LAi_QuestDelay("Poe_last_paper6", 2.0);
		break;

		case "Poe_last_paper6":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Poe_sentences";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Poe_visit2_done":
			//from self-dialog
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));	
			DeleteQuestHeader("The_message");		

			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen1"), "GB_Charleston_town", "goto", "citizen1");
			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen2"), "GB_Charleston_town", "goto", "citizen2");
			ChangeCharacterAddressGroup(characterFromID("Charleston_citizen3"), "GB_Charleston_town", "goto", "citizen3");
			ChangeCharacterAddressGroup(characterFromID("Axel von Fersen"), "GB_Charleston_town", "goto", "citizen4");

			ChangeCharacterAddressGroup(characterFromID("client1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("client2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("client3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("client4"), "none", "", "");

			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");
			Pchar.quest.JRH_rain = "Clear";

			LAi_QuestDelay("launch_items_inventory_Poe", 1.0);
		break;

		case "launch_items_inventory_Poe":
			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
		break;

		case "bye_bye_Poe":
			Pchar.quest.bye_bye_Poe = "done";

			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "bye_bye_Poe";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "bye_bye_Poe_done":
			pchar.quest.Bessop_plantation_info.win_condition.l1 = "locator";
			pchar.quest.Bessop_plantation_info.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.Bessop_plantation_info.win_condition.l1.locator_group = "box";
			pchar.quest.Bessop_plantation_info.win_condition.l1.locator = "box1";
			pchar.quest.Bessop_plantation_info.win_condition = "Bessop_plantation_info";
		break;
		
		case "Bessop_plantation_info":
			LAi_QuestDelay("Bessop_plantation_info1", 2.0);
		break;

		case "Bessop_plantation_info1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Bessop_plantation_info";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Bessop_plantation_info_done":
			AddQuestRecord("The_plantation","1");

			pchar.quest.Bessop_gate_guards.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_guards.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_guards.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_guards.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_guards.win_condition = "Bessop_gate_guards";
		break;

		case "Bessop_gate_guards":
			Characters[GetCharacterIndex("Bessop_guard1")].dialog.CurrentNode  = "no_entrance1";
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard1"), PChar);
			LAi_ActorDialogNow(characterFromID("Bessop_guard1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Bessop_guard1"));
		break;

		case "no_entrance1_done":
			Characters[GetCharacterIndex("Bessop_guard2")].dialog.CurrentNode  = "no_entrance2";
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard2"), PChar);
			LAi_ActorDialogNow(characterFromID("Bessop_guard2"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Bessop_guard2"));
		break;

		case "no_entrance2_done":
			Characters[GetCharacterIndex("Bessop_guard1")].dialog.CurrentNode  = "no_entrance3";
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard1"), PChar);
			LAi_ActorDialogNow(characterFromID("Bessop_guard1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Bessop_guard1"));
		break;

		case "no_entrance3_done":
			Characters[GetCharacterIndex("Bessop_guard2")].dialog.CurrentNode  = "no_entrance4";
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard2"), PChar);
			LAi_ActorDialogNow(characterFromID("Bessop_guard2"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Bessop_guard2"));
		break;

		case "no_entrance4_done":
			AddQuestRecord("The_plantation","2");
			Characters[GetCharacterIndex("Bessop_guard1")].dialog.CurrentNode  = "First time";
			Characters[GetCharacterIndex("Bessop_guard2")].dialog.CurrentNode  = "First time";
			LAi_SetStayType(characterFromID("Bessop_guard1"));
			LAi_SetStayType(characterFromID("Bessop_guard2"));

			LAi_QuestDelay("return_to_Charleston_Jupiter", 0.5);
		break;

		case "return_to_Charleston_Jupiter":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");

			pchar.quest.return_to_Charleston_Jupiter1.win_condition.l1 = "location";
			pchar.quest.return_to_Charleston_Jupiter1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.return_to_Charleston_Jupiter1.win_condition = "return_to_Charleston_Jupiter1";
		break;

		case "return_to_Charleston_Jupiter1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "how_to_enter_plantation";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "how_to_enter_plantation_done":
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("Fireworks","1");
			Pchar.quest.Chinatown_malaria = "no";
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;	//open to Chinatown
			LAi_SetCitizenType(characterFromID("Charleston_doctor"));

	//start values Chinatown here
			Pchar.quest.China_well = "phase1";
			Pchar.quest.nitre_boiling_low = "First_time";	//exit1
			Pchar.quest.nitre_dirt_tub2 = "First_time";	//exit2
			Pchar.quest.nitre_white_planks = "First_time";	//exit3
			Pchar.quest.nitre_drops = "first_time";
			Pchar.quest.nitre_wood = "none";
			Pchar.quest.nitre_boiling = "none";
			Pchar.quest.nitre_lever0 = "up";		//closed
			Pchar.quest.nitre_lever1 = "down";		//open
			Pchar.quest.nitre_lever2 = "down";		//open
			Pchar.quest.sulfur_lever = "up";		//hatch closed
			Pchar.quest.sulfur_distillery = "enabled";	//when hatch is closed
			Pchar.quest.pyrite_stones = "no";
			Pchar.quest.tub1_level = "half";		//half or full
			Pchar.quest.tub2_level = "half";
			Pchar.quest.tub2_content = "water";		//water, nitre or dirt (little nitre)
			Pchar.quest.tub3_content = "water";
			//Pchar.quest.large_bottle = "none";		//start
			//Pchar.quest.medium_bottle = "none";		//start
			Pchar.quest.large_bottle = "LE0";
			Pchar.quest.medium_bottle = "ME0";
		//Pchar.quest.large_bottle = "LN1";
		//Pchar.quest.medium_bottle = "MC2";

			Pchar.quest.2barrels_gpS = "first_time";
			Pchar.quest.2barrels_gpF = "first_time";
			Pchar.quest.floor_barrel = "blade_type";
		//Pchar.quest.water_added = "yes";		//try without
			Pchar.quest.gp_container = 0;
			
		//	Pchar.quest.store_charcoal = 0;
		//	Pchar.quest.store_sulfur = 1;
		//	Pchar.quest.store_nitre = 5;
		//	Pchar.quest.store_total = 6;

		Pchar.quest.store_charcoal = 1;
		Pchar.quest.store_sulfur = 1;
		Pchar.quest.store_nitre = 6;
		Pchar.quest.store_total = 8;

			Pchar.quest.mix_charcoal = 0;
			Pchar.quest.mix_sulfur = 0;
			Pchar.quest.mix_nitre = 0;
			Pchar.quest.mix_total = 0;
		//	Pchar.quest.BB_total = 6;
		Pchar.quest.BB_total = 8;

			Pchar.quest.gp_charcoal = 0;
			Pchar.quest.gp_sulfur = 0;
			Pchar.quest.gp_nitre = 0;
			Pchar.quest.gp_total = 0;

			Pchar.quest.lost_charcoal = 0;
			Pchar.quest.lost_sulfur = 0;
			Pchar.quest.lost_nitre = 0;
			
			Pchar.quest.charcoal_risk = 0;
			Pchar.quest.sulfur_risk = 0;
			Pchar.quest.water_risk = 66;
			//Pchar.quest.water_risk = 0;
			
			float explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
			//LogIt("explosion_risk = " + explosion_risk);

		//	Pchar.quest.gp_quality = "none";

			LAi_QuestDelay("pistolbarrel_gp0_autoequip", 1.0);
	
			pchar.quest.nitre_splash1.win_condition.l1 = "locator";
			pchar.quest.nitre_splash1.win_condition.l1.location = "GB_chinese_nitre";
			pchar.quest.nitre_splash1.win_condition.l1.locator_group = "goto";
			pchar.quest.nitre_splash1.win_condition.l1.locator = "splash1";
			pchar.quest.nitre_splash1.win_condition = "nitre_splash1";

			pchar.quest.nitre_splash2.win_condition.l2 = "locator";
			pchar.quest.nitre_splash2.win_condition.l2.location = "GB_chinese_nitre";
			pchar.quest.nitre_splash2.win_condition.l2.locator_group = "goto";
			pchar.quest.nitre_splash2.win_condition.l2.locator = "splash2";
			pchar.quest.nitre_splash2.win_condition = "nitre_splash2";
	
			pchar.quest.sulphur_head1.win_condition.l3 = "locator";
			pchar.quest.sulphur_head1.win_condition.l3.location = "GB_chinese_sulphur";
			pchar.quest.sulphur_head1.win_condition.l3.locator_group = "goto";
			pchar.quest.sulphur_head1.win_condition.l3.locator = "head1";
			pchar.quest.sulphur_head1.win_condition = "sulphur_head1";

			pchar.quest.sulphur_head2.win_condition.l4 = "locator";
			pchar.quest.sulphur_head2.win_condition.l4.location = "GB_chinese_sulphur";
			pchar.quest.sulphur_head2.win_condition.l4.locator_group = "goto";
			pchar.quest.sulphur_head2.win_condition.l4.locator = "head2";
			pchar.quest.sulphur_head2.win_condition = "sulphur_head2";

			pchar.quest.chinatown_beam1.win_condition.l5 = "locator";
			pchar.quest.chinatown_beam1.win_condition.l5.location = "GB_chinatown";
			pchar.quest.chinatown_beam1.win_condition.l5.locator_group = "goto";
			pchar.quest.chinatown_beam1.win_condition.l5.locator = "beam1";
			pchar.quest.chinatown_beam1.win_condition = "chinatown_beam1";

			pchar.quest.chinatown_beam2.win_condition.l6 = "locator";
			pchar.quest.chinatown_beam2.win_condition.l6.location = "GB_chinatown";
			pchar.quest.chinatown_beam2.win_condition.l6.locator_group = "goto";
			pchar.quest.chinatown_beam2.win_condition.l6.locator = "beam2";
			pchar.quest.chinatown_beam2.win_condition = "chinatown_beam2";

			pchar.quest.nitre_steplock1.win_condition.l7 = "locator";
			pchar.quest.nitre_steplock1.win_condition.l7.location = "GB_chinese_nitre";
			pchar.quest.nitre_steplock1.win_condition.l7.locator_group = "goto";
			pchar.quest.nitre_steplock1.win_condition.l7.locator = "steplock";
			pchar.quest.nitre_steplock1.win_condition = "nitre_steplock1";

			pchar.quest.sulfur_steplock1.win_condition.l8 = "locator";
			pchar.quest.sulfur_steplock1.win_condition.l8.location = "GB_chinese_sulphur";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator_group = "goto";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator = "steplock";
			pchar.quest.sulfur_steplock1.win_condition = "sulfur_steplock1";

			pchar.quest.fill_mill_boxes.win_condition.l9 = "location";
			pchar.quest.fill_mill_boxes.win_condition.l9.location = "GB_chinese_gunpowder";
			pchar.quest.fill_mill_boxes.win_condition = "fill_mill_boxes";

			pchar.quest.GP_standard.win_condition.l10 = "locator";
			pchar.quest.GP_standard.win_condition.l10.location = "GB_chinese_restaurant";
			pchar.quest.GP_standard.win_condition.l10.locator_group = "goto";
			pchar.quest.GP_standard.win_condition.l10.locator = "dialog";
			pchar.quest.GP_standard.win_condition = "GP_standard";
		break;
//..........................................................................................
		case "pistolbarrel_gp0_autoequip":
			if(CheckCharacterItem(Pchar,"pistolbarrel_gp0"))
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "pistolbarrel_gp0");
				return;
			}
			else
			{
				LAi_QuestDelay("pistolbarrel_gp0_autoequip", 1.0);//loop check
			}
		break;
//..........................................................................................
		case "nitre_splash1":	
			PlaySound("PEOPLE\step_water1.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_nitre", "goto", "splash1A");

			LAi_QuestDelay("nitre_splash1_A", 0.5);
		break;

		case "nitre_splash1_A":
			pchar.quest.nitre_splash1.win_condition.l1 = "locator";
			pchar.quest.nitre_splash1.win_condition.l1.location = "GB_chinese_nitre";
			pchar.quest.nitre_splash1.win_condition.l1.locator_group = "goto";
			pchar.quest.nitre_splash1.win_condition.l1.locator = "splash1";
			pchar.quest.nitre_splash1.win_condition = "nitre_splash1";
		break;
	//---------------------------------------------------------------------------------
		case "nitre_splash2":
			PlaySound("PEOPLE\step_water1.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_nitre", "goto", "splash2A");

			LAi_QuestDelay("nitre_splash2_A", 0.5);
		break;

		case "nitre_splash2_A":
			pchar.quest.nitre_splash2.win_condition.l1 = "locator";
			pchar.quest.nitre_splash2.win_condition.l1.location = "GB_chinese_nitre";
			pchar.quest.nitre_splash2.win_condition.l1.locator_group = "goto";
			pchar.quest.nitre_splash2.win_condition.l1.locator = "splash2";
			pchar.quest.nitre_splash2.win_condition = "nitre_splash2";
		break;
//..........................................................................................
		case "sulphur_head1":	
			PlaySound("PEOPLE\wood3.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "head1A");
			LAi_SetPoorType(Pchar);
			LAi_ApplyCharacterDamage(Pchar, 5);
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );

			LAi_QuestDelay("sulphur_head1_A", 1.5);
		break;

		case "sulphur_head1_A":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			LAi_SetPlayerType(Pchar);

			pchar.quest.sulphur_head1.win_condition.l1 = "locator";
			pchar.quest.sulphur_head1.win_condition.l1.location = "GB_chinese_sulphur";
			pchar.quest.sulphur_head1.win_condition.l1.locator_group = "goto";
			pchar.quest.sulphur_head1.win_condition.l1.locator = "head1";
			pchar.quest.sulphur_head1.win_condition = "sulphur_head1";
		break;
	//---------------------------------------------------------------------------------
		case "sulphur_head2":
			PlaySound("PEOPLE\wood3.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "head2A");
			LAi_SetPoorType(Pchar);
			LAi_ApplyCharacterDamage(Pchar, 5);
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );

			LAi_QuestDelay("sulphur_head2_A", 1.5);
		break;

		case "sulphur_head2_A":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			LAi_SetPlayerType(Pchar);

			pchar.quest.sulphur_head2.win_condition.l1 = "locator";
			pchar.quest.sulphur_head2.win_condition.l1.location = "GB_chinese_sulphur";
			pchar.quest.sulphur_head2.win_condition.l1.locator_group = "goto";
			pchar.quest.sulphur_head2.win_condition.l1.locator = "head2";
			pchar.quest.sulphur_head2.win_condition = "sulphur_head2";
		break;
//..........................................................................................
		case "chinatown_beam1":	
			PlaySound("PEOPLE\jump_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinatown", "goto", "fall1");
			LAi_SetPoorType(Pchar);
			LAi_ApplyCharacterDamage(Pchar, 5);
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );

			LAi_QuestDelay("chinatown_beam1_A", 1.5);
		break;

		case "chinatown_beam1_A":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			LAi_SetPlayerType(Pchar);

			pchar.quest.chinatown_beam1.win_condition.l1 = "locator";
			pchar.quest.chinatown_beam1.win_condition.l1.location = "GB_chinatown";
			pchar.quest.chinatown_beam1.win_condition.l1.locator_group = "goto";
			pchar.quest.chinatown_beam1.win_condition.l1.locator = "beam1";
			pchar.quest.chinatown_beam1.win_condition = "chinatown_beam1";
		break;
	//---------------------------------------------------------------------------------
		case "chinatown_beam2":
			PlaySound("PEOPLE\jump_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinatown", "goto", "fall2");
			LAi_SetPoorType(Pchar);
			LAi_ApplyCharacterDamage(Pchar, 5);
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );

			LAi_QuestDelay("chinatown_beam2_A", 1.5);
		break;

		case "chinatown_beam2_A":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			LAi_SetPlayerType(Pchar);

			pchar.quest.chinatown_beam2.win_condition.l1 = "locator";
			pchar.quest.chinatown_beam2.win_condition.l1.location = "GB_chinatown";
			pchar.quest.chinatown_beam2.win_condition.l1.locator_group = "goto";
			pchar.quest.chinatown_beam2.win_condition.l1.locator = "beam2";
			pchar.quest.chinatown_beam2.win_condition = "chinatown_beam2";
		break;
	//---------------------------------------------------------------------------------
		case "nitre_steplock1":	
			PlaySound("INTERFACE\step_path.wav");
			LAi_SetStayType(Pchar);
			
			if(CheckAttribute(Pchar,"quest.nitre_lever0") && Pchar.quest.nitre_lever0 == "down")	
			{
				LAi_QuestDelay("nitre_steplock1_A", 0.5);
			}
			else 
			{
				LAi_QuestDelay("pchar_huh", 2.0);
				LAi_QuestDelay("nitre_steplock1_B", 1.0);
			}
		break;

		case "nitre_steplock1_A":
			PlaySound("NATURE\water_in.wav");

			if(CheckAttribute(Pchar,"quest.nitre_lever1") && Pchar.quest.nitre_lever1 == "up")	
			{
				//closed => tub gets filled up

				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "full")	
				{
					Pchar.quest.tub1_level = "overfull";

					LAi_QuestDelay("nitre_fire_extinct", 0.1);
				}
				else
				{
					Pchar.quest.tub1_level = "full";
				}

				LAi_QuestDelay("nitre_steplock1_B", 4.0);
			}
			else
			{
				//open
				if(CheckAttribute(Pchar,"quest.nitre_lever2") && Pchar.quest.nitre_lever2 == "up")	
				{
					Pchar.quest.tub2_level = "full";
					Pchar.quest.tub2_content = "water";
			
					switch(Pchar.quest.tub3_content)
			    		{
						case "water":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";
						break;

						case "dirt":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WD";
						break;

						case "nitre":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WN";
						break;
			    		}

					LAi_QuestDelay("delay_nitre_steplock1_B", 4.0);
				}
				else
				{
					//both open: no one becomes full, both clean water

					Pchar.quest.tub2_content = "water";		
					Pchar.quest.tub3_content = "water";
					Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";

					LAi_QuestDelay("delay_nitre_steplock1_B", 4.0);
				}
			}
		break;
		
		case "delay_nitre_steplock1_B":
			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "stepback", "nitre_steplock1_B");
		break;

		case "nitre_steplock1_B":
			PlaySound("PEOPLE\step_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_nitre", "goto", "stepback");
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";

			pchar.quest.nitre_steplock1.win_condition.l1 = "locator";
			pchar.quest.nitre_steplock1.win_condition.l1.location = "GB_chinese_nitre";
			pchar.quest.nitre_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.nitre_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.nitre_steplock1.win_condition = "nitre_steplock1";
		break;
//..........................................................................................
		case "sulfur_steplock1":	
			LAi_SetStayType(Pchar);
			
			if(Locations[FindLocation("GB_chinese_sulphur")].models.always.locators == "TRI_l_sulphur_open")
			{
				PlaySound("INTERFACE\lever_stuck.wav");

				LAi_QuestDelay("sulfur_steplock1_C", 1.0);
			}
			
			if(Locations[FindLocation("GB_chinese_sulphur")].models.always.locators == "TRI_l_sulphur_closed")
			{
				PlaySound("INTERFACE\step_path.wav");

				LAi_QuestDelay("sulfur_steplock1_A", 0.5);
			}
		break;

		case "sulfur_steplock1_A":
			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{
				LAi_QuestDelay("sulfur_steplock1_B", 0.1);
			}
			else 
			{	
				PlaySound("INTERFACE\fire_on.wav");
				PlaySound("INTERFACE\fire_on.wav");

				LAi_QuestDelay("sulfur_steplock1_B", 1.0);
			}
		break;

		case "sulfur_steplock1_B":	
			PlaySound("PEOPLE\step_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "step_back");
			LAi_SetPlayerType(Pchar);
			
			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{

			}
			else 
			{
				if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
				{
					//so it not starts too
				}
				else
				{
					Pchar.quest.sulfur_fire = "on";

					LAi_QuestDelay("sulfur_burning_only", 1.0);
				}
			}
			
			if(CheckAttribute(Pchar,"quest.sulfur_boiling") && Pchar.quest.sulfur_boiling == "on")
			{

			}
			else
			{
				if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
				{
					//so it not starts too
				}
				else
				{
					if(CheckAttribute(Pchar, "quest.sulfur_water") && Pchar.quest.sulfur_water == "filled")
					{
						Pchar.quest.sulfur_boiling = "on";

						LAi_QuestDelay("sulfur_boiling_only", 1.0);
						LAi_QuestDelay("sulfur_boiling_only_message", 3.0);
					}
				}
			}

			if(CheckAttribute(Pchar,"quest.sulfur_dust") && Pchar.quest.sulfur_dust == "on")
			{

			}
			else 
			{
				if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
				{
					//so it not starts too
				}
				else
				{
					if(CheckAttribute(Pchar, "quest.sulfur_pyrite") && Pchar.quest.sulfur_pyrite == "filled")
					{
						Pchar.quest.sulfur_dust = "on";

						LAi_QuestDelay("sulfur_dust_only", 1.0);
						LAi_QuestDelay("sulfur_dust_only_message", 3.0);
					}
				}
			}
			
			if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
			{

			}
			else 
			{
				LAi_QuestDelay("sulfur_distillery_check", 0.1);
			}

			pchar.quest.sulfur_steplock1.win_condition.l8 = "locator";
			pchar.quest.sulfur_steplock1.win_condition.l8.location = "GB_chinese_sulphur";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator_group = "goto";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator = "steplock";
			pchar.quest.sulfur_steplock1.win_condition = "sulfur_steplock1";
		break;

		case "sulfur_steplock1_C":	
			PlaySound("PEOPLE\step_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "step_back");
			LAi_SetPlayerType(Pchar);

			pchar.quest.sulfur_steplock1.win_condition.l8 = "locator";
			pchar.quest.sulfur_steplock1.win_condition.l8.location = "GB_chinese_sulphur";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator_group = "goto";
			pchar.quest.sulfur_steplock1.win_condition.l8.locator = "steplock";
			pchar.quest.sulfur_steplock1.win_condition = "sulfur_steplock1";
		break;

		case "fill_mill_boxes":
			locations[FindLocation(Pchar.location)].box5.items.pistolsulphur_H = 1;
			locations[FindLocation(Pchar.location)].box7.items.pistolcharcoal_H = 1;
			locations[FindLocation(Pchar.location)].box6.items.pistolnitre_big_F = 3;
			locations[FindLocation(Pchar.location)].box9.items.bladebarrel_gp0 = 1;
			locations[FindLocation(Pchar.location)].box9.items.pistolbarrel_gp0 = 1;
			locations[FindLocation(Pchar.location)].box14.items.doc2A = 1;
			locations[FindLocation(Pchar.location)].box15.items.doc1A = 1;




	/*
			locations[FindLocation(Pchar.location)].box5.items.pistolsulphur_H = 1;
			locations[FindLocation(Pchar.location)].box7.items.pistolcharcoal_E = 1;
			locations[FindLocation(Pchar.location)].box6.items.pistolnitre_big_F = 2;
			locations[FindLocation(Pchar.location)].box6.items.pistolnitre_H = 1;
			locations[FindLocation(Pchar.location)].box9.items.bladebarrel_gp0 = 1;
			locations[FindLocation(Pchar.location)].box9.items.pistolbarrel_gp0 = 1;
			locations[FindLocation(Pchar.location)].box14.items.doc2A = 1;
			locations[FindLocation(Pchar.location)].box15.items.doc1A = 1;

			//locations[FindLocation(Pchar.location)].box9.items.bladebottle_BE0 = 1;
			//locations[FindLocation(Pchar.location)].box9.items.bladebottle_CE0 = 1;
	*/
		break;

		case "unlock_charcoal_storeroom":
			Locations[FindLocation("GB_chinese_charcoal")].locators_radius.box.box5 = 0.0001;
			Locations[FindLocation("GB_chinese_charcoal")].locators_radius.reload.reload1 = 0.7;
			Locations[FindLocation("GB_chinese_charcoal")].reload.l1.disable = 0;
			DoQuestReloadToLocation("GB_charcoal_storeroom", "goto", "arrive", "unlock_charcoal_storeroom1");
		break;

		case "unlock_charcoal_storeroom1":
			Pchar.quest.charcoal_box5 = "off";
		break;
//----------------------------------------------------------------------------------------------------------------
		case "Chinatown_fill_bucket":
			Pchar.quest.China_well = "phase2";
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_Chinatown")], true);
			LAi_SetPlayerType(Pchar);
		break;

		case "Chinatown_take_bucket":
			Pchar.quest.China_well = "phase1";
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_Chinatown")], true);
			LAi_SetPlayerType(Pchar);
		break;
//----------------------------------------------------------------------------------------------------------------
		case "stay_at_large_bottle":
			//from SL_utils GB_chinese_gunpowder box13
			if(!LAi_IsFightMode(Pchar))
			{
				Pchar.quest.mill_position = "elsewhere";			//reset
				ChangeCharacterAddressGroup(Pchar, "GB_chinese_gunpowder", "goto", "box13");
				LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			}
			else LAi_QuestDelay("stay_at_large_bottle", 1.0);//loops until not fightmode
		break;

		case "stay_at_medium_bottle":
			//from SL_utils GB_chinese_gunpowder box12
			if(!LAi_IsFightMode(Pchar))
			{
				Pchar.quest.mill_position = "elsewhere";			//reset
				ChangeCharacterAddressGroup(Pchar, "GB_chinese_gunpowder", "goto", "box12");
				LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			}
			else LAi_QuestDelay("stay_at_medium_bottle", 1.0);//loops until not fightmode
		break;

		case "place_large_bottle":
			Locations[FindLocation("GB_chinese_gunpowder")].image = "";
			DoQuestReloadToLocation("GB_chinese_gunpowder", "goto", "box13", "place_large_bottle1");
		break;

		case "place_large_bottle1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			Pchar.quest.mill_position = "elsewhere";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "GB_gunpowder_mill.tga";
//	LogIt("large_bottle = " + Pchar.quest.large_bottle);

			if(CheckAttribute(Pchar,"quest.large_bottle") && Pchar.quest.large_bottle == "LG2")
			{
				Logit(TranslateString("","That's Salpeter Soot alright!"));
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			}

			if(CheckAttribute(Pchar,"quest.large_bottle") && Pchar.quest.large_bottle == "LY2")
			{
				Logit(TranslateString("","That's Sulfur Soot alright!"));
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			}
		break;

		case "place_medium_bottle":
			Locations[FindLocation("GB_chinese_gunpowder")].image = "";
			DoQuestReloadToLocation("GB_chinese_gunpowder", "goto", "box12", "place_medium_bottle1");
		break;

		case "place_medium_bottle1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			Pchar.quest.mill_position = "elsewhere";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "GB_gunpowder_mill.tga";
//	LogIt("medium_bottle = " + Pchar.quest.medium_bottle);
		break;
//..........................................................................................
		case "stay_at_ladder_top":
			//from SL_utils GB_chinese_gunpowder box10
	//LogIt("STAY TOP");
			if(!LAi_IsFightMode(Pchar))
			{
				Pchar.quest.mill_position = "elsewhere";			//reset
				LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);

				LAi_QuestDelay("stay_at_ladder_top1", 1.0);
			}
			else LAi_QuestDelay("stay_at_ladder_top", 1.0);//loops until not fightmode
		break;

		case "stay_at_ladder_top1":
	//LogIt("STAY TOP1");
			Pchar.quest.gp_container = "0";			//reset
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_gunpowder", "goto", "box8");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("pchar_playertype", 0.5);
			LAi_QuestDelay("quicksave", 1.0);


/*
	LogIt("store_charcoal = " + makefloat(Pchar.quest.store_charcoal));
	LogIt("store_nitre = " + makefloat(Pchar.quest.store_nitre));
	LogIt("store_sulfur = " + makefloat(Pchar.quest.store_sulfur));
	//LogIt("store_TOTAL = " + makefloat(Pchar.quest.store_total));

	LogIt("mix_charcoal = " + makefloat(Pchar.quest.mix_charcoal));
	LogIt("mix_nitre = " + makefloat(Pchar.quest.mix_nitre));
	LogIt("mix_sulfur = " + makefloat(Pchar.quest.mix_sulfur));
	//LogIt("mix_TOTAL = " + makefloat(Pchar.quest.mix_total));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));

	LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
	LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
	LogIt("water_risk = " + Pchar.quest.water_risk);
	explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
	LogIt("explosion_risk = " + explosion_risk);

	LogIt("gp_quality = " + Pchar.quest.gp_quality);
*/	

	Logit(TranslateString("","In the Gunpowder Mill now:"));

	if(makefloat(Pchar.quest.BB_TOTAL) == 0 )
	{
		if(makefloat(Pchar.quest.water_risk) == 0)
		{
			Logit(TranslateString("","water"));
		}
		else
		{
			Logit(TranslateString("","nothing"));
		}
	}
	else
	{
		if(makefloat(Pchar.quest.store_charcoal) + makefloat(Pchar.quest.mix_charcoal) > 0)
		{ LogIt(makefloat(Pchar.quest.store_charcoal) + makefloat(Pchar.quest.mix_charcoal) + " " + TranslateString("","charcoal")); }

		if(makefloat(Pchar.quest.store_nitre) + makefloat(Pchar.quest.mix_nitre) > 0)
		{ LogIt(makefloat(Pchar.quest.store_nitre) + makefloat(Pchar.quest.mix_nitre) + " " + TranslateString("","nitre")); }

		if(makefloat(Pchar.quest.store_sulfur) + makefloat(Pchar.quest.mix_sulfur) > 0)
		{ LogIt(makefloat(Pchar.quest.store_sulfur) + makefloat(Pchar.quest.mix_sulfur) + " " + TranslateString("","sulfur")); }

		if(makefloat(Pchar.quest.water_risk) == 0)
		{ Logit(TranslateString("","water")); }
/*
		LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
		LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
		LogIt("water_risk = " + Pchar.quest.water_risk);
		explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
		LogIt("explosion_risk = " + explosion_risk);
*/
	}
		break;

		case "fill_and_return_from_ladder_top":
	//LogIt("FILL & RETURN FROM TOP");
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			LAi_SetPlayerType(Pchar);
			Pchar.quest.mill_position = "elsewhere";
		break;
//..........................................................................................
		case "stay_at_bin":
			//from SL_utils GB_chinese_gunpowder box3
			if(!LAi_IsFightMode(Pchar))
			{
				Pchar.quest.mill_position = "elsewhere";			//reset
				ChangeCharacterAddressGroup(Pchar, "GB_chinese_gunpowder", "goto", "box3");
				LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);

				LAi_QuestDelay("pchar_playertype", 1.0);
			}
			else LAi_QuestDelay("stay_at_bin", 1.0);//loops until not fightmode
		break;

		case "empty_gp_barrel":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			LAi_SetPlayerType(Pchar);
			Pchar.quest.mill_position = "elsewhere";
		break;
//..........................................................................................
		case "place_empty_barrel_on_floor1":
			Locations[FindLocation(Pchar.location)].models.always.locators = "sklad_l_GB_barrel";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "";
			DoQuestReloadToLocation("GB_chinese_gunpowder", "goto", "box16", "place_empty_barrel_on_floor2");
		break;

		case "place_empty_barrel_on_floor2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			Pchar.quest.mill_position = "elsewhere";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "GB_gunpowder_mill.tga";
		break;
//..........................................................................................
		case "pick_up_barrel_from_floor1":
			Locations[FindLocation(Pchar.location)].models.always.locators = "sklad_l_GB_empty";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "";
			DoQuestReloadToLocation("GB_chinese_gunpowder", "goto", "box16", "pick_up_barrel_from_floor2");
		break;

		case "pick_up_barrel_from_floor2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], true);
			Pchar.quest.mill_position = "elsewhere";
			Locations[FindLocation("GB_chinese_gunpowder")].image = "GB_gunpowder_mill.tga";

			if(CheckAttribute(Pchar, "quest.2barrels_gpS") && Pchar.quest.2barrels_gpS == "second_time")
			{
				if(CheckCharacterItem(Pchar,"bladebarrel_gpS") && CheckCharacterItem(Pchar,"pistolbarrel_gpS"))
				{
					Pchar.quest.2barrels_gpS = "not_again";

					Logit(TranslateString("","Yes! I made it - now to the Restaurant."));
					PlaySound("OBJECTS\DUEL\man_attack6.wav");

					if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gpS"))
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladebarrel_gpS");
					}

					if(!IsEquipCharacterByItem(Pchar, "pistolbarrel_gpS"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "pistolbarrel_gpS");
					}

					Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_2_produced";
					ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinatown", "goto", "chinese");
					LAi_SetStayType(characterFromID("the_chinese")); 

					CloseQuestHeader("Gunpowder");

					Pchar.quest.remove_lieutenant.win_condition.l1 = "ExitFromLocation";
					Pchar.quest.remove_lieutenant.win_condition.l1.location = "GB_chinese_gunpowder";
					Pchar.quest.remove_lieutenant.win_condition = "gpS_2";
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladebarrel_gpS"))
					{
						if(makefloat(Pchar.quest.mix_charcoal) == 0.5 && makefloat(Pchar.quest.mix_nitre) == 3.0 && makefloat(Pchar.quest.mix_sulfur) == 0.5)
						{
							Logit(TranslateString("","I have made Gunpowder but there's still some in the Mill - enough for another barrel."));						
							PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
						}
					}
					else
					{
						if(CheckCharacterItem(Pchar,"pistolbarrel_gpS"))
						{
							if(makefloat(Pchar.quest.mix_charcoal) == 0.5 && makefloat(Pchar.quest.mix_nitre) == 3.0 && makefloat(Pchar.quest.mix_sulfur) == 0.5)
							{
								Logit(TranslateString("","I have made Gunpowder but there's still some in the Mill - enough for another barrel."));						
								PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
							}
						}
					}
				}
			}
			else
			{
				if(CheckAttribute(Pchar, "quest.2barrels_gpS") && Pchar.quest.2barrels_gpS == "first_time")
				{
					if(CheckCharacterItem(Pchar,"bladebarrel_gpS") && CheckCharacterItem(Pchar,"pistolbarrel_gpS"))
					{
						Pchar.quest.2barrels_gpS = "second_time";
						//Pchar.quest.rope_first_time = "no";		//skipped

						Logit(TranslateString("","Yes! I made it - now to the Restaurant."));
						PlaySound("OBJECTS\DUEL\man_attack6.wav");	

						if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gpS"))
						{
							RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
							EquipCharacterByItem(Pchar, "bladebarrel_gpS");
						}

						if(!IsEquipCharacterByItem(Pchar, "pistolbarrel_gpS"))
						{
							RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
							EquipCharacterByItem(Pchar, "pistolbarrel_gpS");
						}

						Locations[FindLocation("GB_Chinese_restaurant")].models.always.locators = "chinarest_l_guests";
						locations[FindLocation("GB_Chinese_restaurant")].type = "Chinese_restaurant";

						ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinese_restaurant", "goto", "goto2");
						LAi_SetStayType(characterFromID("the_chinese"));

						pchar.quest.GP_standard_1_produced.win_condition.l1 = "locator";
						pchar.quest.GP_standard_1_produced.win_condition.l1.location = "GB_chinese_restaurant";
						pchar.quest.GP_standard_1_produced.win_condition.l1.locator_group = "goto";
						pchar.quest.GP_standard_1_produced.win_condition.l1.locator = "goto2";
						pchar.quest.GP_standard_1_produced.win_condition = "GP_standard_1_produced";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"bladebarrel_gpS"))
						{
							if(makefloat(Pchar.quest.mix_charcoal) == 0.5 && makefloat(Pchar.quest.mix_nitre) == 3.0 && makefloat(Pchar.quest.mix_sulfur) == 0.5)
							{
								Logit(TranslateString("","I have made Gunpowder but there's still some in the Mill - enough for another barrel."));						
								PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
							}
						}
						else
						{
							if(CheckCharacterItem(Pchar,"pistolbarrel_gpS"))
							{
								if(makefloat(Pchar.quest.mix_charcoal) == 0.5 && makefloat(Pchar.quest.mix_nitre) == 3.0 && makefloat(Pchar.quest.mix_sulfur) == 0.5)
								{
									Logit(TranslateString("","I have made Gunpowder but there's still some in the Mill - enough for another barrel."));						
									PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
								}
							}
						}
					}
				}
			}
			else
			{
				//3:rd or more time
				if(CheckCharacterItem(Pchar,"bladebarrel_gpS") && CheckCharacterItem(Pchar,"pistolbarrel_gpS"))
				{
					Logit(TranslateString("","I have made Gunpowder but NOT the right type."));						
					PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");

					if(CheckAttribute(Pchar,"quest.last_ingredients") && Pchar.quest.last_ingredients == "given")
					{
						LAi_QuestDelay("Jup_with_empty_barrels", 2.0);
					}
					else 
					{
						Pchar.quest.need_barrels = "yes";

						GiveItem2Character(characterFromID("Jupiter"), "bladebarrel_gp0");
						EquipCharacterByItem(characterFromID("Jupiter"), "bladebarrel_gp0");
						GiveItem2Character(characterFromID("Jupiter"), "pistolbarrel_gp0");
						EquipCharacterByItem(characterFromID("Jupiter"), "pistolbarrel_gp0");

						Pchar.quest.lost_charcoal = 1.0;
						Pchar.quest.lost_nitre = 6.0;
						Pchar.quest.lost_sulfur = 1.0;

						LAi_QuestDelay("Jup_with_ingredients", 2.0);
					}
				}
			}

	//---------------------------------------------------------------------------------------------------------------------------------------------------

			if(CheckAttribute(Pchar, "quest.2barrels_gpF") && Pchar.quest.2barrels_gpF == "first_time")
			{
				if(CheckCharacterItem(Pchar,"bladebarrel_gpF") && CheckCharacterItem(Pchar,"pistolbarrel_gpF"))
				{
					Pchar.quest.2barrels_gpF = "not_again";
			
					Logit(TranslateString("","Yes! I made it - now to the Restaurant."));
					PlaySound("VOICE\ENGLISH\blaze_2.wav");

					if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gpF"))
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladebarrel_gpF");
					}

					if(!IsEquipCharacterByItem(Pchar, "pistolbarrel_gpF"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "pistolbarrel_gpF");
					}

					DeleteQuestHeader("Sulfur");
					DeleteQuestHeader("Salpeter");
					DeleteQuestHeader("Charcoal");
					DeleteQuestHeader("Gunpowder");

					LAi_QuestDelay("very_nice", 1.0);
					LAi_QuestDelay("gunpowder_F", 2.0);
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladebarrel_gpF"))
					{
						if(makefloat(Pchar.quest.mix_charcoal) == 1.0 && makefloat(Pchar.quest.mix_nitre) == 2.0 && makefloat(Pchar.quest.mix_sulfur) == 1.0)
						{
							Logit(TranslateString("","I have made Gunpowder for Fireworks but there's still some in the Mill."));						
							PlaySound("VOICE\ENGLISH\blaze_1.wav");
						}
					}
					else
					{
						if(CheckCharacterItem(Pchar,"pistolbarrel_gpF"))
						{
							if(makefloat(Pchar.quest.mix_charcoal) == 1.0 && makefloat(Pchar.quest.mix_nitre) == 2.0 && makefloat(Pchar.quest.mix_sulfur) == 1.0)
							{
								Logit(TranslateString("","I have made Gunpowder for Fireworks but there's still some in the Mill."));						
								PlaySound("VOICE\ENGLISH\blaze_1.wav");
							}
						}
					}
				}
			}				
		break;
//..........................................................................................
		case "rumble_mixing_gunpowder":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder1", 0.5);
		break;

		case "rumble_mixing_gunpowder1":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder2", 0.5);
		break;

		case "rumble_mixing_gunpowder2":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder3", 0.5);
		break;

		case "rumble_mixing_gunpowder3":
			LAi_SetStayType(Pchar);

			explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
			
			if(rand(99) < explosion_risk)		
			{
				LAi_SetSitType(Pchar);

				LAi_QuestDelay("gp_explosion", 0.5);
			}
			else
			{
				LAi_QuestDelay("rumble_mixing_gunpowder4", 0.5);
			}
		break;

		case "rumble_mixing_gunpowder4":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder5", 0.5);
		break;

		case "rumble_mixing_gunpowder5":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder6", 0.5);
		break;

		case "rumble_mixing_gunpowder6":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder7", 0.5);
		break;

		case "rumble_mixing_gunpowder7":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder8", 0.5);
		break;

		case "rumble_mixing_gunpowder8":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder9", 0.5);
		break;

		case "rumble_mixing_gunpowder9":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("rumble_mixing_gunpowder10", 0.5);
		break;

		case "rumble_mixing_gunpowder10":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("AMBIENT\JAIL\sigh2.wav");

			LAi_SetPlayerType(Pchar);
			Pchar.quest.rumble_gp = "off";

			Pchar.quest.mix_charcoal = makefloat(Pchar.quest.store_charcoal) + makefloat(Pchar.quest.mix_charcoal);
			Pchar.quest.mix_nitre = makefloat(Pchar.quest.store_nitre) + makefloat(Pchar.quest.mix_nitre);
			Pchar.quest.mix_sulfur = makefloat(Pchar.quest.store_sulfur) + makefloat(Pchar.quest.mix_sulfur);
			Pchar.quest.mix_total = makefloat(Pchar.quest.store_total) + makefloat(Pchar.quest.mix_total);

			Pchar.quest.BB_total = makefloat(Pchar.quest.mix_total);

			Pchar.quest.store_charcoal = 0;
			Pchar.quest.store_nitre = 0;
			Pchar.quest.store_sulfur = 0;
			Pchar.quest.store_total = 0;

			if(makefloat(Pchar.quest.mix_charcoal) >= 1 && makefloat(Pchar.quest.mix_nitre) >= 1) Pchar.quest.charcoal_risk = 0;
			if(makefloat(Pchar.quest.mix_sulfur) >= 1 && makefloat(Pchar.quest.mix_nitre) >= 1) Pchar.quest.sulfur_risk = 0;
/*
	//LogIt("store_charcoal = " + makefloat(Pchar.quest.store_charcoal));
	//LogIt("store_nitre = " + makefloat(Pchar.quest.store_nitre));
	//LogIt("store_sulfur = " + makefloat(Pchar.quest.store_sulfur));
	//LogIt("store_TOTAL = " + makefloat(Pchar.quest.store_total));

	LogIt("mix_charcoal = " + makefloat(Pchar.quest.mix_charcoal));
	LogIt("mix_nitre = " + makefloat(Pchar.quest.mix_nitre));
	LogIt("mix_sulfur = " + makefloat(Pchar.quest.mix_sulfur));
	//LogIt("mix_TOTAL = " + makefloat(Pchar.quest.mix_total));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));

	LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
	LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
	LogIt("water_risk = " + Pchar.quest.water_risk);
	explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
	LogIt("explosion_risk = " + explosion_risk);

	LogIt("gp_quality = " + Pchar.quest.gp_quality);
*/		
		break;
//..........................................................................................
		case "gp_explosion":
			PauseAllSounds();
			PlaySound("OBJECTS\DUEL\pistol_musket.wav");
			PlaySound("OBJECTS\DUEL\pistol_musket.wav");
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\SHIPCHARGE\LG42H.wav");
			PlaySound("OBJECTS\SHIPCHARGE\LG42H.wav");
			PlayStereoSound("OBJECTS\SHIPCHARGE\gunpowder_explosion.wav");

			GetCharacterPos(Pchar, &u, &v, &w);

			CreateParticleSystem("fort_fire" , u-0.5, v, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("fort_fire" , u-0.1, v+1.8, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("fort_fire" , u-0.3, v+0.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("fort_fire" , u-0.2, v+1.0, w-0.5, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("fort_fire" , u, v+1.0, w+0.5, 0.0, 0.0, 0.0, sti(20) );

			CreateParticleSystem("canfire" , u-0.5, v, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("canfire" , u-0.1, v+1.8, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("canfire" , u-0.3, v+0.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("canfire" , u-0.2, v+1.0, w-0.5, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("canfire" , u, v+1.0, w+0.5, 0.0, 0.0, 0.0, sti(20) );

			CreateParticleSystem("gunfire_red" , u-0.5, v, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire_red" , u-0.1, v+1.8, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire_red" , u-0.3, v+0.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire_red" , u-0.2, v+1.0, w-0.5, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire_red" , u, v+1.0, w+0.5, 0.0, 0.0, 0.0, sti(20) );

			CreateParticleSystem("stars_fire" , u-0.5, v, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u-0.1, v+1.8, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u-0.3, v+0.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u-0.2, v+1.0, w-0.5, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u, v+1.0, w+0.5, 0.0, 0.0, 0.0, sti(20) );

			CreateParticleSystem("cancloud" , u-0.5, v, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("cancloud" , u-0.1, v+1.8, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("cancloud" , u-0.3, v+0.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("cancloud" , u-0.2, v+1.0, w-0.5, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("cancloud" , u, v+1.0, w+0.5, 0.0, 0.0, 0.0, sti(20) );

			CreateParticleSystem("splinters", u, v+1.8, W, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters", u-0.5, v+1.0, W, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", u, v+1.8, w, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", u-0.5, v+1.0, w, 0.0, 0.0, 0.0, 0);

			LAi_ApplyCharacterDamage(Pchar, 1000);
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);

			LAi_QuestDelay("gp_killed", 9.0);//was 8
		break;

		case "gp_killed":
			GameOverOrg("land");
		break;
//..........................................................................................
		case "no_running_gunpowder":
			LAi_SetStayType(Pchar);
			LAi_SetPlayerType(Pchar);

			if(CheckAttribute(Pchar, "quest.water_added") && Pchar.quest.water_added == "yes")
			{
				PlaySound("INTERFACE\running_water_short.wav");	
				Pchar.quest.water_added = "no";
				Pchar.quest.water_risk = 66;

				LAi_QuestDelay("no_running_gunpowder1", 1.5);
			}		
/*	
	LogIt("store_charcoal = " + makefloat(Pchar.quest.store_charcoal));
	LogIt("store_nitre = " + makefloat(Pchar.quest.store_nitre));
	LogIt("store_sulfur = " + makefloat(Pchar.quest.store_sulfur));
	//LogIt("store_TOTAL = " + makefloat(Pchar.quest.store_total));

	LogIt("mix_charcoal = " + makefloat(Pchar.quest.mix_charcoal));
	LogIt("mix_nitre = " + makefloat(Pchar.quest.mix_nitre));
	LogIt("mix_sulfur = " + makefloat(Pchar.quest.mix_sulfur));
	//LogIt("mix_TOTAL = " + makefloat(Pchar.quest.mix_total));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));

	LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
	LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
	LogIt("water_risk = " + Pchar.quest.water_risk);
	explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
	LogIt("explosion_risk = " + explosion_risk);

	LogIt("gp_quality = " + Pchar.quest.gp_quality);
*/
		break;

		case "no_running_gunpowder1":
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
		break;
//..........................................................................................
		case "running_gunpowder_barrel":
			LAi_SetStayType(Pchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box13");

			PlaySound("PEOPLE\gunpowder.wav");

			//PERCENTAGE
			
			float BB_perc_charcoal = (makefloat(Pchar.quest.mix_charcoal))/(makefloat(Pchar.quest.mix_total));
			float BB_perc_sulfur = (makefloat(Pchar.quest.mix_sulfur))/(makefloat(Pchar.quest.mix_total));
			float BB_perc_nitre = (makefloat(Pchar.quest.mix_nitre))/(makefloat(Pchar.quest.mix_total));
/*
	LogIt("BB_perc_charcoal = " + BB_perc_charcoal);
	LogIt("BB_perc_sulfur = " + BB_perc_sulfur);
	LogIt("BB_perc_nitre = " + BB_perc_nitre);
*/
			float free_space = 4.0 - makefloat(Pchar.quest.gp_total);
	
			if(free_space >= makefloat(Pchar.quest.mix_total))
			{
//	LogIt("TAKE ALL");
				Pchar.quest.gp_charcoal = makefloat(Pchar.quest.gp_charcoal) + makefloat(Pchar.quest.mix_charcoal);
				Pchar.quest.gp_sulfur = makefloat(Pchar.quest.gp_sulfur) + makefloat(Pchar.quest.mix_sulfur);
				Pchar.quest.gp_nitre = makefloat(Pchar.quest.gp_nitre) + makefloat(Pchar.quest.mix_nitre);
				Pchar.quest.gp_total = makefloat(Pchar.quest.gp_charcoal) + makefloat(Pchar.quest.gp_sulfur) + makefloat(Pchar.quest.gp_nitre);

				Pchar.quest.mix_charcoal = 0;
				Pchar.quest.mix_nitre = 0;
				Pchar.quest.mix_sulfur = 0;
				Pchar.quest.mix_total = 0;

				Pchar.quest.BB_total = 0;

				Pchar.quest.water_added = "no";
				Pchar.quest.water_risk = 66;
			}
			else
			{
//	LogIt("TAKE SOME");
				float add_charcoal = BB_perc_charcoal*free_space;
				float add_sulfur = BB_perc_sulfur*free_space;
				float add_nitre = BB_perc_nitre*free_space;
/*
	LogIt("free_space = " + free_space);
	LogIt("add_charcoal = " + add_charcoal);
	LogIt("add_sulfur = " + add_sulfur);
	LogIt("add_nitre = " + add_nitre);
*/
				Pchar.quest.gp_charcoal = makefloat(Pchar.quest.gp_charcoal) + add_charcoal;
				Pchar.quest.gp_sulfur = makefloat(Pchar.quest.gp_sulfur) + add_sulfur;
				Pchar.quest.gp_nitre = makefloat(Pchar.quest.gp_nitre) + add_nitre;
				Pchar.quest.gp_total = makefloat(Pchar.quest.gp_charcoal) + makefloat(Pchar.quest.gp_sulfur) + makefloat(Pchar.quest.gp_nitre);

				Pchar.quest.mix_charcoal = makefloat(Pchar.quest.mix_charcoal) - add_charcoal;
				Pchar.quest.mix_sulfur = makefloat(Pchar.quest.mix_sulfur) - add_sulfur;
				Pchar.quest.mix_nitre = makefloat(Pchar.quest.mix_nitre) - add_nitre;

				Pchar.quest.mix_total = makefloat(Pchar.quest.mix_charcoal) + makefloat(Pchar.quest.mix_sulfur) + makefloat(Pchar.quest.mix_nitre);
				Pchar.quest.BB_total = makefloat(Pchar.quest.mix_total);
			}

			LAi_QuestDelay("running_gunpowder_barrel_end", 3.0);
		break;

		case "running_gunpowder_barrel_end":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.running_gp = "off";

			if(makefloat(Pchar.quest.gp_total) == 4.0)
			{
				if(makefloat(Pchar.quest.gp_nitre) == 3.0 && makefloat(Pchar.quest.gp_charcoal) == 0.5 
				&& makefloat(Pchar.quest.gp_sulfur) == 0.5)
				{
					Pchar.quest.gp_quality = "standard";
				}
				else
				{
					if(makefloat(Pchar.quest.gp_nitre) == 2.0 && makefloat(Pchar.quest.gp_charcoal) == 1.0 
					&& makefloat(Pchar.quest.gp_sulfur) == 1.0)
					{
						if(CheckAttribute(Pchar,"quest.3workshops") && Pchar.quest.3workshops == "open")
						{
							Pchar.quest.gp_quality = "fireworks";
						}
						else Pchar.quest.gp_quality = "wrong";
						//if you make gpF before you have learned how to, it counts as "wrong" mixture
					}
				}
				else 
				{
					Pchar.quest.gp_quality = "wrong";

					Pchar.quest.lost_charcoal = makefloat(Pchar.quest.lost_charcoal) + makefloat(Pchar.quest.gp_charcoal);
					Pchar.quest.lost_sulfur = makefloat(Pchar.quest.lost_sulfur) + makefloat(Pchar.quest.gp_sulfur);
					Pchar.quest.lost_nitre = makefloat(Pchar.quest.lost_nitre) + makefloat(Pchar.quest.gp_nitre);
				}
			}

/*
	LogIt("lost_charcoal = " + makefloat(Pchar.quest.lost_charcoal));
	LogIt("lost_nitre = " + makefloat(Pchar.quest.lost_nitre));
	LogIt("lost_sulfur = " + makefloat(Pchar.quest.lost_sulfur));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));
*/

/*			
	//LogIt("store_charcoal = " + makefloat(Pchar.quest.store_charcoal));
	//LogIt("store_nitre = " + makefloat(Pchar.quest.store_nitre));
	//LogIt("store_sulfur = " + makefloat(Pchar.quest.store_sulfur));
	//LogIt("store_TOTAL = " + makefloat(Pchar.quest.store_total));

	LogIt("mix_charcoal = " + makefloat(Pchar.quest.mix_charcoal));
	LogIt("mix_nitre = " + makefloat(Pchar.quest.mix_nitre));
	LogIt("mix_sulfur = " + makefloat(Pchar.quest.mix_sulfur));
	//LogIt("mix_TOTAL = " + makefloat(Pchar.quest.mix_total));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));

	LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
	LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
	LogIt("water_risk = " + Pchar.quest.water_risk);
	explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
	LogIt("explosion_risk = " + explosion_risk);

	LogIt("gp_quality = " + Pchar.quest.gp_quality);
*/
		break;
//..........................................................................................
		case "running_gunpowder_floor":
			LAi_SetStayType(Pchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box13");

			PlaySound("PEOPLE\gunpowder.wav");
			CreateParticleSystemX("blast_dirt_black", -0.2, 0.3, 2.2, -0.2, 0.3, 2.2,10);
	
			Pchar.quest.lost_charcoal = makefloat(Pchar.quest.lost_charcoal) + makefloat(Pchar.quest.store_charcoal) + makefloat(Pchar.quest.mix_charcoal);
			Pchar.quest.lost_nitre = makefloat(Pchar.quest.lost_nitre) + makefloat(Pchar.quest.store_nitre) + makefloat(Pchar.quest.mix_nitre);
			Pchar.quest.lost_sulfur = makefloat(Pchar.quest.lost_sulfur) + makefloat(Pchar.quest.store_sulfur) + makefloat(Pchar.quest.mix_sulfur);

			//all are set to 0, big barrel is empty
			Pchar.quest.store_charcoal = 0;
			Pchar.quest.store_nitre = 0;
			Pchar.quest.store_sulfur = 0;
			Pchar.quest.store_total = 0;

			Pchar.quest.mix_charcoal = 0;
			Pchar.quest.mix_nitre = 0;
			Pchar.quest.mix_sulfur = 0;
			Pchar.quest.mix_total = 0;

			Pchar.quest.BB_total = 0;

			Pchar.quest.gp_charcoal = 0;
			Pchar.quest.gp_nitre = 0;
			Pchar.quest.gp_sulfur = 0;
			Pchar.quest.gp_total = 0;

			Pchar.quest.gp_quality = "none";

			Pchar.quest.charcoal_risk = 0;
			Pchar.quest.sulfur_risk = 0;
			Pchar.quest.water_added = "no";
			Pchar.quest.water_risk = 66;

			LAi_QuestDelay("running_gunpowder_floor_end", 3.0);
		break;

		case "running_gunpowder_floor_end":
			Logit(TranslateString("","Oh no - I lost all the Gunpowder on the floor!"));
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");

			LAi_SetPlayerType(Pchar);
			Pchar.quest.running_gp = "off";

	LogIt("lost_charcoal = " + makefloat(Pchar.quest.lost_charcoal));
	LogIt("lost_nitre = " + makefloat(Pchar.quest.lost_nitre));
	LogIt("lost_sulfur = " + makefloat(Pchar.quest.lost_sulfur));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));


/*
	//all are set to 0, big barrel is empty
	LogIt("store_charcoal = " + makefloat(Pchar.quest.store_charcoal));
	LogIt("store_nitre = " + makefloat(Pchar.quest.store_nitre));
	LogIt("store_sulfur = " + makefloat(Pchar.quest.store_sulfur));
	//LogIt("store_TOTAL = " + makefloat(Pchar.quest.store_total));

	LogIt("mix_charcoal = " + makefloat(Pchar.quest.mix_charcoal));
	LogIt("mix_nitre = " + makefloat(Pchar.quest.mix_nitre));
	LogIt("mix_sulfur = " + makefloat(Pchar.quest.mix_sulfur));
	//LogIt("mix_TOTAL = " + makefloat(Pchar.quest.mix_total));

	LogIt("BB_TOTAL = " + makefloat(Pchar.quest.BB_total));

	LogIt("gp_charcoal = " + makefloat(Pchar.quest.gp_charcoal));
	LogIt("gp_nitre = " + makefloat(Pchar.quest.gp_nitre));
	LogIt("gp_sulfur = " + makefloat(Pchar.quest.gp_sulfur));
	LogIt("gp_total = " + makefloat(Pchar.quest.gp_total));

	LogIt("charcoal_risk = " + Pchar.quest.charcoal_risk);
	LogIt("sulfur_risk = " + Pchar.quest.sulfur_risk);
	LogIt("water_risk = " + Pchar.quest.water_risk);
	explosion_risk = makefloat(Pchar.quest.water_risk) + makefloat(Pchar.quest.charcoal_risk) + makefloat(Pchar.quest.sulfur_risk);
	LogIt("explosion_risk = " + explosion_risk);

	LogIt("gp_quality = " + Pchar.quest.gp_quality);
*/
			
			LAi_QuestDelay("Jup_with_ingredients", 2.0);
		break;
//..........................................................................................
		case "gp_mill_water_wheel":
			PlaySound("INTERFACE\running_water_short.wav");

			LAi_QuestDelay("gp_mill_water_wheel1", 1.5);
		break;

		case "gp_mill_water_wheel1":
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");

			LAi_QuestDelay("gp_mill_water_wheel2", 2.0);
			LAi_QuestDelay("gp_mill_water_wheel_message", 3.0);
		break;

		case "gp_mill_water_wheel2":
			Pchar.quest.water_tap_gp = "off";
			PlaySound("PEOPLE\step_stairway.wav");

			ChangeCharacterAddressGroup(Pchar, "GB_chinese_gunpowder", "goto", "box1");
		break;

		case "gp_mill_water_wheel_message":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Logit(TranslateString("","I have added Water to the Big Barrel."));
		break;
//----------------------------------------------------------------------------------------------------------------
		case "charcoal_push_log":
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box3", "charcoal_push_log1");
		break;

		case "charcoal_push_log1":
			PlaySound("PEOPLE\clothes1.wav");
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
		break;
//..........................................................................................
		case "charcoal_saw_log":
			PlaySound("PEOPLE\saw1.wav");

			LAi_QuestDelay("charcoal_saw_log1", 2.5);
		break;

		case "charcoal_saw_log1":
			Locations[FindLocation(Pchar.location)].models.always.l2 = "wood_short_floor";
			Locations[FindLocation(Pchar.location)].models.always.locators = "Hut_locators_charcoal3";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box4", "charcoal_saw_log2");
		break;

		case "charcoal_saw_log2":
			PlaySound("PEOPLE\wood1.wav");
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
			Pchar.quest.charcoal_box4 = "off";
		break;

		case "pick_up_wood_short_floor":
			Locations[FindLocation(Pchar.location)].models.always.l2 = "";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box4", "pick_up_wood_short_floor2");
		break;

		case "pick_up_wood_short_floor2":
			LAi_SetFightMode(pchar, false);
			LAi_SetPlayerType(Pchar);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
		break;
//..........................................................................................
		case "charcoal_place_short_logs":
			Locations[FindLocation(Pchar.location)].models.always.l2 = "wood_short_stump";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			Locations[FindLocation(Pchar.location)].models.always.locators = "Hut_locators_charcoal4";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box1", "charcoal_place_short_logs1");
		break;

		case "charcoal_place_short_logs1":
			PlaySound("PEOPLE\wood1.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladewood_short" );
			EquipCharacterByItem(Pchar, "bladeX4");
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
			Pchar.quest.charcoal_wood_short = "on_stump";
			Pchar.quest.charcoal_box1 = "off";
		break;
//..........................................................................................
		case "charcoal_cut_short_logs":
			Locations[FindLocation("GB_chinese_charcoal")].locators_radius.box.box7 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box7", 0.5);

			Locations[FindLocation(Pchar.location)].models.always.l2 = "wood4_stump";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			Locations[FindLocation(Pchar.location)].models.always.locators = "Hut_locators_charcoal5";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box7", "charcoal_cut_short_logs1");
		break;

		case "charcoal_cut_short_logs1":
			PlaySound("PEOPLE\axe_skull.wav");
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
			Pchar.quest.charcoal_wood_short = "no";
			Pchar.quest.charcoal_box1 = "off";
		break;

		case "pick_up_wood4_stump":
			Locations[FindLocation("GB_chinese_charcoal")].locators_radius.box.box2 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box2", 0.5);

			Locations[FindLocation(Pchar.location)].models.always.l2 = "";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box7", "pick_up_wood4_stump2");
		break;

		case "pick_up_wood4_stump2":
			LAi_SetFightMode(pchar, false);
			LAi_SetPlayerType(Pchar);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
		break;
//..........................................................................................
		case "charcoal_place_wood4":
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			locations[FindLocation("GB_chinese_charcoal")].models.always.l1 = "wood4";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box2", "charcoal_place_wood4_1");
		break;

		case "charcoal_place_wood4_1":
			PlaySound("PEOPLE\wood1.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladewood4" );
			EquipCharacterByItem(Pchar, "bladeX4");
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
			Pchar.quest.charcoal_box2 = "off";
		break;
//..........................................................................................
		case "end_of_tinderbox_charcoal":
			//from LAi_events
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box2", "end_of_tinderbox_charcoal1");
		break;

		case "end_of_tinderbox_charcoal1":
			Pchar.quest.charcoal_tinderbox = "disabled";
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";

			LAi_QuestDelay("charcoal_fire_sound", 0.1);
			LAi_QuestDelay("end_of_tinderbox_charcoal2", 1.0);
		break;

		case "end_of_tinderbox_charcoal2":
			Logit(TranslateString("","This will take time - I'll do something else meanwhile."));
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.charcoal_box2 = "off";

			Pchar.quest.charcoal_glowing_fire.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.charcoal_glowing_fire.win_condition.l1.location = "GB_chinese_charcoal";
			Pchar.quest.charcoal_glowing_fire.win_condition = "charcoal_glowing_fire";
		break;

		case "charcoal_glowing_fire":
			locations[FindLocation("GB_chinese_charcoal")].models.always.l1 = "wood3";

			pchar.quest.charcoal_glowing.win_condition.l1 = "location";
			pchar.quest.charcoal_glowing.win_condition.l1.location = "GB_chinese_charcoal";
			pchar.quest.charcoal_glowing.win_condition = "charcoal_glowing";
		break;

		case "charcoal_glowing":
			LAi_QuestDelay("charcoal_fire_sound", 0.1);
			Pchar.quest.charcoal_glowing1.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.charcoal_glowing1.win_condition.l1.location = "GB_chinese_charcoal";
			Pchar.quest.charcoal_glowing1.win_condition = "charcoal_glowing1";
		break;

		case "charcoal_glowing1":
			Locations[FindLocation("GB_chinese_charcoal")].models.always.locators = "Hut_locators_charcoal7";

			pchar.quest.charcoal_ready.win_condition.l1 = "location";
			pchar.quest.charcoal_ready.win_condition.l1.location = "GB_chinese_charcoal";
			pchar.quest.charcoal_ready.win_condition = "charcoal_ready";
		break;

		case "charcoal_ready":
			Pchar.quest.charcoal_ready1.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.charcoal_ready1.win_condition.l1.location = "GB_chinese_charcoal";
			Pchar.quest.charcoal_ready1.win_condition = "charcoal_ready1";
		break;

		case "charcoal_ready1":
			locations[FindLocation("GB_chinese_charcoal")].models.always.l1 = "wood5";
		break;
//..........................................................................................
		case "charcoal_fire_sound":
			if(Pchar.location == "GB_chinese_charcoal")
			{
				if(Locations[FindLocation("GB_chinese_charcoal")].models.always.locators == "Hut_locators_charcoal6")
				{
					PlaySound3D("NATURE\fireplace2.wav", -1.2, 0.77, 2.6);
					LAi_QuestDelay("charcoal_fire_sound", 5.0);
				}
				else return;
			}
			else return;
		break;
//..........................................................................................
		case "charcoal_pick_up":
			PlaySound("PEOPLE\dig_sand.wav");
			CreateParticleSystemX("blast_dirt_black", -1.2, 0.8, 2.4, -1.2, 0.8, 2.4,10);

			LAi_QuestDelay("charcoal_pick_up0", 1.0);
		break;

		case "charcoal_pick_up0":
			PlaySound("PEOPLE\dig_sand.wav");

			LAi_QuestDelay("charcoal_pick_up1", 1.0);
		break;

		case "charcoal_pick_up1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolcharcoal_E" );
			GiveItem2Character(Pchar, "pistolcharcoal_H");	
			EquipCharacterByItem(Pchar, "pistolcharcoal_H");

			LAi_QuestDelay("charcoal_pick_up2", 1.0);
		break;

		case "charcoal_pick_up2":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","The Jar is only half filled with Charcoal."));
			Pchar.quest.charcoal_box2 = "off";
		break;
//..........................................................................................
		case "charcoal_pick_up_again":
			PlaySound("PEOPLE\dig_sand.wav");
			CreateParticleSystemX("blast_dirt_black", -1.2, 0.8, 2.4, -1.2, 0.8, 2.4,10);

			LAi_QuestDelay("charcoal_pick_up_again0", 1.0);
		break;

		case "charcoal_pick_up_again0":
			PlaySound("PEOPLE\dig_sand.wav");

			LAi_QuestDelay("charcoal_pick_up_again1", 1.0);
		break;

		case "charcoal_pick_up_again1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], true);
			LAi_SetPlayerType(Pchar);
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolcharcoal_H" );
			GiveItem2Character(Pchar, "pistolcharcoal_F");	
			EquipCharacterByItem(Pchar, "pistolcharcoal_F");
			
			LAi_QuestDelay("charcoal_pick_up_again2", 1.0);
		break;

		case "charcoal_pick_up_again2":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			LAi_QuestDelay("charcoal_pick_up_again3", 1.0);
		break;

		case "charcoal_pick_up_again3":
			Locations[FindLocation("GB_chinese_charcoal")].models.always.locators = "Hut_locators_charcoal1";
			locations[FindLocation("GB_chinese_charcoal")].models.always.l1 = "";
			Locations[FindLocation("GB_chinese_charcoal")].image = "";
			DoQuestReloadToLocation("GB_chinese_charcoal", "goto", "box2", "charcoal_pick_up_again4");
		break;

		case "charcoal_pick_up_again4":
			Locations[FindLocation("GB_chinese_charcoal")].image = "GB_charcoal.tga";
			//PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Pchar.quest.charcoal_box2 = "off";

			if(CheckAttribute(Pchar,"quest.charcoal_done") && Pchar.quest.charcoal_done == "yes")
			{
		
			}
			else
			{
				Pchar.quest.charcoal_done = "yes";
				AddQuestRecord("Charcoal", "1");
				CloseQuestHeader("Charcoal");
			}
		break;	
//..........................................................................................
		case "nitre_fireplace":
			if(CheckCharacterItem(Pchar,"bladewood2"))
			{
				LAi_SetPlayerType(Pchar);
				LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], false);
				LAi_SetFightMode(pchar, true);
			
				LAi_QuestDelay("nitre_fireplace3", 1.0);
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.nitre_wood") && Pchar.quest.nitre_wood == "placed")	
				{
					PlaySound("NATURE\fireplace1.wav");
					PlaySound("NATURE\fireplace1.wav");
					PlaySound("NATURE\fireplace1.wav");
					PlaySound("NATURE\fireplace1.wav");
					Logit(TranslateString("","I have already placed wood in here."));
				}
				else
				{
					Logit(TranslateString("","The fire has almost gone out - I need more wood."));
					PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				}

				LAi_QuestDelay("nitre_fireplace1", 2.0);
			} 
		break;

		case "nitre_fireplace1":
			PlaySound("INTERFACE\metal_hatch_close.wav");

			LAi_QuestDelay("nitre_fireplace2", 1.0);
		break;

		case "nitre_fireplace2":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.nitre_fireplace = "off";
		break;

		case "nitre_fireplace3":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], true);
			LAi_SetStayType(Pchar);
			PlaySound("PEOPLE\wood1.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladewood2" );
			EquipCharacterByItem(Pchar, "bladeX4");
			Pchar.quest.nitre_wood = "placed";

			LAi_QuestDelay("nitre_fireplace1", 1.0);

			if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "full")	
			{
				LAi_QuestDelay("nitre_boiling_low", 3.0);	//was 4
				LAi_QuestDelay("nitre_exit_low", 4.0);
			}
			else LAi_QuestDelay("nitre_burning_only", 4.0);
		break;
//..........................................................................................
		case "nitre_burning_only":
			if(CheckAttribute(Pchar, "quest.tub3_content") && Pchar.quest.tub3_content == "nitre")
			{
				LAi_QuestDelay("nitre_wood_finished", 0.1);
				return;
			}
			else
			{
				//Log_SetStringToLog("Burning");
				Pchar.quest.nitre_boiling = "burning";
				CreateParticleSystem("smoke" , 0.1, 6.3, 2.7, 4.5, 1.5, 0.0, sti(20) );
				
				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "full")	
				{
					LAi_QuestDelay("nitre_boiling_low", 0.5);	//was 4
					LAi_QuestDelay("nitre_exit_low", 4.0);
				}
				else LAi_QuestDelay("nitre_burning_only", 5.0);		
			}	
		break;

		case "nitre_boiling_low":
		//	LAi_QuestDelay("nitre_exit_low", 4.0);	//moved up to 2 places

			if(CheckAttribute(Pchar,"quest.nitre_boiling_low") && Pchar.quest.nitre_boiling_low == "First_time")	
			{
				Pchar.quest.nitre_boiling_low = "Second_time";
				LAi_SetStayType(Pchar);

				LAi_QuestDelay("nitre_exit_low_qbook", 4.0);
			}

			if(Pchar.location == "GB_chinese_nitre")
			{
				//Log_SetStringToLog("Low");
				Pchar.quest.nitre_boiling = "low";
				CreateParticleSystem("smoke" , 0.1, 6.3, 2.7, 4.5, 1.5, 0.0, sti(20) );
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);

				

				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "overfull")	
				{
					return;
				}

				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "full")	
				{
					LAi_QuestDelay("nitre_boiling_low", 5.0);
				}
				else LAi_QuestDelay("nitre_burning_only", 5.0);			
			}
			else
			{
				pchar.quest.nitre_boiling_medium.win_condition.l1 = "locator";
				pchar.quest.nitre_boiling_medium.win_condition.l1.location = "GB_chinese_nitre";
				pchar.quest.nitre_boiling_medium.win_condition.l1.locator_group = "goto";
				pchar.quest.nitre_boiling_medium.win_condition.l1.locator = "box6";
				pchar.quest.nitre_boiling_medium.win_condition = "nitre_boiling_medium";
			}
		break;
	
		case "nitre_boiling_medium":
			if(Pchar.location == "GB_chinese_nitre")
			{
				//Log_SetStringToLog("Medium");
				Pchar.quest.nitre_boiling = "medium";
				CreateParticleSystem("smoke" , 0.1, 6.3, 2.7, 4.5, 1.5, 0.0, sti(20) );
				CreateParticleSystem("waterfog_short" , 1.7, 2.9, 1.4, -27.8, 3.6, 16.3, sti(20) );
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\rumble1.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\bubbles2.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\bubbles2.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\bubbles2.wav", 1.3, 1.0, -0.7);
				PlaySound3D("INTERFACE\bubbles2.wav", 1.3, 1.0, -0.7);

				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "overfull")	
				{
					return;
				}

				if(CheckAttribute(Pchar,"quest.tub1_level") && Pchar.quest.tub1_level == "full")	
				{
					LAi_QuestDelay("nitre_boiling_medium", 5.0);
				}
				else LAi_QuestDelay("nitre_burning_only", 5.0);			
			}
			else
			{
				pchar.quest.nitre_wood_finished.win_condition.l1 = "locator";
				pchar.quest.nitre_wood_finished.win_condition.l1.location = "GB_chinese_nitre";
				pchar.quest.nitre_wood_finished.win_condition.l1.locator_group = "goto";
				pchar.quest.nitre_wood_finished.win_condition.l1.locator = "box6";
				pchar.quest.nitre_wood_finished.win_condition = "nitre_wood_finished";
			}
		break;
	
		case "nitre_wood_finished":
			Pchar.quest.nitre_boiling = "none";
			Pchar.quest.nitre_wood = "none";
		break;

		case "nitre_fire_extinct":
			Pchar.quest.nitre_boiling = "none";
			Pchar.quest.nitre_wood = "none";

			PlaySound("INTERFACE\fire_off.wav");
			CreateParticleSystem("smoke_inv_short" , 1.5, 1.7, -0.7, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystemX("ball_splash", 3.0, 3.5, -1.4, 0.0, 0.0, 0.0, 0);
			CreateParticleSystemX("ball_splash", 5.9, 3.5, -0.5, 0.0, 0.0, 0.0, 0);

			LAi_QuestDelay("nitre_fire_extinct1", 6.0);
			LAi_QuestDelay("nitre_fire_blacksmoke", 4.0);
			LAi_QuestDelay("nitre_pchar_notice_blacksmoke", 4.0);
		break;

		case "nitre_fire_extinct1":
			Pchar.quest.tub1_level = "full";
		break;

		case "nitre_fire_blacksmoke":
			CreateParticleSystem("smoke_inv_short" , 1.5, 1.7, -0.7, 5.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("nitre_fire_blacksmoke1", 4.0);
		break;

		case "nitre_fire_blacksmoke1":
			CreateParticleSystem("smoke_inv_short" , 1.5, 1.7, -0.7, 5.1, 4.0, 0.0, sti(20) );
		break;

		case "nitre_pchar_notice_blacksmoke":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem9");

			LAi_QuestDelay("nitre_pchar_notice_blacksmoke1", 1.5);
		break;

		case "nitre_pchar_notice_blacksmoke1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			LAi_SetPlayerType(Pchar);
		break;
//..........................................................................................
		case "nitre_lever0_up":
			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box10", "reset_nitre_loading");
		break;

		case "nitre_lever0_down":
			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box10", "nitre_levers_dripping_sound");
		break;

		case "nitre_lever1_up":
			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box4", "reset_nitre_loading");
		break;

		case "nitre_lever1_down":
			Locations[FindLocation("GB_chinese_nitre")].image = "";

			if(CheckAttribute(Pchar,"quest.nitre_boiling") && Pchar.quest.nitre_boiling == "medium")	
			{
				if(CheckAttribute(Pchar,"quest.nitre_lever2") && Pchar.quest.nitre_lever2 == "up")	
				{
					Log_SetStringToLog("2222");
					Pchar.quest.tub2_level = "full";
					Pchar.quest.tub2_content = "dirt";
					
					if(CheckAttribute(Pchar,"quest.tub3_content"))
					{
			    			switch(Pchar.quest.tub3_content)
			    			{
							case "water":
								Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_DW";
							break;

							case "dirt":
								Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_DD";
							break;

							case "nitre":
								Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_DN";
							break;
			    			}
					}

					DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box4", "nitre_levers_water_sound_and_fog2");
				}
				else
				{
					//both open no one becomes full, both clean water
					Log_SetStringToLog("3333");
					Pchar.quest.tub2_content = "water";
					Pchar.quest.tub3_content = "water";
					Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";

					DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box4", "nitre_levers_water_sound_and_fog3");
				}

				Pchar.quest.tub1_level = "half";
			}
			else
			{
				if(CheckAttribute(Pchar, "quest.tub1_level") && Pchar.quest.tub1_level == "full")
				{
					Log_SetStringToLog("4444");
					if(CheckAttribute(Pchar,"quest.nitre_lever2") && Pchar.quest.nitre_lever2 == "up")	
					{
						Pchar.quest.tub2_level = "full";
						Pchar.quest.tub2_content = "water";

						if(CheckAttribute(Pchar,"quest.tub3_content"))
						{
			    				switch(Pchar.quest.tub3_content)
			    				{
								case "water":
									Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";
								break;

								case "dirt":
									Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WD";
								break;

								case "nitre":
									Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WN";
								break;
			    				}
						}
					}
					else
					{
						//direct from tub1 to tub3, no one becomes full, both clean water
						Pchar.quest.tub2_content = "water";
						Pchar.quest.tub3_content = "water";

						Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";
					}
					
					Pchar.quest.tub1_level = "half";

					DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box4", "nitre_levers_water_sound");
				}

			}
			else 
			{
				Log_SetStringToLog("5555");	
				DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box4", "reset_nitre_loading");
			}
		break;

		case "nitre_lever2_up":
			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box8", "reset_nitre_loading");
		break;

		case "nitre_lever2_down":
			Locations[FindLocation("GB_chinese_nitre")].image = "";

			if(CheckAttribute(Pchar, "quest.tub2_level") && Pchar.quest.tub2_level == "full")
			{
				Pchar.quest.tub2_level = "half";

				if(CheckAttribute(Pchar,"quest.tub2_content"))
				{
			    		switch(Pchar.quest.tub2_content)
			    		{
						case "water":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WW";
							Pchar.quest.tub3_content = "water";
						break;

						case "dirt":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WD";
							Pchar.quest.tub3_content = "dirt";
						break;

						case "nitre":
							Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WN";
							Pchar.quest.tub3_content = "nitre";
						break;
			    		}
				}

				Pchar.quest.tub2_content = "water";

				DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box8", "nitre_levers_water_sound");
			}
			else DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box8", "reset_nitre_loading");
		break;

		case "nitre_levers_water_sound_and_fog2":
			CreateParticleSystem("waterfog" , 1.5, 1.0, -4.2, -27.8, 3.6, 16.3, sti(20) );
			PlaySound("NATURE\water_in.wav");
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";

			if(CheckAttribute(Pchar,"quest.nitre_dirt_tub2") && Pchar.quest.nitre_dirt_tub2 == "First_time")	
			{
				Pchar.quest.dirt_tub2 = "Second_time";
				LAi_SetStayType(Pchar);

				LAi_QuestDelay("pchar_notice_dirt", 2.0);
			}

			Pchar.quest.nitre_tub2.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.nitre_tub2.win_condition.l1.location = "GB_chinese_nitre";
			Pchar.quest.nitre_tub2.win_condition = "nitre_tub2";
		break;

		case "pchar_notice_dirt":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");

			LAi_QuestDelay("nitre_exit_dirt", 6.0);
		break;

		case "nitre_tub2":
			Pchar.quest.tub2_content = "nitre";

			if(CheckAttribute(Pchar,"quest.tub3_content"))
			{
			    	switch(Pchar.quest.tub3_content)
			    	{
					case "water":
						Locations[FindLocation("GB_chinese_nitre")].models.always.locators = "warehouse_l_nitre_NW";
					break;

					case "dirt":
						Locations[FindLocation("GB_chinese_nitre")].models.always.locators = "warehouse_l_nitre_ND";
					break;

					case "nitre":
						Locations[FindLocation("GB_chinese_nitre")].models.always.locators = "warehouse_l_nitre_NN";
					break;
			    	}
			}
		break;

		case "nitre_levers_water_sound_and_fog3":
			CreateParticleSystem("waterfog" , 5.2, 0.4, -3.7, -27.8, 3.6, 16.3, sti(20) );
			PlaySound("NATURE\water_in.wav");
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";
		break;

		case "nitre_levers_water_sound":
			PlaySound("NATURE\water_in.wav");
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";
		break;

		case "reset_nitre_loading":
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";
		break;

		case "nitre_levers_dripping_sound":
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			PlaySound("AMBIENT\CAVE\drop4.wav");
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";

			if(CheckAttribute(Pchar,"quest.nitre_drops") && Pchar.quest.nitre_drops == "first_time")
			{
				Pchar.quest.nitre_drops = "second_time";

				LAi_QuestDelay("pchar_hah", 2.0);
			}
		break;
//..........................................................................................
		case "nitre_fill_bucket":
			Pchar.quest.tub3_content = "dirt";

			if(CheckAttribute(Pchar,"quest.tub2_content"))
			{
			    	switch(Pchar.quest.tub2_content)
			    	{
					case "water":
						Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_WD";
					break;

					case "dirt":
						Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_DD";
					break;

					case "nitre":
						Locations[FindLocation(Pchar.location)].models.always.locators = "warehouse_l_nitre_ND";
					break;
			    	}
			}

			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "tub3", "nitre_fill_bucket1");
		break;

		case "nitre_fill_bucket1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";
		
			LAi_QuestDelay("nitre_fill_bucket2", 1.0);
		break;
		
		case "nitre_fill_bucket2":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");

		break;
//..........................................................................................
		case "nitre_empty_bucket":
			locations[FindLocation(Pchar.location)].models.always.l5 = "roll_of_planks5";//wet nitre planks

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box3", 2.0);
			Locations[FindLocation("GB_chinese_nitre")].locators_radius.box.box3 = 2.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 0.001);
			Locations[FindLocation("GB_chinese_nitre")].locators_radius.box.box9 = 0.001;

			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box9", "nitre_empty_bucket1");
		break;

		case "nitre_empty_bucket1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], true);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";
		
			LAi_QuestDelay("nitre_empty_bucket2", 1.0);
		break;

		case "nitre_empty_bucket2":
			if(CheckAttribute(Pchar,"quest.nitre_white_planks") && Pchar.quest.nitre_white_planks == "First_time")	
			{
				Pchar.quest.nitre_white_planks = "Second_time";

				LAi_QuestDelay("nitre_exit_dry", 1.0);
			}

			Pchar.quest.nitre_white_planks.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.nitre_white_planks.win_condition.l1.location = "GB_chinese_nitre";
			Pchar.quest.nitre_white_planks.win_condition = "nitre_white_planks";
		break;

		case "nitre_white_planks":
			locations[FindLocation("GB_chinese_nitre")].models.always.l5 = "roll_of_planks4";//dry nitre planks
		break;
//..........................................................................................
		case "nitre_scrape_salpeter":
			PlaySound("PEOPLE\scrape.wav");

			LAi_QuestDelay("nitre_scrape_salpeter1", 1.5);
		break;

		case "nitre_scrape_salpeter1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], true);
			LAi_SetPlayerType(Pchar);
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolnitre_E" );
			GiveItem2Character(Pchar, "pistolnitre_H");	
			EquipCharacterByItem(Pchar, "pistolnitre_H");

			LAi_QuestDelay("nitre_scrape_salpeter2", 1.0);
		break;

		case "nitre_scrape_salpeter2":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","The Sack is only half filled with Nitre."));
		break;
//..........................................................................................
		case "nitre_scrape_salpeter_again":
			PlaySound("PEOPLE\scrape.wav");

			LAi_QuestDelay("nitre_scrape_salpeter_again1", 1.5);
		break;

		case "nitre_scrape_salpeter_again1":
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 2.0);
			Locations[FindLocation("GB_chinese_nitre")].locators_radius.box.box9 = 2.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box3", 0.001);
			Locations[FindLocation("GB_chinese_nitre")].locators_radius.box.box3 = 0.001;

			locations[FindLocation(Pchar.location)].models.always.l5 = "roll_of_planks3";//clean planks

			Locations[FindLocation("GB_chinese_nitre")].image = "";
			DoQuestReloadToLocation("GB_chinese_nitre", "goto", "box9", "nitre_scrape_salpeter_again2");
		break;

		case "nitre_scrape_salpeter_again2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], true);
			LAi_SetPlayerType(Pchar);
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolnitre_H" );
			GiveItem2Character(Pchar, "pistolnitre_big_F");	
			EquipCharacterByItem(Pchar, "pistolnitre_big_F");
			Locations[FindLocation("GB_chinese_nitre")].image = "GB_salpeter.tga";

			LAi_QuestDelay("nitre_scrape_salpeter_again3", 1.0);
		break;

		case "nitre_scrape_salpeter_again3":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			if(CheckAttribute(Pchar,"quest.nitre_done") && Pchar.quest.nitre_done == "yes")
			{
				
			}
			else
			{
				Pchar.quest.nitre_done = "yes";
				AddQuestRecord("Salpeter", "1");
				CloseQuestHeader("Salpeter");
			}
		break;
//..........................................................................................
		case "nitre_exit_low":
			Logit(TranslateString("","It's going to take time to get all that water boiling - I'll do something else meanwhile."));
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			LAi_SetPlayerType(Pchar);
		break;

		case "nitre_exit_low_qbook":
			AddQuestRecord("Salpeter", "2");
		break;

		case "nitre_exit_dirt":
			Logit(TranslateString("","It's going to take time to solve all Salpeter - I'll do something else meanwhile."));
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("Salpeter", "3");
			LAi_SetPlayerType(Pchar);
		break;

		case "nitre_exit_dry":
			Logit(TranslateString("","It's going to take time to dry the Salpeter on the planks - I'll do something else meanwhile."));
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("Salpeter", "4");
			LAi_SetPlayerType(Pchar);
		break;
//..........................................................................................
		case "pyrite_dust_pick_up":
			PlaySound("PEOPLE\grass_noise.wav");
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);

			LAi_QuestDelay("pyrite_dust_pick_up0", 1.0);
		break;

		case "pyrite_dust_pick_up0":
			PlaySound("PEOPLE\grass_noise.wav");

			LAi_QuestDelay("pyrite_dust_pick_up1", 1.0);
		break;

		case "pyrite_dust_pick_up1":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			LAi_SetPlayerType(Pchar);
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolpyrite_E" );
			GiveItem2Character(Pchar, "pistolpyrite_H");	
			EquipCharacterByItem(Pchar, "pistolpyrite_H");

			LAi_QuestDelay("pyrite_dust_pick_up2", 1.0);
		break;

		case "pyrite_dust_pick_up2":
			Logit(TranslateString("","The Box is only half filled with Pyrite Dust."));
			Pchar.quest.sulfur_box1 = "off";
			Pchar.quest.sulfur_box6 = "off";
		break;
//..........................................................................................
		case "pyrite_dust_pick_up_again":
			PlaySound("PEOPLE\grass_noise.wav");
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);

			LAi_QuestDelay("pyrite_dust_pick_up_again0", 1.0);
		break;

		case "pyrite_dust_pick_up_again0":
			PlaySound("PEOPLE\grass_noise.wav");

			LAi_QuestDelay("pyrite_dust_pick_up_again2", 1.0);
		break;
	
		case "pyrite_dust_pick_up_again2":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolpyrite_H" );
			GiveItem2Character(Pchar, "pistolpyrite_F");	
			EquipCharacterByItem(Pchar, "pistolpyrite_F");

			Locations[FindLocation("GB_chinese_sulphur")].models.always.l2 = "wood_floor";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "dust", "pyrite_dust_pick_up_again3");
		break;

		case "pyrite_dust_pick_up_again3":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			Pchar.quest.pyrite_stones = "no";
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";
	
			LAi_QuestDelay("pyrite_dust_pick_up_again4", 1.0);
		break;	

		case "pyrite_dust_pick_up_again4":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
	
			Pchar.quest.sulfur_box1 = "off";
			Pchar.quest.sulfur_box6 = "off";
		break;	
//..........................................................................................
		case "pyrite_stones_smashed":
			PlaySound("PEOPLE\axe_skull.wav");
			PlaySound("PEOPLE\jump.wav");
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);

			LAi_QuestDelay("pyrite_stones_smashed0", 1.5);
		break;

		case "pyrite_stones_smashed0":
			PlaySound("PEOPLE\axe_skull.wav");
			PlaySound("PEOPLE\jump.wav");

			LAi_QuestDelay("pyrite_stones_smashed1", 1.5);
		break;

		case "pyrite_stones_smashed1":
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l2 = "wood_sulph";
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l4 = "";
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l5 = "pyrite_stones1";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "dust", "pyrite_stones_smashed2");
		break;

		case "pyrite_stones_smashed2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			LAi_SetPlayerType(Pchar);			
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";

			LAi_QuestDelay("pyrite_stones_smashed3", 1.0);
		break;

		case "pyrite_stones_smashed3":
			Logit(TranslateString("","There are still some stones left."));
			Pchar.quest.pyrite_stones = "few";
			Pchar.quest.sulfur_box1 = "off";
			Pchar.quest.sulfur_box6 = "off";
		break;
//..........................................................................................
		case "pyrite_stones_smashed_again":
			PlaySound("PEOPLE\axe_skull.wav");
			PlaySound("PEOPLE\jump.wav");
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);

			LAi_QuestDelay("pyrite_stones_smashed_again1", 1.5);
		break;
	
		case "pyrite_stones_smashed_again1":
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l4 = "";
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l5 = "";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "dust", "pyrite_stones_smashed_again2");
		break;

		case "pyrite_stones_smashed_again2":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			LAi_SetPlayerType(Pchar);			
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";

			LAi_QuestDelay("pyrite_stones_smashed_again3", 1.0);
		break;

		case "pyrite_stones_smashed_again3":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Pchar.quest.pyrite_stones = "dust";
			Logit(TranslateString("","Now it's just to collect the Pyrite Dust."));
			Pchar.quest.sulfur_box1 = "off";
			Pchar.quest.sulfur_box6 = "off";
		break;
//..........................................................................................
		case "sulfur_empty_bucket":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			LAi_SetPlayerType(Pchar);
			
			LAi_QuestDelay("sulfur_empty_bucket1", 2.0);
		break;

		case "sulfur_empty_bucket1":
			LAi_SetSitType(Pchar);
			PlaySound("PEOPLE\step_echo1.wav");
			PlaySound("PEOPLE\jump_stone.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "box3");

			LAi_QuestDelay("sulfur_empty_bucket2", 0.5);
		break;

		case "sulfur_empty_bucket2":
			LAi_SetPlayerType(Pchar);

			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{
				Pchar.quest.sulfur_boiling = "on";

				LAi_QuestDelay("sulfur_boiling_only", 1.0);
				LAi_QuestDelay("sulfur_boiling_only_message", 3.0);
			}

			LAi_QuestDelay("sulfur_distillery_check", 0.1);
		break;
//..........................................................................................
		case "sulfur_empty_box":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "box7");
			LAi_SetPlayerType(Pchar);

			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{
				Pchar.quest.sulfur_dust = "on";

				LAi_QuestDelay("sulfur_dust_only", 1.0);
				LAi_QuestDelay("sulfur_dust_only_message", 3.0);
			}

			LAi_QuestDelay("sulfur_distillery_check", 0.1);
		break;
//..........................................................................................
		case "sulfur_fill_sulfur":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "box7");
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","The Basket is only half filled with Sulphur."));
		break;

		case "sulfur_fill_sulfur_again":
			LAi_SetFightMode(pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], true);
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_sulphur", "goto", "box7");
			LAi_SetPlayerType(Pchar);

			if(CheckAttribute(Pchar,"quest.sulfur_done") && Pchar.quest.sulfur_done == "yes")
			{
				
			}
			else
			{
				Pchar.quest.sulfur_done = "yes";
				AddQuestRecord("Sulfur", "1");
				CloseQuestHeader("Sulfur");
			}
		break;
//..........................................................................................
		case "sulfur_lever_up":
			locations[FindLocation("GB_chinese_sulphur")].models.always.locators = "TRI_l_sulphur_closed";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "box8", "sulfur_hatch_close");
		break;

		case "sulfur_lever_down":
			locations[FindLocation("GB_chinese_sulphur")].models.always.locators = "TRI_l_sulphur_open";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "box8", "sulfur_hatch_open");
		break;

		case "sulfur_hatch_close":
			PlaySound("PEOPLE\counter_close.wav");
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";
		break;

		case "sulfur_hatch_open":
			PlaySound("INTERFACE\closet_open.wav");
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";
		break;
//..........................................................................................
		case "sulfur_pull_rope":
			LAi_SetStayType(Pchar);

			Locations[FindLocation("GB_chinese_sulphur")].models.always.l5 = "pyrite_stones1";
			Locations[FindLocation("GB_chinese_sulphur")].models.always.l4 = "pyrite_stones2";
			Locations[FindLocation("GB_chinese_sulphur")].image = "";
			DoQuestReloadToLocation("GB_chinese_sulphur", "goto", "box9", "sulfur_pull_rope1");
		break;

		case "sulfur_pull_rope1":
			LAi_SetStayType(Pchar);
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);
			CreateParticleSystemX("blast_dirt", 0.4, 0.2, 6.4, 0.4, 0.2, 6.4, 10);
			PlaySound("PEOPLE\cavern1.wav");
			PlaySound("PEOPLE\cavern1.wav");
			Locations[FindLocation("GB_chinese_sulphur")].image = "GB_sulfur.tga";
		
			LAi_QuestDelay("sulfur_pull_rope2", 1.0);
		break;

		case "sulfur_pull_rope2":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.sulfur_rope = "off";
			Pchar.quest.pyrite_stones = "many";
		break;
//..........................................................................................
		case "sulfur_distillery_check":
			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{
				if(CheckAttribute(Pchar, "quest.sulfur_water") && Pchar.quest.sulfur_water == "filled")
				{
					if(CheckAttribute(Pchar, "quest.sulfur_pyrite") && Pchar.quest.sulfur_pyrite == "filled")
					{
						//all 3 old loops stopped
						Pchar.quest.sulfur_fire = "off";
						Pchar.quest.sulfur_boiling = "off";
						Pchar.quest.sulfur_dust = "off";

						Pchar.quest.sulfur_distill = "on";

						LAi_QuestDelay("sulfur_distill_only", 0.1);
						LAi_QuestDelay("yes_sulfur_distill_is_on", 0.1);
					}
				}
			}
		break;
//..........................................................................................
		case "sulfur_burning_only":
			if(CheckAttribute(Pchar,"quest.sulfur_fire") && Pchar.quest.sulfur_fire == "on")
			{	
				//CreateParticleSystem("smoke" , -0.8, 4.3, 0.0, 4.5, 1.5, 0.0, sti(20) );
				CreateParticleSystem("smoke_inv" , -0.8, 4.3, 0.0, 4.5, 1.5, 0.0, sti(20) );
				PlaySound("NATURE\fireplace2.wav");
				
				LAi_QuestDelay("sulfur_burning_only", 4.0);

				Pchar.quest.stop_sulfur_fire.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.stop_sulfur_fire.win_condition.l1.location = "GB_chinese_sulphur";
				Pchar.quest.stop_sulfur_fire.win_condition = "stop_sulfur_fire";
			}		
			else return;	
		break;

		case "stop_sulfur_fire":
			if(CheckAttribute(Pchar,"quest.sulfur_distillery") && Pchar.quest.sulfur_distillery == "enabled")
			{
				Pchar.quest.sulfur_fire = "off";
			}
		break;
//..........................................................................................
		case "sulfur_boiling_only_message":
			if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
			{
				return;
			}
			else
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
				Logit(TranslateString("","No no no, I forgot to add Sulfur Dust!"));
			}
		break;

		case "sulfur_boiling_only":
			if(CheckAttribute(Pchar,"quest.sulfur_boiling") && Pchar.quest.sulfur_boiling == "on")
			{
				PlaySound("INTERFACE\steam1.wav");
				PlaySound("INTERFACE\steam1.wav");
				CreateParticleSystem("waterfog_short" , 0.0, 2.6, 0.0, 0.0, 3.6, 0.0, sti(20) );

				LAi_QuestDelay("sulfur_boiling_only", 4.0);

				Pchar.quest.stop_sulfur_boiling.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.stop_sulfur_boiling.win_condition.l1.location = "GB_chinese_sulphur";
				Pchar.quest.stop_sulfur_boiling.win_condition = "stop_sulfur_boiling";
			}
			else return;	
		break;

		case "stop_sulfur_boiling":
			if(CheckAttribute(Pchar,"quest.sulfur_distillery") && Pchar.quest.sulfur_distillery == "enabled")
			{
				Pchar.quest.sulfur_water = "empty";
				Pchar.quest.sulfur_boiling = "off";
			}
		break;
//..........................................................................................
		case "sulfur_dust_only_message":
			if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
			{
				return;
			}
			else
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
				Logit(TranslateString("","No no no, I forgot to add Water!"));
			}
		break;

		case "sulfur_dust_only":
			if(CheckAttribute(Pchar,"quest.sulfur_dust") && Pchar.quest.sulfur_dust == "on")
			{
				PlaySound("INTERFACE\rumble3.wav");
				CreateParticleSystem("blast_dirt" , 0.0, 2.6, 0.0, 0.0, 3.6, 0.0, sti(20) );
				CreateParticleSystem("blast_dirt" , 0.0, 2.6, 0.0, 0.0, 3.6, 0.0, sti(20) );

				LAi_QuestDelay("extra_pyrite_dust", 2.0);
				LAi_QuestDelay("sulfur_dust_only", 4.0);

				Pchar.quest.stop_sulfur_dust.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.stop_sulfur_dust.win_condition.l1.location = "GB_chinese_sulphur";
				Pchar.quest.stop_sulfur_dust.win_condition = "stop_sulfur_dust";
			}
			else return;	
		break;

		case "extra_pyrite_dust":
			CreateParticleSystem("blast_dirt" , 0.0, 2.6, 0.0, 0.0, 3.6, 0.0, sti(20) );
		break;

		case "stop_sulfur_dust":
			if(CheckAttribute(Pchar,"quest.sulfur_distillery") && Pchar.quest.sulfur_distillery == "enabled")
			{
				Pchar.quest.sulfur_pyrite = "empty";
				Pchar.quest.sulfur_dust = "off";
			}
		break;
//..........................................................................................
		case "sulfur_distill_only":
			if(CheckAttribute(Pchar,"quest.sulfur_distill") && Pchar.quest.sulfur_distill == "on")
			{
				CreateParticleSystem("smoke_inv" , -0.8, 4.3, 0.0, 4.5, 1.5, 0.0, sti(20) );
				PlaySound("NATURE\fireplace2.wav");
				PlaySound("INTERFACE\boiling_low.wav");

				LAi_QuestDelay("sulfur_distill_only", 4.0);

				Pchar.quest.stop_sulfur_distill.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.stop_sulfur_distill.win_condition.l1.location = "GB_chinese_sulphur";
				Pchar.quest.stop_sulfur_distill.win_condition = "stop_sulfur_distill";
			}
			else return;	
		break;

		case "stop_sulfur_distill":
			if(CheckAttribute(Pchar,"quest.sulfur_distillery") && Pchar.quest.sulfur_distillery == "enabled")
			{
				Pchar.quest.sulfur_water = "empty";
				//Pchar.quest.sulfur_pyrite = "empty";
				Pchar.quest.sulfur_pyrite = "sulfur";	//YES
				Pchar.quest.sulfur_distill = "off";
			}
		break;

		case "yes_sulfur_distill_is_on":
			Logit(TranslateString("","It's going to take time to distill the Sulphur - I'll do something else meanwhile."));
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("Sulfur", "2");
			LAi_SetPlayerType(Pchar);
		break;
//-----------------------------------------------------------------------------------------------------------------------------
//story continues here: Chinatown start
		case "GP_standard":
			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinese_restaurant", "officers", "reload2_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "we_do_the_job":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "we_do_the_job";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "GP_standard_3":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_3";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "we_do_the_job_yes":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "we_do_the_job_yes";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "GP_standard_5":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_5";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "go_to_the_mill":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
		
			LAi_QuestDelay("go_to_the_mill1", 2.0);		
		break;

		case "go_to_the_mill1":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_7";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;


		case "go_to_the_mill2":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(pchar, characterFromID("Jupiter"));

			LAi_SetCitizenType(characterFromID("Jupiter"));
			LAi_SetCitizenType(characterFromID("the_chinese"));

			Pchar.quest.gp_mill_door = "info";
		
			Pchar.quest.Jup_in_restaurant.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Jup_in_restaurant.win_condition.l1.location = "GB_chinese_restaurant";
			Pchar.quest.Jup_in_restaurant.win_condition = "Jup_in_restaurant";			
		break;




		case "Jup_in_restaurant":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinese_restaurant", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinese_restaurant", "goto", "goto8");
		break;

		case "gp_mill_door":
			PlaySound("INTERFACE\closet_open.wav");

			LAi_QuestDelay("gp_mill_door1", 1.0);
		break;

		case "gp_mill_door1":
			DoQuestReloadToLocation("GB_chinese_gunpowder", "reload", "reload1", "gp_mill_door2");
		break;

		case "gp_mill_door2":
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload9 = 1.5;
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box4 = 0.001;
		break;
//---------------------------------------------------------------------------------------------------------

		case "Jup_with_ingredients":
			//from 4 different places, 2 in SL_utils
			
			if(CheckAttribute(Pchar,"quest.last_ingredients") && Pchar.quest.last_ingredients == "given")
			{
				return;			//no more Jup now
			}
			else
			{
				PlaySound("INTERFACE\closet_open.wav");
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_chinese_gunpowder", "reload", "reload1");
				LAi_SetStayType(characterFromID("Jupiter"));
	
				LAi_QuestDelay("Jup_with_ingredients1", 1.0);
			}
		break;

		case "Jup_with_ingredients1":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");

			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator(Pchar, "goto", "ingredients", "Jup_with_ingredients2", 3.0);
		break;

		case "Jup_with_ingredients2":
			if(CheckAttribute(Pchar,"quest.3workshops") && Pchar.quest.3workshops == "open")
			{
				Pchar.quest.last_ingredients = "given";
				Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "last_ingredients";
			}
			else Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "ingredients";

			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_with_ingredients_done":
			if(makefloat(Pchar.quest.lost_charcoal) + makefloat(Pchar.quest.lost_nitre) + makefloat(Pchar.quest.lost_nitre) > 0.0)
			{
				PlaySound("PEOPLE\clothes1.wav");
				PlaySound("PEOPLE\clothes1.wav");
			}

			if(makefloat(Pchar.quest.lost_charcoal) > 3.0)
			{ 
				TakenItems(Pchar, "pistolcharcoal_F", 2); 
				TakenItems(Pchar, "pistolcharcoal_E", -2); 
			}
			else
			{ 
				if(makefloat(Pchar.quest.lost_charcoal) > 2.0)
			  	{ 
					TakenItems(Pchar, "pistolcharcoal_F", 1); 
				  	TakenItems(Pchar, "pistolcharcoal_H", 1); 
					TakenItems(Pchar, "pistolcharcoal_E", -2);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_charcoal) > 1.0)
				{
					TakenItems(Pchar, "pistolcharcoal_F", 1);
					TakenItems(Pchar, "pistolcharcoal_E", -1);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_charcoal) > 0.0)
				{
					TakenItems(Pchar, "pistolcharcoal_H", 1);
					TakenItems(Pchar, "pistolcharcoal_E", -1);
				}
			}

			if(makefloat(Pchar.quest.lost_nitre) > 5.0)
			{ 
				TakenItems(Pchar, "pistolnitre_big_F", 3);  
				TakenItems(Pchar, "pistolnitre_E", -3);
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 4.0)
				{ 
					TakenItems(Pchar, "pistolnitre_big_F", 2); 
					TakenItems(Pchar, "pistolnitre_H", 1); 
					TakenItems(Pchar, "pistolnitre_E", -3);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 3.0)
				{ 
					TakenItems(Pchar, "pistolnitre_big_F", 2); 
					TakenItems(Pchar, "pistolnitre_E", -2);
				}
			}
			else
			{ 
				if(makefloat(Pchar.quest.lost_nitre) > 2.0)
			  	{ 
					TakenItems(Pchar, "pistolnitre_big_F", 1); 
				  	TakenItems(Pchar, "pistolnitre_H", 1); 
					TakenItems(Pchar, "pistolnitre_E", -2);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 1.0)
				{
					TakenItems(Pchar, "pistolnitre_big_F", 1);
					TakenItems(Pchar, "pistolnitre_E", -1);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 0.0)
				{
					TakenItems(Pchar, "pistolnitre_H", 1);
					TakenItems(Pchar, "pistolnitre_E", -1);
				}
			}

			if(makefloat(Pchar.quest.lost_sulfur) > 3.0)
			{ 
				TakenItems(Pchar, "pistolsulphur_F", 2); 
				TakenItems(Pchar, "pistolsulphur_E", -2);
			}
			else
			{ 
				if(makefloat(Pchar.quest.lost_sulfur) > 2.0)
			  	{ 
					TakenItems(Pchar, "pistolsulphur_F", 1); 
				  	TakenItems(Pchar, "pistolsulphur_H", 1); 
					TakenItems(Pchar, "pistolsulphur_E", -2);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_sulfur) > 1.0)
				{
					TakenItems(Pchar, "pistolsulphur_F", 1);
					TakenItems(Pchar, "pistolsulphur_E", -1);
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_sulfur) > 0.0)
				{
					TakenItems(Pchar, "pistolsulphur_H", 1);
					TakenItems(Pchar, "pistolsulphur_E", -1);
				}
			}

			int half_full_jars =  GetCharacterItem(Pchar, "pistolcharcoal_H");
			int half_full_baskets =  GetCharacterItem(Pchar, "pistolsulphur_H");
			int half_full_sacks =  GetCharacterItem(Pchar, "pistolnitre_H");

			if(half_full_jars == 2)
			{
				TakenItems(Pchar, "pistolcharcoal_H", -2);
				TakenItems(Pchar, "pistolcharcoal_F", 1);
			}

			if(half_full_baskets == 2)
			{
				TakenItems(Pchar, "pistolsulphur_H", -2);
				TakenItems(Pchar, "pistolsulphur_F", 1);
			}

			if(half_full_sacks == 2)
			{
				TakenItems(Pchar, "pistolnitre_H", -2);
				TakenItems(Pchar, "pistolnitre_big_F", 1);
			}

			Pchar.quest.lost_charcoal = 0;
			Pchar.quest.lost_nitre = 0;
			Pchar.quest.lost_nitre = 0;

			LAi_QuestDelay("Jup_with_ingredients_done1", 1.0);
		break;

		case "Jup_with_ingredients_done1":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");

			LAi_QuestDelay("Jup_with_ingredients_done2", 2.0);
		break;

		case "Jup_with_ingredients_done2":
			PlaySound("INTERFACE\closed_door.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinese_restaurant", "goto", "goto6");
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "first time";
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Jup_with_ingredients_done3", 2.0);
		break;

		case "Jup_with_ingredients_done3":
			LAi_SetCitizenType(characterFromID("Jupiter"));
			
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolbarrel_gp0" );
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "bladebarrel_gp0" );
		break;
//---------------------------------------------------------------------------------------------------------		
		case "Jup_with_empty_barrels":
			//if gpS after last_ingredients == "given"
			
			PlaySound("INTERFACE\closet_open.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_chinese_gunpowder", "reload", "reload1");
			LAi_SetStayType(characterFromID("Jupiter"));
	
			LAi_QuestDelay("Jup_with_empty_barrels1", 1.0);
		break;

		case "Jup_with_empty_barrels1":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");

			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator(Pchar, "goto", "ingredients", "Jup_with_empty_barrels2", 3.0);
		break;

		case "Jup_with_empty_barrels2":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "need_barrels";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;














//---------------------------------------------------------------------------------------------------------
		case "GP_standard_1_produced":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_1_produced";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "key27_done":
			//from chinese dialog

			PlaySound("INTERFACE\took_item.wav");
			GiveItem2Character(Pchar, "key27");
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "First time";
			LAi_SetCitizenType(characterFromID("the_chinese"));
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("bladebarrel_gp0_autoequip_again", 1.0);
			LAi_QuestDelay("pistolbarrel_gp0_autoequip_again", 1.0);

			Pchar.quest.chinese_no_barrels.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.chinese_no_barrels.win_condition.l1.location = "GB_chinese_restaurant";
			Pchar.quest.chinese_no_barrels.win_condition = "chinese_no_barrels";
		break;

		case "bladebarrel_gp0_autoequip_again":
			if(CheckCharacterItem(Pchar,"bladebarrel_gp0"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladebarrel_gp0");
			
				return;
			}
			else
			{
				LAi_QuestDelay("bladebarrel_gp0_autoequip_again", 1.0);//loop check
			}
		break;

		case "pistolbarrel_gp0_autoequip_again":
			if(CheckCharacterItem(Pchar,"pistolbarrel_gp0"))
			{
				if(CheckCharacterItem(Pchar,"bladebarrel_gp0"))
				{
					if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gp0"))
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladebarrel_gp0");
					}
				}
				else
				{
					EquipCharacterByItem(Pchar, "bladeX4");
				}

				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "pistolbarrel_gp0");
			
				return;
			}
			else
			{
				LAi_QuestDelay("pistolbarrel_gp0_autoequip_again", 1.0);//loop check
			}
		break;

		case "chinese_no_barrels":
			RemoveCharacterEquip(characterFromID("the_chinese"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "pistolbarrel_gpS" );
			RemoveCharacterEquip(characterFromID("the_chinese"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "bladebarrel_gpS" );
		break;

		case "gpS_2":
			if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gpS"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladebarrel_gpS");
			}

			if(!IsEquipCharacterByItem(Pchar, "pistolbarrel_gpS"))
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "pistolbarrel_gpS");
			}
	
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "player", "gpS_2A", 3.0);
		break;

		case "gpS_2A":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_standard_2_produced";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;
	//----------------------------------------------------------------------------------------------
		case "search_red_folder":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "first time";
			LAi_SetStayType(characterFromID("the_chinese"));
			LAi_SetPlayerType(Pchar);

			if(CheckCharacterItem(Pchar,"doc2A"))
			{
				Pchar.quest.found_red_folder.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.found_red_folder.win_condition.l1.location = "GB_chinese_gunpowder";
				Pchar.quest.found_red_folder.win_condition = "found_red_folder";
			}
			else
			{
				LAi_QuestDelay("search_red_folder", 1.0);//loop check
			}
		break;

		case "found_red_folder":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "player", "found_red_folder1", 3.0);
		break;

		case "found_red_folder1":
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "found_red_folder";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;
	//----------------------------------------------------------------------------------------------
		case "gp_standard_2_done":
			//from chinese dialog

			AddQuestRecord("Fireworks","3");
			AddQuestRecord("Fireworks","4");

			Pchar.quest.nitre_door = "open";
			Pchar.quest.charcoal_door = "open";
			Pchar.quest.fireworks_recipe = "yes";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload7", 0.5);
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload7 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 0.0001);
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box5 = 0.0001;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload10", 0.5);
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload10 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box6", 0.0001);
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box6 = 0.0001;

			Locations[FindLocation("GB_Chinatown")].reload.l8.disable = 0;

			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "First time";
			LAi_SetCitizenType(characterFromID("the_chinese"));
			LAi_SetPlayerType(Pchar);
		
			LAi_QuestDelay("pick_up_key24", 1.0);
			LAi_QuestDelay("pick_up_key25", 1.0);
			LAi_QuestDelay("pick_up_key26", 1.0);

			Pchar.quest.chinese_no_barrels2.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.chinese_no_barrels2.win_condition.l1.location = "GB_Chinatown";
			Pchar.quest.chinese_no_barrels2.win_condition = "chinese_no_barrels2";
		
			pchar.quest.fill_nitre_boxes.win_condition.l2 = "location";
			pchar.quest.fill_nitre_boxes.win_condition.l2.location = "GB_chinese_nitre";
			pchar.quest.fill_nitre_boxes.win_condition = "fill_nitre_boxes";
	
			pchar.quest.nitre_chimney.win_condition.l3 = "locator";
			pchar.quest.nitre_chimney.win_condition.l3.location = "GB_chinese_nitre";
			pchar.quest.nitre_chimney.win_condition.l3.locator_group = "goto";
			pchar.quest.nitre_chimney.win_condition.l3.locator = "chimney1";
			pchar.quest.nitre_chimney.win_condition = "nitre_chimney";

			pchar.quest.fill_sulfur_boxes.win_condition.l4 = "location";
			pchar.quest.fill_sulfur_boxes.win_condition.l4.location = "GB_chinese_sulphur";
			pchar.quest.fill_sulfur_boxes.win_condition = "fill_sulfur_boxes";

			pchar.quest.fill_sulfur_corridor_boxes.win_condition.l5 = "location";
			pchar.quest.fill_sulfur_corridor_boxes.win_condition.l5.location = "GB_sulphur_corridor";
			pchar.quest.fill_sulfur_corridor_boxes.win_condition = "fill_sulfur_corridor_boxes";
		break;
	//----------------------------------------------------------------------------------------------
		case "pick_up_key24":
			if(CheckCharacterItem(Pchar,"key24"))
			{
				Pchar.quest.key24 = "picked_up";
				PlaySound("INTERFACE\took_item.wav");
				return;
			}
			else
			{
				LAi_QuestDelay("pick_up_key24", 1.0);//loop check
			}
		break;
	//----------------------------------------------------------------------------------------------
		case "pick_up_key25":
			if(CheckCharacterItem(Pchar,"key25"))
			{
				PlaySound("INTERFACE\took_item.wav");
				return;
			}
			else
			{
				LAi_QuestDelay("pick_up_key25", 1.0);//loop check
			}
		break;
	//----------------------------------------------------------------------------------------------
		case "pick_up_key26":
			if(CheckCharacterItem(Pchar,"key26"))
			{
				PlaySound("INTERFACE\took_item.wav");
				return;
			}
			else
			{
				LAi_QuestDelay("pick_up_key26", 1.0);//loop check
			}
		break;
	//----------------------------------------------------------------------------------------------
		case "chinese_no_barrels2":
			RemoveCharacterEquip(characterFromID("the_chinese"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "pistolbarrel_gpS" );
			RemoveCharacterEquip(characterFromID("the_chinese"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "bladebarrel_gpS" );

			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinese_restaurant", "goto", "goto8");
		break;
	//----------------------------------------------------------------------------------------------
		case "fill_nitre_boxes":
			locations[FindLocation(Pchar.location)].box7.items.pistolnitre_big_F = 1;
			locations[FindLocation(Pchar.location)].box7.items.bladebroom = 1;
			locations[FindLocation(Pchar.location)].box7.items.doc5A = 1;
		break;
	//----------------------------------------------------------------------------------------------
		case "nitre_chimney":	
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_nitre", "goto", "chimney2");
			
			LAi_QuestDelay("nitre_chimney1", 0.5);
		break;

		case "nitre_chimney1":
			pchar.quest.nitre_chimney.win_condition.l1 = "locator";
			pchar.quest.nitre_chimney.win_condition.l1.location = "GB_chinese_nitre";
			pchar.quest.nitre_chimney.win_condition.l1.locator_group = "goto";
			pchar.quest.nitre_chimney.win_condition.l1.locator = "chimney1";
			pchar.quest.nitre_chimney.win_condition = "nitre_chimney";
		break;
	//----------------------------------------------------------------------------------------------
		case "fill_sulfur_boxes":
			locations[FindLocation(Pchar.location)].box2.items.sledgehammer = 1;
			locations[FindLocation(Pchar.location)].box5.items.key25 = 1;
			locations[FindLocation(Pchar.location)].box5.items.doc6A = 1;
		break;
	//----------------------------------------------------------------------------------------------
		case "fill_sulfur_corridor_boxes":
			locations[FindLocation(Pchar.location)].box2.items.bladeaxe3 = 1;
		break;
//-----------------------------------------------------------------------------------------------------------------------------	
		case "china_guests_out":
			if(CheckAttribute(Pchar,"quest.guest_nitre") && Pchar.quest.guest_nitre == "time")
			{
				if(CheckAttribute(Pchar,"quest.guest_charcoal") && Pchar.quest.guest_charcoal == "time")
				{
					if(CheckAttribute(Pchar,"quest.guest_sulfur") && Pchar.quest.guest_sulfur == "time")
					{
						Locations[FindLocation("GB_Chinese_restaurant")].models.always.locators = "chinarest_l_items";
						locations[FindLocation("GB_Chinese_restaurant")].type = "silent_residence";	

						Logit(TranslateString("","No, I don't know how to go on. I have to visit the Restaurant."));
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						AddQuestRecord("Gunpowder","6");

						ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Chinese_restaurant", "goto", "goto8");	
						ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinese_restaurant", "goto", "goto6");	
						LAi_SetStayType(characterFromID("the_chinese"));
					
						pchar.quest.fill_rest_boxes.win_condition.l1 = "location";
						pchar.quest.fill_rest_boxes.win_condition.l1.location = "GB_chinese_restaurant";
						pchar.quest.fill_rest_boxes.win_condition = "fill_rest_boxes";
					}
				}
			}	
		break;

		case "fill_rest_boxes":
			locations[FindLocation(Pchar.location)].box1.items.bladeladle = 1;
	
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "items", "search_restaurant", 3.0);
		break;

		case "search_restaurant":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "search_restaurant";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "search_restaurant_done":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "first time";
			LAi_SetCitizenType(characterFromID("the_chinese"));
			LAi_SetPlayerType(Pchar);

			Pchar.quest.3workshops = "open";	//no Jup with additional ingredients any longer or maybe one last time
			
			LAi_QuestDelay("search_3_items_restaurant", 1.0);
		break;

		case "search_3_items_restaurant":
			if(CheckCharacterItem(Pchar,"bladeladle") && CheckCharacterItem(Pchar,"pistolpyrite_E") && CheckCharacterItem(Pchar,"bladepickaxe1"))
			{
				PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
				Logit(TranslateString("","I got what I need of missing Tools. To the workshops!"));
				return;
			}
			else
			{
				LAi_QuestDelay("search_3_items_restaurant", 1.0);//loop check
			}
		break;
//--------------------------------------------------------------------------------------------------------------------------
		case "very_nice":
			PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		break;

		case "gunpowder_F":
			PlaySound("INTERFACE\closet_open.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_Chinese_gunpowder", "reload", "reload1");
			LAi_SetStayType(characterFromID("the_chinese"));

			LAi_QuestDelay("gunpowder_F1", 1.0);
		break;

		case "gunpowder_F1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("the_chinese"));
			
			LAi_QuestDelay("gunpowder_F2", 1.0);
		break;
		
		case "gunpowder_F2":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "GP_fireworks";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

//start case "6A" from here------------------------------------------------------------------------------------------------->	
		case "GP_fireworks_done":
			PlaySound("INTERFACE\closed_door.wav");
			AddQuestRecord("Fireworks", "5");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_chinese_restaurant", "barmen", "stay1");
			LAi_SetStayType(characterFromID("Jupiter"));
			Pchar.quest.Jupiter_sits = "bartender";
			LAi_SetPlayerType(Pchar);

			RemoveCharacterEquip(characterFromID("the_chinese"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "pistolbarrel_gpF" );
			RemoveCharacterEquip(characterFromID("the_chinese"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("the_chinese"), "bladebarrel_gpF" );

			Locations[FindLocation("GB_chinese_room")].id.label = "Fireworks laboratory";
			Locations[FindLocation("GB_chinese_restaurant")].id.label = "Fireworks laboratory";
			Locations[FindLocation("GB_chinese_restaurant")].reload.l6.disable = 0;
		break;

		case "in_fireworks_lab":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_lab";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "in_fireworks_lab_done":	
			LAi_QuestDelay("in_fireworks_lab_done1", 1.0);
		break;

		case "in_fireworks_lab_done1":	
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_room", "goto", "stay1");
			PlaySound("PEOPLE\run_wood.wav");

			LAi_QuestDelay("in_fireworks_lab_done2", 1.0);
		break;

		case "in_fireworks_lab_done2":	
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToLocator(characterFromID("the_chinese"), "goto", "look0");
			
			LAi_QuestDelay("in_fireworks_lab_done3", 1.0);
		break;

		case "in_fireworks_lab_done3":	
			PlaySound("AMBIENT\TAVERN\move1.wav");
			PlaySound("AMBIENT\TAVERN\move1.wav");

			LAi_QuestDelay("in_fireworks_lab_done4", 2.0);
		break;

		case "in_fireworks_lab_done4":	
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("AMBIENT\JAIL\sigh2.wav");

			LAi_QuestDelay("in_fireworks_lab_done5", 2.5);
		break;

		case "in_fireworks_lab_done5":	
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese1");

			LAi_QuestDelay("in_fireworks_lab_done6", 0.5);
		break;

		case "in_fireworks_lab_done6":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese2");

			LAi_QuestDelay("in_fireworks_lab_done7", 0.5);
		break;

		case "in_fireworks_lab_done7":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese3");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "chinese2");

			LAi_QuestDelay("in_fireworks_lab_done8", 0.5);
		break;

		case "in_fireworks_lab_done8":	
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToLocator(characterFromID("the_chinese"), "goto", "look3");

			LAi_QuestDelay("in_fireworks_lab_done9", 1.0);
		break;

		case "in_fireworks_lab_done9":	
			PlaySound("INTERFACE\paper_small.wav");

			LAi_QuestDelay("in_fireworks_lab_done10", 2.0);
		break;

		case "in_fireworks_lab_done10":	
			PlaySound("INTERFACE\paper_small.wav");

			LAi_QuestDelay("in_fireworks_lab_done11", 2.0);
		break;

		case "in_fireworks_lab_done11":	
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");

			LAi_QuestDelay("in_fireworks_lab_done12", 1.0);
		break;

		case "in_fireworks_lab_done12":	
			PlaySound("INTERFACE\book_close.wav");

			LAi_QuestDelay("in_fireworks_lab_done13", 2.0);
		break;

		case "in_fireworks_lab_done13":	
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese2");

			LAi_QuestDelay("in_fireworks_lab_done14", 0.5);
		break;

		case "in_fireworks_lab_done14":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese1");
	//at cauldron now
			LAi_QuestDelay("in_fireworks_lab_gp", 1.0);
		break;

		case "in_fireworks_lab_gp":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_lab_gp";
			LAi_SetActorType(characterFromID("the_chinese"));
		//	LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorTurnToLocator(characterFromID("the_chinese"), "randitem", "randitem13");
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "in_fireworks_lab_gp_done":	
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese");

			LAi_QuestDelay("in_fireworks_lab_gp_done1", 0.5);
		break;

		case "in_fireworks_lab_gp_done1":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese5");

			LAi_QuestDelay("in_fireworks_lab_gp_done2", 0.5);
		break;

		case "in_fireworks_lab_gp_done2":	
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToLocator(characterFromID("the_chinese"), "goto", "look5");

			LAi_QuestDelay("in_fireworks_lab_gp_done3", 1.0);
		break;

		case "in_fireworks_lab_gp_done3":
			PlaySound("PEOPLE\powderhorn.wav");

			LAi_QuestDelay("in_fireworks_lab_gp_done4", 2.0);
		break;

		case "in_fireworks_lab_gp_done4":
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese");

			LAi_QuestDelay("in_fireworks_lab_gp_done5", 1.0);
		break;

		case "in_fireworks_lab_gp_done5":
			PlaySound("PEOPLE\gunpowder.wav");
			
			LAi_QuestDelay("in_fireworks_lab_gp_done6", 3.0);
		break;

		case "in_fireworks_lab_gp_done6":
			PlaySound("PEOPLE\step_iron.wav");
			
			LAi_QuestDelay("in_fireworks_lab_gp_done7", 1.0);
		break;

		case "in_fireworks_lab_gp_done7":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			
			LAi_QuestDelay("in_fireworks_lab_paper", 1.0);
		break;

		case "in_fireworks_lab_paper":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_lab_paper";
			LAi_SetActorType(characterFromID("the_chinese"));
		//	LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorTurnToLocator(characterFromID("the_chinese"), "goto", "chinese2");
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "in_fireworks_lab_paper_done":	
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese1");

			LAi_QuestDelay("in_fireworks_lab_paper_done1", 0.5);
		break;

		case "in_fireworks_lab_paper_done1":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese2");

			LAi_QuestDelay("in_fireworks_lab_paper_done2", 0.5);
		break;

		case "in_fireworks_lab_paper_done2":	
			PlaySound("INTERFACE\carpet_move.wav");

			LAi_QuestDelay("in_fireworks_lab_paper_done3", 1.5);
		break;

		case "in_fireworks_lab_paper_done3":	
			PlaySound("INTERFACE\carpet_move.wav");

			LAi_QuestDelay("in_fireworks_lab_paper_done4", 1.5);
		break;

		case "in_fireworks_lab_paper_done4":	
			PlaySound("INTERFACE\carpet_move.wav");

			LAi_QuestDelay("in_fireworks_lab_paper_done5", 1.5);
		break;

		case "in_fireworks_lab_paper_done5":	
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese1");

			LAi_QuestDelay("in_fireworks_lab_paper_done6", 0.5);
		break;

		case "in_fireworks_lab_paper_done6":	
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese");

			LAi_QuestDelay("in_fireworks_lab_paper_done7", 0.5);
		break;

		case "in_fireworks_lab_paper_done7":	
			PlaySound("PEOPLE\gunpowder.wav");

			LAi_QuestDelay("in_fireworks_lab_glue", 2.5);
		break;

		case "in_fireworks_lab_glue":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_lab_glue";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;
//JRH fade chinese room

		case "in_fireworks_lab_glue_done":
			Locations[FindLocation("GB_chinese_room")].models.always.locators = "chinese_room_locator";	//no chest	
			Locations[FindLocation("GB_chinese_room")].image = "";
			DoQuestReloadToLocation("GB_chinese_room", "goto", "stay1", "in_fireworks_lab_glue_done5");
		break;

		case "in_fireworks_lab_glue_done5":
			Locations[FindLocation("GB_chinese_room")].image = "GB_chinese_room.tga";
			PlaySound("AMBIENT\TAVERN\move1.wav");
			PlaySound("AMBIENT\TAVERN\move1.wav");

			LAi_QuestDelay("in_fireworks_lab_glue_done6", 2.0);
		break;

		case "in_fireworks_lab_glue_done6":	
			PlaySound("AMBIENT\TAVERN\drop6.wav");
			PlaySound("AMBIENT\TAVERN\drop6.wav");

			LAi_QuestDelay("in_fireworks_lab_glue_done7", 2.0);
		break;

		case "in_fireworks_lab_glue_done7":	
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			LAi_QuestDelay("in_fireworks_lab_rockets", 1.0);
		break;
	
		case "in_fireworks_lab_rockets":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_lab_rockets";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;
//JRH close FW 
		case "in_fireworks_lab_rockets_done":
			CloseQuestHeader("Fireworks");
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\run_wood.wav");	
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_room", "goto", "chinese6");

			LAi_QuestDelay("in_fireworks_lab_rockets_done1", 1.0);
		break;

		case "in_fireworks_lab_rockets_done1":
			PlaySound("AMBIENT\JAIL\door_001.wav");
			GiveItem2Character(Pchar, "pistolFWchest");
			EquipCharacterbyItem(Pchar, "pistolFWchest");

			LAi_QuestDelay("pchar_very_nice", 1.0);
			LAi_QuestDelay("in_fireworks_lab_return_stuff", 2.0);
		break;

		case "in_fireworks_lab_return_stuff":	
			Characters[GetCharacterIndex("the_chinese")].dialog.CurrentNode  = "in_fireworks_return_stuff";
			LAi_SetActorType(characterFromID("the_chinese"));
			LAi_ActorTurnToCharacter(characterFromID("the_chinese"), PChar);
			LAi_ActorDialogNow(characterFromID("the_chinese"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("the_chinese"));
		break;

		case "in_fireworks_lab_return_stuff_done":	
			PlaySound("OBJECTS\DUEL\sword_fallen.wav");
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterByItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistolFWchest");
			EquipCharacterbyItem(Pchar, "pistolFWchest");

			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");

			LAi_QuestDelay("in_fireworks_lab_rockets_done2", 1.0);
		break;

		case "in_fireworks_lab_rockets_done2":
			PlaySound("PEOPLE\run_wood.wav");	
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_room", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("the_chinese"), "GB_chinese_room", "goto", "chinese");

			LAi_QuestDelay("in_fireworks_lab_rockets_done3", 1.0);
		break;

		case "in_fireworks_lab_rockets_done3":
			PlaySound("PEOPLE\run_wood.wav");	
			ChangeCharacterAddressGroup(Pchar, "GB_chinese_room", "reload", "reload1");
			Locations[FindLocation("GB_Chinese_restaurant")].reload.l6.emerge = "reload1";
			SetCurrentTime(22.00, 0);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_chinese_restaurant", "goto", "goto8");
			Pchar.quest.Jupiter_sits = "no";	//reset to normal default phrase

			LAi_QuestDelay("in_fireworks_lab_rockets_done5", 1.0);
	
			Pchar.quest.in_fireworks_lab_rockets_done4.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.in_fireworks_lab_rockets_done4.win_condition.l1.location = "GB_chinese_room";
			Pchar.quest.in_fireworks_lab_rockets_done4.win_condition = "in_fireworks_lab_rockets_done4";
		break;

		case "in_fireworks_lab_rockets_done5":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_exit");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "in_fireworks_lab_rockets_done4":
			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "officers", "reload6_1", "jumpstart_plantation", 2.0);
		break;

		case "jumpstart_plantation":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");	

			LAi_QuestDelay("jumpstart_plantation1", 2.0);
		break;

		case "jumpstart_plantation1":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");	

			LAi_QuestDelay("jumpstart_plantation2", 1.0);
		break;

		case "jumpstart_plantation2":
			SetCurrentTime(22.00, 0);
			SetNextWeather("Clear");	//for fireworks to look good
			DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1", "jumpstart_plantation3");
		break;

		case "jumpstart_plantation3":
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Bessop_plantation")].reload.l1.disable = 1;		//temp closed

			pchar.quest.Bessop_start_dialog.win_condition.l1 = "locator";
			pchar.quest.Bessop_start_dialog.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_start_dialog.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_start_dialog.win_condition.l1.locator = "goto26";
			pchar.quest.Bessop_start_dialog.win_condition = "Bessop_start_dialog";
		break;
	
	//---------------------------------------------------------------------------------------------------------------------
		case "Bessop_box9":
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box8");
		break;

		case "Bessop_box10":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look11");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "Bessop_box11":
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box10");
		break;

		case "Bessop_box13":
			PlaySound("PEOPLE\run_roof.wav");
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box12");
		break;
//---------------------------------------------------------------------------------------------------------------------
//JRH start Plantation sneak

		case "Bessop_start_dialog":
			PauseAllSounds();

			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "goto26_jup");

				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Bessop_start";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Bessop_start_done":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "climb";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "climb_done":
			LAi_SetPlayerType(pchar);
			AddQuestRecord("The_plantation","3");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 2.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box15 = 2.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "gate", 16.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;

			pchar.quest.Bessop_gate_alarm.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_alarm.win_condition = "Bessop_gate_alarm";
		break;
	//..........................................................................................
		case "Bessop_gate_alarm":
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard1"), PChar);
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard2"), PChar);

			LAi_QuestDelay("Bessop_gate_alarm1", 1.0);
		break;
	
		case "Bessop_gate_alarm1":
			LAi_SetActorType(Pchar);

			int guardwarning = rand(1);
			switch (guardwarning)
			{
				case 0:
					PlaySound("VOICE\ENGLISH\pir_capM.wav");
					LAi_ActorTurnToCharacter(Pchar, characterFromID("Bessop_guard1"));

					LAi_QuestDelay("Bessop_gate_alarm2", 4.0);
				break;

				case 1:
					PlaySound("VOICE\ENGLISH\pir_capEE.wav");
					LAi_ActorTurnToCharacter(Pchar, characterFromID("Bessop_guard2"));
				
					LAi_QuestDelay("Bessop_gate_alarm2", 2.5);
				break;
			}
		break;

		case "Bessop_gate_alarm2":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "gate_back");
			LAi_SetPlayerType(Pchar);
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "gate_back_jup");
			}
			
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_ActorTurnToCharacter(characterFromID("Bessop_guard1"), characterFromID("Bessop_guard2"));
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			
			if(CheckAttribute(Pchar,"quest.bessop_fireworks") && Pchar.quest.bessop_fireworks == "on")
			{
				LAi_ActorTurnToLocator(characterFromID("Bessop_guard2"), "goto", "look_FW");
			}
			else LAi_ActorTurnToCharacter(characterFromID("Bessop_guard2"), characterFromID("Bessop_guard1"));

			pchar.quest.Bessop_gate_alarm.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_alarm.win_condition = "Bessop_gate_alarm";
		break;
	//..........................................................................................
		case "wait_climb_until_dark":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "wait_climb_until_dark";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
	//..........................................................................................
		case "Jupiter_to_mountain":
			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			PlaySound("PEOPLE\run_stone.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "mountain_jup");

			LAi_QuestDelay("where_are_the_slaves", 2.0);
		break;

		case "where_are_the_slaves":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "where_are_the_slaves";
			LAi_ActorSelfDialog(pchar, "");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 0.0001);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box15 = 0.0001;
		break;
	
		case "where_are_the_slaves_done":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "slave_barracks";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "slave_barracks_done":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "mountain1");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "mountain1_jup");

			LAi_QuestDelay("slave_barracks_done1", 0.5);
		break;

		case "slave_barracks_done1":
			LAi_SetPoorType(Pchar);
			LAi_SetPoorType(characterFromID("Jupiter"));

			LAi_QuestDelay("on_mountain_top", 2.0);
		break;

		case "on_mountain_top":
			PlaySound("PEOPLE\grass_turn.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "mountain1");

			LAi_QuestDelay("on_mountain_top1", 1.0);
		break;

		case "on_mountain_top1":
			PlaySound("PEOPLE\grass_turn.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "mountain1_Jup");

			LAi_QuestDelay("on_mountain_top2", 2.0);
		break;

		case "on_mountain_top2":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "plantation_patrol";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "plantation_patrol_done":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "patrol_yes";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "patrol_yes_done":
			AddQuestRecord("The_plantation","4");
			LAi_SetPoorType(characterFromID("Jupiter"));

			LAi_QuestDelay("leave_mountain_top", 2.0);
		break;

		case "leave_mountain_top":
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "sneak1");
			LAi_SetSitType(Pchar);
		
			LAi_QuestDelay("leave_mountain_top1", 0.5);
		break;

		case "leave_mountain_top1":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("leave_mountain_top2", 1.0);
		break;

		case "leave_mountain_top2":
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "sneak1_jup");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("leave_mountain_top3", 0.5);
		break;

		case "leave_mountain_top3":
			LAi_SetOfficerType(characterFromID("Jupiter"));

			LAi_QuestDelay("leave_mountain_top4", 1.0);
		break;
//JRH before plantation sneak
		case "leave_mountain_top4":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "wait_for_fireworks";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "wait_for_fireworks_done":
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));

			if(IsEquipCharacterByItem(Pchar, "pistolFWchest"))
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			}
			TakeItemFromCharacter(Pchar, "pistolFWchest" );
			TakeItemFromCharacter(Pchar, "pistoltinderbox" );

			if(!CheckCharacterItem(characterFromID("Jupiter"),"bladeX4")) 
			{ GiveItem2Character(characterFromID("Jupiter"), "bladeX4"); }
			EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");

			GiveItem2Character(characterFromID("Jupiter"), "pistolFWchest");
			EquipCharacterByItem(characterFromID("Jupiter"), "pistolFWchest");
			GiveItem2Character(characterFromID("Jupiter"), "pistoltinderbox");

			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "goto63", "wait_for_fireworks_done1", 5.0);

			AddQuestRecord("The_plantation","5");

			LAi_QuestDelay("Jup_FW_equip_check", 0.01);
		break;

		case "Jup_FW_equip_check":
			if(CheckAttribute(Pchar,"Jup_FW_equip_check") && Pchar.Jup_FW_equip_check == "enough") return;

			if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladeX4"))
			{
				EquipCharacterByItem(Pchar, "bladeX4");
			}	

			if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "pistolFWchest"))
			{
				EquipCharacterByItem(characterFromID("Jupiter"), "pistolFWchest");
			}
			
			LAi_QuestDelay("Jup_FW_equip_check", 0.25);//loop check for 5 sec
		break;

		case "wait_for_fireworks_done1":
			pchar.Jup_FW_equip_check = "enough";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 1.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box17 = 1.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box18", 1.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box18 = 1.0;

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "goto63");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Bessop_plantation")].reload.l1.disable = 1;	//town closed (for night maybe)

			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolFWchest");

			pchar.quest.plantation_fireworks_start.win_condition.l1 = "locator";
			pchar.quest.plantation_fireworks_start.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.plantation_fireworks_start.win_condition.l1.locator_group = "goto";
			pchar.quest.plantation_fireworks_start.win_condition.l1.locator = "FW";
			pchar.quest.plantation_fireworks_start.win_condition = "plantation_fireworks_start";
		break;

		case "plantation_fireworks_start":
			SetMusicAlarm("silent_jungle");		//during fireworks
			locations[FindLocation("Bessop_plantation")].type = "silent_jungle";

			Pchar.quest.bessop_fireworks = "on";
			DeleteQuestHeader("Fireworks");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_FW");
			LAi_SetActorType(characterFromID("bessop_tower1"));
			LAi_ActorTurnToLocator(characterFromID("bessop_tower1"), "goto", "look_FW");
			LAi_SetActorType(characterFromID("bessop_guard2"));
			LAi_ActorTurnToLocator(characterFromID("bessop_guard2"), "goto", "look_FW");

			LAi_QuestDelay("plantation_fireworks_serie1", 0.01);		
		break;
//JRH FW
		case "plantation_fireworks_serie1":
			//1 red sun
			LAi_QuestDelay("fireworks4_sound_start", 0.01);
			LAi_QuestDelay("plantation_fireworks4_A_center", 0.01);

			//2 white ring
			LAi_QuestDelay("fireworks2_sound_start", 6.5);
			LAi_QuestDelay("plantation_fireworks2_A_center", 6.5);

			//3 fire rain
			LAi_QuestDelay("fireworks5_sound_start", 12.0);
			LAi_QuestDelay("plantation_fireworks5_A_center", 12.0);

			//4 red sun x4
			LAi_QuestDelay("fireworks4_sound_start", 18.5);
			LAi_QuestDelay("plantation_fireworks4_A_high", 18.5);
	
			LAi_QuestDelay("fireworks4_sound1", 18.75);						
			LAi_QuestDelay("plantation_fireworks4_B_right", 20.25);

			LAi_QuestDelay("fireworks4_sound1", 19.0);						
			LAi_QuestDelay("plantation_fireworks4_B_low", 20.5);

			LAi_QuestDelay("fireworks4_sound1", 19.25);							
			LAi_QuestDelay("plantation_fireworks4_B_left", 20.75);
	
			//5 yellow cross
			LAi_QuestDelay("fireworks1_sound_start", 26.0);
			LAi_QuestDelay("plantation_fireworks1_A_center", 26.0);	

			LAi_QuestDelay("plantation_fireworks_serie2", 33.5);
		break;

		case "plantation_fireworks_serie2":
			//6 white ring + red sun x4
			LAi_QuestDelay("fireworks2_sound_start", 0.01);
			LAi_QuestDelay("plantation_fireworks2_A_center", 0.01);
			LAi_QuestDelay("plantation_fireworks4_A_high", 0.01);
			LAi_QuestDelay("plantation_fireworks4_A_low", 0.01);
			LAi_QuestDelay("plantation_fireworks4_A_left", 0.01);
			LAi_QuestDelay("plantation_fireworks4_A_right", 0.01);	

			//7 fire rain x3
			LAi_QuestDelay("fireworks5_sound_start", 6.5);
			LAi_QuestDelay("plantation_fireworks5_A_right", 6.5);
			LAi_QuestDelay("fireworks5_sound2", 9.5);
			LAi_QuestDelay("plantation_fireworks5_A_center", 7.0);
			LAi_QuestDelay("fireworks5_sound2", 10.0);
			LAi_QuestDelay("plantation_fireworks5_A_left", 7.5);

			//8 blue flower
			LAi_QuestDelay("fireworks3_sound_start", 13.0);
			LAi_QuestDelay("plantation_fireworks3_A_center", 13.0);

			//9 white ring x4
			LAi_QuestDelay("fireworks2_sound_start", 21.5);
			LAi_QuestDelay("plantation_fireworks2_A_left", 21.5);
			LAi_QuestDelay("plantation_fireworks2_A_right", 21.5);

			LAi_QuestDelay("fireworks2_sound2", 23.5);
			LAi_QuestDelay("plantation_fireworks2_B_high", 23.5);
			LAi_QuestDelay("plantation_fireworks2_B_low", 23.5);
			
			//10 red sun x8
			LAi_QuestDelay("fireworks4_sound_start", 27.0);
			LAi_QuestDelay("fireworks4_sound2", 28.5);
			LAi_QuestDelay("plantation_fireworks4_A_high", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_low", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_left", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_right", 27.0);	
			LAi_QuestDelay("plantation_fireworks4_A_high_left", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_high_right", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_low_left", 27.0);
			LAi_QuestDelay("plantation_fireworks4_A_low_right", 27.0);

			LAi_QuestDelay("plantation_fireworks_serie3", 33.5);
		break;

		case "plantation_fireworks_serie3":
			//11 red sun + fire rain x4
			LAi_QuestDelay("fireworks5_sound_start", 0.01);
			LAi_QuestDelay("plantation_fireworks5_A_left", 0.01);
			LAi_QuestDelay("plantation_fireworks5_A_right", 0.01);
			LAi_QuestDelay("plantation_fireworks5_A_high", 0.01);
			LAi_QuestDelay("plantation_fireworks5_A_low", 0.01);
			LAi_QuestDelay("plantation_fireworks4_B_center", 3.0);

			//12 white ring + red sun x8
			LAi_QuestDelay("fireworks2_sound_start", 6.5);
			LAi_QuestDelay("fireworks4_sound2", 8.0);
			LAi_QuestDelay("plantation_fireworks2_A_center", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_high", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_low", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_left", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_right", 6.5);	
			LAi_QuestDelay("plantation_fireworks4_A_high_left", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_high_right", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_low_left", 6.5);
			LAi_QuestDelay("plantation_fireworks4_A_low_right", 6.5);

			//13 yellow cross + red sun x4
			LAi_QuestDelay("fireworks1_sound_start", 13.0);
			LAi_QuestDelay("plantation_fireworks1_A_center", 13.0);	
			LAi_QuestDelay("plantation_fireworks4_A_high", 13.0);
			LAi_QuestDelay("plantation_fireworks4_A_low", 13.0);
			LAi_QuestDelay("plantation_fireworks4_A_left", 13.0);
			LAi_QuestDelay("plantation_fireworks4_A_right", 13.0);	

			//14 blue flower + red sun x8
			LAi_QuestDelay("fireworks3_sound_start", 20.5);
			LAi_QuestDelay("plantation_fireworks3_A_center", 20.5);
			LAi_QuestDelay("fireworks3_sound3", 24.1);
			LAi_QuestDelay("plantation_fireworks3_7_center", 24.1);

			//15 yellow cross + red sun x4 + white ring x4
			LAi_QuestDelay("fireworks1_sound_start", 30.0);
			LAi_QuestDelay("plantation_fireworks1_A_center", 30.0);	
			LAi_QuestDelay("plantation_fireworks2_A_left", 30.0);
			LAi_QuestDelay("plantation_fireworks2_A_right", 30.0);
			LAi_QuestDelay("plantation_fireworks2_A_high", 30.0);
			LAi_QuestDelay("plantation_fireworks2_A_low", 30.0);
			LAi_QuestDelay("plantation_fireworks4_A_high", 30.0);
			LAi_QuestDelay("plantation_fireworks4_A_left", 30.0);
			LAi_QuestDelay("plantation_fireworks4_A_low", 30.0);
			LAi_QuestDelay("plantation_fireworks4_A_right", 30.0);

			LAi_QuestDelay("plantation_fireworks_serie4", 36.5);
		break;
	
		case "plantation_fireworks_serie4":
			//16 blue flower + red sun x4 + yellow cross x4 + fire rain x6
			LAi_QuestDelay("fireworks3_sound_start", 0.01);
			LAi_QuestDelay("plantation_fireworks3_A_center", 0.01);

			LAi_QuestDelay("fireworks3_sound3", 3.6);
			LAi_QuestDelay("plantation_fireworks1_B_right", 3.6);
			LAi_QuestDelay("plantation_fireworks1_B_low", 3.6);
			LAi_QuestDelay("plantation_fireworks1_B_high", 3.6);
			LAi_QuestDelay("plantation_fireworks1_B_left", 3.6);

			LAi_QuestDelay("plantation_fireworks4_A_high_left", 2.1);
			LAi_QuestDelay("plantation_fireworks4_A_high_right", 2.1);
			LAi_QuestDelay("plantation_fireworks4_A_low_left", 2.1);
			LAi_QuestDelay("plantation_fireworks4_A_low_right", 2.1);
			LAi_QuestDelay("plantation_fireworks3_6_center", 3.6);		//repeat blue flower	
		
			LAi_QuestDelay("fireworks2_sound2", 4.6);
			LAi_QuestDelay("fireworks2_sound2", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_center", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_center", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_left", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_right", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_high", 4.6);
			LAi_QuestDelay("plantation_fireworks5_B_low", 4.6);
			
			LAi_QuestDelay("plantation_fireworks_end", 11.1);
		break;
	
//...........................................................................................................
//...........................................................................................................
		case "fireworks4_sound_start":
			LAi_QuestDelay("fireworks4_sound1", 0.01);
			LAi_QuestDelay("fireworks4_sound2", 1.5);
		break;

		case "fireworks4_sound1":
			PlaySound("AMBIENT\LAND\fireworks4A.wav");
		break;

		case "fireworks4_sound2":
			PlaySound("AMBIENT\LAND\fireworks4B.wav");
		break;
//...........................................................................................................

		//RED SUN low
		case "plantation_fireworks4_A_low":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_low", 1.5);
		break;

		case "plantation_fireworks4_B_low":
			CreateParticleSystem("artifact_short_red" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN center
		case "plantation_fireworks4_A_center":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_center", 1.5);
		break;

		case "plantation_fireworks4_B_center":
			CreateParticleSystem("artifact_short_red" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN high
		case "plantation_fireworks4_A_high":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_high", 1.5);
		break;

		case "plantation_fireworks4_B_high":
			CreateParticleSystem("artifact_short_red" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN left
		case "plantation_fireworks4_A_left":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_left", 1.5);
		break;

		case "plantation_fireworks4_B_left":
			CreateParticleSystem("artifact_short_red" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN right
		case "plantation_fireworks4_A_right":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_right", 1.5);
		break;

		case "plantation_fireworks4_B_right":
			CreateParticleSystem("artifact_short_red" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN high_left
		case "plantation_fireworks4_A_high_left":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_high_left", 1.5);
		break;

		case "plantation_fireworks4_B_high_left":
			CreateParticleSystem("artifact_short_red" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) );	//C
		break;	

//...........................................................................................................

		//RED SUN high_right
		case "plantation_fireworks4_A_high_right":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_high_right", 1.5);
		break;

		case "plantation_fireworks4_B_high_right":
			CreateParticleSystem("artifact_short_red" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN low_left
		case "plantation_fireworks4_A_low_left":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_low_left", 1.5);
		break;

		case "plantation_fireworks4_B_low_left":
			CreateParticleSystem("artifact_short_red" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//RED SUN low_right
		case "plantation_fireworks4_A_low_right":
			CreateParticleSystem("cancloud_stock" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//8
			
			LAi_QuestDelay("plantation_fireworks4_B_low_right", 1.5);
		break;

		case "plantation_fireworks4_B_low_right":
			CreateParticleSystem("artifact_short_red" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud5" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................
		case "fireworks5_sound_start":
			LAi_QuestDelay("fireworks5_sound1", 1.5);
			LAi_QuestDelay("fireworks5_sound2", 2.5);
		break;

		case "fireworks5_sound1":
			PlaySound("AMBIENT\LAND\fireworks5A.wav");
		break;

		case "fireworks5_sound2":
			PlaySound("AMBIENT\LAND\fireworks5B.wav");
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
		break;
//...........................................................................................................

		//FIRE RAIN low
		case "plantation_fireworks5_A_low":
			CreateParticleSystem("qar_fire" , -34.0, 3.0, 53.0, 4.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("plantation_fireworks5_B_low", 2.5);
		break;

		case "plantation_fireworks5_B_low":
			CreateParticleSystem("canfire" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_smoke" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C		//smoke
			CreateParticleSystem("splinters_cannonflash" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
			CreateParticleSystem("splinters_cannonflash" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
		break;
	
//...........................................................................................................

		//FIRE RAIN center
		case "plantation_fireworks5_A_center":
			CreateParticleSystem("qar_fire" , -34.0, 3.0, 53.0, 4.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("plantation_fireworks5_B_center", 2.5);
		break;

		case "plantation_fireworks5_B_center":
			CreateParticleSystem("canfire" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_smoke" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C		//smoke
			CreateParticleSystem("splinters_cannonflash" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
			CreateParticleSystem("splinters_cannonflash" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
		break;
	
//...........................................................................................................

		//FIRE RAIN left
		case "plantation_fireworks5_A_left":
			CreateParticleSystem("qar_fire" , -34.0, 3.0, 53.0, 4.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("plantation_fireworks5_B_left", 2.5);
		break;

		case "plantation_fireworks5_B_left":
			CreateParticleSystem("canfire" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_smoke" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) ); //C		//smoke
			CreateParticleSystem("splinters_cannonflash" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
			CreateParticleSystem("splinters_cannonflash" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
		break;
	
//...........................................................................................................

		//FIRE RAIN right
		case "plantation_fireworks5_A_right":
			CreateParticleSystem("qar_fire" , -34.0, 3.0, 53.0, 4.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("plantation_fireworks5_B_right", 2.5);
		break;

		case "plantation_fireworks5_B_right":
			CreateParticleSystem("canfire" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_smoke" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) ); //C		//smoke
			CreateParticleSystem("splinters_cannonflash" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
			CreateParticleSystem("splinters_cannonflash" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
		break;
	
//...........................................................................................................

		//FIRE RAIN high
		case "plantation_fireworks5_A_high":
			CreateParticleSystem("qar_fire" , -34.0, 3.0, 53.0, 4.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("plantation_fireworks5_B_high", 2.5);
		break;

		case "plantation_fireworks5_B_high":
			CreateParticleSystem("canfire" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_smoke" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C		//smoke
			CreateParticleSystem("splinters_cannonflash" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
			CreateParticleSystem("splinters_cannonflash" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) ); //C	//rain
		break;
	
//...........................................................................................................
		case "fireworks1_sound_start":
			LAi_QuestDelay("fireworks1_sound1", 0.01);
			LAi_QuestDelay("fireworks1_sound2", 1.5);
			LAi_QuestDelay("fireworks1_sound3", 2.5);
		break;

		case "fireworks1_sound1":
			PlaySound("OBJECTS\DUEL\rocket.wav");		
		break;

		case "fireworks1_sound2":
			PlaySound("OBJECTS\SHIPCHARGE\CR12C.wav");		
		break;

		case "fireworks1_sound3":
			PlaySound("AMBIENT\LAND\fireworks1.wav");
		break;
//...........................................................................................................

		//YELLOW STAR low
		case "plantation_fireworks1_A_low":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("plantation_fireworks1_B_low", 1.5);
		break;

		case "plantation_fireworks1_B_low":
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		
			LAi_QuestDelay("plantation_fireworks1_C_low", 0.1);
		break;

		case "plantation_fireworks1_C_low":
			CreateParticleSystem("blast" , -21.0, 26.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 24.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 25.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 25.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			CreateParticleSystem("blast" , -21.0, 26.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 24.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 25.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 25.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
		
			CreateParticleSystem("sparkle_cloud6" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud6" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud6" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud6" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud6" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E			

			LAi_QuestDelay("plantation_fireworks1_D_low", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_low", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_low", 1.0);
		break;

		case "plantation_fireworks1_D_low":
			CreateParticleSystem("blast" , -21.0, 27.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -21.0, 23.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -23.0, 25.0, 64.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -19.0, 25.0, 68.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_E_low", 0.1);
		break;

		case "plantation_fireworks1_E_low":
			CreateParticleSystem("blast" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("blast" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("blast" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E	
		break;

		case "plantation_fireworks1_F_low":
			CreateParticleSystem("blast_dirt" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_dirt" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//YELLOW STAR center
		case "plantation_fireworks1_A_center":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("plantation_fireworks1_B_center", 1.5);
		break;

		case "plantation_fireworks1_B_center":
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		
			LAi_QuestDelay("plantation_fireworks1_C_center", 0.1);
		break;

		case "plantation_fireworks1_C_center":
			CreateParticleSystem("blast" , -21.0, 33.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 31.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 32.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 32.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			CreateParticleSystem("blast" , -21.0, 33.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 31.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 32.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 32.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
		
			CreateParticleSystem("sparkle_cloud6" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud6" , -21.0, 33.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud6" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud6" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud6" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E			

			LAi_QuestDelay("plantation_fireworks1_D_center", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_center", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_center", 1.0);
		break;

		case "plantation_fireworks1_D_center":
			CreateParticleSystem("blast" , -21.0, 34.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -21.0, 30.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -23.0, 32.0, 64.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -19.0, 32.0, 68.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_E_center", 0.1);
		break;

		case "plantation_fireworks1_E_center":
			CreateParticleSystem("blast" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("blast" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("blast" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			LAi_QuestDelay("plantation_fireworks1_G_center", 0.3);			
		break;

		case "plantation_fireworks1_G_center":
			CreateParticleSystem("blast" , -21.0, 34.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -21.0, 30.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -23.0, 32.0, 64.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -19.0, 32.0, 68.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_H_center", 0.3);
		break;

		case "plantation_fireworks1_H_center":
			CreateParticleSystem("blast" , -21.0, 33.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 31.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 32.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 32.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce

			LAi_QuestDelay("plantation_fireworks1_J_center", 0.3);
		break;

		case "plantation_fireworks1_J_center":		
			CreateParticleSystem("sparkle_cloud6" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

		case "plantation_fireworks1_F_center":
			CreateParticleSystem("blast_dirt" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_dirt" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//YELLOW STAR high
		case "plantation_fireworks1_A_high":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("plantation_fireworks1_B_high", 1.5);
		break;

		case "plantation_fireworks1_B_high":
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		
			LAi_QuestDelay("plantation_fireworks1_C_high", 0.1);
		break;

		case "plantation_fireworks1_C_high":
			CreateParticleSystem("blast" , -21.0, 40.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 38.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 39.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 39.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			CreateParticleSystem("blast" , -21.0, 40.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 38.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 39.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 39.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
		
			CreateParticleSystem("sparkle_cloud6" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud6" , -21.0, 40.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud6" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud6" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud6" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E			

			LAi_QuestDelay("plantation_fireworks1_D_high", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_high", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_high", 1.0);
		break;

		case "plantation_fireworks1_D_high":
			CreateParticleSystem("blast" , -21.0, 41.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -21.0, 37.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -23.0, 39.0, 64.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -19.0, 39.0, 68.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_E_high", 0.1);
		break;

		case "plantation_fireworks1_E_high":
			CreateParticleSystem("blast" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("blast" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("blast" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			LAi_QuestDelay("plantation_fireworks1_G_high", 0.3);			
		break;

		case "plantation_fireworks1_G_high":
			CreateParticleSystem("blast" , -21.0, 41.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -21.0, 37.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -23.0, 39.0, 64.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -19.0, 39.0, 68.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_H_high", 0.3);
		break;

		case "plantation_fireworks1_H_high":
			CreateParticleSystem("blast" , -21.0, 40.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -21.0, 38.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -22.0, 39.0, 65.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -20.0, 39.0, 67.0, 5.1, 4.0, 0.0, sti(20) );	//Ce

			LAi_QuestDelay("plantation_fireworks1_J_high", 0.3);
		break;

		case "plantation_fireworks1_J_high":		
			CreateParticleSystem("sparkle_cloud6" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

		case "plantation_fireworks1_F_high":
			CreateParticleSystem("blast_dirt" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_dirt" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//YELLOW STAR left
		case "plantation_fireworks1_A_left":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("plantation_fireworks1_B_left", 1.5);
		break;

		case "plantation_fireworks1_B_left":
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
		
			LAi_QuestDelay("plantation_fireworks1_C_left", 0.1);
		break;

		case "plantation_fireworks1_C_left":
			CreateParticleSystem("blast" , -28.0, 33.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -28.0, 31.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -29.0, 32.0, 58.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -27.0, 32.0, 60.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			CreateParticleSystem("blast" , -28.0, 33.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -28.0, 31.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -29.0, 32.0, 58.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -27.0, 32.0, 60.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
		
			CreateParticleSystem("sparkle_cloud6" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud6" , -28.0, 33.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud6" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud6" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud6" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E			

			LAi_QuestDelay("plantation_fireworks1_D_left", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_left", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_left", 1.0);
		break;

		case "plantation_fireworks1_D_left":
			CreateParticleSystem("blast" , -28.0, 34.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -28.0, 30.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -30.0, 32.0, 57.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -26.0, 32.0, 61.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_E_left", 0.1);
		break;

		case "plantation_fireworks1_E_left":
			CreateParticleSystem("blast" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("blast" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("blast" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			LAi_QuestDelay("plantation_fireworks1_G_left", 0.3);			
		break;

		case "plantation_fireworks1_G_left":
			CreateParticleSystem("blast" , -28.0, 34.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -28.0, 30.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -30.0, 32.0, 57.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -26.0, 32.0, 61.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_H_left", 0.3);
		break;

		case "plantation_fireworks1_H_left":
			CreateParticleSystem("blast" , -28.0, 33.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -28.0, 31.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -29.0, 32.0, 58.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -27.0, 32.0, 60.0, 5.1, 4.0, 0.0, sti(20) );	//Ce

			LAi_QuestDelay("plantation_fireworks1_J_left", 0.3);
		break;

		case "plantation_fireworks1_J_left":		
			CreateParticleSystem("sparkle_cloud6" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

		case "plantation_fireworks1_F_left":
			CreateParticleSystem("blast_dirt" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_dirt" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................

		//YELLOW STAR right
		case "plantation_fireworks1_A_right":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("plantation_fireworks1_B_right", 1.5);
		break;

		case "plantation_fireworks1_B_right":
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
		
			LAi_QuestDelay("plantation_fireworks1_C_right", 0.1);
		break;

		case "plantation_fireworks1_C_right":
			CreateParticleSystem("blast" , -14.0, 33.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -14.0, 31.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -15.0, 32.0, 72.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -13.0, 32.0, 74.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			CreateParticleSystem("blast" , -14.0, 33.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -14.0, 31.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -15.0, 32.0, 72.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -13.0, 32.0, 74.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
		
			CreateParticleSystem("sparkle_cloud6" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud6" , -14.0, 33.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud6" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud6" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud6" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E			

			LAi_QuestDelay("plantation_fireworks1_D_right", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_right", 0.1);
			LAi_QuestDelay("plantation_fireworks1_F_right", 1.0);
		break;

		case "plantation_fireworks1_D_right":
			CreateParticleSystem("blast" , -14.0, 34.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -14.0, 30.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -16.0, 32.0, 71.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -12.0, 32.0, 75.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_E_right", 0.1);
		break;

		case "plantation_fireworks1_E_right":
			CreateParticleSystem("blast" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("blast" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("blast" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			LAi_QuestDelay("plantation_fireworks1_G_right", 0.3);			
		break;

		case "plantation_fireworks1_G_right":
			CreateParticleSystem("blast" , -14.0, 34.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cnn
			CreateParticleSystem("blast" , -14.0, 30.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Css
			CreateParticleSystem("blast" , -16.0, 32.0, 71.0, 5.1, 4.0, 0.0, sti(20) );	//Cww
			CreateParticleSystem("blast" , -12.0, 32.0, 75.0, 5.1, 4.0, 0.0, sti(20) );	//Ce
			
			LAi_QuestDelay("plantation_fireworks1_H_right", 0.3);
		break;

		case "plantation_fireworks1_H_right":
			CreateParticleSystem("blast" , -14.0, 33.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cn
			CreateParticleSystem("blast" , -14.0, 31.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//Cs
			CreateParticleSystem("blast" , -15.0, 32.0, 72.0, 5.1, 4.0, 0.0, sti(20) );	//Cw
			CreateParticleSystem("blast" , -13.0, 32.0, 74.0, 5.1, 4.0, 0.0, sti(20) );	//Ce

			LAi_QuestDelay("plantation_fireworks1_J_right", 0.3);
		break;

		case "plantation_fireworks1_J_right":		
			CreateParticleSystem("sparkle_cloud6" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

		case "plantation_fireworks1_F_right":
			CreateParticleSystem("blast_dirt" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast_dirt" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//C
		break;

//...........................................................................................................
		case "fireworks2_sound_start":
			LAi_QuestDelay("fireworks2_sound1", 0.01);
			LAi_QuestDelay("fireworks2_sound2", 1.5);
		break;

		case "fireworks2_sound1":
			PlaySound("OBJECTS\DUEL\rocket.wav");
		break;

		case "fireworks2_sound2":
			PlaySound("AMBIENT\LAND\fireworks2.wav");
		break;
//...........................................................................................................

		//BURNING RING low
		case "plantation_fireworks2_A_low":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks2_B_low", 1.5);
		break;

		case "plantation_fireworks2_B_low":
			CreateParticleSystem("canfire2" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("canfire2" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("canfire2" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("canfire2" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("canfire2" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("canfire2" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("canfire2" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("canfire2" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			LAi_QuestDelay("plantation_fireworks2_C_low", 0.01);
		break;

		case "plantation_fireworks2_C_low":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_emitter6" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("gunfire" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("gunfire" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("gunfire" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("gunfire" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("gunfire" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("gunfire" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("gunfire" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("gunfire" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			LAi_QuestDelay("plantation_fireworks2_D_low", 1.8);			
		break;
	
		case "plantation_fireworks2_D_low":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+	
		break;

//...........................................................................................................

		//BURNING RING center
		case "plantation_fireworks2_A_center":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks2_B_center", 1.5);
		break;

		case "plantation_fireworks2_B_center":
			CreateParticleSystem("canfire2" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("canfire2" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("canfire2" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("canfire2" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("canfire2" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("canfire2" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("canfire2" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("canfire2" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			LAi_QuestDelay("plantation_fireworks2_C_center", 0.01);
		break;

		case "plantation_fireworks2_C_center":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 34.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_emitter6" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("gunfire" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("gunfire" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("gunfire" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("gunfire" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("gunfire" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("gunfire" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("gunfire" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("gunfire" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			LAi_QuestDelay("plantation_fireworks2_D_center", 1.8);			
		break;
	
		case "plantation_fireworks2_D_center":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+	
		break;

//...........................................................................................................

		//BURNING RING left
		case "plantation_fireworks2_A_left":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks2_B_left", 1.5);
		break;

		case "plantation_fireworks2_B_left":
			CreateParticleSystem("canfire2" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("canfire2" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("canfire2" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("canfire2" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("canfire2" , -30.25, 34.25, 56.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("canfire2" , -30.25, 29.75, 56.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("canfire2" , -25.75, 29.75, 61.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("canfire2" , -25.75, 34.25, 61.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			LAi_QuestDelay("plantation_fireworks2_C_left", 0.01);
		break;

		case "plantation_fireworks2_C_left":
			CreateParticleSystem("sparkle_emitter6" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -30.25, 34.25, 56.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -30.25, 34.75, 56.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 29.75, 61.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 34.25, 61.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_emitter6" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -30.25, 34.25, 56.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -30.25, 29.75, 56.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 29.75, 61.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 34.25, 61.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("gunfire" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("gunfire" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("gunfire" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("gunfire" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("gunfire" , -30.25, 34.25, 56.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("gunfire" , -30.25, 29.75, 56.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("gunfire" , -25.75, 29.75, 61.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("gunfire" , -25.75, 34.25, 61.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			LAi_QuestDelay("plantation_fireworks2_D_left", 1.8);			
		break;
	
		case "plantation_fireworks2_D_left":
			CreateParticleSystem("sparkle_emitter6" , -28.0, 35.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -28.0, 29.0, 59.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -31.0, 32.0, 56.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -25.0, 32.0, 62.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -30.25, 34.25, 56.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -30.25, 29.75, 56.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 29.75, 61.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -25.75, 34.25, 61.25, 5.1, 4.0, 0.0, sti(20) ); //NE+	
		break;

//...........................................................................................................

		//BURNING RING right
		case "plantation_fireworks2_A_right":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks2_B_right", 1.5);
		break;

		case "plantation_fireworks2_B_right":
			CreateParticleSystem("canfire2" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("canfire2" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("canfire2" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("canfire2" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("canfire2" , -16.25, 34.25, 70.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("canfire2" , -16.25, 29.75, 70.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("canfire2" , -11.75, 29.75, 75.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("canfire2" , -11.75, 34.25, 75.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			LAi_QuestDelay("plantation_fireworks2_C_right", 0.01);
		break;

		case "plantation_fireworks2_C_right":
			CreateParticleSystem("sparkle_emitter6" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -16.25, 34.25, 70.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -16.25, 34.75, 70.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 29.75, 75.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 34.25, 75.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_emitter6" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -16.25, 34.25, 70.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -16.25, 29.75, 70.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 29.75, 75.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 34.25, 75.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("gunfire" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("gunfire" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("gunfire" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("gunfire" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("gunfire" , -16.25, 34.25, 70.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("gunfire" , -16.25, 29.75, 70.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("gunfire" , -11.75, 29.75, 75.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("gunfire" , -11.75, 34.25, 75.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			LAi_QuestDelay("plantation_fireworks2_D_right", 1.8);			
		break;
	
		case "plantation_fireworks2_D_right":
			CreateParticleSystem("sparkle_emitter6" , -14.0, 35.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -14.0, 29.0, 73.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -17.0, 32.0, 70.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -11.0, 32.0, 76.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -16.25, 34.25, 70.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -16.25, 29.75, 70.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 29.75, 75.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -11.75, 34.25, 75.25, 5.1, 4.0, 0.0, sti(20) ); //NE+	
		break;

//...........................................................................................................

		//BURNING RING high
		case "plantation_fireworks2_A_high":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks2_B_high", 1.5);
		break;

		case "plantation_fireworks2_B_high":
			CreateParticleSystem("canfire2" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("canfire2" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("canfire2" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("canfire2" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("canfire2" , -23.25, 41.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("canfire2" , -23.25, 36.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("canfire2" , -18.75, 36.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("canfire2" , -18.75, 41.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			LAi_QuestDelay("plantation_fireworks2_C_high", 0.01);
		break;

		case "plantation_fireworks2_C_high":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 41.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 41.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 36.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 41.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_emitter6" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 41.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 36.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 36.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 41.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("gunfire" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("gunfire" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("gunfire" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("gunfire" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("gunfire" , -23.25, 41.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("gunfire" , -23.25, 36.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("gunfire" , -18.75, 36.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("gunfire" , -18.75, 41.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			LAi_QuestDelay("plantation_fireworks2_D_high", 1.8);			
		break;
	
		case "plantation_fireworks2_D_high":
			CreateParticleSystem("sparkle_emitter6" , -21.0, 42.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_emitter6" , -21.0, 36.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_emitter6" , -24.0, 39.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_emitter6" , -18.0, 39.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E

			CreateParticleSystem("sparkle_emitter6" , -23.25, 41.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_emitter6" , -23.25, 36.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 36.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
			CreateParticleSystem("sparkle_emitter6" , -18.75, 41.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+	
		break;

//...........................................................................................................
		case "fireworks3_sound_start":
			LAi_QuestDelay("fireworks3_sound1", 0.01);
			LAi_QuestDelay("fireworks3_sound2", 1.5);
		//	LAi_QuestDelay("fireworks3_sound3", 3.6);
		break;

		case "fireworks3_sound1":
			PlaySound("OBJECTS\DUEL\rocket.wav");
		break;

		case "fireworks3_sound2":
			PlaySound("AMBIENT\LAND\fireworks3.wav");
		break;

		case "fireworks3_sound3":
			PlaySound("INTERFACE\fire_on.wav");
		break;
//...........................................................................................................

		//BLUE ANEMONE low
		case "plantation_fireworks3_A_low":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks3_B_low", 1.5);
		break;

		case "plantation_fireworks3_B_low":
			LAi_QuestDelay("plantation_fireworks3_1_low", 0.1);
			LAi_QuestDelay("plantation_fireworks3_2_low", 0.35);
			LAi_QuestDelay("plantation_fireworks3_3_low", 0.8);
			LAi_QuestDelay("plantation_fireworks3_4_low", 0.95);
			LAi_QuestDelay("plantation_fireworks3_5_low", 1.45);
			LAi_QuestDelay("plantation_fireworks3_6_low", 1.6);	
		break;

		case "plantation_fireworks3_1_low":
			CreateParticleSystem("artifact_short" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			CreateParticleSystem("sparkle_cloud3" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			CreateParticleSystem("blast" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
		break;
	
		case "plantation_fireworks3_2_low":
			CreateParticleSystem("artifact_short" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud3" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			
			CreateParticleSystem("blast" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
		break;

		case "plantation_fireworks3_3_low":
			CreateParticleSystem("artifact_short" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			CreateParticleSystem("sparkle_cloud3" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			
			CreateParticleSystem("blast" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
		break;

		case "plantation_fireworks3_4_low":
			CreateParticleSystem("artifact_short" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_cloud3" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			
			CreateParticleSystem("blast" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
		break;
	
		case "plantation_fireworks3_5_low":
			CreateParticleSystem("artifact_short" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud3" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			
			CreateParticleSystem("blast" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
		break;

		case "plantation_fireworks3_6_low":
			CreateParticleSystem("artifact_short" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("artifact_short" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("artifact_short" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("artifact_short" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+

			CreateParticleSystem("artifact_short" , -21.0, 28.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("artifact_short" , -18.0, 25.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			CreateParticleSystem("artifact_short" , -24.0, 25.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("artifact_short" , -23.25, 22.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("artifact_short" , -18.75, 27.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_cloud3" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud3" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_cloud3" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud3" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
		
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -23.25, 27.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("blast" , -21.0, 22.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -18.75, 22.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
		break;

//...........................................................................................................

		//BLUE ANEMONE center
		case "plantation_fireworks3_A_center":
			CreateParticleSystem("KNBcancloud2" , -31.0, 10.0, 56.0, 4.1, 4.0, 0.0, sti(20) );	//12

			LAi_QuestDelay("plantation_fireworks3_B_center", 1.5);
		break;

		case "plantation_fireworks3_B_center":
			LAi_QuestDelay("plantation_fireworks3_1_center", 0.1);
			LAi_QuestDelay("plantation_fireworks3_2_center", 0.35);
			LAi_QuestDelay("plantation_fireworks3_3_center", 0.8);
			LAi_QuestDelay("plantation_fireworks3_4_center", 0.95);
			LAi_QuestDelay("plantation_fireworks3_5_center", 1.45);
			LAi_QuestDelay("plantation_fireworks3_6_center", 1.6);	
		break;

		case "plantation_fireworks3_1_center":
			CreateParticleSystem("artifact_short" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			CreateParticleSystem("sparkle_cloud3" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
			
			CreateParticleSystem("blast" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+
		break;
	
		case "plantation_fireworks3_2_center":
			CreateParticleSystem("artifact_short" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("sparkle_cloud3" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			
			CreateParticleSystem("blast" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
		break;

		case "plantation_fireworks3_3_center":
			CreateParticleSystem("artifact_short" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			CreateParticleSystem("sparkle_cloud3" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			
			CreateParticleSystem("blast" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
		break;

		case "plantation_fireworks3_4_center":
			CreateParticleSystem("artifact_short" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("sparkle_cloud3" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			
			CreateParticleSystem("blast" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
		break;
	
		case "plantation_fireworks3_5_center":
			CreateParticleSystem("artifact_short" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("sparkle_cloud3" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			
			CreateParticleSystem("blast" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
		break;

		case "plantation_fireworks3_6_center":
			CreateParticleSystem("artifact_short" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("artifact_short" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("artifact_short" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("artifact_short" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+

			CreateParticleSystem("artifact_short" , -21.0, 35.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//N
			CreateParticleSystem("artifact_short" , -18.0, 32.0, 69.0, 5.1, 4.0, 0.0, sti(20) );	//E
			CreateParticleSystem("artifact_short" , -24.0, 32.0, 63.0, 5.1, 4.0, 0.0, sti(20) );	//W
			CreateParticleSystem("artifact_short" , -23.25, 29.75, 63.75, 5.1, 4.0, 0.0, sti(20) ); //SW+
			CreateParticleSystem("artifact_short" , -18.75, 34.25, 68.25, 5.1, 4.0, 0.0, sti(20) ); //NE+

			CreateParticleSystem("sparkle_cloud3" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("sparkle_cloud3" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("sparkle_cloud3" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("sparkle_cloud3" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+
		
			CreateParticleSystem("blast" , -21.0, 32.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//C
			CreateParticleSystem("blast" , -23.25, 34.25, 63.75, 5.1, 4.0, 0.0, sti(20) ); //NW+
			CreateParticleSystem("blast" , -21.0, 29.0, 66.0, 5.1, 4.0, 0.0, sti(20) );	//S
			CreateParticleSystem("blast" , -18.75, 29.75, 68.25, 5.1, 4.0, 0.0, sti(20) ); //SE+

		//	LAi_QuestDelay("plantation_fireworks3_7_center", 0.5);
		break;

		case "plantation_fireworks3_7_center":
			//RED SUN low
			CreateParticleSystem("artifact_short_red" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -21.0, 25.0, 66.0, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN high
			CreateParticleSystem("artifact_short_red" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -21.0, 39.0, 66.0, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN left
			CreateParticleSystem("artifact_short_red" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -28.0, 32.0, 59.0, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN right
			CreateParticleSystem("artifact_short_red" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -14.0, 32.0, 73.0, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN high_left
			CreateParticleSystem("artifact_short_red" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -25.9, 36.9, 61.1, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN high_right
			CreateParticleSystem("artifact_short_red" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -16.1, 36.9, 70.9, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN low_left
			CreateParticleSystem("artifact_short_red" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -25.9, 27.1, 61.1, 5.1, 4.0, 0.0, sti(20) );

			//RED SUN low_right
			CreateParticleSystem("artifact_short_red" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("blast" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("sparkle_cloud5" , -16.1, 27.1, 70.9, 5.1, 4.0, 0.0, sti(20) );
		break;

//...........................................................................................................
//JRH fw end
		case "plantation_fireworks_end":
			PlaySound("OBJECTS\ABORDAGE\abordage_wining.wav");

			LAi_QuestDelay("plantation_fireworks_end1", 3.0);
		break;

		case "plantation_fireworks_end1":
			PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
			ChangeCharacterAddressGroup(characterFromID("bessop_tower1"), "Bessop_plantation", "goto", "tower1_FW");
			ChangeCharacterAddressGroup(characterFromID("bessop_guard2"), "Bessop_plantation", "goto", "guard2_FW");

			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("plantation_fireworks_end2", 1.0);
		break;

		case "plantation_fireworks_end2":
			SetMusicAlarm("night_sneaking");
			locations[FindLocation("Bessop_plantation")].type = "night_sneaking";
		break;

		case "climb_bessop_fence":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box32");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "gate", 0.001);
			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 0.001;

			locations[FindLocation("Bessop_plantation")].id.label = "Bessop Plantation";
			//after any reload to this location

			DoQuickSave();

			pchar.quest.female_slave.win_condition.l1 = "locator";
			pchar.quest.female_slave.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.female_slave.win_condition.l1.locator_group = "goto";
			pchar.quest.female_slave.win_condition.l1.locator = "door_in";
			pchar.quest.female_slave.win_condition = "female_slave";

			pchar.quest.male_slaves.win_condition.l2 = "locator";
			pchar.quest.male_slaves.win_condition.l2.location = "Bessop_plantation";
			pchar.quest.male_slaves.win_condition.l2.locator_group = "goto";
			pchar.quest.male_slaves.win_condition.l2.locator = "goto45";
			pchar.quest.male_slaves.win_condition = "male_slaves";
		break;
//JRH stop react loop
		case "climb_bessop_fence_back":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box18");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard1"), "Bessop_plantation", "goto", "guard1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard2"), "Bessop_plantation", "goto", "guard2");

			if(CheckCharacterItem(Pchar,"BH_sketch")) Pchar.stop_plantation_loop = "yes";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "gate", 16.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;
		break;
	//------------------------------------------------------------------------------------------------------------------------
		case "female_slave":
	//LogIt("female_slave");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "barrack_in");

			ChangeCharacterAddressGroup(characterFromID("f_slave1"), "Bessop_plantation", "sit", "f_slave2");
			LAi_SetStayType(characterFromID("f_slave1"));

			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol4"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol6"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol7"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol8"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard2"), "none", "", "");

			LAi_QuestDelay("female_slave1", 0.5);
		break;

		case "female_slave1":
			pchar.quest.leave_female_slave.win_condition.l1 = "locator";
			pchar.quest.leave_female_slave.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.leave_female_slave.win_condition.l1.locator_group = "goto";
			pchar.quest.leave_female_slave.win_condition.l1.locator = "door_in";
			pchar.quest.leave_female_slave.win_condition = "leave_female_slave";
		break;
//pär door
		case "leave_female_slave":
	//LogIt("leave_female_slave");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "barrack_out");
			ChangeCharacterAddressGroup(characterFromID("f_slave1"), "none", "", "");
			
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol1"), "Bessop_plantation", "patrol", "patrol1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol2"), "Bessop_plantation", "patrol", "patrol14");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol3"), "Bessop_plantation", "patrol", "patrol18");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol4"), "Bessop_plantation", "patrol", "patrol16");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol5"), "Bessop_plantation", "goto", "patrol1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol6"), "Bessop_plantation", "patrol", "patrol6");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol7"), "Bessop_plantation", "patrol", "patrol9");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol8"), "Bessop_plantation", "patrol", "patrol5");
		//	LAi_SetCitizenType(characterFromID("Bessop_patrol5"));		//what for?
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard1"), "Bessop_plantation", "goto", "guard1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard2"), "Bessop_plantation", "goto", "guard2");
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorTurnToLocator(characterFromID("Bessop_guard2"), "goto", "look_FW");
			LAi_SetStayType(characterFromID("Bessop_guard1"));
			LAi_SetStayType(characterFromID("Bessop_guard2"));
	
		Pchar.quest.bessop_pchar_safe = "no";			//bugfix 2(2): when loading this quicksave guards always attacked immediately
			Pchar.quest.guard_attacking = "no";		//enable new reaction
		
			LAi_QuestDelay("leave_female_slave1", 0.5);
		break;

		case "leave_female_slave1":
			pchar.quest.female_slave.win_condition.l1 = "locator";
			pchar.quest.female_slave.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.female_slave.win_condition.l1.locator_group = "goto";
			pchar.quest.female_slave.win_condition.l1.locator = "door_in";
			pchar.quest.female_slave.win_condition = "female_slave";
		break;
	//------------------------------------------------------------------------------------------------------------------------
		case "male_slaves":
	//LogIt("male_slaves");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "barrack2_in");

			ChangeCharacterAddressGroup(characterFromID("m_slave1"), "Bessop_plantation", "sit", "m_slave1");
			LAi_SetLayType(characterFromID("m_slave1"));
			ChangeCharacterAddressGroup(characterFromID("m_slave2"), "Bessop_plantation", "sit", "m_slave2");
			LAi_SetLayType(characterFromID("m_slave2"));
			ChangeCharacterAddressGroup(characterFromID("m_slave3"), "Bessop_plantation", "sit", "m_slave3");
			LAi_SetLayType(characterFromID("m_slave3"));

			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol4"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol6"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol7"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol8"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard2"), "none", "", "");

			LAi_QuestDelay("male_slaves1", 0.5);
		break;

		case "male_slaves1":
			pchar.quest.leave_male_slaves.win_condition.l1 = "locator";
			pchar.quest.leave_male_slaves.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.leave_male_slaves.win_condition.l1.locator_group = "goto";
			pchar.quest.leave_male_slaves.win_condition.l1.locator = "goto45";
			pchar.quest.leave_male_slaves.win_condition = "leave_male_slaves";
		break;
		
		case "leave_male_slaves":
	//LogIt("leave_male_slaves");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "barrack2_out");
			ChangeCharacterAddressGroup(characterFromID("m_slave1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("m_slave2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("m_slave3"), "none", "", "");
			
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol1"), "Bessop_plantation", "patrol", "patrol1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol2"), "Bessop_plantation", "patrol", "patrol14");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol3"), "Bessop_plantation", "patrol", "patrol18");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol4"), "Bessop_plantation", "patrol", "patrol16");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol5"), "Bessop_plantation", "goto", "patrol1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol6"), "Bessop_plantation", "patrol", "patrol6");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol7"), "Bessop_plantation", "patrol", "patrol9");
			ChangeCharacterAddressGroup(characterFromID("Bessop_patrol8"), "Bessop_plantation", "patrol", "patrol5");
		//	LAi_SetCitizenType(characterFromID("Bessop_patrol5"));		//what for?
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard1"), "Bessop_plantation", "goto", "guard1");
			ChangeCharacterAddressGroup(characterFromID("Bessop_guard2"), "Bessop_plantation", "goto", "guard2");
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorTurnToLocator(characterFromID("Bessop_guard2"), "goto", "look_FW");
			LAi_SetStayType(characterFromID("Bessop_guard1"));
			LAi_SetStayType(characterFromID("Bessop_guard2"));
			Pchar.quest.guard_attacking = "no";		//enable new reaction
		
			LAi_QuestDelay("leave_male_slaves1", 0.5);
		break;

		case "leave_male_slaves1":
			pchar.quest.male_slaves.win_condition.l1 = "locator";
			pchar.quest.male_slaves.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.male_slaves.win_condition.l1.locator_group = "goto";
			pchar.quest.male_slaves.win_condition.l1.locator = "goto45";
			pchar.quest.male_slaves.win_condition = "male_slaves";
		break;
	//------------------------------------------------------------------------------------------------------------------------
		case "bessop_box2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload9");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box20":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		break;

		case "bessop_box22":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box40");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;
	
		case "bessop_box33":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box37");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;		
	
		case "bessop_box38":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box43");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box39":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "patrol", "patrol11");	

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box39A":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box40":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box44");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;
	
		case "bessop_box42":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box29");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;
	
		case "bessop_box43":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box45");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box43_B":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look40_B");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box44":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box41");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box44_B":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box40");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box50":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sneak5");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "bessop_box58":
			PlaySound("PEOPLE\recoil.wav");
			Pchar.quest.bessop_pchar_safe = "no";
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box59");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box59":
			PlaySound("PEOPLE\grass_turn.wav");
			Pchar.quest.bessop_pchar_safe = "yes";
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box58_B");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box67":
			Pchar.quest.bessop_pchar_safe = "no";
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box68");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box68":
			Pchar.quest.bessop_pchar_safe = "no";
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box67");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "bessop_box70":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box72");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;
	
		case "bessop_box80":
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box73");

			LAi_QuestDelay("bessop_box80_turn", 0.1);
		break;

		case "bessop_box80_turn":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box34");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "Bessop_tower2_alarm":
			if(CheckAttribute(Pchar,"quest.tower2") && Pchar.quest.tower2 == "yes") return;
			//to avoid double shouting etc

			Pchar.quest.tower2 = "yes";
			PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");
			
			LAi_QuestDelay("Bessop_tower2_alarmA", 1.0);
		break;

		case "Bessop_tower2_alarmA":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "tower2");
			
			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("plantation_patrol_attacking", 1.0);
		break;

		case "climb_bessop_inner_fence":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "box22");

			LAi_QuestDelay("climb_bessop_roofs", 1.0);
		break;

		case "climb_bessop_roofs":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto10");
			
			LAi_QuestDelay("pchar_playertype", 1.0);
		break;	


		case "plantation_patrol_reacting":
			//started from box23 SL_utils.c

			if(CheckAttribute(Pchar,"stop_plantation_loop") && Pchar.stop_plantation_loop == "yes") return;			

			GetCharacterPos(Pchar, &u, &v, &w);

			float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10;

			GetCharacterPos(characterFromID("Bessop_patrol1"), &x1, &y1, &z1);
			GetCharacterPos(characterFromID("Bessop_patrol2"), &x2, &y2, &z2);
			GetCharacterPos(characterFromID("Bessop_patrol3"), &x3, &y3, &z3);
			GetCharacterPos(characterFromID("Bessop_patrol4"), &x4, &y4, &z4);
			GetCharacterPos(characterFromID("Bessop_patrol5"), &x5, &y5, &z5);
			GetCharacterPos(characterFromID("Bessop_patrol6"), &x6, &y6, &z6);
			GetCharacterPos(characterFromID("Bessop_patrol7"), &x7, &y7, &z7);
			GetCharacterPos(characterFromID("Bessop_patrol8"), &x8, &y8, &z8);
			GetCharacterPos(characterFromID("Bessop_guard1"), &x9, &y9, &z9);
			GetCharacterPos(characterFromID("Bessop_guard2"), &x10, &y10, &z10);
			
			float dist_p1 = GetDistance2D(x1, z1, u, w);
			float dist_p2 = GetDistance2D(x2, z2, u, w);
			float dist_p3 = GetDistance2D(x3, z3, u, w);
			float dist_p4 = GetDistance2D(x4, z4, u, w);
			float dist_p5 = GetDistance2D(x5, z5, u, w);
			float dist_p6 = GetDistance2D(x6, z6, u, w);
			float dist_p7 = GetDistance2D(x7, z7, u, w);
			float dist_p8 = GetDistance2D(x8, z8, u, w);
			float dist_p9 = GetDistance2D(x9, z9, u, w);
			float dist_p10 = GetDistance2D(x10, z10, u, w);

			if(CheckAttribute(Pchar,"quest.bessop_pchar_safe") && Pchar.quest.bessop_pchar_safe == "yes")
			{
				//they don't attack you even if they're close
				InterfaceStates.Buttons.Save.enable = 1;	
			}
			else
			{
				if(Pchar.location == "Bessop_storeroom1" || Pchar.location == "Bessop_storeroom2"
				||  Pchar.location == "Bessop_storeroom3" || Pchar.location == "Bessop_storeroom4" 
				||  Pchar.location == "Bessop_tavern")
				{
					InterfaceStates.Buttons.Save.enable = 1;
					//Pchar was "detected" in here strange enough, tavern too!
				}
				else
				{
					InterfaceStates.Buttons.Save.enable = 0;

					if(dist_p1 < 3.0 || dist_p2 < 3.0 || dist_p3 < 3.0 || dist_p4 < 3.0 || dist_p5 < 3.0 || dist_p6 < 3.0 
					|| dist_p7 < 3.0 || dist_p8 < 3.0) 
					{
						LAi_QuestDelay("plantation_patrol_attacking", 0.01);
						//return;							//stops loop
						//OBS loop continues now to enable save in houses
					}

					if(dist_p9 < 3.0 || dist_p10 < 3.0) 
					{
						//stay at the gate if pchar not very close to them
						LAi_ActorAttack(CharacterFromID("Bessop_guard1"), Pchar, "");
						LAi_ActorAttack(CharacterFromID("Bessop_guard2"), Pchar, "");

						LAi_QuestDelay("plantation_guard_attacking", 0.01);
					}
				}
			} 
			
			LAi_QuestDelay("plantation_patrol_reacting", 1.0);		//loop			
		break;
//JRH testing alarm
		case "plantation_patrol_attacking":
			if(CheckAttribute(Pchar,"quest.patrol_attacking") && Pchar.quest.patrol_attacking == "yes") return;
			//to avoid double attacks

			Pchar.quest.patrol_attacking = "yes";
			PlaySound("AMBIENT\TOWN\Alarm.wav");

			LAi_SetActorType(characterFromID("Bessop_patrol1"));
			LAi_SetActorType(characterFromID("Bessop_patrol2"));
			LAi_SetActorType(characterFromID("Bessop_patrol3"));
			LAi_SetActorType(characterFromID("Bessop_patrol4"));
			LAi_SetActorType(characterFromID("Bessop_patrol5"));
			LAi_SetActorType(characterFromID("Bessop_patrol6"));
			LAi_SetActorType(characterFromID("Bessop_patrol7"));
			LAi_SetActorType(characterFromID("Bessop_patrol8"));
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorAttack(CharacterFromID("Bessop_patrol1"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol2"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol3"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol4"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol5"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol6"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol7"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol8"), Pchar, "");
			if(dist_p9 < 3.0 || dist_p10 < 3.0) 
			{
				//stay at the gate if pchar not very close to them
				LAi_ActorAttack(CharacterFromID("Bessop_guard1"), Pchar, "");
				LAi_ActorAttack(CharacterFromID("Bessop_guard2"), Pchar, "");
			}
			LAi_SetActorType(CharacterFromID("Bessop_tower1"));
			LAi_ActorTurnToLocator(CharacterFromID("Bessop_tower1"), "goto", "goto48");
						
			LAi_QuestDelay("bessop_plantation_no_reinc", 1.0);		
		break;

		case "plantation_guard_attacking":
			if(CheckAttribute(Pchar,"quest.guard_attacking") && Pchar.quest.guard_attacking == "yes") return;
			//to avoid double attacks

			Pchar.quest.guard_attacking = "yes";
			PlaySound("AMBIENT\TOWN\Alarm.wav");

			LAi_SetActorType(characterFromID("Bessop_patrol1"));
			LAi_SetActorType(characterFromID("Bessop_patrol2"));
			LAi_SetActorType(characterFromID("Bessop_patrol3"));
			LAi_SetActorType(characterFromID("Bessop_patrol4"));
			LAi_SetActorType(characterFromID("Bessop_patrol5"));
			LAi_SetActorType(characterFromID("Bessop_patrol6"));
			LAi_SetActorType(characterFromID("Bessop_patrol7"));
			LAi_SetActorType(characterFromID("Bessop_patrol8"));
			LAi_SetActorType(characterFromID("Bessop_guard1"));
			LAi_SetActorType(characterFromID("Bessop_guard2"));
			LAi_ActorAttack(CharacterFromID("Bessop_patrol1"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol2"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol3"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol4"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol5"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol6"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol7"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_patrol8"), Pchar, "");
			
			LAi_ActorAttack(CharacterFromID("Bessop_guard1"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("Bessop_guard2"), Pchar, "");
			
			LAi_SetActorType(CharacterFromID("Bessop_tower1"));
			LAi_ActorTurnToLocator(CharacterFromID("Bessop_tower1"), "goto", "goto48");
						
			LAi_QuestDelay("bessop_plantation_no_reinc", 1.0);		
		break;

		case "bessop_hide_from_patrol":
			//from guard_dialog (patrol)

			LAi_QuestDelay("pchar_playertype", 3.0);
			LAi_QuestDelay("pchar_puh", 4.0);
			LAi_QuestDelay("bessop_hide_from_patrol1", 10.0);
		break;

		case "bessop_hide_from_patrol1":
			LAi_SetCitizenType(characterFromID("Bessop_patrol1"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol2"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol3"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol4"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol5"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol6"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol7"));
			LAi_SetCitizenType(characterFromID("Bessop_patrol8"));		
		break;

		case "trade_med_bag":
			//from bessop slave_dialog

			LAi_SetActorType(characterFromID("f_slave1"));
			LAi_ActorTurnToCharacter(characterFromID("f_slave1"), PChar);

			PlaySound("PEOPLE\clothes1.wav");
			RemoveCharacterEquip(Pchar, OUTFIT_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, DOCUMENT_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "med_bag1_obj");
			TakeItemFromCharacter(Pchar, "med_bag1_doc_NO");
			TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
			TakeItemFromCharacter(Pchar, "med_bag1_out");
			TakeItemFromCharacter(Pchar, "med_bag2_obj");
			TakeItemFromCharacter(Pchar, "med_bag2_doc");
			TakeItemFromCharacter(Pchar, "med_bag2_out");

			LAi_QuestDelay("trade_med_bag1", 2.0);
		break;

		case "trade_med_bag1":
			PlaySound("VOICE\ENGLISH\black_witch_laugh.wav");

			LAi_QuestDelay("hostel_sketch4", 2.0);
		break;

		case "hostel_sketch4":
			Characters[GetCharacterIndex("f_slave1")].dialog.CurrentNode  = "hostel_sketch4";
			LAi_SetActorType(characterFromID("f_slave1"));
			LAi_ActorTurnToCharacter(characterFromID("f_slave1"), PChar);
			LAi_ActorDialogNow(characterFromID("f_slave1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("f_slave1"));
		break;

		case "bird_backside":
			//from bessop slave_dialog

			TakeItemFromCharacter(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "bird_sketch_doc");

			//open to swamp now
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box3", 1.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;

			LAi_QuestDelay("bird_backside1", 1.0);
		break;

		case "bird_backside1":
			if(CheckCharacterItem(Pchar,"bird_backside"))
			{
				LAi_QuestDelay("bird_backside2", 1.0);
				return;
			}
			else
			{
				LAi_QuestDelay("bird_backside1", 1.0);//loop check
			}
		break;

		case "bird_backside2":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "bird_backside";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "bird_backside_done":
			//from self_dialog

			PlaySound("INTERFACE\paper_small.wav");
			TakeItemFromCharacter(Pchar, "bird_backside");
			TakeItemFromCharacter(Pchar, "inkpen");

			LAi_QuestDelay("witch_is_drawing", 1.0);
		break;
			
		case "witch_is_drawing":
			PlaySound("VOICE\ENGLISH\black_witch_ahh.wav");

			LAi_QuestDelay("witch_is_drawing1", 1.0);
		break;

		case "witch_is_drawing1":
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("AMBIENT\RESIDENCE\some1.wav");

			LAi_QuestDelay("witch_is_drawing2", 4.0);
		break;

		case "witch_is_drawing2":
			Characters[GetCharacterIndex("f_slave1")].dialog.CurrentNode  = "hostel_sketch11";
			LAi_SetActorType(characterFromID("f_slave1"));
			LAi_ActorTurnToCharacter(characterFromID("f_slave1"), PChar);
			LAi_ActorDialogNow(characterFromID("f_slave1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("f_slave1"));
		break;
//pär save
		case "witch_is_drawing_done":
			PlaySound("INTERFACE\paper_small.wav");
			GiveItem2Character(Pchar, "BH_sketch");
			LAi_SetStayType(characterFromID("f_slave1"));
			LAi_SetPlayerType(pchar);

		Pchar.quest.bessop_pchar_safe = "yes";				//bugfix 1(2): when loading this quicksave guards always attacked immediately
		
			InterfaceStates.Buttons.Save.enable = 1;
			DoQuickSave();
			InterfaceStates.Buttons.Save.enable = 0;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 0.001);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box15 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 0.001);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box17 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box18", 0.001);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box18 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box91", 0.7);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box91 = 0.7;
	
			pchar.quest.Jup_after_plantation.win_condition.l1 = "locator";
			pchar.quest.Jup_after_plantation.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Jup_after_plantation.win_condition.l1.locator_group = "goto";
			pchar.quest.Jup_after_plantation.win_condition.l1.locator = "goto26";
			pchar.quest.Jup_after_plantation.win_condition = "Jup_after_plantation";
		break;
//JRH morning after plantation sneak
		case "Jup_after_plantation":
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "goto", "jup_standby");
			LAi_SetOfficerType(characterFromID("Jupiter"));
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			Pchar.quest.Jupiter_sits = "no";		//reset to neutral phrase
			Pchar.quest.plank_gate = "no";			//reset to neutral phrase
			SetCurrentTime(6.00, 0);
			DeleteQuestHeader("The_plantation");
			locations[FindLocation("Bessop_plantation")].type = "Plantation";

			LAi_QuestDelay("start_maroon_part", 0.1);	
		break;


		case "start_maroon_part":
			Pchar.quest.mar_cav_from_plant = "open";		
			Pchar.quest.mar_cav_to_bridge = "closed";		
		//	Pchar.quest.mar_cav_to_hideout = "open";		//later		
			Pchar.quest.barrelA = "filled";	
			Pchar.quest.tapA = "closed";
			Pchar.quest.first_lever_pickup = "yes";

			LAi_QuestDelay("bridge_broken_A", 0.1);						
			LAi_QuestDelay("bridge_broken_B", 0.1);						
			LAi_QuestDelay("ch_shore_bars", 0.1);						
			LAi_QuestDelay("maroon_cavern_steplock", 0.1);					
			LAi_QuestDelay("maroon_hideout_boxback", 0.1);

			SetCharacterShipLocation(characterFromID("maroon1"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon2"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon3"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon4"), "Maroon_cavern");

			pchar.quest.box_gibbet_rope.win_condition.l1 = "location";
			pchar.quest.box_gibbet_rope.win_condition.l1.location = "swamp_loghouse";
			pchar.quest.box_gibbet_rope.win_condition = "box_gibbet_rope";

			pchar.quest.box_bladelever.win_condition.l2 = "location";
			pchar.quest.box_bladelever.win_condition.l2.location = "maroon_cavern";
			pchar.quest.box_bladelever.win_condition = "box_bladelever";

			pchar.quest.maroon_ohoh.win_condition.l3 = "locator";
			pchar.quest.maroon_ohoh.win_condition.l3.location = "Charleston_passage";
			pchar.quest.maroon_ohoh.win_condition.l3.locator_group = "goto";
			pchar.quest.maroon_ohoh.win_condition.l3.locator = "maroon_ohoh";
			pchar.quest.maroon_ohoh.win_condition = "maroon_ohoh";
		break;

		case "box_gibbet_rope":
			locations[FindLocation(Pchar.location)].box1.items.gibbet_rope = 1;

			LAi_QuestDelay("gibbet_rope_check", 0.1);
		break;

		case "gibbet_rope_check":
			if(CheckCharacterItem(Pchar,"gibbet_rope"))
			{
				PlaySound("PEOPLE\clothes1.wav");
				SetModel(Pchar, "William Legrand2", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
				return;
			}
			else
			{
				LAi_QuestDelay("gibbet_rope_check", 1.0);//loop check
			}
		break;

		case "box_bladelever":
			locations[FindLocation(Pchar.location)].box1.items.corkscrew = 1;
			locations[FindLocation(Pchar.location)].box3.items.bladelever = 1;

			LAi_QuestDelay("bladelever_check", 0.1);
		break;

		case "bladelever_check":
			if(CheckCharacterItem(Pchar,"bladelever"))
			{
				if(CheckCharacterItem(Pchar,"bladeladder2"))
				{
					if(!IsEquipCharacterByItem(Pchar, "bladeladder2")) 
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladeladder2");
					}
				}
				else
				{
					PlaySound("INTERFACE\button1.wav");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladelever");
				} 

				return;
			}
			else
			{
				LAi_QuestDelay("bladelever_check", 1.0);//loop check
			}
		break;

		case "maroon_ohoh":
			LAi_SetStayType(Pchar);
			LAi_QuestDelay("pchar_ohoh", 0.1);

			LAi_QuestDelay("maroon_ohoh1", 1.0);
		break;

		case "maroon_ohoh1":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			LAi_QuestDelay("pchar_playertype", 1.0);

			pchar.quest.maroon_ohoh2.win_condition.l1 = "locator";
			pchar.quest.maroon_ohoh2.win_condition.l1.location = "Charleston_passage";
			pchar.quest.maroon_ohoh2.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_ohoh2.win_condition.l1.locator = "weather";
			pchar.quest.maroon_ohoh2.win_condition = "maroon_ohoh2";
		break;

		case "maroon_ohoh2":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		break;

		//....................................................

		case "open_barrelA":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box11", "open_barrelA_2");
		break;

		case "open_barrelA_2":
			GiveItem2Character(Pchar, "cork");
			Pchar.quest.tapA_activated = "no";
			Pchar.quest.tapA = "open";
			Pchar.quest.barrelA = "empty";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "open_barrelB":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box13", "open_barrelB_2");
		break;

		case "open_barrelB_2":
			GiveItem2Character(Pchar, "cork");
			Pchar.quest.tapB_activated = "no";
			Pchar.quest.tapB = "open";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "open_barrelC":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box12", "open_barrelC_2");
		break;

		case "open_barrelC_2":
			GiveItem2Character(Pchar, "cork");
			Pchar.quest.tapC_activated = "no";
			Pchar.quest.tapC = "open";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "close_barrelA":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box11", "close_barrelA_2");
		break;

		case "close_barrelA_2":
			TakeItemFromCharacter(Pchar, "cork");
			Pchar.quest.tapA_activated = "no";
			Pchar.quest.tapA = "closed";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "close_barrelB":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box13", "close_barrelB_2");
		break;

		case "close_barrelB_2":
			TakeItemFromCharacter(Pchar, "cork");
			Pchar.quest.tapB_activated = "no";
			Pchar.quest.tapB = "closed";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "close_barrelC":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box12", "close_barrelC_2");
		break;

		case "close_barrelC_2":
			TakeItemFromCharacter(Pchar, "cork");
			Pchar.quest.tapC_activated = "no";
			Pchar.quest.tapC = "closed";
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "push_barrelA":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box9", "push_barrelA_2");
		break;

		case "push_barrelA_2":
			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box9 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 0.0001);
			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box10 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box10", 0.5);

			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box11 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box11", 0.0001);
			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box13 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 0.5);
			
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box12");

			LAi_QuestDelay("Pchar_playertype", 0.5);
			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
			LAi_QuestDelay("barrel_roll", 0.5);
		break;

		case "push_barrelB":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box10", "push_barrelB_2");
		break;

		case "push_barrelB_2":
			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box10 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box10", 0.0001);
		//	Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box10 = 0.5;
		//	SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box10", 0.5);

			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box13 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 0.0001);
			Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box12 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box12", 0.5);
			
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box12");

			LAi_QuestDelay("Pchar_playertype", 0.5);
			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
			LAi_QuestDelay("barrel_roll", 0.5);
		break;

		case "barrel_roll":
			PlaySound("INTERFACE\barrel_roll.wav");
		break;

		case "mar_cav_take_ladder_bottom":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "goto", "box14", "mar_cav_take_ladder_bottom1");
		break;

		case "mar_cav_take_ladder_bottom1":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";

			LAi_QuestDelay("Jup_to_officer_reload5_1", 0.1);
		break;

		case "Jup_to_officer_reload5_1":
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Maroon_Cavern", "officers", "reload5_1");
			LAi_SetOfficerType(characterFromID("Jupiter"));
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
		break;	

		//....................................................

		case "mar_cav_place_ladder_rope":
			Locations[FindLocation("Maroon_Cavern")].image = "";
			DoQuestReloadToLocation("Maroon_Cavern", "reload", "reload2", "mar_cav_place_ladder_rope1");
		break;

		case "mar_cav_place_ladder_rope1":
			if(Locations[FindLocation("Maroon_Cavern")].models.always.l6 == "ladder_rope")
			{
				PlaySound("OBJECTS\DUEL\man_attack6.wav");
			}
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Maroon_Cavern")].image = "Inside_cavernMedium.tga";
		break;	

		case "pull_up_ladder_from_cavern":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","And now the Ladder!"));
		break;

		//....................................................

		case "ch_shore_turn_to_box24":
			Pchar.quest.ch_shore_turn_to_box24 = "yes";
		break;

		case "ch_shore_turn_to_look_b24":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_b24");

			LAi_QuestDelay("Pchar_playertype", 1.0);
		break;

		case "ch_shore_turn_to_look_back_b16":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_back_b16");

			LAi_QuestDelay("ch_shore_turn_to_look_back_b16_A", 1.5);
		break;

		case "ch_shore_turn_to_look_back_b16_A":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.ch_shore_direction = "plantation";
		break;

		case "ch_shore_return_to_hatch":
			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box16");
			Pchar.quest.ch_shore_direction = "plantation";

			LAi_QuestDelay("Pchar_playertype", 0.5);
		break;

		case "ch_shore_turn_to_look_b18":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_b18");

			LAi_QuestDelay("Pchar_playertype", 1.5);
		break;

		case "ch_shore_turn_to_box18":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box18");
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			LAi_QuestDelay("Pchar_playertype", 1.0);
		break;

		case "ch_shore_place_ladder_gibbet":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box16", "ch_shore_place_ladder_gibbet1");
		break;

		case "ch_shore_place_ladder_gibbet1":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			LAi_QuestDelay("ch_shore_turn_to_look_b18", 1.0);
		break;	

		case "ch_shore_place_rope_gibbet":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box19", "ch_shore_place_rope_gibbet1");
		break;	

		case "ch_shore_place_rope_gibbet1":
			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box19");
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			Pchar.quest.box_action = "no";

			LAi_QuestDelay("ch_shore_turn_to_look_b18", 0.5);
		break;

		case "ch_shore_take_ladder_gibbet":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box19", "ch_shore_turn_to_box18");
		break;	

		case "ch_shore_place_ladder_rope":
			LAi_SetSitType(Pchar);
			
			LAi_QuestDelay("pchar_playertype", 2.0);
			LAi_QuestDelay("ch_shore_place_ladder_rope1", 2.0);
		break;	

		case "ch_shore_place_ladder_rope1":
			PlaySound("PEOPLE\creak2.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladeladder2");
			Locations[FindLocation(Pchar.location)].models.always.l9 = "ladder_rope";
			Pchar.quest.ch_shore_direction = "BH";

			LAi_QuestDelay("ch_shore_place_ladder_rope2", 0.5);
		break;

		case "ch_shore_place_ladder_rope2":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box19", "ch_shore_place_ladder_rope3");
		break;

		case "ch_shore_place_ladder_rope3":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			Pchar.quest.box_action = "no";

			LAi_QuestDelay("ch_shore_turn_to_look_b18", 0.1);
		break;				

		//....................................................

		case "mar_hideout_turn_to_box3":
			Pchar.quest.mar_hideout_turn_to_box3 = "yes";
		break;
			

		//....................................................

		case "bridge_broken_A":
			pchar.quest.bridge_broken_A1.win_condition.l1 = "locator";
			pchar.quest.bridge_broken_A1.win_condition.l1.location = "Charleston_shore";
			pchar.quest.bridge_broken_A1.win_condition.l1.locator_group = "goto";
			pchar.quest.bridge_broken_A1.win_condition.l1.locator = "fall1";
			pchar.quest.bridge_broken_A1.win_condition = "bridge_broken_A1";
		break;

		case "bridge_broken_A1":
			if(Locations[FindLocation(Pchar.location)].models.always.l6 == "plank2A")
			{
				PlaySound("PEOPLE\place_planks.wav");
			
				LAi_QuestDelay("bridge_broken_A", 1.0);
			}
			else
			{
				LAi_SetStayType(Pchar);
				PlaySound("PEOPLE\creak2.wav");
			
				LAi_QuestDelay("bridge_broken_A2", 1.0);
			}
		break;
	
		case "bridge_broken_A2":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "goto23");
		
			if(CheckCharacterItem(Pchar,"bladeplank2"))
			{
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box30", 0.5);
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box30 = 0.5;

				LAi_QuestDelay("bridge_broken_A", 0.1);
				return;
			}
			else LAi_QuestDelay("bridge_broken_A3", 0.5);
		break;

		case "bridge_broken_A3":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"The bridge is rotten, I'll have to fix it somehow."));
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		
			LAi_QuestDelay("bridge_broken_A4", 0.5);
		break;

		case "bridge_broken_A4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
		
			LAi_QuestDelay("bridge_broken_A", 1.0);
			LAi_QuestDelay("Pchar_playertype", 1.0);
		break;

		//....................................................

		case "bridge_broken_B":
			pchar.quest.bridge_broken_B1.win_condition.l1 = "locator";
			pchar.quest.bridge_broken_B1.win_condition.l1.location = "Charleston_shore";
			pchar.quest.bridge_broken_B1.win_condition.l1.locator_group = "goto";
			pchar.quest.bridge_broken_B1.win_condition.l1.locator = "fall2";
			pchar.quest.bridge_broken_B1.win_condition = "bridge_broken_B1";
		break;

		case "bridge_broken_B1":
			if(Locations[FindLocation(Pchar.location)].models.always.l7 == "plank2B")
			{
				PlaySound("PEOPLE\place_planks.wav");
			
				LAi_QuestDelay("bridge_broken_B", 1.0);
			}
			else
			{
				LAi_SetStayType(Pchar);
				PlaySound("PEOPLE\creak2.wav");
			
				LAi_QuestDelay("bridge_broken_B2", 1.0);
			}
		break;

		case "bridge_broken_B2":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "goto24");
		/*
			if(CheckCharacterItem(Pchar,"bladeplank2"))
			{
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box31", 0.5);
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box31 = 0.5;

				LAi_QuestDelay("bridge_broken_B", 0.1);
				return;
			}
			else LAi_QuestDelay("bridge_broken_B3", 0.5);
		*/

	LAi_QuestDelay("bridge_broken_B3", 0.5);
		break;

		case "bridge_broken_B3":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"The bridge is rotten, I have to be careful."));
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		
			LAi_QuestDelay("bridge_broken_B4", 0.5);
		break;

		case "bridge_broken_B4":
			LAi_SetActorType(Pchar);
		//	LAi_ActorTurnToLocator(Pchar, "goto", "look1");
			LAi_ActorTurnToLocator(Pchar, "officers", "reload3_1");
		
			LAi_QuestDelay("bridge_broken_B", 1.5);
			LAi_QuestDelay("Pchar_playertype", 1.5);
		break;
	
		//....................................................

		case "to_rope1":
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box26");
			PlaySound("PEOPLE\recoil.wav");

		//	LAi_QuestDelay("Pchar_playertype", 0.25);
		break;

		case "to_rope2":
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box27");
			PlaySound("PEOPLE\recoil.wav");

		//	LAi_QuestDelay("Pchar_playertype", 0.25);
		break;

		case "to_rope3":
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box28");
			PlaySound("PEOPLE\recoil.wav");

		//	LAi_QuestDelay("Pchar_playertype", 0.25);
		break;

		//....................................................

		case "ready_to_remove_cave_planks":
			if(LAi_IsFightMode(Pchar))
			{
				LAi_SetPlayerType(Pchar);
				LAi_SetFightMode(PChar, false);
			}

			LAi_QuestDelay("ready_to_remove_cave_planks1", 1.0);
		break;

		case "ready_to_remove_cave_planks1":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box29", 0.0001);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem12", 2.0);

			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.randitem.randitem12 = 2.0;

			LAi_QuestDelay("ready_to_remove_cave_planks2", 0.01);
		break;

		case "ready_to_remove_cave_planks2":
			if(CheckCharacterItem(Pchar,"plank1_long"))
			{
				PlaySound("PEOPLE\wood1.wav");
				TakeItemFromCharacter(Pchar, "plank1_long" );
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				GiveItem2Character(Pchar, "bladeplank2");
				EquipCharacterbyItem(Pchar, "bladeplank2");

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem12", 0.0001);
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem12", 0.0001);
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box40", 1.5);
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;
				Pchar.quest.mar_cav_to_bridge = "open";
			}
			else
			{
				LAi_QuestDelay("ready_to_remove_cave_planks2", 1.0);//loop check
			}
		break;
	
		case "ch_shore_bars":
			LAi_SetPlayerType(Pchar);

			pchar.quest.ch_shore_bars.win_condition.l1 = "locator";
			pchar.quest.ch_shore_bars.win_condition.l1.location = "Charleston_shore";
			pchar.quest.ch_shore_bars.win_condition.l1.locator_group = "goto";
			pchar.quest.ch_shore_bars.win_condition.l1.locator = "stop_bars";
			pchar.quest.ch_shore_bars.win_condition = "ch_shore_bars1";
		break;

		case "ch_shore_bars1":
			if(Locations[FindLocation(Pchar.location)].models.always.l4 == "bars_down")
			{
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetStayType(Pchar);

				if(CheckAttribute(Pchar,"quest.gate_other_side") && Pchar.quest.gate_other_side  == "yes")
				{
					ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "other_side");
				}
				else ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "bars_back");
			}

			LAi_QuestDelay("ch_shore_bars", 0.5);
		break;
	
		//....................................................

		case "ch_shore_place_lever_box34":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box34", "ch_shore_loading_image_back");
		break;

		case "ch_shore_place_lever_box37":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box37", "ch_shore_after_box37");
		break;

		case "ch_shore_loading_image_back":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
		break;

		case "ch_shore_after_box37":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload4_1");
			LAi_SetOfficerType(characterFromID("Jupiter"));
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
		break;

		case "ch_shore_lever_missing":
			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box32");

			LAi_QuestDelay("Pchar_playertype", 0.5);
		break;

		case "ch_shore_lever_down_box34":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box34", "ch_shore_bars_up");
		break;

		case "ch_shore_lever_down_box37":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box37", "ch_shore_bars_up");
		break;

		case "ch_shore_bars_up":
			PlaySound("INTERFACE\girder_open.wav");
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			if(Locations[FindLocation("Charleston_shore")].models.always.l7 == "plank_ground")
			{
				LAi_QuestDelay("ch_shore_bars_up1", 1.5);
			}

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
			{
				//LAi_SetStayType(characterFromID("Jupiter"));
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");
				LAi_SetStayType(characterFromID("Jupiter"));
			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload4_1");
				LAi_SetOfficerType(characterFromID("Jupiter"));
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}

			LAi_QuestDelay("ch_shore_jump_down_box37", 1.0);
		
			pchar.quest.falling_lever.win_condition.l1 = "locator";
			pchar.quest.falling_lever.win_condition.l1.location = "Charleston_shore";
			pchar.quest.falling_lever.win_condition.l1.locator_group = "goto";
			pchar.quest.falling_lever.win_condition.l1.locator = "falling_lever";
			pchar.quest.falling_lever.win_condition = "falling_lever";	
		break;
	
		case "ch_shore_bars_up1":
			PlaySound("PEOPLE\place_planks.wav");
		break;

		case "ch_shore_lever_up_box37":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box37", "ch_shore_bars_down");
		break;

		case "ch_shore_bars_down":
			PlaySound("INTERFACE\girder_close.wav");
			CreateParticleSystemX("blast_dirt", -9.1, 13.4, -30.3, -9.1, 13.4, -30.3, 10);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");
				LAi_SetStayType(characterFromID("Jupiter"));
			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload4_1");
				LAi_SetOfficerType(characterFromID("Jupiter"));
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}

			LAi_QuestDelay("ch_shore_jump_down_box37", 1.0);	
		break;

		case "ch_shore_jump_down_box37":
			//jump down!

			PlaySound("PEOPLE\jump.wav");
			LAi_SetSitType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "box32");

			LAi_QuestDelay("Pchar_playertype", 0.5);
		break;

		case "falling_lever":
			if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
			{
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");
				LAi_SetStayType(characterFromID("Jupiter"));
			}	

			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\metal_fall.wav");

			LAi_QuestDelay("falling_lever1", 1.5);
		break;

		case "falling_lever1":
			if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
			{
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			}
			else PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
			
			LAi_QuestDelay("falling_lever2", 1.0);
		break;

		case "falling_lever2":
			if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
			{
				Locations[FindLocation(Pchar.location)].models.always.l4 = "bars_stuck";
				Locations[FindLocation(Pchar.location)].models.always.l7 = "plank_gate";
				RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("Jupiter"), "bladeplank2" );
				Pchar.quest.plank_gate = "";

				Locations[FindLocation(Pchar.location)].models.always.l8 = "";
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box35", 0.0001);
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.0001;
				Characters[GetCharacterIndex("Moultrie_guard10")].Ship.Type = "obj_raft2";

				Locations[FindLocation("Charleston_shore")].MaxSeaHeight = 0.1;
			}
			else
			{
				Locations[FindLocation(Pchar.location)].models.always.l4 = "bars_down";	
				Locations[FindLocation(Pchar.location)].models.always.l8 = "lever_ground";
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box35", 0.5);
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.5;
			}	
			
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "reload", "reload5", "falling_lever3");
		break;

		case "falling_lever3":
			PlaySound("INTERFACE\girder_close.wav");
			CreateParticleSystemX("blast_dirt", -9.1, 13.4, -30.3, -9.1, 13.4, -30.3, 10);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			LAi_SetPlayerType(Pchar);
			
			if(Locations[FindLocation(Pchar.location)].models.always.l4 == "bars_stuck") 
			{
				LAi_QuestDelay("extra_plank_sound", 0.5);
			}
			else LAi_QuestDelay("falling_lever4", 1.5);
		break;

		case "extra_plank_sound":
			PlaySound("PEOPLE\wood2.wav");

			LAi_QuestDelay("extra_plank_sound1", 1.5);
		break;

		case "falling_lever4":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"The Lever must have fallen to the ground."));
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");

			if(CheckAttribute(Pchar, "quest.ch_shore_repeat_gate") && Pchar.quest.ch_shore_repeat_gate == "yes")
			{
				Pchar.quest.ch_shore_repeat_gate = "no";

				LAi_QuestDelay("Jup_need_plank", 1.5);
			}
		break;

		case "lever_from_ground":
			if(CheckAttribute(Pchar, "quest.Jup_plank") && Pchar.quest.Jup_plank == "yes")
			{
				//remove plank from bridge here
				Locations[FindLocation("Charleston_shore")].models.always.l7 = "";
			}

			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "reload", "reload4", "lever_from_ground1");
		break;

		case "lever_from_ground1":
			if(CheckAttribute(Pchar, "quest.first_lever_pickup") && Pchar.quest.first_lever_pickup == "yes")
			{
				Pchar.quest.first_lever_pickup = "no";

				LAi_SetActorType(Pchar);
				LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

				LAi_QuestDelay("stop_gate", 2.0);
			}

			if(CheckAttribute(Pchar, "quest.Jup_plank") && Pchar.quest.Jup_plank == "yes")
			{
				Pchar.quest.Jup_plank = "no";

				LAi_QuestDelay("Jup_has_plank", 0.1);
			}

			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
		break;

		case "stop_gate":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "stop_gate";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "stop_gate1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "stop_gate1";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "stop_gate3":
			//after Jup dialog

			LAi_SetPlayerType(Pchar);
			LAi_SetStayType(characterFromID("Jupiter"));
			PlaySound("INTERFACE\button1.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterbyItem(Pchar, "bladeX4");
			TakeItemFromCharacter(Pchar, "bladelever" );
			GiveItem2Character(characterFromID("Jupiter"), "bladelever");
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladelever");

			LAi_QuestDelay("ch_shore_loading_image_back", 0.1);
			LAi_QuestDelay("Jup_equip_lever_check", 0.1);

			pchar.quest.stop_gate4.win_condition.l1 = "locator";
			pchar.quest.stop_gate4.win_condition.l1.location = "Charleston_shore";
			pchar.quest.stop_gate4.win_condition.l1.locator_group = "goto";
			pchar.quest.stop_gate4.win_condition.l1.locator = "falling_lever";
			pchar.quest.stop_gate4.win_condition = "stop_gate4";	
		break;

		case "Jup_equip_lever_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"bladelever"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladelever")) 
				{
					RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
					EquipCharacterbyItem(characterFromID("Jupiter"), "bladelever");
				}

				LAi_QuestDelay("Jup_equip_lever_check", 0.5);//loop check
			}
			else return;
		break;

		case "stop_gate4":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box37");
			LAi_SetStayType(Pchar);

			//lever down!

			PlaySound("INTERFACE\lever_down.wav");
			Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_down";
			Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_up";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box32 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box32", 0.001);

			LAi_QuestDelay("stop_gate5", 0.5);
		break;

		case "stop_gate5":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "falling_lever", "stop_gate6");
		break;

		case "stop_gate6":
			LAi_SetPlayerType(Pchar);
			PlaySound("INTERFACE\girder_open.wav");
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box37");
			LAi_SetStayType(characterFromID("Jupiter"));

			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "bladelever" );

			pchar.quest.stop_gate7.win_condition.l1 = "locator";
			pchar.quest.stop_gate7.win_condition.l1.location = "Charleston_shore";
			pchar.quest.stop_gate7.win_condition.l1.locator_group = "goto";
			pchar.quest.stop_gate7.win_condition.l1.locator = "other_side";
			pchar.quest.stop_gate7.win_condition = "stop_gate7";		
		break;

		case "stop_gate7":
			LAi_SetStayType(Pchar);
			Pchar.quest.gate_other_side = "yes";
			PlaySound("INTERFACE\metal_fall.wav");

			LAi_QuestDelay("stop_gate8", 1.5);
		break;

		case "stop_gate8":
			LAi_SetStayType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			
			LAi_QuestDelay("stop_gate9", 1.0);
		break;

		case "stop_gate9":
			LAi_SetStayType(Pchar);
			Locations[FindLocation(Pchar.location)].models.always.l4 = "bars_down";	
			Locations[FindLocation(Pchar.location)].models.always.l8 = "lever_ground";
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box35", 0.5);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box32", 0.8);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box32 = 0.8;
			Locations[FindLocation("Charleston_shore")].image = "";

			DoQuestReloadToLocation("Charleston_shore", "goto", "other_side1", "stop_gate10");
		break;

		case "stop_gate10":
			PlaySound("INTERFACE\girder_close.wav");
			CreateParticleSystemX("blast_dirt", -9.1, 13.4, -30.3, -9.1, 13.4, -30.3, 10);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			LAi_SetStayType(Pchar);

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "goto6");

			LAi_QuestDelay("falling_lever4", 1.5);		//stringlog lever to ground
			LAi_QuestDelay("stop_gate11", 2.5);
		break;

		case "stop_gate11":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "bars_back");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorRunToLocator(characterFromID("Jupiter"), "goto", "bars_back", "stop_gate12", 2.0);	//was 3.0
		break;

		case "stop_gate12":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "stop_gate12";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "stop_gate13":
			//from Jup dialog

			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			LAi_SetPlayerType(Pchar);
			LAi_SetStayType(characterFromID("Jupiter"));
		break;
	
		//....................................................

		case "ch_shore_place_ladder_lever":
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box38", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box38 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box32", 0.8);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box32 = 0.8;

			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "box32", "ch_shore_loading_image_back");
		break;
//pick up plank 2B
		case "ch_shore_pick_up_plank2B":
			Locations[FindLocation("Charleston_shore")].models.always.l7 = "";
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box39", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box39 = 0.001;

			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "reload", "reload3", "Pchar_playertype");
		break;

		case "ch_shore_pick_up_plank_ground":
			Locations[FindLocation("Charleston_shore")].models.always.l7 = "";
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box17 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box31", 0.8);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box31 = 0.8;

			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "bars_back", "Pchar_playertype");
		break;

		//....................................................

		case "maroon_cavern_steplock":
			pchar.quest.maroon_cavern_steplock1.win_condition.l1 = "locator";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.location = "Maroon_cavern";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.maroon_cavern_steplock1.win_condition = "maroon_cavern_steplock1";	
		break;

		case "maroon_cavern_steplock1":
			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\step_path.wav");

			LAi_QuestDelay("maroon_cavern_steplock2", 0.5);
		break;

		case "maroon_cavern_steplock2":
			if(Locations[FindLocation(Pchar.location)].models.always.locators == "cavernMedium_locators_GB_flooded")
			{
				//cavern is flooded
			
				SetNextWeather("Clear");
	 			DeleteAttribute(Pchar, "quest.JRH_rain");
				Locations[FindLocation(Pchar.location)].models.always.locators = "cavernMedium_locators_GB_dry";
				locations[FindLocation("Maroon_Cavern")].environment.weather = "false";
				locations[FindLocation("Maroon_Cavern")].environment.sea = "false";

				if(Characters[GetCharacterIndex("maroon3")].Ship.Type == "obj_barrel3_roll")
				{
					Characters[GetCharacterIndex("maroon3")].Ship.Type = "obj_invisible";
					Locations[FindLocation(Pchar.location)].models.always.l5 = "barrelA";
					Locations[FindLocation(Pchar.location)].models.always.l7 = "bottleA_cork";
				}

				if(Characters[GetCharacterIndex("maroon4")].Ship.Type == "obj_barrel3_roll")
				{
					Characters[GetCharacterIndex("maroon4")].Ship.Type = "obj_invisible";
					Locations[FindLocation(Pchar.location)].models.always.l5 = "barrelB";
					Locations[FindLocation(Pchar.location)].models.always.l7 = "bottleB_cork";
				}

				if(Characters[GetCharacterIndex("maroon2")].Ship.Type == "obj_barrel3_roll")
				{
					Characters[GetCharacterIndex("maroon2")].Ship.Type = "obj_invisible";
					Locations[FindLocation(Pchar.location)].models.always.l5 = "barrelC";
					Locations[FindLocation(Pchar.location)].models.always.l7 = "bottleC_cork";
				}

				if(Characters[GetCharacterIndex("maroon1")].Ship.Type == "obj_ladder2")
				{
					Characters[GetCharacterIndex("maroon1")].Ship.Type = "obj_invisible";
					Locations[FindLocation(Pchar.location)].models.always.l4 = "ladder_bottom";
				}

				if(CheckAttribute(Pchar, "quest.cavern_ladder") && Pchar.quest.cavern_ladder == "picked_up")
				{
					Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box14 = 0.0001;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 0.0001);
				}
				else
				{
					Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box14 = 1.0;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 1.0);
				}
			}
			else
			{
				//cavern is dry
				
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "clear";
				Locations[FindLocation(Pchar.location)].models.always.locators = "cavernMedium_locators_GB_flooded";
				locations[FindLocation("Maroon_Cavern")].environment.weather = "true";
				locations[FindLocation("Maroon_Cavern")].environment.sea = "true";
				
				if(Locations[FindLocation(Pchar.location)].models.always.l7 == "bottleB_cork")
				{
					Characters[GetCharacterIndex("maroon4")].Ship.Type = "obj_barrel3_roll";
					Locations[FindLocation(Pchar.location)].models.always.l5 = "";
					Locations[FindLocation(Pchar.location)].models.always.l7 = "";
				}

				if(Locations[FindLocation(Pchar.location)].models.always.l7 == "bottleC_cork")
				{
					Characters[GetCharacterIndex("maroon2")].Ship.Type = "obj_barrel3_roll";
					Locations[FindLocation(Pchar.location)].models.always.l5 = "";
					Locations[FindLocation(Pchar.location)].models.always.l7 = "";

					if(CheckAttribute(Pchar, "quest.cavern_ladder") && Pchar.quest.cavern_ladder == "picked_up")
					{
						
					}
					else Pchar.quest.cavern_ladder = "free";
				}
				
				if(Locations[FindLocation(Pchar.location)].models.always.l7 == "bottleA_cork")
				{
					if(CheckAttribute(Pchar, "quest.barrelA") && Pchar.quest.barrelA == "empty")
					{
						Characters[GetCharacterIndex("maroon3")].Ship.Type = "obj_barrel3_roll";
						Locations[FindLocation(Pchar.location)].models.always.l5 = "";
						Locations[FindLocation(Pchar.location)].models.always.l7 = "";
					}
				}

				if(CheckAttribute(Pchar, "quest.cavern_ladder") && Pchar.quest.cavern_ladder == "free")
				{
					Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box14 = 1.5;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 1.5);
					Characters[GetCharacterIndex("maroon1")].Ship.Type = "obj_ladder2";
					Locations[FindLocation(Pchar.location)].models.always.l4 = "";
				}
				else
				{
					Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box14 = 0.0001;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 0.0001);
				}
			}

			Locations[FindLocation("Maroon_cavern")].image = "";
			DoQuestReloadToLocation("Maroon_cavern", "reload", "reload5", "maroon_cavern_steplock3");
		break;

		case "maroon_cavern_steplock3":
			Locations[FindLocation("Maroon_cavern")].image = "Inside_cavernMedium.tga";	
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("maroon_cavern_steplock4", 0.5);

			pchar.quest.maroon_cavern_steplock1.win_condition.l1 = "locator";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.location = "Maroon_cavern";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_cavern_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.maroon_cavern_steplock1.win_condition = "maroon_cavern_steplock1";
		break;

		case "maroon_cavern_steplock4":
			if(Locations[FindLocation(Pchar.location)].models.always.locators == "cavernMedium_locators_GB_flooded")
			{
				PlaySound("NATURE\water_in.wav");
			}
			else PlaySound("NATURE\water_out.wav");
		break;
	
		//....................................................

		case "maroon_hideout_boxback":
			LAi_SetPlayerType(Pchar);

			pchar.quest.maroon_hideout_boxback1.win_condition.l1 = "locator";
			pchar.quest.maroon_hideout_boxback1.win_condition.l1.location = "Maroon_hideout";
			pchar.quest.maroon_hideout_boxback1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_hideout_boxback1.win_condition.l1.locator = "box";
			pchar.quest.maroon_hideout_boxback1.win_condition = "maroon_hideout_boxback1";	
		break;

		case "maroon_hideout_boxback1":	
			if(CheckAttribute(Pchar, "quest.jup_kungfu") && Pchar.quest.jup_kungfu == "yes")
			{
				LAi_SetStayType(Pchar);
				Logit(TranslateString("","Strange, I wonder why that crate looks different from the others."));
				PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				ChangeCharacterAddressGroup(Pchar, "Maroon_hideout", "goto", "box_back2");
			
				if(!IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(Pchar, characterFromID("Jupiter"));

					AddPassenger(Pchar, characterFromID("Jupiter"), 0);
					SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
					LAi_SetOfficerType(characterFromID("Jupiter"));
				}

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Maroon_hideout", "officers", "reload3_1");

				LAi_QuestDelay("jup_kungfu", 1.5);
			}
			else
			{
				LAi_SetStayType(Pchar);
				Logit(TranslateString("","No, that crate is too heavy."));
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(Pchar, "Maroon_hideout", "goto", "box_back");

				LAi_QuestDelay("maroon_hideout_boxback", 1.0);
			}
		break;

		case "jup_kungfu":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "kungfu";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "jup_kungfu_done":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			ChangeCharacterAddressGroup(Pchar, "Maroon_hideout", "goto", "box_back2");
			ChangeCharacterAddressGroup(characterFromID("box_ghost"), "Maroon_hideout", "goto", "box_ghost");

			LAi_QuestDelay("jup_kungfu_done1", 2.0);
		break;

		case "jup_kungfu_done1":
			PlaySound("PEOPLE\kungfu.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorAttack(CharacterFromID("Jupiter"), CharacterFromID("box_ghost"), "");
		break;

		case "jup_kungfu_done2":
			Locations[FindLocation(Pchar.location)].models.always.locators = "Cave_Ship_l_GB_closed";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "box", 0.0001);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "steplock", 0.5);
			Locations[FindLocation("Maroon_hideout")].locators_radius.goto.box = 0.0001;
			Locations[FindLocation("Maroon_hideout")].locators_radius.goto.steplock = 0.5;
			Pchar.quest.mar_cav_to_hideout = "open";

			Locations[FindLocation("Maroon_hideout")].image = "";
			DoQuestReloadToLocation("Maroon_hideout", "reload", "reload4", "jup_kungfu_done3");
		break;

		case "jup_kungfu_done3":
			Pchar.quest.jup_kungfu = "no";
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Locations[FindLocation("Maroon_hideout")].image = "Inside_Cave_Ship.tga";	
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("kungfu_new", 0.1);		
		break;

		case "kungfu_new":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "kungfu_new";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "kungfu_new_done":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			LAi_SetPlayerType(Pchar);

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "none", "", "");

			pchar.quest.maroon_hideout_steplock1.win_condition.l1 = "locator";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.location = "Maroon_hideout";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.maroon_hideout_steplock1.win_condition = "maroon_hideout_steplock1";	
		break;

		//....................................................

		case "maroon_hideout_steplock":
			pchar.quest.maroon_hideout_steplock1.win_condition.l1 = "locator";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.location = "Maroon_hideout";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.maroon_hideout_steplock1.win_condition = "maroon_hideout_steplock1";	
		break;

		case "maroon_hideout_steplock1":
			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\step_path.wav");

			LAi_QuestDelay("maroon_hideout_steplock2", 0.5);
		break;

		case "maroon_hideout_steplock2":
			if(Locations[FindLocation(Pchar.location)].models.always.locators == "Cave_Ship_l_GB_closed")
			{
				Locations[FindLocation(Pchar.location)].models.always.locators = "Cave_Ship_l_GB_open";
			}
			else Locations[FindLocation(Pchar.location)].models.always.locators = "Cave_Ship_l_GB_closed";

			Locations[FindLocation("Maroon_hideout")].image = "";
			DoQuestReloadToLocation("Maroon_hideout", "reload", "reload3", "maroon_hideout_steplock3");
		break;

		case "maroon_hideout_steplock3":
			Locations[FindLocation("Maroon_hideout")].image = "Inside_Cave_Ship.tga";	
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("maroon_hideout_steplock4", 0.5);

			pchar.quest.maroon_hideout_steplock1.win_condition.l1 = "locator";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.location = "Maroon_hideout";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_hideout_steplock1.win_condition.l1.locator = "steplock";
			pchar.quest.maroon_hideout_steplock1.win_condition = "maroon_hideout_steplock1";
		break;

		case "maroon_hideout_steplock4":
			if(Locations[FindLocation(Pchar.location)].models.always.locators == "Cave_Ship_l_GB_closed")
			{
				PlaySound("INTERFACE\shelf_close.wav");
			}
			else PlaySound("INTERFACE\shelf_open.wav");
		break;

		//....................................................

		case "officer_to_hideout":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Maroon_hideout", "officers", "reload2_1");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			}
		
			if(IsOfficer(CharacterFromID("Edgar Allan Poe")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Maroon_hideout", "officers", "reload2_1");
				AddPassenger(Pchar, characterFromID("Edgar Allan Poe"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Edgar Allan Poe"));
			}	
		break;
		
		//....................................................

		case "devils_turn_to_tree":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "tree_zoom":
			Locations[FindLocation(Pchar.location)].models.always.locators = "locator_BH2";	//with tree!
			locations[FindLocation(Pchar.location)].image = "zoom_tree.tga";

			DoQuestReloadToLocation("Bishops_Hostel", "box", "box37", "tree_zoom1");
		break;

		case "tree_zoom1":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_Hostel", "box", "box3");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";

			if(!CheckAttribute(Pchar,"quest.BH_message8") || Pchar.quest.BH_message8 != "done")
			{
				AddQuestRecord("Bishop's_Hostel","8");
				DeleteQuestHeader("Navigation_items");

				pchar.quest.Jup_climbs_tree.win_condition.l1 = "locator";
				pchar.quest.Jup_climbs_tree.win_condition.l1.location = "Bishops_Hostel";
				pchar.quest.Jup_climbs_tree.win_condition.l1.locator_group = "goto";
				pchar.quest.Jup_climbs_tree.win_condition.l1.locator = "tree_base";
				pchar.quest.Jup_climbs_tree.win_condition = "Jup_climbs_tree";
			}
			
			LAi_QuestDelay("tree_zoom2", 1.0);	
		break;
	
		case "tree_zoom2":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "tree_zoom";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "tree_zoom_again":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look2");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "green_zoom":
			locations[FindLocation(Pchar.location)].image = "zoom_green.tga";

			DoQuestReloadToLocation("Bishops_Hostel", "box", "box37", "green_zoom1");
		break;

		case "green_zoom1":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_Hostel", "box", "box3");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";
			
			LAi_QuestDelay("green_zoom2", 1.0);	
		break;
	
		case "green_zoom2":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "green_zoom";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "prepare_leave_devils_seat":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "armrest");

			LAi_QuestDelay("leave_devils_seat", 1.0);

			if(!CheckAttribute(Pchar,"quest.BH_message6") || Pchar.quest.BH_message6 != "done")
			{
				AddQuestRecord("Bishop's_Hostel","6");
				SetQuestHeader("Navigation_items");
				AddQuestRecord("Navigation_items","1");
				Pchar.quest.BH_message6 = "done";
			Locations[FindLocation("Bessop_plantation")].reload.l1.disable = 0;
	
				pchar.quest.jup_unlock_the_gate.win_condition.l1 = "locator";
				pchar.quest.jup_unlock_the_gate.win_condition.l1.location = "Charleston_shore";
				pchar.quest.jup_unlock_the_gate.win_condition.l1.locator_group = "goto";
				pchar.quest.jup_unlock_the_gate.win_condition.l1.locator = "other_side";
				pchar.quest.jup_unlock_the_gate.win_condition = "jup_unlock_the_gate";
			}
		break;

		case "leave_devils_seat":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.devils_seat = "go_down";
			LAi_SetPlayerType(Pchar);
		break;

		case "devils_seat_go_down":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "Bishops_Hostel", "box", "box14");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look3");

			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("pchar_sigh", 1.0);
		break;

		case "no_zoom":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "no_zoom";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "no_spyglass":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "no_spyglass";
			LAi_ActorSelfDialog(pchar, "");
		break;

		//....................................................

		case "jup_unlock_the_gate":
			LAi_QuestDelay("jup_unlock_the_gate1", 1.0);
		break;

		case "jup_unlock_the_gate1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "unlock_the_gate";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "jup_unlock_the_gate2":
			LAi_SetStayType(Pchar);
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorRunToLocator(characterFromID("Jupiter"), "officers", "reload4_1", "jup_unlock_the_gate3", 10.0);
		break;

		case "jup_unlock_the_gate3":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box37");
			LAi_SetStayType(characterFromID("Jupiter"));

			LAi_QuestDelay("jup_unlock_the_gate4", 1.0);
		break;

		case "jup_unlock_the_gate4":
			PlaySound("INTERFACE\lever_down.wav");
			Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_down";
			Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_up";

			LAi_QuestDelay("jup_unlock_the_gate5", 0.5);
		break;

		case "jup_unlock_the_gate5":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "other_side", "jup_unlock_the_gate6");
		break;

		case "jup_unlock_the_gate6":
			LAi_SetPlayerType(Pchar);
			PlaySound("INTERFACE\girder_open.wav");
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			
			pchar.quest.jup_unlock_the_gate7.win_condition.l1 = "locator";
			pchar.quest.jup_unlock_the_gate7.win_condition.l1.location = "Charleston_shore";
			pchar.quest.jup_unlock_the_gate7.win_condition.l1.locator_group = "goto";
			pchar.quest.jup_unlock_the_gate7.win_condition.l1.locator = "falling_lever";
			pchar.quest.jup_unlock_the_gate7.win_condition = "jup_unlock_the_gate7";		
		break;

		case "jup_unlock_the_gate7":
			LAi_SetStayType(Pchar);
			PlaySound("INTERFACE\metal_fall.wav");

			LAi_QuestDelay("jup_unlock_the_gate8", 1.5);
		break;

		case "jup_unlock_the_gate8":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			
			LAi_QuestDelay("jup_unlock_the_gate9", 1.0);
		break;

		case "jup_unlock_the_gate9":
			Locations[FindLocation(Pchar.location)].models.always.l4 = "bars_down";
			Locations[FindLocation(Pchar.location)].models.always.l8 = "";
			Pchar.quest.gate_other_side  = "no";
			
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box35", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.001;
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "falling_lever1", "jup_unlock_the_gate10");
		break;

		case "jup_unlock_the_gate10":
			PlaySound("INTERFACE\girder_close.wav");
			CreateParticleSystemX("blast_dirt", -9.1, 13.4, -30.3, -9.1, 13.4, -30.3, 10);
			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";
			LAi_SetPlayerType(Pchar);

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload4_1");
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "Charleston_passage", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "Charleston_passage", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "Charleston_passage", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "Charleston_passage", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "Charleston_passage", "goto", "goto4");

			pchar.quest.maroon_prep.win_condition.l1 = "locator";
			pchar.quest.maroon_prep.win_condition.l1.location = "Charleston_passage";
			pchar.quest.maroon_prep.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_prep.win_condition.l1.locator = "maroon_prep";
			pchar.quest.maroon_prep.win_condition = "maroon_prep";	
		break;

		case "maroon_prep":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "maroon_prep";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "maroon_prep1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "I_do_the_talking";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "maroon_prep2":
			LAi_LocationFightDisable(&Locations[FindLocation("Charleston_passage")], true);	//was enabled for some reason
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			LAi_SetPlayerType(Pchar);

			pchar.quest.maroon_stop.win_condition.l1 = "locator";
			pchar.quest.maroon_stop.win_condition.l1.location = "Charleston_passage";
			pchar.quest.maroon_stop.win_condition.l1.locator_group = "goto";
			pchar.quest.maroon_stop.win_condition.l1.locator = "maroon_stop";
			pchar.quest.maroon_stop.win_condition = "maroon_stop";	
		break;

		case "maroon_stop":
			Characters[GetCharacterIndex("maroon1")].dialog.CurrentNode  = "return1";
			LAi_SetActorType(characterFromID("maroon1"));
			LAi_ActorTurnToCharacter(characterFromID("maroon1"), PChar);
			LAi_ActorDialogNow(characterFromID("maroon1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("maroon1"));
		break;

		case "maroon_stop1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "return1";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "maroon_stop2":
			Characters[GetCharacterIndex("maroon1")].dialog.CurrentNode  = "return1_C";
			LAi_SetActorType(characterFromID("maroon1"));
			LAi_ActorTurnToCharacter(characterFromID("maroon1"), PChar);
			LAi_ActorDialogNow(characterFromID("maroon1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("maroon1"));
		break;

		case "maroon_stop3":
			LAi_SetPlayerType(Pchar);
			LAi_SetStayType(characterFromID("maroon1"));

			pchar.quest.maroon_stop4.win_condition.l1 = "location";
			pchar.quest.maroon_stop4.win_condition.l1.location = "Charleston_swamp";
			pchar.quest.maroon_stop4.win_condition = "maroon_stop4";
		break;

		case "maroon_stop4":
			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "none", "", "");

			pchar.quest.shopping_1A.win_condition.l1 = "locator";
			pchar.quest.shopping_1A.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.shopping_1A.win_condition.l1.locator_group = "goto";
			pchar.quest.shopping_1A.win_condition.l1.locator = "where_to";
			pchar.quest.shopping_1A.win_condition = "shopping_1A";
		break;

//----------------------------------------------------------------------------------------------------------------------------

		case "shopping_1A":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "shopping_1A";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "shopping_1D":
			//from Jup dialog

			AddQuestRecord("Navigation_items","2");
			Pchar.quest.store_box2 = "locked";
			ChangeCharacterAddressGroup(characterFromID("GB_storeowner"), "GB_Charleston_store", "barmen", "stay");
		break;

		case "navigation_items":
			Characters[GetCharacterIndex("GB_storeowner")].dialog.CurrentNode  = "navigation_items";
			LAi_SetActorType(characterFromID("GB_storeowner"));
			LAi_ActorTurnToCharacter(characterFromID("GB_storeowner"), PChar);
			LAi_ActorDialogNow(characterFromID("GB_storeowner"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("GB_storeowner"));
		break;

		case "shopping_1E":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "shopping_1E";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "shopping_1F":
			//from Jup dialog

			Characters[GetCharacterIndex("GB_storeowner")].dialog.CurrentNode  = "Pyms_house";
			LAi_SetActorType(characterFromID("GB_storeowner"));
			LAi_ActorTurnToCharacter(characterFromID("GB_storeowner"), PChar);
			LAi_ActorDialogNow(characterFromID("GB_storeowner"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("GB_storeowner"));
		break;

		case "shopping_1G":
			//from storeowner dialog

			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			Characters[GetCharacterIndex("GB_storeowner")].dialog.CurrentNode  = "First time";
	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			LAi_QuestDelay("shopping_1H", 2.0);			
		break;

		case "shopping_1H":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_to_Fort_Moultrie";
			LAi_ActorSelfDialog(pchar, "");
		break;
	
		case "shopping_1J":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "shopping_1J";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "shopping_1K":
			//from Jup dialog

			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistoltinderbox" );
			GiveItem2Character(Pchar, "pistoltinderbox");

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
			SetOfficersIndex(Pchar, 0, getCharacterIndex("Jupiter"));
			BLI_UpdateOfficers();

			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "reload", "reload1", "shopping_1L", 4.0);
		break;

		case "shopping_1L":
			//switch to Jupiter here

			LAi_QuestDelay("prepare_Jup_spyglass", 0.1);
		break;
//-----------------------------------------------------------------------------------------------------------------------------
//JRH 10 (after store dialog)
//Jupiter's Spyglass mission
		case "Jup_spyglass_start":
			//after store dialogs

			SetNextWeather("Blue Sky");
			DoQuestReloadToLocation("GB_Charleston_town", "reload", "reload8", "Jup_spyglass_1");
		break;

		case "Jup_spyglass_1":
			SetNextWeather("Blue Sky");
			LAi_SetPlayerType(pchar);

	InterfaceStates.Buttons.Save.enable = 0;			//bugfix: a loaded savegame here disabled the boat to Fort_Moultrie_shore, enabled again at the shore
			Pchar.quest.Jupiter_switch3 = "yes";		//updates questbook for Jupiter character
			Pchar.quest.Fort_visit = "2";
			
			//just in case you started an earlier jumpstart
			
			Pchar.quest.Jupiter_tobacco = "2";
			Pchar.quest.Jupiter_jewelry12 = "yes";
			Pchar.quest.Jupiter_coin7 = "yes";
			Pchar.quest.Jupiter_gunpowder = "6";

			ChangeCharacterAddressGroup(CharacterFromID("Edgar Allan Poe"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Legrand_copy"), "GB_Charleston_store", "goto", "legrand");
			LAi_SetStayType(CharacterFromID("Legrand_copy"));

			Pchar.quest.devils_seat_found = "yes";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "no";		//opened later	
			Pchar.quest.boathouse = "return";
			Pchar.quest.Fort_M_flag_pos = "none";

			Pchar.quest.Fort_M_south_wall_right = "open";
			Pchar.quest.Fort_M_south_wall_left = "open";

			locations[FindLocation("Sullivan_jungle1")].type = "Sullivan_jungle";
			locations[FindLocation("Sullivan_jungle2")].type = "Sullivan_jungle";
			locations[FindLocation("Fort_Moultrie_exit")].type = "Sullivan_jungle";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "";	//no burning wood
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Locations[FindLocation("Legrands_house")].reload.l3.disable = 0;		//grot	
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "sml_l_GB_open_smoke2";
			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l6.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l10.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l12.disable = 0;
			Locations[FindLocation("Fort_Moultrie_shore")].models.always.locators = "Shore01_l_GB2";

			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_Moultrie", "goto", "box14");
			characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode = "about_flag";
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist1"), "Fort_Moultrie_village", "goto", "goto25");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist2"), "Fort_Moultrie_village", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist3"), "Fort_Moultrie_village", "goto", "goto26");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist4"), "Fort_Moultrie_village", "goto", "goto13");

			locations[FindLocation("Fort_Moultrie_village")].type = "Fort_Moultrie_village";//music
			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.close_for_night = 1;	//store
			Locations[FindLocation("Fort_Moultrie_village")].reload.l13.close_for_night = 1;//restaurant
			locations[FindLocation("Moultrie_hotel")].id.label = "Fort Moultrie hotel";
			locations[FindLocation("Moultrie_restaurant")].id.label = "Fort Moultrie restaurant";
			locations[FindLocation("Moultrie_store")].id.label = "Fort Moultrie store";

			Locations[FindLocation("Fort_Moultrie")].reload.l3.disable = 1;			//north tower	
			Locations[FindLocation("Fort_Moultrie")].reload.l9.disable = 1;			//south tower, test open
			Locations[FindLocation("Fort_Moultrie")].reload.l5.disable = 1;			//Lieutenant G house
			Locations[FindLocation("Fort_M_tower2B")].reload.l4.disable = 0;		//up to 2C
			Locations[FindLocation("Fort_M_tower2B")].reload.l8.disable = 1;		//to north tower, not open this time
			locations[FindLocation("Lieutenant_G_kitchen")].id.label = "Lieutenant G:s house";
			Locations[FindLocation("Lieutenant_G_kitchen")].reload.l3.disable = 0;		//to office
			locations[FindLocation("Lieutenant_G_office")].id.label = "Lieutenant G:s office";

			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
		LAi_QuestDelay("fort_open", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);

			LAi_QuestDelay("switch_to_Jupiter", 0.1);
			LAi_QuestDelay("Jup_spyglass_2", 0.2);
			LAi_QuestDelay("stop_tower3A", 0.1);
			LAi_QuestDelay("remove_Legrand_copy", 0.1);
		break;

		case "remove_Legrand_copy":
			pchar.quest.remove_Legrand_copy1.win_condition.l1 = "location";
			pchar.quest.remove_Legrand_copy1.win_condition.l1.location = "GB_Charleston_port";
			pchar.quest.remove_Legrand_copy1.win_condition = "remove_Legrand_copy1";
		break;

		case "remove_Legrand_copy1":
			ChangeCharacterAddressGroup(CharacterFromID("Legrand_copy"), "none", "", "");
		break;

		case "stop_tower3A":
			pchar.quest.stop_tower3A_1.win_condition.l1 = "locator";
			pchar.quest.stop_tower3A_1.win_condition.l1.location = "Fort_M_tower3A";
			pchar.quest.stop_tower3A_1.win_condition.l1.locator_group = "goto";
			pchar.quest.stop_tower3A_1.win_condition.l1.locator = "stop";
			pchar.quest.stop_tower3A_1.win_condition = "stop_tower3A_1";
		break;

		case "stop_tower3A_1":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_M_tower3A", "goto", "back");

			LAi_QuestDelay("stop_tower3A", 0.1);
		break;

		case "Jup_spyglass_2":
			DeleteQuestHeader("The_message");
			DeleteQuestHeader("Navigation_items");
			SetQuestHeader("Navigation_items");		//open but empty	
			AddQuestRecord("Navigation_items","10");
			DeleteQuestHeader("Bishop's_Hostel");

			pchar.quest.nice_weather.win_condition.l1 = "location";
			pchar.quest.nice_weather.win_condition.l1.location = "Fort_Moultrie_stairs";
			pchar.quest.nice_weather.win_condition = "nice_weather";
		break;

		case "nice_weather":
			SetNextWeather("Clear");

			pchar.quest.nice_weather1.win_condition.l1 = "location";
			pchar.quest.nice_weather1.win_condition.l1.location = "Fort_M_tower2C";
			pchar.quest.nice_weather1.win_condition = "nice_weather1";
		break;

		case "nice_weather1":
			SetNextWeather("Clear");
		break;

		case "about_flag_done":	
			PlaySound("VOICE\ENGLISH\G_you_could.wav");
			PlaySound("INTERFACE\took_item.wav");
			TakenItems(Pchar, "key7", 1);
			AddQuestRecord("Navigation_items","13");
			Locations[FindLocation("Fort_Moultrie")].locators_radius.box.box38 = 1.0;
			Locations[FindLocation("Fort_Moultrie")].locators_radius.reload.reload5 = 0.0001;
			Pchar.quest.Jupiter_bug_mission = "spyglass";
			Pchar.quest.Fort_visit = "neutral";	//reset soldiers

			LAi_QuestDelay("about_flag_done1", 2.0);
		break;

		case "about_flag_done1":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "Fort_Moultrie", "box", "box39");

			LAi_QuestDelay("about_flag_done2", 0.5);
		break;

		case "about_flag_done2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box13");

			LAi_QuestDelay("pchar_playertype", 0.5);
		break;

		case "return_G_office_box1":	
			if(CheckCharacterItem(Pchar,"map") || CheckCharacterItem(Pchar,"glasses") 
			|| CheckCharacterItem(Pchar,"pistolgrenade"))
			{
				if(CheckCharacterItem(Pchar,"map")) PlaySound("INTERFACE\paper.wav");
				if(CheckCharacterItem(Pchar,"glasses")) {PlaySound("INTERFACE\button3.wav"); PlaySound("INTERFACE\button3.wav");}
				if(CheckCharacterItem(Pchar,"pistolgrenade")) PlaySound("INTERFACE\pinion_place.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "map", -1); TakenItems(Pchar, "glasses", -1); TakenItems(Pchar, "pistolgrenade", -1);

				locations[FindLocation(Pchar.location)].box1.items.map = 0;
				locations[FindLocation(Pchar.location)].box1.items.glasses = 0;
				locations[FindLocation(Pchar.location)].box1.items.pistolgrenade = 0;

				locations[FindLocation(Pchar.location)].box1.items.map = 1;
				locations[FindLocation(Pchar.location)].box1.items.glasses = 1;
				locations[FindLocation(Pchar.location)].box1.items.pistolgrenade = 1;
			}
		break;

		case "return_G_office_box3":	
			if(CheckCharacterItem(Pchar,"microscope")) 
			{
				PlaySound("INTERFACE\wheel_take.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "microscope", -1); 

				locations[FindLocation(Pchar.location)].box3.items.microscope = 0;
				
				locations[FindLocation(Pchar.location)].box3.items.microscope = 1;
			}
		break;

		case "return_G_office_box4":	
			if(CheckCharacterItem(Pchar,"blade24") || CheckCharacterItem(Pchar,"blue_uniform"))
			{
				if(CheckCharacterItem(Pchar,"blade24")) PlaySound("OBJECTS\DUEL\sword_fallen.wav");
				if(CheckCharacterItem(Pchar,"blue_uniform")) PlaySound("PEOPLE\clothes1.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "blade24", -1); TakenItems(Pchar, "blue_uniform", -1);

				locations[FindLocation(Pchar.location)].box4.items.blade24 = 0;
				locations[FindLocation(Pchar.location)].box4.items.blue_uniform = 0;

				locations[FindLocation(Pchar.location)].box4.items.blade24 = 1;
				locations[FindLocation(Pchar.location)].box4.items.blue_uniform = 1;
			}
		break;

		case "return_G_office_box5":	
			if(CheckCharacterItem(Pchar,"leeches") || CheckCharacterItem(Pchar,"fish"))
			{
				if(CheckCharacterItem(Pchar,"leeches")) PlaySound("INTERFACE\glass2.wav");
				if(CheckCharacterItem(Pchar,"fish")) PlaySound("PEOPLE\step_grass.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "leeches", -1); TakenItems(Pchar, "fish", -1);

				locations[FindLocation(Pchar.location)].box5.items.leeches = 0;
				locations[FindLocation(Pchar.location)].box5.items.fish = 0;

				locations[FindLocation(Pchar.location)].box5.items.leeches = 1;
				locations[FindLocation(Pchar.location)].box5.items.fish = 1;
			}
		break;

		case "return_G_office_box6":	
			if(CheckCharacterItem(Pchar,"G_journal") || CheckCharacterItem(Pchar,"G_letter1") 
			|| CheckCharacterItem(Pchar,"G_letter2") || CheckCharacterItem(Pchar,"G_letter3"))
			{
				if(CheckCharacterItem(Pchar,"G_journal")) PlaySound("INTERFACE\book_close.wav");
				if(CheckCharacterItem(Pchar,"G_letter1")) PlaySound("INTERFACE\paper_small.wav");
				if(CheckCharacterItem(Pchar,"G_letter2")) PlaySound("INTERFACE\paper_small.wav");
				if(CheckCharacterItem(Pchar,"G_letter3")) PlaySound("INTERFACE\paper_small.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "G_journal", -1); TakenItems(Pchar, "G_letter1", -1); TakenItems(Pchar, "G_letter2", -1);
				TakenItems(Pchar, "G_letter3", -1);

				locations[FindLocation(Pchar.location)].box6.items.G_journal = 0;
				locations[FindLocation(Pchar.location)].box6.items.G_letter1 = 0;
				locations[FindLocation(Pchar.location)].box6.items.G_letter2 = 0;
				locations[FindLocation(Pchar.location)].box6.items.G_letter3 = 0;

				locations[FindLocation(Pchar.location)].box6.items.G_journal = 1;
				locations[FindLocation(Pchar.location)].box6.items.G_letter1 = 1;
				locations[FindLocation(Pchar.location)].box6.items.G_letter2 = 1;
				locations[FindLocation(Pchar.location)].box6.items.G_letter3 = 1;
			}
		break;

		case "bladeflag_usa_equip_check":
			if(CheckCharacterItem(pchar, "bladeflag_usa"))
			{
				if(!IsEquipCharacterByItem(pchar, "bladeflag_usa"))
				{
					PlaySound("PEOPLE\clothes1.wav");
					RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(pchar, "bladeflag_usa");
				}
			}
		break;

		case "equip_bladespyglass6":
			if(CheckCharacterItem(pchar, "spyglass6"))
			{
				TakeItemFromCharacter(Pchar, "spyglass6");
				GiveItem2Character(Pchar, "bladespyglass6");			
				EquipCharacterbyItem(Pchar, "bladespyglass6");
				Pchar.quest.Fort_M_south_wall_right = "closed";
				LAi_QuestDelay("pchar_yah", 0.5);
				return;
			}
			else LAi_QuestDelay("equip_bladespyglass6", 0.5);
		break;

		case "after_bladespyglass6_pickup":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Logit(TranslateString("","To Mr Poe's house now!"));
		break;

		case "jump_down_to shed":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Logit(TranslateString("","I have to find another way down."));

			pchar.quest.Jup_tired_Poes_bedroom.win_condition.l1 = "locator";
			pchar.quest.Jup_tired_Poes_bedroom.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.Jup_tired_Poes_bedroom.win_condition.l1.locator_group = "goto";
			pchar.quest.Jup_tired_Poes_bedroom.win_condition.l1.locator = "start";
			pchar.quest.Jup_tired_Poes_bedroom.win_condition = "Jup_tired_Poes_bedroom";
		break;

		case "Jup_tired_Poes_bedroom":
			LAi_SetActorType(pchar);	
			LAi_ActorGoToLocator(pchar, "goto", "goto6", "Jup_tired_Poes_bedroom1", 2.0);
		break;

		case "Jup_tired_Poes_bedroom1":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_tired_Poes_bedroom";
			LAi_ActorSelfDialog(pchar, "");
		break;
//JRH roofs
		case "Legrand_Pym_start":
			//from Jup dialog

		SetCurrentTime(03.00, 0);
		SetNextWeather("Heavy Storm");
			Pchar.quest.Legrands_tinderbox = "yes";
			Pchar.quest.Legrands_gunpowder = "6";
			Pchar.quest.Legrands_clock1 = "yes";
			Pchar.quest.Legrands_goldbug = "yes";

			DoQuestReloadToLocation("GB_Charleston_store", "goto", "legrand", "Legrand_Pym_start1");
		break;

		case "Legrand_Pym_start1":
			LAi_QuestDelay("switch_to_Legrand", 0.1);
			LAi_QuestDelay("Legrand_Pym_start1_A", 0.2);
			LAi_QuestDelay("Legrand_Pym_start2", 1.0);
		break;

		case "Legrand_Pym_start1_A":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
		break;

		case "Legrand_Pym_start2":
			TakenItems(Pchar, "BH_sketch", 1);
			TakenItems(Pchar, "crypto2", 1);

			EquipCharacterByItem(Pchar, "bladeX4");
			TakenItems(Pchar, "letter_paper", -1);
			TakenItems(Pchar, "bladewoodsack", -1);
			TakenItems(Pchar, "bladecrypto_csk", -1);

			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("The_parchment");
			DeleteQuestHeader("Searching_the_shores");
		//	SetQuestHeader("The_Message");
		//	AddQuestRecord("The_Message","24");
		//	CloseQuestHeader("The_Message");
			DeleteQuestHeader("Navigation_items");	
			SetQuestHeader("Navigation_items");
			AddQuestRecord("Navigation_items","1");
			AddQuestRecord("Navigation_items","2");
			AddQuestRecord("Navigation_items","3");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","1");
			AddQuestRecord("Bishop's_Hostel","2");
			AddQuestRecord("Bishop's_Hostel","3");
			AddQuestRecord("Bishop's_Hostel","4");
			AddQuestRecord("Bishop's_Hostel","5");
			AddQuestRecord("Bishop's_Hostel","6");

			LAi_QuestDelay("search_tailors_shop1", 1.0);
		break;
//--------------------------------------------------------------------------------------------------------------------
	
		case "prepare_Jup_spyglass":
			PlaySound("INTERFACE\closed_door.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "reload", "reload8");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			LAi_QuestDelay("Jup_spyglass_start", 1.0);
		break;

		case "search_tailors_shop1":
			AddQuestRecord("Navigation_items","3");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Arthur Gordon Pym"), "GB_Charleston_town", "reload", "reload13");
			Characters[GetCharacterIndex("Arthur Gordon Pym")].dialog.CurrentNode  = "outside_tailor";
		break;

		case "search_ladder_to_Charleston_roofs":
			AddQuestRecord("Navigation_items","4");
			AddQuestRecord("Navigation_items","9");
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box24", 1.0);
			Locations[FindLocation("GB_Charleston_town")].locators_radius.box.box24 = 1.0;

			LAi_QuestDelay("subject_caves", 0.1);
			LAi_QuestDelay("subject_travels", 0.1);
			LAi_QuestDelay("subject_whaling", 0.1);
			LAi_QuestDelay("subject_dogs", 0.1);
			LAi_QuestDelay("subject_piracy", 0.1);
			LAi_QuestDelay("subject_cannibalism", 0.1);
			LAi_QuestDelay("tower_chest_stepback", 0.1);
		break;

		case "subject_caves":
			pchar.quest.subject_caves1.win_condition.l1 = "locator";
			pchar.quest.subject_caves1.win_condition.l1.location = "Pym_drawing_room";
			pchar.quest.subject_caves1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_caves1.win_condition.l1.locator = "box6";
			pchar.quest.subject_caves1.win_condition = "subject_caves1";
		break;

		case "subject_caves1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Caves"));
			LAi_QuestDelay("subject_caves", 0.1);
		break;

		case "subject_travels":
			pchar.quest.subject_travels1.win_condition.l1 = "locator";
			pchar.quest.subject_travels1.win_condition.l1.location = "Pym_drawing_room";
			pchar.quest.subject_travels1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_travels1.win_condition.l1.locator = "box7";
			pchar.quest.subject_travels1.win_condition = "subject_travels1";
		break;

		case "subject_travels1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Travels around the world"));
			LAi_QuestDelay("subject_travels", 0.1);
		break;

		case "subject_whaling":
			pchar.quest.subject_whaling1.win_condition.l1 = "locator";
			pchar.quest.subject_whaling1.win_condition.l1.location = "Pym_bedroom";
			pchar.quest.subject_whaling1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_whaling1.win_condition.l1.locator = "box5";
			pchar.quest.subject_whaling1.win_condition = "subject_whaling1";
		break;

		case "subject_whaling1":
			if(CheckAttribute(Pchar, "quest.pym_niche") && Pchar.quest.pym_niche == "open")
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Whaling"));
			}
			LAi_QuestDelay("subject_whaling", 0.1);
		break;

		case "subject_dogs":
			pchar.quest.subject_dogs1.win_condition.l1 = "locator";
			pchar.quest.subject_dogs1.win_condition.l1.location = "Pym_study";
			pchar.quest.subject_dogs1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_dogs1.win_condition.l1.locator = "box3";
			pchar.quest.subject_dogs1.win_condition = "subject_dogs1";
		break;

		case "subject_dogs1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Newfoundland Dogs"));
			LAi_QuestDelay("subject_dogs", 0.1);
		break;

		case "subject_piracy":
			pchar.quest.subject_piracy1.win_condition.l1 = "locator";
			pchar.quest.subject_piracy1.win_condition.l1.location = "Pym_study";
			pchar.quest.subject_piracy1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_piracy1.win_condition.l1.locator = "box2";
			pchar.quest.subject_piracy1.win_condition = "subject_piracy1";
		break;

		case "subject_piracy1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Piracy"));
			LAi_QuestDelay("subject_piracy", 0.1);
		break;

		case "subject_cannibalism":
			pchar.quest.subject_cannibalism1.win_condition.l1 = "locator";
			pchar.quest.subject_cannibalism1.win_condition.l1.location = "Pym_study";
			pchar.quest.subject_cannibalism1.win_condition.l1.locator_group = "box";
			pchar.quest.subject_cannibalism1.win_condition.l1.locator = "box7";
			pchar.quest.subject_cannibalism1.win_condition = "subject_cannibalism1";
		break;

		case "subject_cannibalism1":
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Cannibalism"));
			LAi_QuestDelay("subject_cannibalism", 0.1);
		break;

		case "tower_chest_stepback":
			pchar.quest.tower_chest_stepback1.win_condition.l1 = "locator";
			pchar.quest.tower_chest_stepback1.win_condition.l1.location = "Pym_towerroom";
			pchar.quest.tower_chest_stepback1.win_condition.l1.locator_group = "goto";
			pchar.quest.tower_chest_stepback1.win_condition.l1.locator = "goto2";
			pchar.quest.tower_chest_stepback1.win_condition = "tower_chest_stepback1";
		break;

		case "tower_chest_stepback1":
			ChangeCharacterAddressGroup(Pchar, "Pym_towerroom", "box", "box2");

			LAi_QuestDelay("tower_chest_stepback", 0.1);
		break;

		case "store_ladder_down":
			Pchar.quest.store_box13 = "off";
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_store", "box", "box12");
		break;

		case "tailor_sack_down":
			CreateParticleSystemX("blast_dirt_gray", 1.7, 0.0, -1.4, 1.7, 0.0, -1.4,10);
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_tailorsShop", "box", "box7");
		break;

		case "pchar_equip_anchor_check":
			if(CheckCharacterItem(Pchar,"bladeanchor"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterbyItem(Pchar, "bladeanchor");
			}
		break;

		case "Ship_painting_attempt_up":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Logit(TranslateString("","I need something to tie the Rope to."));
			LAi_SetPlayerType(Pchar);
		break;

		case "place_pym_anchor":
			Locations[FindLocation(Pchar.location)].models.always.locators = "lh_F2_l_pym_CLOSED_ANCHOR";
			Locations[FindLocation("Pym_bedroom")].image = "";
			DoQuestReloadToLocation("Pym_bedroom", "goto", "rope", "place_pym_anchor1");
		break;

		case "place_pym_anchor1":
			Pchar.quest.pym_anchor = "placed";
			Locations[FindLocation("Pym_bedroom")].image = "Inside_Doubleflour_House_Room.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_bedroom")], true);
			
			LAi_QuestDelay("book55A_pickup_check", 1.0);
		break;
	//-----------------------------------------------------------------------------
		case "book55A_pickup_check":
			if(CheckCharacterItem(Pchar,"book55A"))
			{
				PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
				InterfaceStack.SelectMenu_node = "I_ITEMS";
				interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
				EndCancelInterface(false);	
			}
			else LAi_QuestDelay("book55A_pickup_check", 1.0);
		break;
	//-----------------------------------------------------------------------------
		case "Ship_painting_up":
	//change loc file here
			Locations[FindLocation(Pchar.location)].models.always.locators = "lh_F2_l_pym_OPEN";
			Locations[FindLocation("Pym_bedroom")].image = "";
			DoQuestReloadToLocation("Pym_bedroom", "goto", "rope", "Ship_painting_up1");
		break;

		case "Ship_painting_up1":
			Pchar.quest.pym_niche = "open";
			Locations[FindLocation("Pym_bedroom")].image = "Inside_Doubleflour_House_Room.tga";
			PlaySound("INTERFACE\chart_move.wav");
			PlaySound("INTERFACE\chart_move.wav");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("Ship_painting_up2", 1.0);
		break;

		case "Ship_painting_up2":
			Locations[FindLocation("Pym_bedroom")].reload.l2.disable = 1;
			PlaySound("INTERFACE\key_lock.wav");
			LAi_SetPlayerType(Pchar);
		break;

		case "Ship_painting_down":
	//change loc file here
			Locations[FindLocation(Pchar.location)].models.always.locators = "lh_F2_l_pym_CLOSED_ANCHOR";
			Locations[FindLocation("Pym_bedroom")].image = "";
			DoQuestReloadToLocation("Pym_bedroom", "goto", "rope", "Ship_painting_down1");
		break;

		case "Ship_painting_down1":
			Pchar.quest.pym_niche = "closed";
			Locations[FindLocation("Pym_bedroom")].image = "Inside_Doubleflour_House_Room.tga";
			PlaySound("INTERFACE\chart_move.wav");
			PlaySound("INTERFACE\chart_move.wav");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("Ship_painting_down2", 1.0);
		break;

		case "Ship_painting_down2":
			Locations[FindLocation("Pym_bedroom")].reload.l2.disable = 0;
			PlaySound("INTERFACE\key_unlock2.wav");
			LAi_SetPlayerType(Pchar);
		break;
//---------------------------------------------------------------------------------------------------------------------------------------
		case "unlock_Charleston_tailor":
			//from SL_utils
			Locations[FindLocation("GB_Charleston_tailorsShop")].locators_radius.box.box1 = 0.0001;
			Locations[FindLocation("GB_Charleston_tailorsShop")].locators_radius.reload.locator2 = 1.0;
			Locations[FindLocation("GB_Charleston_town")].reload.l13.disable = 0;
			TakenItems(Pchar, "key29", -1);
			
			ChangeCharacterAddressGroup(characterFromID("Arthur Gordon Pym"), "GB_Charleston_town", "officers", "reload13_1");
			DoQuestReloadToLocation("GB_Charleston_town", "goto", "exit_tailor", "unlock_Charleston_tailor1");
		break;

		case "unlock_Charleston_tailor1":
			Characters[GetCharacterIndex("Arthur Gordon Pym")].dialog.CurrentNode  = "Tailor_open";
			LAi_SetActorType(characterFromID("Arthur Gordon Pym"));
			LAi_ActorTurnToCharacter(characterFromID("Arthur Gordon Pym"), PChar);
			LAi_ActorDialogNow(characterFromID("Arthur Gordon Pym"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Arthur Gordon Pym"));
		break;

		case "unlock_Charleston_tailor2":
			LAi_SetActorType(characterFromID("Arthur Gordon Pym"));
			LAi_ActorGoToLocator(characterFromID("Arthur Gordon Pym"), "reload", "reload13", "unlock_Charleston_tailor3", 2.0);
		break;

		case "unlock_Charleston_tailor3":
			PlaySound("INTERFACE\closed_door.wav");
			ChangeCharacterAddressGroup(characterFromID("Arthur Gordon Pym"), "Pym_bedroom", "goto", "goto7");
			Characters[GetCharacterIndex("Arthur Gordon Pym")].dialog.CurrentNode  = "study_open";
			LAi_SetStayType(characterFromID("Arthur Gordon Pym"));
			Locations[FindLocation("Pym_bedroom")].reload.l1.disable = 0;		//unlock to stairs
			LAi_SetPlayerType(Pchar);

			//pchar goes direct to towerroom
			pchar.quest.study_open_done1.win_condition.l1 = "location";
			pchar.quest.study_open_done1.win_condition.l1.location = "Pym_towerroom";
			pchar.quest.study_open_done1.win_condition = "study_open_done1";
		break;

		case "study_open_done":
			//from Pym dialog in bedroom

			AddQuestRecord("Navigation_items","5");

			//pchar has talked to Pym in bedroom first
			pchar.quest.study_open_done1.win_condition.l1 = "location";
			pchar.quest.study_open_done1.win_condition.l1.location = "Pym_stairs";
			pchar.quest.study_open_done1.win_condition = "study_open_done1";
		break;

		case "study_open_done1":
			Characters[GetCharacterIndex("Arthur Gordon Pym")].dialog.CurrentNode  = "First time";
		break;

//---------------------------------------------------------------------------------------------------------------------------------------
		case "pchar_equip_emptysack_check":
			if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterbyItem(Pchar, "bladeemptysack_P");
			}
		break;

		case "Pym_books_return":
			//from SL_utils
			//to prevent just taking books without an empty sack

			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You need something to carry the books in!"));
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		break;

		case "book56_pickup":
			//from SL_utils
			if(CheckCharacterItem(Pchar,"book56"))
			{
				if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
				{
					TakeItemFromCharacter(Pchar, "bladeemptysack_P");
					GiveItem2Character(Pchar, "bladesemifullsack_P");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladesemifullsack_P");
				}

				LAi_QuestDelay("Pym_books_full_sack_check", 0.1);
			}
		break;
	
		case "book57_pickup":
			//from SL_utils
			if(CheckCharacterItem(Pchar,"book57"))
			{
				if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
				{
					TakeItemFromCharacter(Pchar, "bladeemptysack_P");
					GiveItem2Character(Pchar, "bladesemifullsack_P");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladesemifullsack_P");
				}

				LAi_QuestDelay("Pym_books_full_sack_check", 0.1);
			}
		break;
	
		case "book58_pickup":
			//from SL_utils
			if(CheckCharacterItem(Pchar,"book58"))
			{
				if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
				{
					TakeItemFromCharacter(Pchar, "bladeemptysack_P");
					GiveItem2Character(Pchar, "bladesemifullsack_P");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladesemifullsack_P");
				}

				LAi_QuestDelay("Pym_books_full_sack_check", 0.1);
			}
		break;
	
		case "book59_pickup":
			//from SL_utils
			if(CheckCharacterItem(Pchar,"book59"))
			{
				if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
				{
					TakeItemFromCharacter(Pchar, "bladeemptysack_P");
					GiveItem2Character(Pchar, "bladesemifullsack_P");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladesemifullsack_P");
				}

				LAi_QuestDelay("Pym_books_full_sack_check", 0.1);
			}
		break;
	
		case "book60_pickup":
			//from SL_utils
			if(CheckCharacterItem(Pchar,"book60"))
			{
				if(CheckCharacterItem(Pchar,"bladeemptysack_P"))
				{
					TakeItemFromCharacter(Pchar, "bladeemptysack_P");
					GiveItem2Character(Pchar, "bladesemifullsack_P");
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladesemifullsack_P");
				}

				LAi_QuestDelay("Pym_books_full_sack_check", 0.1);
			}
		break;

		case "Pym_books_full_sack_check":
			if(CheckCharacterItem(Pchar,"book56") && CheckCharacterItem(Pchar,"book57") && CheckCharacterItem(Pchar,"book58")
			&& CheckCharacterItem(Pchar,"book59") && CheckCharacterItem(Pchar,"book60"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "bladesemifullsack_P");
				GiveItem2Character(Pchar, "bladefullsack_P");
				EquipCharacterByItem(Pchar, "bladefullsack_P");
				PlaySound("OBJECTS\DUEL\man_attack6.wav");
			}
		break;

		case "place_pym_sack":
			Locations[FindLocation(Pchar.location)].models.always.l2 = "sack2";
			Locations[FindLocation("Pym_study")].image = "";
			DoQuestReloadToLocation("Pym_study", "box", "box11", "place_pym_sack1");
		break;

		case "place_pym_sack1":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Logit(TranslateString("","What am I doing wrong?"));
			Pchar.quest.pym_sack = "placed";
			Locations[FindLocation("Pym_study")].image = "GB_Pym_study.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], true);
		break;

		case "take_pym_sack":
			Locations[FindLocation(Pchar.location)].models.always.l2 = "";
			Locations[FindLocation("Pym_study")].image = "";
			DoQuestReloadToLocation("Pym_study", "box", "box11", "take_pym_sack1");
		break;

		case "take_pym_sack1":
			Pchar.quest.pym_sack = "picked_up";
			Locations[FindLocation("Pym_study")].image = "GB_Pym_study.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], true);
		break;

		case "place_pym_big_sack":
	//change loc file here
			Locations[FindLocation(Pchar.location)].models.always.l2 = "sack2_big";
			Locations[FindLocation(Pchar.location)].models.always.locators = "ResP_l_pym_OPEN";
			Locations[FindLocation("Pym_study")].image = "";
			DoQuestReloadToLocation("Pym_study", "box", "box11", "place_pym_big_sack1");
		break;

		case "place_pym_big_sack1":
			PlaySound("INTERFACE\closet_open.wav");
			Pchar.quest.pym_big_sack = "placed";
			Locations[FindLocation("Pym_study")].image = "GB_Pym_study.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], true);

			LAi_QuestDelay("place_pym_big_sack2", 1.5);
		break;

		case "place_pym_big_sack2":
			PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box11", 0.0001);
			Locations[FindLocation("Pym_study")].locators_radius.box.box11 = 0.0001;
		break;

		case "move_Pym_curtain1":
			Locations[FindLocation(Pchar.location)].models.always.locators = "sh05_l_chamber2";
			Locations[FindLocation("Pym_towerroom")].image = "";
			DoQuestReloadToLocation("Pym_towerroom", "goto", "box4", "reset_towerroom_image");
		break;

		case "move_Pym_curtain2":
			LAi_QuestDelay("bladeboom_equip_check", 0.1);
			
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem11", 1.6);
			Locations[FindLocation("Pym_towerroom")].locators_radius.randitem.randitem11 = 1.6;
			Locations[FindLocation(Pchar.location)].models.always.locators = "sh05_l_chamber3";
			Locations[FindLocation("Pym_towerroom")].image = "";
			DoQuestReloadToLocation("Pym_towerroom", "goto", "box5", "reset_towerroom_image");
		break;

		case "reset_towerroom_image":
			PlaySound("PEOPLE\clothes2.wav");
			Locations[FindLocation("Pym_towerroom")].image = "GB_Pym_chamber.tga";
		break;

		case "bladeboom_equip_check":
			if(CheckCharacterItem(Pchar,"pole3_small"))
			{
				TakeItemFromCharacter(Pchar, "pole3_small");
				GiveItem2Character(Pchar, "bladeboom");
				EquipCharacterByItem(Pchar, "bladeboom");

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box7", 0.5);
				Locations[FindLocation("Pym_towerroom")].locators_radius.box.box7 = 0.5;
			}
			else LAi_QuestDelay("bladeboom_equip_check", 0.5);
		break;

		case "close_pym_tower_hatch":
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.0001);
			Locations[FindLocation("Pym_towerroom")].locators_radius.box.box1 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box3", 0.0001);
			Locations[FindLocation("Pym_towerroom")].locators_radius.box.box3 = 0.0001;
			Locations[FindLocation(Pchar.location)].models.always.locators = "sh05_l_chamber4";
			Locations[FindLocation("Pym_towerroom")].image = "";
			DoQuestReloadToLocation("Pym_towerroom", "goto", "box3", "close_pym_tower_hatch1");
		break;

		case "close_pym_tower_hatch1":
			Pchar.quest.pym_hatch = "locked";
			CreateParticleSystem("blast_dirt_small" , 0.6, 3.0, -2.3, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("PEOPLE\counter_close.wav");
			PlaySound("PEOPLE\counter_close.wav");
			Locations[FindLocation("Pym_towerroom")].image = "GB_Pym_chamber.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);

			LAi_QuestDelay("pistolsextant2_check", 0.1);
		break;

		case "pistolsextant2_check":
			if(CheckCharacterItem(Pchar,"pistolsextant2"))
			{
				PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
				AddQuestRecord("Navigation_items","7");
				EquipCharacterByItem(Pchar, "pistolsextant2");
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box6", 0.0001);
				Locations[FindLocation("Pym_towerroom")].locators_radius.box.box6 = 0.0001;
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.5);
				Locations[FindLocation("Pym_towerroom")].locators_radius.box.box1 = 0.5;
			}
			else LAi_QuestDelay("pistolsextant2_check", 0.5);
		break;

		case "tower_box8_check":
			if(CheckAttribute(Pchar,"quest.tower_box1") && Pchar.quest.tower_box1 == "checked")
			{
				if(CheckAttribute(Pchar,"quest.tower_box7") && Pchar.quest.tower_box7 == "checked")
				{
					if(CheckCharacterItem(Pchar,"bladeboom"))
					{
						LAi_SetStayType(pchar);

						LAi_QuestDelay("use_boom_on_hatch", 2.0);
					}
				}
			}
		break;

		case "use_boom_on_hatch":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "use_boom_on_hatch";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "use_boom_on_hatch1":
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);
			LAi_SetPlayerType(pchar);	
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 0.5);
			Locations[FindLocation("Pym_towerroom")].locators_radius.box.box8 = 0.5;
		break;

		case "pym_tower_boom_brakes":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladeboom");
			EquipCharacterByItem(Pchar, "bladeX4");
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 0.0001);
			Locations[FindLocation("Pym_towerroom")].locators_radius.box.box8 = 0.0001;

			LAi_QuestDelay("pchar_oh", 1.0);
			LAi_QuestDelay("use_gp_on_hatch", 2.0);
		break;

		case "use_gp_on_hatch":
			Pchar.quest.tower_box8 = "off";

			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "use_gp_on_hatch";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "use_gp_on_hatch1":
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);
			LAi_SetPlayerType(pchar);	
			TakeItemFromCharacter(Pchar, "BH_sketch");
			GiveItem2Character(Pchar, "BH_sketch_out");

			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
		break;

		case "bladepaperroll_equip_check":
			//from INTERFACE\items.c

			if(CheckCharacterItem(Pchar,"bladepaperroll"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladepaperroll");
				EquipCharacterByItem(Pchar, "pistoltinderbox");

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 0.5);
				Locations[FindLocation("Pym_towerroom")].locators_radius.box.box9 = 0.5;
			}
			else LAi_QuestDelay("bladepaperroll_equip_check", 0.5);
		break;

		case "place_bladepaperroll":
			Locations[FindLocation(Pchar.location)].models.always.locators = "sh05_l_chamber5";			//just testing
			Locations[FindLocation("Pym_towerroom")].image = "";
			DoQuestReloadToLocation("Pym_towerroom", "box", "box9", "place_bladepaperroll1");
		break;

		case "place_bladepaperroll1":
			Locations[FindLocation("Pym_towerroom")].image = "GB_Pym_chamber.tga";
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);
			Pchar.quest.tower_tinderbox = "enabled";

			if(!IsEquipCharacterByItem(Pchar, "bladeX4"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladeX4");
			}
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "pistoltinderbox");
		break;

		case "end_of_tinderbox_tower":
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], true);
			Pchar.quest.tower_tinderbox = "disabled";

			CreateParticleSystem("fort_fire" , 0.0, 3.02, -1.9, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");

			LAi_QuestDelay("pchar_ohoh", 2.0);
			LAi_QuestDelay("end_of_tinderbox_tower1", 5.0);			//was 3 sec
		break;

		case "end_of_tinderbox_tower1":
			PlaySound("OBJECTS\DUEL\pistol_mtoon.wav");

			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("canfire" , 0.0, 3.02, -1.9, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("splinters", 0.0, 3.02, -1.9, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 0.0, 3.02, -1.9, 0.0, 0.0, 0.0, 0);

			Php = LAi_GetCharacterHP(Pchar);
			if(CheckAttribute(Pchar,"quest.tower_hidden") && Pchar.quest.tower_hidden == "yes")
			{
				LAi_ApplyCharacterDamage(Pchar, Php/2);
			
				LAi_QuestDelay("pchar_oooh", 1.0);
				LAi_QuestDelay("end_of_tinderbox_tower2", 2.0);
			}
			else LAi_KillCharacter(Pchar);
		break;

		case "end_of_tinderbox_tower2":
			Locations[FindLocation(Pchar.location)].models.always.locators = "sh05_l_chamber6";
			Locations[FindLocation("Pym_towerroom")].image = "";
			DoQuestReloadToLocation("Pym_towerroom", "goto", "hide", "end_of_tinderbox_tower3");
		break;

		case "end_of_tinderbox_tower3":
			CreateParticleSystem("smoke_short" , 0.3, 3.0, -2.3, 4.5, 1.5, 0.0, sti(20) );

			Locations[FindLocation("Pym_towerroom")].image = "GB_Pym_chamber.tga";
			Pchar.quest.pym_hatch = "open";
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box9", 0.001);
			Locations[FindLocation("Pym_towerroom")].locators_radius.box.box9 = 0.001;
			ChangeCharacterAddressGroup(characterFromID("Arthur Gordon Pym"), "Pym_drawing_room", "goto", "goto4");
			
			pchar.quest.end_of_tinderbox_tower4.win_condition.l1 = "locator";
			pchar.quest.end_of_tinderbox_tower4.win_condition.l1.location = "Pym_towerroom";
			pchar.quest.end_of_tinderbox_tower4.win_condition.l1.locator_group = "goto";
			pchar.quest.end_of_tinderbox_tower4.win_condition.l1.locator = "walk";
			pchar.quest.end_of_tinderbox_tower4.win_condition = "end_of_tinderbox_tower4";
		break;

		case "end_of_tinderbox_tower4":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			AddQuestRecord("Navigation_items","8");
		
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "goto", "bed");
			GiveItem2Character(characterFromID("Jupiter"), "bladespyglass6");			
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladespyglass6");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorSetLayMode(characterFromID("Jupiter"));

			pchar.quest.end_of_tinderbox_tower5.win_condition.l1 = "locator";
			pchar.quest.end_of_tinderbox_tower5.win_condition.l1.location = "Poe_bedroom";
			pchar.quest.end_of_tinderbox_tower5.win_condition.l1.locator_group = "goto";
			pchar.quest.end_of_tinderbox_tower5.win_condition.l1.locator = "start";
			pchar.quest.end_of_tinderbox_tower5.win_condition = "end_of_tinderbox_tower5";
		break;

		case "end_of_tinderbox_tower5":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");
			EquipCharacterByItem(Pchar, "pistolsextant2");
			LAi_SetActorType(Pchar);	
			LAi_ActorGoToLocator(Pchar, "goto", "goto6", "", 2.0);

			LAi_QuestDelay("Jup_equip_spyglass_check", 0.5);
			LAi_QuestDelay("meeting_at_Poes", 2.0);
		break;

		case "Jup_equip_spyglass_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"bladespyglass6"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladespyglass6"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "bladespyglass6");
				}

				LAi_QuestDelay("Jup_equip_spyglass_check", 0.5);
			}
			else return;
		break;

		case "meeting_at_Poes":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			LAi_QuestDelay("meeting_at_Poes1", 1.0);
		break;

		case "meeting_at_Poes1":
			PlaySound("AMBIENT\JAIL\cough.wav");

			LAi_QuestDelay("meeting_at_Poes2", 2.0);
		break;

		case "meeting_at_Poes2":
			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "sit", "sit5");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("meeting_at_Poes2A", 1.5);
		break;

		case "meeting_at_Poes2A":
			PlaySound("PEOPLE\yawn.wav");
			
			LAi_QuestDelay("meeting_at_Poes3", 2.0);
		break;

		case "meeting_at_Poes3":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Poe_bedroom", "goto", "goto1");
			LAi_SetStayType(characterFromID("Jupiter"));

			LAi_QuestDelay("meeting_at_Poes4", 1.0);
		break;

		case "meeting_at_Poes4":
			LAi_SetOfficerType(characterFromID("Jupiter"));
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);

			LAi_QuestDelay("meeting_at_Poes5", 2.0);
		break;

		case "meeting_at_Poes5":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_has_spyglass";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "meeting_at_Poes6":
			//from Jup dialog

			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);

			LAi_QuestDelay("meeting_at_Poes7", 1.0);
		break;

		case "meeting_at_Poes7":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);

			LAi_QuestDelay("meeting_at_Poes8", 1.0);
		break;

		case "meeting_at_Poes8":
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "bladespyglass6");
			EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");

			LAi_QuestDelay("meeting_at_Poes9", 1.0);
		break;

		case "meeting_at_Poes9":
			LAi_SetFightMode(characterFromID("Jupiter"), false);
			GiveItem2Character(Pchar, "bladespyglass6");			
			EquipCharacterbyItem(Pchar, "bladespyglass6");

			LAi_QuestDelay("meeting_at_Poes10", 1.0);
		break;

		case "meeting_at_Poes10":
			LAi_SetFightMode(Pchar, false);

			LAi_QuestDelay("meeting_at_Poes11", 1.0);
		break;
	
		case "meeting_at_Poes11":
			PlaySound("INTERFACE\closed_door.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "reload", "reload1");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("meeting_at_Poes12", 1.0);
		break;

		case "meeting_at_Poes12":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("meeting_at_Poes13", 1.0);
		break;

		case "meeting_at_Poes13":
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("meeting_at_Poes14", 2.0);
		break;

		case "meeting_at_Poes14":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_has_compass";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "meeting_at_Poes15":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Poe_bedroom", "goto", "goto6A");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));	
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "goto", "drawer", "meeting_at_Poes16", 5.0);
		break;

		case "meeting_at_Poes16":
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "drawer");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), characterFromID("Edgar Allan Poe"));
			PlaySound("INTERFACE\key_unlock2.wav");

			LAi_QuestDelay("meeting_at_Poes17", 1.0);
		break;

		case "meeting_at_Poes17":
			PlaySound("INTERFACE\chart_move.wav");
			PlaySound("INTERFACE\chart_move.wav");

			LAi_QuestDelay("meeting_at_Poes18", 1.0);
		break;

		case "meeting_at_Poes18":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_gives_compass";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;
//jump start "12" from here
		case "meeting_at_Poes19":
			//from Poe dialog

					
			SetCurrentTime(7.00, 0);//yes
			SetNextWeather("Clear");

			PlaySound("PEOPLE\clothes1.wav");
			SetModel(Pchar, "William Legrand3", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			GiveItem2Character(Pchar, "bagcompass4");			
			EquipCharacterbyItem(Pchar, "bagcompass4");

			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "first time";
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			ChangeCharacterAddressGroup(characterFromID("GB_storeowner"), "GB_Charleston_store", "barmen", "stay");

			//for jump starts
			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "none", "", "");
//JRH BH2
			Locations[FindLocation("Maroon_cavern")].environment.weather = "false";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "false";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_dry";
			Locations[FindLocation("Maroon_cavern")].models.always.l4 = "";		
			Locations[FindLocation("Maroon_cavern")].models.always.l5 = "barrelC";		
			Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";			
			Locations[FindLocation("Maroon_cavern")].models.always.l7 = "bottleC_cork";
			Pchar.quest.cavern_ladder = "picked_up";
			Pchar.quest.tapC = "closed";
			SetCharacterShipLocation(characterFromID("maroon1"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon2"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon3"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon4"), "Maroon_cavern");
			Characters[GetCharacterIndex("maroon1")].Ship.Type = "obj_invisible";
			Characters[GetCharacterIndex("maroon2")].Ship.Type = "obj_invisible";
			Characters[GetCharacterIndex("maroon3")].Ship.Type = "obj_invisible";
			Characters[GetCharacterIndex("maroon4")].Ship.Type = "obj_invisible";
			Locations[FindLocation("Maroon_cavern")].locators_radius.box.box9 = 0.0001;
			Locations[FindLocation("Maroon_cavern")].locators_radius.box.box11 = 0.0001;

			Pchar.quest.mar_cav_to_bridge = "open";
			Pchar.quest.first_lever_pickup = "no";
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_rope";
			Locations[FindLocation("Charleston_shore")].models.always.l10= "";
			Locations[FindLocation("Charleston_shore")].models.always.l11= "";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.001;

			LAi_QuestDelay("meeting_at_Poes20", 1.0);
		break;
		
		case "meeting_at_Poes20":
			LAi_SetPlayerType(Pchar);

			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			DeleteQuestHeader("Navigation_items");
			AddQuestRecord("Navigation_items","14");
			CloseQuestHeader("Navigation_items");
			AddQuestRecord("Bishop's_Hostel","7");

			Pchar.quest.Poe_home = "yes";		//for the landlady dialog

			Locations[FindLocation("Swamp_loghouse")].reload.l3.disable = 0;	//to stairs
			Pchar.quest.mar_cav_from_plant = "locked";				//to maroon cave
			Pchar.quest.searching_for_key30 = "yes";				//in maroon_hideout

			Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_ground";
			Locations[FindLocation("Charleston_shore")].models.always.l10= "";
			Locations[FindLocation("Charleston_shore")].models.always.l11= "";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box38 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box32 = 0.8;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.5;
			
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "Charleston_swamp_end", "goto", "goto19");

			pchar.quest.mystery_monk_moves.win_condition.l1 = "location";
			pchar.quest.mystery_monk_moves.win_condition.l1.location = "Charleston_swamp_end";
			pchar.quest.mystery_monk_moves.win_condition = "mystery_monk_moves";
		break;
//-------------------------------------------------------------------------------------------------------------------------
		case "mystery_monk_moves":
			LAi_SetActorType(characterFromID("mystery_monk"));	
			LAi_ActorGoToLocator(characterFromID("mystery_monk"), "reload", "reload2", "mystery_monk_moves1", 3.0);
		break;

		case "mystery_monk_moves1":
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "none", "", "");
			PlaySound("INTERFACE\closed_door.wav");

			LAi_QuestDelay("pchar_huh", 0.5);
		break;

		case "key30_pickup_check":
			if(CheckCharacterItem(Pchar,"key30"))
			{
				PlaySound("INTERFACE\took_item.wav");
				Pchar.quest.searching_for_key30 = "no";

				LAi_QuestDelay("key30_pickup_check1", 0.5);
			}
			else LAi_QuestDelay("key30_pickup_check", 0.5);
		break;

		case "key30_pickup_check1":
			PlaySound("PEOPLE\run_wood.wav");
			ChangeCharacterAddressGroup(Pchar, "Maroon_hideout", "goto", "box8");
		break;

		case "unlock_maroon_cave":
			Pchar.quest.mar_cav_from_plant = "open";
			TakenItems(Pchar, "key30", -1);		

			DoQuestReloadToLocation("Maroon_Cavern", "reload", "reload1", "box_enabled");
		break;

		case "wood_steps_are_gone_done":
			//from selfdialog

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_has_idea";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_has_idea_done":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.ch_shore_repeat_gate = "yes";
		break;

		case "Jup_need_plank":
			//from gate closed and lever to the ground

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_need_plank";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_need_plank_done":
			Pchar.quest.Jup_plank = "yes";
			
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorRunToLocator(characterFromID("Jupiter"), "goto", "goto24", "", 10.0);
		break;

		case "Jup_need_plank_done1":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "goto24");
			LAi_SetStayType(characterFromID("Jupiter"));
		break;
	
		case "Jup_has_plank":
			//from lever_from_ground1

			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload3_1");
			GiveItem2Character(characterFromID("Jupiter"), "bladeplank2");
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Jupiter"), "bladeplank2");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorRunToLocator(characterFromID("Jupiter"), "goto", "bars_back", "Jup_has_plank1", 8.0);

			LAi_QuestDelay("Jup_plank_equip_check", 0.1)
			LAi_QuestDelay("Jup_has_plank_sound", 1.0);
		break;
//JRH Jup plank equip check
		case "Jup_plank_equip_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"bladeplank2"))
			{
				//logit("Jup has plank");
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladeplank2"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "bladeplank2");
				}

				LAi_QuestDelay("Jup_plank_equip_check", 0.5);//loop check
			}
	//		else logit("Jup has NOT plank");
		break;

		case "Jup_has_plank_sound":
			PlaySound("OBJECTS\DUEL\plank.wav");
		break;

		case "Jup_has_plank1":
			PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");
			LAi_SetStayType(characterFromID("Jupiter"));
			Pchar.quest.plank_gate = "ready";
			LAi_SetPlayerType(pchar);

			LAi_QuestDelay("Jup_has_plank2", 1.0);
		break;

		case "Jup_has_plank2":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Logit(TranslateString("","Jupiter for God's sake - don't alarm the Maroons."));
		break;

//end of plank story
		case "extra_plank_sound1":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Jupiter"));
		
			LAi_SetOfficerType(characterFromID("Jupiter"));
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box1 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box2", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box2 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box3", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box3 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box6", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box6 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box5 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "officers", "box7_3", 24.0);
			Locations[FindLocation("Charleston_shore")].locators_radius.officers.box7_3 = 24.0;

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "Charleston_shore", "goto", "m1");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "Charleston_shore", "goto", "m2");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "Charleston_shore", "goto", "m3");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "Charleston_shore", "goto", "m4");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "Charleston_shore", "goto", "m5");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "Charleston_shore", "goto", "m6");

			pchar.quest.maroons_stop_us.win_condition.l1 = "locator";
			pchar.quest.maroons_stop_us.win_condition.l1.location = "Charleston_shore";
			pchar.quest.maroons_stop_us.win_condition.l1.locator_group = "officers";
			pchar.quest.maroons_stop_us.win_condition.l1.locator = "box7_3";
			pchar.quest.maroons_stop_us.win_condition = "maroons_stop_us";
		break;

		case "maroons_stop_us":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "maroons_stop_us";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "raft_talk":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "raft_talk";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "raft_talk_done":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorRunToLocator(characterFromID("Jupiter"), "goto", "goto4", "Jup_see_raft", 9.0);
			LAi_SetPlayerType(pchar);

			pchar.quest.Legrand_see_raft.win_condition.l1 = "locator";
			pchar.quest.Legrand_see_raft.win_condition.l1.location = "Charleston_shore";
			pchar.quest.Legrand_see_raft.win_condition.l1.locator_group = "goto";
			pchar.quest.Legrand_see_raft.win_condition.l1.locator = "goto4A";
			pchar.quest.Legrand_see_raft.win_condition = "Legrand_see_raft";
	
			pchar.quest.maroons_cliff_attack.win_condition.l2 = "locator";
			pchar.quest.maroons_cliff_attack.win_condition.l2.location = "Charleston_shore";
			pchar.quest.maroons_cliff_attack.win_condition.l2.locator_group = "goto";
			pchar.quest.maroons_cliff_attack.win_condition.l2.locator = "attack";
			pchar.quest.maroons_cliff_attack.win_condition = "maroons_cliff_attack";
		break;

		case "maroons_cliff_attack":
			LAi_SetImmortal(characterFromID("Jupiter"), false);

			LAi_group_MoveCharacter(characterFromID("maroon1"), "MAROONS_6");
			LAi_group_MoveCharacter(characterFromID("maroon2"), "MAROONS_6");
			LAi_group_MoveCharacter(characterFromID("maroon3"), "MAROONS_6");
			LAi_group_MoveCharacter(characterFromID("maroon5"), "MAROONS_6");
			LAi_group_MoveCharacter(characterFromID("indian_bandit"), "MAROONS_6");
			LAi_group_MoveCharacter(characterFromID("deserter_us1"), "MAROONS_6");
			LAi_group_Register("MAROONS_6");
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "MAROONS_6", LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "MAROONS_6", true);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box8 = 0.001;
		break;

		case "Jup_see_raft":
			LAi_SetStayType(characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "goto4");
		break;

		case "Legrand_see_raft":
			PlaySound("PEOPLE\step_stone1.wav");
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "goto4A");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("Legrand_see_raft1", 0.5);
		break;

		case "Legrand_see_raft1":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");

			LAi_QuestDelay("raft_better_view", 1.0);
		break;

		case "raft_better_view":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "raft_better_view";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "raft_better_view_done":
			LAi_SetPlayerType(pchar);

			pchar.quest.Legrand_see_raft2.win_condition.l1 = "locator";
			pchar.quest.Legrand_see_raft2.win_condition.l1.location = "Charleston_shore";
			pchar.quest.Legrand_see_raft2.win_condition.l1.locator_group = "officers";
			pchar.quest.Legrand_see_raft2.win_condition.l1.locator = "reload3_1";
			pchar.quest.Legrand_see_raft2.win_condition = "Legrand_see_raft2";
		break;

		case "Legrand_see_raft2":
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ships_1");

			LAi_QuestDelay("Legrand_see_raft3", 2.0);
		break;

		case "Legrand_see_raft3":
			PlaySound("PEOPLE\creak2.wav");
			LAi_ActorTurnToLocator(Pchar, "box", "box10");

			LAi_QuestDelay("follow_shore_to_raft", 2.0);
		break;

		case "follow_shore_to_raft":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "follow_shore_to_raft";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "follow_shore_to_raft_done":
			PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
			LAi_SetPlayerType(pchar);	
			
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 1.5);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box8 = 1.5;
		break;

		case "Jup_shore":
			PlaySound("PEOPLE\step_water1.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "Jup_shore");

			LAi_QuestDelay("pchar_bladeboom_check", 0.1);
		break;

		case "are_you_coming":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "are_you_coming";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "are_you_coming_done":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "box11");

			LAi_QuestDelay("are_you_coming_done1", 1.0);
		break;

		case "are_you_coming_done1":
			Pchar.quest.box_blocked = "no";
			Pchar.quest.are_you_coming = "done";
			LAi_SetplayerType(Pchar);
		break;

		case "Pchar_bladeboom_check":
			if(CheckCharacterItem(Pchar,"pole3_small"))
			{
				TakeItemFromCharacter(Pchar, "pole3_small");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				GiveItem2Character(Pchar, "bladeboom");
				EquipCharacterbyItem(Pchar, "bladeboom");
				
				LAi_QuestDelay("Pchar_bladeboom_taken", 1.0);
			}
			else LAi_QuestDelay("pchar_bladeboom_check", 0.5);//loop check
		break;

		case "Pchar_bladeboom_taken":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ships_1");

			LAi_QuestDelay("Jup_takes_boom", 1.0);
		break;

		case "Jup_takes_boom":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_takes_boom";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_takes_boom_done":	
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladeboom");
			GiveItem2Character(characterFromID("Jupiter"), "bladeboom");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladeboom");
			EquipCharacterbyItem(Pchar, "bladespyglass6");
			LAi_SetPlayerType(pchar);

			LAi_QuestDelay("Jup_boom_equip_check", 0.1);
			LAi_QuestDelay("Jup_takes_boom_done1", 1.0);
		break;
//JRH Jup boom equip check

		case "Jup_boom_equip_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"bladeboom"))
			{
				//logit("Jup has boom");
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladeboom"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "bladeboom");
				}

				LAi_QuestDelay("Jup_boom_equip_check", 0.5);//loop check
			}
	//		else logit("Jup has NOT boom");
		break;

		case "Jup_takes_boom_done1":
			PlaySound("PEOPLE\creak2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "raft1_J");
			LAi_SetPoorType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_takes_boom_done2", 1.0);
		break;

		case "Jup_takes_boom_done2":
			PlaySound("PEOPLE\creak2.wav");	
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "raft1_L");
			LAi_SetPoorType(Pchar);
			Characters[GetCharacterIndex("Charleston_guard2")].Ship.Type = "obj_raft2";

			LAi_QuestDelay("Jup_takes_boom_done3", 1.0);
		break;

		case "Jup_takes_boom_done3":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
		break;
	
		case "raft_to_BH":
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Pchar.quest.maroons_on_cliff = "yes";
		break;
	
		case "Jup_climbs_tree":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_climbs_tree";
			LAi_ActorSelfDialog(pchar, "");
		break;
	
		case "Jup_climbs_tree_done":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "Jup_climb1", "Jup_climbs_tree_done1", 4.0);
		break;

		case "Jup_climbs_tree_done1":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb1");

			LAi_QuestDelay("Jup_climbs_tree1", 3.0);
		break;

		case "Jup_climbs_tree1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree1A";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
	//---------------------------------------------------------------------------------
		case "Jup_climbs_tree1B_done":	
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "see_tree", "Legrand_before_climbing", 7.0);
		break;

		case "Legrand_before_climbing":	
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "see_tree");
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");	

			LAi_QuestDelay("Legrand_before_climbing1", 1.0);  
		break;

		case "Legrand_before_climbing1":	
			LAi_SetStayType(Pchar);
			
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			if(!CheckCharacterItem(characterFromID("Jupiter"),"bladeX4")) GiveItem2Character(characterFromID("Jupiter"), "bladeX4");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladeX4");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb1");
			LAi_SetActorType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_climbs_tree_animation2", 1.0);  
		break;
	//---------------------------------------------------------------------------------
		case "Jup_climbs_tree_animation2":
			PlaySound("PEOPLE\step_grass2.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb2");

			LAi_QuestDelay("Jup_climbs_tree_animation3", 2.0);		
		break;
	
		case "Jup_climbs_tree_animation3":
			PlaySound("PEOPLE\step_grass.wav");
			SetModel(characterFromID("Jupiter"), "jupiter", "climb", "man", 1.8, true);	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb3");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation4", 1.2);   
		break;

		case "Jup_climbs_tree_animation4":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb4");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree_animation4A", 1.2);   
		break;

		case "Jup_climbs_tree_animation4A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb4A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation5", 1.2);   
		break;

		case "Jup_climbs_tree_animation5":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb5");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree_animation5A", 1.2);   
		break;

		case "Jup_climbs_tree_animation5A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb5A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation6", 1.2);   
		break;

		case "Jup_climbs_tree_animation6":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb6");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree_animation6A", 1.2);   
		break;

		case "Jup_climbs_tree_animation6A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb6A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation7", 1.2);   
		break;

		case "Jup_climbs_tree_animation7":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb7");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree_animation8", 1.2);   
		break;

		case "Jup_climbs_tree_animation8":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb8");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation9", 1.2);   
		break;

		case "Jup_climbs_tree_animation9":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb9");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree2A", 2.0);   
		break;
//---------------------------------------------------------------------------------------------------------------------------
		case "Jup_climbs_tree2A":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree2A";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
//---------------------------------------------------------------------------------------------------------------------------
		case "Jup_climbs_tree_animation10":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb10");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation11", 1.2);   
		break;

		case "Jup_climbs_tree_animation11":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb11");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree_animation12", 1.2);   
		break;

		case "Jup_climbs_tree_animation12":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb12");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation13", 1.2);   
		break;

		case "Jup_climbs_tree_animation13":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb13");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree3A", 2.0);   
		break;
//---------------------------------------------------------------------------------------------------------------------------
		case "Jup_climbs_tree3A":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree3A";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
//---------------------------------------------------------------------------------------------------------------------------
		case "Jup_climbs_tree_animation14":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb14");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_tree_animation15", 1.2);   
		break;

		case "Jup_climbs_tree_animation15":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "officers", "L_bug_2");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree4A", 2.0);   
		break;
//---------------------------------------------------------------------------------------------------------------------------
		case "Jup_climbs_tree4A":
			PlaySound("VOICE\ENGLISH\blaze_6.wav");

			LAi_QuestDelay("Jup_climbs_tree4B", 2.0);  
		break;

		case "Jup_climbs_tree4B":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_climbs_tree4B";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_climbs_tree4C":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree4C";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
	
		case "Jup_climbs_tree5A":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

			LAi_QuestDelay("Jup_climbs_tree5B", 2.0);  
		break;

		case "Jup_climbs_tree5B":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_climbs_tree5B";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_climbs_tree6":
			LAi_QuestDelay("Jup_climbs_tree6A", 1.0);  
		break;

		case "Jup_climbs_tree6A":
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("Jup_climbs_tree6B", 3.0);  
		break;

		case "Jup_climbs_tree6B":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree6B";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;	

		case "Jup_climbs_tree7":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
	
			LAi_QuestDelay("Jup_climbs_tree8", 1.0);  
		break;	

		case "Jup_climbs_tree8":
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("Jup_climbs_down_animation14", 3.0);  
		break;

		case "Jup_climbs_down_animation14":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb14");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_down_animation13", 1.2);   
		break;

		case "Jup_climbs_down_animation13":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb13");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_down_animation12", 1.2);   
		break;

		case "Jup_climbs_down_animation12":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb12");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_down_animation11", 1.2);   
		break;

		case "Jup_climbs_down_animation11":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb11");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_down_animation10", 1.2);   
		break;

		case "Jup_climbs_down_animation10":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb10");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_down_animation9", 1.2);   
		break;

		case "Jup_climbs_down_animation9":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb9");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_down_animation8", 1.2);   
		break;

		case "Jup_climbs_down_animation8":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb8");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_down_animation7", 1.2);   
		break;

		case "Jup_climbs_down_animation7":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb7");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_down_animation6", 1.2);   
		break;
	
		case "Jup_climbs_down_animation6":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb6");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_down_animation5", 1.2);   
		break;
	
		case "Jup_climbs_down_animation5":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb5");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs_down_animation4", 1.2);   
		break;
	
		case "Jup_climbs_down_animation4":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb4");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs_tree9", 1.2);   
		break;
	
		case "Jup_climbs_tree9":
			PlaySound("PEOPLE\jump_roof.wav");
			SetModel(characterFromID("Jupiter"), "jupiter", "man", "man", 1.8, true);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb1");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_climbs_tree10", 0.5);  
		break;

		case "Jup_climbs_tree10":
			LAi_SetOfficerType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("back_to_Charleston", 7.0); 
		break;

		case "back_to_Charleston":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "back_to_Charleston";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "back_to_Charleston2":
			PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ship_1");

			AddQuestRecord("Bishop's_Hostel","9");
	
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box54", 2.4);
			Locations[FindLocation("Bishops_hostel")].locators_radius.box.box54 = 2.4;

			LAi_QuestDelay("pchar_playertype", 1.0); 
		break;

		case "raft_to_lagoon":
			LAi_SetStayType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Pchar.quest.maroons_on_cliff = "no";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "officers", "box7_3", 30.0);
			Locations[FindLocation("Charleston_shore")].locators_radius.officers.box7_3 = 30.0;

			LAi_QuestDelay("raft_to_lagoon1", 1.5); 
		break;

		case "raft_to_lagoon1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "sneak_around_maroons";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "sneak_around_maroons_done":
			LAi_SetPlayerType(Pchar);

			pchar.quest.no_maroons_left.win_condition.l1 = "locator";
			pchar.quest.no_maroons_left.win_condition.l1.location = "Charleston_shore";
			pchar.quest.no_maroons_left.win_condition.l1.locator_group = "officers";
			pchar.quest.no_maroons_left.win_condition.l1.locator = "box7_3";
			pchar.quest.no_maroons_left.win_condition = "no_maroons_left";
		break;

		case "no_maroons_left":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "no_maroons_left";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "no_maroons_left_done":
			LAi_SetPlayerType(pchar);
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");

			pchar.quest.hidden_maroons.win_condition.l1 = "locator";
			pchar.quest.hidden_maroons.win_condition.l1.location = "Charleston_shore";
			pchar.quest.hidden_maroons.win_condition.l1.locator_group = "goto";
			pchar.quest.hidden_maroons.win_condition.l1.locator = "falling_lever";
			pchar.quest.hidden_maroons.win_condition = "hidden_maroons";
		break;

		case "hidden_maroons":
			LAi_SetStayType(pchar);

			LAi_SetStayType(characterFromID("maroon1"));
			LAi_SetStayType(characterFromID("maroon2"));
			LAi_SetStayType(characterFromID("maroon3"));
			LAi_SetStayType(characterFromID("maroon5"));
			LAi_SetStayType(characterFromID("deserter_us1"));
			LAi_SetStayType(characterFromID("indian_bandit"));
	
			LAi_QuestDelay("hidden_maroons1", 0.5); 
		break;

		case "hidden_maroons1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");

			LAi_SetOfficerType(characterFromID("maroon1"));
		
			LAi_QuestDelay("hidden_maroons2", 3.0); 
			LAi_QuestDelay("hidden_maroons2A", 1.0); 
		break;

		case "hidden_maroons2A":
			//start a little later

			LAi_SetOfficerType(characterFromID("maroon2"));
			LAi_SetOfficerType(characterFromID("maroon5"));	
			LAi_SetOfficerType(characterFromID("maroon3"));
			LAi_SetOfficerType(characterFromID("deserter_us1"));
			LAi_SetOfficerType(characterFromID("indian_bandit"));
		break;

		case "hidden_maroons2":
			LAi_SetActorType(characterFromID("maroon2"));
			LAi_SetActorType(characterFromID("maroon3"));
			LAi_SetActorType(characterFromID("maroon5"));
			LAi_SetActorType(characterFromID("deserter_us1"));
			LAi_SetActorType(characterFromID("indian_bandit"));
			LAi_ActorTurnToCharacter(characterFromID("maroon2"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("maroon3"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("maroon5"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("deserter_us1"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("indian_bandit"), PChar);

			LAi_QuestDelay("hidden_maroons3", 0.5); 
		break;

		case "hidden_maroons3":
			Characters[GetCharacterIndex("maroon1")].dialog.CurrentNode  = "pay_or_die";
			LAi_SetActorType(characterFromID("maroon1"));
			LAi_ActorTurnToCharacter(characterFromID("maroon1"), PChar);
			LAi_ActorDialogNow(characterFromID("maroon1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("maroon1"));
		break;
	
		case "hidden_maroons6":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_whispers_plan";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "hidden_maroons7":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "goto21", "hidden_maroons7A", 2.0);

			LAi_QuestDelay("pchar_playertype", 1.0);
		
			pchar.quest.hidden_maroons7B.win_condition.l1 = "locator";
			pchar.quest.hidden_maroons7B.win_condition.l1.location = "Charleston_shore";
			pchar.quest.hidden_maroons7B.win_condition.l1.locator_group = "goto";
			pchar.quest.hidden_maroons7B.win_condition.l1.locator = "bars_back";
			pchar.quest.hidden_maroons7B.win_condition = "hidden_maroons7B";
		
			pchar.quest.maroons_cliff_attack.win_condition.l2 = "locator";
			pchar.quest.maroons_cliff_attack.win_condition.l2.location = "Charleston_shore";
			pchar.quest.maroons_cliff_attack.win_condition.l2.locator_group = "goto";
			pchar.quest.maroons_cliff_attack.win_condition.l2.locator = "attack2";
			pchar.quest.maroons_cliff_attack.win_condition = "maroons_cliff_attack";
		break;

		case "hidden_maroons7A":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "goto21");
		break;

		case "hidden_maroons7B":
			Characters[GetCharacterIndex("maroon1")].dialog.CurrentNode  = "stay_or_die";
			LAi_SetActorType(characterFromID("maroon1"));
			LAi_ActorTurnToCharacter(characterFromID("maroon1"), PChar);
			LAi_ActorDialogNow(characterFromID("maroon1"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("maroon1"));
		break;

		case "hidden_maroons7C":
			//from maroon dialog

			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		
			pchar.quest.hidden_maroons8.win_condition.l1 = "locator";
			pchar.quest.hidden_maroons8.win_condition.l1.location = "Charleston_shore";
			pchar.quest.hidden_maroons8.win_condition.l1.locator_group = "goto";
			pchar.quest.hidden_maroons8.win_condition.l1.locator = "stop_bars";
			pchar.quest.hidden_maroons8.win_condition = "hidden_maroons8";
		break;

		case "hidden_maroons8":
			Pchar.quest.gate_other_side  = "yes";
			ChangeCharacterAddressGroup(Pchar, "Charleston_shore", "goto", "other_side");
			ChangeCharacterAddressGroup(characterFromID("gate_ghost"), "Charleston_shore", "goto", "invisible_target");
			LAi_SetStayType(Pchar);
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);

			LAi_QuestDelay("hidden_maroons9", 0.5);
		break;

		case "hidden_maroons9":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorAttack(CharacterFromID("Jupiter"), CharacterFromID("gate_ghost"), "");
		break;	

		case "Jup_stops_maroons000":
			//from LAi_events

			PlaySound("PEOPLE\place_planks.wav");
	
			LAi_QuestDelay("Jup_stops_maroons00", 0.5);
		break;	

		case "Jup_stops_maroons00":
			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", "other_side", "Jup_stops_maroons0");
		break;

		case "Jup_stops_maroons0":
			PlaySound("INTERFACE\girder_close.wav");
			CreateParticleSystemX("blast_dirt", -9.1, 13.4, -30.3, -9.1, 13.4, -30.3, 10);

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "Charleston_shore", "goto", "falling_lever");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "Charleston_shore", "goto", "goto18");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "Charleston_shore", "goto", "goto4A");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "Charleston_shore", "goto", "m1");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "Charleston_shore", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "Charleston_shore", "goto", "goto6");

			LAi_SetPlayerType(characterFromID("maroon1"));
			LAi_SetPlayerType(characterFromID("maroon2"));
			LAi_SetPlayerType(characterFromID("maroon3"));
			LAi_SetPlayerType(characterFromID("maroon5"));
			LAi_SetPlayerType(characterFromID("deserter_us1"));
			LAi_SetPlayerType(characterFromID("indian_bandit"));

			LAi_SetFightMode(characterFromID("maroon1"), true);
			LAi_SetFightMode(characterFromID("maroon2"), true);
			LAi_SetFightMode(characterFromID("maroon3"), true);
			LAi_SetFightMode(characterFromID("maroon5"), true);
			LAi_SetFightMode(characterFromID("deserter_us1"), true);
			LAi_SetFightMode(characterFromID("indian_bandit"), true);

			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "goto21");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));
			}

			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			LAi_QuestDelay("Jup_stops_maroons1", 1.5);
		break;	

		case "Jup_stops_maroons1":
			PlaySound("AMBIENT\pirate_captains.wav");

			LAi_SetActorType(characterFromID("maroon1"));
			LAi_ActorGoToLocator(characterFromID("maroon1"), "goto", "bars_back", "", 3.0);

			LAi_SetOfficerType(characterFromID("maroon2"));
		//	LAi_SetOfficerType(characterFromID("maroon5"));	
			LAi_SetOfficerType(characterFromID("maroon3"));
			LAi_SetOfficerType(characterFromID("deserter_us1"));
			LAi_SetOfficerType(characterFromID("indian_bandit"));

			LAi_QuestDelay("Jup_stops_maroons1_A", 2.0);
			LAi_QuestDelay("Jup_stops_maroons2", 3.0);
		break;

		case "Jup_stops_maroons1_A":
			LAi_SetOfficerType(characterFromID("maroon5"));			//was too fast
		break;
	
		case "Jup_stops_maroons2":
			LAi_SetActorType(characterFromID("maroon2"));
			LAi_SetActorType(characterFromID("maroon3"));
			LAi_SetActorType(characterFromID("maroon5"));
			LAi_SetActorType(characterFromID("deserter_us1"));
			LAi_SetActorType(characterFromID("indian_bandit"));

			LAi_QuestDelay("Jup_stops_maroons3", 1.0);
		break;	

		case "Jup_stops_maroons3":
			PlaySound("VOICE\ENGLISH\pir_capCCC.wav");

			LAi_QuestDelay("Jup_stops_maroons4", 1.0);		
		break;	

		case "Jup_stops_maroons4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto7");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "goto7");

			LAi_QuestDelay("Jup_stops_maroons5", 1.0);		
		break;	
//JRH jup boom
		case "Jup_stops_maroons5":
			LAi_SetPlayerType(Pchar);
			LAi_SetSitType(characterFromID("white_trash1"));
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "Charleston_shore", "goto", "goto7A_up1");
			
			LAi_QuestDelay("Jup_stops_maroons5A", 0.7);				
		break;

		case "Jup_stops_maroons5A":
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "Charleston_shore", "goto", "goto7A");

			LAi_QuestDelay("Jup_stops_maroons6", 0.3);				
		break;

		case "Jup_stops_maroons6":
			LAi_SetStayType(characterFromID("white_trash1"));
			LAi_SetOfficerType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("Jup_stops_maroons7", 0.5);				
		break;		

		case "Jup_stops_maroons7":
			LAi_SetImmortal(characterFromID("Jupiter"), false);
			LAi_SetImmortal(Pchar, true);

			LAi_group_MoveCharacter(characterFromID("white_trash1"), "MAROONS_7");	//only member is white_trash1
			LAi_group_Register("MAROONS_7");
			LAi_group_MoveCharacter(characterFromID("Jupiter"), "LAI_GROUP_PLAYER");
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "MAROONS_7", LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "MAROONS_7", true);

			LAi_QuestDelay("Jup_dont_die", 0.1);
			LAi_QuestDelay("pchar_dont_fight", 0.1);				//better if Jup takes this fight

			pchar.quest.Jup_stops_maroons8.win_condition.l1 = "NPC_Death";
			pchar.quest.Jup_stops_maroons8.win_condition.l1.character = "white_trash1";
			pchar.quest.Jup_stops_maroons8.win_condition = "Jup_stops_maroons8";
		break;

		case "Jup_dont_die":
			if(CheckAttribute(Pchar,"quest.white_trash1_fight") && Pchar.quest.white_trash1_fight == "over") return;

			float Jhp = LAi_GetCharacterHP(characterFromID("Jupiter"));
		//LogIt("Jhp = " + Jhp);
			if(Jhp <= 25) LAi_SetImmortal(characterFromID("Jupiter"), true);

			LAi_QuestDelay("Jup_dont_die", 0.5);
		break;

		case "pchar_dont_fight":
			if(CheckAttribute(Pchar,"quest.white_trash1_fight") && Pchar.quest.white_trash1_fight == "over") return;

			if(LAi_IsFightMode(Pchar))
			{
				LAi_SetPlayerType(Pchar);
				LAi_SetFightMode(PChar, false);
			}

			LAi_QuestDelay("pchar_dont_fight", 0.5);
		break;

		case "Jup_stops_maroons8":
			Pchar.quest.white_trash1_fight = "over";
	
			if(LAi_IsFightMode(Pchar))
			{
				LAi_SetPlayerType(Pchar);
				LAi_SetFightMode(PChar, false);
			}

			CreateParticleSystem("stars_short" , -8.5, 13.1, -32.6, 0.0, 0.0, 0.0, sti(20) );

			LAi_QuestDelay("Jup_stops_maroons9", 1.0);	
		break;

		case "Jup_stops_maroons9":
	
			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "silent_seashore";
			PostEvent("LoadSceneSound", 0);
	
			PlaySound("INTERFACE\important_item.wav");
			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			TakeItemFromCharacter(characterFromID("white_trash1"), "MinersSpade");

			Logit(TranslateString("","Yes! I got a Spade from that thug."));
			
			LAi_QuestDelay("Jup_stops_maroons10", 1.0);
		break;

		case "Jup_stops_maroons10":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_hurry_to_the_raft";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_stops_maroons11":
			//start timer to maroons open the gate again

			LAi_SetImmortal(Pchar, false);
			LAi_SetImmortal(characterFromID("Jupiter"), false);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box45", 1.5);
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box45 = 1.5;
//timer starts here
			LAi_QuestDelay("Jup_stops_maroons12", 7.0);		//was 10 sec, was 5.0
		break;

		case "Jup_stops_maroons12":
			PlaySound("INTERFACE\lever_down.wav");
			Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_down";
			Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_up";
			Locations[FindLocation("Charleston_shore")].models.always.l7 = "";		//no plank on ground

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "attack2", 0.001);
			Locations[FindLocation("Charleston_shore")].locators_radius.goto.attack2 = 0.001;

			LAi_QuestDelay("Jup_stops_maroons13", 0.5);
		break;	

		case "Jup_stops_maroons13":
			GetCharacterPos(Pchar, &x, &y, &z);
			nearloc = LAi_FindNearestFreeLocator("goto", x, y, z);

			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "Charleston_shore", "officers", "reload5_1");

			Locations[FindLocation("Charleston_shore")].image = "";
			DoQuestReloadToLocation("Charleston_shore", "goto", nearloc, "Jup_stops_maroons14");
		break;

		case "Jup_stops_maroons14":
			LAi_SetPlayerType(Pchar);

			PlaySound("INTERFACE\girder_open.wav");

			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box44");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetStayType(characterFromID("Jupiter"));
			}
		
			LAi_SetStayType(characterFromID("white_trash1"));
			GiveItem2Character(characterFromID("white_trash1"), "bladeplank2");
			EquipCharacterbyItem(characterFromID("white_trash1"), "bladeplank2");

			LAi_group_MoveCharacter(characterFromID("maroon1"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("maroon2"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("maroon3"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("maroon5"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("indian_bandit"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("deserter_us1"), "MAROONS_8");
			LAi_group_MoveCharacter(characterFromID("white_trash1"), "MAROONS_8");
			LAi_group_Register("MAROONS_8");
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "MAROONS_8", LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "MAROONS_8", true);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "stop_bars", 0.0001);
			Locations[FindLocation("Charleston_shore")].locators_radius.goto.stop_bars = 0.0001;
			Locations[FindLocation("Charleston_passage")].models.always.locators = "pass2_l_GB_raft";

			Locations[FindLocation("Charleston_shore")].image = "Outside_Passage1.tga";

			LAi_QuestDelay("Jup_stops_maroons15", 1.0);	
		break;	

		case "Jup_stops_maroons15":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "bars_back");

			LAi_QuestDelay("Jup_stops_maroons15B", 1.0);
			
			pchar.quest.Jup_stops_maroons16.win_condition.l1 = "locator";
			pchar.quest.Jup_stops_maroons16.win_condition.l1.location = "Charleston_shore";
			pchar.quest.Jup_stops_maroons16.win_condition.l1.locator_group = "quest";
			pchar.quest.Jup_stops_maroons16.win_condition.l1.locator = "greeting";
			pchar.quest.Jup_stops_maroons16.win_condition = "Jup_stops_maroons16";
		break;

		case "Jup_stops_maroons15B":
			LAi_SetPlayerType(Pchar);
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");

			LAi_QuestDelay("Jup_stops_maroons15C", 1.0);
		break;

		case "Jup_stops_maroons15C":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Logit(TranslateString("","I have to run to the raft! But where is Jupiter?"));
		break;

		case "Jup_stops_maroons16":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "quest", "greeting");

			LAi_QuestDelay("pchar_lets_go", 0.7);
			LAi_QuestDelay("Jup_stops_maroons17", 1.7);		
		break;
	
		case "Jup_stops_maroons17":
			PlaySound("PEOPLE\step_water1.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "box", "box45");

			LAi_QuestDelay("Jup_stops_maroons18", 0.5);	
		break;

		case "Jup_stops_maroons18":
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetPoorType(characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box46_jup");
		break;

		case "raft_to_passage":	
			Locations[FindLocation("Charleston_passage")].MaxSeaHeight = 0.1;
			DoQuestReloadToLocation("Charleston_passage", "goto", "arrive", "raft_to_passage1");
		break;

		case "raft_to_passage1":
			LAi_SetStayType(Pchar);
	
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_passage", "goto", "arrive_Jup");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetStayType(characterFromID("Jupiter"));
			}

			LAi_QuestDelay("raft_to_passage1A", 0.5);
			LAi_QuestDelay("raft_to_passage2", 1.5);	
		break;

		case "raft_to_passage1A":
			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "silent_seashore";
			PostEvent("LoadSceneSound", 0);	
		break;

		case "raft_to_passage2":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "raft_to_passage";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "raft_to_passage3":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "m7");

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "Charleston_passage", "goto", "m1");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "Charleston_passage", "goto", "m5");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "Charleston_passage", "goto", "m6");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "Charleston_passage", "goto", "m3");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "Charleston_passage", "goto", "m2");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "Charleston_passage", "goto", "m4");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "Charleston_passage", "goto", "m7");

			LAi_QuestDelay("raft_to_passage4", 1.0);
			
		break;

		case "raft_to_passage4":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "m7");
			
			LAi_QuestDelay("raft_to_passage4A", 1.0);
		break;

		case "raft_to_passage4A":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "maroons_at_passage";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "raft_to_passage5":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			
			LAi_QuestDelay("raft_to_passage6", 2.0);
		break;

		case "raft_to_passage6":
			PlaySound("PEOPLE\step_water1.wav");
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(Pchar, "Charleston_passage", "box", "box3");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_passage", "goto", "Jup_raft");
			LAi_SetPoorType(Pchar);
			LAi_SetPoorType(characterFromID("Jupiter"));

			LAi_QuestDelay("raft_to_passage7", 2.0);
		break;

		case "raft_to_passage7":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Pchar.quest.hideout.box10 = "locked";
			Pchar.quest.Loghouse_stairs.box2 = "locked";
			Pchar.quest.searching_for_key30 = "no";						//for ev jumpstarts, key30 is already picked up
			Characters[GetCharacterIndex("Charleston_guard1")].Ship.Type = "obj_raft3";	//in hideout

			SetNextWeather("Clear");
			Pchar.quest.JRH_rain = "clear";	

			LAi_QuestDelay("raft_to_hideout", 1.0);
		break;

		case "raft_to_hideout":	
			DoQuestReloadToLocation("Maroon_hideout", "goto", "arrive", "raft_to_hideout1");
		break;
//JRH Jup bo boom any longer
		case "raft_to_hideout1":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			LAi_SetPlayerType(Pchar);

			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Maroon_hideout", "goto", "arrive_Jup");
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
				LAi_SetOfficerType(characterFromID("Jupiter"));

				RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("Jupiter"), "bladeboom");

				if(!CheckCharacterItem(characterFromID("Jupiter"),"bladeX4")) GiveItem2Character(characterFromID("Jupiter"), "bladeX4");
				EquipCharacterbyItem(characterFromID("Jupiter"), "bladeX4");
			}

			pchar.quest.hideout_knock.win_condition.l1 = "locator";
			pchar.quest.hideout_knock.win_condition.l1.location = "Maroon_hideout";
			pchar.quest.hideout_knock.win_condition.l1.locator_group = "box";
			pchar.quest.hideout_knock.win_condition.l1.locator = "box10";
			pchar.quest.hideout_knock.win_condition = "hideout_knock";
		break;

		case "hideout_knock":
			PlaySound("INTERFACE\knock.wav");
			LAi_SetStayType(pchar);

			LAi_QuestDelay("hideout_locked", 2.0);
		break;

		case "hideout_locked":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "hideout_locked";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "kungfu_hint":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "kungfu_hint";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "kungfu_hint_done":
			LAi_SetPlayerType(pchar);
			Pchar.quest.jup_kungfu = "yes";

			pchar.quest.passage_empty.win_condition.l1 = "location";
			pchar.quest.passage_empty.win_condition.l1.location = "Charleston_passage";
			pchar.quest.passage_empty.win_condition = "passage_empty";
		break;

		case "passage_empty":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "passage_empty";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "passage_empty_done":
			LAi_SetPlayerType(pchar);

			LAi_QuestDelay("last_meeting_at_Poes", 0.1);
		break;
//JRH 12
//jump start "13" from here
//----------------------------------------------------------------------------------------------------------------------
		case "last_meeting_at_Poes":
			DeleteQuestHeader("Bishop's_Hostel");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","9");
		//	SetQuestHeader("The_Message");
		//	AddQuestRecord("The_Message","24");
		//	CloseQuestHeader("The_Message");

			Locations[FindLocation("GB_Charleston_town")].reload.l13.disable = 1;//lock to tailor, easiest
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Pchar.quest.mar_cav_from_plant = "open"
			Pchar.quest.mar_cav_to_bridge = "closed";
			Pchar.quest.mar_cav_to_hideout = "open";
			Pchar.quest.hideout.box10 = "locked";
			Pchar.quest.trader_Pym_hint = "yes";

		//	LAi_QuestDelay("fort_open", 0.1);	//very strange: jump 12 it has no effect, playong from earlire it has = you get teleported to the Fort. completely wrong we're on our way to Poe's
	
		Pchar.quest.devils_seat_found = "yes";
		Pchar.quest.Fort_visit = "1";
		Pchar.quest.Jupiter_equip = "case1";
		Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
		Pchar.quest.Ch_town_box6 = "locked";		//brothel
		Pchar.quest.town_exit_closed = "no";
		Pchar.quest.boathouse = "return";
	
			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("GB_storeowner"), "GB_Charleston_store", "barmen", "stay");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "landlady_private", "goto", "bed1");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorSetLayMode(characterFromID("Edgar Allan Poe"));
			SetModel(characterFromID("Edgar Allan Poe"), "Poe_private", "man", "man", 1.8, true);
			ChangeCharacterAddressGroup(characterFromID("landlady"), "landlady_private", "goto", "lady1");
			LAi_SetActorType(characterFromID("landlady"));
			SetModel(characterFromID("landlady"), "landlady_private", "woman", "woman", 1.8, true);
			GiveItem2Character(characterFromID("landlady"), "bladeX4");
			EquipCharacterbyItem(characterFromID("landlady"), "bladeX4");
			GiveItem2Character(characterFromID("landlady"), "pistolwhip");
			EquipCharacterbyItem(characterFromID("landlady"), "pistolwhip");
		
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist5"), "Moultrie_restaurant", "sit", "sit7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist7"), "Moultrie_restaurant", "sit", "sit5");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist9"), "Moultrie_restaurant", "sit", "sit8");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist10"), "Moultrie_restaurant", "sit", "sit23");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist11"), "Moultrie_restaurant", "sit", "sit21");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist6"), "Fort_Moultrie_village", "reload", "reload7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist8"), "Moultrie_finehouse", "goto", "locator1");
			
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload9 = 1.5;
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box4 = 0.001;
			Locations[FindLocation("GB_Chinatown")].reload.l9.disable = 1;
		//	Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box4 = 0.0001;
			Locations[FindLocation("Maroon_Hideout")].models.always.locators = "Cave_Ship_l_GB_open";
			Locations[FindLocation("Maroon_Hideout")].locators_radius.goto.steplock = 0.5;
			Characters[GetCharacterIndex("Charleston_guard1")].Ship.Type = "obj_raft3";	//in hideout
			locations[FindLocation("Poe_bedroom")].models.always.locators = "largehouse02_locators_GB_open";	//open now to landlady downstairs
			Locations[FindLocation("Legrands_house")].reload.l3.disable = 0;		//grot	
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2";
			locations[FindLocation("Fort_Moultrie_village")].type = "Fort_Moultrie_village";//music
			locations[FindLocation("Moultrie_hotel")].id.label = "Fort Moultrie hotel";
			locations[FindLocation("Moultrie_restaurant")].id.label = "Fort Moultrie restaurant";
			locations[FindLocation("Moultrie_store")].id.label = "Fort Moultrie store";
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "sml_l_GB_open_smoke2";
			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l6.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l10.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l12.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.close_for_night = 1;	//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.close_for_night = 1;	//largehouse
			Locations[FindLocation("Fort_Moultrie_shore")].models.always.locators = "Shore01_l_GB2";

			pchar.quest.Poe_and_landlady.win_condition.l1 = "location";
			pchar.quest.Poe_and_landlady.win_condition.l1.location = "landlady_private";
			pchar.quest.Poe_and_landlady.win_condition = "Poe_and_landlady";
		break;

		case "Poe_and_landlady":
			ChangeCharacterAddressGroup(Pchar, "landlady_private", "goto", "huh");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("Poe_and_landlady1", 1.0);
		break;

		case "Poe_and_landlady1":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(characterFromID("landlady"), "landlady_private", "goto", "lady2");

			LAi_QuestDelay("Poe_and_landlady2", 1.0);
		break;

		case "Poe_and_landlady2":
			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "landlady_private", "goto", "bed2");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("Poe_and_landlady3", 1.0);
		break;

		case "Poe_and_landlady3":
			PlaySound("VOICE\ENGLISH\Fre_f_a_009.wav");
			LAi_SetActorType(characterFromID("landlady"));
			LAi_ActorGoToLocator(characterFromID("landlady"), "reload", "reload1", "Poe_and_landlady4", 5.0);
		break;

		case "Poe_and_landlady4":
			ChangeCharacterAddressGroup(Pchar, "landlady_private", "goto", "huh2");
		
			PlaySound("INTERFACE\key_unlock.wav");
			Locations[FindLocation("Poe_entre")].reload.l3.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("landlady"), "Poe_entre", "goto", "goto3");
			LAi_SetStayType(characterFromID("landlady"));
			Pchar.quest.Poe_home = "private";

			LAi_QuestDelay("Poe_and_landlady5", 2.0);
		break;
		
		case "Poe_and_landlady5":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "landlady_private", "goto", "stay1");
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("Poe_and_landlady5A", 0.5);
		break;

		case "Poe_and_landlady5A":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_and_landlady";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_and_landlady6":
			LAi_SetPlayerType(Pchar);

			pchar.quest.last_Poe_bedroom.win_condition.l1 = "location";
			pchar.quest.last_Poe_bedroom.win_condition.l1.location = "poe_bedroom";
			pchar.quest.last_Poe_bedroom.win_condition = "last_Poe_bedroom";
		break;

		case "last_Poe_bedroom":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "stay4", "last_Poe_bedroom1", 4.0);
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "stay1", "", 4.0);
		break;

		case "last_Poe_bedroom1":
			ChangeCharacterAddressGroup(Pchar, "poe_bedroom", "goto", "stay4");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "poe_bedroom", "goto", "stay1");	

			LAi_QuestDelay("last_Poe_bedroom2", 1.0);
		break;

		case "last_Poe_bedroom2":
			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(Pchar, "poe_bedroom", "sit", "sit4");
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("last_Poe_bedroom2A", 1.0);
		break;

		case "last_Poe_bedroom2A":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "poe_bedroom", "sit", "sit1");
			LAi_SetSitType(characterFromID("Jupiter"));			

			LAi_QuestDelay("last_Poe_bedroom3", 3.0);
		break;

		case "last_Poe_bedroom3":
			PlaySound("INTERFACE\closed_door.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "poe_bedroom", "reload", "reload1");
			SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe", "man", "man", 1.8, true);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "goto", "stay2", "last_Poe_bedroom4", 4.0);
		break;

		case "last_Poe_bedroom4":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "poe_bedroom", "goto", "stay2");

			LAi_QuestDelay("last_Poe_bedroom6", 1.0);
		break;
	
		case "last_Poe_bedroom6":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "last_Poe_bedroom";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "last_Poe_bedroom7":
			//from Poe dialog

			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(Pchar, "poe_bedroom", "goto", "stay4");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("last_Poe_bedroom7A", 1.0);
		break;

		case "last_Poe_bedroom7A":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "poe_bedroom", "goto", "stay2");
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);

			LAi_QuestDelay("last_Poe_bedroom8", 1.0);
		break;

		case "last_Poe_bedroom8":
			//from Poe dialog

			PlaySound("INTERFACE\wheel_take.wav");
			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladecompass4");
			
			LAi_QuestDelay("last_Poe_bedroom10", 1.0);
		break;
	
		case "last_Poe_bedroom10":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "last_Poe_bedroom_H";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "last_Poe_bedroom11":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "I_get_the_boat";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "last_Poe_bedroom11A":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");

			LAi_QuestDelay("last_Poe_bedroom12", 1.0);
		break;

		case "last_Poe_bedroom12":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "outside_gates";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "last_Poe_bedroom13":
			LAi_SetPlayerType(pchar);
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			AddQuestRecord("Bishop's_Hostel","10");
			SetQuestHeader("Weapons");
			AddQuestRecord("Weapons","1");

			pchar.quest.split_company.win_condition.l1 = "locator";
			pchar.quest.split_company.win_condition.l1.location = "Fort_Moultrie_exit";
			pchar.quest.split_company.win_condition.l1.locator_group = "reload";
			pchar.quest.split_company.win_condition.l1.locator = "reload3";
			pchar.quest.split_company.win_condition = "split_company";
		break;

		case "split_company":
			if(IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			}

			DoQuestReloadToLocation("Fort_Moultrie_exit", "officers", "reload3_2", "jup_boat_mission");
		break;
//JRH
		case "jup_boat_mission":



			LAi_QuestDelay("switch_to_Jupiter", 0.01);
			LAi_QuestDelay("jup_boat_mission0", 0.5);

			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "Fort_Moultrie_exit", "reload", "reload3");
			GiveItem2Character(characterFromID("Legrand_copy"), "bladespade");
			EquipCharacterbyItem(characterFromID("Legrand_copy"), "bladespade");
			GiveItem2Character(characterFromID("Legrand_copy"), "pistolsextant2");
			EquipCharacterbyItem(characterFromID("Legrand_copy"), "pistolsextant2");

			LAi_SetStayType(characterFromID("Legrand_copy"));

			LAi_QuestDelay("jup_boat_mission1", 2.0);
		break;

		case "jup_boat_mission0":
			TakeItemFromCharacter(Pchar, "wrinkled_paper" );
		break;

		case "jup_boat_mission1":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");

			LAi_QuestDelay("jup_boat_mission2", 1.0);
		break;

		case "jup_boat_mission2":
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "none", "", "");
			LAi_SetPlayerType(Pchar);

			DeleteQuestHeader("Bishop's_Hostel");
			DeleteQuestHeader("Jupiters_wood_mission");
			DeleteQuestHeader("The_message");
			DeleteQuestHeader("Weapons");

			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items","11");
			SetQuestHeader("Weapons");
			AddQuestRecord("Weapons","2");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","11");

			Pchar.quest.boathouse = "boat";
			Pchar.quest.backyard = "open";
			Pchar.quest.go_to_well = "no";
			Pchar.quest.go_to_attic = "phase0";
			Pchar.quest.grot_sacks = "available";

			pchar.quest.attic_sacks_check1.win_condition.l1 = "location";
			pchar.quest.attic_sacks_check1.win_condition.l1.location = "Legrands_attic";
			pchar.quest.attic_sacks_check1.win_condition = "attic_sacks_check1";
		break;

		case "key2_found":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"I found de Key."));
		break;

		case "attic_sacks_check1":
			if(CheckCharacterItem(Pchar,"sack3"))
			{
				if(Pchar.location == "Legrands_attic")
				{
					TakeItemFromCharacter(Pchar, "sack3");
					GiveItem2Character(Pchar, "emptysack");

					LAi_QuestDelay("attic_sacks_check2", 0.1);
				}
				else LAi_QuestDelay("attic_sacks_check1", 0.5);//loop check
			}
			else LAi_QuestDelay("attic_sacks_check1", 0.5);//loop check
		break;

		case "attic_sacks_check2":
			if(CheckCharacterItem(Pchar,"sack3"))
			{
				if(Pchar.location == "Legrands_attic")
				{
					TakeItemFromCharacter(Pchar, "sack3");
					GiveItem2Character(Pchar, "emptysack");
					Pchar.quest.attic_sacks = sti(Pchar.quest.attic_sacks) + 2;

					LAi_QuestDelay("5_empty_sacks_attic_check", 1.0);
					LAi_QuestDelay("8_empty_sacks_check", 0.1);
				}
				LAi_QuestDelay("attic_sacks_check2", 0.5);//loop check
			}
			else LAi_QuestDelay("attic_sacks_check2", 0.5);//loop check
		break;

		case "hut_take_mtoon":	
			if(!CheckAttribute(Pchar,"quest.weapons_message3") || Pchar.quest.weapons_message3 != "done")
			{
				if(CheckCharacterItem(Pchar,"pistolmtoon"))
				{
					EquipCharacterbyItem(Pchar, "pistolmtoon");
					AddQuestRecord("Weapons","3");
					CloseQuestHeader("Weapons");
					Pchar.quest.weapons_message3 = "done";

					LAi_QuestDelay("8_sacks_&_mtoon_check", 0.1);
				}
			}

			int pmt = GetCharacterItem(pchar, "pistolmtoon");
		
			if(pmt == 2)
			{
				PlaySound("OBJECTS\DUEL\sword_fallen.wav");
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I take only one Musketoon."));
				TakenItems(Pchar, "pistolmtoon", -1);
				locations[FindLocation(Pchar.location)].box2.items.pistolmtoon = 1;
			}

			if(CheckCharacterItem(Pchar,"machete"))
			{
				EquipCharacterbyItem(Pchar, "machete");
			}

			LAi_QuestDelay("8_empty_sacks_check", 0.1);
		break;

		case "forgot_the_sails":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Oh yes, the Sails!"));
			Pchar.quest.boathouse = "sail";
		break;

		case "pickup_sails_check":
			if(CheckCharacterItem(Pchar,"sail"))
			{
				PlaySound("PEOPLE\clothes1.wav");
				Pchar.quest.boathouse = "boat";
				ChangeCharacterAddressGroup(Pchar, "Legrands_boathouse", "goto", "box6");
				SetModel(Pchar, "jupiter_sails", "man", "man", 1.8, true);
				TakeItemFromCharacter(Pchar, "sail");
				GiveItem2Character(Pchar, "sailbag");
			}
			else LAi_QuestDelay("pickup_sails_check", 0.5);//loop check
		break;

		case "set_sails":
			TakeItemFromCharacter(Pchar, "sailbag");
			Locations[FindLocation("Legrands_boathouse")].image = "";
			DoQuestReloadToLocation("Legrands_boathouse", "box", "box5", "set_sails1");	
		break;

		case "set_sails1":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Pchar.sails_on_boat = "yes";
			Locations[FindLocation("Legrands_boathouse")].image = "GB_Legrands_boathouse.tga";

			pchar.quest.leave_boathouse.win_condition.l1 = "locator";
			pchar.quest.leave_boathouse.win_condition.l1.location = "Legrands_boathouse";
			pchar.quest.leave_boathouse.win_condition.l1.locator_group = "reload";
			pchar.quest.leave_boathouse.win_condition.l1.locator = "reload2_back";
			pchar.quest.Legrands_boathouse.win_condition = "Legrands_boathouse";
		break;

		case "leave_boathouse":
			DoQuestReloadToLocation("Sullivan_jungle2", "reload", "reload2", "");
		break;
		
		case "throw_the_flour_done":
			LAi_SetPlayerType(Pchar);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box6", 0.0001);
			Locations[FindLocation("Legrands_grot")].locators_radius.box.box6 = 0.0001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem10", 1.5);
			Locations[FindLocation("Legrands_grot")].locators_radius.randitem.randitem10 = 1.5;

			LAi_QuestDelay("flour_sacks_check1", 0.5);
		break;

		case "flour_sacks_check1":
			if(CheckCharacterItem(Pchar,"sack3"))
			{
				if(Pchar.location == "Legrands_grot")
				{
					PlaySound("PEOPLE\gunpowder.wav");
					PlaySound("OBJECTS\SHIPCHARGE\c2waitB.wav");
					CreateParticleSystemX("blast_dirt_gray", 3.2, -1.35, -1.7, 3.2, -1.35, -1.7, 10);
					TakeItemFromCharacter(Pchar, "sack3");
					GiveItem2Character(Pchar, "emptysack");

					SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem10", 0.001);
					Locations[FindLocation("Legrands_grot")].locators_radius.randitem.randitem10 = 0.001;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem11", 1.5);
					Locations[FindLocation("Legrands_grot")].locators_radius.randitem.randitem11 = 1.5;
		
					LAi_QuestDelay("flour_sacks_check2", 0.1);
				}
				else LAi_QuestDelay("flour_sacks_check1", 0.5);//loop check
			}
			else LAi_QuestDelay("flour_sacks_check1", 0.5);//loop check
		break;

		case "flour_sacks_check2":
			if(CheckCharacterItem(Pchar,"sack3"))
			{
				if(Pchar.location == "Legrands_grot")
				{
					PlaySound("PEOPLE\gunpowder.wav");
					PlaySound("OBJECTS\SHIPCHARGE\c4waitB.wav");
					CreateParticleSystemX("blast_dirt_gray", 2.6, -0.95, -1.1, 2.6, -0.95, -1.1, 10);
					TakeItemFromCharacter(Pchar, "sack3");
					GiveItem2Character(Pchar, "emptysack");

					SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem11", 0.001);
					Locations[FindLocation("Legrands_grot")].locators_radius.randitem.randitem11 = 0.001;
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem17", 1.5);
					Locations[FindLocation("Legrands_grot")].locators_radius.randitem.randitem17 = 1.5;

					LAi_QuestDelay("flour_sacks_check3", 0.1);
				}
				else LAi_QuestDelay("flour_sacks_check2", 0.5);//loop check
			}
			else LAi_QuestDelay("flour_sacks_check2", 0.5);//loop check
		break;

		case "flour_sacks_check3":
			if(CheckCharacterItem(Pchar,"sack3"))
			{
				if(Pchar.location == "Legrands_grot")
				{
					PlaySound("PEOPLE\gunpowder.wav");
					PlaySound("OBJECTS\SHIPCHARGE\c5waitB.wav");
					CreateParticleSystemX("blast_dirt_gray", 2.9, -1.15, -1.5, 2.9, -1.15, -1.5, 10);
					TakeItemFromCharacter(Pchar, "sack3");
					GiveItem2Character(Pchar, "emptysack");

					LAi_QuestDelay("8_empty_sacks_check", 0.1);
				}
				else LAi_QuestDelay("flour_sacks_check3", 0.5);//loop check
			}
			else LAi_QuestDelay("flour_sacks_check3", 0.5);//loop check
		break;

		case "3_empty_sacks_attic_check":
			if(locations[FindLocation(Pchar.location)].box2.items.emptysack == 0) 
			{
				Pchar.quest.attic_sacks = sti(Pchar.quest.attic_sacks) + 3;

				LAi_QuestDelay("5_empty_sacks_attic_check", 0.1);
			}		
		break;

		case "5_empty_sacks_attic_check":
			if(sti(Pchar.quest.attic_sacks) == 5)
			{
				LAi_SetStayType(Pchar);
				PlaySound("PEOPLE\roof_creak.wav");

				LAi_QuestDelay("attic_blocked", 1.0);
				LAi_QuestDelay("attic_blocked1", 3.0);
			}

			//Logit("6 empty sacks attic checked");			
		break;

		case "attic_blocked":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
		break;

		case "attic_blocked1":
			Pchar.quest.attic_box1 = "blocked";
			LAi_SetSitType(Pchar);
			Locations[FindLocation("Legrands_backyard")].models.always.locators = "QCexit_l_GB_tree";

			PlaySound("PEOPLE\derrick_fall.wav");
			PlaySound("PEOPLE\roof_broken1.wav");
			PlaySound("PEOPLE\wood3.wav");
			PlaySound("PEOPLE\wood3.wav");

			LAi_QuestDelay("pchar_playertype", 0.5);
			LAi_QuestDelay("attic_blocked2", 1.0);
		break;

		case "attic_blocked2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box1");
			CreateParticleSystemX("blast_dirt", -0.2, 1.0, -3.1, -0.2, 1.0, -3.1, 10);

			LAi_QuestDelay("attic_blocked3", 1.0);
		break;

		case "attic_blocked3":
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
		break;

		case "attic_door_blocked":
			Logit(TranslateString("","A Tree must have fallen and blocked de Door!!"));
			PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box4", 0.5);
			Locations[FindLocation("Legrands_attic")].locators_radius.box.box4 = 0.5;
		break;

		case "8_empty_sacks_check":
			int e_s = GetCharacterItem(Pchar, "emptysack");
			if(e_s == 8)
			{
				PlaySound("VOICE\ENGLISH\gm_crew7.wav");
				Logit(TranslateString("","That's enough of Empty Sacks!"));
				AddQuestRecord("Useful_items","13");
				CloseQuestHeader("Useful_items");

				LAi_QuestDelay("8_sacks_&_mtoon_check", 0.1);
			}

			//Logit("12 empty sacks checked");			
		break;

		case "8_sacks_&_mtoon_check":
			e_s = GetCharacterItem(Pchar, "emptysack");
			if(e_s == 8 && CheckCharacterItem(Pchar,"pistolmtoon"))
			{	
				Pchar.quest.boathouse = "boat";
			}
		break;

		case "need_machete":
			Pchar.quest.machete_hint = "done";
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "need_machete";
			LAi_ActorSelfDialog(Pchar, "");
		break;

		case "need_machete_done":
			LAi_SetPlayerType(Pchar);
			AddQuestRecord("Useful_items","12");
		break;

		case "machete_broken":
			PlaySound("OBJECTS\DUEL\sword_broken.wav");

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterbyItem(Pchar, "bladeX4");
			TakeItemFromCharacter(Pchar, "machete");
			LAi_SetFightMode(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Legrands_attic")], true);

			LAi_QuestDelay("machete_broken1", 1.0);
		break;

		case "machete_broken1":
			Logit(TranslateString("","That Machete was just crap!"));
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
		break;
	
		//----------------------------------------------------------		
	
		case "facade_box10":
			PlaySound("PEOPLE\step_stairway.wav");
			PlaySound("PEOPLE\step_stairway.wav");
			PlaySound("PEOPLE\step_stairway.wav");
			Pchar.quest.facade_box11 = "free";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "facade");
		break;

		case "Jup_first_to_BH":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_first_to_BH";
			LAi_ActorSelfDialog(pchar, "");
		break;
//JRH switch to Legrand after Jup boat
		case "Jup_first_to_BH_done":
			//switch to Legrand revolver mission here

			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			DoQuestReloadToLocation("Fort_Moultrie_village", "reload", "reload1", "pchar_playertype");		
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_Moultrie_barracks", "sit", "sit13");
			LAi_SetSitType(characterFromID("Lieutenant G"));

			DeleteAttribute(Pchar, "items");
			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladespyglass6");
			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			GiveItem2Character(Pchar, "pistolsextant2");
			EquipCharacterbyItem(Pchar, "pistolsextant2");
			AddMoneyToCharacter(Pchar,-1000);
			TakeItemFromCharacter(Pchar, "map");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");

			if(CheckAttribute(Pchar,"quest.Legrands_antidote") && Pchar.quest.Legrands_antidote == "yes")
			TakenItems(Pchar, "potion3", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_rum") && Pchar.quest.Legrands_rum == "yes")
			TakenItems(Pchar, "potionrum", 1);

			DeleteQuestHeader("Weapons");
			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("Bishop's_Hostel");

			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items","14");
			SetQuestHeader("Weapons");
			AddQuestRecord("Weapons","1");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","10");
		
			Pchar.quest.Fort_M_south_wall_right = "closed";
			Pchar.locked_cells = "0";

			Pchar.quest.Fort_visit = "3";
			Locations[FindLocation("Fort_Moultrie")].reload.l10.disable = 0;		//barracks
			Locations[FindLocation("Fort_Moultrie")].reload.l3.disable = 1;			//tower1A
			Locations[FindLocation("Fort_M_tower1B")].reload.l8.disable = 0;		//gate wall
			Locations[FindLocation("Fort_M_tower2B")].reload.l4.disable = 0;		//up to 2C
			Locations[FindLocation("Fort_M_tower2B")].reload.l8.disable = 1;		//wall, direction G house
			Locations[FindLocation("Fort_M_tower2C")].reload.l2.emerge = "box14";		//at top

			pchar.quest.Fort_visit3.win_condition.l1 = "locator";
			pchar.quest.Fort_visit3.win_condition.l1.location = "Fort_Moultrie_barracks";
			pchar.quest.Fort_visit3.win_condition.l1.locator_group = "sit";
			pchar.quest.Fort_visit3.win_condition.l1.locator = "sit13";
			pchar.quest.Fort_visit3.win_condition = "Fort_visit3";

			pchar.quest.open_tower1.win_condition.l2 = "locator";
			pchar.quest.open_tower1.win_condition.l2.location = "Fort_M_tower1A";
			pchar.quest.open_tower1.win_condition.l2.locator_group = "reload";
			pchar.quest.open_tower1.win_condition.l2.locator = "reload7";
			pchar.quest.open_tower1.win_condition = "open_tower1";
		break;

		case "Fort_visit3":
			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "visit3";
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToCharacter(characterFromID("Lieutenant G"), PChar);
			LAi_ActorDialogNow(characterFromID("Lieutenant G"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Lieutenant G"));
		break;

		case "visit3_done":
			if(IsEquipCharacterByItem(Pchar, "bladespyglass6")) RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladespyglass6");
			GiveItem2Character(characterFromID("Lieutenant G"), "bladespyglass6");
			PlaySound("PEOPLE\spyglass.wav");

			LAi_QuestDelay("Fort_visit3_A", 1.0);
		break;

		case "Fort_visit3_A":
			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "visit3_A";
			LAi_SetActorType(characterFromID("Lieutenant G"));
			LAi_ActorTurnToCharacter(characterFromID("Lieutenant G"), PChar);
			LAi_ActorDialogNow(characterFromID("Lieutenant G"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Lieutenant G"));
		break;

		case "visit3_F_done":
			GiveItem2Character(Pchar, "key31");
			PlaySound("INTERFACE\took_item.wav");
			AddQuestRecord("Weapons","5");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_Moultrie_barracks", "sit", "sit13");
			LAi_SetSitType(characterFromID("Lieutenant G"));
			Characters[GetCharacterIndex("Lieutenant G")].dialog.CurrentNode  = "First time";
		break;

		case "open_tower1":
			Locations[FindLocation("Fort_Moultrie")].reload.l3.disable = 0;
		break;

		case "place_fort_ladder":
			LAi_LocationFightDisable(&Locations[FindLocation("Fort_Moultrie")], false);
			Characters[GetCharacterIndex("Moultrie_sergeant")].dialog.CurrentNode  = "what_you_want";
			EquipCharacterbyItem(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "pistolsextant2");
			Locations[FindLocation("Fort_Moultrie")].image = "GB_Fort_Moultrie.tga";

			LAi_QuestDelay("Fort_M_turn_to_ri8", 1.0);
		break;

		case "sergeant_leaves":
			PlaySound("INTERFACE\paper_small.wav");
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolsextant2");
			TakeItemFromCharacter(Pchar, "pistoltinderbox");
			TakeItemFromCharacter(Pchar, "clock1");
			GiveItem2Character(Pchar, "key32");
			GiveItem2Character(Pchar, "sergeants_note");
			if(IsEquipCharacterByItem(Pchar, "bladespade")) EquipCharacterbyItem(Pchar, "bladespade");

			AddQuestRecord("Weapons","6");
			AddQuestRecord("Useful_items","16");

			pchar.quest.sergeant_leaves1.win_condition.l1 = "location";
			pchar.quest.sergeant_leaves1.win_condition.l1.location = "Fort_Moultrie_gunpowder";
			pchar.quest.sergeant_leaves1.win_condition = "sergeant_leaves1";

		/*
			pchar.quest.Fort_corporal.win_condition.l1 = "locator";
			pchar.quest.Fort_corporal.win_condition.l1.location = "Fort_Moultrie_armory";
			pchar.quest.Fort_corporal.win_condition.l1.locator_group = "goto";
			pchar.quest.Fort_corporal.win_condition.l1.locator = "goto1";
			pchar.quest.Fort_corporal.win_condition = "Fort_corporal";
		*/
		break;

		case "sergeant_leaves1":
			locations[FindLocation("Fort_Moultrie_armory")].id.label = "Fort Moultrie armory";

			pchar.quest.Fort_corporal.win_condition.l1 = "locator";
			pchar.quest.Fort_corporal.win_condition.l1.location = "Fort_Moultrie_armory";
			pchar.quest.Fort_corporal.win_condition.l1.locator_group = "goto";
			pchar.quest.Fort_corporal.win_condition.l1.locator = "goto1";
			pchar.quest.Fort_corporal.win_condition = "Fort_corporal";
		break;

		case "reset_cells":
			PlaySound("INTERFACE\step_reset.wav");
			Pchar.locked_cells = "0";
			Pchar.cell2 = "open"; Pchar.cell6 = "open"; Pchar.cell7 = "open"; 
			Pchar.cell5 = "open"; Pchar.cell4 = "open"; Pchar.cell3 = "open";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload14", 0.001);
			Locations[FindLocation("Fort_Moultrie_prison")].locators_radius.reload.reload14 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "stop", 0.7);
			Locations[FindLocation("Fort_Moultrie_prison")].locators_radius.goto.stop = 0.7;

			LAi_QuestDelay("reset_cells1", 2.0);
		break;

		case "reset_cells1":
			int wrong_cell = rand(4);
			switch (wrong_cell)
			{
				case 0:
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				break;

				case 1:
					PlaySound("OBJECTS\VOICES\DEAD\male\dead5.wav");
				break;

				case 2:
					PlaySound("OBJECTS\DUEL\man_attack5.wav");
				break;

				case 3:
					PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
				break;

				case 4:
					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
				break;
			}
		break;

		case "open_prison_stairs":
			PlaySound("INTERFACE\shelf_cogs.wav");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload14", 0.7);
			Locations[FindLocation("Fort_Moultrie_prison")].locators_radius.reload.reload14 = 0.7;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "stop", 0.001);
			Locations[FindLocation("Fort_Moultrie_prison")].locators_radius.goto.stop = 0.001;

			LAi_QuestDelay("open_prison_stairs1", 1.0);
		break;

		case "open_prison_stairs1":
			PlaySound("INTERFACE\step_open.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "stop");
			
			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("pchar_yah", 2.0);
		break;

		case "Fort_corporal":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "note_to_corporal":
			PlaySound("INTERFACE\paper_small.wav");
			TakeItemFromCharacter(Pchar, "sergeants_note");
			TakeItemFromCharacter(Pchar, "key32");

			LAi_QuestDelay("who are you3", 2.0);
		break;

		case "who are you3":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you3";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "corporal_revolver":
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToLocator(characterFromID("Moultrie_corporal"), "goto", "look_revolver");

			LAi_QuestDelay("corporal_revolver1", 1.0);
		break;

		case "corporal_revolver1":
			PlaySound("OBJECTS\DUEL\reload1.wav");

			LAi_QuestDelay("corporal_revolver3", 1.0);
		break;

		case "corporal_revolver3":
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);

			LAi_QuestDelay("who are you4", 1.0);
		break;

		case "who are you4":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you4";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "Legrand_revolver":
			EquipCharacterbyItem(Pchar, "bladespade");
			GiveItem2Character(Pchar, "revolver");
			EquipCharacterByItem(Pchar, "revolver");
			PlaySound("OBJECTS\DUEL\reload2.wav");
			AddQuestRecord("Weapons","7");

			LAi_QuestDelay("who are you5", 1.0);
		break;

		case "who are you5":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you5";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "corporal_ammo":
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorGoToLocator(characterFromID("Moultrie_corporal"), "goto", "ammo", "corporal_ammo1", 3.0);
		break;

		case "corporal_ammo1":
			PlaySound("PEOPLE\counter_open.wav");

			LAi_QuestDelay("corporal_ammo2", 2.0);
		break;

		case "corporal_ammo2":
			PlaySound("INTERFACE\button3.wav");
			PlaySound("INTERFACE\button1.wav");

			LAi_QuestDelay("corporal_ammo3", 1.0);
		break;

		case "corporal_ammo3":
			PlaySound("PEOPLE\counter_close.wav");
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorGoToLocator(characterFromID("Moultrie_corporal"), "goto", "goto1", "who are you6", 3.0);
		break;

		case "who are you6":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you6";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "Legrand_ammo":
			TakenItems(Pchar, "cartridges", 12);
			PlaySound("OBJECTS\DUEL\reload2.wav");
			AddQuestRecord("Weapons","8");
			CloseQuestHeader("Weapons");

			LAi_QuestDelay("who are you7", 1.0);
		break;

		case "who are you7":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you7";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "corporal_rope":
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorGoToLocator(characterFromID("Moultrie_corporal"), "box", "box7", "corporal_rope1", 4.0);
		break;

		case "corporal_rope1":
			PlaySound("PEOPLE\creak2.wav");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_corporal"), "Fort_Moultrie_armory", "box", "box8");

			LAi_QuestDelay("corporal_rope2", 1.0);
		break;

		case "corporal_rope2":
			PlaySound("PEOPLE\clothes1.wav");

			LAi_QuestDelay("corporal_rope3", 1.0);
		break;

		case "corporal_rope3":
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_corporal"), "Fort_Moultrie_armory", "box", "box7");

			LAi_QuestDelay("corporal_rope4", 1.0);
		break;

		case "corporal_rope4":
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorGoToLocator(characterFromID("Moultrie_corporal"), "goto", "goto1", "who are you8", 4.0);
		break;
			
		case "who are you8":
			Characters[GetCharacterIndex("Moultrie_corporal")].dialog.CurrentNode  = "who are you8";
			LAi_SetActorType(characterFromID("Moultrie_corporal"));
			LAi_ActorTurnToCharacter(characterFromID("Moultrie_corporal"), PChar);
			LAi_ActorDialogNow(characterFromID("Moultrie_corporal"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Moultrie_corporal"));
		break;

		case "Legrand_rope":
			PlaySound("PEOPLE\clothes1.wav");
			SetModel(Pchar, "William Legrand2", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			GiveItem2Character(Pchar, "fort_rope");
			AddQuestRecord("Useful_items","17");
			CloseQuestHeader("Useful_items");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("corporal_jumps", 2.0);
		break;

		case "corporal_jumps":
			PlaySound("AMBIENT\SEASHORE\fanfare2.wav");
			
			LAi_QuestDelay("corporal_jumps0", 2.5);
		break;

		case "corporal_jumps0":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			
			LAi_QuestDelay("corporal_jumps1", 1.0);
		break;

		case "corporal_jumps1":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			
			LAi_QuestDelay("corporal_jumps2", 0.5);
		break;

		case "corporal_jumps2":
			PlaySound("PEOPLE\Jump_counter.wav");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_corporal"), "Fort_Moultrie_armory", "goto", "goto15");

			LAi_QuestDelay("corporal_jumps4", 0.5);
		break;

		case "corporal_jumps4":
			ChangeCharacterAddressGroup(characterFromID("Moultrie_corporal"), "Fort_Moultrie_armory", "officers", "reload1_2");
			
			LAi_QuestDelay("corporal_jumps5", 0.5);
		break;

		case "corporal_jumps5":
			ChangeCharacterAddressGroup(characterFromID("Moultrie_sergeant"), "Fort_Moultrie", "goto", "sergeant");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_corporal"), "Fort_Moultrie", "goto", "corporal");
			LAi_SetStayType(characterFromID("Moultrie_corporal"));
			
			LAi_QuestDelay("corporal_jumps6", 0.5);
		break;

		case "corporal_jumps6":
			PlaySound("INTERFACE\closed_door.wav");
			Locations[FindLocation("Fort_Moultrie_gunpowder")].reload.l3.disable = 1;
			Locations[FindLocation("Fort_Moultrie_prison_stairs")].reload.l4.disable = 1;

			LAi_QuestDelay("corporal_jumps7", 1.0);
			LAi_QuestDelay("pchar_huh", 1.0);
		break;

		case "corporal_jumps7":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");

			LAi_QuestDelay("corporal_jumps8", 1.0);
		break;

		case "corporal_jumps8":
			LAi_SetPlayerType(Pchar);
			
			pchar.quest.end_fort3.win_condition.l1 = "locator";
			pchar.quest.end_fort3.win_condition.l1.location = "Fort_Moultrie";
			pchar.quest.end_fort3.win_condition.l1.locator_group = "reload";
			pchar.quest.end_fort3.win_condition.l1.locator = "reload1";
			pchar.quest.end_fort3.win_condition = "end_fort3";
		break;

		case "end_fort3":
			DoQuestReloadToLocation("Bessop_plantation", "officers", "reload1_2", "end_fort3_1");	
		break;

		case "end_fort3_1":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Legrand_first_to_plantation";
			LAi_ActorSelfDialog(pchar, "");
		break;
//JRH check all 3 potions here
		case "Legrand_first_to_plantation_done":
			//switch to Poe church mission here

			SetModel(Pchar, "Edgar Allan Poe", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			DoQuestReloadToLocation("Poe_bedroom", "goto", "goto1", "pchar_playertype");
					
			LAi_QuestDelay("Poe_church_mission", 0.1);
		break;
//-----------------------------------------------------------------------------------------------------------------------------------
		case "Poe_church_mission":
			//jump start "15" from here

			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_Moultrie_barracks", "sit", "sit13");
			LAi_SetSitType(characterFromID("Lieutenant G"));

			Pchar.name = "Edgar Allan";
			Pchar.lastname = "Poe";
			Pchar.rank 	= 2;
			Pchar.reputation = "50";
			Pchar.experience = "0";
			Pchar.skill.Leadership = "5";
			Pchar.skill.Fencing = "1";
			Pchar.skill.Sailing = "1";
			Pchar.skill.Accuracy = "1";
			Pchar.skill.Cannons = "1";
			Pchar.skill.Grappling = "1";
			Pchar.skill.Repair = "1";
			Pchar.skill.Defence = "1";
			Pchar.skill.Commerce = "3";
			Pchar.skill.Sneak = "1";

			Pchar.perks.list.Gunman = true;

			if(CheckCharacterItem(Pchar,"potionrum")) Pchar.quest.Legrands_rum = "yes";	
			if(CheckCharacterItem(Pchar,"potion3")) Pchar.quest.Legrands_antidote = "yes";	
			if(CheckCharacterItem(Pchar,"medical2")) Pchar.quest.Legrands_cauterization = "yes";

			DeleteAttribute(Pchar, "items");
			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "revolver");
			
			DeleteQuestHeader("Weapons");
			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("Bishop's_Hostel");

			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","12");
		
			Locations[FindLocation("Poe_entre")].reload.l3.disable = 0;			//landlady private
			Pchar.quest.town_exit_closed = "yes";
			SetLocatorRadius(locations[FindLocation("GB_Charleston_port")], "box", "box7", 0.0001);
			Locations[FindLocation("GB_Charleston_port")].locators_radius.box.box7 = 0.0001;
			Characters[GetCharacterIndex("Moultrie_guard2")].Ship.Type = "obj_invisible";	//Charleston port
			Pchar.church_entre = "yes";

			pchar.quest.town_exit_closed1.win_condition.l1 = "locator";
			pchar.quest.town_exit_closed1.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.town_exit_closed1.win_condition.l1.locator_group = "reload";
			pchar.quest.town_exit_closed1.win_condition.l1.locator = "reload2";
			pchar.quest.town_exit_closed1.win_condition = "town_exit_closed1";

			LAi_QuestDelay("Poe_pistol", 1.0);
		break;

		case "Poe_pistol":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Poe_pistol";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Poe_pistol_done":
			LAi_QuestDelay("Poe_tools", 1.0);
		break;

		case "Poe_tools":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Poe_tools";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Poe_tools_done":
			LAi_SetPlayerType(pchar);
			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items","18");
			SetQuestHeader("Weapons");
			AddQuestRecord("Weapons","9");
		SetCurrentTime(12.00, 0);
		SetNextWeather("Clear");

			pchar.quest.church_entre.win_condition.l1 = "locator";
			pchar.quest.church_entre.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.church_entre.win_condition.l1.locator_group = "goto";
			pchar.quest.church_entre.win_condition.l1.locator = "priest";
			pchar.quest.church_entre.win_condition = "church_entre";
		break;

		case "church_entre":
			Characters[GetCharacterIndex("Claude Frollo")].dialog.CurrentNode  = "church_entre";
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorTurnToCharacter(characterFromID("Claude Frollo"), PChar);
			LAi_ActorDialogNow(characterFromID("Claude Frollo"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Claude Frollo"));
		break;

		case "church_entre_done":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorRunToLocator(characterFromID("Claude Frollo"), "reload", "reload22", "church_entre_done1", 10.0);

			LAi_QuestDelay("pchar_playertype", 3.0);
			LAi_QuestDelay("Poe_go_on", 3.0);
		break;

		case "church_entre_done1":
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo"), "GB_Charleston_church_office", "goto", "goto5");

			pchar.quest.hymn_book.win_condition.l1 = "locator";
			pchar.quest.hymn_book.win_condition.l1.location = "GB_Charleston_church_office";
			pchar.quest.hymn_book.win_condition.l1.locator_group = "goto";
			pchar.quest.hymn_book.win_condition.l1.locator = "goto5";
			pchar.quest.hymn_book.win_condition = "hymn_book";
		break;

		case "hymn_book":
			Characters[GetCharacterIndex("Claude Frollo")].dialog.CurrentNode  = "hymn_book";
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorTurnToCharacter(characterFromID("Claude Frollo"), PChar);
			LAi_ActorDialogNow(characterFromID("Claude Frollo"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Claude Frollo"));
		break;

		case "hymn_book_done":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorGoToLocator(characterFromID("Claude Frollo"), "box", "box1", "hymn_book_done1", 4.0);
		break;

		case "hymn_book_done1":
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo"), "GB_Charleston_church_office", "box", "box1");

			LAi_QuestDelay("hymn_book_done2", 1.0);
		break;

		case "hymn_book_done2":
			PlaySound("INTERFACE\key_unlock.wav");

			LAi_QuestDelay("hymn_book_done3", 2.0);
		break;

		case "hymn_book_done3":
			PlaySound("INTERFACE\glass1.wav");

			LAi_QuestDelay("hymn_book_done4", 2.0);
		break;

		case "hymn_book_done4":
			PlaySound("INTERFACE\closed_door.wav");

			LAi_QuestDelay("hymn_book_done5", 1.0);
		break;

		case "hymn_book_done5":
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorGoToLocator(characterFromID("Claude Frollo"), "goto", "goto5", "hymn_book_done6", 4.0);
		break;

		case "hymn_book_done6":
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo"), "GB_Charleston_church_office", "goto", "goto5");

			LAi_QuestDelay("holy_water", 0.1);
		break;

		case "holy_water":
			Characters[GetCharacterIndex("Claude Frollo")].dialog.CurrentNode  = "holy_water";
			LAi_SetActorType(characterFromID("Claude Frollo"));
			LAi_ActorTurnToCharacter(characterFromID("Claude Frollo"), PChar);
			LAi_ActorDialogNow(characterFromID("Claude Frollo"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Claude Frollo"));
		break;

		case "holy_water_done":
			LAi_SetStayType(characterFromID("Claude Frollo"));
			Characters[GetCharacterIndex("Claude Frollo")].dialog.CurrentNode  = "neutral";
			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			LAi_SetPlayerType(pchar);
		
			Pchar.sacristy.box1 = "open";

			AddQuestRecord("Useful_items","19");
			AddQuestRecord("Useful_items","20");
			SetQuestHeader("Claude_Frollo's_mission");
			AddQuestRecord("Claude_Frollo's_mission","1");
			AddQuestRecord("Claude_Frollo's_mission","2");

			ChangeCharacterAddressGroup(characterFromID("Medicine Woman"), "GB_Charleston_town", "goto", "box53");
			ChangeCharacterAddressGroup(characterFromID("merchant1"), "none", "", "");	//so he doesn't distract medicin woman

			pchar.quest.medwom_calabash.win_condition.l1 = "locator";
			pchar.quest.medwom_calabash.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.medwom_calabash.win_condition.l1.locator_group = "goto";
			pchar.quest.medwom_calabash.win_condition.l1.locator = "box53";
			pchar.quest.medwom_calabash.win_condition = "medwom_calabash";
		break;

		case "medwom_calabash":
			Characters[GetCharacterIndex("Medicine Woman")].dialog.CurrentNode  = "calabash";
			LAi_SetActorType(characterFromID("Medicine Woman"));
			LAi_ActorTurnToCharacter(characterFromID("Medicine Woman"), PChar);
			LAi_ActorDialogNow(characterFromID("Medicine Woman"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Medicine Woman"));
		break;

		case "medwom_calabash_done":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "merchant6");

			LAi_QuestDelay("medwom_calabash_done1", 1.0);
		break;

		case "medwom_calabash_done1":
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			ChangeCharacterAddressGroup(characterFromID("Medicine Woman"), "none", "", "");
			
			LAi_QuestDelay("medwom_calabash_done2", 1.0);
		break;

		case "medwom_calabash_done2":
			CreateParticleSystemX("blast_dirt", -17.2, 4.9, -24.4, -17.2, 4.9, -24.4, 10);
			LAi_ActorTurnToLocator(Pchar, "box", "box53");

			LAi_QuestDelay("medwom_calabash_done3", 1.0);
		break;

		case "medwom_calabash_done3":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			LAi_SetPlayerType(Pchar);
			SetLocatorRadius(locations[FindLocation("GB_Charleston_town")], "box", "box53", 1.0);		
			Locations[FindLocation("GB_Charleston_town")].locators_radius.box.box53 = 1.0;

			pchar.quest.crypt_sound.win_condition.l1 = "locator";
			pchar.quest.crypt_sound.win_condition.l1.location = "GB_Charleston_wine_cellar";
			pchar.quest.crypt_sound.win_condition.l1.locator_group = "goto";
			pchar.quest.crypt_sound.win_condition.l1.locator = "crypt_sound";
			pchar.quest.crypt_sound.win_condition = "crypt_sound";
		break;

	//-------------------------------------------------------------------------------------------------------------------------
	//ZOMBIE TUNNELS
		case "crypt_sound":
			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "crypt";
			PostEvent("LoadSceneSound", 0);	

			LAi_QuestDelay("see_ladder", 0.1);			
			LAi_QuestDelay("zombieA", 0.1);	
		break;

		case "see_ladder":
			pchar.quest.see_ladder1.win_condition.l1 = "locator";
			pchar.quest.see_ladder1.win_condition.l1.location = "GB_Charleston_wine_cellar";
			pchar.quest.see_ladder1.win_condition.l1.locator_group = "goto";
			pchar.quest.see_ladder1.win_condition.l1.locator = "see_ladder";
			pchar.quest.see_ladder1.win_condition = "see_ladder1";
		break;

		case "see_ladder1":
			LAi_QuestDelay("Poe_look", 0.1);	
			Logit(TranslateString("","Hope that Ladder leads to the Church."));
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_wine_cellar", "goto", "see_ladder");
			LAi_SetStayType(pchar);

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "zombieA":
			pchar.quest.zombieA_1.win_condition.l1 = "locator";
			pchar.quest.zombieA_1.win_condition.l1.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieA_1.win_condition.l1.locator_group = "goto";
			pchar.quest.zombieA_1.win_condition.l1.locator = "alertA";
			pchar.quest.zombieA_1.win_condition = "zombieA_1";

			pchar.quest.zombieB_1.win_condition.l2 = "locator";
			pchar.quest.zombieB_1.win_condition.l2.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieB_1.win_condition.l2.locator_group = "goto";
			pchar.quest.zombieB_1.win_condition.l2.locator = "alertB";
			pchar.quest.zombieB_1.win_condition = "zombieB_1";

			pchar.quest.zombieC_1.win_condition.l3 = "locator";
			pchar.quest.zombieC_1.win_condition.l3.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieC_1.win_condition.l3.locator_group = "goto";
			pchar.quest.zombieC_1.win_condition.l3.locator = "alertC";
			pchar.quest.zombieC_1.win_condition = "zombieC_1";

			pchar.quest.zombieD_1.win_condition.l4 = "locator";
			pchar.quest.zombieD_1.win_condition.l4.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieD_1.win_condition.l4.locator_group = "goto";
			pchar.quest.zombieD_1.win_condition.l4.locator = "alertD";
			pchar.quest.zombieD_1.win_condition = "zombieD_1";
		
			pchar.quest.zombieE_1.win_condition.l5 = "locator";
			pchar.quest.zombieE_1.win_condition.l5.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieE_1.win_condition.l5.locator_group = "goto";
			pchar.quest.zombieE_1.win_condition.l5.locator = "alertE";
			pchar.quest.zombieE_1.win_condition = "zombieE_1";
		/*
			pchar.quest.zombieF_1.win_condition.l6 = "locator";
			pchar.quest.zombieF_1.win_condition.l6.location = "GB_Charleston_wine_cellar";
			pchar.quest.zombieF_1.win_condition.l6.locator_group = "goto";
			pchar.quest.zombieF_1.win_condition.l6.locator = "alertF";
			pchar.quest.zombieF_1.win_condition = "zombieF_1";
		*/	
		break;

		case "zombieA_1":
			if(!CheckAttribute(Pchar,"zombie3.attacks") || Pchar.zombie3.attacks != "yes")	
			{
				Pchar.zombie3.attacks = "yes";
				PlaySound("VOICE\ENGLISH\zombie3.wav");
				LAi_SetActorType(characterFromID("zombie3"));
				LAi_ActorTurnToCharacter(characterFromID("zombie3"), PChar);

				LAi_QuestDelay("zombieA_2", 1.0);
			}		
		break;

		case "zombieA_2":
			LAi_ActorAttack(CharacterFromID("zombie3"), Pchar, "");
			LAi_SetPlayerType(pchar);
		break;

		case "zombieB_1":
			if(!CheckAttribute(Pchar,"zombie5.attacks") || Pchar.zombie5.attacks != "yes")	
			{
				Pchar.zombie5.attacks = "yes";
				PlaySound("VOICE\ENGLISH\zombie5.wav");
				LAi_SetActorType(characterFromID("zombie5"));
				LAi_ActorAttack(CharacterFromID("zombie5"), Pchar, "");	
			}
		break;

		case "zombieC_1":
			if(!CheckAttribute(Pchar,"zombie6.attacks") || Pchar.zombie6.attacks != "yes")	
			{
				Pchar.zombie6.attacks = "yes";
				PlaySound("VOICE\ENGLISH\zombie6.wav");
				LAi_SetActorType(characterFromID("zombie6"));
				LAi_ActorAttack(CharacterFromID("zombie6"), Pchar, "");	
			}

			if(!CheckAttribute(Pchar,"zombie5.attacks") || Pchar.zombie5.attacks != "yes")	
			{
				LAi_QuestDelay("zombieC_2", 2.0);	
			}	
		break;

		case "zombieC_2":
			if(!CheckAttribute(Pchar,"zombie5.attacks") || Pchar.zombie5.attacks != "yes")	 
			{
				Pchar.zombie5.attacks = "yes";
				PlaySound("VOICE\ENGLISH\zombie5.wav");
				LAi_SetActorType(characterFromID("zombie5"));
				LAi_ActorAttack(CharacterFromID("zombie5"), Pchar, "");	
			}
		break;

		case "zombieD_1":
			ChangeCharacterAddressGroup(characterFromID("zombie2"), "GB_Charleston_wine_cellar", "goto", "zombieD");
			LAi_SetActorType(characterFromID("zombie2"));
			LAi_ActorAnimation(characterFromID("zombie2"), "Jump", "zombieD_2", 1.5);

			LAi_QuestDelay("zombieD_3", 0.75);	
		break;
		
		case "zombieD_2":
			Pchar.zombie2.attacks = "yes";
			LAi_SetPlayerType(pchar);
			PlaySound("VOICE\ENGLISH\zombie2.wav");
			LAi_ActorAttack(CharacterFromID("zombie2"), Pchar, "");	
		break;

		case "zombieD_3":
			PlaySound("PEOPLE\jump.wav");
		break;
	
		case "zombieE_1":
			ChangeCharacterAddressGroup(characterFromID("zombie1"), "GB_Charleston_wine_cellar", "goto", "zombieE");
			LAi_SetActorType(characterFromID("zombie1"));
			LAi_ActorAnimation(characterFromID("zombie1"), "Jump", "zombieE_2", 1.5);

			LAi_QuestDelay("zombieD_3", 0.75);
			LAi_QuestDelay("zombieE_3", 1.5);
	LAi_QuestDelay("zombieF_1", 3.0);

			pchar.quest.Chton_church.win_condition.l1 = "location";
			pchar.quest.Chton_church.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.Chton_church.win_condition = "Chton_church";
		break;

		case "zombieE_2":
			Pchar.zombie1.attacks = "yes";
			LAi_SetPlayerType(pchar);
			PlaySound("VOICE\ENGLISH\black_witch_laugh.wav");
			LAi_ActorAttack(CharacterFromID("zombie1"), Pchar, "");	
		break;

		case "zombieE_3":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "zombieF_1":
			if(!CheckAttribute(Pchar,"zombie4.attacks") || Pchar.zombie4.attacks != "yes")	 
			{
				Pchar.zombie4.attacks = "yes";
				ChangeCharacterAddressGroup(characterFromID("zombie4"), "GB_Charleston_wine_cellar", "goto", "zombieF");
				PlaySound("VOICE\ENGLISH\zombie2.wav");
				LAi_SetActorType(characterFromID("zombie4"));
				LAi_ActorAttack(CharacterFromID("zombie4"), Pchar, "");	
			}
		break;

		case "Chton_church":
			PlaySound("PEOPLE\counter_close.wav");
			Locations[FindLocation("GB_Charleston_church")].reload.l2.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Claude Frollo2"), "none", "", "");
			if(IsEquipCharacterByItem(Pchar, "holy_water")) RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeNItems(Pchar,"holy_water", -12);
			Pchar.been_to_church = "yes";

			LAi_QuestDelay("pchar_puh", 1.5);
			LAi_QuestDelay("knitting_basket_pick_up", 0.1);	
		/*
			pchar.quest.step_back_church2_A.win_condition.l1 = "locator";
			pchar.quest.step_back_church2_A.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.step_back_church2_A.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_church2_A.win_condition.l1.locator = "plank2A";
			pchar.quest.step_back_church2_A.win_condition = "step_back_church2_A";
		
			pchar.quest.step_back_church3_A.win_condition.l1 = "locator";
			pchar.quest.step_back_church3_A.win_condition.l1.location = "GB_Charleston_church";
			pchar.quest.step_back_church3_A.win_condition.l1.locator_group = "goto";
			pchar.quest.step_back_church3_A.win_condition.l1.locator = "plank3A";
			pchar.quest.step_back_church3_A.win_condition = "step_back_church3_A";
		*/
		break;
	//----------------------------------------------------------------------------
		case "zombie1_voice":
			PlaySound("VOICE\ENGLISH\black_witch_laugh.wav");
		break;

		case "zombie1_hurt":
			PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
		break;

		case "zombie_f_dead":
			PlaySound("VOICE\ENGLISH\black_witch_disappear.wav");
		break;
		
		case "zombie2_voice":
			PlaySound("VOICE\ENGLISH\zombie2.wav");
		break;

		case "zombie3_voice":
			PlaySound("VOICE\ENGLISH\zombie3.wav");
		break;

		case "zombie4_voice":
			PlaySound("VOICE\ENGLISH\zombie4.wav");
		break;

		case "zombie5_voice":
			PlaySound("VOICE\ENGLISH\zombie5.wav");
		break;

		case "zombie6_voice":
			PlaySound("VOICE\ENGLISH\zombie6.wav");
		break;
		
		case "zombie_m_dead":
			PlaySound("VOICE\ENGLISH\zombie_die.wav");
		break;

		case "holy_water_on_zombie":
			if(CheckAttribute(Pchar,"quest.zombie"))
			{
			    	switch(Pchar.quest.zombie)
			    	{
					case "1":
						if(Characters[GetCharacterIndex("zombie1")].model == "Skel_zombie1")
						{
							if(CheckAttribute(Pchar,"zombie1.temp.safe") && Pchar.zombie1.temp.safe == "yes")	
							{
								//Logit("1 SAFE");
								return;
							}
							else
							{
								//Logit("1 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie1"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie1"));

								LAi_QuestDelay("zombie_f_dead", 1.0);
								LAi_QuestDelay("zombie1_dead", 3.0);
							}
						}
						else
						{
							//Logit("1 ZOMBIE");
							Pchar.zombie1.attacks = "yes";
							Pchar.zombie1.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie1"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie1"), "Skel_zombie1", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie1"));
							LAi_ActorAnimation(characterFromID("zombie1"), "death_1", "zombie1_not_dead", 4.0);	

							LAi_QuestDelay("zombie1_hurt", 1.0);
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}
					break;

					case "2":
						if(Characters[GetCharacterIndex("zombie2")].model == "Skel_zombie2")
						{
							if(CheckAttribute(Pchar,"zombie2.temp.safe") && Pchar.zombie2.temp.safe == "yes")	
							{
								//Logit("2 SAFE");
								return;
							}
							else
							{
								//Logit("2 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie2"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie2"));

								LAi_QuestDelay("zombie_m_dead", 1.0);
								LAi_QuestDelay("zombie2_dead", 3.0);
							}
						}
						else
						{
							//Logit("2 ZOMBIE");
							Pchar.zombie2.attacks = "yes";
							Pchar.zombie2.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie2"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie2"), "Skel_zombie2", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie2"));
							LAi_ActorAnimation(characterFromID("zombie2"), "death_1", "zombie2_not_dead", 4.0);	

							LAi_QuestDelay("zombie3_voice", 1.0);		//3 yes!
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}
					break;

					case "3":
						if(Characters[GetCharacterIndex("zombie3")].model == "Skel_zombie3")
						{
							if(CheckAttribute(Pchar,"zombie3.temp.safe") && Pchar.zombie3.temp.safe == "yes")	
							{
								//Logit("3 SAFE");
								return;
							}
							else
							{
								//Logit("3 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie3"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie3"));

								LAi_QuestDelay("zombie_m_dead", 1.0);
								LAi_QuestDelay("zombie3_dead", 3.0);
							}
						}
						else
						{
							//Logit("3 ZOMBIE");
							Pchar.zombie3.attacks = "yes";
							Pchar.zombie3.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie3"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie3"), "Skel_zombie3", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie3"));
							LAi_ActorAnimation(characterFromID("zombie3"), "death_1", "zombie3_not_dead", 4.0);	

							LAi_QuestDelay("zombie3_voice", 1.0);
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}
					break;
				
					case "4":
						if(Characters[GetCharacterIndex("zombie4")].model == "Skel_zombie4")
						{
							if(CheckAttribute(Pchar,"zombie4.temp.safe") && Pchar.zombie4.temp.safe == "yes")	
							{
								//Logit("4 SAFE");
								return;
							}
							else
							{
								//Logit("4 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie4"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie4"));

								LAi_QuestDelay("zombie_m_dead", 1.0);
								LAi_QuestDelay("zombie4_dead", 3.0);
							}
						}
						else
						{
							//Logit("4 ZOMBIE");
							Pchar.zombie4.attacks = "yes";
							Pchar.zombie4.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie4"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie4"), "Skel_zombie4", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie4"));
							LAi_ActorAnimation(characterFromID("zombie4"), "death_1", "zombie4_not_dead", 4.0);	

							LAi_QuestDelay("zombie4_voice", 1.0);
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}
					break;
				
					case "5":
						if(Characters[GetCharacterIndex("zombie5")].model == "Skel_zombie5")
						{
							if(CheckAttribute(Pchar,"zombie5.temp.safe") && Pchar.zombie5.temp.safe == "yes")	
							{
								//Logit("5 SAFE");
								return;
							}
							else
							{
								//Logit("5 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie5"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie5"));

								LAi_QuestDelay("zombie_m_dead", 1.0);
								LAi_QuestDelay("zombie5_dead", 3.0);
							}
						}
						else
						{
							//Logit("5 ZOMBIE");
							Pchar.zombie5.attacks = "yes";
							Pchar.zombie5.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie5"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie5"), "Skel_zombie5", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie5"));
							LAi_ActorAnimation(characterFromID("zombie5"), "death_1", "zombie5_not_dead", 4.0);	

							LAi_QuestDelay("zombie5_voice", 1.0);
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}
					break;

					case "6":
						if(Characters[GetCharacterIndex("zombie6")].model == "Skel_zombie6")
						{
							if(CheckAttribute(Pchar,"zombie6.temp.safe") && Pchar.zombie6.temp.safe == "yes")	
							{
								//Logit("6 SAFE");
								return;
							}
							else
							{
								//Logit("6 SKELETON");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("INTERFACE\fire_on.wav");
								PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
								GetCharacterPos(characterFromID("zombie6"), &x, &y, &z);
								CreateParticleSystem("fort_fire" , x, y+0.5, z, 5.1, 4.0, 0.0, sti(20) );
								LAi_SetStayType(characterFromID("zombie6"));

								LAi_QuestDelay("zombie_m_dead", 1.0);
								LAi_QuestDelay("zombie6_dead", 3.0);
							}
						}
						else
						{
							//Logit("6 ZOMBIE");
							Pchar.zombie6.attacks = "yes";
							Pchar.zombie6.temp.safe = "yes";
							PlaySound("INTERFACE\fire_off.wav");
							GetCharacterPos(characterFromID("zombie6"), &x, &y, &z);
							CreateParticleSystem("KNBcancloud" , x, y+1, z, 5.1, 4.0, 0.0, sti(20) );
							SetModel(characterFromID("zombie6"), "Skel_zombie6", "man", "skeleton", 1.8, true);
							LAi_SetActorType(characterFromID("zombie6"));
							LAi_ActorAnimation(characterFromID("zombie6"), "death_1", "zombie6_not_dead", 4.0);	

							LAi_QuestDelay("zombie6_voice", 1.0);
							LAi_QuestDelay("zombie_bone_sound", 2.0);
						}

						LAi_QuestDelay("zombie6_voice", 1.0);
					break;
			    	}
			}

			
		break;
			
		case "zombie_bone_sound":
			PlaySound("OBJECTS\VOICES\skeleton_body1.wav");
		break;

	//---------------------------------------------------------------------
		case "zombie1_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie1"));

			LAi_QuestDelay("zombie1_not_dead1", 2.0);
		break;

		case "zombie1_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie1"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie1"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie1"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie1"), "bladebone");

			LAi_ActorAnimation(characterFromID("zombie1"), "Ground_StandUp", "zombie1_not_dead2", 4.0);
		break;

		case "zombie1_not_dead2":
			Pchar.zombie1.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\black_witch_laugh.wav");
			LAi_ActorAttack(CharacterFromID("zombie1"), Pchar, "");
		break;
		
		case "zombie1_dead":
			SetModel(characterFromID("zombie1"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie1"));
		break;
	//---------------------------------------------------------------------
		case "zombie2_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie2"));

			LAi_QuestDelay("zombie2_not_dead1", 2.0);
		break;

		case "zombie2_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie2"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie2"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie2"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie2"), "bladebone");		
	
			LAi_ActorAnimation(characterFromID("zombie2"), "Ground_StandUp", "zombie2_not_dead2", 4.0);
		break;

		case "zombie2_not_dead2":
			Pchar.zombie2.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\zombie2.wav");
			LAi_ActorAttack(CharacterFromID("zombie2"), Pchar, "");
		break;
		
		case "zombie2_dead":
			SetModel(characterFromID("zombie2"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie2"));
		break;
	//---------------------------------------------------------------------
		case "zombie3_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie3"));

			LAi_QuestDelay("zombie3_not_dead1", 2.0);
		break;

		case "zombie3_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie3"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie3"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie3"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie3"), "bladebone");

			LAi_ActorAnimation(characterFromID("zombie3"), "Ground_StandUp", "zombie3_not_dead2", 4.0);
		break;

		case "zombie3_not_dead2":
			Pchar.zombie3.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\zombie3.wav");
			LAi_ActorAttack(CharacterFromID("zombie3"), Pchar, "");
		break;
		
		case "zombie3_dead":
			SetModel(characterFromID("zombie3"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie3"));
		break;
	//---------------------------------------------------------------------
		case "zombie4_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie4"));

			LAi_QuestDelay("zombie4_not_dead1", 2.0);
		break;

		case "zombie4_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie4"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie4"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie4"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie4"), "bladebone");

			LAi_ActorAnimation(characterFromID("zombie4"), "Ground_StandUp", "zombie4_not_dead2", 4.0);
		break;

		case "zombie4_not_dead2":
			Pchar.zombie4.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\zombie4.wav");
			LAi_ActorAttack(CharacterFromID("zombie4"), Pchar, "");
		break;
		
		case "zombie4_dead":
			SetModel(characterFromID("zombie4"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie4"));
		break;
	//---------------------------------------------------------------------
		case "zombie5_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie5"));

			LAi_QuestDelay("zombie5_not_dead1", 2.0);
		break;

		case "zombie5_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie5"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie5"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie5"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie5"), "bladebone");
			
			LAi_ActorAnimation(characterFromID("zombie5"), "Ground_StandUp", "zombie5_not_dead2", 4.0);
		break;

		case "zombie5_not_dead2":
			Pchar.zombie5.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\zombie5.wav");
			LAi_ActorAttack(CharacterFromID("zombie5"), Pchar, "");
		break;
		
		case "zombie5_dead":
			SetModel(characterFromID("zombie5"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie5"));
		break;
	//---------------------------------------------------------------------
		case "zombie6_not_dead":
			LAi_ActorSetLayMode(characterFromID("zombie6"));

			LAi_QuestDelay("zombie6_not_dead1", 2.0);
		break;

		case "zombie6_not_dead1":
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");

			RemoveCharacterEquip(characterFromID("zombie6"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("zombie6"), "zombie_touch");
			GiveItem2Character(characterFromID("zombie6"), "bladebone");
			EquipCharacterbyItem(characterFromID("zombie6"), "bladebone");

			LAi_ActorAnimation(characterFromID("zombie6"), "Ground_StandUp", "zombie6_not_dead2", 4.0);
		break;

		case "zombie6_not_dead2":
			Pchar.zombie6.temp.safe = "no";
			PlaySound("VOICE\ENGLISH\zombie6.wav");
			LAi_ActorAttack(CharacterFromID("zombie6"), Pchar, "");
		break;
		
		case "zombie6_dead":
			SetModel(characterFromID("zombie6"), "SkelZ", "man", "skeleton", 1.8, true);
			LAi_KillCharacter(characterFromID("zombie6"));
		break;
	
		case "dont_throw_HW":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, that one is already dead."));
		break;
	//-------------------------------------------------------------------------------------------------------------------------
	//CHURCH PUZZLE

		case "knitting_basket_pick_up":
			if(CheckCharacterItem(Pchar,"knitting_basket"))
			{
				Locations[FindLocation("GB_Charleston_church")].image = "";
				DoQuestReloadToLocation("GB_Charleston_church", "goto", "basket", "");	
			}
			else LAi_QuestDelay("knitting_basket_pick_up", 0.5);//loop check
		break;

		case "reset_church_image":
			Locations[FindLocation("GB_Charleston_church")].image = "GB_Charleston_church.tga";
		break;

		case "return_church_box7":	
			if(CheckCharacterItem(Pchar,"fake_candelabre") || CheckCharacterItem(Pchar,"wax_candles"))
			{
				if(CheckCharacterItem(Pchar,"fake_candelabre")) PlaySound("OBJECTS\DUEL\candelabre.wav");
				if(CheckCharacterItem(Pchar,"wax_candles")) PlaySound("PEOPLE\step_grass.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "fake_candelabre", -2); TakenItems(Pchar, "wax_candles", -4);

				locations[FindLocation(Pchar.location)].box7.items.fake_candelabre = 0;
				locations[FindLocation(Pchar.location)].box7.items.wax_candles = 0;

				locations[FindLocation(Pchar.location)].box7.items.fake_candelabre = 2;
				locations[FindLocation(Pchar.location)].box7.items.wax_candles = 4;
			}
		break;

		case "return_church_box8":	
			if(CheckCharacterItem(Pchar,"fake_chalice"))
			{
				if(CheckCharacterItem(Pchar,"fake_chalice")) PlaySound("OBJECTS\DUEL\chalice.wav");
				
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "fake_chalice", -1);

				locations[FindLocation(Pchar.location)].box8.items.fake_chalice = 0;
				
				locations[FindLocation(Pchar.location)].box8.items.fake_chalice = 1;
			}
		break;

		case "return_church_box9":	
			if(CheckCharacterItem(Pchar,"altar_bread"))
			{
				if(CheckCharacterItem(Pchar,"altar_bread")) PlaySound("INTERFACE\chewing.wav");
				
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "altar_bread", -5);

				locations[FindLocation(Pchar.location)].box9.items.altar_bread = 0;
				
				locations[FindLocation(Pchar.location)].box9.items.altar_bread = 5;
			}
		break;

		case "return_church_box10":	
			if(CheckCharacterItem(Pchar,"fake_censer"))
			{
				if(CheckCharacterItem(Pchar,"fake_censer")) PlaySound("PEOPLE\step_iron.wav");
					
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "fake_censer", -1);

				locations[FindLocation(Pchar.location)].box10.items.fake_censer = 0;

				locations[FindLocation(Pchar.location)].box10.items.fake_censer = 1;
			}
		break;

		case "pickup_hymnbook_check":
			if(CheckCharacterItem(Pchar,"book61A")) 
			{
				AddQuestRecord("Claude_Frollo's_mission","3");
			}
		break;
	
		case "return_church_box13":	
			if(CheckCharacterItem(Pchar,"book_exorcist"))
			{
				if(CheckCharacterItem(Pchar,"book_exorcist")) PlaySound("INTERFACE\book_open.wav");
				
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "book_exorcist", -1);

				locations[FindLocation(Pchar.location)].box13.items.book_exorcist = 0;
				
				locations[FindLocation(Pchar.location)].box13.items.book_exorcist = 1;
			}
		break;

		case "return_church_box14":	
			if(CheckCharacterItem(Pchar,"flyswatter"))
			{
				if(CheckCharacterItem(Pchar,"flyswatter")) PlaySound("INTERFACE\button3.wav");
				
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "flyswatter", -1);

				locations[FindLocation(Pchar.location)].box14.items.flyswatter = 0;
				
				locations[FindLocation(Pchar.location)].box14.items.flyswatter = 1;
			}
		break;

		case "return_church_box15":	
			if(CheckCharacterItem(Pchar,"shrine") || CheckCharacterItem(Pchar,"jewelcross"))
			{
				if(CheckCharacterItem(Pchar,"shrine")) 
				{
					PlaySound("PEOPLE\step_echo.wav");
					PlaySound("PEOPLE\key_box.wav");
				}
				if(CheckCharacterItem(Pchar,"jewelcross")) PlaySound("INTERFACE\took_item.wav");
 
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "shrine", -1); TakenItems(Pchar, "jewelcross", -1);

				locations[FindLocation(Pchar.location)].box15.items.shrine = 0;
				locations[FindLocation(Pchar.location)].box15.items.jewelcross = 0;

				locations[FindLocation(Pchar.location)].box15.items.shrine = 1;
				locations[FindLocation(Pchar.location)].box15.items.jewelcross = 1;
			}
		break;

		case "return_church_box16":	
			if(CheckCharacterItem(Pchar,"cowl"))
			{
				if(CheckCharacterItem(Pchar,"cowl")) PlaySound("PEOPLE\clothes1.wav");
				
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"No, I don't bother to take anything."));
				TakenItems(Pchar, "cowl", -16); 

				locations[FindLocation(Pchar.location)].box16.items.cowl = 0;
	
				locations[FindLocation(Pchar.location)].box16.items.cowl = 16;
			}
		break;

		case "fail_unlock_church_box5":
			Logit(TranslateString("","No, it wasn't that easy!"));
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		break;

		case "unlock_church_box5":
			Pchar.church.box5 = "open";
			PlaySound("OBJECTS\DUEL\man_attack6.wav");

			LAi_QuestDelay("bladepickaxe2_check", 0.5);
		break;

		case "bladepickaxe2_check":
			if(CheckCharacterItem(Pchar,"bladepickaxe2"))
			{
				EquipCharacterbyItem(Pchar, "bladepickaxe2");
				return;
			}
			else LAi_QuestDelay("bladepickaxe2_check", 0.5);//loop check
		break;

		case "pickup_tools_check":
			if(CheckCharacterItem(Pchar,"bladepickaxe2") && CheckCharacterItem(Pchar,"measuring_tape"))
			{
				na = GetCharacterItem(Pchar, "nails");
				peg = GetCharacterItem(Pchar, "peg");

				if(na == 6 && peg == 4)	
				{
					AddQuestRecord("Useful_items","21");
					CloseQuestHeader("Useful_items");
				}
			}
		break;

		case "book_tools_check":
			if(CheckCharacterItem(Pchar,"bladepickaxe2") && CheckCharacterItem(Pchar,"measuring_tape") && CheckCharacterItem(Pchar,"book61D"))
			{
				na = GetCharacterItem(Pchar, "nails");
				peg = GetCharacterItem(Pchar, "peg");

				if(na == 6 && peg == 4)	
				{
					if(CheckCharacterItem(Pchar,"book61A") || CheckCharacterItem(Pchar,"book61B")
					|| CheckCharacterItem(Pchar,"book61C1") || CheckCharacterItem(Pchar,"book61C2"))
					{
						Pchar.enter_brothel = "ready";

						pchar.quest.under_balcony.win_condition.l1 = "locator";
						pchar.quest.under_balcony.win_condition.l1.location = "GB_Charleston_town";
						pchar.quest.under_balcony.win_condition.l1.locator_group = "goto";
						pchar.quest.under_balcony.win_condition.l1.locator = "brothel_key";
						pchar.quest.under_balcony.win_condition = "under_balcony";
					}					
				}
			}
		break;

		case "leave_confessional_box":
			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_church", "box", "box4");
			ChangeCharacterAddressGroup(characterFromID("GB_mummy3"), "none", "", "");
			LAi_SetPlayerType(Pchar);
		break;

		case "mummy_priest_gone":
			PlaySound("PEOPLE\clothes1.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_church", "box", "box4");
		break;

		case "unlock_Charleston_sacristy":
			//from itemlogic
			TakeItemFromCharacter(Pchar, "key22");
			Locations[FindLocation("GB_Charleston_church")].locators_radius.reload.reload3 = 0.5;
			Locations[FindLocation("GB_Charleston_church")].locators_radius.reload.reload4 = 0.5;
			Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box2 = 0.0001;
			Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box3 = 0.0001;
			Locations[FindLocation("GB_Charleston_church")].reload.l3.disable = 0;
			Locations[FindLocation("GB_Charleston_church")].reload.l4.disable = 0;
			Locations[FindLocation("GB_Charleston_church_office")].reload.l3.disable = 0;
			
			DoQuestReloadToLocation("GB_Charleston_church_office", "reload", "reload3", "prepare_Frollo_brothel");
		break;

		case "prepare_Frollo_brothel":
			SetCurrentTime(22.00, 0);
			SetNextWeather("Clear");
		break;

		case "not_ready_for_brothel_yet":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "not_ready_for_brothel_yet";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "check_brothel_gate":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "check_brothel_gate";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "check_other_side":
			LAi_SetPlayerType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
		break;
		
		case "under_balcony":
			Characters[GetCharacterIndex("Ch_wench2")].dialog.CurrentNode  = "under_balcony";
			LAi_SetActorType(characterFromID("Ch_wench2"));
			LAi_ActorTurnToCharacter(characterFromID("Ch_wench2"), PChar);
			LAi_ActorDialogNow(characterFromID("Ch_wench2"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Ch_wench2"));
		break;

		case "brothel_key":
			PlaySound("INTERFACE\took_item.wav");
			GiveItem2Character(Pchar, "key28");
			AddMoneyToCharacter(Pchar,-10000);	//just in case

			LAi_QuestDelay("Poe_go_on", 1.0);

			pchar.quest.on_balcony.win_condition.l1 = "locator";
			pchar.quest.on_balcony.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.on_balcony.win_condition.l1.locator_group = "goto";
			pchar.quest.on_balcony.win_condition.l1.locator = "brothel_balcony";
			pchar.quest.on_balcony.win_condition = "on_balcony";
		break;

		case "on_balcony":
			Characters[GetCharacterIndex("Ch_wench2")].dialog.CurrentNode  = "on_balcony";
			LAi_SetActorType(characterFromID("Ch_wench2"));
			LAi_ActorTurnToCharacter(characterFromID("Ch_wench2"), PChar);
			LAi_ActorDialogNow(characterFromID("Ch_wench2"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Ch_wench2"));
		break;
//-----------------------------------------------------------------------------------------------------------

		case "return_to_balcony":
			pchar.quest.on_balcony_again.win_condition.l1 = "locator";
			pchar.quest.on_balcony_again.win_condition.l1.location = "GB_Charleston_town";
			pchar.quest.on_balcony_again.win_condition.l1.locator_group = "goto";
			pchar.quest.on_balcony_again.win_condition.l1.locator = "brothel_balcony";
			pchar.quest.on_balcony_again.win_condition = "on_balcony_again";
		break;

		case "on_balcony_again":
			Characters[GetCharacterIndex("Ch_wench2")].dialog.CurrentNode  = "on_balcony_again";
			LAi_SetActorType(characterFromID("Ch_wench2"));
			LAi_ActorTurnToCharacter(characterFromID("Ch_wench2"), PChar);
			LAi_ActorDialogNow(characterFromID("Ch_wench2"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Ch_wench2"));
		break;


//-----------------------------------------------------------------------------------------------------------
		case "pistol_package":
			PlaySound("PEOPLE\clothes1.wav");
			GiveItem2Character(Pchar, "p_package");
			Pchar.p_case_status = "3";
			Pchar.gpb_status = "6";
			Pchar.cap_status = "35";

			TakeItemFromCharacter(Pchar, "book61A" );
			TakeItemFromCharacter(Pchar, "book61B" );
			TakeItemFromCharacter(Pchar, "book61C1" );
			TakeItemFromCharacter(Pchar, "book61C2" );
			TakeItemFromCharacter(Pchar, "book61D" );
			AddQuestRecord("Claude_Frollo's_mission","4");
			CloseQuestHeader("Claude_Frollo's_mission");

			LAi_QuestDelay("leave_brothel_balcony", 1.0);
		break;

		case "leave_brothel_balcony":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(Pchar, "GB_Charleston_town", "reload", "reload24");

			Pchar.quest.return_to_balcony.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.return_to_balcony.win_condition.l1.location = "GB_Charleston_town";
			Pchar.quest.return_to_balcony.win_condition = "return_to_balcony";
		break;

		case "pistol_204_load_check":
			if(CheckAttribute(Pchar,"pistol_204") && Pchar.pistol_204 == "already_loaded")
			{
				
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "pistol204_P") && CheckCharacterItem(Pchar,"cart_box_O") && CheckCharacterItem(Pchar,"caps_box_O"))
				{
					Pchar.pistol_204 = "already_loaded";

					LAi_SetActorType(Pchar);	
					characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Poe_mission";
					LAi_ActorSelfDialog(pchar, "");
				}
			}
		break;

		case "Poe_mission_done":
			LAi_SetPlayerType(Pchar);
			AddQuestRecord("Bishop's_Hostel","13");
			CloseQuestHeader("Weapons");
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "Bessop_plantation", "officers", "reload14_3");
			Pchar.quest.town_exit_closed = "no";

			SetLocatorRadius(locations[FindLocation("Bessop_plantation")], "box", "box3", 0.001);	//temp	
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 0.001;

			pchar.quest.plantation_meeting.win_condition.l1 = "locator";
			pchar.quest.plantation_meeting.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.plantation_meeting.win_condition.l1.locator_group = "officers";
			pchar.quest.plantation_meeting.win_condition.l1.locator = "reload14_3";
			pchar.quest.plantation_meeting.win_condition = "plantation_meeting";
		break;

		case "plantation_meeting":
			Characters[GetCharacterIndex("Legrand_copy")].dialog.CurrentNode  = "plantation_meeting";
			LAi_SetActorType(characterFromID("Legrand_copy"));
			LAi_ActorTurnToCharacter(characterFromID("Legrand_copy"), PChar);
			LAi_ActorDialogNow(characterFromID("Legrand_copy"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Legrand_copy"));
		break;

//----------------------------------------------------------------------------------------------------------------------------
//jump start "16" from here

		case "plantation_switch":
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "none", "", "");
			ChangeCharacterAddressGroup(Pchar, "Bessop_plantation", "goto", "goto100");
			SetModel(Pchar, "William Legrand2", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			Pchar.name = "William";
			Pchar.lastname ="Legrand";

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			TakenItems(Pchar, "cartridges", 12);
			GiveItem2Character(Pchar, "revolver");
			EquipCharacterByItem(Pchar, "revolver");
			GiveItem2Character(Pchar, "fort_rope");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");

			if(CheckAttribute(Pchar,"quest.Legrands_antidote") && Pchar.quest.Legrands_antidote == "yes")
			TakenItems(Pchar, "potion3", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_rum") && Pchar.quest.Legrands_rum == "yes")
			TakenItems(Pchar, "potionrum", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_cauterization") && Pchar.quest.Legrands_cauterization == "yes")
			TakenItems(Pchar, "medical2", 1);
			
			if(!IsOfficer(CharacterFromID("Edgar Allan Poe")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Edgar Allan Poe"));

				ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bessop_plantation", "goto", "goto101");
				AddPassenger(Pchar, characterFromID("Edgar Allan Poe"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Edgar Allan Poe"));
				LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			}
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "First time";
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "bladepickaxe2");
			EquipCharacterbyItem(characterFromID("Edgar Allan Poe"), "bladepickaxe2");
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "pistol204_P");
			TakeNItems(characterFromID("Edgar Allan Poe"),"cart_box_O", 6);
			TakeNItems(characterFromID("Edgar Allan Poe"),"caps_box_O", 6);
			EquipCharacterbyItem(characterFromID("Edgar Allan Poe"), "pistol204_P");
			GiveItem2Character(characterFromID("Edgar Allan Poe"), "measuring_tape");
			TakeNItems(characterFromID("Edgar Allan Poe"),"peg", 4);
			TakeNItems(characterFromID("Edgar Allan Poe"),"nails", 6);

			DeleteQuestHeader("Claude_Frollo's_mission");
			DeleteQuestHeader("Weapons");
			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("Bishop's_Hostel");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","14");

			Locations[FindLocation("Bessop_plantation")].reload.l1.disable = 1; 	//back to town
			locations[FindLocation("GB_Charleston_town")].id.label = "Oh no - they have locked us out!";

			SetLocatorRadius(locations[FindLocation("Bessop_plantation")], "box", "box3", 1.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;

			Locations[FindLocation("Charleston_swamp_end")].reload.l2.disable = 1;	//loghouse

			Locations[FindLocation("Maroon_cavern")].environment.weather = "true";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "true";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_flooded";
			Locations[FindLocation("Maroon_cavern")].locators_radius.box.box9 = 0.0001;
			Locations[FindLocation("Maroon_cavern")].locators_radius.box.box11 = 0.0001;
			Pchar.quest.mar_cav_to_bridge = "locked";
			Pchar.quest.mar_cav_to_hideout = "open";
			Pchar.quest.cavern_ladder = "picked_up";
			Locations[FindLocation("Maroon_Cavern")].models.always.l4 = "";	
			Locations[FindLocation("Maroon_Cavern")].models.always.l5 = "barrelC";
			Locations[FindLocation("Maroon_Cavern")].models.always.l6 = "";	
			Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleC_cork";
			Pchar.quest.tapC = "closed";
			Pchar.quest.ch_shore_resuse_ladder = "no";
			SetCharacterShipLocation(characterFromID("maroon1"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon2"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon3"), "Maroon_cavern");
			SetCharacterShipLocation(characterFromID("maroon4"), "Maroon_cavern");
			Characters[GetCharacterIndex("maroon1")].Ship.Type = "obj_invisible";
			Characters[GetCharacterIndex("maroon2")].Ship.Type = "obj_barrel3_roll";
			Characters[GetCharacterIndex("maroon3")].Ship.Type = "obj_invisible";
			Characters[GetCharacterIndex("maroon4")].Ship.Type = "obj_invisible";

			Locations[FindLocation("Maroon_hideout")].models.always.locators = "Cave_Ship_l_GB_open";
			Locations[FindLocation("Maroon_hideout")].locators_radius.goto.steplock = 0.5;		//0.5 when box is gone
			Locations[FindLocation("Maroon_hideout")].locators_radius.goto.box = 0.0001;		//small when box is gone
			Pchar.quest.hideout.box10 = "locked";							//to stairs
			Locations[FindLocation("Maroon_hideout")].locators_radius.box.box12 = 1.0;		//to raft
			Locations[FindLocation("Maroon_hideout")].MaxSeaHeight = 0.0;

			Locations[FindLocation("Bishops_Hostel")].models.always.locators = "locator_BH2";	//tree + boat + raft
			Characters[GetCharacterIndex("Charleston_guard2")].Ship.Type = "obj_raft3";
			SetCharacterShipLocation(characterFromID("Charleston_guard2"), "Bishops_hostel");
			Characters[GetCharacterIndex("Moultrie_guard3")].Ship.Type = "obj_invisible";		//at boathouse
			SetCharacterShipLocation(characterFromID("Steamship_sailor1"), "Bishops_hostel");	//boat4S at BH

			Pchar.quest.box13_HO_blocked = "yes";
			Pchar.quest.bye_bye_Poe = "done";
			Pchar.quest.sketch_cliff_found = "yes";

			pchar.quest.fine_weather.win_condition.l1 = "location";
			pchar.quest.fine_weather.win_condition.l1.location = "Maroon_Cavern";
			pchar.quest.fine_weather.win_condition = "fine_weather";
		break;

		case "fine_weather":
			SetCurrentTime(11.00, 0);
			SetNextWeather("Clear");	
		break;
	
		case "Poe_to_raft":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto3");

			SetLocatorRadius(locations[FindLocation("Bishops_Hostel")], "box", "box54", 0.001);
			Locations[FindLocation("Bishops_Hostel")].locators_radius.box.box54 = 0.001;

			LAi_QuestDelay("box13_enabled", 1.0);
		break;
	
		case "box13_enabled":
			Pchar.quest.box13_HO_blocked = "no";
		break;

		case "Poe_to_raft1":
			PlaySound("PEOPLE\recoil.wav");
			LAi_SetPoorType(Pchar);
			Pchar.Poe_on_raft = "yes";

			LAi_QuestDelay("box13_enabled", 0.5);
		break;
//JRH box54 small
		case "raft3_to_BH":
			Pchar.BH_last_time = "yes";
	
			LAi_SetStayType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));

			if(!IsOfficer(CharacterFromID("Jupiter")))				
			{
				for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
				RemovePassenger(Pchar, characterFromID("Jupiter"));
				RemovePassenger(Pchar, characterFromID("Edgar Allan Poe"));

				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_Hostel", "officers", "box54_2");

				AddPassenger(Pchar, characterFromID("Edgar Allan Poe"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Edgar Allan Poe"));
				AddPassenger(Pchar, characterFromID("Jupiter"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("Jupiter"));

				LAi_SetOfficerType(characterFromID("Jupiter"));
				RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
				RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
				DeleteAttribute(characterFromID("Jupiter"), "items");
				TakenItems(characterFromID("Jupiter"), "gunpowder", 6);
				GiveItem2Character(characterFromID("Jupiter"), "bladeX4");
				EquipCharacterbyItem(characterFromID("Jupiter"), "bladeX4");
				GiveItem2Character(characterFromID("Jupiter"), "pistolmtoon");
				EquipCharacterbyItem(characterFromID("Jupiter"), "pistolmtoon");	
			}

			string weaponID = GetCharacterEquipByGroup(characterFromID("Jupiter"),GUN_ITEM_TYPE);
			aref weapon;
			Items_FindItem(weaponID, &weapon);

			if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pg2") weapon.shottype = "na2";
			
			LAi_QuestDelay("I_got_the_boat", 5.0);
		break;

		case "I_got_the_boat":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "I_got_the_boat";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "I_got_nails":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "I_got_nails";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "I_got_nails_done":
			PlaySound("AMBIENT\JAIL\chains2.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			TakenItems(characterFromID("Jupiter"), "nails", 6);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			LAi_QuestDelay("pchar_playertype", 1.0);
			LAi_QuestDelay("pchar_yah", 1.0);
			LAi_QuestDelay("poe_go_on", 2.0);
			LAi_QuestDelay("qbook_BH_15", 3.0);

			pchar.quest.this_is_the_tree0.win_condition.l1 = "locator";
			pchar.quest.this_is_the_tree0.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.this_is_the_tree0.win_condition.l1.locator_group = "goto";
			pchar.quest.this_is_the_tree0.win_condition.l1.locator = "tree_base";
			pchar.quest.this_is_the_tree0.win_condition = "this_is_the_tree0";
		break;

		case "qbook_BH_15":
			AddQuestRecord("Bishop's_Hostel","15");
		break;
		
		case "this_is_the_tree0":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			LAi_SetStayType(Pchar);

			DeleteQuestHeader("Bishop's_Hostel");

			LAi_QuestDelay("this_is_the_tree", 3.0);

			pchar.quest.beeline_how_long9.win_condition.l1 = "locator";
			pchar.quest.beeline_how_long9.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.beeline_how_long9.win_condition.l1.locator_group = "officers";
			pchar.quest.beeline_how_long9.win_condition.l1.locator = "L_hole1_1";
			pchar.quest.beeline_how_long9.win_condition = "beeline_how_long9";

			pchar.quest.new_beeline5.win_condition.l1 = "locator";
			pchar.quest.new_beeline5.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.new_beeline5.win_condition.l1.locator_group = "officers";
			pchar.quest.new_beeline5.win_condition.l1.locator = "L_hole2_1";
			pchar.quest.new_beeline5.win_condition = "new_beeline5";	
		break;

		case "this_is_the_tree":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "this_is_the_tree";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Jup_climbs_tree_again":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_climbs_tree_again";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;	

		case "Jup_prepare_to_climb_again":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			PlaySound("INTERFACE\button3.wav");
			TakeItemFromCharacter(Pchar, "goldbug" );

			LAi_QuestDelay("Jup_prepare_to_climb_again1", 1.0);		
		break;	

		case "Jup_prepare_to_climb_again1":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			
			LAi_QuestDelay("Jup_climbs2_tree_done", 1.0);		
		break;	

		case "Jup_climbs2_tree_done":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "Jup_climb1");
			
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "Jup_climb1", "Jup_climbs2_tree_done1", 4.0);

			LAi_QuestDelay("Jup_climbs2_tree_done0", 3.0);
		break;

		case "Jup_climbs2_tree_done0":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "L_bug", "pchar_turn_to_climb1", 3.0);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "officers", "L_bug_1", "poe_turn_to_climb1", 6.0);
		break;

		case "pchar_turn_to_climb1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "Jup_climb1");

			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "poe_turn_to_climb1":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "Jup_climb1");

			LAi_QuestDelay("poe_staytype", 1.0);
		break;	

		case "poe_staytype":
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
		break;	

		case "Jup_climbs2_tree_done1":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb1");

			LAi_QuestDelay("Jup_climbs2_tree_animation2", 3.0);
		break;

		case "Jup_climbs2_tree_animation2":
			PlaySound("PEOPLE\step_grass2.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb2");

			LAi_QuestDelay("Jup_climbs2_tree_animation3", 2.0);		
		break;
	
		case "Jup_climbs2_tree_animation3":
			PlaySound("PEOPLE\step_grass.wav");
			SetModel(characterFromID("Jupiter"), "jupiter", "climb", "man", 1.8, true);	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb3");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation4", 1.2);   
		break;

		case "Jup_climbs2_tree_animation4":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb4");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation4A", 1.2);   
		break;

		case "Jup_climbs2_tree_animation4A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb4A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation5", 1.2);   
		break;

		case "Jup_climbs2_tree_animation5":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb5");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation5A", 1.2);   
		break;

		case "Jup_climbs2_tree_animation5A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb5A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation6", 1.2);   
		break;

		case "Jup_climbs2_tree_animation6":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb6");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation6A", 1.2);   
		break;

		case "Jup_climbs2_tree_animation6A":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb6A");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation7", 1.2);   
		break;

		case "Jup_climbs2_tree_animation7":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb7");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation8", 1.2);   
		break;

		case "Jup_climbs2_tree_animation8":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb8");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation9", 1.2);   
		break;

		case "Jup_climbs2_tree_animation9":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb9");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation10", 1.2);   
		break;

		case "Jup_climbs2_tree_animation10":
			PlaySound("PEOPLE\step_grass1.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb10");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation11", 1.2);   
		break;

		case "Jup_climbs2_tree_animation11":
			PlaySound("PEOPLE\step_grass2.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb11");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation12", 1.2);   
		break;

		case "Jup_climbs2_tree_animation12":
			PlaySound("PEOPLE\step_grass.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb12");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation13", 1.2);   
		break;

		case "Jup_climbs2_tree_animation13":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb13");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "Jup_climbs2_tree_animation14", 1.2);   
		break;

		case "Jup_climbs2_tree_animation14":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb14");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_1", "Jup_climbs2_tree_animation15", 1.2);   
		break;

		case "Jup_climbs2_tree_animation15":
			PlaySound("PEOPLE\grass_turn.wav");	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "officers", "L_bug_2");
			LAi_ActorAnimation(characterFromID("Jupiter"), "Lay_2", "its_so_silent", 4.0);   
		break;

		case "its_so_silent":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "its_so_silent";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Jup_why_stop_delay":
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("Jup_why_stop", 1.0);
		break;

		case "Jup_why_stop":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_why_stop";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_heavy_bug":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_heavy_bug";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_continues_to_skull":
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("Jup_continues_to_skull1", 2.0);
		break;

		case "Jup_continues_to_skull1":
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("Jup_at_the_skull", 2.0);
		break;

		case "Jup_at_the_skull":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_at_the_skull";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_skull_rope_delay":
			LAi_QuestDelay("Jup_skull_rope", 0.5);
		break;

		case "Jup_skull_rope":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_skull_rope";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_thinks_for_a_while":
			LAi_QuestDelay("Poe_simplicity", 2.0);
			LAi_QuestDelay("Jup_sinks_rope", 5.0);
		break;

		case "Jup_sinks_rope":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_sinks_rope";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "BH_rope_down":
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Bishops_Hostel")].models.always.l9= "rope_up";
			locations[FindLocation("Bishops_Hostel")].models.always.l10 = "goldbug_up";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_bug", "BH_rope_down1");
		break;

		case "BH_rope_down1":	
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\grass_turn.wav");	
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("Jup_lowers_rope", 2.0);
		break;

		case "Jup_lowers_rope":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_lowers_rope";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_lowers_rope1":
			Locations[FindLocation("Bishops_Hostel")].models.always.l9= "rope_down";
			locations[FindLocation("Bishops_Hostel")].models.always.l10 = "goldbug_down";			
			Locations[FindLocation("Bishops_Hostel")].locators_radius.box.box56 = 1.0;
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_bug", "Jup_lowers_rope2");
		break;

		case "Jup_lowers_rope2":	
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\grass_turn.wav");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("cancel_sound", 0.5);
			LAi_QuestDelay("Jup_lowers_rope3", 1.0);
		break;

		case "cancel_sound":
			PlaySound("INTERFACE\cancel.wav");	
		break;

		case "Jup_lowers_rope3":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jup_lowers_rope3";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Jup_lowers_rope4":
			LAi_SetPlayerType(Pchar);			
		break;

		case "stake1A":
			SetModel(Pchar, "William Legrand2", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			LAi_SetStayType(Pchar);
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);

			GiveItem2Character(Pchar, "Goldbug");
			GiveItem2Character(Pchar, "fort_rope");
			TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "peg");

			LAi_QuestDelay("place_stake_1A", 1.5);
			LAi_QuestDelay("place_stake_1A", 2.5);
			LAi_QuestDelay("stake1A_placed", 3.5);
		break;

		case "place_stake_1A":
			CreateParticleSystem("blast_dirt_small" , -167.8, 12.5, 184.3, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("PEOPLE\step_stairway2.wav");	
		break;

		case "stake1A_placed":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Jup_down_from_tree2", 1.0);
		break;

		case "Jup_down_from_tree2":
			PlaySound("PEOPLE\jump.wav");
			SetModel(characterFromID("Jupiter"), "jupiter", "man", "man", 1.8, true);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_climb1");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_down_from_tree2A", 0.5);  
		break;

		case "Jup_down_from_tree2A":
			LAi_SetOfficerType(characterFromID("Jupiter"));
			
		 	LAi_QuestDelay("beeline_how_long", 2.0);
		break;

		case "beeline_how_long":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "beeline_how_long";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;
		
		case "beeline_how_long1":
			LAi_SetStayType(Pchar);
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "beeline_how_long2";
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
		break;

		case "beeline_50_feet":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "beeline_50_feet";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "beeline_how_long4":
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "Jup_at_tree", "beeline_how_long5", 2.0);
		break;

		case "beeline_how_long5":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("beeline_how_long6", 1.0);
		break;

		case "beeline_how_long6":
			LAi_SetStayType(characterFromID("Jupiter"));
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_at_tree");

			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "beeline_how_long6_A";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "beeline_how_long7":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "officers", "L_hole1_1", "beeline_how_long8", 17.0);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "L_hole1_1");
		break;

		case "beeline_how_long8":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_hostel", "officers", "L_hole1_1");
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			SetLocatorRadius(locations[FindLocation("Bishops_Hostel")], "officers", "L_hole1_1", 2.0);
			Locations[FindLocation("Bishops_Hostel")].locators_radius.officers.L_hole1_1 = 2.0;
			//enables beeline_how_long9 as checkpoint

			LAi_QuestDelay("pchar_lets_go", 1.0);
		break;

		case "beeline_how_long9":
			Locations[FindLocation("Bishops_Hostel")].models.always.l6= "stake1B";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole1", "stake1B");
		break;

		case "stake1B":
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);
			TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "peg");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("place_stake_1B", 1.5);
			LAi_QuestDelay("place_stake_1B", 2.5);
			LAi_QuestDelay("stake1B_placed", 3.5);
		break;
	
		case "place_stake_1B":
			CreateParticleSystem("blast_dirt_small" , -140.8, 7.6, 184.3, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("PEOPLE\step_stairway2.wav");	
		break;

		case "stake1B_placed":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("Jup_takes_spade", 1.0);
		break;

		case "Jup_takes_spade":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Jup_takes_spade";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Jup_digs_hole1":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladeX4");
			GiveItem2Character(characterFromID("Jupiter"), "bladespade");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladespade");
			PlaySound("PEOPLE\clothes4.wav");	

			LAi_QuestDelay("Jup_spade_equip_check", 0.1);
			LAi_QuestDelay("Jup_digs_hole1_A", 1.0);
		break;

		case "Jup_spade_equip_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"bladespade"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladespade"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "bladespade");
				}

				LAi_QuestDelay("Jup_spade_equip_check", 0.5);//loop check
			}
		break;

		case "Jup_digs_hole1_A":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "officers", "L_hole1_2", "Jup_digs_hole1_B", 2.0);
		break;

		case "Jup_digs_hole1_B":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "officers", "L_hole1_2");
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "hole1");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "hole1");

			LAi_QuestDelay("dig_sand", 1.0);
			LAi_QuestDelay("dig_sand", 2.0);
			LAi_QuestDelay("dig_sand", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 1.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 2.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 2.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_D", 4.0);
		break;

		case "dig_sand":
			PlaySound("PEOPLE\dig_sand.wav");
		break;

		case "Jup_digs_hole1_C":
			CreateParticleSystemX("blast_dirt", -140.8, 7.6, 184.3, -140.8, 7.6, 184.3, 10);
		break;

		case "Jup_digs_hole1_D":
			Locations[FindLocation("Bishops_Hostel")].models.always.l6= "";		//no stake1B
			locations[FindLocation("Bishops_Hostel")].models.always.l11 = "ground1";
			locations[FindLocation("Bishops_Hostel")].models.always.l12 = "pile1A_small";	
			locations[FindLocation("Bishops_Hostel")].models.always.l13 = "pile1B_small";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole1", "Jup_digs_hole1_E");
		break;

		case "Jup_digs_hole1_E":
			LAi_QuestDelay("Jup_digs_hole1_C", 0.1);
			LAi_SetFightMode(characterFromID("Jupiter"), false);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("Jup_digs_hole1_EE", 2.0);
			LAi_QuestDelay("Poe_try_again", 4.0);
			LAi_QuestDelay("Jup_digs_hole1_F", 6.0);
		break;

		case "Jup_digs_hole1_EE":
			PlaySound("VOICE\ENGLISH\poe_result.wav");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "hole1");
		break;

		case "Jup_digs_hole1_F":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");

			LAi_QuestDelay("Jup_digs_hole1_G", 1.0);
		break;

		case "Jup_digs_hole1_G":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "officers", "L_hole1_2", "Jup_digs_hole1_H", 2.0);
		break;

		case "Jup_digs_hole1_H":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "officers", "L_hole1_2");
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "hole1");

			LAi_QuestDelay("dig_sand", 1.0);
			LAi_QuestDelay("dig_sand", 2.0);
			LAi_QuestDelay("dig_sand", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 1.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 2.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 2.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_C", 3.0);
			LAi_QuestDelay("Jup_digs_hole1_I", 4.0);
		break;

		case "Jup_digs_hole1_I":
			locations[FindLocation("Bishops_Hostel")].models.always.l11 = "ground1";
			locations[FindLocation("Bishops_Hostel")].models.always.l12 = "pile1A_large";	
			locations[FindLocation("Bishops_Hostel")].models.always.l13 = "pile1B_large";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole1", "Jup_digs_hole1_J");
		break;

		case "Jup_digs_hole1_J":
			LAi_QuestDelay("Jup_digs_hole1_C", 0.1);
			LAi_SetFightMode(characterFromID("Jupiter"), false);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp
			
			LAi_QuestDelay("Jup_digs_hole1_K", 2.0);
		break;

		case "Jup_digs_hole1_K":
			PlaySound("VOICE\ENGLISH\jupiter_1.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			LAi_QuestDelay("pchar_sigh", 2.0);
			LAi_QuestDelay("Jup_digs_hole1_L", 4.0);
			LAi_QuestDelay("wrong_spot", 7.0);
		break;

		case "Jup_digs_hole1_L":
			PlaySound("VOICE\ENGLISH\poe_very_nice.wav");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "wrong_spot":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "wrong_spot";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "wrong_spot_done":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "hole1");
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);

			LAi_QuestDelay("wrong_spot1", 2.0);
		break;

		case "wrong_spot1":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "wrong_spot1";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "wrong_spot2":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "wrong_spot2";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "wrong_spot2_done":
			LAi_QuestDelay("poe_look", 0.1);

			LAi_QuestDelay("restart_from_tree1", 1.0);
		break;

		case "restart_from_tree1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "tree_base");
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			LAi_QuestDelay("pchar_playertype", 1.0);

			pchar.quest.restart_from_tree2.win_condition.l1 = "locator";
			pchar.quest.restart_from_tree2.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.restart_from_tree2.win_condition.l1.locator_group = "goto";
			pchar.quest.restart_from_tree2.win_condition.l1.locator = "tree_base";
			pchar.quest.restart_from_tree2.win_condition = "restart_from_tree2";
		break;

		case "restart_from_tree2":
			LAi_QuestDelay("pchar_puh", 0.1);
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "L_bug");
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("right_eye", 4.0);
		break;

		case "right_eye":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "right_eye";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "right_eye1_done":
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("right_eye2", 2.0);
		break;

		case "right_eye2":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "right_eye2";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "right_eye3_done":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "officers", "L_bug_1", "peg3", 2.0);
		break;

		case "peg3":
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_hostel", "officers", "L_bug_1");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("peg3_1", 1.0);
		break;

		case "peg3_1":
			locations[FindLocation("Bishops_Hostel")].models.always.l7 = "stake2A";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			Locations[FindLocation("Bishops_Hostel")].models.always.locators = "locator_BH3";	//officers L_bug_2 = on ground
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_bug", "peg3_2");
		break;

		case "peg3_2":
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);
			TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "peg");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("place_stake_2A", 1.5);
			LAi_QuestDelay("place_stake_2A", 2.5);
			LAi_QuestDelay("stake2A_placed", 3.5);
		break;

		case "place_stake_2A":
			CreateParticleSystem("blast_dirt_small" , -167.9, 12.5, 184.0, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("PEOPLE\step_stairway2.wav");	
		break;

		case "stake2A_placed":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("new_beeline", 1.0);
		break;

		case "new_beeline":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "new_beeline";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "new_beeline1":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "Jup_at_tree", "new_beeline2", 2.0);
		break;

		case "new_beeline2":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("new_beeline3", 1.0);
		break;

		case "new_beeline3":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_at_tree");

			LAi_QuestDelay("poe_try_again", 1.0);
			
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "officers", "L_hole2_1", "new_beeline4", 17.0);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "L_hole2_1");
		break;

		case "new_beeline4":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_hostel", "officers", "L_hole2_1");
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Jupiter"));
			SetLocatorRadius(locations[FindLocation("Bishops_Hostel")], "officers", "L_hole2_1", 2.0);
			Locations[FindLocation("Bishops_Hostel")].locators_radius.officers.L_hole2_1 = 2.0;
			
			LAi_QuestDelay("pchar_lets_go", 1.0);	
		break;

		case "new_beeline5":
			Locations[FindLocation("Bishops_Hostel")].models.always.l8= "stake2B";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "stake2B");
		break;

		case "stake2B":
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);
			TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "peg");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("place_stake_2B", 1.5);
			LAi_QuestDelay("place_stake_2B", 2.5);
			LAi_QuestDelay("stake2B_placed", 3.5);
		break;
	
		case "place_stake_2B":
			CreateParticleSystem("blast_dirt_small" , -141.2, 7.7, 176.8, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("PEOPLE\step_stairway2.wav");	
		break;

		case "stake2B_placed":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("Legrand_digs", 1.0);
		break;

		case "Legrand_digs":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Legrand_digs";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Legrand_digs1":
			TakeItemFromCharacter(characterFromID("Jupiter"), "bladespade");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladeX4");
			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			PlaySound("PEOPLE\clothes4.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "skeleton2A");

			LAi_QuestDelay("Legrand_digs2", 1.0);	
		break;

		case "Legrand_digs2":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);
		
			LAi_QuestDelay("dig_sand", 1.0);
			LAi_QuestDelay("dig_sand", 2.0);
			LAi_QuestDelay("dig_sand", 3.0);
			LAi_QuestDelay("Legrand_digs3", 1.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs4", 4.0);
		break;

		case "Legrand_digs3":
			CreateParticleSystemX("blast_dirt", -141.2, 7.7, 176.8, -141.2, 7.7, 176.8, 10);
		break;

		case "Legrand_digs4":
			Locations[FindLocation("Bishops_Hostel")].models.always.l8= "";			//peg4 not visible
			locations[FindLocation("Bishops_Hostel")].models.always.l14 = "ground2";
			locations[FindLocation("Bishops_Hostel")].models.always.l15 = "pile2A_small";	
			locations[FindLocation("Bishops_Hostel")].models.always.l16 = "pile2B_small";
			locations[FindLocation("Bishops_Hostel")].models.always.l17 = "bone";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "Legrand_digs5");
		break;

		case "Legrand_digs5":
			LAi_QuestDelay("Legrand_digs3", 0.1);
			LAi_SetFightMode(Pchar, false);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "skeleton2A");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "skeleton2A");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp
			
			LAi_QuestDelay("Legrand_digs6", 2.0);
		break;

		case "Legrand_digs6":
			LAi_QuestDelay("Legrand_digs3", 0.1);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp
			
			LAi_QuestDelay("Poe_ooh", 0.1);
			LAi_QuestDelay("Legrand_digs7", 2.0);
		break;

		case "Legrand_digs7":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));
		
			LAi_QuestDelay("pchar_huh", 0.1);
			LAi_QuestDelay("Legrand_digs8", 2.0);
		break;

		case "Legrand_digs8":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("Poe_trophy", 0.1);
			LAi_QuestDelay("Legrand_digs9", 2.0);
		break;

		case "Legrand_digs9":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));
		
			LAi_QuestDelay("pchar_ohoh", 0.1);
			LAi_QuestDelay("Legrand_digs10", 2.0);
		break;

		case "Legrand_digs10":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Edgar Allan Poe"));
			
			
			LAi_QuestDelay("Poe_look", 0.1);
			LAi_QuestDelay("Legrand_digs11", 2.0);
		break;

		case "Legrand_digs11":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "skeleton2A");

			LAi_QuestDelay("Legrand_digs12", 1.0);	
		break;

		case "Legrand_digs12":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);
		
			LAi_QuestDelay("dig_sand", 1.0);
			LAi_QuestDelay("dig_sand", 2.0);
			LAi_QuestDelay("dig_sand", 3.0);
			LAi_QuestDelay("Legrand_digs3", 1.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs13", 4.0);
		break;

		case "Legrand_digs13":
			locations[FindLocation("Bishops_Hostel")].models.always.l14 = "ground2";
			locations[FindLocation("Bishops_Hostel")].models.always.l15 = "pile2A_large";	
			locations[FindLocation("Bishops_Hostel")].models.always.l16 = "pile2B_large";
			locations[FindLocation("Bishops_Hostel")].models.always.l17 = "";		//no bone
			locations[FindLocation("Bishops_Hostel")].models.always.l18 = "chest_buried";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "Legrand_digs14");
		break;

		case "Legrand_digs14":
			LAi_QuestDelay("Legrand_digs3", 0.1);
			ChangeCharacterAddressGroup(characterFromID("buried_skeleton1"), "Bishops_hostel", "goto", "skeleton1A");
			ChangeCharacterAddressGroup(characterFromID("buried_skeleton2"), "Bishops_hostel", "goto", "skeleton2A");
			LAi_SetFightMode(Pchar, false);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "skeleton2A");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "skeleton2A");
			PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("skeletons_found0", 1.0);
			LAi_QuestDelay("skeletons_found", 2.0);
		break;

		case "skeletons_found0":
			PlaySound("PEOPLE\recoil.wav");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jup_back");

			LAi_QuestDelay("skeletons_found00", 1.0);
		break;

		case "skeletons_found00":
			LAi_SetStayType(characterFromID("Jupiter"));
		break;

		case "skeletons_found":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "skeletons_found";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "skeletons_found1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "skeletons_found1";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "skeletons_found2":
			Pchar.treasure_spot = "2_skeletons";			
			SetLocatorRadius(locations[FindLocation("Bishops_Hostel")], "box", "box57", 1.5);
			Locations[FindLocation("Bishops_Hostel")].locators_radius.box.box57 = 1.5;
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("poe_look", 0.1);

			pchar.quest.move_skeleton.win_condition.l1 = "locator";
			pchar.quest.move_skeleton.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.move_skeleton.win_condition.l1.locator_group = "box";
			pchar.quest.move_skeleton.win_condition.l1.locator = "box57";
			pchar.quest.move_skeleton.win_condition = "move_skeleton";
		break;

		case "move_skeleton":
			ChangeCharacterAddressGroup(Pchar, "Bishops_Hostel", "goto", "L_skel1_start");
			LAi_SetStayType(Pchar);
		break;

		case "move_skeleton1":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			LAi_SetSitType(Pchar);
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("move_skeleton1_1", 1.0);
		break;

		case "move_skeleton1_1":
			PlaySound("OBJECTS\VOICES\skeleton_body1.wav");
			ChangeCharacterAddressGroup(characterFromID("buried_skeleton1"), "Bishops_hostel", "goto", "skeleton1B");
			LAi_SetStayType(Pchar);
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("enable_move_skeleton2", 1.0);
		break;

		case "enable_move_skeleton2":
			Pchar.quest.box_blocked = "no";
			Pchar.treasure_spot = "1_skeleton";

			LAi_QuestDelay("Poe_try_again", 0.1);
		break;

		case "move_skeleton2":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			LAi_SetSitType(Pchar);
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("move_skeleton2_1", 1.0);
		break;

		case "move_skeleton2_1":
			PlaySound("OBJECTS\VOICES\skeleton_body1.wav");
			ChangeCharacterAddressGroup(characterFromID("buried_skeleton2"), "Bishops_hostel", "goto", "skeleton2B");
			LAi_SetStayType(Pchar);
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("enable_see_cutlass", 1.0);
		break;

		case "enable_see_cutlass":
			Pchar.quest.box_blocked = "no";
			Pchar.treasure_spot = "cutlass";
		break;

		case "enable_dig_up_metal":	
			Pchar.quest.box_blocked = "no";
			Pchar.treasure_spot = "metal";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "skeleton2A");

			LAi_QuestDelay("poe_go_on", 0.1);
		break;

		case "dig_up_chest":
			locations[FindLocation("Bishops_Hostel")].models.always.l18 = "chest_locked";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "dig_up_chest1");
		break;

		case "dig_up_chest1":
			LAi_QuestDelay("Legrand_digs3", 0.1);
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			LAi_SetFightMode(Pchar, false);
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
			LAi_SetStayType(characterFromID("Jupiter"));
			Pchar.quest.box_blocked = "no";
			Pchar.treasure_spot = "locked_chest";
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("poe_ooh", 1.0);
			LAi_QuestDelay("pchar_oh", 2.0);

			pchar.quest.dig_up_chest2.win_condition.l1 = "locator";
			pchar.quest.dig_up_chest2.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.dig_up_chest2.win_condition.l1.locator_group = "box";
			pchar.quest.dig_up_chest2.win_condition.l1.locator = "box57";
			pchar.quest.dig_up_chest2.win_condition = "dig_up_chest2";
		break;

		case "dig_up_chest2":
			LAi_SetStayType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_unlocks_chest":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "Poe_unlocks_chest";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Poe_unlocks_chest1":
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);

			LAi_QuestDelay("Poe_unlocks_chest2", 1.0);
		break;

		case "Poe_unlocks_chest2":
			PlaySound("PEOPLE\blade_basket.wav");
			
			LAi_QuestDelay("Poe_unlocks_chest3", 1.5);
		break;

		case "Poe_unlocks_chest3":
			locations[FindLocation("Bishops_Hostel")].models.always.l18 = "chest_open";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "Poe_unlocks_chest4");
		break;

		case "Poe_unlocks_chest4":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_SetActorType(characterFromID("Jupiter"));
			Pchar.quest.box_blocked = "no";
			Pchar.treasure_spot = "open_chest";
			Pchar.opened_once = "no";
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("pchar_lets_go", 1.0);
			LAi_QuestDelay("prepare_dance_number", 2.0);

			pchar.quest.open_treasure_chest.win_condition.l1 = "locator";
			pchar.quest.open_treasure_chest.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.open_treasure_chest.win_condition.l1.locator_group = "box";
			pchar.quest.open_treasure_chest.win_condition.l1.locator = "box57";
			pchar.quest.open_treasure_chest.win_condition = "open_treasure_chest";
		break;

		case "prepare_dance_number":
			LAi_QuestDelay("poe_ok", 0.1);
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "poe_look");
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "jup_look");
			
			LAi_QuestDelay("prepare_dance_number1", 1.0);
		break;

		case "prepare_dance_number1":
			LAi_QuestDelay("pchar_yah", 0.1);

			locx = stf(loadedLocation.locators.camera.camera_2.x);
       			locy = stf(loadedLocation.locators.camera.camera_2.y);
       			locz = stf(loadedLocation.locators.camera.camera_2.z);
       			locCameraToPos(locx, locy, locz, false);

			LAi_QuestDelay("dance_number_start", 1.0);
		break;

		case "dance_number_start":
			PlayStereoSound("Ambient\JUNGLE\wr_crew2.wav");

			LAi_QuestDelay("dance_turn_left", 0.01);
			LAi_QuestDelay("dance_turn_center", 1.5);
			LAi_QuestDelay("dance_turn_right", 2.5);
			LAi_QuestDelay("dance_turn_center", 3.5);

			LAi_QuestDelay("dance_turn_left", 4.5);
			LAi_QuestDelay("dance_turn_center", 5.5);
			LAi_QuestDelay("dance_turn_right", 6.5);
			LAi_QuestDelay("dance_turn_back", 7.5);

			LAi_QuestDelay("hands_up", 8.5);		
			LAi_QuestDelay("stop_animation", 13.7);		
		break;

		case "dance_turn_left":
			LAi_ActorTurnToLocator(Pchar, "goto", "L_look_L");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "off_look_L");
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "off_look_L");
		break;

		case "dance_turn_center":
			LAi_ActorTurnToLocator(Pchar, "goto", "poe_look_C");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "poe_look_C");
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "jup_look_C");
		break;

		case "dance_turn_right":
			LAi_ActorTurnToLocator(Pchar, "goto", "L_look_R");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "goto", "off_look_R");
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "off_look_R");
		break;

		case "dance_turn_back":
			LAi_ActorTurnToLocator(Pchar, "camera", "camera_2");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "camera", "camera_2");
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "camera", "camera_2");
		break;

		case "hands_up":
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorAnimation(Pchar, "hands up", "", 1.0);
			LAi_ActorAnimation(CharacterFromID("Edgar Allan Poe"), "hands up", "", 1.0);
			LAi_ActorAnimation(CharacterFromID("Jupiter"), "hands up", "", 1.0);
		break;

		case "stop_animation":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "poe_look_C");
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			LAi_QuestDelay("reset_camera", 1.0);
		break;

		case "reset_camera":
			LAi_SetPlayerType(Pchar);
			SendMessage(&locCamera, "l", MSG_CAMERA_FOLLOW);
		break;

		case "open_treasure_chest":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "L_skel1_start");
			LAi_SetStayType(Pchar);
		break;

		case "sacks_from_Jupiter":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "sacks_from_Jupiter";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "sacks_from_Jupiter1":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "L_skel1_start");
			PlaySound("PEOPLE\clothes1.wav");
			TakenItems(characterFromID("Jupiter"), "emptysack", -3);
			TakenItems(Pchar, "emptysack", 3);
		break;

		case "place_treasure_in_sacks":
			TakenItems(Pchar, "mixed_treasure", -3);
		break;

		case "check_3_first_sacks":
			int t_s = GetCharacterItem(Pchar, "treasuresack");
			if(t_s == 3) 
			{
				Pchar.treasure_tour = "1"; 				

				LAi_QuestDelay("3_first_sacks", 1.0);
			}
		break;

		case "3_first_sacks":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "3_first_sacks";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "3_first_sacks_taken":
			LAi_QuestDelay("poe_and", 0.1);
			LAi_QuestDelay("jupiter_bad", 1.0);

			LAi_QuestDelay("3_first_sacks_taken1", 2.0);
		break;

		case "3_first_sacks_taken1":
			LAi_SetActorType(Pchar);	
			LAi_ActorTurnToLocator(Pchar, "camera", "camera_2");
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box59", 2.4);		//near boat
			Locations[FindLocation("Bishops_hostel")].locators_radius.box.box59 = 2.4;

			LAi_QuestDelay("pchar_lets_go", 1.0);
			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		
	//----------------------------------------------------------------------------	


		case "treasure_tour1_done":
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "box", "box60", "prepare_tour2");
		break;

		case "prepare_tour2":
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("prepare_tour2_sacks", 1.0);
		break;

		case "prepare_tour2_sacks":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "prepare_tour2";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "where_are_the_maroons":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "where_are_the_maroons";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;	

		case "where_are_the_maroons1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "where_are_the_maroons1";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "prepare_tour2_done":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			GiveItem2Character(Pchar, "emptysack");
			TakenItems(characterFromID("Jupiter"), "emptysack", -3);
			
			pchar.quest.treasure_chest2.win_condition.l1 = "locator";
			pchar.quest.treasure_chest2.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.treasure_chest2.win_condition.l1.locator_group = "box";
			pchar.quest.treasure_chest2.win_condition.l1.locator = "box57";
			pchar.quest.treasure_chest2.win_condition = "treasure_chest2";
		break;

		case "treasure_chest2":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "L_skel1_start");
			LAi_SetStayType(Pchar);
		break;

		case "3_next_sacks_taken":
			LAi_SetActorType(Pchar);	
			LAi_ActorTurnToLocator(Pchar, "camera", "camera_2");
			
			LAi_QuestDelay("pchar_lets_go", 1.0);
			LAi_QuestDelay("pchar_playertype", 1.0);
		break;

		case "treasure_tour2_done":
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "box", "box60", "prepare_tour3");
		break;

		case "prepare_tour3":
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("prepare_tour3_sacks", 1.0);
		break;

		case "prepare_tour3_sacks":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "prepare_tour3";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "prepare_tour3_done":
			PlaySound("OBJECTS\duel\man_hit1.wav");
			GiveItem2Character(Pchar, "emptysack");
			TakenItems(characterFromID("Jupiter"), "emptysack", -2);
			
			pchar.quest.treasure_chest3.win_condition.l1 = "locator";
			pchar.quest.treasure_chest3.win_condition.l1.location = "Bishops_Hostel";
			pchar.quest.treasure_chest3.win_condition.l1.locator_group = "box";
			pchar.quest.treasure_chest3.win_condition.l1.locator = "box57";
			pchar.quest.treasure_chest3.win_condition = "treasure_chest3";
		break;

		case "treasure_chest3":
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "L_skel1_start");
			LAi_SetStayType(Pchar);
		break;

		case "2_last_sacks_taken":
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "jup_chest", "Jup_lifts_chest", 4.0);
		break;

		case "Jup_lifts_chest":
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);

			LAi_QuestDelay("Jup_lifts_chest1", 1.0);
		break;

		case "Jup_lifts_chest1":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_lifts_chest2", 1.0);
		break;

		case "Jup_lifts_chest2":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			LAi_SetStayType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("Jup_lifts_chest3", 1.0);
		break;

		case "Jup_lifts_chest3":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "officers", "L_hole2_1", "Jup_lifts_chest4", 4.0);
		break;

		case "Jup_lifts_chest4":
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);

			LAi_QuestDelay("Jup_lifts_chest5", 1.0);
		break;


		case "Jup_lifts_chest5":
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);

			LAi_QuestDelay("Jup_lifts_chest6", 1.0);
		break;

		case "Jup_lifts_chest6":
			PlaySound("PEOPLE\ram.wav");
			
			LAi_QuestDelay("Jup_lifts_chest7", 1.0);
		break;

		case "Jup_lifts_chest7":
			PlaySound("PEOPLE\ram.wav");
			
			LAi_QuestDelay("Jup_lifts_chest8", 1.0);
		break;

		case "Jup_lifts_chest8":
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);

			LAi_QuestDelay("poe_try_again", 1.0);
			LAi_QuestDelay("Jup_lifts_chest9", 2.0);
		break;

		case "Jup_lifts_chest9":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_lifts_chest10", 1.0);
		break;

		case "Jup_lifts_chest10":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			LAi_SetStayType(characterFromID("Jupiter"));
			
			LAi_QuestDelay("Jup_lifts_chest11", 1.0);
		break;

		case "Jup_lifts_chest11":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);
		
			LAi_QuestDelay("dig_sand", 1.0);
			LAi_QuestDelay("dig_sand", 2.0);
			LAi_QuestDelay("dig_sand", 3.0);
			LAi_QuestDelay("Legrand_digs3", 1.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 2.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Legrand_digs3", 3.0);
			LAi_QuestDelay("Jup_lifts_chest12", 4.0);
		break;

		case "Jup_lifts_chest12":
			locations[FindLocation("Bishops_Hostel")].models.always.l18 = "chest_free";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "Jup_lifts_chest13");
		break;

		case "Jup_lifts_chest13":
			LAi_QuestDelay("Legrand_digs3", 0.1);
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp
			
			LAi_QuestDelay("Jup_lifts_chest14", 1.0);
		break;

		case "Jup_lifts_chest14":
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			LAi_SetSitType(characterFromID("Jupiter"));

			LAi_QuestDelay("Jup_lifts_chest15", 1.0);
		break;

		case "Jup_lifts_chest15":
			locations[FindLocation("Bishops_Hostel")].models.always.l18 = "";
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_hole2", "Jup_lifts_chest16");
		break;

		case "Jup_lifts_chest16":
			GiveItem2Character(characterFromID("Jupiter"), "treasurechest_red");
			EquipCharacterByItem(characterFromID("Jupiter"), "treasurechest_red");
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box57", 0.001);
			Locations[FindLocation("Bishops_hostel")].locators_radius.box.box57 = 0.001;

			LAi_QuestDelay("Jup_chest_equip_check", 0.1);
		break;

		case "Jup_chest_equip_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"treasurechest_red"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "treasurechest_red"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "treasurechest_red");
				}

				LAi_QuestDelay("Jup_chest_equip_check", 0.5);//loop check
			}
		break;

		case "treasure_tour3_done":
			Locations[FindLocation("Bishops_Hostel")].MaxSeaHeight = 0.0;
			Locations[FindLocation("Bishops_Hostel")].image = "";
			DoQuestReloadToLocation("Bishops_Hostel", "box", "box60", "treasure_tour3_done1");
		break;

		case "treasure_tour3_done1":
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box59", 0.001);
			Locations[FindLocation("Bishops_hostel")].locators_radius.box.box59 = 0.001;
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "near_raft");
			LAi_SetStayType(characterFromID("Jupiter"));
			LAi_SetActorType(Pchar);
			Locations[FindLocation("Bishops_Hostel")].image = "GB_Bishops_hostel.tga";	//temp

			LAi_QuestDelay("rope_to_raft", 1.0);
		break;

		case "rope_to_raft":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "rope_to_raft";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;
		
		case "rope_to_raft_done":
			PlaySound("PEOPLE\clothes1.wav");
			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			TakeItemFromCharacter(Pchar, "fort_rope");

			LAi_QuestDelay("Jup_to_raft", 1.0);
		break;

		case "Jup_to_raft":
			LAi_SetActorType(characterFromID("Jupiter"));	
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "jupiter_raft");

			LAi_QuestDelay("Jup_to_raft1", 1.0);
		break;

		case "Jup_to_raft1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead3.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorAnimation(characterFromID("Jupiter"), "jump", "Jup_to_raft3", 1.8);
		
			LAi_QuestDelay("Jup_to_raft2", 0.5);
		break;

		case "Jup_to_raft2":
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jupiter_raft");
		
			LAi_QuestDelay("Jup_to_raft4", 0.4);
			LAi_QuestDelay("Legrand_see_boat", 1.0);
		break;

		case "Jup_to_raft4":
			PlaySound("PEOPLE\jump.wav");
		break;

		case "Jup_to_raft3":
			LAi_SetActorType(characterFromID("Jupiter"));	
			LAi_ActorTurnToLocator(characterFromID("Jupiter"), "goto", "legrand_boat");
		break;
	
		case "Legrand_see_boat":
			LAi_SetActorType(Pchar);	
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ship_6");

			LAi_QuestDelay("Poe_to_boat", 1.0);
		break;

		case "Poe_to_boat":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "box", "box59", "Poe_to_boat0", 2.0);
		break;

		case "Poe_to_boat0":
			LAi_QuestDelay("Poe_ooh", 0.1);
			PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorAnimation(characterFromID("Edgar Allan Poe"), "jump", "Poe_to_boat1", 0.5);
		break;

		case "Poe_to_boat1":
			PlaySound("PEOPLE\step_stairway.wav");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_hostel", "goto", "poe_boat");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			LAi_SetPlayerType(Pchar);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box59", 1.0);
			Locations[FindLocation("Bishops_hostel")].locators_radius.box.box59 = 1.0;
			Pchar.treasure_tour = "boat";

			LAi_QuestDelay("Poe_to_boat2", 0.5);
		break;
		
		case "Poe_to_boat2":
			LAi_SetStayType(characterFromID("Edgar Allan Poe"));
		break;

		case "treasure_boat_leave":
			PlaySound("PEOPLE\jump_roof.wav");
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "goto", "legrand_boat");
			
			LAi_QuestDelay("treasure_boat_leave0", 2.0);
		break;

		case "treasure_boat_leave0":
			PlaySound("PEOPLE\creak2.wav");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			
			LAi_QuestDelay("Poe_ok", 1.0);
			LAi_QuestDelay("treasure_boat_leave1", 2.0);
		break;

		case "treasure_boat_leave1":
			PlaySound("PEOPLE\step_stairway.wav");
			LAi_SetPoorType(characterFromID("Jupiter"));
	
			LAi_QuestDelay("pchar_lead_way_out", 1.0);
			LAi_QuestDelay("treasure_boat_leave2", 2.0);
		break;

		case "treasure_boat_leave2":
			LAi_QuestDelay("quicksave", 0.1);
			ChangeCharacterAddressGroup(Pchar, "Bishops_hostel", "box", "box58");
			PlaySound("PEOPLE\step_stairway2.wav");
			LAi_SetSitType(Pchar);
			
			LAi_QuestDelay("treasure_boat_leave3", 1.0);
		break;

		case "treasure_boat_leave3":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
		break;
	
//------------------------------------------------------------------------------------------------------------

		case "final_battle":
			SetModel(Pchar, "William Legrand_sack", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe_sack", "man", "man", 1.8, true);
			SetModel(characterFromID("Jupiter"), "Jupiter_sack", "man", "man", 1.8, true);

			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));
			LAi_SetImmortal(characterFromID("Edgar Allan Poe"), true);
			LAi_SetImmortal(characterFromID("Jupiter"), true);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload2_back", 0.001);
			Locations[FindLocation("Legrands_boathouse")].locators_radius.reload.reload2_back = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.001);
			Locations[FindLocation("Legrands_boathouse")].locators_radius.box.box1 = 0.001;

			GiveItem2Character(characterFromID("maroon1"), "spyglass1");
			GiveItem2Character(characterFromID("maroon1"), "opium");

			GiveItem2Character(characterFromID("maroon2"), "2winebottles");
			GiveItem2Character(characterFromID("maroon3"), "tobacco");	
			GiveItem2Character(characterFromID("maroon3"), "tobacco");
			GiveItem2Character(characterFromID("maroon4"), "medical2");
			GiveItem2Character(characterFromID("maroon5"), "fish");			
			GiveItem2Character(characterFromID("maroon5"), "fish");
			GiveItem2Character(characterFromID("maroon_girl"), "jewelry15");

			GiveItem2Character(characterFromID("mystery_monk"), "animists_amulet");
			GiveItem2Character(characterFromID("mystery_monk"), "book_exorcist"); 	
			GiveItem2Character(characterFromID("mystery_monk"), "bladeskull1"); 	

			GiveItem2Character(characterFromID("deserter_us2"), "powderflask");				
			GiveItem2Character(characterFromID("white_trash1"), "altar_bread");						
			GiveItem2Character(characterFromID("white_trash2"), "potionrum");
			GiveItem2Character(characterFromID("indian_bandit"), "indian1");
			GiveItem2Character(characterFromID("hunter_bandit"), "meat");
		
			pchar.quest.maroons_attack.win_condition.l1 = "locator";
			pchar.quest.maroons_attack.win_condition.l1.location = "Legrands_boathouse";
			pchar.quest.maroons_attack.win_condition.l1.locator_group = "goto";
			pchar.quest.maroons_attack.win_condition.l1.locator = "attack";
			pchar.quest.maroons_attack.win_condition = "maroons_attack";
		break;

		case "exit_stop":
			pchar.quest.exit_stop1.win_condition.l1 = "locator";
			pchar.quest.exit_stop1.win_condition.l1.location = "Legrands_boathouse";
			pchar.quest.exit_stop1.win_condition.l1.locator_group = "goto";
			pchar.quest.exit_stop1.win_condition.l1.locator = "exit_stop";
			pchar.quest.exit_stop1.win_condition = "exit_stop1";
		break;

		case "exit_stop1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Logit(TranslateString("","Not the right time to leave."));			
			ChangeCharacterAddressGroup(Pchar, "Legrands_boathouse", "goto", "step_back");

			LAi_QuestDelay("exit_stop", 0.1);
		break;
	//--------------------------------------------------------------------------------------------------	

		case "Jup_clubmtoon_equip_check":
			if(CheckCharacterItem(characterFromID("Jupiter"),"clubmusketoon"))
			{
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "clubmusketoon"))
				{
					EquipCharacterbyItem(characterFromID("Jupiter"), "clubmusketoon");
				}

				LAi_QuestDelay("Jup_clubmtoon_equip_check", 0.5);//loop check
			}
		break;
	
		case "maroons_attack":
			ChangeCharacterAddressGroup(characterFromID("maroon1"), "Legrands_boathouse", "quest", "quest1");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "Legrands_boathouse", "quest", "quest1");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "Legrands_boathouse", "quest", "quest1");
			
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "Legrands_boathouse", "quest", "quest2");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "Legrands_boathouse", "quest", "quest2");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "Legrands_boathouse", "quest", "quest2");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "Legrands_boathouse", "quest", "quest2");



			PlaySound("OBJECTS\ABORDAGE\abordage_wining.wav");
			LAi_group_Register("MAROONS");
			LAi_group_MoveCharacter(characterFromID("maroon1"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("maroon2"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("white_trash1"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("deserter_us1"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("maroon3"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("indian_bandit"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("maroon5"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("Edgar Allan Poe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Jupiter"), LAI_GROUP_PLAYER);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "MAROONS", LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "MAROONS", true);

			LAi_SetStayType(Pchar);
		
			Pchar.quest.7first_maroons_dead.win_condition.l1 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l1.character = "maroon1";
			Pchar.quest.7first_maroons_dead.win_condition.l2 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l2.character = "maroon2";
			Pchar.quest.7first_maroons_dead.win_condition.l3 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l3.character = "maroon3";
			Pchar.quest.7first_maroons_dead.win_condition.l4 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l4.character = "maroon5";
			Pchar.quest.7first_maroons_dead.win_condition.l5 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l5.character = "indian_bandit";
			Pchar.quest.7first_maroons_dead.win_condition.l6 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l6.character = "deserter_us1";
			Pchar.quest.7first_maroons_dead.win_condition.l7 = "NPC_Death";
			Pchar.quest.7first_maroons_dead.win_condition.l7.character = "white_trash1";
			Pchar.quest.7first_maroons_dead.win_condition = "7first_maroons_dead";

			pchar.quest.exit_stop1.win_condition.l1 = "locator";
			pchar.quest.exit_stop1.win_condition.l1.location = "Legrands_boathouse";
			pchar.quest.exit_stop1.win_condition.l1.locator_group = "goto";
			pchar.quest.exit_stop1.win_condition.l1.locator = "exit_stop";
			pchar.quest.exit_stop1.win_condition = "exit_stop1";

			LAi_QuestDelay("maroons_attack1", 1.0);
		break;
	
		case "maroons_attack1":
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);
			LAi_SetPlayerType(characterFromID("Edgar Allan Poe"));
			LAi_SetFightMode(characterFromID("Edgar Allan Poe"), true);
			LAi_SetPlayerType(characterFromID("Jupiter"));
			LAi_SetFightMode(characterFromID("Jupiter"), true);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));
		break;

		case "7first_maroons_dead":
			//Logit("ALL 7 ARE DEAD!");

			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), characterFromID("maroon1"));
			
			if(CheckCharacterItem(characterFromID("Jupiter"),"clubmusketoon"))
			{
				RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("Jupiter"), "clubmusketoon");
				GiveItem2Character(characterFromID("Jupiter"), "pistolmtoon");
				EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");
				EquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon");
			}
		
			if(LAi_IsFightMode(characterFromID("Edgar Allan Poe")))
			{
				LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
				LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			}
		
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "revolver");
			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), GUN_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Edgar Allan Poe"), "pistol204_P");

			LAi_QuestDelay("reset_silent_seashore", 1.0);
			LAi_QuestDelay("maroons_defeated", 2.0);
		break;

		case "reset_silent_seashore":
			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "silent_seashore";
			PostEvent("LoadSceneSound", 0);	
		break;

		case "maroons_defeated":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "maroons_defeated";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "Hero_my_cousin":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			
			LAi_QuestDelay("Hero_my_cousin1", 1.0);
		break;

		case "Hero_my_cousin1":
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), characterFromID("Jupiter"));

			LAi_QuestDelay("Hero_my_cousin2", 2.0);
		break;

		case "Hero_my_cousin2":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Hero_my_cousin2";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Hero_my_cousin3":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

			LAi_QuestDelay("Hero_my_cousin4", 2.0);
		break;

		case "Hero_my_cousin4":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "Hero_my_cousin4";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "Hero_my_cousin5":
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("poe_ooh", 0.1);
			LAi_QuestDelay("maroons_attack2", 1.0);
		break;

		case "maroons_attack2":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
			ChangeCharacterAddressGroup(characterFromID("white_trash2"), "Legrands_boathouse", "quest", "quest1");
			ChangeCharacterAddressGroup(characterFromID("maroon4"), "Legrands_boathouse", "quest", "quest2");
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "Legrands_boathouse", "quest", "quest3");

			LAi_SetSitType(characterFromID("mystery_monk"));

			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToLocator(Pchar, "quest", "quest3");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "quest", "quest3");
			LAi_ActorTurnToLocator(characterFromID("Edgar Allan Poe"), "quest", "quest3");

			LAi_QuestDelay("maroons_attack3", 1.2);
		break;
	
		case "maroons_attack3":
			PlaySound("PEOPLE\jump.wav");
			
			LAi_QuestDelay("maroons_attack4", 0.5);
		break;

		case "maroons_attack4":
			PlaySound("VOICE\ENGLISH\mystery_monk.wav");
			LAi_SetActorType(characterFromID("mystery_monk"));
			LAi_group_MoveCharacter(characterFromID("mystery_monk"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("maroon4"), "MAROONS");
			LAi_group_MoveCharacter(characterFromID("white_trash2"), "MAROONS");

			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			LAi_SetOfficerType(characterFromID("Jupiter"));

			LAi_QuestDelay("maroons_attack5", 1.5);
		break;

		case "maroons_attack5":
			PlaySound("OBJECTS\ABORDAGE\abordage_wining.wav");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "MAROONS", true);
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(Pchar, true);

			LAi_QuestDelay("maroons_attack6", 2.0);
			LAi_QuestDelay("maroons_attack7", 3.0);
			LAi_QuestDelay("maroons_attack8", 4.0);
		break;
	//--------------------------------------------------------------------------------------------
		case "maroons_attack6":	
			CreateParticleSystemX("ball_splash", 15.7, 0.0, 0.2, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
			ChangeCharacterAddressGroup(characterFromID("maroon_girl"), "Legrands_boathouse", "goto", "box1");
			
			LAi_QuestDelay("maroons_attack6_A", 0.5);
		break;

		case "maroons_attack6_A":	
			LAi_SetActorType(characterFromID("maroon_girl"));
			LAi_ActorAttack(CharacterFromID("maroon_girl"), Pchar, "");
			LAi_group_MoveCharacter(characterFromID("maroon_girl"), "MAROONS");
		break;
	//--------------------------------------------------------------------------------------------
		case "maroons_attack7":	
			CreateParticleSystemX("ball_splash", 15.4, -0.4, 1.7, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
			ChangeCharacterAddressGroup(characterFromID("hunter_bandit"), "Legrands_boathouse", "officers", "box5_2");
			
			LAi_QuestDelay("maroons_attack7_A", 0.5);
		break;

		case "maroons_attack7_A":	
			LAi_SetActorType(characterFromID("hunter_bandit"));
			LAi_ActorAttack(CharacterFromID("hunter_bandit"), characterFromID("Jupiter"), "");
			LAi_group_MoveCharacter(characterFromID("hunter_bandit"), "MAROONS");
		break;
	//--------------------------------------------------------------------------------------------
		case "maroons_attack8":	
			CreateParticleSystemX("ball_splash", 17.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
			ChangeCharacterAddressGroup(characterFromID("deserter_us2"), "Legrands_boathouse", "officers", "box5_1");
			
			LAi_QuestDelay("maroons_attack8_A", 0.5);
		break;

		case "maroons_attack8_A":	
			LAi_SetActorType(characterFromID("deserter_us2"));
			LAi_ActorAttack(CharacterFromID("deserter_us2"), characterFromID("Edgar Allan Poe"), "");
			LAi_group_MoveCharacter(characterFromID("deserter_us2"), "MAROONS");

			Pchar.quest.6last_maroons_dead.win_condition.l1 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l1.character = "mystery_monk";
			Pchar.quest.6last_maroons_dead.win_condition.l2 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l2.character = "maroon4";
			Pchar.quest.6last_maroons_dead.win_condition.l3 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l3.character = "white_trash2";
			Pchar.quest.6last_maroons_dead.win_condition.l4 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l4.character = "maroon_girl";
			Pchar.quest.6last_maroons_dead.win_condition.l5 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l5.character = "hunter_bandit";
			Pchar.quest.6last_maroons_dead.win_condition.l6 = "NPC_Death";
			Pchar.quest.6last_maroons_dead.win_condition.l6.character = "deserter_us2";
			Pchar.quest.6last_maroons_dead.win_condition = "6last_maroons_dead";
		break;

		case "6last_maroons_dead":
			//Logit("ALL 6 ARE DEAD!");

			DeleteAttribute(characterFromID("Edgar Allan Poe"), "chr_ai.poison");
			DeleteAttribute(characterFromID("Jupiter"), "chr_ai.poison");

			if(CheckCharacterItem(characterFromID("Jupiter"),"clubmusketoon"))
			{
				RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("Jupiter"), "clubmusketoon");
				GiveItem2Character(characterFromID("Jupiter"), "pistolmtoon");
				EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");
				EquipCharacterByItem(characterFromID("Jupiter"), "pistolmtoon");
			}
		
			if(LAi_IsFightMode(characterFromID("Edgar Allan Poe")))
			{
				LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
				LAi_SetFightMode(characterFromID("Edgar Allan Poe"), false);
			}
		
			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), GUN_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Edgar Allan Poe"), "pistol204_P");

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload2_back", 3.0);
			Locations[FindLocation("Legrands_boathouse")].locators_radius.reload.reload2_back = 3.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "exit_stop", 0.001);
			Locations[FindLocation("Legrands_boathouse")].locators_radius.goto.exit_stop = 0.001;
			Pchar.quest.house_box1 = "open";
			Pchar.quest.backyard = "open";
			Locations[FindLocation("Legrands_backyard")].models.always.locators = "qcexit_l_GB";

			pchar.quest.home_with_treasure.win_condition.l1 = "location";
			pchar.quest.home_with_treasure.win_condition.l1.location = "Legrands_house";
			pchar.quest.home_with_treasure.win_condition = "home_with_treasure";

			LAi_QuestDelay("reset_silent_seashore", 1.0);
			LAi_QuestDelay("maroons_defeated_again", 2.0);
		break;

		case "maroons_defeated_again":
			Locations[FindLocation("Legrands_house")].models.always.locators = "pirh_l_GB_stack";
			Locations[FindLocation("Legrands_house")].locators_radius.box.box1 = 0.001;

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "maroons_defeated_again";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "maroons_defeated_again1":
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Edgar Allan Poe"));
			Locations[FindLocation("Legrands_boathouse")].reload.l3.go = "Legrands_house";
			Locations[FindLocation("Legrands_boathouse")].reload.l3.emerge = "Reload1";
			Locations[FindLocation("Legrands_house")].reload.l1.disable = 1;	//to jungle
			Pchar.quest.go_to_attic = "phase1";
			Locations[FindLocation("Legrands_house")].reload.l3.disable = 1;	//to grot
			Locations[FindLocation("Legrands_house")].reload.l2.disable = 1;	//to kitchen
			Locations[FindLocation("Legrands_attic")].models.always.locators = "Hut_attic_locators_treasure";
			Locations[FindLocation("Legrands_attic")].locators_radius.randitem.randitem2 = 0.001;
			Locations[FindLocation("Legrands_attic")].locators_radius.randitem.randitem3 = 0.001;
			Locations[FindLocation("Legrands_attic")].locators_radius.box.box3 = 0.001;
			Locations[FindLocation("Legrands_attic")].locators_radius.box.box2 = 0.001;
			
			SetCurrentTime(20.00, 0);

			LAi_QuestDelay("poe_go_on", 1.0);
		break;
//JRH chests
		case "home_with_treasure":
			LAi_SetStayType(Pchar);
			SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe", "man", "man", 1.8, true);
			SetModel(characterFromID("Jupiter"), "Jupiter", "man", "man", 1.8, true);
			PlaySound("INTERFACE\closed_door.wav");


			Pchar.quest.house_box2 = "unlocked";			//weaponslocker
			locations[FindLocation(Pchar.location)].box2.items.pistolmtoon = 0;		//reset if jumpstart
			locations[FindLocation(Pchar.location)].box2.items.machete = 0;			//reset if jumpstart

			locations[FindLocation(Pchar.location)].box2.items.pistolmtoon = 2;		//Jup's + Legrand's

			//WEAPONSLOCKER
			if(CheckCharacterItem(Pchar,"barmansknife")) 		locations[FindLocation(Pchar.location)].box2.items.barmansknife = 1;
			if(CheckCharacterItem(Pchar,"bladeclub")) 		locations[FindLocation(Pchar.location)].box2.items.bladeclub = 1;
			if(CheckCharacterItem(Pchar,"guestsknife")) 		locations[FindLocation(Pchar.location)].box2.items.guestsknife = 1;
			if(CheckCharacterItem(Pchar,"blade4")) 			locations[FindLocation(Pchar.location)].box2.items.blade4 = 1;
			if(CheckCharacterItem(Pchar,"tomahawk")) 		locations[FindLocation(Pchar.location)].box2.items.tomahawk = 1;
			if(CheckCharacterItem(Pchar,"blade5")) 			locations[FindLocation(Pchar.location)].box2.items.blade5 = 1;

			if(CheckCharacterItem(Pchar,"revolver")) 		locations[FindLocation(Pchar.location)].box2.items.revolver = 1;
			if(CheckCharacterItem(Pchar,"pistolbbuss")) 		locations[FindLocation(Pchar.location)].box2.items.pistolbbuss = 1;
			if(CheckCharacterItem(Pchar,"PiratesPistol")) 		locations[FindLocation(Pchar.location)].box2.items.PiratesPistol = 1;
			if(CheckCharacterItem(Pchar,"PiratesPistol")) 		locations[FindLocation(Pchar.location)].box2.items.PiratesPistol = 1;
			int pda = GetCharacterItem(pchar, "pistoldart");	locations[FindLocation(Pchar.location)].box2.items.pistoldart = pda;
			if(CheckCharacterItem(Pchar,"Arguebuse")) 		locations[FindLocation(Pchar.location)].box2.items.Arguebuse = 1;
			if(CheckCharacterItem(Pchar,"pistolbow")) 		locations[FindLocation(Pchar.location)].box2.items.pistolbow = 1;

			int ca = GetCharacterItem(pchar, "cartridges");		locations[FindLocation(Pchar.location)].box2.items.cartridges = ca;	
			gp = GetCharacterItem(pchar, "gunpowder");		locations[FindLocation(Pchar.location)].box2.items.gunpowder = gp;
			pg = GetCharacterItem(pchar, "pistolgrapes");		locations[FindLocation(Pchar.location)].box2.items.pistolgrapes = pg;
			mb = GetCharacterItem(pchar, "musketbullets");		locations[FindLocation(Pchar.location)].box2.items.musketbullets = mb;
			pb = GetCharacterItem(pchar, "pistolbullets");		locations[FindLocation(Pchar.location)].box2.items.pistolbullets = pb;
			int ar = GetCharacterItem(pchar, "bladearrows");	locations[FindLocation(Pchar.location)].box2.items.bladearrows = ar;
			int ar2 = GetCharacterItem(pchar, "arrows2");		locations[FindLocation(Pchar.location)].box2.items.arrows2 = ar2;
			
			//3 CHESTS
			if(CheckCharacterItem(Pchar,"bladespade")) 		locations[FindLocation(Pchar.location)].box1.items.bladespade = 1;
										locations[FindLocation(Pchar.location)].box1.items.bladepickaxe2 = 1;
			if(CheckCharacterItem(Pchar,"bladerammer")) 		locations[FindLocation(Pchar.location)].box1.items.bladerammer = 1;
			if(CheckCharacterItem(Pchar,"bladeplank2")) 		locations[FindLocation(Pchar.location)].box1.items.bladeplank2 = 1;
			if(CheckCharacterItem(Pchar,"bladeanchor")) 		locations[FindLocation(Pchar.location)].box1.items.bladeanchor = 1;			
			if(CheckCharacterItem(Pchar,"machete")) 		locations[FindLocation(Pchar.location)].box1.items.machete = 1;
			if(CheckCharacterItem(Pchar,"bladeaxe3")) 		locations[FindLocation(Pchar.location)].box1.items.bladeaxe3 = 1;
			if(CheckCharacterItem(Pchar,"bladeirontool")) 		locations[FindLocation(Pchar.location)].box1.items.bladeirontool = 1;
			na = GetCharacterItem(characterFromID("Jupiter"), "nails"); locations[FindLocation(Pchar.location)].box1.items.nails = na;
			
			//PREPARE FOR ATTIC CHEST
			if(CheckCharacterItem(Pchar,"spyglass1")) 		Pchar.quest.spyglass1 = "1";
			if(CheckCharacterItem(Pchar,"opium")) 			Pchar.quest.opium = "1";
			if(CheckCharacterItem(Pchar,"2winebottles")) 		Pchar.quest.2winebottles = "1";
			int tbc = GetCharacterItem(Pchar, "tobacco");		if(tbc == 1) Pchar.quest.tobacco = "1";
										if(tbc == 2) Pchar.quest.tobacco = "2";
			if(CheckCharacterItem(Pchar,"medical2")) 		Pchar.quest.medical2 = "1";
			if(CheckCharacterItem(Pchar,"jewelry15")) 		Pchar.quest.jewelry15 = "1";
			if(CheckCharacterItem(Pchar,"potionrum")) 		Pchar.quest.potionrum = "1";

			if(CheckCharacterItem(Pchar,"indian1")) 		Pchar.quest.indian1 = "1";
			if(CheckCharacterItem(Pchar,"animists_amulet")) 	Pchar.quest.animists_amulet = "1";
			if(CheckCharacterItem(Pchar,"book_exorcist")) 		Pchar.quest.book_exorcist = "1";
			if(CheckCharacterItem(Pchar,"bladeskull1")) 		Pchar.quest.bladeskull1 = "1";

		
			LAi_QuestDelay("home_with_treasure1", 1.0);
			LAi_QuestDelay("pchar_puh", 2.5);
			LAi_QuestDelay("last_treasuresack", 3.5);

			pchar.quest.treasure_gone.win_condition.l1 = "locator";
			pchar.quest.treasure_gone.win_condition.l1.location = "Legrands_house";
			pchar.quest.treasure_gone.win_condition.l1.locator_group = "goto";
			pchar.quest.treasure_gone.win_condition.l1.locator = "treasure_gone";
			pchar.quest.treasure_gone.win_condition = "treasure_gone";
		break;

		case "home_with_treasure1":
			PlaySound("INTERFACE\key_lock.wav");
		break;

		case "last_treasuresack":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "last_treasuresack";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "last_treasuresack1":
			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			SetModel(characterFromID("Jupiter"), "Jupiter_sack", "man", "man", 1.8, true);
			PlaySound("PEOPLE\clothes1.wav");
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "goto1", "last_treasuresack2", 3.0);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem2");
		break;	

		case "last_treasuresack2":
			SetModel(characterFromID("Jupiter"), "Jupiter", "man", "man", 1.8, true);
			PlaySound("INTERFACE\coins8.wav");
			PlaySound("PEOPLE\clothes1.wav");
			
			LAi_QuestDelay("good_night", 2.0);
		break;	

		case "good_night":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "good_night";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "good_night1":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "good_night1";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "good_night2":
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorGoToLocator(characterFromID("Edgar Allan Poe"), "goto", "goto2", "good_night3", 2.0);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "randitem", "randitem2");
		break;

		case "good_night3":
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Legrands_house", "sit", "sit1");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
	
			LAi_QuestDelay("good_night3A", 0.5);
			LAi_QuestDelay("good_night4", 1.0);
		break;

		case "good_night3A":
			PlaySound("PEOPLE\creak2.wav");
		break;
		
		case "good_night4":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "good_night4";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "good_night5":
			SetCurrentTime(7.00, 0);
			Locations[FindLocation("Legrands_house")].models.always.locators = "pirh_l_GB";
			Locations[FindLocation("Legrands_house")].image = "";

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");
			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");

			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), GUN_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Edgar Allan Poe"), BLADE_ITEM_TYPE);
			DeleteAttribute(characterFromID("Edgar Allan Poe"), "items");

			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
			DeleteAttribute(characterFromID("Jupiter"), "items");

			DoQuestReloadToLocation("Legrands_house", "sit", "wake_up", "good_morning");
		break;

		case "good_morning":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			SetCurrentTime(7.00, 0);
			LAi_SetSitType(pchar);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.7);
			Locations[FindLocation("Legrands_house")].locators_radius.box.box1 = 0.7;
			
			LAi_QuestDelay("good_morning1", 2.0);
		break;

		case "good_morning1":
			SetCurrentTime(10.00, 0);
			Locations[FindLocation("Legrands_house")].image = "GB_Legrands_hut_inside.tga";
			ChangeCharacterAddressGroup(Pchar, "Legrands_house", "goto", "staybed");
			LAi_SetPlayerType(Pchar);
		break;

		case "treasure_gone":
			PauseAllSounds();
			PlaySound("VOICE\ENGLISH\blaze_scream.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload3");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));

			LAi_QuestDelay("treasure_gone1", 2.0);

			pchar.quest.attic_treasure.win_condition.l1 = "location";
			pchar.quest.attic_treasure.win_condition.l1.location = "Legrands_attic";
			pchar.quest.attic_treasure.win_condition = "attic_treasure";
		break;

		case "treasure_gone1":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto3", "treasure_gone2", 4.0);
		break;

		case "treasure_gone2":
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "treasure_gone2";
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorTurnToCharacter(characterFromID("Edgar Allan Poe"), PChar);
			LAi_ActorDialogNow(characterFromID("Edgar Allan Poe"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Edgar Allan Poe"));
		break;

		case "treasure_gone6":
			PostEvent("LoadSceneSound", 0);
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Legrands_house", "sit", "sit1");
			LAi_SetSitType(characterFromID("Edgar Allan Poe"));
			PlaySound("PEOPLE\creak2.wav");
			
			Pchar.quest.items_transfer = "no";
		break;

		case "attic_treasure":
			Pchar.quest.attic_box1 = "temp_blocked";

			if(CheckAttribute(Pchar, "quest.spyglass1") && Pchar.quest.spyglass1 == "1") 	locations[FindLocation(Pchar.location)].box5.items.spyglass1 = 1;
			if(CheckAttribute(Pchar, "quest.opium") && Pchar.quest.opium == "1")        	locations[FindLocation(Pchar.location)].box5.items.opium = 1;
			if(CheckAttribute(Pchar, "quest.2winebottles") && Pchar.quest.2winebottles == "1") locations[FindLocation(Pchar.location)].box5.items.2winebottles = 1;
			if(CheckAttribute(Pchar, "quest.tobacco") && Pchar.quest.tobacco == "1")        locations[FindLocation(Pchar.location)].box5.items.tobacco = 1;
			if(CheckAttribute(Pchar, "quest.tobacco") && Pchar.quest.tobacco == "2")        locations[FindLocation(Pchar.location)].box5.items.tobacco = 2;
			if(CheckAttribute(Pchar, "quest.medical2") && Pchar.quest.medical2 == "1") 	locations[FindLocation(Pchar.location)].box5.items.medical2 = 1;
			if(CheckAttribute(Pchar, "quest.jewelry15") && Pchar.quest.jewelry15 == "1")    locations[FindLocation(Pchar.location)].box5.items.jewelry15 = 1;
			if(CheckAttribute(Pchar, "quest.potionrum") && Pchar.quest.potionrum == "1") 	locations[FindLocation(Pchar.location)].box5.items.potionrum = 1;
			if(CheckAttribute(Pchar, "quest.indian1") && Pchar.quest.indian1 == "1")        locations[FindLocation(Pchar.location)].box5.items.indian1 = 1;
			if(CheckAttribute(Pchar, "quest.animists_amulet") && Pchar.quest.animists_amulet == "1") locations[FindLocation(Pchar.location)].box5.items.animists_amulet = 1;
			if(CheckAttribute(Pchar, "quest.book_exorcist") && Pchar.quest.book_exorcist == "1") locations[FindLocation(Pchar.location)].box5.items.book_exorcist = 1;
			if(CheckAttribute(Pchar, "quest.bladeskull1") && Pchar.quest.bladeskull1 == "1") locations[FindLocation(Pchar.location)].box5.items.bladeskull1 = 1;

			LAi_QuestDelay("pchar_staytype", 0.5);
			LAi_QuestDelay("attic_treasure1", 2.0);
		break;

		case "attic_treasure1":
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "attic_treasure";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "attic_treasure2":
			pchar.quest.Poe_papers.win_condition.l1 = "location";
			pchar.quest.Poe_papers.win_condition.l1.location = "Legrands_house";
			pchar.quest.Poe_papers.win_condition = "Poe_papers";

			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "box", "box6", "attic_treasure3", 2.0);
		break;

		case "attic_treasure3":
			ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box6");
			LAi_SetStayType(Pchar);

			PauseAllSounds();
			Locations[FindLocation(Pchar.location)].type = "blue_cavern";
			PostEvent("LoadSceneSound", 0);

			locations[FindLocation("Legrands_house")].type = "silent_loghouse";
			Locations[FindLocation("Legrands_house")].models.always.locators = "pirh_l_GB_papers";
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Legrands_house", "goto", "goto3");
			LAi_SetStayType(characterFromID("Jupiter"));
			LAi_SetActorType(characterFromID("Edgar Allan Poe"));
			LAi_ActorSetLayMode(characterFromID("Edgar Allan Poe"));

			Pchar.quest.backyard = "closed";
		break;

		case "Poe_papers":
			PlaySound("INTERFACE\closed_locked_door.wav");
			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "poe_tired";

			LAi_QuestDelay("poe_manuscript_check", 0.1);
			LAi_QuestDelay("Poe_sleeps", 5.0);
		break;

		case "Poe_sleeps":
			if(CheckAttribute(Pchar, "stop_snoring") && Pchar.stop_snoring == "yes") return;

			PlaySound("PEOPLE\snoring.wav");

			LAi_QuestDelay("Poe_sleeps", 3.5);
		break;

		case "poe_manuscript_check":
			if(CheckCharacterItem(Pchar,"poe_manuscript"))
			{
				PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
				InterfaceStack.SelectMenu_node = "I_ITEMS";
				interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
				EndCancelInterface(false);
			}
			else LAi_QuestDelay("poe_manuscript_check", 0.5);//loop check
		break;

		case "skeletons_talk":
			Pchar.stop_snoring = "yes";

			Characters[GetCharacterIndex("Jupiter")].dialog.CurrentNode  = "skeletons_talk";
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), PChar);
			LAi_ActorDialogNow(characterFromID("Jupiter"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Jupiter"));
		break;

		case "skeletons_talk1":
			LAi_SetStayType(Pchar);

			LAi_QuestDelay("skeletons_talk2", 2.0);
		break;

		case "skeletons_talk2":
			LAi_SetActorType(Pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "skeletons_talk2";
			LAi_ActorSelfDialog(pchar, "");
		break;
	
		case "skeletons_talk_end":
			GameOverOrg("boarding");
		break;

	//----------------------------------------------------------------------------------------------------------------
		case "move_to_attic_box7":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box7");
		break;

		case "move_to_attic_box8":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box8");
		break;

		case "move_to_attic_box9":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box9");
		break;

		case "move_to_attic_box10":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box10");
		break;

		case "move_to_attic_box11":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box11");
		break;

		case "move_to_attic_box12":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box12");
		break;

		case "move_to_attic_box13":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "box", "box13");
		break;
	
		case "move_to_attic_box14":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "goto", "box14");
		break;

		case "move_to_attic_box5":
			PlaySound("PEOPLE\run_wood.wav"); ChangeCharacterAddressGroup(Pchar, "Legrands_attic", "goto", "box5");
		break;
//-----------------------------------------------------------------------------------------------------------------------------

//Captain Kidd, storyteller

		case "Kidd_storyteller":
			PlaySound("PEOPLE\creak2.wav");			
			LAi_SetStayType(Pchar);
			LAi_SetActorType(characterFromID("Captain Kidd"));
			LAi_ActorTurnToCharacter(characterFromID("Captain Kidd"), PChar);

			LAi_QuestDelay("Kidd_storyteller1", 1.5);	
		break;

		case "Kidd_storyteller1":
			LAi_SetStayType(characterFromID("Captain Kidd"));
			LAi_SetPlayerType(Pchar);
			PlaySound("AMBIENT\CRYPT\daemon1.wav");
			PlaySound("AMBIENT\CRYPT\daemon1.wav");
			PlaySound("AMBIENT\CRYPT\daemon1.wav");
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	

			Pchar.quest.Kidd_storyteller2.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Kidd_storyteller2.win_condition.l1.location = "Kidds_cabin";
			Pchar.quest.Kidd_storyteller2.win_condition = "Kidd_storyteller2";
		break;

		case "Kidd_storyteller2":
			pchar.quest.Kidd_storyteller.win_condition.l1 = "locator";
			pchar.quest.Kidd_storyteller.win_condition.l1.location = "Kidds_cabin";
			pchar.quest.Kidd_storyteller.win_condition.l1.locator_group = "goto";
			pchar.quest.Kidd_storyteller.win_condition.l1.locator = "Kidd";
			pchar.quest.Kidd_storyteller.win_condition = "Kidd_storyteller";
		break;

	//------------------------------------------------------------------------------------------

		//from Kidd dialog
		case "Teach_head_teleport":
			PlaySound("OBJECTS\DUEL\pistol_big2.wav");

			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("blast_smoke" , u, v+1, w, 5.1, 4.0, 0.0, sti(20) );		//smoke
			CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );		//short fore flash
			CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );		//short fore flash

			SetModel(PChar, "William Legrand_hat", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

			LAi_QuestDelay("Kidd_reset_head", 0.5);
			LAi_QuestDelay("Teach_head_teleport2", 1.5);
		break;

		case "Kidd_reset_head":
			SetModel(PChar, "William Legrand", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
		break;
	
		case "Teach_head_teleport2":
			if(CheckAttribute(Pchar,"quest.Teach_head"))
			{
				switch(Pchar.quest.Teach_head)
				{
					case "1":
						DoQuestReloadToLocation("Sullivan_jungle1", "reload", "reload2" ,"Teach_head_1");		
					break;

					case "2":
						DoQuestReloadToLocation("Legrands_house", "goto", "goto10", "day2_start");
						LAi_QuestDelay("Teach_head_2", 1.0);
					break;

					case "3":
						DoQuestReloadToLocation("Legrands_grot", "reload", "reload1" ,"Jup_to_moultrie_done");
						LAi_QuestDelay("Teach_head_3", 1.0);
					break;
				
					case "4":
						RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
						TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

						DoQuestReloadToLocation("Fort_Moultrie", "reload", "reload1" ,"open_village_full_jumpstart4");
						LAi_QuestDelay("Teach_head_4", 0.01);
					break;
				
					case "5":
						DoQuestReloadToLocation("GB_Charleston_port", "reload", "reload2" ,"Teach_head_5");	
					break;

					case "6":
						DoQuestReloadToLocation("GB_Chinatown", "reload", "reload1" ,"Teach_head_6");
					break;

					case "7":
						RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
						TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						DoQuestReloadToLocation("GB_Chinese_restaurant", "reload", "reload2" ,"Teach_head_7");	
					break;

					case "8":
						RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
						DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1" ,"Teach_head_8");
					break;

					case "9":
						DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1" ,"Teach_head_9");
					break;

					case "10":
						RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
						TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						DoQuestReloadToLocation("Bishops_Hostel", "box", "box1" ,"Teach_head_10");
					break;

					case "11":
						DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1" ,"Teach_head_11");	
					break;

					case "12":
						DoQuestReloadToLocation("GB_Charleston_town", "reload", "reload2" ,"Teach_head_12");
					break;

					case "13":
						DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1" ,"Teach_head_13");
					break;

					case "14":
						RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
						TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						DoQuestReloadToLocation("Fort_Moultrie_exit", "reload", "reload3" ,"Teach_head_14");		
					break;

					case "15":
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						DoQuestReloadToLocation("Poe_bedroom", "goto", "goto1", "Teach_head_15");
					break;

					case "16":
						for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
						RemovePassenger(Pchar, characterFromID("Jupiter"));
						DoQuestReloadToLocation("Bessop_plantation", "reload", "reload1" ,"Teach_head_16");		
					break;
				}
			}				
		break;
	//....................................................................................................

		case "Teach_head_1":
			//LEGRANDS HOUSE after shores

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			AddMoneyToCharacter(Pchar,-2000);
			TakeItemFromCharacter(Pchar, "map");
			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladecrypto_d");
			EquipCharacterbyItem(Pchar, "bladecrypto_d");
			GiveItem2Character(Pchar, "pistolmtoon");
			EquipCharacterbyItem(Pchar, "pistolmtoon");
			GiveItem2Character(Pchar, "shell_collection");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");

			SetQuestHeader("Searching_the_shores");
			AddQuestRecord("Searching_the_shores", "1");
			AddQuestRecord("Searching_the_shores", "2");
			AddQuestRecord("Searching_the_shores", "6");
			AddQuestRecord("Searching_the_shores", "3");
			AddQuestRecord("Searching_the_shores", "4");
			AddQuestRecord("Searching_the_shores", "5");
			CloseQuestHeader("Searching_the_shores");
			SetQuestHeader("The_parchment");
			AddQuestRecord("The_parchment", "1");

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;

		case "Teach_head_2":
			//LEGRANDS HOUSE day2

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladecrypto_cl");
			EquipCharacterbyItem(Pchar, "bladecrypto_cl");
			GiveItem2Character(Pchar, "pistoltinderbox");
			EquipCharacterbyItem(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
		
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");

			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items", "1"); AddQuestRecord("Useful_items", "2"); AddQuestRecord("Useful_items", "3");
			DeleteQuestHeader("Searching_the_shores");
			SetQuestHeader("The_parchment");
			AddQuestRecord("The_parchment", "1"); AddQuestRecord("The_parchment", "2"); AddQuestRecord("The_parchment", "3");
			AddQuestRecord("The_parchment", "4"); AddQuestRecord("The_parchment", "5"); AddQuestRecord("The_parchment", "6");
			AddQuestRecord("The_parchment", "7");

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;

		case "Teach_head_3":
			//JUPITERS PAPER MISSION

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4")
			GiveItem2Character(Pchar, "bladecrypto_cl");
			EquipCharacterbyItem(Pchar, "bladecrypto_cl");
			GiveItem2Character(Pchar, "pistoltinderbox");
			EquipCharacterbyItem(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			
			LAi_SetStayType(characterFromID("Jupiter"));

			DeleteQuestHeader("Searching_the_shores");
				

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 4
		case "Teach_head_4":
			//FORT

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4")
			GiveItem2Character(Pchar, "bladecrypto_cl");
			EquipCharacterbyItem(Pchar, "bladecrypto_cl");
			GiveItem2Character(Pchar, "pistoltinderbox");
			EquipCharacterbyItem(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto1");
			

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
		
			DeleteQuestHeader("Searching_the_shores");

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 5
		case "Teach_head_5":
			//CHARLESTON

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4")
			GiveItem2Character(Pchar, "bladecrypto_cl");
			EquipCharacterbyItem(Pchar, "bladecrypto_cl");
			GiveItem2Character(Pchar, "pistoltinderbox");
			EquipCharacterbyItem(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto1");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");
			

			AddQuestRecord("The_message","1"); AddQuestRecord("The_message","2"); AddQuestRecord("The_message","6");
			AddQuestRecord("The_message","5"); AddQuestRecord("The_message","8"); AddQuestRecord("The_message","3");
			AddQuestRecord("The_message","4"); AddQuestRecord("The_message","7");
			DeleteQuestHeader("Searching_the_shores");



			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 6
		case "Teach_head_6":
			//CHINATOWN

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");

			DeleteQuestHeader("Searching_the_shores");

			LAi_QuestDelay("how_to_enter_plantation_done", 0.1);//here are all start values for Chinatown




		

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 7
		case "Teach_head_7":
			//CHINAROOM

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");

			DeleteQuestHeader("Searching_the_shores");

			LAi_QuestDelay("GP_fireworks_done", 0.1);


		

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 8
		case "Teach_head_8":
			//PLANTATION

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistolFWchest");			
			EquipCharacterbyItem(Pchar, "pistolFWchest");

			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");

			AddQuestRecord("Fireworks","1");
			AddQuestRecord("Fireworks","2");
			AddQuestRecord("Fireworks","3");
			AddQuestRecord("Fireworks","4");
			AddQuestRecord("Fireworks","5");
			CloseQuestHeader("Fireworks");
			DeleteQuestHeader("Searching_the_shores");
		
			



			
			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 9
		case "Teach_head_9":
			//MAROONS ETC

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "BH_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");
		
			DeleteQuestHeader("Searching_the_shores");
			DeleteQuestHeader("Fireworks");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","1");
			AddQuestRecord("Bishop's_Hostel","2");
			AddQuestRecord("Bishop's_Hostel","3");
			AddQuestRecord("Bishop's_Hostel","4");


			LAi_QuestDelay("start_maroon_part", 0.1);
		


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 10
		case "Teach_head_10":
			//BISHOP'S HOSTEL, FIRST TIME  	

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			SetModel(Pchar, "William Legrand3", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);	
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "bars_back");
			LAi_SetStayType(characterFromID("Jupiter"));

			GiveItem2Character(Pchar, "bladeX4");
			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "BH_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");

			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","1");
			AddQuestRecord("Bishop's_Hostel","2");
			AddQuestRecord("Bishop's_Hostel","3");
			AddQuestRecord("Bishop's_Hostel","4");




			DeleteQuestHeader("Searching_the_shores");


		


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 11
		case "Teach_head_11":
			//SPYGLASS TOUR + PYM TOUR

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			TakeNItems(Pchar,"gunpowder", 6);
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "BH_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");			//given to Jup but check if Legrand gets it when switched
		
			AddQuestRecord("Navigation_items","1");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","1");
			AddQuestRecord("Bishop's_Hostel","2");
			AddQuestRecord("Bishop's_Hostel","3");
			AddQuestRecord("Bishop's_Hostel","4");
			AddQuestRecord("Bishop's_Hostel","5");
			AddQuestRecord("Bishop's_Hostel","6");

			LAi_QuestDelay("maroon_stop4", 0.1);	//starter of action this phase





			DeleteQuestHeader("Searching_the_shores");

		


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 12
		case "Teach_head_12":
			//BISHOP'S HOSTEL, SECOND TIME

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladespyglass6");
			EquipCharacterbyItem(Pchar, "bladespyglass6");
			GiveItem2Character(Pchar, "pistolsextant2");
			EquipCharacterbyItem(Pchar, "pistolsextant2");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");

			GiveItem2Character(Pchar, "potion3");
			GiveItem2Character(Pchar, "potionrum");
			
			DeleteQuestHeader("Searching_the_shores");
			AddQuestRecord("Bishop's_Hostel","1");
			AddQuestRecord("Bishop's_Hostel","2");
			AddQuestRecord("Bishop's_Hostel","3");
			AddQuestRecord("Bishop's_Hostel","4");
			AddQuestRecord("Bishop's_Hostel","5");

			LAi_QuestDelay("meeting_at_Poes19", 0.1);			//action starts here

			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;

			pchar.quest.Bessop_gate_alarm.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_alarm.win_condition = "Bessop_gate_alarm";


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 13
		case "Teach_head_13":
			//POE'S + JUP BOAT, HUT

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladespyglass6");
			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			GiveItem2Character(Pchar, "pistolsextant2");
			EquipCharacterbyItem(Pchar, "pistolsextant2");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");
			
			GiveItem2Character(Pchar, "potion3");
			GiveItem2Character(Pchar, "potionrum");

			SetModel(Pchar, "William Legrand3", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);	
			DeleteQuestHeader("Searching_the_shores");
			AddQuestRecord("Bishop's_Hostel","9");

			LAi_QuestDelay("last_meeting_at_Poes", 0.1);			//action starts here

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 14
		case "Teach_head_14":
			//FORT REVOLVER	
			//logit("q_r 14");

			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	

			Pchar.quest.Jupiter_tobacco = "2";
			Pchar.quest.Jupiter_jewelry12 = "yes";
			Pchar.quest.Jupiter_coin7 = "yes";
			Pchar.quest.Jupiter_gunpowder = "6";
			Pchar.Lut_G_cipher = "done";

			Pchar.quest.Fort_M_flag_pos = "up";
			Locations[FindLocation("Fort_Moultrie")].models.always.locators = "fort2_locators_GB3";	
			Locations[FindLocation("Maroon_cavern")].environment.weather = "false";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "false";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_dry";
			Locations[FindLocation("Maroon_cavern")].models.always.l4 = "";		
			Locations[FindLocation("Maroon_cavern")].models.always.l5 = "barrelC";		
			Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";			
			Locations[FindLocation("Maroon_cavern")].models.always.l7 = "bottleC_cork";
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_rope";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;
			Locations[FindLocation("Bishops_Hostel")].models.always.locators = "locator_BH2";	//tree + boat + raft

			Locations[FindLocation("GB_Charleston_town")].reload.l13.disable = 1;//lock to tailor, easiest
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Pchar.quest.mar_cav_from_plant = "open"
			Pchar.quest.mar_cav_to_bridge = "closed";
			Pchar.quest.mar_cav_to_hideout = "open";
			Pchar.quest.hideout.box10 = "locked";
			Pchar.quest.trader_Pym_hint = "yes";

			LAi_QuestDelay("fort_open", 0.1);
	
		Pchar.quest.devils_seat_found = "yes";
		Pchar.quest.Jupiter_equip = "case1";
		Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
		Pchar.quest.Ch_town_box6 = "locked";		//brothel
		Pchar.quest.town_exit_closed = "no";
		Pchar.quest.boathouse = "return";
	
			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("deserter_us1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("white_trash1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("mystery_monk"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("GB_storeowner"), "GB_Charleston_store", "barmen", "stay");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("landlady"), "Poe_entre", "goto", "goto3");
			LAi_SetStayType(characterFromID("landlady"));
			SetModel(characterFromID("landlady"), "landlady_private", "woman", "woman", 1.8, true);
			GiveItem2Character(characterFromID("landlady"), "bladeX4");
			EquipCharacterbyItem(characterFromID("landlady"), "bladeX4");
			GiveItem2Character(characterFromID("landlady"), "pistolwhip");
			EquipCharacterbyItem(characterFromID("landlady"), "pistolwhip");

			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist5"), "Moultrie_restaurant", "sit", "sit7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist7"), "Moultrie_restaurant", "sit", "sit5");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist9"), "Moultrie_restaurant", "sit", "sit8");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist10"), "Moultrie_restaurant", "sit", "sit23");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist11"), "Moultrie_restaurant", "sit", "sit21");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist6"), "Fort_Moultrie_village", "reload", "reload7");
			ChangeCharacterAddressGroup(characterFromID("Moultrie_tourist8"), "Moultrie_finehouse", "goto", "locator1");
			
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload9 = 1.5;
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box4 = 0.001;
			Locations[FindLocation("GB_Chinatown")].reload.l9.disable = 1;
			Locations[FindLocation("Maroon_Hideout")].models.always.locators = "Cave_Ship_l_GB_open";
			Locations[FindLocation("Maroon_Hideout")].locators_radius.goto.steplock = 0.5;
			Characters[GetCharacterIndex("Charleston_guard1")].Ship.Type = "obj_raft3";	//in hideout
			locations[FindLocation("Poe_bedroom")].models.always.locators = "largehouse02_locators_GB_open";	//open now to landlady downstairs
			Locations[FindLocation("Legrands_house")].reload.l3.disable = 0;		//grot	
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2";
			locations[FindLocation("Fort_Moultrie_village")].type = "Fort_Moultrie_village";//music
			locations[FindLocation("Moultrie_hotel")].id.label = "Fort Moultrie hotel";
			locations[FindLocation("Moultrie_restaurant")].id.label = "Fort Moultrie restaurant";
			locations[FindLocation("Moultrie_store")].id.label = "Fort Moultrie store";
			Locations[FindLocation("Fort_Moultrie_village")].models.always.locators = "sml_l_GB_open_smoke2";
			Locations[FindLocation("Fort_Moultrie_village")].reload.l2.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l6.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l8.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l10.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l12.disable = 0;
			Locations[FindLocation("Fort_Moultrie_village")].reload.l3.close_for_night = 1;	//gatehouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l4.close_for_night = 1;	//smallhouse
			Locations[FindLocation("Fort_Moultrie_village")].reload.l7.close_for_night = 1;	//largehouse
			Locations[FindLocation("Fort_Moultrie_shore")].models.always.locators = "Shore01_l_GB2";

			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);		
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "Fort_Moultrie_barracks", "sit", "sit13");
			LAi_SetSitType(characterFromID("Lieutenant G"));

			DeleteAttribute(Pchar, "items");
			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladespyglass6");
			GiveItem2Character(Pchar, "bladespade");
			EquipCharacterbyItem(Pchar, "bladespade");
			GiveItem2Character(Pchar, "pistolsextant2");
			EquipCharacterbyItem(Pchar, "pistolsextant2");
			AddMoneyToCharacter(Pchar,-1000);
			TakeItemFromCharacter(Pchar, "map");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "goldbug");

			GiveItem2Character(Pchar, "potion3");
			GiveItem2Character(Pchar, "potionrum");
			
			DeleteQuestHeader("Weapons");
			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("Bishop's_Hostel");
			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items","14");
			SetQuestHeader("Weapons");
			AddQuestRecord("Weapons","1");
			SetQuestHeader("Bishop's_Hostel");
			AddQuestRecord("Bishop's_Hostel","10");
		
			Pchar.quest.Fort_M_south_wall_right = "closed";
			Pchar.locked_cells = "0";

			Pchar.quest.Fort_visit = "3";
			Locations[FindLocation("Fort_Moultrie")].reload.l10.disable = 0;		//barracks
			Locations[FindLocation("Fort_Moultrie")].reload.l3.disable = 1;			//tower1A
			Locations[FindLocation("Fort_M_tower1B")].reload.l8.disable = 0;		//gate wall
			Locations[FindLocation("Fort_M_tower2B")].reload.l4.disable = 0;		//up to 2C
			Locations[FindLocation("Fort_M_tower2B")].reload.l8.disable = 1;		//wall, direction G house
			Locations[FindLocation("Fort_M_tower2C")].reload.l2.emerge = "box14";		//at top

			pchar.quest.Fort_visit3.win_condition.l1 = "locator";
			pchar.quest.Fort_visit3.win_condition.l1.location = "Fort_Moultrie_barracks";
			pchar.quest.Fort_visit3.win_condition.l1.locator_group = "sit";
			pchar.quest.Fort_visit3.win_condition.l1.locator = "sit13";
			pchar.quest.Fort_visit3.win_condition = "Fort_visit3";

			pchar.quest.open_tower1.win_condition.l2 = "locator";
			pchar.quest.open_tower1.win_condition.l2.location = "Fort_M_tower1A";
			pchar.quest.open_tower1.win_condition.l2.locator_group = "reload";
			pchar.quest.open_tower1.win_condition.l2.locator = "reload7";
			pchar.quest.open_tower1.win_condition = "open_tower1";



			LAi_QuestDelay("maroon_cavern_steplock", 0.1);
			LAi_QuestDelay("maroon_hideout_steplock", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);
			LAi_QuestDelay("bridge_broken_B", 0.1);
			LAi_QuestDelay("ch_shore_bars", 0.1);
			LAi_QuestDelay("step_back_store", 0.1);
			
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "closed", 0.001);
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload5", 1.0);
			Locations[FindLocation("Fort_Moultrie_village")].locators_radius.goto.closed = 0.001;
			Locations[FindLocation("Fort_Moultrie_village")].locators_radius.reload.reload5 = 1.0;

			DeleteQuestHeader("Searching_the_shores");

		

	

			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 15
		case "Teach_head_15":
			//POE CHURCH

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			
			Pchar.quest.Legrands_rum = "yes";	
			Pchar.quest.Legrands_antidote = "yes";	
			Pchar.quest.Legrands_cauterization = "yes";

			SetModel(Pchar, "Edgar Allan Poe", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);




			DeleteQuestHeader("Searching_the_shores");

			LAi_QuestDelay("Poe_church_mission", 0.1);


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;
//kidd 16
		case "Teach_head_16":
			//BISHOP'S HOSTEL, LAST TIME

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");

			GiveItem2Character(Pchar, "bladeX4");

			Pchar.quest.Legrands_rum = "yes";	
			Pchar.quest.Legrands_antidote = "yes";	
			Pchar.quest.Legrands_cauterization = "yes";
			
			DeleteQuestHeader("Searching_the_shores");

			LAi_QuestDelay("plantation_switch", 0.1);

			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;

			pchar.quest.Bessop_gate_alarm.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_alarm.win_condition = "Bessop_gate_alarm";

			


			LAi_QuestDelay("Teach_head_all1", 0.01);	
		break;

	//....................................................................................................

		case "Teach_head_all1":
			LAi_SetPlayerType(Pchar);
			PlaySound("PEOPLE\teleport.wav");
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("blast_smoke" , u, v+1, w, 5.1, 4.0, 0.0, sti(20) );
			
			LAi_QuestDelay("Teach_head_all2", 2.0);	
		break;

		case "Teach_head_all2":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Locations[FindLocation("Sullivan_shore3")].reload.l2.disable = 1;	
			//Adventure Galley, just to be sure if pchar returns	
		break;

//kidd end



















//JRH end
//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------
		case "autoequip_bladecrypto":
			if(CheckCharacterItem(Pchar,"bladecrypto_d")) EquipCharacterByItem(Pchar, "bladecrypto_d");
			if(CheckCharacterItem(Pchar,"bladecrypto_dl")) EquipCharacterByItem(Pchar, "bladecrypto_dl");
			if(CheckCharacterItem(Pchar,"bladecrypto_ds")) EquipCharacterByItem(Pchar, "bladecrypto_ds");
			if(CheckCharacterItem(Pchar,"bladecrypto_dsk")) EquipCharacterByItem(Pchar, "bladecrypto_dsk");

			if(CheckCharacterItem(Pchar,"bladecrypto_cl")) EquipCharacterByItem(Pchar, "bladecrypto_cl");
			if(CheckCharacterItem(Pchar,"bladecrypto_csk")) EquipCharacterByItem(Pchar, "bladecrypto_csk");
			if(CheckCharacterItem(Pchar,"bladecrypto_cskp")) EquipCharacterByItem(Pchar, "bladecrypto_cskp");
			if(CheckCharacterItem(Pchar,"bladecrypto_cskt")) EquipCharacterByItem(Pchar, "bladecrypto_cskt");
		break;

		case "switch_to_Jupiter":
			SetModel(PChar, "Jupiter", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");	//just to be sure

			Pchar.name = "Jupiter";
			Pchar.lastname = "";
			Pchar.rank 	= 2;
			Pchar.reputation = "50";
			Pchar.experience = "0";
			Pchar.skill.Leadership = "1";
			Pchar.skill.Fencing = "5";
			Pchar.skill.Sailing = "3";
			Pchar.skill.Accuracy = "1";
			Pchar.skill.Cannons = "1";
			Pchar.skill.Grappling = "1";
			Pchar.skill.Repair = "5";
			Pchar.skill.Defence = "1";
			Pchar.skill.Commerce = "1";
			Pchar.skill.Sneak = "1";

			Pchar.wealth = "0";
			AddLandToCharacter(&Pchar, "Redmond", iNation, -4);

		Pchar.quest.Legrand_gold = sti(Pchar.Money);
			AddMoneyToCharacter(Pchar, -100000);
			AddMoneyToCharacter(Pchar, makeint(Pchar.quest.Jupiter_gold));

			DeleteAttribute(Pchar,"perks.list.BasicCommerce");
			DeleteAttribute(Pchar,"perks.list.BasicLandOwner");
			DeleteAttribute(Pchar,"perks.list.IronWill");
			DeleteAttribute(Pchar,"perks.list.Gunman");
			DeleteAttribute(Pchar,"perks.list.BasicDefence");
			DeleteAttribute(Pchar,"perks.list.GunProfessional");
			DeleteAttribute(Pchar,"perks.list.GunFighter");

			Pchar.perks.list.AdvancedDefence = true;
			Pchar.perks.list.Toughness = true;
			Pchar.perks.list.LightRepair = true;
		
			if(CheckCharacterItem(Pchar,"medical2")) Pchar.quest.Legrands_cauterization = "yes";
			if(CheckCharacterItem(Pchar,"potionrum")) Pchar.quest.Legrands_rum = "yes";	
			if(CheckCharacterItem(Pchar,"potion3")) Pchar.quest.Legrands_antidote = "yes";	
			if(CheckCharacterItem(Pchar,"pistoltinderbox")) Pchar.quest.Legrands_tinderbox = "yes";	
			if(CheckCharacterItem(Pchar,"inkpen")) Pchar.quest.Legrands_inkpen = "yes";
			if(CheckCharacterItem(Pchar,"clock1")) Pchar.quest.Legrands_clock1 = "yes";
			if(CheckCharacterItem(Pchar,"letter_paper")) Pchar.quest.Legrands_letter_paper = "yes";
			if(CheckCharacterItem(Pchar,"goldbug")) Pchar.quest.Legrands_goldbug = "yes";
			
			if(CheckCharacterItem(Pchar,"bladecrypto_d")) Pchar.quest.Legrands_bladecrypto_d = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_dl")) Pchar.quest.Legrands_bladecrypto_dl = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_ds")) Pchar.quest.Legrands_bladecrypto_ds = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_dsk")) Pchar.quest.Legrands_bladecrypto_dsk = "yes";

			if(CheckCharacterItem(Pchar,"bladecrypto_cl")) Pchar.quest.Legrands_bladecrypto_cl = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_csk")) Pchar.quest.Legrands_bladecrypto_csk = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_cskp")) Pchar.quest.Legrands_bladecrypto_cskp = "yes";
			if(CheckCharacterItem(Pchar,"bladecrypto_cskt")) Pchar.quest.Legrands_bladecrypto_cskt = "yes";
	
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");//takes all incl fists
		//_____________________________________________________________________________________________________________


			if(CheckAttribute(Pchar,"quest.Jupiter_tobacco") && Pchar.quest.Jupiter_tobacco == "2")	
			TakenItems(Pchar, "tobacco", 2);

			if(CheckAttribute(Pchar,"quest.Jupiter_tobacco") && Pchar.quest.Jupiter_tobacco == "1")	
			TakenItems(Pchar, "tobacco", 1);

			if(CheckAttribute(Pchar,"quest.Jupiter_indian11") && Pchar.quest.Jupiter_indian11 == "yes")	
			TakenItems(Pchar, "indian11", 1);

			if(CheckAttribute(Pchar,"quest.Jupiter_jewelry12") && Pchar.quest.Jupiter_jewelry12 == "yes")	
			TakenItems(Pchar, "jewelry12", 1);

			if(CheckAttribute(Pchar,"quest.Jupiter_coin7") && Pchar.quest.Jupiter_coin7 == "yes")	
			TakenItems(Pchar, "coin7", 1);

			if(CheckAttribute(Pchar,"quest.Jupiter_wrinkled_paper") && Pchar.quest.Jupiter_wrinkled_paper == "yes")
			TakenItems(Pchar, "wrinkled_paper", 1);

			if(CheckAttribute(Pchar,"quest.Jupiter_gunpowder") && Pchar.quest.Jupiter_gunpowder == "6")	
			TakenItems(Pchar, "gunpowder", 6);

		//......................................................................................................

			EquipCharacterByItem(characterFromID("Legrand_copy"), "bladeX4");

			if(CheckAttribute(Pchar,"quest.Legrands_cauterization") && Pchar.quest.Legrands_cauterization == "yes")
			{
				TakenItems(characterFromID("Legrand_copy"), "medical2", 1);
			}

			if(CheckAttribute(Pchar,"quest.Legrands_rum") && Pchar.quest.Legrands_rum == "yes")
			{
				TakenItems(characterFromID("Legrand_copy"), "potionrum", 1);
			}

			if(CheckAttribute(Pchar,"quest.Legrands_antidote") && Pchar.quest.Legrands_antidote == "yes")
			{
				TakenItems(characterFromID("Legrand_copy"), "potion3", 1);
			}

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cl") && Pchar.quest.Legrands_bladecrypto_cl == "yes")
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "bladecrypto_cl", 1);
				EquipCharacterByItem(characterFromID("Legrand_copy"), "bladecrypto_cl");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_csk") && Pchar.quest.Legrands_bladecrypto_csk == "yes")
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "bladecrypto_csk", 1);
				EquipCharacterByItem(characterFromID("Legrand_copy"), "bladecrypto_csk");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cskp") && Pchar.quest.Legrands_bladecrypto_cskp == "yes")
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "bladecrypto_cskp", 1);
				EquipCharacterByItem(characterFromID("Legrand_copy"), "bladecrypto_cskp");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cskt") && Pchar.quest.Legrands_bladecrypto_cskt == "yes")
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "bladecrypto_cskt", 1);
				EquipCharacterByItem(characterFromID("Legrand_copy"), "bladecrypto_cskt");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_tinderbox") && Pchar.quest.Legrands_tinderbox == "yes")
			{
				RemoveCharacterEquip(characterFromID("Legrand_copy"), GUN_ITEM_TYPE);
				TakenItems(characterFromID("Legrand_copy"), "pistoltinderbox", 1);
				EquipCharacterByItem(characterFromID("Legrand_copy"), "pistoltinderbox");
			}

		//......................................................................................................

			//reset
			Pchar.quest.Jupiter_tobacco = "0";
			Pchar.quest.Jupiter_indian11 = "no";
			Pchar.quest.Jupiter_jewelry12 = "no";
			Pchar.quest.Jupiter_coin7 = "no";

			DeleteQuestHeader("Useful_items");
			DeleteQuestHeader("The_parchment");
			DeleteQuestHeader("Searching_the_shores");
			SetQuestHeader("Jupiters_wood_mission");
			AddQuestRecord("Jupiters_wood_mission","1");			

			if(!CheckCharacterItem(Pchar,"bladeX4")) GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterByItem(Pchar, "bladeX4");

			if(CheckAttribute(Pchar,"quest.Jupiter_switch2") && Pchar.quest.Jupiter_switch2 == "yes")
			{
				SetQuestHeader("Jupiters_Moultrie_mission");
				AddQuestRecord("Jupiters_Moultrie_mission","2"); AddQuestRecord("Jupiters_Moultrie_mission","3");
				DeleteQuestHeader("Jupiters_wood_mission");
			}	

			if(CheckAttribute(Pchar,"quest.Jupiter_switch3") && Pchar.quest.Jupiter_switch3 == "yes")
			{
				DeleteQuestHeader("Jupiters_wood_mission");
				DeleteQuestHeader("Jupiters_Moultrie_mission");
			}
		break;

		case "switch_to_Legrand":
			SetModel(PChar, "William Legrand", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Legrand_copy"));
			RemovePassenger(pchar, characterFromID("Legrand_copy"));
			ChangeCharacterAddressGroup(characterFromID("Legrand_copy"), "none", "", "");	//just to be sure

			Pchar.name = "William";
			Pchar.lastname = "Legrand";
			Pchar.rank = 3;	
			Pchar.skill.Leadership = "5";
			Pchar.skill.Fencing = "2";		
			Pchar.skill.Sailing = "1";
			Pchar.skill.Accuracy = "1";
			Pchar.skill.Cannons = "1";
			Pchar.skill.Grappling = "1";
			Pchar.skill.Repair = "1";
			Pchar.skill.Defence = "1";
			Pchar.skill.Commerce = "3";
			Pchar.skill.Sneak = "5";

			Pchar.wealth = "0";
			AddLandToCharacter(&Pchar, "Redmond", iNation, 4);

		Pchar.quest.Jupiter_gold = sti(Pchar.Money);
			AddMoneyToCharacter(Pchar, -100000);
			AddMoneyToCharacter(Pchar, makeint(Pchar.quest.Legrand_gold));

			DeleteAttribute(Pchar,"perks.list.AdvancedDefence");
			DeleteAttribute(Pchar,"perks.list.Toughness");
			DeleteAttribute(Pchar,"perks.list.LightRepair");

			Pchar.perks.list.BasicCommerce = true;				
			Pchar.perks.list.BasicLandOwner = true;
			Pchar.perks.list.IronWill = true;
			Pchar.perks.list.Gunman = true;
			Pchar.perks.list.BasicDefence = true;
			Pchar.perks.list.GunProfessional = true;
			Pchar.perks.list.GunFighter = true;

			int tobc = GetCharacterItem(Pchar, "tobacco");
			if(tobc == 2) Pchar.quest.Jupiter_tobacco = "2";
			if(tobc == 1) Pchar.quest.Jupiter_tobacco = "1";

			if(CheckCharacterItem(Pchar,"indian11")) Pchar.quest.Jupiter_indian11 = "yes";
			if(CheckCharacterItem(Pchar,"jewelry12")) Pchar.quest.Jupiter_jewelry12 = "yes";			
			if(CheckCharacterItem(Pchar,"coin7")) Pchar.quest.Jupiter_coin7 = "yes";
			if(CheckCharacterItem(Pchar,"wrinkled_paper")) Pchar.quest.Jupiter_wrinkled_paper = "yes";

		RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
		TakenItems(characterFromID("Jupiter"), "pistolmtoon", -1);
	
		//......................................................................................................
			
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"medical2")) Pchar.quest.Legrands_cauterization = "yes";	
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"potionrum")) Pchar.quest.Legrands_rum = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"potion3")) Pchar.quest.Legrands_antidote = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"pistoltinderbox")) Pchar.quest.Legrands_tinderbox = "yes";	
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"inkpen")) Pchar.quest.Legrands_inkpen = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"clock1")) Pchar.quest.Legrands_clock1 = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"letter_paper")) Pchar.quest.Legrands_letter_paper = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"goldbug")) Pchar.quest.Legrands_goldbug = "yes";
			
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_d")) Pchar.quest.Legrands_bladecrypto_d = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_dl")) Pchar.quest.Legrands_bladecrypto_dl = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_ds")) Pchar.quest.Legrands_bladecrypto_ds = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_dsk")) Pchar.quest.Legrands_bladecrypto_dsk = "yes";

			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_cl")) Pchar.quest.Legrands_bladecrypto_cl = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_csk")) Pchar.quest.Legrands_bladecrypto_csk = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_cskp")) Pchar.quest.Legrands_bladecrypto_cskp = "yes";
			if(CheckCharacterItem(characterFromID("Legrand_copy"),"bladecrypto_cskt")) Pchar.quest.Legrands_bladecrypto_cskt = "yes";
		//......................................................................................................	
			
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");//takes all incl fists
		//_____________________________________________________________________________________________________________

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterByItem(Pchar, "bladeX4");

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_d") && Pchar.quest.Legrands_bladecrypto_d == "yes")
			{
				TakenItems(Pchar, "bladecrypto_d", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_d");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_dl") && Pchar.quest.Legrands_bladecrypto_dl == "yes")
			{
				TakenItems(Pchar, "bladecrypto_dl", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_dl");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_ds") && Pchar.quest.Legrands_bladecrypto_ds == "yes")
			{
				TakenItems(Pchar, "bladecrypto_ds", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_ds");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_dsk") && Pchar.quest.Legrands_bladecrypto_dsk == "yes")
			{
				TakenItems(Pchar, "bladecrypto_dsk", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_dsk");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cl") && Pchar.quest.Legrands_bladecrypto_cl == "yes")
			{
				TakenItems(Pchar, "bladecrypto_cl", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_cl");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_csk") && Pchar.quest.Legrands_bladecrypto_csk == "yes")
			{
				TakenItems(Pchar, "bladecrypto_csk", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_csk");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cskp") && Pchar.quest.Legrands_bladecrypto_cskp == "yes")
			{
				TakenItems(Pchar, "bladecrypto_cskp", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_cskp");
			}
			if(CheckAttribute(Pchar,"quest.Legrands_bladecrypto_cskt") && Pchar.quest.Legrands_bladecrypto_cskt == "yes")
			{
				TakenItems(Pchar, "bladecrypto_cskt", 1);
				EquipCharacterByItem(Pchar, "bladecrypto_cskt");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_tinderbox") && Pchar.quest.Legrands_tinderbox == "yes")
			{
				TakenItems(Pchar, "pistoltinderbox", 1);
				EquipCharacterByItem(Pchar, "pistoltinderbox");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_inkpen") && Pchar.quest.Legrands_inkpen == "yes")
			TakenItems(Pchar, "inkpen", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_clock1") && Pchar.quest.Legrands_clock1 == "yes")
			{
				TakenItems(Pchar, "clock1", 1);
				EquipCharacterbyItem(Pchar, "clock1");
			}

			if(CheckAttribute(Pchar,"quest.Legrands_letter_paper") && Pchar.quest.Legrands_letter_paper == "yes")
			TakenItems(Pchar, "letter_paper", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_goldbug") && Pchar.quest.Legrands_goldbug == "yes")
			TakenItems(Pchar, "goldbug", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_gunpowder") && Pchar.quest.Legrands_gunpowder == "6")
			TakenItems(Pchar, "gunpowder", 6);

			if(CheckAttribute(Pchar,"quest.Legrands_antidote") && Pchar.quest.Legrands_antidote == "yes")
			TakenItems(Pchar, "potion3", 1);

			if(CheckAttribute(Pchar,"quest.Legrands_rum") && Pchar.quest.Legrands_rum == "yes")
			TakenItems(Pchar, "potionrum", 1);

			//reset
			Pchar.quest.Legrands_bladecrypto_d = "no";
			Pchar.quest.Legrands_bladecrypto_dl = "no";
			Pchar.quest.Legrands_bladecrypto_ds = "no";
			Pchar.quest.Legrands_bladecrypto_dsk = "no";

			Pchar.quest.Legrands_bladecrypto_cl = "no";
			Pchar.quest.Legrands_bladecrypto_csk = "no";
			Pchar.quest.Legrands_bladecrypto_cskp = "no";
			Pchar.quest.Legrands_bladecrypto_cskt = "no";

			Pchar.quest.Legrands_tinderbox = "no";
			Pchar.quest.Legrands_inkpen = "no";
			Pchar.quest.Legrands_clock1 = "no";
			Pchar.quest.Legrands_letter_paper = "no";
			Pchar.quest.Legrands_goldbug = "no";
			Pchar.quest.Legrands_antidote = "no";
			Pchar.quest.Legrands_rum = "no";
			Pchar.quest.Legrands_cauterization = "no";

			SetQuestHeader("Searching_the_shores");
			AddQuestRecord("Searching_the_shores","1"); AddQuestRecord("Searching_the_shores","2");
			AddQuestRecord("Searching_the_shores","3"); AddQuestRecord("Searching_the_shores","4");
			AddQuestRecord("Searching_the_shores","5"); AddQuestRecord("Searching_the_shores","6");
			CloseQuestHeader("Searching_the_shores");
			SetQuestHeader("The_parchment");
			AddQuestRecord("The_parchment","1"); AddQuestRecord("The_parchment","2");
			AddQuestRecord("The_parchment","3"); AddQuestRecord("The_parchment","4");
			AddQuestRecord("The_parchment","5"); AddQuestRecord("The_parchment","6");
			AddQuestRecord("The_parchment","7"); AddQuestRecord("The_parchment","8");
			SetQuestHeader("Useful_items");
			AddQuestRecord("Useful_items","1"); AddQuestRecord("Useful_items","2");
			AddQuestRecord("Useful_items","3"); AddQuestRecord("Useful_items","4");
			AddQuestRecord("Useful_items","5"); AddQuestRecord("Useful_items","6");
			AddQuestRecord("Useful_items","7");
			CloseQuestHeader("Useful_items");

			if(CheckAttribute(Pchar,"quest.driftwood") && Pchar.quest.driftwood == "yes")
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				GiveItem2Character(Pchar, "bladewoodsack");
				EquipCharacterByItem(Pchar, "bladewoodsack");
				TakenItems(Pchar, "1_log", -9);

				DeleteQuestHeader("Searching_the_shores");
				DeleteQuestHeader("The_parchment");
				DeleteQuestHeader("Useful_items");
			}

			DeleteQuestHeader("Jupiters_wood_mission");
			DeleteQuestHeader("Jupiters_Moultrie_mission");
		break;

		
//======================================================================================================================

//.................................................................................................
		case "pistol_ranking_list":
			//from loosing ap/pf/ab: reinc (seadogs) or give itemsbox
			Pchar.quest.reduce_ammo = "off";	//resets function

			if(CheckCharacterItem(Pchar, "pistol20"))
			{
				Pchar.quest.ammo_prefer = "pb";
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistol10"))
				{
					Pchar.quest.ammo_prefer = "pg";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistolmket"))
				{
					Pchar.quest.ammo_prefer = "mb";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistol9") || CheckCharacterItem(Pchar, "pistol4") || CheckCharacterItem(Pchar, "pistol8")
				|| CheckCharacterItem(Pchar, "pistol6") || CheckCharacterItem(Pchar, "pistol3_14") || CheckCharacterItem(Pchar, "pistol206")
				|| CheckCharacterItem(Pchar, "pistol5") || CheckCharacterItem(Pchar, "pistol203"))
				{
					Pchar.quest.ammo_prefer = "pb";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistolmtoon") || CheckCharacterItem(Pchar, "pistolbbuss"))
				{
					Pchar.quest.ammo_prefer = "pg";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistol201") || CheckCharacterItem(Pchar, "pistol205") || CheckCharacterItem(Pchar, "pistol7")
				|| CheckCharacterItem(Pchar, "pistol4_1") || CheckCharacterItem(Pchar, "pistol204") || CheckCharacterItem(Pchar, "pistol2")
				|| CheckCharacterItem(Pchar, "piratespistol") || CheckCharacterItem(Pchar, "pistol0") || CheckCharacterItem(Pchar, "pistol202"))
				{
					Pchar.quest.ammo_prefer = "pb";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistol3"))
				{
					Pchar.quest.ammo_prefer = "pg";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar, "pistol1"))
				{
					Pchar.quest.ammo_prefer = "pb";
				}
			}
			else
			{
				//no gun left (that uses ammo)
				Pchar.quest.ammo_prefer = "pb";
			}

			//LogIt("prefer = " + Pchar.quest.ammo_prefer);

			LAi_QuestDelay("reduce_ammo", 0.1);
		break;

		case "reduce_ammo":
			int maxp; int maxs; int sh;

			gp = GetCharacterItem(Pchar, "gunpowder");
			pb = GetCharacterItem(Pchar, "pistolbullets");
			pg = GetCharacterItem(Pchar, "pistolgrapes");
			mb = GetCharacterItem(Pchar, "musketbullets");

			//-------------------------------------------------
			if(IsEquipCharacterByItem(Pchar, "ammobag"))
			{
				maxp = 24;
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "ammobag2") || IsEquipCharacterByItem(Pchar, "bladepowderhornP") || IsEquipCharacterByItem(Pchar, "bladepowderhornA"))
				{
					maxp = 18;
				}
				else
				{
					if(IsEquipCharacterByItem(Pchar, "powderflask"))
					{
						maxp = 12;
					}
				}
				else maxp = 6;
			}

			if(gp > maxp)
			{
				TakeNItems(Pchar,"gunpowder", -100);
				TakeNItems(Pchar,"gunpowder", maxp);
			}

			//-------------------------------------------------
			if(IsEquipCharacterByItem(Pchar, "ammobag"))
			{
				maxs = 24;
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "ammobag2"))
				{
					maxs = 18;
				}
				else
				{
					if(IsEquipCharacterByItem(Pchar, "ammopouch"))
					{
						maxs = 12;
					}
					else maxs = 6;
				}
			}

			sh = pb + pg + mb*2;

			if(sh > maxs)
			{
				if(CheckAttribute(Pchar,"quest.ammo_prefer"))
				{
					switch(Pchar.quest.ammo_prefer)
					{
						case "pb":
							if(mb > 0)
							{
								LAi_QuestDelay("reduce_mb", 0.1);
							}
							else
							{
								if(pg > 0)
								{
									LAi_QuestDelay("reduce_pg", 0.1);
								}
								else
								{
									if(pb > 0)
									{
										LAi_QuestDelay("reduce_pb", 0.1);
									}
								}
							}
						break;

						case "pg":
							if(mb > 0)
							{
								LAi_QuestDelay("reduce_mb", 0.1);
							}
							else
							{
								if(pb > 0)
								{
									LAi_QuestDelay("reduce_pb", 0.1);
								}
								else
								{
									if(pg > 0)
									{
										LAi_QuestDelay("reduce_pg", 0.1);
									}
								}
							}
						break;

						case "mb":
							if(pg > 0)
							{
								LAi_QuestDelay("reduce_pg", 0.1);
							}
							else
							{
								if(pb > 0)
								{
									LAi_QuestDelay("reduce_pb", 0.1);
								}
								else
								{
									if(mb > 0)
									{
										LAi_QuestDelay("reduce_mb", 0.1);
									}
								}
							}
						break;
					}
				}
			}
		break;

		case "reduce_mb":
			mb = GetCharacterItem(Pchar, "musketbullets");

			if(CheckCharacterItem(Pchar, "ammopouch"))
			{
				maxs = 12;
			}
			else maxs = 6;

			TakeNItems(Pchar,"musketbullets", -1);
			sh = pb + pg + mb*2;

			if(sh > maxs)
			{
				LAi_QuestDelay("reduce_ammo", 0.1); 	//always restart from 'reduce_ammo'
			}
			else return;
		break;

		case "reduce_pg":
			pg = GetCharacterItem(Pchar, "pistolgrapes");

			if(CheckCharacterItem(Pchar, "ammopouch"))
			{
				maxs = 12;
			}
			else maxs = 6;

			TakeNItems(Pchar,"pistolgrapes", -1);
			sh = pb + pg + mb*2;

			if(sh > maxs)
			{
				LAi_QuestDelay("reduce_ammo", 0.1); 	//always restart from 'reduce_ammo'
			}
			else return;
		break;

		case "reduce_pb":
			pb = GetCharacterItem(Pchar, "pistolbullets");

			if(CheckCharacterItem(Pchar, "ammopouch"))
			{
				maxs = 12;
			}
			else maxs = 6;

			TakeNItems(Pchar,"pistolbullets", -1);
			sh = pb + pg + mb*2;

			if(sh > maxs)
			{
				LAi_QuestDelay("reduce_ammo", 0.1);	//always restart from 'reduce_ammo'
			}
			else return;
		break;

		//<-- JRH





	}
	
}
