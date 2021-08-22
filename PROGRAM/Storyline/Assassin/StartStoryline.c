void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort = "Douwesen_port";
	sTeleportLocName = "Douwesen_port";
// KK -->
	string rldGroup = "reload";
	string rldLocator = "reload1";

	string cabinID = GetCharacterShipCabin(PChar);
	if (cabinID != "Cabin_none")
	{
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);

		Locations[FindLocation("Tutorial_deck")].models.always.l2 = "cabinchest";	//JRH
		Locations[FindLocation("Tutorial_deck")].models.always.l3 = "trunk";		//JRH
	}

	TakeItemFromCharacter(PChar, "commonarmor"); // PB: Override Character Type
	if(CharPlayerType == PLAYER_TYPE_MILITARY && CharNation == HOLLAND) // BOP: Override Character Type
	{
		TakeItemFromCharacter(Pchar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
		GiveItem2Character(PChar, "Blade_ProudOfAnvil");
	}

	TakeNItems(PChar, "spyglass2", 1);
	TakeNItems(PChar, "medical1", 2); // PB
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}
	//JRH ammo mod <--

	EquipCharacterbyItem(Pchar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
	EquipCharacterbyItem(Pchar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
	EquipCharacterbyItem(Pchar, "Spyglass2");
// <-- KK

	Reinit_KhaelRoa();

	Islands[FindIsland("IslaMona")].smuggling_nation = ENGLAND;					// GR: Required for soldiers to be English

//================================| BEGINNING QUESTS |================================//

	//Assassin
	PChar.quest.Assassin = "";
	PChar.quest.Assassin.win_condition.l1 = "location";
	PChar.quest.Assassin.win_condition.l1.character = PChar.id;
	PChar.quest.Assassin.win_condition.l1.location = "Douwesen_port";
	PChar.quest.Assassin.win_condition = "Partida";
	//Assassin

	// PB -->
	DeleteAttribute(PChar, "quest.Hitman");
	DeleteAttribute(PChar, "quest.Hit_start");

	Locations[FindLocation("Muelle_town_01")].reload.l19.label = "House";
	Locations[FindLocation("Muelle_town_01")].reload.l19.go = "";
	Locations[FindLocation("Muelle_town_01")].reload.l19.disable = 1;
	// PB <--

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetNationRelationBoth(ENGLAND, FRANCE,   RELATION_ENEMY);								// Bartolomeu: Required for story
	SetNationRelationBoth(ENGLAND, PORTUGAL, RELATION_FRIEND);								// Bartolomeu: Required for story
	SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_FRIEND);								// Bartolomeu: Required for story
	SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_NEUTRAL);								// Required for story
	SetNationRelationBoth(ENGLAND, HOLLAND,  RELATION_NEUTRAL);								// No Anglo-Dutch war in 1660
	SetRelationsAsNation(GetCurrentFlag());													// Set nations as per selected flag
	if(GetServedNation() == HOLLAND) SetRMRelation(PChar, HOLLAND, REL_AFTERATTACK);		// Bartolomeu: Wary because he's smuggler
	SafePortLeave(HOLLAND, false);
}
