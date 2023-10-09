//-- 17Oct06 version

#define DEFAULT_SURRENDER_MODIFIER	7
#define BRDLT_SHIP	0
#define BRDLT_FORT	1
#define BRDLT_TOWN				2		// KK
#define BOARDER_HAS_GUN_PROB	0.25	// KK
#define BRDLT_MAXCREW	32
#define LOCINITBRD_DEFAULTLOCATION "ship default deck"
#define LOCINITBRD_DEFAULTLOCATION_FORT "fort default deck"

bool IsFort = false; // NK
bool IsTown = false; // KK

int boarding_location = -1;
int boarding_enemy_nation = PIRATE;
int boarding_location_type = -1;
object boarding_fader;
int boarding_enemy_crew = 0;
int boarding_player_crew = 0;
int boarding_enemy_base_crew = 0;
int boarding_officers = 0;		// LDH - not used
float boarding_player_crew_per_chr = 1.0;
ref boarding_enemy;

// added by MAXIMUS [abordage MOD] -->
ref refEnCharacter;		// twin enemy captain
int realCrew;
bool EndingStatsDone = false;	// LDH - flag to prevent reload event handler from running after done.
bool noOfficers = false;
bool endStat = true;
bool bCrewCaptured = false;
bCaptureShip = false;			// declared in globals.c as bool, cannot declare bool here.
// added by MAXIMUS [abordage MOD] <--

object boarding_adr[4];
float boarding_exp = 0.0;
float boarding_player_hp = 40.0;
float boarding_enemy_hp = 40.0;
int boarding_echr_index = -1;
int boarding_erank;		// enemy character level, used to set enemy boarder character levels
bool LAi_boarding_process = false;
// START MOD Code by Stone-D : 02/08/2003
bool Surrendered = false;
float boarding_enemy_original_morale = 0.0;
float boarding_enemy_crew_per_chr = 1.0;
int SurrenderModifier = 0;
int defeat = 0;
int boarding_enemy_crew_start = 0;
int boarding_player_crew_start = 0;
// END MOD Code by Stone-D : 02/08/2003
// NK -->
float mmorale = 0.5;
float emorale = 0.5;
// NK <--
// KK -->
int ncannonsdeck = 0;
int ncargohold = 0;
int nfort = 0;
int cdistrict = 0;
int next_boarding_location = -1;
// <-- KK

//Процес абордажа
// Process of the boarding
bool LAi_IsBoardingProcess()
{
	return LAi_boarding_process;
}

// -------------- Start Boarding ----------------------

//Начать абордаж с главным персонажем
// To begin boarding with the main character
void LAi_StartBoarding(int locType, ref echr, bool isMCAttack)
{
//	DEBUGINFO = 1;		// uncomment this line for full boarding debug information
	SDLogit("***StartBoarding()");
	// LDH - Only main boarding initialization is done here, and run only once per boarding.
	// LDH - Decks get initialized when you enter them in LAi_DeckInitialization().

	// LDH 16Sep06 change ship back to original nation if we board a surrendered ship, possibly doesn't always change captain model
	if (CheckAttribute(echr, "surrendered") && CheckAttribute(echr, "oldnation"))
	{
		SDLogIt("BD: Enemy nation changed from " + echr.nation + " to " + echr.oldnation);
		echr.nation = echr.oldnation;
	}

	SDLogIt("Enemy nation = " + echr.nation);

	InitBoardingVariables();

	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref mchr = GetMainCharacter();
	boarding_enemy = echr;		// save enemy so we can reference it in other functions
	boarding_enemy_nation = echr.nation;

	// LDH - these are no longer used, apparently, so can be removed
	// Fix enemy attributes from last boarding
//	DeleteAttribute(boarding_enemy, "status");
//	DeleteAttribute(boarding_enemy, "position");
	// These two lines are still required for Unassigned Captain to work
	boarding_enemy.status = "dead";
	boarding_enemy.position = "captive";

	// LDH - Save the pre-boarding location, Location will be restored in AIAboarding.c in Return2SeaAfterAbordage() // KK -->
	/*mchr.preboardloc = mchr.location;
	mchr.preboardloc.group = mchr.location.group;
	mchr.preboardloc.locator = mchr.location.locator;
	mchr.preboardloc.from_sea = mchr.location.from_sea;*/
	boarding_adr[0].location = mchr.location;
	boarding_adr[0].group = mchr.location.group;
	boarding_adr[0].locator = mchr.location.locator;
	int i, idx;
	for (i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i);
		if (idx < 0)
		{
			boarding_adr[i].location = "";
			boarding_adr[i].group = "";
			boarding_adr[i].locator = "";
			continue;
		}
		boarding_adr[i].location = Characters[idx].location;
		boarding_adr[i].group = Characters[idx].location.group;
		boarding_adr[i].locator = Characters[idx].location.locator;
	}
// <-- KK

	int mclass = GetCharacterShipClass(mchr);
	int eclass = GetCharacterShipClass(echr);
	if (IsTown) eclass = 0; // KK

	//Сохраним индекс врага
	// Save the enemy character index
	boarding_echr_index = sti(echr.index);

	boarding_erank = sti(echr.rank);	// used to calculate enemy HP
	if (GetDifficulty() < 4 && boarding_erank > 2*sti(mchr.rank))	// LDH 06Sep06 put a limit on this thing to prevent insanely high enemy ranks
	{
		int new_boarding_erank = sti(mchr.rank) * 2;
		SDLogIt("boarding_erank changed from " + boarding_erank + " to " + new_boarding_erank);
		boarding_erank = new_boarding_erank;
	}

	// NK -->
	if(CheckAttribute(mchr,"soundplaying"))
	{
		DeleteAttribute(mchr,"soundplaying");
	}
	else
	{
		ResetSoundScheme();
		PauseAllSounds();
	}

	if (locType == BRDLT_FORT)
	{
		isMCAttack = true;
		IsFort = true;
	}
	else
	{
		IsFort = false;
	}
	// NK <--
// KK -->
	if (locType == BRDLT_TOWN) {
		isMCAttack = true;
		IsTown = true;
	} else {
		IsTown = false;
	}
// <-- KK

	//Установим обработчик на убийство группы
	// Casualty event handler
	// KK SetEventHandler("LAi_event_GroupKill", "LAi_BoardingGroupKill", 1);		// activated in LAi_group_CheckGroupQuest()

	//Настроим интерфейс
	// Let us dispose the interface
	DeleteBattleInterface();
	StartBattleLandInterface();

	// LDH added - make sure ships have morale before starting, may be necessary for forts or towns
	if (!CheckAttribute(mchr, "ship.crew.morale"))
	{
		SDLogIt("Added morale attribute to mchr");
		mchr.ship.crew.morale = MORALE_NORMAL;
	}
	if (!CheckAttribute(echr, "ship.crew.morale"))
	{
		SDLogIt("Added morale attribute to echr");
// KK -->
		if (IsTown)
			echr.ship.crew.morale = GetTownCrewMorale(echr.town);
		else
			echr.ship.crew.morale = MORALE_NORMAL;
// <-- KK
	}

	MusketVolley(mchr, echr); // KK

	int ecrew = GetCrewQuantity(echr);

	// NK -->
	if (IsFort)
	{
		/*ecrew = 2000;
		SDLogIt("Fort crew1 = " + ecrew);
		if (CheckAttribute(echr,"town"))
		{
			// TIH --> changed to be float and int friendly Nov14'06
			//ecrew = GetTownNumTroops(echr.town) * TROOPS_MULT_ON_BOARD + GetTownSize(echr.town) * TOWN_MILITIA_MULT; // NK 04-09-20 increase troops
			// KK ecrew = GetTownNumTroops(echr.town) * TROOPS_MULT_ON_BOARD;
			// KK ecrew += makeint(makefloat(GetTownSize(echr.town)) * TOWN_MILITIA_MULT);
			// TIH <--
			SDLogIt(GetTownNumTroops(echr.town)+"*"+TROOPS_MULT_ON_BOARD+"+"+GetTownSize(echr.town)+"*"+TOWN_MILITIA_MULT);
			echr.ship.crew.morale = MORALE_NORMAL; // 04-09-22 tempfix for fort morale.
		}*/
		SDLogIt("Fort crew2 = " + ecrew);
	}
	// NK <--
// KK -->
	if (IsTown) {
		ecrew = 2000;
		if (CheckAttribute(echr,"town")) {
			ecrew = makeint(makefloat(GetTownNumTroops(echr.town)) * TOWN_MILITIA_MULT); // KK
			SDLogIt(GetTownNumTroops(echr.town)+"*"+TOWN_MILITIA_MULT);
			SetTownCrewMorale(echr.town, MORALE_NORMAL);
			echr.ship.crew.morale = MORALE_NORMAL;
		}
	}
// <-- KK

	if (ecrew < 1) ecrew = 1;

	SetCrewBoarding(echr, ecrew);	// save boarding crew

	int mcrew;
	if (IsFort || IsTown) // KK
		mcrew = GetSquadronCrewQuantity(mchr); // NK 04-09-22 so entire sqdrn's crew used on board fort or town. Will set other ships' crew by ratio in fortcapture.c
	else
		mcrew = GetCrewQuantity(mchr);

	SetCrewBoarding(mchr, mcrew);	// save boarding crew
	mchr.origcrew = mcrew;			// includes squadron quantity if boarding a fort

	//Расчитаем получаемый опыт в случае победы
	// We calculate the experience obtained in the case of victory
	if (!CheckAttribute(mchr,"boarding_exp"))
	{
		boarding_exp = 0.0;
		if (CheckAttribute(echr, "rank"))
		{
			boarding_exp = stf(echr.rank)*100.0;
			if (boarding_exp < 0.0) boarding_exp = 0.0;
		}
		boarding_exp = 100.0 + boarding_exp +
			10.0 * ecrew * (LAi_GetCharacterFightLevel(echr)*9.0 + 1.0) / (LAi_GetCharacterFightLevel(mchr)*9.0 + 1.0);
		mchr.boarding_exp = boarding_exp;
	}

	// NK -->
	// LDH - change from averaging boarding_erank with mchr only if echr was higher to always
	// was makeint(sti(mchr.rank)+(boarding_erank-sti(mchr.rank))/2))
	// Make the enemy rank closer to the player so enemy boarder HP won't be too different.  Used only for enemy boarder HP
	int old_boarding_erank = boarding_erank;
	boarding_erank = makeint((2.0*sti(mchr.rank) + boarding_erank)/3.0+0.5);
	SDLogIt("boarding_erank changed from " + old_boarding_erank + " to " + boarding_erank + ", player rank = " + mchr.rank);

	//Определяем цепь локаций для абордажа
	// We determine the chain of locations for the boarding
	boarding_location = -1;
	boarding_location_type = locType;
	deckID = "";

// KK -->
	switch (locType)
	{
		case BRDLT_FORT:
			nfort = 1;
			deckID = "BOARDING_Fort";
			PrepareLocationForBoardingFort();
		break;
		case BRDLT_TOWN:
			deckID = "BOARDING_Town";
			TownAbordageLoad();
		break;
		// default:
			string chDeck = GetShipLocationID(mchr);
			string enDeck = GetShipLocationID(echr);
			int chDeckNo = sti(getsymbol(chDeck, strlen(chDeck) - 1));
			int enDeckNo = sti(getsymbol(enDeck, strlen(enDeck) - 1));

			if (chDeckNo > 3 && enDeckNo > 3 && chDeckNo != enDeckNo) {
				if (chDeckNo < enDeckNo)
					deckID = "BOARDING_ShipDeck" + chDeckNo + "vs" + enDeckNo;
				else
					deckID = "BOARDING_ShipDeck" + enDeckNo + "vs" + chDeckNo;
			} else {
				if (isMCAttack)
					deckID = "BOARDING_" + GetShipLocationID(echr);
				else
					deckID = "BOARDING_" + GetShipLocationID(mchr);
			}
	}
// <-- KK
	int locID = -1;
	if (deckID != "")
	{
		locID = FindLocation(deckID);
		if (locID < 0)
		{
			Trace("Boarding: ship location not found <" + deckID + ">, setting default");
			deckID = "";
		}
	}

	if (deckID == "")
	{
		if (locType == BRDLT_FORT)
		{
			deckID = LOCINITBRD_DEFAULTLOCATION_FORT;
		}else{
			deckID = LOCINITBRD_DEFAULTLOCATION;
		}
		locID = FindLocation(deckID);
	}

	if (locID < 0)	// We can't find a default boarding location, possibly when attacking a town.  Do ransack in this case.
	{
		Trace("Boarding: ship location not found <" + deckID + ">, no start boarding");

		switch (boarding_location_type)
		{
		case BRDLT_SHIP:

// added by MAXIMUS [abordage MOD] -->
			if (CheckAttribute(boarding_enemy,"position"))
			{
			  /* // eliminated
			  switch(boarding_enemy.position)
			  {
				case "loser": transferCaptain = true; break;
				case "corpse": transferCaptain = false; break;
				case "officer": transferCaptain = false; break;
				case "companion": transferCaptain = true; break;
				case "captive": transferCaptain = false; break;
			  }
			  */
			}
			else
			{
				boarding_enemy.status = "dead";
				boarding_enemy.position = "corpse";
				if(sti(refEnCharacter.index)>0) DeleteCharacter(refEnCharacter);
				Trace("LAi_boarding.c -> twin character <" + refEnCharacter.id + "> was successfully deleted");
				//transferCaptain = false; // eliminated
			}

			if (endStat)
				SetEndingStats();
			else
				endStat = true;
			noOfficers = false;

			bCaptureShip = false;
// added by MAXIMUS [abordage MOD] <--

			// TIH --> fantom flag no longer needed by this point
			if (CheckAttribute(boarding_enemy,"isFantom")) { DeleteAttribute(boarding_enemy,"isFantom"); }
			if (CheckAttribute(refEnCharacter,"isFantom")) { DeleteAttribute(refEnCharacter,"isFantom"); }
			// TIH <--
// KK -->
			Group_UpdateGroup(boarding_enemy);
			boarding_enemy.chr_ai.type = "stay";
			LAi_KillCharacter(boarding_enemy);// kill the original character off
			ChangeCharacterAddressGroup(refEnCharacter, "none", "", "");
			LaunchRansackMain(GetMainCharacter(), echr, "");
// <-- KK
			LAi_boarding_process = false;
			break;

		case BRDLT_FORT:

			// LDH - test this to make sure it works here.  Added with new boarding logic
			if (endStat)
				SetEndingStats();
			else
				endStat = true;

			LaunchFortCapture(echr);
			LAi_boarding_process = false;
			IsFort = false;
			break;

//		default:
			Trace("Boarding: unknown boarding location type");
		}
		return;
	}

//	SDLogIt("Surrender Start");
// START MOD Code by Stone-D : 27/07/2003
	// LDH Program logic changed so that this decrements once per deck, not once per enemy killed
	SurrenderModifier = DEFAULT_SURRENDER_MODIFIER;
	if(CheckAttribute(echr, "ship.crew.morale"))	boarding_enemy_original_morale = stf(echr.ship.crew.morale);
	else											boarding_enemy_original_morale = MORALE_NORMAL;					// PB: For towns without forts
	// LDH - defeat variable is used in GetAdjustedMorale() for final enemy morale adjustment after battle is over
	defeat = makeint((rand(makeint(GetShipSkill(mchr,SKILL_GRAPPLING)+GetShipSkill(mchr,SKILL_SNEAK)))+rand(9)+1)*((GetShipSkill(mchr,SKILL_LEADERSHIP)+CalcCharacterSkill(mchr,SKILL_FENCING))/2)); // NK
//	defeat = (rand(GetShipSkill(mchr,SKILL_GRAPPLING)+GetShipSkill(mchr,SKILL_SNEAK))+rand(9)+1) * ((GetShipSkill(mchr,SKILL_LEADERSHIP)+CalcCharacterSkill(mchr,SKILL_FENCING))/2); // NK
//	defeat = (rand((1..10) + (1..10)) + (0..9) + 1) * ((1..10) + (1..10)) / 2)
//	defeat = ((0..20) + (0..9) + 1) * AverageOfLeadershipAndFencing = (1..300), likely 75

// changed by MAXIMUS [abordage MOD] -->
	if (CheckForSurrender(mchr, echr))
	{
		Surrendered = true;

		if (mclass > eclass)	// if our ship is smaller we get a morale boost
		{
			int beforesurrmorale = sti(mchr.ship.crew.morale);
			int surrmoraleboost = (rand(mclass-eclass)+1) * rand(mclass-eclass)+1);
			SDLogIt("Player morale boost for surrendered ship: " + beforesurrmorale + " -> " + (beforesurrmorale+surrmoraleboost));
			mchr.ship.crew.morale = beforesurrmorale + surrmoraleboost;
			DeleteAttribute(mchr,"boardingReload"); // PB: To ensure this is REMOVED upon surrendering
		}

		mchr.ship.crew.morale = iclamp(1, 99, sti(mchr.ship.crew.morale));
	}
// changed by MAXIMUS [abordage MOD] <--

	if (!isMCAttack) Surrendered = false; // KK

//---------------------------------------
//	Surrendered = true;		// uncomment to test surrendered ships easily
//	SDLogIt("FORCED SURRENDER: enemy HAS surrendered on top deck before fight");
//---------------------------------------

// END MOD Code by Stone-D : 27/07/2003

	// We determine the sizes of the commands
// KK -->
	if (!IsFort && !IsTown)
		refEnCharacter = CreateTwinCharacter(boarding_enemy);
	else
		refEnCharacter = boarding_enemy;
// <-- KK
	LAi_RemoveCheckMinHP(refEnCharacter);//MAXIMUS: for some quest-characters
	SDLogIt("refEnCharacter = " + refEnCharacter.id + ", boarding_enemy = " + boarding_enemy.id);

	// We start (the boarding process)
	LAi_boarding_process = true;
	LAi_LoadLocation(deckID);		// LDH - runs LAi_InitializeDeck
	CreateEntity(&boarding_fader, "fader");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	//LanguageCloseFile(tmpLangFileID);
}	//------ end of LAi_StartBoarding() ------------

//---------------- Initialize Each Deck -------------------

// The following code will be run for each deck entered
void LAi_InitializeDeck(int locIndex)
{
	SDLogit("***InitializeDeck()");

	ref echr = boarding_enemy;
	int mcrew;
	int ecrew;
	ref mchr = GetMainCharacter();
	int maxcrew;

	//Параметры сражающихся сторон
	// Enemy and friendly parameters

	DeleteAttribute(&mchr, "lockerweapons"); // NK get weaps back 05-05-10

	mcrew = GetCrewBoarding(mchr);
	ecrew = GetCrewBoarding(echr);
	boarding_enemy_base_crew = ecrew;

	//Количество хитпойнтов
	// Amount of hitpoints
	ResetMaxHP(mchr);	// just in case
	ResetMaxHP(echr);	// this is being set way too low on easy difficulty
	boarding_player_hp = LAi_GetCharacterMaxHP(mchr);	// restored original game code
	boarding_enemy_hp  = CHAR_START_HITPOINTS + (boarding_erank - 1) * CHAR_HITPOINTS_PER_LEVEL;	// normal hitpoint calc based on level

	SDLogIt("Original enemy HP = " + boarding_enemy_hp + ", enemy rank = " + boarding_erank + ", difficulty = " + GetDifficulty() + ", player rank = " + mchr.rank);

// KK -->
	// LDH - playerHP should be left alone.  EnemyHP is scaled by difficulty and morale differences.
	if (!IsTown) {
		boarding_enemy_hp += boarding_enemy_hp * ((stf(echr.ship.crew.morale) - stf(mchr.ship.crew.morale))/200.0); // LDH - change from absolute morale diff to percentage diff, 0.5 to 1.5 - 19Jan09
		boarding_enemy_hp = boarding_enemy_hp * (1.0 + (GetDifficulty()-1.0)/5.0));	// 1.0, 1.2, 1.4, 1.6
	} else {
		boarding_enemy_hp = boarding_enemy_hp + ((makefloat(GetTownCrewMorale(echr.town)) - stf(mchr.ship.crew.morale))/4.0);	// fix parenthesis as above
		boarding_enemy_hp = boarding_enemy_hp * (1.0 + (GetDifficulty()-1.0)/5.0));	// 1.0, 1.2, 1.4, 1.6
	}
	//SDLogIt("Final enemy HP = " + boarding_enemy_hp + ", emorale = " + echr.ship.crew.morale + ", mmorale = " + mchr.ship.crew.morale + ", morale change = " + (stf(echr.ship.crew.morale)-stf(mchr.ship.crew.morale))/2.0 + " percent"); // LDH changed 19Jan09
// <-- KK

	if (boarding_enemy_hp < LAI_DEFAULT_HP) boarding_enemy_hp = LAI_DEFAULT_HP;		// 40

	float curplayercrew = mcrew;

/*-----
  Maxcrew calcs

  Set maxcrew to the maximum number of boarders that can fit on a particular deck
  Set the ratio between player and enemy boarding crews
  Set the player and enemy boarding crews (actors) such that the sum of the two equals maxcrew

------*/

	maxcrew = GetBoardingLimit(locIndex);
	float CrewRatio = fclamp(1.0/3.0, 2.0/3.0, 1.0 * mcrew / (mcrew + ecrew));	// No more than 2:1 odds on any deck

	mcrew = makeint(CrewRatio * maxcrew + 0.5);
	ecrew = makeint((1.0 - CrewRatio) * maxcrew + 0.5);
	if (mcrew < 1) mcrew = 1;
	if (ecrew < 1) ecrew = 1;
	int crewtotal = mcrew + ecrew;
	SDLogIt("locIndex = " + locIndex + ", Maxcrew = " + maxcrew + ", CrewRatio = " + CrewRatio + ", mcrew = " + mcrew + ", ecrew = " + ecrew + ", total = " + crewtotal);

	// LDH - this is where the boarding actor numbers are set
	boarding_enemy_crew = ecrew;
	boarding_enemy_crew_start = ecrew;
	boarding_player_crew = mcrew;
	boarding_player_crew_start = mcrew;

	// START MOD Code by Stone-D : 30/07/2003
	boarding_player_crew_per_chr = curplayercrew / mcrew;
	boarding_enemy_crew_per_chr = boarding_enemy_base_crew/ecrew; // Stone-D : For calculating final crew numbers
	// END MOD Code by Stone-D : 30/07/2003

	// LDH - keep a reserve for the next boarding location
	boarding_player_crew_per_chr = boarding_player_crew_per_chr * (0.20 + frand(0.05));	// 75% to 80% of crew in reserve.
	boarding_enemy_crew_per_chr  = boarding_enemy_crew_per_chr  * (0.20 + frand(0.05));

	//Выставим игроку и офицерам максимальную жизнь и запомним адреса
	// Set player and officers HP according to relative strengths of mchr and echr and record the boarding location.
	// KK LAi_SetCurHPMax(mchr); // when we go to the next deck we are magically healed?! Why doesn't that work on land with normal doors...

	int limit = GetBoardingLimit(locIndex);
	int mlimit = makeint(CrewRatio * limit + 0.5);
	int elimit = makeint((1.0 - CrewRatio) * limit + 0.5);
	if (mlimit < 1) mlimit = 1;
	if (elimit < 1) elimit = 1;
	mchr.mlimit = mlimit;
	mchr.elimit = elimit;

	mchr.abordagesound = PlayStereoSoundLooped("OBJECTS\ABORDAGE\abordage2.wav");	// PB: Start Playing Boarding Sound

} //-------- end of LAi_InitializeDeck() -------------
// LDH <--

//Загрузить локацию абордажа
// To load the location of the boarding
void LAi_LoadLocation(string locationID)
{
	SDLogIt("***LoadLocation(" + locationID + ")");

	ReloadProgressStart();
	bool swaplocs = SWAPBOARDING && !IsFort && !IsTown && !bMCAbordageInitiator; // KK

	ref mchr = GetMainCharacter();

	/*SDLogIt("Crew/morale stats starting Load Location");
	SDLogIt("Enemy crew = " + GetCrewBoarding(boarding_enemy) + ", Enemy morale = " + boarding_enemy.ship.crew.morale);
	SDLogIt("Player crew = " + GetCrewBoarding(mchr) + ", Our morale = " + mchr.ship.crew.morale);*/

	//Ищем локацию
	// We search for the location
	int locIndex = FindLocation(locationID);
	Log_SetActiveAction("Nothing");
	if (locIndex >= 0)
	{
		LAi_InitializeDeck(locIndex);		// LDH - get new boarding strengths for each deck

// added by MAXIMUS [abordage MOD] (totally rewritten by LDH 01Oct06) -->

		string chLocType = "loc";
		string enLocType = "aloc";
		//string modelLocation = Locations[locIndex].models.always.l1;
		//MAXIMUS: new decks were added from SLiB addon (based on ships classes) -[03.04.2007]-> // KK -->
		if (HasSubStr(locationID, "BOARDING_ShipDeck")) {
			string chDeck = GetCharacterShipQDeck(mchr);
			string enDeck = GetCharacterShipQDeck(boarding_enemy);
			string tmpLocType = "";
			int nchDeck = sti(getsymbol(chDeck, strlen(chDeck) - 1));
			int nenDeck = sti(getsymbol(enDeck, strlen(enDeck) - 1));
			bool single_deck = IsSingleDeck(locationID);
			if (single_deck == false && nchDeck < nenDeck) {
				tmpLocType = enLocType;
				enLocType = chLocType;
				chLocType = tmpLocType;
			}
			if (single_deck == true && swaplocs == true) {
				tmpLocType = enLocType;
				enLocType = chLocType;
				chLocType = tmpLocType;
			}
		}

		// This sets player's location and sets up locations for the player and enemy boarders
		mchr.location = locationID;
		mchr.location.group = "rld";
		mchr.location.locator = chLocType + "0";		// default // KK

// KK -->
		if (locationID != "BOARDING_Fort" && locationID != "BOARDING_Town")
		{
			string DeckTextureDir = "";
			bool AllowCustomTexture = true;
			if(HasSubStr(locationID,"ShipDeck"))			AllowCustomTexture = false;
			if(HasSubStr(locationID,"Cabin"))				AllowCustomTexture = false;
			if(locationID == LOCINITBRD_DEFAULTLOCATION)	AllowCustomTexture = false;
			if(AllowCustomTexture) // PB: Only in non-cabin interior locations
			{
				DeckTextureDir = GetShipDecksTexture(boarding_enemy);
			}
			if (DeckTextureDir == "")	DeleteAttribute(&Locations[locIndex], "filespath.textures");
			else						Locations[locIndex].filespath.textures = DeckTextureDir;
		}

		// Set location of enemy captain for surrender in cabin
		// Note: some of these locators may cause problems, dialog not automatically initiated
		string homeLocator;
		switch (Locations[locIndex].id)
		{
			case "Boarding_Cabin1":
				homeLocator = enLocType + rand(3);
			break;

			case "Boarding_Cabin_medium":
				homeLocator = enLocType + rand(2);
			break;

			case "Boarding_Cabin_small":
				homeLocator = enLocType + rand(1); // KK
			break;

			case "Boarding_Cabin3":
				homeLocator = enLocType + rand(6);
			break;

			case "Boarding_Cabin4":
				homeLocator = enLocType + rand(6);
			break;

			case "Boarding_Cabin2":
				homeLocator = enLocType + rand(6);
			break;

			case "BOARDING_ShipDeck4":
				homeLocator = enLocType + rand(4);
			break;

			case "BOARDING_ShipDeck5":
				homeLocator = enLocType + rand(4);
			break;

			case "BOARDING_ShipDeck6":
				homeLocator = enLocType + rand(5);
			break;

			case "BOARDING_ShipDeck7":
				homeLocator = enLocType + rand(5);
			break;

			case "BOARDING_ShipDeck4vs5":
				homeLocator = enLocType + rand(4);
			break;

			case "BOARDING_ShipDeck4vs6":
				homeLocator = enLocType + rand(4);
			break;

			case "BOARDING_ShipDeck5vs6":
				homeLocator = enLocType + rand(4);
			break;
		}

		// Set location of enemy captain for surrender on deck
		switch(Locations[locIndex].filespath.models)
		{
			case "locations\decks\udeck":
				homeLocator = enLocType + rand(5);
			break;

			case "locations\decks\udeck1":
				homeLocator = enLocType + rand(15);
			break;

			case "locations\decks\udeck2":
				homeLocator = enLocType + rand(15);
			break;
		}
// <-- KK
		// LDH <--

		if (Surrendered) noOfficers = SurrenderAction(mchr, refEnCharacter, locationID, homeLocator, chLocType, false);//MAXIMUS

		//Устанавливаем офицеров, если такие есть
		// We establish officers, if such exist
		PlaceOfficers(locationID, chLocType, noOfficers, !noOfficers);//MAXIMUS
		//Перегружаемся в локацию
		// We are reloaded into the location
		boarding_location = locIndex;
		if (LoadLocation(&Locations[boarding_location]))
		{
			if (!Surrendered) { 
				// Let us take out the sabre
				SendMessage(mchr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
				// We arrange the characters
				LAi_SetBoardingActors(locationID, chLocType, enLocType); // changed by MAXIMUS [abordage MOD]
			}
			else
			{
				// PB: Stop sound upon surrendering -->
				if(CheckAttribute(mchr, "abordagesound"))
				{
					StopSound(sti(mchr.abordagesound), 2000);
					DeleteAttribute(mchr, "abordagesound");
					//SetSchemeForLocation(&locations[FindLocation("ShipDeck1")]);
					//SetMusic("music_abordage");
				}
				// PB: Stop sound upon surrendering <--
			}
			//Запретим диалог
			// Let us forbid the dialogue
			dialogDisable = false; // Captain Hawk Fix
			// NK enable dialog in boarding - 05-07-12 - dialogDisable = true;
		}else{
			Trace("Boarding: Boarding location not loaded, current loc <" + locationID + ">");
		}
	}
	else
	{
		Trace("Boarding: Boarding location not found, current loc <" + locationID + ">");
	}

	ReloadProgressEnd();

	if(CheckAttribute(mchr,"musket"))//MAXIMUS: placed here for sound effects
	{
		if(!Surrendered && FindFile("RESOURCE\Sounds\INTERFACE", "*.wav", "_musketshot.wav")!="") PlaySound("INTERFACE\_musketshot.wav");
		//if(CheckAttribute(mchr,"musket.kills")) PlaySound("OBJECTS\ABORDAGE\abordage_loosing.wav");
		if (CheckAttribute(mchr, "musket")) DeleteAttribute(mchr, "musket");
		if (CheckAttribute(refEnCharacter, "musket")) DeleteAttribute(refEnCharacter, "musket");
	}

	ResetTimeToNormal(); // PB: Reset Time Scale
	PostEvent("LoadSceneSound", 500);
}

void PlaceOfficers(string locationID, string chLocType, bool noOfficers, bool noFight)
{
	if(noOfficers) return;
	ref mchr = GetMainCharacter();

	int mlimit;// restrict officers to PBC limits 22AUG06
	int i, idx;
	if(CheckAttribute(mchr,"mlimit")) mlimit = sti(mchr.mlimit);// mlimit will be gone if we've already run SetEndingStats()
	else mlimit = 1;

	for (i = 1; i <= OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i);
		if(idx<0) continue;
		// boal 05.09.03 offecer need to go to abordage -->
		if(!CheckAttribute(Characters[idx], "AbordageMode") || sti(Characters[idx].AbordageMode) == 0) continue;

// added by MAXIMUS [abordage MOD] -->
		if(noOfficers==true) continue;
		if(IsCompanion(&Characters[idx])) continue;
		if(IsOfficerCompanion(&Characters[idx])) continue;
		if(IsOnShoreLeave(&Characters[idx])) continue;
		if(IsOfficerOnShoreLeave(&Characters[idx])) continue;
// added by MAXIMUS [abordage MOD] <--

		mlimit = mlimit - 1;// first boarder will be the player character - Note this shouldn't be saved
		if(mlimit<1) continue;

		// boal 05.09.03 officer need to go to abordage <--
		DeleteAttribute(&Characters[idx], "location");
		Characters[idx].location = locationID;
		Characters[idx].location.group = "rld";

		int startlocnum = 1;
		int locnum = startlocnum;
		Characters[idx].location.locator = chLocType + locnum;
		ChangeCharacterAddressGroup(&Characters[idx], locationID, "rld", Characters[idx].location.locator);
		locnum++;
		if(locnum>=GetBoardingLimit(FindLocation(locationID))/2) locnum = startlocnum;
		if(noFight) SendMessage(&Characters[idx], "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", 0);
	}
}

bool SurrenderAction(ref mchr, ref ch, string locationID, string homeLocator, string chLocType, bool bGen)
{//MAXIMUS: here we'll make a fantom (if boarding_enemy is fantom or not in player's location) without superfluous attributes with possibility to make him an officer in the future
	ref refEnCaptain = ch;
	if(ch.id=="0" || strleft(ch.id,4)=="fenc" || bGen)
	{
		refEnCharacter = LAi_CreateFantomCharacterEx(true, 0, true, true, BOARDER_HAS_GUN_PROB, refEnCharacter.model, "rld", homeLocator);
		boarding_enemy.isFantom = 0;
		boarding_enemy.fight = 0;
		refEnCaptain.isFantom = 0;
		refEnCaptain.fight = 0;
		refEnCaptain.cabinfight = true;

		if (CheckAttribute(ch,"old.name")) refEnCaptain.old.name = ch.old.name;
		if (CheckAttribute(ch,"old.lastname")) refEnCaptain.old.lastname = ch.old.lastname;
		if (CheckAttribute(ch,"title")) refEnCaptain.title = ch.title;
		if (CheckAttribute(ch,"name")) refEnCaptain.name = ch.name;
		if (CheckAttribute(ch,"middlename")) refEnCaptain.middlename = ch.middlename;
		if (CheckAttribute(ch,"lastname")) refEnCaptain.lastname = ch.lastname;
		if (CheckAttribute(ch,"model")) refEnCaptain.model = ch.model;
		if (CheckAttribute(ch,"sex")) refEnCaptain.sex = ch.sex;
		if (CheckAttribute(ch,"nation")) refEnCaptain.nation = ch.nation;
		if (CheckAttribute(ch,"nation.name")) refEnCaptain.nation.name = sti(ch.nation.name);
		if (CheckAttribute(ch,"rank")) refEnCaptain.rank = ch.rank;
		if (CheckAttribute(ch,"reputation")) refEnCaptain.reputation = ch.reputation;
		if (CheckAttribute(ch,"experience")) refEnCaptain.experience = ch.experience;
		if (CheckAttribute(ch,"questchar")) refEnCaptain.questchar = ch.questchar;
		/*if (CheckAttribute(ch,"money"))
			refEnCaptain.money = ch.money;
		else
			refEnCaptain.money = makeint(rand(100));
		if (CheckAttribute(ch,"wealth"))
			refEnCaptain.wealth = ch.wealth;
		else
			refEnCaptain.wealth = makeint(sti(refEnCaptain.money)*(frand(5.0)+2.3));

		if (!UsableOfficer(ch)) {*/
			/*switch(Rand(7))
			{
				case 0: refEnCaptain.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
				case 1: refEnCaptain.quest.officertype = OFFIC_TYPE_CANNONEER; break;
				case 2: refEnCaptain.quest.officertype = OFFIC_TYPE_QMASTER; break;
				case 3: refEnCaptain.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
				case 4: refEnCaptain.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
				case 5: refEnCaptain.quest.officertype = OFFIC_TYPE_CARPENTER; break;
				case 6: refEnCaptain.quest.officertype = OFFIC_TYPE_DOCTOR; break;
				case 7: refEnCaptain.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
			}*/
			/*if(DEBUG_EXPERIENCE>0) TraceAndLog("SurrenderAction: Set officer type for " + GetMySimpleName(refEnCaptain));
			refEnCaptain.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
			LAi_Create_Officer(rand(8), &refEnCaptain);
		}
		if (CheckAttribute(ch,"quest.officerprice"))
			refEnCaptain.quest.officerprice = ch.quest.officerprice;
		else
			refEnCaptain.quest.officerprice = makeint((sti(characters[GetMainCharacterIndex()].rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10);
		*/
		/*int i;
		if (CheckAttribute(ch,"skill")) {
			aref arSkillsRoot; makearef(arSkillsRoot,ch.skill);
			for (i = 0; i < GetAttributesNum(arSkillsRoot); i++)
			{
				string skillName = GetSkillName(i);
				if (CheckAttribute(ch,"skill."+skillName)) {
					refEnCaptain.skill.(skillName) = ch.skill.(skillName);
				} else {
					refEnCaptain.skill.(skillName) = "1";
				}
			}
		}

		aref arPerksRoot; makearef(arPerksRoot,ChrPerksList.list);
		for (i=0; i < GetAttributesNum(arPerksRoot); i++)
		{
			string perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
			if (CheckAttribute(ch,"perks.list."+perkName)) {
				refEnCaptain.perks.list.(perkName) = ch.perks.list.(perkName);
			} else {
				refEnCaptain.perks.list.(perkName) = false;
			}
		}*/

		if(CheckAttribute(ch,"Ship"))
		{
			refEnCaptain.Ship = true;

			aref oldShip; makearef(oldShip,ch.Ship);
			aref newShip; makearef(newShip,refEnCaptain.Ship);
			CopyAttributes(&newShip,&oldShip);
		}
		LAi_NPC_Equip(&refEnCaptain, sti(refEnCaptain.rank), true, 0.5);

		SDLogIt("Fantom-captain created!!!");
	}

	//refEnCaptain.skill.Leadership = sti(refEnCaptain.skill.Leadership)-1;//MAXIMUS: he surrendered and his Leadership goes to a Devil
	//refEnCaptain.skill.Grappling = sti(refEnCaptain.skill.Grappling)-1;//MAXIMUS: he surrendered and his Grappling goes to a Devil
	string id = "surrender";
	string desc = "This captain surrendered";
	SetSkillCharMod(refEnCaptain, "Leadership", -1, id, desc); //Levis
//	SetSkillCharMod(refEnCaptain, "Grappling", -1, id, desc); //Levis, TY after poll generally agreed to remove this part of the modifier
	
	refEnCaptain.nodisarm = 1;
	if (!CheckAttribute(refEnCaptain,"chr_ai.type")) refEnCaptain.chr_ai.type = "stay";
	if (!CheckAttribute(refEnCaptain,"model.entity")) refEnCaptain.model.entity = "NPCharacter";
// KK -->
	if (CheckAttribute(ch, "Dialog.Filename") && CheckAttribute(ch, "Dialog.BoardingNode")) {
		refEnCaptain.Dialog.Filename = ch.Dialog.Filename;
		refEnCaptain.Dialog.CurrentNode = ch.Dialog.BoardingNode;
	} else {
		refEnCaptain.Dialog.Filename = "Cabinfight_dialog.c";
		refEnCaptain.Dialog.Currentnode = "First time";
	}
// <-- KK
	if (refEnCaptain.sex == "woman")
		refEnCaptain.greeting = "Gr_Pirate_f";
	else
		refEnCaptain.greeting = "Gr_Clauss"; // was "Gr_Dark Teacher" which is identical

	SDLogIt("Did enemy captain dialog at locator " + homeLocator);

	mchr.TalkWithSurrenderedCaptain = true; // KK

	noOfficers = true;
	if(endStat && !bGen) SetEndingStats();

	LAi_RemoveCheckMinHP(refEnCaptain);//MAXIMUS: for some quest-characters
	LAi_SetLoginTime(refEnCaptain, 0.0, 24.0); // KK
	ChangeCharacterAddressGroup(refEnCaptain, locationID, "rld", homeLocator); // KK
	mchr.quest.CaptiveIdx = sti(refEnCaptain.index);
	LAi_group_MoveCharacter(refEnCaptain, LAI_GROUP_PLAYER);

	// Make character run to enemy captain, walk when he gets close
	if (ACTOR_WHEN_BOARDING == 1 && bGen == false) {
		mchr.SavedAlwaysRunToggle = AlwaysRunToggle;
		if(AlwaysRunToggle)
		{
			AlwaysRunToggle = false;
			BeginChangeCharacterActions(mchr);
			SetDefaultNormWalk(mchr);
			SetDefaultFight(mchr);
			EndChangeCharacterActions(mchr);
		}
//MAXIMUS: each character will run to opponent -->
		LAi_SetActorType(refEnCaptain);
		LAi_ActorFollow(refEnCaptain, mchr, "", -1);
		LAi_SetActorType(mchr);
		LAi_ActorFollow(mchr, refEnCaptain, "Surrendered_Captain_Dialog", -1);
//MAXIMUS: each character will run to opponent <--
	}

	endStat = false;

	return true;
}

//Перегрузиться в следующую локации
// Reload into the next boarding location
void LAi_ReloadBoarding()
{
	SDLogIt("***ReloadBoarding()");
	ref mchr = GetMainCharacter();

	DelEventHandler("Control Activation","LAi_ActivateReload"); // KK

	if (GetCrewBoarding(mchr) > 0)		// crews will be zero if it's a fort after SetEndingStats()
	{
		SDLogIt("Crew/morale stats starting ReloadBoarding");
		SDLogIt("Enemy crew = " + GetCrewBoarding(boarding_enemy) + ", Enemy morale = " + boarding_enemy.ship.crew.morale);
		SDLogIt("Player crew = " + GetCrewBoarding(mchr) + ", Our morale = " + mchr.ship.crew.morale);
	}

	//Разрешим диалоги
	// Let us solve the dialogues
// changed by MAXIMUS -->
	SDLogIt("bCabinStarted bDeckStarted bCrewStarted = " + bCabinStarted + "," + bDeckStarted + "," + bCrewStarted);
	dialogDisable = !bDeckEnter; // Captain Hawk Fix // KK
// changed by MAXIMUS <--
	//Проверим предыдущую локацию
	// Let us verify the previous location
	if (boarding_location < 0)
	{
		Trace("Boarding: No loaded current boarding location");
		LAi_boarding_process = false;
		return;
	}

	//Установить хендлеры для обработки
	// To establish event handlers
	SetEventHandler("FaderEvent_StartFade", "LAi_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "LAi_ReloadEndFade", 0);

	//Создаём фейдер и запускаем
	// We create fader and we start
	CreateEntity(&boarding_fader, "fader");
// KK -->
	next_boarding_location = FindLocation(GetNextBoardingLocation());
	if (Surrendered) {
		if (IsTown)
			next_boarding_location = FindLocation(boarding_enemy.location);
		else
			next_boarding_location = FindLocation("BOARDING_" + GetCharacterShipCabin(boarding_enemy));
	}
	if (next_boarding_location >= 0) {
		if (CheckAttribute(&Locations[next_boarding_location], "image"))
			SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[next_boarding_location].image));
	} else {
		if (!IsFort) {
			if (IsTown) {
				SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(boarding_enemy.location)].image));
			} else {
				string boarding_cabin = GetCharacterShipCabin(boarding_enemy);
				if (boarding_cabin == "Cabin_none") boarding_cabin = GetCharacterShipQDeck(boarding_enemy);
				SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation("BOARDING_" + boarding_cabin)].image));
			}
		}
	}
	if (CheckAttribute(boarding_enemy, "nosurrender") == true && sti(boarding_enemy.nosurrender) == -1)
	{
		Surrendered = true;
	}
// <-- KK
	float fadeOutTime = RELOAD_TIME_FADE_OUT;
	SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
}

void LAi_ReloadStartFade()
{
	SDLogIt("***ReloadStartFade()");
	//Выгружаем локацию
	// We unload the location
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "LAi_ReloadStartFade");
	if (boarding_location >= 0) UnloadLocation(&Locations[boarding_location]);
}

void LAi_ReloadEndFade()
{
	int i, idx;
	ref mchr = GetMainCharacter();
	SDLogIt("***ReloadEndFade()");
	//Загружаем следующую локацию
	// We load the next location
	DelEventHandler("FaderEvent_EndFade", "LAi_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	//Определим возможность продолжения перегрузок
	// Let us determine the possibility of continuing the reloads
	bool canReload = true;
// START MOD Code by Stone-D : 27/07/2003
// KK -->
	boarding_location = next_boarding_location;
	if (next_boarding_location == -1) canReload = false;
	if (LAi_IsDead(refEnCharacter)) canReload = false;
// <-- KK
	if (EndingStatsDone) canReload = false;
	chrWaitReloadLocator = "";//MAXIMUS
	DeleteAttribute(GetMainCharacter(),"boardingReload");//MAXIMUS

	if (canReload)
// END MOD Code by Stone-D : 27/07/2003
	{
		//Продолжаем абордаж
		// We continue the boarding
// added by MAXIMUS [abordage MOD] -->
		SDLogIt("Surrendered = " + Surrendered);

		if(Surrendered)	// Note that forts don't surrender
		{
			noOfficers = true;
			boarding_location = FindLocation("BOARDING_" + GetCharacterShipCabin(boarding_enemy)); // KK
			LAi_LoadLocation(Locations[boarding_location].id);
		}
// added by MAXIMUS [abordage MOD] <--
		else
		{
			LAi_LoadLocation(Locations[boarding_location].id); // KK
		}
		WhrDeleteRainEnvironment(); // Baste
		SetMusic("music_abordage");
	}
	else		// cannot reload, no following location
	{
		//Следующей локации нет
		// There is no following location
		// KK DelEventHandler("LAi_event_GroupKill", "LAi_BoardingGroupKill");
		boarding_location = -1;

		//Начислим опыт
		// Let us update the group experience
		if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(mchr, "Grappling", MakeInt(mchr.boarding_exp)); }
		else { AddPartyExp(mchr, MakeInt(mchr.boarding_exp)); } // NK - AddCharacterExp(GetMainCharacter(), MakeInt(boarding_exp));
		DeleteAttribute(mchr, "boarding_exp");

		//Настроим интерфейс
		// Let us dispose of the interface
		Log_SetActiveAction("Nothing");
		EndBattleLandInterface();
		//InitBattleInterface();
		//StartBattleInterface();
		//RefreshBattleInterface(true);

		//Восстановим адреса
		//Restores addresses
		mchr.location = boarding_adr[0].location;
		mchr.location.group = boarding_adr[0].group;
		mchr.location.locator = boarding_adr[0].locator;
		for(i = 1; i < OFFICER_MAX; i++)
		{
			idx = GetOfficersIndex(mchr, i);
			if (idx < 0) continue;
			Characters[idx].location = boarding_adr[i].location;
			Characters[idx].location.group = boarding_adr[i].group;
			Characters[idx].location.locator = boarding_adr[i].locator;
		}
// START MOD Code by Stone-D : 27/07/2003
		//Выгружаемся в интерфейс
		// We are unloaded into the interface
		LAi_boarding_process = false;
		CreateWeatherEnvironment(); // Baste

// LDH -->  Reset AlwaysRunToggle to pre-surrender dialog state is in cabinfight_dialog.c 03Sep06

// END MOD Code by Stone-D : 27/07/2003
//		SDLogIt("Check for ship");

		if (boarding_location_type == BRDLT_SHIP)
		{
// added by MAXIMUS [abordage MOD] -->
			if (CheckAttribute(refEnCharacter,"position"))		// changed back to refEnCharacter in this block of code
			{
			  /*  // eliminated
			  switch(refEnCharacter.position)
			  {
				case "loser": transferCaptain = true; break;
				case "corpse": transferCaptain = false; break;
				case "officer": transferCaptain = false; break;
				case "companion": transferCaptain = true; break;
				case "captive": transferCaptain = false; break;
			  }
			  */
			}
			else
			{
				refEnCharacter.status = "dead";
				refEnCharacter.position = "corpse";
				if(sti(refEnCharacter.index)>0) DeleteCharacter(refEnCharacter);	// Maximus change
				Trace(":");
				Trace("LAi_boarding.c -> twin character <" + refEnCharacter.id + "> was successfully deleted");
				Trace(":");
				//transferCaptain = false; // eliminated
			}
			noOfficers = false;

			if (endStat)
				SetEndingStats();
			else
				endStat = true;

			bCaptureShip = false;
// added by MAXIMUS [abordage MOD] <--

			if (GetCrewBoarding(mchr) > 0)		// crews will be zero if it's a fort after SetEndingStats()
			{
				SDLogIt("Crew/morale stats ending ReloadEndFade");	// remove after testing
				SDLogIt("Enemy crew = " + GetCrewBoarding(boarding_enemy) + ", Enemy morale = " + boarding_enemy.ship.crew.morale);	// remove after testing
				SDLogIt("Player crew = " + GetCrewBoarding(mchr) + ", Our morale = " + mchr.ship.crew.morale);					// remove after testing
			}

			// TIH --> fantom flag no longer needed by this point
			if (CheckAttribute(boarding_enemy,"isFantom")) { DeleteAttribute(boarding_enemy,"isFantom"); }
			if (CheckAttribute(refEnCharacter,"isFantom")) { DeleteAttribute(refEnCharacter,"isFantom"); }
			// TIH <--
			DeleteParticles(); // TIH get rid of flames and candles in sea ? maybe gets rid of other needed stuff too... Aug28'06
//			AssignCompanionComplete(refEnCharacter, boarding_enemy);//MAXIMUS: was in the first version of this mod. Now rewritten and works properly
			Group_UpdateGroup(boarding_enemy); // KK
			boarding_enemy.chr_ai.type = "stay"; // KK
			//MAXIMUS -->
			if(CheckAttribute(mchr,"quest.kill_pirate_complete") && boarding_enemy.id=="Quest pirate") LAi_QuestDelay("kill_pirate_complete",0);//MAXIMUS: just in case
			/*if(boarding_enemy.position!="companion") LaunchRansackMain(mchr, boarding_enemy, "");
			else
			{
				if(CheckAttribute(mchr,"boarding.companion") && sti(mchr.boarding.companion)!=-1)
				{
					ProceedShip(GetCharacter(sti(mchr.boarding.companion)));
					DeleteAttribute(mchr,"boarding.companion");
				}
				else LaunchRansackMain(mchr, boarding_enemy, "");
				boarding_enemy.position = "corpse";
				DeleteAttribute(refEnCharacter,"ship");
				refEnCharacter.Ship.type = SHIP_NOTUSED_TYPE_NAME;
				refEnCharacter.Ship.HP = 0;
			}*/
			if(!IsPassenger(refEnCharacter)) DeleteClass(&refEnCharacter);
			//MAXIMUS <--
			if(!CheckAttribute(boarding_enemy, "position") || boarding_enemy.position!="loser")
			{
				LAi_KillCharacter(boarding_enemy);// kill the original character off // KK
			}
			ChangeCharacterAddressGroup(refEnCharacter, "none", "", ""); // KK
			if(!CheckAttribute(boarding_enemy,"storedAttributes")) DeleteAttribute(boarding_enemy,"storedAttributes");
			RestoreCharacter(boarding_enemy);
			LaunchRansackMain(mchr, boarding_enemy, "");
			LAi_boarding_process = false;
			if(CheckAttribute(mchr,"TalkWithSurrenderedCaptain")) DeleteAttribute(mchr,"TalkWithSurrenderedCaptain");//MAXIMUS: just in case
			return;
		}

//		SDLogIt("Check for fort");
		if (boarding_location_type == BRDLT_FORT)
		{
// KK -->
			TownAbordageLoad();
			IsFort = false;
// <-- KK
			return;
		}

// KK -->
		if (boarding_location_type == BRDLT_TOWN)
		{
			// LDH - test this to make sure it works here.  Added with new boarding logic
			if (endStat)
				SetEndingStats();
			else
				endStat = true;

			LAi_boarding_process = false;
			bAbordageStarted = false;

			Go2LocationAfterAbordage();
			mchr.location.from_sea = Towns[GetTownIndex(boarding_enemy.town)].boarding.l1;
			SetFleetInTown(boarding_enemy.town, "pchar");

			ReloadToResidence(boarding_enemy);
			IsTown = false;
			return;
		}
// <-- KK

		Trace("Boarding: unknow boarding location type");
		SDLogIt("Boarding - unknown boarding location type : " + boarding_location_type);
		LAi_boarding_process = false;
	}
}

// added by MAXIMUS [abordage MOD] -->
// красиво убрать труп капитана
// it is beautiful to remove the corpse of the captain (hehe!)
#event_handler("LAi_RemoveDeadCap", "Lai_RemoveDeadBody");
void Lai_RemoveDeadBody()
{
	aref deadBody = GetEventData();
	if(CORPSEMODE==4) { deadBody.makelocator = true; }
	Lai_KillCharacter(deadBody);
}

#event_handler("LAi_Sharks", "StartSharks");
void StartSharks()
{
	object SharkFader;
	CreateEntity(&SharkFader, "fader");
	SendMessage(&SharkFader, "lfl", FADER_IN, 0.5, true);
	StartVideo("Sharks_attack");
	PostEvent("LAi_RemoveDeadCap", 0, "i", refEnCharacter);
	if(CheckAttribute(refEnCharacter,"prisoned")) DeleteAttribute(refEnCharacter,"prisoned");
}

#event_handler("LAi_KillCaptain", "StartKill");
void StartKill()
{
	object HangFader;
	CreateEntity(&HangFader, "fader");
	SendMessage(&HangFader, "lfl", FADER_IN, 0.5, true);
	StartVideo("Blaze_mutiny_dead");
	PostEvent("LAi_RemoveDeadCap", 0, "i", refEnCharacter);
	if(CheckAttribute(refEnCharacter,"prisoned")) DeleteAttribute(refEnCharacter,"prisoned");
}
// added by MAXIMUS [abordage MOD] <--

//Разрешить перегрузку на следующую палубу
// Event handler reload to the following deck
#event_handler("LAi_event_boarding_EnableReload", "LAi_EnableReload");
void LAi_EnableReload()
{
	int i, index, oldmorale, PlayerCrewLosses, crewchange, newmorale;
	int numBoardingActors = 0;		// LDH - actual PBC actors used in boarding
	ref chr, town;
	ref mchr = GetMainCharacter();
	aref arBoarding;
	SDLogIt("***EnableReload()");

	mchr.boardingReload = true; // KK

// START MOD Code by Stone-D : 01/08/2003
//MAXIMUS -->
	if(CheckAttribute(mchr, "abordagesound"))
	{
		StopSound(sti(mchr.abordagesound), 2000);
		DeleteAttribute(mchr, "abordagesound");
	}
	SetSchemeForLocation(&locations[FindLocation("ShipDeck1")]);//MAXIMUS <--
	SetMusic("music_abordage");

	//DeleteAttribute(mchr, "groupkill");	// LDH - Fixed in LAi_groups.c so LAi_EnableReload only gets called when all enemy dead

	// LDH moved from below 29Jan09
	//Уберём саблю
	// Put away the player's sword
	SendMessage(mchr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", 0);

	if (EndingStatsDone)	// LDH - EndingStatsDone set in SetEndingStatus() - LDH changed 27Jan09
	{
		SetEventHandler("Control Activation","LAi_ActivateReload",1);
		//if (boarding_location != -1) CheckReloadAction(mchr, ""); // KK
		return;
	}

	//Вернём выживших обратно в кучу
	// Let us return those who survived back to the crew
	for (i = 0; i < LAi_numloginedcharacters; i++)
	{
		index = LAi_loginedcharacters[i];
		if (index >= 0 && index != GetMainCharacterIndex()) {
			makeref(chr, Characters[index]);
			// Stone-D : Was including officers in the recount!
			if (!LAi_IsDead(chr) && !IsOfficer(chr) && !IsCompanion(chr) && chr.chr_ai.group == LAI_GROUP_PLAYER)
			{
				SDLogIt("Returned crewman: " + chr.name);	// comment out after test
				boarding_player_crew = boarding_player_crew + 1;
				numBoardingActors = numBoardingActors + 1;	// return one boarding actor
				if (WEAPONSLOCKER && GET_WEAPONS_BACK) GiveItemsBack(&chr); // NK get weaps back 05-05-10

				LAi_SetGuardianTypeNoGroup(chr);	// LDH - boarders go to start locations and wait - 06Feb09
			}
		}
	}

	PlayerCrewLosses = boarding_player_crew_start - boarding_player_crew;

	// LDH - Add survivors of last boarding back into the crew
	crewchange = GetCrewBoarding(mchr) + makeint(1.0 * numBoardingActors * boarding_player_crew_per_chr + 0.5);
	SDLogIt("Player crew change in LAi_EnableReload():  " + GetCrewBoarding(mchr) + " -> " + crewchange);
	SetCrewBoarding(mchr, crewchange);

	SurrenderModifier--;
	defeat = defeat + (10-SurrenderModifier);	// LDH - adds (4..9) to (1..300)

	if (!Surrendered)	// LDH 07Sep06 test added
	{
		Surrendered = CheckForSurrender(mchr, boarding_enemy);		// does not alter morale // KK
	}

	// LDH --> 23AUG06
	// Enemy morale should be adjusted as follows:
	// It will go down for each deck fought, adjusted by enemy captain's leadership skill
	// If we lose boarding characters, it will go up
	// Player crew morale should also be adjusted with each deck for crew loss
	// Player morale will go up if there are few losses - 20Jan09
	// Morale will drop by 5 for each deck fought through for both sides, represents fatigue etc.
	// Morale will get a final adjustment in SetEndingStats()
// KK -->
	if (!IsTown)
		oldmorale = sti(boarding_enemy.ship.crew.morale);
	else
		oldmorale = GetTownCrewMorale(boarding_enemy.town);
	SDLogIt("Enemy leadership skill = " + GetShipSkill(boarding_enemy,SKILL_LEADERSHIP));
	newmorale = iclamp(1, 99, oldmorale - 5 + makeint(GetShipSkill(boarding_enemy,SKILL_LEADERSHIP)/2)); // TIH must be ints Nov17'06 // NK skill //Rally or fall back?; // KK
	if (!IsTown)
		boarding_enemy.ship.crew.morale = newmorale;
	else
		SetTownCrewMorale(boarding_enemy.town, newmorale);
// <-- KK

	SDLogIt("Enemy morale change in LAi_EnableReload() " + oldmorale + " -> " + newmorale);
	oldmorale = newmorale;

	// LDH - adjust enemy morale upwards for player crew losses
	newmorale = iclamp(1,99,newmorale + PlayerCrewLosses * 3);
	boarding_enemy.ship.crew.morale = newmorale;
	SDLogIt("Enemy morale change for player crew losses " + oldmorale + " -> " + newmorale);

	// Player morale change
	oldmorale = sti(mchr.ship.crew.morale);
	newmorale = oldmorale - 5 - PlayerCrewLosses*3 + rand(makeint(GetShipSkill(mchr,SKILL_LEADERSHIP)/2)); // TIH rand must use int Nov17'06 // 30AUG06 add leadership

    // LDH 20Jan09 - add one to morale for each percent of surviving crew over 85% to max 10
	// LDH 20Jan09 - change it to a random number 0..limit
	newmorale += rand(iclamp(0,10, makeint((makefloat(boarding_player_crew)/boarding_player_crew_start-0.85)*100.0)));

	SDLogIt("Player morale change in LAi_EnableReload() " + oldmorale + " -> " + newmorale);
	mchr.ship.crew.morale = iclamp(1,99,newmorale);
	// LDH <--

//---------------------------------------
//	Surrendered = true;		// uncomment to test surrendered ships easily
//	SDLogIt("FORCED SURRENDER: enemy HAS surrendered after fighting on first deck");
//---------------------------------------

	SDLogIt("New PBC: " + boarding_player_crew);
	// KK SDLogIt("Next Location: " + Locations[boarding_location].boarding.nextdeck);

	// LDH - moved from above to make sure the calcs are done before exit
	SetEventHandler("Control Activation","LAi_ActivateReload",1);

	//if (boarding_location != -1) CheckReloadAction(mchr, ""); // KK
// END MOD Code by Stone-D : 01/08/2003
}

//Активация перегрузки на следующую палубу
// Activation of reload to the following deck
void LAi_ActivateReload()
{
//	SDLogIt("***ActivateReload()");		// Uncommenting this gives many many entries in the log
	int tmpi;
	ref mchr = GetMainCharacter(); 
	ref chr;
	string controlName = GetEventData();
	if (controlName != "ChrAction") return;
	//if (CheckAttribute(mchr, "TalkWithSurrenderedCaptain") || LAi_group_IsActivePlayerAlarm()) return; // KK
// changed by MAXIMUS [for speaking with officers on Boarding Deck by ordinary way] -->
	tmpi = SendMessage(mchr, "ls", MSG_CHARACTER_EX_MSG, "FindDialogCharacter");
	if (tmpi >= 0) {
		chr = GetCharacter(tmpi);
		if (CheckAttribute(chr, "Dialog.Filename") && !CheckAttribute(chr, "corpse")) {
			Event("dlgReady","l",tmpi);
		} else {
			Log_SetActiveAction("Nothing");
			LAi_ReloadBoarding();
		}
	} else {
		Log_SetActiveAction("Nothing");
		LAi_ReloadBoarding();
	}
// changed by MAXIMUS [for speaking with officers on Boarding Deck by ordinary way] <--
}

//Расставить персонажей для боя
// To arrange characters for the battle
void LAi_SetBoardingActors(string locID, string chLocType, string enLocType)
{
// START MOD Code by Stone-D : 30/07/2003
	SDLogIt("***LAi_SetBoardingActors()");
	int i, limit, elimit, mlimit;
	ref chr;
	ref mchr = GetMainCharacter();
	string model;
	string ani;
	string bString = "blade";
	int mchr_rank = sti(mchr.rank) - 1;
	int xhp;
	int locIndex = FindLocation(locID);

// KK -->
	int iNation = PERSONAL_NATION;
	string gmodel = "";

	int boarderindex_val = 0;
	string boardermodel_val = "";
	if (CheckAttribute(mchr, "Boarder.Index"))
	{
		boarderindex_val = sti(mchr.Boarder.Index);
	}
	else
	{
		boarderindex_val = BOARDER_INDEX;
	}
	if (CheckAttribute(mchr, "Boarder.Model"))
	{
		boardermodel_val = mchr.Boarder.Model;
	}
	else
	{
		boardermodel_val = BOARDERMODEL;
	}

	int boarder_num = boarderindex_val;
	if (boardermodel_val == "soldier" || boardermodel_val == "boarder")
	{
		if (boarding_enemy.nation != mchr.nation) iNation = sti(mchr.nation);
		if (iNation == PERSONAL_NATION && boarderindex_val == 100) boarder_num = 6;
		if (boardermodel_val == "boarder" && boarderindex_val == 100) boarder_num = 6;
	}
// <-- KK

	limit = GetBoardingLimit(locIndex);

	mlimit = sti(mchr.mlimit);
	elimit = sti(mchr.elimit);

	//Установим союзников из команды
	// Let us establish allies from the command
	// NK -->

	int numBoardingActors = 0;		// LDH - actual PBC used in boarding
	int startlocnum = LAi_numloginedcharacters;
	if(IsTown) startlocnum = 1;		// PB: So that BuildingSet characters are ignored - add GetOfficersQuantity(mchr) when we add officers to the attacks
	int locnum = startlocnum;		// "loc"+locnum to get boarding location
	for(i = startlocnum; i < mlimit; i++)
	{
		if (boarding_player_crew <= 0) break;

		// ccc Boardingparty
		if (boardermodel_val == "") // KK
		{
			model = LAi_GetBoardingModel(mchr, &ani);	//ccc original code // KK
		}
		else
		{
// added by MAXIMUS [abordage mod] -->
			if ((boarderindex_val == 0) || (boarderindex_val == 100)) boarder_num++;
			switch(boardermodel_val)
			{
				case "skeleton": gmodel = SelectBoardingGroup("skel", 1, 4, boarder_num, "man"); model = ExtractBoarderModel(gmodel); break;
				case "corsair": gmodel = SelectBoardingGroup("corsair", 1, 5, boarder_num, "man"); model = ExtractBoarderModel(gmodel); break;
				case "marine": gmodel = SelectBoardingGroup("rn_warnt18_", 1, 5, boarder_num, "man"); model = ExtractBoarderModel(gmodel); break;
				case "masked": gmodel = SelectBoardingGroup("mask_", 2, 4, boarder_num, "man"); model = ExtractBoarderModel(gmodel); break;
				case "girl": gmodel = SelectBoardingGroup("towngirl", 1, 7, boarder_num, "woman"); model = ExtractBoarderModel(gmodel); break;
				case "soldier": gmodel = SelectBoardingSoldiers(iNation, boarder_num); model = ExtractBoarderModel(gmodel); break;
				case "boarder": gmodel = SelectBoardingBoarders(boarder_num); model = ExtractBoarderModel(gmodel); break;
				case "standard": model = LAi_GetBoardingModel(mchr, &ani); break;
			}
// added by MAXIMUS [abordage mod] <--
		}

		// LDH if WEAPONSLOCKER is used, don't generate friendly boarders with weapons - 07May09
		string officertype = GetBoardingCrewType(mchr);
		if (WEAPONSLOCKER)
		{
			chr = LAi_CreateFantomCharacterExOt(true, officertype, GetBoardingCrewRank(mchr), false, 0.0, model, "rld", chLocType + locnum);
			// do SPAREBLADE inside EquipFromLocker() NK 05-07-18
			EquipFromLocker(chr);
			CheckCharacterCurse(chr); // PB: Cursed Coins
		}
		else
		{
			chr = LAi_CreateFantomCharacterExOt(true, officertype, GetBoardingCrewRank(mchr), true, BOARDER_HAS_GUN_PROB, model, "rld", chLocType + locnum);
		}
		chr.nation = GetServedNation(); // PB: Set nation of own boarding crew to your served nation
		SetRandomNameToCharacter(chr);  // PB: Update character name to match

		locnum++;
		// PB: Don't reuse locators unless needed -->
		if(IsTown || IsFort){
			if (locnum >  GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}else{
			if (locnum >= GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}
		// PB: Don't reuse locators unless needed <--

		// ccc section 1 end

		//JRH fix oct 06: boarders don't use ammo, code removed & it didnґt work anyway

		LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
		LAi_SetFightMode(chr, false); 					   //JRH long guns didn't fire
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 0); //JRH long guns didn't fire
		LAi_SetFightMode(chr, true); // KK
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1); // KK
		xhp = makeint(boarding_player_hp);
		LAi_SetHP(chr, xhp, xhp);
		chr.donotshowXP = true; // so friend XP boosts do not show.
//		SDLogIt("Selected crewman: " + chr.name);
		boarding_player_crew = boarding_player_crew - 1;
		numBoardingActors = numBoardingActors + 1;	// add one boarding actor
	}
	// NK <--

	// LDH
	int crewchange = GetCrewBoarding(mchr) - makeint(1.0 * numBoardingActors * boarding_player_crew_per_chr + 0.5);
	SDLogIt("Player crew change in SetBoardingActors():  " + GetCrewBoarding(mchr) + " -> " + crewchange);
	SetCrewBoarding(mchr, crewchange);

	//Установим врагов
	// Let us establish the enemies
	numBoardingActors = 0;
	startlocnum = 0;
	locnum = startlocnum;
// KK -->
	i = 0;
	if ("BOARDING_" + GetCharacterShipCabin(boarding_enemy) == locID && boarding_enemy_crew > 0) {
		LAi_SetLoginTime(refEnCharacter, 0.0, 24.0);

		ChangeCharacterAddressGroup(refEnCharacter, locID, "rld", enLocType + locnum);
		locnum++;
		// PB: Don't reuse locators until needed -->
		if(IsTown || IsFort){
			if (locnum >  GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}else{
			if (locnum >= GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}
		// PB: Don't reuse locators until needed <--

		LAi_group_MoveCharacter(refEnCharacter, LAI_GROUP_BRDENEMY);
		LAi_SetWarriorTypeNoGroup(refEnCharacter);
		LAi_SetFightMode(refEnCharacter, false); 					   //JRH long guns didn't fire
		SendMessage(&refEnCharacter, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 0); //JRH long guns didn't fire
		LAi_SetFightMode(refEnCharacter, true);
		SendMessage(&refEnCharacter, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);

		if (boarding_enemy_hp < 80)
			xhp = 80;
		else
			xhp = 2*boarding_enemy_hp;

		LAi_SetHP(refEnCharacter, xhp, xhp);

		refEnCharacter.donotshowXP = true; // so enemy XP boosts do not show.
		boarding_enemy_crew = boarding_enemy_crew - 1;
		numBoardingActors = numBoardingActors + 1;
		i++;
	}
	while (i < elimit)
	{
		if (boarding_enemy_crew <= 0) break;
		model = LAi_GetBoardingModel(boarding_enemy, &ani);
		officertype = GetBoardingCrewType(boarding_enemy);
		//chr = LAi_CreateFantomCharacterExOt(false, boarding_erank-mchr_rank, true, officertype, GetBoardingCrewRank(boarding_enemy), true, BOARDER_HAS_GUN_PROB, model, "rld", enLocType + locnum); //Changed by Levis
		chr = LAi_CreateFantomCharacterRk(false, GetBoardingCrewRank(boarding_enemy), false, officertype, true, BOARDER_HAS_GUN_PROB, model, "rld", enLocType + locnum); //Changed by Levis

		// PB: Set Boarder Nations -->
		chr.nation = boarding_enemy_nation;
		SetRandomNameToCharacter(chr);
		// PB: Set Boarder Nations <--

/*		if(!IsShipMerchant(boarding_enemy) && boarding_enemy_nation != PIRATE && !CheckAttribute(boarding_enemy, "skipSoldierWeapons"))
		{
			GiveSoldierWeapon(chr, boarding_enemy_nation);	// ARF: Update Soldier Weapons
		}*/

		locnum++;
		// PB: Don't reuse locators until needed -->
		if(IsTown || IsFort){
			if (locnum >  GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}else{
			if (locnum >= GetBoardingLimit(locIndex)/2) locnum = startlocnum;
		}
		// PB: Don't reuse locators until needed <--

		LAi_group_MoveCharacter(chr, LAI_GROUP_BRDENEMY);
		LAi_SetFightMode(chr, false); 					   //JRH long guns didn't fire
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 0); //JRH long guns didn't fire
		LAi_SetFightMode(chr, true);
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);

		if (boarding_enemy_hp < 40)
			xhp = 40;
		else
			xhp = boarding_enemy_hp;

		LAi_SetHP(chr, xhp, xhp);
		chr.donotshowXP = true; // so enemy XP boosts do not show.
		boarding_enemy_crew = boarding_enemy_crew - 1;
		numBoardingActors = numBoardingActors + 1;
		i++;
	}
	// Let us force to fight these 2 groups
// changed by MAXIMUS [abordage mod] -->
	if ("BOARDING_" + GetCharacterShipCabin(boarding_enemy) != locID)
		LAi_group_FightGroupsEx(LAI_GROUP_PLAYER, LAI_GROUP_BRDENEMY, true, GetMainCharacterIndex(), -1, false, false);
	else
		LAi_group_FightGroupsEx(LAI_GROUP_PLAYER, LAI_GROUP_BRDENEMY, true, GetMainCharacterIndex(), GetCharacterIndex(refEnCharacter.id), false, false);

	LAi_QuestDelay("Abordage_Quest", 0.0); // KK was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
// changed by MAXIMUS [abordage mod] <--
// <-- KK

	// take away enemy crew for the number of actors we just added to the interface
	crewchange = GetCrewBoarding(boarding_enemy) - makeint(1.0 * numBoardingActors * boarding_enemy_crew_per_chr + 0.5);
	SDLogIt("Enemy crew change in SetBoardingActors():  " + GetCrewBoarding(boarding_enemy) + " -> " + crewchange);
	SetCrewBoarding(boarding_enemy, crewchange);
//	PostEvent(EVENT_CHANGE_OFFICERS, 500);//MAXIMUS: officers-icons fixed

// END MOD Code by Stone-D : 30/07/2003
}

//Убийство группы
// Death of the enemy group
// event handler, activated in LAi_group_CheckGroupQuest().  Changed from call once for each dead enemy to call once when all enemy dead // KK -->
/*void LAi_BoardingGroupKill()
{
	SDLogIt("***BoardingGroupKill()");
	string group = GetEventData();
	if (group != LAI_GROUP_BRDENEMY && group != LAI_GROUP_CORPSES) return;
	PostEvent("LAi_event_boarding_EnableReload", 5000);
}*/
// <-- KK

//Моделька для абордажного персонажа
// Model for the boarding character
string LAi_GetBoardingModel(ref rCharacter, ref ani)
{
	int i, num, sex, iNation;
	string model, atr;
	aref models;
	ref cmodel;
	// NK modeltypes 05-07-28
	if (CheckAttribute(rCharacter, "boardingmodels"))
	{
		sex = "";
		iNation = ALL_NATIONS;
		if (CheckAttribute(rCharacter, "boardingmodels.sex")) sex = rCharacter.boardingmodels.sex;
		if (CheckAttribute(rCharacter, "boardingmodels.nation")) iNation = sti(rCharacter.boardingmodels.nation);
		cmodel = ModelFromID(GetRandomModelForTypeExSubCheck(1, rCharacter.boardingmodels, sex, iNation));	// KK
		ani = cmodel.ani;
		return cmodel.id;
	}
	// NK <--
	ani = "man";
	iNation = sti(rCharacter.nation);
	// LDH This is why we used to fight pirates on surrendered ships.  Their nation is NEUTRAL_NATION = MAX_NATIONS
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) iNation = PIRATE; // added by MAXIMUS, changed by LDH

	// PB: Sailors instead of soldiers on merchant ships -->
	bool SailorCrew = false;
	if (IsMainCharacter(rCharacter))
	{
		atr = "boardingModel.player";
	}
	else
	{
		atr = "boardingModel.enemy";
		SailorCrew = IsShipMerchant(rCharacter) || iNation == PIRATE;
		SailorCrew = SailorCrew && !IsTown && !IsFort;
	}

	if (SailorCrew)
	{
		ani   = "man";
		model = GetRandomModelForTypeExSubCheck(1, "Sailors", ani, iNation);
	}
	// PB: Sailors instead of soldiers on merchant ships <--
	else
	{
		if (!CheckAttribute(&Nations[iNation], atr)) return ""; // KK
		makearef(models, Nations[iNation].(atr));
		num = GetAttributesNum(models);
		if (num <= 0) return "";
		i = rand(num - 1);
		atr = GetAttributeName(GetAttributeN(models, i));
		model = models.(atr);
		atr += ".ani";
		if (CheckAttribute(models, atr) == true && models.(atr) != "") ani = models.(atr);
	}
	return model;
}

// START MOD Code by Stone-D : 27/07/2003
bool CheckForSurrender(ref mchr, ref echr)
{
	SDLogIt("***CheckForSurrender()");

	if (CheckAttribute(echr,"surrendered")) return true;	// surrendered before boarding

	if (IsFort || IsTown) return false;	// LDH - Forts don't surrender
	if (CheckAttribute(echr, "nosurrender") == true && sti(echr.nosurrender) > 1) return false; // KK

	if (GetCrewBoarding(mchr) < GetMinCrewQuantity(mchr) && GetCrewBoarding(echr) < GetMinCrewQuantity(echr))
	{
		SDLogIt("Surrender because both crews are below minimum");
		SDLogIt("mcrew = " + GetCrewBoarding(mchr) + ", min = " + GetMinCrewQuantity(mchr) + ", ecrew = " + GetCrewBoarding(echr) + ", min = " + GetMinCrewQuantity(echr));
		return true;
	}

	float SurrenderChance = 0.10;	// base chance of surrender, 10%

	int emorale = GetAdjustedMorale(mchr, echr, false);
	if (emorale < sti(mchr.ship.crew.morale) / 2) SurrenderChance += 0.02;
	if (emorale > sti(mchr.ship.crew.morale) * 2) SurrenderChance -= 0.02;
	SurrenderChance += GetShipSkill(mchr,SKILL_LEADERSHIP) * 0.005;
	SurrenderChance -= GetShipSkill(echr,SKILL_LEADERSHIP) * 0.005;
	SurrenderChance -= (GetDifficulty() - 3.0) * 0.02;	// d1 +.04, d2 +.02 d3 0.0 d4 -.02

	SDLogIt("Chance of enemy surrendering: " + SurrenderChance*100.0 + " percent");

	if (frnd() < SurrenderChance || Surrendered)
	{
		SDLogIt("Enemy HAS SURRENDERED");
		return true;
	}
	else
	{
		SDLogIt("Enemy HAS NOT Surrendered");
		return false;
	}
}

// Adjusts morale for enemy
int GetAdjustedMorale(ref mchr, ref echr, bool FinalAdjust)
{
	SDLogIt("***GetAdjustedMorale()");

	int morale = sti(echr.ship.crew.morale);
	if (boarding_location_type == BRDLT_FORT) return morale; // Forts don't surrender. 04-09-22 return current morale

	int mclass = GetCharacterShipClass(mchr);
	int eclass = GetCharacterShipClass(echr);
	int mCrewQ = GetCrewBoarding(mchr);
	int eCrewQ = GetCrewBoarding(echr);

	int mfight = boarding_player_crew;	// # of representative fighters
	int efight = boarding_enemy_crew;	// # of representative fighters

	if (IsTown) eclass = 0; // KK

	if (mclass < eclass)		// if our ship is bigger, morale goes down a bit
		morale = morale - ((eclass - mclass) * 2);  // Slightly nervous but not overmuch
	else	// mclass >= eclass	   if their ship is bigger, morale goes up a lot
		morale = morale + ((mclass - eclass) * 10);  // Ohhh, you are soooo DEAD!

	if (((mCrewQ + eCrewQ) > GetMaxCrewQuantity(&mchr)) && sti(mchr.reputation) < 31)  // See note #2 at function end
		morale = morale + 10 + rand(10);

	morale = morale - makeint( ( 100-GetHullPercent(echr) )/10 );	// TIH int assignment incorrect Nov17'06// LDH 23AUG06 added divide by 10, tweak
	if (GetHullPercent(echr)<25.0) morale = morale - 5;		// See note #3 at function end
	if (GetHullPercent(echr)<10.0) morale = morale - 10;	// "Hey Jimbo, see that play at the Discovery theatre about sharks last month?"
	if ((eCrewQ*2) < mCrewQ) morale=morale - 10;			// See note #4 at function end
	if (mfight > efight) morale = morale - 5;
	if (mfight < efight) morale = morale + 5;
	if (FinalAdjust)
	{
		if (SurrenderModifier <= 0) SurrenderModifier = 1;	// added by MAXIMUS [for excluding error 'divide by zero']
		int losing = makeint(defeat/SurrenderModifier);		// See note #1 at function end ((1..300)+repeat(4..9))/(6..1) example at 3rd deck: (75+15)/4 = 22 (13,17,22,32,etc)
		if (losing < GetShipSkill(&mchr,SKILL_SNEAK)) losing = GetShipSkill(&mchr,SKILL_SNEAK); // NK skill // Defence against weird negative value
		morale = morale - losing;				// See note #5 at function end
	}
	if (eCrewQ <= GetMinCrewQuantity(echr)) morale = morale - 10;
	morale = iclamp(1, 99, morale);		// LDH added 01SEP06 after getting enemy morale 105

	return morale;

/*
Note #1
'SurrenderModifier' is an indicator of your progress through a ship's
infrastructure and is subtracted by one each time you clear a deck.
Defeat is used and defined in both functions at the moment.  Not very
efficient, but WTF. Used to be Defeat - Defeat moved to the top, then
added Losing to maintain consistency.

Note #2
This essentially states what the enemy's crew thinks of their chances
should they surrender. If your crew plus their surviving crew exceeds
your ship's capacity AND you're reputed to be a bloody bastard  - ie,
you sink ships coz it looks kinda neat - they will want to take their
chances and attempt  to take YOUR ship instead of surrendering.  What
do they have to lose? Note that THEY don't know how many officers you
have... basically, whether or not you can take the ship if you wanted
to.  Being somewhat uniform-less, the wankers waving sharpened pieces
of metal at them could just be regular crew for all they know.

Note #3
Their ship is leaking badly and is unlikely to make it to port.  They
won't exactly be singing and dancing, now will they? Yo ho bloody ho,
fuck your damned rum and help me plug this fuckin' leak!

Note #4
There's waaay more of you than them. NOT good. Change Multiplier to 3
if you haven't fixed the enemy ship's starting crew numbers.

Note #5
No more sailing happily into the sunset for you, matey!  You've gotta
cheer up the crew on the captured ship now.  :)
*/
}
// END MOD Code by Stone-D : 27/07/2003


// START MOD Code by Stone-D : 30/07/2003
// Note: make sure this is run before surrender dialog
void SetEndingStats()
{
	SDLogIt("***SetEndingStats()");

	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	int PBMM;	// Post-Battle Morale Modifier, will be added to player ship morale
	int tempPBMM;
	ref PlayerChar = GetMainCharacter();
	int mclass = GetCharacterShipClass(PlayerChar);
	int eclass = GetCharacterShipClass(boarding_enemy);

	if (IsTown) eclass = 0; // KK

	SDLogIt("Player Class: " + mclass + " Enemy Class: " + eclass);

	PBMM = 0;
	float CrewRemainingPercent = 100.0 * GetCrewBoarding(Playerchar) / stf(PlayerChar.origcrew);
	tempPBMM = MakeInt(-0.4 * (100.0-CrewRemainingPercent));		// lose 20% of crew, morale goes down by 8
	SDLogIt("PBMM Crew loss     = " + tempPBMM);
	PBMM += tempPBMM;

	tempPBMM = -(DEFAULT_SURRENDER_MODIFIER - SurrenderModifier) * 2;	// adjust for battle length
	SDLogIt("PBMM Battle Length = " + tempPBMM);
	PBMM += tempPBMM;

	tempPBMM = GetShipSkill(PlayerChar,SKILL_LEADERSHIP)/2;	// adjust for leadership of player and officers
	SDLogIt("PBMM Leadership    = " + tempPBMM);
	PBMM += tempPBMM;

	// Stone-D : The player can minimize morale loss by taking on ships bigger than his own. And winning, of course.
	if (eclass < mclass)
	{
		tempPBMM = rand((mclass - eclass) * 10);						// adjust for enemy ship class
		SDLogIt("PBMM Ship Class    = " + tempPBMM);
		PBMM += tempPBMM;
	}
	SDLogIt("PBMM final adjustment = " + PBMM);

//	if (IsFort) PlayerChar.ship.crew.quantity = makeint(crew +0.5); // NK 04-09-22 will set sqdrn crew from this in fortcapture.c

	SDLogIt("Player Morale: " + sti(PlayerChar.ship.crew.morale) + " --> " + makeint(sti(PlayerChar.ship.crew.morale)+PBMM));
	// KK LogIt(LanguageConvertString(tmpLangFileID,"Player Morale") + ": " + sti(PlayerChar.ship.crew.morale) + " --> " + makeint(sti(PlayerChar.ship.crew.morale)+PBMM)); //NK

	PlayerChar.ship.crew.morale = sti(PlayerChar.ship.crew.morale) + PBMM; // Stone-D : Better spread that loot or the crew will have words...
	PlayerChar.ship.crew.morale = iclamp(1, 99, sti(PlayerChar.ship.crew.morale));
	if (boarding_enemy_crew < 1) boarding_enemy_crew = 1;

	if (boarding_echr_index >= 0 && !IsFort && !IsTown) // 04-09-22 // KK
	{
// KK -->
		if (CheckAttribute(boarding_enemy, "nosurrender") == true && sti(boarding_enemy.nosurrender) == 3)	// some character's crew (ex. Barbossa in standard storyline) will fight to last man standing
		{
			SetCrewQuantity(boarding_enemy, 0);
			boarding_enemy.ship.crew.morale = MORALE_NORMAL;
		}
		else	// normal boarding
		{
			boarding_enemy.ship.crew.morale = GetAdjustedMorale(PlayerChar, boarding_enemy, true);	// set final morale after battle
		}
// <-- KK

		SDLogIt("Enemy Morale: " + boarding_enemy.ship.crew.morale);
		boarding_echr_index = -1;
	}

	DeleteAttribute(PlayerChar,"origcrew");		// NK - Moved by LDH
	SDLogIt("Setting player ship crew to " + GetCrewBoarding(PlayerChar));
	SetCrewQuantity(PlayerChar, GetCrewBoarding(PlayerChar));		// LDH note this will fill our crew after a fort and cause crew overup errors which can be ignored
	SetCrewQuantity(boarding_enemy, GetCrewBoarding(boarding_enemy));
	DeleteCrewBoarding(PlayerChar);
	DeleteCrewBoarding(boarding_enemy);
	DeleteAttribute(PlayerChar,"mlimit");
	DeleteAttribute(PlayerChar,"elimit");
	EndingStatsDone = true;					// LDH - to keep reload event handler from running after boarding is done

	//LanguageCloseFile(tmpLangFileID);

	// LDH - if we board a surrendered ship, group leader has already changed, so it's not a problem.
	// We may need different processing if we let the group leader go free. Changes ship to surrendered
	//UpdateGroup(sti(boarding_enemy.index));	// LDH 10Oct06 - Commented out for now
}

// END MOD Code by Stone-D : 30/07/2003

// KK -->
string SelectBoardingSoldiers(int iNation, int soldier_num)
{
	int i;
	int ulimit = 6;
	int boarderindex_val = 0;
	string smodel = "";
	string ani = "";
	ref mchr = GetMainCharacter();
	aref artmp;

	if (iNation == PERSONAL_NATION && CheckAttribute(mchr, "Soldier") == true) {
		makearef(artmp, mchr.Soldier);
		ulimit = GetAttributesNum(artmp);
	}
	if (iNation == PIRATE) ulimit = 11;
	if (CheckAttribute(mchr, "Boarder.Index"))
		boarderindex_val = sti(mchr.Boarder.Index);
	else
		boarderindex_val = BOARDER_INDEX;
	if (boarderindex_val == -1)
		i = FRAND(ulimit);
	else
		i = soldier_num;
	if (i < 1) i = 1;
	if (i >= ulimit) i = ulimit;

	if (iNation >= 0 && iNation < NATIONS_QUANTITY && iNation != PIRATE) {
		smodel = "m" + i;
		if (CheckAttribute(Nations[iNation], "fantomModel."+smodel))
			smodel = Nations[iNation].fantomModel.(smodel) + "M";
		else
			smodel = SelectBoardingSoldiers(PERSONAL_NATION, soldier_num);
	}
	if (iNation == PIRATE) {
		smodel = "pirat" + i + "M";
	}
	if (iNation == PERSONAL_NATION) {
		smodel = "m" + i;
		if (CheckAttribute(mchr, "Soldier." + smodel) && mchr.Soldier.(smodel) != "") {
			smodel = mchr.Soldier.(smodel) + "M";
		} else {
			smodel = LAi_GetBoardingModel(mchr, &ani);
			if (ani == "man")
				smodel += "M";
			else
				smodel += "W";
		}
	}
	if (iNation == NEUTRAL_NATION) {
		if (i > 1)
			smodel = "towngirl" + i + "W";
		else
			smodel = "towngirlW";
	}

	return smodel;
}

string SelectBoardingBoarders(int soldier_num)
{
	int i;
	int ulimit = 6;
	int boarderindex_val = 0;
	string smodel = "";
	string ani = "";
	ref mchr = GetMainCharacter();

	if (CheckAttribute(mchr, "Boarder.Count")) ulimit = sti(mchr.Boarder.Count);
	if (CheckAttribute(mchr, "Boarder.Index"))
		boarderindex_val = sti(mchr.Boarder.Index);
	else
		boarderindex_val = BOARDER_INDEX;
	if (boarderindex_val == -1)
		i = FRAND(ulimit);
	else
		i = soldier_num;
	if (i < 1) i = 1;
	if (i >= ulimit) i = ulimit;

	smodel = "m" + i;
	if (CheckAttribute(mchr, "Boarder." + smodel) && mchr.Boarder.(smodel) != "") {
		smodel = mchr.Boarder.(smodel);
	} else {
		smodel = LAi_GetBoardingModel(mchr, &ani);
		if (ani == "man")
			smodel += "M";
		else
			smodel += "W";
	}

	return smodel;
}

string SelectBoardingGroup(string group, int group_start, int group_end, int member_num, string sex)
{
	int i;
	int boarderindex_val = BOARDER_INDEX;
	string gmodel = group;
	ref mchr = GetMainCharacter();

	if (CheckAttribute(mchr, "Boarder.Index")) boarderindex_val = sti(mchr.Boarder.Index);
	if (boarderindex_val == -1)
		i = group_start + FRAND(group_end - group_start);
	else
		i = member_num;
	if (i < group_start) i = group_start;
	if (i > group_end) i = group_end;

	gmodel += i;

	switch(sex) {
		case "man":
			gmodel = gmodel + "M";
		break;
		case "woman":
			gmodel = gmodel + "W";
		break;
		case "skeleton":
			gmodel = gmodel + "S";
		break;
	}

	return gmodel;
}

string ExtractBoarderModel(string smodel)
{
	return strcut(smodel, 0, strlen(smodel)-2);
}

string ExtractBoarderAni(string smodel)
{
	int lngth = strlen(smodel);
	string nani = strcut(smodel, lngth-1, lngth-1);
	switch (nani) {
		case "M":
			return "man";
		break;
		case "S":
			return "man";
		break;
	}
	return "woman";
}

string ExtractBoarderSex(string smodel)
{
	int lngth = strlen(smodel);
	string nani = strcut(smodel, lngth-1, lngth-1);
	switch (nani) {
		case "M":
			return "man";
		break;
		case "S":
			return "skeleton";
		break;
	}
	return "woman";
}

string GetNextBoardingLocation()
{
	int townidx, locidx, nboardingdeck;
	string sdistrict, boarding_deck, boarding_cabin;
	if (IsFort) {
		if (nfort < GetFortBoardingLocationsCount()) {
			nfort++;
			PrepareLocationForBoardingFort();
			return "BOARDING_Fort";
		}
		TownAbordageLoad();
		return "BOARDING_Town";
	}
	if (IsTown) {
		cdistrict++;
		sdistrict = "l" + cdistrict;
		townidx = GetTownIndex(boarding_enemy.town);
		if (townidx < 0) return "";
		if (!CheckAttribute(Towns[townidx], "boarding." + sdistrict)) return "";
		PrepareLocationForBoardingTown(Towns[townidx].boarding.(sdistrict));
		return "BOARDING_Town";
	}
	if (ncannonsdeck == -1 && ncargohold == -1) return "";
	boarding_deck = "BOARDING_" + GetCharacterShipQDeck(boarding_enemy);
	nboardingdeck = sti(getsymbol(boarding_deck, strlen(boarding_deck) - 1));
	boarding_cabin = "BOARDING_" + GetCharacterShipCabin(boarding_enemy);
	if (IsSingleDeck(boarding_deck) && !bMCAbordageInitiator) {
		bMCAbordageInitiator = true;
		return boarding_deck;
	}
	bMCAbordageInitiator = true;
	if (ncannonsdeck < GetCharacterShipCannonsDeckCount(boarding_enemy)) {
		ncannonsdeck++;
		return "BOARDING_Deck" + ncannonsdeck;
	}
	if (ncargohold < GetCharacterShipCargoHoldCount(boarding_enemy)) {
		ncargohold++;
		return "BOARDING_Hold";
	}
	ncannonsdeck = -1;
	ncargohold = -1;
	return boarding_cabin;
}

bool IsSingleDeck(string boarding_locationID)
{
	bool ret = true;
	if (!HasSubStr(boarding_locationID, "BOARDING_ShipDeck")) return ret;
	if (HasSubStr(boarding_locationID, "vs")) ret = false;
	if (boarding_locationID == "BOARDING_ShipDeck1") ret = false;
	return ret;
}

int GetFortBoardingLocationsCount()
{
	int fort_cannons_qty = Fort_GetCannonsQuantity(boarding_enemy);
	if (fort_cannons_qty <= 20) return 1;
	if (fort_cannons_qty <= 40) return 2;
	return 3;
}

void PrepareLocationForBoardingFort()
{
	int fortidx, homeland;
	string town; 
	ref fort;

	fortidx = FindLocation("BOARDING_Fort");
	if (fortidx < 0) return;
	town = boarding_enemy.town;
	homeland = GetTownHomeland(town);
	makeref(fort, Locations[fortidx]);
	fort.filespath.models = "locations\Fort_inside\Fort_" + nfort + "\\";
	if (homeland == SPAIN || homeland == PORTUGAL)
		fort.filespath.textures = "locations\SPAIN";
	else
		DeleteAttribute(fort, "filespath.textures");
	fort.image = "Fort_Inside_Fort_" + nfort + ".tga";
	fort.models.always.locators = "fort" + nfort + "_l";
	fort.models.always.l1 = "fort" + nfort;
	fort.models.day.charactersPatch = "fort" + nfort + "_p";
	fort.models.day.fonar = "fort" + nfort + "_fd";
	fort.models.night.charactersPatch = "fort" + nfort + "_p";
	fort.models.night.fonar = "fort" + nfort + "_fn";
	fort.townsack = town;
	fort.island = GetIslandIDFromTown(town);
	if (nfort == 1)
		fort.Environment.Sea = "false";
	else
		fort.Environment.Sea = "true";
}

void PrepareLocationForBoardingTown(string loc)
{
	int locidx = FindLocation(loc);
	int boarding_town_idx = FindLocation("BOARDING_Town");
	ref boarding_town, rloc;

	if (locidx < 0 || boarding_town_idx < 0) return;
	makeref(rloc, Locations[locidx]);
	makeref(boarding_town, Locations[boarding_town_idx]);

	DeleteAttribute(boarding_town, "");
	CopyAttributes(boarding_town, rloc);

	boarding_town.id = "BOARDING_Town";
	boarding_town.id.label = "Boarding town";
	boarding_town.index = boarding_town_idx;
	boarding_town.type = "deck";
	boarding_town.boarding = "town";
	boarding_town.vcskip = true;
	boarding_town.models.always.locators = rloc.models.always.locators + "b";
	if (CheckAttribute(boarding_town, "worldmap")) DeleteAttribute(boarding_town, "worldmap");
	if (CheckAttribute(boarding_town, "fastreload")) DeleteAttribute(boarding_town, "fastreload");
	if (CheckAttribute(boarding_town, "fantoms")) DeleteAttribute(boarding_town, "fantoms");
	if (CheckAttribute(boarding_town, "music")) DeleteAttribute(boarding_town, "music");
	if (CheckAttribute(boarding_town, "reload")) DeleteAttribute(boarding_town, "reload");
}

void TownAbordageLoad()
{
	ref mchr = GetMainCharacter();
	int townidx;

	boarding_enemy.Fort.Mode = FORT_DEAD;
	boarding_enemy.nation = NEUTRAL_NATION;
	// data of fort die
	boarding_enemy.Fort.DieTime.Year = GetDataYear();
	boarding_enemy.Fort.DieTime.Month = GetDataMonth();
	boarding_enemy.Fort.DieTime.Day = GetDataDay();
	boarding_enemy.Fort.DieTime.Time = GetTime();

	mchr.location.from_sea = "BOARDING_Town";

	if (CheckAttribute(boarding_enemy, "town")) {
		townidx = GetTownIndex(boarding_enemy.town);
		if (townidx >= 0) {
			SetUpGovernor();
			cdistrict = 1;
			PrepareLocationForBoardingTown(Towns[townidx].boarding.l1);
			boarding_location_type = BRDLT_TOWN;
			IsFort = false;
			IsTown = true;
		}
	}
}

void SetUpGovernor()
{
	bool governor_exists = false;
	bool fortcommandant_exists = false;
	int i, govidx, fcidx, locidx, iNation, captured_governor_idx;
	string skillname;
	string town = boarding_enemy.town;
	string sdistrict;
	ref captured_governor = characterFromID("Captured governor");
	ref gov = boarding_enemy;

	captured_governor_idx = GetCharacterIndex("Captured governor");
	govidx = GetTownGovernorIndex(town);
	if (govidx >= 0) {
		gov = GetCharacter(govidx);
		if (gov.location != "none") governor_exists = true;
	}
	if (governor_exists) locidx = FindLocation(gov.location);
	if (locidx < 0) governor_exists = false;

	if(!governor_exists)
	{
		fcidx = GetTownFortCommanderIndex(town, 0);
		if (fcidx >= 0) {
			gov = GetCharacter(fcidx);
			if (gov.location != "none") fortcommandant_exists = true;
		}
	}

	DeleteAttribute(captured_governor, "");

	captured_governor.id = "Captured governor";
	captured_governor.index = captured_governor_idx;
	captured_governor.model = "";
	captured_governor.model.entity = "NPCharacter";
	captured_governor.model.animation = "";
	captured_governor.headModel = "";
	captured_governor.dialog.filename = "Captured governor_dialog.c";
	captured_governor.Dialog.CurrentNode = "First time";
	captured_governor.Dialog.TempNode = captured_governor.Dialog.CurrentNode;
	captured_governor.quest.meeting = "0";
	captured_governor.quest = "True";

	iNation = GetTownNation(town);
	if (governor_exists) {
		captured_governor.model = gov.model;
		captured_governor.model.animation = gov.model.animation;
		captured_governor.headModel = gov.headModel;
		captured_governor.name = gov.name;
		if (CheckAttribute(gov, "middlename")) captured_governor.middlename = gov.middlename;
		captured_governor.lastname = gov.lastname;
		captured_governor.sex = gov.sex;
		captured_governor.nation = iNation;
		captured_governor.location = gov.location;
		captured_governor.location.group = gov.location.group;
		captured_governor.location.locator = gov.location.locator;
		if (CheckAttribute(gov, "Dialog.Filename") && CheckAttribute(gov, "Dialog.BoardingNode")) {
			captured_governor.Dialog.Filename = gov.Dialog.Filename;
			captured_governor.Dialog.CurrentNode = gov.Dialog.BoardingNode;
		}
		captured_governor.rank = gov.rank;
		captured_governor.reputation = gov.reputation;
		captured_governor.experience = gov.experience;
		for (i = 0; i < 10; i++) {
			skillname = GetSkillName(i);
			captured_governor.skill.(skillname) = GetCharacterSkill(gov, skillname);
		}
		captured_governor.money = GetCharacterMoney(gov);

		SetModelFromID(captured_governor, gov.model);
	} else {
		captured_governor.sex = "man";
		captured_governor.nation = iNation;
		i = 1;
		while (CheckAttribute(Towns[GetTownIndex(town)], "boarding.l" + i)) i++;
		sdistrict = "l" + (i - 1);
		captured_governor.location = Towns[GetTownIndex(town)].boarding.(sdistrict);
		Locations[FindLocation("BOARDING_Residence")].image = Locations[FindLocation(captured_governor.location)].image;
		captured_governor.location = "BOARDING_Residence";
		captured_governor.location.group = "rld";
		captured_governor.location.locator = "aloc0";
		if(fortcommandant_exists)
		{
			if (CheckAttribute(gov, "Dialog.Filename") && CheckAttribute(gov, "Dialog.BoardingNode")) {
				captured_governor.Dialog.Filename = gov.Dialog.Filename;
				captured_governor.Dialog.CurrentNode = gov.Dialog.BoardingNode;
			}
		}
		captured_governor.rank = boarding_enemy.rank;
		captured_governor.reputation = boarding_enemy.reputation;
		captured_governor.experience = boarding_enemy.experience;
		for (i = 0; i < 10; i++) {
			skillname = GetSkillName(i);
			captured_governor.skill.(skillname) = rand(9) + 1;
		}
		captured_governor.money = 10;

		SetModelFromID(captured_governor, SelectSoldierModelByNation(iNation, "officer"));
		SetRandomNameToCharacter(captured_governor);
	}

	captured_governor.skill.freeskill = 0;
	captured_governor.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
	if (captured_governor.location.group != "sit")
		LAi_SetStayType(captured_governor);
	else
		LAi_SetSitType(captured_governor);
	LAi_SetLoginTime(captured_governor, 0.0, 24.0);
	LAi_group_MoveCharacter(captured_governor, LAI_GROUP_PLAYER);
	if (captured_governor.sex == "woman") captured_governor.greeting = "Gr_Rachel Blacque";		// "Gr_Angelique Moulin" ("Bonjour, monsieur. At your service."), "Gr_Arabella Silehard" ("I'm not so much a governor as I am an agent of the monarchy"), "Gr_Rachel Blacque" ("Oui, monsieur? You wish to speak with me?") 
	else captured_governor.greeting = "Gr_Clauss";							// "Parlez, captain?" Was "Gr_Dark Teacher" which is identical
	captured_governor.town = town;

	boarding_enemy = captured_governor;
}

void ReloadToResidence(ref gov)
{
	int i, locidx, boarding_residence_idx;
	bool governor_exists;
	string town, sdistrict;
	ref boarding_residence, rloc;
	ref mchr = GetMainCharacter();
	aref reloadref;
	locidx = FindLocation(gov.location);
	if (locidx < 0) return;
	town = gov.town;
	governor_exists = GetTownGovernorIndex(town) >= 0;
	i = 1;
	if (!governor_exists) {
		while (CheckAttribute(Towns[GetTownIndex(town)], "boarding.l" + i)) i++;
		sdistrict = "l" + (i - 1);
		locidx = FindLocation(Towns[GetTownIndex(town)].boarding.(sdistrict));
		if (locidx < 0) return;
	}
	boarding_residence_idx = FindLocation("BOARDING_Residence");
	if (boarding_residence_idx < 0) return;

	ReloadProgressStart();

	makeref(boarding_residence, Locations[boarding_residence_idx]);
	makeref(rloc, Locations[locidx]);
	DeleteAttribute(boarding_residence, "");
	CopyAttributes(&boarding_residence, &rloc);

	boarding_residence.id = "BOARDING_Residence";
	//boarding_residence.id.label = "Boarding town";
	boarding_residence.index = boarding_residence_idx;
	boarding_residence.index_org = locidx;
	boarding_residence.vcskip = true;
	LAi_LocationFightDisable(boarding_residence, true);

	mchr.location = "BOARDING_Residence";
	if (governor_exists) {
		mchr.location.group = "reload";
		makearef(reloadref, Locations[boarding_residence_idx].reload);
		int num = GetAttributesNum(reloadref);
		string attrname = "l1";
		if (num > 0) attrname = GetAttributeName(GetAttributeN(reloadref, 0));
		mchr.location.locator = reloadref.(attrname).name;
	} else {
		i = 0;
		while (i < CHARACTERS_QUANTITY) {
			if (!CheckAttribute(characters[i], "location")) continue;
			if (FindLocation(characters[i].location) == locidx) {
				mchr.location.group = characters[i].location.group;
				mchr.location.locator = characters[i].location.locator;
				i++;
				break;
			}
			i++;
		}
		while (i < CHARACTERS_QUANTITY) {
			if (!CheckAttribute(characters[i], "location")) continue;
			if (FindLocation(characters[i].location) == locidx) {
				ChangeCharacterAddressGroup(boarding_enemy, "BOARDING_Residence", characters[i].location.group, characters[i].location.locator);
				break;
			}
			i++;
		}
	}
	boarding_enemy.location = "BOARDING_Residence";

	if (ACTOR_WHEN_BOARDING == 1 && boarding_residence.filespath.models != "locations\inside\Residence5") {
		// Make character run to enemy captain, walk when he gets close
		/*mchr.SavedAlwaysRunToggle = AlwaysRunToggle;
		if (AlwaysRunToggle) {
			AlwaysRunToggle = false;
			BeginChangeCharacterActions(mchr);
			SetDefaultNormWalk(mchr);
			SetDefaultFight(mchr);
			EndChangeCharacterActions(mchr);
		}*/

		LAi_SetActorType(mchr);
		LAi_ActorDialog(mchr, boarding_enemy, "Surrendered_Captain_Dialog", 60.0, 0);	// surrender dialog
	}
	dialogDisable = false;

	if (!LoadLocation(boarding_residence)) trace("Residence not loaded!");

	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);

	StartQuestMovie(true, true, false);
}

void MusketVolley(ref mchr, ref echr)
{
	// This only happens for ships, not forts, and is already tested in AIAbordage.c
	bool PlayerVolley = CheckAttribute(mchr, "musket") && !CheckAttribute(echr, "surrendered");
	bool EnemyVolley  = CheckAttribute(echr, "musket") && !CheckAttribute(echr, "surrendered");
	DeleteAttribute(mchr, "musket");
	DeleteAttribute(echr, "musket");

	// delta determines who fires first and affects the final casualty total
	int leadership0 = GetShipSkill(mchr, SKILL_LEADERSHIP);
	int leadership1 = GetShipSkill(echr, SKILL_LEADERSHIP);
	int accuracy0 = GetShipSkill(mchr, SKILL_ACCURACY);
	int accuracy1 = GetShipSkill(echr, SKILL_ACCURACY);
	float delta = makefloat((leadership0 - leadership1) + (accuracy0 - accuracy1)) / (4.0 * MAX_CHARACTER_SKILL);
//	float delta = 0.0;
	float killratio1 = 0.0;
	float killratio2 = 0.0;
	bool  bEnemyShotFirst = false;

	int numVolleys = PlayerVolley + EnemyVolley;
	ref chr1 = mchr;
	ref chr2 = echr;
	if (numVolleys == 1 && EnemyVolley)
	{
		chr1 = echr;
		chr2 = mchr;
	}

	if (numVolleys == 2)
	{
		if (delta > 0.0) {
			chr1 = mchr;
			chr2 = echr;
		} else {
			chr1 = echr;
			chr2 = mchr;
			bEnemyShotFirst = true;
		}
	}

	int eclass = GetCharacterShipClass(chr2);
	float fProtected = 0.0;		// Fraction of enemy crew protected from musket fire due to being below decks
	if(eclass < 7) fProtected = 0.1;	// Tier 5 and 6 have a few gunners below deck
	if(eclass < 5) fProtected = 0.2;	// Tier 3 and 4 frigates have a full gun deck under cover
	if(eclass < 3) fProtected = 0.3;	// Tier 1 and 2 ships of the line have two or more gun decks under cover

	int nShooter = 1;
	while (numVolleys > 0)
	{
		// musket fire effects have been moved from AIAbordage.c to here
		int mcrew = GetCrewQuantity(chr1);
		int ecrew = GetCrewQuantity(chr2);
		float fGrap = 0.5 * GetShipSkill(chr1, SKILL_GRAPPLING) / MAX_CHARACTER_SKILL;           //TY subbing in grapplng for luck, influence of better managing the boarding and ship position to ensure maximum effect musket volley, after all bosun is in charge of this perk
		float fShipDefense = 0.0;
		//Levis: Damage Control only works on hull damage
		/*if (GetOfficersPerkUsing(chr2, "BasicDamageControl"))        fShipDefense = 0.15;
		if (GetOfficersPerkUsing(chr2, "AdvancedDamageControl"))     fShipDefense = 0.25;
		if (GetOfficersPerkUsing(chr2, "ProfessionalDamageControl")) fShipDefense = 0.40;*/
		if (GetOfficersPerkUsing(chr2, "BasicFirstAid"))        fShipDefense = 0.15;
		if (GetOfficersPerkUsing(chr2, "AdvancedFirstAid"))     fShipDefense = 0.30;
		float fCharDefence = makefloat(GetShipSkill(chr2, SKILL_DEFENCE)) / MAX_CHARACTER_SKILL;

		int musketkills = makeint((0.1*mcrew * (1.0+delta+fGrap-fShipDefense-fCharDefence) + 0.5) * (FRAND(0.25)+FRAND(0.25)+0.75));	// GR: random element added, muskets weren't accurate. Base multiplier 0.25 reduced because there weren't enough musketeers to do that much damage
//		int musketkills = makeint(0.25*ecrew * (1.0+delta+fGrap-fShipDefense-fCharDefence)+0.5);	// Original version used 'ecrew' and no randomisation, so a small ship attacking a big ship would cause more casualties than vice versa
		if (musketkills < 0) musketkills = 0;	// just in case
		if (musketkills > ecrew * 0.75 * (1.0-fProtected)) musketkills = ecrew * 0.75 * (1.0-fProtected);		// Muskets can't kill crew who are below deck

		// SDLogIt("Musket Fire - delta=" + f2s2(delta) + " grappling=" + fGrap + " ShipDef=" + fShipDefense + " CharDef= " + fCharDefence);

		string whose_fire = "Your";
		string which_target = "Enemy";
		if (sti(chr1.index) == sti(echr.index))
		{
			whose_fire = "Enemy";
			which_target = "Your";
		}
		LogIt(TranslateString("", whose_fire + " musket fire kills") + " " + musketkills + " " + TranslateString("", which_target + " crewmen") + ".");
		SDLogIt("Musket fire kills " + musketkills + " enemy crewmen, (" + musketkills + "/" + ecrew + " = " + makeint(100.0*musketkills/ecrew+0.5) + " percent.)");

/*
		// Old logic, left here for documentation
		// LDH - Morale is set as follows:
		//  It's assumed that a musket volley kills 25% of the crew.
		//  If it kills less than this, enemy morale goes up, our morale goes down.
		//  If it kills more, enemy morale goes down, our morale goes up.
		int iMoraleChange = makeint(100.0 * musketkills / ecrew + 0.5) - 25;
*/

		// Note that a killratio of zero is valid
		if (nShooter == 1)
			killratio1 = Clampf(makefloat(musketkills) / makefloat(ecrew));		// first shooter
		else
			killratio2 = Clampf(makefloat(musketkills) / makefloat(ecrew));		// second shooter
		nShooter++;

		ecrew -= musketkills;
		if (ecrew < 1) ecrew = 1;
		SetCrewQuantity(chr2, ecrew);

		// swap shooter and target
		numVolleys -= 1;
		if (numVolleys > 0)
		{
			ref tmpchr = chr1;
			chr1 = chr2;
			chr2 = tmpchr;
			delta = -delta;
		}
	}

	// we shot and we won          (hi-0)  = hi
	// we shot and we lost         (lo-0)  = lo
	// they shot and we won        (lo-0)  = negative lo
	// they shot and we lost       (hi-0)  = negative hi
	// we shot first and we won    (hi-lo) = positive
	// we shot first and we lost   (lo-hi) = negative
	// they shot first and we won  (lo-hi) = positive
	// they shot first and we lost (hi-lo) = negative

	// killratio is a float in the range of about 0.0 to 0.25
	int iMoraleChange = makeint(40.0*(killratio1 - killratio2)+0.5);	// positive number is in our favor
	SDLogIt("Initial morale change = " + iMoraleChange);
	iMoraleChange = iClamp(-10, 10, iMoraleChange);
	if (EnemyVolley)
	{
		if (PlayerVolley)
		{
			if (bEnemyShotFirst)
			{
				iMoraleChange = -iMoraleChange;
			}
		}
		else
		{
			iMoraleChange = -iMoraleChange;
		}
	}

	SDLogIt("Morale before " + iMoraleChange + " Enemy= " + echr.ship.crew.morale + " Friendly=" + mchr.ship.crew.morale);

	mchr.ship.crew.morale = iclamp(1, 99, sti(mchr.ship.crew.morale) + iMoraleChange);
	echr.ship.crew.morale = iclamp(1, 99, sti(echr.ship.crew.morale) - iMoraleChange);

	SDLogIt("Morale after  " + iMoraleChange + " Enemy= " + echr.ship.crew.morale + " Friendly=" + mchr.ship.crew.morale);
}

//---------- number of locations in each boarding area ---------
int GetBoardingLimit(int locIndex)
{
	int limit = 6;	// default, just in case

	switch (Locations[locIndex].filespath.models)
	{
		case "locations\decks\udeck":         // 2 ships side by side, main character starts on "corvette-like" and boards "warship-like" deck
			limit = 12;
		break;

		case "locations\decks\udeck1":        // Narrow single ship
			limit = 20;
		break;

		case "locations\decks\udeck2":        // Wide single ship
			limit = 20;
		break;

// KK -->
		case "locations\decks\Qdeck":         // "corvette-like" deck
			limit = 10;
		break;

		case "locations\decks\deck1":         // Larger cannons deck
			limit = 14;
		break;

		case "locations\decks\deck2":         // Smaller cannons deck
			limit = 14;
		break;

		case "locations\decks\hold":          // Cargo hold
			limit = 10;
		break;
// <-- KK
	}

	switch(Locations[locIndex].id)
	{
		case "Boarding_Cabin_small":          // Tiny cabin
			limit = 4;
		break;

		case "Boarding_Cabin_medium":         // Cabin with 3 rooms, food table and officer's head
			limit = 6;
		break;

		case "Boarding_Cabin1":               // Tutorial cabin
			limit = 8;
		break;

		case "Boarding_Cabin2":               // Has balcony outside rear window
			limit = 10;
		break;

		case "Boarding_Cabin3":               // Has wrap-around gallery across back of cabin
			limit = 10;
		break;

		case "Boarding_Cabin4":			      // Black Pearl
			limit = 10;
		break;

		case "Boarding_Cabin5":			      // Crimson Blood
			limit = 2;
		break;
// KK -->
		case "BOARDING_ShipDeck4":            // Small deck with two little doors on both sides of stairs up on stern
			limit = 10;
		break;

		case "BOARDING_ShipDeck5":            // Medium sized deck with high borts to which lead ladders
			limit = 14;
		break;

		case "BOARDING_ShipDeck6":            // Large deck with exit onto galley and "half-round" stairs to upper deck at stern
			limit = 14;
		break;

		case "BOARDING_ShipDeck7":            // Black Pearl
			limit = 14;
		break;

		case "BOARDING_ShipDeck4vs5":         // Combination of BOARDING_ShipDeck4 and BOARDING_ShipDeck5
			limit = 11;
		break;

		case "BOARDING_ShipDeck4vs6":         // Combination of BOARDING_ShipDeck4 and BOARDING_ShipDeck6
			limit = 11;
		break;

		case "BOARDING_ShipDeck5vs6":         // Combination of BOARDING_ShipDeck5 and BOARDING_ShipDeck6
			limit = 14;
		break;
// <-- KK
	}

	if (IsFort) limit = 8;
	if (IsTown) limit = 8;

	if (limit > 20) limit = 20;		// LDH restored 31Jan09 - 30 is too many in one location, it causes terrible lag
	return limit;
}

// LDH - Special versions of GetCrew and SetCrew for boarding.  Includes fort crews and squadron crews if boarding a fort.
int GetCrewBoarding(ref chr)
{
	if (IsFort || IsTown) // KK
	{
		if (!CheckAttribute(chr, "boardingcrew")) return 0;
		return sti(chr.boardingcrew);
	}
	return GetCrewQuantity(chr);
}

void SetCrewBoarding(ref chr, int crew)
{
	if (IsFort || IsTown) // KK
	{
		chr.boardingcrew = crew;
	}
	else
	{
		SetCrewQuantity(chr, crew);
	}
}

void DeleteCrewBoarding(ref chr)
{
	DeleteAttribute(chr, "boardingcrew");
}

void InitBoardingVariables()
{
	IsFort = false; // NK
	IsTown = false; // KK
	boarding_location = -1;
	boarding_location_type = -1;
	boarding_enemy_crew = 0;
	boarding_player_crew = 0;
	boarding_enemy_base_crew = 0;
//	boarding_officers = 0;
	boarding_player_crew_per_chr = 1.0;
	realCrew = GetCrewQuantity(GetMainCharacter());
	EndingStatsDone = false;	// LDH - flag to prevent reload event handler from running after done.
	noOfficers = false;
	bCrewCaptured = false;		// TIH reset to false so it does not carry into other dialogs
	endStat = true;
	bCaptureShip = false;
	boarding_exp = 0.0;
	boarding_player_hp = 40.0;
	boarding_enemy_hp = 40.0;
	boarding_echr_index = -1;
	LAi_boarding_process = false;
	Surrendered = false;					// LDH - this was not being initialized, caused problems
	boarding_enemy_original_morale = 0.0;
	boarding_enemy_crew_per_chr = 1.0;
	SurrenderModifier = 0;
	defeat = 0;
	boarding_enemy_crew_start = 0;
	boarding_player_crew_start = 0;
	mmorale = 0.5;
	emorale = 0.5;
	ncannonsdeck = 0; // KK
	ncargohold = 0; // KK
	nfort = 0; // KK
	cdistrict = 0; // KK
	next_boarding_location = -1; // KK
}

void SDLogIt(string logtext)
{
// LDH added trace
	if (DEBUGINFO)
	{
//		LogIt(logtext);		// uncomment this line for full boarding debug info on screen
		Trace("BD: " + logtext);
	}
	return;
}
