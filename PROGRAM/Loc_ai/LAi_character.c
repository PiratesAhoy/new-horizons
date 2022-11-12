
//------------------------------------------------------------------------------------------
//Login
//------------------------------------------------------------------------------------------

//Установить время загрузки персонажа
void LAi_SetLoginTime(aref chr, float start, float end)
{
	if(start < 0) start = 0;
	if(start >= 24) start = 23.99999999;
	if(end < 0) end = 0;
	if(end >= 24) end = 23.99999999;
	chr.location.stime = start;
	chr.location.etime = end;
}

//Удалить время загрузки персонажа
void LAi_RemoveLoginTime(aref chr)
{
	aref loc;
	makearef(loc, chr.location);
	DeleteAttribute(loc, "stime");
	DeleteAttribute(loc, "etime");
}

//Данный персонаж является верующим, и в определённое время находиться в церкви
void LAi_SetFanatic(aref chr, string churchID, string group, string locator, float start, float end)
{
	chr.location.church = churchID;
	chr.location.church.group = group;
	chr.location.church.locator = locator;
	chr.location.church.stime = start;
	chr.location.church.etime = end;
}

//Сделать обычным персонаж
void LAi_RemoveFanatic(aref chr)
{
	aref loc;
	makearef(loc, chr.location);
	DeleteAttribute(loc, "church");
}

//Запретить перерождение персонажа после убийства /Forbids character's rebirth after kill/
void LAi_NoRebirthEnable(aref chr)
{
	chr.location.norebirth = "1";
}

//Разрешить перерождение персонажа после убийства /Allows character's rebirth after kill/
void LAi_NoRebirthDisable(aref chr)
{
	aref loc;
	makearef(loc, chr.location);
	DeleteAttribute(loc, "norebirth");
}

//Проверить возможность возрождения персонажа после убийства /Checks up possibility of character's rebirth after kill/
bool CharacterRebirth(aref chr)
{
	if(CheckAttribute(chr,"location.norebirth") && sti(chr.location.norebirth)==1) return false;
	return true;
}

//Разрешить/запретить персонажу загружаться в захваченную локацию
void LAi_LoginInCaptureTown(aref chr, bool isEnable)
{
	aref loc;
	makearef(loc, chr.location);
	if(isEnable)
	{
		loc.loadcapture = "1";
	}else{
		DeleteAttribute(loc, "loadcapture");
	}
}

//------------------------------------------------------------------------------------------
//Fight, hp
//------------------------------------------------------------------------------------------

//Установить хитпойнты
void LAi_SetHP(aref chr, float cur, float max)
{
	if(max < 1) max = 1;
	if(cur < 0) cur = 0;
	if(cur > max) cur = max;

	chr.chr_ai.hp = cur;
	chr.chr_ai.hp_max = max;
// KK -->
	chr.old.chr_ai.hp = cur;
	chr.old.chr_ai.hp_max = max;
// <-- KK
}

//Установить текущии хитпойнты
void LAi_SetCurHP(aref chr, float cur)
{
	float maxHP = LAI_DEFAULT_HP_MAX;
	if(CheckAttribute(chr, "chr_ai.hp_max"))
	{
		maxHP = stf(chr.chr_ai.hp_max);
		if(maxHP < 1) maxHP = 1;
	}
	chr.chr_ai.hp_max = maxHP;
	if(cur < 0) cur = 0;
	if(cur > maxHP) cur = maxHP;
	chr.chr_ai.hp = cur;
}

//Установить текущии хитпойнты максимальными
void LAi_SetCurHPMax(aref chr)
{
	float maxHP = LAI_DEFAULT_HP_MAX;
	if(CheckAttribute(chr, "chr_ai.hp_max"))
	{
		maxHP = stf(chr.chr_ai.hp_max);
		if(maxHP < 1) maxHP = 1;
	}	
	chr.chr_ai.hp_max = maxHP;
	chr.chr_ai.hp = maxHP;
}

//Скорость изменения хп в секунду
void LAi_SetDltHealth(aref chr, float healthPerSec)
{
	//if(healthPerSec < 0) healthPerSec = 0;
	chr.chr_ai.hp_dlt = healthPerSec;
}

//Использовать бутылочку-лечилку
void LAi_UseHealthBottle(aref chr, float healthInBottle)
{
//	if(healthInBottle <= 0) return; // Blocks leeches from giving health drop
	if(healthInBottle == 0) return; // Only quit if 0 health, i.e. no effect
	if(CheckPerkForGroup(chr, "ImprovePotions") && healthInBottle>0) healthInBottle = healthInBottle * 1.1;//partywide boost, not for leeches!
	if(!CheckAttribute(chr, "chr_ai.hp_bottle"))
	{
		chr.chr_ai.hp_bottle = "0";
	}
	chr.chr_ai.hp_bottle = stf(chr.chr_ai.hp_bottle) + healthInBottle;
}

//Использовать бутылочку-противоядие
void LAi_UseAtidoteBottle(aref chr)
{
	DeleteAttribute(chr, "chr_ai.poison");
	DeleteAttribute(chr, "chr_ai.curare");
}

//Отравлен
bool LAi_IsPoison(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.poison")) return true;
	return false;
}

//JRH slower poisoning for mainchar
bool LAi_IsCurare(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.curare")) return true;
	return false;
}

//Сделать персонажа бессмертным
void LAi_SetImmortal(aref chr, bool isImmortal)
{
	if(isImmortal)
	{
		chr.chr_ai.immortal = "1";
	}else{
		aref chr_ai;
		makearef(chr_ai, chr.chr_ai);
		DeleteAttribute(chr_ai, "immortal");
	}
}

//Узнать отношение персонажа к бессмертию
bool LAi_IsImmortal(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.immortal"))
	{
		if(sti(chr.chr_ai.immortal) != 0)
		{
			return true;
		}
	}
	return false;
}

// KK -->
void LAi_SetCrewImmortal(aref chr, bool isImmortal)
{
	if (!CheckAttribute(chr, "Ship.Crew")) return;
	if (isImmortal) {
		chr.Ship.Crew.immortal = true;
	} else {
		aref crew; makearef(crew, chr.Ship.Crew);
		DeleteAttribute(crew, "immortal");
	}
}

bool LAi_IsCrewImmortal(aref chr)
{
	if (!CheckAttribute(chr, "Ship.Crew")) return false;
	aref crew; makearef(crew, chr.Ship.Crew);
	if (!CheckAttribute(crew, "immortal")) return false;
	return sti(crew.immortal);
}
// <-- KK

//Получить хп персонажа
float LAi_GetCharacterHP(aref chr)
{
	float curHp = 0.0;
	if(CheckAttribute(chr, "chr_ai.hp"))
	{
		curHp = stf(chr.chr_ai.hp);
	}
	float maxHp = LAi_GetCharacterMaxHP(chr);
	if(curHp > maxHp) curHp = maxHp;
	chr.chr_ai.hp = curHp;
	chr.chr_ai.hp_max = maxHp;
	return curHp;
}

//Получить максимальные хп персонажа
float LAi_GetCharacterMaxHP(aref chr)
{
	float max_hp = 0.0;
	if(CheckAttribute(chr, "chr_ai.hp_max"))
	{
		max_hp = stf(chr.chr_ai.hp_max);
	}
	if(max_hp < 0.0) max_hp = 0.0;
	chr.chr_ai.hp_max = max_hp;
	return max_hp;
}

//Получить относительные хп персонажа 0..1
float LAi_GetCharacterRelHP(aref chr)
{
	float hp = LAi_GetCharacterHP(chr);
	float maxhp = LAi_GetCharacterMaxHP(chr);
	if(maxhp <= 0.0) return 0.0;
	if(maxhp > 0.0)
	{
		return hp/maxhp;
	}
	return 0.0;
}

float LAi_GetCharacterRelEnergy(aref chr)
{
	float energy = 0.0;
	if(CheckAttribute(chr, "chr_ai.energy"))
	{
		energy = stf(chr.chr_ai.energy);
		energy = energy / LAi_GetCharacterMaxEnergy(chr); // boal
	}
	return energy;
}

float LAi_GetCharacterMaxEnergy(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.energyMax"))
	{
		return stf(chr.chr_ai.energyMax);
	}
	return LAI_DEFAULT_ENERGY_MAX;
}

//Установить проверяльщик хп, если их становиться меньше чем, вызвать квест
void LAi_SetCheckMinHP(aref chr, float min, bool immortal, string quest)
{
	if(min < 0.9999999) min = 0.9999999;
	chr.chr_ai.hpchecker = min;
	chr.chr_ai.hpchecker.quest = quest;
	chr.chr_ai.hpchecker.immortal = immortal;
}

//Удалить проверяльщик хп
void LAi_RemoveCheckMinHP(aref chr)
{
	aref chr_ai;
	makearef(chr_ai, chr.chr_ai);
	DeleteAttribute(chr_ai, "hpchecker");	
}

//Убить персонажа
void LAi_KillCharacter(aref chr)
{
	chr.chr_ai.hp = "0";
	if(LAi_IsImmortal(chr))
	{
		string old = chr.chr_ai.immortal;
		chr.chr_ai.immortal = "0";
		LAi_CheckKillCharacter(chr);
		chr.chr_ai.immortal = old;
	}else{
		LAi_CheckKillCharacter(chr);
	}
}

//Убит ли персонаж
bool LAi_IsDead(aref chr)
{
	bool bDead = false;
	if (CheckAttribute(chr, "chr_ai.hp") == false) 
	{
		bDead = true;
	}
	else
	{
		if (stf(chr.chr_ai.hp) < 1.0) bDead = true;
	}
	//JRH -->
	if (bDead && !IsMainCharacter(chr))
	{
		if(CheckCharacterItem(chr, "blademketK"))
		{
			RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
			TakeItemFromCharacter(chr, "blademketK");
			GiveItem2Character(chr, "blade_mKnife");
			GiveItem2Character(chr, "pistolmket");
			EquipCharacterByItem(chr, "blade_mKnife");
			EquipCharacterByItem(chr, "pistolmket");
		}

		if(CheckCharacterItem(chr, "blademketB"))
		{
			RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(chr, "blademketB");
			GiveItem2Character(chr, "pistolmketB");
			if(!CheckCharacterItem(chr,"bladeX4"))
			{
				GiveItem2Character(chr,"bladeX4");
			}
			EquipCharacterByItem(chr, "bladeX4");
			EquipCharacterByItem(chr, "pistolmketB");
		}
	}
	//<-- JRH
	return bDead;
}


//------------------------------------------------------------------------------------------
//Other
//------------------------------------------------------------------------------------------

//Является ли персонаж управляемым
bool LAi_IsCharacterControl(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.tmpl"))
	{
		if(chr.chr_ai.tmpl == LAI_TMPL_PLAYER) return true;
	}
	return false;
}

//Запретить диалог с персонажем
void LAi_CharacterDisableDialog(aref chr)
{
	chr.chr_ai.disableDlg = "1";
}

//Разрешить диалог с персонажем
void LAi_CharacterEnableDialog(aref chr)
{
	chr.chr_ai.disableDlg = "0";
}

//Разрешить при смерти порождить фантома
void LAi_CharacterReincarnation(aref chr, bool isEnable, bool isUseCurModel)
{
	LAi_CharacterReincarnationEx(chr, isEnable, isUseCurModel, "");
}

//Разрешить при смерти порождить фантома
void LAi_CharacterReincarnationEx(aref chr, bool isEnable, bool isUseCurModel, string locgroup)
{
	if(isEnable)
	{
		if(isUseCurModel)
		{
			chr.chr_ai.reincarnation = "0";
		}else{
			chr.chr_ai.reincarnation = "1";
		}
		if(locgroup == "") locgroup = "goto";
		chr.chr_ai.reincarnation.group = locgroup;
	}else{
		chr.chr_ai = "";
		aref chr_ai;
		makearef(chr_ai, chr.chr_ai);
		DeleteAttribute(chr_ai, "reincarnation");
	}	
}

bool LAi_CharacterIsReincarnation(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.reincarnation") == false) return false;
	return true;
}

bool LAi_CharacterReincarnationMode(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.reincarnation") == false)
	{
		Trace("LAi_CharacterReincarnationMode -> no field chr.chr_ai.reincarnation");
		return false;
	}
	if(sti(chr.chr_ai.reincarnation) != 0) return true;
	return false;
}

string LAi_CharacterReincarnationGroup(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.reincarnation.group") == false)
	{
		Trace("LAi_CharacterReincarnationGroup -> no field chr.chr_ai.reincarnation");
		return "goto";
	}
	if(chr.chr_ai.reincarnation.group != "") return chr.chr_ai.reincarnation.group;
	return "goto";
}

//Скил fencing для персонажа при логине выставляется относительно игрока
/*void LAi_SetAdjustFencingSkill(aref chr, float min, float max)
{
	if(min > max) min = max;
	chr.chr_ai.fencing.min = min;
	chr.chr_ai.fencing.max = max; // NK
}

//Удалить выставлялку скила
void LAi_DelAdjustFencingSkill(aref chr)
{
	aref chr_ai;
	makearef(chr_ai, chr.chr_ai);
	DeleteAttribute(chr_ai, "fencing");
}

void LAi_AdjustFencingSkill(aref chr)
{
	if(sti(chr.index) == GetMainCharacterIndex()) return;
	if(CheckAttribute(chr, "chr_ai.fencing.min"))
	{
		if(CheckAttribute(chr, "chr_ai.fencing.max"))
		{
			ref mc = GetMainCharacter();
			//skill
			float min = stf(chr.chr_ai.fencing.min);
			float max = stf(chr.chr_ai.fencing.max);
			float cur = 1.0;
			if(CheckAttribute(mc, "skill.fencing"))
			{
				cur = makefloat(CalcCharacterSkill(mc,SKILL_FENCING)); // NK
			}
			cur = cur + min + 0.1*(max - min)*rand(10) + 0.5;
			if(cur < 1.0) cur = 1.0;
			if(cur > 10.0) cur = 10.0;
			chr.skill.fencing = MakeInt(cur);
			//hp
			float hp = LAi_GetCharacterHP(mc);
			cur = 1.0 + (min + 0.1*(max - min)*rand(10))*0.2;
			if(cur < 0.2) cur = 0.2;
			if(cur > 5.0) cur = 5.0;
			hp = hp*cur;
			LAi_SetHP(chr, hp, hp);
			LAi_NPC_Equip(chr, sti(chr.rank), true, 0.0);
		}
	}
}*/
//Levis: Not used anymore

//------------------------------------------------------------------------------------------
//Other
//------------------------------------------------------------------------------------------

//Проиграть звук
void LAi_CharacterPlaySound(aref chr, string soundname)
{
	// LDH This shouldn't be happening, but it's here until we can get all the .wav sounds into the sounds_alias.ini file - 24Mar09
	// the problem is mostly with pistol sounds at the moment
	/*if (strRight(soundname, 4) == ".wav")
	{
// KK -->
		float u, v, w;
		if (GetCharacterPos(chr, &u, &v, &w))
			Play3DSound(soundname, u, v, w);
		else
			SendMessage(chr, "s", Sound_GetName(soundname));//MAXIMUS
// <-- KK
		return;
	}*/

	if (strLeft(soundname,3) == "Gr_")
		PlayVoice(chr, soundname);		// LDH plays sound at voice volume - 18Mar09
	else
	{
		if (LAi_IsDead(chr))	// LDH need this to play "body" sounds when dead character falls - 22Mar09
			SendMessage(chr, "s", soundname);	// LDH this plays at the right volume but the wrong location
		else
			PlayCharacterSound(chr, soundname);	// LDH plays sound at soundFX volume - 19Mar09
	}
}

//Переключиться в режим боя и обратно
void LAi_SetFightMode(aref chr, bool isFightMode)
{
	SendMessage(chr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", isFightMode);
//	PostEvent("evntBLI_Update",BLI_UPDATE_PERIOD);//MAXIMUS: makes box from corpse with hand-icon in the top-left corner
}

//Заблокировать текущий режим (!!! сбрасывается при смене шаблона !!!)
void LAi_LockFightMode(aref chr, bool isLockFightMode)
{
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "LockFightMode", isLockFightMode);
//	PostEvent("evntBLI_Update",BLI_UPDATE_PERIOD);//MAXIMUS: makes box from corpse with hand-icon in the top-left corner
}

//------------------------------------------------------------------------------------------
//Weapons
//------------------------------------------------------------------------------------------


//Получить относительный заряд пистолета
float LAi_GetCharacterRelCharge(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.charge"))
	{
		if(CheckAttribute(chr, "chr_ai.chargeprc"))
		{
			if(sti(chr.chr_ai.chargeprc))
			{
				if(!CheckAttribute(chr, "chr_ai.charge_max")) return 0.0;
				float charge = stf(chr.chr_ai.charge);
				float chargemax = stf(chr.chr_ai.charge_max);
				//MAXIMUS: with amount of charges less than maximum, we need less time for loading gun -->
				if(ENABLE_AMMOMOD==1)
				{
					if(IsMaincharacter(chr) || IsOfficer(chr))	//JRH: NOT everyone else
					{
						charge = RecalcCharacterGun(chr);
						chargemax = GetCurrentCharacterGunMax(chr);
					}
				}
				//MAXIMUS: with amount of charges less than maximum, we need less time for loading gun <--
				if(chargemax <= 0) return 0.0;
				if(charge >= chargemax) charge = chargemax;
				charge = charge/chargemax;
				if(charge < 0.0) charge = 0.0;
				if(charge > 1.0) charge = 1.0;
				return charge;
			}else{
				return 1.0;
			}
		}else{
			chr.chr_ai.chargeprc = "1";
		}
	}
	return 0.0;
}

//Получить максимальное количество зарядов пистолета
int LAi_GetCharacterChargeQuant(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.charge_max"))
	{
		return sti(chr.chr_ai.charge_max);
	}
	return 0;
}

//Получить текущее количество зарядов пистолета
int LAi_GetCharacterChargeCur(aref chr)
{
	float charge;
// added by MAXIMUS 24.11.2006 [prevents loading gun with non existent gunpowder or bullets] -->
	if(ENABLE_AMMOMOD==1)
	{
		if(GetCharacterIndex(chr.id)==GetMainCharacterIndex() || IsOfficer(chr))	//JRH: NOT everyone else
		{
			charge = RecalcCharacterGun(chr);//MAXIMUS: code moved to RecalcCharacterGun(ref chr)
			if(charge<=0.0) { LAi_GunSetUnload(chr); }
			return makeint(charge);
		}
	}
// added by MAXIMUS 24.11.2006 [prevents loading gun with non existent gunpowder or bullets] <--
	if(CheckAttribute(chr, "chr_ai.charge"))
	{
		charge = stf(chr.chr_ai.charge);
		return makeint(charge);
	}
	return 0;
}

//Установить количество зарядов
void LAi_GunSetChargeQuant(aref chr, int quant)
{
	if(quant < 0) quant = 0;
//	if(quant > 4) quant = 4;
	if(quant > 6) quant = 6;	//JRH BB6
	chr.chr_ai.charge_max = quant;
	chr.chr_ai.charge = quant;
	chr.chr_ai.chargeprc = "1";
}

//Разрядить пистлет
void LAi_GunSetUnload(aref chr)
{
	chr.chr_ai.charge = "0";
	chr.chr_ai.chargeprc = "1";
}

//Установить скорость заряда пистолета
void LAi_GunSetChargeSpeed(aref chr, float speed)
{
	if(speed < 0.0) speed = 0.0;
	if(speed > 4.0) speed = 4.0;
	chr.chr_ai.charge_dlt = speed;
}

//Установить минимальный урон от пистолета
void LAi_GunSetDamageMin(aref chr, float min)
{
	chr.chr_ai.dmggunmin = min;
}

//Установить максимальный урон от пистолета
void LAi_GunSetDamageMax(aref chr, float max)
{
	chr.chr_ai.dmggunmax = max;
}

//Установить вероятность попадания на максимальной дальности стрельбы
void LAi_GunSetAccuracy(aref chr, float accuracy)
{
	if(accuracy < 0.0) accuracy = 0.0;
	if(accuracy > 1.0) accuracy = 1.0;
	chr.chr_ai.accuracy = accuracy;
}

//Установить минимальный урон от сабли
void LAi_BladeSetDamageMin(aref chr, float min)
{
	chr.chr_ai.dmgbldmin = min;
}

//Установить максимальный урон от сабли
void LAi_BladeSetDamageMax(aref chr, float max)
{
	chr.chr_ai.dmgbldmax = max;
}

//Установить вероятность пробивки
void LAi_BladeSetPiercing(aref chr, float piercing)
{
	if(piercing < 0.0) piercing = 0.0;
	if(piercing > 1.0) piercing = 1.0;
	chr.chr_ai.piercing = piercing;
}

//Установить вероятность неблокирования
void LAi_BladeSetBlock(aref chr, float block)
{
	if(block < 0.0) block = 0.0;
	if(block > 1.0) block = 1.0;
	chr.chr_ai.block = block;
}


//------------------------------------------------------------------------------------------
//Internal
//------------------------------------------------------------------------------------------

//Процессируем всех загружекных персонажей
void LAi_AllCharactersUpdate(float dltTime)
{
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			//Персонаж
			aref chr_ai;
			makearef(chr_ai, Characters[idx].chr_ai);
			ref chr = &Characters[idx];
			if(LAi_IsDead(chr)) continue;
			//Востоновление жизни
			float dlthp = LAI_DEFAULT_DLTHP;
			float hp;
			if(CheckAttribute(chr_ai, "hp_dlt")) dlthp = stf(chr_ai.hp_dlt);

			// El Rapido -->
// KK: we have already set special dlthp for people with "Toughness" ability, enough! -->
			hp = stf(chr_ai.hp) + dlthp * dltTime;  
			/*if(IsCharacterPerkOn(chr, "Toughness"))
			{
				hp = stf(chr_ai.hp) + dlthp*dltTime*40;
			}
			else
			{
				hp = stf(chr_ai.hp) + dlthp*dltTime;
			}*/
// <-- KK
			float oldhp = hp;
			// El Rapido <--

			if(CheckAttribute(chr_ai, "hp_bottle"))
			{
				float bottle = stf(chr_ai.hp_bottle);
				if(bottle != 0) // was 'if(bottle > 0)', fails to apply HP loss from leeches
				{
					//Скорость высасывания из бутылки
					float bottledlthp = LAI_DEFAULT_DLTBLTHP;
					if(CheckAttribute(chr_ai, "hp_dlt_bottle"))
					{
						bottledlthp = stf(chr_ai.hp_dlt_bottle);
					}
					//Количество вытянутых хп за текущий период времени
					bottledlthp = bottledlthp*dltTime;
					if (bottle > 0)
					{
						if(bottledlthp > bottle)
						{
							bottledlthp = bottle;
						}
					}
					else
					{
						bottledlthp = bottledlthp*-1;
						if(bottledlthp < bottle)
						{
							bottledlthp = bottle;
						}
					}
					bottle = bottle - bottledlthp;
					hp = hp + bottledlthp;
					chr_ai.hp_bottle = bottle;
				}else{
					//Нет больше бутылки
					DeleteAttribute(chr_ai, "hp_bottle");
				}
			}
			if(CheckAttribute(chr_ai, "poison"))
			{
				chr_ai.poison = stf(chr_ai.poison) - dltTime;
				if(stf(chr_ai.poison) <= 0.0)
				{
					DeleteAttribute(chr_ai, "poison");
				}else{
					// El Rapido -->
					/*hp = hp - dltTime*2.0;
					if(IsCharacterPerkOn(chr_ai, "Toughness"))
					{
						hp = hp - dltTime*1.0;
					}
					else
					{
						hp = hp - dltTime*2.0;
					}*/
					// El Rapido <--
					//Redone by Levis for extra perk(s)
					float multip = 4.0;
					if(CheckPerkForGroup(chr, "DefendPoison")) multip -= 0.5; //party wide
					if(IsCharacterPerkOn(chr, "Toughness")) multip -= 1;
					hp = hp - dltTime*multip;
					//End redo
				}
			}
			if(LAi_IsImmortal(chr))
			{
				if(hp < oldhp) hp = oldhp;
			}
			float maxhp = stf(chr_ai.hp_max);
			if(hp > maxhp)
			{
				hp = maxhp;
				DeleteAttribute(chr_ai, "bottle");
			}
			chr_ai.hp = hp;
			//Проверка квеста на hp
			LAi_ProcessCheckMinHP(chr);
			//Проверка на смерть
			LAi_CheckKillCharacter(chr);
			//Востоновление заряда
			float chargemax = 0.0;
			if(CheckAttribute(chr_ai, "charge_max"))
			{
				chargemax = stf(chr_ai.charge_max);
			}
			if(!CheckAttribute(chr_ai, "chargeprc")) chr_ai.chargeprc = "1";
			if(chargemax > 0.0)
			{
				if(sti(chr_ai.chargeprc))
				{
					float charge = stf(chr_ai.charge);
					//Скорость зарядки
					float dltcharge = LAi_GunReloadSpeed(chr);
					//Подзаряжаем пистолет
					charge = charge + dltcharge*dltTime;
					if(charge >= chargemax)
					{
						charge = chargemax;
						chr_ai.chargeprc = "0";
					}
					chr_ai.charge = charge;
				}
			}else{
				chr_ai.charge = "0";
			}
		}
	}
}

void LAi_ProcessCheckMinHP(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.hpchecker"))
	{
		float minhp = stf(chr.chr_ai.hpchecker);
		float hp = stf(chr.chr_ai.hp);
		if(hp < minhp)
		{
			if(sti(chr.chr_ai.hpchecker.immortal))
			{
				LAi_SetImmortal(chr, true);
				chr.chr_ai.hp = minhp;
			}
			if(chr.chr_ai.hpchecker.quest != "")
			{
				LAi_QuestDelay(chr.chr_ai.hpchecker.quest, 0.0);
			}
			LAi_RemoveCheckMinHP(chr);
		}
	}
}

void LAi_CharacterSaveAy(aref chr)
{
	float ay = 0.0;
	if(GetCharacterAy(chr, &ay) == false) ay = 0.0;
	chr.chr_ai.type.ay = ay;	
}

void LAi_CharacterRestoreAy(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.type.ay"))
	{
		float ay = stf(chr.chr_ai.type.ay);
		aref type;
		makearef(type, chr.chr_ai.type);
		DeleteAttribute(type, "ay");
		CharacterTurnAy(chr, ay);
	}
}

//Levis:
bool CanReloadGun(ref chr)
{
	bool enough_ammo = true;
	if(CheckAttribute(chr, "chr_ai.charge"))
	{
		aref weapon;
		string weaponID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
		Items_FindItem(weaponID, &weapon);
		if(CheckAttribute(weapon,"shottype"))
		{
			int ammo = 0;
			int gp =  GetCharacterItem(chr, "gunpowder");
			string ammoName
			//TODO: Make sure shottypes are stored in a function somewhere and are called from in different functions
			switch(weapon.shottype)
			{
				case "pg2":
					ammoName = "pistolgrapes";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 1) enough_ammo = false;
					if(ammo <= 1) enough_ammo = false;
				break;
				case "na2":
					ammoName = "nails";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 1) enough_ammo = false;
					if(ammo <= 1) enough_ammo = false;
				break;
				case "pg":
					ammoName = "pistolgrapes";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp == 0) enough_ammo = false;
					if(ammo == 0) enough_ammo = false;
				break;
				case "mb":
					ammoName = "musketbullets";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 1) enough_ammo = false;
					if(ammo == 0) enough_ammo = false;
				break;
				case "pb2":
					ammoName = "pistolbullets";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 1) enough_ammo = false;
					if(ammo <= 1) enough_ammo = false;
				break;
				case "pb":
					ammoName = "pistolbullets";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp == 0) enough_ammo = false;
					if(ammo == 0) enough_ammo = false;
				break;
				case "ca":
					ammoName = "cartridges";
					ammo = GetCharacterItem(chr, ammoName);
					if(ammo == 0) enough_ammo = false;
				break;
				case "ar":
					ammoName = "bladearrows";
					ammo = GetCharacterItem(chr, ammoName);
					if(ammo == 0) enough_ammo = false;
				break;
				case "ar2":
					ammoName = "arrows2";
					ammo = GetCharacterItem(chr, ammoName);
					if(ammo == 0) enough_ammo = false;
				break;
				case "ro":
					ammoName = "rockets";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 2) enough_ammo = false;
					if(ammo == 0) enough_ammo = false;
				break;
				case "pc":
					ammoName = "cart_box_O";
					ammo = GetCharacterItem(chr, ammoName);
					if(ammo == 0) enough_ammo = false;
					ammoName = "caps_box_O";
					ammo = GetCharacterItem(chr, ammoName);
					if(ammo == 0) enough_ammo = false;
				break;
				case "pg6":
					ammoName = "pistolgrapes";
					ammo = GetCharacterItem(chr, ammoName);
					if(gp <= 5) enough_ammo = false;
					if(ammo <= 5) enough_ammo = false;
				break;
			}
		}
		else
		{
			enough_ammo = false;
		}
	}
	else
	{
		enough_ammo = false;
	}
	return enough_ammo;
}

//MAXIMUS: with amount of charges less than maximum, we need less time for loading gun -->
//MAXIMUS: moved here from LAi_GetCharacterChargeCur -->
float RecalcCharacterGun(ref chr)
{
	float charge = 0.0;
	if(CheckAttribute(chr, "chr_ai.charge"))
	{
		charge = stf(chr.chr_ai.charge);
		aref weapon;
		string weaponID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
		Items_FindItem(weaponID, &weapon);
		if(CheckAttribute(weapon,"shottype"))
		{
			string ammoName;
			string ammoName2;

			int gp;
			int pb;
			int pg;
			int mb;
			int ca;
			int na;
			int ar;
			int ar2;
			int ro;
			int gpb;
			int cap;
			bool enough_ammo = true;

			gp = GetCharacterItem(chr, "gunpowder");
 			pg = GetCharacterItem(chr, "pistolgrapes");
			mb = GetCharacterItem(chr, "musketbullets");
			pb = GetCharacterItem(chr, "pistolbullets");
			ca = GetCharacterItem(chr, "cartridges");
			na = GetCharacterItem(chr, "nails");
			ar = GetCharacterItem(chr, "bladearrows");
			ar2 = GetCharacterItem(chr, "arrows2");
			ro = GetCharacterItem(chr, "rockets");
			gpb = GetCharacterItem(chr, "cart_box_O");
			cap = GetCharacterItem(chr, "caps_box_O");

			switch(weapon.shottype)
			{
				case "pg2":
					ammoName = "pistolgrapes";
					if(gp <= 1) enough_ammo = false;
					if(pg <= 1) enough_ammo = false;
				break;
				case "na2":
					ammoName = "nails";
					if(gp <= 1) enough_ammo = false;
					if(na <= 1) enough_ammo = false;
				break;
				case "pg":
					ammoName = "pistolgrapes";
					if(gp == 0) enough_ammo = false;
					if(pg == 0) enough_ammo = false;
				break;
				case "mb":
					ammoName = "musketbullets";
					if(gp <= 1) enough_ammo = false;
					if(mb == 0) enough_ammo = false;
				break;
				case "pb2":
					ammoName = "pistolbullets";
					if(gp <= 1) enough_ammo = false;
					if(pb <= 1) enough_ammo = false;
				break;
				case "pb":
					ammoName = "pistolbullets";
					if(gp == 0) enough_ammo = false;
					if(pb == 0) enough_ammo = false;
				break;
				case "ca":
					ammoName = "cartridges";
					if(ca == 0) enough_ammo = false;
				break;
				case "ar":
					ammoName = "bladearrows";
					if(ar == 0) enough_ammo = false;
				break;
				case "ar2":
					ammoName = "arrows2";
					if(ar2 == 0) enough_ammo = false;
				break;
				case "ro":
					ammoName = "rockets";
					if(gp <= 2) enough_ammo = false;
					if(ro == 0) enough_ammo = false;
				break;
				case "pc":
					ammoName = "cart_box_O";
					ammoName2 = "caps_box_O";
					if(gpb == 0) enough_ammo = false;
					if(cap == 0) enough_ammo = false;
				break;
				case "pg6":
					ammoName = "pistolgrapes";
					if(gp <= 5) enough_ammo = false;
					if(pg <= 5) enough_ammo = false;
				break;
			}

			if(weapon.shottype == "ca" || weapon.shottype == "ar" || weapon.shottype == "ar2")
			{
			    if(enough_ammo == false) 
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0) { charge = 0.0; LAi_GunSetUnload(chr); }
					else
					{
						if(sti(chr.Items.(ammoName))<sti(chr.chr_ai.charge)) charge = stf(chr.Items.(ammoName));
					}
			    }
			}

			if(weapon.shottype == "pg" || weapon.shottype == "pg2" || weapon.shottype == "mb" || weapon.shottype == "pb" || weapon.shottype == "pb2"
			|| weapon.shottype == "na2" || weapon.shottype == "ro" || weapon.shottype == "pg6")
			{
			    if(enough_ammo == false)
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0 || sti(chr.Items.gunpowder)==0) { charge = 0.0; LAi_GunSetUnload(chr); }
					else
					{
						if(sti(chr.Items.(ammoName))<sti(chr.chr_ai.charge))
						{
							if(sti(chr.Items.(ammoName))<sti(chr.Items.gunpowder)) charge = stf(chr.Items.(ammoName));
							else { if(sti(chr.Items.gunpowder)<sti(chr.chr_ai.charge)) charge = stf(chr.Items.gunpowder); }
						}
						else
						{
							if(sti(chr.Items.gunpowder)<sti(chr.Items.(ammoName)) && sti(chr.Items.gunpowder)<sti(chr.chr_ai.charge)) charge = stf(chr.Items.gunpowder);
							else charge = stf(chr.chr_ai.charge);
						}
					}
				}
			}

			if(weapon.shottype == "pc")
			{
			    if(enough_ammo == false)
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0 || sti(chr.Items.(ammoName2))==0) { charge = 0.0; LAi_GunSetUnload(chr); }
					else
					{
						if(sti(chr.Items.(ammoName))<sti(chr.chr_ai.charge))
						{
							if(sti(chr.Items.(ammoName))<sti(chr.Items.(ammoName2))) charge = stf(chr.Items.(ammoName));
							else { if(sti(chr.Items.(ammoName2))<sti(chr.chr_ai.charge)) charge = stf(chr.Items.(ammoName2)); }
						}
						else
						{
							if(sti(chr.Items.(ammoName2))<sti(chr.Items.(ammoName)) && sti(chr.Items.(ammoName2))<sti(chr.chr_ai.charge)) charge = stf(chr.Items.(ammoName2));
							else charge = stf(chr.chr_ai.charge);
						}
					}
				}
			}
		}
	}
	else charge = 1.0;
	return charge;
}
//MAXIMUS: moved here from LAi_GetCharacterChargeCur <--

float GetCurrentCharacterGunMax(ref chr)
{
	float charge = LAi_GetCharacterChargeQuant(chr);
	if(CheckAttribute(chr, "chr_ai.charge"))
	{
		aref weapon;
		string weaponID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
		Items_FindItem(weaponID, &weapon);
		if(CheckAttribute(weapon,"shottype"))
		{
			string ammoName;
			string ammoName2;

			int gp;
			int pb;
			int pg;
			int mb;
			int ca;
			int na;
			int ar;
			int ar2;
			int ro;
			int gpb;
			int cap;
			bool enough_ammo = true;

			gp = GetCharacterItem(chr, "gunpowder");
 			pg = GetCharacterItem(chr, "pistolgrapes");
			mb = GetCharacterItem(chr, "musketbullets");
			pb = GetCharacterItem(chr, "pistolbullets");
			ca = GetCharacterItem(chr, "cartridges");
			na = GetCharacterItem(chr, "nails");
			ar = GetCharacterItem(chr, "bladearrows");
			ar2 = GetCharacterItem(chr, "arrows2");
			ro = GetCharacterItem(chr, "rockets");
			gpb = GetCharacterItem(chr, "cart_box_O");
			cap = GetCharacterItem(chr, "caps_box_O");

			switch(weapon.shottype)
			{
				case "pg2":
					ammoName = "pistolgrapes";
					if(gp <= 1) enough_ammo = false;
					if(pg <= 1) enough_ammo = false;
				break;
				case "na2":
					ammoName = "nails";
					if(gp <= 1) enough_ammo = false;
					if(na <= 1) enough_ammo = false;
				break;
				case "pg":
					ammoName = "pistolgrapes";
					if(gp == 0) enough_ammo = false;
					if(pg == 0) enough_ammo = false;
				break;
				case "mb":
					ammoName = "musketbullets";
					if(gp <= 1) enough_ammo = false;
					if(mb == 0) enough_ammo = false;
				break;
				case "pb2":
					ammoName = "pistolbullets";
					if(gp <= 1) enough_ammo = false;
					if(pb <= 1) enough_ammo = false;
				break;
				case "pb":
					ammoName = "pistolbullets";
					if(gp == 0) enough_ammo = false;
					if(pb == 0) enough_ammo = false;
				break;
				case "ca":
					ammoName = "cartridges";
					if(ca == 0) enough_ammo = false;
				break;
				case "ar":
					ammoName = "bladearrows";
					if(ar == 0) enough_ammo = false;
				break;
				case "ar2":
					ammoName = "arrows2";
					if(ar2 == 0) enough_ammo = false;
				break;
				case "ro":
					ammoName = "rockets";
					if(gp <= 2) enough_ammo = false;
					if(ro == 0) enough_ammo = false;
				break;
				case "pc":
					ammoName = "cart_box_O";
					ammoName2 = "caps_box_O";
					if(gpb == 0) enough_ammo = false;
					if(cap == 0) enough_ammo = false;
				break;
				case "pg6":
					ammoName = "pistolgrapes";
					if(gp <= 5) enough_ammo = false;
					if(pg <= 5) enough_ammo = false;
				break;
			}

			if(weapon.shottype == "ca" || weapon.shottype == "ar" || weapon.shottype == "ar2")
			{
			    if(enough_ammo == false)
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0) { return 0.0;}
					if(sti(chr.Items.(ammoName))<sti(LAi_GetCharacterChargeQuant(chr))) charge = stf(chr.Items.(ammoName));
			    }
			}

			if(weapon.shottype == "pg" || weapon.shottype == "pg2" || weapon.shottype == "mb" || weapon.shottype == "pb" || weapon.shottype == "pb2"
			|| weapon.shottype == "na2" || weapon.shottype == "ro" || weapon.shottype == "pg6")
			{
			    if(enough_ammo == false)
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0 || sti(chr.Items.gunpowder)==0) { return 0.0;}
					if(sti(chr.Items.(ammoName))<sti(LAi_GetCharacterChargeQuant(chr)))
					{
							if(sti(chr.Items.(ammoName))<sti(chr.Items.gunpowder)) charge = stf(chr.Items.(ammoName));
							else { if(sti(chr.Items.gunpowder)<sti(LAi_GetCharacterChargeQuant(chr))) charge = stf(chr.Items.gunpowder); }
					}
					else { if(sti(chr.Items.gunpowder)<sti(chr.Items.(ammoName)) && sti(chr.Items.gunpowder)<sti(LAi_GetCharacterChargeQuant(chr))) charge = stf(chr.Items.gunpowder); }
			    }
			}

			if(weapon.shottype == "pc")
			{
			    if(enough_ammo == false)
			    {
					LAi_GunSetUnload(chr);
			    }
			    else
			    {
					if(sti(chr.Items.(ammoName))==0 || sti(chr.Items.(ammoName2))==0) { return 0.0;}
					if(sti(chr.Items.(ammoName))<sti(LAi_GetCharacterChargeQuant(chr)))
					{
						if(sti(chr.Items.(ammoName))<sti(chr.Items.(ammoName2))) charge = stf(chr.Items.(ammoName));
						else { if(sti(chr.Items.(ammoName2))<sti(LAi_GetCharacterChargeQuant(chr))) charge = stf(chr.Items.(ammoName2)); }
					}
					else { if(sti(chr.Items.(ammoName2))<sti(chr.Items.(ammoName)) && sti(chr.Items.(ammoName2))<sti(LAi_GetCharacterChargeQuant(chr))) charge = stf(chr.Items.(ammoName2)); }
				}
			}
		}
	}
	return charge;
}
//MAXIMUS: with amount of charges less than maximum, we need less time for loading gun <--

// KK -->
void LAi_CharactersIgnoreFight(bool bSet)
{
	ref mchr = GetMainCharacter();
	if (CheckAttribute(mchr, "chr_ai.CharactersIgnoreFight")) DeleteAttribute(mchr, "chr_ai.CharactersIgnoreFight");
	if (bSet) mchr.chr_ai.CharactersIgnoreFight = true;
}

bool LAi_IsCharactersIgnoreFight()
{
	ref mchr = GetMainCharacter();
	if (CheckAttribute(mchr, "chr_ai.CharactersIgnoreFight")) return sti(mchr.chr_ai.CharactersIgnoreFight);
	return false;
}
// <-- KK