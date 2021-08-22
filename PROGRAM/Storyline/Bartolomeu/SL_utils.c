
void OpenBoxProcedure_BART()
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
	//note in INTERFACE\itemsbox search JRH: normal box sounds avoided when not wanted
//pдr
    //Cartagena puzzle -->
	
	if(Locations[locidx].id=="Cartagena_center")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("OBJECTS\DUEL\man_attack1.wav");
				LAi_SetSitType(chr);
				chr.quest.cartagena_derrick_hint = "done";

				LAi_QuestDelay("climb_derrick", 0.5);
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.church_burglar"))
				{
					switch(chr.quest.church_burglar)
			    		{
						case "1":
							PlaySound("INTERFACE\locked_window.wav");
							Logit(TranslateString("","No, it's locked from the inside. I have to brake it."));
							chr.quest.church_burglar = "2";

							Locations[FindLocation("Cartagena_center")].locators_radius.box.box1 = 0.0001;
							SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box1", 0.0001);
						break;

						case "2":
							Logit(TranslateString("","I'll use the butt-end of my pistol."));
							
							RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							GiveItem2Character(chr, "bladepclub203");
							EquipCharacterByItem(chr, "bladepclub203");
							TakeItemFromCharacter(chr, "pistol203");

							chr.quest.church_burglar = "4";
							ChangeCharacterAddressGroup(characterFromID("window_target"), "Cartagena_center", "goto", "target");
						break;

						case "4":
							//do nothing until window is broken
						break;

						case "5":
							PlaySound("PEOPLE\counter_open.wav");
							chr.quest.church_burglar = "6";

							LAi_QuestDelay("enter_church_via_window", 1.5);
						break;

						case "6":
							//do nothing after 5
						break;
					}
			    		return;
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Cartagena_church")
	{
		switch(chr.boxname)
		{
			case "box1":
				ChangeCharacterAddressGroup(chr, "Cartagena_church", "goto", "window1");
				LAi_SetSitType(chr);
				PlaySound("PEOPLE\jump_stone.wav");
				PlaySound("PEOPLE\step_echo2.wav");
				PlaySound("PEOPLE\step_echo2.wav");

				LAi_QuestDelay("cartagena_church_jump", 0.5);
			break;

			case "box2":
				PlaySound("INTERFACE\key_unlock2.wav");
				Locations[FindLocation("Cartagena_church")].locators_radius.reload.reload1 = 1.0;
				Locations[FindLocation("Cartagena_church")].locators_radius.box.box2 = 0.0001;
				SetLocatorRadius(locations[FindLocation(chr.location)], "reload", "reload1", 1.0);
				SetLocatorRadius(locations[FindLocation(chr.location)], "box", "box2", 0.0001);
				Locations[FindLocation("Cartagena_center")].reload.l2.close_for_night = 0;
			break;

			case "box3":
				//LEVER IS UP - DOOR HIDDEN

				PlaySound("INTERFACE\lever_down.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "church3_l_BOP_open";
		
				LAi_QuestDelay("cartagena_church_lever_down", 0.5);
			break;
		
			case "box4":
				//LEVER IS DOWN - DOOR VISIBLE

				PlaySound("INTERFACE\lever_up.wav");
				Locations[FindLocation(chr.location)].models.always.locators = "church3_l_BOP_closed";
				
				LAi_QuestDelay("cartagena_church_lever_up", 0.5);
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Cartagena_church_cave")
	{
		switch(chr.boxname)
		{
			case "box1":
				PlaySound("PEOPLE\creak.wav");
				LaunchItemsBox(&ar);

				if(CheckAttribute(chr,"quest.inquisition_monk"))
				{
					if(chr.quest.inquisition_monk == "monk1_hit" || chr.quest.inquisition_monk == "monk2_hit"
					|| chr.quest.inquisition_monk == "monk3_hit" || chr.quest.inquisition_monk == "monk4_hit")
					{
						return;
					}
				}
				else
				{
					chr.quest.cartagena_snoring = "stopped";
				
					LAi_QuestDelay("hide_at_monks_chest", 0.1);
				}		
			break;

			case "box2":
				if(CheckAttribute(chr, "quest.inquisition_priest") && chr.quest.inquisition_priest == "stunned")
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");
					ChangeCharacterAddressGroup(characterFromID("inquisition_priest"), "Cartagena_church_cave", "goto", "wake_up1");
					LAi_SetActorType(characterFromID("inquisition_priest"));

					LAi_QuestDelay("priest_wakes_up", 0.1);
				}
			break;

			case "box3":
				PlaySound("INTERFACE\chart_move.wav");
				PlaySound("INTERFACE\chart_move.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("cartagena_chest_noise", 0.1);
			break;

			case "box4":
				PlaySound("PEOPLE\counter_open.wav");
				LaunchItemsBox(&ar);

				LAi_QuestDelay("cartagena_chest_noise", 0.1);
			break;

			case "box5":
				if(CheckAttribute(chr, "quest.inquisition_priest") && chr.quest.inquisition_priest == "stunned")
				{
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
					return;
				}
				else
				{
					PlaySound("PEOPLE\counter_open.wav");
					ChangeCharacterAddressGroup(characterFromID("inquisition_priest"), "Cartagena_church_cave", "goto", "wake_up1");
					LAi_SetActorType(characterFromID("inquisition_priest"));

					LAi_QuestDelay("priest_wakes_up", 0.1);
				}
			break;

			case "box6":
				//Elting's celldoor
			
				if(CheckAttribute(chr, "quest.Eltings_cell") && chr.quest.Eltings_cell == "open")
				{
					//go inside
					PlaySound("INTERFACE\rusty.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box11");
				}
				else
				{
					if(CheckCharacterItem(chr,"bladeacid"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeacid"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeacid");
						}

						if(LAi_IsFightMode(chr))
						{
							//this is your 2:nd 'open box'
							PlaySound("INTERFACE\bottle_molasses.wav");

							LAi_QuestDelay("acid_Eltings_cell", 3.0);
						}
						else
						{
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
							LAi_SetFightMode(chr, true);
						}
					}
					else PlaySound("INTERFACE\locked_window.wav");
				}
			break;

			case "box7":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box8":
				PlaySound("INTERFACE\locked_window.wav");
			break;

			case "box9":
				chr.quest.hide_behind_barrel = "yes";
				PlaySound("PEOPLE\step_stone2.wav");
				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box10");

				LAi_QuestDelay("hide_behind_barrel", 2.0);
			break;

			case "box10":
				if(CheckAttribute(chr, "quest.hide_behind_barrel") && chr.quest.hide_behind_barrel == "yes")
				{

				}
				else
				{
					PlaySound("PEOPLE\step_stone2.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box9");
				}
			break;

			case "box11":
				PlaySound("INTERFACE\rusty.wav");
				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box6");
			break;

			case "box12":
				//PRIEST IN BED

				chr.quest.inquisition_priest = "sleeping_left";
				
				if(!CheckCharacterItem(chr,"bladepclub203"))
				{
					RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					GiveItem2Character(chr, "bladepclub203");
					EquipCharacterByItem(chr, "bladepclub203");
					TakeItemFromCharacter(chr, "pistol203");
				}

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "stay12");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;

			case "box13":
				//PRIEST IN BED

				chr.quest.inquisition_priest = "sleeping_right";
				
				if(!CheckCharacterItem(chr,"bladepclub203"))
				{
					RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
					RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
					GiveItem2Character(chr, "bladepclub203");
					EquipCharacterByItem(chr, "bladepclub203");
					TakeItemFromCharacter(chr, "pistol203");
				}

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "stay13");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;

			case "box14":
				//MONK1 IN BED

				chr.quest.inquisition_monk = "monk1_hit";
				
				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr, "bladepclub203");
				EquipCharacterByItem(chr, "bladepclub203");
				TakeItemFromCharacter(chr, "pistol203");

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box14");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;

			case "box15":
				//MONK2 IN BED

				chr.quest.inquisition_monk = "monk2_hit";
				
				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr, "bladepclub203");
				EquipCharacterByItem(chr, "bladepclub203");
				TakeItemFromCharacter(chr, "pistol203");

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box15");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;

			case "box16":
				//MONK3 IN BED

				chr.quest.inquisition_monk = "monk3_hit";
				
				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr, "bladepclub203");
				EquipCharacterByItem(chr, "bladepclub203");
				TakeItemFromCharacter(chr, "pistol203");

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box16");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;

			case "box17":
				//MONK4 IN BED

				chr.quest.inquisition_monk = "monk4_hit";
				
				RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
				RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
				GiveItem2Character(chr, "bladepclub203");
				EquipCharacterByItem(chr, "bladepclub203");
				TakeItemFromCharacter(chr, "pistol203");

				ChangeCharacterAddressGroup(chr, "Cartagena_church_cave", "goto", "box17");
				LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			break;
		}

		return;
	}


	if(Locations[locidx].id=="Governor_Daughter_House")
	{
		switch(chr.boxname)
		{
			case "box1":
				LaunchItemsBox(&ar);
			break;

			case "box2":
				if(CheckAttribute(chr,"quest.daughter_fireplace") && chr.quest.daughter_fireplace == "no_key")
				{
					//do nothing

				}
				else
				{
					if(CheckAttribute(chr,"quest.daughter_fireplace") && chr.quest.daughter_fireplace == "key_on_floor")
					{
					

					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladefire_irons"))
					{
						if(!IsEquipCharacterByItem(chr, "bladefire_irons"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladefire_irons");
						}

						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("use_fire_irons", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","There's something in the fire."));
					}
				}
			break;
		}

		return;
	}

	if(Locations[locidx].id=="Admiral_Office")
	{
		switch(chr.boxname)
		{
			case "box1":
				//go to chair OR place cannonball

				if(CheckAttribute(chr,"quest.admiral_cannonball") && chr.quest.admiral_cannonball == "placed")
				{
					//do nothing
				}
				else
				{
					if(CheckCharacterItem(chr,"bladecannon_ball"))
					{
						if(!IsEquipCharacterByItem(chr, "bladecannon_ball"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladecannon_ball");
						}

						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("place_admiral_cannonball", 1.0);
					}
					else
					{
						ChangeCharacterAddressGroup(chr, "Admiral_Office", "goto", "sit1");
						chr.quest.admiral_steplock = "way_in";

						LAi_QuestDelay("enter_admiral_steplock", 1.0);
					}
				}
			break;

			case "box2":
				//at chair

				if(CheckAttribute(chr,"quest.admiral_steplock") && chr.quest.admiral_steplock == "way_out")
				{
					LAi_SetPlayerType(chr);
					PlaySound("INTERFACE\step_path.wav");
					Locations[FindLocation("Admiral_Office")].models.always.l1 = "bars_down";

					LAi_QuestDelay("leave_admiral_steplock", 0.3);
				}
			break;

			case "box3":
				//clock

				if(CheckAttribute(chr,"quest.admiral_clock") && chr.quest.admiral_clock == "off")
				{
					chr.quest.admiral_clock = "on";
					LAi_SetStayType(chr);
					PlaySound("INTERFACE\clock_wind_up.wav");

					LAi_QuestDelay("admiral_wind_up_clock", 2.2);
				}
				else
				{
					if(CheckAttribute(chr,"quest.admiral_clock") && chr.quest.admiral_clock == "on")
					{
						//do nothing
					}
				}
				else
				{
					if(CheckCharacterItem(chr,"bladeclockkey"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeclockkey"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeclockkey");
						}

						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("place_admiral_clockkey", 1.0);
					}
					else
					{
						PlaySound("VOICE\ENGLISH\blaze_hah.wav");
						Logit(TranslateString("","It has stopped."));
					}
				}
			break;
	
			case "box4":
				//lever
				
				if(CheckAttribute(chr,"quest.admiral_lever") && chr.quest.admiral_lever == "down")
				{
					PlaySound("INTERFACE\lever_stuck.wav");
				}
				else
				{
					if(CheckAttribute(chr,"quest.admiral_lever") && chr.quest.admiral_lever == "up")
					{
						chr.quest.admiral_lever = "down";
						PlaySound("INTERFACE\lever_down.wav");
						Locations[FindLocation(chr.location)].models.always.locators = "Res02_l_BoP2";
						Locations[FindLocation("Admiral_Office")].models.always.l2 = "Adm_lever_down";

						LAi_QuestDelay("admiral_lever_down", 1.0);
					}
				}
				else
				{
					//lever is missing
					if(CheckCharacterItem(chr,"bladelever"))
					{
						if(!IsEquipCharacterByItem(chr, "bladelever"))
						{
								RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
								EquipCharacterByItem(chr, "bladelever");
						}

						LAi_SetFightMode(chr, true);

						LAi_QuestDelay("place_admiral_lever", 1.0);
					}
					else PlaySound("VOICE\ENGLISH\blaze_huh.wav");
				}				
			break;

			case "box5":
				//at door to tunnel instead of reload1

				PlaySound("INTERFACE\locked_window.wav");	
			break;
		}

		return;
	}

    //<-- Cartagena puzzle
    // <-- JRH
  }
	//pдr
	virtual_box = true;	//JRH
	OpenBoxProcedure();
}

//pдr
//from Loginterface.c
void CreateLandActionsEnvironment_BART()
{
//Logit("4444");

	ref PChar = GetMainCharacter();		//JRH

//JRH -->
	if( CheckAttribute(Pchar,"boxname") )
	{
	//	IActions.ActiveActions.OpenBox.IconNum					 	= 29;
	//Cartagena -->


		if(Pchar.location == "Cartagena_center")	
		{
			if(Pchar.boxname == "box1")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 63;
			}

			if(Pchar.boxname == "box2")
			{
				if(CheckAttribute(Pchar,"quest.church_burglar"))
				{
					if(Pchar.quest.church_burglar == "1") 
					{
						IActions.ActiveActions.OpenBox.IconNum  			= 3;
					}

					if(Pchar.quest.church_burglar == "2") 
					{
						IActions.ActiveActions.OpenBox.IconNum  			= 0;
					}
					
					if(Pchar.quest.church_burglar == "4") 
					{
						IActions.ActiveActions.OpenBox.IconNum  			= 2;
					}

					if(Pchar.quest.church_burglar == "5" || Pchar.quest.church_burglar == "6") 
					{
						IActions.ActiveActions.OpenBox.IconNum  			= 1;
					}


				}
			}
		}

		if(Pchar.location == "Cartagena_church")	
		{
			if(Pchar.boxname == "box1")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 63;
			}

			if(Pchar.boxname == "box2" || Pchar.boxname == "box3" || Pchar.boxname == "box4")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 2;
			}
		}
//pдr
		if(Pchar.location == "Cartagena_church_cave")	
		{
			if(Pchar.boxname == "box6")
			{
				if(CheckAttribute(Pchar, "quest.Eltings_cell") && Pchar.quest.Eltings_cell == "open")
				{
					IActions.ActiveActions.OpenBox.IconNum  		= 1;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladeacid"))
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;	
					}
					else 
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 0;
					}
				}
			}

			if(Pchar.boxname == "box7" || Pchar.boxname == "box8")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 0;
			}

			if(Pchar.boxname == "box9" || Pchar.boxname == "box10")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 63;
			}

			if(Pchar.boxname == "box11")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 1;
			}

			if(Pchar.boxname == "box12" || Pchar.boxname == "box13" || Pchar.boxname == "box14"
			|| Pchar.boxname == "box15" || Pchar.boxname == "box16" || Pchar.boxname == "box17")
			{
				IActions.ActiveActions.OpenBox.IconNum  			= 2;
			}
		}

		if(Pchar.location == "Governor_Daughter_House")	
		{
			if(Pchar.boxname == "box2")
			{
				if(CheckCharacterItem(Pchar,"bladefire_irons"))
				{
					IActions.ActiveActions.OpenBox.IconNum  		= 2;	
				}
				else IActions.ActiveActions.OpenBox.IconNum  			= 3;
			}
		}

		if(Pchar.location == "Admiral_office")	
		{
			if(Pchar.boxname == "box1")
			{
				if(CheckCharacterItem(Pchar,"bladecannon_ball"))
				{
					IActions.ActiveActions.OpenBox.IconNum  		= 2;
				}
				else IActions.ActiveActions.OpenBox.IconNum 			= 63;
			}

			if(Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum 	= 63;

			if(Pchar.boxname == "box3")
			{
				if(CheckAttribute(Pchar,"quest.admiral_clock") && Pchar.quest.admiral_clock == "off")
				{
					IActions.ActiveActions.OpenBox.IconNum 			= 2;
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.admiral_clock") && Pchar.quest.admiral_clock == "on")
						IActions.ActiveActions.OpenBox.IconNum 		= 55;
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladeclockkey"))
					{
						IActions.ActiveActions.OpenBox.IconNum 		= 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum 		= 55;
				}
			}

			if(Pchar.boxname == "box4")
			{
				if(CheckAttribute(Pchar,"quest.admiral_lever"))  
				{
					if(Pchar.quest.admiral_lever == "down" || Pchar.quest.admiral_lever == "up")
					{
						IActions.ActiveActions.OpenBox.IconNum  	= 2;
					}
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladelever"))
					{
						IActions.ActiveActions.OpenBox.IconNum  = 2;
					}
					else IActions.ActiveActions.OpenBox.IconNum  	= 3;
				}					
			}

			if(Pchar.boxname == "box5") IActions.ActiveActions.OpenBox.IconNum 	= 2;
		}   
	//<-- Cartagena

		if(Pchar.location == "Havana_Town_02" || Pchar.location == "Santiago_port" || Pchar.location == "Santiago_town_01")
		{	
			IActions.ActiveActions.OpenBox.IconNum			= 2;
		}
   }
//<-- JRH
}

//from LAi_events.c
void LAi_CharacterFireExecute_BART(aref attack, aref enemy, float kDist, int isFindedEnemy)

//Logit("LAi_CharacterFireExecute_BART");
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
		if(CheckAttribute(weapon, "id") && weapon.id == "pistolsteel")
		{
			//JRH pistolsteel
			if(IsEquipCharacterByItem(attack, "bladeflint"))
			{
				CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
				CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
				PlaySound("OBJECTS\duel\GI_ValidClick.wav");
				PlaySound("OBJECTS\duel\steelflint.wav");

				if(CheckAttribute(attack, "filled_pipe") && attack.filled_pipe == "equipped")
				{
					LAi_SetStayType(attack);
					attack.filled_pipe = "none";
					RemoveCharacterEquip(attack, OUTFIT_ITEM_TYPE );
					TakeItemFromCharacter(attack, "filled_pipe");
					GiveItem2Character(attack, "empty_pipe");

					LAi_QuestDelay("smoking_mushrooms0", 1.0);//stops all sounds
					LAi_QuestDelay("smoking_mushrooms1", 2.0);
					LAi_QuestDelay("smoking_mushrooms4", 3.0);//new music starts
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				Log_SetStringToLog(TranslateString("","I need a Flint too!"));
			}
			return;
		}
	
	}
}