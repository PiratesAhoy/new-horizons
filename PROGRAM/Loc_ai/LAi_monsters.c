//Monsters, fantoms & encounters
#event_handler("TeleportMonster","TeleMonster"); // NK

string LAi_monsters_group = "monsters";

void LAi_CreateMonsters(ref location)
{
	//trace("Gauging: Create Monsters start");
	//Возможность логина монстров в локацию
	//NKcccOA1ENABLE MONSTERS EVEN if(LAi_LocationIsMonstersGen(location) == false) return;
	//Сообщим о начале логина монстров
	// NK -->
	//SetAllSoldierGroups(GetMainCharacter()); // NK, to reset soldier friendlyness.
	//note above is for forthcoming RM soldier-kill-tracking mod.
	
	//NK, this will reset all LAI group params, which are screwed up if FightGroups is called.

	// ccc sneakmod-> This lets you "sneak" if you wear a "camouflage"
	// Thanks to NK for providing the basis :)

	float grdlook = LAI_GROUP_GRD_LOOK; // KK
	float grdhear = LAI_GROUP_GRD_HEAR; // KK
	float ptrlook = LAI_GROUP_PTR_LOOK; // KK
	float ptrhear = LAI_GROUP_PTR_HEAR; // KK
	float mnslook = LAI_GROUP_MNS_LOOK;	// standard sight  if player uncamouflaged
	float mnshear = LAI_GROUP_MNS_HEAR;	// standard hear  if uncamouflaged
	ref Pchar = GetMainCharacter();
	string relation = LAI_GROUP_NEUTRAL;

	if(CheckAttribute(Models[GetModelIndex(PChar.model)],"camouflage") && !ownDeckStarted()) 	// PB: Recode this to be a general mod
	{																							// PB: Used for Bartolomeu and Assassin storylines
		if (GetLocationNation(location) != PERSONAL_NATION) relation = LAI_GROUP_ENEMY;			// camouflagecloak makes you suspicious

		if(Whr_IsNight() && !CheckCharacterItem(PChar,"cursedcoin"))							// camouflage works only at night
		{
			grdlook = 5;	// sight reduced if player camouflaged
			grdhear = 1;	// hearradius if player camouflaged
			ptrlook = 5;	// sight reduced if player camouflaged
			ptrhear = 1;	// hearradius if player camouflaged
			mnslook = 5;	// sight reduced if player camouflaged
			mnshear = 1;	// hearradius if player camouflaged
		}
	}
	else 
	{
		// resets relations to neutral upon locationloading, as originally intended for VC
// KK -->
		if (GetLocationNation(location) != PERSONAL_NATION)
		{
			// PB: For Bartolomeu -->
			if(CheckAttribute(location,"dangerous") && GetNationRelation2MainCharacter(GetLocationNation(location)) <= RELATION_ENEMY && rand(1) == 0) // KK
			{
				relation = LAI_GROUP_ENEMY;
			}
			else
			{
				relation = LAI_GROUP_NEUTRAL;
			}
			// PB: For Bartolomeu <--
		}
		else
			relation = LAI_GROUP_FRIEND;
// <-- KK
	}

	// ccc sneakmod sets grouprelation, sight and hearradius according to new disguise
	// for travellers, residents etc.
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, relation);
	LAi_group_SetLookRadius(LAI_DEFAULT_GROUP, mnslook);	
	LAi_group_SetHearRadius(LAI_DEFAULT_GROUP, mnshear);	

	// for all soldiers and citizens, based on NK RM mod, thanks :)
	for(int j = 0; j < NATIONS_QUANTITY; j++)
	{
		LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, relation); // KK
		LAi_group_SetRelation(LAI_GROUP_PATROL, LAI_GROUP_PLAYER, relation); // KK
		LAi_group_SetRelation(GetSoldiersGroup(j), LAI_GROUP_PLAYER, relation);
		LAi_group_SetRelation(GetCitizensGroup(j), LAI_GROUP_PLAYER, relation);

		LAi_group_SetLookRadius(GetSoldiersGroup(j), grdlook);
		LAi_group_SetHearRadius(GetSoldiersGroup(j), grdhear);
		LAi_group_SetLookRadius(LAI_GROUP_GUARDS, grdlook); // KK
		LAi_group_SetHearRadius(LAI_GROUP_GUARDS, grdhear); // KK
		LAi_group_SetLookRadius(LAI_GROUP_PATROL, ptrlook); // KK
		LAi_group_SetHearRadius(LAI_GROUP_PATROL, ptrhear); // KK
	}

// KK -->
	if (GetLocationNation(location) != PERSONAL_NATION) {
		LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_MONSTERS, LAI_GROUP_NEUTRAL);
		LAi_group_SetRelation(LAI_GROUP_PATROL, LAI_GROUP_MONSTERS, LAI_GROUP_NEUTRAL);
	} else {
		LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
		LAi_group_SetRelation(LAI_GROUP_PATROL, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
		LAi_group_FightGroupsEx(LAI_GROUP_GUARDS, LAI_GROUP_MONSTERS, true, -1, -1, false, false);
		LAi_group_FightGroupsEx(LAI_GROUP_PATROL, LAI_GROUP_MONSTERS, true, -1, -1, false, false);
	}
// <-- KK
	// for monsters only sight/hear change	
	LAi_group_SetLookRadius(LAI_GROUP_MONSTERS, mnslook);	
	LAi_group_SetHearRadius(LAI_GROUP_MONSTERS, mnshear);

	// ccc sneakmod <-	 The following section may be superflous now, NK, pls check :)

	//player
	/*LAi_group_Register(LAI_GROUP_PLAYER);
	LAi_group_SetLookRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PPLAYER);
	//guards
	LAi_group_Register(LAI_GROUP_GUARDS);
	LAi_group_SetLookRadius(LAI_GROUP_GUARDS, nlook);		// ccc sneakmod 
	LAi_group_SetHearRadius(LAI_GROUP_GUARDS, nhear);		// ccc sneakmod 
	LAi_group_SetSayRadius(LAI_GROUP_GUARDS, LAI_GROUP_GRD_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PGUARDS);
	//actors
	LAi_group_Register(LAI_GROUP_ACTOR);
	LAi_group_SetLookRadius(LAI_GROUP_GUARDS, LAI_GROUP_ACT_LOOK);	// why GUARDS ??
	LAi_group_SetHearRadius(LAI_GROUP_GUARDS, LAI_GROUP_ACT_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_GUARDS, LAI_GROUP_ACT_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PDEFAULT);
	//governors
	LAi_group_Register(LAI_GROUP_HUBER);
	LAi_group_SetLookRadius(LAI_GROUP_GUARDS, LAI_GROUP_HUB_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_GUARDS, LAI_GROUP_HUB_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_GUARDS, LAI_GROUP_HUB_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PCITIZENS);

	//monsters
	LAi_group_Register(LAI_GROUP_MONSTERS);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_SetLookRadius(LAI_GROUP_MONSTERS, nlook);	// ccc sneakmod 
	LAi_group_SetHearRadius(LAI_GROUP_MONSTERS, nhear);	// ccc sneakmod
	LAi_group_SetSayRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, 0);*/

	//LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // reset rel
	// NK <--
	//trace("Gauging: Top stuff done.");
	if(!LEnc_MonstersLoginStart(location)) return;
	//trace("Gauging: Created monster template");

	//cccOA1 disable monsters in tavern bedroom
	if(location.image == "Tavern_Upstairs_01.tga") return;
	//MAXIMUS: monsters in prison will be generated by special function
	if(location.filespath.models=="locations\inside\prison") 
	{
		if(location.id == "wr_prison" || location.id == "wr_gibbet" || location.id == "Fort_Moultrie_prison")
		{
			//JRH: not in Rogers prison
		}
		else
		{
			FillPrison();
			return;
		}
	}

	if(location.id == "QC_brothel_upstairs") return; // ccc Nov06 no residents in brothelbedroom
	if(HasSubStr(location.id,"brothel") && HasSubStr(location.id,"upstairs")) return;//MAXIMUS: no monsters in brothels bedrooms
	if(bMutinyDeckStarted || HasSubStr(location.id,"Tutorial") || HasSubStr(location.id,"Cap") || HasSubStr(location.id,"Cabin") || HasSubStr(location.id,"Hold")) return;//MAXIMUS: no monsters in these locations

	//MAXIMUS: no monsters on Isla De Muerte
	if (FindIslandByLocation(location.id) == "IslaDeMuerte") return; //ASVS

	//NKcccOA1 enable monsterpositioning in cities (NK, flipped the logic)
	if(location.type != "town" && location.type != "brothel" && location.type != "tavern" && location.type != "house" && location.type != "port") LAi_monsters_group = "monsters";
	else LAi_monsters_group = "goto";
	bool shipLocation = false;//MAXIMUS: automatically fills ship by people
	if(location.type == "own_deck") { LAi_monsters_group = "rld"; shipLocation = true; }
	if(location.type == "crew")
	{
		if(Whr_IsNight()) LAi_monsters_group = GetRandSubString("sit,sleep");
		else LAi_monsters_group = GetRandSubString("sit,rld");
		shipLocation = true;
	}
	if(location.type == "ship") { LAi_monsters_group = "rld"; shipLocation = true; }

	// screwface : to have native indians at hispaniola temple
	if(location.id == "Hispaniola_temple"){LAi_monsters_group = "goto";}

	// ccc Greater Oxbay: to enable encounters in fake forts and Maltese abbey
	if(location.type == "military")
	{
		if(location.filespath.models=="locations\Inside\LargeStore"){LAi_monsters_group = "goto";}
		else {LAi_monsters_group = "rld";}
	}

	if(location.id == "Greenford_M_church") LAi_monsters_group = "goto";

	//cccOA1 enable fights in tavern bar room
	if(location.type == "tavern") LAi_LocationFightDisable(&location, false);
	//Наличие группы для логина монстров
	string group = "locators." + LAi_monsters_group;
	//if(DEBUGINFO) Log_SetStringToLog("Using " + group); // NK
	if(CheckAttribute(location, group) == 0)
	{
		if(DEBUGINFO) Log_SetStringToLog("No locators of " + group);
		if(location.type != "house") return; // NK
		LAi_monsters_group = "reload"; // NK for houses that don't have gotos
		group = "locators." + LAi_monsters_group; 
		if(DEBUGINFO) Log_SetStringToLog("House, using " + group + " instead.");
	}
	//Максимально возможное количество монстров
	int maxMonsters = (MAX_LOGINED_CHARACTERS_IN_LOCATION-12) - LAi_numloginedcharacters;

	//SCREWFACE : INCREASE maxMonsters if crewmembers on shore mod
	if (LANDCREWMEMBERS && makeint(environment.time) > 8.0 && makeint(environment.time) < 22.0) 
	{
		maxMonsters = (MAX_LOGINED_CHARACTERS_IN_LOCATION-6) - LAi_numloginedcharacters;
	}
	//END

	if(DEBUGINFO) Log_SetStringToLog("Total Chars Now: " + LAi_numloginedcharacters + ", MaxMonsters: " + maxMonsters); // NK
	//cccOA1 limit monsters
	//if(CheckAttribute(location,"curvag")) { DeleteAttribute(location,"curvag"); } // NK 
	if(location.type == "town")
	{
		if(IsDay()) // NK
		{
			//if(maxMonsters > LAi_numloginedcharacters /2) maxMonsters = LAi_numloginedcharacters/2; // NK
			if(maxMonsters > 8) maxMonsters = 8;
			//if((MAX_LOGINED_CHARACTERS_IN_LOCATION-12) - LAi_numloginedcharacters >=4 && maxMonsters < 4) maxMonsters = 4; // NK
		}
		else // NK -->
		{
			maxMonsters = maxMonsters/2;
			if(maxMonsters > 8) maxMonsters = 8;
			if((MAX_LOGINED_CHARACTERS_IN_LOCATION-12) - LAi_numloginedcharacters >=4 && maxMonsters < 4) maxMonsters = 4;
		}
		// NK <--
	}
	if(location.type == "tavern" && maxMonsters > 4) maxMonsters = 4;
	if(location.type == "brothel" && maxMonsters > 5) maxMonsters = sti(Rand(3)+2);//MAXIMUS: automatically fills brothels by women
	if(shipLocation)//MAXIMUS: automatically fills ship by people
	{
		int shipClass = ShipsTypes[GetCharacterShipType(GetMainCharacter())].Class;
		if(HasSubStr(location.id,"Seadog"))
		{
			if(Whr_IsNight()) { if(maxMonsters>6) maxMonsters = sti(Rand(6)+1); }
			else { if(maxMonsters>2) maxMonsters = sti(Rand(2)+1); }
		}
		if(HasSubStr(location.id,"deck") && !HasSubStr(location.id,"cannon"))
		{
			if(Whr_IsNight())
			{
				switch(shipClass)
				{
					case 7: if(maxMonsters>5) maxMonsters = sti(Rand(3)+2); break;
					case 6: if(maxMonsters>5) maxMonsters = sti(Rand(3)+2); break;
					case 5: if(maxMonsters>7) maxMonsters = sti(Rand(3)+4); break;
					case 4: if(maxMonsters>7) maxMonsters = sti(Rand(3)+4); break;
					case 3: if(maxMonsters>7) maxMonsters = sti(Rand(3)+4); break;
					case 2: if(maxMonsters>9) maxMonsters = sti(Rand(3)+6); break;
					case 1: if(maxMonsters>9) maxMonsters = sti(Rand(3)+6); break;
					if(maxMonsters>5) maxMonsters = sti(Rand(3)+2);
				}
			}
			else
			{
				if(bCanEnterToLand) LAi_monsters_group = "rld";
				else LAi_monsters_group = "cannon";
				group = "locators." + LAi_monsters_group;
				switch(shipClass)
				{
					case 7: if(maxMonsters>8) maxMonsters = sti(Rand(3)+5); break;
					case 6: if(maxMonsters>10) maxMonsters = sti(Rand(4)+6); break;
					case 5: if(maxMonsters>12) maxMonsters = sti(Rand(5)+7); break;
					case 4: if(maxMonsters>14) maxMonsters = sti(Rand(6)+8); break;
					case 3: if(maxMonsters>16) maxMonsters = sti(Rand(7)+9); break;
					case 2: if(maxMonsters>18) maxMonsters = sti(Rand(6)+12); break;
					case 1: if(maxMonsters>20) maxMonsters = sti(Rand(6)+14); break;
					if(maxMonsters>8) maxMonsters = sti(Rand(3)+5);
				}
			}
		}
		if(HasSubStr(location.id,"cannon"))
		{
			if(Whr_IsNight()) { if(maxMonsters>5) maxMonsters = sti(Rand(2)+3); }
			else { if(maxMonsters>10) maxMonsters = sti(Rand(4)+6); }
		}
	}
	if(location.type == "house")  // NK -->
	{
		if(maxMonsters > 4) maxMonsters = 4;
		int mtemp = rand(3)+1; if(mtemp < maxMonsters) maxMonsters = mtemp; //NK because I set the select_model thing to always work
		if(CheckAttribute(location,"lastentermonth")) // && !CheckAttribute(location,"savethesevags"))
			{ maxMonsters = 1; } //for debug only one
			//{ maxMonsters = sti(location.vags.quantity); location.curvag = 0; }
	}
	if(group == "locators.reload")
	{
		maxMonsters = 1;
		//group = "reload";
	}
	// NK <--

	// ccc Greater Oxbay: to enable encounters in fake forts and Maltese abbey
	if (CheckAttribute(location, "type") && location.type == "military") // KK
	{
		if(location.image == "Fort_01.tga") {maxMonsters = 10;}
		else {maxMonsters = 8;}
	}
	if(location.image == "Isla_Muelle_Church.tga") maxMonsters = 10;

	if(DEBUGINFO) Log_SetStringToLog(stringRet(CheckAttribute(location,"lastentermonth"),"Occupants, ","") + "MaxMonsters Clamped: " + maxMonsters);
	if(maxMonsters <= 0) return;
	//Перебераем локаторы, выбирая свободные
	// NK -->
	int loginedMonsters = 0;
	if(group != "locators.reload") //i.e., normal locators.
	{
		aref grp;
		makearef(grp, location.(group));
		int num = GetAttributesNum(grp);
		if(num <= 0) return;
		if(maxMonsters > num) maxMonsters = num;
		int locatorPos = 0;
		// loginedMonsters moved up
		//trace("Gauging: start locator loop");
		for(int i = 0; i < maxMonsters; i++)
		{
			//Количество локаторов на текущего монстра
			int locnum = (num - locatorPos)/(maxMonsters - loginedMonsters);
			if(locnum < 1) locnum = 1;
			//Выбираем локатор из доступных
			locnum = rand(locnum - 1);
			locatorPos = locatorPos + locnum + 1;
			//Позиция локатора
			aref loc = GetAttributeN(grp, locatorPos - 1);
			if(GetAttributeName(GetAttributeN(grp, i))=="wheel" || GetAttributeName(GetAttributeN(grp, i))=="wheel1") continue;//MAXIMUS: monster onto steering-wheel locator will be placed later
			float lx = stf(loc.x);
			float ly = stf(loc.y);
			float lz = stf(loc.z);
			if(CheckLocationPosition(loadedLocation, lx, ly, lz))
			{
				if(LAi_MonsterLogin(location, LAi_monsters_group, GetAttributeName(GetAttributeN(grp, i))))
				{
					loginedMonsters = loginedMonsters + 1;
				}
			}
		}
	}
	else
	{
		//house, using reload locator
		LAi_MonsterLogin(location, "reload", "reload1");
		loginedMonsters = 1;
	}
	if(DEBUGINFO) Log_SetStringToLog("Logged in " + loginedMonsters + " monsters");
	// NK <--
	//Сообщим об окончании логина монстров
	LEnc_MonstersLoginEnd(location);
}

// NK -->
void TeleMonster()
{
	int chr_index = GetEventData();
	if(DEBUGINFO) Log_SetStringToLog("Moving " + Characters[chr_index].id)
	float tx,ty,tz;
	GetCharacterPos(GetMainCharacter(), &tx, &ty, &tz);
	TeleportCharacterToPos(GetCharacter(chr_index), tx, ty, tz+1.25);
}

object LAi_MonsterInfo;

bool LAi_MonsterLogin(ref location, string group, string locator)
{
	//trace("Gauging: Start MonsterLogin");
	//Запросим модель
	string defModel = "Skel1";
	string defAni = "man";
	LAi_MonsterInfo.model = defModel;
	LAi_MonsterInfo.ani = defAni;
	aref ainfo;
	makearef(ainfo, LAi_MonsterInfo);
	// NK -->
	bool save = CheckAttribute(location,"savethesevags");
	//if(DEBUGINFO && save) Log_SetStringToLog("Will save.");
	bool restore = !save && CheckAttribute(location,"lastentermonth");
	//if(DEBUGINFO && restore) Log_SetStringToLog("Will restore.");
	//check to make sure all properties were saved
	restore = restore  && CheckAttribute(location,"vag.model");
	//if(DEBUGINFO && restore) Log_SetStringToLog("model.");
	restore = restore && CheckAttribute(location,"vag.ani");
	//if(DEBUGINFO && restore) Log_SetStringToLog("ani.");
	restore = restore && CheckAttribute(location,"vag.name");
	//if(DEBUGINFO && restore) Log_SetStringToLog("name.");
	restore = restore && CheckAttribute(location,"vag.lastname");
	//if(DEBUGINFO && restore) Log_SetStringToLog("lastname.");
	restore = restore && CheckAttribute(location,"vag.rich");
	//if(DEBUGINFO && restore) Log_SetStringToLog("rich.");
	//int curvag = -1;
	//if(CheckAttribute(location,"curvag")) curvag = sti(location.curvag);
	//string sCurvag = curvag;
	if(!restore) { if(!LEnc_MonstersLoginSelectModel(location, ainfo, group, locator)) return false; } //NK bit at front
	else
	{
		/*LAi_MonsterInfo.model = location.vags.(sCurvag).model;
		LAi_MonsterInfo.ani = location.vags.(sCurvag).ani;
		LAi_MonsterInfo.current = "vagabond";
		LAi_MonsterInfo.type = "house";
		if(DEBUGINFO) Log_SetStringToLog("Loading vagabond " + curvag + ", model: " + LAi_MonsterInfo.model);*/
		LAi_MonsterInfo.model = location.vag.model;
		LAi_MonsterInfo.ani = location.vag.ani;
		LAi_MonsterInfo.current = "vagabond";
		LAi_MonsterInfo.type = "house";
		if(DEBUGINFO) Log_SetStringToLog("Restoring vag, model: " + LAi_MonsterInfo.model);
	}
	//trace("Gauging: SelectModel done, now getting actual model:");
	if(GetModelindex(ainfo.model) == -1)
	{
		//trace("Gauging: model not exist, assuming type.");
		ainfo.model = GetRandomModelForTypeExSubCheck(sti(ainfo.iscombat), ainfo.model, ainfo.sex, GetCurrentLocationNation()); // PB: was sti(ainfo.nation)
		//trace("Gauging: Found actual model.");
	}
	if(sti(GetModelIndex(ainfo.model)) == -1) TraceAndLog("ERROR - Missing Model ID from initModels: " + ainfo.model); // PB: Error checking
	ref cmodel = &Models[GetModelIndex(ainfo.model)];
	ainfo.ani = cmodel.ani;
	ainfo.sex = cmodel.sex;
	//trace("Gauging: Copied over.");
	// NK <--
	//Проверим модельку
	if(!CheckAttribute(LAi_MonsterInfo, "model")) return false;	
	if(LAi_MonsterInfo.model == "") return false;
	if(!CheckAttribute(LAi_MonsterInfo, "ani")) LAi_MonsterInfo.ani = defAni;
	if(LAi_MonsterInfo.ani == "") LAi_MonsterInfo.ani = defAni;
	//Создаём фантома и заполняем поля по умолчанию
	// NK -->
	int offset = 0; //note this will be SUBTRACTED later
	int pclevel = GetLevel(GetMainCharacter());
	switch(LAi_MonsterInfo.type)
	{
		// LDH --> 08Dec06 -- make the town monsters stronger
		case "town":
			//offset = intRet(pclevel > 10, makeint(pclevel /2), -TOWN_OFFSET); // TIH must be ints Nov17'06
			//if(offset > 4) offset -= GetOfficersQuantity(GetMainCharacter());
			offset = -TOWN_OFFSET;
			offset -= GetOfficersQuantity(GetMainCharacter());
		break;

		case "house": 
			//offset = intRet(pclevel > 10, makeint(pclevel /2), -TOWN_OFFSET); // TIH must be ints Nov17'06
			offset = -TOWN_OFFSET;
		break;
		// LDH <--
	}
	//trace("Gauging: Create Fantom now:");
	ref chr = LAi_CreateFantomCharacterEx(LAi_MonsterInfo.current=="vagabond", -offset, true, false, false, LAi_MonsterInfo.model, group, locator); // NK - PB: Distinguish between enemies and civilians
	//trace("Gauging: CFC done.");
	// NK -->
	//if(group == "locators.reload")
	if(group == "reload")
	{
		/*float x,y,z;
		float tx,ty,tz;
		GetCharacterPos(chr, &x, &y, &z);
		GetCharacterPos(GetMainCharacter(), &tx, &ty, &tz);
		TeleportCharacterToPos(chr, tx, ty, tz+1.25); // for now. Later will make a loop of it using CheckLocationPosition() to test...
		*/
		//PostEvent("TeleportMonster", 2000, "l", sti(chr.index));
		ChangeCharacterAddressGroup(chr, chr.location, "reload", "reload1");
	}
	// NK <--
	//if(DEBUGINFO) Log_SetStringToLog("Created " + chr.id + ", rank " + GetLevel(chr) + ", (" + chr.name + " " + chr.lastname + ")");
	LAi_CharacterReincarnationEx(chr, true, true, LAi_monsters_group);
	chr.current = ainfo.current; // NK
	/*if(curvag != -1) // NK -->
	{
		chr.curvag = curvag;
		chr.myhouse = location.id;
		chr.name = location.vags.(sCurvag).name;
		chr.lastname = location.vags.lastname; //so all the same lastname
		//unneeeded, in CreatefantomEx - chr.sex = location.vags.(sCurvag).ani;
		chr.rich = location.vags.(sCurvag).rich;
		if(DEBUGINFO) Log_SetStringToLog("All properties restored");
	}
	if(save)
	{
		curvag = 0;
		if(CheckAttribute(location,"vags.quantity")) { curvag = sti(location.vags.quantity); }
		if(DEBUGINFO) Log_SetStringToLog("Saving vagabond " + curvag);
		sCurvag = curvag;
		location.vags.(sCurvag).name = chr.name;
		if(curvag == 0) location.vags.lastname = chr.lastname; // so all the same lastname
		location.vags.(sCurvag).model = LAi_MonsterInfo.model;
		location.vags.(sCurvag).name = LAi_MonsterInfo.ani;
		chr.saverich = sCurvag;
		chr.lastname = location.vags.lastname; //to get lastname
	}*/
	// NK -->
	if(restore)
	{
		chr.myhouse = location.id;
		chr.name = location.vag.name;
		chr.lastname = location.vag.lastname;
		chr.quest.meeting = location.vag.meeting;
		//unneeeded, in CreatefantomEx - chr.sex = location.vags.(sCurvag).ani;
		if(DEBUGINFO) Log_SetStringToLog("All properties restored");
	}
	if(save)
	{
		if(DEBUGINFO) Log_SetStringToLog("Saving vag (" + chr.name + " " + chr.lastname + ").");
		location.vag.meeting = 0;
		location.vag.name = chr.name;
		location.vag.lastname = chr.lastname;
		location.vag.model = LAi_MonsterInfo.model;
		location.vag.ani = LAi_MonsterInfo.ani;
		location.vag.rich = -1;
	}
	LAi_SetWarriorType(chr);
	LAi_warrior_SetStay(chr, true);
	if(LAi_MonsterInfo.current != "vagabond") LAi_group_MoveCharacter(chr, LAI_GROUP_MONSTERS); // NK
	LAi_warrior_SetStay(chr, true); // NK
	//Операемся на уровень персонажа
	//ref mchr = GetMainCharacter();
	//Определяем уровень жизни
	// NK -->
	/*int hp = 20 + rand(5)*10;
	if(CheckAttribute(mchr, "rank") != 0)
	{
		int rank = sti(mchr.rank);
		if(rank < 1) rank = 1;
		hp = hp*(1.0 + rank*0.1);
	}
	LAi_SetHP(chr, hp, hp);
	//Определяем скил фектования
	if(CheckAttribute(mchr, "skill.Fencing") != 0)
	{
		int flevel = sti(mchr.skill.Fencing);
		if(flevel < 1) flevel = 1;
		if(flevel > 10) flevel = 10;
		flevel = rand(flevel) + 1;
		if(flevel > 10) flevel = 10;
		chr.skill.Fencing = flevel;
	}*/
	// NK <--
	//Корректируем поля модельки
	LEnc_MonstersLoginCorrectParams(location, chr, group, locator);
	/*if(save) location.vags.quantity = curvag + 1;
	if(curvag != -1) {curvag++; location.curvag = curvag; }*/
	// Screwface : to have dead skeletons on turks shore ship and hispaniola grots
	if(location.id == "Turks_shore_ship" || location.id == "Hispaniola_Grot3"){chr.chr_ai.hp_max = 0; chr.chr_ai.hp = 0;LAi_CheckKillCharacter(chr);}
	return true;
}


// RM -->
string LAi_SoldierModel(int nat)
{
	//Log_SetStringToLog("isGen");
	string model = "corsair1_2";
	//nat = GetLocationNation(loadedLocation)
	if(nat < 0) nat = PIRATE;
	if(nat >= NATIONS_QUANTITY) nat = PIRATE;
	if(CheckAttribute(&Nations[nat], "fantomModel") == false)
	{
		Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include fantoms");
		return;
	}
	aref fantoms;
	makearef(fantoms, Nations[nat].fantomModel);
	int num = GetAttributesNum(fantoms);
	if(num <= 0)
	{
		Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include have fantoms");
		return;
	}
	num = rand(num - 1);
	string m = GetAttributeName(GetAttributeN(fantoms, num));
	model = fantoms.(m);
	string ani = "man";
	m = m + ".ani";
	if(CheckAttribute(fantoms, m) != false)
	{
		ani = fantoms.(m);
	}
	return model;
}
// RM <--


//Создать фантома основываясь на характуристиках данного персонажа в самом дальнем углу
void LAi_GenerateFantomFromMe(aref chr)
{
	//TraceAndLog("Start GenFMM, old char id " + chr.id + ", model = " + chr.model);
	//Проверяем возможность генерации фантома в данной локации
	if(!TestRef(loadedLocation)) return;
	if(!IsEntity(loadedLocation)) return;
	if(LAi_LocationIsFantomsGen(loadedLocation) == false) return;
	//Проверяем возможность перерождения персонажа
	if(LAi_CharacterIsReincarnation(chr) == false) return;
	if(CheckAttribute(GetMainCharacter(),"quest.kill_all_soldiers_in_prison")) return; // NK
	if(CheckAttribute(chr,"corpse")) return; // 05-07-12 fix for corpses, just in case.
	//Проверяем какую модельку использовать для перерождения
	bool isGen = LAi_CharacterReincarnationMode(chr);
	if(CheckAttribute(chr, "model") == false) isGen = true;
	if(CheckAttribute(chr, "model.animation") == false) isGen = true;
	if(chr.model == "") isGen = true;
	if(chr.model.animation == "") isGen = true;
	string model, ani;
	model = chr.model;
	ani = chr.model.animation;
	//NK -->
	if(!CheckAttribute(chr,"origID"))
	{
		chr.origID = chr.id;
	}
	bool hasblade = CheckAttribute(chr,"equip.blade");
	//string oldblade = "";
	/*if(hasblade)
	{
		oldblade = chr.equip.blade;
		//TraceAndLog("Blade = " + oldblade);
	}*/
	bool hasgun = CheckAttribute(chr,"equip.gun");
	/*string oldgun = "";
	if(hasgun)
	{
		oldgun = chr.equip.gun;
		//TraceAndLog("Gun = " + oldgun);
	}*/
	if(!hasgun) if(hasblade && rand(sti(Characters[GetMainCharacterIndex()].rank)) > 5) hasgun = true;
	// NK <--
	if(isGen)
	{
		//TraceAndLog("isGen");
		int nat = GetLocationNation(loadedLocation);
		if(nat < 0 || nat >= NATIONS_QUANTITY) nat = PIRATE;
		// NK modeltypes 05-07-11
		if(ModelIsType(chr.model, "Land_Officers"))
		{
			model = GetRandomModelForTypeNation(true, "Land_Officers", nat);
		}
		else
		{
			model = GetRandomModelForTypeNation(true, "Soldiers", nat);
		}
		/*if(CheckAttribute(&Nations[nat], "fantomModel") == false)
		{
			Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include fantoms");
			return;
		}
		aref fantoms;
		makearef(fantoms, Nations[nat].fantomModel);
		int num = GetAttributesNum(fantoms);
		if(num <= 0)
		{
			Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include have fantoms");
			return;
		}
		num = rand(num - 1);
		string m = GetAttributeName(GetAttributeN(fantoms, num));
		model = fantoms.(m);
		ani = "man";
		m = m + ".ani";
		if(CheckAttribute(fantoms, m) != false)
		{
			ani = fantoms.(m);
		}*/
	}
	//traceandlog("gffm for character " + chr.id + " of model " + chr.model + " we now have model " + model);
	//Сохраняем параметры персонажа
	object tmp;
	CopyAttributes(&tmp, chr);
	//Создаём фантома	
	// NK -->
	// 05-05-10 add friend
	bool wasfriend = false;
	if(CheckAttribute(chr,"friend")) wasfriend = sti(chr.friend);
	ref fnt = LAi_CreateFantomCharacterEx(wasfriend, 0, false, false, false, model, LAi_CharacterReincarnationGroup(chr), ""); // NK
	string curidx = fnt.index;
	//Устанавливаем параметры предыдущего персонажа
	CopyAttributes(fnt, &tmp);
	if(DEBUG_EXPERIENCE>0) TraceAndLog("LAi_GenerateFantomFromMe: Set officer type for " + GetMySimpleName(fnt));
	fnt.quest.officertype = OFFIC_TYPE_RANDCHAR;
	LAi_Create_Officer(0, fnt);
	DeleteAttribute(fnt, "items"); // clear out items
	LAi_NPC_Equip(fnt, sti(fnt.rank), hasblade, floatRet(hasgun,0.5+frnd()/2.0,frnd()/2.0));
	SetRandomNameToCharacter(fnt);
	if(LAi_CharacterReincarnationMode(fnt)) CopyAttributes(CharacterFromID(chr.origID),fnt);
	//TraceAndLog("Blade = " + fnt.equip.blade + "; Gun: " + fnt.equip.gun);
	// NK <--
	LAi_SetCurHPMax(fnt);
	string chrgroup = ""; // NK move this to bottom just in case type screws it up. 05-07-12
	if(CheckAttribute(fnt, "chr_ai.group"))
	{
		chrgroup = fnt.chr_ai.group;
	}
	//Сохраняем модельку и анимацию
	// NK check for stunned 05-07-12
	if(CheckAttribute(fnt, "stuntime"))
	{
		fnt.stuntime.old_type_resume = true;
		LAi_Stunned_AwakenCharacter(fnt);
	}
	// NK <--
	fnt.model = model;
	fnt.model.animation = ani;
	//Инициализируем тип
	if(!CheckAttribute(fnt, "chr_ai.type")) fnt.chr_ai.type = "";	
	string chrtype = fnt.chr_ai.type;
	//SetRandomNameToCharacter(fnt); // NK
	fnt.id = tmp.id;
	fnt.index = curidx;
	fnt.chr_ai.type = "";
	if(chrtype != "")
	{
		chrtype = "LAi_type_" + chrtype + "_Init";
		call chrtype(fnt);
	}
	else LAi_tmpl_stay_InitTemplate(fnt); // NK move this below _and into else_ in case it screws up swords. 05-07-12
	// NK -->
	if(hasblade) EquipCharacterByItem(&fnt, FindCharacterItemByGroup(&fnt, BLADE_ITEM_TYPE));
	if(hasgun) EquipCharacterByItem(&fnt, FindCharacterItemByGroup(&fnt, GUN_ITEM_TYPE));
	EquipCharacterByItem(&fnt, FindCharacterItemByGroup(&fnt, ARMOR_ITEM_TYPE)); // armor too
	//TraceAndLog("Done GFFM");
	LAi_group_MoveCharacter(fnt, chrgroup); // NK move here
	// now, copy name, model, items, equip. NK 05-07-11 -->
	if(!CheckAttribute(chr, "origchar")) fnt.origchar = chr.index;
	else fnt.origchar = chr.origchar;
	aref ato, afrom;
	chr = GetCharacter(sti(fnt.origchar));
	chr.name = fnt.name;
	if(CheckAttribute(fnt, "middlename")) chr.middlename = fnt.middlename;
	chr.lastname = fnt.lastname;
	chr.sex = fnt.sex;
	makearef(afrom, fnt.model); makearef(ato, chr.model);
	CopyAttributes(&ato, &afrom);
	makearef(afrom, fnt.equip); makearef(ato, chr.equip);
	CopyAttributes(&ato, &afrom);
	DeleteAttribute(chr, "items");
	chr.items = "";
	makearef(afrom, fnt.items); makearef(ato, chr.items);
	CopyAttributes(&ato, &afrom);
	// NK <--
}

bool LAi_CreateEncounters(ref location)
{
	bool retValue = false;
	string encGroup, str;
	aref grp;
	int num = 0;
	for(int i = 0; i < 5; i++)
	{
		//Выбираем группу локаторов
		encGroup = LAi_FindRandomLocator("encdetector");
		if(encGroup == "") return retValue;
		//Проверяем на существование
		if(CheckAttribute(location, "locators." + encGroup))
		{
			//Проверим на содержание локатотров
			str = "locators." + encGroup;
			makearef(grp, location.(str));
			num = GetAttributesNum(grp);			
			if(num > 0) break;
		}
	}
	if(num <= 0) return retValue;
	//Максимально возможное количество персонажей в энкоунтере
	int maxChr = 16 - LAi_numloginedcharacters;
	if(maxChr <= 0) return retValue;
	if(maxChr > num) maxChr = num;
	//Есть группа пробуем завести энкоунтеров
	if(!LEnc_LoginStart(location, "encdetector", encGroup, maxChr)) return retValue;
	//Начинаем перебирать локаторы и логинить фантомов
	for(i = 0; i < maxChr; i++)
	{
		//Получим локатор для логина
		string locator = GetAttributeName(GetAttributeN(grp, i));
		//Запросим модель
		string defModel = "man1";
		string defAni = "man";
		LAi_MonsterInfo.model = defModel;
		LAi_MonsterInfo.ani = defAni;
		LAi_MonsterInfo.friend = false;
		LAi_MonsterInfo.sex = "";
		aref ainfo;
		makearef(ainfo, LAi_MonsterInfo);
		LEnc_LoginSelectModel(location, ainfo, encGroup, locator);
		ainfo.current = ainfo.model;
		bool swd = sti(ainfo.sword);
		float pst = stf(ainfo.pistol); // NK
		//Log_SetStringToLog("s" + swd + " p" + pst)
		//Проверим модельку
		if(!CheckAttribute(LAi_MonsterInfo, "model")) break;
		if(LAi_MonsterInfo.model == "") break;
		/*if(!CheckAttribute(LAi_MonsterInfo, "ani")) LAi_MonsterInfo.ani = defModel;
		if(LAi_MonsterInfo.ani == "") LAi_MonsterInfo.ani = defModel;*/
		//Создаём фантома
		// NK modeltypes 05-07-09 -->
		if(GetModelindex(ainfo.model) == -1) ainfo.model = GetRandomModelForTypeExSubCheck(sti(ainfo.iscombat), ainfo.model, ainfo.sex, sti(ainfo.nation));
		ref cmodel = &Models[GetModelIndex(ainfo.model)];
		ainfo.ani = cmodel.ani;
		ainfo.sex = cmodel.sex;
		ref chr = LAi_CreateFantomCharacterEx(sti(ainfo.friend), 0, true, swd, pst, LAi_MonsterInfo.model, encGroup, locator); // NK
		chr.current = ainfo.current;
		// NK <--
		//Log_SetStringtoLog(chr.equip.blade);
		//Скорректируем параметры
		LEnc_LoginCorrectParams(location, chr, encGroup, locator);
		retValue = true;
		//Прекращение логина
		if(!LEnc_IsContinueLogin(location, chr, encGroup, locator)) break;
	}
	//Завершить загрузку энкоунтера в локацию
	LEnc_LoginEnd(location, "encdetector", encGroup);
	return retValue;
}
