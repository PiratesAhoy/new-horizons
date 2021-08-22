// ccc aug 05 AI for "characters" attached to buildings

#define LAI_TYPE_BUILDING		"Building"

void LAi_type_Building_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_BUILDING;
	LAi_tmpl_stay_InitTemplate(chr);
//	LAi_SetDefaultStayAnimation(chr);
	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "building";
	chr.actions.dead.d1 = "building";
	EndChangeCharacterActions(chr);
//	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}

void LAi_type_Building_CharacterUpdate(aref chr, float dltTime)
// this only checks if enemies are near a building and shoots at them. Looks messy but pls don't change anything without contacting ccc
{
	int num, idx, i;
	ref target;
	float x, y, z;

// if box has grenade it acts as boobytrap
	// LDH added checkattribute - 06Jan09
	if(CheckAttribute(chr,"equip.blade") && chr.equip.blade == "box" && CheckCharacterItem(chr,"pistolgrenade"))
	{
		num = FindNearCharacters(chr, 2, -1.0, -1.0, 0.001, false, true);
  		if(num > 0)
  		{
  			for(i = 0; i < num; i++)
  			{
  				idx = sti(chrFindNearCharacters[i].index);
				target = GetCharacter(idx);
				break;
  			}
  			if(i < num)
  			{
  			//	logit(chr.lastname + " (booby) detects " + target.id + " and explodes");
  				Explosion(target, 100);
  				return;		// chr does nothing else
  			}
  		}
	}

// otherwise: if chr has no cannon
	if(!CheckCharacterItem(chr,"cannon") ) return;		// chr does nothing else


// otherwise: if chr is reloading nothing happens
	if( CheckAttribute(chr, "loadtime" ) ) 	// if chr is reloading
	{
		if( stf(chr.loadtime)+10 < locTmpTime)	// 10 sec after reloading started
		{
			DeleteAttribute(chr,"loadtime");	// removes "loading" tag
		}
		return;		// chr does nothing else
	}

// otherwise: if chr is not reloading we check first if an enemy is closer than 6. Then gundamage is applied to him only
	num = FindNearCharacters(chr, 6, -1.0, -1.0, 0.001, false, true);
	if(num > 0)
	{
		for(i = 0; i < num; i++)
		{
			idx = sti(chrFindNearCharacters[i].index);
			if(LAi_group_IsEnemy(chr, &Characters[idx]))
			{
				target = GetCharacter(idx);
				break;
			}
		}
		if(i < num)
		{
			LAi_ApplyCharacterDamage(target, 100);
			if (sti(LAi_GetCharacterHP(target)) < 101) Lai_KillCharacter(target);
			chr.loadtime = locTmpTime;
			GetCharacterPos(chr, &x, &y, &z);
			CreateParticleSystemX("blast_inv", x, y, z, x, y, z,2);
			CreateParticleSystemX("cancloud", x, y, z, x, y, z,10);
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			return;		// chr does nothing else
		}
	}


// otherwise: explosiondamage on several enemies is used only at longer range , in order to prevent damage to oneself and allies nearby
	num = FindNearCharacters(chr, 20.0, -1.0, -1.0, 0.001, false, true);
	if(num > 0)
	{
		for(i = 0; i < num; i++)
		{
			idx = sti(chrFindNearCharacters[i].index);
			if(LAi_group_IsEnemy(chr, &Characters[idx]))
			{
				target = GetCharacter(idx);
				break;
			}
		}
		if(i < num)
		{
			Explosion(target, 100);
			chr.loadtime = locTmpTime;
			GetCharacterPos(chr, &x, &y, &z);
			CreateParticleSystemX("blast_inv", x, y, z, x, y, z,2);
			CreateParticleSystemX("cancloud", x, y, z, x, y, z,10);
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");

			// mar06  cannonhit raises alarm
			LAi_group_SetLookRadius(target.chr_ai.group, 25.0);
			LAi_group_SetSayRadius(target.chr_ai.group, 20.0);
			LAi_group_SetHearRadius(target.chr_ai.group, 20.0);
		}
	}

}

bool LAi_type_Building_CharacterLogin(aref chr)
{
	return true;
}

bool LAi_type_Building_CharacterLogoff(aref chr)
{
	return true;
}

void LAi_type_Building_TemplateComplite(aref chr, string tmpl)
{
}

void LAi_type_Building_NeedDialog(aref chr, aref by)
{
}

bool LAi_type_Building_CanDialog(aref chr, aref by)
{
	 return true;
}

void LAi_type_Building_StartDialog(aref chr, aref by)
{
}

void LAi_type_Building_EndDialog(aref chr, aref by)
{
}

void LAi_type_Building_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

void LAi_type_Building_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

void LAi_type_Building_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


void LAi_type_Building_Attacked(aref chr, aref by)
{
	if(CheckCharacterItem(chr,"pistolgrenade"))
	{
	//	logit(chr.lastname + " attacked by" + by.id + " uses grenade");
		Explosion (by, 100);
		TakeItemFromCharacter(chr,"pistolgrenade" );	// only onetime use
	}	
}

