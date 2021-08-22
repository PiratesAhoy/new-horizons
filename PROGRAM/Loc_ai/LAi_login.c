// KK -->
#define MAX_LOGINED_CHARACTERS_IN_LOCATION 32

int LAi_loginedcharacters[MAX_LOGINED_CHARACTERS_IN_LOCATION];
int LAi_numloginedcharacters = 0;
// <-- KK

bool LAi_CharacterLogin(aref chr, string locID)
{
	string func;
	//Проверим адрес логина
	if(CheckAttribute(chr, "location") == false)
	{
		Trace("Character <" + chr.id + "> have not field [location]");
		return false;
	}
	if(CheckAttribute(chr,"storedAttributes") && CharacterRebirth(chr)==false) { DeleteCharacter(chr); return false; }
	bool isLogin = false;
	// 04-12-05 this is making things worse bool always = false; // NK 04-11-10 override
	if(chr.location == locID)
	{
		if(sti(chr.index) == GetMainCharacterIndex()) isLogin = true;
		if(CheckAttribute(chr, "location.stime") != false)
		{
			if(CheckAttribute(chr, "location.etime") != false)
			{
				//Проверям время логина
				if(LAi_login_CheckTime(stf(chr.location.stime), stf(chr.location.etime))) isLogin = true;
			}else isLogin = true;
		}else isLogin = true;
	}
	//Проверяем возможность нахождения в церкви
	if(CheckAttribute(chr, "location.church") != false)
	{
		if(chr.location.church == locID)
		{
			//Проверям время нахождения в церкви
			if(CheckAttribute(chr, "location.church.stime") != false)
			{
				if(CheckAttribute(chr, "location.church.etime") != false)
				{
					//Проверям время нахождения в церкви
					if(LAi_login_CheckTime(stf(chr.location.church.stime), stf(chr.location.church.etime))) isLogin = true;
				}
			}
		}
	}
	//Залогинем последователей
	if(!LAi_IsBoarding)
	{
		// 04-12-05 this is making things worse if(CheckAttribute(chr,"alwaysload")) { if(sti(chr.alwaysload)) { isLogin = true; always = true; } } // NK 04-11-10 add alwaysload override
		if(CheckAttribute(chr, "location.follower") != false)
		{
			ref mcref = GetMainCharacter();
			chr.location = mcref.location;
			chr.location.group = mcref.location.group;
			chr.location.locator = mcref.location.locator;
			isLogin = true;
			if(LAi_restoreStates)
			{
				LAi_SetCurHPMax(chr);
			}
		}
	}
	//Проверим на захваченность локации
	if(LAi_IsCapturedLocation)
	{
		if(GetMainCharacterIndex() != sti(chr.index)) // 04-12-05 this is making things worse && !always) // NK 04-11-10 allow override
		{
			for(int i_ofc = 1; i_ofc < OFFICER_MAX; i_ofc++)
			{
				int idx = GetOfficersIndex(GetMainCharacter(), i_ofc);
				if(idx == sti(chr.index)) break;
			}
		}
	}
	if(!isLogin) return false;
	//Если персонажей больше максимального числа, незагружаем больше
	if(LAi_numloginedcharacters >= MAX_LOGINED_CHARACTERS_IN_LOCATION)
	{
		Trace("LAi_CharacterLogin -> many logined characters in location (>" + MAX_LOGINED_CHARACTERS_IN_LOCATION + ")");
		return false;
	}
	//Устанавливаем необходимые поля, если надо
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		chr.chr_ai.type = LAI_DEFAULT_TYPE;
	}
	if(CheckAttribute(chr, "chr_ai.tmpl") == false)
	{
		chr.chr_ai.tmpl = LAI_DEFAULT_TEMPLATE;
	}
	if(CheckAttribute(chr, "chr_ai.group") == false)
	{
		chr.chr_ai.group = LAI_DEFAULT_GROUP;
	}
	if(CheckAttribute(chr, "chr_ai.alarmreact") == false)
	{
		chr.chr_ai.alarmreact = LAI_DEFAULT_ALARMREACT;
	}
	if(CheckAttribute(chr, "chr_ai.grpalarmr") == false)
	{
		chr.chr_ai.grpalarmr = LAI_DEFAULT_GRPALARMR;
	}
	if(CheckAttribute(chr, "chr_ai.hp") == false)
	{
		chr.chr_ai.hp = LAI_DEFAULT_HP;
	}
	if(CheckAttribute(chr, "chr_ai.hp_max") == false)
	{
		chr.chr_ai.hp_max = LAI_DEFAULT_HP_MAX;
	}
	if(CheckAttribute(chr, "chr_ai.charge") == false)
	{
		chr.chr_ai.charge = LAI_DEFAULT_CHARGE;
	}
	//Проверяем хитпойнты
	float hp = stf(chr.chr_ai.hp);
	float hpmax = stf(chr.chr_ai.hp_max);
	if(hpmax < 1) hpmax = 1;
	chr.chr_ai.hp_max = hpmax;
	if(hp > hpmax) hp = hpmax;
	if(hp < 0) hp = 0;
	chr.chr_ai.hp = hp;
	if(!actLoadFlag)
	{
		if(hp < 1)
		{
			if(CheckAttribute(chr, "location.norebirth") != false)
			{
				if(sti(chr.location.norebirth) != 0) return false;
			}
			//Надо возраждать персонажа
			chr.chr_ai.hp = hpmax;
			hp = hpmax;
			SetRandomNameToCharacter(chr);
			func = chr.chr_ai.type;
			chr.chr_ai.type = "";
			chr.chr_ai.tmpl = "";
			if(func != "")
			{
				func = "LAi_type_" + func + "_Init";
				call func(chr);
			}
		}
	}
	if(hp < 1) return false;
	//Проверяем персонажа
	if(LAi_CheckCharacter(chr, "LAi_CharacterLogin") == false) return false;
	//Выставляем скилл для сражения
	//LAi_AdjustFencingSkill(chr); //Levis: Not needed anymore
	RestoreCharacter(chr);//MAXIMUS: returns stored attributes
	//Логиним персонажа
	func = chr.chr_ai.type;
	bool res = true;
	if(func != "")
	{
		func = "LAi_type_" + func + "_CharacterLogin";
		res = call func(chr);
	}
	if(res == false) return false;
	chr.chr_ai.login = true;
	LAi_AddLoginedCharacter(chr);
	return true;
}

void LAi_CharacterPostLogin(ref location)
{
	//Расставляем последователей
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		if(bDeckStarted || bCrewStarted) break;//MAXIMUS: login was enabled in LAi_Init.c, but not needs here
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			//Просматриваем последователей
			ref chr = &Characters[idx];
			if(CheckAttribute(chr, "location.follower") != false)
			{
				//Получим координаты игрока
				float x, y, z;
				if(GetCharacterPos(GetMainCharacter(), &x, &y, &z) == false)
				{
					x = 0.0; y = 0.0; z = 0.0;
				}
				//Ищем свободный ближайший локатор
				string locator = LAi_FindNearestFreeLocator("goto", x, y, z);
				if(locator != "")
				{
					TeleportCharacterToLocator(chr, "goto", locator)
					CharacterTurnByChr(chr, GetMainCharacter());
				}else{
					Trace("Can't find good locator for follower character <" + chr.id + ">");
				}
			}
		}
	}
	if(!actLoadFlag)
	{
		//Расставляем квестовых энкоунтеров
		if(!LAi_CreateEncounters(location))
		{
			//Расставляем монстров
			LAi_CreateMonsters(location);
		}
	}
}

bool LAi_CharacterLogoff(aref chr)
{
	// LDH --> moved from below Aug29'06
	if(!CheckAttribute(chr, "index")) {
		Trace("Warning: Invalid character index in LAi_CharacterLogoff(), function returned false");
		return false; 
	}
	// LDH <--
	// NK handle stunned character logoffs for use in next logon 05-07-12
	if(sti(chr.index) <= CHARACTERS_QUANTITY) // to skip fantoms
	{
		if(CheckAttribute(chr, "stuntime") || CheckAttribute(chr, "first_oldtype"))
		{
			if(CheckAttribute(chr, "first_oldtype")) { chr.stuntime.old_type = chr.first_oldtype; DeleteAttribute(&chr, "first_oldtype"); }
			chr.stuntime.old_type_resume = true;
			LAi_StunnedStandsUp(chr); // PB
		}
	}
	// NK <--
	chr.chr_ai.login = false;	
	if(LAi_CheckCharacter(chr, "LAi_CharacterLogoff") == false) return false; // LDH - moved above
	LAi_DelLoginedCharacter(chr);
	string func = chr.chr_ai.type;
	bool res = true;
	if(func != "")
	{
		func = "LAi_type_" + func + "_CharacterLogoff";
		res = call func(chr);
	}
	if(res == false) return false;
	return true;
}

void LAi_AddLoginedCharacter(aref chr)
{
	int index = sti(chr.index);
	LAi_loginedcharacters[LAi_numloginedcharacters] = index;
	LAi_numloginedcharacters = LAi_numloginedcharacters + 1;
	CheckCharacterCurse(chr); // PB: Cursed Coins
}

void LAi_DelLoginedCharacter(aref chr)
{
	int index = sti(chr.index);
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		if(LAi_loginedcharacters[i] == index)
		{
			LAi_loginedcharacters[i] = LAi_loginedcharacters[LAi_numloginedcharacters - 1];
			LAi_numloginedcharacters = LAi_numloginedcharacters - 1;
		}		
	}
	if(LAi_numloginedcharacters < 0) LAi_numloginedcharacters = 0;
}

bool LAi_login_CheckTime(float start, float end)
{
	float curTime = GetTime();
	if(start <= end)
	{
		if((curTime >= start) && (curTime <= end)) return true;
	}else{
		if(curTime >= start) return true;
		if(curTime <= end) return true;
	}
	return false;
}

void LAi_PostLoginInit(aref chr)
{
	if(!IsEntity(chr)) return;
	//Добавляем в группу
	LAi_group_MoveCharacter(chr, chr.chr_ai.group);
	//Инициализируем шаблон
	string func = chr.chr_ai.tmpl;
	if(func != "")
	{
		func = "LAi_tmpl_" + func + "_InitTemplate";
		bool res = call func(&chr);
		if(res == false)
		{
			chr.chr_ai.tmpl = LAI_DEFAULT_TEMPLATE;
		}
	}
	//Инициализируем тип
	func = chr.chr_ai.type;
	if(func != "")
	{
		func = "LAi_type_" + func + "_Init";
		call func(&chr);
	}
	//Update the contriblist and skill multipliers and do auto level up for NPC's
	InitAutoSkillsSystem(chr, true); //Levis, the check for autoskill will happen later.
	if(CheckAttribute(chr,"ContribList")) DeleteAttribute(chr,"ContribList")); //Levis refresh contriblist on login
	DeleteAttribute(&PostInitQueue,"restorelist"); //Levis: Because everything is restored by the autoskill system already now
}


