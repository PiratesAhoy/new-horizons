

#event_handler("Event_ChrSnd_Body", "LAi_ChrSnd_Body");
void LAi_ChrSnd_Body()
{
	aref chr = GetEventData();
	if(CheckAttribute(chr, "sex"))
	{
		switch(chr.sex)
		{
		case "man":
			LAi_CharacterPlaySound(chr, "body");
			break;
		case "woman":
			LAi_CharacterPlaySound(chr, "body");
			break;
		case "skeleton":
			LAi_CharacterPlaySound(chr, "skeleton_body");
			break;
		case "monkey":
			LAi_CharacterPlaySound(chr, "monkey_body");
			break;
		}
	}
}

#event_handler("Event_ChrSnd_Dead", "LAi_ChrSnd_Dead");
void LAi_ChrSnd_Dead()
{
	aref chr = GetEventData();
	if(CheckAttribute(chr, "corpse")) return; // NK to not play second death sound.
	if(CheckAttribute(chr, "sex"))
	{
		switch(chr.sex)
		{
		case "man":
			string sname = "dead";
				switch(makeint(chr.nation))
				{
					case 0 : sname = "dead_eng";break;
					case 1 : sname = "dead_fra";break;
					case 2 : sname = "dead_spa";break;
					case 3 : sname = "dead_guy";break;
					case 4 : sname = "dead_dut";break;
					case 5 : sname = "dead_por";break;
				}
				if(rand(10) < 3) LAi_CharacterPlaySound(chr, sname);
				else LAi_CharacterPlaySound(chr, "dead");
			break;
		case "woman":
			LAi_CharacterPlaySound(chr, "dead_wom");
			break;
		case "skeleton":
			LAi_CharacterPlaySound(chr, "skeleton_dead");
			break;
		case "monkey":
			LAi_CharacterPlaySound(chr, "monkey_dead");
			break;
		}
	}
}

#event_handler("Event_ChrSnd_Attack", "LAi_ChrSnd_Attack");
void LAi_ChrSnd_Attack()
{
	aref chr = GetEventData();
	if(CheckAttribute(chr, "sex"))
	{
		switch(chr.sex)
		{
		case "man":
			string sname = "man_attack";
				switch(makeint(chr.nation))
				{
					case 0 : sname = "man_attack_eng";break;
					case 1 : sname = "man_attack";break;
					case 2 : sname = "man_attack_spa";break;
					case 3 : sname = "man_attack";break;
					case 4 : sname = "man_attack_dut";break;
					case 5 : sname = "man_attack";break;
				}
				if(rand(10) < 1) LAi_CharacterPlaySound(chr, sname);
				else LAi_CharacterPlaySound(chr, "man_attack");
			break;
		case "woman":
			LAi_CharacterPlaySound(chr, "woman_attack");
			break;
		case "skeleton":
			LAi_CharacterPlaySound(chr, "skeleton_attack");
			break;
		case "monkey":
			LAi_CharacterPlaySound(chr, "monkey_attack");
			break;
		}
	}
}

#event_handler("Event_ChrSnd_Hit", "LAi_ChrSnd_Hit");
void LAi_ChrSnd_Hit()
{
	aref chr = GetEventData();
	if(CheckAttribute(chr, "sex"))
	{
		switch(chr.sex)
		{
		case "man":
			LAi_CharacterPlaySound(chr, "man_hit");
			break;
		case "woman":
			LAi_CharacterPlaySound(chr, "woman_hit");
			break;
		case "skeleton":
			LAi_CharacterPlaySound(chr, "skeleton_hit");
			break;
		case "monkey":
			LAi_CharacterPlaySound(chr, "monkey_hit");
			break;
		}
	}
}

