/* =========================================================================================
	TIH - Aug24'06
	A bit of surgury. Ok, a lot.

	Added the ability to restrict the dialog direction for special types of captains.
	Added a section for accepting all crew without the action of hiring as well.
	Moved some sections around to better 'group' them in the code file.
	Taking and setting crew quantity has been moved here from reinit.c - MAXIMUS

	It isn't right to allow the player to "hire" or "release" certain captains that 
	should be killed, or imprisoned. As such, there is a flag that can be set depending 
	on the "boarding_enemy" id (or any other criteria you want to do). It does not use 
	the "NPChar" attributes, as those are pulled from an innadequate character variable.

============================================================================================ */
void ProcessDialogEvent()
{
	ref NPChar, tmpChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);

	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	string NPC_Meeting, blade, gun, cuirass, reload_locator, old;
	string talk, respect_type;
	string sLogTitle, sLogEntry;
	int iNation = sti(NPChar.nation);
	string pNation = XI_ConvertString("p"+GetNationNameByType(iNation));
	if(GetNationNameByType(iNation)=="no nation") pNation = XI_ConvertString("pPirate");
	if(GetNationNameByType(iNation)=="Pirates") pNation = XI_ConvertString("pPirate");

	ref PChar = GetMainCharacter();
	int prisonRansomCost = GetCharacterMoney(NPChar);
	int crewCaptured = GetMaxCrewQuantity(&PChar) - GetCrewQuantity(PChar);
	int survivors = GetCrewQuantity(boarding_enemy);
	int allpeople = GetCrewQuantity(PChar) + GetCrewQuantity(boarding_enemy);
	int i;

	bool bIsNavy = false;
	bool bIsPrivateer = false;
	bool bIsHonourable = false;
	bIsHonourable = (GetCharacterReputation(PChar) >= REPUTATION_GOOD);
	if(GetCurrentFlag() != PIRATE)
	{
		if(ProfessionalNavyNation() != UNKNOWN_NATION && ProfessionalNavyNation() == GetCurrentFlag()) bIsNavy = true;
		if(ProfessionalNavyNation() == UNKNOWN_NATION && HaveLetterOfMarque(GetCurrentFlag())) bIsPrivateer = true;
	}
	if(!CheckAttribute(PChar, "executions")) PChar.executions = 0;

	if(!CheckAttribute(NPChar,"money")) NPChar.money = makeint(rand(100));
	if(!CheckAttribute(NPChar,"shipmoney")) NPChar.shipmoney = 0; // PB: Prevent missed attribute error on capturing mutinous companions
	if(!CheckAttribute(NPChar,"wealth"))
	{
	    switch(Rand(5))
	    {
			case 0: NPChar.wealth = makeint(sti(NPChar.money)*2.3); break;
			case 1: NPChar.wealth = makeint(sti(NPChar.money)*3.3); break;
			case 2: NPChar.wealth = makeint(sti(NPChar.money)*4.3); break;
			case 3: NPChar.wealth = makeint(sti(NPChar.money)*5.3); break;
			case 4: NPChar.wealth = makeint(sti(NPChar.money)*6.3); break;
			case 5: NPChar.wealth = makeint(sti(NPChar.money)*7.3); break;
	    }
	}
	// TIH --> allowing and disallowing certain things Aug24'06 // KK -->
	bool bAllowHireJoin = FindFreeRandomOfficer()!=-1;
	bool bAllowRelease  = true;
	bool bAllowCapture  = HasSubStr(NPChar.id,"Enc_CabinCaptain") || strcut(NPChar.id,0,1) == "Cr"; // PB: Allow Coast Raiders also
	if(!bAllowCapture)
	{
		bAllowCapture = HasSubStr(NPChar.id,"fantom")&&FindFreeCabinCaptain()!=-1;
	}
	if(CheckAttribute(NPChar,"cabinfight") && sti(NPChar.cabinfight)==true) { bAllowCapture = FindFreeCabinCaptain()!=-1; } /* fantoms allow anything */ //MAXIMUS 10.10.2007

	if(CheckAttribute(boarding_enemy,"location.norebirth") && sti(boarding_enemy.location.norebirth)==1) { bAllowHireJoin = true; bAllowRelease = false; bAllowCapture = true; } /* special captains must die */
	if(CheckAttribute(boarding_enemy,"questchar") && sti(boarding_enemy.questchar)==true) { bAllowHireJoin = false; bAllowRelease = false; bAllowCapture = true; } /* quest allows capture */ //MAXIMUS: special identifier added into tempquest- and storycharacters init
	if(CheckAttribute(boarding_enemy,"canhire") && sti(boarding_enemy.canhire) == true && FindFreeRandomOfficer()!=-1) bAllowHireJoin = true;

	if(GetPassengersQuantity(PChar) >= PASSENGERS_MAX) { bAllowHireJoin = false; bAllowCapture = false; } // no room for them!
	if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) == 1 || CheckAttribute(PChar, "isnotcaptain")) { bAllowHireJoin = false; }
	// TIH <-- // <-- KK

	bool bDeathFight, bAllowCompanion;//MAXIMUS
//MAXIMUS: [if your crew and enemy's crew will be enough for two minimum crews, you will be able to take him as companion] -->
	if(GetCrewQuantity(boarding_enemy)<GetMinCrewQuantity(boarding_enemy))
	{
		if(sti(GetCrewQuantity(PChar)) - (sti(GetMinCrewQuantity(boarding_enemy)) - sti(GetCrewQuantity(boarding_enemy)))>GetMinCrewQuantity(PChar)) { bAllowCompanion = bAllowHireJoin; }
		else { bAllowCompanion = false; }
	}
	else
	{
		if(GetCrewQuantity(PChar)<GetMinCrewQuantity(PChar))
		{
			if(sti(GetCrewQuantity(boarding_enemy)) - (sti(GetMinCrewQuantity(PChar)) - sti(GetCrewQuantity(PChar)))>GetMinCrewQuantity(boarding_enemy)) { bAllowCompanion = bAllowHireJoin; }
			else { bAllowCompanion = false; }
		}
		else { bAllowCompanion = bAllowHireJoin; }
	}
//MAXIMUS: [if your crew and enemy's crew will be enough for two minimum crews, you will be able to take him as companion] <--

//MAXIMUS: [if enemy captain is stronger than player, you'll fight with him] -->
	if(makeint(CalcCharacterSkill(PChar, "Leadership")+CalcCharacterSkill(PChar, "Fencing")+CalcCharacterSkill(PChar, "Grappling"))>=makeint(CalcCharacterSkill(NPChar, "Leadership")+CalcCharacterSkill(NPChar, "Fencing")+CalcCharacterSkill(NPChar, "Grappling")))
	{
/*		if(CheckAttribute(boarding_enemy,"fight") && sti(boarding_enemy.fight)==1) bDeathFight = true;// if captain was created as fantom, but not by CreateTwinCharacter
		else
		{*/
			if(IsCharacterPerkOn(PChar, "SwordplayProfessional") && IsCharacterPerkOn(PChar, "IronWill")) bDeathFight = false;
			else
			{
				if(IsCharacterPerkOn(NPChar, "SwordplayProfessional") && IsCharacterPerkOn(NPChar, "IronWill")) bDeathFight = true;
				else bDeathFight = false;
			}
//		}//MAXIMUS: eliminated, because we can make a proper officer from any fantom
	}
	else { bDeathFight = true; }

	if (!CheckAttribute(NPChar,"questchar") && !CheckAttribute(NPChar,"reputation"))
	{
		NPChar.reputation = rand(20) + rand(20) + rand(20) + rand(20) + 5;	// If reputation not already set, this should give a random number between 5 and 85, biased towards average of 45 i.e. neutral
trace("No reputation was assigned. Randomly assigning reputation " + NPChar.reputation);
	}

	if(GetCharacterShipClass(PChar) < (GetCharacterShipClass(boarding_enemy) - 1))	// GR: Enemy will surrender if your ship is at least 2 tiers bigger than his
	{
		bDeathFight = false;
	}
	if(HasSubStr(PChar.location, "shipdeck"))					// GR: Enemy will surrender if you're on deck, meaning the ship struck her colours before you boarded,
	{										// and if the captain is honourable - good reputation and not a pirate
		if(NPChar.nation != PIRATE && GetCharacterReputation(NPChar) >= REPUTATION_GOOD)
		{
			bDeathFight = false;
		}
	}
	if(GetCharacterShipClass(boarding_enemy) < (GetCharacterShipClass(PChar) - 1))	// GR: Enemy will NOT surrender if his ship is at least 2 tiers bigger than yours - if you want such a ship, you must fight for it!
	{
		bDeathFight = true;
	}

	if(IsUsedAlliesModel(NPChar)) { bDeathFight = true; }//MAXIMUS: ally's twin will always be agressive [twin officers looks strange, not so?]
//MAXIMUS: [if enemy captain is stronger than player, you'll fight with him] <--
	if (strlower(GetAttribute(NPChar, "id")) == "quest trader") bDeathFight = true;	// GR: merchant whom you escorted and betrayed hates you
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\017";

			RestoreAlwaysRunState();		// LDH 03Sep06

			// PB: Prevent breaks inside dialog switch case -->
			int dialog_switch = 0;
			if (NPChar.ship.type == "HMS Interceptor")		dialog_switch = 1;
			if (NPChar.id == "Dark Captain")				dialog_switch = 2;
			if (NPChar.id == "Robert Christopher Silehard")	dialog_switch = 3;
			// PB: Prevent breaks inside dialog switch case <--
			switch(dialog_switch)
			{
				// SJG for Interceptor capture
				case 1:
					dialog.text = DLG_TEXT[109];
					link.l1 = DLG_TEXT[110];
					link.l1.go = "Norrington";
				break;

				// CTM for Sao Feng sidequest
				case 2:
					Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy: at least I think I added this
					dialog.Text = DLG_TEXT[115];
					Link.l1 = DLG_TEXT[93];
					Link.l1.go = "exit_dark";
				break;

				case 3:
					dialog.Text = DLG_TEXT[116] + GetMyFullName(PChar) + DLG_TEXT[117];
					link.l1 = DLG_TEXT[118];
					link.l1.go = "take_as_prisoner";
					link.l2 = DLG_TEXT[119];
					if (CalcCharacterSkill(pchar, SKILL_FENCING) < 9)
					{
						link.l2.go = "kill_them_all";
					}
					else
					{
						link.l2.go = "exit_sharks";
					}
				break;

				if(bDeathFight)
				{// added by MAXIMUS 26.08.2006 [if enemy captain is stronger than player, you'll fight with him] -->
					if(CheckAttribute(NPChar,"wealth")) NPChar.money = sti(NPChar.money) + sti(NPChar.wealth);
					ref shipRef = GetShipByType(GetCharacterShipType(NPChar));
					string shipType = XI_ConvertString(shipRef.Sname);
					string checkSex = DLG_TEXT[102];
					if(PChar.sex=="woman") { checkSex = DLG_TEXT[106]; }
					if(NPChar.nation == PIRATE || GetCharacterReputation(NPChar) <= (REPUTATION_RASCAL + REPUTATION_SWINDLER)/2)	// Enemy is evil or pirate, so use original insults
					{
						switch(Rand(2))
						{
							case 0: dialog.Text = DLG_TEXT[94] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + "." + DLG_TEXT[95]; break;
							case 1: dialog.Text = GetMySimpleName(PChar) + checkSex; break;
							case 2: dialog.Text = DLG_TEXT[103] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[104]; break;
						}
						switch(Rand(2))
						{
							case 0: Link.l1 = DLG_TEXT[105] + DLG_TEXT[89] + GetMySimpleName(PChar) + DLG_TEXT[90]; break;
							case 1: Link.l1 = DLG_TEXT[91] + GetMySimpleName(PChar) + DLG_TEXT[92]; break;
							case 2: Link.l1 = DLG_TEXT[93]; break;
						}
					}
					else														// Enemy is not evil or pirate, so needs a reason to fight after surrender
					{
						switch(Rand(2))
						{
							case 0:
								dialog.Text = DLG_TEXT[139] + GetMyLastName(PChar) + DLG_TEXT[140];
								Link.l1 = DLG_TEXT[147];
							break;
							case 1:
								dialog.Text = DLG_TEXT[141] + GetMyLastName(PChar) + DLG_TEXT[142];
								Link.l1 = DLG_TEXT[148];
							break;
							case 2:
								if(CheckAttribute(NPChar, "id") && GetCharacterShipClass(boarding_enemy) < (GetCharacterShipClass(PChar) - 1))
								{
									dialog.TEXT = DLG_TEXT[144] + shipType + " " + GetMyShipNameShow(NPChar) + DLG_TEXT[145] + GetMyLastName(PChar) + DLG_TEXT[146];
									Link.l1 = DLG_TEXT[150];
								}
								else
								{
									dialog.Text = DLG_TEXT[143];
									Link.l1 = DLG_TEXT[149];
								}
							break;
								
						}
					}

					if (strlower(GetAttribute(NPChar, "id")) == "quest trader")	// GR: Captains of betrayed merchants get their own dialog
					{
						switch(Rand(2))
						{
							case 0:
								dialog.Text = DLG_TEXT[152];
								Link.l1 = DLG_TEXT[153];
							break;

							case 1:
								dialog.Text = DLG_TEXT[154] + GetMyLastName(PChar) + "?";
								Link.l1 = DLG_TEXT[155];
							break;

							case 2:
								dialog.Text = DLG_TEXT[156];
								Link.l1 = DLG_TEXT[157];
							break;
						}
					}

					if (makeint(PChar.rank) >= 15 && Rand(19) == 0)	// GR: Occasionally the captain will use a line from "Moby Dick" / "Wrath of Khan"
					{
						dialog.Text = DLG_TEXT[138];
						Link.l1 = DLG_TEXT[151];
					}
					Link.l1.go = "kill_captain";
				}
				else
				{// added by MAXIMUS 26.08.2006 [if enemy captain is stronger than player, you'll fight with him] <--
					if(NPChar.nation!=PIRATE)
					{
						if(NPChar.nation==GetServedNation())	// of the same nation
						{
							switch(Rand(2))
							{
								case 0: dialog.Text = DLG_TEXT[0] + XI_ConvertString("3"+GetNationNameByType(iNation)) + DLG_TEXT[1]; break;
								case 1: dialog.Text = DLG_TEXT[2] + XI_ConvertString("3"+GetNationNameByType(iNation)) + DLG_TEXT[3]; break;
								case 2: dialog.Text = DLG_TEXT[4] + XI_ConvertString("3"+GetNationNameByType(iNation)) + DLG_TEXT[5]; break;
							}
							link.l1 = MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[10];
							link.l1.go = "money";
							link.l2 = DLG_TEXT[12];
							link.l2.go = "kill_them_all";
							if(GetCrewQuantity(PChar)<GetMaxCrewQuantity(PChar)/2)
							{
								link.l3 = DLG_TEXT[84];
								link.l3.go = "Exit_sharks";
							}
							link.l4 = DLG_TEXT[13] + MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[14];
							link.l4.go = "take_crewmembers";
							if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
							{
								link.l5 = DLG_TEXT[77];
								link.l5.go = "be_companion";
							}
							link.l6 = DLG_TEXT[21] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false) + ".";
							link.l6.go = "talk";
						}
						else // different nation
						{
							switch(Rand(2))
							{
								case 0: dialog.Text = DLG_TEXT[6]; break;
								case 1: dialog.Text = DLG_TEXT[7]; break;
								case 2: dialog.Text = DLG_TEXT[8] + XI_ConvertString("3"+GetNationNameByType(iNation)) + DLG_TEXT[9]; break;
							}
							if(!bIsNavy)			// Naval officers shouldn't be looting money
							{
								link.l1 = DLG_TEXT[13] + MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[14];
								link.l1.go = "money";
							}
						//	if(bIsHonourable || bIsNavy || bIsPrivateer)
						//	{
								link.l2 = DLG_TEXT[125];
								link.l2.go = "honourable_surrender";
						//	}
							link.l3 = DLG_TEXT[15];
							link.l3.go = "kill_them_all";
							if(GetCrewQuantity(PChar)<GetMaxCrewQuantity(PChar)/2)
							{
								link.l4 = DLG_TEXT[84];
								link.l4.go = "Exit_sharks";
							}
							link.l5 = DLG_TEXT[16];
							link.l5.go = "take_crewmembers";
							if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
							{
								link.l6 = DLG_TEXT[77];
								link.l6.go = "be_companion";
							}
							link.l7 = DLG_TEXT[21] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false) + ".";
							link.l7.go = "talk";
						}
					}
					else // pirates
					{
						if(NPChar.sex == "woman") NPChar.greeting = "Gr_Pirate_f";		// LDH 16Oct06 add female pirate greetings

						// LDH 17Oct06 - Oops, someone put rand(2) (which gives 3 choices) but only left 2 choices
						switch(Rand(1))		// LDH 17Oct06 changed Rand(2) to Rand(1) to fix dialog not starting automatically
						{
							case 0: dialog.Text = DLG_TEXT[17] + XI_ConvertString("capPirate") + DLG_TEXT[18] + DLG_TEXT[107] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)+"?"; break;
							case 1: dialog.Text = DLG_TEXT[19] + XI_ConvertString("capPirate") + DLG_TEXT[20] + DLG_TEXT[107] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)+"?"; break;
						}
						link.l1 = DLG_TEXT[13] + MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[14];
						link.l1.go = "money";
						link.l2 = DLG_TEXT[125];
						link.l2.go = "honourable_surrender";
						link.l3 = DLG_TEXT[15];
						link.l3.go = "kill_them_all";
						if(GetCrewQuantity(PChar)<GetMaxCrewQuantity(PChar)/2)
						{
							link.l4 = DLG_TEXT[84];
							link.l4.go = "Exit_sharks";
						}
						link.l5 = DLG_TEXT[16];
						link.l5.go = "take_crewmembers";
						if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
						{
							link.l6 = DLG_TEXT[77];
							link.l6.go = "be_companion";
						}
						link.l7 = DLG_TEXT[21] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false) + ".";
						link.l7.go = "talk";
					}
				}//MAXIMUS
			}
			NextDiag.TempNode = "first time";
		break;

		case "talk":
			dialog.text = "...?";

			link.l1 = DLG_TEXT[23] + MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[24];
			link.l1.go = "money";
			
			if (bAllowRelease) //PW protect quest captains from being released for perk when part of kill requirement of quest
			{
				if(CheckCharacterPerkLocked(Pchar, "Turn180") || CheckCharacterPerkLocked(Pchar, "LongRangeGrappling") || CheckCharacterPerkLocked(Pchar, "ImmediateReload"))
				{
					link.l3 = DLG_TEXT[120];
					link.l3.go = "UnlockPerkCharacter";
				}
			}
			if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
			{
				link.l2 = DLG_TEXT[22];
				link.l2.go = "officer";
			}
		break;

		case "officer":
			if(CalcCharacterSkill(NPChar,SKILL_LEADERSHIP)>CalcCharacterSkill(PChar,SKILL_LEADERSHIP))
			{
				dialog.text = PersuasionFailure + DLG_TEXT[25] + pNation + DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "kill";// pissy captains get dead! lol
			}
			else 
			{
				dialog.text = PersuasionSuccess + DLG_TEXT[28] + pNation + DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "ShowSkills";
				link.l2 = DLG_TEXT[31];
				link.l2.go = "Exit";
			}
		break;

		case "officer_crew":
			if(sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar)) // MAXIMUS 28.07.2006 -->
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + crewCaptured;
				boarding_enemy.ship.Crew.Quantity = sti(boarding_enemy.ship.Crew.Quantity) - crewCaptured;
			}
			else
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + sti(boarding_enemy.ship.Crew.Quantity);
				boarding_enemy.ship.Crew.Quantity = 0;
			} // MAXIMUS 28.07.2006 [so, these sections were removed from Reinit.c] <--
			bCrewCaptured = true;// sets a global
			realCrew = GetCrewQuantity(PChar);
			if(CalcCharacterSkill(NPChar,SKILL_LEADERSHIP)>CalcCharacterSkill(PChar,SKILL_LEADERSHIP))
			{
				dialog.text = PersuasionFailure + DLG_TEXT[25] + pNation + DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "kill";// pissy captains get dead! lol
			}
			else 
			{
				dialog.text = PersuasionSuccess + DLG_TEXT[28] + pNation + DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "ShowSkills";
				link.l2 = DLG_TEXT[31];
				link.l2.go = "Exit";
			}
		break;

		case "ShowSkills":
			// Aconcagua: LaunchOfficer uses separate interface now
			//PChar.CharacterInterface_ViewEncOfficer = true;
			NextDiag.CurrentNode = "ReturnfromSkillview";
			NPChar.quest.meeting = NPC_Meeting;
			Pchar.Quest.Last_Enc_Officer = NPChar.Index;
			DialogExit();
			LaunchOfficer(NPChar);
		break;

		case "ReturnfromSkillview":
			NextDiag.TempNode = "First time";
			if(NPChar.sex != "woman")
			{
				switch(sti(NPChar.nation))
				{
					case ENGLAND: NPChar.greeting = "Gr_Herald"; break;
					case FRANCE: NPChar.greeting = "Gr_Amiel Berangere"; break;
					case SPAIN: NPChar.greeting = "Gr_Jaoquin de masse"; break;
					case PIRATE: NPChar.greeting = "Gr_camilo machado"; break;
					case HOLLAND: NPChar.greeting = "Gr_Dutch Officer"; break;
					case PORTUGAL: NPChar.greeting = "Gr_witness-dialog"; break;
				}
				switch(LanguageGetLanguage())//MAXIMUS: temporary added. I must found proper sounds for each nation -->
				{
					case "French": break;
					case "German": break;
					case "English": break;
					case "Russian": NPChar.greeting = "Gr_Officer_m common"; break;
					case "Spanish": break;
				}//MAXIMUS: temporary added. I must found proper sounds for each nation <--
			}
			else
			{
				switch(sti(NPChar.nation))
				{
					case ENGLAND: NPChar.greeting = "Gr_greenford_citizen_01"; break;
					case FRANCE: NPChar.greeting = "Gr_Sylvie Bondies"; break;
					case PIRATE: NPChar.greeting = "Gr_greenford_citizen_01"; break;
					case HOLLAND: NPChar.greeting = "Gr_Tanneken Oremans"; break;
					NPChar.greeting = "Gr_f_officer";
				}
				switch(LanguageGetLanguage())//MAXIMUS: temporary added. I must found proper sounds for each nation -->
				{
					case "French": break;
					case "German": break;
					case "English": break;
					case "Russian": NPChar.greeting = "Gr_Officer_f common"; break;
					case "Spanish": break;
				}//MAXIMUS: temporary added. I must found proper sounds for each nation <--
			}
			switch(Rand(2))
			{
			    case 0: dialog.Text = DLG_TEXT[32]; break;
				case 1: dialog.Text = DLG_TEXT[33]; break;
				case 2: dialog.Text = DLG_TEXT[34]; break;
			}
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "price";
			Link.l2 = DLG_TEXT[36];
			Link.l2.go = "Exit_not_hire";
		break;

		case "Exit_not_hire":
			NPChar.greeting = "Gr_Clauss"; // was "Gr_Dark Teacher" which is identical
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "price":
//			dialog.Text = DLG_TEXT[37] + NPChar.quest.OfficerPrice + DLG_TEXT[38];
			dialog.Text = DLG_TEXT[37] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[38];	// LDH 16Apr09
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[40];
			Link.l2.go = "hire";
			Link.l3 = DLG_TEXT[41];
			Link.l3.go = "Exit_not_hire";
		break;

		case "trade":
			int ptest, ntest;
			ptest = 2+(CalcCharacterSkill(PChar,SKILL_COMMERCE)*1.5 + CalcCharacterSkill(PChar,SKILL_LEADERSHIP) + Rand(CalcCharacterSkill(PChar, SKILL_SNEAK)-1)+1)/2;
			ntest = GetLevel(NPChar)/5 + Rand(CalcCharacterSkill(NPChar,SKILL_COMMERCE)*2 + CalcCharacterSkill(NPChar,SKILL_LEADERSHIP) + CalcCharacterSkill(NPChar,SKILL_SNEAK)-4)+4;
			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
			{
				if(ptest >= ntest && makeint(NPChar.quest.OfficerPrice) >= GetLevel(NPChar)*100 + ptest*16)
				{
					NPChar.quest.OfficerPrice = makeint(NPChar.quest.OfficerPrice) - ptest*16;
	//				dialog.Text = DLG_TEXT[42] + NPChar.quest.OfficerPrice + DLG_TEXT[38];
					dialog.Text = PersuasionSuccess + DLG_TEXT[42] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[38];		// LDH 16Apr09
					Link.l1 = DLG_TEXT[43];
					Link.l1.go = "hire";
				}
				else
				{
					dialog.Text = PersuasionFailure + DLG_TEXT[44];
					Link.l1 = DLG_TEXT[40];
					Link.l1.go = "hire";
				}
			}
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "Exit_not_hire";
		break;

		case "hire":
			// LDH 16Apr09 -->
			int OfficerPrice = CalcEncOfficerPrice(NPChar);
			// This really needs a branch if the player doesn't have enough money to hire this guy
//			if(makeint(PChar.money) >= OfficerPrice)
//			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -OfficerPrice);
  				AddWealthToCharacter(NPChar, OfficerPrice);
//			}
			// LDH <--
/* original code
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -(makeint(NPChar.quest.OfficerPrice)));
			AddMoneyToCharacter(NPChar, makeint(NPChar.quest.OfficerPrice));
*/
			dialog.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46] + " " + DLG_TEXT[85];
			Link.l1.go = "exit_joined";// TIH do a common end action instead
		break;

		case "be_companion":
			int myPower = sti(CalcCharacterSkill(PChar,SKILL_LEADERSHIP) + CalcCharacterSkill(PChar,SKILL_SNEAK) + CalcCharacterSkill(PChar,SKILL_FENCING) + CalcCharacterSkill(PChar,SKILL_CANNONS));
			int enPower = sti(CalcCharacterSkill(NPChar,SKILL_LEADERSHIP) + CalcCharacterSkill(NPChar,SKILL_SNEAK) + CalcCharacterSkill(NPChar,SKILL_FENCING) + CalcCharacterSkill(NPChar,SKILL_CANNONS));
			if(myPower<enPower)
			{
				Preprocessor_Add("gender", GetCharacterAddressForm(PChar, ADDR_GENDER, false, false)); // DeathDaisy
				dialog.text = PersuasionFailure + DLG_TEXT[80];
				link.l1 = DLG_TEXT[81];
				link.l1.go = "officer";
				link.l2 = DLG_TEXT[21] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false) + ".";
				link.l2.go = "talk";
			}
			else
			{
				dialog.text = PersuasionSuccess + DLG_TEXT[78];
				link.l1 = DLG_TEXT[79];
				// link.l1.go = "Exit_companion";
				link.l1.go = "exit_joined"; // Sulan 2010-06-12: Exit_companion causes CTD - reason so far unknown.
				// Unless that is fixed and properly tested, please use this workaround
				link.l2 = DLG_TEXT[31];
				link.l2.go = "talk";
			}
		break;

		case "Exit_companion":// rewritten by MAXIMUS [if line [link.l1.go = "Exit_companion"] will be commented out - this case will be inaccessible]-->
			int j = 1;
			while(GetCompanionIndex(PChar,j)>=0) j++;
			if(j>=COMPANION_MAX)
			{
				dialog.text = DLG_TEXT[87];
				link.l1 = DLG_TEXT[88];
				link.l1.go = "officer";
				link.l2 = DLG_TEXT[21] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false) + ".";
				link.l2.go = "talk";
			}
			else
			{
				LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
				NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
				NPChar.Dialog.CurrentNode = "hired";

				TIH_OfficerHiredProcess(NPChar, false, false, true, true, !UsableOfficer(NPChar));// bLowSalary, bAutoAssign, bPurgeCrud, bSetType, bCreateOfficer
				int tmpIdx = GetCharacterIndex(NPChar.id);

				Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));

				NPChar.wealth = sti(NPChar.wealth)/2;
				NPChar.nation = GetCurrentFlag();
				NPChar.location = "none";

// KK -->
				bool bPirated = ShipTaken(tmpIdx, KILL_BY_ABORDAGE, tmpIdx); // Stone-D 19/07/2003
				//SwapCabinChests(tmpIdx, sti(NPChar.index));
				//ISetShipAttributes(NPChar); // copy ship from enemy to companion officer
				DeleteAttribute(NPChar,"ship");
				aref arToChar;	makearef(arToChar,NPChar.ship);
				aref arFromChar;	makearef(arFromChar,boarding_enemy.ship);
				CopyAttributes(arToChar,arFromChar);
				SeaAI_SetOfficer2ShipAfterAbordage(NPChar, NPChar);
				// PB: Method of acquiring ship influences sale price -->
				// Inspired by TIH's rpgstyle shipyard (Jul27'06)
				if (bPirated)	NPChar.ship.acquired = "pirated";
				else			NPChar.ship.acquired = "taken";
				// PB: Method of acquiring ship influences sale price <--
				/*LAi_SetCurHP(NPChar, 0.0);
				NPChar.Killer.Status = KILL_BY_ABORDAGE;
				NPChar.Killer.Index = GetMainCharacterIndex();
				NPChar.Ship.HP = 0;*/ // TIH kill the enemy ship (its been copied to officer by now, helps with quests) Aug27'06
				PostEvent("evntQuestsCheck",1);
// <-- KK

				DialogExit();
				//transferCaptain = true;
				bCaptureShip = true;
				boarding_enemy.status = "live";
				boarding_enemy.position = "companion";
				if(CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
				LAi_EnableReload();// manual reload (allows looting of cabin before leaving)
			}
		break;// rewritten by MAXIMUS <--

		case "money":
			if(NPChar.nation!=PIRATE)						// GR: Naval officers and privateers aren't supposed to rob non-pirate prisoners, so delay their promotions
			{
				if(bIsPrivateer || bIsNavy)
				{
					for(i = 0;  i < MAX_NATIONS; i++)
					{
						if(HaveLetterOfMarque(i) && i != PIRATE)
						{
							if(GetRMRelation(PChar, i) >= (REL_NEUTRAL + 1.0)) ChangeRMRelation(PChar, i, -1.0);
							else SetRMRelation(PChar, i, REL_NEUTRAL);	// GR: But don't kick them out of the service for such a minor offence
						}
					}
				}
			}

			switch(Rand(2))
		    	{
				case 0: talk = DLG_TEXT[55]; break;
				case 1: talk = DLG_TEXT[56]; break;
				case 2: talk = DLG_TEXT[57]; break;
			}
			dialog.text = DLG_TEXT[47] + talk;
			
			// if not enough room for all the survivors
		    if(survivors > 0 && sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar))
		    {
		    	// no room for ANY survivors
				if(sti(PChar.ship.Crew.Quantity) >= GetMaxCrewQuantity(&PChar))
				{
					if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
					{
						link.l1 = DLG_TEXT[72] + DLG_TEXT[101];
						link.l1.go = "be_companion";
					}
					else
					{
						link.l1 = DLG_TEXT[83];
						link.l1.go = "we_want_to_live";
					}
				}
				// else only enough room for some survivors
				else
				{
					link.l1 = DLG_TEXT[48] + crewCaptured + DLG_TEXT[49];
					link.l1.go = "we_want_to_live";
				}
			}
			// else there is enough room for ALL survivors (if any)
			else 
			{
				if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[53] + survivors + DLG_TEXT[54];
						link.l1.go = "officer_crew";
					}
					else
					{
						if(bCrewCaptured==true) link.l1 = DLG_TEXT[86];
						else link.l1 = DLG_TEXT[62];
						link.l1.go = "officer";
					}
				}
				else
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[96] + survivors + ".";
						link.l1.go = "accept_all_crew";
					}
				}
			}
			link.l2 = DLG_TEXT[15];
			link.l2.go = "kill_them_all";
			if (bAllowRelease) { // KK allow releasing
				link.l3 = DLG_TEXT[52];
				link.l3.go = "possibility_to_release";
			}
			if(bAllowCapture) // TIH allow to take as prisoner Aug24'06
			{
				Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(NPChar)));
				link.l4 = DLG_TEXT[76];
				link.l4.go = "take_as_prisoner";
			}
		break;

		case "honourable_surrender":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
			string NPSword, NPGun, stuff_given;
			int stuff_idx;
			int diffoffset = GetDifficulty();
			int rank = sti(PChar.rank);
			stuff_given = "";

			respect_type = DLG_TEXT[136];
			if(bIsHonourable) respect_type = DLG_TEXT[126] + DLG_TEXT[127];
			if(bIsPrivateer) respect_type = DLG_TEXT[126] + DLG_TEXT[129];
			if(bIsNavy) respect_type = DLG_TEXT[126] + DLG_TEXT[128];

			NPChar.honourable_surrender = true;	// Set attribute which can be checked by prisoner dialog
			ChangeCharacterReputation(PChar, 1);

			NPSword = GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE);
			if(NPSword == "") NPSword = FindCharacterItemByGroup(NPChar, BLADE_ITEM_TYPE);
			if(NPSword == "")
			{
				if(ENABLE_WEAPONSMOD == 1)
				{
					NPSword = GetRandomBladeForLevel(rank-3+diffoffset, rank+diffoffset, 3+(diffoffset/2));
				}
				else
				{
					NPSword = LAi_NPC_EquipBladeSelection(rank);
				}
			}
//			else TakeItemFromCharacter(NPchar, NPSword);

			NPGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(NPGun == "") NPGun = FindCharacterItemByGroup(NPChar, GUN_ITEM_TYPE);
//			if(NPGun != "") TakeItemFromCharacter(NPChar, NPGun);

			if(NPSword != "")
			{
				PlayStereoSound("INTERFACE\important_item.wav");
//				GiveItem2Character(PChar, NPSword);
				stuff_idx = GetItemIndex(NPSword);
				if(stuff_idx >= 0) stuff_given = XI_ConvertString("a") + " " + TranslateString("",Items[stuff_idx].name);
				else stuff_given = "INVALID BLADE '" + NPSword + "'";
			}
			if(NPGun != "")
			{
//				GiveItem2Character(PChar, NPGun);
				stuff_idx = GetItemIndex(NPGUN);
				if(stuff_idx >= 0) stuff_given = stuff_given + " " + XI_ConvertString("and") + " " + XI_ConvertString("a") + " " + TranslateString("",Items[stuff_idx].name);
				else stuff_given = stuff_given + ", INVALID GUN '" + NPGun + "'";
			}
			traceandlog(TranslateString("","You got") + " " + stuff_given + ".");

			switch(Rand(1))
		    	{
				case 0: talk = DLG_TEXT[55]; break;
				case 1: talk = DLG_TEXT[56]; break;
		    	}
			dialog.text = respect_type + DLG_TEXT[130] + TranslateString("",Items[GetItemIndex(NPSword)].name) + DLG_TEXT[131] + talk;
			// if not enough room for all the survivors
			if(survivors > 0 && sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar))
			{
				// no room for ANY survivors
				if(sti(PChar.ship.Crew.Quantity) >= GetMaxCrewQuantity(&PChar))
				{
					if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
					{
						link.l1 = DLG_TEXT[72] + DLG_TEXT[101];
						link.l1.go = "be_companion";
					}
					else
					{
						link.l1 = DLG_TEXT[132];
						link.l1.go = "we_want_to_live";
					}
				}
				// else only enough room for some survivors
				else
				{
					link.l1 = DLG_TEXT[133] + crewCaptured + DLG_TEXT[134];
					link.l1.go = "we_want_to_live";
				}
			}
			// else there is enough room for ALL survivors (if any)
			else 
			{
				if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[53] + survivors + DLG_TEXT[54];
						link.l1.go = "officer_crew";
					}
					else
					{
						if(bCrewCaptured==true) link.l1 = DLG_TEXT[86];
						else link.l1 = DLG_TEXT[135];
						link.l1.go = "officer";
					}
				}
				else
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[96] + survivors + ".";
						link.l1.go = "accept_all_crew";
					}
				}
			}
			if (bAllowRelease) { // KK allow releasing
				link.l2 = DLG_TEXT[52];
				link.l2.go = "possibility_to_release";
			}
			if(bAllowCapture) // TIH allow to take as prisoner Aug24'06
			{
				link.l3 = DLG_TEXT[137];
				link.l3.go = "take_as_prisoner";
			}
//			link.l4 = DLG_TEXT[15];	// Not an option after honourable surrender
//			link.l4.go = "kill_them_all";
		break;

		case "take_crewmembers":
			if(survivors > 0) dialog.Text = DLG_TEXT[73] + survivors + DLG_TEXT[74];
			else dialog.Text = DLG_TEXT[75];
			
			// if not enough room for all the survivors
		    if(survivors > 0 && sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar))
		    {
		    	// no room for ANY survivors
				if(sti(PChar.ship.Crew.Quantity) >= GetMaxCrewQuantity(&PChar))
				{
					if(bAllowHireJoin && bAllowCompanion) // TIH allow to hirejoin Aug24'06//MAXIMUS: allow to companion
					{
						link.l1 = DLG_TEXT[72] + DLG_TEXT[101];
						link.l1.go = "be_companion";
					}
					//else
					//{
					//	link.l1 = DLG_TEXT[83];
					//	link.l1.go = "we_want_to_live";
					//}
				}
				// else only enough room for some survivors
				else
				{
					link.l1 = DLG_TEXT[48] + crewCaptured + DLG_TEXT[49];
					link.l1.go = "we_want_to_live";
				}
			}
			// else there is enough room for ALL survivors (if any)
			else 
			{
				if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[53] + survivors + DLG_TEXT[54];
						link.l1.go = "officer_crew";
					}
					else
					{
						if(bCrewCaptured==true) link.l1 = DLG_TEXT[86];
						else link.l1 = DLG_TEXT[62];
						link.l1.go = "officer";
					}
				}
				else
				{
					if(survivors > 0)
					{
						link.l1 = DLG_TEXT[96] + survivors + ".";
						link.l1.go = "accept_all_crew";
					}
				}
			}
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "kill_them_all";
			if (bAllowRelease) { // KK allow releasing
				Link.l3 = DLG_TEXT[52];
				Link.l3.go = "possibility_to_release";
			}
		break;

		case "accept_all_crew":
//			SetCrewQuantity(PChar, OurCrewChangeProcess(PChar, boarding_enemy));
//			SetCrewQuantity(boarding_enemy, EnemyCrewChangeProcess(PChar, boarding_enemy)); // MAXIMUS 28.07.2006 -->
			if(sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar))
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + crewCaptured;
				boarding_enemy.ship.Crew.Quantity = sti(boarding_enemy.ship.Crew.Quantity) - crewCaptured;
			}
			else
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + sti(boarding_enemy.ship.Crew.Quantity);
				boarding_enemy.ship.Crew.Quantity = 0;
			} // MAXIMUS 28.07.2006 [so, these sections were removed from Reinit.c] <--
			bCrewCaptured = true;// sets a global
			realCrew = GetCrewQuantity(PChar);
			dialog.text = DLG_TEXT[97];
			if(bAllowRelease) // TIH allow to release free Aug24'06
			{
				link.l1 = DLG_TEXT[71];
				link.l1.go = "Exit_release";
			}
			if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
			{
				link.l2 = DLG_TEXT[88];
				link.l2.go = "officer";
			}
			if(bAllowCapture) // TIH allow to take as prisoner Aug24'06
			{
				Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(NPChar)));
				link.l3 = DLG_TEXT[76];
				link.l3.go = "take_as_prisoner";
			}
			link.l4 = DLG_TEXT[99];
			link.l4.go = "possibility_to_release";
			link.l5 = DLG_TEXT[100];
			link.l5.go = "kill_them_all";
		break;

		case "we_want_to_live":
//			SetCrewQuantity(PChar, OurCrewChangeProcess(PChar, boarding_enemy));
//			SetCrewQuantity(boarding_enemy, EnemyCrewChangeProcess(PChar, boarding_enemy)); // MAXIMUS 28.07.2006 -->
			if(sti(PChar.ship.Crew.Quantity) + survivors > GetMaxCrewQuantity(&PChar))
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + crewCaptured;
				boarding_enemy.ship.Crew.Quantity = sti(boarding_enemy.ship.Crew.Quantity) - crewCaptured;
			}
			else
			{
				PChar.ship.Crew.Quantity = sti(PChar.ship.Crew.Quantity) + sti(boarding_enemy.ship.Crew.Quantity);
				boarding_enemy.ship.Crew.Quantity = 0;
			} // MAXIMUS 28.07.2006 [so, these sections were removed from Reinit.c] <--
			realCrew = GetCrewQuantity(PChar);
			dialog.text = DLG_TEXT[69] + sti(boarding_enemy.ship.Crew.Quantity) + DLG_TEXT[70];
			if(bAllowRelease) // TIH allow to release free Aug24'06
			{
				link.l1 = DLG_TEXT[71];
				link.l1.go = "Exit_release";
			}
			if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
			{
				link.l2 = DLG_TEXT[72];
				link.l2.go = "officer";
			}
			if(bAllowCapture) // TIH allow to take as prisoner Aug24'06
			{
				Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(NPChar)));
				link.l3 = DLG_TEXT[76];
				link.l3.go = "take_as_prisoner";
			}
			link.l4 = DLG_TEXT[15];
			link.l4.go = "kill_them_all";
		break;

		case "possibility_to_release":
			dialog.text = DLG_TEXT[58] + MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER) + DLG_TEXT[59];
			if(bAllowRelease) // TIH allow to release free Aug24'06
			{
				link.l1 = DLG_TEXT[60];
				link.l1.go = "Exit_release";
			}
			link.l2 = DLG_TEXT[61];
			link.l2.go = "you_are_liar";
		break;

		case "you_are_liar":
			dialog.text = DLG_TEXT[63];
			if(bAllowHireJoin) // TIH allow to hirejoin Aug24'06
			{
				if(CalcCharacterSkill(NPChar,SKILL_LEADERSHIP)+CalcCharacterSkill(NPChar,SKILL_FENCING)>CalcCharacterSkill(PChar,SKILL_LEADERSHIP)+CalcCharacterSkill(PChar,SKILL_FENCING))
				{
					link.l1 = DLG_TEXT[64];
					link.l1.go = "kill";
				}
				link.l2 = DLG_TEXT[65];
				link.l2.go = "officer";
			} else {
				link.l1 = DLG_TEXT[64];
				link.l1.go = "kill";
			}
		break;

		case "kill":
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[66];
			switch(Rand(1))
			{
				case 0: 
					link.l1 = DLG_TEXT[67];
					link.l1.go = "exit_hanged";
				break;
				case 1: 
					link.l1 = DLG_TEXT[82];
					link.l1.go = "exit_sharks";
				break;
			}
			Link.l2 = DLG_TEXT[68];	
			Link.l2.go = "kill_captain";
			NPC_meeting = "1";
		break;
// SJG>
		case "Norrington":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "Norrington2";
		break;

		case "Norrington2":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "Exit_Norrington";
		break;
// -------------------------- No more dialog beyond this point, it's all actions and exits ----------------------------

		case "exit_joined"://changed by MAXIMUS, because all method was rewritten
		// TIH --> adjusted method Jul19'06
		// instad of trying to autoassign the captain as companion, we simply leave that decision up to the player
		// so instead we move the captian to an officer passenger of the player, and they can elect to assign the 
		// new captain to the ship to salvage the ship (or assign some OTHER officer to the ship, its their choice)
		//=========================================================================================================//
		// MAXIMUS: hmm... My idea was - to leave the captain with his own ship and his own crew - this is right, if we'll think logically, and all dialog says about it
		// Also - this gives to us possibility for some small quests: such as escape of new companion, or his assault, when player will be not prepared, or his assault
		// during sea battle with the ships of his compatriots. IT was my idea... I'll revive it, in course of time.

			NPChar.quest.meeting = NPC_Meeting;
			//Captains have some special perks so let's use them and never generate a new officer out of it. You can later assign them to a role if you want.
			TIH_OfficerHiredProcess(NPChar, false, false, true, false, false);// bLowSalary, bAutoAssign, bPurgeCrud, bSetType, bCreateOfficer
			//DialogMain(NPChar);//MAXIMUS //Levis: why would we need to talk to the guy after hireing automaticly?
			boarding_enemy.status = "live";
			boarding_enemy.position = "officer";
			if(CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_EnableReload();// manual reload (allows looting of cabin before leaving)
			DialogExit();
		// TIH <-- adjusted method
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Dark":
			LAi_SetImmortal(NPChar, false);
			LAi_SetPlayerType(PChar);
			//LAi_SetWarriorType(NPChar);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_BRDENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "talk_on_blood");
			EndQuestMovie();TrackQuestMovie("end","Cabinfight_dialog.c -> kill_captain");
			if(CORPSEMODE<4) { if(CheckAttribute(NPChar,"location")) NPChar.location = "none"; }// MAXIMUS 17.02.2007
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK

			GiveItem2Character(characterFromID("Dark Captain"), "blade13");
			EquipCharacterByItem(characterFromID("Dark Captain"), "blade13");
			GiveItem2Character(characterFromID("Dark Captain"), "pistol2");
			EquipCharacterByItem(characterFromID("Dark Captain"), "pistol2");

			DialogExit();
			LAi_SetFightMode(PChar, true);// MAXIMUS 16.11.2006: prepared for fight
			boarding_enemy.status = "dead";
			boarding_enemy.position = "corpse";
			if(bDeathFight==false) //MAXIMUS: [if player will fight with captain, NPChar.wealth will be NPChar.money]
			{
				if(CORPSEMODE<4)// MAXIMUS 17.02.2007
				{
					Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
					PlayStereoSound("INTERFACE\took_item.wav");
					AddMoneyToCharacter(PChar,sti(NPChar.wealth));
					if(CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
				}
				else
				{
					if(!CheckAttribute(NPChar,"money")) NPChar.money = "0";
					if(!CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
					NPChar.money = sti(NPChar.money) + sti(NPChar.wealth);
					NPChar.wealth = "0";
				}
			}
		break;

		case "kill_them_all":
			if(bIsNavy || bIsPrivateer)
			{
				if(NPChar.nation!=PIRATE && GetServedNation() != PIRATE) Process_Execution(2);
			}
			if (bAllowHireJoin || bAllowRelease || bAllowCapture) ChangeCharacterReputation(PChar, -5); // GR: if you have a choice and choose to execute prisoners, lose rep
			LAi_SetImmortal(NPChar, false);
			LAi_SetPlayerType(PChar);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_BRDENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Abordage_End"); // PB was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
			EndQuestMovie();TrackQuestMovie("end","Cabinfight_dialog.c -> kill_them_all");
			if(CORPSEMODE<4) { if(CheckAttribute(NPChar,"location")) NPChar.location = "none"; }// MAXIMUS 17.02.2007			
/*			if(NPChar.id == "Robert Christopher Silehard")
			{
				GiveItem2Character(characterFromID("Robert Christopher Silehard_SHIP"), "blade25");
				EquipCharacterByItem(characterFromID("Robert Christopher Silehard_SHIP"), "blade25");
				GiveItem2Character(characterFromID("Robert Christopher Silehard_SHIP"), "pistol5");
				EquipCharacterByItem(characterFromID("Robert Christopher Silehard_SHIP"), "pistol5");
			}*/
			DialogExit();
			LAi_SetFightMode(PChar, true);// MAXIMUS 17.02.2007: prepared for fight
			boarding_enemy.Ship.Crew.Quantity = 0;
			boarding_enemy.status = "dead";
			boarding_enemy.position = "corpse";
			if(CORPSEMODE<4)// MAXIMUS 17.02.2007
			{
				Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(PChar,sti(NPChar.wealth));
			}
			else
			{
				if(!CheckAttribute(NPChar,"money")) NPChar.money = "0";
				if(!CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
				NPChar.money = sti(NPChar.money) + sti(NPChar.wealth);
			}
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
		break;

		case "take_as_prisoner"://MAXIMUS: all was moved into TIH_PrisonerTakenProcess
			if (NPChar.id == "Robert Christopher Silehard") NPChar.prisoned = true;	// GR: necessary because talking with replacement governor checks Silehard's "prisoned" attribute.
			NextDiag.CurrentNode = NextDiag.TempNode;
			if(CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			TIH_PrisonerTakenProcess(NPChar, true); // KK
			DialogExit();
		break;

		case "Exit_hanged":
			if(bIsNavy || bIsPrivateer)
			{
				if(NPChar.nation!=PIRATE && GetServedNation() != PIRATE) Process_Execution(1);
			}
			Lai_SetActorType(NPChar);
			LAi_ActorTurnToCharacter(NPChar, PChar);
			LAi_ActorAnimation(NPChar, "afraid","", 10);
			if (IsCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE))
			{
			    blade = GetCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, BLADE_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, blade);
			    GiveItem2Character(PChar, blade);
			}
			if (IsCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE))
			{
			    gun = GetCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, GUN_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, gun);
			    GiveItem2Character(PChar, gun);
			}
			if (IsCharacterEquipByGroup(NPChar,ARMOR_ITEM_TYPE))
			{
			    cuirass = GetCharacterEquipByGroup(NPChar,ARMOR_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, ARMOR_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, cuirass);
			    GiveItem2Character(PChar, cuirass);
			}
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_BRDENEMY);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Abordage_End"); // PB was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);

			boarding_enemy.status = "dead";
			boarding_enemy.position = "corpse";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,sti(NPChar.wealth));
			Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
			bCaptureShip = true;
			object HangFader;
			CreateEntity(&HangFader, "fader");
			SendMessage(&HangFader, "lfl", FADER_IN, 0.5, true);
			StartVideo("Blaze_mutiny_dead");
			DialogExit();
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			PostEvent("LAi_RemoveDeadCap", 20, "i", NPChar);
		break;

		case "Exit_sharks":
			if(bIsNavy || bIsPrivateer)
			{
				if(NPChar.nation!=PIRATE && GetServedNation() != PIRATE) Process_Execution(1);
			}
			Lai_SetActorType(NPChar);
			LAi_ActorTurnToCharacter(NPChar, PChar);
			LAi_ActorAnimation(NPChar, "afraid","", 10);
			if (IsCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE))
			{
			    blade = GetCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, BLADE_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, blade);
			    GiveItem2Character(PChar, blade);
			}
			if (IsCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE))
			{
			    gun = GetCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, GUN_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, gun);
			    GiveItem2Character(PChar, gun);
			}
			if (IsCharacterEquipByGroup(NPChar,ARMOR_ITEM_TYPE))
			{
			    cuirass = GetCharacterEquipByGroup(NPChar,ARMOR_ITEM_TYPE);
			    RemoveCharacterEquip(NPChar, ARMOR_ITEM_TYPE);
			    TakeItemFromCharacter(NPChar, cuirass);
			    GiveItem2Character(PChar, cuirass);
			}
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_BRDENEMY);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Abordage_End"); // PB was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);

			boarding_enemy.status = "dead";
			boarding_enemy.position = "corpse";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,sti(NPChar.wealth));
			Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
			bCaptureShip = true;
			object SharkFader;
			CreateEntity(&SharkFader, "fader");
			SendMessage(&SharkFader, "lfl", FADER_IN, 0.5, true);
			StartVideo("Sharks_attack");
			DialogExit();
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			PostEvent("LAi_RemoveDeadCap", 20, "i", NPChar);
		break;

		case "kill_captain":
			LAi_SetImmortal(NPChar, false);
			LAi_SetPlayerType(PChar);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_BRDENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Abordage_End"); // PB was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
			EndQuestMovie();TrackQuestMovie("end","Cabinfight_dialog.c -> kill_captain");
			if(CORPSEMODE<4) { if(CheckAttribute(NPChar,"location")) NPChar.location = "none"; }// MAXIMUS 17.02.2007
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			if(NPChar.id == "Robert Christopher Silehard")
			{
				GiveItem2Character(characterFromID("Robert Christopher Silehard"), "blade25");
				EquipCharacterByItem(characterFromID("Robert Christopher Silehard"), "blade25");
				GiveItem2Character(characterFromID("Robert Christopher Silehard"), "pistol5");
				EquipCharacterByItem(characterFromID("Robert Christopher Silehard"), "pistol5");
			}
			DialogExit();
			LAi_SetFightMode(PChar, true);// MAXIMUS 16.11.2006: prepared for fight
			boarding_enemy.status = "dead";
			boarding_enemy.position = "corpse";
			if(bDeathFight==false) //MAXIMUS: [if player will fight with captain, NPChar.wealth will be NPChar.money]
			{
				if(CORPSEMODE<4)// MAXIMUS 17.02.2007
				{
					Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
					PlayStereoSound("INTERFACE\took_item.wav");
					AddMoneyToCharacter(PChar,sti(NPChar.wealth));
					if(CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
				}
				else
				{
					if(!CheckAttribute(NPChar,"money")) NPChar.money = "0";
					if(!CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
					NPChar.money = sti(NPChar.money) + sti(NPChar.wealth);
					NPChar.wealth = "0";
				}
			}
		break;

		case "Exit_release":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,sti(NPChar.wealth));
			Log_SetStringToLog(TranslateString("", "CaptainMoney1")+" "+MakeMoneyShow(sti(NPChar.wealth),"",MONEY_DELIVER)+" "+TranslateString("", "CaptainMoney2"));
			if(CheckAttribute(NPChar,"wealth")) NPChar.wealth = "0";
			DialogExit();
			DeleteCharacter(NPChar);
			boarding_enemy.status = "live";
			boarding_enemy.position = "loser";
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_ReloadBoarding();
		break;
		
		case "UnlockPerkCharacter":
			dialog.text = DLG_TEXT[121];
			if(CheckCharacterPerkLocked(Pchar, "Turn180"))
			{
				link.l1 = DLG_TEXT[122];
				link.l1.go = "Exit_release_perk_Turn";
			}
			if(CheckCharacterPerkLocked(Pchar, "LongRangeGrappling"))
			{
				link.l2 = DLG_TEXT[124];
				link.l2.go = "Exit_release_perk_grappling";
			}
			if(CheckCharacterPerkLocked(Pchar, "ImmediateReload"))
			{
				link.l3 = DLG_TEXT[123];
				link.l3.go = "Exit_release_perk_reload";
			}
			link.l4 = DLG_TEXT[15];
			link.l4.go = "kill_them_all";
		break;
		
		case "Exit_release_perk_turn":
			UnlockPerkCharacter(PChar ,"Turn180");
			DialogExit();
			DeleteCharacter(NPChar);
			boarding_enemy.status = "live";
			boarding_enemy.position = "loser";
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_ReloadBoarding();
		break;
		
		case "Exit_release_perk_grappling":
			UnlockPerkCharacter(PChar ,"LongRangeGrappling");
			DialogExit();
			DeleteCharacter(NPChar);
			boarding_enemy.status = "live";
			boarding_enemy.position = "loser";
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_ReloadBoarding();
		break;
		
		case "Exit_release_perk_reload":
			UnlockPerkCharacter(PChar ,"ImmediateReload");
			DialogExit();
			DeleteCharacter(NPChar);
			boarding_enemy.status = "live";
			boarding_enemy.position = "loser";
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_ReloadBoarding();
		break;
//SJG
		case "Exit_Norrington":
			ChangeCharacterAddress(characterFromID("James Norrington"), "none", "");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			boarding_enemy.status = "live";
			boarding_enemy.position = "loser";
			bCaptureShip = true;
			if (CheckAttribute(PChar, "TalkWithSurrenderedCaptain")) DeleteAttribute(PChar, "TalkWithSurrenderedCaptain"); // KK
			LAi_ReloadBoarding();
		break;
	}
}
