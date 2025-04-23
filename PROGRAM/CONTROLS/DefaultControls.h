/*
++++++++++++++ GAME CONTROLS DEFAULTS ++++++++++++++
In this list you can customize the default key settings for all controls in the game.

!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!
This is a program file. Changes to the format of the code will mess up the game. 
Please follow these rules when editing settings:
- Change ONLY the values after the CAPITAL_SETTING names.
- Use ONLY the values from the "LIST OF ALLOWED KEYS" (at bottom of this file). 
- NEVER remove a line starting with "#define".
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

// ======================================
// Global and General
// ======================================

#define CTL_1X3X 					"KEY_R"
#define CTL_10X30X 					"KEY_G"
#define CTL_QUICKSAVE 				"VK_F5" // (not changable ingame)
#define CTL_QUICKLOAD 				"VK_F6" // (not changable ingame)

// Ammo equip keys (not changable ingame)
#define CTL_AMMO_EQUIP_1 			"KEY_1" // Change to Balls (on sea) - Equip best blade   (on land)
#define CTL_AMMO_EQUIP_2 			"KEY_2" // Change to Grape (on sea) - Equip best gun     (on land)
#define CTL_AMMO_EQUIP_3 			"KEY_3" // Change to Chain (on sea) - Equip cobble stone (on land)
#define CTL_AMMO_EQUIP_4 			"KEY_4" // Change to Bombs (on sea) - Equip sand bag     (on land)
#define CTL_AMMO_EQUIP_5 			"KEY_5" // Equip ether bottle
#define CTL_AMMO_EQUIP_6 			"KEY_6" // Equip thief's knife
#define CTL_AMMO_EQUIP_7 			"KEY_7" // Equip poison throwing knife
#define CTL_AMMO_EQUIP_8 			"KEY_8" // Equip stink pot
#define CTL_AMMO_EQUIP_9 			"KEY_9" // Equip grenade
#define CTL_AMMO_EQUIP_0 			"KEY_0" // Equip fists

// Special modders tool keys
#define CTL_SCREEN_FULL_LOGS_TOGGLE "KEY_L"
#define CTL_ARCHIPELAGO_MAP    		"KEY_M"
#define CTL_NPC_INFO_TOGGLE 		"KEY_O"
#define CTL_DEBUG_MENU              "VK_F10"
#define CTL_REINITIALIZE_GAME 		"VK_F11" // (not changable ingame)
#define CTL_EXECUTE_CONSOLE 		"VK_F12" // (not changable ingame)


// ======================================
// Character On Land
// ======================================

#define CTL_LAND_WALK_FORWARD 		"KEY_W"
#define CTL_LAND_WALK_BACKWARD 		"KEY_S"
#define CTL_LAND_SIDESTEP_LEFT 		"KEY_A"
#define CTL_LAND_SIDESTEP_RIGHT 	"KEY_D"
#define CTL_LAND_RUN 				"VK_SHIFT"
#define CTL_ALWAYS_RUN_TOGGLE 		"KEY_K"

#define CTL_LAND_ACTION 			"VK_SPACE" // Enter door, talk to character
#define CTL_LAND_ACTION_ALT   		"VK_SPACE" // KK // Aconcagua: set to SPACE as VK_LBUTTON used differently by others and me
#define CTL_LAND_AUTO_EQUIP 		"KEY_F"
#define CTL_LAND_USE_POTION 		"KEY_C"
#define CTL_LOOT_CORPSE 			"KEY_T"

#define CTL_FIGHT_MODE 				"KEY_E"

#define CTL_FIGHT_ATTACK_FAST 		"VK_LBUTTON"
#define CTL_FIGHT_ATTACK_BREAK		"VK_MBUTTON"
#define CTL_FIGHT_ATTACK_FORCE		"VK_RBUTTON"
//#define CTL_FIGHT_ALT_ATTACK_BASE	"KEY_U"

#define CTL_FIGHT_ATTACK_CHOSE_B	"VK_SHIFT"

#define CTL_FIGHT_BLOCK 			"VK_SPACE"
#define CTL_FIGHT_DODGE 			"KEY_Z"
#define CTL_FIGHT_FIRE_GUN			"KEY_Q"
#define CTL_FIGHT_RUSHMODE 			"KEY_H"

#define CTL_LAND_VIEW_SWITCH 		"VK_TAB" // Change between 1st and 3rd person view
#define CTL_LAND_OPEN_ICONMENU 		"VK_RETURN" // Open fast travel menu (lower left)
#define CTL_LAND_HOT_ACTION 		"VK_F3" // Perform quick action icon (upper left)


// ======================================
// Ship Control
// ======================================

#define CTL_SHIP_VIEW_FORWARD 		"VK_LBUTTON"
#define CTL_SHIP_VIEW_BACKWARD 		"VK_RBUTTON"
#define CTL_DECK_VIEW_FORWARD 		"VK_LBUTTON"
#define CTL_DECK_VIEW_BACKWARD 		"VK_RBUTTON"
#define CTL_SHIP_VIEW_SWITCH 		"VK_TAB" // Change between Deck and Ship view

#define CTL_SHIP_TURN_LEFT 			"KEY_A"
#define CTL_SHIP_TURN_RIGHT 		"KEY_D"
#define CTL_SHIP_SAIL_RAISE 		"KEY_W"
#define CTL_SHIP_SAIL_STRIKE 		"KEY_S"
#define CTL_SHIP_POWER_UP 			"VK_ADD"
#define CTL_SHIP_POWER_DOWN	 		"VK_SUBTRACT"
#define CTL_SHIP_POWER_ZERO			"VK_MULTIPLY"

#define CTL_SHIP_FIRE_AUTO_CANNON 	"VK_SPACE"
#define CTL_DECK_FIRE_AIMED_CANNON 	"KEY_V"

#define CTL_SHIP_FIREDRILL			"KEY_C"
#define CTL_DECK_SPYGLASS			"VK_CONTROL"

#define CTL_MINIMAP_ZOOM_IN			"KEY_E"
#define CTL_MINIMAP_ZOOM_OUT		"KEY_F"

#define CTL_SHIP_OPEN_ICONMENU 		"VK_RETURN" // Open commands menu (lower left)
#define CTL_SHIP_HOT_ACTION 		"VK_F3" // Perform quick command icon (upper left)


// ======================================
// World Map Control
// ======================================

#define CTL_MAP_SHIP_TURN_LEFT 		"KEY_A"
#define CTL_MAP_SHIP_TURN_RIGHT 	"KEY_D"
#define CTL_MAP_SAIL_RAISE 			"KEY_W"
#define CTL_MAP_SAIL_STRIKE 		"KEY_S"

#define CTL_MAP_VIEW_SWITCH 		"VK_TAB" // Change between free roam or stuck on ship view
#define CTL_MAP_VIEW_ROTATE			"VK_CONTROL" // Hold with mouse movement to rotate free roam view
#define CTL_MAP_ZOOM_IN 			"VK_LBUTTON"
#define CTL_MAP_ZOOM_OUT 			"VK_RBUTTON"

#define CTL_MAP_GOTO_SAILING 		"VK_SPACE"
#define CTL_MAP_SKIP_ENCOUNTER 		"KEY_B"


// ======================================
// Interfaces and Dialogs (not changable ingame)
// ======================================

#define CTL_ACTIVATE_MAINMENU 		"VK_F1" // Goto main menu (New Game, Save Game, Quit, etc)
#define CTL_ACTIVATE_INTERFACE 		"VK_F2" // Goto character interfaces (Inventory, Ship, Relations etc)

#define CTL_INTERFACE_NAV_SELECT 	"VK_SPACE"
#define CTL_INTERFACE_NAV_CANCEL 	"VK_ESCAPE"
#define CTL_INTERFACE_NAV_UP 		"VK_UP"
#define CTL_INTERFACE_NAV_DOWN 		"VK_DOWN"
#define CTL_INTERFACE_NAV_LEFT 		"VK_LEFT"
#define CTL_INTERFACE_NAV_RIGHT 	"VK_RIGHT"

#define CTL_CMD_INTERFACE_SELECT 	"VK_RETURN" // Command interface controls (lower left corner icons)
#define CTL_CMD_INTERFACE_CANCEL 	"VK_ESCAPE"
#define CTL_CMD_INTERFACE_LEFT 		"VK_LEFT"
#define CTL_CMD_INTERFACE_RIGHT 	"VK_RIGHT"
#define CTL_CMD_INTERFACE_UP 		"VK_UP"
#define CTL_CMD_INTERFACE_DOWN 		"VK_DOWN"

#define CTL_DIALOG_SELECT 			"VK_SPACE"
#define CTL_DIALOG_SELECT1 			"VK_RETURN"
#define CTL_DIALOG_SELECT_ALT		"VK_LBUTTON" // KK
#define CTL_DIALOG_CANCEL 			"VK_ESCAPE"
#define CTL_DIALOG_CHOICE_UP 		"KEY_W"
#define CTL_DIALOG_CHOICE_UP_ALT	"VK_MBUTTON" // KK
#define CTL_DIALOG_CHOICE_DOWN 		"KEY_S"
#define CTL_DIALOG_CHOICE_DOWN_ALT	"VK_RBUTTON" // KK
#define CTL_DIALOG_SCROLL_UP 		"VK_PRIOR"
#define CTL_DIALOG_SCROLL_DOWN 		"VK_NEXT"


// ======================================
// Cheats (not changable ingame)
// ======================================

#define CTL_CHEAT_GODMODE			"VK_NUMPAD0"
#define CTL_CHEAT_SCROLL_LEFT 		"VK_NUMPAD1"
#define CTL_CHEAT_SCROLL_MAIN 		"VK_NUMPAD2"
#define CTL_CHEAT_SCROLL_RIGHT 		"VK_NUMPAD3"
#define CTL_CHEAT_PLAYERLVLUP 		"VK_NUMPAD4"
#define CTL_CHEAT_FAKELVLUP 		"VK_NUMPAD5"
#define CTL_CHEAT_MOREGOLD 			"VK_NUMPAD6"
#define CTL_CHEAT_RAISEREP 			"VK_NUMPAD7"
#define CTL_CHEAT_WORLDMAP 			"VK_NUMPAD8"
#define CTL_CHEAT_RAPIDRAID 		"VK_NUMPAD9"


// ======================================
// Free Camera movement (not changable ingame)
// ======================================

#define CTL_FREE_CAM_FORWARD		"VK_LBUTTON"
#define CTL_FREE_CAM_BACKWARD		"VK_RBUTTON"

// Development tools
#define CTL_DEV_LIGHTER_TOGGLE		"KEY_L"


// ======================================
// LIST OF ALLOWED KEYS
// ======================================
/*
// Mouse:
	VK_LBUTTON
	VK_RBUTTON
	VK_MBUTTON	//MAXIMUS: picture added into pc_keyboard

// Basic keys:
	KEY_0 -to- KEY_9
	KEY_A -to- KEY_Z

// Numpad keys:
	VK_NUMPAD0 -to- VK_NUMPAD9
	VK_MULTIPLY
	VK_ADD
	VK_SEPARATOR
	VK_SUBTRACT
	VK_DECIMAL
	VK_DIVIDE

// Extended keys:
	VK_BACK
	VK_TAB
	VK_RETURN
	VK_ALT
	VK_SHIFT
	VK_CONTROL
	VK_ESCAPE
	VK_SPACE
	VK_PRIOR
	VK_NEXT
	VK_LEFT
	VK_UP
	VK_RIGHT
	VK_DOWN
	VK_PAUSE

// F-keys: (only a few are allowed)
	VK_F1
	VK_F2
	VK_F3
	VK_F4
	VK_F11	(has improper graphic, but works)
	VK_F12	(has improper graphic, but works)

*/
