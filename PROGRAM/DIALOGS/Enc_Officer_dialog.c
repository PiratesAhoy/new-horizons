void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	aref Type, OldType;
	string NPC_Meeting;
	// MAXIMUS 08.10.2006 ==>
	int ourMoney, ourCrew;
	if(CheckAttribute(PChar,"money")) ourMoney = makeint(PChar.money);
	else ourMoney = 0;
	if(CheckAttribute(PChar,"ship.crew.quantity")) ourCrew = makeint(PChar.ship.crew.quantity);
	else ourCrew = 0;
	// MAXIMUS 08.10.2006 <==
	

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	// JRH fix oct 06 -->
	string weaponID = GetCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE);
	aref weapon;
	Items_FindItem(weaponID, &weapon);
	// <-- JRH
	
	//Levis for smuggling
	string questname = "";
	string patroltime = GetPatrolTimeText(Islands[GetCharacterCurrentIsland(Pchar)], GetBestSmugglingtime(Islands[GetCharacterCurrentIsland(Pchar)],NPChar));
	if(CheckAttribute(Pchar,"amount_smuggleruns")) questname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
	//end Levis
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}

	// RM -->
	if(strcut(Dialog.CurrentNode, 0, 3) == "flag") // changed by MAXIMUS [was Dialog.CurrentNode]
	{
// KK -->
		string ssel = GetSymbol(Dialog.CurrentNode, 4) + GetSymbol(Dialog.CurrentNode, 5);
		int cc;
		int sel_nation = sti(ssel);
		string tstr = XI_ConvertString(GetNationDescByType(sel_nation));
		HoistFlag(sel_nation);
		if (sel_nation == PERSONAL_NATION) tstr = XI_ConvertString("4personal");
		d.Text = DLG_TEXT[48] + tstr + DLG_TEXT[49];
// <-- KK
		Link.l1 = DLG_TEXT[50];
		Link.l1.go = "exit";
		return;
	}
	// RM <--
	// NK -->
	//unneeded due to KAM's select model and this func in scheffnow's models file
	/*if(strlen(Dialog.CurrentNode) > 6)
	{
		if(strcut(Dialog.CurrentNode, 0, 6) == "chmodel")
		{
			int idx = sti(GetSymbol(Dialog.CurrentNode,7));
			idx = GetOfficersIndex(&PChar, idx);
			if(idx != -1)
			{
				string ani = "man";
				string sex = "man";
				float height = 1.8;
				string model = "";
				ref chr = GetCharacter(idx);
				switch(GetSymbol(Dialog.CurrentNode,8))
				{
					case "M":
						ani = "man";
						sex = "man";
						height = 1.8;
						break;
					case "W":
						ani = "woman";
						sex = "woman";
						height = 1.75;
						break;
					case "T":
						ani = "towngirl";
						sex = "woman";
						height = 1.75;
						break;
					case "S":
						ani = "skeleton";
						sex = "skeleton";
						height = 1.8;
						break;
				}
				for(int sm = 9; sm < strlen(Dialog.CurrentNode); sm++) { model += GetSymbol(Dialog.CurrentNode,sm); }
				dialog.text = "OK.";
				Link.l1 = "Thanks.";
				Link.l1.go = "Exit";
				if(DEBUGINFO) dialog.text = "OK, new model " + model + ", ani " + ani + ", sex " + sex + ", height " + height + ".";
				SetModel(&chr, model, ani, sex, height, true);
			}
			else
			{
				dialog.text = "Sorry, that won't work.";
				Link.l1 = "Ah, well.";
				Link.l1.go = "exit";
			}
			return;
		}
	}*/
	bool bgtmp = CheckAttribute(NPChar, "greeting") && CheckAttribute(NPChar, "grsex") && NPChar.grsex != NPChar.sex;
	if(!bgtmp) bgtmp = !CheckAttribute(NPChar,"greeting") || !CheckAttribute(NPChar, "grsex");
	if(bgtmp)
	{
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
		}
		else // NK add else 05-05-01
		{
			switch(sti(NPChar.nation))
			{
				// no Spa or Por female voices! using a second Dutch one for now.
//				case ENGLAND: NPChar.greeting = "Gr_greenford_citizen_01"; break;
				case ENGLAND: NPChar.greeting = "Gr_f_officer_English"; break; // Grey Roger: replaces one citizen phrase with new audio files
				case FRANCE: NPChar.greeting = "Gr_Sylvie Bondies"; break;
				//case SPAIN: NPChar.greeting = "Gr_Jaoquin de masse"; break;
				case PIRATE: NPChar.greeting = "Gr_greenford_citizen_01"; break;
				case HOLLAND: NPChar.greeting = "Gr_Tanneken Oremans"; break;
				//case PORTUGAL: NPChar.greeting = "Gr_witness-dialog"; break;
//				NPChar.greeting = "Gr_f_officer"; // second Dutch
				NPChar.greeting = "Gr_Officer_f common";//MAXIMUS: replaces one boring phrase
			}
		}
		NPChar.grsex = NPChar.sex;
	}
	// NK <--
	if(PChar.sex == "woman"){
		Preprocessor_Add("sir", XI_ConvertString("ma'am")); // DeathDaisy
	}
	else{
		Preprocessor_Add("sir", XI_ConvertString("sir")); // DeathDaisy
	}
	
	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_hire":
			// TODO: Aconcagua: here is still some bug, had
			// an officer being equiped with a gun he could not handle...

			if (ENABLE_AMMOMOD) {	// LDH change
				//JRH fix oct 06: rewritten "checkcharacteritem" wasn't enough any longer -->
				if(CheckAttribute(NPChar,"equip."+GUN_ITEM_TYPE))
				{
					if(CheckAttribute(weapon, "secondary") && weapon.secondary == "true")
					{
					 	//do nothing
					}else{
						TakenItems(NPChar, "gunpowder", -100);TakenItems(NPChar, "pistolbullets", -100);
						TakenItems(NPChar, "pistolgrapes", -100);TakenItems(NPChar, "musketbullets", -100);
						TakenItems(NPChar, "gunpowder", MAX_GUNPOWDER);		//UZVER
					}
				}

				if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pb") TakenItems(NPChar, "pistolbullets", MAX_SHOTS);
				if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pb2") TakenItems(NPChar, "pistolbullets", MAX_SHOTS);
				if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pg") TakenItems(NPChar, "pistolgrapes", MAX_SHOTS);
				if(CheckAttribute(weapon, "shottype") && weapon.shottype == "pg2") TakenItems(NPChar, "pistolgrapes", MAX_SHOTS);
				if(CheckAttribute(weapon, "shottype") && weapon.shottype == "mb") TakenItems(NPChar, "musketbullets", (MAX_SHOTS / 2));
				//<-- JRH
			}
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerHired");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_fire":
			Pchar.quest.FiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerFired");
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;

			// SA -->
			ChangeCharacterReputation(PChar, -1);
			DialogExit();			
		break;

		case "Exit_Departed":
			Pchar.quest.FiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerFiredGood"); // SA
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;

			DialogExit();			
		break;

		case "Exit_Departed2":
			Pchar.quest.FiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerFiredGoodPayed"); // SA

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;

			DialogExit();
		break;
		// SA <--



// ccc Greater Oxbay, enlist certain chr instantly
		case "instanthire":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) == 1 || CheckAttribute(PChar, "isnotcaptain"))
			{
				//JRH
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "Exit";
			}
			else
			{
				NPChar.friend = true;
				Diag.TempNode = "OnboardSoon";
				d.Text = DLG_TEXT[51];
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "Exit_hire";
			}								
		break;
// ccc end



		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			// NK charmod -->
			NPChar.friend = true;
			NPChar.officer = true;
			
			if(!CheckAttribute(NPChar,"offgen"))
			{
				//Log_SetStringToLog("GENERATING OFFICER");
				// NK 05-07-09 use modeltypes
				NPChar.offgen = true;
				bool gennew = true;
				//string tmpstr = "";
				//logit("Current: " + NPChar.current + ", off: " + NPChar.quest.officertype);
				/*if(CheckAttribute(NPChar, "quest.officertype") && NPChar.quest.officertype != OFFIC_TYPE_RANDCHAR) { tmpstr = NPChar.quest.officertype; } // do we already have an officertype?
				else if(CheckAttribute(NPChar, "current")) // checks to see if we were created by LEnc, and if so assigned an officertype already.
				{
					tmpstr = NPChar.current;
				}*/
				//logit("tmpstr is " + tmpstr);
				/*switch(tmpstr)
				{
					case OFFIC_TYPE_BOATSWAIN: gennew = false; break;
					case OFFIC_TYPE_CANNONEER: gennew = false; break;
					case OFFIC_TYPE_QMASTER: gennew = false; break;
					case OFFIC_TYPE_NAVIGATOR: gennew = false; break;
					case OFFIC_TYPE_FIRSTMATE: gennew = false; break;
// MAXIMUS interface MOD -->
                // MAXIMUS officers -->
					case OFFIC_TYPE_CARPENTER: gennew = false; break;
					case OFFIC_TYPE_DOCTOR: gennew = false; break;
					case OFFIC_TYPE_ABORDAGE: gennew = false; break;
                // MAXIMUS officers <--
				}*/
				gennew = UsableOfficer(NPChar); //Levis
				if(!gennew) // if not, find a new one.
				{
					/*switch(Rand(7))
					{
						case 0: NPChar.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
						case 1: NPChar.quest.officertype = OFFIC_TYPE_CANNONEER; break;
						case 2: NPChar.quest.officertype = OFFIC_TYPE_QMASTER; break;
						case 3: NPChar.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
						case 4: NPChar.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
                    // MAXIMUS officers -->
						case 5: NPChar.quest.officertype = OFFIC_TYPE_CARPENTER; break;
						case 6: NPChar.quest.officertype = OFFIC_TYPE_DOCTOR; break;
						case 7: NPChar.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
                    // MAXIMUS officers <--
// MAXIMUS interface MOD <--
					}*/
					NPChar.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
				}
				//else { NPChar.quest.officertype = tmpstr; }
			// NK charmod <--
				LAi_Create_Officer(0, NPChar); //Taghmon, create officer
			}

			Diag.TempNode = "OnceAgain";

			d.Text = DLG_TEXT[0];
			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
			{
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "Node_2";
			}
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "Exit";
			
		break;

		case "Node_2":
			d.Text = DLG_TEXT[3] + XI_ConvertString("S"+NPChar.quest.officertype) + DLG_TEXT[4];
// View Enc Officer: Taghmon
			Link.l1 = DLG_TEXT[46]; //jumping to new Node
			Link.l1.go = "ShowSkills";
			if(!OFFICER_TUTORIAL || CheckAttribute(PChar,"quest.Officer_Tutorial.TalkedtoOfficer")) //Levis
			{
				//If this is the first officer you are going to hire you should go to the showskills so we can have the captain walk in.
				Link.l2 = DLG_TEXT[5];
				Link.l2.go = "price";
			}
			Link.l3 = DLG_TEXT[6] + XI_ConvertString("S"+NPChar.quest.officertype) + DLG_TEXT[7];
			Link.l3.go = "Exit";	
		break;

		case "ShowSkills":
			// Aconcagua: LaunchOfficer uses separate interface now
			//PChar.CharacterInterface_ViewEncOfficer = true;			// added after build 11 by KAM
			Diag.CurrentNode = "ReturnfromSkillview";
			NPChar.quest.meeting = NPC_Meeting;
			Pchar.Quest.Last_Enc_Officer = NPChar.Index;
// LDH --> 05Oct06 Bandaid fix for invalid characters, Devlin, 33_Piratess10, etc.  Needs to be researched and fixed in the character files
			if (NPChar.chr_ai.type == "actor")	// should be "sit" or "citizen" here
			{
				NPChar.old.chr_ai.type = NPChar.chr_ai.type;
				makearef(Type, NPChar.chr_ai.type);
				makearef(OldType, NPChar.old.chr_ai.type);
				CopyAttributes(&OldType,&Type);
				DeleteAttribute(NPChar, "chr_ai.type");		// fix for invalid characters, devlin, 33_Piratess10, etc
				NPChar.chr_ai.type = "sit";					// note that they won't actually be sitting.
			}
// LDH <--
			if(OFFICER_TUTORIAL && !CheckAttribute(PChar,"quest.Officer_Tutorial.TalkedtoOfficer") && GetDifficulty() < DIFFICULTY_SEADOG)
				AddDialogExitQuest("OT_Captain_enter_location"); //OfficerTutorial by Levis
			DialogExit();			
//			LaunchCharacter(NPChar); // MAXIMUS interface MOD
			LaunchOfficer(NPChar); // MAXIMUS interface MOD
		break;

		case "ReturnfromSkillview":
			if(CheckAttribute(NPChar, "old.chr_ai.type"))
			{
				NPChar.chr_ai.type = NPChar.old.chr_ai.type;
				makearef(Type, NPChar.chr_ai.type);
				makearef(OldType, NPChar.old.chr_ai.type);
				CopyAttributes(&Type,&OldType);
				DeleteAttribute(NPChar, "old.chr_ai.type");
			}
			d.Text = DLG_Text[47];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "price";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
		break;

//View Enc Officer End

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			d.Text = DLG_TEXT[8] + XI_ConvertString("S"+NPChar.quest.officertype) + DLG_TEXT[9];
			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "price";
			}
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
		break;

		case "price":
//			d.Text = DLG_TEXT[12] + NPChar.quest.OfficerPrice + DLG_TEXT[13];
			d.Text = DLG_TEXT[12] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[13];		// LDH 16Apr09
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "hire";
			Link.l3 = DLG_TEXT[16];
			Link.l3.go = "exit";
		break;

		case "trade":
			// NK -->
			int sLuck = CalcCharacterSkill(PChar, SKILL_SNEAK);
			int ptest = 2 + (
					CalcCharacterSkill(PChar, SKILL_COMMERCE) * 3 / 2
					+ CalcCharacterSkill(PChar, SKILL_LEADERSHIP)
					+ Rand(CalcCharacterSkill(PChar, SKILL_SNEAK))
				) / 2;
			int ntest = GetLevel(NPChar) / 5 + Rand(
					CalcCharacterSkill(NPChar,SKILL_COMMERCE) * 2
					+ CalcCharacterSkill(NPChar,SKILL_LEADERSHIP)
					+ CalcCharacterSkill(NPChar,SKILL_SNEAK)
					- 4
				) + 4;
			int oPrice = sti(NPChar.quest.OfficerPrice);
			if(ptest >= ntest && oPrice >= GetLevel(NPChar) * 100 + ptest * 16)
			{
				// Aconcagua: Randomize a little more...
				NPChar.quest.OfficerPrice = oPrice - ptest * 14 - Rand(ptest * 2);
				// NK <--
//				d.Text = DLG_TEXT[17] + NPChar.quest.OfficerPrice + DLG_TEXT[18];
				d.Text = PersuasionSuccess + DLG_TEXT[17] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[18];		// LDH 16Apr09
				Link.l1 = DLG_TEXT[19];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "exit";
			}
			else
			{
				d.Text = PersuasionFailure + DLG_TEXT[21];
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[23];
				Link.l2.go = "exit";
			}
		break;

		case "hire":
//			if(makeint(ourMoney) >= makeint(NPChar.quest.OfficerPrice))// MAXIMUS 08.10.2006
			int OfficerPrice = CalcEncOfficerPrice(NPChar);
			if(ourMoney >= OfficerPrice || ProfessionalNavyNation() != UNKNOWN_NATION)		// LDH 16Apr09
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				// LDH 16Apr09
				AddMoneyToCharacter(Pchar, -OfficerPrice);
  				AddMoneyToCharacter(NPChar, OfficerPrice);// TIH give money to officer (this is moved to wealth in later step) Oct31'06

				Diag.TempNode = "OnboardSoon";
				if(NPChar.chr_ai.type == LAI_TYPE_SIT)
				{
					d.Text = DLG_TEXT[24];
					Link.l1 = DLG_TEXT[25];
				}
				else
				{
					d.Text = DLG_TEXT[51];
					if (HasSubStr(PChar.location, "jungle") || HasSubStr(PChar.location, "exit")) d.Text = DLG_TEXT[198];
					Link.l1 = DLG_TEXT[52];
				}
				Link.l1.go = "Exit_hire";
			}
			else
			{
				d.Text = DLG_TEXT[26];
				Link.l1 = DLG_TEXT[27];
				Link.l1.go = "Exit";								
			}
		break;

		case "OnboardSoon":			
			Diag.TempNode = "OnboardSoon";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Exit";											
		break;

// NK -->
		case "rations":
			if(!CheckAttribute(pchar,"Crewstatus.foodrations")) pchar.Crewstatus.foodrations = 1;
			if(!CheckAttribute(pchar,"Crewstatus.rumrations")) pchar.Crewstatus.rumrations = 2;
			if(sti(pchar.Crewstatus.foodrations) == 1) pchar.tempfr = XI_ConvertString("rfull");
			else pchar.tempfr = XI_ConvertString("rhalf");
			if(sti(pchar.Crewstatus.rumrations) == 1) pchar.temprr = XI_ConvertString("rdouble");
			else pchar.temprr = XI_ConvertString("rnormal");
// added by MAXIMUS [CheckAttribute only] -->
			int ourFood = 0;
			int ourRum = 0;
			if(CheckAttribute(pchar.Crewstatus,"foodused")) ourFood = stf(pchar.Crewstatus.foodused);
			if(CheckAttribute(pchar.Crewstatus,"rumused")) ourRum = stf(pchar.Crewstatus.rumused);
// added by MAXIMUS [CheckAttribute only] <--
			d.Text = DLG_TEXT[53] + pchar.tempfr + DLG_TEXT[54] + pchar.temprr + DLG_TEXT[55] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_WHEAT)) - ourFood) / (makefloat(GetSquadronTotalCrewQuantity(pchar)) * FOOD_PER_CREW / stf(pchar.Crewstatus.foodrations))) + DLG_TEXT[56] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_RUM)) - ourRum) / (makefloat(GetSquadronTotalCrewQuantity(pchar)) * FOOD_PER_CREW / stf(pchar.Crewstatus.rumrations))) + DLG_TEXT[57]; // KK
			//Link.l1 = "No.";
			//Link.l1.go = "Exit";
			//if(pchar.tempfr != "full" && pchar.temprr != "normal")
			{
				Link.l2 = DLG_TEXT[58];
				Link.l2.go = "R12";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "normal")
			{
				Link.l3 = DLG_TEXT[59];
				Link.l3.go = "R22";
			}
			//if(pchar.tempfr != "full" && pchar.temprr != "double")
			{
				Link.l4 = DLG_TEXT[60];
				Link.l4.go = "R11";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "double")
			{
				Link.l5 = DLG_TEXT[61];
				Link.l5.go = "R21";
			}
			DeleteAttribute(pchar,"tempfr");
			DeleteAttribute(pchar,"temprr");
		break;

		case "R12":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 2;

			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit";
		break;

		case "R22":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 2;

			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit";
		break;

		case "R11":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 1;

			d.Text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit";
		break;

		case "R21":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 1;

			d.Text = DLG_TEXT[65];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit";
		break;

		case "SalaryC":
			d.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "Exit";
			if(sti(PChar.CrewStatus.explength) <= 1)
			{
				d.Text = DLG_TEXT[68];
				Link.l2 = DLG_TEXT[69];
				Link.l2.go = "Salary";
			}
		break;

		case "ArticlesC":
			d.Text = DLG_TEXT[70];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[71];
			Link.l2.go = "Articles";
		break;

		case "Salary":
			d.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			ResetAllLengths(PChar);
			PChar.articles = false;
		break;

		case "Articles":
			d.Text = DLG_TEXT[73];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			ResetAllLengths(PChar);
			PChar.articles = true;
			DeleteAttribute(PChar, "repeat_salary_payment"); // PB
		break;

		// RM -->
		case "flgchoice":
			d.Text = DLG_TEXT[74];
// KK -->
			if (GetCurrentFlag() != PERSONAL_NATION) {
				Link.l1 = DLG_TEXT[75] + XI_ConvertString("4"+GetNationDescByType(GetCurrentFlag())) + DLG_TEXT[49];
				Link.l1.go = "flag0" + sti(PChar.nation);
			} else {
				Link.l1 = DLG_TEXT[164];
				Link.l1.go = "flag" + PERSONAL_NATION;
			}
// <-- KK
// KK -->
			if (GetCurrentFlag() != PIRATE) {
				Link.l2 = DLG_TEXT[76];
				Link.l2.go = "flag0" + PIRATE;
			}
// <-- KK
			string tempstr;
			for(int q = 0; q < NATIONS_QUANTITY; q++)
			{
				if (q==PIRATE) continue;
// KK -->
				if (GetCurrentFlag() == q) continue;
				if (GetRMRelation(PChar, q) >= REL_AMNESTY)
				{
					tempstr = "l" + (q+3);
					Link.(tempstr) = DLG_TEXT[116] + XI_ConvertString("4"+GetNationDescByType(q)) + DLG_TEXT[49];
					Link.(tempstr).go = "flag0"+q;
				}
			}
			if (GetCurrentFlag() != PERSONAL_NATION) {
				tempstr = "l" + (PERSONAL_NATION+3);
				Link.(tempstr) = DLG_TEXT[117];
				Link.(tempstr).go = "flag"+PERSONAL_NATION;
			}
// <-- KK
		break;
		// RM <--

		case "flag00":
			PChar.nation = ENGLAND;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(ENGLAND)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag01":
			PChar.nation = FRANCE;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(FRANCE)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag02":
			PChar.nation = SPAIN;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(SPAIN)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag03":
			PChar.nation = PIRATE;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(PIRATE)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag04":
			PChar.nation = HOLLAND;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(HOLLAND)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag05":
			PChar.nation = PORTUGAL;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(PORTUGAL)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;

		case "flag10":
			PChar.nation = PERSONAL_NATION;
			d.Text = DLG_TEXT[48] + XI_ConvertString("4"+GetNationDescByType(PERSONAL_NATION)) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
		break;
			
		case "hired":
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[30] + GetMyRespectfullyName(pchar) + DLG_TEXT[187];//MAXIMUS
			// NK -->
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Exit";								
			/*Link.l2 = DLG_TEXT[77];
			Link.l2.go = "shipandcrew_status";
			Link.l3 = DLG_TEXT[78];
			Link.l3.go = "personal_status";
			Link.l4 = DLG_TEXT[79];
			Link.l4.go = "your_status";*/ //making room for other options by adding them together.
			Link.l2 = DLG_TEXT[189];
			Link.l2.go = "status_overview";
// ccc Dec 06   Settlement feature reenabled
// changed by MAXIMUS [abordage MOD] -->
			// ccc building kit
			if(!bSeaActive && !ownDeckStarted() && ENABLE_BUILDINGSET) // KK
			{
				Link.l5 = DLG_TEXT[161];
				Link.l5.go = "building";
			}
// changed by MAXIMUS [abordage MOD] -->
			//Levis unlocking the mind -->
			if(CheckCharacterItem(Pchar,"ayahuasca"))
			{
				Link.l6 = DLG_TEXT[188];
				Link.l6.go = "ayahuasca";
			}
			//Levis unlocking the mind <--
			//Levis smuggling addon -->
			if(CheckAttribute(Pchar,"quest.Contraband.scout"))
			{
				if(!CheckAttribute(Pchar,"quest.Contraband.scout.done") && !bSeaActive)
				{
					Link.l8 = DLG_TEXT[190];
					Link.l8.go = "patrolquestion";
				}
			}
			//Levis smuggling addon <--

		break;	// original line

		//Levis smuggling addon -->
		case "patrolquestion":
			d.Text = DLG_TEXT[191];
			Link.l1 = DLG_TEXT[192];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[193];
			Link.l2.go = "Send Officer";
		break;

		case "Send Officer":
			d.Text = DLG_TEXT[197];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit_Send";
		break;

		case "Patrolschedule_failed":
			d.Text = DLG_TEXT[194];
			Link.l1 = DLG_TEXT[195];
			Link.l1.go = "Exit_back_in_slot";
		break;

		case "Patrolschedule_got":
			//Questbook
			Preprocessor_AddQuestData("time",patroltime);
			AddQuestRecord(questname, 13);
			Preprocessor_Remove("time");
			//Text
			d.Text = DLG_TEXT[196]+ patroltime;
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit_back_in_slot";
		break;

		case "Exit_Send":
			PChar.quest.Contraband.officerID = NPChar.id;
			AddDialogExitQuest("Send Officer to scout"); //Add quest
			DialogExit();
		break;

		case "Exit_back_in_slot":
			PChar.quest.Contraband.officerID = NPChar.id;
			AddDialogExitQuest("Send Officer back in slot"); //Add quest
			DialogExit();
		break;
		//Levis smuggling addon <--

		case "status_overview":
			d.Text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[77];
			Link.l2.go = "shipandcrew_status";
			Link.l3 = DLG_TEXT[78];
			Link.l3.go = "personal_status";
			Link.l4 = DLG_TEXT[79];
			Link.l4.go = "your_status";
		break;

		//Levis unlocking the mind -->
		case "ayahuasca":
			TakeItemFromCharacter(Pchar,"ayahuasca");
			DialogExit();
			UseAyahuasca(NPChar);
		break;
		//Levis unlocking the mind <--

		case "building":
			npchar.building = "nothing";
			npchar.interior = "nothing";
			// int planks = 0;
			// int money = 0;
			// int crew = 0;

			d.text = DLG_TEXT[118] + GetSquadronGoods(pchar,GOOD_PLANKS) + "/" + GetSquadronGoods(pchar,GOOD_BRICKS) + DLG_TEXT[119] + ourMoney + DLG_TEXT[120] + ourCrew + DLG_TEXT[121];// MAXIMUS 08.10.2006 // KK
			Link.l7 = DLG_TEXT[122];
			Link.l7.go = "box";
			Link.l6 = DLG_TEXT[123];
			Link.l6.go = "fence";
			Link.l51 = DLG_TEXT[124];
			Link.l51.go = "bastion";
			Link.l5 = DLG_TEXT[125];
			Link.l5.go = "keep";

			Link.l2 = DLG_TEXT[126];
			Link.l2.go = "house";
			Link.l21 = DLG_TEXT[127];
			Link.l21.go = "workshop";
			Link.l3 = DLG_TEXT[128];
			Link.l3.go = "farm";
			Link.l4 = DLG_TEXT[129];
			Link.l4.go = "forest";

			if(IsBrothelEnabled())
			{
				Link.l9 = DLG_TEXT[130];
			}
			else
			{
				Link.l9 = DLG_TEXT[131];
			}
			Link.l9.go = "mansion";
			Link.l10 = DLG_TEXT[132];
			Link.l10.go = "observatory";

			Link.l11 = DLG_TEXT[133];
			Link.l11.go = "exit";

			Link.l12 = DLG_TEXT[134];
			Link.l12.go = "explain";
			Link.l1 = DLG_TEXT[135];
			Link.l1.go = "exit";
		break;

		case "explain":
			d.Text = DLG_TEXT[136];
			Link.l1 = DLG_TEXT[137];
			Link.l1.go = "building";
		break;

		case "house":
			npchar.building = "house";
			d.text = DLG_TEXT[108]; //"Right, and do you want some furnishing or equipment in there?";
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "workshop":
			npchar.building = "workshop";
			d.text = DLG_TEXT[108];
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "farm":
			npchar.building = "farm";
			d.text = DLG_TEXT[108];
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "forest":
			npchar.building = "forest";
			d.text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
		break;

		case "keep":
			npchar.building = "keep";
			d.text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
		break;

		case "bastion":
			npchar.building = "bastion";
			d.text = DLG_TEXT[138];
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "box":
			npchar.building = "box";
			d.text = DLG_TEXT[139];
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "fence":
			npchar.building = "fence";
			d.text = DLG_TEXT[138];
			Link.l3 = DLG_TEXT[111];
			Link.l3.go = "interior";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "erect";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "mansion":
			npchar.building = "mansion";
			d.text = DLG_TEXT[162];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
			Link.l3 = DLG_TEXT[163];
			Link.l3.go = "interior";
		break;

		case "observatory":
			npchar.building = "observatory";
			d.text = DLG_TEXT[162];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
			Link.l3 = DLG_TEXT[163];
			Link.l3.go = "interior";
		break;

		case "":
			npchar.building = "";
			d.text = DLG_TEXT[48];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[49];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[51];
			Link.l3.go = "interior";
		break;


		case "interior":
			d.text = DLG_TEXT[140];

			if(npchar.building == "workshop")
			{
			Link.l2 = DLG_TEXT[141];
			Link.l2.go = "mine";
			Link.l21 = DLG_TEXT[142];
			Link.l21.go = "foundry";
			Link.l22 = DLG_TEXT[143];
			Link.l22.go = "distillery";
			Link.l23 = DLG_TEXT[144];
			Link.l23.go = "dock";
			}

			if(npchar.building == "fence" || npchar.building == "bastion" || npchar.building == "box"  || npchar.building == "keep") // ccc Dec06 keep added
			{
			Link.l3 = DLG_TEXT[145];
			Link.l3.go = "cannon";
			}

			if(npchar.building == "house")
			{
			Link.l8 = DLG_TEXT[146];
			Link.l8.go = "marketstall";
			}

			if(npchar.building == "house" || npchar.building == "farm")
			{
			Link.l5 = DLG_TEXT[147];
			Link.l5.go = "luxurious furniture";
			}

			if(IsBrothelEnabled())
			{
				if(npchar.building == "mansion")
				{
				Link.l9 = DLG_TEXT[148];
				Link.l9.go = "boudoir";
				}
			}

			if(npchar.building == "mansion" || npchar.building == "observatory")
			{
			Link.l10 = DLG_TEXT[149];
			Link.l10.go = "office";
			}

			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";

			Link.l6 = DLG_TEXT[151];
			Link.l6.go = "exit";
		break;

		case "office":
			npchar.interior = "office";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "boudoir":
			npchar.interior = "boudoir";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "mine":
			npchar.interior = "mine";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "foundry":
			npchar.interior = "foundry";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "distillery":
			npchar.interior = "distillery";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "dock":
			npchar.interior = "dock";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS1"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "cannon":
			npchar.interior = "cannon";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "marketstall":
			npchar.interior = "marketstall";
			d.text = DLG_TEXT[112] + XI_ConvertString(npchar.building) + DLG_TEXT[113] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "exit";
		break;

		case "6":
			npchar.interior = "";
			d.text = DLG_TEXT[52] + XI_ConvertString(npchar.building) + DLG_TEXT[53] + XI_ConvertString("BS"+npchar.interior);
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "erect";
			Link.l3 = DLG_TEXT[55];
			Link.l3.go = "building";
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;

		case "erect":
			aref buildingref;
			Items_FindItem(npchar.building,&buildingref);
			int planks = sti(buildingref.building.planks);
			int bricks = sti(buildingref.building.bricks); // KK
			int money = sti(buildingref.building.money);
			int crew = sti(buildingref.building.crew); // ccc Dec06 fix for apparent calc error

			if(npchar.interior != "nothing")
			{
				aref interiorref;
				Items_FindItem(npchar.interior,&interiorref);
				planks += sti(interiorref.building.planks);
				bricks += sti(interiorref.building.bricks); // KK
				money += sti(interiorref.building.money);
				crew += sti(interiorref.building.crew); // ccc Dec06 fix for apparent calc error
			}
			if(money > sti(ourMoney) || crew > sti(ourCrew) || planks > GetSquadronGoods(pchar,GOOD_PLANKS) || bricks > GetSquadronGoods(pchar,GOOD_BRICKS))// MAXIMUS 08.10.2006 // KK
			{
				d.text = DLG_TEXT[152] + XI_ConvertString(npchar.building) + DLG_TEXT[165] + XI_ConvertString("BS"+npchar.interior) + DLG_TEXT[153] + planks + " / " + bricks + DLG_TEXT[154] + money + DLG_TEXT[155] +crew+ DLG_TEXT[156] + GetSquadronGoods(pchar,GOOD_PLANKS) + " / " + GetSquadronGoods(pchar,GOOD_BRICKS) +DLG_TEXT[157]+ourMoney+DLG_TEXT[158]+ourCrew+DLG_TEXT[159];// MAXIMUS 08.10.2006 // KK
				Link.l3 = DLG_TEXT[160];
				Link.l3.go = "exit";
			}
			else
			{
				Diag.CurrentNode = Diag.TempNode;
				NPChar.quest.meeting = NPC_Meeting;
				DialogExit();

				// move officer away from building site
				float x,y,z,ay;
				GetCharacterPos(pchar, &x, &y, &z); // get pos
				GetCharacterAy(pchar, &ay); // get angle
				z -= cos(ay)*1; // add Z component
				x -= sin(ay)*1; // add X component
			 	TeleportCharacterToPos(npchar, x, y, z); // move char
			 	CharacterTurnAy(npchar, ay);

				// take buildingresources
			//	RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );  // GR: Why -1?
			//	RemoveCharacterGoods(pchar, GOOD_BRICKS, bricks - 1); // KK
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks);
				RemoveCharacterGoods(pchar, GOOD_BRICKS, bricks); // KK
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -money);
				ourCrew = sti(ourCrew) -crew;// MAXIMUS 08.10.2006
				Pchar.Ship.crew.quantity = ourCrew; // ccc Dec06 using Maximus ourCrew variable fixes some slight calc errors. So used properly it makes sense.
			//	Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew; // TIH fix for sloppy code change Nov1'06
				Build_here(pchar, npchar.building, npchar.interior, true);
			}
		break;

			// ccc building kit end

		case "shipandcrew_status":
			Diag.TempNode = "Hired";
			d.text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[82];
			Link.l2.go = "rations";
			if(CheckAttribute(PChar, "articles") && sti(PChar.articles))
			{
				//  && FindCurrentDeck() == "ShipDeck"
				If (NPChar.quest.officertype == OFFIC_TYPE_QMASTER && bCanEnterToLand)
				{
					Link.l3 = DLG_TEXT[199] + GetMyAddressForm(PChar, NPChar, ADDR_CIVIL, false, true) + DLG_TEXT[200];
					Link.l3.go = "Divide Plunder";
				}
				Link.l6 = DLG_TEXT[83];
				Link.l6.go = "SalaryC";
			}
			else
			{
				Link.l6 = DLG_TEXT[181];
				Link.l6.go = "Finances";
				if(ProfessionalNavyNation() == UNKNOWN_NATION)
				{
					Link.l3 = DLG_TEXT[84];
					Link.l3.go = "ArticlesC";
				}
			}
			Link.l4 = DLG_TEXT[85];
			Link.l4.go = "flgchoice";
			if(PChar.location != "Tutorial_Deck")
			{
				Link.l5 = DLG_TEXT[86];
				Link.l5.go = "layupships";
			}
		break;

		case "Finances":
			//We currently owe: crew / officers
			// Current Salary based on the crew we have today is: 
			d.text = DLG_TEXT[182] + CalcCrewPayment(pchar, GetSquadronCrewQuantity(pchar)) + DLG_TEXT[183] + CalcOfficerPayOwed(PChar) + DLG_TEXT[184] + GetEstimatedCrewPay() + DLG_TEXT[185] +  GetEstimatedOfficerPay() + DLG_TEXT[186];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;
//PW--->whole section copied from usurer dialog		
		case "Divide Plunder":
		//case "qmdivide_choose"://PW whole section copied from usurer dialog qm added for unique case names - much redundant but check it works
			//may add in port new expedition choice later
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "qmdivide_only_money";
			//link.l2 = DLG_TEXT[213];
			//link.l2.go = "qmdivide_new_expedition";
		break;

		case "qmdivide_only_money":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[214] + DLG_TEXT[215] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[216] +
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[217] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[218] + DLG_TEXT[219] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[220];
			Link.l1 = DLG_TEXT[206];
			Link.l1.go = "qmdivide2";
			Link.l2 = DLG_TEXT[207];
			Link.l2.go = "Exit_qmnoChange";
		break;

		case "qmdivide_new_expedition":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[221] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[202] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[203] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[204] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[205];
			Link.l1 = DLG_TEXT[206];
			Link.l1.go = "qmdivide1";
			Link.l2 = DLG_TEXT[207];
			Link.l2.go = "Exit_qmnoChange";
		break;

/*		case "qmdivide":
			Dialog.snd = "voice\USDI\USDI034";
			// LDH fix for odd money display 10Sep06
			d.Text = DLG_TEXT[201] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER)+ DLG_TEXT[202] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[203] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[204] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[205];
			Link.l1 = DLG_TEXT[206];
			Link.l1.go = "qmdivide1";
			Link.l2 = DLG_TEXT[207];
			Link.l2.go = "Exit_qmnoChange";
		break; */

		case "qmdivide1":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[208] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[209];
			Link.l1 = DLG_TEXT[210];
			Link.l1.go = "Exit_qmnoChange";
			DividePlunder(pchar,true);
			// NK new delay section 05-04-17
			if(REFIT_TIME)
			{
				PChar.updatedays = REFIT_TIME;
				PChar.updatedays.disableDCU = true;
				PChar.updatedays.disableIT = true;
				AddDialogExitQuest("DPFader");
			}
			/*PChar.disableDCU = true;
			int a;
			if(CheckAttribute(ShipLookupTable,"itemtraders")) ShipLookupTable.itemtraders = 0;
			
			for(int dn = 0; dn < REFIT_TIME -1; dn++) { AddTimeToCurrent(24, 0); }
			if(CheckAttribute(ShipLookupTable,"itemtraders")) ShipLookupTable.itemtraders = 1;
			AddTimeToCurrent(24, 0);
			DeleteAttribute(&PChar,"disableDCU");
			//WaitDate("", 0, 2, 0, 0, 0); // NK 05-04-16*/
		break;

		case "qmdivide2":		// GR: same as "qmdivide1" but without the delay
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[222] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[223];
			Link.l1 = DLG_TEXT[224];
			Link.l1.go = "Exit_qmnoChange";
			DividePlunder(pchar,false);
		break;

		case "exit_qmNoChange":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
//PW <-- block copied from usurer_dialog.c

		case "personal_status":
			Diag.TempNode = "Hired";
			d.text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[87];
			Link.l2.go = "Difficulty";
			Link.l3 = DLG_TEXT[88];
			Link.l3.go = "clothes";
		break;

		case "your_status":
			Diag.TempNode = "Hired";
			d.text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "exit";

			// boal 05.09.03 offecer need to go to abordage -->
// KK -->
			Link.l3 = DLG_TEXT[166]; // added by JA
			Link.l3.go = "ChangeRole"; // added by JA
			if (CheckAttribute(NPChar, "AbordageMode") == true && sti(NPChar.AbordageMode) == true) {
				Link.l4 = DLG_TEXT[39];
				Link.l4.go = "Boal_safeAbordage";
			} else {
				Link.l4 = DLG_TEXT[38];
				Link.l4.go = "Boal_Abordage";
			}
// <-- KK
			Link.l5 = DLG_TEXT[43];
			Link.l5.go = "Boal_Stay";
			Link.l6 = DLG_TEXT[44];
			Link.l6.go = "Boal_Follow";
			// boal 05.09.03 offecer need to go to abordage <--
			Link.l7 = DLG_TEXT[89];
			Link.l7.go = "clothesyou";
			//PW -->> Sabine dialog start start
			if ( NPChar.id == "Sabine Matton") 
			{
				if(CheckAttribute(NPChar,"quest.NoRaise")) 
				{
					Link.l8 = DLG_TEXT[225];
					Link.l8.go = "Sabine payrise";
				}
			}
			//PW <----Sabine dialog start end
			
			if(CheckAttribute(PChar,"articles") && sti(PChar.articles)) 
			{
				Link.l2 = DLG_TEXT[90]; // SA
				Link.l2.go = "AsYouWish_G"; // SA
			}
			else
			{
				if(CheckAttribute(NPChar,"quest.OfficerPayOwed"))//MAXIMUS: CheckAttribute added - isn't this right?
				{
					Link.l2 = DLG_TEXT[179] + sti(NPChar.quest.OfficerPayOwed) + DLG_TEXT[180]; // SA
					Link.l2.go = "AsYouWish_G2"; // SA
				}
			}
			Link.l9 = DLG_TEXT[32]; //fire officer meanly
			Link.l9.go = "AsYouWish";
		break;

		// added by JA -->
		case "ChangeRole":
			Diag.TempNode = "Hired";
			d.text = DLG_TEXT[167];
			Link.l1 = DLG_TEXT[168];
			Link.l1.go = "SwitchBoatswain";
			Link.l2 = DLG_TEXT[169];
			Link.l2.go = "SwitchGunner";
			Link.l3 = DLG_TEXT[170];
			Link.l3.go = "SwitchNavigator";
			Link.l4 = DLG_TEXT[171];
			Link.l4.go = "SwitchFirstMate";
			Link.l5 = DLG_TEXT[172];
			Link.l5.go = "SwitchQuaterMaster";
			Link.l6 = DLG_TEXT[173];
			Link.l6.go = "SwitchCarpenter";
			Link.l7 = DLG_TEXT[174];
			Link.l7.go = "SwitchDoctor";
			Link.l8 = DLG_TEXT[175];
			Link.l8.go = "SwitchTough";
			Link.l9 = DLG_TEXT[176];
			Link.l9.go = "Exit";
		break;

		case "SwitchBoatswain":
			NPChar.quest.officertype = OFFIC_TYPE_BOATSWAIN;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "Boatswain"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchGunner":
			NPChar.quest.officertype = OFFIC_TYPE_CANNONEER;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "MGunner"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchNavigator":
			NPChar.quest.officertype = OFFIC_TYPE_NAVIGATOR;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "Navigator"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchFirstMate":
			NPChar.quest.officertype = OFFIC_TYPE_FIRSTMATE;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "First_Mate"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchQuaterMaster":
			NPChar.quest.officertype = OFFIC_TYPE_QMASTER;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "QMaster"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchCarpenter":
			NPChar.quest.officertype = OFFIC_TYPE_CARPENTER;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "Carpenter"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchDoctor":
			NPChar.quest.officertype = OFFIC_TYPE_DOCTOR;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "Doc"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;

		case "SwitchTough":
			NPChar.quest.officertype = OFFIC_TYPE_ABORDAGE;
			DeleteAttribute(NPChar,"ContribList"); //Added by Levis
			ResetMaxHP(NPChar); //Added by Levis to take officer boosts in account
			//Set_Ship_OfficersIndex(PChar, GetCharacterIndex(NPChar.id), "Deck_Fighter"); //ASVS
			dialog.text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[178];
			Link.l1.go = "Exit";
		break;
			// <-- added by Aconcagua
			//PW ---> Sabine to maybe get paid
		case "Sabine payrise":
			dialog.text = DLG_TEXT[226];
			Link.l1 = DLG_TEXT[227];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[228];
			Link.l2.go = "Sabine payrise1";
			Link.l3 = DLG_TEXT[229];
			Link.l3.go = "Sabine normal pay";
		break;	

		case "Sabine payrise1":
			NPChar.quest.OfficerPrice = sti(NPChar.quest.OfficerPrice) + 50;
			OfficerPrice = CalcEncOfficerPrice(NPChar);
			if(ourMoney >= OfficerPrice) 
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(Pchar, -OfficerPrice);
  				AddMoneyToCharacter(NPChar, OfficerPrice);
			
			}
			DialogExit();	
		break;
		
		case "Sabine normal pay":
			if (sti(NPChar.quest.OfficerPrice <= 100)) NPChar.quest.OfficerPrice = 100  ;
			DeleteAttribute (NPChar,"quest.NoRaise");
			DialogExit();
		break;
		
		//PW<-- Sabine to get paid end
		case "layupships":
			// added after build 11 by KAM (a temporary solution!) -->
			DialogExit();
			LaunchKAMShipBerthing();
			// <-- added after build 11 by KAM

		break;

		case "LUSwapC":
			PChar.tempship = PChar.ship.idx;
			PChar.oldship = PChar.ship.idx;

			PChar.tempship.idx = PChar.oldship.idx
			PChar.oldship.idx = PChar.ship.idx;
			PChar.ship.idx = PChar.tempship.idx;

			PChar.tempship.HP = PChar.oldship.HP
			PChar.oldship.HP = PChar.ship.HP;
			PChar.ship.HP = PChar.tempship.HP;

			PChar.tempship.SP = PChar.oldship.SP
			PChar.oldship.SP = PChar.ship.SP;
			PChar.ship.SP = PChar.tempship.SP;

			PChar.tempship.type = PChar.oldship.type
			PChar.oldship.type = PChar.ship.type;
			PChar.ship.type = PChar.tempship.type;

			PChar.tempship.guns = PChar.oldship.guns;
			PChar.oldship.guns = PChar.Ship.Cannons.Type;
			PChar.Ship.Cannons.Type = PChar.tempship.guns;

			PChar.tempship.name = PChar.oldship.name;
			PChar.oldship.name =  PChar.ship.name;
			PChar.ship.name = PChar.tempship.name;
			DeleteAttribute(PChar,"tempship");

			SetCrewQuantity(PChar, GetCrewQuantity(PChar));
			RecalculateCargoLoad(PChar);
			//if(GetCargoFreeSpace(PChar)<0) newt = "It won't all fit, though...";
			
			dialog.text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;

		case "LUShipC":
			PChar.oldship = PChar.ship.idx;
			PChar.oldship.idx = PChar.ship.idx;
			PChar.oldship.type = PChar.ship.type;
			PChar.oldship.HP = Ship_GetHP(PChar);
			PChar.oldship.SP = PChar.ship.SP;
			PChar.oldship.guns = PChar.Ship.Cannons.Type;
			PChar.oldship.name =  PChar.ship.name;
			if( CheckAttribute(PChar,"location.from_sea") )
			{
				if( !CheckAttribute(PChar,"location.old_from_sea") )
				{
					PChar.location.old_from_sea = PChar.location.from_sea;
				}
				PChar.location.from_sea = "";
			}
			DeleteAttribute(PChar,"ship");
			PChar.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
			PChar.ship.idx = SHIP_NOTUSED; // PS
			dialog.text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;

		case "LULaunchC":
			PChar.ship = PChar.oldship.idx;
			PChar.ship.idx = PChar.oldship.idx;
			PChar.oldship.Cannons.Type; = PChar.oldship.guns
			PChar.ship.name =  PChar.oldship.name;
			PChar.ship.type = PChar.oldship.type;
			PChar.ship.HP = PChar.oldship.HP;
			PChar.ship.SP = PChar.oldship.SP;
			DeleteAttribute(PChar,"oldship");
			ref base_ship = GetShipByType(sti(PChar.ship.idx));

			int gq[GOODS_QUANTITY]; // NK
			string goods_id;

			PChar.Ship.Pos.x = 0;
			PChar.Ship.Pos.z = 0;
			PChar.Ship.Ang = "";
			PChar.Ship.Cannons.Borts = "";
			PChar.Ship.Cannons.Charge.Type = GOOD_BALLS;
			if (!CheckAttribute(PChar,"Ship.Cannons.Type")) { PChar.Ship.Cannons.Type = MakeInt(base_ship.Cannon); }
			if (!CheckAttribute(PChar,"Ship.Crew.Morale"))	{ PChar.Ship.Crew.Morale = 45;	}
			if (!CheckAttribute(PChar,"Ship.Crew.Quantity")) { PChar.Ship.Crew.Quantity = GetMinCrewQuantity(&PChar); } // PRS3

			// уберем все товары
			for(int g=0; g<GOODS_QUANTITY; g++)
			{
				if(!CheckAttribute(Goods[g],"name")) continue; // NK
				goods_id = Goods[g].name;
				if( CheckAttribute(PChar,"Ship.Cargo.Goods."+goods_id) )
				{
					gq[g] = sti(PChar.Ship.Cargo.Goods.(goods_id));
				}
				else
				{
					gq[g] = 0;
				}
				PChar.Ship.Cargo.Goods.(goods_id) = 0;
			}
			PChar.Ship.Cargo.Load = 0;
			
			// установим все товары
			for(g=0; g<GOODS_QUANTITY; g++)
			{
				SetCharacterGoods(PChar, g, gq[g]);
			}
			if( CheckAttribute(PChar,"location.old_from_sea") )
			{
				if(PChar.location.old_from_sea != "") PChar.location.from_sea = PChar.location.old_from_sea;
				if(PChar.location.from_sea == "" && GetCurrentTownID() != "") PChar.location.from_sea = GetAttribute(GetCurrentTown(), "boarding.l1");
				DeleteAttribute(PChar,"location.old_from_sea");
			}
			dialog.text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;
			

		case "clothes":
			DialogExit();
			LaunchKAMSelectModel();
		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

		case "nochange":
			dialog.text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;
// NK <--

		case "AsYouWish":
			//Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Exit";								
			Link.l2 = DLG_TEXT[35];
			Link.l2.go = "Exit_Fire";		
		break;

		case "AsYouWish_G": // SA -->
			d.Text = DLG_TEXT[92];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Exit";						
			Link.l2 = DLG_TEXT[93];
			Link.l2.go = "Exit_Departed";
		break;

		case "AsYouWish_G2": // SA -->
			d.Text = DLG_TEXT[92];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[93];
			Link.l2.go = "Exit_Departed2";
		break;

		case "Departed":
			Diag.TempNode = "Departed";
			d.Text = DLG_TEXT[94];
			Link.l1 = DLG_TEXT[95];
			Link.l1.go = "Exit";
		break;
		// SA <--

		case "Fired":
			Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";
		break;

		// NK -->
		case "Difficulty":
			d.Text = DLG_TEXT[96] + stringRet(GetSymbol(GetDifficultyName(GetDifficulty()),0) == "A" || GetSymbol(GetDifficultyName(GetDifficulty()),0) == DLG_TEXT[103], DLG_TEXT[106],DLG_TEXT[107]) + GetDifficultyName(GetDifficulty());
			if(GetShipCap()) { d.Text = d.Text + DLG_TEXT[97]; }
			else { d.Text = d.Text + DLG_TEXT[98]; }
			Link.l1 = stringRet(GetSymbol(GetDifficultyName(1),0) == "A" || GetSymbol(GetDifficultyName(1),0) == DLG_TEXT[103], DLG_TEXT[104],DLG_TEXT[105]) + GetDifficultyName(1) + ".";
			Link.l1.go = "diff1";
			Link.l2 = stringRet(GetSymbol(GetDifficultyName(2),0) == "A" || GetSymbol(GetDifficultyName(2),0) == DLG_TEXT[103], DLG_TEXT[104],DLG_TEXT[105]) + GetDifficultyName(2) + ".";
			Link.l2.go = "diff2";
			Link.l3 = stringRet(GetSymbol(GetDifficultyName(3),0) == "A" || GetSymbol(GetDifficultyName(3),0) == DLG_TEXT[103], DLG_TEXT[104],DLG_TEXT[105]) + GetDifficultyName(3) + ".";
			Link.l3.go = "diff3";
			Link.l4 = stringRet(GetSymbol(GetDifficultyName(4),0) == "A" || GetSymbol(GetDifficultyName(4),0) == DLG_TEXT[103], DLG_TEXT[104],DLG_TEXT[105]) + GetDifficultyName(4) + ".";
			Link.l4.go = "diff4";
			Link.l5 = DLG_TEXT[99];
			if(GetShipCap()) { Link.l5.go = "shipcapoff"; }
			else { Link.l5.go = "shipcapon"; }
		break;

		case "diff1":
			d.Text = DLG_TEXT[100];
			SetDifficulty(1);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;

		case "diff2":
			d.Text = DLG_TEXT[100];
			SetDifficulty(2);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;

		case "diff3":
			d.Text = DLG_TEXT[100];
			SetDifficulty(3);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;

		case "diff4":
			d.Text = DLG_TEXT[100];
			SetDifficulty(4);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;

		case "shipcapon":
			d.Text = DLG_TEXT[100] + DLG_TEXT[101];
			SetShipCap(true);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;

		case "shipcapoff":
			d.Text = DLG_TEXT[100] + DLG_TEXT[102];
			SetShipCap(false);
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Exit";
		break;
		// NK <--

        // boal 05.09.03 offecer need to go to abordage -->
		case "Boal_Abordage":
			NPChar.AbordageMode = makeint(1);
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit";
		break;

		case "Boal_safeAbordage":
			NPChar.AbordageMode = makeint(0);
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit";
		break;

		case "Boal_Stay":
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("Boal_LandEnc_OfficerStay");
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit";
		break;

		case "Boal_Follow":
			SetCharacterTask_FollowCharacter(Characters[GetCharacterIndex(NPChar.id)], PChar); // it works!!!
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit";
		break;
        // boal 05.09.03 offecer need to go to abordage <--
	}
}
