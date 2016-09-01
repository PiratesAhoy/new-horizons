// 05-07-04
// TownFantoms section:
object TownFantomBehaviors;
#define DEFAULT_BEHAVIOR "MaleCitizen_Rel0"
#define CHANCE_TO_BE_IN_NEAR_LOC_OUTSIDE 0.25
#define CHANCE_TO_BE_IN_NEAR_LOC_INSIDE 0.01

#define MAX_TOWN_FANTOMS 32

extern void InitBehaviors();
float posX, posY, posZ;

int FindFreeTownFantomSlot(string sTownName)
{
	ref town = GetTownFromID(sTownName);
	if(!CheckAttribute(town, "fantoms")) return 0;
	for(int i = 0; i < MAX_TOWN_FANTOMS; i++)
	{
		if(!CheckAttribute(town, "fantoms.townfantom"+i)) return i;
	}
	return -1;
}
// adds fantom to town, with home house, behavior of type citizentype, model of type modeltype, and chance of changing changechance
bool AddTownFantom(string sTownName, string house, string behav_name, string modeltype, float changechance)
{
	// get town, check if free slot
	ref town = GetTownFromID(sTownName);
	int curnum = FindFreeTownFantomSlot(sTownName);
	if(curnum == -1) return false;

	// base vars
	int i;
	string stmp;

	// start actual gen
	ref loc = &Locations[FindLocation(house)];
	aref curfnt;
	string fntid = "townfantom"+curnum;
	behav_name = DEFAULT_BEHAVIOR; // for now
	town.fantoms.(fntid) = "";
	makearef(curfnt, town.fantoms.(fntid));
	
	// ++ basic info ++
	curfnt.modeltype = modeltype;
	curfnt.house = house;
	curfnt.behavior = behav_name;

	// ++ change-over-time params ++
	curfnt.date.year = GetDataYear();
	curfnt.date.month = GetDataMonth();
	curfnt.date.day = GetDataDay();
	curfnt.date.changechance = changechance;

	// ++ behavior parameters ++

	// +schedule+
	aref basebeh, schedule, tempfrom, tempto;
	makearef(basebeh, TownFantomBehaviors.(behav_name)); // get base behavior template
	curfnt.schedule = ""; makearef(schedule, curfnt.schedule); // make local reference to this townfantom's schedule
	string localplace;
	int localnum = 0;

	// copy over the schedule locations from the temp object, using only those with real locations (and re-ordering otherwise)
	for(i = 0; i < sti(basebeh.qty); i++)
	{
		stmp = "l"+i;
		string curloc = "";
		if(CheckAttribute(basebeh, stmp+".loc")) curloc = basebeh.(stmp).loc;
		if(curloc == "Home") curloc = house; // if not specified, loc is assumed to be home, not none.
		else
		{
			if(CheckAttribute(town, "locations."+curloc))
			{
				if(isdigit(town.locations.(curloc))) // multiple versions of location. Bad to do it this way--permamently--rather than at char login time each time. But oh well.
				{
					string st2 = "loc"+rand(sti(town.locations.(curloc))-1);
					curloc = town.locations.(curloc).(st2);
				}
				else { curloc = town.locations.(curloc); }
			}
			else { if(curloc == "none" || curloc == "") { curloc = "none"; } // if no location, or "none", set to "none"
			else { curloc = ""; } } // else set to skip this entry
		}
		if(curloc != "")
		{
			localplace = "l"+localnum;
			schedule.(localplace) = basebeh.(stmp);
			makearef(tempto, schedule.(localplace)); makearef(tempfrom, basebeh.(stmp));
			CopyAttributes(&tempto, &tempfrom);
			tempto.loc = curloc; // overwrite with real loc
			localnum++;
		}
	}
	schedule.qty = localnum;
	return true;
}

void InitTownFantomBehaviors()
{
	if(LoadSegment("TownFantoms\TownFantoms_Behavior_init.c")) // NK do this with loadsegment
		{
			InitBehaviors();
			UnloadSegment("TownFantoms\TownFantoms_Behavior_init.c");
		}
}
