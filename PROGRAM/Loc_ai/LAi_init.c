
#include "Loc_ai\LAi_defines.c"
#include "Loc_ai\LAi_events.c"
#include "Loc_ai\LAi_utils.c"
#include "Loc_ai\LAi_login.c"
#include "Loc_ai\LAi_character.c"
#include "Loc_ai\LAi_templates.c"
#include "Loc_ai\LAi_types.c"
#include "Loc_ai\LAi_groups.c"
#include "Loc_ai\LAi_fightparams.c"
#include "Loc_ai\LAi_boarding.c"
#include "Loc_ai\LAi_monsters.c"
#include "Loc_ai\LAi_location.c"
#include "Loc_ai\LAi_equip.c"
#include "Loc_ai\LAi_sounds.c"
#include "Loc_ai\LAi_CreateOfficer.c"
// boal Cabin 09.09.03 --> // MAXIMUS Deck --> // KK -->
#include "Loc_ai\LAi_deck.c"
#include "Loc_ai\LAi_mutiny.c"
// <-- KK // MAXIMUS Deck <-- // boal Cabin 09.09.03 <--

bool LAi_IsInitedAI = false;
bool LAi_IsCapturedLocation = false;
bool LAi_restoreStates = false;
bool LAi_IsBoarding = false;

//Инициализация интелекта
void LocAi_Init(ref loc)
{
	int i, con, maxcrew, idx, num, offic;
	ref crew;
	aref st;
	string locator, sat;
	int locIndex = 1;
	//int res = 0;
	ref mainChr = GetMainCharacter();

	LAi_numloginedcharacters = 0;
	if (!LAi_group_Init()) trace("Error: Characters group logic not inited!!!");
	SetEventHandler("CharacterUpdate", "LAi_CharacterUpdate", 1);
	SetEventHandler("CharactersStateUpdate", "LAi_Character_FrameUpdate", 1);
	SetEventHandler("Location_CharacterEndTask", "LAi_CharacterEndTask", 0);
	SetEventHandler("Location_CharacterTaskFailure", "LAi_CharacterTaskFailure", 0);
	SetEventHandler("Location_CharacterBusyPos", "LAi_CharacterBusyPos", 0);
	SetEventHandler("Location_CharacterFollowGo", "LAi_CharacterFollowGo", 0);
	SetEventHandler("Location_CharacterFollowStay", "LAi_CharacterFollowStay", 0);
	SetEventHandler("Location_CharacterFightGo", "LAi_CharacterFightGo", 0);
	SetEventHandler("Location_CharacterFightStay", "LAi_CharacterFightStay", 0);
	SetEventHandler("Location_CharacterAttack", "LAi_CharacterAttack", 0);
	SetEventHandler("Location_CharacterBlock", "LAi_CharacterBlock", 0);
	SetEventHandler("Location_CharacterFire", "LAi_CharacterFire", 0);
	SetEventHandler("Location_CharacterIsFire", "LAi_CharacterIsFire", 0);
	SetEventHandler("Location_CharacterIsFight", "LAi_CharacterIsFight", 0);
	SetEventHandler("Location_CharacterEscapeSlide", "LAi_CharacterEscapeSlide", 0);
	SetEventHandler("Location_CharacterColThreshold", "LAi_CharacterColThreshold", 0);
	SetEventHandler("Location_Character_EndAction", "LAi_Character_EndAction", 0);
	LAi_IsInitedAI = true;
	LAi_IsCapturedLocation = IsLocationCaptured(loc.id);
	if(!actLoadFlag)
	{
		//Очистим фантомных персонажей
		LAi_Clear_Fantoms();
	}
	//Выставим адреса офицерам главного персонажа
	LAi_IsBoarding = false;
	if (CheckAttribute(loc, "boarding") == true && loc.boarding == "true") LAi_IsBoarding = true;
	if (!LAi_IsBoarding)
	{
		if(LAi_restoreStates)
		{
			LAi_SetCurHPMax(mainChr);
			LAi_UseAtidoteBottle(mainChr);
		}

		// SCREWFACE : crewmembers on shore mod
		bool LandCrew = LANDCREWMEMBERS;
		if (LandCrew)
		{
			if (loc.type == "Shop")							LandCrew = false;
			if (loc.type == "residence")					LandCrew = false;
			if (loc.type == "house")						LandCrew = false;
			if (GetAttribute(loc    , "vcskip") == true)	LandCrew = false; // PB
			if (GetAttribute(mainChr, "vcskip") == true)	LandCrew = false; // PB
			if (LandCrew)
			{
				crew = characterFromID("Treas_Crewmember_1");
				maxcrew = GetMaxLandCrew(mainChr.Ship.Crew.Quantity);
				if (maxCrew > 0)
				{
					for(con =  1; con <= 10 ; con++)
					{
						crew = characterFromID("Treas_Crewmember_" + con);
						if(Lai_IsDead(crew))
						{
							RemoveCharacterCrew(mainChr,1);
							if(MAX_CREWMEMBERS  > 0){MAX_CREWMEMBERS = MAX_CREWMEMBERS-1;}
							if(MAX_CREWMEMBERS == 0) LANDCREWMEMBERS = false; // PB: If all your crew died, disable this mod
						}
						LAi_group_MoveCharacter(crew, LAI_GROUP_PLAYER);
						LAi_SetCitizenTypeNoGroup(crew);
						LAi_SetImmortal(crew, false);
						if((con<=maxcrew) && (con<=MAX_CREWMEMBERS) && !Lai_IsDead(crew))
						{
							crew.location = mainChr.location;
							if(CheckAttribute(loc, "locators.officers." + mainChr.location.locator + "_1"))
							{
								crew.location.group = "officers";
								crew.location.locator = mainChr.location.locator + "_" + locIndex;
							}
							else
							{
								//float x, y, z;
								//GetCharacterPos(&mainChr, &x, &y, &z);
								//string nearloc = LAi_FindNearestFreeLocator("reload", x, y, z);
								crew.location.group = mainChr.location.group;
								crew.location.locator = mainChr.location.locator; //nearloc;
							}
						}
						else
						{
							crew.location = "";
							crew.location.group = "";
							crew.location.locator = "";
						}
						crew.rank = mainChr.rank;
						crew.experience = mainChr.experience;
						crew.old.name = "Crewmember";
						crew.name = XI_ConvertString("Crewmember");
						crew.middlename = "";
						crew.lastname = "";
						crew.skill.Fencing = mainChr.skill.Fencing;
						if (IsCharacterPerkOn(mainChr,"BasicDefence")) crew.perks.list.BasicDefence = true;
						if (IsCharacterPerkOn(mainChr,"AdvancedDefence")) crew.perks.list.AdvancedDefence = true;					
						if (IsCharacterPerkOn(mainChr,"SwordplayProfessional")) crew.perks.list.SwordplayProfessional = true;	
						if (IsCharacterPerkOn(mainChr,"CriticalHit")) crew.perks.list.CriticalHit = true;
						if (IsCharacterPerkOn(mainChr,"Gunman")) crew.perks.list.Gunman = true;
						if (IsCharacterPerkOn(mainChr,"GunProfessional")) crew.perks.list.GunProfessional = true;
						LAi_SetHP(crew, mainChr.chr_ai.hp, mainChr.chr_ai.hp_max);
						LAi_SetOfficerType(crew);
					
					//JRH -->
						string bladeID = GetCharacterEquipByGroup(crew, BLADE_ITEM_TYPE);
						aref blade;
						Items_FindItem(bladeID, &blade);

						string bladeID2 = GetCharacterEquipByGroup(mainChr, BLADE_ITEM_TYPE);
						aref blade2;
						Items_FindItem(bladeID2, &blade2);

						string gunID = GetCharacterEquipByGroup(crew, GUN_ITEM_TYPE);
						aref gun;
						Items_FindItem(gunID, &gun);

						string gunID2 = GetCharacterEquipByGroup(mainChr, GUN_ITEM_TYPE);
						aref gun2;
						Items_FindItem(gunID2, &gun2);

						string old_gun;
						string right_gun;

						string old_blade;
						string right_blade = "bladeX4";
				//---------------------------------------------------------------------------------------------------		

						if(CheckAttribute(blade2, "price"))
						{
							if(blade2.price >= 2)		right_blade = "barmansknife";	//anything better than fists
							if(blade2.price >= 50)		right_blade = "blade4";
							if(blade2.price >= 250)		right_blade = "blade10";
							if(blade2.price >= 500)		right_blade = "blade12";
							if(blade2.price >= 1000)	right_blade = "blade31";
							if(blade2.price >= 4000)	right_blade = "blade24";
							if(blade2.price >= 8000)	right_blade = "blade34";
						}

						if(bladeID2 == "")
						{
							right_blade = "";
						}

						//LogIt("right_blade = " + right_blade);

						if(CheckCharacterEquipByGroup(crew, BLADE_ITEM_TYPE) != right_blade) // PB: Check if character has the equipped item
						{
							if(bladeID != "")
							{
								old_blade = GetCharacterEquipByGroup(crew, BLADE_ITEM_TYPE);
								//LogIt("old_blade = " + old_blade);
								TakeItemFromCharacter(crew, old_blade);
							}
							//else LogIt("old_blade = " + "no blade");

							GiveItem2Character(crew, right_blade);
							EquipCharacterbyItem(crew, right_blade);
						}

				//---------------------------------------------------------------------------------------------------
					    if(GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
						{
							if(gunID2 == "pistolmket" || gunID2 == "pistolmtoon" || gunID2 == "pistol10" || gunID2 == "LongRifle_C" || gunID2 == "LongRifle_CT")
							{
								right_gun = "pistolbbuss";
							}

							if(gunID2 == "pistolbbuss")
							{
								right_gun = "pistol3";
							}

							if(gunID2 == "pistol3_14" || HasSubStr(gunID2, "pistol9"))
							{
								right_gun = "pistol5";
							}

							if(HasSubStr(gunID2, "pistol8"))
							{
								right_gun = "pistol6";
							}

							if( HasSubStr(gunID2, "pistol7") || HasSubStr(gunID2, "pistol6") || HasSubStr(gunID2, "PiratesPistol") )
							{
								right_gun = "pistol2";
							}

							if(HasSubStr(gunID2, "pistol4") || gunID2 == "pistol4_1")
							{
								right_gun = "pistol7";
							}

							if(HasSubStr(gunID2, "pistol5") || HasSubStr(gunID2, "pistol3") )
							{
								right_gun = "PiratesPistol";
							}

							if( HasSubStr(gunID2, "pistol25") || HasSubStr(gunID2, "pistol26") )
							{
								right_gun = "pistol5";
							}
							else
							{
								if(HasSubStr(gunID2, "pistol2") ) 
								{
									right_gun = "pistol1";
								}
							}

							if(HasSubStr(gunID2, "pistol1") )
							{
								right_gun = "pistol1";
							}

							if(gunID2 == "")
							{
								right_gun = "";
							}
					    }
					    else
					    {
							if(gunID2 == "Arguebuse" || gunID2 == "pistol13")
							{
								right_gun = "pistol13";
							}

							if( HasSubStr(gunID2, "pistol11") || HasSubStr(gunID2, "pistol12") )
							{
								right_gun = "pistol11";
							}
					    }
						//LogIt("right_gun = " + right_gun);

						if(CheckCharacterEquipByGroup(crew, GUN_ITEM_TYPE) != right_gun) // PB: Check if character has the equipped item
						{
							if(gunID != "")
							{
								old_gun = GetCharacterEquipByGroup(crew, GUN_ITEM_TYPE);
								//LogIt("old_gun = " + old_gun);
								TakeItemFromCharacter(crew, old_gun);
							}
							//else LogIt("old_gun = " + "no gun");

							GiveItem2Character(crew, right_gun);
							EquipCharacterbyItem(crew, right_gun);
							
						//AMMO only if crew got a gun
							gunID = GetCharacterEquipByGroup(crew, GUN_ITEM_TYPE);
							Items_FindItem(gunID, &gun);
							
							if(gunID != "")
							{
								TakeNItems(crew,"gunpowder", -100);
								TakeNItems(crew,"pistolbullets", -100);
								TakeNItems(crew,"pistolgrapes", -100);
								TakeNItems(crew,"musketbullets", -100);

								if(CheckAttribute(gun, "shottype"))
								{
									if(gun.shottype == "pb" || gun.shottype == "pb2") TakeNItems(crew,"pistolbullets", 6);
									if(gun.shottype == "pg" || gun.shottype == "pg2") TakeNItems(crew,"pistolgrapes", 6);
									if(gun.shottype == "mb") TakeNItems(crew,"musketbullets", 3);
									if(gun.shottype == "pg" || gun.shottype == "pg2" || gun.shottype == "pb" || gun.shottype == "pb2" || gun.shottype == "mb")
									TakeNItems(crew,"gunpowder", 6);
									if(gun.shottype == "ca") TakeNItems(crew,"cartridges", 6);
								}
						//here for "new" gun, both first gun or changed gun
								if(CheckAttribute(gun, "chargeQ"))
								{
									crew.chr_ai.charge = makeint(gun.chargeQ);
								}
							}
						}
				
						if(right_gun == "")
						{
							TakeNItems(crew,"gunpowder", -100);
							TakeNItems(crew,"pistolbullets", -100);
							TakeNItems(crew,"pistolgrapes", -100);
							TakeNItems(crew,"musketbullets", -100);
						}
						//LogIt("gun.shottype = " + gun.shottype);	
						//LogIt("charges = " + crew.chr_ai.charge);
						//LAi_SetImmortal(crew, true);		//while testing
					//<-- JRH
					}
				}
			}
		}
		// SCREWFACE : End
		locIndex = 0; // KK
		for (i = 1; i < OFFICER_MAX; i++) {
			idx = GetOfficersIndex(mainChr, i);
			if (idx < 0) continue;

			if (locations[FindLocation(mainChr.location)].type=="jail") continue; // added by MAXIMUS

// KK -->
			if (CheckAttribute(loc, "locators.officers")) {
				locIndex++;
			} else {
				continue;
			}
// <-- KK

			DeleteAttribute(&Characters[idx], "location");
			Characters[idx].location = mainChr.location;
			Characters[idx].location.group = "officers";

// changed by MAXIMUS [bug with officers, not loaded into the next reload location] -->
			locator = mainChr.location.locator;
			if (strcut(locator, strlen(locator) - 4, strlen(locator) - 1) == "back")
				Characters[idx].location.locator = strcut(locator, 0, strlen(locator) - 6) + "_" + locIndex;
			else
				Characters[idx].location.locator = locator + "_" + locIndex;
			
			locator = Characters[idx].location.locator;
			makearef(st, loc.locators.reload);
			num = GetAttributesNum(st);
			for (offic = 0; offic < num; offic++)
			{
				//int at = GetAttributeN(st, offic);
				sat = "locators.officers." + locator;
				//res = 0;
				if(!CheckAttribute(loc, sat))
				{
					Characters[idx].location.group = "reload";
					Characters[idx].location.locator = mainChr.location.locator;
				}
			}
// changed by MAXIMUS [bug with officers, not loaded into the next reload location] <--

			if(LAi_restoreStates)
			{
				LAi_SetCurHPMax(&Characters[idx]);
				LAi_UseAtidoteBottle(&Characters[idx]);
			}
		}
	} else {
		LAi_restoreStates = false;
	}
	LAi_IsCapturedLocation = IsLocationCaptured(loc.id);
}

//Инициализация интелекта
void LocAi_Release()
{
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			LAi_CharacterLogoff(&Characters[idx]);
		}
	}
	LAi_group_Release();
	LAi_IsInitedAI = false;
	LAi_numloginedcharacters = 0;
	DelEventHandler("CharacterUpdate", "LAi_CharacterUpdate");
	DelEventHandler("CharactersStateUpdate", "LAi_Character_FrameUpdate");
	DelEventHandler("Location_CharacterEndTask", "LAi_CharacterEndTask");
	DelEventHandler("Location_CharacterTaskFailure", "LAi_CharacterTaskFailure");
	DelEventHandler("Location_CharacterBusyPos", "LAi_CharacterBusyPos");
	DelEventHandler("Location_CharacterFollowGo", "LAi_CharacterFollowGo");
	DelEventHandler("Location_CharacterFollowStay", "LAi_CharacterFollowStay");
	DelEventHandler("Location_CharacterFightGo", "LAi_CharacterFightGo");
	DelEventHandler("Location_CharacterFightStay", "LAi_CharacterFightStay");
	DelEventHandler("Location_CharacterAttack", "LAi_CharacterAttack");
	DelEventHandler("Location_CharacterBlock", "LAi_CharacterBlock");
	DelEventHandler("Location_CharacterFire", "LAi_CharacterFire");
	DelEventHandler("Location_CharacterIsFire", "LAi_CharacterIsFire");
	DelEventHandler("Location_CharacterIsFight", "LAi_CharacterIsFight");
	DelEventHandler("Location_CharacterEscapeSlide", "LAi_CharacterEscapeSlide");
	DelEventHandler("Location_CharacterColThreshold", "LAi_CharacterColThreshold");
	DelEventHandler("Location_Character_EndAction", "LAi_Character_EndAction");	
	//Очистим фантомных персонажей
	LAi_Clear_Fantoms();
}


void LocAi_PostInit(ref loc)
{
	if(!LAi_IsBoarding) LAi_CharacterPostLogin(loc);
	if(ownDeckStarted() && !bMutinyDeckStarted) LAi_CharacterPostLogin(loc);//MAXIMUS: automatically fills ship by people
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			LAi_PostLoginInit(&Characters[idx]);
			ReloadProgressUpdate(); //Levis
		}
	}
	LAi_restoreStates = false;
}

//Инициализация перед новой игрой
void LAi_NewGame()
{
	//Задержанные квесты
	DeleteAttribute(&Lai_questdelays, "");
	//Группы
	DeleteAttribute(&LAi_grp_relations, "");
	LAi_grp_playeralarm = 0;
	LAi_grp_alarmactive = false;
	//Абордаж
	boarding_location = -1;
	boarding_location_type = -1;
	boarding_enemy_crew = 0;
	boarding_player_crew = 0;
	boarding_officers = 0;
	boarding_player_crew_per_chr = 1.0;
	boarding_exp = 0;
	LAi_boarding_process = false;
	//Разное
	LAi_IsInitedAI = false;
	LAi_IsCapturedLocation = false;
	LAi_restoreStates = true;
	DeleteAttribute(&LAi_MonsterInfo, "");
	LAi_numloginedcharacters = 0;
	DeleteAttribute(&LAi_QuestFader, "");
	globalSGMode = false;
// KK -->
	bDeckStarted = false;
	bCabinStarted = false;
	bCrewStarted = false;
	bDeckEnter = false;
	bToDeckFromLand = false;
	DeckID = "";
	FromDeckIdx = -1;
	LandLocationIdx = -1;
	LandLocator = "";
// <-- KK
	//Ставим тип игрока главному персонажу
	LAi_SetPlayerType(GetMainCharacter());
}



