void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	if (NPChar.quest.teodoro == "2")
	{
		Dialog.CurrentNode = "TeodoroQuestDone";
	}
	if (NPChar.quest.teodoro == "3")
	{
		Dialog.CurrentNode = "TeodoroLie";
	}
// NK -->
	if (NPChar.quest.teodoro == "Teodoro_completed")
	{
		Dialog.CurrentNode = "Teodoro_completed";
	}
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;
// NK <--

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
			Locations[FindLocation("house_of_laurence")].vcskip = true; // NK
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_1";
			NextDiag.tempNode = "First time";
			NPChar.itemtrade.tradetype = IT_TYPE_STALL; // NK itemtrade 05-04-08
		break;

		case "node_1":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "node_2";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "exit";
			if(!CheckAttribute(NPChar, "quest.teodoro_started")) SetQuestHeader("Patric"); // NK
		break;

		case "node_2":
			Preprocessor_Add("sir", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false)); // DeathDaisy
			Dialog.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "exit";
		break;

		case "node_3":
			Dialog.Text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "node_4";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
			NextDiag.TempNode = "Second Time";
		break;

		case "node_4":
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13] + GetMyFullName(PChar) + DLG_TEXT[14];
			Link.l1.go = "node_5";
		break;

		case "node_5":
			Dialog.Text = DLG_TEXT[15] + GetMyFullName(NPChar) + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17] + GetMyName(NPChar) + DLG_TEXT[18];
			Link.l1.go = "node_6";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "exit";
		break;

		case "node_6":
			Dialog.Text = DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) +DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "node_7";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "exit";
		break;

		case "node_7":
			Dialog.text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "node_8";
			Link.l2 = DLG_TEXT[26];
			Link.l2.go = "exit";
		break;

		case "node_8":
			Dialog.Text = DLG_TEXT[27] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[28])]) + DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "node_11";
		break;

		case "node_11":
			Dialog.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "node_12";
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "node_13";
		break;

		case "node_12":
			Dialog.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "node_13";
		break;

		case "node_13":
			Dialog.text = DLG_TEXT[37] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[38])]) + DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_14";
		break;

		case "node_14":
			Dialog.text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[43])]) + DLG_TEXT[44];
			Link.l1.go = "node_15";
			Link.l2 = DLG_TEXT[45] + GetMyName(NPChar) + DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "node_15":
			Dialog.text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "node_16";
		break;

		case "node_16":
			Dialog.text = DLG_TEXT[49] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[50])]) + DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "node_17";
			Link.l2 = DLG_TEXT[53];
			Link.l2.go ="node_18";
		break;

		case "node_17":
			Dialog.text = DLG_TEXT[54] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "node_17_1";
			Link.l2 = DLG_TEXT[57];
			Link.l2.go = "exit;"
		break;

		case "node_17_1":
			Dialog.text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "node_19";
		break;

		case "node_18":
			Dialog.text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "node_19";
		break;

		case "node_19":
			Dialog.text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "node_20";
			Link.l2 = DLG_TEXT[64];
			Link.l2.go = "node_21";
		break;

		case "node_20":
			if (CalcCharacterSkill(PChar,SKILL_COMMERCE) > 2) // NK
			{
				Dialog.text = PersuasionSuccess + DLG_TEXT[65];
				Link.l1 = DLG_TEXT[66] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[67])]) + DLG_TEXT[68];
				Link.l1.go = "node_21_1";
				NPChar.money.quest = "5000";
			}
			else
			{
				Dialog.text = PersuasionFailure + DLG_TEXT[69];
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "node_20_1";
			}
		break;

		case "node_20_1":
			Dialog.text = DLG_TEXT[71];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "node_21";
		break;

		case "node_21":
			Dialog.Text = DLG_TEXT[74] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "node_21_1";
			NPChar.quest.teodoro = "1";
			NPChar.money.quest = "3000";
		break;

		case "node_21_1":
			Dialog.text = DLG_TEXT[77];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "exit";
			NPChar.quest.teodoro = "1"; //NK enable this
			AddQuestRecord("Patric", 3); // NK
		break;

		////////////////////////////////////////////////////////////////////
		// второй разговор.
		////////////////////////////////////////////////////////////////////

		case "Second Time":
			Dialog.Text = DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "node_22";
			if (NPChar.quest.teodoro == "1" || NPChar.quest.teodoro == "6" || NPChar.quest.teodoro == "7") // KK
			{
				Dialog.text = DLG_TEXT[82] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[83];
				Link.l1 = DLG_TEXT[84];
				Link.l1.go = "exit";
			}
			if(npchar.quest.teodoro == "5")
			{
				Link.l1 = DLG_TEXT[99];
				Link.l1.go = "Lucien";
			}
			if (npchar.quest.teodoro == "4" || npchar.quest.teodoro == "5" || npchar.quest.teodoro == "Teodoro_completed") // NK
			{
				if (characters[GetCharacterIndex("Raoul Calmes")].quest.visit == "0")
				{
					Locations[FindLocation("house_of_smuggler_in_FiF")].vcskip = true; // NK
					dialog.text = DLG_TEXT[85] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[86])]) + DLG_TEXT[87];
					link.l1 = DLG_TEXT[88];
					link.l1.go = "exit";
					characters[GetCharacterIndex("Raoul Calmes")].quest.visit = "1";
					if (npchar.quest.teodoro != "5") NPChar.quest.teodoro = "6"; // KK
					AddQuestRecord("Patric", 6); // NK
				}
			}
		break;

		case "node_22":
			Dialog.Text = DLG_TEXT[89];
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "Items";
			Link.l2 = DLG_TEXT[91];
			Link.l2.go = "exit";
		break;

		//Руморсы
		case "Rumours":
			Dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[93];
			Link.l2.go = "node_23";
		break;


		case "Lucien":
			Dialog.text = DLG_TEXT[102] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[103])]) + DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "Lucien2";
		break;

		case "Lucien2":
			Dialog.text = DLG_TEXT[118];
			Link.l1 = DLG_TEXT[119];
			link.l1.go = "exit";
			NPChar.quest.teodoro = "7"; // KK
			AddQuestRecord("Patric", 9); // NK
		break;

		// выполнение квеста.
		case "Teodoro_completed":
			DeleteAttribute(&Locations[FindLocation("house_of_laurence")],"vcskip"); // NK
			Dialog.Text = DLG_TEXT[94] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[95]; 
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
			NPChar.money.quest = "0";
			NPChar.quest.Teodoro = "done";
			NextDiag.TempNode = "Second Time";
			AddQuestRecord("Patric", 11); // NK
			CloseQuestHeader("Patric"); // NK
		break;		

		case "TeodoroLie":
			Dialog.text = DLG_TEXT[97];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "lie_1";
			Link.l2 = DLG_TEXT[99];
			Link.l2.go = "lie_2";
			NPChar.quest.Teodoro = "done";
		break;

		case "lie_1":
			Dialog.text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "exit";
			NextDiag.TempNode = "Second Time";
		break;

		case "lie_2":
			Dialog.text = DLG_TEXT[102] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[103])]) + DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "lie_2_1";
		break;

		case "lie_2_1":
			Dialog.text = DLG_TEXT[106];
			Link.l1 = DLG_TEXT[107];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			NPChar.money.quest = "0";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
			NextDiag.TempNode = "Second Time";
		break;

		case "tavern":
			Dialog.text = DLG_TEXT[108] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[109];
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[111];
			Link.l2.go = "exit";
		break;

		case "store":
			Dialog.text = DLG_TEXT[112];
			Link.l1 = DLG_TEXT[113];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			Dialog.text = DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if(NextDiag.TempNode == "First Time" && !CheckAttribute(NPChar, "quest.teodoro_started"))
			{
				AddQuestRecord("Patric", 1); // NK
				NPChar.quest.teodoro_started = true;
			}
			if(NextDiag.TempNode == "Second Time" && NPChar.quest.teodoro == "0")
			{
				AddQuestRecord("Patric", 2); // NK
				CloseQuestHeader("Patric");
			}
		break;
		
		
		case "Items":
			if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
			// PB: Prevent error
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
	}
}

