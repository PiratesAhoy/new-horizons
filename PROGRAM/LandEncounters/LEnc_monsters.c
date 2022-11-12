// ccc Nov05  Deleted 6 KB of outcommented code as it messed up this mess even more
// If you wish to restore some of that you'll find it in LEnc_monsters_Old_Oct05.c

// This file has been heavily modded by NK and ccc to let it generate random locationspecific NPCs for every location.
// Before messing with it you'd better contact us at the "PotC modding" forum of www.piratesahoy.com


object LEnc_MonstersLoginObject;

bool LEnc_MonstersLoginStart(ref location)
{
	if (!CheckAttribute(location, "id")) return false; // KK
	ref Pchar = GetMainCharacter();
	bool shipLocation = false;
	bool bChance = true; // KK
	int ivcskip = 0; // KK
	// this should be fine, but I'm not doing it yet...DeleteAttribute(&LEnc_MonstersLoginObject, ""); // NK clear object. 05-07-27
	LEnc_MonstersLoginObject.isind = frnd() <= 0.5;

// KK -->
	string locid = location.id; 

	if (CheckAttribute(PChar,"vcskip")) ivcskip = sti(PChar.vcskip); // NK 04-07
	if (ivcskip == 0 && CheckAttribute(location, "vcskip") == true) ivcskip = sti(location.vcskip);
// <-- KK

	float monkeys, skeletons;
	bool done = false; // NK
	LEnc_MonstersLoginObject.type = "dungeon";
	if(CheckAttribute(location, "type"))
	{
		if(location.type == "brothel")//MAXIMUS: automatically fills brothels by women
		{
			LEnc_MonstersLoginObject.bandit = "0";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			LEnc_MonstersLoginObject.vagabond = "1.0";
			LEnc_MonstersLoginObject.type = "Brothel";
			return true;
		}
		if(location.type == "own_deck") { shipLocation = true; }
		if(location.type == "crew") { shipLocation = true; }
		if(location.type == "ship") { shipLocation = true; }
		if(shipLocation && ivcskip == 0)//MAXIMUS: automatically fills ship by people
		{
			LEnc_MonstersLoginObject.bandit = "0";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			LEnc_MonstersLoginObject.vagabond = "1.0";
			LEnc_MonstersLoginObject.type = location.type;
			return true;
		}
		if(location.id == "Hispaniola_Passage") return false;
		if(location.id == "Hispaniola_temple")
		{
			LEnc_MonstersLoginObject.bandit = "0";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "1.0";
			LEnc_MonstersLoginObject.vagabond = "0";
			LEnc_MonstersLoginObject.type = "Jungle";
			return true;
		}
		if(location.type == "KhaelRoa") return false;   // SECTION FOR KHAEL ROA JUNGLES
		
		if(sti(GetAttribute(location,"ambush"))==1)
		{
			// SCREWFACE : RANDOM AMBUSH MOD
			if (LANDCREWMEMBERS && ivcskip == 0) // WORKS WITH CREWMEMBERS ON SHORE
			{
				if(location.island == "hispaniola")
				{
					switch(rand(30))
					{
						case 0 : Random_natives_group_jungle(rand(6)); break;
						case 1 : Random_pirates_group_jungle(RAND(6)); break;
					}
				}
				if(location.island == "KhaelRoa")
				{
					switch(rand(20))
					{
						case 0 : Random_natives_group_jungle(rand(6)); break;
					}
				}
			} //END

			if (rand(100) > 40)
			{
				LEnc_MonstersLoginObject.bandit = "0";
				LEnc_MonstersLoginObject.skeleton = "0";
				LEnc_MonstersLoginObject.monkey = "0.3";
				LEnc_MonstersLoginObject.mummy = "0";
				LEnc_MonstersLoginObject.vagabond = "0";
				LEnc_MonstersLoginObject.type = "Jungle";
				return true;
			}
			else
			{
				return false;
			}
		}
		// SCREWFACE : AMBUSH ON SEASHORES
		if (LANDCREWMEMBERS && ivcskip == 0) {
			if(location.type == "Seashore") {
				switch(location.island)
				{
					case "guadeloupe":
						switch(rand(45))
						{
							case 0 : Ambush("RabBlack", 5, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 2, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Falaisedefleur":
						switch(rand(45))
						{
							case 0 : Ambush("RabBlack_1", 4, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 7, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Oxbay":
						switch(rand(30))
						{
							case 0 : Ambush("RabBlack", 4, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 7, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Turks":
						switch(rand(20))
						{
							case 0 : Ambush("native", 6, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 8, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Hispaniola":
						switch(rand(20))
						{
							case 0 : Ambush("native", 8, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 8, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "KhaelRoa":
						switch(rand(20))
						{
							case 0 : Ambush("native", 8, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
						}
					break;
					case "Redmond":
						switch(rand(50))
						{
							case 0 : Ambush("RabBlack_1", 4, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 2, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 3, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Conceicao":
						switch(rand(50))
						{
							case 1: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 5, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Cayman":
						switch(rand(30))
						{
							case 0 : Ambush("native", 5, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 3, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 6, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "Cuba":
						switch(rand(40))
						{
							case 0 : Ambush("native", 5, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 3, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 6, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
					case "IslaMuelle":
						switch(rand(40))
						{
							case 0 : Ambush("native", 6, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
							case 1: Random_Raid("smugglers", 2, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
							case 2: Random_Raid("smugglers", 4, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");break;
						}
					break;
				}
			}
		}
		// END
		
		if(location.type == "KR_Jungle")		// KHAEL ROA
		{

			// SCREWFACE : RANDOM AMBUSH MOD
			if (LANDCREWMEMBERS && ivcskip == 0) { // WORKS WITH CREWMEMBERS ON SHORE
				if (location.island == "hispaniola") {
					switch(rand(35))
					{
						case 0 : Ambush("native", 10, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
						case 1 :
							if (rand(1)==0)
								Ambush("RabBlack", 8, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
							else
								Ambush("RabBlack_1", 8, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
							break;
						case 2 : Random_natives_group_jungle(rand(15)); break;
						case 3 : Random_natives_group_jungle(rand(10)); break;
						case 4 : Random_natives_group_jungle(rand(8)); break;
						case 5 : Random_natives_group_jungle(rand(6)); break;
					}
				}
				if (location.island == "KhaelRoa") {
					switch(rand(20))
					{
						case 0 : Ambush("native", 10, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, ""); break;
						case 1 : Random_natives_group_jungle(rand(10)); break;
					}
				}
			} //END

			if(rand(100) > 50)
			{
				LEnc_MonstersLoginObject.bandit = "0";
				LEnc_MonstersLoginObject.skeleton = "0";
				LEnc_MonstersLoginObject.monkey = "0.3";
				LEnc_MonstersLoginObject.mummy = "0";
				LEnc_MonstersLoginObject.vagabond = "0";
				LEnc_MonstersLoginObject.type = "Jungle";
				return true;
			}
			else
			{
				if(rand(100) < 40)
				{
					LEnc_MonstersLoginObject.bandit = "0";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "1.0";
					LEnc_MonstersLoginObject.vagabond = "0";
					LEnc_MonstersLoginObject.type = "Jungle";
					return true;
				}
				else
				{	
					return false;
				}
			}		
		}
		// END OF SECTION FOR KHAEL ROA JUNGLES

		 //NK cccOA1 More locationtypes with monsters
		if(location.type == "jungle") // NK
		{
			// SCREWFACE : RANDOM MILITARY RAID IN JUNGLES
			if (LANDCREWMEMBERS && ivcskip == 0) //WORKS WITH CREWMEMBERS ON SHORE
			{
				int location_or_nation;
				switch(rand(20))
				{
					case 0:
						if (CheckAttribute(location, "townsack"))
							location_or_nation = GettownNation(location.townsack);
						else
							location_or_nation = GetLocationNation(location);
						switch(location_or_nation)
						{
							case ENGLAND : if(GetServedNation() != ENGLAND) {Random_Raid("Soldiers", 10, ENGLAND,  LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;
							case FRANCE : if(GetServedNation() != FRANCE)  {Random_Raid("Soldiers", 10, FRANCE,   LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;
							case SPAIN : if(GetServedNation() != SPAIN)   {Random_Raid("Soldiers", 10, SPAIN,    LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;
							case HOLLAND : if(GetServedNation() != HOLLAND) {Random_Raid("Soldiers", 10, HOLLAND,  LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;
							case PORTUGAL : if(GetServedNation() != PORTUGAL){Random_Raid("Soldiers", 10, PORTUGAL, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;	
							case GUEST1_NATION : if(GetServedNation() != GUEST1_NATION) {Random_Raid("Soldiers", 10, GUEST1_NATION,  LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL,  "MILITARY RAID!!!");}break;
							case PERSONAL_NATION: if(GetServedNation() != PERSONAL_NATION) {Random_Raid("smugglers", 10, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");}break;
						}
					break;

					case 1:
						Random_Raid("smugglers", 8, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "AMBUSH!!!");
					break;

					case 2:
						if (CheckAttribute(location, "townsack"))
							location_or_nation = GettownNation(location.townsack);
						else
							location_or_nation = GetLocationNation(location);
						if (location_or_nation != PIRATE) Random_Patrol("Soldiers", RAND(15), location_or_nation,"SOLDIERS PATROL!");
					break;

					case 3:
						if (CheckAttribute(location, "townsack"))
							location_or_nation = GettownNation(location.townsack);
						else
							location_or_nation = GetLocationNation(location);
						if (location_or_nation != PIRATE) Random_Patrol("Soldiers", RAND(15), location_or_nation,"SOLDIERS PATROL!");
					break;

					case 4:
						Random_pirates_group_jungle(RAND(8));
					break;

					case 5:
						Random_pirates_group_jungle(RAND(6));
					break;
				}
			} // SCREWFACE : END

			LEnc_MonstersLoginObject.type = "jungle";
		}
		// NK -->
		if(location.type=="town" || location.type=="Port")//MAXIMUS
		{
			//SCREWFACE : RANDOM NIGHT PIRATES RAID IN TOWNS AND PORTS
			if (LANDCREWMEMBERS && ivcskip == 0)
			{
				if (makeint(environment.time) > 22.0 || makeint(environment.time) < 8.0 && GettownNation(location.townsack)!=3)
				{
					if(rand(20)==0){Random_Raid("smugglers", 20, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "ALERT!!! PIRATES RAID!!!");}	// was 'LAI_GROUP_NEUTRAL,LAI_GROUP_ENEMY' which makes them attack everyone except you!
				}
				if (makeint(GetLocationNation(location))!=PIRATE) //(GettownNation(location.townsack)!=3)
				{
					if(rand(10)>3){Random_Patrol("Soldiers", RAND(7), GetLocationNation(location),"SOLDIERS PATROL!");}
					if(makeint(environment.time) > 8.0 && makeint(environment.time) < 22.0)
					{
						Random_sailors_group(RAND(6), GetLocationNation(location));
						Random_item_traders(GetLocationNation(location));
						//Random_citizens_group(RAND(4), GetLocationNation(location));
					}
					if(rand(10)>4){Random_pirates_group(RAND(5));}
				}
				else
				{
					if(rand(10)>1){Random_pirates_group(RAND(5));}
					if(makeint(environment.time) > 8.0 && makeint(environment.time) < 22.0)
					{
						Random_sailors_group(RAND(8), GetLocationNation(location));
						Random_item_traders(GetLocationNation(location));
						//Random_citizens_group(RAND(4), GetLocationNation(location));
					}
					if(rand(10)>2){Random_pirates_group(RAND(4));}
				}
			}

			if (ivcskip == 1 && TOWN_VCSKIP_DISABLEALL == 1) return false; // KK
			LEnc_MonstersLoginObject.type = "town";
			if (isDay()) {
				if(frnd() > TOWN_ENC_CHANCE && ivcskip != -1) return false;
			} else {
				if(frnd() > TOWN_ENC_CHANCE_NIGHT && ivcskip != -1) return false;
			}
			LEnc_MonstersLoginObject.bandit = "0";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			LEnc_MonstersLoginObject.vagabond = "1";
			bChance = true;
			if (ivcskip != -1) bChance = frnd() < TOWN_BANDIT_CHANCE * (2.0 - IsDay()); // KK
			if (bChance == true && ivcskip < 1) // KK
			{
				if(DEBUGINFO) Log_SetStringToLog("Loading town with possible bandits");
				bool bpossible = true;
				bool btoday = false;
				if (!CheckAttribute(location, "lastbandit")) {
					location.lastbandit = environment.date.day + " " + environment.date.month;
				} else {
					if (location.lastbandit != environment.date.day + " " + environment.date.month) {
						location.lastbandit = environment.date.day + " " + environment.date.month;
					} else {
						bpossible = frnd() < TOWN_BANDIT_RESPAWN_CH;
						btoday = true; //really should check if you've SEEN / KILLED them, not just if they were GEN'D. But ah well.
						if(DEBUGINFO) Log_SetStringToLog("Bandits already generated" + stringRet(bpossible," but more possible,", " so none."));
					}
				}
				string sTownName = "";
				if(CheckAttribute(location,"townsack")) sTownName = location.townsack;
				float bprob = GetTownMonsterProb(sTownName) / (makefloat(GetTownSize(sTownName))/1000.0);
				bprob *= TOWN_BANDIT_ENC_SCALAR * (2.0 - IsDay());
				bprob *= 0.5 + makefloat(GetDifficulty())/8.0;
				if(btoday) bprob *= TOWN_BANDIT_RESPAWN_SCL; //less if you've already encountered some
				bprob = Clampf(bprob); // to catch <0 or >1 values.
				if(bprob > TOWN_BANDIT_MAX) bprob = TOWN_BANDIT_MAX;
				if(!bpossible) bprob = 0;
				if(DEBUGINFO) Log_SetStringToLog("Bandit prob: " + bprob);
				LEnc_MonstersLoginObject.bandit = bprob;
				LEnc_MonstersLoginObject.vagabond = 1.0 - bprob;
			}
			else { if(DEBUGINFO) Log_SetStringToLog("Loading town with only vags"); }
			done =  true;
		}
		if(location.type == "house")
		{
			if (ivcskip == 1) return false;
			if(CheckAttribute(location, "type") == true && location.type == "Tavern") return false;  // NK for redundancy // KK
			if(CheckAttribute(location, "id") == true && HasSubStr(location.id, "upstairs")) return false;  // PB: No random characters in tavern rooms
			if(!LAi_LocationCanFight() && HOUSE_FIGHTDISABLE_ALL) 
			{
				if(DEBUGINFO) Log_SetStringToLog("House fight check failed");
				return false;
			}
			float scalar = 1.0;
			if(!LAi_LocationCanFight())  scalar = HOUSE_DISFIGHT_SCL;
			if(frnd() > HOUSE_ENC_CHANCE * scalar && !CheckAttribute(location,"lastentermonth"))
			{
				if(DEBUGINFO) Log_SetStringToLog("House Enc check failed, chance was " + HOUSE_ENC_CHANCE * scalar);
				return false;
			}
			int vag = 1;
			done = true;

			// Here we check to see if we already generated person(s) for this house
			bool newvags = true;
			if(CheckAttribute(location,"lastentermonth") && LAi_LocationCanFight()) //so it's not someone else's house
			{
				if(location.lastentermonth == Environment.date.month) { newvags = false; }
			}
			LEnc_MonstersLoginObject.type = "house";
			if(newvags || CheckAttribute(location,"randloc") ) //generate new people for house; ccc randomlocs, always new ones
			{
				if(DEBUGINFO) Log_SetStringToLog("Generate new occupants");
				if(CheckAttribute(location,"lastentermonth")) { DeleteAttribute(location,"lastentermonth"); }
				if(CheckAttribute(location,"vag")) { DeleteAttribute(location,"vag"); }
				if(CheckAttribute(location,"savethesevags")) { DeleteAttribute(location,"savethesevags"); }
				vag = 1; // note that if HOUSE_FIGHTDISABLE_ALL == false, vags WILL sometimes be gen'd in quest-used houses!
				if(frnd() < HOUSE_BANDIT_CHANCE && LAi_LocationCanFight()) vag = 0; // to skip quest-used houses, as above.
				LEnc_MonstersLoginObject.bandit = 1-vag;
				LEnc_MonstersLoginObject.skeleton = "0";
				LEnc_MonstersLoginObject.monkey = "0";
				LEnc_MonstersLoginObject.mummy = "0";
				LEnc_MonstersLoginObject.vagabond = vag;
				if(vag > 0 && LAi_LocationCanFight()) { location.savethesevags = true; location.lastentermonth = Environment.date.month; } //so vag(s) will be registered.
			}
			else //recover old people used
			{
				
				if(frnd() < HOUSE_OLDPEOPLE_REAPPEAR)
				{
					if(DEBUGINFO) Log_SetStringToLog("Recover old vags");
					LEnc_MonstersLoginObject.bandit = "0";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "1";
				}
				else
				{
					//do check for temporary bandits - BARGLARS! Who don't like to be interrupted...
					if(frnd() > HOUSE_OLDPEOPLE_BANDIT || !LAi_LocationCanFight()) return false; //encounter no one
					if(DEBUGINFO) Log_SetStringToLog("Old vag gone at the moment, but...burglers!");
					LEnc_MonstersLoginObject.bandit = "1";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "0";
				}
			}
		}
		if(location.type == "tavern")
		{
			// SCREWFACE : RANDOM TAVERNBRAWL MOD & sailors
			if (LANDCREWMEMBERS && ivcskip == 0) {
				PChar.TAVERNBRAWL = true;// TIH
				if(rand(10)==0)
				{
					LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
					Random_Raid("smugglers", 5, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "TAVERNBRAWL!!!");
				}
				DeleteAttribute(PChar,"TAVERNBRAWL");// TIH
			} else {
				if (ivcskip == 1) return false; // KK
			}
			// END
			LEnc_MonstersLoginObject.type = "tavern";
// KK -->
			//bChance = false;
			//if (ivcskip != -1) bChance = frnd() < TAVERN_ENC_CHANCE;
			//if (!bChance) return false;
// <-- KK
			//Levis Extra atmosphere -->
			if (ivcskip != -1)
			{
				if (Whr_IsNight())
				{
					//Night
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
					{
						//JRH
						Random_sailors_sit_tavern(3+RAND(3), GetLocationNation(location));
						Random_guard_sit_tavern  (  RAND(2), GetLocationNation(location));
						Random_sailors_group     (1+RAND(3), GetLocationNation(location));
						Random_guards_group      (  RAND(1), GetLocationNation(location));
					}
					else
					{	// PB: Total number of characters: Between 2 and 9
						Random_sailors_sit_tavern(1+RAND(2), GetLocationNation(location)); // 1-3 sitting sailors : always one sitting sailor
						Random_guard_sit_tavern  (2*RAND(1), GetLocationNation(location)); // 0-2 sitting soldiers: they come together or not at all
						Random_sailors_group     (  RAND(2), GetLocationNation(location)); // 0-2 walking sailors
						Random_guards_group      (1+RAND(1), GetLocationNation(location)); // 1-2 walking soldiers: always one walking soldier
					}
				}
				else
				{
					//Day
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
					{
						//JRH
						Random_sailors_sit_tavern(1+RAND(1), GetLocationNation(location));
						Random_guard_sit_tavern  (  RAND(2), GetLocationNation(location));
						Random_sailors_group     (  RAND(3), GetLocationNation(location));
						Random_guards_group      (  RAND(1), GetLocationNation(location));
					}
					else
					{	// PB: Total number of characters: Between 1 and 5
						Random_sailors_sit_tavern(1+RAND(1), GetLocationNation(location)); // 1-2 sitting sailors : always one sitting sailor
						Random_guard_sit_tavern  (  RAND(1), GetLocationNation(location)); // 0-1 sitting soldiers
						Random_sailors_group     (  RAND(1), GetLocationNation(location)); // 0-1 walking sailors
						Random_guards_group      (  RAND(1), GetLocationNation(location)); // 0-1 walking soldiers
					}
				}
			}
			//<--Levis extra atmosphere
			float tvag = TAVERN_ENC_QTY;
			if(frnd() < TAVERN_BANDIT_CHANCE) tvag = frnd()/4.0;
			LEnc_MonstersLoginObject.bandit = TAVERN_ENC_QTY-tvag;
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			//LEnc_MonstersLoginObject.vagabond = tvag; // NK
			LEnc_MonstersLoginObject.vagabond = "0"; // Levis extra atmosphere
			done = true;
		}
		// NK <--
	}
	LEnc_MonstersLoginObject.current = "";
	if(ivcskip == 1) return false; // NK
	if(!done) { // NK
	if(LEnc_MonstersLoginObject.type == "jungle")
	{
		if(IsDay())
		{
			// LDH rewritten so you don't get constant bandit encounters - 03Apr09
			// Murphy's Law of Averages:  If there's a 20% chance of something happening, it will happen 5 times in a row.
			if (rand(100) < 50)			// 50% it's empty (original 56%)
			{
//TraceAndLog("Bandits: nothing");
				return false;
			}
			else
			{
				if (rand(100) < 50)		// 25% vagabonds (original 24%)
				{
//TraceAndLog("Bandits: vagabonds");
					LEnc_MonstersLoginObject.bandit = "0";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "1";
				}
				else					// 25% bandits (original 20%)
				{
					string strLastBanditDay = environment.date.day + " " + environment.date.month;
					if (!CheckAttribute(location,"lastbandit") || location.lastbandit != strLastBanditDay)
					{
//TraceAndLog("Bandits: new bandits generated");
						location.lastbandit = strLastBanditDay;
					}
					else
					{
						if (rand(100) < 90)		// 10% chance of bandits regen (original 100%)
						{
//TraceAndLog("Bandits: bandits skipped because we already had them here today");
							return false;	// if already had bandits here today, 2.5% bandits (original 20%), 72.5% empty
						}
//TraceAndLog("Bandits: regenerated bandits");
					}

					// Chances from stock game:     56% empty,   24% vagabonds, 20% bandits
					// No bandits encountered yet:  50% empty,   25% vagabonds, 25% bandits
					// Bandits already encountered: 72.5% empty, 25% vagabonds, 2.5% bandits

					LEnc_MonstersLoginObject.bandit = "1";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "0";
				}
			}
		} 
		else 
		{
			if(rand(100) < 40)			// 40%
			{
				if(rand(100) < 20)		// 8% vagabonds
				{
					LEnc_MonstersLoginObject.bandit = "0";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "1";
				}else{
					return false;		// 32% it's empty
				}
			} 
			else						// 60%
			{
				if(rand(100) < 40)		// 24% bandits
				{
					LEnc_MonstersLoginObject.bandit = "1";
					LEnc_MonstersLoginObject.skeleton = "0";
					LEnc_MonstersLoginObject.monkey = "0";
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "0";
				} 
				else					// 36% skeletons and monkeys
				{
					monkeys = 0.4 + (rand(100)*0.01)*0.6;
					skeletons = 1.0 - monkeys;
					//cccOA1 allow indoors only pseudoskeletons
					if(location.type == "tavern" || location.type == "house")
					{
						skeletons = 1.0;
						monkeys = 0;
					} 	// <- cccOA1
					LEnc_MonstersLoginObject.bandit = "0";
					LEnc_MonstersLoginObject.skeleton = skeletons;
					LEnc_MonstersLoginObject.monkey = monkeys;
					LEnc_MonstersLoginObject.mummy = "0";
					LEnc_MonstersLoginObject.vagabond = "0";
				}
			}
		}
	}
	else
	{
		if(LEnc_MonstersLoginObject.type == "inca_temple")
		{
				LEnc_MonstersLoginObject.bandit = "0";
				LEnc_MonstersLoginObject.skeleton = "0.2";
				LEnc_MonstersLoginObject.monkey = "0.3";
				LEnc_MonstersLoginObject.mummy = "0.5";
				LEnc_MonstersLoginObject.vagabond = "0";
		}
		else
		{
			if(rand(100) < 90)			// 90% skeletons
			{
				LEnc_MonstersLoginObject.bandit = "0";
				LEnc_MonstersLoginObject.skeleton = "1";
				LEnc_MonstersLoginObject.monkey = "0";
				LEnc_MonstersLoginObject.mummy = "0";
				LEnc_MonstersLoginObject.vagabond = "0";
			}
			else						// 10% skeletons and monkeys
			{
				skeletons = 0.8 + (rand(100)*0.01)*0.2;
				monkeys = 1.0 - skeletons;
				LEnc_MonstersLoginObject.bandit = "0";
				LEnc_MonstersLoginObject.skeleton = skeletons;
				LEnc_MonstersLoginObject.monkey = monkeys;
				LEnc_MonstersLoginObject.mummy = "0";
				LEnc_MonstersLoginObject.vagabond = "0";
			}
		}
	}
	// NK -->

	// ccc Greater Oxbay: for all parts of Maltese Abbey regardless of type;
	if(CheckAttribute(location, "abbey") == true && sti(location.abbey) == true) // KK
	{
		LEnc_MonstersLoginObject.bandit = "1.0";	// ccc Nov05 "0.9";
		LEnc_MonstersLoginObject.skeleton = "0";
		LEnc_MonstersLoginObject.monkey = "0";
		LEnc_MonstersLoginObject.mummy = "0";
		LEnc_MonstersLoginObject.vagabond = "0";	// ccc Nov05 "0.1";
		Logit("You are ALONE now. No other LIVING soul dares to enter here..");	// ccc Nov05
	}

	// ccc to enable encounters in fake forts
	if(HasSubStr(locid, "_fakefort") || HasSubStr(locid, "_armory")) // KK
	{
// KK -->
		if (GetCurrentLocationNation() != PERSONAL_NATION) {
			LEnc_MonstersLoginObject.bandit = "0.9";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			LEnc_MonstersLoginObject.vagabond = "0.1";
		} else {
			LEnc_MonstersLoginObject.bandit = "1.0";
			LEnc_MonstersLoginObject.skeleton = "0";
			LEnc_MonstersLoginObject.monkey = "0";
			LEnc_MonstersLoginObject.mummy = "0";
			LEnc_MonstersLoginObject.vagabond = "0";
		}
// <-- KK
	}
	// ccc end
	}
	if(DEBUGINFO)
	{
		if(stf(LEnc_MonstersLoginObject.bandit) + stf(LEnc_MonstersLoginObject.skeleton) + stf(LEnc_MonstersLoginObject.monkey) + stf(LEnc_MonstersLoginObject.mummy) + stf(LEnc_MonstersLoginObject.vagabond) == 0)
			{ Log_SetStringToLog("Nothing generated") ;}
		else
			{ Log_SetStringToLog("Bnd: " + LEnc_MonstersLoginObject.bandit + ", Vag: " + LEnc_MonstersLoginObject.vagabond + ", Sk: " + LEnc_MonstersLoginObject.skeleton + ", Mo: " + LEnc_MonstersLoginObject.monkey + ", Mu: " + LEnc_MonstersLoginObject.mummy); }
	}
// LDH test 03Apr09
	Traceif("Bnd: " + LEnc_MonstersLoginObject.bandit + ", Vag: " + LEnc_MonstersLoginObject.vagabond + ", Sk: " + LEnc_MonstersLoginObject.skeleton + ", Mo: " + LEnc_MonstersLoginObject.monkey + ", Mu: " + LEnc_MonstersLoginObject.mummy);
	return true;
}

bool LEnc_MonstersLoginSelectModel(ref location, aref modelInfo, string group, string locator)
{
// KK -->
	if (!CheckAttribute(location, "id")) return false;
	ref PChar = GetMainCharacter();
	string locid = location.id;
	if (HasSubStr(location.id, "bedroom")) locid = "Bedroom";
// <-- KK
	if (HasSubStr(location.id, "brothel")) locid = "Brothel";
	if(CheckAttribute(location, "type"))
	{
		if(location.type=="crew") locid = "crew";
		if(location.type=="own_deck") locid = "own_deck";
		if(location.type=="ship") locid = "ship";
	}

	modelInfo.type = LEnc_MonstersLoginObject.type; // NK
	modelInfo.sex = "";
	modelInfo.nation = ALL_NATIONS;
	modelInfo.iscombat = -1;
	float bandit = stf(LEnc_MonstersLoginObject.bandit);
	float skeleton = stf(LEnc_MonstersLoginObject.skeleton);
	float vagabond = stf(LEnc_MonstersLoginObject.vagabond);
	float monkey = stf(LEnc_MonstersLoginObject.monkey);
	float mummy = stf(LEnc_MonstersLoginObject.mummy);

	bool found = false;

	// NK 05-07-08 redo this whole darn thing for modeltypes
	// NOTE: the sum of the encounterable monsters must always be <= 1.0
	float p = frnd();
	if(!found && p <= bandit)
	{
		LEnc_MonstersLoginObject.current = "bandit";
		//modelInfo.sex = "man";
		// ccc to enable encounters in fake forts
		if (HasSubStr(locid, "_fakefort") || HasSubStr(locid, "_armory")) { // KK
			if (CheckAttribute(location, "townsack")) {
				modelInfo.iscombat = true;
				modelInfo.model = "Soldiers";
				int iNation = GetTownNation(location.townsack);
				modelInfo.nation = iNation;
			}
		}
		// ccc Greater Oxbay for Maltese Abbey 	
		else
		{
			if (CheckAttribute(location, "abbey") == true && sti(location.abbey) == true) // KK
			{
				modelInfo.iscombat = true;
				/*if(rand(100) < 30){ modelInfo.current = "Priests";}
				else{modelInfo.current = "Maltese";}*/
				modelInfo.model = "Animists3";	// ccc Nov05 "Maltese";
			}
			else
			{
				modelInfo.iscombat = true;
				modelInfo.model = "Bandits";
				modelInfo.nation = GetCurrentLocationNation();
			}
		}
		found = true;
	}
	if(!found && p <= bandit + skeleton)
	{
		LEnc_MonstersLoginObject.current = "skeleton";
		//cccOA1 skeletons replaced at several locations
		switch(location.type)
		{
			case "dungeon":
			//	if(sti(LEnc_MonstersLoginObject.isskel))  //  CCC Enable skeletons in dungeon  -->
			//	{
			//		modelInfo.model = "Skeletons";
			//	}
	        //    else
			//	{
					modelInfo.model = "Smugglers";
					modelInfo.nation = PIRATE;
			//	}
				modelInfo.iscombat = true;
			break;

			case "jungle":
			//	if(sti(LEnc_MonstersLoginObject.ismum))  //  CCC Enable skeletons in dungeon  -->
				if(sti(LEnc_MonstersLoginObject.isind))  // PB: Two types of indians instead
				{
			//		modelInfo.model = "Mummies";
					modelInfo.model = "Indians";
	            }
	            else
	            {
					modelInfo.model = "Natives";
				}
				modelInfo.iscombat = true;
			break;

			case "inca_temple":			// ccc nov04 to delete "smuggler" skeletons from temple
			//	if(frnd() < MUMMY_CHANCE)  //  CCC Enable skeletons in dungeon  -->
			//	{
					modelInfo.model = "Mummies";
			//	}
			//	else
			//	{
			//		modelInfo.model = "Natives";
			//	}
				modelInfo.iscombat = true;
			break;

			// the following cases should NEVER occur, because skels are never assigned to these locations
			case "town":
				modelInfo.model = "Outlaws";
				modelInfo.nation = PIRATE;
				modelInfo.iscombat = true;
			break;

			case "house":
				modelInfo.model = "Vagabonds";
				modelInfo.nation = GetCurrentLocationNation();
			break;

			case "tavern":
				modelInfo.model = OFFIC_TYPE_SAILOR;
				modelInfo.nation = GetCurrentLocationNation();
			break;

			case "Brothel":
				modelInfo.model = "Vagabonds";
				modelInfo.nation = GetCurrentLocationNation();
			break;

			case "crew":
				modelInfo.model = "Vagabonds";
				modelInfo.nation = GetServedNation();
			break;

			case "own_deck":
				modelInfo.model = "Vagabonds";
				modelInfo.nation = GetServedNation();
			break;

			case "ship":
				modelInfo.model = "Vagabonds";
				modelInfo.nation = GetServedNation();
			break;

			// default case:
			modelInfo.sex = "man";		// ccc jan06
			modelInfo.model = "Outlaws";	// ccc jan06

			// Screwface : to have dead skeletons on Turks shore ship
			if(location.id == "Turks_shore_ship" || location.id == "Hispaniola_Grot3"){modelInfo.model = "Skeletons";}
			modelInfo.nation = GetCurrentLocationNation();
		}
		// <- cccOA1
		found = true;
	}
	if(!found && p <= bandit + skeleton + monkey)
	{
		LEnc_MonstersLoginObject.current = "monkey";
		modelInfo.model = "Monkeys";
		found = true;
	}
	if(!found && p <= bandit + skeleton + monkey + mummy)
	{
		LEnc_MonstersLoginObject.current = "mummy";
	//	if(frnd() < MUMMY_CHANCE)  //  CCC Enable skeletons in dungeon  -->
	//	{
	//		modelInfo.model = "Mummies";
	//	}
	//	else
	//	{
			modelInfo.model = "Natives";
	//	}
		found = true;
	}
	if(!found && p <= bandit + skeleton + monkey + mummy + vagabond)
	{
		LEnc_MonstersLoginObject.current = "vagabond";
// KK -->
		if (HasSubStr(locid, "_fakefort") || HasSubStr(locid, "_armory")) locid = "fort";
		if (CheckAttribute(location, "abbey") == true && sti(location.abbey) == true) locid = "abbey";
		if (CheckAttribute(location, "navy") == true && sti(location.navy) == true && GetRandomModelForTypeNation(1, "navy", GetCurrentLocationNation()) != DEFAULT_MODEL) locid = "navy";
// <-- KK
		switch(locid)	// ccc specials for locationspecific encounters
		{
			case "crew":
				modelInfo.sex = "man";
				modelInfo.model = OFFIC_TYPE_SAILOR;
				// Cap'n Crunch -->
				if(ProfessionalNavyNation() != UNKNOWN_NATION)
				{
					modelInfo.nation = ProfessionalNavyNation();
					modelInfo.model = "Soldiers";
				}
				// Cap'n Crunch <--
				if(ModelIsType(PChar.model, "Animists")) modelinfo.model = "Animists";
				if(CheckCharacterItem(PChar, "Davy_Chest")) modelinfo.model = "Davycrew";
				if(CheckCharacterItem(PChar, "Devil_Contract")) modelinfo.model = "Ghost";
			break;

			case "own_deck":
				modelInfo.sex = "man";
				modelInfo.model = OFFIC_TYPE_SAILOR;
				// Cap'n Crunch -->
				if(ProfessionalNavyNation() != UNKNOWN_NATION)
				{
					modelInfo.nation = ProfessionalNavyNation();
					modelInfo.model = "Soldiers";
				}
				// Cap'n Crunch <--
				if(ModelIsType(PChar.model, "Animists")) modelinfo.model = "Animists";
				if(CheckCharacterItem(PChar, "Davy_Chest")) modelinfo.model = "Davycrew";
			break;

			case "ship":
				modelInfo.sex = "man";
				modelInfo.model = OFFIC_TYPE_SAILOR;
				// Cap'n Crunch -->
				if(ProfessionalNavyNation() != UNKNOWN_NATION)
				{
					modelInfo.nation = ProfessionalNavyNation();
					modelInfo.model = "Soldiers";
				}
				// Cap'n Crunch <--
				if(ModelIsType(PChar.model, "Animists")) modelinfo.model = "Animists";
				if(CheckCharacterItem(PChar, "Davy_Chest")) modelinfo.model = "Davycrew";
			break;

			case "Brothel":
				modelInfo.sex = "woman";
				modelInfo.model = "Lower_Citizens";
			break;

			case "Bedroom":
				modelInfo.sex = "woman";
				modelInfo.model = "Rich_Citizens";
			break;

// KK -->
			case "fort":
				modelInfo.sex = "man";
				modelInfo.model = "Rich_Citizens";
				modelInfo.nation = GetCurrentLocationNation(); // Maybe disable this?
			break;

			case "navy":		// Thomas the Terror Sep07 for Redmond/Port Royal
				if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)	modelInfo.model = "navy";
				else												modelInfo.model = "Soldiers";
				modelInfo.nation = GetCurrentLocationNation();
			break;

			case "abbey":
				modelInfo.model = "Monks";
			break;
// <-- KK

			// default:
				modelInfo.model = "Vagabonds";
		}
		found = true;
	}
	modelInfo.current = LEnc_MonstersLoginObject.current;
	return found;

}

void LEnc_MonstersLoginCorrectParams(ref location, aref chr, string group, string locator)
{
	if (!CheckAttribute(location, "id")) return; // KK
	bool isSet = false;
	ref mchr = GetMainCharacter();
	int mchr_rank = sti(mchr.rank);
	DeleteAttribute(chr, "patroltype"); // NK 04-20

	string locid = location.id;
	int iNation = GetTownNation(GetTownIDFromLocID(locid));
	if (HasSubStr(locid, "bedroom")) locid = "Bedroom"; // KK
	if (HasSubStr(locid, "brothel")) locid = "Brothel";
	if (CheckAttribute(location,"type"))
	{
		if(location.type=="crew") locid = "crew";
		if(location.type=="own_deck") locid = "own_deck";
		if(location.type=="ship") locid = "ship";
		if (location.type == "military") locid = "military"; // KK
		if(CheckAttribute(location,"id") && HasSubStr(location.id,"Cannon")) locid = "cannon";
		if (location.type == "house" && HasSubStr(location.filespath.models, "Tavern")) locid = "inn"; // KK
		if (location.type == "house" && HasSubStr(location.filespath.models, "Store")) locid = "Tradepost"; // KK
		if (CheckAttribute(location, "navy") == true && sti(location.navy) == 1 && GetRandomModelForTypeNation(1, "navy", iNation) != DEFAULT_MODEL) locid = "navy"; // KK
	}

	bool  hasBlade = true;  // Swindler 05-10-10: monsters normally has blade
	float gunProb = frnd(); // Swindler 05-10-10: probability for monster to have gun

	switch(chr.current)
	{
	case "bandit":
		isSet = true;
		// NK -->
		//LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
		LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_GUARDS, LAI_GROUP_NEUTRAL);
		// NK <--
		LAi_CharacterReincarnation(chr, false, true);	//cccOA1
		chr.patroltype = true; // NK 04-20
		LAi_type_patrol_Init(chr);			//cccOA1

		chr.dialog.CurrentNode = "First time";		// CCC APR07
		chr.dialog.filename = "Enc_Bandit_dialog.c";		// CCC APR07
		// PB: Booty for Stealing -->
		string itemID = "";
		SpawnItem(chr, &itemID,false,makefloat(CalcCharacterSkill(chr,SKILL_SNEAK)));
		GiveItem2Character(chr, itemID);
		// PB: Booty for Stealing <--

		// ccc Greater Oxbay  stronger fortgarrison
		if(locid == "military") { // KK
			if (CheckAttribute(location,"townsack")) {
				gunProb = 2.0; // Swindler 05-10-10: fortgarrison has gun
				chr.dialog.filename = "patrol_dialog.c";
				// KK -->
				chr.nation = iNation;
				LAi_group_MoveCharacter(chr, GetSoldiersGroup(iNation) ); // ccc Nov05
				// <-- KK
				// jun05 booty for stealing
				if(frnd()<0.2) TakenItems(chr, "pistolgrenade", rand(2));
				if(frnd()<0.2) TakenItems(chr, "pistolrock", rand(2));
			}
		}

		if(CheckAttribute(location, "abbey") == true && sti(location.abbey) == true) // KK
		{
			gunProb = 0.0; // ccc nov05
			LAi_type_citizen_Init(chr); // ccc Nov05 dumb zombie AI
			chr.name = TranslateString("","Weird"); // ccc  nov05
			chr.lastname = TranslateString("","Warriormonk"); // ccc  nov05
			chr.perks.list.BasicDefence = "1"; // ccc  nov05
			chr.perks.list.AdvancedDefence = "1"; // ccc  nov05

			// jun05 booty for stealing
			if(location.id == "Greenford_M_crypt") // PB
			{
				TakenItems(chr, "jewelry"+ makeint(1 + rand(13)), rand(2));
				TakenItems(chr, "jewelry"+ makeint(1 + rand(13)), rand(2));
			}
		}
		break;
		
	case "skeleton":
		 isSet = true;

 		if(chr.model == "mummy" || chr.model == "native")		//ccc 10.2
 		{
			chr.isIndian = true; // Levis
		}
		else
		{
			// ccc sneakmod -> lets monsters walk through dungeons
			if (mchr.model == "animists3")
			{
				 LAi_type_citizen_Init(chr);
			}
			else
			{
				LAi_SetWarriorType(chr);
				LAi_warrior_SetStay(chr, true);
			}
			// ccc sneakmod <-

			LAi_group_MoveCharacter(chr, LAI_GROUP_MONSTERS);
			// jun05 booty for stealing
			if(frnd()<0.2) TakenItems(chr, "pistolgrenade", rand(2));
			if(frnd()<0.2) TakenItems(chr, "pistolrock", rand(2));
		}
		break;
		
	case "monkey":
		isSet = true;
		chr.sex = "monkey";
		LAi_type_monkey_Init(chr);
		hasBlade = false; // Swindler 05-10-10: monkeys don't have blades
		gunProb = 0.0;    // Swindler 05-10-10: monkeys don't have guns

		// ccc -->
		chr.money = 0;
		chr.name = VC_MONKEY_NAME;
		chr.lastname = VC_MONKEY_LNAME;
		// ccc <--
		break;
		
	case "mummy":
		isSet = true;
		chr.sex = "skeleton";
		chr.isIndian = true; // Levis
		break;
		
	case "vagabond":
		isSet = true;
		LAi_CharacterReincarnation(chr, false, true);
		LAi_group_MoveCharacter(chr, GetCitizensGroup(iNation) ); //LAI_DEFAULT_GROUP, NK now place in correct group. 05-07-19

/*	// ccc sneakmod ->
		LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, 0.0);	//ccc10.2
		LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_MONSTERS, 0.0);	//ccc10.2
		LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_GUARDS, 0.0);	//ccc10.2
		LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL); // NK
		LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL); // NK
*/	// ccc sneakmod 
		// NK go back to citizen so we can add addressing only if no hostiles around. 05-07-17
		LAi_type_citizen_Init(chr);
		// --> Swindler 05-10-10: I think, as long vags have rich citizen models, they can also be equipped with good weapons
		gunProb = 0.0;        // Swindler

		// NK -->
		bool restore = CheckAttribute(location,"vag.rich");
		bool save = false;
		if (restore) {save = location.vag.rich == "-1"; }
		restore = restore && !save;
		if (save) {location.vag.rich = false;}
		bool brich = frnd() < VAG_MERCH_CHANCE;
		if(restore) brich = sti(location.vag.rich);
		if(brich)
		{
			if(save) location.vag.rich = true;
			// NK <--
			//cccOA1-> Vagabond changed to rich armed traveller
 			 gunProb *= 1.5; // Swindler 05-10-10: changed the logic of making vag to a rich armed traveller

			int vagamoney = Rand(1000);			//ccc
			int vagahp = vagamoney/4+ Rand(200);		//ccc
			chr.money = vagamoney;			//ccc
			LAi_SetHP(chr, vagahp, vagahp);		//ccc
			if(vagamoney > 250) chr.perks.list.CriticalHit = "1";	//ccc
			if(vagamoney > 550) chr.perks.list.Gunman = "1";	//ccc
			if(vagamoney > 750) chr.perks.list.SwordplayProfessional = "1";	//ccc
			if(CheckAttribute(mchr, "skill.Fencing"))		//ccc
			{
			chr.skill.Fencing = sti(mchr.skill.Fencing) + Rand(3);	//cccOA1<-		
			}
		} // NK
		chr.dialog.CurrentNode = "First time";
		//chr.dialog.filename = "Enc_Walker.c";
		// ->ccc10.2 vaga dialog according to location for the time being
		if(location.type == "house" && CheckAttribute(location,"lastentermonth"))
		{
			chr.dialog.filename = "Enc_Resident_dialog.c";
			if(CheckAttribute(location,"vag.meeting"))	//ccc10.2 "," was missing
			{
				if(sti(location.vag.meeting))
				{
					if(CheckAttribute(location,"friendquest")) {chr.dialog.CurrentNode = "friendquest";} // apr05 friend status
					else {chr.dialog.CurrentNode = "second time";}	// apr05 friend status
				}
			}
		}
		else
		{
 			chr.dialog.filename = "Enc_Walker.c";

			// LDH define greetings for walkers so their heads use talking animation and the sound is played automatically - 18Mar09
			if (chr.sex == "man") chr.greeting = "Gr_to_say";
			else chr.greeting = "Gr_greenford_citizen_01";
 		}
		
		if(chr.sex == "woman")	//NK was LEnc_MonstersLoginObject.current.sex // cccOA1
		{
			chr.perks.list.CriticalHit = "1";			//cccOA1
			chr.perks.list.SwordplayProfessional = "1";	//cccOA1
			GiveItem2Character(chr, "jewelry"+ makeint(1 + rand(15)) );	// jun05 booty for stealing
		}

		switch(locid)	// ccc specials for locationspecific encounters
		{
			case "crew":
				chr.dialog.filename = "Crewmember_fight_dialog.c";
				chr.greeting = "Gr_Seaman";
				if(HasSubStr(locator,"bed"))
				{
					ChangeCharacterAddressGroup(chr, location.id, "rld", locator);
					chr.dialog.filename = "Crewmember_tired_dialog.c";
					chr.sleep = true;//for snore sound
					LAi_SetLayType(chr);
				}
				else
				{
					if(HasSubStr(locator,"sit"))
					{
						chr.dialog.filename = "Crewmember_alc_dialog.c";
						if(Rand(4)>2) chr.greeting = "Gr_Drunk";
						ChangeCharacterAddressGroup(chr, location.id, "sit", locator);
						switch(Rand(1))
						{
							case 0: LAi_SetSitType(chr); break;
							case 1: LAi_SetHuberType(chr); break;
						}
						if(StraifCharacter(chr)) LAi_SetSitType(chr);//MAXIMUS: because of AOP characters
						if(locator=="sit3")//MAXIMUS: gun-carriage locator
						{
							chr.dialog.filename = "Crewmember_fight_dialog.c";
							chr.greeting = "Gr_Seaman";
							if(StraifCharacter(chr)) LAi_SetSitType(chr);
							else LAi_SetHuberType(chr);
						}
					}
					else LAi_SetCitizenType(chr);
				}
				LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
				GiveItem2Character(chr, "potion"+ makeint(1 + rand(3)) );
				chr.old.name = "Crewmember";
				chr.old.lastname = "";
				chr.name = XI_ConvertString("Crewmember");
				chr.lastname = "";
			break;

			case "own_deck":
				ref tmpChr;
				chr.dialog.filename = "Crewmember_fight_dialog.c";
				LAi_SetCitizenType(chr);
				if(CheckAttribute(location,"wheelset"))
				{
					if(CheckAttribute(location, "locators.rld.wheel1"))
					{
						DeleteAttribute(location,"wheelset");
						ChangeCharacterAddressGroup(chr, location.id, "rld", "wheel1");
						group = "rld";
						locator = "wheel1";
					}
				}
				if(CheckAttribute(location,"coxswain"))
				{
					if(CheckAttribute(location, "locators.rld.wheel"))
					{
						if(location.id=="ShipDeck3") location.wheelset = true;
						DeleteAttribute(location,"coxswain");
						ChangeCharacterAddressGroup(chr, location.id, "rld", "wheel");
						group = "rld";
						locator = "wheel";
					}
				}
				LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
				GiveItem2Character(chr, "potion"+ makeint(1 + rand(3)) );
				chr.greeting = "Gr_Seaman";
				chr.old.name = "Crewmember";
				chr.old.lastname = "";
				chr.name = XI_ConvertString("Crewmember");
				chr.lastname = "";
				if(HasSubStr(locator,"wheel") || HasSubStr(locator,"cannon"))//MAXIMUS: locators for cannons and special dialogs not done yet
				{
					if(!bCanEnterToLand)//MAXIMUS: makes working characters
					{
						if(HasSubStr(locator,"cannon") && Rand(10)!=Rand(10)) break;//MAXIMUS: only some characters will work near cannons or in other places
						chr.chr_ai.type.state = "";
						LAi_tmpl_stay_InitTemplate(chr);
						CharacterTurnByLoc(chr, group, locator);
						chr.chr_ai.type.lock = "1";
						chr.dialog.filename = "Crewmember_fight_dialog.c";
						chr.worklocator = locator;//MAXIMUS: needed for CharacterUpdate
						chr.worklocator.group = group;//MAXIMUS: needed for CharacterUpdate
						LAi_SetStayworkType(chr);
						LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
						if(HasSubStr(locator,"cannon")) { chr.dialog.filename = "Crewmember_fight_dialog.c"; }
					}
				}
			break;

			case "ship":
				chr.dialog.filename = "Crewmember_fight_dialog.c";
				LAi_SetCitizenType(chr);
				LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
				GiveItem2Character(chr, "potion"+ makeint(1 + rand(3)) );
				chr.greeting = "Gr_Seaman";
				chr.old.name = "Crewmember";
				chr.old.lastname = "";
				chr.name = XI_ConvertString("Crewmember");
				chr.lastname = "";
			break;

			case "cannon":
				chr.dialog.filename = "Crewmember_fight_dialog.c";//MAXIMUS: I plan a new dialog for cannoneers
//				chr.dialog.filename = "Crewmember_cannon_dialog.c";
				LAi_SetCitizenType(chr);
				LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
				GiveItem2Character(chr, "potion"+ makeint(1 + rand(3)) );
				chr.greeting = "Gr_Seaman";//MAXIMUS: I plan another greeting for cannoneers
				chr.old.name = "Crewmember";
				chr.old.lastname = "";
				chr.name = XI_ConvertString("Crewmember");
				chr.lastname = "";
			break;

			case "Brothel":
				chr.dialog.filename = "wench_dialog.c";
				chr.greeting = "Gr_Wench";
				if(!CheckAttribute(location,"brothels_mom") && !CheckAttribute(location, "permanent_mom"))//MAXIMUS: brothel's mom must be equipped to protect her girls ;)
				{
					chr.dialog.filename = "mistress_dialog.c";
					chr.greeting = "Gr_Brothel's mom";
					location.brothels_mom = true;
					LAi_NPC_Equip(chr, sti(chr.rank), hasBlade, gunProb);
					EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, ARMOR_ITEM_TYPE));
				}
			 	GiveItem2Character(chr, "jewelry"+ makeint(1 + rand(15)) );	// jun05 booty for stealing
			break;

			case "Bedroom":
				chr.dialog.filename = "Enc_Bedroom_dialog.c";
			 	GiveItem2Character(chr, "jewelry"+ makeint(1 + rand(15)) );	// jun05 booty for stealing
				if(CheckAttribute(chr, "id"))
				{
					mchr.quest.LandEnc_ladykiller.win_condition.l1 = "NPC_death";	// GR: why can't modders be consistent and always use PChar? Anyway, this is revenge if you kill the lady in the bedroom
					mchr.quest.LandEnc_ladykiller.win_condition.l1.character = chr.id;

					mchr.quest.LandEnc_ladykiller.win_condition.l2 = "location";
					mchr.quest.LandEnc_ladykiller.win_condition.l2.character = mchr.id;
					mchr.quest.LandEnc_ladykiller.win_condition.l2.location = chr.location;	// When you leave bedroom, character seems to "die" and trigger revenge, so only trigger if she dies in bedroom
					mchr.quest.LandEnc_ladykiller.win_condition = "LandEnc_ladykiller";
					mchr.quest.bedroomlady = chr.id;
					mchr.quest.bedroomlady.location = chr.location;

//					mchr.quest.LandEnc_cancel_ladykiller.win_condition.l1 = "ExitFromLocation";
//					mchr.quest.LandEnc_cancel_ladykiller.win_condition.l1.location = chr.location;
//					mchr.quest.LandEnc_cancel_ladykiller.win_condition = "LandEnc_cancel_ladykiller";
				}
			break;
	
			case "Tradepost":
				chr.dialog.filename = "Enc_Tradepost.c";
				GiveItem2Character(chr, "mineral"+ makeint(1 + rand(2)) );	// jun05 booty for stealing
			break;
	
			case "military": // KK
				chr.dialog.filename = "Enc_Fort_dialog.c";	// ccc dialog for forts
				LAi_group_MoveCharacter(chr, "fort");
				LAi_group_SetRelation(LAI_GROUP_PLAYER, "fort", LAI_GROUP_NEUTRAL);
				LAi_group_SetRelation(LAI_GROUP_GUARDS, "fort", LAI_GROUP_NEUTRAL);
				hasBlade = false; // ccc nov05 must be unarmed
				gunProb = 0.0;    // ccc nov05 must be unarmed
				GiveItem2Character(chr, "potion"+ makeint(3 + rand(1)) );	// jun05 booty for stealing
			break;
	
			case "inn":
				chr.dialog.filename = "Enc_Inn.c";
				GiveItem2Character(chr, "potion"+ makeint(3 + rand(1)) );	// jun05 booty for stealing
			break;

// KK -->
			case "navy":
				if(FindIslandByLocation(location.id) == "Antigua") chr.dialog.filename = "antigua_patrol.c";
				else chr.dialog.filename = "patrol_dialog.c";
				GiveItem2Character(chr, "spyglass"+ makeint(1 + rand(1)));
			break;
// <-- KK
		}
		chr.dialog.TempNode = chr.Dialog.CurrentNode;
		//<-ccc10.2
		break;
	}
	if(LEnc_MonstersLoginObject.type == "inca_temple")
	{
		float maxhp = LAi_GetCharacterMaxHP(chr);
		maxhp = maxhp*0.5;
		LAi_SetHP(chr, maxhp, maxhp);
	}
	//Levis: temp fix for indians:
	if (HasSubStr(chr.model,"indian") || HasSubStr(chr.model,"native"))
	{
		chr.isIndian = true;
	}
	if (sti(GetAttribute(chr, "isIndian")) == true)
	{
		gunProb = 1.0;
		chr.name = VC_MUMMY_NAME; // ccc10.2
		chr.lastname = VC_MUMMY_LNAME; // ccc10.2
		if(VC_MUMMY_NOMONEY) chr.money = 0; // NK
		GiveItem2Character(chr, "indian"+ makeint(1 + rand(15)) );	// jun05 booty for stealing
		GiveItem2Character(chr, "mineral"+ makeint(1 + rand(2)) );	// jun05 booty for stealing
	}
	// Swindler: instead use that call:
	if(locid!="Brothel")
	{
		if(!HasSubStr(locator,"bed"))
		{
			LAi_NPC_Equip(chr, sti(chr.rank), hasBlade, gunProb);
			EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, ARMOR_ITEM_TYPE)); // armor too
		}
	}
	else
	{
		if(chr.sex!="woman")
		{
			LAi_NPC_Equip(chr, sti(chr.rank), hasBlade, gunProb);
			EquipCharacterByItem(&chr, FindCharacterItemByGroup(&chr, ARMOR_ITEM_TYPE)); // armor too
		}
	}
	// Swindler <--

	// ccc Nov05: Good work, Swindler, but then we have to add another correction for UNIQUE weapons here:
	// ccc specials for locationspecific encounters
	if (CheckAttribute(location, "abbey") == true && sti(location.abbey) == true) // KK
	{
		GiveItem2Character(chr, "blade8");
		EquipCharacterByItem(chr, "blade8");
		location.purged = 0;	// tag to check if loc has been purged of ghosts
	}
}

void LEnc_MonstersLoginEnd(ref location)
{
	DeleteAttribute(location,"savethesevags"); // NK
	if(CheckAttribute(location,"brothels_mom")) DeleteAttribute(location,"brothels_mom");//MAXIMUS
}

// PB: More flexible function -->
void LAi_CreateFantomGroup(string modeltype, int bmax, string mainrel, string npcrel, int iNation, string officertype, int offset, bool genrank, string bladeID, string gunID, string attackers_name, string locator)
{
	ref chr;
	string model;

	// LAi Group
	string group = "ambush";
	if(modeltype == "Soldiers" || modeltype == "Navy_office4" || modeltype == "Merchant_Officers" || HasSubStr(modeltype, "Soldier")) // PB: Add ANY soldiers
	{
		group = GetSoldiersGroup(iNation);	// ccc Nov05: Make local guards if modeltype is "Soldiers"
		if (gunID == "") gunID = "All";	// PB: Soldiers always get guns
	}

	// Blade
	bool hasblade = true;
	if (bladeID == "None")
	{
		hasblade = false;
		bladeID = "";
	}
	
	// Gun
	float hasgun = 0.5;
	if (gunID == "None")
	{
		hasgun = 0.0;
		gunID = "";
	}
	if (gunID == "All")
	{
		hasgun = 1.0;
		gunID = "";
	}
	
	// Combat Enabled
	int iscombat = 1;								// If any weapons, model must support fighting
	if (!hasblade && hasgun == 0.0)	iscombat = -1;	// No weapons at all, so choose from ALL models, including those that don't support fighting
	
	// Officer type
	if (officertype == "")	officertype = OFFIC_TYPE_GUARD;

	for(int i = 0; i < bmax; i++)
	{
		model = GetRandomModelForTypeNation(iscombat, modeltype, iNation); // may return female models too, depending on the group
		chr = LAi_CreateFantomCharacterRk(npcrel ==  LAI_GROUP_FRIEND, offset, genrank, officertype, hasblade, hasgun, model, LAi_GroupForLocator(locator), locator);
 
		// El Rapido: Assign a name to the attackers, maybe "Elite Soldiers" or "Pirate Hunters" or "Governor's Lifeguard".
		if (attackers_name != "")
		{
			chr.name       = attackers_name;
			chr.middlename = "";
			chr.lastname   = ""; 
		}
		
		// TIH: Custom Sword, used for tavernbrawl fists only mod Jul15'06
		if (bladeID != "")
		{
			TakeItemFromCharacter(chr, GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE));
			RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
			if(!CheckCharacterItem(chr, bladeID))	GiveItem2Character(chr, bladeID);
			EquipCharacterByItem(chr, bladeID);
		}
		
		// PB: Custom Gun
		if (gunID != "")
		{
			TakeItemFromCharacter(chr, GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE));
			RemoveCharacterEquip(chr, GUN_ITEM_TYPE);
			if(!CheckCharacterItem(chr, gunID))	GiveItem2Character(chr, gunID);
			EquipCharacterByItem(chr, gunID);
			LAi_NPC_Ammo(chr); // JRH
		}
		
		LAi_SetWarriorType(chr);
		LAi_group_MoveCharacter(chr, group);
	}

	LAi_group_SetRelation(LAI_GROUP_PLAYER, group, mainrel);
	if(mainrel=="enemy")
	{
		// PB: Don't draw blades if not necessary -->
		if(CheckAttribute(GetMainCharacter(), "locationLock"))
		{
			LAi_group_SetHearRadius(group, 40000000.0);
			LAi_group_SetSayRadius(group, 40000000.0);
		}
		// PB: Don't draw blades if not necessary <--
		else
		{
			LAi_group_FightGroups(group, LAI_GROUP_PLAYER, true);
		}
	}

	LAi_group_SetRelation(LAI_GROUP_GUARDS, group, npcrel);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, group, npcrel);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, group, npcrel);

	// ccc Nov05 set relation to local soldiers (which are NOT! LAI_GROUP_GUARDS) with NK's new function
	SetAllNormalGroupsRel(group, npcrel);
	
	if(npcrel=="enemy") LAi_group_FightGroups(group, LAI_GROUP_GUARDS, true);
}

string LAi_GroupForLocator(string locator)
{
	if (HasSubStr(locator, "reload"))	return "reload";
	if (HasSubStr(locator, "rld"))		return "reload";
	if (HasSubStr(locator, "goto"))		return "goto";
	if (HasSubStr(locator, "monster"))	return "monsters";
	return "";
}
// PB: More flexible function <--

void Random_Raid(string modeltype, int bmax, int iNation, string mainrel, string npcrel, string alert)		
{
	// PB -->
	string bladeID = "";
	string gunID   = "";
	if (TAVERNBRAWL_FISTSONLY && CheckAttribute(GetMainCharacter(),"TAVERNBRAWL"))
	{
		bladeID = "bladeX4";
		gunID   = "None";
	}

	LAi_CreateFantomGroup(modeltype, bmax, mainrel, npcrel, iNation, OFFIC_TYPE_GUARD, 0, true, bladeID, gunID, "", LAi_FindRandomLocator("reload"));
	if (alert != "")	LogIt(alert);											// Don't show empty log messages
	PlaySound("OBJECTS\abordage\abordage2.wav");								// Just for fun
	// PB <--
}

void Random_Patrol(string type, int bmax, int nation,string alert)		
{
	if(bmax<=2) return;
	//int tmpNameFileID = LanguageOpenFile("characters_names.txt");
	Log_SetStringToLog(alert);
	//PlaySound("OBJECTS\abordage\abordage2.wav");

	ref chr, chr_prec;
	float hasgun;
	string group, locator;
	hasgun = 0.5;
	group = "goto";
	locator = LAi_FindRandomLocator(group);
	
	for(int i = 0; i < bmax; i++)
	{
		if(i==0)
		{
			chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, SelectSoldierModelByNation(nation, "Land_Officers"), group, locator);
			//chr.middlename = "";
			chr.old.name = "Officer";
			chr.name = TranslateString("","Officer");
			Chr.lastname="";
			LAi_SetPatrolType(chr);
		}
		else
		{
			chr = LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, type, "man", nation), group, locator);
			//chr.middlename = chr_prec.id;
			chr.old.name = "Soldier";
			chr.name = TranslateString("","Soldier");
			Chr.lastname="";
			LAi_SetWarriorType(chr);
			LAi_warrior_DialogEnable(chr, true);
			LAi_tmpl_SetFollow(chr, chr_prec, 120000);
		}
		chr.Dialog.Filename = "Random_Patrol_dialog.c";
		chr.nation = nation;

		LAi_group_MoveCharacter(chr, GetSoldiersGroup(nation) );
		chr.greeting = GetSoldiersGreeting(nation, GetTownIDFromLocID(chr.location));
		chr_prec = CharacterFromId(chr.id);
	}
	if(GetNationRelation2MainCharacter(nation) == RELATION_FRIEND)
	{
		LAi_group_SetRelation(GetSoldiersGroup(nation), LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
	}
	else
	{
		LAi_group_SetRelation(GetSoldiersGroup(nation), LAI_GROUP_MONSTERS, LAI_GROUP_NEUTRAL);
	}

	//LanguageCloseFile(tmpNameFileID);
}

void Random_pirates_group(int bmax)		
{
	if(bmax <= 2) return;
	//Log_SetStringToLog("pirate group");

	ref chr, chr_prec;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	locator = LAi_FindRandomLocator(group);
	
	for(int i = 0; i < bmax; i++)
	{
		if(i==0)
		{
			if(rand(4)>3){ani="woman";}else{ani="man";}
			chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "captains", ani, PIRATE), group, locator);
			//chr.middlename = "";
			chr_prec = CharacterFromId(chr.id);
			LAi_SetCivilianPatrolType(chr);
		}
		else
		{
			if(rand(3)==0)
			{
				if(rand(4)>2){ani="woman";}else{ani="man";}
				chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "mates", ani, PIRATE), group, locator);
			}
			else
			{
				ani="man";
				chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_SAILOR, ani, PIRATE), group, locator);
			}
			LAi_SetwarriorType(chr);
			LAi_warrior_DialogEnable(chr, true);		
		}
		LAi_group_MoveCharacter(chr, "random_pirates_group");
		chr.Dialog.Filename = "Random_pirates_group_dialog.c";
		chr.nation = PIRATE;
		if(i>0){LAi_tmpl_SetFollow(chr, chr_prec, 120000);} // PB: was chr.middlename = chr_prec.id;
		if(chr.sex=="woman"){chr.greeting = "Gr_Random_pirates_group_woman";chr.ani="woman";}
		else{chr.greeting = "Gr_Random_pirates_group";}
	}
	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("random_sailors_group", "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentCitizenGroup(), "random_pirates_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_pirates_group", LAI_GROUP_NEUTRAL);
}

void Random_sailors_group(int bmax, int nation)		
{
	if(bmax==0) return;
	//Log_SetStringToLog("sailors group");

	ref chr, chr_prec;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	
	for(int i = 0; i < bmax; i++)
	{
		locator = LAi_FindRandomLocator(group); //Levis moved in the loop to spread them more
		chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_SAILOR, ani, nation), group, locator);
		if(i==0)
		{
			//chr.middlename = "";
			chr_prec = CharacterFromId(chr.id);
		}
		chr.Dialog.filename="Enc_walker.c";
		LAi_SetCivilianPatrolType(chr);
		if(nation==3){chr.nation=rand(5);}
		else{chr.nation = nation;}
		LAi_group_MoveCharacter(chr, GetCurrentCitizenGroup());
	}
/*	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("random_pirates_group", "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentCitizenGroup(), "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_sailors_group", LAI_GROUP_NEUTRAL);*/
}

//Levis extra atmosphere -->
void Random_guards_group(int bmax, int nation)
{
	if(bmax==0) return;
	if(nation == PIRATE) return; // PB: No pirate guards in taverns

	ref chr;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	
	for(int i = 0; i < bmax; i++)
	{
		locator = LAi_FindRandomLocator(group);
		chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "Soldiers", ani, nation), group, locator);
		chr.Dialog.filename="random_guards_group_dialog.c";
		LAi_SetCivilianPatrolType(chr);
		chr.nation = nation;
		LAi_group_MoveCharacter(chr, GetCurrentSoldierGroup());
	}
/*	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_guard_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("random_pirates_group", "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentCitizenGroup(), "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_guards_group", LAI_GROUP_NEUTRAL);*/
}
//<-- Levis extra atmosphere

void Random_citizens_group(int bmax, int nation)		
{
	if(bmax==0) return;
	//Log_SetStringToLog("CITIZEN GROUP");

	ref chr, chr_prec;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	locator = LAi_FindRandomLocator(group);
	
	for(int i = 0; i < bmax; i++)
	{
		int citizentype= Rand(1);
		switch(citizentype)
		{
			case 0 : //UPPER
				if(nation!=PIRATE)
				{
					if(rand(10)>5){ani="woman";}else{ani="man";}
					chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "Upper_citizens", ani, nation), group, locator);
					LAi_SetCitizenType(chr);
					//chr.Dialog.filename="Enc_walker.c";
					chr.nation = nation;
				}
			break;

			case 1 : //RICH
				if(nation!=PIRATE)
				{
					chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "Rich_citizens", "man", nation), group, locator);
					chr.nation = nation;
					//chr.middlename = "";
					chr_prec = CharacterFromId(chr.id);
					LAi_SetCitizenType(chr);
					If(rand(10)>5)
					{
						chr=LAi_CreateFantomCharacterEx(false, 0, true, false, false, GetRandomModelForTypeExSubCheck(1, "Rich_citizens", "woman", nation), group, locator);
						//LAi_SetCivilianPatrolType(chr);
						//LAi_SetCitizenType(chr);
						LAi_SetWarriorType(chr);
						LAi_warrior_DialogEnable(chr, true);
						//chr.middlename = chr_prec.id;
						chr.nation = nation;
						LAi_group_MoveCharacter(chr, GetCurrentCitizenGroup());
						LAi_tmpl_SetFollow(chr, chr_prec, 120000);
					}
				}
			break;
		
		}
	}
	//LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_pirates_group", LAI_GROUP_NEUTRAL);
}

//Levis Extra Atmosphere-->
void Random_guard_sit_tavern(int bmax, int nation)		
{
	if(bmax==0) return;
	if(nation == PIRATE) return; // PB: No pirate guards in taverns

	ref chr;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "sit";
	for(int i = 0; i < bmax; i++)
	{
		float x,y,z;
		GetCharacterPos(GetMainCharacter(), &x, &y, &z);
		if(i>0)
		{
			GetCharacterPos(chr, &x, &y, &z);
		}
		//locator = Lai_FindNearestFreeLocator(group, x, y, z);
		locator = LAi_FindRandomLocator(group);
		if (locator!="")
		{
			chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "Soldiers", ani, nation), group, locator);	
			chr.Dialog.filename="random_guards_group_dialog.c";
			LAi_SetSitType(chr);
			chr.nation = nation;
			LAi_group_MoveCharacter(chr, GetCurrentSoldierGroup());
		}
	}
/*	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_guards_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("random_sailors_sit", "random_guards_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_guards_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_guards_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_guards_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentCitizenGroup(), "random_guards_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_guards_sit", LAI_GROUP_NEUTRAL);*/
}
// <--Levis extra atmosphere
void Random_sailors_sit_tavern(int bmax, int nation)		
{
	if(bmax==0) return;
	//Log_SetStringToLog("sailors sit");

	ref chr;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "sit";
	for(int i = 0; i < bmax; i++)
	{
		float x,y,z;
		GetCharacterPos(GetMainCharacter(), &x, &y, &z);
		if(i>0)
		{
			GetCharacterPos(chr, &x, &y, &z);
		}
		//locator = Lai_FindNearestFreeLocator(group, x, y, z);
		locator = LAi_FindRandomLocator(group);
		if (locator!="")
		{
			if(rand(10)>9)
			{
				ani = "man";
				chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "Captains", ani, nation), group, locator);	
				chr.Dialog.filename="Random_captains_sit_tavern_dialog.c";
			}
			else
			{
				if(rand(10)>8)
				{
					ani = "man";
					chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "mates", ani, nation), group, locator);
					chr.Dialog.filename="Random_mates_sit_tavern_dialog.c";
				}
				else
				{
					ani="man";
					chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_SAILOR, ani, nation), group, locator);
					chr.Dialog.Filename = "Random_sailors_sit_tavern_dialog.c";
					chr.sex ="man";
				}
			}
			LAi_SetSitType(chr);
			chr.nation = nation;
			//if(chr.sex=="woman"){chr.ani="woman";}
			LAi_group_MoveCharacter(chr, GetCurrentCitizenGroup());
		}
	}
/*	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_sailors_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation("random_sailors_sit", "random_sailors_group", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_sailors_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_sailors_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_sailors_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentCitizenGroup(), "random_sailors_sit", LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_sailors_sit", LAI_GROUP_NEUTRAL);*/
}

void Random_item_traders(int nation)		
{
	string ani, group, locator, locator2, model;
	group = "merchant";
	if(IsEntity(loadedLocation) != true) return;
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return;
	//Log_SetStringToLog("Item traders");

	ref chr;
	float hasgun;
	hasgun = 0.5;
	ani = "man";

	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return;

	for(int i = 0; i < num; i++)
	{
		bool fini = false;
		aref loc = GetAttributeN(grp, i);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			if(HasSubStr(GetAttributeName(GetAttributeN(grp, i)),"merchant"))
			{
				while(!fini)
				{
					if(rand(10)>5){ani="woman";}else{ani="man";}
					if(rand(10)==0){model = GetRandomModelForTypeExSubCheck(1, "Middle_citizens", ani, nation);}
					else{model = GetRandomModelForTypeExSubCheck(1, "lower_citizens", ani, nation);}
				
					if(model!= DEFAULT_MODEL)
					{
						fini = true;
						chr=LAi_CreateFantomCharacterEx(false, 0, true, false, 0, model, group, GetAttributeName(GetAttributeN(grp, i)));		
						chr.Dialog.filename="Item Trader_Dialog.c";
						LAi_SetMerchantType(chr);
						chr.nation = nation;
						chr.name 	= "Street";
						chr.middlename 	= "";
						chr.lastname 	= "Merchant";
						switch(makeint(nation))
						{
							case 0 : chr.greeting = "Gr_Oxbay Citizen";break;
							case 1 : chr.greeting = "Gr_falaise de fleur citizen";break;
							case 2 : chr.greeting = "Gr_isla muelle citizen";break;
							case 3 : chr.greeting = "Gr_QC Citizen";break;
							case 4 : chr.greeting = "Gr_Douwesen Citizen";break;
							case 5 : chr.greeting = "Gr_Conceicao Citizen";break;
						}
					}
				}
			}
		}
	}
}

void Random_natives_group_jungle(int bmax)		
{
	if(bmax <= 2) return;
	//Log_SetStringToLog("pirate group");

	ref chr, chr_prec;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	locator = LAi_FindRandomLocator(group);
	
	for(int i = 0; i < bmax; i++)
	{
		chr=LAi_CreateFantomCharacterEx(false, 0, true, true, 0, GetRandomModelForTypeExSubCheck(1, "native", ani, PIRATE), group, locator);
		if(i==0)
		{
			//chr.middlename = "";
			chr_prec = CharacterFromId(chr.id);
			LAi_SetCivilianPatrolType(chr);
		}
		else
		{
			LAi_SetwarriorType(chr);
			//LAi_warrior_DialogEnable(chr, true);		
		}
		LAi_group_MoveCharacter(chr, "random_natives_group_jungle");
		if(i>0){LAi_tmpl_SetFollow(chr, chr_prec, 120000);} // PB: was chr.middlename = chr_prec.id;
	}
	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_natives_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_natives_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_natives_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_natives_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_natives_group_jungle", LAI_GROUP_ENEMY);
}

void Random_pirates_group_jungle(int bmax)		
{
	if(bmax <= 2) return;
	//Log_SetStringToLog("pirate group");

	ref chr, chr_prec;
	float hasgun;
	string ani, group, locator;
	hasgun = 0.5;
	ani = "man";
	group = "goto";
	locator = LAi_FindRandomLocator(group);
	
	for(int i = 0; i < bmax; i++)
	{
		if(i==0)
		{
			if(rand(4)>3){ani="woman";}else{ani="man";}
			chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "captains", ani, PIRATE), group, locator);
			//chr.middlename = "";
			chr_prec = CharacterFromId(chr.id);
			LAi_SetCivilianPatrolType(chr);
		}
		else
		{
			if(rand(3)==0)
			{
				if(rand(4)>2){ani="woman";}else{ani="man";}
				chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, "mates", ani, PIRATE), group, locator);
			}
			else
			{
				ani="man";
				chr=LAi_CreateFantomCharacterEx(false, 0, true, true, hasgun, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_SAILOR, ani, PIRATE), group, locator);
			}
			LAi_SetwarriorType(chr);
			//LAi_warrior_DialogEnable(chr, true);		
		}
		LAi_group_MoveCharacter(chr, "random_pirates_group_jungle");
		if(i>0){LAi_tmpl_SetFollow(chr, chr_prec, 120000);} // PB: was chr.middlename = chr_prec.id;
	}
	LAi_group_SetRelation(LAI_GROUP_PLAYER, "random_pirates_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, "random_pirates_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_DEFAULT_GROUP, "random_pirates_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, "random_pirates_group_jungle", LAI_GROUP_ENEMY);
	LAi_group_SetRelation(GetCurrentSoldierGroup(), "random_pirates_group_jungle", LAI_GROUP_ENEMY);
}
