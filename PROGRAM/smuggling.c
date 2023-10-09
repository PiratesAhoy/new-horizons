//Smuggling States
#define 	SMUGGLING_NONE		0
#define 	SMUGGLING_LOW		1
#define 	SMUGGLING_NORMAL	2
#define 	SMUGGLING_MEDIUM	3
#define 	SMUGGLING_HIGH		4

//Some parameters
#define		SMUGGLING_STATE_CHANGE_CHANCE	10		//0-1000 (int) if its 1000 it will change as soon as the time limit was passed with 0 it will never change.
#define		SMUGGLING_AMOUNT_INCR_CHANCE	150		//0-1000 (int) if its 1000 every day a smuggler will attempt to add something to the amount if 0 no other smuggler will.
#define		SMUGGLING_DAYS_BEFORE_CHANGE	150		//(int) amount of days which at least should have passed before changing state.
#define		SMUGGLING_THRESHOLD_INCREASE	3000 	//(int) amount of goods which have to be smuggled for the state to increase.
#define		SMUGGLING_MAX_GROUPS_PER_STATE	4		//(int) max amount of groups which is added per state (with 0 for none).
#define 	SMUGGLING_PAUSE_QUANTITY		3		//(int) amount of define pauses. If this is more then there are there is a larger chance of having no pause.
#define		SMUGGLING_PRICE_INC_PER_LIKE	0.002	//(float) default 0.002 increase percentage point per liking (50 gives 10%) measure with -50 ad +50.
#define		SMUGGLING_TIME_CHANCE_MULT		3		//(int) multiplier to the rand number for checking if the coastguards finds you. Higher means less chance.
#define		SMUGGLING_PERCENTAGE_BAD_INFO	50.0	//(float) 0-100 percentage of change which is calculated to see if you got bad info. 0 means you always get good info

//Debug parameters
#define		DEBUG_SMUGGLING		0		//0 means no logs, 1 means you can check if everything is set, 2 means the schedules will be logged, and you will see post event messages 3 everything is logged.


void InitIslandSmuggling()
{
	//This function sets the initial smuggling data
	//eventually it will look like this for example:
	/*
	Island.smuggling.state = 1;						This is the state of patrol on the island
	Island.smuggling.amount = 100;					This is how much is already transported to the island
	Island.smuggling.pause.0.start = 12.5;			This is a starttime of a pause
	Island.smuggling.pause.0.end = 13.75;			This is the endtime of a pause
	Island.smuggling.pause.0.name = "lunch";		This is the name of the pause
	Island.smuggling.patrolversion = 2;
	Island.smuggling.patrol.0.start = 0.0;			This is the starttime of a patrol	
	Island.smuggling.patrol.0.end = 7.75;			This is the endtime of a patrol
	Island.smuggling.patrol.0.groups = 2;			This is how many groups the patrol has
	Island.smuggling.patrol.0.name = "patrol";		This is the name of the patrol
	*/
	for(int n=0; n<ISLANDS_QUANTITY; n++) 
	{
		ref sisland = GetIslandByIndex(n);
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING Check island: "+sisland.id);
		addIslandSmugglingAmount(sisland, rand(1000)); //each island has a certain amount of goods smuggled already
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING total amount of smuggled goods: "+sisland.id+" is "+sisland.smuggling.amount);
		UpdateIslandSmugglingState(sisland);
		setIslandSmugglingDate(sisland);
		setIslandSmugglingContraband(sisland);
		setIslandSmugglingPatrols(sisland);
	}
}

void setIslandSmugglingPauses(ref sisland)
{
	//This function set the pauses for the different island. it checks the smuggling state to see how many pauses
	//need to be set.
	//If you want to add pauses make sure they are in order of start time and there can't be overlapping pauses.
	//the id doesn't matter but its nice if it also counts up, as long as they are in order of time everything goes well.
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING nation: " + GetNationIDByType(sti(sisland.smuggling_nation)) );
	if(!CheckAttribute(sisland,"smuggling.state")) return; //performance enhancement
	string id;
	//See which pauses there will be
	bool pickpauses[SMUGGLING_PAUSE_QUANTITY];
	int pick =3;
	//first check how many depending on difficulty
	if(sti(sisland.smuggling.state)>1) pick--;
	if(GetDifficulty() > 2)
	{
		if(sti(sisland.smuggling.state)>2) pick--;
		if(sti(sisland.smuggling.state)>3) pick--;
	}
	else
	{
		if(sti(sisland.smuggling.state)>3) pick--;
	}
	int left = SMUGGLING_PAUSE_QUANTITY;
	//Choose some options
	for(int n=0; n<SMUGGLING_PAUSE_QUANTITY; n++) 
	{
		if(pick==0) break;
		if(left > pick)
		{
			if(rand((left)*10) < ((pick)*10))
			{
				pickpauses[n] = TRUE;
				pick--;
			}
		}
		else
		{
			pickpauses[n] = TRUE;
			pick--;
		}
		left--;
	}
	//Apply the options
	switch(sti(sisland.smuggling_nation))
	{
		case ENGLAND:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 10.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 11.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).name = "breakfast";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 15.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 16.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "dinner";
			}
			id = 2;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 19.0+((15+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 19.5+((15+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "tea time";
			}
			/*id = 3;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 21.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 22.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "supper";
			}*/
		break;
		
		case FRANCE:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 10.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 11.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "petit déjeuner";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 15.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 16.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "déjeuner";
			}
			id = 2;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 20.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 22.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "dinner";
			}
		break;
		
		case SPAIN:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 13.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 15.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "comida";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 16.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 18.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "siësta";
			}
			id = 2;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 21.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 23.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "cena";
			}
		break;
		
		case PIRATE:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 18.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 19.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "dinner";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 21.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 23.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "private time";
			}
		break;
		
		case HOLLAND:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 9.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 10.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "ontbijt";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 15.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 16.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).name = "lunch";
			}
			id = 2;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 20.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 21.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "avondeten";
			}
		break;
		
		case PORTUGAL:
			id = 0;
			if(pickpauses[sti(id)] == TRUE)
			{

				sisland.smuggling.pause.(id).start = 13.0+((30+rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 15.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "comida";
			}
			id = 1;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 16.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).end = 18.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "siësta";
			}
			id = 2;
			if(pickpauses[sti(id)] == TRUE)
			{
				sisland.smuggling.pause.(id).start = 21.0+((rand(11)*5)/60.0);
				sisland.smuggling.pause.(id).end = 23.0+((rand(5)*5)/60.0);
				sisland.smuggling.pause.(id).name = "cena";
			}
		break;
		
		case GUEST1_NATION:
			if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
				id = 0;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start =10.0+((15+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 11.0+((15+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "frukost";
				}
				id = 1;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start = 13.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 14.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "middag";
				}
				id = 2;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start = 20.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 21.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "kvällsvard";
				}
			}
			if(GetCurrentPeriod() >= PERIOD_REVOLUTIONS){
				id = 0;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 9.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 10.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "breakfast";
				}
				id = 1;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 13.0+((rand(11)*5)/60.0);
					sisland.smuggling.pause.(id).end = 14.0+((rand(11)*5)/60.0);
					sisland.smuggling.pause.(id).name = "lunch";
				}
				id = 2;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 20.0+((rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 21.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "dinner";
				}
			}
		break;
		/*case AMERICA:
				id = 0;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 9.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 10.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "breakfast";
				}
				id = 1;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 13.0+((rand(11)*5)/60.0);
					sisland.smuggling.pause.(id).end = 14.0+((rand(11)*5)/60.0);
					sisland.smuggling.pause.(id).name = "lunch";
				}
				id = 2;
				if(pickpauses[sti(id)] == TRUE)
				{
					sisland.smuggling.pause.(id).start = 20.0+((rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 21.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "dinner";
				}
		break;*/
	}
	/*if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
		switch(sti(sisland.smuggling_nation))
		{
			case SWEDEN:
				id = 0;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start =10.0+((15+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 11.0+((15+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "frukost";
				}
				id = 1;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start = 13.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 14.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "middag";
				}
				id = 2;
				if(pickpauses[sti(id)] == TRUE){
					sisland.smuggling.pause.(id).start = 20.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).end = 21.0+((30+rand(5)*5)/60.0);
					sisland.smuggling.pause.(id).name = "kvällsvard";
				}
			break;
		}
	}*/
}

void lockIslandContraband(ref sisland)
{
	//This functions locks the contraband so it can't be removed untill unlocked.
	if(CheckAttribute(sisland,"Trade.Contraband"))
	{
		aref contrabands;
		makearef(contrabands,sisland.Trade.Contraband);
		int amountcontraband = GetAttributesNum(contrabands);
		for(int i = 0; i < amountcontraband; i++) 
		{
			string contrabandidx = GetAttributeName(GetAttributeN(contrabands,i));
			sisland.Trade.Contraband.(contrabandidx).notremove = true;
		}
	}
}

void unlockIslandContraband(ref sisland)
{
	//This function unlocks all contraband of the island so it can change again.
	if(CheckAttribute(sisland,"Trade.Contraband"))
	{
		aref contrabands;
		makearef(contrabands,sisland.Trade.Contraband);
		int amountcontraband = GetAttributesNum(contrabands);
		for(int i = 0; i < amountcontraband; i++) 
		{
			string contrabandidx = GetAttributeName(GetAttributeN(contrabands,i));
			if(CheckAttribute(sisland,"Trade.Contraband."+contrabandidx+".notremove"))
			{
				string name = "Trade.Contraband."+contrabandidx+".notremove";
				DeleteAttribute(sisland,name);
			}
		}
		setIslandSmugglingContraband(sisland); //run this in case the state did change in the meantime.
	}
}

void setContrabandCurPrice(ref sisland, int Good, int price)
{
	string attr = "Good_"+Good;
	sisland.smuggling.curprices.(attr).price = price;
	sisland.smuggling.curprices.(attr).date = GetHumanDate(GetDataYear(),GetDataMonth(),GetDataDay());
}

void removeIslandContraband(ref sisland)
{
	if(CheckAttribute(sisland,"Trade.Contraband"))
	{
		aref contrabands;
		makearef(contrabands,sisland.Trade.Contraband);
		int amountcontraband = GetAttributesNum(contrabands);
		for(int i = 0; i < amountcontraband; i++) 
		{
			string contrabandidx = GetAttributeName(GetAttributeN(contrabands,i));
			if(!CheckAttribute(sisland,"Trade.Contraband."+contrabandidx+".notremove"))
			{
				string name = "Trade.Contraband."+contrabandidx;
				DeleteAttribute(sisland,name);
				i -= 1;
				amountcontraband -= 1;
			}
		}
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING contraband reset for '" + GetAttribute(sisland, "id") + "'");
	}
}

void setIslandSmugglingContraband(ref sisland)
{
	//This function adds contraband to the island depending on the smuggling state. For now smugglers can't handle more then
	//4 pieces of contraband on an island and I don't think this should be more either.
	//Remove old contraband
	if(sisland.id == "Antigua")   					return; // We don't want to change the contraband for Antigua
	removeIslandContraband(sisland);
	if(IsIslandDisabled(sisland.id))				return; // No need to bother with uninhabited islands
	if(!CheckAttribute(sisland,"smuggling.state"))			return; // If there is no coastguard, there can't be contraband

	//Now set the new contraband based on the nation of the island.
	int idx = 1;
	switch(sti(sisland.smuggling_nation))
	{
		case ENGLAND:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_EBONY);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_COFFEE);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_PAPRIKA);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_BRICKS);
			}
		break;
		
		case FRANCE:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_SANDAL);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_COTTON);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_CINNAMON);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_MAHOGANY);
			}
		break;
		
		case SPAIN:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_ALE);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_SILK);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_TOBACCO);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_CHOCOLATE);
			}
		break;
		
		case PIRATE:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_LEATHER);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_CLOTHES);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_COTTON);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_SILK);
			}
		break;
		
		case HOLLAND:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_SUGAR);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_LINEN);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_FRUITS);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_SANDAL);
			}
		break;
		
		case PORTUGAL:
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_WINE);
			idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_MAHOGANY);
			if(sti(sisland.smuggling.state)>1)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_COPRA);
			}
			if(sti(sisland.smuggling.state)>3)
			{
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_EBONY);
			}
		break;
		
		case GUEST1_NATION:
			if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_LINEN);
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_SILK);
				if(sti(sisland.smuggling.state)>1){
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_SUGAR);
				}
				if(sti(sisland.smuggling.state)>3){
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_COFFEE);
				}
			}
			if(GetCurrentPeriod() >= PERIOD_REVOLUTIONS){
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_PAPRIKA);
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_OIL);
				if(sti(sisland.smuggling.state)>1)
				{
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_LINEN);
				}
				if(sti(sisland.smuggling.state)>3)
				{
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_ALE);
				}
			}
		break;
		/*case AMERICA:
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_PAPRIKA);
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_OIL);
				if(sti(sisland.smuggling.state)>1)
				{
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_LINEN);
				}
				if(sti(sisland.smuggling.state)>3)
				{
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND_NAME, idx, GOOD_ALE);
				}
		break;*/
	}
	/*if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS && SWEDEN_ALLOWED){
		switch(sti(sisland.smuggling_nation)){
			case SWEDEN:
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_LINEN);
				idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_SILK);
				if(sti(sisland.smuggling.state)>1){
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_SUGAR);
				}
				if(sti(sisland.smuggling.state)>3){
					idx = AddTradeGood(sisland, TRADE_TYPE_CONTRABAND, idx, GOOD_COFFEE);
				}
			break;
		}
	}*/
}

int getIslandSmugglingPatrols(ref sisland)
{
	//This function returns the amount of patrols at the current time.
	aref patrols;
	makearef(patrols,sisland.smuggling.patrol);
	int amountpatrols = GetAttributesNum(patrols);
	int numpatrols = 0;
	float time = GetTime();
	for(int i = 0; i < amountpatrols; i++) 
	{
		string patrolidx = GetAttributeName(GetAttributeN(patrols,i));
		if(time <= stf(sisland.smuggling.patrol.(patrolidx).end) && time >= stf(sisland.smuggling.patrol.(patrolidx).start))
		{
			numpatrols = sisland.smuggling.patrol.(patrolidx).groups;
			break;
		}
	}
	return numpatrols;
}

void setIslandSmugglingPatrols(ref sisland)
{
	if(!CheckAttribute(sisland,"smuggling.state")) return; //performance enhancement
	//This functions makes the patrols on the island
	if(CheckAttribute(sisland, "smuggling.patrol")) DeleteAttribute(sisland, "smuggling.patrol");
	setIslandSmugglingPauses(sisland);
	int numpatrols = 3+rand(4-sti(sisland.smuggling.state));//With a higher state there are less patrols so they are larger
	//Divide the guards over the patrols
	int coastguardnum = getIslandCoastGuardNum(sisland)/numpatrols;
	int restguards = 0;
	int groups = 0;
	int tottroops = 0;
	int duration = 0;
	int hour = 0;
	int minute = 0;
	int pause = 0;
	int amountpause = 0;
	aref pauses;
	if(CheckAttribute(sisland,"smuggling.pause"))
	{
		makearef(pauses,sisland.smuggling.pause);
		amountpause = GetAttributesNum(pauses);
	}
	bool startpatrol = true;
	//Make first few patrols
	for(int n=0; n<(numpatrols-1); n++) 
	{
		string patrol = n;
		if(pause<amountpause) string pausestring = GetAttributeName(GetAttributeN(pauses,pause));
		int maxdur = (24 - hour)/((numpatrols-n)-1);
		int hmax = maxdur+hour;
		for(int h=hour; h<(hmax); h++) 
		{
			if(startpatrol) 
			{
				tottroops = (coastguardnum+restguards);
				//Let's randomize the patrols a bit more
				if(tottroops>12)
				{
					if(sisland.smuggling.state > 2 || tottroops > makeint(((SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))*6)*0.8))
					{
						//when the state gets higher we have less randomization or when there is enough for many groups
						groups = ((tottroops/6)/2) + rand(((tottroops/6)/2)-1)+1; //it will at least be always 50% of what is possible
					}
					else
					{
						//Use this for islands with low patrol state
						groups = rand((tottroops/6)-1)+1; //it will never be 0
					}
				}
				else
				{
					//If there are troops for less then 2 groups
					if(rand(100)>10) //There is a 10% chance there will be a patrol without guards
					{
						groups = tottroops/6;
					}
					else
					{
						//making sure at least all pauses will be added to the schedule
						if(n<(numpatrols-2) || pause==(amountpause-1))
						{
							restguards = coastguardnum;
							n--;
							numpatrols--;
							break;
						}
					}
				}
				if(groups > (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))) groups = (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland)); //Limiting the amount of groups on a patrol.
				sisland.smuggling.patrol.(patrol).start = hour+(minute/60.0);
				restguards = tottroops - (groups*6);
				sisland.smuggling.patrol.(patrol).groups = 0;
				if(sti(sisland.smuggling.state)>0) sisland.smuggling.patrol.(patrol).groups = groups;
				sisland.smuggling.patrol.(patrol).name = "patrol";
				startpatrol = false;
			}
			else
			{
				if(pause<amountpause)
				{
					if(h>sti(sisland.smuggling.pause.(pausestring).start))
					{
						//If possible split up the patrol in 2 pieces
						if(groups>1) sisland.smuggling.patrol.(patrol).groups = (groups/2);
						if(tottroops > ((SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))*6)) sisland.smuggling.patrol.(patrol).groups = tottroops/12; // because we want half
						if(sisland.smuggling.patrol.(patrol).groups > (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))) sisland.smuggling.patrol.(patrol).groups = (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland));
						//Set the rest
						sisland.smuggling.patrol.(patrol).end = sisland.smuggling.pause.(pausestring).start;
						n++;
						numpatrols++;
						patrol = n;
						sisland.smuggling.patrol.(patrol).start = sisland.smuggling.pause.(pausestring).start;
						sisland.smuggling.patrol.(patrol).groups = 0;
						sisland.smuggling.patrol.(patrol).end = sisland.smuggling.pause.(pausestring).end;
						sisland.smuggling.patrol.(patrol).name = sisland.smuggling.pause.(pausestring).name;
						hour = h;
						pause++;
						if(n<(numpatrols-1)) numpatrols++; //making sure at least all pauses will be added to the schedule
						patrol = (n+1);
						sisland.smuggling.patrol.(patrol).start = sisland.smuggling.pause.(pausestring).end;
						sisland.smuggling.patrol.(patrol).groups = groups;
						sisland.smuggling.patrol.(patrol).name = "patrol";
						startpatrol = false;
						//If possible split up the patrol in 2 pieces
						if(groups>1) sisland.smuggling.patrol.(patrol).groups = (groups/2);
						if(tottroops > ((SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))*6)) 
						{
							sisland.smuggling.patrol.(patrol).groups = tottroops/12; //because we want half
							restguards = 0; //need to set this for the next loop
						}
						if(sisland.smuggling.patrol.(patrol).groups > (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))) 
						{
							sisland.smuggling.patrol.(patrol).groups = (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland));
							restguards = tottroops - ((SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))*12); //need to set this for the next loop
						}
						break;
					}
				}
				if(rand(hmax)<1 || h >= (hmax-1) || h > (24-(maxdur*0.5)))
				{
					if((h-hour)<(maxdur*0.4) || h >= (hmax-1) || h > (24-(maxdur*0.5)))
					{
						//making sure at least all pauses will be added to the schedule
						if(n<(numpatrols-2) || pause==(amountpause-1))
						{
							minute = rand(11)*5; //makes sure times look nicer
							hour = h;
							sisland.smuggling.patrol.(patrol).end = hour+(minute/60.0);
							if(sti(sisland.smuggling.patrol.(patrol).end) < sisland.smuggling.patrol.(patrol).start)
							{
								minute = 56;
								sisland.smuggling.patrol.(patrol).end = hour+(minute/60.0);
							}
							startpatrol = true;
							break;
						}
					}
				}
			}
		}
	}
	//Make last patrol to fill up last time
	if(!startpatrol) n--;
	patrol = n;
	if(CheckAttribute(sisland,"smuggling.patrol."+patrol+".start"))
	{
		sisland.smuggling.patrol.(patrol).end = 24.0;
		numpatrols--;
	}
	else
	{
		groups = (coastguardnum+restguards)/6;
		sisland.smuggling.patrol.(patrol).start = hour+(minute/60.0);
		sisland.smuggling.patrol.(patrol).end = 24.0);
		sisland.smuggling.patrol.(patrol).groups = 0;
		if(sti(sisland.smuggling.state)>0) sisland.smuggling.patrol.(patrol).groups = groups;
		if(groups > (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland))) sisland.smuggling.patrol.(patrol).groups = (SMUGGLING_MAX_GROUPS_PER_STATE * getIslandSmugglingState(sisland));
		sisland.smuggling.patrol.(patrol).name = "patrol";
	}
	//Add the version
	if(!CheckAttribute(sisland,"smuggling.patrolversion"))
	{
		sisland.smuggling.patrolversion = 1;
	}
	else
	{
		sisland.smuggling.patrolversion = sti(sisland.smuggling.patrolversion) + 1;
	}
	//Debug info
	if(DEBUG_SMUGGLING>1)
	{
		for(n=0; n<(numpatrols); n++) 
		{
			patrol = n;
			string start = GetTimeText(stf(sisland.smuggling.patrol.(patrol).start));
			string end = GetTimeText(stf(sisland.smuggling.patrol.(patrol).end));
			trace(n+" "+sisland.smuggling.patrol.(patrol).name+" starts at: "+start+" ends at: "+end+" with "+sisland.smuggling.patrol.(patrol).groups+" groups");
		}
	}
}

int getIslandCoastGuardNum(ref sisland)
{
	// This function returns the amount of guards on coast guard patrol (in total)
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING get amount of coast guard");
	int townnum = GetIslandTownsQuantity(sisland.id);
	int troops = getIslandSmugglingState(sisland)*18; // For each smuggling state at least 3 extra patrols are added
	int town_troops = 0;
	int percentage_on_coast_guard = 0;
	//Check all towns on the island
	for(int i = 1; i <= townnum; i++)
	{
		string townid = GetTownIDFromIsland(sisland.id, i);
		ref stown = GetTownFromID(townid);
		//Only towns which have the same nation contribute in the coast guard
		if(CheckAttribute(stown, "nation") && stown.nation == sisland.smuggling_nation) // PB: Fix for islands without towns
		{
			//Depending on the state of the island there are more or less in the coastguard
			percentage_on_coast_guard = getIslandSmugglingState(sisland)*5;
			town_troops = (sti(stown.troops)*(percentage_on_coast_guard/100.0));
			troops = troops + town_troops;
			if(DEBUG_SMUGGLING>2) trace("SMUGGLING check town: "+townid+" town nation: "+GetNationNameByType(makeint(stown.nation))+" percentage of troops taken: "+percentage_on_coast_guard+" amount of guards: "+town_troops);
		}
	}
	return troops;
}

void addIslandSmugglingAmount(ref sisland, int amount)
{
	// add the amount of smuggled goods.
	int oldamount = 0;
	if(CheckAttribute(sisland,"smuggling.amount")) 
	{
		oldamount = sisland.smuggling.amount;
	}
	sisland.smuggling.amount = oldamount + amount;
	if(DEBUG_SMUGGLING>0) trace("SMUGGLING total amount of smuggled goods: "+sisland.id+" is "+sisland.smuggling.amount);
}

void UpdateAllIslandSmuggling()
{
	for(int n=0; n<ISLANDS_QUANTITY; n++) 
	{
		ref sisland = GetIslandByIndex(n);
		if(CheckAttribute(sisland,"smuggling.state"))
		{
			UpdateIslandSmugglingState(sisland);
		}
	}
}

void UpdateIslandSmugglingState(ref sisland)
{
	//This function updates the smuggling state, this needs to run daily.
	int townnum = GetIslandTownsQuantity(sisland.id);
	// if there are not towns then we dont need to check
	bool bRemoveContraband = false;
	if (townnum == 0)                                     bRemoveContraband = true; //no smuggling state has to be set either
	if (sti(sisland.smuggling_nation) == PIRATE         ) bRemoveContraband = true; //no coast guard if the island is under pirate control
	if (sti(sisland.smuggling_nation) == PERSONAL_NATION) bRemoveContraband = true; //you don't want the coastguard to get you on your own island
	if (IsIslandDisabled(sisland.id))                     return; 			//no smuggling updates to unexplored islands
	if (bRemoveContraband)
	{
		removeIslandContraband(sisland);
		return;
	}
	// Check if already set or not
	if(!CheckAttribute(sisland,"smuggling.state"))
	{
		int economy = 0;
		//Check all towns on the island
		for(int n = 1; n <= townnum; n++)
		{
			string townid = GetTownIDFromIsland(sisland.id, n);
			ref stown = GetTownFromID(townid);
			int towneco = GetTownEconomy(stown)+2; //economy starts at -2 so we increase it so its never below 0
			economy = economy + towneco;
		}
		//Take the avarage economy.
		sisland.smuggling.state = (economy/townnum);
		//We dont want to start with 0 already
		if(sisland.smuggling.state < 1)
		{
			sisland.smuggling.state = 1;
		}
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING set state to: "+sisland.smuggling.state);
	}
	else
	{
		if(CheckAttribute(sisland,"smuggling.date"))
		{
			int dayspast = GetPastTime("day", sti(sisland.smuggling.date.year), sti(sisland.smuggling.date.month),sti(sisland.smuggling.date.day), stf(sisland.smuggling.date.time),
			GetDataYear(),GetDataMonth(),GetDataDay(), GetTime());
			if(dayspast >= SMUGGLING_DAYS_BEFORE_CHANGE)
			{
				if(rand(1000)<=SMUGGLING_STATE_CHANGE_CHANCE)
				{
					int samount = getAttribute(sisland,"smuggling.amount");
					int change = -1;
					if (samount>SMUGGLING_THRESHOLD_INCREASE) change = 1;
					changeIslandSmugglingState(sisland, change);
				}
			}
			else
			{
				if(rand(1000)<=SMUGGLING_AMOUNT_INCR_CHANCE)
				{
					//See if they get caught
					if(pow2(sisland.smuggling.state,2)<=rand(16))
					{
						if(CheckAttribute(sisland,"Trade.Contraband") && getIslandAmountContraband(sisland)>0)
						{
							//Make a smuggler who adds some goods to the island
							if(DEBUG_SMUGGLING>0) trace("SMUGGLING smuggler visited "+sisland.id);
							int iShipType, iCargoType, iTradeGoods, irank;
							if(CheckAttribute(sisland,"smuggler.ship")) DeleteAttribute(sisland,"smuggler.ship");
							iShipType = Force_GetShipType(7, rand(20), "trade", sti(sisland.smuggling_nation));
							sisland.smuggler.ship.type = GetShipID(iShipType);
							int contid = rand(getIslandAmountContraband(sisland)-1)+1;//to make sure the rand() wont give 0
							string contrabandid = "id" + contid;
							iTradeGoods = sisland.Trade.Contraband.(contrabandid);
							aref smuggler;
							makearef(smuggler,sisland.smuggler);
							int hullspace = GetCharacterFreeSpace(smuggler, iTradeGoods);
							//Only 60% of space is used
							int smuggle_amount = hullspace*0.6;
							addIslandSmugglingAmount(sisland, smuggle_amount);
						}
					}
				}
			}
		}
		else
		{
			setIslandSmugglingDate(sisland);
		}
	}
}

void changeIslandSmugglingState(ref sisland, int change)
{
	//This function changes the actual state of the island.
	if(CheckAttribute(sisland,"smuggling.state"))
	{
		//Set the new state
		sisland.smuggling.state = sti(sisland.smuggling.state) + change;
		if(SMUGGLING_HIGH<sisland.smuggling.state)
		{
			sisland.smuggling.state = SMUGGLING_HIGH;
		}
		if(SMUGGLING_NONE>sisland.smuggling.state)
		{
			sisland.smuggling.state = SMUGGLING_NONE;
		}
		//Set the amount on 0 again
		sisland.smuggling.amount = 0;
		//Set the time again.
		setIslandSmugglingDate(sisland);
	}
	else
	{
		sisland.smuggling.state = SMUGGLING_NORMAL;
	} 
	string logTitle, logEntry,SmugglingState;
	// DeathDaisy: Add smuggling state level info to rumours.
	if(sisland.smuggling.state == SMUGGLING_LOW) SmugglingState = "lax";
	if(sisland.smuggling.state == SMUGGLING_NORMAL) SmugglingState = "normal";
	if(sisland.smuggling.state == SMUGGLING_MEDIUM) SmugglingState = "tight";
	if(sisland.smuggling.state == SMUGGLING_HIGH) SmugglingState = "very tight";
	
	if(change>0) 
	{
		logTitle = XI_ConvertString(sisland.name)+" "+TranslateString("","Increase_Patrol");
		logEntry = TranslateString("","Increase_Message1")+" "+XI_ConvertString(sisland.name)+TranslateString("Increase_Message2",SmugglingState)+".";
		WriteNewLogEntry(logTitle, logEntry, "General", false);
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING increased state of "+sisland.id+" to: "+sisland.smuggling.state);
	}
	if(change<0) 
	{
		logTitle = XI_ConvertString(sisland.name)+" "+TranslateString("","Decrease_Patrol");
		logEntry = TranslateString("","Decrease_Message1")+" "+XI_ConvertString(sisland.name)+TranslateString("Decrease_Message2",SmugglingState)+".";
		WriteNewLogEntry(logTitle, logEntry, "General", false);
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING decreased state of "+sisland.id+" to: "+sisland.smuggling.state);
	}
	if(change==0) 
	{
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING state of "+sisland.id+" remained at: "+sisland.smuggling.state);
	}
	setIslandSmugglingContraband(sisland);
	setIslandSmugglingPatrols(sisland);
}

void setIslandSmugglingDate(ref sisland)
{
	//Set the date when the state was last changed. If none is set yet make one up in the range where it can change.
	if(!CheckAttribute(sisland,"smuggling.date"))
	{
		int extra_days = -1*rand(SMUGGLING_DAYS_BEFORE_CHANGE);
		sisland.smuggling.date.year = GetAddingDataYear(0,0,extra_days);
		sisland.smuggling.date.month = GetAddingDataMonth(0,0,extra_days);
		sisland.smuggling.date.day = GetAddingDataDay(0,0,extra_days);
		sisland.smuggling.date.time = GetTime();
	}
	else
	{
		sisland.smuggling.date.year = GetDataYear();
		sisland.smuggling.date.month = GetDataMonth();
		sisland.smuggling.date.day = GetDataDay();
		sisland.smuggling.date.time = GetTime();
	}
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING date of last change is: "+sisland.smuggling.date.day+"-"+sisland.smuggling.date.month+"-"+sisland.smuggling.date.year+" (dd-mm-yyyy)");
}

int getIslandAmountContraband(ref sisland)
{
	//This returns how many contraband items an island has.
	int maxcontraband = 4;
	for(int n = 1; n <= maxcontraband; n++)
	{
		string id = "Trade.Contraband.id"+n;
		if(!CheckAttribute(sisland,id))
		{
			return (n-1);
		}
	}
	return maxcontraband;
}

int getIslandSmugglingState(ref sisland)
{
	//This returns the smuggling state of the island.
	int state = 0;
	if(CheckAttribute(sisland,"smuggling.state")) state = sti(sisland.smuggling.state);
	return state;
}

float getCoastGuardEncounterChance()
{
	//returns the chance of getting caught.
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING get chance to get caught");
	ref PChar = GetMainCharacter();
	int patrols = getIslandSmugglingPatrols(Islands[GetCharacterCurrentIsland(PChar)]);
	float chance_get_caught = 100.0;
	//Check for patrols
	if(patrols == 0)
	{
		chance_get_caught = 0.0;
	}
	else
	{
		chance_get_caught = 100.0-((1.0/patrols)*100.0);
		if(patrols == 1) chance_get_caught = 35.0;
	}
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING patrols: "+patrols+" chance: "+chance_get_caught);
	//Check if the governor knows anything to counteract your actions:
	if(CheckAttribute(Pchar,"quest.smuggling_guild.governor_quest.nation"))
	{
		if(GetSmugglingNation() == sti(pchar.quest.smuggling_guild.governor_quest.nation))
		{
			chance_get_caught = chance_get_caught * 1.3;
		}
		if(CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.made_first_report"))
		{
			if(GetSmugglingNation() == sti(pchar.quest.smuggling_guild.governor_quest.nation))
			{
				chance_get_caught = chance_get_caught * 1.45;
			}
			else
			{
				chance_get_caught = chance_get_caught * 1.2;
			}
		}
	}
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING after governor changes chance: "+chance_get_caught);
	//Check for skill
	chance_get_caught = chance_get_caught * (1.0-(CalcCharacterSkill(PChar,SKILL_SNEAK)/20.0));
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING skill: "+CalcCharacterSkill(PChar,SKILL_SNEAK)+" chance: "+chance_get_caught);
	//Check for day/night
	if(!isDay()) 
	{
		float moonintensity = getMoonIntensity(); //between 0 and 1 with 1 being max brightness
		float multnight = 1 - (0.25 * (1-moonintensity));
		chance_get_caught = chance_get_caught * multnight;
	}
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING isday: "+isDay()+" chance: "+chance_get_caught);
	//Check for weather
	aref aCurWeather = GetCurrentWeather();
	if(aCurWeather.id == "Blue Sky") chance_get_caught = chance_get_caught * 1.2;
	if(aCurWeather.id == "Day Storm") chance_get_caught = chance_get_caught * 0.5;
	if(aCurWeather.id == "Rainy") chance_get_caught = chance_get_caught * 0.8;
	if(aCurWeather.id == "Heavy Rain") chance_get_caught = chance_get_caught * 0.6;
	if(aCurWeather.id == "Stormy") chance_get_caught = chance_get_caught * 0.4;
	if(aCurWeather.id == "Heavy Storm") chance_get_caught = chance_get_caught * 0.2;
	if(aCurWeather.id == "Foggy") chance_get_caught = chance_get_caught * 0.8;
	if(aCurWeather.id == "Heavy Fog") chance_get_caught = chance_get_caught * 0.2;
	if(aCurWeather.id == "Super Fog") chance_get_caught = chance_get_caught * 0.05;
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING weather: "+aCurWeather.id+" chance: "+chance_get_caught);
	//Check for difficulty
	int difficulty = GetDifficulty();
	chance_get_caught = chance_get_caught * (0.8 + (difficulty*0.1)); // is between 1 and 4 and with 2 it should give the same chance and if higher the chance should go up again.
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING difficulty: "+difficulty+" chance: "+chance_get_caught);
	//Check perks
	if(CheckPerkForGroup(Pchar,"ImproveSmuggling")) chance_get_caught = chance_get_caught * 0.95;
	if(CheckPerkForGroup(Pchar,"AdvanceSmuggling")) chance_get_caught = chance_get_caught * 0.90;
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING perks ImproveSmuggling: "+CheckPerkForGroup(Pchar,"ImproveSmuggling")+" AdvanceSmuggling "+CheckPerkForGroup(Pchar,"AdvanceSmuggling")+" chance: "+chance_get_caught);
	if(DEBUG_SMUGGLING>0) trace("SMUGGLING chance get caught: "+chance_get_caught);
	return chance_get_caught;
}

string GetPatrolText(ref sisland)
{
	//This function returns a text describing the patrols on the island.
	aref patrols;
	makearef(patrols,sisland.smuggling.patrol);
	int amountpatrols = GetAttributesNum(patrols);
	string text = "";
	//Loop trough all patrols and make a nice text.
	for(int i = 0; i < amountpatrols; i++) 
	{
		string patrol = GetAttributeName(GetAttributeN(patrols,i));
		string start = GetTimeText(stf(sisland.smuggling.patrol.(patrol).start));
		string end = GetTimeText(stf(sisland.smuggling.patrol.(patrol).end));
		if (sti(sisland.smuggling.patrol.(patrol).groups) == 0) // PB: Don't mention the groups for breaks
			text += sisland.smuggling.patrol.(patrol).name+" from "+start+" till "+end + GlobalStringConvert("newline");
		else
			text += sisland.smuggling.patrol.(patrol).name+" from "+start+" till "+end+" with "+sisland.smuggling.patrol.(patrol).groups+" groups" + GlobalStringConvert("newline");
	}
	return text;
}

string GetPatrolTimeText(ref sisland, int best)
{
	aref patrols;
	makearef(patrols,sisland.smuggling.patrol);
	if (GetAttributesNum(patrols) > 0) // PB: Just in case there are no patrols at all
	{
		string patrol = GetAttributeName(GetAttributeN(patrols,best));
		string start  = GetTimeText(stf(sisland.smuggling.patrol.(patrol).start));
		string end    = GetTimeText(stf(sisland.smuggling.patrol.(patrol).end));
		return TranslateString("","between") +" "+ start +" "+ TranslateString("","and") +" "+ end;
	}
	return "";
}

int GetBestSmugglingtime(ref sisland,ref chr)
{
	//This Function returns the best time to smuggle
	// DeathDaisy: Added character ref and extra modifiers
	//First let's see if we get false information or not
	int cLuck = CalcCharacterSkill(chr,SKILL_SNEAK); // DeathDaisy: Changed from float to int since it will always be a round number
	int cLeadership = CalcCharacterSkill(chr,SKILL_LEADERSHIP);
	int badinfo_chance = makeint((SMUGGLING_PERCENTAGE_BAD_INFO/100)*(((11-cLuck)*5)-((11-cLeadership)*2)));
	if(CheckPerkForGroup(chr,"Trustworthy")) badinfo_chance = badinfo_chance*0.7;
	if(CheckPerkForGroup(chr,"IronWill")) badinfo_chance = badinfo_chance*0.8;
	/*if(CheckCharacterPerk(chr,"Charisma")) badinfo_chance = badinfo_chance*0.5;
	if(CheckCharacterPerk(chr,"WitCharm")) badinfo_chance = 0;*/
//	trace("chance = "+badinfo_chance);
	int besttime = 0;
	aref patrols;
	makearef(patrols,sisland.smuggling.patrol);
	int amountpatrols = GetAttributesNum(patrols);
	if(rand(99) >= badinfo_chance)
	{
		int bestgroups = 9999;
		bool atnight = FALSE;
		//Loop trough all patrols and make a nice text.
		for(int i = 0; i < amountpatrols; i++) 
		{
			string patrol = GetAttributeName(GetAttributeN(patrols,i));
			int groups = sti(sisland.smuggling.patrol.(patrol).groups);
			float starttime = stf(sisland.smuggling.patrol.(patrol).start);
			if(groups < bestgroups)
			{
				besttime = i;
				bestgroups = groups;
				if(starttime < 6.0 || starttime > 22.0)
				{
					atnight = TRUE;
				}
				else
				{
					atnight = FALSE;
				}
			}
			else
			{
				if(groups == bestgroups)
				{
					if(atnight == FALSE)
					{
						if(starttime < 6.0 || starttime > 22.0)
						{
							besttime = i;
							bestgroups = groups;
							atnight = TRUE;
						}
					}
				}
			}
		}
	}
	else
	{
		besttime = rand(amountpatrols-1);
	}
	return besttime;
}

int getSmugglingState(ref sisland)
{
	return sti(sisland.smuggling.state);
}

string getSmugglingStateDesc(int state)
{
	//This function returns a nice text for the patrolling state.
	switch (state)
	{
		case SMUGGLING_NONE:
			return TranslateString("","Patrol_None");
		break;
		
		case SMUGGLING_LOW:
			return TranslateString("","Patrol_Low");
		break;
		
		case SMUGGLING_NORMAL:
			return TranslateString("","Patrol_Normal");
		break;
		
		case SMUGGLING_MEDIUM:
			return TranslateString("","Patrol_Medium");
		break;
		
		case SMUGGLING_HIGH:
			return TranslateString("","Patrol_High");
		break;
	}
	return TranslateString("","Patrol_Normal");
}

string CreatePatrolBook(ref sisland)
{
	//This function creates the patrol book
	string id;
	//If there is no patrol set we return empty handed
	if(Checkattribute(sisland,"smuggling.patrolversion"))
	{
		id = "patrolbook_"+sisland.id+"_"+sisland.smuggling.patrolversion);
		//We got the id so if the book already exist we can exit
		if(GetItemIndex(id) == -1) //Book already exists
		{
			int itemindex = findemptyItem();
			//Add an item to the game for this book
			AddItem(itemindex,id, "",     13, 7,   0.05,  0,   2, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  1); //Levis: price = 2 so it can be tossed
			ChangeItemGroup(itemindex,BOOK_ITEM_TYPE);
			//Set some move attributes to the book so it can display right in the interface.
			ref genitm;
			int genitmIndex = itemindex;
			makeref(genitm,Items[genitmIndex]);
			genitm.name			= "itmname_patrolbook"; //All patrol books use the same template
			genitm.describe		= "itmdescr_patrolbook"; //All patrol books use the same template
			genitm.text			= "patrolbook"; //All patrol books use the same template
			genitm.island		= sisland.name;	
			genitm.version		= sisland.smuggling.patrolversion;
			genitm.state		= getSmugglingStateDesc(sti(sisland.smuggling.state));
			genitm.schedule		= GetPatrolText(sisland);
			genitm.UnlockedPerk = "ImproveSmuggling"; 
		}
	}
	else
	{
		trace("SMUGGLING ERROR: Can't create book because there is no patrol schedule on "+sisland.id);
	}
	return id;
}

//Functions for more anoying coast guard

void StartCoastGuardCheck()
{
	if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Start event");
	SetEventHandler("CheckCoastGuard","CheckCoastGuard",1);
	float chance_get_caught = getCoastGuardEncounterChance();
	Characters[GetMaincharacterIndex()].postevent.CheckCoastGuard = true;
	PostEvent("CheckCoastGuard",5000,"f",chance_get_caught);
}

void CheckCoastGuard()
{
	ref PChar = GetMainCharacter();
	float chance_get_caught = GetEventData();
	if(PChar.location == PChar.quest.contraband.CurrentPlace && !dialogRun && !dialogSelf)
	{
		if(Rand((100*SMUGGLING_TIME_CHANCE_MULT))<=chance_get_caught)
		{
			if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Coastguard found you!");
			Lai_QuestDelay("Rand_ContrabandInterruption",1.0);
			StopCoastGuardCheck();
		}
		if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING caught chance is "+chance_get_caught+" in "+(100*SMUGGLING_TIME_CHANCE_MULT));
		if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Evaded the Coastguard (for now)");
	}
	else{
		if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING caught chance paused"); 
	}
	PostEvent("CheckCoastGuard",5000,"f",chance_get_caught);
}

void StopCoastGuardCheck()
{
	if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Stop event");
	DelEventHandler("CheckCoastGuard","CheckCoastGuard");
//	DelEventHandler("PauseCoastGuardCheck","PauseCoastGuardCheck");
	DeleteAttribute(GetMainCharacter(),"postevent.CheckCoastGuard");
}

//Interface function
//This makes sure fast traveling is disabled when opium smuggling is active so we can't skip the guards
bool AllowFastTravelForSmuggling()
{
	ref pchar = GetMainCharacter();
	if(CheckCharacterItem(pchar,"opium"))
	{
		if(DEBUG_SMUGGLING>0) trace("FAST TRAVEL disabled due to carrying opium");
		return false;
	}
	if(CheckAttribute(pchar,"quest.smuggling.spotted"))
	{
		if(DEBUG_SMUGGLING>0) trace("FAST TRAVEL disabled because you were spotted smuggling");
		return false;
	}
	return true;
}

//Smuggling Guild stuff
void addPlayerSmugglingAmount(ref chr, int total_smuggle)
{
	int amount = CheckSmugglingAmount(chr);
	chr.quest.smuggling_guild.smuggle_amount = amount + total_smuggle;
}

int CheckSmugglingAmount(ref chr)
{
	if(!CheckAttribute(chr,"quest.smuggling_guild.smuggle_amount")) chr.quest.smuggling_guild.smuggle_amount = 0;
	return sti(chr.quest.smuggling_guild.smuggle_amount);
}

int CheckSmugglerLiking(ref chr)
{
	//The liking is between 0 and 100 with 100 being the best
	if(!CheckAttribute(chr,"quest.smuggling_guild.liking")) chr.quest.smuggling_guild.liking = 50;
	return sti(chr.quest.smuggling_guild.liking);
}

void ChangeSmugglerLiking(ref chr, int change)
{
	int liking = CheckSmugglerLiking(chr);
	chr.quest.smuggling_guild.liking = liking + change;
	if(chr.quest.smuggling_guild.liking > 100) chr.quest.smuggling_guild.liking = 100;
	if(chr.quest.smuggling_guild.liking < 0 ) chr.quest.smuggling_guild.liking = 0;
}

void GetSmugglingGuildMembers(int NumMembers, string Category, string Dialog)
{
	int chosen = 0;
	int chridx = 0;
	ref pchar = GetMainCharacter();
	if(DEBUG_SMUGGLING>0) trace("SMUGGLING GUILD MEMBERS: Start picking "+NumMembers+" new members for the guild");
	string index = "";
	string sLocName = "";
	string sIslandName = "";

	while (chosen < NumMembers) {
		chridx = rand(MAX_CHARACTERS);
		ref chr = GetCharacter(chridx);

		if (GetAttribute(chr, "id") == "0" || GetAttribute(chr, "id") == "-1")	continue; // PB: Invalid character, no point checking further
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS Character index: " + chridx + ", name = " + GetMySimpleName(chr) + " (" + chr.id + ")");
		
		if (bAllies(chr))														continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass player party check");
		
		if (CheckAttribute(chr,"Dialog.Filename.SmugglingGuild"))				continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass guildmember already check");

		if (CharacterIsDead(chr))												continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass still alive");

		sLocName = GetAttribute(chr,"location");
		if (sLocName == "-1" || sLocName == "" || sLocName == "none")			continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass location");
		
		sIslandName = FindIslandByLocation(sLocName);
		if (sIslandName == "")													continue;
		if (sIslandName == sLocName)											continue; // This avoids captains at sea and fort commanders
		if (IsIslandDisabled(sIslandName))										continue;
		if (GetAttribute(GetIslandByID(sIslandName),"skipCR") == "1")			continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass island check");

		if (isSoldier(chr) != UNKNOWN_NATION)									continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass soldier check");

		if (CheckAttribute(chr,"questchar"))									continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass quest character check");

	//	if (CheckAttribute(chr,"quest.officertype"))							continue; // PB: This is not safe anymore due to the Leveling system!
		if (GetAttribute(chr,"isOfficer") == true)								continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass officer check");

		if (GetAttribute(chr,"chr_ai.type") == LAI_TYPE_MERCHANT)				continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass merchant check");

		if (GetAttribute(chr,"Dialog.Filename") == "governor.c")				continue;
		if (GetAttribute(chr,"Dialog.Filename.GroupDialog") == "governor.c")	continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass govenor check");

		if (GetAttribute(chr,"Dialog.Filename") == "Smuggler_OnShore_dialog.c")	continue;
		if (GetAttribute(chr,"Dialog.Filename") == "Agent_dialog.c")			continue;
		if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass smuggler check");

	//	if (GetAttribute(chr,"abordagemode") != "1")							continue; // PB: This can only be disabled for officers, who aren't valid clients
	//	if(DEBUG_SMUGGLING>2) trace("SMUGGLING GUILD MEMBERS pass boardingmode check");

		if (chr.lastname == "") {
			if(DEBUG_SMUGGLING>0) trace("SMUGGLING GUILD MEMBERS RENAMED: "+GetMySimpleName(chr));
			SetRandomNameToCharacter(chr);
		}

		index = Category + chosen;
		pchar.quest.smuggling_guild.people.(Category).(index) = chr.id;
		pchar.quest.smuggling_guild.people.(Category).(index).name = GetMySimpleName(chr);
		pchar.quest.smuggling_guild.people.(Category).(index).location = GetPrettyLocationName(chr.location);
		pchar.quest.smuggling_guild.people.(Category).(index).island = GetIslandNameByLocationID(chr.location);
		if(DEBUG_SMUGGLING>0) trace("SMUGGLING GUILD MEMBERS PICKED: "+pchar.quest.smuggling_guild.people.(Category).(index).name+" at: "+pchar.quest.smuggling_guild.people.(Category).(index).location+" ("+chr.location+") on: "+pchar.quest.smuggling_guild.people.(Category).(index).island));
		chr.Dialog.Filename.SmugglingGuild = Dialog;
		chosen += 1;
	}
}

bool CheckGovernorAllInfo()
{
	ref pchar = getMainCharacter();
	if(!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.gave_second_report")) return false;
	if(!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.gave_buyers_list")) return false;
	if(!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.gave_first_report")) return false;
	if(CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.final_report")) return false;
	return true;
}

//Opium Quest Functions
void GuardsAttackOpium()
{
	if(DEBUG_SMUGGLING>0) trace("OPIUM SMUGGLING start fight");
	int radius = 50;
	FindGuards(radius); //Get all in a certain radius;
	ref pchar = getMainCharacter();
	aref Guards; makearef(Guards,pchar.quest.opium_smuggling.guards);
	for(int i=0;i<GetAttributesNum(Guards);i++)
	{
		aref guard = GetAttributeN(Guards,i);
		//Filter out other info
		if(CheckAttribute(guard,"idx"))
		{
			ref sld = getCharacter(sti(guard.idx));
			LAi_SetActorType(sld);
			if(DEBUG_SMUGGLING>2) trace("OPIUM SMUGGLING guard "+sld.id+" attack");
			LAi_group_MoveCharacter(sld, "OpiumAmbush");
		}
	}
	LAi_group_FightGroups(LAI_GROUP_PLAYER, "OpiumAmbush", true);
	//Let's make sure the normal guards won't attack them
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "OpiumAmbush", LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction(GetCurrentSoldierGroup(),"OpiumAmbush",LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction("OpiumAmbush",GetCurrentSoldierGroup(),LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
}

int FindGuards(int radius)
{
	//TODO: Used FindNearCharacters here instead
	int Charnum = GetCharacterIndex("Boat1234");
	int closeidx = -1;
	ref pchar = getMainCharacter();
	String guardidx = "Guard";
	int guardnum = 0;
	bool soldier;
	float x,y,z,gx,gy,gz,dist;
	if(DEBUG_SMUGGLING>0)trace("OPIUM SMUGGLING start check to see if guards are present within radius "+radius);
	for(int i=1;i<Charnum;i++)
	{
		ref chr = GetCharacter(i);
		soldier = false;
		if(CheckAttribute(chr,"issoldier"))
		{
			if(chr.issoldier == "1") soldier = true;
		}
		if(soldier)
		{
			if(CheckAttribute(chr,"location"))
			{
				if(chr.location == pchar.location)
				{
					if(!CharacterIsDead(chr))
					{
						GetCharacterPos(pchar,&x,&y,&z);
						GetCharacterPos(chr,&gx,&gy,&gz);
						dist = sqrt(sqr(x - gx) + sqr(y - gy) + sqr(z - gz));
						guardidx = "Guard"+closeidx;
						if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING ID: "+chr.id);
						if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING DISTANCE: "+dist);
						if(dist<=radius)
						{
							if(CheckAttribute(pchar,"quest.opium_smuggling.guards."+guardidx))
							{
								if(dist < stf(pchar.quest.opium_smuggling.guards.(guardidx).dist))
								{
									closeidx = guardnum;
									if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING SET AS CLOSEST");
								}
							}
							else
							{
								closeidx = guardnum;
							}
							guardidx = "Guard"+guardnum;
							guardnum++;
							pchar.quest.opium_smuggling.guards.(guardidx).idx = i;
							pchar.quest.opium_smuggling.guards.(guardidx).dist = dist;
						}
					}
				}
			}
		}
	}
	pchar.quest.opium_smuggling.guards.num = guardnum;
	if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING return: "+closeidx);
	return closeidx;
}

int getOpiumCaughtChance()
{
	ref Pchar = GetMainCharacter();
	if (GetAttribute(Pchar         , "vcskip") == true)	return 0;
	if (GetAttribute(LoadedLocation, "vcskip") == true)	return 0;
	int chance = 100;
	//Take difficulty into account:
	chance = chance - (50-GetDifficulty()*10);
	float mult = 1;
	//Take smuggling perks into account:
	if(CheckPerkForGroup(Pchar,"ImproveSmuggling")) mult = mult - 0.10;
	if(CheckPerkForGroup(Pchar,"AdvanceSmuggling")) mult = mult - 0.15;
	//At night you wont be detected that easy
	if(!isDay()) 
	{
		mult = mult - 0.5;
	}
	chance = makeint(round(chance*mult));
	return chance;
}

int GetOpiumPrice()
{
	return 100;
}

int GetOpiumSellPrice()
{
	ref pchar=GetMainCharacter();
	int retval = CheckSmugglerLiking(pchar)+sti(pchar.rank)*10+GetOpiumPrice();
	return retval;
}

int getOpiumFine()
{
	int fine = 1000;
	ref pchar = getMainCharacter();
	if(CheckAttribute(pchar,"items.opium"))
	{
		fine = makeint(round(sti(pchar.items.opium) * GetOpiumPrice() * 1.25));
	}
	return fine;
}

bool CheckOpiumBuyer(ref Buyer)
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"quest.opium_smuggling.lastbuyer")) pchar.quest.opium_smuggling.lastbuyer = "";
	if(Buyer.id == pchar.quest.opium_smuggling.lastbuyer) return false;
	if(CheckAttribute(pchar,"quest.opium_smuggling.questgiven")) return false;
	return true;
}

void UseOpium(ref User)
{
	//Remove 1 opium
	ref pchar = GetMainCharacter();
//	TakeItemFromCharacter(User, "opium"); // PB: This is already handled elsewhere
	//Lets check all effects
	OpiumEffects(User);
	//Set Opium Sickness
	float sickness = 0.2;
	if(CheckAttribute(pchar,"quest.opium_use.opiumsickness")) sickness = sickness + stf(User.quest.opium_use.opiumsickness);
	User.quest.opium_use.opiumsickness = sickness;
	//Remove the opium sickness in X days.
	int opiumuses = 0;
	if(CheckAttribute(pchar,"quest.opium_use.amount")) opiumuses = sti(pchar.quest.opium_use.amount);
	opiumuses++;
	int days = makeint(sickness*10/2);
	pchar.quest.opium_use.amount = opiumuses;
	string questname = "remove_opium_effect_"+opiumuses;
	pchar.quest.opium_use.users.(questname).userid = User.id;
	pchar.quest.(questname).win_condition.l1 = "Timer";
	pchar.quest.(questname).win_condition.l1.date.day = GetAddingDataDay(0, 0, days);
	pchar.quest.(questname).win_condition.l1.date.month = GetAddingDataMonth(0, 0, days);
	pchar.quest.(questname).win_condition.l1.date.year = GetAddingDataYear(0, 0, days);
	pchar.quest.(questname).win_condition = "remove_opium_effect";
}

void OpiumEffects(ref User)
{
	float a,b,c;
	GetCharacterPos(User, &a, &b, &c);
	int effect = rand(100);
	
	if(effect <=10)
	{
		//decrease max health
		float Bonus = -5 - sti(User.rank)/5;
		if(CheckAttribute(User, "HPBonus")) Bonus = Bonus + stf(User.HPBonus);
		User.HPBonus = Bonus;
		Logit(TranslateString("","Opium lose health"));
		return;
	}
	
	if(effect <=60)
	{
		//unlock random perk
		aref perklist; makearef(perklist, ChrPerksList.list);
		int num = GetAttributesNum(perklist);
		string perkname;
		perkname = GetAttributeName(GetAttributeN(perklist, rand(num-1)));
		if(!UnlockPerkCharacter(User, perkname))
		{
			Logit(TranslateString("","Nothing happened"));
		}
		return;
	}
	
	if(effect <=75)
	{
		//Get a skillpoint
		CreateParticleSystem("stars_short" , a, b+1.0, c, 0.0, 0.0, 0.0, 1);
		User.perks.FreePoints = makeint(User.perks.FreePoints) + 1;
		Logit(TranslateString("","Opium Skillpoint"));
		return;
	}
	
	if(effect <=80)
	{
		User.chr_ai.poison = 150;
		Logit(TranslateString("","Opium Poison"));
		return;
	}
	
	if(effect >=80)
	{
		//decrease max health
		Logit(TranslateString("","Nothing happened"));
		return;
	}
}

//Smuggling Quest Functions

void SetCoastalGuardPursuit()
{
	ref Pchar = GetMainCharacter();
	if(DEBUG_SMUGGLING>2) trace("SMUGGLING move coastguard to the sea");
	Group_SetTaskAttack("Coastal_Guards", PLAYER_GROUP, true);
	Group_LockTask("Coastal_Guards");
	Group_SetPursuitGroup("Coastal_Guards", PLAYER_GROUP);
	Group_SetAddress("Coastal_Guards", Islands[GetCharacterCurrentIsland(Pchar)].id, "", "");
	// PB: Ensure they're deleted after escaping -->
	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition.l1 = "MapEnter";
	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition = "Rand_ContrabandInterruptionAtSeaEnded";
	// PB: Ensure they're deleted after escaping <--
}

void StopCoastalGuardPursuit()
{
	ref Pchar, rCap1, rCap2, rCap3;
	Pchar = GetMainCharacter();
	rCap1 = CharacterFromID("Coastal_Captain01");
	rCap2 = CharacterFromID("Coastal_Captain02");
	rCap3 = CharacterFromID("Coastal_Captain03");

	group_DeleteGroup("Coastal_Guards");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain01"), "None", "", "");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain02"), "None", "", "");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain03"), "None", "", "");
}

string FindCoastGuardLocator(bool BySea)
{
	aref reloads, reloadref;
	int i;
	if(BySea)
	{
		//By Sea
		ref island = &Islands[FindIsland(loadedlocation.island)];
		makearef(reloads,island.reload);
		for(i=0;i<GetAttributesNum(reloads);i++)
		{
			reloadref = GetAttributeN(reloads,i);
			if(reloadref.go == loadedlocation.id)
			{
				return reloadref.emerge;
			}
		}
		
	}
	else
	{
		//By Land
		makearef(reloads,loadedlocation.reload);
		for(i=0;i<GetAttributesNum(reloads);i++)
		{
			reloadref = GetAttributeN(reloads,i);
			if(reloadref.label == "Jungle.")
			{
				return reloadref.name;
			}
		}
	}
	return "";
}

void CreateCoastGuardPatrol()
{
	ref PChar = GetMainCharacter();
	ref sld;
	if(DEBUG_SMUGGLING>1) trace("SMUGGLING load Coastguard patrol and pursuit");
	//Levis add smuggling perk -->
	float largegroup_chance = 100.0;
	if(CheckPerkForGroup(Pchar,"ImproveSmuggling"))
	{
		largegroup_chance = largegroup_chance*0.5;
	}
	largegroup_chance = 100;
	//<-- smuggling perk
	string group = "reload";
	string locator;
	int fromseachance = 50;
	if(CheckPerkForGroup(Pchar,"AdvanceSmuggling"))
	{
		fromseachance = fromseachance*0.5;
	}
	if(rand(100)<fromseachance)
	{
		locator = FindCoastGuardLocator(true);
		Pchar.quest.contraband.fromsea = true;
	}
	else
	{
		locator = FindCoastGuardLocator(false);
		Pchar.quest.contraband.fromsea = false;
	}
	Pchar.quest.contraband.locator = locator;
	Pchar.quest.contraband.group = group;
	int numguards = 6;
	String IDXname;
	if(rand(100)<=largegroup_chance) numguards = 2;
	//Generate the Captain
	//sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.75, GetRandomModelForTypeNation(true, "Land_Officers", GetSmugglingNation()), group, locator);
	sld = LAi_CreateFantomCharacterExOt(false, 0, true, OFFIC_TYPE_GUARD, GetRandomRank(true, OFFIC_TYPE_GUARD, (4-GetDifficulty())), true, 0.75, GetRandomModelForTypeNation(true, "Land_Officers", GetSmugglingNation()), group, locator);
	sld.Dialog.Filename = "Coastal Guards_dialog.c";
	sld.Dialog.CurrentNode = "First time";
	Pchar.quest.contraband.SoldierIDX1 = sld.index;
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "CoastalGuards");
	LAi_ActorDialog(sld, Pchar, "", 120, 0);
	//Generate the Guards
	for (int i = 2; i <= numguards; i++)
	{
		IDXname = "SoldierIDX"+i;
		//sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.75, GetRandomModelForTypeNation(true, "Soldiers", GetSmugglingNation()), group, locator);
		sld = LAi_CreateFantomCharacterExOt(false, OFFIC_TYPE_GUARD, GetRandomRank(true, OFFIC_TYPE_GUARD, (4-GetDifficulty())), true, 0.75, GetRandomModelForTypeNation(true, "Soldiers", GetSmugglingNation()), group, locator);
		Pchar.quest.contraband.(IDXname) = sld.index;
		LAi_SetActorType(sld);
		LAi_group_MoveCharacter(sld, "CoastalGuards");
		LAi_ActorFollow(sld, Pchar, "", 120);
	}
	//Generate the ships
	Group_CreateGroup("Coastal_Guards");
	GenerateQuestShip("Coastal_Captain01", GetSmugglingNation()); // PB: Use Generic Function
	Group_AddCharacter("Coastal_Guards", "Coastal_Captain01");
	Group_SetGroupCommander("Coastal_Guards", "Coastal_Captain01");

	if(GetCompanionQuantity(Pchar) > 1 || makeint(Pchar.rank) > 5)
	{
		GenerateQuestShip("Coastal_Captain02", GetSmugglingNation()); // PB: Use Generic Function
		Group_addCharacter("Coastal_Guards", "Coastal_Captain02");
	}

	if(GetCompanionQuantity(Pchar) > 2 || makeint(Pchar.rank) > 8)
	{
		GenerateQuestShip("Coastal_Captain03", GetSmugglingNation()); // PB: Use Generic Function
		Group_addCharacter("Coastal_Guards", "Coastal_Captain03");
	}
	/*if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Move the patrol to the land");
	ref PChar = GetMainCharacter();
	ref sld;

	String IDXname;
	for (int i = 1; i <= 6; i++)
	{
		IDXname = "SoldierIDX"+i;
		if(CheckAttribute(Pchar,"quest.contraband."+IDXname))
		{
			sld = getCharacter(sti(Pchar.quest.contraband.(IDXname)));
			LAi_CharacterLogin(sld, PChar.location);
			CreateCharacter(sld);
			TeleportCharacterToLocator(sld, Pchar.quest.contraband.group, Pchar.quest.contraband.locator);
			if(CheckAttribute(sld,"condition") && sld.condition=="reload") { DeleteAttribute(sld,"condition"); }
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			if(i == 1) LAi_ActorDialog(sld, Pchar, "", 120, 0);
			else LAi_ActorFollow(sld, Pchar, "", 120);
		}
	}*/
}

void CoastGuardPatrolGoAway()
{
	if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Patrol should go away again!");
	ref PChar = GetMainCharacter();
	ref sld;

	String IDXname;
	for (int i = 1; i <= 6; i++)
	{
		IDXname = "SoldierIDX"+i;
		if(CheckAttribute(Pchar,"quest.contraband."+IDXname))
		{
			sld = getCharacter(sti(Pchar.quest.contraband.(IDXname)));
			ChangeCharacterAddressGroup(sld,"","","");
		}
	}
}

void CoastGuardPatrolRemove()
{
	if(DEBUG_SMUGGLING>1) TraceAndLog("SMUGGLING Patrol should go away again!");
	ref PChar = GetMainCharacter();
	ref sld;

	String IDXname;
	for (int i = 1; i <= 6; i++)
	{
		IDXname = "SoldierIDX"+i;
		if(CheckAttribute(Pchar,"quest.contraband."+IDXname))
		{
			sld = getCharacter(sti(Pchar.quest.contraband.(IDXname)));
			LAi_ActorRunToLocator(sld,Pchar.quest.contraband.group,Pchar.quest.contraband.locator,"Coast Guard Away",60);
		}
	}
}

void PlaceSmugglersOnShore(string LocationId)
{
	ref Smuggler, PChar;

	PChar = GetMainCharacter();

	// PB: Rewritten -->
	for (int i = 1; i <= 3; i++)
	{
		Smuggler = CharacterFromID("Rand_Smug0" + i);
/*		//Levis smugglers carry opium
		if(CheckAttribute(Smuggler,"items.opium")) TakeNItems(Smuggler,"opium", -sti(Smuggler.items.opium)); //remove previous given opium
		if(rand(100) < 25) //1 in 4 chance of them having opium
		{
			TakeNItems(Smuggler, "opium", 2+rand(sti(PChar.rank)));
		}
*/		
		LAi_SetCurHPMax(Smuggler);
		SetModelfromArray(Smuggler, GetModelIndex(GetRandomModelForTypeExSubCheck(1, "Smugglers", "man", PIRATE)));

		LAi_SetWarriorTypeNoGroup(Smuggler);
		LAi_warrior_DialogEnable(Smuggler, true);
		LAi_warrior_SetStay(Smuggler, true);

		LAi_group_MoveCharacter(Smuggler, "Smugglers");
		ChangeCharacterAddressGroup(Smuggler,LocationID,"Smugglers","Smuggler0" + i);
	}
	// PB: Rewritten <--

	AddGeometryToLocation(LocationID, "smg");

	LAi_group_SetRelation(PLAYER_GROUP, "Smugglers", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("CoastalGuards", "Smugglers", LAI_GROUP_NEUTRAL);

	PChar.quest.Rand_Smuggling.win_condition.l1 = "Timer";
	PChar.quest.Rand_Smuggling.win_condition.l1.date.day = GetAddingDataDay(0,0,7);
	PChar.quest.Rand_Smuggling.win_condition.l1.date.month = GetAddingDataMonth(0,0,7);
	PChar.quest.Rand_Smuggling.win_condition.l1.date.year = GetAddingDataYear(0,0,7);
	PChar.quest.Rand_Smuggling.win_condition = "Rand_Smuggling";
}


void RemoveSmugglersFromShore()
{
	ref PChar = GetMainCharacter();
	PChar.quest.Rand_SmugglingRemove.win_condition.l1 = "ExitFromLocation";
	PChar.quest.Rand_SmugglingRemove.win_condition.l1.location = PChar.location;
	PChar.quest.Rand_SmugglingRemove.win_condition = "Rand_SmugglingRemove";
	DeleteAttribute(PChar,"quest.Contraband.Active");
	Pchar.quest.Rand_Smuggling.over = "yes";
	LAi_group_SetRelation(LAI_GROUP_PLAYER, "CoastalGuards", LAI_GROUP_NEUTRAL);
	unlockIslandContraband(GetIslandByIndex(sti(Pchar.quest.Contraband.islandindex))); //added by levis
}

void MoveBackSmugglersOnShore()
{
	ref Smuggler, PChar;
	PChar = GetMainCharacter();

	for (int i = 1; i <= 3; i++)
	{
		Smuggler = CharacterFromID("Rand_Smug0" + i);

		LAi_warrior_DialogEnable(Smuggler, true);
		LAi_warrior_SetStay(Smuggler, true);

		LAi_group_MoveCharacter(Smuggler, "Smugglers");
	}
}

string SelectSmugglingLocation()
{
	//TODO: Change this function so the location is stored in the island object and can be changed there. Or somewhere else.
	ref Pchar, CurIsland;
	String SmugLocation[4];
	string TargetLocation;

	Pchar = GetMainCharacter();
	int n;
	n = GetCharacterCurrentIsland(Pchar);
	if(n < 0) return "none";
	CurIsland = GetIslandByIndex(n);

	if(DEBUG_SMUGGLING>0) Trace("Selection Started. Island - " + CurIsland.id);
	TargetLocation = "None";

	switch (CurIsland.id)
	{
		case "FalaiseDeFleur":
			TargetLocation = "Falaise_de_fleur_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Redmond":
			TargetLocation = "Redmond_Shore_02";
		//	SmugLocation[0] = "Redmond_shore_01";
		//	SmugLocation[1] = "Redmond_shore_02";
		//	TargetLocation = SmugLocation[Rand(1)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Conceicao":
			SmugLocation[0] = "Conceicao_shore_01";
			SmugLocation[1] = "Conceicao_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Oxbay":
			SmugLocation[0] = "Oxbay_shore_01";
			SmugLocation[1] = "Oxbay_shore_02";
			SmugLocation[2] = "Oxbay_lighthouse";
			TargetLocation = SmugLocation[Rand(2)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "IslaMuelle":
			TargetLocation = "muelle_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Douwesen":
			SmugLocation[0] = "Douwesen_shore_01";
			SmugLocation[1] = "Douwesen_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

// TALISMAN added --> so smugglers have beach to use - 
		case "Curacao":
			TargetLocation = "Curacao_shore_01";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;	
		
		case "Aruba":
			TargetLocation = "Aruba_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;
		
// <-- TALISMAN		
// JRH -->
		case "Eleuthera":
			TargetLocation = "Eleuthera_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;
// JRH <--
		case "QuebradasCostillas":
			TargetLocation = "QC_Shore1";   // TALISMAN was -> "none"; - now works with smuggler in Charlestown tavern
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "KhaelRoa":
			TargetLocation = "none";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Guadeloupe":
			TargetLocation = "Guadeloupe_shore_01";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Hispaniola":
			SmugLocation[0] = "Hispaniola_shore_02";
			SmugLocation[1] = "Hispaniola_shore_01";
			SmugLocation[2] = "Hispaniola_shore_03"; // KK
			SmugLocation[3] = "Hispaniola_shore_04"; // KK
			TargetLocation = SmugLocation[Rand(3)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Turks":
			SmugLocation[0] = "Turks_lighthouse";	//JRH all 4 added
			SmugLocation[1] = "Turks_shore_01";
			SmugLocation[2] = "Turks_shore_04";
			SmugLocation[3] = "Turks_shore_05";
			TargetLocation = SmugLocation[Rand(3)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Cuba":
// KK -->
			SmugLocation[0] = "Cuba_shore_01";
			SmugLocation[1] = "Cuba_shore_02";
			SmugLocation[2] = "Cuba_Shore_06";
			TargetLocation = SmugLocation[Rand(2)];
// <-- KK
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

// KK -->
		case "SaintMartin":
			SmugLocation[0] = "SaintMartin_shore_01";
			SmugLocation[1] = "SaintMartin_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;
// <-- KK

		case "Antigua":
			TargetLocation = "Antigua_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Cayman":
			SmugLocation[0] = "Cayman_Shore_01";
			SmugLocation[1] = "Cayman_Shore_02";
			SmugLocation[2] = "Cayman_Shore_03";
			TargetLocation = SmugLocation[Rand(2)];
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;

		case "Colombia":
			TargetLocation = "Colombia_shore";
			if(DEBUG_SMUGGLING>0) Trace("Location " + TargetLocation + " Selected");
		break;
	}

	Pchar.Quest.SelectedSmugglingLocation = TargetLocation;
	return TargetLocation;
}

//Functions used to get contraband goods
int FindFirstContrabandGoods(ref _refCharacter)
{
	int i;
	int curIslandIdx = GetCharacterCurrentIsland(_refCharacter);
	ref CurIsland = GetIslandByIndex(curIslandIdx);
	aref islRef; makearef(islRef,CurIsland.Trade.Contraband);
	int n;
	for(i=0;i<GetAttributesNum(islRef);i++)
	{
		n = sti(GetAttributeValue(GetAttributeN(islRef,i)));
		if( GetSquadronGoods(_refCharacter,n)>0 )
		{
			_refCharacter.FindContrabandGoods.IslandIdx = curIslandIdx;
			_refCharacter.FindContrabandGoods.GoodsIdx = i;
			return n;
		}
	}
	DeleteAttribute(_refCharacter,"FindContrabandGoods");
	return -1;
}

int FindNextContrabandGoods(ref _refCharacter)
{
	int i,n;
	if(CheckAttribute(_refCharacter,"FindContrabandGoods.IslandIdx"))
	{
		if(CheckAttribute(_refCharacter,"FindContrabandGoods.GoodsIdx"))
		{
			int curIslandIdx = sti(_refCharacter.FindContrabandGoods.IslandIdx);
			if(curIslandIdx>=0)
			{
				int curGoodsNum = sti(_refCharacter.FindContrabandGoods.GoodsIdx) + 1;
				aref islRef; makearef(islRef,Islands[curIslandIdx].Trade.Contraband);
				for(i=curGoodsNum; i<GetAttributesNum(islRef); i++)
				{
					n = GetAttributeValue(GetAttributeN(islRef,i));
					if( GetSquadronGoods(_refCharacter,n)>0 )
					{
						_refCharacter.FindContrabandGoods.GoodsIdx = i;
						return n;
					}
				}
			}
		}
	}
	DeleteAttribute(_refCharacter,"FindContrabandGoods");
	return -1;
}