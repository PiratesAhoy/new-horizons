void InitWmInterface()
{
	DeleteAttribute(&BattleInterface,"");
	WM_InitializeCommands();
	WM_SetParameterData();

	CreateEntity(&BattleInterface,"WM_INTERFACE");
	LayerAddObject(EXECUTE,&BattleInterface,-1);
	LayerAddObject(REALIZE,&BattleInterface,-1);

//	 SetEventHandler("BI_CommandEndChecking","WM_CommandEndChecking",0);
//	 SetEventHandler("BI_LaunchCommand","WM_LaunchCommand",0);
	 SetEventHandler("WM_SetPossibleCommands","WM_SetPossibleCommands",0);
	 SetEventHandler("WM_UpdateCurrentAction","WM_UpdateCurrentAction",0);

	 CreateILogAndActions(LOG_FOR_WORLDMAP);
	 Log_SetActiveAction("EnterToSea");

	 SetEventHandler("BI_UpdateWmInterface","BI_UpdateWmInterface",0);
	 PostEvent("BI_UpdateWmInterface",1000);
	 SetEventHandler("Control Activation","WM_ProcessControlPress",0); // boal
}

void WM_ProcessControlPress()
{
	string ControlName = GetEventData();
	if( sti(InterfaceStates.Launched) != 0 ) {return;}

	switch(ControlName)
	{
		case "BICommandsActivate":
			PlaySound("interface/ok.flac"); // boal даешь звуки!
		break;
	}
}

void BI_UpdateWmInterface()
{
	SendMessage(&BattleInterface,"l",BI_MSG_REFRESH);
	PostEvent("BI_UpdateWmInterface",1000);
}

void WM_UpdateCurrentAction()
{
	bool bDefault = true;
	Trace("WM_UpdateCurrentAction: Encountering type: " + worldMap.encounter_type + " near island " + worldMap.encounter_island);
	switch( sti(worldMap.encounter_type) )
	{
	case WORLDMAP_ENCOUNTER_TYPE_UNKNOWN:
		Trace("WM_UpdateCurrentAction: Encountering sea");
		Log_SetActiveAction("EnterToSea");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_MERCHANT:
		Trace("WM_UpdateCurrentAction: Encountering ship");
		Log_SetActiveAction("EnterToShip");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_WARRING:
		Trace("WM_UpdateCurrentAction: Encountering battle");
		Log_SetActiveAction("EnterToAttack");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_FOLLOW:
		Trace("WM_UpdateCurrentAction: Encountering enemy");

		Log_SetActiveAction("EnterToEnemy");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_STORM:
		Trace("WM_UpdateCurrentAction: Encountering storm");
		Log_SetActiveAction("EnterToStorm");
		bDefault = false;
		break;
	}
	if( bDefault ) {
		if( sti(worldMap.encounter_island) ) {
			Trace("WM_UpdateCurrentAction: Approaching " + worldMap.encounter_island);
			PlaySound("#land_ho");
			Log_SetActiveAction("EnterToIsland");
		} else {
			Trace("WM_UpdateCurrentAction: Entering open waters");
			Log_SetActiveAction("EnterToSea");
		}
	}
	SendMessage(&BattleInterface,"l",BI_MSG_REFRESH);
}

void WM_InitializeCommands()
{
	int idLngFile = LanguageOpenFile("commands_name.txt");

	BattleInterface.Commands.Cancel.enable			= false;
	BattleInterface.Commands.Cancel.picNum			= 1;
	BattleInterface.Commands.Cancel.selPicNum		= 0;
	BattleInterface.Commands.Cancel.texNum			= 0;
	BattleInterface.Commands.Cancel.event			= "Cancel";
	BattleInterface.Commands.Cancel.note			= LanguageConvertString(idLngFile, "sea_Cancel");

	BattleInterface.Commands.EnterToSea.enable		= false;
	BattleInterface.Commands.EnterToSea.picNum		= 1;
	BattleInterface.Commands.EnterToSea.selPicNum	= 1;
	BattleInterface.Commands.EnterToSea.texNum		= 1;
	BattleInterface.Commands.EnterToSea.event		= "EnterToSea";
	BattleInterface.Commands.EnterToSea.note		= LanguageConvertString(idLngFile, "worldmap_sea");

	BattleInterface.Commands.EnterToIsland.enable		= false;
	BattleInterface.Commands.EnterToIsland.picNum		= 0;
	BattleInterface.Commands.EnterToIsland.selPicNum	= 0;
	BattleInterface.Commands.EnterToIsland.texNum		= 1;
	BattleInterface.Commands.EnterToIsland.event		= "EnterToIsland";
	BattleInterface.Commands.EnterToIsland.note			= LanguageConvertString(idLngFile, "worldmap_sea");

	BattleInterface.Commands.EnterToShip.enable		= false;
	BattleInterface.Commands.EnterToShip.picNum		= 3;
	BattleInterface.Commands.EnterToShip.selPicNum	= 3;
	BattleInterface.Commands.EnterToShip.texNum		= 1;
	BattleInterface.Commands.EnterToShip.event		= "EnterToShip";
	BattleInterface.Commands.EnterToShip.note		= LanguageConvertString(idLngFile, "worldmap_sea");

	BattleInterface.Commands.EnterToStorm.enable		= false;
	BattleInterface.Commands.EnterToStorm.picNum		= 5;
	BattleInterface.Commands.EnterToStorm.selPicNum		= 5;
	BattleInterface.Commands.EnterToStorm.texNum		= 1;
	BattleInterface.Commands.EnterToStorm.event			= "EnterToStorm";
	BattleInterface.Commands.EnterToStorm.note			= LanguageConvertString(idLngFile, "worldmap_sea");

	BattleInterface.Commands.EnterToAttack.enable		= false;
	BattleInterface.Commands.EnterToAttack.picNum		= 3;
	BattleInterface.Commands.EnterToAttack.selPicNum	= 3;
	BattleInterface.Commands.EnterToAttack.texNum		= 1;
	BattleInterface.Commands.EnterToAttack.event		= "EnterToAttack";
	BattleInterface.Commands.EnterToAttack.note			= LanguageConvertString(idLngFile, "worldmap_sea");

	BattleInterface.Commands.EnterToEnemy.enable	= false;
	BattleInterface.Commands.EnterToEnemy.picNum	= 2;
	BattleInterface.Commands.EnterToEnemy.selPicNum	= 2;
	BattleInterface.Commands.EnterToEnemy.texNum	= 1;
	BattleInterface.Commands.EnterToEnemy.event		= "EnterToEnemy";
	BattleInterface.Commands.EnterToEnemy.note		= LanguageConvertString(idLngFile, "worldmap_sea");

	LanguageCloseFile(idLngFile);

	worldMap.encounter_type = -1;
}

void WM_SetParameterData()
{
	// float fHtRatio = stf(Render.screen_y) / 600;
	float fHtRatio = 1.0;
	int fTmp, fTmp2;
	BattleInterface.CommandTextures.list.t0.name = "BATTLE_INTERFACE/Cancel.tga";
	BattleInterface.CommandTextures.list.t0.xsize = 2;
	BattleInterface.CommandTextures.list.t0.ysize = 1;

	BattleInterface.CommandTextures.list.t1.name = "WorldMap/Interfaces/BgIcons2.tga";
	BattleInterface.CommandTextures.list.t1.xsize = 8;
	BattleInterface.CommandTextures.list.t1.ysize = 1;

	BattleInterface.wm_sign.fontid					= "interface_normal";
	BattleInterface.wm_sign.fontcolor				= argb(255,255,255,168) //argb(255,255,255,255);
	BattleInterface.wm_sign.fontscale				= 1.1 * fHtRatio;
	fTmp = makeint(-14.0 * fHtRatio);
	fTmp2 = makeint(18.0 * fHtRatio);
	BattleInterface.wm_sign.fontoffset       = fTmp + "," + fTmp2;

	BattleInterface.wm_sign.shipnamefontid			= "interface_normal";
	BattleInterface.wm_sign.shipnamefontcolor		= argb(255,255,255,255);
	BattleInterface.wm_sign.shipnamefontscale		= 1.1 * fHtRatio;
	fTmp = makeint(-14.0 * fHtRatio);
	fTmp2 = makeint(40.0 * fHtRatio);
	BattleInterface.wm_sign.shipnamefontoffset       = fTmp + "," + fTmp2;

	BattleInterface.wm_sign.backtexturename			= "battle_interface\ShipBackIcon.tga.tx";
	BattleInterface.wm_sign.backcolor				= argb(255,128,128,128);
	BattleInterface.wm_sign.backuv					= "0.0,0.0,1.0,1.0";
	BattleInterface.wm_sign.backoffset				= "-2,-2"; //"0.0,0.0";
	fTmp = makeint(128.0 * fHtRatio);
	BattleInterface.wm_sign.backiconsize			= fTmp + "," + fTmp;

	BattleInterface.wm_sign.shipstatetexturename	= "battle_interface\ShipState.tga.tx";
	BattleInterface.wm_sign.shipstatecolor			= argb(255,128,128,128);
	BattleInterface.wm_sign.shiphpuv				= "0.0,0.109,0.5,0.6875";
	fTmp = makeint(-32.0 * fHtRatio);
	fTmp2 = makeint(-13.0 * fHtRatio);
	BattleInterface.wm_sign.shiphpoffset			= fTmp + "," + fTmp2;
	fTmp = makeint(32.0 * fHtRatio);
	BattleInterface.wm_sign.shipspoffset			= fTmp + "," + fTmp2;

	fTmp = makeint(64.0 * fHtRatio);
	fTmp2 = makeint(74.0 * fHtRatio);
	BattleInterface.wm_sign.shiphpiconsize			= fTmp + "," + fTmp2;
	BattleInterface.wm_sign.shipspiconsize			= fTmp + "," + fTmp2;
	BattleInterface.wm_sign.shipspuv				= "0.5,0.109,1.0,0.6875";

	BattleInterface.wm_sign.shipclasstexturename	= "battle_interface\ShipClass.tga.tx";
	BattleInterface.wm_sign.shipclasscolor			= argb(255,102,102,102); //argb(255,128,128,128);
	BattleInterface.wm_sign.shipclassuv				= "0.0,0.0,1.0,1.0";
	fTmp = makeint(-14.0 * fHtRatio);
	fTmp2 = makeint(-52.0 * fHtRatio);
	BattleInterface.wm_sign.shipclassoffset			= fTmp + "," + fTmp2;

	fTmp = makeint(64.0 * fHtRatio);
	fTmp2 = makeint(16.0 * fHtRatio);
	BattleInterface.wm_sign.shipclassiconsize		= fTmp + "," + fTmp2;

	BattleInterface.wm_sign.gunchargeprogress		= "0.0625, 0.219, 0.359, 0.5, 0.641, 0.781, 0.983";

	BattleInterface.wm_sign.shiptexturename			= "battle_interface\ship_icons2.tga.tx";
	BattleInterface.wm_sign.shipcolor				= argb(255,128,128,128);

	fTmp = makeint(-14.0 * fHtRatio);
	fTmp2 = makeint(-12.0 * fHtRatio);
	BattleInterface.wm_sign.shipoffset				= fTmp + "," + fTmp2;

	fTmp = makeint(64.0 * fHtRatio);
	BattleInterface.wm_sign.shipiconsize			= fTmp + "," + fTmp;

	fTmp = makeint(-40.0 * fHtRatio);
	BattleInterface.wm_sign.commandlistverticaloffset = fTmp;

	float fTmp3;
	fTmp = makeint(70.0 * fHtRatio);
	fTmp3 = fTmp;
	fTmp2 = makeint(128.0 * fHtRatio);
	BattleInterface.wm_sign.iconoffset1 = fTmp + "," + fTmp;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset2 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset3 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset4 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset5 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset6 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset7 = fTmp + "," + fTmp3;
	fTmp3 += fTmp2;
	BattleInterface.wm_sign.iconoffset8 = fTmp + "," + fTmp3;

	BattleInterface.CommandList.CommandMaxIconQuantity = 8;
	BattleInterface.CommandList.CommandIconSpace = 1;
	BattleInterface.CommandList.CommandIconLeft = makeint(108 * fHtRatio);//157;
	BattleInterface.CommandList.CommandIconWidth = RecalculateHIcon(makeint(48 * fHtRatio));
	BattleInterface.CommandList.CommandIconHeight = RecalculateVIcon(makeint(48 * fHtRatio));

	BattleInterface.CommandList.CommandNoteFont = "interface_normal";
	BattleInterface.CommandList.CommandNoteColor = argb(255,255,255,255);
	BattleInterface.CommandList.CommandNoteScale = 1.0 * fHtRatio;
	BattleInterface.CommandList.CommandNoteOffset = RecalculateHIcon(0) + "," + RecalculateVIcon(makeint(-42 * fHtRatio));

	BattleInterface.CommandList.CommandNoteFont = "interface_normal";
	BattleInterface.CommandList.CommandNoteColor = argb(255,255,255,255);
	BattleInterface.CommandList.CommandNoteScale = 1.0 * fHtRatio;
	BattleInterface.CommandList.CommandNoteOffset = RecalculateHIcon(0) + "," + RecalculateVIcon(makeint(-42 * fHtRatio));

	BattleInterface.CommandList.UDArrow_Texture = "battle_interface\arrowly.tga.tx";
	BattleInterface.CommandList.UDArrow_UV_Up = "0.0,1.0,1.0,0.0";
	BattleInterface.CommandList.UDArrow_UV_Down = "0.0,0.0,1.0,1.0";
	BattleInterface.CommandList.UDArrow_Size = RecalculateHIcon(makeint(32 * fHtRatio)) + "," + RecalculateVIcon(makeint(32 * fHtRatio));
	BattleInterface.CommandList.UDArrow_Offset_Up = RecalculateHIcon(makeint(-41 * fHtRatio)) + "," + RecalculateVIcon(makeint(-30 * fHtRatio));
	BattleInterface.CommandList.UDArrow_Offset_Down = RecalculateHIcon(makeint(-41 * fHtRatio)) + "," + RecalculateVIcon(makeint(46 * fHtRatio));

	// BattleInterface.maincharindex = pchar.index;

	// WM_SetShipData();
}

void CreateWorldMapActionsEnvironment()
{
    // float fHtRatio = stf(Render.screen_y) / iGlobalVar1;
    float fHtRatio = 1.0;
	IActions.type = "map";

	IActions.ActiveActions.TextureName = "WorldMap/Interfaces/BgIcons2.tga";
	IActions.ActiveActions.horzQ = 8;
	IActions.ActiveActions.vertQ = 1;
	IActions.ActiveActions.width = RecalculateHIcon(makeint(48 * fHtRatio));
	IActions.ActiveActions.height = RecalculateVIcon(makeint(48 * fHtRatio));
	IActions.ActiveActions.left = sti(showWindow.right) - RecalculateHIcon(makeint(284 * fHtRatio));
	IActions.ActiveActions.top = sti(showWindow.top) + RecalculateVIcon(makeint(32 * fHtRatio));

	IActions.ActiveActions.text1.font = "interface_normal";
	IActions.ActiveActions.text1.scale = 1.0 * fHtRatio;
	IActions.ActiveActions.text1.pos.x = sti(showWindow.right) - RecalculateHIcon(makeint(260 * fHtRatio));
	IActions.ActiveActions.text1.pos.y = sti(showWindow.top) + RecalculateVIcon(makeint(86 * fHtRatio));
	IActions.ActiveActions.text1.text = XI_ConvertString("Press_F3");
	IActions.ActiveActions.text2.font = "interface_normal";
	IActions.ActiveActions.text2.scale = 1.0 * fHtRatio;
	IActions.ActiveActions.text2.pos.x = sti(showWindow.right) - RecalculateHIcon(makeint(260 * fHtRatio));
	IActions.ActiveActions.text2.pos.y = sti(showWindow.top) + RecalculateVIcon(makeint(86 * fHtRatio));//RecalculateVIcon(102);
	IActions.ActiveActions.text2.text = XI_ConvertString("for_quick_action");

	IActions.ActiveActions.EnterToSea.IconNum	= 1;
	IActions.ActiveActions.EnterToSea.Text = XI_ConvertString("for_quick_action_EnterToSea");
	IActions.ActiveActions.EnterToIsland.IconNum = 0;
	IActions.ActiveActions.EnterToIsland.Text = XI_ConvertString("for_quick_action_EnterToIsland");
	IActions.ActiveActions.EnterToShip.IconNum = 3;
	IActions.ActiveActions.EnterToShip.Text = XI_ConvertString("for_quick_action_EnterToShip");
	IActions.ActiveActions.EnterToStorm.IconNum = 5;
	IActions.ActiveActions.EnterToStorm.Text = XI_ConvertString("for_quick_action_EnterToStorm");
	IActions.ActiveActions.EnterToAttack.IconNum = 3;
	IActions.ActiveActions.EnterToAttack.Text = XI_ConvertString("for_quick_action_EnterToAttack");
	IActions.ActiveActions.EnterToEnemy.IconNum	= 2;
	IActions.ActiveActions.EnterToEnemy.Text = XI_ConvertString("for_quick_action_EnterToEnemy");
}

void WM_SetPossibleCommands()
{
	int chIdx = GetEventData();
	// int mainIdx = sti(PChar.index);

	if( chIdx<0 || CharacterIsDead(GetCharacter(chIdx)) )
	{
		// disable all commands
		aref aroot,arcur;
		makearef(aroot,BattleInterface.Commands);
		int q = GetAttributesNum(aroot);
		for(int i=0; i<q; i++)
		{
			arcur = GetAttributeN(aroot,i);
			arcur.enable = false;
		}
		return;
	}

	BattleInterface.Commands.Cancel.enable = true;
	BattleInterface.Commands.EnterToAttack.enable = false;
	BattleInterface.Commands.EnterToShip.enable	= false;
	BattleInterface.Commands.EnterToSea.enable = false;
	BattleInterface.Commands.EnterToIsland.enable = false;
	BattleInterface.Commands.EnterToStorm.enable = false;
	BattleInterface.Commands.EnterToEnemy.enable = false;

	bool bDefault = true;
	switch( sti(worldMap.encounter_type) )
	{
	case WORLDMAP_ENCOUNTER_TYPE_UNKNOWN:
		BattleInterface.Commands.EnterToIsland.enable = true;
		// Log_SetActiveAction("EnterToIsland");
		Log_SetActiveAction("EnterToSea");  //boal
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_MERCHANT:
		BattleInterface.Commands.EnterToShip.enable	= true;
		Log_SetActiveAction("EnterToShip");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_WARRING:
		BattleInterface.Commands.EnterToAttack.enable = true;
		Log_SetActiveAction("EnterToAttack");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_FOLLOW:
		BattleInterface.Commands.EnterToEnemy.enable = true;
		Log_SetActiveAction("EnterToEnemy");
		bDefault = false;
		break;
	case WORLDMAP_ENCOUNTER_TYPE_STORM:
		BattleInterface.Commands.EnterToStorm.enable = true;
		Log_SetActiveAction("EnterToStorm");
		bDefault = false;
		break;
	}

	if( bDefault )
	{
		if( sti(worldMap.encounter_island) ) {
			BattleInterface.Commands.EnterToIsland.enable = true;
			Log_SetActiveAction("EnterToIsland");
		} else {
			BattleInterface.Commands.EnterToSea.enable = true;
			Log_SetActiveAction("EnterToSea");
		}
	}
}
