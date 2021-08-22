//Levis
#event_handler("evntCheckBlockade","procEvntCheckBlockade");

void procEvntCheckBlockade()
{
	int locidx = GetEventData();
	ref lcn = &Locations[locidx];
	if(lcn.id == loadedLocation.id)
	{
		aref buildinglist, building; makearef(buildinglist,lcn.building);
		ref chr;
		float x,y,z,ay;
		for(int i=0;i<GetAttributesNum(buildinglist);i++)
		{
			building = GetAttributeN(buildinglist,i);
			chr = &characters[sti(building.index)];
			if(!CheckAttribute(building,"newpos"))
			{
				GetCharacterPos(chr, &x, &y, &z);
				building.newpos.x = x;
				building.newpos.y = y;
				building.newpos.z = z;
				GetCharacterAy(chr, &ay);
				building.newpos.ay = ay;
			}
			TeleportCharacterToPosAy(chr, stf(building.newpos.x), stf(building.newpos.y), stf(building.newpos.z), stf(building.newpos.ay));
		}
	}
	if(CheckAttribute(GetMainCharacter(),"checkbuildings."+lcn.id)) PostEvent("evntCheckBlockade",300,"l",locidx);
}

//This will store a characters ship so he can't access it until it's been restored
void StoreCharacterShip(ref chref)
{
	aref sto;
	aref sfrom;
	makearef(sfrom, chref.ship); 
	makearef(sto, 	chref.stored_ship);
	CopyAttributes(sto, sfrom);
	//It's stored so now remove all traces of it
	DeleteAttribute(chref,"ship");
	chref.ship.type = SHIP_NOTUSED_TYPE_NAME;
	chref.ship.idx = SHIP_NOTUSED;
	//Also disable reload to ship icon
	bQuestDisableSeaEnter = true;
}

bool RestoreCharacterShip(ref chref)
{
	if(CheckAttribute(chref,"stored_ship"))
	{
		aref sto;
		aref sfrom;
		makearef(sto, chref.ship); 
		makearef(sfrom, chref.stored_ship);
		CopyAttributes(sto, sfrom);
		DeleteAttribute(chref,"stored_ship");
		bQuestDisableSeaEnter = false;
		return true;
	}
	return false;
}

void StartBlockadeCheck(string loc)
{
	ref PChar = GetMainCharacter();
	PChar.postevent.checkbuildings.(loc) = true;
	PChar.checkbuildings.(loc) = true;
	PostEvent("evntCheckBlockade",1000,"l",FindLocation(loc));
}

void StopBlockadeCheck(string loc)
{
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar,"checkbuildings."+loc))
	{
		DeleteAttribute(&PChar,"postevent.checkbuildings."+loc);
		DeleteAttribute(&PChar,"checkbuildings."+loc);
	}
}

bool HideTreasureAtLocation(string locid, float x, float y, float z, string required_item, string quest)
{
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar,"required_item."+locid))
	{
		WriteLocatorGlobal(locid, "box", "treasure_box", "", -1, x, y, z, false);
		if(required_item != "")
		{
			if(!CheckAttribute(PChar,"required_item")) PChar.required_item = required_item; //Only set it if none is set already so we don't conflict with the treasure quests
			PChar.required_item.(locid) = required_item;
		}
		if(quest != "")
		{
			PChar.quest.treasure_chest.(locid) = quest;
		}
		return true;
	}
	traceandlog("ERROR in HideTreasureAtLocation: Treasure Location already in use. Please report this bug! (include compile.log)");
	trace("Location: "+locid);
	return false;
}

bool AddItemToTreasureAtLocation(string locid, string itemid, int amount)
{
	if(CheckAttribute(wholeWorld,locid+".locators.box.treasure_box"))
	{
		ref lcn = &Locations[FindLocation(locid)];
		lcn.treasure_box.items.(itemid) = amount;
		return true;
	}
	traceandlog("ERROR in AddItemToTreasureAtLocation: Treasure Location doesn't contain treasure box. Please report this bug! (include compile.log)");
	trace("Location: "+locid);
	return false;
}

bool FillTreasureChestWithRandomLoot(string locid)
{
	ref Pchar = GetMainCharacter();
	if(CheckAttribute(wholeWorld,locid+".locators.box.treasure_box"))
	{
		ref lcn = &Locations[FindLocation(locid)];
		int Calc_luck = GetCharacterSkill(Pchar,SKILL_SNEAK);
		if( Calc_luck > rand(11) ) // chance you may get robbed, higher luck means lower chances
		{
			Calc_luck = rand(Calc_luck-1)+1;
			//TREASURE
			//TODO: Make this use the additem function
			lcn.treasure_box.money = (Calc_luck*rand(3000));// TIH put here instead
			lcn.treasure_box.items.jewelry1 = (Calc_luck*rand(100));
			if(calc_luck > 3){lcn.treasure_box.items.jewelry2 = (Calc_luck*rand(100));}
			if(calc_luck > 3){lcn.treasure_box.items.jewelry3 = (Calc_luck*rand(100));}
			if(calc_luck > 4){lcn.treasure_box.items.jewelry4 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.jewelry5 = (Calc_luck*rand(100));
			lcn.treasure_box.items.jewelry6 = (Calc_luck*rand(100));
			if(calc_luck > 2){lcn.treasure_box.items.jewelry7 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.jewelry8 = (Calc_luck*rand(100));
			lcn.treasure_box.items.jewelry9 = (Calc_luck*rand(100));
			if(calc_luck > 5){lcn.treasure_box.items.jewelry10 = (Calc_luck*rand(100));}
			if(calc_luck > 1){lcn.treasure_box.items.jewelry11 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.jewelry12 = (Calc_luck*rand(100));
			lcn.treasure_box.items.jewelry13 = (Calc_luck*rand(100));
			if(calc_luck > 2){lcn.treasure_box.items.jewelry14 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.jewelry15 = (Calc_luck*rand(100));
			if(calc_luck > 6){lcn.treasure_box.items.jewelry16 = (Calc_luck*rand(100));}
			if(calc_luck > 9){lcn.treasure_box.items.indian1 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.indian3 = (Calc_luck*rand(50));
			if(calc_luck > 9){lcn.treasure_box.items.indian5 = (Calc_luck*rand(100));}
			if(calc_luck > 8){lcn.treasure_box.items.indian6 = (Calc_luck*rand(100));}
			lcn.treasure_box.items.indian8 = (Calc_luck*rand(10));
			lcn.treasure_box.items.indian9 = (Calc_luck*rand(10));
			if(calc_luck > 9){lcn.treasure_box.items.indian10 = (Calc_luck*rand(100));}
			if(calc_luck > 7){lcn.treasure_box.items.indian12 = (Calc_luck*rand(100));}
			if(calc_luck > 8){lcn.treasure_box.items.indian14 = (Calc_luck*rand(100));}
			//WEAPONS
			int period = GetCurrentPeriod();
			if(calc_luck > 6)
			{
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.pistol3 = (Calc_luck*rand(5)); // Grapeshot Pistol
				else lcn.treasure_box.items.pistol2 = (Calc_luck*rand(5)); // Duelling Pistol
			}
			if(calc_luck > 7)
			{
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.pistol6 = (Calc_luck*rand(4)); // Double-Shot Pistol
				else lcn.treasure_box.items.pistol7a = (Calc_luck*rand(5)); // Brace of older Small Pistols
				lcn.treasure_box.items.spyglass3 = 1;
			}
			if(calc_luck > 8)
			{
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.pistolmtoon = (Calc_luck*rand(4)); // Musketoon
				else lcn.treasure_box.items.pistol8 = (Calc_luck*rand(4)); // Brace of Flintlock Pistols
				lcn.treasure_box.items.commonarmor = (Calc_luck*rand(3));
			}
			if(calc_luck > 9)
			{
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.pistol9 = (Calc_luck*rand(4)); // Brace of Horse Pistols
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.pistolmket = (Calc_luck*rand(10)); // Musket
				else lcn.treasure_box.items.pistolbbuss = (Calc_luck*rand(10)); // Blunderbuss
				if (period >= PERIOD_GOLDEN_AGE_OF_PIRACY) lcn.treasure_box.items.blade27 = rand(10); // Bosun's Choice
				else lcn.treasure_box.items.blade22 = rand(10); // Corsair's Pride
				lcn.treasure_box.items.goldarmor = rand(10);
				lcn.treasure_box.items.spyglass4 = 1;
			}
		}
		return true;
	}
	traceandlog("ERROR in FillTreasureChestWithRandomLoot: Treasure Location doesn't contain treasure box. Please report this bug! (include compile.log)");
	trace("Location: "+locid);
	return false;
}

int getRandomImportGood(ref CurIsland)
{
	aref islRef; makearef(islRef,CurIsland.Trade.Import);
	int n = GetAttributesNum(islRef);
	if(n < 1) return -1;
	int goodidx = rand(n-1);
	return sti(GetAttributeValue(GetAttributeN(islRef,goodidx)));
}

int getRandomContrabandGood(ref CurIsland)
{
	aref islRef; makearef(islRef,CurIsland.Trade.Contraband);
	int n = GetAttributesNum(islRef);
	if(n < 1) return GOOD_WHEAT; // PB: was -1, but better to return something than nothing for its use in Stormy Start
	int goodidx = rand(n-1);
	return sti(GetAttributeValue(GetAttributeN(islRef,goodidx)));
}

string GetPrettyLocationName(string location)
{
	ref lcn = &Locations[FindLocation(location)];
	string label = "";
	if (CheckAttribute(lcn, "id.label"))	label = TranslateString("", lcn.id.label);
	else
	{
		TraceAndLog("GetPrettyLocationName ERROR: Please post your compile.log file at piratesahoy.net!");
		trace("No label found for " + location);
	}
	Preprocessor_Add("island_name", GetIslandNameByLocationID(location));
	if (CheckAttribute(lcn, "townsack")) Preprocessor_Add("town_name", FindTownName(lcn.townsack));
	String name = PreprocessText(label);
	Preprocessor_Remove("town_name");
	Preprocessor_Remove("island_name");
	return name;
}

void UseVegetal(ref chref)
{
	ref PChar = GetMainCharacter();
	TakeNItems(chref, "vegetal", -1);
	//TODO: add translation for description
	SetSkillCharMod(chref, SKILL_FENCING, 2, "vegetal", "Boosted fighting ability by vegetal");
	SetSkillCharMod(chref, SKILL_DEFENCE, 2, "vegetal", "Boosted fighting ability by vegetal");
	ChangeHPBonus(chref, 100);
	PChar.quest.vegetal_effect = sti(GetAttribute(PChar,"quest.vegetal_effect")) + 1;
	chref.quest.vegetal_effect.active = sti(GetAttribute(chref,"quest.vegetal_effect.active")) + 1;
	string questname = "vegetal_effect"+PChar.quest.vegetal_effect;
	PChar.quest.vegetal_effect.users.(questname).charid = chref.id;
	pchar.quest.(questname).win_condition.l1 = "ExitFromLocation";
	pchar.quest.(questname).win_condition.l1.location = pchar.location;
	pchar.quest.(questname).win_condition = "Remove Vegetal Effect";
}

void RemoveVegetalEffect(ref chref);
{
	RemoveSkillCharMod(chref, SKILL_FENCING, "vegetal");
	RemoveSkillCharMod(chref, SKILL_DEFENCE, "vegetal");
	ChangeHPBonus(chref, -100);
	chref.quest.vegetal_effect.active = sti(GetAttribute(chref,"quest.vegetal_effect.active")) - 1;
	if(sti(GetAttribute(chref,"quest.vegetal_effect.active")) < 0)
	{
		chref.quest.vegetal_effect.active = 0;
	}
}

void GetRandom3DPosInRange(float x1, float x2, float y1, float y2, float z1, float z2, float x, float y, float z)
{
	x = GetRandom1DPosInRange(x1, x2);
	y = GetRandom1DPosInRange(y1, y2);
	z = GetRandom1DPosInRange(z1, z2);
}

float GetRandom1DPosInRange(float x1, float x2)
{
	float offset = x2 - x1;
	offset = offset * frnd();
	return x1 + offset;
}