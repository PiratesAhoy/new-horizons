void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	string NPC_Meeting, blade, gun, cuirass, reload_locator;
	string sLogTitle, sLogEntry;
	int iNation = sti(NPChar.nation);
	int i;

	ref PChar;
	PChar = GetMainCharacter();
	int prisonRansomCost = GetPrisonRansomCost(NPChar);

	// PB: Check Port for Ransoming -->
	int locationNation = UNKNOWN_NATION;
	if(CheckAttribute(pchar, "location.from_sea"))	locationNation = GetLocationNationFromID(pchar.location.from_sea); // PB
	if(sti(NPChar.money) > 0.25 * prisonRansomCost) NPChar.money = makeint(0.1 * prisonRansomCost + rand(makeint(0.15 * prisonRansomCost)));
	// PB: Check Port for Ransoming <--

	NPChar.prisoned.indialog = true; // MAXIMUS: identifier for fine playing animations
	if(!CheckAttribute(NPChar,"chr_ai.type")) NPChar.chr_ai.type = "stay";
	PChar.prisonerIDX = sti(NPChar.index);

	bool bAllowHireJoin = FindFreeRandomOfficer()!=-1;
	// PB: Always Allow Ransoming and Releasing, except at Hostile Towns -->
	bool bAllowRelease  = false;
	if(bCanEnterToLand && locationNation != UNKNOWN_NATION)
	{
trace("Prisoned_dialog: locationNation = " + locationNation);
		if(HasSubStr(pchar.location.from_sea, "port"))
		{
			if(iNation == locationNation)
			{
				bAllowRelease = true;												// Full ransom at town of his own nation
			}
			else
			{
				if(GetNationRelation(iNation, locationNation) == RELATION_FRIEND)
				{
					bAllowRelease = true;
					prisonRansomCost = makeint(prisonRansomCost * 0.75);			// 75% ransom at town of a friendly nation
				}
				else
				{
					if(GetNationRelation(iNation, locationNation) == RELATION_NEUTRAL)
					{
						bAllowRelease = true;
						prisonRansomCost = makeint(prisonRansomCost * 0.5);			// Half ransom at town of a neutral nation
					}
					else
					{
						if(locationNation == PIRATE)
						{
							bAllowRelease = true;
							prisonRansomCost = makeint(prisonRansomCost * 0.25);	// 25% ransom at pirate town
						}
					}
				}
			}
		}
	}
	// PB: Always Allow Ransoming and Releasing, except at Hostile Towns <--

	if(CheckAttribute(NPChar,"location.norebirth") && NPChar.location.norebirth==1) { bAllowHireJoin = true}			// No longer blockfrom ransom/release with bAllowRelease = false
	if(CheckAttribute(NPChar,"questchar") && NPChar.questchar==true) { bAllowHireJoin = false;}					// No longer block questchar from ransom/release with bAllowRelease = false
	if(CheckAttribute(NPChar,"canhire") && sti(NPChar.canhire) == true && FindFreeRandomOfficer()!=-1) bAllowHireJoin = true;	// "canhire" attribute overrides block on hiring questchar, but only if there is a slot for him to become an officer
	if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) == 1 || CheckAttribute(PChar, "isnotcaptain")) { bAllowHireJoin = false; }
	if(CheckAttribute(NPChar,"canrelease") && sti(NPChar.canrelease) == false) bAllowRelease = false;				// "canrelease" attribute can be set false to explicitly block ransom/release
	
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
			NextDiag.TempNode = "officer";

			if(NPChar.chr_ai.type == LAI_TYPE_ACTOR) LAi_SetStayType(NPChar); // PB: To make sure he talks
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					dialog.text = DLG_TEXT[51];
					link.l1 = DLG_TEXT[1] + MakeMoneyShow(prisonRansomCost,"",MONEY_DELIVER) + DLG_TEXT[11];
					link.l1.go = "money";
					if(bAllowHireJoin)
					{
						link.l2 = DLG_TEXT[34];
						link.l2.go = "officer";
					}
					if(bAllowRelease)
					{
						if(locationNation==PIRATE)
						{
							link.l3 = DLG_TEXT[37] + FindTownName(GetTownIDFromLocID(pchar.location.from_sea)) + DLG_TEXT[39];
							link.l3.go = "release_equip";
						}
						else
						{
							link.l3 = DLG_TEXT[37] + FindTownName(GetTownIDFromLocID(pchar.location.from_sea)) + DLG_TEXT[42];
							link.l3.go = "release";
						}
					}
					else
					{
						link.l3 = DLG_TEXT[43] + XI_ConvertString(GetNationDescByType(iNation)) + DLG_TEXT[41];
						link.l3.go = "exit_thank_you";
					}
					link.l4 = DLG_TEXT[53];
					link.l4.go = "exit";
				break;

				case LAI_TYPE_POOR:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[50];
					link.l1.go = "stand_up";
					link.l2 = DLG_TEXT[4];
					link.l2.go = "Exit_afraid";
					link.l3 = DLG_TEXT[49];
					link.l3.go = "exit_beat";
					link.l4 = DLG_TEXT[3];
					link.l4.go = "kill";
				break;
			}

			NextDiag.TempNode = "first time";
		break;

		case "stand_up":
			dialog.text = "...";
			link.l1 = DLG_TEXT[52];
			link.l1.go = "First time";
			NPChar.standing = true;
			LAi_SetActorType(NPChar);
			LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Turn", 3.5);
		break;

		case "money":
			if(bAllowRelease)
			{
				dialog.text = DLG_TEXT[57];
				link.l1 = DLG_TEXT[2] + FindTownName(GetTownIDFromLocID(pchar.location.from_sea)) + DLG_TEXT[33];
				link.l1.go = "exit_ransom";
				if(locationNation==PIRATE)
				{
					link.l2 = DLG_TEXT[38] + FindTownName(GetTownIDFromLocID(pchar.location.from_sea)) + DLG_TEXT[39];
					link.l2.go = "release_equip";
				}
				else
				{
					link.l2 = DLG_TEXT[38] + FindTownName(GetTownIDFromLocID(pchar.location.from_sea)) + DLG_TEXT[42];
					link.l2.go = "release";
				}
				link.l3 = DLG_TEXT[53];
				link.l3.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[5];
				link.l2 = DLG_TEXT[30];
				link.l2.go = "exit";
				link.l1 = DLG_TEXT[6];
				link.l1.go = "threaten";
			}
		break;

		case "threaten":
			dialog.text = DLG_TEXT[35] + MakeMoneyShow(sti(NPChar.Money),"",MONEY_DELIVER) + DLG_TEXT[31];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit_money";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "exit";
		break;

		case "exit_thank_you":
			NPChar.released = true;
			NextDiag.CurrentNode = "thank_you";
			DialogExit();
			DeleteAttribute(NPChar.prisoned,"indialog");
			DeleteAttribute(PChar,"prisonerIDX");
		break;

		case "thank_you":
			dialog.text = DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + ".";
			if(bAllowRelease)
		    {
				if(locationNation==PIRATE)
				{
					link.l1 = DLG_TEXT[42];
					link.l1.go = "release";
				}
				else
				{
					link.l1 = DLG_TEXT[37] + DLG_TEXT[42];
					link.l1.go = "release";
				}
				link.l2 = XI_ConvertString(GetCharacterShipLocation(PChar)) + DLG_TEXT[39];
				link.l2.go = "release_equip";
			}
			else
			{
				link.l1 = DLG_TEXT[47] + XI_ConvertString(GetNationDescByType(iNation)) + DLG_TEXT[48];
				link.l1.go = "exit_thank_you";
			}
		break;

		case "officer":
			string pNation = GetNationNameByType(iNation);
			if(GetNationNameByType(iNation)=="no nation") pNation = "Pirate";
		    if(CalcCharacterSkill(NPChar,SKILL_LEADERSHIP)>CalcCharacterSkill(PChar,SKILL_LEADERSHIP) || FindFreeRandomOfficer()==-1)
		    {
				if(pNation=="Pirate") dialog.text = DLG_TEXT[26] + XI_ConvertString("p"+GetNationNameByType(sti(iNation))) + DLG_TEXT[27];
				else dialog.text = DLG_TEXT[26] + XI_ConvertString(GetNationDescByType(iNation)) + DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "Exit";
			}
			else 
			{
				switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
				{
					case LAI_TYPE_POOR:
						Lai_SetActorType(NPChar);
						LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Turn", 3.5);
						NPChar.standing = true;
					break;
				}
				if(pNation=="Pirate") dialog.text = DLG_TEXT[7] + XI_ConvertString("p"+GetNationNameByType(sti(iNation))) + DLG_TEXT[12];
				else dialog.text = DLG_TEXT[7] + XI_ConvertString(GetNationDescByType(iNation)) + DLG_TEXT[12];
				link.l1 = DLG_TEXT[8];
				link.l1.go = "ShowSkills";
				link.l2 = DLG_TEXT[13];
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
			DeleteAttribute(NPChar.prisoned,"indialog");
			DeleteAttribute(PChar,"prisonerIDX");
			LaunchOfficer(NPChar);
			LAi_SetStayType(NPChar);
		break;

		case "ReturnfromSkillview":
			if(NPChar.sex != "woman")
			{
				switch(sti(iNation))
				{
					case ENGLAND: NPChar.greeting = "Gr_Herald"; break;
					case FRANCE: NPChar.greeting = "Gr_Amiel Berangere"; break;
					case SPAIN: NPChar.greeting = "Gr_Jaoquin de masse"; break;
					case PIRATE: NPChar.greeting = "Gr_camilo machado"; break;
					case HOLLAND: NPChar.greeting = "Gr_Dutch Officer"; break;
					case PORTUGAL: NPChar.greeting = "Gr_witness-dialog"; break;
				}
			}
			else
			{
				switch(sti(iNation))
				{
//					case ENGLAND: NPChar.greeting = "Gr_greenford_citizen_01"; break;
					case ENGLAND: NPChar.greeting = "Gr_f_officer_English"; break; // Grey Roger: replaces one citizen phrase with new audio files
					case FRANCE: NPChar.greeting = "Gr_Sylvie Bondies"; break;
					case PIRATE: NPChar.greeting = "Gr_greenford_citizen_01"; break;
					case HOLLAND: NPChar.greeting = "Gr_Tanneken Oremans"; break;
					NPChar.greeting = "Gr_f_officer";
				}
			}
			dialog.Text = DLG_Text[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "price";
			Link.l2 = DLG_TEXT[16];
            Link.l2.go = "Exit";
		break;

		case "price":
			//DeathDaisy -->
			string CaptSir;
			if(PChar.sex == "woman")
			{
				CaptSir = XI_ConvertString("ma'am");
			}
			else
			{
				CaptSir = XI_ConvertString("sir");
			}
			// DeathDaisy <--
			dialog.Text = DLG_TEXT[17] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[40] + strlower(GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + XI_ConvertString("captain") + " " + strlower(CaptSir)) + "?";	// LDH 16Apr09 | DeathDaisy: added code to translate "Mr. Captain sir?" to the proper gender, it looks a bit silly with Miss Captain ma'am, but so does Mr. Captain sir honestly
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "hire";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "Exit";
		break;

		case "trade":
			int ptest, ntest;
			ptest = 2+(CalcCharacterSkill(PChar,SKILL_COMMERCE)*1.5 + CalcCharacterSkill(PChar,SKILL_LEADERSHIP) + Rand(CalcCharacterSkill(PChar, SKILL_SNEAK)-1)+1)/2;
			ntest = GetLevel(NPChar)/5 + Rand(CalcCharacterSkill(NPChar,SKILL_COMMERCE)*2 + CalcCharacterSkill(NPChar,SKILL_LEADERSHIP) + CalcCharacterSkill(NPChar,SKILL_SNEAK)-4)+4;
			if(ptest >= ntest && makeint(NPChar.quest.OfficerPrice) >= GetLevel(NPChar)*100 + ptest*16)
			{
				NPChar.quest.OfficerPrice = makeint(NPChar.quest.OfficerPrice) - ptest*16;
				dialog.Text = PersuasionSuccess + DLG_TEXT[21] + CalcEncOfficerPrice(NPChar) + DLG_TEXT[40];	// LDH 16Apr09
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.Text = PersuasionFailure + DLG_TEXT[23];
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "exit";
			}
		break;

		case "hire":
			// LDH 16Apr09 -->
			int OfficerPrice = CalcEncOfficerPrice(NPChar);
			dialog.Text = DLG_TEXT[24];
			if(makeint(PChar.money) >= OfficerPrice)
			{
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "Exit_hire";
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -OfficerPrice);
  				AddWealthToCharacter(NPChar, OfficerPrice);
			}
			else
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "exit";
			}
			// LDH <--
		break;

		case "kill":
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Turn", 3.5);
					NPChar.standing = true;
				break;
			}
			if(CheckAttribute(NPChar, "honourable_surrender")) dialog.text = DLG_TEXT[54];
			else dialog.text = DLG_TEXT[9];
			switch(Rand(1))
			{
				case 0: 
					link.l1 = DLG_TEXT[10];
					if(CheckAttribute(NPChar, "honourable_surrender")) link.l1 = DLG_TEXT[55];
					link.l1.go = "exit_hanged";
				break;
				case 1: 
					link.l1 = DLG_TEXT[44];
					if(CheckAttribute(NPChar, "honourable_surrender")) link.l1 = DLG_TEXT[56];
					link.l1.go = "exit_sharks";
				break;
			}
			if(!CheckAttribute(NPChar, "honourable_surrender"))
			{
				Link.l2 = DLG_TEXT[29];	
				Link.l2.go = "kill_prisoner";
			}
			if(bAllowHireJoin)
			{
				link.l3 = DLG_TEXT[34];
				link.l3.go = "officer";
			}
			NPC_meeting = "1";
		break;

		case "kill_prisoner":
			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			NPChar.money = 0; // PB: If you kill him, you don't deserve the money!
			LAi_NPC_Equip(NPChar, sti(PChar.rank), true, 0.5);
			DeleteAttribute(NPChar,"prisoned");
			DeleteAttribute(NPChar,"status");
			RemovePassenger(PChar,NPChar);
			DeleteAttribute(NPChar,"ransom");
			NPChar.location = "none";
			DeleteAttribute(NPChar,"standing");
			LAi_SetImmortal(NPChar, false);
			LAi_group_MoveCharacter(NPChar, "prison");
			LAi_group_FightGroups("prison", LAI_GROUP_PLAYER, true);
			EndQuestMovie();TrackQuestMovie("end","prisoned_dialog.c -> kill_prisoner");
			DialogExit();
			DeleteAttribute(PChar,"prisonerIDX");
			LAi_SetFightMode(PChar, true);
		break;

		case "Exit_beat":
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					Lai_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "afraid", "", -1);
					DeleteAttribute(NPChar,"standing");
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_Afraid", "", -1);
				break;
			}
			Lai_SetActorType(PChar);
			LAi_ActorAnimation(PChar, "attack_2","Surrendered_Captain_Dialog", -1);
			DialogExit();
			LAi_CharacterPlaySound(NPChar, "OBJECTS\DUEL\punch"+sti(Rand(3)+3)+".wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar.prisoned,"indialog");
			DeleteAttribute(PChar,"prisonerIDX");
		break;

		case "Exit_afraid":
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					Lai_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "afraid", "", -1);
					DeleteAttribute(NPChar,"standing");
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_Afraid", "", -1);
				break;
			}
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar.prisoned,"indialog");
			DeleteAttribute(PChar,"prisonerIDX");
		break;

		case "Exit_hanged":
			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					Lai_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "afraid", "Surrendered_Captain_Dead", -1);
					DeleteAttribute(NPChar,"standing");
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_Afraid", "Surrendered_Captain_Dead1", -1);
				break;
			}
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			if(CheckAttribute(NPChar,"honourable_surrender"))
			{
				if (NPChar.nation!=PIRATE) Process_Execution(5);
				ChangeCharacterReputation(PChar, -10); // GR: promising good treatment and then executing prisoner is EVIL!
			}
			else
			{
				if (NPChar.nation!=PIRATE) Process_Execution(2);
				ChangeCharacterReputation(PChar, -5); // PB: Killing isn't very nice
			}
			ChangeCharacterAddressGroup(NPChar, "None", "", "");
			object HangFader;
			CreateEntity(&HangFader, "fader");
			SendMessage(&HangFader, "lfl", FADER_IN, 0.5, true);
			StartVideo("Blaze_mutiny_dead");
			PostEvent("LAi_RemoveDeadCap", 20, "i", NPChar);
			DialogExit();
		break;

		case "Exit_sharks":
			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					Lai_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "afraid", "Surrendered_Captain_Dead", -1);
					DeleteAttribute(NPChar,"standing");
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_Afraid", "Surrendered_Captain_Dead1", -1);
				break;
			}
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			if(CheckAttribute(NPChar,"honourable_surrender"))
			{
				if (NPChar.nation!=PIRATE) Process_Execution(5);
				ChangeCharacterReputation(PChar, -10); // GR: promising good treatment and then executing prisoner is EVIL!
			}
			else
			{
				if (NPChar.nation!=PIRATE) Process_Execution(2);
				ChangeCharacterReputation(PChar, -5); // PB: Killing isn't very nice
			}
			ChangeCharacterAddressGroup(NPChar, "None", "", "");
			object SharksFader;
			CreateEntity(&SharksFader, "fader");
			SendMessage(&SharksFader, "lfl", FADER_IN, 0.5, true);
			StartVideo("Sharks_attack");
			DialogExit();
			PostEvent("LAi_RemoveDeadCap", 20, "i", NPChar);
		break;

		case "Exit":
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_SitDown", "Surrendered_Captain_Poor", 3.5);
					DeleteAttribute(NPChar,"standing");
				break;
			}
			DialogExit();
			NPChar.greeting = "Gr_Smugglers_vs_Blythe";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar.prisoned,"indialog");
		break;

		case "release":
			LAi_SetCurHPMax(&NPChar);
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			DeleteAttribute(NPChar,"released");
			ChangeCharacterReputation(PChar, 4); // PB: Releasing without asking for money IS nice. GR: was 5, but you now get +1 for not taking his money earlier
			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner

			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					LAi_SetActorType(NPChar);
					LAi_ActorRunToLocation(NPChar, "reload", LAi_FindRandomLocator("reload"), "None", "", "", "", -1);
					RemovePassenger(PChar,NPChar);
					DeleteAttribute(NPChar,"prisoned");
					DeleteAttribute(NPChar,"standing");
					NPChar.ClearUponExit = true; // PB: So this guy is cleared upon exit
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Run", 3.5);
				break;
			}
			DialogExit();
		break;

		case "release_equip":
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			DeleteAttribute(NPChar,"released");
			LAi_NPC_Equip(NPChar, sti(PChar.rank), true, 0.5);
			ChangeCharacterReputation(PChar, 4); // PB: Releasing without asking for money IS nice. GR: was 5, but you now get +1 for not taking his money earlier
			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			LAi_SetCurHPMax(&NPChar);

			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					LAi_SetActorType(NPChar);
					LAi_ActorRunToLocation(NPChar, "reload", LAi_FindRandomLocator("reload"), "None", "", "", "", -1);
					RemovePassenger(PChar,NPChar);
					DeleteAttribute(NPChar,"prisoned");
					DeleteAttribute(NPChar,"standing");
					NPChar.ClearUponExit = true; // PB: So this guy is cleared upon exit
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Run", 3.5);
				break;
			}
			DialogExit();
		break;

		case "exit_hire":
		// TIH --> adjusted method Jul19'06
			NPChar.quest.meeting = NPC_Meeting;
			TIH_PrisonerHiredAsOfficerProcess(NPChar, true, true, false);// bLowSalary, bSetType, bCreateOfficer // KK
			DialogExit();
			DeleteAttribute(PChar,"prisonerIDX");
//			ChangeCharacterAddressGroup(NPChar, "None", "", ""); // KK
			//TIH_OfficerHiredShow(true, true, true);// TIH show the new officer on the deck and start new dialog
			// KK TIH_OfficerHiredShow(false, true, true);// TIH DON'T show the new officer on the deck and start new dialog Aug24'06
		// TIH <--
		break;

		case "exit_money":
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			AddMoneyToCharacter(PChar,sti(NPChar.Money));
			PlayStereoSound("INTERFACE\took_item.wav");

			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					LAi_SetActorType(NPChar);
					LAi_ActorRunToLocation(NPChar, "reload", LAi_FindRandomLocator("reload"), "None", "", "", "", -1);
					RemovePassenger(PChar,NPChar);
					DeleteAttribute(NPChar,"prisoned");
					DeleteAttribute(NPChar,"standing");
					NPChar.ClearUponExit = true; // PB: So this guy is cleared upon exit
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Run", 3.5);
				break;
			}
			DialogExit();
		break;

		case "exit_ransom":
			DeleteAttribute(NPChar,"status");
			DeleteAttribute(NPChar,"ransom");
			AddMoneyToCharacter(PChar,prisonRansomCost);
			PlayStereoSound("INTERFACE\took_item.wav");

			if(GetMySimpleOldName(NPChar) == "Robert Christopher Silehard") DeleteAttribute(CharacterFromID("Robert Christopher Silehard"),"prisoned");	// GR: needed for "standard" storyline so you don't tell governor that Silehard is a prisoner
			switch(NPChar.chr_ai.type)// MAXIMUS: just a little fun in the game
			{
				case LAI_TYPE_STAY:
					LAi_SetActorType(NPChar);
					LAi_ActorRunToLocation(NPChar, "reload", LAi_FindRandomLocator("reload"), "None", "", "", "", -1);
					RemovePassenger(PChar,NPChar);
					DeleteAttribute(NPChar,"prisoned");
					DeleteAttribute(NPChar,"standing");
					NPChar.ClearUponExit = true; // PB: So this guy is cleared upon exit
				break;

				case LAI_TYPE_POOR:
					LAi_SetActorType(NPChar);
					LAi_ActorAnimation(NPChar, "Ground_StandUp", "Surrendered_Captain_Run", 3.5);
				break;
			}
			DialogExit();
		break;
	}
}
