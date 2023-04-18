void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int con, maxcrew, idx, tmpi, fskill;
	tmpi = GetCharacterIndex(NPChar.id);
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1)
			{
				link.l2 = DLG_TEXT[2];
				link.l2.go = "Howmany";
			}
			//Link.l3 = DLG_TEXT[3];
			//Link.l3.go = "clothesyou";

			//Levis Add Waiting Time options -->
			//Moved weaponslocker to next dialog to make room for more.
			Link.l4 = DLG_TEXT[39];
			Link.l4.go = "Information";
			
			//Levis Add Waiting Time options <--
			//PURSEON ==================== Begin Training fight Section ===================>
			if(HasSubStr(PChar.location,"ShipDeck") && !CheckAttribute(PChar,"TrainingFight"))
			{
				Preprocessor_Add("lad", GetCharacterAddressForm(NPChar, ADDR_INFORMAL, false, false)); // DeathDaisy
				Link.l5 = DLG_TEXT[28];
				Link.l5.go = "MakeChoice";
			}
			Diag.TempNode = "first time";
		break;

		case "MakeChoice":
			Dialog.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "TrainingFight1";
			Link.l3 = DLG_TEXT[31];
			Link.l3.go = "TrainingFight2";
		break;

		case "TrainingFight1":
			NPChar.old.id = NPChar.id;
			NPChar.id = "TrainingFight_1";
			LAi_type_actor_Reset(Pchar);
			LAi_type_actor_Reset(CharacterFromID("TrainingFight_1")); 
			PChar.TrainingFight.leader = GetCharacterIndex(NPChar.id);
			PChar.TrainingFight.level = 1;
			AddDialogExitQuest("StartTrainingFight");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "TrainingFight2":
			NPChar.old.id = NPChar.id;
			NPChar.id = "TrainingFight_1";
			LAi_type_actor_Reset(Pchar);
			LAi_type_actor_Reset(NPChar); 
			PChar.TrainingFight.leader = GetCharacterIndex(NPChar.id);
			PChar.TrainingFight.level = 2;
			AddDialogExitQuest("StartTrainingFight");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "ContinueTrainingFight":
			AddDialogExitQuest("StartTrainingFight");
			DialogExit();
		break;

		case "EnoughForYou1":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "ContinueTrainingFight";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "FinishingTrainingFight";
		break;

		case "EnoughForYou2":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "ContinueTrainingFight";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "FinishingTrainingFight";
		break;

		case "FinishingTrainingFight":
			AddDialogExitQuest("player_back"); // PB: Reset Player
			//Levis Unlock Perk
			if(sti(PChar.TrainingFight.level) >= 2 && CheckCharacterPerkLocked(Pchar, "SwordplayProfessional"))
			{
				UnlockPerkCharacter(PChar ,"SwordplayProfessional");
			}
			LAi_SetCitizenType(CharacterFromID("TrainingFight_1"));
			LAi_group_MoveCharacter(CharacterFromID("TrainingFight_1"), LAI_GROUP_PLAYER);
			PChar.TrainingFight.member = Characters[GetCharacterIndex("TrainingFight_1")].old.id;
			Characters[GetCharacterIndex("TrainingFight_1")].id = PChar.TrainingFight.member;
			DeleteAttribute(CharacterFromID(PChar.TrainingFight.member),"old.id");
			DeleteAttribute(PChar,"TrainingFight.member");
			DeleteAttribute(PChar,"TrainingFight.level");
			DeleteAttribute(PChar,"TrainingFight");
			DialogExit();
			Diag.CurrentNode = "first time";
		break;
		//PURSEON ======================= End Training fight Section ==========================<
		
		//Levis Add Waiting Time options -->
		case "Information":
			Dialog.Text = DLG_TEXT[40];
			// KK -->
			if (GetCharacterShipCabin(PChar) == "Cabin_none") {
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "weaponslocker";
			}
			// <-- KK
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "whatsthetime";
			link.l4 = DLG_TEXT[42];
			link.l4.go = "exit";
		break;
		
		case "whatsthetime":
			if(PChar.sex == "woman")	
			{
				Preprocessor_Add("sir", FirstLetterUp(XI_ConvertString("ma'am"))); // DeathDaisy
			}
			else
			{
				Preprocessor_Add("sir", FirstLetterUp(XI_ConvertString("sir"))); // DeathDaisy
			}
			Dialog.Text = DLG_TEXT[43]+GetTimeText(GetTime())+DLG_TEXT[44];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "Wait1hour";
			Link.l2 = DLG_TEXT[47];
			Link.l2.go = "Wait8hours";
			Link.l3 = DLG_TEXT[48];
			Link.l3.go = "wait_custom";
			Link.l4 = DLG_TEXT[45];
			Link.l4.go = "Exit_reset";
		break;
			
		case "Wait1hour":
			DialogExit();
			WaitDate("", 0,0,0,1,0);
			PChar.waitedonship = NPChar.id;
			AddDialogExitQuest("waited_on_ship_for_time");
			LAi_Fade("", "");
		break;

		case "Wait8hours":
			DialogExit();
			WaitDate("", 0,0,0,8,0);
			PChar.waitedonship = NPChar.id;
			AddDialogExitQuest("waited_on_ship_for_time");
			LAi_Fade("", "");
		break;
		//Levis Add Waiting Time options <--

		case "wait_custom":
			Dialog.Text = DLG_TEXT[49];
			Link.l1 = "";
			Link.l1.edit = "string";
			Link.l1.go = "wait_custom_submit";
		break;

		case "wait_custom_submit":
			if(PChar.sex == "woman")
			{
				Preprocessor_Add("sir", XI_ConvertString("ma'am")); // DeathDaisy
			}
			else
			{
				Preprocessor_Add("sir", XI_ConvertString("sir")); // DeathDaisy
			}

			int value = sti(Dialog.value);

			int hours = 0;
			int minutes = 0;

			bool isInvalid = false;

			if (value <= 0) {
				isInvalid = true;
			}

			if (value < 24) {
				hours = tmpi;
			}
			if (value >= 24 && value < 100) {
				DialogExit();
				isInvalid = true;
			}
			if (value >= 100) {
				hours = value / 100;
				minutes = value % 100;
				if (minutes >= 60) {
					isInvalid = true;
				}
			}

			if (isInvalid) {
				Dialog.Text = DLG_TEXT[54];
				Link.l1 = DLG_TEXT[55];
				Link.l1.go = "wait_custom";
				Link.l2 = DLG_TEXT[56];
				Link.l2.go = "Exit_reset";
				break;
			}

			float desiredTime = hours + makefloat(minutes)/60.0);
			float currentTime = GetTime();
			float diff = desiredTime - currentTime;
			if (diff < 0) {
				diff += 24.0;
			}
			if (diff > 24.0) {
				diff -= 24.0;
			}
			Pchar.Quest.TimeToWait = diff;

			Dialog.Text = DLG_TEXT[50] + GetTimeText(hours + (minutes/60.0)) + DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "wait_custom_confirm";
			Link.l2 = DLG_TEXT[53];
			Link.l2.go = "Exit_reset";
		break;

		case "wait_custom_confirm":
			float timeToWait = stf(Pchar.Quest.TimeToWait);
			WaitDate("", 0,0,0,makeint(timeToWait),makeint((timeToWait - makeint(timeToWait)) * 60.0));
			LAi_Fade("", "");
			DialogExit();
		break;

		case "Howmany":
			Dialog.Text = DLG_TEXT[5];
			maxcrew = GetMaxLandCrew(sti(PChar.Ship.Crew.Quantity));
			{ 
				link.l1 = DLG_TEXT[6];
				link.l1.go ="one";
				if(maxcrew>=2)
				{
					link.l2 = DLG_TEXT[7];
					link.l2.go = "two";
				}
				if(maxcrew>=3)
				{
					link.l3 = DLG_TEXT[8];
					link.l3.go = "three";
				}
				if(maxcrew>=4)
				{
					link.l4 = DLG_TEXT[9];
					link.l4.go = "four";
				}
				if(maxcrew>=5)
				{
					link.l5 = DLG_TEXT[10];
					link.l5.go = "five";
				}
				if(maxcrew>=6)
				{
					link.l6 = DLG_TEXT[11];
					link.l6.go = "six";
				}
				if(maxcrew>=7)
				{
					link.l7 = DLG_TEXT[12];
					link.l7.go = "seven";
				}
				if(maxcrew>=8)
				{
					link.l8 = DLG_TEXT[13];
					link.l8.go = "eight";
				}
				if(maxcrew>=9)
				{
					link.l9 = DLG_TEXT[14];
					link.l9.go = "nine";
				}
				if(maxcrew>=10)
				{
					link.l10 = DLG_TEXT[15];
					link.l10.go = "ten";
				}
			}
			link.l11 = DLG_TEXT[27];
			link.l11.go = "exit";
		break;

		case "one":
			Dialog.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 1;
		break;

		case "two":
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 2;
		break;

		case "three":
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 3;
		break;

		case "four":
			Dialog.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 4;
		break;

		case "five":
			Dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 5;
		break;

		case "six":
			Dialog.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 6;
		break;

		case "seven":
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 7;
		break;

		case "eight":
			Dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 8;
		break;

		case "nine":
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 9;
		break;

		case "ten":
			Dialog.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 10;
		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

// KK -->
		case "weaponslocker":
			DialogExit();
			PChar.boxname = "weaponslocker";
			aref ar; makearef(ar, Locations[FindLocation("Tutorial_Deck")].weaponslocker);
			LaunchItemsBox(&ar);
			DeleteAttribute(PChar, "boxname");
		break;
// <-- KK

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
		
		case "Exit_reset":
			AddDialogExitQuest("reset after waiting");
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
