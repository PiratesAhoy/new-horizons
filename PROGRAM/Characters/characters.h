#define CHARACTER_NOTUSED_NAME	"Noname"
#define BASE_CHARACTER_ONE 0
#define BASE_CHARACTER_TWO 1

#define MORALE_MAX		99
#define MORALE_NORMAL   45
#define MORALE_MIN		0
#define MORALE_TABLE_SIZE	10
#define MORALET_TREACHEROUS	0	//Ужасная
#define MORALET_AWFUL		1	//Отвратительная
#define MORALET_LOW			2	//Плохая
#define MORALET_POOR		3	//Низкая
#define MORALET_NORMAL		4	//Средняя
#define MORALET_ELATED		5	//Приподнятая
#define MORALET_GOOD		6	//Хорошая
#define MORALET_HIGH		7	//Высокая
#define MORALET_EXCELLENT	8	//Отличная
#define MORALET_HEROIC		9	//Героическая
string  MoraleTable[MORALE_TABLE_SIZE];

#define REPUTATION_MIN          1
#define REPUTATION_MAX          89
#define REPUTATION_TABLE_SIZE   9
// KK -->
#define REPUTATION_HORROR       5
#define REPUTATION_BASTARD     15
#define REPUTATION_SWINDLER    25
#define REPUTATION_RASCAL      35
#define REPUTATION_NEUTRAL     45
#define REPUTATION_PLAIN       55
#define REPUTATION_GOOD        65
#define REPUTATION_VERYGOOD    75
#define REPUTATION_HERO        85
// <-- KK
#define REPUTATIONT_HORROR      0
#define REPUTATIONT_BASTARD     1
#define REPUTATIONT_SWINDLER    2
#define REPUTATIONT_RASCAL      3
#define REPUTATIONT_NEUTRAL     4
#define REPUTATIONT_PLAIN       5
#define REPUTATIONT_GOOD        6
#define REPUTATIONT_VERYGOOD    7
#define REPUTATIONT_HERO        8
string  ReputationTable[REPUTATION_TABLE_SIZE];

//#define PASSENGERS_MAX	32
//#define COMPANION_MAX	4
// maximum number of cabin captains allowed to be alive at once:
// (captured captains are alive until hired or released)
#define CABINCAPTAINS_MAX 35
int Enc_Capt[CABINCAPTAINS_MAX]; // TIH put back as this is needed as "id" changes on these slots Nov5'06
int Last_Capt = 0;

#define SKILL_LEADERSHIP	"Leadership"
#define SKILL_FENCING		"Fencing"
#define SKILL_SAILING		"Sailing"
#define SKILL_ACCURACY		"Accuracy"
#define SKILL_CANNONS		"Cannons"
#define SKILL_GRAPPLING		"Grappling"
#define SKILL_REPAIR		"Repair"
#define SKILL_DEFENCE		"Defence"
#define SKILL_COMMERCE		"Commerce"
#define SKILL_SNEAK			"Sneak"

#define KILL_BY_BALL		1
#define KILL_BY_ABORDAGE	2
#define KILL_BY_SPY			3
#define KILL_BY_ISLAND		4
#define KILL_BY_TOUCH		5
#define KILL_BY_OWNER		6 // KK

// KK -->
#define PLAYERTYPE_ADVENTURER     "Adventurer"
#define PLAYERTYPE_AGENT          "Agent"
#define PLAYERTYPE_MILITARY       "Army Veteran"
#define PLAYERTYPE_CORSAIR        "Corsair"
#define PLAYERTYPE_ENGINEER       "Engineer"
#define PLAYERTYPE_EXPLORER       "Explorer"
#define PLAYERTYPE_GAMBLER        "Gambler"
#define PLAYERTYPE_GUNNER         "Gunner"
#define PLAYERTYPE_MARINE         "Marine"
#define PLAYERTYPE_MERCHANT       "Merchant"
#define PLAYERTYPE_NAVALOFFICER   "Naval Officer"
#define PLAYERTYPE_PHYSICIAN      "Physician"
#define PLAYERTYPE_QUARTERMASTER  "Quartermaster"
#define PLAYERTYPE_REBEL          "Rebel"
#define PLAYERTYPE_ROGUE          "Rogue"
#define PLAYERTYPE_SAILOR         "Sailor"
#define PLAYERTYPE_SHIPWRIGHT     "Shipwright"
#define PLAYERTYPE_SMUGGLER       "Smuggler"
#define PLAYERTYPE_SOCIALCLIMBER  "Social Climber"
#define PLAYERTYPE_SWORDMASTER    "Sword Master"
#define PLAYERTYPE_CURSED	      "Cursed"
#define PLAYERTYPE_CASTAWAY	      "Castaway"
#define PLAYERTYPE_CUSTOM         "Custom"
#define PLAYERTYPE_LAND_OWNER     "Land Owner"
// <-- KK

// NK -->
// please do CHARACTERS_QUANTITY++; after finding a new slot with this function!
int FindBlankCharSlot()
{
	ref ch;
	for(int i=CHARACTERS_QUANTITY; i<MAX_CHARACTERS; i++)
	{
		makeref(ch,Characters[i]);
		if(ch.id=="0") return i;
		CHARACTERS_QUANTITY++;
		// NK 05-04-05 use CHARACTERS_QUANTITY, and update it if we find nonblank slots after.
		// NOTE!!!! We do NOT update CHARACTERS_QUANTITY based on the slot we are returning, because we may not be _really_ using FindBlankCharSlot()
	}   // to make a new character. So when you use this to make a new char, please also update CHARACTERS_QUANTITY.
		// however, I'm also adding a straight call to this to the bottom of reinit(), to make sure CHARACTERS_QUANTITY is OK.
	trace("::No more place for new characters - FindBlankCharSlot() returns -1 (CHARACTERS_QUANTITY = "+CHARACTERS_QUANTITY+")::");
	return -1;
}
// NK <--
