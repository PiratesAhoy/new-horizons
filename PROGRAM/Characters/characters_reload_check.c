

//Disable reload locator
bool chrEnableReloadLocator(string locationID, string reloadLocatorName, bool isEnable)
{
	Event("EnableReloadLocatorEvent", "ssl", locationID, reloadLocatorName, isEnable);
	//Location
	int li = FindLocation(locationID);
	if(li < 0) return false;
	//Reload locator
	aref rl, at;
	makearef(rl, locations[li].reload);
//	int disableVal = 0;
	int num = GetAttributesNum(rl);
	for(int i = 0; i < num; i++)
	{
		at = GetAttributeN(rl, i);
		if(at.name == reloadLocatorName)
		{
		/*	if(CheckAttribute(at,"disable")) disableVal = sti(at.disable);
			if(isEnable) disableVal--; else disableVal++;
			if(disableVal <= 0) DeleteAttribute(at,"disable"); else at.disable = disableVal;*/
			if(isEnable) DeleteAttribute(at,"disable"); else at.disable = 1; // PB: Simplified
			return true;
		}
	}
	return false;
}


//locatorName
bool chrCheckReload(ref loc, string reloadLocatorName)
{
	//Reload locator
	aref rl, at;
	makearef(rl, loc.reload);
	int num = GetAttributesNum(rl);
	int disableVal = 0;
	for(int i = 0; i < num; i++)
	{
		at = GetAttributeN(rl, i);
		if(CheckAttribute(at, "name") && at.name == reloadLocatorName) // PB: For missing attribute
		{
			// Screwface : forbid the access to ship decks if you have no ship (for ship berthing)
			if (GetCharacterShipType(GetMainCharacter()) == SHIP_NOTUSED)
			{
 				if(CheckAttribute(at, "go") && at.go == loc.island)
				{
					if(!CheckAttribute(at, "olddisablevalue"))
					{
						if(CheckAttribute(at, "disable")) 
							at.olddisablevalue = sti(at.disable);
						else
							at.olddisablevalue = 0;
						at.disable = 1;
					}
				}
			}
			else // restore the old disable value or not
			{
				if(CheckAttribute(at, "olddisablevalue"))
				{
					If(at.olddisablevalue==0)
						DeleteAttribute(at, "disable");	
					else
						at.disable = sti(at.olddisablevalue);
					DeleteAttribute(at, "olddisablevalue");
				}
			} // End
			if(CheckAttribute(at, "goto_disable")) disableVal = sti(at.goto_disable); // Screwface : disable fast travel
			if(CheckAttribute(at, "disable")) disableVal = sti(at.disable);
			if(CheckAttribute(at, "close_for_night") && sti(at.close_for_night)>0)
			{
				if(GetTime()>22.0 || GetTime()<6.0) disableVal++;
			}
			if(CheckAttribute(at, "close_for_day") && sti(at.close_for_day)>0)	  //JRH
			{
				if(GetTime()>=6.0 && GetTime()<=22.0) disableVal++;
			}
			return disableVal <= 0;
		}
	}
	return false;
}

//locatorName
int chrCheckReloadLink(ref loc, string reloadLocatorName) // KK
{
	ref mc = GetMainCharacter(); // KK
	mc.reloadStatus = "Reload";//MAXIMUS: for more easy locator identification
	//Reload locator
	aref rl, at;
	makearef(rl, loc.reload);
	int num = GetAttributesNum(rl);
	int disableVal = 0;
	for(int i = 0; i < num; i++)
	{
		at = GetAttributeN(rl, i);
// KK -->
		if (CheckAttribute(at, "disabled") == true && sti(at.disabled) == true) {
			mc.reloadStatus = "Closed";
			return 1;
		}
// <-- KK
		if(CheckAttribute(at,"name"))
		{
			if(at.name == reloadLocatorName)
			{
				if (CheckAttribute(at, "goto_disable")){DeleteAttribute(at, "goto_disable");} // Screwface : we discovered the place
// KK -->
				if (at.go == "") {
					mc.reloadStatus = "Nothing";
					return 1;
				}
				if (at.go == "Sea") {
					if (iShipCaptain == GetMainCharacterIndex())
						mc.reloadStatus = "ToSea";
					else
						mc.reloadStatus = "Nothing";
					return 1;
				}
				int tmploc = FindLocation(at.go);
				if(tmploc > 0)//MAXIMUS: -[for more easy locator identification]->
				{
					ref goLoc = &Locations[tmploc];
					if (FindCurrentDeck() == "ShipDeck") {
						if (HasSubStr(at.go, "Hold")) mc.reloadStatus = "ToCargoHold";
						if (HasSubStr(at.go, "Deck")) mc.reloadStatus = "ToCannonsDeck";
						if (HasSubStr(at.go, "Seadog")) mc.reloadStatus = "ToSeaDogs";
						if (HasSubStr(at.go, "Tutorial_Deck")) mc.reloadStatus = "ToCabin";
						if (goLoc.type == "port" || goLoc.type == "town") mc.reloadStatus = "ToBoat";
						if (goLoc.type == "seashore") mc.reloadStatus = "ToBoat";
					}
					if (FindCurrentDeck() == "Cabin" && HasSubStr(at.go, "ShipDeck")) mc.reloadStatus = "ToShipDeck";
					if (FindCurrentDeck() == "Hold") {
						if (HasSubStr(at.go, "Deck")) mc.reloadStatus = "ToCannonsDeck";
						if (HasSubStr(at.go, "ShipDeck")) mc.reloadStatus = "ToShipDeck";
						if (HasSubStr(at.go, "Hold")) mc.reloadStatus = "ToCargoHold";
						if (HasSubStr(at.go, "Seadog")) mc.reloadStatus = "ToSeaDogs";
					}
					if (FindCurrentDeck() == "CannonsDeck") {
						if (HasSubStr(at.go, "Deck")) mc.reloadStatus = "ToCannonsDeck";
						if (HasSubStr(at.go, "ShipDeck")) mc.reloadStatus = "ToShipDeck";
						if (HasSubStr(at.go, "Hold")) mc.reloadStatus = "ToCargoHold";
						if (HasSubStr(at.go, "Seadog")) mc.reloadStatus = "ToSeaDogs";
					}
					if (FindCurrentDeck() == "Seadogs") {
						if (HasSubStr(at.go, "Deck")) mc.reloadStatus = "ToCannonsDeck";
						if (HasSubStr(at.go, "ShipDeck")) mc.reloadStatus = "ToShipDeck";
						if (HasSubStr(at.go, "Hold")) mc.reloadStatus = "ToCargoHold";
					}
					if (goLoc.type == "shop") {
						if (HasSubStr(goLoc.id, "_Store")) mc.reloadStatus = "ToStore";
						if (HasSubStr(goLoc.id, "_Shipyard") || HasSubStr(goLoc.id, "_yard")) mc.reloadStatus = "ToShipyard";
						if (HasSubStr(goLoc.id, "_TailorsShop")) mc.reloadStatus = "ToTailor";
						if (HasSubStr(goLoc.id, "_blacksmith")) 
						{
							mc.reloadStatus = "ToBlacksmith";
							if(goLoc.id == "Turks_blacksmith") mc.reloadStatus = "ToArsenal";	//JRH: gun or blade
							if(goLoc.id == "Con_blacksmith") mc.reloadStatus = "ToGunsmith";	//JRH: gun
						}
					}
					if (goLoc.type == "indian_shop") mc.reloadStatus = "ToIndianStore";			//JRH
					if (goLoc.type == "tavern") {
						if (HasSubStr(goLoc.id, "_Tavern")) mc.reloadStatus = "ToTavern";
						if (HasSubStr(goLoc.id, "_Tavern2")) mc.reloadStatus = "ToTavern2";		//JRH
						if (HasSubStr(goLoc.id, "_brothel")) mc.reloadStatus = "ToBrothel";
					}
					if (goLoc.type == "brothel") mc.reloadStatus = "ToBrothel";
					if (goLoc.type == "residence" && HasSubStr(goLoc.id, "_townhall")) mc.reloadStatus = "ToResidence";
					if (goLoc.type == "residence" && HasSubStr(goLoc.id, "_residence")) mc.reloadStatus = "ToResidence";
					if (HasSubStr(goLoc.id, "_Usurer")) mc.reloadStatus = "ToUsurer";
					if (HasSubStr(goLoc.id, "_gunsmith")) mc.reloadStatus = "ToGunsmith";		//JRH
					if (HasSubStr(goLoc.id, "_surgeon") || HasSubStr(goLoc.id, "apothecary")) mc.reloadStatus = "ToDoctor";		//JRH
					if (HasSubStr(goLoc.id, "_sailmaker")) mc.reloadStatus = "ToSailmaker";		//JRH
					if (HasSubStr(goLoc.id, "_library")) mc.reloadStatus = "ToLibrary";			//JRH
					if (CheckAttribute(goLoc, "id.label") && goLoc.id.label == "Opium Den") mc.reloadStatus = "ToOpium";			//JRH
					if (CheckAttribute(goLoc, "id.label") && goLoc.id.label == "Abbey of the Maltese order") mc.reloadStatus = "ToMaltese";	//JRH				
					if (CheckAttribute(goLoc, "id.label") && goLoc.id.label == "Order of Malta") mc.reloadStatus = "ToMaltese";		//JRH							//JRH
					if (CheckAttribute(goLoc, "id.label") && goLoc.id.label == "Naval academy") mc.reloadStatus = "ToAcademy";		//JRH
					if (goLoc.id == "Antigua_Residence" || goLoc.id == "Greenford Naval HQ" 
					 || goLoc.id == "Redmond Naval HQ" || goLoc.id == "Admiral_Office"
					 || goLoc.id == "Havana_House_03") mc.reloadStatus = "ToFightDeck";		//JRH
					if (goLoc.id == "EITC_Office") mc.reloadStatus = "ToEITC";				//JRH
					if (goLoc.id == "DWIC") mc.reloadStatus = "ToDWIC";					//JRH
					if (goLoc.type == "church" && HasSubStr(goLoc.id, "_church")) mc.reloadStatus = "ToChurch";
					if (goLoc.type == "Turks_church") mc.reloadStatus = "ToChurch";			//JRH
					if (goLoc.type == "jail") mc.reloadStatus = "ToPrison";
					if (goLoc.type == "military") {
						if (HasSubStr(goLoc.id, "_fakefort")) mc.reloadStatus = "ToFort";
						if (HasSubStr(goLoc.id, "_armory")) mc.reloadStatus = "ToArsenal";
					}
					if (goLoc.type == "town") mc.reloadStatus = "ToTown";
					if (goLoc.type == "jungle") mc.reloadStatus = "ToJungle";
					if (goLoc.type == "port" && FindCurrentDeck() == "") mc.reloadStatus = "ToPort";
					if (goLoc.type == "town" && HasSubStr(goLoc.id, "_port") && FindCurrentDeck() == "") mc.reloadStatus = "ToPort";
					if (goLoc.type == "seashore" && FindCurrentDeck() == "") mc.reloadStatus = "ToShore";//MAXIMUS
					if (CheckAttribute(at, "emerge")) mc.location.locator.emerge = at.emerge;
					return 1;
				}
				if (at.go == FindIslandByLocation(mc.location)) {
					// Screwface : If you have no ship, you can't go to sea, fix for ship berthing
					if(GetCharacterShipType(GetMainCharacter()) == SHIP_NOTUSED)
					{
						mc.reloadStatus = "nothing";
					}
					else
					{
						if (VISIT_DECK == 1 || bQuestDisableSeaEnter)
							mc.reloadStatus = "ToBoat";
						else
							mc.reloadStatus = "ToSea";
					}
					return 1;
				}
				//if (CheckAttribute(at, "go") && at.go != "") mc.reloadStatus = "Reload";
				return 1;
			} else {
				DeleteAttribute(mc, "reloadStatus");
			}
// <-- KK
		}
	}
	return 0;
}


//locatorName
bool chrCheckAutoReload(ref loc, string reloadLocatorName)
{
	//Reload locator
	aref rl, at;
	makearef(rl, loc.reload);
	int num = GetAttributesNum(rl);
	for(int i = 0; i < num; i++)
	{
		at = GetAttributeN(rl, i);
		if(at.name == reloadLocatorName)
		{
			if(CheckAttribute(at, "autoreload") == 0) return false;
			return MakeInt(at.autoreload) != 0;
		}
	}
	return false;
}













