

#define LAI_TMPL_FIGHT	"fight"
#define DEBUG_FIGHTING	0

/*
	Возможные состояния:
		"wait"		ждёт цели
		"go"		идёт к цели
		"fight"		дерётся с целью
		"stop"		ждёт возможности пройти к цели
		"chase"		The character has its sword sheeted and is chasing you (EXPERIMENTAL)
*/

float firedistance,fightdistance,checkdistance,chasedistance,hppercantagehelp;
object GroupTargets;


bool LAi_tmpl_SetFight(aref chr, aref target)
{
	float charge = stf(chr.chr_ai.charge);

	//if (chr.chr_ai.group == target.chr_ai.group) return false; // KK // PB: Removed as this can prevent quest characters from fighting each other
	if(!LAi_tmpl_fight_InitTemplate(chr)) return false;
	if(DEBUG_FIGHTING) trace("Called Set fight for "+chr.id+" with target "+target.id);
	if(IMPROVE_FIGHT_AI)
	{
		if(chr.chr_ai.tmpl.state != "support")
		{
			LAi_tmpl_fight_SetTarget(chr, target);
		}
	}
	else
	{
		LAi_tmpl_fight_SetTarget(chr, target);
	}

// JRH -->
	if(IsEquipCharacterByItem(chr, "pistolmket"))
	{
		if(charge == 1.0) 
		{
			PostEvent("mket_on_hip", 1000, "i", chr);
		}
		else
		{
			if(CheckCharacterItem(chr, "blade_mKnife"))
			{
				PostEvent("mketK_as_blade", 1000, "i", chr);
			}
		}
	}

	if(IsEquipCharacterByItem(chr, "pistolmtoon"))
	{
		if(charge == 1.0) PostEvent("mtoon_on_hip", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "pistolmketB"))
	{
		if(charge == 1.0) 
		{
			PostEvent("mketB_on_hip", 0, "i", chr);
		}
		else PostEvent("mketB_as_blade", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "Arguebuse"))
	{
		if(charge == 1.0) PostEvent("Arguebuse_on_hip", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "pistolbbuss"))
	{
		if(charge == 1.0) PostEvent("bbuss_on_hip", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "pistol13"))
	{
		if(charge == 1.0) PostEvent("pistol13_on_hip", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "LongRifle_C"))
	{
		if(charge == 1.0) PostEvent("LongRifle_C_on_hip", 0, "i", chr);
	}
	
	if(IsEquipCharacterByItem(chr, "LongRifle_H"))
	{
		if(charge == 1.0) PostEvent("LongRifle_H_on_hip", 0, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "portugize"))
	{
		if(charge >= 1.0) PostEvent("portugize_on_hip", 0, "i", chr);			//changed from charge == 1.0
	}

	if(IsEquipCharacterByItem(chr, "battleax"))
	{
		PostEvent("bax_on_hip", 10, "i", chr);
	}

	if(IsEquipCharacterByItem(chr, "witcher_steel-2") || IsEquipCharacterByItem(chr, "witcher_steel-1") 
	|| IsEquipCharacterByItem(chr, "witcher_steel") || IsEquipCharacterByItem(chr, "witcher_steel+1") 
	|| IsEquipCharacterByItem(chr, "witcher_steel+2") || IsEquipCharacterByItem(chr, "witcher_steel+3"))
	{
		PostEvent("witcher_steel_on_hip", 10, "i", chr);
	}
// <-- JRH

	return true;
}

bool LAi_tmpl_fight_LostTarget(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return true;
	string state = chr.chr_ai.tmpl.state;
	if(state == "wait") return true;
	return false;
}

bool LAi_tmpl_fight_NoActive(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return true;
	if(chr.chr_ai.tmpl.state != "fight") return true;
	return false;
}

bool LAi_tmpl_fight_IsGo(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return false;
	if(chr.chr_ai.tmpl.state == "go") return true;
	return false;
}

bool LAi_tmpl_fight_InitTemplate(aref chr)
{
	CharacterPlayAction(chr, "");
	bool isNew = false;
	if(CheckAttribute(chr, "chr_ai.tmpl"))
	{
		if(chr.chr_ai.tmpl != LAI_TMPL_FIGHT) isNew = true;
	}else{
		isNew = true;
	}
	if(IMPROVE_FIGHT_AI)
	{
		if(DEBUG_FIGHTING) trace("Called LAi_tmpl_fight_InitTemplate");
		firedistance = 15;
		checkdistance = 20;
		chasedistance = 7;
		fightdistance = 2.5;
		hppercantagehelp = 0.3;
		if(isNew)
		{
			chr.chr_ai.tmpl.changestatetime = "0";
			DeleteAttribute(chr, "chr_ai.tmpl");
			chr.chr_ai.tmpl = LAI_TMPL_FIGHT;
			int idx = LAi_tmpl_fight_SetBestTarget(chr);
			if(idx == -1) 
			{
				LAi_tmpl_fight_SetTarget(chr, NullCharacter);
			}
			else 
			{
				LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
			}
			chr.chr_ai.tmpl.time = "0";
			LAi_tmpl_fight_FightStay(chr);
		}
	}
	else
	{
	// KK -->
		//bool isRes = SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode");
		//if(!LAi_IsInitedAI) isRes = true;
	// <-- KK
		if(isNew)
		{
			DeleteAttribute(chr, "chr_ai.tmpl");
			chr.chr_ai.tmpl = LAI_TMPL_FIGHT;
			chr.chr_ai.tmpl.target = "";
			LAi_tmpl_fight_SetWaitState(chr);
			chr.chr_ai.tmpl.time = "0";
			if(LAi_IsInitedAI)
			{
				LAi_tmpl_fight_SetWaitState(chr);
			}
		}else{
			if(!CheckAttribute(chr, "chr_ai.tmpl.state")) LAi_tmpl_fight_SetWaitState(chr);
			if(!CheckAttribute(chr, "chr_ai.tmpl.time")) chr.chr_ai.tmpl.time = "0";
			if(!CheckAttribute(chr, "chr_ai.tmpl.target"))
			{
				chr.chr_ai.tmpl.target = "";
				LAi_tmpl_fight_SetWaitState(chr);
			}else{
				if(chr.chr_ai.tmpl.target == "")
					LAi_tmpl_fight_SetWaitState(chr);
			}
			LAi_tmpl_fight_updatetemplate(chr);
		}
		chr.chr_ai.tmpl.nostop = "5";
		LAi_SetFightMode(chr,true);
		LAi_LockFightMode(chr,true);
	}
	return LAi_IsInitedAI;
}

//Процессирование шаблона персонажа
void LAi_tmpl_fight_CharacterUpdate(aref chr, float dltTime)
{
	//Если не в режиме боя переведём в него
	float time,cx,cy,cz,tx,ty,tz,distancetotarget;
	aref tmpl;
	makearef(tmpl, chr.chr_ai.tmpl);
	int idx;
	string aigroup = chr.chr_ai.group;
	aref Allies3: makearef(Allies3,GroupTargets.(aigroup).members);
	string group = "goto";
	string locator = "";
	if(DEBUG_FIGHTING) trace("Update "+chr.id+" with target = "+tmpl.target+" state = "+tmpl.state);
	if(tmpl.target != "")
	{
		ref target = &Characters[sti(tmpl.target)];
		//Анализируем действие стояния
		if(IMPROVE_FIGHT_AI)
		{
			if(DEBUG_FIGHTING) trace("Start Update");
			if(LAi_IsDead(target))
			{
				idx = LAi_tmpl_fight_SetBestTarget(chr);
				if(idx == -1) 
				{
					if(DEBUG_FIGHTING) trace("No target found for "+chr.id);
					LAi_tmpl_fight_SetWaitState(chr);
					LAi_Character_TemplateComplite(chr, LAI_TMPL_FIGHT);
					return;
				}
				else 
				{
					LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
				}
				tmpl.time = 0
			}
			else
			{
				time = stf(tmpl.time) + dltTime;
				tmpl.changestatetime = stf(tmpl.changestatetime) + dltTime;
				if(time > 3)
				{
					idx = LAi_tmpl_fight_SetBestTarget(chr);
					if(idx == -1) 
					{
						//Maybe our target just went out of checking range, but we don't want to loose it now do we...
						if(LAi_IsDead(target))
						{
							if(DEBUG_FIGHTING) trace("No target found for "+chr.id);
							LAi_tmpl_fight_SetWaitState(chr);
							LAi_Character_TemplateComplite(chr, LAI_TMPL_FIGHT);
							return;
						}
					}
					else
					{
						LAi_tmpl_fight_SetTarget(chr, &Characters[idx])
					}
					tmpl.time = 0;
				}else{
					tmpl.time = time;
				}
			}
			//Levis: chasing
			cx,cy,cz,tx,ty,tz;
			GetCharacterPos(chr, &cx, &cy, &cz);
			GetCharacterPos(target, &tx, &ty, &tz);
			distancetotarget = GetDistance2D(cx, cz, tx, tz);
			if(tmpl.state == "chase")
			{
				if(distancetotarget < chasedistance)
				{
					LAi_tmpl_fight_FightStay(chr);
				}
				else
				{
					if(LAi_CharacterCanFire(chr) && distancetotarget < firedistance)//If we can fire we do
					{
						LAi_tmpl_fight_FightFire(chr);
					}
					else
					{
						LAi_tmpl_fight_FightChase(chr);
					}
				}
			}
			else
			{
				if(stf(tmpl.changestatetime) > 8 && tmpl.state == "go")
				{
					//Character doesn't seem to reach his destination
					if(CanReloadGun(chr)) 
					{
						if(DEBUG_FIGHTING) trace("Set Support because character can't reach target");
						LAi_tmpl_fight_FightSupport(chr);
					}
					else
					{
						if(DEBUG_FIGHTING) trace("Switchin because character can't reach target but can't reload either");
						LAi_tmpl_fight_SwitchIn(chr);
					}
				}
				else
				{
					if(tmpl.state == "fight" && LAi_GetCharacterRelHP(chr) < 0.6)
					{
						if(CanReloadGun(chr))
						{
							if(GetAttributesNum(Allies3) > 4) //Check how many allies left, if we have less then 4 allies left you should start fighting anyways
							{
								idx = LAi_tmpl_fight_SetBestTarget(chr);
								if(idx >= 0)
								{
									if(sti(GetAttribute(GroupTargets,aigroup+".targets."+idx)) < 2 || !CheckAttribute(GroupTargets,aigroup+".targets."+idx)) //If the best target has no people fighting it then go get it!
									{
									
										if(DEBUG_FIGHTING) trace("Nobody is taking care of best target so in we go altough we are exhausted");
										LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
										LAi_tmpl_fight_FightStay(chr);
									}
									else
									{
										if(DEBUG_FIGHTING) trace("Set Support because character is getting exhausted and enough people are handling this target already");
										LAi_tmpl_fight_FightSupport(chr);
									}
								}
								else
								{
									//If the character is getting wounded it becomes supporting.
									if(DEBUG_FIGHTING) trace("Set Support because character is getting exhausted and enough people are handling this target already");
									LAi_tmpl_fight_FightSupport(chr);
								}
							}
							else
							{
								LAi_tmpl_fight_FightGo(chr);
							}
						}
						else
						{
							if(DEBUG_FIGHTING) trace("fighting but can't reload aigroup = "+aigroup+" target = "+target.index+". agains "+sti(GetAttribute(GroupTargets,aigroup+".targets."+target.index)));
							if(sti(GetAttribute(GroupTargets,aigroup+".targets."+target.index))>4)
							{
								//If more then 4 people are attacking your enemy you can go supporting too
								if(DEBUG_FIGHTING) trace("Enough people are attacking this target already, I'm going to make some room altough I can't reload but that will keep me fresh so I can switch in");
								LAi_tmpl_fight_FightSupport(chr);
							}
							else
							{
								LAi_tmpl_fight_FightStay(chr);
							}
						}
					}
					else
					{
						if(tmpl.state == "fire")
						{
							if(LAi_CharacterCanFire(chr))
							{
								if(distancetotarget > fightdistance)
								{
									CharacterTurnByChr(chr,target);
									LAi_tmpl_fight_FightFire(chr);
								}
								else
								{
									if(DEBUG_FIGHTING) trace("Should we try to make some distance to fire the shot? it "+chr.chr_ai.tmpl.changestatetime+" ticks ago");
									if(sti(chr.chr_ai.tmpl.changestatetime) > 4)
									{
										if(DEBUG_FIGHTING) trace("it's long enough ago so let's try it");
										//Try to make some distance
										group = "goto";
										locator = LAi_FindRandomLocator(group);
										if(locator == "") { group = "rld"; locator = LAi_FindRandomLocator(group); }
										if(locator == "") { group = "reload"; locator = LAi_FindRandomLocator(group); }
										if(locator != "")
										{
											SetCharacterTask_RuntoPoint(chr, group, locator);
										}
										if(DEBUG_FIGHTING) trace("run to "+group+" "+locator);
									}
									else
									{
										if(DEBUG_FIGHTING) trace("no continue with what we where doing");
										CharacterTurnByChr(chr,target);
										LAi_tmpl_fight_FightFire(chr);
									}
								}
							}
							else
							{
								if(distancetotarget > fightdistance)
								{
									LAi_tmpl_fight_FightGo(chr);
								}
								else
								{
									LAi_tmpl_fight_FightStay(chr);
								}
							}
						}
						else
						{
							if(LAi_CharacterCanFire(chr) && distancetotarget < firedistance)//If we can fire we do
							{
								LAi_tmpl_fight_FightFire(chr);
							}
							else
							{
								if(distancetotarget > chasedistance) //If we can still fire a shot we don't chase we fire first
								{
									LAi_tmpl_fight_FightChase(chr);
								}
								else
								{
									if(distancetotarget > fightdistance)
									{
										LAi_tmpl_fight_FightGo(chr);
									}
									else
									{
										LAi_tmpl_fight_FightStay(chr);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if(SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
			{
				LAi_LockFightMode(chr,false);
				LAi_SetFightMode(chr,true);
				LAi_LockFightMode(chr,true);
			}
			//Если есть цель, то отслеживаем её смерть
			if(LAi_IsDead(target))
			{
				LAi_tmpl_fight_SetWaitState(chr);
				LAi_Character_TemplateComplite(chr, LAI_TMPL_FIGHT);
				return;
			}
			if(tmpl.state == "stop")
			{
				//Определим дистанцию до противника
				if(!LAi_tmpl_fight_CheckEnemy(chr))
				{
					time = stf(tmpl.time) - dltTime;
					if(time < 0)
					{
						LAi_tmpl_fight_StopRestore(chr);
						tmpl.time = -1;
					}else{
						tmpl.time = time;
					}
				}else{
					LAi_tmpl_fight_StopRestore(chr);
					tmpl.time = -1;
				}
			}else{
				time = stf(tmpl.nostop) - dltTime;
				if(time <= 0.0) time = -1.0;
				tmpl.nostop = time;
			}
		}
		if(DEBUG_FIGHTING) trace("End Update");
	}else{

	//JRH -->
		if(IsEquipcharacterByItem(chr, "pistolmket"))
		{
			PostEvent("mket_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "blademketK"))
		{
			PostEvent("blademketK_as_gun", 1000, "i", chr);
			PostEvent("mket_on_back", 1500, "i", chr);	//if musket on hip
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "pistolmtoon"))
		{
			PostEvent("mtoon_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "pistolmketB"))
		{
			PostEvent("mketB_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "blademketB"))
		{
			PostEvent("blademketB_as_gun", 1000, "i", chr);
			PostEvent("mketB_on_back", 1500, "i", chr);	//if musket on hip
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "Arguebuse"))
		{
			PostEvent("Arguebuse_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "pistolbbuss"))
		{
			PostEvent("bbuss_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "pistol13"))
		{
			PostEvent("pistol13_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "LongRifle_C"))
		{
			PostEvent("LongRifle_C_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}
		if(IsEquipCharacterByItem(chr, "LongRifle_H"))
		{
			PostEvent("LongRifle_H_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "portugize"))
		{
			PostEvent("portugize_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}

		if(IsEquipCharacterByItem(chr, "battleax"))
		{
			PostEvent("bax_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}
	
		if(IsEquipCharacterByItem(chr, "witcher_steel-2") || IsEquipCharacterByItem(chr, "witcher_steel-1") 
		|| IsEquipCharacterByItem(chr, "witcher_steel") || IsEquipCharacterByItem(chr, "witcher_steel+1") 
		|| IsEquipCharacterByItem(chr, "witcher_steel+2") || IsEquipCharacterByItem(chr, "witcher_steel+3"))
		{
			PostEvent("witcher_steel_on_back", 1000, "i", chr);
			PostEvent("mguns_reset_check", 1000, "i", chr);
		}
	// <-- JRH
		if(IMPROVE_FIGHT_AI)
		{
			if(tmpl.state != "support")
			{
				//Check for a enemy again else stop this template
				idx = LAi_tmpl_fight_SetBestTarget(chr);
				if(idx == -1) 
				{
					if(DEBUG_FIGHTING) trace("No target found for "+chr.id);
					LAi_tmpl_fight_SetWaitState(chr);
					LAi_Character_TemplateComplite(chr, LAI_TMPL_FIGHT);
					return;
				}
				else 
				{
					LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
					LAi_tmpl_fight_FightStay(chr);
				}
			}
			else
			{
				int nearestchar = LAi_tmpl_fight_NearestEnemy(chr, checkdistance);
				if(nearestchar >= 0)
				{
					GetCharacterPos(&characters[nearestchar], &tx, &ty, &tz);
					GetCharacterPos(chr, &cx, &cy, &cz);
					distancetotarget = GetDistance2D(cx, cz, tx, tz);
				}
				else
				{
					distancetotarget = chasedistance+1;
				}
				bool helppchar = false;
				//If the mainplayer is in need and we are in the playergroup we need to help him out
				if(aigroup == "player")
				{
					float hp = LAi_GetCharacterRelHP(GetMainCharacter());
					if(hp < hppercantagehelp)
					{
						idx = LAi_tmpl_fight_SetBestTarget(GetMainCharacter());
						if(idx > -1) 
						{
							LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
							LAi_tmpl_fight_FightStay(chr);
							helppchar = true;
						}
					}
				}
				if(!helppchar)
				{
					//We are supporting and our gun is reloaded so time to use it
					idx = LAi_tmpl_fight_SetBestTarget(chr); //moved outside the loop so its called for supporting characters to check if others are alive
					if(sti(GetAttribute(GroupTargets,aigroup+".targets."+idx)) < 2 || !CheckAttribute(GroupTargets,aigroup+".targets."+idx)) //If the best target has no people fighting it then go get it!
					{
						if(idx >= 0)
						{
							if(DEBUG_FIGHTING) trace("Nobody is taking care of best target so in we go");
							LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
							LAi_tmpl_fight_FightStay(chr);
						}
						else
						{
							if(DEBUG_FIGHTING) trace("There seems to be nobody around anymore");
							LAi_tmpl_fight_FightSupport(chr);
							//Let's find a place where we can fight again.
							group = "goto";
							locator = locator = LAi_FindRandomLocator(group);
							if(locator == "") { group = "rld"; locator = locator = LAi_FindRandomLocator(group); }
							if(locator == "") { group = "reload"; locator = LAi_FindRandomLocator(group); }
							if(locator != "")
							{
								SetCharacterTask_RuntoPoint(chr, group, locator);
							}
							if(DEBUG_FIGHTING) trace("run to "+group+" "+locator);
						}
					}
					else
					{
						if(GetAttributesNum(Allies3) > 4) //Check how many allies left, if we have less then 4 allies left you should start fighting anyways
						{
							if(distancetotarget > chasedistance)
							{
								if(LAi_CharacterCanFire(chr))
								{
									if(idx == -1) 
									{
										if(DEBUG_FIGHTING) trace("No target found for "+chr.id);
										LAi_tmpl_fight_SwitchIn(chr);
									}
									else 
									{
										if(DEBUG_FIGHTING) trace("Character "+chr.id+" should fire gun");
										LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
										LAi_tmpl_fight_FightFire(chr);
									}
								}
								else
								{
									SetCharacterTask_Stay(chr);
									CharacterTurnByChr(chr,&characters[nearestchar]);
									if(CanReloadGun(chr)) 
									{
										if(DEBUG_FIGHTING) trace("Character "+chr.id+" is reloading "+chr.chr_ai.charge);
										LAi_tmpl_fight_FightSupport(chr);
									}
									else
									{
										if(DEBUG_FIGHTING) trace("Character "+chr.id+" can't fire or reload so check if character should switch in with someone");
										LAi_tmpl_fight_SwitchIn(chr);
									}
								}
							}
							else
							{
								if(LAi_CharacterCanFire(chr) && distancetotarget > fightdistance) //If we can fire we should do so first but we do need to take a little distance so we can properly aim
								{
									if(idx == -1) 
									{
										if(DEBUG_FIGHTING) trace("No target found for "+chr.id);
										LAi_tmpl_fight_SwitchIn(chr);
									}
									else 
									{
										if(DEBUG_FIGHTING) trace("Character "+chr.id+" taken some distance so it should fire the gun now");
										LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
										LAi_tmpl_fight_FightFire(chr);
									}
								}
								else
								{
									//If we are to close we run away
									if(nearestchar >= 0)
									{
										group = "goto";
										locator = LAi_FindFarFreeLocator(group, tx, ty, tz);
										if(locator == "") { group = "rld"; locator = LAi_FindFarFreeLocator(group, tx, ty, tz); }
										if(locator == "") { group = "reload"; locator = LAi_FindFarFreeLocator(group, tx, ty, tz); }
										if(locator != "")
										{
											SetCharacterTask_RuntoPoint(chr, group, locator);
										}
										if(DEBUG_FIGHTING) trace("run to "+group+" "+locator);
									}
								}
							}
						}
						else
						{
							if(DEBUG_FIGHTING) trace("Character "+chr.id+" is running out of allies so time to join the fight again");
							idx = LAi_tmpl_fight_SetBestTarget(chr);
							LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
							LAi_tmpl_fight_FightGo(chr);
						}
					}
				}
			}
			tmpl.time = 0
		}
		else
		{
			//Если цели нет, переходим в режим ожидания
			if(tmpl.state != "wait")
			{
				LAi_tmpl_fight_SetWaitState(chr);
			}
		}
	}
}

//Персонаж выполнил команду  go to point
void LAi_tmpl_fight_EndGoToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  go to point
void LAi_tmpl_fight_FailureGoToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж выполнил команду  run to point
void LAi_tmpl_fight_EndRunToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  run to point
void LAi_tmpl_fight_FailureRunToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж не может добраться до точки назначения
void LAi_tmpl_fight_BusyPos(aref chr, float x, float y, float z)
{
	if(!IMPROVE_FIGHT_AI) LAi_tmpl_fight_Stop(chr, 1.0 + rand(3));
}

//Персонаж начал перемещение за другим
void LAi_tmpl_fight_FollowGo(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_fight_FollowStay(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  follow character
void LAi_tmpl_fight_FailureFollow(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж начал перемещение за другим
void LAi_tmpl_fight_FightGo(aref chr)
{
	if(!LAi_IsFightMode(chr))
	{
		LAi_LockFightMode(chr,false);
		LAi_SetFightMode(chr,true);
		LAi_LockFightMode(chr,true);
	}
	if(GetAttribute(chr,"chr_ai.tmpl.state") != "go")
	{
		chr.chr_ai.tmpl.changestatetime = "0";
	}
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now going");
	chr.chr_ai.tmpl.state = "go";
	GroupTargetSetState(chr, "go");
}

void LAi_tmpl_fight_FightFire(aref chr)
{
	if(!LAi_IsFightMode(chr))
	{
		LAi_LockFightMode(chr,false);
		LAi_SetFightMode(chr,true);
		LAi_LockFightMode(chr,true);
	}
	if(GetAttribute(chr,"chr_ai.tmpl.state") != "fire")
	{
		chr.chr_ai.tmpl.changestatetime = "0";
	}
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now fireing");
	chr.chr_ai.tmpl.state = "fire";
	GroupTargetSetState(chr, "fire");
}

//Levis: Chase mode
void LAi_tmpl_fight_FightChase(aref chr)
{
	if(LAi_IsFightMode(chr))
	{
		LAi_LockFightMode(chr,false);
		LAi_SetFightMode(chr,false);
		LAi_LockFightMode(chr,true);
	}
	if(GetAttribute(chr,"chr_ai.tmpl.state") != "chase")
	{
		chr.chr_ai.tmpl.changestatetime = "0";
	}
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now chasing");
	chr.chr_ai.tmpl.state = "chase";
	GroupTargetSetState(chr, "chase");
}

//Levis: Support mode
void LAi_tmpl_fight_FightSupport(aref chr)
{
	if(LAi_IsFightMode(chr))
	{
		LAi_LockFightMode(chr,false);
		LAi_SetFightMode(chr,false);
		LAi_LockFightMode(chr,true);
	}
	if(GetAttribute(chr,"chr_ai.tmpl.state") != "support")
	{
		chr.chr_ai.tmpl.changestatetime = "0";
	}
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now supporting");
	LAi_tmpl_fight_SetTarget(chr, NullCharacter);
	chr.chr_ai.tmpl.state = "support";
	GroupTargetSetState(chr, "support");
}

//Levis: Switch Incase
void LAi_tmpl_fight_SwitchIn(aref chr)
{
	int idx = FindSwitchInPartner(chr);
	if(DEBUG_FIGHTING) trace("Switch in with "+idx);
	string aigroup = chr.chr_ai.group;
	if(idx > 0)
	{
		if(CheckAttribute(GroupTargets,aigroup+".members."+idx))
		{
			ref target = &characters[idx];
			idx = GetAttribute(GroupTargets,aigroup+".members."+idx);
			if(idx >= 0)
			{
				if(DEBUG_FIGHTING) trace("SWITCHING "+target.id+" to support and "+chr.id+" to the battle");
				LAi_tmpl_fight_FightSupport(target);
				LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
				LAi_tmpl_fight_FightGo(chr);
				return;
			}
		}
	}
	else
	{
		//We check if a target has less then 3 people attacking it. If so we switch in there instead.
		aref Targets: makearef(Targets,GroupTargets.(aigroup).targets);
		for(int i = 0; i < GetAttributesNum(Targets); i++)
		{
			idx = sti(GetAttributeName(GetAttributeN(Targets, i)));
			if(sti(GetAttributeValue(GetAttributeN(Targets, i))) < 4 && idx >= 0)
			{
				if(DEBUG_FIGHTING) trace("Assisting "+idx+" instead of switching in");
				LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
				LAi_tmpl_fight_FightGo(chr);
				return;
			}
		}
	}
	LAi_tmpl_fight_FightSupport(chr);
}


//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_fight_FightStay(aref chr)
{
	if(!LAi_IsFightMode(chr))
	{
		LAi_LockFightMode(chr,false);
		LAi_SetFightMode(chr,true);
		LAi_LockFightMode(chr,true);
	}
	if(GetAttribute(chr,"chr_ai.tmpl.state") != "fight")
	{
		chr.chr_ai.tmpl.changestatetime = "0";
	}
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now fighting");
	chr.chr_ai.tmpl.state = "fight";
	GroupTargetSetState(chr, "fight");
}

//Персонаж провалил команду  Fight
void LAi_tmpl_fight_FailureFight(aref chr)
{
	if(!IMPROVE_FIGHT_AI) LAi_tmpl_fight_SetWaitState(chr);
}

//Можно ли стрелять
bool LAi_tmpl_fight_IsFire(aref chr)
{
	return LAi_CharacterCanFire(chr);
}

//Можно ли использовать оружие
bool LAi_tmpl_fight_IsFight(aref chr)
{
	return LAi_LocationCanFight();
}


//Персонаж выполнил команду  escape
void LAi_tmpl_fight_EndEscape(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж скользит вдоль патча
void LAi_tmpl_fight_EscapeSlide(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  escape
void LAi_tmpl_fight_FailureEscape(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж толкается с другими персонажами
void LAi_tmpl_fight_ColThreshold(aref chr)
{
	if(!IMPROVE_FIGHT_AI) LAi_tmpl_fight_Stop(chr, 1.0 + rand(3));
}

//Персонаж закончил проигрывать анимацию
void LAi_tmpl_fight_EndAction(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонажа просят освободить место
void LAi_tmpl_fight_FreePos(aref chr, aref who)
{
}

//------------------------------------------------------------------------------------------
//Внутреннии функции
//------------------------------------------------------------------------------------------

//Перейти в режим боя и ожидать указание цели
void LAi_tmpl_fight_SetWaitState(aref chr)
{
	if(DEBUG_FIGHTING) trace("Character "+chr.id+" is now waiting");
	if(IMPROVE_FIGHT_AI) 
	{
		if(GetAttribute(chr,"chr_ai.tmpl.state") != "wait")
		{
			chr.chr_ai.tmpl.changestatetime = "0";
		}
	}
	SetCharacterTask_Stay(chr);
	chr.chr_ai.tmpl.target = "";
	chr.chr_ai.tmpl.state = "wait";
	GroupTargetSetState(chr, "wait");
}

//Атаковать цель
void LAi_tmpl_fight_SetTarget(aref chr, aref target)
{
	if(!CheckAttribute(target,"index"))
	{
		if(DEBUG_FIGHTING) trace("Target set to empty for "+chr.id);
		if(IMPROVE_FIGHT_AI && CheckAttribute(chr,"chr_ai.tmpl.target"))
		{
			if(chr.chr_ai.tmpl.target == "")
			{
				return;
			}
			else
			{
				chr.chr_ai.tmpl.target = "";
			}
		}
		else
		{
			chr.chr_ai.tmpl.target = "";
			return;
		}
	}
	else
	{
		chr.chr_ai.tmpl.target = target.index;
	}
	if(!IMPROVE_FIGHT_AI) LAi_tmpl_fight_FightGo(chr);
	if(LAi_IsInitedAI)
	{
		SetCharacterTask_Fight(chr, target);
		if(iRealismMode>0 || SHORE_DANGER_ALARM){Characters[GetMainCharacterIndex()].doalarm = true;} // Screwface
		if(IsMainCharacter(target)) ResetTimeToNormal(); // PB: Slow down game to normal speed when enemies draw their blade
	}
	if(IMPROVE_FIGHT_AI)
	{
		if(DEBUG_FIGHTING) trace("Start SetTarget");
		//Levis Store the targets so we can see if others need help
		if(CheckAttribute(GroupTargets,"location"))
		{
			if(GroupTargets.location != loadedLocation.id)
			{
				if(DEBUG_FIGHTING) trace("New Location, clear old data");
				//We apparently moved to a new location so let's clean it up.
				for(int i = 0; i < GetAttributesNum(GroupTargets); i++)
				{
					DeleteAttribute(&GroupTargets,GetAttributeName(GetAttributeN(GroupTargets, i)));
					i--;
				}
				GroupTargets.location = loadedLocation.id;
			}
		}
		else
		{
			GroupTargets.location = loadedLocation.id;
		}
		//Set the target in the grouptargets
		string aigroup = chr.chr_ai.group;
		string chrindx = chr.index;
		if(CheckAttribute(target,"index"))
		{
			string targetidx = target.index;
			if(CheckAttribute(GroupTargets,aigroup+".targets."+targetidx))
			{
				if(DEBUG_FIGHTING) trace("Increase target "+targetidx);
				GroupTargets.(aigroup).targets.(targetidx) = sti(GroupTargets.(aigroup).targets.(targetidx)) + 1;
			}
			else
			{
				if(DEBUG_FIGHTING) trace("Set target "+targetidx);
				GroupTargets.(aigroup).targets.(targetidx) = 1;
			}
		}
		//Check if this member had a previous target if so remove one from the group targets
		if(CheckAttribute(GroupTargets,aigroup+".members."+chrindx))
		{
			string oldtargetidx = GroupTargets.(aigroup).members.(chrindx)
			if(CheckAttribute(GroupTargets,aigroup+".targets."+oldtargetidx))
			{
				if(DEBUG_FIGHTING) trace("Reduce target "+oldtargetidx);
				GroupTargets.(aigroup).targets.(oldtargetidx) = sti(GroupTargets.(aigroup).targets.(oldtargetidx)) - 1;
				if(sti(GroupTargets.(aigroup).targets.(oldtargetidx)) < 1)
				{
					if(DEBUG_FIGHTING) trace("Delete target "+oldtargetidx);
					DeleteAttribute(&GroupTargets,aigroup+".targets."+oldtargetidx);
				}
			}
		}
		//Update new target
		if(CheckAttribute(target,"index"))
		{
			GroupTargets.(aigroup).members.(chrindx) = targetidx;
		}
		else
		{
			GroupTargets.(aigroup).members.(chrindx) = -1;
		}
	}
}

//Получить цель
int LAi_tmpl_fight_GetTarget(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.target")) return -1;
	if(chr.chr_ai.tmpl.target == "") return -1;
	return sti(chr.chr_ai.tmpl.target);
}

void LAi_tmpl_fight_Stop(aref chr, float stopTime)
{
	if(stf(chr.chr_ai.tmpl.nostop) > 0.0) return;
	if(chr.chr_ai.tmpl.state != "go") return;
	if(stopTime <= 0) return;
	if(chr.chr_ai.tmpl.target == "") return;
	//Определяем в близи наличие врагов
	if(LAi_tmpl_fight_CheckEnemy(chr)) return;
	//Оставим в режиме боя
	SetCharacterTask_Stay(chr);
	chr.chr_ai.tmpl.state = "stop";
	GroupTargetSetState(chr, "stop");
	chr.chr_ai.tmpl.time = stopTime;
	chr.chr_ai.tmpl.nostop = 5 + rand(10);
}

void LAi_tmpl_fight_StopRestore(aref chr)
{
	LAi_tmpl_fight_FightGo(chr);
	int idx = sti(chr.chr_ai.tmpl.target);
	LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
}

void LAi_tmpl_fight_updatetemplate(aref chr)
{
	if(!IMPROVE_FIGHT_AI)
	{
		if(chr.chr_ai.tmpl.state == "wait")
		{
			LAi_tmpl_fight_SetWaitState(chr);
		}else{
			int idx = sti(chr.chr_ai.tmpl.target);
			LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
		}
	}
}

bool LAi_tmpl_fight_CheckEnemy(aref chr)
{
	int num = FindNearCharacters(chr, 4.5, -1.0, -1.0, 0.001, false, false); //Expanded Radius A little bit
	if(num <= 0) return false;
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return true;
	}
	return false;
}

int LAi_tmpl_fight_NearestEnemy(aref chr, int radius)
{
	int num = FindNearCharacters(chr, radius, -1.0, -1.0, 0.001, false, false); //Expanded Radius A little bit
	if(num <= 0) return false;
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return idx;
	}
	return -1;
}

int LAi_tmpl_fight_SetBestTarget(aref chr)
{
	//First we check if a team member is in need of assistance
	string aigroup = chr.chr_ai.group;
	aref Allies: makearef(Allies,GroupTargets.(aigroup).members);
	int aidx = -1;
	string targetidx = -1;
	int bestidx = -1;
	float lowest = 99999;
	for(int i = 0; i < GetAttributesNum(Allies); i++)
	{
		aidx = sti(GetAttributeName(GetAttributeN(Allies, i)));
		//Check if the ally is in need of help
		if(LAi_IsDead(&characters[aidx]))
		{
			//remove the character from the group
			targetidx = GetAttributeValue(GetAttributeN(Allies, i));
			if(DEBUG_FIGHTING) trace("Reduce target (by dead) "+targetidx);
			GroupTargets.(aigroup).targets.(targetidx) = sti(GroupTargets.(aigroup).targets.(targetidx)) - 1;
			if(sti(GroupTargets.(aigroup).targets.(targetidx)) < 1)
			{
				if(DEBUG_FIGHTING) trace("Delete target (by dead) "+targetidx);
				DeleteAttribute(&GroupTargets,aigroup+".targets."+targetidx);
			}
			targetidx = aidx;
			DeleteAttribute(&GroupTargets,aigroup+".members."+targetidx);
			continue;
		}
		float hp = LAi_GetCharacterRelHP(&characters[aidx]);
		if(hp < hppercantagehelp)
		{
			targetidx = GetAttributeValue(GetAttributeN(Allies, i));
			//Check if enough people are helping already
			if(sti(GetAttribute(GroupTargets,aigroup+".targets."+targetidx)) < 3)
			{
				//If so we only want the one with the lowest hp
				if(hp < lowest)
				{
					lowest = hp;
					bestidx = GroupTargets;
				}
			}
		}
		if(aigroup == "player" && !IsMainCharacter(chr)) //Check if we are checking for maincharacter else we will end up in an infinite loop
		{
			//Check for officers to see if they need to help the player
			if(LAi_GetCharacterRelHP(GetMainCharacter()) < hppercantagehelp)
			{
				if(DEBUG_FIGHTING) trace("HELP MAIN CHARACTER");
				//We call this function again but for the main player, this way we'll get a nice check
				return LAi_tmpl_fight_SetBestTarget(GetMainCharacter());
			}
			
		}
	}
	if(bestidx >= 0)
	{
		return bestidx;
	}
	//We'll always go after the lowest HP enemy first but if he is poisoned we should first attack someone else because he is less of a threat
	//Also we first want to attack characters which can fire because they are more dangerous then characters which can't
	int num = FindNearCharacters(chr, checkdistance, -1.0, -1.0, 0.001, false, true);
	if(num <= 0) return -1;
	lowest = 99999;
	int lowestidx = -1;
	int lonelyidx = -1;
	int neadidx = -1;
	bestidx = -1;
	int firstenemy = -1;
	for(i = 0; i < num; i++)
	{
		neadidx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[neadidx]))
		{
			if(firstenemy < 0) firstenemy = neadidx; //Incase the best enemy doesn't exist we take the closest one
			if(sti(GetAttribute(GroupTargets,aigroup+".targets."+neadidx))<3)
			{
				if(lonelyidx < 0) lonelyidx = neadidx; //We want to store the closest with not enough help because its better then the closest in general
				if(lowest > LAi_GetCharacterHP(chr))
				{
					//Check how many allies are attacking this target
					lowest = LAi_GetCharacterHP(chr);
					lowestidx = neadidx;
					if(!LAi_IsPoison(chr) && LAi_CharacterCanFire(chr)) //We first check if the character is lowest, if so we check if its best too. If not we reset the best character because its no longer the best
					{
						bestidx = neadidx;
					}
					else
					{
						bestidx = -1;
					}
				}
			}
			
		}
	}
	//First check for best
	if(bestidx >= 0)
	{
		return bestidx;
	}
	//Else check for lowest
	if(lowestidx >= 0)
	{
		return lowestidx;
	}
	//Else closest without help
	if(lowestidx >= 0)
	{
		return lonelyidx;
	}
	//Else check for closest
	if(firstenemy >=0)
	{
		return firstenemy;
	}
	//if all fails we check if we are in the player group and if so we check for the main character instead
	if(aigroup == "player" && !IsMainCharacter(chr))
	{
		return LAi_tmpl_fight_SetBestTarget(GetMainCharacter());
	}
	return -1;
}

int FindSwitchInPartner(ref chr)
{
	string aigroup = chr.chr_ai.group;
	aref Allies2: makearef(Allies2,GroupTargets.(aigroup).members);
	int aidx = -1;
	int lowidx = -1;
	int lowhpidx = -1;
	float lowhp = 1;
	float closest = 99999;
	float cx,cy,cz,tx,ty,tz;
	for(int i = 0; i < GetAttributesNum(Allies2); i++)
	{
		aidx = sti(GetAttributeName(GetAttributeN(Allies2, i)));
		ref ally = &characters[aidx];
		//Do not switch with a supporting character
		if(!CheckAttribute(ally,"chr_ai.tmpl.state")) ally.chr_ai.tmpl.state = "wait";
		if(ally.chr_ai.tmpl.state != "support")
		{
			//Let's check if the character is at least a bit damaged else we don't need to switch in yet
			if(LAi_GetCharacterHP(&characters[aidx]) < 0.6)
			{
				//Found an ally now let's see if he is usefull
				if(CanReloadGun(ally))
				{
					//A character must have lost at least half it's hp to become interested to switch
					//Now let's see who is the closest
					GetCharacterPos(chr, &cx, &cy, &cz);
					GetCharacterPos(ally, &tx, &ty, &tz);
					float dist = GetDistance2D(cx, cz, tx, tz);
					if(closest > dist)
					{
						lowidx = aidx;
						closest = dist;
					}
				}
				else
				{
					if(LAi_GetCharacterHP(ally) < LAi_GetCharacterHP(chr))
					{
						//Our HP is higher so might be wise to switch in so the other person can still recover
						if(LAi_GetCharacterHP(ally) < lowhp)
						{
							lowhp = LAi_GetCharacterHP(ally);
							lowhpidx = aidx;
						}
					}
				}
			}
		}
	}
	if(lowidx > 0) //We don't switch with the mainchar
	{
		return lowidx;
	}
	if(lowhpidx > 0) //We don't switch with the mainchar
	{
		return lowhpidx;
	}
	return -1;
}

void GroupTargetSetState(ref chr, string state)
{
	string aigroup = chr.chr_ai.group;
	string index = chr.index;
	GroupTargets.(aigroup).members.(index).state = state;
}

bool EnoughFightersInGroup(ref chr)
{
	
}