// items group id
#define OBJECT_ITEM_TYPE		"items"
#define GUN_ITEM_TYPE			"gun"
#define BLADE_ITEM_TYPE			"blade"
#define SPYGLASS_ITEM_TYPE		"spyglass"
#define ARMOR_ITEM_TYPE			"armor"			// GreatZen
#define FLASK_ITEM_TYPE			"powderflask"	//JRH or "powderbarrel"	
#define POUCH_ITEM_TYPE			"ammopouch"		//JRH or "ammobag"
#define BELT_ITEM_TYPE			"pistolbelt"	//JRH
#define LOCKPICK_ITEM_TYPE		"lockpick"		// PB
#define CLOCK_ITEM_TYPE			"clock"			// PB
#define COMPASS_ITEM_TYPE		"compass"		// PB
#define POTION_ITEM_TYPE		"potion"		//MAXIMUS
#define QUEST_ITEM_TYPE			"quest_item"	//MAXIMUS
#define AMMUNITION_ITEM_TYPE	"ammunition"	// KK
#define MAP_ITEM_TYPE			"map"			// KK
#define OUTFIT_ITEM_TYPE		"outfit"		//JRH
#define DOCUMENT_ITEM_TYPE		"document"		//JRH
#define BOOK_ITEM_TYPE			"book"			//Levis
#define EQUIP_ITEM_TYPE			"equip"			//JRH questitem with equip button
#define EQUIP2_ITEM_TYPE		"equip2"		//JRH questitem with equip button
#define EQUIP3_ITEM_TYPE		"equip3"		//JRH questitem with equip button
#define EXAMINE_ITEM_TYPE		"examine"		//JRH questitem with examine button
#define OPEN_ITEM_TYPE			"open"		    	//JRH ammo item with examine button
#define FLIP_ITEM_TYPE			"flip"			//JRH questitem with flip button

// indexes for items` array
// NK -->
#define MAX_ITEMS					2300		//JRH was 1700
int ITEMS_QUANTITY = 0;
#define MAX_RANDITEMS				2300 // MUST BE CAREFUL, JRH was 1700
// should be near items; some items are not for rand pickup, but some are added more than once
// (for probability). Setting this = max_items should be fine.
// note that this is academic as only ~200 something items are used now anyway.
int RANDITEMS_QUANTITY = 0;
#define MAX_SKILLITEMS				1000 // must be >= num skill-changing items; best to leave this = max_items
int SKILLITEMS_QUANTITY = 0;
int TRADEITEMS_QUANTITY = 0; // 05-04-01 NK itemtrade
int FIRST_TRADE_ITEM = 0;	// 05-04-07 so we skip quest/notrade items.
int QUESTITEMS_QUANTITY = 0; // KK
#define MAX_GUNPOWDER 6     //  Sulan: Maximum units of gunpowder for character pistol/musket
#define MAX_SHOTS 6         //  Sulan: Maximum bullets/grapes for character pistol

// NK <--
#define MAX_BUTTONS				  128
#define BUTTON_ACTIVATION_TIME	  1000
#define ITEMS_LAYER				  50
#define MAX_LOADED_RANDITEMS	  140		//JRH: was 130
#define MAX_HANDLED_BOXES 		  100		//JRH: was 25


object Items[MAX_ITEMS];
object RandItems[MAX_RANDITEMS]; // NK
object SkillItems[MAX_SKILLITEMS]; // NK

// NK new style randitems:
#define RANDITEMS_MAXCHANCE	10
#define RANDITEMS_MAX			8192 // hope that's enough. At max we'd need MAX_ITEMS * RANDITEMS_MAXCHANCE or so, but most items have smaller itm.rare
#define RANDITEMS_MAXLEVELS	128

int RandItemsIdx[RANDITEMS_MAX];
int RandItemsIdx_Quantity = 0;
int RandItemsLevels[RANDITEMS_MAXLEVELS];		// stores last-randitemidx-for-level
int RandItemsLevels_Quantity = 0;

int RandItemsIdx_BLADE[RANDITEMS_MAX];
int RandItemsIdx_BLADE_Quantity = 0;
int RandItemsLevels_BLADE[RANDITEMS_MAXLEVELS];		// stores last-randitemidx-for-level
int RandItemsLevels_BLADE_Quantity = 0;

int RandItemsIdx_GUN[RANDITEMS_MAX];
int RandItemsIdx_GUN_Quantity = 0;
int RandItemsLevels_GUN[RANDITEMS_MAXLEVELS];		// stores last-randitemidx-for-level
int RandItemsLevels_GUN_Quantity = 0;
// NK <--

// scheffnow - weaponsmod -->
#define MAX_BLADES          500
#define MAX_GUNS            150
#define MAX_QUALITY         6
#define QUALITY_BADLYWORN   0
#define QUALITY_WORN        1
#define QUALITY_AVERAGE     2
#define QUALITY_GOOD        3
#define QUALITY_FINE        4
#define QUALITY_EXELLENT    5
int BLADE_HIGH = -1;
int GUN_HIGH   = -1;
object  BladeItems[MAX_BLADES];
object  GunItems[MAX_GUNS];
object  SortItems[1]; // NEVER USED 05-07-22
// scheffnow - weaponsmod <--

