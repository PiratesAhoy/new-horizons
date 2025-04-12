#include "BUILDINGS\Buildingkit.c" //Levis: moved to seperate file for easier management

void ChangeTownNation (string townsk, int nat)		// functioncall must include townname, i.e. townsack attribute, and nationindex 
{
	// NK to use forts interface in towntable.c 05-07-10
	int n;
	ref town = GetTownFromID(townsk);
	int numforts = GetTownNumForts(townsk);
	ref ch;
	for(n = 0; n < numforts; n++)
	{
		ch = GetTownFortCommander(townsk, n);
		/*ref commander = CharacterFromID(	// the fortcommander of this town
		if (townsk == "Falaise de Fleur") commander = (characterFromID("FalaisedeFleur Commander"));	// why didn't Akella...
		else if (townsk == "Isla Muelle") commander = (characterFromID("IslaMuelle Commander"));	// stick to one spelling system ? @@
		else commander = (characterFromID(townsk + " Commander"));*/

		ch.nation = nat;						// gets the nation from the functioncall
		ch.model = SelectSoldierModelByNation(nat, "Officer");	// NK was soldier. 05-07-10 - and the appropriate charmodel
	}
	SetTownNation(townsk, nat);				// town gets the nation from the functioncall

	for(n = 0; n < CHARACTERS_QUANTITY; n++)		// loop to cycle through all characters
	// NK 05-04-05 change to CHARACTERS_QUANTITY. Fantoms won't be changed, but that's OK because this won't be run when there are any.
	{
		makeref(ch, Characters[n]);		// defines ch as character who has loopindex as characterindex

		if(CheckAttribute(ch, "sound_type") && ch.sound_type == "soldier")	// if ch is a soldier
		{
			if(CheckAttribute(ch, "location") && FindLocation(Characters[ch].location) >= 0)
				// and if ch has a location
			{
				if(CheckAttribute(Locations[FindLocation(ch.location)],"townsack") && Locations[FindLocation(ch.location)].townsack == townsk)	// and if ch is in this town
				{
					ch.nation = nat				// ch gets nation from functioncall
					ch.model = SelectSoldierModelByNation(nat, "Soldier");	// and a new uniform
					facemaker(ch);				// and the appropriate facepicture
					//Log_SetStringToLog(ch.id + " changed ");

					// ccc oct 06  fix to remove St Martin siegearmies after towncapture
					ref exit;
					if(townsk=="Philipsburg" )
					{
						ChangeCharacterAddress(Ch, "none", "");	// removes soldiers

						exit = &Locations[FindLocation("Philipsburg_exit")];
						if(CheckAttribute(exit,"building") ) DeleteAttribute(exit,"building");    // removes siege guns
					}

					if(townsk=="Marigot" )
					{
						ChangeCharacterAddress(Ch, "none", "");	// removes soldiers

						exit = &Locations[FindLocation("Marigot_exit")];
						if(CheckAttribute(exit,"building") ) DeleteAttribute(exit,"building");    // removes siege guns
					}
					// ccc oct 06 end
				}
			}
		}
	}
	PlayStereoSound("INTERFACE\notebook.flac");		// notification by sound and screenmessage
	Log_SetStringToLog(townsk + " " + TranslateString("","has been occupied by") + " " + TranslateString("",GetNationDescByType(nat)) + " " + XI_ConvertString("forces"));
}

void Explosion(ref chr, int damage)		// Explosion hurts character "chr" with "damage" hp
{
	float x, y, z;			// coordinates for effects...
	GetCharacterPos(chr, &x, &y, &z);	// ...are those of the chr 
	CreateParticleSystemX("blast", x, y, z, x, y, z,0);	// effects at that pos
	CreateParticleSystemX("fort_fire", x, y, z, x, y, z,5);
	// LDH changed 23Mar09
	PlayStereoSound("OBJECTS/SHIPCHARGE/cannon_fire3.flac");
	if(chr.sex == "woman") PlayStereoSound("OBJECTS\VOICES\DEAD\female\dead_wom5.wav");
	else PlayStereoSound("OBJECTS\VOICES\DEAD\male\dead6.wav");

	int num = FindNearCharacters(chr, 3.0, -1.0, -1.0, 0.001, false, true);
		// checks if there are other people around the initial target. 3 is the checkradius

	for(int j = 0; j <= num; j++)	// the following loop runs for each near character
	{
		int idx = sti(chrFindNearCharacters[j].index);	// defines near character as idx
		ref findCh;
		findCh = GetCharacter(idx);	// necessary? to get object for next line

    // ccc dec05 rewritten to ensure distance is correct and to keep playergroup alive
		float dist = -1.0;
  	if(GetCharacterDistByChr3D(chr, findCh, &dist) && dist<4)
    {
		LAi_ApplyCharacterDamage(findCh, damage);		// damage is applied to findCh
  	if (sti(LAi_GetCharacterHP(findCh)) < damage+1) // and if that's too much..
      { 
        if(findCh.chr_ai.group != LAI_GROUP_PLAYER)  // ..and he's not in playergroup..
        {Lai_KillCharacter(findCh);} // ..he is being killed
        else{findCh.chr_ai.hp = 10} // playergroup barely survives
      }
  	}
  }	// end of loop

	LAi_ApplyCharacterDamage(chr, damage);		// damage is applied to chr
	if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(Chr, "Defence", damage*3 ); }
	else { AddPartyExp(Chr, damage*3 ); }// some expoints as compensation
	if (sti(LAi_GetCharacterHP(chr)) < damage+1) Lai_KillCharacter(chr);
		// and if that's too much he is being killed
}

// ccc dec05 changed to use different models based on modeltype
void Ambush(string modeltype, int bmax, string mainrel, string npcrel, string locator)		// horde of attackers appears
// bmax is number of chr, mainrel relation to player, npcrel to NPCs
{
	// Nation
	int iNation = ALL_NATIONS;
	if(modeltype == "Soldiers" || modeltype == "Navy_office4" || HasSubStr(modeltype, "Soldier")) // PB: Add ANY soldiers
	{
		iNation = GetCurrentLocationNation();	// ccc Nov05: Make local guards if modeltype is "Soldiers"
	}

	LAi_CreateFantomGroup(modeltype, bmax, mainrel, npcrel, iNation, "", 0, true, "", "", "", locator);

	LogIt(TranslateString("","ALARM!  AN AMBUSH!!!"));
	PlaySound("OBJECTS\abordage\abordage2.wav");
}

// ccc Captain's Challenge, function to equip chref from new weapons locker
// NK 05-05-10 add armor, make 1 log line, use less variables
void EquipFromLocker(ref chref)
{
	aref arItm;
	ref loc = &locations[FindLocation("Tutorial_Deck")];
	string logstr = "";
	string curitemname;
	int curitemnr;
	DeleteAttribute(&chref, "items"); // NK 05-07-18 delete all items from chref.
	
	// blade
	string curitem = FindLockerItemByGroup(chref, BLADE_ITEM_TYPE); 
	if (curitem != "") 
	{
		GiveItem2Character(chref, curitem);
		EquipCharacterByItem(chref, curitem);

		Items_FindItem(curitem,&arItm);
		curitemname = TranslateString("",arItm.name);
		logstr = "a "+curitemname;

		curitemnr = sti(loc.WeaponsLocker.items.(curitem)) - 1; // KK
		if(curitemnr<=0) DeleteAttribute(&loc,"WeaponsLocker.items."+curitem); // KK
		else loc.WeaponsLocker.items.(curitem) = curitemnr; // KK
	}
	else
	{
		GiveItem2Character(chref, BOARDER_SPAREBLADE);
		EquipCharacterByItem(chref, BOARDER_SPAREBLADE);	// spare weapon if next line yields no blade
	}

	// gun
	curitem = FindLockerItemByGroup(chref, GUN_ITEM_TYPE); 
	if (curitem != "") 
	{
		GiveItem2Character(chref, curitem);
		EquipCharacterByItem(chref, curitem);

		Items_FindItem(curitem,&arItm);
		curitemname = TranslateString("",arItm.name);
		if(logstr == "") { logstr = XI_ConvertString("a") + " " + curitemname; }
		else { logstr += " " + XI_ConvertString("and") + " " + XI_ConvertString("a") + " "+curitemname; }

		curitemnr = sti(loc.WeaponsLocker.items.(curitem)) - 1; // KK
		if(curitemnr<=0) DeleteAttribute(&loc,"WeaponsLocker.items."+curitem); // KK
		else loc.WeaponsLocker.items.(curitem) = curitemnr; // KK

		//JRH ammo -->
    		if (ENABLE_AMMOMOD)
    		{
			string weaponID = GetCharacterEquipByGroup(chref,GUN_ITEM_TYPE);
			aref weapon;
			Items_FindItem(weaponID, &weapon);

			//this ammo is just for looting reasons
			TakenItems(chref, "gunpowder", 1);

			if(CheckAttribute(weapon, "shottype"))
			{
				if(weapon.shottype == "pg2" || weapon.shottype == "pg") TakenItems(chref, "pistolgrapes", 1 + rand(1));
				if(weapon.shottype == "mb") TakenItems(chref, "musketbullets", 1);
				if(weapon.shottype == "pb2" || weapon.shottype == "pb") TakenItems(chref, "pistolbullets", 1 + rand(1));
			}
		
			float charge = stf(chref.chr_ai.charge);
			if(charge < 1.0)
			{
				charge = 1.0;
				chref.chr_ai.chargeprc = "0";
			}
			chref.chr_ai.charge = charge;
			
		}
		//<-- JRH ammo
	}
	
	// armor NK 05-05-10
	curitem = FindLockerItemByGroup(chref, ARMOR_ITEM_TYPE);
	if (curitem != "")
	{
		GiveItem2Character(chref, curitem);
		EquipCharacterByItem(chref, curitem);

		Items_FindItem(curitem,&arItm);
		curitemname = TranslateString("",arItm.name);
		if(logstr == "") { logstr = curitemname; }
		else { logstr += " " + XI_ConvertString("and") + " " + curitemname; }

		curitemnr = sti(loc.WeaponsLocker.items.(curitem)) - 1; // KK
		if(curitemnr<=0) DeleteAttribute(&loc,"WeaponsLocker.items."+curitem); // KK
		else loc.WeaponsLocker.items.(curitem) = curitemnr; // KK
	}
	
	// PB: Potions
	curitem = FindLockerItemByGroup(chref, POTION_ITEM_TYPE);
	if (curitem != "")
	{
		GiveItem2Character(chref, curitem);
		EquipCharacterByItem(chref, curitem);

		Items_FindItem(curitem,&arItm);
		curitemname = TranslateString("",arItm.name);
		if(logstr == "") { logstr = curitemname; }
		else { logstr += " " + XI_ConvertString("and") + " " + curitemname; }

		curitemnr = sti(loc.WeaponsLocker.items.(curitem)) - 1; // KK
		if(curitemnr<=0) DeleteAttribute(&loc,"WeaponsLocker.items."+curitem); // KK
		else loc.WeaponsLocker.items.(curitem) = curitemnr; // KK
	}
	// PB: Cursed Coins -->
	curitem = "cursedcoin";
	if(!CheckAttribute(loc, "WeaponsLocker.items."+curitem)) curitem = "";
	if (curitem != "")
	{
		GiveItem2Character(chref, "cursedcoin");

		curitemnr = sti(loc.WeaponsLocker.items.(curitem)) - 1; // KK
		if(curitemnr<=0) DeleteAttribute(&loc,"WeaponsLocker.items."+curitem); // KK
		else loc.WeaponsLocker.items.(curitem) = curitemnr; // KK
	}
	// PB: Cursed Coins <--

	//JRH weaponslocker -->
	if (ENABLE_AMMOMOD)
    {
		DeleteAttribute(&loc,"WeaponsLocker.items.gunpowder");
		DeleteAttribute(&loc,"WeaponsLocker.items.pistolbullets");
		DeleteAttribute(&loc,"WeaponsLocker.items.pistolgrapes");
		DeleteAttribute(&loc,"WeaponsLocker.items.musketbullets");
	}
	//<-- JRH weaponslocker

	Trace("BOARDING: EquipFromLocker got: " + logstr );	// LDH - 23Dec08
}


// ccc Captain's Challenge, function to check if chref can be equiped from new weapons locker
string FindLockerItemByGroup(ref chref, string groupID)
{
	// TIH --> new method that only loops through what is IN the weapons locker, not ALL items in the game Aug31'06
	// this also will first pick out things that are better than others, so it helps ignore junk
	// if you have BLADEDAMAGE mod on, dont put 'worn' items in your locker if you dont want them breaking!
	ref loc = &Locations[FindLocation("Tutorial_Deck")]; // ? -> NK not reget this each time 05-05-10
	if (CheckAttribute(loc,"WeaponsLocker.items")) // KK
	{
		aref lockerItems;
		makearef(lockerItems, loc.WeaponsLocker.items); // KK
		if ( GetAttributesNum(lockerItems) > 0 )
		{
			int i,n;
			int itmqual;
			int high = -1;
			string highid = "";
			string curId = "";

			for (i = GetAttributesNum(lockerItems)-1; i >= 0; i--)// go through the locker items
			{
				aref refItm;
				curId = GetAttributeName(GetAttributeN(lockerItems, i));
				n = Items_FindItem(curId,&refItm);// returns item index and fills aref refItm

				if ( n < 0 ) 									continue;// invalid item
				if ( !CheckAttribute(refItm,"id") ) 			continue;// no valid id
				if ( !CheckAttribute(refItm,"groupID") ) 		continue;// no valid groupid
				if ( refItm.groupID != groupID ) 				continue;// not what we are looking for, move along now
				if ( sti(loc.WeaponsLocker.items.(curId)) < 1 ) continue;// not enough in box // KK

				if ( groupID == GUN_ITEM_TYPE )// must check requisits on guns
				{
					if( !CheckAttribute(refItm,"chargeQ") ) { continue; }// invalid gun
					if( sti(refItm.chargeQ) >= 2 && !IsCharacterPerkOn(chref,"Gunman") )			{ continue; }// no requisite
					if( sti(refItm.chargeQ) >= 4 && !IsCharacterPerkOn(chref,"GunProfessional") )	{ continue; }// no requisite
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
					{
						if( sti(refItm.chargeQ) >= 6 && !IsCharacterPerkOn(chref,"GunFighter") )		{ continue; }// no requisite
					}
				}

				// now we compare by 'n', but using sorted arrays to do it
				switch (groupID)
				{
					case BLADE_ITEM_TYPE:
						n = NativeFindCharacter(&BladeItems, curId);
					break;
					case GUN_ITEM_TYPE:
						n = NativeFindCharacter(&GunItems, curId);
					break;
					//default:
						// armor has no special sorted arrays to compare too
						// n is already set
				}
				if (n <= high) { continue; }
				// this only happens with blades, and only if the blade damage mod is enabled for the second check
				if (groupID == BLADE_ITEM_TYPE)
				{
					itmqual = GetItemQualityByID(refItm.id);
					if (itmqual > -1) // some blades dont have quality set (or weapons mod is off), so don't check those
					{
						if (itmqual == 0) { continue; }
						if (BLADEDAMAGE_ENABLED && itmqual == 1) { continue; }
					}
				}
				// now set the high to be used for further iteration compares
				high = n;
				highid = curId;
			}
			if(high > -1) return highid;
		}
	}
	return "";

	/* old method left here for tracking purposes
	int i,n;
	ref refItm;
	ref loc = &Locations[FindLocation("Tutorial_Deck")]; // NK not reget this each time 05-05-10
	for(i=MAX_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		string itid = refItm.id
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(loc,"WeaponsLocker.items."+refItm.id) ) continue; // KK
		if( sti(loc.WeaponsLocker.items.(itid) )<1 ) continue; // KK

		if(groupID==GUN_ITEM_TYPE)
		{
			if( !CheckAttribute(refItm,"chargeQ") ) continue;
			n = sti(refItm.chargeQ);
			if(n<2) {return refItm.id;}
			if(n<4)
			{
				if( IsCharacterPerkOn(chref,"Gunman") ) {return refItm.id;}
				else continue;
			}
			if( IsCharacterPerkOn(chref,"GunProfessional") )	{return refItm.id;}
			continue;
		}
		return refItm.id;
	}
	return "";
	*/
	// TIH <--
}

// ccc

// NK get weaps back 05-05-10 -->
void GiveItemsBack(ref chr)
{
	string stmp;
	string stmp1;
	ref loc = &Locations[FindLocation("Tutorial_Deck")];

	// TIH --> rewritten to use proper equip function Aug31'06
	stmp = GetCharacterEquipByGroup(&chr, BLADE_ITEM_TYPE);
	if( stmp != "" && stmp != BOARDER_SPAREBLADE) // PB: Don't put "free" weapons in the weaponslocker
	{
		if(CheckAttribute(loc, "WeaponsLocker.items."+stmp)) { loc.WeaponsLocker.items.(stmp) = sti(loc.WeaponsLocker.items.(stmp)) + 1; } // KK
		else { loc.WeaponsLocker.items.(stmp) = 1; } // KK
		stmp1 = stmp;
	}
	stmp = GetCharacterEquipByGroup(&chr, GUN_ITEM_TYPE);
	if( stmp != "" )
	{
		if(CheckAttribute(loc, "WeaponsLocker.items."+stmp)) { loc.WeaponsLocker.items.(stmp) = sti(loc.WeaponsLocker.items.(stmp)) + 1; } // KK
		else { loc.WeaponsLocker.items.(stmp) = 1; } // KK
		stmp1 = stmp1 + " " + stmp;
	}
	if (!LAi_IsDead(chr)) // do not do if the character died... their armor is considered busted
	{
		stmp = GetCharacterEquipByGroup(&chr, ARMOR_ITEM_TYPE);
		if( stmp != "" )
		{
			if(CheckAttribute(loc, "WeaponsLocker.items."+stmp)) { loc.WeaponsLocker.items.(stmp) = sti(loc.WeaponsLocker.items.(stmp)) + 1; } // KK
			else { loc.WeaponsLocker.items.(stmp) = 1; } // KK
			stmp1 = stmp1 + " " + stmp;
		}
	}
	// PB: Potions
	stmp = FindCharacterItemByGroup(&chr, POTION_ITEM_TYPE);
	if( stmp != "" )
	{
		if(CheckAttribute(loc, "WeaponsLocker.items."+stmp)) { loc.WeaponsLocker.items.(stmp) = sti(loc.WeaponsLocker.items.(stmp)) + 1; } // KK
		else { loc.WeaponsLocker.items.(stmp) = 1; } // KK
		stmp1 = stmp1 + " " + stmp;
	}
	// PB: Cursed Coins
	if (!LAi_IsDead(chr)) // do not do if the character died... their cursed coin was lost
	{
		stmp = "";
		if(CheckCharacterItem(chr, "cursedcoin"))	stmp = "cursedcoin";
		if( stmp != "" )
		{
			if(CheckAttribute(loc, "WeaponsLocker.items."+stmp)) { loc.WeaponsLocker.items.(stmp) = sti(loc.WeaponsLocker.items.(stmp)) + 1; } // KK
			else { loc.WeaponsLocker.items.(stmp) = 1; } // KK
			stmp1 = stmp1 + " " + stmp;
		}
	}
	Trace("BOARDING: GiveItemsBack returned: "+ stmp1 );	// LDH 23Dec08
}
// NK <--

// ccc skillearning
/*void skillearning(ref chr, string skillnm, int lp)
{
	int step = 10;
	int skillpt = sti(chr.skill.(skillnm));
	if(skillpt>9) return;

	switch(skillnm)
	{
	case "Fencing": step = 20; break;
	case "leadership": step = 40; break;
	case "defence": step = 20; break;

	}
	if(!CheckAttribute(chr,"skill."+skillnm+".lp")) chr.skill.(skillnm).lp = 0; // NK
	int newLp = sti(chr.skill.(skillnm).lp) + lp;
	chr.skill.(skillnm).lp = newLp;

	int skillPtSqr = skillpt*skillpt*step;
	if(newLp > skillPtSqr)
	{
		chr.skill.(skillnm) = skillpt + 1;
		chr.skill.(skillnm).lp = newLp - skillPtSqr;
		logit(chr.name + " " + chr.lastname + TranslateString("","'s") + " " + XI_ConvertString(skillnm) + " " + TranslateString("","skill has improved to") + " " + chr.skill.(skillnm) );
		PlayStereoSound("interface\new_level.flac");
	}
/*
	if (sti(chr.index) == GetMainCharacterIndex())
	{

	logit(chr.lastname + "'s " + skillnm + "skill is now " + chr.skill.(skillnm) + " lp: "  + chr.skill.(skillnm).lp);
	PlaySound("INTERFACE\button3.flac");
	}
*/
//}

// NK -->

// 05-07-10
// set citizens and guards (rel) to targetgroup. Done both for generic DEFAULT and GUARDS group, plus also local guards/citizens (if applicable)
void SetAllNormalGroupsRel(string targetgroup, string rel)
{
	string citgroup = GetCurrentCitizenGroup();
	string solgroup = GetCurrentSoldierGroup();
	if(citgroup != LAI_DEFAULT_GROUP) LAi_group_SetRelation(LAI_DEFAULT_GROUP, targetgroup, rel);
	if(solgroup != LAI_GROUP_GUARDS) LAi_group_SetRelation(LAI_GROUP_GUARDS, targetgroup, rel);
	LAi_group_SetRelation(citgroup, targetgroup, rel);				
	LAi_group_SetRelation(solgroup, targetgroup, rel);
}

// 05-07-26
// for corpse and stun, mostly
void LAI_group_SetRelationWithAllStock(string targetgroup, string rel)
{
	string citgroup = GetCurrentCitizenGroup();
	string solgroup = GetCurrentSoldierGroup();
	if(citgroup != LAI_DEFAULT_GROUP) LAi_group_SetRelation(LAI_DEFAULT_GROUP, targetgroup, rel);
	if(solgroup != LAI_GROUP_GUARDS) LAi_group_SetRelation(LAI_GROUP_GUARDS, targetgroup, rel);
	LAi_group_SetRelation(citgroup, targetgroup, rel);				
	LAi_group_SetRelation(solgroup, targetgroup, rel);
	LAi_group_SetRelation(LAI_GROUP_PLAYER, targetgroup, rel);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, targetgroup, rel);
}

float GetAttackLuckMod(ref chr)
{
	return (0.75 + (makefloat(CalcCharacterSkill(&chr, SKILL_SNEAK))/50.0));
}

void LAi_AttemptSteal(aref attack, aref enemy, aref weapon)
{
	if(CheckAttribute(enemy,"itemtrade")) MerchantGuildAttack(enemy, false);	// PB: For streetmerchants only
	if(frnd() < stf(weapon.steal)*GetAttackLuckMod(&attack)) // chance of successful theft are 75% + luckskill
	{
		bEnemyExchange = true; // added by MAXIMUS
		LaunchCharacterItemChange(enemy);	// ccc jun 05 stealinterface
		PlaySound("INTERFACE\took_item.flac");
		// PB: Restore After Location Reload -->
		enemy.stuntime.old_type = enemy.chr_ai.type;
		enemy.stuntime.group    = enemy.chr_ai.group;
		// PB: Restore After Location Reload <--
		LAi_SetCitizenType(enemy);	// makes disarmed victim flee
		LAi_group_Attack(attack, enemy);
	} else {
		if(enemy.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); }	// victim raises alarm
		else{PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_f_c_016.wav"); }
		LAi_group_Attack(attack, enemy); // NK do this too
		SetAllNormalGroupsRel(LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // NK do this in one function 05-07-10
		ChangeCharacterReputation(attack, -3);		// rephit for being caught
		SoldierReinforcements(enemy); //PB: If you loot a town guard
	}
}

void LAi_PlayHitGFX(aref attack, aref enemy, aref weapon, string effects_to_play)
{
	int i;
	float x, y, z;			// coordinates for effects
	GetCharacterPos(ARefChrToRef(enemy), &x, &y, &z);	// determines position of initial target
	string tmpstr;
	string cureff = GetSubString(effects_to_play, " ", 0);
	int cureffnum = 0;
	while(cureff != "")
	{
		if(CheckAttribute(weapon, cureff+".FX.qty"))
		{
			for(i = 0; i < sti(weapon.(cureff).FX.qty); i++)
			{
				tmpstr = "effect"+i;
				CreateParticleSystem(weapon.(cureff).fx.(tmpstr), x, y+1, z, 0.0, 0.0, 0.0, sti(weapon.(cureff).fx.(tmpstr).time));
			}
		}
		cureffnum++;
		cureff = GetSubString(effects_to_play, " ", cureffnum);
	}
}
// NK <--

// PB -->
#event_handler("PlaySoundAfterDelay_event", "PlaySoundAfterDelay")
void PlaySoundAfterDelay()
{
	string soundname = GetEventData();
	PlaySound(soundname);
}

void MerchantGuildAttack(aref enemy, bool bKill)
{
	ref PChar = GetMainCharacter();
	int iNation = sti(GetAttribute(enemy,"nation"));

	int numGuards = MAX_LOGINED_CHARACTERS_IN_LOCATION-2 - LAi_numloginedcharacters;		// LDH - changed from 32 to TIH's original 30
	if (numGuards > 5 ) numGuards = 5;
	if (numGuards > 0 )
	{
		Logit(TranslateString("","The Merchant Guild's watchmen are very vigilant..."));
//		LAi_CreateFantomGroup("Navy_office4", numGuards, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, iNation, OFFIC_TYPE_GUARD, 0,  true, "", "", "", "");
		LAi_CreateFantomGroup("Merchant_Officers", 1, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, iNation, OFFIC_TYPE_GUARD, 0,  true, "", "", "", "");
		if (numGuards > 1) LAi_CreateFantomGroup("Merchant_Soldiers", numGuards-1, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, iNation, OFFIC_TYPE_GUARD, 0,  true, "", "", "", "");
//		LAi_CreateFantomGroup("Merchant_Soldiers", numGuards, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, iNation, OFFIC_TYPE_GUARD, 0,  true, "", "", "", "");

		if(!CheckAttribute(PChar, "locationLock"))
		{
			PChar.locationLock = true;
			StartQuestMovie(true, false, false);
		}
	}

	if(bKill)
	{
		// TIH --> bug fix... this now works right Jul23'06
		ChangeCharacterReputation(PChar, -100);				// TIH MUST BE INT Nov17'06
		pchar.traitor = true;								// PB: Trigger massive penalties
		UpdateRMRelation(PChar, iNation, REPCH_FRIENDLY);	// PB: Straight function call
		Preprocessor_Add("nationdesc", XI_ConvertString(GetNationDescByType(iNation)));
		string sLogTitle = GetTranslatedLog("Merchant Guild Member Killed");
		string sLogEntry = GetTranslatedLog("I do not remember the specifics, but a #snationdesc# merchant got killed in my presence. Was it one of my officers who did it? Myself? Or a complete accident? Either way, the Merchant Guild blamed me and I was lucky to escape with my life. This has had a notable effect on my relations and reputation.");
		WriteNewLogEntry(sLogTitle,PreprocessText(sLogEntry), "Personal", true);
		Preprocessor_Delete("nationdesc");
		// TIH <--
	}
}

void SoldierReinforcements(ref refCharacter)
{
	ref PChar = GetMainCharacter();

	if (sti(GetAttribute(refCharacter, "quest.guard_protection")) < 1)
	{
		if (GetAttribute(PChar         , "vcskip") == true)																				return;
		if (GetAttribute(LoadedLocation, "vcskip") == true)																				return;

		if(!HasSubStr(GetAttribute(refCharacter, "id"), "soldier"))																		return;
		if(!HasSubStr(GetAttribute(refCharacter, "Dialog.Filename"), "Soldier_dialog.c"))												return;

		if(!HasSubStr(GetAttribute(refCharacter, "location"), "port") && !HasSubStr(GetAttribute(refCharacter, "location"), "town"))	return;
	}

	int numGuards = MAX_LOGINED_CHARACTERS_IN_LOCATION-2 - LAi_numloginedcharacters;		// LDH - changed from 32 to TIH's original 30
	if (numGuards > 1 ) numGuards = 1;					// PB: was 2
	if (numGuards > 0 )
	{
		Logit(TranslateString("","The Garrison Commander sent immediate reinforcements..."));
		LAi_CreateFantomGroup("Soldiers", numGuards, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, GetCurrentLocationNation(), OFFIC_TYPE_GUARD, 0, true, "", "", "", "");

		if(!CheckAttribute(PChar, "locationLock"))
		{
			PChar.locationLock = true;
			StartQuestMovie(true, false, false);
		}
		// GR: Stealing Soldier Uniforms -->
		if (!CheckAttribute(pchar, "receivemodel"))
		{
			if (frnd() < 0.2) pchar.receivemodel = GetRandomModelForTypeExSubCheck(true, "Land_Officers", "man", GetCurrentLocationNation() ); // 20% chance of an officer
			else              pchar.receivemodel = GetRandomModelForTypeExSubCheck(true, "Soldiers"     , "man", GetCurrentLocationNation() ); // otherwise a random soldier
		}
		// GR: Stealing Soldier Uniforms <--
	}
}
// PB <--