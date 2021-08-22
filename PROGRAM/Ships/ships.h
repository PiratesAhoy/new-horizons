int SHIP_TYPES_QUANTITY		= 0;
#define SHIP_TYPES_QUANTITY_WITH_FORT		514
#define NOSKIP_CHANCE_WRONGNATION 0.2 // NK
#define NOSKIP_CHANCE_WRONGNATION_PIRATE 0.4 // NK
#define MAX_CLASS 1 // NK this and below, just so it's not hard coded in the funcs.
#define MIN_CLASS 8
#define DEFAULT_CLOSESTPOINT	0.3
#define DEFAULT_BESTPOINT		0.8
#define SHIP_CURSED				164	// Fudge Dragon: Re-enable skeletons

// PS ship defs and ints cut

int SHIP_BOAT = 0;
int SHIP_FORT	= 0;

#define SHIP_NOTUSED	        1000
#define SHIP_NOTUSED_TYPE_NAME  "Not Used"
#define SHIP_NAME_NOTUSED		"Noname"

#define SHIP_FORT_NAME "Fort"
#define SHIP_BOAT_NAME "Boat"
#define SHIP_LIFEBOAT  "Tartane50"

object  ShipsTypes[SHIP_TYPES_QUANTITY_WITH_FORT];
object ShipLookupTable;

object ShipModels; // KK

ref GetShipByType(int iType)
{
	// Swindler 2006-07-10 -->
	// Added check for valid index. If index is out of range, first shiptype in
	// array will be returned.
	if (iType >= SHIP_TYPES_QUANTITY_WITH_FORT || iType < 0)
	{
		traceif(">>> SWINDLER TRACE: ShipType " + iType + " doesn't exist!");
		return &ShipsTypes[0];
	}
	// Swindler <--
	return &ShipsTypes[iType];
}

// PS -->

ref GetShipByID(string id)
{
	// Swindler 2006-07-10 -->
	// Calls function GetShipByType(int iType), which does a check for valid
	// index, instead of accessing global ShipsTypes-Array directly
	return GetShipByType(GetShipIndex(id));
	// Swindler <--
}

int GetShipIndex(string id)
{
	if (id == SHIP_NOTUSED_TYPE_NAME)
		return SHIP_NOTUSED;
	if (id == SHIP_FORT_NAME)
		return SHIP_FORT;
	if (id == SHIP_BOAT_NAME)
		return SHIP_BOAT;
	// NK 04-09-08
	// Old findship code commented out, now using NativeFindCharacter...
	/*if(CheckAttribute(ShipLookupTable,"id."+id) && ShipsTypes[sti(ShipLookupTable.id.(id))].id == id) return sti(ShipLookupTable.id.(id));
	int n;
	int place = -1;
	for(n=0;n<SHIP_TYPES_QUANTITY;n++)
	{
		if(!CheckAttribute(ShipsTypes[n],"id") || ShipsTypes[n].id == "blank") continue;
		if(id == ShipsTypes[n].id) { place = n; break; }
	}
	if(place != -1) { ShipLookupTable.id.(id) = place; return place; }
	return SHIP_NOTUSED;*/
	return NativeFindCharacter(&ShipsTypes, id);
}

string GetShipID(int idx)
{
	if(idx >=0 && idx < SHIP_TYPES_QUANTITY_WITH_FORT) { return ShipsTypes[idx].id; }
	return SHIP_NOTUSED_TYPE_NAME;
}

// PS funcs moved to ships.c

// PS <--


// PRS3 -->
//nation-specific ship stat multipliers
#define SHIPSTAT_VARIANCE 0.03 //i.e. actual multiplier stat will vary by +/- rand(this amount)

object shipstatsmult; //nation-specific stat modifiers. Modifier is a float multiplier for the stat. Values assigned in ships_init.c so they can be reinit'd.

// PRS3 <--
