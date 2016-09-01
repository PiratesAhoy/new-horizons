void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort = "PoPrince_Port";
	sTeleportLocName = "PoPrince_Port";
// KK -->
	string rldGroup = "reload";
	string rldLocator = "reload2";

	DeleteAttribute(PChar, "items"); // PB: Override Character Type

	TakeNItems(PChar, "blade6", 1);
	TakeNItems(PChar, "spyglass1", 1);
	TakeNItems(PChar, "medical1", 2); // PB

	EquipCharacterbyItem(Pchar, "blade6");
	EquipCharacterbyItem(Pchar, "Spyglass1");
	TakeNItems(PChar, "jewelry9", 1);			//ASVS
	TakeItemFromCharacter(Pchar, "map");		//ASVS
	setCharacterShipLocation(characterFromID("Portuguese Captain"), "PoPrince_Port");
//ASVS --->
	PChar.main_theme.value = "10";
	PChar.main_theme.musicname = "music_Bart_main_theme";
//ASVS <---

	Reinit_KhaelRoa();
	
	Towns[GetTownIndex("Buccaneers Camp")].skiptrade = true; // PB: Eugene Martin's custom dialog doesn't allow accepting quests

//================================| BEGINNING QUESTS |================================//

	//Bartolomeu
	PChar.quest.Bartolomeu = "";
	PChar.quest.Bartolomeu.win_condition.l1 = "location";
	PChar.quest.Bartolomeu.win_condition.l1.character = PChar.id;
	PChar.quest.Bartolomeu.win_condition.l1.location = "PoPrince_Port";
	PChar.quest.Bartolomeu.win_condition = "first_step";
	//Bartolomeu

	// PB -->
	ChangeCharacterAddress(characterFromID("WIC Officer"), "none", "");
	ChangeCharacterAddress(characterFromID("Bartolomeu o Portugues"), "none", "");
	DeleteAttribute(PChar, "quest.Bart_start");
	DeleteAttribute(PChar, "quest.Santiago");
	DeleteAttribute(PChar, "quest.Santiago_start");
	DeleteAttribute(PChar, "quest.Firstcontact");
	DeleteAttribute(PChar, "quest.Contact_start");
	DeleteAttribute(PChar, "quest.Jackpot");
	DeleteAttribute(PChar, "quest.Jackpot_start");
	// PB <--

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetNationRelationBoth(ENGLAND, PORTUGAL, RELATION_FRIEND);	// Bartolomeu: Required for story
	SetNationRelationBoth(ENGLAND, HOLLAND,  RELATION_NEUTRAL);	// No Anglo-Dutch war in 1660
	SetNationRelationBoth(ENGLAND, FRANCE,   RELATION_ENEMY);	// Consistent with "Assassin"
	SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_FRIEND);	// Consistent with "Assassin"
	SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_NEUTRAL);	// Consistent with "Assassin", also makes early missions easier
	SetRelationsAsNation(PORTUGAL);								// Set nations as per Portugal
}
