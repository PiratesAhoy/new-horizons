// KK -->
#define SHIPUPGRADES_QUANTITY         8

#define SHIPUPGRADE_CPLATES           0
#define SHIPUPGRADE_BCANNONS          1
#define SHIPUPGRADE_GCHASERS          2
#define SHIPUPGRADE_NSAILS            3
#define SHIPUPGRADE_LTOPMASTS         4
#define SHIPUPGRADE_STAYS             5
#define SHIPUPGRADE_RHULL             6
#define SHIPUPGRADE_FLUSHED           7

string GetShipUpgradeID(int upgradeidx)
{
	switch (upgradeidx) {
		case SHIPUPGRADE_CPLATES:   return "cplates";   break;
		case SHIPUPGRADE_BCANNONS:  return "bcannons";  break;
		case SHIPUPGRADE_GCHASERS:  return "gchasers";  break;
		case SHIPUPGRADE_NSAILS:    return "nsails";    break;
		case SHIPUPGRADE_LTOPMASTS: return "ltopmasts"; break;
		case SHIPUPGRADE_STAYS:     return "stays";     break;
		case SHIPUPGRADE_RHULL:     return "rhull";     break;
		case SHIPUPGRADE_FLUSHED:   return "flushed";   break;
	}
	return "";
}

int GetShipPriceByType(ref chr)
{
	if (!CheckAttribute(chr, "Ship.idx")) return 0;
	int st = sti(chr.Ship.idx);
	if (st == SHIP_NOTUSED) return 0;
	ref shref = GetShipByType(st);
	aref arShip; makearef(arShip, chr.Ship);
	return sti(GetLocalShipAttrib(arShip, shref, "Price"))*2; // TIH - why are ALL ship prices DOUBLED here ??? // PRS3
}

int GetShipRepairPriceByType(ref chr)
{
	if (!CheckAttribute(chr, "Ship.idx")) return 0;
	int st = sti(chr.Ship.idx);
	int shipPrice = GetShipPriceByType(chr);
	if (shipPrice == 0) return 0;
	ref shref = GetShipByType(st);
	aref arShip; makearef(arShip, chr.Ship);
	int shipClassFactor = 4 - sti(GetLocalShipAttrib(arShip, shref, "Class"));
	if (shipClassFactor > 0) shipPrice = shipPrice / shipClassFactor;
	return shipPrice;
}

int GetSailRepairCost(ref chr, int repairPercent)
{
	if (LAi_IsCapturedLocation) return 0; // KK
	int shipPrice = GetShipPriceByType(chr); // KK
	if(shipPrice<=0) return 0;
	int scost = (shipPrice*sailCostPercent+99)/100;
// TIH --> fixed for MAXIMUS [possibility to repair your ship by double price] -->
	float tradeHighModifier = 1.0;
	if(tradeHigh==true) tradeHighModifier = 2.0;
	return makeint(((makefloat(scost)*makefloat(repairPercent)+99.0)/100.0)*tradeHighModifier);
// TIH <-- fixed for MAXIMUS [possibility to repair your ship by double price] <--
}

int GetHullRepairCost(ref chr, int repairPercent)
{
	if (LAi_IsCapturedLocation) return 0; // KK
	int shipPrice = GetShipRepairPriceByType(chr); // KK
	if(shipPrice<=0) return 0;
	int scost = (shipPrice*hullCostPercent+99)/100;
// TIH --> fixed for MAXIMUS [possibility to repair your ship by double price] -->
	float tradeHighModifier = 1.0;
	if(tradeHigh==true) tradeHighModifier = 2.0;
	return makeint(((makefloat(scost)*makefloat(repairPercent)+99.0)/100.0)*tradeHighModifier);
// TIH <-- fixed for MAXIMUS [possibility to repair your ship by double price] <--
}
// <-- KK

//*********   KBLACK TUNING SHIPS FUNCTIONS *************
int GetCostTun(int _idx, string _improvement, float _priceType)
{
	ref ShipRef = GetShipByType(GetCharacterShipType(GetCharacter(_idx)))

	int ship_price 		= ShipRef.price;
	int ship_class 		= ShipRef.class;
	int ship_strength	= ShipRef.hp;
	int ship_weight		= ShipRef.weight;
	int ship_capacity	= ShipRef.capacity;
	int ship_caliber	= ShipRef.maxcaliber;
	int ship_cannons	= ShipRef.cannonsquantity;

	float modifier = GetCharPriceMod(GetMainCharacter(),_priceType,true,true); // PW: was 'int'!

	switch (_improvement) {
		case "rhull":
			return makeint(modifier * ship_strength * RHCOSTMULT);
		break;
		case "cplates":
			return makeint(modifier * ship_weight * CPCOSTMULT);
		break;
		case "flushed":
			return makeint(modifier * ship_weight * FLUSHEDCOSTMULT);
		break;
		case "nsails":
			return makeint(modifier * ship_price * NSCOSTMULT);
		break;
		case "ltopmasts":
			return makeint(modifier * ship_price * TMCOSTMULT);
		break;
		case "stays":
			return makeint(modifier * ship_price * SSCOSTMULT);
		break;
		case "bcannons":
			return makeint(modifier * ship_cannons * BCCOSTMULT);
		break;
		case "gchasers":
			return makeint(modifier * ship_cannons * GCCOSTMULT);
		break;
	}
	return 0; // KK
}

int GetTimeTun(int _idx, string _improvement)
{
	int i,j;
	ref char;
	i=0;
	switch (_improvement ) {
		
		case "cplates":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetHullRepairCost(sti(char.ship.idx),100)/1000));
			return i * CPTIMEMULT;
		break;
		
		case "rhull":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetHullRepairCost(sti(char.ship.idx),100)/1000));
			return i * RHTIMEMULT;
		break;
		
		case "flushed":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetHullRepairCost(sti(char.ship.idx),100)/1000));
			return i * FLUSHEDTIMEMULT;
		break;
		
		case "nsails":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetSailRepairCost(sti(char.ship.idx),100)/1000));
			return i * NSTIMEMULT;
		break;
		case "ltopmasts":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetSailRepairCost(sti(char.ship.idx),100)/1000));
			return i * TMTIMEMULT;
		break;
		case "stays":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i= 1+makeint(sqrt(GetSailRepairCost(sti(char.ship.idx),100)/1000));
			return i * SSTIMEMULT;
		break;

		case "bcannons":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i = 1;
			return i;
		break;
		case "gchasers":
			if (_idx == 0 ) { char = GetMainCharacter(); }
			else { char = GetCharacter(_idx); }
			i = 1;
			return i;
		break;
	}
	return 0; // KK
}
	
int ApplyTun (int _idx, string _improvement, int _time)
{
	int i,j;
	float pertoadd;
	ref char;
	
	if (_idx == 0 ) { char = GetMainCharacter(); }
	else { char = GetCharacter(_idx); }
	switch (_improvement ) {
		
		case "cplates":
			applytunspeed(char,"cplates",CPSPEEDRANGEMAX,CPSPEEDRANGEMIN);
			applytunturning(char,"cplates",CPTURNINGRANGEMAX,CPTURNINGRANGEMIN);
			applytuninertia(char,"cplates",CPINERTIARANGEMAX,CPINERTIARANGEMIN);		
		break;
		
		case "rhull":
			applytunhullhp(char,"rhull",RHHULLHPRANGEMAX,RHHULLHPRANGEMIN);
			applytuninertia(char,"rhull",RHINERTIARANGEMAX,RHINERTIARANGEMIN);		
			applytunupcaliber(char,"rhull",RHCALIBERADD);
		break;
		
		case "flushed":
			applytunspeed(char,"flushed",FLUSHSPEEDRANGEMAX,FLUSHSPEEDRANGEMIN);
			applytunturning(char,"flushed",FLUSHTURNINGRANGEMAX,FLUSHTURNINGRANGEMIN);
			applytunhullhp(char,"flushed",FLUSHHULLHPRANGEMAX,FLUSHHULLHPRANGEMIN);
			applytunload(char,"flushed",FLUSHLOADRANGEMAX,FLUSHLOADRANGEMIN);
		break;
		
		case "nsails":
			applytunspeed(char,"nsails",NSSPEEDRANGEMAX,NSSPEEDRANGEMIN);
			applytuninertia(char,"nsails",NSINERTIARANGEMAX,NSINERTIARANGEMIN);		
			applytunsailhp(char,"nsails",NSSAILHPRANGEMAX,NSSAILHPRANGEMIN);
//KB -Tuning ships - removed functionality 			applytunsailcrit(char,"nsails",NSSAILCRIT);		
		break;
		
		case "ltopmasts":
			applytunspeed(char,"ltopmasts",TMSPEEDRANGEMAX,TMSPEEDRANGEMIN);
			applytuninertia(char,"ltopmasts",TMINERTIARANGEMAX,TMINERTIARANGEMIN);		
			applytunsailcrit(char,"ltopmasts",TMSAILCRIT);		
		break;
		case "stays":
			applytunturning(char,"stays",SSTURNINGRANGEMAX,SSTURNINGRANGEMIN);
			applytuntack(char,"stays",SSTACKRANGEMAX,SSTACKRANGEMIN);		
		break;

		case "bcannons":
			char.ship.tune.bcannons.on = 1;
		break;
		case "gchasers":
			char.ship.tune.gchasers.on = 1;
		break;
	}
	if (_time > 0) {
		WaitDate("", 0, 0, _time, 0, 0);
		Log_SetStringToLog("You get your ship " + _time + " days later.");
	}
	return 0;
}

int UnApplyTun (int _idx, string _improvement, bool berth) // PW added boolean for difference between berthing/non berthing (no time element)
{
	int i,j;
	float pertoadd;
	ref char;
	int time;
	int cost;

	time = GetTimeTun(_idx, _improvement                 )/10;
	cost = GetCostTun(_idx, _improvement, PRICE_TYPE_SELL)/10;
	if (time < 1) { time = 1; }
	if (berth) time = 0;// PW boolean check to remove time factor on berthing
	if (_idx == 0 ) { char = GetMainCharacter(); }
	else { char = GetCharacter(_idx); }
	switch (_improvement ) {
		
		case "cplates":
			unapplytunspeed(char,"cplates");
			unapplytunturning(char,"cplates");
			unapplytuninertia(char,"cplates");		
		break;
		
		case "nsails":
			unapplytunspeed(char,"nsails");
			unapplytuninertia(char,"nsails");		
			unapplytunsailhp(char,"nsails");
			unapplytunsailcrit(char,"nsails");		
		break;
		case "ltopmasts":
			unapplytunspeed(char,"ltopmasts");
			unapplytuninertia(char,"ltopmasts");		
			unapplytunsailcrit(char,"ltopmasts");		
		break;
		case "stays":
			unapplytunturning(char,"stays");
			unapplytuntack(char,"stays");		
		break;

		case "bcannons":
			char.ship.tune.bcannons.on = 0;
		break;
		case "gchasers":
			char.ship.tune.gchasers.on = 0;
		break;
		
		//Kblack - It's not allowed to take out, but... just in case. 	
		case "rhull":
			unapplytunhullhp(char,"rhull");
			unapplytuninertia(char,"rhull");		
			unapplytunupcaliber(char,"rhull");		
		break;

		//Kblack - It's not allowed to take out, but... just in case. 		
		case "flushed":
			unapplytunspeed(char,"flushed");
			unapplytunturning(char,"flushed");
			unapplytunhullhp(char,"flushed");
			unapplytunload(char,"flushed");
		break;
		
	}

	if (time > 0) {
		WaitDate("", 0, 0, time, 0, 0);
		Log_SetStringToLog("You get your ship " + time + " days later.");
	}
	if (_improvement == "rhull" ||  _improvement == "flushed") cost = 0;// PW make sure you don't get paid when removed on berthing
	if (cost > 0) Characters[GetMainCharacterIndex()].Money = sti(Characters[GetMainCharacterIndex()].Money) + cost; // PW Money to pchar not companion

	return 0;
}

//---> FlayedOne For use when berthing. Doesn't take time. Strips all upgrades. Mainchar gets the money.
int stripUpgradesBerth(int _idx)
{
	for (int  upgradeId=0; upgradeId<8; upgradeId++)
	{
		if(CheckTun(_idx,GetShipUpgradeID(upgradeId)))
			UnApplyTun(_idx,GetShipUpgradeID(upgradeId),1); // PW: added boolean to remove time if berthing
	}
	return 0;
}
//<--- FlayedOne

// KK -->
bool CheckTun(int _idx, string _improvement)
{
	if (_idx < 0) return false;
	ref char = GetCharacter(_idx);
	if (!CheckAttribute(char, "ship.tune." + _improvement + ".on")) return false;
	return sti(char.ship.tune.(_improvement).on);
}
// <-- KK

void InitTun (int _idx)
{
	int i,j;
	ref char;

	if (_idx == 0 ) { char = GetMainCharacter(); }
	else { char = GetCharacter(_idx); }
	char.ship.tune = "";
	char.ship.tune.cplates = "";
	char.ship.tune.cplates.on = 0;
	char.ship.tune.bcannons = "";
	char.ship.tune.bcannons.on = 0;
	char.ship.tune.gchasers = "";
	char.ship.tune.gchasers.on = 0;
	char.ship.tune.nsails = "";
	char.ship.tune.nsails.on = 0;
	char.ship.tune.ltopmasts = "";
	char.ship.tune.ltopmasts.on = 0;
	char.ship.tune.stays = "";
	char.ship.tune.stays.on = 0;
	char.ship.tune.rhull = "";
	char.ship.tune.rhull.on = 0;
	char.ship.tune.flushed = "";
	char.ship.tune.flushed.on = 0;
	char.ship.tune.tack = 0;
	char.ship.tune.tackmod = 0;
	return;
}

//  KBLACK - FUNCTIONS TO APPLY SHIP IMPROVEMENTS TO SHIP CHARACTERISTICS 
void applytunspeed(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	aref temparef;
	
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+1; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.5*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.(_improvement).on = 1;
	// KB & PB: Error control -->
	makearef(temparef,_char.ship.stats);
	if (!CheckAttribute(temparef,"origspeed"))
	{
		if(!CheckAttribute(temparef, "speedrate"))
		{
			int SpeedRate = GetCharacterShipValue(_char, "SpeedRate");
			temparef.speedrate = SpeedRate; // PB: Why does "temparef.speedrate = GetCharacterShipValue(_char, "SpeedRate");" return 0???
		}
		temparef.origspeed = temparef.speedrate;
	}
	// KB & PB: Error control <--
	_char.ship.tune.(_improvement).speedrate = stf(_char.ship.stats.origspeed) * pertoadd/100;
	_char.ship.stats.speedrate = stf(_char.ship.stats.speedrate) + stf(_char.ship.tune.(_improvement).speedrate);
/*	if(IsMainCharacter(_char))
	{
		LogIt("Ships speed increased by " + _char.ship.tune.(_improvement).speedrate);
		LogIt("Max possible improvement = " + (stf(_char.ship.stats.origspeed) * rangemax/100));
		LogIt("Ships new speed = " + _char.ship.stats.speedrate);
	}*/
}


void applytunturning(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	aref temparef;
	
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+1; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.5*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.(_improvement).on = 1;
	// KB & PB: Error control -->
	makearef(temparef,_char.ship.stats);
	if (!CheckAttribute(temparef,"origturn"))
	{
		if(!CheckAttribute(temparef, "turnrate"))
		{
			int TurnRate = GetCharacterShipValue(_char, "TurnRate");
			temparef.turnrate = TurnRate; // PB: Why does "temparef.turnrate = GetCharacterShipValue(_char, "TurnRate");" return 0???
		}
		temparef.origturn = temparef.turnrate;
	}
	// KB & PB: Error control <--
	_char.ship.tune.(_improvement).turnrate = stf(_char.ship.stats.origturn) * pertoadd/100;
	_char.ship.stats.turnrate = stf(_char.ship.stats.turnrate) + stf(_char.ship.tune.(_improvement).turnrate);
/*	if(IsMainCharacter(_char))
	{
		LogIt("Ships turning rate increased by " + _char.ship.tune.(_improvement).turnrate);
		LogIt("Max possible improvement = " + (stf(_char.ship.stats.origturn) * rangemax/100));
		LogIt("Ships new turning rate = " + _char.ship.stats.turnrate);
	}*/
}


void applytuninertia(ref _char, string _improvement, float rangemax, float rangemin) {
return; }

void applytunhullhp(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	aref temparef;
	
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+1; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.5*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.(_improvement).on = 1;
	// KB & PB: Error control -->
	makearef(temparef,_char.ship.stats);
	if (!CheckAttribute(temparef,"orighp"))
	{
		if(!CheckAttribute(temparef, "hp"))
		{
			int HP = GetCharacterShipValue(_char, "HP");
			temparef.hp = HP; // PB: Why does "temparef.hp = GetCharacterShipValue(_char, "HP");" return 0???
		}
		temparef.orighp = temparef.hp;
	}
	// KB & PB: Error control <--
	_char.ship.tune.(_improvement).hp = stf(_char.ship.stats.orighp) * pertoadd/100;
	_char.ship.stats.hp = sti(_char.ship.stats.hp) + sti(_char.ship.tune.(_improvement).hp);

	if (CheckAttribute(_char, "ship.hp"))
	{
		int shipHP = sti(_char.ship.hp);
		int tuneHP = sti(_char.ship.tune.(_improvement).hp);
		if(shipHP + tuneHP > 0) _char.ship.hp = shipHP + tuneHP; //Levis added check to make sure we dont go under 0
	}
/*	if(IsMainCharacter(_char))
	{
		LogIt("Ships hull hps increased by " + _char.ship.tune.(_improvement).hp);
		LogIt("Max possible improvement = " + (stf(_char.ship.stats.orighp) * rangemax/100));
		LogIt("Ships new hps = " + _char.ship.stats.hp);
	}*/
}


void applytunload(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	aref temparef;
	
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+1; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.5*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.(_improvement).on = 1;
	// KB & PB: Error control -->
	makearef(temparef,_char.ship.stats);
	if (!CheckAttribute(temparef,"origcapacity"))
	{
		if(!CheckAttribute(temparef, "capacity"))
		{
			int Capacity = GetCharacterShipValue(_char, "Capacity");
			temparef.capacity = Capacity; // PB: Why does "temparef.capacity = GetCharacterShipValue(_char, "Capacity");" return 0???
		}
		temparef.origcapacity = temparef.capacity;
	}
	// KB & PB: Error control <--

	_char.ship.tune.(_improvement).capacity = stf(_char.ship.stats.origcapacity) * pertoadd/100;
	_char.ship.stats.capacity = sti(_char.ship.stats.capacity) + sti(_char.ship.tune.(_improvement).capacity);
/*	if(IsMainCharacter(_char))
	{
		LogIt("Ships capacity increased by " + _char.ship.tune.(_improvement).capacity);
		LogIt("Max possible improvement = " + (stf(_char.ship.stats.origcapacity) * rangemax/100));
		LogIt("Ships new capacity = " + _char.ship.stats.capacity);
	}*/
}

void applytunupcaliber(ref _char, string _improvement, int inc) {
	_char.ship.tune.(_improvement).on = 1;
	_char.ship.tune.(_improvement).incaliber = inc;
	int cal;
	aref temparef;
	ref tempref;
	tempref=GetShipByType(sti(_char.ship.idx));
	Makearef(temparef,_char.ship);
	int attribute = sti(GetLocalShipAttrib(temparef,tempref,"MaxCaliber"));
	cal = GetCannonCaliberIndex(attribute);
	if(cal != -1 && cal+inc >= CANNON_CALIBERS_MAX) { cal = CANNON_CALIBERS_MAX; }
	if(cal != -1 && cal+inc <= 0 ) { cal = 0; } // PB: To prevent decreasing too far
	if(cal >= 0) { // Fixed by MM
		_char.ship.stats.maxcaliber = Cannon_Calibers[cal+inc];
	}
}

void applytunsailhp(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+1; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.5*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.(_improvement).on = 1;
	_char.ship.tune.(_improvement).sails = makefloat(pertoadd/100);
}

void applytunsailcrit(ref _char, string _improvement, int inc) {
	_char.ship.tune.(_improvement).on = 1;
	_char.ship.tune.(_improvement).sailcrit = inc;
}

void applytuntack(ref _char, string _improvement, float rangemax, float rangemin) {
	float j;
	float pertoadd;
	j = rangemax - rangemin;
	pertoadd = j*frnd()+rangemin;
	if (rand(11) <= GetShipSkill(_char, SKILL_SNEAK)) { pertoadd=pertoadd+0.05; } // KK
	if (rand(11) <= GetShipSkill(_char, SKILL_SAILING)) { pertoadd=pertoadd+(0.05*j); } // KK
	if (pertoadd > rangemax) { pertoadd = rangemax;}
	_char.ship.tune.tack = sti(_char.ship.tune.tack)+1; 
	_char.ship.tune.(_improvement).on = 1;
	_char.ship.tune.(_improvement).tuntack = pertoadd;

/*	if(IsMainCharacter(_char))
	{
		LogIt("Ships dead angle decreased by " + (stf(_char.ship.tune.tackmod) + pertoadd));
		LogIt("Max possible improvement = " + (stf(_char.ship.tune.tackmod) + rangemin));
	}*/

	_char.ship.tune.tackmod = stf(_char.ship.tune.tackmod) + pertoadd; 
}

//  KBLACK - FUNCTIONS TO ---- TAKE OUT ---- SHIP IMPROVEMENTS TO SHIP CHARACTERISTICS 
void unapplytunspeed(ref _char, string _improvement) {
	
	_char.ship.tune.(_improvement).on = 0;
	_char.ship.stats.speedrate = stf(_char.ship.stats.speedrate) - stf(_char.ship.tune.(_improvement).speedrate);
	_char.ship.tune.(_improvement).speedrate = 0;
}


void unapplytunturning(ref _char, string _improvement) {
	_char.ship.tune.(_improvement).on = 0;
	_char.ship.stats.turnrate = stf(_char.ship.stats.turnrate) - stf(_char.ship.tune.(_improvement).turnrate);
	_char.ship.tune.(_improvement).turnrate = 0;
}


void unapplytuninertia(ref _char, string _improvement) {
return; }

void unapplytunhullhp(ref _char, string _improvement) {

	if (CheckAttribute(_char, "ship.hp"))
	{
		int shipHP = sti(_char.ship.hp);
		int tuneHP = sti(_char.ship.tune.(_improvement).hp);
		if(shipHP - tuneHP > 0) _char.ship.hp = shipHP - tuneHP; //Levis added check to make sure we dont go under 0
	}
	_char.ship.tune.(_improvement).on = 0;
	_char.ship.stats.hp = sti(_char.ship.stats.hp) - sti(_char.ship.tune.(_improvement).hp);
	_char.ship.tune.(_improvement).hp = 0;
}


void unapplytunload(ref _char, string _improvement) {

	_char.ship.tune.(_improvement).on = 0;
	_char.ship.stats.capacity = sti(_char.ship.stats.capacity) - sti(_char.ship.tune.(_improvement).capacity);
	_char.ship.tune.(_improvement).capacity = 0;
}

void unapplytunupcaliber(ref _char, string _improvement) {
	_char.ship.tune.(_improvement).on = 0;
	int inc=sti(_char.ship.tune.(_improvement).incaliber);
	int cal;
	aref temparef;
	ref tempref;
	tempref=GetShipByType(sti(_char.ship.idx));
	Makearef(temparef,_char.ship);
	int attribute = sti(GetLocalShipAttrib(temparef,tempref,"MaxCaliber"));
	cal = GetCannonCaliberIndex(attribute);
	if (cal != -1 && cal-inc < 0) { cal = 0; }
	if(cal != -1) { cal=cal - inc; _char.ship.stats.maxcaliber= Cannon_Calibers[cal]; }
	_char.ship.tune.(_improvement).incaliber = 0;
}

void unapplytunsailhp(ref _char, string _improvement) {

	_char.ship.tune.(_improvement).on = 0;
	_char.ship.tune.(_improvement).sails = 0;
}

void unapplytunsailcrit(ref _char, string _improvement) {
	_char.ship.tune.(_improvement).on = 0;
	_char.ship.tune.(_improvement).sailcrit = 0;
}

void unapplytuntack(ref _char, string _improvement) {

	_char.ship.tune.(_improvement).on = 0;
	_char.ship.tune.tack = sti(_char.ship.tune.tack)-1; 
	_char.ship.tune.tackmod = stf(_char.ship.tune.tackmod) - stf(_char.ship.tune.(_improvement).tuntack); 
	_char.ship.tune.(_improvement).tuntack = 0;
}


//********* END  KBLACK tuning ships functions ************
