/*====================================================|START OF SKILLS-SECTION|====================================================*/

bool IsMainCharacter(ref chr)
{
	if(sti(GetAttribute(chr,"index"))==GetMainCharacterIndex())	return true;
																return false;
}

bool IsUsedAlliesModel(ref chr)
{
	if(!bAllies(chr))
	{
		if(IsUsedOfficerModel(chr))// for excluding twins-officers
		{
			trace("Officer's twin found!!!");
			return true;
		}
		if(IsUsedMainCharacterModel(chr))// for excluding main character's twins
		{
			trace("Main character's twin found!!!");
			return true;
		}
	}

	return false;
}

bool IsUsedMainCharacterModel(ref chr)
{
	if(!CheckAttribute(chr,"model")) return false;

	ref PChar = GetMainCharacter();
	string CharacterModel = chr.model;
	if(CharacterModel==PChar.model || CharacterModel==strcut(PChar.model,0,strlen(PChar.model)-3)) return true;

	return false;
}

bool IsUsedOfficerModel(ref chr)
{
	if(!CheckAttribute(chr,"model")) return false;
	if(CheckAttribute(chr,"Dialog.Filename"))
	{
		if(chr.Dialog.Filename!="Enc_Officer_dialog.c" && chr.Dialog.Filename!="Enc_Walker.c") return false;
	}

	ref PChar = GetMainCharacter();
	int i, j, tempIdx, tempNum;
	ref tempChar, tmpChar;

// ******* STEP 1/4: CHECKING OFFICERS *******
	for(i=1; i<OFFICER_MAX; i++)
	{
		tempIdx = GetOfficersIndex(PChar,i);
		if(tempIdx>=0)
		{
			tempChar = &characters[tempIdx];
			if(chr.model==tempChar.model) return true;
			if(chr.model=="Beatrice" && tempChar.model=="BeatriceA") return true;
			if(chr.model=="BeatriceA" && tempChar.model=="Beatrice") return true;
		}
	}

// ******* STEP 2/4: CHECKING COMPANIONS AND THEIR OFFICERS *******
	for(i=1; i<COMPANION_MAX; i++)
	{
		tempIdx = GetCompanionIndex(PChar,i);
		if(tempIdx>=0)
		{
			tempChar = &characters[tempIdx];
			if(chr.model==tempChar.model) return true;
			if(chr.model=="Beatrice" && tempChar.model=="BeatriceA") return true;
			if(chr.model=="BeatriceA" && tempChar.model=="Beatrice") return true;
			for(j=1; j<OFFICER_MAX; j++)
			{
				tempNum = GetOfficersIndex(tempChar,j);
				if(tempNum>=0)
				{
					tmpChar = &characters[tempNum];
					if(chr.model==tmpChar.model) return true;
					if(chr.model=="Beatrice" && tmpChar.model=="BeatriceA") return true;
					if(chr.model=="BeatriceA" && tmpChar.model=="Beatrice") return true;
				}
			}
		}
	}

// ******* STEP 3/4: CHECKING CAPTAINS ON SHORE LEAVE AND THEIR OFFICERS *******
	for(i=0; i<TOWNS_QUANTITY; i++) // Screwface
	{
		string tempstring1 = "port" + i;
		for(j=1; j<5; j++)
		{
			string tempstring2 = "slot" + j;
			if(CheckAttribute(PChar,"ShipBerthing."+tempstring1+"."+tempstring2+".status") && sti(PChar.ShipBerthing.(tempstring1).(tempstring2).status)==2)
			{
				tempIdx = sti(PChar.ShipBerthing.(tempstring1).(tempstring2).captainindex);
				tempChar = &characters[tempIdx];
				if(chr.model==tempChar.model) return true;
				if(chr.model=="Beatrice" && tempChar.model=="BeatriceA") return true;
				if(chr.model=="BeatriceA" && tempChar.model=="Beatrice") return true;
				for(int k=1; k<OFFICER_MAX; k++)
				{
					tempNum = GetOfficersIndex(tempChar,k);
					if(tempNum>=0)
					{
						tmpChar = &characters[tempNum];
						if(chr.model==tmpChar.model) return true;
						if(chr.model=="Beatrice" && tmpChar.model=="BeatriceA") return true;
						if(chr.model=="BeatriceA" && tmpChar.model=="Beatrice") return true;
					}
				}
			}
		}
	}

// ******* STEP 4/4: CHECKING NON-OFFICERS PASSENGERS *******
	for (i=0; i<GetPassengersQuantity(PChar); i++)
	{
		tempIdx = GetPassenger(PChar,i);
		if(tempIdx>=0)
		{
			tempChar = &characters[tempIdx];
			if(!IsOfficer(tempChar))
			{
				if(chr.model==tempChar.model) return true;
				if(chr.model=="Beatrice" && tempChar.model=="BeatriceA") return true;
				if(chr.model=="BeatriceA" && tempChar.model=="Beatrice") return true;
			}
		}
	}

	return false;
}

bool bAllies(ref chr)
{
	if(!CheckAttribute(chr,"index"))						return false;
	if(sti(chr.index)==-1)									return false;

	if(IsMainCharacter(chr))								return true;
	if(IsCompanion(chr))									return true;
	if(IsOfficer(chr))										return true;
	if(IsOfficerCompanion(chr))								return true;
	if(IsPassenger(chr))									return true;
	if(IsOnShoreLeave(chr))									return true;
	if(IsOfficerOnShoreLeave(chr))							return true;
	if(CheckAttribute(chr, "StoredFellow"))					return true; // PB: Prevent these characters being overwritten
	if(GetAttribute(chr,"chr_ai.group")==LAI_GROUP_PLAYER)	return true; // PB
	return false;
}
/*====================================================|END OF SKILLS-SECTION|====================================================*/

/*=======================================================|QUESTS  SECTION|=======================================================*/
string GenerateMR(ref PChar, ref NPChar)
{
	string mr_3 = "MR_3";
	if (PChar.sex == "woman") mr_3 = "MR_3M";
	PChar.quest.RemoveMRs.win_condition.l1 = "ExitFromLocation";
	PChar.quest.RemoveMRs.win_condition.l1.location = PChar.location;
	PChar.quest.RemoveMRs.win_condition = "RemoveMRs";

	return XI_ConvertString("MR_1") + " " + GetMyRespectfullyName(PChar) + XI_ConvertString("MR_2") + " " + XI_ConvertString(NPChar.currentMR.relationtype) + " " + Characters[GetCharacterIndex(NPChar.currentMR)].name + XI_ConvertString(mr_3);
}

string GenerateTradeQuest(ref pchar, int iTradeNation, int iTradeGoods, float fprice, float tprice, bool bMain)// moved here from traders dialogs
{
	int i, iQuantityGoods, iMoney, iTradeExp, iDaysExpired, chridx;
	float fDistance, fWeight, pricediff;
	string sTown = "";
//MAXIMUS -[such functions must be universal (IMHO), if we are planning to make a real Caribbean in the future]->
	string friendlyTowns = "";
	string pirateTowns = "";
	ref chr;
	for(i = 0; i < TOWNS_QUANTITY; i++)
	{
		if(!CheckAttribute(&Towns[i],"id")) continue;
		if(!CheckAttribute(&Towns[i],"nation")) continue;
		if(GetAttribute(&Towns[i],"skiptrade") == true) continue;//MAXIMUS: added for some towns (such as St. John's on Antigua)
		if(sti(Towns[i].nation) != iTradeNation) continue;
		if(GetIslandIDFromTown(Towns[i].id) == GetIslandIDFromTown(GetCurrentTownID())) continue;
		friendlyTowns = StoreString(friendlyTowns,Towns[i].id);
	}
	if (friendlyTowns != "") {
		sTown = GetRandSubString(friendlyTowns);
		while (sTown == "" || HasSubStr(sTown, ","))
		{
			sTown = GetRandSubString(friendlyTowns);
		}
	} else {
		sTown = "Quebradas Costillas"; //MAXIMUS: Quebradas Costillas - why some trader can't trade with pirates?
	}
	iQuantityGoods = GetSquadronFreeSpace(pchar, iTradeGoods) * 4/5; // NK ratio 05-05-12
	fDistance = GetTownDistance2D(GetCurrentTown(), GetTownFromID(sTown));
	fWeight = GetGoodWeightByType(iTradeGoods, iQuantityGoods);
	// money was ((iQuantityGoods *10+99)/100)*100;
	// should give ~40k (at scl 0.02) for 2000 goods brought 1000 distance, and you get a commission on the sale.
	pricediff = tprice - fprice;
	if (pricediff < 1.0) pricediff = 1.0;
	iMoney = round(GetCharPriceMod(PChar, PRICE_TYPE_SELL, true, false) * fDistance * fWeight * TRADEQUEST_DIST_SCL + pricediff * iQuantityGoods * TRADEQUEST_COMMISSION);
	iTradeExp = round(fDistance * sqrt(fWeight) * TRADEQUEST_DIST_SCL * 10);
	iDaysExpired = 20 + makeint(fDistance/100);
	// NK <--

	if(!bMain) return "";

	pchar.quest.generate_trade_quest_progress.iTradeGoods = iTradeGoods;
	pchar.quest.generate_trade_quest_progress.iQuantityGoods = iQuantityGoods;
	pchar.quest.generate_trade_quest_progress.iMoney = iMoney;
	pchar.quest.generate_trade_quest_progress.iTradeExp = iTradeExp;
	pchar.quest.generate_trade_quest_progress.iTradeNation = iTradeNation;
	//MAXIMUS -->
	pchar.quest.generate_trade_quest_progress.iTradeColony = sTown;
// KK -->
	for (i = 0; i < TOWNS_QUANTITY; i++)
	{
		chridx = GetTownStoreOwnerIndex(Towns[i].id);
		if (chridx < 0) continue;
		chr = GetCharacter(chridx);
		if (CheckAttribute(chr, "store") && sti(chr.store) >= 0) continue;
		if (CheckAttribute(chr, "location") && chr.location != "") SetStoreOwner(chr.location, chridx);
	}
// <-- KK
	pchar.quest.generate_trade_quest_progress.iStoreOwner = "";
	int iStoreOwner = GetTownStoreOwnerIndex(sTown); // KK
	if (iStoreOwner >= 0) pchar.quest.generate_trade_quest_progress.iStoreOwner = GetMySimpleName(characterFromID(characters[iStoreOwner].id)); // KK
	//MAXIMUS <--

	return FindTownName(sTown);
}

void TradeQuestDone()
{
	ref PChar = GetMainCharacter();

	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(PChar, "Leadership", (makeint(PChar.quest.generate_trade_quest_progress.iTradeExp)/10));
		AddPartyExpChar(PChar, "Commerce", makeint(PChar.quest.generate_trade_quest_progress.iTradeExp));
		AddPartyExpChar(PChar, "Sneak", (makeint(PChar.quest.generate_trade_quest_progress.iTradeExp)/100));
	}
	else { AddPartyExp(PChar, (makeint(PChar.quest.generate_trade_quest_progress.iTradeExp))); }
	AddMoneyToCharacter(PChar, makeint(PChar.quest.generate_trade_quest_progress.iMoney));
	PlayStereoSound("INTERFACE\took_item.wav");
	PChar.quest.generate_trade_quest_progress = "";
	PChar.quest.generate_trade_quest.over = "yes";
	RemoveCharacterGoods(PChar, makeint(PChar.quest.generate_trade_quest_progress.iTradeGoods), makeint(PChar.quest.generate_trade_quest_progress.iQuantityGoods));
	DeleteAttribute(pchar,"quest.generate_trade_quest_progress");
}

void KillPirateQuestDone()
{
	ref PChar = GetMainCharacter();

	// LDH 02Feb09
	int KillQuestExperience = sti(pchar.quest.generate_kill_quest.money)/10;	// was 1500
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(pchar, "Leadership", KillQuestExperience);
		AddPartyExpChar(pchar, "Sneak", KillQuestExperience/100);
	}
	else { AddPartyExp(pchar, KillQuestExperience); }
	PlayStereoSound("INTERFACE\took_item.wav");
	AddMoneyToCharacter(pchar, makeint(pchar.quest.generate_kill_quest.money));
	AddDialogExitQuest("kill_pirate_refused_2");
	ChangeCharacterReputation(pchar, 1);
	pchar.quest.generate_kill_quest = "wait_timer";
}

//extern int CreateStoresOwners(int n);

void SetStoreOwner(string locationID, int n)
{
	if(locationID=="" || n<0) return;
	if(GetTownStoreIndex(GetTownIDFromLocID(locationID))<0) return;

	int storeNum = GetTownStoreIndex(GetTownIDFromLocID(locationID));
	characters[n].store = StoreNum;
	if(storeNum>0) Stores[storeNum].owner = characters[n].id;
}

void GenerateTreasureQuest()
{
	ref PChar = GetMainCharacter();
	string sea_location, treasure_location, destination, attackers_location;
	string numquest, attackers_locator;
	float x,y,z;

	int TreasureQuests = 10;
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) TreasureQuests = 9; // PB: To disable the Guadeloupe one in Early Explorers
	switch(Rand(TreasureQuests))  // GENERATE DESTINATION
	{
		case 0 :
			treasure_location = "Oxbay_Jungle_02";			x = -19.8645; y = 0.133416; z = 19.565;
 			attackers_location = treasure_location; attackers_locator = "citizens04";
			numquest="1"; destination = "Oxbay"; PChar.required_item = "Minersspade";
			PChar.treasureloc = "OShore 1";					// PB: For "X Marks the Spot"
		break;
		case 1 :
			treasure_location = "Dungeon 1";				x = -31.5832; y = -5.11523; z = 14.6615;
			attackers_location = ""; attackers_locator = "";
			numquest="2"; destination = "Oxbay"; PChar.required_item = "-1";
			PChar.treasureloc = "Oxbay";					// PB: For "X Marks the Spot"
		break;
		case 2 :
			treasure_location = "Conceicao_Grot";			x = 11.8876; y = -0.699745; z = 1.46466;
			attackers_location = "Conceicao_shore_02"; attackers_locator = "locator14";
			numquest="3"; destination = "Conceicao"; PChar.required_item = "Minerspick";
			PChar.treasureloc = "CShore 2";					// PB: For "X Marks the Spot"
		break;
		case 3 :
			treasure_location = "Hispaniola_grot3";			x = 11.8876; y = -0.699745; z = 1.46466;
			attackers_location = "Hispaniola_passage"; attackers_locator = "goto7";
			numquest="4"; destination = "Hispaniola"; PChar.required_item = "Minerspick";
			PChar.treasureloc = "HiShore 3";				// PB: For "X Marks the Spot"
		break;
		case 4 :
			treasure_location = "Turks_shore_ship";			x = 33.6905; y = 5.30348; z = 3.8345;
			attackers_location = "Turks_shore_01"; attackers_locator = "goto1";
			numquest="5"; destination = "Turks"; PChar.required_item = "-1";
			PChar.treasureloc = "TurksShore 1";				// PB: For "X Marks the Spot"
		break;
		case 5 :
			treasure_location = "Cuba_Shore_01";			x = 230.049; y = 3.59354; z = 33.4243;
			attackers_location = treasure_location; attackers_locator = "locator5";
			numquest="6"; destination = "Cuba"; PChar.required_item = "Minersspade";
			PChar.treasureloc = "CubShore 1";				// PB: For "X Marks the Spot"
		break;
		case 6 :
			treasure_location = "Turks_Cave_Exit_02";		x = 2.86374; y = -0.562296; z = -10.135;
			attackers_location = treasure_location; attackers_locator = "goto5";
			numquest="7"; destination = "Turks"; PChar.required_item = "Minersspade";
			PChar.treasureloc = "TurksShore 2";				// PB: For "X Marks the Spot"
		break;
		case 7 :
			treasure_location = "Cayman_Grot_01";			x = 11.8876; y = -0.699745; z = 1.46466;
			attackers_location = "Cayman_Jungle_06"; attackers_locator = "goto5";
			numquest="8"; destination = "Cayman"; PChar.required_item = "Minerspick";
			PChar.treasureloc = "CaymanShore 2";			// PB: For "X Marks the Spot"
		break;
		case 8 :
			treasure_location = "Cayman_Grot_02";			x = 40.9334; y = -0.00547115; z = 37.0136;
			attackers_location = "Cayman_Jungle_08"; attackers_locator = "goto9";
			numquest="9"; destination = "Cayman"; PChar.required_item = "Minerspick";
			PChar.treasureloc = "CaymanShore 3";			// PB: For "X Marks the Spot"
		break;
		case 9 :
			treasure_location = "Hispaniola_shore_02";		x = -15.2203; y = 2.33325; z = 39.6414;
			attackers_location = treasure_location; attackers_locator = "citizen06";
			numquest="10"; destination = "Hispaniola"; PChar.required_item = "Minersspade";
			PChar.treasureloc = "HiShore 2";				// PB: For "X Marks the Spot"
		break;
		case 10:
			treasure_location = "Guadeloupe_Lighthouse";	x = 28.972; y = 12.183; z = -51.921;
			attackers_location = treasure_location; attackers_locator = "goto22";
			numquest="11"; destination = "Guadeloupe"; PChar.required_item = "Minersspade";
			PChar.treasureloc = "GuadShore 1";				// PB: For "X Marks the Spot"
		break;
	}
	Group_DelCharacter("Treasure_Pirate", "Treasure Pirate");
	Group_deleteGroup("Treasure_Pirate");
	if(rand(sti(Pchar.skill.sneak))<3) // PB: was >0 - HIGHER luck skill gives a HIGHER chance at enemies?
	{
		GenerateQuestShip("Treasure Pirate", PIRATE); // PB: Use Generic Function
	//	SetCharacterRelationBoth(GetCharacterIndex("Treasure Pirate"),GetMainCharacterIndex(),RELATION_ENEMY); // PB: Is already done by Group_SetTaskAttack
		Group_CreateGroup("Treasure_Pirate");
		Group_AddCharacter("Treasure_Pirate", "Treasure Pirate");
		Group_SetGroupCommander("Treasure_Pirate", "Treasure Pirate");
		Group_SetTaskAttack("Treasure_Pirate", PLAYER_GROUP, true);
		Group_LockTask("Treasure_Pirate");
		Group_SetPursuitGroup("Treasure_Pirate", PLAYER_GROUP);
		Group_SetAddress("Treasure_Pirate", destination, "", "");
		//Logit("TreasureQuest: Treasure_Pirate "+GetCharacterIndex("Treasure Pirate")+" generated");// DEBUG
	}
	if(rand(sti(Pchar.skill.sneak))<3) // PB: was >0 - HIGHER luck skill gives a HIGHER chance at enemies?
	{
		ref pir; string ani;
		int con;
		for(con =  1; con < 11 ; con++)
		{
			pir = &Characters[GetcharacterIndex("Treas_Pirate_" + con)];
			ClearCharacter(pir); // PB: Clear ALL attributes from previous character
			if(rand(Makeint(Pchar.skill.sneak)) == 0) continue;

			pir.nation = PIRATE;
			SetModelfromArray(pir, GetModelIndex(GetRandomModelForTypeExSubCheck(1, "Sailors", "man", sti(pir.nation))) );
			SetRandomNameToCharacter(pir);
			pir.quest.officertype = OFFIC_TYPE_PIRATE; //Levis lets make them actual pirates
			InitCharacterSkills(pir);	// PB: Reset this character
			LAi_NPC_Equip(pir, sti(pir.rank), true, true);
			LAi_SetWarriorType(pir);
			LAi_group_MoveCharacter(pir, "treasure_pirates");
			LAi_SetImmortal(pir, false);
			LAi_NoRebirthEnable(pir); //Levis so they won't be resurrected
			ChangeCharacterAddressGroup(pir, attackers_location, "goto", attackers_locator);

			//Logit("TreasureQuest: Treas_Pirate "+GetcharacterIndex("Treas_Pirate_" + con)+" generated");// DEBUG
		}
		LAi_group_SetRelation(LAI_GROUP_PLAYER, "treasure_pirates", "enemy");
		LAi_group_SetRelation(LAI_DEFAULT_GROUP, "treasure_pirates", "enemy");
		LAi_group_SetRelation(LAI_GROUP_MONSTERS, "treasure_pirates", "enemy");
		LAi_group_FightGroups("treasure_pirates", LAI_GROUP_PLAYER, true);
	}
	sea_location = FindSeaShoreForLocation(treasure_location);
	CloseQuestHeader("treasure");
	Preprocessor_Add("island", TranslateString("", FindIslandName(destination))); // PB
	if(FindSeaShoreForLocation(treasure_location)!="") Preprocessor_Add("seashore", TranslateString("", locations[FindLocation(sea_location)].id.label)); // KK
	Preprocessor_Add("destination", TranslateString("", locations[FindLocation(treasure_location)].id.label)); // KK
	DeleteQuestHeader("treasure");
	AddQuestRecord("treasure",numquest);
	Preprocessor_Remove("destination"); // KK
	Preprocessor_Remove("seashore"); // KK
	Preprocessor_Remove("island"); // KK

	// PB: Treasure Chest locators -->
	//ref lcn = &Locations[FindLocation(treasure_location)];
	//WriteLocatorGlobal(treasure_location, "box", "treasure_box", "", -1, x, y, z, false);
	//Levis: Lets set the required item location specific so more can be stored when needed
	HideTreasureAtLocation(treasure_location, x, y, z, PChar.required_item, "Found Treasure");
	//Levis <--
	if(GetDifficulty() < DIFFICULTY_SEADOG) // Hints only on Landlubber and Mariner
	{
		switch(PChar.required_item)
		{
			case "Minerspick":
				AddQuestRecord("treasure",12);
				break;
			case "Minersspade":
				AddQuestRecord("treasure",13);
				break;
		}
	}
	//Levis moved this to general function:
	FillTreasureChestWithRandomLoot(treasure_location);
	// PB: Treasure Chest locators <--
}

string FindSeaShoreForLocation(string locID)//MAXIMUS: search for nearest shore
{
	if(locID=="") return "";
	if(FindLocation(locID)==-1) return "";
	if(CheckAttribute(&locations[FindLocation(locID)],"type") && locations[FindLocation(locID)].type=="seashore") return locations[FindLocation(locID)].id;

	aref loc; makearef(loc, locations[FindLocation(locID)].reload);
	for(int i=0; i<GetAttributesNum(loc); i++)
	{
		aref attr = GetAttributeN(loc,i);
		string attrName = GetAttributeName(attr);
		if(CheckAttribute(loc,attrName+".go") && loc.(attrName).go!="")
		{
			if(FindLocation(loc.(attrName).go)!=-1)
			{
				if(CheckAttribute(&locations[FindLocation(loc.(attrName).go)],"type"))
				{
					if(locations[FindLocation(loc.(attrName).go)].type=="seashore") return locations[FindLocation(loc.(attrName).go)].id;
					else
					{
						aref loc1; makearef(loc1, locations[FindLocation(loc.(attrName).go)].reload);
						for(int j=0; j<GetAttributesNum(loc1); j++)
						{
							aref attr1 = GetAttributeN(loc1,j);
							string attrName1 = GetAttributeName(attr1);
							if(CheckAttribute(loc1,attrName1+".go") && loc1.(attrName1).go!="")
							{
								if(FindLocation(loc1.(attrName1).go)!=-1)
								{
									if(CheckAttribute(&locations[FindLocation(loc1.(attrName1).go)],"type"))
									{
										if(locations[FindLocation(loc1.(attrName1).go)].type=="seashore") return locations[FindLocation(loc1.(attrName1).go)].id;
										else
										{
											aref loc2; makearef(loc2, locations[FindLocation(loc1.(attrName1).go)].reload);
											for(int k=0; k<GetAttributesNum(loc2); k++)
											{
												aref attr2 = GetAttributeN(loc2,k);
												string attrName2 = GetAttributeName(attr2);
												if(CheckAttribute(loc2,attrName2+".go") && loc2.(attrName2).go!="")
												{
													if(FindLocation(loc2.(attrName2).go)!=-1)
													{
														if(CheckAttribute(&locations[FindLocation(loc2.(attrName2).go)],"type"))
														{
															if(locations[FindLocation(loc2.(attrName2).go)].type=="seashore") return locations[FindLocation(loc2.(attrName2).go)].id;
															else
															{
																aref loc3; makearef(loc3, locations[FindLocation(loc2.(attrName2).go)].reload);
																for(int l=0; l<GetAttributesNum(loc3); l++)
																{
																	aref attr3 = GetAttributeN(loc3,l);
																	string attrName3 = GetAttributeName(attr3);
																	if(CheckAttribute(loc3,attrName3+".go") && loc3.(attrName3).go!="")
																	{
																		if(FindLocation(loc3.(attrName3).go)!=-1)
																		{
																			if(CheckAttribute(&locations[FindLocation(loc3.(attrName3).go)],"type"))
																			{
																				if(locations[FindLocation(loc3.(attrName3).go)].type=="seashore") return locations[FindLocation(loc3.(attrName3).go)].id;
																				else
																				{//MAXIMUS: currently checks up to 4 locations, but can search more :)
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return locations[FindLocation(locID)].id;
}
/*====================================================|END OF QUESTS SECTION|====================================================*/

/*====================================================|START OF DIRECT-SAILS|====================================================*/
ref DirectSailMessenger(string encType)
{
	string ani, model, firstName;
	ref mainChar = GetMainCharacter();
	ref tmpChar;

	model = LAi_GetBoardingModel(mainChar, &ani);
	firstName = XI_ConvertString("Crewmember");

	tmpChar = mainChar;
	tmpChar.old.name = tmpChar.name;
	tmpChar.old.lastname = tmpChar.lastname;
	tmpChar.old.model = tmpChar.model;
	tmpChar.old.Dialog.Filename = tmpChar.Dialog.Filename;
	tmpChar.old.Dialog.Currentnode = tmpChar.Dialog.Currentnode;
	if(!CheckAttribute(tmpChar,"greeting")) { tmpChar.greeting = ""; }
	tmpChar.old.greeting = tmpChar.greeting;
	tmpChar.old.Dialog.Currentnode = tmpChar.Dialog.Currentnode;
	if(CheckAttribute(tmpChar,"disableDlg")) { tmpChar.old.disableDlg = sti(tmpChar.disableDlg); tmpChar.disableDlg = 0; }

	tmpChar.model = model;
	tmpChar.name = firstName;
	tmpChar.lastname = "";
	tmpChar.Dialog.Filename = "Enc_DirectSail_dialog.c";
	tmpChar.Dialog.Currentnode = "First time";
	tmpChar.greeting = encType;
	tmpChar.IsFantom = false;
	tmpChar.SailHo = true;

	for(int i=0; i<GetPassengersQuantity(mainChar); i++)
	{
		int idx = GetPassenger(mainChar,i);
		if(idx>0)
		{
			if(CheckAttribute(characters[idx],"quest.officertype") && !CheckAttribute(characters[idx],"prisoned"))
			{
				if(characters[idx].quest.officertype==OFFIC_TYPE_BOATSWAIN || characters[idx].quest.officertype==OFFIC_TYPE_FIRSTMATE)
				{
					tmpChar.name = XI_ConvertString(characters[idx].quest.officertype);
					tmpChar.model = characters[idx].model;
					Facemaker(tmpChar);
					return tmpChar;
				}
			}
		}
	}
	Facemaker(tmpChar);
	return tmpChar;
}

/*=====================================================|END OF DIRECT-SAILS|=====================================================*/

/*====================================================|START OF ABORDAGE_MOD|====================================================*/
ref CreateTwinCharacter(ref _refEnemy)
{
	ref refMyCharacter = GetMainCharacter();
	ref Fightincabin;

	Fightincabin = _refEnemy;
	Fightincabin.isFantom = 0;
	Fightincabin.fight = 0;
	_refEnemy.isFantom = 0;
	_refEnemy.fight = 0;

	bool IsFantom = CheckAttribute(_refEnemy, "isFantom") == true && sti(_refEnemy.IsFantom) == true; // KK
	if(!IsFantom) IsFantom = strleft(_refEnemy.id,4)=="fenc";//MAXIMUS:
	if(!IsFantom) IsFantom = _refEnemy.id=="0";//MAXIMUS:
	if(!IsFantom) IsFantom = _refEnemy.id == "Quest Pirate";	// LDH 14Jan09

	int freeIdx = FindFreeCabinCaptain(); // KK
	if(freeIdx != -1)
	{
		if(IsFantom)
		{
			Fightincabin = GetCharacter(freeIdx); // KK

			int newIndex = Fightincabin.index;
			string newId = Fightincabin.id
			CopyAttributes(&Fightincabin,_refEnemy);
			Fightincabin.index = newIndex;
			Fightincabin.id	= newId;
			facemaker(Fightincabin);

			if(CheckAttribute(Fightincabin,"ship")) DeleteAttribute(Fightincabin,"ship");
			if(CheckAttribute(Fightincabin,"shiptype")) DeleteAttribute(Fightincabin,"shiptype");
			if(CheckAttribute(Fightincabin,"shipmoney")) DeleteAttribute(Fightincabin,"shipmoney");
			if(CheckAttribute(Fightincabin,"curshipnum")) DeleteAttribute(Fightincabin,"curshipnum");
			if(CheckAttribute(Fightincabin,"seaai")) DeleteAttribute(Fightincabin,"seaai");
			if(CheckAttribute(Fightincabin,"features")) DeleteAttribute(Fightincabin,"features");
			if(CheckAttribute(Fightincabin,"seatime")) DeleteAttribute(Fightincabin,"seatime");
			if(CheckAttribute(Fightincabin,"relation")) DeleteAttribute(Fightincabin,"relation");
			if(CheckAttribute(Fightincabin,"fantomtype")) DeleteAttribute(Fightincabin,"fantomtype");
			if(CheckAttribute(Fightincabin,"canfiretime")) DeleteAttribute(Fightincabin,"canfiretime");
			if(CheckAttribute(Fightincabin,"rankscale")) DeleteAttribute(Fightincabin,"rankscale");
			if(CheckAttribute(Fightincabin,"tmpperks")) DeleteAttribute(Fightincabin,"tmpperks");
			if(CheckAttribute(Fightincabin,"tmpskill")) DeleteAttribute(Fightincabin,"tmpskill");
			if(CheckAttribute(Fightincabin,"points")) DeleteAttribute(Fightincabin,"points");
			if(CheckAttribute(Fightincabin,"randofficers")) DeleteAttribute(Fightincabin,"randofficers");
			if(CheckAttribute(Fightincabin,"skillnatmult")) DeleteAttribute(Fightincabin,"skillnatmult");
			if(CheckAttribute(Fightincabin,"nodisarm")) DeleteAttribute(Fightincabin,"nodisarm");
			if(CheckAttribute(Fightincabin,"points")) DeleteAttribute(Fightincabin,"points");
			if(CheckAttribute(Fightincabin,"isFantom")) DeleteAttribute(Fightincabin,"isFantom");

			Fightincabin.isFantom = 1;
			Fightincabin.fight = 0;
			_refEnemy.isFantom = 1;
			_refEnemy.fight = 0;

			if(CheckAttribute(_refEnemy,"Ship"))
			{
				Fightincabin.Ship = "";
				aref arShipMy, arShipEnemy;
				makearef(arShipMy,Fightincabin.Ship);
				makearef(arShipEnemy,_refEnemy.Ship);
				CopyAttributes(&arShipMy,&arShipEnemy);
			}
		}
	}

	//if(!UsableOfficer(_refEnemy))
	//{
		/*switch(Rand(7))
		{
			case 0: Fightincabin.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
			case 1: Fightincabin.quest.officertype = OFFIC_TYPE_CANNONEER; break;
			case 2: Fightincabin.quest.officertype = OFFIC_TYPE_QMASTER; break;
			case 3: Fightincabin.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
			case 4: Fightincabin.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
			case 5: Fightincabin.quest.officertype = OFFIC_TYPE_CARPENTER; break;
			case 6: Fightincabin.quest.officertype = OFFIC_TYPE_DOCTOR; break;
			case 7: Fightincabin.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
		}*/
//		if(!CheckAttribute(Fightincabin,"quest.officertype")) Fightincabin.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
//		LAi_Create_Officer(rand(8), &Fightincabin);
	//}

	if(CheckAttribute(_refEnemy,"quest.officerprice")) { Fightincabin.quest.officerprice = _refEnemy.quest.officerprice; }
	else { Fightincabin.quest.officerprice = makeint((sti(refMyCharacter.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10); }

	if(!CheckAttribute(_refEnemy,"money")) { Fightincabin.money = makeint(rand(100)); }
	if(CheckAttribute(_refEnemy,"money")) { Fightincabin.wealth = makeint(sti(_refEnemy.money)*(frand(5.0)+2.3)); }

	Fightincabin.nodisarm = 1;
	if(!CheckAttribute(Fightincabin,"chr_ai.type")) { Fightincabin.chr_ai.type = "stay"; }
	if(!CheckAttribute(Fightincabin,"model.entity")) { Fightincabin.model.entity = "NPCharacter"; }
	Fightincabin.Dialog.Filename = "Cabinfight_dialog.c";
	Fightincabin.Dialog.Currentnode = "First time";
	if(Fightincabin.sex=="woman") Fightincabin.greeting = "Gr_Pirate_f";
	else Fightincabin.greeting = "Gr_Clauss"; // was "Gr_Dark Teacher" which is identical
	if (IsFantom) LAi_NPC_Equip(&Fightincabin, sti(Fightincabin.rank), true, 0.5); // KK

	return Fightincabin;
}

// Moved useable officer check to officer.c by Levis

/*=====================================================|END OF ABORDAGE_MOD|=====================================================*/

/*====================================================|START OF LOCATION-MOD|====================================================*/
void InitQCBrothel()
{
	if (FindLocation("QC_Brothel") < 0) return; // KK
	int n = FindLocation("QC_town"); // KK
	if (n < 0) return; // KK
	Locations[n].reload.l7.name = "Reload9";
	Locations[n].reload.l7.go = "QC_brothel";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.label = "#stown_name# Brothel.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("QC_Brothel"); // KK
	Locations[n].id = "QC_brothel";
	locations[n].id.label = "#stown_name# Brothel.";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern_Brothel.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "brothel";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.tavern = "LT";
	Locations[n].models.always.locators = "LT_l";
	Locations[n].models.always.window = "LT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LT_p";

	//Night
	Locations[n].models.night.charactersPatch = "LT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlt_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_brothel_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Brothel Bedroom";
	Locations[n].reload.l2.disable = 1;

	Locations[n].monsters = "0";
	LAi_LocationFightDisable(Locations[n], true);

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29

	// Bedroom
	n = FindLocation("QC_brothel_upstairs");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go  = "QC_brothel";
	Locations[n].reload.l1.emerge = Locations[n].reload.l1.emerge = Locations[FindLocation("QC_brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";
}

// KK -->
void InitTortugaBrothel()
{
	if (FindLocation("Tortuga_Brothel") < 0 || FindLocation("Tortuga_Port") < 0 || FindLocation("Tortuga_Brothel_bedroom") < 0 || FindLocation("Tortuga_Brothel_room") < 0) return;

	int n = FindLocation("Tortuga_Port");
	if (n < 0) return;
	Locations[n].reload.l11.go = "Tortuga_Brothel";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.label = " #stown_name# Brothel.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("Tortuga_Brothel");
	Locations[n].id = "Tortuga_Brothel";
	Locations[n].id.label = "#stown_name# Brothel.";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "brothel";
	locations[n].fastreload = "Tortuga";
	LAi_LocationFantomsGen(&Locations[n], false);

	InitBrothel(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Tortuga_Port";
	Locations[n].reload.l1.emerge = "brothel";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.go = "Tortuga_Brothel_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Brothel Bedroom";

	Locations[n].reload.l3.go = "Tortuga_Brothel_room";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "Opium Den";

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "Hispaniola";

	// Bedroom
	n = FindLocation("Tortuga_Brothel_bedroom");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("Tortuga_Brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";

	// Room
	n = FindLocation("Tortuga_Brothel_room");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("Tortuga_Brothel")].reload.l3.name;
	Locations[n].reload.l1.autoreload = "0";
}

void InitPaPBrothel()
{
	if (FindLocation("PaP_Brothel") < 0 || FindLocation("Guadeloupe_Port") < 0 || FindLocation("PaP_Brothel_bedroom") < 0 || FindLocation("PaP_Brothel_room") < 0) return;

	int n = FindLocation("Guadeloupe_Port");
	Locations[n].reload.l11.go = "PaP_Brothel";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.label = " #stown_name# Brothel.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("PaP_Brothel");
	Locations[n].id = "PaP_Brothel";
	locations[n].id.label = "#stown_name# Brothel.";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "brothel";
	locations[n].fastreload = "Pointe_a_Pitre";
	LAi_LocationFantomsGen(&locations[n], false);

	InitBrothel(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.emerge = "brothel";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.go = "PaP_Brothel_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Brothel Bedroom";

	Locations[n].reload.l3.go = "PaP_Brothel_room";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "Opium Den";

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "Guadeloupe";

	// Bedroom
	n = FindLocation("PaP_Brothel_bedroom");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PaP_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("PaP_Brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";

	// Room
	n = FindLocation("PaP_Brothel_room");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PaP_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("PaP_Brothel")].reload.l3.name;
	Locations[n].reload.l1.autoreload = "0";
}

void InitCharlestownBrothel()
{
	if (FindLocation("Charlestown_Brothel") < 0 || FindLocation("Charlestown_Port") < 0 || FindLocation("Charlestown_Brothel_bedroom") < 0) return;

	int n = FindLocation("Charlestown_Port");
	locations[n].reload.l9.name = "housePirate";
	locations[n].reload.l9.go = "Charlestown_Brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";
//	locations[n].reload.l9.disable = 0;
	Locations[n].reload.l9.close_for_night = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("Charlestown_Brothel");
	Locations[n].id = "Charlestown_Brothel";
	locations[n].id.label = "#stown_name# Brothel.";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	Locations[n].type = "brothel";
	Locations[n].fastreload = "Charlestown";
	LAi_LocationFantomsGen(&Locations[n], true);

	InitBrothel(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "housePirate";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.go = "Charlestown_Brothel_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Brothel Bedroom";

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "QuebradasCostillas";

	// Bedroom
	n = FindLocation("Charlestown_Brothel_bedroom");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go  = "Charlestown_Brothel";
	Locations[n].reload.l1.emerge = Locations[n].reload.l1.emerge = Locations[FindLocation("Charlestown_Brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";
}

void InitEleutheraBrothel()
{
	if (FindLocation("Eleuthera_Brothel") < 0 || FindLocation("Eleuthera_Town") < 0 || FindLocation("Eleuthera_Brothel_room") < 0) return;

	int n = FindLocation("Eleuthera_Town");
	locations[n].reload.l9.name = "houseS2";
	locations[n].reload.l9.go = "Eleuthera_Brothel";
	locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.label = " #stown_name# Brothel.";
	Locations[n].reload.l9.close_for_night = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("Eleuthera_Brothel");
	Locations[n].id = "Eleuthera_Brothel";
	Locations[n].id.label = "#stown_name# Brothel.";
	locations[n].filespath.models = "locations\inside\Brothel";
	locations[n].image = "Inside_Brothel.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";
	Locations[n].lockWeather = "Inside";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "Brothel_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	locations[n].models.always.back = "..\inside_back";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_patch";

	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera_town";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Eleuthera";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Eleuthera_Brothel_bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel room";
	Locations[n].reload.l2.disable = 1;

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "Eleuthera";

	// Room
	n = FindLocation("Eleuthera_Brothel_bedroom");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Eleuthera_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("Eleuthera_Brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";
}

void InitAliceTownBrothel()
{
	if (FindLocation("Alice Town_Brothel") < 0 || FindLocation("Alice Town") < 0 || FindLocation("Alice Town_Brothel_bedroom") < 0 || FindLocation("Alice Town_Brothel_room") < 0) return;

	int n = FindLocation("Alice Town");
	locations[n].reload.l9.name = "houseS1";
	locations[n].reload.l9.go = "Alice Town_Brothel";
	locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l11.label = " #stown_name# Brothel.";
	Locations[n].reload.l9.close_for_night = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1;

	// -----BROTHEL--------------------------------------------
	n = FindLocation("Alice Town_Brothel");
	Locations[n].id = "Alice Town_Brothel";
	Locations[n].id.label = "#stown_name# Brothel.";
	//Town sack
	Locations[n].townsack = "Alice_Town";
	//Sound
	locations[n].type = "brothel";
	locations[n].fastreload = "Alice_Town";
	LAi_LocationFantomsGen(&Locations[n], false);

	InitBrothel(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Alice Town";
	Locations[n].reload.l1.emerge = "houseS1";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.go = "Alice Town_Brothel_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Brothel Bedroom";

	Locations[n].reload.l3.go = "Alice Town_Brothel_room";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "Opium Den";

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	Locations[n].island = "Eleuthera";

	// Bedroom
	n = FindLocation("Alice Town_Brothel_bedroom");
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Alice Town_Brothel";
	Locations[n].reload.l1.emerge = Locations[FindLocation("Alice Town_Brothel")].reload.l2.name;
	Locations[n].reload.l1.label = "Brothel";
}
// <-- KK

#event_handler("CheckQuestPossibility", "CheckGambledQuest");
void CheckGambledQuest()
{
	ref PChar = GetMainCharacter();
//	if(!HasSubStr(PChar.location,"tavern") && !CheckAttribute(PChar,"IsOnDeck"))
	if(!HasSubStr(PChar.location,"upstairs") && !CheckAttribute(PChar,"IsOnDeck"))
	{
		PChar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
		PChar.quest.not_to_the_ship_2.win_condition.l1.location = PChar.location;
		PChar.quest.not_to_the_ship_2.win_condition = "girl_for_sale_2";
	}
	else { PostEvent("CheckQuestPossibility", 100, "1", 0); }
}

//======================================| TOWNS |======================================//

void InitUpgrades(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;
	//Models
	Locations[n].upgrades = "upgrades";

	Locations[n].models.always.shipyard.locator.group = "upgrades";
	Locations[n].models.always.shipyard.locator.name = "shipyard";

	Locations[n].models.always.academy = "..\upgrades\academy1";
	Locations[n].models.always.academy.locator.group = "upgrades";
	Locations[n].models.always.academy.locator.name = "academy";

	Locations[n].models.always.church = "..\upgrades\church1";
	Locations[n].models.always.church.locator.group = "upgrades";
	Locations[n].models.always.church.locator.name = "church";

	Locations[n].models.always.storehouse = "..\upgrades\storehouse1";
	Locations[n].models.always.storehouse.locator.group = "upgrades";
	Locations[n].models.always.storehouse.locator.name = "storehouse";

	Locations[n].models.always.huts = "..\upgrades\huts1";
	Locations[n].models.always.huts.locator.group = "upgrades";
	Locations[n].models.always.huts.locator.name = "huts";

	Locations[n].models.always.fishingpier = "..\upgrades\fishingpier1";
	Locations[n].models.always.fishingpier.locator.group = "upgrades";
	Locations[n].models.always.fishingpier.locator.name = "fishingpier";

	Locations[n].models.always.mill = "..\upgrades\mill1";
	Locations[n].models.always.mill.locator.group = "upgrades";
	Locations[n].models.always.mill.locator.name = "mill";

	Locations[n].models.always.mill_movie = "..\upgrades\mill_movie";
	Locations[n].models.always.mill_movie.locator.group = "upgrades";
	Locations[n].models.always.mill_movie.locator.name = "mill_movie";
	Locations[n].models.always.mill_movie.rotate.x = 0.0;
	Locations[n].models.always.mill_movie.rotate.y = 0.0;
	Locations[n].models.always.mill_movie.rotate.z = 1.0;
/*
//=======================================| SECTION FOR DESTROYED BUILDINGS |=======================================//

	Locations[n].models.always.shipyard = "..\upgrades\shipyard_destroyed";
	Locations[n].models.always.shipyard.locator.group = "upgrades";
	Locations[n].models.always.shipyard.locator.name = "shipyard";

	Locations[n].models.always.academy = "..\upgrades\academy_destroyed";
	Locations[n].models.always.academy.locator.group = "upgrades";
	Locations[n].models.always.academy.locator.name = "academy";

	Locations[n].models.always.church = "..\upgrades\church_destroyed";
	Locations[n].models.always.church.locator.group = "upgrades";
	Locations[n].models.always.church.locator.name = "church";

	Locations[n].models.always.storehouse = "..\upgrades\storehouse_destroyed";
	Locations[n].models.always.storehouse.locator.group = "upgrades";
	Locations[n].models.always.storehouse.locator.name = "storehouse";

	Locations[n].models.always.huts = "..\upgrades\huts_destroyed";
	Locations[n].models.always.huts.locator.group = "upgrades";
	Locations[n].models.always.huts.locator.name = "huts";

	Locations[n].models.always.fishingpier = "..\upgrades\fishingpier_destroyed";
	Locations[n].models.always.fishingpier.locator.group = "upgrades";
	Locations[n].models.always.fishingpier.locator.name = "fishingpier";

	Locations[n].models.always.mill = "..\upgrades\mill_destroyed";
	Locations[n].models.always.mill.locator.group = "upgrades";
	Locations[n].models.always.mill.locator.name = "mill";

	Locations[n].models.always.mill_movie = "";
	Locations[n].models.always.mill_movie.locator.group = "";
	Locations[n].models.always.mill_movie.locator.name = "";

//=======================================| SECTION FOR DESTROYED BUILDINGS |=======================================//
*/
}

void InitArsenal(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Arsenal";
	Locations[n].image = "Inside_Arsenal.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Arsenal";
	Locations[n].models.always.locators = "Arsenal_locators";
	Locations[n].models.always.window = "Arsenal_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Arsenal_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Arsenal_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "barracks";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
}

void InitBank(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Bank";
	Locations[n].image = "Inside_Bank.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Bank";
	Locations[n].models.always.locators = "Bank_locators";
	Locations[n].models.always.window = "Bank_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Bank_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Bank_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "reload8_back";
	Locations[n].reload.l1.autoreload = "0";
}

void InitResidence7(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\residence7";
	Locations[n].image = "Inside_Residence7.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "res07";
	Locations[n].models.always.locators = "res07_locators";
	Locations[n].models.always.window = "res07_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "res07_patch";
	//Night
	Locations[n].models.night.charactersPatch = "res07_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
}

void InitChurch1(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Church_1";
	Locations[n].image = "Inside_Church_1.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "church_1";
	Locations[n].models.always.locators = "church_1_locators";
	Locations[n].models.always.window = "church_1_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "church_1_patch";
	//Night
	Locations[n].models.night.charactersPatch = "church_1_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "reload7_back";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
}

void InitStorehouse(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\StoreHouse";
	Locations[n].image = "Inside_Storehouse.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "storehouse";
	Locations[n].models.always.locators = "storehouse_locators";
	Locations[n].models.always.window = "";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "storehouse_patch";
	//Night
	Locations[n].models.night.charactersPatch = "storehouse_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "storehouse";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
}

void InitStore02(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\store02";
	Locations[n].image = "Inside_Store02.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "store02";
	Locations[n].models.always.locators = "store02_locators";
	Locations[n].models.always.window = "store02_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store02_patch";
	//Night
	Locations[n].models.night.charactersPatch = "store02_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "reload6_back";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
}

void InitStore01(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\store01";
	Locations[n].image = "Inside_Store01.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "store01";
	Locations[n].models.always.locators = "store01_locators";
	Locations[n].models.always.window = "store01_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "store01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "reload6_back";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
}

void InitShipyard4(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Shipyard4";
	Locations[n].image = "inside_shipyard4.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Sh04";
	Locations[n].models.always.locators = "Sh04_locators";
	Locations[n].models.always.window = "Sh04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh04_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Sh04_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";
}

void InitBrothel(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Brothel";
	Locations[n].image = "Inside_Brothel.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Brothel";
	Locations[n].models.always.locators = "Brothel_locators";
	Locations[n].models.always.window = "Brothel_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Brothel_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Brothel_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].monsters = "0";
	LAi_LocationFightDisable(Locations[n], true);
}

void InitBrothelRoom(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\brothel_room";
	Locations[n].image = "Inside_Brothel_Room.tga";
	Locations[n].type = "house";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "brothel_room";
	Locations[n].models.always.locators = "brothel_room_locators";
	Locations[n].models.always.window = "brothel_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "brothel_room_patch";
	//Night
	Locations[n].models.night.charactersPatch = "brothel_room_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationMonstersGen(&Locations[n], false);
}

void InitTavern02(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Tavern02";
	Locations[n].image = "Inside_Tavern02.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "tavern02";
	Locations[n].models.always.locators = "tavern02_locators";
	Locations[n].models.always.window = "tavern02_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "tavern02_patch";
	//Night
	Locations[n].models.night.charactersPatch = "tavern02_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
}

void InitTavern01(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\Tavern01";
	Locations[n].image = "Inside_Tavern01.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Tavern01";
	Locations[n].models.always.locators = "Tavern01_locators";
	Locations[n].models.always.window = "Tavern01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
}

void InitStoneHouse(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\StoneHouse";
	Locations[n].image = "Inside_Stonehouse.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "StoneHouse";
	Locations[n].models.always.locators = "StoneHouse_locators";
	Locations[n].models.always.window = "StoneHouse_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "StoneHouse_patch";
	//Night
	Locations[n].models.night.charactersPatch = "StoneHouse_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";
}

void InitHut(string locationID)
{
	int n = FindLocation(locationID);
	if (n < 0) return;

	Locations[n].filespath.models = "locations\Inside\hut";
	Locations[n].image = "Inside_Hut.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "hut";
	Locations[n].models.always.locators = "hut_locators";
	Locations[n].models.always.window = "hut_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "hut_patch";
	//Night
	Locations[n].models.night.charactersPatch = "hut_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";

	LAi_LocationMonstersGen(&Locations[n], false);
}
//======================================| TOWNS |======================================//

//=========================| ISLA DE MUERTE (based on AOP Isla Mona) |=========================//
void CreateIslaDeMuerte()
{
	if(CheckAttribute(worldMap.islands,"IslaDeMuerte")) return;

	Islands[FindIsland("IslaDeMuerte")].reload_enable = true; // CTM

	//Name
	worldMap.islands.IslaDeMuerte.name = "IslaDeMuerte";
	//Geometry parameters
	worldMap.islands.IslaDeMuerte.position.x = 386.499; //303.0
	worldMap.islands.IslaDeMuerte.position.y = 20.0; //30.0
	worldMap.islands.IslaDeMuerte.position.z = 425.603; //-596.0
	worldMap.islands.IslaDeMuerte.position.rx = 375.139; //306.7
	worldMap.islands.IslaDeMuerte.position.rz = 418.814; //-587.6
	worldMap.islands.IslaDeMuerte.radius = 40.0;
	worldMap.islands.IslaDeMuerte.kradius = 0.75;
	//Island label
	worldMap.islands.IslaDeMuerte.old.label.text = "Isla De Muerte";
	worldMap.islands.IslaDeMuerte.label.text = TranslateString("","Isla De Muerte");
	worldMap.islands.IslaDeMuerte.label.icon = -1;
	worldMap.islands.IslaDeMuerte.label.visible = "true";

	//Cursed Coin to mark Isla de Muerte's location - Armada
	//Geometry parameters
	worldMap.islands.IslaDeMuerte.locations.city0.position.x = 386.499; //303.0
	worldMap.islands.IslaDeMuerte.locations.city0.position.y = 0.6; //0.0
	worldMap.islands.IslaDeMuerte.locations.city0.position.z = 425.603; //-581.0
	worldMap.islands.IslaDeMuerte.locations.city0.position.ay = 0.0;
	worldMap.islands.IslaDeMuerte.locations.city0.modelName = "CursedCoin"; //leaf
	worldMap.islands.IslaDeMuerte.locations.city0.visible = "true";
	worldMap.islands.IslaDeMuerte.locations.city0.move = "false";
}

void DeleteIslaDeMuerte()
{
	if(FindIsland("IslaDeMuerte")!=-1)
	{
		Islands[FindIsland("IslaDeMuerte")].reload_enable = false;
		Islands[FindIsland("IslaDeMuerte")].visible = false;
		aref ourMap; makearef(ourMap,worldMap.islands);
		DeleteAttribute(ourMap,"IslaDeMuerte");
		if(wdmCurrentIsland=="IslaDeMuerte") wdmCurrentIsland = WDM_NONE_ISLAND;
	}
}
//=========================| ISLA DE MUERTE (based on AOP Isla Mona) |=========================//

//=====================| CODE BELOW WILL BE USED FOR AI OF ALL CHARACTERS |=====================//
void CharacterSideStepControl(ref chr, float mag, bool onoff)
{
	if(onoff)
	{
		if(!CheckAttribute(chr, "sidestep"))
		{
			chr.sidestep = mag;
			event("sidestep_event", "l", sti(chr.index));
		}
	}
	else { DeleteAttribute(chr, "sidestep"); }
}

// KK -->
#event_handler("DoSideStep", "CheckSideStep");
void CheckSideStep()
{
	aref chr = GetEventData();
	if(CharacterIsDead(chr) || !IsEntity(chr)) return;

	string leftAnimation, rightAnimation, bAction;

	if(LAi_IsFightMode(chr))
	{
		leftAnimation = "straif_weapon_left";
		rightAnimation = "straif_weapon_right";
	}
	else
	{
		leftAnimation = "straif_left";
		rightAnimation = "straif_right";
	}
	bAction = leftAnimation+","+rightAnimation;
	chr.straif = true;

	string curAction = GetRandSubString(bAction);

	if (HasSubStr(curAction, "left")) {
		SetEventHandler("DoStraif", "CharacterDoStraif", 0);
		Event("DoStraif", "il", chr, -1);
	}
	if (HasSubStr(curAction, "right")) {
		SetEventHandler("DoStraif", "CharacterDoStraif", 0);
		Event("DoStraif", "il", chr, 1);
	}
}

void CharacterDoStraif()
{
	aref chr = GetEventData();
	bool bLeft = GetEventData() > 0;
	string Animation;
	float stepDist = -SIDESTEP_DIST_LEFT;
	bool bStraif = StraifCharacter(chr);

	DelEventHandler("DoStraif", "CharacterDoStraif");
 
	if (bLeft) {
		if(LAi_IsFightMode(chr))
			Animation = "straif_weapon_left";
		else
			Animation = "straif_left";
		stepDist = SIDESTEP_DIST_RIGHT;
	} else {
		if(LAi_IsFightMode(chr))
			Animation = "straif_weapon_right";
		else
			Animation = "straif_right";
	}

	if (IsEntity(chr)) {
		if (bStraif) CharacterPlayAction(chr, Animation); // that stupid func doesn't work when in fightmode!!!
		CharacterSideStepControl(chr, stepDist, true);

		DeleteAttribute(chr, "straif");
		PostEvent("Lai_EndAction", 250, "i", chr);
	}
}
// <-- KK
//========================| CODE WILL BE USED FOR AI OF ALL CHARACTERS |========================//

int DeleteLocation(int n, string locID)
{
	int locNum = n;
	if(GetLocationIndex(locID)<sti(n-1))
	{
		for(int i=GetLocationIndex(locID); i<n; i++)
		{
			DeleteAttribute(&locations[i],"");
			if(sti(i+1)<n) CopyAttributes(&locations[i],&locations[sti(i+1)]);
			locNum = i;
		}
	}
	else
	{
		DeleteAttribute(&locations[GetLocationIndex(locID)],"");
		locNum = locNum - 1;
	}

	return locNum;
}

void CharacterIntoLocationLocator(int idx, string locationID)
{
	string offLocat = "";
	string offGroup = "";
	offLocat = LAi_FindIndexedLocator(locationID, "officers","reload");
	if(offLocat!="") { offGroup = "officers"; }
	else
	{
		offLocat = LAi_FindIndexedLocator(locationID, "reload","reload");
		if(offLocat!="") { offGroup = "reload"; }
		else
		{
			offLocat = LAi_FindIndexedLocator(locationID, "goto","goto");
			if(offLocat!="") { offGroup = "goto"; }
			else
			{
				offLocat = LAi_FindIndexedLocator(locationID, "rld","loc");
				if(offLocat!="") { offGroup = "rld"; }
				else { offLocat = ""; }
			}
		}
	}
	if(offLocat!="")
	{
		if(offLocat!=Characters[GetMainCharacterIndex()].location.locator)
		{
			ChangeCharacterAddressGroup(GetCharacter(idx), locationID, offGroup, offLocat);
		}
	}
	else { trace("No free locators in location "+locationID); }
}

string LAi_FindFirstLocationLocator(string locId, string group)//Function [LAi_FindFirstLocator] already declared in elrapido.c, but seems to be not working
{
	string at = "locators." + group;
	if(CheckAttribute(&locations[FindLocation(locId)], at) == 0) return "";
	aref grp;
	makearef(grp, locations[FindLocation(locId)].(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	return GetAttributeName(GetAttributeN(grp, 1));
}

string LAi_FindIndexedLocator(string locId, string group, string locname)
{
	string at = "locators." + group;
	if(CheckAttribute(&locations[FindLocation(locId)], at) == 0) return "";
	aref grp;
	makearef(grp, locations[FindLocation(locId)].(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	string curLocLocator = "";
	for(int i=0; i<num; i++)
	{
		curLocLocator = GetAttributeName(GetAttributeN(grp, i));
		if(curLocLocator=="") return "";
		if(locname=="") return "";
		if(!CheckAttribute(grp,curLocLocator+".indexed"))
		{
			if(strleft(curLocLocator,3)==locname || strleft(curLocLocator,4)==locname || strleft(curLocLocator,6)==locname || strleft(curLocLocator,7)==locname)
			{
				grp.(curLocLocator).indexed = true;
				return curLocLocator;
			}
		}
	}
	return "";
}

void LAi_ClearIndexedLocators(string locId, string group)
{
	string at = "locators." + group;
	if(CheckAttribute(&locations[FindLocation(locId)], at) == 0) return;
	aref grp;
	makearef(grp, locations[FindLocation(locId)].(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return; // KK
	string curLocLocator = "";
	for(int i=0; i<num; i++)
	{
		curLocLocator = GetAttributeName(GetAttributeN(grp, i));
		if(CheckAttribute(grp,curLocLocator+".indexed"))
		{
			DeleteAttribute(grp,curLocLocator+".indexed");
		}
	}
}

//MAXIMUS: coded by KK, changed by MAXIMUS ;) changes made by MAXIMUS changed by KK :) and changed by MAXIMUS ;b -->
void CheckReloadAction(ref chr, string actionType)
{
	//MAXIMUS: changes made here, will prevent showing of empty-reloads and showing reloads on enemy's ship
	if (FindLoadedLocation() == -1) {
		Log_SetActiveAction("Nothing");
		return;
	}

	if (bMutinyDeckStarted) {
		if (LAi_group_IsActivePlayerAlarm()) {
			Log_SetActiveAction("Nothing");
			return;
		}
// KK -->
		if (!bSeaActive)
			Log_SetActiveAction("ToMap");
		else
			Log_SetActiveAction("ToSea");
// <-- KK
		return;
	}

	if (LAi_IsBoardingProcess()) {
		if (LAi_group_IsActivePlayerAlarm()) {
			Log_SetActiveAction("Nothing");
			return;
		}
		if (CheckAttribute(chr, "boardingReload") && sti(chr.boardingReload) == 1) {
			if (CheckAttribute(chr, "TalkWithSurrenderedCaptain")) {
				Log_SetActiveAction("Nothing");
				return;
			}
			if (Locations[boarding_location].id == "BOARDING_" + GetCharacterShipCabin(boarding_enemy) ||
				HasSubStr(Locations[boarding_location].id, "BOARDING_ShipDeck") == true ||
				CharacterIsDead(refEnCharacter) ||
				IsOfficer(refEnCharacter) ||
				IsPassenger(refEnCharacter) ||
				IsCompanion(refEnCharacter)) {
				if (!isFort && !isTown) {
					Log_SetActiveAction("ToSea");
					return;
				}
			}
			if (isFort) {
				if (nfort == GetFortBoardingLocationsCount()) {
					Log_SetActiveAction("ToTown");
					return;
				}
			}
			if (isTown) {
				string sdistrict = "l" + (cdistrict + 1);
				if (GetTownIndex(boarding_enemy.town) >= 0) {
					if (!CheckAttribute(Towns[GetTownIndex(boarding_enemy.town)], "boarding." + sdistrict)) {
						if (GetTownGovernorIndex(boarding_enemy.town) > 0)
							Log_SetActiveAction("ToResidence");
						else
							Log_SetActiveAction("ToTown");
						return;
					}
				}
			}
			Log_SetActiveAction("ToFightDeck");
			return;
		}
	}

	if (bAbordageStarted && !ownDeckStarted()) {
		Log_SetActiveAction("Nothing");
		return;
	}
	if (CheckAttribute(chr,"autoreload")) { // MAXIMUS
		Log_SetActiveAction("Nothing");
		return;
	}
	if (chrWaitReloadLocator == "") {
		Log_SetActiveAction("Nothing");
		return;
	}

	string reloadType = actionType;
	if (!chrIsNowEnableReload()) reloadType = "Closed";

	if (actionType == "" && reloadType != "Closed") {
		reloadType = "Reload";
		if (CheckAttribute(chr, "reloadStatus")) reloadType = chr.reloadStatus;
	}

	if (reloadType == "Closed" && chrCheckReloadLink(&Locations[FindLocation(chr.location)], chrWaitReloadLocator) == 0) reloadType = "Nothing"; // MAXIMUS
	if (reloadType == "ToSea" || reloadType == "ToBoat") {
		if (GetCharacterShipType(chr) == SHIP_NOTUSED) reloadType = "Nothing";
	}

	Log_SetActiveAction(reloadType);
	if (CheckAttribute(chr, "reload.label")) Log_SetActionLabel(chr.reload.label);
}
//MAXIMUS: coded by KK, changed by MAXIMUS <--

void CheckCharacterAction()
{
	ref mchref = GetMainCharacter();
	if (!IsEntity(mchref)) return; // KK
	if (bInterlocutorActive) return; // KK
	if (FindLocation(mchref.location) < 0) {
		Log_SetActiveAction("Nothing");
		CheckReloadAction(mchref, "");
		return;
	}

// KK -->
	if(CheckAttribute(mchref,"activeItem.Action")) {
		Log_SetActiveAction(mchref.activeItem.Action);
	}
	else
	{
		if (CheckAttribute(mchref, "boxname")) {
			if (mchref.boxname == "WeaponsLocker") {
				Log_SetActiveAction("OpenWeaponsLocker");
			} else {
				if (HasSubStr(mchref.boxname, "gunpowder")) {
					Log_SetActiveAction("OpenBarrel");
				} else {
					if (HasSubStr(mchref.boxname, "box")) {
						if (HasSubStr(mchref.boxname, "corpse_box")) {
							Log_SetActiveAction("Corpse");
						} else {
							Log_SetActiveAction("OpenBox");
						}
					} else {
						DeleteAttribute(mchref, "boxname");
						Log_SetActiveAction("Nothing");
						CheckReloadAction(mchref, "");
						return;
					}
				}
			}
			if (CheckAttribute(mchref, "boxname.boxlabel")) Log_SetActionLabel(TranslateString("", mchref.boxname.boxlabel));
		} else {
			Log_SetActiveAction("Nothing");
			CheckReloadAction(mchref, "");
		}
	}
// <-- KK
}
/*
#event_handler("charUpdateItemLocator","ShowLabel");
void ShowLabel()
{
	aref chr = GetEventData();
	string label = GetEventData();
	if(IsMainCharacter(chr) && CheckAttribute(chr,"activeItem.Action") && label!="" && !dialogRun && !dialogSelf)
	{
		SetUpLogInterface(label,COLOR_GREEN_LIGHT,16,80);
		ClearAllLogStrings();
		chr.activeItem.update = true;
		PostEvent("charUpdateItemLocator",150,"is",chr,label);
		return;
	}
	if(chrWaitReloadLocator=="" && !CheckAttribute(chr,"boxname") && !CheckAttribute(chr,"Interlocutor.update"))
	{
		RestoreLogInterface();
	}
	if(CheckAttribute(chr,"activeItem.update")) DeleteAttribute(chr,"activeItem.update");
}
*/
object LocationDirectory;//finding any needed file -->

string FindFile(string dirName, string fileMask, string fileName)
{
	DeleteAttribute(&LocationDirectory, "");
// KK -->
	if (dirName == "") dirName = ".";
	if (GetSymbol(dirName, strlen(dirName) - 1) != "\") dirName = dirName + "\";
	LocationDirectory.dir = dirName;
// <-- KK
	LocationDirectory.mask = fileMask;
	CreateEntity(&LocationDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocationDirectory);
	aref arList;
	makearef(arList, LocationDirectory.filelist);
	for(int i = 0; i < GetAttributesNum(arList); i++)
	{
		aref arCur = GetAttributeN(arList, i);
		string fname = GetAttributeValue(arCur);
		if(fname == fileName) {
			string fullname = dirName + fname; // KK
			return fullname;
		}
	}
	return "";
}//finding any needed file <--

// KK -->
int CheckDirectory(string dirName, string fileMask)
{
	DeleteAttribute(&LocationDirectory, "");
	if (dirName == "") dirName = ".";
	if (GetSymbol(dirName, strlen(dirName) - 1) != "\") dirName = dirName + "\";
	LocationDirectory.dir = dirName;
	LocationDirectory.mask = fileMask;
	CreateEntity(&LocationDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocationDirectory);
	aref arList;
	makearef(arList, LocationDirectory.filelist);
	return GetAttributesNum(arList);
}

bool MakeDirectory(string dirName)
{
	if (dirName == "") dirName = ".";
	if (GetSymbol(dirName, strlen(dirName) - 1) != "\") dirName = dirName + "\";
	string stmppath = "";
	if (CheckAttribute(&GameInterface, "SavePath")) stmppath = GameInterface.SavePath;
	GameInterface.SavePath = dirName;
	string saveName = "";
	int fSize = 0;
	bool ret = SendMessage(&GameInterface, "llee", MSG_INTERFACE_SAVE_FILE_FIND, 0, &saveName, &fSize) == 0;
	if (stmppath != "") GameInterface.SavePath = stmppath;
	return ret;
}

aref GetFiles(string dirName, string fileMask)
{
	DeleteAttribute(&LocationDirectory, "");
	if (dirName == "") dirName = ".";
	if (GetSymbol(dirName, strlen(dirName) - 1) != "\") dirName = dirName + "\";
	LocationDirectory.dir = dirName;
	LocationDirectory.mask = fileMask;
	CreateEntity(&LocationDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocationDirectory);
	aref arList;
	makearef(arList, LocationDirectory.filelist);
	return arList;
}

bool DeleteFile(string dirName, string fname)
{
	if (dirName == "") dirName = ".";
	if (GetSymbol(dirName, strlen(dirName) - 1) != "\") dirName = dirName + "\";
	if (FindFile(dirName, "*.*", fname) == "") return false;
	string stmppath = "";
	if (CheckAttribute(&GameInterface, "SavePath")) stmppath = GameInterface.SavePath;
	GameInterface.SavePath = dirName;
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_DELETE_SAVE_FILE, fname);
	if (stmppath != "") GameInterface.SavePath = stmppath;
	return true;
}
// <-- KK
// MAXIMUS -->
string strlefttosymbol(string fName, string eSymbol, int bCorrection)
{
	int q = findSubStr(&fName, eSymbol, 0);
	q = sti(q-bCorrection);
	return strleft(fName, q);
}

string strrightfromsymbol(string fName, string sName, int bCorrection)
{
	return strcut(fName,strlen(sName)+bCorrection,strlen(fName)-1);
}

string GetMyFullOldName(ref chr)
{
	string name = "";
	if(!CheckAttribute(chr,"old.name")) chr.old.name = name;
	if(!CheckAttribute(chr,"old.lastname")) chr.old.lastname = name;
	if(CheckAttribute(chr,"name") && chr.old.name=="") chr.old.name = chr.name;
	if(CheckAttribute(chr,"lastname") && chr.old.lastname=="") chr.old.lastname = chr.lastname;
	if(CheckAttribute(chr,"old.title")) { name = chr.old.title + " "; }
	if(CheckAttribute(chr,"old.firstname"))
	{
		if(CheckAttribute(chr,"old.middlename")) name += chr.old.middlename;
		else name += chr.old.firstname;
	}
	else
	{
		name += chr.old.name;
		if(CheckAttribute(chr,"old.middlename"))
		{
			if(name!="") name += " " + chr.old.middlename;
			else name += chr.old.middlename;
		}
	}
	if(chr.old.lastname!="") name += " " + chr.old.lastname;
	return name;
}

string GetMySimpleOldName(ref chr)
{
	string name = "";
	string tmpName = "";
	string tmpLastname = "";
	if (!CheckAttribute(chr,"old.name")) tmpName = name; else tmpName = chr.old.name; 
	if (!CheckAttribute(chr,"old.lastname")) tmpLastname = name; else tmpLastname = chr.old.lastname;
	if (CheckAttribute(chr,"old.firstname")) {
		name = chr.old.firstname;
		if (CheckAttribute(chr,"old.middlename") == true && chr.old.middlename != "") {
			if (name != "") name += " "+chr.old.middlename;
			else name += chr.old.middlename;
		}
	} else {
		if (tmpName != "") name += tmpName;
		if (CheckAttribute(chr, "old.middlename") && chr.old.middlename != "") {
			if (name != "") name += " "+chr.old.middlename;
		}
	}

	if(!HasSubStr(tmpLastname,"<") && !HasSubStr(tmpLastname,">") && tmpLastname!="") {
		if (name != "") name += " "+tmpLastname;
		else name += tmpLastname;
	}

	return name;
}

string StoreString(string strName, string strAdd)
{
	string retstring = strName;

	if(retstring=="") retstring += strAdd;
	else retstring += ","+strAdd;

	return retstring;
}

string RemoveFromString(string instr, string cutstr) // KK
{
	if(instr==cutstr) return "";
	string bret = instr;
	int fndNum = findSubStr(instr,cutstr,0);
	int symbol;
	if(instr!=cutstr) symbol = sti(strlen(cutstr)+1);
	else symbol = 0;
	string part1 = "";
	string part2 = "";
	if(fndNum>0)
	{
		part1 = strcut(instr,0,fndNum-1);
		if(strcut(part1,strlen(part1)-1,strlen(part1)-1)==",") part1 = strcut(instr,0,fndNum-2);
		if(sti(strlen(instr)-strlen(cutstr))!=fndNum) part2 = strcut(instr,fndNum+strlen(cutstr),strlen(instr)-1);
	}
	else
	{
		part2 = strcut(instr,symbol,strlen(instr)-1);
		if(strcut(part2,0,0)==",") part2 = strcut(part2,1,strlen(part2)-1);
	}
	bret = part1 + part2;
	return bret;
}

string GetSpecialString(string strName, int numStr)
{
	string retstr = "";
	int symCount = 0;
	int symStr = 0;
	int num = 0;
	for(int i=0; i<strlen(strName); i++)
	{
		if(GetSymbol(strName,i)!=",") { symStr++; }
		else
		{
			num++;
			retstr = strcut(strName,symCount-symStr,i-1);
			if(num==numStr) return retstr;
			symStr = 0;
		}
		symCount++;
		if(i==sti(strlen(strName)-1))
		{
			if(num<numStr)
			{
				retstr = strcut(strName,symCount-symStr,strlen(strName)-1);
			}
		}
	}
	return retstr;
}

int GetWordsNumWithComma(string strName)
{
	int symStr = 0;
	for(int i=0; i<strlen(strName); i++)
	{
		if(GetSymbol(strName,i)!=",") { symStr++; }
	}
	return sti(symStr+1);
}

string FirstLetter(string strData)
{
// KK -->
	if (strData == "") return "";
	int len = strlen(strData);
//	if (len == 1) return ToUpperEng(strData);
	if (len == 1) return ToUpper(strData);	// GR: use multinational 'ToUpper' instead of English-specific 'ToUpperEng'
// <-- KK
	return ToUpper(strleft(strData,1))+strcut(strData,1,strlen(strData)-1);
}

string FirstLetterUp(string strData)
{
// KK -->
	if (strData == "") return "";
	int len = strlen(strData);
//	if (len == 1) return ToUpperEng(strData);
// <-- KK
//	return ToUpperEng(strleft(strData,1))+strcut(strData,1,strlen(strData)-1);
	if (len == 1) return ToUpper(strData);	// GR: use multinational 'ToUpper' instead of English-specific 'ToUpperEng'
	return ToUpper(strleft(strData,1))+strcut(strData,1,strlen(strData)-1);
}

string FirstLetterDown(string strData)
{
// KK -->
	if (strData == "") return "";
	int len = strlen(strData);
//	if (len == 1) return ToLowerEng(strData);
// <-- KK
//	return ToLowerEng(strleft(strData,1))+strcut(strData,1,strlen(strData)-1);
	if (len == 1) return ToLower(strData);	// GR: use multinational 'ToLower' instead of English-specific 'ToLowerEng'
	return ToLower(strleft(strData,1))+strcut(strData,1,strlen(strData)-1);
}

string GetLingvo(string strData)
{
	if(LanguageGetLanguage()=="Russian")
	{
		if(strcut(strData, strlen(strData)-1, strlen(strData)-1)=="à")
		{
			strData = strcut(strData, 0, strlen(strData)-2)+"ó";
		}
		if(strcut(strData, strlen(strData)-1, strlen(strData)-1)=="À")
		{
			strData = strcut(strData, 0, strlen(strData)-2)+"Ó";
		}
	}

	return strData;
}
// MAXIMUS <--

extern int InitAdditionalLocators();//adding not prescribed locators -->
extern void AddNewLocators();
string systemStatus = "down";

void WriteAdditionalLocators(int locIdx)
{
	string loadFilePath = FindFile("PROGRAM\Locations", "*_locators.c", "locations_locators.c");
	if(loadFilePath=="") return;
	//loadFilePath = strcut(loadFilePath, 8, strlen(loadFilePath) - 1); // KK
	loadFilePath = "Locations\locations_locators.c"; // KK
	if(LoadSegment(loadFilePath))
	{
		ref mchr = GetMainCharacter();
		mchr.locIndex = locIdx;
		if(InitAdditionalLocators()!=-1)
		{
			if(CheckAttribute(mchr,"newGameStart") && sti(mchr.newGameStart)==1)
			{
				AddNewLocators();
				DeleteAttribute(mchr, "newGameStart");
			}
		}
		UnloadSegment(loadFilePath);
		DeleteAttribute(mchr, "locIndex");
	}
}

object wholeWorld;

void WriteLocatorGlobal(string locationID, string locatorGroup, string locatorName, string locatorText, int charIndex, float posX, float posY, float posZ, bool bTempLocator)
{
	if (FindLocation(locationID) < 0) return; // KK

	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).tmpLocator = bTempLocator;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).corpseIdx = charIndex;
	if(sti(charIndex)<0) { wholeWorld.(locationID).locators.(locatorGroup).(locatorName).corpseIdx = -1; }
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).text = locatorText;

	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).x = posX;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).y = posY;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).z = posZ;

	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.x = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.y = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.z = 0.0;

	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.x = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.y = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.z = 0.0;

	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.x = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.y = 0.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.z = 0.0;

	wholeWorld.(locationID).locators_radius.(locatorGroup).(locatorName) = 2.0;
	wholeWorld.(locationID).locators.(locatorGroup).(locatorName).radius = 1.5;

	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).corpseIdx = charIndex;
	if(sti(charIndex)<0) { locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).corpseIdx = -1; }
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).tmpLocator = bTempLocator;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).text = locatorText;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).x = posX;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).y = posY;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).z = posZ;

	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vx.x = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vx.y = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vx.z = 0.0;

	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vy.x = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vy.y = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vy.z = 0.0;

	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vz.x = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vz.y = 0.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).vz.z = 0.0;

	locations[FindLocation(locationID)].locators_radius.(locatorGroup).(locatorName) = 2.0;
	locations[FindLocation(locationID)].locators.(locatorGroup).(locatorName).radius = 1.5;
}

void ReadLocatorCoordinates(string locatorGroup, string locatorName, float posX, float posY, float posZ)
{
	ref lcn = &Locations[FindLocation(characters[GetMainCharacterIndex()].location)];
	posX = 0.0;
	posY = 0.0;
	posZ = 0.0;
	if (CheckAttribute(lcn,"locators." + locatorGroup + "." + locatorName))
	{
		posX = lcn.locators.(locatorGroup).(locatorName).x;
		posY = lcn.locators.(locatorGroup).(locatorName).y;
		posZ = lcn.locators.(locatorGroup).(locatorName).z;
	}
}

void DeleteLocatorGlobal(string locationID, string locatorGroup, string locatorName)
{
	aref rootLocs;

	makearef(rootLocs, locations[FindLocation(characters[GetMainCharacterIndex()].location)].locators);
	if(CheckAttribute(rootLocs, locatorGroup+"."+locatorName)) { DeleteAttribute(rootLocs, locatorGroup+"."+locatorName); }

	makearef(rootLocs, wholeWorld.(locationID).locators);
	if(CheckAttribute(rootLocs, locatorGroup+"."+locatorName)) { DeleteAttribute(rootLocs, locatorGroup+"."+locatorName); }
}

bool CheckAdditionalLocator(string locationID, string locatorGroup, string locatorName)
{
	string curLocName = "";
	string curLocGroup = "";
	ref lcn = &Locations[FindLocation(locationID)];
	aref rootLocators, curGrp, curLoc;
	int i, j;

	makearef(rootLocators,lcn.locators);
	for(i=0; i<GetAttributesNum(rootLocators); i++)
	{
		curGrp = GetAttributeN(rootLocators,i);
		curLocGroup = GetAttributeName(curGrp);
		if(curLocGroup==locatorGroup)
		{
			for(j=0; j<GetAttributesNum(curGrp); j++)
			{
				curLoc = GetAttributeN(curGrp,j);
				curLocName = GetAttributeName(curLoc);
				if(CheckAttribute(lcn, "locators."+curLocGroup+"."+curLocName+".tmpLocator"))
				{
					if(curLocName==locatorName) return true;
				}
			}
		}
	}
	return false;
}

void ClearTempParticles(string locationID, string locatorGroup, string locatorName)
{
	string partId = locationID+".locators."+locatorGroup+"."+locatorName+".pID";
	if(CheckAttribute(wholeWorld, partId))
	{
		aref rootIDs; makearef(rootIDs, wholeWorld.partId);
		for(int i=0; i<GetAttributesNum(rootIDs); i++)
		{
			string idNum = i+1;
			partId = partId+"."+idNum;
			if(CheckAttribute(wholeWorld, partId) && sti(wholeWorld.partId)!=-1)
			{
				string tmpID = locatorGroup+"."+locatorName+".pID"+idNum;
				int prtID = sti(wholeWorld.(partId));
				DeleteParticleSystem(prtID);
				DeleteAttribute(wholeWorld, partId);
			}
		}
	}
}

bool CheckCharPosition(float posX, float posY, float posZ)
{
	float x, y, z;
	bool bX, bY, bZ;
	GetCharacterPos(GetMainCharacter(), &x, &y, &z);

	float curXplus = makefloat(posX+makeint(1)));
	float curYplus = makefloat(posY+makeint(1));
	float curZplus = makefloat(posZ+makeint(1));
	float curXminus = makefloat(posX-makeint(1));
	float curYminus = makefloat(posY-makeint(1));
	float curZminus = makefloat(posZ-makeint(1));

	if(x>=curXminus && x<=curXplus) { bX = true; }
	else { bX = false; }
	if(y>=curYminus && y<=curYplus) { bY = true; }
	else { bY = false; }
	if(z>=curZminus && z<=curZplus) { bZ = true; }
	else { bZ = false; }
	if(bX && bY && bZ) return true;
	return false;
}

void EnterToReloadLocator(ref chr)
{
	string locator = "";
	int result;
	aref locFake;

	if(CheckAttribute(chr,"fakereload.locator"))
	{
		makearef(locFake, locations[FindLoadedLocation()]);
		locator = chr.fakereload.locator;
	}
	if(locator=="") { ExitFromReloadLocator(chr); return; }

	chrWaitReloadIsNoLink = false;
	chrWaitReloadLocator = locator;
	chrWaitLocationRef = locFake;
	makearef(chrWaitReloadRef, locFake.reload);
	result = chrCheckReloadLink(locFake, locator);
	string reloadType = "Reload";

	if(CheckAttribute(chr,"reloadStatus")) {
		reloadType = chr.reloadStatus;
	}
	chr.reloadStatus = reloadType;

	if(result != 1) {
		chrWaitReloadIsNoLink = true;
		if (result == 0) {
			Log_SetActiveAction("Closed");
			return;
		}
	}

	if(chrCheckAutoReload(locFake, locator) == true) {
		if (chrIsNowEnableReload() != true) {
			lockedReloadLocator = "";
			Log_SetActiveAction("Closed");
			return;
		}
		Reload(chrWaitReloadRef, chrWaitReloadLocator, chr.location);
		chrWaitReloadLocator = "";
		chrWaitReloadIsNoLink = false;
	} else {
		lockedReloadLocator = "";
		CheckReloadAction(chr, reloadType);
	}
}

void ExitFromReloadLocator(ref chr)
{
	if(CheckAttribute(chr,"fakereload.locator")) DeleteAttribute(chr,"fakereload.locator");
	DeleteAttribute(chr,"reloadStatus");
	Log_SetActiveAction("Nothing");
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
	lockedReloadLocator = "";
}

string FindFreeRandomLocatorForCharacter(ref chr, ref loc, string group)
{
	string freeLocators = "";
	string usedLocators = "";
	string at = "locators." + group;
	if(!CheckAttribute(loc,at) || loc.at=="") return "";
	aref grp; makearef(grp, loc.(at));
	if(GetAttributesNum(grp)<=0) return "";

	int num = GetAttributesNum(grp);
	for(int n=1; n<TOTAL_CHARACTERS; n++)
	{
		if(n==GetCharacterIndex(chr)) continue;
		ref rCharacter = GetCharacter(n);
		if(CheckAttribute(rCharacter,"location") && rCharacter.location==chr.location)
		{
			if(CheckAttribute(rCharacter,"group") && rCharacter.location.group==group)
			{
				if(CheckAttribute(rCharacter,"location.locator") && rCharacter.location.locator!="") usedLocators = StoreString(usedLocators, rCharacter.location.locator);
			}
		}
	}
	for(int i=0; i<num; i++)
	{
		aref locRef = GetAttributeN(grp, i);
		string locName = GetAttributeName(locRef);
		if(!HasSubStr(usedLocators,locName)) freeLocators = StoreString(freeLocators, locName);
	}
	return GetRandSubString(freeLocators);
}

string LocatorExitSence(string locationID, string locType, string toLocation)
{
	string attrib = locType;
	switch(locType)
	{
		case "from": attrib = "name"; break;
		case "to": attrib = "emerge"; break;
		return "reload1";
	}
	aref cLoctr; makearef(cLoctr,locations[FindLocation(locationID)].reload);
	for(int i=0; i<GetAttributesNum(cLoctr); i++)
	{
		aref curItem1 = GetAttributeN(cLoctr,i);
		string attrName1 = GetAttributeName(curItem1);
		if(CheckAttribute(cLoctr,attrName1+".go") && HasSubStr(cLoctr.(attrName1).go,toLocation))
		{
			bool check = true;
			if(toLocation=="town" && HasSubStr(cLoctr.(attrName1).go,"townhall")) check = false;
			if(CheckAttribute(cLoctr,attrName1+"."+attrib) && check) return cLoctr.(attrName1).(attrib);
		}
	}
	return "reload1";
}//adding not prescribed locators <--

ref MalteseKnight()
{
	//int tmpNameFileID = LanguageOpenFile("characters_names.txt");
	ref mainChar = GetMainCharacter();
	ref tmpChar = LAi_CreateFantomCharacterEx(false, 3, true, false, 0.0, "skelt", "", "");
	tmpChar.HeadModel = "h_skel4";

	if(CheckAttribute(mainChar,"disableDlg")) { mainChar.old.disableDlg = sti(mainChar.disableDlg); mainChar.disableDlg = 0; }

	tmpChar.name = TranslateString("","The late");
	tmpChar.lastname = TranslateString("","monk");
	tmpChar.Dialog.Filename = "Maltese_corpse_dialog.c";
	tmpChar.Dialog.Currentnode = "First time";

	string curBox = mainChar.boxname;
	float x,y,z;
	x = locations[FindLocation(mainChar.location)].locators.box.(curBox).x;
	y = locations[FindLocation(mainChar.location)].locators.box.(curBox).y;
	z = locations[FindLocation(mainChar.location)].locators.box.(curBox).z;
	TeleportCharacterToPos(tmpChar, x,y,z);
	LAi_SetStayType(tmpChar);

	//LanguageCloseFile(tmpNameFileID);
	return tmpChar;
}

void WriteAttributes(ref chr)
{
	if (IsMainCharacter(chr)) return;
	if (CheckAttribute(chr, "tmpKilled")) return;
	if (CheckAttribute(chr, "storedAttributes") == true && sti(chr.storedAttributes) == true) return;

	int bCorpseMode = CORPSEMODE;
	if(CheckAttribute(chr,"CORPSEMODE") && sti(chr.CORPSEMODE)==4) bCorpseMode = 4;

	float x,y,z,ay;
	GetCharacterPos(chr, &x, &y, &z);
	GetCharacterAY(chr, &ay);
	chr.deathx = x
	chr.deathy = y
	chr.deathz = z
	chr.deathay = ay;
	chr.corpse = true;
	if(!CheckAttribute(chr, "old.name")) { chr.old.name = chr.name; }
	if(!CheckAttribute(chr, "old.lastname")) { chr.old.lastname = chr.lastname; }
	if(CheckAttribute(chr, "firstname") && !CheckAttribute(chr, "old.firstname")) { chr.old.firstname = chr.firstname; }
	if(CheckAttribute(chr, "middlename") && !CheckAttribute(chr, "old.middlename")) { chr.old.middlename = chr.middlename; }
	if(CheckAttribute(chr, "title") && !CheckAttribute(chr, "old.title")) { chr.old.title = chr.title; }

	if(bCorpseMode!=4)
	{
//		if(CheckAttribute(chr,"corpse")) DeleteAttribute(chr,"corpse");
		return;
	}

	for(int c = 0; c < 10; c++)
	{
		string curSkillName = GetSkillName(c);
		if(CheckAttribute(chr, "skill."+curSkillName+".mod")) { chr.old.skill.(curSkillName).mod = chr.skill.(curSkillName).mod; }
	}

	if(CheckAttribute(chr, "dialog.filename")) { chr.old.dialog.filename = chr.dialog.filename; }
	if(CheckAttribute(chr, "dialog.currentnode")) { chr.old.dialog.currentnode = chr.dialog.currentnode; }
	if(CheckAttribute(chr, "dialog.tempnode")) { chr.old.dialog.tempnode = chr.dialog.tempnode; }
	if(CheckAttribute(chr, "chr_ai.type")) { chr.old.chr_ai.type = chr.chr_ai.type; }
	if(CheckAttribute(chr, "chr_ai.group")) { chr.old.chr_ai.group = chr.chr_ai.group; }
	if(CheckAttribute(chr, "chr_ai.type.dialog")) { chr.old.chr_ai.type.dialog = chr.chr_ai.type.dialog; }
	if(CheckAttribute(chr, "chr_ai.dmgbldmin")) { chr.old.chr_ai.dmgbldmin = chr.chr_ai.dmgbldmin; }
	if(CheckAttribute(chr, "chr_ai.dmgbldmax")) { chr.old.chr_ai.dmgbldmax = chr.chr_ai.dmgbldmax; }
	if(CheckAttribute(chr, "chr_ai.piercing")) { chr.old.chr_ai.piercing = chr.chr_ai.piercing; }
	if(CheckAttribute(chr, "chr_ai.block")) { chr.old.chr_ai.block = chr.chr_ai.block; }
	if(CheckAttribute(chr, "chr_ai.charge_max")) { chr.old.chr_ai.charge_max = chr.chr_ai.charge_max; }
	if(CheckAttribute(chr, "chr_ai.charge_dlt")) { chr.old.chr_ai.charge_dlt = chr.chr_ai.charge_dlt; }
	if(CheckAttribute(chr, "chr_ai.dmggunmin")) { chr.old.chr_ai.dmggunmin = chr.chr_ai.dmggunmin; }
	if(CheckAttribute(chr, "chr_ai.dmggunmax")) { chr.old.chr_ai.dmggunmax = chr.chr_ai.dmggunmax; }
	if(CheckAttribute(chr, "chr_ai.accuracy")) { chr.old.chr_ai.accuracy = chr.chr_ai.accuracy; }
	if(CheckAttribute(chr, "items"))//MAXIMUS: I'm not sure that it's needed
	{
		aref ifrom; makearef(ifrom, chr.items);
		DeleteAttribute(chr,"old.items");
		chr.old.items = "";
		aref ito; makearef(ito, chr.old.items);
		CopyAttributes(&ito, &ifrom);
	}

	chr.storedAttributes = true;
}

void RestoreCharacter(ref chCorpse)
{
	if(!CheckAttribute(chCorpse,"corpse")) return;
	else DeleteAttribute(chCorpse,"corpse");
	if(CharacterIsDead(chCorpse)) { LAi_CharacterLogoff(chCorpse); return; }

	int tmpNameFileID = LanguageOpenFile("characters_names.txt");
	bool bNoName;

	if(CheckAttribute(chCorpse,"old.name"))
	{
		if(chCorpse.old.name!="")
		{
			if(LanguageConvertString(tmpNameFileID,chCorpse.old.name)!="") { chCorpse.name = LanguageConvertString(tmpNameFileID,chCorpse.old.name); bNoName = false; }
			else { chCorpse.name = chCorpse.old.name; bNoName = false; }
		}
		else { chCorpse.name = chCorpse.old.name; bNoName = false; }
	}
	else { bNoName = true; }

	if(CheckAttribute(chCorpse,"old.lastname"))
	{
		if(chCorpse.old.lastname!="")
		{
			if(LanguageConvertString(tmpNameFileID,chCorpse.old.lastname)!="") { chCorpse.lastname = LanguageConvertString(tmpNameFileID,chCorpse.old.lastname); bNoName = false; }
			else { chCorpse.lastname = chCorpse.old.lastname; }
		}
		else { chCorpse.lastname = chCorpse.old.lastname; bNoName = false; }
	}
	else { bNoName = true; }

	if(CheckAttribute(chCorpse,"old.firstname"))
	{
		if(chCorpse.old.firstname!="")
		{
			if(LanguageConvertString(tmpNameFileID,chCorpse.old.firstname)!="") { chCorpse.firstname = LanguageConvertString(tmpNameFileID,chCorpse.old.firstname); }
			else { chCorpse.firstname = chCorpse.old.firstname; }
		}
		else { chCorpse.firstname = chCorpse.old.firstname; }
	}

	if(CheckAttribute(chCorpse,"old.middlename"))
	{
		if(chCorpse.old.middlename!="")
		{
			//if(LanguageConvertString(tmpNameFileID,chCorpse.old.middlename)!="") { chCorpse.middlename = LanguageConvertString(tmpNameFileID,chCorpse.old.middlename); }
			//else { chCorpse.middlename = chCorpse.old.middlename; }
			chCorpse.middlename = TranslateString("", chCorpse.old.middlename); // KK
		}
		else { chCorpse.middlename = chCorpse.old.middlename; }
	}
	LanguageCloseFile(tmpNameFileID);

	if(CheckAttribute(chCorpse,"old.title"))
	{
		if(chCorpse.old.title!="")
		{
			if(TranslateString("",chCorpse.old.title)!="") { chCorpse.title = TranslateString("",chCorpse.old.title); }
			else { chCorpse.title = chCorpse.old.title; }
		}
		else { chCorpse.title = chCorpse.old.title; }
	}

	if(bNoName) { SetRandomNameToCharacter(chCorpse); }
	if(CheckAttribute(chCorpse,"deathx")) { DeleteAttribute(chCorpse,"deathx"); }
	if(CheckAttribute(chCorpse,"deathy")) { DeleteAttribute(chCorpse,"deathy"); }
	if(CheckAttribute(chCorpse,"deathz")) { DeleteAttribute(chCorpse,"deathz"); }
	if(CheckAttribute(chCorpse,"deathay")) { DeleteAttribute(chCorpse,"deathay"); }
	if(!CheckAttribute(chCorpse,"storedAttributes")) { LAi_CharacterLogoff(chCorpse); return; }
	if(bAllies(chCorpse)) { DeleteAttribute(chCorpse,"storedAttributes"); LAi_CharacterLogoff(chCorpse); return; }
	if(LAi_IsBoardingProcess()) { DeleteAttribute(chCorpse,"storedAttributes"); LAi_CharacterLogoff(chCorpse); return; }

	if(CheckAttribute(chCorpse,"old.dialog.filename")) { chCorpse.dialog.filename = chCorpse.old.dialog.filename; }
	if(CheckAttribute(chCorpse,"old.dialog.currentnode")) { chCorpse.dialog.currentnode = chCorpse.old.dialog.currentnode; }
	if(CheckAttribute(chCorpse,"old.dialog.tempnode")) { chCorpse.dialog.tempnode = chCorpse.old.dialog.tempnode; }
	if(CheckAttribute(chCorpse,"old.chr_ai.type.dialog")) { chCorpse.chr_ai.type.dialog = chCorpse.old.chr_ai.type.dialog; }
	if(CheckAttribute(chCorpse,"old.chr_ai.dmgbldmin")) { chCorpse.chr_ai.dmgbldmin = chCorpse.old.chr_ai.dmgbldmin; }
	if(CheckAttribute(chCorpse,"old.chr_ai.dmgbldmax")) { chCorpse.chr_ai.dmgbldmax = chCorpse.old.chr_ai.dmgbldmax; }
	if(CheckAttribute(chCorpse,"old.chr_ai.piercing")) { chCorpse.chr_ai.piercing = chCorpse.old.chr_ai.piercing; }
	if(CheckAttribute(chCorpse,"old.chr_ai.block")) { chCorpse.chr_ai.block = chCorpse.old.chr_ai.block; }
	if(CheckAttribute(chCorpse,"old.chr_ai.charge_max")) { chCorpse.chr_ai.charge_max = chCorpse.old.chr_ai.charge_max; }
	if(CheckAttribute(chCorpse,"old.chr_ai.charge_dlt")) { chCorpse.chr_ai.charge_dlt = chCorpse.old.chr_ai.charge_dlt; }
	if(CheckAttribute(chCorpse,"old.chr_ai.dmggunmin")) { chCorpse.chr_ai.dmggunmin = chCorpse.old.chr_ai.dmggunmin; }
	if(CheckAttribute(chCorpse,"old.chr_ai.dmggunmax")) { chCorpse.chr_ai.dmggunmax = chCorpse.old.chr_ai.dmggunmax; }
	if(CheckAttribute(chCorpse,"old.chr_ai.accuracy")) { chCorpse.chr_ai.accuracy = chCorpse.old.chr_ai.accuracy; }
	if(CheckAttribute(chCorpse,"old.items"))//MAXIMUS: I'm not sure that it's needed
	{
		aref ifrom; makearef(ifrom, chCorpse.old.items);
		DeleteAttribute(chCorpse,"items");
		chCorpse.items = "";
		aref ito; makearef(ito, chCorpse.items);
		CopyAttributes(&ito, &ifrom);
	}
// KK -->
	if (CheckAttribute(chCorpse, "old.chr_ai.group")) {
		if (chCorpse.old.chr_ai.group != LAI_GROUP_CORPSES) {
			chCorpse.chr_ai.group = chCorpse.old.chr_ai.group;
		} else {
			DeleteAttribute(chCorpse, "old.chr_ai.group");
			LAi_group_MoveCharacter(chCorpse, LAI_DEFAULT_GROUP);
		}
	}
	if (CheckAttribute(chCorpse, "old.chr_ai.type")) { LAi_group_MoveCharacter(chCorpse, chCorpse.old.chr_ai.type); }
	//if (CheckAttribute(chCorpse, "old.chr_ai.hp")) { chCorpse.chr_ai.hp = chCorpse.old.chr_ai.hp; }//Removed by levis cause it isn't used anymore.
	//if (CheckAttribute(chCorpse, "old.chr_ai.hp_max")) { chCorpse.chr_ai.hp_max = chCorpse.old.chr_ai.hp_max; }//Removed by levis cause it isn't used anymore.
	if (CheckAttribute(chCorpse, "passenger")) { DeleteAttribute(chCorpse, "passenger"); } // KK
	if (CheckAttribute(chCorpse, "prisoned")) { DeleteAttribute(chCorpse, "prisoned"); }
	if (CheckAttribute(chCorpse, "actions")) { DeleteAttribute(chCorpse, "actions"); }
	if (CheckAttribute(chCorpse, "killer")) { DeleteAttribute(chCorpse, "killer"); }
	if (CheckAttribute(chCorpse, "status")) { DeleteAttribute(chCorpse, "status"); }
	if (CheckAttribute(chCorpse, "position")) { DeleteAttribute(chCorpse, "position"); }
	if (CheckAttribute(chCorpse, "fight")) { DeleteAttribute(chCorpse, "fight"); }
	if (CheckAttribute(chCorpse, "surrendered")) { DeleteAttribute(chCorpse, "surrendered"); }
// <-- KK
	if (CheckAttribute(chCorpse, "corpse")) { DeleteAttribute(chCorpse, "corpse"); }

	for(int c = 0; c < 10; c++)
	{
		string curSkillName = GetSkillName(c);
		if(CheckAttribute(chCorpse,"old.skill."+curSkillName+".mod")) { chCorpse.skill.(curSkillName).mod = chCorpse.old.skill.(curSkillName).mod; }
		else { if(CheckAttribute(chCorpse,"skill."+curSkillName+".mod")) { DeleteAttribute(chCorpse,"skill."+curSkillName+".mod"); } }
	}

	DeleteAttribute(chCorpse,"storedAttributes");
	LAi_CharacterLogoff(chCorpse);
}

void DropCharaterItem(ref refCharacter, int itmIdx)
{
	float x, y, z;
	GetCharacterPos(refCharacter, &x, &y, &z);
	int locNum = 1;
	ref curLoc = &Locations[FindLocation(refCharacter.location)];
	aref rootLocs;
	string newLocName;
	if(CheckAttribute(curLoc,"locators.items"))
	{
		makearef(rootLocs, curLoc.locators.items);
		locNum = GetAttributesNum(rootLocs)+1;
	}
	newLocName = "item"+locNum;
	WriteLocatorGlobal(refCharacter.location, "items", newLocName, "", itmIdx, x+stf(makeint(Rand(5)+4)/10), y, z+stf(makeint(Rand(5)+4)/10), true);

	Items[itmIdx].startLocator = newLocName;
	Items[itmIdx].shown = "1";
	Items[itmIdx].startLocation = refCharacter.location;

	Item_OnLoadLocation(refCharacter.location);
	ReloadProgressUpdate();

//	AddDroppedItem(refCharacter.location, itmIdx);
}

void AddDroppedItem(string locationID, int itmIdx)
{
	if(!CheckAttribute(Items[itmIdx], "startLocator")) return;
	if(!CheckAttribute(Items[itmIdx], "startLocation")) return;
	if(!CheckAttribute(Items[itmIdx], "shown")) return;

	aref curItem; makearef(curItem, Items[itmIdx]);
	if(curItem.shown == "1")
	{
		if(curItem.startLocation == locationID)
		{
			string itemFolder = "items";
			aref curModel; makearef(curModel, ItemModels[itmIdx]);

			CreateEntity(&curModel, "MODELR");
			ReloadProgressUpdate();
			if(CheckAttribute(curItem, "folder")) { itemFolder = curItem.folder; }
			SendMessage(&curModel, "ls", MSG_MODEL_SET_DIRPATH, itemFolder+"\\");
			SendMessage(&curModel, "ls", MSG_MODEL_LOAD_GEO, itemFolder + "\\" + curItem.model);
			SendMessage(&curModel, "ls", MSG_MODEL_SET_DIRPATH,"");

			if(HasSubStr(curItem.model, "blade") || HasSubStr(curItem.model, "pistol")) SendMessage(&curModel, "ls", MSG_MODEL_SET_TECHNIQUE, "BladeItem");
			else SendMessage(&curModel, "ls", MSG_MODEL_SET_TECHNIQUE, "RandItem");

			LayerAddObject("execute", &curModel, ITEMS_LAYER);
			LayerAddObject("realize", &curModel, ITEMS_LAYER);

			string curLocName = curItem.startLocator;
			SendMessage(SeaLighter, "ssi", "AddModel", curItem.model, &curModel);
			SendMessage(&curModel, "lffffffffffff", MSG_MODEL_SET_POSITION, stf(locations[FindLocation(locationID)].locators.items.(curLocName).x), stf(locations[FindLocation(locationID)].locators.items.(curLocName).y), stf(locations[FindLocation(locationID)].locators.items.(curLocName).z), 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

			Trace("LandInterface: Loaded model "+itemFolder+"\\"+curItem.model);
			ReloadProgressUpdate();
		}
	}
}
/*=====================================================|END OF LOCATION-MOD|=====================================================*/

/*=====================================================|START OF INTERFACES|=====================================================*/
void GetInterfaceParameters()
{
	ReinitInterface();
}

ref deadChr;
void ReinitInterface()
{
// KK -->
	Interfaces[INTERFACE_SELECT_STORYLINE].SectionName = "interface\select_storyline.c";
	Interfaces[INTERFACE_SELECT_STORYLINE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\select_storyline.ini";
// <-- KK
	Interfaces[INTERFACE_STORE].SectionName = "interface\store.c";
	Interfaces[INTERFACE_STORE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\store.ini";
	Interfaces[INTERFACE_SHIP_CHOOSE].SectionName = "interface\ship.c";
	Interfaces[INTERFACE_SHIP_CHOOSE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\ship.ini";
	Interfaces[INTERFACE_SHIPYARD].SectionName = "interface\shipyard.c";
	Interfaces[INTERFACE_SHIPYARD].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\shipyard.ini";
	Interfaces[INTERFACE_CHARACTER].SectionName = "interface\character.c";
	Interfaces[INTERFACE_CHARACTER].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\character.ini";
	Interfaces[INTERFACE_MAINMENU].SectionName = "interface\mainmenu.c";
	Interfaces[INTERFACE_MAINMENU].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\mainmenu.ini";
	Interfaces[INTERFACE_SHIPHOLD].SectionName = "interface\shiphold.c";
	Interfaces[INTERFACE_SHIPHOLD].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\shiphold.ini";
	Interfaces[INTERFACE_HIRECREW].SectionName = "interface\hirecrew.c";
	Interfaces[INTERFACE_HIRECREW].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\hirecrew.ini";
	Interfaces[INTERFACE_PASSENGERS].SectionName = "interface\passengers.c";
	Interfaces[INTERFACE_PASSENGERS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\passengers.ini";
	Interfaces[INTERFACE_CHARACTER_SELECT].SectionName = "interface\selectCharacter.c";
	Interfaces[INTERFACE_CHARACTER_SELECT].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\selectCharacter.ini";
	Interfaces[INTERFACE_QUESTBOOK].SectionName = "interface\questbook.c";
	Interfaces[INTERFACE_QUESTBOOK].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\questbook.ini";
	// Sulan ShipsLog -->
	Interfaces[INTERFACE_SHIPLOG].SectionName = "interface\shipslog.c";
	Interfaces[INTERFACE_SHIPLOG].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\shipslog.ini";
	Interfaces[INTERFACE_NEWS].SectionName = "interface\news.c";
	Interfaces[INTERFACE_NEWS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\news.ini";
	Interfaces[INTERFACE_MONKEY].SectionName = "interface\monkey.c";
	Interfaces[INTERFACE_MONKEY].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\monkey.ini";
	// Sulan ShipsLog <--
	Interfaces[INTERFACE_TRADEBOOK].SectionName = "interface\tradebook.c";
	Interfaces[INTERFACE_TRADEBOOK].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\tradebook.ini";
	Interfaces[INTERFACE_NATIONRELATION].SectionName = "interface\NationRelation.c";
	Interfaces[INTERFACE_NATIONRELATION].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\NationRelation.ini";
	Interfaces[INTERFACE_SAVELOAD].SectionName = "interface\save_load.c";
	Interfaces[INTERFACE_SAVELOAD].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\save_load.ini";
	Interfaces[INTERFACE_ITEMS].SectionName = "interface\items.c";
	Interfaces[INTERFACE_ITEMS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\items.ini";
	Interfaces[INTERFACE_FORTCAPTURE].SectionName = "interface\fortcapture.c";
	Interfaces[INTERFACE_FORTCAPTURE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\fortcapture.ini";
	Interfaces[INTERFACE_ITEMSBOX].SectionName = "interface\itemsbox.c";
	Interfaces[INTERFACE_ITEMSBOX].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\itemsbox.ini";
	Interfaces[INTERFACE_HELPSCREEN].SectionName = "interface\helpscreen.c";
	Interfaces[INTERFACE_HELPSCREEN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\helpscreen.ini";
	Interfaces[INTERFACE_OPTIONSCREEN].SectionName = "interface\option_screen.c";
	Interfaces[INTERFACE_OPTIONSCREEN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\option_screen.ini";
	Interfaces[INTERFACE_SELECTMENU].SectionName = "interface\select_menu.c";
	Interfaces[INTERFACE_SELECTMENU].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\select_menu.ini";
	Interfaces[INTERFACE_ITEMSTRADE].SectionName = "interface\itemstrade.c";
	Interfaces[INTERFACE_ITEMSTRADE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\itemstrade.ini";
	Interfaces[INTERFACE_CONTROLS].SectionName = "interface\controls.c";
	Interfaces[INTERFACE_CONTROLS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\controls.ini";
	Interfaces[INTERFACE_PERKS].SectionName = "interface\perks.c";
	Interfaces[INTERFACE_PERKS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\perks.ini";
	Interfaces[INTERFACE_SALARY].SectionName = "interface\salary.c";
	Interfaces[INTERFACE_SALARY].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\salary.ini";
	Interfaces[INTERFACE_PLAYGAME].SectionName = "interface\playgame.c";
	Interfaces[INTERFACE_PLAYGAME].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\playgame.ini";
	Interfaces[INTERFACE_ENDGAME].SectionName = "interface\endgame.c";
	Interfaces[INTERFACE_ENDGAME].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\endgame.ini";
	Interfaces[INTERFACE_RANSACK_JOIN].SectionName = "interface\ransack_join.c";
	Interfaces[INTERFACE_RANSACK_JOIN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\ransack_join.ini";
	Interfaces[INTERFACE_RANSACK_CREW].SectionName = "interface\ransack_crew.c";
	Interfaces[INTERFACE_RANSACK_CREW].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\ransack_crew.ini";
	Interfaces[INTERFACE_RANSACK_CAPTAIN].SectionName = "interface\ransack_captain.c";
	Interfaces[INTERFACE_RANSACK_CAPTAIN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\ransack_captain.ini";
	Interfaces[INTERFACE_RANSACK_MAIN].SectionName = "interface\ransack_main.c";
	Interfaces[INTERFACE_RANSACK_MAIN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_main.ini";
	Interfaces[INTERFACE_TRANSFER_MAIN].SectionName = "interface\transfer_main.c";
	Interfaces[INTERFACE_TRANSFER_MAIN].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_main.ini";
	Interfaces[INTERFACE_TRANSFER_GOODS].SectionName = "interface\transfer_goods.c";
	Interfaces[INTERFACE_TRANSFER_GOODS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_goods.ini";
	Interfaces[INTERFACE_TRANSFER_CHARACTER].SectionName = "interface\transfer_characters.c";
	Interfaces[INTERFACE_TRANSFER_CHARACTER].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_characters.ini";
	Interfaces[INTERFACE_TRANSFER_CREW].SectionName = "interface\transfer_crew.c";
	Interfaces[INTERFACE_TRANSFER_CREW].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_crew.ini";
// boal -->
	Interfaces[INTERFACE_BOAL_MAP].SectionName = "interface\boal_map.c";
	Interfaces[INTERFACE_BOAL_MAP].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\boal_map.ini";
// boal <--
// GreatZen Interface Mod -->
	Interfaces[INTERFACE_MONEYT].SectionName = "interface\money.c";
	Interfaces[INTERFACE_MONEYT].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\money.ini";
// GreatZen Interface Mod <--
// MAXIMUS interface MOD -->
	Interfaces[INTERFACE_MAP].SectionName = "interface\map.c";
	Interfaces[INTERFACE_MAP].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\map.ini";
	Interfaces[INTERFACE_OFFICER].SectionName = "interface\officer.c";
	Interfaces[INTERFACE_OFFICER].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\officer.ini";
	Interfaces[INTERFACE_TRANSFER_CANNONS].SectionName = "interface\transfer_cannons.c";
	Interfaces[INTERFACE_TRANSFER_CANNONS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\transfer_cannons.ini";
	Interfaces[INTERFACE_CUSTOMIZATION].SectionName = "interface\customization.c";
	Interfaces[INTERFACE_CUSTOMIZATION].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\customization.ini";
	Interfaces[INTERFACE_ABOUT_BUILD].SectionName = "interface\about_build.c";
	Interfaces[INTERFACE_ABOUT_BUILD].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\about_build.ini";
	Interfaces[INTERFACE_GAMBLE].SectionName = "interface\gamble.c";
	Interfaces[INTERFACE_GAMBLE].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\gamble.ini";
	Interfaces[INTERFACE_MUTINY].SectionName = "interface\mutiny_map.c";
	Interfaces[INTERFACE_MUTINY].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\mutiny_map.ini";
	Interfaces[INTERFACE_A_MAP].SectionName = "interface\a_map.c";
	Interfaces[INTERFACE_A_MAP].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\a_map.ini";
	Interfaces[INTERFACE_INFOBOX].SectionName = "interface\info_box.c";
	Interfaces[INTERFACE_INFOBOX].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\info_box.ini";
// MAXIMUS interface MOD <--
//added by KAM -->
	Interfaces[INTERFACE_KAM_SELECTMODEL].SectionName = "interface\kam_selectmodel.c";
	Interfaces[INTERFACE_KAM_SELECTMODEL].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_selectmodel.ini";
	Interfaces[INTERFACE_KAM_SELECTSAILS].SectionName = "interface\kam_selectsails.c";
	Interfaces[INTERFACE_KAM_SELECTSAILS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_selectsails.ini";
	Interfaces[INTERFACE_KAM_RATIONS].SectionName = "interface\kam_rations.c";
	Interfaces[INTERFACE_KAM_RATIONS].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_rations.ini";
	Interfaces[INTERFACE_KAM_ARTICLES].SectionName = "interface\kam_articles.c";
	Interfaces[INTERFACE_KAM_ARTICLES].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_articles.ini";
	Interfaces[INTERFACE_KAM_SHIPTRANSFER].SectionName = "interface\kam_shiptransfer.c";
	Interfaces[INTERFACE_KAM_SHIPTRANSFER].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_shiptransfer.ini";
	Interfaces[INTERFACE_KAM_SHIPBERTHING].SectionName = "interface\kam_shipberthing.c";
	Interfaces[INTERFACE_KAM_SHIPBERTHING].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\kam_shipberthing.ini";
//added by KAM <--
// KK -->
	Interfaces[INTERFACE_CAPTURE_COLONY].SectionName = "interface\capture_colony.c";
	Interfaces[INTERFACE_CAPTURE_COLONY].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\capture_colony.ini";
// <-- KK
//Levis Readable books -->
	Interfaces[INTERFACE_BOOK].SectionName = "interface\Book.c";
	Interfaces[INTERFACE_BOOK].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\book.ini";
//Levis Readable books <--
// PB: Catch Erroneous Install -->
	Interfaces[INTERFACE_INSTALLERROR].SectionName = "interface\installerror.c";
	Interfaces[INTERFACE_INSTALLERROR].IniFile = "RESOURCE\INI\"+GetCurrentInterfacePath()+"\installerror.ini";
// PB: Catch Erroneous Install <--
}

string GetCurrentInterfacePath()
{
	string IntCur = "";
	if(bNewInterface==true) { IntCur = "NEW_INTERFACES"; }
	else { IntCur = "INTERFACES"; }
	return IntCur;
}

void EnableQuickControls()
{
	bKeyboardEnabled = true;
	CI_CreateAndSetControls( "", "NK_KB_Shift_on", CI_GetKeyCode("VK_SHIFT"), 0, false);
	CI_CreateAndSetControls( "", "NK_KB_Shift_off", CI_GetKeyCode("VK_SHIFT"), INVERSE_CONTROL, false);
	CI_CreateAndSetControls( "", "NK_KB_Alt_on", CI_GetKeyCode("VK_ALT"), 0, false);
	CI_CreateAndSetControls( "", "NK_KB_Alt_off", CI_GetKeyCode("VK_ALT"), INVERSE_CONTROL, false);
	CI_CreateAndSetControls( "", "NK_KB_Control_on", CI_GetKeyCode("VK_CONTROL"), 0, false);
	CI_CreateAndSetControls( "", "NK_KB_Control_off", CI_GetKeyCode("VK_CONTROL"), INVERSE_CONTROL, false);
}

bool GetQuickControl(string cName)
{
	string controlName = "";
	if(bKeyboardControl && !bKeyboardAlt && !bKeyboardShift) controlName = "control";
	if(bKeyboardAlt && !bKeyboardShift && !bKeyboardControl) controlName = "alt";
	if(bKeyboardShift && !bKeyboardControl && !bKeyboardAlt) controlName = "shift";

	if(controlName==cName) return true;
	return false;
}
/*======================================================|END OF INTERFACES|======================================================*/

/*======================================================|START OF LANGUAGE|======================================================*/
void GetLanguageParameters()
{
// KK -->
	int ifcelng = GetInterfaceLanguage();
	switch (ifcelng) {
		case ILANG_RUS:
			LanguageSetLanguage("Russian");
			if(LoadSegment("Characters\Russian\Characters_names_ru.c"))
			{
				InitCharactersNamesRu();
				UnloadSegment("Characters\Russian\Characters_names_ru.c");
			}
			return;
		break;
		case ILANG_FRA:
			LanguageSetLanguage("French");
		break;
		case ILANG_GER:
			LanguageSetLanguage("German");
		break;
		case ILANG_SPA:
			LanguageSetLanguage("Spanish");
		break;
		case ILANG_POL:
			LanguageSetLanguage("Polish");
		break;
		case ILANG_SWE:
			LanguageSetLanguage("Swedish");
		break;
		// default:
			LanguageSetLanguage("English");
	}

	if(ifcelng!=ILANG_RUS)
	{
		if(LoadSegment("Characters\Characters_names.c"))
		{
			InitCharactersNames();
			UnloadSegment("Characters\Characters_names.c");
		}
	}
// <-- KK
}

void InitLocalization()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	GetLanguageParameters();
	if (LogsToggle == LOG_VERBOSE) Log_SetStringToLog(TranslateString("","Characters names on") + " " + XI_ConvertString("be_"+LanguageGetLanguage()) + " " + TranslateString("","language..."));
	SetLocalizedLabels();	// PB: This is needed to have town names in the Sail-To Menu
	// KK if (LogsToggle == LOG_VERBOSE) Log_SetStringToLog(TranslateString("","Islands and locations names on") + " " + XI_ConvertString("be_"+LanguageGetLanguage()) + " " + TranslateString("","language..."));
	BI_InitializeCommands();
	if (LogsToggle == LOG_VERBOSE) Log_SetStringToLog(TranslateString("","Battle-interface commands on") + " " + XI_ConvertString("be_"+LanguageGetLanguage()) + " " + TranslateString("","language..."));
	BLI_SetObjectData();
	if (LogsToggle == LOG_VERBOSE) Log_SetStringToLog(TranslateString("","Land-interface commands on") + " " + XI_ConvertString("be_"+LanguageGetLanguage()) + " " + TranslateString("","language..."));

	//LanguageCloseFile(tmpLangFileID);
	//UpdateCharactersNames();
}

// MAXIMUS 20.08.2018 used for localization -->
#event_handler("ChangeLanguage", "SetLanguage");
void SetLanguage()
{
	int lngIdx = GetEventData();
	string isLang = GetEventData();

	if(lngIdx==sti(GetInterfaceLanguage())) return;

	iLangInterface = lngIdx;
	SetKeyboardLayout(lngIdx);
	InitLocalization();
	trace("Localized labels were translated to "+GetInterfaceLanguageName(lngIdx)+"!");
}
// MAXIMUS 20.08.2018 used for localization <--

void ResetKeyboardCharacters(string curLanguage)
{
	if(curLanguage!="Russian") curLanguage = "English";// temporary. If anyone'll want to make changes - welcome ;)
	switch(curLanguage)
	{
		case "Russian":
			CI_CreateAndSetControls("", "NK_Key_a", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_b", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_c", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_d", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_e", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_f", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_g", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_h", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_i", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_j", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_k", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_l", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_m", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_n", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_o", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_p", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_q", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_r", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_s", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_t", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_u", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_v", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_w", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_x", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_y", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_z", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_[", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_]", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_'", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_`", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_,", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_.", "", 0, false);
		break;

		case "English":
			CI_CreateAndSetControls("", "NK_Key_à", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_á", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_â", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ã", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ä", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_å", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_¸", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_æ", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ç", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_è", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_é", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ê", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ë", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ì", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_í", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_î", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ï", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ð", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ñ", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ò", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ó", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ô", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_õ", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ö", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_÷", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ø", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ù", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_û", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ú", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ý", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ü", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_þ", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_ÿ", "", 0, false);
			CI_CreateAndSetControls("", "NK_Key_.", "", 0, false);
		break;
	}
}

//MAXIMUS: text can be added into the special file, or into the one single standard file for all storylines
string GetTranslatedStoryLine(int idx, string strName)
{
	if(strName=="" || idx<=-1) return strName;
	string filePath = GetStorylinePath(idx);
	int tmpNameFileID = -1;
	string tmpName = "";

	if(FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage()+"\"+filePath, "*.txt", "storyline_strings.txt") != "")
	{
		tmpNameFileID = LanguageOpenFile(filePath + "storyline_strings.txt");
		tmpName = LanguageConvertString(tmpNameFileID, strName);
	}

	if(tmpName=="" && FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage()+"\Storyline", "*.txt", "storyline_strings.txt") != "")//also translated text can be in one single file for all storylines
	{
		tmpNameFileID = LanguageOpenFile("Storyline\storyline_strings.txt");
		tmpName = LanguageConvertString(tmpNameFileID, strName);
	}

	if(tmpName=="" && FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "interface_strings.txt") != "")//maybe someone puted translated text in this file by mistake
	{
		tmpNameFileID = LanguageOpenFile("interface_strings.txt");
		tmpName = LanguageConvertString(tmpNameFileID, strName);
	}

	LanguageCloseFile(tmpNameFileID);

	if(tmpName=="") tmpName = TranslateString("", strName);//final search in all known files

	if(tmpName=="") return strName;
	return tmpName;
}

string GetTranslatedPeriod(string strName)
{
	if(strName=="") return strName;
	int tmpNameFileID = -1;
	string tmpName = "";

	if(FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "periods_strings.txt") != "")
	{
		tmpNameFileID = LanguageOpenFile("periods_strings.txt");
		tmpName = LanguageConvertString(tmpNameFileID, strName);
	}

	if(tmpName=="" && FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "interface_strings.txt") != "")//maybe someone puted translated text in this file by mistake
	{
		tmpNameFileID = LanguageOpenFile("interface_strings.txt");
		tmpName = LanguageConvertString(tmpNameFileID, strName);
	}

	LanguageCloseFile(tmpNameFileID);

	if(tmpName=="") tmpName = TranslateString("", strName);//final search in all known files

	if(tmpName=="") return strName;
	return tmpName;
}

string GetTranslatedLog(string strLog)
{
	if(strLog=="") return strLog;
	int tmpLogFileID = -1;
	string tmpLog = "";

	if(FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "shipslog_strings.txt") != "")
	{
		tmpLogFileID = LanguageOpenFile("shipslog_strings.txt");
		tmpLog = LanguageConvertString(tmpLogFileID, strLog);
	}

	if(tmpLog=="" && FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "interface_strings.txt") != "")//maybe someone puted translated text in this file by mistake
	{
		tmpLogFileID = LanguageOpenFile("interface_strings.txt");
		tmpLog = LanguageConvertString(tmpLogFileID, strLog);
	}

	LanguageCloseFile(tmpLogFileID);

	if(tmpLog=="") tmpLog = TranslateString("", strLog);//final search in all known files

	if(tmpLog=="") return strLog;
	return tmpLog;
}

// KK -->
bool FindLocalLanguage(string lang)
{
	string dir = "RESOURCE\INI\TEXTS\" + lang;
	if (FindFile(dir, "*.ini", "common.ini") == "") return false;
//	if (CheckDirectory(dir, "*.txt") < 15) return false;								// PB: LESS than 15? Even ENGLISH has more now!
//	if (FindFile(dir + "\QUESTBOOK", "*.txt", "quests_texts.txt") == "") return false;	// PB: English doesn't have this file either...
	return true;
}
// <-- KK

void UpdateCharactersNames()
{
//	int tmpNameFileID = LanguageOpenFile(GetStorylinePath(FindCurrentStoryline()) + "characters_names.txt");
	for(int j=0; j<TOTAL_CHARACTERS; j++)
	{
		ref ch = GetCharacter(j);
		if(CheckAttribute(ch,"greeting"))
		{
			string curGree = ch.greeting;
			ch.greeting = curGree;
		}
		bool bRandName;
		bool bPass = false;
		string isFstName, isMdlName, isLstName, isNikName;
		isFstName = "";
		isMdlName = "";
		isLstName = "";
		isNikName = "";
/*
		string isFullName = "Without name";
		if(CheckAttribute(ch,"name")) isFullName = ch.name;
		if(CheckAttribute(ch,"middlename")) isFullName += " " + ch.middlename;
		if(CheckAttribute(ch,"lastname")) isFullName += " " + ch.lastname;
		if(CheckAttribute(ch,"index")) isFullName += "[" + ch.index + "]";
		else isFullName += "[ ]";
		trace(isFullName);
*/
		if(CheckAttribute(ch,"chr_ai.type"))
		{
			if(ch.chr_ai.type==LAI_TYPE_BUILDING) bPass = true;
		}
		// PB: This randomizes character names on Start New Game when a previous game was already started -->
		//     Replacing LanguageConvertString with TranslateString does work, but slows down the starting of the game
		// MAXIMUS: fixes were added and now names are permanent
		//     Was modifed TranslateString, which searching needed names in two places first - main character_names.txt and StoryLine characters_names.txt. Looks like starting new game is not slowing down anymore
		bool bOldNamed = true;
		if(CheckAttribute(ch,"name"))
		{
			if(ch.name=="") continue;

			if(!CheckAttribute(ch,"old.name")) bOldNamed = false;
			if(bOldNamed==true && ch.old.name=="") bOldNamed = false;
			if(bOldNamed==false)
			{
				ch.old.name = ch.name;
				isFstName = ch.name;
				bOldNamed = true;
			}
			isFstName = ch.old.name;
			if(TranslateString("", isFstName)=="")
			{
				if(bPass)
				{
					if(LanguageGetLanguage()!="Russian") ch.name = strcut(XI_ConvertString(isFstName),1,strlen(XI_ConvertString(isFstName))-1);
					else ch.name = XI_ConvertString(isFstName);
				}
				else
				{
					ch.name.assigned = true;
					SetRandomNameToCh(ch);
				}
			}
			else
			{
				if(bPass)
				{
					if(LanguageGetLanguage()!="Russian") ch.name = strcut(XI_ConvertString(isFstName),1,strlen(XI_ConvertString(isFstName))-1);
					else ch.name = XI_ConvertString(isFstName);
				}
				else ch.name = TranslateString("", isFstName);
			}
			ch.name = TranslateString("", ch.name);
//			trace(" * NAME - " + ch.name);
			DeleteAttribute(ch,"name.assigned");
		}

		if(CheckAttribute(ch,"middlename"))
		{
			if(ch.middlename=="") continue;

			if(!CheckAttribute(ch,"old.middlename")) bOldNamed = false;
			if(bOldNamed==true && ch.old.middlename=="") bOldNamed = false;
			if(bOldNamed==false)
			{
				ch.old.middlename = ch.middlename;
				isMdlName = ch.middlename;
				bOldNamed = true;
			}
			isMdlName = ch.old.middlename;

			ch.middlename = TranslateString("", isMdlName); // KK
//			trace(" * MIDDLE NAME - " + ch.middlename);
		}

		if(CheckAttribute(ch,"lastname"))
		{
			if(ch.lastname=="") continue;

			if(!CheckAttribute(ch,"old.lastname")) bOldNamed = false;
			if(bOldNamed==true && ch.old.lastname=="") bOldNamed = false;
			if(bOldNamed==false)
			{
				ch.old.lastname = ch.lastname;
				isLstName = ch.lastname;
				bOldNamed = true;
			}
			isLstName = ch.old.lastname;
//			if(CheckAttribute(ch,"old.name"))
//			{
				if(ch.old.name=="Regulating") isLstName = "R" + isLstName;
//			}
			if(TranslateString("", isLstName)=="")
			{
				if(bPass) continue;
				ch.lastname.assigned = true;
				SetRandomNameToCh(ch);
			}
			else
			{
				if(bPass) continue;
				ch.lastname = TranslateString("", isLstName);
			}
			ch.lastname = TranslateString("", ch.lastname);
//			trace(" * LAST NAME - " + ch.lastname);
			DeleteAttribute(ch,"lastname.assigned");
		}

		if(CheckAttribute(ch,"nickname"))
		{
			if(ch.nickname=="") continue;

			if(!CheckAttribute(ch,"old.nickname")) bOldNamed = false;
			if(bOldNamed==true && ch.old.nickname=="") bOldNamed = false;
			if(bOldNamed==false)
			{
				ch.old.nickname = ch.nickname;
				isNikName = ch.nickname;
				bOldNamed = true;
			}
			isNikName = ch.old.nickname;
			ch.nickname = TranslateString("", ch.nickname);
//			trace(" * NIKNAME - " + ch.nickname);
		}
		// PB: This randomizes character names on Start New Game when a previous game was already started <--
		if(CheckAttribute(ch,"nation"))
		{
			if(sti(ch.nation)<NATIONS_QUANTITY)
			{
				for(int cNat=0; cNat<NATIONS_QUANTITY; cNat++)
				{
					string sNation = cNat;
					int curRank = GetRank(ch, cNat);
					if(curRank < sti(Nations[cNat].Ranks.Quantity))
					{
						if(curRank==0) continue;
						if(CheckAttribute(ch,"nations."+sNation+".Rank"))
						{
							ch.nations.(sNation).Rank = curRank;
							//ch.firstname = ch.name;
							//UpdateTitle(&ch);
//							trace(" * NATION - " + XI_ConvertString(GetNationNameByType(cNat)));
//							trace(" * RANKNAME - " + "ch.nations."+sNation+".Rank = "+XI_ConvertString(GetRankName(ch, cNat)));
						}
					}
				}
			}
		}
	}
	trace("Characters names were translated to "+GetInterfaceLanguageName(sti(GetInterfaceLanguage()))+"!");
//	LanguageCloseFile(tmpNameFileID);
}

void SetRandomNameToCh(ref rCharacter)
{
	if(systemStatus=="down") return;
	int curCharNation;
	string rfName = "";
	string rlName = "";
	ref rfNames = &Nullcharacter;
	ref rlNames = &Nullcharacter;

	if(!CheckAttribute(rCharacter,"sex")) return;
	if(!CheckAttribute(rCharacter,"nation")) iNation = PIRATE;// MAXIMUS
	int iNation = sti(rCharacter.nation);
	if(iNation == -1) iNation = PIRATE;
	if(iNation == PIRATE) { string allNations = "0,1,2,4,5"; iNation = sti(GetRandSubString(allNations)); }// MAXIMUS

	string rSex = rCharacter.sex;
	switch(iNation)
	{
		case 0:
			if (rSex == "woman") { rfNames = &sEnWomenNames; } else { rfNames = &sEnManNames; }
			rlNames = &sEnFamilies;
		break;
		case 1:
			if (rSex == "woman") { rfNames = &sFrWomenNames; } else { rfNames = &sFrManNames; }
			rlNames = &sFrFamilies;
		break;
		case 2:
			if (rSex == "woman") { rfNames = &sSpWomenNames; } else { rfNames = &sSpManNames; }
			rlNames = &sSpFamilies;
		break;
		case 4:
			if (rSex == "woman") { rfNames = &sHoWomenNames; } else { rfNames = &sHoManNames; }
			rlNames = &sHoFamilies;
		break;
		case 5:
			if (rSex == "woman") { rfNames = &sPoWomenNames; } else { rfNames = &sPoManNames; }
			rlNames = &sPoFamilies;
		break;
		case 6:
			if (rSex == "woman") { rfNames = &sAmWomenNames; } else { rfNames = &sAmManNames; }
			rlNames = &sAmFamilies;
		break;
	}

	if (GetArraySize(&rfNames) >= 2)
	{
		rCharacter.nation.name = iNation;//MAXIMUS: used in GetCharacterAddressForm
//		if(CheckAttribute(rCharacter,"name.assigned")) trace("GHANGING NAME...");
//		if(CheckAttribute(rCharacter,"lastname.assigned")) trace("GHANGING LASTNAME...");
		rfName = GetRandSubString(rfNames[rand(GetArraySize(&rfNames) - 2)]);
		rlName = GetRandSubString(rlNames[rand(GetArraySize(&rlNames) - 2)]);
	}
	if(CheckAttribute(rCharacter,"name.assigned")) rCharacter.name = rfName;
	if(CheckAttribute(rCharacter,"lastname.assigned")) rCharacter.lastname = rlName;
//MAXIMUS -[addition, offered by KK]->
	if(!CheckAttribute(rCharacter,"old.name") || rCharacter.old.name=="") rCharacter.old.name = rCharacter.name;
	if(!CheckAttribute(rCharacter,"old.lastname") || rCharacter.old.lastname=="") rCharacter.old.lastname = rCharacter.lastname;
//MAXIMUS <-[addition, offered by KK]-
}

void SetLocalizedLabels()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int i, n, j;
	string isIsland = "";
	string isLocLab = "";
	string isCityNm = "";
// KK -->
	aref arIslandReload, arIslandLoc;
	int num;
	string townname;
	ref fortchar = &NullCharacter;
	for(n=0; n<ISLANDS_QUANTITY; n++)
	{
		if(CheckAttribute(Islands[n],"worldmap"))
		{
			isIsland = Islands[n].worldmap;
			worldMap.islands.(isIsland).label.text = TranslateString("", worldMap.islands.(isIsland).label.text); // KK LanguageConvertString(tmpLangFileID,isIsland);
//			trace("ISLAND - "+worldMap.islands.(isIsland).label.text); // MAXIMUS: trace for testing
			arIslandReload; makearef(arIslandReload, WorldMap.islands.(isIsland).locations);
			num = GetAttributesNum(arIslandReload);
			for(i=0; i < num; i++)
			{
				arIslandLoc = GetAttributeN(arIslandReload, i);
				if (CheckAttribute(arIslandLoc, "label.text")) {
					if (!CheckAttribute(arIslandLoc, "label.old.text")) {
						isCityNm = arIslandLoc.label.text;
						arIslandLoc.label.old.text = isCityNm;
					} else {
						isCityNm = arIslandLoc.label.old.text;
					}
					arIslandLoc.label.text = TranslateString("", isCityNm); // KK LanguageConvertString(tmpLangFileID, isCityNm);
//					trace(" * BAY - "+arIslandLoc.label.text); // MAXIMUS: trace for testing
				}
			}

			makearef(arIslandReload, Islands[n].reload);
			num = GetAttributesNum(arIslandReload);
			for (j = 0; j < num; j++) {
				arIslandLoc = GetAttributeN(arIslandReload, j);
				if (CheckAttribute(arIslandLoc, "label")) {
					if (!CheckAttribute(arIslandLoc, "old.label")) {
						isLocLab = arIslandLoc.label;
						arIslandLoc.old.label = isLocLab;
					} else {
						isLocLab = FindIslandName(arIslandLoc.old.label);
					}
					townname = GetTownIDFromLocID(arIslandLoc.go);
					if (townname != "") {
						Preprocessor_Add("town_name", FindTownName(townname));
						arIslandLoc.label = PreprocessText(isLocLab);
						Preprocessor_Remove("town_name");
					} else {
						if (arIslandLoc.go == "Fort") {
							fortchar = characterFromID(arIslandLoc.commander);
							if (CheckAttribute(fortchar, "town")) {
								Preprocessor_Add("town_name", FindTownName(fortchar.town));
								arIslandLoc.label = PreprocessText(arIslandLoc.label);
								Preprocessor_Remove("town_name");
							} else {
								arIslandLoc.label = TranslateString("",isLocLab);
							}
						} else {
							arIslandLoc.label = TranslateString("",isLocLab);
						}
					}
//					trace(" * LOCATION - "+arIslandLoc.label); // MAXIMUS: trace for testing
				}
			}
		}
		else
		{
			if(CheckAttribute(Islands[n],"id"))
			{
				isIsland = Islands[n].id;
				worldMap.islands.(isIsland).label.text = TranslateString("", worldMap.islands.(isIsland).label.text); //LanguageConvertString(tmpLangFileID,isIsland);
//				trace("ISLAND - "+worldMap.islands.(isIsland).label.text); // MAXIMUS: trace for testing
				arIslandReload; makearef(arIslandReload, WorldMap.islands.(isIsland).locations);
				num = GetAttributesNum(arIslandReload);
				for (i = 0; i < num; i++) {
					arIslandLoc = GetAttributeN(arIslandReload, i);
					if (CheckAttribute(arIslandLoc, "label.text")) {
						if (!CheckAttribute(arIslandLoc, "label.old.text")) {
							isCityNm = arIslandLoc.label.text;
							arIslandLoc.label.old.text = isCityNm;
						} else {
							isCityNm = arIslandLoc.label.old.text;
						}
						arIslandLoc.label.text = TranslateString("", isCityNm);
//						trace(" * BAY - "+arIslandLoc.label.text); // MAXIMUS: trace for testing
					}
				}

				makearef(arIslandReload, Islands[n].reload);
				num = GetAttributesNum(arIslandReload);
				for (j = 0; j < num; j++) {
					arIslandLoc = GetAttributeN(arIslandReload, j);
					if (CheckAttribute(arIslandLoc, "label")) {
						if (!CheckAttribute(arIslandLoc, "old.label")) {
							isLocLab = arIslandLoc.label;
							arIslandLoc.old.label = isLocLab;
						} else {
							isLocLab = arIslandLoc.old.label;
						}
						townname = GetTownIDFromLocID(arIslandLoc.go);
						if (townname != "") {
							Preprocessor_Add("town_name", FindTownName(townname));
							arIslandLoc.label = PreprocessText(isLocLab);
							Preprocessor_Remove("town_name");
						} else {
							if (arIslandLoc.go == "Fort") {
								fortchar = characterFromID(arIslandLoc.commander);
								if (CheckAttribute(fortchar, "town")) {
									Preprocessor_Add("town_name", FindTownName(fortchar.town));
									arIslandLoc.label = PreprocessText(arIslandLoc.label);
									Preprocessor_Remove("town_name");
								} else {
									arIslandLoc.label = TranslateString("",isLocLab);
								}
							} else {
								arIslandLoc.label = TranslateString("",isLocLab);
							}
						}
//						trace(" * LOCATION - "+arIslandLoc.label); // MAXIMUS: trace for testing
					}
				}
			}
		}
	}
// <-- KK
	//LanguageCloseFile(tmpLangFileID);
}
/*=======================================================|END OF LANGUAGE|=======================================================*/

// KK: Maximus, could you please find another way of dealing with Remy Gatien? Instead of making two characters with the same id (in fact we
// have THREE Remy Gatiens; 3rd is "Belette" captain) try to make characters with identical name and lastname, but different chr.id, for example,
// VERY PLEASE! The way is coded now makes awfull mess...
/*void CheckSecondCharacter(ref NPChar)//MAXIMUS: we have two characters "Remy Gutien_gov". This section must correct dialog links and NPChar attributes
{
	aref NextDiag; makearef(NextDiag,NPChar.Dialog);
	for(int n=0; n<CHARACTERS_QUANTITY; n++)
	{
		if(CheckAttribute(characters[n],"id") && NPChar.id==characters[n].id)
		{
			if(CheckAttribute(NPChar,"location.stime") && CheckAttribute(characters[n],"location.stime") && NPChar.location.stime!=characters[n].location.stime)
			{
				aref NextDiag2; makearef(NextDiag2, characters[n].Dialog);
				CopyAttributes(&NextDiag2,&NextDiag);

				if(CheckAttribute(NPChar,"locDate")) { characters[n].locDate = sti(NPChar.locDate); }
				if(CheckAttribute(NPChar,"rank")) { characters[n].rank = sti(NPChar.rank); }
				if(CheckAttribute(NPChar,"reputation")) { characters[n].reputation = sti(NPChar.reputation); }
				if(CheckAttribute(NPChar,"money")) { characters[n].money = sti(NPChar.money); }
				if(CheckAttribute(NPChar,"wealth")) { characters[n].wealth = sti(NPChar.wealth); }
				if(CheckAttribute(NPChar,"freepoints")) { characters[n].perks.freepoints = sti(NPChar.freepoints); }

				aref arPerksRoot; makearef(arPerksRoot,ChrPerksList.list);
				int chrPerksQ = GetAttributesNum(arPerksRoot);
				for(int i=0; i<chrPerksQ; i++)
				{
					string perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
					if(CheckAttribute(NPChar,perkName))
					{
						characters[n].perks.list.(perkName) = sti(NPChar.perks.list.(perkName));
					}
				}

				for(int j=0; j<10; j++)
				{
					string skillName = GetSkillName(j);
					if(CheckAttribute(NPChar,"skill."+skillName))
					{
						characters[n].skill.(skillName) = sti(NPChar.skill.(skillName));
					}
					if(CheckAttribute(NPChar,"skill."+skillName + ".modifier"))
					{
						characters[n].skill.(skillName).modifier = sti(NPChar.skill.(skillName).modifier);
					}
					if(CheckAttribute(NPChar,"skill."+skillName + ".effective"))
					{
						characters[n].skill.(skillName).effective = sti(NPChar.skill.(skillName).effective);
					}

					if(CheckAttribute(NPChar,"experience."+skillName))
					{
						characters[n].experience.(skillName) = sti(NPChar.experience.(skillName));
					}
				}
			}
		}
	}
}*/
//Levis: Not used anymore

void CalculateEncInfoData()
{
	ref mainCh = GetMainCharacter();
	mainCh.ShipEnc = "none";
	mainCh.CanEscape = 1;
	EncRecalcReloadToSea();

	float modifier = 1.0;
	if (checkAttribute(mainCh, "Perks.List.ShipSpeedUp")) {
		if (sti(mainCh.Perks.List.ShipSpeedUp) != 0) modifier += 0.2;
	}
	if (checkAttribute(mainCh, "Perks.List.ShipTurnRateUp")) {
		if (sti(mainCh.Perks.List.ShipTurnRateUp) != 0) modifier += 0.15;
	}
	if (checkAttribute(mainCh, "Perks.List.SailingProfessional")) {
		if (sti(mainCh.Perks.List.SailingProfessional) != 0) modifier += 0.65;
	}
	ref MyShipType = GetShipByType(GetCharacterShipType(mainCh));
	aref arship; makearef(arship, mainCh.ship);
	float SpeedMod = stf(GetLocalShipAttrib(arship, MyShipType, "SpeedRate")) / 12 / stf(mainCh.EncSpeed);
	float sailmod = sqrt(GetShipSkill(mainCh, SKILL_SAILING)) * 16 * modifier * SpeedMod;
	if (sti(sqrt(CalcCharacterSkill(mainCh, SKILL_SNEAK))) != 0) {
		if (rand(100) / (sqrt(CalcCharacterSkill(mainCh, SKILL_SNEAK)) * 3.2) > sailmod) mainCh.CanEscape = false;
	}
}

void EncRecalcReloadToSea()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	worldMap.encounter.type = "";
	string totalInfo = "";
	float EncSpeed = 1.0;
	int numEncounters = wdmGetNumberShipEncounters();
	int isShipEncounterType = 0;
	ref rEncounter;
	ref mc = GetMainCharacter();

	for(int i = 0; i < numEncounters; i++)
	{
		if(wdmSetCurrentShipData(i))
		{
			if(MakeInt(worldMap.encounter.select) == 0) continue;
			isShipEncounterType++;
			if (isShipEncounterType>1)
			{
				totalInfo = totalInfo + " " + XI_ConvertString("vs.") + " ";
			}
			rEncounter = &MapEncounters[sti(worldMap.encounter.type)];

			if (!CheckAttribute(rEncounter, "RealEncounterType")) {
				totalInfo = totalInfo + TranslateString("","ships");
			} else {
				switch(sti(rEncounter.RealEncounterType))
	       		{
					case ENCOUNTER_TYPE_MERCHANT0:
				        totalInfo = totalInfo + TranslateString("","merchants");
				        EncSpeed = 0.65;
					break;
					case ENCOUNTER_TYPE_MERCHANT1:
				        totalInfo = totalInfo + TranslateString("","merchants with a light escort");
				        EncSpeed = 0.7;
					break;
					case ENCOUNTER_TYPE_MERCHANT2:
				        totalInfo = totalInfo + TranslateString("","a single merchant with heavy escort");
				        EncSpeed = 0.75;
					break;
					case ENCOUNTER_TYPE_PATROL:
				        totalInfo = totalInfo + TranslateString("","a small patrol");
				        EncSpeed = 0.95;
					break;
					case ENCOUNTER_TYPE_FLEET:
				        totalInfo = totalInfo + TranslateString("","warships");
				        EncSpeed = 0.75;
					break;
					case ENCOUNTER_TYPE_CORSAR:
				        totalInfo = totalInfo + TranslateString("","warships");
				        EncSpeed = 0.95;
					break;
					case ENCOUNTER_TYPE_PIRATE:
				        totalInfo = totalInfo + TranslateString("","small craft");
				        EncSpeed = 0.85;
					break;
					case ENCOUNTER_TYPE_PUNITIVE_SQUADRON:
				        totalInfo = totalInfo + TranslateString("","a rag-tag bunch");
				        EncSpeed = 0.75;
					break;
					case ENCOUNTER_TYPE_LMERCHANT0:
				        totalInfo = totalInfo + TranslateString("","a group of merchants");
				        EncSpeed = 0.6;
					break;
					case ENCOUNTER_TYPE_LMERCHANT1:
				        totalInfo = totalInfo + TranslateString("","an escorted group of merchants");
				        EncSpeed = 0.7;
					break;
					case ENCOUNTER_TYPE_LMERCHANT2:
				        totalInfo = totalInfo + TranslateString("","a convoy");
				        EncSpeed = 0.75;
					break;
					case ENCOUNTER_TYPE_LPATROL:
				        totalInfo = totalInfo + TranslateString("","a large patrol");
				        EncSpeed = 0.9;
					break;
					case ENCOUNTER_TYPE_LFLEET:
				        totalInfo = totalInfo + TranslateString("","a small fleet");
				        EncSpeed = 0.8;
					break;
					case ENCOUNTER_TYPE_LCORSAR:
				        totalInfo = totalInfo + TranslateString("","a battle fleet");
				        EncSpeed = 0.65;
					break;
					case ENCOUNTER_TYPE_LPIRATE:
				        totalInfo = totalInfo + TranslateString("","a rag-tag bunch");
				        EncSpeed = 0.85;
					break;
					case ENCOUNTER_TYPE_LPUNITIVE_SQUADRON:
				        totalInfo = totalInfo + TranslateString("","a scratch patrol");
				        EncSpeed = 0.75;
					break;

					totalInfo = totalInfo + TranslateString("","ships");
	        	}
			}

			if(SAILHO_INFOLEVEL>=2)
			{
				if(sti(rEncounter.Nation) != PIRATE) totalInfo = totalInfo + " " + TranslateString("","flying the colors of") + " " + XI_ConvertString("3"+Nations[sti(rEncounter.Nation)].Name);
				else totalInfo = totalInfo + " " + TranslateString("","flying the Jolly Roger");
			}

			if(SAILHO_INFOLEVEL>=1)
			{
				// DeathDaisy -->
				string PCharTitle = "sir";
				switch(mc.sex){
					case "woman":
						PCharTitle = "ma'am";
					break;
				}
				// DeathDaisy <--
				if(isShipEncounterType>1){ totalInfo = TranslateString("","Sail Ho! There's a battle up ahead " + PCharTitle + ", it looks like") + " " + totalInfo;
				}
				else{ totalInfo = TranslateString("","Sail Ho! It looks like") + " " + totalInfo;
				}
			}
			else
			{
				if(isShipEncounterType>1) totalInfo = TranslateString("","Sail Ho! And gunfire, there's a battle up ahead!");
				else totalInfo = TranslateString("","Sail Ho!");
			}

			if(mc.ShipEnc!="enemy")
			{
				if(GetNationRelation2MainCharacter(sti(rEncounter.Nation)) == RELATION_ENEMY) mc.ShipEnc = "enemy";
				else mc.ShipEnc = "ship";
			}
		}
	}
	else totalinfo += ".";
	mc.EncInfo = totalinfo;
	mc.EncSpeed = EncSpeed;
	mc.EncNation = GetNationRelation2MainCharacter(sti(rEncounter.Nation));

	//LanguageCloseFile(tmpLangFileID);
}

void FillPrison()
{
	ref pchar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(pchar.location)];
	if(FindLoadedLocation()<0) return;
	if(CheckAttribute(pchar,"vcskip")) return;
	if(CheckAttribute(lcn,"vcskip") && TOWN_VCSKIP_DISABLEALL) return;

	//int tmpNameFileID = LanguageOpenFile("characters_names.txt");
	string modelsList = GetPrisonersList();
	string model;
	ref prisoner;
	for(int i=1; i<17; i++)
	{
		if(i==15) continue;

		if (modelsList != "") {
			model = GetRandSubString(modelsList);
			modelsList = RemoveFromString(modelsList, model);
		} else {
			model = LAi_GetBoardingModel(GetMainCharacter(), "");
		}

		//============================================| PRISONERS |============================================//
		if(i<14 && i!=12 && i!=13)
		{
			if(i==9)
			{
				prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, "goto", "goto24");
				LAi_SetPoorType(prisoner);
				DisarmCharacter(prisoner, false, true);
				LAi_group_MoveCharacter(prisoner, GetCurrentCitizenGroup());

				if(modelsList!="")
				{
					model = GetRandSubString(modelsList);
					modelsList = RemoveFromString(modelsList, model);
				}
				else { model = LAi_GetBoardingModel(GetMainCharacter(), ""); }

				prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, "goto", "goto" + i);
				LAi_SetCitizenType(prisoner);
				DisarmCharacter(prisoner, false, true);
				LAi_group_MoveCharacter(prisoner, GetCurrentCitizenGroup());
				prisoner.Dialog.Currentnode = "First time";
			}
			else
			{
				prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, "goto", "goto" + i);
				LAi_SetPoorType(prisoner);
				DisarmCharacter(prisoner, false, true);
				LAi_group_MoveCharacter(prisoner, GetCurrentCitizenGroup());
				prisoner.Dialog.Currentnode = "exit";//MAXIMUS: maybe something else in the future
			}
			prisoner.Dialog.Filename = "Prisoner_dialog.c";
		}
		//=============================================| SOLDIERS |=============================================//
// KK & PB -->
		bool skip_soldiers = false;
		if (Locations[FindLoadedLocation()].id == "Redmond_prison") skip_soldiers = true;
		if (Locations[FindLoadedLocation()].id == "Greenford_prison") skip_soldiers = true;
		if (Locations[FindLoadedLocation()].id == "Havana_prison" && sti(GetStorylineVar(FindCurrentStoryline(), "HAVANA_NO_PRISONERS")) > 0) skip_soldiers = true;
		if (skip_soldiers) {
			if (i == 1 || i == 14 || i == 16) continue;
		}
// KK & PB <--
		if(i==1)
		{
			prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, SelectSoldierModelByNation(GetCurrentLocationNation(), "officer"), "sit", "sit" + i);
			LAi_SetHuberType(prisoner);
			prisoner.name = TranslateString("","Officer");
			prisoner.lastname = "";
			prisoner.Dialog.Filename = "Soldier_dialog.c"; // PB: Other file would be nice
			prisoner.Dialog.Currentnode = "First time";
			LAi_group_MoveCharacter(prisoner, GetCurrentSoldierGroup());
		}
		if(i>=12 && i<=13)
		{
			prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, SelectSoldierModelByNation(GetCurrentLocationNation(), "soldier"), "goto", "goto" + sti(17 + Rand(6)));
			LAi_SetCivilianPatrolType(prisoner);
			prisoner.name = TranslateString("","Soldier");
			prisoner.lastname = "";
			prisoner.Dialog.Filename = "Soldier_dialog.c";
			prisoner.Dialog.Currentnode = "First time";
			LAi_group_MoveCharacter(prisoner, GetCurrentSoldierGroup());
		}
		if(i>=14)
		{
			prisoner = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, SelectSoldierModelByNation(GetCurrentLocationNation(), "soldier"), "goto", "goto" + i);
			LAi_SetCivilianGuardianType(prisoner);
			prisoner.name = TranslateString("","Soldier");
			prisoner.lastname = "";
			prisoner.Dialog.Filename = "Soldier_dialog.c";
			prisoner.Dialog.Currentnode = "First time";
			LAi_group_MoveCharacter(prisoner, GetCurrentSoldierGroup());
		}
	}

	//LanguageCloseFile(tmpNameFileID);
}

string GetPrisonersList()
{
	string modelsList = "";
	modelsList = GetPrisonersModels();
	return modelsList;
}

string GetLadiesList()
{
	string modelsList = "";
	modelsList = GetMansionModels();
	return modelsList;
}

string GetWhoresList()
{
	string modelsList = "";
	modelsList = GetBrothelModels();
	return modelsList;
}

void DisarmCharacter(ref tmpChr, bool bTake, bool bTakeAll)
{
	string blade, gun, cuirass, flask, pouch;
	if(IsCharacterEquipByGroup(tmpChr,BLADE_ITEM_TYPE))
	{
		blade = GetCharacterEquipByGroup(tmpChr,BLADE_ITEM_TYPE);
		RemoveCharacterEquip(tmpChr, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(tmpChr, blade);
		if(bTake) GiveItem2Character(GetMainCharacter(), blade); // PB: was 'gun'???
	}
	if(IsCharacterEquipByGroup(tmpChr,GUN_ITEM_TYPE))
	{
		gun = GetCharacterEquipByGroup(tmpChr,GUN_ITEM_TYPE);
		RemoveCharacterEquip(tmpChr, GUN_ITEM_TYPE);
		TakeItemFromCharacter(tmpChr, gun);
		if(bTake) GiveItem2Character(GetMainCharacter(), gun);
	}
	if(IsCharacterEquipByGroup(tmpChr,ARMOR_ITEM_TYPE))
	{
		cuirass = GetCharacterEquipByGroup(tmpChr,ARMOR_ITEM_TYPE);
		RemoveCharacterEquip(tmpChr, ARMOR_ITEM_TYPE);
		TakeItemFromCharacter(tmpChr, cuirass);
		if(bTake) GiveItem2Character(GetMainCharacter(), cuirass); // PB: was 'gun'???
	}
	if(IsCharacterEquipByGroup(tmpChr,FLASK_ITEM_TYPE))
	{
		flask = GetCharacterEquipByGroup(tmpChr,FLASK_ITEM_TYPE);
		RemoveCharacterEquip(tmpChr, FLASK_ITEM_TYPE);
		TakeItemFromCharacter(tmpChr, flask);
		if(bTake) GiveItem2Character(GetMainCharacter(), flask);
	}
	if(IsCharacterEquipByGroup(tmpChr,POUCH_ITEM_TYPE))
	{
		pouch = GetCharacterEquipByGroup(tmpChr,POUCH_ITEM_TYPE);
		RemoveCharacterEquip(tmpChr, POUCH_ITEM_TYPE);
		TakeItemFromCharacter(tmpChr, pouch);
		if(bTake) GiveItem2Character(GetMainCharacter(), pouch);
	}
	if(bTakeAll)
	{
		aref chItems; makearef(chItems, tmpChr.items);
		DeleteAttribute(chItems,"");
	}
}
