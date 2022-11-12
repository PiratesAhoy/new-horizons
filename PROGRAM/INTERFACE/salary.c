int nPaymentQ;

void InitInterface_I(string iniName, int payment)
{
// KK -->
	if (IsEntity(&worldmap)) {
		EngineLayersOffOn(true);
		SetTimeScale(0.0);
	}
// <-- KK
	GameInterface.title = "titleSalary";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
// KK -->
	if (bSeaActive) {
		locCameraSleep(true);
		//SetTimeScale(0.0);

		LayerFreeze("realize", true);
		LayerFreeze("execute",true);
	}
	SetNodeUsing("VIDEOBASE", bNewInterface);
	SetNodeUsing("BACKSLIDE", bNewInterface);
	SetNodeUsing("CENTERRECTANGLE", bNewInterface);
	SetNodeUsing("CENTERBOUND", bNewInterface);
	SetNodeUsing("TITLE", bNewInterface);
	SetNodeUsing("FOREPICTURE", !bNewInterface);
	CreateString(!bNewInterface, "ScreenTitle", XI_ConvertString(GameInterface.title), FONT_TITLE, COLOR_NORMAL, 320, 16, SCRIPT_ALIGN_CENTER, 1.0);
// <-- KK

	nPaymentQ = payment;
	CalculateInfoData();

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("INFO_TEXT",LanguageConvertString(tmpLangFileID,"Salary info"));
	LanguageCloseFile(tmpLangFileID);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0)
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void ProcessBreakExit()
{
	SkipSailorPayment();
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void ProcessCancelExit()
{
	SkipSailorPayment();
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

// KK -->
	if (IsEntity(&worldmap)) {
		SetTimeScale(1.0);
		EngineLayersOffOn(false);
	}
	if (bSeaActive) {
		locCameraSleep(false);
		//SetTimeScale(1.0);
	}
// <-- KK

	interfaceResultCommand = exitCode;
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
			ExecuteSailorPayment();
// KK -->
			if (IsEntity(&worldmap)) {
				SetTimeScale(1.0);
				EngineLayersOffOn(false);
			}
			if (bSeaActive) {
				locCameraSleep(false);
				//SetTimeScale(1.0);
			}
// <-- KK
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
		}
	break;

	case "B_CANCEL":
		if(comName=="activate" || comName=="click")
		{
			SkipSailorPayment();
// KK -->
			if (IsEntity(&worldmap)) {
				SetTimeScale(1.0);
				EngineLayersOffOn(false);
			}
			if (bSeaActive) {
				locCameraSleep(false);
				//SetTimeScale(1.0);
			}
// <-- KK
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
		}
		if(comName=="upstep")
		{
			if(GetSelectable("B_OK"))	{SetCurrentNode("B_OK");}
		}
	break;
	}
}

void ExecuteSailorPayment()
{
	ref PChar = GetMainCharacter();

	// Remember that we've already made a decision this month
	PChar.LastPayMonth = GetDataMonth();

	AddMoneyToCharacter(PChar,-nPaymentQ);
//JA 26Nov06 -> pay officers on other ships, and use daily pay system
	PChar.quest.CrewPayOwed = 0;

	// NK -->
	int i, j, cn, on;
	for(i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(PChar, i);
		if(cn == -1) continue;
		if (IsTrader(GetCharacter(cn))) continue; // KK
		if(cn!=sti(PChar.index)) PayOfficerOwedMoney(&Characters[cn]);	// LDH added & 06Mar09
		for(j = 1; j < OFFICER_MAX; j++)
		{
			on = GetOfficersIndex(Characters[cn], j);
			if(on == -1) continue;
			PayOfficerOwedMoney(&Characters[on]); 	// LDH added & 06Mar09
		}
	}
	for(i = 0; i < GetPassengersQuantity(pchar); i++)
	{
		cn = GetPassenger(pchar, i);
		if(cn == -1) continue;
		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned") || IsOfficer(curChar) || IsTrader(curChar)) continue;  //don't pay if prisoner, trader or already payed above. // KK
		PayOfficerOwedMoney(&Characters[cn]);  	// LDH added & 06Mar09
	}

// <-- JA
	int pSalary = GetPaymentSum(PChar);//MAXIMUS
	// LDH if there wasn't enough money for salary, the money was being added to character as well as to wealth and never subtracted - 14Apr09
	if (!CheckAttribute(PChar, "isnotcaptain"))		// LDH 16Apr09
	{
		if (pSalary > GetCharacterMoney(PChar)) pSalary = GetCharacterMoney(PChar);
		AddMoneyToCharacter(PChar,-pSalary);
	}
	AddWealthToCharacter(PChar, pSalary);

	// PB: Repeat Payment Executing Bonus -->
	if(!CheckAttribute(PChar, "repeat_salary_payment")) PChar.repeat_salary_payment = 0;
	else
	{
		if(sti(PChar.repeat_salary_payment) <  0) PChar.repeat_salary_payment = 0;
		if(sti(PChar.repeat_salary_payment) >= 9) PChar.repeat_salary_payment = 9;
	}
	PChar.repeat_salary_payment = sti(PChar.repeat_salary_payment) + 1;

	AddPartyExpChar(PChar, "Leadership", sti(PChar.repeat_salary_payment)*500);
	// PB: Repeat Payment Executing Bonus <--

	DeleteAttribute(PChar,"foodoff"); // reset food off toggle
	// NK <--
	//DeleteAttribute(PChar,"CrewPayment");  JA 27Nov06 CrewPayment not used to track crew money owed anymore.
}
//MAXIMUS -->
int GetPaymentSum(ref PChar)
{
//	int pSalary = makeint((0.75 + makefloat(GetFoodEver()) * 0.25) * makefloat((10+sti(PChar.rank)*2) * 100 * COMP_PRICE_SCALAR* SALARY_MULTIPLIER) * (0.5 * makefloat(GetDifficulty())));
	int pSalary = makeint(500+100*sti(PChar.rank));
	return pSalary;
}
//MAXIMUS <--
void PayOfficerOwedMoney(ref chref)
{
	if(!CheckAttribute(chref,"quest.OfficerPrice") || !GetRemovable(&chref)) return;//not a payable officer
	if(CheckAttribute(chref,"quest.OfficerPayOwed"))
	{
		AddWealthToCharacter(&chref, sti(chref.quest.OfficerPayOwed));
		chref.quest.OfficerPayOwed = 0;
	}
}


void SkipSailorPayment()
{
	ref mchref = GetMainCharacter();
	int morale = 45;
//MAXIMUS: for new Mutiny -->
	int debt = GetPaymentSum(mchref);

	// Remember that we've already made a decision this month
	mchref.LastPayMonth = GetDataMonth();

	mchref.crewdebt = sti(mchref.crewdebt) + debt;
//MAXIMUS: for new Mutiny <--
	if( CheckAttribute(mchref,"Ship.Crew.Morale") ) morale = sti(mchref.Ship.Crew.Morale);

	// PB: Repeat Payment Skipping Penalty -->
	if(!CheckAttribute(mchref, "repeat_salary_payment")) mchref.repeat_salary_payment = 0;
	else
	{
		if(sti(mchref.repeat_salary_payment) > 0) mchref.repeat_salary_payment  = 0;
	}
	mchref.repeat_salary_payment        = sti(mchref.repeat_salary_payment) - 1;


	int nLeadership = GetShipSkill(mchref,SKILL_LEADERSHIP);
	int nMoraleDecreaseQ = 30 - nLeaderShip;
	if (CheckPerkForGroup(mchref,"IronWill")) nMoraleDecreaseQ /= 2;
	nMoraleDecreaseQ = abs(sti(mchref.repeat_salary_payment)) * nMoraleDecreaseQ;
	// PB: Repeat Payment Skipping Penalty <--

	morale -= nMoraleDecreaseQ;
	if(morale<0)	morale = 0;

	//mchref.CrewPayment = nPaymentQ; //JA 28Nov06 Not required as money owed to crew now stored elsewhere

	int cn, i;
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			// PB: Use Companion Skills and Reputation for Morale -->
			morale = 45;
			if( CheckAttribute(cn,"Ship.Crew.Morale") ) morale = sti(cn.Ship.Crew.Morale);
			morale -= nMoraleDecreaseQ;
			if(morale<0)	morale = 0;
			Characters[cn].Ship.Crew.Morale = morale;
			// PB: Use Companion Skills and Reputation for Morale <--
		}
	}

	if(sti(mchref.Ship.Crew.Morale) <= 10)	KAM_Mutiny();//MAXIMUS: new "Mutiny"
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	ref mchref = GetMainCharacter();

	CreateString(true,"payment",""+nPaymentQ,FONT_NORMAL,COLOR_NORMAL,320,258,SCRIPT_ALIGN_CENTER,1.0);

	if( sti(mchref.Money) < nPaymentQ )
	{
		SetSelectable("B_OK",false);
		SetCurrentNode("B_CANCEL");
	}
}
