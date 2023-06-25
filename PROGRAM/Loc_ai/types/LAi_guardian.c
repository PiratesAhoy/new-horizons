/*
Тип: охраник

	Используемые шаблоны:
		stay
		talk
		fight		
		goto
*/



#define LAI_TYPE_GUARDIAN	"guardian"


//Инициализация
void LAi_type_guardian_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	bool isNew = false;
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		isNew = true;
	}else{
		if(chr.chr_ai.type != LAI_TYPE_GUARDIAN) isNew = true;
	}
	if(isNew == true)
	{
		//Новый тип
		DeleteAttribute(chr, "chr_ai.type");
		chr.chr_ai.type = LAI_TYPE_GUARDIAN;
		chr.chr_ai.type.enemy = "";
		chr.chr_ai.type.etime = "0";
		chr.chr_ai.type.wait = "";
		//Установим шаблон стояния
		LAi_tmpl_stay_InitTemplate(chr);
	}else{
		//Востанавливаем состояние
		if(chr.chr_ai.type.wait == "attack")
		{
			LAi_type_guardian_CmdAttack(chr);
		}else{
			if(chr.chr_ai.type.wait == "return")
			{
				LAi_type_guardian_Return(chr);
			}
		}
	}
	//Установим анимацию персонажу
	LAi_SetDefaultStayAnimation(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
	//Сохраним адрес как точку охраны
	chr.chr_ai.type.group = chr.location.group;
	chr.chr_ai.type.locator = chr.location.locator;
}

//Процессирование типа персонажа
void LAi_type_guardian_CharacterUpdate(aref chr, float dltTime)
{
	/* - Section commented out until properly working
	// ccc sneak mod ->
	// int watch = rand (12) + 4;		// ccc sneak mod guard reduction
	// LAi_SetLoginTime(chr, watch, watch +6 );	// guards appear for 6h shifts
	chr.patroltype = true;
	chr.dialog.filename = "patrol_dialog.c"; 
	LAi_type_patrol_Init(chr);	// ccc sneak mod  to get them moving


	// ccc sneak mod  whole section disabled as guardian is patrol now
	*/
	aref type;
	int trg, t;
	float time, dist;
//Log_SetStringToLog("LAi_type_guardian_CharacterUpdate "+chr.id ); //boal
	makearef(type, chr.chr_ai.type);
	//Режим ожидания
	if(type.wait != "") return;
	//Нормальная работа
	string tmpl = chr.chr_ai.tmpl;
	if(tmpl == LAI_TMPL_DIALOG) return;
	if(tmpl == LAI_TMPL_FIGHT)
	{
		bool isValidate = false;
		trg = LAi_tmpl_fight_GetTarget(chr);
		if(trg >= 0)
		{
			if(LAi_group_ValidateTarget(chr, &Characters[trg]))
			{
				if(!LAi_tmpl_fight_LostTarget(chr))
				{
					isValidate = true;
				}
			}
		}
		//Пробуем обновить оптимальную цель
		time = stf(type.etime) - dltTime;
		if(time <= 0.0)
		{
			type.etime = 0.0;
			t = LAi_group_GetTarget(chr);
			if(t != trg) 
				isValidate = false;
		}else{
			type.etime = time;
		}
		//Если текущая цель не действительна, получим новую
		if(!isValidate)
		{
			//Ищем новую цель
			trg = LAi_group_GetTarget(chr);
			if(trg < 0)
			{
				//Переходим в режим ожидания
				LAi_tmpl_fight_SetWaitState(chr);
				LAi_type_guardian_Return(chr);
			}else{
				//Натравливаем на новую цель
				LAi_type_guardian_CmdAttack_Now(chr, trg);
				if(rand(100) < 20)
				{
					LAi_CharacterPlaySound(chr, "warrior");
				}
			}
		}
	}else{
		if(tmpl == LAI_TMPL_STAY)
		{
			if(rand(1000) == 125)
			{
				LAi_CharacterPlaySound(chr, "guardian");
			}
			//Проверим наличие врагов
			trg = LAi_group_GetTarget(chr);
			if(trg >= 0)
			{
				chr.chr_ai.type.enemy = trg;
				LAi_type_guardian_CmdAttack(chr);
			}else{
				//Проверяем дистанцию до точки охраны
				dist = -1.0;
				if(GetCharacterDistByLoc(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator, &dist))
				{
					if(dist > 1.0)
					{
						LAi_tmpl_runto_InitTemplate(chr);
						LAi_tmpl_runto_SetLocator(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator, -1.0);
					}else{
						CharacterTurnByLoc(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator);
					}
				}else{
					CharacterTurnByLoc(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator);
				}
			}
		}else{
			//Проверим наличие врагов
			trg = LAi_group_GetTarget(chr);
			if(trg >= 0)
			{
				chr.chr_ai.type.enemy = trg;
				LAi_type_guardian_CmdAttack(chr);
			}else{
				if(tmpl != LAI_TMPL_RUNTO)
				{
					LAi_tmpl_stay_InitTemplate(chr);
				}else{
					if(LAi_tmpl_runto_IsStay(chr))
					{
						LAi_tmpl_stay_InitTemplate(chr);
					}
				}
			}
		}
	}
}

//Загрузка персонажа в локацию
bool LAi_type_guardian_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_guardian_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_guardian_TemplateComplite(aref chr, string tmpl)
{
	LAi_tmpl_stay_InitTemplate(chr);
	CharacterTurnByLoc(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator);
}


//Сообщить о желании завести диалог
void LAi_type_guardian_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_guardian_CanDialog(aref chr, aref by)
{
	//Если просто стоим, то согласимся на диалог
	if(chr.chr_ai.tmpl == LAI_TMPL_STAY)
	{
		if(LAi_CanNearEnemy(chr, 5.0)) return false;
		return true;
	}
	if(sti(by.index) == GetMainCharacterIndex())
	{
		if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG)
		{
			if(LAi_tmpl_dialog_StopNPC(chr)) return true;
		}
	}
	return false;
}

//Начать диалог
void LAi_type_guardian_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	LAi_CharacterSaveAy(chr);
	CharacterTurnByChr(chr, by);
	LAi_tmpl_SetActivatedDialog(chr, by);
}

//Закончить диалог
void LAi_type_guardian_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_CharacterRestoreAy(chr);
}

//Персонаж атаковал другого персонажа
void LAi_type_guardian_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	
}

//Персонаж атоковал заблокировавшегося персонажа
void LAi_type_guardian_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{

}

//Персонаж выстрелил
void LAi_type_guardian_Fire(aref chr, aref enemy, float kDist, bool isFindedEnemy)
{

}

//Персонаж атакован
void LAi_type_guardian_Attacked(aref chr, aref by)
{
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG)
	{
		LAi_tmpl_dialog_StopNPC(chr);
	}
    //boal fix ai -->
    float dist = -1.0;
	
	if(!GetCharacterDistByChr3D(chr, by, &dist)) return;
	if(dist < 0.0) return;
	if(dist > 20.0) return;
	//Натравливаем
	LAi_tmpl_SetFight(chr, by);
    // boal <--
}


//------------------------------------------------------------------------------------------
//Внутреннии функции
//------------------------------------------------------------------------------------------

void LAi_type_guardian_CmdAttack(aref chr)
{
	chr.chr_ai.type.wait = "attack";
	PostEvent("Event_type_guardian_Attacked", rand(5)*100, "i", chr);
}

#event_handler("Event_type_guardian_Attacked", "LAi_type_guardian_CmdAttack_Event");
void LAi_type_guardian_CmdAttack_Event()
{
	aref chr = GetEventData();
	if(!TestRef(chr)) return;
	chr.chr_ai.type.wait = "";
	if(CheckAttribute(chr.chr_ai.type,"enemy"))
    {
		if(chr.chr_ai.type.enemy == "") return;
		int trg = sti(chr.chr_ai.type.enemy);
	}
	LAi_type_guardian_CmdAttack_Now(chr, trg);
}

bool LAi_type_guardian_CmdAttack_Now(aref chr, int trg)
{
	if(trg < 0)
	{
		LAi_tmpl_stay_InitTemplate(chr);
		return false;
	}
	chr.chr_ai.type.etime = 8 + rand(12);
	if(!LAi_tmpl_SetFight(chr, &Characters[trg]))
	{
		//Несмогли инициировать шаблон
		LAi_tmpl_stay_InitTemplate(chr);
		return false;
	}
	return true;
}

void LAi_type_guardian_Return(aref chr)
{
	chr.chr_ai.type.wait = "return";
	chr.chr_ai.type.enemy = "";
	PostEvent("Event_type_guardian_Return", rand(10)*100, "i", chr);
}

#event_handler("Event_type_guardian_Return", "LAi_type_guardian_Return_Event");
void LAi_type_guardian_Return_Event()
{
	aref chr = GetEventData();
	if(!TestRef(chr)) return;
	chr.chr_ai.type.wait = "";	
	chr.chr_ai.type.enemy = "";
	LAi_tmpl_runto_InitTemplate(chr);
	LAi_tmpl_runto_SetLocator(chr, chr.chr_ai.type.group, chr.chr_ai.type.locator, -1.0);
}




