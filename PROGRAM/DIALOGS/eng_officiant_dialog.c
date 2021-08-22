void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	string shiploc = ""; // KK
	string ShipLocationName = ""; // KK
	string name; //Levis

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	// MAXIMUS -->
	string curGreeting = "";
	if(CheckAttribute(NPChar,"greeting")) { curGreeting = NPChar.greeting; }
	if (CheckAttribute(NPChar, "isResurrecting") == true && sti(NPChar.isResurrecting) == true) // KK
	{
		//JRH -->
		if(Pchar.location == "wr_claire")
		{
			NPChar.greeting = "VOICE\" + LanguageGetLanguage() + "\claire_welcome.wav";
		}
		//<-- JRH
		else NPChar.greeting = "VOICE\" + LanguageGetLanguage() + "\Fre_f_a_006.wav";
	}
	else NPChar.greeting = curGreeting;
	// MAXIMUS <--
	
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
			NextDiag.TempNode = "first time";

			//ccc Survival ->
			if (CheckAttribute(NPChar, "isResurrecting") == true && sti(NPChar.isResurrecting) == true) // KK
			{
				//JRH quest alternative Rdm -->
				if(Pchar.location == "wr_claire")
				{
					dialog.text = DLG_TEXT[18] + DLG_TEXT[45];
					link.l1 = DLG_TEXT[20];
					link.l1.go = "survival";
				}
				//<-- JRH
				else
				{
	//				PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_f_a_006.wav")
					dialog.text = DLG_TEXT[18] + FindTownName(GetCurrentTownID()) + DLG_TEXT[19]; // KK
					link.l1 = DLG_TEXT[20];
					link.l1.go = "survival";
				}
			}
			else
			//ccc Survival <-
			{
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_1" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_2" && npchar.id == "Greenford_officiant")
				{
					dialog.snd = "Voice\ENOF\ENOF002";
					dialog.text = DLG_TEXT[45] + GetMyAddressForm(NPChar, Pchar, ADDR_CIVIL, false, false) + DLG_TEXT[46];
					link.l1 = DLG_TEXT[47] + GetMyFullName(NPChar) + DLG_TEXT[48];
					link.l1.go = "church_help";
				}
				else
				{
					if (CheckQuestAttribute("Jacks_early_days", "Try_to_join_Skull") || CheckQuestAttribute("Jacks_early_days", "Words_from_Skull") && npchar.id == "QC_officiant")
					{
						dialog.snd = "Voice\ENOF\ENOF002";
						dialog.text = DLG_TEXT[61] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[62] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[63])]) + DLG_TEXT[64];
						link.l1 = DLG_TEXT[65];
						link.l1.go = "exit";
					}
					else
					{
						switch(Rand(4))
						{
							case 0:
								dialog.snd = "Voice\ENOF\ENOF001";
								dialog.text = DLG_TEXT[0];
								link.l1 = DLG_TEXT[1];
								link.l1.go = "exit";
							break;

							case 1:
								dialog.snd = "Voice\ENOF\ENOF001";
								dialog.text = DLG_TEXT[2];
								link.l1 = DLG_TEXT[3];
								link.l1.go = "exit";
							break;

							case 2:
								if (CheckQuestAttribute("Jacks_early_days", "Ines_Diaz_Discussion") || CheckQuestAttribute("Susan_Shaypen_Quests", "Ines_Diaz_with_Susan") && npchar.id == "QC_officiant")
								{
									dialog.snd = "Voice\ENOF\ENOF001";
									dialog.text = DLG_TEXT[66];
									link.l1 = DLG_TEXT[67];
									link.l1.go = "exit";
								}
								else
								{
									dialog.snd = "Voice\ENOF\ENOF001";
									if (PChar.sex == "woman")		// GR: female player characters don't snog the barmaid so re-use the "drunken spree" section instead
									{
										dialog.text = DLG_TEXT[2];
										link.l1 = DLG_TEXT[3];
										link.l1.go = "exit";
									}
									else
									{
										dialog.text = DLG_TEXT[4];
										link.l1 = DLG_TEXT[5];
										link.l1.go = "exit";
										link.l2 = DLG_TEXT[44];
										if(sti(pchar.rank) > 4)
										{
											if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
											{
												link.l2.go = "room_day_wait_with_girl";
											}
											else
											{
												link.l2.go = "room_night_wait_with_girl";
											}
										}
										else
										{
											link.l2.go = "room_noob_with_girl";
										}
									}
								}
							break;

							case 3:
								dialog.snd = "Voice\ENOF\ENOF001";
								dialog.text = DLG_TEXT[6];
								link.l1 = DLG_TEXT[7];
								link.l1.go = "exit";
							break;

							case 4:
								if (CheckQuestAttribute("Jacks_early_days", "Ines_Diaz_Discussion") || CheckQuestAttribute("Susan_Shaypen_Quests", "Ines_Diaz_with_Susan") && npchar.id == "QC_officiant")
								{
									dialog.snd = "Voice\ENOF\ENOF001";
									dialog.text = DLG_TEXT[68];
									link.l1 = DLG_TEXT[69];
									link.l1.go = "exit";
								}
								else
								{
									dialog.snd = "Voice\ENOF\ENOF001";
									dialog.text = DLG_TEXT[8];
									link.l1 = DLG_TEXT[9];
									link.l1.go = "exit";
								}
							break;
						}
					}
					//Levis: Add option to get rid of albatros at officiant -->
					if(CheckAttribute(pchar,"quest.plants.officiant_buys_albatros"))
					{
						if(CheckCharacterItem(Pchar,"albatross"))
						{
							link.l9 = DLG_TEXT[72];
							link.l9.go = "Give Albatros";
						}
					}
					//Levis end albatros <--
				}
			}
		break;

		//Levis: Add option to get rid of albatros at officiant -->
		case "Give Albatros":
			if(!CheckAttribute(PChar,"quest.plants.steven_dead"))
			{
				dialog.text = DLG_TEXT[73] + DLG_TEXT[74];
			}
			else
			{
				dialog.text = DLG_TEXT[73];
			}
			link.l9 = DLG_TEXT[75];
			link.l9.go = "Give Albatros exit";
		break;

		case "Give Albatros exit":
			PlayStereoSound("INTERFACE\took_item.wav");
			TakeItemFromCharacter(Pchar,"albatross");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		//Levis end albatros <--

		case "room_day_wait_with_girl":
			PlayStereoSound("INTERFACE\took_item.wav");
			DialogExit();
			Pchar.sexwith.CurrentNode = "after_love";
			AddDialogExitQuest("sleep_in_tavern_with_girl"); //Levis: Extra atmosphere
			Pchar.sexwith = NPChar.id; //Levis: Extra atmosphere
			TavernWaitDate2("wait_day");
			NPChar.additionalSound = "VOICE\"+LanguageGetLanguage()+"\whore_1.wav";
		break;

		case "room_noob_with_girl":
			DialogExit();
			Pchar.sexwith.CurrentNode = "after_bad_love";
			AddDialogExitQuest("sleep_in_tavern_with_girl"); //Levis: Extra atmosphere
			Pchar.sexwith = NPChar.id; //Levis: Extra atmosphere
			NPChar.additionalSound = "VOICE\"+LanguageGetLanguage()+"\whore_1.wav";
		break;

		case "room_night_wait_with_girl":
			PlayStereoSound("INTERFACE\took_item.wav");
			DialogExit();
			Pchar.sexwith.CurrentNode = "after_love";
			AddDialogExitQuest("sleep_in_tavern_with_girl"); //Levis: Extra atmosphere
			Pchar.sexwith = NPChar.id; //Levis: Extra atmosphere
			TavernWaitDate2("wait_night");
			NPChar.additionalSound = "VOICE\"+LanguageGetLanguage()+"\whore_1.wav";
		break;

		case "after_love":
			name = NPChar.id;
			PChar.Sexwith.(name) = 2;
			DeleteAttribute(NPChar,"additionalSound");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;
		
		case "after_bad_love":
			name = NPChar.id;
			PChar.Sexwith.(name) = 1;
			DeleteAttribute(NPChar,"additionalSound");
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "church_help":
			dialog.snd = "Voice\ENOF\ENOF003";	
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50] + GetMyFullName(&Characters[GetCharacterIndex("Father Jerald")]) + DLG_TEXT[51];
			link.l1.go = "church_help_2";
		break;

		case "church_help_2":
			dialog.snd = "Voice\ENOF\ENOF004";
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "church_help_4";
		break;

		case "church_help_4":
			dialog.snd = "Voice\ENOF\ENOF005";
			dialog.text = DLG_TEXT[54] + GetMyFullName(&Characters[GetCharacterIndex("Gilbert Ballester")]) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "church_help_5";
		break;

		case "church_help_5":
			dialog.snd = "Voice\ENOF\ENOF006";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "after_off";
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				if(GetDifficulty() <= DIFFICULTY_MARINER) AddQuestRecord("Ammand", 7);
				else AddQuestRecord("Ammand", 19);
			}
			else
			{
				if(GetDifficulty() <= DIFFICULTY_MARINER) AddQuestRecord("Church_help", 7);
				else AddQuestRecord("Church_help", 16);
			}
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.greeting = curGreeting;// MAXIMUS
		break;

		case "without_money":
			NextDiag.TempNode = "first time";
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			//LAi_ActorWaitDialog(PChar, NPChar);
			dialog.snd = "Voice\ENOF\ENOF007";
			dialog.text = DLG_TEXT[12]; //PW was 10
			link.l1 = DLG_TEXT[13]; //PW was 11
			link.l1.go = "without_money_3"; // PW case 2 skipped
		break;

		/*case "without_money_2":
			//dialog.snd = "Voice\ENOF\ENOF008";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "without_money_3";
		break;
		*/
		case "without_money_3":
			dialog.snd = "Voice\ENOF\ENOF009";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "without_money_4";
		break;

		case "without_money_4":
			AddDialogExitQuest("officiant_back_to_citizen");
			dialog.snd = "Voice\ENOF\ENOF010";
			dialog.text = DLG_TEXT[16];
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit";
			//ChangeCharacterReputation(pchar, -1); //PW POTC stock game reputation loss removed
		break;

		case "sister":
			dialog.snd = "Voice\ENOF\ENOF011";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Virginie d'Espivant")].dialog.currentnode = "speak_2";
			AddDialogExitQuest("virginie_speak");
			Dialog.TempNode = "first time";
		break;

		//ccc Survival ->
		case "survival":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "survival1";
		break;

		case "survival1":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "survival2";
		break;


		case "survival2":
			dialog.text = DLG_TEXT[25];
// KK -->
			if (GetCharacterShipType(PChar) != SHIP_NOTUSED) {
				link.l1 = DLG_TEXT[26];
				link.l1.go = "survival3";
			} else {
				link.l1 = DLG_TEXT[31];
				link.l1.go = "survival4";
			}
// <-- KK
		break;

		case "survival3":
// KK -->//changed by MAXIMUS string GetCharacterShipLocation(ref rChar) declared in locations.c
			ShipLocationName = TranslateString("", GetCharacterShipLocationName(PChar));
			Preprocessor_Add("island_name", XI_ConvertString(GetIslandNameByLocationID(PChar.location)));
			if (CheckAttribute(&Locations[FindLoadedLocation()], "townsack")) Preprocessor_Add("town_name", FindTownName(GetCurrentTownID()));
			ShipLocationName = PreprocessText(ShipLocationName);
			Preprocessor_Remove("island_name");
			Preprocessor_Remove("town_name");
			if (HasSubStr(ShipLocationName, "port"))
				dialog.text = DLG_TEXT[27] + ShipLocationName + DLG_TEXT[29];
			else
				dialog.text = DLG_TEXT[27] + DLG_TEXT[28] + ShipLocationName + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30] + DLG_TEXT[31];
			link.l1.go = "survival4";
// <-- KK
		break;

		case "survival4":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exitS";
		break;

// KK -->
		case "Blaze_must_escape":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Blaze_must_escape_1";
		break;

		case "Blaze_must_escape_1":
			dialog.text = DLG_TEXT[36] + XI_ConvertString("cap"+GetNationDescByType(GetCurrentLocationNation())) + DLG_TEXT[37] + FindTownName(GetCurrentTownID()) + DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Blaze_must_escape_2";
		break;

		case "Blaze_must_escape_2":
			dialog.text = DLG_TEXT[40];
			if (GetCharacterShipType(PChar) != SHIP_NOTUSED) {
				ShipLocationName = GetCharacterShipLocationName(PChar);
				if (HasSubStr(ShipLocationName, "port"))
					dialog.text += DLG_TEXT[41] + TranslateString("",ShipLocationName) + DLG_TEXT[42];
				else
					dialog.text += DLG_TEXT[41] + DLG_TEXT[42] + TranslateString("",ShipLocationName) + DLG_TEXT[42];
			}
			link.l1 = DLG_TEXT[43];
			link.l1.go = "ExitS";
		break;

		case "ExitS":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			NPChar.greeting = curGreeting;// MAXIMUS

			AddDialogExitQuest("ResurrectionEvent_OfficiantLeaves"); // KK
		break;
// <-- KK

		//ccc Survival <-
	}
}
