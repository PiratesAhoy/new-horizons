#define FELLOWTRAVEL_NO			0
#define FELLOWTRAVEL_CAPTIVE	1
#define FELLOWTRAVEL_PASSENGER	2
#define FELLOWTRAVEL_OFFICER	3
#define FELLOWTRAVEL_COMPANION	4

#define EVENT_CHANGE_OFFICERS	"EvntChangeOfficers"
#define EVENT_CHANGE_COMPANIONS	"EvntChangeCompanions"

#define MAX_ITEM_TAKE	256

#define MSGICON_ACTIVE_TIME 10
#define MSGICON_LEVELUP	0
#define MSGICON_LOGBOOK	1
#define MSGICON_GETITEM	2

#define DOUBLE_REP_INCR 0		// LDH 30Sep06

#event_handler("evnt_MsgIconTick","proc_MsgIconTick");

bool GetShipRemovable(ref _refCharacter)
{
	bool locked = CheckAttribute(_refCharacter,"ShipRemovable") && sti(_refCharacter.ShipRemovable) == false;
	return !locked && !IsCargoLocked(_refCharacter); 
}

void SetShipRemovable(ref _refCharacter, bool bRemovable)
{
	if(bRemovable)
		DeleteAttribute(_refCharacter,"ShipRemovable");
	else
		_refCharacter.ShipRemovable = false;
}

void SetCargoLocked(ref chr, bool locked)
{
	if(locked)
		chr.isCargoLocked = true;
	else
		DeleteAttribute(chr, "isCargoLocked");
}

bool IsCargoLocked(ref chr)
{
	return CheckAttribute(chr, "isCargoLocked") && chr.isCargoLocked == true;
}

//
bool CharacterIsDead(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter, "corpse")) return true; // NK pers. corpse 05-07-19
	return LAi_IsDead(_refCharacter);
}

bool CharacterIsFriend(ref _refCharacter)
{
	if(GetAttribute(_refCharacter,"friend")==true) return true;
	return false;
}

//Levis:
bool IsCompanionOfficer(ref Captain, ref Officer)
{
	//trace("Called for "+Captain.id+" and "+Officer.id);
	if(GetOfficerOf(Officer) < 0 && GetCompanionOf(Officer) < 0) return false;
	for(int i=0; i<COMPANION_MAX; i++)
	{
		//trace("Officer "+Officer.index+" Captain "+Captain.index+" Companion "+GetCompanionIndex(Captain,i)+" Officerof "+GetOfficerOf(Officer));
		if(GetOfficerOf(Officer) == GetCompanionIndex(Captain,i)) return true;
		if(sti(Officer.index) == GetCompanionIndex(Captain,i)) return true;
	}
	return false;
}

bool IsCompanion(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter, "index"))
	{
		int index = sti(_refCharacter.index);
		if(index >= 0)
		{
			for(int i=0; i<COMPANION_MAX; i++) // PB: 0 is main character, so INCLUDED in companions!
			{
				if(GetCompanionIndex(GetMainCharacter(),i)==index)
					return true;
			}
		}
	}
	return false;
}

bool IsOfficer(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter, "index"))
	{
		int findIdx = sti(_refCharacter.index); // changed by MAXIMUS
		if(findIdx >= 0)
		{
			for(int i=0; i<OFFICER_MAX; i++)
			{
				if(GetOfficersIndex(GetMainCharacter(),i) == findIdx)
					return true;
			}
		}
	}
	return false;
}

//JRH
bool IsOfficerType(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter, "chr_ai.type") && _refCharacter.chr_ai.type == LAI_TYPE_OFFICER)
	{
		return true;
	}
	else return false;
}

// Viper - CharSheetEnh Start
bool IsOfficerCompanion(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter, "index"))
	{
		int findIdx = sti(_refCharacter.index);
		if(findIdx >= 0)
		{
			for(int i=1; i<COMPANION_MAX; i++)
			{
				ref comp = GetCharacter(GetCompanionIndex(GetMainCharacter(), i));
				for(int j=1; j<OFFICER_MAX; j++)
				{
					if(GetOfficersIndex(comp, j) == findIdx) return true;
				}
			}
		}
	}
	return false;
}
// Viper - CharSheetEnh End

// KK -->
bool IsOfficerOf(ref _refOfficer, ref _refCharacter)
{
	if (!CheckAttribute(_refOfficer, "OfficerOf.idx")) return false;
	return GetCharacterIndex(_refCharacter.id) == GetOfficerOf(_refOfficer);
}

bool IsCompanionOf(ref _refOfficer, ref _refCharacter)
{
	if (!CheckAttribute(_refOfficer, "CompanionOf.idx")) return false;
	return GetCharacterIndex(_refCharacter.id) == sti(_refOfficer.CompanionOf.idx);
}
// <-- KK

void SetCharacterRemovable(ref _refCharacter,bool removable)
{
	if(removable) DeleteAttribute(_refCharacter,"NonRemovable");
	else _refCharacter.NonRemovable = true;
}

bool GetRemovable(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"NonRemovable") ) return !sti(_refCharacter.NonRemovable);
	return true;
}

// Cargo utilites
//------------------------------------------
int GetCargoLoad(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	return sti(_refCharacter.Ship.Cargo.Load);
}

int RecalculateCargoLoad(ref _refCharacter)
{
	// NK 04-16 temp bugfix - if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	if(!CheckAttribute(_refCharacter,"Ship")) return 0; // NK ditto; we return 0 _only_ if _ship_ doesn't exist; we continue if ship does but cargo doesn't
	int loadSpace = 0;
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
		loadSpace = loadSpace + GetGoodWeightByType(i,GetCargoGoods(_refCharacter,i));
	}
	// PB: Cannons and Crew -->
	if (SHIPS_WEIGHT)
	{
		loadSpace = loadSpace + GetCannonCurQuantity(_refCharacter) * GetCannonWeightByCharacter(_refCharacter);
		loadSpace = loadSpace + GetTotalCrewQuantity(_refCharacter) * CREW_WEIGHT;

		if (loadSpace > GetCargoMaxSpace(_refCharacter))
		{
			if (bSeaActive && !bAbordageStarted)
			{
				if(CheckAttribute(_refCharacter, "Ship.Capsize"))
				{
					DeleteAttribute(_refCharacter, "Ship.Capsize");
					TraceAndLog("The " + GetMyShipNameShow(_refCharacter) + " captained by " + GetMySimpleName(_refCharacter) + " has capsized due to overloading!");
					CapsizeShip(_refCharacter);
				}
				else
				{
					if(!CheckAttribute(_refCharacter, "Ship.Unstable"))
					{
						if(IsCompanion(_refCharacter))
						{
							if(IsMainCharacter(_refCharacter))
								TraceAndLog("Captain, it seems our ship is unstable! We have to lose weight and quick!");
							else
								TraceAndLog("Captain, it seems the " + GetMyShipNameShow(_refCharacter) + " captained by " + GetMySimpleName(_refCharacter) + " is unstable! She has to lose weight and quick!");
						}
						else
						{
							TraceAndLog("The " + GetMyShipNameShow(_refCharacter) + " captained by " + GetMySimpleName(_refCharacter) + " is in danger of capsizing!");
							LogIt("This should NOT be happening. Please post your compile.log file at piratesahoy.net!");
							DumpAttributes(_refCharacter);
						}
						_refCharacter.Ship.Unstable = true;
						PostEvent("DoCapsize", (50+rand(20))*1000, "i", _refCharacter);
					}
				}
			}
			else
			{
				if(IsCompanion(_refCharacter))
				{
					if(IsMainCharacter(_refCharacter))
						TraceAndLog("Captain, our ship has been overloaded!");
					else
						TraceAndLog("Captain, the " + GetMyShipNameShow(_refCharacter) + " captained by " + GetMySimpleName(_refCharacter) + " has been overloaded!");
				}
			}
		}
	}
	// PB: Cannons and Crew <--
	_refCharacter.Ship.Cargo.Load = loadSpace;
	return loadSpace;
}

int GetCargoFreeSpace(ref _refCharacter)
{
	// TIH 7-7-06 temp bugfix - if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	int freeSpace = GetCargoMaxSpace(_refCharacter) - GetCargoLoad(_refCharacter);
	return freeSpace;
}

int GetCargoMaxSpace(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"Ship.Type") ) return 0;
	int _ShipType = GetCharacterShipType(_refCharacter); // PS
	if( _ShipType==SHIP_NOTUSED )
		return 0;
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	if(_ShipType == -1) trace("SHIP MISSING: " + _refCharacter.ship.type); // PB: Error checking
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[_ShipType],"Capacity")); // PRS3
}

int GetCharacterFreeSpace(ref _refCharacter,int _Goods)
{
	int weight = sti(Goods[_Goods].weight);
	int unitQ = sti(Goods[_Goods].Units);

	int retVal = unitQ * (GetCargoFreeSpace(&_refCharacter)/weight);
	return retVal;
}

int GetSquadronFreeSpace(ref _refCharacter,int _Goods)
{
	int weight = sti(Goods[_Goods].weight);
	int unitQ = sti(Goods[_Goods].Units);

	int retVal = unitQ * (GetCargoFreeSpace(&_refCharacter)/weight);
	int i,cn;
	ref chref;
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			chref = GetCharacter(cn);
			if (IsTrader(chref)) continue; // KK
			if( GetRemovable(chref) )
			{
				retVal = retVal + unitQ*(GetCargoFreeSpace(chref)/weight);
			}
		}
	}
	return retVal;
}

int GetCargoGoods(ref _refCharacter,int _Goods)
{
	if(_Goods<0) return 0;//MAXIMUS
	string goodsName = Goods[_Goods].name;
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Goods."+goodsName)) return 0;
	return sti(_refCharacter.Ship.Cargo.Goods.(goodsName));
}

int GetSquadronGoods(ref _refCharacter,int _Goods)
{
	int i,cn;
	ref chref;
	int retVal = GetCargoGoods(&_refCharacter,_Goods);
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			chref = GetCharacter(cn);
			if (IsTrader(chref) && _Goods != GOOD_WHEAT && _Goods != GOOD_RUM) continue; // KK, modified by GR to allow food and rum to be included
			if( GetRemovable(chref) || _Goods == GOOD_WHEAT || _Goods == GOOD_RUM) // LDH 13Oct06 fix for quest ships
			{
				retVal = retVal + GetCargoGoods(chref,_Goods);
			}
		}
	}
	return retVal;
}

// TIH --> new function to easily clear a cargo item
void ClearCharacterGoods(ref _refCharacter,int _Goods)
{
	if (IsTrader(_refCharacter)) return; // KK
	string goodsName = Goods[_Goods].name;
	_refCharacter.Ship.Cargo.Goods.(goodsName) = 0;
	RecalculateCargoLoad(_refCharacter);
}
// TIH <--

void SetCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
//	if (IsTrader(_refCharacter)) return; // KK - PB: Quest traders need cargo too
	string goodsName = Goods[_Goods].name;
	string goodsAttr = "Ship.Cargo.Goods." + goodsName; // PB: Prevent errors
	if (sti(GetAttribute(_refCharacter, goodsAttr)) == _Quantity) return; // KK
	_refCharacter.Ship.Cargo.Goods.(goodsName) = _Quantity;
	int curLoad = RecalculateCargoLoad(_refCharacter);
	int maxLoad = GetCargoMaxSpace(_refCharacter);
	if(curLoad>maxLoad && _Quantity>0)
	{
// KK -->
		//Trace("ERROR! Cargo space overup (character=" + _refCharacter.index + ",Quantity=" + _Quantity + ", curload=" + curLoad + ",maxload=" + maxLoad + ")"); // NK 05-04-06
		ClearCharacterGoods(_refCharacter, _Goods);
		SetCharacterGoods(_refCharacter, _Goods, GetGoodQuantityByWeight(_Goods, GetCargoFreeSpace(_refCharacter)));
// <-- KK
	}
}

bool AddCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	ref ch;
	int i,cn,freeQuantity;
	string goodsName = Goods[_Goods].name;

	for (i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if (cn < 0) continue;
		ch = GetCharacter(cn);
	//	if (IsTrader(ch)) continue; // KK - PB: Quest traders need cargo too
		if (i > 0 && !GetRemovable(ch)) continue;	// GR: don't add cargo to a locked companion
		freeQuantity = GetGoodQuantityByWeight( _Goods, GetCargoFreeSpace(ch) );
		if(freeQuantity>=_Quantity)
		{
			ch.Ship.Cargo.Goods.(goodsName) = sti(ch.Ship.Cargo.Goods.(goodsName)) + _Quantity;
			RecalculateCargoLoad(ch);
			return true;
		}
		ch.Ship.Cargo.Goods.(goodsName) = sti(ch.Ship.Cargo.Goods.(goodsName)) + freeQuantity;
		_Quantity = _Quantity - freeQuantity;
		RecalculateCargoLoad(ch);
	}
	Trace("Overup cargo space on "+_Quantity);
	return false;
}

void AddAmmoGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	if (IsTrader(_refCharacter)) return; // KK
	string goodsName = Goods[_Goods].name;
	int oldQ = 0;
	if( CheckAttribute(_refCharacter,"Ship.Cargo.Goods."+goodsName) ) {
		oldQ = sti(_refCharacter.Ship.Cargo.Goods.(goodsName));
	}
	int newQ = oldQ + _Quantity;
	int delta = newQ/20 - oldQ/20;
	if( delta==0) return;
	int nCargoLoad = 0;
	if( CheckAttribute(_refCharacter, "Ship.Cargo.Load") ) {
		nCargoLoad = sti(_refCharacter.Ship.Cargo.Load);
	}
	_refCharacter.Ship.Cargo.Load = nCargoLoad + delta*sti(Goods[_Goods].Weight);
}

int RemoveCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	int i,cn,curQuantity;
	string goodsName = Goods[_Goods].name;

	for (i=0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{
			if (IsTrader(GetCharacter(cn))) continue; // KK
			if (i > 0 && !GetRemovable(GetCharacter(cn))) continue; // GR: don't take goods from locked companion
			curQuantity = sti( Characters[cn].Ship.Cargo.Goods.(goodsName) );
			if(curQuantity>=_Quantity)
			{
				Characters[cn].Ship.Cargo.Goods.(goodsName) = curQuantity - _Quantity;
				RecalculateCargoLoad(&Characters[cn]);
				return true;
			}
			Characters[cn].Ship.Cargo.Goods.(goodsName) = 0;
			_Quantity = _Quantity - curQuantity;
			RecalculateCargoLoad(&Characters[cn]);
		}
	}
	Trace("Overup cargo space on "+_Quantity);
	return false;
}

// Cannons utilite
int GetCaracterShipCannonsType(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cannons.Type")) return CANNON_TYPE_NONECANNON;
	return sti(_refCharacter.Ship.Cannons.Type);
}
int GetCannonQuantity(ref refCharacter)
{
	int nShipType = GetCharacterShipType(refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	ref rShip = GetShipByType(nShipType);
	aref arship; makearef(arship, refCharacter.ship); return sti(GetLocalShipAttrib(arship, &rShip, "CurCanQty")); //NK can qty 05-04-18
	//return sti(rShip.CannonsQuantity);
}
// NK 05-04-19 -->
int GetCannonMaxQuantity(ref refCharacter)
{
	int nShipType = GetCharacterShipType(refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	ref rShip = GetShipByType(nShipType);
	aref arship; makearef(arship, refCharacter.ship); return sti(GetLocalShipAttrib(arship, &rShip, "MaxCanQty")); //NK can qty 05-04-18
	//return sti(rShip.CannonsQuantity);
}
// NK <--
int GetMaximumCaliber(ref refCharacter)
{
	int nShipType = GetCharacterShipType(refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	ref rShip = GetShipByType(nShipType);
	aref arship; makearef(arship, refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, rShip,"MaxCaliber")); // PRS3
}

// Ship utilite
// KK -->
bool CharacterHasShip(ref _refCharacter)
{
	int st = GetCharacterShipType(_refCharacter);
	if (st <0 || st >= SHIP_TYPES_QUANTITY) { return false; } // PB: Prevent CTDs
	return true;
}
// <-- KK

int GetCharacterShipType(ref _refCharacter)
{
	// PS -->
	/*if(CheckAttribute(_refCharacter,"Ship.Type"))
	{
		if(_refCharacter.Ship.Type == SHIP_NOTUSED_TYPE_NAME) return SHIP_NOTUSED; // PS
		int iShipType = GetShipIndex(_refCharacter.Ship.Type); // PS
		if(iShipType>=0 && iShipType<SHIP_TYPES_QUANTITY)	return iShipType;
	}
	return SHIP_NOTUSED;*/
	if(!CheckAttribute(_refCharacter, "ship.type")) return SHIP_NOTUSED;
	if(_refCharacter.ship.type == SHIP_NOTUSED_TYPE_NAME)
	{
		_refCharacter.ship.idx = SHIP_NOTUSED;
		return SHIP_NOTUSED;
	}
	int stype = -1;
	// NK 04-09-08 now using native in GetShipIndex so that's faster.
	/*if(CheckAttribute(_refCharacter,"ship.idx")) { stype = sti(_refCharacter.ship.idx); }
	if(stype != -1 && stype != SHIP_NOTUSED && stype < SHIP_TYPES_QUANTITY)
	{
		if(ShipsTypes[stype].id == _refCharacter.ship.type) { return stype; }
	}*/
	stype = GetShipIndex(_refCharacter.ship.type);
	_refCharacter.ship.idx = stype;
	return stype;
}
string GetCharacterShipID(ref char)
{
	if (CheckAttribute(char, "Ship.type")) return char.Ship.type;
	return SHIP_NOTUSED_TYPE_NAME;
}
// PS <--
int GetCharacterShipHP(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[nShipType], "HP")); // PRS3
}
int GetCurrentShipHP(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	if (CheckAttribute(_refCharacter,"ship.hp") && sti(_refCharacter.ship.hp)>0) return sti(_refCharacter.ship.hp);

	return 0;
}
int GetCharacterShipSP(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[nShipType], "SP")); // PRS3
}
string GetShipTypeName(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return SHIP_NOTUSED_TYPE_NAME; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return GetLocalShipAttrib(arship, &ShipsTypes[nShipType], "SName"); // PRS3
}

bool JettyShip(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return false; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "Jetty"))
		return sti(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "Jetty"));
	else
		return GetMaxCrewQuantity(chr) < 400; // Armada
}

bool SteamShip(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return false; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "steamship"))
		return sti(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "steamship"));
	else
		return false;
}

float SupplyScalarByShip(ref refShip)
{
	if (CheckAttribute(refShip, "SupplyScalar"))
		return stf(refShip.SupplyScalar);
	else
		return 1.0;
}

float SupplyScalarByCharacter(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 1.0; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "SupplyScalar"))
		return stf(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "SupplyScalar"));
	else
		return 1.0;
}

bool HasCharacterShipAttribute(ref chr, string attribute)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return false; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], attribute))
		return true;
	else
		return false;
}

int GetCharacterShipValue(ref chr, string attribute)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], attribute))
		return sti(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], attribute));
	else
		return 0;
}

int GetCharacterShipClass(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return -1; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[nShipType], "Class")); // PRS3
}

// KK -->
string GetCharacterShipCabin(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return "Tutorial_Deck"; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "Cabin") == false) return "Tutorial_Deck";
	return GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "Cabin");
}

int FindCharacterShipCabin(ref chr)
{
	int cabinidx = -1;
	if (IsMainCharacter(chr)) cabinidx = FindLocation("Tutorial_Deck");
	int companionNo = GetCompanionNumber(GetMainCharacter(), GetCharacterIndex(chr.id));
	if (companionNo > 0) cabinidx = FindLocation("Companion_Cabin_" + companionNo);
	return cabinidx;
}

int GetCharacterShipCannonsDeckCount(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "CannonsDeck") == false) return 0;
	return sti(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "CannonsDeck"));
}

int GetCharacterShipCargoHoldCount(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "CargoHold") == false) return 0;
	return sti(GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "CargoHold"));
}

int GetCharacterShipDeckCount(ref chr)
{
	return GetCharacterShipCannonsDeckCount(chr) + GetCharacterShipCargoHoldCount(chr);
}

string GetCharacterShipQDeck(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return "ShipDeck1"; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if (CheckShipAttribute(ship, &ShipsTypes[nShipType], "QDeck")) {
		string loc = GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "QDeck");
		if (FindLocation(loc) >= 0) return loc;
	}
	return "ShipDeck1";
}
// <-- KK
//MAXIMUS: gives possibility for upgrade player's ship -->
int GetCharacterShipLocations(ref chr)
{
	int count = 0;
	if(GetCharacterShipCQuarters(chr)!="") count = count + 1;
	if(GetCharacterShipCabin(chr)!="Cabin_none" && GetCharacterShipCabin(chr)!="Tutorial_Deck") count = count + 1;
	return count;
}

string GetCharacterShipCQuarters(ref chr)
{
	int nShipType = GetCharacterShipType(chr);
	if (nShipType <0 || nShipType >= SHIP_TYPES_QUANTITY) { return ""; } // PB: Prevent CTDs
	aref ship; makearef(ship, chr.ship);
	if(CheckShipAttribute(ship, &ShipsTypes[nShipType], "CQuarters"))
	{
		string loc = GetLocalShipAttrib(ship, &ShipsTypes[nShipType], "CQuarters");
		if(FindLocation(loc)!=-1) return loc;
	}
	if(GetCharacterShipClass(chr)<=6) return "Seadogs";//temporary added (till some changes in other files will done)
	return "";
}
//MAXIMUS: gives possibility for upgrade player's ship <--
float GetFleetSpeed(ref PChar)
{
	int cn;
	ref refShip, chr;
	aref arship;
	float speed, cp, ftmp;
	speed = 99.0; cp = 0.0;
	for(int i=0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(PChar,i);
		if(cn!=-1)
		{
			chr = GetCharacter(cn);
			refShip = GetShipByType(GetCharacterShipType(chr));
			makearef(arship, chr.ship);
			ftmp = stf(GetLocalShipAttrib(&arship, &refShip, "speedrate"));
			if(ftmp < speed) speed = ftmp;
			ftmp = stf(GetLocalShipAttrib(&arship, &refShip, "ClosestPoint"));
			if(ftmp > cp) cp = ftmp;
		}
	}
	return speed * DEFAULT_CLOSESTPOINT / cp;
}
int GetMaxCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Type")) return 0;
	int shipType = GetCharacterShipType(_refCharacter); // PS
	if (shipType <0 || shipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[shipType], "MaxCrew")); // PRS3
}
int GetMinCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Type")) return 0;
	int shipType = GetCharacterShipType(_refCharacter); // PS
	if (shipType <0 || shipType >= SHIP_TYPES_QUANTITY) { return 0; } // PB: Prevent CTDs
	aref arship; makearef(arship, _refCharacter.ship); // PRS3
	return sti(GetLocalShipAttrib(arship, &ShipsTypes[shipType], "MinCrew")); // PRS3
}
int GetFreeCrewQuantity(ref _refCharacter)
{
	return GetMaxCrewQuantity(_refCharacter) - GetTotalCrewQuantity(_refCharacter);
}
int GetFreePartyCrewQuantity(ref _refCharacter)
{
	int i, cn;
	int sumCrew = 0;
	for (i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{
			sumCrew = sumCrew + GetFreeCrewQuantity(GetCharacter(cn));
		}
	}
	return sumCrew;
}
int GetCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Crew.Quantity")) return 0;
	return sti(_refCharacter.Ship.Crew.Quantity);
}
bool SetCrewQuantity(ref _refCharacter,int num)
{
	int maxCrew = GetMaxCrewQuantity(_refCharacter);
	if(num>maxCrew)
	{
		if(!LAi_IsBoardingProcess()) Trace("Error!!! Overup maximum crew quantity (character=" + _refCharacter.index + ")");//MAXIMUS
		_refCharacter.Ship.Crew.Quantity = maxCrew;
		return false;
	}
	_refCharacter.Ship.Crew.Quantity = num;
	return true;
}
bool AddCharacterCrew(ref _refCharacter,int num)
{
	return SetCrewQuantity(_refCharacter,GetCrewQuantity(_refCharacter)+num);
}
bool RemoveCharacterCrew(ref _refCharacter,int num)
{
	int curCrew = GetCrewQuantity(_refCharacter);
	if(curCrew<num)
	{
		Trace("Error!!! Remove overup crew (character=" + _refCharacter.index + ")");
		SetCrewQuantity(_refCharacter,0);
		return false;
	}
	SetCrewQuantity(_refCharacter,curCrew-num);
	return true;
}

// KK, jsv -->
int GetWoundedCrewQuantity(ref _refCharacter)
{
	if (!CheckAttribute(_refCharacter, "Ship.Crew.Wounded.Quantity")) return 0;
	return sti(_refCharacter.Ship.Crew.Wounded.Quantity);
}

int GetTotalCrewQuantity(ref _refCharacter)
{
	return GetCrewQuantity(_refCharacter) + GetWoundedCrewQuantity(_refCharacter);
}

bool SetCharacterWoundedCrew(ref _refCharacter, int num)
{
	if (num > 0)
	{
		_refCharacter.Ship.Crew.Wounded.Quantity = num;
	}
	else
	{
		if (num < 0) Trace("[character= " + _refCharacter.index + "] trying to remove " + (-num) + " extra wounded");
		if (CheckAttribute(_refCharacter, "Ship.Crew.Wounded")) DeleteAttribute(_refCharacter, "Ship.Crew.Wounded");
	}
	return true;
}

// The two functions below no longer update main crew. That feature was never used anywhere. --jsv
bool AddCharacterWoundedCrew(ref _refCharacter, int num)
{
	if (num == 0) return false;
	return SetCharacterWoundedCrew(_refCharacter, GetWoundedCrewQuantity(_refCharacter) + num);
}

bool RemoveCharacterWoundedCrew(ref _refCharacter, int num)
{
	return AddCharacterWoundedCrew(_refCharacter, -num);
}

// nb: this one does update the Ship.Crew accordingly! -jsv
// Could've been named better, but it's only used to implement Heal* functions.
bool UpdateWoundedCrewQuantity(ref _refCharacter, int num)
{
	if (num < 0) return false;
	int crew = GetTotalCrewQuantity(_refCharacter);

	SetCrewQuantity(_refCharacter, crew - num);
	SetCharacterWoundedCrew(_refCharacter, num);
	return true;
}

void HealSquadronWoundedCrew()
{
	ref pchar = GetMainCharacter();
	for (int i = 0; i < COMPANION_MAX; i++)
	{
		int cn = GetCompanionIndex(pchar, i);
		if (cn < 0) continue;
		ref rCharacter = GetCharacter(cn);
		UpdateWoundedCrewQuantity(rCharacter, 0);
	}
}


bool HealCharacterWoundedCrew(ref _refCharacter, int num)
{
	int woundedCrew = GetWoundedCrewQuantity(_refCharacter);
	if (num > woundedCrew) num = woundedCrew;
	return UpdateWoundedCrewQuantity(_refCharacter, woundedCrew - num);
}
// <-- KK, jsv

string GetCharacterOfficerType(ref _refCharacter)
{
	if (!CheckAttribute(_refCharacter, "quest.officertype")) return "";
	return _refCharacter.quest.officertype;
}

// PB -->
int GetWoundedHealedPerDay(ref _refCharacter)
{
	int healing_rate = HEALED_PER_DAY;
	if(GetCargoGoods(_refCharacter, GOOD_TREATMENT) > 0)
		healing_rate = healing_rate + HEALED_WITH_MEDS;
	if(CharacterHasOfficerType(_refCharacter, OFFIC_TYPE_DOCTOR))
	{
		healing_rate = healing_rate + CharacterGetOfficerSkill(_refCharacter, OFFIC_TYPE_DOCTOR, "defence");
		if(CheckCharacterPerk(_refCharacter, "AdvancedFirstAid"))
		{
			healing_rate = healing_rate + 2;
			trace("2 more healed due to Advanced First Aid");
		}
		else
		{
			if(CheckCharacterPerk(_refCharacter, "BasicFirstAid"))
			{
				healing_rate = healing_rate + 1;
				trace("1 more healed due to Basic First Aid");
			}
		}
	}
	return makeint(0.5 * healing_rate + rand(healing_rate));
}

int GetWoundedKilledPerDay(ref _refCharacter)
{
	int death_rate = KILLED_PER_DAY;
	if(CharacterHasOfficerType(_refCharacter, OFFIC_TYPE_DOCTOR))
		death_rate = death_rate - CharacterGetOfficerSkill(_refCharacter, OFFIC_TYPE_DOCTOR, "defence");

	if (GetOfficersPerkUsing(_refCharacter, "BasicFirstAid")) death_rate = death_rate - 2;
	if (GetOfficersPerkUsing(_refCharacter, "AdvancedFirstAid")) death_rate = death_rate - 2;

	if(GetCargoGoods(_refCharacter, GOOD_TREATMENT) > 0)
		death_rate = death_rate - HEALED_WITH_MEDS;
	if(death_rate <= 0) return 0;
	else return makeint(0.5 * death_rate + rand(death_rate));
}

bool CharacterHasOfficerType(ref _refCharacter, string OfficerType)
{
	int i, cn;
	if(IsMainCharacter(_refCharacter))
	{
		int num = GetPassengersQuantity(_refCharacter);
		for(i = 0; i < num; i++)
		{
			cn = GetPassenger(_refCharacter, i);
			if(cn < 0) continue;
			if(GetAttribute(GetCharacter(cn),"quest.officertype") == OfficerType &&
				!IsPrisoner(GetCharacter(cn)) && !IsCompanion(GetCharacter(cn))) return true;
		}
	}
	else
	{
		for(i = 1; i < OFFICER_MAX; i++)
		{
			cn = GetOfficersIndex(&_refCharacter,i);
			if(cn < 0) continue;
			if(GetAttribute(GetCharacter(cn),"quest.officertype") == OfficerType) return true;
		}
	}
	return false;
}

int CharacterGetOfficerSkill(ref _refCharacter, string OfficerType, string skillName)
{
	int i, cn;
	int skillvalue = 0;
	if(IsMainCharacter(_refCharacter))
	{
		int num = GetPassengersQuantity(_refCharacter);
		for(i = 0; i < num; i++)
		{
			cn = GetPassenger(_refCharacter, i);
			if(cn < 0) continue;
			if(GetAttribute(GetCharacter(cn),"quest.officertype") == OfficerType &&
				!IsPrisoner(GetCharacter(cn)) && !IsCompanion(GetCharacter(cn)))
			{
				if(CalcCharacterSkill(GetCharacter(cn), skillName) > skillvalue)
					skillvalue = CalcCharacterSkill(GetCharacter(cn), skillName);
			}
		}
	}
	else
	{
		for(i = 1; i < OFFICER_MAX; i++)
		{
			cn = GetOfficersIndex(&_refCharacter,i);
			if(cn < 0) continue;
			if(GetAttribute(GetCharacter(cn),"quest.officertype") == OfficerType &&
				!IsPrisoner(GetCharacter(cn)) && !IsCompanion(GetCharacter(cn)))
			{
				if(CalcCharacterSkill(GetCharacter(cn), skillName) > skillvalue)
					skillvalue = CalcCharacterSkill(GetCharacter(cn), skillName);
			}
		}
	}
	return skillvalue;
}
// PB <--

// Payments -jsv  -->

// Scale factor for all salaries. Depends on the difficulty level and the leadership of the main character
// (with officers contributing both their skill and perks)
float PayScaleFactor()
{
	ref mc = GetMainCharacter();
	int leadership = GetShipSkill(mc, SKILL_LEADERSHIP);
	int iron_will = GetOfficersPerkUsing(mc, "IronWill");
	float leadership_factor = 1.0 - makefloat(leadership)*makefloat(1 + iron_will)/40.0;
	float difficulty_factor = makefloat(GetDifficulty() + 1)*0.5;
	return leadership_factor * difficulty_factor * SALARY_MULTIPLIER;
}

// The base pay 1 crew member gets montly, adjusted by leadership and difficulty coefficients.
float AdjustedCrewPay()
{
	return BASE_CREW_PAY * PayScaleFactor();
}

// nb: This one is used also when dividing plunder as a measure of comparison.
float DailyCrewPay()
{
	return AdjustedCrewPay()*12.0/365.0;
}

// NK CM/DP -->
// 05-04-18 do hirecrewcost here rather than in hirecrew.c
int GetCrewHireCost(ref ch)
{
	return makeint(AdjustedCrewPay() * 0.5);
}

// <-- Payments

void ResetAllLengths(ref pchar)
{
	pchar.crewstatus.explength = 0;
	int i, j, cn;
	ref chr;
	for(i = 0; i < GetPassengersQuantity(pchar); i++)
	{
		cn = GetPassenger(pchar, i);
		if(cn == -1) continue;
		chr = GetCharacter(cn);
		if(CheckAttribute(chr,"cexplength")) DeleteAttribute(chr,"cexplength");
		if(CheckAttribute(chr,"oexplength")) DeleteAttribute(chr,"oexplength");
	}
	for(i = 0; i <COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(pchar, i);
		if(cn == -1) continue;
		chr = GetCharacter(cn);
		if(CheckAttribute(chr,"cexplength")) DeleteAttribute(chr,"cexplength");
		if(CheckAttribute(chr,"oexplength")) DeleteAttribute(chr,"oexplength");
		for(j = 0; j <OFFICER_MAX; j++)
		{
			cn = GetOfficersIndex(chr, j);
			if(cn == -1) continue;
			chr = GetCharacter(cn);
			if(CheckAttribute(chr,"cexplength")) DeleteAttribute(chr,"cexplength");
			if(CheckAttribute(chr,"oexplength")) DeleteAttribute(chr,"oexplength");
		}
	}
}

bool GetFoodEver()
{
	if(CheckAttribute(GetMainCharacter(),"foodoff")) return false;
	return true;
}
//returns ratio for personal share size (including officers!) vs. total money
float GetPersonalShareRatio(ref char)
{
	return 0.05*makefloat(GetDifficulty());
}

//returns shareratio for chref (chref assumed to be, or have been, officer and/or companion of pchar
float GetCharShareRatio(ref pchar, ref chref)
{
	// LDH rewritten 12Mar09
	int cexplength = 0;
	int oexplength = 0;
	int explength  = 1;
	float share = 0.0;
	float base = GetPersonalShareRatio(pchar);	// 0.05 * difficulty = 0.05, 0.10, 0.15, 0.20
	if(CheckAttribute(pchar,"CrewStatus.explength"))
		explength = sti(pchar.CrewStatus.explength);	// days since signed articles, started paying salary, or last divided plunder

	if(explength == 0) explength = 1;
	if(CheckAttribute(chref,"cexplength")) cexplength += sti(chref.cexplength);	// days as companion
	if(CheckAttribute(chref,"oexplength")) oexplength += sti(chref.oexplength);	// days as officer
	if (cexplength + oexplength > explength)	// first time we've divided loot after long period of paying salary
	{
		// arbitrary number, gives a fairly good division for unusually long oexplength and cexplength
		// lower number gives officers more money, player less
		// this normally won't happen except in saved games when ResetAllLengths wasn't called, code left here to catch problems
		explength = 50;
	}

	share = base * (cexplength * COMP_MULT + oexplength) / OFF_DIV / explength;

	trace(chref.name + " " + chref.lastname + 
		" explen=" + explength + " companion=" + cexplength + " officer=" + oexplength + 
		" share ratio " + share*100.0 + "%% (" + share/GetPersonalShareRatio(pchar)*100.0 + "%% of psr)");
	return share;
}

//returns ratio for personal share size vs. total money, minus officer/companion part of share.
float GetPersonalShareRatioC(ref char)
{
	float base = GetPersonalShareRatio(char);
	float sub = 0;
	int i, j, cn;
	ref chref;
	for(i=0; i < GetPassengersQuantity(char); i++)
	{
		cn = GetPassenger(char, i);
		if(cn==-1) continue;
		sub += GetCharShareRatio(&char, GetCharacter(cn));
	}
	for(i = 1; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(&char,i);
		if(cn==-1) continue;
		chref = GetCharacter(cn);
		sub += GetCharShareRatio(&char, chref);
		for(j=0; j < GetPassengersQuantity(chref); j++)
		{
			cn = GetPassenger(chref, j);
			if(cn==-1) continue;
			sub += GetCharShareRatio(char, GetCharacter(cn));
		}
	}
	return (base - sub);
}

//gets personal share in gp
int GetPersonalShare(ref char)
{
	return makeint(makefloat(GetCharacterMoney(&char)) * GetPersonalShareRatio(&char));
}

//gets personal share, minus officers', in gp
// called once when it adds player character wealth
int GetPersonalShareC(ref char)
{
	int share = makeint(makefloat(GetCharacterMoney(&char)) * GetPersonalShareRatioC(&char));
	if(share < 0) share = 0; //just to be sure
	return share;
}

//gets character's share in gp
int GetCharShare(ref char, ref chref)
{
	return makeint(makefloat(GetCharacterMoney(&char)) * GetCharShareRatio(&char, &chref));
}

//gets individual crew share in gp.
int GetCrewShare(ref char)
{
	// NK div0 fix 05-04-17
	int cqty = GetSquadronTotalCrewQuantity(char);
	if(!cqty) return 0; // maybe should be 99999999999?
	return makeint(makefloat(GetCharacterMoney(char)) * (1.0 - (GetPersonalShareRatio(char) + LEFTOVER_SHARE)) / makefloat(cqty));
	// NK <--
}

//gets CSR
float GetCrewShareRatio(ref pchar)
{
	float csr = 1.0;

	// LDH 22Apr09
	// from salary calculations
	int explength = 1;
	if(CheckAttribute(pchar,"CrewStatus.explength")) explength = sti(pchar.CrewStatus.explength);
	if (explength < 1) explength = 1;
	// money for crew / expected money (three times normal daily pay times explength)
	csr = makefloat(GetCrewShare(pchar)) / (3.0 * DailyCrewPay() * explength);

	return csr;
}

//gets clamped CSR
float GetCrewShareRatioC(ref char)
{
	float csr = GetCrewShareRatio(char);
	if(csr > 1.0) csr = 2.0-(1.0/csr);
	return csr;
}

//returns name for csr
string GetCrewShareName(float csr)
{
	if(csr < 0.1) return XI_ConvertString("furious");
	if(csr < 0.2) return XI_ConvertString("very angry");
	if(csr < 0.3) return XI_ConvertString("angry");
	if(csr < 0.5) return XI_ConvertString("upset");
	if(csr < 0.7) return XI_ConvertString("very disappointed");
	if(csr < 0.9) return XI_ConvertString("disappointed");
	if(csr < 1.1) return XI_ConvertString("d"+"neutral");
	if(csr < 1.3) return XI_ConvertString("pleased");
	if(csr < 1.5) return XI_ConvertString("quite pleased");
	if(csr < 1.7) return XI_ConvertString("happy");
	if(csr < 1.8) return XI_ConvertString("very happy");
	if(csr < 1.9) return XI_ConvertString("extremely happy");
	return XI_ConvertString("overjoyed");
}

// DIVIDE THE PLUNDER
void DividePlunder(ref PChar, bool bNewExp)
{
	int cn,j,q;
	ref chref,chref2;

	float csr = GetCrewShareRatioC(PChar);
	PChar.Crewstatus.lastcsr = csr;
	float atcsr = 1.0;
	if(CheckAttribute(PChar,"Crewstatus.alltimecsr")) atcsr = stf(PChar.Crewstatus.alltimecsr);
	atcsr = (atcsr + GetCrewShareRatioC(PChar)) / 2.0;
	PChar.Crewstatus.alltimecsr = atcsr;
	AddWealthToCharacter(&PChar, GetPersonalShareC(PChar) * (0.75 + makefloat(GetFoodEver()) * 0.25));
	for(q = 0; q < GetPassengersQuantity(PChar); q++)
	{
		cn = GetPassenger(PChar, q);
		if(cn!=-1)
		{
			chref = GetCharacter(cn);
			AddWealthToCharacter(&chref, GetCharShare(PChar, &chref));		// LDH was addmoney 12Mar09
		}
	}

	// PB: Leadership Bonus -->
	float explength = GetAttribute(PChar, "CrewStatus.explength");
	if(explength > NORMAL_EXP_LENGTH) explength = NORMAL_EXP_LENGTH;
	explength = explength/NORMAL_EXP_LENGTH;
	AddPartyExpChar(PChar, "Leadership", makeint(15000 * csr * explength));
	// PB: Leadership Bonus <--

	for(q = 1; q < COMPANION_MAX; q++)
	{
		cn = GetCompanionIndex(&PChar,q);
		if(cn!=-1)
		{
			chref = GetCharacter(cn);
			AddWealthToCharacter(&chref, GetCharShare(PChar, &chref));		// LDH 14Jan09 - was addmoney 12Mar09
			for(j=0; j < GetPassengersQuantity(chref); j++)
			{
				cn = GetPassenger(chref, j);
				if(cn!=-1)
				{
					chref2 = GetCharacter(cn);
					AddWealthToCharacter(&chref2, GetCharShare(PChar, &chref2));	// LDH was addmoney 12Mar09
				}
			}
		}
	}
	ResetAllLengths(PChar);
	DeleteAttribute(PChar,"foodoff"); // reset food off toggle
	pchar.money = makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE);
	SetSquadronCrewQuantityTotalRatio(PChar, 0.2 * stf(PChar.Crewstatus.lastcsr) * (1.0 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/5.0));
	// new to reset ship goods qtys, repair, etc. NK 05-04-24
	if(bNewExp)	// GR: Only repair and restock ship if starting a new expedition
	{
		for(q = 0; q < COMPANION_MAX; q++)
		{
			cn = GetCompanionIndex(&PChar,q);
			if(cn!=-1)
			{
				chref = GetCharacter(cn);
				ResetShip(&chref)
			}
		}
	}
	// NK <--
	ClearPayOwed();		// LDH 08Mar09
}

// LDH - clear owed crew pay and officer salaries when dividing plunder - 08Mar09
void ClearPayOwed()
{
	ref PChar = GetMainCharacter();
	PChar.quest.CrewPayOwed = 0;
	int i, j, cn, on;
	for(i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(PChar, i);
		if(cn == -1) continue;
		if (IsTrader(GetCharacter(cn))) continue;

		if(cn!=sti(PChar.index))
			ClearOfficerPayOwed(&Characters[cn]);

		for(j = 1; j < OFFICER_MAX; j++)
		{
			on = GetOfficersIndex(Characters[cn], j);
			if(on == -1) continue;
			ClearOfficerPayOwed(&Characters[on]);
		}
	}
	for(i = 0; i < GetPassengersQuantity(pchar); i++)
	{
		cn = GetPassenger(pchar, i);
		if(cn == -1) continue;
		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned") || IsOfficer(curChar) || IsTrader(curChar)) continue;
		ClearOfficerPayOwed(&Characters[cn]);
	}
}

void ClearOfficerPayOwed(ref chref)
{
	if(!CheckAttribute(chref,"quest.OfficerPrice") || !GetRemovable(&chref)) return;//not a payable officer
	if(CheckAttribute(chref,"quest.OfficerPayOwed"))
	{
		chref.quest.OfficerPayOwed = 0;
	}
}

// LDH 16Apr09
// Officer hiring bonus is one month's salary for an active officer at current salary rate
// This is the same number that will show as salary in the character screen for an active officer
int CalcEncOfficerPrice(ref officer)
{
	return makeint(sti(officer.quest.officerprice) * OFF_PRICE_SCALAR * PayScaleFactor());
}

// used on DP. NK 05-04-24
// will set health, cannon, etc. to max, and add autobuy goods.
void ResetShip(ref chref)
{
	chref.ship.hp = GetCharacterShipHP(&chref);
	DeleteAttribute(&chref,"ship.blots");
	chref.ship.sp = GetCharacterShipSP(&chref);
	DeleteAttribute(&chref,"ship.sails");
	DeleteAttribute(&chref,"ship.masts");
	ResetCannons(&chref)
	if(FOOD_ON) AddCharacterGoods(chref, GOOD_WHEAT, 1+makeint(makefloat(GetCrewQuantity(&chref)) * FOOD_PER_CREW * WHEAT_DAYS));
	if(FOOD_ON) AddCharacterGoods(chref, GOOD_RUM, 1+makeint(makefloat(GetCrewQuantity(&chref)) * FOOD_PER_CREW * RUM_DAYS));
	AddCharacterGoods(chref, GOOD_BALLS, makeint(makefloat(GetMaxCannonQuantity(&chref)) * BALLS_PER));
	AddCharacterGoods(chref, GOOD_GRAPES, makeint(makefloat(GetMaxCannonQuantity(&chref)) * GRAPE_PER));
	AddCharacterGoods(chref, GOOD_KNIPPELS, makeint(makefloat(GetMaxCannonQuantity(&chref)) * CHAIN_PER));
	if(!USE_REAL_CANNONS) AddCharacterGoods(chref, GOOD_BOMBS, makeint(makefloat(GetMaxCannonQuantity(&chref)) * BOMBS_PER));
	if(CANNONPOWDER_MOD && GetMaxCannonQuantity(&chref) > 0)
	{
		int PowderPerShot = 0;
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(chref)]);
		int shotQty = GetCargoGoods(&chref,GOOD_BALLS) + GetCargoGoods(&chref,GOOD_GRAPES) + GetCargoGoods(&chref,GOOD_KNIPPELS) + GetCargoGoods(&chref,GOOD_BOMBS);
		if(CheckAttribute(rCannon,"gunpowder")) PowderPerShot = sti(rCannon.gunpowder);
		AddCharacterGoods(chref, GOOD_GUNPOWDER, POWDER_PER * shotQty * PowderPerShot);
	}
	AddCharacterGoods(chref, GOOD_SAILCLOTH, makeint(makefloat(GetCharacterShipHP(&chref)) * SAIL_PER));
	AddCharacterGoods(chref, GOOD_PLANKS, makeint(makefloat(GetCharacterShipHP(&chref)) * PLANKS_PER));
}

// KK -->
//gets total crew of squadron
int GetSquadronTotalCrewQuantity(ref mchref)
{
	int crewQ = 0;
	int i,cn;
//	crewQ += GetTotalCrewQuantity(mchref);
	ref chref;
	for(i=0; i<COMPANION_MAX; i++) // PB: Starting at 0 includes player ship crew too
	{
		cn = GetCompanionIndex(mchref,i);
		if( cn>=0 && GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ += GetTotalCrewQuantity(chref);
		}
	}
	return crewQ;
}
// <-- KK

// PB -->
//gets total crew on escort and specific quest ships
int GetUnremovableCrewQuantity(ref mchref)
{
	int crewQ = 0;
	int i,cn;
	ref chref;
	for(i=1; i<COMPANION_MAX; i++) // Deliberately exclude player crew, just in case
	{
		cn = GetCompanionIndex(mchref,i);
		if( cn>0 && !GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ += GetTotalCrewQuantity(chref);
		}
	}
	return crewQ;
}
// <-- PB

//gets healthy crew of squadron
int GetSquadronCrewQuantity(ref mchref)
{
	int crewQ = 0;
	int i,cn;
	crewQ += GetCrewQuantity(mchref);
	ref chref;
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if( cn >= 0 && GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ += GetCrewQuantity(chref);
		}
	}
	return crewQ;
}

//sets crew based on ratio
int SetSquadronCrewQuantityRatio(ref char, float ratio)
{
	int crewQ = 0;
	int tcrewQ = 0;
	int i,cn;
	crewQ = GetCrewQuantity(char);
	SetCrewQuantity(char, makeint(crewQ*ratio));
	tcrewQ += GetCrewQuantity(char);
	ref chref;
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(char,i);
		if( cn>=0 && GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ = GetCrewQuantity(chref);
			SetCrewQuantity(chref, makeint(crewQ*ratio));
			tcrewQ += GetCrewQuantity(chref);
		}
	}
	return tcrewQ;
}

int SetSquadronCrewQuantityTotalRatio(ref char, float ratio)
{
	ratio = clampf(ratio);
	int crewQ = 0;
	int tcrewQ = 0;
	int i,cn;
	crewQ = GetMaxCrewQuantity(char);
	SetCrewQuantity(char, makeint(crewQ*ratio));
	tcrewQ += GetCrewQuantity(char);
	ref chref;
	for(i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(char,i);
		if( cn>=0 && GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ = GetMaxCrewQuantity(chref);
			if(!bSeaActive) SetCrewQuantity(chref, makeint(crewQ*ratio));
			tcrewQ += GetCrewQuantity(chref);
		}
	}
	return tcrewQ;
}


/*
float GetSquadronGoodsRatio(ref _refCharacter,int _Goods)
{
	int i,cn;
	int retVal[4];
	int total = 0;
	for(i = 0; i<4; i++) retVal[i] = 0;
	retVal[0] = GetCargoGoods(&_refCharacter,_Goods);
	total += GetCargoGoods(&_refCharacter,_Goods);
	for(i=1; i<4; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			retVal[i] = GetCargoGoods(&Characters[cn],_Goods);
			total += GetCargoGoods(&Characters[cn],_Goods);
		}
	}
	float real_ret[4];
	for(i = 0; i<4; i++) realret[i] = retVal[i]/total;
	return real_ret; return retval;
}

void SetSquadronGoodsRatio(ref _refCharacter,int _Goods, int quantity, float ratio[4])
{
	SetCharacterGoods(_refCharacter, _Goods, makeint(quantity/ratio[0]));
	for(i=1; i<4; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			SetCharacterGoods(&Characters[cn], _Goods, makeint(quantity/ratio[i]));
		}
	}
}
*/
// NK CM/DP <--

float GetSailPercent(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"Ship.SP") ) return 100.0;
	int iSP = GetCharacterShipSP(_refCharacter);
	if(iSP<=0) return 100.0;
	float fpsp = 100.0*stf(_refCharacter.Ship.SP)/iSP;
	return fpsp;
}
float GetHullPercent(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.HP")) return 100.0;
	int iHP = GetCharacterShipHP(_refCharacter);
	if(iHP<=0) return 100.0;
	float fphp = 100.0*stf(_refCharacter.Ship.HP)/iHP;
	return fphp;
}
float GetSailRPD(ref _refCharacter) // процент ремонта парусов в день
{
	int repairSkill = GetShipSkill(_refCharacter,SKILL_REPAIR);
	float damagePercent = 100.0 - GetSailPercent(_refCharacter);
	if(damagePercent==0.0) return 0.0;
	return repairSkill*10.0 / damagePercent;
}
float GetHullRPD(ref _refCharacter) // процент ремонта корпуса в день
{
	int repairSkill = GetShipSkill(_refCharacter,SKILL_REPAIR);
	float damagePercent = 100.0 - GetHullPercent(_refCharacter);
	if(damagePercent==0.0) return 0.0;
	return repairSkill*10.0 / damagePercent;
}
int GetSailSPP(ref _refCharacter) // количество парусины на один процент починки
{
	return 9-GetCharacterShipClass(_refCharacter);
}
int GetHullPPP(ref _refCharacter) // количество досок на один процент починки
{
	return 9-GetCharacterShipClass(_refCharacter);
}

// Fellowtravels utilites
// работа с пассажирами
int GetPassengersQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers.Quantity")) return 0;
	return sti(_refCharacter.Fellows.Passengers.Quantity);
}

int GetNotCaptivePassengersQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers.Quantity"))
		return 0;

	int psgQuant = GetPassengersQuantity(_refCharacter);
	
	int result = 0;

	for(int i = 0; i < psgQuant; i++)
	{
		int cn = GetPassenger(_refCharacter, i);
		if(cn < 0)
			break;

		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar, "prisoned") && sti(curChar.prisoned) == true)
		{
			continue;
		}
		result++;
	}
	return result;
}

int GetPassenger(ref _refCharacter,int idx)
{
	if(idx<0) return -1;
	if(idx>=GetPassengersQuantity(_refCharacter)) return -1;

	string PsgAttrName = "id"+(idx+1);
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers."+PsgAttrName)) return -1;
	return sti(_refCharacter.Fellows.Passengers.(PsgAttrName));
}
int GetPassengerNumber(ref _refCharacter,int findCharacterIdx)
{
	int psgQuant = GetPassengersQuantity(_refCharacter);
	int cn;
	ref cr;
	for(int i=0; i<psgQuant; i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;
		cr = GetCharacter(cn);
		if(findCharacterIdx==sti(cr.index)) return i;
	}
	return -1;
}
int GetNotCaptivePassenger(ref _refCharacter,int idx)
{
	if(idx<0) return -1;
	int psgQuant = GetPassengersQuantity(_refCharacter);

	int curIdx=0;
	ref curChar;
	int cn;
	for(int i=0;i<psgQuant;i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;

		curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned"))
		{
			if(sti(curChar.prisoned)==true) continue;
		}
		if(curIdx==idx)	return sti(curChar.index);
		curIdx++;
	}
	return -1;
}
int ChangePassenger(ref _refCharacter,int idx, int psngIdx)
{
	int retVal = GetPassenger(_refCharacter,idx);
	ref rOldPass = GetCharacter(retVal);
	ref rNewPass = GetCharacter(psngIdx);

	if(idx>=0)
	{
		string PsgAttrName = "id"+(idx+1);
		_refCharacter.Fellows.Passengers.(PsgAttrName) = psngIdx;
// KK -->
		rNewPass.passenger = true;
		DeleteAttribute(rOldPass, "passenger");
// <-- KK

		ResetPartySkillAll(_refCharacter);
		ResetPartySkillAll(rOldPass); // Might have become captain in the process!
	//	ResetPartySkillAll(rNewPass);
	}
	return retVal;
}
int AddPassenger(ref _refCharacter,ref _refPassenger, int prisonFlag)
{
	int i;
	int PsgQuantity = GetPassengersQuantity(_refCharacter);
	if(PsgQuantity<PASSENGERS_MAX)
	{
		aref tmpRef; makearef(tmpRef,_refCharacter.Fellows.Passengers);
		string PsgAttrName;
		for(i=0;i<PsgQuantity;i++)
		{
			PsgAttrName = "id"+(i+1);
			if(tmpRef.(PsgAttrName)==_refPassenger.index) return PsgQuantity;
		}
		PsgQuantity++;
		tmpRef.Quantity = PsgQuantity;
		PsgAttrName = "id"+PsgQuantity;
		tmpRef.(PsgAttrName) = _refPassenger.index;
		_refPassenger.passenger = true; // KK
		if(prisonFlag==true)	_refPassenger.prisoned = true;
		else					ResetPartySkillAll(_refCharacter); // PB: Let's be careful here and reset ONLY party skill (could also be ResetSkillModifier/ResetEffectiveSkill)
	}
	else	trace("Overup maximum passengers quantity");
	return PsgQuantity;
}
int RemovePassenger(ref _refCharacter,ref _refPassenger)
{
	int i;
	RemoveOfficersIndex(_refCharacter,sti(_refPassenger.index));
	int PsgQuantity = GetPassengersQuantity(_refCharacter);
	int psgNum = GetPassengerNumber(_refCharacter,sti(_refPassenger.index));
	aref tmpRef;

	if(psgNum==-1)	// GR: if actual _refPassenger not found, see if a prisoner clone with the same name exists
	{
trace("RemovePassenger: Actual passenger '" + GetMySimpleName(_refPassenger) + "' with model '" + GetAttribute(_refPassenger,"model") + "' not found, searching for prisoner clone");
		int cn;
		ref cr;
		for(i=0; i<PsgQuantity; i++)
		{
			cn = GetPassenger(_refCharacter,i);
			if(cn==-1) break;
			cr = GetCharacter(cn);
			if(HasSubStr(GetAttribute(cr,"id"), "Enc_CabinCaptain") && GetMySimpleName(cr) == GetMySimpleName(_refPassenger) && GetAttribute(cr,"model") == GetAttribute(_refPassenger,"model"))
			{
				psgNum = i;
				if (CheckAttribute(cr, "passenger")) DeleteAttribute(cr, "passenger");
				break;
			}
		}
	}

	if(psgNum==-1) return PsgQuantity;

	makearef(tmpRef,_refCharacter.Fellows.Passengers);
	string inPsgAttrName,outPsgAttrName;
	for(i=(psgNum+1); i<PsgQuantity; i++)
	{
		inPsgAttrName = "id"+i;
		outPsgAttrName = "id"+(i+1);
		tmpRef.(inPsgAttrName) = tmpRef.(outPsgAttrName);
	}

	outPsgAttrName = "id"+PsgQuantity;
	DeleteAttribute(tmpRef,outPsgAttrName);
	PsgQuantity--;
	tmpRef.Quantity = PsgQuantity;
	if (CheckAttribute(_refPassenger, "passenger")) DeleteAttribute(_refPassenger, "passenger"); // KK
	ResetPartySkillAll(_refCharacter); // PB: Let's be careful here and reset ONLY party skill (could also be ResetSkillModifier/ResetEffectiveSkill)
	return PsgQuantity;
}

// PB -->
bool IsPassenger(ref _refCharacter)
{
	// Old check Depreciated by PB
//	if(!CheckAttribute(_refCharacter,"index")) 		return false;								// MAXIMUS
//	if (CheckAttribute(_refCharacter, "passenger"))	return sti(_refCharacter.passenger);

	int cn;
	ref chr;
	ref pchar = GetMainCharacter();
	for(int i=0; i < GetPassengersQuantity(pchar); i++)
	{
		cn = GetPassenger(pchar, i);
		if (cn < 0)													continue;					// Skip invalid characters
		chr = GetCharacter(cn);																	// Reference to the character
		if(!CheckAttribute(chr,"index"))							continue;					// Skip invalid characters
		if(CheckAttribute(_refCharacter, "index") && CheckAttribute(chr, "index"))
		{
			if(sti(_refCharacter.index) == sti(chr.index))			return true;				// This character is in the captain's passenger list
		}
	}

	return false;
}
// PB <--

int FindFellowtravellers(ref _refCharacter,ref _refFindCharacter)
{
	int i;
	string stmp;
	aref atmp;
	aref curref;

	if(sti(_refFindCharacter.index)==-1) return FELLOWTRAVEL_NO;
	if(CheckAttribute(_refFindCharacter,"prisoned"))
	{
		if(sti(_refFindCharacter.prisoned)==true) return FELLOWTRAVEL_CAPTIVE;
	}
	for(i=1;i<OFFICER_MAX;i++)
	{
		if( sti(_refFindCharacter.index) == GetOfficersIndex(_refCharacter,i) )	return FELLOWTRAVEL_OFFICER;
	}
	for(i=0;i<GetPassengersQuantity(_refCharacter);i++)
	{
		if(sti(_refFindCharacter.index)==GetPassenger(_refCharacter,i))	return FELLOWTRAVEL_PASSENGER;
	}
	for(i=1;i<COMPANION_MAX;i++)
	{
		if( GetCompanionIndex(_refCharacter,i)==sti(_refFindCharacter.index) )	return FELLOWTRAVEL_COMPANION;
	}
	return FELLOWTRAVEL_NO;
}

// 04-12-06 to find if char is in party. Searches officers, companions, and companion officers.
bool IsInParty(int mchridx, int chridx)
{
	int i,j;
	if(chridx == -1 || mchridx == -1) return false;
	ref mchr;
	for(j = 0; j < COMPANION_MAX; j++)
	{
		if(GetCompanionIndex(GetCharacter(mchridx),j) == -1) continue;
		mchr = GetCharacter(GetCompanionIndex(GetCharacter(mchridx),j));
		for(i=0;i<OFFICER_MAX;i++)
		{
			if(GetOfficersIndex(mchr,i) == chridx) return true;
		}
	}
	return false;
}

// работа с компаньонами
int SetCompanionIndex(ref _refCharacter,int _CompanionNum, int _CompanionIdx)
{
	if(_CompanionNum == -1)
	{
		for(int i=1; i<COMPANION_MAX; i++)
		{
			if(GetCompanionIndex(_refCharacter, i) == -1)
			{
				_CompanionNum = i;
				break;
			}
		}
	}
	if(_CompanionNum<1) return _CompanionIdx;
	if(_CompanionNum>=COMPANION_MAX) return _CompanionIdx;

	if(_CompanionIdx!=-1)
	{
		for(i=0;i<COMPANION_MAX;i++)
		{
			if(GetCompanionIndex(_refCharacter,i)==_CompanionIdx) return -1;
		}
	}

	string compName = "id"+_CompanionNum;
	int retVal = GetCompanionIndex(_refCharacter,_CompanionNum);
	_refCharacter.Fellows.Companions.(compName) = _CompanionIdx;
	if(_CompanionIdx >=0)
	{
		Characters[_CompanionIdx].CompanionOf.idx = GetCharacterIndex(_refCharacter.id); // KK
		Characters[_CompanionIdx].CompanionOf.num = _CompanionNum; // KK
		if(CheckAttribute(&Characters[_CompanionIdx],"nation") )
		{
			Characters[_CompanionIdx].prev_nation = Characters[_CompanionIdx].nation;
			Characters[_CompanionIdx].nation = _refCharacter.nation;
		}
		MakeOfficerCaptain(&Characters[_CompanionIdx]);
	}
	if( retVal>=0)
	{
		ref chr = GetCharacter(retVal);
		if(CheckAttribute(chr, "prev_nation"))
		{
			chr.nation = chr.prev_nation;
			DeleteAttribute(chr, "prev_nation");
		}
		RestoreOfficerFromCaptain(chr);
		DeleteAttribute(chr, "CompanionOf");
	}

	Event(EVENT_CHANGE_COMPANIONS,"");
	return retVal;
}
int RemoveCharacterCompanion(ref _refCharacter, ref refCompanion)
{
	string compName;
	int i;

	aref refComps;
	makearef(refComps,_refCharacter.Fellows.Companions);
	for(i=1; i<COMPANION_MAX; i++)
	{
		compName = "id"+i;
		if(CheckAttribute(refComps,compName) && refComps.(compName)==refCompanion.index)
		{
			refComps.(compName) = -1;
			refCompanion.location = _refCharacter.location;
			refCompanion.location.group = _refCharacter.location.group;
			refCompanion.location.locator = _refCharacter.location.locator;
			if (CheckAttribute(refCompanion, "CompanionOf")) DeleteAttribute(refCompanion, "CompanionOf"); // KK
			Event(EVENT_CHANGE_COMPANIONS,"");
			return i;
		}
	}
	return -1;
}
int GetCompanionIndex(ref _refCharacter,int _CompanionNum)
{
	if(_CompanionNum<0             )	return -1;
	if(_CompanionNum>=COMPANION_MAX)	return -1;
	if(_CompanionNum==0)
	{
		if(CheckAttribute(_refCharacter,"index")) return sti(_refCharacter.index);
	}

	string compName = "id"+_CompanionNum;
	if(!CheckAttribute(_refCharacter,"Fellows.Companions."+compName)) return -1;
	return sti(_refCharacter.Fellows.Companions.(compName));
}
int GetCompanionNumber(ref _refCharacter,int _CompanionIdx)
{
	for(int i=0; i<COMPANION_MAX; i++)
	{
		if( GetCompanionIndex(_refCharacter,i) == _CompanionIdx ) return i;
	}
	return -1;
}
int GetCompanionQuantity(ref _refCharacter)
{
	int qn = 1;
	for(int i=1; i<COMPANION_MAX; i++)
	{
		if( GetCompanionIndex(_refCharacter,i)>=0 ) qn++;
	}
	return qn;
}

// работа с офицерами
int GetOfficersQuantity(ref _refCharacter)
{
	int idx=0;
	for(int i=1; i<OFFICER_MAX; i++)
	{
		if( GetOfficersIndex(_refCharacter,i)!=-1 ) idx++;
	}
	return idx;
}
int GetOfficersIndex(ref _refCharacter,int _OfficerNum)
{
	if(_OfficerNum<0            ) return -1;
	if(_OfficerNum>OFFICER_MAX-1) return -1;
	if(_OfficerNum==0)
	{
		if(CheckAttribute(_refCharacter,"index")) return MakeInt(_refCharacter.index);
	}

	string compName = "id"+_OfficerNum;
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers.Officers."+compName)) return -1;
	return sti(_refCharacter.Fellows.Passengers.Officers.(compName));
}
int SetOfficersIndex(ref _refCharacter,int _OfficerNum, int _OfficerIdx)
{
	int i;
	if(_OfficerNum == -1)
	{
		for(i=1; i<OFFICER_MAX; i++)
		{
			if(GetOfficersIndex(_refCharacter, i) == -1)
			{
				_OfficerNum = i;
				break;
			}
		}
	}
	if(_OfficerNum<1) return _OfficerIdx;
	if(_OfficerNum>=OFFICER_MAX) return _OfficerIdx;

	if(_OfficerIdx!=-1)
	{
		for(i=0;i<OFFICER_MAX;i++)
		{
			if(GetOfficersIndex(_refCharacter,i)==_OfficerIdx) return -1;
		}
		AddPassenger(_refCharacter,GetCharacter(_OfficerIdx),false);
	}

	string compName = "id"+_OfficerNum;
	int retVal = GetOfficersIndex(_refCharacter,_OfficerNum);
	_refCharacter.Fellows.Passengers.Officers.(compName) = _OfficerIdx;
	if(_OfficerIdx>=0)
	{
		LAi_SetOfficerType(GetCharacter(_OfficerIdx));
		Characters[_OfficerIdx].location = _refCharacter.location;
		Characters[_OfficerIdx].OfficerOf.idx = GetCharacterIndex(_refCharacter.id); // KK
		Characters[_OfficerIdx].OfficerOf.num = _OfficerNum; // KK
	}
	if(retVal>=0)
	{
		LAi_SetCitizenTypeNoGroup(GetCharacter(retVal));
		Characters[retVal].location = "none";
	}
	Event(EVENT_CHANGE_OFFICERS,"");
	return retVal;
}
bool RemoveOfficersIndex(ref _refCharacter, int _OfficerIdx)
{
	if(_OfficerIdx==-1) return false;
	for(int i=1; i<OFFICER_MAX; i++)
	{
		if(GetOfficersIndex(_refCharacter,i) == _OfficerIdx)
		{
			SetOfficersIndex(_refCharacter,i,-1);
			if (CheckAttribute(&Characters[_OfficerIdx], "OfficerOf")) DeleteAttribute(&Characters[_OfficerIdx], "OfficerOf"); // KK
			return true;
		}
	}
	return false;
}

// KK -->
int GetOfficerOf(ref _refCharacter)
{
	if (CheckAttribute(_refCharacter, "OfficerOf.idx")) return sti(_refCharacter.OfficerOf.idx);
	return -1;
}

int GetCompanionOf(ref _refCharacter)
{
	if (CheckAttribute(_refCharacter, "CompanionOf.idx")) return sti(_refCharacter.CompanionOf.idx);
	return -1;
}
// <-- KK

// table service
//MAXIMUS -->
string GetTranslatedReputationForSex(ref xi_refCharacter, string repName)
{
	if(!CheckAttribute(xi_refCharacter,"sex")) return XI_ConvertString("i"+repName);

	string chReputation = "";
	switch(xi_refCharacter.sex)
	{
		case "man": chReputation = XI_ConvertString("i"+repName); break;
		case "woman": chReputation = XI_ConvertString("w"+repName); break;
		chReputation = XI_ConvertString("i"+repName);
	}
	return chReputation;
}
//MAXIMUS <--

string GetReputationName(int reputation)
{
// KK -->
	int delta = roundup(makefloat(REPUTATION_MAX - REPUTATION_MIN + 1) / makefloat(REPUTATION_TABLE_SIZE));
	int rep = makeint(makefloat(reputation) / makefloat(delta) - 0.5);	// GR: Add -0.5
	if (rep < 0) rep = 0;												// GR: Needed because reputation < 5 will give rep < 0
	return ReputationTable[rep];
// <-- KK
}

string GetMoraleName(int morale)
{
// KK -->
	int delta = roundup(makefloat(MORALE_MAX - MORALE_MIN + 1) / makefloat(MORALE_TABLE_SIZE));
	int mor = makeint(makefloat(morale) / makefloat(delta));
	return MoraleTable[mor];
// <-- KK
}

// PB -->
int FindCaptainIndex(ref character)
{
	int idx = GetOfficerOf(character);
	if (idx == -1) idx = GetAttribute(character, "index"); // If not an officer of anyone, return original character
	return idx;
}

int FindCommanderIndex(ref character)
{
	int idx = GetCompanionOf(character);
	if (idx == -1) idx = GetAttribute(character, "index"); // If not an officer of anyone, return original character
	return idx;
}
// PB <--

// NK -->
int GetCharacterMoney(ref rChr)
{
	// PB: Store Owners use TOWN gold for item transactions -->
	if( HasSubStr(rChr.location, "_store") && GetTownStoreOwnerIndex(GetCurrentTownID()) == GetCharacterIndex(rChr.id) )
	{
		return GetTownGold(GetCurrentTownID());
	}
	// PB: Store Owners use TOWN gold for item transactions <--

	// PB: Blacksmiths use TOWN gold for item transactions -->
	if( HasSubStr(rChr.Dialog.Filename, "Blacksmith") )
	{
		return GetTownGold(GetCurrentTownID());
	}
	// PB: Blacksmiths use TOWN gold for item transactions <--
	if( CheckAttribute(rChr,"money") ) return sti(rChr.money);
	return 0;
}

int GetRandCharMoney(ref char, float scalar)
{
	//TODO: Tie this more to officertypes too
	scalar *= 6-GetDifficulty();
	int retval = makeint((floatRet(rand(makeint(scalar/2.0)) + scalar/2.0 > 1,rand(makeint(scalar/2.0)) + scalar/2.0,1)) * (sti(char.rank)/2.0 + fRand(sti(char.rank)) * (fRand(CalcCharacterSkill(GetMainCharacter(), SKILL_SNEAK)-1)+1))+0.5);
	if(retval < 20) retval = 5+rand(25);
	return retval;
}

/**
 * Returns the ransom of a captive.
 *
 * If ransom is not set at calltime, it will be calculated.
 *
 * @param   captive  Reference to captive, whose ransom to return.
 * @return  The ransom, you get for the captive.
 */
int GetPrisonRansomCost(ref captive)
{
	//ref char = CharacterFromID(refCharacter.id); // Swindler: We create a reference by using a reference to the same object?
	if(!CheckAttribute(captive, "ransom"))
	{
		// Swindler 2006-07-10 -->
		// Calculation code moved to function CalculatePrisonRansomCost(ref character)
		captive.ransom = CalculatePrisonRansomCost(&captive)
		// Swindler <--
	}

	return sti(captive.ransom);
}

/**
 * Calculates the ransom of a captive.
 *
 * @param   captive  Reference to captive, whose ransom to calculate.
 * @return  The ransom, you get for the captive.
 */
// Swindler 2006-07-10 -->
// Bugfixing and refactoring of code, previously in GetPrisonRansomCost(ref captive)
int CalculatePrisonRansomCost(ref captive)
{
	// ref shipt = GetShipByType(0); // NK bugfix 04-06 - Swindler 2006-07-10: not necessary anymore, as GetShipByType() now does this check. 
	float srank = sqrt(sqrt(pow(sti(captive.rank),3.0)));
	float sclass;
	float sweight;

	if (CheckAttribute(captive, "shiptype"))
	{
		ref shipt = GetShipByID(captive.shiptype);
		sclass = makefloat(10 - sti(shipt.Class));
		sweight = sqrt(makefloat(sti(shipt.Weight)) / 10000 * 508); // This not changed by PRS3 sadly.Changed 04-09-19 to be more accurate, was simply /19.7
	}
	else
	{
		sclass = 6.0;
		sweight = 22.0;
	}

	return makeint(sclass * sweight * srank * makefloat(50 + rand(50 + CalcCharacterSkill(GetMainCharacter(), SKILL_SNEAK)*10))/10.0);
}
// Swindler <--

int GetLevel(ref chref) { if(CheckAttribute(chref,"rank")) { return sti(chref.rank); } return 0; }
// NK <--


// DP mod -->
// Superceded by PayScaleFactor -jsv 
/* float CalcOffScalar()
{
	return
		(1.0 - (
				  makefloat(GetShipSkill(GetMainCharacter(), SKILL_LEADERSHIP))
				  * makefloat(1.0 + CheckPerkForSingleCharacter(GetMainCharacter(), "IronWill")) / 40.0
		)) * (0.5 + makefloat(GetDifficulty()) * 0.5);
} */

//JA 26Nov06 -> Update salary system. Pay computed daily for crew and all officers.
int CalcSquadronPayment(ref mchref)
{
	int PaymentQ = CalcOfficerPayOwed(mchref);
	PaymentQ += CalcCrewPayment(&mchref, GetSquadronTotalCrewQuantity(mchref));
	return PaymentQ;
}

int CalcOfficerPayOwed(ref mchref)
{
	int i, j, cn, on;
	float PaymentQ = 0
	for(i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref, i);
		if(cn == -1) continue;
		if(cn != mchref.index && CheckAttribute(Characters[cn],"quest.OfficerPrice") && GetRemovable(&Characters[cn]))
		{
			if(CheckAttribute(Characters[cn],"quest.OfficerPayOwed")) PaymentQ += sti(Characters[cn].quest.OfficerPayOwed);
		}
		
		for(j = 1; j < OFFICER_MAX; j++)
		{
			on = GetOfficersIndex(Characters[cn], j);
			if(on == -1) continue;
			if(CheckAttribute(Characters[on],"quest.OfficerPrice") && GetRemovable(&Characters[on]))
			{
				if(CheckAttribute(Characters[on],"quest.OfficerPayOwed")) PaymentQ += sti(Characters[on].quest.OfficerPayOwed);
			}
		}
	}
	for(i = 0; i < GetPassengersQuantity(mchref); i++)
	{
		cn = GetPassenger(mchref, i);
		if(cn == -1) continue;
		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned") || IsOfficer(curChar)) continue;
		if(CheckAttribute(curChar,"quest.OfficerPrice") && GetRemovable(curChar))
		{
			if(CheckAttribute(Characters[cn],"quest.OfficerPayOwed")) PaymentQ += sti(Characters[cn].quest.OfficerPayOwed);
		}
	}
	return makeint(PaymentQ);
}

int CalcCrewPayment(ref mchref, int crewQ)
{
	int PaymentQ = 0
	if(CheckAttribute(mchref,"quest.CrewPayOwed")) PaymentQ = stf(mchref.quest.CrewPayOwed);

	return makeint(PaymentQ);
}

void DoDailyCrewPay()
{
	ref mchref = GetMainCharacter();
	if (CheckAttribute(mchref,"isnotcaptain")) return;		// LDH 16Apr09

	int i, j, cn, on;
	float fOffScalar = PayScaleFactor();
	int CrewQ = GetSquadronTotalCrewQuantity(mchref);

	// 0: should be main char...
	for(i = 1; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref, i);
		if(cn == -1) continue;
		if(cn!=sti(mchref.index)) AddDailyOfficerPay(&Characters[cn], COMP_PRICE_SCALAR*fOffScalar);
		for(j = 1; j < OFFICER_MAX; j++)
		{
			on = GetOfficersIndex(Characters[cn], j);
			if(on == -1) continue;
			AddDailyOfficerPay(&Characters[on], OFF_PRICE_SCALAR*fOffScalar);
		}
	}

	for(i = 0; i < GetPassengersQuantity(mchref); i++)
	{
		cn = GetPassenger(mchref, i);
		if(cn == -1) continue;
		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned") || IsCompanion(curChar)) continue;
		if(CheckAttribute(curChar, "quest.officertype"))
		{
			AddDailyOfficerPay(&Characters[cn], OFF_PRICE_SCALAR * fOffScalar); // Sulan: corrected.
		}
		else
		{
			AddDailyOfficerPay(&Characters[cn], PASSENGER_PRICE_SCALAR * fOffScalar); //Sulan: corrected.
		}
	}
	float fCrewPay = 0;
	//add crew pay owed:
	
	if(CheckAttribute(mchref,"quest.CrewPayOwed")) fCrewPay = stf(mchref.quest.CrewPayOwed);
	fCrewPay += makefloat(crewQ) * DailyCrewPay();
	mchref.quest.CrewPayOwed = fCrewPay;
}

void AddDailyOfficerPay(ref curChar, int PayMult)
{
	if(CheckAttribute(curChar,"quest.OfficerPrice") && GetRemovable(curChar)) //check that officer should be paid
	{
		float fOPay = 0;
		if(CheckAttribute(curChar,"quest.OfficerPayOwed")) fOPay = stf(curChar.quest.OfficerPayOwed);

		fOPay += stf(curChar.quest.OfficerPrice)*PayMult*12/365;
		curChar.quest.OfficerPayOwed = fOPay;
	}
}

int GetEstimatedOfficerPay()
{
	ref mchref = GetMainCharacter();
	if (CheckAttribute(mchref,"isnotcaptain")) return 0;		// LDH 16Apr09

	int i, j, cn, on;
	float fOffScalar = PayScaleFactor();
	float fEstTotalPay = 0;
	for(i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref, i);
		if(cn == -1) continue;
		if(cn!=sti(mchref.index)) fEstTotalPay += stf(Characters[cn].quest.OfficerPrice)*COMP_PRICE_SCALAR*fOffScalar;
		for(j = 1; j < OFFICER_MAX; j++)
		{
			on = GetOfficersIndex(Characters[cn], j);
			if(on == -1) continue;
			fEstTotalPay += stf(Characters[on].quest.OfficerPrice)*OFF_PRICE_SCALAR*fOffScalar;
		}
	}
	for(i = 0; i < GetPassengersQuantity(mchref); i++)
	{
		cn = GetPassenger(mchref, i);
		if(cn == -1) continue;
		ref curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned") || IsOfficer(curChar) || IsCompanion(curChar)) continue;
		if (!CheckAttribute(Characters[cn], "quest.OfficerPrice")) continue;		// LDH 18Apr09
		fEstTotalPay += stf(Characters[cn].quest.OfficerPrice)*PASSENGER_PRICE_SCALAR*fOffScalar;
	}
	return makeint(fEstTotalPay);
}

int GetEstimatedCrewPay()
{
	ref mchref = GetMainCharacter();
	if (CheckAttribute(mchref,"isnotcaptain")) return 0;		// LDH 16Apr09

	float fEstCrewPay = 0;
	fEstCrewPay += GetSquadronTotalCrewQuantity(mchref) * AdjustedCrewPay();
	return makeint(fEstCrewPay);
}
// <-- JA

// KK -->
int GetRaiseMoraleCost(ref chref)
{
	ref mchref = GetMainCharacter();
	float fEstCrewPay = GetCrewQuantity(chref) * AdjustedCrewPay();
	return makeint(fEstCrewPay);
}
// <-- KK

int AddMoneyToCharacter(ref _refCharacter,int _Money)
{
	// PB: Store Owners use TOWN gold for item transactions -->
	if( HasSubStr(_refCharacter.location, "_store") && GetTownStoreOwnerIndex(GetCurrentTownID()) == GetCharacterIndex(_refCharacter.id) )
	{
		return SetTownGold(GetCurrentTownID(), GetTownGold(GetCurrentTownID()) + _Money);
	}
	// PB: Store Owners use TOWN gold for item transactions <--

	// PB: Blacksmiths use TOWN gold for item transactions -->
	if( HasSubStr(_refCharacter.Dialog.Filename, "Blacksmith") )
	{
		return SetTownGold(GetCurrentTownID(), GetTownGold(GetCurrentTownID()) + _Money);
	}
	// PB: Blacksmiths use TOWN gold for item transactions <--

	if(CheckAttribute(_refCharacter,"Money")) int newMoney = sti(_refCharacter.Money) + _Money;
	if(newMoney<0) newMoney=0;
	_refCharacter.Money = newMoney;
	return newMoney;
}

// RM Put these in Char_ut.c -->
/*NEW PROPERTY:
char.wealth = personal wealth; default to 4000gp (200x20)
char.land = personal land, in acres; default to 0.
Add interface on char sheet--or maybe talk to qm?--to let you loan money to party.
Change quests so the personal ones pay the character personally. (i.e Patric)?
*/
int GetCharacterWealth(ref char)
{
	int wealth = 500;
	if(CheckAttribute(char,"wealth")) wealth = sti(char.wealth);
	char.wealth = wealth;
	return sti(char.wealth);
}

int AddWealthToCharacter(ref _refCharacter, int _wealth)
{
	int newwealth = GetCharacterWealth(_refCharacter) + _wealth;
	if(newwealth<0) newwealth=0;
	_refCharacter.wealth = newwealth;
	return newwealth;
}

// KK -->
int GetCharacterLandIslandNation(ref _refCharacter, string sIsland, int iNation)
{
	if (FindIsland(sIsland) < 0) return 0;
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) return 0;
	iNation++;
	string n = "n" + iNation;
	if (CheckAttribute(_refCharacter, "land." + sIsland + "." + n + ".quantity")) return sti(_refCharacter.land.(sIsland).(n).quantity);
	return 0;
}

int GetCharacterLandNation(ref _refCharacter, int iNation)
{
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) return 0;
	iNation++;
	string n = "n" + iNation;
	int quantity = 0;
	for (int i = 0; i < ISLANDS_QUANTITY; i++)
	{
		if (!CheckAttribute(&Islands[i], "id")) continue;
		string sIsland = Islands[i].id;
		if (CheckAttribute(_refCharacter, "land." + sIsland + "." + n + ".quantity")) quantity = quantity + sti(_refCharacter.land.(sIsland).(n).quantity);
	}
	return quantity;
}

int GetCharacterLandIsland(ref _refCharacter, string sIsland)
{
	if (FindIsland(sIsland) < 0) return 0;
	int quantity = 0;
	for (int i = 1; i <= NATIONS_QUANTITY; i++)
	{
		string n = "n" + i;
		if (CheckAttribute(_refCharacter, "land." + sIsland + "." + n + ".quantity")) quantity = quantity + sti(_refCharacter.land.(sIsland).(n).quantity);
	}
	return quantity;
}

int GetCharacterLand(ref _refCharacter)
{
	int quantity = 0;
	for (int i = 0; i < ISLANDS_QUANTITY; i++)
	{
		if (!CheckAttribute(&Islands[i], "id")) continue;
		string sIsland = Islands[i].id;
		quantity = quantity + GetCharacterLandIsland(_refCharacter, sIsland);
	}
	return quantity;
}

int AddLandToCharacter(ref _refCharacter, string sIsland, int iNation, int quantity)
{
	if (FindIsland(sIsland) < 0) return 0;
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) return 0;
	int newland = GetCharacterLandIslandNation(_refCharacter, sIsland, iNation) + quantity;
	if (newland < 0) newland = 0;
	iNation++;
	string n = "n" + iNation;
	_refCharacter.land.(sIsland).(n).quantity = newland;
	return newland;
}

void RemoveLandFromCharacterNation(ref _refCharacter, int iNation)
{
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) return;
	iNation++;
	string n = "n" + iNation;
	for (int i = 0; i < ISLANDS_QUANTITY; i++)
	{
		if (!CheckAttribute(&Islands[i], "id")) continue;
		string sIsland = Islands[i].id;
		if (CheckAttribute(_refCharacter, "land." + sIsland + "." + n)) DeleteAttribute(_refCharacter, "land." + sIsland + "." + n);
	}
}

void RemoveLandFromCharacterIsland(ref _refCharacter, string sIsland)
{
	if (FindIsland(sIsland) < 0) return 0;
	for (int i = 1; i <= NATIONS_QUANTITY; i++)
	{
		string n = "n" + i;
		if (CheckAttribute(_refCharacter, "land." + sIsland)) DeleteAttribute(_refCharacter, "land." + sIsland);
	}
}

void RemoveLandFromCharacter(ref _refCharacter)
{
	if (CheckAttribute(_refCharacter, "land")) DeleteAttribute(_refCharacter, "land");
}
// <-- KK

//returns char's rank with nation
int GetRank(ref char, int iNation)
{
	int rank = 0;
	string sNation = iNation;
	if(CheckAttribute(char,"nations."+sNation+".Rank"))
		rank = sti(char.nations.(sNation).Rank);
	return rank;
}

//returns char's OLD rank with nation; oldrank assigned on LeaveService()
int GetOldRank(ref char, int iNation)
{
	int rank = 0;
	string sNation = iNation;
	if(CheckAttribute(char,"nations."+sNation+".OldRank"))
		rank = sti(char.nations.(sNation).OldRank);
	return rank;
}

// KK -->
int GetBestRank(ref char, ref bestrank, ref brnation)
{
	bestrank = 0;
	brnation = ENGLAND;
	for (int i = 0; i < NATIONS_QUANTITY; i++)
	{
		int curRank = GetRank(char, i);
		if (curRank > bestrank) {
			bestrank = GetRank(char, i);
			brnation = i;
		}
	}
	return brnation; //added by levis to return the nation also.
}

bool HasRank(ref char, int iNation)
{
	if (iNation < 0 || iNation > NATIONS_QUANTITY) return false;
	string rn = "" + iNation;
	if (CheckAttribute(char, "nations." + rn + ".Title")) return true;
	int iRank = GetRank(char, iNation);
	rn = "" + iRank;
	return iRank > 0 && CheckAttribute(Nations[iNation],"Ranks."+rn) == true;
}
// <-- KK

//returns the name of char's rank with nation.
string GetRankName(ref char, int iNation)
{
	if (iNation < -1 || iNation > NATIONS_QUANTITY) return ""; // KK
	int iRank = GetRank(char, iNation);
	return GetRankNameDirect(char, iNation, iRank);
}

//returns the name of rank in iNation
string GetRankNameDirect(ref char, int iNation, int rank)
{
	if (iNation < -1 || iNation > NATIONS_QUANTITY) return ""; // KK
	string rn = rank;
	if (iNation == PERSONAL_NATION)	// PB: Use this as flag to return fame level instead of PIRATE
	{
		rn = iclamp(1, sti(Nations[PIRATE].Ranks.Quantity), rank);	// LDH 08Oct06 fix for "Known as mister" at rank 13
		if(CheckAttribute(Nations[PIRATE],"Ranks."+rn))		return Nations[PIRATE].Ranks.(rn);		// PB: Fame Levels
	}

//	if (ProfessionalNavyNation() == iNation)
	if (ProfessionalNavyNationChar(char) == iNation)	// GR: Look at whether this char, not player char, is in the navy
	{
		if(CheckAttribute(Nations[iNation],"Ranks."+rn))	return Nations[iNation].Ranks.(rn);		// NK: Navy Ranks
	}
	else
	{
		if(CheckAttribute(Nations[iNation],"Titles."+rn))	return Nations[iNation].Titles.(rn);	// PB: Privateer Titles
	}
// KK -->
	rn = "" + iNation;
	if (CheckAttribute(char, "nations." + rn + ".Title"))	return char.nations.(rn).Title;
// <-- KK
	// 05-07-18 fix to use getmyaddress
	object tempchar;
	tempchar.nation = iNation;
	return GetMyAddressForm(&tempchar, &char, ADDR_CIVIL, false, false);
}

/*NEW PROPERTY: char.title. Use this instead of firstname in dialogs if(char.title != "")
for now, I'm backing up char.name to char.firstname and setting char.name to char.title,
so I don't have to rewrite all that dialog.
*/

//updates title by checking for best rank. Overwrites name, puts actual name in firstname // KK -->
/*int UpdateTitle(ref char)
{
	int bestrank = 0;
	for(int i = 0; i < NATIONS_QUANTITY; i++)
	{
		if(GetRank(char, i) > bestrank)
		{
			bestrank = GetRank(char, i);
			char.title = GetRankName(char, i);
			if(!CheckAttribute(char,"firstname")) char.firstname = char.name;
			if (XI_ConvertString(char.title) == "")
				char.name = char.title;//MAXIMUS
			else
				char.name = XI_ConvertString(char.title);
		}
	}
	if(!bestrank && CheckAttribute(char,"firstname"))
	{
		if (XI_ConvertString(char.firstname) == "")
			char.name = char.firstname;//MAXIMUS
		else
			char.name = XI_ConvertString(char.firstname);
		DeleteAttribute(&char, "title");
		// KK DeleteAttribute(&char,"firstname"); // This line removed first name leaving only surname.
	}
	return bestrank;
}*/ // <-- KK

/*promotes char in service of iNation (if possible) and returns new rank; also adds
reqnextrank * GOVREL_RANKSCALAR points to govrel.
returns -1 if not possible. Also sets char.title to best title, and backs up char.name
to char.firstname (if it hasn't already), and sets char.name to char.title. */
int Promote(ref char, ref gov, int iNation)
{
	bool InTutDeck = false;
	if (GetAttribute(char, "location") == "Tutorial_Deck") InTutDeck = true;
	if (!InTutDeck)
	{
		if(iNation == PIRATE && GetCharacterReputation(char) <= REPUTATION_RASCAL) ChangeCharacterReputation(char, -5); // Evil pirates lose reputation! - GR
		else ChangeCharacterReputation(char, 5); //Add some reputation gain -Levis
	}
	string sNation = iNation;
	int curRank = GetRank(char, iNation);
	if(curRank >= sti(Nations[iNation].Ranks.Quantity)) return false;
	ChangeGovRelation(&char, &gov, GOVREL_RANKSCALAR*RequiredNextRank(char, iNation));
	curRank++;
	SetRank(char, iNation, curRank); // PB: was	char.nations.(sNation).Rank = curRank;
	GivePromotionReward(iNation); // PB
//	bool NoLandGiven = ProfessionalNavyNation() != UNKNOWN_NATION && curRank < 7;
	bool NoLandGiven = curRank < 7;	// GR: no land for navy OR privateers until you are landed gentry
	if(NoLandGiven || iNation == PIRATE)
	{
		if (!InTutDeck) WriteNewLogEntry("Promoted to "+GetNationDescByType(iNation)+" "+GetRankNameDirect(char, iNation, currank),"My dedication and faithful service for "+GetNationNameByType(iNation)+" have earned me the rank of "+GetRankNameDirect(char, iNation, currank)+".","Personal",true);
	}
	else
	{
		AddLandToCharacter(&char, Locations[FindLocation(gov.location)].island, iNation, curRank*LAND_PER_RANK); // KK
		if (!InTutDeck) WriteNewLogEntry("Promoted to "+GetNationDescByType(iNation)+" "+GetRankNameDirect(char, iNation, currank),"My dedication and faithful service for "+GetNationNameByType(iNation)+" have earned me the title of "+GetRankNameDirect(char, iNation, currank)+". The "+GetNationDescByType(iNation)+" governor "+gov.name+" "+gov.lastname+" awarded me with the title and "+curRank*LAND_PER_RANK+" acres of land.","Personal",true);
	}
	//UpdateTitle(&char);
	return curRank;
}

bool PromoteCanBe(ref char, int iNation)
{
	if(GetRank(char, iNation) >= sti(Nations[iNation].Ranks.Quantity)) return false;
	return true;
}
//finds land given to char by nation by the time char is this rank
int GetLandFromRank(int rank)
{
	int land = 0;
	for(int i = 1; i <= rank; i++) land += i*LAND_PER_RANK;
	return land;
}

//sets rank of char in service of iNation to newrank, and sets points to that rank
float SetRank(ref char, int iNation, int newrank)
{
	// PB: Rewritten to include ALL functionality here -->
	float points = 0.0;
	float pointsForRank = 0.0;
	string sNation = iNation;
	int OldRank = GetRank(char, iNation);
	char.nations.(sNation).Rank = newrank; // Set rank

	if(IsMainCharacter(char)) // PB: DON'T do this for other characters than the player!
	{
		points = GetRMRelation(char, iNation);
		if(IsInServiceOf(iNation)) // Already in the service
		{
			pointsForRank = RequiredNextRankDirect(newrank);
			if (newrank > OldRank && points < pointsForRank) points = pointsForRank; // Promoted
			if (newrank < OldRank && points > pointsForRank) points = pointsForRank; // Demoted
		}
		else // Joining the service
		{
			ReceiveLetterOfMarque(iNation);
			if(sti(char.reputation) >= REP_COMEBACKMIN && newrank > 0)
			{
				//UpdateTitle(&char);
				points = RequiredNextRankDirect(newrank);
			}
			string sLogTitle = "Joined Service of " + GetNationNameByType(iNation);
			string sLogEntry = "I received a Letter of Marque from " + GetNationNameByType(iNation) + ". Now I am in their service, I can legally sink and capture ships, which means prize money and potential promotions for me in the future.";
			WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
		}
		if(points < 0.0) points = 0.0;
		SetRMRelation(char, iNation, points);
		SetServedNation(iNation);	// Reaffirm your loyalties
		ResetForts(iNation); 		// Make all forts for this nation forget any past mistakes
	}
	// PB: Rewritten to include ALL functionality here <--
	return points;
}

//sets rank of char in service of iNation to newrank, and does not change points
void SetRankDirect(ref char, int iNation, int newrank)
{
	string sNation = iNation;
	char.nations.(sNation).Rank = newrank;
	//UpdateTitle(&char);
}

// KK -->
//sets some special title of char in service of iNation to newtitle (eg. "Doctor")
void SetRankTitle(ref char, string newtitle)
{
	char.Title = newtitle; // PB: Do this IN ADDITION to formal titles
}
// <-- KK

//sets old rank to oldrank
void SetOldRank(ref char, int iNation, int oldrank)
{
	string sNation = iNation;
// KK -->
	aref arTmp;
	makearef(arTmp, char.nations.(sNation));
	arTmp.OldRank = oldrank;
// <-- KK
}

//chooses best flag for char
int ChooseBestFlag(ref char)
{
	int bestnat = RMGetHighestRelation(&char); // 04-12-06 moved the code here to this function back in nations.c
	char.nation = bestnat;
	return bestnat;
}

//removes char from service of iNation: sets rank to 0, puts old rank in nation.OldRank, updates title, sets
//rmrelation to after_attack. If rep < min, confiscates land, sets RMrel to war, sets soldiers hostile, does
//not give char oldrank
bool LeaveService(ref char, int iNation, bool override)
{
	if(!IsMainCharacter(char))  return false;
	if(!IsInServiceOf(iNation)) return false;
	bool leavebad = false;
	if(sti(char.reputation) < REP_LEAVEMIN) leavebad = true;
	if(override) leavebad = true;
	string sNation = iNation;
	int curRank = GetRank(char, iNation);
	char.nations.(sNation).Rank = 0;
	char.nations.(sNation).OldRank = 0;
	if(curRank)
	{
		aref arTmp; // KK
		if(leavebad)
		{
			RemoveLandFromCharacterNation(&char, iNation); // KK
			curRank = 0;

			if (sti(GetAttribute(char, "knighted")) == iNation) // GR: if you have an honorific prefix from this nation, lose it
			{
				DeleteAttribute(char, "knighted");
				DeleteAttribute(char, "Title");
			}
		}
// KK -->
		makearef(arTmp, char.nations.(sNation));
		arTmp.OldRank = curRank;
// <-- KK
	}
	//UpdateTitle(&char);
	if(leavebad)
	{
		if(GetRMRelation(char, iNation) > REL_WAR) SetRMRelation(char, iNation, REL_WAR);
		//if(GetRMKills(&char, iNation) < RM_GROUP_MINKILLS) SetRMKills(&Char, iNation, RM_GROUP_MINKILLS);
		LAi_group_SetRelation(GetSoldiersGroup(iNation), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		//SetAllSoldierGroups(&char);
	}
	else {
		if(GetRMRelation(char, iNation) > REL_AFTERATTACK) SetRMRelation(char, iNation, REL_AFTERATTACK);
	}

	// Lost LoM
	string sLogTitle = "Left Service of " + GetNationNameByType(iNation);
	string sLogEntry = "This marks the end of my service for " + GetNationNameByType(iNation) + ". But at least I am free now to pursue other goals.";
	if(leavebad)
	{
		sLogEntry += " My leaving was on rather bad terms and left me with decidedly less friends than I had.";
		SetServedNation(PIRATE); // PB
	}
	WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
	LooseLetterOfMarque(iNation);

	DeleteAttribute(char, "professionalnavy"); // PB: No more navy
	DeleteAttribute(char, "isnotcaptain"); // LDH 16Apr09

	// PB: Reset Pirates -->
	if (iNation == PIRATE)
	{
		if (dialogRun)	AddDialogExitQuest("pirateend");
		else			Lai_QuestDelay("pirateend", 0.0);
	}
	// PB: Reset Pirates <--

	// PB: Reset Crew -->
	Characters[GetCharacterIndex("Crewmember_01")].model = "bocman";
	Characters[GetCharacterIndex("Crewmember_01")].headmodel = "h_bocman";
	Characters[GetCharacterIndex("Crewmember_02")].model = "black_corsair";
	Characters[GetCharacterIndex("Crewmember_02")].headmodel = "h_black_corsair";
	Characters[GetCharacterIndex("Crewmember_03")].model = "man5";
	Characters[GetCharacterIndex("Crewmember_03")].headmodel = "h_man5";
	Characters[GetCharacterIndex("Crewmember_04")].model = "man4";
	Characters[GetCharacterIndex("Crewmember_04")].headmodel = "h_man4";
	Characters[GetCharacterIndex("Crewmember_05")].model = "capitan";
	Characters[GetCharacterIndex("Crewmember_05")].headmodel = "h_capitan";
	Characters[GetCharacterIndex("Treas_Crewmember_1")].model = "Bocman";
	Characters[GetCharacterIndex("Treas_Crewmember_1")].headmodel = "h_Bocman";
	Characters[GetCharacterIndex("Treas_Crewmember_2")].model = "Sailor4";
	Characters[GetCharacterIndex("Treas_Crewmember_2")].headmodel = "h_Sailor4";
	Characters[GetCharacterIndex("Treas_Crewmember_3")].model = "Sailor5";
	Characters[GetCharacterIndex("Treas_Crewmember_3")].headmodel = "h_Sailor5";
	Characters[GetCharacterIndex("Treas_Crewmember_4")].model = "Sailor6";
	Characters[GetCharacterIndex("Treas_Crewmember_4")].headmodel = "h_Sailor6";
	Characters[GetCharacterIndex("Treas_Crewmember_5")].model = "Sailor7";
	Characters[GetCharacterIndex("Treas_Crewmember_5")].headmodel = "h_Sailor7";
	Characters[GetCharacterIndex("Treas_Crewmember_6")].model = "Pirtt7";
	Characters[GetCharacterIndex("Treas_Crewmember_6")].headmodel = "h_Pirtt7";
	Characters[GetCharacterIndex("Treas_Crewmember_7")].model = "Sailor1";
	Characters[GetCharacterIndex("Treas_Crewmember_7")].headmodel = "h_Sailor1";
	Characters[GetCharacterIndex("Treas_Crewmember_8")].model = "Bocman3";
	Characters[GetCharacterIndex("Treas_Crewmember_8")].headmodel = "h_Bocman3";
	Characters[GetCharacterIndex("Treas_Crewmember_9")].model = "Black_corsair";
	Characters[GetCharacterIndex("Treas_Crewmember_9")].headmodel = "h_Black_corsair";
	Characters[GetCharacterIndex("Treas_Crewmember_10")].model = "50evl2in";
	Characters[GetCharacterIndex("Treas_Crewmember_10")].headmodel = "h_50evl2in";
	DeleteAttribute(char, "boardingmodels");
	// PB: Reset Crew <--
	if(leavebad) return true;
	return false;
}


//returns points required for next rank of char in service of nation.
float RequiredNextRank(ref char, int iNation)
{
	float nextrank = makefloat(GetRank(char, iNation)) + 1.0 + NEXTRANK_ADD;
	nextrank *= NEXTRANK_COEFF;
	float retVal = pow(nextrank,NEXTRANK_POW);
	return retVal * NEXTRANK_SCALAR;
}

//returns points required for specified rank
float RequiredNextRankDirect(int rank)
{
	float nextrank = makefloat(rank) + NEXTRANK_ADD; // NK bugfix 04-09-08
	nextrank *= NEXTRANK_COEFF;
	float retVal = pow(nextrank,NEXTRANK_POW);
	return retVal * NEXTRANK_SCALAR;
}

//returns rank, based on points
int GetRankFromPoints(float points) // NK change to int func 04-09-16. Stupid typo.
{
	int rank = 0;
	for(rank = 0; rank <= MAX_RANK; rank++)
	{
		if(points < RequiredNextRankDirect(rank)) { break; }
	}
	return rank;
}

//returns fame. If iNation == -1, interprets this as getting fame for general purposes (i.e. crew)
float GetFame(ref pchar, int iNation)
{
	bool crew = (iNation == -1);
	int rank = sti(pchar.rank);
	int i;
	int PerkIron;
	int PerkChar;
	int PerkWC;
	int skillLead;
	int skillLuck;
	float nrank = 1.0;
	int numnat;
	if(crew)
	{
		PerkIron  = GetOfficersPerkUsing(pchar,"IronWill");
		//PerkChar  = GetOfficersPerkUsing(pchar,"Charisma"); //to be added, prereq iron will //Removed by Levis untill is't well done
		//PerkWC    = GetOfficersPerkUsing(pchar,"WitCharm"); //to be added, prereq charisma //Removed by Levis untill is't well done
		skillLead = GetShipSkill(pchar,SKILL_LEADERSHIP);
		skillLuck = GetShipSkill(pchar,SKILL_SNEAK);
		nrank = 0;
		numnat = 0;
		for(i = 0; i < NATIONS_QUANTITY; i++)
		{
			if(GetRank(pchar, i))
			{
				numnat++;
				nrank += makefloat(GetRank(pchar, i))/24.0;
			}
		}
		if(numnat>0) { nrank = (nrank / makefloat(numnat)) * sqrt(numnat); }
		else { nrank = 0; }
	}
	else
	{
		PerkIron  = CheckPerkForSingleCharacter(pchar,"IronWill");
		//PerkChar  = CheckPerkForSingleCharacter(pchar,"Charisma"); //to be added, prereq iron will //Removed by Levis untill is't well done
		//PerkWC    = CheckPerkForSingleCharacter(pchar,"WitCharm"); //to be added, prereq charisma //Removed by Levis untill is't well done
		skillLead = CalcCharacterSkill(pchar,SKILL_LEADERSHIP);
		skillLuck = CalcCharacterSkill(pchar,SKILL_SNEAK);
		if(iNation == PIRATE) // new code 04-09-06, so if querying pirate fame you get extra for having ranks.
		{
			for(i = 0; i < NATIONS_QUANTITY; i++)
			{
				if(GetRank(pchar, i))
				{
					numnat++;
					nrank += makefloat(GetRank(pchar, i))/24.0;
				}
			}
			if(numnat>0) { nrank = (nrank / makefloat(numnat)) * sqrt(numnat); }
			else { nrank = 0; }
		}
		else
		{
			nrank = makefloat(GetRank(pchar, iNation))/12.0;
		}
	}

	float lastcsr = 1.0;
	if(CheckAttribute(pchar,"Crewstatus.lastcsr")) lastcsr = stf(pchar.CrewStatus.lastcsr);
	else pchar.CrewStatus.lastcsr = lastcsr;
	//unclamp lastcsr
	if(lastcsr > 1.0) lastcsr = 1.0/(2.0-lastcsr);
	//mult csr
	if(lastcsr > 1) lastcsr = 1.0 + (lastcsr-1.0) * FAME_CSR_SCALE;
	//else lastcsr = 1 - ((1 - lastcsr) * FAME_CSR_SCALE);

	//clamp csr to min/max
	if(lastcsr < FAME_CSR_MIN) lastcsr = FAME_CSR_MIN;
	if(lastcsr > FAME_CSR_MAX) lastcsr = FAME_CSR_MAX;

	int gold = GetCharacterWealth(pchar);
	int land = GetCharacterLand(pchar);

	float perkscale = 0.0;
	if(PerkIron)
	{
		perkscale = 0.25;
		 //Removed by Levis until it's well done
		/*if(PerkChar)
		{
			perkscale = 0.5;
			if(PerkWC) { perkscale = 1.0; }
		}*/
	}

	float points = 1.0;
	//calc points; 200 good for lvl10 char with 5/5, 300k gp, 1k acres
	points *= (1.0 + skillLead/10.0 + rand(skillLuck)/20.0 + perkscale);
	points *= sqrt(rank)/2.0;
	points *= (1.0 + nrank);
	points *= (sqrt(makefloat(gold))/20.0 + floatret(!crew,3.0*sqrt(pow(land/100.0,1.25)),0));
	if(crew) points *= lastcsr;
	if(iNation == PIRATE) { points *= (FAME_PIRNATION_CSR_BASE+ lastcsr * FAME_PIRNATION_CSR_SCALAR); } // NK 04-09-06 so if querying fame with nation pirate, csr counts.
	points *= FAME_SCALAR;
	if(crew) points = 0.1 + sqrt(sqrt(pow(points,1.5))) / 10.0;
	string fame_name = "extra_fame" + iNation
	if (CheckAttribute(pchar, fame_name)) points += (stf(pchar.(fame_name))*FAME_SCALAR); // PB: Add extra fame for quest purposes
	return points;
}

//returns character's score - this determines your "Known as" on the relations screen, for example "Famous Pirate"
float GetScore(ref char)
{
	int i;
	float score = 0;
	for(i = 0; i < NATIONS_QUANTITY; i++) score += GetFame(char, i);
	score /= NATIONS_QUANTITY;
	score = sqrt(score)*10; // - (6 + sti(char.rank)*2); calc performed later
	if(CheckAttribute(char,"married"))
	{
		if(sti(char.married))
		{
			score += MRGetMarPoints(CharacterFromID(char.married.id)) + MRGetTalkPoints(CharacterFromID(char.married.id));
		}
	}
	if(CheckAttribute(char,"Mistress"))
	{
		aref mist;
		ref cmist;
		makearef(mist,char.mistress);
		if(GetAttributesNum(mist))
		{
			for(i = 0; i < GetAttributesNum(mist); i++)
			{
				cmist = CharacterFromID(GetAttributeName(GetAttributeN(mist, i)));
				score += MR_MIST_FAME_SCL * (MRGetMarPoints(cmist) + MRGetTalkPoints(cmist));
			}
		}
	}
	score *= (0.5 + makefloat(GetDifficulty())/6.0);
	float atcsr = 1.0;
	if(CheckAttribute(char,"Crewstatus.alltimecsr")) { atcsr = stf(char.Crewstatus.alltimecsr); }
	else { char.Crewstatus.alltimecsr = atcsr; }
	//clamp csr to max 1.5 (it was already clamped at 2)
	if(atcsr > 1.0) atcsr = 1.0 + (atcsr-1.0) / 2.0;
	score *= atcsr;
	score = score - (6.0 + stf(char.rank)*2);
	if(score<1.0) score = 1.0;
	return score;
}

// start Marr. relations

/*New Property: gov.MR (marriageable relations; for governors).
MR.quantity = number of relations for that gov
add property MR.(i) (where i is the number of the Marriageable Relation, as above) = that relation's char id

that relation has property
char.relationtype = niece or daughter.
char.father = gov id.
char.relnum = relation number.
char.reqpoints = required points for that relation to be available.
char.marpoints  = required points to marry (see below)
char.talkpoints = points based on num times talked to; incremented in char's dialog.*/

/* old functions; maybe I'll use them instead of SetupMR some day...
int GetMRIndex(ref gov, int iRelnum)
{
	string relnum = iRelnum;
	if(!CheckAttribute(gov,"MR."+relnum)) return -1;
	else return GetCharacterIndex(gov.MR.(relnum));
}


ref GetMR(ref gov, int iRelnum)
{
	string relnum = iRelnum;
	return CharacterFromID(gov.MR.(relnum));
}


//returns object of all available relations. For use in gov dialog, to make them appear.
//note: for now, fixed to getGovR*2 + RMRel/2, && getgr >= 0
object FindAvailMR(ref char, ref gov)
{
	object MRs;
	int i, size;
	string ta;
	size = 0;
	MRs.quantity = size;
	if(!CheckAttribute(gov,"MR.quantity")) return MRs;
	if(sti(gov.MR.quantity) == 0) return MRs;
	if(GetGovRelation(char, gov) <= 0) return MRs;
	int MRqty = sti(gov.MR.quantity);
	for(i = 0; i < MRqty; i++)
	{
		if(GetGovRelation(char, gov)*2.0 + GetRMRelation(char, sti(gov.nation))/2.0 >= stf(Characters[GetMRIndex(gov, i)].reqpoints))
		{
			size++;
			ta = i;
			MRs.quantity = size;
			MRs.(ta) = gov.MR.("MR"+i);
		}
	}
	return MRs;
}
*/

float MRGetMarpoints(ref mchar)
{
	return stf(mchar.marpoints);
}

float MRGetTalkpoints(ref mchar)
{
	return stf(mchar.talkpoints);
}

float MRCalcMarpoints(ref pchar, int iNation)
{
	float mp = GetFame(pchar, iNation);
	mp *= MR_MPCOEFF;
	if(MR_MPPOW < 1.0) //because POTC does NOT support exponents of less than 1, strangely...
	{
		if(MR_MPPOW > 0.5) { mp = sqrt(pow(mp,MR_MPPOW*2)); }
		else { mp = sqrt(sqrt(pow(mp,MR_MPPOW*4))); } // so pow must be >= 0.25!
	}
	else {mp = pow(mp, MR_MPPOW); }
	mp *= MR_MPSCALAR;
	mp += MR_MPOFFSET;
	mp *= (MR_MPBASESCALE + frnd()*MR_MPRANDSCALE);
	if(mp< MR_MPMIN) mp = MR_MPMIN;
	return mp;
}

int MRGetWifeIndex() { return GetCharacterIndex(Characters[GetMainCharacterIndex()].married.id); };

ref MRGetWife() {return GetCharacter(MRGetWifeIndex()); }


// find if char can marry mchar. Based on fame with mchar's nation, and points from
// previous chats. prop is for if this is a proposal, or if just talking (check to
// make informant.)
bool MRCanMarry(ref char, ref mchar, bool prop)
{
	return (MRCanMarryRatio(&char, &mchar, prop) >= 1.0);
}


float MRCanMarryRatio(ref char, ref mchar, bool prop)
{
	//init vars
	prop = !prop;
	float marpoints = stf(mchar.marpoints) * (1.0 + makefloat(prop)*MR_NONPROP_SCALAR);
	float current = GetFame(&char, sti(mchar.nation));
	if(CheckAttribute(mchar,"talkpoints")) current += stf(mchar.talkpoints);

	return  current / marpoints;
}

float MRGetAddTalkpoints(ref char, ref mchar)
{
	float skillLead = CalcCharacterSkill(char,SKILL_LEADERSHIP);
	int skillLuck = CalcCharacterSkill(char,SKILL_SNEAK);
	bool PerkIron = CheckPerkForSingleCharacter(char,"IronWill");
	bool PerkChar = 0; //CheckPerkForSingleCharacter(char,"Charisma"); //to be added, prereq iron will //Removed by Levis until it's well done
	bool PerkWC = 0; //CheckPerkForSingleCharacter(char,"WitCharm"); //to be added, prereq charisma    //Removed by Levis until it's well done
	return MRTALKPOINTS_SCALAR*(skillLead/5.0 * floatRet(PerkIron, floatRet(PerkChar, floatRet(PerkWC, 2.0, 1.5), 1.25), 1.0) + makefloat(rand(skillLuck))/10.0);
}

float MRAddTalkpoints(ref char, ref mchar)
{
	float curpoints = 0;
	if(CheckAttribute(mchar,"talkpoints")) curpoints = stf(mchar.talkpoints);

	curpoints += MRGetAddTalkpoints(&char, &mchar);
	mchar.talkpoints = curpoints;
	return curpoints;
}

// end Marr. relations


//find if merch will allow char to trade, based on char's RMRel with merch's
//nation, and char's rep.
bool TradeCheck(ref char, ref merch, bool first)
{
	if (LAi_IsCapturedLocation) return true; // KK
	int pNation = sti(char.nation);
	int mNation = sti(merch.nation);
	int rep = sti(char.reputation);
	float rel = 0.0;
	// PURSEON -->
	if(first || !CheckAttribute(merch, "traderelation"))
	{
		rel = GetRMRelation(GetMainCharacter(), mNation);
		if(GetNationRelation(pNation, mNation) < RELATION_ENEMY && pNation != PERSONAL_NATION)		// your flag is NOT hostile to the merchant
		{
			if(rel <= REL_AFTERATTACK)																// but you are flying a false flag!
			{
				if (frnd() < GetChanceDetectFalseFlag() || CheckAttribute(merch,"FalseFlagDetect"))	// checks if the merchant will believe you
				{
					merch.FalseFlagDetect = true;													// you have been caught and the merchant won't be so trusting next time
				}
				else
				{
					rel = RelationToRMRelation(GetNationRelation(pNation, mNation))					// believes your false flag
				}
			}
			else
			{
				DeleteAttribute(merch, "FalseFlagDetect");											// you are actually friendly
			}
		}
		else
		{
			if(rel <= REL_WAR)																		// are you at war or not?
			{
				merch.FalseFlagDetect = true;														// merchant KNOWS you are an enemy and remembers this
			}
			else
			{
				DeleteAttribute(merch, "FalseFlagDetect");											// you are actually friendly
			}
		}
		merch.traderelation = rel;
	}
	else
	{
		rel = sti(merch.traderelation); // PB: Use the SAME relation for the WHOLE dialog
	}
	// <--PURSEON
	//find loc
	bool strengthcomp;
	int locIdx = FindLoadedLocation();
	if(locIdx<0) return true;
	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return true;

	// PB: Recoded Checks -->

	// -- Town fight strength vs. squadron fight strength --

	// Store/shipyard owner can be intimidated if player has three times more crew than the town has troops
	int ttroops = GetTownNumTroops(Locations[locIdx].townsack);
	int ptroops = GetSquadronCrewQuantity(char);

	if(ptroops > ttroops * 3) strengthcomp = true;

	// -- Actual Checks --

	if(mNation == PIRATE)
	{
		// Pirates don't do business with the navy
		if(ProfessionalNavyNation() == UNKNOWN_NATION)
		{
			// If you aren't hostile with the pirates, they'll always accept you
			if(rel  >  REL_WAR)													return true;
			// If you have no loyalties to any one nation, they'll accept you too
			if(GetLetterOfMarqueQuantity() == 0)								return true;
		}
	}
	else
	{
		// If you are Hostile with their nation, but you are a Hero
		if(rel <=  REL_WAR         && rep >= TRADEREP_ALL                     )	return true;

		// If you are less than Neutral to their nation, but you are a Horror of the High Seas
		if(rel <  REL_NEUTRAL         && rep <= TRADEREP_MIN                  )	return true;

		// If their nation is less than Hostile to you and you are Matey or better
		if(rel  >  REL_WAR         && rep >= TRADEREP_WAR                     )	return true;

		// If their nation is better than Wary and you are Neutral or better
		if(rel  >= REL_AFTERATTACK && rep >= TRADEREP_NEUTRAL                 )	return true;

		// If their nation is Friendly then they'll trade with you regardless of reputation
		if(rel >= REL_NEUTRAL                                                 ) return true;

		// If their nation is better than Neutral, you are Swindler or better and can intimidate them
		if(rel  >= REL_AMNESTY     && rep >= TRADEREP_STRENGTH && strengthcomp)	return true;

		// You have a Letter of Marque with the nation and have been promoted at least once
		if(GetRank(GetMainCharacter(), mNation) > 0                           )	return true;

		// You are friendly to the pirates, flying a pirate flag and the town is tolerant of pirates
		if(CheckForPirateException(merch)                                     )	return true;
	}

	// PB: Recoded Checks <--

//MAXIMUS -[we are here already, why we can't complete our mission?]->
	if(first && CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
	{
		if(char.quest.generate_trade_quest_progress.iTradeColony == GetCurrentTownID()) return true;
	}
//MAXIMUS <-[we are here already, why we can't complete our mission?]-
	return false;
}

void SetBaseShipData(ref refCharacter)
{
	int  i;
	aref refShip;
	int  nShipType;
	ref  refBaseShip;

	if (!TestRef(refCharacter)) return;
	if(CheckAttribute(refCharacter,"Ship"))
	{
		makearef(refShip,refCharacter.Ship);

		nShipType = GetCharacterShipType(refCharacter);
		if(nShipType==SHIP_NOTUSED) return;
		if(!CheckAttribute(refShip,"stats")) {
//KB - Tuning ships - changed call to SetRandomStatsToShip
			SetRandomStatsToShip(GetCharacterIndex(refCharacter.id), nShipType, sti(refCharacter.nation)); // PRS3
//KB - orig SetRandomStatsToShip(refShip, nShipType, sti(refCharacter.nation)); // PRS3
		}
		refBaseShip = GetShipByType(nShipType);

		refShip.HP = GetLocalShipAttrib(refShip, refBaseShip, "HP");
		refShip.SP = GetLocalShipAttrib(refShip, refBaseShip, "SP");

		if (nShipType != SHIP_FORT) // PB: Don't overwrite this for forts
		{
			refShip.Pos.x = 0;
			refShip.Pos.z = 0;
		}
		refShip.Ang = "";
		refShip.Cannons.Borts = "";
		if (USE_REAL_CANNONS)
			refShip.Cannons.Charge.Type = GOOD_BALLS; // KNB
		else
			refShip.Cannons.Charge.Type = GOOD_BOMBS;
		if(!CheckAttribute(refShip,"Cannons.Type")) { refShip.Cannons.Type = MakeInt(GetLocalShipAttrib(refShip, refBaseShip, "Cannon")); }

		if(!CheckAttribute(refShip,"Crew.Morale"))	{ refShip.Crew.Morale = 45;	}
		if(!CheckAttribute(refShip,"Crew.Quantity")) { refShip.Crew.Quantity = GetLocalShipAttrib(refShip, refBaseShip, "MaxCrew"); }
	// TIH --> code cleanup, and missing bracket fix 7-7-06
		string goodsName;
		if(GetCargoLoad(refCharacter)<=0)
		{
			refCharacter.Ship.Cargo.Load = 0;
			for(i=0; i<GOODS_QUANTITY; i++)
			{
				goodsName = Goods[i].Name;
				refCharacter.Ship.Cargo.Goods.(goodsName) = 0;
			}

			// TIH --> ships need food and rum if mod is on Aug31'06
			if (FOOD_ON) {
				int goodSum = 0;
				i = GetCharacterFreeSpace(refCharacter,GOOD_WHEAT);
				if(i>0) 
				{ 
					goodSum = makeint(2 + sti(refCharacter.ship.crew.quantity) * FOOD_PER_CREW * WHEAT_DAYS);// at least 2 wheat
					if(i>=goodSum)	{ SetCharacterGoods(refCharacter,GOOD_WHEAT,goodSum); }
					else  			{ SetCharacterGoods(refCharacter,GOOD_WHEAT,makeint(i/2)); }
				}
				i = GetCharacterFreeSpace(refCharacter,GOOD_RUM);
				if(i>0) 
				{ 
					goodSum = makeint(2 + sti(refCharacter.ship.crew.quantity) * FOOD_PER_CREW * RUM_DAYS);// at least 2 rum
					if(i>=goodSum)	{ SetCharacterGoods(refCharacter,GOOD_RUM,goodSum); }
					else  			{ SetCharacterGoods(refCharacter,GOOD_RUM,i); }
				}
			}
			// TIH <--

			// cannonballs
			i = GetCharacterFreeSpace(refCharacter,GOOD_BALLS);
			if(i>0)
			{
				if(i>=DEFAULT_NUM_BALLS) 	{ SetCharacterGoods(refCharacter,GOOD_BALLS,DEFAULT_NUM_BALLS); }
				else 						{ SetCharacterGoods(refCharacter,GOOD_BALLS,i); }
			}

			// grapes
			i = GetCharacterFreeSpace(refCharacter,GOOD_GRAPES);
			if(i>0)
			{
				if(i>=DEFAULT_NUM_GRAPE) 	{ SetCharacterGoods(refCharacter,GOOD_GRAPES,DEFAULT_NUM_GRAPE); }
				else 						{ SetCharacterGoods(refCharacter,GOOD_GRAPES,i); }
			}

			// knippels
			i = GetCharacterFreeSpace(refCharacter,GOOD_KNIPPELS);
			if(i>0)
			{
				if(i>=DEFAULT_NUM_KNIPPELS) { SetCharacterGoods(refCharacter,GOOD_KNIPPELS,DEFAULT_NUM_KNIPPELS); }
				else 						{ SetCharacterGoods(refCharacter,GOOD_KNIPPELS,i); }
			}

			// bombs // fixed 05-04-09 NK to use DEFAULT in the cargocheck too, and KNB no bombs. // TIH added mod toggle 7-7-06
			if (!USE_REAL_CANNONS)
			{
				i = GetCharacterFreeSpace(refCharacter,GOOD_BOMBS);
				if(i>0)
				{
					if(i>=DEFAULT_NUM_BOMBS) 	{ SetCharacterGoods(refCharacter,GOOD_BOMBS,DEFAULT_NUM_BOMBS); }
					else 						{ SetCharacterGoods(refCharacter,GOOD_BOMBS,i); }
				}
			}

			// added by MAXIMUS [gunpowder mod] -->
			// gunpowder
			if (CANNONPOWDER_MOD) // TIH --> mod toggle 7-7-06
			{
				i = GetCharacterFreeSpace(refCharacter,GOOD_GUNPOWDER);
				if(i>0)
				{
					ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(refCharacter)]);
					int basePwdr = 0;
					if(CheckAttribute(rCannon,"gunpowder")) basePwdr = makeint(sti(rCannon.gunpowder) * sti(GetCannonCurQuantity(refCharacter)));
					float averageQty = 0.0;
					if (USE_REAL_CANNONS) 	{ averageQty = makefloat(GetCargoGoods(refCharacter,GOOD_BALLS) + GetCargoGoods(refCharacter,GOOD_GRAPES) + GetCargoGoods(refCharacter,GOOD_KNIPPELS))/3; }
					else 					{ averageQty = makefloat(GetCargoGoods(refCharacter,GOOD_BALLS) + GetCargoGoods(refCharacter,GOOD_GRAPES) + GetCargoGoods(refCharacter,GOOD_KNIPPELS) + GetCargoGoods(refCharacter,GOOD_BOMBS))/4; }
					float canCharge = 0;
					if(sti(GetCannonCurQuantity(refCharacter))>0) canCharge = makefloat(averageQty/makefloat(GetCannonCurQuantity(refCharacter)));
					int loadPwdr = makeint(makefloat(basePwdr * canCharge)) + makeint(sti(refCharacter.ship.crew.quantity)*3);
					if(i>=loadPwdr) {
						SetCharacterGoods(refCharacter, GOOD_GUNPOWDER, loadPwdr);
					} else {
						SetCharacterGoods(refCharacter, GOOD_GUNPOWDER, i);
					}
				}
			}
			// TIH <-- mod toggle
			// added by MAXIMUS [gunpowder mod] <--
		}
	// TIH <-- code cleanup
	}
}

void SetBaseFellows(object refCharacter)
{
	aref tmpRef;

	makearef(tmpRef,refCharacter.Fellows.Companions);
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;

	makearef(tmpRef,refCharacter.Fellows.Passengers);
	tmpRef.Quantity = 0;
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;
	tmpRef.id4 = -1;
	tmpRef.id5 = -1;
	tmpRef.id6 = -1;
	tmpRef.id7 = -1;
	tmpRef.id8 = -1;

	makearef(tmpRef,refCharacter.Fellows.Passengers.Officers);
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;
}

// statistics utilite
void DoShipKilledStatistics(int killerCharacterIdx,int deadCharacterIdx)
{
	ref killer = GetCharacter(killerCharacterIdx);
	ref dead = GetCharacter(deadCharacterIdx);

	string attrName = Nations[sti(dead.nation)].Name;
	int oldValue = GetNationShipKilled(killer,attrName);
	killer.Statistics.KilledShip.Nation.(attrName) = oldValue+1;

	oldValue = GetClassShipKilled(GetCharacterShipClass(dead));
	attrName = "" + GetCharacterShipClass(dead);
	killer.Statistics.KilledShip.Class.(attrName) = oldValue+1;
}

void DoShipCaptureStatistics(int killerCharacterIdx,int captiveCharacterIdx)
{
	ref killer = GetCharacter(killerCharacterIdx);
	ref captive = GetCharacter(captiveCharacterIdx);

	string attrName = Nations[sti(captive.nation)].Name;
	int oldValue = GetNationShipCaptured(killer,attrName);
	killer.Statistics.CapturedShip.Nation.(attrName) = oldValue+1;

	oldValue = GetClassShipCaptured(killer,GetCharacterShipClass(captive));
	attrName = "" + GetCharacterShipClass(captive);
	killer.Statistics.CapturedShip.Class.(attrName) = oldValue+1;
}

int GetNationShipKilled(ref _refCharacter,string nation)
{
	if( CheckAttribute(_refCharacter,"Statistics.KilledShip.Nation." + nation) )
		return sti(_refCharacter.Statistics.KilledShip.Nation.(nation));
	return 0;
}
int GetClassShipKilled(ref _refCharacter,int classNum)
{
	string className = "" + classNum;
	if( CheckAttribute(_refCharacter,"Statistics.KilledShip.Class." + classNum) )
		return sti(_refCharacter.Statistics.KilledShip.Class.(className));
	return 0;
}

int GetNationShipCaptured(ref _refCharacter,string nation)
{
	if( CheckAttribute(_refCharacter,"Statistics.CapturedShip.Nation." + nation) )
		return sti(_refCharacter.Statistics.CapturedShip.Nation.(nation));
	return 0;
}
int GetClassShipCaptured(ref _refCharacter,int classNum)
{
	string className = "" + classNum;
	if( CheckAttribute(_refCharacter,"Statistics.CapturedShip.Class." + classNum) )
		return sti(_refCharacter.Statistics.CapturedShip.Class.(className));
	return 0;
}

// Items Utilite
int GetChrItemQuantity(ref _refCharacter)
{
	aref ar; makearef(ar,_refCharacter.items);
	return GetAttributesNum(ar);
}
bool GiveItem2Character(ref _refCharacter,string itemName)
{
	return TakeNItems(_refCharacter,itemName,1);
}
void TakeItemFromCharacter(ref _refCharacter,string itemName)
{
	TakeNItems(_refCharacter,itemName,-1);
}
bool CheckCharacterItem(ref _refCharacter,string itemName)
{
	if( CheckAttribute(_refCharacter,"Items."+itemName) && sti(_refCharacter.Items.(itemName))>0 )	return true;
	else	return false;
}
int GetCharacterItem(ref _refCharacter,string itemName)
{
	if(CheckAttribute(_refCharacter,"Items."+itemName))
	{
		return sti(_refCharacter.Items.(itemName));
	}
	return 0;
}
bool ReplaceItem(ref _refTakingCharacter,ref _refGivingCharacter,string itemName)
{
	bool retVal = CheckCharacterItem(_refGivingCharacter,itemName);
	if( TakeNItems(_refTakingCharacter,itemName,1) )
		TakeNItems(_refGivingCharacter,itemName,-1);
	return retVal;
}
bool TakeNItems(ref _refCharacter,string itemName, int n)
{
	if(itemName == "") return false;
	int q;
	aref arItm;
	if( Items_FindItem(itemName,&arItm)<0 )
	{
		trace("WARNING!!! Item id = "+itemName+" not implemented");

		// LDH - because I'm damned tired of fixing individual instances of these problems when mods are turned off - 31Mar09
		if ( ! ENABLE_AMMOMOD )
			if (HasSubStr(itemName, "powder") || HasSubStr(itemName, "bullet"))
				return false;

		int rc = -1;
		if ( ! ENABLE_WEAPONSMOD ) {
			string strTemp = GetSymbol(itemName, strLen(itemName)-1);
			if (strTemp == "+" || strTemp == "-")
			{
				itemName = strLeft(itemName, strLen(itemName)-2);
				rc = Items_FindItem(itemName,&arItm);
				if (rc < 0)
					trace("WARNING!!! Item id = "+itemName+" not implemented");
			}
		}

		if (rc < 0) 
		{
//			trace("WARNING!!! Item id = "+itemName+" not implemented");
			return false;
		}
		// LDH <--

//		return false;
	}
	else
	{
		if( CheckAttribute(arItm,"gold") )
		{
			if( CheckAttribute(_refCharacter,"Money") )	q = sti(_refCharacter.Money);
			else q = 0;
			q += n*sti(arItm.gold);
			if(q<0) {q=0;}
			_refCharacter.Money = q;
			return true;
		}
		if( CheckAttribute(arItm,"price") && sti(arItm.price)==0 )
		{
			//if(sti(_refCharacter.index)==GetMainCharacterIndex() && IsEntity(_refCharacter))
			if(IsMainCharacter(_refCharacter))		//JRH to get rid of errorlog messages
			{
				//JRH -->
				if(itemName == "pistol201" || itemName == "pistol202" || itemName == "pistol203"
					|| itemName == "pistol204" || itemName == "pistol205" || itemName == "pistol206"
					|| itemName == "pistolbelt")
				{
					if(n>0)	{Log_SetStringToLog(XI_ConvertString("You take item"));
					PlayStereoSound("interface\important_item.wav");}
				}
				//<-- JRH
				else
				{
					if(n>0)
					{
						//JRH -->
						if(CheckAttribute(_refCharacter,"quest.take_items_log") )
						{
							if(_refCharacter.quest.take_items_log == "6") Log_SetStringToLog(XI_ConvertString("You take 6 items"));
							if(_refCharacter.quest.take_items_log == "3") Log_SetStringToLog(XI_ConvertString("You take 3 items"));
							if(_refCharacter.quest.take_items_log == "2") Log_SetStringToLog(XI_ConvertString("You take 2 items"));
						}
						//<-- JRH
						else Log_SetStringToLog(XI_ConvertString("You take item"));
					}
					if(n<0)	{Log_SetStringToLog(XI_ConvertString("You give item"));}
					PlayStereoSound("interface\important_item.wav");
				}
			}
			if( n>0 && IsOfficer(_refCharacter) || IsCompanion(_refCharacter) ) {
				AddMsgToCharacter(_refCharacter,MSGICON_GETITEM);
			}
		}
		
		UpdateSkillModifierFromItem(_refCharacter, itemName); // PB: Update only relevant skill modifiers
		
		q = GetCharacterItem(_refCharacter,itemName);
		if (q + n <= 0) {
			DeleteAttribute(_refCharacter,"Items."+itemName);
			if (WEIGHTMOD) SetCharacterCapacity(_refCharacter, GetCharacterCapacity(_refCharacter) - (q * GetItemWeightByID(itemName)));
		} else {
			if (q <= 0 && GetChrItemQuantity(_refCharacter) >= MAX_ITEM_TAKE) return false;
			_refCharacter.Items.(itemName) = q + n;
			if (WEIGHTMOD) SetCharacterCapacity(_refCharacter, GetCharacterCapacity(_refCharacter) + (n * GetItemWeightByID(itemName)));
		}
		return true;
	}
	return false;
}

void UpdateSkillModifierFromItem(ref _refCharacter, string itemName)
{
	aref arItm;
	Items_FindItem(itemName,&arItm);
	if(CheckAttribute(arItm, "skill"))
	{
		for(int sn = 0; sn < 10; sn++)
		{
			string skillName = GetSkillName(sn);
			if (CheckAttribute(arItm, "skill." + skillName))
			{
				ResetSkillModifier(_refCharacter, skillName);
			}
		}
	}
}

// KK -->
int FindCharacterMap(ref _refCharacter, int number)
{
	if (number <= 0) return -1;
	if (!CheckAttribute(_refCharacter, "Items")) return -1;
	aref curItem,arItem;
	aref rootItems; makearef(rootItems, _refCharacter.Items);
	int num = GetAttributesNum(rootItems);
	int n = 0;
	for (int i = 0; i < num; i++) {
		curItem = GetAttributeN(rootItems, i);
		if (Items_FindItem(GetAttributeName(curItem), &arItem) >= 0) {
			if (CheckAttribute(arItem, "groupID")) {
				if (arItem.groupID == MAP_ITEM_TYPE) n++;
				if (n == number) return sti(arItem.index);
			}
		}
	}
	return -1;
}
// <-- KK

//Contraband functions moved to smuggling.c

int GetCharacterCurrentIsland(ref _refCharacter)
{
// KK -->
	/*int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return -1;
	return GetIslandIdxByLocationIdx(curLocNum);*/
	// PB: Make this work for companion ships while ashore too -->
	string curLoc = "";
	if (CheckAttribute(_refCharacter, "location.from_sea"))				curLoc = _refCharacter.location.from_sea;
	if (curLoc == "" && CheckAttribute(_refCharacter, "location"))		curLoc = _refCharacter.location;
	// PB: Make this work for companion ships while ashore too <--
	int locidx = FindLocation(curLoc);

	if (GetIslandIdxByLocationIdx(locidx) < 0 && IsCompanion(_refCharacter))	// GR: if we can't work out a companion's island, it's probably the same as yours
	{
		locidx = FindLocation(Characters[GetMainCharacterIndex()].location);
	}
	if (locidx < 0) return -1;
	return GetIslandIdxByLocationIdx(locidx);
// <-- KK
}

// NK new func for just IDs 05-03-28
string GetIslandIDByLocationID(string locid)
{
	int locIdx = FindLocation(locid);
	if(CheckAttribute(Locations[locIdx],"island")) { return Islands[FindIsland(Locations[locIdx].island)].id; } // NK bugfix 05-04-02
	/*aref rootar,ar;
	makearef(rootar,Locations[0].IslandsList);
	for(int i=0; i<GetAttributesNum(rootar); i++)
	{
		ar = GetAttributeN(rootar,i);
		if( locIdx>=sti(ar.begin) && locIdx<=sti(ar.end) )
		{
			return GetAttributeName(ar);
		}
	}*/
	return "";
}
// NK <--

int GetIslandIdxByLocationIdx(int locIdx)
{
	if(CheckAttribute(Locations[locIdx],"island")) { return FindIsland(Locations[locIdx].island); }
	aref rootar,ar;
	makearef(rootar,Locations[0].IslandsList);
	for(int i=0; i<GetAttributesNum(rootar); i++)
	{
		ar = GetAttributeN(rootar,i);
		if( locIdx>=sti(ar.begin) && locIdx<=sti(ar.end) )
		{
			return FindIsland(GetAttributeName(ar));
		}
	}
	return -1;
}

string GetIslandNameByLocationID(string locid)
{
	return FindIslandName(GetIslandIDByLocationID(locid));
}

int GetCharacterCurrentStore(ref _refCharacter)
{
	int i;
	int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return -1;
	if(CheckAttribute(&Locations[curLocNum],"townsack")) return GetTownStoreIndex(Locations[curLocNum].townsack); // NK 05-04-17 use towntable
	if( CheckAttribute(&Locations[curLocNum],"fastreload") )
	{
		string locGroupId = Locations[curLocNum].fastreload;
		for(i=0; i<STORE_QUANTITY; i++)
		{
			if(Stores[i].group==locGroupId)
			{
				return i;
			}
		}
	}
	else
	{
		curLocNum = GetIslandIdxByLocationIdx(curLocNum);
		if(curLocNum<0)	{return -1;}
		for(i=0; i<STORE_QUANTITY; i++)
		{
			if(stores[i].Island==Islands[curLocNum].id)
			{
				return i;
			}
		}
	}

	return  -1;
}

// NK 05-04-19 -->
// make single function for char-mod price. summ = use officers too.
float GetCharPriceMod(ref ch, int priceType, bool summ, bool bShipyard)
{
	float skillModify = 1.0;
	float skillDelta;
	if(summ) skillDelta = GetShipSkill  (&ch,SKILL_COMMERCE);
	else skillDelta = CalcCharacterSkill(&ch,SKILL_COMMERCE);
	if(priceType==PRICE_TYPE_BUY)
	{
		skillModify = 1.4 - skillDelta*0.019;
		if(CheckOfficersPerk(&ch,"AdvancedCommerce"))	{ skillModify -= 0.2; }
		else
		{
			if(CheckOfficersPerk(&ch,"BasicCommerce"))	{ skillModify -= 0.1; }
		}
	}
	else
	{
		bool bCheckSkills = true;
		if ( IsMainCharacter(ch) )
		{
		/*	if (IsInAnyService())  	// Levis: Professional Navy and LoM pay commission, but are not affected by skills
			{
				bCheckSkills = false;
				if (bShipyard)		skillModify = SHIPYARD_SHIP_SELL_MULT;															// skills don't affect shipyard transactions
				else				skillModify = makefloat(((SHIPYARD_PIRATEDSHIP_SELL_MULT+SHIPYARD_BOUGHTSHIP_SELL_MULT)/2));	// 50% commission
			}*/
//			if (!bShipyard && HasMerchantPassport(ch))	// PB: Honest merchants don't pay commission outside the shipyard
			if (!bShipyard && HasMerchantPassport(ch) && !IsInAnyService())	// GR: navy and privateers don't get the merchant trade benefit
			{
				bCheckSkills = false;
				skillModify  = 1.0;																									// skills don't affect store transactions
			}
		}
		if (bCheckSkills)
		{
			skillModify = 0.75 + skillDelta*0.019;
			if(CheckOfficersPerk(&ch,"AdvancedCommerce"))	skillModify += 0.05;
		}
	}
	return skillModify;
}
int GetCurrentIslandGoodsPrice(int GoodsType)
{
	int curStoreIdx = GetCharacterCurrentStore(GetMainCharacter());
	if(curStoreIdx<0) return 0;
	// NK to use global store's town aref. 05-04-15
	string tn = GetTownIDFromGroup(Stores[curStoreIdx].group);
	//if(tn != "") { rStoreTown = GetTownFromID(tn); }
	// NK <--
	return GetStoreGoodsPrice(&Stores[curStoreIdx],GoodsType,PRICE_TYPE_SELL,GetMainCharacter(), 0); // NK
}

int GetCurrentLocationNation()
{
	int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return UNKNOWN_NATION;
	return GetLocationNation(&Locations[curLocNum]);
}

void SetRandomNameToCharacter(ref rCharacter)
{
	// if (IsMainCharacter(rCharacter)) return;	// TIH random name on death fix 7-7-06 // KK
// MAXIMUS random name on death fix 24.11.2006 -->
	/*if(CheckAttribute(rCharacter,"old.name"))
	{
		if(rCharacter.old.name=="Malcolm")
		{
			if(CheckAttribute(rCharacter,"old.lastname"))
			{
				if(rCharacter.old.lastname=="Hatcher")
				{
					rCharacter.id = "Malcolm Hatcher";
					return;
				}
			}
		}
	}*/
	if (CheckAttribute(rCharacter, "questchar")) {
		if (CheckAttribute(rCharacter, "old.name")) rCharacter.name = rCharacter.old.name;
		if (CheckAttribute(rCharacter, "old.middlename")) rCharacter.middlename = rCharacter.old.middlename; // KK
		if (CheckAttribute(rCharacter, "old.nickname")) rCharacter.nickname = rCharacter.old.nickname; // KK
		if (CheckAttribute(rCharacter, "old.lastname")) rCharacter.lastname = rCharacter.old.lastname;
		return;
	}
// MAXIMUS random name on death fix 24.11.2006 <--

	int iNation = sti(rCharacter.nation);
	if (iNation == PERSONAL_NATION) iNation = PIRATE;
	string allNations = "0,1,2,4,5";// MAXIMUS
	if(iNation == PIRATE) iNation = sti(GetRandSubString(allNations));// MAXIMUS

	ref rNames, rLastNames;

	switch(iNation)
	{
		case ENGLAND:
			rNames = &sEnWomenNames;
			if(rCharacter.sex != "woman") rNames = &sEnManNames;
			rLastNames = &sEnFamilies;
		break;
		case FRANCE:
			rNames = &sFrWomenNames;
			if(rCharacter.sex != "woman") rNames = &sFrManNames;
			rLastNames = &sFrFamilies;
		break;
		case SPAIN:
			rNames = &sSpWomenNames;
			if(rCharacter.sex != "woman") rNames = &sSpManNames;
			rLastNames = &sSpFamilies;
		break;
		case HOLLAND:
			rNames = &sHoWomenNames;
			if(rCharacter.sex != "woman") rNames = &sHoManNames;
			rLastNames = &sHoFamilies;
		break;
		case PORTUGAL:
			rNames = &sPoWomenNames;
			if(rCharacter.sex != "woman") rNames = &sPoManNames;
			rLastNames = &sPoFamilies;
		break;
		case GUEST1_NATION:
			if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
				rNames = &sSwWomenNames;
				if(rCharacter.sex != "woman") rNames = &sSwManNames;
				rLastNames = &sSwFamilies;
			}
			else{
				rNames = &sAmWomenNames;
				if(rCharacter.sex != "woman") rNames = &sAmManNames;
				rLastNames = &sAmFamilies;
			}
		break;
		/*case AMERICA:
				rNames = &sAmWomenNames;
				if(rCharacter.sex != "woman") rNames = &sAmManNames;
				rLastNames = &sAmFamilies;
		break;*/
		/*case SWEDEN:
			if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
				rNames = &sSwWomenNames;
				if(rCharacter.sex != "woman") rNames = &sSwManNames;
				rLastNames = &sSwFamilies;
			}
		break;*/
		// KK default:
			rNames = &sEnWomenNames;
			if(rCharacter.sex != "woman") rNames = &sEnManNames;
			rLastNames = &sEnFamilies;
	}
	/*if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
		switch(iNation){
			case SWEDEN: 
				rNames = &sSwWomenNames;
				if(rCharacter.sex != "woman") rNames = &sSwManNames;
				rLastNames = &sSwFamilies;
			break;
		}
	}*/

	if (GetArraySize(rNames) >= 2) //Quiliooto Fix
	{
		rCharacter.nation.name = iNation;//MAXIMUS: used in GetCharacterAddressForm
		rCharacter.name = GetRandSubString(rNames[rand(GetArraySize(rNames) - 2)]);
// KK -->
		if (CheckAttribute(rCharacter, "middlename")) DeleteAttribute(rCharacter, "middlename");
		if (CheckAttribute(rCharacter, "old.middlename")) DeleteAttribute(rCharacter, "old.middlename");
// <-- KK
		rCharacter.lastname = GetRandSubString(rLastNames[rand(GetArraySize(rLastNames) - 2)]);
// KK -->
		if (!CheckAttribute(rCharacter, "old.name") || rCharacter.old.name == "") rCharacter.old.name = rCharacter.name;
		if (CheckAttribute(rCharacter, "middlename")) rCharacter.old.middlename = rCharacter.middlename;
		if (!CheckAttribute(rCharacter, "old.lastname") || rCharacter.old.lastname == "") rCharacter.old.lastname = rCharacter.lastname;
// <-- KK
	}
}

//=============================================================================
//  EQUIP SECTION
//=============================================================================

// NK rewrite this to not page through entire array. 05-05-11
// fixed 05-06-28 OOPS!
string FindCharacterItemByGroup(ref chref, string groupID)
{
	// TIH --> new method that uses the blade/guns sorted arrays Aug24'06
	if(!CheckAttribute(chref,"items")) return "";

	int i,n;
	int itmqual;
	int high = -1;
	string highid = "";
	string curId = "";

	aref chit; makearef(chit, chref.items);
	for(i = GetAttributesNum(chit)-1; i >= 0; i--)
	{
		aref refItm;
		curId = GetAttributeName(GetAttributeN(chit, i));
		n = Items_FindItem(curId,&refItm);// returns item index and fills aref refItm

		// check to see if this item is even something we can bother with selecting
		if ( n < 0 ) 								continue;// invalid item
		if ( !CheckAttribute(refItm,"id") ) 		continue;// no valid id
		if ( !CheckAttribute(refItm,"groupID") ) 	continue;// no valid groupid
		if ( refItm.groupID != groupID ) 			continue;// not what we are looking for, move along now
		if ( refItm.id == "telescope") 				continue;// PB: do not find this for auto-equipping!

		if ( groupID == GUN_ITEM_TYPE )// must check requisits on guns
		{
			if( !CheckAttribute(refItm,"chargeQ") ) { continue; }// invalid gun
			if( sti(refItm.chargeQ) >  1 && !IsCharacterPerkOn(chref,"Gunman") ) { continue; }// no requisite
			if( sti(refItm.chargeQ) >= 4 && !IsCharacterPerkOn(chref,"GunProfessional") ) { continue; }// no requisite
			if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
			{
				if( sti(refItm.chargeQ) >= 6 && !IsCharacterPerkOn(chref,"GunFighter") ) { continue; }//JRH BB6
			}
		}

		// now we compare by 'n', but using different arrays to do it
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
		// TIH --> bladedamage mod: we skip broken blades for all, and bad blades for mainchar Aug31'06
		// this only happens with blades, and only if the blade damage mod is enabled for the second check
		if (groupID == BLADE_ITEM_TYPE && BLADEDAMAGE_ENABLED)
		{
			itmqual = GetItemQualityByID(refItm.id);
			if (itmqual == 0) { continue; }
			if (itmqual == 1 && sti(chref.index) == GetMainCharacterIndex()) { continue; }
		}

		// TIH <--
		// now set the high to be used for further iterations
		high = n;
		highid = curId;
	}
	// if the high number was actually set to something, we return the highid set
	if(high > -1) return highid;
	return "";
	// TIH <--
	/* old method - doesn't use sorted arrays for guns and blades
	// DO NOT DELETE THIS COMMENTED CODE - left for tracking reasons
	int i,n;
	ref refItm;
	int high = -1;
	//for(i=ITEMS_QUANTITY-1; i>=0; i--)
	if(!CheckAttribute(chref,"items")) return "";
	aref chit; makearef(chit, chref.items);
	for(i = GetAttributesNum(chit)-1; i >= 0; i--)
	{
		aref curitmar = GetAttributeN(chit, i);
		string curitmid = GetAttributeName(curitmar);
		int oldhigh = high;
		n = GetItemIndex(curitmid);
		if(n <= high) continue;
		high = n;
		refItm = &Items[n];
		if( !CheckAttribute(refItm,"groupID") ) {high = oldhigh; continue; }
		if(refItm.groupID!=groupID) {high = oldhigh; continue; }
		// done above - if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(groupID==GUN_ITEM_TYPE)
		{
			if( !CheckAttribute(refItm,"chargeQ") ) {high = oldhigh; continue; }
			n = sti(refItm.chargeQ);
			//if(n<2) {return refItm.id;}
			//if(n<4)
			if(n>=4)
			{
				if( !IsCharacterPerkOn(chref,"GunProfessional") )
				{
					high = oldhigh;
					continue;
				}
			}
			else
			{
				if(n > 1)
				{
					if(!IsCharacterPerkOn(chref,"Gunman") )
					{
						high = oldhigh;
						continue;
					}
				}
			}
		}
	}
	if(high > -1) return Items[high].id;
	return "";
	*/
}

bool IsEquipCharacterByItem(ref chref, string itemID)
{
	aref arEquip;
	makearef(arEquip,chref.equip);
	int q = GetAttributesNum(arEquip);
	for(int i=0; i<q; i++)
	{	if(GetAttributeValue(GetAttributeN(arEquip,i))==itemID) return true;
	}
	return false;
}

string GetCharacterEquipByGroup(ref chref, string groupID)
{
	if( CheckAttribute(chref,"equip."+groupID) ) return chref.equip.(groupID);
	return "";
}

// PB -->
string CheckCharacterEquipByGroup(ref chref, string groupID)
{
	string item = GetCharacterEquipByGroup(chref,groupID);
	if(CheckCharacterItem(chref,item)) return item;
	return "";
}
// PB <--

void RemoveCharacterEquip(ref chref, string groupID)
{
	UpdateSkillModifierFromItem(chref, GetCharacterEquipByGroup(chref, groupID)); // PB: Update only relevant skill modifiers
	DeleteAttribute(chref,"equip."+groupID);
	SetEquipedItemToCharacter(chref,groupID,"");
}

void SetEquipedItemToCharacter(ref chref, string groupID, string itemID)
{
	//traceandlog("running seteq, grp " + groupID + ", item " + itemID + ", chref "+chref.id);
	object emptyItm;
	aref arItm;
	string modelName = "";
	makearef(arItm,emptyItm);
	if(itemID!="")
	{
		if( !CheckCharacterItem(chref,itemID) ) return;
		Items_FindItem(itemID,&arItm);
	}

	switch(groupID)
	{
		// GreatZen --> // KK -->
		case ARMOR_ITEM_TYPE:
			if (itemID == "")
			{
				// TIH -->
				if(CheckAttribute(chref, "chr_ai.coverage"))	chref.chr_ai.coverage = 0.0;
				if(CheckAttribute(chref, "chr_ai.bladestop"))	chref.chr_ai.bladestop = 0.0;
				if(CheckAttribute(chref, "chr_ai.bladefrac"))	chref.chr_ai.bladefrac = 1.0;
				if(CheckAttribute(chref, "chr_ai.gunstop"))		chref.chr_ai.gunstop = 0.0;
				if(CheckAttribute(chref, "chr_ai.gunfrac"))		chref.chr_ai.gunfrac = 1.0;
				if(CheckAttribute(chref, "model.armorlevel"))	// PB: Don't update the model if there is no need
				{
					DeleteAttribute(chref, "model.armorlevel");
					SetModel(chref, chref.model, chref.model.animation, chref.sex, stf(chref.model.height), FindLoadedLocation() != -1);
				}
			}
			else
			{
				if (CheckAttribute(arItm,"coverage"))
					chref.chr_ai.coverage = stf(arItm.coverage)/100.0;
				else
					chref.chr_ai.coverage = 0.0;

				if (CheckAttribute(arItm,"bladestop"))
					chref.chr_ai.bladestop = stf(arItm.bladestop)/100.0;
				else
					chref.chr_ai.bladestop = 0.0;

				if (CheckAttribute(arItm,"bladefrac"))
					chref.chr_ai.bladefrac = stf(arItm.bladefrac)/100.0;
				else
					chref.chr_ai.bladefrac = 1.0;

				if (CheckAttribute(arItm,"gunstop"))
					chref.chr_ai.gunstop = stf(arItm.gunstop)/100.0;
				else
					chref.chr_ai.gunstop = 0.0;

				if (CheckAttribute(arItm,"gunfrac"))
					chref.chr_ai.gunfrac = stf(arItm.gunfrac)/100.0;
				else
					chref.chr_ai.gunfrac = 1.0;

				// NK again
				if (CheckAttribute(arItm,"cmodel") && arItm.cmodel != "" && !checkAttribute(arItm, "modelitem")) { // PB: Skip armor items that deliberately have no model set
					//trace("starting changemodel check");
					string mdname = chref.model;
					int newarmorlevel = sti(arItm.cmodel);
					string modid;
					bool bmodelfound = false;
					int i;
					chref.model.armorlevel = newarmorlevel;
					for (i = newarmorlevel; i >= 0; i--) // find existing lower-quality armored model
					{
						modid = mdname + "_A" + i;
						if (FindFile("RESOURCE\MODELS\Characters", "*.gm", modid + ".gm") != "") {
							bmodelfound = true;
							break;
						}
					}
					if (!bmodelfound) {
						for(i = newarmorlevel+1; i <= 3; i++) // if no lower one, look for higher. There may eventually be more than 3 though.
						{
							modid = mdname + "_A" + i;
							if (FindFile("RESOURCE\MODELS\Characters", "*.gm", modid + ".gm") != "") {
								bmodelfound = true;
								break;
							}
						}
					}
					if (bmodelfound)
						SetModel(chref, chref.model, chref.model.animation, chref.sex, stf(chref.model.height), FindLoadedLocation() != -1);
					else
						DeleteAttribute(chref, "model.armorlevel"); // PB: Don't update the model if there is no need
				}
			}
		break;
		// GreatZen <-- // <-- KK
		case SPYGLASS_ITEM_TYPE:
			if(CheckAttribute(arItm,"id"))
				setTelescopeInitParameters(&Telescope,arItm);
		break;

		case GUN_ITEM_TYPE:
			if(CheckAttribute(arItm,"model"))	{modelName = arItm.model;}
			SendMessage(chref,"ls",MSG_CHARACTER_SETGUN,modelName);
			if(CheckAttribute(arItm,"chargeQ"))
				LAi_GunSetChargeQuant(chref,sti(arItm.chargeQ));
			else
				LAi_GunSetChargeQuant(chref,0);
			
			if(CheckAttribute(arItm,"chargespeed") && stf(arItm.chargespeed)>0.0)
				LAi_GunSetChargeSpeed(chref,1.0/stf(arItm.chargespeed));
			else
				LAi_GunSetChargeSpeed(chref,0.0);

			if(CheckAttribute(arItm,"dmg_min"))
				LAi_GunSetDamageMin(chref,stf(arItm.dmg_min));
			else
				LAi_GunSetDamageMin(chref,0.0);

			if(CheckAttribute(arItm,"dmg_max"))
				LAi_GunSetDamageMax(chref,stf(arItm.dmg_max));
			else
				LAi_GunSetDamageMax(chref,0.0);

			if(CheckAttribute(arItm,"accuracy"))
				LAi_GunSetAccuracy(chref,stf(arItm.accuracy)*0.01);
			else
				LAi_GunSetAccuracy(chref,0.0);

	//		if (IsMainCharacter(chref)) LAi_QuestDelay("pchar_hip_mode_check", 0.1);		//JRH: this doesn't work
		break;

		case BLADE_ITEM_TYPE:
			float liveTime = 0.1;
			int colors = argb(64, 64, 64, 64);
			int colore = argb(0, 32, 32, 32);
			if(CheckAttribute(arItm,"model"))	{modelName = arItm.model;}
			if(CheckAttribute(arItm, "blade.time"))	{liveTime = stf(arItm.blade.time);}
			if(CheckAttribute(arItm, "blade.colorstart"))	{colors = sti(arItm.blade.colorstart);}
			if(CheckAttribute(arItm, "blade.colorend"))	{colore = sti(arItm.blade.colorend);}
			SendMessage(chref, "lsfll", MSG_CHARACTER_SETBLADE, modelName, liveTime, colors, colore);

			if(CheckAttribute(arItm,"dmg_min"))
				LAi_BladeSetDamageMin(chref,stf(arItm.dmg_min));
			else
				LAi_BladeSetDamageMin(chref,0.0);

			if(CheckAttribute(arItm,"dmg_max"))
				LAi_BladeSetDamageMax(chref,stf(arItm.dmg_max));
			else
				LAi_BladeSetDamageMax(chref,0.0);

			if(CheckAttribute(arItm,"piercing"))
				LAi_BladeSetPiercing(chref,stf(arItm.piercing)*0.01);
			else
				LAi_BladeSetPiercing(chref,0.0);

			if(CheckAttribute(arItm,"block"))
				LAi_BladeSetBlock(chref,stf(arItm.block)*0.01);
			else
				LAi_BladeSetBlock(chref,0.0);
		break;
	}
}

void EquipCharacterByItem(ref chref, string itemID)
{
	aref arItm;

	if( !CheckCharacterItem(chref, itemID) ) return;
	//trace("has item");
	if( Items_FindItem(itemID, &arItm)<0 )	return;
	//trace("found item");
	if( !CheckAttribute(arItm, "groupID") ) return;
	//trace("has gid");

	string groupName = arItm.groupID;
	string oldItemID = GetCharacterEquipByGroup(chref, groupName);
	// for now just comment this. 05-07-06 - if(oldItemID==itemID && !CheckAttribute(chref,"armoroverride")) return; // NK bugfix to armor model switching. 05-07-06
	chref.equip.(groupName) = itemID;

	if(IsEntity(chref))
	{
		//trace("is entity");
		SetEquipedItemToCharacter(chref, groupName, itemID);
	}
	// ccc special weapons, so that distanceweapons are precharged if equiped
	// must be activated by setting PRECHARGE = 1 in buildsettings_2.h
	if(groupName==GUN_ITEM_TYPE && sti(chref.index)==GetMainCharacterIndex() && PRECHARGE != 1)
	{	LAi_GunSetUnload(chref);
	}

	UpdateSkillModifierFromItem(chref, oldItemID); // PB: Update only relevant skill modifiers
	UpdateSkillModifierFromItem(chref, itemID   ); // PB: Update only relevant skill modifiers

// added by MAXIMUS 21.07.2006 [weapon will not be charged without gunpowder or proper bullets][changed 24.11.2006] -->
	if(ENABLE_AMMOMOD==1)
	{
		if(GetCharacterIndex(chref.id)==GetMainCharacterIndex() || IsOfficer(chref)) //JRH fix oct 06: crewmembers
		{
			aref weapon;
			string weaponID = GetCharacterEquipByGroup(chref,GUN_ITEM_TYPE);
			Items_FindItem(weaponID, &weapon);
			if(CheckAttribute(weapon,"shottype"))
			{
				string ammoName;
				string ammoName2;					//JRH
				
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

				gp = GetCharacterItem(chref, "gunpowder");
 				pg = GetCharacterItem(chref, "pistolgrapes");
				mb = GetCharacterItem(chref, "musketbullets");
				pb = GetCharacterItem(chref, "pistolbullets");
				ca = GetCharacterItem(chref, "cartridges");
				na = GetCharacterItem(chref, "nails");
				ar = GetCharacterItem(chref, "bladearrows");
				ar2 = GetCharacterItem(chref, "arrows2");
				ro = GetCharacterItem(chref, "rockets");
				gpb = GetCharacterItem(chref, "cart_box_O");
				cap = GetCharacterItem(chref, "caps_box_O");
				
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
						if(gp <= 2) chref.Items.gunpowder = 0;
						if(ro == 0) chref.Items.(ammoName) = 0;
					break;
					case "pc":
						ammoName = "cart_box_O";
						ammoName2 = "caps_box_O";
						if(gpb == 0) enough_ammo = false;
						if(cap == 0) enough_ammo = false;
					break;
				}

			//JRH -->
				if(weapon.shottype == "pg" || weapon.shottype == "pg2" || weapon.shottype == "mb" || weapon.shottype == "pb" 
				|| weapon.shottype == "pb2" || weapon.shottype == "na2" || weapon.shottype == "ro")
				{
				    if(enough_ammo == false) 
				    {
						LAi_GunSetUnload(chref);
				    }
				    else
				    {
						if(sti(chref.Items.(ammoName))==0 || sti(chref.Items.gunpowder)==0) LAi_GunSetUnload(chref);
						else
						{
							if(CheckAttribute(weapon,"chargeQ"))
							{
								if(sti(chref.Items.(ammoName))<sti(weapon.chargeQ)) LAi_GunSetUnload(chref);
								if(sti(chref.Items.gunpowder)<sti(weapon.chargeQ)) LAi_GunSetUnload(chref);
							}
						}
				    }
				}


				if(weapon.shottype == "ca" || weapon.shottype == "ar" || weapon.shottype == "ar2")
				{
				    if(enough_ammo == false) 
				    {
						LAi_GunSetUnload(chref);
				    }
				    else
				    {
						if(sti(chref.Items.(ammoName))==0) LAi_GunSetUnload(chref);
						else
						{
							if(CheckAttribute(weapon,"chargeQ"))
							{
								if(sti(chref.Items.(ammoName))<sti(weapon.chargeQ)) LAi_GunSetUnload(chref);
							}
						}
				    }
				}
			
				if(weapon.shottype == "pc")
				{
				    if(enough_ammo == false) 
				    {
						LAi_GunSetUnload(chref);
				    }
				    else
				    {
						if(sti(chref.Items.(ammoName))==0 || sti(chref.Items.(ammoName2))==0) LAi_GunSetUnload(chref);
						else
						{
							if(CheckAttribute(weapon,"chargeQ"))
							{
								if(sti(chref.Items.(ammoName))<sti(weapon.chargeQ)) LAi_GunSetUnload(chref);
								if(sti(chref.Items.(ammoName2))<sti(weapon.chargeQ)) LAi_GunSetUnload(chref);
							}
						}
				    }
				}
			//<-- JRH
			}
		}
	}
// added by MAXIMUS 21.07.2006 [weapon will not be charged without gunpowder or proper bullets][changed 24.11.2006] <--
}

void ExecuteCharacterEquip(ref chref)
{
	// NK fix; the stmp declaration was _below_ its first use!!! Also add armor. 05-04-12
	//trace("exing chr equip");
	string stmp = GetCharacterEquipByGroup(chref,BLADE_ITEM_TYPE);
	if(stmp!="")	{SetEquipedItemToCharacter(chref, BLADE_ITEM_TYPE, stmp);}
	stmp = GetCharacterEquipByGroup(chref,GUN_ITEM_TYPE);
	if(stmp!="")	{SetEquipedItemToCharacter(chref, GUN_ITEM_TYPE, stmp);}
	stmp = GetCharacterEquipByGroup(chref,ARMOR_ITEM_TYPE);
	SetEquipedItemToCharacter(chref, ARMOR_ITEM_TYPE, stmp); // yes even if it's "".
	//trace("done exing");
	// NK <--
}

bool IsCanEquiping(ref chref, string equiping_group)
{
	if( CheckAttribute(chref,"equip.disabled_group."+equiping_group)
		&& sti(chref.equip.disabled_group.(equiping_group))==true ) return false;
	if (equiping_group == OBJECT_ITEM_TYPE)   return false; // KK
	if (equiping_group == DOCUMENT_ITEM_TYPE) return false; // PB
	if (equiping_group == BOOK_ITEM_TYPE)     return false; // PB
	if (equiping_group == IT_TYPE_BLACKSMITH) return false; // PB
	return true;
}

void EnableEquip(ref chref, string equiping_group, bool enable)
{
	if(enable)
	{
		if(equiping_group=="")
		{
			DeleteAttribute(chref,"equip.disabled_group");
		}
		else
		{
			DeleteAttribute(chref,"equip.disabled_group."+equiping_group);
		}
	}
	else
	{
		if(equiping_group=="")
		{
			string stmp;
			stmp = GUN_ITEM_TYPE;		chref.equip.disabled_group.(stmp) = true;
			stmp = BLADE_ITEM_TYPE;		chref.equip.disabled_group.(stmp) = true;
			stmp = SPYGLASS_ITEM_TYPE;	chref.equip.disabled_group.(stmp) = true;
			stmp = ARMOR_ITEM_TYPE;		chref.equip.disabled_group.(stmp) = true; // NK 05-04-13
		}
		else
		{
			chref.equip.disabled_group.(equiping_group) = true;
		}
	}
}

// NK 04-09-06 -->
// to check if rep == "none"
int GetCharacterReputation(ref chr)
{
	if(CheckAttribute(chr,"reputation")) {if(chr.reputation != "none") { return sti(chr.reputation); } }
	return REPUTATION_NEUTRAL;
}
// NK <--
int ChangeCharacterReputation(ref chref, int incr) // TIH changed BACK to int ! got rid of float problems Aug29'06
{
	bool isDonation = false;
	if (IsMainCharacter(chref)) LogIt(TranslateString("","CHANGE REP FOR PLAYER:") + " " + intRet(incr==9999,1,incr) + stringRet(DOUBLE_REP_INCR," x2","")); // NK find rep bug
	int prevVal = GetCharacterReputation(&chref); // NK 04-09-06

	// LDH 25Sep06 simplify rep code for donations
	if (incr == 9999) {
		incr = 1;	// for donations, see quests_reaction.c
		isDonation = true;
	} else {
		if (DOUBLE_REP_INCR) incr *= 2;
	}

	int newVal = iclamp(REPUTATION_MIN, REPUTATION_MAX, prevVal + incr);
	chref.reputation = newVal;

	// LDH 19Sep06 - change officers' reputation as well
	if(!isDonation && sti(chref.index) == GetMainCharacterIndex())
	{
		int incrOfficer = incr;
		if (iabs(incr) != 1) incrOfficer /= 2;	// officers get half the increase unless incr is just 1
		for (int i = 1; i < OFFICER_MAX; i++)
		{
			int idx = GetOfficersIndex(GetMainCharacter(), i);
			if (idx > 0)
			{
				ref chOfficer = &Characters[idx];
				int value = GetCharacterReputation(chOfficer) + incrOfficer;			// PB: This MUST use a separate variable or it will not work correctly
				chOfficer.reputation = iclamp(REPUTATION_MIN, REPUTATION_MAX, value );	// PB: But I have no clue why, so this is really quite bizarre
			//	trace("Change of rep for " + chOfficer.name + " " + incrOfficer + " (" + chOfficer.reputation + ")");
			}
		}
	}

	if(!IsMainCharacter(chref)) return newVal;

	string prevName = GetTranslatedReputationForSex(chref, GetReputationName(prevVal));	// PB: Correction for female characters
	string newName  = GetTranslatedReputationForSex(chref, GetReputationName(newVal ));	// PB: Correction for female characters
	if(prevName!=newName)
	{
		string outString = XI_ConvertString("Your reputation")+" ";
		if(incr>0)	{outString+=XI_ConvertString("increase");}
		else	{outString+=XI_ConvertString("decrease");}
		outString += " " + XI_ConvertString("to") + " " + newName;						// PB: Correction for female characters
		LogIt(outString);
	}
	return newVal;
}

bool Character_IsAbordageEnable(ref rCharacter)
{
	if(CheckAttribute(rCharacter, "Abordage.Enable")) { return sti(rCharacter.Abordage.Enable); }
	return true;
}

void Character_SetAbordageEnable(ref rCharacter, bool bEnable)
{
	rCharacter.Abordage.Enable = bEnable;
}

void Character_SetCompanionEnemyEnable(ref rCharacter, bool bEnable)
{
	rCharacter.CompanionEnemyEnable = bEnable;
}

void AddMsgToCharacter(ref chref, int nMsg)
{
	string msgName = "msg"+nMsg;
	bool bStartEvent = !CheckAttribute(chref,"MessageIcons."+msgName);
	chref.MessageIcons.(msgName).pic = nMsg;
	chref.MessageIcons.(msgName) = MSGICON_ACTIVE_TIME;
	if(bStartEvent) PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,sti(chref.index));
}

void DelMsgFromCharacter(ref chref, int nMsg)
{
	DeleteAttribute(chref,"MessageIcons.msg"+nMsg);
}

void proc_MsgIconTick()
{
	int nMsg = GetEventData();
	int chrIdx = GetEventData();
	if(DialogRun!=0) {
		PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,chrIdx);
		return;
	}
	ref chref = GetCharacter(chrIdx);
	string msgName = "msg"+nMsg;
	int nTime = 0;

	if( CheckAttribute(chref,"MessageIcons."+msgName) )
	{
		nTime = sti(chref.MessageIcons.(msgName));
		if(nTime>0)
		{
			chref.MessageIcons.(msgName) = nTime-1;
			PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,chrIdx);
			return;
		}
		DelMsgFromCharacter(chref,nMsg);
	}
}

// Stone-D Surrender Mod -->
int GetPrisonerQuantity(ref _refCharacter)
{
	int qn = 0;
	ref Char;
	for(int i=0; i<GetPassengersQuantity(_refCharacter); i++)
	{
		Char=GetCharacter(GetPassenger(_refCharacter,i));
		if (IsPrisoner(Char)) qn++; // KK
	}
	return qn;
}
// Stone-D Surrender Mod <--

// KK -->
int GetPrisoner(ref _refCharacter, int n)
{
	int c = -1;
	int q = GetPrisonerQuantity(_refCharacter);
	if (n < 0 || n >= q) return -1;
	for (int i = 0; i < GetPassengersQuantity(_refCharacter); i++) {
		int idx = GetPassenger(_refCharacter, i);
		if (idx == -1) continue;
		ref Char = GetCharacter(idx);
		if (IsPrisoner(Char)) c++;
		if (c == n) return idx;
	}
	return -1;
}

bool IsPrisoner(ref _refCharacter)
{
	if (CheckAttribute(_refCharacter, "prisoned")) return sti(_refCharacter.prisoned);
	return false;
}

bool IsTrader(ref _refCharacter)
{
	int findIdx = -1; // KK
	if (CheckAttribute(_refCharacter, "index"))
		findIdx = sti(_refCharacter.index); // changed by MAXIMUS
	else
		return false;

	// PB: Just check single character officer type -->
	if (GetAttribute(_refCharacter, "quest.officertype") == OFFIC_TYPE_TRADER)	return true;
//	else										return false;
	// PB: Just check single character officer type <--
	// GR: this doesn't work on "Quest trader" if levelling has turned him into a different captain
	if (strlower(GetAttribute(_refCharacter, "id")) == "quest trader")		return true;
/*
	// PB: What was this supposed to be doing?
	ref mc = GetMainCharacter();
	for (int i = 1; i < 4; i++)
	{
		if (GetCompanionIndex(mc, i) == findIdx && CheckAttribute(&Characters[findIdx], "quest.officertype") == true && Characters[findIdx].quest.officertype == OFFIC_TYPE_TRADER) return true;
	}
*/
	return false;
}

int GetShipMinClassForCharacter(ref _refCharacter)
{
	int leadership = GetPartySkill(_refCharacter, SKILL_LEADERSHIP);
	int sailing    = GetPartySkill(_refCharacter, SKILL_SAILING);
	return GetShipMinClassForSkills(leadership, sailing);
}

int GetShipMinClassForSkills(int iLeadership, int iSailing)
{
	int skillN = iretMin(iLeadership, iSailing);
	return makeint(8 - skillN*0.7); // PB: Allow Tier 1 Ships
}

string GetCharacterShipModel(ref _refCharacter)
{
	string ShipID = GetCharacterShipID(_refCharacter);
	if (GetShipIndex(ShipID) < 0) return "";
	ref rShip = GetShipByID(ShipID);
	if (!CheckAttribute(_refCharacter, "Ship")) return "";
	aref arship; makearef(arship, _refCharacter.Ship);
	if (!CheckShipAttribute(arship, rship, "Model")) { trace("GetCharacterShipModel: missing Model attrib"); return ""; }
	return GetLocalShipAttrib(arship, rship, "Model");
}

float GetCharacterMaxCapacity(ref _refCharacter)
{
	if (!CheckAttribute(_refCharacter, "capacity.max")) {
		if (!CheckAttribute(_refCharacter, "sex")) return MAN_CAPACITY;
		if (_refCharacter.sex == "woman") return WOMAN_CAPACITY;
		return MAN_CAPACITY;
	}
	return stf(_refCharacter.capacity.max);
}

float GetCharacterCapacity(ref _refCharacter)
{
	if (!WEIGHTMOD) return 0.0;
	if (!CheckAttribute(_refCharacter, "capacity")) return 0.0;
	return stf(_refCharacter.capacity);
}

void SetCharacterCapacity(ref _refCharacter, float capacity)
{
	if (capacity <= 0.0) {
		_refCharacter.capacity = 0.0;
		return;
	}
	float max = GetCharacterMaxCapacity(_refCharacter);
	if (capacity >= max) {
		_refCharacter.capacity = max;
		return;
	}
	_refCharacter.capacity = capacity;
}

bool CheckFleetShips(bool bAddShip)
{
	ref pchar = GetMainCharacter();
	int companion_qty = GetCompanionQuantity(pchar);
	if (bAddShip) companion_qty += 1;
	if (companion_qty == 1) return false;
	if (companion_qty == 2) {
		for (int i = 1; i < COMPANION_MAX; i++)
		{
			int cn = GetCompanionIndex(pchar, i);
			if (cn < 0) continue;
			if (!GetRemovable(GetCharacter(cn))) return false;
		}
	}
	return true;
}

bool IsMutineer(ref _refCharacter)
{
	if (CheckAttribute(_refCharacter, "Mutineer")) return sti(_refCharacter.Mutineer);
	return false;
}

void SetMutineer(ref _refCharacter, bool bSet)
{
	DeleteAttribute(_refCharacter, "Mutineer");
	if (bSet) _refCharacter.Mutineer = true;
}
// <-- KK

// Added by MM...

int GetNotCaptivePassengerNumber(ref _refCharacter,int findCharacterIdx)
{
	int psgQuant = GetNotCaptivePassengersQuantity(_refCharacter);
	int cn;
	ref cr;
	for(int i=0; i<psgQuant; i++)
	{
		cn = GetNotCaptivePassenger(_refCharacter,i);
		if(cn==-1) break;
		cr = GetCharacter(cn);
		if(findCharacterIdx==sti(cr.index)) return i;
	}
	return -1;
}
int ChangeNotCaptivePassenger(ref _refCharacter,int idx, int psngIdx)
{
	int retVal = GetNotCaptivePassenger(&_refCharacter,idx);
	if(idx>=0)
	{
		string PsgAttrName = "id"+(idx+1);
		_refCharacter.Fellows.Passengers.(PsgAttrName) = psngIdx;
		Characters[idx].passenger = true;
		if (CheckAttribute(&Characters[psngIdx], "passenger")) DeleteAttribute(&Characters[psngIdx], "passenger");
	}
	return retVal;
}
int RemoveNotCaptivePassenger(ref _refCharacter,ref _refPassenger)
{
	int i;
	RemoveOfficersIndex(_refCharacter,sti(_refPassenger.index));
	int PsgQuantity = GetNotCaptivePassengersQuantity(_refCharacter);
	int psgNum = GetNotCaptivePassengerNumber(_refCharacter,sti(_refPassenger.index));
	if(psgNum==-1) return PsgQuantity;

	aref tmpRef;
	makearef(tmpRef,_refCharacter.Fellows.Passengers);
	string inPsgAttrName,outPsgAttrName;
	for(i=(psgNum+1); i<PsgQuantity; i++)
	{
		inPsgAttrName = "id"+i;
		outPsgAttrName = "id"+(i+1);
		tmpRef.(inPsgAttrName) = tmpRef.(outPsgAttrName);
	}

	outPsgAttrName = "id"+PsgQuantity;
	DeleteAttribute(tmpRef,outPsgAttrName);
	PsgQuantity--;
	tmpRef.Quantity = PsgQuantity;
	if (CheckAttribute(_refPassenger, "passenger")) DeleteAttribute(_refPassenger, "passenger"); // KK
	ResetPartySkillAll(_refCharacter); // PB: Let's be careful here and reset ONLY party skill (could also be ResetSkillModifier/ResetEffectiveSkill)
	return PsgQuantity;
}

