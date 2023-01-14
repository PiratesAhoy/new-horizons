
#define RELOAD_TIME_FADE_OUT	0.5
#define RELOAD_TIME_FADE_IN		0.5

object reload_fader;
aref reload_locator_ref;
int reload_cur_island_index, reload_cur_location_index;
int reload_island_index, reload_location_index;

object reload_xaddress;

bool LoadMainCharacterInFirstLocation(string location_id, string locator_group, string emerge_locator, string ship_location)
{
	int lindex = -1; // KK
	//Find ship location
	if(ship_location != "")
	{
		lindex = FindLocation(ship_location);
		if(lindex < 0)
		{
			trace("Incorrect location id for location character's ship (location " + ship_location + " not found)");
		}
	}
	if(lindex >= 0)
	{
		SetPlayerShipLocation(lindex);
		PlaceFleetNearShore(ship_location); // KK
	}
	//Find location
	lindex = -1;
	lindex = FindLocation(location_id);
	if(lindex < 0)
	{
		trace("Incorrect location id for first location (location " + location_id + " not found)");
		return false;
	}
	trace("!!! Reload to " + location_id + " (index=" + lindex + ")"); // KK
	//Find reload data
	aref reload_group;
	aref locator_ref;
	aref curLoc;
	string new_emerge = "";
	ref mc = GetMainCharacter();

	bool bChange = locator_group!="reload";
	if(bChange) bChange = locator_group!="rld";
	makearef(reload_group, Locations[lindex].reload);

	if(GetAttributesNum(reload_group)==0 || bChange)//MAXIMUS: full check for wrong locators
	{
		if(GetAttributesNum(reload_group)==0) trace("Locator group <" + locator_group + "> for first location <" + location_id + "> isn't correct!");

		Locations[lindex].testing = true;
		LoadLocation(&Locations[lindex]);
		makearef(curLoc, Locations[lindex].locators);
		for(int i=0; i<GetAttributesNum(curLoc); i++)
		{
			aref arLoc = GetAttributeN(curLoc,i);
			if(GetAttributeName(arLoc)=="") continue;
			string arLocName = GetAttributeName(arLoc);
			if(arLocName=="rld" || arLocName=="goto")
			{
				makearef(arLoc,Locations[lindex].locators.(arLocName));
				for(int j=0; j<GetAttributesNum(arLoc); j++)
				{
					if(GetAttributeName(GetAttributeN(arLoc,j))=="") continue;
					locator_group = arLocName;
					trace("New locator group for first location is <" + locator_group + ">!");
					emerge_locator = GetAttributeName(GetAttributeN(arLoc,j));
					new_emerge = emerge_locator;
					trace("New emerge locator for first location is <" + emerge_locator + ">!");
					break;
				}
			}
			if(new_emerge==emerge_locator) break;
		}
		DeleteAttribute(&Locations[lindex],"testing");
		UnloadLocation(&Locations[lindex]);
		if(new_emerge!=emerge_locator)
		{
			trace("Location " + location_id + " hasn't reload groups!");
			InterfaceStates.LaunchAnyway = true;
			LaunchMainMenu();
			return false;
		}
	}
	else
	{
		if(emerge_locator!="")
		{
			if(locator_group=="reload" && FindEmergeLocator(&Locations[lindex], emerge_locator)=="")
			{
				trace("Emerge locator " + emerge_locator + " in location " + location_id + " not found!");
				locator_ref = GetAttributeN(reload_group, 0);
				emerge_locator = locator_ref.name;
				trace("Character emerge on first locator (" + emerge_locator + ")");
			}
		}
		else
		{
			locator_ref = GetAttributeN(reload_group, 0);
			emerge_locator = locator_ref.name;
		}
	}

	lockedReloadLocator = emerge_locator;
	mc.location = Locations[lindex].id;
	mc.location.group = locator_group; // KK
	mc.location.locator = emerge_locator;
	if (!IsEntity(&chrAnimationKipper)) CreateEntity(&chrAnimationKipper, "CharacterAnimationKipper");
	if (CheckAttribute(mc, "newGameStart") && sti(mc.newGameStart) == true) DeleteAttribute(mc, "newGameStart"); // KK

	ReloadProgressUpdate();

	if(!LoadLocation(&Locations[lindex]))
	{
		InterfaceStates.LaunchAnyway = true;
		LaunchMainMenu();
		trace("LoadMainCharacterInFirstLocation: Error during LoadLocation!");
		return false;
	}

	//Fader
	PostEvent("LoadSceneSound", 500);
	return true;
}

void SetPlayerShipLocation(int location_index)
{
	//Main character
	if(location_index < 0)
	{
		Trace("SetPlayerShipLocation - incorrect location index");
		return;
	}
	ref mc = GetMainCharacter();
	mc.location.from_sea = ""; // KK
	if (GetCharacterShipType(mc) == SHIP_NOTUSED) return; // KK
	mc.location.from_sea = Locations[location_index].id;
	SetFleetInTown(GetTownIDFromLocID(mc.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
}


//reload_group = xxx.reload
int Reload(aref reload_group, string locator_name, string current_location)
{
	ref PChar = GetMainCharacter();
	if(dialogRun || dialogSelf)//MAXIMUS -->
	{
		DialogExit();
	}
	PChar.condition = "reload";//MAXIMUS <--
	if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_TIPS")) < 1) SetReloadNextTipsImage(); // JRH

// changed by MAXIMUS -->
	dialogDisable = !ownDeckStarted(); // KK
// changed by MAXIMUS <--

	reload_xaddress.active = "false";
	//Check locked locator
	trace("Reload: Process started for locator_name = " + locator_name + " and lockedReloadLocator = " + lockedReloadLocator); // PB
	if(locator_name == lockedReloadLocator)
	{
		if(CheckAttribute(PChar, "ForceReload")) // PB: To fix potentially getting stuck
		{
			TraceAndLog("Reload: Continue despite locked locator. Please post your compile.log file at piratesahoy.net!"); // PB: For testing
		}
		else
		{
			lockedReloadLocator = "";
	//		PlaySound("knock");//MAXIMUS
			return -1;
		}
	}
	DeleteAttribute(PChar, "ForceReload"); // PB
	//Find reload data
	int num = GetAttributesNum(reload_group);
	if(num == 0) { /*PlaySound("knock");*/ return 0; }//MAXIMUS
	for(int i = 0; i < num; i++)
	{
		reload_locator_ref = GetAttributeN(reload_group, i);
// added CheckAttribute by MAXIMUS -->
		if(CheckAttribute(reload_locator_ref,"name"))
		{
			if(locator_name == reload_locator_ref.name) break;
		}
// added CheckAttribute by MAXIMUS <--
	}
	if(i == num)
	{
//		if (Locations[FindLoadedLocation()].id == locator_name) return 0; // KK
		trace("Can't reload...");
		trace("Reload locator '" + locator_name + "' in current location " + current_location + " not found!");	// LDH added location 11Mar09
//		PlaySound("knock");//MAXIMUS
		return 0;
	}
	//Check main attributes
	if(CheckAttribute(reload_locator_ref, "name") == 0)
	{
		trace("Can't reload...");
		trace("Reload: attribute 'name' in " + GetAttributeName(reload_locator_ref) + " not accessible");
//		PlaySound("knock");//MAXIMUS
		return 0;
	}
	if(CheckAttribute(reload_locator_ref, "go") == 0)
	{
		trace("Can't reload...");
		trace("Reload: attribute 'go' in " + GetAttributeName(reload_locator_ref) + " not accessible");
//		PlaySound("knock");//MAXIMUS
		return 0;
	}
	if(CheckAttribute(reload_locator_ref, "emerge") == 0)
	{
		trace("Can't reload...");
		trace("Reload: attribute 'emerge' in " + GetAttributeName(reload_locator_ref) + " not accessible");
//		PlaySound("knock");//MAXIMUS
		return 0;
	}
	//Find current location
	reload_cur_island_index = -1;
	reload_cur_location_index = -1;
	if(current_location != "")
	{		
		reload_cur_island_index = FindIsland(current_location);
		if(reload_cur_island_index < 0)
		{
			reload_cur_location_index = FindLocation(current_location);
			if(reload_cur_location_index < 0)
			{
				trace("Can't unload currend location...");
				trace("Current location not found: id = " + current_location);
//				PlaySound("knock");//MAXIMUS
//				return 0;
			}
		}
	}
	//Find location & reload
	reload_island_index = -1;
	reload_location_index = -1;

	//JRH: reloading in fightmode with a musket not charged could mean firing from shoulder mode in the next location
	if(LAi_IsFightMode(Pchar))
	{
		LAi_QuestDelay("pchar_hip_mode_check", 0.1);
	}

	reload_island_index = FindIsland(reload_locator_ref.go);
	if(reload_island_index < 0)
	{
		reload_location_index = FindLocation(reload_locator_ref.go);
		if(reload_location_index < 0)
		{
			trace("Can't reload...");
			trace("Location not found: id = " + reload_locator_ref.go);
//			PlaySound("knock");//MAXIMUS
			return 0;
		}
	}
	//Main character
	ref mc = GetMainCharacter();
	trace("reload_cur_island_index = " + reload_cur_island_index);
	trace("reload_cur_location_index = " + reload_cur_location_index);
	trace("reload_island_index = " + reload_island_index);
	trace("reload_location_index = " + reload_location_index);
	//Test in sea exit
	if((reload_cur_island_index < 0) && (reload_island_index >= 0))
	{
		if(reload_cur_location_index >= 0)
		{
			//From location to sea
			if(Locations[reload_cur_location_index].id != mc.location.from_sea)
			{
				trace("Not reload to sea, no ships: cur:" + Locations[reload_cur_location_index].id + " from:" + mc.location.from_sea);
//				PlaySound("knock");//MAXIMUS
				return -1;
			}
		}
	}
	//Start fader
	SetEventHandler("FaderEvent_StartFade", "ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "ReloadEndFade", 0);
	if (!IsEntity(&reload_fader)) { // KK
		CreateEntity(&reload_fader, "fader");
		bool bPicture = CheckAttribute(mc,"newGameStart")==false;//MAXIMUS -->
		if(!bPicture) bPicture = HasSubStr(mc.location,"deck")==true;
		if(bPicture)
		{
			if(reload_island_index>=0)
			{
				// KK -->
				if (VISIT_DECK == 0)
					SetReloadImage(&reload_fader, "Landing");
				else
					SetReloadImage(&reload_fader, "Sea");
				// <-- KK
			}
			else
			{
				int loc_pict_index = reload_location_index;
				if(loc_pict_index<0) loc_pict_index = reload_cur_location_index;
				if(loc_pict_index>=0)
				{
					if(CheckAttribute(&Locations[loc_pict_index],"image"))
					{
						// PB: Random Loading Screens -->
						aref LoadingScreens;
						string LoadingImage;
						makearef(LoadingScreens,Locations[loc_pict_index].image);
						int image_count = GetAttributesNum(LoadingScreens);
						LoadingImage = Locations[loc_pict_index].image;
						if (image_count > 0) {
							switch(1 + rand(image_count - 1))
							{
								case 1: LoadingImage = Locations[loc_pict_index].image.1; break;
								case 2: LoadingImage = Locations[loc_pict_index].image.2; break;
								case 3: LoadingImage = Locations[loc_pict_index].image.3; break;
								case 4: LoadingImage = Locations[loc_pict_index].image.4; break;
								case 5: LoadingImage = Locations[loc_pict_index].image.5; break;
							}
						}
						SetReloadImage(&reload_fader, LoadingImage);
						// PB: Random Loading Screens <--
					}
				}
			}
		}//MAXIMUS <--

		bool IsMakeShot = true;
		float fadeOutTime = RELOAD_TIME_FADE_OUT;
		if (reload_cur_island_index<0 && reload_cur_location_index<0)
		{
			fadeOutTime = 0.00001;	//Can't need fade out - no loaded location
			IsMakeShot = false;
		}
		SendMessage(&reload_fader, "lfl", FADER_OUT, fadeOutTime, false);
		if(IsMakeShot) SendMessage(&reload_fader, "l", FADER_STARTFRAME);
	}
	//Set lockedReloadLocator
	if(reload_cur_island_index < 0)
	{
		//From location
		if (reload_island_index < 0)
			lockedReloadLocator = reload_locator_ref.emerge;//To location
		else
			lockedReloadLocator = "";//To sea
	} else {
		//From sea
		if (reload_island_index < 0)
			lockedReloadLocator = reload_locator_ref.emerge;//To location
		else
			lockedReloadLocator = "";//To sea
	}
	if (CheckAttribute(GetMainCharacter(), "autoreload")) {
		Characters[GetMainCharacterIndex()].autoreload.location = current_location;
		Characters[GetMainCharacterIndex()].autoreload.locator = chrWaitReloadLocator;
	}
	Log_SetActiveAction("Nothing");//MAXIMUS
	chrWaitReloadLocator = "";//MAXIMUS
	chrWaitReloadIsNoLink = false;//MAXIMUS
	Trace("Start reload");
	return 1;
}

void ReloadStartFade()
{
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "ReloadStartFade");
	Trace("ReloadStartFade");
	//Main character
	ref mc = GetMainCharacter();
	if(reload_cur_island_index < 0)
	{
		//From location
		if(reload_island_index < 0)
		{
			//To location
			if(reload_cur_location_index >= 0) UnloadLocation(&Locations[reload_cur_location_index]);
			return;
		} else {
			//To sea
			if (reload_cur_location_index >= 0) {
				UnloadLocation(&Locations[reload_cur_location_index]);
			} else {
				mc.location.from_sea = "";
				SetFleetInTown(GetTownIDFromLocID(mc.location.from_sea), "pchar");
			} // NK WM/IT 05-04-02
			DeleteClass(&chrAnimationKipper);
			return;
		}
	} else {
		//From sea
		if(reload_island_index < 0)
		{
			//To location
			DeleteSeaEnvironment();
			mc.location.from_sea = reload_locator_ref.go;
			SetFleetInTown(GetTownIDFromLocID(mc.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			// LDH update the merchants when going to port
			// other updates are more appropriate if you've stayed overnight in town, these updates happen in DoDailyUpdates()
			// When worldmap sailing is fixed to properly update the merchants, these three update lines should be removed
			UpdateAllTowns(false);			// This gives the town proper itemtrade values so merchants have goods first visit - 30Jan09 
//			UpdateAllItemTraders(false);	// This gives the merchants new goods if they need them - 07Feb09
//			UpdateAllStores(false);			// This is probably not necessary, but added just to be sure - 07Feb09

			// PB: One value on Salary and another on Articles -->
			bool articles = false;
			if (CheckAttribute(mc, "articles") == true && sti(mc.articles) == true) articles = true;
			if (!articles)
			{
				int explength = 0;
				if(CheckAttribute(mc,"CrewStatus.explength")) explength = sti(mc.CrewStatus.explength);
				Trace("DS: Player ship was at sea for " + explength + " days");
				mc.CrewStatus.explength = 0;
			}
			// PB: One value on Salary and another on Articles <--
			mc.directsail.count = 0.0;	// LDH reset encounter frequency count when we go to port - 12Feb09
			FromDeckIdx = -1;			// LDH - character will go to boat location when returning to ship - 14Feb09
			bEmergeOnStartloc = false;	// LDH - character will go to boat location when returning to ship - 14Feb09
			return;
		} else {
			//To sea
			DeleteSeaEnvironment();
			mc.location.from_sea = "";
			SetFleetInTown(GetTownIDFromLocID(mc.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			return;
		}
	}
}

void ReloadEndFade()
{
	dialogDisable = false;
	ReloadProgressStart();
	DelEventHandler("FaderEvent_EndFade", "ReloadEndFade");
	Trace("ReloadEndFade");
	ReloadProgressUpdate();
	//Main character
	ref mc = GetMainCharacter();
	if(reload_cur_island_index < 0)
	{
		//From location
		if (reload_island_index < 0)
			ReloadToLocation(reload_location_index, reload_locator_ref);//To location
		else
			ReloadToSea(reload_island_index, reload_locator_ref);//To sea
	} else {
		//From sea
		if (reload_island_index < 0)
			ReloadToLocation(reload_location_index, reload_locator_ref);//To location
		else
			ReloadToSea(reload_island_index, reload_locator_ref);//To sea
	}
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	PostEvent("LoadSceneSound", 500);
	ReloadProgressEnd();

	// added after build 11 by KAM -->
	if (CheckAttribute(mc,"ShipBerthing.DoInvoice"))
	{
		SBInvoiceOnLanding(-1);
		DeleteAttribute(mc.ShipBerthing,"DoInvoice");
	}
	// <-- added after build 11 by KAM
}

string	FindEmergeLocator(ref rObject, string emerge_str)
{
	aref arReload;
	makearef(arReload,rObject.reload);
	int n = GetAttributesNum(arReload);
	for (int i=0;i<n;i++)
	{
		aref arLoc;
		arLoc = GetAttributeN(arReload,i);
		if(!CheckAttribute(arLoc, "name")) continue;//MAXIMUS
		if (arLoc.name == emerge_str) 
		{
			string loc_name = GetAttributeName(arLoc);
			return loc_name;
		}
	}
 	Trace("ERROR(no find emerge string): string FindEmergeLocator(ref rObject, string emerge_str) : " + emerge_str);
	return "";
}

object chrAnimationKipper;

int ReloadToLocation(int location_index, aref reload_data)
{
	ref mc = GetMainCharacter();
	mc.location = Locations[location_index].id;
	mc.location.group = "reload";
	mc.location.locator = reload_data.emerge;
	if(reload_xaddress.active == "true")
	{
		mc.location.group = reload_xaddress.group;
		mc.location.locator = reload_xaddress.locator;
	}
	if(IsEntity(&chrAnimationKipper) == false) CreateEntity(&chrAnimationKipper, "CharacterAnimationKipper");
	return LoadLocation(&Locations[location_index]);
}

int ReloadToSea(int island_index, aref reload_data)
{
	object Login;

	ref rPlayer = GetMainCharacter();
	rPlayer.lastFightMode = 0;

	ref rIsland = GetIslandByIndex(island_index);
	/*Trace("============================");
	Trace("island_index = " + island_index);
	DumpAttributes(rIsland);
	Trace("============================");*/

	rPlayer.location = rIsland.id;
	rPlayer.location.group = "reload";
	rPlayer.location.locator = reload_data.emerge;

	Login.Island = rIsland.id;

	Login.Encounters = "";

// KK -->
	//string sLoc = FindEmergeLocator(rIsland,reload_data.emerge);

	aref rIslLoc = FindIslandReloadLocator(rIsland.id, reload_data.emerge);
	Login.PlayerGroup.x = rIslLoc.x;
	Login.PlayerGroup.z = rIslLoc.z;
	Login.PlayerGroup.ay = 0.0;
	if (CheckAttribute(rIslLoc, "ships.l0.ay")) Login.PlayerGroup.ay = rIslLoc.ships.l0.ay;
	if (CheckAttribute(rIslLoc, "ay")) Login.PlayerGroup.ay = rIslLoc.ay;
// <-- KK
	Login.FromCoast = true;

	//Trace("Load from location to sea sLoc = " + rIslLoc.name + ", x = " + Login.PlayerGroup.x + ",z = " + Login.PlayerGroup.z+ ",ay = "+Login.PlayerGroup.ay);
		
	SeaLogin(Login);

	SupplyAmmo(false); // JRH

	return 1;
}

bool TeleportCharacterFromCurLocationToLocation(string locatorExit, string group, string locator)
{
	reload_xaddress.group = group;
	reload_xaddress.locator = locator;
	aref reload_group;
	makearef(reload_group, loadedLocation.reload);
	if(Reload(reload_group, locatorExit, loadedLocation.id) == false) return false;
	reload_xaddress.active = "true";
	return true;
}

// KK -->
string FindReloadPicture(string fname)
{
	string result;

	result = FindReloadTextureName(fname, "RESOURCE\Textures\Loading\" + LanguageGetLanguage());
	if (result != "") return result;

	result = FindReloadTextureName(fname, "RESOURCE\Textures\Loading");
	if (result != "") return result;

	result = FindReloadTextureName(fname, "RESOURCE\Textures\Loading\ENGLISH");
	if (result != "") return result;

	result = FindReloadTextureName(fname, "RESOURCE\Textures\INTERFACES\BACKGROUND");
	if (result != "") return result;

	return "";
}

string FindReloadTextureName(string fname, string folder) {
	if (FindFile(folder, "*.tga.tx", fname + ".tx") != "")
        return folder + "\" + fname;
	if (FindFile(folder, "*.tga", fname) != "")
        return folder + "\" + fname;
	if (FindFile(folder, "*.tga.tx", fname + ".tga.tx") != "")
        return folder + "\" + fname + ".tga.tx";
	if (FindFile(folder, "*.tga", fname + ".tga") != "")
        return folder + "\" + fname + ".tga";
	if (FindFile(folder, "*.png", fname + ".png") != "")
        return folder + "\" + fname + ".png";
    if (FindFile(folder, "*.jpg", fname + ".jpg") != "")
        return folder + "\" + fname + ".jpg";
    return "";
}

void SetReloadImage(ref fader, string image) {
	SendMessage(fader, "ls", FADER_PICTURE0, FindReloadPicture("background"));
	SendMessage(fader, "ls", FADER_PICTURE, FindReloadPicture(image));
}

// <-- KK
