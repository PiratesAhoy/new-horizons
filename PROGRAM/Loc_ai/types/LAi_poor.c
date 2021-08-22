// File entirely rewritten by 'a simple virtual sailor', based on the Lai_merchant.c 
// contact him on the Pirateahoy.net forum if you have some questions.



#define LAI_TYPE_POOR		"poor"



void LAi_type_poor_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_POOR;
	chr.chr_ai.type.state = "stay";
	chr.chr_ai.type.time = "0";		
	chr.chr_ai.type.who = "-1";
	chr.chr_ai.type.timewait = "0";
	chr.chr_ai.type.afraid = "0";
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_SetDefaultStayAnimation(chr);

	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "Ground_sitting";		
	chr.actions.idle.i2 = "Ground_look_around";	
	chr.actions.idle.i3 = "Ground_Scratch";		
	chr.actions.dead.d1 = "Ground_Death";
	chr.actions.dead.d2 = "Ground_Death1";
	chr.actions.turnLeft = "Ground_sitting";	//not sure about those two lines,
    chr.actions.turnRight = "Ground_sitting";	//but it might solve the stand-up bug.
	EndChangeCharacterActions(chr);


	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}

void LAi_type_poor_CharacterUpdate(aref chr, float dltTime)
{
	float time, tw;
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG)
		{
			LAi_tmpl_stay_InitTemplate(chr);
		}
	if(chr.chr_ai.tmpl == LAI_TMPL_STAY)
	{
		time = stf(chr.chr_ai.type.time);
		int num = FindNearCharacters(chr, 3.5, -1.0, -1.0, 0.001, false, true);
		if(num > 0)
		{
			if(LAi_type_poor_FindEnemy(chr, num) < 0)
			{
				int ichr = sti(chrFindNearCharacters[0].index);
				time = time + dltTime;
				chr.chr_ai.type.time = time;
				if(stf(chr.chr_ai.type.who) != ichr)
				{
					chr.chr_ai.type.time = "0";
					chr.chr_ai.type.who = ichr;
				}
				tw = stf(chr.chr_ai.type.timewait);
				tw = tw + dltTime;
				chr.chr_ai.type.timewait = tw;
				if(time < 60.0)
				{
					if(tw > 6.0)
					{
						if(rand(100) < 30 && CheckAttribute(chr,"beggar"))
						{
							LAi_type_poor_Beg(chr, Characters[ichr]);
							chr.chr_ai.type.timewait = "0";
							CharacterTurnByChr(chr, &Characters[ichr]);
						}
					}
				}else{
					//LAi_type_poor_RestoreAngle(chr);
					if(time > 200.0)
					{
						chr.chr_ai.type.time = "0";
					}
				}
			}else{
				chr.chr_ai.type.afraid = "1";
				LAi_tmpl_ani_PlayAnimation(chr, "Ground_Afraid", -1.0); //was just "afraid"
				//LAi_SetAfraidDead(chr);
				BeginChangeCharacterActions(chr);
				chr.actions.dead.d1 = "Ground_Afraid_Death";
				chr.actions.dead.d2 = "Ground_Afraid_Death";
				EndChangeCharacterActions(chr);
				//LAi_type_poor_RestoreAngle(chr);
			}
		}else{
			chr.chr_ai.type.time = "0";
			chr.chr_ai.type.who = "-1";
			chr.chr_ai.type.timewait = "1";
			//LAi_type_poor_RestoreAngle(chr);
		}
	}else{
		if(chr.chr_ai.tmpl != LAI_TMPL_ANI)
		{
			chr.chr_ai.type.time = "0";
			chr.chr_ai.type.who = "-1";
			chr.chr_ai.type.timewait = "3";
		}else{
			time = stf(chr.chr_ai.type.time);
			num = FindNearCharacters(chr, 5.5, -1.0, -1.0, 0.001, false, false);
			if(num > 0)
			{
				if(LAi_type_poor_FindEnemy(chr, num) < 0) num = 0;
			}
			if(num <= 0)
			{
				if(sti(chr.chr_ai.type.afraid) != 0)
				{
					chr.chr_ai.type.afraid = "0";
					//LAi_SetDefaultDead(chr);
					BeginChangeCharacterActions(chr);
					chr.actions.dead.d1 = "Ground_Death";
					chr.actions.dead.d2 = "Ground_Death1";
					EndChangeCharacterActions(chr);
					LAi_tmpl_stay_InitTemplate(chr);
				}
			}else{
				BeginChangeCharacterActions(chr);
				chr.actions.dead.d1 = "Ground_Afraid_Death";
				chr.actions.dead.d2 = "Ground_Afraid_Death";
				EndChangeCharacterActions(chr);
				//LAi_SetAfraidDead(chr);
			}
		}
	}
} 

bool LAi_type_poor_CharacterLogin(aref chr)
{
	return true;
}


bool LAi_type_poor_CharacterLogoff(aref chr)
{
	return true;
}


void LAi_type_poor_TemplateComplite(aref chr, string tmpl)
{	

	if(chr.chr_ai.tmpl == LAI_TMPL_ANI)
	{
		if(sti(chr.chr_ai.type.afraid) == 0)
		{
			LAi_tmpl_stay_InitTemplate(chr);
		}
	}
}


void LAi_type_poor_NeedDialog(aref chr, aref by)
{
}


bool LAi_type_poor_CanDialog(aref chr, aref by)
{
	
	if(chr.chr_ai.type.afraid == "1") return false;
	if(chr.chr_ai.tmpl == LAI_TMPL_STAY) return true;
	if(chr.chr_ai.tmpl == LAI_TMPL_ANI) return true;
	return false;
}


void LAi_type_poor_StartDialog(aref chr, aref by)
{
	LAi_CharacterSaveAy(chr);
	CharacterTurnByChr(chr, by);
	LAi_tmpl_SetActivatedDialog(chr, by);
}


void LAi_type_poor_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_CharacterRestoreAy(chr);
}

void LAi_type_poor_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

void LAi_type_poor_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

void LAi_type_poor_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}

void LAi_type_poor_Attacked(aref chr, aref by)
{	
}


void LAi_type_poor_Beg(aref chr, aref ichr)
{
	if(CheckAttribute(ichr,"beggar")) //I don't want a beggar to beg money to another beggar
	{
		if(CheckAttribute(chr, "nation") && rand(100) < 30)
		{
		LAi_tmpl_ani_PlayAnimation(chr, "Ground_Afraid", -1.0);
		string sname = "";
		switch(makeint(chr.nation))
			{
				case 0 : sname = "beggars_eng";break;		// english
				case 1 : sname = "beggars_fra";break;		// french
				case 2 : sname = "beggars_spa";break;		// spanish
				case 3 : break;								// pirates
				case 4 : break;								// dutch
				case 5 : break;								// portuguese
			}
			if(sname != ""){LAi_CharacterPlaySound(chr, sname);}
		//Eng b 008, 010 ; Fre b 009, 010, 012 ; Spa b 007, 009, 024, 030. Not sure if it is really usefull.
		}
	}
	else
	{
		LAi_tmpl_ani_PlayAnimation(chr, "Ground_Beg", -1.0);
		if(CheckAttribute(chr, "sex") && chr.sex == "man")
		{
			if(CheckAttribute(chr, "nation") && chr.nation == 2) LAi_CharacterPlaySound(chr, "beggar_spa");
			else LAi_CharacterPlaySound(chr, "beggar");
		}
	}
}

void LAi_type_poor_RestoreAngle(aref chr)
{
	if(CheckAttribute(chr, "location.group"))
	{
		if(CheckAttribute(chr, "location.locator"))
		{
			CharacterTurnByLoc(chr, chr.location.group, chr.location.locator);
		}
	}
}


int LAi_type_poor_FindEnemy(aref chr, int num)
{
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return idx;
	}
	return -1;
}

