bool IsQuestUsedItem(string itmID)
{
	aref arItm;
	if( Items_FindItem(itmID,&arItm)<0 ) return false;
	if( CheckAttribute(arItm,"price") && sti(arItm.price)>0 ) return false;
	return true;
}

// KK -->
bool IsTradeItem(string itmID)
{
	aref arItm;
	if (Items_FindItem(itmID, &arItm) < 0) return false;
	if (CheckAttribute(arItm, "skiptrade") == true && sti(arItm.skiptrade) == true) return false;
	return true;
}
// <-- KK

void DoCharacterUsedItem(ref chref, string itmID)
{
	aref arItm;
	if( Items_FindItem(itmID,&arItm)<0 ) return;
	if(arItm.id == "myrrh")
	{
		//JRH
		if(chref.location == "BB_burning_cave")
		{
			TakeItemFromCharacter(chref,itmID);
		}
		else
		{
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Log_SetStringToLog(TranslateString("","No, I'll save that to later"));
			return;
		}
	}
	else TakeItemFromCharacter(chref,itmID);

	if( CheckAttribute(arItm,"potion.health") )
	{
		LAi_UseHealthBottle(chref,stf(arItm.potion.health));
		if(sti(chref.index)==GetMainCharacterIndex()) 
		{
			Log_SetStringToLog(TranslateString("","Health Up"));
		}
	}
	if( CheckAttribute(arItm,"potion.antidote") )
	{
		LAi_UseAtidoteBottle(chref);
		if(sti(chref.index)==GetMainCharacterIndex()) 
		{
			Log_SetStringToLog(TranslateString("","You are cured from poison"));
		}
	}

	if(sti(chref.index)==GetMainCharacterIndex())
	{
		if( CheckAttribute(arItm,"potion.sound") ) PlaySound(arItm.potion.sound);	//JRH, sounds in initItems.c

		if( USE_PARTICLES>2 && GetAttribute(arItm,"id") == "medical2")
		{
			LAi_QuestDelay("cauterization_smoke", 0.1);
			LAi_QuestDelay("cauterization_sound", 1.0);
		}
	}
	
	if(arItm.id == "opium")
	{
		UseOpium(chref);
	}
	
	if(arItm.id == "vegetal")
	{
		UseVegetal(chref);
	}
}
//NK - 04-09-08 brand new, for finding _max_
float MaxHealthPotionForCharacter(ref chref, ref idx)
{
	float ftmp;
	bool isFinded = false;
	idx = -1;
	aref chritems; makearef(chritems, chref.items);
	int n;
	for(int i = 0; i < GetAttributesNum(chritems); i++)
	{
		if(sti(GetAttributeValue(GetAttributeN(chritems, i))) > 0)
		{
			n = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
			if(CheckAttribute(&Items[n],"potion"))
			{
				if(CheckAttribute(&Items[n],"potion.health") && stf(Items[n].potion.health)>0)
				{
					if(isFinded)
					{
						if( stf(Items[n].potion.health)>ftmp )
						{
							ftmp = stf(Items[n].potion.health);
							idx = n;
						}
					}else{
						ftmp = stf(Items[n].potion.health);
						isFinded = true;
						idx = n;
					}
				}
			}
		}
	}
	if(!isFinded) return 0.0;
	return ftmp;
}


// NK 04-09-08 rewrite for speed to search chref.items and match to array rather than vice versa. -->
float MinHealthPotionForCharacter(ref chref, ref idx)
{
	float ftmp;
	bool isFinded = false;
	idx = -1;
	aref chritems; makearef(chritems, chref.items);
	int n;
	for(int i = 0; i < GetAttributesNum(chritems); i++)
	{
		if(sti(GetAttributeValue(GetAttributeN(chritems, i))) > 0)
		{
			n = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
			if(n >= 0 && CheckAttribute(&Items[n],"potion"))	// LDH fix for negative index
			{
				if(CheckAttribute(&Items[n],"potion.health") && stf(Items[n].potion.health)>0)
				{
					if(isFinded)
					{
						if( stf(Items[n].potion.health)<ftmp )
						{
							ftmp = stf(Items[n].potion.health);
							idx = n; // NK
						}
					}else{
						ftmp = stf(Items[n].potion.health);
						isFinded = true;
						idx = n; // NK
					}
				}
			}
		}
	}
	if(!isFinded) return 0.0;
	return ftmp;
}

//Levis:
string FindAntidoteForCharacter(ref chref)
{
	string sret = "";
	aref chritems; makearef(chritems, chref.items);
	int n;
	for(int i = 0; i < GetAttributesNum(chritems); i++)
	{
		if(sti(GetAttributeValue(GetAttributeN(chritems, i))) > 0)
		{
			n = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
			if(CheckAttribute(&Items[n],"potion"))
			{
				if(CheckAttribute(&Items[n],"potion.antidote"))
				{
					//TODO: Make it check which antidote is best etc but let's start with this.
					sret = Items[n].id;
				}
			}
		}
	}
	return sret;
}

string FindHealthForCharacter(ref chref,float fHealth)
{
	string sret = "";
	float fdelta = fHealth + 100.0;
	float ftmp;

	aref chritems; makearef(chritems, chref.items);
	int n;
	for(int i = 0; i < GetAttributesNum(chritems); i++)
	{
		if(sti(GetAttributeValue(GetAttributeN(chritems, i))) > 0)
		{
			n = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
			if(CheckAttribute(&Items[n],"potion"))
			{
				if(CheckAttribute(&Items[n],"potion.health"))
				{
					ftmp = stf(Items[n].potion.health);
					if( ftmp<fHealth )	{ftmp = fHealth - ftmp;}
					else	{ftmp = ftmp - fHealth;}
					if(ftmp<fdelta)
					{
						fdelta = ftmp;
						sret = Items[n].id;
					}
				}
			}
		}
	}
	return sret;
}

int FindPotionFromChr(ref chref, ref arFind, int startIdx)
{
	aref chritems; makearef(chritems, chref.items);
	int n;
	for(int i = startIdx; i < GetAttributesNum(chritems); i++) //we start at attribute startIdx
	{
		if(sti(GetAttributeValue(GetAttributeN(chritems, i))) > 0)
		{
			n = GetItemIndex(GetAttributeName(GetAttributeN(chritems, i)));
			if(n < 0) return -1; // PB: Prevent crashes
			if(CheckAttribute(&Items[n],"potion"))
			{
				makearef(arFind, Items[n]);
				return i; //return current attribute number
			}
		}
	}
	return -1;
}
// NK <--

int FindQuestUsableItem(ref arFind, int startIdx)
{
	int i;
	aref arItm;
	bool bSeaInterface = bSeaActive && !bAbordageStarted;

	if(startIdx<0) startIdx=0;
	for(i=startIdx; i<ITEMS_QUANTITY; i++)
	{
		makearef(arItm,Items[i]);
		if( CheckAttribute(arItm,"quest") )
		{
			if( bSeaInterface && arItm.quest.tex=="QuestCommands" )
			{
				arFind = arItm;
				return i;
			}
		}
	}

	return -1;
}

bool EnablePotionUsing(ref mc, aref arItm)
{
	bool bEnableUse = false;
	if( CheckAttribute(arItm,"potion.health") && stf(arItm.potion.health) > 0) {
		if( LAi_GetCharacterHP(mc)<LAi_GetCharacterMaxHP(mc) ) {
			return true;
		}
	}
	if( CheckAttribute(arItm,"potion.antidote") ) {
		if( LAi_IsPoison(mc) || LAi_IsCurare(mc)) {
			return true;
		}
	}
	return false;
	
	//JRH curare
}

// NK -->
string GetItemBonuses(string id)
{
	aref itm;
	string tempstr = "";
	if(Items_FindItem(id, &itm) < 0)
	{
		//trace("GIB: id " + id + " not found");
		return tempstr;
	}
	if(!CheckAttribute(itm,"skill"))
	{
		//trace("GIB: id " + id + " has no skillch");
		return tempstr;
	}
	if(CheckAttribute(itm,"skill.hidden"))
	{
		if(sti(itm.skill.hidden))
		{
			//trace("GIB: id " + id + " hides skillch");
			return tempstr;
		}
	}
	tempstr = "(";
	string skillName = "";
	bool comma = false;
	for(int i = 0; i < 10; i++)
	{
		skillName = GetSkillName(i);
		if(CheckAttribute(itm,"skill."+skillName))
		{
			if(comma) tempstr += ", ";
			comma = true;
			if(CheckAttribute(itm,"skill."+skillName+".set")) { tempstr += itm.skill.(skillName).set + " " + XI_ConvertString(skillName); continue; }
			if(sti(itm.skill.(skillName)) > 0) { tempstr += "+" + itm.skill.(skillName) + " " + XI_ConvertString(skillName);}
			else { tempstr += itm.skill.(skillName) + " " + XI_ConvertString(skillName); }
		}
	}
	if(CheckAttribute(itm,"skill.num")) { if(sti(itm.skill.num)>1) { tempstr += "; " + XI_ConvertString("rrequired") + " " + itm.skill.num + " " + XI_ConvertString("required"); } }
	tempstr += ")";
	//trace("GIB: id " + id + " add desc: " + tempstr);
	if(tempstr != "()") return tempstr;
	return ""
}
// NK <--

void swapBlades(int i, int j)
{
	ref elemI, elemJ, elemTemp;
	object objTemp;

	makeref(elemI, BladeItems[i]);
	makeref(elemJ, BladeItems[j]);
	makeref(elemTemp, objTemp);
	CopyAttributes(elemTemp, elemJ);
	CopyAttributes(elemJ, elemI);
	CopyAttributes(elemI, elemTemp);
}

int compareBlades(int i, int j, string sortAttr1, string sortAttr2)
{
	int test1, test2;
	if (sortAttr2 == "")
	{
		test1 = sti(BladeItems[i].(sortAttr1));
		test2 = sti(BladeItems[j].(sortAttr1));
	}
	else
	{
		int temp = iretMax(sti(BladeItems[i].(sortAttr2)), sti(BladeItems[j].(sortAttr2)));
		int highorder = 100;
		while (highorder < temp) highorder *= 10;	// in case sortAttr2 is price or some other high value
		test1 = sti(BladeItems[i].(sortAttr1))*highorder + sti(BladeItems[i].(sortAttr2));
		test2 = sti(BladeItems[j].(sortAttr1))*highorder + sti(BladeItems[j].(sortAttr2));
	}
	if (test1 > test2) return 1;
	if (test1 < test2) return -1;
	return 0;
}

// LDH sort by sortAttr1, then sortAttr2 within sortAttr1 using standard quicksort - 09May09
// normally this will be minlevel and max damage but can be any two integer attributes and sortAttr2 can be ""
// if we could pass a reference to an array, we could make this generic for all arrays
void SortBladeArray(int low, int high, string sortAttr1, string sortAttr2)
{
	int i, mid;
	if (low >= high) return;

	swapBlades(low, (low+high)/2);	// odd that the other quicksort functions don't do this, it's standard quicksort processing
	mid = low;
	for ( i=low+1 ; i<=high ; i++ )
	{
		if (compareBlades(i, low, sortAttr1, sortAttr2) < 0)
		{
			mid++;
			swapBlades(mid, i);
		}
	}
	swapBlades(low, mid);
	SortBladeArray(low, mid-1, sortAttr1, sortAttr2);
	SortBladeArray(mid+1, high, sortAttr1, sortAttr2);
}

void SortGunArray(int intLowerPos, int intUpperPos)
{
    int intCenterValue;
    int intCenterPos;
    int i;

    ref MinGun;
    ref MaxGun;
    ref TmpGun;
    if (intLowerPos < intUpperPos)
    {
        makeref(MinGun,GunItems[intLowerPos]);
        intCenterValue = MinGun.minLevel;
        intCenterPos   = intLowerPos;
        for(i=intLowerPos+1;i<=intUpperPos;i++)
        {
            makeref(MinGun,GunItems[i]);
            if (MinGun.minLevel < intCenterValue)
            {
                intCenterPos++;
                makeref(MinGun,GunItems[intCenterPos]);
                makeref(MaxGun,GunItems[i]);
                makeref(TmpGun,GunItems[MAX_GUNS-1]);
                CopyAttributes(TmpGun,MinGun);
                CopyAttributes(MinGun,MaxGun);
                CopyAttributes(MaxGun,TmpGun);
            }
        }
        makeref(MinGun,GunItems[intLowerPos]);
        makeref(MaxGun,GunItems[intCenterPos]);
        makeref(TmpGun,GunItems[MAX_GUNS-1]);
        CopyAttributes(TmpGun,MinGun);
        CopyAttributes(MinGun,MaxGun);
        CopyAttributes(MaxGun,TmpGun);
        SortGunArray(intLowerPos,intCenterPos-1);
        SortGunArray(intCenterPos+1,intUpperPos);
    }
}




int GetFirstBladeForLevel(int intLevel)
{
	//traceandlog("Getting first blade for level " + intLevel);
    int intLowerPos = 0;
    int intUpperPos = BLADE_HIGH;
    int intBladePos = -1;
    int intBladeLevel;
    int intTargetLevel;
    int i;
	int temp = 0; // NK tempfix

    ref refBlade;

    if (intLevel < 0)
    {
        intTargetLevel = 0;
    }
    else
    {
        intTargetLevel = intLevel;
    }
    intBladePos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
	// NK reload debug
//	trace("GetFirstBladeForLevel startpos " + intBladePos);
    makeref(refBlade,BladeItems[intBladePos]);
    intBladeLevel = refBlade.minLevel;
    while(intBladeLevel != intTargetLevel && intLowerPos < intUpperPos)
    {
		//counter++; if(counter > 30) break; // NK
		// NK reload debug
//	trace("GetFirstBladeForLevel first while loop, gp" + intBladePos + ", level " + intBladeLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
        if (intBladeLevel > intTargetLevel)
        {
            intUpperPos = intBladePos;
        }
        else
        {
            intLowerPos = intBladePos;
        }
		temp = intBladePos; // NK
        intBladePos = intLowerPos + makeint(makefloat(intUpperPos - intLowerPos) /2.0);
		if(temp == intBladePos) break; // NK
        makeref(refBlade,BladeItems[intBladePos]);
        intBladeLevel = refBlade.minLevel;
    }
	//counter = 0;
    if (intBladeLevel == intTargetLevel)
    {
        while (intBladeLevel == intTargetLevel && intBladePos > 0)
        {
			//counter++; if(counter > 30) break; // NK
		// NK reload debug
//	trace("GetFirstBladeForLevel second while loop, gp" + intBladePos + ", level " + intBladeLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
            intBladePos--;
            makeref(refBlade,BladeItems[intBladePos]);
            intBladeLevel = refBlade.minLevel;
        }
        intBladePos++;
    }
    if (intBladePos < 0)
    {
        intBladePos = 0;
    }
	//traceandlog("First blade is " + intBladePos + ", " + BladeItems[intBladePos].id + " of qual " + BladeItems[intBladePos].BladeQuality);
    return intBladePos;
}

int GetLastBladeForLevel(int intLevel)
{
	//traceandlog("Getting last blade for level " + intLevel);
    int intLowerPos = 0;
    int intUpperPos = BLADE_HIGH;
    int intBladePos = 0;
    int intBladeLevel;
    int intTargetLevel;
    int i;
	int temp = 0; // NK tempfix

    ref refBlade;

    if (intLevel > GetBladeMaxLevel())
    {
        intTargetLevel = GetBladeMaxLevel();
    }
    else
    {
        intTargetLevel = intLevel;
    }
    intBladePos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
	// NK reload debug
//	trace("GetLastBladeForLevel startpos " + intBladePos);
    makeref(refBlade,BladeItems[intBladePos]);
    intBladeLevel = refBlade.minLevel;
    while(intBladeLevel != intTargetLevel && intLowerPos < intUpperPos)
    {
		//counter++; if(counter > 30) break; // NK
	// NK reload debug
//	trace("GetLastBladeForLevel first while loop, gp" + intBladePos + ", level " + intBladeLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
        if (intBladeLevel > intTargetLevel)
        {
            intUpperPos = intBladePos;
        }
        else
        {
            intLowerPos = intBladePos;
        }
		temp = intBladePos;
        intBladePos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
		if(temp == intBladePos) break; // NK
        makeref(refBlade,BladeItems[intBladePos]);
        intBladeLevel = refBlade.minLevel;
    }
	//counter = 0; // NK
    if (intBladeLevel == intTargetLevel)
    {
        while (intBladeLevel == intTargetLevel && intBladePos < BLADE_HIGH)
        {
			//counter++; if(counter > 30) break; // NK
		// NK reload debug
//	trace("GetLastBladeForLevel first while loop, gp" + intBladePos + ", level " + intBladeLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
            intBladePos++;
            makeref(refBlade,BladeItems[intBladePos]);
            intBladeLevel = refBlade.minLevel;
        }
        intBladePos--;
    }
    if (intBladePos < 0)
    {
        intBladePos = 0;
    }
	//traceandlog("Last blade is " + intBladePos + ", " + BladeItems[intBladePos].id + " of qual " + BladeItems[intBladePos].BladeQuality);
    return intBladePos;
}

int GetFirstGunForLevel(int intLevel)
{
    int intLowerPos = 0;
    int intUpperPos = GUN_HIGH;
    int intGunPos   = 0;
    int intGunLevel;
    int intTargetLevel;
    int i;
	int temp = 0; // NK tempfix

    ref refGun;

    if (intLevel < 0)
    {
        intTargetLevel = 0;
    }
    else
    {
        intTargetLevel = intLevel;
    }

    intGunPos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
	// NK reload debug
//	trace("GetFirstGunForLevel startpos " + intGunPos);
    makeref(refGun,GunItems[intGunPos]);
    intGunLevel = sti(refGun.minLevel);
    while(intGunLevel != intTargetLevel && intLowerPos < intUpperPos)
    {
		//counter++; if(counter > 30) break; // NK
	// NK reload debug
//	trace("GetFirstGunForLevel first while loop, gp" + intGunPos + ", level " + intGunLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
        if (intGunLevel > intTargetLevel)
        {
            intUpperPos = intGunPos;
        }
        else
        {
            intLowerPos = intGunPos;
        }
		temp = intGunPos;
        intGunPos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
		if(temp == intGunPos) break; // NK
        makeref(refGun,GunItems[intGunPos]);
        intGunLevel = sti(refGun.minLevel);
    }
	//counter = 0; // NK
    if (intGunLevel == intTargetLevel)
    {
        while (intGunLevel == intTargetLevel && intGunPos > 0)
        {
			//counter++; if(counter > 30) break; // NK
			// NK reload debug
//	trace("GetFirstGunForLevel second while loop, gp" + intGunPos + ", level " + intGunLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
            intGunPos--;
            makeref(refGun,GunItems[intGunPos]);
            intGunLevel = refGun.minLevel;
        }
        intGunPos++;
    }
    if (intGunPos < 0)
    {
        intGunPos = 0;
    }
    return intGunPos;
}

int GetLastGunForLevel(int intLevel)
{
    int intLowerPos = 0;
    int intUpperPos = GUN_HIGH;
    int intGunPos   = 0;
    int intGunLevel;
    int intTargetLevel;
    int i;
	int temp = 0; // NK

    ref refGun;

    if (intLevel > GetGunMaxLevel())
    {
        intTargetLevel = 0;
    }
    else
    {
        intTargetLevel = intLevel;
    }
    intGunPos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
	// NK reload debug
//	trace("GetLastGunForLevel startpos " + intGunPos);
    makeref(refGun,GunItems[intGunPos]);
    intGunLevel = refGun.minLevel;
    while(intGunLevel != intTargetLevel && intLowerPos < intUpperPos)
    {
		//counter++; if(counter > 30) break; // NK
		// NK reload debug
//	trace("GetLastGunForLevel first while loop, gp" + intGunPos + ", level " + intGunLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
        if (intGunLevel > intTargetLevel)
        {
            intUpperPos = intGunPos;
        }
        else
        {
            intLowerPos = intGunPos;
        }
		temp = intGunPos; // NK
        intGunPos = intLowerPos + sti(stf(intUpperPos - intLowerPos) /2);
		if(temp == intGunPos) break; // NK
        makeref(refGun,GunItems[intGunPos]);
        intGunLevel = refGun.minLevel;
    }
	//counter = 0; // NK
    if (intGunLevel == intTargetLevel)
    {
        while (intGunLevel == intTargetLevel && intGunPos < GUN_HIGH)
        {
			//counter++; if(counter > 30) break; // NK
			// NK reload debug
//	trace("GetLastGunForLevel first while loop, gp" + intGunPos + ", level " + intGunLevel + ", targ " + intTargetLevel + ", low " + intLowerPos + ", up " + intUpperPos);
            intGunPos++;
            makeref(refGun,GunItems[intGunPos]);
            intGunLevel = refGun.minLevel;
        }
        intGunPos--;
    }
    if (intGunPos < 0)
    {
        intGunPos = 0;
    }
    return intGunPos;
}

int GetBladeMaxLevel()
{
    ref refMaxBlade;
    makeref(refMaxBlade,BladeItems[BLADE_HIGH]);
    return sti(refMaxBlade.minLevel);
}

int GetGunMaxLevel()
{
    ref refMaxGun;
    makeref(refMaxGun,GunItems[GUN_HIGH]);
    return sti(refMaxGun.minLevel);
}

string GetRandomBladeForLevel(int minLevel, int maxLevel, int maxQuality)
{
	// LDH simplified 06May09, rewritten 08May09
	int intMinLevel   = iClamp(0, GetBladeMaxLevel()-4, minlevel);
	int intMaxLevel   = iClamp(0, GetBladeMaxLevel(), maxLevel);
	int intMaxQuality = iClamp(0, MAX_QUALITY, maxQuality);
	if (intMinLevel > intMaxLevel)
	{
		int templevel = intMaxLevel;
		intMaxLevel = intMinLevel;
		intMinLevel = templevel;
	}
	int intMinBlade  = GetFirstBladeForLevel(intMinLevel);
	int intMaxBlade  = GetLastBladeForLevel(intMaxLevel);
    int intRandBlade = intMinBlade + Rand(intMaxBlade - intMinBlade);

    ref refBlade;
	int bq;
	float randrare;

	bool bFound = false;
	while (!bFound && intRandBlade >= 0)
    {
        makeref(refBlade,BladeItems[intRandBlade]);
		randrare = frnd();
		if(CheckAttribute(refBlade,"BladeQuality")) bq = sti(refBlade.BladeQuality);
		else bq = 2;

		bFound = refBlade.skipequip == false && bq <= intMaxQuality && randrare <= stf(refBlade.rare) && stf(refBlade.rare) != 0.0; // Sulan: rarity code
        intRandBlade--;
    }
	if(refBlade.id == "blank") refBlade.id = "blade8";	// ccc special weapons
    string blade = refBlade.id;
	if (!bFound) blade = "blade4";
    return blade;
}

string GetRandomGunForLevel(int minLevel, int maxLevel, int maxQuality)
{
    int intMinGun;
    int intMaxGun;
    int intRandGun;

    int intMinLevel;
    int intMaxLevel;
    int intMaxQuality;

    // Sulan: rarity for guns -->
    aref arItem;          
    float randrare;       
    bool bFound = false;  
    int gq;               // gun quality
    ref refGun;
    // <-- Sulan

    if (minLevel < 0)
    {
       intMinLevel = 0;
    }
    else
    {
	    if (minLevel > GetGunMaxLevel() - 4)
	    {
	       intMinLevel = GetGunMaxLevel() - 4; // NK for variety 05-07-13
        }
        else
        {
	       intMinLevel = minLevel;
        }
    }
    if (maxLevel < 0)
    {
       intMaxLevel = 0;
    }
    else
    {
	    if (maxLevel > GetGunMaxLevel())
	    {
	       intMaxLevel = GetGunMaxLevel();
        }
        else
        {
	       intMaxLevel = maxLevel;
        }
    }
    if (maxQuality < 0)
    {
       intMaxQuality = 0;
    }
    else
    {
	    if (maxQuality > MAX_QUALITY)
	    {
	       intMaxQuality = MAX_QUALITY;
        }
        else
        {
	       intMaxQuality = maxQuality;
        }
    }
    if (intMinLevel < intMaxLevel)
    {
        intMinGun  = GetFirstGunForLevel(intMinLevel);
        intMaxGun  = GetLastGunForLevel(intMaxLevel);
    }
    else
    {
        intMinGun  = GetFirstGunForLevel(intMaxLevel);
        intMaxGun  = GetLastGunForLevel(intMinLevel);
    }
    intRandGun = intMinGun + Rand(intMaxGun - intMinGun);
    
    // Sulan: Rarity for guns -->
    while (!bFound && intRandGun >= 0)
    {
      makeref(refGun,GunItems[intRandGun]);
 		  randrare = frnd();
 		  
      if(CheckAttribute(refGun,"GunQuality")) gq = sti(refGun.GunQuality);
		  else 
      {
        gq = 2;
        refGun.GunQuality = 2;
      } 		  
 	    bFound = refGun.skipequip == false && gq <= intMaxQuality && randrare <= stf(refGun.rare) && stf(refGun.rare) != 0.0;
      intRandGun--;
    }  
    // <-- Sulan      
	if((refGun.id == "blank") || (!bFound))
	{
		if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) refGun.id = "pistol1";	// ccc special weapons
		else refGun.id = "pistol1a";
	}

	if( Items_FindItem(refGun.id,&arItem)<=0 ) // Sulan - avoid invalid items
	{
		trace("Invalid item: "+refGun.id+" - not given to character.");
		if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) return "pistol1";
		else return "pistol1a";
	}
	else
	{
		return refGun.id;
	}
}

//  scheffnow - weaponsmod <--

// Blacksmith Functions -->

// NK 05-05-11 generalize these and use GetItemIndex, which uses a native call, for speed.

int GetItemPriceByID(string BladeID)
// Retrieves an item price
// Takes an item id, and returns its marketvalue (price) as an integer. NOTE NOT YET IT COMPATIBLE. 05-05-11 NK
{
	// NK 04-09-08 edited to use GetItemIndex() and only call it once.
	int idx = GetItemIndex(BladeID);
	if(idx != -1) return sti(Items[idx].price);
	return 0;
}


string GetItemNameByID(string BladeID)
// Retrieves the name of an item by it's item id
// Takes an item id as parameter and returns the name of that item (excl. status!).
{
	ref CurrentItem = &Items[GetItemIndex(BladeID)];	// Reference to an item
	string retstr = TranslateString("", CurrentItem.name);
	return retstr;
}

string GetItemUpgradePrice(string BladeID, int CurrentQuality, int RequiredQuality, float pricemult)
// Retrieves the upgrade price for the specified blade from CurrentQuality to RequiredQuality
// Takes a blade id, the current status and the required status. Then fetches the price
// to upgrade from the current status to the new status.
{
	if (CurrentQuality >= RequiredQuality) return "0";

	// Get the base id for the blade
	string BladeBaseID;
	if (findSubStr(&BladeID, "+", 0) > -1 || findSubStr(&BladeID, "-", 0) > -1)
		BladeBaseID = strcut(&BladeID, 0, strlen(BladeID) - 3);
	else
		BladeBaseID = BladeID;

	int OldBladePrice = 0;
	int NewBladePrice = 0;
	int UpgradePrice = 0;
	float IntermediatePrice = 0;

	// Convert the qualities to the values used in the blade id's
	CurrentQuality -= 2;
	RequiredQuality -= 2;

	// Get the price of the current quality
	if (CurrentQuality == 0)
		OldBladePrice = GetItemPriceByID(BladeBaseID);
	if (CurrentQuality > 0)
		OldBladePrice = GetItemPriceByID(BladeBaseID + "+" + CurrentQuality);
	if (CurrentQuality < 0)
		OldBladePrice = GetItemPriceByID(BladeBaseID + CurrentQuality);

	// Get the price of the required quality
	if (RequiredQuality == 0)
		NewBladePrice = GetItemPriceByID(BladeBaseID);
	if (RequiredQuality > 0)
		NewBladePrice = GetItemPriceByID(BladeBaseID + "+" + RequiredQuality);
	if (RequiredQuality < 0)
		NewBladePrice = GetItemPriceByID(BladeBaseID + RequiredQuality);

	// Calculate the upgrade price (use a float to work with decimals)
	UpgradePrice = NewBladePrice - OldBladePrice;
	IntermediatePrice = NewBladePrice - OldBladePrice;
	UpgradePrice += (IntermediatePrice * pricemult) * BLACKSMITH_PROFITPERCENT;

	// Convert to string and return
	string ReturnPrice = UpgradePrice;
	return ReturnPrice;
}

// NK now return -1 rather than AVERAGE as an easier check, and so I can use it in IT below. :) 05-07-19
int GetItemQualityByID(string GunID)
// Retrieves the quality of a gun by it's item id
// Takes a gun id as parameter and returns an integer indicating the status of the gun.
{
	int idx = GetItemIndex(GunID);
	if(idx == -1) return -1; // If no item has been found with the specified GunID, then return -1
	ref CurrentItem = &Items[idx];	// Reference to an item
	if(CheckAttribute(CurrentItem, "groupID"))
	{
		string attr = "";
		switch(CurrentItem.groupID)
		{
			case BLADE_ITEM_TYPE: attr = "BladeQuality"; break;
			case GUN_ITEM_TYPE: attr = "gunQuality"; break;
		}
		if(attr != "" && CheckAttribute(CurrentItem, attr)) return sti(CurrentItem.(attr));
	}
	return -1; // If no item has been found with the specified GunID, then return -1
}


// Blacksmith Functions <--

// NK add weaponsmod function GetWeaponIDByQuality 05-04-07
//returns ID of weapon of that quality. Note, takes BASE id! With no +-X at end!
string GetWeaponIDByQuality(string baseid, int q)
{
	if(GetItemIndex(baseid+"+2") == -1) return baseid; // hack for items that have no qual. 05-07-25 NK
	if(q>5) return (baseid + "+3");
	else if(q<0) return (baseid + "-2");
	switch(q)
	{
		case 0: baseid += "-2"; break;
		case 1: baseid += "-1"; break;
		case 3: baseid += "+1"; break;
		case 4: baseid += "+2"; break;
		case 5: baseid += "+3"; break;
	}
	return baseid;
}
// NK <--

// KK -->
string GetItemQualityName(int iQuality)
{
	string ret = "";
	switch (iQuality)
	{
		case 0: ret = TranslateString("","a badly worn"); break;
		case 1: ret = TranslateString("","a worn"); break;
		case 2: ret = TranslateString("","an average"); break;
		case 3: ret = TranslateString("","a good"); break;
		case 4: ret = TranslateString("","a fine"); break;
		case 5: ret = TranslateString("","an excellent"); break;
	}
	return ret;
}
// <-- KK

// NK itemtrade 05-03-26 -->
// do all item trade related functions here.

// assign types to trader
void IT_AssignTypesToTrader(ref chr)
{
	chr = GetCharacter(sti(chr.index)); // just to be sure
	if(CheckAttribute(chr,"itemtrade.done")) return; // because we run this from GiveItem...
	int nat = sti(chr.index); chr = GetCharacter(nat); // just to be sure.
	nat = sti(chr.nation);
	int lvl = sti(chr.rank);
	string loc = chr.location;
	string island = GetIslandIDByLocationID(loc);
	string town = GetTownIDFromLocID(loc);

	int quality;
	if(CheckAttribute(chr,"itemtrade.quality"))
	{
		quality = sti(chr.itemtrade.quality);
		trace("IT for " + chr.id + ", quality passed " + quality);
	}
	else
	{
		// TIH --> rpg_style has a better handler
		if ( IT_RPG_STYLE ) {
			// better method
			if(quality < 1) quality = 0;
			if(town != "") {
				quality = makeint( Bring2Range(1.0, 10.0, makefloat(STORE_MINSIZE / 2.0), makefloat(STORE_MINSIZE*2.0), makefloat(GetTownSize(town)) ) );// TIH number tweak Aug24'06
				trace("IT for " + chr.id + ", town "+town+" size "+GetTownSize(town)+", raw quality set to " + quality);
			} else {
				quality = ((nat == PIRATE) * 2) + rand(5);
				trace("IT for " + chr.id + ", random raw quality set to " + quality);
			}
		} else {
			// previous method
			quality = rand((nat == PIRATE) * 2) + rand(3) + rand(2);
			if(town != "") quality += rand(makeint(Bring2Range(1.0, 8.0, STORE_MINSIZE / 2.0, STORE_MINSIZE*2.0, GetTownSize(town))));// TIH added float decimals to this float function Aug28'06
			trace("IT for " + chr.id + ", raw quality set to " + quality);
		}
		// TIH <--
	}

	string tradetype = IT_TYPE_GENERAL;
	if(HasSubStr(loc,"store")) 												{ tradetype = IT_TYPE_STORE;			trace("IT tradetype checked store, now " + tradetype);}
	if(HasSubStr(chr.Dialog.Filename, "Item Trader")) 						{ tradetype = IT_TYPE_STALL;			trace("IT tradetype checked street, now " + tradetype);}
	if(HasSubStr(chr.Dialog.Filename, "Blacksmith")) 						{ tradetype = IT_TYPE_BLACKSMITH;		trace("IT tradetype checked dlg = BSmith, now " + tradetype);}
	if(CheckAttribute(chr,"current") && HasSubStr(chr.current, "vagabond")) { tradetype = IT_TYPE_SNEAKY;			trace("IT tradetype checked current = vagabond, now " + tradetype);}
	if(HasSubStr(chr.id, "fantom character")) 								{ tradetype = IT_TYPE_SNEAKY;			trace("IT tradetype checked fantom character, now " + tradetype);}

	if(CheckAttribute(chr,"itemtrade.tradetype")) 							{ tradetype = chr.itemtrade.tradetype;	trace("IT tradetype chr override, now " + tradetype);}
	else 																	{ chr.itemtrade.tradetype = tradetype;	trace("IT tradetype assign to chr, now " + tradetype);}

	bool assigntypes = !CheckAttribute(chr,"itemtrade.types");
	bool skiptown, skipisland, skipnat, skipgen, skipqty, skipprice, skipsize;
	bool skipclamp = false;// TIH skip the iclamp or not - so super-quality special rpg_style merchants can exist (like Gregor Samsa)
	if(assigntypes)
	{
		chr.itemtrade.types = ""; // note! Structure is types.tX = types, types.iX = item IDs.
		skiptown 	= CheckAttribute(chr,"itemtrade.skiptype.town");
		skipisland 	= CheckAttribute(chr,"itemtrade.skiptype.island");
		skipnat 	= CheckAttribute(chr,"itemtrade.skiptype.nat");
		skipgen 	= CheckAttribute(chr,"itemtrade.skiptype.general");
		skipqty 	= CheckAttribute(chr,"itemtrade.qty");
		skipprice 	= CheckAttribute(chr,"itemtrade.price");
		skipsize 	= CheckAttribute(chr,"itemtrade.size");
	}
	aref itmt; makearef(itmt, chr.itemtrade.types);
	int cur = 0;
	string tmpstr = "t" + cur;

	switch(tradetype)
	{
		case IT_TYPE_STORE:
			if(assigntypes)
			{
				if ( IT_RPG_STYLE ) {// TIH
				if(!skipqty) chr.itemtrade.qty = 1.25;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.2;// prices are at a premium for store merchants ( those friggen price whores! =)
				} else {
				if(!skipqty) chr.itemtrade.qty = 1.25;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.1;
				}
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
					}
				}
			}
			quality++;
			break;

		case IT_TYPE_STALL:
			if(assigntypes)
			{
				if ( IT_RPG_STYLE ) {// TIH
				if(!skipqty) chr.itemtrade.qty = 0.7;	// smaller amount of stuff at a stall
				if(!skipsize) chr.itemtrade.size = 0.5; // smaller amount of stuff at a stall
				if(!skipprice) chr.itemtrade.price = 1.0;
				} else {
				if(!skipqty) chr.itemtrade.qty = 1.0;
				if(!skipsize) chr.itemtrade.size = 0.5;
				if(!skipprice) chr.itemtrade.price = 1.0;
				}
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
					}
				}
			}
			break;

		case IT_TYPE_BLACKSMITH:
			if(assigntypes)
			{
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.25;
				itmt.(tmpstr) = BLADE_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = GUN_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = ARMOR_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = IT_TYPE_BLACKSMITH + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = BLADE_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = GUN_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = ARMOR_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = IT_TYPE_BLACKSMITH;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.tqty = cur;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
						itmt.general.qty = 0.5; // 0.25 really
					}
				}
			}
			break;

		case BLADE_ITEM_TYPE:
			if(assigntypes)
			{
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.25;
				itmt.(tmpstr) = BLADE_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = BLADE_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.tqty = cur;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
						itmt.general.qty = 0.5; // 0.25 really
					}
				}
			}
			break;

		case GUN_ITEM_TYPE:
			if(assigntypes)
			{
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.25;
				itmt.(tmpstr) = GUN_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = GUN_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.tqty = cur;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
						itmt.general.qty = 0.5; // 0.25 really
					}
				}
			}
			break;

		case ARMOR_ITEM_TYPE:
			if(assigntypes)
			{
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.25;
				itmt.(tmpstr) = ARMOR_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = ARMOR_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.tqty = cur;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
						itmt.general.qty = 0.5; // 0.25 really
					}
				}
			}
			break;

// KK -->
		case MAP_ITEM_TYPE:
			if(assigntypes)
			{
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 1.0;
				if(!skipprice) chr.itemtrade.price = 1.25;
				itmt.(tmpstr) = MAP_ITEM_TYPE + "_" + IT_TYPE_NATION + nat;
				itmt.(tmpstr).qty = 3.0; // actually 1.5
				itmt.(tmpstr).price = 0.75; // note actually only 0.9375 because it's multiplied by the 1.25 above.
				itmt.(tmpstr).quality = 1;
				cur++; tmpstr = "t"+cur;
				itmt.(tmpstr) = MAP_ITEM_TYPE;
				itmt.(tmpstr).qty = 2.0; // 1.0
				itmt.(tmpstr).price = 0.8; // actually 1.0
				cur++; tmpstr = "t"+cur;
				itmt.tqty = cur;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
						itmt.general.qty = 0.5; // 0.25 really
					}
				}
			}
			break;
// <-- KK

		case IT_TYPE_SNEAKY:
			if(assigntypes)
			{
				if ( IT_RPG_STYLE ) {// TIH
				if(!skipqty) chr.itemtrade.qty = 0.5;	// not very many
				if(!skipsize) chr.itemtrade.size = 0.4;	// not very many
				if(!skipprice) chr.itemtrade.price = 0.8;// lower priced!
				} else {
				// set to behave like "IT_TYPE_GENERAL" as that is how they used to behave
				if(!skipqty) chr.itemtrade.qty = 0.5;
				if(!skipsize) chr.itemtrade.size = 0.5;
				if(!skipprice) chr.itemtrade.price = 1.0;
				if(!skiptown) IT_AssignTownType(&chr, town);
				if(!skipisland) IT_AssignIslandType(&chr, island);
				if(!skipnat) IT_AssignNationType(&chr, nat);
				}
				if(!skipgen)
				{
					if(!CheckAttribute(itmt,"general"))
					{
						itmt.general = true;
					}
				}
				itmt.(tmpstr) = IT_TYPE_SNEAKY;
				cur++;
				itmt.tqty = cur;
				//DeleteAttribute(&itmt, "general");// very bad to do if you want someone to trade ANY items
			}
			// TIH --> allow external higher quality setting to pass
			if ( IT_RPG_STYLE && CheckAttribute(chr,"itemtrade.quality") && sti(chr.itemtrade.quality) > IT_QUAL_MAX )
			{
				quality = sti(chr.itemtrade.quality);
				skipclamp = true; // so it doesnt iclamp the quality down for special merchants (like Samsa Gregor)
			} else {
				quality++; // they sell slightly better stuff
			}
			// TIH <--
			break;

		//default is case IT_TYPE_GENERAL:
		if(assigntypes)
		{
			if(!skipqty) chr.itemtrade.qty = 0.5;
			if(!skipsize) chr.itemtrade.size = 0.5;
			if(!skipprice) chr.itemtrade.price = 1.0;
			if(!skiptown) IT_AssignTownType(&chr, town);
			if(!skipisland) IT_AssignIslandType(&chr, island);
			if(!skipnat) IT_AssignNationType(&chr, nat);
			if(!skipgen)
			{
				if(!CheckAttribute(itmt,"general"))
				{
					itmt.general = true;
				}
			}
		}
	}

	if ( !skipclamp )// TIH skipclamp addition
	{
		if ( IT_RPG_STYLE ) {
			// TIH --> raise the minclamp for merchant quality based off every 5 levels of the player Aug24'06
			// This helps make it so a high level character doesnt find any extremely low level merchants
			int it_qual_min_level = roundup(makefloat(GetLevel(GetMainCharacter())+1)/5.0);
			if (it_qual_min_level < IT_QUAL_MIN) { it_qual_min_level = IT_QUAL_MIN; }
			if (it_qual_min_level >= IT_QUAL_MAX) { it_qual_min_level = IT_QUAL_MAX-1; }
			quality = iclamp(it_qual_min_level, IT_QUAL_MAX, quality);
			// TIH <--
		} else {
			quality = iclamp(IT_QUAL_MIN, IT_QUAL_MAX, quality);
		}
	}
	trace("IT for " + chr.id + ", quality set to " + quality);
	chr.itemtrade.quality = quality;
	chr.itemtrade.done = true; // make character itemtrader.
	town = chr.id;
	if(sti(chr.index) < CHARACTERS_QUANTITY) // to skip fantoms--some vags will trade items.
	{
		ShipLookupTable.itemtraders = true;
		ShipLookupTable.itemtraders.(town) = true; // for lookup of traders in daily updates.
	}
}
int IT_AssignTownType(ref chr, string town)
{
	chr = GetCharacter(sti(chr.index)); // just to be sure
	int cur = 0;
	if(CheckAttribute(chr,"itemtrade.types.tqty")) cur = sti(chr.itemtrade.types.tqty);
	if(town == "") town = GetTownIDFromLocID(chr.location);
	if(town == "") return cur;
	aref itmt; makearef(itmt, chr.itemtrade.types);
	string tmpstr;
	tmpstr = "t"+cur;
	itmt.(tmpstr) = IT_TYPE_TOWN + town;
	itmt.(tmpstr).qty = IT_TOWNTYPE_QTY;
	itmt.(tmpstr).price = IT_TOWNTYPE_PRICE;
	itmt.(tmpstr).quality = IT_TOWNTYPE_QUAL;
	cur++;
	chr.itemtrade.types.tqty = cur;
	return cur;
}

int IT_AssignIslandType(ref chr, string island)
{
	chr = GetCharacter(sti(chr.index)); // just to be sure
	int cur = 0;
	if(CheckAttribute(chr,"itemtrade.types.tqty")) cur = sti(chr.itemtrade.types.tqty);
	if(island == "") island = GetIslandIDByLocationID(chr.location);
	if(island == "") return cur;
	aref itmt; makearef(itmt, chr.itemtrade.types);
	string tmpstr;
	tmpstr = "t"+cur;
	itmt.(tmpstr) = IT_TYPE_ISLAND + island;
	itmt.(tmpstr).qty = IT_ISLANDTYPE_QTY;
	itmt.(tmpstr).price = IT_ISLANDTYPE_PRICE;
	itmt.(tmpstr).quality = IT_ISLANDTYPE_QUAL;
	cur++;
	chr.itemtrade.types.tqty = cur;
	return cur;
}

int IT_AssignNationType(ref chr, int nat)
{
	chr = GetCharacter(sti(chr.index)); // just to be sure
	int cur = 0;
	if(CheckAttribute(chr,"itemtrade.types.tqty")) cur = sti(chr.itemtrade.types.tqty);
	if(nat == -1) nat = sti(chr.nation);
	if(nat == -1) return cur; // should never occur...
	aref itmt; makearef(itmt, chr.itemtrade.types);
	string tmpstr;
	tmpstr = "t"+cur;
	itmt.(tmpstr) = IT_TYPE_NATION + nat;
	itmt.(tmpstr).qty = IT_NATIONTYPE_QTY;
	itmt.(tmpstr).price = IT_NATIONTYPE_PRICE;
	itmt.(tmpstr).quality = IT_NATIONTYPE_QUAL;
	cur++;
	chr.itemtrade.types.tqty = cur;
	return cur;
}



//********town-related item funcs. Dunno whether they should be here or towntable.c.

// gets normal money for trader. Unused for now, since we just compare to basemoney.
/*
int GetTownItemTraderMoney(string townn)
{

}
*/
//multiplier to good qty based on town
//float GetTownItemQty(string townn, string itype)
float GetTownItemQty(ref town, string itype)
{
	/*if(townn == "") return 1.0;
	ref town = GetTownFromID(townn);*/
	float change = 1.0;
	//float chmag = 1.0; // the magnitude of the change; final change calc'd as change ^ chmag.
	if(itype != "")
	{
		if(CheckAttribute(town,"itemtrade.types."+itype+".qty")) change = stf(town.itemtrade.types.(itype).qty);
	}
	else
	{
		if(CheckAttribute(town,"itemtrade.qty"))
		{
			change = stf(town.itemtrade.qty);
			//if(CheckAttribute(town,"itemtrade.qty.chmag")) chmag = stf(town.itemtrade.qty.chmag);
		}
	}
	/*int tsize = GetTownSize(townn);
	if(IsFleetInTown(townn, "pchar"))
	{
		tsize += GetSquadronCrewQuantity(GetMainCharacter()) * IT_UPD_TS_FLEET_MULT;
		change *= IT_UPD_INPORTPC_MULT;
	}
	change *= Bring2RangeNoCheck(IT_TSIZE_MIN, IT_TSIZE_MAX, IT_TSIZE_MIN * IT_TSIZE_NORMAL, IT_TSIZE_MAX * IT_TSIZE_NORMAL, tsize);
	return pow2(change, chmag);*/
	return change;
}

//multiplier to good price based on town
//float GetTownItemPrice(string townn, string itype)
float GetTownItemPrice(ref town, string itype)
{
	/*if(townn == "") return 1.0;
	ref town = GetTownFromID(townn);*/
	float change = 1.0;
	//float chmag = 1.0; // the magnitude of the change; final change calc'd as change ^ chmag.
	if(itype != "")
	{
		if(CheckAttribute(town,"itemtrade.types."+itype+".price")) change = stf(town.itemtrade.types.(itype).price);
	}
	else
	{
		if(CheckAttribute(town,"itemtrade.price"))
		{
			change = stf(town.itemtrade.price);
			//if(CheckAttribute(town,"itemtrade.price.chmag")) chmag = stf(town.itemtrade.price.chmag);
		}
	}
	/*int tsize = GetTownSize(townn);
	if(IsFleetInTown(townn, "pchar"))
	{
		tsize += GetSquadronCrewQuantity(GetMainCharacter()) * IT_UPD_TS_FLEET_MULT;
		change *= IT_UPD_INPORTPC_MULT;
	}
	change *= Bring2RangeNoCheck(IT_TSIZE_MIN, IT_TSIZE_MAX, IT_TSIZE_MIN * IT_TSIZE_NORMAL, IT_TSIZE_MAX * IT_TSIZE_NORMAL, tsize);
	return pow2(change, chmag);*/
	return change;
}

//modifier (NOT mult) to trader quality for item based on town.
//int GetTownItemQuality(string townn, string itype)
int GetTownItemQuality(ref town, string itype)
{
	/*if(townn == "") return 0;
	ref town = GetTownFromID(townn);*/
	int mod = 0;
	if(itype != "")
	{
		if(CheckAttribute(town,"itemtrade.types."+itype+".quality")) mod = sti(town.itemtrade.types.(itype).quality);
	}
	// unlike qty and price, town base quality does NOT get rechecked (it can't, because it would influence buy/sell or buyonly checking!)
	//else
	//{
		if(CheckAttribute(town,"itemtrade.quality"))
		{
			mod += sti(town.itemtrade.quality);
		}
	//}
	/*int tsize = GetTownSize(townn);
	if(tsize < STORE_MINSIZE / 2) mod--;
	else
	{
		if(tsize >= STORE_MINSIZE) mod++;
	}*/
	return mod;
}

// get town item related stats (price,qty,qual)
/*bool GetTownItemStats(string townn, ref itm, ref tqty, ref tprice, ref tqual)
{
	float tbaseqty, tbaseprice;
	int i, tbasequal;
	bool foundtq, foundtp, foundtl;
	string temp;
	foundtq = false; foundtp = false; foundtl = false;
	tbaseqty = GetTownItemQty(townn, "");
	tbaseprice = GetTownItemPrice(townn, "");
	tbasequal = GetTownItemQuality(townn, "");
	// NOTE!!!! FIX THIS TO USE NEW ITEM STRUCTURE BEFORE USING THIS!!!
	// new structure is just itm.types.(type name), with no tqty or tX!
	for(i = 0; i < sti(itm.types.tqty); i++)	//because we need to look through all item types to find town qty. Yes, this is not so good a way to do it.
	{
		temp = "t"+i;
		if(!foundtq)
		{
			tqty = GetTownItemQty(townn, itm.types.(temp));
			if(tqty != tbaseqty) foundtq = true;
		}
		if(!foundtp)
		{
			tprice = GetTownItemPrice(townn, itm.types.(temp));
			if(tprice != tbaseprice) foundtp = true;
		}
		if(!foundtl)
		{
			tqual = GetTownItemQuality(townn, itm.types.(temp));
			if(tqual != tbasequal) foundtl = true;
		}
	}
	bool tmp = foundtq || foundtp || foundtl;
	return tmp;
}*/
bool GetTownItemStats(ref town, ref itm, ref tqty, ref tprice, ref tqual)
{
	//trace("IT getting town stats for " + town.name + ", item " + itm.id);
	float tbaseqty, tbaseprice;
	int i, tbasequal;
	string temp;
	bool tmp = false;
	aref itmtypes; makearef(itmtypes, itm.types);
	for(i = 0; i < GetAttributesNum(itmtypes); i++)
	{
		temp = GetAttributeName(GetAttributeN(itmtypes, i));
		if(CheckAttribute(town,"itemtrade.types."+temp))
		{
			tqty = GetTownItemQty(&town, temp);
			tprice = GetTownItemPrice(&town, temp);
			tqual = GetTownItemQuality(&town, temp);
			tmp = true;
			break;
		}
	}
	/* now do these at runtime
	if(!tmp)
	{
		tqty = GetTownItemQty(&town, "");
		tprice = GetTownItemPrice(&town, "");
		tqual = GetTownItemQuality(&town, "");
	}*/
	return tmp;
}


//does rare-modding calcs
float ModItemQtyPlayer()
{
  // Sulan: Redid this function. It will now return values between 1.1 and 2.0 
  // depending on Luck skill. The previous one always returned 1.5 -->
	float ret;
	ret= makefloat(CalcCharacterSkill(GetMainCharacter(), SKILL_SNEAK))/10+1; 
	return ret;
	// <-- Sulan
}

// does qty modding based on qty of trader / item
float ModItemQtyQual(float qual, float iqual)
{
	float tmp;
	qual = makefloat(qual); iqual = makefloat(iqual); // just to be sure...
	if(qual <= iqual + IT_QUAL_MAXABOVE)
	{
		tmp = pow(qual/iqual, IT_QUAL_POWER_BELOW);
		if(tmp < IT_QUAL_FLOOR) tmp = 0.0;
	}
	else
	{
		tmp = IT_QUAL_ABOVESCL * pow((iqual + IT_QUAL_ADDABOVE) / qual, IT_QUAL_POWER_ABOVE);
		if(tmp < IT_QUAL_FLOOR_LQ) tmp = 0.0;
	}
	return tmp;
}

//ignores town mod, qual mod, pchar mod, etc--just the trader type vs item type.
// note: if exist tree itemslist, we return values from there, we do NOT recalc.
void GetItemBaseStatsForTrader(ref ch, ref itm, ref qty, ref price, ref qual)
{
	//trace("IT getting base stats for " + itm.id);
	string temp, type;
	int i;
	ch = GetCharacter(sti(ch.index)); // just to be sure
	aref att;

	bool isgeneral = true;
	qty = 1.0; price = 1.0; qual = 0;
	int max;
	if(CheckAttribute(ch,"itemtrade.qty")) qty = stf(ch.itemtrade.qty);
	if(CheckAttribute(ch,"itemtrade.price")) price = stf(ch.itemtrade.price);
	if(CheckAttribute(ch,"itemtrade.types")) // NK 05-04-14. Yikes. Was !Check.
	{
		if(CheckAttribute(ch,"itemtrade.types.iqty"))
		{
			max = sti(ch.itemtrade.types.iqty);
			for(i = 0; i < max; i++)
			{
				temp = "i"+i;
				makearef(att, ch.itemtrade.types.(temp));
				if(itm.id == GetAttributeValue(att))
				{
					if(CheckAttribute(att,"qty")) qty *= stf(att.qty);
					if(CheckAttribute(att,"price")) price *= stf(att.price);
					if(CheckAttribute(att,"quality")) qual += sti(att.quality);
					isgeneral = false;
					break;
				}
			}
		}
		if(isgeneral && CheckAttribute(ch,"itemtrade.types.tqty"))
		{
			// fill item's itemtypes
			object itm_itemtypes;
			makearef(att, itm.types);
			max = GetAttributesNum(att);
			for(i = 0; i < max; i++)
			{
				temp = GetAttributeName(GetAttributeN(att, i));
				itm_itemtypes.(temp) = true;
				//trace(itm.id + " has type " + temp);
			}
			max = sti(ch.itemtrade.types.tqty);
			for(i = 0; i < max; i++)
			{
				temp = "t"+i;
				makearef(att, ch.itemtrade.types.(temp));
				type = GetAttributeValue(att);
				//trace("checking type " + type);
				if(CheckAttribute(itm_itemtypes,type))
				{
					//trace("found a match!");
					if(CheckAttribute(att,"qty")) qty *= stf(att.qty);
					if(CheckAttribute(att,"price")) price *= stf(att.price);
					if(CheckAttribute(att,"quality")) qual += sti(att.quality);
					isgeneral = false;
					//trace("IT found type for " + itm.id + ", type " + type);
					break;
				}
			}
		}
	}
	if(isgeneral) // add checkatt 05-04-08
	{
		if(!CheckAttribute(ch,"itemtrade.types.general"))
		{
			qty = 0; // item is unused by this trader.
		}
		else
		{
			if(CheckAttribute(itm, "skipgeneral") &&  sti(itm.skipgeneral))  // Sulan: Fixed
			{
				qty = 0; // item is unused by this trader.
			}
			else
	  		{
	  			//trace("IT found no type for " + itm.id + ", so general");
				if(CheckAttribute(ch,"itemtrade.types.general.qty")) qty *= stf(ch.itemtrade.types.general.qty);
				if(CheckAttribute(ch,"itemtrade.types.general.price")) price *= stf(ch.itemtrade.types.general.price);
				if(CheckAttribute(ch,"itemtrade.types.general.quality")) qual += sti(ch.itemtrade.types.general.quality);
			}
	  	}
	}
}

bool DeleteItemFromTradeList(ref ch, string id)
{
	ch = GetCharacter(sti(ch.index)); // just to be sure
	//trace("IT deleting all mention of " + id);
	bool tmp = false;
	ch = GetCharacter(sti(ch.index)); // just to be sure
	if(CheckAttribute(ch,"itemtrade.itemlist.items."+id))
	{
		DeleteAttribute(ch,"itemtrade.itemlist.items."+id);
		tmp = true;
	}
	if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+id))
	{
		DeleteAttribute(ch,"itemtrade.itemlist.buyonly."+id);
		tmp = true;
	}
	bool found = false;
	// for now try not to use raretenth.
	/*if(CheckAttribute(ch,"itemtrade.itemlist.raretenth"))
	{
		int i, j;
		aref rareatt, att, att2;
		makearef(rareatt, ch.itemtrade.itemlist.raretenth);
		for(i = 0; i < GetAttributesNum(rareatt); i++)
		{
			att = GetAttributeN(rareatt, i);
			for(j = 0; j < GetAttributesNum(att); j++)
			{
				att2 = GetAttributeN(att, j);
				if(CheckAttribute(att2, id))
				{
					att2 = stf(att2) - stf(att2.(id));
					if(att2 < 0) att2 = 0;
					DeleteAttribute(att2, id);
					found = true;
					break;
				}
			}
			if(found) break;
		}
	}*/
	return tmp || found;
}
// Gets the qty, price stats for specified trader (ch) and item (itm). If Qty, price are modded as is, not returned.
// Will recalc quality, town stats if recalc = 1; will recalc from scratch if recalc = 2. Will just read stats if recalc = 0.
// Returns true if item is used, false if item is not.
bool GetItemStatsForTrader(ref ch, int tidx, ref itm, ref qty2, ref price2, int recalc)
{
	ch = GetCharacter(sti(ch.index)); // just to be sure
	int iqual, qual, tqual;

	float tqty, tprice, qqty, qty, price;
	string id, temp;
	string branch = "";
	id = itm.id;
	qty = 1.0; price = 1.0; qual = 0; qqty = 1.0;
	// check first. But we have to redo town anyway...
	if(recalc == IT_RECALC_ALL) DeleteItemFromTradeList(&ch, id);
	else
	{
		if(CheckAttribute(ch,"itemtrade.itemlist.items."+itm.id)) { branch = "items"; }// TIH serious bugfix - missing DOT
		else { if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+itm.id)) { branch = "buyonly"; } }// TIH serious bugfix - missing DOT
	}
	if(branch != "")
	{
		if(!recalc)
		{
			qty2 = stf(ch.itemtrade.itemlist.(branch).(id).rqty);
			price2 = stf(ch.itemtrade.itemlist.(branch).(id).fprice);
			return true; // now we don't go farther because
		}
		else
		{
			qty = stf(ch.itemtrade.itemlist.(branch).(id).qty);
			price = stf(ch.itemtrade.itemlist.(branch).(id).price);
			qual = sti(ch.itemtrade.itemlist.(branch).(id).quality);
			// check if item is buyonly because of quality, not skipsell. If so, move back to items. Yes, this means if quality is unchanged the item will get put back to buyonly again...
			if(branch == "buyonly" && !sti(itm.skipsell) && stf(ch.itemtrade.itemlist.(branch).(id).qqty) == IT_QUAL_BUYONLY)
			{
				DeleteItemFromTradeList(&ch, id);
				branch = "items";
				ch.itemtrade.itemlist.(branch).(id).qty = qty;
				ch.itemtrade.itemlist.(branch).(id).price = price;
				ch.itemtrade.itemlist.(branch).(id).quality = qual;
			}
		}
	}
	else
	{
		//if(tmpgauge) Trace("Gauging: getting base stats for " + id);
		//trace("IT creating stats from scratch");
		branch = "items";
		if(sti(itm.skipsell)) branch = "buyonly";
		GetItemBaseStatsForTrader(&ch, &itm, &qty, &price, &qual);
		//if(tmpgauge) Trace("Gauging: done getting base stats");
		if(qty <= 0) // item is unused / contra for trader
		{
			qty2 = qty; price2 = price;
			//trace("IT qty is 0 for trader");
			//if(tmpgauge) Trace("Gauging: deleting item " + id);
			DeleteItemFromTradeList(&ch, id);
			//if(tmpgauge) Trace("Gauging: done deleting item");
			return false;
		}
		ch.itemtrade.itemlist.(branch).(id).qty = qty;
		ch.itemtrade.itemlist.(branch).(id).price = price;
		ch.itemtrade.itemlist.(branch).(id).quality = qual;
	}
	//trace("IT branch is " + branch);
	ref town;
	if(tidx != -1) town = GetTownByIndex(tidx);
	bool usetown = !CheckAttribute(ch,"itemtrade.skiptown") && tidx != -1;
	iqual = 0; tqual = 0; tqty = 1.0; tprice = 1.0;
	//if(tmpgauge) Trace("Gauging: item " + id + ", getting town? " + usetown);
	if(usetown) GetTownItemStats(&town, &itm, &tqty, &tprice, &tqual);
	//if(tmpgauge) Trace("Gauging: done getting town stats");
	ch.itemtrade.itemlist.(branch).(id).tqty = tqty;
	ch.itemtrade.itemlist.(branch).(id).tprice = tprice;
	ch.itemtrade.itemlist.(branch).(id).tquality = tqual;
	qty *= tqty;
	price *= tprice;
	qual += tqual;
	if(qty <= 0) // item is unused / contra for town
	{
		qty2 = qty; price2 = price;
		//trace("IT qty is 0 for town");
		//if(tmpgauge) Trace("Gauging: town qty 0, deleting item");
		DeleteItemFromTradeList(&ch, id);
		//if(tmpgauge) Trace("Gauging: done deleting item");
		return false;
	}
	ch.itemtrade.itemlist.(branch).(id).fquality = qual;
	qual += sti(ch.itemtrade.quality);
	if(CheckAttribute(itm,"quality"))
	{
		iqual = sti(itm.quality);
		if(iqual>0)
		{
			//if(tmpgauge) Trace("Gauging: modding item " + id + ", qty by qual");
			// 05-07-19 special handling for when a weapon is of < fine quality and its itemqual is less than traderqual
			int weapq = GetItemQualityByID(itm.id);
			if(weapq != -1)
			{
				if(weapq < QUALITY_FINE && iqual < qual)
				{
					iqual = retmax(1, iqual - (4 - iqual));
				}
			}
			// TIH --> rpgstyle handler for allowing low items for low level players
			int mcL = GetLevel(GetMainCharacter());
			if ( IT_RPG_STYLE && iqual < qual && sti(itm.minlevel) >= sti(mcL-2) && sti(itm.minlevel) <= sti(mcL+1) ) {
				qqty = abs( makefloat( 1.0 - (0.09 * iclamp(1,10,(qual - iqual)) ) ) );
				if (qqty > 1.0) qqty = 1.0;
				if (qqty < 0.0) qqty = 0.0;
			} else {
				qqty = ModItemQtyQual(qual, iqual);
			}
			//trace("IT item: " + id + " minlevel: " + sti(itm.minlevel) + " quality: " + sti(itm.quality) + " iqual: "+ iqual + " tqual: " +qual + " qqty: " + qqty);
			//if(tmpgauge) Trace("Gauging: done qual");
			// TIH <--
		}
	}
	if(qqty <= 0) // item is too low qual, so is only buyable.
	{
		//trace("IT quality mod is 0, setting to buyonly");
		if(branch != "buyonly")
		{
			//if(tmpgauge) Trace("Gauging: swapping item " + id + "to buyonly branch, qual too low.");
			ch.itemtrade.itemlist.buyonly.(id).qty = ch.itemtrade.itemlist.(branch).(id).qty;
			ch.itemtrade.itemlist.buyonly.(id).price = ch.itemtrade.itemlist.(branch).(id).price;
			ch.itemtrade.itemlist.buyonly.(id).quality = ch.itemtrade.itemlist.(branch).(id).quality;
			ch.itemtrade.itemlist.buyonly.(id).tqty = ch.itemtrade.itemlist.(branch).(id).tqty;
			ch.itemtrade.itemlist.buyonly.(id).tprice = ch.itemtrade.itemlist.(branch).(id).tprice;
			ch.itemtrade.itemlist.buyonly.(id).tquality = ch.itemtrade.itemlist.(branch).(id).tquality;
			ch.itemtrade.itemlist.buyonly.(id).fquality = ch.itemtrade.itemlist.(branch).(id).fquality;
			DeleteAttribute(ch,"itemtrade.itemlist."+branch+"."+id);
			branch = "buyonly";
			//if(tmpgauge) Trace("Gauging: done swapping");
			//DeleteItemFromTradeList(&ch, id);
		}
		qqty = IT_QUAL_BUYONLY;
	}
	qty = qty * qqty;
	ch.itemtrade.itemlist.(branch).(id).fqty = qty;
	float rarem = RARE_DEFAULT;
	if(CheckAttribute(itm,"rare")) rarem = stf(itm.rare);
	ch.itemtrade.itemlist.(branch).(id).rqty = qty * rarem;
	ch.itemtrade.itemlist.(branch).(id).fprice = price;
	ch.itemtrade.itemlist.(branch).(id).qqty = qqty;
	qty2 = qty; price2 = price;
	//divide into tenths
	// for now try not to use raretenth.
	/*if(branch != "buyonly")
	{
		//if(tmpgauge) Trace("Gauging: adding item " + id + " to raretenth list");
		qual = makeint(qty*rarem*10.0); if(qual>9) qual = 9;
		temp = "t"+qual;
		//trace("IT placing " + itm.id + " in tenth " + temp);
		if(!CheckAttribute(ch,"itemtrade.itemlist.raretenth."+temp)) ch.itemtrade.itemlist.raretenth.(temp) = 0.0;
		ch.itemtrade.itemlist.raretenth.(temp).(id) = qty;
		ch.itemtrade.itemlist.raretenth.(temp) = stf(ch.itemtrade.itemlist.raretenth.(temp)) + qty;
		//if(tmpgauge) Trace("Gauging: done adding to raretenth");
	}*/
	return true;
}
//new real GiveItemToTrader func
void GiveNewItemsToTrader(ref ch)
{
	ch = GetCharacter(sti(ch.index)); // just to be sure
	ref itm;
	int i, j, totalattr, endqty, totalprice, curprice, numtries, itmqty;
	string oid, tid; int k, levelRange, qualityCheck, wackPoint, itmQchk, yuckItmQty; aref copyTo, copyFrom; // TIH rpg style needed vars
	aref base, curpct, curitem;
	string temp;
	float chance, size, tqty, tprice;
	bool isupdate = false;
	if(CheckAttribute(ch,"itemtrade.update"))
	{
		isupdate = true;
	}
	size = 0.5; if(CheckAttribute(ch, "itemtrade.size")) size = stf(ch.itemtrade.size);
	tqty = 1.0; tprice = 1.0;
	ref town;
	int tidx = GetTownIndex(GetTownIDFromLocID(ch.location));
	if(tidx != -1) town = GetTownByIndex(tidx);
	bool usetown = !CheckAttribute(ch,"itemtrade.skiptown") && tidx != -1;
	if(usetown)
	{
		tqty = GetTownItemQty(&town, "");
		tprice = GetTownItemPrice(&town, "");
		size *= tqty;
	}
	tqty *= ModItemQtyPlayer();
	bool tmpbool;

	makearef(base, ch.itemtrade.itemlist.items);
	totalprice = 0;
	for(i = 0; i < GetAttributesNum(base); i++)
	{
		curitem = GetAttributeN(base, i);
		if (GetItemIndex(GetAttributeName(curitem)) < 0) continue;		// LDH fix for bad items
		makeref(itm, Items[GetItemIndex(GetAttributeName(curitem))]);
		if(isupdate) DeleteAttribute(ch, "itemtrade.update." + itm.id); // so we are left with only items in ch.it.update that have not been dealt with.
		// TIH --> item skip for player level handling - the proper way RPGs handle items for sale Jul23'06
		if ( IT_RPG_STYLE && CheckAttribute(itm,"minlevel") ) {
			// if the item simply is too high for the character, we never show them
			if ( itm.minlevel > GetLevel(GetMainCharacter())+2 ) { continue; }// we add +1 so that merchants carry something for a quick level up

			// if its WAY too low quality, for a high level character, lets not bother selling to the character
			if ( IT_DROP_LOWQUAL_ITEMS && itm.minlevel < GetLevel(GetMainCharacter()) ) {// add toggle for this sub-mod Aug24'06
				// for every 5 levels the character gains ahead of the items minlevel,
				// this will knock off one level of low quality, but will stop with 'average' quality
				// this will never drop "Good" "Fine" or "Excellent" items
				// has a side effect of making poor merchants not have much for sale to high level characters (good thing?)
				levelRange 		= GetLevel(GetMainCharacter()) - sti(itm.minlevel);
				qualityCheck 	= 5;
				qualityCheck 	= GetItemQualityByID(itm.id);
				wackPoint 		= makeint( levelRange / 5 );
				if ( levelRange >= 5 && qualityCheck >= 0 && qualityCheck <= 3 && qualityCheck < wackPoint ) { continue; }
			}
		}
		// TIH <--
		endqty = 0;
		chance = stf(curitem.rqty) * tqty;
		
		// Sulan: weapons periods -->
		int currentPeriod = GetCurrentPeriod();
		itmqty = GetCharacterItem(&ch, itm.id);
		if(CheckAttribute(itm,"firstperiod") && currentPeriod<sti(itm.firstperiod))
		{
		//	TraceAndLog("Remove " + itm.id + " from trader because of Periods Mod: Should not yet appear!");
			TakeNItems(&ch, itm.id, itmqty*-1); // remove those items from the list
			continue;                           // and continue with the next item
		}

		itmqty = GetCharacterItem(&ch, itm.id);
		if(CheckAttribute(itm,"lastperiod") && currentPeriod>sti(itm.lastperiod))
		{
		//	TraceAndLog("Remove " + itm.id + " from trader because of Periods Mod: Should no longer appear!");
			TakeNItems(&ch, itm.id, itmqty*-1); // remove those items from the list
			continue;                           // and continue with the next item
		}
		// Sulan: weapons periods <--

		// PB: Treasure Quests -->
		// So that you'll always find it if you need it
		if(CheckAttribute(GetMainCharacter(), "required_item"))
		{
			if(!CheckCharacterItem(GetMainCharacter(), Characters[GetMainCharacterIndex()].required_item) && !CheckCharacterItem(ch, Characters[GetMainCharacterIndex()].required_item))
				GiveItem2Character(ch, Characters[GetMainCharacterIndex()].required_item);
		}
		// PB: Treasure Quests <--
				
		if(isupdate)
		{
			tmpbool = itmqty || stf(curitem.rqty) > 0; // check whether quality prevents us from adding the item, but if we already have it proceed.
			if(tmpbool)
			{
				tmpbool = frnd() < chance;
				if(tmpbool && itmqty) tmpbool = frnd() < size; // so we don't check size when deciding to sell, only to what qty.
				if(tmpbool)
				{
					endqty = roundup(chance * size * makefloat(IT_RARE_NUMTRIES)) - itmqty; // endqty is the desired delta itmqty
					//if(itmqty == 0 && endqty == 0) endqty = 1; // because makeint rounds down.
					if(endqty < 0)
					{
						if(itmqty >= itmqty + (endqty * 1.5)) endqty = -rand(abs(endqty*2)); // if we're far enough above zero, we use endqty * 2
						else endqty = -rand(abs(endqty));
					}
					else endqty = rand(endqty*2); // so we don't always undershoot the mark
				}
			}
			if(CheckAttribute(itm,"maxquantity")) // move this out to run irrespective of frnd()! 05-04-08
			{
				if(endqty + itmqty > sti(itm.maxquantity))
				{
					endqty = sti(itm.maxquantity) - itmqty;
				}
			}
		}
		else
		{
			if(chance>1.0)
			{
				itmqty = IT_RARE_NUMTRIES/IT_OVER_RANDSPREAD * makeint(chance);
				for(j = 0; j < IT_OVER_RANDSPREAD; j++) { endqty += rand(itmqty); }
				chance -= makeint(chance);
				endqty = roundup(makefloat(endqty) * size);
			}
			//trace("IT now chance is " + chance);
			for(j = 0; j < IT_RARE_NUMTRIES; j++)
			{
				if(j && frnd() > size) { continue; } // yikes! was if <! size!
				if(frnd() < chance) endqty++;
			}
			if(CheckAttribute(itm,"maxquantity")) { if(endqty > sti(itm.maxquantity)) { endqty = sti(itm.maxquantity); } }
		}
		if(endqty)
		{
			totalprice += makeint(stf(curitem.fprice) * stf(itm.price) * endqty * tprice);
			TakeNItems(&ch, itm.id, endqty);
			//trace("IT found " + endqty + " items of id " + itm.id + ", total price now " + totalprice);

			// TIH --> RPG style reduction of low quality items based on player level
			if ( IT_RPG_STYLE && IT_WEAP_LOWQUAL_CUTOFF > 0 && IT_WEAP_LOWQUAL_CUTOFF < 6 && GetItemQualityByID(itm.id) ) {
				// if we got this far to begin with, then we know that a higher quality weapon has been added
				// if the weapon just added is of quality IT_WEAP_LOWQUAL_CUTOFF or higher, we check for lower qualities added to be removed
				// Qualities:  0  1  2  3  4  5
				itmQchk = GetItemQualityByID(itm.id) - IT_WEAP_LOWQUAL_CUTOFF;// no need to loop up beyond the cutoff
				if ( itmQchk >= 0 && CheckAttribute(itm,"baseid") ) {
					// start from the bottom and work up to current item (only way to catch them all in all situations)
					for (j = 0; j <= itmQchk; j++) {

						oid = GetWeaponIDByQuality( itm.baseid, j );// get the id we need to check on

						if ( CheckAttribute(ch,"itemtrade.itemlist.items."+oid) ) { // if they have it on the sale side

							/* dont REALLY need to do this bit with buy only... */
							// swap the lower quality item into buyonly
							ch.itemtrade.itemlist.buyonly.(oid) = "";
							makearef(copyTo,   ch.itemtrade.itemlist.buyonly.(oid) );
							makearef(copyFrom, ch.itemtrade.itemlist.items.(oid)   );
							CopyAttributes(copyTo, copyFrom);
							DeleteAttribute(ch,"itemtrade.itemlist.items."+oid);
							ch.itemtrade.itemlist.buyonly.(oid).qqty = IT_QUAL_BUYONLY;// special flag must be set
							// this is all that it copies:
							//ch.itemtrade.itemlist.buyonly.(oid).qty 		= ch.itemtrade.itemlist.items.(oid).qty;
							//ch.itemtrade.itemlist.buyonly.(oid).price 	= ch.itemtrade.itemlist.items.(oid).price;
							//ch.itemtrade.itemlist.buyonly.(oid).quality 	= ch.itemtrade.itemlist.items.(oid).quality;
							//ch.itemtrade.itemlist.buyonly.(oid).tqty 		= ch.itemtrade.itemlist.items.(oid).tqty;
							//ch.itemtrade.itemlist.buyonly.(oid).tprice 	= ch.itemtrade.itemlist.items.(oid).tprice;
							//ch.itemtrade.itemlist.buyonly.(oid).tquality 	= ch.itemtrade.itemlist.items.(oid).tquality;
							//ch.itemtrade.itemlist.buyonly.(oid).fquality 	= ch.itemtrade.itemlist.items.(oid).fquality;
							//ch.itemtrade.itemlist.buyonly.(oid).fqty 		= ch.itemtrade.itemlist.items.(oid).fqty;
							//ch.itemtrade.itemlist.buyonly.(oid).rqty 		= ch.itemtrade.itemlist.items.(oid).rqty;
							//ch.itemtrade.itemlist.buyonly.(oid).fprice 	= ch.itemtrade.itemlist.items.(oid).fprice;
							//ch.itemtrade.itemlist.buyonly.(oid).qqty 		= ch.itemtrade.itemlist.items.(oid).qqty;

							yuckItmQty = GetCharacterItem(ch,oid);
							if ( yuckItmQty > 0 ) {
								TakeNItems(&ch, oid, (yuckItmQty * -1) ); // take those items away from the trader

								// add that many items to the next better quality weapon they may have of the same baseid
								for (k = 0; k < 6; k++) {
									tid = GetWeaponIDByQuality( itm.baseid, k );
									if ( CheckCharacterItem(ch,tid) ) {
										TakeNItems(&ch, tid, yuckItmQty);
										break;// break out of loop k
									}
								}
								trace("IT dropped low quality weapon ("+oid+") in favor of higher quality ("+itm.id+")");
								break;// break out of loop j
							}
						}
					}
				}
			}
			// TIH <--
		}
	}
	if(isupdate) AddMoneyToCharacter(&ch, totalprice);
	else
	{
		ch.money = totalprice;
		ch.itemtrade.basemoney = makefloat(totalprice) / tprice; // to index trader money to town
	}
}
// move GiveItemToTrader here from q_r.c
void GiveItemToTrader(ref ch)
{
	//trace("Gauging: NEXTDAY_start giveitem. Char " + ch.id + ", qual " + ch.itemtrade.quality);
	// unneeded ref pchar = GetMainCharacter();
	int chridx = sti(ch.index);
	if(chridx == GetMainCharacterIndex()) // 05-05-03 bugfix
	{
		trace("GIVING ItemTrade TO PCHAR! ERROR!");
		DeleteAttribute(GetMainCharacter(),"itemtrade");
		DeleteAttribute(&ShipLookupTable,"itemtraders."+Characters[GetMainCharacterIndex()].id);
		return;
	}
	ch = GetCharacter(chridx); // just to be sure

	//DeleteAttribute(ch, "items");
	bool givenew = false;
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iDay + " " + iMonth;
	//int iRDTSC;
	if(!CheckAttribute(ch, "items"))
	{
		givenew = true; // note a trader may have a sword/gun, thus meaning that this check will give true even when we haven't assigned items yet. So:
		trace("IT ch " + ch.id + " has no items tree");
	}
	else
	{
		if(CheckAttribute(ch, "quest.item_date")) // if we have this
		{
			if(ch.quest.item_date == "0") { givenew = true; } // if it's not set to a date, means we haven't assigned items.
		}
		else // we may not have item_date yet. If so, check quest.meeting
		{
			if(!CheckAttribute(ch,"quest.meeting") || ch.quest.meeting == "0") // we check this
			{
				givenew = true;
			}
			ch.quest.item_date = "0"; // assign something to item_date.
		}
	}
	if (!CheckAttribute(ch, "itemtrade.itemlist")) givenew = true;	// LDH 16Mar09
	//trace("Gauging: NEXTDAY_did checks");
	if(givenew) // do we decide to fill the trader or just update.
	{
		//trace("Gauging: NEXTDAY_givenew!!!");
		//trace("IT starting from scratch");
		if(!CheckAttribute(ch,"itemtrade.done")) // start from scratch
		{
			IT_AssignTypesToTrader(&ch); // will not do anything if types already assigned.
			SetTraderItemStats(&ch, IT_RECALC_ALL);
		}
		else
		{
			SetTraderItemStats(&ch, IT_RECALC_QL_TN);  // 05-04-17
		}
		GiveNewItemsToTrader(&ch);

		ch.quest.item_date = lastspeak_date;
	}
	else // i.e. we just do an update.
	{
		//trace("Gauging: NEXTDAY_decide to update");
		if(ch.quest.item_date != lastspeak_date)
		{
			int i, curqty, moneych;
			i = sti(ch.itemtrade.quality);
			if(i < IT_QUAL_MAX && CheckAttribute(ch, "itemtrade.numtimes") && sti(ch.itemtrade.numtimes) > i * 10) // quality update.
			{
				//trace("Gauging: NEXTDAY_increase quality start");
				ch.itemtrade.numtimes = 0;
				ch.itemtrade.quality = sti(ch.itemtrade.quality) + 1;
				SetTraderItemStats(&ch, IT_RECALC_QL_TN);
				moneych = sti(ch.money);
				// we need to update base money

				// new:
				aref itmtree1, itmtree2, itmtemp;

				ch.olditems = "";
				makearef(itmtemp, ch.olditems); 		// create temp holder pointer
				makearef(itmtree1, ch.items); 			// create pointer to items
				CopyAttributes(&itmtemp, &itmtree1); 	// make backup // TIH '&' fix Aug28'06
				DeleteAttribute(ch, "items"); 			// clear for givenew

				GiveNewItemsToTrader(&ch); 				// give new

				DeleteAttribute(ch, "items"); 			// clear for return old
				ch.items = ""; 							// clean items
				makearef(itmtree2, ch.items);			// create pointer to items
				CopyAttributes(&itmtree2, &itmtemp); 	// copy old back // TIH '&' fix Aug28'06
				DeleteAttribute(ch, "olditems");		// clear old out

				/* old:
				aref itmtree, itmtemp;
				ch.olditems = ""; makearef(itmtemp, ch.olditems); makearef(itmtree, ch.items); // create old items tree
				CopyAttributes(itmtemp, itmtree); // and make backup
				DeleteAttribute(ch, "items"); // clear for givenew
				GiveNewItemsToTrader(&ch); // give new
				//off for now, we do a regular update for the new items.
				//makearef(itmtree, ch.items); ch.newitems = ""; makearef(itmtemp, ch.newitems); //make new items tree
				//CopyAttributes(itmtemp, itmtree); // make backup of new items
				DeleteAttribute(ch, "items");
				ch.items = ""; // clean items
				makearef(itmtemp, ch.olditems);
				CopyAttributes(itmtree, itmtemp); // copy old back
				DeleteAttribute(ch, "olditems");
				*/

				ch.money = moneych; // restore old money.
				// *** maybe we add model changing code here, to visually show quality.
				//trace("Gauging: NEXTDAY_increase qual end");
				trace("IT "+ ch.id +" raised to level "+ ch.itemtrade.quality);
			}

			string id;
			ref itm;
			ch.itemtrade.update = true; // set up update

			aref itms; makearef(itms, ch.items);
			//list all items before update.
			//trace("Gauging: NEXTDAY_bef list all items first");
			for(i = 0; i < GetAttributesNum(itms); i++)
			{
				id = GetAttributeName(GetAttributeN(itms, i));
				ch.itemtrade.update.(id) = true;
			}
			//iRDTSC = RDTSC_B();
			//trace("Gauging: NEXTDAY_now actually givenewitems");
			GiveNewItemsToTrader(&ch);
			//trace("Gauging: NEXTDAY_finished givenewitems");
			moneych = 0;
			bool replace;
			makearef(itms, ch.itemtrade.update);
			for(i = 0; i < GetAttributesNum(itms); i++) // find items that haven't been dealt with yet. That means they are in the buyonly list (either via quality or skipsell).
			{
				id = GetAttributeName(GetAttributeN(itms, i));
				if (GetItemIndex(id) < 0) continue;		// LDH fix for bad items
				makeref(itm, Items[GetItemIndex(id)]);
				curqty = sti(GetAttributeValue(GetAttributeN(itms, i)));
				TakeNItems(&ch, id, -curqty);
				replace = CheckAttribute(itm, "replacewith");
				TakeNItems(&ch, id, -curqty);
				if(replace) // if possible, replace item.
				{
					while(replace)
					{
						id = itm.replacewith;
						makeref(itm, Items[GetItemIndex(id)]);
						if(sti(itm.skipsell)) // if still can't sell
						{
							if(CheckAttribute(itm, "replacewith")) continue; // continue with replacing
							else { replace = false; TakeNItems(&ch, id, curqty); break; } // else stop here and get money.
						}
						else { break; } // stop here if item not skipsell.
					}
				}
				if(!replace) moneych += curqty * GetItemPriceTrader(&ch, id); // otherwise ditch item and get the money back.
			}
			DeleteAttribute(ch, "itemtrade.update");
			//trace("Gauging: NEXTDAY_done it.update list");
			AddMoneyToCharacter(&ch, moneych);
			// now do money vs. town, base.
			moneych = makeint(stf(ch.itemtrade.basemoney) * GetTownItemPrice(GetTownFromID(GetTownIDFromLocID(ch.location)), ""));
			moneych = makeint((moneych - GetCharacterMoney(&ch)) * IT_UPD_MONEYCHANGER);
			AddMoneyToCharacter(&ch, moneych);

			ch.quest.item_date = lastspeak_date;
		}
	}
	//trace("====================================================");
	//trace("Setup Item Trader: "+ch.id);
	//DumpAttributes(ch);
	//trace("====================================================");
	//trace("Gauging: NEXTDAY_done giveitem");

	if (ENABLE_AMMOMOD)		// LDH skip ammo if mod disabled
	{
		 //JRH -->
		if(CheckCharacterItem(ch, "gunpowder") > 0) TakeNItems(ch,"gunpowder", -100);
		if(CheckCharacterItem(ch, "pistolbullets") > 0)	TakeNItems(ch,"pistolbullets", -100);
		if(CheckCharacterItem(ch, "pistolgrapes") > 0)	TakeNItems(ch,"pistolgrapes", -100);
		if(CheckCharacterItem(ch, "musketbullets") > 0)	TakeNItems(ch,"musketbullets", -100);
		if(CheckCharacterItem(ch, "powderflask") > 0) TakeNItems(ch,"powderflask", -100);
		if(CheckCharacterItem(ch, "ammopouch") > 0)	TakeNItems(ch,"ammopouch", -100);

		ref pchar = GetMainCharacter();
		int ra;
		int ra1;
		int ra2;
		int ra4;
		int ra8;
		int ra16;
		float ff;

		if(CheckAttribute(pchar, "rank"))
		{
			ra = stf(pchar.rank);
			if(ra > 16)
			{
				ra = 16;
			}
		}

		ff = 1.0;			//change here only
		ra1 = ff*ra;
		ra2 = round(0.5*ra1);
		ra4 = round(0.25*ra1);
		ra8 = round(0.125*ra1);
		ra16 = round(0.0625*ra1);

		if(ch.itemtrade.tradetype == IT_TYPE_STALL || ch.itemtrade.tradetype == IT_TYPE_GENERAL || ch.itemtrade.tradetype == IT_TYPE_STORE)
		{
			TakeNItems(ch,"gunpowder", ra2 + rand(ra2) );
			TakeNItems(ch,"pistolbullets", ra2 + rand(ra2) );
			TakeNItems(ch,"pistolgrapes", ra2 + rand(ra2) );
			TakeNItems(ch,"musketbullets", ra4 + rand(ra4) );

			if(rand(100)<20) TakeNItems(ch,"powderflask", 1);
			if(rand(100)<20) TakeNItems(ch,"ammopouch", 1 );	//test available from start JRH
		}
		
		if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
		{
			TakeNItems(ch,"spyglass1", -100);
			TakeNItems(ch,"spyglass2", -100);
			TakeNItems(ch,"spyglass3", -100);
			TakeNItems(ch,"spyglass4", -100);
			TakeNItems(ch,"compass1", -100);
			TakeNItems(ch,"compass2", -100);
			TakeNItems(ch,"compass3", -100);
			TakeNItems(ch,"sextant", -100);
			TakeNItems(ch,"Minerscrow", -100);
			TakeNItems(ch,"Minerspick", -100);
			TakeNItems(ch,"Minersspade", -100);	
			TakeNItems(ch,"gunpowder", -100);
			TakeNItems(ch,"pistolbullets", -100);
			TakeNItems(ch,"musketbullets", -100);				
			TakeNItems(ch,"pistolgrapes", -100);
		}
		//JRH <--
	}
}

// updates all item traders, run once per day in wdm events next day update.
void UpdateAllItemTraders(int clean)
{
	//trace("Gauging: NEXTDAY_IT start");
	if(!CheckAttribute(ShipLookupTable,"itemtraders")) return;
	if(!sti(ShipLookupTable.itemtraders)) return; // allow update switch off 05-04-17
	//trace("doing IT update");
	aref ittable; makearef(ittable, ShipLookupTable.itemtraders);
	aref artmp;
	string id;
	ref ch;
	int i;
	ref PChar = GetMainCharacter();
	object todelete;
	if(CheckAttribute(ShipLookupTable,"itemtraders."+PChar.id)) { DeleteAttribute(&ShipLookupTable,"itemtraders."+PChar.id); } // bugifx 05-05-03
	//trace("Gauging: NEXTDAY_Past the checkattrs and makearefs at top");
	if(clean)
	{
		for(i = 0; i < GetAttributesNum(ittable); i++)
		{
			artmp = GetAttributeN(ittable, i);
			id = GetAttributeName(artmp);
			ch = CharacterFromID(id);
			// for now on clean we delete all items as well as itemtrade.itemlist!
			DeleteAttribute(&ch, "itemtrade.itemlist");
			DeleteAttribute(&ch, "items");
			if(clean == 1) GiveItemToTrader(&ch); // override inactive trader status if cleaning.
			else // if clean == 2, turn everyone off and put off the updating until you speak with them.
			{
				ittable.(id) = false;
				ch.dayssincelasttrade = IT_MAX_DAYS_TO_UPDATE+1;
			}
		}
		//trace("Gauging: NEXTDAY_cleanloop done - cleanstate " + clean);
	}
	else
	{
		if(CheckAttribute(ShipLookupTable, "itemtradestep"))
		{
			i = sti(ShipLookupTable.itemtradestep) + 1;
		}
		else i = 0;
		i = i % IT_STEPS_ON_UPDATE;
		ShipLookupTable.itemtradestep = i;
		while(i < GetAttributesNum(ittable))
		{
			artmp = GetAttributeN(ittable, i);
			id = GetAttributeName(artmp);
			ch = CharacterFromID(id);
			if(sti(GetAttributeValue(artmp))) GiveItemToTrader(&ch);
			int days;
			if(CheckAttribute(ch, "dayssincelasttrade")) days = sti(ch.dayssincelasttrade) + IT_STEPS_ON_UPDATE;
			else days = IT_STEPS_ON_UPDATE;
			ch.dayssincelasttrade = days;
			if(days > IT_MAX_DAYS_TO_UPDATE) // so we don't keep updating traders unless they are in use.
			{
				ittable.(id) = false;
				DeleteAttribute(&ch, "items");
				DeleteAttribute(&ch, "itemtrade.itemlist");
			}
			i+= IT_STEPS_ON_UPDATE;
		}

	}
	//trace("it update done");
	//trace("Gauging: NEXTDAY_IT done");
}

// sets price and qty defines for unused items
void SetTraderItemStats(ref ch, int clean)
{
	ch = GetCharacter(sti(ch.index)); // just to be sure
	int i, idx;
	float qty, price;
	ref itm;
	string temp = GetTownIDFromLocID(ch.location);
	bool istown = temp != "";
	idx = -1;
	if(istown) idx = GetTownIndex(temp);
	temp = "";
	//if(clean == 2) DeleteAttribute(ch,"itemtrade.itemslist");
	for(i = FIRST_TRADE_ITEM; i < ITEMS_QUANTITY; i++) // change from i = 0. quicker now.
	{
		makeref(itm, Items[i]);
		if(sti(itm.skiptrade)) continue;
		if(!clean)
		{
			if(CheckAttribute(ch,"itemtrade.itemlist.items."+itm.id)) { temp = "items"; }// TIH serious bugfix - missing DOT
			else { if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+itm.id)) { temp = "buyonly"; } }// TIH serious bugfix - missing DOT
			if(temp != "") continue;
		}
		temp = itm.id;
		/*if(CheckAttribute(ch,"itemtrade.itemslist.items."+temp))
		{
			if(ch.itemtrade.itemlist.items.(temp).date == lastspeak_date) continue;
		}*/
		//trace("IT setting stats for " + itm.id);
		GetItemStatsForTrader(&ch, idx, &itm, &qty, &price, clean); // this will assign them to the itemlist if they're not there already.
	}
}

// gets the number of different item types (i.e. item IDs) the character has
int GetCharacterItemTypes(ref chr)
{
	if(!CheckAttribute(chr,"Items"))
	{
		return 0;
	}
	aref tmp; makearef(tmp,chr.items);
	return GetAttributesNum(tmp);
}

// gets the total number of items of all types the character has
int GetCharacterItemsTotal(ref chr)
{
	if(!CheckAttribute(chr,"Items"))
	{
		return 0;
	}
	aref tmp; makearef(tmp,chr.items);
	int qty = 0;
	for(int i = 0; i < GetAttributesNum(tmp); i++)
	{
		qty += GetAttributeValue(GetAttributeN(tmp, i));
	}
	return qty;
}

//returns the base price of an item modified by any price multipliers.
int GetItemPriceTrader(ref ch, string id)
{
	int idx = GetItemIndex(id);
	if(idx < 0) return 0;
	ref itm = &Items[idx];
	float mult = 1.0;
	if(CheckAttribute(ch,"itemtrade.itemlist.items."+id)) { mult = stf(ch.itemtrade.itemlist.items.(id).fprice); } // now uses .fprice, the final price.
	else
	{
		if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+id)) { mult = stf(ch.itemtrade.itemlist.buyonly.(id).fprice); }
	}
	return makeint(mult * stf(itm.price));
}

//returns true if item has > 0 qty attribute; otherwise item is (if ==0) not used or (if<0) contraband, and we return false. Checks both itemlists (sell/buy and buyonly)
bool TraderUseItem(ref ch, string id)
{
	ref pchar = GetMainCharacter();
	if(CheckAttribute(pchar,"alwaysshowitems."+id) || CheckAttribute(ch, "alwaysshowitems."+id)) return true; // fix for quest items like spyglass2. 05-04-21. 05-07-25 add for traders too
	if(CheckAttribute(ch,"itemtrade.itemlist.items."+id))
	{
		if(stf(ch.itemtrade.itemlist.items.(id).qty) > 0) return true;
	}
	if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+id))
	{
		if(stf(ch.itemtrade.itemlist.buyonly.(id).qty) > 0) return true;
	}
	return false;
}

//returns true if item has > 0 qty attribute; otherwise item is (==0) not used or (<0) contraband, and we return false. Checks only sell.
bool TraderSellItem(ref ch, string id)
{
	ref pchar = GetMainCharacter(); if(CheckAttribute(pchar,"alwaysshowitems."+id)) return true; // fix for quest items like spyglass2. 05-04-21

	// TIH --> rpg_style hide out of level items Jul27'06
	if ( IT_RPG_STYLE ) {
		int idx = GetItemIndex(id);
		if(idx < 0) return false;
		ref itm; makeref(itm,Items[idx]);
		if ( CheckAttribute(itm,"minlevel") && !CheckAttribute(ch,"itemtrade.rareseller") ) {
			if ( sti(itm.minlevel) > GetLevel(GetMainCharacter()) ) { return false; }// TIH skip the item as its too high for player
		}
	}
	// TIH <--

	if(CheckAttribute(ch,"itemtrade.itemlist.items."+id))
	{
		if(stf(ch.itemtrade.itemlist.items.(id).qty) > 0) return true;
	}
	/*if(CheckAttribute(ch,"itemtrade.itemlist.buyonly."+id))
	{
		if(stf(ch.itemtrade.itemlist.buyonly.(id).qty) > 0) return true;
	}*/
	return false;
}

// NK itemstrade <--

// KK -->
float GetItemWeightByID(string itemID)
{
	int idx = GetItemIndex(itemID);
	if  (idx < 0) return 0.0;
	if (!CheckAttribute(&Items[idx], "weight")) return 0.0;
	return stf(Items[idx].weight);
}

int CheckPossibleItemsQuantity(ref _refCharacter, string itemID, int quantity)
{
	if (!WEIGHTMOD) return quantity;
	if (quantity < 0) return (-quantity);
	float max_capacity = GetCharacterMaxCapacity(_refCharacter);
	float current_capacity = GetCharacterCapacity(_refCharacter);
	float item_weight = GetItemWeightByID(itemID);
	float total_weight = makefloat(quantity) * item_weight;
	float remaining_capacity = max_capacity - current_capacity;
	if (total_weight > remaining_capacity) quantity = makeint(remaining_capacity / item_weight);
	return quantity;
}
// <-- KK

// Levis -->
void ChangeItemGroup(ref   ItemIndex, string Group)
{
	ref genitm;
	int genitmIndex = ItemIndex;
	makeref(genitm,Items[genitmIndex]);
	genitm.groupID = Group;
}

void AddItem( ref   ItemIndex,
              string  id,
              string  model,
              string  picTexture,
              int   picIndex,
              float rare,
              int   minlevel,
              float price,
              int   indiantype,
              int numneeded, int stack, int hidden,
              int leadership, int fencing, int sailing, int accuracy, int cannons,
              int grappling, int repair, int defence, int commerce, int sneak,
              int skiptrade, int skiprand, int skipequip, int skipsell
			  
          )
{
	if(GetItemIndex(id) == -1)
	{
		ref genitm;
		int genitmIndex = ItemIndex;
		makeref(genitm,Items[genitmIndex]);
		genitm.id         = id;
		genitm.name       = "itmname_" + id;
		genitm.describe   = "itmdescr_" + id;
		genitm.model      = model;
		genitm.picTexture = "ITEMS_" + picTexture;
		genitm.picIndex   = picIndex;
		genitm.persistent = true;

		// GreatZen -->
		genitm.skill.num = 1;//MAXIMUS
		if ( numneeded > 1 )  genitm.skill.num      = numneeded;
		genitm.skill.stack = 1;//MAXIMUS
		if ( stack > 1 )      genitm.skill.stack    = stack;
		genitm.skill.hidden = false;//MAXIMUS
		if ( hidden == 1 )    genitm.skill.hidden   = true;

		bool SkillBonus = true;
		if (HasSubStr(id, "jewel") || HasSubStr(id, "indian") || HasSubStr(id, "mineral"))
		{
		SkillBonus = iRealismMode<2 && !ITEM_REALISM;			// BB&Sulan: no bonuses - for those who like more realism, to whom a ruby does not grant any fencing skills
		if(iRealismMode>0)		genitm.skill.hidden     = true;	// PB: You do get the bonus on Realistic Game Mode, but you don't get to see it
		}
		if(SkillBonus)
		{
		if ( leadership != 0 )  genitm.skill.leadership = leadership;
		if ( fencing    != 0 )  genitm.skill.fencing    = fencing;
		if ( sailing    != 0 )  genitm.skill.sailing    = sailing;
		if ( accuracy   != 0 )  genitm.skill.accuracy   = accuracy;
		if ( cannons    != 0 )  genitm.skill.cannons    = cannons;
		if ( grappling  != 0 )  genitm.skill.grappling  = grappling;
		if ( repair     != 0 )  genitm.skill.repair     = repair;
		if ( defence    != 0 )  genitm.skill.defence    = defence;
		if ( commerce   != 0 )  genitm.skill.commerce   = commerce;
		if ( sneak      != 0 )  genitm.skill.sneak      = sneak;
		}
		// GreatZen <--

		genitm.skiptrade = skiptrade;
		genitm.skiprand  = skiprand;
		genitm.skipequip = skipequip;
		genitm.skipsell  = skipsell;

		genitm.types.indian = false;//MAXIMUS
		if ( indiantype == 1 )  genitm.types.indian = true;

		genitm.groupID = OBJECT_ITEM_TYPE; // KK

		//genitm.shown    = false;
		genitm.price      = price;
		genitm.minlevel   = minlevel;
		genitm.rare       = rare;
		ITEMS_QUANTITY ++;
		trace("ITEM ADDED at "+ItemIndex+"total items now: "+ITEMS_QUANTITY);
		
	}
	else
	{
		trace("ITEM ADDING ERROR: id already exist");
	}
}

int findemptyItem()
{
	int i = NativeFindCharacter(&Items, "blank");
	return i;
}

bool CheckPartyItem(string itemName)
{
	ref character = GetMainCharacter();
	if(CheckCharacterItem(character,itemName)) return true;
	int cn;
	for(int i = 0; i < GetPassengersQuantity(character); i++)
	{
		cn = GetPassenger(character, i);
		if(cn < 0) continue;
		if(CheckCharacterItem(GetCharacter(cn),itemName)) return true;
	}
	return false;
}
// <--Levis

// --> PB
void ItemSetPrice(string itemID, int price)
{
	if (itemID == "") return; // PB: Prevent potential error messages
	if (GetItemIndex(itemID) < 0) return;
	aref arItem;
	Items_FindItem(itemID, &arItem);
	arItem.price = price;
}
// <-- PB