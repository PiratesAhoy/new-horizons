
int nCurScroll;
//ref PChar;

void InitInterface(string iniName)
{
	PChar = GetMainCharacter();

	GameInterface.title = "titleKAMRations";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	SetSelectable("EXIT_BUTTON",true); // MAXIMUS interface mod

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

// LDH -->  trying to allow ESC to exit.

	SetCurrentNode("FULLFOOD_BUTTON");	// LDH added to allow ESC to exit.

// LDH <--

	KAM_UpdateDisplay();
}

void KAM_UpdateDisplay()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string tempfr;
	string temprr;
	string tempmessage1;
	string tempmessage2;

	if(!CheckAttribute(pchar,"Crewstatus.foodrations")) pchar.Crewstatus.foodrations = 1;
	if(!CheckAttribute(pchar,"Crewstatus.rumrations")) pchar.Crewstatus.rumrations = 2;

	if(sti(pchar.Crewstatus.foodrations) == 1) tempfr = LanguageConvertString(tmpLangFileID,"FULL");
	else tempfr = LanguageConvertString(tmpLangFileID,"HALF");

	if(sti(pchar.Crewstatus.rumrations) == 1) temprr = LanguageConvertString(tmpLangFileID,"DOUBLE");
	else temprr = LanguageConvertString(tmpLangFileID,"NORMAL");

	// TIH --> calculations and divide by zero fix Jul11'06
	float tmpfood = 0.0;
	float tmprum = 0.0;
	if(CheckAttribute(pchar.Crewstatus,"foodused")) tmpfood = stf(pchar.Crewstatus.foodused);
	if(CheckAttribute(pchar.Crewstatus,"rumused")) tmprum = stf(pchar.Crewstatus.rumused);

	int allCrew = GetSquadronTotalCrewQuantity(pchar);
	if (allCrew < 1) allCrew = 1;

	int tmpMsgNum1 = makeint((makefloat(GetSquadronGoods(pchar, GOOD_WHEAT)) - tmpfood ) / (makefloat(allCrew) * FOOD_PER_CREW / stf(pchar.Crewstatus.foodrations)));
	int tmpMsgNum2 = makeint((makefloat(GetSquadronGoods(pchar, GOOD_RUM)) - tmprum ) / (makefloat(allCrew) * FOOD_PER_CREW / stf(pchar.Crewstatus.rumrations)));

	tempmessage1 = LanguageConvertString(tmpLangFileID,"FOOD rations are at") + " " + tempfr + " " + LanguageConvertString(tmpLangFileID,"level. On these rations, food in the hold is enough for") + " " + tmpMsgNum1 + " " + GetLocalizedDayString(tmpMsgNum1) + "."; //MAXIMUS: XI_ConvertString("days") changed to LocalizedDay simply for literate spelling in russian
	tempmessage2 = LanguageConvertString(tmpLangFileID,"RUM rations are at") + " " + temprr + " " + LanguageConvertString(tmpLangFileID,"level. On these rations, rum in the hold is enough for") + " " + tmpMsgNum2 + " " + GetLocalizedDayString(tmpMsgNum2) + "."; //MAXIMUS: XI_ConvertString("days") changed to LocalizedDay simply for literate spelling in russian
	// TIH <--
	SetFormatedText("TEXTWINDOW1",tempmessage1);
	SetFormatedText("TEXTWINDOW2",tempmessage2);
}


void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if(comName=="activate" || comName=="click")
	{
		switch (nodName)
		{
			case "FULLFOOD_BUTTON":
				pchar.Crewstatus.foodrations = 1;
				KAM_UpdateDisplay();
				break;

			case "HALFFOOD_BUTTON":
				pchar.Crewstatus.foodrations = 2;
				KAM_UpdateDisplay();
				break;

			case "DOUBLERUM_BUTTON":
				pchar.Crewstatus.rumrations = 1;
				KAM_UpdateDisplay();
				break;

			case "NORMALRUM_BUTTON":
				pchar.Crewstatus.rumrations = 2;
				KAM_UpdateDisplay();
				break;
		}
	}
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_KAM_RATIONS_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

    interfaceResultCommand = exitCode;
	PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP",1);
	EndCancelInterface(false);
}
