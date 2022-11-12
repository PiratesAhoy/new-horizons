/*
Тип: Бедняг

	Используемые шаблоны:
		stay
		dialog
		ani
*/
// NK 05-07-10
// make a new STUNNED type for CCC's stun behavior, rather than combining with POOR.


#define LAI_TYPE_STUNNED		"stunned"
#define LAI_GROUP_STUNNED		"stunned"
#define LAI_GROUP_CORPSES		"corpses"


// NK fix this for stunning already-stunned character 05-07-12
// stun character chr for duration seconds, with the following bools.
void LAi_Stunned_StunCharacter(aref chr, float duration, bool playSFX, bool playGFX, bool resumeoldtype)
{
	// TIH no stunning settings Aug31'06
	if (CheckAttribute(chr, "nodisarm" )) return;
	if (IsMainCharacter(chr)) return;
	if (LAi_IsBoardingProcess() && CheckAttribute(chr, "chr_ai.group") && chr.chr_ai.group !=  LAI_GROUP_PLAYER) return;
	if (CheckAttribute(chr,"corpse")) return;

	if(!CheckAttribute(chr, "stuntime"))
	{
		aref achr, astun;
		chr.stuntime.old_type = chr.chr_ai.type; // save old type
		if(!CheckAttribute(chr, "first_oldtype")) chr.first_oldtype = chr.chr_ai.type; // for logoff
		if(chr.chr_ai.type == LAI_TYPE_ACTOR) // save actor properties
		{
			chr.stuntime.actor.type = "";
			makearef(astun, chr.stuntime.actor.type);
			makearef(achr, chr.chr_ai.type);
			CopyAttributes(&astun, &achr);
			
			chr.stuntime.actor.tmpl = "";
			makearef(astun, chr.stuntime.actor.tmpl);
			makearef(achr, chr.chr_ai.tmpl);
			CopyAttributes(&astun, &achr);
			if(CheckAttribute(chr, "location.follower")) // just in case follower
			{
				chr.stuntime.locfollow = chr.location.follower;
			}
		}
		if(CheckAttribute(chr,"dialog.filename")) chr.stuntime.dialog.filename = chr.dialog.filename;	// saves original dialog
		if(CheckAttribute(chr,"dialog.currentnode")) chr.stuntime.dialog.currentnode = chr.dialog.currentnode;	// TIH dont forget CURRENTNODE ! Aug31'06
		if(CheckAttribute(chr, "greeting")) chr.stuntime.greeting = chr.greeting; // NK to make a groan the greeting
		chr.dialog.filename = "stunned_dialog.c" ;	// assigns "stunned" dialog during stuntime
		LAi_SetStunnedTypeNoGroup(chr);	// makes initial target collapse or cover
		if(chr.sex == "woman")
		{
			chr.greeting = "OBJECTS\Voices\dead\female\dead_wom2.wav";
		}
		else
		{
			chr.greeting = "OBJECTS\Voices\dead\male\dead1.wav";
		}
		chr.stuntime.group = chr.chr_ai.group;
		LAi_Group_MoveCharacter(chr, LAI_GROUP_STUNNED);
		LAI_group_SetRelationWithAllStock(LAI_GROUP_STUNNED, LAI_GROUP_NEUTRAL);
	}
	chr.stuntime.duration = duration;
	chr.stuntime = locTmpTime;	// stores the time of this, for reawakening
	if(resumeoldtype)
	{
		chr.stuntime.old_type_resume = true;
	}
	else DeleteAttribute(chr, "stuntime.old_type_resume");
	
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	if(playSFX)
	{
		/*if(chr.sex == "man") {PlaySound3D("OBJECTS\Voices\dead\male\dead1.wav", x, y, z);}	// groan
		else{PlaySound3D("OBJECTS\Voices\dead\female\dead_wom2.wav", x, y, z);}*/
		/*if(chr.sex == "woman") { LAi_CharacterPlaySound(chr, "OBJECTS\Voices\dead\female\dead_wom2.wav"); }
		else { LAi_CharacterPlaySound(chr, "OBJECTS\Voices\dead\male\dead1.wav"); }*/
		LAi_CharacterPlaySound(chr, chr.greeting);
	}
	if(playGFX)
	{
		CreateParticleSystem("stars" , x, y+1, z, 0.0, 0.0, 0.0, 20);
	}
	QuestsCheck();	// Force quest check so that case "NPC_Stunned" can trigger
}

// fix this 05-07-12 to check for proper resume old type attribute since it was changed above.
bool LAi_Stunned_AwakenCharacter(aref chr)
{
	aref achr, astun;
	if(!CheckAttribute(chr, "stuntime")) return false;
	// makes character walk again, but not very agile. NK mod to allow resume of old type, and check for actortype
	if(!CheckAttribute(chr,"stuntime.old_type_resume") && !CheckAttribute(chr, "stuntime.actor"))
	{
		if(!CheckAttribute(chr, "first_oldtype")) chr.first_oldtype = chr.stuntime.old_type; // for logoff
		LAi_SetCitizenTypeNoGroup(chr);
		chr.stunnewtype = true;
	} 
	else // NK enable reset old type; edit 05-07-12 for follow
	{//MAXIMUS: all code moved down into the LAi_StunnedStandsUp [for nice-showing this process only] -->
		if(chr.sex=="man" && !StraifCharacter(chr)) { CharacterPlayAction(chr, "Ground_StandUp"); }
		if(chr.sex=="woman") { CharacterPlayAction(chr, "idle_10"); }
	}
	if(!Lai_IsBoardingProcess()) PostEvent("LAi_StandsUp", 3750, "i", chr);//MAXIMUS: [for nice-showing this process only]
	else PostEvent("LAi_StandsUp", 3970, "i", chr);
	//MAXIMUS: all code moved down into the LAi_StunnedStandsUp [for nice-showing this process only] <--
	return true;
}

//MAXIMUS: moved here from LAi_Stunned_AwakenCharacter [for nice-showing this process only] -->
#event_handler("LAi_StandsUp", "LAi_StunnedStandsUpCall");
void LAi_StunnedStandsUpCall()
{
	aref chr = GetEventData();
	LAi_StunnedStandsUp(chr);
}

void LAi_StunnedStandsUp(aref chr)
{
	aref achr, astun;
	if(!CheckAttribute(chr, "stuntime")) return;
	if(CheckAttribute(chr,"stuntime.dialog.filename")) chr.dialog.filename = chr.stuntime.dialog.filename;	// restores original dialog, NK add checkattr 05-04-09
	if(CheckAttribute(chr,"stuntime.dialog.currentnode")) chr.dialog.currentnode = chr.stuntime.dialog.currentnode;	// TIH dont forget CURRENTNODE ! Aug31'06
	//else chr.dialog.filename = ""; // NK 05-04-09
	if(CheckAttribute(chr, "stuntime.greeting")) chr.greeting = chr.stuntime.greeting; // NK for greeting
	else DeleteAttribute(&chr, "greeting");
	if(!CheckAttribute(chr,"stuntime.old_type_resume") && !CheckAttribute(chr, "stuntime.actor")) { /*do nothing*/ }
	else
	{
		string func;
		if(IsOfficer(chr) || bAbordageStarted || chr.stuntime.old_type == "officer") func = "LAi_Set"+chr.stuntime.old_type+"Type";
		else func = "LAi_Set"+chr.stuntime.old_type+"TypeNoGroup";
		trace("old type func name is " + func + ", type is " + chr.stuntime.old_type);
		call func(chr);
		if(CheckAttribute(chr, "stuntime.actor.type"))
		{
			DeleteAttribute(chr, "chr_ai.type");
			chr.chr_ai.type = "";
			makearef(astun, chr.stuntime.actor.type);
			makearef(achr, chr.chr_ai.type);
			CopyAttributes(&achr, &astun);
		}
		if(CheckAttribute(chr, "stuntime.actor.tmpl"))
		{
			DeleteAttribute(chr, "chr_ai.tmpl");
			chr.chr_ai.tmpl = "";
			makearef(astun, chr.stuntime.actor.tmpl);
			makearef(achr, chr.chr_ai.tmpl);
			CopyAttributes(&achr, &astun);
		}
		if(CheckAttribute(chr, "stuntime.locfollow")) // just in case follower
		{
			chr.location.follower = chr.stuntime.locfollow;
		}
	}
	if(CheckAttribute(chr,"stuntime.group")) LAi_group_MoveCharacter(chr, chr.stuntime.group);// MAXIMUS 08.10.2006
	
	// corpse group 05-07-19
	if(CheckAttribute(chr, "stuntime.name")) chr.name = chr.stuntime.name;
	if(CheckAttribute(chr, "stuntime.middlename")) chr.name = chr.stuntime.middlename;
	if(CheckAttribute(chr, "stuntime.lastname")) chr.lastname = chr.stuntime.lastname;
	if(CheckAttribute(chr, "corpse"))
	{
		LAi_SetImmortal(chr, false);
		LAi_KillCharacter(chr);
		DeleteAttribute(chr, "corpse");
	}
	
	if(CheckAttribute(chr,"stuntime")) { DeleteAttribute(chr,"stuntime"); }// removes "stunned" tag
}
//MAXIMUS: moved here from LAi_Stunned_AwakenCharacter [for nice-showing this process only] <--

void LAi_Stunned_MakeCorpse(aref chr)
{
	if(!CheckAttribute(chr, "stuntime"))
	{
		aref achr, astun;
		chr.stuntime.old_type = chr.chr_ai.type; // save old type
		if(!CheckAttribute(chr, "first_oldtype")) chr.first_oldtype = chr.chr_ai.type; // for logoff
		if(chr.chr_ai.type == LAI_TYPE_ACTOR) // save actor properties
		{
			chr.stuntime.actor.type = "";
			makearef(astun, chr.stuntime.actor.type);
			makearef(achr, chr.chr_ai.type);
			CopyAttributes(&astun, &achr);
			
			chr.stuntime.actor.tmpl = "";
			makearef(astun, chr.stuntime.actor.tmpl);
			makearef(achr, chr.chr_ai.tmpl);
			CopyAttributes(&astun, &achr);
			if(CheckAttribute(chr, "location.follower")) // just in case follower
			{
				chr.stuntime.locfollow = chr.location.follower;
			}
		}
		chr.stuntime.dialog.filename = chr.dialog.filename;	// saves original dialog
		if(CheckAttribute(chr, "greeting")) chr.stuntime.greeting = chr.greeting; // NK to make a groan the greeting
	}	
	DeleteAttribute(chr, "greeting");
	chr.corpse = true;
	chr.stuntime.name = chr.name;
	chr.stuntime.lastname = chr.lastname;
	if(CheckAttribute(chr, "middlename")) chr.stuntime.middlename = chr.middlename;
	chr.lastname = GetMyFullName(chr);
	chr.name = XI_ConvertString("The Late");
	chr.stuntime.old_type_resume = true;
		
	chr.dialog.filename = "corpse_dialog.c";
	chr.stuntime.group = chr.chr_ai.group;
	LAi_SetStunnedTypeNoGroup(chr);
	LAi_Group_MoveCharacter(chr, LAI_GROUP_CORPSES);
	LAI_group_SetRelationWithAllStock(LAI_GROUP_CORPSES, LAI_GROUP_NEUTRAL);
}

void LAi_type_stunned_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_STUNNED;
	LAi_tmpl_stay_InitTemplate(chr);
	//Установим анимацию персонажу
	LAi_SetDefaultStayAnimation(chr);
	BeginChangeCharacterActions(chr);

// ccc jul05 corpse, only Henry shall move, all others are stunned or corpses
	if(CheckAttribute(chr,"corpse")) // dead
	{
		string laystr = "Lay_"+(rand(1)+1);
		chr.actions.idle.i1 = laystr;
		chr.actions.idle.i2 = laystr;
		chr.actions.idle.i3 = laystr;
		chr.actions.dead.d1 = laystr;
		EndChangeCharacterActions(chr);
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
	}
	else // stunned
	{//MAXIMUS: [for nice-showing this process only] -->
		if(chr.sex=="man" && !StraifCharacter(chr)) { CharacterPlayAction(chr, "Ground_SitDown"); }
		if(chr.sex=="woman" || StraifCharacter(chr)) { CharacterPlayAction(chr, "Afraid"); }
		PostEvent("LAi_BecameStunned", 3500, "i", chr);/*
		if(chr.sex != "woman")
		{
			chr.actions.idle.i1 = "Ground_sitting"; //"Ground_sitting";
			chr.actions.idle.i2 = "Ground_sitting"; //"Ground_look_around";
			chr.actions.idle.i3 = "Ground_sitting"; //"Ground_Scratch";
			chr.actions.dead.d1 = "Ground_Death";
		}
		else
		{
//			chr.actions.idle.i1 = "Sit_Lower_head";
//			chr.actions.idle.i2 = "Sit_Lower_head";
//			chr.actions.idle.i3 = "Sit_Lower_head";
//			chr.actions.dead.d1 = "Sit_Death";
//MAXIMUS 23.09.2006 [looks more realistic] -->
			chr.actions.idle.i1 = "Afraid";
			chr.actions.idle.i2 = "Afraid";
			chr.actions.idle.i3 = "Afraid";
			switch(rand(1))
			{
				case 0: chr.actions.dead.d1 = "death_afraid_1"; break;
				case 1: chr.actions.dead.d1 = "death_afraid_2"; break;
			}
//MAXIMUS 23.09.2006 [looks more realistic] <--
		}*/
	}/*
// ccc jul05 end
	EndChangeCharacterActions(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);*/
}

#event_handler ("LAi_BecameStunned", "LAi_CharacterBecameStunned");
void LAi_CharacterBecameStunned()
{
	aref chr = GetEventData();
	CharacterPlayAction(chr, "");
	if(!CheckAttribute(chr,"corpse"))
	{
		if(GetAttribute(chr, "sex")!="woman")
		{
			chr.actions.idle.i1 = "Ground_sitting";
			chr.actions.idle.i2 = "Ground_sitting";
			chr.actions.idle.i3 = "Ground_sitting";
			chr.actions.dead.d1 = "Ground_Death";
		}
		else
		{
			chr.actions.idle.i1 = "Afraid";
			chr.actions.idle.i2 = "Afraid";
			chr.actions.idle.i3 = "Afraid";
			switch(rand(1))
			{
				case 0: chr.actions.dead.d1 = "death_afraid_1"; break;
				case 1: chr.actions.dead.d1 = "death_afraid_2"; break;
			}
		}
	}
	EndChangeCharacterActions(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}
//MAXIMUS: [for nice-showing this process only] <--

//Процессирование типа персонажа
void LAi_type_stunned_CharacterUpdate(aref chr, float dltTime)
{

	// ccc jul05 tools, mine
	if(chr.lastname == "mantrap")
	{
		int res = LAi_FindNearestCharacter(chr, 1);
		ref findCh;
		if(res != -1)
		{

			findCh = GetCharacter(res);
			logit(chr.lastname + " detects " + findCh.lastname);
			PlaySound("objects\duel\sword_slide1.wav");
			LAi_ApplyCharacterDamage(findch, 3);
			LAi_CheckKillCharacter(findCh);
			//LAi_group_SetRelation(findCh.chr_ai.group, chr.chr_ai.group, LAI_GROUP_ENEMY);
			LAi_group_Attack(chr, findCh);
			//LAi_tmpl_fight_SetTarget(findCh, chr);

			/*
			if(findCh.chr_ai.group!=LAI_GROUP_PLAYER&&LAi_IsFightMode(findCh))
			{
				//LAi_group_SetRelation(findCh.chr_ai.group, "pole", LAI_GROUP_ENEMY);
				//LAi_tmpl_SetFight(findCh, chr);
				LAi_tmpl_fight_SetTarget(findCh, chr);
			}
			*/
			if(CheckCharacterItem(chr,"pistolx4") && findCh.lastname!="pole") Explosion (findCh, 100);
		}
	}

	// ccc end

	// ccc special weapon kit, reawakening of stunned characters
	if( CheckAttribute(chr, "stuntime" ) && !CheckAttribute(chr, "corpse")) 	// if victim is stunned
	{
		if( stf(chr.stuntime)+stf(chr.stuntime.duration) <  locTmpTime || locTmpTime < 3 )
			// 100 sec after knockout OR after reloading
		{ LAi_Stunned_AwakenCharacter(&chr); return; }
	}
	// ccc special weapon kit end, unchanged original code continues

	int num = FindNearCharacters(chr, 5.0, -1.0, -1.0, 0.001, false, true);
	int idx;
	if(num > 0)
	{
		for(int i = 0; i < num; i++)
		{
			idx = sti(chrFindNearCharacters[i].index);
			if(LAi_group_IsEnemy(chr, &Characters[idx])) break;
		}
		if(i < num)
		{
			// always off because stunned doesn't cower. NK 05-07-10 not used for Henry any more
			/*if(chr.chr_ai.tmpl != LAI_TMPL_ANI && chr.id == "Henry") // ccc only Henry shall cower
			{
				LAi_tmpl_ani_PlayAnimation(chr, "afraid", -1.0);
				LAi_SetAfraidDead(chr);
			}*/
		}else{
			if(chr.chr_ai.tmpl != LAI_TMPL_STAY)
			{
				LAi_tmpl_stay_InitTemplate(chr);
				LAi_SetDefaultDead(chr);
			}
		}
	}else{
		if(chr.chr_ai.tmpl != LAI_TMPL_DIALOG)
		{
			/*if(rand(500) == 123)
			{
				LAi_CharacterPlaySound(chr, "poorman");
			}*/
		}
		if(chr.chr_ai.tmpl != LAI_TMPL_STAY)
		{
			LAi_tmpl_stay_InitTemplate(chr);
			LAi_SetDefaultDead(chr);
		}
	}

	//}	// ccc jul05 tools, mine

}

//Загрузка персонажа в локацию
bool LAi_type_stunned_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_stunned_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_stunned_TemplateComplite(aref chr, string tmpl)
{
}

//Сообщить о желании завести диалог
void LAi_type_stunned_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_stunned_CanDialog(aref chr, aref by)
{
	//Если уже говорим, то откажем
	if(chr.chr_ai.tmpl == LAI_TMPL_STAY) return true;
	//Согласимся на диалог
	 return true;	// ccc special weapon kit, changed from false, so that you can rob even enemies 
}

//Начать диалог
void LAi_type_stunned_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	LAi_tmpl_SetActivatedDialog(chr, by);
}

//Закончить диалог
void LAi_type_stunned_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
}

//Персонаж атаковал другого персонажа
void LAi_type_stunned_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//Персонаж атоковал заблокировавшегося персонажа
void LAi_type_stunned_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//Персонаж выстрелил
void LAi_type_stunned_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


//Персонаж атакован
void LAi_type_stunned_Attacked(aref chr, aref by)
{
	// ccc building kit dec05, to stop npcs hacking at corpses
	LAi_group_SetAlarm(by.chr_ai.group, LAI_GROUP_CORPSES, 0.0); 
	LAI_group_SetRelationWithAllStock(LAI_GROUP_CORPSES, LAI_GROUP_NEUTRAL);	
}

