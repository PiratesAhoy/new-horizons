#include "ships\ships.h"

#define 	SHIPYARD_SHIPS_HAVE_TUNES		1

extern void InitShips();
extern void InitRandomShipsNames();

string	sRndShpSpName[2], sRndShpEnName[2], sRndShpFrName[2], sRndShpPiName[2], sRndShpHoName[2], sRndShpPoName[2], sRndShpAmName[2], sRndShpSwName[2];

void ShipsInit()
{
	if (LoadSegment("ships\ships_init.c"))
	{
		InitShips();
		UnloadSegment("ships\ships_init.c");
	}
	if (LoadSegment("ships\ships_name.c"))
	{
		InitRandomShipsNames();
		UnloadSegment("ships\ships_name.c");
	}
}

void SetRandomNameToShip(ref rCharacter)
{
	int nat = sti(rCharacter.nation);
	if (bAllies(rCharacter))	nat = GetServedNation();
	if(nat >= NATIONS_QUANTITY)	nat = PIRATE; // 04-12-06 add nation >= NATIONS_QUANTITY handling
	rCharacter.Ship.Name = GetRandomShipNameForNation(nat);
}

string GetRandomShipNameForNation(int nat)
{
	ref rMassiveOfNames;
	switch (nat) // 04-12-06 change to var
	{
		case ENGLAND:  makeref(rMassiveOfNames, sRndShpEnName); break;
		case FRANCE:   makeref(rMassiveOfNames, sRndShpFrName); break;
		case SPAIN:    makeref(rMassiveOfNames, sRndShpSpName); break;
		case PIRATE:   makeref(rMassiveOfNames, sRndShpPiName); break;
		case HOLLAND:  makeref(rMassiveOfNames, sRndShpHoName); break;
		case PORTUGAL: makeref(rMassiveOfNames, sRndShpPoName); break;
		case GUEST1_NATION:
			if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
				makeref(rMassiveOfNames, sRndShpSwName);
			}
			else{
				makeref(rMassiveOfNames, sRndShpAmName); 
			}
		break;
		//case AMERICA:  makeref(rMassiveOfNames, sRndShpAmName); break;
		//case SWEDEN: makeref(rMassiveOfNames, sRndShpSwName);	break;
		// default:
                   makeref(rMassiveOfNames, sRndShpEnName); //add default case 04-12-06
	}
	/*if(SWEDEN_ALLOWED && GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
		switch(nat){
			case SWEDEN: makeref(rMassiveOfNames, sRndShpSwName);	break;
		}
	}*/
	int iMassiveOfNamesSize = GetArraySize(rMassiveOfNames);

	// LDH prevent duplicate ship names - 09Feb09
	int i;
	ref chr;
	string name;
	string allNames = "";
	for (i = 0; i < MAX_SHIPS_ON_SEA; i++) {
		if (ships[i] <= 0) continue;
		chr = GetCharacter(ships[i]);
		if (!CheckAttribute(chr, "ship.name")) continue;
		name = chr.ship.name;
		allNames += name + ",";
	}
	name = GetRandSubString(rMassiveOfNames[rand(iMassiveOfNamesSize-2)]);
	i = 1;
	while (HasSubStr(allNames, name+",") && i<10)
	{
		Trace("SetRandomNameToShip() tried to reuse name " + name + ", " + i + " attempts to assign name");
		name = GetRandSubString(rMassiveOfNames[rand(iMassiveOfNamesSize-2)]);
		i += 1;
	}
	return name;
}

// PS -->
int Force_GetShipType(int maxclass, int minclass, string type, int nat)
{
	//these are JUST IN CASE...
	if(maxclass > minclass) {int tmp = maxclass; maxclass = minclass; minclass = tmp; } // NK to swap min/max if needed 05-04-15
	// 04-09-09 NK-PRS3
	if(type == "pirate")
	{
		if(PIRATES_USE_BOTH_TYPES) { type = ""; }
		else { type = "war"; }
	}
	// NK <--
	switch(type) // add this 05-05-01 for just in case.
	{
		case "trade":
			maxclass = iclamp(MAXMERCHANTCLASS, MIN_CLASS, maxclass);
			minclass = iclamp(MAXMERCHANTCLASS, MIN_CLASS, minclass);
		break;

		case "pirate":
			maxclass = iclamp(MAXPIRATECLASS, MIN_CLASS, maxclass);
			minclass = iclamp(MAXPIRATECLASS, MIN_CLASS, minclass);
		break;
		// default, war, where max class is MAX_CLASS
			maxclass = iclamp(MAX_CLASS, MIN_CLASS, maxclass);
			minclass = iclamp(MAX_CLASS, MIN_CLASS, minclass);
	}

	// Screwface
	bool finish = false;
	int end = 0; // Security to avoid infinite loop
	while(!finish && end < 100) // maximum of 100 loop should be enough
	{
		int iShipType = Fantom_GetShipType(maxclass, minclass, type, nat);
		if(iShipType < SHIP_TYPES_QUANTITY && iShipType >= 0)
		{
			finish = true;
		}
		else
		{
			end++;
		}
	}
	if(finish)
	{
		trace("Force_GetShipType: Maxclass = "+maxclass+", Minclass = "+minclass+", Per = "+GetPeriodName(GetCurrentPeriod())+", Nat = "+GetNationNameByType(nat)+", Type = "+type+", Loop = "+end+", Ship ID = "+GetShipID(iShipType));
		return iShipType;
	}
	else
	{
		//	return GetCharacterShipType(GetMainCharacter());
		// PB: If all fails, return a random period-specific ship type instead of the player ship -->
		TraceAndLog("ERROR - Force_GetShipType: unable to find ship, returning a default ship instead");
		TraceAndLog("ERROR - Force_GetShipType: Maxclass = "+maxclass+", Minclass = "+minclass+", Per = "+GetPeriodName(GetCurrentPeriod())+", Nat = "+GetNationNameByType(nat)+", Type = "+type);
		switch((GetCurrentPeriod()))
		{
			case PERIOD_EARLY_EXPLORERS:
				switch(rand(1))
				{
					case 0: return GetShipIndex("Carrack"); break;
					case 1: return GetShipIndex("caravel1"); break;
				}
			break;

			case PERIOD_THE_SPANISH_MAIN:
				switch(rand(2))
				{
					case 0: return GetShipIndex("Caravel2"); break;
					case 1: return GetShipIndex("RN_RevengeM"); break;
					case 2: return GetShipIndex("FastGalleon1"); break;
				}
			break;

			case PERIOD_GOLDEN_AGE_OF_PIRACY:
				switch(rand(2))
				{
					case 0: return GetShipIndex("Barque4_47"); break;
					case 1: return GetShipIndex("PiratPostillionen"); break;
					case 2: return GetShipIndex("frigate1"); break;
				}
			break;

			case PERIOD_COLONIAL_POWERS:
				switch(rand(2))
				{
					case 0: return GetShipIndex("PiratHannah"); break;
					case 1: return GetShipIndex("PO_Neptunus"); break;
					case 2: return GetShipIndex("frigate2"); break;
				}
			break;

			case PERIOD_REVOLUTIONS:
				switch(rand(2))
				{
					case 0: return GetShipIndex("ketch"); break;
					case 1: return GetShipIndex("Hooker"); break;
					case 2: return GetShipIndex("Corvette47"); break;
				}
			break;

			case PERIOD_NAPOLEONIC:
				switch(rand(2))
				{
					case 0: return GetShipIndex("Schooner50"); break;
					case 1: return GetShipIndex("FastMerchantman1"); break;
					case 2: return GetShipIndex("lineship47"); break;
				}
			break;
		}
		// PB: If all fails, return a random period-specific ship type instead of the player ship <--
	}

	// old section outcommented
	/*int iShipType = Fantom_GetShipType(maxclass, minclass, type, nat);
	if(iShipType < SHIP_TYPES_QUANTITY && iShipType >= 0) { return iShipType; }
	trace("oh no, we didn't find a ship the first go!");
	iShipType = Fantom_GetShipType(maxclass, minclass, type, nat); // try again, for randomness
	if(iShipType < SHIP_TYPES_QUANTITY && iShipType >= 0) { return iShipType; }
	iShipType = Fantom_GetShipType(maxclass, minclass, type, -1); // clear nation
	if(iShipType < SHIP_TYPES_QUANTITY && iShipType >= 0) { return iShipType; }
	iShipType = Fantom_GetShipType(maxclass, minclass, "none", -1); // clear type too
	if(iShipType < SHIP_TYPES_QUANTITY && iShipType >= 0) { return iShipType; }
	iShipType = GetCharacterShipType(GetMainCharacter());
	return iShipType;*/
}

// PB: Why is this function not used outside the Standard Storyline quests_reaction.c file???
void SetUpShip(ref chr, string ftype, bool isgen)
{
	if(!CheckAttribute(chr,"ship.type")) return;
	if(chr.ship.type == SHIP_NOTUSED_TYPE_NAME) return;
	int iShipType = GetCharacterShipType(chr);
	if(iShipType == -1) return;
	if(iShipType == SHIP_NOTUSED) return;
	SetBaseShipData(&chr);
	ref Shiptype = GetShipByType(iShipType);
	// PRS3 -->
	aref arship; makearef(arship, chr.ship);
	// PRS3 <--
	if(sti(chr.nation) == PIRATE) ftype= "pirate";
	chr.FantomType = ftype;
	float mult = 1.0;
	if(isgen && DEBUG_EXPERIENCE>0) TraceAndLog("SetUpShip: Set officer type for " + GetMySimpleName(chr));
	/*switch(ftype)
	{
		case "trade":
			mult *= 1.0;
			if(isgen) chr.quest.officertype = OFFIC_TYPE_CAPMERCHANT;
			break;

		case "war":
			mult *= 1.25;
			if(isgen) chr.quest.officertype = OFFIC_TYPE_CAPNAVY;
			break;

		case "pirate":
			mult *= 1.0;
			if(isgen) chr.quest.officertype = OFFIC_TYPE_CAPPIRATE;
			break;

		case "error":
			mult *= 1.0;
			if(isgen) chr.quest.officertype = OFFIC_TYPE_CAPPIRATE;
			break;
	}*/
	//Levis moved this to already existing functions
	chr.quest.officertype = GetCaptainType(chr);
	mult *= CaptainMultFromOfficerType(chr.quest.officertype);;
	int iMCShipClass = makeint(GetCharacterShipClass(GetMainCharacter()));
	//Log_SetStringToLog("Mult 1 = " + mult);
	if(makeint(Shiptype.Class) < iMCShipClass) mult *= 1.5;
	if(makeint(Shiptype.Class) > iMCShipClass) mult *= 0.75;
	chr.Points = mult * stf(GetLocalShipAttrib(arship, Shiptype, "Weight")) / 5000; // PRS3
	//Log_SetStringToLog("NewM " + mult);
	//end hack.

	//set various stuff using AIFantom calls.
	if(isgen) LAi_Create_Officer(0, chr);
	if(isgen) Fantom_SetRandomMoney(chr, ftype);
	Fantom_SetCannons(chr, ftype);
	Fantom_SetSails(chr, ftype);
	if(isgen) Ship_SetFantomData(chr);
	Fantom_ClearCargo(chr); // TIH clear out prior slot cargo
	Fantom_SetBalls(chr, ftype);
	Fantom_SetGoods(chr, ftype);
}
// PS <--

void arSetRandomStatsToShip(aref chrship, int idx, int nat)
{
	int a;
	int cal;
	bool isint = true;
	float fStatMod = 1.0; //the base modifier. See below.
	bool NatStatMod = true;
	string atrname, atrstr; //temp attribute strings
	ref refShip = GetShipByType(idx); //this is our base
	if(nat == PIRATE && frnd() < CHANCE_OVERRIDE_PRS3NAT_IF_PIRATE) nat = rand(NATIONS_QUANTITY - 1); //override nation if pirate and chance ok
	if (CheckAttribute(refShip,"nation") == true && frnd() > CHANCE_OVERRIDE_SHIPNATION) nat = sti(refShip.nation); //if ship has nation, use that.

	DeleteAttribute(chrship, "stats"); //delete old tree
	if(CheckAttribute(refShip,"noNatStatMod")) { if(sti(refShip.noNatStatMod)) NatStatMod = false; } //i.e. do random variation but do not vary by nation
	if(CheckAttribute(refShip,"unique"))       { if(sti(refShip.unique))       return; }             // PB: Do NOT randomize stats on Unique Ships!

	chrship.stats = ""; //redeclare attribute
	chrship.stats.nation = nat;
	aref arShip; makearef(arShip, chrship.stats); //this is where we'll put stuff
	aref natstats; atrstr = "n" + nat;
	if(!CheckAttribute(shipstatsmult,"n"+nat)) atrstr = "n"; // PB: Use default values if none defined
	makearef(natstats, shipstatsmult.(atrstr)); //these are our multipliers
	// added 04-09-08 to support class-specific mults -->
	if(CheckAttribute(natstats,"class"+sti(refShip.class))) { atrname = "class"+sti(refShip.class); makearef(natstats, shipstatsmult.(atrstr).(atrname)); }

	arShip.MaxCaliber = refShip.MaxCaliber; // MM: Needed so that the calibre upgrade is correctly applied. ~Mere Mortal

	//loop through attributes in natstats
	for(a = 0; a < GetAttributesNum(natstats); a++)
	{
		fStatMod = 1.0; //reset mod
		isint = true;
		atrname = GetAttributeName(GetAttributeN(natstats,a));
		if(HasSubStr(atrname, "class")) continue; // added 04-09-08 skip attribute if it has class in it (so we can support class-specific mults)
		if(HasSubStr(atrname, "skillmult")) continue; // 04-09-10 added skip if skill mult
		if(atrname == "MaxCaliber")
		{
			if(NatStatMod)
			{
				//special manual handling for caliber
				if(stf(natstats.MaxCaliber) == 1.0) continue; //caliber doesn't get random variation
				cal = GetCannonCaliberIndex(sti(refShip.MaxCaliber));
				if(stf(natstats.MaxCaliber) > 1.0)
				{
					if(cal != -1 && cal+1 < CANNON_CALIBERS_MAX) { cal++; arShip.MaxCaliber = Cannon_Calibers[cal]; }
					if(USE_REAL_CANNONS && sti(GetAttribute(arShip, "MaxCaliber")) > sti(Cannon_Calibers[CANNON_CALIBERS_MAX-2]))
						arShip.MaxCaliber = Cannon_Calibers[CANNON_CALIBERS_MAX-2]; // PB: Limit to 32
				}
				else
				{
					if(cal != -1 && cal-1 >= 0) {cal--; arShip.MaxCaliber = Cannon_Calibers[cal]; }
				}
			}
		}
		else
		{
			if(atrname == "speedrate" || atrname == "turnrate") isint = false;
			//new local stat will be base stat * (natstat mult +/- rand(SHIPSTAT_VARIANCE))
			if(NatStatMod) fStatMod = makefloat(natstats.(atrname)); // so we can still do random variation even if not doing nation variation.
			arShip.(atrname) = makefloat(refShip.(atrname)) * (fStatMod * RandMult(SHIPSTAT_VARIANCE)); // 05-05-11 mult. If you prefer additive: - SHIPSTAT_VARIANCE + frnd()*SHIPSTAT_VARIANCE*2);
			if(isint) arShip.(atrname) = round(stf(arShip.(atrname)));
		}
	}
}

//KB Tuning ships, changed parameters - removed aref chrship and changed by int _idx
//// NK PRS3 -->
void SetRandomStatsToShip(int _idx, int idx, int nat)
{
//KB - Tuning ships - changed calling parameters
	if (_idx < 0) return;
	aref chrship;
	ref character;
	if (_idx == GetMainCharacterIndex())
		character = GetMainCharacter();
	else
		character = GetCharacter(_idx);
	makearef(chrship, character.ship);
	ref refShip = GetShipByType(idx); //this is our base

	// PB: Moved here to prevent possible missed attributes on "unique" ships
	InitTun(_idx); //KB - Tuning ships

	if (CheckAttribute(refShip, "unique")) {
		if (sti(refShip.unique)) return; //if ship is unique, do not modify stats
	}

	arSetRandomStatsToShip(chrship, idx, nat);

//KB - Tuning ships
//KB Tuning ships <--
//KB - Tuning Ships - Adding random tuned chars to ships
	//Levis check if we are filling for the shipyard:
	int time=0;
	if(!CheckAttribute(character,"ship.ForShipyard"))
	{
		//We have a random ship here
		if (rand(99) <= sti(CPDISP) ) { ApplyTun(_idx,"cplates",time) ;}
		if (rand(99) <= sti(BCDISP) ) { ApplyTun(_idx,"bcannons",time);}
		if (rand(99) <= sti(GCDISP) ) { ApplyTun(_idx,"gchasers",time);}
		if (rand(99) <= sti(NSDISP) ) { ApplyTun(_idx,"nsails",time);}
		if (rand(99) <= sti(TMDISP) ) { ApplyTun(_idx,"ltopmasts",time);}
		if (rand(99) <= sti(SSDISP) ) { ApplyTun(_idx,"stays",time);}
		if (rand(99) <= sti(RHDISP) ) { ApplyTun(_idx,"rhull",time);}
		if (nat == PIRATE || sti(character.nation) == PIRATE ) {
			if (rand(99) <= sti(FLUSHEDPROB_IFPIRATE)) ApplyTun(_idx,"flushed",time);
		} else {
			if (rand(99) <= sti(FLUSHEDPROB))  ApplyTun(_idx,"flushed",time);
		}
	}
	else
	{
		if(SHIPYARD_SHIPS_HAVE_TUNES)
		{
			//We are doing ships for the shipyard
			int maxtuns = round((8-sti(refShip.Class))/2);
			int chance = round((8-sti(refShip.Class))/2);
			int numtuns = 0;
			//First check for pirate, and if so create a large chance for flushing
			if (nat == PIRATE || sti(character.nation) == PIRATE ) {
				if(numtuns <= maxtuns) { if(rand(99) <= ((chance+2)*5)) { ApplyTun(_idx,"flushed",time) ; numtuns++;} }
			}
			//Now check the very common copper plates
			if(numtuns <= maxtuns) { if(rand(99) <= (chance)) { ApplyTun(_idx,"cplates",time) ; numtuns++;} }
			//Check some tunes special for trade
			if(CheckAttribute(refShip,"Type.Trade"))
			{
				if(numtuns <= maxtuns) { if(rand(99) <= (chance+2)) { ApplyTun(_idx,"ltopmasts",time) ; numtuns++;} }
				if(numtuns <= maxtuns) { if(rand(99) <= ((chance+2)*2)) { ApplyTun(_idx,"nsails",time) ; numtuns++;} }
			}
			//Check some special for war
			if(CheckAttribute(refShip,"Type.War"))
			{
				if(numtuns <= maxtuns) { if(rand(99) <= ((chance+2)*4)) { ApplyTun(_idx,"bcannons",time) ; numtuns++;} }
				if(numtuns <= maxtuns) { if(rand(99) <= (chance+2)) { ApplyTun(_idx,"gchasers",time) ; numtuns++;} }
				if(numtuns <= maxtuns) { if(rand(99) <= ((chance+2)*6)) { ApplyTun(_idx,"rhull",time) ; numtuns++;} }
			}
			//If still left check these
			if(numtuns <= maxtuns) { if(rand(99) <= ((chance+2)+2)) { ApplyTun(_idx,"stays",time) ; numtuns++;} }
		}
	}
}

string GetLocalShipAttrib(aref chrship, ref ship, string attrib) //pass this the chr and the shipstypes[] entry and the attribute name. Will return local version if there.
{
	//originally written to use a string; should work ok without it.
	//string tmpstr;
	//tmpstr = ship.(attrib);
	// NK special handling for cannon qty 05-04-18 -->
	if(attrib == "CurCanQty")
	{
// KK -->
		if (CheckAttribute(chrship, "Cannons.Type") == true && sti(chrship.Cannons.Type) == CANNON_TYPE_NONECANNON) return "0";
		if (CheckAttribute(chrship,"Cannons.Borts.cannonf.qty") && CheckAttribute(chrship,"Cannons.Borts.cannonb.qty") && CheckAttribute(chrship,"Cannons.Borts.cannonl.qty") && CheckAttribute(chrship,"Cannons.Borts.cannonr.qty"))
			return "" + (sti(chrship.Cannons.Borts.cannonf.qty) + sti(chrship.Cannons.Borts.cannonb.qty) + sti(chrship.Cannons.Borts.cannonl.qty) + sti(chrship.Cannons.Borts.cannonr.qty));
		else
			return GetLocalShipAttrib(&chrship, &ship, "CannonsQuantity");
		// TIH <-- empty cannons bug fix
// <-- KK
	}
	if(attrib == "MaxCanQty")
	{
		int fullqty = sti(GetLocalShipAttrib(&chrship, &ship, "Cannons.Borts.cannonf.qty"));
		fullqty += sti(GetLocalShipAttrib(&chrship, &ship, "Cannons.Borts.cannonb.qty"));
		fullqty += sti(GetLocalShipAttrib(&chrship, &ship, "Cannons.Borts.cannonl.qty"));
		fullqty += sti(GetLocalShipAttrib(&chrship, &ship, "Cannons.Borts.cannonr.qty"));
		return ""+fullqty;
	}
	// NK <--
	if(CheckAttribute(chrship,"stats."+attrib)) return chrship.stats.(attrib);
	if (CheckAttribute(ship, attrib)) return ship.(attrib); // KK
	return ""; // KK
}

bool CheckShipAttribute(aref chrship, ref ship, string attrib)
{
	if(CheckAttribute(chrship,"stats."+attrib)) return true;
	if(CheckAttribute(ship,attrib)) return true;
	return false;
}

// 04-09-10 added skill mult for nations.
float GetSkillMultByNation(string skill, int nat)
{
	if(nat == -1) return 1.0;
	if(nat > NATIONS_QUANTITY) return 1.0; // 05-04-20 check
	string atr = "n"+nat + ".skill." + skill;
	if(!Checkattribute(shipstatsmult,atr)) return 1.0;
	return stf(shipstatsmult.(atr));
	return 1.0;
}
// NK PRS3 <--

string GetShipLocationID(ref chref)
{
	if(!CheckAttribute(chref,"ship.type")) return "";
	int st = GetCharacterShipType(chref); // PS
	if(st==SHIP_NOTUSED) return "";
	if(st==SHIP_FORT)
	{
		aref ar_FindLoc = FindIslandReloadLocator(chref.location,chref.location.locator);
		if( CheckAttribute(ar_FindLoc,"go") ) return ar_FindLoc.go;
		return "";
	}
	return GetCharacterShipQDeck(chref); // KK
}

// KK -->
string GetShipDecksTexture(ref chref)
{
	if (!CheckAttribute(chref, "ship")) return "";
	int st = GetCharacterShipType(chref);
	if (st == SHIP_NOTUSED) return "";
	aref ship; makearef(ship, chref.ship);
	string path = "";
	string deck = GetLocalShipAttrib(ship, &ShipsTypes[st], "DeckTexturesDir");
	if (deck != "") {
		path = "Locations\decks\" + GetLocalShipAttrib(ship, &ShipsTypes[st], "DeckTexturesDir");
		if (CheckDirectory("RESOURCE\Textures\" + path, "*") == 0) path = "";
	}
	return path;
}
// <-- KK

//MAXIMUS -[16.09.2007]->
string GetBoardingModelName(string locID)
{
	for(int i=sti(Locations[0].IslandsList.Boarding.begin); i<sti(Locations[0].IslandsList.Boarding.end); i++)
	{
		if(CheckAttribute(Locations[i],"id") && Locations[i].id==locID)
		{
			if(CheckAttribute(Locations[i],"filespath.models") && Locations[i].filespath.models!="")
			{
				string locPath = Locations[i].filespath.models;
				return strcut(locPath, 16, strlen(locPath)-1);
			}
		}
	}
	return "udeck";
}

string GetBoardingLocationId(ref tmpChar, string locModel)
{
	string locPath = "locations\decks\"+locModel;

	for(int i=sti(Locations[0].IslandsList.Boarding.begin); i<sti(Locations[0].IslandsList.Boarding.end); i++)
	{
		if(CheckAttribute(Locations[i],"filespath.models") && Locations[i].filespath.models==locPath)
		{
			if(CheckAttribute(Locations[i],"id") && Locations[i].id!="")
			{
				if(!HasSubStr(locModel,"VS"))
				{
					if(GetShipLocationID(tmpChar)==Locations[i].id) { return Locations[i].id; }
				}
				else { return Locations[i].id; }
			}
		}
	}
	return LOCINITBRD_DEFAULTLOCATION;
}
//MAXIMUS <-[16.09.2007]-

// NK moved shipyard fill code here
void FillShipsList(ref NPChar)
{
	DeleteAttribute(NPChar, "shipyard");

	//npchar.shipyard.ship1 = SHIP_TARTANE;
	int NPCNumShips = 0;
	string attr;
	int i, iClass;
	int shipnation = -1;
	int iNation = sti(NPChar.nation);
	ref rShip;
	aref curship; // PRS3

	int iClassMin = 8; //no minimum class
	int iClassMax = 3;

	//now we can do this via townsack.
	string sTownName = "";
	if(CheckAttribute(Locations[FindLoadedLocation()],"townsack"))
	{
		sTownName = Locations[FindLoadedLocation()].townsack;
	}
	else { sTownName = GetTownIDFromGroup(Stores[GetCharacterCurrentStore(GetMainCharacter())].group); }
	// PB -->
	// You can buy class 1 ships if you've got a LoM and a high enough navy rank
	// (That way navy players can get their navy ships; ordinary privateers can't buy them)
	// Pirates only sell smaller ships
	// (makes it harder to get high class pirate design ships. You now MUST capture them)
	if(sTownName != "")
	{
		if(GetTownSize(sTownName) >= (STORE_MINSIZE/2)) iClassMax = 2;
		if(GetTownSize(sTownName) >= STORE_MINSIZE) iClassMax = 1;
	}
	if(iNation == PIRATE) iClassMax = MAXPIRATECLASS;
	// PB <--
	if(SHIPYARD_SELL_ALL_CLASSES) iClassMax = 1; // NK 05-03-19 add toggle to class limiting
	for (i=0; i<SHIP_TYPES_QUANTITY; i++)
	{
		shipnation = -1;
		rShip = GetShipByType(i);
		iClass = MakeInt(rShip.Class);
		if (CheckAttribute(NPChar,"id") && NPChar.id == "Hendrick Vanderdecken") // PB: Enable the buying of unavailable quest ships
		{
			bool VanderdeckenShip = false;
			if(sti(rShip.CanBuy) == false && sti(rShip.CanEncounter) == false)	VanderdeckenShip = true;
			if(HasSubStr(rShip.id, "Steam"))									VanderdeckenShip = true;
			if(HasSubStr(rShip.id, "obj_"))										VanderdeckenShip = false;
			if(!VanderdeckenShip) 												continue;
		}
		else
		{
			if (iClass > iClassMin) { continue; }
			if (iClass < iClassMax) { continue; }
			if(sti(rShip.CanBuy) != true) { continue; }
			// KK: Periods -->
			if (iNation >= 0 && iNation < NATIONS_QUANTITY) {
				string sNation = GetNationIDByType(iNation);
				if (NATIONAL_PAINT_SCHEMES) // Replace with another setting if desired
				{
					if (CheckAttribute(rShip, sNation) == true && stf(rShip.(sNation)) < FRAND(1.0)) continue;
				}else{
					if (sti(GetAttribute(rShip, "nation")) != iNation) continue;
				}
			}
			string sPeriod = GetCurrentPeriod();
			if (CheckAttribute(rShip, "period."+sPeriod) && stf(rShip.period.(sPeriod)) < FRAND(1.0)) continue;
			// KK: Periods <--
			if(CheckAttribute(rShip,"Nation")) shipnation = sti(rShip.Nation);
			if(Rand(makeint(retmax(0,SHIPYARD_CHANCE_CLASS-1-iClass)))) continue; // NK 05-03-31 change this from 7 to define.
		}
		shipnation = iNation;
		if(frnd() < SHIPYARD_CHANCE_OTHERNATION)
		{
			// loop until find available other nation. Note, to avoid infinite loop checking capped at 50.
			shipnation = rand(NATIONS_QUANTITY - 1);
			string tmp = "skipnat"+shipnation;
			for(int n = 0; n < 50; n++)
			{
				if(!CheckAttribute(rShip,tmp)) break;
				if(sti(rShip.(tmp)) == 0) break;
				shipnation = rand(NATIONS_QUANTITY - 1);
				tmp = "skipnat"+shipnation;
			}
		}
		NPCNumShips++;
		attr = "ship"+NPCNumShips;
		NPChar.shipyard.(attr) = i;
		// PRS3 -->
		makearef(curship, NPChar.shipyard.(attr));
		// PB: To prevent randomization of stats on "unique" ships in shipyards -->
		if (!CheckAttribute(rShip, "unique")) //if ship is not unique, do modify stats
			//Levis let's use the same function to get random stats as everywhere else.
			NPChar.ship = "";
			aref toShip; makearef(toShip, NPChar.ship);
			aref fromShip; makearef(fromShip, curship);
			CopyAttributes(toShip, fromShip);
			NPChar.ship.type = rShip.type;
			NPChar.ship.idx = i;
			NPChar.ship.ForShipyard = 1;
			int _idx = GetCharacterIndex(NPChar.id);
			SetRandomStatsToShip(_idx, i, shipnation);
			CopyAttributes(fromShip, toShip);
			DeleteAttribute(NPChar,"ship");
			//arSetRandomStatsToShip(curship, i, shipnation);
		else
			curship.stats.nation = shipnation; //otherwise, at least prevent missed attributes
		// PB: To prevent randomization of stats on "unique" ships in shipyards <--
		// PRS3 <--
	}

	// TIH --> rpg_style Auto-sort ships by class and price Jul27'06
	// yes this is an ugly mess... but the engine was giving me beef... so this is how it ended up
	// this DOES work, works real good... just ugly :)
	// by all means if you see a cleaner way to do it, then PLEASE do it... no one else has!
	if ( SY_RPG_STYLE )
	{
		aref 	syShipList;
		makearef(syShipList, NPChar.shipyard);
		int 	st;
		int 	j,x,y;
		int 	numShips = GetAttributesNum(syShipList);
		int 	SortClass[600];
		int 	SortPrice[600];
		int 	holder, idxholder;
		aref 	tmparef, tmpShip;
		aref 	tmparefC, tmparefN;
		aref 	swapShipT, swapShipN, swapShipC;
		string 	slotN, slotC;

		syShipList.swaptmp = true;
		makearef(swapShipT, syShipList.swaptmp);

		// god I wish I had a real database engine ...
		for(j = 0; j < numShips; j++)
		{
			tmparef = GetAttributeN(syShipList,j); makearef(tmpShip, tmparef);
			st 		= sti(GetAttributeValue(tmparef));
			SortClass[j] = GetLocalShipAttrib(tmpShip, ShipsTypes[st],"Class");
			SortPrice[j] = GetLocalShipAttrib(tmpShip, ShipsTypes[st],"Price");
		}

		//trace("----------------------------------------------");
		//trace("---> before sort:");
		//DumpAttributes(syShipList);
		//trace("----------------------------------------------");

		// sort by class of ship
		for(x = 0; x < numShips; x++)
		{
			for(y = 0; y < numShips-1; y++)
			{
				if(SortClass[y] < SortClass[y+1])
				{
					tmparefC = GetAttributeN(syShipList,y);
					tmparefN = GetAttributeN(syShipList,(y+1));
					slotC 	= GetAttributeName(tmparefC);
					slotN 	= GetAttributeName(tmparefN);

					makearef(swapShipC,syShipList.(slotC));
					makearef(swapShipN,syShipList.(slotN));

					//trace("-> swapShipC  Class: "+SortClass[y]+"  Slot: "+slotC+"");
					//trace("-> swapShipN  Class: "+SortClass[y+1]+"  Slot: "+slotN+"");

					CopyAttributes(swapShipT,swapShipN);
					CopyAttributes(swapShipN,swapShipC);
					CopyAttributes(swapShipC,swapShipT);

					idxholder			= sti(GetAttributeValue(tmparefN));
					syShipList.(slotN) 	= sti(GetAttributeValue(tmparefC));
					syShipList.(slotC) 	= idxholder;

					holder 			= SortClass[y+1];
					SortClass[y+1] 	= SortClass[y];
					SortClass[y] 	= holder;
					holder 			= SortPrice[y+1];
					SortPrice[y+1] 	= SortPrice[y];
					SortPrice[y] 	= holder;
				}
			}
		}
		//trace("----------------------------------------------");
		//trace("---> after sort class:");
		//DumpAttributes(syShipList);
		//trace("----------------------------------------------");

		// do it all over again, but for price per class
		for(x = 0; x < numShips; x++)
		{
			for(y = 0; y < numShips-1; y++)
			{
				if(SortPrice[y] > SortPrice[y+1] && SortClass[y] == SortClass[y+1])
				{
					tmparefC = GetAttributeN(syShipList,y);
					tmparefN = GetAttributeN(syShipList,(y+1));
					slotC 	= GetAttributeName(tmparefC);
					slotN 	= GetAttributeName(tmparefN);

					makearef(swapShipC,syShipList.(slotC));
					makearef(swapShipN,syShipList.(slotN));

					//trace("-> swapShipC  Class: "+SortClass[y]+"  Slot: "+slotC+"");
					//trace("-> swapShipN  Class: "+SortClass[y+1]+"  Slot: "+slotN+"");

					CopyAttributes(swapShipT,swapShipN);
					CopyAttributes(swapShipN,swapShipC);
					CopyAttributes(swapShipC,swapShipT);

					idxholder			= sti(GetAttributeValue(tmparefN));
					syShipList.(slotN) 	= sti(GetAttributeValue(tmparefC));
					syShipList.(slotC) 	= idxholder;

					holder 			= SortClass[y+1];
					SortClass[y+1] 	= SortClass[y];
					SortClass[y] 	= holder;
					holder 			= SortPrice[y+1];
					SortPrice[y+1] 	= SortPrice[y];
					SortPrice[y] 	= holder;
				}
			}
		}
		//trace("----------------------------------------------");
		//trace("---> after sort class & price:");
		//DumpAttributes(syShipList);
		//trace("----------------------------------------------");
		DeleteAttribute(syShipList,"swaptmp");
	}
	// TIH <--

}
// NK <--

// KK -->
void ModifyShip(ref refShip)
{
	int idx;
	ref refCurShip;
	if (!CheckAttribute(refShip, "id")) return;
	idx = GetShipIndex(refShip.id);
	if (idx == -1) return;
	makeref(refCurShip, ShipsTypes[idx]);
	DeleteAttribute(refCurShip, "");
	CopyAttributes(refCurShip, refShip);
	DeleteAttribute(refShip, "");
}

void CrimsonBlood_ModifyShip()
{
	object otmp;
	ref refShip;
	aref arship, cannonl, cannonr, cannonb, cannonf;
	int i;

	makeref(refShip, otmp);

	//-------------------------------------------------------------------------
	//  Cursed Crimson Blood - Stock corvette upgraded by Armada and Hylie Pistof
	//  Original skin by Petros; modified by Armada
	//     <SWS - Willemstad Builders' Trials Winter 09 S/N 133> (WBT1L) - Light Frigate
	//-------------------------------------------------------------------------
	refShip.Name			= "CrimsonBlood";
	refShip.Nation			= PIRATE;
	refShip.id				= SHIP_CURSED;
	refShip.All				= "Corvette1";
	refShip.walk			= "Aurora"; // PB: To overwrite the original SHIP_CURSED walk file
	refShip.sname      		= "CursedBlood";
	refShip.unique			= true;
	refShip.Class		   = 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.Cannons.Borts.cannonl.qty = 13;
	refShip.Cannons.Borts.cannonr.qty = 13;
	// NK <--
	refShip.MaxCrew		 = 300;
	refShip.MinCrew		 = 60;
	refShip.Price		   = 200000;
	refShip.HP			  = 100000; // stronger
	refShip.SP			  = 999999;
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_torn_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_torn_red_plain.tga";
// <-- Petros
	refShip.fog_trail = true; // PB: Cursed Ship Trails Fog

	refShip.BigPic			= refShip.id;
	refShip.BigPicTex		= 4;
	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 10;
	refShip.BI.Pic = 3;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.CanEncounter	= false;
	refShip.CanBuy = false;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.6;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.6;
		refShip.TurnRate		= 36.5;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 12;		refShip.InertiaBrakingY = 8;
		refShip.InertiaAccelerationZ = 6.0;		refShip.InertiaBrakingZ = 4.0;

	}

// Review: Vessel configured as: Supernatural Light Frigate
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 133> is henceforth complete
// on this day and date Jan 2 10, 1749h

// GR: fill in cannon data normally provided by "Ships_init.c" -->
	refShip.FireHeight = 3.0;
 	refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;

	makearef(cannonl,refShip.Cannons.Borts.cannonl);
	makearef(cannonr,refShip.Cannons.Borts.cannonr);
	makearef(cannonf,refShip.Cannons.Borts.cannonf);
	makearef(cannonb,refShip.Cannons.Borts.cannonb);
	if(USE_REAL_CANNONS)
	{
		refShip.Height.Grapes.Y   = 5.0;    refShip.Height.Grapes.DY  = 1.0;
		cannonf.FireZone  = Degree2Radian(20.0) * FIRE_ANGLE_SCALAR_W;
		cannonf.FireDir   = Degree2Radian(0.0);
		cannonf.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		cannonf.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

		cannonr.FireZone  = Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
		cannonr.FireDir   = Degree2Radian(90.0);
		cannonr.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		cannonr.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

		cannonb.FireZone  = Degree2Radian(20.0) * FIRE_ANGLE_SCALAR_W;
		cannonb.FireDir   = Degree2Radian(180.0);
		cannonb.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		cannonb.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

		cannonl.FireZone  = Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
		cannonl.FireDir   = Degree2Radian(270.0);
		cannonl.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		cannonl.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;
	}
	else
	{
		refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.MaxCaliber = 24;
		refShip.Cannon = CANNON_TYPE_CANNON_LBS24;
		cannonf.FireZone	= Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
		cannonf.FireDir		= Degree2Radian(0.0);
		cannonf.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		cannonf.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

		cannonr.FireZone	= Degree2Radian(80.0) * FIRE_ANGLE_SCALAR_W;
		cannonr.FireDir		= Degree2Radian(90.0);
		cannonr.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		cannonr.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

		cannonb.FireZone	= Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
		cannonb.FireDir		= Degree2Radian(180.0);
		cannonb.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		cannonb.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

		cannonl.FireZone	= Degree2Radian(80.0) * FIRE_ANGLE_SCALAR_W;
		cannonl.FireDir		= Degree2Radian(270.0);
		cannonl.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		cannonl.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
	}
// <-- GR: End of extra cannon data
// GR: correct performance data -->
	refShip.TurnDependWeight = 0.5;
	if(USE_REAL_SAILING) refShip.TurnDependSpeed = 0.95;
	else refShip.TurnDependSpeed = 0.6;
	refShip.InertiaAccelerationY = stf(refShip.InertiaAccelerationY) / 6.0;
	refShip.InertiaAccelerationZ = stf(refShip.InertiaAccelerationZ) / 4.0;
	refShip.InertiaBrakingZ = stf(refShip.InertiaBrakingZ) / 10.0;
// <-- GR: End of performance data

	ModifyShip(refShip);

	// PB: For dialogs, queststexts and ship names -->
	Preprocessor_Delete("cursed_ship");
	Preprocessor_Delete("uncursed_ship");
	Preprocessor_Save("cursed_ship", "Crimson Blood");
	Preprocessor_Save("uncursed_ship", "Black Pearl");
	// PB: For dialogs, queststexts and ship names <--
}

bool IsShipMerchant(ref chr)
{
	int iNation = sti(chr.nation);
	ref rShip = GetShipByType(GetCharacterShipType(chr));
	aref arShip; makearef(arShip, chr.Ship);
	if (CheckShipAttribute(arShip, rShip, "Flags.UseMerchantFlag") == true && sti(GetLocalShipAttrib(arShip, rShip, "Flags.UseMerchantFlag")) == true)	return true;
	if (CheckShipAttribute(arShip, rShip, "Flags.UseNavalFlag"   ) == true && sti(GetLocalShipAttrib(arShip, rShip, "Flags.UseNavalFlag"   )) == true)	return false;
	if (CheckAttribute(chr, "Flags.UseMerchantFlag") == true)																							return true;
	if (CheckAttribute(chr, "Flags.UseNavalFlag") == true)																								return false;
	if (IsMainCharacter(chr) || IsCompanion(chr))
	{
		// PB: Fly navy flag only if you're officially in the service of that nation -->
		if(iNation >= 0 && iNation < NATIONS_QUANTITY)
			return !IsInServiceOf(iNation);
		// PB: Fly navy flag only if you're officially in the service of that nation <--
	}
	else
	{
		// PB: Use fantom type instead of ship type if available -->
		if(CheckAttribute(chr,"FantomType"))
		{
			switch(chr.FantomType)
			{
				case "trade":
					return true;
				break;

				case "war":
					return false;
				break;
			}
		}
		// PB: Use fantom type instead of ship type if available <--
	}
	return sti(GetLocalShipAttrib(arShip, rShip, "Type.Trade")) == true && sti(GetLocalShipAttrib(arShip, rShip, "Type.War")) == false;
}

string GetMyShipName(ref refCharacter)
{
	int iNation = sti(refCharacter.nation);
	bool bUse = false;
	string shipname;
	ref rNation;
	if (!CheckAttribute(refCharacter, "Ship.Name")) return SHIP_NAME_NOTUSED;
	shipname = refCharacter.Ship.Name;
	if (shipname == "") return "";
	if (IsShipMerchant(refCharacter) == false && iNation >= 0 && iNation < NATIONS_QUANTITY) {
		makeref(rNation, Nations[iNation]);
		if (CheckAttribute(rNation, "ShipNamePrefix") && GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) shipname = rNation.ShipNamePrefix + " " + shipname; // PB
	}
	return shipname;
}

string GetMyShipNameShow(ref refCharacter)
{
	int iNation = sti(refCharacter.nation);
	string shipname;
	ref rNation;
	if (!CheckAttribute(refCharacter, "Ship.Name")) return SHIP_NAME_NOTUSED;
	shipname = "'" + refCharacter.Ship.Name + "'";
	if (shipname == "''") return "";
	if (IsShipMerchant(refCharacter) == false && GetAttribute(refCharacter, "ship.type") != SHIP_FORT_NAME && iNation >= 0 && iNation < NATIONS_QUANTITY) { // PB: Don't do this for forts
		makeref(rNation, Nations[iNation]);
		if (CheckAttribute(rNation, "ShipNamePrefix") && GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) shipname = rNation.ShipNamePrefix + " " + shipname; // PB
	}
	return shipname;
}
// <-- KK
