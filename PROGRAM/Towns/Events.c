#define	MAX_EVENTS				31		//Just a arbitrary number

int RANDOM_TOWN_EVENTS_QTY = 0;
object TownEvents[MAX_EVENTS];

void GetRandomTownEvents()
{
	//These are all the random events. Each event has a id which is linked to the log entrys in RESOURCE\INI\TEXTS\ENGLISH\EventsDesribe.txt
	//The multipliers are a value to which the troops/size or gold is multiplied while the add value is a value which is added. They can be used at the same time
	//The chances can be set for each economy, when the chance is set on 0 it shouldn't show up for this economy
	int n = 0;
	object RTE;
	ref RandomTownEvent, q;
	q = &n;
	makeref(RandomTownEvent, RTE);
	
	RandomTownEvent.id = "MALARIA"									// Town Economy -1
	RandomTownEvent.chance.starving = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		3;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1.0/2.0;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 1.0/2.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 5.0/6.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -2;
	RandomTownEvent.startquest = "Malaria Strikes";					// Start a specific quest
	RandomTownEvent.pirate = true;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "PIRATES"              					// Town Economy -1
	RandomTownEvent.chance.starving = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		5;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	8;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		15;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 9.0/10.0;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 5.0/6.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 2.0/5.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -2;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "GOLDFOUND"            					// Town Economy +2
	RandomTownEvent.chance.starving = 		7;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		4;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 100;
	RandomTownEvent.sizemultiplier = 1;
	RandomTownEvent.sizeadd = 300;
	RandomTownEvent.goldmultiplier = 7.0/5.0;
	RandomTownEvent.goldadd = 1;
	RandomTownEvent.economy = 3;
	RandomTownEvent.startquest = "Gold Found";						// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "SILVERFOUND"         					 	// Town Economy +1
	RandomTownEvent.chance.starving = 		14;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		10;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		3;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 60;
	RandomTownEvent.sizemultiplier = 1;
	RandomTownEvent.sizeadd = 200;
	RandomTownEvent.goldmultiplier = 1;
	RandomTownEvent.goldadd = 300*TOWN_GOLD_SCALAR;
	RandomTownEvent.economy = 2;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "INDIANS" 				             		// Town Economy -2
	RandomTownEvent.chance.starving = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	6;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		8;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1.0/4.0;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 1.0/3.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 3.0/5.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -2;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = true;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "SLAVEREVOLT"					         	// Town Economy -1
	RandomTownEvent.chance.starving = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	4;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		10;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 7.0/8.0;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 3.0/4.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 1;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -1;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "FIRE"                					 	// Town Economy -1
	RandomTownEvent.chance.starving = 		5;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		10;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	6;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		5;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 4.0/5.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 3.0/4.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -1;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = true;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "HURRICANE"    				        	// Town Economy -1
	RandomTownEvent.chance.starving = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	5;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		6;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 7.0/8.0;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 3.0/5.0;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 2.0/3.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = -2;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = true;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "SETTLERS"     				        	// Town Economy +1
	RandomTownEvent.chance.starving = 		30;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		20;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		5;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	0;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 50;
	RandomTownEvent.sizemultiplier = 1;
	RandomTownEvent.sizeadd = 250;
	RandomTownEvent.goldmultiplier = 6.0/5.0;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = 6;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "EXPEDITION"    					       	// Town Economy +2
	RandomTownEvent.chance.starving = 		1;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		4;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		10;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	6;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		2;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 1;
	RandomTownEvent.sizeadd = 200;
	RandomTownEvent.goldmultiplier = 1;
	RandomTownEvent.goldadd = 700*TOWN_GOLD_SCALAR;
	RandomTownEvent.economy = 3;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = false;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);
	
	RandomTownEvent.id = "GOODECO"     					        	// Town Economy +1
	RandomTownEvent.chance.starving = 		15;						// Chance of it happening (0-100)
	RandomTownEvent.chance.stuggling = 		10;						// Chance of it happening (0-100)
	RandomTownEvent.chance.surviving = 		5;						// Chance of it happening (0-100)
	RandomTownEvent.chance.prospering = 	2;						// Chance of it happening (0-100)
	RandomTownEvent.chance.wealthy = 		0;						// Chance of it happening (0-100)
	RandomTownEvent.troopmultiplier = 1;
	RandomTownEvent.troopsadd = 0;
	RandomTownEvent.sizemultiplier = 1;
	RandomTownEvent.sizeadd = 0;
	RandomTownEvent.goldmultiplier = 1;
	RandomTownEvent.goldadd = 0;
	RandomTownEvent.economy = 2;
	RandomTownEvent.startquest = "";								// Start a specific quest
	RandomTownEvent.pirate = true;									// Pirate towns can also be affected
	AddRandomTownEvent(q, RandomTownEvent);

	RANDOM_TOWN_EVENTS_QTY = q;
}

void AddRandomTownEvent(ref q, ref RTE)
{
	ref Events;
	makeref(Events, TownEvents[q]);
	CopyAttributes(Events, RTE);
	q++;
}

int GetRandomTownEvent(ref ctown)
{
	int shift = rand(RANDOM_TOWN_EVENTS_QTY);
	int index;
	for(int i = 0; i < RANDOM_TOWN_EVENTS_QTY; i++)
	{
		index = i + shift;
		if(index >= RANDOM_TOWN_EVENTS_QTY) index -= RANDOM_TOWN_EVENTS_QTY;
		//TOWNS_QUANTITY is included here cause this function is called for each town. so this way the percentages are correct.
		if(rand(TOWNS_QUANTITY*100*EVENT_CHANCE_MULTIPLIER) < GetTownChance(ctown, index))
		{
			return index;
		}
	}
	return -1;
}

int GetTownChance(ref ctown, int index)
{
	//Returns the chance for the right economy
	string economy = GetEconomyText(GetTownEconomy(ctown));
	aref ecochance;
	makearef(ecochance ,TownEvents[index].chance.(economy));
	int chance = sti(ecochance);
	return chance;
}

void LaunchRandomTownEvent(ref ctown)
{
	ref Pchar = GetMainCharacter();
	//Check if the attribute exist else make it.
	int yeardays = GetDayOfYear(GetDataYear(), GetDataMonth(), GetDataDay());
	if(!CheckAttribute(ctown,"lasttownevent")) ctown.lasttownevent = yeardays-rand(EVENT_PER_DAYS+1);
	int day = sti(ctown.lasttownevent);
	if(yeardays < day) 
	{
		day = day + GetYearDays(GetDataYear() - 1);
	}
	
	//Add a check to see if a smuggling quest is active
	bool nosmuggle = true;
	if(CheckAttribute(Pchar, "quest.Contraband.Active"))
	{
		if(Pchar.quest.Contraband.Active) nosmuggle = false;
	}
    //Check if we can launch an event.
    if((day + (EVENT_PER_DAYS*ENCOUNTERBREAK)) < yeardays && nosmuggle)
    {
		int random;
		int iSize;
		int iTroops;
		int iGold;
		int iEconomy;
		string logTitle;
		string logEntry;
		//Get the events
		GetRandomTownEvents();
		//Pick a event, if none is picked it returns -1
		random = GetRandomTownEvent(ctown); //Added by Levis
		if(random >= 0)
		{
			//Check if this is a pirate village and if it can have this event
			if(GetTownNation(ctown.id) == PIRATE && TownEvents[random].pirate == false) return;
			
			//Change the town size
			iSize = GetTownSize(ctown.id);
			SetTownSize(ctown.id, makeint(abs(iSize * makefloat(TownEvents[random].sizemultiplier) + makefloat(TownEvents[random].sizeadd))));
			
			//Change the amount of troops
			iTroops = GetTownNumTroops(ctown.id);
			SetTownNumTroops(ctown.id, makeint(abs(iTroops *makefloat(TownEvents[random].troopmultiplier) + makefloat(TownEvents[random].troopsadd))));
			
			//Change the amount of gold
			iGold = GetTownGold(ctown.id);
			SetTownGold(ctown.id, makeint(abs(iGold * makefloat(TownEvents[random].goldmultiplier) + makefloat(TownEvents[random].goldadd))));
			
			//AdjustTownEconomy
			AdjustTownEconomy(ctown, sti(TownEvents[random].economy));
			
			//Set preprocessor data
			Preprocessor_Add("town" , FindTownName(ctown.id));
			
			//Get the logTitle and logEntry
			int lngFileID = LanguageOpenFile("EventsDesribe.txt");
			logTitle = PreprocessText(LanguageConvertString(lngFileID, TownEvents[random].id + "_title"));
			logEntry = PreprocessText(LanguageConvertString(lngFileID, TownEvents[random].id + "_entry"));
			LanguageCloseFile(lngFileID);
			
			//Remove preprocessor data
			Preprocessor_Remove("town");
			
			//Write the logentry
			if(logTitle != "") WriteNewLogEntry(logTitle, logEntry, "General", false);
			
			//Make sure it takes a while before the next event happens
			ctown.lasttownevent = yeardays;
			
			//Start a Quest if there is one
			if(TownEvents[random].startquest != "")
			{
				string questmarker = TownEvents[random].id
				Pchar.quest.(questmarker) = ctown.id;
				CompleteQuestName(TownEvents[random].startquest);
			}
		}
	}
}

void LaunchTownQuestEvent(ref ctown)
{
	//This function can be used to set specific quest related event things
	string options[5], logTitle, logEntry;
	ref pchar = GetMainCharacter();
	int n = -1;
	//Check which quests can be done
	if(CheckAttribute(pchar,"quest.fetch_quest_town"))
	{
		if(pchar.quest.fetch_quest_town == "")
		{
			n++;
			options[n] = "Fetch";
		}
	}
	else
	{
		n++;
		options[n] = "Fetch";
	}
	//Get a quest
	if(n>=0)
	{
		int chance = rand(TOWNS_QUANTITY*100*EVENT_CHANCE_MULTIPLIER);
		if(chance < QUEST_EVENTS_CHANCE)
		{
			string quest = options[rand(n)];
			int lngFileID = LanguageOpenFile("EventsDesribe.txt");
			switch(quest)
			{
				case "Fetch":
					//Get data
					if(FetchQuestType(ctown))
					{
						CompleteQuestName("fetch_quest_created");
						//Set event
						Preprocessor_Add("town", FindTownName(pchar.quest.fetch_quest_town));
						logTitle = PreprocessText(LanguageConvertString(lngFileID, quest + "_" + pchar.quest.fetch_quest.type + "_title"));
						logEntry = PreprocessText(LanguageConvertString(lngFileID, quest + "_" + pchar.quest.fetch_quest.type + "_entry"));
						Preprocessor_Remove("town");
					}
				break;
			}
			LanguageCloseFile(lngFileID);
			if(logTitle != "") WriteNewLogEntry(logTitle, logEntry, "General", false);
		}
	}
	return;
}