

#define LAI_TMPL_DIALOG		"dialog"

/*
	Возможные состояния:
		"wait"		ждёт начала диалога
		"dialog"	разговаривает
*/


bool LAi_tmpl_SetDialog(aref chr, aref by, float dlgTime)
{
	if(!LAi_tmpl_dialog_InitTemplate(chr)) return false;
	chr.chr_ai.tmpl.dialog = "";
	chr.chr_ai.tmpl.time = "0";
	chr.chr_ai.tmpl.dlgtime = "-1";	
	chr.chr_ai.tmpl.state = "wait";
	LAi_tmpl_dialog_StartDialog(chr, by, dlgTime);
	return true;
}

//Если мы пасивны, запускаем шаблон без времени завершения
bool LAi_tmpl_SetActivatedDialog(aref chr, aref by)
{
	if(!LAi_tmpl_dialog_InitTemplate(chr)) return false;
	chr.chr_ai.tmpl.dialog = by.index;
	chr.chr_ai.tmpl.time = "0";
	chr.chr_ai.tmpl.dlgtime = "-1";	
	chr.chr_ai.tmpl.state = "dialog";
	LAi_tmpl_dialog_CharacterUpdate(chr, 0.0);
	return true;
}

void LAi_tmpl_dialog_NoAni(aref chr)
{
	chr.chr_ai.tmpl.noani = "1";
}

//Остановить диалог между NPC
bool LAi_tmpl_dialog_StopNPC(aref chr)
{
	if(chr.chr_ai.tmpl.state == "dialog")
	{
		//Если один из беседующих игрок, то не прекращаем диалог
		int idx = sti(chr.chr_ai.tmpl.dialog);
		if(GetMainCharacterIndex() == sti(chr.index)) return false;
		if(GetMainCharacterIndex() == idx) return false;
		//Операнивно всё сворачиваем
		CharacterPlayAction(chr, "");
		CharacterPlayAction(&Characters[idx], "");
		LAi_Character_EndDialog(chr, &Characters[idx]);
		LAi_Character_EndDialog(&Characters[idx], chr);
		chr.chr_ai.tmpl.dialog = "";
		chr.chr_ai.tmpl.time = "0";
		chr.chr_ai.tmpl.dlgtime = "-1";	
		chr.chr_ai.tmpl.state = "wait";
	}
	return true;
}


bool LAi_tmpl_dialog_InitTemplate(aref chr)
{
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "LockFightMode", false);
	CharacterPlayAction(chr, "");
	bool isNew = false;
	if(CheckAttribute(chr, "chr_ai.tmpl"))
	{
		if(chr.chr_ai.tmpl != LAI_TMPL_DIALOG) isNew = true;
	}else{
		isNew = true;
	}
	if(isNew)
	{
		DeleteAttribute(chr, "chr_ai.tmpl");
		chr.chr_ai.tmpl = LAI_TMPL_DIALOG;
		chr.chr_ai.tmpl.state = "wait";
		chr.chr_ai.tmpl.dialog = "";
		chr.chr_ai.tmpl.time = "0";
		chr.chr_ai.tmpl.dlgtime = "-1";
		if(LAi_IsInitedAI) SetCharacterTask_Stay(chr);
	}else{
		chr.chr_ai.tmpl.wait = "0";
		if(!CheckAttribute(chr, "chr_ai.tmpl.state")) chr.chr_ai.tmpl.state = "wait";
		if(chr.chr_ai.tmpl.state == "falure") chr.chr_ai.tmpl.state = "wait";
		if(!CheckAttribute(chr, "chr_ai.tmpl.time")) chr.chr_ai.tmpl.time = "0";
		if(!CheckAttribute(chr, "chr_ai.tmpl.dlgtime")) chr.chr_ai.tmpl.dlgtime = "-1";		
		if(!CheckAttribute(chr, "chr_ai.tmpl.dialog"))
		{
			chr.chr_ai.tmpl.dialog = "";
			chr.chr_ai.tmpl.state = "wait";
		}else{
			if(chr.chr_ai.tmpl.dialog == "") chr.chr_ai.tmpl.state = "wait";
		}
		if(chr.chr_ai.tmpl.state == "wait")
		{
			chr.chr_ai.tmpl.dialog = "";
			chr.chr_ai.tmpl.time = "0";
			chr.chr_ai.tmpl.dlgtime = "-1";
		}
		if(LAi_IsInitedAI) LAi_tmpl_dialog_CharacterUpdate(chr, 0.0);
	}
	chr.chr_ai.tmpl.phrasetime = rand(5);
	return true;
}

//Возможно ли завенсти диалог
bool LAi_tmpl_dialog_IsActive(aref chr)
{
	if(chr.chr_ai.tmpl.state == "wait") return false;
	return true;
}


//Процессирование шаблона персонажа
void LAi_tmpl_dialog_CharacterUpdate(aref chr, float dltTime)
{
	float time;
	aref tmpl;
	makearef(tmpl, chr.chr_ai.tmpl);
	//Всегда стоим
	SetCharacterTask_Stay(chr);
	//Если в диалоге, направляемся на персонажа
	if(tmpl.state == "dialog")
	{
		//Проверяем время ведения диолога
		float dlgtime = stf(tmpl.dlgtime);
		if(dlgtime >= 0)
		{
			//Мы ведём диалог
			time = stf(tmpl.time) + dltTime;
			tmpl.time = time;
			if(time > dlgtime)
			{
				int idx = sti(chr.chr_ai.tmpl.dialog);
				CharacterPlayAction(chr, "");
				// NK for index of -1, i.e. citizen wait for pchar to start dlg 05-07-17
				if(idx != -1) CharacterPlayAction(&Characters[idx], "");
				if(idx != -1) LAi_Character_EndDialog(chr, &Characters[idx]);
				if(idx != -1) LAi_Character_EndDialog(&Characters[idx], chr);
				else LAi_Character_EndDialog(NullCharacter, chr);
				// NK <--
				chr.chr_ai.tmpl.dialog = "";
				chr.chr_ai.tmpl.time = "0";
				chr.chr_ai.tmpl.dlgtime = "-1";	
				chr.chr_ai.tmpl.state = "wait";
				return;
			}
		}
	}
	//Выкидываем всякие жесты и фразочки
	time = stf(chr.chr_ai.tmpl.phrasetime) - dltTime;
	if(time < 0.0)
	{
		if(!CheckAttribute(chr, "chr_ai.tmpl.noani"))
		{
			if(rand(100) < 80)
			{
				switch(rand(3))
				{
				case 0:
					CharacterPlayAction(chr, "dialog_stay2");
					break;
				case 1:
					CharacterPlayAction(chr, "dialog_stay3");
					break;
				case 2:
					CharacterPlayAction(chr, "dialog_stay4");
					break;
				case 3:
					CharacterPlayAction(chr, "dialog_stay5");
					break;
				};
			}
		}
		if(stf(tmpl.dlgtime) >= 0.0)
		{
			string snd = "male-citizen";
			if(CheckAttribute(chr,"sex"))
			{
				if(chr.sex == "woman")
				{
					snd = "female-citizen";
				}
			}
			LAi_CharacterPlaySound(chr, snd);
		}
		chr.chr_ai.tmpl.phrasetime = 5 + rand(5);
	}else{
		chr.chr_ai.tmpl.phrasetime = time;
	}
}

//Персонаж выполнил команду  go to point
void LAi_tmpl_dialog_EndGoToPoint(aref chr)
{
}

//Персонаж провалил команду  go to point
void LAi_tmpl_dialog_FailureGoToPoint(aref chr)
{
}

//Персонаж выполнил команду  run to point
void LAi_tmpl_dialog_EndRunToPoint(aref chr)
{	
}

//Персонаж провалил команду  run to point
void LAi_tmpl_dialog_FailureRunToPoint(aref chr)
{	
}

//Персонаж не может добраться до точки назначения
void LAi_tmpl_dialog_BusyPos(aref chr, float x, float y, float z)
{
}

//Персонаж начал перемещение за другим
void LAi_tmpl_dialog_FollowGo(aref chr)
{
}

//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_dialog_FollowStay(aref chr)
{	
}

//Персонаж провалил команду  dialog character
void LAi_tmpl_dialog_FailureFollow(aref chr)
{	
}


//Персонаж начал перемещение за другим
void LAi_tmpl_dialog_FightGo(aref chr)
{
}

//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_dialog_FightStay(aref chr)
{
}

//Персонаж провалил команду  Fight
void LAi_tmpl_dialog_FailureFight(aref chr)
{
}

//Можно ли стрелять
bool LAi_tmpl_dialog_IsFire(aref chr)
{	
	return false;
}

//Можно ли использовать оружие
bool LAi_tmpl_dialog_IsFight(aref chr)
{
	return false;
}


//Персонаж выполнил команду  escape
void LAi_tmpl_dialog_EndEscape(aref chr)
{
}

//Персонаж скользит вдоль патча
void LAi_tmpl_dialog_EscapeSlide(aref chr)
{
}

//Персонаж провалил команду  escape
void LAi_tmpl_dialog_FailureEscape(aref chr)
{
}


//Персонаж толкается с другими персонажами
void LAi_tmpl_dialog_ColThreshold(aref chr)
{
}

//Персонаж закончил проигрывать анимацию
void LAi_tmpl_dialog_EndAction(aref chr)
{
	CharacterPlayAction(chr, "");
}


//Персонажа просят освободить место
void LAi_tmpl_dialog_FreePos(aref chr, aref who)
{
}

//------------------------------------------------------------------------------------------
//Внутреннии функции
//------------------------------------------------------------------------------------------

void LAi_tmpl_dialog_updatetemplate(aref chr)
{
	if(chr.chr_ai.tmpl.state == "dialog")
	{
		SetCharacterTask_Stay(chr);
	}else{
		chr.chr_ai.tmpl.state = "wait";
		SetCharacterTask_Stay(chr);
	}
}

void LAi_tmpl_dialog_StartDialog(aref chr, aref by, float dlgTime)
{
	//Заполняем поля
	chr.chr_ai.tmpl.dialog = by.index;
	chr.chr_ai.tmpl.state = "wait";
	chr.chr_ai.tmpl.dtime = "0";
	chr.chr_ai.tmpl.dlgtime = dlgTime;
	//Запускаем диалог
	int idx = sti(chr.chr_ai.tmpl.dialog);
	int my = sti(chr.index);
	if(idx == my)
	{
		//Не говорим сами с собой
		Trace("Template dialog: can't start dialog with myself!");
		chr.chr_ai.tmpl.dlgtime = "0";
	}
	if(!IsEntity(&Characters[idx]))
	{
		//Не говорим с несущиствующим персонажем
		Trace("Template dialog: can't start dialog with unloaded character!");
		chr.chr_ai.tmpl.dlgtime = "0";
	}	
	int mainChr = GetMainCharacterIndex();
	if(mainChr == idx)
	{
		//Диалог с главным персонажем
		chr.chr_ai.tmpl.dlgtime = "-1";
		if(!DialogMain(&Characters[my]))
		{
			Trace("Template dialog: can't start dialog, DialogMain return false!");
			chr.chr_ai.tmpl.dlgtime = "0";
		}
	}else{
		if(mainChr == my)
		{
			//Диалог с главным персонажем
			chr.chr_ai.tmpl.dlgtime = "-1";
			if(!DialogMain(&Characters[idx]))
			{
				Trace("Template dialog: can't start dialog, DialogMain return false!");
				chr.chr_ai.tmpl.dlgtime = "0";
			}			
		}else{
			//Диалог между NPC
			if(dlgTime < 0) dlgTime = 0;
			LAi_Character_StartDialog(&Characters[my], &Characters[idx]);
			LAi_Character_StartDialog(&Characters[idx], &Characters[my]);
			chr.chr_ai.tmpl.dlgtime = dlgTime;
		}
	}
	chr.chr_ai.tmpl.state = "dialog";
	LAi_tmpl_dialog_CharacterUpdate(chr, 0.0);
}

