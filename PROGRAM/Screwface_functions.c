
int Find_nearest_inf_ship(ref chr)
{
	ref rGroup;
	ref PChar = GetMainCharacter();
	string groupname;

	int i;
	ref achr;
	int achridx;
	int place = -1;
	float enemydist;
	enemydist = 0.0;
	float memoire=0.0;

	if(CheckAttribute(chr,"runaway")){DeleteAttribute(chr,"runaway");}

	float visibility_range = GetCharVisibilityRange(chr, 2); // PB: Ship nation is visible inside MEDIUM range
	float effective_range  = visibility_range;
	//LogIt("Visibility range : " + visibility_range + "!");

	for (i=0; i<MAX_SHIP_GROUPS; i++)
	{
		rGroup = Group_GetGroupByIndex(i);
		if(CheckAttribute(rGroup,"AlreadyLoaded"))
		{
			//LogIt(" " + rgroup.id + "   ");

			if (!CheckAttribute(rGroup, "id")) { continue; }
			if (!CheckAttribute(rGroup, "location")) { continue; }
			if (rGroup.location != PChar.location) { continue; }
			achr = Group_GetGroupCommanderR(rGroup);

			if(CheckAttribute(achr,"surrendered") || CharacterIsDead(achr)){continue;} //Group_UpdateGroup(achr);continue;}
			if(!Checkattribute(achr,"index")){continue;}
			if(GetNationRelation(sti(achr.nation), sti(chr.nation)) == RELATION_ENEMY)
			{
				//achr = Group_GetGroupCommander(rGroup.id);
				enemydist = Ship_GetDistance2D(achr, chr);
				if(Whr_IsNight() && HasCharacterShipAttribute(achr, "night_stealth")) effective_range = visibility_range / 2;	// PB: Black Pearl stealth at night
				if(enemydist < effective_range && Ship_power_inf(chr,achr))
				{
					//LogIt(" " + chr.Ship.Pos.x + "   ");
					//LogIt(" Enemy distance : " + enemydist + "   ");
					if(enemydist < memoire || place == -1)
					{
						if(place == -1 || GetShipSkill(chr, Skill_LEADERSHIP)>4) // lower captains are Stubborn
						{
							place = achr.index;
							memoire = enemydist;
						}
					}
				}
			}
		}
		else
		{
			if(CheckAttribute(rGroup, "id"))
			{
				achr = Group_GetGroupCommanderR(rGroup);
				if(CheckAttribute(achr, "id") && HasSubStr(achr.id, "fenc_"))
				{
					achr = Group_GetGroupCommanderR(rGroup);
					if(CheckAttribute(achr,"surrendered") || CharacterIsDead(achr)){continue;}
					if(!Checkattribute(achr,"index")){continue;}
					if(GetNationRelation(sti(achr.nation), sti(chr.nation)) == RELATION_ENEMY)
					{
						enemydist = Ship_GetDistance2D(achr, chr);
						if(enemydist < visibility_range && Ship_power_inf(chr,achr))
						{
							if(enemydist < memoire || place == -1)
							{
								if(place == -1 || GetShipSkill(chr, SKILL_LEADERSHIP)>4) //lower captains are Stubborn
								{
									place = achr.index;
									memoire = enemydist;
								}
							}
						}
					}
				}
			}
		}
	}

	if(GetNationRelation(GetCurrentFlag(), sti(chr.nation)) == RELATION_ENEMY || SeaAI_GetRelation(sti(PChar.index), sti(chr.index)) == RELATION_ENEMY) // PB: was GetRelation
	{
		enemydist = Ship_GetDistance2D(PChar, chr);
		if(enemydist <= visibility_range && Ship_power_inf(chr,PChar))
		{
			//if(enemydist < Ship_GetDistance2D(GetCharacter(place), chr) || place == -1){place = PChar.index;}
			if(enemydist < memoire || place == -1)
			{
				if(place == -1 || GetShipSkill(chr, SKILL_LEADERSHIP)>4)
				{
					place = PChar.index;
					memoire = enemydist;
				}
			}
		}
	}
	
	return place;
}

// To check if chr1 ship is stronger than chr2 ship
bool Ship_power_inf(ref chr1, ref chr2)
{
	ref rgroup = Group_GetGroupByID(GetGroupIDFromCharacter(chr1));
	ref rgroup2 = Group_GetGroupByID(GetGroupIDFromCharacter(chr2));
	bool result = false;

	if(GetCannonCurQuantity(chr1)<=0) {chr1.runaway = "1"; return true;}
	if(!CheckAttribute(chr1,"Fantomtype")) return true;

	// PIRATES REACTIONS
	if(CheckAttribute(chr1,"fantomtype") && chr1.fantomtype == "pirate")
	{
		// THEY DON'T LIKE WAR SHIPS BUT ATTACK THEM IF THEY HAVE SUPERIOR POWER
		if(CheckAttribute(chr2,"fantomtype") && chr2.fantomtype == "war" || chr2.index == GetMainCharacterIndex())
		{
			//LogIt("Power rgroup : " + Group_GetPowerHP_R(rGroup));
			//LogIt("Power rgroup2 : " + Group_GetPowerHP_R(rGroup2));
			if(Group_GetPowerHP_R(rGroup) >= Group_GetPowerHP_R(rGroup2))
			{
				//LogIt("I'm stronger");
				return true;
			}
			else
			{
				//LogIt("number ships rgroup : " + Group_GetCharactersNumR(rGroup));
				//LogIt("number ships rgroup2 : " + Group_GetCharactersNumR(rGroup2));
				if(Group_GetCharactersNumR(rGroup) >= Group_GetCharactersNumR(rGroup2) && GetCharacterShipClass(chr1) <= GetCharacterShipClass(chr2))
				{
					//LogIt("j'attaque");
					return true;
				}
				else
				{
					// They run away
					chr1.runaway = "1";
					if(Ship_GetDistance2D(chr1, chr2) < 200 && GetCannonCurQuantity(chr1)>2 && GetCargoGoods(chr1,GOOD_GUNPOWDER)>0)
					{
						if(GetCargoGoods(chr1,GOOD_BALLS)>0 || GetCargoGoods(chr1,GOOD_KNIPPELS)>0) // stop running and defend if a bigger enemy is too close
						{
							DeleteAttribute(chr1,"runaway");
						}
					}
					return true;
				}
			}
		}
		else
		{
			// TRADE SHIPS : They attack
			if(GetCharacterShipClass(chr2) == 1)
			{
				// Pirates don't like big escorts
				chr1.runaway = "1";
				return true;
			}
			else
			{
				return true;
			}
		}
	}

	// WAR SHIPS REACTIONS
	if(CheckAttribute(chr1,"fantomtype") && chr1.fantomtype == "war")
	{
		if(CheckAttribute(chr2,"fantomtype") && chr2.fantomtype == "war" || chr2.index == GetMainCharacterIndex())
		{
			if(Group_GetPowerHP_R(rGroup) >= Group_GetPowerHP_R(rGroup2))
			{
				return true;
			}
			else
			{
				if(Group_GetCharactersNumR(rGroup) >= Group_GetCharactersNumR(rGroup2) && GetCharacterShipClass(chr1) <= GetCharacterShipClass(chr2))
				{
					return true;
				}
				else
				{
					// They run away
					chr1.runaway = "1";
					if(Ship_GetDistance2D(chr1, chr2) < 200 && GetCannonCurQuantity(chr1)>2 && GetCargoGoods(chr1,GOOD_GUNPOWDER)>0)
					{
						if(GetCargoGoods(chr1,GOOD_BALLS)>0 || GetCargoGoods(chr1,GOOD_KNIPPELS)>0) // stop running and defend if a bigger enemy is too close
						{
							DeleteAttribute(chr1,"runaway");
						}
					}
					return true;
				}
			}
		}
		else
		{
			// TRADE SHIPS OR PIRATES : They attack
			return true;
		}
	}

	if( CheckAttribute(chr1,"Fantomtype") && chr1.fantomtype == "trade") return true; // trade ship have other reactions

	return false;
}

// Merchants basically run away but can attack if enemy is to close and if they have superiority
bool Check_courageous_merchant(ref chr1, ref chr2)
{
	ref rgroup = Group_GetGroupByID(GetGroupIDFromCharacter(chr1));
	ref rgroup2 = Group_GetGroupByID(GetGroupIDFromCharacter(chr2));
	float range = 600.0;
	//if(Whr_IsNight()){range = 800;}
	bool result = false;

	if(GetCannonCurQuantity(chr1)<=0) return false;

	if(Ship_GetDistance2D(chr1, chr2) < range  && GetCargoGoods(chr1,GOOD_GUNPOWDER)>0)
	{
		if(GetCargoGoods(chr1,GOOD_BALLS)>0 || GetCargoGoods(chr1,GOOD_KNIPPELS)>0)
		{
			if(Group_GetPowerHP_R(rGroup) >= Group_GetPowerHP_R(rGroup2)) return true;

			if(Group_GetCharactersNumR(rGroup) >= 2 * Group_GetCharactersNumR(rGroup2)) return true;

			if(GetCharacterShipClass(chr1) <=  GetCharacterShipClass(chr2) - 2) return true;

			if(GetCannonCurQuantity(chr1) > GetCannonCurQuantity(chr2) && GetCurrentShipHP(chr1) > GetCurrentShipHP(chr2)) return true;

			if(Ship_GetDistance2D(chr1, chr2) < 200 && GetCannonCurQuantity(chr1)>2) return true;
		}
	}

	return result;
}

// PB: Completely Rewritten -->
bool CheckAllShips(string type, bool initialize)
{
	int i, shipidx, num;
	aref shipattr;
	string shipstr;
	ref chr;
	float ship_range = 0.0;
	float visibility_range = 0.0;
	ref PChar = GetMainCharacter();

	if (!initialize) // Do this here for performance
	{
		if (GetCurrentFlag() == PERSONAL_NATION)	return false; // Never a false flag
		if (iForceDetectionFalseFlag == -1)			return false; // Override: Never detect
	}

	bool Recognized = false;
	if (CheckAttribute(PChar, "seaAI.update."+(type) )) {
		makearef(shipattr, PChar.seaAI.update.(type) );
		num = GetAttributesNum(shipattr);
		for (i = 0; i < num; i++) {
			shipstr = "l" + i;
			shipidx = sti(shipattr.(shipstr).idx);
			if (shipidx < 0) continue;
			chr = GetCharacter(shipidx);
			ship_range       = shipattr.(shipstr).distance;
			visibility_range = GetCharVisibilityRange(chr, 2); // KK: Ship nation is visible inside MEDIUM range
			if(Whr_IsNight() && HasCharacterShipAttribute(PChar, "night_stealth")) visibility_range /= 2;	// PB: Black Pearl stealth at night
			
			if (initialize)
			{
				CheckInitialFlagRelations(chr, visibility_range, ship_range);
			}
			else
			{
				if (ship_range < visibility_range)
				{
					bool bCheckInitial = false;
					if (!CheckAttribute(chr, "PlayerShip"))									bCheckInitial = true;	// GR: If you can be seen and aren't already logged, you are now
					if (CheckAttribute(chr, "PlayerShip") && !HasThisShip(chr.PlayerShip))	bCheckInitial = true;	// GR: If you are already logged and the log is out of date, update it
					if (bCheckInitial) CheckInitialFlagRelations(chr, visibility_range, ship_range);
				}
				Recognized = CheckForMainCharacterfalseflag(chr, visibility_range, ship_range);
			}
		}
	}
	return Recognized;
}

int GetFortRelationToPirates(ref chr)
{
	if (CheckAttribute(chr, "relation_to_pirates"))
	{
		return sti(chr.relation_to_pirates);
	}
	else
	{
		int iRelation = RELATION_ENEMY;
		string town;
		ref rPeriod;

		if (CheckAttribute(chr, "town"))	town = chr.town;			// For fort commanders
		else								town = GetCurrentTownID();	// For characters in town
		if (town != "")
		{
			iRelation = GetNationRelation(GetTownNation(town), PIRATE);
			makeref(rPeriod, Periods[GetCurrentPeriod()]);
			if (CheckAttribute(rPeriod, "Towns." + town + ".relation_to_pirates")) iRelation = sti(rPeriod.Towns.(town).relation_to_pirates);
		}
		chr.relation_to_pirates = iRelation; // Skip the above checks after the first time
		return iRelation;
	}
}

bool CheckForPirateException(ref chr)
{
	bool IsFort = !bSeaActive;
	IsFort = IsFort || GetAttribute(chr, "ship.type") == SHIP_FORT_NAME;
	bool PirateException = false;
	if (IsFort)
	{
		PirateException = true;
		if(GetCurrentFlag() != PIRATE)									PirateException = false;
		if(GetNationRelation2MainCharacter(PIRATE) == RELATION_ENEMY)	PirateException = false;
		if(GetFortRelationToPirates(chr) == RELATION_ENEMY)				PirateException = false;
	}
	return PirateException;
}

void UpdateAllShipsAtSea(ref chr, bool IsFort)
{
	int i, oNation, OChar_index;
	ref otherChar;
	int nNation = sti(chr.nation);
	int Char_index  = sti(chr.index);

	for(i = 0; i < MAX_SHIPS_ON_SEA; i++)
	{
		if (ships[i] <= 0) continue;
		otherChar    = GetCharacter(ships[i]);
		oNation      = sti(otherChar.nation);

		if (IsFort) // Forts aren't part of this loop, so need to use the BOTH function
		{
			if (oNation == PIRATE)
			{
				SetCharacterRelationBoth(Char_index, sti(otherChar.index), GetFortRelationToPirates(chr));
			}
			else
			{
				SetCharacterRelationBoth(Char_index, sti(otherChar.index), GetNationRelation(nNation, oNation));
			}
		}
		else // Relations between ships can be set only one way, because they'll be set the other way later
		{
			if (IsCompanion(chr) && IsCompanion(otherChar))
			{
				nNation = GetCurrentFlag();
				oNation = nNation;
			}
			SetCharacterRelation(Char_index, sti(otherChar.index), GetNationRelation(nNation, oNation));
		}
	}
}

void SetAllShipsNeutral()
{
	int i;
	for(i = 0; i < MAX_SHIPS_ON_SEA; i++)
	{
		if (ships[i] <= 0) continue;
		SetCharacterRelationBoth(GetMainCharacterIndex(), ships[i], RELATION_NEUTRAL);
	}
	for(i = 0; i < MAX_FORTS; i++)
	{
		if (sti(Forts[i].fortcmdridx) <= 0) continue;
		SetCharacterRelationBoth(GetMainCharacterIndex(), sti(Forts[i].fortcmdridx), RELATION_NEUTRAL);
	}
}

void CheckInitialFlagRelations(ref chr, float visibility_range, float ship_range)
{
	// Initialize nations
	int iNation = GetCurrentFlag();
	int nNation = sti(chr.nation);
	float rel = GetRMRelation(GetMainCharacter(), nNation);
	bool IsFort = GetAttribute(chr, "ship.type") == SHIP_FORT_NAME;

	// Initialize relations between NPC ships
	UpdateAllShipsAtSea(chr, IsFort);

	if (IsCompanion    (chr)) return; // Companions don't care
	if (CharacterIsDead(chr)) return; // Already dead, don't change relation again

	if (rel <= REL_WAR && iForceDetectionFalseFlag == 1 && ship_range < visibility_range) chr.recognized = 1; // GR: obey forced recognition of false flag

	// Ships that recognized you are ALWAYS hostile
	if (CheckAttribute(chr, "recognized") && !CheckAttribute(chr, "surrendered"))
	{
		Trace("FLAGS: The " + GetMyShipNameShow(chr) + " turned hostile as they have recognized us");
		SetCharRelationToFleet(chr, RELATION_ENEMY);
	}
	else
	{
		// Remember player's previous flag
		if (!CheckAttribute(chr, "PlayerNation") || !CheckAttribute(chr, "PlayerShip") || GetNationRelation(iNation, nNation) == RELATION_ENEMY)
		{
			if (ship_range < visibility_range)
			{
				if (GetNationRelation(iNation, nNation) == RELATION_ENEMY || !RELATION_IGNORE_FRIENDLY)
				{
					chr.PlayerNation = iNation;
//					chr.PlayerShip = GetCharacterShipID(GetMainCharacter());
					chr.PlayerShip = GetCharacterShipModel(GetMainCharacter());
					Trace("FLAGS: The " + GetMyShipNameShow(chr) + " has spotted us at " + ship_range + " and will remember us as " + GetNationDescByType(iNation) + " in " + chr.PlayerShip + " with visibility=" + visibility_range);
				}
				else Trace("FLAGS: The " + GetMyShipNameShow(chr) + " has spotted us at " + ship_range + ", but is not interested as we are not hostile");
			}
			else
			{
			//	Trace("FLAGS: The " + GetMyShipNameShow(chr) + " is out of range and is not checking our flag");
			}
		}
		else
		{
			if (ship_range < visibility_range)
			{
				if (!HasThisShip(chr.PlayerShip))
				{
					Trace("FLAGS: The " + GetMyShipNameShow(chr) + " remembered us as having " + chr.PlayerShip + ", which we no longer have");
					ResetCharacterMemory(chr);
				}
				else
				{
					iNation = sti(chr.PlayerNation);
					Trace("FLAGS: The " + GetMyShipNameShow(chr) + " remembers us as " + GetNationDescByType(iNation) );
				}
			}
			else
			{
				Trace("FLAGS: The " + GetMyShipNameShow(chr) + " is out of range so can neither remember nor forget us");
			}
		}

		// Turn hostile depending on player's previous flag
		if (IsFort && iNation == PIRATE)
		{
		//	Trace("FLAGS: The " + GetMyShipNameShow(chr) + " turned " + GetFortRelationToPirates(chr) + " based on their relation to pirates");
			SetCharRelationToFleet(chr, GetFortRelationToPirates(chr));
		}
		else
		{
			if(GetNationRelation(iNation, sti(chr.nation)) == RELATION_ENEMY)
			{
			//	Trace("FLAGS: The " + GetMyShipNameShow(chr) + " turned hostile as they believe us to be " + GetNationDescByType(iNation));
				if (SeaAI_GetRelation(GetMainCharacterIndex(), sti(chr.index)) != RELATION_ENEMY)
				{
					SetCharRelationToFleet(chr, RELATION_ENEMY);
				}
			}
			else
			{
			//	Trace("FLAGS: The " + GetMyShipNameShow(chr) + " believes our current flag");
				SetCharRelationToFleet(chr, GetNationRelation(GetCurrentFlag(), nNation));
			}
		}
	}
}

bool CheckForMainCharacterfalseflag(ref chr, float visibility_range, float ship_range)
{
	if (IsCompanion(chr))						return false; // Companions don't care
	if (CheckForPirateException(chr))			return false; // You are friendly to the pirates, flying a pirate flag and the town is tolerant of pirates
	if (GetAttribute(chr, "skipFalseFlag"))		return false; // Quest ship that will always believe your false flag

	ref PChar = GetMainCharacter();

	bool Recognized = false;
	float chance = 1 - (ship_range / visibility_range);
	float randVal = frnd();
	if (SeaAI_GetRelation(sti(chr.index), sti(PChar.index)) != RELATION_ENEMY && GetNationRelation(PERSONAL_NATION, sti(chr.nation)) == RELATION_ENEMY)
	{
		if (ship_range < visibility_range)
		{
			chance = 0.5 + chance; // 0.5 will be decreased if you are too easily recognized
			chance = chance * GetChanceDetectFalseFlag();
			if(iForceDetectionFalseFlag == 1) chance = 1.0; // PB: Obeys "iForceDetectionFalseFlag" setting to always see through false flag
			if(randVal <= chance)
			{
				Trace("FLAGS: The " + GetMyShipNameShow(chr) + " has recognized our false " + GetNationDescByType(GetCurrentFlag()) + " flag at range=" + ship_range + " with visibility=" + visibility_range + ", chance=" + chance + " and frnd=" + randVal);
				Recognized = true;
				SetGroupHostile(chr, false); // They start firing on you, so it is no immediate betrayal
			}
		}
	}
	return Recognized;
}

void SetGroupHostile(ref chr, bool bBetrayed)
{
	int i, num, otherChar;
	string sGroupID = GetGroupIDFromCharacter(chr);
	if (sGroupID == "") // For forts and other ships that may not be in any group
	{
		chr.recognized = 1;
		if (bBetrayed) chr.betrayed = 1;
	}
	else
	{
		ref rGroup = Group_GetGroupByID(sGroupID);
		num = Group_GetCharactersNumR(rGroup);
		for (i = 0; i < num; i++)
		{
			otherChar = Group_GetCharacterIndexR(rGroup, i);
			characters[otherChar].recognized = 1;
			if (bBetrayed) characters[otherChar].betrayed = 1;
		}
		Group_SetTaskAttack(sGroupID, PLAYER_GROUP, false); // False to skip call to SetCharacterRelationBoth!
	}
}

void SetCharRelationToFleet(ref chr, int iRelation)
{
	int i, companionChar;
	int otherChar = sti(chr.index);
	ref PChar = GetMainCharacter();
	for (i = 0; i < COMPANION_MAX; i++) // Set hostile to ALL ships in your fleet
	{
		companionChar = GetCompanionIndex(PChar, i);
		if (companionChar < 0) continue;
		if (!GetRemovable(GetCharacter(companionChar))) continue;
		SetCharacterRelationBoth(otherChar, companionChar, iRelation);
	}
}
// PB: Completely Rewritten <--

void Improve_SeaAi(String groupe)
{
	ref crgchar = Group_GetGroupCommander(groupe);
	if(CheckAttribute(crgchar,"surrendered") || CharacterIsDead(crgchar)){return;}
	float x, z;
	int enemydist = 0;
	int nextenemy = 0;
	string sLocationGroup, sLocationLocator;
	ref rIsland;
	string sTst;
	ref rGroup = Group_GetGroupByID(groupe);
	ref PChar = GetMainCharacter();
	//LogIt("Leadership : " + crgchar.skill.leadership + " ");

	if(CheckAttribute(crgchar,"fantomtype"))
	{
		if(crgchar.fantomtype=="trade")
		{
			nextenemy = Find_nearest_inf_ship(crgchar);
			if(nextenemy != -1) // && Characters[nextenemy].ship.type != SHIP_FORT_NAME ) 
			{
				if(Check_courageous_merchant(crgchar, &Characters[nextenemy]) || GetCharacterShipClass(crgchar) < 3)
				{
					//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a brave merchant and I'm defending!");
					Group_UnlockTask(groupe);
					Group_SetTaskAttack(groupe, GetGroupIDFromCharacter(GetCharacter(nextenemy)), false); // PB: Relations should already be hostile
					Group_LockTask(groupe);
				}
				else
				{
					//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a merchant and I have a too close enemy, so I'm running away!");
					Group_UnlockTask(groupe);
					Group_SetTaskRunaway(groupe);
					Group_LockTask(groupe);
					if(Group_GetTask(groupe)==AITASK_MOVE)
					{
						rGroup.memo.x = rGroup.Task.Target.Pos.x;
						rGroup.memo.z = rGroup.Task.Target.Pos.z;
					}
					else
					{
						if(Group_GetTask(groupe)!=AITASK_ATTACK)
						{
							rGroup.memo.x = crgchar.ship.Pos.x;
							rGroup.memo.z = crgchar.ship.Pos.z;
						}
					}
				}
			}
			else
			{
				if(Group_GetTask(groupe)==AITASK_RUNAWAY || Group_GetTask(groupe)==AITASK_ATTACK)
				{
					if(CheckAttribute(rGroup,"memo"))
					{
						//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a merchant! There's no more danger, so I can return to my initial route!");
						x = stf(rGroup.memo.x);
						z = stf(rGroup.memo.z);
						Group_UnlockTask(groupe);
						Group_SetTaskMove(groupe, x, z);
						Group_LockTask(groupe);
						DeleteAttribute(rGroup,"memo");
					}
					//else{TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " an anchoring merchant!");}
				}
				else
				{
					if(Group_GetTask(groupe)==AITASK_MOVE)
					{
					  	//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a merchant sailing to a destination!");
						Group_UnlockTask(groupe);
						Group_SetTaskMove(groupe, stf(rGroup.Task.Target.Pos.x), stf(rGroup.Task.Target.Pos.z));
						Group_LockTask(groupe);
					}
					//else{TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " an anchoring merchant!");}
				}
			}
		}

		if(crgchar.fantomtype=="pirate" || crgchar.fantomtype=="war")
		{
			//nextenemy = FindClosestShipofRel(crgchar.index, &enemydist, RELATION_ENEMY);
			nextenemy = Find_nearest_inf_ship(crgchar);
			if(CheckAttribute(crgchar,"runaway")) 
			{
				//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " and I'm running away!");
				Group_UnlockTask(groupe);
				Group_SetTaskRunaway(groupe);
				Group_LockTask(groupe);
			}
			else
			{
				if(nextenemy != -1) 
				{
					//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " and I'm attacking " + Characters[nextenemy].id + "!");
					Group_UnlockTask(groupe);
					Group_SetTaskAttack(groupe, GetGroupIDFromCharacter(GetCharacter(nextenemy)), false); // PB: Relations should already be hostile
					Group_LockTask(groupe);
				}
				else
				{
					// find new Quest_ship locator to patrol
					if(PChar.location!="")
					{
						sLocationGroup = "Quest_ships";
						sLocationLocator = GetRandomQuestShipLocator(PChar.location); // PB

						rIsland = GetIslandByID(PChar.location);
						sTst = sLocationGroup + "." + sLocationLocator + ".x";

						if (CheckAttribute(rIsland, sTst) || CheckAttribute(rGroup,"memo"))
						{
							if(CheckAttribute(rGroup,"memo"))
							{
								if(GetDistance2D(stf(crgchar.ship.Pos.x), stf(crgchar.ship.Pos.z), stf(rGroup.memo.x), stf(rGroup.memo.z)) <= 500)
								{
									//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a  " + crgchar.fantomtype + " and I'm patroling to " + sLocationLocator + "!");
									x = stf(rIsland.(sLocationGroup).(sLocationLocator).x);
									z = stf(rIsland.(sLocationGroup).(sLocationLocator).z);
									rGroup.memo.x = x;
									rGroup.memo.z = z;
								}
								else
								{
									x = stf(rGroup.memo.x);
									z = stf(rGroup.memo.z);							
									//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " and I'm " + GetDistance2D(stf(crgchar.ship.Pos.x), stf(crgchar.ship.Pos.z), stf(rGroup.memo.x), stf(rGroup.memo.z)) + " yards from my next patrol point!");
								}
							}
							else
							{
								//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " and I'm patroling to " + sLocationLocator + "!");
								x = stf(rIsland.(sLocationGroup).(sLocationLocator).x);
								z = stf(rIsland.(sLocationGroup).(sLocationLocator).z);
								rGroup.memo.x = x;
								rGroup.memo.z = z;
							}
						}
						else
						{
							if(rand(1)==0){x = 10000.0 * rand(10);}else{x = -10000.0 * rand(10);}
							if(rand(1)==0){z = 10000.0 * rand(10);}else{z = -10000.0 * rand(10);}
							if(CheckAttribute(rGroup,"memo")){DeleteAttribute(rGroup,"memo");}
							//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " without target or I've lost my target!");
						}
					}
					else
					{
						if(rand(1)==0){x = 10000.0 * rand(10);}else{x = -10000.0 * rand(10);}
						if(rand(1)==0){z = 10000.0 * rand(10);}else{z = -10000.0 * rand(10);}
						if(CheckAttribute(rGroup,"memo")){DeleteAttribute(rGroup,"memo");}
						//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " a " + crgchar.fantomtype + " without target or I've lost my target!");
					}
					Group_UnlockTask(groupe);
					Group_SetTaskMove(groupe, x, z);
					Group_LockTask(groupe);
				}
			}
		}
	}
	else
	{
		if(CheckAttribute(crgchar,"runaway"))
		{
			//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " and I'm running away!");
			Group_UnlockTask(groupe);
			Group_SetTaskRunaway(groupe);
			Group_LockTask(groupe);
		}
		else
		{
			nextenemy = Find_nearest_inf_ship(crgchar);
			if(nextenemy != -1)
			{
				//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " and I'm attacking " + Characters[nextenemy].id + "!");
				Group_UnlockTask(groupe);
				Group_SetTaskAttack(groupe, GetGroupIDFromCharacter(GetCharacter(nextenemy)), false); // PB: Relations should already be hostile
				Group_LockTask(groupe);
			}
			else
			{
				//TraceAndLog("I'm " + GetMyShipNameShow(crgchar) + " and I'm doing nothing...");
			}
		}
	}
}

void Refreshseacolor_in()
{
	if (bSeaActive && !bAbordageStarted) {
		SetEventHandler("frame", "BI_Refreshseacolor_in", 1);
		return;
	}
}
void Refreshseacolor_out()
{
	if (bSeaActive && !bAbordageStarted) {
		SetEventHandler("frame", "BI_Refreshseacolor_out", 1);
		return;
	}
}

bool HasThisShip(string Ship)
{
	int n, compidx;
	bool hasship = false;
	ref comp;
	for (n = 0; n<COMPANION_MAX; n++)
	{
		compidx = GetCompanionIndex(GetMainCharacter(), n);
		if (compidx >= 0)
		{
			comp = GetCharacter(compidx);
//			if (GetCharacterShipID(comp) == Ship) hasship = true;
			if (GetCharacterShipModel(comp) == Ship) hasship = true;
		}
	}
	return hasship;
}