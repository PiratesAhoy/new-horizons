/*// ===============================================| MAXIMUS |===============================================
Finally I made an interface for change all BUILD-settings in options-interface. All #defines were changed to variables
for making them changeable

Description for each option must be added into RESOURCE\INI\TEXT\*needed language*\SettingsDescribe.txt
*name_of_the_option*{translated text} (for example: auto_skill_system{Experience Gain})
setting*name_of_the_option*1 (for example: settingauto_skill_system1)
{
Describe for lowest value
}
setting*name_of_the_option*2
{
Describe for higher value
}
setting*name_of_the_option*3
{
#Describe for whole option
}
*/// ===============================================| MAXIMUS |===============================================

// ======================================
// STARTING OPTIONS FOR A NEW GAME:
// ======================================

bool AUTO_SKILL_SYSTEM = true;
	// 1: Skills will be distributed automatically, depending on player-actions
	// 0: Player must distribute character's skills manually (Stock PotC)

// ======================================
// GENERAL MODS:
// ======================================

int DEATHRATE = 40;
	// Chance of dying(= game over) after shipwrecks and lost fights
	// Choose a value between 1(certain survival) and 130(certain death)
	// After survival you will be down and out, so it is a new challenge and no cheat!

bool ENABLE_WEAPONSMOD = true;
	// 1: Weapons have different quality grades: from "Badly worn" to "Excellent"
	// 0: Off, stock PotC
	
bool SWEDEN_ALLOWED = 0;
	// 1: Sweden shows up in game
	// 0: Sweden does not show up in game
	
bool PERSUASION_TAGS = 0;
	// 1: [Persuasion Tags] show up in dialogue when a skill check/random roll happens
	// 0: [Persuasion Tags] does not show up in dialogues


// ======================================
// WORLDMAP & SHIP ENCOUNTERS:
// ======================================

int WDMAP_SHIP_SHOW_MODE = 0;
	// Determines what ships are shown on the worldmap and how
	// 0: Stock PotC, all ships shown with national sail colours
	// 1: All ships visible, but nationality for all but pirate hidden
	// 2: No nations shown
	// 3: No ships at all shown

int NATIONAL_PAINT_SCHEMES = 1;
	// Determines if the paint schemes of ships are dependent on their nationality
	// 1: Yes
	// 0: No

int SAILHO_INFOLEVEL = 2;
	// Amount of info in the "sailho" screenmessage on the map
	// 0: Reports only "some ship"
	// 1: Adds ship group type
	// 2: Adds nationality

bool RELATION_IGNORE_FRIENDLY = 1;
	// Determines whether forts and ships will record you if you are friendly
	// 0: Forts and ships will remember you even if you are not hostile
	// 1: Forts and ships will only remember you if you are hostile


// ======================================
// SAILING & SHIP BATTLES:
// ======================================

bool VISIT_DECK = true;
	// 0: Stock PotC: When anchoring, you go directly to shore; also you go directly to sea when leaving port or bay.
	// 1: When anchoring, you go to your ship's deck. From there you can go to shore in the same way as in the tutorial.
	//    When leaving land you'll also go to your ship's deck, unless you select 'Sea' command.


// ======================================
// CANNONS
// ======================================

bool CANNONPOWDER_MOD = true;
	// 0: Stock PotC: no gunpowder required for ship guns
	// 1: You must have gunpowder in your CARGO HOLD to charge SHIPGUNS
	// (Not to be confused with the PERSONAL ITEM gunpowder for PISTOLS)


// ======================================
// SHIP MANAGEMENT, REPAIRS, TRADING:
// ======================================

bool FOOD_ON = true;
	// 1: The crew requires food (wheat) and drink (rum) to stay alive and happy
	// 0: Off, stock PotC

bool SY_RPG_STYLE = true;
	// 1: Shipyards will not sell outclassed ships to low level players
	// 0: Stock PotC: all shiptypes may be sold

bool REALISTIC_SHIP_PURCHASE = true;
	// 1: No ships larger than frigates can be purchased but need to be captured instead
	//    This because ships of the line, etc, were never sold, especially not to privateers.
	// 0: No additional limits on buying ships
	// You can tweak this mod to your liking in InternalSettings.h

bool IT_RPG_STYLE = true;
	// 1: Traders will not have items that are too good for the player
	// 0: Traders will have items based on their own random level. Players can buy VERY good items at the beginning of the game

int SALARY_MULTIPLIER = 3;
	// Multiplier for Crew and Officer salary. 1 is Stock POTC. 4 and above makes a more interesting and challenging game.

// ======================================
// LAND FIGHT MODS:
// ======================================

bool ENABLE_AMMOMOD = true;
	// 0: Stock PotC: no ammunition required for handheld guns
	// 1: You must have gunpowder and the right type of bullets in your PERSONAL INVENTORY to charge HANDHELD guns
	// (Not to be confused with the CARGO HOLD gunpowder for SHIPGUNS)

int CORPSEMODE = 4;
	// 0: Stock PotC: no bodies laying around, no looting ability
	// 1: Corpses will persist, but will not be manually lootable
	// 2: Corpse persists and can be manually looted of items
	// 	WARNING: Until a body is looted, the body will create an impassible obstacle!
	// 4: Corpses fall to the ground properly, don't obstruct walking and can be looted manually

bool AUTOLOOT_ON = true;
	// 0: No automatic looting of killed characters
	// 1: Blade/Gun/Money of killed enemies is automatically moved into your inventory
	// (This can be combined with CORPSEMODE 2 as any leftover items not autolooted will be left on the corpse)


// ======================================
// LAND EXPLORATION, LOCATIONS:
// ======================================

float DIALOG_CAMERA = 0.0;
	// 0.1 - 1.0: Camera will be moved to the side during dialog, for full scene viewing
	// 0.0: Stock PotC dialogs

bool ENABLE_BROTHEL = false;
	// 0: Stock PotC: no brothel in QC
	// 1: Brothel location opened; a bit explicit, but in WORDS only

bool ENABLE_BUILDINGSET = true;
	// 0: New towns have the same look as the stock PotC locations
	// 1: "additional" buildings in some new locations

int NO_THEFT = 0;
	// You can now pick pockets. But this is risky, and other thieves may pick YOUR pocket too.
	// 0 - 60 : The higher this value the safer you are from pickpockets
	// Above 30 nobody picks YOUR pocket, above 60 you yourself get no chance to steal

int LOCK_OPEN = 0;
 	// 0- 70: the higher this value the higher your chance of picking the locks of treasurechests
	// Above 66 chests always open, above 33 you won't hurt yourself anymore ;-)

// ======================================
// LOG, LOOKS & EFFECTS:
// ======================================

bool LOC_CAMERA = false;
	// 0: Near doors camera view will stay locked to view FROM player
	// 1: Stock PotC: Near doors camera will swerve and focus ON the playercharacter

int ONSEA_COMPASS = 2;
	// 0: Stock PotC: Compass rose is blue
	// 1: Orange transparent compass
	// 2: Historical brass compass

int DEFAULT_SAILS = 1;
	// 0: Stock PotC sails, with emblems
	// 1: Build Default: All ships 'Weathered' sails, no emblems except pure white emblems where historically accurate
	// 2: All ships pure white sails, no emblems except where historically accurate
	// 3: All ships pure white sails, with emblems

int PIRATES_BLACK_SAILS = 0;
	// 0: Pirates use the same sails as DEFAULT_SAILS (set above)
	// 1: Pirates use plain black sails
	// 2: Pirates use emblemed black sails
