void SetupNPCName(ref ch, string firstN, string secondN)
{
ch.old.name = firstN;
ch.old.lastname = secondN;
ch.name = TranslateString("", firstN);
ch.lastname = TranslateString("", secondN);
}
void LocatorReloadEnterDisable(string _locationID, string _locator, bool _flag)
{
aref arDis, arRld;
makearef(arRld, Locations[FindLocation(_locationID)].reload);
int	Qty = GetAttributesNum(arRld);
for(int i=0; i<Qty; i++)
{
arDis = GetAttributeN(arRld, i);
if(arDis.name == _locator)
{
if(_flag)arDis.disable = true;
else DeleteAttribute(arDis, "disable");
break;
}
}
}
/////////////////////// ==> Items-методы
ref ItemsFromID(string _Items)
{
return &items[GetItemIndex(_Items)];
}
int GetQuestPastTimeParam(string _quest)
{
aref arQ;
makearef(arQ, PChar.(_quest));
if(CheckAttribute(PChar, _quest + ".control_year"))
{
return GetPastTime("hour", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
} 
return 0;
}
int GetCharacterbyLocation(string location, string group, string locator)
{
ref sld;
for(int i=0;i<MAX_CHARACTERS;i++)
{
sld = &characters[i];
if (sld.location == location && sld.location.group == group && sld.location.locator == locator) return i;
}
return -1;
}
string LAi_FindFreeRandomLocator(string group)
{
	if(IsEntity(&loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at)== 0)return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0)return "";
	int base = rand(num - 1);
	for(int i = 0; i < num; i++)
	{
	int index = base + i;
	if(index >= num)
	{
	index = index - num;
	}
	aref loc = GetAttributeN(grp, index);
	//Boyer change #20170318-38
	if(!CheckAttribute(loc, "x"))
 continue;
	float lx = stf(loc.x);
	float ly = stf(loc.y);
	float lz = stf(loc.z);
	if(CheckLocationPosition(loadedLocation, lx, ly, lz))
	{
	return GetAttributeName(GetAttributeN(grp, index));
	}
	}
	return "";
}