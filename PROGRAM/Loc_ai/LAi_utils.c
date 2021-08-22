//Поверить ссылку на персонажа
bool LAi_CheckCharacter(aref chr, string out)
{
	if(!TestRef(chr))
	{
		Trace("LAi_CheckCharacter -> invalid aref, call from " + out);
		return false;
	};
	if(CheckAttribute(chr, "index") == false)
	{
		Trace(out + " -> invalid character, no field <index>");
		return false;
	}
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		Trace(out + " -> invalid character, no field <chr_ai.type>");
		return false;
	}
	if(CheckAttribute(chr, "chr_ai.tmpl") == false)
	{
		Trace(out + " -> invalid character, no field <chr_ai.tmpl>");
		return false;
	}
	return true;
}

//Зарядился ли пистолет у персонажа
bool LAi_CharacterCanFire(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.chargeprc"))
	{
		chr.chr_ai.chargeprc = "1";
		chr.chr_ai.charge = 0;
		return false;
	}
	//MAXIMUS: with amount of charges less than maximum, gun will be loaded by existent amount of charges -[gives one good side effect - possibility to fire off with partially charged gun]->
	if(ENABLE_AMMOMOD==1)
	{
		if(stf(chr.chr_ai.charge)>=1.0)
		{
			if(stf(chr.chr_ai.charge)==RecalcCharacterGun(chr)) return true;
		}
	}
	//MAXIMUS: with amount of charges less than maximum, gun will be loaded by existent amount of charges <-[gives one good side effect - possibility to fire off with partially charged gun]-
	if(sti(chr.chr_ai.chargeprc)==0)
	{
		if(stf(chr.chr_ai.charge) >= 1.0) return true;
	}
	return false;
}

//Может ли сражаться персонаж в заданной локации
bool LAi_LocationCanFight()
{
	if(IsEntity(loadedLocation) != true) return true;
	if(CheckAttribute(loadedLocation, "noFight") != true)  return true;
	if(sti(loadedLocation.noFight) != false) return false;
	return true;
}

//Найти случайный локатор в заданной группе локаторов
string LAi_FindRandomLocator(string group)
{
	//Rewritten by Levis
	//This function returns a random locator which isn't used yet.
	//Check to see if the location is loaded
	if(IsEntity(loadedLocation) != true) return "";
	//Set up the reference
	string at = "locators." + group;
	aref locs, loc;
	makearef(locs,loadedLocation.(at));
	//We go trough all locators but for randomisation we add a shift to the index
	int amountlocs = GetAttributesNum(locs);
	int shift = rand(amountlocs);
	//Check the locators
	string locator = "";
	for(int i = 0; i < amountlocs; i++) //Levis improvement encounters
	{
		int index = i + shift;
		if(index>=amountlocs) index -= amountlocs;
		loc = GetAttributeN(locs, index);
		locator = GetAttributeName(loc);
		if (group == "reload" && locator == "boat") continue; // PB: The 'boat' one is NOT valid!
		//Check if the location is loaded
		if(CheckLocationPosition(loadedLocation, stf(loc.x), stf(loc.y), stf(loc.z)))
		{
			return locator;
		}
	}
	return "";
	/*if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	int tries = 5; //Levis improvement encounters
	for(int i = 0; i < tries; i++) //Levis improvement encounters
	{
		if(CheckAttribute(loadedLocation, at) != 0)
		{
			aref grp;
			makearef(grp, loadedLocation.(at));
			int num = GetAttributesNum(grp);
			if(num <= 0) return "";
			num = rand(num - 1);
			return GetAttributeName(GetAttributeN(grp, num));
		}
	}
	return "";*/
}

//Найти дальний локатор в заданной группе локаторов
string LAi_FindFarLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist;
	string locator = "";
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float dx = x - stf(loc.x);
		float dy = y - stf(loc.y);
		float dz = z - stf(loc.z);
		float d = dx*dx + dy*dy + dz*dz;
		if(j >= 0)
		{
			if(d > dist)
			{
				dist = d;
				j = i;
			}
		}else{
			j = i;
			dist = d;
		}
		if(j >= 0) locator = GetAttributeName(GetAttributeN(grp, j));
		if (group == "reload" && locator == "boat") locator = ""; // PB: The 'boat' one is NOT valid!
	}
	return locator;
}

//Найти дальний свободный локатор в заданной группе локаторов
string LAi_FindFarFreeLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist;
	string locator = "";
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			float dx = x - lx;
			float dy = y - ly;
			float dz = z - lz;
			float d = dx*dx + dy*dy + dz*dz;
			if(j >= 0)
			{
				if(d > dist)
				{
					dist = d;
					j = i;
				}
			}else{
				j = i;
				dist = d;
			}
		}
		if(j >= 0) locator = GetAttributeName(GetAttributeN(grp, j));
		if (group == "reload" && locator == "boat") locator = ""; // PB: The 'boat' one is NOT valid!
	}
	return locator;
}

//Найти ближайший свободный локатор
string LAi_FindNearestFreeLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist;
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			float dx = x - lx;
			float dy = y - ly;
			float dz = z - lz;
			float d = dx*dx + dy*dy + dz*dz;
			if(j >= 0)
			{
				if(d < dist)
				{
					dist = d;
					j = i;
				}
			}else{
				j = i;
				dist = d;
			}
		}
	}
	if(j < 0) return "";
	return GetAttributeName(GetAttributeN(grp, j));
}

//Найти ближайшего видимого персонажа в заданном радиусе
int LAi_FindNearestCharacter(aref chr, float radius)
{
	int res = FindNearCharacters(chr, radius, -1.0, -1.0, 0.01, false, true);
	if(res <= 0) return -1;
	return sti(chrFindNearCharacters[0].index);
}

//Найти ближайшего видимого персонажа в заданном радиусе
int LAi_FindNearestVisCharacter(aref chr, float radius)
{
	int res = FindNearCharacters(chr, radius, -1.0, -1.0, 0.01, true, true);
	if(res <= 0) return -1;
	return sti(chrFindNearCharacters[0].index);
}

//Получить уровень драки приведёный к 0..1
float LAi_GetCharacterFightLevel(aref character)
{
	//Fencing skill
	float fgtlevel = 0.0;
	if(isBoardingLoading == false)
	{
		if(CheckAttribute(character, "skill.Fencing") != 0)
		{
			fgtlevel = makefloat(CalcCharacterSkill(character,SKILL_FENCING)); // NK
		}
	}else{
		fgtlevel = CalcCharacterSkill(character, SKILL_FENCING);
	}
	//Level
	if(fgtlevel < 0.0) fgtlevel = 0.0;
	if(fgtlevel > MAX_CHARACTER_SKILL) fgtlevel = MAX_CHARACTER_SKILL;
	fgtlevel = fgtlevel/MAX_CHARACTER_SKILL;
	return fgtlevel;
}

//Применить повреждение к персонажу
void LAi_ApplyCharacterDamage(aref chr, int dmg)
{
	if(LAi_IsImmortal(chr)) return;
	float damage = MakeFloat(dmg);
	//Офицерам ослабляем поврежрение
	if(CheckAttribute(chr, "chr_ai.type"))
	{
		if(chr.chr_ai.type == LAI_TYPE_OFFICER)
		{
			damage = damage*0.7; // the 1.03 patch has it 0.55!
		}
	}
	//Получаем текущие параметры
	if(!CheckAttribute(chr, "chr_ai.hp")) chr.chr_ai.hp = LAI_DEFAULT_HP;
	if(!CheckAttribute(chr, "chr_ai.hp_max")) chr.chr_ai.hp_max = LAI_DEFAULT_HP_MAX;
	float maxhp = stf(chr.chr_ai.hp_max);
	float hp = stf(chr.chr_ai.hp);
	//Пересчитываем
	hp = hp - damage;
	if(hp < 1.0) hp = 0.0;
	chr.chr_ai.hp = hp;
	//Проверим квест
	LAi_ProcessCheckMinHP(chr);
	//Напишем о нанесённом повреждении
	// NK -->
	int chrIndex = sti(chr.index);
	ref mainChr = GetMainCharacter();
	if(sti(mainChr.index) == chrIndex)
	{
		if(SHOWHP_PLAYER) SendMessage(chr, "lfff", MSG_CHARACTER_VIEWDAMAGE, dmg, MakeFloat(MakeInt(hp)), MakeFloat(MakeInt(maxhp)));
		return;
	}
	for(int i = 1; i < OFFICER_MAX; i++)
	{
		if(GetOfficersIndex(mainChr, i) == chrIndex)
		{
			if(SHOWHP_OFFICERS) SendMessage(chr, "lfff", MSG_CHARACTER_VIEWDAMAGE, dmg, MakeFloat(MakeInt(hp)), MakeFloat(MakeInt(maxhp)));
			return;
		}
	}
	if(!SHOWHP_OTHERS) return;
	// NK <--
	SendMessage(chr, "lfff", MSG_CHARACTER_VIEWDAMAGE, dmg, MakeFloat(MakeInt(hp)), MakeFloat(MakeInt(maxhp)));
}


//Убить персонажа, если закончились hp
void LAi_CheckKillCharacter(aref chr)
{
	if(IsMainCharacter(chr) && CheckAttribute(chr, "TrainingFight")) return;//MAXIMUS
	if(SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsDead")) return;

	if(!CheckAttribute(chr, "chr_ai.hp")) chr.chr_ai.hp = 0.0;
	//Проверяем
	if(stf(chr.chr_ai.hp) < 1.0)
	{
		//Убиваем, если смертен
		if(LAi_IsImmortal(chr))
		{
			chr.chr_ai.hp = 1.0;
			return;
		}

		WriteAttributes(chr);//MAXIMUS: stores attributes for characters, which can be reincarnated

		chr.chr_ai.hp = "0";
		SetCharacterTask_Dead(chr);
		Postevent(EVENT_CHARACTER_DEAD, 1, "i", chr);

		//Переинициируем параметры
		DeleteAttribute(chr, "chr_ai.poison");// ccc fix for poisoned rebirths

		//ccc Survival -> if(CheckAttribute(chr, "chr_ai.type")) //original code, replaced by 
		if(IsMainCharacter(chr))
		{
			PlaySound("OBJECTS\VOICES\DEAD\skeleton\skeleton_dead01.wav");
			if (!CheckAttribute(chr,"quest.disable_rebirth") && !bSuppressResurrection)
			{
				LogIt(TranslateString("","Visions of kingdom come fill your blood-deprived brain"));	//ccc mar20
				LogIt(TranslateString("","Will that lovely angel save you ?"));	//ccc mar20
				LogIt(TranslateString("","Or will you join the demons of the netherworld ?"));	//ccc mar20
			}
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_054.wav");	//ccc mar20
			PlayStereoOGG("music_ship_dead");
		}
		else//ccc Survival <-
		{
			if(CheckAttribute(chr, "chr_ai.type"))
			{
				string func = chr.chr_ai.type;
				chr.chr_ai.type = "";
				chr.chr_ai.tmpl = "";
				if(func!="")
				{
					func = "LAi_type_" + func + "_Init";
					call func(chr);
				}
			}
		}
		LAi_Character_Dead_Process(chr);
	}
}

void LAi_UnStoreFantom(ref fantom)
{
	DeleteAttribute(&fantom,"StoredFellow");
}

//Use this function to store the properties of a fantom.
//Be careful! He will stay in the fantom array, so storing too many will cause fantom generation to drop in amount.
void LAi_StoreFantom(ref fantom)
{
	fantom.StoredFellow = true;
}

bool LAi_FantomIsStored(ref fantom)
{
	return CheckAttribute(fantom,"StoredFellow");
}

void LAi_Clear_Fantoms()
{
	ref fantom;
	for(int i = 0; i < 32; i++)
	{
		fantom = &Characters[LOC_FANTOM_CHARACTERS + i];
		if(!LAi_FantomIsStored(fantom))
		{
			DeleteAttribute(fantom, "");
			fantom.index = LOC_FANTOM_CHARACTERS + i;
			fantom.id = "";
			fantom.location = "none";
			fantom.location.locator = "";
			fantom.location.group = "";
		}
	}
}

//Создать фантомного персонажа
ref LAi_CreateFantomCharacter(bool isfriend, int offset, bool genrank, bool hasblade, float hasgun, string model, string group, string locator) // NK
{
	return LAi_CreateFantomCharacterEx(isfriend, offset, genrank, hasblade, hasgun, model, group, locator); // NK
}

//Levis:
ref LAi_CreateFantomCharacterEx(bool isfriend, int offset, bool genrank, bool hasblade, float hasgun, string model, string group, string locator)
{
	string officertype = OFFIC_TYPE_RANDCHAR;
	if(isfriend)	officertype = FindRandomModelOfficerType(model);
	else			officertype = GetRandomEnemyType();
	return LAi_CreateFantomCharacterRk(isfriend, offset, genrank, officertype, hasblade, hasgun, model, group, locator);
}

// PB: Split this further for group use
ref LAi_CreateFantomCharacterRk(bool isfriend, int offset, bool genrank, string officertype, bool hasblade, float hasgun, string model, string group, string locator)
{
	int rank = offset;
	if (genrank) rank = GetRandomRank(isfriend, officertype, offset);
	return LAi_CreateFantomCharacterExOt(isfriend, officertype, rank, hasblade, hasgun, model, group, locator);
}

//Levis split this up to assign even more stuff to a fantom if we like
ref LAi_CreateFantomCharacterExOt(bool isfriend, string officertype, int rank, bool hasblade, float hasgun, string model, string group, string locator)
{
	return LAi_CreateFantomCharacterExOtAt(isfriend, officertype, "", "", "", rank, hasblade, hasgun, model, group, locator);
}

//Создать фантомного персонажа
ref LAi_CreateFantomCharacterExOtAt(bool isfriend, string officertype, string attr1, string attr2, string attr3, int rank     , bool hasblade, 
								  float hasgun , string model, string group      , string locator)
{
	//Ищем свободное место для персонажа
	for(int i = 0; i < 32; i++)
	{
		if(CheckAttribute(&Characters[LOC_FANTOM_CHARACTERS + i], "id") == false) break;
		if(Characters[LOC_FANTOM_CHARACTERS + i].id == "") break;
	}
	if(i >= 32)
	{
		for(i = 0; i < 32; i++)
		{
			if(!IsEntity(&Characters[LOC_FANTOM_CHARACTERS + i])) break;
		}
		if(i >= 32) i = 0;
	}
	ref chr; makeref(chr, Characters[LOC_FANTOM_CHARACTERS + i]); // KK
	//Заполняем поля персонажа
	chr.id = "Location fantom character <" + i + ">";
	chr.index = LOC_FANTOM_CHARACTERS + i;
	//address
	if (!IsEntity(loadedLocation))
		chr.location = "none";
	else
		chr.location = loadedLocation.id;
	chr.location.group = "";
	chr.location.locator = "";
	chr.location.from_sea = "";
	chr.location.fantom = "1";
	//model
	if (model != "")
		chr.model = model;
	else
		chr.model = "man1";
	// NK apmod model code 05-04-22 -->
	float mheight = MAN_HEIGHT; // KK
	string sex = "man";
	string ani = "man";
	int modelidx = GetModelIndex(model);
	ref rmodel; // KK
	if (modelidx != -1)
	{
		makeref(rmodel, Models[modelidx]); // KK
		ani = rmodel.ani;
		sex = rmodel.sex;
		mheight = stf(rmodel.height);
	}
	chr.model.entity = "NPCharacter";
	chr.model.animation = ani;
	chr.model.height = mheight; // 1.8;
	chr.sex = sex;
	// NK <--
	facemaker(chr); // NK - chr.FaceId = "0";
	// done above chr.headModel = "h_" + chr.model;
	//game params
	//chr.sex = "man";
	// NK -->
	// sex, ani above
	/*chr.sex = ani;
	if(ani == "towngirl") chr.sex = "woman";*/
	chr.reputation = 20 + rand(69);
	chr.friend = isfriend;
	DeleteAttribute(&chr, "HPBonus"); // NK 05-07-03

	DeleteAttribute(&chr, "items"); // ccc Building Kit Dec05 prevents reused chr from "inheriting" items of their predecessors

	//Levis: Add attributes assigned to characters
	if(attr1 != "") chr.(attr1) = true;
	if(attr2 != "") chr.(attr2) = true;
	if(attr3 != "") chr.(attr3) = true;

	//nation - moved up here for consistency 
	int nat = GetLocationNation(loadedLocation);	
	if(nat >= 0)
	{
		chr.nation = nat;
	}else{
		chr.nation = PIRATE; //GetMainCharacter().nation;
	}
	//name
	SetRandomNameToCharacter(chr);
  
	// Sulan: No naval soldiers with shovels and pickaxes -->	
//	if((iFCoHS_BoardingNation != PIRATE) && bFCoHS_FriendlyBoardingStarted)
//	{
//		chr.isSoldier = true;
//	}
//	else
//	{
		if(CheckAttribute(loadedLocation,"boarding"))
		{
			if(boarding_enemy_nation != PIRATE)
			{
				chr.isSoldier = true;
			}
		}
//	}
	// Sulan <--

	chr.rank = rank;
	chr.quest.officertype = officertype;
	chr.money = GetRandCharMoney(chr, 5); // Sulan: decrease carried crew money
	ResetMaxHp(chr); //Levis
	if(hasblade) LAi_NPC_Equip(chr, sti(chr.rank), hasblade, hasgun); // NK do hasblade check. Only times we'll want to run NPCEquip without weapons is a time when we'd probably run it by hand afterwards...
	//Log_SetStringToLog(chr.money);
	// NK <--
	chr.spyglass.itemID = "spyglass2";
	//Quest data
	chr.Dialog.CurrentNode = "First time";
	chr.Dialog.TempNode = chr.Dialog.CurrentNode;
	chr.quest.meeting = "0";
	chr.quest = "True";
	//blade
// NK -- >
// 05-05-10 add gun, armor
/*
	GiveItem2Character(chr, "blade4");
	chr.equip.blade = "blade4";*/
	SetModelItem(&chr, ""); // NK give appropriate models armor. 05-07-11
	EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, BLADE_ITEM_TYPE));
	EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, GUN_ITEM_TYPE));
	EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, ARMOR_ITEM_TYPE));
// NK <--
	DeleteAttribute(chr,"itemtrade"); // NK 05-04-05 so itemtrading cleared
	//Логинем персонажа в локацию
	chr.chr_ai.type = LAI_DEFAULT_TYPE;
	chr.chr_ai.tmpl = LAI_DEFAULT_TEMPLATE;
	chr.chr_ai.group = LAI_DEFAULT_GROUP;
	chr.chr_ai.alarmreact = LAI_DEFAULT_ALARMREACT;
	chr.chr_ai.grpalarmr = LAI_DEFAULT_GRPALARMR;
	// NK -->
	/*chr.chr_ai.hp = LAI_DEFAULT_HP;
	chr.chr_ai.hp_max = LAI_DEFAULT_HP_MAX;*/
	// NK <--
	chr.chr_ai.charge = LAI_DEFAULT_CHARGE;
	if(LAi_numloginedcharacters >= 32)
	{
		Trace("LAi_CreateFantomCharacter -> many logined characters in location (>32)");
		return chr;
	}
	LAi_AddLoginedCharacter(chr);
	if(!CreateCharacter(chr))
	{
		Trace("LAi_CreateFantomCharacter -> CreateCharacter return false");
		return chr;
	}
	//Поставим персонажа на локатор
	if(group == "")
	{
// changed by MAXIMUS -->
		if(!bAbordageStarted) group = "goto";
		else group = "rld";
// changed by MAXIMUS <--
		locator = "";
	}
	if(locator == "")
	{
		//Выбираем дальний локатор
		float posX, posY, posZ;
		posX = 0.0; posY = 0.0; posZ = 0.0;
		if(GetCharacterPos(GetMainCharacter(), &posX, &posY, &posZ))
		{
			locator = LAi_FindFarFreeLocator(group, posX, posY, posZ);
			if(locator == "")
			{
				locator = LAi_FindFarLocator(group, posX, posY, posZ);
				if(locator == "")
				{
					locator = LAi_FindRandomLocator(group);
				}
			}
		}else{
			locator = LAi_FindRandomLocator(group);
		}
	}
	chr.location.group = group;
	chr.location.locator = locator;
//	TraceAndLog("LAi_CreateFantomCharacterExOtAt: " + chr.id + " generated at " + locator);
	//MAXIMUS -->
	if(CheckAdditionalLocator(chr.location, group, locator)==false)
	{
		if(SendMessage(chr, "lss", MSG_CHARACTER_ENTRY_TO_LOCATION, group, locator) == false)
		{
			Trace("LAi_CreateFantomCharacter -> can't teleportation character to <" + group + "::" + locator + ">");
		}
	}
	//MAXIMUS <--
	chr.IsFantom = true;//MAXIMUS
	return chr;
}


object lai_questdelays;
void LAi_QuestDelay(string quest, float delayTime)
{
	int num = GetAttributesNum(&lai_questdelays);
	string atr = "e";
	for(int i = 0; i < num + 10; i++)
	{
		atr = "e" + i;
		if(!CheckAttribute(&lai_questdelays, atr)) break;
	}
	lai_questdelays.(atr) = delayTime;
	lai_questdelays.(atr).quest = quest;
}

void LAi_QuestDelayProcess(float dltTime)
{
	string atr;
	int num = GetAttributesNum(&lai_questdelays);
	//Обсчитываем времена
	for(int i = 0; i < num; i++)
	{
		atr = GetAttributeName(GetAttributeN(&lai_questdelays, i));
		lai_questdelays.(atr) = stf(lai_questdelays.(atr)) - dltTime;
	}
	//Проверяем исполнение и вызываем обработку
	for(i = 0; i < num; i++)
	{
		atr = GetAttributeName(GetAttributeN(&lai_questdelays, i));
		if(atr == "root")
		{
			Trace("LAi_QuestDelayProcess -> invalide attibute field: root!!!");
			continue;
		}
		float time = stf(lai_questdelays.(atr));
		if(time > 0)
		{
			lai_questdelays.(atr) = time;
		}else{
			string quest = lai_questdelays.(atr).quest;
			DeleteAttribute(&lai_questdelays, atr);
			CompleteQuestName(quest);
			i = -1;
			num = GetAttributesNum(&lai_questdelays);
		}
	}
}

void LAi_ChangeReputation(aref chr, int repPoints)
{
	if(chr.reputation != "None")
	{
		if(chr.reputation != "")
		{
			int reput = sti(chr.reputation) + repPoints;
			if(reput < REPUTATION_MIN) reput = REPUTATION_MIN;
			if(reput > REPUTATION_MAX) reput = REPUTATION_MAX;
			chr.reputation = reput;
		}
	}

}

void LAi_CheckCharacterID(aref chr)
{
	SendMessage(chr, "ss", "CheckID", chr.id);
}

void LAi_SetDefaultStayAnimation(aref chr)
{
	if(IsEntity(chr))
	{
		BeginChangeCharacterActions(chr);
		SetDefaultStayIdle(chr);
		SetDefaultNormWalk(chr);
		SetDefaultFight(chr);
		SetDefaultDead(chr);
		SetDefaultFightDead(chr);
		EndChangeCharacterActions(chr);
	}
}

void LAi_SetDefaultDead(aref chr)
{
	if(IsEntity(chr))
	{
		BeginChangeCharacterActions(chr);
		SetDefaultDead(chr);
		EndChangeCharacterActions(chr);
	}
}

void LAi_SetAfraidDead(aref chr)
{
	if(IsEntity(chr))
	{
		BeginChangeCharacterActions(chr);
		SetAfraidDead(chr);
		EndChangeCharacterActions(chr);
	}
}

void LAi_SetDefaultSitAnimation(aref chr)
{
	if(IsEntity(chr))
	{
		BeginChangeCharacterActions(chr);
		SetDefaultSitIdle(chr);
		SetDefaultSitDead(chr);
		EndChangeCharacterActions(chr);
	}
}

void LAi_SetHuberSitAnimation(aref chr)
{
	if(IsEntity(chr))
	{
		BeginChangeCharacterActions(chr);
		SetHuberAnimation(chr);		
		EndChangeCharacterActions(chr);
	}
}
//MAXIMUS -[17.09.2007]->
void LAi_SetDefaultLayAnimation(aref chr)
{
	if(IsEntity(chr))
	{
		chr.chr_ai.type.mode = "lay";
		BeginChangeCharacterActions(chr);
		chr.actions.idle.i1 = "Lay_1";
		EndChangeCharacterActions(chr);
	}
}
//MAXIMUS <-[17.09.2007]-

//Вывести экран в темноту, выполнить квест questFadeOut, вернуть всё обратно, выполнить квест questFadeIn
object LAi_QuestFader;
void LAi_Fade(string questFadeOut, string questFadeIn)
{
	if(questFadeOut != "") LAi_QuestDelay(questFadeOut, 0.5);
	if(questFadeIn != "") LAi_QuestDelay(questFadeIn, 1.0);
	
	if(IsEntity(&LAi_QuestFader))
	{
		Trace("LAi_Fade -> previous fade operation not ended!");
		return;
	}
	//Fader
	SetEventHandler("FaderEvent_EndFade", "LAi_FadeEndFadeOut", 0);
	SetEventHandler("FaderEvent_EndFadeIn", "LAi_FadeEndFadeIn", 0);
	CreateEntity(&LAi_QuestFader, "fader");
	SendMessage(&LAi_QuestFader, "lfl", FADER_OUT, 0.5, false);
	LAi_QuestFader.oldSaveState = InterfaceStates.Buttons.Save.enable;
	InterfaceStates.Buttons.Save.enable = 0;
}

void LAi_FadeEndFadeOut()
{
	DelEventHandler("FaderEvent_EndFade", "LAi_FadeEndFadeOut");
	SendMessage(&LAi_QuestFader, "lfl", FADER_IN, 0.5, true);
}

void LAi_FadeEndFadeIn()
{
	DelEventHandler("FaderEvent_EndFadeIn", "LAi_FadeEndFadeIn");
	InterfaceStates.Buttons.Save.enable = LAi_QuestFader.oldSaveState;
}

//Есть ли оружие у персонада
bool LAi_IsSetBale(aref chr)
{
	return (SendMessage(chr, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
}

//В режиме боя
bool LAi_IsFightMode(aref chr)
{
	return (SendMessage(chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") != 0);
}

//Установить флажёк для востановления хитпойнтов и отношений
#event_handler("EventWorldMapInit", "LAi_SetRestoreStates");
#event_handler(EVENT_SEA_LOGIN, "LAi_SetRestoreStates");
void LAi_SetRestoreStates()
{
	LAi_restoreStates = true;
}

#event_handler("EventSGMode", "LAi_GetSGMode");
bool globalSGMode = false;
bool LAi_GetSGMode()
{
	return globalSGMode;
}

bool LAi_IsBottleWork(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.hp_bottle"))
	{
		if(stf(chr.chr_ai.hp_bottle) > 0.0) return true;
	}
	return false;
}

//Найти в близи врагов
bool LAi_CanNearEnemy(aref chr, float radius)
{
	int num = FindNearCharacters(chr, radius, -1.0, -1.0, 0.001, false, false);
	if(num <= 0) return false;
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return true;
	}	
	return false;
}

// KK -->
#event_handler("LAi_PauseAll", "PauseLayer");
void PauseLayer()
{
	SetTimeScale(0.0);
//	ref ch = GetMainCharacter();
}
// <-- KK
