object objLandInterface;
object objFastReloadTable;
// NK 05-04-23 switch to towns[] object objTownStateTable;
int g_intRetVal;

bool bDisableFastReload = false;

#define	ACTIONMENU_UPDATE_PERIOD	300
#event_handler("evntBattleCommandSound","procBattleCommandSound");

bool bLandInterfaceStart = false;

bool bInterlocutorActive = false; // KK

void procBattleCommandSound()
{
	string comName = GetEventData();
	if(comName=="deactivate")
	{
		PlaySound("interface\cancel.wav"); // KK
	}
	if(comName=="activate")
	{
		PlaySound("interface\ok.wav");
	}
	if(comName=="right" || comName=="left")
	{
		PlaySound("interface\ok.wav");
	}
}

void InitBattleLandInterface()
{
	bLandInterfaceStart = false;
	SetEventHandler(EVENT_LOCATION_LOAD,"StartBattleLandInterface",0);
	SetEventHandler(EVENT_LOCATION_UNLOAD,"EndBattleLandInterface",0);
	LoadLIStates();
}

void BLI_EnableShow()
{
	SetLandInterfaceShow(sti(InterfaceStates.BattleShow.Command));
}

void BLI_DisableShow()
{
	SetLandInterfaceShow(false);
}

void StartBattleLandInterface()
{
	if(bLandInterfaceStart)
	{
		BLI_SetObjectData();
		return;
	}
	bLandInterfaceStart = true;

	BLI_SetShowParameters();
	CreateEntity(&objLandInterface,"battle_land_interface");
	DeleteAttribute(&objLandInterface,"");
	LayerAddObject(EXECUTE,&objLandInterface,-1);
	LayerAddObject(REALIZE,objLandInterface,-1);

	if (!CheckAttribute(InterfaceStates, "BIVisible")) InterfaceStates.BIVisible = true; // KK

	SetEventHandler(EVENT_CHANGE_OFFICERS,"BLI_UpdateOfficers",0);
	SetEventHandler(EVENT_DIALOG_START,"BLI_DisableShow",0);
	SetEventHandler(EVENT_DIALOG_EXIT,"BLI_EnableShow",0);

	BLI_SetObjectData();

	if(dialogRun) BLI_DisableShow();
	else BLI_EnableShow();

	SetEventHandler("evntBLI_Update","BLI_UpdateObjectData",0);
	SetEventHandler("BI_CommandEndChecking","BLI_CheckCommand",0);
	SetEventHandler("BI_LaunchCommand","BLI_ExecuteCommand",0);
	SetEventHandler("BI_SetPossibleCommands","BLI_SetPossibleCommands",0);
	SetEventHandler("evntFindDialogChar","procFindDialogChar",0);
	SetEventHandler("Location_CharacterEntryToLocator", "BLI_ChrEnterToLocation", 0);
	SetEventHandler("Location_CharacterExitFromLocator", "BLI_ChrExitFromLocation", 0);
	SetEventHandler("evntPerkAgainUsable","BLI_RefreshCommandMenu",0);

	RefreshFlags();

	Event("evntBLI_Update");
	Event("evntFindDialogChar");

	BLIVisible(sti(InterfaceStates.BIVisible)); // KK
}

// KK -->
void BLI_SetFlags()
{
	int init = 0;
	if (CheckAttribute(&Characters[GetMaincharacterIndex()], "Flags.waitdelay")) return;
	if (CheckAttribute(&objLandInterface, "DoSetFlags")) {
		init = sti(objLandInterface.DoSetFlags);
		DeleteAttribute(&objLandInterface, "DoSetFlags");
	}
	while (init < locNumShips)
	{
		if (iShips[init] >= 0 && CheckAttribute(&Characters[iShips[init]], "Flags.DoRefresh") == true) {
			DeleteAttribute(&Characters[iShips[init]], "Flags.DoRefresh");
			SetShipFlag(iShips[init]);
			init++;
			objLandInterface.DoSetFlags = init;
			FlagsDelay();
			return;
		}
		init++;
	}
	DelEventHandler("frame", "BLI_SetFlags");
}
// <-- KK

// Screwface
void BLI_FlagsDelay()
{
	int init = 0;
	// Just in case to avoid some errors
	If(!CheckAttribute(&Characters[GetMaincharacterIndex()],"Flags.waitdelay")) Characters[GetMaincharacterIndex()].Flags.waitdelay = 1;
	if (CheckAttribute(&objLandInterface, "Waitrefreshflags")) init = sti(objLandInterface.Waitrefreshflags);
	//trace("waiting before refresh - Frame : "+init);
	init++;
	objLandInterface.Waitrefreshflags = init;
	if(init >= sti(Characters[GetMaincharacterIndex()].Flags.waitdelay)) {
		DeleteAttribute(&objLandInterface, "Waitrefreshflags");
		DelEventHandler("frame", "BLI_FlagsDelay");
		DeleteAttribute(&Characters[GetMaincharacterIndex()], "Flags.waitdelay");
	}
}

ref BLI_CheckCommand()
{
	string commandName = GetEventData();

	aref uiref;	makearef(uiref,objLandInterface.UserIcons);
	aref ar;
	int nq = GetAttributesNum(uiref);
	int i;

	ref pchar = GetMainCharacter();

	bool bUsed = false;
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		ar.enable = false;
	}
	g_intRetVal = BI_COMMODE_USER_ICONS;

	switch(commandName)
	{
// KK -->
		case "BI_EnterShip":
			if (GetCompanionQuantity(pchar) == 1) {
				iShipCaptain = GetMainCharacterIndex();
				Land_DeckStartNow(iShipCaptain, GetCharacterShipQDeck(GetCharacter(iShipCaptain)));
				g_intRetVal = 0;
			} else {
				bUsed = SetShipIcons();
			}
			break;
		// added by KAM -->
// MAXIMUS Deck -->
		case "BI_ExitDeck":
			Return2SeaAfterDeck();
			g_intRetVal = 0;
			break;
// MAXIMUS Deck <--
		// <-- added by KAM

		case "BI_Back":
			Deck_GoBack();
			g_intRetVal = 0;
			break;

		case "BI_ReloadFromLandToSea":
			ReloadFromLandToSea();
			g_intRetVal = 0;
			break;
// <-- KK

		case "cancel":
			g_intRetVal = 0;
		break;

		case "BI_FastReload":
			bUsed = SetReloadIcons();
		break;

		case "BI_ItemsUse":
			bUsed = SetUsedPotionIcons();
		break;

		case "BI_DialogStart":
			g_intRetVal = 0;
		break;

		case "BI_ItemsChange":
			g_intRetVal = 0;
		break;

		case "BI_TakeItem":
			g_intRetVal = 0;
		break;

		case "BI_PlaceItem":
			g_intRetVal = 0;
		break;

		case "BI_OutDoor":
			g_intRetVal = 0;
		break;

		case "BI_UseBox":
			g_intRetVal = 0;
		break;
//MAXIMUS -->
		case "BI_UseCorpse":
			g_intRetVal = 0;
		break;

		case "BI_UseBarrel":
			g_intRetVal = 0;
		break;
//MAXIMUS <--
		case "BI_ActivateRush":
			g_intRetVal = 0;
		break;
	}

	if(!bUsed) objLandInterface.UserIcons.cancel.enable = true;
	return &g_intRetVal;
}

void BLI_ExecuteCommand()
{
	int		chrIdx = GetEventData();
	string	commName = GetEventData();
	int		targChrIdx = GetEventData();
	string	evntName = GetEventData();

	aref	uiref;
	int		curLocIdx;
	int		tmpi;

	ref pchar = GetMainCharacter();

	if( commName=="cancel" || evntName=="cancel" ) return;

	switch(commName)
	{
// KK -->
		case "BI_EnterShip":
			bToDeckFromLand = true;
			bEmergeOnStartloc = false;
			DoFastReload(commName, evntName);//MAXIMUS
		break;
// <-- KK

		case "BI_FastReload":
			DoFastReload(commName, evntName);//MAXIMUS
		break;
		case "BI_ItemsUse":
			if( FindUserIcon(evntName,&uiref) )
			{
				aref arItm;
				if( Items_FindItem(uiref.potion,&arItm) >= 0 )
				{
					//if( CheckAttribute(arItm,"potion") )
					//{
						DoCharacterUsedItem(GetMainCharacter(),arItm.id); //TODO: make sure everyone can use it.
					//}
				}
			}
		break;
		case "BI_DialogStart":
			tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
			ref tmpChar = GetCharacter(tmpi);
			if(tmpi>=0 && !CheckAttribute(tmpChar, "corpse"))	Event("dlgReady","l",tmpi);
			else Event("dlgReady","l",tmpi); //Log_SetStringToLog(TranslateString("","Gamlet")); //Levis: CORPSEMODE 3 fix, Remove event to revert
		break;
		case "BI_ItemsChange":
			tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
			if(tmpi>=0)	LaunchCharacterItemChange(GetCharacter(tmpi));
		break;
		case "BI_TakeItem":
			Item_OnPickItem();
		break;
		case "BI_PlaceItem":
			Item_OnUseItem();
		break;
		case "BI_OutDoor":
			Event("Control Activation","s","ChrAction");
		break;
		case "BI_UseBox":
			OpenBoxProcedure();
		break;//MAXIMUS -->
		case "BI_UseCorpse":
			OpenBoxProcedure();
		break;
		case "BI_UseBarrel":
			OpenBoxProcedure();
		break;//MAXIMUS <--
		case "BI_ActivateRush":
			ActivateCharacterPerk(GetMainCharacter(),"Rush");
		break;
	}
}

//MAXIMUS: moved here for excluding fast reload if character is in dialog -->
void DoFastReload(string commName, string evntName)
{
	if(commName=="" || evntName=="") return;
	if(commName=="cancel" || evntName=="cancel") return;
	if(dialogRun || dialogSelf) return;

	int curLocIdx = -1;
	aref uiref;
	ref mchr = GetMainCharacter();

	switch(commName)
	{
		case "BI_EnterShip":
			FindUserIcon(evntName, &uiref);
			mchr.condition = "reload";
			iShipCaptain = sti(uiref.name);
			Land_DeckStartNow(iShipCaptain, GetCharacterShipQDeck(GetCharacter(iShipCaptain)));
		break;

		case "BI_FastReload":
			curLocIdx = FindLoadedLocation();
			if (curLocIdx == -1) return;
			if (FindUserIcon(evntName, &uiref))
			{
				if(CheckAttribute(uiref, "location"))
				{
					characters[GetMainCharacterIndex()].condition = "reload";
					if (CheckAttribute(Locations[curLocIdx], "fastreload") == true && Locations[curLocIdx].fastreload != "ship")
						PlayerFastTravel(curLocIdx, uiref.location);
					else
						TransferToDeck(uiref.location);
				}
			}
		break;
	}
}
//MAXIMUS: moved here for excluding fast reload if character is in dialog <--

void EndBattleLandInterface()
{
	if(!bLandInterfaceStart) return;
	bLandInterfaceStart = false;

	DeleteAttribute( GetMainCharacter(), "boxname" );

	DeleteDateTimeDisplay(); // KK

	BLI_DisableShow();
	SendMessage(&objLandInterface,"l",MSG_BATTLE_LAND_END);

	DeleteClass(&objLandInterface);

	DelEventHandler(EVENT_CHANGE_OFFICERS,"BLI_UpdateOfficers");
	DelEventHandler(EVENT_DIALOG_START,"BLI_DisableShow");
	DelEventHandler(EVENT_DIALOG_EXIT,"BLI_EnableShow");

	DelEventHandler("evntBLI_Update","BLI_UpdateObjectData");
	DelEventHandler("BI_CommandEndChecking","BLI_CheckCommand");
	DelEventHandler("BI_LaunchCommand","BLI_ExecuteCommand");
	DelEventHandler("BI_SetPossibleCommands","BLI_SetPossibleCommands");
	DelEventHandler("evntFindDialogChar","procFindDialogChar");
	DelEventHandler("Location_CharacterEntryToLocator", "BLI_ChrEnterToLocation");
	DelEventHandler("Location_CharacterExitFromLocator", "BLI_ChrExitFromLocation");
	DelEventHandler("evntPerkAgainUsable","BLI_RefreshCommandMenu");

	Log_SetActiveAction("Nothing");
}

void BLI_SetObjectData()
{
	DeleteAttribute(&objLandInterface,"");
	objLandInterface.data.riskAlarm = 0;
	// индикатор тревоги
	objLandInterface.data.alarm = 0.0;
	// персы вместе с нами
	ref mainCh = GetMainCharacter();
	aref ar;
	int i,cn;
	ref curCh;
	string attrName;
	for(i=0; i < OFFICER_MAX; i++)
	{
		cn = GetOfficersIndex(mainCh,i);
		if(cn==-1) continue;
		curCh = GetCharacter(cn);
		if (curCh.location != mainCh.location) continue;
		attrName = "id"+i;
		makearef(ar,objLandInterface.data.icons.(attrName));
		ar.picture = curCh.FaceId;
		ar.health = 0.0;
		ar.charge = 0.0;
	}
	BLI_SetCommandParameters();
	BLI_SetMassageParameters();
	// текстуры
	int idLngFile = LanguageOpenFile("commands_name.txt");
	objLandInterface.CommandTextures.list.t0.name = "battle_interface\LandCommands.tga";
	objLandInterface.CommandTextures.list.t0.columns = 2;
	objLandInterface.CommandTextures.list.t0.xsize = calcNumberOfTextureColumns(2);
	objLandInterface.CommandTextures.list.t0.ysize = 8;//4;//MAXIMUS
	objLandInterface.CommandTextures.list.t1.name = "battle_interface\LandTarget4.tga";
	objLandInterface.CommandTextures.list.t1.columns = 8; //Greatzen was 4
	objLandInterface.CommandTextures.list.t1.xsize = calcNumberOfTextureColumns(8); //Greatzen was 4
	objLandInterface.CommandTextures.list.t1.ysize = 4; // KK JRH
	objLandInterface.CommandTextures.list.t2.name = "battle_interface\LandTarget1.tga";
	objLandInterface.CommandTextures.list.t2.columns = 4; // KK
	objLandInterface.CommandTextures.list.t2.xsize = calcNumberOfTextureColumns(4); // KK
	objLandInterface.CommandTextures.list.t2.ysize = 2; // PB
	objLandInterface.CommandTextures.list.t3.name = "battle_interface\Cancel.tga";
	objLandInterface.CommandTextures.list.t3.columns = 1;
	objLandInterface.CommandTextures.list.t3.xsize = calcNumberOfTextureColumns(1);
	objLandInterface.CommandTextures.list.t3.ysize = 1;
	objLandInterface.CommandTextures.list.t4.name = "battle_interface\UsedItems1.tga";
	objLandInterface.CommandTextures.list.t4.columns = 4;
	objLandInterface.CommandTextures.list.t4.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t4.ysize = 2;
	objLandInterface.CommandTextures.list.t5.name = "battle_interface\UsedItems2.tga";
	objLandInterface.CommandTextures.list.t5.columns = 4;
	objLandInterface.CommandTextures.list.t5.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t5.ysize = 2;
  // Viper
	objLandInterface.CommandTextures.list.t6.name = "battle_interface\UsedItems3.tga"; //Levis
	objLandInterface.CommandTextures.list.t6.columns = 4;
	objLandInterface.CommandTextures.list.t6.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t6.ysize = 2;
	objLandInterface.CommandTextures.list.t7.name = "blank.tga"; // PW: avoid system.log errors
	objLandInterface.CommandTextures.list.t7.columns = 4;
	objLandInterface.CommandTextures.list.t7.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t7.ysize = 4;
	objLandInterface.CommandTextures.list.t8.name = "blank.tga"; // PW: avoid system.log errors
	objLandInterface.CommandTextures.list.t8.columns = 4;
	objLandInterface.CommandTextures.list.t8.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t8.ysize = 4;
  // Viper
// KK -->
	objLandInterface.CommandTextures.list.t9.name = "blank.tga"; // PW: avoid system.log errors
	objLandInterface.CommandTextures.list.t9.columns = 0;
	objLandInterface.CommandTextures.list.t9.xsize = calcNumberOfTextureColumns(0);
	objLandInterface.CommandTextures.list.t9.ysize = 0;

	objLandInterface.CommandTextures.list.t10.name = "battle_interface\ships_16.tga";
	objLandInterface.CommandTextures.list.t10.columns = 4;
	objLandInterface.CommandTextures.list.t10.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t10.ysize = 4;
	objLandInterface.CommandTextures.list.t11.name = "battle_interface\ships_1.tga";
	objLandInterface.CommandTextures.list.t11.columns = 1;
	objLandInterface.CommandTextures.list.t11.xsize = calcNumberOfTextureColumns(1);
	objLandInterface.CommandTextures.list.t11.ysize = 1;
	objLandInterface.CommandTextures.list.t12.name = "battle_interface\ships_2.tga";
	objLandInterface.CommandTextures.list.t12.columns = 1;
	objLandInterface.CommandTextures.list.t12.xsize = calcNumberOfTextureColumns(1);
	objLandInterface.CommandTextures.list.t12.ysize = 2;
	objLandInterface.CommandTextures.list.t13.name = "battle_interface\08shs_02.tga";
	objLandInterface.CommandTextures.list.t13.columns = 1;
	objLandInterface.CommandTextures.list.t13.xsize = calcNumberOfTextureColumns(1);
	objLandInterface.CommandTextures.list.t13.ysize = 1;
	objLandInterface.CommandTextures.list.t14.name = "battle_interface\ships_32.tga";
	objLandInterface.CommandTextures.list.t14.columns = 4;
	objLandInterface.CommandTextures.list.t14.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t14.ysize = 4;
	objLandInterface.CommandTextures.list.t15.name = "battle_interface\ships_48.tga";
	objLandInterface.CommandTextures.list.t15.columns = 4;
	objLandInterface.CommandTextures.list.t15.xsize = calcNumberOfTextureColumns(4);
	objLandInterface.CommandTextures.list.t15.ysize = 4;
// <-- KK

	objLandInterface.CommandTextures.CommandTexNum = 0;
	// список команд
	objLandInterface.Commands.Cancel.enable			= false;
	objLandInterface.Commands.Cancel.picNum			= calcTextureIndex(0, 1);
	objLandInterface.Commands.Cancel.selPicNum		= calcSelectedTextureIndex(0, 1);
	objLandInterface.Commands.Cancel.texNum			= 3;
	objLandInterface.Commands.Cancel.event			= "Cancel";
	objLandInterface.Commands.Cancel.note			= LanguageConvertString(idLngFile, "land_Cancel");
	objLandInterface.Commands.ItemsUse.enable		= true;
	objLandInterface.Commands.ItemsUse.picNum		= calcTextureIndex(0, 2);
	objLandInterface.Commands.ItemsUse.selPicNum	= calcSelectedTextureIndex(0, 2);
	objLandInterface.Commands.ItemsUse.texNum		= 0;
	objLandInterface.Commands.ItemsUse.event		= "BI_ItemsUse";
	objLandInterface.Commands.ItemsUse.note			= LanguageConvertString(idLngFile, "land_ItemsUse");
	objLandInterface.Commands.DialogStart.enable	= true;
	objLandInterface.Commands.DialogStart.picNum	= calcTextureIndex(4, 2);
	objLandInterface.Commands.DialogStart.selPicNum	= calcSelectedTextureIndex(4, 2);
	objLandInterface.Commands.DialogStart.texNum	= 0;
	objLandInterface.Commands.DialogStart.event		= "BI_DialogStart";
	objLandInterface.Commands.DialogStart.note		= LanguageConvertString(idLngFile, "land_DialogStart");
	objLandInterface.Commands.ItemsChange.enable	= true;
	objLandInterface.Commands.ItemsChange.picNum	= calcTextureIndex(1, 2);
	objLandInterface.Commands.ItemsChange.selPicNum	= calcSelectedTextureIndex(1, 2);
	objLandInterface.Commands.ItemsChange.texNum	= 0;
	objLandInterface.Commands.ItemsChange.event		= "BI_ItemsChange";
	objLandInterface.Commands.ItemsChange.note		= LanguageConvertString(idLngFile, "land_ItemsChange");
	objLandInterface.Commands.TakeItem.enable		= true;
	objLandInterface.Commands.TakeItem.picNum		= calcTextureIndex(5, 2);
	objLandInterface.Commands.TakeItem.selPicNum	= calcSelectedTextureIndex(5, 2);
	objLandInterface.Commands.TakeItem.texNum		= 0;
	objLandInterface.Commands.TakeItem.event		= "BI_TakeItem";
	objLandInterface.Commands.TakeItem.note			= LanguageConvertString(idLngFile, "land_TakeItem");
	objLandInterface.Commands.PlaceItem.enable		= true;
	objLandInterface.Commands.PlaceItem.picNum		= calcTextureIndex(5, 2);
	objLandInterface.Commands.PlaceItem.selPicNum	= calcSelectedTextureIndex(5, 2);
	objLandInterface.Commands.PlaceItem.texNum		= 0;
	objLandInterface.Commands.PlaceItem.event		= "BI_PlaceItem";
	objLandInterface.Commands.PlaceItem.note		= LanguageConvertString(idLngFile, "land_PlaceItem");
	objLandInterface.Commands.OutDoor.enable		= true;
	objLandInterface.Commands.OutDoor.picNum		= calcTextureIndex(2, 2);
	objLandInterface.Commands.OutDoor.selPicNum		= calcSelectedTextureIndex(2, 2);
	objLandInterface.Commands.OutDoor.texNum		= 0;
	objLandInterface.Commands.OutDoor.event			= "BI_OutDoor";
	objLandInterface.Commands.OutDoor.note			= LanguageConvertString(idLngFile, "land_OutDoor");
	objLandInterface.Commands.UseBox.enable			= true;
	objLandInterface.Commands.UseBox.picNum			= calcTextureIndex(8, 2);
	objLandInterface.Commands.UseBox.selPicNum		= calcSelectedTextureIndex(8, 2);
	objLandInterface.Commands.UseBox.texNum			= 0;//MAXIMUS
	objLandInterface.Commands.UseBox.event			= "BI_UseBox";
	objLandInterface.Commands.UseBox.note			= LanguageConvertString(idLngFile, "land_UseBox");
//MAXIMUS -->
	objLandInterface.Commands.UseCorpse.enable		= true;
	objLandInterface.Commands.UseCorpse.picNum		= calcTextureIndex(9, 2);
	objLandInterface.Commands.UseCorpse.selPicNum	= calcSelectedTextureIndex(9, 2);
	objLandInterface.Commands.UseCorpse.texNum		= 0;
	objLandInterface.Commands.UseCorpse.event		= "BI_UseCorpse";
	objLandInterface.Commands.UseCorpse.note		= LanguageConvertString(idLngFile, "land_UseCorpse");

	objLandInterface.Commands.UseBarrel.enable		= true;
	objLandInterface.Commands.UseBarrel.picNum		= calcTextureIndex(10, 2);
	objLandInterface.Commands.UseBarrel.selPicNum	= calcSelectedTextureIndex(10, 2);
	objLandInterface.Commands.UseBarrel.texNum		= 0;
	objLandInterface.Commands.UseBarrel.event		= "BI_UseBarrel";
	objLandInterface.Commands.UseBarrel.note		= LanguageConvertString(idLngFile, "land_UseBarrel");
//MAXIMUS <--
// KK -->
	objLandInterface.Commands.ReloadFromLandToSea.enable		= false;
	objLandInterface.Commands.ReloadFromLandToSea.picNum		= calcTextureIndex(7, 2);
	objLandInterface.Commands.ReloadFromLandToSea.selPicNum		= calcSelectedTextureIndex(7, 2);
	objLandInterface.Commands.ReloadFromLandToSea.texNum		= 0;
	objLandInterface.Commands.ReloadFromLandToSea.event			= "BI_ReloadFromLandToSea";
	objLandInterface.Commands.ReloadFromLandToSea.note	    = LanguageConvertString(idLngFile, "land_ExitDeck");

	objLandInterface.Commands.FastReload.enable		= true;
	objLandInterface.Commands.FastReload.picNum		= calcTextureIndex(3, 2);
	objLandInterface.Commands.FastReload.selPicNum	= calcSelectedTextureIndex(3, 2);
	objLandInterface.Commands.FastReload.texNum		= 0;
	objLandInterface.Commands.FastReload.event		= "BI_FastReload";
	objLandInterface.Commands.FastReload.note		= LanguageConvertString(idLngFile, "land_FastReload");

	if (GetCompanionQuantity(mainCh) == 1) {
		int st = GetCharacterShipType(mainCh);
		if (st >= 0 && st < SHIP_TYPES_QUANTITY) {
			objLandInterface.Commands.EnterShip.enable = true;
			int textureIndex = sti(ShipsTypes[st].BI.Tex);
			string textureAttr = "t" + textureIndex;
			int textureColumns = objLandInterface.CommandTextures.list.(textureAttr).columns;
			objLandInterface.Commands.EnterShip.picNum = calcTextureIndex(sti(ShipsTypes[st].BI.Pic), textureColumns);
			objLandInterface.Commands.EnterShip.selPicNum = calcSelectedTextureIndex(sti(ShipsTypes[st].BI.Pic), textureColumns);
			objLandInterface.Commands.EnterShip.texNum = textureIndex;
			objLandInterface.Commands.EnterShip.event  = "BI_EnterShip";
			objLandInterface.Commands.EnterShip.note   = GetMyShipName(mainCh);
		}
	} else {
		objLandInterface.Commands.EnterShip.enable = true;
		objLandInterface.Commands.EnterShip.picNum = calcTextureIndex(5, 4);
		objLandInterface.Commands.EnterShip.selPicNum = calcSelectedTextureIndex(5, 4);
		objLandInterface.Commands.EnterShip.texNum = 2;
		objLandInterface.Commands.EnterShip.event  = "BI_EnterShip";
		objLandInterface.Commands.EnterShip.note   = LanguageConvertString(idLngFile, "land_EnterDeck");
	}
	// added by KAM -->
// MAXIMUS Deck -->
	objLandInterface.Commands.ExitDeck.enable		= false;
	objLandInterface.Commands.ExitDeck.picNum		= calcTextureIndex(7, 2);
	objLandInterface.Commands.ExitDeck.selPicNum	= calcSelectedTextureIndex(7, 2);
	objLandInterface.Commands.ExitDeck.texNum		= 0;
	objLandInterface.Commands.ExitDeck.event		= "BI_ExitDeck";
	objLandInterface.Commands.ExitDeck.note		    = LanguageConvertString(idLngFile, "land_ExitDeck");
// MAXIMUS Deck <--
	// <-- added by KAM
	objLandInterface.Commands.Back.enable		= false;
	objLandInterface.Commands.Back.picNum		= calcTextureIndex(4, 4);
	objLandInterface.Commands.Back.selPicNum	= calcSelectedTextureIndex(4, 4);
	objLandInterface.Commands.Back.texNum		= 2;
	objLandInterface.Commands.Back.event		= "BI_Back";
	objLandInterface.Commands.Back.note		    = LanguageConvertString(idLngFile, "land_Back");
// <-- KK
	objLandInterface.Commands.ActivateRush.enable	= true;
	objLandInterface.Commands.ActivateRush.picNum		= calcTextureIndex(6, 2);
	objLandInterface.Commands.ActivateRush.selPicNum	= calcSelectedTextureIndex(6, 2);
	objLandInterface.Commands.ActivateRush.texNum		= 0;
	objLandInterface.Commands.ActivateRush.event	= "BI_ActivateRush";
	objLandInterface.Commands.ActivateRush.note		= LanguageConvertString(idLngFile, "land_ActivateRush");

	// список пользовательских картинок
		// cancel icon
	objLandInterface.UserIcons.cancel.enable = true;
	objLandInterface.UserIcons.cancel.pic = calcTextureIndex(0, 1);
	objLandInterface.UserIcons.cancel.selPic = calcSelectedTextureIndex(0, 1);
	objLandInterface.UserIcons.cancel.tex = 3;
	objLandInterface.UserIcons.cancel.name = "cancel";

	LanguageCloseFile(idLngFile);
		// go to icons
	int idxloc = FindLoadedLocation();
	string outGroupName = "";
	RecalculateHireCrew(idxloc);
	if(idxloc>=0 && CheckAttribute(&Locations[idxloc],"fastreload"))
	{
		outGroupName = Locations[idxloc].fastreload;
		CreateReloadPaths(outGroupName);
	}

	SendMessage(&objLandInterface,"l",MSG_BATTLE_LAND_START);
}

bool FindUserIcon(string id,ref uiref)
{
	aref arroot,ar; makearef(arroot,objLandInterface.UserIcons);
	for(int i=0; i<GetAttributesNum(arroot); i++)
	{
		ar = GetAttributeN(arroot,i);
		if(!CheckAttribute(ar,"name")) continue;//MAXIMUS
		if(ar.name != id) continue;
		uiref = ar;
		return true;
	}
	return false;
}

void BLI_SetShowParameters()
{
	aref ar; makearef(ar,objLandInterface.Parameters);

	ar.shadowH = RecalculateVIcon(28);
	ar.shadowW = RecalculateHIcon(20);
	ar.shadowTOP = RecalculateVIcon(18);
	ar.widthCom = RecalculateHIcon(64);
	ar.heightCom = RecalculateVIcon(64);
	ar.leftPosCom = sti(showWindow.left)+RecalculateHIcon(16);
	ar.topPosCom = sti(showWindow.bottom)-RecalculateVIcon(80);
	ar.distCom = RecalculateHIcon(8);

	ar.widthHealth = RecalculateHIcon(64);
	ar.heightHealth = RecalculateVIcon(16);
	ar.distHealth = RecalculateVIcon(4);

	// высота и отступ для количества зарядов пистолета
	ar.GunShootHeight = RecalculateHIcon(16);
	ar.GunShootSpace = RecalculateVIcon(2);

	ar.AlarmColorLight	= argb(255,128,128,128);
	ar.AlarmColorDark	= argb(255,148,38,38);
	ar.PoisonColorLight	= argb(255,128,128,128);
	ar.PoisonColorDark	= argb(255,38,148,38);
	ar.AlarmBlindUpTime		= 0.3;
	ar.AlarmBlindDownTime	= 0.7;

	ar.DoShowCommandos = true;
	ar.CommandosQuantity = OFFICER_MAX;

	ar.shadowTexture = "battle_interface\portraits_shadow.tga";

//MAXIMUS: fixed officers-icons - we'll see proper icon for each officer in any location -->
	//SetOfficerTexture(0);
	//SetOfficerTexture(1);
	//SetOfficerTexture(2);
	//SetOfficerTexture(3);
	for(int i=0; i<sti(ar.CommandosQuantity); i++)
	{
		SetOfficerTexture(i);
	}
//MAXIMUS: fixed officers-icons - we'll see proper icon for each officer in any location <--

	ar.stateTexture = "battle_interface\officerstate.tga";
	ar.gunChargeTexture = "battle_interface\guncharge.tga";

	ar.iconHorzQuantity = 8;
	ar.iconVertQuantity = 4;
	BLI_SetCommandParameters();
	BLI_SetMassageParameters();
}

void BLI_SetCommandParameters()
{
	objLandInterface.CommandShowParam.maxShowQuantity = 10;
	objLandInterface.CommandShowParam.iconDistance = RecalculateHIcon(4);
	objLandInterface.CommandShowParam.iconWidth = RecalculateHIcon(64);
	objLandInterface.CommandShowParam.iconHeight = RecalculateVIcon(64);
	objLandInterface.CommandShowParam.leftIconsOffset = sti(showWindow.left)+RecalculateHIcon(16);
	objLandInterface.CommandShowParam.downIconsOffset = sti(showWindow.bottom)-RecalculateVIcon(80);
	objLandInterface.CommandShowParam.buttonWidth = RecalculateHIcon(8);
	objLandInterface.CommandShowParam.buttonHeight = RecalculateVIcon(64);
	objLandInterface.CommandShowParam.buttonOffset = RecalculateHIcon(4);
	objLandInterface.CommandShowParam.buttonTexture = "battle_interface\lr_buttons.tga";
	objLandInterface.CommandShowParam.shipStateWidth = RecalculateHIcon(64);
	objLandInterface.CommandShowParam.shipStateHeight = RecalculateVIcon(16);
	objLandInterface.CommandShowParam.shipStateTexture = "battle_interface\indicators.tga";
	objLandInterface.CommandShowParam.shipStateOffset = RecalculateVIcon(0);
	objLandInterface.CommandShowParam.commandFont = "bold_numbers";
	objLandInterface.CommandShowParam.printXOffset = RecalculateHIcon(32);
	objLandInterface.CommandShowParam.printYOffset = RecalculateVIcon(-26);
	objLandInterface.CommandShowParam.commandNoteFont = "interface_normal";
	objLandInterface.CommandShowParam.noteXOffset = RecalculateHIcon(0);
	objLandInterface.CommandShowParam.noteYOffset = RecalculateVIcon(-28);
	objLandInterface.CommandShowParam.argbTFactorColor = argb(256,64,64,64);
}

void BLI_SetMassageParameters()
{
	objLandInterface.MessageIcons.IconWidth = RecalculateHIcon(64);
	objLandInterface.MessageIcons.IconHeight = RecalculateVIcon(24);
	objLandInterface.MessageIcons.IconDist = RecalculateVIcon(2);
	objLandInterface.MessageIcons.IconBottom = sti(showWindow.bottom)-RecalculateHIcon(80+40);
	objLandInterface.MessageIcons.IconMaxQuantity = 2;
	objLandInterface.MessageIcons.BlendTime = 3.0;
	objLandInterface.MessageIcons.FallSpeed = 22.0;
	objLandInterface.MessageIcons.argbHighBlind = argb(255,128,128,128);
	objLandInterface.MessageIcons.argbLowBlind = argb(255,68,68,68);
	objLandInterface.MessageIcons.BlindUpTime = 0.5;
	objLandInterface.MessageIcons.BlindDownTime = 1.0;
	objLandInterface.MessageIcons.texture = "battle_interface\MessageIcons.tga";
	objLandInterface.MessageIcons.TexHSize = 2;
	objLandInterface.MessageIcons.TexVSize = 2;
}

void BLI_UpdateObjectData()
{
	objLandInterface.data.alarm = LAi_group_GetPlayerAlarm();
	bool bIsRiskAlarm = LAi_group_IsActivePlayerAlarm();
	if(sti(objLandInterface.data.riskAlarm)!=bIsRiskAlarm) BLI_RefreshCommandMenu();
	objLandInterface.data.riskAlarm = bIsRiskAlarm;
	ref mainCh = GetMainCharacter();
	aref ar,arItm;
	int i,cn;
	ref curCh;
	string attrName;
	for(i=0; i<OFFICER_MAX; i++)
	{
		attrName = "id"+i;
		cn = GetOfficersIndex(mainCh,i);
		if(cn==-1 || !IsEntity(&Characters[cn]))
		{
			DeleteAttribute(&objLandInterface,"data.icons."+attrName);
			continue;
		}
		curCh = GetCharacter(cn);
		makearef(ar,objLandInterface.data.icons.(attrName));
		ar.picture = curCh.FaceId;
		ar.health = LAi_GetCharacterRelHP(curCh);
		ar.charge = LAi_GetCharacterRelCharge(curCh);//gun's reload speed (calculates from charges quantity)
		ar.shootMax = LAi_GetCharacterChargeQuant(curCh);//maximal charges quantity (for current gun)
		ar.shootCur = LAi_GetCharacterChargeCur(curCh);//actual charges quantity
		ar.poison = LAi_IsPoison(curCh);
	}
	CheckOfficers();//MAXIMUS: updates officers-icons
	SearchAdditionalLocators();//MAXIMUS: makes box from corpse with hand-icon in the top-left corner
	PostEvent("evntBLI_Update",ACTIONMENU_UPDATE_PERIOD);//MAXIMUS (was BLI_UPDATE_PERIOD)
}

void SearchAdditionalLocators()
{
	//Removed by Levis to make sure corpses also work on locators
	/*if(chrWaitReloadLocator!="")
	{
		if(!CheckAttribute(GetMainCharacter(),"boxname.label"))
		{
			if(!CheckAttribute(GetMainCharacter(),"fakereload.locator")) { CharacterBoxUpdate(GetMainCharacter(),"",false); return; }
		}
	}*/
	ref chr = GetMainCharacter();
	if(chr.location=="") return;
	//if(FindLocation(chr.location)<0) return;
	if(!IsEntity(loadedLocation)) return; //Levis changed to use loadedlocation
	if(CheckAttribute(chr,"condition") && chr.condition=="reload") return;

	if(CheckAttribute(chr,"autoreload") && !CheckAttribute(chr,"autoreload.locator"))
	{
		if(chr.location!=chr.autoreload.location)
		{
			DeleteAttribute(chr,"autoreload.location");
			DeleteAttribute(chr,"autoreload");
		}
	}
	string locationID = chr.location;
	string curLocName = "";
	string curLocGroup = "";
	//ref lcn = &Locations[FindLocation(locationID)]; //Levis changed to loadedlocation
	ref lcn = loadedLocation;
	aref rootLocators, curGrp, curLoc;
	int i, j, itmIdx;
	bool bPos, exacLocator;

	makearef(rootLocators,lcn.locators);
	for(i=0; i<GetAttributesNum(rootLocators); i++)
	{
		curGrp = GetAttributeN(rootLocators,i);
		curLocGroup = GetAttributeName(curGrp);
		for(j=0; j<GetAttributesNum(curGrp); j++)
		{
			curLoc = GetAttributeN(curGrp,j);
			curLocName = GetAttributeName(curLoc);
			exacLocator = false;
			bPos = false;
			if(CheckAttribute(lcn, "locators."+curLocGroup+"."+curLocName+".tmpLocator")) exacLocator = true;
			if(!exacLocator) continue;
			if(exacLocator)
			{
				int itemN = sti(lcn.locators.(curLocGroup).(curLocName).corpseIdx);
				bPos = CheckCharPosition(stf(lcn.locators.(curLocGroup).(curLocName).x), stf(lcn.locators.(curLocGroup).(curLocName).y), stf(lcn.locators.(curLocGroup).(curLocName).z));
				if(bPos)
				{
					switch(curLocGroup)
					{
						case "box":
							chr.boxname = curLocName;
// KK -->
							if (HasSubStr(curLocName, "corpse_box")) {
								int corpseidx = -1;
								if (CheckAttribute(lcn, "locators.box." + curLocName + ".corpseIdx")) corpseidx = sti(lcn.locators.box.(curLocName).corpseIdx);
								//ClearAllLogStrings();
								if (corpseidx >= 0 && CheckAttribute(characters[corpseidx], "old.name") == true && CheckAttribute(characters[corpseidx], "old.lastname") == true)
									chr.boxname.label = XI_ConvertString("BodyOf") + characters[corpseidx].old.name + " " + characters[corpseidx].old.lastname;
								else
									chr.boxname.label = "Corpse";
								Log_SetActiveAction("Corpse");
								chr.boxname.label = lcn.locators.(curLocGroup).(curLocName).text;
							}
							if(HasSubStr(curLocName, "treasure_box"))
							{
								Log_SetActiveAction("OpenBox");
								chr.boxname.label = "Treasure";
							}
							if(HasSubStr(curLocName, "hidden_box"))
							{
								Log_SetActiveAction("OpenBox");
								chr.boxname.label = "Hidden Things";
								Box_FillBox(lcn, curLocName, false);
							}
							CharacterBoxUpdate(chr,chr.boxname.label,true);
						break;

						case "items":
							if(itemN>=0)
							{
								Log_SetActiveAction("Pick");
								chr.activeItem = itemN;
								chr.activeLocator = curLocName;
								chr.activeRandItem = false;
								chr.activeItem.pick = true;
							}
						break;

						case "reload":
							chr.fakereload.locator = curLocName;
							EnterToReloadLocator(chr);
						break;

						case "item":
							if(HasSubStr(curLocName, "666") || HasSubStr(curLocName, "999") || HasSubStr(curLocName, "777"))
							{
								chr.activeItem = -1;
								chr.activeLocator = curLocName;
								chr.activeRandItem = false;
								chr.activeItem.pick = false;
								chr.activeItem.Action = "Action";
								chr.activeItem.Action.label = "alarm_bell";
								if(HasSubStr(curLocName, "666"))
								{
									chr.activeItem.Action.label = "steereing_wheel";
									if(!CheckAttribute(chr,"location.first") && !bSeaActive) Log_SetActiveAction(chr.activeItem.Action);
								}
								if(HasSubStr(curLocName, "777"))
								{
									chr.activeItem.Action.label = lcn.locators.(curLocGroup).(curLocName).text;
									Log_SetActiveAction(chr.activeItem.Action);
								}
								if(HasSubStr(curLocName, "999")) Log_SetActiveAction(chr.activeItem.Action);
							}
						break;
					}
				}
				else
				{
					switch(curLocGroup)
					{
						case "box":
							if(CheckAttribute(chr,"boxname") && chr.boxname==curLocName)
							{
								DeleteAttribute(chr,"boxname.label");
								DeleteAttribute(chr,"boxname");
								CharacterBoxUpdate(chr,"",false);
								if(!CheckAttribute(chr,"activeItem")) { CheckCharacterAction(); }
								else
								{
									if(chr.activeItem=="") { CheckCharacterAction(); }
									else
									{
										if(CheckAttribute(chr,"activeItem.pick") && chr.activeItem.pick!="1") { CheckCharacterAction(); }
									}
								}
							}
						break;

						case "items":
							if(itemN>=0)
							{
								if(!CheckAttribute(chr,"boxname")) { CheckCharacterAction(); }
								chr.activeItem = "";
								chr.activeLocator = "";
								chr.activeItem.pick = false;
							}
						break;

						case "reload":
							if(CheckAttribute(chr,"fakereload.locator") && chr.fakereload.locator==curLocName)
							{
								ExitFromReloadLocator(chr);
								if(!CheckAttribute(chr,"activeItem")) { CheckCharacterAction(); }
								else
								{
									if(chr.activeItem=="") { CheckCharacterAction(); }
									else { if(CheckAttribute(chr,"activeItem.pick") && chr.activeItem.pick!="1") { CheckCharacterAction(); } }
								}
							}
						break;

						case "item":
							Item_OnExitLocator();
						break;
					}
				}
			}
		}
	}
	if(!CheckAttribute(chr,"boxname"))
	{
		if(!CheckAttribute(chr,"activeItem")) { CheckCharacterAction(); }
		else
		{
			if(chr.activeItem=="") { CheckCharacterAction(); }
			else
			{
				if(CheckAttribute(chr,"activeItem.pick") && chr.activeItem.pick!="1") { CheckCharacterAction(); }
			}
		}
	}
	BLI_RefreshCommandMenu();
}

void CharacterBoxUpdate(ref chr, string label, bool bClear)
{
	if(dialogRun || dialogSelf || label=="")
	{
		if(bClear) ClearAllLogStrings();
		if(CheckAttribute(chr,"BoxName.update")) DeleteAttribute(chr,"BoxName.update");
		//if(chrWaitReloadLocator=="") RestoreLogInterface();
		return;
	}

	if (!CheckAttribute(chr,"boxname")) chr.boxname = ""; // KK
	chr.BoxName.update = true;
// KK -->
	//ClearAllLogStrings();
	//SetUpLogInterface(label,COLOR_GREEN_LIGHT,16,80);
	Log_SetActionLabel(TranslateString("", label));
// <-- KK
//	Log_SetStringToLog(SpellString("", label));
}

#event_handler("procChrOpenBox","BoxNameUpdate");
void BoxNameUpdate()
{
	ref mchr = GetMainCharacter(); // KK
	if(dialogRun || dialogSelf)
	{
		ClearAllLogStrings();
		if (CheckAttribute(mchr, "BoxName.update")) DeleteAttribute(mchr, "BoxName.update");
		if (chrWaitReloadLocator == "") RestoreLogInterface();
		return;
	}

	string label = GetEventData();
	mchr.boxname.boxlabel = label; // KK
	mchr.BoxName.update = true;
// KK -->
	//ClearAllLogStrings();
	//SetUpLogInterface(label,COLOR_GREEN_LIGHT,16,80);
	Log_SetActionLabel(TranslateString("", label));
// <-- KK
//	Log_SetStringToLog(SpellString("", label));
//	PostEvent("procChrOpenBox",125,"s",label);
}

void SetLandInterfaceShow(bool commandosShow)
{
	SendMessage(&objLandInterface,"ll",MSG_BATTLE_LAND_SET_SHOW,commandosShow);
}

void BLI_SetPossibleCommands()
{
	int idLngFile = LanguageOpenFile("commands_name.txt");
	ref mchref = GetMainCharacter();
	int chrMode = SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"IsFightMode");

	bool bTmpBool = false;
	bool bUseCommand = false;
	int i;
	aref rootcom,curcom;
	makearef(rootcom,objLandInterface.Commands);
	for(i=0; i<GetAttributesNum(rootcom); i++)
	{
		curcom = GetAttributeN(rootcom,i);
		curcom.enable = false;
	}

	if(chrMode==0)
	{
		bTmpBool = true;
		if(LAi_group_IsActivePlayerAlarm()) bTmpBool = false;
		if(!LAi_IsCharacterControl(mchref)) bTmpBool = false;
		if(bDisableFastReload)	bTmpBool = false;
		if(!IsEnableFastTravel()) bTmpBool = false;
		i = -1;
		if(CheckAttribute(mchref,"dialogready")) i=sti(mchref.dialogready);
		if(i>=0)
		{
			objLandInterface.Commands.DialogStart.enable = CheckAttribute(&Characters[i],"Dialog.FileName")==true && Characters[i].Dialog.FileName!="";//true;//MAXIMUS
			if( IsOfficer(&Characters[i]) )
			{
	//JRH-->
				if(CheckAttribute(mchref,"quest.exchange_items_officer") && mchref.quest.exchange_items_officer == "no")
				{
					objLandInterface.Commands.ItemsChange.enable = false;
				}
	//<--JRH
				else objLandInterface.Commands.ItemsChange.enable = true;
			}
			else
			{
				if (CheckAttribute(&Characters[i],"InterfaceFlags.ItemsChange") && Characters[i].InterfaceFlags.ItemsChange != "0")
				{
					objLandInterface.Commands.ItemsChange.enable = true;
				}
			}
		}
	}

	objLandInterface.Commands.FastReload.enable	= bTmpBool==true; // KK causes more problems than good && objLandInterface.Commands.DialogStart.enable==false;//MAXIMUS
	bUseCommand = true;

	if(GetCharacterPerkUsing(mchref,"Rush"))
	{
		objLandInterface.Commands.ActivateRush.enable = true;
		bUseCommand = true;
	}

	if( CanBeUseItem(mchref) )
	{
		objLandInterface.Commands.ItemsUse.enable = true;
		bUseCommand = true;
	}

	if(CheckAttribute(mchref,"boxname"))//MAXIMUS -->
	{
		objLandInterface.Commands.UseBox.enable	= false;
		objLandInterface.Commands.UseBarrel.enable	= false;
		objLandInterface.Commands.UseCorpse.enable	= false;
		if(HasSubStr(mchref.boxname,"corpse_box")) objLandInterface.Commands.UseCorpse.enable = true;
		if(HasSubStr(mchref.boxname,"gunpowder"))
		{
			objLandInterface.Commands.UseBarrel.enable = true;
			objLandInterface.Commands.UseBarrel.note = LanguageConvertString(idLngFile, "land_UseBarrel");
			if(LAi_IsBoardingProcess() && mchref.location!=GetShipLocationID(mchref) && mchref.location!=GetShipLocationID(boarding_enemy))
			{
				objLandInterface.Commands.UseBarrel.note = LanguageConvertString(idLngFile, "land_UseStorage");
			}
			if(ownDeckStarted() && mchref.location!=GetCharacterShipQDeck(mchref))
			{
				objLandInterface.Commands.UseBarrel.note = LanguageConvertString(idLngFile, "land_UseStorage");
			}
		}
		objLandInterface.Commands.UseBox.enable	= !HasSubStr(mchref.boxname,"gunpowder") && !HasSubStr(mchref.boxname,"corpse");
		bUseCommand = true;
	}//MAXIMUS <--
	
	if( CheckAttribute(mchref,"activeItem") && mchref.activeItem!="" )
	{
		bUseCommand = true;
		if( CheckAttribute(mchref,"activeItem.pick") && mchref.activeItem.pick=="1" )
		{
			objLandInterface.Commands.TakeItem.enable = true;
		}
		else
		{
			objLandInterface.Commands.PlaceItem.enable = true;
		}
	}

	if(CheckForReload()) // KK //MAXIMUS
	{
		bUseCommand = true;
		objLandInterface.Commands.OutDoor.enable = true;
	}
// KK -->
	/*if(bMutinyDeckStarted || LAi_IsBoardingProcess())
	{
		objLandInterface.Commands.OutDoor.enable = false;
		bUseCommand = false;
	}*/
// <-- KK

// KK -[changed by MAXIMUS: isn't simpler and faster? Also without lags ;)]->
	objLandInterface.Commands.ExitDeck.enable = bDeckEnter && iShipCaptain == GetMainCharacterIndex() && !bQuestDisableSeaEnter; // PB
	objLandInterface.Commands.EnterShip.enable = bTmpBool && !LAi_IsBoardingProcess();
	if (bDeckEnter) objLandInterface.Commands.EnterShip.enable = GetCompanionQuantity(mchref) > 1;
	int curlocidx = FindLoadedLocation();
	int portlocidx = -1;
	int cn = -1;
	if(CheckAttribute(mchref, "location.from_sea")) portlocidx = FindLocation(mchref.location.from_sea);
	if(!bSeaActive) bTmpBool = sti(objLandInterface.Commands.OutDoor.enable) == true;//MAXIMUS: full check already done above :) // KK
	//else bTmpBool = CheckAttribute(mchref, "Interlocutor.update")==false;
	if (bTmpBool == true && VISIT_DECK == 1 && curLocIdx != -1 && portlocidx != -1)//MAXIMUS: I doubt, that even it's needed (curLocIdx!=-1 && portlocidx!=-1)...
	{
		if(!bMutinyDeckStarted && !LAi_IsBoardingProcess())
		{
			bTmpBool = chrWaitReloadLocator != "" && CheckAttribute(mchref, "reloadStatus") == true;
			if (bTmpBool == true && mchref.reloadStatus != "ToSea" && mchref.reloadStatus != "ToBoat") bTmpBool = false;
			if (bTmpBool == true && bDeckEnter) bTmpBool = false; // PB: Don't do this on your ship's deck
			if (bTmpBool) {
				if (bQuestDisableSeaEnter) bTmpBool = false;
			}
			objLandInterface.Commands.ReloadFromLandToSea.enable = bTmpBool;
		}
	}

	bTmpBool = true;
	if(bSeaActive) bTmpBool = bMapEnter;
	objLandInterface.Commands.Back.enable = sti(objLandInterface.Commands.ExitDeck.enable) == true && bTmpBool == true && bDeckEnter == true && LandLocationIdx != -1;
	bUseCommand = true;
// MAXIMUS Deck <--
// <-[changed by MAXIMUS: isn't simpler and faster? Also without lags ;)]- KK

	if(!bUseCommand)
	{
		SendMessage(&objLandInterface,"llllll",BI_IN_SET_COMMAND_MODE,0,-1,-1,-1,-1);
	}
	LanguageCloseFile(idLngFile);
}

// MAXIMUS // KK -->
bool CheckForReload()
{
	ref mchref = GetMainCharacter();
	if (sti(GetReloadMapAttrib(FindLoadedLocation(), chrWaitReloadLocator, "disable")) == true) return false;
	string go = GetReloadMapAttrib(FindLoadedLocation(), chrWaitReloadLocator, "go");
	if (go == "") return false;
	//int islandidx = GetCharacterCurrentIsland(mchref);
	if (GetIslandIDByLocationID(Locations[FindLoadedLocation()].id) == go && CheckAttribute(mchref, "location.from_sea") == true && Locations[FindLocation(mchref.location.from_sea)].island != go) return false;
	if (chrWaitReloadLocator != "" || CheckAttribute(mchref, "fakereload.locator")) return true;
	if (go != "") return true;
	return false;
}
// <-- MAXIMUS // KK

void BLI_evntRefreshCommandMenu()
{
	DelEventHandler("frame","BLI_evntRefreshCommandMenu");
	BLI_RefreshCommandMenu();
}
void BLI_RefreshCommandMenu()
{
	SendMessage(&objLandInterface,"lllll",BI_IN_SET_COMMAND_MODE,-1,-1,-1,-1,-1);
}
/*
void procFindDialogChar()
{
	ref mchref = GetMainCharacter();
	int dlgChar = -1;
	// NK comment this out, enable in boarding. 05-07-12 - if(!LAi_IsBoardingProcess())
	dlgChar = SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");

	int oldDlgChar = -1;
	if(CheckAttribute(mchref,"dialogready")) oldDlgChar = sti(mchref.dialogready);

	if(dlgChar!=oldDlgChar)
	{
		mchref.dialogready = dlgChar;
		BLI_RefreshCommandMenu();
	// PB: Auto show name -->
	// Coding by AlexusB, automated by Viper, made toggleable in BS.h by NK
		if(!CheckAttribute(mchref,"reloadStatus.update") && !dialogRun && !dialogSelf)
		{
			ref NPChar = GetCharacter(dlgChar);
			if (dlgChar>0 && AUTO_SHOW_NAME_HP)
			{
				if(CheckAttribute(NPChar,"name"))
				{
					if(CheckAttribute(NPChar, "corpse")) Log_SetStringToLog(NPChar.name + " " + NPChar.lastname + ": " + XI_ConvertString("Rank") + ": " + NPChar.rank + " " + XI_ConvertString("HP") + ": 0/" + makeint(NPChar.chr_ai.hp_max) ) ;
					else Log_SetStringToLog(GetMyFullName(NPChar) + " " + XI_ConvertString("Rank") + ": " + NPChar.rank + " " + XI_ConvertString("HP") + ": "+ makeint(NPChar.chr_ai.hp) + "/" + makeint(NPChar.chr_ai.hp_max) ) ;
				}
			}
		}
	}

	PostEvent("evntFindDialogChar",500);
	// PB: Auto show name <--
}*/

//MAXIMUS: -[small improvement for these processes]->
void procFindDialogChar()
{
	ref mchref = GetMainCharacter();
	int dlgChar = SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
	mchref.dialogready = dlgChar;

	if(dlgChar==-1)
	{
		if (bInterlocutorActive) bInterlocutorActive = false;
		RestoreLogActions();
		// KK if(CheckAttribute(mchref,"Interlocutor.update")) DeleteAttribute(mchref,"Interlocutor.update");
		// KK if(CheckAttribute(mchref,"Interlocutor.index")) DeleteAttribute(mchref,"Interlocutor.index");
		BLI_RefreshCommandMenu();
		CheckCharacterAction();
		PostEvent("evntFindDialogChar",ACTIONMENU_UPDATE_PERIOD);
		return;
	}

	int oldDlgChar = -1;
	if(CheckAttribute(mchref,"dialogready")) oldDlgChar = sti(mchref.dialogready);

// KK -->
	bool bShow = !CheckAttribute(mchref,"boxname") && !CheckAttribute(mchref,"activeItem.Action");
	if (bShow) {
		bShow = chrWaitReloadLocator == "";
		if (bShow == false && g_ActiveActionName == "Closed") bShow = true;
	}
// <-- KK
	string chrName = "";
	ref NPChar = &Nullcharacter;
	if(dlgChar!=oldDlgChar) mchref.dialogready = dlgChar;
	BLI_RefreshCommandMenu();
	if(AUTO_SHOW_NAME_HP)//MAXIMUS: actually we not need to show HP - we can see all info by KEY_O. So, I leave only name here
	{
		NPChar = GetCharacter(dlgChar);
// KK -->
		chrName = GetMyFullName(NPChar);
		if (CheckAttribute(NPChar, "corpse") == true && chrName != " ") chrName = FirstLetter(TranslateString("","body_of_"+NPChar.sex)) + " " + chrName;
		if (CheckAttribute(NPChar,"chr_ai.type") && NPChar.chr_ai.type == "Building") chrName = ""; // PB: Don't show this for buildings
// <-- KK
		bInterlocutorActive = bShow; // KK
		PortraitUpdate(mchref,NPChar,chrName,bShow);
	}
}

void PortraitUpdate(ref mchref, ref NPChar, string chrName, bool bShow)
{
// KK -->
	//if (LAi_boarding_process && !Surrendered) return; //Removed by levis for corpsemode 3
	if (LAi_IsDead(mchref)) {
		Log_SetActiveAction("Nothing");
		//return; //Removed by levis for corpsemode 3
	}
// <-- KK

	if(bShow == true && chrName != "" && CheckAttribute(NPChar, "FaceId") && sti(NPChar.FaceId) != -1) {
		string facePict = "INTERFACES\PORTRAITS\64\face_" + sti(NPChar.FaceId) + ".tga";
		if (CheckAttribute(NPChar, "corpse") || FindFile("RESOURCE\TEXTURES\INTERFACES\PORTRAITS\64","*.tga.tx","face_"+sti(NPChar.FaceId)+".tga.tx")=="") facePict = "INTERFACES\PORTRAITS\128\face_skull.tga";
		// KK SetUpLogInterface("",COLOR_GREEN_LIGHT,16,0);
		SetUpLogActions(facePict, 1, 1, 0);
		Log_SetActiveAction("TalkWith");
		// KK mchref.Interlocutor.update = true;
		// KK mchref.Interlocutor.index = sti(NPChar.index);
		InterlocutorUpdate(mchref, NPChar, chrName);
	}

	if(!bShow) {
		RestoreLogActions();
		// KK if(CheckAttribute(mchref,"Interlocutor.update")) DeleteAttribute(mchref,"Interlocutor.update");
		// KK if(CheckAttribute(mchref,"Interlocutor.index")) DeleteAttribute(mchref,"Interlocutor.index");
		if(chrWaitReloadLocator=="" && !CheckAttribute(mchref,"boxname") && !CheckAttribute(mchref,"activeItem.Action"))
		{
			RestoreLogInterface();
		}
		CheckReloadAction(mchref, "");
		if (CheckAttribute(mchref, "BoxName")) DeleteAttribute(mchref, "BoxName.update");
		if (CheckAttribute(mchref, "activeItem")) DeleteAttribute(mchref, "activeItem.update");
		CheckCharacterAction();

		PostEvent("evntFindDialogChar",50);
	}
}

void InterlocutorUpdate(ref chr, ref NPChar, string name)
{
	if(!IsMainCharacter(chr)) return;

	bool bHide = CheckAttribute(chr, "condition")==true && chr.condition=="reload";
	if(!bHide) bHide = name=="";

	if(FindLocation(chr.location)==-1 || /*!CheckAttribute(chr,"Interlocutor.update") ||*/ bHide || chrWaitReloadLocator!="")
	{
		PortraitUpdate(chr, NPChar, "", false);
		return;
	}

	//ClearAllLogStrings();
	Log_SetActionLabel(name);
//	Log_SetStringToLog(name);
	PostEvent("evntFindDialogChar",ACTIONMENU_UPDATE_PERIOD);
}

#event_handler("UpdateLocator","BLI_ChrEnterToLocation");
void BLI_ChrEnterToLocation()
{
	aref loc = GetEventData(); //moved up by levis
	aref chr = GetEventData(); //moved up by levis
	if(HasSubStr(GetAttribute(GetMainCharacter(), "boxname"),"corpse_box")) return; //Levis to make sure corpses can be on locators
	DelEventHandler("frame", "BLI_evntRefreshCommandMenu");
	if(bMutinyDeckStarted || LAi_IsBoardingProcess()) return;// MAXIMUS
	if(CheckAttribute(GetMainCharacter(),"autoreload")) return;// MAXIMUS
	string group = GetEventData();
	if(group!="reload") return;
	string locator = GetEventData();
	aref locList,locCur;
	int i,n;

	if(!IsMainCharacter(chr)) return;

	// Screwface : moved here to avoid label disappear too quickly
	if (CheckAttribute(chr, "reload.label")) DeleteAttribute(chr, "reload.label");
	// Screwface : End

	makearef(locList,loc.reload);
	n = GetAttributesNum(locList);
	for(i=0;i<n;i++)
	{
		locCur = GetAttributeN(locList,i);
		if(CheckAttribute(locCur,"name")) { if(locCur.name == locator) break; }
}
	if(i<n)
	{
		if(CheckAttribute(locCur,"go"))
		{
			i = FindLocation(locCur.go);
// KK -->
			if (i >= 0 && CheckAttribute(&locations[i], "id.label")) {
				string label = TranslateString("", locations[i].id.label);
				Preprocessor_Add("island_name", XI_ConvertString(GetIslandNameByLocationID(chr.location)));
				if (CheckAttribute(&Locations[i], "townsack")) Preprocessor_Add("town_name", FindTownName(Locations[i].townsack));
				chr.reload.label = PreprocessText(label);
				Log_SetActionLabel(chr.reload.label);
				//Log_SetStringToLog(PreprocessText(label)); // returned by MAXIMUS - language switching mod
				Preprocessor_Remove("town_name");
				Preprocessor_Remove("island_name");
			}
			if (i < 0 && CheckAttribute(locCur, "label") == true) {
				chr.reload.label = locCur.label;
				Log_SetActionLabel(TranslateString("", locCur.label));
			}
// <-- KK
		}
	}
	SetEventHandler("frame","BLI_evntRefreshCommandMenu",1);
	//LanguageCloseFile(tmpLangFileID);
}

#event_handler("procChrEnterToLocator","updateChrEntryToLocator");
void updateChrEntryToLocator()
{
	aref chr = GetEventData();
	string label = GetEventData();

	if(FindLoadedLocation()==-1 || label=="") { BreakLabelUpdate(chr); return; }
	if(dialogRun || dialogSelf) { BreakLabelUpdate(chr); return; }
	if(CheckAttribute(chr, "condition") && chr.condition=="reload") { BreakLabelUpdate(chr); return; }
	if(CheckAttribute(chr,"activeItem.Action")) { BreakLabelUpdate(chr); return; }
	if(chrWaitReloadLocator=="") { BreakLabelUpdate(chr); return; }

// KK -->
	//ClearAllLogStrings();
	//SetUpLogInterface(label,COLOR_GREEN_LIGHT,16,80);
	Log_SetActionLabel(TranslateString("", label));
// <-- KK
//	Log_SetStringToLog(label);
	PostEvent("procChrEnterToLocator",ACTIONMENU_UPDATE_PERIOD,"is",chr,label);
}

void BreakLabelUpdate(aref chr)
{
	if(CheckAttribute(chr,"reloadStatus.label")) DeleteAttribute(chr,"reloadStatus.label");
	if(CheckAttribute(chr,"reloadStatus.update")) DeleteAttribute(chr,"reloadStatus.update");
	if(!CheckAttribute(chr,"boxname") && !CheckAttribute(chr,"activeItem.Action")) { RestoreLogInterface(); }
}

void RestoreLogInterface()
{
	if(!CheckAttribute(IActions,"log.changed")) return;
	//CreateLogEnvironment();
	DeleteAttribute(IActions,"log.changed");

	//SendMessage(&ILog,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
	//CheckCharacterAction();
	//Log_SetStringToLog("");
}

void RestoreLogActions()
{
	if(!CheckAttribute(IActions,"ActiveActions.changed")) return;
	CreateLandActionsEnvironment();
	DeleteAttribute(IActions,"ActiveActions.changed");

	SendMessage(&IActions,"lll",LOG_AND_ACTIONS_CHANGE,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.ActionLabel));
	if(chrWaitReloadLocator!="") CheckReloadAction(GetMainCharacter(), "");
	else CheckCharacterAction();
}

void SetUpLogInterface(string strData, int stColor, int stLeft, int stTop)
{//MAXIMUS: log-string can have any color and can be shown in any place (COLOR_*** can be replaced with argb(*,*,*,*))
	int stepLeft = sti(showWindow.left)+16;
	if(sti(stLeft)>0) stepLeft = sti(showWindow.left)+sti(stLeft);

	int stepUp = sti(showWindow.top)+80;
	stepUp = sti(showWindow.top) + 1;
	if(sti(stTop)>0) stepUp = sti(showWindow.top)+sti(stTop);
// <-- KK

	int stepColor = stColor;
	if (stColor == -1) stepColor = argb(0,255,255,255);//default
	//if(strData!="") { if(HasSubStr(strData,"careful") || HasSubStr(strData,"warning")) stepColor = COLOR_RED_LIGHT; }

	IActions.Log.left = stepLeft;
	IActions.Log.up = stepUp;
	IActions.Log.color = stepColor;
	IActions.log.changed = true;

	SendMessage(&ILog,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
	CheckCharacterAction();
}

void SetUpLogActions(string textPath, int horzQuantity, int vertQuantity, int picNum)
{//MAXIMUS: action-icon can use any texture
	IActions.ActiveActions.TextureName = textPath;
	IActions.ActiveActions.horzQ = horzQuantity;
	IActions.ActiveActions.vertQ = vertQuantity;
	IActions.ActiveActions.TalkWith.IconNum = picNum;
	IActions.ActiveActions.changed = true;

	SendMessage(&IActions,"lll",LOG_AND_ACTIONS_CHANGE,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.ActionLabel));
}
//MAXIMUS: <-[small improvement for these processes]-

void BLI_ChrExitFromLocation()
{
	SetEventHandler("frame","BLI_evntRefreshCommandMenu",1);
}

void LI_Reload()
{
/*	SetEvemt
	chrCharacterKeys
	ref mc = GetMainCharacter();
	Reload(chrWaitReloadRef, chrWaitReloadLocator, mc.location);
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;*/
	Event("Control Activation","s","ChrAction");
}

bool SetUsedPotionIcons()
{
	aref arItm, ar, uiref;
	int i, itmIdx, nq;
	ref mc = GetMainCharacter();

	bool bUsed = false;

	makearef(uiref,objLandInterface.UserIcons);
	nq = GetAttributesNum(uiref);
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		if( CheckAttribute(ar,"potion") ) {
			DeleteAttribute(uiref,GetAttributeName(ar));
			nq--; i--;
		}
	}

	string UI_name;
	int UI_idx = 0;

	itmIdx = FindPotionFromChr(mc, &arItm, 0);
	while(itmIdx>=0)
	{
		if( EnablePotionUsing(mc,arItm) )
		{
			UI_idx++;
			UI_name = "potion"+UI_idx;
			int textureIndex = GetPotionTexture(arItm);
			string textureAttr = "t" + textureIndex;
			int textureColumns = objLandInterface.CommandTextures.list.(textureAttr).columns;
			objLandInterface.UserIcons.(UI_name).enable = true;
			objLandInterface.UserIcons.(UI_name).pic = calcTextureIndex(GetPotionPicture(arItm), textureColumns);
			objLandInterface.UserIcons.(UI_name).selPic = calcSelectedTextureIndex(GetPotionPicture(arItm), textureColumns);
			objLandInterface.UserIcons.(UI_name).tex = textureIndex;
			objLandInterface.UserIcons.(UI_name).name = UI_name;
			objLandInterface.UserIcons.(UI_name).potion = arItm.id;
			objLandInterface.UserIcons.(UI_name).note = GetItemNameByID(arItm.id) + ": " + GetCharacterItem(mc, arItm.id); // KK
			bUsed = true;
		}
		itmIdx = FindPotionFromChr(mc, &arItm, itmIdx+1);
	}
	//Levis -->
	if(CheckCharacterItem(mc,"opium"))
	{
		UI_idx++;
		UI_name = "potion"+UI_idx;
		objLandInterface.UserIcons.(UI_name).enable = true;
		objLandInterface.UserIcons.(UI_name).pic = calcTextureIndex(0, 4);
		objLandInterface.UserIcons.(UI_name).selPic = calcSelectedTextureIndex(0, 4);
		objLandInterface.UserIcons.(UI_name).tex = 6;
		objLandInterface.UserIcons.(UI_name).name = UI_name;
		objLandInterface.UserIcons.(UI_name).potion = "opium";
		objLandInterface.UserIcons.(UI_name).note = "Use Opium";
		bUsed = true;
	}
	if(CheckCharacterItem(mc,"vegetal"))
	{
		UI_idx++;
		UI_name = "potion"+UI_idx;
		objLandInterface.UserIcons.(UI_name).enable = true;
		objLandInterface.UserIcons.(UI_name).pic = calcTextureIndex(1, 4);
		objLandInterface.UserIcons.(UI_name).selPic = calcSelectedTextureIndex(1, 4);
		objLandInterface.UserIcons.(UI_name).tex = 6;
		objLandInterface.UserIcons.(UI_name).name = UI_name;
		objLandInterface.UserIcons.(UI_name).potion = "vegetal";
		objLandInterface.UserIcons.(UI_name).note = "Use Vegetal";
		bUsed = true;
	}
	//Levis <--
	return bUsed;
}

bool SetReloadIcons()
{
	int tmpLangFileID = LanguageOpenFile("commands_name.txt"); // KK
	int i, nq, locidx;
	aref ar, curloc, locref, locList, uiref;
	ref mc = GetMainCharacter();

	bool bUse = false;

	makearef(uiref,objLandInterface.UserIcons);
	nq = GetAttributesNum(uiref);
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		if( CheckAttribute(ar,"location") ) {
			DeleteAttribute(uiref,GetAttributeName(ar));
			nq--; i--;
		}
	}

	int idxloc = FindLoadedLocation();
	string str1,str2,fastLocName;
	string outGroupName = "";
	if(idxloc>=0 && CheckAttribute(&Locations[idxloc],"fastreload"))
	{
		outGroupName = Locations[idxloc].fastreload;
		if( CheckAttribute(&objFastReloadTable,"table."+outGroupName) )
		{
			makearef(locList,objFastReloadTable.table.(outGroupName));
			nq = GetAttributesNum(locList);
			for(i=0; i<nq; i++)
			{
				curloc = GetAttributeN(locList,i);
				if (CheckFastJump(Locations[idxloc].id, curloc.location)) {
					fastLocName = "fr_"+(i+1);
					objLandInterface.UserIcons.(fastLocName).enable = true;
					int textureIndex = 1+sti(curloc.tex);
					string textureAttr = "t" + textureIndex;
					int textureColumns = objLandInterface.CommandTextures.list.(textureAttr).columns;
					int picture = sti(curloc.pic);
					objLandInterface.UserIcons.(fastLocName).pic = calcTextureIndex(picture, textureColumns);
					objLandInterface.UserIcons.(fastLocName).selPic = calcSelectedTextureIndex(picture, textureColumns);
					objLandInterface.UserIcons.(fastLocName).tex = textureIndex;
					objLandInterface.UserIcons.(fastLocName).name = "reload"+i;
					objLandInterface.UserIcons.(fastLocName).location = curloc.location;
					objLandInterface.UserIcons.(fastLocName).note = LanguageConvertString(tmpLangFileID, curloc.note); // KK

// KK -->
					if (curloc.location == "Hold1" && GetCharacterShipCargoHoldCount(mc) > 1)
						objLandInterface.UserIcons.(fastLocName).note = LanguageConvertString(tmpLangFileID, curloc.note+"1");
					if (curloc.location == "Deck1" && GetCharacterShipCannonsDeckCount(mc) > 1)
						objLandInterface.UserIcons.(fastLocName).note = LanguageConvertString(tmpLangFileID, "go_UpperCannonsDeck");
// <-- KK

					bUse = true;
				}
			}
		}
		// to port icon
		if( GetCharacterShipType(mc) != SHIP_NOTUSED )
		{
			if(CheckFastJump(Locations[idxloc].id, mc.location.from_sea) || Truncate(Locations[idxloc].id,0,3)=="QC_" || Locations[idxloc].fastreload=="Pirate_fort" || Locations[idxloc].fastreload=="SL") //GreatZen
			{
				bool temp;
				if(Locations[idxloc].id!="QC_port" && Locations[idxloc].id!="Douwesen_shore_01" && Locations[idxloc].id!="Conceicao_shore_02")//MAXIMUS -->
				{
					temp = true;
					if(Locations[FindLoadedLocation()].fastreload=="ship") temp = false;
					if(bDeckEnter) temp = false;
					if(temp)
					{
						objLandInterface.UserIcons.port.enable = true;
						objLandInterface.UserIcons.port.pic = calcTextureIndex(2, 4);
						objLandInterface.UserIcons.port.selPic = calcSelectedTextureIndex(2, 4);
						if(Locations[idxloc].fastreload=="QC" || Locations[idxloc].fastreload=="Pirate_fort" || Locations[idxloc].fastreload=="SL") {
							objLandInterface.UserIcons.port.pic = 1;
							objLandInterface.UserIcons.port.selPic = 1;
						}
						objLandInterface.UserIcons.port.tex = 2;
						objLandInterface.UserIcons.port.name = "reloadtoport";

						if(Truncate(Locations[idxloc].id,0,3)=="QC_") objLandInterface.UserIcons.port.location = "QC_port";
						if(Locations[idxloc].fastreload=="Pirate_fort") objLandInterface.UserIcons.port.location = "Douwesen_shore_01";
						if(Locations[idxloc].fastreload=="SL") objLandInterface.UserIcons.port.location = "Conceicao_shore_02";
						else objLandInterface.UserIcons.port.location = mc.location.from_sea;
						objLandInterface.UserIcons.port.note = LanguageConvertString(tmpLangFileID, "go_port");
					}
				}//MAXIMUS <--
				bUse = true;
			}
		}
	}
	LanguageCloseFile(tmpLangFileID);
	return bUse;
}

void SetOfficerTexture(int officerIdx)
{
	aref ar; makearef(ar,objLandInterface.Parameters);
	string attrName = "iconTexture"+officerIdx;

	int cn = GetOfficersIndex(GetMainCharacter(),officerIdx);
	if (cn < 0) {
		DeleteAttribute(ar,attrName);
		ar.(attrName) = "";
	} else {
		ar.(attrName) = "interfaces\portraits\64\face_"+Characters[cn].FaceID+".tga";
	}
}

// KK: fixed officers-icons - we'll see proper icon for each officer in any location (simpler than MAXIMUS did) -->
void BLI_UpdateOfficers()
{
	BLI_SetObjectData();
	CheckOfficers();//MAXIMUS: all was moved down and BLI_UpdateObjectData will check officers-icons too :) [this will exclude hundreds of BLI_UpdateOfficers() in different places]
}

void CheckOfficers()
{
	ref mchr = GetMainCharacter();
	int i = -1;
	for (int o = 0; o < OFFICER_MAX; o++) {
		int idx = GetOfficersIndex(mchr, o);
		if (idx < 0) continue;
		ref ochr = GetCharacter(idx);
		if (IsEntity(ochr)) {
			i++;
			SetOfficerTexture(o);
			string iTex = "iconTexture" + o;
			SendMessage(&objLandInterface, "lls", MSG_BATTLE_LAND_SET_ICONTEX, i, objLandInterface.Parameters.(iTex));
		}
	}
}
// <-- KK

int GetPotionPicture(aref arItm)
{
	if( CheckAttribute(arItm,"potion.pic") ) {
		return sti(arItm.potion.pic);
	}
	traceif("Item "+arItm.id+ " hav`t POTION.PIC attribute");
	return 0;
}

int GetPotionTexture(aref arItm)
{
	if( !CheckAttribute(arItm,"potion.tex") ) {
		traceif("Item "+arItm.id+ " hav`t POTION.TEX attribute");
		return 0;
	}
	return 3+sti(arItm.potion.tex);
}

bool CanBeUseItem(ref chref)
{
	// NK rewrite for speed 04-09-08 -->
	/*for(int i=0; i<ITEMS_QUANTITY; i++)
	{
		if( CheckAttribute(&Items[i],"potion") && CheckAttribute(chref,"items."+Items[i].id) ) {
			if( EnablePotionUsing(chref,&Items[i]) ) {return true;}
		}
	}*/
	aref chritems; makearef(chritems, chref.items);
	int idx;
	for(int i = 0; i < GetAttributesNum(chritems); i++)
	{
		idx = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
		if (idx < 0) continue;		// LDH fix for negative index
		if(CheckAttribute(&Items[idx],"potion")) { if( EnablePotionUsing(chref,&Items[idx]) ) {return true;} }
	}
	//Levis -->
	if(CheckCharacterItem(chref,"opium"))
	{
		return true;
	}
	if(CheckCharacterItem(chref,"vegetal"))
	{
		return true;
	}
	//Levis <--
	return false;
	// NK <--
}

// NK rewrite to use native StrCut() -->
string Truncate(string str,int pos,int pos2)
{               
  /*string a="";
  int i;
  for (i=pos;i<pos2;i++)
 {
   a=a+GetSymbol(str,i);
 }

  return a;*/
	return strcut(str, pos, pos2-1);
}
// NK <--

// KK -->
bool SetShipIcons()
{
	int i, cn, st;
	string ship;
	ref curchr;
	ref mchr = GetMainCharacter();
	for (i = 0; i < COMPANION_MAX; i++) {
		cn = GetCompanionIndex(mchr, i);
		if (cn < 0) continue; // Levis: was if (cn < 0 || cn == iShipCaptain)
		curchr = GetCharacter(cn);
		st = GetCharacterShipType(curchr);
		if (st >= 0 && st < SHIP_TYPES_QUANTITY) {
			ship = "ship" + i;
			int textureIndex = sti(ShipsTypes[st].BI.Tex);
			string textureAttr = "t" + textureIndex;
			int textureColumns = objLandInterface.CommandTextures.list.(textureAttr).columns;
			objLandInterface.UserIcons.(ship).enable = true;
			objLandInterface.UserIcons.(ship).pic    = calcTextureIndex(sti(ShipsTypes[st].BI.Pic), textureColumns);
			objLandInterface.UserIcons.(ship).selPic = calcSelectedTextureIndex(sti(ShipsTypes[st].BI.Pic), textureColumns);
			objLandInterface.UserIcons.(ship).tex    = textureIndex;
			objLandInterface.UserIcons.(ship).note   = GetMyShipName(curchr);
			objLandInterface.UserIcons.(ship).name   = cn;
		}
	}
	return true;
}

void ReloadFromLandToSea()
{
	ref pchar = GetMainCharacter();
	Reload(chrWaitReloadRef, chrWaitReloadLocator, pchar.location);
	DeleteAttribute(pchar,"reloadStatus");
	DirectsailCheck(true);

	bAbordageStarted = false;
	bDeckStarted = false;
	bCrewStarted = false;
	Sea.AbordageMode = false;
	chrWaitReloadLocator = "";
	LandLocationIdx = -1;
	bDeckEnter = false;
	bToDeckFromLand = false;
	DeckID = "";
	FromDeckIdx = -1;
	bEmergeOnStartloc = false;	// LDH Going from land to sea should put player at boat locator - 14Feb09
	LandLocator = "";
}

void BLIVisible(bool visibleFlag)
{
	InterfaceStates.BIVisible = visibleFlag;
	BLI_RefreshCommandMenu();
	if (visibleFlag)
		BLI_EnableShow();
	else
		BLI_DisableShow();
	LogsVisible(visibleFlag);
}
// <-- KK
