#include "TownFantoms\TownFantoms.c" // Town Fantoms
// RM -->
// all town defines in buildsettings.h

#define DEBUGTOWNTABLE 0

#define RANDOM_TOWN_EVENT_PROBABILITY   400
#define RANDOM_TOWN_EVENT_MALARIA       0       // Town Economy -1
#define RANDOM_TOWN_EVENT_PIRATES       1       // Town Economy -1
#define RANDOM_TOWN_EVENT_GOLDFOUND     2       // Town Economy +2
#define RANDOM_TOWN_EVENT_SILVERFOUND   3       // Town Economy +1
#define RANDOM_TOWN_EVENT_INDIANS       4       // Town Economy -2
#define RANDOM_TOWN_EVENT_SLAVEREVOLT   5       // Town Economy -1
#define RANDOM_TOWN_EVENT_FIRE          6       // Town Economy -1
#define RANDOM_TOWN_EVENT_HURRICANE     7       // Town Economy -1
#define RANDOM_TOWN_EVENT_SETTLERS      8       // Town Economy +1
#define RANDOM_TOWN_EVENT_EXPEDITION    9       // Town Economy +2
#define RANDOM_TOWN_EVENT_GOODECO       10      // Town Economy +1
#define RANDOM_TOWN_EVENTS_QTY          11

#define TOWN_ECONOMY_STARVING     -2
#define TOWN_ECONOMY_STRUGGLING   -1
#define TOWN_ECONOMY_SURVIVING    0
#define TOWN_ECONOMY_PROSPERING   1
#define TOWN_ECONOMY_WEALTHY      2

// NK 05-04-23 switch to towns[] 
#define MAX_TOWNS 65
object Towns[MAX_TOWNS];
int TOWNS_QUANTITY = 0;

// KK -->
#define TAX_NONE    0
#define TAX_LOW     1
#define TAX_NORMAL  2
#define TAX_HIGH    3
#define TAX_PLUNDER 4

extern void InitTowns(bool first);
// <-- KK

ref GetTownFromID(string sTownName)
{
	if(sTownName == "") return &NullCharacter; // just in case.

	int idx = GetTownIndex(sTownName);
	if(idx < 0 || idx >= TOWNS_QUANTITY) return &NullCharacter; // read only! But it's empty, so what. :)
	return &Towns[idx];
	/*ref ctown;
	string temp;
	if(sTownName == "Conceiçao") sTownName = "Conceicao";  // <-- fix by emrep for Trade Mission error
	for(int i = 0; i < TOWNS_QUANTITY; i++)
	{
		temp = "t" + i;
		makearef(ctown, objTownStateTable.towns.(temp));
		if(ctown.id == sTownName) break;
	}
	return ctown; // trying it out without the &*/
}
// WM -->
// 04-09-22
//get town of nation
string GetTownIDFromNation(int nat)
{
	string ptowns[100];
	int qty = 0;
	string temp;
	ref ctown;
	// NK 05-04-23 switch to towns[]
	for(int i = 0; i < TOWNS_QUANTITY; i++)
	{
		makeref(ctown, Towns[i]);
		if(sti(ctown.nation) == nat)
		{
			ptowns[qty] = ctown.id;
			qty++;
		}
	}
	if(qty == 0) return "";
	return ptowns[rand(qty-1)];
}
// WM <--

int GetTownIndex(string sTownName)
{
	if(sTownName == "Conceiçao") sTownName = "Conceicao";
	if (sTownName == "Antigua") sTownName = "St John's"; // KK
	// NK 05-04-23 switch to towns[]
	return NativeFindCharacter(&Towns, sTownName);
}

ref GetTownByIndex(int idx)
{
	// NK 05-04-23 switch to towns[]
	if(idx < 0 || idx >= TOWNS_QUANTITY) return &NullCharacter;
	return &Towns[idx];
	/*ref ctown;
	string temp = "t" + idx;
	if(CheckAttribute(objTownStateTable,"towns."+temp)) makearef(ctown, objTownStateTable.towns.(temp));
	return ctown;*/
}

// KK -->
void SetTownName(string townid, string townname)
{
	if (!TownExist(townid)) return;
	ref rtown = GetTownFromID(townid);
	rtown.name = townname;
}

string FindTownName(string townid)
{
	if (!TownExist(townid)) return "";
	ref rtown = GetTownFromID(townid);
	if (CheckAttribute(rtown, "name"))
	{
		// PB: For Renamed Personal Towns -->
		if(GetTownNation(townid) == PERSONAL_NATION)
			return rtown.name;
		else
			return XI_ConvertString(rtown.name);
		// PB: For Renamed Personal Towns <--
	}
	return "";
}
// <-- KK

// 04-11-08 added this. Checks if town stownname exists.
bool TownExist(string sTownName)
{
	int idx = GetTownIndex(sTownName);
	return idx >= 0 && idx < TOWNS_QUANTITY;
}

//town-island interoperability
int GetIslandTownsQuantity(string islandid)
{
	if(islandid == "") return 0;
	ref island = GetIslandByID(islandid);
	if(CheckAttribute(island,"towns.quantity")) return sti(island.towns.quantity);
	return 0;
}

string GetTownIDFromIsland(string islandid, int townnum)
{
	string tn = townnum;
	if(islandid == "") return "";
	if(townnum == 0) return "";
	if(GetIslandTownsQuantity(islandid) < townnum) return "";
	ref island = GetIslandByID(islandid);
	If(!Checkattribute(island,"towns."+(tn))) return ""; // Screwface : avoid isla mona error with have a quantity of 10 towns !!!!!!!!
	return island.towns.(tn);
}


ref GetTownfromIsland(string islandid, int townnum)
{
	return GetTownFromID(GetTownIDFromIsland(islandid, townnum));
}

string GetIslandIDFromTown(string sTownName)
{
	if(sTownName == "") return "";
	ref ctown = GetTownFromID(sTownName);
	return ctown.island;
}

ref GetIslandFromTown(string sTownName)
{
	return GetIslandByID(GetIslandIDFromTown(sTownName));
}

//town-store interoperability
string GetTownIDFromGroup(string group)
{
	return group; // NK I have rewritten store group to just be town name. Yay, speed. 05-07-10
	// NK new 05-04-15 use lookup.
	// NK 05-04-23 because obj doesn't exist any more (switched to Towns[]) we use shiplookuptable.
	/*if(CheckAttribute(ShipLookupTable,"townlookup.names"))
	{
		if(CheckAttribute(ShipLookupTable,"townlookup.names."+group)) return ShipLookupTable.townlookup.names.(group);
		trace("town storegroup " + group + " not exist!");
	}
	return "";*/
	// <--
	/*ref ctown;
	string temp;
	string ret = "";
	if(!CheckAttribute(objTownStateTable,"towns.Quantity")) return ret;
	for(int i = 0; i < TOWNS_QUANTITY; i++)
	{
		temp = "t" + i;
		makearef(ctown, objTownStateTable.towns.(temp));
		if(ctown.id == group) {ret = ctown.id; break;}
		if(CheckAttribute(ctown, "storegroup"))
		{
			if(ctown.storegroup == group) {ret = ctown.id; break;}
		}
	}
	return ret;*/
}

ref GetTownFromGroup(string group)
{
	// NK 05-04-23 switch to towns[]
	return GetTownFromID(GetTownIDFromGroup(group));
	/*ref ctown;
	string temp;
	for(int i = 0; i < TOWNS_QUANTITY; i++)
	{
		temp = "t" + i;
		makearef(ctown, objTownStateTable.towns.(temp));
		if(ctown.id == group) break;
		if(CheckAttribute(ctown, "storegroup"))
		{
			if(ctown.storegroup == group) break;
		}
	}
	return &ctown;*/
}

string GetCurrentTownID() // added 04-09-08
{
	if(FindLoadedLocation() != -1)
	{
		if(CheckAttribute(Locations[FindLoadedLocation()],"townsack")) { return Locations[FindLoadedLocation()].townsack; }
		else { return ""; }
	}
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "location")) return ""; // KK
	int idx = FindLocation(pchar.location);
	if(idx != -1)
	{
		ref loc = &Locations[idx];
		if(CheckAttribute(loc,"townsack")) return loc.townsack;
	}
	return "";
}

string GetTownIDFromLocID(string id) // added 05-03-28
{
	if(id == "" || FindLocation(id)==-1) return "";
	if(CheckAttribute(Locations[FindLocation(id)],"townsack")) return Locations[FindLocation(id)].townsack;
	return "";
}


ref GetCurrentTown() // added 04-09-08
{
	return GetTownFromID(GetCurrentTownID());
}

int GetCurrentStore(string locID) // added by MAXIMUS 02.11.2007
{
	return GetTownStoreIndex(GetTownIDFromLocID(locID));
}

int GetTownStoreIndex(string sTownName)
{
	// NK 05-04-23 switch to towns[]
	if(!TownExist(sTownName)) return -1; // KK
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"store")) return sti(ctown.store);
	return -1;
}
ref GetTownStore(string sTownName)
{
// KK -->
	int store_idx = GetTownStoreIndex(sTownName);
	if (store_idx < 0 || store_idx > STORE_QUANTITY) return &NullCharacter;
	return &Stores[store_idx];
// <-- KK
}


//access town properties

//for CCC's Vice City
float GetTownMonsterProb(string sTownName)
{
	// NK 05-04-23 switch to towns[]
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"monsterprob")) return stf(ctown.monsterprob);
	return DEFAULT_TOWN_MONSTERPROB;
}

float SetTownMonsterProb(string sTownName, float bprob)
{
	// NK 05-04-23 switch to towns[]
	ref ctown = GetTownFromID(sTownName);
	float oldprob = -1;
	if(CheckAttribute(ctown,"monsterprob")) oldprob = stf(ctown.monsterprob);
	ctown.monsterprob = bprob;
	return oldprob;
}

//added 04-11-08
bool IsTownCaptured(string sTownName)
{
	int idx = GetTownIndex(sTownName);
	if(idx == -1) { trace("WARNING!!! Town name " + sTownName + " not found"); return false;}
	// NK 05-04-23 switch to towns[]
	ref ctown = GetTownByIndex(idx);
	if(checkAttribute(ctown,"captured")) return sti(ctown.captured);
	return false;
}

int GetTownSize(string sTownName)
{
	// NK 05-04-23 switch to towns[]
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"size")) return sti(ctown.size);
	return DEFAULT_TOWN_POP;
}

void SetTownSize(string sTownName, int size)
{
	if(sTownName == "") return;
	ref ctown = GetTownFromID(sTownName);
	if(size < 0) size = DEFAULT_TOWN_POP;
	ctown.size = size;
}

int GetTownGold(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"gold")) return sti(ctown.gold);
	return DEFAULT_TOWN_POP * TOWN_GOLD_SCALAR;
}

void SetTownGold(string sTownName, int tgold)
{
	if(sTownName == "") return;
	ref ctown = GetTownFromID(sTownName);
	ctown.gold = tgold;
}
// distance handling 05-05-12
float GetTownDistance2DbyID(string Town1, string Town2)
{
	ref t1 = GetTownFromID(Town1);
	ref t2 = GetTownFromID(Town2);
	return GetTownDistance2D(&t1, &t2);
}

float GetTownDistance2D(ref tn1, ref tn2)
{
	float x1, x2, z1, z2;
	x1 = stf(tn1.position.x);
	z1 = stf(tn1.position.z);
	x2 = stf(tn2.position.x);
	z2 = stf(tn2.position.z);
	return GetDistance2D(x1, z1, x2, z2);
}

// 05-05-12
void GetTownPosition(ref tn, ref x, ref z)
{
	x = stf(tn.position.x);
	z = stf(tn.position.z);
}

void GetTownPositionByID(string town, ref x, ref z)
{
	float x1, z1;
	GetTownPosition(GetTownFromID(town), &x1, &z1);
	x = x1; z = z1;
}

int GetTownNation(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"nation")) return sti(ctown.nation);
	return PIRATE;
}

void SetTownNation(string sTownName, int iNation)
{
	ref ctown = GetTownFromID(sTownName);
	ctown.nation = iNation;
}

// KK -->
int GetTownHomeland(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown, "homeland")) return sti(ctown.homeland);
	return GetTownNation(sTownName);
}
// <-- KK

int GetTownGovernorIndex(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	int gov = -1;
	if(CheckAttribute(ctown,"gov")) gov = GetCharacterIndex(ctown.gov); // KK
	return gov;
}

string GetTownGovernorID(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	string gov = "";
	if(CheckAttribute(ctown,"gov")) gov = ctown.gov;
	return gov;
}


ref GetTownGovernor(string sTownName)
{
	/*ref ctown = GetTownFromID(sTownName);
	ref gov;
	if(CheckAttribute(ctown,"gov")) gov = CharacterFromID(ctown.gov);
	return &gov;*/
	return GetCharacter(GetTownGovernorIndex(sTownName));
}

int GetTownNumForts(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"forts.Quantity")) return sti(ctown.forts.Quantity);
	return 0;
}

// KK -->
ref GetTownFortCommander(string sTownName, int fcom)
{
	int fcmdridx = GetTownFortCommanderIndex(sTownName, fcom);
	if (fcmdridx < 0) return &NullCharacter;
	return GetCharacter(fcmdridx);
	/*ref ctown = GetTownFromID(sTownName);
	int fortsq = GetTownNumForts(sTownName);
	string curfort = fcom;
	if(fortsq)
	{
		if(CheckAttribute(ctown,"forts."+curfort+".fortchar")) fcmdr = CharacterFromID(ctown.forts.(curfort).fortchar);
	}
	return &fcmdr;*/
}

string GetTownFortCommanderID(string sTownName, int fcom)
{
	int fortsq;
	string curfort = fcom;
	ref ctown;
	if (!TownExist(sTownName)) return "";
	ctown = GetTownFromID(sTownName);
	fortsq = GetTownNumForts(sTownName);
	if (fortsq > 0 && CheckAttribute(ctown, "forts." + curfort + ".fortchar")) return ctown.forts.(curfort).fortchar;
	return "";
}

int GetTownFortCommanderIndex(string sTownName, int fcom)
{
	string fcomid = GetTownFortCommanderID(sTownName, fcom);
	return GetCharacterIndex(fcomid);
}

int CalculateTownFortCrewQuantity(ref fchar)
{
	if (CheckAttribute(fchar, "Ship.Type") == false || fchar.Ship.Type != SHIP_FORT_NAME) return 0;
	return makeint((stf(fchar.Fort.Cannons.Type.1.Quantity) * stf(Cannon[sti(fchar.Fort.Cannons.Type.1)].caliber) + stf(fchar.Fort.Cannons.Type.2.Quantity) * stf(Cannon[sti(fchar.Fort.Cannons.Type.2)].caliber)) * 0.5);
}
// <-- KK

int GetTownNumTroops(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"troops")) return sti(ctown.troops);
	return makeint(makefloat(DEFAULT_TOWN_POP) * TOWN_TROOPS_SCALAR);
}

void TownDistributeTroops(string sTownName)
{
	int i, troops, curtroops, numforts, tmp;
	ref fchar;
	if (!TownExist(sTownName)) return; // KK
	numforts = GetTownNumForts(sTownName);
	if (numforts <= 0) return;
	
	for(i = 0; i < numforts; i++)
	{
		fchar = GetTownFortCommander(sTownName, i);
		troops = CalculateTownFortCrewQuantity(fchar);
		fchar.ship.crew.quantity = troops;
	}
}

void SetTownNumTroops(string sTownName, int ntroops)
{
	if(sTownName == "") return;
	ref ctown = GetTownFromID(sTownName);
	ctown.troops = ntroops;
	TownDistributeTroops(sTownName);
}

int GetTownCrewQuantity(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"crew.quantity")) return sti(ctown.crew.quantity);
	return 0;
}

void SetTownCrewQuantity(string sTownName, int qty) // add 04-09-08
{
	ref ctown = GetTownFromID(sTownName);
	ctown.crew.quantity = qty;
}


int GetTownCrewMorale(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	if(CheckAttribute(ctown,"crew.morale")) return sti(ctown.crew.morale);
	return MORALE_NORMAL;
}

void SetTownCrewMorale(string sTownName, int morale) // add 04-09-08
{
	ref ctown = GetTownFromID(sTownName);
	ctown.crew.morale = morale;
}

// LocAI group functions - PB Update: 6 Feb 2016

// nation
string GetNationAIGroup(int iNation, string groupName)
{
	if (iNation == PERSONAL_NATION) 				groupName = LAI_GROUP_PLAYER;
	else
	{
		if (iNation > PERSONAL_NATION && iNation < NATIONS_QUANTITY)
		{
			ref rNation = GetNationByType(iNation);
			if (groupName != "")						groupName = "_" + groupName;		// PB: For town capture, you may want to get ONLY the group without anything appended
			if (CheckAttribute(rNation, "laigroup"))
			{
				groupName = rNation.laigroup + groupName;
				groupName = strreplace(groupName, "__", "_");								// PB: For backwards compatibility
				//TraceAndLog("GetNationAIGroup returns " + groupName + " from nation AI group for " + GetNationIDByType(iNation));
				return groupName;
			}
		}
		if (HasSubStr(groupName, "SOLDIERS"))			groupName = LAI_GROUP_GUARDS;		// PB: HasSubStr should be the safest way to distinguish between the two
		else											groupName = LAI_DEFAULT_GROUP;
	}
	groupName = strreplace(groupName, "__", "_");											// PB: For backwards compatibility
	//TraceAndLog("GetNationAIGroup returns " + groupName + " for " + GetNationIDByType(iNation));
	return groupName;
}

// town
string GetTownAIGroup(string sTownName, string groupName)
{
	return GetTownAIGroup_R(GetTownFromID(sTownName), groupName);
}

string GetTownAIGroup_R(ref ctown, string groupName)
{
	if (CheckAttribute(ctown, "laigroup"))
	{
		if (ctown.laigroup == LAI_GROUP_PLAYER)	groupName = LAI_GROUP_PLAYER;
		else									groupName = ctown.laigroup + "_" + groupName;
	}
	else
	{
		int iNation = UNKNOWN_NATION;
		if (CheckAttribute(ctown, "nation")) iNation = sti(ctown.nation);
		groupName = GetNationAIGroup(iNation, groupName);
	}
	groupName = strreplace(groupName, "__", "_");											// PB: For backwards compatibility
/*	if (CheckAttribute(ctown, "id"))
	{
		TraceAndLog("GetTownAIGroup_R returns " + groupName + " for ctown = " + ctown.id);
	}
	else
	{
		TraceAndLog("GetTownAIGroup_R returns " + groupName + " for ctown:");
		DumpAttributes(ctown);
	}*/
	return groupName;
}

// soldiers
string GetTownSoldierGroup_R(ref ctown)
{
	return GetTownAIGroup_R(ctown, "SOLDIERS");
}

string GetTownSoldierGroup(string sTownName)
{
	return GetTownSoldierGroup_R(GetTownFromID(sTownName));
}

string GetCurrentSoldierGroup()
{
	return GetTownSoldierGroup_R(GetCurrentTown());
}

string GetSoldiersGroup(int iNation)
{
	return GetNationAIGroup(iNation, "SOLDIERS");
}

// citizens
string GetTownCitizenGroup_R(ref ctown)
{
	return GetTownAIGroup_R(ctown, "CITIZENS");
}

string GetTownCitizenGroup(string sTownName)
{
	return GetTownCitizenGroup_R(GetTownFromID(sTownName));
}

string GetCurrentCitizenGroup()
{
	return GetTownCitizenGroup_R(GetCurrentTown());
}

string GetCitizensGroup(int iNation)
{
	return GetNationAIGroup(iNation, "CITIZENS");
}



// NK WM/itemtrade 05-04-02 add ship in port check, right now just pchar
// LDH this is not used anywhere, it's been commented out in items_utilitie.c - 29Mar09
// fleetsinport will be checked directly where it's used in TownUpdate()
/*bool IsFleetInTown(string townn, string fleetid)
{
	if(townn == "") return false;
	ref ctown = GetTownFromID(townn);
	return CheckAttribute(ctown,"fleetsinport."+fleetid);
}*/

// sets fleet to this town. Give townname of "" to clear from all towns. Returns true if fleet found in a town, false if found in no towns.
bool SetFleetInTown(string sTownName, string fleetid)
{
	if(!TOWNS_QUANTITY) return false; //if(!CheckAttribute(objTownStateTable,"towns.Quantity")) return false; // for when this is called during loading of game.
	bool washere = false;
	ref ctown;
	//string temp;
	if(sTownName == "Conceiçao") sTownName = "Conceicao";  // <-- fix by emrep for Trade Mission error
	for(int i = 0; i < TOWNS_QUANTITY; i++)
	{
		//temp = "t" + i;
		//makearef(ctown, objTownStateTable.towns.(temp));
		makeref(ctown, Towns[i]);
		washere = washere || CheckAttribute(ctown,"fleetsinport."+fleetid);
		if(ctown.id == sTownName)
		{
			//washere = CheckAttribute(ctown,"fleetsinport."+fleetid);
			//if(here && !washere)
				ctown.fleetsinport.(fleetid) = true;
			//if(!here && washere) DeleteAttribute(ctown,"fleetsinport."+fleetid);
		}
		else DeleteAttribute(ctown,"fleetsinport."+fleetid);
	}
	return washere;
}
// NK WM/IT <--

// NK 05-04-15 cleaned this and TownUpdate to not reget the ref every time.
//town update functions
void TownRecalc(ref ctown, bool instant)
{
	bool pirtown = sti(ctown.nation) == PIRATE;
	int size = sti(ctown.size);
	int ogold = sti(ctown.gold);
	int otroops = sti(ctown.troops);
	int ocrewQ = sti(ctown.crew.quantity);
	int ocrewM = sti(ctown.crew.morale);

	int gold = makeint(makefloat(size) * makefloat(TOWN_GOLD_SCALAR) * (0.8 + frand(0.4)));
	int troops = makeint(stf(ctown.size) * TOWN_TROOPS_SCALAR * (0.8 + frand(0.4))) * (0.5 + makefloat(GetDifficulty())/4.0) * (1 + pirtown); // NK 04-08-29 pirate towns get x2 troops

	int crewQ = makeint(stf(ctown.size)*TOWN_CREW_SCALAR * GetFame(GetMainCharacter(), -1) * (0.75 + frand(0.5))) * (1 + pirtown);
	if(crewQ < 5) crewQ = 5;
	if(DEBUGTOWNTABLE) Trace("Desired Crew Qty: " + crewQ);		// LDH changed log to trace - 17Jan09
	crewQ = makeint(makefloat(crewQ) * (2.5 - (makefloat(GetDifficulty()) / 2.0)));
	if(DEBUGTOWNTABLE) Trace("New Crew Qty: " + crewQ);		// LDH changed log to trace - 17Jan09
	int crewM = ((5-GetDifficulty()) * 10 + rand(20)) * (1 + pirtown);
	if(crewQ > size) crewQ = size;
	if(crewM > MORALE_MAX) crewM = MORALE_MAX;
	if(crewM < MORALE_MIN) crewM = MORALE_MIN;

	ctown.gold = ogold + makeint(makefloat(gold - ogold) * GOLD_CHANGE_RATIO);
	if(instant) ctown.gold = gold;
	gold = sti(ctown.gold);
	ctown.troops = otroops + makeint(makefloat(troops - otroops) * TROOPS_CHANGE_RATIO);
	if(instant) ctown.troops = troops;
	troops = sti(ctown.troops);
	TownDistributeTroops(ctown.id); // was sTownName
	ctown.crew.quantity = ocrewQ + makeint(makefloat(crewQ - ocrewQ) * CREW_CHANGE_RATIO);
	if(instant) ctown.crew.quantity = crewQ
	crewQ = sti(ctown.crew.quantity);
	ctown.crew.morale = crewM;
}

void TownUpdate(ref ctown, bool instant)
{
  // Error handling
  if(!CheckAttribute(ctown, "name")) return; 

	int random = 0;	 
  int economy = GetTownEconomy(ctown);
  bool captured = false;  
  
  // Random Town Events
	random = rand(RANDOM_TOWN_EVENT_PROBABILITY);
	if(random == RANDOM_TOWN_EVENT_PROBABILITY) LaunchRandomTownEvent(ctown);
  
	if(CheckAttribute(ctown,"captured")) captured = sti(ctown.captured);
	int size = sti(ctown.size);
	    
	// Only update town growth and wheat production once per week (roughly)
	if(GetDataDay() == 1 || GetDataDay() == 8 || GetDataDay() == 16 || GetDataDay() == 23)
	{  	
	
	  int sidx = -1; 
    if(CheckAttribute(ctown,"store")) sidx = sti(ctown.store);
  	bool bstore = sidx != -1; //for towns with no store
  	if(bstore) ref store = &Stores[sidx];
  	
    int wheatQ = size;
  	if(bstore)  wheatQ = GetStoreGoodsQuantity(store, GOOD_WHEAT);
  	float starve = 0.0;
  	if(CheckAttribute(ctown,"starve")) starve = stf(ctown.starve);
  	if(DEBUGTOWNTABLE) Trace("Updating " + ctown.id + "." + stringRet(captured," Town is sacked.","") + " Size " + size + ", wheat " + wheatQ);		// LDH changed log to trace - 17Jan09
  	if(bstore)
  	{
  		wheatQ -= (size * FOOD_PER_CREW /2); //eat food
  		if (wheatQ < 0) wheatQ = 0;
  		if(wheatQ * GROW_FOOD_SCALAR >= size)
  		{
  			starve = 0;
  			size += makeint(size/1000 * (18+8*economy));  // 0.2 to 3.4 % population increase
  			if(wheatQ * GROW_FOOD_SCALAR >= size*2) size += makeint(size/1000 * (18+8*economy)); // increase doubled if much wheat
  		}
  		else
  		{
  			//increment starving
  			if(wheatQ < size * MIN_FOOD_SCALAR) starve += (1.0 - (makefloat(wheatQ)/makefloat(size))) * STARVE_SCALAR;
  		}
  		size -= makeint(starve)*POP_CH; //decrement based on starving
  		//if(rounddown(starve)) Log_SetStringToLog("Starvation! " + (sti(ctown.size) - size) + " people die.");
  		ctown.starve = starve;
  		if(size > MAX_POP) size = MAX_POP;
  		ctown.size = size;
  		if(DEBUGTOWNTABLE) Trace("New size: " + size);		// LDH changed log to trace - 17Jan09
  		SetStoreGoods(store, GOOD_WHEAT, wheatQ);
  		if(size >= STORE_MINSIZE) { store.StoreSize = "large"; }
  		else { store.StoreSize = "small"; }
  	}
  	TownRecalc(&ctown, instant);
  }
	
// KK -->
	if(captured) {
		ctown.captured = false;
		LiberateTown(ctown.id);
	}
// <-- KK

	// NK WM/itemtrade 05-04-02 add ship in port check, right now just pchar
	bool flt = false;
	string TownID = "";
	if(CheckAttribute(GetMainCharacter(),"location.from_sea"))
	{
		TownID = GetTownIDFromLocID(Characters[GetMainCharacterIndex()].location.from_sea);
		if(TownID == ctown.id)
		{
			flt = true;
			ctown.fleetsinport.pchar = true;
		}
		// LDH 29Mar09
		if (TownID == "" || TownID == "-1")
		{
			ref pchar = GetMainCharacter();
			string island = "";
			if (pchar.location.from_sea != "")
				island = FindIslandByLocation(pchar.location.from_sea);
			if (island != "")
				TownID = GetAttribute(GetIslandByID(island),"towns.1"); // PB: For islands with no towns
		}
	}
	if(!flt) { DeleteAttribute(ctown,"fleetsinport.pchar"); }

	// LDH 29Mar09
	// Need to update all towns on an island where a character is on land 
	// so that going to another town by land won't have traders with no goods or money
	if (TownID != "" && TownID != "-1") // PB: For islands with no towns
	{
		if (GetIslandIDFromTown(ctown.id) == GetIslandIDFromTown(TownID))
		{
			flt = true;
		}
	}

	// itemtrade 05-04-05
	// move quality before fleetsize, and fix the non-stick error, 05-04-15
	int quality = 0; if(CheckAttribute(ctown,"itemtrade.basequality")) quality = sti(ctown.itemtrade.basequality);
	if(size > STORE_MINSIZE) { quality++; }
	else { if(size < STORE_MINSIZE / 2) { quality--; } }
	int oq = 0; if(CheckAttribute(ctown,"itemtrade.quality")) oq = sti(ctown.itemtrade.quality);
	// add section to handle changing quality
	bool tupdate = CheckAttribute(ShipLookupTable,"itemtraders") && sti(ShipLookupTable.itemtraders);
	if(oq != quality) // if quality doesn't match previous
	{
		if(!tupdate)
		{
			ctown.itemtrade.quality = quality;
			DeleteAttribute(ctown,"newqualdays");
		}
		else
		{
			//trace("qual mismatch town " + ctown.id + ", size " + size + "; old qual " + oq + ", new " +quality);
			if(!CheckAttribute(ctown, "newqualdays")) { ctown.newqualdays = 1; } // on first day, add attribute
			else
			{
				int qdays = sti(ctown.newqualdays);
				//trace("qdays = " + qdays);
				if(qdays < IT_UPD_TOWNQUAL_DAYS) // wait IT_UPD_TOWNQUAL_DAYS days.
				{
					qdays++; ctown.newqualdays = qdays;
				}
				else
				{
					//trace("setting new quality to " + quality + ", oq was " + oq);

					ctown.itemtrade.quality = quality;
					aref ittable; makearef(ittable, ShipLookupTable.itemtraders);
					ref ch;
					string id;
					for(int i = 0; i < GetAttributesNum(ittable); i++)
					{
						id = GetAttributeName(GetAttributeN(ittable, i));
						ch = CharacterFromID(id);
						// LDH need to update all towns on the island - 29Mar09
//						if(GetTownIDFromLocID(ch.location) == ctown.id) SetTraderItemStats(&ch, IT_RECALC_QL_TN);
						if (GetIslandIDFromTown(GetTownIDFromLocID(ch.location)) == GetIslandIDFromTown(ctown.id))
						{
							SetTraderItemStats(&ch, IT_RECALC_QL_TN);
						}
					}
				}
			}
		}
	}
	else
	{
		DeleteAttribute(ctown, "newqualdays"); //otherwise start again.
	}
	if(tupdate)
	{
		if(flt) size += GetSquadronCrewQuantity(GetMainCharacter()) * IT_UPD_TS_FLEET_MULT;
		float chmag = 1.0; if(CheckAttribute(ctown,"itemtrade.qty.chmag")) chmag = stf(ctown.itemtrade.qty.chmag);
		float base = 1.0 * (1.0 + (flt * ( IT_UPD_INPORTPC_MULT-1.0))); if(CheckAttribute(ctown,"itemtrade.baseqty")) base *= stf(ctown.itemtrade.baseqty);
		ctown.itemtrade.qty = base * pow2(Bring2RangeNoCheck(IT_TSIZE_MIN, IT_TSIZE_MAX, IT_TSIZE_MIN * IT_TSIZE_NORMAL, IT_TSIZE_MAX * IT_TSIZE_NORMAL, size), chmag);
		chmag = 1.0; if(CheckAttribute(ctown,"itemtrade.price.chmag")) chmag = stf(ctown.itemtrade.price.chmag);
		base = 1.0 * (1.0 + (flt * ( IT_UPD_INPORTPC_MULT-1.0))); if(CheckAttribute(ctown,"itemtrade.baseprice")) base *= stf(ctown.itemtrade.baseprice);
		ctown.itemtrade.price = base* pow2(Bring2RangeNoCheck(IT_TSIZE_MIN, IT_TSIZE_MAX, IT_TSIZE_MIN * IT_TSIZE_NORMAL, IT_TSIZE_MAX * IT_TSIZE_NORMAL, size), chmag);
	}
	// itemtrade<--
	// NK <--
}

void UpdateAllTowns(bool instant)
{
	int q;
	ref curtn;
	for(q = 0; q < TOWNS_QUANTITY; q++)
	{

		makeref(curtn, Towns[q]);
		TownUpdate(&curtn, instant);
	}
}


// Sulan -->
// Basic Town Economy
void AdjustTownEconomy(ref ctown, int Adjustment)
{
	int iEconomy;

	if(CheckAttribute(ctown, "economy")) iEconomy = sti(ctown.economy);
	else iEconomy = 0;
	iEconomy = iEconomy + Adjustment;
	if(iEconomy < TOWN_ECONOMY_STARVING) iEconomy = TOWN_ECONOMY_STARVING;
	if(iEconomy > TOWN_ECONOMY_WEALTHY) iEconomy = TOWN_ECONOMY_WEALTHY;
	ctown.economy = iEconomy;
}

int GetTownEconomy(ref ctown)
{
	int economy = 0;
	if(CheckAttribute(ctown, "economy")) economy = sti(ctown.economy);
	return economy;
}

string GetEconomyText(int economy)
{
	string sEconomy ="";
	
	switch(economy)
	{
		case TOWN_ECONOMY_STARVING:
			sEconomy = XI_ConvertString("TownStarving");
		break;
		case TOWN_ECONOMY_STRUGGLING:
			sEconomy = XI_ConvertString("TownStruggling");
		break;
		case TOWN_ECONOMY_SURVIVING:
			sEconomy = XI_ConvertString("TownSurviving");
		break;
		case TOWN_ECONOMY_PROSPERING:
			sEconomy = XI_ConvertString("TownProspering");
		break;
		case TOWN_ECONOMY_WEALTHY:
			sEconomy = XI_ConvertString("TownWealthy");
		break;
	}
	return sEconomy;
}

void LaunchRandomTownEvent(ref ctown)
{
	int random;
	int iSize;
	int iTroops;
	int iGold;
	int iEconomy;
	string logTitle;
	string logEntry;

//	if(ctown.id == "KhaelRoa")						return; // PB: Exclude Cozumel
//	if(IsIslandDisabled(ctown.island))				return; // PB: Exclude towns on disabled islands
	if(GetAttribute(ctown, "skiptrade") == true)	return; // PB: Exclude towns that are excluded from regular trade
//	if(GetTownNation(ctown.id) == PIRATE)			return; // PB: Specific events cancelled for pirate towns

	random = rand(RANDOM_TOWN_EVENTS_QTY-1);
	Preprocessor_Add("town", FindTownName(ctown.id));
	switch(random)
	{
		case RANDOM_TOWN_EVENT_MALARIA:
			logTitle = GetTranslatedLog("Malaria strikes #stown#");
			logEntry = GetTranslatedLog("An increasing number of people in #stown# are reported to have died from Malaria. The civilian losses were quite high, but the soldiers in the local garrison have suffered even more.");
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, abs(iSize * 2/3));
			iTroops = GetTownNumTroops(ctown.id);
			SetTownNumTroops(ctown.id, abs(iTroops/2));
			AdjustTownEconomy(ctown, -1);
		break;
		case RANDOM_TOWN_EVENT_PIRATES:
			if(GetTownNation(ctown.id) == PIRATE)
			{
				logTitle = GetTranslatedLog("Indians attack #stown#");
				logEntry = GetTranslatedLog("A major attack of indians on #stown# has been reported by travellers. The indians seem to have plundered and massacred the civilian population as well as the local garrison. Finally the cannons of the garrison drove them away, leaving the town completely desolate.");
				iSize = GetTownSize(ctown.id);
				SetTownSize(ctown.id, abs(iSize * 1/3));
				iTroops = GetTownNumTroops(ctown.id);
				SetTownNumTroops(ctown.id, abs(iTroops *1/4));
				iGold = GetTownGold(ctown.id);
				SetTownGold(ctown.id, abs(iGold * 3/5));         // indians are not as focused on gold as are pirates
				AdjustTownEconomy(ctown, -2);
			}
			else
			{
				logTitle = GetTranslatedLog("Pirates plunder #stown#");
				logEntry = GetTranslatedLog("A pirate assault on #stown# has been reported. Some pirates seem to have sneaked into town before their ships attacked the harbor in the middle of the night. Those in town took the garrison by surprise and kept the town gates open for their comrades. The whole attack didn't last much longer than two hours. The pirates escaped with a vast amount of gold, before the fort commander was able to gather his troops for defence. Several people died in the brutal attack, as they tried to defend their possesions on their own.");
				iSize = GetTownSize(ctown.id);
				SetTownSize(ctown.id, abs(iSize * 5/6));
				iTroops = GetTownNumTroops(ctown.id);
				SetTownNumTroops(ctown.id, abs(iTroops *9/10));
				iGold = GetTownGold(ctown.id);
				SetTownGold(ctown.id, abs(iGold * 1/5));
				AdjustTownEconomy(ctown, -1);
			}
		break;
		case RANDOM_TOWN_EVENT_GOLDFOUND:
			logTitle = GetTranslatedLog("Gold found near #stown#");
			logEntry = GetTranslatedLog("Miners from #stown# have struck a rich vein of gold. A new gold mine has been opened and the governor has sent for more troops in order to better protect the town from possible attacks. The new riches attract all kind of people, so #stown# is expected to grow.");
			iSize = GetTownSize(ctown.id) + 300;
			SetTownSize(ctown.id, iSize);
			iTroops = GetTownNumTroops(ctown.id) + 100;
			SetTownNumTroops(ctown.id, iTroops);
			iGold = GetTownGold(ctown.id)+(500*TOWN_GOLD_SCALAR);
			SetTownGold(ctown.id, iGold);
			AdjustTownEconomy(ctown, 2);
		break;
		case RANDOM_TOWN_EVENT_SILVERFOUND:
			logTitle = GetTranslatedLog("Silver found near #stown#");
			logEntry = GetTranslatedLog("Miners from #stown# have struck a rich vein of silver. A new silver mine has been opened and the governor has sent for more troops in order to better protect the town from possible attacks. The new riches attract all kind of people, so #stown# is expected to grow.");
			iSize = GetTownSize(ctown.id) + 200;
			SetTownSize(ctown.id, iSize);
			iTroops = GetTownNumTroops(ctown.id) + 60;
			SetTownNumTroops(ctown.id, iTroops);
			iGold = GetTownGold(ctown.id)+(300*TOWN_GOLD_SCALAR);
			SetTownGold(ctown.id, iGold);
			AdjustTownEconomy(ctown, 1);
		break;
		case RANDOM_TOWN_EVENT_INDIANS:
			logTitle = GetTranslatedLog("Indians attack #stown#");
			logEntry = GetTranslatedLog("A major attack of indians on #stown# has been reported by travellers. The indians seem to have plundered and massacred the civilian population as well as the local garrison. Finally the cannons of the garrison drove them away, leaving the town completely desolate.");
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, abs(iSize * 1/3));
			iTroops = GetTownNumTroops(ctown.id);
			SetTownNumTroops(ctown.id, abs(iTroops *1/4));
			iGold = GetTownGold(ctown.id);
			SetTownGold(ctown.id, abs(iGold * 3/5));         // indians are not as focused on gold as are pirates
			AdjustTownEconomy(ctown, -2);
		break;
		case RANDOM_TOWN_EVENT_SLAVEREVOLT:
			logTitle = GetTranslatedLog("Slave revolt at #stown#");
			logEntry = GetTranslatedLog("The governor of #stown# spread news that a slave revolt has been put down by the local garrison. All surviving marauders were hanged as a warning. Although the rebellion has been put down, the loss of quite a lot of slaves is expected to have a bad impact on the economy of #stown#.");
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, abs(iSize * 3/4));
			iTroops = GetTownNumTroops(ctown.id);
			SetTownNumTroops(ctown.id, abs(iTroops *7/8));
			AdjustTownEconomy(ctown, -1);
		break;
		case RANDOM_TOWN_EVENT_FIRE:
			logTitle = GetTranslatedLog("Serious fire in #stown#");
			logEntry = GetTranslatedLog("A serious fire has laid waste to parts of #stown#. The fire erupted near the harbor, where a warehouse suddenly exploded into flames. There is rumor it was stocked with oil or gunpowder or even both. The fire quickly spread and could not be quenched until two days later. Quite a lot of people are reported to have died in the attempt to save their belongings from the flames.");
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, abs(iSize * 4/5));
			iGold = GetTownGold(ctown.id);
			SetTownGold(ctown.id, abs(iGold * 3/5));
			AdjustTownEconomy(ctown, -1);
		break;
		case RANDOM_TOWN_EVENT_HURRICANE:
			logTitle = GetTranslatedLog("Hurricane strikes #stown#");
			logEntry = GetTranslatedLog("#stown# has been struck by a serious hurricane. Wind and water destroyed many buildings in town, especially the poorer parts were hit badly. Several ships in the harbor sunk as a result of the hurricane. Diseases are expected to spread throughout town as usual after such disasters.");
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, abs(iSize * 4/5));
			iTroops = GetTownNumTroops(ctown.id);
			SetTownNumTroops(ctown.id, abs(iTroops *7/8));
			iGold = GetTownGold(ctown.id);
			SetTownGold(ctown.id, abs(iGold * 3/5));
			AdjustTownEconomy(ctown, -1);
		break;
		case RANDOM_TOWN_EVENT_SETTLERS:
			logTitle = GetTranslatedLog("New settlers at #stown#");
			logEntry = GetTranslatedLog("A convoy of ships bringing new settlers from Europe has arrived at #stown#. The new settlers are badly needed to strengthen the economy of the town. It has been reported that the convoy also brought luxury goods and new inventions from Europe to the colonies, as well as a small battalion of soldiers.");
			iSize = GetTownSize(ctown.id) + 150;
			SetTownSize(ctown.id, iSize);
			iTroops = GetTownNumTroops(ctown.id)+50;
			SetTownNumTroops(ctown.id, iTroops);
			iGold = GetTownGold(ctown.id);
			SetTownGold(ctown.id, abs(iGold * 6/5));
			AdjustTownEconomy(ctown, 1);
		break;  
		case RANDOM_TOWN_EVENT_EXPEDITION:
			logTitle = GetTranslatedLog("Expedition returns to #stown#");
			logEntry = GetTranslatedLog("An expedition into the jungle has returned to #stown#. The expedition was a great success, as the explorers found a gold vein not far away, which was exploited by a native tribe. The explorers captured the village and enslaved the surviving indians in order to establish a new mining camp. The expedition finally returned with a great amount of goods and gold, several hitherto unknown plants and a number of slaves.");
			iSize = GetTownSize(ctown.id)+200;
			SetTownSize(ctown.id, iSize);
			iTroops = GetTownNumTroops(ctown.id);
			iGold = GetTownGold(ctown.id)+(700*TOWN_GOLD_SCALAR);
			SetTownGold(ctown.id, iGold);
			AdjustTownEconomy(ctown, 2);
		break;
		case RANDOM_TOWN_EVENT_GOODECO:   // There are usually no news telling that a city performed well, it happens unnoticed.
			logTitle ="";
			AdjustTownEconomy(ctown, 1);
		break;
	}
	if(logTitle != "") WriteNewLogEntry(PreprocessText(logTitle), PreprocessText(logEntry), "General", false);
	Preprocessor_Delete("town");
}
// <-- Sulan


// added 05-04-17
void UpdateAllStores(bool instant)
{
	int s;
	if(instant) { for(s = 0; s < STORE_QUANTITY; s++) { FillStoreGoods2(&Stores[s]); } }
	else { for(s = 0; s < STORE_QUANTITY; s++) { UpdateStore(&Stores[s]); } }

}

// KK -->
void InitTownTable(bool first)
{
	int i, flagidx, flagtex;
	ref rTown;
	ref mchr = GetMainCharacter();
	string stmp = "Towns\InitTowns.c";
	if (LoadSegment(stmp)) {
		InitTowns(first);
		UnloadSegment(stmp);
	}
	stmp = GetStorylinePath(FindCurrentStoryline());
	if (FindFile("PROGRAM\" + stmp + "Towns", "*.c", "InitTowns.c") != "") {
		stmp += "Towns\InitTowns.c";
		if (LoadSegment(stmp)) {
			InitTowns(first);
			UnloadSegment(stmp);
		}
	}
	for (i = 0; i < TOWNS_QUANTITY; i++)
	{
		rTown = GetTownByIndex(i);
		// PB: Pirate and Personal Towns Always Same Flag -->
/*		if (GetTownNation(rTown.id) == PIRATE) {
			if (!CheckAttribute(rTown, "Flags.Pirate")) rTown.Flags.Pirate = rand(FLAGS_PICTURES_QUANTITY_PER_TEXTURE - 2); // PB: -2 to prevent Jack Sparrow flag in random encounters
			if (!CheckAttribute(rTown, "Flags.Pirate.texture")) rTown.Flags.Pirate.texture = rand(PIRATEFLAGS_TEXTURES_QUANTITY - 1);
			flagidx = GetPirateFlag(mchr, &flagtex);
			if (sti(rTown.Flags.Pirate.texture) == flagtex && sti(rTown.Flags.Pirate) == flagidx) {
				if (flagidx == 0)
					rTown.Flags.Pirate = flagidx + 1;
				else
					rTown.Flags.Pirate = flagidx - 1;
			}
		}*/
/*		if (GetTownNation(rTown.id) == PRIVATEER_NATION) {
			if (!CheckAttribute(rTown, "Flags.Personal")) rTown.Flags.Personal = rand(FLAGS_PICTURES_QUANTITY_PER_TEXTURE - 1);
			if (!CheckAttribute(rTown, "Flags.Personal.texture")) rTown.Flags.Personal.texture = rand(PERSONALFLAGS_TEXTURES_QUANTITY - 1);
			flagidx = GetPersonalFlag(mchr, &flagtex);
			if (sti(rTown.Flags.Personal.texture) == flagtex && sti(rTown.Flags.Personal) == flagidx) {
				if (flagidx == 0)
					rTown.Flags.Personal = flagidx + 1;
				else
					rTown.Flags.Personal = flagidx - 1;
			}
		}*/
		// PB: Pirate and Personal Towns Always Same Flag <--
	}
}

void ModifyTown(ref refTown)
{
	if (!CheckAttribute(refTown, "id")) return;
	int tidx = GetTownIndex(refTown.id);
	if (tidx < 0) return;
	int iNation = -1;
	ref town = GetTownByIndex(tidx);
	if (CheckAttribute(refTown, "name"))
		town.name = refTown.name;
	else
		refTown.name = town.name;
	if (CheckAttribute(refTown, "monsterprob")) town.monsterprob = refTown.monsterprob;
	if (CheckAttribute(refTown, "size")) town.size = refTown.size;
	if (CheckAttribute(refTown, "gold")) town.gold = refTown.gold;
	if (CheckAttribute(refTown, "nation")) {
		iNation = sti(refTown.nation);
		town.homeland = iNation;
	}
	if (CheckAttribute(refTown, "gov")) town.gov = refTown.gov;
	if (CheckAttribute(refTown, "officiant")) town.officiant = refTown.officiant;
	if (CheckAttribute(refTown, "troops")) town.troops = refTown.troops;
	if (CheckAttribute(refTown, "crew.quantity")) town.crew.quantity = refTown.crew.quantity;
	if (CheckAttribute(refTown, "crew.morale")) town.crew.morale = refTown.crew.morale;
	town.do_firstinit = true;
	CaptureTownForNation(town.id, iNation);
	DeleteAttribute(town, "do_firstinit");
	SetTownName(town.id, refTown.name);
	Preprocessor_Delete(town.id);
	Preprocessor_Save(town.id, refTown.name));
	DeleteAttribute(refTown, "");
}
// <-- KK

// ****************** STORES SECTION *********************
void FillStoreGoods2(ref pRef)
{
	int i,j,nq,n,tt;
	int economy = 0;
	string goodName;
	int goodBasePrice;

	int islandIdx = FindIsland(pRef.Island);
	aref arTypes,arCurGoods,arCurType;
	if(islandIdx!=-1)
	{

		ref rTown = GetTownFromGroup(pRef.group);
		if(CheckAttribute(rTown, "economy")) economy = sti(rTown.economy);

		ref rIsland = GetIslandByIndex(islandIdx);
		makearef(arTypes,rIsland.Trade);
		nq = GetAttributesNum(arTypes);
		for(i=0;i<nq;i++)
		{
			arCurType = GetAttributeN(arTypes,i);
			tt=TRADE_TYPE_NORMAL;
			switch(GetAttributeName(arCurType))
			{
			case "Export":		tt=TRADE_TYPE_EXPORT;		break;
			case "Import":		tt=TRADE_TYPE_IMPORT;		break;
			case "Contraband":	tt=TRADE_TYPE_CONTRABAND;	break;
			}
			n = GetAttributesNum(arCurType);
			for(j=0;j<n;j++)
			{
				goodName = Goods[sti(GetAttributeValue(GetAttributeN(arCurType,j)))].name;
				pRef.Goods.(goodName).TradeType = tt;
			}
		}
	}
	else
	{
		trace("Mistake island id into store:  id="+pRef.Island);
	}
	// NK -->
	int tsize = DEFAULT_TOWN_POP;
	bool pirtown = false;
	if(GetTownIDFromGroup(pRef.group) != "")
	{
		tsize = GetTownSize(GetTownIDFromGroup(pRef.group));
		if(tsize > STORE_MINSIZE) {pRef.StoreSize = "large";}
		else {pRef.StoreSize = "small";}
		pirtown = GetTownNation(GetTownIDFromGroup(pRef.group)) == PIRATE;
	}
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		goodName = Goods[i].Name;
		if( i==GOOD_BALLS || i==GOOD_GRAPES || i==GOOD_KNIPPELS || i==GOOD_BOMBS )
		{
			pRef.Goods.(goodName).Quantity = makeint(TT_AMMO_SCALE * makefloat(1+pirtown) * makefloat(tsize)*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0)))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = 1.0;
			pRef.Goods.(goodName).TradeType = TRADE_TYPE_AMMUNITION;
			continue;
		}
		/*if( i==GOOD_PLANKS || i==GOOD_SAILCLOTH )
		{
			pRef.Goods.(goodName).Quantity = 500+Rand(50)*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = 1.0;
			//pRef.Goods.(goodName).TradeType = TRADE_TYPE_AMMUNITION;
			continue;
		}*/
		goodBasePrice = MakeInt(goods[i].Cost);
		switch(sti(pRef.Goods.(goodName).TradeType))
		{
		case TRADE_TYPE_NORMAL:
			pRef.Goods.(goodName).Quantity = makeint(TT_NORMAL_SCALE * makefloat(tsize)*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0))+(makefloat(tsize)*0.1*economy))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_EXPORT:
			pRef.Goods.(goodName).Quantity = makeint(TT_EXPORT_SCALE * makefloat(tsize)*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0))+(makefloat(tsize)*0.1*economy))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_IMPORT:
			pRef.Goods.(goodName).Quantity = makeint(TT_IMPORT_SCALE * makefloat(tsize)*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0))+(makefloat(tsize)*0.1*economy))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_CONTRABAND:
			pRef.Goods.(goodName).Quantity = makeint(TT_CONTRABAND_SCALE * makefloat(tsize)*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0)))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd();
			break;
		}
		if(i == GOOD_WHEAT)
		{
			pRef.Goods.(goodName).Quantity = makeint(TT_NORMAL_SCALE * makefloat(tsize)*(1.0 - GQTY_VARIANCE/4.0 + frand(GQTY_VARIANCE)))*sti(goods[i].Units);
			//Log_SetStringToLog("Store " + pRef.group + " of town " +  GetTownIDFromGroup(pRef.group) + " (pop " + tsize + ") has " + pRef.Goods.(goodName).Quantity + " wheat.");
		}
	}
}
// RM <--

// KK -->
string GetBestTown(string id)
{
	string IslandName = "";
	float rel1;
	float rel;
	int n = 0;
	int sel = 1;
	if (id == "") return ""; // PB: Invalid function call
	if (CheckAttribute(Locations[FindLocation(id)], "townsack")) return Locations[FindLocation(id)].townsack;
	if (CheckAttribute(Locations[FindLocation(id)], "island")) IslandName = Locations[FindLocation(id)].island;

	n = GetIslandTownsQuantity(IslandName);
	if (n < 1) return "";

	rel = GetNationRelation2MainCharacter(GetTownNation(GetTownIDFromIsland(IslandName, 1))));
	rel1 = rel;
	for (int i = 2; i <= n; i++) {
		rel1 = GetNationRelation2MainCharacter(GetTownNation(GetTownIDFromIsland(IslandName, i))));
		if (rel < rel1) {
			rel = rel1;
			sel = i;
		}
	}
	return GetTownIDFromIsland(IslandName, sel);
}

bool PlaceFleetNearShore(string id)
{
	ref mc = GetMainCharacter();
	if (FindLocation(id) == -1 || GetCharacterShipType(mc) == SHIP_NOTUSED) return false;
	SetCharacterShipLocation(mc, id);
	float x, z;
	if (wdmGetShorePos(id, &x, &z)) {
		worldMap.playerShipX = x;
		worldMap.playerShipZ = z;
		worldMap.playerShipAY = 3.0;
	}
	return true;
}

void SetTownGarrisonForNation(string town, int iNation)
{
	int n;
	bool chknation = iNation >= 0 && iNation < NATIONS_QUANTITY;
	int oldNation = GetTownNation(town);
	int homeland = GetTownHomeland(town);
	string sNation, model;
	ref mchr = GetMainCharacter();
	ref character;
	bool bFirstInit = false;

	if (!TownExist(town)) return;
	chknation = chknation || iNation == PERSONAL_NATION;
	if (!chknation) return;
	if (CheckAttribute(GetTownFromID(town), "do_firstinit")) bFirstInit = sti(Towns[GetTownIndex(town)].do_firstinit);
trace("SetTownGarrisonForNation: town="+town+", 1st="+bFirstInit);

	for (n = 0; n < CHARACTERS_QUANTITY; n++) {
		character = GetCharacter(n);
		if (CheckAttribute(character, "location") == false || FindLocation(character.location) < 0 || GetTownGovernorIndex(town) == n || IsOfficer(character) == true) continue;
		if (GetTownIDFromLocID(character.location) == town) {
			if (bAllies(character)) continue; // PB: Skip any characters that are with the player
			if (GetAttribute(character, "Dialog.Filename") != "tailor_dialog.c" || iNation != PERSONAL_NATION)	character.nation = iNation; // PB: Skip tailor nation change when taking town for yourself
			if (isSoldier(character) != UNKNOWN_NATION) {
				if (!CheckAttribute(character, "model.uniform")) continue;	// LDH  15Jan09
				if (CheckAttribute(character, "old.location")) {
					character.location = character.old.location;
					DeleteAttribute(character, "old.location");
				}
				if (!CheckAttribute(character, "questchar"))
				{
					SetRandomNameToCharacter(character);
					character.old.name = "";
					character.old.lastname = "";
				}
				if (character.Dialog.Filename == GetSoldiersDialog(oldNation, town) || character.Dialog.Filename == "Story_Fra_Occup_common_dialog.c") // PB: Only change his dialog file if it is the DEFAULT soldier dialog file
					character.Dialog.Filename = GetSoldiersDialog(iNation, town);
				character.greeting = GetSoldiersGreeting(iNation, town);
				GiveSoldierWeapon(character, iNation);	// ARF: Update Soldier Weapons
				model = "m" + sti(character.model.uniform);
				if (iNation != PERSONAL_NATION) {
					SetModel(character, Nations[iNation].fantomModel.(model), character.sex, character.sex, 0.0, false);
				} else {
					SetModel(character, mchr.Soldier.(model), character.sex, character.sex, 0.0, false);
				}
				LAi_group_MoveCharacter(character, GetSoldiersGroup(iNation));
			} else {
				if (iNation != PERSONAL_NATION) {
					if (bFirstInit) {
						sNation = "n" + oldNation;
						if (!CheckAttribute(character, "nation." + sNation)) {
							character.nation.(sNation).name = character.name;
							if (CheckAttribute(character, "middlename")) {
								character.nation.(sNation).middlename = character.middlename;
							} else {
								if (CheckAttribute(character, "nation." + sNation + ".middlename")) DeleteAttribute(character, "nation." + sNation + ".middlename");
							}
							character.nation.(sNation).lastname = character.lastname;
						}
						sNation = "n" + iNation;
						if (CheckAttribute(character, "nation." + sNation)) {
							character.name = character.nation.(sNation).name;
							character.old.name = character.name;
							if (CheckAttribute(character, "nation." + sNation + ".middlename")) {
								character.middlename = character.nation.(sNation).middlename;
								character.old.middlename = character.middlename;
							}
							character.lastname = character.nation.(sNation).lastname;
							character.old.lastname = character.lastname;
						} else {
							if (!CheckAttribute(character, "questchar"))
							{
								if (CheckAttribute(character, "middlename")) {
									DeleteAttribute(character, "old.middlename");
									DeleteAttribute(character, "middlename");
								}
								character.name = "";
								character.old.name = "";
								character.lastname = "";
								character.old.lastname = "";
								SetRandomNameToCharacter(character);
							}
						}
					}
				}
				LAi_group_MoveCharacter(character, GetCitizensGroup(iNation));
				SetTownCharacterGreeting(character, iNation);
			}
			character.old.chr_ai.group = character.chr_ai.group;
		}
	}
}

void OccupyTown(string town)
{
	int n, nforts;
	ref chr;
	ref mchr = GetMainCharacter();

	if (!TownExist(town)) return;
	for (n = 0; n < CHARACTERS_QUANTITY; n++)
	{
		chr = GetCharacter(n);
		if (!CheckAttribute(chr, "location") || FindLocation(chr.location) == -1) continue;
		if (GetTownIDFromLocID(chr.location) == town && isSoldier(chr) != UNKNOWN_NATION) {
			chr.old.location = characters[n].location;
			chr.location = "none";
		}
	}
	nforts = GetTownNumForts(town);
	for (n = 0; n < nforts; n++)
	{
		chr = GetTownFortCommander(town, n);
		chr.Fort.Mode = FORT_DEAD;
		chr.nation = NEUTRAL_NATION;
		// data of fort die
		chr.Fort.DieTime.Year = GetDataYear();
		chr.Fort.DieTime.Month = GetDataMonth();
		chr.Fort.DieTime.Day = GetDataDay();
		chr.Fort.DieTime.Time = GetTime();
	}
}

void LiberateTown(string town)
{
	int n;
	ref chr;
	ref mchr = GetMainCharacter();

	if (!TownExist(town)) return;
	for (n = 0; n < CHARACTERS_QUANTITY; n++)
	{
		chr = GetCharacter(n);
		if (!CheckAttribute(chr, "old.location") || FindLocation(chr.old.location) == -1) continue;
		if (GetTownIDFromLocID(chr.old.location) == town && isSoldier(chr) != UNKNOWN_NATION) {
			chr.location = chr.old.location;
			DeleteAttribute(chr, "old.location");
		}
	}
}

void CaptureTownForNation(string town, int iNation)
{
	bool chknation = iNation >= 0 && iNation < NATIONS_QUANTITY;
	int orgNation = GetTownNation(town);
	string sNation = "n" + iNation;
	ref island = GetIslandFromTown(town);
	bool bFirstInit = false;

	chknation = chknation || iNation == PERSONAL_NATION;
	if (!chknation || !TownExist(town)) return;
	if (orgNation == iNation) return; // PB: Don't do any of the below if the town is already of that nationality
	if (CheckAttribute(GetTownFromID(town), "do_firstinit")) bFirstInit = sti(Towns[GetTownIndex(town)].do_firstinit);
trace("CaptureTownForNation: town="+town+", 1st="+bFirstInit);

	if (CheckAttribute(island, "smuggling_nation") == true && sti(island.smuggling_nation) == orgNation) // PB: was && iNation != PERSONAL_NATION
	{
		island.smuggling_nation = iNation;
		UpdateIslandSmugglingState(island); // PB: Probably should update this, no?
	}

	wdmSetIcon(town, "", iNation);
	SetTownGarrisonForNation(town, iNation);
	SetTownNation(town, iNation);
	Towns[GetTownIndex(town)].laigroup = GetNationAIGroup(iNation, "");

	if (IsEntity(GetMainCharacter())) {
		if (iNation == PERSONAL_NATION) {
			Log_SetStringToLog(TranslateString("", "Colony of") + " " + FindTownName(town) + " " + TranslateString("", "captured by") + " " + GetMyFullName(GetMainCharacter()) + ".");
		} else {
			Log_SetStringToLog(TranslateString("", "Colony of") + " " + FindTownName(town) + " " + TranslateString("", "captured by") + " " + TranslateString("", GetNationNameByType(iNation)) + ".");
		}
	}

	int govidx = GetTownGovernorIndex(town);
	if (govidx >= 0) {
		ref gov = &characters[govidx];
		gov.nation = iNation;
		if (iNation != PERSONAL_NATION)
		{
			SetRandomNameToCharacter(gov);
			switch(iNation)
			{
				case ENGLAND:
					gov.greeting = "Gr_Robert Christopher Silehard";
				break;
				case FRANCE:
					gov.greeting = "Gr_joseph claude le moigne";
				break;
				case SPAIN:
					gov.greeting = "Gr_Christofor Manuel de Alencar";
				break;
				case PIRATE:
					gov.greeting = "Gr_Isenbrandt Jurcksen";
				break;
				case HOLLAND:
					gov.greeting = "Gr_Reynard Grueneveldt";
				break;
				case PORTUGAL:
					gov.greeting = "Gr_Jacinto Arcibaldo Barreto";
				break;
				case AMERICA:
					gov.greeting = "Gr_Robert Christopher Silehard";
				break;
			}
			SetModelFromID(gov, GetRandomModelForTypeExSubCheck(-1, "Rich_citizens", "man", iNation)); // PB: Give this guy a random model
		}
	}
	int nforts = GetTownNumForts(town);
	for (int i = 0; i < nforts; i++) {
		ref fortchar = GetTownFortCommander(town, i);
		fortchar.nation = iNation;
		ResetCharacterMemory(fortchar); // PB
		if (iNation != PERSONAL_NATION) SetModelFromID(fortchar, SelectSoldierModelByNation(iNation, "officer"));
	}

	if (iNation == PERSONAL_NATION && GetCurrentFlag() != PERSONAL_NATION && GetNationRelation(PERSONAL_NATION, GetCurrentFlag()) == RELATION_ENEMY)
		HoistFlag(PERSONAL_NATION); // GR: if you capture the town for yourself while flying a flag hostile to yourself, auto-hoist Personal flag to avoid trouble with your own fort and soldiers
}

bool DisableTownCapture(string town, bool disable)
{
	if (!TownExist(town)) return true;
	ref rtown = GetTownFromID(town);
	if (!CheckAttribute(rtown, "disable_capture")) {
		if (disable) rtown.disable_capture = 1;
		return disable;
	}
	int disable_capture = sti(rtown.disable_capture);
	if (disable)
		disable_capture++;
	else
		disable_capture--;
	rtown.disable_capture = disable_capture;
	if (disable_capture <= 0 && CheckAttribute(rtown, "disable_capture") == true) DeleteAttribute(rtown, "disable_capture");
	return disable;
}

bool isEnabledTownCapture(string town)
{
	if (!TownExist(town)) return false;
	ref rtown = GetTownFromID(town);
	if (CheckAttribute(rtown, "disable_capture")) {
		if (sti(rtown.disable_capture) > 0) {
			return false;
		} else {
			DeleteAttribute(rtown, "disable_capture");
			return true;
		}
	}
	return true;
}

string FindTownTavern(string sTown)
{
	ref officiant;
	if (!TownExist(sTown)) return "";
	officiant = GetTownOfficiant(sTown);
	if (CheckAttribute(officiant, "tavern.location")) return officiant.tavern.location;
	return "";
}

int GetTownTavernOwnerIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "tavern")) return -1;
	return GetCharacterIndex(refStore.tavern);
}

int GetTownOfficiantIndex(string sTownName)
{
	ref ctown = GetTownFromID(sTownName);
	int officiant = -1;
	if(CheckAttribute(ctown, "officiant")) officiant = GetCharacterIndex(ctown.officiant);
	return officiant;
}

ref GetTownOfficiant(string sTownName)
{
	return GetCharacter(GetTownOfficiantIndex(sTownName));
}

//Levis -->
bool CheckOfficiantHadSex(string townid)
{
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar,"Sexwith")) return false;
	ref officiant = GetTownOfficiant(townid);
	if(!CheckAttribute(PChar,"Sexwith."+officiant.id)) return false;
	return true;
}
//Levis <--

int GetTownStoreOwnerIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "owner")) return -1;
	return GetCharacterIndex(refStore.owner);
}

ref GetTownStoreOwner(string sTownName)
{
	int idx = GetTownStoreIndex(sTownName);
	if (idx >= 0) return GetCharacter(idx);
	return &NullCharacter;
}

int GetTownShipyardOwnerIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "dockyard")) return -1;
	return GetCharacterIndex(refStore.dockyard);
}

string GetTownShore(string townID)
{
	if (!TownExist(townID)) return "";
	ref refOfficiant = GetTownOfficiant(townID);
	if (CheckAttribute(refOfficiant, "resurrection.shore")) return refOfficiant.resurrection.shore;
	return "";
}

int GetTownUsurerIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "usurer")) return -1;
	return GetCharacterIndex(refStore.usurer);
}

int GetTownTaylorIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "taylor")) return -1;
	return GetCharacterIndex(refStore.taylor);
}

int GetTownBlacksmithIndex(string sTownName)
{
	ref refStore;
	if (!TownExist(sTownName)) return -1;
	refStore = GetTownStore(sTownName);
	if (!CheckAttribute(refStore, "blacksmith")) return -1;
	return GetCharacterIndex(refStore.blacksmith);
}

int GetProfitFromTowns()
{
	int profit = 0;
	int moralech;
	for (int i = 0; i < TOWNS_QUANTITY; i++) {
		if (GetTownNation(Towns[i].id) == PERSONAL_NATION && CheckAttribute(Towns[i], "tax") == true) {
			profit += sti(makefloat(Towns[i].tax) * makefloat(GetTownSize(Towns[i].id)) / 5.0);
			if (rand(11) > 10) {
				moralech = TAX_NORMAL - sti(Towns[i].tax);
				SetTownCrewMorale(Towns[i].id, GetTownCrewMorale(Towns[i].id) + moralech);
			}
		}
	}
	return profit;
}

bool SetTownGovernor(string TownName, ref refMyChar)
{
	int chridx;
	string chrid;
	ref refchar, rtmp;
	aref artmp;
	object objtmp;

	chridx = GetTownGovernorIndex(TownName);
	if (chridx < 0 || chridx >= CHARACTERS_QUANTITY) return false;
	refchar = GetCharacter(chridx);
	chrid = refchar.id;
	//chridx = GetCharacterIndex(chrid);
	makeref(rtmp, objtmp);
	CopyAttributes(rtmp, refChar);
	DeleteAttribute(refChar, "");
	CopyAttributes(refChar, refMyChar);
	refChar.orig = "";
	makearef(artmp, refChar.orig);
	CopyAttributes(&artmp, rtmp);

	refChar.id = chrid;
	refChar.index = chridx;
	refChar.location = refchar.orig.location;
	refChar.location.group = refchar.orig.location.group;
	refChar.location.locator = refchar.orig.location.locator;
	DeleteAttribute(refChar, "location.from_sea"); // PB: Prevent potential CTDs
	// PB: Fix for Female Governors -->
	SetModelfromArray(refChar, GetModelIndex(refChar.model));
	if (refChar.sex == "woman")
	{
		ChangeCharacterAddressGroup(refChar, refChar.location, "goto", GetNearLocatorToLocator(refChar.location.group, refChar.location.locator, "goto"));
		LAi_SetStayType(refChar);
	}
	else
	{
		if (refChar.location.group == "sit")
		{
			LAi_SetHuberType(refChar);
		}
		else
		{
			LAi_SetHuberStayType(refChar);
		}
	}
	// PB: Fix for Female Governors <--
	DeleteAttribute(refChar, "officer");
	DeleteAttribute(refChar, "offgen");
	DeleteAttribute(refChar, "quest");
	refChar.quest = "True";
	refChar.quest.meeting = 0;
	refChar.nation = PERSONAL_NATION;
	if (CheckAttribute(refChar, "orig.chr_ai.tmpl")) refChar.chr_ai.tmpl = refChar.orig.chr_ai.tmpl;
	if (CheckAttribute(refChar, "orig.Dialog.filename")) refChar.Dialog.filename = refChar.orig.Dialog.filename;
	if (CheckAttribute(refChar, "orig.Dialog.filename.GroupDialog")) refChar.Dialog.filename.GroupDialog = refChar.orig.Dialog.filename.GroupDialog;
	if (CheckAttribute(refChar, "orig.Dialog.CurrentNode")) refChar.Dialog.CurrentNode = refChar.orig.Dialog.CurrentNode;
	if (CheckAttribute(refChar, "orig.Dialog.TempNode")) refChar.Dialog.TempNode = refChar.orig.Dialog.TempNode;
	if (CheckAttribute(refChar, "orig.quest")) refChar.quest = refChar.orig.quest;
	if (CheckAttribute(refChar, "orig.quest.meeting")) refChar.quest.meeting = refChar.orig.quest.meeting;

	refChar.OfficerIdx = GetCharacterIndex(refMyChar.id);

	ChangeCharacterAddressGroup(refMyChar, "None", "", "");
//	RemovePassenger(GetMainCharacter(), refMyChar);

	return true;
}

bool SetTownFortCommander(string TownName, ref refMyChar)
{
	string chrid;
	int chridx;
	ref refchar, rtmp;
	aref artmp;
	object objtmp;

	refchar = GetTownFortCommander(TownName, 0);
	chrid = refchar.id;
	chridx = GetCharacterIndex(chrid);
	makeref(rtmp, objtmp);
	CopyAttributes(rtmp, refChar);
	DeleteAttribute(refChar, "");
	CopyAttributes(refChar, refMyChar);
	refChar.orig = "";
	makearef(artmp, refChar.orig);
	CopyAttributes(&artmp, rtmp);

	refChar.id = chrid;
	refChar.index = chridx;
	refChar.name = refMyChar.name;
	refChar.old.name = refMyChar.old.name;
	refChar.location = refchar.orig.location;
	refChar.location.group = refchar.orig.location.group;
	refChar.location.locator = refchar.orig.location.locator;
	DeleteAttribute(refChar, "location.from_sea"); // PB: Prevent potential CTDs
	refChar.Dialog.Filename = "";
	refChar.Dialog.CurrentNode = "";
	refChar.Dialog.TempNode = "";
	DeleteAttribute(refChar, "officer");
	DeleteAttribute(refChar, "offgen");
	DeleteAttribute(refChar, "quest");
	DeleteAttribute(refChar, "relation_to_pirates"); // PB
	refChar.quest = "True";
	refChar.quest.meeting = 0;
	refChar.quest.escort = 0;
	refChar.nation = PERSONAL_NATION;
	refChar.ship.type = refChar.orig.ship.type;
	refChar.Fort.Cannons.Charge.Type = refChar.orig.Fort.Cannons.Charge.Type;
	refChar.Fort.Cannons.Type.1 = refChar.orig.Fort.Cannons.Type.1;
	refChar.Fort.Cannons.Type.1.Quantity = refChar.orig.Fort.Cannons.Type.1.Quantity;
	refChar.Fort.Cannons.Type.2 = refChar.orig.Fort.Cannons.Type.2;
	refChar.Fort.Cannons.Type.2.Quantity = refChar.orig.Fort.Cannons.Type.2.Quantity;
	refChar.Ship.Cargo.Goods.Balls = refChar.orig.Ship.Cargo.Goods.Balls;
	refChar.Ship.Cargo.Goods.Grapes = refChar.orig.Ship.Cargo.Goods.Grapes;
	refChar.Ship.Cargo.Goods.Knippels = refChar.orig.Ship.Cargo.Goods.Knippels;
	refChar.Ship.Cargo.Goods.Bombs = refChar.orig.Ship.Cargo.Goods.Bombs;
	refChar.Ship.Cargo.Goods.Gunpowder = refChar.orig.Ship.Cargo.Goods.Gunpowder;
	refChar.town = refChar.orig.town;

	refChar.OfficerIdx = GetCharacterIndex(refMyChar.id);

	ChangeCharacterAddressGroup(refMyChar, "None", "", "");
//	RemovePassenger(GetMainCharacter(), refMyChar);

	return true;
}

void AddTown(ref n, ref ctown)
{
	int iNation;
	string stmp;
	ref rPeriod, rTown, chr;
	aref archr;
	if (!CheckAttribute(ctown, "id")) {
		DeleteAttribute(ctown, "");
		return;
	}
	stmp = ctown.id;
	makeref(rPeriod, Periods[GetCurrentPeriod()]);
	makeref(rTown, Towns[n]);
	DeleteAttribute(rTown, "");
	CopyAttributes(rTown, ctown);
	DeleteAttribute(ctown, "");
	if (CheckAttribute(rPeriod, "Towns." + stmp + ".Name"))
		rTown.name = rPeriod.Towns.(stmp).Name;
	else
	{
		switch (stmp) {
			case "Conceicao":           rTown.name = "Sao Jorge";         break;
			case "Douwesen":            rTown.name = "Kralendijk";        break;
			case "Falaise de Fleur":    rTown.name = "St Pierre";         break;
			case "Isla Muelle":         rTown.name = "San Juan";          break;
			case "Oxbay":               rTown.name = "Speightstown";      break;
			case "Greenford":           rTown.name = "Bridgetown";        break;
			case "Redmond":             rTown.name = "Port Royale";       break;
			case "Quebradas Costillas": rTown.name = "Pirate Settlement"; break;
			case "Tortuga":             rTown.name = "La Tortue";         break;
			case "Eleuthera":           rTown.name = "Governor's Harbor"; break;
			case "Alice":               rTown.name = "Alice Town";        break;
			case "Khael Roa":           rTown.name = "Cozumel";           break;
			// default:
			                            rTown.name = stmp;
		}
	}
	if (CheckAttribute(rPeriod, "Towns." + stmp + ".nation")) {
		iNation = sti(rPeriod.Towns.(stmp).nation);
		if (GetTownNation(stmp) != iNation) {
			rTown.do_firstinit = true;
			CaptureTownForNation(stmp, iNation);
			DeleteAttribute(rTown, "do_firstinit");
			rTown.homeland = iNation;
		}
	}
	string IslandID = rTown.island;
	if(IsIslandDisabled(IslandID))	rTown.skiptrade = true;	// PB

	if (CheckAttribute(rPeriod, "Towns." + stmp + ".gov")) {
		chr = GetTownGovernor(stmp);
		makearef(archr, rPeriod.Towns.(stmp).gov);
		if (CheckAttribute(archr, "name")) {
			chr.old.name = archr.name;
		//	chr.name = TranslateString("", chr.old.name);
			chr.name = GetTranslatedPeriod(chr.old.name);
		}
		if (CheckAttribute(archr, "middlename")) {
			chr.old.middlename = archr.middlename;
		//	chr.middlename = TranslateString("", chr.old.middlename);
			chr.middlename = GetTranslatedPeriod(chr.old.middlename);
		} else {
			if (CheckAttribute(chr, "middlename")) DeleteAttribute(chr, "middlename");
		}
		if (CheckAttribute(archr, "nickname")) {
			chr.old.nickname = archr.nickname;
		//	chr.nickname = TranslateString("", chr.old.nickname);
			chr.nickname = GetTranslatedPeriod(chr.old.nickname);
		} else {
			if (CheckAttribute(chr, "nickname")) DeleteAttribute(chr, "nickname");
		}
		if (CheckAttribute(archr, "lastname")) {
			chr.old.lastname = archr.lastname;
		//	chr.lastname = TranslateString("", chr.old.lastname);
			chr.lastname = GetTranslatedPeriod(chr.old.lastname);
		}
		if (CheckAttribute(archr, "sex")) chr.sex = archr.sex;
		if (CheckAttribute(archr, "model")) SetModelFromID(chr, archr.model);
		if (CheckAttribute(archr, "greeting")) chr.greeting = archr.greeting;
	}

	n++;
}
// <-- KK

//MAXIMUS -->
string FindTownStore(string townID)//townID = GetTownIDFromLocID(PChar.location)
{
	if(!TownExist(townID)) return "";
	string island = GetIslandIDFromTown(townID);
	if (island == "") return "";
	int nbegin = sti(Locations[0].IslandsList.(island).begin);
	int nend = sti(Locations[0].IslandsList.(island).end);
	for(int n = nbegin; n < nend; n++)
	{
		if(!CheckAttribute(Locations[n], "type") || !CheckAttribute(Locations[n], "townsack")) continue;
		if(HasSubStr(Locations[n].id,"store") && !HasSubStr(Locations[n].id,"tailor") && Locations[n].type == "shop" && Locations[n].townsack == townID) return Locations[n].id;
	}
	return "";
}
//MAXIMUS <--
