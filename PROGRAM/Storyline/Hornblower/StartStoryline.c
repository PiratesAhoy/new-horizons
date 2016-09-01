void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort  = "Antigua_port";
	sTeleportLocName = "Antigua_port";
// KK -->
	string rldGroup = "reload";
	string rldLocator = "sea_2";

	// PB: Override Character Type -->
	DeleteAttribute(PChar, "items");
	GiveItem2Character(PChar, "map");
	DeleteAttribute(PChar, "shiplog");
	// PB: Override Character Type <--

	GiveItem2Character(Pchar, "bladeX4");	// PB: Gives you your fists
	TakeNItems(PChar, "blade1", 1);
	TakeNItems(PChar, "pistol1", 1);
	TakeNItems(PChar, "spyglass2", 1);
	TakeNItems(PChar, "medical1", 2); // PB
	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	TakeNItems(PChar, "clock1",1); // SJG
	TakeNItems(PChar, "compass3",1); //SJG
	GiveItem2Character(pchar, "relationbook"); // PB: Relations Tutorial

	EquipCharacterbyItem(Pchar, "blade1");
	EquipCharacterbyItem(Pchar, "pistol1");
	EquipCharacterbyItem(Pchar, "Spyglass2");
	EquipCharacterbyItem(PChar, "clock1"); // SJG
	EquipCharacterbyItem(PChar, "compass3"); //SJG
// <-- KK

// SJG -->
	string BOARDERMODEL = "marine";
	PChar.isnotcaptain = true; // LDH 18Apr09
// <-- SJG

	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//

	//Hornblower
	PChar.quest.Start = "";
	PChar.quest.Start.win_condition.l1 = "location";
	PChar.quest.Start.win_condition.l1.character = PChar.id;
	PChar.quest.Start.win_condition.l1.location = "Antigua_port";
	PChar.quest.Start.win_condition = "Start";
	//Hornblower

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	// GR: France and allies currently at peace with Britain and Portugal
	SetNationRelationBoth(ENGLAND,  FRANCE,  RELATION_NEUTRAL);
	SetNationRelationBoth(ENGLAND,  SPAIN,   RELATION_NEUTRAL);
	SetNationRelationBoth(ENGLAND,  HOLLAND, RELATION_NEUTRAL);
	SetNationRelationBoth(PORTUGAL, FRANCE,  RELATION_NEUTRAL);
	SetNationRelationBoth(PORTUGAL, SPAIN,   RELATION_NEUTRAL);
	SetNationRelationBoth(PORTUGAL, HOLLAND, RELATION_NEUTRAL);
	LooseLetterOfMarque     (ENGLAND);		// Disable regular governor dialog
	PChar.professionalnavy = ENGLAND ;		// Add this again as it was removed by the previous function
	SetRelationsAsNation    (ENGLAND);		// Set nations as per selected nation

	SetCharacterShipLocation(characterfromID("Lt. Uriah Quelp"), "Antigua_port");
	SetCharacterShipLocation(characterfromID("Sir Edward Pellew"), "Antigua_port");
	SetCharacterShipLocation(characterfromID("Lt. William Bush"), "Antigua_port");
	SetCharacterShipLocation(characterfromID("Black Charlie Hammond"), "Antigua_port");
	SetCharacterShipLocation(characterfromID("Dreadnought Foster"), "Antigua_port");
	
	SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Keene"));
	SetCharacterRemovable(characterFromID("Captain Keene"), false);
	SetCharacterShipLocation(characterfromID("Captain Keene"), "Antigua_port");
	Character_SetCompanionEnemyEnable(characterfromID("Captain Keene"), true); // PB: Not linked to player!
	
	SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Harvey"));
	SetCharacterRemovable(characterFromID("Captain Harvey"), false);
	SetCharacterShipLocation(characterfromID("Captain Harvey"), "Antigua_port");
	Character_SetCompanionEnemyEnable(characterfromID("Captain Harvey"), true); // PB: Not linked to player!

	SetCompanionIndex(Pchar, -1, GetCharacterIndex("Lt. Percy Buckland"));
	SetCharacterRemovable(characterFromID("Lt. Percy Buckland"), false);
	SetCharacterShipLocation(characterfromID("Lt. Percy Buckland"), "Antigua_port");
	Character_SetCompanionEnemyEnable(characterfromID("Lt. Percy Buckland"), true); // PB: Not linked to player!
}
