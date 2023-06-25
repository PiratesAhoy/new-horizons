
void OpenBoxProcedure_WR()
{
//Logit("OpenBoxProcedure_JRH");
//Logit("2222");
	ref chr = GetMainCharacter();
	if( !CheckAttribute(chr,"boxname") ) return;
	int locidx = FindLoadedLocation();
	if(locidx<0) return;
	string atrName = chr.boxname;
	aref ar;
	if(!HasSubStr(chr.boxname,"corpse")){//MAXIMUS: makes box from corpse with hand-icon in the top-left corner -->
		makearef(ar,Locations[locidx].(atrName));
		if(GetAttributesNum(ar)==0)
		{
			Locations[locidx].(atrName).Money = 0;
			makearef(ar,Locations[locidx].(atrName));
		}

    // JRH -->
//-----------------------------------------------------------------------------------------------------------------
	int gp;
	int pb;
	int pg;
	int mb;
	int i;
	float u, v, w;
	//note in INTERFACE\itemsbox search JRH: normal box sounds avoided when not wanted

	//Q2 -->

	if(Locations[locidx].id=="Grand_Cayman_townhall")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"Cayman_box1") && chr.Cayman_box1 == "unlocked")
				{
					SetNextWeather("Clear");
					DoQuestReloadToLocation("Grand_Cayman_town", "goto", "box2", "_");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Grand_Cayman_town")
	{
		switch(chr.boxname)
		{
			case "box2":
				SetNextWeather("Clear");

				if(CheckAttribute(chr,"Cayman_box2") && chr.Cayman_box2 == "turned")
				{
					PlaySound("PEOPLE\run_roof.wav");
					chr.Cayman_box2 = "not_turned";
					ChangeCharacterAddressGroup(chr, "Grand_Cayman_town", "reload", "reload22");
					
					chr.quest.clear_weather.win_condition.l1 = "locator";
					chr.quest.clear_weather.win_condition.l1.location = "Grand_Cayman_town";
					chr.quest.clear_weather.win_condition.l1.locator_group = "reload";
					chr.quest.clear_weather.win_condition.l1.locator = "reload22";
					chr.quest.clear_weather.win_condition = "clear_weather";

					chr.quest.Estate_turn_to_box9.win_condition.l1 = "location";
					chr.quest.Estate_turn_to_box9.win_condition.l1.location = "BB_Eden_estate";
					chr.quest.Estate_turn_to_box9.win_condition = "Estate_turn_to_box9";
				}
				else LAi_QuestDelay("Cayman_turn_to_ri3", 0.01);
			break;

			case "box3":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Grand_Cayman_town", "reload", "reload23");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_bedroom1")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_attic2")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_attic3")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_dining_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_bedroom2")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_chapel")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"Eden_chapel_box1") && chr.Eden_chapel_box1 == "on") return;

				chr.Eden_chapel_box1 = "on";
				PlaySound("INTERFACE\girder_open.wav");
				Locations[FindLocation("BB_Eden_chapel")].models.always.l1 = "girder_free";
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box1", 0.0001);
				Locations[FindLocation("BB_Eden_chapel")].locators_radius.box.box1 = 0.0001;
				Locations[FindLocation("BB_Eden_estate")].reload.l6.disable = 0;
				SetNextWeather("Clear");
				
				LAi_QuestDelay("estate_girder", 2.0);	
			break;
		}

		return;
	}
	
	if(Locations[locidx].id=="BB_Eden_office")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("INTERFACE\closet_open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("return_Eden_books", 0.1);
				}
				else PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box2":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("return_Eden_pictures", 0.1);
				}
				else PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box3":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("INTERFACE\chart_move.wav");
					PlaySound("INTERFACE\chart_move.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("return_Eden_contract", 0.1);
				}
				else PlaySound("INTERFACE\small_door_locked.wav");
			break;

			case "box4":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("empty_Eden_box4_check", 0.1);
				}
				else PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box5":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				}
				else PlaySound("INTERFACE\small_door_locked.wav");
			break;

			case "box6":
				if(CheckAttribute(chr,"eden_office_boxes") && chr.eden_office_boxes == "open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_garden_house")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);	
			break;

			case "box2":
				LaunchItemsBox(&ar);
			break;

			case "box3":
				LaunchItemsBox(&ar);
			break;

			case "box4":
				LaunchItemsBox(&ar);	
			break;

			case "box5":
				LaunchItemsBox(&ar);
			break;

			case "box6":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Eleuthera_shore")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				if(CheckCharacterItem(chr,"bladeanchor_big"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeanchor_big"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeanchor_big");
					}
				}
			
				chr.citadel_lever_dir = "tower";
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest1");

				LAi_QuestDelay("Citadel_to_box2", 0.5);	
			break;
	//--------------------------------------------------------------------------------------------------
	//new serie TO tower
			case "box2":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box4");

				LAi_QuestDelay("Citadel_turn_box5", 0.5);
			break;

			case "box4":
				PlaySound("PEOPLE\run_stone.wav");
				if(CheckAttribute(chr,"citadel_lever_dir") && chr.citadel_lever_dir == "tower")
				{
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box6");

					LAi_QuestDelay("Citadel_turn_box10", 0.5);
				}
				else 
				{
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box25");	
				}
			break;

			case "box6":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box10");
			break;

			case "box10":
				if(CheckCharacterItem(chr,"bladeanchor_big"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeanchor_big"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeanchor_big");
					}
				}

				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box12");
			break;

			case "box12":
				if(CheckCharacterItem(chr,"bladeanchor_big"))
				{
					Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";
					PlaySound("OBJECTS\DUEL\anchor.wav");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladeanchor_big");
					EquipCharacterByItem(chr, "bladeX4");

					LAi_QuestDelay("Citadel_place_anchor", 1.0);
				}
				else
				{
					if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB2" ||
				  	 Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB1")
					{
						//bridge
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box13");
					}
					else 
					{
						//no bridge
						if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big3")
						{
							Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "";

							PlaySound("OBJECTS\DUEL\man_attack1.wav");
							LAi_SetSitType(chr);	
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr, "bladeanchor_big");
							EquipCharacterByItem(chr, "bladeanchor_big");

							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F1")
							{
								//take it + return to lever
					
								LAi_QuestDelay("Citadel_place_anchor", 1.0);
							}
							
							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F2")
							{
								//take it + change to FB2 + continue on bridge
								Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB2";
								chr.citadel_extra_bridge_sound = "on";
					
								LAi_QuestDelay("Citadel_place_anchor", 1.0);
							}
						}
						else
						{
							PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
							chr.citadel_lever_dir = "lever";					

							LAi_QuestDelay("Citadel_to_box21", 1.0);
						}
					}
				 }
			break;

			case "box39":
				if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB1"
				|| Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB2")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box13");
				}
				else 
				{
					chr.citadel_lever_dir = "lever";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box21");
				}
			break;

			case "box13":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box14");
			break;

			case "box14":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box15");
			break;

			case "box15":
				PlaySound("PEOPLE\creak2.wav");
				if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB1")
				{
					
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "reload", "reload5");
				}
				else
				{
					chr.citadel_lever_dir = "lever";
					ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box37");
				}
			break;

			case "box37":
				//upper door closed
				PlaySound("INTERFACE\knock2.wav");

				LAi_QuestDelay("Citadel_to_box17", 1.0);
			break;

			case "box16":
				//lever

				if(CheckAttribute(chr,"citadel_lever"))
				{
					switch(chr.citadel_lever)
					{
						case "up":
							if(GetAttribute(chr, "citadel_lever_blocked") == "yes") return;
							chr.citadel_lever_blocked = "yes";

							PlaySound("INTERFACE\lever_down.wav");
							chr.citadel_lever = "down";	
							Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_down";

							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F")
							{
								Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB2";
								chr.citadel_bridge_sounds = "on";
							}

							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F1")
							{
								if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big3")
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_F2";
									chr.citadel_bridge_sounds = "off";
								}
								else 
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB2";
									chr.citadel_bridge_sounds = "on";
								}
							}

							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB1")
							{
								if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big3")
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB2";
									chr.citadel_bridge_sounds = "off";
								}
								else 
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_F2";
									chr.citadel_bridge_sounds = "on";
								}
							}

							LAi_QuestDelay("Citadel_lever", 0.5);
						break;

						case "down":
							if(GetAttribute(chr, "citadel_lever_blocked") == "yes") return;
							chr.citadel_lever_blocked = "yes";

							PlaySound("INTERFACE\lever_up.wav");
							chr.citadel_lever = "up";	
							Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
					
							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F2")
							{
								Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_F1";
								chr.citadel_bridge_sounds = "off";
							}

							if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB2")
							{
								if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big3")
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
									chr.citadel_bridge_sounds = "off";
									chr.citadel_success = "yes";
								}
								else 
								{
									Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_F1";
									chr.citadel_bridge_sounds = "on";
								}
							}

							LAi_QuestDelay("Citadel_lever", 0.5);	
						break;

						case "missing":
							if(CheckCharacterItem(chr,"bladelever"))
							{
								if(GetAttribute(chr, "citadel_lever_blocked") == "yes") return;
								chr.citadel_lever_blocked = "yes";

								if(!IsEquipCharacterByItem(chr, "bladelever"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladelever");
								}
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("Citadel_place_lever", 1.0);
							}
							else
							{
								PlaySound("VOICE\ENGLISH\blaze_huh.wav");
							}	
						break;
					}
				}	
			break;

			case "box17":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box18");
				chr.citadel_lever_dir = "lever";
			break;

			case "box18":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box19");
			break;

			case "box19":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box20");
			break;

			case "box20":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box21");
			break;
	//--------------------------------------------------------------------------------------------------
	//new serie FROM tower
			case "box21":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box30");
			break;

			case "box30":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box7");
					
				LAi_QuestDelay("Citadel_turn_box5", 0.5);
			break;

			case "box7":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box4");
				
				LAi_QuestDelay("Citadel_turn_box3", 0.5);
			break;
	//--------------------------------------------------------------------------------------------------
			case "box25":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest2");

				LAi_QuestDelay("Citadel_to_box1", 0.5);	
			break;

		//to tower lower door 
			case "box26":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box27");
			break;

			case "box27":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box28");

				LAi_QuestDelay("pchar_playertype", 0.5);
				LAi_QuestDelay("recoil_sound", 0.5);		
			break;

			case "box28":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest4");

				LAi_QuestDelay("Citadel_to_quest5", 0.5);	
			break;

			case "box29":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box31");	
			break;

			case "box31":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
				
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest7");

				if(Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_FB2" ||
				   Locations[FindLocation("Eleuthera_shore")].models.always.locators == "Pass1_l_Eleuthera_F2")
				{
					LAi_QuestDelay("Citadel_to_reload6", 0.5);
				}
				else LAi_QuestDelay("Citadel_to_box38", 0.5);
			break;

			case "box38":
				//lower door closed
				PlaySound("INTERFACE\knock2.wav");

				LAi_QuestDelay("Citadel_to_box32", 1.0);
			break;

		//from tower lower door 
			case "box32":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box33");	
			break;

			case "box33":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "box", "box34");	
			break;

			case "box34":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest8");

				LAi_QuestDelay("Citadel_to_quest9", 0.5);
			break;

			case "box35":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "Eleuthera_shore", "quest", "quest10");

				LAi_QuestDelay("Citadel_to_box26", 0.5);
			break;

			case "box36":
				//dig up anchor
				
				if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big2")
				{
					//pick it up
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					LAi_SetSitType(chr);

					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box36", 0.001);
					Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;

					LAi_QuestDelay("dig_up_anchor_Citadel2", 1.0);
				}

				if(Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big1")
				{
				    if(CheckAttribute(chr,"citadel_box36") && chr.citadel_box36 == "on")
				    {
					return;
				    }
				    else
				    {
					if(CheckCharacterItem(chr,"bladespade"))
					{
						chr.citadel_box36 = "on";

						if(!IsEquipCharacterByItem(chr, "bladespade")) 
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladespade");
						}
						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("dig_sand", 1.0);
						LAi_QuestDelay("dig_sand", 2.0);
						LAi_QuestDelay("dig_sand", 3.0);
						LAi_QuestDelay("dig_anchor_Citadel", 1.0);
						LAi_QuestDelay("dig_anchor_Citadel", 2.0);
						LAi_QuestDelay("dig_anchor_Citadel", 2.0);
						LAi_QuestDelay("dig_anchor_Citadel", 3.0);
						LAi_QuestDelay("dig_anchor_Citadel", 3.0);
						LAi_QuestDelay("dig_anchor_Citadel", 3.0);
						LAi_QuestDelay("dig_up_anchor_Citadel", 4.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						LAi_SetSitType(chr);						

						Logit(TranslateString("","No, it's stuck in the sand."));
						LAi_QuestDelay("pchar_playertype", 1.0);
					}
				    }
				}				
			break;
		//unlock to tunnel
			case "box40":
				if(CheckAttribute(chr, "citadel_box40") && chr.citadel_box40 == "on") return;

				if(CheckCharacterItem(chr,"key30"))
				{
					chr.citadel_box40 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_citadel_tunnel", 2.0);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Citadel_tower_stairs4")
	{
		switch(chr.boxname)
		{
			case "box4":
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.5;
				DoQuestReloadToLocation("Citadel_cave", "goto", "fall", "fall_Citadel_cave");	
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Citadel_cave")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("bladespade_check", 0.1);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Citadel_tower_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("key30_check", 0.1);
			break;

			case "box4":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}



	if(Locations[locidx].id=="Tortuga_port")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

		     //WAY UP
			case "box2":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box3");
			break;

			case "box3":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box4");
			break;

			case "box4":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "reload", "reloadQ2");
			break;

			case "box5":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box6");
			break;

			case "box6":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box7");
			break;

			case "box7":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "reload", "reloadQ3");
			break;

			case "box8":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "reload", "reloadQ5");

				if (makeint(environment.time) > 22.0 || makeint(environment.time) < 6.0)
				{
					LAi_QuestDelay("Tortuga_gunsmith_closed", 2.0);	
				}
			break;

			case "box9":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box10");
			break;

			case "box10":
				PlaySound("INTERFACE\knock2.wav");

				LAi_QuestDelay("Tortuga_carriage", 1.0);
			break;

			case "box11":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Tortuga_dovecote_to_box12", 0.5);
			break;

			case "box12":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box13");
			break;

			case "box13":
				PlaySound("PEOPLE\jump_stone.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Pchar_playertype", 0.25);

				if(CheckAttribute(chr,"Cook_dead") && chr.Cook_dead == "yes")
				{
					ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box14");
				}
				else 
				{
					ChangeCharacterAddressGroup(chr, "Tortuga_port", "quest", "fight1");


					LAi_QuestDelay("Tortuga_Cook_fight", 1.0);
				}
			break;

			case "box14":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box15");

				LAi_QuestDelay("TT_turn_box16", 0.5);
			break;

			case "box15":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box16");
			break;

			case "box16":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Tortuga_dovecote_to_box17", 0.5);
			break;

			case "box17":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box18");
			break;

			case "box18":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "reload", "reloadQ6");
			
				chr.quest.image_dovecote.win_condition.l1 = "location";
				chr.quest.image_dovecote.win_condition.l1.location = "Tortuga_tower_stairs_B";
				chr.quest.image_dovecote.win_condition = "image_dovecote";

				chr.quest.Tortuga_dovecote_turn_to_ship5.win_condition.l1 = "locator";
				chr.quest.Tortuga_dovecote_turn_to_ship5.win_condition.l1.location = "Tortuga_port";
				chr.quest.Tortuga_dovecote_turn_to_ship5.win_condition.l1.locator_group = "goto";
				chr.quest.Tortuga_dovecote_turn_to_ship5.win_condition.l1.locator = "dovecote1";
				chr.quest.Tortuga_dovecote_turn_to_ship5.win_condition = "Tortuga_dovecote_turn_to_ship5";
			break;

			case "box19":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "merchant", "dovecote4");
				LAi_SetActorType(characterFromID("fake_Ogeron"));
				LAi_ActorTurnToLocator(characterFromID("fake_Ogeron"), "merchant", "dovecote4");
				LAi_SetActorType(characterFromID("french_surgeon4"));
				LAi_ActorTurnToLocator(characterFromID("french_surgeon4"), "merchant", "dovecote4");

				LAi_QuestDelay("Tortuga_dovecote_to_dc4", 1.0);
			break;

		     //WAY DOWN
			case "box20":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box21");
			break;

			case "box21":
				PlaySound("PEOPLE\jump_stone.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box22");

				LAi_QuestDelay("Pchar_playertype", 0.25);
			break;

			case "box22":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box23");

				LAi_QuestDelay("TT_turn_box13", 0.5);
			break;

			case "box23":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box24");
			break;

			case "box24":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Tortuga_dovecote_to_box25", 0.5);
			break;

			case "box25":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box26");
			break;

			case "box26":
				PlaySound("PEOPLE\jump_stone.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "box", "box27");

				LAi_QuestDelay("Pchar_playertype", 0.25);
			break;

			case "box27":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_port", "reload", "reloadQ8");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Tortuga_surgeon2")
	{
		switch(chr.boxname)
		{
			case "box5":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_surgeon2", "goto", "gotoQ2");
			break;			
		}

		return;
	}

	if(Locations[locidx].id=="Tortuga_gunsmith_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;			
		}

		return;
	}

	if(Locations[locidx].id=="Tortuga_gunsmith_workshop")
	{
		switch(chr.boxname)
		{
			case "box6":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_gunsmith_workshop", "goto", "gunsmith2");
			break;			
		}

		return;
	}

	if(Locations[locidx].id=="Tortuga_tower")
	{
		switch(chr.boxname)
		{
		    //WAY UP
			case "box8":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box9");
			break;

			case "box9":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box10");
			break;

			case "box10":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box11");

				LAi_QuestDelay("TT_turn_box12", 0.5);	
			break;

			case "box11":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box12");

				LAi_QuestDelay("TT_turn_box13", 0.5);
			break;

			case "box12":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box13");

				LAi_QuestDelay("TT_turn_box14", 0.5);
			break;

			case "box13":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box14");

				LAi_QuestDelay("TT_turn_box15", 0.5);
			break;

			case "box14":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box15");

				LAi_QuestDelay("TT_turn_box16", 0.5);
			break;

			case "box15":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box16");

				LAi_QuestDelay("TT_turn_tower_window", 0.5);
			break;

			case "box16":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box27");

				if(CheckAttribute(chr,"Tortuga_tower_scenery") && chr.Tortuga_tower_scenery == "seen") 
				{
					chr.Tortuga_tower_scenery = "seen";
					return;
				}

				LAi_QuestDelay("Pchar_very_nice", 1.0);
			break;

			case "box27":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box24");
			break;

			case "box24":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box25");
			break;

			case "box25":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box26");
			break;

			case "box26":
				locations[FindLocation("Tortuga_port")].id.label = "#stown_name# tower.";
				Locations[FindLocation("Tortuga_port")].image = "wr_Tortuga_tower_outside.tga";

				Locations[FindLocation("Tortuga_port")].vcskip = true;
				SetCurrentTime(12, 0);
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "reload", "reloadQ5");
			break;

		    //WAY DOWN
			case "box28":
				PlaySound("PEOPLE\jump_stone.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box29");

				LAi_QuestDelay("Pchar_playertype", 0.25);
				LAi_QuestDelay("TT_turn_box30", 0.5);
			break;

			case "box29":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box30");

				LAi_QuestDelay("TT_turn_box23", 0.5);
			break;

			case "box30":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box23");
			break;	

			case "box23":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box22");

				LAi_QuestDelay("TT_turn_box21", 0.5);
			break;

			case "box22":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box21");

				LAi_QuestDelay("TT_turn_box20", 0.5);
			break;

			case "box21":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box20");

				LAi_QuestDelay("TT_turn_box19", 0.5);
			break;

			case "box20":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box19");

				LAi_QuestDelay("TT_turn_box18", 0.5);
			break;

			case "box19":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box18");

				LAi_QuestDelay("TT_turn_box17", 0.5);
			break;

			case "box18":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "box", "box17");
			break;

			case "box17":
				locations[FindLocation("Tortuga_port")].id.label = "#stown_name# port.";

				Locations[FindLocation("Tortuga_port")].image = "Town_Tortuga.tga";
				Locations[FindLocation("Tortuga_port")].vcskip = false;
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_tower", "reload", "reloadQ4");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Tortuga_sailmaker")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_sailmaker", "box", "box2");
				Locations[FindLocation("Tortuga_port")].vcskip = true;
			break;

			case "box2":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_sailmaker", "reload", "reload2");
			break;

			case "box3":
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_sailmaker", "box", "box4");
			break;

			case "box4":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Tortuga_sailmaker", "reload", "reload1");
				Locations[FindLocation("Tortuga_port")].vcskip = false;
			break;
		}

		return;
	}

//EDEN
//-------------------------------------------------------------------------------------------------------------

	if(Locations[locidx].id=="BB_Eden_tunnel")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("equip_wine_bottles_box1", 0.5);	
			break;

			case "box2":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("equip_wine_bottles_box2", 0.5);								
			break;

			case "box3":
				//load elevator
		
				if(CheckAttribute(chr,"Eden_tunnel_box3") && chr.Eden_tunnel_box3 == "on") return;

				if(Locations[FindLocation(chr.location)].models.always.l3 == "elevator_up")
				{
					if(Locations[FindLocation(chr.location)].models.always.l7 == "barrel_elevator_up")
					{
						//fill wine
		
						if(CheckCharacterItem(chr,"pistolbottlew5"))
						{
							chr.wine_bottles = makeint(chr.wine_bottles)+1;
							//LogIt("wine_bottles = " + chr.wine_bottles);

							chr.Eden_tunnel_box3 = "on";
							PlaySound("AMBIENT\TAVERN\tinkle1.wav");
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							LAi_SetStayType(chr);

							LAi_QuestDelay("crash_pistol_bottle", 3.0);
						}
						else
						{
							if(CheckCharacterItem(chr,"bladebottlew5"))
							{
								chr.wine_bottles = makeint(chr.wine_bottles)+1;
								//LogIt("wine_bottles = " + chr.wine_bottles);

								chr.Eden_tunnel_box3 = "on";
								PlaySound("AMBIENT\TAVERN\tinkle1.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								LAi_SetStayType(chr);

								LAi_QuestDelay("crash_blade_bottle", 3.0);
							}
						}
						else
						{
							Logit(TranslateString("","Now let's fill the barrel up."));
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						}
					}		
					else
					{
						//place barrel
		
						if(CheckCharacterItem(chr,"bladebarrel3"))
						{
							if(IsEquipCharacterByItem(chr, "bladebarrel3")) 
							{ RemoveCharacterEquip(chr, BLADE_ITEM_TYPE); }
							TakeItemFromCharacter(chr, "bladebarrel3");
								
							PlaySound("PEOPLE\jump.wav");
							PlaySound("PEOPLE\step_echo.wav");
							Locations[FindLocation(chr.location)].models.always.l7 = "barrel_elevator_up";
							Locations[FindLocation(chr.location)].models.always.l8 = "bottle_elevator_up";	

							int wine_bottles = 0;
							chr.wine_bottles = wine_bottles;
							//LogIt("wine_bottles = " + chr.wine_bottles);					

							LAi_QuestDelay("Eden_tunnel_place_empty_barrel", 0.5);
						}
						else
						{
							Logit(TranslateString("","Hmm, I could place some goods on the elevator."));
							PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
						}
					}
				}						
			break;

			case "box4":
				if(CheckAttribute(chr,"Eden_tunnel_box4") && chr.Eden_tunnel_box4 == "open")
				{
					LaunchItemsBox(&ar);
				}
				else
				{
					if(CheckCharacterItem(chr,"key16"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");	
						chr.Eden_tunnel_box4 = "open";
						TakeItemFromCharacter(chr, "key16");

					}
					else 
					{
						PlaySound("PEOPLE\beltkey.wav");		
					}
				}								
			break;

			case "box5":
				//barrel niche

				if(CheckAttribute(chr,"Eden_tunnel_box5") && chr.Eden_tunnel_box5 == "on") return;

				if(Locations[FindLocation(chr.location)].models.always.l10 == "bottle_niche")
				{
					//pick up empty barrel
					
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box5", 0.0001);
					Locations[FindLocation("BB_Eden_tunnel")].locators_radius.box.box5 = 0.0001;

					LAi_SetSitType(chr);
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("Eden_tunnel_take_empty_barrel", 0.5);
				}
				else
				{
					if(CheckCharacterItem(chr,"corkscrew"))
					{
						chr.Eden_tunnel_box5 = "on";
						LAi_SetSitType(chr);
						PlaySound("AMBIENT\TAVERN\open_bottle.wav");
						TakeItemFromCharacter(chr, "corkscrew");

						LAi_QuestDelay("Eden_tunnel_wine_out", 1.0);
					}			
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("Eden_tunnel_too_heavy_barrel", 0.5);
				}
			break;

			case "box6":
				//lever downstairs: gate up & down				

				if(Locations[FindLocation(chr.location)].models.always.l5 == "lever1_up")
				{
					//gate is down
					PlaySound("INTERFACE\lever_down.wav");	
					Locations[FindLocation(chr.location)].models.always.l4 = "bars_up";
					Locations[FindLocation(chr.location)].locators_radius.goto.gate_stop1 = 0.001;
					Locations[FindLocation(chr.location)].models.always.l5 = "lever1_down";
					Locations[FindLocation(chr.location)].reload.l1.disable = 1;		//to Eden office

					LAi_QuestDelay("Eden_tunnel_gate_up", 0.5);	
				}
				else
				{
					PlaySound("INTERFACE\lever_up.wav");	
					Locations[FindLocation(chr.location)].models.always.l4 = "bars_down";
					Locations[FindLocation(chr.location)].locators_radius.goto.gate_stop1 = 0.5;
					Locations[FindLocation(chr.location)].models.always.l5 = "lever1_up";
					Locations[FindLocation(chr.location)].reload.l1.disable = 0;		//to Eden office

					LAi_QuestDelay("Eden_tunnel_gate_down", 0.5);
				}	
			break;

			case "box7":
				//lever upstairs: elevator up & down	
			
				if(Locations[FindLocation(chr.location)].models.always.l6 == "lever2_up")
				{
					//send elevator up
					PlaySound("INTERFACE\lever_down.wav");	
					Locations[FindLocation(chr.location)].models.always.l6 = "lever2_down";
					Locations[FindLocation(chr.location)].models.always.l3 = "elevator_up";
				
					if(Locations[FindLocation(chr.location)].models.always.l7 == "barrel_elevator_down")
					{
						Locations[FindLocation(chr.location)].models.always.l7 = "barrel_elevator_up";
						Locations[FindLocation(chr.location)].models.always.l8 = "bottle_elevator_up";
					}

					if(CheckAttribute(chr,"wine_bottles") && chr.wine_bottles == "5")
					{
						Locations[FindLocation(chr.location)].locators_radius.box.box3 = 0.001;
					}
					else
					{
						if(CheckAttribute(chr,"wine_bottles") && chr.wine_bottles == "4")
						{
							Locations[FindLocation(chr.location)].locators_radius.box.box3 = 0.001;
						}
					}
					else Locations[FindLocation(chr.location)].locators_radius.box.box3 = 0.7;
					
					Locations[FindLocation(chr.location)].locators_radius.randitem.randitem5 = 0.8;

					if(CheckAttribute(chr,"wine_bottles") && chr.wine_bottles == "4") chr.wine_bottles = makeint(chr.wine_bottles)+1;
					//fake 5 which prevents from repeating long final sequence if sending elevator down again	
				
					LAi_QuestDelay("Eden_tunnel_elevator_up", 0.5);	
				}
				else 
				{
					//send elevator down
					PlaySound("INTERFACE\lever_up.wav");	
					Locations[FindLocation(chr.location)].models.always.l6 = "lever2_up";
					Locations[FindLocation(chr.location)].models.always.l3 = "elevator_down";

					if(Locations[FindLocation(chr.location)].models.always.l7 == "barrel_elevator_up")
					{
						Locations[FindLocation(chr.location)].models.always.l7 = "barrel_elevator_down";
						Locations[FindLocation(chr.location)].models.always.l8 = "bottle_elevator_down";
					}

					Locations[FindLocation(chr.location)].locators_radius.box.box3 = 0.001;
					Locations[FindLocation(chr.location)].locators_radius.randitem.randitem5 = 0.001;
		
					LAi_QuestDelay("Eden_tunnel_elevator_down", 0.5);	
				}
			break;

			case "box8":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box9":
				PlaySound("INTERFACE\locked_window.wav");
			break;

		}

		return;
	}

	if(Locations[locidx].id=="BB_Eden_estate")
	{
		switch(chr.boxname)
		{
		//entre estate building ------------------------------------------------------------------

			case "box23":
				SetNextWeather("Clear");
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "goto", "box21");
			break;

			case "box21":
				SetNextWeather("Clear");
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "goto", "box22");
			break;

			case "box22":
				SetNextWeather("Clear");
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box3");

				LAi_QuestDelay("Estate_turn_to_box1", 0.5);
			break;
			
			case "box3":
				if(IsOfficer(CharacterFromID("Hands")))				
				{
					ChangeCharacterAddressGroup(characterFromID("Hands"), "none", "", "");
					ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "goto", "hands");
					LAi_SetOfficerType(characterFromID("Hands"));
		
					Characters[GetCharacterIndex("Caesar")].Dialog.Filename = "Caesar_dialog.c";

					if(CheckAttribute(chr,"servants_info") && chr.servants_info == "5")
					{
						ChangeCharacterAddressGroup(characterFromID("Margaret_Pough"), "BB_Eden_estate", "goto", "entre");
						LAi_SetStayType(characterFromID("Margaret_Pough"));
					}
				}
				else Characters[GetCharacterIndex("Caesar")].Dialog.Filename = "Eden servants_dialog.c";

				if(IsOfficer(CharacterFromID("Pell")))				
				{
					ChangeCharacterAddressGroup(characterFromID("Pell"), "none", "", "");
					ChangeCharacterAddressGroup(characterFromID("Pell"), "BB_Eden_estate", "goto", "pell");
					LAi_SetOfficerType(characterFromID("Pell"));
				}

				ChangeCharacterAddressGroup(characterFromID("Caesar"), "BB_Eden_estate", "goto", "servant2");
				SetModel(characterFromID("Caesar"), "black_servant2", "man", "man", 1.8, false);
				LAi_SetStayType(characterFromID("Caesar"));
				characters[GetCharacterIndex("Caesar")].name = "Servant";
				
				if(CheckAttribute(chr,"servants_info") && chr.servants_info == "5")
				{
					ChangeCharacterAddressGroup(characterFromID("Margaret_Pough"), "BB_Eden_estate", "goto", "entre");
				}

				if(!CheckAttribute(chr, "servant_Caesar") || chr.servant_Caesar != "done")
				{
					//only first time he sees Hands

					if(IsOfficer(CharacterFromID("Hands")))				
					{
						chr.quest.servant_is_Caesar.win_condition.l1 = "locator";
						chr.quest.servant_is_Caesar.win_condition.l1.location = "BB_Eden_estate";
						chr.quest.servant_is_Caesar.win_condition.l1.locator_group = "goto";
						chr.quest.servant_is_Caesar.win_condition.l1.locator = "entre";
						chr.quest.servant_is_Caesar.win_condition = "servant_is_Caesar";
					}
				}

				SetNextWeather("Clear");
				DoQuestReloadToLocation("BB_Eden_estate", "reload", "reload1", "enter_estate");						
			break;

		//leave estate building -----------------------------------------------------------------

			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box2");

				if(CheckAttribute(chr,"estate_direction"))
				{
					switch(chr.estate_direction)
					{
						case "stop":
							//not sure if this case is needed							


					//		PlaySound("INTERFACE\knock2.wav");
						break;

						case "Teach_house":	
							LAi_QuestDelay("Estate_turn_to_box24", 0.5);
							LAi_QuestDelay("Estate_change_soundtype", 2.0);	
						break;

						case "Knight_house":
							

						break;

						case "Cayman_town":
							LAi_QuestDelay("Estate_turn_to_box22", 0.5);
							LAi_QuestDelay("Estate_change_soundtype", 2.0);
						break;
					}
				}						
			break;

			case "box2":
				PlaySound("PEOPLE\run_roof.wav");

				if(CheckAttribute(chr,"estate_direction"))
				{
					switch(chr.estate_direction)
					{
						case "Teach_house":	
							ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box24");
							ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box27");

							LAi_QuestDelay("Estate_turn_to_box27", 0.5);	
						break;

						case "Knight_house":
							ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box11");	

						break;

						case "Cayman_town":
							ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "reload", "reload10");

							LAi_QuestDelay("Estate_turn_to_wall", 0.5);
						break;
					}
				}							
			break;

		//to Teach's house -----------------------------------------------------------------------------

			case "box24":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box27");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box25");

				LAi_QuestDelay("Estate_turn_to_box25", 0.5);								
			break;

			case "box27":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box25");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box28");

				LAi_QuestDelay("Estate_turn_to_box28", 0.5);
			break;

			case "box25":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box28");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box26");

				LAi_QuestDelay("Estate_turn_to_box26", 0.5);								
			break;

			case "box28":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box26");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box4");

				LAi_QuestDelay("Estate_turn_to_box4", 0.5);
				LAi_QuestDelay("Hands_to_Teach_kitchen", 2.0);
			break;

			case "box26":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box4");

				LAi_QuestDelay("Estate_turn_to_Teach_door", 0.5);							
			break;

			case "box4":
				DoQuestReloadToLocation("BB_Teach_kitchen", "reload", "reload4", "_");						
			break;
	
			case "box5":
				if(locations[FindLocation("BB_Eden_estate")].environment.sea == "true")
				{
					if(CheckAttribute(chr,"hands_flood") && chr.hands_flood == "done")
					{
						DoQuestReloadToLocation("BB_Teach_drawing_room", "reload", "reload2", "Estate_low_tide");
					}
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box6");
					ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box7");

					LAi_QuestDelay("Estate_turn_to_box7", 0.5);
				}								
			break;

			case "box6":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box7");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box8");	

				LAi_QuestDelay("Estate_turn_to_box8", 0.5);						
			break;

			case "box7":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box8");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box29");

				LAi_QuestDelay("Estate_turn_to_box29", 0.5);							
			break;

			case "box8":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box29");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box9");

				LAi_QuestDelay("Estate_turn_to_box9", 0.5);							
			break;

			case "box29":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box9");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box10");

				LAi_QuestDelay("Estate_turn_to_box10", 0.5);							
			break;

			case "box9":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box10");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box13");

				LAi_QuestDelay("Estate_turn_to_box13", 0.5);
				LAi_QuestDelay("Hands_to_Eden_cellar", 2.0);							
			break;

			case "box10":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box13");

				LAi_QuestDelay("Estate_turn_to_Teach_cellar", 0.5);								
			break;

			case "box13":
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "clear";

				DoQuestReloadToLocation("BB_Eden_tunnel", "reload", "reload2", "_");						
			break;

			case "box11":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_Eden_estate", "box", "box12");							
			break;

		//inside house
			case "box14":
				PlaySound("PEOPLE\lockpick2.wav");
			break;

			case "box15":
				PlaySound("PEOPLE\lockpick2.wav");
			break;

			case "box16":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box17":
				PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box18":
				PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box19":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box20":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_Teach_drawing_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				ChangeCharacterAddressGroup(characterFromID("Hands"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_Eden_estate", "box", "box6");	
				DoQuestReloadToLocation("BB_Eden_estate", "box", "box5", "Hands_mhm");					
			break;
		}

		return;
	}


//RICHARDS
//-------------------------------------------------------------------------------------------------------------
	if(Locations[locidx].id=="cloister_exit")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "cloister_exit", "reload", "reload3");							
			break;

			case "box2":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_QAR_cabin")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "BB_QAR_cabin", "goto", "bed");
				LAi_SetActorType(chr);
				LAi_ActorSetLayMode(chr);
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box1", 0.0001);
				Locations[FindLocation("BB_QAR_cabin")].locators_radius.box.box1 = 0.0001;

				LAi_QuestDelay("pchar_sigh", 1.0);
				LAi_QuestDelay("pchar_sigh", 1.0);
				LAi_QuestDelay("Richards_back", 3.0);							
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_graveyard")
	{
		switch(chr.boxname)
		{
			case "box2":
				LaunchItemsBox(&ar);								
			break;

			case "box3":
				if(CheckAttribute(chr,"chapel_window") && chr.chapel_window == "broken")
				{
					Logit(TranslateString("","No, I'll only cut myself on those shards."));
					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_graveyard", "reload", "reload7");
					LAi_SetFightMode(chr, true);
					ChangeCharacterAddressGroup(CharacterFromID("chapel_target"), "BB_graveyard", "goto", "target");

					chr.quest.enter_chapel.win_condition.l1 = "location";
					chr.quest.enter_chapel.win_condition.l1.location = "bb_church_room";
					chr.quest.enter_chapel.win_condition = "enter_chapel";
				}
			break;

			case "box4":
				if(CheckCharacterItem(chr,"mapBB4B"))
				{
					//map not repaired yet
					LAi_SetActorType(chr);	
					characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "U2_monastary";
					LAi_ActorSelfDialog(chr, "");
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_graveyard", "reload", "reload2_back");
				}



					



			/*
				if(CheckCharacterItem(chr,"mapBB4C"))
				{
					//map is repaired but maybe not exmined

				}
				else
				{
					LAi_SetActorType(pchar);	
					characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "U2_monastary";
					LAi_ActorSelfDialog(pchar, "");
				}
			*/



			/*
				if(CheckCharacterItem(chr,"mapBB4C"))
				{
					//map is repaired but maybe not exmined

				}
				else
				{
					if(CheckCharacterItem(chr,"mapBB4B"))
					{
						//tape not found



					}
					else
					{
						if(CheckCharacterItem(chr,"mapBB4A") || CheckCharacterItem(chr,"mapBB4A_back"))
						{


						}
					}
				}
			*/





		/*
				if(CheckCharacterItem(chr,"mapBB4B"))
				{
					//you have not repaired the map yet
					LAi_QuestDelay("pchar_hah", 0.1);
					Logit(TranslateString("","Hmm. That's not a good idea"));
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_graveyard", "reload", "reload2_back");
				}
		*/
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_refectory")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "BB_refectory", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "BB_refectory", "box", "box1");
			break;

			case "box3":
				Logit(TranslateString("","Kitchen"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box4":
				Logit(TranslateString("","Dormitorium"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box5":
				Logit(TranslateString("","Cellarium"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box6":
				Logit(TranslateString("","Chapter-house"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box7":
				Logit(TranslateString("","Scriptorium"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box8":
				Logit(TranslateString("","Cloister"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box9":
				Logit(TranslateString("","Infirmary"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box10":
				Logit(TranslateString("","Lavatorium"));
				PlaySound("INTERFACE\knock2.wav");
			break;
			
			case "box11":
				Logit(TranslateString("","Sacristy"));
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box12":
				Logit(TranslateString("","Church "));
				PlaySound("INTERFACE\knock2.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_abbess")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"abbess_map1") && chr.abbess_map1 == "seen")
				{
					return;
				}
				else
				{
					chr.abbess_map1 = "seen";
					PlaySound("OBJECTS\DUEL\man_attack6.wav");
				}								
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_church_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\paper.wav");
			break;	
		
			case "box2":
				if(CheckAttribute(chr,"church_room_box2") && chr.church_room_box2 == "on")
				{
					return;
				}
				else
				{
					chr.church_room_box2 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_church_room", 2.0);
				}				
			break;

			case "box3":
				Logit(TranslateString("","No, I'll only cut myself on those shards."));
				PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			break;

			case "box4":
				LaunchItemsBox(&ar);	

				LAi_QuestDelay("hammer_check_chapel", 0.1);							
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_bell_tower")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "graveyard_box1") && chr.graveyard_box1 == "disabled") return;

				if(CheckCharacterItem(chr,"bladehammer"))
				{
					if(LAi_IsFightMode(chr))
					{
						chr.graveyard_box1 = "disabled";
						PlaySound("AMBIENT\CHURCH\bell.wav");
						PlaySound("AMBIENT\CHURCH\bell.wav");

						LAi_QuestDelay("skip_fightmode", 1.0);
						LAi_QuestDelay("graveyard_bell", 5.0);
					}
					else
					{
						if(!IsEquipCharacterByItem(chr, "bladehammer"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladehammer");
						}
						LAi_SetPlayerType(chr);
						LAi_LocationFightDisable(&Locations[chr.location], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{
					chr.graveyard_box1 = "disabled";
					Logit(TranslateString("","The bell is too heavy - can't move it. I need something heavy to hit it with."));
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

					LAi_QuestDelay("graveyard_no_bell", 2.0);
				}					
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_crypt1")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;	

			case "box2":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);								
			break;

			case "box3":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);								
			break;

			case "box4":
				if(CheckAttribute(chr,"crypt1_coffin") && chr.crypt1_coffin == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt1_coffin = "closed";
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt1_coffin = "open";

					if(CheckAttribute(chr,"crypt_zombie") && chr.crypt_zombie == "defeated")
					{
						LaunchItemsBox(&ar);

						LAi_QuestDelay("broom_check_box4", 0.1);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("BB_crypt1")], false);
						ChangeCharacterAddressGroup(CharacterFromID("crypt_zombie1"), "BB_crypt1", "box", "box4");
						LAi_SetActorType(CharacterFromID("crypt_zombie1"));
						LAi_ActorAttack(CharacterFromID("crypt_zombie1"), chr, "");

						LAi_SetActorType(CharacterFromID("BB_nun1"));
						LAi_ActorTurnToLocator(CharacterFromID("BB_nun1"), "box", "box4");
					}	
				}						
			break;
		
			case "box5":
				if(CheckAttribute(chr,"crypt1_coffin") && chr.crypt1_coffin == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt1_coffin = "closed";
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt1_coffin = "open";

					
					if(CheckAttribute(chr,"crypt_zombie") && chr.crypt_zombie == "defeated")
					{
						LaunchItemsBox(&ar);

						LAi_QuestDelay("broom_check_box4", 0.1);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("BB_crypt1")], false);
						ChangeCharacterAddressGroup(CharacterFromID("crypt_zombie1"), "BB_crypt1", "box", "box5");
						LAi_SetActorType(CharacterFromID("crypt_zombie1"));
						LAi_ActorAttack(CharacterFromID("crypt_zombie1"), chr, "");

						LAi_SetActorType(CharacterFromID("BB_nun1"));
						LAi_ActorTurnToLocator(CharacterFromID("BB_nun1"), "box", "box4");
					}
				}						
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_crypt2_1")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;	

			case "box2":
				if(CheckAttribute(chr,"crypt2_1_box2") && chr.crypt2_1_box2 == "on")
				{
					return;
				}
				else
				{
					chr.crypt2_1_box2 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_crypt2_2", 2.0);
				}				
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_crypt2_2")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;	

			case "box5":
				if(CheckAttribute(chr,"crypt2_2_box5") && chr.crypt2_2_box5 == "on") return;

				
				if(CheckAttribute(chr,"crypt2_coffin5") && chr.crypt2_coffin5 == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt2_coffin5 = "closed";
					chr.crypt2_2_box5 = "on";

					LAi_QuestDelay("crypt_coffins_reset", 3.0);
					LAi_QuestDelay("crypt2_2_box5_off", 3.0);
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt2_coffin5 = "open";
					chr.crypt2_2_box5 = "on";

					if(CheckAttribute(chr,"coffins_sequence") && chr.coffins_sequence == "3")
					{
						chr.coffins_sequence = "4";	//OK!
						//last one, open to misericor, lock to 2_1

						LAi_QuestDelay("pchar_4", 3.0);
						LAi_QuestDelay("unlock_misericord", 4.5);
					}
					else
					{
						//skeleton pops up
					
						ChangeCharacterAddressGroup(chr, "BB_crypt2_2", "goto", "stuck5");
						LAi_LocationFightDisable(&Locations[chr.location], false);
						ChangeCharacterAddressGroup(characterFromID("crypt_skeleton5"), "BB_crypt2_2", "goto", "skeleton5");
						LAi_SetActorType(characterFromID("crypt_skeleton5"));
						LAi_ActorAttack(CharacterFromID("crypt_skeleton5"), chr, "");

						LAi_QuestDelay("crypt_skeletons_reset", 3.0);
						LAi_QuestDelay("crypt2_2_box5_off", 6.0);
						LAi_QuestDelay("crypt2_2_box5_reset_pchar", 6.0);
					}
				}
			break;

			case "box6":
				if(CheckAttribute(chr,"crypt2_2_box6") && chr.crypt2_2_box6 == "on") return;

				if(CheckAttribute(chr,"crypt2_coffin6") && chr.crypt2_coffin6 == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt2_coffin6 = "closed";
					chr.crypt2_2_box6 = "on";

					LAi_QuestDelay("crypt_coffins_reset", 3.0);
					LAi_QuestDelay("crypt2_2_box6_off", 3.0);
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt2_coffin6 = "open";
					chr.crypt2_2_box6 = "on";

					if(CheckAttribute(chr,"coffins_sequence") && chr.coffins_sequence == "0")
					{
						chr.coffins_sequence = "1";	//OK!

						LAi_QuestDelay("pchar_1", 3.0);
						LAi_QuestDelay("crypt2_2_box6_off", 3.0);
					}
					else
					{
						//skeleton pops up
					
						ChangeCharacterAddressGroup(chr, "BB_crypt2_2", "goto", "stuck6");
						LAi_LocationFightDisable(&Locations[chr.location], false);
						ChangeCharacterAddressGroup(characterFromID("crypt_skeleton6"), "BB_crypt2_2", "goto", "skeleton6");
						LAi_SetActorType(characterFromID("crypt_skeleton6"));
						LAi_ActorAttack(CharacterFromID("crypt_skeleton6"), chr, "");

						LAi_QuestDelay("crypt_skeletons_reset", 3.0);
						LAi_QuestDelay("crypt2_2_box6_off", 6.0);
						LAi_QuestDelay("crypt2_2_box6_reset_pchar", 6.0);
					}

					
				}								
			break;

			case "box7":
				if(CheckAttribute(chr,"crypt2_2_box7") && chr.crypt2_2_box7 == "on") return;

				if(CheckAttribute(chr,"crypt2_coffin7") && chr.crypt2_coffin7 == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt2_coffin7 = "closed";
					chr.crypt2_2_box7 = "on";

					LAi_QuestDelay("crypt_coffins_reset", 3.0);
					LAi_QuestDelay("crypt2_2_box7_off", 3.0);
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt2_coffin7 = "open";
					chr.crypt2_2_box7 = "on";

					if(CheckAttribute(chr,"coffins_sequence") && chr.coffins_sequence == "2")
					{
						chr.coffins_sequence = "3";	//OK!

						LAi_QuestDelay("pchar_3", 3.0);
						LAi_QuestDelay("crypt2_2_box7_off", 3.0);
					}
					else
					{
						//skeleton pops up
					
						ChangeCharacterAddressGroup(chr, "BB_crypt2_2", "goto", "stuck7");
						LAi_LocationFightDisable(&Locations[chr.location], false);
						ChangeCharacterAddressGroup(characterFromID("crypt_skeleton7"), "BB_crypt2_2", "goto", "skeleton7");
						LAi_SetActorType(characterFromID("crypt_skeleton7"));
						LAi_ActorAttack(CharacterFromID("crypt_skeleton7"), chr, "");

						LAi_QuestDelay("crypt_skeletons_reset", 3.0);
						LAi_QuestDelay("crypt2_2_box7_off", 6.0);
						LAi_QuestDelay("crypt2_2_box7_reset_pchar", 6.0);
					}
				}
			break;

			case "box8":
				if(CheckAttribute(chr,"crypt2_2_box8") && chr.crypt2_2_box8 == "on") return;

				if(CheckAttribute(chr,"crypt2_coffin8") && chr.crypt2_coffin8 == "open")
				{
					PlaySound("INTERFACE\shelf_close.wav");
					chr.crypt2_coffin8 = "closed";
					chr.crypt2_2_box8 = "on";

					LAi_QuestDelay("crypt_coffins_reset", 3.0);
					LAi_QuestDelay("crypt2_2_box8_off", 3.0);
				}
				else
				{
					PlaySound("INTERFACE\shelf_open.wav");	
					chr.crypt2_coffin8 = "open";
					chr.crypt2_2_box8 = "on";

					if(CheckAttribute(chr,"coffins_sequence") && chr.coffins_sequence == "1")
					{
						chr.coffins_sequence = "2";	//OK!

						LAi_QuestDelay("pchar_2", 3.0);
						LAi_QuestDelay("crypt2_2_box8_off", 3.0);
					}
					else
					{
						//skeleton pops up
					
						ChangeCharacterAddressGroup(chr, "BB_crypt2_2", "goto", "stuck8");
						LAi_LocationFightDisable(&Locations[chr.location], false);
						ChangeCharacterAddressGroup(characterFromID("crypt_skeleton8"), "BB_crypt2_2", "goto", "skeleton8");
						LAi_SetActorType(characterFromID("crypt_skeleton8"));
						LAi_ActorAttack(CharacterFromID("crypt_skeleton8"), chr, "");

						LAi_QuestDelay("crypt_skeletons_reset", 3.0);
						LAi_QuestDelay("crypt2_2_box8_off", 6.0);
						LAi_QuestDelay("crypt2_2_box8_reset_pchar", 6.0);
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_abbey_cell")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
				Logit(TranslateString("","Poor nun!"));
			break;

			case "box3":
				if(Locations[FindLocation(chr.location)].models.always.l2 == "straw")
				{
					if(CheckCharacterItem(chr,"bladebroom"))
					{
						if(LAi_IsFightMode(chr))
						{
							if(CheckAttribute(chr,"misericord_box3") && chr.misericord_box3 == "on") return;

							if(CheckAttribute(chr, "broom_straw") && chr.broom_straw == "phase2")
							{
								chr.misericord_box3 = "on";
								PlaySound("PEOPLE\grass_noise.wav");
								CreateParticleSystemX("blast_dirt", -13.6, 0.2, -0.8, -13.6, 0.2, -0.8, 10);							

								LAi_QuestDelay("broom_in_misericord", 2.0);
							}
							else
							{
								if(CheckAttribute(chr, "broom_straw") && chr.broom_straw == "phase1")
								{
									chr.misericord_box3 = "on";
									PlaySound("PEOPLE\grass_noise.wav");
									CreateParticleSystemX("blast_dirt", -13.6, 0.2, -0.8, -13.6, 0.2, -0.8, 10);							

									chr.broom_straw = "phase2";

									LAi_QuestDelay("broom_in_misericord_free", 1.0);
								}
								else
								{
									chr.misericord_box3 = "on";
									PlaySound("PEOPLE\grass_noise.wav");
									CreateParticleSystemX("blast_dirt", -13.6, 0.2, -0.8, -13.6, 0.2, -0.8, 10);
								
									chr.broom_straw = "phase1";

									LAi_QuestDelay("broom_in_misericord_free", 1.0);
								}
							}			
						}
						else
						{
							if(!IsEquipCharacterByItem(chr, "bladebroom"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladebroom");
							}
							LAi_SetPlayerType(chr);
							LAi_LocationFightDisable(&Locations[chr.location], false);
						 	LAi_SetFightMode(chr, true);
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
						Logit(TranslateString("","Something under that straw?"));

						if(CheckAttribute(chr, "miseri_first_time") && chr.miseri_first_time == "done")
						{

						}
						else
						{
							chr.miseri_first_time = "done";

							chr.quest.unlock_crypt1.win_condition.l1 = "location";
							chr.quest.unlock_crypt1.win_condition.l1.location = "bb_graveyard";
							chr.quest.unlock_crypt1.win_condition = "unlock_crypt1";
						}
					}
				}
				else
				{
					LaunchItemsBox(&ar);	


					
				}
			break;

			case "box4":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("pistolcenser_check_misericord", 0.1);
			break;
		}

		return;
	}

//CAESAR
//-------------------------------------------------------------------------------------------------------------
	if(Locations[locidx].id=="Turks_port")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators";
				Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_day";
				Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_night";
				DoQuestReloadToLocation("Turks_tavern_bedroom", "goto", "box4", "_");
			break;

			case "box3":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Turks_port", "quest", "step_up2");
			break;

			case "box4":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Turks_port", "quest", "step_up2");
			break;

			case "box5":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Turks_to_step_up1", 0.5);
			break;

			case "box6":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Turks_to_box6", 0.5);
			break;

			case "box7":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Turks_to_step_up3", 0.5);
			break;

			case "box8":
				ChangeCharacterAddressGroup(chr, "Turks_port", "box", "box8");
				PlaySound("PEOPLE\recoil.wav");
				LAi_SetPoorType(chr);
				chr.Turks_creep = "yes";
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box8", 0.0001);
				Locations[FindLocation("Turks_port")].locators_radius.box.box8 = 0.0001;

				LAi_QuestDelay("Turks_to_fight2", 1.0);
			break;

			case "box9":
				//boat from cave

				if(CheckAttribute(chr, "Caesar_GPS") && chr.Caesar_GPS == "visited")
				{
					if(Locations[FindLocation("Turks_port")].models.always.l10 == "")	
					{
						//watergate down (+ flooded + closed hatch)

						Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_day";
						Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_night";
						DoQuestReloadToLocation("Turks_port", "reload", "town", "_");
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","The Gate is blocking the way out."));
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					Logit(TranslateString("","That boat could be the way back to the Port."));
				}
			break;

			case "box10":
				//boat from Port

				if(CheckCharacterItem(chr,"mapBB2A") || CheckCharacterItem(chr,"mapBB2B"))
				{
					PlaySound("VOICE\ENGLISH\Odel_no.wav");
					Logit(TranslateString("","No, I have no more business there."));
				}
				else
				{
					Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_roof";
					Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_roof";
					DoQuestReloadToLocation("Turks_port", "quest", "boat_cave", "_");
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Turks_Fort_Office")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box2":	
				PlaySound("INTERFACE\knock2.wav");
			break;

			case "box3":
				PlaySound("INTERFACE\rum_barrel_empty.wav");
			break;

			case "box4":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box5":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box6":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box7":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Turks_Fort_Office", "goto", "stay");

				LAi_QuestDelay("Turks_armory_turn_to_gpb", 0.7);
			break;

			case "box8":
				PlaySound("OBJECTS\DUEL\reload1.wav");
			break;

			case "box9":
				PlaySound("OBJECTS\DUEL\reload1.wav");
			break;

			case "box10":
				PlaySound("PEOPLE\place_planks.wav");
			break;

			case "box11":
				PlaySound("PEOPLE\place_planks.wav");
			break;


		}
		return;
	}

	if(Locations[locidx].id=="Turks_Jungle_03")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckCharacterItem(chr,"bladebarrel_gpS") && CheckCharacterItem(chr,"pistolbarrel_gpS"))
				{
					if(IsEquipCharacterByItem(chr, "bladebarrel_gpS") && IsEquipCharacterByItem(chr, "pistolbarrel_gpS"))
					{
						LAi_SetSitType(chr);
						PlaySound("PEOPLE\jump.wav");
						RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "pistolbarrel_gpS" );
						TakeItemFromCharacter(chr, "bladebarrel_gpS" );

						LAi_QuestDelay("Turks_place_barrels", 0.5);
					}
					else
					{
						RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladebarrel_gpS");
						EquipCharacterByItem(chr, "pistolbarrel_gpS");
					}
				}
				else
				{
					//light the fuse
					LAi_SetSitType(chr);
					CreateParticleSystem("fort_fire" , 27.7, 0.5, 1.1, 0.0, 0.0, 0.0, sti(20) );
					PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");
				
					LAi_QuestDelay("pchar_playertype", 0.5);
					LAi_QuestDelay("bomb_lit", 3.0);
					LAi_QuestDelay("bomb_lit", 6.0);
					LAi_QuestDelay("Turks_gate_explosion", 9.0);
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Turks_tavern_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Turks_tavern_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("longrifle_equip_check", 0.1);
			break;			

			case "box4":
				SetNextWeather("Clear");
				locations[FindLocation("Turks_port")].type = "silent_seashore";
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_roof";
				Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_roof";

				DoQuestReloadToLocation("Turks_port", "box", "box2", "_");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Turks_balcony_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Turks_wreck_shore")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\anchor_up.wav");
				ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box4");
			break;

			case "box4":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("OBJECTS\SHIPCHARGE\ball_splash1.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "quest", "splash");
					chr.wreck_shore_mast = "way_up";
				}
				else
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box5");
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box4");

					LAi_QuestDelay("Turks_shore_turn_to_splash", 0.5);
				}
				else
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box6");
				}
			break;

			case "box6":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box5");
				}
				else
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					PlaySound("PEOPLE\recoil.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box10");
				}
			break;

			case "box10":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\step_wood.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box6");
				}
				else
				{
					PlaySound("PEOPLE\jump_counter.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "quest", "railing");

					LAi_QuestDelay("Turks_shore_to_box7", 0.5);
				}
			break;

			case "box7":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\jump_counter.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "quest", "railing");

					LAi_QuestDelay("Turks_shore_to_box10", 0.5);
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box8");
				}
			break;

			case "box8":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box7");
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box9");
				}
			break;

			case "box9":
				if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_down")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box8");
				}
				else
				{
					if(CheckAttribute(chr, "wreck_shore_mast") && chr.wreck_shore_mast == "way_up")
					{
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "box", "box8");
						chr.wreck_shore_mast = "way_down";
					}	
				}
				else
				{
					//only first time
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Turks_wreck_shore", "quest", "bottle");
					chr.wreck_shore_mast = "way_down";
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_sloop_wreck_cabin")
	{
		switch(chr.boxname)
		{
			case "box1":
				SetNextWeather("Clear");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("wreck_cabin_empty_box1", 0.1);
			break;

			case "box2":
						SetNextWeather("Clear");
						if(LAi_IsFightMode(chr))
						{
							//second 'open box'

							switch(Locations[FindLocation(chr.location)].models.always.l2)
							{
								case "":
									if(CheckCharacterItem(chr,"blade_gp_dry"))
									{
										if(!IsEquipCharacterByItem(chr, "blade_gp_dry"))
										{
											RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										}
										TakeItemFromCharacter(chr, "blade_gp_dry");
										EquipCharacterByItem(chr, "bladeX4");
										PlaySound("PEOPLE\step_stairway2.wav");
								
										LAi_QuestDelay("place_gp_dry", 1.0);
									}
								break;

								case "gp_dry":
									if(IsEquipCharacterByItem(chr, "bladebottle_CB2"))
									{
										PlaySound("AMBIENT\TAVERN\open_bottle.wav");
										TakeItemFromCharacter(chr, "bladebottle_CB2");
										GiveItem2Character(chr,"bladebottle_CE0");
										EquipCharacterByItem(chr, "bladebottle_CE0");

										LAi_QuestDelay("wine_on_gp_dry", 0.5);
									}

									if(IsEquipCharacterByItem(chr, "Barmansknife"))
									{
										PlaySound("PEOPLE\chopchop.wav");

										LAi_QuestDelay("gpmap_free", 1.0);
									}
								break;

								case "gp_wet":
									if(IsEquipCharacterByItem(chr, "bladeX4") || IsEquipCharacterByItem(chr, "Barmansknife"))
									{
										if(Locations[FindLocation("BB_sloop_wreck_cabin")].models.always.locators == "capsm_l_KR_map1")
										{
											PlaySound("PEOPLE\dig_sand.wav");

											LAi_QuestDelay("hand_on_gp_wet", 1.0);
										}
									}
								break;
							}
						}
						else
						{
							//first 'open box'
						
							switch(Locations[FindLocation(chr.location)].models.always.l2)
							{
								case "":
									if(CheckCharacterItem(chr,"blade_gp_dry"))
									{
										if(!IsEquipCharacterByItem(chr, "blade_gp_dry"))
										{
											RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
											EquipCharacterByItem(chr, "blade_gp_dry");
										}

										ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
										LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
										LAi_SetFightMode(chr, true);

										LAi_QuestDelay("stuck_at_gpmap", 1.0);
									}
									else LAi_QuestDelay("pchar_huh", 0.1);
								break;

								case "gp_dry":
									if(IsEquipCharacterByItem(chr, "Barmansknife") && IsEquipCharacterByItem(chr, "pistolhammer"))
									{
										ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
										LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
										LAi_SetFightMode(chr, true);
									}
									else
									{
										if(IsEquipCharacterByItem(chr, "pistolhammer"))
										{
											ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
											LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
											LAi_SetFightMode(chr, true);
										}
										else
										{
											if(IsEquipCharacterByItem(chr, "Barmansknife"))
											{
												ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
												LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
												LAi_SetFightMode(chr, true);
											}
										}
									}

									if(IsEquipCharacterByItem(chr, "bladebottle_CB2"))
									{
										ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
										LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
										LAi_SetFightMode(chr, true);
									}

									LAi_QuestDelay("stuck_at_gpmap", 1.0);
								break;

								case "gp_wet":
									if(IsEquipCharacterByItem(chr, "bladeX4"))
									{
										if(Locations[FindLocation("BB_sloop_wreck_cabin")].models.always.locators == "capsm_l_KR_map1")
										{
											ChangeCharacterAddressGroup(chr, "BB_sloop_wreck_cabin", "goto", "stuck");
											LAi_LocationFightDisable(&Locations[FindLocation("BB_sloop_wreck_cabin")], false);
											LAi_SetFightMode(chr, true);
										}
									}

									LAi_QuestDelay("stuck_at_gpmap", 1.0);
								break;

							}
						}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_sloop_wreck_hold")
	{
		switch(chr.boxname)
		{
			case "box1":
				chr.Caesar_GPS = "visited";
				SetNextWeather("Clear");
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"Caesar_info") && chr.Caesar_info == "no")
				{
					if(CheckAttribute(chr,"return_to_GPS") && chr.return_to_GPS == "done")
					{
						return;
					}
					else LAi_QuestDelay("return_to_wreck_hold", 0.1);
				}
			break;
		}

		return;
	}

//HANDS
	if(Locations[locidx].id=="bb_Maltains")
	{
		switch(chr.boxname)
		{
			case "box34":
				//bars up

				if(locations[FindLocation("bb_Maltains")].models.always.l2 == "bars_down")
				{
					PlaySound("INTERFACE\lever_up.wav");
					locations[FindLocation("bb_Maltains")].models.always.l2 = "bars_up";
					Locations[FindLocation("bb_Maltains")].reload.l3.disable = 0;
					Locations[FindLocation("Charlestown_port")].reload.l18.disable = 0;
					Locations[FindLocation("Charlestown_port")].reload.l18.close_for_day = 1;

					LAi_QuestDelay("maltains_bars_up", 1.0);
				}
				else PlaySound("INTERFACE\lever_stuck.wav");
			break;

			case "box35":
				//bars down

				if(locations[FindLocation("bb_Maltains")].models.always.l2 == "bars_up")
				{
					PlaySound("INTERFACE\lever_down.wav");
					locations[FindLocation("bb_Maltains")].models.always.l2 = "bars_down";
					Locations[FindLocation("bb_Maltains")].reload.l3.disable = 1;
					Locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;
					Locations[FindLocation("Charlestown_port")].reload.l18.close_for_day = 0;

					LAi_QuestDelay("maltains_bars_down", 1.0);
				}
				else PlaySound("INTERFACE\lever_stuck.wav");
			break;
			
			//------------------------------------------------------------------------------------
			
			case "box1":
				//nr4

				if(CheckAttribute(chr, "cell1") && chr.cell1 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell1 = "open";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "3")
						{
							chr.unlocked_cells = "4";

							LAi_QuestDelay("pchar_4", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_lock.wav");
						chr.cell1 = "locked";

						LAi_QuestDelay("reset_cells", 1.0);
					}
				}
			break;

			case "box3":
				//nr3

				if(CheckAttribute(chr, "cell3") && chr.cell3 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell3 = "open";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "2")
						{
							chr.unlocked_cells = "3";

							LAi_QuestDelay("pchar_3", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_lock.wav");
						chr.cell3 = "locked";

						LAi_QuestDelay("reset_cells", 1.0);
					}
				}
			break;

			case "box5":
				//nr7

				if(CheckAttribute(chr, "cell5") && chr.cell5 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell5 = "open";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "6")
						{
							chr.unlocked_cells = "7";

							LAi_QuestDelay("pchar_7", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_lock.wav");
						chr.cell5= "locked";

						LAi_QuestDelay("reset_cells", 1.0);
					}
				}
			break;

			case "box7":
				//nr2

				if(CheckAttribute(chr, "cell7") && chr.cell7 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}		

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell7 = "open";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "1")
						{
							chr.unlocked_cells = "2";

							LAi_QuestDelay("pchar_2", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_lock.wav");
						chr.cell7 = "locked";

						LAi_QuestDelay("reset_cells", 1.0);
					}
				}
			break;

			case "box9":
				//nr1

				if(CheckAttribute(chr, "cell9") && chr.cell9 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell9 = "open";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "0")
						{
							chr.unlocked_cells = "1";

							LAi_QuestDelay("pchar_1", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_lock.wav");
						chr.cell9 = "locked";

						LAi_QuestDelay("reset_cells", 1.0);
					}
				}
			break;

			case "box11":
				PlaySound("VOICE\ENGLISH\pir_capHH.wav");
				Logit(TranslateString("","It's not time for any meal now."));
			break;

			case "box13":
				PlaySound("VOICE\ENGLISH\gm_crew1C.wav");
				Logit(TranslateString("","Hey, it's occupied."));
			break;

			//----------------------------------------------------------------------

			case "box2":
				//nr9

				if(CheckAttribute(chr, "cell2_blocked") && chr.cell2_blocked == "yes") return;

				if(CheckAttribute(chr, "cell2") && chr.cell2 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell2 = "enter";

						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "8")
						{
							chr.unlocked_cells = "9";

							LAi_QuestDelay("pchar_9", 1.0);
						}
						else 
						{
							chr.cell2_blocked = "yes";

							LAi_QuestDelay("reset_cells", 1.0);
						}		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckAttribute(chr, "cell2") && chr.cell2 == "enter")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box4");
						chr.cell2 = "open";
					}
					else
					{
						if(CheckCharacterItem(chr,"bladekeyring"))
						{
							if(!IsEquipCharacterByItem(chr, "bladekeyring"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladekeyring");
							}

							PlaySound("INTERFACE\key_lock.wav");
							chr.cell2 = "locked";

							LAi_QuestDelay("reset_cells", 1.0);
						}
					}
				}
			break;

			case "box4":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box6");
			break;

			case "box6":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("maltains_to_box8", 0.1);
			break;

			case "box8":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("maltains_to_box10", 0.1);
			break;

			case "box10":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box12");
			break;

			case "box12":
				PlaySound("INTERFACE\metal_hatch_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("maltains_to_box14", 0.1);
			break;

			case "box14":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box2");
			break;

			//----------------------------------------------------------------------

			case "box15":
				//nr6

				if(CheckAttribute(chr, "cell15_blocked") && chr.cell15_blocked == "yes") return;

				if(CheckAttribute(chr, "cell15") && chr.cell15 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						
						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "5")
						{
							chr.cell15 = "enter";
							chr.unlocked_cells = "6";

							LAi_QuestDelay("pchar_6", 1.0);
						}
						else 
						{
							chr.cell15_blocked = "yes";
							chr.cell15 = "open";
							LAi_QuestDelay("reset_cells", 1.0);
						}		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckAttribute(chr, "cell15") && chr.cell15 == "enter")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box16");
						chr.cell15 = "open";
					}
					else
					{
						if(CheckCharacterItem(chr,"bladekeyring"))
						{
							if(!IsEquipCharacterByItem(chr, "bladekeyring"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladekeyring");
							}

							PlaySound("INTERFACE\key_lock.wav");
							chr.cell15 = "locked";

							LAi_QuestDelay("reset_cells", 1.0);
						}
					}
				}
			break;

			case "box16":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box15");
			break;

			case "box17":
				//nr5

				if(CheckAttribute(chr, "cell17_blocked") && chr.cell17_blocked == "yes") return;

				if(CheckAttribute(chr, "cell17") && chr.cell17 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						
						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "4")
						{
							chr.cell17 = "enter";
							chr.unlocked_cells = "5";

							LAi_QuestDelay("pchar_5", 1.0);
						}
						else 
						{
							chr.cell17_blocked = "yes";
							chr.cell17 = "open";

							LAi_QuestDelay("reset_cells", 1.0);
						}		
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckAttribute(chr, "cell17") && chr.cell17 == "enter")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box18");
						chr.cell17 = "open";
					}
					else
					{
						if(CheckCharacterItem(chr,"bladekeyring"))
						{
							if(!IsEquipCharacterByItem(chr, "bladekeyring"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladekeyring");
							}

							PlaySound("INTERFACE\key_lock.wav");
							chr.cell17 = "locked";

							LAi_QuestDelay("reset_cells", 1.0);
						}
					}
				}
			break;

			case "box18":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box17");
			break;

			case "box19":
				//nr8

				if(CheckAttribute(chr, "cell19_blocked") && chr.cell19_blocked == "yes") return;

				if(CheckAttribute(chr, "cell19") && chr.cell19 == "locked")
				{
					if(CheckCharacterItem(chr,"bladekeyring"))
					{
						if(!IsEquipCharacterByItem(chr, "bladekeyring"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladekeyring");
						}

						PlaySound("INTERFACE\key_unlock2.wav");
						
						if(CheckAttribute(chr, "unlocked_cells") && chr.unlocked_cells == "7")
						{
							chr.cell19 = "enter";
							chr.unlocked_cells = "8";

							LAi_QuestDelay("pchar_8", 1.0);
						}
						else 
						{
							chr.cell19_blocked = "yes";
							chr.cell19 = "open";
							
							LAi_QuestDelay("reset_cells", 1.0);	
						}	
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckAttribute(chr, "cell19") && chr.cell19 == "enter")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box20");
						chr.cell19 = "open";

						if(!CheckCharacterItem(chr,"book67")) LAi_QuestDelay("pillow_check", 0.1);
					}
					else
					{
						if(CheckCharacterItem(chr,"bladekeyring"))
						{
							if(!IsEquipCharacterByItem(chr, "bladekeyring"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladekeyring");
							}
					
							PlaySound("INTERFACE\key_lock.wav");
							chr.cell19 = "locked";

							LAi_QuestDelay("reset_cells", 1.0);
						}
					}
				}
			break;

			case "box20":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box19");
			break;

			//------------------------------------------------------------------------------------

			case "box21":
				if(CheckCharacterItem(chr,"key34"))
				{
					if(CheckAttribute(chr,"quest.malta_box21") && chr.quest.malta_box1 == "on")
					{
						return;
					}
					else
					{
						chr.quest.malta_box21 = "on";
						PlaySound("INTERFACE\key_unlock.wav");

						LAi_QuestDelay("unlock_Malta_secret", 2.0);
					}
				}
			break;

			//------------------------------------------------------------------------------------

			case "box25":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				LAi_QuestDelay("maltains_to_box26", 0.5);
			break;

			case "box26":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				LAi_QuestDelay("maltains_to_box27", 0.5);
			break;

			case "box27":
				PlaySound("PEOPLE\run_wood.wav");	
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "quest", "quest1");

				LAi_QuestDelay("maltains_to_box28", 0.75);
			break;

			case "box28":
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box29");

				LAi_QuestDelay("maltains_turn_to_box30", 0.5);
			break;

			case "box22":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box23":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box24":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box29":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
			
				LAi_QuestDelay("maltains_to_box30", 0.5);
			break;

			case "box30":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("maltains_to_box32", 0.1);
			break;

			case "box32":
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "box", "box33");
				LAi_SetSitType(chr);

				LAi_QuestDelay("maltains_turn_to_quest3", 0.5);
			break;

			case "box33":
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "bb_Maltains", "quest", "quest3");
				LAi_SetSitType(chr);

				LAi_QuestDelay("maltains_turn_to_box9", 0.25);
			break;

			case "box31":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}
//-------------------------------------------------------------------------------------------------------------
	if(Locations[locidx].id=="Antigua_port")
	{
		switch(chr.boxname)
		{
			case "box6":
				PlaySound("INTERFACE\knock2.wav");			
				SetLocatorRadius(locations[FindLocation("Antigua_port")], "box", "box6", 0.001);	//only once
				Locations[FindLocation("Antigua_port")].locators_radius.box.box6 = 0.001;
				SetLocatorRadius(locations[FindLocation("Antigua_port")], "reload", "reload7_back", 1.5);
				Locations[FindLocation("Antigua_port")].locators_radius.reload.reload7_back = 1.5;

				LAi_QuestDelay("Antigua_fort", 1.0);
				return;
			break;

			case "box7":
				if(CheckAttribute(chr, "prison_escape") && chr.prison_escape == "phase2")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Antigua_port", "reload", "reload10");
					LAi_SetPlayerType(chr);

					chr.quest.prison_2_escape8.win_condition.l1 = "location";
					chr.quest.prison_2_escape8.win_condition.l1.location = "Antigua_yard";
					chr.quest.prison_2_escape8.win_condition = "prison_2_escape8";

					LAi_QuestDelay("prison_2_escape7", 1.0);
				}
				else
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "reload", "reload10");

					if(IsOfficer(CharacterFromID("Caesar"))) chr.Caesar_officer = "yes";				
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Hands"));
					RemovePassenger(chr, characterFromID("Pell"));
					RemovePassenger(chr, characterFromID("Caesar"));

					AddPassenger(chr, characterFromID("Hands"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Hands"));
			//		ChangeCharacterAddressGroup(characterFromID("Hands"), "Antigua_port", "officers", "reload5_1");
					LAi_SetOfficerType(characterFromID("Hands"));

					AddPassenger(chr, characterFromID("Pell"), 0);
					SetOfficersIndex(chr, 2, getCharacterIndex("Pell"));
			//		ChangeCharacterAddressGroup(characterFromID("Pell"), "Antigua_port", "officers", "reload5_2");
					LAi_SetOfficerType(characterFromID("Pell"));

					if(CheckAttribute(chr,"Caesar_officer") && chr.Caesar_officer == "yes")
					{
						AddPassenger(chr, characterFromID("Caesar"), 0);
						SetOfficersIndex(chr, 3, getCharacterIndex("Caesar"));
			//			ChangeCharacterAddressGroup(characterFromID("Pell"), "Antigua_port", "officers", "reload5_3");
						LAi_SetOfficerType(characterFromID("Caesar"));
					}

					LAi_QuestDelay("prison_2_escape6", 1.0);
				}
			break;
		}
		return;
	}
//-------------------------------------------------------------------------------------------------------------
	if(Locations[locidx].id=="bb_prison_port")
	{
		switch(chr.boxname)
		{
			case "box1":
				//arrived to prison pier

				if(CheckAttribute(chr, "quest.prison_pier") && chr.quest.prison_pier == "phase6")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_port", "reload", "prison_door");
				}
				
				if(CheckAttribute(chr, "quest.prison_pier") && chr.quest.prison_pier == "phase5")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "reload", "prison_door");
					
					LAi_QuestDelay("prison_pier_phase6", 1.0);
				}

				if(CheckAttribute(chr, "quest.prison_pier") && chr.quest.prison_pier == "phase4")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "turn2");
					
					LAi_QuestDelay("prison_pier_phase5", 1.0);
				}
				
				if(CheckAttribute(chr, "quest.prison_pier") && chr.quest.prison_pier == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "randitem", "randitem2");
					
					LAi_QuestDelay("prison_pier_phase3", 1.0);
				}
			break;

			case "box2":
				//depart from port

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_sky = "2_Rd";

				Locations[FindLocation("bb_prison_port")].image = "wr_prison_pier.tga";
				DoQuestReloadToLocation("bb_prison_port", "goto", "prison_entre", "arrive_prison_pier");
			break;

			case "box3":
				//start bridge

				if(CheckAttribute(chr, "quest.prison_bridge") && chr.quest.prison_bridge == "start")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_port", "goto", "reload1");

					chr.quest.pchar_playertype.win_condition.l1 = "location";
					chr.quest.pchar_playertype.win_condition.l1.location = "bb_prison_alcove";
					chr.quest.pchar_playertype.win_condition = "pchar_playertype";
				}
				else
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "reload1");
					LAi_SetActorType(characterFromID("P2_guard_bridge1"));
					LAi_SetActorType(characterFromID("P2_guard_bridge2"));
					LAi_ActorTurnToLocator(characterFromID("P2_guard_bridge1"), "reload", "reload3");
					LAi_ActorTurnToLocator(characterFromID("P2_guard_bridge2"), "reload", "reload3");

					LAi_QuestDelay("prison_bridge_start_turn", 1.0);
				}
			break;

			case "box4":
				//end of the bridge
				
				if(CheckAttribute(chr, "quest.prison_bridge") && chr.quest.prison_bridge == "end")
				{
					DoQuestReloadToLocation("bb_prison_alcove", "reload", "reload1", "pchar_playertype");
				}
				else
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "see_door1");

					LAi_QuestDelay("prison_bridge_end_turn", 1.0);
				}
			break;

			case "box5":
				//return to prison pier

				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_port", "goto", "goto6");
			break;

			case "box6":
				//return to port

				SetCurrentTime(21, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "Clear";

				chr.quest.prison_pier = "phase7";
				Locations[FindLocation("bb_prison_port")].image = "Town_IslaMuelle_Port.tga";
				DoQuestReloadToLocation("bb_prison_port", "goto", "return", "return_prison_pier");
			break;

			case "box7":
				//return to elevator from prison

				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_port", "box", "box8");
			break;

			case "box8":
				//return to elevator from prison

				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_port", "reload", "reload3");

				LAi_QuestDelay("prison_bridge_extra_turn", 0.1);

				chr.quest.pchar_playertype.win_condition.l1 = "locator";
				chr.quest.pchar_playertype.win_condition.l1.location = "bb_prison_elevator";
				chr.quest.pchar_playertype.win_condition.l1.locator_group = "goto";
				chr.quest.pchar_playertype.win_condition.l1.locator = "goto4";
				chr.quest.pchar_playertype.win_condition = "pchar_playertype";
			break;
		}
		return;
	}

	if(Locations[locidx].id=="bb_prison_elevator")
	{
		switch(chr.boxname)
		{
			case "box1":
				//up button

				if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "down")
				{
					Locations[FindLocation("bb_prison_elevator")].reload.l1.disable = 1;
					Locations[FindLocation("bb_prison_elevator")].reload.l2.disable = 1;
					PlaySound("INTERFACE\elevator_1.wav");
					chr.quest.prison_elevator = "moving";

					LAi_QuestDelay("bb_prison_elevator_up", 8.0);
				}
				else
				{ 
					PlaySound("INTERFACE\lever_stuck.wav");

					if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "up")
					{
						LAi_QuestDelay("bb_prison_elevator_already_up", 1.0);
					}
				}
			break;

			case "box2":
				//down button

				if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "up")
				{
					Locations[FindLocation("bb_prison_elevator")].reload.l1.disable = 1;
					Locations[FindLocation("bb_prison_elevator")].reload.l2.disable = 1;
					PlaySound("INTERFACE\elevator_1.wav");
					chr.quest.prison_elevator = "moving";

					LAi_QuestDelay("bb_prison_elevator_down", 8.0);
				}
				else
				{ 
					PlaySound("INTERFACE\lever_stuck.wav");

					if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "down")
					{
						LAi_QuestDelay("bb_prison_elevator_already_down", 1.0);
					}
				}
			break;

			case "box3":
				//to pier

				if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "down")
				{
					LAi_SetStayType(chr);
					Locations[FindLocation("bb_prison_port")].image = "wr_prison_pier.tga";
					DoQuestReloadToLocation("bb_prison_port", "goto", "goto5", "turn_prison_port_guards");
				}
				else
				{ 
					PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box4":
				//to bridge

				if(CheckAttribute(chr, "quest.prison_elevator") && chr.quest.prison_elevator == "up")
				{
					Locations[FindLocation("bb_prison_port")].image = "wr_prison_bridge.tga";
					DoQuestReloadToLocation("bb_prison_port", "goto", "prison_bridgeA", "prison_bridge_extra_turn");
				}
				else
				{ 
					PlaySound("INTERFACE\locked_window.wav");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="bb_prison_alcove")
	{
		switch(chr.boxname)
		{
			case "box1":
				//fallen crate, down

				PlaySound("PEOPLE\step_stairway.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "goto1");
			break;

			case "box2":
				//fallen crate, up

				PlaySound("PEOPLE\step_stairway.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "goto2");
			break;

			case "box3":
				//swing rope forward

				LAi_SetSitType(chr);
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "goto3");

				LAi_QuestDelay("swing_alcove_rope", 0.5);
			break;

			case "box4":
				//swing rope back

				if(CheckAttribute(chr, "alcove.rope") && chr.alcove.rope == "at_gibbet")
				{
					LAi_SetSitType(chr);
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "goto4");

					LAi_QuestDelay("swing_alcove_rope", 0.5);
				}
				else
				{
					if(CheckCharacterItem(chr,"raft_ropes"))
					{
						if(LAi_IsFightMode(chr))
						{
							PlaySound("PEOPLE\clothes1.wav");
							Locations[FindLocation("bb_prison_alcove")].models.always.l3 = "rope_gibbet";
							TakeItemFromCharacter(chr, "raft_ropes");

							LAi_QuestDelay("place_alcove_rope", 0.5);
						}
						else
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							if(!CheckCharacterItem(chr,"bladeX4")) GiveItem2Character(chr, "bladeX4");
							EquipCharacterByItem(chr, "bladeX4");
						 	LAi_SetFightMode(chr, true);
						}
					}
					else
					{
						Logit(TranslateString("","I'll need a Rope here."));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					}
				}
			break;

			case "box5":
				//upper crate start side

				if(CheckAttribute(chr, "alcove.crate") && chr.alcove.crate == "fallen_down")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "crate5_2");

					LAi_QuestDelay("alcove_box5_jump", 0.5);
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "crate5_1");

					LAi_QuestDelay("alcove_box5_jump", 0.5);
				}
				
			break;

			case "box6":
				//upper crate other side

				if(CheckAttribute(chr, "alcove.crate") && chr.alcove.crate == "fallen_down")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "crate6_2");

					LAi_QuestDelay("alcove_box6_jump", 0.5);
				}
				else
				{
					if(CheckCharacterItem(chr,"bladeboom"))
					{
						if(LAi_IsFightMode(chr))
						{
							PlaySound("PEOPLE\creak2.wav");

							LAi_QuestDelay("push_alcove_crate", 1.0);
						}
						else
						{
							if(!IsEquipCharacterByItem(chr, "bladeboom"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeboom");
							}
							LAi_SetPlayerType(chr);
						 	LAi_SetFightMode(chr, true);
						}
					}
					else
					{
						LAi_SetSitType(chr);
						PlaySound("PEOPLE\step_stairway.wav");
						ChangeCharacterAddressGroup(chr, "bb_prison_alcove", "goto", "crate6_1");

						LAi_QuestDelay("alcove_box6_jump", 0.5);
					}
				}
			break;

			case "box7":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;

			case "box8":
				if(CheckCharacterItem(chr,"key3"))
				{
					PlaySound("INTERFACE\key_unlock2.wav");

					LAi_QuestDelay("unlock_bb_prison", 1.0);								
				}
				else
				{
					Logit(TranslateString("","Rotunda lower levels"));
					PlaySound("INTERFACE\locked_window.wav");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="bb_prison")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner7"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner7"), "box", "box8", "prisoner7_stay", 2.0);
			break;

			case "box3":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner6"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner6"), "box", "box9", "prisoner6_stay", 2.0);
			break;

			case "box4":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner5"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner5"), "box", "box10", "prisoner5_stay", 2.0);
			break;

			case "box5":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner4"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner4"), "box", "box11", "prisoner4_stay", 2.0);
			break;

			case "box6":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner8"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner8"), "box", "box12", "prisoner8_stay", 2.0);
			break;

			case "box7":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner9"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner9"), "box", "box13", "prisoner9_stay", 2.0);
			break;

			case "box8":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box2");
			break;

			case "box9":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box3");
			break;

			case "box10":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box4");
			break;

			case "box11":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box5");
			break;

			case "box12":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box6");
			break;

			case "box13":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box7");
			break;

			case "box14":
				//open cell
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box21");
			break;

			case "box15":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner1"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner1"), "box", "box22", "prisoner1_stay", 2.0);
			break;

			case "box16":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner2"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner2"), "box", "box23", "prisoner2_stay", 2.0);
			break;

			case "box17":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner10"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner10"), "box", "box19", "prisoner10_stay", 2.0);
			break;

			case "box18":
				PlaySound("INTERFACE\locked_window.wav");
				LAi_SetActorType(characterFromID("bb_prisoner3"));
				LAi_ActorGoToLocator(characterFromID("bb_prisoner3"), "box", "box20", "prisoner3_stay", 2.0);
			break;

			case "box19":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box17");
			break;

			case "box20":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box18");
			break;

			case "box21":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box14");
			break;

			case "box22":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box15");
			break;

			case "box23":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison", "box", "box16");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="bb_prison2")
	{
		switch(chr.boxname)
		{
			case "box1":
				//to cell1 MAROONS

				if(CheckAttribute(chr, "P2_cell1") && chr.P2_cell1 == "open")
				{
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison2", "goto", "goto2");
				}
				else
				{
					if(CheckCharacterItem(chr,"key38"))
					{
						int club = GetCharacterItem(chr, "bladeclub");
						if(club >= 4)
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.P2_cell1 = "open";

							LAi_QuestDelay("cell1_step_back", 1.0);
						}
						else
						{
							LAi_SetActorType(chr);	
							characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "need_weapons";
							LAi_ActorSelfDialog(chr, "");
						}
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box2":
				//from cell1

				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison2", "goto", "goto1");
			break;

			case "box3":
				//to cell2 PELL

				if(CheckAttribute(chr, "P2_cell2_special") && chr.P2_cell2_special == "locked_for_ever")
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
				
				if(CheckAttribute(chr, "P2_cell2") && chr.P2_cell2 == "open")
				{
					if(CheckAttribute(chr, "P2_ambush") && chr.P2_ambush == "cell")
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.P2_cell2_special = "locked_for_ever";
						LAi_SetOfficerType(characterFromID("bb_maroon1"));
						LAi_SetOfficerType(characterFromID("bb_maroon2"));

						LAi_QuestDelay("Took_in_cell2", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "bb_prison2", "goto", "goto4");
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"key38"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.P2_cell2 = "open";

						LAi_QuestDelay("cell2_step_back", 1.0);
					}
					else 
					{
						if(CheckAttribute(chr, "P2_box3") && chr.P2_box3 == "on") return;

						PlaySound("INTERFACE\locked_window.wav");

						if(CheckAttribute(chr, "Pell_story") && chr.Pell_story == "done")
						{
							Characters[GetCharacterIndex("Pell")].dialog.CurrentNode  = "neutral_cell";
						}
						else
						{
							chr.P2_box3 = "on";
							LAi_SetActorType(chr);
							LAi_SetActorType(characterFromID("Pell"));
							LAi_ActorGoToLocator(characterFromID("Pell"), "box", "box4", "Pell_story", 1.5);
						}
					}
				}
			break;

			case "box4":
				//from cell2

				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison2", "goto", "goto3");
			break;

			case "box5":
				//door

				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison2", "box", "box6");
				if(CheckAttribute(chr, "P2_ambush") && chr.P2_ambush == "on")
				{
					ChangeCharacterAddressGroup(characterFromID("Pell"), "bb_prison2", "goto", "box6_pell");
					ChangeCharacterAddressGroup(characterFromID("bb_maroon1"), "bb_prison2", "goto", "box6_m1");
					ChangeCharacterAddressGroup(characterFromID("bb_maroon2"), "bb_prison2", "goto", "box6_m2");
				}
			break;

			case "box6":
				//door

				if(CheckAttribute(chr, "P2_ambush") && chr.P2_ambush == "on")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					logit("Hmm. That's not a good idea");
				}
				else
				{
					PlaySound("PEOPLE\counter_openclose.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison2", "box", "box5");
					
					if(CheckAttribute(chr, "mapBB5") && chr.mapBB5 == "picked_up")
					{

					}
					else
					{
						if(IsOfficer(CharacterFromID("Pell")))				
						{ ChangeCharacterAddressGroup(characterFromID("Pell"), "bb_prison2", "goto", "box5_pell"); }
					}
				}
			break;

			case "box7":
				//hatch

				if(CheckAttribute(chr, "prison2.water") && chr.prison2.water == "slow")
				{
					if(CheckAttribute(chr, "P2_hatch_checked") && chr.P2_hatch_checked == "yes")
					{
						PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack6.wav");
						logit("There it is. The exit!");
						AddQuestRecord("Israel_Hands", "9");
						chr.P2_hatch_checked = "yes";
					}
				}

				if(CheckAttribute(chr, "prison2.water") && chr.prison2.water == "empty")
				{
					if(CheckAttribute(chr, "P2_hatch") && chr.P2_hatch == "open")
					{
						SetNextWeather("Clear");
						ChangeCharacterAddressGroup(characterFromID("Pell"), "bb_prison_port", "quest", "pell_fort");

						if(!LAi_IsDead(CharacterFromID("bb_maroon1"))) 
						{ 
							ChangeCharacterAddressGroup(characterFromID("bb_maroon1"), "bb_prison_port", "quest", "boat3"); 
							LAi_SetSitType(characterFromID("bb_maroon1"));
						}
						if(!LAi_IsDead(CharacterFromID("bb_maroon2"))) 
						{ 
							ChangeCharacterAddressGroup(characterFromID("bb_maroon2"), "bb_prison_port", "quest", "boat2"); 
							LAi_SetSitType(characterFromID("bb_maroon2"));
						}
						if(!LAi_IsDead(CharacterFromID("bb_maroon3"))) 
						{ 
							ChangeCharacterAddressGroup(characterFromID("bb_maroon3"), "bb_prison_port", "quest", "boat4"); 
							LAi_SetSitType(characterFromID("bb_maroon3"));
						}
						if(!LAi_IsDead(CharacterFromID("bb_maroon4"))) 
						{ 
							ChangeCharacterAddressGroup(characterFromID("bb_maroon4"), "bb_prison_port", "quest", "boat1"); 
							LAi_SetPoorType(characterFromID("bb_maroon4"));
						}

						DoQuestReloadToLocation("bb_prison_port", "goto", "temp", "_");
					}
					else
					{
						if(CheckCharacterItem(chr,"key38"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.P2_hatch = "open";

							Characters[GetCharacterIndex("gm_crew22")].Ship.Type = "Gunboat";
							Characters[GetCharacterIndex("gm_crew23")].Ship.Type = "Gunboat";
							Characters[GetCharacterIndex("Maltese_soldier1")].Ship.Type = "obj_Boat2";

							SetCharacterShipLocation(characterFromID("gm_crew22"), "BB_prison_port");	//Gunboat at port
							SetCharacterShipLocation(characterFromID("gm_crew23"), "BB_prison_port");	//Gunboat at prison
							setCharacterShipLocation(characterFromID("Maltese_soldier1"), "bb_prison_port");	//it was missing for unknown reason
						}
					}
				}
			break;

			case "box8":
				//closed bars end of corridor
				
				PlaySound("INTERFACE\locked_window.wav");
			break;
//pär sewer
			case "box9":
				//sewer

				if(CheckAttribute(chr, "equip.blade"))
				{
					switch(chr.equip.blade)
					{
						case "bladesaw":
							if(LAi_IsFightMode(chr))
							{
								if(CheckAttribute(chr, "saw_sewer") && chr.saw_sewer == "2")
								{			
									PlaySound("PEOPLE\scrape3.wav");
				
									LAi_QuestDelay("saw_blunt", 2.5);
								}
								else
								{
									chr.saw_sewer = sti(chr.saw_sewer) + 1;
									PlaySound("PEOPLE\saw1.wav");
								}
							}
							else
							{
								ChangeCharacterAddressGroup(chr, "bb_prison2", "quest", "sewer");
								LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
								LAi_SetFightMode(chr, true);
							}
						break;

						case "bladeaxe4":
							if(LAi_IsFightMode(chr))
							{
								if(CheckAttribute(chr, "axe_sewer") && chr.axe_sewer == "2")
								{			
									PlaySound("OBJECTS\DUEL\sword_broken.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladeaxe4");
									EquipCharacterByItem(chr, "bladeX4");

									if(LAi_IsFightMode(chr)) LAi_SetFightMode(chr, false);
									LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], true);
									LAi_QuestDelay("pchar_oh", 0.7);
								}
								else
								{
									chr.axe_sewer = sti(chr.axe_sewer) + 1;
									PlaySound("OBJECTS\DUEL\anchor.wav");
									PlaySound("OBJECTS\DUEL\chalice.wav");
								}							
							}
							else
							{
								ChangeCharacterAddressGroup(chr, "bb_prison2", "quest", "sewer");
								LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
								LAi_SetFightMode(chr, true);
							}
						break;

						case "bladehammer":
							if(LAi_IsFightMode(chr))
							{
								if(CheckAttribute(chr, "hammer_sewer") && chr.hammer_sewer == "1")
								{
									LAi_QuestDelay("Took_returns", 0.7);
								}			

								chr.hammer_sewer = sti(chr.hammer_sewer) + 1;
								PlaySound("PEOPLE\wood3.wav");
								PlaySound("PEOPLE\wood3.wav");
								PlaySound("PEOPLE\spade.wav");
							}
							else
							{
								ChangeCharacterAddressGroup(chr, "bb_prison2", "quest", "sewer");
								LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
								LAi_SetFightMode(chr, true);
							}
						break;

						//default
						PlaySound("INTERFACE\locked_window.wav");

						if(CheckAttribute(chr, "P2_sewer") && chr.P2_sewer == "checked")
						{

						}
						else
						{
							LAi_SetActorType(chr);	
							characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "need_tools";
							LAi_ActorSelfDialog(chr, "");

							chr.P2_sewer = "checked";

							LAi_QuestDelay("Took_drunk_check", 0.1);
						}
					}
				}
			break;

			case "box10":
				//Iron Maiden
			
				PlaySound("INTERFACE\metal_hatch_close.wav");
			
				LAi_QuestDelay("IronMaiden", 1.0);
			break;

			case "box11":
				//chest

				ChangeCharacterAddressGroup(chr, "bb_prison2", "goto", "stay11");

				if(CheckAttribute(chr, "P2_chest") && chr.P2_chest == "open")
				{
					LaunchItemsBox(&ar);
				}
				else
				{
					if(CheckCharacterItem(chr,"key38"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.P2_chest = "open";
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box12":
				//instead of reload1

				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				logit("Hmm. That's not a good idea");
			break;

			case "box13":
				//instead of reload2

				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				logit("Hmm. That's not a good idea");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="bb_prison_officer")
	{
		switch(chr.boxname)
		{
			case "box10":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "bb_prison_officer", "box", "box5");
			break;

			case "box5":
				if(CheckAttribute(chr, "mapBB5") && chr.mapBB5 == "picked_up")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "bb_prison_officer", "box", "box11");
				}
				else
				{
					LaunchItemsBox(&ar);

					chr.quest.mapBB5A_check.win_condition.l1 = "item";
					chr.quest.mapBB5A_check.win_condition.l1.character = chr.id;
					chr.quest.mapBB5A_check.win_condition.l1.item = "mapBB5A";
					chr.quest.mapBB5A_check.win_condition = "mapBB5A_check";
				}

			break;

			case "box6":
				LaunchItemsBox(&ar);
			break;

			case "box11":
				//the second rope: water slow/off

				if(GetAttribute(chr, "rope2_Tooks") == "on") return;
				chr.rope2_Tooks = "on";

				PlaySound("PEOPLE\creak2.wav");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("prison2_rope11", 1.0);
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box12":
				//the first rope: water fast/slow
				PlaySound("PEOPLE\creak2.wav");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("prison2_rope12", 1.0);
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box13":
				//looting drunk Took
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

//JRH Kristiania
//------------------------------------------------------------------------------------------------------
	
	if(Locations[locidx].id=="Kristiania_center")
	{
		switch(chr.boxname)
		{
			case "box1":
				LAi_SetStayType(chr);
				Logit(TranslateString("","Fort Waxholm"));	
				PlaySound("INTERFACE\knock2.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_center", "quest", "fort");

				LAi_QuestDelay("Kristiania_fort_password", 0.01);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_townhall_entre")
	{
		switch(chr.boxname)
		{
			case "box1":	
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		
			case "box2":	
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":	
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":	
				LaunchItemsBox(&ar);
			break;

			case "box5":	
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_townhall")
	{
		switch(chr.boxname)
		{
			case "box1":	
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":	
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":	
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":	
				LaunchItemsBox(&ar);
			break;

			case "box5":	
				LaunchItemsBox(&ar);
			break;

			case "box6":	
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_fort_commander")
	{
		switch(chr.boxname)
		{
			case "box1":	
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":	
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				
				LAi_QuestDelay("equip_BB_blades", 0.5);

				if(CheckAttribute(chr, "fort_ship") && chr.fort_ship == "gone")
				{
					
				}
				else LAi_QuestDelay("Fort_ship_disappear", 0.5);
			break;

			case "box3":	
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":	
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_cathedral")
	{
		switch(chr.boxname)
		{
			case "box4":
				//DOOR BUTTON				

				switch(Locations[FindLocation(chr.location)].models.always.l1)
				{
					case "door_button_missing":
						if(Locations[FindLocation(chr.location)].models.always.locators == "church3_l_ON_open" 
						|| Locations[FindLocation(chr.location)].models.always.locators == "church3_l_ON_closed")
						{
							PlaySound("OBJECTS\DUEL\electricity.wav");
							float Php = LAi_GetCharacterHP(chr);
							float Php75 = Php*0.75;
							LAi_ApplyCharacterDamage(chr, Php75);
							GetCharacterPos(chr, &u, &v, &w);
							CreateParticleSystem("canfire2" , 5.1, 1.2, 7.8, 0.0, 0.0, 0.0, sti(20) );
							SetModel(chr, "Skel4", chr.model.animation, chr.sex, stf(chr.model.height), true);
							
							LAi_QuestDelay("reset_Pyle_model", 0.5);
						}

						if(Locations[FindLocation(chr.location)].models.always.locators == "church3_l_OFF_open" 
						|| Locations[FindLocation(chr.location)].models.always.locators == "church3_l_OFF_closed")
						{
							if(CheckCharacterItem(chr,"switch_button"))
							{
								//place it
								PlaySound("OBJECTS\DUEL\spyglass.wav");
								TakeItemFromCharacter(chr, "switch_button");
								chr.switch_button = "needs_hammer";

								LAi_QuestDelay("place_switch_button", 1.0);
							}
							else 
							{
								//nothing happens ev comment
								PlaySound("VOICE\ENGLISH\blaze_huh.wav");
								Logit(TranslateString("","Something's missing here for sure."));
							}
						}
					break;

					case "door_button":
						if(CheckAttribute(chr, "switch_button") && chr.switch_button == "needs_hammer")
						{
							PlaySound("PEOPLE\chopchop.wav");
							chr.switch_button = "done";

							chr.quest.visit_tailor.win_condition.l1 = "location";
							chr.quest.visit_tailor.win_condition.l1.location = "Nueva_Suecia_TailorsShop";
							chr.quest.visit_tailor.win_condition = "visit_tailor";

							return;
						}

						switch(Locations[FindLocation(chr.location)].models.always.locators)
						{
								case "church3_l_OFF_open":
									PlaySound("INTERFACE\button1.wav");
									PlaySound("INTERFACE\button1.wav");

									LAi_QuestDelay("pchar_hah", 0.75);
								break;

								case "church3_l_ON_open":
									Locations[FindLocation(chr.location)].models.always.locators = "church3_l_ON_closed";
									Locations[FindLocation("Kristiania_cathedral")].reload.l2.disable = 1;
									PlaySound("INTERFACE\button1.wav");
									PlaySound("INTERFACE\button1.wav");

									LAi_QuestDelay("KR_church_close_door", 0.75);
								break;

								case "church3_l_OFF_closed":
									PlaySound("INTERFACE\button1.wav");
									PlaySound("INTERFACE\button1.wav");

									LAi_QuestDelay("pchar_hah", 0.75);
								break;

								case "church3_l_ON_closed":
									Locations[FindLocation(chr.location)].models.always.locators = "church3_l_ON_open";
									Locations[FindLocation("Kristiania_cathedral")].reload.l2.disable = 0;
									PlaySound("INTERFACE\button1.wav");
									PlaySound("INTERFACE\button1.wav");

									LAi_QuestDelay("KR_church_open_door", 0.75);
								break;
						}
					break;
				}
			break;

			case "box5":
				//LEVER LIGHTS
				
				switch(Locations[FindLocation(chr.location)].models.always.locators)
				{
						case "church3_l_OFF_open":
							Locations[FindLocation(chr.location)].models.always.locators = "church3_l_ON_open";
							PlaySound("INTERFACE\lever_down.wav");

							LAi_QuestDelay("KR_church_lever_down", 0.5);
						break;

						case "church3_l_ON_open":
							Locations[FindLocation(chr.location)].models.always.locators = "church3_l_OFF_open";
							PlaySound("INTERFACE\lever_up.wav");
							
							LAi_QuestDelay("KR_church_lever_up", 0.5);
						break;

						case "church3_l_OFF_closed":
							Locations[FindLocation(chr.location)].models.always.locators = "church3_l_ON_closed";
							PlaySound("INTERFACE\lever_down.wav");

							LAi_QuestDelay("KR_church_lever_down", 0.5);
						break;

						case "church3_l_ON_closed":
							Locations[FindLocation(chr.location)].models.always.locators = "church3_l_OFF_closed";
							PlaySound("INTERFACE\lever_up.wav");

							LAi_QuestDelay("KR_church_lever_up", 0.5);
						break;
				}
			break;

			case "box6":
				//COLLECTION BOX
				
				if(CheckCharacterItem(chr,"paper_clip2"))
				{
					PlaySound("PEOPLE\beltkey.wav");

					LAi_QuestDelay("use_paper_clip", 1.0);								
				}
				else
				{
					Logit(TranslateString("","It's something inside."));
					Logit(TranslateString("","I need a small hook to reach it."));
					PlaySound("PEOPLE\beltkey.wav");
					AddQuestRecord("KR_amulet","5");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Nueva_Suecia_hidden_town")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_hidden_town", "reload", "reload4_back");

				chr.quest.lock_door_sound.win_condition.l1 = "location";
				chr.quest.lock_door_sound.win_condition.l1.location = "Nueva_Suecia_upper_town";
				chr.quest.lock_door_sound.win_condition = "lock_door_sound";
			break;
		}
		return;
	}

	if(Locations[locidx].id=="NS_hidden_town_priest")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Nueva_Suecia_upper_town")
	{
		switch(chr.boxname)
		{
			case "box1":			
				if(CheckCharacterItem(chr,"key35"))
				{
					PlaySound("INTERFACE\key_unlock2.wav");

				//change from stop1 to stop2
					Locations[FindLocation("Nueva_Suecia_upper_town")].type = "town";
					Locations[FindLocation("Nueva_Suecia_upper_town")].reload.l1.go = "Kristiania_entre";
					Locations[FindLocation("Nueva_Suecia_upper_town")].reload.l1.disable = 0;
						
					if(Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.locators == "mu03_l_JRH_stop1")
					{ Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.locators = "mu03_l_JRH"; }

					if(Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.locators == "mu03_l_JRH_open_stop1")
					{ Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.locators = "mu03_l_JRH_open"; }

					Locations[FindLocation("Kristiania_entre")].reload.l2.disable = 0;
					Locations[FindLocation("Kristiania_entre")].reload.l3.disable = 1;
					Locations[FindLocation("Kristiania_entre")].models.always.locators = "ff01_l_JRH_stop2";
	
					Locations[FindLocation("Kristiania_center")].type = "silent_repair_town";
					Locations[FindLocation("Kristiania_center")].reload.l3.disable = 1;
					Locations[FindLocation("Kristiania_center")].models.always.locators = "GrTown_l_JRH_stop2";

					LAi_QuestDelay("unlock_NS_up", 1.0);								
				}
				else
				{
					PlaySound("INTERFACE\knock2.wav");

					LAi_QuestDelay("NS_up_turn_to_box32", 1.0);
				}
			break;

		//ROOF TOUR		
	
			case "box2":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box3");
			break;

			case "box3":			
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "goto", "plank");

				LAi_QuestDelay("NS_up_to_box4", 0.5);
			break;
			
			case "box4":			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "goto", "roof1");

				LAi_QuestDelay("NS_up_to_box5", 1.0);
			break;

			case "box5":			
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box6");

				LAi_QuestDelay("pchar_sigh", 0.5);
			break;

			case "box6":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box7");

				LAi_QuestDelay("pchar_puh", 1.0);
			break;

			case "box7":			
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_QuestDelay("NS_up_to_box8", 0.5);
			break;

			case "box8":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "goto", "roof2");

				LAi_QuestDelay("NS_up_to_box9", 0.5);
			break;

			case "box9":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box10");
			break;

			case "box10":			
				PlaySound("PEOPLE\creak2.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box11");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box11":			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box12");

				LAi_QuestDelay("pchar_ohoh", 1.0);
			break;

			case "box12":			
				PlaySound("PEOPLE\step_stairway.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box13");

				LAi_QuestDelay("shutter_selfdialog", 0.5);
			break;

			case "box13":	
				PlaySound("OBJECTS\DUEL\man_attack2.wav");		
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box14");

				LAi_QuestDelay("NS_up_fall_to_ground", 0.75);
			break;

			case "box14":	
				chr.NS_up_shutter = "saved";		
				PlaySound("PEOPLE\step_stairway.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box15");

				LAi_QuestDelay("pchar_puh", 0.5);
				LAi_QuestDelay("pchar_puh", 0.5);
			break;

			case "box15":	
				chr.NS_up_shutter = "dangerous_again";		
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box16");

				LAi_QuestDelay("beam_selfdialog", 0.5);
			break;

		//--------------------------------------------------------------------------------------------

			case "box16":			
				PlaySound("PEOPLE\step_stairway2.wav");
				PlaySound("PEOPLE\roof_creak2.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box17");

				LAi_QuestDelay("NS_up_turn_to_camera9", 0.5);
			break;

			case "box17":	
				PlaySound("PEOPLE\creak2.wav");		
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box18");
			break;

			case "box18":	
				PlaySound("PEOPLE\creak.wav");			
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box19");
			break;

			case "box19":	
				PlaySound("PEOPLE\creak2.wav");			
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box20");
			break;

		//--------------------------------------------------------------------------------------------

			case "box20":	
				chr.NS_up_beam = "saved";		
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box21");

				LAi_QuestDelay("pchar_yah", 1.0);
			break;

			case "box21":	
				chr.NS_up_beam = "dangerous_again";			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box22");
			break;

			case "box22":	
				PlaySound("PEOPLE\jump_roof.wav");		
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box23");

				LAi_QuestDelay("NS_up_turn_to_box24", 0.5);
			break;

			case "box23":	
				PlaySound("PEOPLE\run_roof.wav");		
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box24");
			break;

			case "box24":	
				PlaySound("PEOPLE\run_roof.wav");		
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box25");
			break;

			case "box25":	
				PlaySound("PEOPLE\jump_roof.wav");		
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box26");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box26":	
				PlaySound("PEOPLE\run_roof.wav");		
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box27");

				LAi_QuestDelay("NS_up_turn_to_box28", 0.5);
			break;

			case "box27":	
				PlaySound("PEOPLE\run_roof.wav");		
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box28");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box28":			
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box29");

				LAi_QuestDelay("pchar_sigh", 0.5);
			break;

			case "box29":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box30");
			break;

			case "box30":			
				PlaySound("PEOPLE\step_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "reload", "reload12");

				LAi_QuestDelay("check_Teach_hat", 0.5);
			break;

		//--------------------------------------------------------------------------------------------

			case "box31":			
				PlaySound("PEOPLE\run_stone.wav");

				if(CheckAttribute(chr, "tailor_passage") && chr.tailor_passage == "open")
				{
					ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "reload", "reload14");
				}
				else ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box1");
			break;

			case "box32":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "reload", "reload13");
			break;
		
		//--------------------------------------------------------------------------------------------

			case "box33":	
				Logit(TranslateString("","Nueva Suecia lower town"));		
				PlaySound("INTERFACE\locked_window.wav");
			break;
//pär radius
		//LEVER
			case "box34":
				switch(Locations[FindLocation(chr.location)].models.always.locators)
				{
					case "mu03_l_JRH":
						//closed

						Locations[FindLocation(chr.location)].models.always.l3 = "lever_down";
						Locations[FindLocation(chr.location)].models.always.locators = "mu03_l_JRH_open";
						Locations[FindLocation("Nueva_Suecia_lower_town")].models.always.locators = "mu01_l_JRH_open";
						PlaySound("INTERFACE\lever_down.wav");
				//Locations[FindLocation("Nueva_Suecia_upper_town")].locators_radius.reload.reload6_back = 0.7;
				//Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.reload.reload2_back = 0.7;

						LAi_QuestDelay("NS_upper_town_lever_down", 0.5);
					break;

					case "mu03_l_JRH_stop1":
						//closed

						Locations[FindLocation(chr.location)].models.always.l3 = "lever_down";
						Locations[FindLocation(chr.location)].models.always.locators = "mu03_l_JRH_open_stop1";
						Locations[FindLocation("Nueva_Suecia_lower_town")].models.always.locators = "mu01_l_JRH_open";
						PlaySound("INTERFACE\lever_down.wav");
				//Locations[FindLocation("Nueva_Suecia_upper_town")].locators_radius.reload.reload6_back = 0.7;
				//Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.reload.reload2_back = 0.7;

						LAi_QuestDelay("NS_upper_town_lever_down", 0.5);
					break;

					case "mu03_l_JRH_open":
						//open

						Locations[FindLocation(chr.location)].models.always.l3 = "lever_up";
						Locations[FindLocation(chr.location)].models.always.locators = "mu03_l_JRH";
						Locations[FindLocation("Nueva_Suecia_lower_town")].models.always.locators = "mu01_l_JRH";
						PlaySound("INTERFACE\lever_up.wav");
				//Locations[FindLocation("Nueva_Suecia_upper_town")].locators_radius.reload.reload6_back = 2.0;
				//Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.reload.reload2_back = 1.5;

						LAi_QuestDelay("NS_upper_town_lever_up", 0.5);
					break;	

					case "mu03_l_JRH_open_stop1":
						//open

						Locations[FindLocation(chr.location)].models.always.l3 = "lever_up";
						Locations[FindLocation(chr.location)].models.always.locators = "mu03_l_JRH_stop1";
						Locations[FindLocation("Nueva_Suecia_lower_town")].models.always.locators = "mu01_l_JRH";
						PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation("Nueva_Suecia_upper_town")].locators_radius.reload.reload6_back = 2.0;
				Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.reload.reload2_back = 1.5;

						LAi_QuestDelay("NS_upper_town_lever_up", 0.5);
					break;	
				}
			break;

		//INFORMATION BOXES
			case "box35":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Logit(TranslateString("","Not a chance - the Barrel is too heavy."));
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "randitem", "randitem7");

				LAi_QuestDelay("pchar_playertype", 0.7);
			break;

			case "box37":
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				Logit(TranslateString("","It's just about too high."));
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box27");

				LAi_QuestDelay("pchar_playertype", 0.7);
			break;

			case "box38":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box39");
				LAi_SetSitType(chr);

				LAi_QuestDelay("pchar_playertype", 0.25);
			break;

			case "box39":
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				Logit(TranslateString("","It's just about too high."));
				
				LAi_QuestDelay("NS_up_to_box38", 1.0);
			break;

			case "box40":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_upper_town", "box", "box41");
				LAi_SetSitType(chr);

				LAi_QuestDelay("pchar_playertype", 0.25);
			break;

			case "box41":
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				Logit(TranslateString("","It's just about too high."));
				
				LAi_QuestDelay("NS_up_to_box40", 1.0);
			break;

		}
		return;
	}

	if(Locations[locidx].id=="Nueva_Suecia_lower_town")
	{
		switch(chr.boxname)
		{
			case "box1":	
				Logit(TranslateString("","Nueva Suecia upper town"));
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box2":	
				if(CheckAttribute(chr, "NS_low_bell") && chr.NS_low_bell == "on")
				{
					PlaySound("VOICE\ENGLISH\mhm.wav");
					Logit(TranslateString("","I have already done that."));
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");	
					ChangeCharacterAddressGroup(chr, "Nueva_Suecia_lower_town", "box", "box3");
					SetLocatorRadius(locations[FindLocation(chr.location)], "quest", "shipyard", 0.0001);
					Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.quest.shipyard = 0.0001;
				}
			break;

			case "box3":			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_lower_town", "box", "box4");
			break;

			case "box4":			
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_lower_town", "box", "box5");

				LAi_QuestDelay("pchar_ohoh", 1.0);
			break;

			case "box5":			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_lower_town", "box", "box6");
			break;

			case "box6":			
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Nueva_Suecia_lower_town", "box", "box7");	
			break;

			case "box7":
				if(CheckAttribute(chr, "NS_low_bell") && chr.NS_low_bell == "on") return;

				if(CheckAttribute(chr, "NS_low_bell") && chr.NS_low_bell == "ready")
				{
					chr.NS_low_bell = "on";
					PlaySound("INTERFACE\bell2.wav");

					LAi_QuestDelay("NS_low_bell_sound", 1.0);
					LAi_QuestDelay("NS_low_bell_sound", 2.0);
					LAi_QuestDelay("NS_open_shipyard", 3.0);
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");	
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "bell");

					LAi_QuestDelay("NS_low_turn_to_bell", 1.0);
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Nueva_Suecia_tailorsshop")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Nueva_Suecia_tailor_upstairs")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
	
			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Oriel_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_port")
	{
		switch(chr.boxname)
		{
			//SHIPYARD AT SHORE
			case "box1":
				SetNextWeather("Clear");		//avoid rain inside shipwreck
				PlaySound("PEOPLE\Run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_port", "quest", "box2");

				LAi_QuestDelay("KR_port_turn_to_ship05", 1.0);
			break;

			case "box2":
				PlaySound("PEOPLE\Run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_port", "quest", "box3");

				LAi_QuestDelay("KR_port_turn_to_ship05", 1.0);
			break;

			case "box3":
				PlaySound("PEOPLE\Run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_port", "quest", "box5");

				LAi_QuestDelay("KR_port_turn_to_ship05", 1.0);
			break;

			case "box5":
				SetNextWeather("Clear");		//avoid rain inside shipwreck
				DoQuestReloadToLocation("Kristiania_shipwreck", "reload", "reload1", "_");	
			break;

			case "box4":
				//PIER TO WRECK

				SetNextWeather("Clear");		//avoid rain inside shipwreck
				DoQuestReloadToLocation("Kristiania_shipwreck", "goto", "box5", "_");				
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_shipyard")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;


			case "box3":
				if(CheckAttribute(chr, "KR_shipyard") && chr.KR_shipyard == "locked")
				{
					PlaySound("INTERFACE\door_locked2.wav");
				}
				else
				{
			//		chr.KR_shipyard = "locked";		//maybe locked later
					DoQuestReloadToLocation("Kristiania_shipyard_stairs", "reload", "reload2", "_");
				}	
			break;

			case "box4":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box6":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_shipwreck")
	{
		switch(chr.boxname)
		{
			case "box2":
				//with switch_button

				LaunchItemsBox(&ar);
			
				if(CheckAttribute(chr, "cardinal") && chr.cardinal == "start")
				{
					chr.cardinal = "done";
					ChangeCharacterAddressGroup(CharacterFromID("KR_cardinal"), "Nueva_Suecia_lower_town", "quest", "cardinal");
					ChangeCharacterAddressGroup(CharacterFromID("KR_priest1"), "Nueva_Suecia_lower_town", "quest", "priest1");
					ChangeCharacterAddressGroup(CharacterFromID("KR_priest2"), "Nueva_Suecia_lower_town", "quest", "priest2");
					ChangeCharacterAddressGroup(CharacterFromID("KR_priest3"), "Nueva_Suecia_lower_town", "quest", "priest3");
					ChangeCharacterAddressGroup(CharacterFromID("KR_priest4"), "Nueva_Suecia_lower_town", "quest", "priest4");

					chr.quest.cardinal_start.win_condition.l1 = "locator";
					chr.quest.cardinal_start.win_condition.l1.location = "Nueva_Suecia_lower_town";
					chr.quest.cardinal_start.win_condition.l1.locator_group = "quest";
					chr.quest.cardinal_start.win_condition.l1.locator = "cardinal";
					chr.quest.cardinal_start.win_condition = "cardinal_start";
				}
			break;

			case "box3":
				LaunchItemsBox(&ar);
			break;

			case "box4":
				LaunchItemsBox(&ar);
			break;

			case "box5":
				//WRECK TO PIER

				Locations[FindLocation("Kristiania_port")].locators_radius.box.box4 = 1.0;
			//	Characters[GetCharacterIndex("wr_mummy2")].Ship.Type = "obj_raft3";	//raft visible in port now
				Characters[GetCharacterIndex("Kr_cit16")].Ship.Type = "obj_raft3";	//raft visible in port now
				DoQuestReloadToLocation("Kristiania_port", "goto", "box4", "_");
			break;

			case "box6":
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Kristiania_jungle_house")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\Run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_jungle_house", "reload", "reload2");
			break;

			case "box2":
				PlaySound("PEOPLE\Run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Kristiania_jungle_house", "goto", "exit");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Redhouse_entre")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Redhouse_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box6":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}








//-----------------------------------------------------------------------------------------------------
	if(Locations[locidx].id=="BB_island1")
	{
		switch(chr.boxname)
		{
			case "box1":
				//ground

				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "BB_island1", "goto", "box2");
			break;

			case "box2":
				//middle platform

				if(CheckAttribute(chr, "quest.BB_isl1_ladder") && chr.quest.BB_isl1_ladder == "way_up")
				{
					chr.quest.BB_isl1_ladder = "temp_off";
					PlaySound("PEOPLE\creak2.wav");

					if(CheckAttribute(chr, "BB_isl1_tunnel") && chr.BB_isl1_tunnel == "open")
					{
						ChangeCharacterAddressGroup(chr, "BB_island1", "goto", "box3");
					}
					else 
					{
						chr.BB_isl1_box4 = "on";		//no action before turn around
						if(CheckCharacterItem(chr,"bladeBB"))
						{
							if(!IsEquipCharacterByItem(chr, "bladeBB"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeBB");
							}
							
							LAi_LocationFightDisable(&Locations[FindLocation("BB_island1")], true);
						} 
						if(CheckCharacterItem(chr,"pistolbladeBB"))
						{
							if(!IsEquipCharacterByItem(chr, "pistolbladeBB"))
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistolbladeBB");
							}	
						}
						ChangeCharacterAddressGroup(chr, "BB_island1", "goto", "box4");
					}

					LAi_QuestDelay("BB_island1_ladder_up", 2.0);
				}

				if(CheckAttribute(chr, "quest.BB_isl1_ladder") && chr.quest.BB_isl1_ladder == "way_down")
				{
					chr.quest.BB_isl1_ladder = "way_up";
				//	PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_island1", "goto", "box1");

					if(IsOfficer(CharacterFromID("Hands")))				
					{
						ChangeCharacterAddressGroup(characterFromID("Hands"), "none", "", "");
						ChangeCharacterAddressGroup(characterFromID("Hands"), "BB_island1", "officers", "off_1");
						LAi_SetOfficerType(characterFromID("Hands"));
					}
					if(IsOfficer(CharacterFromID("Caesar")))				
					{
						ChangeCharacterAddressGroup(characterFromID("Caesar"), "none", "", "");
						ChangeCharacterAddressGroup(characterFromID("Caesar"), "BB_island1", "officers", "off_2");
						LAi_SetOfficerType(characterFromID("Caesar"));
					}
					if(IsOfficer(CharacterFromID("Pell")))				
					{
						ChangeCharacterAddressGroup(characterFromID("Pell"), "none", "", "");
						ChangeCharacterAddressGroup(characterFromID("Pell"), "BB_island1", "officers", "off_3");
						LAi_SetOfficerType(characterFromID("Pell"));
					}

					LAi_QuestDelay("jump_roof_sound", 0.25);
					LAi_QuestDelay("BB_island1_ground_turn_around", 1.0);
				}
			break;

			case "box3":
				//top platform when door is open

				if(CheckAttribute(chr, "quest.BB_isl1_ladder") && chr.quest.BB_isl1_ladder == "way_up")
				{
					chr.quest.BB_isl1_ladder = "way_down";
					DoQuestReloadToLocation("BB_mountain_tunnel", "goto", "goto1", "BB_island1_ladder_down");
				}

				if(CheckAttribute(chr, "quest.BB_isl1_ladder") && chr.quest.BB_isl1_ladder == "way_down")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_island1", "goto", "box2");
				}
			break;

			case "box4":
				//top platform before door is open

				if(CheckAttribute(chr, "BB_isl1_box4") && chr.BB_isl1_box4 == "on") return;
				chr.BB_isl1_box4 = "on";

				if(CheckCharacterItem(chr,"bladeBB"))
				{
					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("OBJECTS\DUEL\sabre_sh.wav");
						
						chr.quest.BB_isl1_ladder = "temp_off";			//stops action at box3
						LAi_QuestDelay("key_unlock2", 1.5);
						LAi_QuestDelay("BB_island1_unlock_tunnel", 3.0);	
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("BB_island1")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("BB_isl1_box4_off", 1.0);
					}
				}
				else
				{
					PlaySound("INTERFACE\knock2.wav");
					Logit(TranslateString("","I guess a lever should be placed here."));
					if(CheckAttribute(chr, "Kr_quest") && chr.Kr_quest == "BB_tower")
					{
						chr.Kr_quest = "items_needed";
						ChangeCharacterAddressGroup(CharacterFromID("Kr_cit26"), "none", "", "");
						Characters[GetCharacterIndex("Kr_cit22")].dialog.CurrentNode  = "items_list";
						AddQuestRecord("Blackbeards_tower","4");		
					}
					chr.BB_door = "found";

					LAi_QuestDelay("pchar_hah", 1.0);
					LAi_QuestDelay("BB_island1_ladder_down_to_box2", 2.0);	
				}
			break;

			case "box5":
				//yell at officers

				PlaySound("OBJECTS\SHIPCHARGE\gunner_warning.wav");
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box5", 0.0001);
				Locations[FindLocation("BB_island1")].locators_radius.box.box5 = 0.0001;

				LAi_QuestDelay("Pyle_transformation16", 0.5);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_island2")
	{
		switch(chr.boxname)
		{
			case "box1":
				DoQuickSave();
				PlaySound("PEOPLE\run_stone.wav");
				PlaySound("PEOPLE\creak2.wav");

				if(CheckAttribute(chr, "BB_tower_entrance") && chr.BB_tower_entrance == "open")
				{
					ChangeCharacterAddressGroup(chr, "BB_island2", "reload", "reload4");
				}
				else 
				{
					LAi_LocationFightDisable(&Locations[FindLocation("BB_island2")], true);
					ChangeCharacterAddressGroup(chr, "BB_island2", "goto", "box7");
				}

				SetNextWind("NE",30);
				//SetNextWind("N",30);
			break;

			case "box2":
				PlaySound("PEOPLE\run_stone.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "BB_island2", "reload", "reload5");
			break;

			case "box3":
				//SPYGLASS

				SetNextWind("N",30);
				if(CheckAttribute(chr, "BB_spyglass") && chr.BB_spyglass == "on") return;

				chr.BB_spyglass = "on";
				if(CheckCharacterItem(chr,"BB_coin"))
				{
					PlaySound("INTERFACE\coin_drop.wav");
			//		TakeItemFromCharacter(chr, "BB_coin");	//coin should be able to reuse
					chr.quest.BB_tower_spyglass = "done";	

					LAi_QuestDelay("place_coin_BB_spyglass", 1.5);
				}
				else
				{
					Logit(TranslateString("","Insert coin."));					

					LAi_QuestDelay("move_to_BB_hatch", 1.0);		
				}
			break;

			case "box4":
				//FLAG
				SetNextWind("N",30);

				if(CheckAttribute(chr, "BB_isl2_box4") && chr.BB_isl2_box4 == "on") return;
				chr.BB_isl2_box4 = "on";

				if(Locations[FindLocation(chr.location)].models.always.locators == "jungle01_l_JRH")
				{
					//empty pole

					if(IsEquipCharacterByItem(chr, "bladeflag_pir") || IsEquipCharacterByItem(chr, "bladeflag_pir2")
					|| IsEquipCharacterByItem(chr, "bladeflag_HOL") || IsEquipCharacterByItem(chr, "bladeflag_ENG")	
					|| IsEquipCharacterByItem(chr, "bladeflag_FRA") || IsEquipCharacterByItem(chr, "bladeflag_POR")
					|| IsEquipCharacterByItem(chr, "bladeflag_SPA") || IsEquipCharacterByItem(chr, "bladeflag_PRE")
					|| IsEquipCharacterByItem(chr, "bladeflag_IRE") || IsEquipCharacterByItem(chr, "bladeflag_SWE")
					|| IsEquipCharacterByItem(chr, "bladeflag_HOL2") || IsEquipCharacterByItem(chr, "bladeflag_AME")	
					|| IsEquipCharacterByItem(chr, "bladeflag_SPA2"))
					{
						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("raise_BBflag", 1.0);
					}
					else
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "BB_island2", "goto", "spyglass");
						chr.BB_isl2_box4 = "off";
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.locators == "jungle01_l_JRH_F")
					{
						//flag raised

						if(chr.new.flag.sequence == 6) return;

						if(IsEquipCharacterByItem(chr, "bladeflag_pir") || IsEquipCharacterByItem(chr, "bladeflag_pir2")
						|| IsEquipCharacterByItem(chr, "bladeflag_HOL") || IsEquipCharacterByItem(chr, "bladeflag_ENG")	
						|| IsEquipCharacterByItem(chr, "bladeflag_FRA") || IsEquipCharacterByItem(chr, "bladeflag_POR")
						|| IsEquipCharacterByItem(chr, "bladeflag_SPA") || IsEquipCharacterByItem(chr, "bladeflag_PRE")
						|| IsEquipCharacterByItem(chr, "bladeflag_IRE") || IsEquipCharacterByItem(chr, "bladeflag_SWE")
						|| IsEquipCharacterByItem(chr, "bladeflag_HOL2") || IsEquipCharacterByItem(chr, "bladeflag_AME")	
						|| IsEquipCharacterByItem(chr, "bladeflag_SPA2"))
						{
							LAi_SetPlayerType(chr);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("change_BBflag", 1.0);
						}
						else 
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							if(!CheckCharacterItem(chr,"bladeX4")) GiveItem2Character(chr, "bladeX4");
							EquipCharacterByItem(chr, "bladeX4");

							LAi_SetPlayerType(chr);

							PlaySound("PEOPLE\run_stone.wav");
							ChangeCharacterAddressGroup(chr, "BB_island2", "goto", "spyglass");
							chr.BB_isl2_box4 = "off";
						}
					}
				}
			break;

			case "box5":
				PlaySound("PEOPLE\run_stone.wav");
				if(chr.new.flag.sequence == 6) 
				{
					ChangeCharacterAddressGroup(chr, "BB_island2", "goto", "spyglass");
				}
				else ChangeCharacterAddressGroup(chr, "BB_island2", "goto", "flagpole");
			break;

			case "box6":
				LAi_SetPlayerType(chr);

				DoQuestReloadToLocation("BB_tower", "goto", "goto1", "_");
			break;

			case "box7":
				if(CheckAttribute(chr, "BB_isl2_box7") && chr.BB_isl2_box7 == "on") return;
				chr.BB_isl2_box7 = "on";

				if(CheckCharacterItem(chr,"pistolbladeBB"))
				{
					if(!LAi_IsFightMode(chr))
					{
						chr.bb_isl2_position = "bridge";
						LAi_LocationFightDisable(&Locations[FindLocation("BB_island2")], false);
						LAi_SetFightMode(chr, true);

			//			LAi_QuestDelay("BB_isl2_box7_off", 1.0);
					}
				}
				else
				{
					PlaySound("INTERFACE\knock2.wav");
					Logit(TranslateString("","I guess the other blade should be placed here."));

					LAi_QuestDelay("BB_island2_still_locked", 2.0);	
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_tower")
	{
		switch(chr.boxname)
		{
			case "box1":
			//	PlaySound("INTERFACE\locked_window.wav");
				
				LaunchItemsBox(&ar);
				return;
			break;

			case "box3":
				chr.quest.lower_cave_trap = "from_tower";

				if(chr.model == "Skel4" || chr.model == "SkelZ") 
				{
					chr.trap_box14 = "disabled";

					LAi_QuestDelay("trap_box14_enabled", 2.5);
				}
				DoQuestReloadToLocation("BB_lower_cave", "goto", "goto2", "_");
			break;

			case "box4":
				LAi_SetStayType(chr);
				SetNextWeather("Clear");
				SetNextWind("N",30);
				SetCurrentTime(11.00, 0);		//because spyglass view = day

				DoQuestReloadToLocation("BB_island2", "goto", "box5", "_");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_upper_cave")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "goto1");
				DoQuickSave();
			break;

			case "box3":
				PlaySound("PEOPLE\recoil.wav");	
				ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "goto5");

				if(CheckAttribute(chr, "treasure_removed") && chr.treasure_removed == "yes")
				{
					LAi_QuestDelay("with_treasure_to_sea2", 0.1);
					LAi_QuestDelay("pchar_oh", 0.5);
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "C_dialog") && chr.C_dialog == "on") return;

				if(CheckAttribute(chr, "treasure_removed") && chr.treasure_removed == "yes")
				{
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "box8");

					LAi_QuestDelay("with_treasure_to_sea5", 0.1);
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");	
					ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "box4");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "goto5");

					LAi_QuestDelay("Pchar_playertype", 1.0);
				}
			break;

			case "box4":
				PlaySound("PEOPLE\step_stairway.wav");	
				ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "box6");
			break;

			case "box6":
				PlaySound("PEOPLE\Run_wood.wav");
				
				ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "box7");

				LAi_QuestDelay("BB_uppercave_leverturn", 0.5);
			break;

			case "box7":
				//LEVER

				if(CheckAttribute(chr, "quest.grotto_lever") && chr.quest.grotto_lever == "up")
				{
					PlaySound("INTERFACE\lever_down.wav");
					chr.quest.grotto_lever = "down";
					Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hdo_Ldo";
					Locations[FindLocation("BB_lower_cave")].models.always.locators = "grotto2_l_dry";
					locations[FindLocation("BB_lower_cave")].environment.sea = "false";

					Locations[FindLocation(chr.location)].models.always.l3 = "girder_block2";
					Locations[FindLocation("BB_upper_cave")].reload.l1.disable = 1;

					Locations[FindLocation("BB_tower")].locators_radius.reload.reload5 = 0.001;
					Locations[FindLocation("BB_tower")].locators_radius.goto.goto2 = 0.7;
					
					LAi_QuestDelay("lower_cave_water_out", 0.5);
				}
				else
				{
					if(CheckAttribute(chr, "quest.grotto_lever") && chr.quest.grotto_lever == "down")
					{
						PlaySound("INTERFACE\lever_up.wav");
						chr.quest.grotto_lever = "up";
						Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hdo_Lup";
						Locations[FindLocation("BB_lower_cave")].models.always.locators = "grotto2_l_flood";
						locations[FindLocation("BB_lower_cave")].environment.sea = "true";

						Locations[FindLocation(chr.location)].models.always.l3 = "girder_free2";
						if(Locations[FindLocation("BB_lower_cave")].models.always.l1 == "bars_down")
						{
							Locations[FindLocation("BB_upper_cave")].reload.l1.disable = 0;
						}
					
						if(CheckAttribute(chr, "Arot_sailing") && chr.Arot_sailing == "yes")
						{
							SetCharacterShipLocation(characterFromID("wr_mummy6"), "none");
						}

						Locations[FindLocation("BB_tower")].locators_radius.reload.reload5 = 0.7;
						Locations[FindLocation("BB_tower")].locators_radius.goto.goto2 = 0.001;

						LAi_QuestDelay("lower_cave_water_in", 0.5);	
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladelever3"))
					{
						if(!IsEquipCharacterByItem(chr, "bladelever3"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever3");
						}
						
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("place_upper_cave_lever", 1.0);
					}
					else
					{
						if(CheckAttribute(chr, "boat.islet") && chr.boat.islet == "ready")
						{
							PlaySound("PEOPLE\step_stairway.wav");
							ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "tartane");
							LAi_SetStayType(chr);

							LAi_QuestDelay("Pchar_lets_go", 1.0);
						}
						else 
						{
							PlaySound("PEOPLE\Run_wood.wav");
							ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "box8");

							LAi_QuestDelay("BB_uppercave_caveturn", 0.5);
						}
					}
				}	
			break;

			case "box8":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "BB_upper_cave", "goto", "return");
			break;

			case "box9":
				//TARTANE
			
				DoQuestReloadToLocation("BB_isle", "goto", "arrive", "pchar_playertype");		
			break;

			case "box10":
				//NO POLE YET

				if(CheckCharacterItem(chr,"bladeboom"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeboom"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeboom");
					}

					LAi_SetActorType(chr);
					LAi_ActorRunToLocator(chr, "goto", "pole", "place_grotto_boom", 3.0);
				}
				else
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					Logit(TranslateString("","No, the cannon is stuck!"));
				}
			break;

			case "box11":
				//HATCH IS DOWN, POLE IN PLACE

				if(CheckAttribute(chr, "treasure_removed") && chr.treasure_removed == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
				}
				else
				{
					PlaySound("INTERFACE\shelf_cogs.wav");
					Locations[FindLocation("BB_upper_cave")].reload.l2.disable = 0;
					Locations[FindLocation(chr.location)].models.always.window = "grotto1_w";
					Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hup";
					locations[FindLocation("BB_upper_cave")].type = "silent_cave_seashore";

					if(CheckAttribute(chr, "Arot_sailing") && chr.Arot_sailing == "yes")
					{
						SetCharacterShipLocation(characterFromID("wr_mummy6"), "none");
					}

					LAi_QuestDelay("open_grotto_hatch", 1.0);
				}
			break;

			case "box12":
				//HATCH IS UP, POLE IN PLACE

			SetNextWind("N",60);
				PlaySound("INTERFACE\shelf_cogs.wav");
				Locations[FindLocation("BB_upper_cave")].reload.l2.disable = 1;
				Locations[FindLocation(chr.location)].models.always.window = "grotto1_w_up";
				locations[FindLocation("BB_upper_cave")].type = "silent_seashore";

				if(CheckAttribute(chr, "quest.grotto_lever") && chr.quest.grotto_lever == "up")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hdo_Lup";
				}
				else
				{
					if(CheckAttribute(chr, "quest.grotto_lever") && chr.quest.grotto_lever == "down")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hdo_Ldo";
					}
				}
				else Locations[FindLocation(chr.location)].models.always.locators = "grotto1_l_Hdo";

				LAi_QuestDelay("close_grotto_hatch", 1.0);
			break;

			case "box13":
				//BOOKSHELF

				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				Logit(TranslateString("","So he could read? Most about Alchemy!"));
			break;

			case "box14":
				//LEAVING WITH TREASURE

				PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");

		//1
			ref cmdr = CharacterFromID("Dante Siciliano");

		//2 swe (personal)
			chr.special_flag = "off";
			CaptureTownForNation("Grand Turk", PERSONAL_NATION);
			cmdr.nation = PERSONAL_NATION;
			cmdr.Flags.Personal = 3; cmdr.Flags.Personal.texture = 4;

		//3 needed as a reset when personal is going down & "teach" is going up
			chr.special_flag = "off";
			CaptureTownForNation("Grand Turk", PIRATE);
			cmdr.nation = PIRATE;

		//4
			chr.special_flag = "on";
			CaptureTownForNation("Grand_Turk", PIRATE);
			cmdr.nation = PIRATE;
			cmdr.Flags.Pirate = 4; cmdr.Flags.Pirate.texture = 2;

		//5
			Towns[GetTownIndex("Grand Turk")].gov = "Dante Siciliano";

				LAi_QuestDelay("storm_careen", 1.0);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_lower_cave")
	{
		switch(chr.boxname)
		{
			case "box1":
				//first room
				LaunchItemsBox(&ar);
			break;

			case "box2":
		
			break;

			case "box3":
		
			break;
		
			case "box4":
		
			break;

			case "box5":
		
			break;
		
			case "box6":
				//GOLD BARS
				LaunchItemsBox(&ar);

				Logit(TranslateString("","No, the Gold Bars are too heavy - the crew will take them to the ship."));
			break;

			case "box7":
				//GOLD COINS
				LaunchItemsBox(&ar);

				Logit(TranslateString("","No, the Gold Coins are too heavy - the crew will take them to the ship.."));
			break;

			case "box8":
				//SILVER BARS
				LaunchItemsBox(&ar);

				Logit(TranslateString("","No, the Silver Bars are too heavy - the crew will take them to the ship."));
			break;

			case "box9":
				//WEAPONS
				LaunchItemsBox(&ar);

				Logit(TranslateString("","No, the Valuable Weapons are too heavy - the crew will take them to the ship."));
			break;

			case "box10":
				//CHERUB
				
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("BB_cherub", 0.5);
			break;

			case "box11":
				//GOLD DUST
				
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("BB_gold_dust", 0.5);
			break;

			case "box12":
				//GOLD DUST
				
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("BB_gold_dust", 0.5);
			break;

			case "box13":
				//go to deadly trap
	
				if(chr.model == "Skel4" || chr.model == "SkelZ") 
				{
					if(CheckCharacterItem(chr,"pistolbook71"))
					{
						chr.quest.lower_cave_trap = "from_cave";
						ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "goto4");

						chr.trap_box14 = "disabled";

						LAi_QuestDelay("trap_box14_enabled", 2.5);
					}
					else
					{
						if(CheckCharacterItem(chr,"bladepainting"))
						{
							LAi_QuestDelay("pchar_ohoh", 0.01);
							logit("Oh yes, I have forgotten the Book!");
							ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "escape");
						}
						else
						{	
							LAi_QuestDelay("pchar_ohoh", 0.01);
							logit("Oh yes, I have forgotten the Painting!");
							ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "escape");
						}
					}
				}
				else
				{
					DoQuickSave();
					chr.quest.lower_cave_trap = "from_cave";
					ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "goto4");
				}
			break;
//pär trap	
			case "box14":
				//at deadly trap
				
				if(CheckAttribute(chr, "trap_box14") && chr.trap_box14 == "disabled") return;

				chr.quest.escape_trap = "yes";

				if(CheckAttribute(chr, "quest.lower_cave_trap") && chr.quest.lower_cave_trap == "from_cave")
				{
					if(chr.model == "Skel4" || chr.model == "SkelZ")
					{
						DoQuestReloadToLocation("BB_tower", "goto", "goto5", "_");
					}
					else ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "escape");
				}
				else
				{
					if(CheckAttribute(chr, "quest.lower_cave_trap") && chr.quest.lower_cave_trap == "from_tower")
					{
						if(chr.model == "Skel4" || chr.model == "SkelZ")
						{
							ChangeCharacterAddressGroup(chr, "BB_lower_cave", "goto", "escape");
						}
						else DoQuestReloadToLocation("BB_tower", "goto", "goto5", "_");		
					}
				}
				
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.5);	//restarts trap
			break;

			case "box15":
				//at painting

				if(CheckCharacterItem(chr,"BBDagger"))
				{
					if(!IsEquipCharacterByItem(chr, "BBDagger"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "BBDagger");
					}
					ChangeCharacterAddressGroup(CharacterFromID("painting_target"), "BB_lower_cave", "goto", "target");
					LAi_LocationFightDisable(&Locations[FindLocation("BB_lower_cave")], false);
					LAi_SetFightMode(chr, true);
				}
				else 
				{
					Logit(TranslateString("","No, the Painting is too big to carry around. Maybe if I could cut the canvas out."));
					chr.treasure_painting = "checked";

					LAi_QuestDelay("pchar_mhm", 0.1);
					if(locations[FindLocation("BB_lower_cave")].models.always.locators == "grotto2_l_dry")
					{
						LAi_QuestDelay("wand_and_censer_check", 1.0);
					}
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_burning_cave")
	{
		switch(chr.boxname)
		{
			case "box1":
				//chest on floor

				LaunchItemsBox(&ar);
			break;

			case "box2":
				//ladder

				if(CheckCharacterItem(chr,"bladehammer"))
				{
					if(!IsEquipCharacterByItem(chr, "bladehammer"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladehammer");
					}

					LAi_LocationFightDisable(&Locations[FindLocation("BB_burning_cave")], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("bc_ladder_enabled", 1.0);
				}
				else
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					LAi_SetSitType(chr);

					LAi_QuestDelay("pchar_playertype", 0.5);
					LAi_QuestDelay("bc_ladder_stuck", 1.0);
				}
			break;

			case "box3":
				//cage prison1
			
				if(Locations[FindLocation("BB_burning_cave")].models.always.locators == "locator")
				{
					if(CheckCharacterItem(chr,"bladechair"))
					{
						if(!IsEquipCharacterByItem(chr, "bladechair"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladechair");
						}

						PlaySound("PEOPLE\wood1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
						TakeItemFromCharacter(chr, "bladechair");

						Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator1_chair";
						Locations[FindLocation("BB_burning_cave")].image = "";
						DoQuestReloadToLocation("BB_burning_cave", "goto", "at_box3", "bc_loading");
					}
					else LAi_QuestDelay("bc_cage_too_high", 0.1);
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_burning_cave", "box", "box4");
				}
			break;

			case "box4":
				//chest in cage prison1

				LaunchItemsBox(&ar);
				
				LAi_QuestDelay("bc_down_from_chair", 0.5);
			break;

			case "box5":
				//cage prison2

				switch(Locations[FindLocation("BB_burning_cave")].models.always.locators)
				{
					case "locator1_chair":
						//place the ladder

						if(CheckCharacterItem(chr,"bladeladder2"))
						{
							if(!IsEquipCharacterByItem(chr, "bladeladder2"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeladder2");
							}
							
							PlaySound("PEOPLE\wood2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
							TakeItemFromCharacter(chr, "bladeladder2");
							
							Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator2_ladder";
							Locations[FindLocation("BB_burning_cave")].image = "";
							DoQuestReloadToLocation("BB_burning_cave", "goto", "at_box5", "bc_loading");
						}
						else LAi_QuestDelay("bc_cage_too_high", 0.1);	
					break;


					case "locator2_ladder":
						//climb the ladder
						
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "BB_burning_cave", "box", "box6");

						LAi_QuestDelay("turn_bc_box6", 0.1);
					break;

					case "locator3_GD_open":
						//climb the ladder
						
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "BB_burning_cave", "box", "box6");

						LAi_QuestDelay("turn_bc_box6", 0.1);
					break;

					LAi_QuestDelay("bc_cage_too_high", 0.1);	//all other cases
				}
				return;
			break;

			case "box6":
				//chest in cage prison2

				LaunchItemsBox(&ar);
				
				LAi_QuestDelay("bc_down_from_ladder", 0.5);
			break;

			case "box7":
				switch(Locations[FindLocation("BB_burning_cave")].models.always.locators)
				{
					case "locator6_chair_ladder":
						//climb

						PlaySound("PEOPLE\creak.wav");
						ChangeCharacterAddressGroup(chr, "BB_burning_cave", "box", "box9");

						LAi_QuestDelay("pchar_yah", 1.0);
					break;

					case "locator5_chair":
						//place ladder on top of chair

						if(!IsEquipCharacterByItem(chr, "bladeladder2"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeladder2");
						}
							
						PlaySound("PEOPLE\wood2.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
						TakeItemFromCharacter(chr, "bladeladder2");
							
						Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator6_chair_ladder";
						Locations[FindLocation("BB_burning_cave")].image = "";
						DoQuestReloadToLocation("BB_burning_cave", "goto", "at_box7", "bc_loading_topchest");
					break;

					case "locator4_ladder_wrong":
						//climb the ladder or place chair instead
		
						if(CheckCharacterItem(chr,"bladechair"))
						{
							if(!IsEquipCharacterByItem(chr, "bladechair"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladechair");
							}

							TakeItemFromCharacter(chr, "bladechair");

							Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator5_chair";
							Locations[FindLocation("BB_burning_cave")].image = "";
							DoQuestReloadToLocation("BB_burning_cave", "goto", "at_box7", "bc_loading2");
						}
						else
						{
							PlaySound("PEOPLE\creak2.wav");
							ChangeCharacterAddressGroup(chr, "BB_burning_cave", "box", "box8");
						}
					break;

					case "locator3_GD_open":
						//place ladder (wrong)

						if(CheckAttribute(chr, "hell_gate5") && chr.hell_gate5 == "search_gift")
						{
							if(CheckCharacterItem(chr,"bladeladder2"))
							{
								if(!IsEquipCharacterByItem(chr, "bladeladder2"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladeladder2");
								}
							
								PlaySound("PEOPLE\wood2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeX4");
								TakeItemFromCharacter(chr, "bladeladder2");
							
								Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator4_ladder_wrong";
								Locations[FindLocation("BB_burning_cave")].image = "";
								DoQuestReloadToLocation("BB_burning_cave", "goto", "at_box7", "bc_loading3"); //was bc_loading
							}
							else LAi_QuestDelay("bc_cage_too_high", 0.1);
						}
						else LAi_QuestDelay("bc_cage_too_high", 0.1);
					break;

					LAi_QuestDelay("bc_cage_too_high", 0.1);	//all other cases
				}
				return;
			break;

			case "box8":
				//on (wrong) ladder

				if(Locations[FindLocation("BB_burning_cave")].models.always.locators == "locator6_chair_ladder")
				{
					PlaySound("PEOPLE\step_echo.wav");
					ChangeCharacterAddressGroup(chr, "BB_burning_cave", "goto", "at_box7");
				}
				else LAi_QuestDelay("bc_cage_too_high_wrong", 0.1);
			break;

			case "box9":
				//chest on top of cage in prison1

				LaunchItemsBox(&ar);

				LAi_QuestDelay("bc_down_from_top_chest", 0.5);
			break;

			case "box10":
				//down to LONG

				Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator7_exit";
				locations[FindLocation("BB_burning_cave")].models.day.charactersPatch = "walk_patch_LONG";
				locations[FindLocation("BB_burning_cave")].models.night.charactersPatch = "walk_patch_LONG";

				Locations[FindLocation("BB_burning_cave")].image = "wr_unknown2.tga";				
				DoQuestReloadToLocation("BB_burning_cave", "goto", "hole2", "_");	
			break;

			case "box11":
				//up to HIGH

				Locations[FindLocation("BB_burning_cave")].models.always.locators = "locator_high";
				locations[FindLocation("BB_burning_cave")].models.day.charactersPatch = "walk_patch_HIGH";
				locations[FindLocation("BB_burning_cave")].models.night.charactersPatch = "walk_patch_HIGH";

				Locations[FindLocation("BB_burning_cave")].image = "";
				DoQuestReloadToLocation("BB_burning_cave", "goto", "high1", "_");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_isle")
	{
		switch(chr.boxname)
		{
			case "box1":
				//exit tartane
				if(CheckCharacterItem(chr,"bladelever3"))
				{
					DoQuestReloadToLocation("BB_upper_cave", "goto", "box7", "BB_uppercave_leverturn");
				}
				else DoQuestReloadToLocation("BB_upper_cave", "goto", "box8", "_");	
			break;

			case "box2":
				if(CheckAttribute(chr, "isle.chimney") && chr.isle.chimney == "logbook")
				{
					if(CheckCharacterItem(chr,"book69A") || CheckCharacterItem(chr,"book69B") || CheckCharacterItem(chr,"book69C"))
					{
						PlaySound("INTERFACE\falling_down.wav");
						TakeItemFromCharacter(chr, "book69A"); TakeItemFromCharacter(chr, "book69B"); TakeItemFromCharacter(chr, "book69C");
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box2", 0.0001);
						Locations[FindLocation("BB_isle")].locators_radius.box.box2 = 0.0001;
						DeleteQuestHeader("KR_logbook");
					
						LAi_QuestDelay("logbook_down_chimney", 2.5);
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\grandma_yell.wav");
				
					LAi_QuestDelay("chimney_dialog", 1.5);
				}
			break;

			
		}
		return;
	}

	if(Locations[locidx].id=="BB_isle_passage")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_isle_hut")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box3");	
			break;

			case "box3":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box4");	
			break;

			case "box4":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box5");	
			break;

			case "box5":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box6");	
			break;

			case "box6":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box7");	
			break;

			case "box7":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_isle_hut", "box", "box8");	
			break;

			case "box8":
				if(CheckAttribute(chr, "isle.chest") && chr.isle.chest == "on") return;

				if(CheckAttribute(chr, "isle.chest") && chr.isle.chest == "open")
				{
					LaunchItemsBox(&ar);
					ChangeCharacterAddressGroup(chr, "BB_isle_hut", "goto", "jump");

					LAi_QuestDelay("BB_isle_hut_jump", 0.7);
				}
				else
				{
					if(CheckCharacterItem(chr,"BB_key"))
					{
						chr.isle.chest = "on";
						PlaySound("INTERFACE\key_unlock2.wav");

						LAi_QuestDelay("unlock_isle_chest", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");

						LAi_QuestDelay("BB_isle_hut_jump_locked", 0.7);
					}
				}	
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_careen_shore")
	{
		switch(chr.boxname)
		{
		//blockhouse
			case "box1":
				PlaySound("INTERFACE\knock2.wav");

				LAi_QuestDelay("careen_dog", 0.5);
			break;

		//passage
			case "box2":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box3");
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box4");

				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_1"), "BB_careen_shore", "quest", "mut1");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_2"), "BB_careen_shore", "quest", "mut2");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_3"), "BB_careen_shore", "quest", "mut3");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_4"), "BB_careen_shore", "quest", "mut4");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_5"), "BB_careen_shore", "quest", "mut5");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_6"), "BB_careen_shore", "quest", "mut6");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_7"), "BB_careen_shore", "quest", "mut7");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_8"), "BB_careen_shore", "quest", "mut8");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_9"), "BB_careen_shore", "quest", "mut9");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_10"), "BB_careen_shore", "quest", "mut10");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_11"), "BB_careen_shore", "quest", "mut11");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_12"), "BB_careen_shore", "quest", "mut12");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_13"), "BB_careen_shore", "quest", "mut13");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_14"), "BB_careen_shore", "quest", "mut14");
			
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_15"), "BB_careen_shore", "quest", "mut15");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_16"), "BB_careen_shore", "quest", "mut16");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_17"), "BB_careen_shore", "quest", "mut17");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_18"), "BB_careen_shore", "quest", "mut18");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_19"), "BB_careen_shore", "quest", "mut19");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_20"), "BB_careen_shore", "quest", "mut20");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_21"), "BB_careen_shore", "quest", "mut21");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_22"), "BB_careen_shore", "quest", "mut22");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_32"), "BB_careen_shore", "quest", "mut23");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_24"), "BB_careen_shore", "quest", "mut24");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_25"), "BB_careen_shore", "quest", "mut25");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_26"), "BB_careen_shore", "quest", "mut26");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_27"), "BB_careen_shore", "quest", "mut27");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_31"), "BB_careen_shore", "quest", "mut31");

				ChangeCharacterAddressGroup(CharacterFromID("Fletcher Christian"), "BB_careen_shore", "quest", "mshm");
				ChangeCharacterAddressGroup(CharacterFromID("Constable Mills"), "BB_careen_shore", "quest", "const");
				ChangeCharacterAddressGroup(CharacterFromID("Midshipman Young"), "BB_careen_shore", "quest", "cap");
				
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box3":
				if(CheckAttribute(chr, "careen_passage") && chr.careen_passage == "back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "quest", "return");
	
					LAi_QuestDelay("careen_mutineers9", 0.5);
				}
				else
				{
					LAi_SetActorType(CharacterFromID("Mutineer_15"));
					LAi_SetActorType(CharacterFromID("Mutineer_16"));
					LAi_SetActorType(CharacterFromID("Mutineer_17"));
					LAi_SetActorType(CharacterFromID("Mutineer_18"));
					LAi_SetActorType(CharacterFromID("Mutineer_19"));
					LAi_SetActorType(CharacterFromID("Mutineer_20"));
					LAi_SetActorType(CharacterFromID("Mutineer_21"));
					LAi_SetActorType(CharacterFromID("Mutineer_22"));
					LAi_SetActorType(CharacterFromID("Mutineer_32"));
					LAi_SetActorType(CharacterFromID("Mutineer_24"));
					LAi_SetActorType(CharacterFromID("Mutineer_25"));
					LAi_SetActorType(CharacterFromID("Mutineer_26"));
					LAi_SetActorType(CharacterFromID("Mutineer_27"));
					LAi_SetActorType(CharacterFromID("Mutineer_31"));

					LAi_SetActorType(CharacterFromID("Fletcher Christian"));
					LAi_SetActorType(CharacterFromID("Constable Mills"));
					LAi_SetActorType(CharacterFromID("Midshipman Young"));

					LAi_ActorTurnToCharacter(characterFromID("mutineer_15"), characterFromID("mutineer_1"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_16"), characterFromID("mutineer_2"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_17"), characterFromID("mutineer_3"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_18"), characterFromID("mutineer_4"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_19"), characterFromID("mutineer_5"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_20"), characterFromID("mutineer_6"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_21"), characterFromID("mutineer_7"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_22"), characterFromID("mutineer_8"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_32"), characterFromID("mutineer_9"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_24"), characterFromID("mutineer_10"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_25"), characterFromID("mutineer_11"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_26"), characterFromID("mutineer_12"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_27"), characterFromID("mutineer_13"));
					LAi_ActorTurnToCharacter(characterFromID("mutineer_31"), characterFromID("mutineer_14"));
	
					LAi_ActorTurnToCharacter(characterFromID("Fletcher Christian"), characterFromID("Constable Mills"));
					LAi_ActorTurnToCharacter(characterFromID("Constable Mills"), characterFromID("mutineer_2"));
					LAi_ActorTurnToCharacter(characterFromID("Midshipman Young"), characterFromID("Constable Mills"));

					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box4");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "quest", "turn_passage");

					LAi_QuestDelay("pchar_staytype", 0.5);
					LAi_QuestDelay("pchar_huh", 0.5);
				}
			break;

			case "box4":
				if(CheckAttribute(chr, "careen_passage") && chr.careen_passage == "back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "quest", "return");
	
					LAi_QuestDelay("careen_mutineers9", 0.5);
				}
				else
				{
					LAi_SetPoorType(CharacterFromID("Mutineer_15"));
					LAi_SetPoorType(CharacterFromID("Mutineer_16"));
					LAi_SetPoorType(CharacterFromID("Mutineer_17"));
					LAi_SetPoorType(CharacterFromID("Mutineer_18"));
					LAi_SetPoorType(CharacterFromID("Mutineer_19"));
					LAi_SetPoorType(CharacterFromID("Mutineer_20"));
					LAi_SetPoorType(CharacterFromID("Mutineer_21"));
					LAi_SetPoorType(CharacterFromID("Mutineer_22"));
					LAi_SetPoorType(CharacterFromID("Mutineer_32"));
					LAi_SetPoorType(CharacterFromID("Mutineer_24"));
					LAi_SetPoorType(CharacterFromID("Mutineer_25"));
					LAi_SetPoorType(CharacterFromID("Mutineer_26"));
					LAi_SetPoorType(CharacterFromID("Mutineer_27"));
					LAi_SetPoorType(CharacterFromID("Mutineer_31"));

					LAi_SetStayType(CharacterFromID("Fletcher Christian"));
					LAi_SetStayType(CharacterFromID("Constable Mills"));

					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "quest", "new_shore");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "randitem", "randitem42");

					LAi_QuestDelay("pchar_playertype", 0.5);
					LAi_QuestDelay("pchar_ohoh", 1.0);
					LAi_QuestDelay("careen_mutineers1", 2.0);
				}
			break;
		
			case "box6":
				if(CheckAttribute(chr, "careen_passage") && chr.careen_passage == "back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box4");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "quest", "return");

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
				else
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box4");
					PlaySound("PEOPLE\step_ground.wav");

					LAi_QuestDelay("careen_turn_back", 1.0);
				}
			break;


		//tower
			case "box7":
				if(Locations[FindLocation("BB_careen_shore")].models.always.locators == "Shore06_l_careen_S4")
				{
					Logit(TranslateString("","No, it's not the time for that."));
					PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box8");
				}
			break;

			case "box8":
				if(CheckAttribute(chr, "careen_tower") && chr.careen_tower == "down")
				{
					chr.careen_tower = "up";
					PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
					CreateParticleSystemX("ball_splash", 93.5, 1.0, 27.5, 0.0, 0.0, 0.0, 0);
					CreateParticleSystemX("ball_splash", 93.5, 0.0, 27.5, 0.0, 0.0, 0.0, 0);
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "goto", "tower_down");
					LAi_SetActorType(chr);
					
					LAi_QuestDelay("careen_tower_down", 0.75);	//turning 180
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box9");
				}
			break;

			case "box9":
				if(CheckAttribute(chr, "careen_tower") && chr.careen_tower == "down")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box8");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box10");
				}
			break;

			case "box10":
				if(CheckAttribute(chr, "careen_tower") && chr.careen_tower == "down")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box9");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box11");
				}
			break;

			case "box11":
				if(Locations[FindLocation("BB_careen_shore")].models.always.locators == "Shore06_l_careen_S3") chr.careen_tower = "down";

				if(CheckAttribute(chr, "careen_tower") && chr.careen_tower == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box10");
				}
				else
				{
					if(Locations[FindLocation("BB_careen_shore")].models.always.locators == "Shore06_l_careen_S")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "BB_careen_shore", "goto", "cliff_top");
						chr.careen_tower = "down";
					}
					else
					{
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box12");

						if(CheckAttribute(chr, "careen_running") && chr.careen_running == "started")
						{
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "goto", "locator9");

							LAi_QuestDelay("pchar_staytype", 0.75);
						}
					}
				}
			break;

			case "box12":
				if(CheckAttribute(chr, "careen_tower") && chr.careen_tower == "down")
				{
					//PlaySound("PEOPLE\creak2.wav");
					PlaySound("PEOPLE\recoil.wav");	
					ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box11");
					LAi_SetSitType(chr);

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
				else
				{
					if(CheckAttribute(chr, "careen_guns") && chr.careen_guns == "ready")
					{
						if(CheckAttribute(chr, "careen_running") && chr.careen_running == "done")
						{
							PlaySound("PEOPLE\run_wood.wav");

							characters[GetCharacterIndex("Maltese_soldier3")].Ship.Type = "Corvette2";
							characters[GetCharacterIndex("Maltese_soldier3")].sailaway = true;
		
							locations[FindLocation("BB_careen_shore")].type = "silent_seashore";
							SetNextWeather("Clear");
							SetNextWind("NW",90);		//was N, 30

							Locations[FindLocation("BB_careen_shore")].image = "";
							DoQuestReloadToLocation("BB_careen_shore", "quest", "see_guns" ,"careen_ship1");

							AddPassenger(chr, characterFromID("Pell"), 0);
							SetOfficersIndex(chr, 3, getCharacterIndex("Pell"));
							LAi_SetOfficerType(characterFromID("Pell"));

							
						}
						else LAi_QuestDelay("pchar_mhm", 0.01);
					}
					else
					{
						PlaySound("PEOPLE\run_wood.wav");
						ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box13");
					}
				}
			break;

			case "box13":
				chr.careen_tower = "down";
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "BB_careen_shore", "box", "box12");

				LAi_QuestDelay("creak_sound", 0.5);
			break;

		//book	
			case "box5":
				ChangeCharacterAddressGroup(chr, "BB_careen_shore", "quest", "box5_back");
				PlaySound("INTERFACE\paper_small.wav");
				Logit(TranslateString("","Three officers with a total of 5 shares. Add to that the 29 shares for the sailors. But first I have to..."));
			break;

		//remove watchtower roof
			case "box15":
				PlaySound("VOICE\ENGLISH\Fre_m_a_074.wav");

				LAi_QuestDelay("careen_tower_damaged7_A", 2.5);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_careen_blockhouse")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("INTERFACE\knock2.wav");

				LAi_QuestDelay("careen_dog", 0.5);
			break;

			case "box3":
				PlaySound("INTERFACE\key_unlock2.wav");
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box3", 0.0001);
				SetLocatorRadius(locations[FindLocation(chr.location)], "reload", "reload1", 1.0);
				SetCurrentTime(21.00, 0);
				chr.quest.JRH_rain = "Clear";
				SetNextWeather("Clear");
				Locations[FindLocation("BB_careen_shore")].image = "wr_careen_shore.tga";
			break;
		}
		return;
	}

	if(Locations[locidx].id=="BB_careen_capsm")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				if(CheckCharacterItem(chr,"pitchfork"))
				{
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box2", 0.001);
					Locations[FindLocation("BB_careen_capsm")].locators_radius.box.box2 = 0.001;
					LAi_LocationFightDisable(&Locations[FindLocation("BB_careen_capsm")], false);
				SetCurrentTime(0.00, 0);

					if(!IsEquipCharacterByItem(chr, "pitchfork"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "pitchfork");
					}
					LAi_SetFightMode(chr, true);
				

					LAi_QuestDelay("use_pitchfork", 1.0);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","I need a long tool to remove the pole."));
					LAi_SetPlayerType(chr);
					AddQuestRecord("Careen_corvette", "1");
				}
				
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_careen_holdP")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"careen_convicts") && chr.careen_convicts == "locked")
				{
					if(CheckCharacterItem(chr,"key39"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");

						LAi_QuestDelay("unlock_convicts", 1.0);
					}
					else 
					{
						PlaySound("INTERFACE\locked_window.wav");
						AddQuestRecord("Careen_corvette", "5");
					}
				}
				else
				{
					if(Locations[FindLocation("BB_careen_holdP")].models.night.charactersPatch == "hold_p_convicts")
					{
						Locations[FindLocation("BB_careen_holdP")].id.label = "Animals hold prow";
						Locations[FindLocation("BB_careen_holdP")].models.day.charactersPatch = "hold_p_animals";
						Locations[FindLocation("BB_careen_holdP")].models.night.charactersPatch = "hold_p_animals";
						DoQuestReloadToLocation("BB_careen_holdP", "reload", "reload5" ,"_");
					}
					else
					{
						Locations[FindLocation("BB_careen_holdP")].id.label = "Convicts hold prow";
						Locations[FindLocation("BB_careen_holdP")].models.day.charactersPatch = "hold_p_convicts";
						Locations[FindLocation("BB_careen_holdP")].models.night.charactersPatch = "hold_p_convicts";
						DoQuestReloadToLocation("BB_careen_holdP", "reload", "reload4" ,"_");
					}
				}
			break;

			case "box2":
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
				Logit(TranslateString("","There's something I can use. A pitchfork."));
				AddQuestRecord("Careen_corvette", "3");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_careen_holdS")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="BB_careen_capmd_2")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");

				LaunchItemsBox(&ar);
			break;

			case "box5":
				chr.capmd_position = "outer";
				chr.quest.items_transfer = "no";
				chr.corv_weaponslocker = "check";
				LaunchItemsBox(&ar);

				LAi_QuestDelay("corv_capmd_2_check", 0.1);
			break;

			case "box6":
				chr.capmd_position = "outer";
				chr.quest.items_transfer = "no";
				chr.corv_weaponslocker = "check";
				LaunchItemsBox(&ar);
				
				LAi_QuestDelay("corv_capmd_2_check", 0.1);
			break;

			case "box7":
				chr.capmd_position = "outer";
				chr.quest.items_transfer = "no";
				chr.corv_weaponslocker = "check";
				LaunchItemsBox(&ar);

				LAi_QuestDelay("corv_capmd_2_check", 0.1);
			break;

			case "box8":
				chr.capmd_position = "outer";
				chr.quest.items_transfer = "no";
				chr.corv_weaponslocker = "check";
				LaunchItemsBox(&ar);

				LAi_QuestDelay("corv_capmd_2_check", 0.1);
			break;

			case "box9":
				switch(Locations[FindLocation(chr.location)].models.always.locators)
				{
					case "capmd_2_l_careen":
						if(CheckCharacterItem(chr,"pitchfork"))
						{
							ChangeCharacterAddressGroup(chr, "BB_careen_capmd_2", "goto", "at_door");
							if(!IsEquipCharacterByItem(chr, "pitchfork"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "pitchfork");
							}
							LAi_LocationFightDisable(&Locations[FindLocation("BB_careen_capmd_2")], false);
							LAi_SetFightMode(chr, true);
						
							LAi_QuestDelay("place_pitchfork", 1.0);
						}
						//pchar can't get rid of the pitchfork so no 'else' here		
					break;

					case "capmd_2_l_careen_blocked":
						ChangeCharacterAddressGroup(chr, "BB_careen_capmd_2", "goto", "at_door");
						if(!IsEquipCharacterByItem(chr, "bladeX4"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}
						LAi_LocationFightDisable(&Locations[FindLocation("BB_careen_capmd_2")], false);
						LAi_SetFightMode(chr, true);
						
						LAi_QuestDelay("remove_pitchfork", 1.0);	
					break;
				}
			break;

			case "box10":
				if(!IsEquipCharacterByItem(chr, "bladeX4"))
				{
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					EquipCharacterByItem(chr, "bladeX4");
				}
				LAi_LocationFightDisable(&Locations[FindLocation("BB_careen_capmd_2")], false);
				LAi_SetFightMode(chr, true);
						
				LAi_QuestDelay("take_pitchfork", 1.0);
			break;
		}

		return;
	}
    //<-- Q2

	if(Locations[locidx].id=="Shipyard_docks")
	{
		switch(chr.boxname)
		{
			case "box1":
				//PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Shipyard_docks", "reload", "reload5");
			break;

			case "box2":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Shipyard_docks", "goto", "goto9");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Redmond_shore_02")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "box", "box3");
			break;

			case "box3":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "goto", "goto9");
			break;

			case "box4":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "box", "box5");
			break;

			case "box5":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "box", "box6");
			break;

			case "box6":
				PlaySound("PEOPLE\Run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_shore_02", "reload", "reload4D");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Redmond_tavern")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_tavern", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_tavern", "box", "box1");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="mutiny_deckWR")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\step_stairway1.wav");
				ChangeCharacterAddressGroup(chr, "mutiny_deckWR", "box", "box2");
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.mutineer_boat") && chr.quest.mutineer_boat == "ready")
				{
					DoQuestReloadToLocation("Swamp_island1", "goto", "at_sea1", "_");
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Swamp_island1")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(Locations[FindLocation(chr.location)].models.always.locators == "jungle2_locators_JRH1")
				{
					PlaySound("VOICE\ENGLISH\blaze_dont_leave_me.wav");
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.locators == "jungle2_locators_JRH2")
					{
						if(CheckAttribute(chr,"quest.swamp1_sounds") && chr.quest.swamp1_sounds == "scream")
						{
							PlaySound("VOICE\ENGLISH\blaze_scream.wav");
						}
						else PlaySound("VOICE\ENGLISH\blaze_help.wav");
					}
				}
				else PlaySound("VOICE\ENGLISH\blaze_scream.wav");
			break;

			case "box2":
				PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
				Logit(TranslateString("","That island is the only land in sight. I have to get there!"));
			break;

			case "box3":
				if(Locations[FindLocation(chr.location)].models.always.locators == "jungle2_locators_JRH1")
				{
					PlaySound("VOICE\ENGLISH\blaze_help.wav");
				}
				else PlaySound("VOICE\ENGLISH\blaze_scream.wav");
			break;

			//box4, 5, 6 not used anymore		

			case "box7":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				chr.quest.fallen_tree = "pos_2";
				Locations[FindLocation(chr.location)].models.always.locators = "Jungle2_locators_JRH2";

				LAi_QuestDelay("push_tree1", 0.5);
			break;

			case "box8":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				chr.quest.fallen_tree = "pos_3";
				Locations[FindLocation(chr.location)].models.always.locators = "Jungle2_locators_JRH3";

				LAi_QuestDelay("push_tree2", 0.5);
			break;

			case "box9":
				if(CheckAttribute(chr, "quest.tree_boat") && chr.quest.tree_boat == "ready")
				{
					DoQuestReloadToLocation("Swamp_island2", "goto", "arrive", "_");
				}
			break;

			case "box10":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				chr.quest.fallen_tree = "pos_4";
				Locations[FindLocation(chr.location)].models.always.locators = "Jungle2_locators_JRH4";
			
				LAi_QuestDelay("push_tree3", 0.5);
			break;

			case "box11":
				PlaySound("PEOPLE\step_stairway1.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_island1", "goto", "leave");

				LAi_QuestDelay("swamp1_pos2_turn_sea_last_time", 0.01);
			break;

			case "box12":
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
				Logit(TranslateString("","Hmm, this tree is floating, how can I get it to sea?"));

				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Swamp_island2")
	{
		switch(chr.boxname)
		{

			case "box1":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto2");
				return;
			break;

			case "box2":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto3");
				return;
			break;

			case "box3":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto4");

				LAi_QuestDelay("swamp_wreck1", 1.0);
			break;

			case "box4":
				if(CheckAttribute(chr,"quest.raft_ropes") && chr.quest.raft_ropes == "picked_up")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "reload", "reload7");
					chr.quest.mast_climb = "way_up";
				}
				else
				{
					if(CheckAttribute(chr,"quest.mast_climb") && chr.quest.mast_climb == "way_down")
					{
						PlaySound("PEOPLE\run_wood.wav");
						ChangeCharacterAddressGroup(chr, "Swamp_island2", "reload", "reload7");
						chr.quest.mast_climb = "way_up";
					}
					else
					{
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto5");

						LAi_QuestDelay("swamp_wreck2", 0.5);
					}
				}
			break;

			case "box5":
				if(CheckAttribute(chr,"quest.mast_climb") && chr.quest.mast_climb == "way_down")
				{
					PlaySound("PEOPLE\jump.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto4");

					LAi_QuestDelay("swamp_wreck1", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto6");
				}
			break;

			case "box6":
				if(CheckAttribute(chr,"quest.mast_climb") && chr.quest.mast_climb == "way_down")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto5");

					LAi_QuestDelay("swamp_wreck2", 0.5);
				}
				else
				{
					PlaySound("PEOPLE\recoil.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "goto", "goto7");
					chr.quest.mast_climb = "way_down";
				}
			break;

			case "box7":
				//building a raft on the shore - starts with box16 just looking
				if(Locations[FindLocation(chr.location)].models.always.locators == "TownExitW_locators_JRH8_raft_ropes")
				{
					//move raft to the water here
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("launch_raft", 1.0);
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.locators == "TownExitW_locators_JRH8_raft_ropes")
					{
						//move raft to the water here

					}
					else
					{
						if(Locations[FindLocation(chr.location)].models.always.locators == "TownExitW_locators_JRH8_raft_logs")
						{
							if(CheckCharacterItem(chr,"raft_ropes"))
							{
								//take ropes, switch to ...JRH8_raft_ropes
								PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
								Logit(TranslateString("","I'll use the rope to assemble the raft!"));
								LAi_SetSitType(chr);

								LAi_QuestDelay("build_raft", 1.0);
							}
							else
							{
								PlaySound("VOICE\ENGLISH\blaze_huh.wav");
								Logit(TranslateString("","Enough with logs - how do I assemble the raft?"));
							}
						}
					}
					else
					{
						if(Locations[FindLocation(chr.location)].models.always.locators == "TownExitW_locators_JRH8")
						{
							PlaySound("OBJECTS\DUEL\man_hit1.wav");
							Logit(TranslateString("","Hmm, let's arrange them in some order..."));
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("arrange_raft_logs", 1.0);
						}
					}
					else
					{
						if(CheckCharacterItem(chr,"pistollog"))
						{
							if(!IsEquipCharacterByItem(chr, "pistollog"))
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistollog");
							}

							PlaySound("PEOPLE\wood2.wav");
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							TakeItemFromCharacter(chr, "pistollog");

							gp = GetCharacterItem(chr, "gunpowder");
							pb = GetCharacterItem(chr, "pistolbullets");
						//	LogIt("gp start = " + gp);
						//	LogIt("pb start = " + pb);

							chr.quest.gunpowder = sti(GetCharacterItem(chr, "gunpowder"));
							chr.quest.pistolbullets = sti(GetCharacterItem(chr, "pistolbullets"));

						//	LogIt("Pchar.quest.gunpowder = " + chr.quest.gunpowder);
						//	LogIt("Pchar.quest.pistolbullets = " + chr.quest.pistolbullets);

							LAi_QuestDelay("collect_raft_logs", 1.0);
						}
					}
					else
					{
						Logit(TranslateString("","I still need more logs to build a raft."));
						//PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					}
				}
			break;

			case "box8":
				//koster in stone (ri 15)
					if(IsEquipCharacterByItem(chr, "Minerspick"))
					{
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("use_Minerspick_on_stone", 1.0);
					}
					else
					{
						if(IsEquipCharacterByItem(chr, "MinersSpade"))
						{
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("wrong_use_MinersSpade_on_stone", 1.0);
						}
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						Logit(TranslateString("","No, I can't move it!"));
					}
			break;

			case "box9":
				//koster in mud (ri 20)
					if(IsEquipCharacterByItem(chr, "Minerspick"))
					{
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("use_Minerspick_on_mud", 1.0);
					}
					else
					{
						if(IsEquipCharacterByItem(chr, "MinersSpade"))
						{
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("wrong_use_MinersSpade_on_mud", 1.0);
						}
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						Logit(TranslateString("","No, I can't move it!"));
					}
			break;

			case "box10":
				//raft_ropes in mast top (ri 7)
					if(IsEquipCharacterByItem(chr, "BarmansKnife"))
					{
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("use_BarmansKnife_on_rope", 1.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack5.wav");
						Logit(TranslateString("","No, this rope is tied too hard!"));

						LAi_QuestDelay("raft_ropes1", 1.0);
					}
			break;

			case "box11":
					//to loghouse entre
					PlaySound("PEOPLE\step_water1.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "reload", "reload5");
			break;

			case "box12":
					//start to grot
					PlaySound("PEOPLE\step_water1.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "box", "box15");
			break;

			case "box13":
					//start back from grot
					PlaySound("PEOPLE\step_water1.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "box", "box14");
			break;

			case "box14":
					//half way back from grot
					PlaySound("PEOPLE\step_water1.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "reload", "reload1");
			break;

			case "box15":
					//half way to grot
					PlaySound("PEOPLE\step_water1.wav");
					ChangeCharacterAddressGroup(chr, "Swamp_island2", "reload", "reload8");
			break;

			case "box16":
				//getting the idea of building a raft on the shore

				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				Logit(TranslateString("","Hmm, with some more logs maybe I could build a raft here."));
			break;

			case "box17":
				//push raft to shore
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_QuestDelay("push_raft", 1.0);
			break;

			case "box18":
				//enter raft at shore
				PlaySound("PEOPLE\step_water1.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_island2", "box", "box19");
				LAi_SetPoorType(chr);

				LAi_QuestDelay("enter_raft", 0.001);
			break;

			case "box19":
				//leave shipwreck island into the fog
				if(CheckAttribute(chr, "quest.raft_boat") && chr.quest.raft_boat == "ready")
				{
					DoQuestReloadToLocation("at_sea_in_fog", "goto", "fog_at_sea", "_");
				}
			break;

		}

		return;
	}

	if(Locations[locidx].id=="Swamp_wreck_inside")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box2":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box3":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box4":
				PlaySound("PEOPLE\Jump.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_wreck_inside", "goto", "goto10");
				return;
			break;

			case "box5":
				//PlaySound("PEOPLE\recoil.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Swamp_wreck_inside", "goto", "goto9");
				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Loghouse")
	{
		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="Swamp_grot")
	{
		if(CheckAttribute(chr, "quest.buried_skeleton") && chr.quest.buried_skeleton == "visible")
		{
			PlaySound("OBJECTS\VOICES\skeleton_body3.wav");
			LaunchItemsBox(&ar);
			return;
		}
		else
		{
			if(IsEquipCharacterByItem(chr, "MinersSpade"))
			{
				LAi_SetFightMode(chr, true);

				LAi_QuestDelay("use_MinersSpade_on_grave", 1.0);
			}
			else
			{
				if(IsEquipCharacterByItem(chr, "MinersPick"))
				{
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("wrong_use_MinersPick_on_grave", 1.0);
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
				Logit(TranslateString("","Looks like someone has been digging here.."));
			}
		}

		return;
	}

	if(Locations[locidx].id=="QC_town")
	{
		switch(chr.boxname)
		{
			case "box1":
				ChangeCharacterAddressGroup(chr, "QC_town", "goto", "roof2");
				PlaySound("PEOPLE\Jump_Roof.wav");
			break;

			case "box2":
				ChangeCharacterAddressGroup(chr, "QC_town", "goto", "roof3");
				PlaySound("PEOPLE\Jump_Roof.wav");
			break;
		
			case "box3":
				ChangeCharacterAddressGroup(chr, "QC_town", "goto", "roof4");
				PlaySound("PEOPLE\Jump_Roof.wav");
			break;

			case "box4":
				ChangeCharacterAddressGroup(chr, "QC_town", "goto", "roof5");
				PlaySound("PEOPLE\Jump_Stone.wav");
				LAi_SetStayType(chr);
			break;

			case "box7":
				PlaySound("INTERFACE\creak.wav");

				LAi_QuestDelay("arrive_store_upstairs", 1.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="wr_sacristy")
	{
		switch(chr.boxname)
		{
			case "box1":
				//scales
				if(CheckCharacterItem(chr,"coin4"))
				{
					PlaySound("INTERFACE\coin_drop.wav");

					LAi_QuestDelay("sacristy_scales_coin4", 2.0);
				}
				else
				{
					if(CheckCharacterItem(chr,"coin4_bad"))
					{
						Logit(TranslateString("","The pieces-of-eight vary too much in weight to be of any use!"));
						PlaySound("INTERFACE\coin_drop.wav");
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"coin1") || CheckCharacterItem(chr,"coin2") || CheckCharacterItem(chr,"coin3")
					|| CheckCharacterItem(chr,"coin5") || CheckCharacterItem(chr,"coin6") || CheckCharacterItem(chr,"coin7")
					|| CheckCharacterItem(chr,"coin8") || CheckCharacterItem(chr,"coin9") || CheckCharacterItem(chr,"coin10")
					|| CheckCharacterItem(chr,"coin11") || CheckCharacterItem(chr,"coin12") || CheckCharacterItem(chr,"coin13")
					|| CheckCharacterItem(chr,"coin14") || CheckCharacterItem(chr,"coin15") || CheckCharacterItem(chr,"coin16"))
					{
						PlaySound("INTERFACE\coin_drop.wav");

						LAi_QuestDelay("sacristy_scales_other_coin", 2.0);
					}
				}
				else
				{
					Logit(TranslateString("","Scales hmm...?"));
					PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				}
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.votiv_lever") && chr.quest.votiv_lever == "F")
				{
					ChangeCharacterAddressGroup(chr, "wr_sacristy", "reload", "reload4");
					PlaySound("PEOPLE\recoil.wav");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="stonehouse_inside")
	{
		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_booty")
	{
		switch(chr.boxname)
		{
			case "box4":
				if(CheckAttribute(chr, "quest.Friday_room") && chr.quest.Friday_room == "open")
				{
					ChangeCharacterAddressGroup(chr, "wr_booty", "reload", "reload4");
					PlaySound("PEOPLE\creak2.wav");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;

			case "box5":
				ChangeCharacterAddressGroup(chr, "wr_booty", "goto", "reload3");
				PlaySound("PEOPLE\creak2.wav");
			break;

			//default
			PlaySound("INTERFACE\locked_window.wav");
			return;
		}

		return;
	}

	if(Locations[locidx].id=="ck_drawing_room")
	{
		PlaySound("INTERFACE\locked_window.wav");
		return;
	}

	if(Locations[locidx].id=="JRH_tavern_upstairs")
	{
		switch(chr.boxname)
		{
			case "box1":
				//standard chest, in this case 'stuck'
				PlaySound("AMBIENT\JAIL\jail_door1.wav");
				Log_SetStringToLog(TranslateString("","You try to pick the lock with your knife... in vain!"));
				return;
			break;

			case "box2":
				//remove hatch
				LAi_SetFightMode(chr, true);
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				Locations[FindLocation(chr.location)].models.always.locators = "LH_F2_l_JRH_open";
				Locations[FindLocation("JRH_tavern_upstairs")].image = "";

				LAi_QuestDelay("open_tavern_upstairs_hatch", 1.0);
			break;

			case "box3":
				//put back hatch
				LAi_SetFightMode(chr, true);
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				Locations[FindLocation(chr.location)].models.always.locators = "LH_F2_l_JRH_closed";
				Locations[FindLocation("JRH_tavern_upstairs")].image = "";

				LAi_QuestDelay("close_tavern_upstairs_hatch", 1.0);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="wr_wood_tower2")
	{
		switch(chr.boxname)
		{
			case "box1":
				//store04_locators_JRH6, small cannon pointing out

				if(CheckAttribute(chr, "quest.swivelgun") && chr.quest.swivelgun == "charged")
				{
					if(CheckAttribute(chr, "quest.wet_gp") && chr.quest.wet_gp == "yes")
					{
						LAi_SetSitType(chr);
						PlaySound("OBJECTS\duel\wet_gunpowder.wav");
						CreateParticleSystem("gunfire_black" , 5.3, 4.45, 3.0, 5.3, 7.0, 3.0, sti(20) );
						CreateParticleSystem("gunfire_black" , 5.3, 4.45, 2.2, 5.3, 7.0, 2.2, sti(20) );
						chr.quest.swivelgun = "not_charged";

						LAi_QuestDelay("pchar_playertype", 0.5);
						LAi_QuestDelay("swivelgun_longer_black_smoke", 2.0);
					}
					else
					{
						LAi_SetSitType(chr);
						PlaySound("OBJECTS\SHIPCHARGE\CR24C.wav");
						CreateParticleSystem("smoke_short" , 5.3, 4.45, 3.0, 5.3, 7.0, 3.0, sti(20) );
						CreateParticleSystem("smoke_short" , 5.3, 4.45, 2.2, 5.3, 7.0, 2.2, sti(20) );
						chr.quest.swivelgun = "not_charged";

						if(CheckAttribute(chr, "quest.spriggs") && chr.quest.spriggs == "in_wood_tower")
						{
							chr.quest.spriggs = "on_shore";
							LAi_QuestDelay("spriggs_arrives", 3.0);
						}

						LAi_QuestDelay("pchar_playertype", 0.5);
						LAi_QuestDelay("swivelgun_longer_smoke", 5.0);
					}
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");

					LAi_QuestDelay("swivelgun_turn", 1.5);
				}
			break;

			case "box2":
				//store04_locators_JRH7, small cannon pointing in

				if(CheckAttribute(chr, "quest.swivelgun") && chr.quest.swivelgun == "charged")
				{
					PlaySound("PEOPLE\creak2.wav");

					LAi_QuestDelay("swivelgun_turn", 1.5);
				}
				else
				{
					gp = GetCharacterItem(chr, "gunpowder");

					if(gp >=6)
					{
						PlaySound("PEOPLE\powderhorn.wav");
						chr.quest.swivelgun = "charged";
						TakeNItems(chr, "gunpowder", -6);
					}
					else
					{
						Logit(TranslateString("","There is not enough Gunpowder"));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					}
				}
			break;

			case "box3":
				//flagchest
				if(CheckCharacterItem(chr,"key19"))
				{
					PlaySound("INTERFACE\key_unlock2.wav");
					chr.quest.flagchest = "open";
					TakeItemFromCharacter(chr, "key19");

					LAi_QuestDelay("pick_up_pirate_flag", 0.5);
				}
				else
				{
					if(CheckAttribute(chr, "quest.flagchest") && chr.quest.flagchest == "open")
					{
						LaunchItemsBox(&ar);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_wood_tower3")
	{
		switch(chr.boxname)
		{
			case "box1":
				//pull down ladder

				if(IsEquipCharacterByItem(chr, "bladeboathook_1"))
				{
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladeboathook_1");
					GiveItem2Character(chr, "bladeboathook_2");
					EquipCharacterByItem(chr, "bladeboathook_2");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_wood_tower3")], false);
					LAi_SetPlayerType(chr);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("prepare_pull_down_ladder", 1.0);
				}
				else
				{
					Logit(TranslateString("","Hmm, that hatch is too high up."));
					PlaySound("AMBIENT\JAIL\sigh.wav");

					if(CheckAttribute(chr,"quest.wt3_musket") && chr.quest.wt3_musket == "picked_up")
					{
						return;
					}
					else
					{
						if(CheckAttribute(chr,"quest.wt3_notice_musket") && chr.quest.wt3_notice_musket == "yes")
						{
							return;
						}
						else
						{
							LAi_SetStayType(chr);
							chr.quest.wt3_notice_musket = "yes";

							LAi_QuestDelay("notice_wt3_musket", 1.5);
						}
					}
				}
			break;

			case "box2":
				ChangeCharacterAddressGroup(chr, "wr_wood_tower3", "goto", "wall0");
				PlaySound("PEOPLE\run_wood.wav");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_cave_shore")
	{
		switch(chr.boxname)
		{
			case "box1":
				chr.quest.wood_tower_route = "way_down";		//all cases

				//NO FLAG
				if(Locations[FindLocation(chr.location)].models.always.locators == "Shore04_l_JRH3"
				|| Locations[FindLocation(chr.location)].models.always.locators == "Shore04_l_JRH4")
				{
					if(CheckAttribute(chr, "quest.flag_pole") && chr.quest.flag_pole == "locked") return;

					chr.quest.flag_pole = "locked";

					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeflag_pir")
					{

						if(chr.equip.blade == "bladeflag_pir")
						{
							locations[locidx].townsack = "Grand Turk";
							chr.quest.equip_flag = "pirate";
							chr.quest.hoist_flag = "pirate";
						}

						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);

						if(Locations[FindLocation(chr.location)].models.always.locators == "Shore04_l_JRH3")
						Locations[FindLocation(chr.location)].models.always.locators = "Shore04_l_JRH3F";

						if(Locations[FindLocation(chr.location)].models.always.locators == "Shore04_l_JRH4")
						Locations[FindLocation(chr.location)].models.always.locators = "Shore04_l_JRH4F";

						//TraceAndLog("itemLogic hoist_flag");
						LAi_QuestDelay("hoist_flag", 1.0);
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.locators == "Shore04_l_JRH3_spyglass")
					{
						//NO FLAG (pchar has picked up spyglass to check boat on shore)

						switch(chr.quest.wood_tower_view_direction)
						{
							case "right":
								LAi_SetPlayerType(chr);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("boat_zoom", 1.0);
							break;

							case "front":
								LAi_SetActorType(chr);
								LAi_ActorTurnToLocator(chr, "ships_other", "ship_21");
								chr.quest.wood_tower_view_direction = "right";

								LAi_QuestDelay("blaze_huh", 1.0);
							break;

							case "left":
								LAi_SetActorType(chr);
								LAi_ActorTurnToLocator(chr, "ships_other", "ship_6");
								chr.quest.wood_tower_view_direction = "front";
							break;

							case "start":
								LAi_SetActorType(chr);
								LAi_ActorTurnToLocator(chr, "ships_other", "ship_10");
								chr.quest.wood_tower_view_direction = "left";
							break;
						}
						return;
					}
				}
			break;

			case "box2":
				//ladder in water
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr, "bladeladder2");
				EquipCharacterByItem(chr, "bladeladder2");

				Locations[FindLocation(chr.location)].models.always.locators = "Shore04_l_JRH2";

				LAi_QuestDelay("pick_up_ship_ladder", 0.1);
			break;

			case "box3":
				//chest at boat
				if(CheckAttribute(chr, "quest.Bunce") && chr.quest.Bunce == "awaken") return;

				if(CheckAttribute(chr, "quest.cave_shore_pirates") && chr.quest.cave_shore_pirates == "trying_to_lift")
				{
					return;
				}
				else
				{
					if(CheckAttribute(chr, "quest.cave_shore_pirates") && chr.quest.cave_shore_pirates == "lifting")
					{

						if(CheckAttribute(chr, "quest.cave_shore_red_chest") && chr.quest.cave_shore_red_chest == "free")
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladewhistle");
							GiveItem2Character(chr, "bladechest_red");
							EquipCharacterByItem(chr, "bladechest_red");

							TakeItemFromCharacter(chr, "bladeflag_eng");
							TakeItemFromCharacter(chr, "bladeflag_fra");
							TakeItemFromCharacter(chr, "bladeflag_spa");
							TakeItemFromCharacter(chr, "bladeflag_por");
							TakeItemFromCharacter(chr, "bladeflag_hol");
							TakeItemFromCharacter(chr, "bladeflag_pir");

							locations[FindLocation("wr_wood_tower2")].reload.l4.disable = 1;//locked to balcony

							LAi_QuestDelay("equip_redchest_caveshore", 0.1);
							return;
						}
						else return;
					}
				}
				else
				{
					ChangeCharacterAddressGroup(chr, "wr_cave_shore", "goto", "boat7D");
					chr.quest.cave_shore_boat = "ground";
					PlaySound("PEOPLE\step_ground1.wav");
					PlaySound("PEOPLE\step_ground1.wav");

					if(CheckAttribute(chr, "quest.cave_shore_pirates") && chr.quest.cave_shore_pirates == "actors")
					{
						LAi_SetOfficerType(CharacterFromID("pir_cap6"));
						LAi_SetOfficerType(CharacterFromID("pir_cap10"));
						LAi_SetOfficerType(CharacterFromID("pir_cap11"));
						LAi_SetOfficerType(CharacterFromID("pir_cap17"));
						LAi_SetOfficerType(CharacterFromID("pir_cap21"));
						LAi_SetOfficerType(CharacterFromID("pir_cap24"));

						chr.quest.cave_shore_pirates = "officers";
					}
				}
			break;

			case "box5":
				//ground at boat
				ChangeCharacterAddressGroup(chr, "wr_cave_shore", "goto", "boat7");
				chr.quest.cave_shore_boat = "chest";
				PlaySound("PEOPLE\step_stone.wav");

				if(CheckAttribute(chr,"quest.stuck_red_chest") && chr.quest.stuck_red_chest == "observed")
				{
					return;
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					chr.quest.stuck_red_chest = "observed"
					Logit(TranslateString("","The Chest from the Blue Cavern - and it's stuck under the Boat!"));
					AddQuestRecord("Cave_shore", "5");
				}
			break;

			case "box4":
				//place ladder at cliff
				if(chr.equip.blade == "bladeladder2")
				{
					LAi_SetFightMode(chr, true);
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("place_ladder_cave_shore", 1.0);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				}
			break;

			case "box6":
				//head visible in tower top
		
				if(CheckAttribute(chr, "flag_knowledge") && chr.flag_knowledge == "yes")
				{

				}
				else DoQuestReloadToLocation("wr_wood_tower3", "goto", "stairs", "wood_top_down3");
			break;

			case "box7":
				//from sacristy between
				ChangeCharacterAddressGroup(chr, "wr_cave_shore", "goto", "arrive");
				PlaySound("PEOPLE\run_roof.wav");
			break;

			case "box8":
				//climb ladder up
				ChangeCharacterAddressGroup(chr, "wr_cave_shore", "reload", "reload6");
				PlaySound("PEOPLE\creak2.wav");
			break;

			case "box9":
				//climb ladder down
				ChangeCharacterAddressGroup(chr, "wr_cave_shore", "goto", "reload5");
				PlaySound("PEOPLE\step_grass1.wav");
			break;

			case "box10":
				//NO FLAG (pchar has picked up spyglass to check boat on shore)
	
					switch(chr.quest.wood_tower_view_direction)
					{
						case "right":
							LAi_SetPlayerType(chr);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("boat_zoom", 1.0);
						break;

						case "front":
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "ships_other", "ship_21");
							chr.quest.wood_tower_view_direction = "right";

							LAi_QuestDelay("blaze_huh", 1.0);
						break;
					}
					return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_church_inside")
	{
		switch(chr.boxname)
		{
			case "box1":
				//collection box

				LaunchItemsBox(&ar);

				LAi_QuestDelay("collection_box", 0.1);
			break;

			case "box2":
				//ship lever

			if(CheckAttribute(chr, "quest.votiv_lever_function") && chr.quest.votiv_lever_function == "temp_off")
			{
				return;
			}
			else
			{
				PlaySound("INTERFACE\lever_up.wav");
				chr.quest.votiv_lever_function = "temp_off";

				if(Locations[FindLocation("wr_church_inside")].models.always.l3 == "lever_down_B")
				{
					chr.quest.votiv_lever = "M";
					Locations[FindLocation("wr_church_inside")].models.always.l3 = "lever_down_M";
					Locations[FindLocation("wr_church_inside")].reload.l1.disable = 1;
					Locations[FindLocation("wr_sacristy")].reload.l1.disable = 0;
				}
				else
				{
					if(Locations[FindLocation("wr_church_inside")].models.always.l3 == "lever_down_M")
					{
						chr.quest.votiv_lever = "F";
						Locations[FindLocation("wr_church_inside")].models.always.l3 = "lever_down_F";
						Locations[FindLocation("wr_church_inside")].reload.l1.disable = 1;
						Locations[FindLocation("wr_sacristy")].reload.l1.disable = 1;
					}
				}
				else
				{
					if(Locations[FindLocation("wr_church_inside")].models.always.l3 == "lever_down_F")
					{
						chr.quest.votiv_lever = "B";
						Locations[FindLocation("wr_church_inside")].models.always.l3 = "lever_down_B";
						Locations[FindLocation("wr_church_inside")].reload.l1.disable = 0;
						Locations[FindLocation("wr_sacristy")].reload.l1.disable = 1;
					}
				}

				LAi_QuestDelay("votiv_ship", 0.5);
			}
			break;

			case "box3":
				//to pulpit

				ChangeCharacterAddressGroup(chr, "wr_church_inside", "goto", "pulpit");
				PlaySound("PEOPLE\step_stairway.wav");
			break;

			case "box4":
				//from pulpit

				ChangeCharacterAddressGroup(chr, "wr_church_inside", "box", "box3");
				PlaySound("PEOPLE\step_echo1.wav");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="church_choir")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.choir_box1") && chr.quest.choir_box1 == "open")
				{
					PlaySound("INTERFACE\Closet_Open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("choir_many_animists_check", 0.1);
				}
				else PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box2":
				switch(chr.quest.choir_ladder)
				{
					case "not_found":
						PlaySound("AMBIENT\JAIL\jail_door1.wav");
						Logit(TranslateString("","The lock is too rusty - I can't move the key."));
					break;

					case "found":
						if(IsEquipCharacterByItem(chr, "bladeladder"))
						{
							if(LAi_IsFightMode(chr))
							{
								//this is your 2:nd 'open box'
								if(CheckAttribute(chr,"quest.choir_box2B") && chr.quest.choir_box2B == "on")
								{
									return;
								}
								else
								{
									chr.quest.choir_box2B = "on";
									PlaySound("OBJECTS\DUEL\man_attack1.wav");

									LAi_QuestDelay("choir_box2B_off", 1.0);
									LAi_QuestDelay("place_ladder_choir_box2", 1.0);
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.choir_box2A") && chr.quest.choir_box2A == "on")
								{
									return;
								}
								else
								{
									chr.quest.choir_box2A = "on";
									ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck2");
									LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
									LAi_SetFightMode(chr, true);

									LAi_QuestDelay("choir_box2A_off", 1.0);
									LAi_QuestDelay("stay_at_choir_box2", 1.0);
								}
							}
						}
						else
						{
						 	PlaySound("AMBIENT\JAIL\jail_door1.wav");
							Logit(TranslateString("","The lock is too rusty - I can't move the key."));
						}
					break;

					case "placed":
						//later when ladder is placed
						PlaySound("PEOPLE\step_stairway.wav");
						ChangeCharacterAddressGroup(chr, "church_choir", "goto", "ladder1");

						LAi_QuestDelay("choir_ladder_up", 1.0);
					break;

					case "oilbottle":
						if(IsEquipCharacterByItem(chr, "bladeoilbottle"))
						{
							if(LAi_IsFightMode(chr))
							{
								//this is your 2:nd 'open box'

								if(CheckAttribute(chr,"quest.choir_box2D") && chr.quest.choir_box2D == "on")
								{
									return;
								}
								else
								{
									chr.quest.choir_box2D = "on";
									PlaySound("PEOPLE\oil_unlock.wav");

									LAi_QuestDelay("choir_box2D_off", 4.0);
									LAi_QuestDelay("oilbottle_choir_box2", 3.0);
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.choir_box2C") && chr.quest.choir_box2C == "on")
								{
									return;
								}
								else
								{
									chr.quest.choir_box2C = "on";
									ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck2");
									LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
									LAi_SetFightMode(chr, true);

									LAi_QuestDelay("choir_box2C_off", 1.0);
									LAi_QuestDelay("stay_at_choir_box2", 1.0);
								}
							}
						}
						else
						{
							PlaySound("PEOPLE\step_stairway.wav");
							ChangeCharacterAddressGroup(chr, "church_choir", "goto", "ladder1");

							LAi_QuestDelay("choir_ladder_up", 1.0);
						}
					break;

					case "blocking":
						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							if(CheckAttribute(chr,"quest.choir_box2F") && chr.quest.choir_box2F == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box2F = "on";
								PlaySound("OBJECTS\DUEL\man_attack1.wav");

								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr, "bladeladder");
								EquipCharacterbyItem(chr, "bladeladder");

								LAi_QuestDelay("choir_box2F_off", 2.5);
								LAi_QuestDelay("remove_ladder_choir_box2", 0.5);
							}
						}
						else
						{
							if(CheckAttribute(chr,"quest.choir_box2E") && chr.quest.choir_box2E == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box2E = "on";
								ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck2");
								LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("choir_box2E_off", 1.0);
								LAi_QuestDelay("stay_at_choir_box2", 1.0);
							}
						}
					break;

					case "open_chest":
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);

						LAi_QuestDelay("choir_churchsilver_check", 0.1);
					break;
				}
				return;
			break;

			case "box3":
				if(CheckAttribute(chr, "quest.choir_box3") && chr.quest.choir_box3 == "open")
				{
					PlaySound("INTERFACE\Closet_Open.wav");
					LaunchItemsBox(&ar);
				}
				else
				{
					if(IsEquipCharacterByItem(chr, "PiratesDagger"))
					{
						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							if(CheckAttribute(chr,"quest.choir_box3") && chr.quest.choir_box3 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box3 = "on";
								PlaySound("PEOPLE\knife_closet.wav");

								LAi_QuestDelay("choir_box3_off", 2.5);
								LAi_QuestDelay("knifeuse_choir_box3", 2.5);
							}
						}
						else
						{
							if(CheckAttribute(chr,"quest.choir_box3") && chr.quest.choir_box3 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box3 = "on";
								ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck3");
								LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("choir_box3_off", 1.0);
								LAi_QuestDelay("stay_at_choir_box3", 1.0);
							}
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");

						Logit(TranslateString("","Neither lock nor handle. How do I open it?"));
					}
				}
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.choir_box4") && chr.quest.choir_box4 == "open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
				}
				else
				{
					if(IsEquipCharacterByItem(chr, "bladelockpick"))
					{
						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							if(CheckAttribute(chr,"quest.choir_box4") && chr.quest.choir_box4 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box4 = "on";
								PlaySound("PEOPLE\lockpick.wav");

								LAi_QuestDelay("choir_box4_off", 3.0);
								LAi_QuestDelay("lockpick_choir_box4", 3.0);
							}
						}
						else
						{
							if(CheckAttribute(chr,"quest.choir_box4") && chr.quest.choir_box4 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box4 = "on";
								ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck4");
								LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("choir_box4_off", 1.0);
								LAi_QuestDelay("stay_at_choir_box4", 1.0);
							}
						}
					}
					else PlaySound("INTERFACE\door_locked2.wav");
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.choir_box5") && chr.quest.choir_box5 == "open")
				{
					PlaySound("INTERFACE\Closet_Open.wav");
					LaunchItemsBox(&ar);
				}
				else
				{
					if(IsEquipCharacterByItem(chr, "bladehandle"))
					{
						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							if(CheckAttribute(chr,"quest.choir_box5") && chr.quest.choir_box5 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box5 = "on";
								PlaySound("PEOPLE\chopchop.wav");

								LAi_QuestDelay("choir_box5_off", 1.5);
								LAi_QuestDelay("handle_choir_box5", 1.5);
							}
						}
						else
						{
							if(CheckAttribute(chr,"quest.choir_box5") && chr.quest.choir_box5 == "on")
							{
								return;
							}
							else
							{
								chr.quest.choir_box5 = "on";
								ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck5");
								LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("choir_box5_off", 1.0);
								LAi_QuestDelay("stay_at_choir_box5", 1.0);
							}
						}
					}
					else{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
						Logit(TranslateString("","Neither lock nor handle. How do I open it?"));
					}
				}
			break;

			case "box6":
				if(CheckAttribute(chr,"quest.choir_box6") && chr.quest.choir_box6 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box6 = "on";
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("choir_box6_off", 1.0);
					LAi_QuestDelay("choir_clock_up", 0.5);
				}
			break;

			case "box7":
				PlaySound("INTERFACE\paper.wav");
			break;

			case "box8":
				PlaySound("INTERFACE\cello.wav");
			break;

			case "box9":
				PlaySound("INTERFACE\flute.wav");
			break;

			case "box10":
				if(CheckAttribute(chr,"quest.choir_box10") && chr.quest.choir_box10 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box10 = "on";
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("choir_box10_off", 1.0);
					LAi_QuestDelay("choir_ladder_down", 1.0);
				}
			break;

			case "box11":
				PlaySound("INTERFACE\paper.wav");
			break;

			case "box12":
				if(CheckAttribute(chr,"quest.choir_box12") && chr.quest.choir_box12 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box12 = "on";
					PlaySound("INTERFACE\book_close.wav");

					LAi_QuestDelay("choir_box12_off", 1.0);
				}
			break;

			case "box13":
				if(CheckAttribute(chr,"quest.choir_box13") && chr.quest.choir_box13 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box13 = "on";
					PlaySound("INTERFACE\violin.wav");
					
					LAi_QuestDelay("choir_box13_off", 1.0);
					LAi_QuestDelay("choir_violin_right_down", 1.0);
				}
			break;

			case "box14":
				if(CheckAttribute(chr,"quest.choir_box14") && chr.quest.choir_box14 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box14 = "on";
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("choir_box14_off", 1.0);
					LAi_QuestDelay("choir_violin_right_up", 0.5);
				}
			break;

			case "box15":
				if(CheckAttribute(chr,"quest.choir_box15") && chr.quest.choir_box15 == "on")
				{
					return;
				}
				else
				{
					chr.quest.choir_box15 = "on";
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("choir_box15_off", 1.0);
					LAi_QuestDelay("choir_violin_left_up", 0.5);
				}
			break;

			case "box16":
				if(CheckAttribute(chr, "quest.choir_lockpick") && chr.quest.choir_lockpick == "not_found")
				{
					if(CheckAttribute(chr,"quest.choir_box16") && chr.quest.choir_box16 == "on")
					{
						return;
					}
					else
					{
						chr.quest.choir_box16 = "on";
						PlaySound("INTERFACE\violin.wav");

						LAi_QuestDelay("choir_box16_off", 4.0);
						LAi_QuestDelay("choir_lockpick", 0.5);
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.choir_box16") && chr.quest.choir_box16 == "on")
					{
						return;
					}
					else
					{
						chr.quest.choir_box16 = "on";
						PlaySound("INTERFACE\violin.wav");
					
						LAi_QuestDelay("choir_box16_off", 1.0);
						LAi_QuestDelay("choir_violin_left_down", 0.5);
					}
				}
			break;

			case "box17":
				if(IsEquipCharacterByItem(chr, "bladekeygrand"))
				{
					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						if(CheckAttribute(chr,"quest.choir_box17") && chr.quest.choir_box17 == "on")
						{
							return;
						}
						else
						{
							chr.quest.choir_box17 = "on";
							PlaySound("INTERFACE\key_lock.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladekeygrand");
							EquipCharacterByItem(chr, "bladeX4");

							LAi_SetFightMode(chr, false);
							LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], true);

							LAi_QuestDelay("choir_box17_off", 1.0);
							LAi_QuestDelay("place_choir_clockkey", 1.0);
						}
					}
					else
					{
						if(CheckAttribute(chr,"quest.choir_box17") && chr.quest.choir_box17 == "on")
						{
							return;
						}
						else
						{
							chr.quest.choir_box17 = "on";
							LAi_LocationFightDisable(&Locations[FindLocation("church_choir")], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("choir_box17_off", 1.0);
						}
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.choir_clock") && chr.quest.choir_clock == "clock_started")
					{
						return;
					}
					else
					{
						if(CheckAttribute(chr, "quest.choir_clock") && chr.quest.choir_clock == "key_placed")
						{
							chr.quest.choir_clock = "clock_started";	//this is ok!
							PlaySound("INTERFACE\clock_wind_up.wav");

							LAi_QuestDelay("choir_wind_up_clock", 2.2);
						}
					}
					else
					{
						if(CheckAttribute(chr,"quest.choir_box17") && chr.quest.choir_box17 == "on")
						{
							return;
						}
						else
						{
							chr.quest.choir_box17 = "on";
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","It has stopped."));

							LAi_QuestDelay("choir_box17_off", 1.0);
							LAi_QuestDelay("choir_clock_down", 1.0);
						}
					}
				}
			break;

			case "box18":
				ChangeCharacterAddressGroup(chr, "church_choir", "goto", "gate19");
				PlaySound("PEOPLE\creak2.wav");
			break;

			case "box19":
				ChangeCharacterAddressGroup(chr, "church_choir", "goto", "gate18");
				PlaySound("PEOPLE\creak2.wav");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="church_wine_cellar")
	{
		switch(chr.boxname)
		{
			case "box1":
				//lever is down, cellar is dry (but a little foggy)

				Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_flood2";
				locations[FindLocation("wr_wine_cellar")].environment.sea = "true";

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_down_floor")
				{
						Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_floor";
						Locations[FindLocation("church_wine_cellar")].models.always.l1 = "";		//no elevator
						Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_down";
						SetCharacterShipLocation(characterFromID("pir_cap26"), "church_wine_cellar");

						SetCharacterShipLocation(characterFromID("pir_cap28"), "church_wine_cellar");//barrel3_roll as a ship
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_down_barrel")
				{
					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "empty")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_ship";
						Locations[FindLocation("church_wine_cellar")].models.always.l1 = "";		//no elevator
						Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_down";
						SetCharacterShipLocation(characterFromID("pir_cap26"), "church_wine_cellar");

						SetCharacterShipLocation(characterFromID("pir_cap27"), "church_wine_cellar");
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "";
					}

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "filled")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_down"
					}
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_up")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "empty")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_up";
					}

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "final")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";		//was ""
					}
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_up_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_up_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";

					SetCharacterShipLocation(characterFromID("pir_cap28"), "church_wine_cellar");
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_final")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_final";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_up";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "church_wine_cellar");

					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";					//was ""
				}

				PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation("church_wine_cellar")].models.always.l5 = "lever1_up";
				locations[FindLocation("church_wine_cellar")].environment.sea = "true";

				SetCurrentTime(11.00, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "Mine Fog 1";

				LAi_QuestDelay("church_wine_cellar_water_in", 0.5);
				return;
			break;

			case "box2":
				//lever is up, cellar is flooded

				Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_dry2";
				locations[FindLocation("wr_wine_cellar")].environment.sea = "false";

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_down")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_down_barrel";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_ship")
				{
					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "final")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_final";
						Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_final";
						Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_up";
						SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

						SetCharacterShipLocation(characterFromID("pir_cap27"), "none");
						SetCharacterShipLocation(characterFromID("pir_cap28"), "none");
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";
					}
					else
					{
						Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_down_barrel";//check!
						Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_down";
						Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_up";
						SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

						SetCharacterShipLocation(characterFromID("pir_cap27"), "none");
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_down";
					}
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_down_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_down";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_up";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

					SetCharacterShipLocation(characterFromID("pir_cap28"), "none");
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_floor";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_up")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";	//already
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";		//already

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "final")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";
					}
					else Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_up";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_up_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_up_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";	//already
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";		//already

					SetCharacterShipLocation(characterFromID("pir_cap28"), "none");
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_floor";
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_final")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_final";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_final";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_up";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

					SetCharacterShipLocation(characterFromID("pir_cap27"), "none");
					SetCharacterShipLocation(characterFromID("pir_cap28"), "none");
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";
				}

				PlaySound("INTERFACE\lever_down.wav");
				Locations[FindLocation("church_wine_cellar")].models.always.l5 = "lever1_down";
				locations[FindLocation("church_wine_cellar")].environment.sea = "false";

				SetCurrentTime(11.00, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "Mine Fog 1";

				LAi_QuestDelay("church_wine_cellar_water_out", 0.5);
				return;
			break;

			case "box3":
				//free rope end (flood_ship)
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_up_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

					SetCharacterShipLocation(characterFromID("pir_cap27"), "none");
				}
				else
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "elevator3_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_45";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "none");

					SetCharacterShipLocation(characterFromID("pir_cap27"), "none");

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "empty")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_up";
					}
				}

				LAi_QuestDelay("church_wine_cellar_rope_wall", 0.5);
				return;
			break;

			case "box4":
				//rope on wall
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_up"
				|| Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_up_floor")
				{
					Logit(TranslateString("","No, the elevator is to heavy!"));
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_up")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_ship";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_down";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "church_wine_cellar");

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "empty")
					{
						SetCharacterShipLocation(characterFromID("pir_cap27"), "church_wine_cellar");
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "";
					}

					if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "final")
					{
						Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";		//was ""
					}

					LAi_QuestDelay("church_wine_cellar_rope_free", 0.5);
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_flood_up_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_flood_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l1 = "";
					Locations[FindLocation("church_wine_cellar")].models.always.l2 = "rope_down";
					SetCharacterShipLocation(characterFromID("pir_cap26"), "church_wine_cellar");

					LAi_QuestDelay("church_wine_cellar_rope_free", 0.5);
					return;
				}
			break;

			case "box5":
				//empty barrel
				PlaySound("AMBIENT\TAVERN\open_bottle.wav");

				LAi_QuestDelay("empty_church_barrel", 0.5);
				return;
			break;

			case "box6":
				//push barrel off elevator
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				if(CheckAttribute(chr, "quest.church_barrel") && chr.quest.church_barrel == "empty")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_down_floor";
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_floor";

					LAi_QuestDelay("push_church_barrel_off_elevator", 0.5);
					return;
				}
				else
				{
					Logit(TranslateString("","No, the barrel is to heavy!"));
					return;
				}
			break;

			case "box7":
				//push barrel on OR under elevator
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_down_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_down_barrel";
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_down";

					LAi_QuestDelay("push_church_barrel_on_elevator", 0.5);
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_up_floor")
				{
					Locations[FindLocation("church_wine_cellar")].models.always.locators = "cwc_dry_up";
					Locations[FindLocation("church_wine_cellar")].models.always.l6 = "barrel3_steplock";

					LAi_QuestDelay("push_church_barrel_under_elevator", 0.5);
					return;
				}
			break;

			case "box8":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);

				if(locations[FindLocation(chr.location)].box8.items.bladebottle_CE0 >=1)
				{
					LAi_QuestDelay("empty_bottle_check", 0.1);
				}

				LAi_QuestDelay("return_from_box8_churchcellar", 1.0);
				return;
			break;

			case "box9":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);

				if(locations[FindLocation(chr.location)].box9.items.bladebottle_CE0 >=1)
				{
					LAi_QuestDelay("empty_bottle_check", 0.1);
				}

				LAi_QuestDelay("return_from_box9_churchcellar", 1.0);
				return;
			break;

			case "box10":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
				return;
			break;

			case "box11":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
				return;
			break;

			case "box12":
				PlaySound("INTERFACE\Closet_Open.wav");
				LaunchItemsBox(&ar);
				return;
			break;

			case "box13":
				//wine barrel
				if(CheckAttribute(chr,"quest.church_wine") && chr.quest.church_wine == "on")
				{
					PlaySound("INTERFACE\water_tap.wav");
					chr.quest.church_wine = "off";
					LAi_SetPlayerType(chr);

					LAi_QuestDelay("church_running_wine", 0.01);
				}
				else
				{
					if(CheckAttribute(chr,"quest.churchcellar_fillbottle") && chr.quest.churchcellar_fillbottle == "on")
					{
						return;
					}
					else
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
						{
							chr.quest.churchcellar_fillbottle = "on";
							PlaySound("INTERFACE\water_tap.wav");
							LAi_SetStayType(chr);

							LAi_QuestDelay("church_fill_winebottle", 0.5);
						}
						else
						{
							PlaySound("INTERFACE\water_tap.wav");
							chr.quest.church_wine = "on";
							LAi_SetStayType(chr);

							LAi_QuestDelay("church_running_wine", 0.5);
							LAi_QuestDelay("church_its_wine", 1.0);
						}
					}
				}
			break;

			case "box14":
				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_final")
				{
					ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "reload12");
					PlaySound("INTERFACE\rusty.wav");
				}
				else  PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box15":
				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_final")
				{
					ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "reload11");
					PlaySound("INTERFACE\rusty.wav");
				}
				else  PlaySound("INTERFACE\locked_window.wav");
			break;
		//----------------------------------------------------------------------------------------------------
			case "box16":
				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_final")
				{
					ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "box9");
					PlaySound("INTERFACE\rusty.wav");
				}
				else  PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box17":
				ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "reload9");
				PlaySound("INTERFACE\rusty.wav");
			break;
		//----------------------------------------------------------------------------------------------------
			case "box18":
				if(Locations[FindLocation(chr.location)].models.always.locators == "cwc_dry_final")
				{
					ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "box8");
					PlaySound("INTERFACE\rusty.wav");
				}
				else  PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box19":
				ChangeCharacterAddressGroup(chr, "church_wine_cellar", "goto", "reload7");
				PlaySound("INTERFACE\rusty.wav");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_farm_corridor")
	{
		switch(chr.boxname)
		{
			case "box1":
				//at candle
				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', used for picking up scroll46

					if(CheckAttribute(chr, "quest.keymiddle") && chr.quest.keymiddle == "on_counter")
					{
						PlaySound("INTERFACE\took_item.wav");
						chr.quest.keymiddle = "picked_up";
						GiveItem2Character(chr,"key18");

						Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "";
						Locations[FindLocation("wr_farm_corridor")].locators_radius.reload.reload2 = 0.0001;
						Locations[FindLocation("wr_farm_corridor")].locators_radius.box.box2 = 0.5;	//enable key funct

						LAi_QuestDelay("pick_up_key18", 0.5);
						return;
					}

					if(CheckAttribute(chr, "quest.scroll46") && chr.quest.scroll46 == "on_counter")
					{
						PlaySound("INTERFACE\paper.wav");
						chr.quest.scroll46 = "picked_up";
						GiveItem2Character(chr,"book46");

						//key only visible if candle are lit:
						if(Locations[FindLocation("wr_farm_corridor")].models.always.locators == "StoreSmall_locators_JRH_normal")
						{
							Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "keymiddle";
						}
						else Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "";

						LAi_QuestDelay("pick_up_book46", 0.5);
						return;
					}
				}
				else
				{

					string gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
					aref gun;
					Items_FindItem(gunID, &gun);

					if(CheckAttribute(gun, "model"))
					{
						if(HasSubStr(gun.model, "pistol"))
						{
							//LogIt("model is a pistol");
							LAi_QuestDelay("temp_ammo_check_corridor_pistol", 0.1);
						}
					}

					if(CheckAttribute(chr, "quest.scroll46") && chr.quest.scroll46 == "on_counter")
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					ChangeCharacterAddressGroup(chr, "wr_farm_corridor", "goto", "candle_stuck");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_corridor")], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("stay_at_candle", 1.0);
					return;
				}
			break;

			case "box2":
				//door function
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_from_corridor", 2.0);
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_farm_servant")
	{
		switch(chr.boxname)
		{
			case "box5":
				if(CheckAttribute(chr, "servant_box5") && chr.servant_box5 == "on") return;

				if(CheckCharacterItem(chr,"key36"))
				{
					chr.servant_box5 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_alchemy2_upstairs", 2.0);
				}
				else PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box1":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					PlaySound("PEOPLE\basket.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolnitre_check", 0.1);
					return;
				}
				else
				{
					PlaySound("PEOPLE\basket.wav");
					return;
				}
			break;

			case "box3":
				//hatch is hidden

				Locations[FindLocation("wr_farm_servant")].models.always.locators = "sh_l_JRH2_open";
				Locations[FindLocation("wr_farm_alchemy")].reload.l3.disable = 0;	//open from alchemy

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "reload", "reload3");

				LAi_QuestDelay("pull_carpet", 1.0);
				return;
			break;

			case "box4":
				//hatch is visible
				Locations[FindLocation("wr_farm_servant")].models.always.locators = "sh_l_JRH2_closed_doc";
				Locations[FindLocation("wr_farm_alchemy")].reload.l3.disable = 1;	//closed from alchemy

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "goto3");

				LAi_QuestDelay("pull_carpet", 1.0);
				return;
			break;
		}

		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_wine_cellar")
	{
		switch(chr.boxname)
		{
			case "box1":
				//lever is down, cellar is dry (but a little foggy)
				PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation("wr_wine_cellar")].models.always.l2 = "lever1_up";
				locations[FindLocation("wr_wine_cellar")].environment.sea = "true";

				SetCurrentTime(11.00, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "Mine Fog 1";

				if(CheckAttribute(chr,"quest.wine_cellar_enemies") && chr.quest.wine_cellar_enemies == "started")
				{
					Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_flood2";
				}
				else Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_flood1";

				LAi_QuestDelay("wr_wine_cellar_water_in", 0.5);
				return;
			break;

			case "box2":
				//lever is up, cellar is flooded
				PlaySound("INTERFACE\lever_down.wav");

				Locations[FindLocation("wr_wine_cellar")].models.always.l2 = "lever1_down";
				locations[FindLocation("wr_wine_cellar")].environment.sea = "false";

				SetCurrentTime(11.00, 0);
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "Mine Fog 1";

				if(Locations[FindLocation(chr.location)].models.always.locators == "Cellar_downstairs_locators_JRH_flood1")
					Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_dry1";

				if(Locations[FindLocation(chr.location)].models.always.locators == "Cellar_downstairs_locators_JRH_flood2")
					Locations[FindLocation("wr_wine_cellar")].models.always.locators = "Cellar_downstairs_locators_JRH_dry2";

				LAi_QuestDelay("wr_wine_cellar_water_out", 0.5);
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Defoes_cabin")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\paper.wav");
				return;
			break;

			case "box2":
				PlaySound("INTERFACE\paper.wav");
				return;
			break;

			case "box4":
				PlaySound("INTERFACE\door_locked2.wav");
				return;
			break;

			case "box5":
				PlaySound("INTERFACE\door_locked2.wav");
				return;
			break;

			case "box6":
				PlaySound("INTERFACE\paper.wav");
				return;
			break;

			LaunchItemsBox(&ar);
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_captain")
	{
		switch(chr.boxname)
		{
			case "box3":
				string weaponID7 = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);
				aref weapon7;
				Items_FindItem(weaponID7, &weapon7);

				if(CheckAttribute(chr,"quest.gall_captain") && chr.quest.gall_captain == "open")
				{
					Logit(TranslateString("","Cannonball storage"));
					PlaySound("PEOPLE\step_iron.wav");
					PlaySound("PEOPLE\step_iron.wav");
					PlaySound("PEOPLE\step_iron.wav");
					return;
				}

				if(LAi_IsFightMode(chr))
				{
					PlaySound("PEOPLE\blade_basket.wav");
					PlaySound("OBJECTS\DUEL\sword_broken.wav");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeNItems(chr, weaponID7, -20);
					EquipCharacterByItem(chr, "bladeX4");

					EquipCharacterByItem(chr, "pistol203");

					LAi_QuestDelay("cannonballs_again", 2.0);
				}
				else
				{
					if(CheckAttribute(weapon7, "id"))
					{
						if(weapon7.id == "bladeX4" || weapon7.id == ""
						|| weapon7.id == "bladepowderhornA" || weapon7.id == "bladepowderhornP" )
						{
							Logit(TranslateString("","I need a blade to open that box!"));
						}
					}

					if(CheckCharacterItem(chr,"bladeA11"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeA11");
					}

					LAi_SetFightMode(chr, true);
					return;
				}
			break;

			LaunchItemsBox(&ar);
		}
		return;
	}

	if(Locations[locidx].id=="wr_corv_capmd")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box2":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box3":
				if(CheckAttribute(chr,"quest.ship_wc") && chr.quest.ship_wc == "sit_down")
				{
					PlaySound("PEOPLE\Toilet.wav");

					LAi_QuestDelay("ship_wc", 1.5);	//was 2.3
				}

				if(CheckAttribute(chr,"quest.ship_wc") && chr.quest.ship_wc == "start")
				{
					ChangeCharacterAddressGroup(chr, "wr_corv_capmd", "goto", "wc_stay");
					LAi_SetSitType(chr);
					PlaySound("AMBIENT\JAIL\sigh.wav");
					chr.quest.ship_wc = "sit_down";
				}
			break;

			case "box4":
				ChangeCharacterAddressGroup(chr, "wr_corv_capmd", "goto", "wc_stay");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_corv_capsm")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("PEOPLE\ram.wav");

				if(Locations[FindLocation("wr_corv_capsm")].reload.l1.disable == 1)
				{
					LAi_QuestDelay("unlock_capsm_crew", 0.5);
				}

				if(Locations[FindLocation("wr_corv_capsm")].reload.l1.disable == 0)
				{
					LAi_QuestDelay("lock_capsm_crew", 0.5);
				}
			break;

			case "box3":
				//placing barrel2 on floor

				if(CheckCharacterItem(chr,"bladebarrel2"))
				{
					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						if(CheckCharacterItem(chr,"bladebarrel2"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebarrel2");

							if(CheckCharacterItem(chr,"bladeanchor"))
							{
								EquipcharacterByItem(chr, "bladeanchor");
							}
							else EquipcharacterByItem(chr, "bladepclub203");

							Locations[FindLocation("wr_corv_capsm")].models.always.locators = "capsm_l_JRH2";//barrel placed
							Locations[FindLocation("wr_corv_capsm")].image = "";
							DoQuestReloadToLocation("wr_corv_capsm", "goto", "barrel", "Vane_at_corvette6");
						}
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("wr_corv_capsm")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else 
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I have to search for something to step on here."));
				}
			break;

			case "box4":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_capsm", "reload", "reload3");

				LAi_QuestDelay("enter_via_wc", 1.0);
			break;

			LaunchItemsBox(&ar);
			return;
		}
		return;
	}

	if(Locations[locidx].id=="wr_corv_crew")
	{
		switch(chr.boxname)
		{
			case "box3":
				//door to yellow deck
				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', using bladeitems. (fire gun = gunitems)
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladekeysimple")
					{
						PlaySound("INTERFACE\key_unlock.wav");

						LAi_QuestDelay("unlock_crew_deck1", 1.0);
					}

					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladecompasses")
					{
						if(CheckAttribute(chr,"quest.beltkey") && chr.quest.beltkey == "on_map")
						{
							if(CheckAttribute(chr,"quest.tablemap") && chr.quest.tablemap == "on_floor")
							{
								//pick up key here
								PlaySound("INTERFACE\took_item.wav");
								chr.quest.beltkey = "picked_up";
								GiveItem2Character(chr, "bladekeysimple");
								EquipCharacterByItem(chr, "bladekeysimple");
								Locations[FindLocation("wr_corv_crew")].models.always.l3 = "";//no key
								Locations[FindLocation("wr_corv_crew")].models.always.l2 = "";//no map
								TakeItemFromCharacter(chr, "bladecompasses");
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								TakeItemFromCharacter(chr, "pistolhand");

								LAi_QuestDelay("use_gunitem_at_belt_door", 1.0);
							}
							else LAi_QuestDelay("use_bladeitem_at_belt_door", 1.0);//???
						}

						if(CheckAttribute(chr,"quest.beltkey") && chr.quest.beltkey == "in_lock")
						{
							if(CheckAttribute(chr,"quest.tablemap") && chr.quest.tablemap == "under_door")
							{
								PlaySound("PEOPLE\beltkey_drop.wav");
								chr.quest.beltkey = "on_map";

								LAi_QuestDelay("use_bladeitem_at_belt_door", 1.0);
							}
							else
							{
								PlaySound("PEOPLE\beltkey.wav");
								Logit(TranslateString("","The door is locked from the other side with the key still in the lock."));

								LAi_QuestDelay("use_bladeitem_at_belt_door", 1.0);
							}
						}
					}
				}
				else
				{
					ChangeCharacterAddressGroup(chr, "wr_corv_crew", "goto", "goto8");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "goto10");

					LAi_QuestDelay("stay_at_belt_door", 0.5);
					return;
				}
			break;

			case "box4":
				if(CheckAttribute(chr,"quest.crew_to_ships") && chr.quest.crew_to_ships == "closed")
				{
					Logit(TranslateString("","Prize ships"));
					PlaySound("INTERFACE\knock.wav");
					return;
				}
				else
				{
					ChangeCharacterAddressGroup(chr, "wr_corv_crew", "reload", "reload3");
					PlaySound("PEOPLE\creak2.wav");
				}
			break;

			LaunchItemsBox(&ar);
			return;
		}
		return;
	}

	if(Locations[locidx].id=="wr_farm_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				//niche is hidden
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				Locations[FindLocation(chr.location)].models.always.locators = "largehouse02_locators_JRH2";
				Locations[FindLocation("wr_farm_bedroom")].image = "";

				if(CheckAttribute(chr,"quest.book49_check") && chr.quest.book49_check == "off")
				{
					chr.quest.book49_check = "on";
					LAi_QuestDelay("book49_pickup_check", 0.1);
				}

				LAi_QuestDelay("change_bedroom_chart", 1.0);
			break;

			case "box4":
				//niche is open
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				Locations[FindLocation(chr.location)].models.always.locators = "largehouse02_locators_JRH1";
				Locations[FindLocation("wr_farm_bedroom")].image = "";

				LAi_QuestDelay("change_bedroom_chart", 1.0);
			break;

			case "box2":
				//window is closed
				if(Locations[FindLocation("wr_farm_bedroom")].models.always.window == "largehouse02_windows")
				{
					PlaySound("PEOPLE\beltkey.wav");
					Locations[FindLocation("wr_farm_bedroom")].models.always.window = "largehouse02_windows2";	//1 closed hatch
					Locations[FindLocation("wr_farm_bedroom")].models.always.l4 = "largehouse02_windows3";		//1 open hatch
					Locations[FindLocation("wr_farm_bedroom")].locators_radius.box.box2 = 0.0001;
					Locations[FindLocation("wr_farm_bedroom")].locators_radius.box.box3 = 0.7;	//was 1.0
					locations[FindLocation("wr_farm_bedroom")].type = "indian_seashore";
					Locations[FindLocation("wr_farm_bedroom")].image = "";

					LAi_QuestDelay("open_bedroom_window", 1.0);
				}
			break;

			case "box3":
				//window is open
				if(Locations[FindLocation("wr_farm_bedroom")].models.always.window == "largehouse02_windows2")
				{
					PlaySound("PEOPLE\creak2.wav");
					Locations[FindLocation("wr_farm_bedroom")].models.always.window = "largehouse02_windows";	//2 closed hatches
					Locations[FindLocation("wr_farm_bedroom")].models.always.l4 = "";		//no open hatch
					Locations[FindLocation("wr_farm_bedroom")].locators_radius.box.box2 = 0.7;	//was 1.0
					Locations[FindLocation("wr_farm_bedroom")].locators_radius.box.box3 = 0.0001;
					locations[FindLocation("wr_farm_bedroom")].type = "Rogers_private";
					Locations[FindLocation("wr_farm_bedroom")].image = "";

					LAi_QuestDelay("close_bedroom_window", 1.0);
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "farm_counter") && chr.farm_counter == "open")
				{
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("newspapers_check", 0.1);
				}
				else
				{
					//locked from start
					if(CheckCharacterItem(chr,"key17"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.farm_counter = "open";
						TakeItemFromCharacter(chr, "key17");
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_corv_deck1")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(IsEquipCharacterByItem(chr, "bladebottle_CT2_sulf_w"))
				{
					ChangeCharacterAddressGroup(chr, "wr_corv_deck1", "goto", "goto3");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "goto4");

					LAi_QuestDelay("acid_copper_door", 1.0);
				}
			break;

			case "box2":
				PlaySound("PEOPLE\Jump_Counter.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_deck1", "goto", "crate2");

				LAi_QuestDelay("yellow_jump_crate2", 0.5);
			break;

			case "box3":
				PlaySound("PEOPLE\Jump_Counter.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_deck1", "goto", "crate3");

				LAi_QuestDelay("yellow_jump_crate3", 0.5);
			break;

			case "box4":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_deck1", "goto", "stair");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_galley")
	{
		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_farm_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolretort3_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\small_door_locked.wav");
					return;
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_farm_alchemy")
	{
		switch(chr.boxname)
		{
			case "box8":
				if(CheckAttribute(chr, "alchemy_box8") && chr.alchemy_box8 == "on") return;

				if(CheckCharacterItem(chr,"key36"))
				{
					chr.alchemy_box8 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_alchemy2_downstairs", 2.0);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box1":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolcalciumsack_check", 0.1);
					LAi_QuestDelay("pistolcharcoal_WR_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box2":
				//LEVER
				if(CheckAttribute(chr,"quest.alchemy_lever") && chr.quest.alchemy_lever == "down")
				{
						PlaySound("INTERFACE\lever_up.wav");
						chr.quest.alchemy_lever = "up";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l6 = "lever1_up";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l4 = "bars_up";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l3 = "plank_down";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l7 = "rope_down";

						Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box4 = 0.5;//at fireplace
						Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box3 = 0.0001;//plank disabled

						LAi_QuestDelay("alchemy_bars_up", 0.5);
				}
				else
				{
						PlaySound("INTERFACE\lever_down.wav");
						chr.quest.alchemy_lever = "down";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l6 = "lever1_down";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l4 = "bars_down";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l3 = "plank_up";
						Locations[FindLocation("wr_farm_alchemy")].models.always.l7 = "rope_up";

						Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box4 = 0.0001;//at fireplace
						Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box3 = 0.5;//plank enabled

						LAi_QuestDelay("alchemy_bars_down", 0.5);
				}
			break;

			case "box3":
				//OXYGEN
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\basket.wav");

				LAi_QuestDelay("alchemy_plank_oxygen", 0.8);
			break;

			case "box4":
				//FIREPLACE
	
				//LogIt("apparatus_cooling = " + chr.quest.apparatus_cooling);
				//LogIt("apparatus_level = " + chr.quest.apparatus_level);
				//LogIt("cauldron = " + chr.quest.cauldron);
				//LogIt("lab_position = " + chr.quest.lab_position);
				//LogIt("retort = " + chr.quest.retort);

				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', used for placing bladeitems. (fire gun = gunitems)

					if(CheckAttribute(chr,"quest.apparatus_level"))
					{
						if(chr.quest.apparatus_level == "start")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladecauldron")
							{
								PlaySound("INTERFACE\pinion_place.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecauldron");
								EquipCharacterByItem(chr, "bladeX4");

								chr.quest.apparatus_level = "cauldron";
								chr.quest.cauldron = "empty";
								chr.quest.apparatus_cooling = "1";
								Locations[FindLocation("wr_farm_alchemy")].models.always.l9 = "cauldron3";

								LAi_QuestDelay("place_distillery_item", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladecauldron_w")
							{
								PlaySound("INTERFACE\pinion_place.wav");
								PlaySound("INTERFACE\rum_barrel_filled.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecauldron_w");
								EquipCharacterByItem(chr, "bladeX4");

								chr.quest.apparatus_level = "cauldron";
								chr.quest.cauldron = "water";
								chr.quest.apparatus_cooling = "2";
								Locations[FindLocation("wr_farm_alchemy")].models.always.l9 = "cauldron3_w";

								if(CheckAttribute(chr,"quest.qbook_cauldron") && chr.quest.qbook_cauldron == "done")
								{

								}
								else
								{
									chr.quest.qbook_cauldron = "done";
									AddQuestRecord("Alchemy_apparatus", "2");
								}

								LAi_QuestDelay("place_distillery_item", 1.0);
								LAi_QuestDelay("alchemy_boiling_loop", 2.0);
								return;
							}
						}

						if(chr.quest.apparatus_level == "retort")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladetop")
							{
								PlaySound("INTERFACE\glass1.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladetop");
								EquipCharacterByItem(chr, "bladeX4");

								chr.quest.apparatus_level = "top";
								chr.quest.top = "yes";
								Locations[FindLocation("wr_farm_alchemy")].models.always.l11 = "top3";

								LAi_QuestDelay("place_distillery_item", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CG2")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "G2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_G2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_sulf_c")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "T2_sulf_c";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_T2_sulf_c";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CP2")
							{
								PlaySound("OBJECTS\DUEL\pistol_small2.wav");
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "P2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_P2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								if(CheckAttribute(chr,"quest.qbook_retort") && chr.quest.qbook_retort == "done")
								{

								}
								else
								{
									chr.quest.qbook_retort = "done";
									AddQuestRecord("Alchemy_tutorial", "5");
								}

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle2", 0.5);
								return;
							}
						}
//pär distill Q2
						if(chr.quest.apparatus_level == "top")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CG2")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "G2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_G2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_sulf_c")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "T2_sulf_c";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_T2_sulf_c";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CP2")
							{
								PlaySound("OBJECTS\DUEL\pistol_small2.wav");
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "P2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_P2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								if(CheckAttribute(chr,"quest.qbook_retort") && chr.quest.qbook_retort == "done")
								{

								}
								else
								{
									chr.quest.qbook_retort = "done";
									AddQuestRecord("Alchemy_tutorial", "5");
								}

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle2", 0.5);
								return;
							}
						}

						if(chr.quest.apparatus_level == "glass_tube")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
							{
								PlaySound("INTERFACE\glass1.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CE0");
								EquipCharacterByItem(chr, "bladeX4");

								chr.quest.apparatus_level = "empty_bottle";
								chr.quest.empty_bottle = "yes";
								Locations[FindLocation("wr_farm_alchemy")].models.always.l13 = "bottle_FE0";

								if(CheckAttribute(chr,"quest.qbook_receiver") && chr.quest.qbook_receiver == "done")
								{

								}
								else
								{
									chr.quest.qbook_receiver = "done";
									AddQuestRecord("Alchemy_apparatus", "1");

									if(CheckAttribute(chr,"quest.cauldron") && chr.quest.cauldron == "water")
									{
										CloseQuestHeader("Alchemy_apparatus");
										chr.quest.apparatus_hint = "no";
									}
								}

								LAi_QuestDelay("glass_on_stool_sound", 0.5);
								LAi_QuestDelay("place_distillery_item", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CG2")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "G2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_G2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_sulf_c")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "T2_sulf_c";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_T2_sulf_c";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CP2")
							{
								PlaySound("OBJECTS\DUEL\pistol_small2.wav");
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "P2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_P2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								if(CheckAttribute(chr,"quest.qbook_retort") && chr.quest.qbook_retort == "done")
								{

								}
								else
								{
									chr.quest.qbook_retort = "done";
									AddQuestRecord("Alchemy_tutorial", "5");
								}

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle2", 0.5);
								return;
							}
						}

						if(chr.quest.apparatus_level == "empty_bottle")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CG2")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								//apparatus_level still is empty_bottle obs!
								chr.quest.apparatus_liquid = "G2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_G2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_sulf_c")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "T2_sulf_c";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_T2_sulf_c";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CP2")
							{
								PlaySound("OBJECTS\DUEL\pistol_small2.wav");
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "P2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_P2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								if(CheckAttribute(chr,"quest.qbook_retort") && chr.quest.qbook_retort == "done")
								{

								}
								else
								{
									chr.quest.qbook_retort = "done";
									AddQuestRecord("Alchemy_tutorial", "5");
								}

								LAi_QuestDelay("fill_apparatus_with_liquid", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1_mix7")
							{
								PlaySound("AMBIENT\TAVERN\open_bottle.wav");
								chr.quest.apparatus_liquid = "Y2";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_Y2";

								if(CheckAttribute(chr, "quest.cauldron") && chr.quest.cauldron == "water")
								{
									chr.quest.apparatus_cooling = "3";
								}
								else chr.quest.apparatus_cooling = "2";

								LAi_QuestDelay("fill_apparatus_with_liquid_big_bottle2", 0.5);
								return;
							}
						}

						if(chr.quest.apparatus_level == "finished")
						{
							if(CheckAttribute(chr, "quest.apparatus_liquid") && chr.quest.apparatus_liquid == "G2")
							{
								PlaySound("INTERFACE\button2.wav");
								chr.quest.apparatus_level = "glass_tube";
								chr.quest.apparatus_liquid = "none";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l13 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_CT1_sulf");
								EquipCharacterByItem(chr, "bladebottle_CT1_sulf");

								LAi_QuestDelay("place_distillery_item", 0.5);
							}
							if(CheckAttribute(chr, "quest.apparatus_liquid") && chr.quest.apparatus_liquid == "T2_sulf_c")
							{
								PlaySound("INTERFACE\button2.wav");
								chr.quest.apparatus_level = "glass_tube";
								chr.quest.apparatus_liquid = "none";
				//pär postman
								Locations[FindLocation("wr_farm_alchemy")].models.always.l13 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_CT1_nitr");
								EquipCharacterByItem(chr, "bladebottle_CT1_nitr");

								LAi_QuestDelay("place_distillery_item", 0.5);
							}
							if(CheckAttribute(chr, "quest.apparatus_liquid") && chr.quest.apparatus_liquid == "P2")
							{
								PlaySound("INTERFACE\button2.wav");
								chr.quest.apparatus_level = "glass_tube";
								chr.quest.apparatus_liquid = "none";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l13 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_CB1");
								EquipCharacterByItem(chr, "bladebottle_CB1");

								if(CheckAttribute(chr,"quest.qbook_alcohol") && chr.quest.qbook_alcohol == "done")
								{

								}
								else
								{
									chr.quest.qbook_alcohol = "done";
									AddQuestRecord("Alchemy_tutorial", "3");
								}

								LAi_QuestDelay("place_distillery_item", 0.5);
							}
							if(CheckAttribute(chr, "quest.apparatus_liquid") && chr.quest.apparatus_liquid == "Y2")
							{
								PlaySound("INTERFACE\button2.wav");
								chr.quest.apparatus_level = "glass_tube";
								chr.quest.apparatus_liquid = "none";

								Locations[FindLocation("wr_farm_alchemy")].models.always.l13 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_GY2");
								EquipCharacterByItem(chr, "bladebottle_GY2");

								chr.Q2_mix = "8";

								LAi_QuestDelay("place_distillery_item", 0.5);
							}
						}

						if(chr.quest.apparatus_level != "start" && chr.quest.cauldron == "empty")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
							{
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CW1");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								chr.quest.cauldron = "water";
								Locations[FindLocation("wr_farm_alchemy")].models.always.l9 = "cauldron3_w";
								if(CheckAttribute(chr, "quest.apparatus_liquid") && chr.quest.apparatus_liquid == "none")
								{
									chr.quest.apparatus_cooling = "2";
								}
								else chr.quest.apparatus_cooling = "3";

								if(CheckAttribute(chr,"quest.qbook_cauldron") && chr.quest.qbook_cauldron == "done")
								{

								}
								else
								{
									chr.quest.qbook_cauldron = "done";
									AddQuestRecord("Alchemy_apparatus", "2");


									if(CheckAttribute(chr,"quest.apparatus_level") && chr.quest.apparatus_level == "empty_bottle")
									{
										CloseQuestHeader("Alchemy_apparatus");
										chr.quest.apparatus_hint = "no";
									}
								}

								LAi_QuestDelay("place_distillery_item", 3.0);
								LAi_QuestDelay("alchemy_boiling_loop", 4.0);
								return;
							}
						}
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.apparatus_level") && chr.quest.apparatus_level == "finished")
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					chr.quest.lab_position = "fireplace";
					ChangeCharacterAddressGroup(chr, "wr_farm_alchemy", "goto", "fireplace_stuck");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_alchemy")], false);
					LAi_SetFightMode(chr, true);
		
					LAi_QuestDelay("stay_at_fireplace", 1.0);
					return;
				}
			break;
//pär mix med bottle
			case "box5":
				//MIXTABLE medium bottle

				if(CheckAttribute(chr, "use_only_big_bottle") && chr.use_only_big_bottle == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I think I'll use the Big Bottle for Mixtures instead."));
					return;
				}

				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', used for placing, filling or picking up bottles

					//NO BOTTLE
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "none")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CE0");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_ME0";
							chr.quest.mixtable_bottle = "ME0";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							if(CheckAttribute(chr, "quest.block_water") && chr.quest.block_water == "yes") return;

							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CW1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MW1";
							chr.quest.mixtable_bottle = "MW1";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1")
						{
							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CB1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB1";
							chr.quest.mixtable_bottle = "MB1";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							return;
						}
				
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							if(CheckAttribute(chr, "Q2_mix"))
							{
								if(chr.Q2_mix == "10" || chr.Q2_mix == "11" || chr.Q2_mix == "12" || chr.Q2_mix == "4")
								{
									//ok
								}
								else return;
							} 

							if(CheckCharacterItem(chr,"bladebottle_CB1_mix9"))
							{
							    if(CheckAttribute(chr, "Q2_mix"))
							    {
							        if(chr.Q2_mix == "11" || chr.Q2_mix == "12")	
								{
									PlaySound("INTERFACE\glass2.wav");
									PlaySound("PEOPLE\step_stairway2.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
									EquipCharacterByItem(chr, "bladeX4");
									locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_sulf";
									chr.quest.mixtable_bottle = "MT1_sulf";

									LAi_QuestDelay("place_mixtable_item", 0.5);
									LAi_QuestDelay("alchemy_acid_fog", 1.5);
									return;
								}
							    }
							}
							else
							{
								PlaySound("INTERFACE\glass2.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_sulf";
								chr.quest.mixtable_bottle = "MT1_sulf";

								LAi_QuestDelay("place_mixtable_item", 0.5);
								LAi_QuestDelay("alchemy_acid_fog", 1.5);
								return;
							}
						}
					//pär här
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_nitr")
						{
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix != "11") return;

							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_nitr");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_nitr";
							chr.quest.mixtable_bottle = "MT1_nitr";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydr")
						{
							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydr");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydr";
							chr.quest.mixtable_bottle = "MT1_hydr";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydrnitr")
						{
							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydrnitr");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydrnitr";
							chr.quest.mixtable_bottle = "MT1_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CQ1")
						{
							PlaySound("INTERFACE\glass2.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CQ1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MQ1";
							chr.quest.mixtable_bottle = "MQ1";

							LAi_QuestDelay("place_mixtable_item", 0.5);
							return;
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "12")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1_mix9")
							{
								PlaySound("INTERFACE\glass2.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CB1_mix9");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB1_mix9";
								chr.quest.mixtable_bottle = "MB1_mix9";

								LAi_QuestDelay("place_mixtable_item", 0.5);
								return;
							}
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CR1")
						{
							Logit(TranslateString("","I think I'll make some more Sulfur Auretum first."));
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						}
						//other bottles ev. in here giving Hmm that's not a good idea or so...
					}

					//EMPTY BOTTLE
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "ME0")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							if(CheckAttribute(chr, "quest.block_water") && chr.quest.block_water == "yes") return;

							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CW1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MW1";
							chr.quest.mixtable_bottle = "MW1";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CB1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB1";
							chr.quest.mixtable_bottle = "MB1";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
				
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							if(CheckAttribute(chr, "Q2_mix"))
							{
								if(chr.Q2_mix == "10" || chr.Q2_mix == "11" || chr.Q2_mix == "12" || chr.Q2_mix == "4")
								{
									//ok
								}
								else return;
							}

							if(CheckCharacterItem(chr,"bladebottle_CB1_mix9"))
							{
							    if(CheckAttribute(chr, "Q2_mix"))
							    {
								if(chr.Q2_mix == "11" || chr.Q2_mix == "12")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_sulf";
									chr.quest.mixtable_bottle = "MT1_sulf";

									LAi_QuestDelay("place_mixtable_item", 3.0);
									LAi_QuestDelay("alchemy_acid_fog", 4.0);
									return;
								}
							    }
							}
							else
							{
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_sulf";
								chr.quest.mixtable_bottle = "MT1_sulf";

								LAi_QuestDelay("place_mixtable_item", 3.0);
								LAi_QuestDelay("alchemy_acid_fog", 4.0);
								return;
							}
						}
				//pär här
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_nitr")
						{
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix != "11") return;

							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_nitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_nitr";
							chr.quest.mixtable_bottle = "MT1_nitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							LAi_QuestDelay("alchemy_acid_fog", 4.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydr";
							chr.quest.mixtable_bottle = "MT1_hydr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							LAi_QuestDelay("alchemy_acid_fog", 4.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydrnitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydrnitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydrnitr";
							chr.quest.mixtable_bottle = "MT1_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT2_hydr");
							GiveItem2Character(chr,"bladebottle_CT1_hydr");
							EquipCharacterByItem(chr, "bladebottle_CT1_hydr");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydr";
							chr.quest.mixtable_bottle = "MT1_hydr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							LAi_QuestDelay("alchemy_acid_fog", 4.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_hydrnitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT2_hydrnitr");
							GiveItem2Character(chr,"bladebottle_CT1_hydrnitr");
							EquipCharacterByItem(chr, "bladebottle_CT1_hydrnitr");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT1_hydrnitr";
							chr.quest.mixtable_bottle = "MT1_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CQ1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CQ1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MQ1";
							chr.quest.mixtable_bottle = "MQ1";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "12")
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1_mix9")
							{
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CB1_mix9");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB1_mix9";
								chr.quest.mixtable_bottle = "MB1_mix9";

								LAi_QuestDelay("place_mixtable_item", 1.5);
								return;
							}
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CR1")
						{
							Logit(TranslateString("","I think I'll make some more Sulfur Auretum first."));
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BP2_ps")
						{
							PlaySound("INTERFACE\bottle_powder.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BP2_ps");
							GiveItem2Character(chr,"bladebottle_BP1_ps");
							EquipCharacterByItem(chr, "bladebottle_BP1_ps");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MP2_ps";
							chr.quest.mixtable_bottle = "MP2_ps";

							LAi_QuestDelay("place_mixtable_item", 1.5);
							return;
						}
//pär L.H. fix, only when"14"
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS2_LH")
						{
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "14")
							{
								PlaySound("PEOPLE\sponge.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BS2_LH");
								GiveItem2Character(chr,"bladebottle_BS1_LH");
								EquipCharacterByItem(chr, "bladebottle_BS1_LH");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MU2";
								chr.quest.mixtable_bottle = "MU2";

								LAi_QuestDelay("place_mixtable_item", 1.5);
								return;
							}
						}
				//pär extra stringlog 2
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB2_mix9")
						{
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","I need only half of that!"));
						}

						//other bottles ev. in here giving Hmm that's not a good idea or so...
					}

					//HALF FULL BOTTLE: WATER
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MW1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CB1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB2";
							chr.quest.mixtable_bottle = "MB2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_sulf_w";
							chr.quest.mixtable_bottle = "MT2_sulf_w";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_nitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_nitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_nitr_w";
							chr.quest.mixtable_bottle = "MT2_nitr_w";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						//other bottles ev. in here giving Hmm that's not a good idea or so...
					}

					//HALF FULL BOTTLE: ALCOHOL
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MB1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CW1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MB2";
							chr.quest.mixtable_bottle = "MB2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: H2SO4
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT1_sulf")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							//explosion
							PlaySound("INTERFACE\bottle_molasses.wav");

							LAi_QuestDelay("alchemy_acid_explosion", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB1_mix9")
						{
							PlaySound("INTERFACE\bottle_powder.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CB1_mix9");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_ML1_sulf_aur";
							chr.quest.mixtable_bottle = "ML1_sulf_aur";

							LAi_QuestDelay("place_mixtable_item", 1.5);
							LAi_QuestDelay("alchemy_acid_small_boiling", 2.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CB2_mix9")
						{
							PlaySound("INTERFACE\bottle_powder.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CB2_mix9");
							GiveItem2Character(chr,"bladebottle_CB1_mix9");
							EquipCharacterByItem(chr, "bladebottle_CB1_mix9");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_ML1_sulf_aur";
							chr.quest.mixtable_bottle = "ML1_sulf_aur";

							LAi_QuestDelay("place_mixtable_item", 1.5);
							LAi_QuestDelay("alchemy_acid_small_boiling", 2.0);
							return;
						}
					}

					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "ML1_sulf_aur")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CC1")
						{
							PlaySound("INTERFACE\bottle_powder.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CC1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MC2";
							chr.quest.mixtable_bottle = "MC2";

							LAi_QuestDelay("place_mixtable_item", 1.5);
							return;
						}
					}

					//HALF FULL BOTTLE: HNO3
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT1_nitr")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_hydrnitr";
							chr.quest.mixtable_bottle = "MT2_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT2_hydr");
							GiveItem2Character(chr,"bladebottle_CT1_hydr");
							EquipCharacterByItem(chr, "bladebottle_CT1_hydr");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_hydrnitr";
							chr.quest.mixtable_bottle = "MT2_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							if(CheckAttribute(chr, "quest.block_water") && chr.quest.block_water == "yes") return;

							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CW1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("alchemy_acid_boiling", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CQ1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CQ1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_mix11";
							chr.quest.mixtable_bottle = "MT2_mix11";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: HCl
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT1_hydr")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_nitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_nitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_hydrnitr";
							chr.quest.mixtable_bottle = "MT2_hydrnitr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydrnitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydrnitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MA2";
							chr.quest.mixtable_bottle = "MA2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_hydrnitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT2_hydrnitr");
							GiveItem2Character(chr,"bladebottle_CT1_hydrnitr");
							EquipCharacterByItem(chr, "bladebottle_CT1_hydrnitr");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MA2";
							chr.quest.mixtable_bottle = "MA2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: HCl + HNO3
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT1_hydrnitr")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_hydr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MA2";
							chr.quest.mixtable_bottle = "MA2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT2_hydr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT2_hydr");
							GiveItem2Character(chr,"bladebottle_CT1_hydr");
							EquipCharacterByItem(chr, "bladebottle_CT1_hydr");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MA2";
							chr.quest.mixtable_bottle = "MA2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: copperas
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MV1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CW1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MG2";
							chr.quest.mixtable_bottle = "MG2";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: nitre
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MS1_chil")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_sulf_c";
							chr.quest.mixtable_bottle = "MT2_sulf_c";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: salt
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MS1_salt")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_hydr";
							chr.quest.mixtable_bottle = "MT2_hydr";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							LAi_QuestDelay("alchemy_acid_fog", 4.0);
							return;
						}
					}

					//HALF FULL BOTTLE: mercury
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MQ1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_nitr")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_nitr");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_mix11";
							chr.quest.mixtable_bottle = "MT2_mix11";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							return;
						}
					}

					//HALF FULL BOTTLE: dried mixture
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MB1_mix9")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_ML1_sulf_aur";
							chr.quest.mixtable_bottle = "ML1_sulf_aur";

							LAi_QuestDelay("place_mixtable_item", 3.0);
							LAi_QuestDelay("alchemy_acid_small_boiling", 3.5);
							return;
						}
					}

					//HALF FULL BOTTLE: Sulfur Auretum
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "ML1_sulf_aur")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CR1")
						{
							PlaySound("INTERFACE\bottle_powder.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CR1");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MR2";
							chr.quest.mixtable_bottle = "MR2";

							LAi_QuestDelay("place_mixtable_item", 1.5);
							return;
						}
					}

					//FULL BOTTLE: cognac
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MB2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";

						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CB2");
						EquipCharacterByItem(chr, "bladebottle_CB2");

						if(CheckAttribute(chr, "quest.boat_to_prizeships") && chr.quest.boat_to_prizeships == "not_yet")
						{
							LAi_SetStayType(chr);
						}

						if(CheckAttribute(chr,"quest.qbook_cognac") && chr.quest.qbook_cognac == "done")
						{

						}
						else
						{
							chr.quest.qbook_cognac = "done";
							AddQuestRecord("Alchemy_tutorial", "4");
							CloseQuestHeader("Alchemy_tutorial");
							chr.quest.process_hint = "no";
						}

						LAi_QuestDelay("place_mixtable_item", 0.5);
						LAi_QuestDelay("switch_to_potion_cognac", 3.0);		//was 5.0
					}

					//FULL BOTTLE: H2SO4 + water
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_sulf_w")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_sulf_w");
						EquipCharacterByItem(chr, "bladebottle_CT2_sulf_w");
						chr.quest.Minerva_copper = "no";
						AddQuestRecord("Alchemy_copper", "2");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: H2SO4 + nitre
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_sulf_c")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_sulf_c");
						EquipCharacterByItem(chr, "bladebottle_CT2_sulf_c");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: HNO3 + water (Aqua Fortis)
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_nitr_w")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_nitr_w");
						EquipCharacterByItem(chr, "bladebottle_CT2_nitr_w");
						chr.quest.Minerva_silver = "no";
						AddQuestRecord("Alchemy_silver", "2");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: HCl
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_hydr")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_hydr");
						EquipCharacterByItem(chr, "bladebottle_CT2_hydr");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: HCl + HNO3
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_hydrnitr")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_hydrnitr");
						EquipCharacterByItem(chr, "bladebottle_CT2_hydrnitr");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: Aqua Regis
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MA2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CA2");
						EquipCharacterByItem(chr, "bladebottle_CA2");
						chr.quest.Minerva_gold = "no";
						AddQuestRecord("Alchemy_gold", "2");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: copperas + water
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MG2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CG2");
						EquipCharacterByItem(chr, "bladebottle_CG2");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: Black Pulvis Solaris
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MC2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CC2_bps");
						EquipCharacterByItem(chr, "bladebottle_CC2_bps");

						chr.Q2_mix = "11";				//ready for Red Pulvis Solaris

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MT2_mix11")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CT2_mix11");
						EquipCharacterByItem(chr, "bladebottle_CT2_mix11");

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}

					//FULL BOTTLE: Red Pulvis Solaris
					if(CheckAttribute(chr, "quest.mixtable_bottle") && chr.quest.mixtable_bottle == "MR2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.mixtable_bottle = "none";

						Locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CR2_rps");
						EquipCharacterByItem(chr, "bladebottle_CR2_rps");

						chr.Q2_mix = "13";				//ready for final mixes
						chr.use_only_small_bottle = "no";		
						chr.use_only_big_bottle = "no";		//both may be needed

						LAi_QuestDelay("place_mixtable_item", 0.5);
					}
				}
				else
				{

					if(CheckAttribute(chr, "quest.mixtable_bottle"))
					{
						if(chr.quest.mixtable_bottle == "MA2" || chr.quest.mixtable_bottle == "MG2" || chr.quest.mixtable_bottle == "MT2_hydrnitr"
						|| chr.quest.mixtable_bottle == "MT2_hydr" || chr.quest.mixtable_bottle == "MT2_sulf_c" || chr.quest.mixtable_bottle == "MT2_sulf_w"
						|| chr.quest.mixtable_bottle == "MT2_nitr_w" || chr.quest.mixtable_bottle == "MB2"
						|| chr.quest.mixtable_bottle == "MC2" || chr.quest.mixtable_bottle == "MR2"
						|| chr.quest.mixtable_bottle == "MT2_mix11")
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}
					}

					chr.quest.lab_position = "mixtable";
					ChangeCharacterAddressGroup(chr, "wr_farm_alchemy", "goto", "mixtable_stuck");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_alchemy")], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("stay_at_mixtable", 1.0);
					return;
				}
			break;

			case "box6":
				PlaySound("INTERFACE\key_unlock.wav");
				chr.quest.distillery_items = "open";

				LAi_QuestDelay("unlock_from_alchemy", 2.0);
			break;
//pär mix big bottle
			case "box7":
				//MIXTABLE large bottle

				if(CheckAttribute(chr, "use_only_small_bottle") && chr.use_only_small_bottle == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I think I'll use the Small Bottle for Mixtures instead."));
					return;
				}

				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', used for placing, filling or picking up bottles

					switch(Locations[FindLocation(chr.location)].models.always.l16)
					{
						case "":
							//NO BOTTLE

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BE0")
							{
								PlaySound("INTERFACE\glass1.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BE0");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LE0";
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
								return;
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BP1_ps")
							{
								PlaySound("INTERFACE\glass1.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BP1_ps");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LP1_ps";
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
								return;
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "14")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1_LH")
								{
									PlaySound("INTERFACE\glass1.wav");
									PlaySound("PEOPLE\step_stairway2.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BS1_LH");
									EquipCharacterByItem(chr, "bladeX4");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LU1_LH";
							
									LAi_QuestDelay("place_mixtableL_item", 0.5);
									return;
								}
							}
						break;

						case "bottle_LE0":
							//EMPTY BOTTLE

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LTa_sulf";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									LAi_QuestDelay("alchemy_acid_fogL", 4.0);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_ss";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "3")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV2")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV2");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix2";	//reused bottle

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LWa";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LWa";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "8")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_GY2")
								{
									PlaySound("AMBIENT\TAVERN\open_bottle.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_GY2");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_gas";

									LAi_QuestDelay("censer_sound", 0.5);
									LAi_QuestDelay("place_mixtableL_item", 1.5);
									LAi_QuestDelay("alchemy_acid_fog", 2.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_sc";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "13")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CC2_bps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CC2_bps");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LC1_bps";
							
									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CR2_rps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CR2_rps");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LR1_rps";
							
									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "14")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BP1_ps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BP1_ps");
									GiveItem2Character(chr,"bladebottle_BE0");
									EquipCharacterByItem(chr, "bladebottle_BE0");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LP1_ps";
							
									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1_LH")
								{
									PlaySound("PEOPLE\sponge.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BS1_LH");
									GiveItem2Character(chr,"bladebottle_BE0");
									EquipCharacterByItem(chr, "bladebottle_BE0");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LU1_LH";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
						//pär extra stringlog
								if(CheckAttribute(chr, "equip.blade")  )
								{
									if(chr.equip.blade == "bladebottle_BP2_ps" || chr.equip.blade == "bladebottle_BS2_LH")
									{
										PlaySound("VOICE\ENGLISH\blaze_hah.wav");
										Logit(TranslateString("","I need only half of that!"));
									}
								}
							}
						break;

						case "bottle_LSa_salt":
							//QUARTER FULL BOTTLE: salt

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_hydr";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									LAi_QuestDelay("alchemy_acid_fogL", 4.0);
									return;
								}
							}
						break;

						case "bottle_LS1_salt":
							//HALF FULL BOTTLE: salt

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CT1_sulf")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CT1_sulf");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LTc_hydr";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LTc_hydr":
							//THREE QUARTER FULL BOTTLE: 2salt + H2SO4

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BTc_hydr");
								EquipCharacterByItem(chr, "bladebottle_BTc_hydr");
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}

							//also used after mix2 + oven + water
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "3")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BTc_mix3");
								EquipCharacterByItem(chr, "bladebottle_BTc_mix3");

					DoQuickSave();			
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;
					
						case "bottle_LSa_cc":
							//QUARTER FULL BOTTLE: Calcium Carbonate
						
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LCa_coal":
							//QUARTER FULL BOTTLE: Coal
						
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG1_ss";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LC1_coal":
							//HALF FULL BOTTLE: Coal
						
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_ss";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LG1_cc": 
							//HALF FULL BOTTLE: coal + calcium carbonate

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LGc_cc": 
							//THREE QUARTER FULL BOTTLE: 2 coal + calcium carbonate 

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_ss")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_ss");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG2_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LG2_mix2":
							//FULL BOTTLE: 2 coal + sodium sulfate + calcium carbonate

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BG2");
								EquipCharacterByItem(chr, "bladebottle_BG2");
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;
						
						case "bottle_LWa":
							//QUARTER FULL BOTTLE: water						

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "3")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV2")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV2");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LTc_hydr";	//reused bottle

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LS1_mix2":
							//HALF FULL BOTTLE: white powder from mix2 and oven

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "3")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LTc_hydr";	//reused bottle

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LSa_cao":
							//QUARTER FULL BOTTLE: calcium oxide

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix7";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_cao";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LSa_NH4Cl":
							//QUARTER FULL BOTTLE: sal ammoniac

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix7";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LUa":
							//QUARTER FULL BOTTLE: sulphur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
			
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL1_s";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
						
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_sc";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;
						
						case "bottle_LS1_mix7":
							//HALF FULL BOTTLE: calcium oxide + sal ammoniac						

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_mix7";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LT1_cao":
							//HALF FULL BOTTLE: calcium oxide + water

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{	
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_mix7";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LT1_NH4Cl":
							//HALF FULL BOTTLE: NH4Cl + water

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_mix7";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LY1_cao":
							//HALF FULL BOTTLE: calcium oxide + sulfur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{	
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_s";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_cao";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;
						
						case "bottle_LY1_NH4Cl":
							//HALF FULL BOTTLE: sal amoniac + sulfur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_s";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LL1_s":
							//HALF FULL BOTTLE: water + sulfur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_NH4Cl";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LYc_s":
							//THREE QUARTER FULL BOTTLE: sal ammoniac + calcium oxide + sulfur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CW1")
								{
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CW1");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL2_s";

									LAi_QuestDelay("place_mixtableL_item", 3.0);
									return;
								}
							}
						break;

						case "bottle_LLc_cao":
							//THREE QUARTER FULL BOTTLE: water + sulfur + calcium oxide

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_NH4Cl")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_NH4Cl");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL2_s";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LLc_NH4Cl":
							//THREE QUARTER FULL BOTTLE: water + sulfur + sal ammoniac

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL2_s";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

							}
						break;

						case "bottle_LL2_s":
							//FULL BOTTLE: light yellow liquid

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "7")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BY2_mix7");
								EquipCharacterByItem(chr, "bladebottle_BY2_mix7");
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;

						case "bottle_LU2":
							//FULL BOTTLE: Liquor Hepatis

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "8")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BS2_LH");
								EquipCharacterByItem(chr, "bladebottle_BS2_LH");

								chr.Q2_mix = "9";
			//ship arrives here				
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;

						case "bottle_LSa_sc":
							//QUARTER FULL BOTTLE: sodium carbonate

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LGa_M":
							//QUARTER FULL BOTTLE: antimony

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LM1_sc";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LM1_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LM1_sc":
							//HALF FULL BOTTLE: sodium carbonate + antimony

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LMc_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LM1_cao":
							//HALF FULL BOTTLE: calcium oxide + antimony
		
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LMc_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LY1_sc":
							//HALF FULL BOTTLE: sodium carbonate + sulphur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LU1":
							//HALF FULL BOTTLE: antimony + sulphur

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_sc";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_cao";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LYc_sc":
							//THREE QUARTER FULL BOTTLE: sodium carbonate + sulfur + calcium oxide

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_cao")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_cao");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY2_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LYc_cao":
							//THREE QUARTER FULL BOTTLE: antimony + sulfur + calcium oxide

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CV1_sc")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CV1_sc");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY2_mix9";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LY2_mix9":
							//FULL BOTTLE: light yellow powder

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BY2_mix9");
								EquipCharacterByItem(chr, "bladebottle_BY2_mix9");
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;

						case "bottle_LC1_bps":
							//HALF FULL BOTTLE: Black Pulvis Solaris
					
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "13")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CR2_rps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CR2_rps");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LP2_ps";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LR1_rps":
							//HALF FULL BOTTLE: Red Pulvis Solaris
					
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "13")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CC2_bps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_CC2_bps");
									GiveItem2Character(chr,"bladebottle_CE0");
									EquipCharacterByItem(chr, "bladebottle_CE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LP2_ps";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LP2_ps":
							//FULL BOTTLE: Pulvis Solaris
					
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "13")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BP2_ps");
								EquipCharacterByItem(chr, "bladebottle_BP2_ps");

								chr.Q2_mix = "14";				//
							
								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;
	
						case "bottle_LP1_ps":
							//HALF FULL BOTTLE: Pulvis Solaris

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "14")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1_LH")
								{
									PlaySound("PEOPLE\sponge.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BS1_LH");
									GiveItem2Character(chr,"bladebottle_BE0");
									EquipCharacterByItem(chr, "bladebottle_BE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_AU2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS2_LH")
								{
									PlaySound("PEOPLE\sponge.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BS2_LH");
									GiveItem2Character(chr,"bladebottle_BS1_LH");
									EquipCharacterByItem(chr, "bladebottle_BS1_LH");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_AU2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LU1_LH":
							//HALF FULL BOTTLE: Liquor Hepatis

							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "14")
							{
								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BP1_ps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BP1_ps");
									GiveItem2Character(chr,"bladebottle_BE0");
									EquipCharacterByItem(chr, "bladebottle_BE0");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_AU2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BP2_ps")
								{
									PlaySound("INTERFACE\bottle_powder.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BP2_ps");
									GiveItem2Character(chr,"bladebottle_BP1_ps");
									EquipCharacterByItem(chr, "bladebottle_BP1_ps");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_AU2";

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_AU2":
							//FULL BOTTLE: Philospher's Stone
							if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "15")
							{
								PlaySound("INTERFACE\button2.wav");
								Locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr,"bladebottle_BAU");
								EquipCharacterByItem(chr, "bladebottle_BAU");

								SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box5", 0.0001);
								Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box5 = 0.0001;
								SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box7", 0.0001);
								Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box7 = 0.0001;
								
								chr.use_only_big_bottle = "yes";
								chr.use_only_small_bottle = "yes";	//means none

								LAi_QuestDelay("place_mixtableL_item", 0.5);
							}
						break;
//pär mixtable big bottle end
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LTc_hydr" 
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LG2_mix2"
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LL2_s"
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LU2"
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LY2_mix9"
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_LP2_ps"
					|| Locations[FindLocation(chr.location)].models.always.l16 == "bottle_AU2")
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					chr.quest.lab_position = "mixtableL";
					ChangeCharacterAddressGroup(chr, "wr_farm_alchemy", "goto", "mixtableL_stuck");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_alchemy")], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("stay_at_mixtableL", 1.0);
					return;
				}
			break;
		}
		return;
	}
//pär2
	if(Locations[locidx].id=="wr_farm_alchemy2")
	{
		switch(chr.boxname)
		{
			case "box17":
				if(CheckAttribute(chr, "alchemy2_box17") && chr.alchemy2_box17 == "on") return;

				if(CheckCharacterItem(chr,"key36"))
				{
					chr.alchemy2_box17 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_alchemy2_downstairs", 2.0);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box18":
				if(CheckAttribute(chr, "alchemy2_box18") && chr.alchemy2_box18 == "on") return;

				if(CheckCharacterItem(chr,"key36"))
				{
					chr.alchemy2_box18 = "on";
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_alchemy2_upstairs", 2.0);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box19":
				//SMALL WALLBOX

				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box1":
				//SALT

				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				if(locations[FindLocation(chr.location)].box1.items.pistolsalt >=1)
				{
					LAi_QuestDelay("pistolsalt_check", 0.1);
				}
			break;

			case "box2":
				//FILTERS

				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);

				if(locations[FindLocation(chr.location)].box2.items.pistolcloth >=1)
				{
					LAi_QuestDelay("pistolcloth_check", 0.1);
				}
			break;

			case "box3":
				//FUNNEL

				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				if(locations[FindLocation(chr.location)].box3.items.pistolfunnel >=1)
				{
					LAi_QuestDelay("pistolfunnel_check", 0.1);
				}

				if(locations[FindLocation(chr.location)].box3.items.bladebottle_CE0 >=1)
				{
					LAi_QuestDelay("empty_bottle_check", 0.1);
					return;
				}
			break;

			case "box4":
				//DOWNSTAIRS FILTER

				switch(Locations[FindLocation(chr.location)].models.always.l15)
				{
					case "powder_white_filter":
						if(IsEquipCharacterByItem(chr, "bladebottle_CE0"))
						{
							LAi_SetStayType(chr);
							PlaySound("PEOPLE\gunpowder.wav");
							Locations[FindLocation(chr.location)].models.always.l15 ="";
						//	RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						//	TakeItemFromCharacter(chr, "bladebottle_CE0");
						//	GiveItem2Character(chr,"bladebottle_CV1_sc");
						//	EquipCharacterByItem(chr, "bladebottle_CV1_sc");	

							chr.Q2_mix = "4";
							chr.use_only_big_bottle = "no";		//small mix bottle enabled
							chr.use_only_small_bottle = "yes";	//big mix bottle disabled

							chr.quest.HNO3_check.win_condition.l1 = "location";
							chr.quest.HNO3_check.win_condition.l1.location = "wr_farm_alchemy";
							chr.quest.HNO3_check.win_condition = "HNO3_check";

							LAi_QuestDelay("alch2_box4_white_powder", 3.0);							
						}

						if(IsEquipCharacterByItem(chr, "bladebottle_BE0"))
						{
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","A Small Bottle will do here."));
						}		
					break;

					case "powder_red_filter":
						if(IsEquipCharacterByItem(chr, "bladebottle_CE0"))
						{
							LAi_SetStayType(chr);
							PlaySound("PEOPLE\gunpowder.wav");
							Locations[FindLocation(chr.location)].models.always.l15 ="";
							
							chr.Q2_mix = "12";		//ready to mix red powder with (new) sulf aur

							LAi_QuestDelay("alch2_box4_red_powder", 3.0);
						}		
					break;

					case "":
						//no powder

						if(Locations[FindLocation(chr.location)].models.always.l13 == "cloth_clean")
						{
							if(IsEquipCharacterByItem(chr, "bladebottle_BTc_mix3"))
							{
								LAi_SetStayType(chr);
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BTc_mix3");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");

								Locations[FindLocation(chr.location)].models.always.l15 = "powder_white_filter";
								Locations[FindLocation(chr.location)].models.always.l13 = "cloth_dirty";

								LAi_QuestDelay("alch2_box4", 3.0);
							}

							if(IsEquipCharacterByItem(chr, "bladebottle_CA2_mix11"))
							{
								LAi_SetStayType(chr);
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CA2_mix11");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");
								
								Locations[FindLocation(chr.location)].models.always.l15 = "powder_red_filter";
								Locations[FindLocation(chr.location)].models.always.l13 = "cloth_dirty";

								LAi_QuestDelay("alch2_box4", 3.0);
							}
						}
						else
						{
							if(IsEquipCharacterByItem(chr, "pistolcloth"))
							{
								LAi_SetStayType(chr);
								PlaySound("PEOPLE\clothes1.wav");
								Locations[FindLocation(chr.location)].models.always.l13 = "cloth_clean";
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								TakeItemFromCharacter(chr, "pistolcloth");

								LAi_QuestDelay("alch2_box4", 1.0);
							}
							else
							{
								//risk here to pour your right liquid away

								if(IsEquipCharacterByItem(chr, "bladebottle_BTc_mix3"))
								{
									LAi_SetStayType(chr);
									PlaySound("INTERFACE\bottle_molasses.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladebottle_BTc");
									GiveItem2Character(chr,"bladebottle_BE0");
									EquipCharacterByItem(chr, "bladebottle_BE0");

									chr.filter_failure = "yes";
									Locations[FindLocation(chr.location)].models.always.l13 = "";

									LAi_QuestDelay("alch2_box4", 3.0);
								}
								else
								{
					//pär here you loose red liquid
									if(IsEquipCharacterByItem(chr, "bladebottle_CA2_mix11"))
									{
										LAi_SetStayType(chr);
										PlaySound("INTERFACE\bottle_molasses.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										TakeItemFromCharacter(chr, "bladebottle_CA2_mix11");
										GiveItem2Character(chr,"bladebottle_CE0");
										EquipCharacterByItem(chr, "bladebottle_CE0");
					
										chr.filter_failure = "yes";
										Locations[FindLocation(chr.location)].models.always.l13 = "";

										LAi_QuestDelay("alch2_box4", 3.0);
									}
								}
								else
								{
									if(Locations[FindLocation(chr.location)].models.always.l13 == "cloth_dirty")
									{
										LAi_SetStayType(chr);
										PlaySound("PEOPLE\clothes1.wav");
										Locations[FindLocation(chr.location)].models.always.l13 = "";
				
										LAi_QuestDelay("alch2_box4", 1.0);
									}
									else
									{
										//no cloth
										PlaySound("VOICE\ENGLISH\blaze_hah.wav");
										Logit(TranslateString("","A clean piece of Cloth as a filter is needed here."));
									}
								}
							}
						}		
					break;
				}
			break;

			case "box5":
				//BIG BARREL not used
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				Logit(TranslateString("","I can get rid of bad Mixtures here."));

				//blade item types not fists not empty bottles
			break;
//pär gold
			case "box6":
				//GOLDBAR HERE

				if(Locations[FindLocation(chr.location)].models.always.l16 == "leadbar")
				{
					if(CheckCharacterItem(chr,"bladebottle_BAU"))
					{
						if(LAi_IsFightMode(chr))
						{
							//second 'open box'

							PlaySound("AMBIENT\CAVE\drop7.wav");
							LAi_QuestDelay("making_gold", 1.0);
						}
						else
						{
							//first 'open box'
							if(!IsEquipCharacterByItem(chr, "bladebottle_BAU"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladebottle_BAU");
							}

							Logit(TranslateString("","Just one drop..."));
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "gold");
							LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_alchemy2")], false);
							LAi_SetFightMode(chr, true);
							PauseAllSounds();//stops music
							locations[FindLocation("wr_farm_alchemy2")].type = "silent_residence";
							locations[FindLocation("wr_farm_booty2")].type = "silent_residence";	//yes, already here
							PostEvent("LoadSceneSound", 0.1);
							PlaySound("VOICE\ENGLISH\blaze_1.wav");
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","That metal looks like Lead. Supposed to become Gold?"));
					}
				}
				else
				{
					//it's gold!
				}
			break;

			case "box7":
				//PICK UP BOTTLE AFTER GRINDING	OR PLACE EMPTY BOTTLE			

				switch(Locations[FindLocation(chr.location)].models.always.l14)
				{
					case "":
						if(IsEquipCharacterByItem(chr, "bladebottle_CE0"))
						{
							Locations[FindLocation(chr.location)].models.always.l14 ="bottle_GE0";
							PlaySound("INTERFACE\button2.wav");
							PlaySound("PEOPLE\step_stone.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CE0");
							EquipCharacterByItem(chr, "bladeX4");	

							LAi_QuestDelay("take_grinded_item", 0.5);
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","A Small Bottle will do here."));
						}	
					break;

					case "bottle_GC1":
						Locations[FindLocation(chr.location)].models.always.l14 ="";
						PlaySound("INTERFACE\button2.wav");	
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CC1");
						EquipCharacterByItem(chr, "bladebottle_CC1");	

						LAi_QuestDelay("take_grinded_item", 0.5);
					break;

					case "bottle_GG1":
						Locations[FindLocation(chr.location)].models.always.l14 ="";	
						PlaySound("INTERFACE\button2.wav");	
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_CG1");
						EquipCharacterByItem(chr, "bladebottle_CG1");

						LAi_QuestDelay("take_grinded_item", 0.5);
					break;
				}
			break;

			case "box8":
				//UPSTAIRS GRINDING
				
				if(CheckAttribute(chr, "alchemy2_box8") && chr.alchemy2_box8 == "on") return;

				chr.alchemy2_box8 = "on";
				ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "box8");
				LAi_SetSitType(chr);
				PlaySound("INTERFACE\grinder.wav");

				if(CheckAttribute(chr, "alchemy2_grinder"))
				{
					if(chr.alchemy2_grinder == "black_stones" || chr.alchemy2_grinder == "grey_stones")
					CreateParticleSystem("blast_dirt_small" , -9.05, 3.9, 9.65, 0.0, 0.0, 0.0, sti(20) );
				}
							
				LAi_QuestDelay("pchar_staytype", 1.0);	
				LAi_QuestDelay("2FH_grinding", 1.7);
			break;
//pär2 box9
			case "box9":
				//FIREPLACE also box14

				if(GetAttribute(chr, "crucible") == "on") return;	//to avoid 2 fast operations before DQR

				if(IsEquipCharacterByItem(chr, "bladewood2"))
				{
					PlaySound("PEOPLE\place_planks.wav");
					PlaySound("PEOPLE\jump_roof.wav");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladewood2" );
					EquipCharacterByItem(chr, "bladeX4");
					
					switch(Locations[FindLocation(chr.location)].models.always.locators)
					{
						case "TwoFloorHouse_locators_JRH0":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH1";
						break;

						case "TwoFloorHouse_locators_JRH1":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH2";
						break;

						case "TwoFloorHouse_locators_JRH2":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH3";
						break;
					}

					chr.crucible = "on";
					LAi_QuestDelay("place_wood_alchemy2_box9", 0.5);

					Locations[FindLocation("wr_farm_alchemy2")].image = "";
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.l10 == "" 
				&& Locations[FindLocation(chr.location)].models.always.l7 == "cauldron2")
				{
					//CAULDRON IS EMPTY AND NOT TILTED
					if(CheckAttribute(chr, "equip.blade"))
					{
						switch(chr.equip.blade)
						{
							case "bladebottle_BTc_hydr":
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BTc_hydr");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
								Locations[FindLocation(chr.location)].models.always.l10 = "liquid_white";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH3", 3.0);
							break;

							case "bladebottle_BG2":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BG2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
								Locations[FindLocation(chr.location)].models.always.l10 = "powder_grey";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH3", 1.5);
							break;

							case "bladebottle_CG1":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CG1");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//powder burning up direct
									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9_burning_direct", 1.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "powder_grey";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH2", 1.5);
								}
								return;		//so not empty bottle below gets activated direct
							break;

							case "bladebottle_BY2_mix9":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BY2_mix9");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH2"
								|| Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//powder burning up direct
									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9_burning_direct", 1.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "powder_light_yellow";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH1", 1.5);
								}
							break;

							case "bladebottle_CT2_mix11":
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CT2_mix11");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//reacting direct to orange liquid
									Locations[FindLocation(chr.location)].models.always.l10 = "liquid_orange";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9", 3.0);
									LAi_QuestDelay("oven_alchemy2_box9_burning_direct", 3.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "liquid_white";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9", 3.0);
								}
								return;
							break;
						}
					}
					
					if(CheckAttribute(chr, "equip.gun"))
					{
						switch(chr.equip.gun)
						{
							case "pistolbucket_dung":
								if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "6")
								{
									PlaySound("PEOPLE\cavern1.wav");
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									TakeItemFromCharacter(chr, "pistolbucket_dung");
									Locations[FindLocation(chr.location)].models.always.l10 = "solid_brown";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH1", 1.5);
								}
							break;

							case "pistolstonebasket_R":
								if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
								{
									PlaySound("PEOPLE\cavern1.wav");
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									TakeItemFromCharacter(chr, "pistolstonebasket_R");

									if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH2"
									|| Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
									{
										//stones burning up direct
										chr.crucible = "on";
										LAi_QuestDelay("oven_alchemy2_box9_burning_direct", 1.5);
									}
									else
									{
										Locations[FindLocation(chr.location)].models.always.l10 = "solid_red";

										chr.crucible = "on";
										LAi_QuestDelay("oven_alchemy2_box9_take_time_JRH1", 1.5);
									}
								}
							break;
						}
					}
				}

				switch(Locations[FindLocation(chr.location)].models.always.l8)
				{
					case "bottle_FQ1":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CQ1");
							EquipCharacterByItem(chr, "bladebottle_CQ1");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}
					break;

					case "bottle_FS1":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_ss");
							EquipCharacterByItem(chr, "bladebottle_CV1_ss");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "2";			//ready for mix 2

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "6")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_NH4Cl");
							EquipCharacterByItem(chr, "bladebottle_CV1_NH4Cl");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "7";			//ready for mix 7

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "5")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_cao");
							EquipCharacterByItem(chr, "bladebottle_CV1_cao");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "6";			//ready for mix 6

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_cao");
							EquipCharacterByItem(chr, "bladebottle_CV1_cao");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}
					break;

					case "bottle_FS2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV2");
							EquipCharacterByItem(chr, "bladebottle_CV2");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "3";			//ready for mix 3

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}
					break;

					case "bottle_FB2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CB2_mix9");
							EquipCharacterByItem(chr, "bladebottle_CB2_mix9");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "10";			//ready for mix 10
							chr.use_only_big_bottle = "no";		//small mix bottle enabled
							chr.use_only_small_bottle = "yes";	//big mix bottle disabled

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}
					break;

					case "bottle_FA2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CA2_mix11");
							EquipCharacterByItem(chr, "bladebottle_CA2_mix11");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box9", 1.0);
						}
					break;

					case "bottle_FY2":
						//PICK UP BOTTLE

					break;

					case "bottle_FE0":
						//EMPTY BOTTLE

						if(Locations[FindLocation(chr.location)].models.always.l11 == "")
						{
							//PLACE FUNNEL

							if(IsEquipCharacterByItem(chr, "pistolfunnel"))
							{
								PlaySound("INTERFACE\button2.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								TakeItemFromCharacter(chr, "pistolfunnel");
								Locations[FindLocation(chr.location)].models.always.l11 = "funnel";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box9", 0.5);
							}
							else
							{
					//pär extra funnel equip
								gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);

								if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
								{
									PlaySound("INTERFACE\button2.wav");
									EquipCharacterByItem(chr, "pistolfunnel");
								}

							}
						}
					break;

					case "":
						//PLACE EMPTY BOTTLE or EMPTY BOTTLE + FUNNEL

						if(IsEquipCharacterByItem(chr, "bladebottle_CE0") && IsEquipCharacterByItem(chr, "pistolfunnel"))
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							TakeItemFromCharacter(chr, "pistolfunnel");
							Locations[FindLocation(chr.location)].models.always.l11 = "funnel";

							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CE0");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation(chr.location)].models.always.l8 = "bottle_FE0";

							chr.crucible = "on";
							LAi_QuestDelay("oven_alchemy2_box9", 0.5);
						}		
						else
						{
							if(IsEquipCharacterByItem(chr, "bladebottle_CE0"))
							{						
								PlaySound("INTERFACE\glass1.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CE0");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation(chr.location)].models.always.l8 = "bottle_FE0";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box9", 0.5);
							}
							else
							{
					//pär extra equip
								weaponID7 = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);
								gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);

								if(weaponID7 == "" || weaponID7 == "bladeX4")
								{
									if(CheckCharacterItem(chr,"bladebottle_CE0"))
									{
										PlaySound("INTERFACE\glass1.wav");	
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										EquipCharacterByItem(chr, "bladebottle_CE0");

										if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
										{
											PlaySound("INTERFACE\button2.wav");
											EquipCharacterByItem(chr, "pistolfunnel");
										}
									}
									else
									{
										if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
										{
											PlaySound("INTERFACE\button2.wav");
											EquipCharacterByItem(chr, "bladeX4");
											EquipCharacterByItem(chr, "pistolfunnel");
										}
									}
								}
							}
						}
					break;
				}
			break;

			case "box10":
				//BELOW LADDER

				if(CheckCharacterItem(chr,"bladebottle_CE0"))
				{
					if(!IsEquipCharacterByItem(chr, "bladebottle_CE0"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladebottle_CE0");
					}
				}

				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "ladder");
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "goto4");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box11":
				//ACID BARREL

				if(CheckAttribute(chr,"2FH_acid") && chr.2FH_acid == "on")
				{
					PlaySound("INTERFACE\water_tap.wav");
					chr.2FH_acid = "off";
					LAi_SetPlayerType(chr);

					LAi_QuestDelay("2FH_running_acid", 0.01);
				}
				else
				{
					if(CheckAttribute(chr,"2FH_fillbottle") && chr.2FH_fillbottle == "on")
					{
						return;
					}
					else
					{
						if(CheckCharacterItem(chr,"bladebottle_CE0"))
						{
							chr.2FH_fillbottle = "on";
							PlaySound("INTERFACE\water_tap.wav");
							LAi_SetStayType(chr);

							LAi_QuestDelay("2FH_fill_acidbottle", 0.5);
						}
						else
						{
							PlaySound("INTERFACE\water_tap.wav");
							chr.2FH_acid = "off";
							LAi_SetStayType(chr);

							LAi_QuestDelay("2FH_running_acid", 0.5);
						}
					}
				}

				return;
			break;

			case "box12":
				//WOOD SUPPLY

				if(CheckCharacterItem(chr,"bladewood2"))
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I have already got some wood."));

					if(!IsEquipCharacterByItem(chr, "bladewood2"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladewood2");
					}
				}
				else
				{
					if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","I don't need more wood at the moment."));
					}
					else
					{
						PlaySound("OBJECTS\DUEL\plank.wav");
						TakeNItems(chr, "bladewood2", 1);
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladewood2");
					}
				}
			break;

			case "box13":
				//WHEEL

				if(CheckAttribute(chr, "alchemy2_box13") && chr.alchemy2_box13 == "temp_blocked") return;

				switch(Locations[FindLocation(chr.location)].models.always.l10)
				{
					case "liquid_white":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					case "liquid_mercury":
						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
							LAi_SetStayType(chr);
							chr.alchemy2_box13 = "temp_blocked";
							PlaySound("INTERFACE\rusty.wav");

							LAi_QuestDelay("crucible_turn", 1.0);
							return;
						}
					break;

					case "liquid_orange":
						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
							LAi_SetStayType(chr);
							chr.alchemy2_box13 = "temp_blocked";
							PlaySound("INTERFACE\rusty.wav");

							LAi_QuestDelay("crucible_turn", 1.0);
							return;
						}
					break;

					case "powder_white":
						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
						{
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
							LAi_SetStayType(chr);
							chr.alchemy2_box13 = "temp_blocked";
							PlaySound("INTERFACE\rusty.wav");

							LAi_QuestDelay("crucible_turn", 1.0);
							return;
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
						{
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
							LAi_SetStayType(chr);
							chr.alchemy2_box13 = "temp_blocked";
							PlaySound("INTERFACE\rusty.wav");

							LAi_QuestDelay("crucible_turn", 1.0);
							return;
						}

						if(CheckAttribute(chr, "Q2_mix"))
						{
							if(chr.Q2_mix == "5" || chr.Q2_mix == "9")
							{
								ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
								LAi_SetStayType(chr);
								chr.alchemy2_box13 = "temp_blocked";
								PlaySound("INTERFACE\rusty.wav");

								LAi_QuestDelay("crucible_turn", 1.0);
								return;
							}
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "6")
						{
							ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
							LAi_SetStayType(chr);
							chr.alchemy2_box13 = "temp_blocked";
							PlaySound("INTERFACE\rusty.wav");

							LAi_QuestDelay("crucible_turn", 1.0);
							return;
						}
					break;

					case "powder_grey":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					case "powder_light_yellow":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					case "powder_dark_yellow":
						ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
						LAi_SetStayType(chr);
						chr.alchemy2_box13 = "temp_blocked";
						PlaySound("INTERFACE\rusty.wav");

						LAi_QuestDelay("crucible_turn", 1.0);
						return;
					break;

					case "solid_brown":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					case "solid_grey":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					case "solid_red":
						LAi_QuestDelay("crucible_dont_turn", 0.1);
						return;
					break;

					//default: turn the wheel
					ChangeCharacterAddressGroup(chr, "wr_farm_alchemy2", "goto", "wheel1");
					LAi_SetStayType(chr);
					chr.alchemy2_box13 = "temp_blocked";
					PlaySound("INTERFACE\rusty.wav");

					LAi_QuestDelay("crucible_turn", 1.0);
				}		
			break;

			case "box14":
				//FIREPLACE also box9

				if(GetAttribute(chr, "crucible") == "on") return;	//to avoid 2 fast operations before DQR

				if(IsEquipCharacterByItem(chr, "bladewood2"))
				{
					PlaySound("PEOPLE\place_planks.wav");
					PlaySound("PEOPLE\jump_roof.wav");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladewood2" );
					EquipCharacterByItem(chr, "bladeX4");
					
					switch(Locations[FindLocation(chr.location)].models.always.locators)
					{
						case "TwoFloorHouse_locators_JRH0":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH1";
						break;

						case "TwoFloorHouse_locators_JRH1":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH2";
						break;

						case "TwoFloorHouse_locators_JRH2":
							Locations[FindLocation(chr.location)].models.always.locators = "TwoFloorHouse_locators_JRH3";
						break;
					}

					chr.crucible = "on";
					LAi_QuestDelay("place_wood_alchemy2_box14", 0.5);

					Locations[FindLocation("wr_farm_alchemy2")].image = "";
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.l10 == "" 
				&& Locations[FindLocation(chr.location)].models.always.l7 == "cauldron2")
				{
					//CAULDRON IS EMPTY AND NOT TILTED
					if(CheckAttribute(chr, "equip.blade"))
					{
						switch(chr.equip.blade)
						{
							case "bladebottle_BTc_hydr":
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BTc_hydr");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
								Locations[FindLocation(chr.location)].models.always.l10 = "liquid_white";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH3", 3.0);
							break;

							case "bladebottle_BG2":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BG2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
								Locations[FindLocation(chr.location)].models.always.l10 = "powder_grey";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH3", 1.5);
							break;

							case "bladebottle_CG1":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CG1");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//powder burning up direct
									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14_burning_direct", 1.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "powder_grey";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH2", 1.5);
								}
								return;		//so not empty bottle below gets activated direct
							break;

							case "bladebottle_BY2_mix9":
								PlaySound("INTERFACE\bottle_powder.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BY2_mix9");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH2"
								|| Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//powder burning up direct
									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14_burning_direct", 1.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "powder_light_yellow";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH1", 1.5);
								}
							break;

							case "bladebottle_CT2_mix11":
								PlaySound("INTERFACE\bottle_molasses.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CT2_mix11");
								GiveItem2Character(chr,"bladebottle_CE0");
								EquipCharacterByItem(chr, "bladebottle_CE0");

								if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
								{
									//reacting direct to orange liquid
									Locations[FindLocation(chr.location)].models.always.l10 = "liquid_orange";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14", 3.0);
									LAi_QuestDelay("oven_alchemy2_box14_burning_direct", 3.5);
								}
								else
								{
									Locations[FindLocation(chr.location)].models.always.l10 = "liquid_white";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14", 3.0);
								}
								return;
							break;
						}
					}
					
					if(CheckAttribute(chr, "equip.gun"))
					{
						switch(chr.equip.gun)
						{
							case "pistolbucket_dung":
								if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "6")
								{
									PlaySound("PEOPLE\cavern1.wav");
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									TakeItemFromCharacter(chr, "pistolbucket_dung");
									Locations[FindLocation(chr.location)].models.always.l10 = "solid_brown";

									chr.crucible = "on";
									LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH1", 1.5);
								}
							break;

							case "pistolstonebasket_R":
								if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
								{
									PlaySound("PEOPLE\cavern1.wav");
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									TakeItemFromCharacter(chr, "pistolstonebasket_R");

									if(Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH2"
									|| Locations[FindLocation("wr_farm_alchemy2")].models.always.locators == "TwoFloorHouse_locators_JRH3")
									{
										//stones burning up direct
										chr.crucible = "on";
										LAi_QuestDelay("oven_alchemy2_box14_burning_direct", 1.5);
									}
									else
									{
										Locations[FindLocation(chr.location)].models.always.l10 = "solid_red";

										chr.crucible = "on";
										LAi_QuestDelay("oven_alchemy2_box14_take_time_JRH1", 1.5);
									}
								}
							break;
						}
					}
				}

				switch(Locations[FindLocation(chr.location)].models.always.l8)
				{
					case "bottle_FQ1":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CQ1");
							EquipCharacterByItem(chr, "bladebottle_CQ1");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}
					break;

					case "bottle_FS1":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "1")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_ss");
							EquipCharacterByItem(chr, "bladebottle_CV1_ss");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "2";			//ready for mix 2

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "6")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_NH4Cl");
							EquipCharacterByItem(chr, "bladebottle_CV1_NH4Cl");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "7";			//ready for mix 7

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "5")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_cao");
							EquipCharacterByItem(chr, "bladebottle_CV1_cao");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "6";			//ready for mix 6

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV1_cao");
							EquipCharacterByItem(chr, "bladebottle_CV1_cao");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}
					break;

					case "bottle_FS2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "2")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CV2");
							EquipCharacterByItem(chr, "bladebottle_CV2");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "3";			//ready for mix 3

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}
					break;

					case "bottle_FB2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "9")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CB2_mix9");
							EquipCharacterByItem(chr, "bladebottle_CB2_mix9");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.Q2_mix = "10";			//ready for mix 10
							chr.use_only_big_bottle = "no";		//small mix bottle enabled
							chr.use_only_small_bottle = "yes";	//big mix bottle disabled

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}
					break;

					case "bottle_FA2":
						//PICK UP BOTTLE

						if(CheckAttribute(chr, "Q2_mix") && chr.Q2_mix == "11")
						{
							PlaySound("INTERFACE\glass1.wav");
							Locations[FindLocation(chr.location)].models.always.l8 = "";
							Locations[FindLocation(chr.location)].models.always.l11 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_CA2_mix11");
							EquipCharacterByItem(chr, "bladebottle_CA2_mix11");
							GiveItem2Character(chr,"pistolfunnel");
							EquipCharacterByItem(chr, "pistolfunnel");

							chr.crucible = "on";
							LAi_QuestDelay("extra_bottle_sound", 0.5);
							LAi_QuestDelay("oven_alchemy2_box14", 1.0);
						}
					break;

					case "bottle_FY2":
						//PICK UP BOTTLE

					break;

					case "bottle_FE0":
						//EMPTY BOTTLE

						if(Locations[FindLocation(chr.location)].models.always.l11 == "")
						{
							//PLACE FUNNEL

							if(IsEquipCharacterByItem(chr, "pistolfunnel"))
							{
								PlaySound("INTERFACE\button2.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								TakeItemFromCharacter(chr, "pistolfunnel");
								Locations[FindLocation(chr.location)].models.always.l11 = "funnel";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box14", 0.5);
							}
							else
							{
					//pär extra funnel equip
								gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);

								if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
								{
									PlaySound("INTERFACE\button2.wav");
									EquipCharacterByItem(chr, "pistolfunnel");
								}

							}
						}
					break;

					case "":
						//PLACE EMPTY BOTTLE or EMPTY BOTTLE + FUNNEL

						if(IsEquipCharacterByItem(chr, "bladebottle_CE0") && IsEquipCharacterByItem(chr, "pistolfunnel"))
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							TakeItemFromCharacter(chr, "pistolfunnel");
							Locations[FindLocation(chr.location)].models.always.l11 = "funnel";

							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CE0");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation(chr.location)].models.always.l8 = "bottle_FE0";

							chr.crucible = "on";
							LAi_QuestDelay("oven_alchemy2_box14", 0.5);
						}		
						else
						{
							if(IsEquipCharacterByItem(chr, "bladebottle_CE0"))
							{						
								PlaySound("INTERFACE\glass1.wav");
								PlaySound("PEOPLE\step_stairway2.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_CE0");
								EquipCharacterByItem(chr, "bladeX4");
								locations[FindLocation(chr.location)].models.always.l8 = "bottle_FE0";

								chr.crucible = "on";
								LAi_QuestDelay("oven_alchemy2_box14", 0.5);
							}
							else
							{
					//pär extra equip
								weaponID7 = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);
								gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);

								if(weaponID7 == "" || weaponID7 == "bladeX4")
								{
									if(CheckCharacterItem(chr,"bladebottle_CE0"))
									{
										PlaySound("INTERFACE\glass1.wav");	
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										EquipCharacterByItem(chr, "bladebottle_CE0");

										if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
										{
											PlaySound("INTERFACE\button2.wav");
											EquipCharacterByItem(chr, "pistolfunnel");
										}
									}
									else
									{
										if(gunID == "" && CheckCharacterItem(chr,"pistolfunnel"))
										{
											PlaySound("INTERFACE\button2.wav");
											EquipCharacterByItem(chr, "bladeX4");
											EquipCharacterByItem(chr, "pistolfunnel");
										}
									}
								}
							}
						}
					break;
				}
			break;
//pär grind
			case "box15":
				//FILL UP TANK FOR GRINDING

				if(!CheckAttribute(chr, "alchemy2_grinder") || chr.alchemy2_grinder == "empty")
				{
					if(IsEquipCharacterByItem(chr, "pistolstonebasket_B"))
					{
						chr.alchemy2_grinder = "black_stones";

						PlaySound("PEOPLE\cavern1.wav");
						RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
						TakeItemFromCharacter(chr, "pistolstonebasket_B" );

						return;
					}

				    	if(CheckAttribute(chr, "Q2_mix"))
				    	{
						if(chr.Q2_mix == "5" || chr.Q2_mix == "9")
				    		{
							if(IsEquipCharacterByItem(chr, "pistolstonebasket_G"))
							{
								chr.alchemy2_grinder = "grey_stones";						

								PlaySound("PEOPLE\cavern1.wav");
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								TakeItemFromCharacter(chr, "pistolstonebasket_G" );

								return;
							}
						}
				   	}

					if(!IsEquipCharacterByItem(chr, "pistolstonebasket_B") && !IsEquipCharacterByItem(chr, "pistolstonebasket_G"))
					{
						PlaySound("PEOPLE\step_echo.wav");
	
						if(CheckCharacterItem(chr,"pistolstonebasket_G") || CheckCharacterItem(chr,"pistolstonebasket_B"))
						{
							Logit(TranslateString("","I can grind stones here."));
						}
					}				
				}
			break;

			case "box16":
				//ROPE: POWDER OUT AFTER GRINDING
				
				LAi_SetSitType(chr);

				if(CheckAttribute(chr, "alchemy2_grinder"))
				{
					switch(chr.alchemy2_grinder)
					{
						case "black_stones":
							PlaySound("PEOPLE\key_box.wav");		
						break;

						case "grey_stones":
							PlaySound("PEOPLE\key_box.wav");		
						break;

						case "black_powder":
							PlaySound("INTERFACE\p_case_open.wav");	

							LAi_QuestDelay("alchemy2_grinder_powder_out", 1.0);
						break;

						case "grey_powder":
							PlaySound("INTERFACE\p_case_open.wav");	

							LAi_QuestDelay("alchemy2_grinder_powder_out", 1.0);		
						break;
					
						case "empty":
							PlaySound("INTERFACE\p_case_open.wav");			
						break;
					}

				}

				LAi_QuestDelay("pchar_playertype", 0.4);
			break;

		}
		return;
	}
//pär
	if(Locations[locidx].id=="wr_farm_booty2")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolstonebasket_R_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box2":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					PlaySound("INTERFACE\closet_open.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolstonebasket_M_check", 0.1);
					LAi_QuestDelay("pistolstonebasket_B_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box4":
				PlaySound("INTERFACE\locked_window.wav");
			break;
//pär gold
			case "box5":
				//GOLDBARS HERE

				if(CheckAttribute(chr,"booty2_box5") && chr.booty2_box5 == "on") return;

				if(Locations[FindLocation(chr.location)].models.always.l2 == "leadbars")
				{
					if(CheckCharacterItem(chr,"bladebottle_BAU"))
					{
					    if(Locations[FindLocation("wr_farm_alchemy2")].models.always.l16 == "goldbar")
					    {
						if(LAi_IsFightMode(chr))
						{
							//second 'open box'
							chr.booty2_box5 = "on";
							PlaySound("AMBIENT\CAVE\drop8.wav");
							PlaySound("AMBIENT\CAVE\drop4.wav");
							PlaySound("AMBIENT\CAVE\drop4.wav");
							PlaySound("AMBIENT\CAVE\drop4.wav");
							PlaySound("AMBIENT\CAVE\drop4.wav");
							PlaySound("AMBIENT\CAVE\drop4.wav");								

							LAi_QuestDelay("making_more_gold", 2.0);
						}
						else
						{
							//first 'open box'
							if(!IsEquipCharacterByItem(chr, "bladebottle_BAU"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladebottle_BAU");
							}

							Logit(TranslateString("","I'll use more this time. Five drops maybe."));
							ChangeCharacterAddressGroup(chr, "wr_farm_booty2", "goto", "goto1");
							LAi_LocationFightDisable(&Locations[FindLocation("wr_farm_booty2")], false);
							LAi_SetFightMode(chr, true);
							PlaySound("VOICE\ENGLISH\blaze_5.wav");
						}
					    }
					    else
					    {
						if(!IsEquipCharacterByItem(chr, "bladebottle_BAU"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladebottle_BAU");
						}

						LAi_SetActorType(chr);	
						characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "single_silverbar_first";
						LAi_ActorSelfDialog(chr, "");
					    }
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
						Logit(TranslateString("","No, it looks more like unclean Silver. If all that could be Gold!"));
					}
				}
				else
				{
					//it's gold!
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_farm_booty")
	{
		switch(chr.boxname)
		{
			case "box8":
				//water barrel
				if(CheckAttribute(chr,"quest.farm_water") && chr.quest.farm_water == "on")
				{
					PlaySound("INTERFACE\water_tap.wav");
					chr.quest.farm_water = "off";
					LAi_SetPlayerType(chr);

					LAi_QuestDelay("farm_running_water", 0.01);
				}
				else
				{
					if(CheckAttribute(chr,"quest.farmbooty_fillbottle") && chr.quest.farmbooty_fillbottle == "on")
					{
						return;
					}
					else
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladecauldron")
						{
							chr.quest.farmbooty_fillbottle = "on";
							LAi_SetStayType(chr);

							LAi_QuestDelay("farm_fill_cauldron_booty", 0.5);
						}
						else
						{
							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
							{
								chr.quest.farmbooty_fillbottle = "on";
								PlaySound("INTERFACE\water_tap.wav");
								LAi_SetStayType(chr);

								LAi_QuestDelay("farm_fill_waterbottle", 0.5);
							}
						}
						else
						{
							PlaySound("INTERFACE\water_tap.wav");
							chr.quest.farm_water = "on";
							LAi_SetStayType(chr);

							LAi_QuestDelay("farm_running_water", 0.5);
						}
					}
				}

				return;
			break;

			case "box1":
				if(CheckAttribute(chr,"quest.distillery_items") && chr.quest.distillery_items == "open")
				{
					LaunchItemsBox(&ar);

					if(locations[FindLocation(chr.location)].box1.items.bladebottle_CP2 >=1)
					{
						LAi_QuestDelay("champagne_bottle_check", 0.1);
					}

					if(locations[FindLocation(chr.location)].box1.items.book51 ==1)
					{
						LAi_QuestDelay("book51_check", 0.1);
					}
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.distillery_items") && chr.quest.distillery_items == "open")
				{
					LaunchItemsBox(&ar);

					if(locations[FindLocation(chr.location)].box2.items.pistolglass_tube >=1)
					{
						LAi_QuestDelay("glass_tube_check", 0.1);
						return;
					}
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box3":
				if(CheckAttribute(chr,"quest.distillery_items") && chr.quest.distillery_items == "open")
				{
					LaunchItemsBox(&ar);

					if(locations[FindLocation(chr.location)].box3.items.bladetop >=1)
					{
						LAi_QuestDelay("top_check", 0.1);
						return;
					}
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box4":
				if(CheckAttribute(chr,"quest.distillery_items") && chr.quest.distillery_items == "open")
				{
					LaunchItemsBox(&ar);

					if(locations[FindLocation(chr.location)].box4.items.pistolretort >=1)
					{
						LAi_QuestDelay("retort_check", 0.1);
						return;
					}
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box5":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					LaunchItemsBox(&ar);

					LAi_QuestDelay("big_empty_bottle_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box6":
				if(CheckAttribute(chr,"quest.distillery_items") && chr.quest.distillery_items == "open")
				{
					LaunchItemsBox(&ar);

					if(locations[FindLocation(chr.location)].box6.items.bladebottle_CE0 >=1)
					{
						LAi_QuestDelay("empty_bottle_check", 0.1);
						return;
					}
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box7":
				if(CheckAttribute(chr,"quest.distillery_items_Q2") && chr.quest.distillery_items_Q2 == "open")
				{
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pistolbucket_dung_check", 0.1);
					LAi_QuestDelay("pistolsulphur_WR_check", 0.1);
					LAi_QuestDelay("pistolstonebasket_G_check", 0.1);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box9":
				//looks like a locked wardrobe (before open from alchemy)
				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			LaunchItemsBox(&ar);
			return;
		}
		return;
	}

	if(Locations[locidx].id=="wr_secret")
	{
		if(CheckAttribute(chr,"quest.clear_study_boxes") && chr.quest.clear_study_boxes == "yes")
		{
			locations[FindLocation(chr.location)].box1.items.blade1 = 0;
			locations[FindLocation(chr.location)].box1.items.pistol20 = 0;
			locations[FindLocation(chr.location)].box1.items.ammobag1 = 0;
			locations[FindLocation(chr.location)].box1.items.ammobag2 = 0;

			locations[FindLocation(chr.location)].box1.items."bladeA5" = 0;
			locations[FindLocation(chr.location)].box1.items."spyglass3" = 0;
			locations[FindLocation(chr.location)].box1.items.temp_coins = 0;
			locations[FindLocation(chr.location)].box1.items.sewing_kit = 0;
			locations[FindLocation(chr.location)].box1.items.tobacco = 0;
			locations[FindLocation(chr.location)].box1.items.folding_knife = 0;
			locations[FindLocation(chr.location)].box1.items.compass1 = 0;
			locations[FindLocation(chr.location)].box1.items.pistoltinderbox = 0;
			locations[FindLocation(chr.location)].box1.items.key17 = 0;

			locations[FindLocation(chr.location)].box1.items.red_uniform = 0;
			locations[FindLocation(chr.location)].box1.items.sextant = 0;
			locations[FindLocation(chr.location)].box1.items.tin_jug = 0;
			locations[FindLocation(chr.location)].box1.items.tobacco = 0;
			locations[FindLocation(chr.location)].box1.items."pistol9+2" = 0;
			locations[FindLocation(chr.location)].box1.items.silver_bar = 0;
			locations[FindLocation(chr.location)].box1.items.clock1 = 0;
 			locations[FindLocation(chr.location)].box1.items.foreign_items = 0;
			locations[FindLocation(chr.location)].box1.items.drawing_kit = 0;
			locations[FindLocation(chr.location)].box1.items.strange_shells = 0;
			locations[FindLocation(chr.location)].box1.items.package = 0;
			locations[FindLocation(chr.location)].box1.items.temp_purse = 0;

			locations[FindLocation(chr.location)].box1.money = 0;
		}

		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_corv_smallcabin_L")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_smallcabin_L", "goto", "goto8");
			break;

			case "box3":
				PlaySound("INTERFACE\wheel_take.wav");
				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
				GiveItem2Character(chr,"pistolwheel");
				EquipCharacterByItem(chr, "pistolwheel");
				Locations[FindLocation("wr_corv_smallcabin_L")].models.always.l2 = "";		//wheel picked up

				Locations[FindLocation("wr_corv_smallcabin_L")].locators_radius.reload.reload7 = 0.5;
				Locations[FindLocation("wr_corv_smallcabin_L")].locators_radius.box.box2 = 0.0001;

				LAi_QuestDelay("pick_up_pistolwheel", 0.5);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_corv_smallcabin_R")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "wr_corv_smallcabin_R", "goto", "goto9");
			break;

			case "box4":
				LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_cap_inner")
	{
		switch(chr.boxname)
		{
			case "box1":
				Logit(TranslateString("","Water supply"));
				PlaySound("INTERFACE\rum_barrel_filled.wav");
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.cap_inner_gp_box") && chr.quest.cap_inner_gp_box == "locked")
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
				else LaunchItemsBox(&ar);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_deck2_prow")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_prow_left", 2.0);
			break;

			case "box1":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_prow_right", 2.0);
			break;

			case "box3":
				PlaySound("INTERFACE\pinion_take.wav");
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr,"bladepinion_small");
				EquipCharacterByItem(chr, "bladepinion_small");
				Locations[FindLocation("wr_gall_deck2_prow")].models.always.l2 = "";//small pinion picked up
				Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box3 = 0.001;

				LAi_QuestDelay("pick_up_pinion_small", 0.5);
			break;

			case "box4":
				if(IsEquipCharacterByItem(chr, "bladeirontool"))
				{
					LAi_SetFightMode(chr, true);
					Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box4 = 0.0001;
					Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.randitem.randitem5 = 1.5;		//plank

					LAi_QuestDelay("remove_plank_prow", 1.0);
				}
				else
				{
					Logit(TranslateString("","I can't remove that plank with my bare hands."));
					Logit(TranslateString("","But I guess it's the Galley."));
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");

					if(CheckAttribute(chr,"quest.qbook_crowbar") && chr.quest.qbook_crowbar == "done")
					{

					}
					else
					{
						chr.quest.qbook_crowbar = "done";
						AddQuestRecord("Open_the_galley", "2");
					}
				}
			break;

			case "box5":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_prow_galley", 2.0);
			break;

			case "box6":
				//anvil
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_SetSitType(chr);

				LAi_QuestDelay("anvil_too_heavy", 1.0);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_deck2_stern")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.cannon_goodspile") && chr.quest.cannon_goodspile == "gone")
				{
					Logit(TranslateString("","Cannonball storage is empty!!"));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				}
				else
				{
					Logit(TranslateString("","Cannonball storage"));
					PlaySound("PEOPLE\step_iron.wav");
					PlaySound("PEOPLE\step_iron.wav");
					PlaySound("PEOPLE\step_iron.wav");
				}
				return;
			break;

			case "box2":
				Logit(TranslateString("","Wad of rugs supply"));
				PlaySound("PEOPLE\clothes1.wav");
				return;
			break;

			case "box3":
				Logit(TranslateString("","Gunpowder storage"));
				PlaySound("PEOPLE\grass_noise.wav");
				return;
			break;

			case "box4":
				Logit(TranslateString("","Wad of rugs supply"));
				PlaySound("PEOPLE\clothes1.wav");
				return;
			break;

			case "box7":
				Logit(TranslateString("","Gunpowder storage"));
				PlaySound("PEOPLE\grass_noise.wav");
				return;
			break;

			case "box8":
				Logit(TranslateString("","Gunpowder storage"));
				PlaySound("PEOPLE\grass_noise.wav");
				return;
			break;

			case "box9":
				Logit(TranslateString("","Gunpowder storage"));
				PlaySound("PEOPLE\grass_noise.wav");
				return;
			break;

			case "box10":
				Logit(TranslateString("","Gunpowder storage"));
				PlaySound("PEOPLE\grass_noise.wav");
				return;
			break;

			case "box5":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_stern_left", 2.0);
			break;

			case "box6":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_stern_right", 2.0);
			break;

			case "box11":
				if(IsEquipCharacterByItem(chr, "bladebottle_CA2"))
				{
					LAi_SetPlayerType(chr);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("acid_gold_door", 1.0);
				}
			break;

			case "box12":
				if(CheckCharacterItem(chr,"bladebottle_CA2"))
				{
					Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload5 = 0.001;
					Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box11 = 1.0;
					ChangeCharacterAddressGroup(chr, "wr_gall_deck2_stern", "goto", "goto3");
				}
				else
				{
					ChangeCharacterAddressGroup(chr, "wr_gall_deck2_stern", "reload", "reload5");
				}
				PlaySound("PEOPLE\creak2.wav");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_hold_first")
	{
		switch(chr.boxname)
		{
			case "box1":
				//tie ropes to elevator
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_QuestDelay("ropes_to_elevator", 1.0);

				return;
			break;

			case "box2":
				//pick up bladeirontool
				chr.quest.bladeirontool = "picked_up";
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladeX4");
				LAi_SetFightMode(chr, true);
				Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "";//irontool picked up
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box2 = 0.001;
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box5 = 0.5;		//irontool

				LAi_QuestDelay("pick_up_bladeirontool", 1.0);

				return;
			break;

			case "box3":
				if(IsEquipCharacterByItem(chr, "bladebottle_CT2_nitr_w"))
				{
					ChangeCharacterAddressGroup(chr, "wr_gall_hold_first", "goto", "goto2");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "goto3");

					LAi_QuestDelay("acid_silver_door", 1.0);
				}
				else
				{
					PlaySound("INTERFACE\knock.wav");
					PlaySound("PEOPLE\crew_noise.wav");
					PlaySound("PEOPLE\crew_noise.wav");
					PlaySound("PEOPLE\crew_noise.wav");

					LAi_QuestDelay("Pchar_hah", 7.0);
				}
			break;

			case "box6":
				//short stair floor level
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_gall_hold_first", "goto", "reload4");
			break;

			case "box4":
				//short stair medium level
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_gall_hold_first", "goto", "reload5");
			break;

			case "box5":
				//short stair top level
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "wr_gall_hold_first", "goto", "reload6");

				if(!CheckCharacterItem(chr,"bladeirontool")) LAi_QuestDelay("mast_so_what", 1.0);
			break;

			case "box7":
				//crew sound
				PlaySound("INTERFACE\knock.wav");
				PlaySound("PEOPLE\crew_noise.wav");
				PlaySound("PEOPLE\crew_noise.wav");
				PlaySound("PEOPLE\crew_noise.wav");

				LAi_QuestDelay("Pchar_hah", 7.0);
			break;

		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_hold_second")
	{
		switch(chr.boxname)
		{
			case "box1":
				//half way up stair to cap_inner
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_gall_hold_second", "goto", "goto1");
			break;

			case "box2":
				if(IsEquipCharacterByItem(chr, "bladeirontool"))
				{
					LAi_SetFightMode(chr, true);
					Locations[FindLocation("wr_gall_hold_second")].locators_radius.box.box2 = 0.0001;
					Locations[FindLocation("wr_gall_hold_second")].locators_radius.randitem.randitem11 = 2.0;//1.5 no good

					LAi_QuestDelay("remove_planks_hold", 1.0);
				}
				else
				{
					Logit(TranslateString("","I can't remove that plank with my bare hands."));
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_ships")
	{
		switch(chr.boxname)
		{
			case "box3":
				if(CheckAttribute(chr,"quest.corvette_status") && chr.quest.corvette_status == "schhh")
				{
					//using this above as a check for part 10 (broadside etc)
					Logit(TranslateString("","Hmm. That's not a good idea"));

					return;
				}

				if(CheckAttribute(chr, "quest.deck_bell") && chr.quest.deck_bell == "broken")
				{
					PlaySound("INTERFACE\bell_broken.wav");
				}
				else PlaySound("INTERFACE\bell2.wav");

				if(CheckAttribute(chr,"quest.guncrew") && chr.quest.guncrew == "locked_in")
				{
					PlaySound("PEOPLE\crew_noise.wav");

					LAi_QuestDelay("Pchar_whatwasthat", 7.0);
				}
				else
				{
					if(CheckAttribute(chr,"quest.guncrew") && chr.quest.guncrew == "dialog_in_hold")
					{
						return;
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.guncrew") && chr.quest.guncrew == "free_in_hold")
					{
						if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W3" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N3"
						|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E3" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S3")
						return;	//if cannon high crew doesn't return

						if(CheckAttribute(chr,"quest.ammodeck") && chr.quest.ammodeck == "open")
						{
							chr.quest.guncrew = "at_cannon_with_ammo";

							Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload3 = 1.0;
							Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload2 = 1.0;
							Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box5 = 0.0001;
							Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box6 = 0.0001;
							Locations[FindLocation("wr_ships")].reload.l8.disable = 0;
							Locations[FindLocation("wr_ships")].reload.l9.disable = 0;

							GiveItem2Character(CharacterFromID("guncrew_1"), "pistolbarrel4");
							EquipCharacterByItem(CharacterFromID("guncrew_1"), "pistolbarrel4");

							if(chr.quest.ammodeck_ball == "yes")
							{
								RemoveCharacterEquip(CharacterFromID("guncrew_2"), BLADE_ITEM_TYPE);
								GiveItem2Character(CharacterFromID("guncrew_2"), "bladecannon_ball");
								EquipCharacterByItem(CharacterFromID("guncrew_2"), "bladecannon_ball");
								chr.quest.ammodeck_ball = "no";	//happens only first time
							}
							EquipCharacterByItem(CharacterFromID("guncrew_2"), "pistolrammer");

							RemoveCharacterEquip(CharacterFromID("guncrew_3"), BLADE_ITEM_TYPE);
							GiveItem2Character(CharacterFromID("guncrew_3"), "bladewad");
							EquipCharacterByItem(CharacterFromID("guncrew_3"), "bladewad");
							EquipCharacterByItem(CharacterFromID("guncrew_3"), "pistolboom");

							RemoveCharacterEquip(CharacterFromID("guncrew_4"), BLADE_ITEM_TYPE);
							GiveItem2Character(CharacterFromID("guncrew_4"), "bladebucket");
							EquipCharacterByItem(CharacterFromID("guncrew_4"), "bladebucket");
							GiveItem2Character(CharacterFromID("guncrew_4"), "pistolsponge");
							EquipCharacterByItem(CharacterFromID("guncrew_4"), "pistolsponge");

							LAi_QuestDelay("guncrew_exit_R8_1", 1.0);
							LAi_QuestDelay("guncrew_exit_R8_2", 2.0);
							LAi_QuestDelay("guncrew_exit_R9_1", 0.5);
							LAi_QuestDelay("guncrew_exit_R9_2", 2.0);
						}
						else
						{
							chr.quest.guncrew = "at_cannon_without_ammo";

							Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.reload.reload3 = 1.0;
							Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.reload.reload2 = 1.0;
							Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box1 = 0.0001;
							Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box2 = 0.0001;
							Locations[FindLocation("wr_ships")].reload.l10.disable = 0;
							Locations[FindLocation("wr_ships")].reload.l11.disable = 0;

							LAi_QuestDelay("guncrew_exit_R11_1", 1.0);
							LAi_QuestDelay("guncrew_exit_R11_2", 2.0);
							LAi_QuestDelay("guncrew_exit_R10_1", 0.5);
							LAi_QuestDelay("guncrew_exit_R10_2", 2.0);
						}
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.guncrew"))
					{
						if(chr.quest.guncrew == "at_cannon_with_ammo" || chr.quest.guncrew == "at_cannon_without_ammo")
						{
							int gunnergreeting = rand(3);
							switch (gunnergreeting)
							{
								case 0: PlaySound("VOICE\ENGLISH\guncrew_1.wav"); break;

								case 1: PlaySound("VOICE\ENGLISH\guncrew_2.wav"); break;

								case 2: PlaySound("VOICE\ENGLISH\guncrew_3.wav"); break;

								case 3: PlaySound("VOICE\ENGLISH\guncrew_4.wav"); break;
							}
						}
					}
				}
				return;
			break;

			case "box4":
				//use as a checkpoint only
				return;
			break;

			case "box5":
				//cannon up
				if(CheckAttribute(chr,"quest.deck_cannon") && chr.quest.deck_cannon == "no_ropes")
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					return;
				}

				if(CheckAttribute(chr,"quest.pistolwheel") && chr.quest.pistolwheel == "picked_up")
				{
					Locations[FindLocation("wr_ships")].locators_radius.box.box12 = 0.001;
				}
				else Locations[FindLocation("wr_ships")].locators_radius.box.box12 = 1.2;


				if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W1" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N1"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E1" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1X" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W0"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N0" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E0"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S0")
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("shipcannon_up_box5", 1.0);
					return;
				}
			break;

			case "box6":
				if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
				{
					//cannon down
					Locations[FindLocation("wr_ships")].locators_radius.box.box12 = 0.001;
					PlaySound("PEOPLE\clothes1.wav");

					LAi_QuestDelay("shipcannon_down", 0.5);
					return;
				}

				if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W3" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N3"
				|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E3" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S3")
				{

					//cannon hard down
					Locations[FindLocation("wr_ships")].locators_radius.box.box12 = 0.001;
					PlaySound("PEOPLE\clothes1.wav");
					Locations[FindLocation("wr_ships")].models.always.l2 = "";	//was deck_box
					Locations[FindLocation("wr_ships")].locators_radius.reload.reload6 = 1.0;//visible to crew but blocked

					LAi_QuestDelay("shipcannon_hard_down", 0.5);
					return;
				}
			break;

			case "box7":
				//ropes on quarterdeck
				if(CheckAttribute(chr,"quest.deck_cannon") && chr.quest.deck_cannon == "no_ropes")
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					return;
				}

				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Locations[FindLocation("wr_ships")].locators_radius.box.box7 = 0.0001;

				LAi_QuestDelay("shipcannon_high_up_box7", 1.0);
				return;
			break;

			case "box8":
				//left position
				if(CheckAttribute(chr,"quest.anchor_mechanism") && chr.quest.anchor_mechanism == "complete")
				{
					//anchor down! - is up, invisible else
					PlaySound("INTERFACE\shelf_cogs.wav");
					LAi_SetSitType(chr);

					chr.quest.anchor = "down";
					Locations[FindLocation("wr_ships")].models.always.l5 = "anchor0";		//down
					Locations[FindLocation("wr_ships")].models.always.l6 = "elevator&ropes_C2";	//air
					Locations[FindLocation("wr_ships")].models.always.l14 = "";			//never ropes when anchor is down
					Locations[FindLocation("wr_ships")].locators_radius.reload.reload7 = 1.0;
					Locations[FindLocation("wr_corv_deck1")].reload.l5.disable = 0;
					Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G2";//air

					if(chr.quest.anchor_size == "small")
					{
						SetCurrentTime(23.00, 0);
						SetNextWeather("Clear");
						//Weathers["Moon Night"].Rain.NumDrops = 0;
						//Weathers["Moon Night"].Fog.Enable = false;
						locations[FindLocation("wr_ships")].type = "silent_seashore";
					}

					if(CheckAttribute(chr,"quest.elevatorG_status"))
					{
						if(chr.quest.elevatorG_status == "ropes_placed")
						{
							Locations[FindLocation("wr_ships")].models.always.l7 = "ropes2";
							Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "ropes2";
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box1 = 0.001;//place ropes function
						}

						if(chr.quest.elevatorG_status == "elevator_ready")
						{
							Locations[FindLocation("wr_ships")].models.always.l7 = "elevator&ropes_G2";			//air
							Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "elevator&ropes_G2";
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.randitem.randitem10 = 1.5;   	//enable pick up planks in hold
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box2 = 0.001;         	//disable pick up irontool
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box5 = 0.5;			//irontool

							if(CheckAttribute(chr,"quest.bladeirontool") && chr.quest.bladeirontool == "picked_up")
							{
								Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "";			//no irontool
								Locations[FindLocation("wr_ships")].models.always.l8 = "";				//no irontool
							}
							else
							{
								Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "irontool2";
								Locations[FindLocation("wr_ships")].models.always.l8 = "irontool";
							}

							if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "deck")
							{
								if(CheckAttribute(chr,"quest.elevator_position") && chr.quest.elevator_position == "hold")
								{
									Locations[FindLocation("wr_ships")].models.always.l9 = "plank2";
									chr.quest.plank_position = "air";
									Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 1.0;	//enable fall
									Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 0.0001;    	//disable pick up planks from deck
									Locations[FindLocation("wr_gall_hold_first")].models.always.l2 = "plank2";	//planks in the air seen from hold
								}

								if(CheckAttribute(chr,"quest.elevator_position") && chr.quest.elevator_position == "deck")
								{
									Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 0.0001;	//disable fall

									if(CheckAttribute(chr,"quest.corvette_status") && chr.quest.corvette_status == "schhh")
									{
										//no pick up planks during fight
										Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 0.0001;    	//disable pick up planks from deck
									}
									else
									{
										Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 2.0; 		//enable pick up planks from deck
									}
								}
							}
							else
							{
								Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 1.0;	//enable fall

								if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "picked_up")
								{
									Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 2.0; 		//enable place planks on deck
								}
								else Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 0.0001;    	//disable pick up planks from deck
							}
						}
					}

					Locations[FindLocation("wr_ships")].image = "";
					Locations[FindLocation("wr_ships")].locators_radius.box.box8 = 0.0001;
					Locations[FindLocation("wr_ships")].locators_radius.box.box9 = 0.5;

					LAi_QuestDelay("anchor_down_ships", 1.0);
				}
				else
				{
					if(CheckAttribute(chr,"quest.anchor_mechanism") && chr.quest.anchor_mechanism == "anchor_lost")
					{

						//"anchor" down! - is up
						PlaySound("INTERFACE\shelf_cogs.wav");
						LAi_SetSitType(chr);

						chr.quest.anchor_lost = "down";
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor0";		//down

						Locations[FindLocation("wr_ships")].image = "";
						Locations[FindLocation("wr_ships")].locators_radius.box.box8 = 0.0001;
						Locations[FindLocation("wr_ships")].locators_radius.box.box9 = 0.5;

						LAi_QuestDelay("anchor_down_ships", 1.0);
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.anchor") && chr.quest.anchor == "up")
					{

						//anchor down! - mechanism not ready (do this before fixing with pinions etc)
						PlaySound("INTERFACE\shelf_cogs.wav");
						LAi_SetSitType(chr);

						chr.quest.anchor = "down";
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor0";		//down
						Locations[FindLocation("wr_ships")].models.always.l6 = "elevator&ropes_C2";	//air
						Locations[FindLocation("wr_ships")].locators_radius.reload.reload7 = 1.0;
						Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G2";//air

						if(CheckAttribute(chr,"quest.elevatorG_status"))
						{
							if(chr.quest.elevatorG_status == "ropes_placed")
							{
								Locations[FindLocation("wr_ships")].models.always.l7 = "ropes2";
								Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "ropes2";
								Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box1 = 0.001;//place ropes function
							}
						}

						Locations[FindLocation("wr_ships")].image = "";

						LAi_QuestDelay("anchor_down_ships", 1.0);
					}
					else
					{
						//pinions etc in here

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box', used for placing/taking pinions. (fire gun = wheel)

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladepinion_small")
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_on_hub_already", 1.0);

									return;
								}
								else
								{
									if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
									{
										//wheel on the other hub but blocking

										PlaySound("INTERFACE\damper_change.wav");
										LAi_QuestDelay("wheel_blocking", 1.0);

										return;
									}
								}
								else
								{
									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "free")
									{
										//place small pinion!
										PlaySound("INTERFACE\pinion_place.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										TakeItemFromCharacter(chr, "bladepinion_small");
										EquipCharacterByItem(chr, "bladeX4");

										Locations[FindLocation("wr_ships")].models.always.l10 = "pinion_small_L";
										chr.quest.pinion_pos_left = "small";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}

									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "large")
									{
										//place small pinion & pick up large one!
										PlaySound("INTERFACE\pinion_place.wav");
										PlaySound("INTERFACE\pinion_take.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										TakeItemFromCharacter(chr, "bladepinion_small");
										GiveItem2Character(chr,"bladepinion_large");
										EquipCharacterByItem(chr, "bladepinion_large");

										Locations[FindLocation("wr_ships")].models.always.l10 = "pinion_small_L";
										chr.quest.pinion_pos_left = "small";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}
								}
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladepinion_large")
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_on_hub_already", 1.0);

									return;
								}
								else
								{
									if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
									{
										//wheel on the other hub but blocking

										PlaySound("INTERFACE\damper_change.wav");
										LAi_QuestDelay("wheel_blocking", 1.0);

										return;
									}
								}
								else
								{
									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "free")
									{
										//place large pinion!
										PlaySound("INTERFACE\pinion_place.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										TakeItemFromCharacter(chr, "bladepinion_large");
										EquipCharacterByItem(chr, "bladeX4");

										Locations[FindLocation("wr_ships")].models.always.l10 = "pinion_large_L";
										chr.quest.pinion_pos_left = "large";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}

									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "small")
									{
										//place large pinion & pick up small one!
										PlaySound("INTERFACE\pinion_place.wav");
										PlaySound("INTERFACE\pinion_take.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										TakeItemFromCharacter(chr, "bladepinion_large");
										GiveItem2Character(chr,"bladepinion_small");
										EquipCharacterByItem(chr, "bladepinion_small");

										Locations[FindLocation("wr_ships")].models.always.l10 = "pinion_large_L";
										chr.quest.pinion_pos_left = "large";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}
								}
							}

							if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_on_hub_already", 1.0);

									return;
								}
								else
								{
									if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
									{
										//wheel on the other hub but blocking

										PlaySound("INTERFACE\damper_change.wav");
										LAi_QuestDelay("wheel_blocking", 1.0);

										return;
									}
								}
								else
								{
									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "small")
									{
										//pick up small one!
										PlaySound("INTERFACE\pinion_take.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										GiveItem2Character(chr,"bladepinion_small");
										EquipCharacterByItem(chr, "bladepinion_small");

										Locations[FindLocation("wr_ships")].models.always.l10 = "";
										chr.quest.pinion_pos_left = "free";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}

									if(CheckAttribute(chr,"quest.pinion_pos_left") && chr.quest.pinion_pos_left == "large")
									{
										//pick up large one!
										PlaySound("INTERFACE\pinion_take.wav");
										RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
										GiveItem2Character(chr,"bladepinion_large");
										EquipCharacterByItem(chr, "bladepinion_large");

										Locations[FindLocation("wr_ships")].models.always.l10 = "";
										chr.quest.pinion_pos_left = "free";

										LAi_QuestDelay("at_mechanism_L", 0.5);
										return;
									}
								}
							}
						}
						else
						{
							if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								if(!CheckCharacterItem(chr,"pistolhand")) GiveItem2Character(chr,"pistolhand");
								EquipCharacterByItem(chr, "pistolhand");//able to pick up wheel
							}

							chr.quest.deck_position = "mechanism_L";
							ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "stuck8");
							LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("stay_at_stuck8", 1.0);
						}
					}
				}

				return;
			break;

			case "box9":
				//right position
				if(CheckAttribute(chr,"quest.broadside") && chr.quest.broadside == "started")
				{
					Logit(TranslateString("","Hmm. That's not a good idea"));
					return;
				}

				if(CheckAttribute(chr,"quest.anchor_mechanism") && chr.quest.anchor_mechanism == "complete")
				{
					//anchor up! - is down, invisible else
					PlaySound("PEOPLE\drill_water.wav");
					LAi_SetSitType(chr);

					LAi_QuestDelay("anchor_up_animation", 0.25);

					chr.quest.anchor = "up";
					Locations[FindLocation("wr_ships")].models.always.l6 = "elevator&ropes_C1";	//deck
					Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G1";//deck

					if(CheckAttribute(chr,"quest.anchor_size"))
					{
						if(chr.quest.anchor_size == "large")
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor1";

						if(chr.quest.anchor_size == "small")
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor_small1";
					}

					if(CheckAttribute(chr,"quest.elevator_ropes") && chr.quest.elevator_ropes == "picked_up")
					{
						Locations[FindLocation("wr_ships")].locators_radius.randitem.randitem2 = 0.0001;
					}
					else
					{
						Locations[FindLocation("wr_ships")].models.always.l14 = "ropesA";		//ropes on anchor
						Locations[FindLocation("wr_ships")].locators_radius.randitem.randitem2 = 1.5;	//with p.u. elevator_ropes
					}

					Locations[FindLocation("wr_ships")].locators_radius.reload.reload7 = 0.0001;
					Locations[FindLocation("wr_corv_deck1")].reload.l5.disable = 1;

					if(CheckAttribute(chr,"quest.elevatorG_status"))
					{
						if(chr.quest.elevatorG_status == "ropes_placed")
						{
							Locations[FindLocation("wr_ships")].models.always.l7 = "ropes0";
							Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "ropes0";
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box1 = 1.5;//place ropes function
						}

						if(chr.quest.elevatorG_status == "elevator_ready")
						{
							if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "deck")
							{
								Locations[FindLocation("wr_ships")].models.always.l7 = "elevator&ropes_G1";	//deck
								Locations[FindLocation("wr_ships")].models.always.l8 = "";			//invisible irontool on deck!
								Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "elevator&ropes_G1";

								Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 0.0001;//disable fall
								Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 0.0001;      //disable pick up planks from deck
								chr.quest.elevator_position = "deck";

								if(CheckAttribute(chr,"quest.bladeirontool") && chr.quest.bladeirontool == "picked_up")
								{
									Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "";			//no irontool
								}
								else
								{
									Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "irontool1";
									Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box2 = 0.5;          //enable pick up irontool
									Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box5 = 0.0001;       //irontool
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "air")
								{
									Locations[FindLocation("wr_ships")].models.always.l7 = "elevator&ropes_G0";	//hold
									Locations[FindLocation("wr_ships")].models.always.l8 = "";		//invisible irontool
									Locations[FindLocation("wr_gall_hold_first")].models.always.l2 = "plank1";
									Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "elevator&ropes_G0";
									Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "";	//invisible irontool
									Locations[FindLocation("wr_ships")].models.always.l9 = "plank1";	//on deck
									Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 0.0001;//disable fall
									Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 2.0;    //enable pick up planks from deck
									chr.quest.plank_position = "deck";
									chr.quest.elevator_position = "hold";
								}
							}
							else
							{
								Locations[FindLocation("wr_ships")].models.always.l7 = "elevator&ropes_G0";	//hold
								Locations[FindLocation("wr_ships")].models.always.l8 = "";		   	//invisible irontool
								Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "elevator&ropes_G0";
								Locations[FindLocation("wr_gall_hold_first")].models.always.l5 = "";	     	//invisible irontool
								Locations[FindLocation("wr_gall_hold_first")].locators_radius.randitem.randitem10 = 0.0001;   //disable pick up planks in hold
								Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 1.0;   	//enable fall
								chr.quest.elevator_position = "hold";

								if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "picked_up")
								{
									Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 2.0;      	//enable place planks on deck
								}
								else Locations[FindLocation("wr_ships")].locators_radius.box.box11 = 0.0001;      	//disable pick up planks from deck
							}
						}
					}

					Locations[FindLocation("wr_ships")].image = "";

					Locations[FindLocation("wr_ships")].locators_radius.box.box8 = 0.5;
					Locations[FindLocation("wr_ships")].locators_radius.box.box9 = 0.0001;

					LAi_QuestDelay("anchor_up_ships", 1.0);
				}
				else
				{
					if(CheckAttribute(chr,"quest.anchor_mechanism") && chr.quest.anchor_mechanism == "anchor_lost")
					{
						//anchor_lost up! - is down
						PlaySound("PEOPLE\drill_water.wav");
						LAi_SetSitType(chr);

						LAi_QuestDelay("anchor_up_animation", 0.25);

						chr.quest.anchor_lost = "up";
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor_lost";

						Locations[FindLocation("wr_ships")].image = "";

						Locations[FindLocation("wr_ships")].locators_radius.box.box8 = 0.5;
						Locations[FindLocation("wr_ships")].locators_radius.box.box9 = 0.0001;

						LAi_QuestDelay("anchor_up_ships", 1.0);
					}
				}
				else
				{
					//pinions etc in here - you can't lift the anchor

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box', used for placing/taking pinions. (fire gun = wheel)

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladepinion_small")
						{
							if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
							{
								PlaySound("INTERFACE\damper_change.wav");
								LAi_QuestDelay("wheel_on_hub_already", 1.0);

								return;
							}
							else
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									//wheel on the other hub but blocking

									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_blocking", 1.0);

									return;
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "free")
								{
									//place small pinion!
									PlaySound("INTERFACE\pinion_place.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladepinion_small");
									EquipCharacterByItem(chr, "bladeX4");

									Locations[FindLocation("wr_ships")].models.always.l11 = "pinion_small_R";
									chr.quest.pinion_pos_right = "small";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}

								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "large")
								{
									//place small pinion & pick up large one!
									PlaySound("INTERFACE\pinion_place.wav");
									PlaySound("INTERFACE\pinion_take.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladepinion_small");
									GiveItem2Character(chr,"bladepinion_large");
									EquipCharacterByItem(chr, "bladepinion_large");

									Locations[FindLocation("wr_ships")].models.always.l11 = "pinion_small_R";
									chr.quest.pinion_pos_right = "small";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}
							}
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladepinion_large")
						{
							if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
							{
								PlaySound("INTERFACE\damper_change.wav");
								LAi_QuestDelay("wheel_on_hub_already", 1.0);

								return;
							}
							else
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									//wheel on the other hub but blocking

									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_blocking", 1.0);

									return;
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "free")
								{
									//place large pinion!
									PlaySound("INTERFACE\pinion_place.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladepinion_large");
									EquipCharacterByItem(chr, "bladeX4");

									Locations[FindLocation("wr_ships")].models.always.l11 = "pinion_large_R";
									chr.quest.pinion_pos_right = "large";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}

								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "small")
								{
									//place large pinion & pick up small one!
									PlaySound("INTERFACE\pinion_place.wav");
									PlaySound("INTERFACE\pinion_take.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladepinion_large");
									GiveItem2Character(chr,"bladepinion_small");
									EquipCharacterByItem(chr, "bladepinion_small");

									Locations[FindLocation("wr_ships")].models.always.l11 = "pinion_large_R";
									chr.quest.pinion_pos_right = "large";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}
							}
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
							{
								PlaySound("INTERFACE\damper_change.wav");
								LAi_QuestDelay("wheel_on_hub_already", 1.0);

								return;
							}
							else
							{
								if(CheckAttribute(chr,"quest.wheel_pos_left") && chr.quest.wheel_pos_left == "wheel")
								{
									//wheel on the other hub but blocking

									PlaySound("INTERFACE\damper_change.wav");
									LAi_QuestDelay("wheel_blocking", 1.0);

									return;
								}
							}
							else
							{
								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "small")
								{
									//pick up small one!
									PlaySound("INTERFACE\pinion_take.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									GiveItem2Character(chr,"bladepinion_small");
									EquipCharacterByItem(chr, "bladepinion_small");

									Locations[FindLocation("wr_ships")].models.always.l11 = "";
									chr.quest.pinion_pos_right = "free";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}

								if(CheckAttribute(chr,"quest.pinion_pos_right") && chr.quest.pinion_pos_right == "large")
								{
									//pick up large one!
									PlaySound("INTERFACE\pinion_take.wav");
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									GiveItem2Character(chr,"bladepinion_large");
									EquipCharacterByItem(chr, "bladepinion_large");

									Locations[FindLocation("wr_ships")].models.always.l11 = "";
									chr.quest.pinion_pos_right = "free";

									LAi_QuestDelay("at_mechanism_R", 0.5);
									return;
								}
							}
						}
					}
					else
					{
						if(CheckAttribute(chr,"quest.wheel_pos_right") && chr.quest.wheel_pos_right == "wheel")
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							if(!CheckCharacterItem(chr,"pistolhand")) GiveItem2Character(chr,"pistolhand");
							EquipCharacterByItem(chr, "pistolhand");//able to pick up wheel
						}

						chr.quest.deck_position = "mechanism_R";
						ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "stuck9");
						LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("stay_at_stuck9", 1.0);
					}
				}

				return;
			break;

			case "box10":
				if(LAi_IsFightMode(chr))
				{
					//second 'open box'
					SetModel(chr, "Pira4M_HTUS", chr.model.animation, chr.sex, stf(chr.model.height), true);
					chr.quest.elevatorG_status = "ropes_placed";
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(chr, "elevator_ropes");

					if(CheckAttribute(chr,"quest.anchor"))
					{
						if(chr.quest.anchor == "up")
						{
							Locations[FindLocation("wr_ships")].models.always.l7 = "ropes0";
							Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "ropes0";
							Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box1 = 1.5;//place ropes function
						}

						if(chr.quest.anchor == "down")
						{
							Locations[FindLocation("wr_ships")].models.always.l7 = "ropes2";
							Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "ropes2";
						}
					}

					LAi_QuestDelay("place_elevator_ropes", 1.0);
				}
				else
				{
					//first 'open box'
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					EquipCharacterByItem(chr, "bladeX4");
					LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], false);
					LAi_SetFightMode(chr, true);
				}

				return;
			break;

			case "box11":
				if(IsEquipCharacterByItem(chr, "bladeplank2") && IsEquipCharacterByItem(chr, "pistolplank2"))
				{
					PlaySound("PEOPLE\place_planks.wav");
					RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "pistolplank2");
					TakeItemFromCharacter(chr, "bladeplank2");

					chr.quest.plank_position = "deck";
					Locations[FindLocation("wr_ships")].models.always.l9 = "plank1";
					Locations[FindLocation("wr_gall_hold_first")].models.always.l2 = "plank1";
					Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 0.0001;//disable fall

					LAi_QuestDelay("place_planks_on_deck", 1.0);
				}
				else
				{
					if(CheckAttribute(chr,"quest.plank_position") && chr.quest.plank_position == "deck")
					{
						if(CheckAttribute(chr,"quest.deck_position") && chr.quest.deck_position == "fight_enabled")
						{
							PlaySound("OBJECTS\DUEL\man_attack1.wav");
							Logit(TranslateString("","No, they have nailed down the planks!"));
						}
						else
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr, "bladeplank2");
							GiveItem2Character(chr, "pistolplank2");
							EquipCharacterbyItem(chr, "bladeplank2");
							EquipCharacterbyItem(chr, "pistolplank2");

							chr.quest.plank_position = "picked_up";
							Locations[FindLocation("wr_ships")].models.always.l9 = "";
							Locations[FindLocation("wr_gall_hold_first")].models.always.l2 = "";
							Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 1.0;//enable fall

							LAi_QuestDelay("place_planks_on_deck", 1.0);//yes the same §
						}
					}
				}

				return;
			break;

			case "box12":
				PlaySound("INTERFACE\pinion_take.wav");
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr,"bladepinion_large");
				EquipCharacterByItem(chr, "bladepinion_large");
				Locations[FindLocation("wr_ships")].models.always.l15 = "";//large pinion picked up
				chr.quest.pistolwheel = "picked_up";
				Locations[FindLocation("wr_ships")].locators_radius.box.box12 = 0.001;

				LAi_QuestDelay("pick_up_pinion_large", 0.5);

				return;
			break;
		/*
		//moved to wr_gall_qdeck
			case "box13":
				if(CheckAttribute(chr,"quest.captains_door") && chr.quest.captains_door == "closed")
				{
					PlaySound("PEOPLE\wheel_open.wav");

					LAi_QuestDelay("open_captains_door", 4.0);
				}

				if(CheckAttribute(chr,"quest.captains_door") && chr.quest.captains_door == "open")
				{
					PlaySound("PEOPLE\wheel_close.wav");

					LAi_QuestDelay("close_captains_door", 3.5);
				}

				return;
			break;
		*/
			case "box14":
				//place anchor in prow

				if(CheckAttribute(chr,"quest.anchor_lost") && chr.quest.anchor_lost == "down")
				{
					PlaySound("PEOPLE\step_wood.wav");
					PlaySound("PEOPLE\step_wood.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "pickup_ropes");

					LAi_QuestDelay("jump_corvette", 0.5);
				}

				if(CheckAttribute(chr,"quest.anchor_lost") && chr.quest.anchor_lost == "up")
				{
					if(LAi_IsFightMode(chr))
					{
						//second 'open box'
						PlaySound("INTERFACE\button3.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladeanchor");
						GiveItem2Character(chr, "bladeX4");
						EquipCharacterByItem(chr, "bladeX4");

						chr.quest.anchor_mechanism = "complete";
						chr.quest.anchor_size = "small";
						Locations[FindLocation("wr_ships")].models.always.l5 = "anchor_small1";
						chr.quest.anchor = "up";
						Locations[FindLocation("wr_ships")].locators_radius.box.box15 = 0.0001;

						LAi_QuestDelay("anchor_placed_at_corvette", 0.5);
					}
					else
					{
						//first 'open box'
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeanchor");
						LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], false);
						LAi_SetFightMode(chr, true);
					}
				}

				return;
			break;

			case "box15":
				//climb up to place anchor at prow
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\step_wood.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "prow");

				LAi_QuestDelay("jump_corvette", 0.5);

				return;
			break;

			case "box16":
				//climb up for a jump down to corvette
				PlaySound("PEOPLE\step_wood.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "jump2");

				LAi_QuestDelay("abandon_galleon", 0.2);

				return;
			break;

			case "box17":
				//jump down to corvette
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "jump3");

				LAi_QuestDelay("abandon_galleon1", 1.0);

				return;
			break;
		/*
		//moved to wr_gall_qdeck
			case "box18":
				//move to steering wheel
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "steering");

				return;
			break;
		*/
			case "box19":
				//enter ships
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "reload2");
			break;

			case "box20":
				//leave ships
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "wr_ships", "reload", "reload3");
			break;

			case "box21":
				//climb up mast
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "reload16");

				if(CheckAttribute(chr,"quest.elevatorG_status") || CheckCharacterItem(chr,"elevator_ropes"))
				{
				}
				else LAi_QuestDelay("mast_so_what", 1.0);
			break;

			case "box22":
				//climb down mast
				PlaySound("PEOPLE\Jump.wav");
				ChangeCharacterAddressGroup(chr, "wr_ships", "goto", "reload15");
			break;

			case "box23":
				//start replacement for box 8 (anchor down)

				if(CheckAttribute(chr,"quest.anchor") && chr.quest.anchor == "up")
				{

					//anchor down! - mechanism not ready (do this before fixing with pinions etc)
					PlaySound("INTERFACE\shelf_cogs.wav");
					LAi_SetSitType(chr);

					chr.quest.anchor = "down";
					Locations[FindLocation("wr_ships")].models.always.l5 = "anchor0";		//down
					Locations[FindLocation("wr_ships")].models.always.l6 = "elevator&ropes_C2";	//air
					Locations[FindLocation("wr_ships")].locators_radius.reload.reload7 = 1.0;
					Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G2";//air

					Locations[FindLocation("wr_ships")].image = "";

					LAi_QuestDelay("anchor_down_ships", 1.0);
				}
				else
				{
					Logit(TranslateString("","Not much of a mechanism left here. The Pinions and the Wheel are all missing."));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");

					if(CheckAttribute(chr,"quest.qbook_pinions") && chr.quest.qbook_pinions == "done")
					{

					}
					else
					{
						chr.quest.qbook_pinions = "done";
						AddQuestRecord("Repair_the_anchor", "2");
					}
				}
			break;

			case "box24":
				//start replacement for box 9 (anchor up)

				Logit(TranslateString("","Not much of a mechanism left here. The Pinions and the Wheel are all missing."));
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");

				if(CheckAttribute(chr,"quest.qbook_pinions") && chr.quest.qbook_pinions == "done")
				{

				}
				else
				{
					chr.quest.qbook_pinions = "done";
					AddQuestRecord("Repair_the_anchor", "2");
				}
			break;

		}
		return;
	}

	if(Locations[locidx].id=="wr_gall_qdeck")
	{
		switch(chr.boxname)
		{
			case "box13":
				if(CheckAttribute(chr,"quest.captains_door") && chr.quest.captains_door == "closed")
				{
					PlaySound("PEOPLE\wheel_open.wav");

					LAi_QuestDelay("open_captains_door", 4.0);
				}

				if(CheckAttribute(chr,"quest.captains_door") && chr.quest.captains_door == "open")
				{
					PlaySound("PEOPLE\wheel_close.wav");

					LAi_QuestDelay("close_captains_door", 3.5);
				}

				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_corvette")
	{
		switch(chr.boxname)
		{
			case "box3":
				PlaySound("INTERFACE\bell_broken.wav");

				return;
			break;

			case "box5":
				//cannon up
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				return;
			break;

			case "box7":
				//ropes on quarterdeck
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				return;
			break;

			case "box8":
				//left position

				//anchor down! - is up, invisible else
				PlaySound("INTERFACE\shelf_cogs.wav");
				chr.quest.anchor = "down";
				Locations[FindLocation("wr_corvette")].models.always.l5 = "anchor0";		//down
				Locations[FindLocation("wr_corvette")].models.always.l6 = "elevator&ropes_C2";	//air
				Locations[FindLocation("wr_corvette")].locators_radius.reload.reload7 = 1.0;

				Locations[FindLocation("wr_corv_deck1")].reload.l5.disable = 0;
				Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G2";//air

				Locations[FindLocation("wr_corvette")].image = "";
				Locations[FindLocation("wr_corvette")].locators_radius.box.box8 = 0.0001;
				Locations[FindLocation("wr_corvette")].locators_radius.box.box9 = 0.5;

				LAi_QuestDelay("anchor_down_corvette", 1.0);

				return;
			break;

			case "box9":
				//right position

				//anchor up! - is down, invisible else
				PlaySound("PEOPLE\drill_water.wav");
				chr.quest.anchor = "up";
				Locations[FindLocation("wr_corvette")].models.always.l5 = "anchor_small1";
				Locations[FindLocation("wr_corvette")].models.always.l6 = "elevator&ropes_C1";	//deck
				Locations[FindLocation("wr_corvette")].locators_radius.reload.reload7 = 0.0001;

				Locations[FindLocation("wr_corv_deck1")].reload.l5.disable = 1;
				Locations[FindLocation("wr_corv_deck1")].models.always.l2 = "elevator&ropes_G1";//deck

				Locations[FindLocation("wr_corvette")].image = "";
				Locations[FindLocation("wr_corvette")].locators_radius.box.box8 = 0.5;
				Locations[FindLocation("wr_corvette")].locators_radius.box.box9 = 0.0001;

				LAi_QuestDelay("anchor_up_corvette", 1.0);

				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_cavern")
	{
		switch(chr.boxname)
		{
			case "box1":
				//locked chest hanging - door is open (start)
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_ground_open";

				LAi_QuestDelay("cavern_church_lock", 0.5);
				return;
			break;

			case "box2":
				//locked chest on ground - door is locked
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_air_closed";

				LAi_QuestDelay("cavern_church_unlock", 0.5);
				return;
			break;

			case "box3":
				//open chest on ground - door is locked
				if(CheckAttribute(chr,"quest.cavern_chestkey") && chr.quest.cavern_chestkey == "yes")
				{
					PlaySound("INTERFACE\key_lock.wav");

					Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_ground_closed";

					LAi_QuestDelay("cavern_chest_lock", 0.5);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I can't lock the chest. The key and the entire lock are missing!"));

					LAi_QuestDelay("cavern_key_gone", 1.0);
				}

				return;
			break;

			case "box4":
				//ready to place the chest on ground
				if(CheckCharacterItem(chr,"bladechest_red"))
				{
					if(!IsEquipCharacterByItem(chr, "bladechest_red"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterbyItem(chr, "bladechest_red");
					}

					LAi_SetFightMode(chr, true);
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_ground_open";

					LAi_QuestDelay("cavern_place_chest", 1.0);
				}
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_cannon_tower")
	{
		switch(chr.boxname)
		{
			case "box1":
				//gunpowder barrel
				PlaySound("AMBIENT\JAIL\jail_door2.wav");

				if(CheckAttribute(chr, "quest.wet_gp") && chr.quest.wet_gp == "yes")
				{
					TakeNItems(chr, "gunpowder", -100);

					LAi_QuestDelay("cannon_tower_dry_gp", 0.1);
				}

		 		LaunchItemsBox(&ar);
				return;
			break;

			case "box2":
				//R1: musket is up - door is locked (start)
				PlaySound("INTERFACE\lever_down.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "Imayak_l_JRH1";
				LAi_QuestDelay("blue_cavern_unlock", 0.5);
				return;
			break;

			case "box3":
				//R1: musket is down - door is open
				PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "Imayak_l_JRH";
				LAi_QuestDelay("blue_cavern_lock", 0.5);
				return;
			break;

			case "box4":
				//not used
			break;

			case "box5":
				//missing musket lever
				if(IsEquipCharacterByItem(chr, "pistolmket"))
				{
					PlaySound("OBJECTS\DUEL\reload1.wav");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					if(!CheckCharacterItem(chr,"bladeX4")) GiveItem2Character(chr, "bladeX4");
					EquipCharacterByItem(chr, "bladeX4");
					RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
					TakeItemFromCharacter(chr, "pistolmket");

					Locations[FindLocation(chr.location)].models.always.locators = "Imayak_l_JRH";

					LAi_QuestDelay("place_musket_lever", 1.0);
				}
				else
				{
					Logit(TranslateString("","One musket is missing!"));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				}
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_church_outside")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\Run_roof.wav");
				ChangeCharacterAddressGroup(chr, "wr_church_outside", "goto", "goto6");
			break;

			case "box2":
				PlaySound("PEOPLE\Run_roof.wav");
				ChangeCharacterAddressGroup(chr, "wr_church_outside", "goto", "goto7");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Tavern_storeroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_storeroom", 2.0);
			break;

			case "box2":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Tavern_storeroom", "box", "box3");
			break;

			case "box3":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Tavern_storeroom", "box", "box2");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Redmond_UsurerHouse")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_shop", 2.0);
			break;

			case "box2":
				if(!IsEquipCharacterByItem(chr, "bladepickaxe1")) EquipCharacterByItem(chr, "bladepickaxe1");
				LAi_SetFightMode(chr, true);

				LAi_QuestDelay("stick_on_floorhatch", 1.0);
			break;

			case "box3":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_UsurerHouse", "box", "box4");
			break;

			case "box4":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Redmond_UsurerHouse", "box", "box3");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				//ordinary chest
				PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 		LaunchItemsBox(&ar);
				return;
			break;


			case "box2":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_kitchen", 2.0);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_mine")
	{
		PlaySound("INTERFACE\key_unlock.wav");

		switch(chr.boxname)
		{
			case "box1":
				LAi_QuestDelay("unlock_tunnel_B", 2.0);
			break;

			case "box2":
				LAi_QuestDelay("unlock_tunnel_A", 2.0);
			break;

			case "box3":
				LAi_QuestDelay("unlock_tunnel_Z", 2.0);
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_animists")
	{
		switch(chr.boxname)
		{
			case "box1":
				//throne

				LAi_SetSitType(chr);

				if(Locations[FindLocation(chr.location)].models.always.locators == "scave_l_JRH_OFF")
				{
					PlaySound("AMBIENT\JAIL\sigh.wav");
					Logit(TranslateString("","No effect - the mechanism is not activated."));

					LAi_QuestDelay("temple_sit_function_OFF", 2.0);
				}
				else
				{
					PlaySound("INTERFACE\step_path.wav");

					LAi_QuestDelay("temple_mandala_turn", 0.3);
				}
			break;

			case "box2":
				//lever is down - function is on

				PlaySound("INTERFACE\lever_up.wav");

				Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_OFF";

				LAi_QuestDelay("temple_lever_OFF", 0.5);
				return;
			break;

			case "box3":
				//lever is up - function is off

				PlaySound("INTERFACE\lever_down.wav");

				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "1")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_ON1";
				}

				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "2")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_ON2";
				}

				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "3")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_ON3";
				}

				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "4")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_ON4";
				}

				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "5")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "scave_l_JRH_ON5";
				}

				LAi_QuestDelay("temple_lever_ON", 0.5);
				return;
			break;

			case "box4":
				if(CheckAttribute(chr,"quest.mine_bomb") && chr.quest.mine_bomb == "open")
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"bladeaxe5"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeaxe5")) EquipCharacterByItem(chr, "bladeaxe5");
						LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);//temp only
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("axe5_to_minebomb", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\door_locked2.wav");
						Logit(TranslateString("","What have they done here - nailed the cupboard?"));
						return;
					}
				}
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 		LaunchItemsBox(&ar);

				LAi_QuestDelay("from_box5_temple", 1.0);
			break;

			case "box6":
				//was cell2
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Logit(TranslateString("","No, I can't remove that thing whatever it is."));
				return;
			break;

			case "box7":
				//was cell4
				if(CheckCharacterItem(chr,"pistolspade"))
				{
					if(!IsEquipCharacterByItem(chr, "pistolspade")) EquipCharacterByItem(chr, "pistolspade");
					LAi_SetFightMode(chr, true);
				}
			break;

			case "box8":
				//to cell1
				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "2")
				{
					ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box9");
					PlaySound("INTERFACE\rusty.wav");
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box9":
				ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box8");
				PlaySound("INTERFACE\rusty.wav");
			break;

			case "box10":
				//to cell2
				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "3")
				{
					ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box11");
					PlaySound("INTERFACE\rusty.wav");
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box11":
				ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box10");
				PlaySound("INTERFACE\rusty.wav");
			break;

			case "box12":
				//to cell3
				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "4")
				{
					ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box13");
					PlaySound("INTERFACE\rusty.wav");
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box13":
				ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box12");
				PlaySound("INTERFACE\rusty.wav");
			break;

			case "box14":
				//to cell4
				if(CheckAttribute(chr,"quest.mandala_position") && chr.quest.mandala_position == "5")
				{
					ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box15");
					PlaySound("INTERFACE\rusty.wav");
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box15":
				ChangeCharacterAddressGroup(chr, "wr_animists", "box", "box14");
				PlaySound("INTERFACE\rusty.wav");
			break;

			case "box16":
				//to throne
				ChangeCharacterAddressGroup(chr, "wr_animists", "goto", "goto38");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box17":
				//to writing desk
				ChangeCharacterAddressGroup(chr, "wr_animists", "goto", "sit1");
				PlaySound("PEOPLE\creak2.wav");
			break;

		}
		return;
	}

	if(Locations[locidx].id=="wr_gibbet")
	{
		switch(chr.boxname)
		{
			case "box1":
				//barrel end

				if(Locations[FindLocation(chr.location)].models.always.locators == "Pri_l_gibbet_JRH")
				{
					ChangeCharacterAddressGroup(chr, "wr_gibbet", "goto", "right");
					LAi_SetSitType(chr);
					PlaySound("INTERFACE\bottle_molasses.wav");
					Locations[FindLocation("wr_gibbet")].models.always.locators = "Pri_l_gibbet_JRH1";//barrel up

					LAi_QuestDelay("empty_barrel_gibbet3", 1.0);//staytype after 1 sec
					LAi_QuestDelay("empty_barrel_gibbet2", 3.0);//creak sound after 3 sec
					LAi_QuestDelay("empty_barrel_gibbet", 4.0);//reload after 4 sec
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "Pri_l_gibbet_JRH2")//empty barrel no skeleton
				{
					if(CheckCharacterItem(chr,"bladehammer"))
					{
						EquipCharacterByItem(chr, "bladehammer");
						ChangeCharacterAddressGroup(chr, "wr_gibbet", "goto", "right");
						LAi_SetFightMode(chr, true);
						LAi_QuestDelay("hammer_on_barrel", 1.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						Logit(TranslateString("","That barrel could be useful but I can't remove it with my bare hands from the gibbet."));
					}
				}
			break;

			case "box2":
				//skeleton end

				if(Locations[FindLocation(chr.location)].models.always.locators == "Pri_l_gibbet_JRH1")//barrel up
				{
					Logit(TranslateString("","Maybe I should cut him down."));
					ChangeCharacterAddressGroup(chr, "wr_gibbet", "goto", "goto5");//test 1 step back
					LAi_SetFightMode(chr, true);
					ChangeCharacterAddressGroup(CharacterFromID("wr_hanged"), "wr_gibbet", "goto", "goto3");//reset

					LAi_QuestDelay("cut_down_hanged", 1.0);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "Pri_l_gibbet_JRH3")//horizontal, up
				{
					if(CheckCharacterItem(chr,"bladeaxe4"))
					{
						EquipCharacterByItem(chr, "bladeaxe4");
						ChangeCharacterAddressGroup(chr, "wr_gibbet", "goto", "goto5");//test 1 step back
						LAi_SetFightMode(chr, true);
						ChangeCharacterAddressGroup(CharacterFromID("wr_hanged"), "wr_gibbet", "goto", "goto3");//reset

						LAi_QuestDelay("axe_on_skeleton", 1.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						Logit(TranslateString("","The corpse is too heavy walking around with."));
					}
				}
			break;

			case "box3":
				//poles in the middle
				if(CheckCharacterItem(chr,"bladesaw"))
				{
					EquipCharacterByItem(chr, "bladesaw");
					ChangeCharacterAddressGroup(chr, "wr_gibbet", "goto", "saw");
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("saw_on_gibbet", 1.0);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					Logit(TranslateString("","Maybe these poles and planks could be of some help."));
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_food_supply")
	{
		switch(chr.boxname)
		{
			case "box1":
				//filled barrel
				if(CheckCharacterItem(chr,"bladebarrel"))
				{
					Logit(TranslateString("","My barrel is filled with rum!"));
					PlaySound("INTERFACE\rum_barrel_empty.wav");
					PlaySound("INTERFACE\rum_barrel_filled.wav");

					LAi_QuestDelay("rum_food_supply", 2.0);
				}
				else
				{
					//empty barrel
					if(CheckCharacterItem(chr,"bladebarrel2"))
					{
						PlaySound("INTERFACE\rum_barrel_empty.wav");
						PlaySound("INTERFACE\bottle_molasses.wav");
						chr.quest.prison_barrel = "filled";

						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladebarrel2");
						GiveItem2Character(chr, "bladebarrel");
						EquipCharacterByItem(chr, "bladebarrel");

						LAi_QuestDelay("filling_rum_food_supply", 4.0);
					}
				}
				else
				{
					Logit(TranslateString("","There sure is a lot of rum stacked in here"));
					PlaySound("INTERFACE\rum_barrel_empty.wav");
					PlaySound("INTERFACE\rum_barrel_filled.wav");

					LAi_QuestDelay("rum_food_supply", 2.0);
				}
			break;

			case "box7":
				//pick up food chest (and drop medicine chest, bandages or sack if you got any of those)

				if(CheckCharacterItem(chr,"rolls_of_bandages")) chr.quest.cellar_bandages = "placed";
				if(CheckCharacterItem(chr,"leeches")) chr.quest.cellar_leeches = "placed";

				if(CheckCharacterItem(chr,"meds1"))
				{
					chr.quest.cellar_meds1 = "placed";
					TakeItemFromCharacter(chr, "meds1");
				}
				if(CheckCharacterItem(chr,"meds2"))
				{
					chr.quest.cellar_meds2 = "placed";
					TakeItemFromCharacter(chr, "meds2");
				}
				if(CheckCharacterItem(chr,"meds3"))
				{
					chr.quest.cellar_meds3 = "placed";
					TakeItemFromCharacter(chr, "meds3");
				}
				if(CheckCharacterItem(chr,"Potion3"))
				{
					chr.quest.cellar_Potion3 = "placed";
					TakeItemFromCharacter(chr, "Potion3");
				}
				if(CheckCharacterItem(chr,"pistolgas"))
				{
					chr.quest.cellar_pistolgas = "placed";
					TakeItemFromCharacter(chr, "pistolgas");
				}
				if(CheckCharacterItem(chr,"mercury_bottles"))
				{
					chr.quest.cellar_mercury = "placed";
					TakeItemFromCharacter(chr, "mercury_bottles");
				}
				if(CheckCharacterItem(chr,"empty_bottless"))
				{
					chr.quest.cellar_emptyb = "placed";
					TakeItemFromCharacter(chr, "empty_bottles");
				}
				if(CheckCharacterItem(chr,"mdchest_B2"))
				{
					chr.quest.cellar_md_B2 = "placed";
					TakeItemFromCharacter(chr, "mdchest_B2");
				}
				if(CheckCharacterItem(chr,"mdchest_B3"))
				{
					chr.quest.cellar_md_B3 = "placed";
					TakeItemFromCharacter(chr, "mdchest_B3");
				}

				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);

				if(CheckCharacterItem(chr,"pistolmdchest_F2B"))
				{
					chr.quest.med_chest = "F2B_placed";
					Log_SetStringToLog(XI_ConvertString("You give item"));
					PlaySound("INTERFACE\important_item.wav");
					TakeItemFromCharacter(chr, "pistolmdchest_F2A");
					TakeItemFromCharacter(chr, "pistolmdchest_F2B");

					Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_M";
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F2B_C"))
					{
						chr.quest.med_chest = "F2B_C_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F2A_C");
						TakeItemFromCharacter(chr, "pistolmdchest_F2B_C");
						TakeItemFromCharacter(chr, "rolls_of_bandages");

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MC";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F2B_S"))
					{
						chr.quest.med_chest = "F2B_S_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F2A_S");
						TakeItemFromCharacter(chr, "pistolmdchest_F2B_S");
						TakeItemFromCharacter(chr, "leeches");	//if you got any

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MS";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F2B_CS"))
					{
						chr.quest.med_chest = "F2B_CS_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F2A_CS");
						TakeItemFromCharacter(chr, "pistolmdchest_F2B_CS");
						TakeItemFromCharacter(chr, "rolls_of_bandages");
						TakeItemFromCharacter(chr, "leeches");	//if you got any

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MCS";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F3B"))
					{
						chr.quest.med_chest = "F3B_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F3A");
						TakeItemFromCharacter(chr, "pistolmdchest_F3B");

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_M";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F3B_C"))
					{
						chr.quest.med_chest = "F3B_C_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F3A_C");
						TakeItemFromCharacter(chr, "pistolmdchest_F3B_C");
						TakeItemFromCharacter(chr, "rolls_of_bandages");

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MC";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F3B_S"))
					{
						chr.quest.med_chest = "F3B_S_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F3A_S");
						TakeItemFromCharacter(chr, "pistolmdchest_F3B_S");
						TakeItemFromCharacter(chr, "leeches");	//if you got any

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MS";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdchest_F3B_CS"))
					{
						chr.quest.med_chest = "F3B_CS_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdchest_F3A_CS");
						TakeItemFromCharacter(chr, "pistolmdchest_F3B_CS");
						TakeItemFromCharacter(chr, "rolls_of_bandages");
						TakeItemFromCharacter(chr, "leeches");	//if you got any

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_MCS";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdcloth"))
					{
						chr.quest.med_chest = "cloth_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdcloth");

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_C";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdsack"))
					{
						chr.quest.med_chest = "sack_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdsack");

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_S";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolmdclothsack"))
					{
						chr.quest.med_chest = "clothsack_placed";
						Log_SetStringToLog(XI_ConvertString("You give item"));
						PlaySound("INTERFACE\important_item.wav");
						TakeItemFromCharacter(chr, "pistolmdclothsack");
						TakeItemFromCharacter(chr, "leeches");	//if you got any

						Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH2_CS";
					}
				}
				else
				{
					Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH";//no med items
				}


				LAi_QuestDelay("pickup_foodchest_place_mdchest", 0.5);
			break;

			case "box2":
				//pick up medicine chest - don't place anything

			    if(CheckAttribute(chr,"quest.med_monkey_food") && chr.quest.med_monkey_food == "done")
			    {
				Locations[FindLocation("wr_food_supply")].models.always.locators = "store03_locators_JRH";

				LAi_QuestDelay("pickup_mdchest_place_nothing", 0.5);
			    }
			    else
			    {
				Logit(TranslateString("","No, I can't carry the medicine stuff too."));
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			    }
			break;

			case "box3":
				//meat
				if(CheckCharacterItem(chr,"key15"))
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box4":
				//ale
				if(CheckCharacterItem(chr,"key15"))
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box5":
				//bread
				if(CheckCharacterItem(chr,"key15"))
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box6":
				//fish
				if(CheckCharacterItem(chr,"key15"))
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box10":
				if(CheckAttribute(chr,"quest.mine_enabled") && chr.quest.mine_enabled == "yes")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "wr_food_supply", "box", "box11");
				}
				else PlaySound("INTERFACE\knock.wav");
				return;
			break;

			case "box11":
				if(CheckAttribute(chr,"quest.mine_enabled") && chr.quest.mine_enabled == "yes")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "wr_food_supply", "box", "box10");
				}
				else PlaySound("INTERFACE\knock.wav");
				return;
			break;

			case "box12":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(chr, "wr_food_supply", "goto", "goto2");
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_prison")
	{
		switch(chr.boxname)
		{
			case "box1":
				//steplock A outer cell
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);

				if(CheckAttribute(chr,"quest.prison_barrel") && chr.quest.prison_barrel == "empty")
				{
					GiveItem2Character(chr, "bladebarrel2");
					EquipCharacterByItem(chr, "bladebarrel2");

					//Log_SetStringToLog("itemlogic_empty");
					chr.quest.prison_barrel2 = "loop_off";//to stop ongoing loop
					chr.quest.prison_barrel3 = "pick_up";//to get locatorset ONE time

					if(CheckAttribute(chr,"quest.keybox13_prison") && chr.quest.keybox13_prison == "within_reach")
					{
						Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH00";//open floor hatch
					}
					else
					{
						Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH1";//open floor hatch
					}

					Locations[FindLocation("wr_prison")].image = "";
					DoQuestReloadToLocation("wr_prison", "goto", "goto2", "steplock_A_prison8");	//dead end
															//another way into the loop again
				}
				else
				{
					if(CheckAttribute(chr,"quest.prison_skull") && chr.quest.prison_skull == "placed")
					{
						GiveItem2Character(chr, "bladebarrel");
						EquipCharacterByItem(chr, "bladebarrel");

						//Log_SetStringToLog("itemlogic_else_is_filled + skull placed");
						Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH7";//skull,open floor hatch without barrel

						Locations[FindLocation("wr_prison")].image = "";
						//DoQuestReloadToLocation("wr_prison", "goto", "goto2", "steplock_A_prison4");//ok but very late arrive rogers

						DoQuestReloadToLocation("wr_prison", "goto", "goto2", "steplock_A_prison4_rogers");//try this instead
					}
					else
					{
						GiveItem2Character(chr, "bladebarrel");
						EquipCharacterByItem(chr, "bladebarrel");
						chr.quest.steplock_A_prison = "something_else";
						//try to avoid twice on goto3 to close hatch, when picked up filled barrel

						Log_SetStringToLog("itemlogic_else_is_filled");

						locations[FindLocation("wr_dungeon3_right")].reload.l1.disable = 1;//ladder up to inner cell

						if(CheckAttribute(chr,"quest.keybox13_prison") && chr.quest.keybox13_prison == "within_reach")
						{
							Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH00";//open floor hatch
						}
						else
						{
							Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH1";//open floor hatch
						}

						Locations[FindLocation("wr_prison")].image = "";
						DoQuestReloadToLocation("wr_prison", "goto", "goto2", "steplock_A_prison4");//into the loop again
					}
				}
			break;

			case "box2":
				//steplock B inner cell

				if(CheckAttribute(chr,"quest.prison_barrel4") && chr.quest.prison_barrel4 == "plank_placed_on_wall")
				{
					if(CheckCharacterItem(chr,"bladebarrel"))
					{
						//PUT DOWN BARREL
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladebarrel");
						EquipcharacterByItem(chr, "bladeA11");
						Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH9";//skull, barrel on steplock B, floor & wall open, plank on wall

						Locations[FindLocation("wr_prison")].image = "";
						DoQuestReloadToLocation("wr_prison", "goto", "goto4", "loading_image_back_prison");
					}
					else
					{
						//PICK UP BARREL
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr, "bladebarrel");
						EquipCharacterByItem(chr, "bladebarrel");
						Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH10";//skull, both open, plank on wall but NO NARREL

						Locations[FindLocation("wr_prison")].image = "";
						DoQuestReloadToLocation("wr_prison", "goto", "goto4", "loading_image_back_prison");
					}
				}
				else
				{
					//PICK UP BARREL
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					GiveItem2Character(chr, "bladebarrel");
					EquipCharacterByItem(chr, "bladebarrel");
					chr.quest.steplock_B_prison = "something_else";
					chr.quest.prison_barrel4 = "wait_with_wall_plank";

					//Log_SetStringToLog("itemlogic");
					Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH7_A";//skull, open floor & wall, no barrel

					chr.quest.swimtime = "no";

					if(Locations[FindLocation("wr_dungeon3_left")].models.always.locators == "d03_l_JRH_L3")
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L1";

					if(Locations[FindLocation("wr_dungeon3_left")].models.always.locators == "d03_l_JRH_L4")
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L4";

					Locations[FindLocation("wr_mine")].reload.l5.disable = 1;		//tunnelA
					Locations[FindLocation("wr_dungeon3_left")].environment.sea = "false";	//tunnelA
					Locations[FindLocation("wr_dungeon3_left")].environment.weather = "false";

					SetCurrentTime(11.00, 0);
					SetNextWeather("Clear");
					chr.quest.JRH_rain = "Mine Fog 1";

					ChangeCharacterAddressGroup(CharacterFromID("wr_boc5"), "wr_mine", "goto", "goto3");
					LAi_SetStayType(CharacterFromID("wr_boc5"));
					ChangeCharacterAddressGroup(CharacterFromID("Powdermonkey"), "none", "", "");

					Locations[FindLocation("wr_prison")].image = "";
					DoQuestReloadToLocation("wr_prison", "goto", "goto4", "steplock_B_prison4");//into the loop again
				}
			break;

			case "box3":
				//reach key-box13 from outer cell with pickaxe

				if(CheckCharacterItem(chr,"bladepickaxe2"))
				{
					EquipCharacterByItem(chr, "bladepickaxe2");
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("pickaxe2_on_keybox", 1.0);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","I need something with a hook to get those boxes."));

					if(CheckAttribute(chr,"quest.hook_to_keyboxes") && chr.quest.hook_to_keyboxes == "done")
					{

					}
					else
					{
						chr.quest.hook_to_keyboxes = "done";
						AddQuestRecord("Open_the_cell", "2");
					}
				}
			break;

			case "box4":
				//placing plank on wall standing on open floor hatch

				LAi_SetFightMode(chr, true);
				chr.quest.prison_barrel4 = "plank_placed_on_wall";
				Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH9";//skull, barrel on steplock B, floor & wall open, plank on wall

				LAi_QuestDelay("place_plank_on_wall", 1.0);
			break;

			case "box5":
				//placing barrel under open wall hatch

				if(CheckCharacterItem(chr,"bladebarrel"))
				{
					//PUT DOWN BARREL
					locations[FindLocation(chr.location)].box6.items.jewelry5 = 1;
					locations[FindLocation(chr.location)].box6.items.pistol206 = 1;
					locations[FindLocation(chr.location)].box6.items.blue_uniform = 1;

					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladebarrel");

					if(CheckCharacterItem(chr,"bladeA11"))
					{
						EquipcharacterByItem(chr, "bladeA11");
					}
					else EquipcharacterByItem(chr, "bladeX4");

					Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH11";//skull, barrel on steplock B, floor & wall open, plank on wall

					Locations[FindLocation("wr_prison")].image = "";
					DoQuestReloadToLocation("wr_prison", "goto", "goto30", "loading_image_back_prison");
				}
			break;

			case "box6":
				if(CheckAttribute(chr,"quest.prison_barrel4") && chr.quest.prison_barrel4 == "ready_to_remove_plank_from_wall")
				{
					//remove plank from wall

					PlaySound("PEOPLE\wood1.wav");

					LAi_QuestDelay("remove_plank_from_wall1", 0.1);
				}
				else
				{
					//blue chest: ordinary box procedure

					PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 			LaunchItemsBox(&ar);
					LAi_QuestDelay("get_all_3_items", 0.1);
					return;
				}
			break;

			case "box7":
				//place plank on floor

				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				TakeItemFromCharacter(chr, "bladeplank");
				EquipcharacterByItem(chr, "bladeA11");
				Locations[FindLocation("wr_prison")].models.always.locators = "Pri_l_JRH14";//floor closed, plank on floor

				Locations[FindLocation("wr_prison")].image = "";
				DoQuestReloadToLocation("wr_prison", "goto", "goto18", "place_plank_on_floor");
			break;

			case "box8":
				//cell door

				if(CheckAttribute(chr,"quest.prison_celldoor") && chr.quest.prison_celldoor == "open")
				{
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "wr_prison", "box", "box9");
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box9":
				//cell door

				if(CheckAttribute(chr,"quest.prison_celldoor") && chr.quest.prison_celldoor == "open")
				{
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "wr_prison", "box", "box8");
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box10":
				//step on open hatch
				if(CheckCharacterItem(chr,"bladeplank"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeplank"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE );
						EquipCharacterByItem(chr, "bladeplank");
					}
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box11", 0.0001);
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box4", 0.5);

					Locations[FindLocation("wr_prison")].locators_radius.box.box11 = 0.0001;
					Locations[FindLocation("wr_prison")].locators_radius.box.box4 = 0.5;
				}
				else
				{
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box4", 0.0001);
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box11", 0.5);

					Locations[FindLocation("wr_prison")].locators_radius.box.box4 = 0.0001;
					Locations[FindLocation("wr_prison")].locators_radius.box.box11 = 0.5;
				}

				PlaySound("PEOPLE\recoil.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "wr_prison", "goto", "goto10");
			break;

			case "box11":
				//jump down from open hatch

				PlaySound("PEOPLE\Jump.wav");
				ChangeCharacterAddressGroup(chr, "wr_prison", "goto", "goto11");
			break;

			case "box12":
				//step on barrel

				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "wr_prison", "goto", "goto8");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_mine_control")
	{
		switch(chr.boxname)
		{
			case "box1":
				//lever is up - system1 (mine) is off
				PlaySound("INTERFACE\lever_down.wav");

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1";
					LAi_QuestDelay("mine_lights_1", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_G" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_G")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1_G";
					LAi_QuestDelay("mine_lights_1G", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_F" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_F")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1_F";
					Locations[FindLocation("wr_mine")].models.always.locators = "mine_l_JRH1";
					Locations[FindLocation("wr_dungeon4_main")].models.always.locators = "d04_l_JRH_OFF1";

					Locations[FindLocation("wr_dungeon3_right")].models.always.locators = "d03_l_JRH_R1";
					if(CheckAttribute(chr,"quest.swimtime") && chr.quest.swimtime == "yes")
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L3";
					}
					else
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L1";
					}

					LAi_QuestDelay("mine_lights_1F", 0.5);
				}
			break;

			case "box2":
				//lever is up - system2 (tunnelA) is off
				PlaySound("INTERFACE\lever_down.wav");

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2";
					LAi_QuestDelay("mine_lights_2", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_G" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_G")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2_G";
					LAi_QuestDelay("mine_lights_2G", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_F" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_F")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2_F";
					Locations[FindLocation("wr_mine")].models.always.locators = "mine_l_JRH2";
					Locations[FindLocation("wr_dungeon4_main")].models.always.locators = "d04_l_JRH_OFF1";

					Locations[FindLocation("wr_dungeon3_right")].models.always.locators = "d03_l_JRH_R2";
					if(CheckAttribute(chr,"quest.swimtime") && chr.quest.swimtime == "yes")
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L4";
					}
					else
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L2";
					}

					LAi_QuestDelay("mine_lights_2F", 0.5);
				}
			break;

			case "box3":
				//lever is up - system3 (tunnelZ) is off
				PlaySound("INTERFACE\lever_down.wav");

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3";
					LAi_QuestDelay("mine_lights_3", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_G" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_G")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3_G";
					LAi_QuestDelay("mine_lights_3G", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_F" || Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_F")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3_F";
					Locations[FindLocation("wr_mine")].models.always.locators = "mine_l_JRH3";
					Locations[FindLocation("wr_dungeon4_main")].models.always.locators = "d04_l_JRH_ON1";

					Locations[FindLocation("wr_dungeon3_right")].models.always.locators = "d03_l_JRH_R1";
					if(CheckAttribute(chr,"quest.swimtime") && chr.quest.swimtime == "yes")
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L3";
					}
					else
					{
						Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L1";
					}

					LAi_QuestDelay("mine_lights_3F", 0.5);
				}
			break;

			case "box4":
				//lever is down - gas OR fire

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_G")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1";
					LAi_QuestDelay("mine_lights_gas_off", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_G")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2";
					LAi_QuestDelay("mine_lights_gas_off", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_G")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3";
					LAi_QuestDelay("mine_lights_gas_off", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1_F")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1";
					LAi_QuestDelay("mine_lights_fire_off", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2_F")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2";
					LAi_QuestDelay("mine_lights_fire_off", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3_F")
				{
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3";
					LAi_QuestDelay("mine_lights_fire_off", 0.5);
				}
			break;

			case "box5":
				//lever is up - no gas or fire

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH1")
				{
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH1_G";
					LAi_QuestDelay("mine_lights_gas_on", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH2")
				{
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH2_G";
					LAi_QuestDelay("mine_lights_gas_on", 0.5);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "d02_l_JRH3")
				{
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation(chr.location)].models.always.locators = "d02_l_JRH3_G";
					LAi_QuestDelay("mine_lights_gas_on", 0.5);
				}
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Redmond_Town_01")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			//lever is up - bridge is unvisible (start)
			PlaySound("INTERFACE\lever_down.wav");
			Locations[FindLocation(chr.location)].models.always.locators = "Red01_l_JRH4";

			LAi_QuestDelay("bridge_visible", 1.0);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
	    	{
			//lever is down - bridge is visible (on the way back ONLY!)
			PlaySound("INTERFACE\lever_up.wav");
			Locations[FindLocation(chr.location)].models.always.locators = "Red01_l_JRH_back_rope";
			chr.quest.bridge_check = "gone";

			LAi_QuestDelay("bridge_invisible", 1.0);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box4")
	    	{
			PlaySound("OBJECTS\DUEL\man_attack1.wav");
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar2");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box5")
	    	{
			PlaySound("OBJECTS\VOICES\DEAD\male\dead3.wav");
			PlaySound("OBJECTS\VOICES\DEAD\male\dead3.wav");
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar3");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box6")
	    	{
			chr.quest.high_roof_check = "ok";
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar9");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box7")
	    	{
			PlaySound("OBJECTS\DUEL\man_hit4.wav");
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar10");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box8")
	    	{
			PlaySound("PEOPLE\run_wood.wav");

			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar11");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box9")
	    	{
			PlaySound("OBJECTS\VOICES\DEAD\male\dead3.wav");
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar12");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box10")
	    	{
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "cat_burglar15");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box11")
	    	{
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "goto63");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box12")
	    	{
			ChangeCharacterAddressGroup(chr, "Redmond_Town_01", "goto", "goto62");
			return;
		}

	}

	if(Locations[locidx].id=="Redmond_shipyard")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1")
	    	{
			PlaySound("INTERFACE\locked_window.wav");
			LAi_QuestDelay("shipyard_loft3", 1.0);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			PlaySound("INTERFACE\locked_window.wav");
			LAi_QuestDelay("shipyard_loft5", 1.0);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
	    	{
			PlaySound("AMBIENT\JAIL\jail_door2.wav");
			LaunchItemsBox(&ar);
			return;
		}
	}

	if(Locations[locidx].id=="wr_gunroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				//wheel on water tank

				if(CheckAttribute(chr,"quest.wheel_check") && chr.quest.wheel_check == "0")
				{
					chr.quest.wheel_check = "1";
					//chr.quest.4checks = sti(chr.quest.3checks) + 1;//not used yet
				}

				if(CheckAttribute(chr,"quest.rum_phase") && chr.quest.rum_phase == "2") return;
				if(CheckAttribute(chr,"quest.rum_phase") && chr.quest.rum_phase == "3") return;

				PlaySound("INTERFACE\rum_wheel.wav");
				PlaySound("INTERFACE\rusty.wav");

				if(CheckAttribute(chr,"quest.rum_water") && chr.quest.rum_water == "filled")
				{
					if(CheckAttribute(chr,"quest.rum_wheel") && chr.quest.rum_wheel == "on")
					{
						chr.quest.rum_wheel = "off";
						LAi_QuestDelay("wheel_water", 0.1);
					}
					else
					{
						chr.quest.rum_wheel = "on";
						LAi_QuestDelay("wheel_water", 3.0);
					}
				}

				Logit(TranslateString("","Water valve"));
				return;
			break;

			case "box2":
				//open water tank

				if(CheckAttribute(chr,"quest.water_check") && chr.quest.water_check == "0")
				{
					chr.quest.water_check = "1";
					//chr.quest.4checks = sti(chr.quest.3checks) + 1;//not used yet
				}

				PlaySound("AMBIENT\TAVERN\open_bottle.wav");
				Logit(TranslateString("","Water tank"));

				LAi_QuestDelay("water_tank", 1.0);
				return;
			break;

			case "box3":
				//molasses tank

				if(CheckAttribute(chr,"quest.molasses_check") && chr.quest.molasses_check == "0")
				{
					chr.quest.molasses_check = "1";
					//chr.quest.4checks = sti(chr.quest.3checks) + 1;//not used yet

					SetQuestHeader("Distiller");
					AddQuestRecord("Distiller", "1");
					//DeleteQuestHeader("Woodes_Rogers_reward_4");	//skip it earlier: when "Librarian" is started
				}

				if(CheckAttribute(chr,"quest.rum_molasses") && chr.quest.rum_molasses == "filled")
				{
					PlaySound("INTERFACE\rum_barrel_filled.wav");
					PlaySound("INTERFACE\rum_barrel_empty.wav");
				}

			//........................................................................................

				if(CheckAttribute(chr,"quest.rum_molasses") && chr.quest.rum_molasses == "bladebottle")
				{
					if(CheckCharacterItem(chr,"pistolbottlew4"))
					{
						TakeItemFromCharacter(chr, "pistolbottlew4");
						EquipCharacterByItem(chr, "pistol204");
						PlaySound("INTERFACE\bottle_molasses.wav");

						chr.quest.rum_molasses = "filled";
						LAi_QuestDelay("bartender_arrives", 4.0);	//quest continues ...
					}
					else
					{
						PlaySound("INTERFACE\rum_barrel_empty.wav");
						if(CheckAttribute(chr,"quest.rum_phase") && chr.quest.rum_phase != "3")
						PlaySound("INTERFACE\took_item.wav");
					}
				}

				if(CheckAttribute(chr,"quest.rum_molasses") && chr.quest.rum_molasses == "pistolbottle")
				{
					if(CheckCharacterItem(chr,"bladebottlew4"))
					{
						TakeItemFromCharacter(chr, "bladebottlew4");
						EquipCharacterByItem(chr, "bladeA11");
						PlaySound("INTERFACE\bottle_molasses.wav");

						chr.quest.rum_molasses = "filled";
						LAi_QuestDelay("bartender_arrives", 4.0);	//quest continues ...
					}
					else
					{
						PlaySound("INTERFACE\rum_barrel_empty.wav");
						if(CheckAttribute(chr,"quest.rum_phase") && chr.quest.rum_phase != "3")
						PlaySound("INTERFACE\took_item.wav");
					}
				}

				if(CheckAttribute(chr,"quest.rum_molasses") && chr.quest.rum_molasses == "empty")
				{
					if(CheckCharacterItem(chr,"bladebottlew4") && CheckCharacterItem(chr,"pistolbottlew4") )
					{
						TakeItemFromCharacter(chr, "bladebottlew4");
						EquipCharacterByItem(chr, "bladeA11");
						PlaySound("INTERFACE\bottle_molasses.wav");
						chr.quest.rum_molasses = "bladebottle";
					}
					else
					{
						if(CheckCharacterItem(chr,"bladebottlew4"))
						{
							TakeItemFromCharacter(chr, "bladebottlew4");
							EquipCharacterByItem(chr, "bladeA11");
							PlaySound("INTERFACE\bottle_molasses.wav");
							chr.quest.rum_molasses = "bladebottle";
						}
					}
					else
					{
						if(CheckCharacterItem(chr,"pistolbottlew4"))
						{
							TakeItemFromCharacter(chr, "pistolbottlew4");
							EquipCharacterByItem(chr, "pistol204");
							PlaySound("INTERFACE\bottle_molasses.wav");
							chr.quest.rum_molasses = "pistolbottle";
						}
					}
					else
					{
						PlaySound("INTERFACE\rum_barrel_empty.wav");

						if(CheckAttribute(chr,"quest.rum_phase") )
						{
							if(chr.quest.rum_phase == "3" || chr.quest.rum_phase == "4")
							{
								//no key sound please
							}
							else PlaySound("INTERFACE\took_item.wav");
						}
					}
				}

				Logit(TranslateString("","Molasses tank"));
				return;
			break;

			case "box4":
				//damper

				if(CheckAttribute(chr,"quest.damper_check") && chr.quest.damper_check == "0")
				{
					chr.quest.damper_check = "1";
					//chr.quest.4checks = sti(chr.quest.3checks) + 1;//not used yet
				}

				if(CheckAttribute(chr,"quest.rum_damper") && chr.quest.rum_damper == "closed")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.rum_damper = "half_open";
					chr.quest.rum_fire = "unlit";

					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH1";

					LAi_QuestDelay("damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.rum_damper") && chr.quest.rum_damper == "half_open")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.rum_damper = "open";

					if(CheckAttribute(chr,"quest.rum_fire") && chr.quest.rum_fire == "unlit")
					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH2";

					if(CheckAttribute(chr,"quest.rum_fire") && chr.quest.rum_fire == "lit")
					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH2_F";

					LAi_QuestDelay("damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.rum_damper") && chr.quest.rum_damper == "open")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.rum_damper = "half_closed";

					if(CheckAttribute(chr,"quest.rum_fire") && chr.quest.rum_fire == "unlit")
					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH1";

					if(CheckAttribute(chr,"quest.rum_fire") && chr.quest.rum_fire == "lit")
					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH1_F";

					LAi_QuestDelay("damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.rum_damper") && chr.quest.rum_damper == "half_closed")
				{
					PlaySound("INTERFACE\damper_close.wav");
					chr.quest.rum_damper = "closed";

					Locations[FindLocation(chr.location)].models.always.locators = "tavern02_locators_JRH0";

					LAi_QuestDelay("damper", 0.5);
					return;
				}
			break;

			case "box5":
				//climb to water tank

				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(chr, "wr_gunroom", "goto", "reload1");
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_study")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box2":
				//treasure tales
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book36") && chr.quest.wr_book36 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book36") )
					{
						LAi_QuestDelay("book36and27_check", 0.1);
						LAi_QuestDelay("book36_check", 0.1);
					}
				}
				return;
			break;

			case "box3":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box4":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box5":
				if(CheckAttribute(chr,"quest.study_chest") && chr.quest.study_chest == "open")
				{
					//once opened stays open
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key10"))
					{
						PlaySound("INTERFACE\key_unlock.wav");
						chr.quest.study_chest = "open";
						TakeItemFromCharacter(chr, "key10");
						LaunchItemsBox(&ar);
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box6":
				LaunchItemsBox(&ar);
				return;
			break;

			case "box7":
				//locked counter with 4 levers

				if(CheckAttribute(chr,"quest.study_counter") && chr.quest.study_counter == "open")
				{
					LaunchItemsBox(&ar);
				}
				else
				{
					if(CheckCharacterItem(chr,"key17"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.study_counter = "open";
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box8":
				if(GetAttribute(chr, "study_levers") == "disabled") {return;}

				//lever2 is up or missing (1 from left)
				if(CheckAttribute(chr,"quest.study_lever2") && chr.quest.study_lever2 == "up")
				{
					if(CheckAttribute(chr,"quest.study_lever1") && chr.quest.study_lever1 == "down")
					{
						//wall is gone
						PlaySound("INTERFACE\lever_down.wav");
						chr.quest.study_lever2 = "down";
						Locations[FindLocation("wr_study")].models.always.l2 = "lever2_down";
						Locations[FindLocation("wr_study")].models.always.l5 = "bars_up";
						Locations[FindLocation("wr_study")].locators_radius.box.box8 = 0.0001;
						Locations[FindLocation("wr_study")].locators_radius.box.box12 = 0.5;

						LAi_QuestDelay("study_bars_up", 0.5);
					}
					else
					{
						if(chr.quest.study_lever1 == "up" && chr.quest.study_lever3 == "up" && chr.quest.study_lever4 == "up")
						{
   							PlaySound("INTERFACE\lever_stuck.wav");
							return;
						}
						else
						{
							PlaySound("INTERFACE\step_reset.wav");
							chr.quest.study_position = "8";
							LAi_QuestDelay("study_levers_reset1", 1.0);
							return;
						}
					}
				}

				if(CheckAttribute(chr,"quest.study_lever2") && chr.quest.study_lever2 == "missing")
				{
					if(CheckCharacterItem(chr,"bladelever"))
					{
						chr.study_levers = "disabled";		
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("study_place_lever2_A", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					}
					return;
				}
			break;

			case "box9":
				if(GetAttribute(chr, "study_levers") == "disabled") {return;}

				//lever3 is up or missing (2 from left)
				if(CheckAttribute(chr,"quest.study_lever3") && chr.quest.study_lever3 == "up")
				{
					if(CheckAttribute(chr,"quest.study_lever1") && chr.quest.study_lever1 == "down")
					{
						//wall is gone
						if(CheckAttribute(chr,"quest.study_lever2") && chr.quest.study_lever2 == "down")
						{
							//bars are up
							PlaySound("INTERFACE\lever_down.wav");
							chr.quest.study_lever3 = "down";
							Locations[FindLocation("wr_study")].models.always.l3 = "lever3_down";
							Locations[FindLocation("wr_study")].models.always.l6 = "girder_free";
							Locations[FindLocation("wr_study")].locators_radius.box.box9 = 0.0001;
							Locations[FindLocation("wr_study")].locators_radius.box.box13 = 0.5;

							LAi_QuestDelay("study_girder_free", 0.5);
						}
						else
						{
							if(chr.quest.study_lever1 == "up" && chr.quest.study_lever2 == "up" && chr.quest.study_lever4 == "up")
							{
								PlaySound("INTERFACE\lever_stuck.wav");
								return;
							}
							else
							{
								PlaySound("INTERFACE\step_reset.wav");
								chr.quest.study_position = "9";

								LAi_QuestDelay("study_levers_reset1", 1.0);
								return;
							}
						}
					}
					else
					{
						if(chr.quest.study_lever1 == "up" && chr.quest.study_lever2 == "up" && chr.quest.study_lever4 == "up")
						{
							PlaySound("INTERFACE\lever_stuck.wav");
							return;
						}
						else
						{
							PlaySound("INTERFACE\step_reset.wav");
							chr.quest.study_position = "9";

							LAi_QuestDelay("study_levers_reset1", 1.0);
							return;
						}
					}
				}

				if(CheckAttribute(chr,"quest.study_lever3") && chr.quest.study_lever3 == "missing")
				{
					if(CheckCharacterItem(chr,"bladelever"))
					{
						chr.study_levers = "disabled";
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("study_place_lever3_A", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					}
					return;
				}
			break;

			case "box10":
				if(GetAttribute(chr, "study_levers") == "disabled") {return;}

				//lever1 is up or missing (3 from left)
				if(CheckAttribute(chr,"quest.study_lever1") && chr.quest.study_lever1 == "up")
				{
					PlaySound("INTERFACE\lever_down.wav");
					chr.quest.study_lever1 = "down";
					Locations[FindLocation("wr_study")].models.always.l1 = "lever1_down";
					Locations[FindLocation("wr_study")].locators_radius.box.box10 = 0.0001;
					Locations[FindLocation("wr_study")].locators_radius.box.box14 = 0.5;
					Locations[FindLocation("wr_study")].locators_radius.reload.reload2 = 0.5;	//visible when wall is gone
					Locations[FindLocation(chr.location)].models.always.locators = "sh05_locators_JRH1";

					LAi_QuestDelay("study_wall_free", 0.5);
				}

				if(CheckAttribute(chr,"quest.study_lever1") && chr.quest.study_lever1 == "missing")
				{
					if(CheckCharacterItem(chr,"bladelever"))
					{
						chr.study_levers = "disabled";
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("study_place_lever1_A", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					}
					return;
				}
			break;

			case "box11":
				if(GetAttribute(chr, "study_levers") == "disabled") {return;}

				//lever4 is up or missing (4 from left)
				if(CheckAttribute(chr,"quest.study_lever4") && chr.quest.study_lever4 == "up")
				{
					if(CheckAttribute(chr,"quest.study_lever1") && chr.quest.study_lever1 == "down")
					{
						//wall is gone
						if(CheckAttribute(chr,"quest.study_lever2") && chr.quest.study_lever2 == "down")
						{
							//bars are up
							if(CheckAttribute(chr,"quest.study_lever3") && chr.quest.study_lever3 == "down")
							{
								//girder is gone
								PlaySound("INTERFACE\lever_down.wav");
								chr.quest.study_lever4 = "down";
								Locations[FindLocation("wr_study")].models.always.l4 = "lever4_down";
								Locations[FindLocation("wr_study")].locators_radius.box.box11 = 0.0001;
								Locations[FindLocation("wr_study")].locators_radius.box.box15 = 0.5;

								LAi_QuestDelay("study_secret_unlock", 0.5);
							}
							else
							{
								if(chr.quest.study_lever1 == "up" && chr.quest.study_lever2 == "up" && chr.quest.study_lever3 == "up")
								{
									PlaySound("INTERFACE\lever_stuck.wav");
									return;
								}
								else
								{
									PlaySound("INTERFACE\step_reset.wav");
									chr.quest.study_position = "11";

									LAi_QuestDelay("study_levers_reset1", 1.0);
									return;
								}
							}
						}
						else
						{
							if(chr.quest.study_lever1 == "up" && chr.quest.study_lever2 == "up" && chr.quest.study_lever3 == "up")
							{
								PlaySound("INTERFACE\lever_stuck.wav");
								return;
							}
							else
							{
								PlaySound("INTERFACE\step_reset.wav");
								chr.quest.study_position = "11";

								LAi_QuestDelay("study_levers_reset1", 1.0);
								return;
							}
						}
					}
					else
					{
						if(chr.quest.study_lever1 == "up" && chr.quest.study_lever2 == "up" && chr.quest.study_lever3 == "up")
						{
							PlaySound("INTERFACE\lever_stuck.wav");
							return;
						}
						else
						{
							PlaySound("INTERFACE\step_reset.wav");
							chr.quest.study_position = "11";

							LAi_QuestDelay("study_levers_reset1", 1.0);
							return;
						}
					}
				}

				if(CheckAttribute(chr,"quest.study_lever4") && chr.quest.study_lever4 == "missing")
				{
					if(CheckCharacterItem(chr,"bladelever"))
					{
						chr.study_levers = "disabled";
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("study_place_lever4_A", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					}
					return;
				}
			break;

			case "box12":
				//lever2 is down (1 from left)
				PlaySound("INTERFACE\lever_up.wav");
				chr.quest.study_lever2 = "up";
				Locations[FindLocation("wr_study")].models.always.l2 = "lever2_up";
				Locations[FindLocation("wr_study")].models.always.l5 = "bars_down";
				Locations[FindLocation("wr_study")].locators_radius.box.box8 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box12 = 0.0001;

				LAi_QuestDelay("study_bars_down", 0.5);
			break;

			case "box13":
				//lever3 is down (2 from left)
				PlaySound("INTERFACE\lever_up.wav");
				chr.quest.study_lever3 = "up";
				Locations[FindLocation("wr_study")].models.always.l3 = "lever3_up";
				Locations[FindLocation("wr_study")].models.always.l6 = "girder_block";
				Locations[FindLocation("wr_study")].locators_radius.box.box9 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box13 = 0.0001;

				LAi_QuestDelay("study_girder_block", 0.5);
			break;

			case "box14":
				//lever1 is down (3 from left)
				PlaySound("INTERFACE\lever_up.wav");
				chr.quest.study_lever1 = "up";
				Locations[FindLocation("wr_study")].models.always.l1 = "lever1_up";
				Locations[FindLocation("wr_study")].locators_radius.box.box10 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box14 = 0.0001;
				Locations[FindLocation(chr.location)].models.always.locators = "sh05_locators_JRH";

				LAi_QuestDelay("study_wall_block", 0.5);
			break;

			case "box15":
				//lever4 is down (4 from left)
				PlaySound("INTERFACE\lever_up.wav");
				chr.quest.study_lever4 = "up";
				Locations[FindLocation("wr_study")].models.always.l4 = "lever4_up";

				Locations[FindLocation("wr_study")].locators_radius.box.box11 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box15 = 0.0001;

				LAi_QuestDelay("study_secret_lock", 0.5);
			break;

			case "box16":
				//Rogers corpse

				if(CheckAttribute(chr,"quest.clear_study_boxes") && chr.quest.clear_study_boxes == "yes")
				{
					locations[FindLocation(chr.location)].box16.items.blade1 = 0;
					locations[FindLocation(chr.location)].box16.items.pistol20 = 0;
					locations[FindLocation(chr.location)].box16.items.ammobag1 = 0;
					locations[FindLocation(chr.location)].box16.items.ammobag2 = 0;

					locations[FindLocation(chr.location)].box16.items."bladeA5" = 0;
					locations[FindLocation(chr.location)].box16.items."spyglass3" = 0;
					locations[FindLocation(chr.location)].box16.items.temp_coins = 0;
					locations[FindLocation(chr.location)].box16.items.sewing_kit = 0;
					locations[FindLocation(chr.location)].box16.items.tobacco = 0;
					locations[FindLocation(chr.location)].box16.items.folding_knife = 0;
					locations[FindLocation(chr.location)].box16.items.compass1 = 0;
					locations[FindLocation(chr.location)].box16.items.pistoltinderbox = 0;
					locations[FindLocation(chr.location)].box16.items.key17 = 0;

					locations[FindLocation(chr.location)].box16.items.red_uniform = 0;
					locations[FindLocation(chr.location)].box16.items.sextant = 0;
					locations[FindLocation(chr.location)].box16.items.tin_jug = 0;
					locations[FindLocation(chr.location)].box16.items.tobacco = 0;
					locations[FindLocation(chr.location)].box16.items."pistol9+2" = 0;
					locations[FindLocation(chr.location)].box16.items.silver_bar = 0;
					locations[FindLocation(chr.location)].box16.items.clock1 = 0;
 					locations[FindLocation(chr.location)].box16.items.foreign_items = 0;
					locations[FindLocation(chr.location)].box16.items.drawing_kit = 0;
					locations[FindLocation(chr.location)].box16.items.strange_shells = 0;
					locations[FindLocation(chr.location)].box16.items.package = 0;
					locations[FindLocation(chr.location)].box16.items.temp_purse = 0;

					locations[FindLocation(chr.location)].box16.money = 0;
				}

				LaunchItemsBox(&ar);
				return;
			break;
		}
		return;
	}

	if(Locations[locidx].id=="wr_residence")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1")
	    	{
			//law
			LaunchItemsBox(&ar);

			if(CheckAttribute(chr,"quest.wr_book21") && chr.quest.wr_book21 == "placed")
			{
				//do nothing book is already placed
			}
			else
			{
				if(CheckCharacterItem(chr,"book21") )
				{
					LAi_QuestDelay("book21and24_check", 0.1);
					LAi_QuestDelay("book21_check", 0.1);
				}
			}
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
	    	{
			//antiques jewels
			LaunchItemsBox(&ar);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			PauseAllSounds();
			PlaySound("INTERFACE\Clock.wav");
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box4")
	    	{
			ChangeCharacterAddressGroup(chr, "wr_residence", "goto", "goto13");
			PlaySound("PEOPLE\Run_wood.wav");
			return;
		}
	}

	if(Locations[locidx].id=="wr_library")
	{
		switch(chr.boxname)
		{
			case "box4":
				//history
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_gunroom") && chr.quest.wr_gunroom == "locked")
				{
					if(CheckCharacterItem(chr,"book24") )
					{
						//double check: before & after box visit
						//it was possible to unlock with wrong book
						LAi_QuestDelay("book24_unlock_check", 0.1);
					}
				}

				if(CheckAttribute(chr,"quest.wr_gunroom") && chr.quest.wr_gunroom == "unlocked")
				{
					LAi_QuestDelay("book24_lock_check", 0.1);
				}
			break;

			case "box2":
				//trade
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book34") && chr.quest.wr_book34 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book34") )
					{
						LAi_QuestDelay("book34_check", 0.1);
					}
				}
			break;

			case "box3":
				//chemistry
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book27") && chr.quest.wr_book27 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book27") )
					{
						LAi_QuestDelay("book27_check", 0.1);
					}
				}
			break;

			case "box5":
				//geo
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book33") && chr.quest.wr_book33 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book33") )
					{
						LAi_QuestDelay("book33_check", 0.1);
					}
				}
			break;

			case "box6":
				//shipbuild
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book23") && chr.quest.wr_book23 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book23") )
					{
						LAi_QuestDelay("book23_check", 0.1);
					}
				}
			break;

			case "box7":
				//sea battles
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book22") && chr.quest.wr_book22 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book22") )
					{
						LAi_QuestDelay("book22and26_check", 0.1);
						LAi_QuestDelay("book22_check", 0.1);
					}
				}

				//tour "sea battles"
				ChangeCharacterAddressGroup(chr, "wr_library", "box", "box14");
				LAi_QuestDelay("tour_library", 0.1);
				return;
			break;

			case "box12":
				//medicine
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book26") && chr.quest.wr_book26 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book26") )
					{
						LAi_QuestDelay("book26_check", 0.1);
					}
				}
			break;

			case "box8":
				//lever is up - gunroom door is hidden
				PlaySound("INTERFACE\lever_down.wav");

				if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "medicine")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH13";

				}
				else
				{
					if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "mission5")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH10";
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "book25")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH7";
					}
					else
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH4";
					}
				}

				LAi_QuestDelay("gunroom_door_visible", 0.5);
				return;
			break;

			case "box9":
				//lever is down - gunroom door is visible
				PlaySound("INTERFACE\lever_up.wav");

				if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "medicine")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH12";

				}
				else
				{
					if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "mission5")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH9";
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.wr_library") && chr.quest.wr_library == "book25")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH6";
					}
					else
					{
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_JRH3";
					}
				}

				LAi_QuestDelay("gunroom_door_hidden", 0.5);
				return;
			break;

			case "box10":
				//erotica
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.wr_book28") && chr.quest.wr_book28 == "placed")
				{
					//do nothing book is already placed
				}
				else
				{
					if(CheckCharacterItem(chr,"book28") )
					{
						LAi_QuestDelay("book28andCorkscrews_check", 0.1);
						LAi_QuestDelay("book28_check", 0.1);
					}
				}

				//tour "erotica"
				ChangeCharacterAddressGroup(chr, "wr_library", "box", "box15");
				LAi_QuestDelay("tour_library", 0.1);
				return;
			break;

			case "box1":
				//poetry
				LaunchItemsBox(&ar);

				if(CheckCharacterItem(chr,"emptysack") )
				{
					LAi_QuestDelay("book30_pickup", 0.1);
				}
				else LAi_QuestDelay("book30_return", 0.1);

				return;
			break;

			case "box14":
				//walk to seabattles or not

				if(CheckAttribute(chr,"quest.seabattles_enable") && chr.quest.seabattles_enable == "yes")
				{
					ChangeCharacterAddressGroup(chr, "wr_library", "goto", "goto19");
					PlaySound("PEOPLE\Run_wood.wav");
				}
				else PlaySound("VOICE\ENGLISH\blaze_hah.wav");

				return;
			break;

			case "box15":
				//walk to erotica or not

				if(CheckAttribute(chr,"quest.erotica_enable") && chr.quest.erotica_enable == "yes")
				{
					ChangeCharacterAddressGroup(chr, "wr_library", "goto", "goto21");
					PlaySound("PEOPLE\Run_wood.wav");
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");

				return;
			break;

			//default:
			LaunchItemsBox(&ar);
			return;
		}
		return;
	}

	if(Locations[locidx].id=="wr_crew")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			//lever is down - hatch is closed (start) - counter is open
			PlaySound("INTERFACE\lever_up.wav");
			Locations[FindLocation(chr.location)].models.always.locators = "tavern03_locators_JRH2";

			LAi_QuestDelay("crew_hatch_open", 0.5);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1")
	    	{
			//lever is up - hatch is open - counter is blocked
			PlaySound("INTERFACE\lever_down.wav");
			Locations[FindLocation(chr.location)].models.always.locators = "tavern03_locators_JRH1";

			LAi_QuestDelay("crew_hatch_lock", 0.5);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
	    	{
			PlaySound("INTERFACE\locked_window.wav");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box4")
	    	{
			LaunchItemsBox(&ar);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box5")
	    	{
			ChangeCharacterAddressGroup(chr, "wr_crew", "box", "box6");
			PlaySound("PEOPLE\step_stairway.wav");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box6")
	    	{
			ChangeCharacterAddressGroup(chr, "wr_crew", "box", "box5");
			PlaySound("PEOPLE\step_stairway2.wav");
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box7")
	    	{
			Logit(TranslateString("","There's a chest - but how do I get to it?"));
			PlaySound("INTERFACE\knock.wav");

			if(CheckAttribute(chr,"quest.crew_chest") && chr.quest.crew_chest == "visible")
			{

			}
			else
			{
				chr.quest.crew_chest = "visible";
				AddQuestRecord("Open_the_mine", "2");	//only first time
			}

			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box8")
	    	{
			PlaySound("INTERFACE\knock.wav");
			return;
		}
	}

	if(Locations[locidx].id=="loanshark_cellar")
	{
		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_shop")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				Locations[FindLocation("wr_shop")].image = "";
				PlaySound("INTERFACE\lever_down.wav");
				chr.quest.wr_elevator = "down";

				if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
				{
					Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Ldown_mdc";
				}
				else
				{
					if(CheckAttribute(chr,"quest.wr_shoppistol") && chr.quest.wr_shoppistol == "yes")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Ldown";
					}
				}
				else
				{
					Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Ldown_P3";
				}

				LAi_QuestDelay("elevator_lever", 0.5);
				return;
			break;

			case "box3":
				if(CheckAttribute(chr,"quest.shop_elevator") && chr.quest.shop_elevator == "temp_off")
				{
					PlaySound("INTERFACE\lever_stuck.wav");
					Logit(TranslateString("","The lever is not working!!!"));
					return;
				}
				else
				{
					Locations[FindLocation("wr_shop")].image = "";
					PlaySound("INTERFACE\lever_up.wav");
					chr.quest.wr_elevator = "up";

					if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Lup_mdc";
					}
					else
					{
						if(CheckAttribute(chr,"quest.wr_shoppistol") && chr.quest.wr_shoppistol == "yes")
						{
							Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Lup";
						}
					}
					else
					{
						Locations[FindLocation(chr.location)].models.always.locators = "residence05_locators_JRH_Lup_P3";
					}

					LAi_QuestDelay("elevator_lever", 0.5);
					return;
				}
			break;

			case "box4":
				//double this one! box 4 = the locked one
				if(CheckCharacterItem(chr,"key8"))
				{
					//go inside
					PlaySound("INTERFACE\key_unlock.wav");
					LAi_QuestDelay("shop_closet", 2.0);
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				chr.quest.shop_box5_tour1.win_condition.l1 = "locator";
				chr.quest.shop_box5_tour1.win_condition.l1.location = "wr_shop";
				chr.quest.shop_box5_tour1.win_condition.l1.locator_group = "goto";
				chr.quest.shop_box5_tour1.win_condition.l1.locator = "goto11";
				chr.quest.shop_box5_tour1.win_condition = "shop_box5_tour1";

				ChangeCharacterAddressGroup(chr, "wr_shop", "goto", "goto11");
				return;
			break;

			case "box7":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box9":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);

				chr.quest.shop_box9_tour1.win_condition.l1 = "locator";
				chr.quest.shop_box9_tour1.win_condition.l1.location = "wr_shop";
				chr.quest.shop_box9_tour1.win_condition.l1.locator_group = "goto";
				chr.quest.shop_box9_tour1.win_condition.l1.locator = "goto6";
				chr.quest.shop_box9_tour1.win_condition = "shop_box_run_sound";

				ChangeCharacterAddressGroup(chr, "wr_shop", "goto", "goto6");
				return;
			break;

			case "box8":
				if(CheckAttribute(chr,"quest.wr_shop") && chr.quest.wr_shop == "box8_tour_open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					LAi_QuestDelay("shop_box8_tour", 0.1);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key9"))
					{
						chr.quest.wr_shop = "box8_tour_open";
						TakeItemFromCharacter(chr, "key9");
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
						LAi_QuestDelay("shop_box8_tour", 0.1);
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box10":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				chr.quest.shop_box10_tour1.win_condition.l1 = "locator";
				chr.quest.shop_box10_tour1.win_condition.l1.location = "wr_shop";
				chr.quest.shop_box10_tour1.win_condition.l1.locator_group = "goto";
				chr.quest.shop_box10_tour1.win_condition.l1.locator = "goto9";
				chr.quest.shop_box10_tour1.win_condition = "shop_box_run_sound";

				ChangeCharacterAddressGroup(chr, "wr_shop", "goto", "goto9");
				return;
			break;

			case "box11":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				chr.quest.shop_box11_tour1.win_condition.l1 = "locator";
				chr.quest.shop_box11_tour1.win_condition.l1.location = "wr_shop";
				chr.quest.shop_box11_tour1.win_condition.l1.locator_group = "goto";
				chr.quest.shop_box11_tour1.win_condition.l1.locator = "goto8";
				chr.quest.shop_box11_tour1.win_condition = "shop_box_run_sound";

				ChangeCharacterAddressGroup(chr, "wr_shop", "goto", "goto8");
				return;
			break;

			case "box12":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				chr.quest.shop_box12_tour1.win_condition.l1 = "locator";
				chr.quest.shop_box12_tour1.win_condition.l1.location = "wr_shop";
				chr.quest.shop_box12_tour1.win_condition.l1.locator_group = "goto";
				chr.quest.shop_box12_tour1.win_condition.l1.locator = "goto10";
				chr.quest.shop_box12_tour1.win_condition = "shop_box_run_sound";

				ChangeCharacterAddressGroup(chr, "wr_shop", "goto", "goto10");
				LAi_QuestDelay("shop_box12_tour1", 1.0);
				return;
			break;

			case "box13":
				//medicine chest

				Logit(TranslateString("","If I just had something to carry this chest with!"));
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				return;
			break;
		}
		return;
	}

	//so pchar not dies here
	if(Locations[locidx].id=="wr_shop_office")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			if(CheckAttribute(chr,"quest.chest_hint") && chr.quest.chest_hint == "dave")
			{
				LaunchItemsBox(&ar);
				return;
			}
			else
			{
				PlaySound("INTERFACE\locked_window.wav");
		 		return;
			}
		}
	}

	if(Locations[locidx].id=="Dave_Edna_room")
	{
		//elevator
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1")
		{
			if(CheckAttribute(chr,"quest.wr_elevator") && chr.quest.wr_elevator == "down")
			{
				PlaySound("INTERFACE\elevator_gate.wav");

				LAi_QuestDelay("elevator_up", 0.5);
				return;
			}

			if(CheckAttribute(chr,"quest.wr_elevator") && chr.quest.wr_elevator == "up")
			{
				PlaySound("INTERFACE\locked_window.wav");
				return;
			}
		}

		//violin box
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			if(CheckAttribute(chr,"quest.med_Dave") && chr.quest.med_Dave == "violin_bought")
			{
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
				return;
			}
			else
			{
				PlaySound("INTERFACE\locked_window.wav");
		 		return;
			}
		}

		//locked door
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
	    	{
			PlaySound("INTERFACE\key_unlock.wav");

			LAi_QuestDelay("unlock_daves_room", 2.0);
			return;
		}
	}

	if(Locations[locidx].id=="wr_mother")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.wr_elevator") && chr.quest.wr_elevator == "up")
				{
					PlaySound("INTERFACE\elevator_gate.wav");
					LAi_QuestDelay("elevator_down", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.wr_elevator") && chr.quest.wr_elevator == "down")
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box3":
				if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box4":
				if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;

			case "box5":
				if(CheckAttribute(chr,"quest.medicine_quest") && chr.quest.medicine_quest == "started")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("INTERFACE\locked_window.wav");
					return;
				}
			break;
		}
	}

	if(Locations[locidx].id=="wr_gunpowder")
	{
		LaunchItemsBox(&ar);
		return;
	}

	if(Locations[locidx].id=="wr_armory")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1")
		{
			PlaySound("AMBIENT\JAIL\door_003.wav");
			LaunchItemsBox(&ar);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
		{
			if(CheckAttribute(chr,"quest.wr_armorybox") && chr.quest.wr_armorybox == "open")
			{
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
				return;
			}
			else
			{
				Logit(TranslateString("","The chest is blocked by a lot of goods."));
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				return;
			}
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box3")
		{
			switch(chr.quest.wr_quest1)
			{
				case "pistol2":
					Logit(TranslateString("","Not a chance!"));
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("armory_intro2", 0.1);
				break;

				case "blade_found":
					chr.quest.wr_quest1 = "blade_used2";
					LAi_LocationFightDisable(&Locations[FindLocation(chr.location)], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("blade_on_armory_box", 1.0);
				break;

				case "blade_used2":
					LAi_QuestDelay("armory_balls", 0.1);
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}
	}

	if(Locations[locidx].id=="wr_kitchen")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box1" || chr.boxname == "box2" || chr.boxname == "box3")
	    	{
			PlaySound("AMBIENT\JAIL\door_003.wav");
			LaunchItemsBox(&ar);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box4")
	    	{
			//R1: lever is down - door is open
			PlaySound("INTERFACE\lever_up.wav");
			Locations[FindLocation(chr.location)].models.always.locators = "FlamHouse_locators_JRH2";

			LAi_QuestDelay("kitchen_R1_lock", 0.5);
			return;
		}

		if(CheckAttribute(chr,"boxname") && chr.boxname == "box5")
	    	{
			if(CheckAttribute(chr,"quest.wr_kitchendoor") && chr.quest.wr_kitchendoor == "stuck")
			{
				PlaySound("INTERFACE\lever_stuck.wav");
				Logit(TranslateString("","The lever is not working!!!"));

				LAi_QuestDelay("kitchen_lever_stuck", 1.0);
				return;
			}
			else
			{
				//R1: lever is up - door is locked (start)
				PlaySound("INTERFACE\lever_down.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "FlamHouse_locators_JRH1";

				LAi_QuestDelay("kitchen_R1_unlock", 0.5);
				return;
			}
		}
	}

	if(Locations[locidx].id=="QC_store_JRH")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "QC_store_JRH", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "QC_store_JRH", "box", "box1");
			break;
		}
		return;
	}

	//so pchar not dies here
	if(Locations[locidx].id=="QC_store_bedroom")
	{
		if(CheckAttribute(chr,"boxname") && chr.boxname == "box2")
	    	{
			LaunchItemsBox(&ar);
			return;
		}
	}

	if(Locations[locidx].id=="QC_shipyard2_JRH")
	{
		switch(chr.boxname)
		{
			case "box1":
				//F
				//Log_SetStringToLog("Box1");

				PlaySound("INTERFACE\closet_Open.wav");
		 		LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.shya_heavytool") && chr.quest.shya_heavytool == "taken")
				{

				}
				else LAi_QuestDelay("shya_take_heavytool", 0.1);
			break;

			case "box2":
				//AB lower chest
				//Log_SetStringToLog("Box2");

				if(CheckAttribute(chr,"quest.shya_box2") && chr.quest.shya_box2 == "open")
				{
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
					LaunchItemsBox(&ar);

					if(CheckAttribute(chr,"quest.shya_drill") && chr.quest.shya_drill == "done")
					{
						//dont repeat take drill check
					}
					else LAi_QuestDelay("shya_take_drill", 0.1);
				}
				else
				{
					if(CheckAttribute(chr,"quest.shya_box2") && chr.quest.shya_box2 == "unlocked_but_stuck")
					{
						if(IsEquipCharacterByItem(chr, "tool3"))
						{
							LAi_LocationFightDisable(&Locations[chr.location], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("shya_use_hammer", 1.0);
						}
						else
						{
							Logit(TranslateString("","It's unlocked but somehow the mechanism is jammed."));

							PlaySound("AMBIENT\JAIL\jail_door1.wav");
						}
					}
					else
					{
						if(CheckCharacterItem(chr,"key2"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.quest.shya_box2 = "unlocked_but_stuck";
							TakeItemFromCharacter(chr, "key2");
						}
						else
						{
							PlaySound("INTERFACE\locked_window.wav");
						}
					}
				}
			break;

			case "box3":
				//E chest function
				//Log_SetStringToLog("Box3");

				if(CheckAttribute(chr,"quest.shya_posE"))
				{
					if(chr.quest.shya_posE == "chest")
					{
						if(CheckAttribute(chr,"quest.shya_box3") && chr.quest.shya_box3 == "free_key")
						{
							PlaySound("INTERFACE\key_lock.wav");
							chr.quest.shya_box3 = "locked";
							GiveItem2Character(chr, "key4");

							LAi_QuestDelay("shya_delayed_ping", 1.0);
						}
						else
						{
							if(CheckAttribute(chr,"quest.shya_box3") && chr.quest.shya_box3 == "open")
							{
								PlaySound("INTERFACE\closet_Open.wav");
								chr.quest.shya_box3 = "free_key";
								LaunchItemsBox(&ar);
							}
						}
						else
						{
							//this is "locked" mode but don't check for this
							if(CheckCharacterItem(chr,"key4"))
							{
								PlaySound("INTERFACE\key_unlock2.wav");
								chr.quest.shya_box3 = "open";
								TakeItemFromCharacter(chr, "key4");
							}
							else
							{
								Logit(TranslateString("","It's an ordinary lock here."));
								PlaySound("INTERFACE\locked_window.wav");

							}
						}
					}
				}
			break;

			case "box4":
				//C drilling
				//Log_SetStringToLog("Box4");

				LAi_LocationFightDisable(&Locations[chr.location], false);
				LAi_SetFightMode(chr, true);

				chr.quest.shya_posC = "invisible";
				chr.quest.shya_drill = "done";
				ChangeCharacterAddressGroup(chr, "QC_shipyard2_JRH", "goto", "goto9");

				LAi_QuestDelay("shya_use_drill", 1.0);
				LAi_QuestDelay("shya_radius_check", 0.1);
			break;

			case "box5":
				//AB upper chest
				//Log_SetStringToLog("Box5");

				if(CheckAttribute(chr,"quest.shya_box5") && chr.quest.shya_box5 == "open")
				{
						PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 				LaunchItemsBox(&ar);

						LAi_QuestDelay("shya_take_blade4_box5", 0.1);
						LAi_QuestDelay("shya_take_key4_box5", 0.1);
						LAi_QuestDelay("shya_take_tar_box5", 1.0);
						LAi_QuestDelay("empty_carpenter_chest", 0.1);
				}
				else
				{
					if(CheckCharacterItem(chr,"key1"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						TakeItemFromCharacter(chr, "key1");
						chr.quest.shya_box5 = "open";
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
					}
				}
			break;

			case "box6":
				//D basket chest
				//Log_SetStringToLog("Box6");

				if(CheckAttribute(chr,"quest.shya_box6") && chr.quest.shya_box6 == "open")
				{
					//already open
					PlaySound("PEOPLE\basket.wav");
		 			LaunchItemsBox(&ar);

					if(CheckAttribute(chr,"quest.shya_hammer") && chr.quest.shya_hammer == "taken")
					{

					}
					else LAi_QuestDelay("shya_take_hammer", 0.1);
				}
				else
				{
					if(IsEquipCharacterByItem(chr, "blade4"))
					{
						LAi_LocationFightDisable(&Locations[chr.location], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("shya_use_cutlass", 1.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						Logit(TranslateString("","No lock but it's stuck, maybe I can pry it open with any sharp and strong item."));
					}
				}
			break;

			case "box7":
				//Log_SetStringToLog("Box7");
				//only mast blocking drawer

				if(CheckAttribute(chr,"quest.shya_posJ") && chr.quest.shya_posJ == "blocked")
				{
					if(IsEquipCharacterByItem(chr, "tool2"))
					{
						LAi_LocationFightDisable(&Locations[chr.location], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("shya_use_axe", 1.0);
					}
					else
					{
						Logit(TranslateString("","Have to be careful - that beam rests only on a small piece of wood."));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					}
				}
			break;

			case "box8":
				//bookshelf
				//Log_SetStringToLog("Box8");

				PlaySound("INTERFACE\closet_Open.wav");
		 		LaunchItemsBox(&ar);
			break;

			case "box9":
				//P commode: push beam
				//Log_SetStringToLog("Box9");

				if(CheckAttribute(chr,"quest.shya_beam"))
				{
					if(chr.quest.shya_beam == "middle")
					{
						//push?
						if(CheckAttribute(chr,"quest.shya_barrel2") && chr.quest.shya_barrel2 == "taken")
						{
							Locations[FindLocation(chr.location)].models.always.l1 = "BeamL";
							PlaySound("OBJECTS\DUEL\man_attack1.wav");

							LAi_QuestDelay("push_MtoL", 0.5);
						}
						else
						{
							Logit(TranslateString("","If I only could push this beam a little."));
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						}
					}
				}
			break;

			case "box10":
				//H push beam
				//Log_SetStringToLog("Box10");

				Locations[FindLocation(chr.location)].models.always.l1 = "BeamR";
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_QuestDelay("push_MtoR", 0.5);
			break;

			case "box11":
				//AB push beam
				//Log_SetStringToLog("Box11");

				if(CheckAttribute(chr,"quest.shya_barrel1") && chr.quest.shya_barrel1 == "taken")
				{
					Locations[FindLocation(chr.location)].models.always.l1 = "BeamM";
					PlaySound("OBJECTS\DUEL\man_attack1.wav");

					LAi_QuestDelay("push_RtoM", 0.5);
				}
				else
				{
					Logit(TranslateString("","If I only could push this beam a little."));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				}
			break;

			case "box12":
				//G large lock
				//Log_SetStringToLog("Box12");

				if(CheckAttribute(chr,"quest.shya_box12") && chr.quest.shya_box12 == "unlocked")
				{
					//this can only occur if NOT the other lock is unlocked
					PlaySound("INTERFACE\locked_window.wav");
					Logit(TranslateString("","Hmm, the other lock is not opened yet"));
				}
				else
				{
					if(CheckCharacterItem(chr,"key3"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						TakeItemFromCharacter(chr, "key3");
						chr.quest.shya_box12 = "unlocked";

						//check if other lock also is unlocked, direct here
						if(CheckAttribute(chr,"quest.shya_box14") && chr.quest.shya_box14 == "unlocked")
						{
							//we go now to box17 for LaunchItemsBox
							chr.quest.shya_posC = "open";

							LAi_QuestDelay("shya_radius_check", 0.1);
						}
					}
					else
					{
						Logit(TranslateString("","It's a large lock to the left."));
						PlaySound("INTERFACE\locked_window.wav");
					}
				}

			break;

			case "box13":
				//G push beam
				//Log_SetStringToLog("Box13");

				Locations[FindLocation(chr.location)].models.always.l1 = "BeamM";
				PlaySound("OBJECTS\DUEL\man_attack1.wav");

				LAi_QuestDelay("push_LtoM", 0.5);
			break;

			case "box14":
				//Log_SetStringToLog("Box14");

				if(CheckAttribute(chr,"quest.shya_box14") && chr.quest.shya_box14 == "free_key")
				{
					PlaySound("INTERFACE\key_lock.wav");
					chr.quest.shya_box14 = "locked";
					GiveItem2Character(chr, "key4");

					LAi_QuestDelay("shya_delayed_ping", 1.0);
				}
				else
				{
					if(CheckAttribute(chr,"quest.shya_box14") && chr.quest.shya_box14 == "unlocked")
					{
						//this can only occur if NOT the other lock is unlocked
						PlaySound("INTERFACE\locked_window.wav");
						chr.quest.shya_box14 = "free_key";
						Logit(TranslateString("","Hmm, the other lock is not opened yet"));
					}
				}
				else
				{
					//this is "locked" mode but don't check for this
					if(CheckCharacterItem(chr,"key4"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.shya_box14 = "unlocked";
						TakeItemFromCharacter(chr, "key4");


						//check if other lock also is unlocked, direct here
						if(CheckAttribute(chr,"quest.shya_box12") && chr.quest.shya_box12 == "unlocked")
						{
							//we go now to box17 for LaunchItemsBox
							chr.quest.shya_posC = "open";

							LAi_QuestDelay("shya_radius_check", 0.1);
						}
					}
					else
					{
						Logit(TranslateString("","It's an ordinary lock to the right."));
						PlaySound("INTERFACE\locked_window.wav");

					}
				}
			break;

	  		case "box15":
				//K at door

				if(CheckAttribute(chr,"quest.shya_posK") && chr.quest.shya_posK == "locked")
				{
					if(IsEquipCharacterByItem(chr, "tool1"))
					{
						LAi_LocationFightDisable(&Locations[chr.location], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("shya_use_compasses", 1.0);
					}
					else
					{
						Logit(TranslateString("","This 'lock' is so simple that I could pick it with a fork!"));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					}
				}

				if(CheckAttribute(chr,"quest.shya_posK") && chr.quest.shya_posK == "blocked")
				{
					if(IsEquipCharacterByItem(chr, "tool5"))
					{
						LAi_LocationFightDisable(&Locations[chr.location], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("shya_use_saw", 1.0);
					}
					else
					{
						Logit(TranslateString("","Not a chance!"));
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
					}
				}
			break;

			case "box16":
				//Log_SetStringToLog("Box16");
				//only drawer behind mast

				if(CheckAttribute(chr,"quest.shya_posJ") && chr.quest.shya_posJ == "chest")
				{
					PlaySound("INTERFACE\closet_Open.wav");
					LaunchItemsBox(&ar);

					if(CheckAttribute(chr,"quest.shya_compasses") && chr.quest.shya_compasses == "taken")
					{

					}
					else LAi_QuestDelay("shya_take_compasses", 0.1);
				}
			break;

			case "box17":
				//C open chest
				//Log_SetStringToLog("Box17");

				PlaySound("AMBIENT\JAIL\jail_door2.wav");
		 		LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.shya_axe") && chr.quest.shya_axe == "taken")
				{

				}
				else LAi_QuestDelay("shya_take_axe", 0.1);
			break;

			case "box18":
				//P commode: chest function
				//Log_SetStringToLog("Box9");

				if(CheckAttribute(chr,"quest.shya_beam"))
				{
					if(chr.quest.shya_beam == "left")
					{
						//open?
						if(CheckAttribute(chr,"quest.shya_box9") && chr.quest.shya_box9 == "open")
						{
							//already open
							PlaySound("INTERFACE\closet_Open.wav");
		 					LaunchItemsBox(&ar);

							if(CheckAttribute(chr,"quest.shya_saw") && chr.quest.shya_saw == "taken")
							{
								//wake up Caroline only once
							}
							else LAi_QuestDelay("shya_take_saw", 0.1);
						}
						else
						{
							if(IsEquipCharacterByItem(chr, "blade5"))
							{
								LAi_LocationFightDisable(&Locations[chr.location], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("shya_use_dagger", 1.0);
							}
							else
							{
								Logit(TranslateString("","No lock - and no handle either, how do I open it?"));
								PlaySound("VOICE\ENGLISH\blaze_huh.wav");
							}
						}
					}
				}
			break;

			case "box19":
				//E blocking beam
				//Log_SetStringToLog("Box19");

				if(CheckAttribute(chr,"quest.shya_posE"))
				{
					if(chr.quest.shya_posE == "blocked")
					{
						if(IsEquipCharacterByItem(chr, "tool6"))
						{
							LAi_LocationFightDisable(&Locations[chr.location], false);
							LAi_SetFightMode(chr, true);

							ChangeCharacterAddressGroup(chr, "QC_shipyard2_JRH", "goto", "lever");

							LAi_QuestDelay("shya_use_lever", 1.0);
						}
						else
						{
							Logit(TranslateString("","This beam is too heavy, I must find something to use as a lever."));
							PlaySound("OBJECTS\DUEL\man_attack1.wav");
						}
					}
				}
			break;
		}
		return;
	}
    // <-- JRH
  }
	virtual_box = true;	//JRH
	OpenBoxProcedure();
}

//JRH
//from Loginterface.c
void CreateLandActionsEnvironment_WR()
{
//Logit("4444");

	ref PChar = GetMainCharacter();		//JRH

//JRH -->

	if( CheckAttribute(Pchar,"boxname") )
	{
		if(Pchar.location == "Eleuthera_shore")
		{
			IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box37" || Pchar.boxname == "box38") IActions.ActiveActions.OpenBox.IconNum = 0;
			if(Pchar.boxname == "box16" || Pchar.boxname == "box36" || Pchar.boxname == "box40") IActions.ActiveActions.OpenBox.IconNum = 2;
			if(Pchar.boxname == "box12")
			{
		//		if(CheckCharacterItem(Pchar,"bladeanchor_big") || Locations[FindLocation("Eleuthera_shore")].models.always.l6 == "anchor_big3")
				if(CheckCharacterItem(Pchar,"bladeanchor_big"))
				{
					IActions.ActiveActions.OpenBox.IconNum = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 63;
			}
		}

		if(Pchar.location == "Citadel_tower_stairs4") IActions.ActiveActions.OpenBox.IconNum  	= 1;

		if(Pchar.location == "Tortuga_port")
		{
			IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 29;
			if(Pchar.boxname == "box10")
			{
				if (makeint(environment.time) > 22.0 || makeint(environment.time) < 6.0)
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 1;
			}
		}

		if(Pchar.location == "Tortuga_tower") IActions.ActiveActions.OpenBox.IconNum  	= 63;
		if(Pchar.location == "Tortuga_sailmaker") IActions.ActiveActions.OpenBox.IconNum  = 63;
		if(Pchar.location == "Tortuga_surgeon2") IActions.ActiveActions.OpenBox.IconNum  	= 63;
		if(Pchar.location == "Tortuga_gunsmith_workshop") IActions.ActiveActions.OpenBox.IconNum  = 63;

		if(Pchar.location == "cloister_exit")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 63;
		}

		if(Pchar.location == "BB_QAR_cabin")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 63;
		}

		if(Pchar.location == "BB_graveyard")
		{
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum  	= 13;
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum  	= 63;
		}

		if(Pchar.location == "BB_church_room")
		{
			if(Pchar.boxname == "box1")  IActions.ActiveActions.OpenBox.IconNum  	= 3;
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 2;
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum  	= 13;
		}

		if(Pchar.location == "BB_bell_tower")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 57;
		}

		if(Pchar.location == "BB_crypt2_1")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}

		if(Pchar.location == "BB_crypt2_2")
		{
			if(Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum  	= 30;
		}

		if(Pchar.location == "BB_abbey_cell")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 3;
			if(Pchar.boxname == "box3")
			{
				if(Locations[FindLocation(Pchar.location)].models.always.l2 == "straw")
				{
					if(CheckCharacterItem(Pchar,"bladebroom"))
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum  	= 3;
				}
				else	IActions.ActiveActions.OpenBox.IconNum  	= 29;
			}
		}

		if(Pchar.location == "BB_refectory")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2")
			{
				 IActions.ActiveActions.OpenBox.IconNum  	= 63; 
			}
			else IActions.ActiveActions.OpenBox.IconNum  	= 0;
		}

		if(Pchar.location == "Turks_Fort_Office")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box5"
			|| Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum  	= 0;
			if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box8"
			|| Pchar.boxname == "box9" || Pchar.boxname == "box10" || Pchar.boxname == "box11") 
				IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}

		if(Pchar.location == "Turks_jungle_03")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}


		if(Pchar.location == "Turks_tavern_bedroom")
		{
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum  	= 1;
		}

		if(Pchar.location == "Turks_port")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 1;
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box5")
				IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum  	= 30;
			if(Pchar.boxname == "box9" || Pchar.boxname == "box10") 
				IActions.ActiveActions.OpenBox.IconNum  	= 5;
		}

		if(Pchar.location == "Turks_wreck_shore")
		{
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box5"
			|| Pchar.boxname == "box6" || Pchar.boxname == "box7" || Pchar.boxname == "box8"
			|| Pchar.boxname == "box9" || Pchar.boxname == "box10" || Pchar.boxname == "box11"
			|| Pchar.boxname == "box12")  IActions.ActiveActions.OpenBox.IconNum  	= 61; 
			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}

		if(Pchar.location == "BB_sloop_wreck_cabin")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}

		if(Pchar.location == "BB_careen_holdP")
		{
			if(Pchar.boxname == "box1")
			{
				if(CheckAttribute(Pchar,"careen_convicts") && Pchar.careen_convicts == "locked")
				{
					if(CheckCharacterItem(Pchar,"key39"))
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;	
					}
					else IActions.ActiveActions.OpenBox.IconNum  	= 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 1;
			}
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 3;
		}

		if(Pchar.location == "BB_careen_holdS")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 7;
		}

		if(Pchar.location == "BB_sloop_wreck_hold")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 7;
		}

		if(Pchar.location == "BB_careen_capmd_2")
		{
			if(Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum  	= 6;
			if(Pchar.boxname == "box9" || Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum = 2;
		}

		if(Pchar.location == "BB_careen_capsm")
		{
			if(Pchar.boxname == "box2")
			{
				if(CheckCharacterItem(Pchar,"pitchfork"))
				{	
					IActions.ActiveActions.OpenBox.IconNum  	= 2;	
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 3;
			}
		}
//pär
		if(Pchar.location == "BB_Maltains")
		{
			if(Pchar.boxname == "box9")
			{
				if(CheckAttribute(Pchar, "cell9") && Pchar.cell9 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}
		
			if(Pchar.boxname == "box7")
			{
				if(CheckAttribute(Pchar, "cell7") && Pchar.cell7 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar, "cell3") && Pchar.cell3 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.boxname == "box1")
			{
				if(CheckAttribute(Pchar, "cell1") && Pchar.cell1 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.boxname == "box5")
			{
				if(CheckAttribute(Pchar, "cell5") && Pchar.cell5 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.boxname == "box17")
			{
				if(CheckAttribute(Pchar, "cell17") && Pchar.cell17 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else 
				{
					if(CheckAttribute(Pchar, "cell17") && Pchar.cell17 == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.boxname == "box15")
			{
				if(CheckAttribute(Pchar, "cell15") && Pchar.cell15 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else 
				{
					if(CheckAttribute(Pchar, "cell15") && Pchar.cell15 == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.boxname == "box19")
			{
				if(CheckAttribute(Pchar, "cell19") && Pchar.cell19 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else 
				{
					if(CheckAttribute(Pchar, "cell19") && Pchar.cell19 == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.boxname == "box2")
			{
				if(CheckAttribute(Pchar, "cell2") && Pchar.cell2 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else 
				{
					if(CheckAttribute(Pchar, "cell2") && Pchar.cell2 == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum    = 1;
			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum    = 0;
			if(Pchar.boxname == "box21" || Pchar.boxname == "box34" || Pchar.boxname == "box35") 
				IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box16" || Pchar.boxname == "box18" || Pchar.boxname == "box20"
			|| Pchar.boxname == "box25" || Pchar.boxname == "box26" || Pchar.boxname == "box27"
			|| Pchar.boxname == "box28" || Pchar.boxname == "box29" || Pchar.boxname == "box32"
			|| Pchar.boxname == "box33" || Pchar.boxname == "box4" || Pchar.boxname == "box10"
			|| Pchar.boxname == "box14")
				IActions.ActiveActions.OpenBox.IconNum    = 63;
		}

		if(Pchar.location == "Antigua_port") 
		{
			if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 0;
			if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 63;
		}

		if(Pchar.location == "BB_prison_port")
		{
			if(Pchar.boxname == "box1") 
			{
				if(CheckAttribute(Pchar, "quest.prison_pier") && Pchar.quest.prison_pier == "phase6")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}
			
			if(Pchar.boxname == "box3") 
			{
				if(CheckAttribute(Pchar, "quest.prison_bridge") && Pchar.quest.prison_bridge == "start")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}

			if(Pchar.boxname == "box4") 
			{
				if(CheckAttribute(Pchar, "quest.prison_bridge") && Pchar.quest.prison_bridge == "end")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}

			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 54;
			if(Pchar.boxname == "box5" || Pchar.boxname == "box7" || Pchar.boxname == "box8") 
				IActions.ActiveActions.OpenBox.IconNum    = 63;
			if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 54;
		}

		if(Pchar.location == "BB_prison_elevator")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 2;
			
			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar, "quest.prison_elevator") && Pchar.quest.prison_elevator == "down")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.boxname == "box4")
			{
				if(CheckAttribute(Pchar, "quest.prison_elevator") && Pchar.quest.prison_elevator == "up")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;
			}
		}

		if(Pchar.location == "BB_prison_alcove")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
			|| Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 63;
			if(Pchar.boxname == "box4")
			{
				if(CheckAttribute(Pchar, "alcove.rope") && Pchar.alcove.rope == "at_gibbet")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"raft_ropes"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}
			if(Pchar.boxname == "box6")
			{
				if(CheckCharacterItem(Pchar,"bladeboom"))
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}
			if(Pchar.boxname == "box8") 
			{
				if(CheckCharacterItem(Pchar,"key3"))
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;
			}
		}

		if(Pchar.location == "BB_prison2")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box4" || Pchar.boxname == "box5" 
			|| Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 1;
			if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum    = 0;
			if(Pchar.boxname == "box1") 
			{
				if(CheckAttribute(Pchar, "P2_cell1") && Pchar.P2_cell1 == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else 
				{
					if(CheckCharacterItem(Pchar,"key38"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}
			if(Pchar.boxname == "box3") 
			{
				if(CheckAttribute(Pchar, "P2_cell2") && Pchar.P2_cell2 == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"key38"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				if(CheckAttribute(Pchar, "P2_cell2_special") && Pchar.P2_cell2_special == "locked_for_ever")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}
			if(Pchar.boxname == "box7") 
			{
				if(CheckAttribute(Pchar, "prison2.water") && Pchar.prison2.water == "slow")	
				{	
					IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
				if(CheckAttribute(Pchar, "prison2.water") && Pchar.prison2.water == "empty")	
				{	
					if(CheckAttribute(Pchar, "P2_hatch") && Pchar.P2_hatch == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else
					{
						if(CheckCharacterItem(Pchar,"key38"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
					}
				}
			}
			if(Pchar.boxname == "box9") 
			{
				if(IsEquipCharacterByItem(Pchar, "bladehammer") || IsEquipCharacterByItem(Pchar, "bladesaw") || IsEquipCharacterByItem(Pchar, "bladeaxe4"))
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3; 
			} 
			if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 30; 
			if(Pchar.boxname == "box11") 
			{
				if(CheckAttribute(Pchar, "P2_chest") && Pchar.P2_chest == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
				else 
				{
					if(CheckCharacterItem(Pchar,"key38"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}
			if(Pchar.boxname == "box12" || Pchar.boxname == "box13")  IActions.ActiveActions.OpenBox.IconNum    = 1;
		}

		if(Pchar.location == "BB_prison_officer")
		{
			if(Pchar.boxname == "box11" || Pchar.boxname == "box12" || Pchar.boxname == "box13") 
				IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 63;	
			if(Pchar.boxname == "box5")
			{
				if(CheckAttribute(Pchar, "mapBB5") && Pchar.mapBB5 == "picked_up")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;	
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 29;	
			}		 
		}

		if(Pchar.location == "Grand_Cayman_townhall")
		{
			if(Pchar.boxname == "box1") 
			{
				if(CheckAttribute(Pchar,"Cayman_box1") && Pchar.Cayman_box1 == "unlocked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;				
			}		
		}

		if(Pchar.location == "Grand_Cayman_town")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;
		}

		if(Pchar.location == "BB_Eden_estate")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box21" || Pchar.boxname == "box22"
			|| Pchar.boxname == "box23" || Pchar.boxname == "box24" || Pchar.boxname == "box25"
			|| Pchar.boxname == "box26" || Pchar.boxname == "box5" || Pchar.boxname == "box6"
			|| Pchar.boxname == "box7" || Pchar.boxname == "box8" || Pchar.boxname == "box9"	
			|| Pchar.boxname == "box10")  IActions.ActiveActions.OpenBox.IconNum    = 63;

			if(Pchar.boxname == "box1" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box13")  IActions.ActiveActions.OpenBox.IconNum  	= 1;

			if(Pchar.boxname == "box14" || Pchar.boxname == "box15" || Pchar.boxname == "box16"
			|| Pchar.boxname == "box17" || Pchar.boxname == "box18" || Pchar.boxname == "box19"
			|| Pchar.boxname == "box20")  IActions.ActiveActions.OpenBox.IconNum    = 29;
		}

		if(Pchar.location == "BB_Teach_drawing_room")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 1;
		}

		if(Pchar.location == "BB_Eden_chapel")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;
		}

		if(Pchar.location == "BB_Eden_tunnel")
		{
			if(Pchar.boxname == "box3" || Pchar.boxname == "box5" || Pchar.boxname == "box6"
			|| Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box8" || Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 0;
		}

		if(Pchar.location == "BB_careen_shore")
		{
			IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum  	= 62;
			if(Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum  	= 58;
			if(Pchar.boxname == "box15") IActions.ActiveActions.OpenBox.IconNum  	= 2;
			if(Pchar.boxname == "box12")
			{
				if(CheckAttribute(Pchar, "careen_running") && Pchar.careen_running == "started")
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 3;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 63;
			}	
		}

		if(Pchar.location == "BB_careen_blockhouse")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 0;
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}
//JRH Kristiania
		if(Pchar.location == "Kristiania_center")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 0;
		}

		if(Pchar.location == "Kristiania_port")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3") 
				IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum  	= 5;
			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum  	= 1;
		}

		if(Pchar.location == "Kristiania_shipyard")
		{
			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar, "KR_shipyard") && Pchar.KR_shipyard == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 1;
			}
		}

		if(Pchar.location == "Kristiania_shipwreck")
		{
			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum  	= 5;
		}

		if(Pchar.location == "Kristiania_cathedral") 
		{
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 60;
		}

		if(Pchar.location == "Nueva_Suecia_upper_town")
		{
			IActions.ActiveActions.OpenBox.IconNum  	= 63;

			if(Pchar.boxname == "box33") 
			{
				IActions.ActiveActions.OpenBox.IconNum  	= 0;
			}
			
			if(Pchar.boxname == "box1") 
			{
				if(CheckCharacterItem(Pchar,"key35"))
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 0;
			}

			if(Pchar.boxname == "box34" || Pchar.boxname == "box35")  IActions.ActiveActions.OpenBox.IconNum  	= 2;
		}

		if(Pchar.location == "Nueva_Suecia_hidden_town") IActions.ActiveActions.OpenBox.IconNum    = 63;

		if(Pchar.location == "Nueva_Suecia_lower_town")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 0;
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box5" || Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 63;
			if(Pchar.boxname == "box7")
			{
				if(CheckAttribute(Pchar, "NS_low_bell"))
				{
					if(Pchar.NS_low_bell == "on" || Pchar.NS_low_bell == "ready")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 57;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}
			if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum  	= 0;
		}

		if(Pchar.location == "Kristiania_jungle_house") IActions.ActiveActions.OpenBox.IconNum  	= 63;

		if(Pchar.location == "Redhouse_room")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 62;
		}
//BB tower
		if(Pchar.location == "BB_island1")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar, "quest.BB_isl1_ladder") && Pchar.quest.BB_isl1_ladder == "way_up")
				IActions.ActiveActions.OpenBox.IconNum  	= 1;

				if(CheckAttribute(Pchar, "quest.BB_isl1_ladder") && Pchar.quest.BB_isl1_ladder == "way_down")
				IActions.ActiveActions.OpenBox.IconNum  	= 63;

				if(CheckAttribute(Pchar, "quest.BB_isl1_ladder") && Pchar.quest.BB_isl1_ladder == "temp_off")
				IActions.ActiveActions.OpenBox.IconNum  	= 3;
			}
			if(Pchar.boxname == "box4")
			{
				if(CheckCharacterItem(Pchar,"bladeBB"))
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 0;
			}
			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum  	= 4;
		}

		if(Pchar.location == "BB_island2")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box5")
				{IActions.ActiveActions.OpenBox.IconNum  	= 63;}
			if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum  	= 1;
			if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum  	= 2;
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum  	= 3;

			if(Pchar.boxname == "box4")
			{
				if(IsEquipCharacterByItem(pchar, "bladeflag_pir") || IsEquipCharacterByItem(pchar, "bladeflag_pir2")
				|| IsEquipCharacterByItem(pchar, "bladeflag_HOL") || IsEquipCharacterByItem(pchar, "bladeflag_ENG")	
				|| IsEquipCharacterByItem(pchar, "bladeflag_FRA") || IsEquipCharacterByItem(pchar, "bladeflag_POR")
				|| IsEquipCharacterByItem(pchar, "bladeflag_SPA") || IsEquipCharacterByItem(pchar, "bladeflag_PRE")
				|| IsEquipCharacterByItem(pchar, "bladeflag_IRE") || IsEquipCharacterByItem(pchar, "bladeflag_SWE")
				|| IsEquipCharacterByItem(pchar, "bladeflag_HOL2") || IsEquipCharacterByItem(pchar, "bladeflag_AME")	
				|| IsEquipCharacterByItem(pchar, "bladeflag_SPA2"))
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 2;	
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 63;
			}
		}

		if(Pchar.location == "BB_tower")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 29;
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum  	= 1;
		}

		if(Pchar.location == "BB_upper_cave")
		{
			IActions.ActiveActions.OpenBox.IconNum  	= 63;

			if(Pchar.boxname == "box10" || Pchar.boxname == "box11" || Pchar.boxname == "box12") 
				{IActions.ActiveActions.OpenBox.IconNum  	= 2;}
			
			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum  	= 3;
			if(Pchar.boxname == "box9" || Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum  	= 5;
			if(Pchar.boxname == "box7")
			{
				if(CheckAttribute(Pchar, "quest.grotto_lever"))
				{
					if(Pchar.quest.grotto_lever == "up" || Pchar.quest.grotto_lever == "down")
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;
					}
				}
				else 
				{
					if(CheckCharacterItem(Pchar,"bladelever3")) IActions.ActiveActions.OpenBox.IconNum  	= 2;
				}
			}
		}

		if(Pchar.location == "BB_lower_cave")
		{
			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum  	= 30;
		}
//pär
		if(Pchar.location == "BB_burning_cave")
		{
			
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 2;
			if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum  	= 3;
			if(Pchar.boxname == "box10" || Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum  	= 1;
			if(Pchar.boxname == "box1" || Pchar.boxname == "box4" || Pchar.boxname == "box6"
			|| Pchar.boxname == "box9") {IActions.ActiveActions.OpenBox.IconNum  	= 29;}

			if(Pchar.boxname == "box3")
			{
				if(Locations[FindLocation("BB_burning_cave")].models.always.locators == "locator")
				{
					if(CheckCharacterItem(Pchar,"bladechair"))
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum  	= 3;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 63;
			}
			if(Pchar.boxname == "box5")
			{
				switch(Locations[FindLocation("BB_burning_cave")].models.always.locators)
				{
					case "locator1_chair":
						if(CheckCharacterItem(Pchar,"bladeladder2"))
						{
							IActions.ActiveActions.OpenBox.IconNum  	= 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum  	= 3;	
					break;

					case "locator2_ladder":
						IActions.ActiveActions.OpenBox.IconNum  	= 63;
					break;

					case "locator3_GD_open":
						IActions.ActiveActions.OpenBox.IconNum  	= 63;
					break;

					IActions.ActiveActions.OpenBox.IconNum  	= 3;	//all other cases
				}
			}
			if(Pchar.boxname == "box7")
			{
				switch(Locations[FindLocation("BB_burning_cave")].models.always.locators)
				{
					case "locator6_chair_ladder":
						IActions.ActiveActions.OpenBox.IconNum  	= 63;
					break;

					case "locator5_chair":
						IActions.ActiveActions.OpenBox.IconNum  	= 2;
					break;

					case "locator4_ladder_wrong":
						if(CheckCharacterItem(Pchar,"bladechair"))
						{
							IActions.ActiveActions.OpenBox.IconNum  	= 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum  	= 63;
					break;

					case "locator3_GD_open":
						if(CheckAttribute(Pchar, "hell_gate5") && Pchar.hell_gate5 == "search_gift")
						{
							if(CheckCharacterItem(Pchar,"bladeladder2"))
							{
								IActions.ActiveActions.OpenBox.IconNum  	= 2;
							}
							else IActions.ActiveActions.OpenBox.IconNum  	= 3;
						}
						else IActions.ActiveActions.OpenBox.IconNum  	= 3;
					break;

					IActions.ActiveActions.OpenBox.IconNum  	= 3;	//all other cases
				}
			}
		}

		if(Pchar.location == "BB_isle")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 5;
			if(Pchar.boxname == "box2")
			{
				if(CheckAttribute(Pchar, "isle.chimney") && Pchar.isle.chimney == "logbook")
				{
					IActions.ActiveActions.OpenBox.IconNum  	= 62;
				}
				else IActions.ActiveActions.OpenBox.IconNum  	= 4;							
			}
		}

		if(Pchar.location == "BB_isle_hut")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box8") 
			{
				IActions.ActiveActions.OpenBox.IconNum  	= 29;
			}
			else IActions.ActiveActions.OpenBox.IconNum  	= 63;
		}


//=================================================================================================================
//part 1
		
		if(Pchar.location == "bb_prison")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box15" || Pchar.boxname == "box16" || Pchar.boxname == "box17"
			|| Pchar.boxname == "box18") IActions.ActiveActions.OpenBox.IconNum  	= 0;
			if(Pchar.boxname == "box14" || Pchar.boxname == "box21")  IActions.ActiveActions.OpenBox.IconNum  = 63;
		}


		if(Pchar.location == "mutiny_deckWR")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum  	= 63;
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum  	= 5;
		}

		if(Pchar.location == "swamp_island1")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
			|| Pchar.boxname == "box12")
				{IActions.ActiveActions.OpenBox.IconNum	= 3;}
			if( Pchar.boxname == "box4" || Pchar.boxname == "box5" || Pchar.boxname == "box6"
			|| Pchar.boxname == "box11")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			if(Pchar.boxname == "box7" || Pchar.boxname == "box8" || Pchar.boxname == "box10")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum  	= 5;
		}

		if(Pchar.location == "swamp_island2")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box11" || Pchar.boxname == "box12" || Pchar.boxname == "box13" || Pchar.boxname == "box14"
			|| Pchar.boxname == "box15" || Pchar.boxname == "box18")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			if(Pchar.boxname == "box5" || Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 61;}
			if( Pchar.boxname == "box7" || Pchar.boxname == "box8" || Pchar.boxname == "box9"
			|| Pchar.boxname == "box10" || Pchar.boxname == "box17")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box16") IActions.ActiveActions.OpenBox.IconNum  	= 3;
			if(Pchar.boxname == "box19") IActions.ActiveActions.OpenBox.IconNum  	= 5;
		}

		if(Pchar.location == "swamp_wreck_inside")
		{
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
		}

		if(Pchar.location == "Swamp_grot") IActions.ActiveActions.OpenBox.IconNum   	= 30;

		if(Pchar.location == "QC_town")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box8")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum  	= 1;
		}

		if(Pchar.location == "QC_store_JRH")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
		}

		if(Pchar.location == "QC_shipyard2_JRH")
		{
			if(Pchar.boxname == "box2")
			{
				if(CheckAttribute(Pchar,"quest.shya_box2") && Pchar.quest.shya_box2 == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.shya_box2") && Pchar.quest.shya_box2 == "unlocked_but_stuck")
					{
						if(IsEquipCharacterByItem(Pchar, "tool3"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else
					{
						if(CheckCharacterItem(Pchar,"key2"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 29;
					}
				}
			}

			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar,"quest.shya_posE"))
				{
					if(Pchar.quest.shya_posE == "chest")
					{
						if(CheckAttribute(Pchar,"quest.shya_box3") && Pchar.quest.shya_box3 == "free_key")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else
						{
							if(CheckAttribute(Pchar,"quest.shya_box3") && Pchar.quest.shya_box3 == "open")
							{
								IActions.ActiveActions.OpenBox.IconNum    = 29;
							}
						}
						else
						{
							if(CheckCharacterItem(Pchar,"key4"))
							{
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
							else IActions.ActiveActions.OpenBox.IconNum    = 29;
						}
					}
				}
			}

			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box5")
			{
				if(CheckAttribute(Pchar,"quest.shya_box5") && Pchar.quest.shya_box5 == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"key1"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
			}

			if(Pchar.boxname == "box6")
			{
				if(CheckAttribute(Pchar,"quest.shya_box6") && Pchar.quest.shya_box6 == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
				else
				{
					if(IsEquipCharacterByItem(Pchar, "blade4"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
			}

			if(Pchar.boxname == "box7")
			{
				if(CheckAttribute(Pchar,"quest.shya_posJ") && Pchar.quest.shya_posJ == "blocked")
				{
					if(IsEquipCharacterByItem(Pchar, "tool2"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}

			if(Pchar.boxname == "box9")
			{
				if(CheckAttribute(Pchar,"quest.shya_beam"))
				{
					if(Pchar.quest.shya_beam == "middle")
					{
						if(CheckAttribute(Pchar,"quest.shya_barrel2") && Pchar.quest.shya_barrel2 == "taken")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 3;
					}
				}
			}

			if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box11")
			{
				if(CheckAttribute(Pchar,"quest.shya_barrel1") && Pchar.quest.shya_barrel1 == "taken")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}

			if(Pchar.boxname == "box12")
			{
				if(CheckAttribute(Pchar,"quest.shya_box12") && Pchar.quest.shya_box12 == "unlocked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"key3"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}

			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box14")
			{
				if(CheckAttribute(Pchar,"quest.shya_box14") && Pchar.quest.shya_box14 == "free_key")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.shya_box14") && Pchar.quest.shya_box14 == "unlocked")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
				}
				else
				{
					if(CheckCharacterItem(Pchar,"key4"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}

			if(Pchar.boxname == "box15")
			{
				if(CheckAttribute(Pchar,"quest.shya_posK") && Pchar.quest.shya_posK == "locked")
				{
					if(IsEquipCharacterByItem(Pchar, "tool1"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}

				if(CheckAttribute(Pchar,"quest.shya_posK") && Pchar.quest.shya_posK == "blocked")
				{
					if(IsEquipCharacterByItem(Pchar, "tool5"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
			}

			if(Pchar.boxname == "box18")
			{
				if(CheckAttribute(Pchar,"quest.shya_beam"))
				{
					if(Pchar.quest.shya_beam == "left")
					{
						if(CheckAttribute(Pchar,"quest.shya_box9") && Pchar.quest.shya_box9 == "open")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 29;
						}
						else
						{
							if(IsEquipCharacterByItem(Pchar, "blade5"))
							{
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
							else IActions.ActiveActions.OpenBox.IconNum    = 3;
						}
					}
				}
			}

			if(Pchar.boxname == "box19")
			{
				if(CheckAttribute(Pchar,"quest.shya_posE"))
				{
					if(Pchar.quest.shya_posE == "blocked")
					{
						if(IsEquipCharacterByItem(Pchar, "tool6"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
				}
			}
		}

		if(Pchar.location == "Tavern_storeroom")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 2;
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}
		}

		if(Pchar.location == "JRH_tavern_upstairs")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
		}

		if(Pchar.location == "wr_bedroom")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_residence")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 62;}
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum	= 63;
		}

		if(Pchar.location == "wr_kitchen")
		{
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
		}

		if(Pchar.location == "wr_booty")
		{
			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum	= 1;
			if(Pchar.boxname == "box4")
			{
				if(CheckAttribute(Pchar,"quest.Friday_room") && Pchar.quest.Friday_room == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
		}

		if(Pchar.location == "wr_armory")
		{
			if(CheckAttribute(Pchar,"boxname") && Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar,"quest.wr_quest1"))
				{
					if(Pchar.quest.wr_quest1 == "pistol2" || Pchar.quest.wr_quest1 == "blade_found")
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
				}
				return;
			}
		}

		if(Pchar.location == "Redmond_UsurerHouse")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}
		}

		if(Pchar.location == "wr_gunpowder")
		{
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum	= 7;
		}

		if(Pchar.location == "wr_shop")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box4")
			{
				if(CheckCharacterItem(Pchar,"key8"))
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
		}

		if(Pchar.location == "Redmond_tavern")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}
		}

		if(Pchar.location == "Dave_Edna_room")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
		}

		if(Pchar.location == "wr_mother")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_library")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box5"
			|| Pchar.boxname == "box6" || Pchar.boxname == "box12" || Pchar.boxname == "box13" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box1" || Pchar.boxname == "box10" || Pchar.boxname == "box11")
				{IActions.ActiveActions.OpenBox.IconNum	= 62;}

			if(Pchar.boxname == "box8" || Pchar.boxname == "box9")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box14")
			{
				if(CheckAttribute(Pchar,"quest.seabattles_enable") && Pchar.quest.seabattles_enable == "yes")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 63;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}

			if(Pchar.boxname == "box15")
			{
				if(CheckAttribute(Pchar,"quest.erotica_enable") && Pchar.quest.erotica_enable == "yes")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 63;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
		}

		if(Pchar.location == "wr_gunroom")
		{
			if( Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}

			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum	= 63;
		}

		if(Pchar.location == "wr_study")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 62;}

			if(Pchar.boxname == "box7")
			{
				if(CheckAttribute(Pchar,"quest.study_counter") && Pchar.quest.study_counter == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 29;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"key17"))
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum	= 29;
					}
				}
			}

			if( Pchar.boxname == "box8")
			{
				if(CheckAttribute(Pchar,"quest.study_lever2") && Pchar.quest.study_lever2 == "missing")
				{
					if(CheckCharacterItem(Pchar,"bladelever"))
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum	= 3;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 2;
			}

			if( Pchar.boxname == "box9")
			{
				if(CheckAttribute(Pchar,"quest.study_lever3") && Pchar.quest.study_lever3 == "missing")
				{
					if(CheckCharacterItem(Pchar,"bladelever"))
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum	= 3;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 2;
			}

			if( Pchar.boxname == "box10")
			{
				if(CheckAttribute(Pchar,"quest.study_lever1") && Pchar.quest.study_lever1 == "missing")
				{
					if(CheckCharacterItem(Pchar,"bladelever"))
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum	= 3;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 2;
			}

			if( Pchar.boxname == "box11")
			{
				if(CheckAttribute(Pchar,"quest.study_lever4") && Pchar.quest.study_lever4 == "missing")
				{
					if(CheckCharacterItem(Pchar,"bladelever"))
					{
						IActions.ActiveActions.OpenBox.IconNum	= 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum	= 3;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 2;
			}

			if( Pchar.boxname == "box12" || Pchar.boxname == "box13" || Pchar.boxname == "box14" || Pchar.boxname == "box15")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}

			if(Pchar.boxname == "box16") IActions.ActiveActions.OpenBox.IconNum	= 30;
		}

		if(Pchar.location == "Redmond_town_01")
		{
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10" || Pchar.boxname == "box11"
			|| Pchar.boxname == "box12")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
		}

		if(Pchar.location == "wr_food_supply")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 10;
			if(Pchar.boxname == "box2" || Pchar.boxname == "box7")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(CheckAttribute(Pchar,"quest.mine_enabled") && Pchar.quest.mine_enabled == "yes")
			{
				if(Pchar.boxname == "box10" || Pchar.boxname == "box11")
					{IActions.ActiveActions.OpenBox.IconNum	= 1;}
			}
			else
			{
				if(Pchar.boxname == "box10" || Pchar.boxname == "box11")
					{IActions.ActiveActions.OpenBox.IconNum	= 0;}
			}

			if(Pchar.boxname == "box12") IActions.ActiveActions.OpenBox.IconNum	= 63;
		}

		if(Pchar.location == "wr_crew")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box5" || Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}
			if(Pchar.boxname == "box7" || Pchar.boxname == "box8")
				{IActions.ActiveActions.OpenBox.IconNum	= 0;}
		}

		if(Pchar.location == "wr_mine")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
		}

		if(Pchar.location == "wr_mine_control")
		{
			IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_prison")
		{
			if(Pchar.boxname == "box3")
			{
				if(CheckCharacterItem(Pchar,"bladepickaxe2"))
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 3;
			}

			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box4"
			|| Pchar.boxname == "box5" || Pchar.boxname == "box7")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box10" || Pchar.boxname == "box11" || Pchar.boxname == "box12")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			if(Pchar.boxname == "box6")
			{
				if(CheckAttribute(Pchar,"quest.prison_barrel4") && Pchar.quest.prison_barrel4 == "ready_to_remove_plank_from_wall")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 29;
			}
			if(Pchar.boxname == "box8" || Pchar.boxname == "box9")
			{
				if(CheckAttribute(Pchar,"quest.prison_celldoor") && Pchar.quest.prison_celldoor == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
		}

		if(Pchar.location == "wr_gibbet")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 2;
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 30;

			if(Pchar.boxname == "box3")
			{
				if(CheckCharacterItem(Pchar,"bladesaw"))
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 3;
			}
		}

		if(Pchar.location == "wr_cavern") IActions.ActiveActions.OpenBox.IconNum	= 2;

		if(Pchar.location == "wr_church_inside")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 60;
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 2;
			if(Pchar.boxname == "box3" || Pchar.boxname == "box4")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
		}

		if(Pchar.location == "wr_church_outside") IActions.ActiveActions.OpenBox.IconNum = 63;

		if(Pchar.location == "wr_church_attic") IActions.ActiveActions.OpenBox.IconNum	= 63;

		if(Pchar.location == "Redmond_shore_02") IActions.ActiveActions.OpenBox.IconNum	= 63;

		if(Pchar.location == "wr_cannon_tower")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 7;
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}

			if(Pchar.boxname == "box5")
			{
				if(CheckAttribute(Pchar,"quest.wt3_musket") && Pchar.quest.wt3_musket == "picked_up")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 3;
			}
		}

		if(Pchar.location == "wr_animists")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
			|| Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box16" || Pchar.boxname == "box17")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			if(Pchar.boxname == "box9" || Pchar.boxname == "box11" || Pchar.boxname == "box13"
			|| Pchar.boxname == "box15")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}
			if(Pchar.boxname == "box8")
			{
				if(CheckAttribute(Pchar,"quest.mandala_position") && Pchar.quest.mandala_position == "2")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
			if(Pchar.boxname == "box10")
			{
				if(CheckAttribute(Pchar,"quest.mandala_position") && Pchar.quest.mandala_position == "3")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
			if(Pchar.boxname == "box12")
			{
				if(CheckAttribute(Pchar,"quest.mandala_position") && Pchar.quest.mandala_position == "4")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
			if(Pchar.boxname == "box14")
			{
				if(CheckAttribute(Pchar,"quest.mandala_position") && Pchar.quest.mandala_position == "5")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 0;
			}
		}

		if(Pchar.location == "Shipyard_docks") IActions.ActiveActions.OpenBox.IconNum = 63;

		if(Pchar.location == "defoes_cabin")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
			|| Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 62;}
		}

		if(Pchar.location == "wr_farm_booty")
		{
			if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_farm_booty2")
		{
			if(Pchar.boxname == "box5") 
			{
				if(CheckCharacterItem(Pchar,"bladebottle_BAU"))
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 3;
			}
		}

		if(Pchar.location == "wr_farm_bedroom") 
		{
			if(Pchar.boxname == "box5")
			{
				if(CheckCharacterItem(Pchar,"Key17"))
				{			
					IActions.ActiveActions.OpenBox.IconNum = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum = 29;
			}
			else IActions.ActiveActions.OpenBox.IconNum = 2;
		}

		if(Pchar.location == "wr_farm_corridor") IActions.ActiveActions.OpenBox.IconNum = 2;

		if(Pchar.location == "wr_farm_servant")
		{
			if(Pchar.boxname == "box2")
			{
				IActions.ActiveActions.OpenBox.IconNum	= 62;
			}
			else IActions.ActiveActions.OpenBox.IconNum = 2;
		}

		if(Pchar.location == "wr_farm_alchemy")
		{
			if(Pchar.boxname == "box3")
			{
				IActions.ActiveActions.OpenBox.IconNum    = 59;
			}
			else
			{
				if(Pchar.boxname != "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;
			}
		}

		if(Pchar.location == "wr_farm_alchemy2")
		{
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5"
			|| Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box11"
			|| Pchar.boxname == "box12" || Pchar.boxname == "box13" || Pchar.boxname == "box14"
			|| Pchar.boxname == "box7" || Pchar.boxname == "box15" || Pchar.boxname == "box16"
			|| Pchar.boxname == "box17" || Pchar.boxname == "box18")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}

			if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum	= 63;	

			if(Pchar.boxname == "box6") 
			{
				if(CheckCharacterItem(Pchar,"bladebottle_BAU"))
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 3;
			}	
		}

		if(Pchar.location == "wr_ships" || Pchar.location == "wr_corvette")
		{
			if(Pchar.boxname == "box8")
			{
				if(CheckAttribute(Pchar,"quest.anchor_mechanism") && Pchar.quest.anchor_mechanism == "complete")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 25;
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.anchor") && Pchar.quest.anchor == "up")
					{
						IActions.ActiveActions.OpenBox.IconNum	= 25;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
			}
			else
			{
				if(Pchar.boxname == "box9")
				{
					if(CheckAttribute(Pchar,"quest.anchor_mechanism") && Pchar.quest.anchor_mechanism == "complete")
					{
						IActions.ActiveActions.OpenBox.IconNum	= 25;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
			}
			else
			{
				if(Pchar.boxname == "box18" || Pchar.boxname == "box19" || Pchar.boxname == "box20"
				|| Pchar.boxname == "box15" || Pchar.boxname == "box16" || Pchar.boxname == "box17")
					{IActions.ActiveActions.OpenBox.IconNum	= 63;}
			}
			else
			{
				if(Pchar.boxname == "box21" || Pchar.boxname == "box22")
					{IActions.ActiveActions.OpenBox.IconNum	= 61;}
			}
			else
			{
				if(Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7")
					{IActions.ActiveActions.OpenBox.IconNum	= 58;}
			}
			else
			{
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum	= 57;
			}
			else
			{
				if(Pchar.boxname == "box23")
				{
					if(CheckAttribute(Pchar,"quest.anchor") && Pchar.quest.anchor == "up")
					{
						IActions.ActiveActions.OpenBox.IconNum = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum	= 3;
				}
			}
			else
			{
				if(Pchar.boxname == "box24") IActions.ActiveActions.OpenBox.IconNum	= 3;
			}
			else IActions.ActiveActions.OpenBox.IconNum = 2;
		}

		if(Pchar.location == "wr_gall_qdeck")
		{
			if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_gall_hold_first")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}
			if(Pchar.boxname == "box4" || Pchar.boxname == "box5" || Pchar.boxname == "box6")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}

			if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum	= 0;
		}

		if(Pchar.location == "wr_gall_hold_second")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 63;
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum 	= 2;
		}

		if(Pchar.location == "wr_gall_deck2_prow") IActions.ActiveActions.OpenBox.IconNum = 2;

		if(Pchar.location == "wr_gall_deck2_stern")
		{
			if(Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box11")
			{
				IActions.ActiveActions.OpenBox.IconNum	= 2;
			}
			else
			{
				if(Pchar.boxname == "box12") IActions.ActiveActions.OpenBox.IconNum	= 63;
			}
			else IActions.ActiveActions.OpenBox.IconNum	= 3;
		}

		if(Pchar.location == "wr_gall_cap_inner")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 3;
		}

		if(Pchar.location == "wr_gall_captain")
		{
			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar,"quest.gall_captain") && Pchar.quest.gall_captain == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 3;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 2;
			}
		}

		if(Pchar.location == "wr_corv_smallcabin_L")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 63;
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum	= 2;
		}

		if(Pchar.location == "wr_corv_smallcabin_R")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 63;
		}

		if(Pchar.location == "wr_corv_deck1")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4")
				IActions.ActiveActions.OpenBox.IconNum    = 63;
		}

		if(Pchar.location == "wr_corv_crew")
		{
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box4")
			{
				if(CheckAttribute(Pchar,"quest.crew_to_ships") && Pchar.quest.crew_to_ships == "closed")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}
		}

		if(Pchar.location == "wr_corv_capmd")
		{
			if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 63;
		}

		if(Pchar.location == "wr_corv_capsm")
		{
			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 2;
			if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 63;
			if(Pchar.boxname == "box3")
			{
				if(CheckCharacterItem(Pchar,"bladebarrel2"))
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}
		}

		if(Pchar.location == "wr_wine_cellar") IActions.ActiveActions.OpenBox.IconNum    = 2;

		if(Pchar.location == "church_wine_cellar")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
			|| Pchar.boxname == "box4" || Pchar.boxname == "box5" || Pchar.boxname == "box6"
			|| Pchar.boxname == "box7" || Pchar.boxname == "box13")
				{IActions.ActiveActions.OpenBox.IconNum	= 2;}

			if(Pchar.boxname == "box17" || Pchar.boxname == "box19") IActions.ActiveActions.OpenBox.IconNum    = 1;

			if(Pchar.boxname == "box14" || Pchar.boxname == "box15" || Pchar.boxname == "box16"
			|| Pchar.boxname == "box18")
			{
				if(Locations[FindLocation(Pchar.location)].models.always.locators == "cwc_dry_final")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;
			}
		}

		if(Pchar.location == "church_choir")
		{
			if(Pchar.boxname == "box6" || Pchar.boxname == "box14" || Pchar.boxname == "box15")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}

			if(Pchar.boxname == "box7" || Pchar.boxname == "box11" || Pchar.boxname == "box12")
				{IActions.ActiveActions.OpenBox.IconNum	= 62;}



			if(Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box13"
			|| Pchar.boxname == "box16")
				{IActions.ActiveActions.OpenBox.IconNum	= 56;}

			if(Pchar.boxname == "box18" || Pchar.boxname == "box19")
				{IActions.ActiveActions.OpenBox.IconNum	= 1;}

			if(Pchar.boxname == "box2")
			{
				switch(Pchar.quest.choir_ladder)
				{
					case "not_found":
						//Logit(TranslateString("","The lock is too rusty - I can't move the key."));
						IActions.ActiveActions.OpenBox.IconNum	= 29;
					break;

					case "found":
						if(IsEquipCharacterByItem(Pchar, "bladeladder"))
						{
							if(LAi_IsFightMode(Pchar))
							{
								//this is your 2:nd 'open box'
								//LAi_QuestDelay("place_ladder_choir_box2", 1.0);
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
							else
							{
								//ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck2");
								//LAi_SetFightMode(chr, true);
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
						}
						else
						{
							//Logit(TranslateString("","The lock is too rusty - I can't move the key."));
							IActions.ActiveActions.OpenBox.IconNum	= 29;
						}
					break;

					case "placed":
						//later when ladder is placed
						//ChangeCharacterAddressGroup(chr, "church_choir", "goto", "ladder1");
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					break;

					case "oilbottle":
						if(IsEquipCharacterByItem(Pchar, "bladeoilbottle"))
						{
							if(LAi_IsFightMode(Pchar))
							{
								//this is your 2:nd 'open box'
								//PlaySound("PEOPLE\oil_unlock.wav");
								IActions.ActiveActions.OpenBox.IconNum    = 2;

							}
							else
							{
								//ChangeCharacterAddressGroup(Pchar, "church_choir", "goto", "stuck2");
								//LAi_SetFightMode(Pchar, true);
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
						}
						else
						{
							//ChangeCharacterAddressGroup(Pchar, "church_choir", "goto", "ladder1");
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
					break;

					case "blocking":
						if(LAi_IsFightMode(Pchar))
						{
							//this is your 2:nd 'open box'
							//GiveItem2Character(chr, "bladeladder");
							//EquipCharacterbyItem(chr, "bladeladder");
							//LAi_QuestDelay("remove_ladder_choir_box2", 0.5);
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else
						{
							//ChangeCharacterAddressGroup(chr, "church_choir", "goto", "stuck2");
							//LAi_SetFightMode(chr, true);
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
					break;

					case "open_chest":
						//LaunchItemsBox(&ar);
						IActions.ActiveActions.OpenBox.IconNum	= 29;
					break;
				}
			}

			if(Pchar.boxname == "box3")
			{
				if(CheckCharacterItem(Pchar,"PiratesDagger")) IActions.ActiveActions.OpenBox.IconNum = 2;
			}

			if(Pchar.boxname == "box4")
			{
				if(CheckCharacterItem(Pchar,"bladelockpick")) IActions.ActiveActions.OpenBox.IconNum = 2;
			}

			if(Pchar.boxname == "box5")
			{
				if(CheckCharacterItem(Pchar,"bladehandle")) IActions.ActiveActions.OpenBox.IconNum = 2;
			}

			if(Pchar.boxname == "box17")
			{
				if(CheckCharacterItem(Pchar, "bladekeygrand"))
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else
				{
					if(CheckAttribute(Pchar, "quest.choir_clock") && Pchar.quest.choir_clock == "clock_started")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 55;
					}
					else
					{
						if(CheckAttribute(Pchar, "quest.choir_clock") && Pchar.quest.choir_clock == "key_placed")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum    = 55;
					}
				}
			}
		}

		if(Pchar.location == "wr_sacristy")
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box2")
			{
				if(CheckAttribute(Pchar, "quest.votiv_lever") && Pchar.quest.votiv_lever == "F")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 0;
			}
		}

		if(Pchar.location == "wr_cave_shore")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box4")
				IActions.ActiveActions.OpenBox.IconNum    = 2;

			if(Pchar.boxname == "box5" || Pchar.boxname == "box7"
			|| Pchar.boxname == "box8" || Pchar.boxname == "box9")
				{IActions.ActiveActions.OpenBox.IconNum	= 63;}

			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar, "quest.cave_shore_red_chest") && Pchar.quest.cave_shore_red_chest == "free")
				{
					IActions.ActiveActions.OpenBox.IconNum	= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 63;
			}

			if(Pchar.boxname == "box6")
			{
				if(CheckAttribute(Pchar, "flag_knowledge") && Pchar.flag_knowledge == "yes")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 63;
			}

			if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 3;
		}

		if(Pchar.location == "wr_wood_tower2")
		{
			if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 58;
		}

		if(Pchar.location == "wr_wood_tower3")
		{
			if(Pchar.boxname == "box1")
			{
				if(CheckAttribute(Pchar,"quest.wt3_box1") && Pchar.quest.wt3_box1 == "large")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 3;
			}

			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 63;
		}
	}
//<-- JRH
}

//JRH
//from LAi_events.c
void LAi_CharacterFireExecute_WR(aref attack, aref enemy, float kDist, int isFindedEnemy)

//Logit("LAi_CharacterFireExecute_JRH");
//LogIt("2222");
	// ccc jul 05 Former LAi_CharacterFire() function minus the EventData yielded by the original targeting process
	// Shooting can now also be executed from other functions with other data
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	//ccc aref attack = GetEventData();
	//ccc aref enemy = GetEventData();
	//ccc float kDist = GetEventData();
	//ccc int isFindedEnemy = GetEventData();
	//Çàðÿä ïåðñîíàæà
	if(!CheckAttribute(attack, "chr_ai.charge")) attack.chr_ai.charge = "0";
	float charge = stf(attack.chr_ai.charge) - 1.0;
	if(charge <= 0.0)
	{
		charge = 0.0;
		attack.chr_ai.chargeprc = "1";
	}
	attack.chr_ai.charge = charge;
	//Åñëè ïðîìàõíóëèñü, òî íè÷åãî íå äåëàåì

//JRH moved up block from below
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);	// defines weaponname
	aref weapon;
	Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

	string weaponID7 = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	aref weapon7;
	Items_FindItem(weaponID7, &weapon7);

	float u, v, w;          		//JRH coordinates for effects
	GetCharacterPos(attack, &u, &v, &w);    //JRH determines position of initial target

	float x, y, z;          		//JRH revolver effect
	GetCharacterPos(enemy, &x, &y, &z);

	if(isFindedEnemy == 0)
	{
		//çäåñü ìîæíî ïîäíèìàòü òðåâîãó â ñëó÷àå áëèçêîãî âûñòðåëà

		if(CheckAttribute(weapon, "id") && weapon.id == "pistoltinderbox")
		{
			//JRH tinder box
			CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\duel\GI_ValidClick.wav");

			if(attack.location == "Legrands_kitchen")
			{
				if(CheckAttribute(attack,"quest.Legrands_fireplace"))
				{
					if(attack.quest.Legrands_fireplace == "extinct" || attack.quest.Legrands_fireplace == "unlit")
					{
						if(CheckAttribute(attack,"quest.Legrands_damper") && attack.quest.Legrands_damper == "closed")
						{
							Log_SetStringToLog(TranslateString("","You need oxygen!"));

							LAi_QuestDelay("end_of_tinderbox3", 1.0);	//hah
			//LogIt("1111");
						}
						else
						{
							Locations[FindLocation(attack.location)].models.always.locators = "mediumhouse01_locators_GB0";
							locations[FindLocation(attack.location)].models.always.l2 = "wood3";
							Locations[FindLocation("Legrands_kitchen")].image = "";
							attack.quest.Legrands_fireplace = "glowing";
					
							LAi_QuestDelay("end_of_tinderbox", 1.0);
			//LogIt("2222");
						}
					}
					else 
					{
						if(attack.quest.Legrands_fireplace == "no_wood")
						{
							Log_SetStringToLog(TranslateString("","Only ashes left - I'll need new wood!"));
							
							LAi_QuestDelay("end_of_tinderbox4", 1.0);	//sigh
			//LogIt("3333");
						}
					}
					else 
					{
						LAi_QuestDelay("end_of_tinderbox2", 1.0); 
			//LogIt("4444");
					}
				}
			}
		//	return;

			if(attack.location == "GB_chinese_charcoal")
			{
				if(CheckAttribute(attack,"quest.charcoal_tinderbox") && attack.quest.charcoal_tinderbox == "enabled")
				{
					Locations[FindLocation(attack.location)].models.always.locators = "Hut_locators_charcoal6";
					Locations[FindLocation("GB_chinese_charcoal")].image = "";
					
					LAi_QuestDelay("end_of_tinderbox_charcoal", 1.0);
				}
			}
			return;
		}

	    //JRH light fire -->
		if(attack.location == "wr_gunroom")
		{
			CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\duel\GI_ValidClick.wav");

			if(CheckAttribute(attack,"quest.rum_damper") && attack.quest.rum_damper == "closed")
			{
				Log_SetStringToLog(TranslateString("","You need oxygen!"));

				LAi_QuestDelay("gunroom_disable_fightmode", 0.5);
			}

			if(CheckAttribute(attack,"quest.rum_damper") && attack.quest.rum_damper == "half_open")
			{
				if(Locations[FindLocation(attack.location)].models.always.locators == "tavern02_locators_JRH1")
				{
					if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "wood")
		    			{
						Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH1_F";
						attack.quest.rum_fire = "lit";
						Locations[FindLocation(attack.location)].models.always.l1 = "wood_lit";

						LAi_QuestDelay("damper", 0.5);
					}
					else
					{
						if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "sack")
		    				{
							Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH1_F";
							attack.quest.rum_fire = "lit";
							Locations[FindLocation(attack.location)].models.always.l1 = "sack2_lit";

							LAi_QuestDelay("damper", 0.5);
						}
					}
					else
					{
						Log_SetStringToLog(TranslateString("","Get some wood first!"));

						LAi_QuestDelay("gunroom_disable_fightmode", 0.5);
					}
				}
			}

			if(CheckAttribute(attack,"quest.rum_damper") && attack.quest.rum_damper == "open")
			{
				if(Locations[FindLocation(attack.location)].models.always.locators == "tavern02_locators_JRH2")
				{
					if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "wood")
		    			{
						attack.quest.rum_fire = "lit";
						Locations[FindLocation(attack.location)].models.always.l1 = "wood_lit";
						Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH2_F";

						LAi_QuestDelay("damper", 0.5);
					}
					else
					{
						if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "sack")
		    				{
							//Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH1_F";//pär bad idea
							Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH2_F";
							attack.quest.rum_fire = "lit";
							Locations[FindLocation(attack.location)].models.always.l1 = "sack2_lit";

							LAi_QuestDelay("damper", 0.5);
						}
					}
					else
					{
						Log_SetStringToLog(TranslateString("","Get some wood first!"));

						LAi_QuestDelay("gunroom_disable_fightmode", 0.5);
					}
				}
			}

			if(CheckAttribute(attack,"quest.rum_damper") && attack.quest.rum_damper == "half_closed")
			{
				if(Locations[FindLocation(attack.location)].models.always.locators == "tavern02_locators_JRH1")
				{
					if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "wood")
		    			{
						attack.quest.rum_fire = "lit";
						Locations[FindLocation(attack.location)].models.always.l1 = "wood_lit";
						Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH1_F";

						LAi_QuestDelay("damper", 0.5);
					}
					else
					{
						if(CheckAttribute(attack,"quest.rum_fuel") && attack.quest.rum_fuel == "sack")
		    				{
							Locations[FindLocation(attack.location)].models.always.locators = "tavern02_locators_JRH1_F";
							attack.quest.rum_fire = "lit";
							Locations[FindLocation(attack.location)].models.always.l1 = "sack2_lit";

							LAi_QuestDelay("damper", 0.5);
						}
					}
					else
					{
						Log_SetStringToLog(TranslateString("","Get some wood first!"));

						LAi_QuestDelay("gunroom_disable_fightmode", 0.5);
					}
				}
			}

			return;
		}
		else
		{
			if(attack.location == "wr_farm_corridor")
			{
				if(Locations[FindLocation("wr_farm_corridor")].models.always.locators == "StoreSmall_locators_JRH_dark")
				{
					if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pb" || weapon.shottype == "pg")
					{
						//JRH tinder box STYLE
						CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
						CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
						PlaySound("OBJECTS\duel\GI_ValidClick.wav");

						Locations[FindLocation("wr_farm_corridor")].filespath.textures = "locations\inside\Corridor\normal";
						Locations[FindLocation("wr_farm_corridor")].models.always.locators = "StoreSmall_locators_JRH_normal";

						if(CheckAttribute(attack, "quest.scroll46") && attack.quest.scroll46 == "picked_up")
						{
							Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "keymiddle";
							attack.quest.keymiddle = "on_counter";
						}

						LAi_QuestDelay("corridor_lit", 1.0);
					}
				}
				return;
			}
		}
		else
		{
			if(attack.location == "wr_mine_control")
			{
				float Php;
				Php = LAi_GetCharacterHP(attack);
				//int Php3;
				//Php3 = Php/3;
				int Php4; int Php2;
				Php4 = Php/4; Php2 = Php/2;

				CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
				CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
				PlaySound("OBJECTS\duel\GI_ValidClick.wav");

				if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH1_G" || Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH2_G" || Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH3_G")
				{
					//Log_SetStringToLog("Reading 1");

					if(CheckAttribute(attack,"quest.torch_enable") && attack.quest.torch_enable == "no")
		    			{
						if(CheckAttribute(attack,"quest.gas_level") && attack.quest.gas_level == "3")
						{

							if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH1_G")
							{
								//Log_SetStringToLog("Reading 3");
								Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH1_F";
							}

							if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH2_G")
							{
								//Log_SetStringToLog("Reading 4");
								Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH2_F";
							}

							if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH3_G")
							{
								//Log_SetStringToLog("Reading 5");
								Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH3_F";
							}

							CreateParticleSystem("fort_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );

							PlaySound("OBJECTS\SHIPCHARGE\CR18C.wav");
							PlaySound("OBJECTS\DUEL\pistol_small2.wav");
							PlaySound("OBJECTS\DUEL\pistol_medium3.wav");

							LAi_ApplyCharacterDamage(attack, Php2);

							LAi_QuestDelay("mine_lights_fire_on_dmg2", 0.5);
						}
						else
						{
							if(CheckAttribute(attack,"quest.gas_level") && attack.quest.gas_level == "4")
								LAi_QuestDelay("boiling_explosion", 0.1);
						}
						else
						{
							Log_SetStringToLog(TranslateString("","Not a bad idea, but light the gas!"));
							//Log_SetStringToLog("Reading 6");
						}
					}
					else
					{
						//Log_SetStringToLog("Reading 2");

						if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH1_G")
						{
							//Log_SetStringToLog("Reading 3");
							Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH1_F";
						}

						if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH2_G")
						{
							//Log_SetStringToLog("Reading 4");
							Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH2_F";
						}

						if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH3_G")
						{
							//Log_SetStringToLog("Reading 5");
							Locations[FindLocation(attack.location)].models.always.locators = "d02_l_JRH3_F";
						}


						if(CheckAttribute(attack,"quest.gas_level") && attack.quest.gas_level == "4")
								LAi_QuestDelay("boiling_explosion", 0.1);

						if(CheckAttribute(attack,"quest.gas_level") && attack.quest.gas_level == "2")
						{
							PlaySound("OBJECTS\DUEL\pistol_bbus.wav");
							PlaySound("OBJECTS\DUEL\pistol_small2.wav");

							LAi_ApplyCharacterDamage(attack, Php4);

							LAi_QuestDelay("mine_lights_fire_on_dmg1", 0.5);
						}
						else
						{
							if(CheckAttribute(attack,"quest.gas_level") && attack.quest.gas_level == "3")
							{
								CreateParticleSystem("gunfire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );

								PlaySound("OBJECTS\SHIPCHARGE\CR18C.wav");
								PlaySound("OBJECTS\DUEL\pistol_small2.wav");
								PlaySound("OBJECTS\DUEL\pistol_medium3.wav");

								LAi_ApplyCharacterDamage(attack, Php2);

								LAi_QuestDelay("mine_lights_fire_on_dmg2", 0.5);
							}
						}
						else LAi_QuestDelay("mine_lights_fire_on", 0.5);
					}
				}

				if(Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH1" || Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH2" || Locations[FindLocation(attack.location)].models.always.locators == "d02_l_JRH3")
				{
					//Log_SetStringToLog("Reading 7");
					if(CheckAttribute(attack,"quest.torch_enable") && attack.quest.torch_enable == "yes")
					{
						//Log_SetStringToLog("Reading 8");
		    				Log_SetStringToLog(TranslateString("","Turn on the gas first!"));
					}
				}

				return;
			}
		}

		else
		{
			if(attack.location == "Legrands_kitchen")
			{
				//FOR NORMAL PISTOLS ONLY
				if(weapon.shottype == "pb" || weapon.shottype == "pg")
				{
					CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
					CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
					PlaySound("OBJECTS\duel\GI_ValidClick.wav");

					if(CheckAttribute(attack,"quest.Legrands_fireplace"))
					{
						if(attack.quest.Legrands_fireplace == "extinct" || attack.quest.Legrands_fireplace == "unlit")
						{
							if(CheckAttribute(attack,"quest.Legrands_damper") && attack.quest.Legrands_damper == "closed")
							{
								Log_SetStringToLog(TranslateString("","You need oxygen!"));

								LAi_QuestDelay("end_of_tinderbox3", 1.0);	//hah
							}
							else
							{
								Locations[FindLocation(attack.location)].models.always.locators = "mediumhouse01_locators_GB1";
								locations[FindLocation(attack.location)].models.always.l2 = "wood3";
								Locations[FindLocation("Legrands_kitchen")].image = "";
								attack.quest.Legrands_fireplace = "fire1";

								LAi_QuestDelay("end_of_tinderbox", 1.0);
							}
						}
						else 
						{
							if(attack.quest.Legrands_fireplace == "no_wood")
							{
								Log_SetStringToLog(TranslateString("","Only ashes left - I'll need new wood!"));
							
								LAi_QuestDelay("end_of_tinderbox4", 1.0);	//sigh
							}
						}
						else LAi_QuestDelay("end_of_tinderbox2", 1.0);
					}
				}	
				return;
			}
		}
	    // <-- JRH light fire
		else
		{
			if(attack.location == "wr_animists")
			{
				if(CheckAttribute(attack,"quest.cell2_check") && attack.quest.cell2_check == "on")
				{
					PlaySound("PEOPLE\spade.wav");
					LAi_QuestDelay("sledge_to_defence", 1.0);
					return;
				}
				else
				{
					PlaySound("PEOPLE\spade.wav");
					LAi_QuestDelay("sledge_to_minebomb", 1.0);
					return;
				}
			}
		}
		else
		{
			if(attack.location == "wr_farm_alchemy")
			{
				if(CheckAttribute(attack,"quest.lab_position") && attack.quest.lab_position == "fireplace")
				{
					if(CheckAttribute(attack,"quest.apparatus_level"))
					{
						if(attack.quest.apparatus_level == "cauldron")
						{
							if(CheckAttribute(weapon, "id") )
							{
								if(weapon.id == "pistolretort")
								{
									//place retort!
									if(Locations[FindLocation("wr_farm_alchemy")].models.always.locators == "mediumhouse01_locators_JRH2")
									{
										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "empty")
											PlaySound("INTERFACE\glass1.wav");
										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "water")
											PlaySound("INTERFACE\glass2.wav");
										LAi_SetPoorType(attack);

										LAi_QuestDelay("alchemy_glass_explosion", 0.5);
										return;
									}

									if(Locations[FindLocation("wr_farm_alchemy")].models.always.locators == "mediumhouse01_locators_JRH1")
									{
										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "empty")
										{
											PlaySound("INTERFACE\glass1.wav");
											LAi_SetPoorType(attack);

											LAi_QuestDelay("alchemy_glass_explosion", 0.5);
											return;
										}

										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "water")
										{
											PlaySound("INTERFACE\glass2.wav");

											RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
											TakeItemFromCharacter(attack, "pistolretort");

											Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_E0";
											attack.quest.apparatus_level = "retort";
											attack.quest.retort = "yes";

											LAi_QuestDelay("place_distillery_item", 0.5);
										}
									}

									if(Locations[FindLocation("wr_farm_alchemy")].models.always.locators == "mediumhouse01_locators_JRH0")
									{
										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "empty")
											PlaySound("INTERFACE\glass1.wav");
										if(CheckAttribute(attack,"quest.cauldron") && attack.quest.cauldron == "water")
										{
											PlaySound("INTERFACE\glass2.wav");
										}

										RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
										TakeItemFromCharacter(attack, "pistolretort");

										Locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_E0";
										attack.quest.apparatus_level = "retort";
										attack.quest.retort = "yes";

										LAi_QuestDelay("place_distillery_item", 0.5);
									}
								}
							}
						}

						if(attack.quest.apparatus_level == "top")
						{
							if(CheckAttribute(weapon, "id") )
							{
								if(weapon.id == "pistolglass_tube")
								{
									//place glass tube!
									PlaySound("INTERFACE\glass1.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolglass_tube");

									Locations[FindLocation("wr_farm_alchemy")].models.always.l12 = "glass_tube3";
									attack.quest.apparatus_level = "glass_tube";
									attack.quest.glass_tube = "yes";

									LAi_QuestDelay("place_distillery_item", 0.5);
								}
							}
						}
					}
				}

				if(CheckAttribute(attack,"quest.lab_position") && attack.quest.lab_position == "mixtable")
				{
					int ps = GetCharacterItem(attack, "pistolsalt");
					int pn = GetCharacterItem(attack, "pistolnitre");
					int pc = GetCharacterItem(attack, "pistolcopperas");

					//EMPTY BOTTLE
					if(CheckAttribute(attack, "quest.mixtable_bottle") && attack.quest.mixtable_bottle == "ME0")
					{
						if(CheckAttribute(weapon, "id") )
						{
							if(weapon.id == "pistolsalt")
							{
								//sulf needed - else stock here!
								if (CheckCharacterItem(attack, "bladebottle_CT1_sulf"))
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MS1_salt";
									attack.quest.mixtable_bottle = "MS1_salt";

									if(ps == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsalt");

									LAi_QuestDelay("place_mixtable_item", 1.0);
									return;
								}
							}

							if(weapon.id == "pistolnitre")
							{
								if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "4")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MS1_chil";
									attack.quest.mixtable_bottle = "MS1_chil";

									if(pn == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolnitre");

									LAi_QuestDelay("place_mixtable_item", 1.0);
									return;
								}
								else
								{
									//sulf needed - else stock here!
									if (CheckCharacterItem(attack, "bladebottle_CT1_sulf"))
									{
										PlaySound("PEOPLE\grass_noise.wav");
										locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MS1_chil";
										attack.quest.mixtable_bottle = "MS1_chil";

										if(pn == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
										TakeItemFromCharacter(attack, "pistolnitre");

										LAi_QuestDelay("place_mixtable_item", 1.0);
										return;
									}
								}
							}

							if(weapon.id == "pistolcopperas")
							{
								PlaySound("PEOPLE\grass_noise.wav");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MV1";
								attack.quest.mixtable_bottle = "MV1";

								if(pc == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolcopperas");

								LAi_QuestDelay("place_mixtable_item", 1.0);
								return;
							}
						}
					}

					//HALF FULL BOTTLE: WATER
					if(CheckAttribute(attack, "quest.mixtable_bottle") && attack.quest.mixtable_bottle == "MW1")
					{
						if(CheckAttribute(weapon, "id") && weapon.id == "pistolcopperas")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MG2";
							attack.quest.mixtable_bottle = "MG2";

							if(pc == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcopperas");

							LAi_QuestDelay("place_mixtable_item", 1.0);
							return;
						}
					}

					//HALF FULL BOTTLE: H2SO4
					if(CheckAttribute(attack, "quest.mixtable_bottle") && attack.quest.mixtable_bottle == "MT1_sulf")
					{
						if(CheckAttribute(weapon, "id") )
						{
							if(weapon.id == "pistolnitre")
							{
								PlaySound("PEOPLE\grass_noise.wav");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_sulf_c";
								attack.quest.mixtable_bottle = "MT2_sulf_c";

								if(pn == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolnitre");

								LAi_QuestDelay("place_mixtable_item", 1.0);
								return;
							}

							if(weapon.id == "pistolsalt")
							{
								PlaySound("PEOPLE\grass_noise.wav");
								locations[FindLocation("wr_farm_alchemy")].models.always.l5 = "bottle_MT2_hydr";
								attack.quest.mixtable_bottle = "MT2_hydr";

								if(ps == 1) RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolsalt");

								LAi_QuestDelay("place_mixtable_item", 1.0);
								return;
							}
						}
					}
				}
//pär pistolitems
				if(CheckAttribute(attack,"quest.lab_position") && attack.quest.lab_position == "mixtableL")
				{
					switch(Locations[FindLocation(attack.location)].models.always.l16)
					{
						case "bottle_LE0":
							//EMPTY BOTTLE

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "1")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsalt")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_salt";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsalt");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LCa_coal";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LSa_cc";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LUa";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}	
							}

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "8")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolretort3")
								{
									Logit(TranslateString("","No,I have to apply the wax to the gases, not the other way around."));
									PlaySound("VOICE\ENGLISH\blaze_hah.wav");
									return;
								}
							}

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LUa";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGa_M";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}	
							}
						break;
						
						case "bottle_LTa_sulf":
							//QUARTER FULL BOTTLE: H2SO4

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "1")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsalt")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LT1_hydr";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsalt");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LSa_salt":
							//QUARTER FULL BOTTLE: salt

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "1")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsalt")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_salt";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsalt");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;
				
						case "bottle_LT1_hydr":
							//HALF FULL BOTTLE: HCl

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "1")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsalt")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LTc_hydr";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsalt");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;
						
						case "bottle_LCa_coal":
							//QUARTER FULL BOTTLE: coal

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LC1_coal";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG1_cc";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LSa_cc":
							//QUARTER FULL BOTTLE: Calcium Carbonate 

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG1_cc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LSa_ss":
							//QUARTER FULL BOTTLE: Sodium Sulfate

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG1_ss";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LS1_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LS1_mix2":
							//HALF FULL BOTTLE: Sodium Sulfate + Calcium Carbonate

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_mix2";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LG1_ss":
							//HALF FULL BOTTLE: coal + sodium sulfate
							
							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_ss";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LG1_cc":
							//HALF FULL BOTTLE: coal + calcium carbonate
							
							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_cc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LGc_mix2":
							//THREE QUARTER FULL BOTTLE: coal + sodium sulfate + calcium carbonate

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcharcoal_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG2_mix2";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcharcoal_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;	

						case "bottle_LC1_coal":
							//HALF FULL BOTTLE: Coal
						
							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LGc_cc";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LGc_ss": 
							//THREE QUARTER FULL BOTTLE: 2 coal + sodium sulfate

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "2")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolcalciumsack")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolcalciumsack");

									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LG2_mix2";

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LSa_cao":
							//QUARTER FULL BOTTLE: calcium oxide

							if(CheckAttribute(attack, "Q2_mix"))
							{
								if(attack.Q2_mix == "7" || attack.Q2_mix == "9")
								{
									if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
									{
										PlaySound("PEOPLE\grass_noise.wav");
										locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_cao";

										RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
										TakeItemFromCharacter(attack, "pistolsulphur_WR");

										LAi_QuestDelay("place_mixtableL_item", 1.0);
										return;
									}
								}
							}

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LM1_cao";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LSa_NH4Cl":
							//QUARTER FULL BOTTLE: sal ammoniac

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_NH4Cl";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LWa":
							//QUARTER FULL BOTTLE: water

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL1_s";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LS1_mix7":
							//HALF FULL BOTTLE: Sal Ammoniac + Calcium Oxide

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_s";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LT1_cao":
							//HALF FULL BOTTLE: calcium oxide + water

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_cao";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LT1_NH4Cl":
							//HALF FULL BOTTLE: sal ammoniac + water

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LLc_NH4Cl";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LLc_mix7":
							//THREE QUARTER FULL BOTTLE: sal ammoniac + water + calcium oxide

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "7")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LL2_s";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LY1_gas":
							//HALF FULL BOTTLE: gas

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "8")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolretort3")
								{
									PlaySound("PEOPLE\sponge.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LUc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolretort3");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LUc":
							//THREE QUARTER FULL BOTTLE: gas + fat

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "8")
							{	
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolretort3")
								{
									PlaySound("PEOPLE\sponge.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LU2";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolretort3");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LSa_sc":
							//QUARTER FULL BOTTLE: sodium carbonate

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY1_sc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LM1_sc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LGa_M":
							//QUARTER FULL BOTTLE: antimony

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LU1";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;
					
						case "bottle_LUa":
							//QUARTER FULL BOTTLE: sulphur

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LU1";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LS1_mix9":
							//HALF FULL BOTTLE: Sal Ammoniac + Calcium Oxide

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LMc_mix9";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}

								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_mix9";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LM1_sc":
							//HALF FULL BOTTLE: sodium carbonate + antimony

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_sc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LY1_sc":
							//HALF FULL BOTTLE: sodium carbonate + sulphur

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_sc";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;
				
						case "bottle_LM1_cao":
							//HALF FULL BOTTLE: calcium oxide + antimony

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_cao";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LY1_cao":
							//HALF FULL BOTTLE: calcium oxide + sulfur

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LYc_cao";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;

						case "bottle_LMc_mix9":
							//THREE QUARTER FULL BOTTLE: sodium carbonate + calcium oxide + antimony

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolsulphur_WR")
								{
									PlaySound("PEOPLE\grass_noise.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY2_mix9";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolsulphur_WR");

									LAi_QuestDelay("place_mixtableL_item", 1.0);
									return;
								}
							}
						break;

						case "bottle_LYc_mix9":
							//THREE QUARTER FULL BOTTLE: sodium carbonate + calcium oxide + sulfur

							if(CheckAttribute(attack, "Q2_mix") && attack.Q2_mix == "9")
							{
								if(CheckAttribute(weapon, "id") && weapon.id == "pistolstonebasket_M")
								{
									PlaySound("PEOPLE\cavern1.wav");
									locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LY2_mix9";

									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolstonebasket_M");

									LAi_QuestDelay("place_mixtableL_item", 1.5);
									return;
								}
							}
						break;
//pär pistolitems end
					}
				}
				return;
			}
		}
		else
		{
			if(attack.location == "wr_ships")
			{
				if(CheckAttribute(attack,"quest.deck_position") && attack.quest.deck_position == "mechanism_L")
				{
					if(CheckAttribute(weapon, "id") )
					{
						if(weapon.id == "pistolwheel")
						{
							//place wheel!
							PlaySound("INTERFACE\wheel_place.wav");
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolwheel");
							if(!CheckCharacterItem(attack,"pistolhand")) GiveItem2Character(attack,"pistolhand");
							EquipCharacterByItem(attack, "pistolhand");

							Locations[FindLocation("wr_ships")].models.always.l13 = "wheel_L";
							attack.quest.wheel_pos_left = "wheel";

							LAi_QuestDelay("at_mechanism_L", 0.5);
						}

						{
							if(weapon.id == "pistolhand")
							{
								//take wheel if any
								if(CheckAttribute(attack,"quest.wheel_pos_left") && attack.quest.wheel_pos_left == "wheel")
								{
									PlaySound("INTERFACE\wheel_take.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolhand");
									GiveItem2Character(attack,"pistolwheel");
									EquipCharacterByItem(attack, "pistolwheel");

									Locations[FindLocation("wr_ships")].models.always.l13 = "";
									attack.quest.wheel_pos_left = "free";

									LAi_QuestDelay("at_mechanism_L", 1.0);
								}
								else
								{
									//return?
								}
							}
						}
					}
					return;	//new
				}

				if(CheckAttribute(attack,"quest.deck_position") && attack.quest.deck_position == "mechanism_R")
				{
					if(CheckAttribute(weapon, "id") )
					{
						if(weapon.id == "pistolwheel")
						{
							//place wheel!
							PlaySound("INTERFACE\wheel_place.wav");
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolwheel");
							if(!CheckCharacterItem(attack,"pistolhand")) GiveItem2Character(attack,"pistolhand");
							EquipCharacterByItem(attack, "pistolhand");

							Locations[FindLocation("wr_ships")].models.always.l13 = "wheel_R";
							attack.quest.wheel_pos_right = "wheel";

							LAi_QuestDelay("at_mechanism_R", 0.5);
						}

						{
							if(weapon.id == "pistolhand")
							{
								//take wheel if any
								if(CheckAttribute(attack,"quest.wheel_pos_right") && attack.quest.wheel_pos_right == "wheel")
								{
									PlaySound("INTERFACE\wheel_take.wav");
									RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
									TakeItemFromCharacter(attack, "pistolhand");
									GiveItem2Character(attack,"pistolwheel");
									EquipCharacterByItem(attack, "pistolwheel");

									Locations[FindLocation("wr_ships")].models.always.l13 = "";
									attack.quest.wheel_pos_right = "free";

									LAi_QuestDelay("at_mechanism_R", 1.0);
								}
								else
								{
									//return?
								}
							}
						}
					}
					return;	//new
				}

				if(CheckAttribute(attack,"quest.deck_position") && attack.quest.deck_position == "elsewhere")
				{
					//no enemy no interesting station - do nothing
					return;	//new
				}
			}

			if(attack.location == "wr_corv_crew")
			{
				if(CheckAttribute(weapon, "id") && weapon.id == "pistolhand")
				{
					if(CheckAttribute(attack,"quest.tablemap") && attack.quest.tablemap == "on_floor")
					{
						PlaySound("INTERFACE\paper.wav");
						Locations[FindLocation("wr_corv_crew")].models.always.l2 = "doormap1";
						attack.quest.tablemap = "under_door";

						Locations[FindLocation("wr_corv_crew")].models.always.l3 = "";

						LAi_QuestDelay("use_gunitem_at_belt_door", 1.0);
						return;
					}

					if(CheckAttribute(attack,"quest.tablemap") && attack.quest.tablemap == "under_door")
					{
						PlaySound("INTERFACE\paper.wav");
						Locations[FindLocation("wr_corv_crew")].models.always.l2 = "floormap1";
						attack.quest.tablemap = "on_floor";

						if(CheckAttribute(attack,"quest.beltkey") && attack.quest.beltkey == "on_map")
						{
							Locations[FindLocation("wr_corv_crew")].models.always.l3 = "keysimple1";
						}
						else Locations[FindLocation("wr_corv_crew")].models.always.l3 = "";

						LAi_QuestDelay("use_gunitem_at_belt_door", 1.0);
						return;
					}
				}

				if(CheckAttribute(weapon, "id") && weapon.id == "pistolmap1")
				{
					PlaySound("INTERFACE\paper.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolmap1");
					if(!CheckCharacterItem(attack,"pistolhand")) GiveItem2Character(attack,"pistolhand");
					EquipCharacterByItem(attack, "pistolhand");

					Locations[FindLocation("wr_corv_crew")].models.always.l2 = "floormap1";
					attack.quest.tablemap = "on_floor";

					LAi_QuestDelay("use_gunitem_at_belt_door", 1.0);
				}

				return;
			}
		}
		else
		{
			if(attack.location == "BB_island2")
			{
				if(CheckAttribute(attack,"bb_isl2_position") && attack.bb_isl2_position == "bridge")
				{
					if(LAi_IsFightMode(attack))
					{
						if(CheckAttribute(attack, "BB_isl2_box7_gun") && attack.BB_isl2_box7_gun == "on") return;
						attack.BB_isl2_box7_gun = "on";
						//this is your 2:nd 'open box'

						PlaySound("OBJECTS\DUEL\sabre_sh.wav");

						RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
						TakeItemFromCharacter(attack, "pistolbladeBB");
						if(!CheckCharacterItem(attack,"bladeX4")) GiveItem2Character(attack, "bladeX4");
						EquipCharacterByItem(attack, "bladeX4");
						DeleteQuestHeader("KR_cutlasses");
						
						LAi_QuestDelay("key_unlock2", 1.5);
						LAi_QuestDelay("BB_island2_unlock_tower", 3.0);
					}
				}
			}
		}
		else
		{
			if(attack.location == "BB_sloop_wreck_cabin")
			{
				if(CheckAttribute(weapon, "id") && weapon.id == "pistolhammer")
				{
				    if(CheckAttribute(weapon7, "id") && weapon7.id == "Barmansknife")
			            {
					if(LAi_IsFightMode(attack))
					{
						//this is your 2:nd 'open box'

						PlaySound("OBJECTS\DUEL\spyglass.wav");
						PlaySound("OBJECTS\DUEL\steelflint.wav");

						attack.quest.hammer_gp = sti(attack.quest.hammer_gp) + 1;

						if(CheckAttribute(attack, "quest.hammer_gp"))
						{
							switch(attack.quest.hammer_gp)
							{
								case "1": 	CreateParticleSystem("gunfire_red" , 1.55, 3.8, -2.8, 0.0, 0.0, 0.0, sti(20) );
										CreateParticleSystem("stars_fire" , 1.55, 3.8, -2.8, 0.0, 0.0, 0.0, sti(20) );  		
										LAi_QuestDelay("pchar_1", 1.0);
								break;

								case "2": 	CreateParticleSystem("gunfire_red" , 1.55, 3.8, -2.8, 0.0, 0.0, 0.0, sti(20) );
										CreateParticleSystem("stars_fire" , 1.55, 3.8, -2.8, 0.0, 0.0, 0.0, sti(20) ); 
										CreateParticleSystem("MMcancloud2_Light" , 1.55, 3.8, -2.8, 5.1, 4.0, 0.0, sti(20) );
										LAi_QuestDelay("pchar_2", 1.0);
								break;

								case "3": 	PlaySound("OBJECTS\SHIPCHARGE\LG42H.wav");
										PlaySound("OBJECTS\SHIPCHARGE\gunpowder_explosion.wav");

										GetCharacterPos(attack, &u, &v, &w);

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
											 
										LAi_KillCharacter(attack);
								break;
							}
						}

						LAi_QuestDelay("gpmap_free_counting", 1.0);
					}
				    }
				    else
				    {
					//only pistolhammer
					if(LAi_IsFightMode(attack))
					{
						//this is your 2:nd 'open box'

						switch(Locations[FindLocation(attack.location)].models.always.l2)
						{
							case "":
								PlaySound("OBJECTS\DUEL\club2.wav");
							break;

							case "gp_dry":
								PlaySound("OBJECTS\DUEL\club2.wav");
							break;

							case "gp_wet":
								PlaySound("PEOPLE\step_carpet.wav");
								PlaySound("PEOPLE\sponge.wav");
					
								LAi_QuestDelay("pchar_laugh", 1.5);
							break;
						}

						LAi_QuestDelay("gpmap_free", 1.0);	
					}
				    }
				}
			}
		}
	}
//<-- JRH
}
