#define CURSED_PIRATES_ENC_CHANCE 0.3

ref CurLandEnc;
object TempLandEnc;

bool LEnc_LoginStart(ref location, string encGroup, string encLocator, int maxChrQuant)
{
	

	ref player, CurTemplate;
	player = GetMainCharacter();
	string sTempName;
	if(!CheckAttribute(location, "type")) return false;

	CurTemplate = GetLandEncTemplateByID(location.type);

	if(GetAttribute(player  , "vcskip") == true) return false; // PB
	if(GetAttribute(location, "vcskip") == true) return false; // PB
//	if(CheckAttribute(location, "DisableEncounters") == true && sti(location.DisableEncounters) != 0 ) return false;

	// NK rewrite this. 05-07-09
	int leqty = makeint(CurTemplate.quantity);
	bool found = false;
	int i, cur;
	string lencs[32];
	if(leqty)
	{
		cur = 0;
		for(i = 1; i <= leqty; i++)
		{
			sTempName = "enc" + i;
			if(CheckAttribute(CurTemplate, sTempName))
			{
				float chance = 0.5;
				if(CheckAttribute(CurTemplate, sTempName+".chance"))
				{
					chance = stf(CurTemplate.(sTempName).chance);
				}
				if(CheckAttribute(CurTemplate, sTempName+".StartTime") && CheckAttribute(CurTemplate, sTempName+".EndTime"))
				{
					if(!LAi_login_CheckTime(stf(CurTemplate.(sTempName).StartTime), stf(CurTemplate.(sTempName).EndTime))) continue;
				}
				if(frnd() <= chance*ENC_CHANCE_SCALAR)
				{
					found = true;
					lencs[cur] = sTempName;
					cur++;
				}
			}
		}
		if(found) sTempName = lencs[rand(cur-1)];
	}
	/*sTempName = Rand(makeint(CurTemplate.quantity)-1)+1;
	if(makeint(CurTemplate.quantity) && makeint(sTempName) >= 0)*/
	if(found)
	{
		//sTempName = "enc" + sTempName;	

		CopyAttributes(&TempLandEnc, GetLandEncByID(CurTemplate.(sTempName).type));

		CurLandEnc = &TempLandEnc;			
	}
	else
	{
		return false;
	}

	if(CheckAttribute(CurLandEnc, "StartingQuest1"))
	{
		player.quest.LandEnc_StartingQuest1.win_condition.l1 = CurLandEnc.StartingQuest1.QuestType;
		player.quest.LandEnc_StartingQuest1.win_condition.l1.location = location.id;
		player.quest.LandEnc_StartingQuest1.win_condition.l1.locator_group = encGroup;
		player.quest.LandEnc_StartingQuest1.win_condition.l1.locator = encLocator;
		player.quest.LandEnc_StartingQuest1.win_condition = CurLandEnc.StartingQuest1;
		//log_setstringTolog("!!!!" + CurLandEnc.StartingQuest1);
	}
	if(CheckAttribute(CurLandEnc, "StartingQuest2"))
	{
		player.quest.LandEnc_StartingQuest2.win_condition.l1 = CurLandEnc.StartingQuest2.QuestType;
		player.quest.LandEnc_StartingQuest2.win_condition.l1.location = location.id;
		player.quest.LandEnc_StartingQuest2.win_condition.l1.locator_group = encGroup;
		player.quest.LandEnc_StartingQuest2.win_condition.l1.locator = encLocator;
		player.quest.LandEnc_StartingQuest2.win_condition = CurLandEnc.StartingQuest2;
	//	log_setstringTolog("!!!!" + CurLandEnc.StartingQuest2);
	}

//	Location.locators_radius.(encGroup).(encLocator) = 5;


	CurLandEnc.LocationID = location.id;
	CurLandEnc.LocGroup = encGroup;
	CurLandEnc.Locator = encLocator;
	CurLandEnc.maxCharacters = maxChrQuant;
	CurLandEnc.CurCharacter = 1;
	return true;
}

bool LEnc_LoginSelectModel(ref location, aref modelInfo, string group, string locator)
{
	string CurrentChar, CurModel;
	CurrentChar = "char" + CurLandEnc.CurCharacter;
	CurModel = "model" + (Rand(Makeint(CurLandEnc.(CurrentChar).modelQuantity)-1) + 1);

	modelInfo.model = CurLandEnc.(CurrentChar).(CurModel);
	// NK iscombat 05-07-27
	if(CheckAttribute(CurLandEnc, CurrentChar+"."+CurModel+".iscombat")) { modelInfo.iscombat = CurLandEnc.(CurrentChar).(CurModel).iscombat; }
	else
	{
		if(CheckAttribute(CurLandEnc, CurrentChar+".iscombat")) { modelInfo.iscombat = CurLandEnc.(CurrentChar).iscombat; }
		else { modelInfo.iscombat = -1; }
	}
	// NK modeltypes 05-07-09 -->
	//modelInfo.ani = CurLandEnc.(CurrentChar).(CurModel).ani;
	if(CheckAttribute(CurLandEnc, CurrentChar+"."+CurModel+".sex")) { modelInfo.sex = CurLandEnc.(CurrentChar).(CurModel).sex; }
	else
	{
		if(CheckAttribute(CurLandEnc, CurrentChar+".sex")) { modelInfo.sex = CurLandEnc.(CurrentChar).sex; }
		else { trace("no sex found"); modelInfo.sex = ""; }
	}
	if(CheckAttribute(CurLandEnc, CurrentChar+"."+CurModel+".nation")) { modelInfo.nation = CurLandEnc.(CurrentChar).(CurModel).nation; }
	else
	{
		if(CheckAttribute(CurLandEnc, CurrentChar+".nation")) { modelInfo.nation = CurLandEnc.(CurrentChar).nation; }
		else { modelInfo.nation = GetCurrentLocationNation(); }
	}
	//modelInfo.HeadModel = "h_" + modelInfo.model;
	// NK <--
	// NK -->
	modelInfo.pistol = CurLandEnc.(CurrentChar).pistol;
	modelInfo.sword  = CurLandEnc.(CurrentChar).sword;
	// NK <--

	return makeint(CurLandEnc.(CurrentChar).cont);
}

void LEnc_LoginCorrectParams(ref location, aref chr, string group, string locator)
{
	ref player;
// Viper - Sword bugfix Begin
	//bool IsPistol, IsBlade, isBlade2;
	player = GetMainCharacter();
	string CurrentChar, CurModel, curAttr;
	CurrentChar = "char" + CurLandEnc.CurCharacter;
	//CurModel = "model" + (Rand(Makeint(CurLandEnc.(CurrentChar).modelQuantity)-1) + 1);
	chr.id = "Enc_Char" + CurLandEnc.CurCharacter;

	//chr.rank = makeint(player.rank) - 2 + rand(4); // NK
	if(makeint(chr.rank) <= 0) chr.rank = 1;

	//chr.experience = CalculateExperienceFromRank(sti(chr.rank));

	facemaker(chr);

	//curAttr = "char" + CurLandEnc.CurCharacter + ".pistol";
	//if(CheckAttribute(CurLandEnc, curAttr)) IsPistol = true;
	//IsPistol = CurLandEnc.(curAttr)
	//if(LogsToggle) Log_SetStringToLog(curAttr + " = " + IsPistol); // NK

	//curAttr = "char" + CurLandEnc.CurCharacter + ".sword";
	//if(CheckAttribute(CurLandEnc, curAttr)) IsBlade2 = true;
	//IsBlade = CurLandEnc.(curAttr)

	//LAi_NPC_Equip(chr, makeint(chr.rank), IsBlade, floatRet(IsPistol,0.5+frnd()/2.0,frnd()/2.0)); // NK
	//if (isBlade2 && !IsBlade && CheckCharacterItem(chr, "blade4") ) TakeItemFromCharacter(chr, "blade4");

// Viper - Sword bugfix End

	switch(CurLandEnc.(CurrentChar).type)
	{
		case "warrior":
			LAi_SetWarriorTypeNoGroup(chr);
			LAi_warrior_SetStay(chr, true);
			LAi_warrior_DialogEnable(chr, true);
		break;

		case "guardian":
			LAi_SetGuardianTypeNoGroup(chr);
		break;

		case "stay":
			LAi_SetStayTypeNoGroup(chr);
		break;

		case "Sit":
			// NK fix for women sitting 05-07-09
			if(!IsSittingCharacter(chr))// MAXIMUS: AOP characters got proper animation
			{
				LAi_SetActorTypeNoGroup(chr);
				string newgroup = "goto";
				string newloc = LAi_FindRandomLocator(newgroup);
				if(newloc == "")
				{
					newgroup = "reload"
					newloc = LAi_FindRandomLocator(newgroup);
				}
				TeleportCharacterToLocator(&chr, newgroup, newloc);
				LAi_ActorWaitDialog(chr, GetMainCharacter()); // enable dialog 05-07-14
			}
			else { LAi_SetSitTypeNoGroup(chr); }
			// NK <--
		break;

		case "Citizen":
			LAi_SetCitizenTypeNoGroup(chr);
		break;

		case "Actor":
			LAi_SetActorTypeNoGroup(chr);
		break;
	}

	//CalculateAppropriateSkills(chr);	

	//LAi_SetHP(chr, LAI_DEFAULT_HP + (makeint(player.rank)*5), LAI_DEFAULT_HP_MAX + (makeint(player.rank)*5));

	chr.Dialog.Filename = CurLandEnc.(CurrentChar).Dialog;
	chr.Dialog.CurrentNode = "Node_1";

}
// MAXIMUS -[AOP characters got proper animation]->
bool IsSittingCharacter(ref chr)
{
	if(chr.sex=="man") return true;
	string curAni = chr.model.animation;
	if(HasSubStr(curAni,"piratess")) return true;
	if(HasSubStr(curAni,"sit")) return true;

	return false;
}
// MAXIMUS <-[AOP characters got proper animation]-
bool LEnc_IsContinueLogin(ref location, aref chr, string group, string locator)
{
	string CurrentChar;
	CurrentChar = "char" + CurLandEnc.CurCharacter;

	bool retValue = makeint(CurLandEnc.(CurrentChar).cont);

	CurLandEnc.CurCharacter = makeint(CurLandEnc.CurCharacter) + 1;
 
	return retValue;
}

void LEnc_LoginEnd(ref location, string encGroup, string encLocator)
{
	DeleteAttribute(CurLandEnc, "");
}

/*
// this is never used... NK 05-07-09
bool CheckEncounterChance(float Chance)
{
	if(frnd() <= Chance) //NK 04-09-05 WTF!!!??? It was using Rand(1), which meant that no matter _what_ the chance was, it was a 50% chance. Bloody weird. Then again, THIS FUNCTION IS NOT USED.
	{
		return true;
	}
	else
	{
		return false;
	}
}
// this is never used... NK 05-07-09
string SelectEncounterblade()
{
	ref player;
	player = getMainCharacter();
	switch(player.rank)
	{
	
		case 1:
			return "blade1";
		break;

		case 2:
			return "blade2";
		break;

		case 3:
			return "blade3";
		break;

		case 4:
			return "blade4";
		break;

		case 5:
			return "blade5";
		break;
	
		case 6:
			return "blade6";
		break;
	
		case 7:
			return "blade7";
		break;

		case 8:
			return "blade8";
		break;

		case 9:
			return "blade9";
		break;

		case 10:
			return "blade10";
		break;

		case 11:
			return "blade11";
		break;

		case 12:
			return "blade12";
		break;
	}
	if(makeint(player.rank) > 12) return "blade13";

	return "blade1";
}
*/

string SelectEncounterPistol()
{
/*	ref player;
	player = getMainCharacter();
	switch(player.rank)
	{
	
		case 1:
			return "pistol1";
		break;

		case 2:
			return "blade2";
		break;

		case 3:
			return "blade3";
		break;

		case 4:
			return "blade4";
		break;

		case 5:
			return "blade5";
		break;
	
		case 6:
			return "blade6";
		break;
	
		case 7:
			return "blade7";
		break;

		case 8:
			return "blade8";
		break;

		case 9:
			return "blade9";
		break;

		case 10:
			return "blade10";
		break;

		case 11:
			return "blade11";
		break;

		case 12:
			return "blade12";
		break;
	}
	if(makeint(player.rank) > 12) return "blade13";*/

	return "pistol1";

}
