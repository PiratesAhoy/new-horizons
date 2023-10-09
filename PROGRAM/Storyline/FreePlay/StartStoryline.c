void StartStoryLine()
{
	ref PChar, ch, officer;
	PChar = GetMainCharacter();
	ch = CharacterFromID("Malcolm Hatcher");

	bChangeNation = false;// MAXIMUS 7-8-06
	ref TutDeck = &Locations[FindLocation("Tutorial_Deck")];

// KK -->
	aref arstart = GetStorylineStartParams(FindCurrentStoryline());
	string loadPort = arstart.port;
	string rldGroup = "reload";
	string rldLocator = "reload1";
	int loc = FindLocation(arstart.location);
	int iNation = GetCurrentFlag();

	sTeleportLocName = arstart.location;

	// PB: Override Character Type -->
	PChar.start_weapon.blade = FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE);
	PChar.start_weapon.gun   = FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE);
	TakeItemFromCharacter(PChar, PChar.start_weapon.blade);
	TakeItemFromCharacter(PChar, PChar.start_weapon.gun);
	TakeItemFromCharacter(PChar, "spyglass2");
	// PB: Override Character Type <--
	if(GetMySimpleOldName(pchar) == "Morgen le Fay" && pchar.model == "WitchGirl"){
		if(ENABLE_WEAPONSMOD) PChar.start_weapon.blade = "blade308-1";
		else PChar.start_weapon.blade = "blade308";
	}
	if(GetMySimpleOldName(pchar) == "Ciri Riannon" && pchar.model == "CiriWitcher"){
		if(ENABLE_WEAPONSMOD) PChar.start_weapon.blade = "bladeCiri+2";
		else PChar.start_weapon.blade = "bladeCiri";
	}

	if (GetCurrentFlag() != ENGLAND && GetCurrentFlag() != PERSONAL_NATION)
	{
		ch.nation = GetCurrentFlag();
		DeleteAttribute(ch, "questchar");
		SetRandomNameToCharacter(ch);
	}

	switch(CharPlayerType)
	{
		case PLAYER_TYPE_REBEL:
			if (GetMySimpleOldName(PChar) == "Julian McAllister" || pchar.model == "47_JRMMSub")
			{
				GiveModel2Player("47_Blaze_brtlt",false);
				GiveModel2Player("Blaze4",false);
				GiveModel2Player("Blaze5",false);
				GiveModel2Player("Blaze6",false);
				GiveModel2Player("Blaze7",false);
				GiveModel2Player("Blaze",false);
				GiveModel2Player("Blaze_NB",false);
				GiveModel2Player("wf1blaze",false);
				GiveModel2Player("Corsair1_J",false);
				GiveModel2Player("Corsair2_J",false);
				GiveModel2Player("Corsair4_J",false);
			}
			
			if (GetMySimpleOldName(PChar) == "Julian McAllister" && iNation == ENGLAND)
			{
				GiveItem2Character(PChar,"luckcharm");

				if(ENABLE_AMMOMOD)
				{
					TutDeck.box1.items.powderflask = 1;  //JRMM
					TutDeck.box1.items.ammopouch = 1;  //JRMM
				}
				TutDeck.box1.items.bladekit = 1;  //JRMM

				TutDeck.box1.items.medical1 = 4; //JRMM
				TutDeck.box1.items.potion3 = 1;  //JRMM

				// Robert Fletcher
				ch = CharacterFromID("Malcolm Hatcher");
				ch.nation = iNation;
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
				ch.skill.Leadership = "5";
				ch.skill.Accuracy = "1";
				ch.skill.Cannons = "1";
				ch.old.name = "Robert";
				ch.old.lastname = "Fletcher";
				ch.name = TranslateString("","Robert");
				ch.lastname = TranslateString("","Fletcher");
				SetModelfromArray(ch, GetModelIndex("pir_cap6"));
			}

			if (PChar.model == "Animists1" && GetMySimpleOldName(PChar) == "Dark Teacher")
			{
    				ch = CharacterFromID("Malcolm Hatcher");
    				ch.nation = iNation;
    				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
    				ch.name = TranslateString("","Dark");
    				ch.lastname = "Disciple";
				ch.greeting = "Gr_Quest_ANIMISTS";
    				SetModelfromArray(ch, GetModelIndex("animists2"));
			}
		break;

		case PLAYER_TYPE_NAVAL_OFFICER:
			if(ProfessionalNavyNation() != UNKNOWN_NATION)
			{
				// Admiral
				ch = CharacterFromID("Malcolm Hatcher");
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
				ch.nation = iNation;
				ch.professionalnavy = iNation;
				if (GetMySimpleOldName(PChar) == "Horatio Hornblower" && iNation == ENGLAND)
				{
					ch.old.name = "Edward";
					ch.old.lastname = "Pellew";
					ch.name = TranslateString("","Edward");
					ch.lastname = TranslateString("","Pellew");
					SetRank(ch, iNation, 7);
					SetRankTitle(ch, TranslateString("", "Sir"));
					SetModelfromArray(ch, GetModelIndex("PellewX_18"));

//					ChangeCharacterAddressGroup(characterFromID("Sir Rodney Leighton"), "Redmond Naval HQ", "goto", "goto3");
//					setCharacterShipLocation(characterFromID("Sir Rodney Leighton"), "Redmond_port");
//					Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 0;
					ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Greenford Naval HQ", "goto", "goto3");
					LAi_SetStayType(characterFromID("Sir Edward Pellew"));
					setCharacterShipLocation(characterFromID("Sir Edward Pellew"), "Greenford_port");
					Locations[FindLocation("Greenford_town")].reload.l19.disable = 0;
//					ChangeCharacterAddressGroup(characterfromID("El Supremo"), "Dining_Room", "goto", "goto2");
				}
				else
				{
					DeleteAttribute(ch, "questchar");
					SetRandomNameToCharacter(ch);
					SetRank(ch, iNation, 7); // GR: was 12, which would be the chief of the entire navy sitting at a desk in the nation's capital!
					switch(iNation)
					{
						case ENGLAND:
							SetRankTitle(ch, TranslateString("", "Sir"));
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("hugnt18"));
							else											SetModelfromArray(ch, GetModelIndex("brtadm2_18"));
						break;
						case FRANCE:
							SetRankTitle(ch, TranslateString("", "Chevalier"));
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("hugnt18"));
							else											SetModelfromArray(ch, GetModelIndex("fra_adm_18"));
						break;
						case SPAIN:
							SetRankTitle(ch, TranslateString("", "Don"));
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("admiral"));
							else											SetModelfromArray(ch, GetModelIndex("spa_adm_18"));
						break;
						case HOLLAND:
							SetModelfromArray(ch, GetModelIndex("Gherarde_De_Jongh"));
						break;
						case PORTUGAL:
							SetRankTitle(ch, TranslateString("", "Dom"));
							SetModelfromArray(ch, GetModelIndex("admiral"));
						break;
						case AMERICA:
							SetModelfromArray(ch, GetModelIndex("USA_adm_18"));
						break;
					}
				}
			}
		break;

		case PLAYER_TYPE_ROGUE:
			// Elbaron Caron
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			if (iNation == FRANCE)
			{
				ch.old.name = "Elbaron";
				ch.old.lastname = "Caron";
				ch.name = TranslateString("","Elbaron");
				ch.lastname = TranslateString("","Caron");
				SetModelfromArray(ch, GetModelIndex("50M5"));
			}
			else
			{
				DeleteAttribute(ch, "questchar");
				SetRandomNameToCharacter(ch);
			}
		break;

		case PLAYER_TYPE_GAMBLER:
			Pchar.quest.poker.allowed = true;//PW allow poker trophy quest only for freeplay gambler
			Locations[FindLocation("Turks_port")].reload.l19.name = "reload9_back";
			Locations[FindLocation("Turks_port")].reload.l19.go = "Turks_poker_entre";
			Locations[FindLocation("Turks_port")].reload.l19.emerge = "reload1";
			Locations[FindLocation("Turks_port")].reload.l19.autoreload = "0";
			Locations[FindLocation("Turks_port")].reload.l19.close_for_night = 1;

			Locations[FindLocation("Turks_port")].reload.l20.name = "balcony";
			Locations[FindLocation("Turks_port")].reload.l20.go = "Turks_poker_entre";
			Locations[FindLocation("Turks_port")].reload.l20.emerge = "reload2";
			Locations[FindLocation("Turks_port")].reload.l20.autoreload = "0";
			// Elbaron Caron
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			if (iNation == FRANCE)
			{
				ch.old.name = "Elbaron";
				ch.old.lastname = "Caron";
				ch.name = TranslateString("","Elbaron");
				ch.lastname = TranslateString("","Caron");
				SetModelfromArray(ch, GetModelIndex("50M5"));
			}
			else
			{
				DeleteAttribute(ch, "questchar");
				SetRandomNameToCharacter(ch);
			}
		break;

		case PLAYER_TYPE_MERCHANT:
			if (GetMySimpleOldName(PChar) == "Cutler Beckett" && PChar.model == "Cutler_Beckett")
			{
    				ch = CharacterFromID("Malcolm Hatcher");
    				ch.name = TranslateString("","Lieutenant");
    				ch.lastname = TranslateString("","Bligh");
    				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
    				SetModelfromID(ch, "Eitc_lt1_47");
				SetRankTitle(PChar, TranslateString("", "Lord"));
				PChar.knighted = ENGLAND;
			}
		break;

		case PLAYER_TYPE_SWORD_MASTER:
			if (GetMySimpleOldName(PChar) == "Bohdan Aleskeevich Voronov" && iNation == PERSONAL_NATION)
			{
				ch.old.name = "Taras";
				ch.old.lastname = "Bulba";
				ch.name = TranslateString("","Taras");
				ch.lastname = TranslateString("","Bulba");
				SetModelfromID(ch, "mongol");
			}

			if (GetMySimpleOldName(PChar) == "Will Turner")
			{
				if(PChar.model == "will")
				{
    					ch.nation = iNation;
    					ch.Dialog.Filename = "Robert Fletcher_dialog.c";
    					ch.name = TranslateString("","John");
    					ch.lastname = "Brown";
					ch.greeting = "Gr_Edgar Attwood";
    					SetModelfromID(ch, "old_man2");
				}
				if(PChar.model == "WillTurner2")
				{
    					ch.nation = iNation;
    					ch.Dialog.Filename = "Robert Fletcher_dialog.c";
    					ch.name = TranslateString("","Bootstrap Bill");
    					ch.lastname = TranslateString("", "Turner");
    					SetModelfromID(ch, "BootstrapBill");
				}
			}
		break;

		case PLAYER_TYPE_SMUGGLER:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			switch(GetMySimpleOldName(PChar))
			{
				case "Anamaria":
					SetModelFromID(ch, "OldWoman1");
					ch.name = TranslateString("","Mother");
					ch.greeting = "Gr_Ines Diaz";
					ch.lastname = "";
					ch.keepmodel = true;
				break;
				SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_BOATSWAIN, "man", PIRATE)));
				DeleteAttribute(ch, "questchar");
				SetRandomNameToCharacter(ch);
			}
		break;

		case PLAYER_TYPE_ADVENTURER:
			switch(GetMySimpleOldName(PChar))
			{
				case "Danielle Greene":
					if (HasSubstr(PChar.model, "daniell"))
					{
						SetOfficersIndex(PChar, 1, GetCharacterIndex("RalphFawn"));
					}
				break;
				case "Purpure":
					if (HasSubstr(PChar.model, "Purpure"))
					{
						ch = CharacterFromID("Malcolm Hatcher");
						ch.Dialog.Filename = "Robert Fletcher_dialog.c";
						SetModelFromID(ch, "man8");
						ch.name = TranslateString("","Uncle");
						ch.lastname = TranslateString("","Gules");
						ch.keepmodel = true;
						if (GetDataYear() == 1830) SetCurrentDate(GetDataDay(), GetDataMonth(), 1840);
						PChar.quest.remove_hatcher = true;
					}
				break;
			}
		break;

		case PLAYER_TYPE_AGENT:
			// Admiral
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			if (GetMySimpleOldName(PChar) == "Jean Lafitte" && GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
				iNation = AMERICA;
			if (PChar.model == "Milady") GiveModel2Player("Milady2",false);
			if (PChar.model == "Milady2") GiveModel2Player("Milady",false);														// Encourage play for America
			ch.nation = iNation;
			DeleteAttribute(ch, "questchar");
			SetRandomNameToCharacter(ch);
			ch.professionalnavy = iNation;
			SetRank(ch, iNation, 7); // GR: was 12, which would be the chief of the entire navy sitting at a desk in the nation's capital!
			switch(iNation)
			{
				case ENGLAND:
					SetRankTitle(ch, TranslateString("", "Sir"));
					SetModelfromArray(ch, GetModelIndex("brtadm2_18"));
				break;
				case FRANCE:
					SetModelfromArray(ch, GetModelIndex("fra_cpt2_18"));
					SetRankTitle(ch, TranslateString("", "Chevalier"));
					if (GetMySimpleOldName(PChar) == "Milady de Winter")
					{
						SetModelfromArray(ch, GetModelIndex("Maltese"));
						ch.old.name = "Cardinal";
						ch.old.lastname = "Richelieu";
						ch.name = TranslateString("","Cardinal");
						ch.lastname = TranslateString("","Richelieu");
						PChar.reputation = REPUTATION_HORROR;
						DeleteAttribute(ch, "nations."+ ch.professionalnavy + ".Rank");
						DeleteAttribute(ch, "professionalnavy");
						DeleteAttribute(ch, "Title");
					}
					if (GetMySimpleOldName(PChar) == "Comte de Rochefort")
					{
						SetModelfromArray(ch, GetModelIndex("Cardinal"));
						ch.old.name = "Cardinal";
						ch.old.lastname = "Mazarin";
						ch.name = TranslateString("","Cardinal");
						ch.lastname = TranslateString("","Mazarin");
						DeleteAttribute(ch, "nations."+ ch.professionalnavy + ".Rank");
						DeleteAttribute(ch, "professionalnavy");
						DeleteAttribute(ch, "Title");
					}
				break;
				case SPAIN:
					SetRankTitle(ch, TranslateString("", "Don"));
					SetModelfromArray(ch, GetModelIndex("spa_adm_18"));
				break;
				case HOLLAND:
					SetModelfromArray(ch, GetModelIndex("Gherarde_De_Jongh"));
				break;
				case PORTUGAL:
					SetRankTitle(ch, TranslateString("", "Dom"));
					SetModelfromArray(ch, GetModelIndex("admiral"));
				break;
				case AMERICA:
					SetModelfromArray(ch, GetModelIndex("USA_adm_18"));
				break;
				case PIRATE:
					SetModelfromArray(ch, GetModelIndex("CaptainTeague"));
					ch.old.name = "Teague";
					ch.old.lastname = "Sparrow";
					ch.name = TranslateString("","Teague");
					ch.lastname = TranslateString("","Sparrow");
				break;
				case PERSONAL_NATION:
					SetModelfromArray(ch, GetModelIndex("hadoque"));
					ch.old.name = "François";
					ch.old.lastname = "de Hadoque";
					ch.name = TranslateString("","François");
					ch.lastname = TranslateString("","de Hadoque");
				break;
			}
		break;

		case PLAYER_TYPE_CURSED:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			string curse_type = "general";
			if(CheckCharacterItem(PChar, "Davy_Chest")) curse_type = "DavyJones";
			if(CheckCharacterItem(PChar, "Devil_Contract")) curse_type = "Orellana";
			switch(curse_type)
			{
				case "DavyJones":
					SetModelfromArray(ch, GetModelIndex("Hadras"));
					ch.old.name = "Hadras";
					ch.old.lastname = "";
					ch.name = TranslateString("","Hadras");
					ch.lastname = "";

					SetModelFromID(CharacterFromID("Crewmember_01"), "Palafico");
					Characters[GetCharacterIndex("Crewmember_01")].name = TranslateString("", "Palafico");
					SetModelFromID(CharacterFromID("Crewmember_02"), "Penrod");
					Characters[GetCharacterIndex("Crewmember_02")].name = TranslateString("", "Palafico");
					SetModelFromID(CharacterFromID("Crewmember_03"), "Maccus");
					Characters[GetCharacterIndex("Crewmember_03")].name = TranslateString("", "Maccus");
					SetModelFromID(CharacterFromID("Crewmember_04"), "Hadras");
					Characters[GetCharacterIndex("Crewmember_04")].name = TranslateString("", "Hadras");
					SetModelFromID(CharacterFromID("Crewmember_05"), "davy5");
				break;

				case "Orellana":
					SetModelfromArray(ch, GetModelIndex("priest_inq"));
					ch.name = TranslateString("","Mephistopheles");
					ch.lastname = "";
					PChar.reputation = REPUTATION_HORROR;
				break;

				// Default
				if (PChar.ship.type == SHIP_CURSED) GiveShip2Character(PChar,"BlackPearl",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true); // So you can actually lift the curse
				locations[FindLocation("Grotto")].box1.items.cursedcoin = 0;
				TutDeck.WeaponsLocker.items.cursedcoin = GetCursedCoinCount() - 1 - GetDifficulty()*2;

				// Ragetti
				if (GetMySimpleOldName(PChar) == "Hector Barbossa")
				{
					SetModelfromID(ch, "pirat4");
					ch.old.name = "Twigg";
					ch.old.lastname = "";
					ch.name = TranslateString("","Twigg");
					ch.lastname = "";
				}
				else
				{
					SetModelfromArray(ch, GetModelIndex("BadV"));
					DeleteAttribute(ch, "questchar");
					SetRandomNameToCharacter(ch);
				}
			}
		break;

		case PLAYER_TYPE_CORSAIR:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.nation = iNation;
			if (NationNoIsland(iNation, GetCurrentPeriod()))
			{
				SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_BOATSWAIN, "man", iNation)));
				DeleteAttribute(ch, "questchar");
				SetRandomNameToCharacter(ch);
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			}

			switch(GetMySimpleOldName(PChar))
			{
				case "Blackbeard":
					if(PChar.model == "Blackbeard")
					{
    						ch.Dialog.Filename = "Robert Fletcher_dialog.c";
    						ch.name = TranslateString("", "Black Caesar");
						ch.lastname = "";
   						SetModelfromID(ch, "napitan");
						ch.greeting = "Gr_QC citizen";
						PChar.reputation = REPUTATION_SWINDLER;
					}
				break;

				case "Eduardo Villanueva":
					if(PChar.model == "Villanueva")
					{
    						ch.Dialog.Filename = "Robert Fletcher_dialog.c";
						SetModelfromID(ch, "blackman");
    						ch.name = TranslateString("", "Mateo");
    						ch.lastname = TranslateString("", "Enrique");
						ch.greeting = "Gr_qc citizen";
						PChar.reputation = REPUTATION_RASCAL;
					}
				break;

				case "Capitaine Chevalle":
					if(PChar.model == "captaine_chevalle")
					{
   						SetModelfromArray(ch, GetModelIndex("black_corsair"));
    						ch.name = TranslateString("", "Raoul");
    						ch.lastname = TranslateString("", "Dupont");
						ch.greeting = "Gr_thierry bosquet";
						PChar.reputation = REPUTATION_RASCAL;
					}
				break;

				case "Sumbhajee Angria":
					if(PChar.model == "sri_sumbhajee")
					{
   						SetModelfromArray(ch, GetModelIndex("sri_sumbhajee_aid"));
    						ch.name = TranslateString("", "Askay");
    						ch.lastname = "";
						ch.greeting = "Gr_Toff oremans";
						PChar.reputation = REPUTATION_RASCAL;
						SetRankTitle(PChar, TranslateString("", "Sri"));
					}
				break;

				case "Sao Feng":
					if(PChar.model == "saofeng")
					{
    						ch.Dialog.Filename = "Robert Fletcher_dialog.c";
   						SetModelfromArray(ch, GetModelIndex("saofeng_guard"));
    						ch.name = TranslateString("", "Lian");
    						ch.lastname = "";
						ch.greeting = "Gr_f_officer_English";
						PChar.reputation = REPUTATION_RASCAL;
					}
				break;
			}
		break;

		case PLAYER_TYPE_CASTAWAY:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			switch(GetMySimpleOldName(PChar))
			{
				case "Black Caesar":
					if(PChar.model == "BlackCaesar")
					{
   						SetModelfromArray(ch, GetModelIndex("Sailor19"));
						ch.nation = ENGLAND;
						DeleteAttribute(ch, "questchar");
						SetRandomNameToCharacter(ch);
						ch.greeting = "Gr_Maxwell";
						ch.keepmodel = true;
					}
				break;
				DeleteAttribute(ch, "questchar");
				SetRandomNameToCharacter(ch);
				SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, "Captains", "man", iNation)));
			}
		break;

		case PLAYER_TYPE_ENGINEER:
			Pchar.portugize_phase = 0;
			Pchar.sakharine_phase = 0;
			Pchar.perks.list.Gunman = true;	
			Pchar.perks.list.GunProfessional = true;
			Locations[FindLocation("New_cloister_inside")].reload.l5.disable = false;		//inner yard to library
			Locations[FindLocation("New_cloister_inside")].locators_radius.reload.reload5 = 0.001;	//small until map is given
			Pchar.monastary = "Ivan_Sakharine";							//Cartagena citizens inform about the New Cloister

			pchar.quest.monk_map_talk.win_condition.l1 = "locator";
			pchar.quest.monk_map_talk.win_condition.l1.location = "New_cloister_inside";
			pchar.quest.monk_map_talk.win_condition.l1.locator_group = "sit";
			pchar.quest.monk_map_talk.win_condition.l1.locator = "sit1";
			pchar.quest.monk_map_talk.win_condition = "monk_map_talk";
		
			Pchar.quest.port_mech.win_condition.l1 = "item";
			Pchar.quest.port_mech.win_condition.l1.character = Pchar.id;
			Pchar.quest.port_mech.win_condition.l1.item = "port_mechanism";
			Pchar.quest.port_mech.win_condition = "check_portugize_parts";

			Pchar.quest.port_tools.win_condition.l1 = "item";
			Pchar.quest.port_tools.win_condition.l1.character = Pchar.id;
			Pchar.quest.port_tools.win_condition.l1.item = "port_tools";
			Pchar.quest.port_tools.win_condition = "check_portugize_parts";

			pchar.quest.library_bars1.win_condition.l1 = "locator";
			pchar.quest.library_bars1.win_condition.l1.location = "New_cloister_library";
			pchar.quest.library_bars1.win_condition.l1.locator_group = "quest";
			pchar.quest.library_bars1.win_condition.l1.locator = "bars1";
			pchar.quest.library_bars1.win_condition = "library_bars1";

			pchar.quest.library_bars2.win_condition.l1 = "locator";
			pchar.quest.library_bars2.win_condition.l1.location = "New_cloister_library";
			pchar.quest.library_bars2.win_condition.l1.locator_group = "quest";
			pchar.quest.library_bars2.win_condition.l1.locator = "bars2";
			pchar.quest.library_bars2.win_condition = "library_bars2";
		break;
	}

	TakeNItems(PChar, "medical1", 2); // PB

	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}

	//NK -->
	PChar.Ship.HP = MakeInt(GetCharacterShipHP(PChar) * 3 / 5);
	PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) * 3/5);
	PChar.Ship.SP = MakeInt(GetCharacterShipSP(PChar) * 4 / 5); // MAXIMUS interface MOD
	// to fix the good overup stuff 05-04-06 NK -->
	string goods_id;
	for(int n=0; n<GOODS_QUANTITY; n++)
	{
		if(!CheckAttribute(Goods[n],"name")) continue;
		goods_id = Goods[n].name;
		PChar.Ship.Cargo.Goods.(goods_id) = 0;
	}
	// NK <--
	int space = GetCargoMaxSpace(PChar); // MAXIMUS interface MOD // KK

// KK -->

// Levis: moved up so we can determine the cargo for the new port
	string cabinID = GetCharacterShipCabin(PChar);
	rldGroup = "rld";
	rldLocator = "startloc";
	if (cabinID != "Cabin_none") {
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);

		TutDeck.models.always.l2 = "cabinchest";		//JRH
		TutDeck.models.always.l3 = "trunk";				//JRH

		if (cabinID != "Tutorial_Deck") TutDeck.items.randitem1 = "";
	} else {
		if (CheckAttribute(ch, "keepmodel")) DeleteAttribute(ch, "keepmodel");
		else SetModelFromID(ch, "Corsair5");
		iShipCaptain = sti(ch.index);
		SetUpCabin(GetCharacter(iShipCaptain));
		rldGroup = "reload";
		rldLocator = "reload1";
	}

	string rldLocator_Port = "";

	if (CharPlayerType == PLAYER_TYPE_REBEL)			iNation = PIRATE;					// Traitors start at Nevis
	if (NationNoIsland(iNation, GetCurrentPeriod()))	iNation = PIRATE;					// Need some place to start

	switch(iNation)
	{
		case ENGLAND:
			loadPort = "Oxbay_port";
			rldLocator_Port = "reload2";
			CharStore = OXBAY_STORE; //PW set store for price of goods put on ship
		break;
		case FRANCE:
			loadPort = "Falaise_de_fleur_port_01";
			rldLocator_Port = "sea";
			CharStore = FALAISE_DE_FLEUR_STORE; //PW set store for price of goods put on ship
		break;
		case SPAIN:
			loadPort = "Muelle_port";
			rldLocator_Port = "reload3";
			CharStore = ISLA_MUELLE_STORE; //PW set store for price of goods put on ship
		break;
		case PIRATE:
			loadPort = "QC_port";
			rldLocator_Port = "reload1";
			CharStore = PIRATES_STORE; //PW set store for price of goods put on ship
		break;
		case HOLLAND:
			loadPort = "Douwesen_port";
			rldLocator_Port = "reload2";
			CharStore = DOUWESEN_STORE; //PW set store for price of goods put on ship
		break;
		case PORTUGAL:
			loadPort = "Conceicao_port";
			rldLocator_Port = "reload2";
			CharStore = CONCEICAO_STORE; //PW set store for price of goods put on ship
		break;
		case AMERICA:
			loadPort = "Eleuthera_Port";
			rldLocator_Port = "reload1_back";
			CharStore = ELEUTHERA_STORE; //PW set store for price of goods put on ship
		break;
		case PERSONAL_NATION:
			loadPort = "Oxbay_port";
			rldLocator_Port = "reload2";
			CharStore = OXBAY_STORE; //PW set store for price of goods put on ship
		break;
	}

	string ship_deck = "";
	if (cabinID != "Cabin_none")
		ship_deck = GetCharacterShipQDeck(PChar);
	else
	{
		ship_deck = GetCharacterShipQDeck(ch);
		ch.nation = GetCurrentFlag();			// PB: Just for fun
		SetCharacterShipLocation(ch, loadPort);	// PB: Just for fun
	}
	Locations[loc].reload.l1.go = ship_deck;
	Locations[loc].reload.l1.emerge = "reload1";
	Locations[FindLocation(ship_deck)].reload.l4.go = loadPort;
	Locations[FindLocation(ship_deck)].reload.l4.emerge = rldLocator_Port;
	Locations[FindLocation(ship_deck)].reload.l4.disable = 1;
	Locations[FindLocation(ship_deck)].reload.l5.go = loadPort;
	Locations[FindLocation(ship_deck)].reload.l5.emerge = rldLocator_Port;
	Locations[FindLocation(ship_deck)].reload.l5.disable = 1;
	// PB: Can we CreatePortLandscape for the tutorial?

	trace("Made change of cabin and deck parameters for "+CharShipType);
// <-- KK

// added by MAXIMUS [gunpowder mod] -->
	// fixed 05-04-06 to use makeint() -->
	int loadBalls = makeint(GetCannonQuantity(PChar)*BALLS_PER);
	int loadGrapes = makeint(GetCannonQuantity(PChar)*GRAPE_PER);
	int loadChain = makeint(GetCannonQuantity(PChar)*CHAIN_PER);
	int loadBombs = makeint(GetCannonQuantity(PChar)*BOMBS_PER*(!USE_REAL_CANNONS));
	int loadWheat = makeint(sti(PChar.ship.crew.quantity) * FOOD_PER_CREW * WHEAT_DAYS * 1.5);	// PB: Jamaica is pretty far with the new Worldmap
	int loadRum = makeint(sti(PChar.ship.crew.quantity) * FOOD_PER_CREW * RUM_DAYS * 1.5);		// PB: And refitting your ship takes 15 days

	int loadGunpowder = makeint(GetCannonQuantity(PChar) * GetCannonChargesPerCannon(PChar)) * CANNONPOWDER_MOD;
	if (loadGunpowder < 0) loadGunpowder = 0;
	loadGunpowder *= (BALLS_PER + GRAPE_PER + CHAIN_PER + BOMBS_PER*(!USE_REAL_CANNONS));

	int loadCargo = GetGoodWeightByType(GOOD_BALLS, loadBalls) + GetGoodWeightByType(GOOD_GRAPES, loadGrapes) + GetGoodWeightByType(GOOD_KNIPPELS, loadChain) + GetGoodWeightByType(GOOD_BOMBS, loadBombs) + GetGoodWeightByType(GOOD_WHEAT, loadWheat) + GetGoodWeightByType(GOOD_RUM, loadRum) + GetGoodWeightByType(GOOD_GUNPOWDER, loadGunpowder);

	if (space < loadCargo) {
		int cargo_count = makeint((loadBalls > 0) + (loadGrapes > 0) + (loadChain > 0) + (loadBombs > 0) + (loadWheat > 0) + (loadRum > 0));
		if (cargo_count != 0) {
			loadBalls /= cargo_count;
			loadGrapes /= cargo_count;
			loadChain /= cargo_count;
			loadBombs /= cargo_count;
			loadWheat /= cargo_count;
			loadRum /= cargo_count;
			loadGunpowder /= cargo_count;
		}
	}
	SetCharacterGoods(&PChar, GOOD_BALLS, loadBalls);
	SetCharacterGoods(&PChar, GOOD_GRAPES, loadGrapes);
	SetCharacterGoods(&PChar, GOOD_KNIPPELS, loadChain);
	SetCharacterGoods(&PChar, GOOD_BOMBS, loadBombs);
	SetCharacterGoods(&PChar, GOOD_WHEAT, loadWheat);
	SetCharacterGoods(&PChar, GOOD_RUM, loadRum);
	SetCharacterGoods(&PChar, GOOD_GUNPOWDER, loadGunpowder);

	int attempts = 0;
	CharGood1 = 0;
	CharGood2 = 0;
	while(CharGood1 == CharGood2)
	{
		CharGood1 = getRandomImportGood(GetIslandByID(FindIslandByLocation(loadPort)));
		CharGood2 = getRandomImportGood(GetIslandByID(FindIslandByLocation(loadPort)));
		// PB: Keep looping until *valid* goods are found (PW not < type 11)-->
		if (CharGood1 < 11 || CharGood2 < 11 ) CharGood1 = CharGood2;// PW don't really want any "usable" or gold/silver goods
		// PW also added new import goods to some islands to allow non gold/silver to occur)
		//if (CharGood1 == GOOD_SAILCLOTH	|| CharGood2 == GOOD_SAILCLOTH	) CharGood1 = CharGood2;
		//if (CharGood1 == GOOD_PLANKS	|| CharGood2 == GOOD_PLANKS		) CharGood1 = CharGood2;
		//if (CharGood1 == GOOD_WHEAT		|| CharGood2 == GOOD_WHEAT		) CharGood1 = CharGood2;
		//if (CharGood1 == GOOD_RUM 		|| CharGood2 == GOOD_RUM		) CharGood1 = CharGood2;
		//if (CharGood1 == GOOD_GUNPOWDER	|| CharGood2 == GOOD_GUNPOWDER	) CharGood1 = CharGood2;
		// PB: Keep looping until *valid* goods are found (PW not < type 11) <--
		
		attempts++;
		if(attempts > 40) break;
	}
	
	/*if (CharGood1 == GOOD_SAILCLOTH || CharGood1 == GOOD_PLANKS) 	CharGood1 = GOOD_SILK;
	if (CharGood1 == GOOD_WHEAT || CharGood1 == GOOD_RUM) 			CharGood1 = GOOD_SILK;
	if (CharGood2 == GOOD_SAILCLOTH || CharGood2 == GOOD_PLANKS) 	CharGood2 = GOOD_WINE;
	if (CharGood2 == GOOD_WHEAT || CharGood2 == GOOD_RUM) 			CharGood2 = GOOD_WINE;*/

// ---->PW altered to take weight into account
	//space -= loadCargo;
	int lessCargo;
	space = GetCargoFreeSpace(PChar);
	float cargo_div = Rand(100)/100.0;
	
	loadCargo = 1 + makeint(cargo_div*100);//PW 
	if (CharGood1 == CharGood2) loadCargo = 200; // PW if earlier while loop ran out and left them =
	lessCargo = loadCargo;
	if (GetGoodWeightByType(CharGood1, loadCargo) > space) 
	{
	lessCargo = space  * loadCargo ;
	lessCargo /= GetGoodWeightByType(CharGood1, loadCargo);
	}
	SetCharacterGoods(&PChar, CharGood1, lessCargo);
	space = GetCargoFreeSpace(PChar);
	loadCargo = 200 - lessCargo
	lessCargo = loadCargo;
	if (GetGoodWeightByType(CharGood2, loadCargo) > space) 
	{
	lessCargo = space  * loadCargo ;
	lessCargo /= GetGoodWeightByType(CharGood2, loadCargo);
	}
	SetCharacterGoods(&PChar, CharGood2, lessCargo);
	
//<------PW end altered to take weight into account

// by this section we are adding money to character (if he has a unsufficiently sum for ship's repair and crew's hiring) -->
// -----> PW repair and crew cost moved up so it can help prevent extreme cargo values
	int sailCostPercent = 20;
	int hullCostPercent = 40;
	aref arCurShip; makearef(arCurShip, PChar.ship);
	int shipPrice = sti(GetLocalShipAttrib(arCurShip, GetCharacterShipType(PChar), "Price"));
	int hireQty = makeint(GetMaxCrewQuantity(PChar) - GetCrewQuantity(PChar));

	int hireCost = sti(GetCrewHireCost(PChar) * hireQty);

	int hcost = MakeInt(makeint((((shipPrice*hullCostPercent+99)/100)*makeint(100 - MakeInt(GetHullPercent(PChar)))+99)/100));
	int scost = MakeInt((makeint((shipPrice*sailCostPercent+99)/100)*makeint(100 - MakeInt(GetSailPercent(PChar)))+99)/100);

	int repCost = hcost + scost;

// <---- PW end section moved up
// ---> PW calc changed to match in store price received 12/2016
	ref sto; makeref(sto, Stores[CharStore]);


	int Quantity = GetCargoGoods(PChar,CharGood1);
	int p = 0; int j;
	for(j=0;j<Quantity;j++)
		{
		if (p > (repCost + hireCost)) // check if value > repair cost
			{
			SetCharacterGoods(&PChar, CharGood1, j);// if yes stop at this quantity
			break;	
			}
		p += makeint(GetStoreGoodsPrice(sto, CharGood1, PRICE_TYPE_SELL, PChar, j)); 
		} 
	int cargoPrice1 = p;
	Quantity = GetCargoGoods(PChar,CharGood2);
	p = 0;
	for(j=0;j<Quantity;j++)
		{
		if (p + cargoPrice1 > (repCost + hireCost))//check if value > repair cost
			{
			SetCharacterGoods(&PChar, CharGood2, j);// if yes stop at this quantity
			break;	
			}	
		p += makeint(GetStoreGoodsPrice(sto, CharGood2, PRICE_TYPE_SELL, PChar, j)); 
		} 
	p += cargoPrice1;
// <------- PW calc match store price change end

	float qty = 1;
	switch(Rand(5))
    	{
		case 0: qty = 1.356; break;
		case 1: qty = 1.890; break;
		case 2: qty = 1.674; break;
		case 3: qty = 1.724; break;
		case 4: qty = 1.057; break;
		case 5: qty = 1.532; break;
   	}
// ----> PW revised calculation for adding money to player 
	
 	if (GetCharacterShipClass (PChar) > 4)//PW if <= 4 no cargo/repair balance (=cheat mode anyway)
		{
		if (p < sti(hireCost+repCost)) //if cargo value < repair value
			{
			int addMoney = makeint(sti(hireCost+repCost)-p);// PW add any shortfall
			addMoney += (1000*qty);// add a further 1000 * random qty
			AddMoneyToCharacter(PChar, addMoney);
			}
		else
			{
			p = (500*qty);// add a further 500 * random qty (since don't calc surplus already)
			AddMoneyToCharacter(PChar, p);
			} 
		}	
	else 
		{
		PChar.money = makeint(5000*qty);// TIH fixed decimal gold on cheat start new game
		}
// <---- PW end of revised calculation
// by this section we are adding money to character (if not cheat and he has a unsufficiently sum for ship's repair and crew's hiring) otherwise if cheat random 5000 * qty <--

// added by MAXIMUS [gunpowder mod] <--


	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//

	PChar.quest.StartAdventure.win_condition.l1 = "Timer";
	PChar.quest.StartAdventure.win_condition.l1.date.day = GetAddingDataDay(0, 0, 0);
	PChar.quest.StartAdventure.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	PChar.quest.StartAdventure.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
	PChar.quest.StartAdventure.win_condition = "StartAdventure";

	PChar.quest.Tut_start.win_condition.l1 = "location";
	PChar.quest.Tut_start.win_condition.l1.character = PChar.id;
	PChar.quest.Tut_start.win_condition.l1.location = "Tutorial_Deck";
	PChar.quest.Tut_start.win_condition = "Tut_start";

	// PB: Started Later -->
	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");
	// PB: Started Later <--

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators
	PChar.location.first = true;
	PChar.vcskip = true; // PB: To prevent random characters until AFTER the tutorial

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// Level
	ref rModel;
	makeref(rModel, Models[GetModelIndex(PChar.model)]);
	int i;
	int PlayerLevel = sti(PChar.rank);
	int ModelLevel  = GetAttribute(rModel, "minlevel");
	if (ModelLevel > PlayerLevel)
	{
		for (i = PlayerLevel; i < ModelLevel; i++)
		{
			LevelUp_Cheat(PChar, 1);
		}
	}

	// DeathDaisy: Modify regent/monarch names
	// EARLY EXPLORERS
	// England
	if(GetDataYear() >= 1500)
	{
		Periods[GetCurrentPeriod()].Royal.England.Name = "Henry VII";
		Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("His Royal Majesty");
		if(GetDataYear() > 1509 && GetDataYear() < 1547) Periods[GetCurrentPeriod()].Royal.England.Name = "Henry VIII";
		if(GetDataYear() >= 1547 && GetDataYear() <= 1553) Periods[GetCurrentPeriod()].Royal.England.Name = "Edward VI";
		if(GetDataYear() > 1553 && GetDataYear() <= 1558)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "Mary I";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Her Royal Majesty");
		}
		if(GetDataYear() > 1558 && GetDataYear() < 1603)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "Elizabeth I";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Her Royal Majesty");
		}
	}
	// Spain
	if(GetDataYear() >= 1500)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Fernando II";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
		if(GetDataYear() > 1504 && GetDataYear() <= 1516)
		{
			Periods[GetCurrentPeriod()].Royal.Spain.Name = "Juana I";
			Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("Her Most Catholic Majesty");
		}
		if(GetDataYear() > 1516 && GetDataYear() <= 1556) Periods[GetCurrentPeriod()].Royal.Spain.Name = "Carlos I";
		if(GetDataYear() > 1556 && GetDataYear() <= 1598) Periods[GetCurrentPeriod()].Royal.Spain.Name = "Felipe II";
		if(GetDataYear() > 1598 && GetDataYear() < 1621) Periods[GetCurrentPeriod()].Royal.Spain.Name = "Felipe III";
	}
	// Portugal
	if(GetDataYear() >= 1500)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Manuel I";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
		if(GetDataYear() > 1521 && GetDataYear() < 1557) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "JoÝo III";
		if(GetDataYear() >= 1557 && GetDataYear() <= 1578) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "SebastiÝo";
		if(GetDataYear() > 1578 && GetDataYear() < 1580) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Henrique";
		if(GetDataYear() == 1580) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "António"; // GR: the crown was in dispute in 1580, and António had support throughout the Portuguese Empire even if he didn't do well at home. 
		if(GetDataYear() > 1580 && GetDataYear() <= 1598) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Felipe I";
		if(GetDataYear() > 1598 && GetDataYear() < 1621) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Felipe II";
	}
	// France
	if(GetDataYear() >= 1500){
		Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XII";
		Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		if(GetDataYear() >= 1515 && GetDataYear() < 1547) Periods[GetCurrentPeriod()].Royal.France.Name = "François";
		if(GetDataYear() >= 1547 && GetDataYear() < 1559) Periods[GetCurrentPeriod()].Royal.France.Name = "Henri II";
		if(GetDataYear() >= 1559 && GetDataYear() <= 1560) Periods[GetCurrentPeriod()].Royal.France.Name = "François II";
		if(GetDataYear() > 1560 && GetDataYear() < 1574) Periods[GetCurrentPeriod()].Royal.France.Name = "Charles IX";
		if(GetDataYear() >= 1574 && GetDataYear() <= 1589) Periods[GetCurrentPeriod()].Royal.France.Name = "Henri III";
		if(GetDataYear() > 1589 && GetDataYear() < 1610) Periods[GetCurrentPeriod()].Royal.France.Name = "Henri IV";
	}
	
	// SPANISH MAIN
	// England
	if(GetDataYear() >= 1603)
	{
		Periods[GetCurrentPeriod()].Royal.England.Name = "James I";
		Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("His Royal Majesty");
		if(GetDataYear() >= 1625 && GetDataYear() < 1649) Periods[GetCurrentPeriod()].Royal.England.Name = "Charles I";
		if(GetDataYear() >= 1649 && GetDataYear() <= 1653)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("The Commonwealth of England");
		}
		if(GetDataYear() > 1653 && GetDataYear() <= 1658)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "Oliver Cromwell";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Lord Protector");
		}
		if(GetDataYear() > 1658 && GetDataYear() <= 1659)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "Richard Cromwell";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Lord Protector");
		}
		if(GetDataYear() > 1659 && GetDataYear() < 1685) Periods[GetCurrentPeriod()].Royal.England.Name = "Charles II";
	}
	// Spain
	if(GetDataYear() >= 1621)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Felipe IV";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
		if(GetDataYear() > 1665 && GetDataYear() <= 1700) Periods[GetCurrentPeriod()].Royal.Spain.Name = "Carlos II";
	}
	// Portugal
	if(GetDataYear() >= 1621)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Felipe III";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
		if(GetDataYear() > 1640 && GetDataYear() <= 1656) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "JoÝo IV";
		if(GetDataYear() > 1656 && GetDataYear() <= 1683) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Alfonso VI";
	}
	// France
	if(GetDataYear() >= 1610)
	{
		Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XIII le Juste";
		Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		if(GetDataYear() >= 1643 && GetDataYear() <= 1715) Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XIV le Grand";
	}
			
	// GOLDEN AGE OF PIRACY
	// England & Great Britain
	if(GetDataYear() >= 1707)
	{
		Periods[GetCurrentPeriod()].Nations.Name.England = "Britain";	// England and Scotland are formally united 
		Periods[GetCurrentPeriod()].Nations.OfficialName.England = "Great Britain";
		Nations[GetNationIDByType(ENGLAND)].Desc = "British";
	}
	if(GetDataYear() >= 1685)
	{
		Periods[GetCurrentPeriod()].Royal.England.Name = "James II";
		Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("His Royal Majesty");
		if(GetDataYear() > 1688 && GetDataYear() <= 1694)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "William II and Mary II";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Their Royal Majesties");
		}
		if(GetDataYear() > 1694 && GetDataYear() < 1702) Periods[GetCurrentPeriod()].Royal.England.Name = "William II";
		if(GetDataYear() >= 1702 && GetDataYear() <= 1714)
		{
			Periods[GetCurrentPeriod()].Royal.England.Name = "Anne of Stuart";
			Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("Her Royal Majesty");
			if(GetDataYear() >= 1707) Periods[GetCurrentPeriod()].Royal.England.Name = "Anne of Great Britain";
		}
		if(GetDataYear() > 1714 && GetDataYear() < 1727) Periods[GetCurrentPeriod()].Royal.England.Name = "George I";
		if(GetDataYear() > 1727 && GetDataYear() <= 1760) Periods[GetCurrentPeriod()].Royal.England.Name = "George II";
	}
	// Spain
	if(GetDataYear() > 1700 && GetDataYear() <= 1746)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Felipe V";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	}
	// Portugal
	if(GetDataYear() > 1683)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Pedro II";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
		if(GetDataYear() > 1706 && GetDataYear() <= 1750) Periods[GetCurrentPeriod()].Royal.Portugal.Name = "JoÝo V";
	}
	// France
	if(GetDataYear() > 1715 && GetDataYear() < 1774)
	{
		Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XV le Bien Aimé";
	}
	
	// COLONIAL POWERS
	// Spain
	if(GetDataYear() > 1746)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Fernando VI";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
		if(GetDataYear() > 1759 && GetDataYear() <= 1788) Periods[GetCurrentPeriod()].Royal.Spain.Name = "Carlos III";
	}
	// England
	if(GetDataYear() > 1760 && GetDataYear() < 1820)
	{
		Periods[GetCurrentPeriod()].Royal.England.Name = "George III";
		Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("His Royal Majesty");
	}
	// Portugal
	if(GetDataYear() > 1750 && GetDataYear() < 1777)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "José I";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
	}
	// REVOLUTIONS
	// Spain
	if(GetDataYear() > 1788 && GetDataYear() < 1808)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Carlos IV";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	}
	// Portugal
	if(GetDataYear() > 1777)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Maria I & Pedro III";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("The Most Faithful Majesties of");
		if(GetDataYear() >= 1786 && GetDataYear() < 1816)
		{
			Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Maria I";
			Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("Her Most Faithful Majesty");
		}
	}
	// France
	if(GetDataYear() >= 1774 && GetDataYear() <= 1792)
	{
		Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XVI";
		Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	}
	// America 
	//DeathDaisy: maybe add later, would be best if it could change to US during play since those who are interested are likely to play during those years
/*	if(GetCurrentPeriod() >= PERIOD_REVOLUTIONS && GetDataYear() < 1776)
	{
		Periods[GetCurrentPeriod()].Nations.Name.America = "Thirteen Colonies";	// DeathDaisy: America is born
		Periods[GetCurrentPeriod()].Nations.OfficialName.America = "Thirteen Colonies";
	} */
	
	// NAPOLEONIC ERA
	// England
	if(GetDataYear() >= 1820)
	{
		Periods[GetCurrentPeriod()].Royal.England.Name = "George IV";
		Periods[GetCurrentPeriod()].Royal.England.Title = XI_ConvertString("His Royal Majesty");
	}
	// Spain
	if(GetDataYear() >= 1808)
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Fernando VII";
		Periods[GetCurrentPeriod()].Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	}
	// Portugal
	if(GetDataYear() >= 1816)
	{
		Periods[GetCurrentPeriod()].Royal.Portugal.Name = "JoÝo VI";
		Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
		if(GetDataYear() > 1826)
		{
			Periods[GetCurrentPeriod()].Royal.Portugal.Name = "Maria II";
			Periods[GetCurrentPeriod()].Royal.Portugal.Title = XI_ConvertString("Her Most Faithful Majesty");
		}
	}
	// France
	if(GetDataYear() > 1792)
	{
		Periods[GetCurrentPeriod()].Royal.France.Name = "";
		Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("Republic of France");
		if(GetDataYear() > 1799 && GetDataYear() < 1804)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Napoléon Bonaparte";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("Premier Consul");
		}
		if(GetDataYear() >= 1804 && GetDataYear() <1814)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Napoléon Bonaparte";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("L'Empereur");
		}
		if(GetDataYear() >= 1814 && GetDataYear() < 1815)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XVIII";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		}
		if(GetDataYear() == 1815)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Napoléon Bonaparte";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("L'Empereur");
		}
		if(GetDataYear() > 1815 && GetDataYear() <= 1824)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Louis XVIII";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		}
		if(GetDataYear() > 1824)
		{
			Periods[GetCurrentPeriod()].Royal.France.Name = "Charles X";
			Periods[GetCurrentPeriod()].Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
		}
	}
	// America
	if(GetDataYear() > 1796)
	{
		Periods[GetCurrentPeriod()].Royal.America.Name = "John Adams";
		Periods[GetCurrentPeriod()].Royal.America.Title = XI_ConvertString("President");
		if(GetDataYear() > 1800 && GetDataYear() <= 1808) Periods[GetCurrentPeriod()].Royal.America.Name = "Thomas Jefferson";
		if(GetDataYear() > 1808 && GetDataYear() <= 1816) Periods[GetCurrentPeriod()].Royal.America.Name = "James Madison";
		if(GetDataYear() > 1816 && GetDataYear() <= 1824) Periods[GetCurrentPeriod()].Royal.America.Name = "James Monroe";
		if(GetDataYear() > 1824) Periods[GetCurrentPeriod()].Royal.America.Name = "John Quincy Adams";
	}
	
	// SWEDEN - gets their own section because they have relatively few regents
	if(SWEDEN_ALLOWED && GetDataYear() >= 1600 && GetDataYear() <= 1769)
	{
		Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Karl IX";
		Periods[GetCurrentPeriod()].Royal.Sweden.Title = XI_ConvertString("King");
		if(GetDataYear() > 1611 && GetDataYear() < 1633) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Gustav II Adolf";
		if (GetDataYear() >= 1633 && GetDataYear() < 1655)
		{
			Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Kristina";
			Periods[GetCurrentPeriod()].Royal.Sweden.Title = XI_ConvertString("Queen");
		}
		if(GetDataYear() >= 1655 && GetDataYear() < 1660) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Karl X Gustav";
		if(GetDataYear() >= 1660 && GetDataYear() < 1698) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Karl XI";
		if(GetDataYear() >= 1698 && GetDataYear() < 1719) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Karl XII";
		if(GetDataYear() >= 1719 && GetDataYear() < 1720)
		{
			Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Ulrika Eleonora";
			Periods[GetCurrentPeriod()].Royal.Sweden.Title = XI_ConvertString("Queen");
		}
		if(GetDataYear() >= 1720 && GetDataYear() < 1751) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Fredrik I";
		if(GetDataYear() >= 1751) Periods[GetCurrentPeriod()].Royal.Sweden.Name = "Adolf Fredrik";
	}

	// PB: Modify Default Relations 
	// EARLY EXPLORERS - DeathDaisy: Wars in the 1500s were confusing (to me) with overlapping wars where realms were allies in some and enemies in some. The wars I chose are kinda arbitrary, but Early Explorers is honestly pretty boring rn, some wars will do it good. wont be mad if changed.
	if(GetDataYear() >= 1500 && GetDataYear() <= 1504){ // DeathDaisy: Italian War of 1499-1504
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_FRIEND);
		if(GetDataYear() > 1501){
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		}
	}
	if(GetDataYear() >= 1508 && GetDataYear() <= 1516){	// DeathDaisy: War of the League of Cambrai
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_FRIEND);
		if(GetDataYear() >= 1511){
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
		}
	}
	if(GetDataYear() >= 1521 && GetDataYear() < 1526){	// DeathDaisy: Italian War of 1521–26
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1526 && GetDataYear() <= 1530){	// DeathDaisy: War of the League of Cognac
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, ENGLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1536 && GetDataYear() <= 1538){	// DeathDaisy: Italian War of 1536-38
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
	}
	if(GetDataYear() >= 1542 && GetDataYear() <= 1546){	// DeathDaisy: Italian War of 1542–46
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1551 && GetDataYear() <= 1559){	// DeathDaisy: Italian War of 1551–59
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		if(GetDataYear() >= 1556){	// DeathDaisy: England joined later
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
		}
	}
	if(GetDataYear() >= 1562 && GetDataYear() <= 1598){	// DeathDaisy: French Wars of Religion
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1580 && GetDataYear() <= 1583){	// DeathDaisy: War of the Portuguese Succession. Portugal had two factions of loyalists, fighting on opposite sides, but the spanish side won, so they are with spain here
		SetNationRelationBoth(SPAIN, ENGLAND, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_FRIEND);
		SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1585 && GetDataYear() < 1602){	// DeathDaisy: Anglo-Spanish War 1585-1604
		SetNationRelationBoth(SPAIN, ENGLAND, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_FRIEND);
		SetNationRelationBoth(PORTUGAL, ENGLAND, RELATION_ENEMY);
		SetNationRelationBoth(PORTUGAL, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_FRIEND);
	}
	
	// THE SPANISH MAIN
	if (GetDataYear() >= 1602 && GetDataYear() <= 1663)	// GR: Dutch-Portuguese War
	{
		SetNationRelationBoth(HOLLAND, PORTUGAL, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, PORTUGAL, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_FRIEND);
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_FRIEND);
		SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
	}

	if (GetDataYear() >= 1618 && GetDataYear() <= 1648)	// GR: Thirty Years War
	{
		SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
		if (GetDataYear() >= 1625 && GetDataYear() <= 1630)
		{
			SetNationRelationBoth(ENGLAND,	SPAIN,	 RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND,	HOLLAND, RELATION_FRIEND);
		}
		if (GetDataYear() >= 1635)
		{
			SetNationRelationBoth(SPAIN,	FRANCE,	RELATION_ENEMY);
			SetNationRelationBoth(HOLLAND,	FRANCE,	RELATION_FRIEND);
		}
		if (SWEDEN_ALLOWED && GetDataYear() >= 1630)
		{
			SetNationRelationBoth(FRANCE,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(HOLLAND,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(SPAIN,	SWEDEN,	RELATION_ENEMY);
		}
	}

	if (GetDataYear() >= 1640 && GetDataYear() <= 1679)	// GR: Iberian Union collapses, Portugal resumes alliance with England
	{
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, PORTUGAL, RELATION_FRIEND);
	}

	if (GetDataYear() >= 1652 && GetDataYear() <= 1654)	// GR: First Anglo-Dutch War
	{
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
	}
	if(GetDataYear() >= 1655 && GetDataYear() <= 1661 && SWEDEN_ALLOWED){	// DeathDaisy: Second Northern War
		SetNationRelationBoth(HOLLAND, SWEDEN, RELATION_ENEMY);
	}		
	if (GetDataYear() >= 1665 && GetDataYear() <= 1667)	// GR: Second Anglo-Dutch War
	{
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, HOLLAND, RELATION_FRIEND);
		if(GetDataYear() == 1666 && SWEDEN_ALLOWED){
			SetNationRelationBoth(HOLLAND, SWEDEN, RELATION_ENEMY);
		}
	}
	if(GetDataYear() >= 1667 && GetDataYear() <= 1668){	// DeathDaisy: War of Devolution
		SetNationRelationBoth(FRANCE, SPAIN, RELATION_ENEMY);
		if(GetDataYear() == 1668){
			SetNationRelationBoth(FRANCE, HOLLAND, RELATION_ENEMY);
			SetNationRelationBoth(FRANCE, ENGLAND, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_FRIEND);
			SetNationRelationBoth(SPAIN, HOLLAND, RELATION_FRIEND);
			SetNationRelationBoth(SPAIN, ENGLAND, RELATION_FRIEND);
			if(SWEDEN_ALLOWED){
				SetNationRelationBoth(FRANCE, SWEDEN, RELATION_ENEMY);
				SetNationRelationBoth(SPAIN, SWEDEN, RELATION_FRIEND);
				SetNationRelationBoth(ENGLAND, SWEDEN, RELATION_FRIEND);
				SetNationRelationBoth(HOLLAND, SWEDEN, RELATION_FRIEND);
			}
		}
	}
	if (GetDataYear() >= 1672 && GetDataYear() <= 1674)	// GR: Third Anglo-Dutch War
	{
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_FRIEND);
		SetNationRelationBoth(FRANCE, HOLLAND, RELATION_ENEMY);
	}
	if (GetMySimpleOldName(PChar) == "Michiel de Ruyter" && iNation == HOLLAND)
	{
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
	}

	if (GetDataYear() >= 1672 && GetDataYear() <= 1678)	// DeathDaisy: Franco-Dutch War 1672-1678
	{
		SetNationRelationBoth(ENGLAND, FRANCE,   RELATION_FRIEND);
		SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_ENEMY);
		SetNationRelationBoth(SPAIN,   HOLLAND,  RELATION_FRIEND);
		SetNationRelationBoth(SPAIN,   PORTUGAL, RELATION_NEUTRAL);
		SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_NEUTRAL);
		SetNationRelationBoth(HOLLAND, PORTUGAL, RELATION_NEUTRAL);
		SetNationRelationBoth(FRANCE, HOLLAND, RELATION_ENEMY);
		if (SWEDEN_ALLOWED)
		{
			SetNationRelationBoth(FRANCE,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(ENGLAND,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(HOLLAND,	SWEDEN,	RELATION_ENEMY);
			SetNationRelationBoth(SPAIN,	SWEDEN,	RELATION_ENEMY);
		}
	}
	if(GetDataYear() == 1679){	// DeathDaisy: Scanian War - Technically started in 75, but kept going after the Franco-Dutch War
		SetNationRelationBoth(HOLLAND, FRANCE, RELATION_ENEMY);
		if(SWEDEN_ALLOWED){
			SetNationRelationBoth(FRANCE, SWEDEN, RELATION_FRIEND);
			SetNationRelationBoth(HOLLAND, SWEDEN, RELATION_ENEMY);
		}
	}
	
	// GOLDEN AGE OF PIRACY
	if(GetDataYear() >= 1683 && GetDataYear() <= 1684){	// DeathDaisy: War of the Reunions
		SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
	}
	if (GetDataYear() >= 1688 && GetDataYear() <= 1697)	// PB: War of the League of Augsburg
	{
		SetNationRelationBoth(ENGLAND, SPAIN,    RELATION_FRIEND);
		SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_ENEMY);
		SetNationRelationBoth(SPAIN,   HOLLAND,  RELATION_FRIEND);
		SetNationRelationBoth(SPAIN,   PORTUGAL, RELATION_NEUTRAL);
		SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_NEUTRAL);
		SetNationRelationBoth(HOLLAND, PORTUGAL, RELATION_NEUTRAL);
		if (SWEDEN_ALLOWED && GetDataYear() <= 1691)
		{
			SetNationRelationBoth(FRANCE,	SWEDEN,	RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(SPAIN,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(HOLLAND,	SWEDEN,	RELATION_FRIEND);
			SetNationRelationBoth(PORTUGAL,	SWEDEN,	RELATION_NEUTRAL);
		}
	}
	if(GetDataYear() >= 1700 && GetDataYear() <= 1721){ // DeathDaisy: Great Northern War etc. No nation on the enemy side is actually in the game, but may as well add some friends. Overlaps with the war of Spanish Succession. 
		if(GetDataYear() == 1700){
			SetNationRelationBoth(HOLLAND, ENGLAND, RELATION_FRIEND);
			if(SWEDEN_ALLOWED) SetNationRelationBoth(HOLLAND, SWEDEN, RELATION_FRIEND);
		}
		if (GetDataYear() >= 1702 && GetDataYear() <= 1714)	// GR: War of Spanish Succession
		{
			SetNationRelationBoth(ENGLAND, SPAIN,    RELATION_ENEMY);
			SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_FRIEND);
			SetNationRelationBoth(SPAIN,   HOLLAND,  RELATION_ENEMY);
			SetNationRelationBoth(SPAIN,   PORTUGAL, RELATION_ENEMY);
			SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_ENEMY);
			SetNationRelationBoth(HOLLAND, PORTUGAL, RELATION_FRIEND);
			if(SWEDEN_ALLOWED)
			{
				SetNationRelationBoth(FRANCE,	SWEDEN,	RELATION_NEUTRAL);
				//SetNationRelationBoth(ENGLAND,	SWEDEN,	RELATION_NEUTRAL);
				SetNationRelationBoth(SPAIN,	SWEDEN,	RELATION_NEUTRAL);
				SetNationRelationBoth(HOLLAND,	SWEDEN,	RELATION_NEUTRAL);
				SetNationRelationBoth(PORTUGAL,	SWEDEN,	RELATION_NEUTRAL);
			}
		}
		if(GetDataYear() >= 1717 && GetDataYear() <= 1720){	// DeathDaisy: War of the Quadruple Alliance
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(SPAIN, ENGLAND, RELATION_ENEMY);
			SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
			SetNationRelationBoth(FRANCE, ENGLAND, RELATION_FRIEND);
			SetNationRelationBoth(FRANCE, HOLLAND, RELATION_FRIEND);
		}
		if(SWEDEN_ALLOWED) SetNationRelationBoth(ENGLAND, SWEDEN, RELATION_FRIEND);
		if(SWEDEN_ALLOWED && GetDataYear() >= 1717 && GetDataYear() <= 1719) SetNationRelationBoth(ENGLAND, SWEDEN, RELATION_ENEMY); // DeathDaisy: England becomes United Kindoms and seems to have switched sides for a few years. I just read a list at wikipedia, so dunno why. subject for change and shaming of me
	}
	if(GetDataYear() >= 1735 && GetDataYear() <= 1737){	// DeathDaisy: Spanish-Portuguese War 1735-37
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_ENEMY);
	}
	// COLONIAL POWERS
	if(GetDataYear() >= 1740 && GetDataYear() <= 1748){	// DeathDaisy: The War of Austrian Succession
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_FRIEND);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
		SetNationRelationBoth(HOLLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(HOLLAND, SPAIN, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, SPAIN, RELATION_FRIEND);
		if(SWEDEN_ALLOWED && GetDataYear() >= 1741 && GetDataYear() <= 1743){
			SetNationRelationBoth(SWEDEN, ENGLAND, RELATION_ENEMY);
			SetNationRelationBoth(SWEDEN, HOLLAND, RELATION_ENEMY);
			SetNationRelationBoth(SWEDEN, FRANCE, RELATION_FRIEND);
			SetNationRelationBoth(SWEDEN, SPAIN, RELATION_FRIEND);
		}
	}
	if(GetDataYear() >= 1756 && GetDataYear() <= 1763){	// DeathDaisy: Seven Years' War
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		if(SWEDEN_ALLOWED && GetDataYear() >= 1757 && GetDataYear() <= 1762){
			SetNationRelationBoth(ENGLAND, SWEDEN, RELATION_ENEMY);
			SetNationRelationBoth(FRANCE, SWEDEN, RELATION_FRIEND);
		}
		if(GetDataYear() >= 1762){
			SetNationRelationBoth(SPAIN, ENGLAND, RELATION_ENEMY);
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_FRIEND);
			SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, ENGLAND, RELATION_FRIEND);
			if(GetDataYear() == 1762 && SWEDEN_ALLOWED){
				SetNationRelationBoth(PORTUGAL, SWEDEN, RELATION_ENEMY);
				SetNationRelationBoth(SPAIN, SWEDEN, RELATION_FRIEND);
			}
		}
	}
	
	// REVOLUTIONS
	if(GetDataYear() >= 1776 && GetDataYear() <= 1777){	// DeathDaisy: Spanish-Portoguese War 1776-77
		SetNationRelationBoth(SPAIN, PORTUGAL, RELATION_ENEMY);
	}
	if (GetDataYear() >= 1780 && GetDataYear() <= 1784)	// GR: Fourth Anglo-Dutch War
	{
		SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, HOLLAND, RELATION_FRIEND);
	}
	if(GetDataYear() >= 1792 && GetDataYear() <= 1797){	// DeathDaisy: War of the First Coalition - a loose coalition against france, where everyone was enemies with france but not necessarily allies with eachother
		SetNationRelationBoth(FRANCE, SPAIN, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, ENGLAND, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, HOLLAND, RELATION_ENEMY);
		SetNationRelationBoth(FRANCE, PORTUGAL, RELATION_ENEMY);
		if(GetDataYear() >= 1795){	// Spain and the dutch republic withdraws
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_NEUTRAL);
			SetNationRelationBoth(FRANCE, HOLLAND, RELATION_NEUTRAL);
		}
		if(GetDataYear() > 1795){	// Spain joins again on france side after some treaty
			SetNationRelationBoth(FRANCE, SPAIN, RELATION_FRIEND);
		}
	}
	// NAPOLEONIC ERA
	if(GetDataYear() >= 1808){	// DeathDaisy: suggestion from Homo Eructus!
		SetNationRelationBoth(SPAIN,FRANCE,RELATION_ENEMY);
		SetNationRelationBoth(ENGLAND, SPAIN,	RELATION_FRIEND); // Homo eructus: moved from 1812
		SetNationRelationBoth(SPAIN, PORTUGAL,	RELATION_FRIEND);
	}
	if (GetDataYear() >= 1812 && GetDataYear() <= 1815)	// GR: War of 1812
	{
		SetNationRelationBoth(ENGLAND, AMERICA,	RELATION_ENEMY);
		//SetNationRelationBoth(SPAIN, AMERICA,	RELATION_NEUTRAL);	// DeathDaisy: from enemy of neutral, suggestion from  // Homo eructus: set as default for the period
		//SetNationRelationBoth(SPAIN, FRANCE,	RELATION_ENEMY); // DeathDaisy: added above at an earlier date, also suggested by Homo eructus
	}

	/*if (GetDataYear() >= 1789 && GetDataYear() <= 1808) // DeathDaisy: out commented since monarch reigns are added as its own thing above
	{
		Periods[GetCurrentPeriod()].Royal.Spain.Name = "Carlos IV";
	}*/
	iNation = GetCurrentFlag();
	SetRelationsAsNation(iNation);																	// Set nations as per selected flag

	int DefaultStart = 2;
	switch(CharPlayerType)
	{
		case PLAYER_TYPE_REBEL:
			if(iRealismMode == 0)			SetRelationsAsNation(PERSONAL_NATION);					// Don't keep original nation relations on Arcade Game Mode
			if(iNation == PERSONAL_NATION)	iNation = iNation = rand(NATIONS_QUANTITY-1);			// Make sure you do have an enemy!
			if(iNation != PIRATE)			SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);			// You saved a group of pirates from torture and death
			SetRMRelation(PChar, iNation, REL_MIN);													// You are a traitor to the crown
			HoistFlag(PIRATE);																		// Make port at Nevis, so should hoist pirate flag
			SetServedNation(PERSONAL_NATION);														// Prevent traitor behaviour at game start
			DefaultStart = 0;																		// Already start as pirate, so skip the extra check later
		break;

		case PLAYER_TYPE_NAVAL_OFFICER:
			if(ProfessionalNavyNation() != UNKNOWN_NATION)
			{
				// Rank
				int PlayerRank = 3;																	// If commissioned, Lieutenant (=default)
				if (GetAttribute(rModel, "minrank") > 0)	PlayerRank = sti(rModel.minrank);

				// Promotion
				if(PlayerRank == 1) GivePromotionReward(iNation);									// PB: For Midshipmen
				for (i = 0; i < PlayerRank-1; i++)
				{
					Promote_Cheat(PChar, iNation);
				}
			}
			DefaultStart = 1;																		// Do ensure the pirates are set to friendly, if necessary
		break;

		case PLAYER_TYPE_CORSAIR:
			if (iNation != PIRATE)
			{
				if (GetMySimpleOldName(PChar) == "José Joaquím Almeida" && GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
				{
					iNation = AMERICA;
					SetServedNation(iNation);
					SetRMRelation(PChar, iNation, REL_NEUTRAL);									// Encourage play for America
				}
				else
				{
					SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);									// But are still neutral to the pirates
				}
				SetRank(PChar, iNation, 0);												// Non-pirate corsairs get a Letter of Marque
			}
		break;

		case PLAYER_TYPE_CURSED:
			if(CheckCharacterItem(PChar, "Davy_Chest"))	Nations_SetAllHostile();					// Hostile to everybody
			DefaultStart = 0;																		// Have to remain hostile to everyone, so skip the extra check later
		break;
	}

	switch(GetMySimpleOldName(PChar))
	{
		case "Sumbhajee Angria":
			if(PChar.model == "sri_sumbhajee")
			{
				officer = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Sri_Sumbhajee_aid", 3, PIRATE, false);
				officer.name = TranslateString("", "Pusasn");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade31");
				GiveItem2Character(officer, "pistol7");
				if (ENABLE_AMMOMOD)
				{
					TakenItems(officer, "gunpowder", 3 + rand(3));
					TakenItems(officer, "pistolbullets", 3 + rand(3));
				}
				officer.greeting = "Gr_Toff Oremans";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 2, GetCharacterIndex(officer.id));
			}
		break;

		case "Sao Feng":
			if(PChar.model == "saofeng")
			{
				officer = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "saofeng_guard", 3, PIRATE, false);
				officer.name = TranslateString("", "Lian");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade20");
				TakenItems(officer, "medical1", 4);
				officer.greeting = "Gr_Woman_English Citizen";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 1, GetCharacterIndex(officer.id));

				officer = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "saofeng_guard", 3, PIRATE, false);
				officer.name = TranslateString("", "Park");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				officer.lastname = "";
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade20");
				TakenItems(officer, "medical1", 4);
				officer.greeting = "Gr_Woman_English Citizen";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 2, GetCharacterIndex(officer.id));

				officer = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "mongol", 3, PIRATE, false);
				officer.name = TranslateString("","Tai");
				officer.lastname = TranslateString("","Huang");
				officer.reputation = REPUTATION_RASCAL;
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade27");
				GiveItem2Character(officer, "piratespistol");
				if (ENABLE_AMMOMOD)
				{
					TakenItems(officer, "gunpowder", 1 + rand(2));
					TakenItems(officer, "pistolbullets", 1 + rand(2));
				}
				officer.greeting = "Gr_QC citizen";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 3, GetCharacterIndex(officer.id));
				PChar.quest.remove_hatcher = true;
			}
		break;

		case "Hector Barbossa":
			if(PChar.model == "Barbossa")
			{
				officer = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "Ragetti", 3, PIRATE, false);
				officer.name = TranslateString("", "Ragetti");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				officer.lastname = "";
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade4");
				GiveItem2Character(officer, "jerkin");
				if(CharPlayerType == PLAYER_TYPE_CURSED) GiveItem2Character(officer, "cursedcoin");
				officer.greeting = "Gr_douwesen pirate";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 1, GetCharacterIndex(officer.id));

				officer = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "pintel", 3, PIRATE, false);
				officer.name = TranslateString("", "Pintel");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				officer.lastname = "";
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade4");
				GiveItem2Character(officer, "pistol1");
				if (ENABLE_AMMOMOD)
				{
					TakenItems(officer, "gunpowder", 3 + rand(3));
					TakenItems(officer, "pistolbullets", 3 + rand(3));
				}
				if(CharPlayerType == PLAYER_TYPE_CURSED) GiveItem2Character(officer, "cursedcoin");
				officer.greeting = "Gr_douwesen pirate";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 2, GetCharacterIndex(officer.id));

				officer = CreateOfficer_Cheat(OFFIC_TYPE_BOATSWAIN, "BlackCaesar", 3, PIRATE, false);
				officer.name = TranslateString("", "Bo'sun");
				officer.lastname = "";
				officer.reputation = REPUTATION_RASCAL;
				officer.lastname = "";
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade4");
				GiveItem2Character(officer, "jerkin");
				if(CharPlayerType == PLAYER_TYPE_CURSED) GiveItem2Character(officer, "cursedcoin");
				officer.greeting = "Gr_douwesen pirate";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 3, GetCharacterIndex(officer.id));
			}
		break;

		case "Cutler Beckett":
			if(PChar.model == "Cutler_Beckett")
			{
				officer = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "CivilianHB", 3, ENGLAND, false);
				officer.name = TranslateString("", "Ian");
				officer.lastname = TranslateString("", "Mercer");
				officer.reputation = REPUTATION_SWINDLER;
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				GiveItem2Character(officer, "blade22");
				GiveItem2Character(officer, "piratespistol");
				if (ENABLE_AMMOMOD)
				{
					TakenItems(officer, "gunpowder", 6);
					TakenItems(officer, "pistolbullets", 6);
				}
				officer.greeting = "Gr_seaman";
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 1, GetCharacterIndex(officer.id));
			}
		break;

		case "Black Caesar":
			if(PChar.model == "BlackCaesar")
			{
				ch = CharacterFromID("Malcolm Hatcher");
				officer = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, ch.model, 3, ENGLAND, false);
				officer.name = GetMyName(ch);
				officer.lastname = GetMyLastName(ch);
				officer.reputation = REPUTATION_RASCAL;
				DeleteAttribute(officer, "loyality");
				DeleteAttribute(officer, "alignment");
				DeleteAttribute(officer, "items");
				DeleteAttribute(officer, "equip");
				officer.AbordageMode = 1;
				SetOfficersIndex(PChar, 1, GetCharacterIndex(officer.id));
				officer.greeting = "Gr_Maxwell";
				officer.grsex = "man";
				PChar.quest.remove_hatcher = true;
			}
		break;
	}

	if (DefaultStart > 0 && NationNoIsland(iNation, GetCurrentPeriod()))
	{
		SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);												// You do need some sort of safe base of operation
		if (DefaultStart > 1) SafePortLeave(PIRATE, false);											// Hoist False Flag if Required
	}
}
