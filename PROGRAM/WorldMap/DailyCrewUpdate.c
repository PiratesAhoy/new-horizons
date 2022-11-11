// NK DailyCrewUpdate functions

// NK moved defines to BuildSettings.h 05-03-19

//start main function
void DailyCrewUpdate()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

//declare vars -->
	ref pchar = GetMainCharacter();
	int i,j,cn;
	ref chref;
	bool bCompanionMutiny = false; // KK
// variables that are needed always
	int skillComm = CalcCharacterSkill(pchar, SKILL_COMMERCE);
	int PerkComm = CheckPerkForSingleCharacter(pchar,"BasicCommerce") + CheckPerkForSingleCharacter(pchar,"AdvancedCommerce");
	int PerkBasicLand = CheckPerkForSingleCharacter(pchar,"BasicLandOwner");
	int skillLuck = GetShipSkill(pchar,SKILL_SNEAK);
	int CursedCoins = 0; // PB: Cursed Coins
	if(!CheckAttribute(pchar,"disableDCU")) // 05-04-17 add disableDCU check
	{
//variables that are needed by DCU
		int crewQ = GetSquadronTotalCrewQuantity(pchar);
		// PB: Cursed Coins -->
		if(CheckCharacterItem(pchar,"cursedcoin"))
		{
			CursedCoins = GetCursedCoinCount();
			crewQ = crewQ - CursedCoins;
			if(crewQ<0)	crewQ = 0;
		}
		// PB: Cursed Coins <--
		crewQ = crewQ + GetUnremovableCrewQuantity(pchar);
		bool CheckFood = FOOD_ON && CheckAttribute(pchar, "ship") && crewQ>0;
//		if(CheckFood) CheckFood = pchar.ship.type != "Tartane1" && pchar.ship.type != "Tartane2" && !CheckAttribute(pchar,"skipfood"); // both NK 04-11 to skip foodcheck // KK The crew doesn't eat when on tartane?

	//morale
	// for now, all companion ships take pchar's ship's morale.
		float morale = 45;
		if(CheckAttribute(pchar,"Ship.Crew.Morale")) morale = stf(pchar.Ship.Crew.Morale);
		int PerkIron = GetOfficersPerkUsing(pchar,"IronWill");
		int skillLead = GetShipSkill(pchar,SKILL_LEADERSHIP);

		float moralech = 0.0;
		float moralemod = 0.6 + (stf(skillLead) + stf(PerkIron)*5)/20; // PB: Simplified and corrected
		//max: x1.35; min: x0.65
		float moralescale = 1.0;
		bool articles = false;
		if (CheckAttribute(pchar, "articles") == true && sti(pchar.articles) == true) articles = true;


	//JA 1Dec06 reworked Food & Rum system -->
	//food

		// GR: If you have the "Cooking With Albatross" book and an albatross, cook it
		bool HaveCookBook = CheckCharacterItem(PChar, "book9");		// Do you have the cookbook?
		int PCabin = FindCharacterShipCabin(PChar);
		if (!HaveCookBook && PCabin >= 0 && CheckAttribute(&Locations[PCabin], "box1.items.book9")) // If not, is it in your ship's chest?
		{
			HaveCookBook = true;
		}
		if (HaveCookBook && CheckCharacterItem(PChar, "albatross"))
		{
			TakeItemFromCharacter(PChar, "albatross");
			AddCharacterGoods(PChar, GOOD_WHEAT, 2);
		}

		int foodQ = GetSquadronGoods(pchar, GOOD_WHEAT);
		float foodRatio[4];
		int ft[4];
		ft[0]=0; ft[1] = 0; ft[2]=0; ft[3]=0;
		float foodused = 0;
		if(CheckFood) foodused = makefloat(crewQ) * FOOD_PER_CREW;
		float foodusedtemp = 0.0;
		if(CheckAttribute(pchar,"Crewstatus.foodused"))
		{ //Add leftover food requirement from yesterday.
			if(CheckFood) { foodusedtemp = foodusedtemp + stf(pchar.Crewstatus.foodused); }
			pchar.Crewstatus.foodused = 0.0;
		}
		int foodrations = 1; //this is a divisor
		if(CheckAttribute(pchar,"Crewstatus.foodrations")) foodrations = sti(pchar.Crewstatus.foodrations);
		int food_daysleft = 999;

		float rationedFoodConsumption;
		if(foodused==0) rationedFoodConsumption = 1; // avoid divide by zero
		else 
		{
			rationedFoodConsumption = foodused / makefloat(foodrations);
			//Add by levis for cooking perk:
			if(CheckCharacterPerk(pchar, "Cooking")) rationedFoodConsumption = rationedFoodConsumption*0.9;
		}
		if(CheckFood) food_daysleft = makeint((makefloat(foodQ) - foodusedtemp) / rationedFoodConsumption);

		if(CheckFood) { if((makefloat(foodQ) - foodusedtemp) / rationedFoodConsumption < 1) { food_daysleft = 0; } }

		int daysnofood = 0;
		if(CheckFood) { if(CheckAttribute(pchar, "Crewstatus.daysnofood")) { daysnofood = sti(pchar.Crewstatus.daysnofood); } }

		if(food_daysleft < 8 && food_daysleft > 0 && LogsToggle >= LOG_NORMAL) Log_SetStringToLog(TranslateString("","Captain, we have only") + " " + food_daysleft + " " + TranslateString("","days worth of food left!"));
		// KK if(food_daysleft == 0 && LogsToggle > LOG_QUIET) Log_SetStringToLog(TranslateString("","Captain, we're out of food!"));

	//fill foodratio so we can track what ship had what food later.
		int iMostFoodShip = 0; //JA find the ship with the most food on it for handling special low food case later
		if(CheckFood && foodQ) // NK 04-09-09 divbyzero error fix
		{
			float iHighestFoodRatio = 0; //JA Need this to handle special case.
			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) { // KK --> // PB: Included GetRemovable(GetCharacter(cn))
					foodRatio[i] = makefloat(GetCargoGoods(&Characters[cn],GOOD_WHEAT)) / makefloat(foodQ);
					if(foodRatio[i] > iHighestFoodRatio)
					{
						iHighestFoodRatio = foodRatio[i];
						iMostFoodShip = i;
					}
				}// <-- KK
			}
		}

	//rum
		int rumQ = GetSquadronGoods(pchar, GOOD_RUM);
		float rumRatio[4];
		int rt[4];
		rt[0]=0; rt[1] = 0; rt[2]=0; rt[3]=0;
		float rumused = 0;
		if(CheckFood) rumused = makefloat(crewQ) * FOOD_PER_CREW;
		float rumusedtemp = 0.0;
		if(CheckAttribute(pchar,"Crewstatus.rumused")) //Handle left over rum fraction used from yesterday.
		{
			if(CheckFood) { rumusedtemp = rumusedtemp + stf(pchar.Crewstatus.rumused); }
			pchar.Crewstatus.rumused = 0.0;
		}
		int rumrations = 2; //this is a divisor
		if(CheckAttribute(pchar,"Crewstatus.rumrations")) rumrations = sti(pchar.Crewstatus.rumrations);
		int rum_daysleft = 999;

		float rationedRumConsumption;
		if(rumused==0) rationedRumConsumption = 1;
		else rationedRumConsumption = rumused / makefloat(rumrations);
		if(CheckFood) rum_daysleft = makeint((makefloat(rumQ) - rumusedtemp) / rationedRumConsumption);
		
		// --> Swindler 05-10-10: fix for divide by zero error
        if (rumused > 0 && (makefloat(rumQ) - rumusedtemp) / rationedRumConsumption < 1) { rum_daysleft = 0; }
        // Swindler <--

		if(rum_daysleft < 8 && rum_daysleft > 0 && LogsToggle >= LOG_NORMAL) Log_SetStringToLog(TranslateString("","Captain, we have only") + " " + rum_daysleft + " " + TranslateString("","days worth of rum left!"));
		// KK if(rum_daysleft == 0 && LogsToggle > LOG_QUIET) Log_SetStringToLog(TranslateString("","Captain, we're out of rum!"));

		int rum2chance = RUM_BASECH + ((skillLead/2 + skillLuck/2) * (PerkIron + 0.5));

	//fill rumratio so we can track what ship had what rum later.
		int iMostRumShip = 0; //JA find the ship with the most rum on it for handling special low rum case later
		if(CheckFood && rumQ) // NK 04-09-09 divbyzero error fix
		{
			float iHighestRumRatio = 0; //JA Need this to handle special case.
			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) { // KK --> // PB: Included GetRemovable(GetCharacter(cn))
					rumRatio[i] = makefloat(GetCargoGoods(&Characters[cn],GOOD_RUM)) / makefloat(rumQ);
					if(rumRatio[i] > iHighestRumRatio)
					{
						iHighestRumRatio = rumRatio[i];
						iMostRumShip = i;
					}
				} // <-- KK
			}
		}


	//check food and deal with it.
		if(CheckFood)
		{
			foodusedtemp = foodusedtemp + rationedFoodConsumption; //Get total food to be eaten today

			//Handle fractional food requiements.
			//ignore small leftover food fractions
			if (round(foodusedtemp) - foodusedtemp <= 0.05 && round(foodusedtemp) - foodusedtemp >= -0.05) {
				foodusedtemp = round(foodusedtemp);
			}
			else //add extra food fraction to next day's food, and round down todays food.
			{
				pchar.Crewstatus.foodused = foodusedtemp - makefloat(makeint(foodusedtemp));
				foodusedtemp = makeint(foodusedtemp);
			}
			//Remove eaten food from total quantity

			foodQ = foodQ - foodusedtemp;

			if(foodQ <= 0)
			{
				foodQ = 0;
				pchar.Crewstatus.foodused = 0.0;
			}

			//divide remaining food back into ships
			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) ft[i] = makeint(makefloat(foodQ)*foodRatio[i]);
			}
			if(ft[0]+ft[1]+ft[2]+ft[3] == 0 && foodQ > 0) //handle special case of trying to divide 1 or two food between a few ships
			{
				ft[iMostFoodShip] = 1; //put last remaining food on this ship;
			}

			// PB: Start at a different number each time to evenly distribute consumption
			if (CheckAttribute(pchar, "Crewstatus.foodlastship"))
			{
				j = sti(pchar.Crewstatus.foodlastship) + 1;
				if (j >= 4) j = 0;
			}
			else
			{
				j = 0;
			}
			pchar.Crewstatus.foodlastship = j;

			//if food doesn't divide evenly:
			while(ft[0]+ft[1]+ft[2]+ft[3] != foodQ)
			{
				for(i=0; i<4; i++)
				{
					j = i + sti(pchar.Crewstatus.foodlastship);
					if (j >= 4) j -= 4;
					if (ft[j] > 0) //Ship had food
					{
						if(ft[0]+ft[1]+ft[2]+ft[3] > foodQ) //too much food allocated, so remove some
						{
							ft[j]--;
						}
						if(ft[0]+ft[1]+ft[2]+ft[3] < foodQ) //not enough food allocated, so add some
						{
							ft[j]++;
						}
					}
				}
			}
	//JA <-- 1Dec06 reworked Food & Rum system

			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) SetCharacterGoods(&Characters[cn],GOOD_WHEAT, ft[i]);
			}
			if(LogsToggle > LOG_QUIET)
			{
				if (foodQ <= 0)
					Log_SetStringToLog(TranslateString("","Captain, we're out of food!"));
				else
					Log_SetStringToLog(TranslateString("","Food Qty") + ": " + makeint(foodQ) + ", " + TranslateString("","good for") + " " + food_daysleft + " " + XI_ConvertString("days."));
			}
			if(foodQ <= 0)
			{
				daysnofood++;
				moralescale = moralescale * (FOOD0_SCALE/(pow(daysnofood,1.25)/2));
				float tempdie = 1 - ((pow(daysnofood,1.5) + frand(pow(daysnofood,1.5)))/4.0 * FOOD_CREWDIEOFF * (1.0-(FRAND(skillLuck)/30.0)));
				if(tempdie < 0) tempdie = 0.0;
				if(GetCrewQuantity(pchar) <= makeint(makefloat(GetMaxCrewQuantity(pchar)) / 4.0)) KAM_Mutiny(); //MAXIMUS: new "Mutiny"
// KK -->
				for (i = 1; i < COMPANION_MAX; i++)
				{
					cn = GetCompanionIndex(pchar, i);
					if (cn < 0) continue;
					chref = GetCharacter(cn);
					if (IsMutineer(chref) == false && GetCrewQuantity(chref) <= makeint(makefloat(GetMaxCrewQuantity(chref)) / 4.0)) {
						SetMutineer(chref, true);
						bCompanionMutiny = true;
					}
				}
// <-- KK
				//Log_SetStringToLog("Dieratio: " + tempdie);
				//Log_SetStringToLog("No food! Scale down to " + moralescale);
				string tempded = GetSquadronCrewQuantity(pchar) - SetSquadronCrewQuantityRatio(pchar, tempdie);
				if(LogsToggle > LOG_QUIET)
				{
				  if(tempded < 1) Log_SetStringToLog(TranslateString("","Captain, we're out of crew!"));
				  else Log_SetStringToLog("" + tempded + " " + TranslateString("","crew have died from starvation."));
				}
			}
			else
			{
				daysnofood = 0;
				if(foodrations == 2)
				{
					moralescale = moralescale * FOOD2_SCALE;
					//Log_SetStringToLog("Scale down to " + moralescale);
				}
			}
		}
		pchar.Crewstatus.foodrations = foodrations;
		pchar.Crewstatus.daysnofood = daysnofood;

	//JA 1Dec06 reworked Food & Rum system -->
		//check rum and deal with it.
		if(CheckFood)
		{
			rumusedtemp = rumusedtemp + rationedRumConsumption; //JA: total rum used today and rest of yesterday

			//Handle fractional rum requiements.
			//ignore small leftover rum fractions
			if(round(rumusedtemp) - rumusedtemp <= 0.05 && round(rumusedtemp) - rumusedtemp >= -0.05) rumusedtemp = round(rumusedtemp);
			else //add extra rum fraction to next day's rum, and round down todays rum.
			{
				pchar.Crewstatus.rumused = rumusedtemp - makefloat(makeint(rumusedtemp));
				rumusedtemp = makeint(rumusedtemp);
			}
			//Remove eaten rum from total quantity
			rumQ = rumQ - rumusedtemp;
			
			if(rumQ <= 0)
			{
				rumQ = 0;
				pchar.Crewstatus.rumused = 0.0
			}

			//divide remaining rum back into ships
			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) rt[i] = makeint(makefloat(rumQ)*rumRatio[i]);
			}

			if(rt[0]+rt[1]+rt[2]+rt[3] == 0 && rumQ > 0) //handle special case of trying to divide 1 or two rum between a few ships
			{
				rt[iMostRumShip] = 1; //put last remaining rum on this ship;
			}

			// PB: Start at a different number each time to evenly distribute consumption
			if (CheckAttribute(pchar, "Crewstatus.rumlastship"))
			{
				j = sti(pchar.Crewstatus.rumlastship) + 1;
				if (j >= 4) j = 0;
			}
			else
			{
				j = 0;
			}
			pchar.Crewstatus.rumlastship = j;

			//if rum doesn't divide evenly:
			while(rt[0]+rt[1]+rt[2]+rt[3] != rumQ)
			{
				for(i=0; i<4; i++)
				{
					j = i + sti(pchar.Crewstatus.rumlastship);
					if (j >= 4) j -= 4;
					if (rt[j] > 0) //ship had rum
					{
						if(rt[0]+rt[1]+rt[2]+rt[3] > rumQ) //too much rum so remove one
						{
							rt[j]--;
						}
						if(rt[0]+rt[1]+rt[2]+rt[3] < rumQ) //not enough rum so add one
						{
							rt[j]++;
						}
					}
				}
			}
			SetCharacterGoods(pchar, GOOD_RUM, rt[0]);
			for(i=1; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(pchar,i);
				if(cn!=-1) SetCharacterGoods(&Characters[cn],GOOD_RUM, rt[i]);
			}

	//JA <-- 1Dec06 reworked Food & Rum system 
			
			if(LogsToggle > LOG_QUIET)
			{				
			    if(rumQ <= 0) Log_SetStringToLog(TranslateString("","Captain, we're out of rum!"));
				else Log_SetStringToLog(TranslateString("","Rum Qty") + ": " + makeint(rumQ) + ", " + TranslateString("","good for") + " " + rum_daysleft + " " + XI_ConvertString("days."));
			}

			if(rumQ <= 0)
			{
				moralescale = moralescale * RUM0_SCALE;
				//Log_SetStringToLog("No rum! Scale down to " + moralescale);
			}
			else
			{
				if(rumrations == 1)
				{
					if(!rand(rum2chance))
					{
						Log_SetStringToLog(TranslateString("","Drunken brawl breaks out, morale plummets!")); // NK 05-03-19 added detail
						moralech = moralech - RUMDEC * (2-moralemod);	// PB: Corrected to prevent morale INCREASING when this happens
						ResetTimeToNormal();							// PB: Slow down game to normal speed so you can deal with the situation
					}
					else
					{
						moralescale = moralescale * RUM_SCALE;
					}
				}
				else
				{
					moralescale = moralescale * RUM2_SCALE;
				}
			}
		}

		// PB: Cursed Coins -->
		if(CursedCoins>0)
		{
			crewQ = GetSquadronTotalCrewQuantity(pchar) - CursedCoins;
			if(crewQ>0)
			{
				float uncursed_percentage = stf(crewQ)/GetSquadronTotalCrewQuantity(pchar);
				moralescale = moralescale * uncursed_percentage;
				if(moralescale < 0.5)	moralescale = 0.5;
				LogIt("Captain, " + makeint((1-uncursed_percentage)*100) + "% of the crew is cursed due to " + CursedCoins + " Aztec coins");
			}

			for (i = 0; i < COMPANION_MAX; i++)
			{
				if (GetCompanionIndex(PChar, i) < 0) continue;
				chref = GetCharacter(GetCompanionIndex(PChar, i));
				if(CheckCharacterItem(chref,"cursedcoin"))
				{
					if(!CheckAttribute(chref, "curseddays"))	chref.curseddays = 0;
					chref.curseddays = sti(chref.curseddays) + 1;
				}
			}
			if(sti(pchar.curseddays)==25)	LogIt("Captain, the crew is really not happy with this whole curse business. They work SO HARD at repairing the sails, but it appears to have no effect!");
			if(sti(pchar.curseddays)==35)	LogIt("Captain, now the crew can't even see where they're going anymore with all this unnatural fog! Cannot you be persuaded to attempt to lift the curse?");
		}
		// PB: Cursed Coins <--

	//loot
		float lastcsr = 1.0;
		if(CheckAttribute(pchar,"Crewstatus.lastcsr")) lastcsr = stf(pchar.CrewStatus.lastcsr);
		else pchar.CrewStatus.lastcsr = lastcsr;
		//unclamp lastcsr
		if(lastcsr > 1.0) lastcsr = 1/(2-lastcsr);

	//expedition length, i.e. days since divide plunder
		int explength = 0;
		if(CheckAttribute(pchar,"CrewStatus.explength")) explength = sti(pchar.CrewStatus.explength);
		else pchar.CrewStatus.explength = 0;

	//determine crew share ratio
		float csr = 1.0;

		// LDH 22Apr09 -->
		if (articles)
		{
			csr = GetCrewShareRatio(pchar);
			float NormalExpLength = NORMAL_EXP_LENGTH * EXP_LENGTH_START_FRAC;		// 180 * 0.5
			if (explength > NormalExpLength)
			{
				csr = csr * (2 * NormalExpLength / explength - 1.0);		// 90 days=100, 120 days=50, 150 days=20
			}
		}
		// LDH <--

		if(articles && LogsToggle >= LOG_NORMAL) LogIt(TranslateString("","Each crewman's share is now") + " " + csr + TranslateString("","x average for this time."));

	//update morale
		float norm_morale = 100;

	//clamp csr - PB: Return original code to distinguish between Salary and Articles
		if(csr > 1) csr = 2-(1/csr);
		if(articles) { norm_morale = (100 - (CSR_SCALE*2))/2 + csr * CSR_SCALE; }
		else { norm_morale = norm_morale * SALARY_SCALE; }

	// LDH lower morale if player isn't sharing loot - 06Mar09
		//Only check when on sea or worldmap
		if(bSeaActive || IsEntity(&worldMap) != 0)
		{
			if (articles || AllowUnlimitedLoot())
			{
				// do nothing
				DeleteAttribute(pchar, "articles_note");																			// PB: Reset this
				DeleteQuestHeader("crew_affairs");																					// PB: Remove Questbook entry
			}
			else
			{
				// PB: Include ship's chests -->
				ref loc = &locations[FindLocation("Tutorial_Deck")];
				int money = sti(pchar.money);
				if(CheckAttribute(loc, "weaponslocker.money"))	money = money + sti(loc.weaponslocker.money);
				if(CheckAttribute(loc, "box1.money"))			money = money + sti(loc.box1.money);
				//Levis: Check the amount of ships
				int numship = 1;
				for(i=1; i<COMPANION_MAX; i++)
				{
					if(GetCompanionIndex(pchar,i) != -1) numship ++;
				}
				//End Check
				money = money - ( (1000000 * numship) + GetEstimatedOfficerPay() + GetEstimatedCrewPay() ); //Levis added numship
				// PB: Include ship's chests <--
				if (money > 0)
				{
					norm_morale = norm_morale - money/(1000*makeint(pchar.reputation)); // Sulan: an honest trader will less likely provoke mutiny in his crew than a pirate
					Trace("DailyCrewUpdate: morale lowered by " + money/(1000*makeint(pchar.reputation)) + " due to undivided loot");	// LDH - 06Mar09

					if(!CheckAttribute(pchar, "articles_note"))
					{
						pchar.articles_note = true;																					// PB: Show this only once
						LogIt(TranslateString("","Captain, the crew is envious of the amount of money we have on board and wants to sign articles"));	// PB: Log message added + effect increased to become visible
						SetQuestHeader("crew_affairs");																				// PB: Add to Questbook too
						AddQuestRecord("crew_affairs", 1);																			// PB: Add to Questbook too
					}
				}
				else
				{
					DeleteAttribute(pchar, "articles_note");																		// PB: Reset once this has been sorted
					DeleteQuestHeader("crew_affairs");																				// PB: Remove Questbook entry
				}
			}
		}

	//calculate final morale for player
		// norm_morale = base morale for entire fleet; not modified per character
		// moralescale = morale scalar based on food and rum rations, modified for cursed coins effect; not modified per character
		moralemod = moralemod * moralescale;																					// apply food and rum modifiers
		moralemod = fClamp(MORALE_MIN,MORALE_MAX, norm_morale * moralemod);														// apply leadership and perks for player
		moralech = moralech + (moralemod-morale) * CHANGE_MULT;																	// PB: Corrected and simplified
		morale = morale + moralech;
		morale = fClamp(MORALE_MIN,MORALE_MAX,morale);
//trace("DailyCrewUpdate: old morale = " + pchar.Ship.Crew.Morale + ", norm_morale = " + norm_morale + ", moralemod = " + moralemod + ", moralech = " + moralech + ", new morale = " + morale);
		pchar.Ship.Crew.Morale = morale;

		if (morale <= 10) KAM_Mutiny(); //MAXIMUS: new "Mutiny"
		if(LogsToggle > LOG_QUIET) Log_SetStringToLog(TranslateString("","The crew now has") + " " + XI_ConvertString(GetMoraleName(morale)) + " " + XI_ConvertString("morale") + " (" + makeint(morale) + ").");
		if(!CheckFood) { pchar.foodoff = true; }

		
	//set values for next time and play sounds.
		explength++;
		pchar.CrewStatus.explength = explength;
		//apply personal explengths
		for(i=1; i<COMPANION_MAX; i++)
		{
			cn = GetCompanionIndex(pchar,i);
			if(cn!=-1)
			{
				chref = GetCharacter(cn);

				// LDH make companion ship morale change like player ship morale - 27Jan09
				// This way you don't have captured ships going from Treacherous to Heroic in one jump
				if(!CheckAttribute(chref, "Ship.Crew.Morale"))	chref.Ship.Crew.Morale = 45;						// PB: To fix missed attribute
				morale = sti(chref.Ship.Crew.Morale);											// companion ship previous morale

				// PB: Use Companion Skills and Reputation for Morale -->
				int diff = 0;
				int player_rep = GetCharacterReputation(pchar);
				int compan_rep = GetCharacterReputation(chref);
				PerkIron = GetCharacterPerkUsing(chref,"IronWill");									// check captain ONLY
				if(player_rep >= REPUTATION_NEUTRAL && compan_rep >= REPUTATION_NEUTRAL) ResetEffectiveSkill(chref, SKILL_LEADERSHIP);	// Without this reset, leadership is 0!
				if(player_rep <= REPUTATION_NEUTRAL && compan_rep <= REPUTATION_NEUTRAL) ResetEffectiveSkill(chref, SKILL_LEADERSHIP);	// Only apply leadership bonus if companion and player reputations do not conflict
				skillLead = GetEffectiveSkill(chref,SKILL_LEADERSHIP);									// check captain ONLY
				moralemod = 0.6 + (stf(skillLead) + stf(PerkIron)*5)/20;								// calculated same as player
				moralemod = moralemod * moralescale;											// apply food and rum modifiers
				moralemod = norm_morale * moralemod;											// apply leadership and perks for companion
				if(ProfessionalNavyNation() == UNKNOWN_NATION)
				{
					if(player_rep > REPUTATION_NEUTRAL && compan_rep < REPUTATION_NEUTRAL)
						moralemod = moralemod - (player_rep - compan_rep);
					if(player_rep < REPUTATION_NEUTRAL && compan_rep > REPUTATION_NEUTRAL)
						moralemod = moralemod - (compan_rep - player_rep);
				}

				moralemod = fClamp(MORALE_MIN,MORALE_MAX, moralemod);
				moralech = moralech + (moralemod-morale) * CHANGE_MULT;															// PB: Corrected and simplified
				morale = morale + moralech;																						// get new companion morale
				morale = fClamp(MORALE_MIN,MORALE_MAX,morale);
				chref.Ship.Crew.Morale = morale;
				// PB: Use Companion Skills and Reputation for Morale <--

				// KK: Companion Mutiny -->
				if (morale <= 30 && GetRemovable(chref)) // PB: Skip 'locked' ships
				{
					if (IsMutineer(chref) == false && morale <= 10)
					{
						SetMutineer(chref, true);
						bCompanionMutiny = true;
					}
					else
					{
						if(!CheckAttribute(chref, "mutiny_note") && GetDifficulty() < DIFFICULTY_SEADOG) // Hints only on Landlubber and Mariner
						{
							chref.mutiny_note = true;	
							LogIt("Captain, the crew of the " + XI_ConvertString(GetShipString(GetCharacterShipType(chref))) + " " + GetMyShipNameShow(chref) + " " + TranslateString("", "commanded by") + " " + GetMySimpleName(chref) + " has less than Low morale. Beware of mutiny!");
						}
					}
				}
				else
				{
					DeleteAttribute(chref, "mutiny_note");
				}
				// KK: Companion Mutiny <--

				if(CheckAttribute(chref,"cexplength")) {chref.cexplength = sti(chref.cexplength)+1;}
				else {chref.cexplength = 1;}
			}
		}
		for(i=1; i<OFFICER_MAX; i++)
		{
			cn = GetOfficersIndex(pchar,i);
			if (cn != -1) {
				chref = GetCharacter(cn);
				if (CheckAttribute(chref,"oexplength")) 
					chref.oexplength = sti(chref.oexplength)+1;
				else
					chref.oexplength = 1;
			}
		}
		//Log_SetStringToLog("XL: " + explength + ", NM: " + norm_morale);

		if (LogsToggle >= LOG_NORMAL) Log_SetStringToLog(TranslateString("","We've been out") + " " + explength + " " + TranslateString("","days.")); // PB: One value on Salary and another on Articles
	}
	// GreatZen -->
	int land = GetCharacterLand(pchar);
	int profit = makeint(LAND_PROFIT_SCALAR * pow(land/100,LAND_PROFIT_POW) * (0.25 + frand(0.5) + makefloat(PerkComm)/4.0) * (0.5 + makefloat(skillComm)/5.0 + makefloat(rand(roundup(makefloat(skillComm)/5.0)))/2.0) * (1.0 + 0.5 * makefloat(PerkBasicLand)));
	AddWealthtoCharacter(pchar, profit);
	if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Commerce", makeint(profit/10)); }// MAXIMUS - [skillsup system]
	if(LogsToggle >= LOG_NORMAL && profit > 0) Log_SetStringToLog(TranslateString("","You made") + " " + MakeMoneyShow(profit, MONEY_SIGN, MONEY_DELIVER) + " " + TranslateString("","gold from your estates."));
	// GreatZen <--

	//unpaid usurers mod  --->
	if (CheckAttribute(pchar, "mad_usurer")) {
		int usurers = sti(pchar.mad_usurer);
		if (usurers > 0) {
			int iRep = sti(pchar.reputation);
			if (iRep > 21) {
				pchar.reputation = makeint(pchar.reputation) - usurers;
				if(makeint(pchar.reputation) < 21) pchar.reputation = 22; //you cannot become a bloody bastard just for not paying your debts! swindler is the worst you can get
			}
		}
	} else {
		pchar.mad_usurer = 0;
	}
	//unpaid usurers mod <---

	//ASVS - playing main_theme music mod --->
	if(CheckAttribute(pchar, "main_theme.value"))
	{
		Change_MainThemeMusic_Chance(-0.5); // very simple for the moment...
	}
	//ASVS - playing main_theme music mod <---

// KK & PB -->
		
	for (i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(pchar, i);
		if (cn < 0) continue;
		chref = GetCharacter(cn);
		int wounded_qty = GetWoundedCrewQuantity(chref);
		if (wounded_qty > 0) {
			int healed_qty = GetWoundedHealedPerDay(chref);
			if(healed_qty > wounded_qty) healed_qty = wounded_qty;
			HealCharacterWoundedCrew(chref, healed_qty);

			wounded_qty = GetWoundedCrewQuantity(chref);
			int killed_qty = GetWoundedKilledPerDay(chref);
			if(killed_qty > wounded_qty) killed_qty = wounded_qty;
			RemoveCharacterWoundedCrew(chref, killed_qty);

			if (GetCargoGoods(chref, GOOD_TREATMENT) > 0) RemoveCharacterGoods(chref, GOOD_TREATMENT, 1);
		
			if (GetWoundedCrewQuantity(chref) > 0 || healed_qty > 0 || killed_qty > 0)
			{
				LogIt(GetWoundedCrewQuantity(chref) + " wounded crewmembers: " + healed_qty + " healed and " + killed_qty + " died from gangrene on "+GetMyShipNameShow(chref)+".");
			} // Serge Grey: moved and changed for ship's name outputting (24.05.2018).
		}
		LAi_SetCurHPMax(chref);		// GR: routine personal healing doesn't seem to happen at sea, so heal fully instead
	}

	for (i = 1; i < OFFICER_MAX; i++)	// Heal officers too
	{
		cn = GetOfficersIndex(PChar, i);
		if (cn != -1) LAi_SetCurHPMax(&Characters[cn]);
	}

		
// KK & PB <--

// KK -->
	profit = GetProfitFromTowns();
	AddMoneyToCharacter(pchar, profit);
	if (LogsToggle >= LOG_NORMAL && profit > 0) Log_SetStringToLog(TranslateString("", "You made") + " " + MakeMoneyShow(profit, MONEY_SIGN, MONEY_DELIVER) + " " + TranslateString("", "gold as taxes from controlled towns."));
// <-- KK

	//ransom section
	for(i = 0; i < GetPassengersQuantity(pchar); i++)
	{
		cn = GetPassenger(pchar, i);
		if(cn != -1)
		{
			chref = GetCharacter(cn);
			//MAXIMUS: [if player wants to release captive in location of his nation, he doesn't want to escape anymore]
			if(IsPrisoner(chref) && !CheckAttribute(chref,"released") && !CheckAttribute(chref,"quest.no_escape"))	// GR: new attribute "quest.no_escape" for quest prisoners who must not escape due to plot
			{
				int tmpransom = GetPrisonRansomCost(chref);// NK 04-10-25 change so escape only near shore, make sure ransom increases
				chref.ransom = makeint(stf(chref.ransom) * RANSOM_INC) +1;
				//if(sti(chref.ransom) == tmpransom) chref.ransom = tmpransom + 1;
				bool rtmp = false;
				if(IsEntity(&worldMap) != 0) { if(wdmGetCurrentIsland() != WDM_NONE_ISLAND) { rtmp = true; } }// on wdmap and near island
				else { if(!bSeaActive) { rtmp = true; } } // on land, we presume
				if(rtmp)
				{
					if(frnd() < ESCAPE_CHANCE * (1.0 + makefloat(GetShipSkill(chref, SKILL_SNEAK))) / (1.0 + makefloat(skillLuck))) // was CalcCharacterSkill(pchar, SKILL_SNEAK)
					{
						DeleteAttribute(chref,"prisoned");
						if(GetMySimpleOldName(chref) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
						RemovePassenger(pchar,chref);
						DeleteAttribute(chref,"ransom"); // NK
						ChangeCharacterAddressGroup(chref, "None", "", "");
						chref.location = "none";
						Log_SetStringToLog(TranslateString("","Your prisoner") + " " + GetMySimpleName(chref) + " " + TranslateString("","jumped overboard and escaped!"));
					}
				}// NK <--
			}
		}
	}

	if(!articles) DoDailyCrewPay(); //JA 26Nov06 Calc Pay owed daily.//MAXIMUS

	// Fudge Dragon: Changing Face of the Caribbean -->
	if (sti(GetStorylineVar(FindCurrentStoryline(), "CHANGING_RELATIONS")))
	{ 
		// Sulan: improved code and moved it to nations.c
		RandomNationsRelationsChange();
 	}
	// Fudge Dragon: Changing Face of the Caribbean <--

	if (bCompanionMutiny) ShipMutiny(); // KK
}
