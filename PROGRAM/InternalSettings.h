/*
++++++++++++++ TWEAKS AND SWITCHES FOR MODS ++++++++++++++
In this list you can customize the keyfeatures of the game to your liking.
Or disable certain mods completely.

NOTE! All actual int and float values are overridden in function InitOpenSeaMod() in PROGRAM\NK.c

!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!
This is a program file. Changes to the format of the code will mess up the game.
Please follow these rules when editing settings:
- Change ONLY the values after the CAPITAL_SETTING names.
- Use ONLY the values from the explanation below the setting.
- DO NOT replace numbers with "letters", or integer numbers (1) with decimal values (0.75)
- NEVER remove a line starting with "#define".
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


// ======================================
// REALISM OPTIONS:
// ======================================
// Included in Realistic Game Mode:
#define REALISTIC_SHIP_INERTIA			0		// BOOL - 1=ON - Ships require counter-rudder and don't sail as if on rails
#define SHORE_DANGER_ALARM			0		// BOOL - 1=ON - Red flashing icon and danger music do not start until enemies draw their blade
#define DISCOVER_SAIL_TO			1		// BOOL - 0=OFF - Shores and ports must be discovered by sailing there manually or having the island's map before you can use Sail To
#define DISCOVER_FAST_TRAVEL			1		// BOOL - 0=OFF - Town locations must be discovered by finding them manually or asking for directions before you can use Fast Travel
#define NAVIGATION_EQUIPMENT			0		// BOOL - 1=ON - Items required for certain navigational information to become available
#define ENABLE_LIMITED_SHIPCLASS		0		// BOOL - 1=ON - When player takes command of ship of too high tier, Leadership and Sailing skills drops
#define CANNOT_RELOAD_WHILE_FIGHTING		1		// INT - 1=DEFAULT: Controlled by Realism Mode - 0 or 2 override the Realism Mode setting
#define SAIL_OPERATE_DELAY			3		// INT - sailors will operate sails this amount of seconds after receiving command (set to 0 to restore stock PotC)
// Included in Iron Man Mode:
#define OPEN_SEA_MOD				0		// BOOL - 1=ON - Worldmap enlarged for realistic DirectSail
#define WORLDMAP_DISABLED			0		// BOOL - 1=ON - DirectSail enforced
#define SAILTO_DISABLED				0		// BOOL - 1=ON - Cannot Sail-To any ships at sea
#define ONSEA_DATA_DISABLED			0		// BOOL - 1=ON - Spyglass and compass additional information disabled, cannot move camera to non-player ships
#define REALISTIC_ABILITIES			0		// INT  - 1=DEFAULT: Controlled by Realism Mode - 0 or 2 override the Realism Mode setting
#define ITEM_REALISM				1		// BOOL - 1=ON - Items like rubies, diamonds and inca statuettes give no skill bonuses (books and items like compass etc. still do)
#define CLINT_SHOTGUN				1		// BOOL - 0=OFF - Clint Eastwood carries brace of four horse pistols in Arcade Mode; 1=ON - Clint Eastwood carries shotgun in Arcade Mode.  In any other mode he always has brace of four horse pistols.
#define CURSES_DISABLED				2		// INT - 0=default: Cursed items can be dumped or given away. 1 = cursed coins, 2 = cursed albatross, 0 = neither, 3 = both


// ======================================
// STARTING OPTIONS:
// ======================================

#define STORMY_START_CHOICES	20				// Set to 19 to disable Cozumel stormy start, set to 17 to also disable Barbados stormy start

// Character Selection Options
#define NEW_MODEL_1				"Blaze"			// Nathaniel Hawk
#define NEW_MODEL_2				"Jack"			// Captain Jack Sparrow
#define NEW_MODEL_3				"will"			// Will Turner
#define NEW_MODEL_4				"cnorrington"	// James Norrington
#define NEW_MODEL_5				"Devlin"		// Blaze Devlin (AoP)
#define NEW_MODEL_6				"Aubrey"		// "Lucky" Jack Aubrey
#define NEW_MODEL_7				"capnhook"		// Captain Hook
#define NEW_MODEL_8				"33_TG5D"		// Towngirl 5
#define NEW_MODEL_9				"9CATa"			// Catalina the Pirate
#define NEW_MODEL_10			"9Ta"			//
#define NEW_MODEL_11			"50_Becka"		// Becka
#define NEW_MODEL_12			"Beatrice"		// Beatrice Devlin (AoP)

// Ship Selection Options
#define NEW_SHIP_1				"Lugger1"		//
#define NEW_SHIP_2				"Sloop1"		//
#define NEW_SHIP_3				"Barque1"		//
#define NEW_SHIP_4				"Yacht1"		//
#define NEW_SHIP_5				"Gunboat"		// Fred Bobs teeny gunboat
#define NEW_SHIP_6				"SloopBermuda"	// Captain Augast
#define NEW_SHIP_7				"LuggerVML" 	// KK
#define NEW_SHIP_8				"Ketch" 		// Petros

// ======================================
// GENERAL SETTINGS:
// ======================================

#define AUTOHIRECREW_ONCHANGESHIP		0		// BOOL - Automatically hire extra crew when repairing your ship or buying a new one at shipyard
#define ENABLE_SKILLUP_IFZERO			0 		// BOOL - If a character has 0 for a skill, you can increase it anyway, 1=allow, 0=not
#define CHAR_HITPOINTS_PER_LEVEL		10		// INT - The amount of hitpoints which is added to a character's maximum hitpoints on each level up
#define CHAR_START_HITPOINTS			40		// INT - The amount of hitpoints any character starts with at level 1
#define OPRICE_LEVEL_MULT				0.5		// FLOAT - What % of full price-per-rank increase an officer gets on leveling up. I.e. when this is 0.5, price goes up by 100 per rank

#define NUM_RANDOM_OFFICERS				50		// INT - number of encounter (tavern) officers.
#define FEMALE_OFFICER_PERCENTAGE		40		// INT = Percentage of female officers encountered

// Difficulty
#define ENEMYLEVEL_MULT_BASE			0.66	// FLOAT - The base multiplier to level for enemies.
#define ENEMYLEVEL_DIFF_INFL			0.2		// FLOAT - The influence of difficulty on enemy levels.
#define ENEMYLEVEL_RAND_INFL			0.33	// FLOAT - The influence of a random function on enemy levels--will be x(1.0 +/- rand(this))
#define ENEMYLEVEL_LUCK_INFL			0.01	// FLOAT - The influence of your luck on enemy levels. The influence will be _up to_ this x luck.

#define FRIENDLEVEL_MULT_BASE			0.66	// FLOAT - (no description)
#define FRIENDLEVEL_DIFF_INFL			0.2		// FLOAT - (no description)
#define FRIENDLEVEL_RAND_INFL			0.33	// FLOAT - (no description)
#define FRIENDLEVEL_LUCK_INFL			0.01	// FLOAT - (no description)
#define FRIENDLEVEL_LEAD_INFL			0.01	// FLOAT - (no description)

#define PERK_MULTIPLIER					1		// FLOAT - Default = 1, Perks are set to cost base value*multiplier. Set to 0 to have everything be cost 1
#define	ALLOW_LOCKED_PERKS				1		// BOOL	 - Default = 1, If 1 perks can be locked. If 0 no perks can be locked.

// Motion control
#define SIDESTEP_DIST_LEFT				0.05	// FLOAT - Default=0.05, distance traveled per step when sidestepping to the LEFT
#define SIDESTEP_DIST_RIGHT				0.05	// FLOAT - Default=0.05, distance traveled per step when sidestepping to the RIGHT
#define SIDESTEP_DELAY					10		// INT - Default=100, time delay in milliseconds between sidesteps. 1000 / this * dist = rate per second
#define SIDESTEP_CHECK					0		// BOOL - Off=0, Default=1, Prevent player from teleporting out of location via sidestep. DOESN'T WORK!


// ======================================
// TIME SCALARS
// ======================================

int		TIMESCALAR_SEA =			5;			// INT - how many seconds of gametime one second of realtime is at sea
#define TIMESCALAR_LAND				10			// INT - same but for land
#define TIMEUPDATE_BLOCK_LAND		1			// BOOL - whether time updates per minute or on location change (i.e. in blocks)
#define TIMESCALAR_SAILTO_SHIP		2			// INT - timescalar to sail to ship
#define TIMESCALAR_SAILTO_LOC		1			// INT - timescalar to sail to locator
#define TIMESCALAR_SAILTO_THRU		4			// INT - timescalar to sail to something across centerpoint of island, i.e. thing is on other side of island
#define TIME_FASTTRAVEL				20			// INT - time spent in each location when fasttravelling
#define TIME_MOVEGOOD				30			// INT - time in minutes for 1 crewman to move 1 unit of a good. Also, no matter the crew, this * goods qty /10 is added in minutes.

// ======================================
// WEATHER CONTROLS - JL
// ======================================

int		MAX_WBALLAST =					25;		// INT - how far the weighting will swing in favor of current trend.. use positive integer between 0 and 50 - 0 is no swing - 50 is major swing.. this is for Windspeed
int		MAX_RBALLAST =					25;		// ^^DITTO for rain
int		MAX_FBALLAST =					25;		// ^^DITTO for fog
float	MAX_ABALLAST =					25.0;	// FLOAT - ^^DITTO for wind angle

int		MAX_WINDCHANGE =				5;		// INT - How much the wind CAN change in one hour - use positive integer between 0 and 20
int		MAX_FOGCHANGE =					5;		// INT - ^^DITTO for fog
int		MAX_RAINCHANGE =				5;		// INT - ^^DITTO for rain
#define MAX_ANGLECHANGE					0.5		// FLOAT - ^^DITTO for wind angle

#define FREE_FOG						1		// BOOL - Allow fog during daylight hours 0 - false 1 - true

// ======================================
// WORLDMAP & SHIP ENCOUNTERS:
// ======================================

#define START_DIFF_SHIPCAP			0			// BOOL - 1: Takes player's level and ship class into account when generating ship encounters
												// 0: Encounters are completely random

#define MAX_SHIPS_ON_SEA			32			// INT - original value is 32, DO NOT TOUCH THIS

#define MAP_VOYAGELENGTH			4.0 		// FLOAT - ccc maptweak is 8.0: lets voyages take longer, original 4.0, slower days on worldmap is 2.0

#define MAXPIRATECLASS				4 			// INT - this is the maximum class ship pirates will be given. Defaults to 4.
#define MAXCOASTGUARDCLASS			2 			// INT - this is the maximum class ship for coast guards.
#define MAXMERCHANTCLASS			3 			// INT - DO NOT TOUCH THIS UNLESS YOU HAVE ADDED TRADESHIPS > CLASS 3

#define PIRATES_USE_BOTH_TYPES 		0			// BOOL - do pirates use ships of both war and trade type? If 0, only use type 'war'.

// Coastraiders & Coasttraders mod
float	COASTRAIDER_CHANCE = 		0.2;		// FLOAT - Generates local ships in ports and around the islands. Some are local merchants, others pirates.
												// 0.0 : Stock PotC, no local ships at all
												// 0.1 - 0.9 : The higher that value the more pirates instead of merchants appear
float	NAVYRAIDER_CHANCE = 		0.4; 			// FLOAT - Ditto, but chance that raider is a foreign warship. Chance for that is coastraider_chance * navyraider_chance
#define COASTGUARD_CHANCE		0.3			// FLOAT - chance in percent that ships of the island's nation will be warships, not merchants
#define TRADE_OTHERNATIONCHANCE		0.4			// FLOAT - chance in percent that the tradeship is not of the island's nation
#define CR_CLASS_ABOVE_PCHAR		1			// INT - if Ship sightings are capped, this is how many classes above pchar's ship class the coaster can be.
#define CR_MAX_MINCLASS			6			// INT - highest class minclass can be. Minclass normally scales up as pchar level goes up.
#define CR_MINCLASS_PERLEVEL		4			// INT - move minclass up one notch per this many PChar levels.
#define CR_MAXPIRATECLASS		4			// INT - maximum class of pirate ship for coaster, NOT the same as MAXPIRATECLASS above
#define AUTOCREATE_CR 			1 			// BOOL - Set to 1 to create new coastships every time you leave or approach an island. 0 will create ships only if you ask a citizen about them.
#define DEAD_GENNEW_CR 			0.33 			// FLOAT - chance to make new coastal ship for character if character is dead.
#define CR_PERSIST 			5 			// INT - number of days until new coastal ship is generated
#define DS_MULTIFLEET			0.0			// FLOAT - percentage chance of an extra group in a direct-sail encounter.  Default 0.0, no additional groups.  Likely to cause crashes if set above 0.0


// ======================================
// SAILING & SHIP BATTLES:
// ======================================

#define DECK_VIEW_ON_SEAENTER		0			// INT - Decide where camera should start upon entering a ship
												// 0: Stock PotC, external camera
												// 1: Camera on ship deck

#define USE_REAL_CANNONS			1			// BOOL - 0: Stock PotC: guns fire in a high arc, wide left-right traversing
												//        1: More realistic, direct fire; less left-right traversing possible
#define EXTRA_HIT_CHECK				1			// BOOL - Enable stray shot hits on friendly ships to cause hostility
												//        USE_REAL_CANNONS must be set to 1 for this setting to take effect
												//        1: Yes, when a ship is hit, reduce relation to you
												//        0: No, accidental hits won't cause hostilities

#define USE_REAL_SAILING			1			// BOOL - Off=0, Realistic=1, KNB's sailing / grappling changes
#define REALISTIC_WAVES				1			// BOOL - desc="Set to 0 to disable the realistic waves mod by KiwisDoFly."
#define UPDATE_AI_FREQUENCY			1			// INT - Time frequency in minutes for AI update at sea
#define SAIL_LUFFING_SOUNDS			2			// INT - Set from 1 to 3 to play sail luffing sounds when sailing too close to wind.  0=off, higher numbers add more luffing sound.

#define ARCADE_MULT_TURN			3.0 		// FLOAT - this multiplies base ship-turn-rate, default: 3
#define ARCADE_MULT_SPEED 			2		 	// INT - Shipspeed if you set the menu "Options/Sailing mode" to ARCADE MODE
												// 1: Same speed as in "Realistic Mode"
												// 2: Twice as fast (default setting)
												// 3: 3x as fast etc.
												
#define CANNON_RANGE_SCALAR 		1.0			// 0.3 - 2.0 : The higher the value the longer the cannon range OF SHIPS
												// SET TO 1.0 IF USING REAL CANNONS!
#define FORT_RANGE_SCALAR 			0.5			// 0.3 - 2.0 : The higher the value the longer the cannon range OF FORTS
#define CANNON_DAMAGE_SCALAR 		0.5;		// 0.3 - 2.0 : The higher the value the more damage cannons do
#define ARCADE_MULT_CANNONS			0.5		 	// INT - Cannon reload time if you set the menu "Options/Sailing mode" to ARCADE MODE
												// 1.0: Same speed as in "Realistic Mode"
												// 0.5: Half as much reload time

// Firedrill
// Shipfires started by bombs do more damage and burn longer (by the factors defined below)
// This can be a tactical ADVANTAGE for you cause only you can extinguish fires by pressing the "C" potionuse key.
#define FIREDAMAGE					2			// INT - Stock firedamage is multiplied by this. 1 = original value, disables whole mod; 0 = no fires.
#define FIRETIME					3			// INT - Stock burningtime of shipfires is multiplied by this factor. 1 = original value, 0 = no fires.
#define GUN_DOUSING					1			// BOOL - Set to 0 and gun cartridges will NOT be jettisoned during firedrill
#define FD_REQUIRE_DEFENCE			1			// BOOL - Should fire drill require captains with Basic Ship Defence skill. 1 = yes, 0 = no.
#define AI_FIREDRILL_CHANCE			0.07		// FLOAT - chance each round for AI to do firedrill if burning. Modded by skill.
#define FIREKILLCH_BASE				0.005		// FLOAT - base chance of kill ship from fire
#define FIREKILLCH_HP_MIN			0.5			// FLOAT - kill will not happen unless HP < this * baseHP
#define FIREKILLCH_MAXCH			0.1			// FLOAT - max chance
#define FIREKILLCH_MINCH			0.001		// FLOAT - min chance
#define FIREKILLCH_HP_RAT_PWR		0.5			// FLOAT - power to HP ratio


#define SURR_GLOBAL_SCL				0.04		// FLOAT - Ships will surrender if damage or crew morale become critical
												// 0.0 : Stock PotC, no surrenders
												// 0.01 - 0.5 : The higher that value the faster ships surrender
// Surrender adjustments
#define SURR_MAX_MORALE				30			// INT - if morale > this, no surrender check. Scaled to between below two numbers.
#define SURR_MRL_SCL_MAX			1.0			// FLOAT - (no description)
#define SURR_MRL_SCL_MIN			0.4			// FLOAT - (no description)

// Sailto controls
#define SAILTO_MIN_SPEEDRATIO		0.75		// FLOAT - if your speed is less than this compared to your target's, can't sail-to. Note, also checks wind angle for you and the target running away, and rigtype for both.
#define SAILTO_MIN_DISTANCE			500			// INT - if you are closer than this many units to the enemy ship, you can't sailto.
												// Note: You have to be in realistic sailing mode for both above features to work

#define SAILTO_DISTANCE1			100.0		// FLOAT - Closest you'll find yourself to enemy when using sailto.  Stock is 40.0. Used in AI_Sea.c
#define SAILTO_DISTANCE2			200.0		// FLOAT - Farthest you'll find yourself from enemy when using sailto.  Stock is 100.0.

// Sea Realism Params
float	MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER =			500.0;	// FLOAT - original value is 500 - Petros: reset to 500.0 to prevent trouble
float	MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION =	500.0;	// FLOAT - original value is 500

// KK Mods -->
#define CHANCE_DETECT_FALSE_FLAG_BASE			0.00	// FLOAT - minimal probability of detecting false flag.
#define CHANCE_DETECT_FALSE_FLAG_MAX			0.99	// FLOAT - probability of detecting false flag when Nathaniel rank=MAX_RANK.

#define FLEETCOMMAND_MIN_LEVEL					5		// INT 1-10 - min. level of leadership at which character can command more than a single ship

#define PENNANTS_MIN_YEAR						1000	// INT - year at which ships will use pennants
#define MERCHANT_FLAGS_MIN_YEAR					1000	// INT - year at which merchant ships will use separate flags
// KK <--


// ======================================
// CANNONS
// ======================================

#define JRH_GUNSOUNDS				1			// BOOL - Off=0, Default=1, Jack Rackham's new cannon sounds. USE_REAL_CANNONS must be on for this to do anything.

#define FIRE_ANGLE_SCALAR_W			1.1			// FLOAT - Off=2.0, Realistic=1.0, SET TO 1.0 IF USING REAL CANNONS! scalar to how wide the angle your guns can point (aka elevation). This is multiplied by the build default (30 degrees) to get the final number. Set to 2.0 for stock POTC
#define FIRE_ANGLE_SCALAR_H			1.0			// FLOAT - Off=2.0, Realistic=1.0, SET TO 1.0 IF USING REAL CANNONS! scalar to how high/low your guns can point (aka elevation). This is multiplied by the build default (30 degrees) to get the final number. Set to 2.0 for stock POTC

#define DEFAULT_CHARGE				2			// INT - MUST NOT BE 5 IF USE_REAL_CANNONS is 1!!!! Balls = 2, Grape = 3, Chain/Knippels = 4, Bombs = 5 // KK

#define PROSHIPDEF_NOCRITCH			0.8			// FLOAT - chance a crit is avoided if captain has professional ship defence. Stock POTC is 1.0

// Cannon qty section
#define MIN_CREW_FOR_ALL_GUNS		0.6			// FLOAT - if < crew than this, can't man all guns. if crew > this, reload time less.
#define BEST_RATE_FOR_ALL_CREW		1.25		// FLOAT - if crew is at 1.0 ratio (i.e. crew = mincrew*5) reloading is sped up by this

#define RELOAD_TIME_MULTIPLIER		1.0			// FLOAT - Cannon reload time scalar.  2.0 will make cannons take twice as long to reload

// Amount added to mast damage when mast hit by the following things
#define MAST_ISLAND_SCL				0.5			// FLOAT - (no description)
#define MAST_SHIP_SCL				0.1			// FLOAT - (no description)
#define MAST_BALL_SCL				0.25		// FLOAT - (no description)
#define MAST_GRAPE_SCL				0.1			// FLOAT - (no description)
#define MAST_CHAIN_SCL				0.32		// FLOAT - (no description)
#define MAST_BOMB_SCL				0.33		// FLOAT - (no description)
#define MAST_MULT_SCL				0.75		// FLOAT - (no description)

// Ammo section
// Default ammo loadout for stock ships (hardly ever used)
#define DEFAULT_NUM_BALLS 			900			// INT - (no description)
#define DEFAULT_NUM_GRAPE 			510			// INT - (no description)
#define DEFAULT_NUM_KNIPPELS 		500			// INT - (no description)
#define DEFAULT_NUM_BOMBS 			570			// INT - (no description)
#define DEFAULT_NUM_GUNPOWDER 		900			// INT - added by MAXIMUS [gunpowder mod]

#define MAX_TO_RELOAD				0.25		// FLOAT - if reloading has progressed past this point, do not give new ammo.
#define OUTOFRANGE_SCL				1.5			// FLOAT - if range to target > this * current ammo range, will change to best range ammo, even if not reloading now

#define MAXRANGE					0.8			// FLOAT - if range >= this, will load best range ammo
#define CREWCH_ALL					0.75		// FLOAT - chance to fire against crew if in range
#define HULL_PCT_CHAIN				0.25		// FLOAT - if our hull < this, will switch to chain and try to escape.
#define CHAIN_SPEEDDIFF 			5			// INT - if enemy > this kts faster, use chain
#define CHAIN_SPEEDDIFF_CHANCE		0.5			// FLOAT - chance to do above.
#define TARGET_HULL_MIN				0.2			// FLOAT - if their hull < this, will fire hulldamage ammo to sink them.
#define HULLCH						0.75		// FLOAT - chance to do above

// Destroyable Cannons
#define CAN_DESTROY_CHANCE			0.02		// FLOAT - chance to destroy a cannon--note, PER SHOT. And also scaled by ball dmg vs ship max hp
#define CAN_DESTROY_ON_CRIT			0.5			// FLOAT - chance to destroy a cannon on a critical hit
#define CAN_DESTROY_OTHERARC		0.1			// FLOAT - chance if no guns on current arc, check other arcs
#define CAN_FIXABLE_MIN				0.25		// FLOAT - min chance for destroyed gun to be fixable
#define CAN_FIXABLE_MAX				0.75		// FLOAT - max chance for destroyed gun to be fixable


// ======================================
// BOARDING & CAPTURING
// ======================================

// Realistic distances for board surrendered ships
#define BOARD_SURR_DISTANCE_MULT	10.0		// FLOAT - Times surrendered ship box size to automatically board

// Boarding weapons
#define WEAPONSLOCKER				1			// BOOL - 1 = boarders will take swords AND guns out of the new weaponslocker in your cabin
#define BOARDER_SPAREBLADE			"blade4"	// ITEMID -  sword your boarders will get if the weaponslocker is empty, choose itemID from Items\initItems.c
#define GET_WEAPONS_BACK			1			// BOOL - 1 = boarders will give weapons back to you after fight; 0 = you need new weapons for every boarding

#define FENCING_BOARD_PWR			0.25		// FLOAT - influence of melee skill on boarding odds for AI boarding player, implemented as an exponent.

#define SHIPMONEY_MULT				0.001		// FLOAT - multiplier to how much money you get on boarding

// Surrender scalars _for in boarding process_, NOT for on sea
#define SURRENDER_SCL_POW			0.4			// FLOAT - (no description)
#define SURRENDER_SCL_ADD			-0.2		// FLOAT - (no description)
#define SURRENDER_SCL_COEFF			0.5			// FLOAT - (no description)
#define SURRENDER_SCL_MIN			0.9			// FLOAT - (no description)
#define SURRENDER_SCL_MAX			1.75		// FLOAT - (no description)

#define SWAPBOARDING				1			// BOOL - when we are boarded (vs. our boarding an enemy), locations are reversed. Set to 0 to disable that.
#define BOARDERMODEL2				"blackman"	// STRING - additional modeloptions, take effect only if BOARDERMODEL is not "" or one of the groupnames
#define BOARDERMODEL3				"killer"	// STRING - ditto
#define BOARDERMODEL4				"will"		// STRING - ditto

// KK -->
// Models for Nathaniel's boarders.
// These are filenames from resource\models\characters but with extra character at the end describing whether they are
// men ("M"), ladies ("W") or skeletons ("S"). Empty string ("") gets stock default.

#define BOARDERMODEL 				"standard"	// Outfit for your boarders, insert one of these groups (Don't change spelling or the "" !): 
												// "marine", "corsair", "masked", "skeleton", "girl", "soldier" (soldiers of current flag),
												// "boarder" (Nathaniel's soldiers); default: "standard"

#define NATHANIEL_BOARDER_0			"33_TG5DW"
#define NATHANIEL_BOARDER_1			"33_Piratess10W"
#define NATHANIEL_BOARDER_2			"Skel3S"
#define NATHANIEL_BOARDER_3			"towngirl1W"
#define NATHANIEL_BOARDER_4			"Will_2M"
#define NATHANIEL_BOARDER_5			""
#define NATHANIEL_BOARDER_6			"towngirl7W"
#define NATHANIEL_BOARDER_7			"Corsair1_4M"
#define NATHANIEL_BOARDER_8			"50_IndiaW"
#define NATHANIEL_BOARDER_9			"black_corsairM"
#define NATHANIEL_BOARDER_10		"black_corsairM"
#define NATHANIEL_BOARDER_11		"black_corsairM"

#define BOARDER_INDEX				-1			// INT - range= -1,100 , Select model for Nathaniel boarders.
												// -1: random (generates different sets for every deck; works also for remaining groups),
												// 0: sequential (NATHANIEL_BOARDER_1 to NATHANIEL_BOARDER_5; works also for remaining groups),
												// 1-99: one selected model for all boarders (works also for remaining groups in range from 1 to 99),
												// 100: sequential (NATHANIEL_BOARDER_6 to NATHANIEL_BOARDER_10; for remaining groups identical to 0).
// <-- KK

// PRISONER RANSOM OPTIONS Based on code by Stone-D and Nathan Kell, all credit and thanks to them :)
// You can't get ransom for your prisoners at sea anymore but at certain landlocations only. Choose ONE locationtype from the list. Can be changed during saved games.
#define RANSOMSITE					"all" 		// STRING - You can change 'all' to: 'town', 'jungle', 'dungeon', 'residence', 'church' or 'tavern'.
#define RANSOM_AT_HOME				0			// BOOL - If you set this option to 1 you must take the prisoner to his 'homeisland' to get ransom (i.e. the island with the prisoners nation)
#define RELEASE_AT_SEA				1			// BOOL - If enabled, you can only 'release' captives at sea (for 0 gold); you must go to the ransomsite to ransom them. If ransomsite 'all', you must go to land.
#define ACTOR_WHEN_BOARDING			0			// BOOL - If enabled, main character will run on boarding deck or in residence to initiate dialog with defeated enemy; otherwise player must go to him/her "manually".


// ======================================
// SPYGLASS VIEW by KBLACK
// ======================================

// --- Makes the info given by spyglasses unaccurate and depending of distance
// (all nautical terms are in spanish - except those I know in English)
// (all settings are INT)

// --- KBSPG - Fine tuning section (set by default to "Fun" )
// --- Accuracy parameters
#define KBSPGACCSPG1				4			// Accuracy parameter of Cheap Spyglass
#define KBSPGACCSPG2				3			// Accuracy parameter of Standard Spyglass
#define KBSPGACCSPG3				2			// Accuracy parameter of Good Spyglass
#define KBSPGACCSPG4				1			// Accuracy parameter of Mastercraft Spyglass

// --- Range parameters. Further modified by Accuracy of spyglass

#define KBSPGRANGEHULL				700			// Range in yards to start getting info about hull status
#define KBSPGRANGECLASS				1500		// Range in yards to start getting info about class of ships ( number of decks and details of hull )
#define KBSPGRANGECANNONS			750 		// Range in yards to start getting info about number of cannons (counting "portas")
#define KBSPGRANGEGUNPOWDER			250			// Range in yards to start getting info about quantity of gunpowder (counting "portas")
#define KBSPGRANGENAME				450			// Range in yards to start getting info about name of ships (you've to be close to read it)
#define KBSPGRANGELOAD				250			// Range in yards to start getting info about type of ammo loaded

#define KBSPGRANGESAILS				1400		// Range in yards to start getting info about sails status (easy to see from far away)
#define KBSPGRANGENATION			1300		// Range in yards to start getting info about nation - if you see the sails, you see the flag - further away you get "UNKNOWN" nation
#define KBSPGRANGESPEED				1000		// Range in yards to start getting info about speed - although more inaccurate with the distance, you can guess it
												// from the waves the ship makes, and the change in distance, and the rigging deployed

#define KBSPGRANGECREW				450			// Range in yards to start getting info about number of sailors (in realistic, fun or tuned, you'll get the fraction
												// of sailors in the topo deck, and have to calculate depending the number of decks the ships has - a lugger, what you
												// see it's what you get; a manowar, you have most of the crew in the lower decks
#define KBSPGRANGEMORALE			350			// Range in yards to start getting info about morale of crew
#define KBSPGRANGECALIBER			500			// Range in yards to start getting info about caliber of guns

#define KBSPGRANGETYPE				1800		// Range in yards to get the type of ship - really funny to have to guess the ship by the shape :-)
												// No need for RANGE - but also spyglasses return unaccurate info about distance

// --- Variability of the info - scalar to tune how wide is the range of variable info. I't multiplied by accuracy of spyglass.

#define KBSPGVARHULL				5			// Default 5 - Higher more unaccurate
#define KBSPGVARCANNONS				20			// Default 20 - Lower more unaccurate
#define KBSPGVARGUNPOWDER			20			// Default 20 - Lower more unaccurate
												// No need for KBSPGVARCLASS
												// No need for KBSPGVARNAME
												// No need for KBSPGVARLOAD

#define KBSPGVARSAILS				1			// Default 1 - Higher more unaccurate
#define KBSPGVARSPEED				100			// Default 100 - Lower more unaccurate
												// No need for KBSPGVARSAILS

#define KBSPGVARCREW				10			// Default 10 - Lower more unaccurate
												// No need for KBSPGVARMORALE
												// No need for KBSPGVARCALIBER
												// No need for KBSPGVARTYPE

#define KBSPGVARRANGE				20			// Default 20 - Lower more unaccurate


// ======================================
// SHIP MANAGEMENT, REPAIRS, TRADING:
// ======================================

// Crew morale section
#define CREW_PCT_FOR_MORALE			0.02		// FLOAT - morale decreases by 1 for each time crew decreases by this pct.

// Combat levels - also, how much decrease in morale
#define COMBATLEVEL_NONE			0.0			// FLOAT - not in combat
#define COMBATLEVEL_ENEMYHERE		0.06		// FLOAT - not in combat but enemy present.
#define COMBATLEVEL_GUNS			0.08		// FLOAT - fired OR RELOADED guns, but has not been hit
#define COMBATLEVEL_HIT				0.3			// FLOAT - has been hit. Note this is increased by crewpct above

// Time delays, in seconds -- how long does the combatlevel last
#define TIME_SINCE_GUNS				120			// INT - (no description)
#define TIME_SINCE_HIT				60			// INT - (no description)

#define MORALE_AMT_COMEBACK			0.5			// FLOAT - amount by which morale goes back towards basemorale each time we update morale

int		RANGE_TO_ENEMY =			3000;		// INT - in feet/yards/whatever unit the game uses.
#define DIST_NOSHIP					100000.0	// FLOAT - big dist num

#define CLASS_SCALAR_FOR_MORALE 				5.0	// FLOAT - class ratio between killship and deadship is scaled by this before applied as morale bonus to killer.
#define CLASS_SCALAR_FOR_MORALE_OTHER 			1.0	// FLOAT - class ratio between current enemy ship and deadship scaled by this before applied as morale bonus to current enemy ship
#define CLASS_SCALAR_FOR_MORALE_ORIG_TO_OTHER 	0.1	// FLOAT - in addition to above, current enemy ship gets this * the killer ship's morale bonus as well (so if a MoW sees a schooner kill a frigate, they get both the bonus for the frigate death and this * the bonus for the schooner killing it)

#define CHANGE_MORALE_EVERY			6			// INT - change crew morale based on above once per this many seconds. THIS WILL ALSO SCALE MORALE CHANGES! Bigger number, less effect. Should be divisable by 3.

// Shipyard behavior management (NK PRS3 TIH)
#define SHIPYARD_CHANCE_OTHERNATION			0.1 // FLOAT - chance a ship at a shipyard will not be from shipwright's nation.
#define CHANCE_OVERRIDE_PRS3NAT_IF_PIRATE	0.4 // FLOAT - chance to use a random nation rather than PIRATE if passed nation is pirate in SetRandomStatsToShip()
#define CHANCE_OVERRIDE_SHIPNATION			0.0 // FLOAT - chance to use passed nation rather than base ship's nation if base ship has nation. Defaults to never doing so. Will almost never be used.

#define SHIPYARD_SELL_ALL_CLASSES		0		// BOOL - are shipyards limited to selling only certain classes of ship, based on town size (see STORE_MINSIZE, below, in Town Constants
#define SHIPYARD_CHANCE_CLASS			9		// INT - default 8. Chance for a ship to be available is 1 in (this - ship class). So if this is 8, then a class 1 ship has a 1-in-7 chance of being available. NOTE setting to 0 makes any ship always available.
#define SHIPYARD_SHIP_SELL_MULT			0.30	// FLOAT - multiplier to sell price for ship - non rpgstyle shipyards
#define SHIPYARD_BOUGHTSHIP_SELL_MULT	0.90	// FLOAT - SY_RPG_STYLE - multiplier to sell price for a LEGIT ship (one you bought originally)
#define SHIPYARD_PIRATEDSHIP_SELL_MULT	0.10	// FLOAT - SY_RPG_STYLE - multiplier to sell price for a PIRATED ship (one you acquired through an unrespectable act) - sale prices for legal prize ships are halfway between this and BOUGHTSHIP_SELL_MULT
#define SHIPYARD_NAVY_PRIZE_SELL_MULT	0.20	// FLOAT - SY_RPG_STYLE - multiplier to sell price for a NAVY taken ship (one you acquired through lawful act as serving naval officer)
#define SHIPYARD_PRIV_PRIZE_SELL_MULT	0.50	// FLOAT - SY_RPG_STYLE - multiplier to sell price for a PRIVATEER taken ship (one you acquired when in possession of a relevant LOM)
#define SHIPYARD_NAVY_WEALTH_MULT		0.125	// FLOAT - multiplier which controls how much of the navy prize money is diverted into player wealth instead of crew money
#define SHIPYARD_CANNON_SELL_MULT		0.75	// FLOAT - multiplier to sell price of cannon
#define SHIPYARD_RPG_LPC				3		// INT - levels needed per class of ship to purchase (starting with class 6) (only used if SY_RPG_STYLE is on)
												// EX: set to 3, a level 4 player can buy class 5, 6 and 7... level 3 player can only buy class 6 and 7... level 13+ can buy any class (except ships of the line class 1 - those are NEVER SOLD!!!)

/* ----REALISTIC SHIP PURCHASE----
This mod disables the selling of navy ships to characters who don't have a high enough national rank

Note: Navy ships are ships that have Type.War = true and Type.Trade = false
      If you want a certain ship to not be considered a navy ship, change these settings in ships_init.c

Settings per ship class:
------------------------
-1 = No LoM required
 0 = Only a LoM required
>0 = National rank required (see nations_init.c)
Set all to -1 to disable this mod
*/
#define RANK_FOR_EIGHTH_RATE			-1		// Default: No LoM Required
#define RANK_FOR_SEVENTH_RATE			-1		// Default: No LoM Required
#define RANK_FOR_SIXTH_RATE				0		// Only a LoM required
#define RANK_FOR_FIFTH_RATE				2		// Lowest rank: Junior Lieutenant (England)
#define RANK_FOR_FOURTH_RATE			4		// Lowest rank: Senior Lieutenant (England)
#define RANK_FOR_THIRD_RATE				6		// Lowest rank: Captain (England)
#define RANK_FOR_SECOND_RATE			8		// Lowest rank: Rear Admiral (England)
#define RANK_FOR_FIRST_RATE				10		// Lowest rank: Admiral (England)

// Blacksmith mod adjustments
// Note: Setting ENABLE_WEAPONSMOD to 0 will disable this mod
#define BLACKSMITH_PAY_OUT_WEALTH	0			// BOOL - Set to 1 to pay the blacksmith from your personal wealth; set to 0 to pay him from the party's money
#define BLACKSMITH_PROFITPERCENT	10			// INT - The blacksmith will add this percentage for his own profit

// Store goods merchant AUTO BUY settings
// For each ammo type, the button will buy this many rounds per cannon
#define BALLS_PER					15.0 		// FLOAT - suggested balls_per: 15.0
#define GRAPE_PER					15.0 		// FLOAT - suggested grape_per: 15.0
#define CHAIN_PER					15.0 		// FLOAT - suggested chain_per: 15.0
#define BOMBS_PER					15.0		// FLOAT - suggested bombs_per: 15.0
#define POWDER_PER					0.6667		// FLOAT - enough cannon powder to fire this fraction of your ammo

// For sail and plank, the button will buy this many units of sail / plank per point of hull HP of the ship
#define SAIL_PER					0.01 		// FLOAT - suggested sail_per: 0.01
#define PLANKS_PER					0.02 		// FLOAT - suggested sail_per: 0.02

// For wheat and rum, the button will buy this many days' worth of wheat, or rum, for your current crew size.
// Note that this is for /double/ rum rations; so normally set this to half the number of days' worth of rum.
#define WHEAT_DAYS					30.0 		// FLOAT - suggested wheat_per: 30.0
#define RUM_DAYS					15.0 		// FLOAT - suggested rum_per: 15.0, 30 days at normal rum rations.
#define CREW_WEIGHT					2.0			// FLOAT - weight of a single crewmember

//****** KB Tuning Ships *****

// ( These ones came from shipyard.c )
#define sailCostPercent			10  //int 0-100
#define hullCostPercent			20  // int 0-100


// ---- ADD ONS ---- All need shipyards. All can take out.

//Copper plates
#define CPSPEEDRANGEMAX			5		// int 0-100
#define CPSPEEDRANGEMIN			0		// int 0-100
#define CPTURNINGRANGEMAX		2		// int 0-100
#define CPTURNINGRANGEMIN		0		// int 0-100
#define CPINERTIARANGEMAX		0		// Not implemented
#define CPINERTIARANGEMIN		-5		// Not implemented
#define CPTIMEMULT				1		// Time to repair all hull multiply by CPTIMEMULT
#define CPDISP					5		// int 0-100 Chance of being available
#define CPCOSTMULT				4		//Ships price * CPCOSTMULT

//Bronze cannons
#define BCACC					10.0	//float 0-100 increase of accuracy
#define BCRELOAD				10.0	//float 0-100 decrease of reload time
#define BCCRITICALCANNON		2.0		//float Multiplies the chance of loss a normal cannon
#define BCWEIGH					-5		//Not implemented
#define BCDISP					10		// Availability
#define BCCOSTMULT				1750	// Cannons price per BCCOSTMULT

//Good chasers
#define GCACCADD				10.0	//float 0-100 - increase of accuracy
#define GCRANGEADD				1.1		//increase of speed - be careful: too big and the Fantoms will not aim correctly
#define GCSAILCRIT				8.0		//float 0-100 - % of sail crit - to be added to CSAILCRIT
#define GCMASTCRIT				20.0	//float 0-100 - % of mast crit
#define GCDISP					10		// int 0-100 Chance of being available
#define GCCOSTMULT				2000	// GCCOSTMULT * rcannons.cost(depending cannons fitted) * 2

// Common chasers
#define CSAILCRIT				5.0		//float 0-100 - % of sail crit
#define CSAILCRITDMG			4.0     // Damage multiplier if sail crit , either with chasers or good chasers
#define CMASTCRIT				15.0	// float 0-100 - % of mast crit

// Guns
#define MASTCRIT				8.0		//float 0-100 - % of mast crit

//New sails and ropes
#define NSSPEEDRANGEMAX			5		//int 0-100
#define NSSPEEDRANGEMIN			0		//int 0-100
#define NSSAILHPRANGEMAX		10		//int 0-100 % of damage reduction
#define NSSAILHPRANGEMIN		0		//int 0-100
#define NSINERTIARANGEMAX		0		//Not implemente
#define NSINERTIARANGEMIN		-10		//Not implemente
#define NSTIMEMULT				1		// Time to repair all rigging multiply by NSTIMEMULT
#define NSDISP					25		// int 0-100 Chance of being available
#define NSCOSTMULT				0.5		// Cost of repair all rigging multiply by NSCOSTMULT

//Long top-masts
#define TMSPEEDRANGEMAX			10		//int 0-100
#define TMSPEEDRANGEMIN			0		//int 0-100
#define TMINERTIARANGEMAX		0		//Not implemente
#define TMINERTIARANGEMIN		-10		//Not implemente
#define TMSAILCRIT				4		//int 0-100 increase of % of mastcrit
#define TMTIMEMULT				1		// Time to repair all rigging multiply by TMTIMEMULT
#define TMDISP					15		// int 0-100 Chance of being available
#define TMCOSTMULT				0.5		//Cost of repair all rigging multiply by TMCOSTMULT

//Staysails
#define SSTACKRANGEMAX			0.0		// float 0 - 1 Degrees of improve ClosestPoint - remmeber that ClosestPoint goes from 0 to 1
#define SSTACKRANGEMIN			-0.1	// float 0 - 1 Degrees of improve ClosestPoint - remmeber that ClosestPoint goes from 0 to 1
#define SSTURNINGRANGEMAX		5		// int 0-100
#define SSTURNINGRANGEMIN		0		// int 0-100
#define SSTIMEMULT				1		// Time to repair all rigging multiply by SSTIMEMULT
#define SSDISP					3		// int 0-100 Chance of being available	// Rare
#define SSCOSTMULT				0.5		//Cost of repair all rigging multiply by SSCOSTMULT

//Reinforced Hull --- No way back!!!!
#define RHHULLHPRANGEMAX		10		//int 0-100
#define RHHULLHPRANGEMIN		0		//int 0-100
#define RHINERTIARANGEMAX		10		//Not implemented
#define RHINERTIARANGEMIN		0		//Not implemented
#define RHCALIBERADD			1		// Number of calibers up
#define RHTIMEMULT				1		// Time to repair all hull multiply by RHTIMEMULT
#define RHDISP					50		// int 0-100 Chance of being available	// Rather easy
#define RHCOSTMULT				40		// Cost of repair all hull multiply by RHCOSTMULT

// Pirate "flush" of ships - reduce the superstructure of captured ships in order to make them more "frigate-like"
// Need pirate or smuggler shipyard
// Just One way and only once in a ship
// Should change the model of ship in certain cases???

#define FLUSHSPEEDRANGEMAX		15		//int 0-100
#define FLUSHSPEEDRANGEMIN		5		//int 0-100
#define FLUSHTURNINGRANGEMAX	15		//int 0-100
#define FLUSHTURNINGRANGEMIN	5		//int 0-100
#define FLUSHHULLHPRANGEMAX		-5		//int 0-100
#define FLUSHHULLHPRANGEMIN		-7		//int 0-100
#define FLUSHLOADRANGEMAX		20		//int 0-100
#define FLUSHLOADRANGEMIN		10		//int 0-100
#define FLUSHEDCOSTMULT			6		//int 0-100
#define FLUSHEDTIMEMULT			1		//int 0-100
#define FLUSHEDPROB				10		//int 0-100 Chance of being on in a fantom
#define FLUSHEDPROB_IFPIRATE	60		//int 0-100 Chance of being on in a fantom


// ======================================
// ITEMS AND ITEM-TRADING
// ======================================

// Quality defines
#define IT_QUAL_MIN					1			// INT - minimum quality for items
#define IT_QUAL_MAX					10			// INT - max quality for items
#define IT_QUAL_MAXABOVE			1.0			// FLOAT - was 2 max trader qual can be above itm qual before itm gets rarer
#define IT_QUAL_ADDABOVE			1.0			// FLOAT - added to trader qual for formula when itm.qual is too much lower than trader qual
#define IT_QUAL_ABOVESCL			1.0			// FLOAT - was 2.5 scalar to inverse ratio power formula. Increase this to make too-low-quality items less rare.
#define IT_QUAL_POWER_BELOW			3.0			// FLOAT - power the traderqual/itemqual ratio (when tqual is below or near iqual)
#define IT_QUAL_POWER_ABOVE			3.5			// FLOAT - was 2 power the itemqual / tradequal ratio when tradequal is too high
#define IT_QUAL_AI_POW				0.5			// FLOAT - power to price when autoassign qual to items
#define IT_QUAL_AI_SCL				0.165		// FLOAT - scalar to price^pow when autoassign qual to items
#define IT_QUAL_AW_POW				0.33333		// FLOAT - power to price when autoassign qual to weapons
#define IT_QUAL_AW_SCL				0.22		// FLOAT - scalar to price^pow when autoassign qual to weapons
#define IT_QUAL_FLOOR				0.01		// FLOAT - if the mult is < this, it becomes 0 (we don't bother with item)
#define IT_QUAL_FLOOR_LQ			0.15		// FLOAT - ditto but for qual < trader qual
#define IT_QUAL_BUYONLY				0.00001		// FLOAT - qty mult when quality mult leads to buyonly.
#define IT_WEAP_RARITY_CUTOFF		0.02		// FLOAT - (RPG_STYLE only) do not sell any weapons rarer than this (if Rarity less than IT_WEAP_RARITY_CUTOFF, then do not sell)
#define IT_WEAP_LOWQUAL_CUTOFF		1			// INT - (RPG_STYLE only) if a merchant has more than one quality of the same weapon, this is the quality cutoff below the highest quality weapon carried. Set this to 0 or 6 if you NEVER want cutoff (if lower weapon quality less than IT_WEAP_LOWQUAL_CUTOFF below highest quality weapon, then do not sell, buy only; EX:  ( Worn(1) < (Fine(4) - 2) ) = do not sell)
#define IT_DROP_LOWQUAL_ITEMS		0			// BOOL - (RPG_STYLE only) toggle: have merchants not sell extremely low quality items to high level players (can make most poor quality merchants not have much of anything to sell higher level characters... could be a good thing, or bad thing, off by default because of it)
#define IT_WEAP_PRICE_SCL			0.25		// FLOAT - scalar to weapon price (does not affect weaponsmod created weapons)
#define IT_RARE_NUMTRIES			15			// INT - number of times we try to give an item to a trader. We test modified rarity each time, and if frnd() less than rare, we give item. This is also maxqty.
#define IT_BASE_PRICE_SCL			1.0			// FLOAT - base scalar to item price.

// Update defines
#define IT_UPD_SKIPOLD				1.0			// FLOAT - chance to, when updating, skip an item if we already have 1+ of that type.
#define IT_UPD_COUNTFAIL			0.75		// FLOAT - count a failed add attempt as an attempt.
#define IT_UPD_CLOSE				0.1			// FLOAT - closeness to old type for balanced update.
#define IT_UPD_PRICEQTY				0.5			// FLOAT - power to the scaling pricechange makes to qty
#define IT_UPD_KEEP_MINQTY			0.5			// FLOAT - with a rare*qty of >= this, keep 1 to IT_UPDATE_KEEP_MAX of the item
#define IT_UPD_KEEP_MAX				4			// INT - max num of items to keep if rare meets IT_UPDATE_KEEP_MINQTY. Note this is for rare*qty = 1.0. If r*q>1.0, num will be > this.
#define IT_UPD_RAREMIN				0.1			// FLOAT - if trader has only 1 of an item, and its rarity is <= this, it's handled specially
#define IT_UPD_TOWNPRICE			10			// INT - (no description)
#define IT_UPD_INPORT_MULT			3.0			// FLOAT - multiplier to adding new goods, and sell/buy chances, when ship in port. Note: unused at the moment.
#define IT_UPD_INPORTPC_MULT		1.25		// FLOAT - ditto but for player.
#define IT_UPD_TS_FLEET_MULT		0.25		// FLOAT - how many town citizens a crewman counts as for town item qty checks
#define IT_UPD_TRADECHNOI			0.25		// FLOAT - chance will do normal buy/sell rather than givenewitems if trader doesn't have item.
#define IT_UPD_NUMTRIESMULT			0.5			// FLOAT - multiplier to NUMTRIES when updating.
#define IT_UPD_MONEYCHANGER			0.1			// FLOAT - difference in current vs chosen money * this = change in money per update
#define IT_UPD_TOWNQUAL_DAYS		7			// INT - number of days until new town quality takes effect, to avoid quick quality swings.

#define IT_OVER_RANDSPREAD			4			// INT - when rare * qty > 1.0, we add qty by dividing IT_RARE_NUMTRIES by this and then taking that number for a random add this number of times. Bigger values here mean more curved distribution, smaller means flatter.

// Itemtrader type defines (STRING)
#define IT_TYPE_GENERAL				"General"	// general trader type, catchall default
#define IT_TYPE_STORE				"Store"		// shopkeeper type
#define IT_TYPE_STALL				"Stall"		// item trader type
#define IT_TYPE_SNEAKY				"Sneaky Trader" // vagabonds and special wandering traders
#define IT_TYPE_BLACKSMITH			"Smith"
#define IT_TYPE_JEWELER				"Jeweler"
#define IT_TYPE_TAILOR				"Tailor"
#define IT_TYPE_BOOKSELLER			"Bookseller"
#define IT_TYPE_MAPMAKER			"Mapmaker"
#define IT_TYPE_CURIO				"Curio"
#define IT_TYPE_TATTOO				"Tattooist"
#define IT_TYPE_MEDICAL				"Apothecary"

// Computed itemtrade types
#define IT_TYPE_ISLAND				"island_"	// STRING - prefix tag
#define IT_TYPE_TOWN				"town_"		// STRING - prefix tag
#define IT_TYPE_NATION				"nat_"		// STRING - prefix tag
#define IT_TOWNTYPE_QTY				1.33		// FLOAT - qty scalar for town type
#define IT_TOWNTYPE_PRICE			0.8			// FLOAT - price scalar for town type
#define IT_TOWNTYPE_QUAL			1			// INT - qual add for town type
#define IT_ISLANDTYPE_QTY			1.25		// FLOAT - qty scalar for town type
#define IT_ISLANDTYPE_PRICE			0.9			// FLOAT - price scalar for town type
#define IT_ISLANDTYPE_QUAL			1			// INT - qual add for town type
#define IT_NATIONTYPE_QTY			1.25		// FLOAT - qty scalar for town type
#define IT_NATIONTYPE_PRICE			0.9			// FLOAT - price scalar for town type
#define IT_NATIONTYPE_QUAL			1			// INT - qual add for town type

// Town item defaults
#define IT_TSIZE_MIN				0.5			// FLOAT - min for town size scalar
#define IT_TSIZE_MAX				3.0			// FLOAT - max for town size scalar
#define IT_TSIZE_NORMAL				1000		// FLOAT - town size where mults are 1.0

// Updating speed params
#define IT_MAX_DAYS_TO_UPDATE		30			// INT - if it has been longer than (this) many days since you last traded with the itemtrader, the item stock will be deleted and the trader will not be given updates (and will start fresh the next time you talk).
#define IT_STEPS_ON_UPDATE			3			// INT - Traders are updated in this many pases, so 1/(this) of all traders are updated per day and there is a delay of (this) many days between updates for each trader.

// Shouldn't be touched
#define IT_RECALC_QL_TN				1			// INT - (no description)
#define IT_RECALC_ALL				2			// INT - (no description)
#define IT_CLEAN_REINIT				0			// INT - set to 1 and reinit will clear all traders' items and stats always

// Junk auto sell settings
#define SELL_JUNK_BLADES			1			// INT - Set to 1 to sell blades using Sell All Loot that are unlikely to be useful at your level. Default 0
// If SELL_JUNK_BLADES is 0, the following won't be used.
#define JUNK_BLADE_LEVEL_1			5			// INT - At this character level start selling blades with max damage less than 20. Default 5. Set to 999 to disable.
#define JUNK_BLADE_LEVEL_2			9			// INT - At this character level start selling blades with max damage less than 25. Default 9. Set to 999 to disable.
#define JUNK_BLADE_LEVEL_3			13			// INT - At this character level start selling blades with max damage less than 30. Default 13. Set to 999 to disable.

// Item skill increases
#define MAX_SKILL_INCREASE			4			// INT - The maximum number of skill points you can gain from items

// Rarity and random controls
// Note: in this block, when I talk about rare scalars, I mean scalars to the attribute itm.rare, where "rare" is the probability of finding an item.
// So anything that makes the _attribute_ rare larger (i.e. scalars of >1) actually make the item _less_ rare.
// rarity for item = itm.rare * base_scalar * (luck_scalar, 1.0 to LUCK_RARE_MAX)
#define RARE_DEFAULT				0.1			// FLOAT - default rarity for items that lack a .rare
#define BASE_RARE_SCALAR			1.0			// FLOAT - final rarity scaled by this
#define LUCK_RARE_MAX				1.5			// FLOAT - scalar when player luck = max. Note, it's _summoned_ luck, so officers' lucks count too.
#define RARE_RAND_RETRIES			2			// INT - RPG_STYLE only - How many times it will try to find a random item for a locator
#define RARE_MAXLEVEL_ABOVE			10			// INT - RPG_STYLE only - 0 = off - How many levels above the character a random spawned item can be - players LUCK is factored in by half points - try not to set this too low, or really low level characters will basically never find anything good!
#define RAND_ITEM_NOSKIP			0.3			// FLOAT - random chance a spawned box item will spawn ANOTHER item, and so forth (can get out of hand if set too high!)
												// normally, when a random item is picked for a box, and it cannot be spawned (too rare, too high minlevel),
												// another will not be chosen. This is the probability that another /will/ be chosen.
												// Note that this is tested each time, so the probability of trying for a /third/ time is prob * prob;
												// in mathematical terms, the probability to try for the nth try = prob ^ (n-1).
												// setting this too high may result in an endless loop on opening a box!!!


// ======================================
// LAND EXPLORATION, LOCATIONS:
// ======================================

#define QUEST_CHAR_MONEY				20000	// INT - The amount of money some quest characters have. Stock value 1000000

#define CITIZEN_STOPCHANCE				0.50	// FLOAT - Off=0, Default=0.50, Chance for a citizen to stop when the player approaches.
#define CITIZEN_TALKCHANCE				0.005	// FLOAT - Off=0, Default=0.05, Chance for a citizen to engage the player in conversation on their own.
#define TIME_BETWEEN_DLG				600		// INT - Default=120, Time in seconds between the same citizen auto-starting dialog is somewhere between this and 2x this.
#define TIME_BETWEEN_DLG_ALL			300		// INT - Default=30, Time in seconds between any citizens auto-starting dialog is somewhere between this and 2x this.

#define VAG_MERCH_CHANCE 				0.2 	// FLOAT - chance that vagabond is merchant in disguise

#define FORT_RAIDSUCCESS				50		// INT - chance in % that fortgarrisons yield to your demands

#define CCC_PITFALLS					1		// INT - set to -1 to turn off autoreload, or above 0 to set the locator radius

#define RANDOM_DUNGEON_BLADES           0		// BOOL - set weather blades in dungeons from stock POTC are randomised. set to 0 to return to stock functionality.
#define OBJECTS_IN_BOX					3		// INT - Changed from build-default of 5 to 3 on 05-07-25 for randitem...tone down boxes now that we can loot corpses.

// VICE CITY (ccc, done with a lot of help by NK) - generates lots of friendly and/or hostile people in town
#define TOWN_VCSKIP_DISABLEALL			1 		// BOOL - change to 0 if vags still generated if loc has skip attr.
#define TOWN_ENC_CHANCE					1.0 	// FLOAT - chance for anyone to be generated in town during day
#define TOWN_ENC_CHANCE_NIGHT			0.4 	// FLOAT - chance, like above, but at night
#define TOWN_BANDIT_CHANCE				0.1 	// FLOAT - chance of there being bandits at all. x2 if at night.
#define TOWN_BANDIT_RESPAWN_CH			0.1 	// FLOAT - chance for bandits to be spawned again that day.
#define TOWN_BANDIT_ENC_SCALAR			0.25 	// FLOAT - bandit probability scaled by this
#define TOWN_BANDIT_RESPAWN_SCL			0.2 	// FLOAT - scalar to bandit prob if already bandits gen'd today.
#define TOWN_BANDIT_MAX					0.2 	// FLOAT - max bandit probability
#define TOWN_OFFSET						-5		// INT - offset to rank for monsters in town, for Create_Officer(). CURRENTLY ALSO USED FOR HOUSE
#define DEFAULT_TOWN_MONSTERPROB		1.0 	// FLOAT - default probability for bandits in a town (if there is not a town-specific setting)

// All houses have permanent residents now. The friendly ones have lots of options
#define HOUSE_ENC_CHANCE				0.9 	// FLOAT - chance to find someone(s) in the house
#define HOUSE_BANDIT_CHANCE				0.1 	// FLOAT - chance for that to be bandit(s)
#define HOUSE_FIGHTDISABLE_ALL			0		// BOOL - change to 1 to disable ALL encounters in houses with fight disabled; 0 leaves vags gen'd there.
#define HOUSE_DISFIGHT_SCL				0.5 	// FLOAT - scalar to chance of encounter if fight is disabled. Only used if disableall is false.
#define HOUSE_OLDPEOPLE_REAPPEAR		0.75 	// FLOAT - chance for the owner(s) to be in the house. Note that we must have passed enc_chance itself first.
#define HOUSE_OLDPEOPLE_BANDIT			0.25 	// FLOAT - if above false, will check for bandit; if OK will spawn bandit.

// Tavernbrawls may take place in barrooms, and travellers appear
#define TAVERN_ENC_CHANCE				0.75 	// FLOAT - chance for anyone to be generated in taverns
#define TAVERN_BANDIT_CHANCE			0.0 	// FLOAT - chance for the someone(s) to be violent drunkards. Enable this (set to 0.25) only if you are up to some brawling, because this may get you in conflict with the townfolk.
#define TAVERN_ENC_QTY					0.5 	// FLOAT - less than all possible characters will be generated if this != 1
#define TAVERNBRAWL_FROMDIALOG			1 		// BOOL - Toggle if you want brawls to mysteriously occur during any dialog in a tavern.
#define TAVERNBRAWL_FISTSONLY			1 		// BOOL - Toggle if you want brawls characters to only have fists when fighting.

// This lets monkeys and indians appear more realistic
#define VC_MUMMY_NOMONEY				1 		// BOOL - do mummies("indians") get money or not. Set to 1 and mummies get 0 for money.
#define VC_MONKEY_NAME				"A rabid"	// STRING - Monkey firstname
#define VC_MONKEY_LNAME				"monkey"	// STRING - Monkey lastname
#define VC_MUMMY_NAME				"Akellani"	// STRING - Native firstname
#define VC_MUMMY_LNAME				"native"	// STRING - Native lastname

// LandEncounters--the original game's random land friends/foes
#define ENC_CHANCE_SCALAR				1.0		// FLOAT - scalar to chance of such encounters as raiders and tavern-officers.

// Treasurechests
#define NO_MINES						0 		// INT - decreases the amount of boobytrapped exploding treasurechests; above 20 (minus your luck skill) there will be none.
#define ONE_TRAP						1		// BOOL - will only explode booby trap once
#define REMEMBER_OPEN					1		// BOOL - once opened, will stay open while still in that location.

// ======================================
// LAND FIGHT MODS:
// ======================================

// The Special Weapon Assembling Kit
#define PRECHARGE						1		// BOOL - Set to 1 and distanceweapons are charged as soon as you equip them. Set to 0 and you must wait the loading period before a newly equipped weapon can be used.
#define STUN_STARS						1		// BOOL - show twinkly stars FX on stun.
#define NO_SPECIALWEAPONED_NPC			1		// BOOL - change to 0 if NPCs shall equip special weapons
#define REPLOSS							1		// INT - Reputation you loose if you hit an unarmed NPC

// Bladedamage
#define BLADEDAMAGE_ENABLED 			1		// BOOL - 1: Blades will suffer damage by use and decrease in quality	
												// 0: Stock PotC: bladequality never changes
												// Note: Setting ENABLE_WEAPONSMOD to 0 will also disable this mod

#define BLADEDAMAGE_BASE				75		// INT - This increases the amount of strokes you can CERTAINLY do without your blade breaking.
#define BLADEDAMAGE_RAND				75		// INT - This increases the amount of strokes you MIGHT BE ABLE to do without your blade breaking.
#define BLADEDAMAGE_DEFAULTBLADE	"bladeX4"	// ITEMID - This is the blade characters use after their blade is broken. Default to "bladeX4" (fists). Set to "blade5" for daggers.
#define BLADEDAMAGE_USEOTHERBLADE		0		// BOOL - If 0, the character will use the DEFAULTBLADE after breaking. If 1, the character will use another blade, if available.
#define BLADEDAMAGE_KEEPBROKENBLADE		0		// BOOL - If 0, enemy will have lost their blade completely after their blade broke. If 1, enemy will be given a broken blade after their blade broke

#define WEAPMOD_GUNDMG					1.5		// FLOAT - scalar to base damage for pistols. 1.0 here means roughly 2/3 stock game damage.
#define MIN_GUNATTACK_HP				5		// INT - The minimum hp you and officers will have left after being shot. Set 0 to disable this mod.

#define USEMAXPOTION_ONKEYPRESS			0 	// BOOL - If 0 (default), when pressing the use potion key the SMALLEST potions will be used first. If 1, the LARGEST potion will be used first.
#define TOUGHNESS_REGEN_MULT			10.0	// FLOAT - Faster HP regen for toughness perk, default 2, Build 13 was 80

// Autoloot and loot dead settings
#define MIN_QUALITY_TO_KEEP				-1		// INT - if weaponsmod is on and loot the dead is on, if the item has a poorer quality than this you will not pick it up.
#define CORPSE_AUTODISAPPEAR			90000	// INT - Time in ms before a LOOTABLE corpse automatically disappears. Set to 0 to disable the automatic disappearing of LOOTABLE corpses.
#define AUTOLOOT_BOARDINGS				0		// BOOL - Default 1: Lootable bodies are not created during boardings, they are auto-looted (if AUTO_LOOT = 1).
												// WARNING: Lootable bodies during boarding can cause serious movement and fighting issues as bodies create obstructions UNTIL manually looted!
												// Set to 0 so lootable bodies will be made during boardings (if CORPSEMODE = 2).
// Ammomod settings
#define AMMOMOD_ABLECAPTAIN				0		// BOOL - Set to 0 to disable your character from being able to fill his own ammo from the ship, requiring a cannoneer and level 6 or higher to do it. Set to 1 to have your character fill his own ammo inventory stocks.



// ======================================
// INTERFACE MODS:
// ======================================

#define GOLD_PER_CLICK      			1000	// INT - Amount of gold that is transferred by one click
#define ALLOWBERTHING_ONLYAT			""		// STRING - Set to "shipyard" to allow ship berthing only at a shipyard.
#define ENABLE_VIDEOS 					1 		// BOOL - Enable/Disable videos in the game.
#define ENABLE_EXTRA_SOUNDS 			1 		// BOOL - Enable/Disable added sound effects.
#define ENABLE_PLAYING_MAINTHEME		1		// BOOL - Enable/Disable mod that randomly makes storyline main theme music playing instead of current one, depending on your progress in the quest.
#define ENABLE_WEAKER_PISTOL_SOUNDS 	0		// BOOL - Enable/Disable   0 = old loud sounds

// ======================================
// LOG NOTIFICATIONS:
// ======================================

#define SHOWHP_PLAYER					0 		// BOOL - Show HP text (i.e. 65/128) for player.
#define SHOWHP_OFFICERS					1 		// BOOL - Show HP text (i.e. 65/128) for officers.
#define SHOWHP_OTHERS					1 		// BOOL - Show HP text (i.e. 65/128) for other characters.
#define ARMOR_ALWAYSSHOW 				1 		// BOOL - Always show log about armor if character taking damage has armor.
#define AUTO_SHOW_NAME_HP				1		// BOOL - Disable the automatic showing of the name of the person you're facing.
#define LOGLOOT							1		// BOOL - Set to 1 to show loot you take from corpses in your log. The L key also toggles this.


// ======================================
// LOG, LOOKS & EFFECTS:
// ======================================

#define SHIPHIT_PARTICLES 				3		// INT - The higher the setting the more effects (choose a lower setting if you get performance problems)
												// 0: Stock PotC (red-orange explosion on hit) 
												// 1: Minimal hit effects (small puffs of gray smoke)
												// 2: Recommended hit effects (puffs and splinters)
												// 3: Excessive hit debris effects (plumes of planks and barrels, water splashes, flashes and smoke - ship explosions extensive)
#define USE_PARTICLES					3		// Sets the amount of effects in the Greenford's haunted Abbey and various other particle situations
												// 0: Off
												// 1: Few effects
												// 2: Medium effects
												// 3: Full effects
#define USE_PARTICLES_CANNONS			1		// Sets the realism of the cannon visual effects.
												// 0: Low - Stock POTC cannon smoke
												// 1: Medium - Realistic cannon smoke
												// 2: High - Extremely Realistic cannon smoke, high-end computer recommended.

// ======================================
// NK's ORIGINAL SETTINGS:
// ======================================

// CUSTOM SAILS -------------------------
#define QTY_LOGOSAILS_WHOLE_WHITE		17		// INT - increase this when you add new whole white sails.
												// The files should be named sails_whole_white_pirate0.tga.tx, sails_whole_white_pirate1.tga.tx, sails_whole_white_pirate2.tga.tx, etc.
												// So if the value above is set, for example, to 15, then the file numbers should be 0 - 14
												// They should be put in RESOURCE/Textures/Ships/Sails
#define QTY_LOGOSAILS_TORN_WHITE		15		// INT - increase this when you add new torn white sails. the files should be named sails_torn_white_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_WHOLE_RED			17		// INT - increase this when you add new whole red sails. the files should be named sails_whole_red_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_TORN_RED			15		// INT - increase this when you add new torn red sails. the files should be named sails_torn_red_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_WHOLE_TAN			17		// INT - increase this when you add new whole tan sails. the files should be named sails_whole_tan_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_TORN_TAN			17		// INT - increase this when you add new torn tan sails. the files should be named sails_torn_tan_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_WHOLE_BLACK		17		// INT - increase this when you add new whole black sails. the files should be named sails_whole_black_pirate0.tga.tx etc.
#define QTY_LOGOSAILS_TORN_BLACK		16		// INT - increase this when you add new torn black sails. the files should be named sails_torn_black_pirate0.tga.tx etc.

// LOCATIONAL ---------------------------
#define OFFICER_TO_MCHR_DIST			10.0 	// FLOAT - was 30, stock
#define OFFICER_TO_TARGET_DIST			10.0 	// FLOAT - was 30, stock

// ARMOR --------------------------------
#define ARMOR_LUCK_SCALAR				0.025	// FLOAT - armor coverage scaled by 1.0 + luck * armor_luck_scalar
#define ARMOR_DEFAULT_FRAC				0.8		// FLOAT - (no description)
#define ARMOR_DEFAULT_STOP				0.01	// FLOAT - (no description)

// TOWN CONSTANTS -----------------------
#define TROOPS_CHANGE_RATIO				0.05	// FLOAT - every day, the troops in a town return towards what the normal amount should be by this * (desired num - current num)
#define CREW_CHANGE_RATIO				0.1		// FLOAT - same but for crew
#define GOLD_CHANGE_RATIO				0.025	// FLOAT - same but for gold
#define DEFAULT_TOWN_POP				750		// INT - default population for a town (if the town's pop is not recorded)
#define MAX_POP							5000	// INT - max pop a town can have
#define TOWN_TROOPS_SCALAR				0.4		// FLOAT - pop * this = normal number of troops
#define TOWN_CREW_SCALAR				0.25	// FLOAT - pop * this = normal crew quantity available for hire
#define STORE_MINSIZE					1500	// INT - min size for a store to be considered large. Used currently only to tell what class of ships a shipwright can sell.
#define TOWN_GOLD_SCALAR				10000	// INT - pop * this = normal gold supply
#define TOWN_GOLD_SACK_SCALAR 			0.2		// FLOAT - base amount of gold you get on sacking a town = this * town's gold
#define MIN_FOOD_SCALAR					0.75	// FLOAT - if town wheat qty < this * pop, starvation starts (pop decreases)
#define MAX_FOOD_SCALAR					1.5		// FLOAT - wheat qty capped to this * pop or thereabouts
#define GROW_FOOD_SCALAR				1.0		// FLOAT - if town wheat qty > this * pop, expansion starts (pop increases)
#define STARVE_SCALAR					1.0		// FLOAT - starvation effects scaled by this
#define POP_CH							5		// INT - base unit of pop change
#define SACK_TROOPS_DECREASE			0.5		// FLOAT - troops decrease to this * original number after sack. Note this does _not_ include the number lost in the fighting!
#define SACK_TOWN_DECREASE				0.6		// FLOAT - pop decreases to this * original pop

// Fort battles
#define TROOPS_MULT_ON_BOARD			2		// INT - more troops near fort than can be shot at; also wounded who revive in time. So this multiplier is applied after sea combat but before assaulting ("boarding") the fort.
#define TOWN_MILITIA_MULT				0.2		// FLOAT - portion of 'town' population that joins with troops on assaulting the fort

// Trade Goods
#define GQTY_VARIANCE					0.3		// FLOAT - random variance in base good supply; supply * 1.0 +- this
#define GQTY_MAX_SCALAR					3.0		// FLOAT - cap for goods when restocking stores (this * normal supply = max)
#define GQTY_MIN_SCALAR					0.1		// FLOAT - floor, ditto
#define GQTY_LOW_SCALAR					0.5		// FLOAT - various steps in the good qty determination
#define GQTY_SEMILOW_SCALAR				0.75	// FLOAT - (no description)
#define GQTY_SEMIHIGH_SCALAR			1.3333	// FLOAT - (no description)
#define GQTY_HIGH_SCALAR				2.0		// FLOAT - (no description)
#define GQTY_PRICECHG_POW 				0.5		// FLOAT - power to the change in good price based on qty vs. townsize. So if this is 0.5, the qtymodifier to price is qtymodify^0.5. A way to change how important qty vs. townsize is to goodprice.
#define GQTY_CONTRABAND_PRICE_SCALAR	0.8		// FLOAT - price scalar for contraband good prices (in stores!) because the qty is normally very low leading to massive prices.
#define GQTY_PRICE_MAXSCL				5.0	// FLOAT - max and min scalars to price based on qty vs. townsize
#define GQTY_PRICE_MINSCL				0.2		// FLOAT - (no description)
#define GOODS_PRICE_SCALAR				5		// FLOAT - Adjust ALL the prices of goods in the game times this amount

#define TT_NORMAL_SCALE					1.0		// FLOAT - scalar to base good qty when trade type is normal
#define TT_EXPORT_SCALE					1.5		// FLOAT - ditto for export
#define TT_IMPORT_SCALE					0.5		// FLOAT - ditto for import
#define TT_CONTRABAND_SCALE				0.1		// FLOAT - ditto for contraband
#define TT_AMMO_SCALE					0.2		// FLOAT - ditto for ammo

#define TRADEQUEST_DIST_SCL				0.02	// FLOAT - distance * weight * this = distance component
#define TRADEQUEST_COMMISSION			0.1		// FLOAT - get this portion of profit

// DAILY UPDATE CONSTANTS ---------------

// Land wealth
#define LAND_PROFIT_SCALAR				5		// INT - base scalar to land profit
#define LAND_PROFIT_POW					1.05	// FLOAT - exponential scalar

// Prisoners
#define RANSOM_INC						1.01	// FLOAT - ransom is multiplied by this each day until prisoner ransomed or escapes.
#define ESCAPE_CHANCE					0.02	// FLOAT - chance = this * (1.0 + prisoner_luck /10) / (1.0 + your_luck/10)

// Loot
#define AVG_CREW_SHARE					400		// INT - note this is multipled by sqrt(pchar level)
#define LEFTOVER_SHARE					0.1		// FLOAT - amount left out of dividing the plunder to be starter fund for next voyage = total money * this
#define CSR_SCALE						45		// INT - scalar for Crew Share Ratio for morale
#define SALARY_SCALE					0.6		// FLOAT - default-used scalar (instead of CSR) when in salary mode
#define COMP_MULT						6.0		// FLOAT - multiplier to an officer's share if he/she serves as fellow captain
#define OFF_DIV							48.0	// FLOAT - must be above x8! Above * comp, plus 1 * each off, over this, = part of loot given to them.
#define FAME_CSR_SCALE					0.5		// FLOAT - scalar to CSR when calcing fame
#define FAME_CSR_MIN					0.1		// FLOAT - min CSR for fame calc
#define FAME_CSR_MAX					5.0		// FLOAT - max CSR for fame calc
#define FAME_PIRNATION_CSR_BASE			0.75	// FLOAT - NK added 04-09-06 so if nation == pirate for fame query, csr counts. fame *= base + CSR*Scalar
#define FAME_PIRNATION_CSR_SCALAR		0.25	// FLOAT - scalar to CSR
#define FAME_SCALAR						1.0		// FLOAT - base scalar for fame

#define MORALE_MAX_RAISE				70		// INT - max value morale can be raised to by bribing the crew

#define OFF_PRICE_SCALAR				0.2		// FLOAT - scalar to officerprice for use as monthly salary. Stock POTC: 0.2
#define COMP_PRICE_SCALAR				0.5		// FLOAT - ditto, but for companions. Stock POTC: 0.5
#define BASE_CREW_PAY					12		// INT - Base salary gold paid to each crew member, not adjusted for skills, perks & difficulty.  POTC Stock: 12
#define PASSENGER_PRICE_SCALAR			0.1		// FLOAT - scalar to officerprice used as monthly salary for unassigned officers. Stock POTC: 0

// Rum (note 2 is normal and 1 is double)
#define RUM2_SCALE						1.1		// FLOAT - ratio nominal morale is scaled by when rum rations are normal
#define RUM_SCALE						1.25	// FLOAT - ditto but for double rations
#define RUM0_SCALE						0.9		// FLOAT - ditto but for if out of rum
#define RUMDEC							15		// INT - amount morale decreases on a "bad" day when on double rum rations (drunken brawl)
#define RUM_BASECH						10		// INT - base chance for a decrease when on double rations (it's a 1-in-[this+modifiers] chance)

// Food (note 1 is normal and 2 is half)
#define FOOD_PER_CREW					0.01	// FLOAT - qty of wheat eaten per day per crewmember
#define FOOD2_SCALE						0.75	// FLOAT - ratio nominal morale is scaled by when on half rations of food
#define FOOD0_SCALE						0.25	// FLOAT - base scalar to what morale is scaled to when out of food (it's a complex formula)
#define FOOD_CREWDIEOFF					0.1		// FLOAT - ratio of crew who die off each day.

// Expedition length
#define NORMAL_EXP_LENGTH				180		// INT - nominal length of an expedition
#define EXP_LENGTH_START_FRAC			0.5		// FLOAT - portion of above when morale is _increased_ above nominal by exp length
#define REFIT_TIME						60		// INT - number of days to refit for next expedition
#define CHANGE_MULT						0.25	// FLOAT - multiplier to how much actual morale is changed each day to be nearer nominal morale. Bigger number here, the closer actual morale "tracks" nominal.

// Wounded crew
#define HEALED_PER_DAY					1		// INT - number of wounded crewmembers healed per day without doctor and medicines
#define HEALED_WITH_MEDS				5		// INT - number of wounded crewmembers healed per day if medicines are present
#define KILLED_PER_DAY					16		// INT - number of wounded crewmembers that die per day without doctor and medicines


// ======================================
// Testing toggles
// ======================================
#define RANDOM_LOCS_TOGGLE				0
#define DISARM_MODE						0
#define VISIBLE_LOCATORS				0
#define WITH_BRIGHT_COLOURS				0		// VISIBLE_LOCATORS must be on to change this
#define FREE_CAMERA						0
#define SIDESTEP_ENABLED				0		// BOOL - 0 (default) = off, 1 = on: you can use sidestep during the game (NOTE: No collision detection!)
#define ENABLE_CHEATMODE				0		// Cheats can be triggered with numpad buttons
