/*
Тип: воин, бьёт врагов, когда свободен, возвращается к лидеру или стоит

	Используемые шаблоны:
		fight
		follow
		walk
		stay
		dialog
*/



#define LAI_TYPE_WARRIOR	"warrior"



//Установить войну командира
void LAi_warrior_SetCommander(aref chr, aref commander)
{
	chr.chr_ai.type.index = commander.index;
}

//Разрешить или запретить диалоги для война
void LAi_warrior_DialogEnable(aref chr, bool isEnable)
{
	chr.chr_ai.type.dialog = isEnable;
}

//Сказать войну стоять при отсутствие целей
void LAi_warrior_SetStay(aref chr, bool isStay)
{
	chr.chr_ai.type.stay = isStay;
}

//Инициализация
void LAi_type_warrior_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	bool isNew = false;
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		isNew = true;
	}else{
		if(chr.chr_ai.type != LAI_TYPE_WARRIOR) isNew = true;
	}
	if(isNew == true)
	{
		//Новый тип
		DeleteAttribute(chr, "chr_ai.type");
		chr.chr_ai.type = LAI_TYPE_WARRIOR;
		chr.chr_ai.type.stay = "0";
		chr.chr_ai.type.index = "";
		chr.chr_ai.type.dialog = "0";
		LAi_tmpl_stay_InitTemplate(chr);
	}else{
		if(!CheckAttribute(chr, "chr_ai.type.stay")) chr.chr_ai.type.stay = "0";
		if(!CheckAttribute(chr, "chr_ai.type.index")) chr.chr_ai.type.index = "";
		if(!CheckAttribute(chr, "chr_ai.type.dialog")) chr.chr_ai.type.dialog = "0";
	}
	//Установим анимацию персонажу
	LAi_SetDefaultStayAnimation(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}

//Процессирование типа персонажа
void LAi_type_warrior_CharacterUpdate(aref chr, float dltTime)
{
	int trg = -1;
	//Ссылка на ветку с параметрами
	aref type;
	makearef(type, chr.chr_ai.type);
	// ccc special weapons, rearm disarmed chr. NK 05-07-01 fix chars who do not draw blade
	if(GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE)=="" && FindCharacterItemByGroup(chr, BLADE_ITEM_TYPE) != "")
	{
		EquipCharacterByItem(chr, FindCharacterItemByGroup(chr, BLADE_ITEM_TYPE))
	}
	// ccc end
	//Анализируем состояние
	string btl = "";
	float dhlt;
	if(chr.chr_ai.tmpl == LAI_TMPL_FIGHT)
	{
		//Воюем
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
		if(!isValidate)
		{
			//Ищем новую цель
			trg = LAi_group_GetTarget(chr);
			if(trg < 0)
			{
				//Переходим в режим ожидания
				LAi_tmpl_stay_InitTemplate(chr);
				LAi_type_warrior_SetWateState(chr);
			}else{
				//Натравливаем на новую цель
				LAi_tmpl_SetFight(chr, &Characters[trg]);
				if(rand(100) < 20)
				{
					LAi_type_warrior_PlaySound(chr);
				}
			}
		}
		//Levis:
		if(CheckCharacterItem(chr,"vegetal"))
		{
			if(sti(GetAttribute(chr,"quest.vegetal_effect.active")) < 1)
			{
				if(FindNearEnemies(chr, 5, true) > 3)
				{
					UseVegetal(chr);
				}
			}
			if(sti(GetAttribute(chr,"quest.vegetal_effect.active")) > 1)
			{
				if(FindNearEnemies(chr, 5, true) > 6)
				{
					UseVegetal(chr);
				}
			}
		}
		//Levis: potions
		if(!LAi_IsBottleWork(chr))
		{
			if(LAi_GetCharacterRelHP(chr) < 0.6)
			{
				dhlt = LAi_GetCharacterMaxHP(chr) - LAi_GetCharacterHP(chr);
				btl = FindHealthForCharacter(&Characters[sti(chr.index)], dhlt);
				DoCharacterUsedItem(&Characters[sti(chr.index)], btl);
			}
		}
	}else{
		//Ищем новую цель
		trg = LAi_group_GetTarget(chr);
		if(trg >= 0)
		{
			//Нападаем на новую цель
			LAi_tmpl_SetFight(chr, &Characters[trg]);
			if(rand(100) < 70)
			{
				LAi_type_warrior_PlaySound(chr);
			}
		}else{
			if(chr.chr_ai.tmpl == LAI_TMPL_STAY)
			{
				//Стоим и ждём цели
				LAi_type_warrior_SetWateState(chr);
			}

		}
	}
	//Levis: antidote
	if(CheckAttribute(chr, "chr_ai.poison"))
	{
		if(LAi_GetCharacterRelHP(chr) < 0.8)
		{
			//Levis:
			btl = FindAntidoteForCharacter(chr);
			DoCharacterUsedItem(&Characters[sti(chr.index)], btl);
		}
	}
}

//Загрузка персонажа в локацию
bool LAi_type_warrior_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_warrior_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_warrior_TemplateComplite(aref chr, string tmpl)
{
}

//Сообщить о желании завести диалог
void LAi_type_warrior_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_warrior_CanDialog(aref chr, aref by)
{	
	if(sti(chr.chr_ai.type.dialog) == 0) return false;
	//Если просто стоим, то согласимся
	if(chr.chr_ai.tmpl == LAI_TMPL_STAY) return true;
	if(chr.chr_ai.tmpl == LAI_TMPL_FOLLOW) return true;
	if(chr.chr_ai.tmpl == LAI_TMPL_WALK) return true;
	return false;
}

//Начать диалог
void LAi_type_warrior_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	LAi_CharacterSaveAy(chr);
	CharacterTurnByChr(chr, by);
	LAi_tmpl_SetActivatedDialog(chr, by);
}

//Закончить диалог
void LAi_type_warrior_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_CharacterRestoreAy(chr);
}

//Персонаж атаковал другого персонажа
void LAi_type_warrior_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	
}

//Персонаж атоковал заблокировавшегося персонажа
void LAi_type_warrior_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	
}

//Персонаж выстрелил
void LAi_type_warrior_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{

}


//Персонаж атакован
void LAi_type_warrior_Attacked(aref chr, aref by)
{
	//Своих пропускаем
//Log_SetStringToLog("LAi_type_warrior_Attacked "+chr.id + " "+by.id);
	if(!LAi_group_IsEnemy(chr, by)) return;
	LAi_group_UpdateTargets(chr);
// boal -->
/*	bool isChangeTarget = false;
	if(chr.chr_ai.tmpl == LAI_TMPL_FIGHT)
	{
		if(LAi_tmpl_fight_NoActive(chr))
		{
			isChangeTarget = true;
		}
	}else{
		isChangeTarget = true;
	}
	if(isChangeTarget)
	{
		//Меняем цель
		LAi_tmpl_SetFight(chr, by);*/
//boal fix ai -->
    float dist = -1.0;
	
	if(!GetCharacterDistByChr3D(chr, by, &dist)) return;
	if(dist < 0.0) return;
	if(dist > 20.0) return;
	//Натравливаем
	//LAi_tmpl_SetFight(chr, by); // TIH moved down below after sound check
    // boal <--
    // TIH reduced this repetitive sound by only doing it on change of target and less percent - Aug29'06
    if ( LAi_tmpl_fight_GetTarget(chr) != sti(by.index) ) {
		if(rand(100) < 40)
		{
			LAi_type_warrior_PlaySound(chr);
		}
	}
	LAi_tmpl_SetFight(chr, by);// TIH moved down here from above, so its set after sound - Aug29'06
//	}
}

//Переходим в режим ожидания
void LAi_type_warrior_SetWateState(aref chr)
{
	if(sti(chr.chr_ai.type.stay) == 0)
	{
		if(chr.chr_ai.type.index != "")
		{
			int cmd = sti(chr.chr_ai.type.index);
			if(cmd >= 0)
			{
				//Возвращаемся к командиру
				LAi_tmpl_SetFollow(chr, &Characters[cmd], -1.0);
			}else{
				//Гуляем в поисках цели
				LAi_tmpl_walk_InitTemplate(chr);
			}
		}else{
			//Гуляем в поисках цели
			LAi_tmpl_walk_InitTemplate(chr);
		}
	}else{
		//Ожидаем цель стоя на месте
		if(chr.chr_ai.tmpl != LAI_TMPL_STAY)
		{
			LAi_tmpl_stay_InitTemplate(chr);
		}
	}
}

void LAi_type_warrior_PlaySound(aref chr)
{
	if(LAi_IsDead(chr)) return;
	string sname = "";
	if(CheckAttribute(chr, "sex"))
	{
		switch(chr.sex)
		{
		case "man":
			switch(makeint(chr.nation))
			{
				case 0 : sname = "warrior_eng";break;				// english
				case 1 : sname = "warrior_fra";break;				// french
				case 2 : sname = "warrior_spa";break;				// spanish
				case 3 : sname = "warrior_pir";break;				// pirates
				case 4 : sname = "warrior_dut";break;				// dutch
				case 5 : sname = "warrior";break;					// portuguese
			}
			break;
		case "woman":
			sname = "shi_warrior";//MAXIMUS
			break;
		case "skeleton":
			sname = "skeleton";
			break;
		}
	}
	if(sname == "") return;
	LAi_CharacterPlaySound(chr, sname);
}
