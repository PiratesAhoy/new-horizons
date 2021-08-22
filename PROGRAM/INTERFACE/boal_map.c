void InitInterface(string iniName)
{
	EngineLayersOffOn(true);
	SetTimeScale(0.0);

// KK -->
	if (bShipMutiny)
		GameInterface.title = "MUTINY";
	else
		GameInterface.title = "titleBoal_map";
// <-- KK

	if(bAnimation && bNewInterface) iniName = "RESOURCE\INI\NEW_INTERFACES\ANIMATION\boal_map.ini";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	//SetNodeUSing("BACKGROUND",false);
	SetNodeUsing("VIDEOPIE",bAnimation && bNewInterface);
	//SetNodeUSing("RAMKA",false);

	CalculateInfoData();
	if(ENABLE_EXTRA_SOUNDS == 1) PlaySound("#sail_ho"); // NK // bool added by KAM after build 11

	ref mc = GetMainCharacter();
	SetFormatedText("INFO_TEXT",mc.EncInfo);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);
	SetNodeUsing("VIDEOPIE",bAnimation);

	CreateString(true, "Engage", TranslateString("", "Engage") + "?", FONT_NORMAL, COLOR_NORMAL, 320, 300, SCRIPT_ALIGN_CENTER, 1.0); // KK

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0); // Output/yield at sea
//	SetEventHandler("exitCancel","ProcessCancelExit",0); // Output/yield at sea on the small cross or Esc - PB: Escape key disabled
	SetEventHandler("ievnt_command","ProcCommand",0); // output/yield to the map/chart/card only here (on NO)
	SetEventHandler("evntDoPostExit","DoPostExit",0); // output/yield from the interface
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
	wdmReloadToSea();
    ResetVew();
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
	// KK wdmReloadToSea();
    ResetVew();
}

void ResetVew()
{
    SendMessage(&IActions,"ll",LI_SET_VISIBLE,true);
    SetTimeScale(1.0);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
//	DelEventHandler("exitCancel","ProcessCancelExit"); - PB: Escape key disabled
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
    ResetVew();
	EndCancelInterface(true);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
		case "B_OK":
			if(comName=="activate" || comName=="click")
			{
				// misfortune
				PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
				ResetVew();
				wdmReloadToSea();
			}
			if(comName=="rightstep" && GetSelectable("B_CANCEL")) { SetCurrentNode("B_CANCEL"); }
			if (comName == "downstep" || comName == "upstep") SetCurrentNode("B_SAVE"); // KK
		break;

		case "B_CANCEL":
			if(comName=="activate" || comName=="click")
			{
				//to pass
				PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
				if(CheckAttribute(GetMainCharacter(),"ShipEnc")) DeleteAttribute(GetMainCharacter(),"ShipEnc"); // NK
				ResetVew();
			}
			if(comName=="leftstep" && GetSelectable("B_OK")) { SetCurrentNode("B_OK"); }
			if (comName == "downstep" || comName == "upstep") SetCurrentNode("B_SAVE"); // KK
		break;
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	CreateString(true, "engage", TranslateString("", "Engage") + "?", FONT_NORMAL, COLOR_NORMAL, 320, 268, SCRIPT_ALIGN_CENTER, 0.9);
	ref mainCh = GetMainCharacter();
	if (sti(mainCh.CanEscape) == false) {
		SetSelectable("B_CANCEL", false);
		SetCurrentNode("B_OK");
	}
}
