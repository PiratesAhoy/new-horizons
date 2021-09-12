bool bSatisfied = false;
void InitInterface(string iniName)
{
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	ChangePicture("BACKGROUND", FindReloadPicture("Mutiny.tga"), true); // KK

	CreateString(true,"fakeTitle",XI_ConvertString("Mutiny"),FONT_TITLE,COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"CrewMorale","",FONT_NORMAL,COLOR_NORMAL,320,365,SCRIPT_ALIGN_CENTER,0.8);

	SetSelectable("B_FIGHT",true);
	SetSelectable("B_PAY",true);
	CalculateInfoData();
/*	if (ENABLE_EXTRA_SOUNDS == 1) {
		PauseAllSounds();
		PlayStereoSound("VOICE\\"+LanguageGetLanguage()+"\\pay_mutiny.wav");
	}*/

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_MUTINY_EXIT );
	wdmReloadToSea();
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_MUTINY_EXIT );
	wdmReloadToSea();
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	ref PChar = GetMainCharacter();

	switch(nodName)
	{
	case "B_FIGHT":
		if(comName=="activate" || comName=="click")
		{// misfortune
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_MUTINY_EXIT);
			if(!bSatisfied)
			{
				if(IsEntity(&worldMap)!=0)
				{
					DeleteAttribute(PChar,"ShipEnc");
					// KK wdmReloadToSea();
					// KK LAi_Fade("","");
					PostEvent("Sea_StartMutiny", 0.0);
				}
				else
				{
					int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
					int crewOut = makeint(GetCrewQuantity(PChar)/3);
					if(GetCrewQuantity(PChar)-crewOut<0) { crewOut = GetCrewQuantity(PChar); }
					if(!bSeaActive && !CheckAttribute(PChar,"IsOnDeck"))
					{
						if(crewOut>0)
						{
							PChar.Ship.Crew.Quantity = GetCrewQuantity(PChar)-crewOut;
							if(GetCrewQuantity(PChar)<=0) { PChar.Ship.Crew.Quantity = 0; }
							switch(rand(1))
							{
								case 0: Log_SetStringToLog(crewOut + " " + LanguageConvertString(tmpLangFileID,"CrewMutinyLeavesShip")); break;
								case 1: PostEvent("StartFight", 600.0); break;
							}
							DeleteAttribute(PChar,"Mutiny");
						}
					}
					else
					{
						if(CheckAttribute(PChar,"IsOnDeck"))
						{
							if(crewOut>0)
							{
								PChar.Ship.Crew.Quantity = GetCrewQuantity(PChar)-crewOut;
								if(GetCrewQuantity(PChar)<=0) { PChar.Ship.Crew.Quantity = 0; }
								PostEvent("StartFight", 600.0);
								DeleteAttribute(PChar,"Mutiny");
							}
						}
						else { PostEvent("Sea_StartMutiny", 20); }
					}
					LanguageCloseFile(tmpLangFileID);
				}
			}
			else
			{
				DeleteAttribute(PChar,"Mutiny");
			}
		}
	break;

	case "B_PAY":
		if(comName=="activate" || comName=="click")
		{//to pass
			RaiseCrewMorale();
		}
		if(comName=="upstep")
		{
			if(GetSelectable("B_FIGHT")) { SetCurrentNode("B_FIGHT"); }
		}
	break;
	}
}

void RaiseCrewMorale()
{
	if(!GetSelectable("B_PAY")) return;
	ref chref = GetMainCharacter();
	int crewQuantity = GetCrewQuantity(chref);
	if(GetRaiseMoraleCost(chref)>sti(chref.money)) return; // KK
	if(!CheckAttribute(chref,"Ship.Crew.Morale")) return;
	int crewMorale = sti(chref.Ship.Crew.Morale);

	AddMoneyToCharacter(chref,-GetRaiseMoraleCost(chref)); // KK
	crewMorale += 10;
	if(crewMorale>=makeint(chref.Ship.Crew.Morale*3)) { bSatisfied = true; }
	if(crewMorale>MORALE_MAX) { crewMorale = MORALE_MAX; bSatisfied = true; }

	int rumRation = roundup(crewQuantity * FOOD_PER_CREW); // PB: Use correct rum ration value for entire squadron
	if(GetSquadronGoods(chref,GOOD_RUM)>=rumRation) { RemoveCharacterGoods(chref,GOOD_RUM,rumRation); } // PB: Use ALL ships in the fleet
	else { bSatisfied = false; }
	chref.Ship.Crew.Morale = crewMorale;
	if(CheckAttribute(chref, "seatime.tempmorale")) { chref.seatime.tempmorale = stf(chref.seatime.tempmorale) + 10.0; }
	if(CheckAttribute(chref, "seatime.basecrewmorale") && sti(chref.seatime.basecrewmorale) < MORALE_MAX_RAISE ) { chref.seatime.basecrewmorale = stf(chref.seatime.basecrewmorale) + 10.0; }
	GameInterface.strings.Money = MakeMoneyShow(sti(characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER);
	CalculateInfoData();
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_PAY",0,"#"+XI_ConvertString("MutinyPay"));
	ref mainCh = GetMainCharacter();
	mainCh.Mutiny = true;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	mainCh.crewdebt = sti(mainCh.crewdebt) + GetRaiseMoraleCost(mainCh); // KK
	if(bSatisfied) mainCh.crewdebt = "0";
	string totalInfo = LanguageConvertString(tmpLangFileID,"CrewMutinyArticles1") + " " + sti(mainCh.crewdebt) +  " " + LanguageConvertString(tmpLangFileID,"CrewMutinyArticles2");

	int rumRation = roundup(GetSquadronTotalCrewQuantity(mainCh) * FOOD_PER_CREW); // PB: Use correct rum ration value for entire squadron

	if(sti(mainCh.money)<sti(mainCh.crewdebt))
	{
		SetSelectable("B_PAY",false);
		SetCurrentNode("B_FIGHT");
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FIGHT",0,"#"+XI_ConvertString("MutinyFight"));
		totalInfo += " " + LanguageConvertString(tmpLangFileID,"CrewMutinyArticles5");
		if(GetSquadronGoods(mainCh,GOOD_RUM)<rumRation) // PB: Use ALL ships in the fleet
		{
			totalInfo += " " + LanguageConvertString(tmpLangFileID,"CrewMutinyArticles4");
		}
	}
	else
	{
		if(GetSquadronGoods(mainCh,GOOD_RUM)<rumRation) // PB: Use ALL ships in the fleet
		{
			SetSelectable("B_PAY",false);
			SetCurrentNode("B_FIGHT");
			SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FIGHT",0,"#"+XI_ConvertString("MutinyFight"));
			totalInfo += " " + LanguageConvertString(tmpLangFileID,"CrewMutinyArticles4");
		}
		else
		{
			if(bSatisfied)
			{
				SetSelectable("B_PAY",false);
				SetCurrentNode("B_FIGHT");
				totalInfo = LanguageConvertString(tmpLangFileID,"CrewMutinyArticles3");
				SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FIGHT",0,"#"+XI_ConvertString("MutinyExit"));
				PlaySound("AMBIENT\cheer.wav");
			}
			else
			{
				SetSelectable("B_PAY",true);
				SetCurrentNode("B_PAY");
				SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FIGHT",0,"#"+XI_ConvertString("MutinyFight"));
			}
		}
	}

	GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale") + ": " + XI_ConvertString(GetMoraleName(mainCh.Ship.Crew.Morale)) + "!";

	SetFormatedText("INFO_TEXT",totalInfo);
	LanguageCloseFile(tmpLangFileID);
}
