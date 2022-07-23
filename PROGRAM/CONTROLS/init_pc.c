/*
	TIH Nov17'06
	All the default key settings themselves are now located in the file "BuildDefaultControls.h".
	Edit that file with your own defaults so you can easily change them in any future updates.
	New keys added below, should be added to that file unless its internal and unadjustable.
*/

void ExternControlsInit(bool bFirst)
{
	if(bFirst)
	{
		ExternInitKeyCodes();
		CI_CreateAndSetControls( "", "ICancel", CI_GetKeyCode(CTL_INTERFACE_NAV_CANCEL), 0, false );
		CI_CreateAndSetControls( "", "IAction", CI_GetKeyCode(CTL_INTERFACE_NAV_SELECT), 0, false );
		return;
	}

	ExternInitKeyCodes();




// -------------------------------------------------------------------------------------------------------------------
// Camera / Mouse movement

	// character camera
	CI_CreateAndSetControls( "", "ChrCamTurnV", 257, 0, false );
	SetControlForInverting("ChrCamTurnV",false);
	CI_CreateAndSetControls( "", "ChrCamTurnH", 256, 0, false );
	CI_CreateAndSetControls( "", "Turn V", 257, INVERSE_CONTROL, false );
	SetControlForInverting("Turn V",true);
	CI_CreateAndSetControls( "", "Turn H", 256, 0, false );
	CI_CreateAndSetControls( "", "ChrTurnH", 256, 0, false );

	// ship follow camera
	CI_CreateAndSetControls( "", "ShipCamera_Turn_V", 257, INVERSE_CONTROL, false );
	SetControlForInverting("ShipCamera_Turn_V",true);
	CI_CreateAndSetControls( "", "ShipCamera_Turn_H", 256, 0, false );

	// deck camera
	CI_CreateAndSetControls( "", "DeckCamera_Turn_V", 257, 0, false );
	SetControlForInverting("DeckCamera_Turn_V",false);
	CI_CreateAndSetControls( "", "DeckCamera_Turn_H", 256, 0, false );

	// free camera
	CI_CreateAndSetControls( "", "FreeCamera_Turn_V", 257, INVERSE_CONTROL, false );
	SetControlForInverting("FreeCamera_Turn_V",true);
	CI_CreateAndSetControls( "", "FreeCamera_Turn_H", 256, 0, false );
	CI_CreateAndSetControls( "", "FreeCamera_Forward", CI_GetKeyCode(CTL_FREE_CAM_FORWARD), 0, false );
	CI_CreateAndSetControls( "", "FreeCamera_Backward", CI_GetKeyCode(CTL_FREE_CAM_BACKWARD), 0, false );




// -------------------------------------------------------------------------------------------------------------------
// Character

	CI_CreateAndSetControls( "PrimaryLand", "ChrForward", CI_GetKeyCode(CTL_LAND_WALK_FORWARD), 0, true );
	MapControlToGroup("ChrForward","FightModeControls");
	MapControlToGroup("ChrForward","BattleInterfaceControls");

	CI_CreateAndSetControls( "PrimaryLand", "ChrBackward", CI_GetKeyCode(CTL_LAND_WALK_BACKWARD), 0, true );
	MapControlToGroup("ChrBackward","FightModeControls");
	MapControlToGroup("ChrBackward","BattleInterfaceControls");

	CI_CreateAndSetControls( "PrimaryLand", "ChrStrafeLeft", CI_GetKeyCode(CTL_LAND_SIDESTEP_LEFT), 0, true );
	MapControlToGroup("ChrStrafeLeft", "FightModeControls");
	CI_CreateAndSetControls( "PrimaryLand", "ChrStrafeRight", CI_GetKeyCode(CTL_LAND_SIDESTEP_RIGHT), 0, true );
	MapControlToGroup("ChrStrafeRight", "FightModeControls");

	CI_CreateAndSetControls( "PrimaryLand", "ChrRun", CI_GetKeyCode(CTL_LAND_RUN), 0, true );
	MapControlToGroup("ChrRun","FightModeControls");
	//MapControlToGroup("ChrRun","BattleInterfaceControls");// TIH not needed Aug24'06


	CI_CreateAndSetControls( "PrimaryLand", "ChrAction", CI_GetKeyCode(CTL_LAND_ACTION), 0, true );
	CI_CreateAndSetControls( "PrimaryLand", "ChrActionAlt", CI_GetKeyCode(CTL_LAND_ACTION_ALT), 0, true ); // KK

	CI_CreateAndSetControls( "PrimaryLand", "Equip", CI_GetKeyCode(CTL_LAND_AUTO_EQUIP), 0, true );	// PB: Equip button
	MapControlToGroup("Equip", "FightModeControls");


	CI_CreateAndSetControls( "PrimaryLand", "ChrFightMode", CI_GetKeyCode(CTL_FIGHT_MODE), 0, true );
	MapControlToGroup("ChrFightMode","FightModeControls");
	MapControlToGroup("ChrFightMode","BattleInterfaceControls");

	CI_CreateAndSetControls( "FightModeControls", "ChrAttackFast", CI_GetKeyCode(CTL_FIGHT_ATTACK), 0, true );

	CI_CreateAndSetControls( "FightModeControls", "ChrBlock", CI_GetKeyCode(CTL_FIGHT_BLOCK), 0, true );
	MapControlToGroup("ChrBlock","BattleInterfaceControls");

	CI_CreateAndSetControls( "FightModeControls", "ChrRecoil", CI_GetKeyCode(CTL_FIGHT_DODGE), 0, true );

	CI_CreateAndSetControls( "FightModeControls", "ChrFire", CI_GetKeyCode(CTL_FIGHT_FIRE_GUN), 0, true );
	//MapControlToGroup("ChrFire","BattleInterfaceControls");// TIH not needed Aug24'06

	CI_CreateAndSetControls( "PrimaryLand", "BOAL_UsePotion", CI_GetKeyCode(CTL_LAND_USE_POTION), 0, true );
	MapControlToGroup("BOAL_UsePotion", "FightModeControls");

	// Scheffnow rush mod
	CI_CreateAndSetControls( "PrimaryLand", "SCHEFFNOW_RUSH", CI_GetKeyCode(CTL_FIGHT_RUSHMODE), 0, true );
	MapControlToGroup("SCHEFFNOW_RUSH", "FightModeControls");

	CI_CreateAndSetControls( "PrimaryLand", "Rapid_Raid", CI_GetKeyCode(CTL_CHEAT_RAPIDRAID), 0, true );// El Rapido Rapid Raid
	MapControlToGroup("Rapid_Raid", "FightModeControls");												// El Rapido Rapid Raid

	CI_CreateAndSetControls( "PrimaryLand", "ChrCamCameraSwitch", CI_GetKeyCode(CTL_LAND_VIEW_SWITCH), 0, true );
	MapControlToGroup("ChrCamCameraSwitch","FightModeControls");
	MapControlToGroup("ChrCamCameraSwitch","BattleInterfaceControls");

	CI_CreateAndSetControls( "PrimaryLand", "LICommandsActivate", CI_GetKeyCode(CTL_LAND_OPEN_ICONMENU), 0, true );
	MapControlToGroup("LICommandsActivate","FightModeControls");

	CI_CreateAndSetControls( "PrimaryLand", "BIFastCommand", CI_GetKeyCode(CTL_LAND_HOT_ACTION), 0, true );
	MapControlToGroup("BIFastCommand","FightModeControls");


// -------------------------------------------------------------------------------------------------------------------
// Ship

	CI_CreateAndSetControls( "Sailing3Pers", "ShipCamera_Forward", CI_GetKeyCode(CTL_SHIP_VIEW_FORWARD), 0, true );
	CI_CreateAndSetControls( "Sailing3Pers", "ShipCamera_Backward", CI_GetKeyCode(CTL_SHIP_VIEW_BACKWARD), 0, true );

	CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Forward", CI_GetKeyCode(CTL_DECK_VIEW_FORWARD), 0, true );
	CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Backward", CI_GetKeyCode(CTL_DECK_VIEW_BACKWARD), 0, true );

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_TurnLeft", CI_GetKeyCode(CTL_SHIP_TURN_LEFT), 0, true );
	MapControlToGroup("Ship_TurnLeft","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_TurnRight", CI_GetKeyCode(CTL_SHIP_TURN_RIGHT), 0, true );
	MapControlToGroup("Ship_TurnRight","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_RaiseSails", CI_GetKeyCode(CTL_SHIP_SAIL_RAISE), 0, true ); // KK
	MapControlToGroup("Ship_RaiseSails","Sailing1Pers"); // KK

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_LowerSails", CI_GetKeyCode(CTL_SHIP_SAIL_STRIKE), 0, true ); // KK
	MapControlToGroup("Ship_LowerSails","Sailing1Pers"); // KK

// PB: Steam Ships -->
	CI_CreateAndSetControls( "Sailing3Pers", "Ship_PowerUp", CI_GetKeyCode(CTL_SHIP_POWER_UP), 0, true );
	MapControlToGroup("Ship_PowerUp","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_PowerDown", CI_GetKeyCode(CTL_SHIP_POWER_DOWN), 0, true );
	MapControlToGroup("Ship_PowerDown","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_PowerZero", CI_GetKeyCode(CTL_SHIP_POWER_ZERO), 0, true );
	MapControlToGroup("Ship_PowerZero","Sailing1Pers");
// PB: Steam Ships <--

	CI_CreateAndSetControls( "Sailing3Pers", "Ship_Fire", CI_GetKeyCode(CTL_SHIP_FIRE_AUTO_CANNON), 0, true );
	MapControlToGroup("Ship_Fire","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing1Pers", "Aimed_Ship_Fire", CI_GetKeyCode(CTL_DECK_FIRE_AIMED_CANNON), 0, true ); // Aimed ship fire mod by LDH
	//MapControlToGroup("Aimed_Ship_Fire","Sailing1Pers");// TIH not needed Nov16'06

	if(FIREDAMAGE > 1) // Firedrill mod by CCC
	{
		CI_CreateAndSetControls( "Sailing1Pers", "TIH_FireDrill", CI_GetKeyCode(CTL_SHIP_FIREDRILL), 0, true );
		//MapControlToGroup("TIH_FireDrill","Sailing1Pers");// TIH not needed Aug24'06
		MapControlToGroup("TIH_FireDrill","Sailing3Pers");
	}

	CI_CreateAndSetControls( "Sailing1Pers", "TelescopeIn", CI_GetKeyCode(CTL_DECK_SPYGLASS), 0, true ); 				// set fix option_screen.c
	CI_CreateAndSetControls( "Sailing1Pers", "TelescopeOut", CI_GetKeyCode(CTL_DECK_SPYGLASS), INVERSE_CONTROL, true );	// set fix option_screen.c

	CI_CreateAndSetControls( "Sailing3Pers", "MiniMapZoomIn", CI_GetKeyCode(CTL_MINIMAP_ZOOM_IN), 0, true );
	MapControlToGroup("MiniMapZoomIn","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "MiniMapZoomOut", CI_GetKeyCode(CTL_MINIMAP_ZOOM_OUT), 0, true );
	MapControlToGroup("MiniMapZoomOut","Sailing1Pers");


	CI_CreateAndSetControls( "Sailing3Pers", "Sea_CameraSwitch", CI_GetKeyCode(CTL_SHIP_VIEW_SWITCH), 0, true );
	MapControlToGroup("Sea_CameraSwitch","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "BICommandsActivate", CI_GetKeyCode(CTL_SHIP_OPEN_ICONMENU), 0, true );
	MapControlToGroup("BICommandsActivate","Sailing1Pers");

	CI_CreateAndSetControls( "Sailing3Pers", "BIFastCommand", CI_GetKeyCode(CTL_SHIP_HOT_ACTION), 0, true );
	MapControlToGroup("BIFastCommand","Sailing1Pers");

// KK -->
	CI_CreateAndSetControls( "Sailing3Pers", "ControlDown", CI_GetKeyCode("VK_CONTROL"), 0, true );
	CI_CreateAndSetControls( "Sailing3Pers", "ControlUp", CI_GetKeyCode("VK_CONTROL"), INVERSE_CONTROL, true );
// <-- KK




// -------------------------------------------------------------------------------------------------------------------
// World map

	CI_CreateAndSetControls( "", "WMapTurnH", 256, 0, false );
	CI_CreateAndSetControls( "", "WMapTurnV", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "WorldMapControls", "WMapShipSailUp", CI_GetKeyCode(CTL_MAP_SAIL_RAISE), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapShipSailDown", CI_GetKeyCode(CTL_MAP_SAIL_STRIKE), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapShipTurnLeft", CI_GetKeyCode(CTL_MAP_SHIP_TURN_LEFT), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapShipTurnRight", CI_GetKeyCode(CTL_MAP_SHIP_TURN_RIGHT), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapCameraSwitch", CI_GetKeyCode(CTL_MAP_VIEW_SWITCH), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapCameraRotate", CI_GetKeyCode(CTL_MAP_VIEW_ROTATE), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapForward", CI_GetKeyCode(CTL_MAP_ZOOM_IN), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapBackward", CI_GetKeyCode(CTL_MAP_ZOOM_OUT), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapCancel", CI_GetKeyCode(CTL_MAP_GOTO_SAILING), 0, true );
	CI_CreateAndSetControls( "WorldMapControls", "WMapSkipEncounter", CI_GetKeyCode(CTL_MAP_SKIP_ENCOUNTER), 0, true ); // NK




// -------------------------------------------------------------------------------------------------------------------
// General and Global

	CI_CreateAndSetControls( "General", "ScreenCleaning", CI_GetKeyCode("VK_F9"), 0, true );
	CI_CreateAndSetControls( "General", "BOAL_Control", CI_GetKeyCode(CTL_1X3X), 0, true );			// 1x/3x
	CI_CreateAndSetControls( "General", "BOAL_Control0", CI_GetKeyCode(CTL_10X30X), 0, true );		// 10x/30x
//MAXIMUS: looting will start by pressing F-3 key -->
	CI_CreateAndSetControls( "General", "NK_DialogStart", CI_GetKeyCode(CTL_LOOT_CORPSE), 0, true );// Loot Dead
	MapControlToGroup("NK_DialogStart", "PrimaryLand");
	MapControlToGroup("NK_DialogStart", "FightModeControls");
//MAXIMUS: looting will start by pressing F-3 key <--
	CI_CreateAndSetControls( "General", "NK_AlwaysRunToggle", CI_GetKeyCode(CTL_ALWAYS_RUN_TOGGLE), 0, true );
	MapControlToGroup("NK_AlwaysRunToggle", "PrimaryLand");
	MapControlToGroup("NK_AlwaysRunToggle", "FightModeControls");
	MapControlToGroup("NK_AlwaysRunToggle", "Sailing1Pers");
	MapControlToGroup("NK_AlwaysRunToggle", "Sailing3Pers");

	CI_CreateAndSetControls( "General", "NK_LogsToggle", CI_GetKeyCode(CTL_SCREEN_FULL_LOGS_TOGGLE), 0, true );	// Toggle full logs
	CI_CreateAndSetControls( "General", "Sulan_ArchipelagoMap", CI_GetKeyCode(CTL_ARCHIPELAGO_MAP), 0, true ); // Show Map
	MapControlToGroup("Sulan_ArchipelagoMap", "PrimaryLand");
	MapControlToGroup("Sulan_ArchipelagoMap", "Sailing1Pers");
	MapControlToGroup("Sulan_ArchipelagoMap", "Sailing3Pers");
	MapControlToGroup("Sulan_ArchipelagoMap", "WorldMapControls");

	CI_CreateAndSetControls( "General", "BOAL_Control2", CI_GetKeyCode(CTL_NPC_INFO_TOGGLE), 0, true );	// Toggle show char info
	CI_CreateAndSetControls( "", "NK_Re-init", CI_GetKeyCode(CTL_REINITIALIZE_GAME), 0, false );		// Process reinit (hidden from control settings)
	CI_CreateAndSetControls( "", "executeconsole", CI_GetKeyCode(CTL_EXECUTE_CONSOLE), 0, false );		// Activate the console function (hidden from control settings)

	CI_CreateAndSetControls( "General", "DCH_Quicksave", CI_GetKeyCode(CTL_QUICKSAVE), 0, false );	// dchaley
	CI_CreateAndSetControls( "General", "DCH_Quickload", CI_GetKeyCode(CTL_QUICKLOAD), 0, false );	// dchaley

	// ccc special weapons fastequip keys --> (not changable ingame)
	// These are multi-behavior, while land/fighting they are weapon equip, while sailing they are cannons
	CI_CreateAndSetControls( "", "BI_ChargeCannonballs", CI_GetKeyCode(CTL_AMMO_EQUIP_1), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeGrapes", CI_GetKeyCode(CTL_AMMO_EQUIP_2), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKnippels", CI_GetKeyCode(CTL_AMMO_EQUIP_3), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeBombs", CI_GetKeyCode(CTL_AMMO_EQUIP_4), 0, false );
	// These only work while in land/fight ... not sailing
	CI_CreateAndSetControls( "", "BI_ChargeKey5", CI_GetKeyCode(CTL_AMMO_EQUIP_5), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKey6", CI_GetKeyCode(CTL_AMMO_EQUIP_6), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKey7", CI_GetKeyCode(CTL_AMMO_EQUIP_7), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKey8", CI_GetKeyCode(CTL_AMMO_EQUIP_8), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKey9", CI_GetKeyCode(CTL_AMMO_EQUIP_9), 0, false );
	CI_CreateAndSetControls( "", "BI_ChargeKey0", CI_GetKeyCode(CTL_AMMO_EQUIP_0), 0, false );
	// ccc <--





// -------------------------------------------------------------------------------------------------------------------
// Interface (not changable ingame)

	// Main interface
	CI_CreateAndSetControls( "General", "MainMenu", CI_GetKeyCode(CTL_ACTIVATE_MAINMENU), 0, false );
	MapControlToGroup("MainMenu","Sailing3Pers");
	MapControlToGroup("MainMenu","Sailing1Pers");
	MapControlToGroup("MainMenu","PrimaryLand");
	MapControlToGroup("MainMenu","WorldMapControls");
	MapControlToGroup("MainMenu","FightModeControls");
	MapControlToGroup("MainMenu","BattleInterfaceControls");

	CI_CreateAndSetControls( "General", "Interface", CI_GetKeyCode(CTL_ACTIVATE_INTERFACE), 0, false );
	MapControlToGroup("Interface","Sailing3Pers");
	MapControlToGroup("Interface","Sailing1Pers");
	MapControlToGroup("Interface","PrimaryLand");
	MapControlToGroup("Interface","WorldMapControls");
	MapControlToGroup("Interface","FightModeControls");
	MapControlToGroup("Interface","BattleInterfaceControls");

	CI_CreateAndSetControls( "", "ITurnH", 256, 0, false );
	CI_CreateAndSetControls( "", "ITurnV", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "ILClick", CI_GetKeyCode("VK_LBUTTON"), 0, false );
	CI_CreateAndSetControls( "", "ILClick_Up", CI_GetKeyCode("VK_LBUTTON"), INVERSE_CONTROL, false); // KK
	CI_CreateAndSetControls( "", "IRClick", CI_GetKeyCode("VK_RBUTTON"), 0, false );
// KK -->
	CI_CreateAndSetControls( "", "IRClick_Up", CI_GetKeyCode("VK_RBUTTON"), INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "IMClick", CI_GetKeyCode("VK_MBUTTON"), 0, false );
	CI_CreateAndSetControls( "", "IMClick_Up", CI_GetKeyCode("VK_MBUTTON"), INVERSE_CONTROL, false );
// <-- KK
	CI_CreateAndSetControls( "", "IStartButton", CI_GetKeyCode("VK_RETURN"), 0, false );
	CI_CreateAndSetControls( "", "IAllCancel", CI_GetKeyCode("VK_BACK"), 0, false );
	CI_CreateAndSetControls( "", "ICancel", CI_GetKeyCode(CTL_INTERFACE_NAV_CANCEL), 0, false );
	CI_CreateAndSetControls( "", "IAction", CI_GetKeyCode(CTL_INTERFACE_NAV_SELECT), 0, false );
	CI_CreateAndSetControls( "", "ILeftAlt", CI_GetKeyCode("VK_ALT"), 0, false );
	CI_CreateAndSetControls( "", "ILeftAltUp", CI_GetKeyCode("VK_ALT"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "IRightAlt", CI_GetKeyCode("VK_ALT"), 0, false );
	CI_CreateAndSetControls( "", "IRightAltUp", CI_GetKeyCode("VK_ALT"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "ILeftControl", CI_GetKeyCode("VK_CONTROL"), 0, false );
	CI_CreateAndSetControls( "", "ILeftControlUp", CI_GetKeyCode("VK_CONTROL"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "IRightControl", CI_GetKeyCode("VK_CONTROL"), 0, false );
	CI_CreateAndSetControls( "", "IRightControlUp", CI_GetKeyCode("VK_CONTROL"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "ILeftShift", CI_GetKeyCode("VK_SHIFT"), 0, false );
	CI_CreateAndSetControls( "", "ILeftShiftUp", CI_GetKeyCode("VK_SHIFT"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "IRightShift", CI_GetKeyCode("VK_SHIFT"), 0, false );
	CI_CreateAndSetControls( "", "IRightShiftUp", CI_GetKeyCode("VK_SHIFT"), INVERSE_CONTROL, false ); // KK
	CI_CreateAndSetControls( "", "IUp", CI_GetKeyCode(CTL_INTERFACE_NAV_UP), 0, false );
	CI_CreateAndSetControls( "", "IDown", CI_GetKeyCode(CTL_INTERFACE_NAV_DOWN), 0, false );
	CI_CreateAndSetControls( "", "ILeft", CI_GetKeyCode(CTL_INTERFACE_NAV_LEFT), 0, false );
	CI_CreateAndSetControls( "", "IRight", CI_GetKeyCode(CTL_INTERFACE_NAV_RIGHT), 0, false );

	// Battle interface
	CI_CreateAndSetControls( "BattleInterfaceControls", "BICommandsConfirm", CI_GetKeyCode(CTL_CMD_INTERFACE_SELECT), 0, true );
	CI_CreateAndSetControls( "BattleInterfaceControls", "BICommandsCancel", CI_GetKeyCode(CTL_CMD_INTERFACE_CANCEL), 0, true );
	CI_CreateAndSetControls( "BattleInterfaceControls", "BICommandsLeft", CI_GetKeyCode(CTL_CMD_INTERFACE_LEFT), 0, true );
	CI_CreateAndSetControls( "BattleInterfaceControls", "BICommandsRight", CI_GetKeyCode(CTL_CMD_INTERFACE_RIGHT), 0, true );




// -------------------------------------------------------------------------------------------------------------------
// Dialog (not changable ingame)

	CI_CreateAndSetControls( "", "DlgCancel", CI_GetKeyCode(CTL_DIALOG_CANCEL), 0, false );
	CI_CreateAndSetControls( "DialogControls", "DlgScrollUp", CI_GetKeyCode(CTL_DIALOG_SCROLL_UP), 0, false );
	CI_CreateAndSetControls( "DialogControls", "DlgScrollDown", CI_GetKeyCode(CTL_DIALOG_SCROLL_DOWN), 0, false );

	SwitchDialogControls(); // KK


// -------------------------------------------------------------------------------------------------------------------
// Cheats (not changable ingame)

	CI_CreateAndSetControls( "", "CheatGod",					CI_GetKeyCode(CTL_CHEAT_GODMODE),      0, false );
	CI_CreateAndSetControls( "", "CheatScrollCharactersLeft",	CI_GetKeyCode(CTL_CHEAT_SCROLL_LEFT ), 0, false );
	CI_CreateAndSetControls( "", "CheatScrollCharactersMain",	CI_GetKeyCode(CTL_CHEAT_SCROLL_MAIN ), 0, false );
	CI_CreateAndSetControls( "", "CheatScrollCharactersRight",	CI_GetKeyCode(CTL_CHEAT_SCROLL_RIGHT), 0, false );
	CI_CreateAndSetControls( "", "CheatLevelUp",				CI_GetKeyCode(CTL_CHEAT_PLAYERLVLUP),  0, false );
	CI_CreateAndSetControls( "", "CheatFakeLevelUp",			CI_GetKeyCode(CTL_CHEAT_FAKELVLUP),    0, false );
	CI_CreateAndSetControls( "", "CheatGold",					CI_GetKeyCode(CTL_CHEAT_MOREGOLD),     0, false );
	CI_CreateAndSetControls( "", "CheatReputation",				CI_GetKeyCode(CTL_CHEAT_RAISEREP),     0, false );
	CI_CreateAndSetControls( "", "CheatWorldmap",				CI_GetKeyCode(CTL_CHEAT_WORLDMAP),     0, false );




// -------------------------------------------------------------------------------------------------------------------
// Chunks of commented out code that is either no longer used, may be used during testing, or only left for reference
// -------------------------------------------------------------------------------------------------------------------

	//CI_CreateAndSetControls( "", "Dump", CI_GetKeyCode("KEY_0"), 0, false );

	// 04-12-10 disabled since we have Time-1x/3x and we need the key.
	//CI_CreateAndSetControls( "", "TimeScale", CI_GetKeyCode("VK_MULTIPLY"), 0, false );

	// Cameras =====================================================================
/*		// character camera
	CI_CreateAndSetControls( "", "ChrCamTurnV", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "ChrCamTurnH", 256, 0, false );
	CI_CreateAndSetControls( "", "Turn V", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "Turn H", 256, 0, false );
	CI_CreateAndSetControls( "PrimaryLand", "ChrCamCameraSwitch", CI_GetKeyCode("VK_TAB"), 0, true );

		// ship follow camera
	CI_CreateAndSetControls( "", "ShipCamera_Turn_V", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "ShipCamera_Turn_H", 256, 0, false );
	CI_CreateAndSetControls( "Sailing3Pers", "ShipCamera_Forward", CI_GetKeyCode("VK_LBUTTON"), 0, true );
	CI_CreateAndSetControls( "Sailing3Pers", "ShipCamera_Backward", CI_GetKeyCode("VK_RBUTTON"), 0, true );

		// deck camera
	CI_CreateAndSetControls( "", "DeckCamera_Turn_V", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "DeckCamera_Turn_H", 256, 0, false );
	CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Forward", CI_GetKeyCode("VK_LBUTTON"), 0, true );
	CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Backward", CI_GetKeyCode("VK_RBUTTON"), 0, true );
	//CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Left", CI_GetKeyCode("VK_LEFT"), 0, true );
	//CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Right", CI_GetKeyCode("VK_RIGHT"), 0, true );

		// free camera
	CI_CreateAndSetControls( "", "FreeCamera_Turn_V", 257, INVERSE_CONTROL, false );
	CI_CreateAndSetControls( "", "FreeCamera_Turn_H", 256, 0, false );
	CI_CreateAndSetControls( "", "FreeCamera_Forward", CI_GetKeyCode("VK_LBUTTON"), 0, false );
	CI_CreateAndSetControls( "", "FreeCamera_Backward", CI_GetKeyCode("VK_RBUTTON"), 0, false );
*/

	//CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Left", CI_GetKeyCode("VK_LEFT"), 0, true );
	//CI_CreateAndSetControls( "Sailing1Pers", "DeckCamera_Right", CI_GetKeyCode("VK_RIGHT"), 0, true );

	//CI_CreateContainer("", "ChrTurnH1", 15.0);
	//MapControlToGroup("ChrTurnH1","FightModeControls");
	//MapControlToGroup("ChrTurnH1","BattleInterfaceControls");
	//AddToContainer("PrimaryLand", "ChrTurnH1", "TmpChrTurn1", CI_GetKeyCode("KEY_D"), 0, false );
	//MapControlToGroup("TmpChrTurn1","FightModeControls");
	//AddToContainer("PrimaryLand", "ChrTurnH1", "TmpChrTurn2", CI_GetKeyCode("KEY_A"), 0, true );
	//MapControlToGroup("TmpChrTurn2","FightModeControls");

	//CI_CreateAndSetControls( "FightModeControls", "ChrFightMode", CI_GetKeyCode("KEY_E"), 0, true );
//	CI_CreateAndSetControls( "Sailing1Pers", "Interface", CI_GetKeyCode("VK_F2"), 0, false );
//	CI_CreateAndSetControls( "", "MainMenu", CI_GetKeyCode("VK_F1"), 0, false );

	//CI_CreateAndSetControls( "", "IContextHelp", CI_GetKeyCode("VK_CONTROL"), 0, false );

	//			Help chooser
	//CI_CreateAndSetControls( "", "Help", CI_GetKeyCode("KEY_I"), 0, false );
	/*CI_CreateAndSetControls( "", "HelpChooser_LeftClick", CI_GetKeyCode("VK_LBUTTON"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Cancel", CI_GetKeyCode("VK_ESCAPE"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Action", CI_GetKeyCode("VK_SPACE"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Next", CI_GetKeyCode("VK_NEXT"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Prev", CI_GetKeyCode("VK_PRIOR"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Left", CI_GetKeyCode("VK_LEFT"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Right", CI_GetKeyCode("VK_RIGHT"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Up", CI_GetKeyCode("VK_UP"), 0, false );
	CI_CreateAndSetControls( "HelpChooser", "HelpChooser_Down", CI_GetKeyCode("VK_DOWN"), 0, false );
	*/

	// Teleport
	if(ENABLE_CHEATMODE)
	{
		CI_CreateAndSetControls( "", "TeleportActive", CI_GetKeyCode("VK_F4"), 0, false );
		CI_CreateAndSetControls( "", "TeleportUp", CI_GetKeyCode("VK_UP"), 0, false );
		CI_CreateAndSetControls( "", "TeleportDown", CI_GetKeyCode("VK_DOWN"), 0, false );
		CI_CreateAndSetControls( "", "TeleportSelect", CI_GetKeyCode("VK_RETURN"), 0, false );
	}

	// weather
	//CI_CreateAndSetControls( "", "WhrPrevWeather", CI_GetKeyCode("KEY_M"), 0, false );
	//CI_CreateAndSetControls( "", "WhrNextWeather", CI_GetKeyCode("KEY_N"), 0, false );
	//CI_CreateAndSetControls( "", "WhrUpdateWeather", CI_GetKeyCode("KEY_B"), 0, false );

	//MapControlToGroup("NK_AlwaysRunToggle", "BattleInterfaceControls");
	//MapControlToGroup("NK_AlwaysRunToggle", "Sailing1Pers");
	//MapControlToGroup("NK_AlwaysRunToggle", "Sailing3Pers");
	//MapControlToGroup("NK_AlwaysRunToggle", "WorldMapControls");

	/*MapControlToGroup("NK_LogsToggle", "PrimaryLand");
	MapControlToGroup("NK_LogsToggle", "FightModeControls");
	MapControlToGroup("NK_LogsToggle", "BattleInterfaceControls");
	MapControlToGroup("NK_LogsToggle", "Sailing1Pers");
	MapControlToGroup("NK_LogsToggle", "Sailing3Pers");
	MapControlToGroup("NK_LogsToggle", "WorldMapControls");*/

	/*MapControlToGroup("NK_Re-init", "PrimaryLand");
	MapControlToGroup("NK_Re-init", "FightModeControls");
	MapControlToGroup("NK_Re-init", "BattleInterfaceControls");
	MapControlToGroup("NK_Re-init", "Sailing1Pers");
	MapControlToGroup("NK_Re-init", "Sailing3Pers");
	MapControlToGroup("NK_Re-init", "WorldMapControls");*/

	/*MapControlToGroup("BOAL_Control", "PrimaryLand");
	MapControlToGroup("BOAL_Control", "FightModeControls");
	MapControlToGroup("BOAL_Control", "BattleInterfaceControls");
	MapControlToGroup("BOAL_Control", "Sailing1Pers");
	MapControlToGroup("BOAL_Control", "Sailing3Pers");
	MapControlToGroup("BOAL_Control", "WorldMapControls");*/

	/*MapControlToGroup("BOAL_Control2", "PrimaryLand");
	MapControlToGroup("BOAL_Control2", "FightModeControls");
	MapControlToGroup("BOAL_Control2", "BattleInterfaceControls");
	MapControlToGroup("BOAL_Control2", "Sailing1Pers");
	MapControlToGroup("BOAL_Control2", "Sailing3Pers");
	MapControlToGroup("BOAL_Control2", "WorldMapControls");*/

	/*MapControlToGroup("BOAL_Control0", "PrimaryLand");
	MapControlToGroup("BOAL_Control0", "FightModeControls");
	MapControlToGroup("BOAL_Control0", "BattleInterfaceControls");
	MapControlToGroup("BOAL_Control0", "Sailing1Pers");
	MapControlToGroup("BOAL_Control0", "Sailing3Pers");
	MapControlToGroup("BOAL_Control0", "WorldMapControls");*/

	//MapControlToGroup("BOAL_UsePotion", "BattleInterfaceControls");
	//MapControlToGroup("BOAL_UsePotion", "Sailing1Pers");	// ccc enabled for firedrill
	//MapControlToGroup("BOAL_UsePotion", "Sailing3Pers");	// ccc

/*
//  ccc special weapons, section disabled to enable fastequip keys -->
	CI_CreateAndSetControls( "Sailing3Pers", "BI_ChargeCannonballs", CI_GetKeyCode("KEY_1"), 0, true );
	MapControlToGroup("BI_ChargeCannonballs","Sailing1Pers");
	MapControlToGroup("BI_ChargeCannonballs", "BattleInterfaceControls");

	CI_CreateAndSetControls( "Sailing3Pers", "BI_ChargeGrapes", CI_GetKeyCode("KEY_2"), 0, true );
	MapControlToGroup("BI_ChargeGrapes","Sailing1Pers");
	MapControlToGroup("BI_ChargeGrapes", "BattleInterfaceControls");

	CI_CreateAndSetControls( "Sailing3Pers", "BI_ChargeKnippels", CI_GetKeyCode("KEY_3"), 0, true );
	MapControlToGroup("BI_ChargeKnippels","Sailing1Pers");
	MapControlToGroup("BI_ChargeKnippels", "BattleInterfaceControls");

	CI_CreateAndSetControls( "Sailing3Pers", "BI_ChargeBombs", CI_GetKeyCode("KEY_4"), 0, true );
	MapControlToGroup("BI_ChargeBombs","Sailing1Pers");
	MapControlToGroup("BI_ChargeBomb", "BattleInterfaceControls");
*/

//CI_CreateAndSetControls( "", "Tele", CI_GetKeyCode("KEY_P"), 0, false );

	// NK keys
	// just create the controls for now...
	/*CI_CreateControlOnly("NK_Key_a");
	CI_CreateControlOnly("NK_Key_b");
	CI_CreateControlOnly("NK_Key_c");
	CI_CreateControlOnly("NK_Key_d");
	CI_CreateControlOnly("NK_Key_e");
	CI_CreateControlOnly("NK_Key_f");
	CI_CreateControlOnly("NK_Key_g");
	CI_CreateControlOnly("NK_Key_h");
	CI_CreateControlOnly("NK_Key_i");
	CI_CreateControlOnly("NK_Key_j");
	CI_CreateControlOnly("NK_Key_k");
	CI_CreateControlOnly("NK_Key_l");
	CI_CreateControlOnly("NK_Key_m");
	CI_CreateControlOnly("NK_Key_n");
	CI_CreateControlOnly("NK_Key_o");
	CI_CreateControlOnly("NK_Key_p");
	CI_CreateControlOnly("NK_Key_q");
	CI_CreateControlOnly("NK_Key_r");
	CI_CreateControlOnly("NK_Key_s");
	CI_CreateControlOnly("NK_Key_t");
	CI_CreateControlOnly("NK_Key_u");
	CI_CreateControlOnly("NK_Key_v");
	CI_CreateControlOnly("NK_Key_w");
	CI_CreateControlOnly("NK_Key_x");
	CI_CreateControlOnly("NK_Key_y");
	CI_CreateControlOnly("NK_Key_z");
	CI_CreateControlOnly("NK_Key_0");
	CI_CreateControlOnly("NK_Key_1");
	CI_CreateControlOnly("NK_Key_2");
	CI_CreateControlOnly("NK_Key_3");
	CI_CreateControlOnly("NK_Key_4");
	CI_CreateControlOnly("NK_Key_5");
	CI_CreateControlOnly("NK_Key_6");
	CI_CreateControlOnly("NK_Key_7");
	CI_CreateControlOnly("NK_Key_8");
	CI_CreateControlOnly("NK_Key_9");*/
	// NK <--
}

void ExternInitKeyCodes()
{
	objControlsState.key_codes.VK_LBUTTON	= 1;
	objControlsState.key_codes.VK_LBUTTON.img = "q";
	objControlsState.key_codes.VK_RBUTTON	= 2;
	objControlsState.key_codes.VK_RBUTTON.img = "w";
	objControlsState.key_codes.VK_BACK		= 8;
	objControlsState.key_codes.VK_BACK.img = "b";
	objControlsState.key_codes.VK_TAB		= 9;
	objControlsState.key_codes.VK_TAB.img = "t";
	objControlsState.key_codes.VK_RETURN	= 13;
	objControlsState.key_codes.VK_RETURN.img = "n";

	objControlsState.key_codes.VK_SHIFT		= 16;
	objControlsState.key_codes.VK_SHIFT.img = "i";
	objControlsState.key_codes.VK_CONTROL	= 17;
	objControlsState.key_codes.VK_CONTROL.img = "c";
	objControlsState.key_codes.VK_ALT		= 18; // KK was 15 - WRONG don't change it back!
	objControlsState.key_codes.VK_ALT.img = "i";
// KK -->
	objControlsState.key_codes.VK_PAUSE		= 19;
	objControlsState.key_codes.VK_PAUSE.img = "i";
// <-- KK
	objControlsState.key_codes.VK_ESCAPE	= 27;
	objControlsState.key_codes.VK_ESCAPE.img = "e";
	objControlsState.key_codes.VK_SPACE		= 32;
	objControlsState.key_codes.VK_SPACE.img = "s";
	objControlsState.key_codes.VK_PRIOR		= 33;
	objControlsState.key_codes.VK_PRIOR.img = "p";
	objControlsState.key_codes.VK_NEXT		= 34;
	objControlsState.key_codes.VK_NEXT.img = "j";
	objControlsState.key_codes.VK_LEFT		= 37;
	objControlsState.key_codes.VK_LEFT.img = "l";
	objControlsState.key_codes.VK_UP		= 38;
	objControlsState.key_codes.VK_UP.img = "u";
	objControlsState.key_codes.VK_RIGHT		= 39;
	objControlsState.key_codes.VK_RIGHT.img = "r";
	objControlsState.key_codes.VK_DOWN		= 40;
	objControlsState.key_codes.VK_DOWN.img = "d";

	objControlsState.key_codes.KEY_0 = 48;
	objControlsState.key_codes.KEY_0.img = "0";
	objControlsState.key_codes.KEY_1 = 49;
	objControlsState.key_codes.KEY_1.img = "1";
	objControlsState.key_codes.KEY_2 = 50;
	objControlsState.key_codes.KEY_2.img = "2";
	objControlsState.key_codes.KEY_3 = 51;
	objControlsState.key_codes.KEY_3.img = "3";
	objControlsState.key_codes.KEY_4 = 52;
	objControlsState.key_codes.KEY_4.img = "4";
	objControlsState.key_codes.KEY_5 = 53;
	objControlsState.key_codes.KEY_5.img = "5";
	objControlsState.key_codes.KEY_6 = 54;
	objControlsState.key_codes.KEY_6.img = "6";
	objControlsState.key_codes.KEY_7 = 55;
	objControlsState.key_codes.KEY_7.img = "7";
	objControlsState.key_codes.KEY_8 = 56;
	objControlsState.key_codes.KEY_8.img = "8";
	objControlsState.key_codes.KEY_9 = 57;
	objControlsState.key_codes.KEY_9.img = "9";

	objControlsState.key_codes.KEY_A = 65;
	objControlsState.key_codes.KEY_A.img = "A";
	objControlsState.key_codes.KEY_B = 66;
	objControlsState.key_codes.KEY_B.img = "B";
	objControlsState.key_codes.KEY_C = 67;
	objControlsState.key_codes.KEY_C.img = "C";
	objControlsState.key_codes.KEY_D = 68;
	objControlsState.key_codes.KEY_D.img = "D";
	objControlsState.key_codes.KEY_E = 69;
	objControlsState.key_codes.KEY_E.img = "E";
	objControlsState.key_codes.KEY_F = 70;
	objControlsState.key_codes.KEY_F.img = "F";
	objControlsState.key_codes.KEY_G = 71;
	objControlsState.key_codes.KEY_G.img = "G";
	objControlsState.key_codes.KEY_H = 72;
	objControlsState.key_codes.KEY_H.img = "H";
	objControlsState.key_codes.KEY_I = 73;
	objControlsState.key_codes.KEY_I.img = "I";
	objControlsState.key_codes.KEY_J = 74;
	objControlsState.key_codes.KEY_J.img = "J";
	objControlsState.key_codes.KEY_K = 75;
	objControlsState.key_codes.KEY_K.img = "K";
	objControlsState.key_codes.KEY_L = 76;
	objControlsState.key_codes.KEY_L.img = "L";
	objControlsState.key_codes.KEY_M = 77;
	objControlsState.key_codes.KEY_M.img = "M";
	objControlsState.key_codes.KEY_N = 78;
	objControlsState.key_codes.KEY_N.img = "N";
	objControlsState.key_codes.KEY_O = 79;
	objControlsState.key_codes.KEY_O.img = "O";
	objControlsState.key_codes.KEY_P = 80;
	objControlsState.key_codes.KEY_P.img = "P";
	objControlsState.key_codes.KEY_Q = 81;
	objControlsState.key_codes.KEY_Q.img = "Q";
	objControlsState.key_codes.KEY_R = 82;
	objControlsState.key_codes.KEY_R.img = "R";
	objControlsState.key_codes.KEY_S = 83;
	objControlsState.key_codes.KEY_S.img = "S";
	objControlsState.key_codes.KEY_T = 84;
	objControlsState.key_codes.KEY_T.img = "T";
	objControlsState.key_codes.KEY_U = 85;
	objControlsState.key_codes.KEY_U.img = "U";
	objControlsState.key_codes.KEY_V = 86;
	objControlsState.key_codes.KEY_V.img = "V";
	objControlsState.key_codes.KEY_W = 87;
	objControlsState.key_codes.KEY_W.img = "W";
	objControlsState.key_codes.KEY_X = 88;
	objControlsState.key_codes.KEY_X.img = "X";
	objControlsState.key_codes.KEY_Y = 89;
	objControlsState.key_codes.KEY_Y.img = "Y";
	objControlsState.key_codes.KEY_Z = 90;
	objControlsState.key_codes.KEY_Z.img = "Z";
// KK -->
	objControlsState.key_codes.VK_EQUAL = 61; // =
	objControlsState.key_codes.VK_EQUAL.img = "=";
// <-- KK

	objControlsState.key_codes.VK_NUMPAD0	= 96;
	objControlsState.key_codes.VK_NUMPAD0.img = ")";
	objControlsState.key_codes.VK_NUMPAD1	= 97;
	objControlsState.key_codes.VK_NUMPAD1.img = "!";
	objControlsState.key_codes.VK_NUMPAD2	= 98;
	objControlsState.key_codes.VK_NUMPAD2.img = "@";
	objControlsState.key_codes.VK_NUMPAD3	= 99;
	objControlsState.key_codes.VK_NUMPAD3.img = "#";
	objControlsState.key_codes.VK_NUMPAD4	= 100;
	objControlsState.key_codes.VK_NUMPAD4.img = "$";
	objControlsState.key_codes.VK_NUMPAD5	= 101;
	objControlsState.key_codes.VK_NUMPAD5.img = "%";
	objControlsState.key_codes.VK_NUMPAD6	= 102;
	objControlsState.key_codes.VK_NUMPAD6.img = "^";
	objControlsState.key_codes.VK_NUMPAD7	= 103;
	objControlsState.key_codes.VK_NUMPAD7.img = "&";
	objControlsState.key_codes.VK_NUMPAD8	= 104;
	objControlsState.key_codes.VK_NUMPAD8.img = "*";
	objControlsState.key_codes.VK_NUMPAD9	= 105;
	objControlsState.key_codes.VK_NUMPAD9.img = "(";
	objControlsState.key_codes.VK_MULTIPLY	= 106;
	objControlsState.key_codes.VK_MULTIPLY.img = "m";
	objControlsState.key_codes.VK_ADD		= 107;
	objControlsState.key_codes.VK_ADD.img = "+";
	objControlsState.key_codes.VK_SEPARATOR	= 108;
	objControlsState.key_codes.VK_SEPARATOR.img = "_";
	objControlsState.key_codes.VK_SUBTRACT	= 109;
	objControlsState.key_codes.VK_SUBTRACT.img = "-";
	objControlsState.key_codes.VK_DECIMAL	= 110;
	objControlsState.key_codes.VK_DECIMAL.img = ".";
	objControlsState.key_codes.VK_DIVIDE	= 111;
	objControlsState.key_codes.VK_DIVIDE.img = "/";
	objControlsState.key_codes.VK_F1		= 112;
	objControlsState.key_codes.VK_F1.img = "z";
	objControlsState.key_codes.VK_F2		= 113;
	objControlsState.key_codes.VK_F2.img = "x";
	objControlsState.key_codes.VK_F3		= 114;
	objControlsState.key_codes.VK_F3.img = "v";
	objControlsState.key_codes.VK_F4		= 115;
	objControlsState.key_codes.VK_F4.img = "<";
	objControlsState.key_codes.VK_F5        = 116;
	objControlsState.key_codes.VK_F5.img    = "a";
	objControlsState.key_codes.VK_F6        = 117;
	objControlsState.key_codes.VK_F6.img    = "ö";
	objControlsState.key_codes.VK_F9        = 120;
	objControlsState.key_codes.VK_F9.img    = "f";

	// dchaley -->
	// 04-12-10 commented out because of Euro incompatibility.
	// need these for quick save
	/*objControlsState.key_codes.VK_F5        = 116;
	objControlsState.key_codes.VK_F5.img    = "a";		// changed by KAM
	objControlsState.key_codes.VK_F9        = 120;
	objControlsState.key_codes.VK_F9.img    = "f";		// changed by KAM*/
	// dchaley <--


	// boal -->
	objControlsState.key_codes.VK_F11      = 122;
	objControlsState.key_codes.VK_F11.img = "<";
	objControlsState.key_codes.VK_F12      = 123;
	objControlsState.key_codes.VK_F12.img = "<";
	objControlsState.key_codes.VK_MBUTTON   = 4;
	objControlsState.key_codes.VK_MBUTTON.img = "_";//MAXIMUS: picture added into pc_keyboard
	// boal <--

	// NK Keyboard 05-07-21
	if(bKeyboardEnabled)
	{
		objControlsState.key_codes.VK_CAPITAL = 20; //capslock
		objControlsState.key_codes.VK_CAPITAL.img = ">";
		objControlsState.key_codes.VK_END = 35;
		objControlsState.key_codes.VK_END.img = ">";
		objControlsState.key_codes.VK_HOME = 36;
		objControlsState.key_codes.VK_HOME.img = ">";
		objControlsState.key_codes.VK_INSERT = 45;
		objControlsState.key_codes.VK_INSERT.img = ">";
		objControlsState.key_codes.VK_DELETE = 46;
		objControlsState.key_codes.VK_DELETE.img = ">";
		objControlsState.key_codes.VK_OEM_1 = 186; // ; æ
		objControlsState.key_codes.VK_OEM_1.img = ">";
		objControlsState.key_codes.VK_OEM_PLUS = 187; // +
		objControlsState.key_codes.VK_OEM_PLUS.img = ">";
		objControlsState.key_codes.VK_OEM_COMMA = 188; // , á
		objControlsState.key_codes.VK_OEM_COMMA.img = ">";
		objControlsState.key_codes.VK_OEM_MINUS = 189; // -
		objControlsState.key_codes.VK_OEM_MINUS.img = ">";
		objControlsState.key_codes.VK_OEM_PERIOD = 190; // . þ
		objControlsState.key_codes.VK_OEM_PERIOD.img = ">";

		// added by MAXIMUS for typing on Russian -->
		objControlsState.key_codes.VK_OEM_2 = 191; // / .
		objControlsState.key_codes.VK_OEM_2.img = ">";
		objControlsState.key_codes.VK_OEM_3 = 192; // ` ¸
		objControlsState.key_codes.VK_OEM_3.img = ">";
		objControlsState.key_codes.VK_OEM_4 = 219; // [ õ
		objControlsState.key_codes.VK_OEM_4.img = ">";
		objControlsState.key_codes.VK_OEM_5 = 220; // \
		objControlsState.key_codes.VK_OEM_5.img = ">";
		objControlsState.key_codes.VK_OEM_6 = 221; // ] ú
		objControlsState.key_codes.VK_OEM_6.img = ">";
		objControlsState.key_codes.VK_OEM_7 = 222; // ' ý changed by MAXIMUS was 223
		objControlsState.key_codes.VK_OEM_7.img = ">";
		// added by MAXIMUS for typing on Russian <--
		//oem_2-3 are 191-192 as / and `
		//then oem_4-7 are 219-222, [ \ ] '
	}
	// NK <--

	// Key groups for controls remapping
	objControlsState.grouplist.Sailing1Pers = true;
	objControlsState.grouplist.Sailing3Pers = true;
	objControlsState.grouplist.FightModeControls = true;
	objControlsState.grouplist.PrimaryLand = true;
	objControlsState.grouplist.General = true;	// KAM
	objControlsState.grouplist.worldMapControls = true;	// KAM
}
