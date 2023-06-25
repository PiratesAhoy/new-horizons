


//«апретить сражатьс€ персонажам в заданной локации
void LAi_LocationFightDisable(ref location, bool isDisable)
{
	if(isDisable)
	{
		location.noFight = "1";
	}else{
		DeleteAttribute(location, "noFight");
	}
}

//–азрешить или запретить генерации монстров
void LAi_LocationMonstersGen(ref location, bool isEnable)
{
	if(isEnable)
	{
		location.monsters = "1";
	}else{
		DeleteAttribute(location, "monsters");
	}
}

//”становить врем€ генерации монстров
void LAi_LocationSetMonstersTime(ref location, float start, float end)
{
	//!!!
	return;

	if(!CheckAttribute(location, "monsters"))
	{
		location.monsters = "0";
	}		
	location.monsters.stime = start;
	location.monsters.etime = end;	
}

bool LAi_LocationIsMonstersGen(ref location)
{
	//ѕроверим разрешение на генерацию монстров
	if(CheckAttribute(location, "monsters") == false) return false;
	if(sti(location.monsters) == 0) return false;
	//ѕроверим врем€ логина
	if(CheckAttribute(location, "monsters.stime"))
	{
		if(CheckAttribute(location, "monsters.etime"))
		{
			float start = stf(location.monsters.stime);
			float end = stf(location.monsters.etime);
			if(!LAi_login_CheckTime(start, end)) return false;
		}
	}
	return true;
}

//–азрешить или запретить генерации фантомов при убийстве в данной локации
void LAi_LocationFantomsGen(ref location, bool isEnable)
{
	if(isEnable)
	{
		location.fantoms = "1";
	}else{
		DeleteAttribute(location, "fantoms");
	}
}

bool LAi_LocationIsFantomsGen(ref location)
{
	if(CheckAttribute(location, "fantoms") == false) return false;
	if(sti(location.fantoms) != true) return false;
	return true;
}


