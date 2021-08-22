
void OpenBoxProcedure_BUG()
{
//Logit("OpenBoxProcedure_BUG");
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
	//note in INTERFACE\itemsbox search JRH: normal box sounds avoided when not wanted

	//GoldBug-->
	if(Locations[locidx].id=="Sullivan_shore1")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore1", "goto", "box3");

				LAi_QuestDelay("Sull_sh1_turn_to_box2", 0.5);
			break;
		
			case "box3":
				DoQuestReloadToLocation("Sullivan_shore2", "reload", "reload1", "");		
			break;

			case "box4":
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				Logit(TranslateString("","The remnants of the hull of what appear to have been a ship's long boat."));
				Logit(TranslateString("","The last storm must have brought it here."));

				LAi_QuestDelay("So_that's_how it_happened", 1.0);
			break;

			case "box5":
				AddQuestRecord("Searching_the_shores", "4");
				PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
				Logit(TranslateString("","Ouch, the Gold-Bug gave me a sharp bite!"));
				Logit(TranslateString("","I'll need a leaf, or something of that nature, by which to take hold of it."));
				LAi_ApplyCharacterDamage(chr, 5);
				if(LAi_IsDead(chr)) GameOverOrg("land");

				SetLocatorRadius(locations[FindLocation(chr.location)], "randitem", "randitem6", 1.5);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.randitem.randitem6 = 1.5;
			break;

			case "box6":
				AddQuestRecord("Searching_the_shores", "3");
				chr.quest.detected_goldbug = "seen";

				PlaySound("OBJECTS\DUEL\man_attack6.wav");
				Logit(TranslateString("","Jupiter look! It's a Gold-Bug!"));
				
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box5", 1.5);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.box.box5 = 1.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box6", 0.001);
				Locations[FindLocation("Sullivan_shore1")].locators_radius.box.box6 = 0.001;

				LAi_QuestDelay("Jupiter_a_Goldbug", 1.0);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Sullivan_shore2")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore2", "goto", "box7");

				LAi_QuestDelay("Sull_sh2_turn_to_ri1", 0.5);
			break;
		
			case "box4":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore2", "goto", "box6");

				LAi_QuestDelay("Sull_sh2_turn_to_box1", 0.5);
			break;
		
			case "box5":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore2", "goto", "box6");

				LAi_QuestDelay("Sull_sh2_turn_to_box1", 0.5);
			break;

			case "box6":
				DoQuestReloadToLocation("Sullivan_shore1", "reload", "reload1", "");			
			break;

			case "box7":
				DoQuestReloadToLocation("Sullivan_shore3", "goto", "box1", "Sull_sh3_turn_to_look1");			
			break;

		//.....................................................................................................

			case "box8":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore2", "goto", "box9");

				LAi_QuestDelay("Sull_sh2_turn_to_bear", 0.5);
			break;

			case "box9":
				if(CheckAttribute(chr, "quest.sh2_bear") && chr.quest.sh2_bear == "phase1")
				{
					PlaySound("NATURE\bear1.wav");
					chr.quest.sh2_bear = "phase2";

					LAi_QuestDelay("run_from_bear", 1.0);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Sullivan_shore3")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_roof.wav");
				DoQuestReloadToLocation("Sullivan_shore3", "reload", "reload3", "");
			break;

			case "box2":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore3", "goto", "box3");
			break;

			case "box3":
				PlaySound("PEOPLE\jump_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_shore3", "goto", "box4");
				LAi_SetSitType(chr);

				LAi_QuestDelay("Sull_sh3_turn_to_look2", 0.5);
			break;

			case "box4":
				DoQuestReloadToLocation("Sullivan_shore2", "reload", "reload3", "");		
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Sullivan_jungle1")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "Lhouse_box1") && chr.Lhouse_box1 == "temp_blocked") 
				{
					return;
				}
				else
				{
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "reload", "reload1");

					LAi_QuestDelay("Legrands_house_entre", 0.01);
				}
			break;

			case "box9":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "goto", "box1");
			break;
		
			case "box10":
				if(CheckAttribute(chr, "quest.facade_box10") && chr.quest.facade_box10 == "leave")
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "box", "box11");

					LAi_QuestDelay("facade_box10", 0.01);
				}

				if(CheckAttribute(chr, "quest.facade_box10") && chr.quest.facade_box10 == "free")
				{
					PlaySound("INTERFACE\locked_window.wav");
					chr.quest.facade_box10 = "leave";
				}	
			break;

			case "box11":
				if(CheckAttribute(chr, "quest.facade_box11") && chr.quest.facade_box11 == "leave")
				{
					PlaySound("PEOPLE\jump.wav");

					int e_s = GetCharacterItem(chr, "emptysack");
					if(e_s == 12 && CheckCharacterItem(chr,"pistolmtoon"))
					{
						ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "box", "box14");

						LAi_QuestDelay("pchar_playertype", 0.1);
					}
					else 
					{
						ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "reload", "reload1");

						LAi_QuestDelay("Legrands_house_entre", 0.01);
					}		
				}

				if(CheckAttribute(chr, "quest.facade_box11") && chr.quest.facade_box11 == "free")
				{
					PlaySound("INTERFACE\locked_window.wav");
					chr.quest.facade_box11 = "leave";
				}	
			break;

			case "box14":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Sullivan_jungle1", "box", "box9");
			break;
		}
		return;
	}

	if(Locations[locidx].id=="Legrands_boathouse")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\creak2.wav");
				PlaySound("PEOPLE\step_water.wav");
				ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box3");
			break;

			case "box3":
				if(CheckAttribute(chr, "quest.boathouse"))
				{
					switch(chr.quest.boathouse)
					{
						case "boat":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box4");
						break;

						case "wood":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box6");
							LAi_SetStayType(chr);
						break;

						case "sail":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box6");
							LAi_SetStayType(chr);
						break;

						case "return":
							chr.quest.boathouse = "";		//temp can't do anything
							PlaySound("PEOPLE\creak2.wav");
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "goto", "citizen02");

							LAi_QuestDelay("return_from_boathouse", 2.0);
						break;
					}
					return;
				}
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.boathouse"))
				{
					switch(chr.quest.boathouse)
					{
						case "boat":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box5");
		
							if(CheckAttribute(chr, "sails_on_boat") && chr.sails_on_boat == "yes")
							{
								//Logit("obj_boat4S");
							}
							else
							{
								//Logit("obj_boat4");

								if(CheckCharacterItem(chr,"sailbag"))
								{
									//Logit("carrying sails");
								}
								else LAi_QuestDelay("forgot_the_sails", 1.0);
							}
						break;
					
						case "sail":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box6");
							LAi_SetStayType(chr);
						break;

						case "return":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box3");
							//LAi_SetStayType(chr);
						break;
					}
					return;
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.boathouse"))
				{
					switch(chr.quest.boathouse)
					{
						case "return":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box4");
						break;

						case "boat":
							if(CheckAttribute(chr, "sails_on_boat") && chr.sails_on_boat == "yes")
							{
								e_s = GetCharacterItem(chr, "emptysack");
								if(e_s == 8 && CheckCharacterItem(chr,"pistolmtoon"))
								{								
									//sail away
									//Logit("sail away");

									Characters[GetCharacterIndex("Charleston_guard2")].Ship.Type = "obj_invisible";		//raft2 at BH later on
									SetCharacterShipLocation(characterFromID("Charleston_guard2"), "Bishops_hostel");
									Characters[GetCharacterIndex("Moultrie_guard3")].Ship.Type = "obj_invisible";		//at boathouse
									SetCharacterShipLocation(characterFromID("Steamship_sailor1"), "Bishops_hostel");	//boat4S at BH

									DoQuestReloadToLocation("Bishops_Hostel", "goto", "arrive_boat", "Jup_first_to_BH");
								}
								else
								{
									//not ready yet
									//Logit("not ready yet");
									chr.quest.boathouse = "return";

									PlaySound("PEOPLE\run_wood.wav");
									ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box4");
									LAi_SetStayType(chr);

									chr.quest.leave_boathouse.win_condition.l1 = "locator";
									chr.quest.leave_boathouse.win_condition.l1.location = "Legrands_boathouse";
									chr.quest.leave_boathouse.win_condition.l1.locator_group = "reload";
									chr.quest.leave_boathouse.win_condition.l1.locator = "reload2_back";
									chr.quest.leave_boathouse.win_condition = "leave_boathouse";
								}
							}
							else
							{
								if(CheckCharacterItem(chr,"sailbag"))
								{
									PlaySound("PEOPLE\clothes1.wav");
									SetModel(chr, "Jupiter", chr.model.animation, chr.sex, stf(chr.model.height), true);
									Characters[GetCharacterIndex("Moultrie_guard3")].Ship.Type = "obj_boat4S";

									LAi_QuestDelay("set_sails", 1.0);	
								}
							}
						break;

						case "sail":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box4");
							LAi_SetStayType(chr);
						break;
					}
					return;
				}
			break;


			//..................................................................................

			case "box6":
				if(CheckAttribute(chr, "quest.boathouse"))
				{
					switch(chr.quest.boathouse)
					{
						case "wood":
							PlaySound("PEOPLE\creak2.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box7");
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "goto", "look1");
						break;

						case "sail":
							PlaySound("PEOPLE\creak2.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box7");
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "goto", "look1");
						break;

						case "return":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box3");
						break;

						case "boat":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box3");
						break;
					}
					return;
				}
			break;

			case "box7":
				if(CheckAttribute(chr, "quest.boathouse"))
				{
					switch(chr.quest.boathouse)
					{
						case "wood":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box8");
						break;

						case "sail":
							PlaySound("PEOPLE\run_wood.wav");
							ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "sail");

							LAi_QuestDelay("pickup_sails_check", 0.1);
						break;
					}
					return;
				}
			break;

			case "box8":
				PlaySound("PEOPLE\run_wood.wav");

				if(CheckAttribute(chr, "quest.boathouse") && chr.quest.boathouse == "wood")
				{
					ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "fireplace");

					LAi_QuestDelay("bladewoodsack_autoequip", 0.1);
				}

				if(CheckAttribute(chr, "quest.boathouse") && chr.quest.boathouse == "return")
				{
					ChangeCharacterAddressGroup(chr, "Legrands_boathouse", "goto", "box6");
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Legrands_house")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.house_box1") && chr.quest.house_box1 == "locked")
				{
					PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{ 
					PlaySound("AMBIENT\JAIL\door_003.wav");	
					LaunchItemsBox(&ar);
				}
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.house_box2") && chr.quest.house_box2 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");	
					LaunchItemsBox(&ar);

					LAi_QuestDelay("hut_take_mtoon", 0.1);
				}
				else
				{ 
					if(CheckCharacterItem(chr,"key2"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.house_box2 = "unlocked";
						TakeItemFromCharacter(chr, "key2");
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
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

			case "box7":
				LaunchItemsBox(&ar);
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.backyard") && chr.quest.backyard == "closed")
				{
					PlaySound("INTERFACE\knock.wav");
				}
				else
				{
					if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "no")
					{

					}
					else chr.quest.go_to_well = "phase0";
					DoQuestReloadToLocation("Legrands_backyard", "goto", "box2", "Legrands_house_backdoor");
				}
			break;
	
			case "box8":
				PlaySound("PEOPLE\yawn.wav");
				ChangeCharacterAddressGroup(chr, "Legrands_house", "sit", "sitbed");
				LAi_SetSitType(chr);

				LAi_QuestDelay("gotobed_day1", 2.0);
			break;

			case "box9":
				if(CheckCharacterItem(chr,"key20"))
				{
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_Legrands_grot", 2.0);
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;
		}

		return;
	}	

	if(Locations[locidx].id=="Legrands_kitchen")
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
				//OXYGEN
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\basket.wav");

				LAi_QuestDelay("Legrands_kitchen_plank_oxygen", 0.8);
			break;

			case "box4":
				//LogIt("chr.quest.Legrands_cauldron_water = " + chr.quest.Legrands_cauldron_water);

				//FIREPLACE
				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box', used for placing bladeitems. (fire gun = gunitems)

					//PLACE FRYING PAN
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladefryingpan")
					{
					    if(CheckAttribute(chr, "quest.Legrands_cauldron_w") && chr.quest.Legrands_cauldron_w == "in_fireplace")
					    {
						if(CheckAttribute(chr,"quest.Legrands_parchment_place") && chr.quest.Legrands_parchment_place == "in_cauldron")
						{

						}
						else
						{
							if(chr.quest.Legrands_fireplace == "fire2" )
					    		{
								PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
								Logit(TranslateString("","Ouch, I'll burn my fingers."));
								LAi_ApplyCharacterDamage(chr, 10);
								if(LAi_IsDead(chr)) GameOverOrg("land");

								LAi_QuestDelay("end_of_tinderbox2", 0.1);
					    		}
							else
							{
								if(chr.quest.Legrands_fireplace == "fire1")
								{
									PlaySound("OBJECTS\DUEL\man_hit5.wav");
									Logit(TranslateString("","Ouch, I'll burn my fingers."));
									LAi_ApplyCharacterDamage(chr, 5);
									if(LAi_IsDead(chr)) GameOverOrg("land");

									LAi_QuestDelay("end_of_tinderbox2", 0.1);
								}
							}
					    		else
					    		{
								PlaySound("INTERFACE\glass1.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladefryingpan");
								EquipCharacterByItem(chr, "bladeX4");
								chr.quest.Legrands_fryingpan = "in_fireplace";
								chr.quest.Legrands_fryingpan_temp = "cold";
								Locations[FindLocation("Legrands_kitchen")].models.always.l6 = "fryingpan";
							
								LAi_QuestDelay("end_of_placing_fryingpan", 0.5);
								LAi_QuestDelay("autoequip_bladecrypto", 0.1);
								return;
							}
						}
					    }
					}

					//PLACE CAULDRON
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladecauldron_w")
					{
					        if(chr.quest.Legrands_fireplace == "fire2" )
					        {
							PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
							Logit(TranslateString("","Ouch, I'll burn my fingers."));
							LAi_ApplyCharacterDamage(chr, 10);

							LAi_QuestDelay("end_of_tinderbox2", 0.1);
					        }
					        else
					        {
					    		if(chr.quest.Legrands_fireplace == "fire1")
					    		{
						    		PlaySound("OBJECTS\DUEL\man_hit5.wav");
						    		Logit(TranslateString("","Ouch, I'll burn my fingers."));
						    		LAi_ApplyCharacterDamage(chr, 5);

						    		LAi_QuestDelay("end_of_tinderbox2", 0.1);
					    		}
					    	}
					    	else
					    	{
							PlaySound("INTERFACE\pinion_place.wav");
							PlaySound("INTERFACE\rum_barrel_filled.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladecauldron_w");
							EquipCharacterByItem(chr, "bladeX4");
							chr.quest.Legrands_cauldron_w = "in_fireplace";
							Locations[FindLocation("Legrands_kitchen")].models.always.l9 = "cauldron3_w";
						
							LAi_QuestDelay("end_of_placing_cauldron", 0.5);
							LAi_QuestDelay("autoequip_bladecrypto", 0.1);
							return;
					    	}
					}

					//PLACE WOOD
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladewoodsack")
					{
						if(CheckAttribute(chr,"quest.Legrands_fireplace") && chr.quest.Legrands_fireplace == "no_wood")
						{
							PlaySound("PEOPLE\roof_broken1.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladewoodsack");
						//	GiveItem2Character(chr, "bladeemptysack");	//IF we should keep it
							EquipCharacterByItem(chr, "bladeX4");
							chr.quest.Legrands_fireplace = "unlit";
							locations[FindLocation(chr.location)].models.always.l2 = "wood4";	//unlit
							locations[FindLocation(chr.location)].models.always.l10 = "";		//no ashes1
							locations[FindLocation(chr.location)].models.always.l11 = "";		//no ashes2
							CreateParticleSystemX("blast_dirt_gray", 1.2, 0.5, 0.8, 1.2, 0.5, 0.8,10);

							if(CheckAttribute(chr,"quest.driftwood") && chr.quest.driftwood == "yes")
							{
								LAi_QuestDelay("second_placing_woodsack", 1.0);
							}
							else LAi_QuestDelay("end_of_placing_woodsack", 1.0);
							return;
						}
					}

					//PLACE OR WARM UP DIRTY CRYPTO
					if(CheckAttribute(chr, "equip.blade"))
					{
					    if(chr.equip.blade == "bladecrypto_d" || chr.equip.blade == "bladecrypto_dl"
					    || chr.equip.blade == "bladecrypto_ds" || chr.equip.blade == "bladecrypto_dsk")
					    {
						if(CheckAttribute(chr,"quest.Legrands_fireplace"))
						{
						    if(chr.quest.Legrands_fireplace == "no_wood" || chr.quest.Legrands_fireplace == "extinct"
						    || chr.quest.Legrands_fireplace == "glowing" || chr.quest.Legrands_fireplace == "unlit")
						    {
							if(CheckAttribute(chr, "quest.Legrands_cauldron_w") && chr.quest.Legrands_cauldron_w == "in_fireplace")
							{
							    if(CheckAttribute(chr,"quest.Legrands_fryingpan") && chr.quest.Legrands_fryingpan == "in_fireplace")
							    {
								//don't place parchment if pan is there
							    }
							    else
							    {
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								
								if(CheckAttribute(chr, "quest.Legrands_cauldron_water") && chr.quest.Legrands_cauldron_water == "hot")
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									TakeItemFromCharacter(chr, "bladecrypto_d"); TakeItemFromCharacter(chr, "bladecrypto_dl");
									TakeItemFromCharacter(chr, "bladecrypto_ds"); TakeItemFromCharacter(chr, "bladecrypto_dsk");	//pchar has ONE of these
									EquipCharacterByItem(chr, "bladeX4");
									chr.quest.Legrands_parchment_place = "in_cauldron";

									locations[FindLocation(chr.location)].models.always.l5 = "crypto_roll_clean";
									chr.quest.Legrands_crypto_roll = "clean";

									LAi_QuestDelay("place_dirty_parchment_in_hot_water", 1.0);
								}
								else
								{ 
									/*
									locations[FindLocation(chr.location)].models.always.l5 = "crypto_roll_dirty";
					
									LAi_QuestDelay("dirty_parchment_in_cold_water", 1.0);
									*/

									PlaySound("VOICE\ENGLISH\blaze_hah.wav");
									Logit(TranslateString("","No, the water isn't warm enough."));	
									LAi_SetFightMode(chr, false);
									LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
									return;
								}
						
								return;
							    }
							}
						    }
		
						    if(chr.quest.Legrands_fireplace == "fire1")
						    {
							if(CheckAttribute(chr, "equip.blade"))
							{
							    if(chr.equip.blade == "bladecrypto_ds" || chr.equip.blade == "bladecrypto_dsk")
							    {
								PlaySound("OBJECTS\DUEL\man_hit5.wav");
						    		Logit(TranslateString("","Ouch, I'll burn my fingers."));
						    		LAi_ApplyCharacterDamage(chr, 5);

						    		LAi_QuestDelay("end_of_tinderbox2", 0.1);
							    }

							    if(chr.equip.blade == "bladecrypto_dl")
							    {
							    	PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecrypto_dl");
								GiveItem2Character(chr, "bladecrypto_ds");
								EquipCharacterByItem(chr, "bladecrypto_ds");

								LAi_QuestDelay("end_of_visible_skull_dirty", 1.0);
							    }
							}
						    }

						    if(chr.quest.Legrands_fireplace == "fire2")
						    {
							if(CheckAttribute(chr, "equip.blade"))
							{
							    if(chr.equip.blade == "bladecrypto_dsk")
							    {
								PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
								Logit(TranslateString("","Ouch, I'll burn my fingers."));
								LAi_ApplyCharacterDamage(chr, 10);
								if(LAi_IsDead(chr)) GameOverOrg("land");

								LAi_QuestDelay("end_of_tinderbox2", 0.1);
							    }

							    if(chr.equip.blade == "bladecrypto_ds" || chr.equip.blade == "bladecrypto_dl")
							    {
								PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecrypto_ds"); TakeItemFromCharacter(chr, "bladecrypto_dl"); 
								GiveItem2Character(chr, "bladecrypto_dsk");
								EquipCharacterByItem(chr, "bladecrypto_dsk");
							AddQuestRecord("The_parchment", "4");

								LAi_QuestDelay("end_of_visible_skullgoat_dirty", 1.0);
							    }   
							}
						    }
						}
					    }
					}

					//PLACE OR WARM UP CLEAN CRYPTO
					if(CheckAttribute(chr, "equip.blade"))
					{
					    if(chr.equip.blade == "bladecrypto_cl" || chr.equip.blade == "bladecrypto_csk"
					    || chr.equip.blade == "bladecrypto_cskp")
					    {
						if(CheckAttribute(chr,"quest.Legrands_fireplace"))
						{
						    if(chr.quest.Legrands_fireplace == "no_wood" || chr.quest.Legrands_fireplace == "extinct"
						    || chr.quest.Legrands_fireplace == "glowing" || chr.quest.Legrands_fireplace == "unlit")
						    {
							if(CheckAttribute(chr,"quest.Legrands_fryingpan") && chr.quest.Legrands_fryingpan == "in_fireplace")
							{
								PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);	
								TakeItemFromCharacter(chr, "bladecrypto_cl"); TakeItemFromCharacter(chr, "bladecrypto_csk");
								TakeItemFromCharacter(chr, "bladecrypto_cskp");
								EquipCharacterByItem(chr, "bladeX4");
								chr.quest.Legrands_parchment_place = "in_fryingpan";
								locations[FindLocation(chr.location)].models.always.l8 = "crypto_flat";
					
								LAi_QuestDelay("end_of_placing_crypto_on_pan", 1.0);
								return;
							}
							else
							{
								//trying to clean parchment again
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","No, I have already done that."));
								LAi_SetFightMode(chr, false);
								LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
								return;
							}
						    }
		
						    if(chr.quest.Legrands_fireplace == "fire1")
						    {
							if(CheckAttribute(chr, "equip.blade"))
							{
							    if(chr.equip.blade == "bladecrypto_csk")
							    {
							    	PlaySound("OBJECTS\DUEL\man_hit5.wav");
						    		Logit(TranslateString("","Ouch, I'll burn my fingers."));
						    		LAi_ApplyCharacterDamage(chr, 5);

						    		LAi_QuestDelay("end_of_tinderbox2", 0.1);
							    }

							    if(chr.equip.blade == "bladecrypto_cl")
							    {
							    	PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecrypto_cl");
								GiveItem2Character(chr, "bladecrypto_csk");
								EquipCharacterByItem(chr, "bladecrypto_csk");

								LAi_QuestDelay("end_of_visible_skullgoat_clean", 1.0);
							    }
							}
						    }

						    if(chr.quest.Legrands_fireplace == "fire2")
						    {
							if(CheckAttribute(chr, "equip.blade"))
							{
							    if(chr.equip.blade == "bladecrypto_cskp")
							    {
								PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
								Logit(TranslateString("","Ouch, I'll burn my fingers."));
								LAi_ApplyCharacterDamage(chr, 10);
								if(LAi_IsDead(chr)) GameOverOrg("land");

								LAi_QuestDelay("end_of_tinderbox2", 0.1);
							    }

							    if(chr.equip.blade == "bladecrypto_csk" || chr.equip.blade == "bladecrypto_cl")
							    {
								PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladecrypto_csk"); TakeItemFromCharacter(chr, "bladecrypto_cl");
								GiveItem2Character(chr, "bladecrypto_cskp");
								EquipCharacterByItem(chr, "bladecrypto_cskp");

								LAi_QuestDelay("end_of_visible_parttext_clean", 1.0);
							    }
							}
						    }
						}
					    }
					}


					//PICK UP CRYPTO ROLL
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
					{
					    if(CheckAttribute(chr,"quest.Legrands_parchment_place") && chr.quest.Legrands_parchment_place == "in_cauldron")
					    {
						if(chr.quest.Legrands_fireplace == "fire2" )
					        {
							PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
							Logit(TranslateString("","Ouch, I'll burn my fingers."));
							LAi_ApplyCharacterDamage(chr, 10);
							if(LAi_IsDead(chr)) GameOverOrg("land");

							LAi_QuestDelay("end_of_tinderbox2", 0.1);
					        }
					        else
					        {
					    		if(chr.quest.Legrands_fireplace == "fire1")
					    		{
						    		PlaySound("OBJECTS\DUEL\man_hit5.wav");
						    		Logit(TranslateString("","Ouch, I'll burn my fingers."));
						    		LAi_ApplyCharacterDamage(chr, 5);

						    		LAi_QuestDelay("end_of_tinderbox2", 0.1);
					    		}
					    	}
						else
						{
			//JRH pick up clean crypto
							if(CheckAttribute(chr, "quest.Legrands_crypto_roll") && chr.quest.Legrands_crypto_roll == "clean")
							{
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							//	GiveItem2Character(chr, "bladecrypto_cl");
							//	EquipCharacterByItem(chr, "bladecrypto_cl");
							GiveItem2Character(chr, "bladecrypto_csk");
							EquipCharacterByItem(chr, "bladecrypto_csk");
								chr.quest.Legrands_parchment_place = "";
								locations[FindLocation(chr.location)].models.always.l5 = "";	//roll in cauldron

								LAi_QuestDelay("take_dirty_parchment_from_hot_water", 1.0);			//yes ok here too
								return;
							}
							else
							{
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");
								PlaySound("AMBIENT\Cave\drop3.wav");

								LAi_QuestDelay("dirty_parchment_in_cold_water2", 1.0);
								return;	
							}
						}
					    }
				
					    //PICK UP CRYPTO SHEET
					    if(CheckAttribute(chr,"quest.Legrands_parchment_place") && chr.quest.Legrands_parchment_place == "in_fryingpan")
					    {
						if(chr.quest.Legrands_fireplace == "fire2" )
					        {
							PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
							Logit(TranslateString("","Ouch, I'll burn my fingers."));
							LAi_ApplyCharacterDamage(chr, 10);
							if(LAi_IsDead(chr)) GameOverOrg("land");

							LAi_QuestDelay("end_of_tinderbox2", 0.1);
					        }
					        else
					        {
					    		if(chr.quest.Legrands_fireplace == "fire1")
					    		{
						    		PlaySound("OBJECTS\DUEL\man_hit5.wav");
						    		Logit(TranslateString("","Ouch, I'll burn my fingers."));
						    		LAi_ApplyCharacterDamage(chr, 5);

						    		LAi_QuestDelay("end_of_tinderbox2", 0.1);
					    		}
					    	}
						else
						{
							if(CheckAttribute(chr, "quest.Legrands_fryingpan_temp") && chr.quest.Legrands_fryingpan_temp == "hot")
							{
								PlaySound("INTERFACE\paper.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								GiveItem2Character(chr, "bladecrypto_cskt");
								EquipCharacterByItem(chr, "bladecrypto_cskt");
								chr.quest.Legrands_parchment_place = "";
								locations[FindLocation(chr.location)].models.always.l8 = "";	//no flat crypto
					
								LAi_QuestDelay("end_of_visible_text_clean", 1.0);
								return;
							}
							else
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								ChangeCharacterAddressGroup(chr, "Legrands_kitchen", "goto", "fireplace");
								Logit(TranslateString("","No, the water isn't warm enough."));	
								LAi_SetFightMode(chr, false);
								LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);
								return;
							}
						}
					    }
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.fireplace_disabled") && chr.quest.fireplace_disabled == "yes")
					{
						return;
					}
					else
					{
						ChangeCharacterAddressGroup(chr, "Legrands_kitchen", "goto", "fireplace_stuck");
						LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("stay_at_Legrands_fireplace", 1.0);
						return;
					}
				}
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box6":
				//DAMPER

				if(CheckAttribute(chr,"quest.Legrands_damper") && chr.quest.Legrands_damper == "closed")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.Legrands_damper = "half_open";
					Locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_half";

					LAi_QuestDelay("Legrands_damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.Legrands_damper") && chr.quest.Legrands_damper == "half_open")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.Legrands_damper = "open";
					Locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_open";

					LAi_QuestDelay("Legrands_damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.Legrands_damper") && chr.quest.Legrands_damper == "open")
				{
					PlaySound("INTERFACE\damper_change.wav");
					chr.quest.Legrands_damper = "half_closed";
					Locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_half";

					if(CheckAttribute(chr,"quest.Legrands_fireplace") && chr.quest.Legrands_fireplace == "fire2")
					{
						Locations[FindLocation(chr.location)].models.always.locators = "mediumhouse01_locators_GB1";
						locations[FindLocation(chr.location)].models.always.l2 = "wood3";
						Locations[FindLocation("Legrands_kitchen")].image = "";
						chr.quest.Legrands_fireplace = "fire1";
					}

					LAi_QuestDelay("Legrands_damper", 0.5);
					return;
				}

				if(CheckAttribute(chr,"quest.Legrands_damper") && chr.quest.Legrands_damper == "half_closed")
				{
					PlaySound("INTERFACE\damper_close.wav");
					chr.quest.Legrands_damper = "closed";
					Locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_closed";

					if(CheckAttribute(chr,"quest.Legrands_fireplace"))
					{
						if(chr.quest.Legrands_fireplace == "fire2" || chr.quest.Legrands_fireplace == "fire1"
						|| chr.quest.Legrands_fireplace == "glowing")
						{
							chr.quest.Legrands_fireplace = "extinct";
							Locations[FindLocation(chr.location)].models.always.locators = "mediumhouse01_locators_GB0";
							locations[FindLocation("Legrands_kitchen")].models.always.l2 = "wood5";

							LAi_QuestDelay("Legrands_damper_closed_smoke", 0.5);
							return;
						} 
						else
						{
							LAi_QuestDelay("Legrands_damper_closed", 0.5);
							return;
						} 
					}
				}
			break;

			case "box7":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Legrands_kitchen", "goto", "bench");

				if(CheckAttribute(chr, "quest.inkpen") && chr.quest.inkpen == "picked_up")
				{
					LAi_QuestDelay("down_from_bench", 2.0);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Legrands_backyard")
	{
		switch(chr.boxname)
		{
			case "box2":
				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase7")
				{
					DoQuestReloadToLocation("Legrands_house", "goto", "box4", "pchar_playertype");
				}

				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase1")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "goto", "box3");
				
					LAi_QuestDelay("way_to_well1", 0.1);
				}
				
				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase0")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box3");
					chr.quest.go_to_well = "phase1";
				}

				//------------------------------------------------------------------------------------

				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase2")
				{
					chr.quest.go_to_attic = "phase0";
					DoQuestReloadToLocation("Legrands_house", "goto", "box4", "pchar_playertype");
				}

				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase1")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box5");

					LAi_QuestDelay("way_to_attic1", 0.5);
				}

				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase0")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box3");
					chr.quest.go_to_attic = "phase1";
				}
			break;

			case "box3":
				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase7")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "goto", "box2");

					LAi_QuestDelay("return_from_well3", 0.5);
				}
				
				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase2")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "goto", "box4");
					chr.quest.go_to_well = "phase3";
				}
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase7")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "reload", "reload1");

					LAi_QuestDelay("return_from_well1", 1.0);
				}

				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase6")
				{
					//ready to pick up filled cauldron

					PlaySound("INTERFACE\anchor_up.wav");
					CreateParticleSystemX("ball_splash", 5.1, 0.0, -34.2, 0.0, 0.0, 0.0, 0);

					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					GiveItem2Character(chr, "bladecauldron_w");
					EquipCharacterByItem(chr, "bladecauldron_w");
					CloseQuestHeader("Useful_items");

					LAi_QuestDelay("pick_up_filled_cauldron1", 0.5);
				}

				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase5")
				{
					//prepare to pick up filled cauldron

					LAi_SetFightMode(chr, true);
					
					LAi_QuestDelay("ready_to_pick_up_filled_cauldron", 1.0);
				}

				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase4")
				{
					//fighmode with empty cauldron

					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladecauldron");
					EquipCharacterByItem(chr, "bladeX4");

					PlaySound("INTERFACE\_Yakordrop1.wav");
					CreateParticleSystemX("ball_splash", 5.1, 0.0, -34.2, 0.0, 0.0, 0.0, 0);

					LAi_SetFightMode(chr, false);
					chr.quest.go_to_well = "phase5";
				}

				if(CheckAttribute(chr, "quest.go_to_well") && chr.quest.go_to_well == "phase3")
				{
					//arrived to well

					if(CheckCharacterItem(chr,"bladecauldron"))
					{
						if(!IsEquipCharacterByItem(chr, "bladecauldron"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladecauldron");
						}
					
						LAi_SetFightMode(chr, true);
						chr.quest.go_to_well = "phase4";
					}
					else
					{
						LAi_SetActorType(chr);
						LAi_ActorTurnToLocator(chr, "reload", "reload1");
						chr.quest.go_to_well = "phase7";

						LAi_QuestDelay("return_from_well1", 1.0);
					}
				}
			break;
			
			//-----------------------------------------------------------------------------

			case "box5":
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase2")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box2");

					LAi_QuestDelay("return_from_attic3", 0.1);
				}
				
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase1")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box6");

					if(Locations[FindLocation(chr.location)].models.always.locators == "qcexit_l_GB_tree")
					{
						chr.quest.go_to_attic = "phase2";
					}

					LAi_QuestDelay("way_to_attic2", 0.1);
				}
			break;

			case "box6":
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase2")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box5");	
				}
				
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase1")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box7");

					LAi_QuestDelay("way_to_attic3", 0.1);
				}
			break;

			case "box7":
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase2")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box6");

					LAi_QuestDelay("return_from_attic2", 0.1);
				}
				
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase1")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box8");

					LAi_QuestDelay("way_to_attic4", 0.1);
				}
			break;

			case "box8":
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase2")
				{
					PlaySound("PEOPLE\creak2.wav");
					
					ChangeCharacterAddressGroup(chr, "Legrands_backyard", "box", "box7");

					LAi_QuestDelay("return_from_attic1", 0.1);
				}
				
				if(CheckAttribute(chr, "quest.go_to_attic") && chr.quest.go_to_attic == "phase1")
				{
					if(CheckAttribute(chr, "quest.backyard_box8") && chr.quest.backyard_box8 == "enabled")
					{
						chr.quest.backyard_box8 = "disabled";
						DoQuestReloadToLocation("Legrands_attic", "box", "box1", "pchar_playertype");
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Legrands_attic")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.attic_box1") && chr.quest.attic_box1 == "temp_blocked") return;

				if(CheckAttribute(chr, "quest.attic_box1") && chr.quest.attic_box1 == "blocked")
				{
					PlaySound("INTERFACE\knock.wav");

					LAi_QuestDelay("attic_door_blocked", 1.0);
				}
				else
				{
					chr.quest.go_to_attic = "phase2";
					DoQuestReloadToLocation("Legrands_backyard", "box", "box8", "return_from_attic0");
				}
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.attic_box2") && chr.quest.attic_box2 == "unlocked")
				{
					chr.quest.machete_hint = "done";
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("3_empty_sacks_attic_check", 1.0);
					LAi_QuestDelay("8_empty_sacks_check", 0.1);
				}
				else
				{ 
					if(CheckCharacterItem(chr,"machete"))
					{
						if(LAi_IsFightMode(chr))
						{
						//second 'open box'
							PlaySound("PEOPLE\blade_creak.wav");
							chr.quest.attic_box2 = "unlocked";
							ChangeCharacterAddressGroup(chr, "Legrands_attic", "goto", "free");

							LAi_QuestDelay("machete_broken", 1.0);
						}
						else
						{
							if(!IsEquipCharacterByItem(chr, "machete"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "machete");
							}

							ChangeCharacterAddressGroup(chr, "Legrands_attic", "goto", "stuck");
							LAi_LocationFightDisable(&Locations[FindLocation("Legrands_attic")], false);
							LAi_SetFightMode(chr, true);
						}
					}
					else 
					{
						PlaySound("INTERFACE\lever_stuck.wav");

						if(CheckAttribute(chr, "quest.machete_hint") && chr.quest.machete_hint == "done")
						{


						}
						else LAi_QuestDelay("need_machete", 1.0);
					}
				}
			break;

			case "box3":
				PlaySound("INTERFACE\book_open.wav");
				PlaySound("INTERFACE\took_item.wav");
				GiveItem2Character(chr, "key2");
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box3", 0.001);
				Locations[FindLocation("Legrands_attic")].locators_radius.box.box3 = 0.001;

				LAi_QuestDelay("key2_found", 1.0);
			break;

			case "box4":
				chr.quest.facade_box10 = "free";
				DoQuestReloadToLocation("Sullivan_jungle1", "box", "box10", "facade_box10");
			break;

			

			case "box6": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box7", 0.1); 
					}
			break;

			case "box7": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box8", 0.1);
					}
			break;

			case "box8": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box9", 0.1); 
					}
			break;

			case "box9": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box10", 0.1); 
					}
			break;

			case "box10": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box11", 0.1); 
					}
			break;

			case "box11": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box12", 0.1); 
					}
			break;

			case "box12": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box13", 0.1); 
					}
			break;

			case "box13": 	LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box14", 0.1); 
					}
			break;
		
			case "box14": 	
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar); 
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						LAi_QuestDelay("move_to_attic_box5", 0.1); 
					}
			break;
		
			case "box5":
					//same as box2 chest, at the very end

					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					if(!CheckAttribute(chr,"sack_sequence") || chr.sack_sequence != "already_done")
					{
						chr.sack_sequence = "already_done";
						chr.quest.attic_box1 = "free";
						LAi_QuestDelay("pchar_playertype", 0.1); 
					}
			break;
		}		

		return;
	}

	if(Locations[locidx].id=="Legrands_grot")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("grot_take_food", 0.1);
			break;

			case "box2":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("grot_take_food", 0.1);
			break;

			case "box3":
				PlaySound("AMBIENT\TAVERN\open_bottle.wav");
				Logit(TranslateString("","Two empty barrels."));

				LAi_QuestDelay("empty_barrel", 0.5);
			break;

			case "box4":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("grot_take_dishes", 0.1);
			break;

			case "box5":
				//bottles on table
				PlaySound("INTERFACE\glass1.wav");
				Logit(TranslateString("","Some empty bottles."));
			break;

			case "box6":
				//sacks
				if(CheckAttribute(chr, "quest.grot_sacks") && chr.quest.grot_sacks == "available")
				{
					LAi_SetActorType(chr);	
					characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "throw_the_flour";
					LAi_ActorSelfDialog(chr, "");
				}
				else
				{
					PlaySound("PEOPLE\clothes1.wav");
					Logit(TranslateString("","It's flour in these sacks."));
				}	
			break;

			case "box7":
				//ale
				PlaySound("INTERFACE\drink.wav");
				Logit(TranslateString("","Good beer!"));
			break;

			case "box8":
				//big fish
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
				Logit(TranslateString("","What a stench!"));
			break;

			case "box9":
				//violin
				PlaySound("INTERFACE\violin.wav");
			break;

			case "box10":
				//green box
				PlaySound("PEOPLE\beltkey.wav");
			break;

			case "box11":
				//book
				PlaySound("INTERFACE\book_close.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_Moultrie_exit")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase3")
				{
					DoQuestReloadToLocation("Sullivan_shore3", "reload", "reload1", "FM_exit_stones");
				}

				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "look1");
					chr.quest.FM_exit_stones = "phase3";

					LAi_QuestDelay("pchar_playertype", 0.5);
				}

				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase1")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","It's too high, I can't climb the rocks."));
					chr.quest.FM_exit_stones = "phase2";
				}
			break;

			case "box2":
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_exit", "goto", "box3");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box3":
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_exit", "goto", "box4");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box4":
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_exit", "goto", "box5");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box5":
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_exit", "goto", "box1");
				PlaySound("PEOPLE\jump.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="fake_Fort_Moultrie_exit")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase3")
				{
					DoQuestReloadToLocation("Sullivan_shore3", "reload", "reload1", "FM_exit_stones");
				}

				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "look1");
					chr.quest.FM_exit_stones = "phase3";

					LAi_QuestDelay("pchar_playertype", 0.5);
				}

				if(CheckAttribute(chr, "quest.FM_exit_stones") && chr.quest.FM_exit_stones == "phase1")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","It's too high, I can't climb the rocks."));
					chr.quest.FM_exit_stones = "phase2";
				}
			break;

			case "box2":
				ChangeCharacterAddressGroup(chr, "fake_Fort_Moultrie_exit", "goto", "box3");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box3":
				ChangeCharacterAddressGroup(chr, "fake_Fort_Moultrie_exit", "goto", "box4");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box4":
				ChangeCharacterAddressGroup(chr, "fake_Fort_Moultrie_exit", "goto", "box5");
				PlaySound("PEOPLE\recoil.wav");
			break;

			case "box5":
				ChangeCharacterAddressGroup(chr, "fake_Fort_Moultrie_exit", "goto", "box1");
				PlaySound("PEOPLE\jump.wav");
				LAi_SetSitType(chr);

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_hotel")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckCharacterItem(chr,"key21"))
				{
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_hotel_room1", 2.0);
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;

			case "box2":
				if(CheckCharacterItem(chr,"key21"))
				{
					PlaySound("PEOPLE\beltkey.wav");
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;

			case "box3":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_hotel", "box", "box4");
			break;

			case "box4":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_hotel", "box", "box3");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_hotel_room1")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("INTERFACE\closet_open.wav");
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

	if(Locations[locidx].id=="Moultrie_hotel_room2")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;			
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_restaurant")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_restaurant", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_restaurant", "box", "box1");
			break;
	
			case "box3":
				if(CheckAttribute(chr,"quest.restaurant_cognac") && chr.quest.restaurant_cognac == "on")
				{
					PlaySound("INTERFACE\water_tap.wav");
					chr.quest.restaurant_cognac = "off";
					LAi_SetPlayerType(chr);

					LAi_QuestDelay("restaurant_running_cognac", 0.01);
				}
				else
				{
					if(CheckAttribute(chr,"quest.restaurant_fillbottle") && chr.quest.restaurant_fillbottle == "on")
					{
						return;
					}
					else
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
						{
							chr.quest.restaurant_fillbottle = "on";
							PlaySound("INTERFACE\water_tap.wav");
							LAi_SetStayType(chr);

							LAi_QuestDelay("restaurant_fill_cognacbottle", 0.5);
						}
						else
						{
							Logit(TranslateString("","Yes, it's Cognac!"));
							PlaySound("INTERFACE\water_tap.wav");
							chr.quest.restaurant_cognac = "on";
							LAi_SetStayType(chr);

							LAi_QuestDelay("restaurant_running_cognac", 0.5);
							LAi_QuestDelay("restaurant_bouncer_arrives", 2.0);
						}
					}
				}				

				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_restaurant_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_restaurant_kitchen", 2.0);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_store")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_store", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_store", "box", "box1");
			break;

			case "box3":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box4":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box5":
				LaunchItemsBox(&ar);
			break;

			case "box6":
				LaunchItemsBox(&ar);
			break;

			case "box7":
				PlaySound("INTERFACE\door_locked2.wav");
			break;

			case "box8":
				PlaySound("PEOPLE\blade_kling.wav");
			break;

			case "box9":
				PlaySound("PEOPLE\blade_kling.wav");
			break;

			case "box10":
				PlaySound("OBJECTS\DUEL\reload1.wav");
			break;

			case "box11":
				ChangeCharacterAddressGroup(chr, "Moultrie_store", "box", "box12");
				PlaySound("PEOPLE\step_ground1.wav");
			break;

			case "box12":
				PlaySound("INTERFACE\locked_window.wav");
				ChangeCharacterAddressGroup(chr, "Moultrie_store", "box", "box11");
			break;

			case "box13":
				PlaySound("PEOPLE\spade.wav");
			break;

			case "box14":
				PlaySound("PEOPLE\powderhorn.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_store_room")
	{
		switch(chr.boxname)
		{
			case "box2":
				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box3":
				PlaySound("OBJECTS\DUEL\sword_fallen.wav");
			break;

			case "box4":
				PlaySound("OBJECTS\DUEL\reload1.wav");
			break;

			case "box5":
				LaunchItemsBox(&ar);
			break;

			case "box6":
				PlaySound("INTERFACE\book_close.wav");
			break;

			case "box7":
				PlaySound("PEOPLE\wood1.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Moultrie_gatehouse" || Locations[locidx].id=="Moultrie_finehouse"
	|| Locations[locidx].id=="Moultrie_smallhouse" || Locations[locidx].id=="Moultrie_largehouse")
	{
		PlaySound("INTERFACE\locked_window.wav");
		return;
	}		

	if(Locations[locidx].id=="Fort_Moultrie")
	{
		switch(chr.boxname)
		{
			case "box1":
				DoQuestReloadToLocation("Fort_Moultrie", "goto", "box2", "");
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.fort_barn") && chr.quest.fort_barn == "phase1")
				{
					chr.quest.fort_barn = "";
					DoQuestReloadToLocation("Fort_Moultrie", "goto", "box1", "pchar_playertype");
				}
				else
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "randitem", "randitem1");
					chr.quest.fort_barn = "phase1";

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;

			case "box3":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box4");
			break;

			case "box4":
				LAi_SetPlayerType(chr);
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box9");
			break;

			case "box5":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\step_iron.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box6");

				LAi_QuestDelay("Fort_M_high_wall1", 0.5);
			break;

			case "box7":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box8");

				LAi_QuestDelay("pchar_staytype", 0.5);
			break;

			case "box8":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box4");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box9":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box10");
			break;

			case "box10":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "reload", "reload15");
			break;

			case "box12":
				if(CheckAttribute(chr, "quest.Fort_M_gate_wall") && chr.quest.Fort_M_gate_wall == "right")
				{
					chr.quest.Fort_M_gate_wall = "left";
					DoQuestReloadToLocation("Fort_M_tower1B", "reload", "reload8", "");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box13");
				}
			break;

			case "box13":
				if(CheckAttribute(chr, "quest.Fort_M_gate_wall") && chr.quest.Fort_M_gate_wall == "right")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box12");

					LAi_QuestDelay("Fort_M_turn_to_look4", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box17");

					LAi_QuestDelay("Fort_M_turn_to_box18", 1.0);
				}
			break;

			case "box17":
				if(CheckAttribute(chr, "quest.Fort_M_gate_wall") && chr.quest.Fort_M_gate_wall == "right")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box13");
				}
				else
				{
					if(CheckAttribute(chr, "quest.fort_box17") && chr.quest.fort_box17 == "open")
					{
						chr.quest.Fort_M_gate_wall = "right";
						DoQuestReloadToLocation("Fort_M_tower5A", "goto", "goto4", "");
					}
					else
					{
						if(CheckCharacterItem(chr,"key31"))
						{
							PlaySound("INTERFACE\key_unlock.wav");

							LAi_QuestDelay("unlock_FM_GateTower", 2.0);
						}
						else
						{
							chr.quest.Fort_M_gate_wall = "right";
							PlaySound("INTERFACE\knock.wav");
						}
					}
				}
			break;

			case "box18":
				//2 cases here later
				
				if(CheckAttribute(chr, "quest.Fort_M_ladder_wall") && chr.quest.Fort_M_ladder_wall == "right")
				{
					if(Locations[FindLocation("Fort_Moultrie")].models.always.locators == "fort2_locators_GB4")
					{
						chr.quest.Fort_M_ladder_wall = "left";
						DoQuestReloadToLocation("Fort_M_tower5C", "reload", "reload2", "");
					}
					else
					{
						if(CheckCharacterItem(chr,"bladeladder2"))
						{
							//place ladder
							if(LAi_IsFightMode(chr))
							{
								//second 'open box'
								PlaySound("PEOPLE\wood1.wav");
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladeladder2");
								EquipCharacterbyItem(chr, "bladeX4");

								Locations[FindLocation("Fort_Moultrie")].models.always.locators = "fort2_locators_GB4";
								Locations[FindLocation("Fort_M_tower5B")].reload.l4.disable = 1;		//blocked by the ladder
								chr.quest.Fort_M_gate_wall = "left";
								Locations[FindLocation("Fort_Moultrie")].image = "";

								DoQuestReloadToLocation("Fort_Moultrie", "box", "box18", "place_fort_ladder");
							}
							else
							{
								if(!IsEquipCharacterByItem(chr, "bladeladder2"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladeladder2");
								}

								LAi_LocationFightDisable(&Locations[FindLocation("Fort_Moultrie")], false);
								LAi_SetFightMode(chr, true);
							}
						}
						else
						{

						}
					}
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box19");
				}
			break;

			case "box19":
				if(CheckAttribute(chr, "quest.Fort_M_ladder_wall") && chr.quest.Fort_M_ladder_wall == "right")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box18");

					LAi_QuestDelay("Fort_M_turn_to_ri8", 1.0);
				}
				else
				{
					if(Locations[FindLocation("Fort_Moultrie")].models.always.locators == "fort2_locators_GB4")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box41");

						LAi_QuestDelay("Fort_M_turn_to_look5", 1.0);
					}
					else
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "ladder_pickup");

						LAi_QuestDelay("fort_ladder_check", 0.1);
					}
				}
			break;

			case "box41":
				if(CheckAttribute(chr, "quest.Fort_M_ladder_wall") && chr.quest.Fort_M_ladder_wall == "right")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box19");
				}
				else
				{
					
					DoQuestReloadToLocation("Fort_M_tower4B", "box", "box1", "");
				}
			break;

			case "box14":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box15");
			break;

			case "box15":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\slide_down_roof.wav");
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box5");

				LAi_QuestDelay("pchar_staytype", 1.0);
			break;

			case "box16":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall"))
				{
					if(chr.quest.Fort_M_south_wall == "right")
					{
						if(CheckAttribute(chr, "quest.Fort_M_south_wall_right") && chr.quest.Fort_M_south_wall_right == "open")
						{
							DoQuestReloadToLocation("Fort_M_tower2B", "box", "box1", "");
						}
						else
						{
							chr.quest.Fort_M_south_wall = "left";
							PlaySound("INTERFACE\knock.wav");

							LAi_QuestDelay("jump_down_to shed", 1.0);
							LAi_QuestDelay("Fort_M_turn_to_box21", 2.0);
							return;
						}
					}
					
					if(chr.quest.Fort_M_south_wall == "left")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box21");
					}
				}

				return;
			break;

			case "box11":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall"))
				{
					if(chr.quest.Fort_M_south_wall == "left")
					{
						if(CheckAttribute(chr, "quest.Fort_M_south_wall_left") && chr.quest.Fort_M_south_wall_left == "open")
						{
							DoQuestReloadToLocation("Fort_M_tower3B", "box", "box1", "");
						}
						else
						{
							chr.quest.Fort_M_south_wall = "right";
							PlaySound("INTERFACE\knock.wav");
							return;
						}
					}
					
					if(chr.quest.Fort_M_south_wall == "right")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box20");

						if(CheckAttribute(chr, "quest.Fort_M_turn_to_ship") && chr.quest.Fort_M_turn_to_ship == "done")
						{
			
						}
						else LAi_QuestDelay("Fort_M_turn_to_ship1", 1.0);
					}
				}

				return;
			break;

			case "box20":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall"))
				{
					if(chr.quest.Fort_M_south_wall == "right")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box21");
					}

					if(chr.quest.Fort_M_south_wall == "left")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box11");

						LAi_QuestDelay("Fort_M_turn_to_look3", 1.0);
					}
				}
			break;

			case "box21":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall"))
				{
					if(chr.quest.Fort_M_south_wall == "right")
					{
						PlaySound("PEOPLE\run_stone.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box16");

						LAi_QuestDelay("Fort_M_turn_to_look2", 1.0);
					}

					if(chr.quest.Fort_M_south_wall == "left")
					{
						if(CheckAttribute(chr, "quest.Fort_M_south_wall_right") && chr.quest.Fort_M_south_wall_right == "open")
						{

							PlaySound("PEOPLE\run_stone.wav");
							ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box20");

							if(CheckAttribute(chr, "quest.Fort_M_turn_to_ship") && chr.quest.Fort_M_turn_to_ship == "done")
							{
			
							}
							else LAi_QuestDelay("Fort_M_turn_to_ship1", 1.0);
						}
						else
						{
							ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box28");
							PlaySound("PEOPLE\jump.wav");
							LAi_SetSitType(chr);

							LAi_QuestDelay("pchar_playertype", 0.25);
						}
					}
				}
			break;

		//way DOWN from the wall

			case "box28":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box29");
			break;

			case "box29":
				PlaySound("PEOPLE\jump_roof.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box30");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("pchar_playertype", 0.25);
			break;

			case "box30":
				LAi_ApplyCharacterDamage(chr, 10);
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "goto100");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("pchar_laytype", 0.2);
				LAi_QuestDelay("pchar_poortype", 2.5);
				LAi_QuestDelay("pchar_oooh", 2.5);
				LAi_QuestDelay("pchar_playertype", 4.5);
			break;

		//-------------------------------------------------------------------------------------------

	/*
		//way UP to the wall

			case "box23":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box33");
				LAi_SetSitType(chr);

				LAi_QuestDelay("pchar_playertype", 2.0);
				LAi_QuestDelay("Fort_M_go_to_box24", 2.0);
			break;

			case "box24":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box26");

				LAi_QuestDelay("Fort_M_go_to_box25", 2.0);
			break;

			case "box25":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box26");

				LAi_QuestDelay("Fort_M_go_to_box26", 2.0);
			break;

			case "box26":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box27");

				LAi_QuestDelay("Fort_M_go_to_box27", 2.0);
			break;

			case "box27":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box28");

				LAi_QuestDelay("Fort_M_go_to_box28", 1.0);
			break;

			case "box28":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box21");

				LAi_QuestDelay("Fort_M_prepare_to_box21", 1.0);
			break;
	*/
		//-------------------------------------------------------------------------------------------
		
	/*
			case "box29":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box30");
			break;

			case "box30":
				PlaySound("PEOPLE\slide_down_roof.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box31");
			break;

			case "box31":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box32");
			break;

			case "box32":
				chr.quest.Fort_M_south_wall = "right";
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "goto100");
				LAi_SetSitType(chr);
				
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;
	*/
		//-------------------------------------------------------------------------------------------
		//flag tower top

			case "box34":
				if(CheckCharacterItem(chr,"bladeflag_usa"))
				{
					PlaySound("PEOPLE\run_wood.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "goto", "box35");
				}
				else
				{
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box40");
				}
			break;

			case "box35":
				if(CheckAttribute(chr, "quest.Fort_M_flag_pos"))
				{
				    if(chr.quest.Fort_M_flag_pos == "up")
				    {
					    PlaySound("PEOPLE\step_stairway.wav");
					    ChangeCharacterAddressGroup(chr, "Fort_Moultrie", "box", "box40");
					    AddQuestRecord("Navigation_items","12");

					    LAi_QuestDelay("after_bladespyglass6_pickup", 1.0);	
				    }

				    if(chr.quest.Fort_M_flag_pos == "down")
				    {
					    PlaySound("OBJECTS\DUEL\man_attack1.wav");

					    LAi_QuestDelay("raise_usa_flag", 1.0);
				    }

				    if(chr.quest.Fort_M_flag_pos == "none")
				    {
					if(LAi_IsFightMode(chr))
					{
						//second 'open box'
						PlaySound("PEOPLE\clothes1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladeflag_usa");
						EquipCharacterByItem(chr, "bladeX4");
						SetNextWind("NE",30);

						LAi_QuestDelay("place_usa_flag", 1.0);
					}
					else
					{
						if(!IsEquipCharacterByItem(chr, "bladeflag_usa"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeflag_usa");
						}

						LAi_LocationFightDisable(&Locations[FindLocation("Fort_Moultrie")], false);
						LAi_SetFightMode(chr, true);
					}
				    }
				}
			break;
		//-------------------------------------------------------------------------------------------
		//unlock 3 houses

			case "box36":
				if(CheckCharacterItem(chr,"key5"))
				{
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_FM_barracks", 2.0);
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;

			case "box37":
				if(CheckCharacterItem(chr,"key6"))
				{
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_FM_prison", 2.0);
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;

			case "box38":
				if(CheckCharacterItem(chr,"key7"))
				{
					PlaySound("INTERFACE\key_unlock.wav");

					LAi_QuestDelay("unlock_FM_Ghouse", 2.0);
				}
				else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			break;

			case "box39":
				DoQuestReloadToLocation("Fort_M_tower2C", "reload", "reload2", "");
			break;

			case "box40":
				DoQuestReloadToLocation("Fort_M_tower3C", "goto", "attic", "");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower2B")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall_right") && chr.quest.Fort_M_south_wall_right == "open")
				{
					chr.quest.Fort_M_south_wall = "left";
					DoQuestReloadToLocation("Fort_Moultrie", "goto", "box16", "Fort_M_turn_to_box21");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower3B")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.Fort_M_south_wall_left") && chr.quest.Fort_M_south_wall_left == "open")
				{
					chr.quest.Fort_M_south_wall = "right";
					DoQuestReloadToLocation("Fort_Moultrie", "goto", "box11", "Fort_M_turn_to_box21");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower2C")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
		//		PlaySound("AMBIENT\JAIL\door_003.wav");
		//		LaunchItemsBox(&ar);

				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
		//		PlaySound("AMBIENT\JAIL\door_003.wav");
		//		LaunchItemsBox(&ar);

				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box5":
		//		PlaySound("AMBIENT\JAIL\door_003.wav");
		//		LaunchItemsBox(&ar);

				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower3C")
	{
		switch(chr.boxname)
		{
			case "box1":
		//		PlaySound("AMBIENT\JAIL\door_003.wav");
		//		LaunchItemsBox(&ar);

				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box2":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
		//		PlaySound("AMBIENT\JAIL\door_003.wav");
		//		LaunchItemsBox(&ar);

				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower4B")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(Locations[FindLocation("Fort_Moultrie")].models.always.locators == "fort2_locators_GB4")
				{
					chr.quest.Fort_M_ladder_wall = "right";
					DoQuestReloadToLocation("Fort_Moultrie", "goto", "box41", "");
				}
				else
				{
					PlaySound("INTERFACE\lever_stuck.wav");
					Logit(TranslateString("","No, the door isn't locked but something is blocking it."));
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_M_tower5C")
	{
		switch(chr.boxname)
		{
			case "box6":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_Moultrie_prison")
	{
		switch(chr.boxname)
		{
		//outside cells
			case "box2":
				//nr1

				if(CheckAttribute(chr, "cell2") && chr.cell2 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell2 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell2 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "0")
						{
							chr.locked_cells = "1";

							LAi_QuestDelay("pchar_1", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload2A");
					}
				}
			break;

			case "box6":
				//nr2

				if(CheckAttribute(chr, "cell6") && chr.cell6 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell6 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell6 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "1")
						{
							chr.locked_cells = "2";

							LAi_QuestDelay("pchar_2", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload6A");
					}
				}
			break;

			case "box5":
				//nr3

				if(CheckAttribute(chr, "cell5") && chr.cell5 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell5 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell5 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "2")
						{
							chr.locked_cells = "3";

							LAi_QuestDelay("pchar_3", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload5A");
					}
				}
			break;

			case "box3":
				//nr4

				if(CheckAttribute(chr, "cell3") && chr.cell3 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell3 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell3 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "3")
						{
							chr.locked_cells = "4";

							LAi_QuestDelay("pchar_4", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload3A");
					}
				}
			break;

			case "box7":
				//nr5

				if(CheckAttribute(chr, "cell7") && chr.cell7 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell7 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell7 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "4")
						{
							chr.locked_cells = "5";

							LAi_QuestDelay("pchar_5", 1.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload7A");
					}
				}
			break;

			case "box4":
				//nr6

				if(CheckAttribute(chr, "cell4") && chr.cell4 == "locked")
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.cell4 = "open";

						LAi_QuestDelay("reset_cells", 1.0);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					if(CheckCharacterItem(chr,"key32"))
					{
						PlaySound("INTERFACE\key_lock.wav");
						chr.cell4 = "locked";

						if(CheckAttribute(chr, "locked_cells") && chr.locked_cells == "5")
						{
							chr.locked_cells = "6";

							LAi_QuestDelay("pchar_6", 1.0);
							LAi_QuestDelay("pchar_staytype", 1.0);
							LAi_QuestDelay("open_prison_stairs", 2.0);
						}
						else LAi_QuestDelay("reset_cells", 1.0);
					}
					else
					{
						PlaySound("INTERFACE\rusty.wav");
						ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload4A");
					}
				}
			break;

		//-------------------------------------------------------------------------------------------------
		//inside cells
			case "box8":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload2");
			break;

			case "box9":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload3");
			break;
			
			case "box10":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload4");
			break;
			
			case "box11":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload5");
			break;
			
			case "box12":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload6");
			break;
			
			case "box13":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_prison", "goto", "reload7");
			break;
		}

		return;
	}


	if(Locations[locidx].id=="Fort_Moultrie_gunpowder")
	{
		switch(chr.boxname)
		{
			case "box3":
				PlaySound("PEOPLE\powderhorn.wav");
				return;
			break;

			case "box4":
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_Moultrie_armory")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_Moultrie_armory", 2.0);
			break;

			case "box2":
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box4":
				PlaySound("OBJECTS\DUEL\reload1.wav");
			break;

			case "box5":
				PlaySound("PEOPLE\clothes1.wav");
				Logit(TranslateString("","No, nothing behind the curtain."));
			break;

			case "box6":
				PlaySound("PEOPLE\blade_kling.wav");
			break;

			case "box7":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_armory", "box", "box8");
			break;

			case "box8":
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_armory", "box", "box7");
			break;

			case "box9":
				PlaySound("PEOPLE\grass_noise.wav");
			break;
		}

		return;
	}
	
	if(Locations[locidx].id=="Lieutenant_G_kitchen")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_food", 0.1);
			break;

			case "box2":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_plates", 0.1);
			break;

			case "box3":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_plates", 0.1);
			break;

			case "box4":
				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Lieutenant_G_office")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_office_box1", 0.1);
			break;

			case "box2":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("bladeflag_usa_equip_check", 0.1);
			break;

			case "box3":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_office_box3", 0.1);
			break;

			case "box4":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_office_box4", 0.1);
			break;
			
			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_office_box5", 0.1);
			break;

			case "box6":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_office_box6", 0.1);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Lieutenant_G_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_G_books", 0.1);
			break;

			case "box2":
				PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				Logit(TranslateString("","Hmm, what are they doing? Something's hanging down from that tree."));
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Fort_Moultrie_shore")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_shore", "goto", "box4");
			break;

			case "box2":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "return");

				LAi_QuestDelay("FM_sh_go_to_return", 1.0);
			break;

			case "box3":
				PlaySound("PEOPLE\jump_roof.wav");
				ChangeCharacterAddressGroup(chr, "Fort_Moultrie_shore", "goto", "return");
			break;

			case "box4":
				DoQuestReloadToLocation("GB_Charleston_port", "goto", "box9", "Ch_port_turn_to_ship_1");//was box1
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_port")
	{
		switch(chr.boxname)
		{
			case "box7":
				PlaySound("PEOPLE\creak2.wav");
				PlaySound("PEOPLE\step_water.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box8");
			break;

			case "box8":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box1");
			break;

			case "box1":
		InterfaceStates.Buttons.Save.enable = 1;	//reset for temp disabled savegame, caused trouble with the boat to FM_shore
				DoQuestReloadToLocation("Fort_Moultrie_shore", "goto", "box3", "FM_sh_turn_to_cit1");//was box2
			break;

			case "box9":
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box7");

				LAi_QuestDelay("Ch_port_box9", 1.5);
			break;
	//...........................................................................................................
			case "box2":
				//prison
				
				PlaySound("INTERFACE\knock.wav");

				LAi_QuestDelay("Charleston_prisoner", 1.0);
			break;

			case "box3":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box4");

				LAi_QuestDelay("Ch_port_box4_phase1", 0.5);
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.Ch_port_box4") && chr.quest.Ch_port_box4 == "phase3")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box3");
				}

				if(CheckAttribute(chr, "quest.Ch_port_box4") && chr.quest.Ch_port_box4 == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box3");

					LAi_QuestDelay("Ch_port_box4_phase3", 1.0);
				}

				if(CheckAttribute(chr, "quest.Ch_port_box4") && chr.quest.Ch_port_box4 == "phase1")
				{
					PlaySound("INTERFACE\knock.wav");

					LAi_QuestDelay("Ch_port_box4_phase2", 1.0);
				}
			break;
	//...........................................................................................................
			case "box5":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box6");

				LAi_QuestDelay("Ch_port_box6_phase1", 0.5);
			break;
			
			case "box6":
				if(CheckAttribute(chr, "quest.Ch_port_box6") && chr.quest.Ch_port_box6 == "phase3")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box5");
				}

				if(CheckAttribute(chr, "quest.Ch_port_box6") && chr.quest.Ch_port_box6 == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box5");

					LAi_QuestDelay("Ch_port_box6_phase3", 1.0);
				}

				if(CheckAttribute(chr, "quest.Ch_port_box6") && chr.quest.Ch_port_box6 == "phase1")
				{
					PlaySound("INTERFACE\knock.wav");

					LAi_QuestDelay("Ch_port_box6_phase2", 1.0);
				}
			break;
	//...........................................................................................................
			case "box10":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box11");

				LAi_QuestDelay("Ch_port_box11_phase1", 0.5);
			break;

			case "box11":
				if(CheckAttribute(chr, "quest.Ch_port_box11") && chr.quest.Ch_port_box11 == "phase3")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "box10");
				}

				if(CheckAttribute(chr, "quest.Ch_port_box11") && chr.quest.Ch_port_box11 == "phase2")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box10");

					LAi_QuestDelay("Ch_port_box11_phase3", 1.0);
				}

				if(CheckAttribute(chr, "quest.Ch_port_box11") && chr.quest.Ch_port_box11 == "phase1")
				{
					PlaySound("INTERFACE\knock.wav");

					LAi_QuestDelay("Ch_port_box11_phase2", 1.0);
				}
			break;

	//...........................................................................................................
			case "box12": PlaySound("INTERFACE\knock.wav"); break;
	//...........................................................................................................
			case "box13":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "box", "box14");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_port", "officers", "reload1_1");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
					LAi_SetOfficerType(characterFromID("Jupiter"));
				}
			break;

			case "box14":
				PlaySound("PEOPLE\jump.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "GB_Charleston_port", "goto", "jump_ground");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_town")
	{
		switch(chr.boxname)
		{
			//POE'S HOUSE

			case "box1":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box8");
			break;

			case "box8":
				chr.quest.Ch_town_box11 = "phase1";
				PlaySound("PEOPLE\run_stone.wav");

				if(CheckAttribute(chr, "quest.Poe_knocking") && chr.quest.Poe_knocking == "done")
				{
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box10");
				}
				else ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box11");
			break;

			case "box11":
				if(CheckAttribute(chr, "quest.Ch_town_box11") && chr.quest.Ch_town_box11 == "phase3")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box10");
				}

				if(CheckAttribute(chr, "quest.Ch_town_box11") && chr.quest.Ch_town_box11 == "phase1")
				{
					chr.quest.Ch_town_box11 = "neutral";
					PlaySound("INTERFACE\knock.wav");
					chr.quest.Poe_knocking = "done";

					LAi_QuestDelay("Ch_town_box11_phase2", 1.0);
				}
			break;

			case "box10":
				chr.quest.Ch_town_box11 = "phase1";	//reset previous
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box12");

				LAi_QuestDelay("Ch_town_box12_turn_to_look_b12", 0.5);
				LAi_QuestDelay("Ch_town_box12_turn_to_box13", 0.5);
			break;

			case "box12":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box13");
			break;

			case "box13":
				DoQuestReloadToLocation("Poe_entre", "reload", "reload1", "");
			break;

			case "box14":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box15");
			break;

			case "box15":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box16");

				LAi_QuestDelay("Ch_town_box15_turn_to_box8", 0.5);
			break;

			case "box16":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box2");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "goto", "Poe_Jup");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
				}
			break;

			case "box2":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box1");
			break;

			//...................................................................................			
			//HIGH FLAMHOUSE

			case "box3":
				PlaySound("INTERFACE\locked_window.wav");
				return;
			break;

			case "box4":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload10");
			break;

			case "box9":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box5");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload10_1");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
				}
			break;

			case "box5":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box3");
			break;

			//...................................................................................
			//BROTHEL GATE
		
			case "box6":
				if(CheckAttribute(chr, "quest.Ch_town_box6") && chr.quest.Ch_town_box6 == "locked")
				{
					if(CheckCharacterItem(chr,"key28"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.Ch_town_box6 = "unlocked";
						TakeItemFromCharacter(chr, "key28");
					}
					else
					{
						Logit(TranslateString("","STRIKE - Brothel closed."));
						PlaySound("INTERFACE\locked_window.wav");

						if(CheckAttribute(chr, "been_to_church") && chr.been_to_church == "yes")
						{
							if(CheckAttribute(chr, "enter_brothel") && chr.enter_brothel == "ready")
							{
								LAi_QuestDelay("check_brothel_gate", 1.0);
							}
							else 
							{
								if(CheckCharacterItem(chr,"bladepickaxe2") && CheckCharacterItem(chr,"measuring_tape") && CheckCharacterItem(chr,"book61D"))
								{
									int na = GetCharacterItem(chr, "nails");
									int peg = GetCharacterItem(chr, "peg");

									if(na == 6 && peg == 4)	
									{
										if(CheckCharacterItem(chr,"book61A") || CheckCharacterItem(chr,"book61B")
										|| CheckCharacterItem(chr,"book61C1") || CheckCharacterItem(chr,"book61C2"))
										{
											chr.enter_brothel = "ready";

											chr.quest.under_balcony.win_condition.l1 = "locator";
											chr.quest.under_balcony.win_condition.l1.location = "GB_Charleston_town";
											chr.quest.under_balcony.win_condition.l1.locator_group = "goto";
											chr.quest.under_balcony.win_condition.l1.locator = "brothel_key";
											chr.quest.under_balcony.win_condition = "under_balcony";
										}					
									}
								}

								if(CheckAttribute(chr, "enter_brothel") && chr.enter_brothel == "ready")
								{
									LAi_QuestDelay("check_brothel_gate", 1.0);
								}
								else 
								{
									LAi_QuestDelay("not_ready_for_brothel_yet", 1.0);
								}
							}	
						}
					}

					return;
				}
				else
				{
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload19");
				}
			break;

			case "box7":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box6");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload19_1");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
				}
			break;

			//...................................................................................
			//2 LOCKED BROTHELS

			case "box44":
				Logit(TranslateString("","STRIKE - Brothel closed."));
				PlaySound("INTERFACE\knock.wav"); 
			break;

			case "box48":
				Logit(TranslateString("","STRIKE - Brothel closed."));
				PlaySound("INTERFACE\knock.wav"); 
			break;

			//...................................................................................
			//OPEN STORE

			case "box17":
				chr.quest.Ch_town_box18 = "way_in";
				chr.quest.Ch_town_box19 = "turn_shelf";
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box19");
			break;
		
			case "box19":
				if(CheckAttribute(chr, "quest.Ch_town_box19") && chr.quest.Ch_town_box19 == "go_back")
				{
					chr.quest.Ch_town_box18 = "way_out";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box17");
				}

				if(CheckAttribute(chr, "quest.Ch_town_box19") && chr.quest.Ch_town_box19 == "turn_back")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box18");

					LAi_QuestDelay("Ch_town_box19_2", 0.5);
				}

				if(CheckAttribute(chr, "quest.Ch_town_box19") && chr.quest.Ch_town_box19 == "turn_shelf")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "look19");

					LAi_QuestDelay("Ch_town_box19_1", 0.5);
				}
			break;

			//...................................................................................
			//OPEN STORE 2

			case "box40":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box41");
			break;

			case "box41":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box40");
			break;

			//...................................................................................
			//PLANK WALK
			
			case "box20":
				PlaySound("PEOPLE\place_planks.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box21");

				LAi_QuestDelay("Ch_town_box20", 0.5);
			break;

			case "box21":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload18");

				LAi_QuestDelay("Ch_town_box21", 0.5);
			break;

			case "box22":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box23");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload18_1");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
				}

				LAi_QuestDelay("Ch_town_box22", 0.5);
			break;

			case "box23":
				PlaySound("PEOPLE\place_planks.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box20");
			break;

			//...................................................................................
			//HIGH ROOFS

			case "box24":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box25");
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box44");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box25":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box26");
				LAi_SetSitType(chr);

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box44");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box26":
				chr.quest.Ch_town_box27 = "phase1";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box27");
				
				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box44");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box27":
				if(CheckAttribute(chr, "quest.Ch_town_box27") && chr.quest.Ch_town_box27 == "phase2")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "penthouse");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box44");
	
					LAi_QuestDelay("pchar_playertype", 0.5);

					chr.quest.Ch_PH.win_condition.l1 = "locator";
					chr.quest.Ch_PH.win_condition.l1.location = "GB_Charleston_penthouse";
					chr.quest.Ch_PH.win_condition.l1.locator_group = "reload";
					chr.quest.Ch_PH.win_condition.l1.locator = "reload2";
					chr.quest.Ch_PH.win_condition = "Ch_PH";
				}

				if(CheckAttribute(chr, "quest.Ch_town_box27") && chr.quest.Ch_town_box27 == "phase1")
				{
					PlaySound("INTERFACE\locked_window.wav");	

					LAi_QuestDelay("Ch_town_box27", 0.5);
				}
			break;

			case "box28":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box29");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb29");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			
			case "box29":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box30");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "high");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box30":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box31");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb31");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box31":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box32");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb31");
	
				LAi_QuestDelay("Ch_town_box32", 0.5);
			break;

			case "box32":
				PlaySound("PEOPLE\run_roof.wav");
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box33");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb31");
	
				LAi_QuestDelay("Ch_town_box33", 0.5);
			break;

			case "box33":
				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box34");

				LAi_SetSitType(chr);
				
				LAi_QuestDelay("Ch_town_box33_1", 0.5);
			break;

			case "box34":
				chr.quest.Ch_town_box35 = "phase1";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box35");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb31");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box35":
				if(CheckAttribute(chr, "quest.Ch_town_box35") && chr.quest.Ch_town_box35 == "phase2")
				{
					CreateParticleSystemX("blast_dirt_gray", 14.0, 10.8, 37.7, 14.0, 10.8, 37.7,10);
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\slide_down_roof.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box36");

					LAi_QuestDelay("Ch_town_box35_2", 0.5);
				}

				if(CheckAttribute(chr, "quest.Ch_town_box35") && chr.quest.Ch_town_box35 == "phase1")
				{
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "lookb35");

					LAi_QuestDelay("Ch_town_box35_1", 0.5);
				}
			break;

			case "box36":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box37");

				LAi_QuestDelay("Ch_town_box36", 0.5);
			break;

			case "box38":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload12");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookb35");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			//...................................................................................
			//TERRACE

			case "box53":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box43");
			break;

			case "box43":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "fence");

				LAi_QuestDelay("Ch_town_box43", 0.5);
			break;

			case "box50":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box51");
			break;

			case "box51":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box52");

				LAi_QuestDelay("Ch_town_box51", 0.5);
			break;

			case "box52":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload4");
			break;

			//...................................................................................
			//DUPIN TOUR

			case "box39":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box54");

				ChangeCharacterAddressGroup(characterFromID("Charleston_guard2"), "GB_Charleston_town", "goto", "guard2");
			break;

			case "box54":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box59");
			break;

			case "box56":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box57");

				LAi_QuestDelay("Ch_town_box56", 0.5);
			break;

			case "box57":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box58");

				LAi_QuestDelay("Ch_town_box57", 0.5);
			break;

			case "box58":
				SetNextWeather("Clear");		//rain sound can be heard in opium den
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload17");

				LAi_QuestDelay("Ch_town_box58", 0.5);
			break;

			case "box59":
				PlaySound("INTERFACE\metal_hatch_close.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box56");

				LAi_QuestDelay("Ch_town_box59", 0.5);
			break;

			//...................................................................................
			//PYM BRIDGE
			
			case "box55":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload15");
			break;

			case "box60":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload14");
				LAi_SetPlayerType(chr);
			break;

			//...................................................................................
			//OPIUM PLANK

			case "box61":
				SetNextWeather("Clear");		//rain sound can be heard in opium den
				PlaySound("PEOPLE\place_planks.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box62");

				LAi_QuestDelay("Ch_town_box61", 0.5);
			break;

			case "box62":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "reload", "reload23");

				LAi_QuestDelay("Ch_town_box62", 0.5);
			break;

			case "box63":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box64");

				ChangeCharacterAddressGroup(characterFromID("Charleston_guard2"), "GB_Charleston_town", "goto", "guard3");

				LAi_QuestDelay("Ch_town_box63", 0.5);
			break;

			case "box64":
				PlaySound("PEOPLE\place_planks.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_town", "goto", "box61");

				LAi_QuestDelay("Ch_town_box64", 0.5);
			break;

			//...................................................................................
			//OUTSIDE DUPIN ENTRE

			case "box65":
				if(CheckAttribute(chr, "quest.town_box65") && chr.quest.town_box65 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("D_scalpel_check", 0.1);
				}
				else 
				{
					if(CheckCharacterItem(chr,"D_key23"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.town_box65 = "unlocked";

						LAi_QuestDelay("D_scalpel_check", 0.1);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			//...................................................................................
			//CLOSE TO TAVERN
			case "box45":
				Logit(TranslateString("","Visitors to the Tavern - please use the door to the left."));
				PlaySound("INTERFACE\knock.wav"); 
			break;

			//...................................................................................
			//NEVER OPENED

			case "box42": PlaySound("INTERFACE\knock.wav"); break;
			case "box43": PlaySound("INTERFACE\knock.wav"); break;
			case "box46": PlaySound("INTERFACE\knock.wav"); break;
			case "box47": PlaySound("INTERFACE\knock.wav"); break;
			case "box49": PlaySound("INTERFACE\knock.wav"); break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_town_tavern")
	{
		switch(chr.boxname)
		{
			case "box1":
				Logit(TranslateString("","Winecellar."));
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_governor_office")
	{
		switch(chr.boxname)
		{
			case "box1":
				Logit(TranslateString("","Hmm, nothing of use here."));
				PlaySound("INTERFACE\paper.wav");
			break;

			case "box2":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				Logit(TranslateString("","Hmm, nothing of use here."));
				PlaySound("INTERFACE\paper.wav");
			break;

			case "box5":
				PlaySound("INTERFACE\book_close.wav");
			break;

			case "box6":		
				PlaySound("INTERFACE\book_close.wav");
			break;

			case "box7":
				if(CheckAttribute(chr, "quest.gov_office_clock") && chr.quest.gov_office_clock == "ticking")
				{
					return;
				}
				else
				{
					chr.quest.gov_office_clock = "ticking";
					LAi_SetStayType(chr);
					PlaySound("INTERFACE\clock_ticking.wav");

					LAi_QuestDelay("gov_office_ticking", 3.5);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_governor_bedroom")
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
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				PlaySound("INTERFACE\book_close.wav");
			break;

			case "box5":
				PlaySound("INTERFACE\book_close.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_governor_kitchen")
	{
		switch(chr.boxname)
		{
			
			case "box1":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
			
			case "box2":
				Logit(TranslateString("","Servants."));
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_store")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.store_box2") && chr.quest.store_box2 == "locked")
				{
					PlaySound("INTERFACE\locked_window.wav");
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "GB_Charleston_store", "box", "box3");
				}
			break;

			case "box3":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_store", "box", "box2");
			break;

			case "box4":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box6":		
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;

			case "box7":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box8":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box9":
				PlaySound("PEOPLE\clothes1.wav");
				Logit(TranslateString("","It's flour in these sacks."));	
			break;

			case "box10":
				PlaySound("AMBIENT\TAVERN\open_bottle.wav");
				
				LAi_QuestDelay("drink", 1.0);
			break;

			case "box11":
				PlaySound("INTERFACE\book_close.wav");	
			break;

			case "box12":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_store", "box", "box13");
			break;			

			case "box13":
				if(CheckAttribute(chr,"quest.store_box13") && chr.quest.store_box13 == "on")
				{
					return;
				}
				else
				{
					chr.quest.store_box13 = "on";
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("store_ladder_down", 1.0);
				}
			break;

			case "box14":
				Logit(TranslateString("","Storeroom."));
				PlaySound("INTERFACE\knock.wav");	
			break;

			case "box15":
				Logit(TranslateString("","Private."));
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Poe_entre")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\small_door_locked.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Landlady_private")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				PlaySound("INTERFACE\small_door_locked.wav");
			break;

			case "box3":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Poe_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
		
				LAi_QuestDelay("return_Poe_items", 0.1);
			break;

			case "box2":
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_Poe_books", 0.1);
			break;

			case "box3":
				Logit(TranslateString("","Hmm, many notes, letters and books here"));
				PlaySound("INTERFACE\paper.wav");
			break;

			case "box4":
				Logit(TranslateString("","The Narrative of Arthur Gordon Pym of Nantucket"));
				PlaySound("INTERFACE\book_close.wav");
			break;

			case "box5":
				Logit(TranslateString("","A photo of Edgar"));
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			break;

			case "box6":
				Logit(TranslateString("","The painting is signed by Frans Hals 1641"));
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			break;

			case "box7":
				if(CheckAttribute(chr, "quest.poe_box7") && chr.quest.poe_box7 == "unlocked")
				{
					PlaySound("INTERFACE\chart_move.wav");
					PlaySound("INTERFACE\chart_move.wav");
					LaunchItemsBox(&ar);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box8":
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Dupin_office")
	{
		switch(chr.boxname)
		{
			case "box2":
				if(CheckAttribute(chr, "quest.dupin_office_box2") && chr.quest.dupin_office_box2 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("D_scissors_check", 0.1);
				}
				else 
				{
					if(CheckCharacterItem(chr,"D_key23"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.dupin_office_box2 = "unlocked";

						LAi_QuestDelay("D_scissors_check", 0.1);						
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box3":
				Logit(TranslateString("","William Kidd 1645 - 1701"));
			break;

			case "box4":
				Logit(TranslateString("","C. Auguste Dupin has earned this certificate for..."));
			break;
			
			case "box5":
				Logit(TranslateString("","Fort Moultrie"));
			break;

			case "box6":
				Logit(TranslateString("","Edgar Allan Poe"));
			break;

			case "box7":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_Dupin_items", 0.1);
			break;

			case "box8":
				PlaySound("PEOPLE\basket.wav");
			break;

			case "box9":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("D_feather_check", 0.1);
			break;
			
		}

		return;
	}

	if(Locations[locidx].id=="Dupin_private")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("D_compasses_check", 0.1);
			break;

			case "box2":
				DoQuestReloadToLocation("GB_Charleston_town", "reload", "reload17", "return_to_Dupin");
			break;

			case "box3":
				//LEVER IS UP - HATCH CLOSED

				PlaySound("INTERFACE\lever_down.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "mh10_l_dupin_open";

				LAi_QuestDelay("Dupin_private_hatch_unlock", 0.5);
			break;
			
			case "box4":
				//LEVER IS DOWN - HATCH OOPEN

				PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "mh10_l_dupin_closed";

				LAi_QuestDelay("Dupin_private_hatch_lock", 0.5);
			break;

			case "box5":
				PlaySound("INTERFACE\knock.wav");
			break;

			case "box6":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box7":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_Dupin_revolver", 0.1);
			break;

			case "box8":
				PlaySound("INTERFACE\locked_window.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_opium")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\basket.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.opium_box2") && chr.quest.opium_box2 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("D_magnifying_check", 0.1);
				}
				else 
				{
					if(CheckCharacterItem(chr,"D_key23"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.opium_box2 = "unlocked";

						LAi_QuestDelay("D_magnifying_check", 0.1);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.opium_box4") && chr.quest.opium_box4 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("D_tweezers_check", 0.1);
				}
				else 
				{
					if(CheckCharacterItem(chr,"D_key23"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.opium_box4 = "unlocked";

						LAi_QuestDelay("D_tweezers_check", 0.1);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.opium_box5") && chr.quest.opium_box5 == "unlocked")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("return_medicine_leaves", 0.1);
				}
				else 
				{
					if(CheckCharacterItem(chr,"D_key23"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.opium_box5 = "unlocked";

						LAi_QuestDelay("return_medicine_leaves", 0.1);
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;
		/*	
			case "box6":
				ChangeCharacterAddressGroup(characterFromID("Charleston_guard2"), "GB_Charleston_town", "goto", "guard3");

				if(IsOfficer(CharacterFromID("Jupiter")))				
				{
					for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
					RemovePassenger(chr, characterFromID("Jupiter"));

					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "GB_Charleston_town", "officers", "reload23_1");
					AddPassenger(chr, characterFromID("Jupiter"), 0);
					SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
				}

				DoQuestReloadToLocation("GB_Charleston_town", "goto", "box63", "CH_town_turn_to_off_r23");
			break;
		*/
			case "box7":
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}
	
	if(Locations[locidx].id=="GB_Charleston_penthouse")
	{
		switch(chr.boxname)
		{
			case "box3":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_penthouse", "reload", "reload3");

				chr.quest.Ch_town_box28.win_condition.l1 = "locator";
				chr.quest.Ch_town_box28.win_condition.l1.location = "GB_Charleston_town";
				chr.quest.Ch_town_box28.win_condition.l1.locator_group = "goto";
				chr.quest.Ch_town_box28.win_condition.l1.locator = "box28";
				chr.quest.Ch_town_box28.win_condition = "Ch_town_box28";
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Pym_drawing_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\locked_window.wav");
			break;
		
			case "box3":
				//WINDOW
				
				DoQuestReloadToLocation("GB_Charleston_town", "goto", "roof_return", "roofs_too_high");
			break;

			case "box4":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;
		
			case "box5":
				PlaySound("VOICE\ENGLISH\blaze_very_nice.wav"); 
				Logit(TranslateString("","The Brig Grampus"));		
			break;

			case "box6":
				//Caves
				LaunchItemsBox(&ar);
		
				if(CheckCharacterItem(chr,"bladeemptysack_P") || CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					LAi_QuestDelay("book57_pickup", 0.1);
				}
				else LAi_QuestDelay("Pym_books_return", 0.1);
			break;

			case "box7":
				//Travels
				LaunchItemsBox(&ar);

				if(CheckCharacterItem(chr,"bladeemptysack_P") || CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					LAi_QuestDelay("book56_pickup", 0.1);
				}
				else LAi_QuestDelay("Pym_books_return", 0.1);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Pym_bedroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;
		
			case "box4":
				if(CheckCharacterItem(chr,"bladeanchor"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeanchor"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeanchor");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'
						PlaySound("INTERFACE\klonk.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladeanchor");
						EquipCharacterByItem(chr, "bladeX4");

						LAi_QuestDelay("place_pym_anchor", 0.5);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_bedroom")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					LAi_SetSitType(chr);

					if(CheckAttribute(chr, "quest.pym_anchor") && chr.quest.pym_anchor == "placed")
					{
						if(CheckAttribute(chr, "quest.pym_niche") && chr.quest.pym_niche == "open")
						{
							LAi_QuestDelay("Ship_painting_down", 0.5);
						}
						else LAi_QuestDelay("Ship_painting_up", 0.5);
					}
					else LAi_QuestDelay("Ship_painting_attempt_up", 1.0);
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.pym_niche") && chr.quest.pym_niche == "open")
				{
					LaunchItemsBox(&ar);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_mhm.wav"); 
					Logit(TranslateString("","Nantucket Whaling Ships"));
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Pym_study")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box2":
				//Piracy
				LaunchItemsBox(&ar);

				if(CheckCharacterItem(chr,"bladeemptysack_P") || CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					LAi_QuestDelay("book59_pickup", 0.1);
				}
				else LAi_QuestDelay("Pym_books_return", 0.1);
			break;

			case "box3":
				//Dogs
				LaunchItemsBox(&ar);

				if(CheckCharacterItem(chr,"bladeemptysack_P") || CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					LAi_QuestDelay("book60_pickup", 0.1);
				}
				else LAi_QuestDelay("Pym_books_return", 0.1);
			break;

			case "box4":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("pchar_equip_emptysack_check", 0.1);
			break;

			case "box5":
				Logit(TranslateString("","16.30???"));
				PlaySound("INTERFACE\clock.wav");
			break;

			case "box6":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box7");
			break;

			case "box7":
				//Cannibalism
				LaunchItemsBox(&ar);

				if(CheckCharacterItem(chr,"bladeemptysack_P") || CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					LAi_QuestDelay("book58_pickup", 0.1);
				}
				else LAi_QuestDelay("Pym_books_return", 0.1);
			break;

			case "box8":
				chr.quest.pym_ladder = "way_up";
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box9");
			break;

			case "box9":
				if(CheckAttribute(chr, "quest.pym_ladder") && chr.quest.pym_ladder == "way_up")
				{
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box13");
				}
				else
				{
					PlaySound("PEOPLE\jump.wav");
					ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box8");
				}
			break;

			case "box10":
				PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			break;

			case "box11":
				if(CheckCharacterItem(chr,"bladesemifullsack_P"))
				{
					if(!IsEquipCharacterByItem(chr, "bladesemifullsack_P"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladesemifullsack_P");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'
						PlaySound("PEOPLE\clothes1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladesemifullsack_P");
						EquipCharacterByItem(chr, "bladeX4");

						if(CheckCharacterItem(chr,"book55A")) chr.quest.book55A = "placed";
						if(CheckCharacterItem(chr,"book55B")) chr.quest.book55B = "placed";
						if(CheckCharacterItem(chr,"book55D")) chr.quest.book55D = "placed";
						if(CheckCharacterItem(chr,"book56")) chr.quest.book56 = "placed";
						if(CheckCharacterItem(chr,"book57")) chr.quest.book57 = "placed";
						if(CheckCharacterItem(chr,"book58")) chr.quest.book58 = "placed";
						if(CheckCharacterItem(chr,"book59")) chr.quest.book59 = "placed";
						if(CheckCharacterItem(chr,"book60")) chr.quest.book60 = "placed";
						
						TakeItemFromCharacter(chr, "book55A"); TakeItemFromCharacter(chr, "book55B");
						TakeItemFromCharacter(chr, "book55D"); TakeItemFromCharacter(chr, "book56");
						TakeItemFromCharacter(chr, "book57");  TakeItemFromCharacter(chr, "book58");
						TakeItemFromCharacter(chr, "book59");  TakeItemFromCharacter(chr, "book60");

						LAi_QuestDelay("place_pym_sack", 0.5);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{

				    if(CheckCharacterItem(chr,"bladefullsack_P"))
				    {
					if(!IsEquipCharacterByItem(chr, "bladefullsack_P"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladefullsack_P");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'
						
						PlaySound("INTERFACE\step_path.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladefullsack_P");
						EquipCharacterByItem(chr, "bladeX4");

						TakeItemFromCharacter(chr, "book55A"); TakeItemFromCharacter(chr, "book55B");
						TakeItemFromCharacter(chr, "book55D"); TakeItemFromCharacter(chr, "book56");
						TakeItemFromCharacter(chr, "book57");  TakeItemFromCharacter(chr, "book58");
						TakeItemFromCharacter(chr, "book59");  TakeItemFromCharacter(chr, "book60");

						LAi_QuestDelay("place_pym_big_sack", 0.5);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], false);
						LAi_SetFightMode(chr, true);
					}
				    }
				}
				else
				{
				    if(Locations[FindLocation(chr.location)].models.always.l2 == "sack2")
				    {
					if(!IsEquipCharacterByItem(chr, "bladeX4"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'
						
						PlaySound("PEOPLE\clothes1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr, "bladesemifullsack_P");
						EquipCharacterByItem(chr, "bladesemifullsack_P");

						if(CheckAttribute(chr, "quest.book55A") && chr.quest.book55A == "placed") {
							GiveItem2Character(chr, "book55A");
							chr.quest.book55A = "picked_up"; }
						if(CheckAttribute(chr, "quest.book55B") && chr.quest.book55B == "placed") {
							GiveItem2Character(chr, "book55B");
							chr.quest.book55B = "picked_up"; }
						if(CheckAttribute(chr, "quest.book55D") && chr.quest.book55D == "placed") {
							GiveItem2Character(chr, "book55D");
							chr.quest.book55D = "picked_up"; }
						if(CheckAttribute(chr, "quest.book56") && chr.quest.book56 == "placed") {
							GiveItem2Character(chr, "book56");
							chr.quest.book56 = "picked_up"; }
						if(CheckAttribute(chr, "quest.book57") && chr.quest.book57 == "placed") {
							GiveItem2Character(chr, "book57");
							chr.quest.book57 = "picked_up"; }
						if(CheckAttribute(chr, "quest.book58") && chr.quest.book58 == "placed") {
							GiveItem2Character(chr, "book58");
							chr.quest.book58 = "picked_up"; }
						if(CheckAttribute(chr, "quest.book59") && chr.quest.book59 == "placed") {
							GiveItem2Character(chr, "book59");
							chr.quest.book59 = "picked_up"; }
						if(CheckAttribute(chr, "quest.book60") && chr.quest.book60 == "placed") {
							GiveItem2Character(chr, "book60");
							chr.quest.book60 = "picked_up"; }

						LAi_QuestDelay("take_pym_sack", 0.5);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_study")], false);
						LAi_SetFightMode(chr, true);
					}
				    }
				}
				else
				{
				    if(CheckCharacterItem(chr,"bladeemptysack_P"))
				    {
					if(!IsEquipCharacterByItem(chr, "bladeemptysack_P"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeemptysack_P");
					}

					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","It's no idea - the sack is empty."));
				    }
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					Logit(TranslateString("","I don't know what to place here."));
				}
			break;

			case "box12":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box6");
			break;

			case "box13":
				if(CheckAttribute(chr, "quest.pym_ladder") && chr.quest.pym_ladder == "way_up")
				{
					if(CheckAttribute(chr, "quest.pym_big_sack") && chr.quest.pym_big_sack == "placed")
					{
						DoQuestReloadToLocation("Pym_towerroom", "goto", "goto1", "");
					}
					else
					{
						PlaySound("INTERFACE\knock.wav");
						chr.quest.pym_ladder = "way_down";
					}
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Pym_study", "box", "box9");
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Pym_towerroom")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.pym_hatch") && chr.quest.pym_hatch == "locked")
				{
					PlaySound("INTERFACE\knock.wav");
					Logit(TranslateString("","No, it's locked to the Study!"));
					chr.quest.tower_box1 = "checked";

					LAi_QuestDelay("tower_box8_check", 0.1);
				}
				else
				{
					chr.quest.pym_ladder = "way_down";
					DoQuestReloadToLocation("Pym_study", "box", "box13", "");
				}
			break;

			case "box2":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box3":
				if(CheckCharacterItem(chr,"bladeboom"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeboom"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeboom");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("PEOPLE\creak.wav");
						PlaySound("OBJECTS\DUEL\boom.wav");

						LAi_QuestDelay("close_pym_tower_hatch", 1.0);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","There's something hidden here but the hatch is stuck."));

					if(!CheckAttribute(chr,"quest.nav_itms6") || chr.quest.6 != "done")
					{
						AddQuestRecord("Navigation_items","6");
						chr.quest.nav_itms6 = "done";
					}
				}
			break;

			case "box4":
				//PlaySound("INTERFACE\carpet_move.wav");
				PlaySound("PEOPLE\clothes1.wav");
				
				LAi_QuestDelay("move_Pym_curtain1", 1.0);
			break;

			case "box5":
				//PlaySound("INTERFACE\carpet_move.wav");
				PlaySound("PEOPLE\clothes1.wav");
				
				LAi_QuestDelay("move_Pym_curtain2", 1.0);
			break;

			case "box6":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;

			case "box7":
				PlaySound("INTERFACE\locked_window.wav");
				Logit(TranslateString("","No, I have to try something else!"));
				chr.quest.tower_box7 = "checked";

				LAi_QuestDelay("tower_box8_check", 0.1);
			break;

			case "box8":
				if(CheckCharacterItem(chr,"bladeboom"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeboom"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeboom");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						if(CheckAttribute(chr,"quest.tower_box8") && chr.quest.tower_box8 == "on")
						{
							return;
						}
						else
						{
							chr.quest.tower_box8 = "on";
							PlaySound("PEOPLE\roof_creak.wav");
					
							LAi_QuestDelay("pym_tower_boom_brakes", 3.0);
						}
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], false);
						LAi_SetFightMode(chr, true);
					}
				}
			break;

			case "box9":
				if(CheckCharacterItem(chr,"bladepaperroll"))
				{
					if(!IsEquipCharacterByItem(chr, "bladepaperroll"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladepaperroll");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("INTERFACE\paper_small.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladepaperroll");
						EquipCharacterByItem(chr, "bladeX4");
					
						LAi_QuestDelay("place_bladepaperroll", 1.0);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{
					if(!IsEquipCharacterByItem(chr, "pistoltinderbox"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
						EquipCharacterByItem(chr, "pistoltinderbox");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						//fire tinderbox here
					
						//LAi_QuestDelay("light_paperroll", 1.0);
					}
					else
					{
						LAi_LocationFightDisable(&Locations[FindLocation("Pym_towerroom")], false);
						LAi_SetFightMode(chr, true);
					}

				}
			break;

			case "box10":
				chr.quest.tower_hidden = "yes";
				PlaySound("PEOPLE\step_stone1.wav");
				ChangeCharacterAddressGroup(chr, "Pym_towerroom", "goto", "hide");
			break;

			case "box11":
				chr.quest.tower_hidden = "no";
				PlaySound("PEOPLE\step_stone1.wav");
				ChangeCharacterAddressGroup(chr, "Pym_towerroom", "goto", "walk");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_tailorsShop")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckCharacterItem(chr,"key29"))
				{
					if(CheckAttribute(chr,"quest.tailor_box1") && chr.quest.tailor_box1 == "on")
					{
						return;
					}
					else
					{
						chr.quest.tailor_box1 = "on";
						PlaySound("INTERFACE\key_unlock.wav");

						LAi_QuestDelay("unlock_Charleston_tailor", 2.0);
					}
				}
				else
				{
					Logit(TranslateString("","Charleston."));
					PlaySound("INTERFACE\knock.wav");
				}
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_tailorsShop", "box", "box3");
			break;

			case "box3":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_tailorsShop", "box", "box2");
			break;

			case "box4":
				Logit(TranslateString("","Textiles."));
				PlaySound("INTERFACE\knock.wav");
			break;

			case "box5":
				PlaySound("AMBIENT\JAIL\door_003.wav");
				LaunchItemsBox(&ar);
			break;

			case "box6":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box7":
				CreateParticleSystemX("blast_dirt_gray", 2.2, 0.4, -1.4, 2.2, 0.4, -1.4,10);
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_tailorsShop", "box", "box8");
			break;

			case "box8":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("pchar_equip_anchor_check", 0.1);
				LAi_QuestDelay("tailor_sack_down", 1.0);
			break;

			case "box9":
				Logit(TranslateString("","Private."));
				PlaySound("INTERFACE\knock.wav");
			break;

			case "box10":
				PlaySound("INTERFACE\closet_open.wav");
				LaunchItemsBox(&ar);
			break;

			case "box11":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_church")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.key22") && chr.quest.key22 == "picked_up")
				{
					PlaySound("INTERFACE\collection_box.wav");
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"magnet2"))
					{
						PlaySound("INTERFACE\collection_box.wav");
						PlaySound("PEOPLE\pickaxe_box.wav");
						GiveItem2Character(chr, "key22");
						TakeItemFromCharacter(chr, "magnet2");
						chr.quest.key22 = "picked_up";

						SetLocatorRadius(locations[FindLocation(chr.location)], "reload", "reload3", 0.0001);
						SetLocatorRadius(locations[FindLocation(chr.location)], "reload", "reload4", 0.0001);
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box2", 0.5);
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box3", 0.5);

						Locations[FindLocation("GB_Charleston_church")].locators_radius.reload.reload3 = 0.0001;
						Locations[FindLocation("GB_Charleston_church")].locators_radius.reload.reload4 = 0.0001;
						Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box2 = 0.5;
						Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box3 = 0.5;

						LAi_QuestDelay("magnet_key", 2.0);
					}
					else
					{
						if(CheckCharacterItem(chr,"magnet"))
						{
							Logit(TranslateString("","The magnet makes something move inside."));
							PlaySound("INTERFACE\collection_box.wav");
							PlaySound("PEOPLE\key_box.wav");

							LAi_QuestDelay("Poe_promising", 1.0);
						}
					}
					else
					{
						Logit(TranslateString("","No, it's locked!"));
						PlaySound("INTERFACE\collection_box.wav");

						LAi_QuestDelay("Poe_ooh", 1.0);
					}
				}
			break;

			case "box2":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_Charleston_sacristy", 2.0);
			break;

			case "box3":
				PlaySound("INTERFACE\key_unlock.wav");

				LAi_QuestDelay("unlock_Charleston_sacristy", 2.0);
			break;

			case "box4":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_Charleston_church", "goto", "mummy_talk");

				if(CheckCharacterItem(chr,"key22"))
				{
					LAi_QuestDelay("Poe_ok", 1.0);
					LAi_QuestDelay("mummy_priest_gone", 2.0);
				}
				else
				{
					ChangeCharacterAddressGroup(characterFromID("GB_mummy3"), "GB_Charleston_church", "sit", "mummy");
				}
			break;

			case "box5":
				//CARPENTER'S CHEST

				if(CheckAttribute(chr, "church.box5") && chr.church.box5 == "open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);

					LAi_QuestDelay("pickup_tools_check", 0.1);
					LAi_QuestDelay("book_tools_check", 0.1);
				}
				else
				{
					if(CheckCharacterItem(chr,"needles2"))
					{
						PlaySound("PEOPLE\lockpick.wav");
						TakeItemFromCharacter(chr, "needles2");
						
						LAi_QuestDelay("unlock_church_box5", 3.0);
					}
					else
					{
						if(CheckCharacterItem(chr,"needles"))
						{
							PlaySound("PEOPLE\lockpick2.wav");

							LAi_QuestDelay("fail_unlock_church_box5", 2.0);
						}
					}
					else
					{
						Logit(TranslateString("","That lock looks very simple - maybe I can pick it open?"));
						PlaySound("INTERFACE\locked_window.wav");

						LAi_QuestDelay("Poe_simplicity", 1.0);
					}
				}
			break;

			case "box6":
				PlaySound("INTERFACE\paper.wav");
			break;

		//--------------------------------------------------------------			
		//altar boxes

			case "box7":
				PlaySound("INTERFACE\closet_Open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_church_box7", 0.1);
			break;

			case "box8":
				PlaySound("INTERFACE\closet_Open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_church_box8", 0.1);
			break;

			case "box9":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box9 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box9", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box10 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box10", 0.5);

				LAi_QuestDelay("return_church_box9", 0.1);
			break;

			case "box10":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box10 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box10", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box11 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box11", 0.5);

				LAi_QuestDelay("return_church_box10", 0.1);
			break;

			case "box11":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box11 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box11", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box9 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box9", 0.5);
			break;


			case "box12":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box12 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box12", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box12 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box13", 0.5);

				LAi_QuestDelay("pickup_hymnbook_check", 0.1);
				LAi_QuestDelay("book_tools_check", 0.1);
			break;

			case "box13":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box13 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box13", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box14 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box14", 0.5);

				LAi_QuestDelay("return_church_box13", 0.1);
			break;

			case "box14":
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box14 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box14", 0.0001);
				Locations[FindLocation("GB_Charleston_church")].locators_radius.box.box12 = 0.5;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box12", 0.5);

				LAi_QuestDelay("return_church_box14", 0.1);
			break;

			case "box15":
				PlaySound("INTERFACE\closet_Open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_church_box15", 0.1);
			break;

			case "box16":
				PlaySound("INTERFACE\closet_Open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("return_church_box16", 0.1);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Charleston_church_office")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "sacristy.box1") && chr.sacristy.box1 == "open")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
				}
				else PlaySound("INTERFACE\locked_window.wav");
			break;
		
			case "box2":
				PlaySound("INTERFACE\locked_window.wav");
			break;	

			case "box3":
				PlaySound("INTERFACE\small_door_locked.wav");
			break;

			case "box4":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
			break;

			case "box5":
				PlaySound("INTERFACE\knock.wav");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_Chinatown")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr, "quest.China_well") && chr.quest.China_well == "phase1")
				{
					if(CheckCharacterItem(chr,"pistolbucket_empty"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeX4"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}
					
						if(!IsEquipCharacterByItem(chr, "pistolbucket_empty"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolbucket_empty");
						}
					
						LAi_LocationFightDisable(&Locations[FindLocation("GB_Chinatown")], false);
						LAi_SetFightMode(chr, true);
					}
				}
				else
				{
				    if(CheckAttribute(chr, "quest.China_well") && chr.quest.China_well == "phase2")
				    {
					if(!IsEquipCharacterByItem(chr, "bladeX4"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}
					
					if(!IsEquipCharacterByItem(chr, "pistolhand2"))
					{
						RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
						EquipCharacterByItem(chr, "pistolhand2");
					}

					LAi_LocationFightDisable(&Locations[FindLocation("GB_Chinatown")], false);
					LAi_SetFightMode(chr, true);
				    }
				}
				else return;
			break;

			case "box2":
				PlaySound("PEOPLE\run_stone.wav");

				if(CheckAttribute(chr, "quest.nitre_door") && chr.quest.nitre_door == "open")
				{	
					ChangeCharacterAddressGroup(chr, "GB_Chinatown", "reload", "reload7");
				}
				else ChangeCharacterAddressGroup(chr, "GB_Chinatown", "goto", "box5");
			break;

			case "box3":
				PlaySound("PEOPLE\run_stone.wav");

				if(CheckAttribute(chr, "quest.charcoal_door") && chr.quest.charcoal_door == "open")
				{
					ChangeCharacterAddressGroup(chr, "GB_Chinatown", "reload", "reload10");
				}
				else ChangeCharacterAddressGroup(chr, "GB_Chinatown", "goto", "box6");
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.gp_mill_door") && chr.quest.gp_mill_door == "info")
				{
					PlaySound("INTERFACE\lever_stuck.wav");

					LAi_QuestDelay("gp_mill_door", 1.0);
				}
				else
				{
					PlaySound("INTERFACE\lever_stuck.wav");

					LAi_QuestDelay("pchar_huh", 1.0);
				}
			break;

			case "box5":
				PlaySound("INTERFACE\knock.wav");

				LAi_QuestDelay("chinatown_box5", 1.5);
			break;

			case "box6":
				PlaySound("INTERFACE\knock.wav");

				LAi_QuestDelay("chinatown_box6", 1.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_restaurant")
	{
		switch(chr.boxname)
		{
			case "box1":
				if(CheckAttribute(chr,"quest.chinarest_chest1") && chr.quest.chinarest_chest1 == "open")
				{
					//once opened stays open
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key24"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.chinarest_chest1 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_room")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "GB_chinese_room", "goto", "goto2");

				LAi_QuestDelay("in_fireworks_lab", 1.0);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_gunpowder")
	{
		switch(chr.boxname)
		{
			case "box10":
				//ladder top: fill barrel
				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for placing, filling or picking up bottles

					if(makefloat(chr.quest.BB_total) == 8.0)
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","The barrel is already filled. Now it's time to grind it."));

						LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
						return;
					}
					else
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BC2");
								GiveItem2Character(chr,"bladebottle_BC1");
								EquipCharacterByItem(chr, "bladebottle_BC1");
							}
							else
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 2;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BC2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");								
							}

							chr.quest.charcoal_risk = 33;
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BC1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							chr.quest.charcoal_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							chr.quest.charcoal_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}
			
					//----------------------------------------------------------------------------------------
					
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BG2");
								GiveItem2Character(chr,"bladebottle_BG1");
								EquipCharacterByItem(chr, "bladebottle_BG1");
							}
							else
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 1;
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BG2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BG1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AG2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}						

					//----------------------------------------------------------------------------------------

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BN2");
								GiveItem2Character(chr,"bladebottle_BN1");
								EquipCharacterByItem(chr, "bladebottle_BN1");
							}
							else
							{
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 2;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BN2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BN1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

					//----------------------------------------------------------------------------------------
						
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BS2");
								GiveItem2Character(chr,"bladebottle_BS1");
								EquipCharacterByItem(chr, "bladebottle_BS1");
							}
							else
							{
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 2;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BS2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
							
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BS1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 1;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

					//----------------------------------------------------------------------------------------

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BY2");
								GiveItem2Character(chr,"bladebottle_BY1");
								EquipCharacterByItem(chr, "bladebottle_BY1");
							}
							else
							{
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 1;
								chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BY2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BY1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
							chr.quest.store_nitre = makefloat(chr.quest.store_nitre) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AY2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

					//----------------------------------------------------------------------------------------

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(chr.quest.BB_total) == 7.0)
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BZ2");
								GiveItem2Character(chr,"bladebottle_BZ1");
								EquipCharacterByItem(chr, "bladebottle_BZ1");
							}
							else
							{
								chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 1;
								chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 1;
								chr.quest.store_total = makefloat(chr.quest.store_total) + 2;
								chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladebottle_BZ2");
								GiveItem2Character(chr,"bladebottle_BE0");
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
							
							chr.quest.charcoal_risk = 33;
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BZ1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
							
							chr.quest.charcoal_risk = 33;
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.store_charcoal = makefloat(chr.quest.store_charcoal) + 0.5;
							chr.quest.store_sulfur = makefloat(chr.quest.store_sulfur) + 0.5;
							chr.quest.store_total = makefloat(chr.quest.store_total) + 1;
							chr.quest.BB_total = makefloat(chr.quest.store_total) + makefloat(chr.quest.mix_total);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AZ2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
							
							chr.quest.charcoal_risk = 33;
							chr.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 0.5);
							return;
						}			
					}
				}
				else
				{
					if(CheckAttribute(chr, "equip.blade"))
					{
						if(chr.equip.blade == "bladebottle_AC2" || chr.equip.blade == "bladebottle_AG2" || chr.equip.blade == "bladebottle_AN2"
						|| chr.equip.blade == "bladebottle_AS2" || chr.equip.blade == "bladebottle_AY2" || chr.equip.blade == "bladebottle_BC2" 
						|| chr.equip.blade == "bladebottle_BG2" || chr.equip.blade == "bladebottle_BN2" || chr.equip.blade == "bladebottle_BS2" 
						|| chr.equip.blade == "bladebottle_BY2" || chr.equip.blade == "bladebottle_BC1" || chr.equip.blade == "bladebottle_BG1" 
						|| chr.equip.blade == "bladebottle_BN1" || chr.equip.blade == "bladebottle_BS1" || chr.equip.blade == "bladebottle_BY1"
						|| chr.equip.blade == "bladebottle_BZ2" || chr.equip.blade == "bladebottle_BZ1" || chr.equip.blade == "bladebottle_AZ2")
						{
							chr.quest.gp_container = makefloat(chr.quest.gp_container) + 1;	
						}
					}
					
					if(CheckAttribute(chr, "equip.gun"))
					{
						if(chr.equip.gun == "pistolcharcoal_F" || chr.equip.gun == "pistolcharcoal_H"
						|| chr.equip.gun == "pistolnitre_big_F" || chr.equip.gun == "pistolnitre_H"
						|| chr.equip.gun == "pistolsulphur_H" || chr.equip.gun == "pistolsulphur_F")
						{
							chr.quest.gp_container = makefloat(chr.quest.gp_container) + 1;
						}
					}
					
//				LogIt("gp_container = " + chr.quest.gp_container);	

					if(CheckAttribute(chr, "quest.gp_container") && chr.quest.gp_container == "0")
					{
						LAi_QuestDelay("stay_at_ladder_top1", 0.01);
						return;	//stops from reading more here
					}
					else
					{
						chr.quest.mill_position = "ladder_top";
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);
			/*
				LogIt("store_charcoal = " + makefloat(chr.quest.store_charcoal));
				LogIt("store_nitre = " + makefloat(chr.quest.store_nitre));
				LogIt("store_sulfur = " + makefloat(chr.quest.store_sulfur));
				LogIt("store_total = " + makefloat(chr.quest.store_total));
				LogIt("BB_total = " + makefloat(chr.quest.BB_total));
			*/
						LAi_QuestDelay("stay_at_ladder_top", 1.0);
						return;
					}
				}
			break;

			case "box12":
				//medium bottle
				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for placing, filling or picking up bottles

					//NO BOTTLE
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "none")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_CE0")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_CE0");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_ME0";
							chr.quest.medium_bottle = "ME0";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MC2";
							chr.quest.medium_bottle = "MC2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AG2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MG2";
							chr.quest.medium_bottle = "MG2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							//LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MN2";
							chr.quest.medium_bottle = "MN2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MS2";
							chr.quest.medium_bottle = "MS2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AY2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MY2";
							chr.quest.medium_bottle = "MY2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AZ2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MZ2";
							chr.quest.medium_bottle = "MZ2";

							LAi_QuestDelay("place_medium_bottle", 0.5);
							return;
						}
						//other bottles ev. in here giving Hmm that's not a good idea or so...
					}

					//EMPTY BOTTLE
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "ME0")
					{
					//-----------------------------------------------------------------------------------------
						//LARGE HALF FULL BOTTLES
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MC2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MC2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BC1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MG2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MG2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BG1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MN2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MN2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BN1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MS2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MS2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BS1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MY2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MY2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BY1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ1")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MZ2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MZ2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BZ1");
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}
					//-----------------------------------------------------------------------------------------
						//LARGE FULL BOTTLES
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MC2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MC2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BC2");
							GiveItem2Character(chr,"bladebottle_BC1");
							EquipCharacterByItem(chr, "bladebottle_BC1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MG2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MG2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BG2");
							GiveItem2Character(chr,"bladebottle_BG1");
							EquipCharacterByItem(chr, "bladebottle_BG1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MN2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MN2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BN2");
							GiveItem2Character(chr,"bladebottle_BN1");
							EquipCharacterByItem(chr, "bladebottle_BN1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MS2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MS2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BS2");
							GiveItem2Character(chr,"bladebottle_BS1");
							EquipCharacterByItem(chr, "bladebottle_BS1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MY2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MY2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BY2");
							GiveItem2Character(chr,"bladebottle_BY1");
							EquipCharacterByItem(chr, "bladebottle_BY1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ2")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.medium_bottle = "MZ2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MZ2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BZ2");
							GiveItem2Character(chr,"bladebottle_BZ1");
							EquipCharacterByItem(chr, "bladebottle_BZ1");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}


					//HALF FULL BOTTLE: can't happen

				
					//FULL BOTTLE: black
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MC2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AC2");
						EquipCharacterByItem(chr, "bladebottle_AC2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: grey
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MG2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AG2");
						EquipCharacterByItem(chr, "bladebottle_AG2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}
				
					//FULL BOTTLE: white
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MN2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AN2");
						EquipCharacterByItem(chr, "bladebottle_AN2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: yellow
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MS2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AS2");
						EquipCharacterByItem(chr, "bladebottle_AS2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: light yellow
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MY2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AY2");
						EquipCharacterByItem(chr, "bladebottle_AY2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}	

					//FULL BOTTLE: dark green
					if(CheckAttribute(chr, "quest.medium_bottle") && chr.quest.medium_bottle == "MZ2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.medium_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_AZ2");
						EquipCharacterByItem(chr, "bladebottle_AZ2");

						LAi_QuestDelay("place_medium_bottle", 0.5);
						return;
					}	
				}
				else
				{
//			LogIt("medium_bottle = " + chr.quest.medium_bottle);
						if(CheckAttribute(chr, "quest.medium_bottle"))
						{
							if(chr.quest.medium_bottle == "MC2" || chr.quest.medium_bottle == "MG2" || chr.quest.medium_bottle == "MN2"
							|| chr.quest.medium_bottle == "MS2" || chr.quest.medium_bottle == "MY2" || chr.quest.medium_bottle == "MZ2")
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeX4");
							}

							if(CheckCharacterItem(chr,"bladebottle_CE0"))
							{
								if(!IsEquipCharacterByItem(chr, "bladebottle_CE0"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladebottle_CE0");
								}
							}
						}
					
						chr.quest.mill_position = "medium_bottle";
						ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "stuck12");
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("stay_at_medium_bottle", 1.0);
						return;
				}
			break;

			case "box13":
				//large bottle
				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for placing, filling or picking up bottles

				//------------------------------------------------------------------------------------------------------------------
					//NO BOTTLE
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "none")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BE0")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BE0");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LE0";
							chr.quest.large_bottle = "LE0";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BC1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC1";
							chr.quest.large_bottle = "LC1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BC2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BC2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC2";
							chr.quest.large_bottle = "LC2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BG1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG1";
							chr.quest.large_bottle = "LG1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							//LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BG2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BG2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";
							chr.quest.large_bottle = "LG2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							//LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BN1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN1";
							chr.quest.large_bottle = "LN1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							//LAi_QuestDelay("alchemy_acid_fog", 1.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BN2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BN2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN2";
							chr.quest.large_bottle = "LN2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BS1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS1";
							chr.quest.large_bottle = "LS1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BS2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BS2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS2";
							chr.quest.large_bottle = "LS2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BY1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY1";
							chr.quest.large_bottle = "LY1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BY2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BY2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";
							chr.quest.large_bottle = "LY2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ1")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BZ1");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ1";
							chr.quest.large_bottle = "LZ1";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_BZ2")
						{
							PlaySound("INTERFACE\glass1.wav");
							PlaySound("PEOPLE\step_stairway2.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_BZ2");
							EquipCharacterByItem(chr, "bladeX4");
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";
							chr.quest.large_bottle = "LZ2";

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}
						//other bottles ev. in here giving Hmm that's not a good idea or so...
					}
			//------------------------------------------------------------------------------------------------------------------
					//EMPTY BOTTLE
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LE0")
					{
					//-----------------------------------------------------------------------------------------
						//MEDIUM BOTTLES
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LC1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LG1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AG2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
		
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LN1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LS1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LY1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AY2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							//HALF FULL BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LZ1";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ1";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AZ2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
											
						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: black
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LC1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BC1");
							EquipCharacterByItem(chr, "bladebottle_BC1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LC2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LG2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							//problem?
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LZ2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: grey
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LG1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BG1");
							EquipCharacterByItem(chr, "bladebottle_BG1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}						

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LG2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AG2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: white
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LN1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BN1");
							EquipCharacterByItem(chr, "bladebottle_BN1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LG2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
				
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LN2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LY2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: yellow
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LS1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BS1");
							EquipCharacterByItem(chr, "bladebottle_BS1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							//problem
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LZ2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AC2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LY2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AN2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LS2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AS2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: light yellow
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LY1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BY1");
							EquipCharacterByItem(chr, "bladebottle_BY1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}
						
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}						

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LY2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AY2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
				//------------------------------------------------------------------------------------------------------------------
					//HALF FULL BOTTLE: dark green
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LZ1")
					{
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladeX4")
						{
							//PICK UP BOTTLE

							PlaySound("INTERFACE\button2.wav");
							chr.quest.large_bottle = "none";

							Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr,"bladebottle_BZ1");
							EquipCharacterByItem(chr, "bladebottle_BZ1");

							LAi_QuestDelay("place_large_bottle", 0.5);
							return;
						}
						
						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AC2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}						

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AG2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AN2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AS2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AY2")
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","No, I'm not sure that's the right mix."));

							LAi_QuestDelay("place_large_bottle1", 0.5);
						}

						if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebottle_AZ2")
						{
							//FILL UP BOTTLE
							PlaySound("PEOPLE\grass_noise.wav");
							chr.quest.large_bottle = "LZ2";

							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladebottle_AZ2");
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						//GUN ITEMS see LAi_CharacterFireExecute_BUG() below
					}
					
				//------------------------------------------------------------------------------------------------------------------
					//FULL BOTTLE: black
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LC2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BC2");
						EquipCharacterByItem(chr, "bladebottle_BC2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: grey
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LG2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BG2");
						EquipCharacterByItem(chr, "bladebottle_BG2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}
				
					//FULL BOTTLE: white
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LN2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BN2");
						EquipCharacterByItem(chr, "bladebottle_BN2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: yellow
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LS2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BS2");
						EquipCharacterByItem(chr, "bladebottle_BS2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: light yellow
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LY2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BY2");
						EquipCharacterByItem(chr, "bladebottle_BY2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}

					//FULL BOTTLE: dark green
					if(CheckAttribute(chr, "quest.large_bottle") && chr.quest.large_bottle == "LZ2")
					{
						PlaySound("INTERFACE\button2.wav");
						chr.quest.large_bottle = "none";

						Locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "";
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr,"bladebottle_BZ2");
						EquipCharacterByItem(chr, "bladebottle_BZ2");

						LAi_QuestDelay("place_large_bottle", 0.5);
						return;
					}
				//------------------------------------------------------------------------------------------------------------------
				}
				else
				{
//		LogIt("large_bottle = " + chr.quest.large_bottle);
						if(CheckAttribute(chr, "quest.large_bottle"))
						{
							if(chr.quest.large_bottle == "LC2" || chr.quest.large_bottle == "LG2" || chr.quest.large_bottle == "LN2"
							|| chr.quest.large_bottle == "LS2" || chr.quest.large_bottle == "LY2" || chr.quest.large_bottle == "LZ2")
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeX4");
							}
						}

						if(CheckCharacterItem(chr,"bladebottle_BE0"))
						{
							if(!IsEquipCharacterByItem(chr, "bladebottle_BE0"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladebottle_BE0");
							}
						}

						chr.quest.mill_position = "large_bottle";
						ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "stuck13");
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("stay_at_large_bottle", 1.0);
						return;
				}
			break;

			case "box2":
				//rope			

				if(CheckAttribute(chr, "quest.running_gp") && chr.quest.running_gp == "on") return;	

				if(makefloat(chr.quest.BB_total) == 0.0)
				{
					//big barrel is empty
		
					LAi_SetSitType(chr);
					PlaySound("INTERFACE\damper_change.wav");

					LAi_QuestDelay("no_running_gunpowder", 0.5);
					return;
				}
				else
				{
					if(makefloat(chr.quest.store_total) == 0.0)
					{
						//all is grinded						
			
						if(Locations[FindLocation(chr.location)].models.always.locators == "sklad_l_GB_barrel")
						{
							//barrel on floor
		
							if(makefloat(chr.quest.gp_total) == 4.0)
							{
								//floor barrel is full
		
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","I have already filled that Barrel, it's just to pick it up."));
								return;
							}
							else
							{
								//there is still some empty space in the floor barrel
		
								chr.quest.running_gp = "on";
								LAi_SetSitType(chr);
								PlaySound("INTERFACE\damper_change.wav");

								LAi_QuestDelay("running_gunpowder_barrel", 0.5);
								return;
							}
						}

						if(Locations[FindLocation(chr.location)].models.always.locators == "sklad_l_GB_empty")
						{
							//no barrel on floor
							
						//	if(CheckAttribute(chr, "quest.rope_first_time") && chr.quest.rope_first_time == "yes")
							if(makefloat(chr.quest.BB_TOTAL) < 8.0 )
							{
								PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
								Logit(TranslateString("","There's no Barrel on the floor."));
								return;
							}
							else
							{
								chr.quest.running_gp = "on";
								LAi_SetSitType(chr);
								PlaySound("INTERFACE\damper_change.wav");

								LAi_QuestDelay("running_gunpowder_floor", 0.5);
								return;
							}
						}
					}
					else
					{
						//not all is grinded
		
						PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
						Logit(TranslateString("","I have to grind all first."));
						return;
					}
				}
			break;

			case "box8":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "box10");
			break;

			case "box11":
				if(makefloat(chr.quest.BB_total) == 0.0)
				{
					//big barrel is empty

					PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					Logit(TranslateString("","There's nothing to grind yet."));
					return;
				}
				else
				{
					if(makefloat(chr.quest.store_total) == 0.0)
					{
						//all is grinded

						PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
						Logit(TranslateString("","I have already done that."));
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.rumble_gp") && chr.quest.rumble_gp == "on") return;

					chr.quest.rumble_gp = "on";
					PlaySound("INTERFACE\rumble2.wav");
								
					LAi_QuestDelay("rumble_mixing_gunpowder", 0.01);
				}
			break;

			case "box9":
				//cupboard

				if(CheckAttribute(chr,"quest.gp_mill_chest9") && chr.quest.gp_mill_chest9 == "open")
				{
					//once opened stays open
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key27"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_mill_chest9 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box14":
				//drawer

				if(CheckAttribute(chr,"quest.gp_mill_chest14") && chr.quest.gp_mill_chest14 == "open")
				{
					//once opened stays open
					PlaySound("INTERFACE\chart_move.wav");
					PlaySound("INTERFACE\chart_move.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key27"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_mill_chest14 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box15":
				//drawer

				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);
				return;
			break;

			case "box1":
				//step on chest to water wheel

				PlaySound("PEOPLE\step_stairway2.wav");
				ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "box18");
			break;

			case "box18":
				//water wheel

				if(CheckAttribute(chr, "quest.water_tap_gp") && chr.quest.water_tap_gp == "on") return;

				chr.quest.water_tap_gp = "on";

				if(CheckAttribute(chr, "quest.water_added") && chr.quest.water_added == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","Water is already added."));

					LAi_QuestDelay("gp_mill_water_wheel2", 1.0);
				}
				else
				{
					chr.quest.water_added = "yes";
					chr.quest.water_risk = 0;
					PlaySound("INTERFACE\water_tap.wav");

					LAi_QuestDelay("gp_mill_water_wheel", 0.5);
				}
			break;

			case "box3":
				//big gunpowder barrel for bad GP
				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for throwing bad gp mixtures away
					if(CheckAttribute(chr, "equip.blade") && chr.equip.blade == "bladebarrel_gpW")
					{
						PlaySound("PEOPLE\grass_noise.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladebarrel_gpW");
						GiveItem2Character(chr,"bladebarrel_gp0");
						EquipCharacterByItem(chr, "bladebarrel_gp0");

						LAi_QuestDelay("empty_gp_barrel", 0.5);
						LAi_QuestDelay("Jup_with_ingredients", 2.0);
					}
					else
					{
						//equip.blade is one of the 18 possible bottles
						if(CheckAttribute(chr, "equip.blade"))
						{
							string bottleID = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);	// defines weaponname
							aref bottle;
							Items_FindItem(bottleID, &bottle);
						}

						if(IsEquipCharacterByItem(chr, "bladebottle_AC2") || IsEquipCharacterByItem(chr, "bladebottle_BC1")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 1;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BC2")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 2;}

						if(IsEquipCharacterByItem(chr, "bladebottle_AS2") || IsEquipCharacterByItem(chr, "bladebottle_BS1")) 
						{chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 1;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BS2")) 
						{chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 2;}
						
						if(IsEquipCharacterByItem(chr, "bladebottle_AN2") || IsEquipCharacterByItem(chr, "bladebottle_BN1")) 
						{chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 1;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BN2")) 
						{chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 2;}

						if(IsEquipCharacterByItem(chr, "bladebottle_AG2") || IsEquipCharacterByItem(chr, "bladebottle_BG1")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 0.5;
						 chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 0.5;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BG2")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 1;
						 chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 1;}

						if(IsEquipCharacterByItem(chr, "bladebottle_AY2") || IsEquipCharacterByItem(chr, "bladebottle_BY1")) 
						{chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 0.5;
						 chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 0.5;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BY2")) 
						{chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 1;
						 chr.quest.lost_nitre = makefloat(chr.quest.lost_nitre) + 1;}

						if(IsEquipCharacterByItem(chr, "bladebottle_AZ2") || IsEquipCharacterByItem(chr, "bladebottle_BZ1")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 0.5;
						 chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 0.5;}
						if(IsEquipCharacterByItem(chr, "bladebottle_BZ2")) 
						{chr.quest.lost_charcoal = makefloat(chr.quest.lost_charcoal) + 1;
						 chr.quest.lost_sulfur = makefloat(chr.quest.lost_sulfur) + 1;}

					LogIt("lost_charcoal = " + makefloat(chr.quest.lost_charcoal));
					LogIt("lost_nitre = " + makefloat(chr.quest.lost_nitre));
					LogIt("lost_sulfur = " + makefloat(chr.quest.lost_sulfur));

						PlaySound("PEOPLE\grass_noise.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, bottleID);

						if(CheckAttribute(chr, "quest.bad_bottle") && chr.quest.bad_bottle == "medium")
						{
							GiveItem2Character(chr,"bladebottle_CE0");
							EquipCharacterByItem(chr, "bladebottle_CE0");
						}

						if(CheckAttribute(chr, "quest.bad_bottle") && chr.quest.bad_bottle == "large")
						{
							GiveItem2Character(chr,"bladebottle_BE0");
							EquipCharacterByItem(chr, "bladebottle_BE0");
						}

						LAi_QuestDelay("empty_gp_barrel", 0.5);
						LAi_QuestDelay("Jup_with_ingredients", 2.0);
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladebarrel_gpW") || CheckCharacterItem(chr,"pistolbarrel_gpW"))
					{
						if(CheckCharacterItem(chr,"pistolbarrel_gpW"))
						{
							if(!IsEquipCharacterByItem(chr, "pistolbarrel_gpW"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeX4");

								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistolbarrel_gpW");
							}
						}
		
						if(CheckCharacterItem(chr,"bladebarrel_gpW"))
						{
							if(!IsEquipCharacterByItem(chr, "bladebarrel_gpW"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladebarrel_gpW");
							}
						}

						chr.quest.mill_position = "bin";
						ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "stuck3");
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("stay_at_bin", 1.0);
						return;
					}
					else
					{
						//MEDIUM BOTTLE

						if(IsEquipCharacterByItem(chr, "bladebottle_AC2") || IsEquipCharacterByItem(chr, "bladebottle_AG2") || IsEquipCharacterByItem(chr, "bladebottle_AN2")
						|| IsEquipCharacterByItem(chr, "bladebottle_AS2") || IsEquipCharacterByItem(chr, "bladebottle_AY2") || IsEquipCharacterByItem(chr, "bladebottle_AZ2"))
						{
							chr.quest.bad_bottle = "medium";
							chr.quest.mill_position = "bin";
							ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "stuck3");
							LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("stay_at_bin", 1.0);
							return;
						}
					}
					else
					{
						//LARGE BOTTLE

						if(IsEquipCharacterByItem(chr, "bladebottle_BC2") || IsEquipCharacterByItem(chr, "bladebottle_BG2") || IsEquipCharacterByItem(chr, "bladebottle_BN2")
						|| IsEquipCharacterByItem(chr, "bladebottle_BS2") || IsEquipCharacterByItem(chr, "bladebottle_BY2") || IsEquipCharacterByItem(chr, "bladebottle_BZ2")			
						|| IsEquipCharacterByItem(chr, "bladebottle_BC1") || IsEquipCharacterByItem(chr, "bladebottle_BG1") || IsEquipCharacterByItem(chr, "bladebottle_BN1")
						|| IsEquipCharacterByItem(chr, "bladebottle_BS1") || IsEquipCharacterByItem(chr, "bladebottle_BY1") || IsEquipCharacterByItem(chr, "bladebottle_BZ1"))
						{
							chr.quest.bad_bottle = "large";
							chr.quest.mill_position = "bin";
							ChangeCharacterAddressGroup(chr, "GB_chinese_gunpowder", "goto", "stuck3");
							LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("stay_at_bin", 1.0);
							return;
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","I can get rid of bad Mixtures here."));
					}
				}
			break;

			case "box4":
				//locked, ev opened later
				PlaySound("INTERFACE\locked_window.wav");
			/*
			LogIt("lost_charcoal = " + makefloat(chr.quest.lost_charcoal));
			LogIt("lost_nitre = " + makefloat(chr.quest.lost_nitre));
			LogIt("lost_sulfur = " + makefloat(chr.quest.lost_sulfur));
			*/
				return;
			break;

			case "box5":
				//sulfur basket

				if(CheckAttribute(chr,"quest.gp_mill_chest5") && chr.quest.gp_mill_chest5 == "open")
				{
					//once opened stays open
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key27"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_mill_chest5 = "open";
						
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
				//nitre sacks

				if(CheckAttribute(chr,"quest.gp_mill_chest6") && chr.quest.gp_mill_chest6 == "open")
				{
					//once opened stays open
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key27"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_mill_chest6 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box7":
				//charcoal jar

				if(CheckAttribute(chr,"quest.gp_mill_chest7") && chr.quest.gp_mill_chest7 == "open")
				{
					//once opened stays open
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key27"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_mill_chest7 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box16":
				//No gunpowder barrel on floor

				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for placing gunpowder barrel
					if(CheckCharacterItem(chr,"bladebarrel_gp0"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladebarrel_gp0" );
						EquipCharacterByItem(chr, "bladeX4");
						PlaySound("OBJECTS\DUEL\club2.wav");
						PlaySound("PEOPLE\step_echo.wav");

						chr.quest.floor_barrel = "blade_type";

						LAi_QuestDelay("place_empty_barrel_on_floor1", 1.0);
						return;
					}
					
					//pistolbarrel_gp0 at the end of this file
				}
				else
				{
					if(CheckCharacterItem(chr,"bladebarrel_gp0"))
					{
						if(!IsEquipCharacterByItem(chr, "bladebarrel_gp0"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladebarrel_gp0");
						}
					}
					
					if(CheckCharacterItem(chr,"pistolbarrel_gp0"))
					{
						if(!IsEquipCharacterByItem(chr, "pistolbarrel_gp0"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolbarrel_gp0");
						}	
					}

					if(CheckCharacterItem(chr,"bladebarrel_gp0") || CheckCharacterItem(chr,"pistolbarrel_gp0"))
					{
						chr.quest.mill_position = "floor";
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);
					}
					else PlaySound("VOICE\ENGLISH\blaze_huh.wav");

					return;
				}
			break;

			case "box17":
				//gunpowder barrel on floor

				if(LAi_IsFightMode(chr))
				{
				//this is your 2:nd 'open box', used for picking up gunpowder barrel
		
				    if(CheckAttribute(chr, "quest.floor_barrel") && chr.quest.floor_barrel == "blade_type")
				    {
					chr.quest.gp_charcoal = 0;
					chr.quest.gp_nitre = 0;
					chr.quest.gp_sulfur = 0;
					chr.quest.gp_total = 0;

					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);

					if(CheckAttribute(chr, "quest.gp_quality") )
					{
						if(chr.quest.gp_quality == "standard")
						{
							GiveItem2Character(chr,"bladebarrel_gpS");
							EquipCharacterByItem(chr, "bladebarrel_gpS");
						}

						if(chr.quest.gp_quality == "fireworks")
						{
							GiveItem2Character(chr,"bladebarrel_gpF");
							EquipCharacterByItem(chr, "bladebarrel_gpF");
						}

						if(chr.quest.gp_quality == "wrong")
						{
							GiveItem2Character(chr,"bladebarrel_gpW");
							EquipCharacterByItem(chr, "bladebarrel_gpW");
						}
					}
		
					LAi_QuestDelay("pick_up_barrel_from_floor1", 1.0);
					return;
				    }
				}
				else
				{
					if(makefloat(chr.quest.gp_total) == 4.0)
					{
						if(CheckAttribute(chr, "quest.floor_barrel") && chr.quest.floor_barrel == "blade_type")
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}

						if(CheckAttribute(chr, "quest.floor_barrel") && chr.quest.floor_barrel == "gun_type")
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolhand2");
						}

						chr.quest.mill_position = "floor";
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_gunpowder")], false);
						LAi_SetFightMode(chr, true);

						return;
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","The Barrel isn't filled yet."));
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_nitre")
	{
		switch(chr.boxname)
		{
			case "box1":
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
					if(CheckAttribute(chr, "quest.nitre_wood") && chr.quest.nitre_wood == "placed")
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","I have already got some wood."));
					}
					else
					{
						PlaySound("PEOPLE\wood1.wav");
						TakeNItems(chr, "bladewood2", 1);
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladewood2");
					}
				}
			break;
		
			case "box2":				
				if(CheckAttribute(chr, "quest.nitre_fireplace") && chr.quest.nitre_fireplace == "on") return;

				LAi_SetStayType(chr);
				PlaySound("INTERFACE\metal_hatch_open.wav");
				chr.quest.nitre_fireplace = "on";
				
				LAi_QuestDelay("nitre_fireplace", 1.5);
			break;

			case "box3":
			    if(locations[FindLocation("GB_chinese_nitre")].models.always.l5 == "roll_of_planks4")	
			    {
				if(CheckCharacterItem(chr,"bladepickaxe1"))
				{				
					if(!IsEquipCharacterByItem(chr, "bladepickaxe1"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladepickaxe1");
					}

					if(CheckCharacterItem(chr,"pistolnitre_H"))
					{
						Locations[FindLocation("GB_chinese_nitre")].locators_radius.box.box3 = 0.0001;
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box3", 0.0001);

						if(!IsEquipCharacterByItem(chr, "pistolnitre_H"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolnitre_H");
						}

						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("nitre_scrape_salpeter_again", 1.0);
					}
					else
					{
						if(CheckCharacterItem(chr,"pistolnitre_E"))
						{
							if(!IsEquipCharacterByItem(chr, "pistolnitre_E"))
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistolnitre_E");
							}

							LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], false);
							LAi_SetFightMode(chr, true);

							LAi_QuestDelay("nitre_scrape_salpeter", 1.0);
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_puh.wav");
							Logit(TranslateString("","I need a Sack to collect the Salpeter."));
						}
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolnitre_E"))
					{
						if(!IsEquipCharacterByItem(chr, "pistolnitre_E"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolnitre_E");
						}

						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
						Logit(TranslateString("","I need a Tool to scrape the Salpeter from the planks."));

						if(!CheckAttribute(chr,"quest.salpeter6") || chr.quest.salpeter6 != "done")
						{
							AddQuestRecord("Salpeter","6");
							chr.quest.salpeter6 = "done";
						}

						chr.quest.guest_nitre = "time";
						LAi_QuestDelay("china_guests_out", 1.0);
					}
				}
				else 
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","I need a Tool to scrape the Salpeter from the planks."));
					Logit(TranslateString("","I need a Sack to collect the Salpeter."));
				}
			    }
			    else
			    {
				if(locations[FindLocation("GB_chinese_nitre")].models.always.l5 == "roll_of_planks5")	
			    	{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","The Salpeter is not dry yet."));
				}
			    }	
			break;
			
			case "box4":
				if(CheckAttribute(chr, "quest.nitre_lever1") && chr.quest.nitre_lever1 == "down")
				{
					//lever is down				
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l2 = "lever1_up";
					chr.quest.nitre_lever1 = "up";

					LAi_QuestDelay("nitre_lever1_up", 0.5);
				}
				else
				{

					//lever is up				
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l2 = "lever1_down";
					chr.quest.nitre_lever1 = "down";

					LAi_QuestDelay("nitre_lever1_down", 0.5);
				}
			break;
			
			case "box5":
				chr.quest.nitre_position = "tub";

				if(CheckAttribute(chr,"quest.tub3_content") && chr.quest.tub3_content == "nitre")	
				{
					if(CheckCharacterItem(chr,"pistolbucket_empty"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeX4"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}

						if(!IsEquipCharacterByItem(chr, "pistolbucket_empty"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolbucket_empty");
						}
						
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], false);
						LAi_SetFightMode(chr, true);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
						Logit(TranslateString("","I need an Empty Bucket to get the Salpeter from the Tub."));
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.tub3_content") && chr.quest.tub3_content == "dirt")	
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","There is some Salpeter in the water but not enough."));
					}
				}
				else
				{
					if(CheckAttribute(chr,"quest.tub3_content") && chr.quest.tub3_content == "water")	
					{
						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
						Logit(TranslateString("","There is no Salpeter here yet - only water."));
					}
				}
			break;

			case "box6":				
				DoQuestReloadToLocation("GB_Chinatown", "goto", "box2", "Chinatown_box2");
			break;

			case "box7":
				//door (store)
	
				if(CheckAttribute(chr,"quest.gp_nitre_box7") && chr.quest.gp_nitre_box7 == "open")
				{
					//once opened stays open
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key26"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_nitre_box7 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box8":
				if(CheckAttribute(chr, "quest.nitre_lever2") && chr.quest.nitre_lever2 == "down")
				{
					//lever is down				
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l4 = "lever2_up";
					chr.quest.nitre_lever2 = "up";

					LAi_QuestDelay("nitre_lever2_up", 0.5);
				}
				else
				{
					//lever is up				
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l4 = "lever2_down";
					chr.quest.nitre_lever2 = "down";

					LAi_QuestDelay("nitre_lever2_down", 0.5);
				}
			break;

			case "box9":
				chr.quest.nitre_position = "planks";

				if(CheckCharacterItem(chr,"pistolbucket_nitre"))
				{
					if(!IsEquipCharacterByItem(chr, "bladeX4"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					if(!IsEquipCharacterByItem(chr, "pistolbucket_nitre"))
					{
						RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
						EquipCharacterByItem(chr, "pistolbucket_nitre");
					}

					LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_nitre")], false);
					LAi_SetFightMode(chr, true);
				}
			
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","It's here on the planks they let the Salpeter dry."));
				}
			
			break;

			case "box10":
				if(CheckAttribute(chr, "quest.nitre_lever0") && chr.quest.nitre_lever0 == "down")
				{
					//lever is down				
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l6 = "lever0_up";
					chr.quest.nitre_lever0 = "up";

					LAi_QuestDelay("nitre_lever0_up", 0.5);
				}
				else
				{

					//lever is up				
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation("GB_chinese_nitre")].models.always.l6 = "lever0_down";
					chr.quest.nitre_lever0 = "down";

					LAi_QuestDelay("nitre_lever0_down", 0.5);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_charcoal_stairs")
	{
		switch(chr.boxname)
		{
			case "box2":
				DoQuestReloadToLocation("GB_Chinatown", "goto", "box3", "Chinatown_box3");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_charcoal")
	{
		switch(chr.boxname)
		{
			case "box1":
			    //stump, see also box7 for pick up wood
			    if(CheckAttribute(chr, "quest.charcoal_box1") && chr.quest.charcoal_box1 == "on")
			    {
				
			    }
			    else
			    {
				if(CheckAttribute(chr, "quest.charcoal_wood_short") && chr.quest.charcoal_wood_short == "on_stump")
				{
					if(CheckCharacterItem(chr,"bladeaxe3"))
					{
						chr.quest.charcoal_box1 = "on";

						if(!IsEquipCharacterByItem(chr, "bladeaxe3"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeaxe3");
						}

						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("charcoal_cut_short_logs", 1.0);
					}
					else
					{
						if(Locations[FindLocation(chr.location)].models.always.locators == "Hut_locators_charcoal4")
						{
							Logit(TranslateString("","I could need an Axe here."));
							PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
						}
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladewood_short"))
					{
						chr.quest.charcoal_box1 = "on";

						if(!IsEquipCharacterByItem(chr, "bladewood_short"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladewood_short");
						}

						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("charcoal_place_short_logs", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
					}
				}
			    }
			break;

			case "box2":
				//fireplace

			    if(CheckAttribute(chr, "quest.charcoal_box2") && chr.quest.charcoal_box2 == "on")
			    {
				
			    }
			    else
			    {
				if(CheckCharacterItem(chr,"bladewood4"))
				{
					chr.quest.charcoal_box2 = "on";				

					if(!IsEquipCharacterByItem(chr, "bladewood4"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladewood4");
					}

					LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
					LAi_SetFightMode(chr, true);

					LAi_QuestDelay("charcoal_place_wood4", 1.0);
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "Hut_locators_charcoal5")
				{
				    if(Locations[FindLocation(chr.location)].models.always.l1 == "wood4")
				    {
					if(CheckCharacterItem(chr,"pistoltinderbox"))
					{
						chr.quest.charcoal_box2 = "on";	

						if(!IsEquipCharacterByItem(chr, "pistoltinderbox"))
						{
							EquipCharacterByItem(chr, "bladeX4");
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistoltinderbox");
						}
					
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
						LAi_SetFightMode(chr, true);
						chr.quest.charcoal_tinderbox = "enabled";
					}
				    }	
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "Hut_locators_charcoal6")
				{
					//burning
					Logit(TranslateString("","This will take time - I'll do something else meanwhile."));
					PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");

					if(!CheckAttribute(chr,"quest.charcoal4") || chr.quest.charcoal4 != "done")
					{
						AddQuestRecord("Charcoal","4");
						chr.quest.charcoal4 = "done";
					}
				}

				if(Locations[FindLocation(chr.location)].models.always.locators == "Hut_locators_charcoal7")
				{
					if(Locations[FindLocation(chr.location)].models.always.l1 == "wood5")
				    	{
						//black
						if(CheckCharacterItem(chr,"bladeladle"))
						{
							if(!IsEquipCharacterByItem(chr, "bladeladle"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeladle");
							}

							if(CheckCharacterItem(chr,"pistolcharcoal_H"))
							{
								chr.quest.charcoal_box2 = "on";	

								Locations[FindLocation("GB_chinese_charcoal")].locators_radius.box.box2 = 0.0001;
								SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box2", 0.0001);

								if(!IsEquipCharacterByItem(chr, "pistolcharcoal_H"))
								{
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									EquipCharacterByItem(chr, "pistolcharcoal_H");
								}

								LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
								LAi_SetFightMode(chr, true);

								LAi_QuestDelay("charcoal_pick_up_again", 1.0);
							}
							else
							{
								if(CheckCharacterItem(chr,"pistolcharcoal_E"))
								{
									chr.quest.charcoal_box2 = "on";	

									if(!IsEquipCharacterByItem(chr, "pistolcharcoal_E"))
									{
										RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
										EquipCharacterByItem(chr, "pistolcharcoal_E");
									}

									LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
									LAi_SetFightMode(chr, true);

									LAi_QuestDelay("charcoal_pick_up", 1.0);
								}
								else
								{
									PlaySound("VOICE\ENGLISH\blaze_puh.wav");
									Logit(TranslateString("","I need a Jar to collect the Charcoal."));
								}
							}
						}
						else
						{
							if(CheckCharacterItem(chr,"pistolcharcoal_E"))
							{
								if(!IsEquipCharacterByItem(chr, "pistolcharcoal_E"))
								{
									RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
									EquipCharacterByItem(chr, "pistolcharcoal_E");
								}

								PlaySound("VOICE\ENGLISH\blaze_puh.wav");
								Logit(TranslateString("","I need a Ladle to scoop the Charcoal from the fireplace."));

								if(!CheckAttribute(chr,"quest.charcoal3") || chr.quest.charcoal3 != "done")
								{
									AddQuestRecord("Charcoal","3");
									chr.quest.charcoal3 = "done";
								}

								chr.quest.guest_charcoal = "time";
								LAi_QuestDelay("china_guests_out", 1.0);
							}
						}
						else 
						{
							PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
							Logit(TranslateString("","I need a Ladle to scoop the Charcoal from the fireplace."));
							Logit(TranslateString("","I need a Jar to collect the Charcoal."));
						}
					}

					if(Locations[FindLocation(chr.location)].models.always.l1 == "wood3")
				    	{
						//only glowing		
						Logit(TranslateString("","This will take time - I'll do something else meanwhile."));
						PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");

						if(!CheckAttribute(chr,"quest.charcoal4") || chr.quest.charcoal4 != "done")
						{
							AddQuestRecord("Charcoal","4");
							chr.quest.charcoal4 = "done";
						}
					}
				}
			    }
			break;

			case "box3":
				//bed
				LAi_SetSitType(chr);
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "Hut_locators_charcoal2";

				LAi_QuestDelay("charcoal_push_log", 0.5);
			break;

			case "box4":
			    //saw
			    if(CheckAttribute(chr, "quest.charcoal_box4") && chr.quest.charcoal_box4 == "on")
			    {
				
			    }
			    else
			    {
			          if(CheckAttribute(chr, "quest.key24") && chr.quest.key24 == "picked_up")
			   	  {          			
					if(CheckCharacterItem(chr,"bladesaw"))
					{
						chr.quest.charcoal_box4 = "on";

						if(!IsEquipCharacterByItem(chr, "bladesaw"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladesaw");
						}

						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_charcoal")], false);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("charcoal_saw_log", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
						Logit(TranslateString("","I could need a Saw here."));
					}
				  }
				  else
				  {
					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
					Logit(TranslateString("","I have missed something."));
				  }
			    }
			break;

			case "box5":
			        //door to charcoal storeroom
			   
				if(CheckAttribute(chr, "quest.charcoal_box5") && chr.quest.charcoal_box5 == "on")
			    	{
				
			    	}
			    	else
			    	{
					if(CheckCharacterItem(chr,"key24"))
					{
						chr.quest.charcoal_box5 = "on";							
						PlaySound("INTERFACE\key_unlock.wav");

						LAi_QuestDelay("unlock_charcoal_storeroom", 2.0);
					}
					else
					{
						PlaySound("INTERFACE\knock.wav");
					}
				}			    
			break;

			case "box6":
			        //pick up wood_short_floor
				
				PlaySound("INTERFACE\cancel.wav");
				GiveItem2Character(chr, "bladewood_short");				
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladewood_short");	

				LAi_QuestDelay("pick_up_wood_short_floor", 0.5);		    
			break;

			case "box7":
			        //pick up wood4_stump
				
				Locations[FindLocation("GB_chinese_charcoal")].locators_radius.box.box7 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box7", 0.0001);

				PlaySound("INTERFACE\cancel.wav");
				GiveItem2Character(chr, "bladewood4");				
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladewood4");	

				LAi_QuestDelay("pick_up_wood4_stump", 0.5);		    
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_sulphur_corridor")
	{
		switch(chr.boxname)
		{
			case "box2":
				if(CheckAttribute(chr,"quest.sulf_corridor_box2") && chr.quest.sulf_corridor_box2 == "open")
				{
					//once opened stays open
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key25"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.sulf_corridor_box2 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="GB_chinese_sulphur")
	{
		switch(chr.boxname)
		{
			case "box1":
			    if(CheckAttribute(chr, "quest.sulfur_box1") && chr.quest.sulfur_box1 == "on")
			    {
				
			    }
			    else
			    {
				if(CheckAttribute(chr, "quest.pyrite_stones"))
				{
				    	switch(chr.quest.pyrite_stones)
				    	{
						case "many":
							if(CheckCharacterItem(chr,"sledgehammer"))
							{
								if(!IsEquipCharacterByItem(chr, "sledgehammer"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "sledgehammer");
								}
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);

								chr.quest.sulfur_position = "planks";
								LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
								LAi_SetFightMode(chr, true);

								chr.quest.sulfur_box1 = "on";
								LAi_QuestDelay("pyrite_stones_smashed", 1.0);
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","I need a tool to smash the Pyrite stones to dust."));
							}
					   	break;

					    	case "few":
							if(CheckCharacterItem(chr,"sledgehammer"))
							{
								if(!IsEquipCharacterByItem(chr, "sledgehammer"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "sledgehammer");
								}
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);

								chr.quest.sulfur_position = "planks";
								LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
								LAi_SetFightMode(chr, true);

								chr.quest.sulfur_box1 = "on";
								LAi_QuestDelay("pyrite_stones_smashed_again", 1.0);
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","I need a tool to smash the Pyrite stones to dust."));
							}
					    	break;

						case "dust":
							if(CheckCharacterItem(chr,"bladebroom"))
							{				
								if(!IsEquipCharacterByItem(chr, "bladebroom"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladebroom");
								}

								if(CheckCharacterItem(chr,"pistolpyrite_H"))
								{
									if(!IsEquipCharacterByItem(chr, "pistolpyrite_H"))
									{
										RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
										EquipCharacterByItem(chr, "pistolpyrite_H");
									}

									chr.quest.sulfur_position = "planks";
									LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
									LAi_SetFightMode(chr, true);

									chr.quest.sulfur_box1 = "on";
									LAi_QuestDelay("pyrite_dust_pick_up_again", 1.0);
								}
								else
								{
									if(CheckCharacterItem(chr,"pistolpyrite_E"))
									{
										if(!IsEquipCharacterByItem(chr, "pistolpyrite_E"))
										{
											RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
											EquipCharacterByItem(chr, "pistolpyrite_E");
										}

										chr.quest.sulfur_position = "planks";
										LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
										LAi_SetFightMode(chr, true);

										chr.quest.sulfur_box1 = "on";
										LAi_QuestDelay("pyrite_dust_pick_up", 1.0);
									}
									else
									{
										PlaySound("VOICE\ENGLISH\blaze_puh.wav");
										Logit(TranslateString("","I need a Box to collect the Pyrite Dust."));

										if(!CheckAttribute(chr,"quest.sulfur4") || chr.quest.sulfur4 != "done")
										{
											AddQuestRecord("Sulfur","4");
											chr.quest.sulfur4 = "done";
										}

										chr.quest.guest_sulfur = "time";
										LAi_QuestDelay("china_guests_out", 1.0);
									}
								}
							}
							else
							{
								if(CheckCharacterItem(chr,"pistolpyrite_E"))
								{
									if(!IsEquipCharacterByItem(chr, "pistolpyrite_E"))
									{
										RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
										EquipCharacterByItem(chr, "pistolpyrite_E");
									}

									PlaySound("VOICE\ENGLISH\blaze_puh.wav");
									Logit(TranslateString("","I need a Broom to sweep the Pyrite Dust from the floor."));
								}
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","I need a Broom to sweep the Pyrite Dust from the floor."));
								Logit(TranslateString("","I need a Box to collect the Pyrite Dust."));
							}
					    	break;

					    	case "no":
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					    	break;
					}
					return;
				}
			    }
			break;

			case "box2":
				//clock

				if(CheckAttribute(chr,"quest.gp_sulf_chest2") && chr.quest.gp_sulf_chest2 == "open")
				{
					//once opened stays open
					PlaySound("INTERFACE\clock.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					if(CheckCharacterItem(chr,"key25"))
					{
						PlaySound("INTERFACE\key_unlock2.wav");
						chr.quest.gp_sulf_chest2 = "open";
						
						return;
					}
					else
					{
						PlaySound("INTERFACE\locked_window.wav");
						return;
					}
				}
			break;

			case "box3":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "GB_chinese_sulphur", "goto", "box4");
			break;

			case "box4":	
				if(CheckAttribute(chr, "quest.sulfur_water") && chr.quest.sulfur_water == "filled")
				{
					PlaySound("INTERFACE\rum_barrel_filled.wav");

					LAi_QuestDelay("sulfur_empty_bucket1", 1.5);
				}
				else
				{
					if(CheckCharacterItem(chr,"pistolbucket_water"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeX4"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeX4");
						}

						if(!IsEquipCharacterByItem(chr, "pistolbucket_water"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolbucket_water");
						}
						
						chr.quest.sulfur_position = "ladder";
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
						LAi_SetFightMode(chr, true);
					}
					else
					{
						PlaySound("INTERFACE\rum_barrel_empty.wav");

						LAi_QuestDelay("sulfur_empty_bucket1", 3.0);					
					}
				}
			break;

			case "box5":
				//med chest

				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		
			case "box6":
			    if(CheckAttribute(chr, "quest.sulfur_box6") && chr.quest.sulfur_box6 == "on")
			    {
				
			    }
			    else
			    {
				if(CheckAttribute(chr, "quest.pyrite_stones"))
				{
				    	switch(chr.quest.pyrite_stones)
				    	{
						case "many":
							if(CheckCharacterItem(chr,"sledgehammer"))
							{
								if(!IsEquipCharacterByItem(chr, "sledgehammer"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "sledgehammer");
								}
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);

								chr.quest.sulfur_position = "planks";
								LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
								LAi_SetFightMode(chr, true);

								chr.quest.sulfur_box6 = "on";
								LAi_QuestDelay("pyrite_stones_smashed", 1.0);
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","I need a tool to smash the Pyrite stones to dust."));
							}
					   	break;

					    	case "few":
							if(CheckCharacterItem(chr,"sledgehammer"))
							{
								if(!IsEquipCharacterByItem(chr, "sledgehammer"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "sledgehammer");
								}
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);

								chr.quest.sulfur_position = "planks";
								LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
								LAi_SetFightMode(chr, true);

								chr.quest.sulfur_box6 = "on";
								LAi_QuestDelay("pyrite_stones_smashed_again", 1.0);
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","I need a tool to smash the Pyrite stones to dust."));
							}
					    	break;

						case "dust":
							if(CheckCharacterItem(chr,"bladebroom"))
							{				
								if(!IsEquipCharacterByItem(chr, "bladebroom"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladebroom");
								}

								if(CheckCharacterItem(chr,"pistolpyrite_H"))
								{
									if(!IsEquipCharacterByItem(chr, "pistolpyrite_H"))
									{
										RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
										EquipCharacterByItem(chr, "pistolpyrite_H");
									}

									chr.quest.sulfur_position = "planks";
									LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
									LAi_SetFightMode(chr, true);

									chr.quest.sulfur_box6 = "on";
									LAi_QuestDelay("pyrite_dust_pick_up_again", 1.0);
								}
								else
								{
									if(CheckCharacterItem(chr,"pistolpyrite_E"))
									{
										if(!IsEquipCharacterByItem(chr, "pistolpyrite_E"))
										{
											RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
											EquipCharacterByItem(chr, "pistolpyrite_E");
										}

										chr.quest.sulfur_position = "planks";
										LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
										LAi_SetFightMode(chr, true);

										chr.quest.sulfur_box6 = "on";
										LAi_QuestDelay("pyrite_dust_pick_up", 1.0);
									}
									else
									{
										PlaySound("VOICE\ENGLISH\blaze_puh.wav");
										Logit(TranslateString("","I need a Box to collect the Pyrite Dust."));
									}
								}
							}
							else
							{
								if(CheckCharacterItem(chr,"pistolpyrite_E"))
								{
									if(!IsEquipCharacterByItem(chr, "pistolpyrite_E"))
									{
										RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
										EquipCharacterByItem(chr, "pistolpyrite_E");
									}

									PlaySound("VOICE\ENGLISH\blaze_puh.wav");
									Logit(TranslateString("","I need a Broom to sweep the Pyrite Dust from the floor."));
								}
							}
							else 
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","I need a Broom to sweep the Pyrite Dust from the floor."));
								Logit(TranslateString("","I need a Box to collect the Pyrite Dust."));
							}
					    	break;

					    	case "no":
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					    	break;
					}
					return;
				}
			    }
			break;
	
			case "box7":
				if(CheckAttribute(chr, "quest.sulfur_pyrite") && chr.quest.sulfur_pyrite == "sulfur")
				{
					if(CheckCharacterItem(chr,"pistolsulphur_H"))
					{
						if(!IsEquipCharacterByItem(chr, "pistolsulphur_H"))
						{
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							EquipCharacterByItem(chr, "pistolsulphur_H");
						}

						ChangeCharacterAddressGroup(chr, "GB_chinese_sulphur", "goto", "stuck_at_hatch");
						chr.quest.sulfur_position = "hatch3";
						LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
						LAi_SetFightMode(chr, true);
					}
					else
					{
						if(CheckCharacterItem(chr,"pistolsulphur_E"))
						{
							if(!IsEquipCharacterByItem(chr, "pistolsulphur_E"))
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistolsulphur_E");
							}

							ChangeCharacterAddressGroup(chr, "GB_chinese_sulphur", "goto", "stuck_at_hatch");
							chr.quest.sulfur_position = "hatch2";
							LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
							LAi_SetFightMode(chr, true);
						}
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.sulfur_pyrite") && chr.quest.sulfur_pyrite == "filled")
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","No, I have filled the distillery with Pyrite Dust already."));
					}
					else
					{
						if(CheckCharacterItem(chr,"pistolpyrite_F"))
						{
							if(!IsEquipCharacterByItem(chr, "pistolpyrite_F"))
							{
								RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
								EquipCharacterByItem(chr, "pistolpyrite_F");
							}
						
							ChangeCharacterAddressGroup(chr, "GB_chinese_sulphur", "goto", "stuck_at_hatch");
							chr.quest.sulfur_position = "hatch";
							LAi_LocationFightDisable(&Locations[FindLocation("GB_chinese_sulphur")], false);
							LAi_SetFightMode(chr, true);
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");			
						}
					}
				}
			break;	

			case "box8":
				if(CheckAttribute(chr, "quest.sulfur_lever") && chr.quest.sulfur_lever == "down")
				{
					//lever is down				
					PlaySound("INTERFACE\lever_up.wav");
					Locations[FindLocation("GB_chinese_sulphur")].models.always.l3 = "lever_up";
					chr.quest.sulfur_lever = "up";
					chr.quest.sulfur_distillery = "enabled";

					LAi_QuestDelay("sulfur_lever_up", 0.5);
				}
				else
				{

					//lever is up				
					PlaySound("INTERFACE\lever_down.wav");
					Locations[FindLocation("GB_chinese_sulphur")].models.always.l3 = "lever_down";
					chr.quest.sulfur_lever = "down";

					chr.quest.sulfur_fire = "off";
					chr.quest.sulfur_boiling = "off";
					chr.quest.sulfur_dust = "off";
					chr.quest.sulfur_distill = "off";
				
					chr.quest.sulfur_distillery = "disabled";

					LAi_QuestDelay("sulfur_lever_down", 0.5);
				}
			break;

			case "box9":
				//pull rope
				if(CheckAttribute(chr, "quest.sulfur_rope") && chr.quest.sulfur_rope == "on") return;

				if(CheckAttribute(chr, "quest.pyrite_stones") && chr.quest.pyrite_stones != "no")
				{
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					Logit(TranslateString("","No, I have enough pyrite on the floor already."));
				}
				else
				{
					chr.quest.sulfur_rope = "on";

					PlaySound("PEOPLE\basket.wav");
					LAi_SetSitType(chr);

					LAi_QuestDelay("sulfur_pull_rope", 1.0);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Bessop_plantation")
	{
		switch(chr.boxname)
		{
			case "box3":
				//to swamp

				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "reload", "reload3");

				LAi_QuestDelay("plant_turn_to_look1", 0.01);
			break;
		//...............................................................................
			case "box7":
				//dead end

				chr.quest.plantation_lake = "way_in";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box5");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_in")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box5");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box6");
	
					LAi_QuestDelay("pchar_playertype", 1.0);
				}

				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box7");
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_in")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box6");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "look2");
	
					LAi_QuestDelay("pchar_playertype", 1.0);
				}

				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box4");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box7");
	
					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;

			case "box6":
				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_in")
				{
					PlaySound("PEOPLE\clothes3.wav");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box5");
	
					LAi_QuestDelay("plantation_lake", 1.0);
				}

				if(CheckAttribute(chr, "quest.plantation_lake") && chr.quest.plantation_lake == "way_back")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box5");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box4");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;
	//...............................................................................
			case "box8":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box9");
			break;

			case "box9":
				PlaySound("INTERFACE\knock.wav");
				
				LAi_QuestDelay("Bessop_box9", 1.0);
			break;

			case "box10":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box11");

				LAi_QuestDelay("Bessop_box10", 1.0);
			break;

			case "box11":
				PlaySound("INTERFACE\knock.wav");
				
				LAi_QuestDelay("Bessop_box11", 1.0);
			break;

			case "box12":
				PlaySound("PEOPLE\run_roof.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box13");
			break;

			case "box13":
				PlaySound("PEOPLE\clothes3.wav");		//some action here?
				
				LAi_QuestDelay("Bessop_box13", 1.0);
			break;

			case "box14":
				PlaySound("PEOPLE\run_roof.wav");
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box13");
			break;
	//----------------------------------------------------------------------------------------------------
			case "box15":
				//climb mountain
		
				if (makeint(environment.time) > 6.00 && makeint(environment.time) < 22.00)
				{
					//DAYTIME

					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			
					LAi_QuestDelay("wait_climb_until_dark", 1.0);
				}
				else
				{
					SetCurrentTime(22.00, 0);
					SetNextWeather("Clear");

					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box33");
				}
			break;
			
			case "box33":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box36");	

				LAi_QuestDelay("bessop_box33", 0.1);		
			break;

			case "box36":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box37");			
			break;

			case "box37":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "mountain");

				LAi_QuestDelay("Jupiter_to_mountain", 2.0);			
			break;
	//----------------------------------------------------------------------------------------------------
	//OUTSIDE PLANTATION
			case "box16":
				LAi_QuestDelay("plantation_patrol_attacking", 0.01);
			break;

			case "box17":
				//sneak close to mountain

				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak2");				
			break;
	//----------------------------------------------------------------------------------------------------
	//FENCE & START SEQUENCE
			case "box18":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak3");

				LAi_QuestDelay("climb_bessop_fence", 1.0);				
			break;

		//EXTRA ON WAY BACK
			case "box91":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box17_B");			
			break;

			case "box32":
				if(CheckAttribute(chr, "quest.bessop_box86") && chr.quest.bessop_box86 == "on")
				{
					InterfaceStates.Buttons.Save.enable = 1;
					chr.quest.bessop_box86 = "off";
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak3_B");

					LAi_QuestDelay("climb_bessop_fence_back", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box19");	
				}		
			break;

			case "box19":
				if(CheckAttribute(chr, "quest.bessop_box86") && chr.quest.bessop_box86 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box32_B");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box20");	
				}			
			break;

			case "box20":
				if(CheckAttribute(chr, "quest.bessop_box86") && chr.quest.bessop_box86 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box19_B");	
				}
				else
				{
					if(CheckAttribute(chr, "quest.bessop_bales_shortcut") && chr.quest.bessop_bales_shortcut == "on")
					{
						PlaySound("PEOPLE\grass_turn.wav");
						ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box50");	
					}
					else
					{
						PlaySound("PEOPLE\grass_turn.wav");
						ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box42");	

						LAi_QuestDelay("bessop_box20", 1.0);
					}
				}			
			break;

			case "box42":
				if(CheckAttribute(chr, "quest.bessop_box86") && chr.quest.bessop_box86 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box50_B");	
				}
				else
				{
					chr.quest.bessop_bales_shortcut = "on";	
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box50");		

					LAi_QuestDelay("bessop_box42", 1.0);
				}			
			break;

		//WAY BACK
			case "box87":
				chr.quest.bessop_pchar_safe = "yes";
				chr.quest.bessop_box86 = "on";			//YES 86
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box42_B");			
			break;

		//WAY BACK
			case "box88":
				chr.quest.bessop_pchar_safe = "yes";
				chr.quest.bessop_box86 = "on";			//YES 86
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box42_B");			
			break;

			case "box50":
				if(CheckAttribute(chr, "quest.bessop_box86") && chr.quest.bessop_box86 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box20_B");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box23");	

					LAi_QuestDelay("bessop_box50", 0.1);
				}			
			break;
		
		//WAY BACK
			case "box86":
				chr.quest.bessop_pchar_safe = "yes";
				chr.quest.bessop_box86 = "on";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box50_B");			
			break;

			case "box23":
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak5");
				LAi_SetPlayerType(chr);
			//chr.quest.bessop_gate_alarm = "off";
				LAi_SetCitizenType(characterFromID("bessop_patrol5"));	
				chr.quest.bessop_pchar_safe = "no";			
	
		//temp off while working
	
				LAi_QuestDelay("plantation_patrol_reacting", 0.1);			
	/*	
				chr.quest.Bessop_tower2_alarmA.win_condition.l1 = "locator";
				chr.quest.Bessop_tower2_alarmA.win_condition.l1.location = "Bessop_plantation";
				chr.quest.Bessop_tower2_alarmA.win_condition.l1.locator_group = "goto";
				chr.quest.Bessop_tower2_alarmA.win_condition.l1.locator = "goto11";
				chr.quest.Bessop_tower2_alarmA.win_condition = "Bessop_tower2_alarm";
	
				chr.quest.Bessop_tower2_alarmB.win_condition.l1 = "locator";
				chr.quest.Bessop_tower2_alarmB.win_condition.l1.location = "Bessop_plantation";
				chr.quest.Bessop_tower2_alarmB.win_condition.l1.locator_group = "goto";
				chr.quest.Bessop_tower2_alarmB.win_condition.l1.locator = "goto11A";
				chr.quest.Bessop_tower2_alarmB.win_condition = "Bessop_tower2_alarm";
	
				chr.quest.Bessop_tower2_alarmC.win_condition.l1 = "locator";
				chr.quest.Bessop_tower2_alarmC.win_condition.l1.location = "Bessop_plantation";
				chr.quest.Bessop_tower2_alarmC.win_condition.l1.locator_group = "goto";
				chr.quest.Bessop_tower2_alarmC.win_condition.l1.locator = "goto11B";
				chr.quest.Bessop_tower2_alarmC.win_condition = "Bessop_tower2_alarm";

				chr.quest.Bessop_tower2_alarmD.win_condition.l1 = "locator";
				chr.quest.Bessop_tower2_alarmD.win_condition.l1.location = "Bessop_plantation";
				chr.quest.Bessop_tower2_alarmD.win_condition.l1.locator_group = "goto";
				chr.quest.Bessop_tower2_alarmD.win_condition.l1.locator = "goto11C";
				chr.quest.Bessop_tower2_alarmD.win_condition = "Bessop_tower2_alarm";
	
				chr.quest.Bessop_tower2_alarmE.win_condition.l1 = "locator";
				chr.quest.Bessop_tower2_alarmE.win_condition.l1.location = "Bessop_plantation";
				chr.quest.Bessop_tower2_alarmE.win_condition.l1.locator_group = "goto";
				chr.quest.Bessop_tower2_alarmE.win_condition.l1.locator = "patrol2";
				chr.quest.Bessop_tower2_alarmE.win_condition = "Bessop_tower2_alarm";	
	*/
			break;
	//----------------------------------------------------------------------------------------------------
	//BALES
			case "box24":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box25");			
			break;
	
			case "box90":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box24_B");			
			break;

			case "box25":
				if(CheckAttribute(chr, "quest.bessop_box85") && chr.quest.bessop_box85 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box90_B");
					chr.quest.bessop_box85 = "off";	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box26");	
				}		
			break;

			case "box26":
				chr.quest.bessop_pchar_safe = "no";
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak6");			
			break;

		//WAY BACK
			case "box85":
				chr.quest.bessop_pchar_safe = "yes";
				chr.quest.bessop_box85 = "on";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box25_B");			
			break;
	//----------------------------------------------------------------------------------------------------
	//BALES & WAGON
			case "box2":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box29");	

				LAi_QuestDelay("bessop_box2", 0.1);		
			break;
			
			case "box89":
				//only on way back
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box2_B");			
			break;

			case "box29":
				if(CheckAttribute(chr, "quest.bessop_box84") && chr.quest.bessop_box84 == "on")
				{
					chr.quest.bessop_box84 = "off";
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box89_B");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box30");	
				}		
			break;

			case "box30":
				if(CheckAttribute(chr, "quest.bessop_box84") && chr.quest.bessop_box84 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box29_B");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box31");
				}			
			break;

			case "box31":
				if(CheckAttribute(chr, "quest.bessop_box84") && chr.quest.bessop_box84 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box30_B");	
				}
				else
				{
					chr.quest.bessop_pchar_safe = "no";
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak7");
				}			
			break;

		//WAY BACK
			case "box84":
				chr.quest.bessop_pchar_safe = "yes";
				chr.quest.bessop_box84 = "on";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box31_B");			
			break;
	//----------------------------------------------------------------------------------------------------
	//GRASS SEQUENCE
			case "box27":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box34");			
			break;

			case "box34":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box35");			
			break;

			case "box35":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box39");			
			break;

			case "box39":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box41");	

				LAi_QuestDelay("bessop_box39", 0.1);		
			break;

			case "box41":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "box", "box83");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box47");	
				}						
			break;

			case "box47":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box41");	
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box48");	
				}		
			break;

			case "box48":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box47");	
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box49");	
				}		
			break;

			case "box49":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box48");	
				}
				else
				{
					chr.quest.bessop_pchar_safe = "no";
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak4");
				}			
			break;

			case "box73":
				if(CheckAttribute(chr, "quest.bessop_box80") && chr.quest.bessop_box80 == "on")
				{
					chr.quest.bessop_box80 = "off";
					chr.quest.bessop_pchar_safe = "no";
					DoQuestReloadToLocation("Bessop_storeroom3", "reload", "reload3", "");
				}
				else
				{
					chr.quest.bessop_pchar_safe = "yes";
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box47");	

					LAi_QuestDelay("bessop_box39A", 1.0);
				}
			break;

		//FENCE TO STOREROOM 3
			case "box80":
				chr.quest.bessop_box80 = "on";
				chr.quest.bessop_pchar_safe = "yes";
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_counter.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "fence73");

				LAi_QuestDelay("bessop_box80", 0.5);				
			break;
	//----------------------------------------------------------------------------------------------------
	//ROOF SEQUENCE
			case "box28":
				//climb over fence inside plantation

				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak8");

				LAi_QuestDelay("climb_bessop_inner_fence", 1.0);				
			break;

			case "box22":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					chr.quest.bessop_box81 = "off";
					chr.quest.bessop_pchar_safe = "no";
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "reload", "reload10");	

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\recoil.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box38");	

					LAi_QuestDelay("bessop_box22", 0.5);
				}		
			break;

			case "box38":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_stairway.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box22");	

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_ground2.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box40");	

					LAi_QuestDelay("bessop_box38", 0.5);
				}				
			break;

			case "box40":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box38");
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box43");	

					LAi_QuestDelay("bessop_box40", 1.0);	
				}		
			break;

			case "box43":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box40_B");	

					LAi_QuestDelay("bessop_box43_B", 1.0);
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box44");	

					LAi_QuestDelay("bessop_box43", 0.5);
				}
			break;

			case "box44":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box43_B");

					LAi_QuestDelay("pchar_playertype", 0.5);
					LAi_QuestDelay("bessop_box44_B", 1.0);	
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box45");	

					LAi_QuestDelay("bessop_box44", 1.0);	
				}		
			break;

			case "box45":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box44_B");	
				}
				else
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box46");	

					LAi_QuestDelay("bessop_box44", 0.5);
				}		
			break;

			case "box46":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box45_B");	

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box21");	

					LAi_QuestDelay("bessop_box43", 1.0);
				}		
			break;

			case "box21":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box46_B");	
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");	
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box51");	
				}		
			break;

			case "box51":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					LAi_SetSitType(chr);
					PlaySound("PEOPLE\step_ground2.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box21_B");

					LAi_QuestDelay("pchar_playertype", 0.5);	
				}
				else
				{
					PlaySound("PEOPLE\jump_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "box", "box83");	
				}
			break;

			case "box83":
				if(CheckAttribute(chr, "quest.bessop_box81") && chr.quest.bessop_box81 == "on")
				{
					PlaySound("PEOPLE\creak2.wav");	
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box51");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box41");	
				
					LAi_QuestDelay("bessop_box39", 0.1);
				}		
			break;
	//----------------------------------------------------------------------------------------------------
	//GRASS WAY BACK + ROOF WAY BACK
			case "box81":	
				chr.quest.bessop_box81 = "on";
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box49");			
			break;


	//----------------------------------------------------------------------------------------------------
	//BETWEEN BARRELS & SUGARCANES SEQUENCE
			case "box1":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box52");			
			break;

			case "box52":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box53");			
			break;

			case "box53":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box54");			
			break;

			case "box54":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box1");			
			break;
	//----------------------------------------------------------------------------------------------------		
	//PLANKS & GRASS SEQUENCE		
			case "box55":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box56");			
			break;

			case "box56":
				if(CheckAttribute(chr, "quest.bessop_box59") && chr.quest.bessop_box59 == "on")
				{
					chr.quest.bessop_box59 = "off";
					chr.quest.bessop_pchar_safe = "no";
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box55");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box57");
				}			
			break;

			case "box57":
				if(CheckAttribute(chr, "quest.bessop_box59") && chr.quest.bessop_box59 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box56");	
				}
				else
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box58");	
				}		
			break;

			case "box58":
				if(CheckAttribute(chr, "quest.bessop_box59") && chr.quest.bessop_box59 == "on")
				{
					PlaySound("PEOPLE\grass_turn.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box57");	
				}
				else
				{
				//	LAi_SetSitType(chr);
					PlaySound("PEOPLE\place_planks.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak9");

					LAi_QuestDelay("bessop_box58", 0.5);
				}				
			break;

		//WAY BACK
			case "box59":
			//	LAi_SetSitType(chr);
				chr.quest.bessop_box59 = "on";
				PlaySound("PEOPLE\place_planks.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak9_B");

				LAi_QuestDelay("bessop_box59", 0.5);				
			break;


	//----------------------------------------------------------------------------------------------------		
	//QUICK HIDE & OUT AGAIN
			case "box60":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box61");			
			break;

			case "box61":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box60");			
			break;
	//----------------------------------------------------------------------------------------------------	
	//CLOSE TO STOCKADE
			case "box62":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box63");			
			break;

			case "box63":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box64");			
			break;

			case "box64":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box65");			
			break;

			case "box65":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box66");			
			break;

		//WAY BACK
			case "box66":
				PlaySound("PEOPLE\grass_turn.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box77");			
			break;

			case "box77":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box78");			
			break;

			case "box78":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box62");			
			break;

		//DIRECT TO BEHIND CART
			case "box76":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box63");			
			break;
	//----------------------------------------------------------------------------------------------------	
	//JUMP OVER BARREL
			case "box67":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_counter.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak10");

				LAi_QuestDelay("bessop_box67", 0.5);				
			break;

			case "box68":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_counter.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak10A");

				LAi_QuestDelay("bessop_box68", 0.5);				
			break;
	//----------------------------------------------------------------------------------------------------	
	//COMPLEX HIDING PLACE
			case "box69":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak11");			
			break;
			
			case "box70":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box71");	

				LAi_QuestDelay("bessop_box70", 2.5);			
			break;
	
			case "box71":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak11");			
			break;

		//WAY BACK
			case "box72":
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box79");			
			break;

			case "box79":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box69");			
			break;
	//----------------------------------------------------------------------------------------------------	
	//VIA STOREROOM4	
			case "box74":	
				if(CheckAttribute(chr, "quest.bessop_box82") && chr.quest.bessop_box82 == "on")
				{
					chr.quest.bessop_pchar_safe = "no";
					DoQuestReloadToLocation("Bessop_storeroom4", "box", "box1", "");
				}
				else
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box75");	
				}		
			break;

			case "box75":
				chr.quest.bessop_pchar_safe = "no";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "sneak12");			
			break;

		//WAY BACK
			case "box82":	
				chr.quest.bessop_box82 = "on";
				chr.quest.bessop_pchar_safe = "yes";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_plantation", "goto", "box74");			
			break;
	//----------------------------------------------------------------------------------------------------	

//JRH Bessop
		}

		return;
	}

	if(Locations[locidx].id=="Bessop_storeroom4")
	{
		switch(chr.boxname)
		{
			case "box1":
				chr.quest.bessop_box82 = "off";
				chr.quest.bessop_pchar_safe = "yes";
				DoQuestReloadToLocation("Bessop_plantation", "goto", "box74", "");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Bessop_tavern")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_tavern", "box", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\counter_openclose.wav");
				ChangeCharacterAddressGroup(chr, "Bessop_tavern", "box", "box1");
			break;

			case "box3":
				PlaySound("INTERFACE\small_door.wav");
				LaunchItemsBox(&ar);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Charleston_swamp")
	{
		switch(chr.boxname)
		{
			case "box1":
				//not used
			break;

			case "box2":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_swamp", "goto", "box3");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "lookR2");
	
				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box3":
				DoQuestReloadToLocation("Charleston_passage", "reload", "reload2", "");
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Swamp_loghouse")
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

	if(Locations[locidx].id=="Loghouse_stairs")
	{
		switch(chr.boxname)
		{
			case "box2":
				if(CheckAttribute(chr, "quest.Loghouse_stairs.box2") && chr.quest.Loghouse_stairs.box2 == "locked")
				{
					PlaySound("INTERFACE\knock.wav");		
				}
				else
				{
					if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

					SetNextWeather("Clear");
					chr.quest.JRH_rain = "clear";

					chr.quest.box_blocked = "yes";
					DoQuestReloadToLocation("Maroon_hideout", "reload", "reload1", "box_enabled");
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Maroon_hideout")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box2");
			break;

			case "box2":
				PlaySound("PEOPLE\run_wood.wav");
				
				if(CheckAttribute(chr, "quest.searching_for_key30") && chr.quest.searching_for_key30 == "yes")
				{
					ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "key");

					LAi_QuestDelay("key30_pickup_check", 0.1);
				}
				else ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box8");
			break;

			case "box8":
				if(CheckAttribute(chr, "quest.mar_hideout_turn_to_box3") && chr.quest.mar_hideout_turn_to_box3 == "yes")
				{
					PlaySound("PEOPLE\run_wood.wav");

					if(Locations[FindLocation(chr.location)].models.always.locators == "Cave_Ship_l_GB_open")
					{
						ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box3");
					}
					else ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box7");

					chr.quest.mar_hideout_turn_to_box3 = "no";
				}
				else
				{
					PlaySound("PEOPLE\creak2.wav");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box3");

					LAi_QuestDelay("pchar_playertype", 1.0);
					LAi_QuestDelay("mar_hideout_turn_to_box3", 1.0);
				}
			break;

			case "box3":
				PlaySound("PEOPLE\counter_open.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box5");
			break;

			case "box5":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box9");
			break;

			case "box9":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

				chr.quest.box_blocked = "yes";
				DoQuestReloadToLocation("Maroon_cavern", "reload", "reload4", "box_enabled");
			break;

			case "box10":
				if(CheckAttribute(chr, "quest.hideout.box10") && chr.quest.hideout.box10 == "locked")
				{
					PlaySound("INTERFACE\knock.wav");		
				}
				else
				{
					if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

					SetNextWeather("Clear");
	 				DeleteAttribute(chr, "quest.JRH_rain");

					chr.quest.box_blocked = "yes";
					DoQuestReloadToLocation("Loghouse_stairs", "goto", "goto4", "box_enabled");
				}
			break;

			//-----------------------------------------------------------------------------------

			case "box4":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box6");
			break;

			case "box6":
				PlaySound("PEOPLE\counter_open.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box7");
			break;

			case "box7":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "goto", "box1");
			break;

			//-----------------------------------------------------------------------------------
			//TO RAFT
			case "box12":
				PlaySound("PEOPLE\step_dpwater2.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "box", "box11");

				ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Maroon_hideout", "box", "box12");
			break;

			case "box11":
				PlaySound("PEOPLE\run_wood.wav");
				PlaySound("PEOPLE\step_dpwater2.wav");
				ChangeCharacterAddressGroup(chr, "Maroon_hideout", "box", "box13");
				ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Maroon_hideout", "goto", "box11");

				LAi_QuestDelay("Poe_to_raft", 1.0);
			break;

			case "box13":
				if(CheckAttribute(chr, "quest.box13_HO_blocked") && chr.quest.box13_HO_blocked == "yes") return;

				chr.quest.box13_HO_blocked = "yes";

				if(CheckAttribute(chr, "Poe_on_raft") && chr.Poe_on_raft == "yes")
				{
					DoQuestReloadToLocation("Bishops_Hostel", "goto", "box54", "raft3_to_BH");
				}
				else 
				{
					PlaySound("PEOPLE\recoil.wav");
					LAi_SetPoorType(characterFromID("Edgar Allan Poe"));

					LAi_QuestDelay("Poe_to_raft1", 0.5);
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Charleston_passage")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_passage", "goto", "goto8");
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;
				
				if(CheckAttribute(chr, "quest.mar_cav_from_plant") && chr.quest.mar_cav_from_plant == "open")
				{
					SetNextWeather("Clear");
					chr.quest.JRH_rain = "clear";

					chr.quest.box_blocked = "yes";
					DoQuestReloadToLocation("Maroon_Cavern", "reload", "reload1", "box_enabled");
				}
				else
				{
					if(CheckCharacterItem(chr,"key30"))
					{
						PlaySound("INTERFACE\key_unlock.wav");	
						SetNextWeather("Clear");
						chr.quest.JRH_rain = "clear";

						chr.quest.box_blocked = "yes";

						LAi_QuestDelay("unlock_maroon_cave", 2.0);
					}
					else PlaySound("INTERFACE\knock.wav");	
				} 
			break;
		/*
			case "box3":
				SetNextWeather("Clear");
				chr.quest.JRH_rain = "clear";

				DoQuestReloadToLocation("Maroon_hideout", "box", "box1", "raft_to_hideout1");
			break;
		*/

		}

		return;
	}

	if(Locations[locidx].id=="Maroon_Cavern")
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
				//EXIT VIA ROPE TO MOUNTAIN TOP
				
				if(CheckAttribute(chr, "quest.ch_shore_resuse_ladder") && chr.quest.ch_shore_resuse_ladder == "no")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","No idea go that way now."));
					return;
				}

				if(Locations[FindLocation(chr.location)].models.always.l6 == "ladder_rope")
				{
					//go up

					if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

					SetNextWeather("Clear");
	 				DeleteAttribute(chr, "quest.JRH_rain");				

					chr.quest.ch_shore_direction = "BH";		//BH or plantation
					DoQuestReloadToLocation("Charleston_shore", "goto", "box25", "pull_up_ladder_from_cavern");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladeladder2")) 
					{
						//place it at lower end of rope 

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							if(!IsEquipCharacterByItem(chr, "bladeladder2"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeladder2");
							}

							PlaySound("PEOPLE\wood1.wav");

							if(CheckAttribute(chr, "quest.ch_shore_ladder_needed") && chr.quest.ch_shore_ladder_needed == "yes")
							{
								Locations[FindLocation("Maroon_Cavern")].models.always.l6 = "ladder_rope";
							}
							else 
							{
								Locations[FindLocation("Maroon_Cavern")].models.always.l6 = "ladder_wall";
								Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box8 = 0.7;
								SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box8", 0.7);
							}

							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladeladder2");
							EquipCharacterByItem(chr, "bladeX4");
	
							LAi_QuestDelay("mar_cav_place_ladder_rope", 0.5);
						}
						else 
						{
							if(!IsEquipCharacterByItem(chr, "bladeladder2"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeladder2");
							}

							if(CheckAttribute(chr, "quest.ch_shore_ladder_needed") && chr.quest.ch_shore_ladder_needed == "yes")
							{
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");
								Logit(TranslateString("","Maybe if I tie the Ladder to the rope and pull it up from the top."));
							}
							else
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","No, I can never climb the rope carrying this Ladder."));
							}

							LAi_SetFightMode(chr, true);
							return;
						}
					}
					else
					{
						//go up

						if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

						SetNextWeather("Clear");
	 					DeleteAttribute(chr, "quest.JRH_rain");				

						chr.quest.ch_shore_direction = "BH";		//BH or plantation
						DoQuestReloadToLocation("Charleston_shore", "goto", "box25", "");
					}
				}
			break;

			case "box5":
				//EXIT TO PASSAGE

				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;				

				SetNextWeather("Clear");
	 			DeleteAttribute(chr, "quest.JRH_rain");

				chr.quest.box_blocked = "yes";
				DoQuestReloadToLocation("Charleston_passage", "reload", "reload1", "box_enabled");
			break;

			case "box6":
				//EXIT TO SHORE

				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;	

				if(CheckAttribute(chr, "quest.mar_cav_to_bridge") && chr.quest.mar_cav_to_bridge == "open")
				{
					SetNextWeather("Clear");
	 				DeleteAttribute(chr, "quest.JRH_rain");

					chr.quest.box_blocked = "yes";
					DoQuestReloadToLocation("Charleston_shore", "reload", "reload1", "box_enabled");
				}
				else PlaySound("INTERFACE\knock.wav");
			break;
//JRH flood blocks door
			case "box7":
				//EXIT TO HIDEOUT

				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

				if(CheckAttribute(chr, "quest.mar_cav_to_hideout") && chr.quest.mar_cav_to_hideout == "open")
				{
					if(Locations[FindLocation(chr.location)].models.always.locators == "cavernMedium_locators_GB_flooded")
					{
						//UNLOCKED BUT BLOCKED

						PlaySound("INTERFACE\knock.wav");
						Logit(TranslateString("","The door isn't locked but blocked."));

						if(IsOfficer(CharacterFromID("Edgar Allan Poe"))) 
						{ LAi_QuestDelay("Poe_obvious", 1.0); }
					}
					else
					{
						SetNextWeather("Clear");
	 					DeleteAttribute(chr, "quest.JRH_rain");	

						DoQuestReloadToLocation("Maroon_hideout", "goto", "box4", "officer_to_hideout");
					}
				}
				else PlaySound("INTERFACE\knock.wav");
			break;

			case "box8":
				//PICK UP LADDER_WALL

				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box'

					PlaySound("PEOPLE\wood1.wav");
					GiveItem2Character(chr, "bladeladder2");
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					EquipCharacterByItem(chr, "bladeladder2");
					Locations[FindLocation("Maroon_Cavern")].models.always.l6 = "";
					Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box8 = 0.0001;
					SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box8", 0.0001);
	
					LAi_QuestDelay("mar_cav_place_ladder_rope", 0.5);
				}
				else 
				{
					if(!IsEquipCharacterByItem(chr, "bladeX4"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeX4");
					}

					LAi_SetFightMode(chr, true);
					return;
				}
			break;

			case "box9":
				//PUSH BARREL A to B

				ChangeCharacterAddressGroup(chr, "Maroon_Cavern", "goto", "box9");
				
				if(CheckAttribute(chr, "quest.barrelA") && chr.quest.barrelA == "filled")
				{
					//TOO HEAVY

					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					Logit(TranslateString("","Not a chance - the Barrel is too heavy."));
					LAi_SetSitType(chr);

					LAi_QuestDelay("pchar_playertype", 1.0);
					LAi_QuestDelay("pchar_puh", 1.0);
				}
				else
				{
					//PUSH IT

					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					LAi_SetSitType(chr);
					Locations[FindLocation("Maroon_Cavern")].models.always.l5 = "barrelB";
					if(Locations[FindLocation("Maroon_Cavern")].models.always.l7 == "bottleA")
					{
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleB";
						chr.quest.tapB = "open";
					}
					if(Locations[FindLocation("Maroon_Cavern")].models.always.l7 == "bottleA_cork")
					{
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleB_cork";
						chr.quest.tapB = "closed";
					}

					LAi_QuestDelay("push_barrelA", 1.0);	
				}
			break;	

			case "box10":
				//PUSH BARREL B to C

				ChangeCharacterAddressGroup(chr, "Maroon_Cavern", "goto", "box10");
				
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
				Locations[FindLocation("Maroon_Cavern")].models.always.l5 = "barrelC";
				if(Locations[FindLocation("Maroon_Cavern")].models.always.l7 == "bottleB")
				{
					Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleC";
					chr.quest.tapC = "open";
				}
				if(Locations[FindLocation("Maroon_Cavern")].models.always.l7 == "bottleB_cork")
				{
					Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleC_cork";
					chr.quest.tapC = "closed";
				}

				LAi_QuestDelay("push_barrelB", 1.0);	
			break;	

			case "box11":
				//TAP A
				
				if(CheckAttribute(chr, "quest.tapA_activated") && chr.quest.tapA_activated == "yes") return;

				chr.quest.tapA_activated = "yes";
				ChangeCharacterAddressGroup(chr, "Maroon_Cavern", "goto", "box11");
				LAi_SetSitType(chr);		
				LAi_QuestDelay("pchar_playertype", 1.0);

				if(CheckAttribute(chr, "quest.tapA") && chr.quest.tapA == "closed")
				{
					if(CheckCharacterItem(chr,"corkscrew")) 
					{
						if(CheckAttribute(chr, "quest.barrelA") && chr.quest.barrelA == "filled")
						{
							PlaySound("INTERFACE\bottle_molasses.wav");
							Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleA";

							LAi_QuestDelay("open_barrelA", 3.5);
						}
						else 
						{
							PlaySound("AMBIENT\TAVERN\open_bottle.wav");
							Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleA";
						
							LAi_QuestDelay("open_barrelA", 1.0);
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","Hmm, I can't get the Cork out."));
						chr.quest.tapA_activated = "no";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"cork")) 
					{	
						PlaySound("INTERFACE\cancel.wav");
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleA_cork";

						LAi_QuestDelay("close_barrelA", 1.0);
					}
				}
			break;

			case "box12":
				//TAP C
				
				if(CheckAttribute(chr, "quest.tapC_activated") && chr.quest.tapC_activated == "yes") return;

				chr.quest.tapC_activated = "yes";
				ChangeCharacterAddressGroup(chr, "Maroon_Cavern", "goto", "box12");
				LAi_SetSitType(chr);		
				LAi_QuestDelay("pchar_playertype", 1.0);

				if(CheckAttribute(chr, "quest.tapC") && chr.quest.tapC == "closed")
				{
					if(CheckCharacterItem(chr,"corkscrew")) 
					{
						PlaySound("AMBIENT\TAVERN\open_bottle.wav");
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleC";
						
						LAi_QuestDelay("open_barrelC", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","Hmm, I can't get the Cork out."));
						chr.quest.tapC_activated = "no";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"cork")) 
					{	
						PlaySound("INTERFACE\cancel.wav");
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleC_cork";

						LAi_QuestDelay("close_barrelC", 1.0);
					}
				}
			break;

			case "box13":
				//TAP B
				
				if(CheckAttribute(chr, "quest.tapB_activated") && chr.quest.tapB_activated == "yes") return;

				chr.quest.tapB_activated = "yes";
				ChangeCharacterAddressGroup(chr, "Maroon_Cavern", "goto", "box13");
				LAi_SetSitType(chr);		
				LAi_QuestDelay("pchar_playertype", 1.0);

				if(CheckAttribute(chr, "quest.tapB") && chr.quest.tapB == "closed")
				{
					if(CheckCharacterItem(chr,"corkscrew")) 
					{
						PlaySound("AMBIENT\TAVERN\open_bottle.wav");
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleB";
						
						LAi_QuestDelay("open_barrelB", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","Hmm, I can't get the Cork out."));
						chr.quest.tapB_activated = "no";
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"cork")) 
					{	
						PlaySound("INTERFACE\cancel.wav");
						Locations[FindLocation("Maroon_Cavern")].models.always.l7 = "bottleB_cork";

						LAi_QuestDelay("close_barrelB", 1.0);
					}
				}
			break;	

			case "box14":
				//LADDER 
			
				if(Characters[GetCharacterIndex("maroon1")].Ship.Type == "obj_ladder2")
				{
					//FLOODED

					PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
					Logit(TranslateString("","The Ladder is stuck under the bridge now!"));
				}
				else
				{
					//DRY

					if(CheckAttribute(chr, "quest.cavern_ladder") && chr.quest.cavern_ladder == "free")
					{
						//TAKE IT

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							chr.quest.cavern_ladder = "picked_up";
							PlaySound("PEOPLE\wood1.wav");
							GiveItem2Character(chr, "bladeladder2");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeladder2");
							TakeItemFromCharacter(chr, "corkscrew");
							Locations[FindLocation("Maroon_Cavern")].models.always.l4 = "";		//ladder_bottom
							Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box14 = 0.0001;
							SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box14", 0.0001);
	
							LAi_QuestDelay("mar_cav_take_ladder_bottom", 0.5);
						}
						else 
						{
							if(!IsEquipCharacterByItem(chr, "bladeladderX4"))
							{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladeX4");
							}

							LAi_SetFightMode(chr, true);
							return;
						}
					}
					else
					{
						if(Locations[FindLocation("Maroon_Cavern")].models.always.l5 == "barrelA")
						{
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","The Ladder is stuck under the Barrel."));
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_huh.wav");
							Logit(TranslateString("","The Ladder is still stuck somehow! How do I lift it?"));
						}
					}
				}
			break;			
		}

		return;
	}

	if(Locations[locidx].id=="Charleston_shore")
	{
		switch(chr.boxname)
		{
		//......................................................................................
		//TO CLIFF AFTER BRIDGE

			case "box1":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look1");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box2":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look1");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box3":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look1");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.maroons_on_cliff") && chr.quest.maroons_on_cliff == "yes")
				{
					if(CheckAttribute(chr, "quest.maroons_on_cliff_turn") && chr.quest.maroons_on_cliff_turn == "done")
					{
						DoQuestReloadToLocation("Bishops_Hostel", "goto", "box13", "BH_turn_to_box20");
					}
					else
					{
						LAi_SetActorType(chr);
						LAi_ActorTurnToLocator(chr, "goto", "look1");

						LAi_QuestDelay("maroons_on_cliff_turn", 1.0);
					}
				}
				else DoQuestReloadToLocation("Bishops_Hostel", "goto", "box13", "BH_turn_to_box20");
			break;

			case "box5":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look1");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box6":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box4");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look1");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box7":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box1");
			break;

		//......................................................................................
		//TO RAFT

			case "box8":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box9");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box10");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box9":
				chr.quest.are_you_coming = "on";
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box10");
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box9");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box11");

				Locations[FindLocation("Charleston_shore")].locators_radius.box.box8 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box8", 0.0001);

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box10":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

				if(CheckAttribute(chr, "quest.are_you_coming") && chr.quest.are_you_coming == "on")
				{
					chr.quest.box_blocked = "yes";
					PlaySound("PEOPLE\step_ground.wav");
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "ships_other", "ships_2");

					LAi_QuestDelay("are_you_coming", 1.0);
				}
				
				if(CheckAttribute(chr, "quest.are_you_coming") && chr.quest.are_you_coming == "done")
				{
					PlaySound("PEOPLE\run_roof.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box11");
					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box10");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box12");

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
			break;

			case "box11":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box12");
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box11");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box13");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box12":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box13");
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box12");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box14");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box13":
				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box14");
				ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "goto", "box13");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "reload", "reload1_back");

				LAi_QuestDelay("pchar_staytype", 0.5);
				LAi_QuestDelay("Jup_shore", 1.5);
			break;
		
			case "box43":
				Characters[GetCharacterIndex("Charleston_guard2")].Ship.Type = "obj_raft2";
				
				DoQuestReloadToLocation("Bishops_Hostel", "goto", "box54", "raft_to_BH");
			break;
		
		//......................................................................................
		//TO SECOND RAFT

			case "box45":
				PlaySound("PEOPLE\creak2.wav");
				LAi_SetPoorType(chr);
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "box", "box46");

				LAi_QuestDelay("pchar_yah", 1.0);
				LAi_QuestDelay("raft_to_passage", 2.0);
			break;

		//......................................................................................
		//TO ROPE

			case "box15":
				chr.quest.ch_shore_direction = "plantation";		//BH or plantation
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "cliff1");

				LAi_QuestDelay("to_rope1", 1.0);	//was 0.5
			break;

			case "box26":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "cliff2");

				LAi_QuestDelay("to_rope2", 1.0);
			break;

			case "box27":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "cliff3");
				
				LAi_QuestDelay("to_rope3", 1.0);
			break;

		//......................................................................................
		//MOUNTAIN TOP

			case "box25":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					if(Locations[FindLocation("Maroon_cavern")].models.always.l6 == "ladder_rope")
					{
						if(CheckAttribute(chr, "quest.ch_shore_box25_sit") && chr.quest.ch_shore_box25_sit == "yes")
						{
							PlaySound("OBJECTS\DUEL\man_attack1.wav");
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr, "bladeladder2");			
							EquipCharacterByItem(chr, "bladeladder2");
							Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";
						
							LAi_QuestDelay("pchar_playertype", 1.0);
							LAi_QuestDelay("pchar_puh", 1.0);
						}
						else
						{
							LAi_SetSitType(chr);
							chr.quest.ch_shore_box25_sit = "yes";
						}
					}
					else
					{
						//continue

						if(CheckAttribute(chr, "quest.ch_shore_turn_to_box24") && chr.quest.ch_shore_turn_to_box24 == "yes")
						{
							PlaySound("PEOPLE\run_stone.wav");
							chr.quest.ch_shore_turn_to_box24 = "no";

							if(Locations[FindLocation("Charleston_shore")].models.always.l9 == "ladder_rope")
							{
								ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box19");
							}
							else ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box16");

							LAi_QuestDelay("ch_shore_turn_to_look_b18", 0.5);
						}
						else
						{
							LAi_SetActorType(chr);
							LAi_ActorTurnToLocator(chr, "goto", "look_b24");

							LAi_QuestDelay("pchar_playertype", 1.0);
							LAi_QuestDelay("ch_shore_turn_to_box24", 1.0);
						}
					}
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					SetNextWeather("Clear");
					chr.quest.JRH_rain = "clear";

					chr.quest.box_blocked = "yes";
					DoQuestReloadToLocation("Maroon_cavern", "reload", "reload2", "box_enabled");
				}		
			break;
		
			case "box16":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					if(Locations[FindLocation(chr.location)].models.always.l9 == "ladder_gibbet")
					{
						PlaySound("PEOPLE\creak.wav");
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box18");

						LAi_QuestDelay("ch_shore_turn_to_look_b18", 0.5);
					}
					else
					{
						if(CheckCharacterItem(chr,"bladeladder2")) 
						{
							if(LAi_IsFightMode(chr))
							{
								//this is your 2:nd 'open box'

								if(!IsEquipCharacterByItem(chr, "bladeladder2"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladeladder2");
								}

								PlaySound("PEOPLE\creak.wav");
								PlaySound("PEOPLE\wood1.wav");
								Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_gibbet";
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								TakeItemFromCharacter(chr, "bladeladder2");
								EquipCharacterByItem(chr, "bladeX4");
	
								LAi_QuestDelay("ch_shore_place_ladder_gibbet", 0.5);
							}
							else 
							{
								if(!IsEquipCharacterByItem(chr, "bladeladder2"))
								{
									RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									EquipCharacterByItem(chr, "bladeladder2");
								}

								LAi_SetFightMode(chr, true);
								return;
							}
						}
						else
						{
							if(CheckCharacterItem(chr,"gibbet_rope")) 
							{
								Logit(TranslateString("","I need a Ladder to place the Rope."));
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								chr.quest.ch_shore_ladder_needed = "yes";

								LAi_QuestDelay("ch_shore_turn_to_look_back_b16", 1.0);
							}
							else
							{
								Logit(TranslateString("","With a Rope I could get down from this cliff."));
								PlaySound("VOICE\ENGLISH\blaze_hah.wav");

								LAi_QuestDelay("ch_shore_turn_to_look_back_b16", 1.0);
							}
						}
					}
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box25");
				}
			break;

			case "box18":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					if(CheckCharacterItem(chr,"gibbet_rope")) 
					{
						//place it

						SetModel(Chr, "William Legrand", chr.model.animation, Chr.sex, stf(Chr.model.height), true);
						PlaySound("PEOPLE\clothes1.wav");
						TakeItemFromCharacter(chr, "gibbet_rope");
						Locations[FindLocation(chr.location)].models.always.l5 = "rope_gibbet";
							
						LAi_QuestDelay("ch_shore_place_rope_gibbet", 1.0);
					}
					else
					{
						Logit(TranslateString("","With a Rope I could get down from this cliff."));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							
						LAi_QuestDelay("ch_shore_return_to_hatch", 1.0);
					}
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{







				}
			break;
//JRH P.U. rope ladder
			case "box19":
				if(CheckAttribute(chr, "quest.box_action") && chr.quest.box_action == "yes") return;

				if(CheckAttribute(chr, "quest.ch_shore_resuse_ladder") && chr.quest.ch_shore_resuse_ladder == "yes")
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					LAi_SetSitType(chr);
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					GiveItem2Character(chr, "bladeladder2");			
					EquipCharacterByItem(chr, "bladeladder2");
					Locations[FindLocation("Charleston_shore")].models.always.l9 = "";
					chr.quest.ch_shore_direction = "plantation";	
					chr.quest.ch_shore_resuse_ladder = "no";
			//Locations[FindLocation("Maroon_Cavern")].locators_radius.box.box4 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box32 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box38 = 0.8;

					LAi_QuestDelay("pchar_playertype", 1.0);
					return;
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					if(Locations[FindLocation(chr.location)].models.always.l9 == "ladder_rope")
					{
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box20");
					}
					else
					{
						PlaySound("PEOPLE\clothes1.wav");
						LAi_SetSitType(chr);
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box42");
					}
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box25");
				}
			
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "get_ladder")
				{
					if(CheckCharacterItem(chr,"bladeladder2")) 
					{
						chr.quest.box_action = "yes";
						LAi_SetActorType(chr);
						LAi_ActorTurnToLocator(chr, "goto", "look_b18");
						Logit(TranslateString("","Yes, now I can extend the rope with the Ladder."));

						LAi_QuestDelay("ch_shore_place_ladder_rope", 2.0);
					}
					else
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						GiveItem2Character(chr, "bladeladder2");			
						EquipCharacterByItem(chr, "bladeladder2");
						Locations[FindLocation("Charleston_shore")].models.always.l9 = "";
						
						LAi_QuestDelay("ch_shore_take_ladder_gibbet", 0.5);
					}	
				}
			break;

			case "box42":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					PlaySound("PEOPLE\recoil.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box19");

					LAi_QuestDelay("pchar_playertype", 0.5);
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "get_ladder")
				{
					PlaySound("PEOPLE\recoil.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box19");

					LAi_QuestDelay("ch_shore_turn_to_box18", 0.5);
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					Logit(TranslateString("","The Rope isn't long enough - I'll brake my bones."));
					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
					chr.quest.ch_shore_direction = "get_ladder";
				}
			break;

			case "box20":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box41");
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					PlaySound("PEOPLE\recoil.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box19");

					LAi_QuestDelay("pchar_playertype", 0.5);
				}
			break;

			case "box41":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					PlaySound("PEOPLE\jump_stone.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box28");
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box20");
				}
			break;

			case "box28":
				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "BH")
				{
					PlaySound("PEOPLE\jump.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "goto1");

					if(CheckAttribute(chr, "quest.mar_cav_to_bridge") && chr.quest.mar_cav_to_bridge == "open")
					{
						if(IsOfficer(CharacterFromID("Jupiter")))				
						{
							for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
							RemovePassenger(chr, characterFromID("Jupiter"));

							ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Charleston_shore", "officers", "reload1_1");
							AddPassenger(chr, characterFromID("Jupiter"), 0);
							SetOfficersIndex(chr, 1, getCharacterIndex("Jupiter"));
							LAi_SetOfficerType(characterFromID("Jupiter"));
						}
					}

					LAi_QuestDelay("Pchar_playertype", 0.5);
				}

				if(CheckAttribute(chr, "quest.ch_shore_direction") && chr.quest.ch_shore_direction == "plantation")
				{
					if(Locations[FindLocation(chr.location)].models.always.l9 == "ladder_rope")
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box41");
					}
					else
					{
						PlaySound("PEOPLE\jump.wav");
						LAi_SetSitType(chr);
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "goto1");

						

						LAi_QuestDelay("Pchar_playertype", 0.5);
					}
				}
			break;
		//......................................................................................
		//REMOVE PLANKS FROM CAVE DOOR

			case "box29":
				if(CheckCharacterItem(chr,"bladelever")) 
				{
					if(!IsEquipCharacterByItem(chr, "bladelever"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladelever");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("PEOPLE\creak.wav");
	
						LAi_QuestDelay("ready_to_remove_cave_planks", 1.0);
					}
					else
					{
						LAi_SetFightMode(chr, true);

						return;
					}
				}
				else
				{
					Logit(TranslateString("","I can't remove that plank with my bare hands."));
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
				}
			break;
		
		//......................................................................................
		//TO MAROON_CAVERN

			case "box40":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

				SetNextWeather("Clear");
				chr.quest.JRH_rain = "clear";

				chr.quest.box_blocked = "yes";
				DoQuestReloadToLocation("Maroon_cavern", "reload", "reload3", "box_enabled");
			break;

		//......................................................................................
		//PLACE PLANKS ON BROKEN BRIDGE

			case "box30":
				if(CheckCharacterItem(chr,"bladeplank2")) 
				{
					LAi_SetPlayerType(chr);

					if(!IsEquipCharacterByItem(chr, "bladeplank2"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeplank2");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("PEOPLE\place_planks.wav");
						PlaySound("PEOPLE\wood1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladeplank2");
						EquipCharacterByItem(chr, "bladeX4");
						Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
						Locations[FindLocation("Charleston_shore")].locators_radius.box.box30 = 0.0001;
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box30", 0.0001);
				
						Locations[FindLocation("Charleston_shore")].image = "";
						DoQuestReloadToLocation("Charleston_shore", "reload", "reload2", "ch_shore_loading_image_back");
					}
					else
					{
						LAi_SetFightMode(chr, true);

						return;
					}
				}
			break;

			case "box31":
				if(CheckCharacterItem(chr,"bladeplank2")) 
				{
					LAi_SetPlayerType(chr);

					if(!IsEquipCharacterByItem(chr, "bladeplank2"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeplank2");
					}

					if(LAi_IsFightMode(chr))
					{
						//this is your 2:nd 'open box'

						PlaySound("PEOPLE\place_planks.wav");
						PlaySound("PEOPLE\wood1.wav");
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						TakeItemFromCharacter(chr, "bladeplank2");
						EquipCharacterByItem(chr, "bladeX4");
						Locations[FindLocation("Charleston_shore")].models.always.l7 = "plank2B";
						Locations[FindLocation("Charleston_shore")].locators_radius.box.box31 = 0.0001;
						SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box31", 0.0001);

						Locations[FindLocation("Charleston_shore")].image = "";
						DoQuestReloadToLocation("Charleston_shore", "reload", "reload3", "ch_shore_loading_image_back");
					}
					else
					{
						LAi_SetFightMode(chr, true);

						return;
					}
				}
			break;

		//......................................................................................
		//PICK UP PLANK FROM BRIDGE

			case "box39":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\place_planks.wav");
				PlaySound("PEOPLE\wood1.wav");
				GiveItem2Character(chr, "bladeplank2");
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladeplank2");

				LAi_QuestDelay("ch_shore_pick_up_plank2B", 0.5);
			break;

		//......................................................................................
		//PICK UP PLANK FROM GROUND AT GATE

			case "box17":
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\place_planks.wav");
				PlaySound("PEOPLE\wood1.wav");
				GiveItem2Character(chr, "bladeplank2");
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladeplank2");

				LAi_QuestDelay("ch_shore_pick_up_plank_ground", 0.5);
			break;

		//......................................................................................
		//PLACE LADDER AT LEVER

			case "box38":
				if(LAi_IsFightMode(chr))
				{
					//this is your 2:nd 'open box'

					if(!IsEquipCharacterByItem(chr, "bladeladder2"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeladder2");
					}

					PlaySound("PEOPLE\creak.wav");
					PlaySound("PEOPLE\wood1.wav");
					Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_lever";
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(chr, "bladeladder2");
					EquipCharacterByItem(chr, "bladeX4");
	
					LAi_QuestDelay("ch_shore_place_ladder_lever", 0.5);
				}
				else
				{
					if(!IsEquipCharacterByItem(chr, "bladeladder2"))
					{
						RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
						EquipCharacterByItem(chr, "bladeladder2");
					}

					LAi_SetFightMode(chr, true);

					return;
				}
			break;

		//......................................................................................
		//TO LEVER VIA LADDER

			case "box32":
				if(Locations[FindLocation(chr.location)].models.always.l10 == "wood_step1")
				{
					PlaySound("OBJECTS\DUEL\man_attack1.wav");
					PlaySound("PEOPLE\step_stairway2.wav");
					LAi_SetSitType(chr);
					ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box36");

					LAi_QuestDelay("Pchar_playertype", 0.3);
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l9 == "ladder_lever")
					{
						PlaySound("PEOPLE\creak2.wav");
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box33");
					}
				}
				else
				{
					if(CheckAttribute(chr, "quest.ch_shore_resuse_ladder") && chr.quest.ch_shore_resuse_ladder == "yes")
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					}
					else
					{
						LAi_SetActorType(chr);	
						characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "wood_steps_are_gone";
						LAi_ActorSelfDialog(chr, "");
					}
				}				
			break;

			case "box33":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box34");
			break;

			case "box34":
				if(Locations[FindLocation(chr.location)].models.always.l8 == "" || Locations[FindLocation(chr.location)].models.always.l8 == "lever_ground")
				{			
					if(CheckCharacterItem(chr,"bladelever")) 
					{
						//place it
			
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							PlaySound("INTERFACE\lever_placed.wav");
							Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_up";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladelever");
							EquipCharacterByItem(chr, "bladeX4");
	
							LAi_QuestDelay("ch_shore_place_lever_box34", 0.5);
						}
						else
						{
							LAi_SetFightMode(chr, true);

							return;
						}
					}
					else
					{
						//go down
			
						Logit(TranslateString("","No, the Lever is missing."));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");

						LAi_QuestDelay("ch_shore_lever_missing", 1.0);
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l8 == "lever_up")
					{
						//lever down!
			
						PlaySound("INTERFACE\lever_down.wav");
						Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_down";
						Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_up";
						if(Locations[FindLocation("Charleston_shore")].models.always.l7 == "plank_gate")
						{
							Locations[FindLocation("Charleston_shore")].models.always.l7 = "plank_ground";
							Locations[FindLocation("Charleston_shore")].locators_radius.box.box17 = 0.5;
							SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box17", 0.5);
						}

						LAi_QuestDelay("ch_shore_lever_down_box34", 0.5);			
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l8 == "lever_down")
					{
						//jump down!
		
						PlaySound("PEOPLE\jump.wav");
						LAi_SetSitType(chr);
						ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box32");

						LAi_QuestDelay("Pchar_playertype", 0.5);			
					}
				}
			break;

		//......................................................................................
		//TO LEVER VIA WOOD STEPS

			case "box36":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				PlaySound("PEOPLE\step_stairway2.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Charleston_shore", "goto", "box37");

				LAi_QuestDelay("Pchar_playertype", 0.3);
			break;

			case "box37":
				if(Locations[FindLocation(chr.location)].models.always.l8 == "" || Locations[FindLocation(chr.location)].models.always.l8 == "lever_ground")
				{			
					if(CheckCharacterItem(chr,"bladelever")) 
					{
						//place it

						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladelever");
						}

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'

							PlaySound("INTERFACE\lever_placed.wav");
							Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_up";
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							TakeItemFromCharacter(chr, "bladelever");
							EquipCharacterByItem(chr, "bladeX4");
	
							LAi_QuestDelay("ch_shore_place_lever_box37", 0.5);
						}
						else
						{
							LAi_SetFightMode(chr, true);

							return;
						}
					}
					else
					{
						//go down

						Logit(TranslateString("","No, the Lever is missing."));
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");

						LAi_QuestDelay("ch_shore_lever_missing", 1.0);
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l8 == "lever_up")
					{
						//lever down!

						PlaySound("INTERFACE\lever_down.wav");
						Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_down";
						Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_up";
						Locations[FindLocation("Charleston_shore")].locators_radius.goto.falling_lever = 1.0;
						SetLocatorRadius(locations[FindLocation(chr.location)], "goto", "falling_lever", 1.0);
						if(Locations[FindLocation("Charleston_shore")].models.always.l7 == "plank_gate")
						{
							Locations[FindLocation("Charleston_shore")].models.always.l7 = "plank_ground";
							Locations[FindLocation("Charleston_shore")].locators_radius.box.box17 = 0.5;
							SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box17", 0.5);
						}

						LAi_QuestDelay("ch_shore_lever_down_box37", 0.5);			
					}
				}
				else
				{
					if(Locations[FindLocation(chr.location)].models.always.l8 == "lever_down")
					{
						//lever up!

						PlaySound("INTERFACE\lever_up.wav");
						Locations[FindLocation("Charleston_shore")].models.always.l8 = "lever_up";
						Locations[FindLocation("Charleston_shore")].models.always.l4 = "bars_down";			
						Locations[FindLocation("Charleston_shore")].locators_radius.goto.falling_lever = 0.001;
						SetLocatorRadius(locations[FindLocation(chr.location)], "goto", "falling_lever", 0.001);

						LAi_QuestDelay("ch_shore_lever_up_box37", 0.5);
			
					}
				}
			break;

		//......................................................................................
		//PICK UP LEVER FROM GROUND

			case "box35":
				PlaySound("INTERFACE\button1.wav");
				GiveItem2Character(chr, "bladelever");
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				EquipCharacterByItem(chr, "bladelever");
				Locations[FindLocation("Charleston_shore")].locators_radius.box.box35 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box35", 0.0001);
				Locations[FindLocation("Charleston_shore")].models.always.l8 = "";		//no visible lever anywhere

				LAi_QuestDelay("lever_from_ground", 0.5);
			break;

		}

		return;
	}

	if(Locations[locidx].id=="Bishops_Hostel")
	{
		switch(chr.boxname)
		{

		//BACK TO CHARLESTON SHORE

			case "box20":
				if(CheckAttribute(chr, "BH_last_time") && chr.BH_last_time == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","No idea go that way now."));
					return;
				}
				else
				{
					if(CheckAttribute(chr, "quest.maroons_on_cliff") && chr.quest.maroons_on_cliff == "yes")
					{
						DoQuestReloadToLocation("Charleston_shore", "goto", "box4", "pass_turn_to_box1");
					}
					else DoQuestReloadToLocation("Charleston_shore", "goto", "box7", "pass_turn_to_box1");
				}
			break;

		//WITH RAFT
			case "box54":
				chr.quest.BH_raft_to_hideout = "blocked";
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box55");
				LAi_SetPoorType(chr);

				LAi_SetActorType(characterFromID("Jupiter"));
				LAi_ActorGoToLocator(characterFromID("Jupiter"), "goto", "near_raft", "", 4.0);
				if(!IsEquipCharacterByItem(characterFromID("Jupiter"), "bladeboom"))
				{EquipCharacterByItem(characterFromID("Jupiter"), "bladeboom");}
			break;

			case "box55":
				if(CheckAttribute(chr, "quest.BH_raft_to_hideout") && chr.quest.BH_raft_to_hideout == "blocked")
				{
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bishops_hostel", "goto", "Jupiter_raft");
					LAi_SetPoorType(characterFromID("Jupiter"));
					chr.quest.BH_raft_to_hideout = "open";

					LAi_QuestDelay("pchar_lets_go", 1.0);
				}
				else
				{
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box1 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box2 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box3 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box4 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box5 = 0.0001;
					Locations[FindLocation("Charleston_shore")].locators_radius.box.box6 = 0.0001;

					LAi_SetPoorType(characterFromID("maroon1"));
					LAi_SetPoorType(characterFromID("maroon2"));
					LAi_SetPoorType(characterFromID("maroon3"));
					LAi_SetPoorType(characterFromID("maroon5"));
					LAi_SetPoorType(characterFromID("deserter_us1"));
					LAi_SetPoorType(characterFromID("indian_bandit"));
					
					Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB10";
					DoQuestReloadToLocation("Charleston_shore", "goto", "box44", "raft_to_lagoon");
				}
			break;
//JRH
		//SACKS TO BOAT
			case "box59":
				if(CheckAttribute(chr, "treasure_tour"))
				{
					if(chr.treasure_tour == "none") 
					{
						PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
						Logit(TranslateString("","We have to get the rest of the Treasure first."));
						return;
					}
				
					if(chr.treasure_tour == "1") 
					{
						chr.treasure_tour = "none";
						chr.treasure_chest = "prepare2";
						PlaySound("PEOPLE\clothes1.wav");
						SetModel(chr, "William Legrand2", chr.model.animation, chr.sex, stf(chr.model.height), true);
						SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe", "man", "man", 1.8, true);
						SetModel(characterFromID("Jupiter"), "Jupiter", "man", "man", 1.8, true);
						TakeItemFromCharacter(chr, "treasuresack");
						TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "treasuresack");
						TakeItemFromCharacter(characterFromID("Jupiter"), "treasuresack");
						Characters[GetCharacterIndex("deserter_us1")].Ship.Type = "obj_sacks1";

						LAi_QuestDelay("treasure_tour1_done", 1.0);
					}

					if(chr.treasure_tour == "2") 
					{
						chr.treasure_tour = "none";
						chr.treasure_chest = "prepare3";
						PlaySound("PEOPLE\clothes1.wav");
						SetModel(chr, "William Legrand2", chr.model.animation, chr.sex, stf(chr.model.height), true);
						SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe", "man", "man", 1.8, true);
						SetModel(characterFromID("Jupiter"), "Jupiter", "man", "man", 1.8, true);
						TakeItemFromCharacter(chr, "treasuresack");
						TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "treasuresack");
						TakeItemFromCharacter(characterFromID("Jupiter"), "treasuresack");
						Characters[GetCharacterIndex("white_trash1")].Ship.Type = "obj_sacks2";

						LAi_QuestDelay("treasure_tour2_done", 1.0);
					}

					if(chr.treasure_tour == "3") 
					{
						chr.treasure_tour = "none";
						PlaySound("PEOPLE\clothes1.wav");
						SetModel(chr, "William Legrand2", chr.model.animation, chr.sex, stf(chr.model.height), true);
						SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe", "man", "man", 1.8, true);
						TakeItemFromCharacter(chr, "treasuresack");
						TakeItemFromCharacter(characterFromID("Edgar Allan Poe"), "treasuresack");
						TakeItemFromCharacter(characterFromID("Jupiter"), "treasurechest_red");
						EquipCharacterByItem(characterFromID("Jupiter"), "bladeX4");
						Characters[GetCharacterIndex("indian_bandit")].Ship.Type = "obj_sacks3";
						Characters[GetCharacterIndex("maroon_girl")].Ship.Type = "obj_treasurechest";	

						LAi_QuestDelay("treasure_tour3_done", 1.0);
					}

					if(chr.treasure_tour == "boat") 
					{
						PlaySound("OBJECTS\DUEL\man_attack1.wav");
						PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
						LAi_SetActorType(chr);
						LAi_ActorAnimation(chr, "jump", "pchar_playertype", 1.8);

						LAi_QuestDelay("treasure_boat_leave", 0.5);
					}
				}
			break;

		//WITH BOAT & RAFT
			case "box58":
				chr.treasure_tour = "sail_away";
				Locations[FindLocation("Legrands_boathouse")].models.always.locators = "Shore07_l_GB2";
				Locations[FindLocation("Legrands_boathouse")].type = "silent_seashore";
				chr.quest.boathouse = "return";
				Characters[GetCharacterIndex("Moultrie_guard3")].Ship.Type = "obj_boat4S";		//at boathouse
				Characters[GetCharacterIndex("mystery_monk")].Ship.Type = "obj_sacks1";			//at boathouse
			//	Characters[GetCharacterIndex("box_ghost")].Ship.Type = "invisible";			//at boathouse		
				Characters[GetCharacterIndex("gate_ghost")].Ship.Type = "obj_sacks3";			//at boathouse
				Characters[GetCharacterIndex("zombie1")].Ship.Type = "obj_raft3";			//at boathouse
				Characters[GetCharacterIndex("zombie2")].Ship.Type = "obj_treasurechest";		//at boathouse

				if(CheckAttribute(chr, "treasure_tour") && chr.treasure_tour == "sail_away")
				{ 
					DoQuestReloadToLocation("Legrands_boathouse", "box", "box5", "final_battle");
				}
			break;

		//........................................................................................

			case "box13":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box20");
			break;

		//........................................................................................
		//LEFT WAY UP (DEAD END)	
			
			case "box3":
				if(CheckAttribute(chr, "BH_last_time") && chr.BH_last_time == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","No idea go that way now."));
					return;
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box4");
				}
			break;

			case "box4":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					chr.quest.BH_left_way = "up";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box3");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box5");
				}
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box4");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "box", "box3");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box6");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box7");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;
		
			case "box6":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box5");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box4");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box7");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box8");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;
		
			case "box7":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box6");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box5");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box8");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box9");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;

			case "box8":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box7");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box6");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box9");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box10");

					LAi_QuestDelay("BH_turn_to_box10", 1.0);
				}
			break;

			case "box9":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box8");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box10");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box11");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;

			case "box10":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box9");
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box11");

					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "look4");

					LAi_QuestDelay("BH_too_steep", 1.0);
				}
			break;

			case "box11":
				if(CheckAttribute(chr, "quest.BH_left_way") && chr.quest.BH_left_way == "down")
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box10");
				}
				else
				{
					chr.quest.BH_left_way = "down";
					LAi_SetActorType(chr);
					LAi_ActorTurnToLocator(chr, "goto", "box10");

					LAi_QuestDelay("pchar_playertype", 1.0);
				}
			break;


		//........................................................................................
		//RIGHT WAY UP

			case "box1":
				if(CheckAttribute(chr, "BH_last_time") && chr.BH_last_time == "yes")
				{
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Logit(TranslateString("","No idea go that way now."));
					return;
				}
				else
				{
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box38");
				}
			break;
			
			case "box38":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box12");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box43");
			break;

			case "box12":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box39");
			break;

			case "box39":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box40");
			break;

			case "box40":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box41");
			break;

			case "box41":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box42");
			break;

			case "box42":
				PlaySound("PEOPLE\step_stairway2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box19");
			break;

			case "box19":
				PlaySound("PEOPLE\step_stairway2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box18");
			break;

			case "box18":
				PlaySound("PEOPLE\step_stairway2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box17");
			break;

			case "box17":
				PlaySound("PEOPLE\clothes1.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box45");

				LAi_QuestDelay("pchar_playertype", 0.5);
				LAi_QuestDelay("pchar_puh", 0.5);
			break;

			case "box45":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box21");
			break;

			case "box21":
				PlaySound("PEOPLE\step_stairway.wav");
				LAi_SetSitType(chr);
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box43");

				LAi_QuestDelay("pchar_playertype", 0.5);
			break;

			case "box43":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box44");
			break;

			case "box44":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box22");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box23");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;	

			case "box22":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box23");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box24");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;

			case "box23":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box24");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box25");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;

			case "box24":
				PlaySound("PEOPLE\recoil.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box25");
			break;

			case "box25":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box28");
			break;
		
			case "box28":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box30");
			break;
		
			case "box30":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box32");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box33");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;
		
			case "box32":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box34");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "box35");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;
		
			case "box34":
				PlaySound("PEOPLE\run_stone.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "box36");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "box", "box37");

				LAi_QuestDelay("pchar_playertype", 1.0);
			break;
		
			case "box36":
				PlaySound("PEOPLE\jump.wav");
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box37");

				LAi_QuestDelay("devils_turn_to_tree", 0.1);
			break;

		//........................................................................................
		//DEVILS SEAT

			case "box37":
				if(CheckAttribute(chr, "quest.devils_seat") && chr.quest.devils_seat == "go_down")
				{
					chr.quest.devils_seat = "neutral";
					PlaySound("PEOPLE\step_stairway2.wav");
					ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "armrest");

					LAi_QuestDelay("devils_seat_go_down", 0.5);
					return;
				}

				if(IsEquipCharacterByItem(chr, "bladespyglass6"))
				{
					if(IsEquipCharacterByItem(chr, "pistolsextant2") && IsEquipCharacterByItem(chr, "bagcompass4"))
					{
						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);
						Locations[FindLocation("Bishops_Hostel")].MaxSeaHeight = 0.1;

						LAi_QuestDelay("tree_zoom", 1.0);
					}
					else
					{
						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("green_zoom", 1.0);
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladespyglass6")) 
					{
						LAi_QuestDelay("no_zoom", 0.1);
					}
					else
					{
						LAi_QuestDelay("no_spyglass", 0.1);
					}
				}
			break;

		//........................................................................................
		//WAY DOWN

			case "box14":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box15");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look5");

				LAi_QuestDelay("pchar_playertype", 1.0);
				LAi_QuestDelay("pchar_ohoh", 1.0);
			break;

			case "box15":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box50");

				LAi_SetActorType(chr);
				LAi_ActorTurnToLocator(chr, "goto", "look6");
				
				LAi_QuestDelay("pchar_playertype", 1.0);
				LAi_QuestDelay("pchar_oooh", 1.0);
			break;

			case "box50":
				PlaySound("PEOPLE\run_wood.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box16");
			break;

			case "box16":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box49");
				LAi_SetSitType(chr);
			break;

			case "box49":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box46");
			break;

			case "box46":
				PlaySound("PEOPLE\creak2.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box47");
			break;

			case "box47":
				chr.quest.box_blocked = "yes";

				PlaySound("PEOPLE\jump.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "box", "box48");
				LAi_SetLayType(chr);

				LAi_QuestDelay("Pchar_oh", 1.0);
				LAi_QuestDelay("Pchar_poortype", 1.0);
				LAi_QuestDelay("BH_turn_to_ground", 2.0);
			break;

			case "box48":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;

				PlaySound("PEOPLE\run_roof.wav");
				ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "ground");
			break;

		//........................................................................................
		//TREASURE
//JRH
			case "box56":
				Locations[FindLocation("Bishops_Hostel")].models.always.l5= "stake1A";
				Locations[FindLocation("Bishops_Hostel")].models.always.l9= "";
				locations[FindLocation("Bishops_Hostel")].models.always.l10 = "";			
				Locations[FindLocation("Bishops_Hostel")].locators_radius.box.box56 = 0.001;
				Locations[FindLocation("Bishops_Hostel")].image = "";
				DoQuestReloadToLocation("Bishops_Hostel", "goto", "L_bug", "stake1A");				
			break;

			case "box57":
				if(CheckAttribute(chr, "quest.box_blocked") && chr.quest.box_blocked == "yes") return;
				
				if(CheckAttribute(chr, "treasure_spot"))
				{
					if(chr.treasure_spot == "2_skeletons")
					{
						chr.quest.box_blocked = "yes";
						ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "L_skel1_start");
						ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_Hostel", "goto", "P_skel1_start");

						LAi_QuestDelay("move_skeleton1", 1.0);
					} 
					if(chr.treasure_spot == "1_skeleton")
					{
						chr.quest.box_blocked = "yes";
						ChangeCharacterAddressGroup(chr, "Bishops_Hostel", "goto", "L_skel1_start");
						ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Bishops_Hostel", "goto", "P_skel1_start");

						LAi_QuestDelay("move_skeleton2", 1.0);
					} 
					if(chr.treasure_spot == "cutlass") 
					{
						chr.quest.box_blocked = "yes";
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
						Logit(TranslateString("","What is it - an old Cutlass?"));
						LAi_SetActorType(chr);
						LAi_ActorTurnToLocator(chr, "officers", "L_hole2_2");

						LAi_QuestDelay("enable_dig_up_metal", 2.0);
					}
					if(chr.treasure_spot == "metal") 
					{
						chr.quest.box_blocked = "yes";
						LAi_SetPlayerType(chr);
						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("dig_sand", 1.0);
						LAi_QuestDelay("dig_sand", 2.0);
						LAi_QuestDelay("dig_sand", 3.0);
						LAi_QuestDelay("Legrand_digs3", 1.0);
						LAi_QuestDelay("Legrand_digs3", 2.0);
						LAi_QuestDelay("Legrand_digs3", 2.0);
						LAi_QuestDelay("Legrand_digs3", 3.0);
						LAi_QuestDelay("Legrand_digs3", 3.0);
						LAi_QuestDelay("Legrand_digs3", 3.0);
						LAi_QuestDelay("dig_up_chest", 4.0);
					}
					if(chr.treasure_spot == "locked_chest") 
					{
						chr.quest.box_blocked = "yes";
						PlaySound("INTERFACE\locked_window.wav");
						
						LAi_QuestDelay("Poe_unlocks_chest", 2.0);
					}
					if(chr.treasure_spot == "open_chest") 
					{
						LaunchItemsBox(&ar);

						if(CheckAttribute(chr, "opened_once") && chr.opened_once == "no")
						{
							chr.opened_once = "yes"

							LAi_QuestDelay("sacks_from_Jupiter", 1.0);
						}
					}
				}			
			break;

		}

		return;
	}
    //<-- GoldBug
    }
	virtual_box = true;	//JRH
	OpenBoxProcedure();
}



//JRH
//from Loginterface.c
void CreateLandActionsEnvironment_BUG()
{
//Logit("4444");

	ref PChar = GetMainCharacter();		//JRH

//JRH -->

	if( CheckAttribute(Pchar,"boxname") )
	{
	//	IActions.ActiveActions.OpenBox.IconNum					 	= 29;

		//GoldBug -->

		if(Pchar.location == "Sullivan_shore1")
			{
				if(Pchar.boxname == "box4" || Pchar.boxname == "box6") 
				{
					IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
				else
				{
					if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Sullivan_shore2") IActions.ActiveActions.OpenBox.IconNum    = 63;

			if(Pchar.location == "Sullivan_shore3") IActions.ActiveActions.OpenBox.IconNum    = 63;
 
			if(Pchar.location == "Legrands_house")
			{
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 6;

				if(Pchar.boxname == "box4")
				{
					if(CheckAttribute(Pchar, "quest.backyard") && Pchar.quest.backyard == "closed")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 1;
				}

				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 62;
				if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 2;
			}

			if(Pchar.location == "Legrands_kitchen")
			{
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 59;
				if(Pchar.boxname == "box4" || Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum	= 63;
			}

			if(Pchar.location == "Legrands_grot")
			{
				if(Pchar.boxname == "box3" || Pchar.boxname == "box5" 
				|| Pchar.boxname == "box6" || Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum    = 2;

				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 10;
				if(Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 56;
				if(Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum   = 62;
			}

			if(Pchar.location == "Sullivan_jungle1") 
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box10")
				{
					if(CheckAttribute(Pchar, "quest.facade_box10") && Pchar.quest.facade_box10 == "free")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum	= 63;	
				}
				if(Pchar.boxname == "box11")
				{
					if(CheckAttribute(Pchar, "quest.facade_box11") && Pchar.quest.facade_box11 == "free")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum	= 63;	
				}
				if(Pchar.boxname == "box12" || Pchar.boxname == "box13" 
				|| Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum	= 63;	
			}

			if(Pchar.location == "Sullivan_jungle2") 
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 3;
			}
			
			if(Pchar.location == "Legrands_boathouse") 
			{
				if(Pchar.boxname == "box5") 
				{
					if(CheckAttribute(Pchar, "quest.boathouse") && Pchar.quest.boathouse == "return")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 5;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Legrands_backyard") 
			{
				if(Pchar.boxname == "box2") 
				{
					if(CheckAttribute(Pchar, "quest.go_to_well") && Pchar.quest.go_to_well == "phase7")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else
					{
						if(CheckAttribute(Pchar, "quest.go_to_attic") && Pchar.quest.go_to_attic == "phase2")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 1;
						}
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}

				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;

				if(Pchar.boxname == "box4") 
				{
					if(CheckAttribute(Pchar, "quest.go_to_well") && Pchar.quest.go_to_well == "phase7")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 2;
				}

				if(Pchar.boxname == "box5" || Pchar.boxname == "box6" || Pchar.boxname == "box7") 
				{
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			
				if(Pchar.boxname == "box8")
				{ 
					if(CheckAttribute(Pchar, "quest.go_to_attic") && Pchar.quest.go_to_attic == "phase1")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.location == "Legrands_attic") 
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box3" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
				|| Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10"
				|| Pchar.boxname == "box11" || Pchar.boxname == "box12" || Pchar.boxname == "box13") 
					IActions.ActiveActions.OpenBox.IconNum    = 2;
			}

			if(Pchar.location == "Fort_Moultrie_exit") IActions.ActiveActions.OpenBox.IconNum    = 63;
			if(Pchar.location == "fake_Fort_Moultrie_exit") IActions.ActiveActions.OpenBox.IconNum    = 63;
		
			if(Pchar.location == "Moultrie_hotel")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box3" || Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Moultrie_restaurant")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 2;
			}

			if(Pchar.location == "Moultrie_restaurant_kitchen")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;
			}

			if(Pchar.location == "Moultrie_store")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box11") 
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum    = 7;
				if(Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10"
				|| Pchar.boxname == "box13") 
					IActions.ActiveActions.OpenBox.IconNum    = 6;
			}

			if(Pchar.location == "Moultrie_store_room")
			{
				if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box7") 
					IActions.ActiveActions.OpenBox.IconNum    = 6;
				if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 62;

			}

			if(Pchar.location == "Fort_Moultrie")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box39")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else
				{
					if(Pchar.boxname == "box36" || Pchar.boxname == "box37" || Pchar.boxname == "box38") 
						IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				else
				{
					if(Pchar.boxname == "box35") 
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_flag_pos") && Pchar.quest.Fort_M_flag_pos == "up")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
				}
				else
				{
					if(Pchar.boxname == "box16")
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_south_wall") && Pchar.quest.Fort_M_south_wall == "left")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
						else
						{
							if(CheckAttribute(Pchar, "quest.Fort_M_south_wall_right") && Pchar.quest.Fort_M_south_wall_right == "open")
							{
								IActions.ActiveActions.OpenBox.IconNum    = 1;
							}
							else IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
					}
				}
				else
				{
					if(Pchar.boxname == "box11")
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_south_wall") && Pchar.quest.Fort_M_south_wall == "right")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
						else
						{
							if(CheckAttribute(Pchar, "quest.Fort_M_south_wall_left") && Pchar.quest.Fort_M_south_wall_left == "open")
							{
								IActions.ActiveActions.OpenBox.IconNum    = 1;
							}
							else IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
					}
				}
				else
				{
					if(Pchar.boxname == "box17")
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_gate_wall") && Pchar.quest.Fort_M_gate_wall == "right")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
						else
						{
							if(CheckAttribute(Pchar, "quest.fort_box17") && Pchar.quest.fort_box17 == "open")
							{
								IActions.ActiveActions.OpenBox.IconNum    = 1;
							}
							else
							{
								if(CheckCharacterItem(Pchar,"key31"))
								{
									IActions.ActiveActions.OpenBox.IconNum    = 2;
								}
								else IActions.ActiveActions.OpenBox.IconNum    = 0;
							}
						}
					}
				}
				else
				{
					if(Pchar.boxname == "box12")
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_gate_wall") && Pchar.quest.Fort_M_gate_wall == "right")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 1;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
				}
				else
				{
					if(Pchar.boxname == "box41")
					{
						if(CheckAttribute(Pchar, "quest.Fort_M_ladder_wall") && Pchar.quest.Fort_M_ladder_wall == "right")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
				}
				else
				{
					if(Pchar.boxname == "box18")
					{
						if(CheckCharacterItem(Pchar,"bladeladder2"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "lieutenant_G_bedroom")
			{
				if(Pchar.boxname == "box2")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}

			if(Pchar.location == "Fort_M_tower2B")
			{
				if(Pchar.boxname == "box1")
				{
					if(CheckAttribute(Pchar, "quest.Fort_M_south_wall_right") && Pchar.quest.Fort_M_south_wall_right == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}

			if(Pchar.location == "Fort_M_tower3B")
			{
				if(Pchar.boxname == "box1")
				{
					if(CheckAttribute(Pchar, "quest.Fort_M_south_wall_left") && Pchar.quest.Fort_M_south_wall_left == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
			}

			if(Pchar.location == "Fort_M_tower4B")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.location == "Fort_Moultrie_prison")
			{
				if(Pchar.boxname == "box2")
				{
					if(CheckAttribute(Pchar, "cell2") && Pchar.cell2 == "locked")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				if(Pchar.boxname == "box6")
				{
					if(CheckAttribute(Pchar, "cell6") && Pchar.cell6 == "locked")
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
				if(Pchar.boxname == "box5")
				{
					if(CheckAttribute(Pchar, "cell5") && Pchar.cell5 == "locked")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				if(Pchar.boxname == "box4")
				{
					if(CheckAttribute(Pchar, "cell4") && Pchar.cell4 == "locked")
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
				if(Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10"
				|| Pchar.boxname == "box11" || Pchar.boxname == "box12" || Pchar.boxname == "box13") 
					IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.location == "Fort_Moultrie_gunpowder")
			{
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 7;
			}

			if(Pchar.location == "Fort_Moultrie_armory")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box5" || Pchar.boxname == "box9") 
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box4" || Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 6;
				if(Pchar.boxname == "box7" || Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Fort_Moultrie_shore") 
			{
				if(Pchar.boxname == "box4")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 25;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "GB_Charleston_port")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 25;
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 53;
				if(Pchar.boxname == "box3" || Pchar.boxname == "box5" || Pchar.boxname == "box7" 
				|| Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10"
				|| Pchar.boxname == "box13" || Pchar.boxname == "box14") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box4" || Pchar.boxname == "box6" || Pchar.boxname == "box11"
				|| Pchar.boxname == "box12") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_town")
			{
				
				if(Pchar.boxname == "box7" || Pchar.boxname == "box13" || Pchar.boxname == "box59"
				|| Pchar.boxname == "box5" || Pchar.boxname == "box1" || Pchar.boxname == "box2") 
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else
				{
					if(Pchar.boxname == "box42" || Pchar.boxname == "box44" || Pchar.boxname == "box56"
					|| Pchar.boxname == "box45" || Pchar.boxname == "box46" || Pchar.boxname == "box47"
					|| Pchar.boxname == "box48" || Pchar.boxname == "box49" || Pchar.boxname == "box3") 
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else
				{
					if(Pchar.boxname == "box11")
					{
						if(CheckAttribute(Pchar, "quest.Ch_town_box11") && Pchar.quest.Ch_town_box11 == "phase1")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
				}
				else
				{
					if(Pchar.boxname == "box27")
					{
						if(CheckAttribute(Pchar, "quest.Ch_town_box27") && Pchar.quest.Ch_town_box27 == "phase1")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
				}
			/*	else
				{
					if(Pchar.boxname == "box3")
					{
						if(CheckAttribute(Pchar, "quest.Ch_town_box3") && Pchar.quest.Ch_town_box3 == "locked")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
				}   */
				else
				{
					if(Pchar.boxname == "box6")
					{
						if(CheckAttribute(Pchar, "quest.Ch_town_box6") && Pchar.quest.Ch_town_box6 == "locked")
						{
							if(CheckCharacterItem(Pchar,"key28"))
							{
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
							else IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
				}
				else
				{
					if(Pchar.boxname == "box65") IActions.ActiveActions.OpenBox.IconNum    = 29;
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}
//JRH icons
			if(Pchar.location == "GB_Charleston_town_tavern")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_governor_office")
			{
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 55;
				if(Pchar.boxname == "box5" || Pchar.boxname == "box6")
					IActions.ActiveActions.OpenBox.IconNum    = 62;
				if(Pchar.boxname == "box1" || Pchar.boxname == "box4")
					IActions.ActiveActions.OpenBox.IconNum    = 2;
			}

			if(Pchar.location == "GB_Charleston_governor_bedroom")
			{
				if(Pchar.boxname == "box4" || Pchar.boxname == "box5")
					IActions.ActiveActions.OpenBox.IconNum    = 62;
			}

			if(Pchar.location == "GB_Charleston_governor_kitchen")
			{
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_store")
			{
				if(Pchar.boxname == "box2")
				{
					if(CheckAttribute(Pchar,"quest.store_box2") && Pchar.quest.store_box2 == "locked")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				if(Pchar.boxname == "box3" || Pchar.boxname == "box12")
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box14" || Pchar.boxname == "box15")
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				if(Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum     = 2;
				if(Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 10;
				if(Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum    = 62;
			}

			if(Pchar.location == "Poe_bedroom")
			{
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4")
					IActions.ActiveActions.OpenBox.IconNum    = 62;
				if(Pchar.boxname == "box5" || Pchar.boxname == "box6")
					IActions.ActiveActions.OpenBox.IconNum    = 3;
				if(Pchar.boxname == "box8") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "Dupin_office")
			{
				if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box5"
					|| Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 3;
			}

			if(Pchar.location == "Dupin_private")
			{
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box3" || Pchar.boxname == "box4")	IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_opium")
			{
				if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_penthouse")
			{
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Pym_drawing_room")
			{
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 3;
				if(Pchar.boxname == "box6" || Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 62;
			}

			if(Pchar.location == "Pym_bedroom")
			{
				if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box5")
				{
					if(CheckAttribute(Pchar, "quest.pym_niche") && Pchar.quest.pym_niche == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 62;

					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}

			if(Pchar.location == "Pym_study")
			{
				if(Pchar.boxname == "box5" || Pchar.boxname == "box10") IActions.ActiveActions.OpenBox.IconNum    = 3;
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box7") 
					IActions.ActiveActions.OpenBox.IconNum    = 62;
				if(Pchar.boxname == "box6" || Pchar.boxname == "box8" || Pchar.boxname == "box12"
				|| Pchar.boxname == "box9")  IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box13")
				{
					if(CheckAttribute(Pchar, "quest.pym_ladder") && Pchar.quest.pym_ladder == "way_up")
					{
						if(CheckAttribute(Pchar, "quest.pym_big_sack") && Pchar.quest.pym_big_sack == "placed")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 1;	
						}
						else
						{
							IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
			}

			if(Pchar.location == "Pym_towerroom")
			{
				if(Pchar.boxname == "box1")
				{
					if(CheckAttribute(Pchar,"quest.pym_hatch") && Pchar.quest.pym_hatch == "locked")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 0;	
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				if(Pchar.boxname == "box3" || Pchar.boxname == "box4" || Pchar.boxname == "box5"
				|| Pchar.boxname == "box8" || Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 2;	
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 0;
				if(Pchar.boxname == "box10" || Pchar.boxname == "box11") IActions.ActiveActions.OpenBox.IconNum    = 63;					
			}

			if(Pchar.location == "GB_Charleston_tailorsShop")
			{
				if(Pchar.boxname == "box1")
				{
					if(CheckCharacterItem(Pchar,"key29"))
					{
					 	IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box7") 
					IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box4" || Pchar.boxname == "box9")	IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Charleston_church")
			{
				if(Pchar.boxname == "box1")
				{
					if(CheckCharacterItem(Pchar,"magnet2") || CheckCharacterItem(Pchar,"magnet"))
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 60;
				}
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 13;
				if(Pchar.boxname == "box5")
				{
					if(CheckAttribute(Pchar, "church.box5") && Pchar.church.box5 == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 29;
					}
					else
					{
						if(CheckCharacterItem(Pchar,"needles2") || CheckCharacterItem(Pchar,"needles"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
				}
				if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 62;				
			}

			if(Pchar.location == "GB_Charleston_church_office")
			{
				if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_Chinatown")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum    = 7;
				if(Pchar.boxname == "box5" || Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 0;
			}

			if(Pchar.location == "GB_chinese_room")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "GB_chinese_gunpowder")
			{
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 7;				
				if(Pchar.boxname == "box8" || Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box10" || Pchar.boxname == "box11" || Pchar.boxname == "box12"
				|| Pchar.boxname == "box13" || Pchar.boxname == "box2" || Pchar.boxname == "box16"
				|| Pchar.boxname == "box17" || Pchar.boxname == "box18") IActions.ActiveActions.OpenBox.IconNum   = 2;
			}

			if(Pchar.location == "GB_chinese_nitre")
			{
				IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box6") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum    = 29;
				if(Pchar.boxname == "box5")
				{
					if(Locations[FindLocation(Pchar.location)].models.always.locators == "warehouse_l_nitre_DN" 
					|| Locations[FindLocation(Pchar.location)].models.always.locators == "warehouse_l_nitre_NN"
					|| Locations[FindLocation(Pchar.location)].models.always.locators == "warehouse_l_nitre_WN")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
				if(Pchar.boxname == "box9")
				{
					if(CheckCharacterItem(Pchar,"pistolbucket_nitre")) 
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}

			if(Pchar.location =="GB_charcoal_stairs")
			{
				if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 1;
			}

			if(Pchar.location == "GB_chinese_charcoal")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3"
				|| Pchar.boxname == "box4" || Pchar.boxname == "box6" || Pchar.boxname == "box7") IActions.ActiveActions.OpenBox.IconNum   = 2;

				if(Pchar.boxname == "box5")
				{
					if(CheckCharacterItem(Pchar,"key24"))
					{
						IActions.ActiveActions.OpenBox.IconNum   = 2;
					}
					else
					{
						IActions.ActiveActions.OpenBox.IconNum   = 0;
					}
				}
			}

			if(Pchar.location == "GB_chinese_sulphur")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box6" || Pchar.boxname == "box7"
				|| Pchar.boxname == "box4" || Pchar.boxname == "box8" || Pchar.boxname == "box9") IActions.ActiveActions.OpenBox.IconNum    = 2;				
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}
		
			if(Pchar.location == "Bessop_plantation")
			{
				if(Pchar.boxname == "box9" || Pchar.boxname == "box11") 
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				else
				{
					if(Pchar.boxname == "box12" || Pchar.boxname == "box14") 
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Bessop_storeroom4") IActions.ActiveActions.OpenBox.IconNum    = 1;

			if(Pchar.location == "Bessop_tavern")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 29;
			}

			if(Pchar.location == "Charleston_swamp")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 3;
				if(Pchar.boxname == "box2" || Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Loghouse_stairs")
			{
				if(CheckAttribute(Pchar, "quest.Loghouse_stairs.box2") && Pchar.quest.Loghouse_stairs.box2 == "locked")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 0;		
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 1;
			}
 
			if(Pchar.location == "Maroon_Hideout")
			{
				if(Pchar.boxname == "box3" || Pchar.boxname == "box9") 
				{
					IActions.ActiveActions.OpenBox.IconNum    = 1;
				}
				else
				{
					if(Pchar.boxname == "box10") 
					{
						if(CheckAttribute(Pchar, "quest.hideout.box10") && Pchar.quest.hideout.box10 == "locked")
						{
							IActions.ActiveActions.OpenBox.IconNum    = 0;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 1;	
					}
				}
				else
				{
					if(Pchar.boxname == "box13") IActions.ActiveActions.OpenBox.IconNum    = 5; 
				}
				else IActions.ActiveActions.OpenBox.IconNum    = 63;
			}

			if(Pchar.location == "Charleston_passage")
			{
				if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum    = 63;
				if(Pchar.boxname == "box2")
				{
					if(CheckAttribute(Pchar, "quest.mar_cav_from_plant") && Pchar.quest.mar_cav_from_plant == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else
					{
						if(CheckCharacterItem(Pchar,"key30"))
						{
							IActions.ActiveActions.OpenBox.IconNum   = 2;
						}
						else IActions.ActiveActions.OpenBox.IconNum    = 0;
					}
				}
				if(Pchar.boxname == "box3") IActions.ActiveActions.OpenBox.IconNum    = 5;				
			}

			if(Pchar.location == "Maroon_Cavern")
			{
				if(Pchar.boxname == "box1" || Pchar.boxname == "box2" || Pchar.boxname == "box3")
					IActions.ActiveActions.OpenBox.IconNum    = 29;
				if(Pchar.boxname == "box4") 
				{
					if(Locations[FindLocation(Pchar.location)].models.always.l6 == "ladder_rope")
					{
						//go up
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
					else
					{
						if(CheckCharacterItem(Pchar,"bladeladder2")) 
						{
							//place it at lower end of rope 
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						}
						else
						{
							//go up
							IActions.ActiveActions.OpenBox.IconNum    = 63;
						}
					}
				}
				if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box6")
				{
					if(CheckAttribute(Pchar, "quest.mar_cav_to_bridge") && Pchar.quest.mar_cav_to_bridge == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				if(Pchar.boxname == "box7")
				{
					if(CheckAttribute(Pchar, "quest.mar_cav_to_hideout") && Pchar.quest.mar_cav_to_hideout == "open")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 1;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 0;
				}
				if(Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10"
				|| Pchar.boxname == "box11" || Pchar.boxname == "box12" || Pchar.boxname == "box13"
				|| Pchar.boxname == "box14") 
					IActions.ActiveActions.OpenBox.IconNum    = 2;
			}
//JRH bridge
			if(Pchar.location == "Charleston_shore")
			{
				IActions.ActiveActions.OpenBox.IconNum    = 63;

				if(Pchar.boxname == "box19")
				{
					if(CheckAttribute(Pchar, "quest.ch_shore_resuse_ladder") && Pchar.quest.ch_shore_resuse_ladder == "yes")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 63;
				}
				
				if(Pchar.boxname == "box29" || Pchar.boxname == "box30" || Pchar.boxname == "box31"
				|| Pchar.boxname == "box34" || Pchar.boxname == "box35" || Pchar.boxname == "box37"
				|| Pchar.boxname == "box38" || Pchar.boxname == "box39" || Pchar.boxname == "box18"
				|| Pchar.boxname == "box17")
				{
					IActions.ActiveActions.OpenBox.IconNum    = 2;
				}
				
				if(Pchar.boxname == "box40") IActions.ActiveActions.OpenBox.IconNum    = 1;
				if(Pchar.boxname == "box43" || Pchar.boxname == "box46") IActions.ActiveActions.OpenBox.IconNum    = 5;

				if(Pchar.boxname == "box32")
				{
					if(Locations[FindLocation(Pchar.location)].models.always.l10 == "wood_step1" || Locations[FindLocation(Pchar.location)].models.always.l9 == "ladder_lever")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 3;
				}
			}
		
			if(Pchar.location == "Bishops_Hostel")
			{
				IActions.ActiveActions.OpenBox.IconNum    = 63;

				if(Pchar.boxname == "box55") IActions.ActiveActions.OpenBox.IconNum    = 5;
				if(Pchar.boxname == "box58") IActions.ActiveActions.OpenBox.IconNum    = 54;
				if(Pchar.boxname == "box56") IActions.ActiveActions.OpenBox.IconNum    = 2;
				if(Pchar.boxname == "box59") 
				{
					if(CheckAttribute(Pchar, "treasure_tour") && Pchar.treasure_tour == "boat")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 5;
					}
					else IActions.ActiveActions.OpenBox.IconNum    = 2;
				}	
				if(Pchar.boxname == "box37") 
				{
					if(CheckAttribute(Pchar, "quest.devils_seat") && Pchar.quest.devils_seat == "go_down")
					{
						IActions.ActiveActions.OpenBox.IconNum    = 63;
					}
					else
					{
						if(IsEquipCharacterByItem(Pchar, "bladespyglass6"))
						{
							IActions.ActiveActions.OpenBox.IconNum    = 3;
						}
						else
						{
							if(CheckCharacterItem(Pchar,"bladespyglass6")) 
							{
								IActions.ActiveActions.OpenBox.IconNum    = 2;
							}
							else
							{
								IActions.ActiveActions.OpenBox.IconNum    = 63;
							}
						}
					}
				}
				if(Pchar.boxname == "box57") 
				{
					if(CheckAttribute(Pchar, "treasure_spot"))
					{
						if(Pchar.treasure_spot == "2_skeletons" || Pchar.treasure_spot == "1_skeleton") 
							IActions.ActiveActions.OpenBox.IconNum    = 2;
						if(Pchar.treasure_spot == "cutlass")      IActions.ActiveActions.OpenBox.IconNum   = 3;
						if(Pchar.treasure_spot == "metal")        IActions.ActiveActions.OpenBox.IconNum  = 34;
						if(Pchar.treasure_spot == "locked_chest") IActions.ActiveActions.OpenBox.IconNum   = 0;
						if(Pchar.treasure_spot == "open_chest")   IActions.ActiveActions.OpenBox.IconNum   = 1;
					}
				}
			}	
//<-- GoldBug
	}
//<-- JRH
}



//JRH
//from LAi_events.c
void LAi_CharacterFireExecute_BUG(aref attack, aref enemy, float kDist, int isFindedEnemy)

//Logit("LAi_CharacterFireExecute_BUG");
//LogIt("2222");
	// ccc jul 05 Former LAi_CharacterFire() function minus the EventData yielded by the original targeting process
	// Shooting can now also be executed from other functions with other data
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	//ccc aref attack = GetEventData();
	//ccc aref enemy = GetEventData();
	//ccc float kDist = GetEventData();
	//ccc int isFindedEnemy = GetEventData();
	//Заряд персонажа
	if(!CheckAttribute(attack, "chr_ai.charge")) attack.chr_ai.charge = "0";
	float charge = stf(attack.chr_ai.charge) - 1.0;
	if(charge <= 0.0)
	{
		charge = 0.0;
		attack.chr_ai.chargeprc = "1";
	}
	attack.chr_ai.charge = charge;
	//Если промахнулись, то ничего не делаем

//JRH moved up block from below
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);	// defines weaponname
	aref weapon;
	Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

	float u, v, w;          		//JRH coordinates for effects
	GetCharacterPos(attack, &u, &v, &w);    //JRH determines position of initial target

	float x, y, z;          		//JRH revolver effect
	GetCharacterPos(enemy, &x, &y, &z);

	if(isFindedEnemy == 0)
	{
		//здесь можно поднимать тревогу в случае близкого выстрела

		if(CheckAttribute(weapon, "id") && weapon.id == "pistoltinderbox")
		{
			//JRH tinder box
			CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\duel\GI_ValidClick.wav");
	/*
		//fireworks in here
			if(IsEquipCharacterByItem(attack, "bladefireworks"))
			{
				CreateParticleSystem("fort_fire" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );
				PlaySound("OBJECTS\SHIPCHARGE\bomb_lit.wav");	
			}			
	*/
			if(attack.location == "Legrands_kitchen")
			{
			    	if(CheckAttribute(attack,"quest.Legrands_parchment_place") && attack.quest.Legrands_parchment_place == "in_cauldron")
			    	{
					//don't try to boil the parchment
					LAi_SetFightMode(attack, false);
					LAi_LocationFightDisable(&Locations[FindLocation("Legrands_kitchen")], true);

					Log_SetStringToLog(TranslateString("","No, I don't want to boil the Parchment!"));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
					return;
			   	}	

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
							Locations[FindLocation(attack.location)].models.always.locators = "mediumhouse01_locators_GB0";
							locations[FindLocation(attack.location)].models.always.l2 = "wood3";
							Locations[FindLocation("Legrands_kitchen")].image = "";
							attack.quest.Legrands_fireplace = "glowing";
					
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
					else 
					{
						LAi_QuestDelay("end_of_tinderbox2", 1.0); 
			
					}
				}
			}
		
			if(attack.location == "GB_chinese_charcoal")
			{
				if(CheckAttribute(attack,"quest.charcoal_tinderbox") && attack.quest.charcoal_tinderbox == "enabled")
				{
					Locations[FindLocation(attack.location)].models.always.locators = "Hut_locators_charcoal6";
					Locations[FindLocation("GB_chinese_charcoal")].image = "";
					
					LAi_QuestDelay("end_of_tinderbox_charcoal", 1.0);
				}
			}
//JRH
			if(attack.location == "pym_towerroom")
			{
				if(CheckAttribute(attack,"quest.tower_tinderbox") && attack.quest.tower_tinderbox == "enabled")
				{
					LAi_QuestDelay("end_of_tinderbox_tower", 1.0);
				}
			}

			return;
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
		else
		{
			if(attack.location == "GB_chinese_nitre")
			{
				if(CheckAttribute(attack, "quest.nitre_position") && attack.quest.nitre_position == "tub")
				{
					PlaySound("INTERFACE\anchor_up.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolbucket_empty");
					GiveItem2Character(attack, "pistolbucket_nitre");
					EquipCharacterByItem(attack, "pistolbucket_nitre");

					LAi_QuestDelay("nitre_fill_bucket", 1.5);
				}

				if(CheckAttribute(attack, "quest.nitre_position") && attack.quest.nitre_position == "planks")
				{
					PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolbucket_nitre");
					GiveItem2Character(attack, "pistolbucket_empty");	
					EquipCharacterByItem(attack, "pistolbucket_empty");

					LAi_QuestDelay("nitre_empty_bucket", 1.5);
				}
				return;
			}
		}
		else
		{
			if(attack.location == "GB_chinese_sulphur")
			{
				if(CheckAttribute(attack, "quest.sulfur_position") && attack.quest.sulfur_position == "ladder")
				{
					attack.quest.sulfur_water = "filled";
					PlaySound("OBJECTS\SHIPCHARGE\ball_splash2.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolbucket_water");
					GiveItem2Character(attack, "pistolbucket_empty");	
					EquipCharacterByItem(attack, "pistolbucket_empty");

					LAi_QuestDelay("sulfur_empty_bucket", 1.5);
				}

				if(CheckAttribute(attack, "quest.sulfur_position") && attack.quest.sulfur_position == "hatch")
				{
					attack.quest.sulfur_pyrite = "filled";
					PlaySound("PEOPLE\grass_noise.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolpyrite_F");
					GiveItem2Character(attack, "pistolpyrite_E");	
					EquipCharacterByItem(attack, "pistolpyrite_E");

					LAi_QuestDelay("sulfur_empty_box", 1.5);
				}

				if(CheckAttribute(attack, "quest.sulfur_position") && attack.quest.sulfur_position == "hatch2")
				{
					//attack.quest.sulfur_pyrite = "empty";
					PlaySound("PEOPLE\grass_noise.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolsulphur_E");
					GiveItem2Character(attack, "pistolsulphur_H");	
					EquipCharacterByItem(attack, "pistolsulphur_H");

					LAi_QuestDelay("sulfur_fill_sulfur", 1.5);
				}

				if(CheckAttribute(attack, "quest.sulfur_position") && attack.quest.sulfur_position == "hatch3")
				{
					attack.quest.sulfur_pyrite = "empty";
					PlaySound("PEOPLE\grass_noise.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolsulphur_H");
					GiveItem2Character(attack, "pistolsulphur_F");	
					EquipCharacterByItem(attack, "pistolsulphur_F");

					LAi_QuestDelay("sulfur_fill_sulfur_again", 1.5);
				}

				return;
			}
		}
		else
		{
			if(attack.location == "GB_chinese_gunpowder")
			{
				if(CheckAttribute(attack, "quest.mill_position") && attack.quest.mill_position == "bin")
				{
					if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolbarrel_gpW")
					{
						PlaySound("PEOPLE\grass_noise.wav");
						RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
						TakeItemFromCharacter(attack, "pistolbarrel_gpW");
						GiveItem2Character(attack,"pistolbarrel_gp0");
						EquipCharacterByItem(attack, "pistolbarrel_gp0");

						LAi_QuestDelay("empty_gp_barrel", 1.5);		//was 0.5
						LAi_QuestDelay("Jup_with_ingredients", 2.0);
						return;
					}
				}
//JRH lost bad gp
				if(CheckAttribute(attack, "quest.mill_position") && attack.quest.mill_position == "floor")
				{

					if(Locations[FindLocation(attack.location)].models.always.locators == "sklad_l_GB_barrel")
					{
						//barrel on floor

						if(makefloat(attack.quest.gp_total) == 4.0)
						{
							//floor barrel is full

						    if(CheckAttribute(attack, "quest.floor_barrel") && attack.quest.floor_barrel == "gun_type")
				    	    	    {
							attack.quest.gp_charcoal = 0;
							attack.quest.gp_nitre = 0;
							attack.quest.gp_sulfur = 0;
							attack.quest.gp_total = 0;

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);

							if(CheckAttribute(attack, "quest.gp_quality") )
							{
								if(attack.quest.gp_quality == "standard")
								{
									GiveItem2Character(attack,"pistolbarrel_gpS");
									EquipCharacterByItem(attack, "pistolbarrel_gpS");
								}

								if(attack.quest.gp_quality == "fireworks")
								{
									GiveItem2Character(attack,"pistolbarrel_gpF");
									EquipCharacterByItem(attack, "pistolbarrel_gpF");
								}

								if(attack.quest.gp_quality == "wrong")
								{
									GiveItem2Character(attack,"pistolbarrel_gpW");
									EquipCharacterByItem(attack, "pistolbarrel_gpW");
								}
							}

							TakeItemFromCharacter(attack, "pistolhand2");

							LAi_QuestDelay("pick_up_barrel_from_floor1", 1.0);
							return;
						    }
						}
						else
						{
							//floor barrel is NOT full

							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Logit(TranslateString("","The Barrel isn't filled yet."));
						}
					}

					if(Locations[FindLocation(attack.location)].models.always.locators == "sklad_l_GB_empty")
					{
						//no barrel on floor

						RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
						TakeItemFromCharacter(attack, "pistolbarrel_gp0");
						GiveItem2Character(attack, "pistolhand2");	
						EquipCharacterByItem(attack, "pistolhand2");
						PlaySound("OBJECTS\DUEL\club2.wav");
						PlaySound("PEOPLE\step_echo.wav");

						attack.quest.floor_barrel = "gun_type";
			
						LAi_QuestDelay("place_empty_barrel_on_floor1", 1.0);
					}
				}

				if(CheckAttribute(attack, "quest.mill_position") && attack.quest.mill_position == "ladder_top")
				{
					if(makefloat(attack.quest.BB_total) == 8.0)
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","The barrel is already filled. Now it's time to grind it."));

						LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
						return;
					}
					else
					{
						//FULL CONTINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(attack.quest.BB_total) == 7.0)
							{
								attack.quest.store_charcoal = makefloat(attack.quest.store_charcoal) + 1;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolcharcoal_F");
								GiveItem2Character(attack,"pistolcharcoal_H");
								EquipCharacterByItem(attack, "pistolcharcoal_H");
							}
							else
							{
								attack.quest.store_charcoal = makefloat(attack.quest.store_charcoal) + 2;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 2;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolcharcoal_F");
								GiveItem2Character(attack,"pistolcharcoal_E");
								EquipCharacterByItem(attack, "pistolcharcoal_E");
							}
							
							attack.quest.charcoal_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(attack.quest.BB_total) == 7.0)
							{
								attack.quest.store_nitre = makefloat(attack.quest.store_nitre) + 1;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolnitre_big_F");
								GiveItem2Character(attack,"pistolnitre_H");
								EquipCharacterByItem(attack, "pistolnitre_H");
							}
							else
							{
								attack.quest.store_nitre = makefloat(attack.quest.store_nitre) + 2;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 2;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolnitre_big_F");
								GiveItem2Character(attack,"pistolnitre_E");
								EquipCharacterByItem(attack, "pistolnitre_E");
							}
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							if(makefloat(attack.quest.BB_total) == 7.0)
							{
								attack.quest.store_sulfur = makefloat(attack.quest.store_sulfur) + 1;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolsulphur_F");
								GiveItem2Character(attack,"pistolsulphur_H");
								EquipCharacterByItem(attack, "pistolsulphur_H");
							}
							else
							{
								attack.quest.store_sulfur = makefloat(attack.quest.store_sulfur) + 2;
								attack.quest.store_total = makefloat(attack.quest.store_total) + 2;
								attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
								RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
								TakeItemFromCharacter(attack, "pistolsulphur_F");
								GiveItem2Character(attack,"pistolsulphur_E");
								EquipCharacterByItem(attack, "pistolsulphur_E");
							}

							attack.quest.sulfur_risk = 33;
							
							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}

						//HALF FULL CONTAINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.store_charcoal = makefloat(attack.quest.store_charcoal) + 1;
							attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
							attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack,"pistolcharcoal_E");
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							attack.quest.charcoal_risk = 33;
						
							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.store_nitre = makefloat(attack.quest.store_nitre) + 1;
							attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
							attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack,"pistolnitre_E");
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.store_sulfur = makefloat(attack.quest.store_sulfur) + 1;
							attack.quest.store_total = makefloat(attack.quest.store_total) + 1;
							attack.quest.BB_total = makefloat(attack.quest.store_total) + makefloat(attack.quest.mix_total);
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack,"pistolsulphur_E");
							EquipCharacterByItem(attack, "pistolsulphur_E");

							attack.quest.sulfur_risk = 33;

							LAi_QuestDelay("fill_and_return_from_ladder_top", 1.0);
							return;
						}
					}
				}

			//**********************************************************************************************************

				if(CheckAttribute(attack, "quest.mill_position") && attack.quest.mill_position == "large_bottle")
				{
					//EMPTY BOTTLE
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LE0")
					{
						//FULL CONTINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LC2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_F");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LN2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_big_F");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LS2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_F");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						//HALF FULL CONTAINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LC1";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC1";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LN1";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN1";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LS1";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS1";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					}

				//HALF FULL BOTTLE cases in here
				//--------------------------------------------------------------------------------------------------------------------
					//BLACK
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LC1")
					{
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LC2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_F");
							GiveItem2Character(attack, "pistolcharcoal_H");	
							EquipCharacterByItem(attack, "pistolcharcoal_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LC2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LC2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LG2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_big_F");
							GiveItem2Character(attack, "pistolnitre_H");	
							EquipCharacterByItem(attack, "pistolnitre_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LG2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
						
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							//problem
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LZ2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_F");
							GiveItem2Character(attack, "pistolsulphur_H");	
							EquipCharacterByItem(attack, "pistolsulphur_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							//problem
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LZ2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					}
					
					//GREY
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LG1")
					{
						if(CheckAttribute(attack, "equip.gun"))
						{
							if(attack.equip.gun == "pistolcharcoal_F" || attack.equip.gun == "pistolnitre_big_F" || attack.equip.gun == "pistolsulphur_F"
							|| attack.equip.gun == "pistolcharcoal_H" || attack.equip.gun == "pistolnitre_H" || attack.equip.gun == "pistolsulphur_H")
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","No, I'm not sure that's the right mix."));

								LAi_QuestDelay("place_large_bottle1", 0.5);
							}	
						}
					}

					//WHITE
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LN1")
					{
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LG2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_F");
							GiveItem2Character(attack, "pistolcharcoal_H");	
							EquipCharacterByItem(attack, "pistolcharcoal_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LG2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LG2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
				
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LN2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_big_F");
							GiveItem2Character(attack, "pistolnitre_H");	
							EquipCharacterByItem(attack, "pistolnitre_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LN2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LN2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LY2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_F");
							GiveItem2Character(attack, "pistolsulphur_H");	
							EquipCharacterByItem(attack, "pistolsulphur_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LY2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					}

					//YELLOW
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LS1")
					{
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							//problem
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LZ2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_F");
							GiveItem2Character(attack, "pistolcharcoal_H");	
							EquipCharacterByItem(attack, "pistolcharcoal_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							//problem
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LZ2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LZ2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LY2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_big_F");
							GiveItem2Character(attack, "pistolnitre_H");	
							EquipCharacterByItem(attack, "pistolnitre_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LY2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LY2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LS2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_F");
							GiveItem2Character(attack, "pistolsulphur_H");	
							EquipCharacterByItem(attack, "pistolsulphur_H");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.large_bottle = "LS2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l3 = "bottle_LS2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_large_bottle", 1.0);
							return;
						}
					}						

					//LIGHT YELLOW
					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LY1")
					{
						if(CheckAttribute(attack, "equip.gun"))
						{
							if(attack.equip.gun == "pistolcharcoal_F" || attack.equip.gun == "pistolnitre_big_F" || attack.equip.gun == "pistolsulphur_F"
							|| attack.equip.gun == "pistolcharcoal_H" || attack.equip.gun == "pistolnitre_H" || attack.equip.gun == "pistolsulphur_H")
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","No, I'm not sure that's the right mix."));

								LAi_QuestDelay("place_large_bottle1", 0.5);
							}	
						}
					}

					if(CheckAttribute(attack, "quest.large_bottle") && attack.quest.large_bottle == "LZ1")
					{
						if(CheckAttribute(attack, "equip.gun"))
						{
							if(attack.equip.gun == "pistolcharcoal_F" || attack.equip.gun == "pistolnitre_big_F" || attack.equip.gun == "pistolsulphur_F"
							|| attack.equip.gun == "pistolcharcoal_H" || attack.equip.gun == "pistolnitre_H" || attack.equip.gun == "pistolsulphur_H")
							{
								PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
								Logit(TranslateString("","No, I'm not sure that's the right mix."));

								LAi_QuestDelay("place_large_bottle1", 0.5);
							}	
						}
					}
				}
			
			//**********************************************************************************************************

				if(CheckAttribute(attack, "quest.mill_position") && attack.quest.mill_position == "medium_bottle")
				{
					//EMPTY BOTTLE
					if(CheckAttribute(attack, "quest.medium_bottle") && attack.quest.medium_bottle == "ME0")
					{
						//FULL CONTAINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MC2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MC2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_F");
							GiveItem2Character(attack, "pistolcharcoal_H");	
							EquipCharacterByItem(attack, "pistolcharcoal_H");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_big_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MN2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MN2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_big_F");
							GiveItem2Character(attack, "pistolnitre_H");	
							EquipCharacterByItem(attack, "pistolnitre_H");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_F")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MS2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MS2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_F");
							GiveItem2Character(attack, "pistolsulphur_H");	
							EquipCharacterByItem(attack, "pistolsulphur_H");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}
						
						//HALF FULL CONTINERS
						//--------------------------------------------------------------------------------------------------
						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolcharcoal_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MC2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MC2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcharcoal_H");
							GiveItem2Character(attack, "pistolcharcoal_E");	
							EquipCharacterByItem(attack, "pistolcharcoal_E");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolnitre_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MN2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MN2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolnitre_H");
							GiveItem2Character(attack, "pistolnitre_E");	
							EquipCharacterByItem(attack, "pistolnitre_E");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}

						if(CheckAttribute(attack, "equip.gun") && attack.equip.gun == "pistolsulphur_H")
						{
							PlaySound("PEOPLE\grass_noise.wav");
							attack.quest.medium_bottle = "MS2";
							locations[FindLocation("GB_chinese_gunpowder")].models.always.l2 = "bottle_MS2";

							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolsulphur_H");
							GiveItem2Character(attack, "pistolsulphur_E");	
							EquipCharacterByItem(attack, "pistolsulphur_E");

							LAi_QuestDelay("place_medium_bottle", 1.0);
							return;
						}
					}
				}
			}
		}
		else
		{
			if(attack.location == "GB_Chinatown")
			{
				if(CheckAttribute(attack, "quest.China_well") && attack.quest.China_well == "phase2")
				{
					PlaySound("INTERFACE\anchor_up.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolhand2");
					GiveItem2Character(attack, "pistolbucket_water");	
					EquipCharacterByItem(attack, "pistolbucket_water");

					LAi_QuestDelay("Chinatown_take_bucket", 1.5);
				}


				if(CheckAttribute(attack, "quest.China_well") && attack.quest.China_well == "phase1")
				{
					PlaySound("INTERFACE\bucket_water.wav");
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
					TakeItemFromCharacter(attack, "pistolbucket_empty");
					GiveItem2Character(attack, "pistolhand2");	
					EquipCharacterByItem(attack, "pistolhand2");

					LAi_QuestDelay("Chinatown_fill_bucket", 1.5);
				}
				
				

				return;
			}
		}
		
			
	}
//<-- JRH
}


