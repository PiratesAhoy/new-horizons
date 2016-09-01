#include "cannons\cannons.h"

extern void InitCannons();

void CannonsInit()
{
	if(LoadSegment("cannons\cannons_init.c"))
	{
		InitCannons();
		UnloadSegment("cannons\cannons_init.c");
	}

	SetEventHandler(GET_CANNON_BY_TYPE_EVENT,"CannonGetByTypeEvent",0);
}

aref CannonGetByTypeEvent()
{
	int iCannonType = GetEventData();
	return &Cannon[iCannonType];
}

int GetCannonByTypeAndCaliber(string sCannonType, int iCaliber)
{
	// KNB -->
	if(USE_REAL_CANNONS)
	{
		switch (sCannonType)
		{
			case "long gun":
				switch (iCaliber)
				{
					case 4:
						return CANNON_TYPE_LONG_LBS4;
					break;
					case 6:
						return CANNON_TYPE_LONG_LBS6;
					break;
					case 9:
						return CANNON_TYPE_LONG_LBS9;
					break;
					case 12:
						return CANNON_TYPE_LONG_LBS12;
					break;
					case 18:
						return CANNON_TYPE_LONG_LBS18;
					break;
					case 24:
						return CANNON_TYPE_LONG_LBS24;
					break;
					case 32:
						return CANNON_TYPE_LONG_LBS32;
					break;
					case 42:
						return CANNON_TYPE_LONG_LBS42;
					break;
				}
			break;

			case "carronade":
				switch (iCaliber)
				{
					case 6:
						return CANNON_TYPE_CARRONADE_LBS12;
					break;
					case 9:
						return CANNON_TYPE_CARRONADE_LBS18;
					break;
					case 12:
						return CANNON_TYPE_CARRONADE_LBS24;
					break;
					case 18:
						return CANNON_TYPE_CARRONADE_LBS32;
					break;
					case 24:
						return CANNON_TYPE_CARRONADE_LBS42;
					break;
					case 32:
						return CANNON_TYPE_CARRONADE_LBS68;
					break;
					case 32:
						return CANNON_TYPE_CARRONADE_LBS68I;
					break;
					case 24:
						return CANNON_TYPE_CARRONADE_LBS42I;
					break;
					case 68:
						return CANNON_TYPE_CARRONADE_LBS68SPEC;
					break;
					case 128:
						return CANNON_TYPE_CARRONADE_DUTCHMAN;
					break;
				}
			break;
		}
	}
	// KNB <--

	else
	{
		switch (sCannonType)
		{
			case "cannon":
				switch (iCaliber)
				{
					case 12:
						return CANNON_TYPE_CANNON_LBS12;
					break;
					case 16:
						return CANNON_TYPE_CANNON_LBS16;
					break;
					case 24:
						return CANNON_TYPE_CANNON_LBS24;
					break;
					case 32:
						return CANNON_TYPE_CANNON_LBS32;
					break;
				}
			break;
			case "culverine":
				switch (iCaliber)
				{
					case 12:
						return CANNON_TYPE_CULVERINE_LBS12;
					break;
					case 16:
						return CANNON_TYPE_CULVERINE_LBS16;
					break;
					case 24:
						return CANNON_TYPE_CULVERINE_LBS24;
					break;
					// NK add 32 just to be sure
					case 32:
						return CANNON_TYPE_CANNON_LBS32;
					break;
				}
			break;
		}
	}
	return CANNON_TYPE_NONECANNON;
}

// NK -->
int GetCannonCaliberIndex(int cal)
{
	for(int i = 0; i < CANNON_CALIBERS_MAX; i++) { if(CANNON_CALIBERS[i] == cal) return i; }
	return -1;
}
// NK <--

// NK Cannon qty mod 05-04-19 -->

int GetCannonPrice(int nCannonType)
{
	if(nCannonType==CANNON_TYPE_NONECANNON) return 0;
	ref rCannon = GetCannonByType(nCannonType);
	return sti(rCannon.Cost);
}

int GetCannonWeight(int nCannonType)
{
	if(nCannonType==CANNON_TYPE_NONECANNON) return 0;
	ref rCannon = GetCannonByType(nCannonType);
	return sti(rCannon.Weight);
}

float GetCannonWeightByCharacter(ref rChar)
{
	int nCannonType = GetCaracterShipCannonsType(rChar);
	if(nCannonType==CANNON_TYPE_NONECANNON) return 0.0;
	ref rCannon = GetCannonByType(nCannonType);
	return stf(rCannon.Weight);
}

int GetCannonDeltaPrice(ref rChar,int nCannonType, int sq, int bq)
{
	/*int ncq = GetCannonQuantity(rChar);
	if(ncq==0) return 0;
	int nMyCannonType = GetCaracterShipCannonsType(rChar);
	if(nMyCannonType==nCannonType) return 0;
	// NK sellprice-->
	if ((GetCannonPrice(nCannonType)-GetCannonPrice(nMyCannonType))*ncq) return (GetCannonPrice(nCannonType)-GetCannonPrice(nMyCannonType)/2)*ncq;
	return (GetCannonPrice(nCannonType)-GetCannonPrice(nMyCannonType))*ncq / 2;
	// NK <--*/
	ref buychar = GetCharacter(sti(rChar.index));
	if(IsCompanion(&rChar)) buychar = GetMainCharacter();
	//int cq = GetCannonQuantity(rChar);
	int mq = GetCannonMaxQuantity(rChar);
	//trace("c / m " + cq +", " + mq);
	if(mq==0) return 0;
	int nMyCannonType = GetCaracterShipCannonsType(rChar);
	int oprice = GetCannonPrice(nMyCannonType) * sq * GetCharPriceMod(&buychar, PRICE_TYPE_SELL, true, true) * SHIPYARD_CANNON_SELL_MULT;
	//Levis changed location to id
	oprice -= MakeInt((0.1 * GetTownCrewMorale(GetTownIDFromLocID(Locations[FindLoadedLocation()].id)) / (MORALE_MAX - MORALE_MIN)) * makefloat(GetCurrentLocationNation() == PERSONAL_NATION)); // KK
	
	//trace("old price " + oprice);
	if(nCannonType == CANNON_TYPE_NONECANNON) return oprice;
	if(nMyCannonType==nCannonType)
	{
		if(bq == sq) return 0; // KK
		oprice = 0; bq -= sq; // only buy needed new guns, old ones are fine
		//trace("new oprice 0, new mq " + mq);
	}
	int nprice = GetCannonPrice(nCannonType) * bq * GetCharPriceMod(&buychar, PRICE_TYPE_BUY, true, true);
	//trace("nprice " + nprice);
	return (nprice - oprice);
}

//will reset to localship's max qty in each arc.
void ResetCannons(ref ch)
{
	if(!CheckAttribute(ch,"ship.cannons.borts")) return;
	aref arship; makearef(arship, ch.ship);
	ref rship = GetShipByType(GetCharacterShipType(ch));
	ch.ship.cannons.borts.cannonf.qty = GetLocalShipAttrib(&arship, &rship, "cannons.borts.cannonf.qty");
	ch.ship.cannons.borts.cannonb.qty = GetLocalShipAttrib(&arship, &rship, "cannons.borts.cannonb.qty");
	ch.ship.cannons.borts.cannonl.qty = GetLocalShipAttrib(&arship, &rship, "cannons.borts.cannonl.qty");
	ch.ship.cannons.borts.cannonr.qty = GetLocalShipAttrib(&arship, &rship, "cannons.borts.cannonr.qty");
}

// add all fixable cannons back to can qty, delete each fix attribute
void RepairAllCannons(ref ch)
{
	if(!CheckAttribute(ch,"ship.cannons.borts")) return;

	int CannonsFixed = 0;	// LDH 21Jan09

	if(CheckAttribute(ch,"ship.cannons.borts.cannonf.fix"))
	{
		ch.ship.cannons.borts.cannonf.qty = iclamp(0, GetCannonArcMaxQty(&ch, 0), sti(ch.ship.cannons.borts.cannonf.qty) + sti(ch.ship.cannons.borts.cannonf.fix));
		CannonsFixed += iretmin(sti(ch.ship.cannons.borts.cannonf.qty), sti(ch.ship.cannons.borts.cannonf.fix));	// LDH 21Jan09
		DeleteAttribute(&ch,"ship.cannons.borts.cannonf.fix");
	}
	if(CheckAttribute(ch,"ship.cannons.borts.cannonb.fix"))
	{
		ch.ship.cannons.borts.cannonb.qty = iclamp(0, GetCannonArcMaxQty(&ch, 2), sti(ch.ship.cannons.borts.cannonb.qty) + sti(ch.ship.cannons.borts.cannonb.fix));
		CannonsFixed += iretmin(sti(ch.ship.cannons.borts.cannonb.qty), sti(ch.ship.cannons.borts.cannonb.fix));	// LDH 21Jan09
		DeleteAttribute(&ch,"ship.cannons.borts.cannonb.fix");
	}
	if(CheckAttribute(ch,"ship.cannons.borts.cannonl.fix"))
	{
		ch.ship.cannons.borts.cannonl.qty = iclamp(0, GetCannonArcMaxQty(&ch, 3), sti(ch.ship.cannons.borts.cannonl.qty) + sti(ch.ship.cannons.borts.cannonl.fix));
		CannonsFixed += iretmin(sti(ch.ship.cannons.borts.cannonl.qty), sti(ch.ship.cannons.borts.cannonl.fix));	// LDH 21Jan09
		DeleteAttribute(&ch,"ship.cannons.borts.cannonl.fix");
	}
	if(CheckAttribute(ch,"ship.cannons.borts.cannonr.fix"))
	{
		ch.ship.cannons.borts.cannonr.qty = iclamp(0, GetCannonArcMaxQty(&ch, 1), sti(ch.ship.cannons.borts.cannonr.qty) + sti(ch.ship.cannons.borts.cannonr.fix));
		CannonsFixed += iretmin(sti(ch.ship.cannons.borts.cannonr.qty), sti(ch.ship.cannons.borts.cannonr.fix));	// LDH 21Jan09
		DeleteAttribute(&ch,"ship.cannons.borts.cannonr.fix");
	}

	// LDH add repair skill for repairs  - 21Jan09
	// This will add skill for repairs done at shipyard.  This is intentional.
	if (AUTO_SKILL_SYSTEM && CannonsFixed > 0) 
	{
		int AddSkill = CannonsFixed * 30;
		if (sti(ch.index) == GetMainCharacterIndex())		// LDH 24Jan09
			Trace("Repair & Defence skill added in RepairAllCannons: " + AddSkill);
		AddPartyExpChar(ch, "Repair", AddSkill));
		AddPartyExpChar(ch, "Defence", AddSkill);
	}

}


// sets qty of cannon in arc to qty. Returns false if can't set.
bool SetCannonArcQty(ref ch, int arc, int qty)
{
	string quadstr = GetQuadName(arc);
	if(quadstr == "") return false; // arc not correct
	ref rship = GetShipByType(GetCharacterShipType(ch));
	if(!sti(rship.cannonsquantity)) return false; // ship has no guns
	/*if(!CheckAttribute(ch,"ship.cannons.borts."+quadstr) ch.ship.cannons.borts.(quadstr) = "";
	aref arcan; makearef(arcan, ch.ship.cannons.borts.(quadstr));
	arcan.qty = qty;*/
	ch.ship.cannons.borts.(quadstr).qty = qty;
	return true;
}

// gets crew-adjusted number of cannon in arc
int GetCannonArcCurQty(ref ch, int arc)
{
	int num = -1;
	string quadstr = GetQuadName(arc);
	if(quadstr == "") return num;
	if(CheckAttribute(ch,"ship.cannons.borts."+quadstr+".curqty")) return sti(ch.ship.cannons.borts.(quadstr).curqty);
	if(CheckAttribute(ch,"ship.cannons.borts."+quadstr+".qty")) return sti(ch.ship.cannons.borts.(quadstr).qty);
	aref arship; makearef(arship, ch.ship);
	ref rship = GetShipByType(GetCharacterShipType(ch));
	return sti(GetLocalShipAttrib(&arship, &rship, "cannons.borts."+quadstr+".qty"));
}


// gets number of cannon in arc
int GetCannonArcQty(ref ch, int arc)
{
	int num = -1;
	string quadstr = GetQuadName(arc);
	if(quadstr == "") return num;
	if(CheckAttribute(ch,"ship.cannons.borts."+quadstr+".qty")) return sti(ch.ship.cannons.borts.(quadstr).qty);
	aref arship; makearef(arship, ch.ship);
	ref rship = GetShipByType(GetCharacterShipType(ch));
	return sti(GetLocalShipAttrib(&arship, &rship, "cannons.borts."+quadstr+".qty"));
}

// gets maximum number of cannon for arc
int GetCannonArcMaxQty(ref ch, int arc)
{
	int num = -1;
	string quadstr = GetQuadName(arc);
	if(quadstr == "") return num;
	//if(CheckAttribute(ch,"ship.cannons.borts."+quadstr+".qty")) return sti(ch.ship.cannons.borts.(quadstr).qty);
	aref arship; makearef(arship, ch.ship);
	ref rship = GetShipByType(GetCharacterShipType(ch));
	return sti(GetLocalShipAttrib(&arship, &rship, "cannons.borts."+quadstr+".qty"));
}

// gets crew-adjusted number of cannon
int GetCannonCurQuantity(ref ch)
{
	return (0+GetCannonArcCurQty(&ch, 0)+GetCannonArcCurQty(&ch, 1)+GetCannonArcCurQty(&ch, 2)+GetCannonArcCurQty(&ch, 3));
}
// NK <--
int GetMaxCannonQuantity(ref ch)
{
	return (0+GetCannonArcMaxQty(&ch, 0)+GetCannonArcMaxQty(&ch, 1)+GetCannonArcMaxQty(&ch, 2)+GetCannonArcMaxQty(&ch, 3));
}

// KK -->
int GetCannonChargesPerCannon(ref ch)
{
	int cannon_type = GetCaracterShipCannonsType(ch);
	if (cannon_type == CANNON_TYPE_NONECANNON) return 0;
	aref rCannon; makearef(rCannon, Cannon[cannon_type]);
	if (!CheckAttribute(rCannon, "gunpowder")) return 0;
	return sti(rCannon.gunpowder);
}

int SellCannons(ref chr, int cq)
{
	ref char = GetCharacter(sti(chr.index));
	if (IsCompanion(chr)) char = GetMainCharacter();
	int nCannonType = GetCaracterShipCannonsType(chr);
	float Charmod = GetCharPriceMod(char, PRICE_TYPE_SELL, true, true);
	return 0 - makeint(GetCannonPrice(nCannonType) * Charmod * SHIPYARD_CANNON_SELL_MULT) * cq; // PB: Changed to prevent float operation from causing disrepancies in prices for batch transactions
}

int BuyCannons(ref chr, int nCannonType, int cq)
{
	ref char = GetCharacter(sti(chr.index));
	if (IsCompanion(chr)) char = GetMainCharacter();
	// PB: Trade High code for cannons moved here -->
	int tradeHighModifier = 1;
	if(tradeHigh) tradeHighModifier = 2;
	return makeint(GetCannonPrice(nCannonType) * GetCharPriceMod(char, PRICE_TYPE_BUY, true, true) * tradeHighModifier) * cq;
	// PB: Trade High code for cannons moved here <--
}

int GetCannonType(int cannon_type)
{
	if (cannon_type < 0 || cannon_type >= CANNON_TYPES_QUANTITY) return -1;
	ref rCannon = GetCannonByType(cannon_type);
	if (CheckAttribute(rCannon, "type")) return sti(rCannon.type);
	return CANNON_NAME_LONG;
}

void SetNoneCannonsOnShip(ref ch)
{
	if (!CheckAttribute(ch,"ship.cannons.borts")) return;
	aref arship; makearef(arship, ch.Ship);
	ch.Ship.Cannons.Borts.cannonf.qty = 0;
	ch.Ship.Cannons.Borts.cannonb.qty = 0;
	ch.Ship.Cannons.Borts.cannonl.qty = 0;
	ch.Ship.Cannons.Borts.cannonr.qty = 0;
	ch.Ship.Cannons.Type = CANNON_TYPE_NONECANNON;
}
// <-- KK
