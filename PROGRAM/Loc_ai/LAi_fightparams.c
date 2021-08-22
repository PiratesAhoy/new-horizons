// GreatZen-NK -->
float ApplyArmor(ref chr, ref attack, float dmg, bool blade)
{
	if (!CheckAttribute(chr,"name")) return 0.0;	// LDH 03Oct06
	if (!CheckAttribute(chr,"chr_ai.coverage")) {
		return dmg;
	} else {
		if(stf(chr.chr_ai.coverage) == 0.0) return dmg;
	}
	// NK add piercing to calc 05-04-22
	float covch = stf(chr.chr_ai.coverage) * (1.0 + makefloat(CalcCharacterSkill(&chr, SKILL_SNEAK)) * ARMOR_LUCK_SCALAR);
	float piercing = 0.05;
	if(CheckAttribute(attack, "chr_ai.piercing"))
	{
		piercing = stf(attack.chr_ai.piercing);
	}
	float piercech = clampf(piercing - covch);
	if(frnd() > covch || frnd() < piercech) return dmg;
	// NK <--
	float afrac = ARMOR_DEFAULT_FRAC;
	float astop = ARMOR_DEFAULT_STOP;
	if (blade) {
		afrac = stf(chr.chr_ai.bladefrac);
		astop = stf(chr.chr_ai.bladestop);
	} else {
		afrac = stf(chr.chr_ai.gunfrac);
		astop = stf(chr.chr_ai.gunstop);
	}
	if(frnd() < astop) return 0.0;
	return dmg*afrac;
}
// GreatZen-NK <--

//--------------------------------------------------------------------------------
//Blade parameters
//--------------------------------------------------------------------------------

//Получить повреждение от сабли
float LAi_BladeCalcDamage(aref attack)
{
	//Расчитываем повреждение от сабли
	float min = 10.0;
	float max = 10.0;
	if(CheckAttribute(attack, "chr_ai.dmgbldmin"))
	{
		min = stf(attack.chr_ai.dmgbldmin);
	}
	if(CheckAttribute(attack, "chr_ai.dmgbldmax"))
	{
		max = stf(attack.chr_ai.dmgbldmax);
	}
	float dmg = min + (max - min)*(rand(100)*0.01);
	return dmg;
}

//Модифицировать повреждение от сабли с учётом скилов
float LAi_BladeApplySkills(aref attack, aref enemy, float dmg)
{
	//Учитываем скилы
	float aSkill = LAi_GetCharacterFightLevel(attack);
	float eSkill = LAi_GetCharacterFightLevel(enemy);
	if(aSkill >= eSkill)
	{
		dmg = dmg*(1.0 + 2.0*(aSkill - eSkill));
	}else{
		dmg = dmg*(1.0 + 0.5*(aSkill - eSkill));
	}
	// NK -->
	dmg *= (0.75 + fRand(CalcCharacterSkill(attack, SKILL_SNEAK))/(40.0/3.0));
	dmg *= (1.5  - fRand(CalcCharacterSkill(enemy, SKILL_SNEAK))/(40.0/3.0));
	float piercing = 0.05;
	float block = 0.01;
	if(CheckAttribute(attack, "chr_ai.piercing"))
	{
		piercing = stf(attack.chr_ai.piercing);
	}
	if(CheckAttribute(enemy, "chr_ai.block"))
	{
		block = stf(enemy.chr_ai.block);
	}
	if(piercing > block*2 && piercing > 0.1) dmg *= (1.0 + fRand(piercing)/2.0);
	if(sti(attack.index) == GetMainCharacterIndex()) dmg *= (1.45 - 0.15*GetDifficulty()); // NK Diff Mod
	else { if(sti(enemy.index) == GetMainCharacterIndex()) { dmg *= (0.85 + 0.15*GetDifficulty()); } } // NK Diff Mod
	// NK <--
	//Moved from attack function
	float kDmg = 1.0;
	if(IsCharacterPerkOn(attack, "Rush"))
	{
		kDmg = 1.5;
	}
	dmg = dmg*kDmg;
	//Аттака своей группы
	kDmg = 1.0;
	if(IsCharacterPerkOn(enemy, "BasicDefence")) kDmg = 0.9;
	if(IsCharacterPerkOn(enemy, "AdvancedDefence")) kDmg = 0.8;
	if(IsCharacterPerkOn(enemy, "SwordplayProfessional")) kDmg = 0.7; // Baste
	//Levis: Opium sickness
	float s = 1.0;
	if(CheckAttribute(enemy,"quest.opium_use.opiumsickness")) s = s - stf(enemy.quest.opium_use.opiumsickness);
	if(s < 0.1) s = 0.1;
	dmg = dmg*kDmg*s;
	return dmg;
}

//Расчитать полученный опыт при ударе саблей
float LAi_BladeCalcExperience(aref attack, aref enemy, float dmg)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	if(LAi_IsImmortal(enemy)) dmg = 1+rand(sti(attack.rank));
//NK -->
	//dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5)) * sqrt(re); //JA 8DEC06 reduced XP at high levels. (was leveling too fast up there
	dmg = pow2(1.4,(re/1.5)/ra)*sqrt(re)*dmg; //Levis - trying to balance the XP at high level differences
	//Log_SetStringToLog("" + (dmg * 0.5));
// NK <--
	//Levis, add a cap for very high opponents
	if(dmg > 200.0)
	{
		dmg = 200.0;
		if(DEBUG_EXPERIENCE>0) trace("XP LOG: Max blade xp reached between " + GetMySimpleName(attack) + " and " + GetMySimpleName(enemy));
	}
	return dmg;
}

//Расчитать вероятность пробивки блока
float LAi_BladeFindPiercingProbability(aref attack, aref enemy, float hitDmg)
{
	float piercing = 0.05;
	float block = 0.01;
	if(CheckAttribute(attack, "chr_ai.piercing"))
	{
		piercing = stf(attack.chr_ai.piercing);			// 0..1 from blade stats
	}
	if(CheckAttribute(enemy, "chr_ai.block"))
	{
		block = stf(enemy.chr_ai.block);				// 0..1 from blade stats
	}
	float aSkill = LAi_GetCharacterFightLevel(attack);	// fencing skill / 10
	float eSkill = LAi_GetCharacterFightLevel(enemy);

	// LDH change to ratios - 11Apr09
//	if(aSkill < eSkill) aSkill = eSkill;				// NK had removed this and set p to minimum of 0
//	float p = piercing - block + (aSkill - eSkill)*0.5;	// original calculation
	//float origP = piercing - block + (floatret(aSkill<eSkill, eSkill, aSkill) - eSkill)*0.5;	// LDH for testing 12Apr09
	//if (origP < 0.0) origP = 0.0;
	//Levis: weren't used so commented

//	if (block == 0) block = 0.01;
//	if (eSkill == 0) eSkill = 0.1;
//	float p = sqrt(piercing/block * sqrt(aSkill/eSkill));			// pierce to block ratio * half skill ratio

	// LDH - 01May09
	//float p = (1.0 + piercing - block)^10 * (1 + askill - eskill);
	float p = (1.0 + piercing - block) * (1 + askill - eskill); // Levis: Simplified

	float k = 1.0;
	if (p > 0)											// LDH added test 06Apr09
	{
		if(IsCharacterPerkOn(enemy, "BasicDefence")) k = 0.75;
		if(IsCharacterPerkOn(enemy, "AdvancedDefence")) k = 0.5;
	}
	
	//Moved from attack function
	float pBreak = 1.0;
	if(IsCharacterPerkOn(attack, "SwordplayProfessional"))
	{
		pBreak = pBreak + 0.25;
	}
	if(IsCharacterPerkOn(attack, "Rush"))
	{
		pBreak = pBreak + 0.5;
	}
	if(IsCharacterPerkOn(enemy, "Rush"))
	{
		pBreak = pBreak + 0.9;
	}
	
	hitDmg = 0.25*hitDmg^2 + 0.5*hitDmg + 0.25;							// hitDmg is a small number, so this is 0.5 to 0.52 typically, can be higher
	//Levis changed and removed a *hitDmg at the end. should have same effect but makes it easier to read.
	// (0.5X + 0.5) * (0.5X +0.5) = 0.25X^2 + 0.5X + 0.25
	
//float retVal = p*k*hitDmg*hitDmg*100;  if (retVal > 100.0) retVal = 100.0;
//float retValOrig = origP*k*hitDmg*hitDmg*100;
//TraceAndLog("p=" + makeint(piercing*100) + ", " + stringRet(piercing<0.1," ","") +
//	"b=" + makeint(block*100) + ", " + stringRet(block<0.1," ","") +
//	"aSkill=" + makeint(aSkill*10) + ", " + stringRet(aSkill<1," ","") +
//	"eSkill=" + makeint(eSkill*10) + ", " + stringRet(eSkill<1," ","") +
//	"p=" + strLeft(f2s2(p*100),6) + ", " +
//	"k=" + k + ", " + stringRet(k==1.0,"  ","") + stringRet(k==0.5," ","") +
//	"hitDmg=" + strLeft(f2s2(hitDmg*hitDmg),6) + ", " +
//	"return=" + strLeft(stringRet(retVal<10," ","") + f2s2(retVal),5) + ", " +
//	"orig=" + stringRet(retValOrig==0,"",strLeft(f2s2(retValOrig),6)));

	//Levis: Opium sickness
	float s = 1.0;
	if(CheckAttribute(enemy,"quest.opium_use.opiumsickness")) s = s - stf(enemy.quest.opium_use.opiumsickness);
	if(s < 0.1) s = 0.1;
	
	p = p*k*hitDmg*pBreak*s;
	if (p>1.0) p = 1.0;
	return p;
}

//--------------------------------------------------------------------------------
//Gun parameters
//--------------------------------------------------------------------------------

//Расчитаем вероятность попадания
float LAi_GunCalcProbability(aref attack, float kDist)
{
	//Если близко, то попадём точно
	if(kDist >= 0.9) return 1.0;
	//Расчитаем вероятность на конце отрезка
	float pmin = 0.3;
	if(CheckAttribute(attack, "chr_ai.accuracy"))
	{
		pmin = stf(attack.chr_ai.accuracy);
	}
	//Применим разброс от скила
	float aSkill = LAi_GetCharacterFightLevel(attack);
	pmin = pmin + 0.3*aSkill;
	//Вероятность попадания в текущей позиции
	float p = pmin + (1.0 - pmin)*(kDist/0.9);
	//Учесть абилити
	if(IsCharacterPerkOn(attack, "GunProfessional"))
	{
		p = p + 0.10;
	}
	if(IsCharacterPerkOn(attack, "Gunman"))
	{
		p = p + 0.05;
	}
	if(IsCharacterPerkOn(attack, "ImproveAiming")) //added by Levis
	{
		p = p + 0.20;
	}
	return p;
}

//Получить повреждение от пистолета
float LAi_GunCalcDamage(aref attack)
{
	//Расчитываем повреждение от сабли
	float min = 10.0;
	float max = 10.0;
	if(CheckAttribute(attack, "chr_ai.dmggunmin"))
	{
		min = stf(attack.chr_ai.dmggunmin);
	}
	if(CheckAttribute(attack, "chr_ai.dmggunmax"))
	{
		max = stf(attack.chr_ai.dmggunmax);
	}
	float dmg = min + (max - min)*(rand(100)*0.01);
	// NK -->
	dmg *= (0.75 + fRand(CalcCharacterSkill(attack, SKILL_SNEAK))/(40.0/3.0));
	if(sti(attack.index) == GetMainCharacterIndex()) dmg *= (1.45 - 0.15*GetDifficulty()); // NK Diff Mod
	// NK <--
	return dmg;
}

//Расчитать полученный опыт при попадании из пистолета
float LAi_GunCalcExperience(aref attack, aref enemy, float dmg)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
//NK -->
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5)) * re;
	//Log_SetStringToLog("" + (dmg * 0.5));
// NK <--
	if(dmg > 1000.0)
	{
		dmg = 1000.0;
		if(DEBUG_EXPERIENCE>0) trace("XP LOG: Max gun xp reached between " + GetMySimpleName(attack) + " and " + GetMySimpleName(enemy));
	}
	return dmg;
}

//Расчитаем текущую скорость перезарядки пистолета
float LAi_GunReloadSpeed(aref chr)
{
	//Получим текущее состояние скорости зарядки
	float charge_dlt = LAI_DEFAULT_DLTCHRG;
	if(CheckAttribute(chr, "chr_ai.charge_dlt"))
	{
		charge_dlt = stf(chr.chr_ai.charge_dlt);
	}

     //JRH
	float F;
	float P;
	if(IsEquipCharacterByItem(chr, "ammobag2"))	//added this one JRH
	{
		F = 1.1;
		P = 1.1;
	}
	else
	{
		if(IsEquipCharacterByItem(chr, "powderbarrel"))
		{
			F = 1.15;
		}
		else
		{
			if(IsEquipCharacterByItem(chr, "powderflask"))
			{
				F = 1.05;
			}
		}
		else F = 0.9;

		if(IsEquipCharacterByItem(chr, "ammobag"))
		{
			P = 1.15;
		}
		else
		{
			if(IsEquipCharacterByItem(chr, "ammopouch")) 
			{	
				P = 1.05;
			}
		}
		else P = 0.9;
	}
     //JRH

	//Модифицируем скилом
	float skill = LAi_GetCharacterFightLevel(chr);
	//charge_dlt = charge_dlt*(1.0 + 0.25*skill);
	charge_dlt = charge_dlt*(1.0 + 0.25*skill)*F*P; //JRH
	//Учтём абилити
	if(IsCharacterPerkOn(chr, "GunProfessional"))
	{
		charge_dlt = charge_dlt*1.5;
	}else{
		if(IsCharacterPerkOn(chr, "Gunman"))
		{
			charge_dlt = charge_dlt*1.1;
		}
	}
// added by MAXIMUS 21.07.2006 [weapon will not be charged without gunpowder or proper bullets] -->
	if(ENABLE_AMMOMOD==1)
	{
	    if(GetCharacterIndex(chr.id)==GetMainCharacterIndex() || IsOfficer(chr)) //JRH fix oct 06
   	    {
		if(CheckAttribute(chr,"equip."+GUN_ITEM_TYPE))
		{
			string weaponID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
			aref weapon;
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
						if(pg <= 1 || gp <= 1) return 0.0;// JRH fix oct 06: not only when pg/gp = 0 !
					break;
					case "na2":
						ammoName = "nails";
						if(na <= 1 || gp <= 1) return 0.0;
					break;
					case "pg":
						ammoName = "pistolgrapes";
						if(pg == 0 || gp == 0) return 0.0;
					break;
					case "mb":
						ammoName = "musketbullets";
						if(mb == 0 || gp <= 1) return 0.0;
					break;
					case "pb2":
						ammoName = "pistolbullets";
						if(pb <= 1 || gp <= 1) return 0.0;
					break;
					case "pb":
						ammoName = "pistolbullets";
						if(pb == 0 || gp == 0) return 0.0;
					break;
					case "ca":
						ammoName = "cartridges";
						if(ca == 0) return 0.0;
					break;
					case "ar":
						ammoName = "bladearrows";
						if(ar == 0) return 0.0;
					break;
					case "ar2":
						ammoName = "arrows2";
						if(ar2 == 0) return 0.0;
					break;
					case "ro":
						ammoName = "rockets";
						if(ro == 0 || gp <= 2) return 0.0;
					break;
					case "pc":
						ammoName = "cart_box_O";
						ammoName2 = "caps_box_O";
						if(gpb == 0 || cap == 0) return 0.0;
					break;
					case "pg6":
						ammoName = "pistolgrapes";
						if(pg <= 5 || gp <= 5) return 0.0;
					break;				
				}
				if(!CheckAttribute(chr,"Items.gunpowder")) chr.Items.gunpowder = 0;
				if(!CheckAttribute(chr,"Items."+ammoName) || sti(chr.Items.gunpowder)==0)
				{
					string aboutBullet = "";
					string aboutPowder = "";

					if(!CheckAttribute(chr,"Items."+ammoName)) aboutBullet = XI_ConvertString("n"+ammoName);
					if(sti(chr.Items.gunpowder)==0) aboutPowder = XI_ConvertString("ngunpowder");
					if(!CheckAttribute(chr,"Items."+ammoName) && sti(chr.Items.gunpowder)==0) aboutPowder = TranslateString("","and gunpowder");
				}
			}
		}
	  }
	}
// added by MAXIMUS 21.07.2006 [weapon will not be charged without gunpowder or proper bullets] <--

	// PB: Can reload when using fists, shotgun or certain special weapons
	string bladeID = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);
	aref blade;
	Items_FindItem(bladeID, &blade);	// defines object for weaponattributes
	string gunID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
	aref gun;
	Items_FindItem(gunID, &gun);	// defines object for weaponattributes
	if (DisableReloadWhileFighting())
	{
		if(LAi_IsFightMode(chr) && !CheckAttribute(blade,"enblrld") && !CheckAttribute(gun,"enblrld") && !CheckAttribute(gun,"throw"))  return 0.0;
	}
	return charge_dlt;
}

//--------------------------------------------------------------------------------
//All
//--------------------------------------------------------------------------------

float LAi_CalcDeadExp(aref attack, aref enemy)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	float dmg = (0.5 + 4.0*LAi_GetCharacterFightLevel(enemy))*LAi_GetCharacterMaxHP(enemy);
//NK -->
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));
	dmg *= (5-GetDifficulty()); //Changed by Levis from 6.0
	//Log_SetStringToLog("" + (dmg * 0.25));
	/*DebugLog("Dead chr group: " + enemy.chr_ai.group);
	if(sti(attack.index) == GetMainCharacterIndex() && CheckAttribute(enemy,"chr_ai.group"))
	{
		AddOneSoldier(enemy.chr_ai.group);
	}*/
// NK <--
	//NK -->

		ref PChar = GetMainCharacter();
		ref lcn = &Locations[FindLocation(PChar.location)];
		bool AutoLoot = false;
		if(AUTOLOOT_ON)																AutoLoot = true;  // TIH autoloot all the time
		if(LAi_IsBoardingProcess()==true && AUTOLOOT_BOARDINGS && CORPSEMODE<4)		AutoLoot = true;  // PB: Automatic looting during boardings (at LDH's request) //MAXIMUS: excludes player's decks and CORPSEMODE 4
		if(sti(attack.index) != GetMainCharacterIndex())							AutoLoot = false; // TIH only main character autoloots
		if(sti(enemy.index) == GetMainCharacterIndex())								AutoLoot = false; // ccc Survival so that you don't loot yourself if being killed
		if(CheckAttribute(lcn, "abbey") && sti(lcn.abbey) == true)					AutoLoot = false; // PB: Looting Maltese Knights is handled differently // KK
		if(CheckAttribute(enemy,"chr_ai.type") && enemy.chr_ai.type == "Building")	AutoLoot = false; // PB: For BuildingSet characters
		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)			AutoLoot = false; // JRH
		if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)			AutoLoot = false; // JRH
		if(AutoLoot)
		{
			int q;
			aref tempitem;
			bool log = false;
			string b = "";
			string g = "";
			string m = "";
			string comp = "";
			string tempitm = ""; // PB: prevent double looting
			bool btemp = !IsOfficer(attack) && !IsOfficer(enemy);
			// SCREWFACE : to loot enemy weapons if one of your crewmember kill an enemy
			if(attack.name==XI_ConvertString("Crewmember") || enemy.name==XI_ConvertString("Crewmember")){btemp=false;}
			// END
			if(!btemp) // that is, do this if either attack || enemy is officer. Done as a ! and && because there were originally three ors to do and some nesting which POTC doesn't support.
			{
				int ethingidx;
				if(CheckAttribute(enemy, "equip.blade") && enemy.lastname != VC_MONKEY_LNAME) // ccc
				{
					//tmp += enemy.equip.blade;
					ethingidx = GetItemIndex(enemy.equip.blade);
					if(ENABLE_WEAPONSMOD && CheckAttribute(Items[ethingidx], "bladequality") && sti(Items[ethingidx].bladequality) < MIN_QUALITY_TO_KEEP+2) // NK 04-11-03 add min qual check
					{
						//do nothing
					}
					else
					{
						tempitm = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE);
						if(tempitm != "bladeX4" && tempitm != "bladearrows")
						// PB: Don't loot fists
						// JRH: or bladearrows as that could exceed the number you can carry
						{
							GiveItem2Character(GetMainCharacter(), tempitm);
							TakeItemFromCharacter(enemy, tempitm); // PB: To prevent double looting
							makearef(tempitem, Items[ethingidx]); // NK 04-09-08 now use native getindex
							log = true;
							b = " " + XI_ConvertString("a") + " " + TranslateString("",tempitem.name);
						}

						//JRH: extra check as NPC:s could get 4 arrows
						int ar = GetCharacterItem(enemy, "bladearrows");
						if(!IsEquipCharacterByItem(enemy, "quiver") && ar > 3)
						{
							TakeNItems(enemy,"bladearrows", -100);
							TakeNItems(enemy,"bladearrows", 3);
						}
					}
				}
				if(CheckAttribute(enemy, "equip.gun") && enemy.lastname != VC_MONKEY_LNAME) // ccc
				{
					ethingidx = GetItemIndex(enemy.equip.gun);
					if(ethingidx >=0)  //Sulan: Fix for invalid guns (e.g. pistol1-0)
					{
						if(ENABLE_WEAPONSMOD && CheckAttribute(Items[ethingidx], "gunquality") && sti(Items[ethingidx].gunquality) < MIN_QUALITY_TO_KEEP+2) // NK 04-11-03 add min qual check
						{
							//do nothing
						}
						else
						{
							tempitm = GetCharacterEquipByGroup(enemy,GUN_ITEM_TYPE);
							GiveItem2Character(GetMainCharacter(), tempitm);
							TakeItemFromCharacter(enemy, tempitm); // PB: To prevent double looting
							makearef(tempitem, Items[ethingidx]); // NK 04-09-08 now use native getindex
							log = true;
							if(b == "") { g = " " + XI_ConvertString("a") + " " + TranslateString("",tempitem.name);}
							else { g = " " + XI_ConvertString("and") + " " + XI_ConvertString("a") + " " + TranslateString("",tempitem.name);}
						}
					}
					else
					{
						tempitm = GetCharacterEquipByGroup(enemy,GUN_ITEM_TYPE);
						trace("LAi_fightparams.c line 497 - invalid item: "+tempitm);
						TakeItemFromCharacter(enemy, tempitm); // Sulan: To prevent manual looting of invalid items
					}
				}
				if(CheckAttribute(enemy,"money") && sti(enemy.money))
				{
					AddMoneyToCharacter(GetMainCharacter(), sti(enemy.money));
					log = true;
					if(b == "" && g == "") {m = " " + sti(enemy.money) + " " + XI_ConvertString("1gold");}
					else {m = " " + XI_ConvertString("and") + " " + sti(enemy.money) + " " + XI_ConvertString("1gold");}
					enemy.money = 0; // PB: To prevent double looting
				}
				//ccc10.2 ->
				if(enemy.lastname == VC_MUMMY_LNAME) //ccc Amazone artefact
				{
					if(CORPSEMODE != 2) GiveItem2Character(GetMainCharacter(), "indian" + (1 + rand(15))); // PB: If corpsemode on, you have to loot the artifacts from the body yourself
					log = true;
					if(b == "" && g == "") {m = " " + TranslateString("","an Indian artifact");}
					else {m = " " + XI_ConvertString("and") + " " + TranslateString("","an Indian artifact");}
				}
				//ccc10.2 <-
				if(log && LOGLOOT) comp = TranslateString("","You got") + b + g + m + ". "; // LDH: Add a toggle
				Log_SetStringToLog(comp + TranslateString("","Total XP") + ": " + makeint(dmg*0.5));
				//trace(comp);
				//traceandlog("from chr " + enemy.id + " you got " + tmp + " +++++++++++++");
			}
		}
		if(enemy.lastname == VC_MONKEY_LNAME) //ccc monkeyhide
		{
			AddCharacterGoods(GetMainCharacter(), GOOD_LEATHER, 1);
			Log_SetStringToLog(TranslateString("","You got the beast's hide!"));
		}
	// NK <--
    if(sti(attack.index) == GetMainCharacterIndex()) UpdateStatistics("Kills",1); // Sulan: Update Kill Statistics
	return dmg*0.5;
}

//--------------------------------------------------------------------------------
//Calculate
//--------------------------------------------------------------------------------


//Начисление повреждений при незаблокированной атаке
void LAi_ApplyCharacterAttackDamage(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	LAi_ApplyCharacterBladeDamage(attack, enemy, attackDmg, hitDmg, false);
}

//Начисление повреждений при заблокированной атаке
void LAi_ApplyCharacterBlockDamage(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	LAi_ApplyCharacterBladeDamage(attack, enemy, attackDmg, hitDmg, true);
}

//Начисление повреждений при атаке мечём
void LAi_ApplyCharacterBladeDamage(aref attack, aref enemy, float attackDmg, float hitDmg, bool isBlocked)
{
	//Если неубиваемый, то нетрогаем его
	if(LAi_IsImmortal(enemy)) return;
	//Применяем абилити
	/*float pBreak = 0.0;
	if(IsCharacterPerkOn(attack, "SwordplayProfessional"))
	{
		pBreak = pBreak + 0.25;
	}
	// Baste - critical hit check moved down
	float kDmg = 1.0;
	if(IsCharacterPerkOn(attack, "Rush"))
	{
		kDmg = 1.5;
		pBreak = pBreak + 0.5;
	}
	if(IsCharacterPerkOn(enemy, "Rush"))
	{
		pBreak = pBreak + 0.9;
	}*/ //Levis: moved to BladeFindPiercingProbability
	isBlocked = isBlocked && CheckAttribute(enemy,"equip.blade") && GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE) != "bladeX4";
	// PB: Disable blocking for enemies with either no sword or their fists equiped
	if(isBlocked)
	{
		//Вероятность пробивки
		float p = LAi_BladeFindPiercingProbability(attack, enemy, hitDmg);
		//p = p + pBreak;

		//Если шансов пробить нет, то ненаносим провреждения
//		if(p < 0.0) return;										// LDH removed 06Apr09
		//Если шансов пробить нет, то ненаносим провреждения
		if(rand(10000) > p*10000)	// if block is NOT pierced
		{
			// LDH rewrite 06Apr09
			if(GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "bladeX4")	// if attacker uses fists, he gets damaged instead
			{
				if(!LAi_IsImmortal(attack))
				{
					LAi_ApplyCharacterDamage(attack, 2*rand(GetCharacterSkill(attack, SKILL_FENCING)));	// LDH 0..20
					LAi_CheckKillCharacter(attack);
				}
//				return;		// LDH so blocked fists don't damage defender - 11Apr09
			}
			return;
		}
	}
	//Вычисляем повреждение
	float dmg = LAi_BladeCalcDamage(attack);
	float damage = LAi_BladeApplySkills(attack, enemy, dmg);
	// Baste - critical hit calculation changed -->
	float critical = 0.0;
	if(IsCharacterPerkOn(attack, "SwordplayProfessional"))
	{
		if(rand(100) <= 25)
		{
			critical = damage*2.0;
		}
	}
	else if(IsCharacterPerkOn(attack, "CriticalHit"))
	{
		if(rand(100) <= 10)
		{
			critical = damage*2.0;
		}
	}
	else
	{
		if(rand(100) <= 5)
		{
			critical = damage*2.0;
		}
	}
	if(isBlocked)
	{
		damage = damage*0.3;
		critical = critical*0.3;
	}
	bool noExp;		// PB: Whatever is on this line ends up changing from what you set. Positively BIZARRE behaviour!
	noExp = false;	// Baste: So we set it to false on THIS line instead
	if(CheckAttribute(attack, "chr_ai.group"))
	{
		if(CheckAttribute(enemy, "chr_ai.group"))
		{
			bool AttackEnemyGroup = attack.chr_ai.group == enemy.chr_ai.group;
			bool PlayerTrainingFight = CheckAttribute(GetMainCharacter(),"TrainingFight");
			bool AttackTrainingFight = HasSubStr(attack.id,"TrainingFight_");
			bool EnemyTrainingFight  = HasSubStr( enemy.id,"TrainingFight_");
			if(AttackEnemyGroup && !PlayerTrainingFight && !AttackTrainingFight && !EnemyTrainingFight)//MAXIMUS
			{
			// ccc mar05 REPLOSS tweak added
			//	PB: I don't think we need this; no harm done = no reploss needed
			//	LAi_ChangeReputation(attack, - REPLOSS);	// ccc rephit for attacking friends
			//	if(sti(attack.index) == GetMainCharacterIndex()) LogIt("CHANGE REP for player: " + -REPLOSS + " - attacking friends");	// LDH 19Dec08
				damage = 0.0; // dmg = 0.0;
				critical = 0.0;
				noExp = true;
			}
		}
	}
	if(critical > 0.0)
	{
		if(sti(attack.index) == GetMainCharacterIndex())
		{
			Log_SetStringToLog(XI_ConvertString("Critical Hit"));
		}
	}
	// Baste <--
	// TIH --> do not show XP messages for other characters, its annoying! Aug24'06
	bool resetshowXP = false;
	if(sti(attack.index) != GetMainCharacterIndex())
	{
		attack.donotshowXP = true;
		resetshowXP = true;
	}
	// TIH <--
	// if(!LAi_IsFightMode(enemy) && attack.equip.blade=="blade5") {damage = damage*(rand(5)+sti(attack.skill.Sneak)+5);}	// ccc sneakmod backstab

	//Наносим повреждение
	// Baste -->
	if(critical > 0.0)
	{
		LAi_ApplyCharacterDamage(enemy, MakeInt(ApplyArmor(enemy, attack, critical, true) + 0.5)); // GreatZen-NK
	}
	else
	{
		LAi_ApplyCharacterDamage(enemy, MakeInt(ApplyArmor(enemy, attack, damage, true) + 0.5)); // GreatZen-NK
	}
	//Проверим на смерть
	LAi_CheckKillCharacter(enemy);
	//Есть ли оружие у цели
	bool isSetBalde = (CheckAttribute(enemy, "equip.blade") == true);//(SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//Начисляем опыта
	if(critical > 0.0) damage = critical; // So EXP calculation takes critical damage into account
	float exp = LAi_BladeCalcExperience(attack, enemy, damage);
	// Baste <--
	if(LAi_IsDead(enemy))
	{
		//Начислим за убийство
		exp = exp + LAi_CalcDeadExp(attack, enemy);
		if(!isSetBalde)
		{
			// ccc mar05 REPLOSS tweak added
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS*3 + " - " + TranslateString("","undrawn blade 1")); 	// LDH 19Dec08
				LAi_ChangeReputation(attack, - REPLOSS*3); // NK tempfix for un-drawn blades 04-17
				if(IsMainCharacter(attack))		 //All near guards will attack you now. -Levis
				{
					LAi_group_FightGroups(LAI_GROUP_PLAYER, GetSoldiersGroup(GetCurrentLocationNation()), true);
				}
			}
		}
		// GR: REPLOSS for killing a stunned character
		if(CheckAttribute(enemy, "stuntime"))
		{
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS*3 + " - " + TranslateString("","stunned victim"));
				LAi_ChangeReputation(attack, - REPLOSS*3);
				if(IsMainCharacter(attack) && !CheckAttribute(enemy,"pickgold")) //All near guards will attack you now. -Levis
				{
					LAi_group_FightGroups(LAI_GROUP_PLAYER, GetSoldiersGroup(GetCurrentLocationNation()), true);
				}
			}
			exp = 0.0;
		}
	}
	//if(AUTO_SKILL_SYSTEM) { if(!LAi_IsDead(enemy)) { AddCharacterExpChar(enemy, "Defence", MakeInt(stf(exp*0.5 + 0.5))/2); } }// MAXIMUS! //Levis we moved this to when its really blocked
	if(!isSetBalde)
	{
		// ccc mar05 REPLOSS tweak added
		if(enemy.chr_ai.group != LAi_monsters_group)
		{
			if (CheckAttribute(enemy, "attacked_you")) // GR: No reploss if enemy attacked you.  If player attacks enemy who attacked you and is now running, show warning
			{
				if (sti(GetAttribute(attack, "index")) == GetMainCharacterIndex()) logit(TranslateString("", "Enemy lost weapon, trying to run!"));
			}
			else
			{
				if (!CheckAttribute(enemy,"pickgold") || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) != "bladeX3") // GR: no reploss if he robbed you and you use a thief's knife
				{
					if(sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS + " - " + TranslateString("","undrawn blade 2")); 	// LDH 19Dec08
					LAi_ChangeReputation(attack, - REPLOSS); // NK tempfix for un-drawn blades 04-17
				}
			}
		}
		exp = 0.0;
	}

	if(!noExp) { if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(attack, SKILL_FENCING, MakeInt(exp*0.5 + 0.5)); }else{ AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5)); } }
	if ( resetshowXP ) { DeleteAttribute(attack,"donotshowXP"); } // TIH do not show other characters XP increases
}

//Начисление повреждений при попадании
void LAi_ApplyCharacterFireDamage(aref attack, aref enemy, float kDist)
{
	//Levis -->
	// Only do this if PLAYER shoots using shotgun mode and only if there are no bullets left
	if(IsMainCharacter(attack) && globalSGMode && 1 > LAi_GetCharacterChargeCur(attack))
	{
		int GetSwordReady = 2;
		string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
		if(HasSubStr(weaponID, "LongRifle") && weaponID != "LongRifle_BT")	weaponID = "LongRifle"; // Exception to regular Long Rifle case
		switch(weaponID)
		{
			case "LongRifle_BT": GetSwordReady = -1; break;	// Quest Rifle with Telescope can reload in 1 second and uses no ammo
			case "pistol10"    : GetSwordReady =  0; break;	// Pump Shotgun               can reload in 1 second
			case "LongRifle"   : GetSwordReady =  1; break;	// Regular Long Rifles should not get your blade out
		}
		if(GetSwordReady == 0)
		{
			if(ENABLE_AMMOMOD)															// Check if any ammo left
			{
				if(!CheckCharacterItem(attack, "gunpowder"))	GetSwordReady = 2;
				if(!CheckCharacterItem(attack, "pistolgrapes"))	GetSwordReady = 2;
			}
		}
		if(GetSwordReady >  0)
		{
			globalSGMode = false;														// Drop from shotgun mode
			if(GetSwordReady >  1)
			{
				LAi_QuestDelay("get_sword_ready", 1.0);									// Get your sword again
			}
			else
			{
				LAi_SetFightMode(attack, false);
			}
		}
		if (attack.location == "Greenford_M_crypt" && LAi_IsImmortal(enemy) && enemy.model == "skel3") // PB: Can only kill this guy in shotgun mode
		{
			LAi_SetImmortal(enemy, false);
		}
	}
	//Levis <--
	//Если неубиваемый, то нетрогаем его
	if(LAi_IsImmortal(enemy)) return;
	//Вероятность поподания
	float p = LAi_GunCalcProbability(attack, kDist);
	//Если промахнулись, то выйдем
	if(rand(10000) > p*10000) return;
	//Начисляем повреждение
	float damage = LAi_GunCalcDamage(attack);
	// Baste - added possibility to score critical hit with pistol -->
	float critical = 0.0;
	int critchance = 5; //Added by Levis to allow more perks to add to crit.
	if(IsCharacterPerkOn(attack, "Gunman")) critchance += 5;
	if(IsCharacterPerkOn(attack, "GunProfessional")) critchance += 10;
	if(IsCharacterPerkOn(attack, "ImproveAiming")) critchance += 15;
	/*if(IsCharacterPerkOn(attack, "GunProfessional"))
	{
		if(rand(100) <= 15)
		{
			critical = damage*2.0;
		}
	}
	else if(IsCharacterPerkOn(attack, "Gunman"))
	{
		if(rand(100) <= 10)
		{
			critical = damage*2.0;
		}
	}
	else
	{
		if(rand(100) <= 5)
		{
			critical = damage*2.0;
		}
	}*/
	//Doing it this way now - Levis
	if(rand(100) <= critchance)
	{
		critical = damage*2.0;
	}
	//Аттака своей группы
	bool noExp;		// Changed to correspond to how it is in LAi_ApplyCharacterBladeDamage
	noExp = false;
	if(CheckAttribute(attack, "chr_ai.group"))
	{
		if(CheckAttribute(enemy, "chr_ai.group"))
		{
			if(attack.chr_ai.group == enemy.chr_ai.group && !CheckAttribute(GetMainCharacter(),"TrainingFight") && !HasSubStr(attack.id,"TrainingFight_") && !HasSubStr(enemy.id,"TrainingFight_"))//MAXIMUS
			{
				// LDH removed because fire might hit an enemy not in the current group.  Too flaky to use. 19Dec08
//				if(sti(attack.index) == GetMainCharacterIndex()) LogIt("CHANGE REP for player: " + -1 + " - firing on friend"); 	// LDH 19Dec08
//				LAi_ChangeReputation(attack, -1);
				damage = 0.0;
				critical = 0.0;
				noExp = true;
			}
		}
	}
	if(critical > 0.0)
	{
		if(sti(attack.index) == GetMainCharacterIndex())
		{
			Log_SetStringToLog(XI_ConvertString("Critical Hit"));
		}
	}
	if(critical > 0.0)
	{
		LAi_ApplyCharacterDamage(enemy, ApplyArmor(enemy, attack, critical, false) + 0.5)); // GreatZen-NK
	}
	else
	{
		LAi_ApplyCharacterDamage(enemy, ApplyArmor(enemy, attack, damage, false) + 0.5)); // GreatZen-NK
	}
	//Проверим на смерть

	// ccc sep05, keeps player & officers barely alive
	if(stf(enemy.chr_ai.hp)<1.0 && enemy.chr_ai.group==LAI_GROUP_PLAYER) enemy.chr_ai.hp = MIN_GUNATTACK_HP;

	LAi_CheckKillCharacter(enemy);
	//Есть ли оружие у цели
	bool isSetBalde = (SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//Начисляем опыт
	if(critical > 0.0) damage = critical; // So EXP calculation takes critical damage into account
	// Baste <--
	float exp = LAi_GunCalcExperience(attack, enemy, damage);
	if(LAi_IsDead(enemy))
	{
		//Начислим за убийство
		exp = exp + LAi_CalcDeadExp(attack, enemy);
		if(!isSetBalde)
		{
			// ccc mar05 REPLOSS tweak added
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS*3 + " - " + TranslateString("","firing on undrawn blade 1")); 	// LDH 19Dec08
				LAi_ChangeReputation(attack, - REPLOSS*3); // NK tempfix for un-drawn blades 04-17
				if(IsMainCharacter(attack))		//All near guards will attack you now. -Levis
				{
					LAi_group_FightGroups(LAI_GROUP_PLAYER, GetSoldiersGroup(GetCurrentLocationNation()), true);
				}
			}
			exp = exp*0.05;
		}
		// GR: REPLOSS for killing a stunned character
		if(CheckAttribute(enemy, "stuntime"))
		{
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS*3 + " - " + TranslateString("","stunned victim"));
				LAi_ChangeReputation(attack, - REPLOSS*3);
				if(IsMainCharacter(attack) && !CheckAttribute(enemy,"pickgold"))	//All near guards will attack you now. -Levis
				{
					LAi_group_FightGroups(LAI_GROUP_PLAYER, GetSoldiersGroup(GetCurrentLocationNation()), true);
				}
			}
			exp = exp*0.05;
		}
	}
	if(AUTO_SKILL_SYSTEM) { if(!LAi_IsDead(enemy)) { AddCharacterExpChar(enemy, "Defence", MakeInt(stf(exp*0.5 + 0.5))/2); } }// MAXIMUS!
	if(!isSetBalde)
	{
		// ccc mar05 REPLOSS tweak added
		if (!CheckAttribute(enemy,"chr_ai.group")) exp = 0.0;	// LDH 03Oct06
		else				// LDH group seems to be missing on boardings - 02Apr09
		{
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(sti(attack.index) == GetMainCharacterIndex())
					LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS + " - " + TranslateString("","firing on undrawn blade 2")); 	// LDH 19Dec08
				LAi_ChangeReputation(attack, -REPLOSS); // NK tempfix for un-drawn blades 04-17
			}
		}
		exp = 0.0;
	}
	if(!noExp) { if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(attack, "Accuracy", MakeInt(exp*0.5 + 0.5)); }else{ AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5)); } }
}

//--------------------------------------------------------------------------------
//NPC parameters
//--------------------------------------------------------------------------------

#event_handler("NPC_Event_GetAttackActive","LAi_NPC_GetAttackActive");
#event_handler("NPC_Event_GetDefenceActive","LAi_NPC_GetAttackDefence");
#event_handler("NPC_Event_GetAggresive","LAi_NPC_GetAggresive");
#event_handler("NPC_Event_GetFireActive","LAi_NPC_GetFireActive");
#event_handler("NPC_Event_EnableFire","LAi_NPC_EnableFire");

float npc_return_tmp;
bool npc_return_tmpb;

// NK 05-05-12:
// remember, level is 0...1, NOT 0...10

// for high level characters, should _always_ be doing something, either attack or block.

// dunno whether 1.0 = always do something, or if >1.0 value is needed.
//probability of attack. Value per sec. > 0
float LAi_NPC_GetAttackActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	/*npc_return_tmp = 0.3 + level*0.7;
	if(iRealismMode>0)
	{*/
		npc_return_tmp = (0.3 + level*0.7) * 3;
	//}
	float tmp = 0.3 + level*0.7;
	npc_return_tmp = (npc_return_tmp * GetDifficulty() + (5-GetDifficulty()) * tmp) / 5;
	// debug - npc_return_tmp = 9999;
	//trace("for chr " + chr.id + " of level " + level + " set attackactive " + npc_return_tmp);
	return npc_return_tmp;
}

// same here - 1.0 max???
//probability of defence. Value per sec. > 0
float LAi_NPC_GetAttackDefence()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	/*npc_return_tmp = 0.008 + level*0.08;
	if(iRealismMode>0)
	{*/
		npc_return_tmp = (0.333 + frnd()*0.1 + level*0.5) * randmult(0.1); //npc_return_tmp+ 0.5;
		//if (npc_return_tmp >0.9) npc_return_tmp = 0.9;
	//}
	float tmp = 0.008 + level*0.08;
	npc_return_tmp = (npc_return_tmp * GetDifficulty() + (5-GetDifficulty()) * tmp) / 5;
	//trace("for chr " + chr.id + " of level " + level + " set attackdefense " + npc_return_tmp);
	return npc_return_tmp;
}

//balance between defence and attack 0..1
float LAi_NPC_GetAggresive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	/*npc_return_tmp = rand(10)*0.1*(0.4 + level*0.6);
	if(iRealismMode>0)
	{*/
		//if(IsOfficer(&chr))
		npc_return_tmp = pow2(0.67 * randmult(0.1)-level*0.1, 1.0 + level*2.0);
		if(npc_return_tmp < 0.2) npc_return_tmp = pow2(npc_return_tmp, 0.33 + level/3.0);
		// NK
		//npc_return_tmp = npc_return_tmp+ 0.05;
		//if (npc_return_tmp >0.4) npc_return_tmp = 0.4;
	//}
	float tmp = rand(10)*0.1*(0.4 + level*0.6);
	npc_return_tmp = (npc_return_tmp * GetDifficulty() + (5-GetDifficulty()) * tmp) / 5;
	//trace("for chr " + chr.id + " of level " + level + " set aggressive " + npc_return_tmp);
	return npc_return_tmp;
}

//probability of fire. Value per sec. > 0
float LAi_NPC_GetFireActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	/*npc_return_tmp = 0.001 + level*0.06;
	if(iRealismMode>0)
	{*/
		npc_return_tmp = (npc_return_tmp+ 0.1) * 2.0; // NK add 2.0
		if (npc_return_tmp >0.5) npc_return_tmp = 0.5;
	//}
	float tmp = 0.001 + level*0.06;
	npc_return_tmp = (npc_return_tmp * GetDifficulty() + (5-GetDifficulty()) * tmp) / 5;
	//trace("for chr " + chr.id + " of level " + level + " set fireactive " + npc_return_tmp);
	return npc_return_tmp;
}

//is fire enable?
bool LAi_NPC_EnableFire()
{
	aref chr = GetEventData();
	/*float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmpb = false;
	if(iRealismMode>0)
	{*/
		npc_return_tmpb = true; // NK
		/*level = level + 0.02;
	}
	if(level > 0.1) npc_return_tmpb = true;*/
	//trace("for chr " + chr.id + " of level " + level + " set enablefire " + npc_return_tmpb);
	if(ENABLE_AMMOMOD==1 && sti(RecalcCharacterGun(chr))<=0) { npc_return_tmpb = false; }//MAXIMUS: character will not fire with not loaded gun
	return npc_return_tmpb;
}

#event_handler("Location_CharacterSGFire","LAi_Location_CharacterSGFire");
void LAi_Location_CharacterSGFire()
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float kDist = GetEventData();
	if(LAi_IsDead(enemy)) return;

	if(LAi_CharacterCanFire(attack)) LAi_CharacterFireExecute(attack, enemy, kDist, true);	// PB: Use normal damage calculations
/*	kDmg = LAi_GunCalcDamage(attack);
	//Реакция груп на атаку
	LAi_group_Attack(attack, enemy);
	if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(attack, "Accuracy", 100*kDmg); }
	else { AddCharacterExp(attack, 100*kDmg); }
	//Наносим повреждение
	LAi_ApplyCharacterDamage(enemy, MakeInt((5 + rand(5))*kDmg));
	//Проверим на смерть
	LAi_CheckKillCharacter(enemy);*/
}
