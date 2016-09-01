void StartStoryLine()
{
	ref PChar, ch;
	PChar = GetMainCharacter();
	ch = CharacterFromID("Inquisitor");

	ref TutDeck = &Locations[FindLocation("Tutorial_Deck")];

	aref arstart = GetStorylineStartParams(FindCurrentStoryline());
	string loadPort = arstart.port;
	string rldGroup = "rld";
	string rldLocator = "startloc";
	int loc = FindLocation(arstart.location);

	sTeleportLocName = arstart.location;

	Pchar.skill.Fencing = "2";
	Pchar.perks.list.BasicDefence = true;

	// PB: Override Character Type -->
	TakeItemFromCharacter(Pchar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
	TakeItemFromCharacter(Pchar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
	TakeItemFromCharacter(Pchar, "spyglass2");
	TakeItemFromCharacter(Pchar, "compass2");
	TakeItemFromCharacter(Pchar, "clock1");
	AddMoneyToCharacter(pchar, -1000);
	SetModelfromArray(PChar, GetModelIndex("Animistse"));
	// PB: Override Character Type <--

	PChar.Ship.HP = MakeInt(GetCharacterShipHP(PChar) * 2 / 5);
	PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) * 3/5);
	PChar.Ship.SP = MakeInt(GetCharacterShipSP(PChar) * 1 / 5); //
	PChar.quest.crew_left = PChar.Ship.crew.quantity;

	// NK new location tags 04-08-29
	PChar.newloctags = true;

	string cabinID = GetCharacterShipCabin(PChar);
	if (cabinID != "Cabin_none") {
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);
		if (cabinID != "Tutorial_Deck") TutDeck.items.randitem1 = "";
	} else {
		SetModelFromID(ch, "Corsair5");
		iShipCaptain = sti(ch.index);
		SetUpCabin(GetCharacter(iShipCaptain));
		rldGroup = "reload";
		rldLocator = "reload1";
	}


	// Location Updates
	Island_SetReloadEnableLocal("IslaMona", "reload_1", true);				// May want Isla Mona for this quest.		
	Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;

	Locations[FindLocation("IslaMona_port_exit")].reload.l1.name = "Reload1";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.go = "Quest_Arawak_Village";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.emerge = "Reload1";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.autoreload = "0";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.label = "";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.disable = 0;
	Locations[FindLocation("IslaMona_port_exit")].reload.l4.disable = 1;		// Residence locked
	Locations[FindLocation("IslaMona_port")].reload.l4.disable = 1;				// Head Port house locked
	Locations[FindLocation("IslaMona_port")].reload.l6.disable = 1;				// Warehouse locked
	Locations[FindLocation("IslaMona_passage")].reload.l4.disable = 0;			// Fort opened

	ref lcn = &Locations[FindLocation("IslaMona_fort")];						// Remove big cannons
	for(int i = 1; i<=MAXBUILDINGS; i++)
	{
		if( CheckAttribute(lcn,"building."+i+".building") )
		{
			Building_delete(lcn, "" + i);
		}
	}

	Locations[FindLocation("Hispaniola_Temple")].reload.l2.name = "reload2";	// Open up Hispaniola temple
	Locations[FindLocation("Hispaniola_Temple")].reload.l2.go = "Quest_Hispaniola_Labirint_1";
	Locations[FindLocation("Hispaniola_Temple")].reload.l2.emerge = "reload27";
	Locations[FindLocation("Hispaniola_Temple")].reload.l2.autoreload = "1";

	Locations[FindLocation("IslaMona_port")].townsack = "Khael Roa";
	Locations[FindLocation("IslaMona_port_exit")].townsack = "Khael Roa";
	Locations[FindLocation("IslaMona_passage")].townsack = "Khael Roa";
	Locations[FindLocation("IslaMona_residence")].townsack = "Khael Roa";
	Locations[FindLocation("IslaMona_headport_house")].townsack = "Khael Roa";
	Locations[FindLocation("Fort_Entry")].townsack = "Khael Roa";
	Locations[FindLocation("IslaMona_fort")].townsack = "Khael Roa";

	Towns[GetTownIndex("Khael Roa")].gov = "Wilfred Burman";

	Locations[FindLocation("Redmond_town_03")].reload.l9.name = "Door_14";		// Merchant in Port Royale
	Locations[FindLocation("Redmond_town_03")].reload.l9.go = "Quest_Merchant_House";
	Locations[FindLocation("Redmond_town_03")].reload.l9.emerge = "reload1";
	Locations[FindLocation("Redmond_town_03")].reload.l9.autoreload = "0";
	Locations[FindLocation("Redmond_town_03")].reload.l9.label = "House of Gilbert Downing.";
	Locations[FindLocation("Redmond_town_03")].reload.l9.close_for_night = 1;

	CaptureTownForNation("Khael Roa", PIRATE);

//================================| BEGINNING QUESTS |================================//

	PChar.quest.intro.win_condition.l1 = "location";
	PChar.quest.intro.win_condition.l1.character = PChar.id;
	PChar.quest.intro.win_condition.l1.location = "Tutorial_Deck";
	PChar.quest.intro.win_condition = "intro";

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators
	PChar.location.first = true;

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort);	// KK

	// PB: Modify Default Relations
	SetNationRelationBoth(ENGLAND, SPAIN,    RELATION_FRIEND);		// Relations as for War of the League of Augsburg, 1688 - 1697
	SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_ENEMY);
	SetNationRelationBoth(SPAIN,   HOLLAND,  RELATION_FRIEND);
	SetNationRelationBoth(SPAIN,   PORTUGAL, RELATION_NEUTRAL);
	SetRelationsAsNation(GetCurrentFlag());							// Set nations as per selected flag

}