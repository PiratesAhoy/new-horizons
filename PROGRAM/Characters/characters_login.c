void LoginCharactersInLocation(ref loc)
{
	int i;
	string locID = loc.id;
	LocAi_Init(loc);
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		if (loc.type == "Dungeon" && IsOfficer(&Characters[i]) && CheckAttribute(&Characters[i], "AbordageMode") && makeint(Characters[i].AbordageMode) == 0) {
			continue;
		} // NK based on BOAL 05-05-01 dungeons count as boarding, Swindler added CheckAttribute() to avoid runtime errors
		if (loc.type == "Deck" && IsOfficer(&Characters[i]) && CheckAttribute(&Characters[i], "AbordageMode") && makeint(Characters[i].AbordageMode) == 0) {
			continue;
		} // KK
		LoginCharacter(&Characters[i], locID);
	}
	if(actLoadFlag)
	{
		for(i = 0; i < 32; i++)
		{
			LoginCharacter(&Characters[LOC_FANTOM_CHARACTERS + i], locID);
		}
	}
	LocAi_PostInit(loc);

	if(!actLoadFlag) Build_again(loc);	// ccc building kit, restores buildings
}

void LoginCharacter(aref chr, string locID)
{
	if(CheckAttribute(chr,"condition") && chr.condition=="reload") { DeleteAttribute(chr,"condition"); }//MAXIMUS: for skipping dialog with character
	if(IsMainCharacter(chr))
	{
	//	ResetTimeToNormal();//MAXIMUS: removes time-acceleration and sets normal time
		if(!CheckAttribute(chr,"systemStatus")) { chr.systemStatus = "up"; systemStatus = chr.systemStatus; }//MAXIMUS: for several things
		if(CheckAttribute(chr,"TrainingFight")) DeleteAttribute(chr,"TrainingFight");//MAXIMUS: if player leaved ShipDeck before his training was finished - this will help :)
		if(CheckAttribute(chr,"location.first"))//MAXIMUS: checking fastreload on tutorial deck
		{
			if(HasSubStr(locID,"tutorial") || HasSubStr(locID,"deck") || HasSubStr(locID,"cabin"))
			{
				DisableFastTravel(true);
				if(HasSubStr(locID,"ShipDeck")) Whr_UpdateWeather(false);
				else WhrDeleteRainEnvironment();
			}
			else
			{
				DeleteAttribute(chr,"location.first");
				DisableFastTravel(false);
				Whr_UpdateWeather(false);
				if(CheckAttribute(chr,"newGameStart") && chr.newGameStart==true) DeleteAttribute(chr,"newGameStart");
			}
		}
		if(!CheckAttribute(&locations[FindLocation(locID)],"fastreload") || locations[FindLocation(locID)].fastreload!="ship") ClearDeck();//MAXIMUS: I'd tried to find a better place, but wasn't be able
	}
	if(LAi_CharacterLogin(chr, locID))
	{
		bool isNoCreated = true;
		if(CreateCharacter(chr))
		{
			isNoCreated = false;
			if(TeleportCharacterToLocator(chr, chr.location.group, chr.location.locator)==0)
			{
				if(IsMainCharacter(chr))
				{
					// ccc  Greater Oxbay mod. To enable entry to non-reload-group locators
				/*	if(chr.location.locator=="randitem2") chr.location.group = "randitem";

					else{if(chr.location.locator=="Goto2") chr.location.group = "goto";} // for Greenford suburb
					else{if(chr.location.locator=="Goto4") chr.location.group = "goto";} // for shipyard ladder*/

					// JRH: Rewritten code to be generic -->
					chr.location.group = "goto"; //default locatorgroup
					if(HasSubStr(chr.location.locator, "randitem")) chr.location.group = "randitem";
					if(HasSubStr(chr.location.locator, "monster")) chr.location.group = "monsters"; //for all dungeons 
					// JRH: Rewritten code to be generic <--

					TeleportCharacterToLocator(chr, chr.location.group, chr.location.locator);
					// ccc end

					traceif("Main character <" + chr.id + "> error teleportation by location: " + chr.location + "  on locator: " + chr.location.group + "::" + chr.location.locator);
				}else{
					isNoCreated = true;
					DeleteCharacter(chr);
					traceif("Delete character <" + chr.id + "> , error teleportation by location: " + chr.location + " on locator: " + chr.location.group + "::" + chr.location.locator);
				}
			}
			SetUpCharacterWeapons(chr); //Levis moved this stuff here so it's only checked for loged in characters
			SetUpCharacterNationName(chr); //Levis moved this stuff here so it's only checked for loged in characters
		}else{
			traceif("Can't create character: " + chr.id);
		}
		if(isNoCreated)
		{
			LAi_CharacterLogoff(chr);
			return;
		}
	}
// <-- KK
}

//Levis let's move some stuff to a function to make it easier to read
void SetUpCharacterNationName(ref chr)
{
	//MAXIMUS: used in GetCharacterAddressForm -->
	int iNation = PIRATE;
	if (CheckAttribute(chr,"nation") && sti(chr.nation) >= 0 && sti(chr.nation)<NATIONS_QUANTITY) iNation = sti(chr.nation);
	if (!CheckAttribute(chr,"nation.name")) chr.nation.name = iNation;
	//MAXIMUS: used in GetCharacterAddressForm <--
}

void SetUpCharacterWeapons(ref chr)
{
	if (CheckAttribute(chr,"itemtrade")) return; // PB: Merchants shouldn't equip their own stock
	if (isSoldier(chr) != UNKNOWN_NATION) GiveSoldierWeapon(chr, makeint(GetAttribute(chr, "nation")));	// PB: Re-Update Soldier Weapons
// KK -->
	if (CheckAttribute(chr, "old.blade")) {
		if (GetCharacterItem(chr, chr.old.blade) == 0) GiveItem2Character(chr, chr.old.blade);
		DeleteAttribute(chr, "old.blade");
	}
	if (CheckAttribute(chr, "old.gun")) {
		if (GetCharacterItem(chr, chr.old.gun) == 0) GiveItem2Character(chr, chr.old.gun);
		DeleteAttribute(chr, "old.gun");
	}
	string equipitm = GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE);
	string equipfound = FindCharacterItemByGroup(chr, BLADE_ITEM_TYPE);
	// ccc special weapons, rearm disarmed chr
	if (equipitm == "" && equipfound != "") {
		EquipCharacterByItem(chr, equipfound);
	} else {
		if (equipitm != "") EquipCharacterByItem(chr, equipitm);
	}
	// ccc end
	equipitm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	equipfound = FindCharacterItemByGroup(chr, GUN_ITEM_TYPE);
	if (equipitm == "" && equipfound != "") {
		EquipCharacterByItem(chr, equipfound);
     //JRH ammo mod -->
		if (ENABLE_AMMOMOD) {	// LDH change
			TakenItems(chr, "gunpowder", -6);
			TakenItems(chr, "pistolbullets", -6);
			TakenItems(chr, "gunpowder", 1 + rand(2));
			TakenItems(chr, "pistolbullets", 1 + rand(2));
		}
     //JRH ammo mod <--
	} else {
		if (equipitm != "") EquipCharacterByItem(chr, equipitm);
	}
}

// PB -->
void LogoffCharactersFromLocation(ref loc)
{
	int i;
	ref chr;
	string locID = loc.id;
	for(i = 0; i < LAi_numloginedcharacters; i++) //Levis: only use logged in characters
	{
		chr = &Characters[LAi_loginedcharacters[i]]; //Levis: only use logged in characters
	//	if (!CheckAttribute(chr, "location"))	continue; // PB: Then we don't need this anymore, do we?
	//	if (chr.location != locID)				continue; // PB: Same here
		if (HasSubStr(chr.id, "Enc_Officer_"))
		{
			if(bAllies(chr))									{ continue; }
			if(LAi_IsBoardingProcess())
			{
				if (chr.id == boarding_enemy.id)				{ continue; }	// PB: Skip the captain of the ship you're currently boarding
				if (IsOfficerOf(boarding_enemy, chr))			{ continue; }	// MM: Skip also any officers assigned to this ship
			}
		//	TraceAndLog("LogoffCharactersFromLocation clears " + GetMySimpleName(chr));
			ClearCharacter(chr); // PB: Completely erase the unused character
		}
	}
}
// PB <--

void LogoffCharacter(aref chr)
{
	if(IsEntity(chr))
	{
		LAi_CharacterLogoff(chr);
		CharacterExitFromLocation(chr);
	}
}


bool ChangeCharacterAddress(ref character, string location_id, string locator)
{
	return ChangeCharacterAddressGroup(character, location_id, "goto", locator);
}

string GetCharacterShipLocation(ref rCharacter)
{
	if (CheckAttribute(rCharacter,"location.from_sea")) return rCharacter.location.from_sea;
	traceif("Character '" + rCharacter.id + "' location.from_sea is absent");
	return "None";
}

bool SetCharacterShipLocation(ref character, string location_id)
{
	int lindex = FindLocation(location_id);
	if(lindex < 0)
	{
		traceif("Incorrect location id 'SetCharacterShipLocation' for character " + character.id + ", index " + character.index + ", set ship location " + location_id + " not found!");
		//traceif("Incorrect location id 'SetCharacterShipLocation' (location '" + location_id + "' not found)");
		return false;
	}
	character.location.from_sea = location_id;
	if(IsMainCharacter(character)) SetFleetInTown(GetTownIDFromLocID(character.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
	return true;
}

bool ChangeCharacterShipGroup(ref rCharacter, string group_id)
{
	rCharacter.Ship.AI.GroupName = group_id; // NK I think this should be:
	rCharacter.SeaAI.Group.Name = group_id; // this. 05-04-20
	if (IsEntity(&AISea))
	{
		SendMessage(&AISea,"las",AI_MESSAGE_SHIP_CHANGE_GROUP,&rCharacter,group_id);
	}
	return true;
}

bool SetCharacterIslandLocation(ref character, string location_id, string group, string locator, string group_id, string task, string target_group_id)
{
	bool bRet = ChangeCharacterAddressGroup(character, location_id, group, locator);
	if (!bRet) return false;
	character.Ship.AI.GroupName = group_id; // NK I think this should be:
	character.SeaAI.Group.Name = group_id; // this. 05-04-20
	character.Ship.AI.Task = task;
	character.Ship.AI.Task.Group = target_group_id;
	return true;
}

#event_handler("removeCondition", "RemoveAttribute");
void RemoveAttribute()
{
	aref chr = GetEventData();
	if(CheckAttribute(chr,"condition") && chr.condition=="reload") { DeleteAttribute(chr,"condition"); }
}

bool ChangeCharacterAddressGroup(ref character, string location_id, string group, string locator)
{
	//traceif("Change character address id = " + character.id + "; location = " + location_id + "; group = " + group + "; locator = " + locator);
	int lindex = FindLocation(location_id);
	character.condition = "reload";//MAXIMUS: for skipping dialog with character
	PostEvent("removeCondition", 2000, "i", character);
	if(lindex < 0)
	{
		//ѕереходим в морскую часть
		LogoffCharacter(character);
		lindex = FindIsland(location_id);
		if(location_id != "none" && lindex < 0) // KK
		{
			traceif("Incorrect location id 'ChangeCharacterAddressGroup' (location " + location_id + " not found");
			return false;
		}
		character.location = location_id;
		character.location.group = group;
		character.location.locator = locator;
		return true;
	}
	//≈сли перемещаемс€ в нутри одной локации, то просто телепортимс€
	if(CheckAttribute(character,"location") && location_id == character.location) // NK add checkattr 05-04-09
	{
		TeleportCharacterToLocator(character, group, locator);
		character.location = location_id;
		character.location.group = group;
		character.location.locator = locator;
		return true;
	}
	//≈сли загруженны, то выйдем из локации
	LogoffCharacter(character);
	//ѕеремещаемс€ в другую локацию
	string oldLocation = "none"; if(CheckAttribute(character, "location")) oldLocation = character.location; // NK add checkattr 05-04-09
	character.location = location_id;
	character.location.group = group;
	character.location.locator = locator;
	//≈сли локаци€ загруженна, то логинемс€
	if(IsEntity(&Locations[lindex]))
	{
		LoginCharacter(character, Locations[lindex].id);
		LAi_PostLoginInit(character);
	}
	return true;
}
