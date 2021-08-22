

#include "characters\characters_reload_check.c"


string lockedReloadLocator;

string chrWaitReloadLocator;
aref chrWaitReloadRef;
aref chrWaitLocationRef;
bool chrWaitReloadIsNoLink = false;

void InitCharacterEvents()
{
	SetEventHandler("Location_CharacterEntryToLocator", "chrCharacterEntryToLocator", 0);
	SetEventHandler("Location_CharacterInLocator", "chrCharacterInLocator", 0);
	SetEventHandler("Location_CharacterExitFromLocator", "chrCharacterExitFromLocator", 0);


	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	
	chrWaitReloadIsNoLink = false;
}

bool AddCharacterLocatorGroup(aref chr, string group)
{
	bool res;
	res = SendMessage(chr, "ls", MSG_CHARACTER_ADD_DETECTOR, group);
	return res;
}

bool DelCharacterLocatorGroup(aref chr, string group)
{
	bool res;
	res = SendMessage(chr, "ls", MSG_CHARACTER_DEL_DETECTOR, group);
	return res;
}


void chrCharacterEntryToLocator()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	aref loc = GetEventData();	
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	aref tmp;
	string locAttr;
	float x, y, z;
	ref mc = GetMainCharacter();
	int result;
	if(!ownDeckStarted()) LandLocationIdx = -1;

	// NK use switch rather than ifs. Faster. 05-05-04 -->
	if(IsMainCharacter(chr))
	{

		// TIH --> removed treasure quest locators out of this override section, so it doesnt happen ALL THE TIME Aug31'06
		switch(mc.location)
		{
			case "Roa_Grot":
				if(locator == "randitem1"){ group = "box"; Log_SetStringToLog(TranslateString("","Secret Chest")); }
				break;
			case "Hispaniola_Grot":
				if(locator == "randitem1"){ group = "box"; Log_SetStringToLog(TranslateString("","Secret Chest")); }
				break;
			case "Turks_Cavern_02":
				if(locator == "randitem1"){ group = "box"; Log_SetStringToLog(TranslateString("","Secret Chest")); }
				break;
			case "Turks_Cave_Exit_02":
				if(locator == "randitem1")
				{ 
					group = "reload"; 
					// changed by MAXIMUS -->
					if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav"); 
					// changed by MAXIMUS <--
					Log_SetStringToLog(TranslateString("","You've dropped through a trapdoor into a cave..."));
				}
				break;
			case "Cayman_Jungle_08":
				if(locator == "goto9")
				{ 
					group = "reload"; 
					// changed by MAXIMUS -->
					if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav"); 
					// changed by MAXIMUS <--
					Log_SetStringToLog(TranslateString("","You've dropped through a trapdoor into a cave..."));
				}
				break;
			// ccc additional exits: some non-reload locators now work like reload group loctrs 
			case "Oxbay_town":
				if(locator == "reload11")
				{ 
				    if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav"); 
				}
				break;
			case "dungeon 1":
				if(locator == "monster1"){ group = "reload"; }
				break;
			case "Greenford_M_church":
				if(locator == "reload2")
				{ 
				    group = "reload"; 
				    if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav"); 
					Log_SetStringToLog(TranslateString("","You've dropped through a trapdoor into the crypt..."));
				}

				break;
			case "Greenford_M_crypt": // PB
				if(locator == "reload14")
				{ 
				    if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav"); 
					Log_SetStringToLog(TranslateString("","You've dropped through a trapdoor into the undercroft..."));
				}

				// ccc Nov05 crypt effects
				if(group == "goto")
				{
					PlayStereoSound("AMBIENT\TAVERN\man2.wav");
					ChangeHPBonus(chr, 3);
					chr.chr_ai.poison = 50;
					Log_SetStringToLog(TranslateString("","The vapour makes you stronger but has a side effect..."));
				}

				if(group == "monsters")
				{ 
					if(chr.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom5.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
					LAi_ApplyCharacterDamage(chr, 5);
					if (sti(LAi_GetCharacterHP(chr)) < 6) Lai_KillCharacter(chr);
				}
				break;
		}
		// TIH <--
	}


	switch(group)
	{
/*
// ccc mines
	case "goto":
		// ccc moved to top: ref location = &Locations[FindLoadedLocation()]
		if(location.type != "jungle" ){ break; }
		if(rand(100)+sti(chr.skill.Sneak)>15){ break; }
		Explosion (chr, makeint(5+rand(20) ) );
		Log_SetStringToLog("A Mine !");
		break;
// ccc mines end
*/
	case "reload":
		if(bMutinyDeckStarted || LAi_IsBoardingProcess()) { break; }
		if(!IsMainCharacter(chr)) { break; }
		chrWaitReloadIsNoLink = false;
		chrWaitReloadLocator = locator;
		chrWaitLocationRef = loc;
		makearef(chrWaitReloadRef, loc.reload);
		result = chrCheckReloadLink(loc, locator);
		string reloadType = "Reload";//MAXIMUS -->
		if(CheckAttribute(chr,"reloadStatus")) reloadType = chr.reloadStatus;
		chr.reloadStatus = reloadType;//MAXIMUS <--

		if(result != 1)
		{
			chrWaitReloadIsNoLink = true;
			if(result == 0) CheckReloadAction(chr, "");//MAXIMUS

			// ccc random locs start
			if(RANDOM_LOCS_TOGGLE)
			{
				if(chrWaitReloadLocator == "reload1")
				{
					logit(TranslateString("","Do you want to leave this place for good?"));
				}
				else
				{ 
					logit(TranslateString("","You could pry this door open, but you never know what's waiting behind!"));
					if(!CheckAttribute(loc, "randloc")) // not in random locations
					{
						chr.lastlocation = loc.id;		// last "normal" location before random loc
						chr.lastlocator = locator;		// last locator in "normal" loc
						if(CheckAttribute(loc,"townsack") ) chr.lasttownsack = loc.townsack;
						// logit("lctr: "+chr.lastlocator+" in "+chr.lastlocation);	// for testing
					}
				}
			}
			// ccc random locs end

			break;
		}
		if (chrCheckAutoReload(loc, locator) == true) {
			if(chrIsNowEnableReload() != true)
			{
				lockedReloadLocator = "";
				CheckReloadAction(chr, "");//MAXIMUS
				break;
			}
			if(!CheckAttribute(chr,"autoreload"))
			{
				chr.autoreload.location = chr.location;
				chr.autoreload.locator = chrWaitReloadLocator;
				Reload(chrWaitReloadRef, chrWaitReloadLocator, chr.location);
			}
			else
			{
				if(GetAttribute(chr, "location") != GetAttribute(chr, "autoreload.location")) // PB
				{
					if(CheckAttribute(chr,"location.locator.old.emerge") && chrWaitReloadLocator==chr.location.locator.old.emerge)
					{
						DeleteAttribute(chr,"autoreload.locator");
					}
					else
					{
						chr.autoreload.location = chr.location;
						chr.autoreload.locator = chrWaitReloadLocator;
						Reload(chrWaitReloadRef, chrWaitReloadLocator, chr.location);
					}
				}
			}
		}
		else
		{
			if(CheckAttribute(chr,"autoreload"))
			{
				DeleteAttribute(chr,"autoreload.location");
				DeleteAttribute(chr,"autoreload.locator");
				DeleteAttribute(chr,"autoreload");
			}
			lockedReloadLocator = "";
			CheckReloadAction(chr, reloadType);
		}//MAXIMUS: code moved into the MAXIMUS_Functions.c
		break;
	case "camdetector":
		// CCC -->
		if(LOC_CAMERA)
		{
			locAttr = "locators.camera." + locator;
			if(CheckAttribute(loc, locAttr) != 0)
			{
				x = MakeFloat(loc.(locAttr).x);
				y = MakeFloat(loc.(locAttr).y);
				z = MakeFloat(loc.(locAttr).z);
				locCameraToPos(x, y, z, false);
			}
		}
		else { locCameraFollow(); }
		// CCC <--
		break;
	case "item":
		Item_OnEnterLocator(loc, locator);
		break;
	case "randitem":
		RandItem_OnEnterLocator(loc, locator);
		break;
	case "box":
// added by MAXIMUS [abordage MOD] checks for additional locators -->
		Box_EnterToLocator(loc, locator);
		break;
	}
//MAXIMUS: checks for additional locators <--
	
	if( CheckAttribute(chr,"Quests.LocatorCheck." + group) )
	{
		chr.Quests.LocatorCheck.(group) = locator;
		QuestsCheck();
	}
	//LanguageCloseFile(tmpLangFileID);
}

void chrCharacterInLocator()
{
	return;

	aref loc = GetEventData();	
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	float timeInLocator = GetEventData();

}

void chrCharacterExitFromLocator()
{
	aref loc = GetEventData();
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	float timeInLocator = GetEventData();

	if(sti(chr.index) == GetMainCharacterIndex())
	{
		ref mc = GetMainCharacter();
		// NK use switch rather than ifs. Faster. 05-05-04 -->
		string curloc = mc.location;
		//ref location = &Locations[FindLoadedLocation()];
		ref location;
		int lidx = FindLocation(curloc);
		//logit("Loaded loc is " + FindLoadedLocation() + " and cur loc id is " + curloc + " and the idx of that is " + lidx);
		if(lidx >= 0) makeref(location, Locations[lidx]);
		else location =  NullCharacter;

		// TIH --> removed treasure quest locators out of this override section, so it doesnt happen ALL THE TIME Aug31'06
		switch(curloc)
		{
			case "Roa_Grot":
				if(locator == "randitem1"){ group = "box";}
				break;
			case "Hispaniola_Grot":
				if(locator == "randitem1"){ group = "box";}
				break;
			case "Turks_Cavern_02":
				if(locator == "randitem1"){ group = "box";}
				break;
			case "Turks_Cave_Exit_02":
				if(locator == "randitem1"){ group = "reload"; }
				break;
			case "dungeon 1":
				// ccc additional exits: some non-reload locators now work like reload group loctrs
				if(locator == "monster1"){ group = "reload"; }
				break;
			case "Oxbay_cave":
			//	if(locator == "randitem1"){ group = "reload"; }
				break;
			case "Greenford_town":
				if(locator == "Goto1"){ group = "reload"; }
				break;
			case "Greenford_M_church":
				if(locator == "Goto2"){ group = "reload"; }
				break;
		}
	}
// ccc additional exits end

	switch(group)
	{
	case "reload":
		if(!CheckAttribute(GetMainCharacter(),"fakereload.locator"))//MAXIMUS
		{
			Log_SetActiveAction("Nothing");
			if(CheckAttribute(GetMainCharacter(),"autoreload"))
			{
				if(characters[GetMainCharacterIndex()].location!=characters[GetMainCharacterIndex()].autoreload.location)
				{
					DeleteAttribute(GetMainCharacter(),"autoreload.location");
					DeleteAttribute(GetMainCharacter(),"autoreload.locator");
					DeleteAttribute(GetMainCharacter(),"autoreload");
				}
			}
			chrWaitReloadLocator = "";
			chrWaitReloadIsNoLink = false;
			//ClearAllLogStrings();//MAXIMUS
			BreakLabelUpdate(chr);//MAXIMUS
			DeleteAttribute(GetMainCharacter(),"reloadStatus");
			if(locator == lockedReloadLocator)
			{
				lockedReloadLocator = "";
				return;
			}
		}
		break;
	case "camdetector":
		locCameraFollow();
		break;
	case "item":
		Item_OnExitLocator();//MAXIMUS: was (loc, locator) - for what?
		break;
	case "randitem":
		Item_OnExitLocator();//MAXIMUS: was (loc, locator) - for what?
		break;
	case "box":
		Box_ExitFromLocator();//MAXIMUS: was (loc, locator) - for what?
		break;
	}

	if( CheckAttribute(chr,"Quests.LocatorCheck." + group) )
	{
		chr.Quests.LocatorCheck.(group) = "";
	}
}

void chrCharacterKeys()
{
	ref mc = GetMainCharacter();	// ccc random locs, moved here
	string controlName = GetEventData();
	if(controlName != "ChrAction") return;
	//Skip if interface active
	if(sti(InterfaceStates.Launched)==true) return;
	//Skip is disable reload
	bool noReload = false;
	if(chrIsNowEnableReload() != true) noReload = true;
	//Skip free links
	if(chrWaitReloadIsNoLink != false) noReload = true;
	if(chrWaitReloadLocator == "") noReload = true;
	if(noReload)
	{
		if(chrWaitReloadLocator != "")
		{
			// ccc random locs
			if(!RANDOM_LOCS_TOGGLE) PlayLocatorSound(&Locations[FindLocation(mc.location)], "reload", chrWaitReloadLocator, "knock", 1.8);//MAXIMUS: PlayStereoSound("knock");
			else {
			if(chrWaitReloadLocator != "reload1") { GoToRandomLoc(); }	// ccc random locs
			else { DoQuestReloadToLocation(mc.lastlocation, "reload", mc.lastlocator ,"_"); } }
		}
		return;
	}
	//trace(" &&&&&&&&&&&&&&&&&&&&&&&&&&& ");
	//Remove icon
	//Start reload
	// ccc, moved up:  ref mc = GetMainCharacter();
// KK -->
	if (bDeckEnter) return;

	if (VISIT_DECK == 1 && mc.location == mc.location.from_sea) {
		ref loc = &Locations[FindLocation(mc.location)];
		string island = loc.island;
		aref rl, at;
		makearef(rl, loc.reload);
		int num = GetAttributesNum(rl);
		for (int i = 0; i < num; i++) {
			at = GetAttributeN(rl, i);
			if (CheckAttribute(at, "name")) {
			  if (at.name == chrWaitReloadLocator) break;
			}
		}

		if (at.go == island) {
			bToDeckFromLand = true;
			if(dialogRun || dialogSelf) { DialogExit(); }//MAXIMUS -->
			mc.condition = "reload";
			Log_SetActiveAction("Nothing");//MAXIMUS <--
			iShipCaptain = GetMainCharacterIndex();
			Land_DeckStartNow(iShipCaptain, GetCharacterShipQDeck(GetCharacter(iShipCaptain)));
			chrWaitReloadLocator = "";
			chrWaitReloadIsNoLink = false;
			return;
		}
	}
// <-- KK
	Reload(chrWaitReloadRef, chrWaitReloadLocator, mc.location);
}

bool chrIsNowEnableReload()
{
	//Skip if not set reload locator
	if(chrWaitReloadLocator == "") return false;
	//Skip if active dialog
	if(DialogRun != 0) return false;
	//Skip
	if(chrCheckReload(chrWaitLocationRef, chrWaitReloadLocator) == 0) return false;
	//Skip if disabled in quest movie
	if(chrIsEnableReload() != true) return false;	
	return true;
}


#event_handler("EventStartQuestMovie","chrChangeReloadStateHndl");
#event_handler("EndStartQuestMovie","chrChangeReloadStateHndl");
#event_handler(EVENT_DIALOG_START,"chrChangeReloadStateHndl");
#event_handler(EVENT_DIALOG_EXIT,"chrChangeReloadStateHndl");
#event_handler("EnableReloadLocatorEvent","chrChangeReloadStateHndl");
#event_handler("chrCheckChangeOpenStateEvent","chrCheckChangeOpenState");

void chrChangeReloadStateHndl()
{
	PostEvent("chrCheckChangeOpenStateEvent", 1);
}

void chrCheckChangeOpenState()
{
	if(chrWaitReloadLocator == "") return;
	CheckReloadAction(GetMainCharacter(), "");//MAXIMUS
}

bool chrIsEnableReload()
{
	if(DialogRun != 0) return false;
	if(qmIsNoReload() != false) return false;
	return true;
}



void GoToRandomLoc()	// ccc random locs
{
	if(!RANDOM_LOCS_TOGGLE) { Logit("Random locs disabled!"); return; }

	string randloc = "Randomhouse"+rand(13);

	DoQuestReloadToLocation(randloc, "reload", "reload1" ,"_");


	Log_SetActiveAction("Nothing");	// deletes padlock icon

}
