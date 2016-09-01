void ProcessDialogEvent()
{
	ref NPChar, crew;
	aref Link, Diag;
	int con;
	string loc;
	int NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int loc_id = FindLocation(PChar.location);
	NPChar.quest.officertype = OFFIC_TYPE_ABORDAGE;
	int min_off_price = makeint( 1000 * sqrt(sti(NPChar.rank)) );
	if(sti(NPChar.quest.OfficerPrice) < min_off_price) NPChar.quest.OfficerPrice = min_off_price; // PB: Increased salary for better crewmember as officer

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
				Dialog.defAni = "dialog_stay1";
				Dialog.defCam = "1";
				Dialog.defSnd = "dialogs\0\017";
				Dialog.defLinkAni = "dialog_1";
				Dialog.defLinkCam = "1";
				Dialog.defLinkSnd = "dialogs\woman\024";
				Dialog.ani = "dialog_stay2";
				Dialog.cam = "1";
				Dialog.snd = "voice\PADI\PADI001";

				switch(makeint(Npchar.nation))
				{
					case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_005.wav");}else{PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_f_c_003.wav");}break;
					case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_001.wav");}else{PlaySound("VOICE\" + LanguageGetLanguage() + "\Fra_f_a_003.wav");}break;
					case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_003.wav");}break;
					case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_001.wav");}break;
					case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_003.wav");}else{PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_003.wav");}break;
					case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_004.wav");}break;
				}

				Dialog.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit";
				Link.l2 = DLG_TEXT[2];
				Link.l2.go = "weapons";
				Link.l3 = DLG_TEXT[3];
				Link.l3.go = "clothesyou";
				if(!CheckAttribute(Pchar, "quest.OldCrewMember"))
				{
					if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
					{
						Link.l4 = "You must have gained some experience serving under me. But how good are you really?";
						Link.l4.go = "ShowSkills";
						Link.l5 = "I am very pleased with your performance. Therefore I am promoting you to officer. Please collect your warrant papers from the ship's purser and meet me later.";
						Link.l5.go = "enlist_me";
					}
				}

				if(MAX_CREWMEMBERS>0)
				{
					Link.l6 = DLG_TEXT[7];
					Link.l6.go = "returntoshipalone";
				}
				Link.l7 = DLG_TEXT[4];
				Link.l7.go = "returntoship";
				if(loc_id != -1)
				{
					if(HasSubStr(locations[loc_id].type, "jungle") || HasSubStr(locations[loc_id].type, "shore") )
					{
						if (makeint(environment.time) >= 21.0 || makeint(environment.time) < 8.0)
						{
							link.l8 = DLG_TEXT[8];
							link.l8.go = "camp_day";
						}
						else
						{
							link.l8 = DLG_TEXT[9];
							link.l8.go = "camp_night";
						}
					}
				}
				Diag.TempNode = "first time";
		break;

		case "ShowSkills":
			// Aconcagua: LaunchOfficer uses separate interface now
			Diag.CurrentNode = "ReturnfromSkillview";
			NPChar.quest.OfficerPrice = CalcEncOfficerPrice(NPChar);
			Pchar.Quest.Last_Enc_Officer = NPChar.Index;
			DialogExit();			
			LaunchOfficer(NPChar); // MAXIMUS interface MOD
		break;

		case "ReturnfromSkillview":
			Dialog.Text = "What do you think of my qualities, captain?";
			Link.l1 = "I am well impressed. Therefore I am promoting you to officer. Please collect your warrant papers from the ship's purser and meet me later.";
			Link.l1.go = "enlist_me";
			Link.l2 = "You'll make a fine sailor; you can get back to work.";
			Link.l2.go = "exit";
		break;

		case "enlist_me":
			if(MAX_CREWMEMBERS>1){MAX_CREWMEMBERS=MAX_CREWMEMBERS-1;}
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			NPChar.offgen = true;
			NPChar.officer = true;
			SetRandomNameToCharacter(NPChar); // Give a name

			NPChar.quest.OfficerPrice = CalcEncOfficerPrice(NPChar);
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			Pchar.quest.OldCrewMember = NPChar.id;
			AddDialogExitQuest("LandEnc_OfficerHired");
			NPChar.quest.meeting = NPC_Meeting;

			Diag.CurrentNode = "hired";
			DialogExit();
		break;

		case "install_camp":
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddGeometryToLocation(PChar.location, "smg");
		break;

		case "camp_day":
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "camp_day_wait";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "exit";
		break;

		case "camp_night":
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "camp_night_wait";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "exit";
		break;

		case "camp_night_wait":
			DialogExit();
			TavernWaitDate("wait_night");
			PlaySound("objects\abordage\abordage_loosing.wav");
			Whr_UpdateWeather(false);

		break;

		case "camp_day_wait":
			DialogExit();
			TavernWaitDate("wait_day");
			PlaySound("NATURE\cricket.wav");
			PlaySound("NATURE\fireplace1.wav");
			PlaySound("AMBIENT\town\cough.wav");
			PlaySound("AMBIENT\tavern\man1.wav");
			PlaySound("AMBIENT\tavern\open_bottle.wav");
			Whr_UpdateWeather(false);
		break;

		case "take_no_ammo":
			PlaySound("VOICE\ENGLISH\Eng_m_a_083.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "weapons";
		break;
//JRH-->
		case "weapons":
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
		//	DialogExit();
		//	LaunchCharacterItemChange(NPChar);
		break;
//<-- JRH
		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

		case "returntoshipalone":
			Dialog.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "exit_alone";
		break;

		case "returntoship":
			Dialog.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "exit_return";
		break;

		case "exit_return":
			for(con =  1; con <= 10 ; con++)
			{
				crew = characterFromID("Treas_Crewmember_" + con);
				// PB: Cursed Coins -->
				if(CheckCharacterItem(crew, "cursedcoin"))
				{
					GiveItem2Character(PChar, "cursedcoin");
					TakeItemFromCharacter(crew, "cursedcoin");
				}
				// PB: Cursed Coins <--
				if(Lai_IsDead(crew)){RemoveCharacterCrew(PChar,1); LAi_SetHP(crew, PChar.chr_ai.hp_max, PChar.chr_ai.hp);}
				loc = LAi_FindRandomLocator("reload");
				LAi_SetActorType(crew);
				LAi_ActorRunToLocation(crew, "reload", loc, "None", "reload", "", "", 20.0);
			}
			LANDCREWMEMBERS = false;
			DialogExit();
		break;

		case "exit_alone":
			if(MAX_CREWMEMBERS>1){MAX_CREWMEMBERS=MAX_CREWMEMBERS-1;}
			// PB: Cursed Coins -->
			if(CheckCharacterItem(NPChar, "cursedcoin"))
			{
				GiveItem2Character(PChar, "cursedcoin");
				TakeItemFromCharacter(NPChar, "cursedcoin");
			}
			// PB: Cursed Coins <--
			loc = LAi_FindRandomLocator("reload");
			LAi_SetActorType(Npchar);
			LAi_ActorRunToLocation(Npchar, "reload", loc, "None", "reload", "", "", 20.0);
			DialogExit();
		break;
	}
}
