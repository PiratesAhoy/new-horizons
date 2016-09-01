

void LAi_NPC_Equip(ref chr, int rank, bool isWeapons, float GunProb)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// NK -->
	//model check
	int currentPeriod = GetCurrentPeriod();
	if(rank <= 0 ) rank = GetLevel(&chr); // NK fix 05-04-30
	int mdlidx = GetModelIndex(chr.model);
	if(mdlidx >= 0)
	{
		ref mdl = &models[mdlidx];
		if(CheckAttribute(mdl, "nogun")) GunProb = 0;
		if(CheckAttribute(mdl, "noblade")) isWeapons = false;
	}

	// NK friend/foe diff scaling 05-07-09
	int diffoffset = GetDifficulty();
	if(CheckAttribute(chr, "friend") && sti(chr.friend))
	{
		diffoffset = 5 - diffoffset;
	}
	// NK <--
	//give blade
	if(isWeapons)
	{
		if(!CheckAttribute(chr,"isIndian"))
		{
			// Scheffnow - weaponsmod -->
			string blade;
			if(ENABLE_WEAPONSMOD == 1)
			{
				blade = GetRandomBladeForLevel(rank-3+diffoffset, rank+diffoffset, 3+(diffoffset/2));
			}
			else
			{
				blade = LAi_NPC_EquipBladeSelection(rank);
			}
			// Scheffnow - weaponsmod <--

			// LDH test is also in LAi_NPC_EquipBladeSelection() and GetRandomBladeForLevel - 20Apr09
			aref bladeItm;
			Items_FindItem(blade,&bladeItm);

			// Sulan: fixed random weapon equip code -->
			bool isValidWeapon = false;
			int isNotPirate = false;
			for(int i=0;i<10;i++)
			{
				//  item is available for equip      item is not unique      item is already available in period        item is still available in period
				if (bladeItm.skipequip==false && stf(bladeItm.rare)>0.0 && currentPeriod>=sti(GetAttribute(bladeItm, "firstperiod")) && currentPeriod<=sti(GetAttribute(bladeItm, "lastperiod")))
				{
					isNotPirate = isSoldier(chr);
					//if(ModelIsType(chr.model, "Land_Officers")) trace("soldier model");
					if(CheckAttribute(bladeItm, "nation") && isNotPirate > 0)
					{
						if(bladeItm.nation!="")  // if weapon has a nation limit and the chr is a soldier
						{
							if(sti(bladeItm.nation)==isNotPirate) isValidWeapon = true; // weapon's nation must match chars nation
						}
						else
						{
							isValidWeapon = true;
						}
					}
					else
					{
						isValidWeapon = true;
					}
				}
				if(isValidWeapon)
				{
					break;
				}
				else
				{
					if(ENABLE_WEAPONSMOD == 1)
					{
						blade = GetRandomBladeForLevel(rank-3+diffoffset, rank+diffoffset, 3+(diffoffset/2));
					}
					else
					{
						blade = LAi_NPC_EquipBladeSelection(rank);
					}
					Items_FindItem(blade,&bladeItm);
				}
			}
			if(isValidWeapon==false)
			{
				blade = "blade36";  // Sulan: default blade: Hunting Sword
				Items_FindItem(blade,&bladeItm);
			}
			trace("Equip Character "+GetMySimpleName(chr)+" with "+bladeItm.id+" his nation: "+chr.nation+" blade nation="+bladeItm.nation);
		}
		else
		{
			blade = "bladearrows"; //JRH: Make indians use arrow
		}
		// Sulan <--

		GiveItem2Character(chr, blade);
		EquipCharacterByItem(chr, blade);

		//give gun
		if(GunProb > 0)
		{
			if(!CheckAttribute(chr,"isIndian"))	GunProb *= 0.25 + makefloat(diffoffset)/4.0;
			else								GunProb  = 1.0;
			if(frnd() <= GunProb)
			{
				// Scheffnow - weaponsmod -->
				string gun;
				if(ENABLE_WEAPONSMOD == 1)
				{
					//Levis make indians use bows
					if(!CheckAttribute(chr,"isIndian"))
					{
						gun = GetRandomGunForLevel(rank-3+diffoffset, rank+diffoffset, 3+(diffoffset/2));
					}
					else
					{
						gun = "pistolbow"; //TODO: Make a funtion to have it pick from several indian weapons once that is better aranged
					}
				}
				else
				{
					//Levis make indians use bows
					if(!CheckAttribute(chr,"isIndian"))
					{
						gun = LAi_NPC_EquipGunSelection(rank);
					}
					else
					{
						gun = "pistolbow"; //TODO: Make a funtion to have it pick from several indian weapons once that is better aranged
					}
				}
				// Scheffnow - weaponsmod <--

				//if(gun == "" && rand(100) < 20) gun = "pistol1";	//cccOA1
				if(gun != "")
				{
					aref gunItm;
					Items_FindItem(gun,&gunItm);
					if(CheckAttribute(chr,"isIndian"))
					{
						gunItm.rare = 0.1; //Levis else it will be changed
					}
					// ARF: fixed random weapon equip code (inspired from Sulan's blade code) -->
					bool isValidWeapon2 = false;
					for(int z=0;z<10;z++)
					{
						//  item is available for equip   item is not unique
						if (gunItm.skipequip==false && stf(gunItm.rare)>0.0)
						{
							// check if the weapon has only one attribute
							if(CheckAttribute(gunItm, "period"))
							{
								// if one attribute and the gun exists in that period
								if(currentPeriod>=sti(gunItm.period))
								{
									isValidWeapon2 = true; //ARF: no need of 'nation' check cause all guns have "no nation"
								}
							}
							else
							{
								//if it has "last" and "first" period check if the gun exists
								if(currentPeriod>=sti(GetAttribute(gunItm, "firstperiod")) && currentPeriod<=sti(GetAttribute(gunItm, "lastperiod")))
								{
									isValidWeapon2 = true; //ARF: no need of 'nation' check cause all guns have "no nation"
								}
							}
						}
						if(isValidWeapon2)
						{
							break;
						}
						else
						{
							if(ENABLE_WEAPONSMOD == 1)
							{
								gun = GetRandomGunForLevel(rank-3+diffoffset, rank+diffoffset, 3+(diffoffset/2));
							}
							else
							{
								gun = LAi_NPC_EquipGunSelection(rank);
							}
							Items_FindItem(gun,&gunItm);
						}
					}
					if(isValidWeapon2==false)
					{
						if(GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)	gun = "pistol1";	// ARF: default gun: Short Pistols
						else													gun = "pistol11";	// JRH: wheellock
						Items_FindItem(gun,&gunItm);
					}
					// ARF (disabled CCC code, cause if weapons is SWAK or building kit, they already equip pistol1) <--

					// ccc aug 05 temporary fix against NPCs equiping SWAK and building kit items
					//if(gunItm.skipequip==true) gun="pistol1";
					// ccc end

					GiveItem2Character(chr, gun);
					EquipCharacterByItem(chr, gun);
					//Log_SetStringToLog(gun + ", equipping " + chr.equip.gun);
				}
			}
		}

		LAi_NPC_Ammo(chr); // PB: Call separate function
	}
	//if(LogsToggle && CheckAttribute(chr,"equip.blade"))
	//{
	//	if(CheckAttribute(chr,"equip.gun")) { Log_SetStringtoLog(LanguageConvertString(tmpLangFileID,"You smell some gunpowder about...")); }
	//	else { Log_SetStringtoLog(LanguageConvertString(tmpLangFileID,"You catch a glint of cold steel.")); }
	//}
	// NK <--
	//LanguageCloseFile(tmpLangFileID);
}

void LAi_NPC_Ammo(ref chr)
{
	// PB: Clear Existing Ammo -->
	DeleteAttribute(chr, "items.pistolbullets");
	DeleteAttribute(chr, "items.pistolgrapes");
	DeleteAttribute(chr, "items.musketbullets");
	DeleteAttribute(chr, "items.bladearrows");
	DeleteAttribute(chr, "items.gunpowder");
	// PB: Clear Existing Ammo <--

	// JRH fix oct 06: rewritten old did not give any ammo to NPCs, amount reduced -->
	//Levis made sure you always have at least 1 bullet
	if (ENABLE_AMMOMOD) {	// LDH change

		string weaponID = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
		aref weapon;
		Items_FindItem(weaponID, &weapon);
		bool givepowder = false;

		if(CheckAttribute(weapon, "shottype") && weapon.shottype != "")
		{
			if(weapon.shottype == "pb" || weapon.shottype == "pb2") { TakenItems(chr, "pistolbullets", 1+rand(2)); givepowder = true; }

			if(weapon.shottype == "pg" || weapon.shottype == "pg2") { TakenItems(chr, "pistolgrapes", 1+rand(2)); givepowder = true; }

			if(weapon.shottype == "mb") { TakenItems(chr, "musketbullets", 1); givepowder = true; } //Always 1 bullet

			if(weapon.shottype == "ar") { TakenItems(chr, "bladearrows", rand(2)); givepowder = false; } //Levis for indians (you will always have at least some arrows) JRH: rand(2) only as 1 arrow always got as a blade
		}
		if(givepowder)
		{
			TakenItems(chr, "gunpowder", rand(3));
		}
	}
	//<-- JRH gives this to officers & enemies, officers are also equipped by Enc_Officers_dialog
}

string LAi_NPC_EquipBladeSelection(int rank)
{
	// LDH rewritten to match GetRandomBladeForLevel() - 08May09
	int intMinLevel  = iClamp(0, 8, rank-4);
	int intMaxLevel  = iClamp(1, GetBladeMaxLevel(), rank+2);
	int intMinBlade  = GetFirstBladeForLevel(intMinLevel);
	int intMaxBlade  = GetLastBladeForLevel(intMaxLevel);
	int intRandBlade = intMinBlade + Rand(intMaxBlade - intMinBlade);

	float rareconst = 1.0; //this multiplies the rare percentage, so that it's more possible to get rare blades
	rareconst *= (1 + ((makefloat(GetDifficulty())-1)/3.0)); 	//difficulty  (1 + (1..4 - 1) / 3) = 1..2

	ref refBlade;
	float randrare;

	//Trace("min = " + intMinLevel + ", max = " + intMaxLevel +
	//	", firstblade = " + intMinBlade + ", lastblade = " + intMaxBlade +
	//	", select = " + intRandBlade);

	bool bFound = false;
	while (!bFound && intRandBlade >= 0)
	{
		makeref(refBlade,BladeItems[intRandBlade]);
		randrare = frnd();

		//Trace("Testing " + intRandBlade + " = " + strLeft(refBlade.id + ",       ", 11) +
		//	"minlvl = " + stringRet(sti(refBlade.minlevel)<10," ","") + refBlade.minlevel + ", " +
		//	"stats = " + strLeft(sti(refBlade.dmg_min) + ":" + sti(refBlade.dmg_max) + ":" + refBlade.piercing + ":" + refBlade.block + ",     ",13) +
		//	"rare = " + strLeft(f2s2(stf(refBlade.rare)),4) + ", " +
		//	"rand = " + strLeft(f2s2(randrare/rareconst),6)
		//	);

		bFound = refBlade.skipequip == false && randrare < stf(refBlade.rare)*rareconst; // && stf(refBlade.rare) != 0.0
		intRandBlade--;
	}
	string blade = refBlade.id;
	if (!bFound) blade = "blade4";
	//Trace("Using blade " + blade);
	return blade;
}

// NK -->
string LAi_NPC_EquipGunSelection(int rank)
{
	int min = rank - 4;
	if(min < 1) min = 1;
	int max = rank + 2;
	if(max < 1) max = 1;
	if(min > 8) min = 8;
	int sel = rand(max - min) + min;
	float rareconst = 1.0; //this multiplies the rare percentage, so that it's more possible to get rare guns
	rareconst *= makefloat(GetDifficulty())/4.0;	//difficulty
	string gun = "pistol1"; // now DOES have a default
	if(GetCurrentPeriod() < PERIOD_GOLDEN_AGE_OF_PIRACY) gun = "pistol11"; // JRH: wheellock
	//Log_SetStringToLog("Rank: " + sel);

	//find available guns
	ref itm;
	int firstgun = 256;
	int lastgun = -1;
	int totalguns = 0;
	int i;
	int gunsID[256];
	int gunsML[256];

	//find all guns
	for(i=0; i<ITEMS_QUANTITY; i++)
	{
		makeref(itm,Items[i]);
		if(!CheckAttribute(itm,"groupID")) continue;
		if(itm.groupID == GUN_ITEM_TYPE)
		{
			if(i < firstgun) firstgun = i;
			if(i > lastgun) lastgun = i;
			gunsID[totalguns] = i;
			totalguns++;
		}
	}
	//Log_SetStringToLog("Total avail = " + totalguns);
	//sort guns high->low by minlevel
	for(i = firstgun; i <= lastgun; i++)
	gunsML[i - firstgun] = sti(Items[i].minlevel);

	int x,y,holder,place;
	for(x = 0; x < totalguns; x++)
	{
		for(y = 0; y < totalguns-1; y++)
		{
			if(gunsML[y] < gunsML[y+1])
			{
				holder = gunsML[y+1];
				place = gunsID[y+1];
				gunsML[y+1] = gunsML[y];
				gunsID[y+1] = gunsID[y];
				gunsML[y] = holder;
				gunsID[y] = place;
			}
			if(gunsML[y] == gunsML[y+1] && Rand(1))
			{
				holder = gunsML[y+1];
				place = gunsID[y+1];
				gunsML[y+1] = gunsML[y];
				gunsID[y+1] = gunsID[y];
				gunsML[y] = holder;
				gunsID[y] = place;
			}
		}
	}

	//find gun to use
	for(i = 0; i < totalguns; i++)
	{
		// LDH find error in rare
		if(!CheckAttribute(Items[gunsID[i]],"rare")) continue;
		//		Trace("Testing gun " + i + ", rare = " + Items[gunsID[i]].rare);
		if(sel >= gunsML[i]*(2.0 - (makefloat(GetDifficulty()-1))/3.0) && frnd() <= stf(Items[gunsID[i]].rare) * rareconst) // difficulty added
		{ gun = Items[gunsID[i]].id; /*Log_SetStringToLog("Using " + Items[gunsID[i]].id);*/ break; }
	}
	//Log_SetStringToLog("2Using " + Items[gunsID[i]].id);
	return gun;
}

// NK <--
