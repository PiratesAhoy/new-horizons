void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
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
			
			Diag.TempNode = "First Time";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\EVGO\EVGO001";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "Voice\EVGO\EVGO002";
				dialog.snd2 = "Voice\EVGO\EVGO003";
				dialog.snd3 = "Voice\EVGO\EVGO004";
				d.Text = RandPhrase(DLG_TEXT[4] + GetMyName(Pchar) + DLG_TEXT[5], TimeGreeting() + DLG_TEXT[6], DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[9];
				if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
				{
					Link.l1.go = "no crew";
				}
				else
				{
					Link.l1.go = "crew hire";
				}
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "quest lines";
				link.l3 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
				link.l3.go = "room";
				Link.l99 = DLG_TEXT[13] + GetMyName(NPChar) + DLG_TEXT[14];
				Link.l99.go = "exit";
			} 
		break;
		
		case "Meeting":
			dialog.snd = "Voice\EVGO\EVGO005";
			d.Text = DLG_TEXT[15] + GetMyName(Pchar) + DLG_TEXT[16], ;
			Link.l1 = DLG_TEXT[17];
			if(CheckAttribute(PChar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "no crew";
			}
			else
			{
				Link.l1.go = "crew hire";
			}
			Link.l2 = GetMyName(NPChar) + DLG_TEXT[18];
			Link.l2.go = "quest lines";
			link.l3 = pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]);
			link.l3.go = "room";
			Link.l4 = DLG_TEXT[21] + GetMyName(NPChar) + DLG_TEXT[22];
			Link.l4.go = "exit";
		break;

		case "room":
			dialog.snd = "Voice\EVGO\EVGO006";
			dialog.text = DLG_TEXT[23];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[24];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[25];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[26];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[27];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "quest lines";
		break;

		case "room_24_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "hall_24_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			LAi_Fade("", "");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "room_day":
			dialog.snd = "Voice\EVGO\EVGO007";
			Dialog.text = DLG_TEXT[26];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[27];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "quest lines";
		break;

		case "room_night":
			dialog.snd = "Voice\EVGO\EVGO008";
			Dialog.text = DLG_TEXT[31];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[32];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[33], DLG_TEXT[34]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[35];
			link.l3.go = "quest lines";
		break;

		case "room_night_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_night");
		break;

		case "hall_night_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "quest lines":
			dialog.snd = "Voice\EVGO\EVGO009";
			d.Text = DLG_TEXT[36] + GetMyName(Pchar) + DLG_TEXT[37];
			if(CheckAttribute(Pchar, "quest.Story_1stTaskReceived"))
			{
				Link.l1 = DLG_TEXT[38];
				Link.l1.go = "Story_1stTask";
			}
			else
			{
			
				Link.l1 = DLG_TEXT[39];
				Link.l1.go = "rumours";
				Link.l2 = DLG_TEXT[40];
				Link.l2.go = "quest lines_1";
			}
		break;

		case "quest lines_1":
			dialog.snd = "Voice\EVGO\EVGO010";
			d.Text = DLG_TEXT[41];
			if(CheckAttribute(PChar, "quest.Story_2ndTask") && Pchar.quest.Story_2ndTask == "Second_part")
			{
				Link.l1 = DLG_TEXT[43] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[44])]) + DLG_TEXT[45];
				Link.l1.go = "Counterspy";
			}
			if( CheckQuestAttribute("AgentConveyToOxbay","start") )
			{				
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "AskAboutBeauvallet";
			}
			if( CheckQuestAttribute("frigate_sink","start") || CheckQuestAttribute("frigate_sink","crew") )
			{
				Link.l1 = DLG_TEXT[47];
				Link.l1.go = "frigate_sink_start_1";				
			}
			if( CheckQuestAttribute("frigate_sink","ReadySteadyGo") )
			{
				Link.l1 = DLG_TEXT[48] + GetMyName(NPChar) + DLG_TEXT[49];
				Link.l1.go = "frigate_sink_crew_1";				
			}
			if (CheckQuestAttribute("ANIMISTS", "to_greenford_for_teacher"))
			{
				link.l1 = DLG_TEXT[50];
				link.l1.go = "to_greenford_for_teacher_2";
			}
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date && !CheckAttribute(PChar, "Quest.Story_OxbayCaptured"))
			{
				link.l11 = DLG_TEXT[51];
				link.l11.go = "convoy";
			}
			if (CheckQuestAttribute("ardent_convoy", "Oxbay"))
			{
				link.l1 = DLG_TEXT[161];
				link.l1.go = "ardent_convoy";
			}
			Link.l99 = DLG_TEXT[42];
			Link.l99.go = "No quest";
		break;
		
		case "convoy":
			npchar.work = lastspeak_date;
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[52];
				link.l1 = DLG_TEXT[53];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY) // KK
				{
					dialog.text = DLG_TEXT[54];
					link.l1 = DLG_TEXT[55];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[56];
						link.l1 = DLG_TEXT[57];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[58];
							link.l1 = DLG_TEXT[59];
							link.l1.go = "exit";
							AddDialogExitQuest("prepare_for_convoy_quest");
							
						}
						else
						{
							dialog.text = DLG_TEXT[60];
							link.l1 = DLG_TEXT[61];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;

		case "to_greenford_for_teacher_2":
			dialog.snd = "Voice\EVGO\EVGO011";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_prison_for_teacher";
			AddQuestRecord("ANIMISTS", 27);
		break;

		case "rumours":
			d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) ); // KK
			Link.l1 = DLG_TEXT[64];
			if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "no crew";
			}
			else
			{
				Link.l1.go = "crew hire";
			}
			Link.l2 = DLG_TEXT[65];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[66] + GetMyName(NPChar) + DLG_TEXT[67];
			Link.l3.go = "exit";
		break;
		
		case "no quest":
			dialog.snd = "Voice\EVGO\EVGO012";
			d.Text = DLG_TEXT[68];
			Link.l1 = DLG_TEXT[69];
			if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "no crew";
			}
			else
			{
				Link.l1.go = "crew hire";
			}
			Link.l2 = DLG_TEXT[70];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[71] + GetMyName(NPChar) + DLG_TEXT[72];
			Link.l3.go = "exit";
		break;

		case "no crew":
			dialog.snd = "Voice\EVGO\EVGO013";
			d.Text = DLG_TEXT[73];
			Link.l1 = DLG_TEXT[74];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[75] + GetMyName(NPChar) + DLG_TEXT[76];
			Link.l2.go = "exit";
		break;

		case "Story_1stTask":
			PChar.quest.Story_1stTaskReceived.over = "yes";
			dialog.snd = "Voice\EVGO\EVGO014";
			d.Text = DLG_TEXT[77] + DLG_TEXT[78] + DLG_TEXT[79];
			Link.l1 = DLG_TEXT[80] + GetMyName(NPChar) + DLG_TEXT[81];
			Link.l1.go = "Story_1stTask_Male_1";
		break;

		case "Story_1stTask_Male_1":
			dialog.snd = "Voice\EVGO\EVGO016";
			d.Text = DLG_TEXT[84];
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "Story_1stTask_Male_2";
		break;

		case "Story_1stTask_Male_2":
			dialog.snd = "Voice\EVGO\EVGO017";
			d.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[87];
			Link.l1.go = "Story_1stTask_Male_3";
		break;

		case "Story_1stTask_Male_3":
			dialog.snd = "Voice\EVGO\EVGO018";
			d.Text = DLG_TEXT[88];
			Link.l1 = DLG_TEXT[89];
			Link.l1.go = "Story_1stTask_Male_4";
		break;

		case "Story_1stTask_Male_4":
			dialog.snd = "Voice\EVGO\EVGO019";
			d.Text = DLG_TEXT[90] + GetMyName(Pchar) + DLG_TEXT[91];
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "Story_1stTask_Male_5";
		break;

		case "Story_1stTask_Male_5":
			dialog.snd = "Voice\EVGO\EVGO020";
			d.Text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "Story_1stTask_Male_6";
		break;
		
		case "Story_1stTask_Male_6":
			dialog.snd = "Voice\EVGO\EVGO021";
			d.Text = DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "Story_1stTask_Male_7";
		break;

		case "Story_1stTask_Male_7":
			dialog.snd = "Voice\EVGO\EVGO022";
			d.Text = DLG_TEXT[97] + GetMyName(Pchar) + DLG_TEXT[98];
			Link.l1 = DLG_TEXT[99];
			Link.l1.go = "Story_1stTask_Male_8";
		break;

		case "Story_1stTask_Male_8":
			dialog.snd = "Voice\EVGO\EVGO023";
			d.Text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "Story_1stTask_Male_9";
		break;

		case "Story_1stTask_Male_9":
			dialog.snd = "Voice\EVGO\EVGO024";
			d.Text = DLG_TEXT[102];
			Link.l1 = DLG_TEXT[103];
			Link.l1.go = "Story_1stTask_Male_10";
		break;
	
		case "Story_1stTask_Male_10":
			dialog.snd = "Voice\EVGO\EVGO025";
			d.Text = DLG_TEXT[104] + GetMyName(Pchar) + DLG_TEXT[105];
			Link.l1 = DLG_TEXT[106];
			Link.l1.go = "Story_1stTask_Male_11";
		break;

		case "Story_1stTask_Male_11":
			dialog.snd = "Voice\EVGO\EVGO026";
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "Story_first talk";
			d.Text = DLG_TEXT[107] + GetMyName(Pchar) + DLG_TEXT[108];
			Link.l1 = DLG_TEXT[109];
			Link.l1.go = "Story_1stTask_Male_12";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "Story_1stTask_Male_13";
		break;

		case "Story_1stTask_Male_12":
			if(CalcCharacterSkill(PChar,SKILL_LEADERSHIP) >= 2) // NK
			{
				AddQuestRecord("Story_1stTaskReceived",2);
				dialog.snd = "Voice\EVGO\EVGO027";
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				d.Text = PersuasionSuccess + DLG_TEXT[111];
				Link.l1 = DLG_TEXT[112];
				Link.l1.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\EVGO\EVGO028";
				d.Text = PersuasionFailure + DLG_TEXT[113];
				Link.l1 = DLG_TEXT[114];
				Link.l1.go = "Story_1stTask_Male_14";
				Link.l1 = DLG_TEXT[115];
				Link.l1.go = "Story_1stTask_Male_13";
			}
		break;

		case "Story_1stTask_Male_13":
			dialog.snd = "Voice\EVGO\EVGO029";
			d.Text = DLG_TEXT[116] + (10*(10 - CalcCharacterSkill(PChar,SKILL_COMMERCE))) + DLG_TEXT[117]; // NK
			if(makeint(Pchar.money) >= (10*(10 - CalcCharacterSkill(PChar,SKILL_COMMERCE)))) // NK
			{
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "Story_1stTask_Male_15";
			}
			else
			{
			Link.l1 = DLG_TEXT[119];
			Link.l1.go = "Story_1stTask_Male_15";
			}
		break;



		case "Story_1stTask_Male_14":	
			dialog.snd = "Voice\EVGO\EVGO030";	
			d.Text = DLG_TEXT[120];
			Link.l1 = DLG_TEXT[121];
			Link.l1.go = "Story_1stTask_Male_13";
		break;

		case "Story_1stTask_Male_15":
			AddQuestRecord("Story_1stTaskReceived",2);
			if(makeint(Pchar.money) >= (10*(10 - CalcCharacterSkill(PChar,SKILL_COMMERCE)))) // NK
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -(10*(10 - CalcCharacterSkill(PChar,SKILL_COMMERCE)))); // NK
				dialog.snd = "Voice\EVGO\EVGO031";	
				d.Text = DLG_TEXT[122] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[123];
				Link.l1 = DLG_TEXT[124];
				Link.l1.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\EVGO\EVGO032";	
				d.Text = DLG_TEXT[125];
				Link.l1 = DLG_TEXT[126];
				Link.l1.go = "exit";
			}
		break;

		case "Story_1stTask_female_1":
			AddQuestRecord("Story_1stTaskReceived",3);
			AddDialogExitQuest("EverardGordon_speak_break");
			dialog.snd = "Voice\EVGO\EVGO033";	
			d.Text = DLG_TEXT[127];
			Link.l1 = DLG_TEXT[128];
			Link.l1.go = "exit";
		break;

		case "wait_for_morning":
			dialog.snd = "Voice\EVGO\EVGO034";	
			d.Text = DLG_TEXT[129];
			Link.l1 = DLG_TEXT[130];
			Link.l1.go = "exit";
			if( sti(PChar.Money) >= 10 )
			{
				Link.l2 = DLG_TEXT[131];
				Link.l2.go = "wait_for_morning_accord";
			}
		break;

		case "AskAboutBeauvallet":
			dialog.snd = "Voice\EVGO\EVGO035";	
			d.Text = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[132])]) + DLG_TEXT[134];
			Link.l1 = DLG_TEXT[135];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_1stTask_EverardTalk");
			DeleteQuestAttribute("AgentConveyToOxbay");
		break;
			
		case "wait_for_morning_accord":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,-10);
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			SetCurrentTime(8, 0);
			Trace("Do Wait date");
			WaitDate("",0,0,1,0,0);
			DialogExit();
		break;

		case "frigate_sink_start_1":
			dialog.snd = "Voice\EVGO\EVGO036";	
			d.Text = DLG_TEXT[136];
			Link.l1 = DLG_TEXT[137];
			Link.l1.go = "frigate_sink_start_2";
		break;

		case "frigate_sink_start_2":
			dialog.snd = "Voice\EVGO\EVGO037";	
			d.Text = DLG_TEXT[138];
			Link.l1 = DLG_TEXT[139];
			Link.l1.go = "frigate_sink_start_3";
		break;

		case "frigate_sink_start_3":	
			dialog.snd = "Voice\EVGO\EVGO038";			
			d.Text = DLG_TEXT[140];
			if( CheckQuestAttribute("frigate_sink", "start") )
			{	
				PChar.quest.frigate_sink = "boat";
				AddQuestRecord("Story_1stTaskReceived",111);
				Link.l1 = DLG_TEXT[141] + GetMyName(NPChar) + DLG_TEXT[142];
				Link.l1.go = "exit";
			}
			
			if( CheckQuestAttribute("frigate_sink", "crew") )
			{
				PChar.quest.frigate_sink = "preparation";
				AddQuestRecord("Story_1stTaskReceived",111);
				Link.l1 = DLG_TEXT[143];
				Link.l1.go = "frigate_sink_start_4";
			}

		break;

		case "frigate_sink_start_4":
			dialog.snd = "Voice\EVGO\EVGO039";	
			PChar.quest.frigate_sink = "preparation";
			AddDialogExitQuest("Fem_WaitingForNightToBlowFrigate");
			d.Text = DLG_TEXT[144];
			Link.l1 = DLG_TEXT[145];
			Link.l1.go = "Exit";
		break;

		case "frigate_sink_crew_1":
			dialog.snd = "Voice\EVGO\EVGO040";	
			d.Text = DLG_TEXT[146] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[147];
			Link.l1 = DLG_TEXT[148];
			Link.l1.go = "frigate_sink_crew_2";
		break;

		case "frigate_sink_crew_2":
			dialog.snd = "Voice\EVGO\EVGO041";	
			d.Text = DLG_TEXT[149];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "frigate_sink_crew_3";
			PChar.quest.frigate_sink = "preparation";
		break;

		case "frigate_sink_crew_3":
			dialog.snd = "Voice\EVGO\EVGO042";	
			d.Text = DLG_TEXT[151];
			Link.l1 = DLG_TEXT[152] + GetMyName(NPChar) + DLG_TEXT[153];
			Link.l1.go = "exit";
			PChar.quest.frigate_sink = "preparation";
			AddDialogExitQuest("Fem_WaitingForNightToBlowFrigate");
		break;

		case "Counterspy":
			dialog.snd = "Voice\EVGO\EVGO043";	
			d.Text = DLG_TEXT[154];
			Link.l1 = DLG_TEXT[155];
			Link.l1.go = "exit";
		break;

		case "ardent_convoy":
			d.Text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "ardent_convoy2";
		break;

		case "ardent_convoy2":
			PChar.quest.ardent_convoy = "Cartagena";
			AddQuestRecord("Convoy Strike", 3);
			d.Text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "exit";
		break;

		case "crew hire":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			if (makeint(environment.time) <= 22.0 && makeint(environment.time) >= 10.0)
			{
				Diag.CurrentNode =  Diag.TempNode;				
				DialogExit();
				launchhirecrew();
			}
			else
			{
				dialog.snd = "Voice\EVGO\EVGO044";	
				dialog.text = DLG_TEXT[156];
				link.l1 = DLG_TEXT[157];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[158];
				link.l2.go = "quest lines";
			}
			//DialogExit();
		break;
	
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "tavern_keeper":
			Diag.TempNode = "First time";
			
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\EVGO\EVGO045";	
			dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
	}
}
