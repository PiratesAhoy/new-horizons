#include "models\models.h"

void SetModel(ref chr, string model, string ani, string sex, float height, bool LIActive) // touchup by NK -->
{
	chr.model = model;

// KK -->
	if (CheckAttribute(chr, "model.armorlevel") == true && FindFile(GetResourceDirectory() + "MODELS\Characters", "*.gm", model + "_A" + sti(chr.model.armorlevel) + ".gm") != "") {
		model += "_A" + sti(chr.model.armorlevel);
	}
// <-- KK

	if (ani == "") ani = DEFAULT_ANI;
	chr.model.animation = ani;

	if(sex == "") sex = DEFAULT_ANI;
	chr.sex = sex;

// KK -->
	if (height <= 0.0) {
		switch (sex) {
			case "man":   height = MAN_HEIGHT;     break;
			case "woman": height = WOMAN_HEIGHT;   break;
			              height = DEFAULT_HEIGHT;
		}
	}
	chr.model.height = height;
// <-- KK

	facemaker(chr);

	SendMessage(chr, "lss", MSG_CHARACTER_SETMODEL, model, chr.model.animation); // KK
	SendMessage(chr, "lsl", MSG_CHARACTER_EX_MSG, "SetSex", sex == "man" || sex == "woman" || sex == "skeleton"); // KK

	if (LIActive) BLI_UpdateOfficers(); // NK <--
	EquipCharacterByItem(chr, GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE)); // PB: To always show characters' weapons
}

// LDH --> total rewrite 19Sep06
void SetModelItem(ref chr, string oldarmor_unused)	// called only once in LAi_Utils.c
{
	SetModelArmor(chr);
}

void SetModelArmor(ref chr)
{
	if(!CheckAttribute(chr,"istailor"))
	{
		if(IsCharacterEquipByGroup(chr,ARMOR_ITEM_TYPE))
		{
			string armor = GetCharacterEquipByGroup(chr,ARMOR_ITEM_TYPE);
			RemoveCharacterEquip(chr, ARMOR_ITEM_TYPE);
			TakeItemFromCharacter(chr, armor);
			GiveItem2Character(chr, armor);
//				armor = FindCharacterItemByGroup(chr,ARMOR_ITEM_TYPE);	// LDH - intended to equip best armor, probably not needed
			EquipCharacterByItem(chr, armor);
		}
	}
	ExecuteCharacterEquip(chr);
}
// LDH <--

/*-- original code, keep around in case there's problems with new version
// All instances of "model" below should be "armor", "oldmodel" should be "oldarmor", reference to chr.model removed
// NK -->
// NK do this separately, so we can call it from CreateFantom() calls
void SetModelItem(ref chr, string oldmodel)
{
	string armor;
	string model = chr.model;
	if(!CheckAttribute(chr, "armoroverride")) // NK 05-04-13
	{
		//traceandlog("armoroverride not set, checking armor items");
		if(!CheckAttribute(chr,"istailor"))
		{
			if(IsCharacterEquipByGroup(chr,ARMOR_ITEM_TYPE))
			{
				if(CheckItem(oldmodel))	// LDH this test will never return true unless oldmodel is a valid item, not a character model
				{
					armor = GetCharacterEquipByGroup(chr,ARMOR_ITEM_TYPE);
					if(armor == oldmodel)
					{
						RemoveCharacterEquip(armor, ARMOR_ITEM_TYPE);	// LDH This can't work, function takes character ref, not string
//						RemoveCharacterEquip(chr, ARMOR_ITEM_TYPE);		// LDH probable intended code
						TakeItemFromCharacter(chr, armor);
					}
					else { TakeItemFromCharacter(chr, oldmodel); } // if char has that item but using different one.
				}
				armor = FindCharacterItemByGroup(chr,ARMOR_ITEM_TYPE);
				if(armor != "") EquipCharacterByItem(chr, armor);
			}
			if(CheckItem(model))		// LDH this test will never return true unless model is a valid item, not a character model
			{
				GiveItem2Character(chr, model);		// LDH this can't work, model is the character model, not an item
				// in case player currently has a better one, we disable this and refind best armor: EquipCharacterByItem(chr, model);
				armor = FindCharacterItemByGroup(chr,ARMOR_ITEM_TYPE);
				if(armor != "") EquipCharacterByItem(chr, armor);
				// for nonvis armor this needs to be disabled - EnableEquip(chr, ARMOR_ITEM_TYPE, false);
			}
		}
		ExecuteCharacterEquip(chr);
	}
}
*/

int GetModelIndex(string model)
{
	int i = NativeFindCharacter(&Models, model);
	if(i >= 0 && i < MAX_MODELS) return i;
	//trace("GetItemIndex: item " + id + " not found!");
	return -1;
}

// added 05-07-02
ref GetModel(int idx)
{
	ref model;
	if (idx >= 0 && idx < MODEL_HIGH) makeref(model, Models[idx]);
	return model;
}

// added 05-07-02
ref ModelFromID(string id)
{
	return GetModel(GetModelIndex(id));
}
// NK <--
//moved here 05-04-30 from tailor_dialog.c
void SetModelfromArray(ref refCharacter, int idx)
{
	ref Model = GetModel(idx);
	//DebugLog("SetModel : " + Models[idx].model);
	SetModel(refCharacter, Model.id, Model.ani, Model.sex, stf(Model.height), FindLoadedLocation() != -1); // Nk do bool this way 05-05-01
}

// NK added 05-07-02
bool SetModelFromID(ref chr, string id)
{
	int idx = GetModelIndex(id);
	if(idx < 0 || idx >= MODEL_HIGH) return false; // KK
	SetModelFromArray(&chr, idx);
	return true;
}

bool CheckItem(string ItemID)
{
	if(ItemID == "") return false;
	// NK 05-04-05 we can just use GetItemIndex != -1.
	/*ref itm;
	int n;
	bool ItemIsDefined;
	ItemIsDefined = false;
	//Trace("CheckItem: ----------------------------------")
	for(n=0; n<MAX_ITEMS; n++)
	{
		makeref(itm,Items[n]);
		//Trace("CheckItem: " + itm.id +" - "+ itemID)
		if(itm.id == ItemID)
		{
		  ItemIsDefined = true;
		  break;
		}
	}
	return ItemIsDefined;*/
	return GetItemIndex(ItemID) != -1;
	// NK <--
}

ref gGetNewCharacter(string Fullname)
{
	int i;
	ref Character;
	i = GetCharacterIndex(Fullname); if (i>=0 && i < MAX_CHARACTERS) return GetCharacter(i); // NK bugfix 04-09-21
	// NK 05-04-05 changed to max characters to not overwrite fantoms and boat char, use CHARACTERS_QUANTITY now -->
	for(i=CHARACTERS_QUANTITY; i<MAX_CHARACTERS; i++)
	{
		makeref(Character,Characters[i]);
		if(Character.id != "0") CHARACTERS_QUANTITY++; // then we aren't at the end.
		else break;
	}
	// NK <--
	return Character;
}

void SortModelArray(int intLowerPos, int intUpperPos)
{
	int intCenterValue;
	int intCenterPos;
	int i;

	ref MinModel;
	ref MaxModel;
	ref TmpModel;
	string stmp; // NK
	if (intLowerPos < intUpperPos)
	{
		makeref(MinModel,Models[intLowerPos]);
		//if(MinModel.id != MinModel.model) MinModel.id = MinModel.model; // NK 05-04-12 so we can use native finds.
		intCenterValue = sti(MinModel.nation);
		intCenterPos   = intLowerPos;
		for(i=intLowerPos+1;i<=intUpperPos;i++)
		{
			makeref(MinModel,Models[i]);
			//if(MinModel.id != MinModel.model) MinModel.id = MinModel.model; // NK 05-04-12 so we can use native finds.
			if (sti(MinModel.nation) < intCenterValue)
			{
				intCenterPos++;
				makeref(MinModel,Models[intCenterPos]);
				//if(MinModel.id != MinModel.model) MinModel.id = MinModel.model; // NK 05-04-12 so we can use native finds.
				makeref(MaxModel,Models[i]);
				//if(MaxModel.id != MaxModel.model) MaxModel.id = MaxModel.model; // NK 05-04-12 so we can use native finds.
				makeref(TmpModel,Models[MAX_MODELS-1]);
				//if(TmpModel.id != TmpModel.model) TmpModel.id = TmpModel.model; // NK 05-04-12 so we can use native finds.
				CopyAttributes(TmpModel,MinModel);
				CopyAttributes(MinModel,MaxModel);
				CopyAttributes(MaxModel,TmpModel);
			}
		}
		makeref(MinModel,Models[intLowerPos]);
		//if(MinModel.id != MinModel.model) MinModel.id = MinModel.model; // NK 05-04-12 so we can use native finds.
		makeref(MaxModel,Models[intCenterPos]);
		//if(MaxModel.id != MaxModel.model) MaxModel.id = MaxModel.model; // NK 05-04-12 so we can use native finds.
		makeref(TmpModel,Models[MAX_MODELS-1]);
		//if(TmpModel.id != TmpModel.model) TmpModel.id = TmpModel.model; // NK 05-04-12 so we can use native finds.
		CopyAttributes(TmpModel,MinModel);
		CopyAttributes(MinModel,MaxModel);
		CopyAttributes(MaxModel,TmpModel);
		SortModelArray(intLowerPos,intCenterPos-1);
		SortModelArray(intCenterPos+1,intUpperPos);
	}
}

// PB: Function completely rewritten and simplified -->
int GetRandomModelForNation(int Nation, int maxRank)
{
	ref pchar = GetMainCharacter();
	int intRandModel, l, n;
	int breakcounter = 0;
	string otype;
	if (Nation < -1 || Nation >= NATIONS_QUANTITY)						Nation = ALL_NATIONS;	// Safeguard for un-existing nation
	if (maxRank < 0)													maxRank = 0;			// Safeguard for negative rank

	bool Found = false;
	while(!Found)
	{
		intRandModel = rand(MODEL_HIGH);

		ref refModel;
		makeref(refModel,Models[intRandModel]);

		if (CheckAttribute(refModel, "period")) {
			otype = refModel.period;
			l = strlen(otype);
			for (n = 0; n < l; n++)
			{
				if (sti(GetSymbol(otype, n)) == GetCurrentPeriod())		Found = true;
			}
		}
		else															Found = true;
		if(sti(refModel.nation) != Nation)								Found = false;
		if(sti(refModel.nation) == ALL_NATIONS)							Found = true;
		if(sti(refModel.minrank)  > maxRank)							Found = false;
		if(sti(refModel.minlevel) > sti(pchar.rank))					Found = false;
		if(refModel.description == "")									Found = false;

		breakcounter++;
		if(breakcounter > 1000)
		{
			trace("ERROR - Tailor Shop no model found, returning: " + refModel.id);
			break;
		}
	}
	return intRandModel;
}
// PB: Function completely rewritten and simplified <--

// NK 05-07-02
// MODELTYPES

// ******* lookup and handling functions

// gets index for type 'id'
int GetModelTypeIndex(string id)
{
	return NativeFindCharacter(&ModelTypes, id);
}

// gets reference to type 'id'
ref GetModelType(string id)
{
	int idx = GetModelTypeIndex(id);
	if(idx == -1) return NullCharacter;
	return &ModelTypes[idx];
}

// gets reference to type 'id' if it exists, or creates it and returns it if not.
ref GetOrCreateModelType(string id)
{
	int idx = NativeFindCharacter(&ModelTypes, id);
	if(idx == -1)
	{
		idx = MODELTYPES_QUANTITY;
		MODELTYPES_QUANTITY++;
		ModelTypes[idx].id = id;
	}
	return &ModelTypes[idx];
}

// clears modeltype slot n directly, irrespective of where in the array it is
// please don't use this function directly; either use ClearModelTypeSlot() to delete a modeltype, or InitModelTypesArray() to start from scratch.
void ClearModelTypeSlotDirect(int n)
{
	ref modeltype; makeref(modeltype, ModelTypes[n]);
	DeleteAttribute(&modeltype, "");
	//DeleteAttribute(&modeltype, "types");
	modeltype.id = "blank";
	modeltype.index = n;
}

// use this to clear a slot instead. This will refill that slot, if it's not at the end of the array, with another nonblank slot, keeping all blank slots at the end of the array.
void ClearModelTypeSlot(int n)
{
	bool bdirect = MODELTYPES_QUANTITY <= 1;
	if(!bdirect)
	{
		if(n >= MODELTYPES_QUANTITY-1)
		{
			bdirect = true;
			MODELTYPES_QUANTITY = n; // assume there's nothing after this, even though we use >= above.
		}
	}

	if(bdirect)
	{
		ClearModelTypeSlotDirect(n);
		return;
	}
	DeleteAttribute(&ModelTypes[n], "");
	CopyAttributes(&ModelTypes[n], &ModelTypes[MODELTYPES_QUANTITY-1]);
	ModelTypes[n].index = n;
	ClearModelTypeSlotDirect(MODELTYPES_QUANTITY);
	MODELTYPES_QUANTITY--;
}

//*********** find model based on type code
// (the stuff that actually converts modeltype to a specific model)

// will get model from all_nations pool of any sex.
string GetRandomModelForType(int iscombat, string type)
{
	return GetRandomModelForTypeExSubCheck(iscombat, type, "", ALL_NATIONS);
}

// will get model from specific nation of any sex
string GetRandomModelForTypeNation(int iscombat, string type, int nat)
{
	return GetRandomModelForTypeExSubCheck(iscombat, type, "", nat);
}

// will get model from all_nations pool of specified sex
string GetRandomModelForTypeSex(int iscombat, string type, string sex)
{
	return GetRandomModelForTypeExSubCheck(iscombat, type, sex, ALL_NATIONS);
}

// checks to see if type is a subtype and if so will choose a master type based on it
string GetRandomModelForTypeExSubCheck(int iscombat, string type, string sex, int nat)
{
	//trace("Getting model for type " + type + ", sex " + sex +  ", " + GetNationNameByType(nat) + ", subtype check");
	if(!CheckAttribute(ModelSubTypes, type)) return GetRandomModelForTypeEx(iscombat, type, sex, nat);
	float randchance = frnd();
	aref base, cur;
	makearef(base, ModelSubTypes.(type));
	for(int i = 0; i < GetAttributesNum(base); i++)
	{
		cur = GetAttributeN(base, i);
		if(randchance < stf(GetAttributeValue(cur)))
		{
			//trace("rand was " + randchance + ", found type " + GetAttributeName(cur));
			//trace("Gauging: found correct subtype");
			return GetRandomModelForTypeEx(iscombat, GetAttributeName(cur), sex, nat);
		}
	}
	return GetRandomModelForTypeEx(iscombat, GetAttributeName(GetAttributeN(base, GetAttributesNum(base)-1)), sex, nat);
}

// explicit version. Checks for nation and sex. Note: please DO NOT pass this a precomputed type string (i.e. Rich_Citizens255, Sailors3,
// anything with both type and nation together); instead, pass both type and nation and this will automatically apply the nation for you.
// However, if it detects it has been passed such a string, it will not append nation to the end,  in the hope of it still working.
string GetRandomModelForTypeEx(int iscombat, string type, string sex, int nat)
{
	int idx, attrnum, breakcount, n, l;
	aref base, cur;
	ref modeltype, rModel;
	float chance;
	string otype, mID;
	bool bsexless = true;
	bool bclear = true;
	bool bskip = true;
	//trace("Actually getting model. Type is " + type);
	if(GetModelIndex(type) != -1) return type; // just in case someone passes us a model name, not a type. 05-07-08
	// this means that NO type name can match a model name and vice versa
	if(nat < -1 || nat >= NATIONS_QUANTITY) nat = ALL_NATIONS; // PB: Allow PERSONAL_NATION (=-1) too!
//	if(nat < 0  || nat >= NATIONS_QUANTITY) nat = ALL_NATIONS; // could be ==-1 but we want to catch all problems // KK
	if(isdigit(type, strlen(type)-1)) {
		// in case nation is already in the type
		// this is DANGEROUS because it means we can only have 10 nations, and you can't precombine ALL_NATIONS because it's three digits.
		otype = strcut(type, 0, strlen(type)-2);
	} else {
		otype = type;
		type += nat;
	}

	// check type exists
	idx = GetModelTypeIndex(type);
	if (idx == -1 && nat != ALL_NATIONS) { // if specific nation type not exist
		type = otype + ALL_NATIONS;
		idx = GetModelTypeIndex(type);
	}
	if (idx == -1) return DEFAULT_MODEL;
	makeref(modeltype, ModelTypes[idx]);

	// now check for models.
	// this should slow us down, but is needed for robustness...
	// maybe if it never gets triggered, we can skip it and assume all assigned types will have assigned models...
	// however we will always have to do the below sexcheck
	if(sex != "" && sex != "both" && CheckAttribute(modeltype, sex+".types")) { // just in case someone wants to say "both." If not found, or sex is "" or both, skip sex
		//trace("local sex " + sex + " found for type " + type);
		makearef(base, modeltype.(sex).types);
		attrnum = GetAttributesNum(base);
		if(attrnum > 0) {
			bsexless = false;
		} else {
			makearef(base, modeltype.types);
			DeleteAttribute(&modeltype, sex); // clear this sex portion so above if will fail next time.
		}
	}
	bclear = bsexless; // if bsexless is false from above, it means no need to clear.
	if (bsexless) {
		if (CheckAttribute(modeltype, "types")) {
			makearef(base, modeltype.types);
			attrnum = GetAttributesNum(base);
			if (attrnum > 0) bclear = false;
		}
	}
	if (bclear) {
		ClearModelTypeSlot(idx);
		return DEFAULT_MODEL;
	}
	//trace("Gauging: now starting loop");
	breakcount = 0;
	//trace("Looking......");
	while(breakcount < 1000) // just in case
	{
		breakcount++;
		cur = GetAttributeN(base, rand(attrnum-1));
		chance = stf(GetAttributeValue(cur));
		if(frnd() > chance) continue;
		mID = GetAttributeName(cur);
		makeref(rModel, Models[GetModelIndex(mID)]);
		if(iscombat != -1 && sti(rModel.iscombat) != iscombat) continue; // NK iscombat 05-07-27
// KK -->
		if (CheckAttribute(rModel, "period")) {
			bskip = true;
			otype = rModel.period;
			l = strlen(otype);
			for (n = 0; n < l; n++)
			{
				if (sti(GetSymbol(otype, n)) == GetCurrentPeriod()) {
					bskip = false;
					break;
				}
			}
			if (bskip) continue;
		}
// <-- KK
		//trace("found model! " + GetAttributeName(cur) + ". Type " + type + ", " + GetNationNamebyType(nat) + " " + sex);
		return mID;
	}
	return DEFAULT_MODEL;
}


// must NOT be passed precompiled type+nation!
// will get model for type, sex, and that does not exist for zeroed nations in natmask.
// Should take _way_ longer than the above single-nation version.
// --
// 05-07-19 addendum. Not yet used, and I don't feel like rewriting it to use the new ModelTypes[] array. So I'm commenting it out.
/*string GetRandomModelForTypeExMask(string type, string sex, string natmask)
{
	aref base, cur;
	float chance;
	string id = "";
	if(sex != "" && sex != "both") type = sex + "." + type; // just in case someone wants to say "both"
	if(natmask != "all" && natmask != GetNationStringAll() && natmask != GetNationStringAll() + "1") // do we really need to run this function?
	{
		if(!CheckAttribute(ShipLookupTable, "modeltypes."+type)) { return DEFAULT_MODEL; } // do a bit of the regular code. Continues below the else.
	}
	else { return GetRandomModelForTypeEx(type, sex, -1); } // if not, use the much faster single-nation version (see else, below)
	makearef(base, ShipLookupTable.modeltypes.(type));
	int breakcount = 0;
	int i;
	object skipmodels;
	while(breakcount < 1000) // just in case
	{
		breakcount++;
		cur = GetAttributeN(base, rand(GetAttributesNum(base)-1));
		chance = stf(GetAttributeValue(cur));
		id = GetAttributeName(cur);
		if(CheckAttribute(skipmodels, id)) continue; // so we don't have to recheck models we skipped before due to nationmask.
		if(frnd() > chance) continue;
		bool skip = false;
		for(i = 0; i < strlen(natmask)-1; i++) // skip the ALL_NATIONS place
		{
			if(GetSymbol(natmask, i) != "1")
			{
				if(CheckAttribute(ShipLookupTable, "modeltypes."+type+i+"."+id))
				{
					skip = true;
					break;
				}
			}
		}
		if(skip)
		{
			skipmodels.(id) = true;
			continue;
		}
		return id;
	}
	return DEFAULT_MODEL;
}*/

// ********* Functions to ease assignment of modeltypes

//simplest: assigns to type with chance chance, with no start or end date, and used by all nations.
void AssignModelType(bool dothis, ref model, string type, float chance)
{
	if(!dothis) return;
	AssignModelTypeEx(dothis, model, type, chance, -1, -1, "all");
}

// assigns to specific nation only. no start or end date. Pass ALL_NATIONS to assign to the general type but NOT
// specific nation types (should not be used this way, you should use NatMask with natmask "all")
void AssignModelTypeNation(bool dothis, ref model, string type, float chance, int nation)
{
	if(!dothis) return;
	AssignModelTypeExSingle(dothis, model, type, chance, -1, -1, nation);
}

// assigns to specified nations. Pass "all" as the natmask to assign to each individual nation and the allnations pool.
// to make life easier, you can use the GetNationStringXXX() functions in globals.c; note that if you do not add a 0
// after the GetNationStringXXX() call in your calling of this function, it will assume you are enabling the model for ALL_NATIONS too.
void AssignModelTypeNatMask(bool dothis, ref model, string type, float chance, string natmask)
{
	if(!dothis) return;
	int len = strlen(natmask);
	if( len <= NATIONS_QUANTITY)
	{
		for(int i = 0; i < NATIONS_QUANTITY - len; i++)
		{
			natmask += "0"; // set other nations to 0
		}
		natmask += "1"; // to add yes to ALL_NATIONS
	}
	AssignModelTypeEx(dothis, model, type, chance, -1, -1, natmask);
}

// assigns specified start and/or end year to all nations
void AssignModelTypeYear(bool dothis, ref model, string type, float chance, int starty, int endy)
{
	if(!dothis) return;
	AssignModelTypeEx(dothis, model, type, chance, starty, endy, "all");
}

// explicit version. Passed type, chance, start and end years, and natmask. Assigns model to nations specified by natmask,
// and ALL_NATIONS if last char of natmask is true. If natmask is "all" will assign to all nations individually and ALL_NATIONS general pool.
void AssignModelTypeEx(bool dothis, ref model, string type, float chance, int startyear, int endyear, string natmask)
{
	if (!dothis) return;
	aref cur;
	int i;
	if(natmask == "all") natmask = GetNationStringAll() + "1"; // special handling for ALL_NATIONS
	if(GetSymbol(natmask, strlen(natmask)-1) == "1") // same
		AssignModelTypeExSingle(dothis, model, type, chance, startyear, endyear, ALL_NATIONS);
	for (i = 0; i < strlen(natmask) - 1; i++)
	{
		if (GetSymbol(natmask, i) == "1")
		{
			if (i == PIRATE) // I hate special cases, but better to do it here...
				AssignModelTypeExSingle(dothis, model, type, chance * CHANCEMULT_PIRATENATION_GENERICMODEL, startyear, endyear, i);
			else
				AssignModelTypeExSingle(dothis, model, type, chance, startyear, endyear, i);
		}
	}
}
// really explicit version. Actually does the assignment. Usually called from AssignModelTypeEx(), unless you want to assign to only one nation. Even then you'd probably use an implicit version.
void AssignModelTypeExSingle(bool dothis, ref model, string type, float chance, int startyear, int endyear, int nation)
{
	if(!dothis) return;
	int cy = GetDataYear();
	bool storeit = true;
	string ctype = type + nation;
	if (cy > 0) { // KK
		if (startyear != -1 && startyear > cy) storeit = false;
		if (storeit && endyear != -1 && endyear < cy) storeit = false;
	}
	string modelid = model.id;
	//if(modelid == "blank") modelid = model.model;
	string msex = model.sex;
	ref modeltype = GetOrCreateModelType(ctype);
	if(storeit)
	{
		modeltype.types.(modelid) = chance;
		modeltype.(msex).types.(modelid) = chance;
	}
	else
	{
		DeleteAttribute(&modeltype, "types."+modelid);
		DeleteAttribute(&modeltype, msex+".types."+modelid);
	}
	model.types.(type) = true; // for reverse lookup.
}

// returns true if model with id 'model' is a part of type 'type'
bool ModelIsType(string model, string type)
{
	ref mdl = &Models[GetModelindex(model)];
	return CheckAttribute(mdl, "types."+type);
}

// finds the types that model 'model' is assigned to. Since there can be more than one, it also has an index. Usually passing a num of 0 is what you want to do...
string FindModelTypeFromModel(string model, int num)
{
	if(GetModelindex(model) == -1)    return ""; // PB: In case this gets called for a model that isn't defined
	ref mdl; makeref(mdl, Models[GetModelindex(model)]);
	if(!CheckAttribute(mdl, "types")) return "";
	aref mdltypes; makearef(mdltypes, mdl.types);
	int numa = GetAttributesNum(mdltypes);
	if(num >= numa) num = numa-1;
	return GetAttributeName(GetAttributeN(mdltypes, num));
}
// NK <--

// PB -->
string FindRandomModelOfficerType(string model)
{
	string type = OFFIC_TYPE_CIVILIAN; // Define default NPC type

	int num = 0;
	string validTypes = "";

	string curType = "";
	string nexType = FindModelTypeFromModel(model, num);

	while (num == 0 || curType != nexType)
	{
		if(UsableOfficerType(nexType, false))	validTypes = StoreString(validTypes, nexType);

		num++;
		curType = nexType;
		nexType = FindModelTypeFromModel(model, num);
	}
	if (validTypes != "") {
		type = GetRandSubString(validTypes);
	}

	return type;
}
// PB <--

// KK -->
void InitCharacterModel(ref model)
{
	if (!CheckAttribute(model, "model")) model.model = DEFAULT_MODEL;
	if (!CheckAttribute(model, "FaceId")) model.FaceId = DEFAULT_FACEID;
	if (!CheckAttribute(model, "assigned")) model.assigned = false;
	if (!CheckAttribute(model, "description")) model.description = "";
	if (!CheckAttribute(model, "minlevel")) model.minlevel = 0;
	if (!CheckAttribute(model, "minrank")) model.minrank = 0;
	if (!CheckAttribute(model, "nation")) model.nation = ALL_NATIONS;
	if (!CheckAttribute(model, "price")) model.price = 10;
	if (!CheckAttribute(model, "sex")) model.sex = "man";
	if (!CheckAttribute(model, "ani")) model.ani = "man";
	if (!CheckAttribute(model, "height")) model.height = 1.8;
	if (!CheckAttribute(model, "iscombat")) model.iscombat = true;
	if (CheckAttribute(model, "id")) {
		if (model.id != "blank" && model.model != DEFAULT_MODEL)
			model.id = model.model; // just in case someone defines model.model and not model.id
		else
			model.model = model.id;
	}
}

void AddCharacterModel(ref model)
{
	int mdidx;
	ref md;
	if (!CheckAttribute(model, "id")) return;
	mdidx = GetModelIndex(model.id);
//trace("modelid="+model.id+", mdidx="+mdidx);
	if (mdidx >= 0) {
		makeref(md, Models[mdidx]);
	} else {
		makeref(md, Models[MODEL_HIGH]);
		mdidx = MODEL_HIGH;
		MODEL_HIGH++;
	}
	DeleteAttribute(md, "");
	CopyAttributes(md, model);
	md.index = mdidx;
	InitCharacterModel(md);
	DeleteAttribute(model, "");
	InitCharacterModel(model);
}
// <-- KK
