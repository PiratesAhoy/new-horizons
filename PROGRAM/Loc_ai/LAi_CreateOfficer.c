//Everything rewritten by Levis

void LAi_Create_Officer(int rankch, ref Npchar)
{
	DeleteAttribute(Npchar,"skillsetup"); //just in case
	DeleteAttribute(Npchar,"completeinit"); //just in case
	Npchar.rank = GetRandomRank(CharacterIsFriend(Npchar), GetAttribute(Npchar,"quest.officertype"), rankch);
	bool realfantom = FALSE;
	//Let's make it fantom for now so it's rank is remembered
	if(CheckAttribute(Npchar,"isfantom")) realfantom = TRUE;
	else Npchar.isfantom = true;
	//Always set the location first to pchar so we know for sure he is initialized right
	string oldlocation = "";
	if(CheckAttribute(Npchar,"location")) oldlocation = Npchar.location;
	Npchar.location = Characters[GetMaincharacterIndex()].location;
	//Now lets set it to the right level
	InitCharacterSkills(Npchar);
	//Now restore the old location
	Npchar.location = oldlocation;
	if(sti(Npchar.quest.OfficerPrice) < 100 && !CheckAttribute(Npchar,"quest.NoRaise")) //Just an arbitrary number. If it wasn't set already, it should be 0 or 1, but in case someone accidentally made a character with a very low officerprice
	{
		//Here we create a base officerprice for the character.
		int officerprice = GetBaseOfficerPrice(Npchar);
		//let's randomize it a little bit.
		Npchar.quest.OfficerPrice = 0.9*officerprice + 0.2*rand(officerprice);
		if(DEBUG_OFFICERPRICE > 0) trace("OFFICERPRICE reset because too low, set to: "+Npchar.quest.OfficerPrice+" for "+GetMySimpleName(Npchar));
	}
	if(!realfantom) DeleteAttribute(Npchar,"isfantom");
}

// creates an officer for the player, of type otype, model (from array!!!) model, offset-to-level offset, of nation, and points/perks left assignable if(blank)
ref CreateOfficer_Cheat(string otype, string model, int offset, int nation, bool blank)
{
	ref pchar = GetMainCharacter();
	ref ch;
	ch = GetCharacter(FindFreeRandomOfficer());
	ch.dialog.filename = "enc_officer_dialog.c";
	ch.offgen = true;
	ch.officer = true;
	ch.Dialog.CurrentNode = "hired";
	ch.Dialog.TempNode = "hired";
	ch.quest.meeting = "1";
	ch.quest = "True";
	ch.reputation = 65;
	ch.nation = nation;
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1;
	ch.AbordageMode = 0;
	LAi_SetLoginTime(ch, 0.0, 24.0); // KK
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER); // KK
	ch.quest.officertype = otype
	LAi_Create_Officer(offset, &ch);
	SetModelfromArray(&ch, GetModelIndex(model));
	SetRandomNameToCharacter(&ch);
	LAi_NPC_Equip(&ch, sti(ch.rank), true, true);
	DeleteAttribute(ch, "greeting");
	if(blank) ResetChar_Cheat(&ch);
//	if(FindLoadedLocation() != -1) PlaceCharacter(&ch, "goto");	// PB: Not needed
	LAi_SetOfficerType(ch);
	AddPassenger(&pchar, &ch, false);
	return &ch;
}

ref CreateOfficerType(string otype, int offset)
{
	ref ch;
	ch = GetCharacter(FindFreeRandomOfficer());
	ch.dialog.filename = "enc_officer_dialog.c";
	ch.offgen = true;
	ch.officer = true;
	ch.Dialog.CurrentNode = "Node_1";
	ch.Dialog.TempNode = "First time";
	ch.quest.meeting = 0;
	ch.quest = "True";
	ch.reputation = rand(88) + 1;
	ch.nation = GetCurrentLocationNation();
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	LAi_SetLoginTime(ch, 0.0, 24.0); // KK

	ch.quest.officertype = otype;
	SetModelfromArray(&ch, GetModelIndex(GetRandomModelForTypeNation(1, otype, sti(ch.nation))));
	SetRandomNameToCharacter(&ch);
	LAi_SetCitizenType(ch);
	if(FindLoadedLocation() != -1) PlaceCharacter(&ch, "goto"); //Moved up by levis so it will level easier
	LAi_Create_Officer(offset, &ch);
	LAi_NPC_Equip(&ch, sti(ch.rank), true, true);
	DeleteAttribute(ch, "greeting");
	return &ch;
}

int GetRandomRank(bool isfriend, string officertype, int offset)
{
	ref pchar = GetMainCharacter();
	int pLuck = CalcCharacterSkill(PChar,SKILL_SNEAK);
	int pLead = CalcCharacterSkill(PChar,SKILL_LEADERSHIP);
	int bonus = GetOfficTypeRankBonus(officertype);
	int pRank = 1;
	//Let's get a baserank first
	if(isfriend)
	{
		//friendly encounter
		pRank = makeint(sti(PChar.rank)*0.75 + rand(sti(PChar.rank)*(1.1-(GetDifficulty()*0.2))) + offset);
		pRank = makeint(pRank * (1+((pLuck*2)+(pLead*3))/200)); //Take in account leadership and luck
		pRank = pRank + rand(bonus); //Take in account different officertypes;
		if (pRank < 5) pRank = 2 + rand(5);
	}
	else
	{
		//enemy encounter
		pRank = makeint(sti(PChar.rank)*0.90 + rand(sti(PChar.rank)*(0.2+(GetDifficulty()*0.2))) + offset);
		pRank = pRank + rand(bonus); //Take in account different officertypes;
		if (pRank < 3) pRank = 1 + rand(4);
	}
	return makeint(pRank);
}

int GetCaptainRank(ref SCaptain)
{
	int shipclass = GetCharacterShipClass(SCaptain);
	//Class 8 ship should have a rank 1 captain. A class 1 ship should have something round a rank 40 captain.
	int rank = (8-shipclass)*7;
	rank = rank*0.8 + 0.3*rand(rank);
	rank += GetOfficTypeRankBonus(SCaptain.quest.officertype);
	if(rank < 1) rank = 1;
	return rank;
}

int GetBoardingCrewRank(ref Crewmember)
{
	int crank = sti(Crewmember.rank);
	int rank = crank*0.6 + 0.2*rand(crank);
	rank += GetOfficTypeRankBonus(Crewmember.quest.officertype);
	if(rank < 1) rank = 1;
	return rank;
}

int GetBaseOfficerPrice(ref Officer)
{
	//Get the modifier for the officertype
	float typemod = GetOfficerPriceMod(Officer);
	//Level based price
	int baseprice = (sti(Officer.rank)-1) * 125;
	int skillprice = 0;
	//Skill based price
	for(int i = 0; i < 10; i++)
	{
		skillprice += GetOfficerPriceForSkillLevel(Officer, GetSkillName(i));
	}
	return makeint((baseprice + skillprice) * typemod * OPRICE_LEVEL_MULT);
}

int GetOfficerPriceForSkillLevel(ref Officer, string skillname)
{
	string officType = Officer.quest.officerType;
	int skillFactor = GetOfficerSkillFactor(Officer, skillname);
	if(skillFactor > 0)
	{
		int skilllevel = GetEffectiveSkill(Officer, skillname);
		return skilllevel * skillFactor * 20;
	}
	return 0;
}
