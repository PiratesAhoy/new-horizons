     //\\ INTERFACE MOD BY MAXIMUS //\\

//\\ INTERFACE FOR OFFICER STATUS WINDOW //\\

// Aconcagua: deleted several functions not needed here
// they remained from copying this file from characters.c

string sPlayerName;
string oldCurNode;

int nPlayerMoney;
int nPlayerLand;
int nNextExperience;
int nCurrentExperience;
int nFreeSkillPoints;
int nCurrentType;

/*
int nLeadership;
int nFencing;
int nSailing;
int nAccuracy;
int nCannons;
int nGrappling;
int nRepair;
int nDefence;
int nCommerce;
int nSneak;
*/

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;
ref xi_refNPchar;

int oldIndex = -1;

int ListMax;
ref MainChar;

ref PChar;

ref NPchar;

void InitInterface_R(string iniName,ref pCharacter)
{
	int i;
	MainChar = GetMainCharacter();
	// Aconcagua: removed setting this attribute from anywhere else
	// but as perks interface needs it, we have to set it still
	// (but now its located centrally)
	MainChar.CharacterInterface_ViewEncOfficer = true;

	//	FillCharactersList(pCharacter);

	bool  OfficerReturnFromPerk = false;

	xi_refMainChar = GetMainCharacter();
	xi_refCharacter = pCharacter;

	// Aconcagua: resulted from copying from character.c
	/*
	  if (sti(pCharacter.index) != GetMainCharacterIndex())
	  {
	  if(CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer"))
	  {
	*/

	// Aconcagua: this is not needed any more either...
	//GameInterface.View_Enc_Officer = "1";

	FillCharactersList_EncOfficerOnly(pCharacter);
	/*
	  }
	  }
	*/

	AddCharacterExp(xi_refCharacter,0);

//MAXIMUS interface MOD
	if(!CheckAttribute(GameInterface,"title"))
	{  
		GameInterface.title = true;

		if(CheckAttribute(xi_refCharacter,"quest.officertype")) // PB
		{
			GameInterface.View_Enc_Officer = true; // PB: To prevent the officer type and character name showing through each other

			// PB: Officer type already shown below, use generic title instead -->
			if (UsableOfficer(xi_refCharacter))	GameInterface.title = "titleOfficer";
			else								GameInterface.title = "title" + xi_refCharacter.quest.officertype;
			// PB: Officer type already shown below, use generic title instead <--
			
		/*	switch(xi_refCharacter.quest.officertype)
			{
				case "boatswain":
					GameInterface.title = "titleBoatswain";
				break;
				case "cannoneer": 
					GameInterface.title = "titleCannoneer";
				break;
				case "navigator": 
					GameInterface.title = "titleNavigator";
				break;
				case "first mate": 
					GameInterface.title = "titleFirstmate";
				break;
				case "quartermaster": 
					GameInterface.title = "titleQmaster";
				break;
				case "carpenter": 
					GameInterface.title = "titleCarpenter";
				break;
				case "doctor": 
					GameInterface.title = "titleDoctor";
				break;
				case "deck fighter": 
					GameInterface.title = "titleDeckfighter";
				break;
			}*/
		}
	}
	SetSelectable("EXIT_BUTTON",true);
//MAXIMUS interface MOD

    GameInterface.SkillChanger.current = 0;

    GameInterface.StatusLine.EXP.Max = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = xi_refCharacter.Experience;

	if( CheckAttribute(&InterfaceStack,"CharacterView_pos") ) GameInterface.SkillChanger.current = InterfaceStack.CharacterView_pos;
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	bBeParty = false;
	for(i=1;i<OFFICER_MAX  ;i++)	{if( GetOfficersIndex (pCharacter,i)>=0 ) bBeParty = true; break;}
	for(i=1;i<COMPANION_MAX;i++)	{if( GetCompanionIndex(pCharacter,i)>=0 ) bBeParty = true; break;}

	if(Checkattribute(GameInterface, "View_Enc_Officer"))
	{
		bBeParty = false;
		SetNodeUsing("LEFTCHANGE_CHARACTER",false);
		SetNodeUsing("RIGHTCHANGE_CHARACTER",false);
	    SetNodeUsing("B_SKILLUP",false);
	}


	SetNodeUsing("B_ABILITIES",true);

    CreateString(true,"CurrentExperience","",FONT_NORMAL,COLOR_NORMAL,175,379,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"NextExperience","",FONT_NORMAL,COLOR_NORMAL,175,410,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,175,441,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Land","",FONT_NORMAL,COLOR_NORMAL,175,472,SCRIPT_ALIGN_CENTER,1.0); // GreatZen
	CreateString(true,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,156,50,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Reputation","",FONT_NORMAL,COLOR_NORMAL,156,82,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"FreeAbilitiesPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,444,396,SCRIPT_ALIGN_RIGHT,1.0);
	//Levis -->
	CreateString(true,"OfficerType","",FONT_NORMAL,COLOR_MONEY,300,470,SCRIPT_ALIGN_LEFT,1.0);
	//Levis <--
	// MAXIMUS [new skill-change] -->
	CreateString(!AUTO_SKILL_SYSTEM,"FreeSkillPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,610,396,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(!AUTO_SKILL_SYSTEM,"FreeSkill",XI_ConvertString("Free Skill Points"),FONT_NORMAL,COLOR_NORMAL,460,401,SCRIPT_ALIGN_LEFT,1.0);
	if(!AUTO_SKILL_SYSTEM) { CreateImage("FREESKILL","ICONS","black rectangle",454,396,616,428); }
	// MAXIMUS [new skill-change] -->
	CreateString(true,"Rank","",FONT_BOLD_NUMBERS,COLOR_NORMAL,268,324,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"Salary","",FONT_NORMAL,COLOR_MONEY,521,471,SCRIPT_ALIGN_CENTER,1.0); // NK

    CreateString(true,SKILL_LEADERSHIP,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,46,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_FENCING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,80,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_SAILING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,114,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_ACCURACY,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,148,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_CANNONS,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,182,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_GRAPPLING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,216,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_REPAIR,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,250,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_DEFENCE,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,284,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_COMMERCE,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,318,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,SKILL_SNEAK,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,352,SCRIPT_ALIGN_RIGHT,1.0);

// added by MAXIMUS [new skill-change] -->
	if(AUTO_SKILL_SYSTEM)
	{
		int curY = 54;
		for(int c = 0; c < 10; c++)
		{		
			string curSkill = GetSkillName(c);
			if(CheckAttribute(xi_refCharacter,"skill."+curSkill))
			{
				string skillPercent = curSkill+"_Percent";
				CreateString(true,skillPercent,"",FONT_NORMAL,COLOR_MONEY,475,curY,SCRIPT_ALIGN_LEFT,0.8);
				if(CheckAttribute(xi_refCharacter,"skill."+curSkill+".bonus") && stf(xi_refCharacter.skill.(curSkill).bonus)>1.0 && sti(xi_refCharacter.skill.(curSkill))<10) { CreateImage("Bonus"+curSkill,"icons","complete",590,curY-10,620,curY+20); }
				curY = curY + 34;
			}
		}
	}
	SetCurrentNode("SKILLCHANGER");
// added by MAXIMUS [new skill-change] <--

// KK -->
	CreateString(true,"MaxHP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,62,332,SCRIPT_ALIGN_LEFT,0.6);
	SetNodeUsing("MAXSHIPCLASSIMAGES", EnableLimitedShipClass());
	CreateString(EnableLimitedShipClass(), "MaxShipClass", "", FONT_BOLD_NUMBERS, COLOR_NORMAL, 192, 332, SCRIPT_ALIGN_LEFT, 0.6);
// <-- KK
	if(!Checkattribute(GameInterface, "View_Enc_Officer"))
	{
		MainChar.AnyCharacterShow = true;
		CreateStringCheckCase(true,"fakeTitle",xi_refCharacter.name + " " + xi_refCharacter.lastname,"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true);
	}

	SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","ProcessFrame",1);
	
}

void FillCharactersList_EncOfficerOnly(ref tempEncOfficer)
{
	If (CheckAttribute(MainChar,"tempCharactersList"))
	{
		DeleteAttribute(MainChar,"tempCharactersList");
		if (TRACELOG == 1) { Trace("deleted existing list"); }
	}

	ListMax = 1;
	curOfficer = 1;
	
	MainChar.tempCharactersList.member1.idx = sti(tempEncOfficer.index);
	xi_refCharacter = GetCharacter(sti(MainChar.tempCharactersList.member1.idx));
	AddCharacterExp(xi_refCharacter,0);

	if (TRACELOG == 1) { Trace("added enc officer id " + sti(MainChar.tempCharactersList.member1.idx) + ". list total: " + ListMax); }
}

void SetVariable()
{
    sPlayerName = xi_refCharacter.name;

    if(!CheckAttribute(xi_refCharacter,"Money")) { xi_refCharacter.Money = GetRandCharMoney(xi_refCharacter, 10); }
	nPlayerMoney = sti(xi_refCharacter.Money);
    if(xi_refCharacter.id == xi_refMainChar.id) nPlayerMoney = sti(xi_refCharacter.wealth); // NK
    nPlayerLand = GetCharacterLand(xi_refCharacter); // RM
    nCurrentExperience = sti(xi_refCharacter.Experience);
	
    nNextExperience = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    nFreeSkillPoints = sti(xi_refCharacter.Skill.FreeSkill);
	int nFreeAbilities = 0;
	if( CheckAttribute(xi_refCharacter,"perks.FreePoints") )
		nFreeAbilities = sti(xi_refCharacter.perks.FreePoints);

	/*
    nLeadership = sti(xi_refCharacter.Skill.Leadership);
    nFencing = sti(xi_refCharacter.Skill.Fencing);
    nSailing = sti(xi_refCharacter.Skill.Sailing);
    nAccuracy = sti(xi_refCharacter.Skill.Accuracy);
    nCannons = sti(xi_refCharacter.Skill.Cannons);
    nGrappling = sti(xi_refCharacter.Skill.Grappling);
    nRepair = sti(xi_refCharacter.Skill.Repair);
    nDefence = sti(xi_refCharacter.Skill.Defence);
    nCommerce = sti(xi_refCharacter.Skill.Commerce);
    nSneak = sti(xi_refCharacter.Skill.Sneak);
	*/

// added by MAXIMUS [new skill-change] -->
	if(AUTO_SKILL_SYSTEM)
	{
		for(int c = 0; c < 10; c++)
		{		
			string curSkill = GetSkillName(c);
			if(CheckAttribute(xi_refCharacter,"skill."+curSkill))
			{
				string skillPercent = curSkill+"_Percent";
				if(sti(xi_refCharacter.skill.(curSkill)) == 0 || sti(xi_refCharacter.skill.(curSkill)) == MAX_CHARACTER_SKILL)
				{
					DisableString(skillPercent);
				}
				else
				{
					EnableString(skillPercent);
					if(CheckAttribute(xi_refCharacter,"Experience."+curSkill)) GameInterface.strings.(skillPercent) = makeint(stf(xi_refCharacter.Experience.(curSkill))/CalculateSkillExperienceFromRank(sti(xi_refCharacter.skill.(curSkill))+1)*100.0)+"%";
					else GameInterface.strings.(skillPercent) = 0+"%";
				}
			}
		}
	}
// added by MAXIMUS [new skill-change] <--

    GameInterface.StatusLine.EXP.Max = nNextExperience;
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = nCurrentExperience;

    GameInterface.strings.CurrentExperience = nCurrentExperience;
    GameInterface.strings.NextExperience = nNextExperience;
    GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.Land = MakeMoneyShow(nPlayerLand,MONEY_SIGN,MONEY_DELIVER) + " " + XI_ConvertString("acr") + ".";
    GameInterface.strings.CharacterName =   stringRet(  CheckAttribute(xi_refCharacter,"name"),
                                                        xi_refCharacter.name + " ",
                                                        "Anonymous"
                                                     ) + 
                                            stringRet(  CheckAttribute(xi_refCharacter,"lastname"),
                                                        xi_refCharacter.lastname + " ",
                                                        "Coward"
                                                     );
    GameInterface.strings.Reputation = GetTranslatedReputationForSex(xi_refCharacter, GetReputationName(GetCharacterReputation(xi_refCharacter)));
	GameInterface.strings.FreeAbilitiesPoints = nFreeAbilities;
    GameInterface.strings.FreeSkillPoints = nFreeSkillPoints;
	if(DEBUG_EXPERIENCE>0)	GameInterface.strings.Rank = xi_refCharacter.rank+"-"+GetTotalRank(xi_refCharacter);
	else					GameInterface.strings.Rank = GetTotalRank(xi_refCharacter);
	if(CheckAttribute(xi_refCharacter,"quest.officerprice") && bAllies(xi_refCharacter))
	{
		//JA 26Nov06 used to have this * 10??
		GameInterface.strings.Salary = XI_ConvertString("MonthlySalary") + ": " + CalcEncOfficerPrice(xi_refCharacter);
	}
	else { GameInterface.strings.Salary = XI_ConvertString(GetNationNameByType(sti(xi_refCharacter.nation))); }

	GameInterface.strings.MaxHP = MakeInt(LAi_GetCharacterHP(xi_refCharacter)) + "/" + MakeInt(LAi_GetCharacterMaxHP(xi_refCharacter));

	if (EnableLimitedShipClass()) GameInterface.strings.MaxShipClass = GetShipMinClassForCharacter(xi_refCharacter); // KK

	SetSkillShow(SKILL_LEADERSHIP);
	SetSkillShow(SKILL_FENCING);
	SetSkillShow(SKILL_SAILING);
	SetSkillShow(SKILL_ACCURACY);
	SetSkillShow(SKILL_CANNONS);
	SetSkillShow(SKILL_GRAPPLING);
	SetSkillShow(SKILL_REPAIR);
	SetSkillShow(SKILL_DEFENCE);
	SetSkillShow(SKILL_COMMERCE);
	SetSkillShow(SKILL_SNEAK);

	SetNewPicture("FACEPICT", "interfaces\portraits\256\face_" + xi_refCharacter.FaceId + ".tga");

//	SetNewPicture("TYPEPICT", "");
	SetNodeUsing("TYPEPICT",xi_refCharacter.id!=xi_refMainChar.id);
//	if( xi_refCharacter.id == xi_refMainChar.id ) {
//		SetNewPicture("TYPEPICT", "");
//	} else {
		if ( IsCompanion(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\blank_ship.tga");
		/*if ( IsOfficer(xi_refCharacter) )
		{
			if(CheckAttribute(xi_refCharacter,"quest.officertype"))
			{
				switch (xi_refCharacter.quest.officertype)
				{
					case "boatswain": SetNewPicture("TYPEPICT", "interfaces\order.tga"); break;
					case "deck fighter": SetNewPicture("TYPEPICT", "interfaces\fighter.tga"); break;
					case "fighter": SetNewPicture("TYPEPICT", "interfaces\fighter.tga"); break;
					case "cannoneer": SetNewPicture("TYPEPICT", "interfaces\gunner.tga"); break;
					case "quartermaster": SetNewPicture("TYPEPICT", "interfaces\quartermaster.tga"); break;
					case "navigator": SetNewPicture("TYPEPICT", "interfaces\navigator.tga"); break;
					case "first mate": SetNewPicture("TYPEPICT", "interfaces\officer.tga"); break;
					case "carpenter": SetNewPicture("TYPEPICT", "interfaces\carpenter.tga"); break;
					case "doctor": SetNewPicture("TYPEPICT", "interfaces\doctor.tga"); break;	
				}
			}
		}*/
		if ( IsOfficer(xi_refCharacter) ) SetNewPicture("TYPEPICT", GetOfficerPricture(xi_refCharacter)); //Levis put all images in 1 function
		if ( IsOfficerCompanion(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isofficercompanion.tga");
		if ( IsOnShoreLeave(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isonshoreleave.tga");
		if ( IsOfficerOnShoreLeave(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isofficeronshoreleave.tga");
//	}

	if (!CheckAttribute(GameInterface.strings,"OfficerType")) {
		int bestRank, rankNation;
		if (IsMainCharacter(xi_refCharacter)) {
			GameInterface.strings.OfficerType = XI_ConvertString(GetCaptainType(xi_refCharacter)); // PB: Indicate Player Type
			//rankNation = GetServedNation(); //removed by levis for highest rank at character screen
			GameInterface.strings.fakeTitle = XI_ConvertString("Captain");
			rankNation = GetBestRank(xi_refCharacter, &bestRank, rankNation); // add return by levis
		} else {
			if (UsableOfficer(xi_refCharacter))	GameInterface.strings.OfficerType = XI_ConvertString(GetAttribute(xi_refCharacter, "quest.officertype"));
			else GameInterface.strings.OfficerType = "";
			rankNation = sti(xi_refCharacter.nation);
			if (IsTrader(xi_refCharacter)) { // KK
				GameInterface.strings.fakeTitle = XI_ConvertString("trader");
				GameInterface.strings.OfficerType = XI_ConvertString("Captain");
			} else {
				if (IsCompanion(xi_refCharacter)) {
					GameInterface.strings.fakeTitle = XI_ConvertString("Companion");
					GameInterface.strings.OfficerType = XI_ConvertString("Captain");
					bestRank = GetRank(xi_refCharacter, rankNation);
				} else {
					if (IsPrisoner(xi_refCharacter)==true) { // KK
						if(xi_refCharacter.sex=="woman")
							GameInterface.strings.fakeTitle = XI_ConvertString("she_prisoned");  // added by MAXIMUS
						else
							GameInterface.strings.fakeTitle = XI_ConvertString("Captive");  // added by MAXIMUS
					} else {
						if(CheckAttribute(xi_refCharacter, "quest.officertype"))
							GameInterface.strings.fakeTitle = XI_ConvertString("Officer");
						else
							GameInterface.strings.fakeTitle = XI_ConvertString("Passenger");
						bestRank = GetRank(xi_refCharacter, rankNation);
					}
				}
			}
		}
	}

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_OFFICER_EXIT;

	DeleteAttribute(MainChar,"tempCharactersList");
	DeleteAttribute(MainChar, "CharacterInterface_ViewEncOfficer");

	CharInterfaceExit(true);
}

void CharInterfaceExit(bool flag)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","ProcessFrame");

	//WriteNewData();
    EndCancelInterface(flag);
	if(flag) { if(CheckAttribute(GetMainCharacter(),"AnyCharacterShow")) { DeleteAttribute(GetMainCharacter(),"AnyCharacterShow"); } }
}

int SetAlphaIntoColor(int col, int alpha)
{
	int newCol = and(col,16777215) + shl(alpha,24);
	return newCol;
}

int GetAlphaFromSkill(int nskill)
{
   return makeint(255-(MAX_CHARACTER_SKILL-nskill)*20*(10/MAX_CHARACTER_SKILL));
}

void SetSkillShow(string skillName)
{
	int skillPoints = sti(xi_refCharacter.Skill.(skillName));
	// Currently, officers do not possess items modifying
	// their skills. If changing this, enable the second value again.
	// (do not forget to uncomment the call to UpdateSkillValue in the
	// InitInterface_R method, too)
	GameInterface.strings.(skillName) = skillPoints; //+ " - " + CalcCharacterSkill(&xi_refCharacter, skillName);
	int color = COLOR_NORMAL;
	if(skillPoints == SKILL_MAX)
		color = COLOR_MONEY;
	ChangeStringColor(skillName, SetAlphaIntoColor(color, GetAlphaFromSkill(skillPoints)));
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	if(nodName == "B_ABILITIES" && comName=="click")
	{
		GameInterface.AbilityChr = xi_refCharacter.index;
		PostEvent("LaunchIAfterFrame",1,"sl", "AbilityView", 1);
		interfaceResultCommand = RC_INTERFACE_OFFICER_EXIT;
		CharInterfaceExit(false);
		return;
	}

	// Aconcagua: rest of functionality deleted, was not necessary
	// (resulted from copying from character.c)
}

void ProcessFrame()
{
	// Aconcagua: functionality deleted, was not necessary
	// (resulted from copying from character.c)
}
