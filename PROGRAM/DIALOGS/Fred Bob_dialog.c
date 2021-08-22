void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	Preprocessor_Add("Civil", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // DeathDaisy
	
	// RM -->
	if(strcut(Dialog.CurrentNode, 0, 3) == "flag") // KK
	{
// KK -->
		string ssel = GetSymbol(Dialog.CurrentNode, 4) + GetSymbol(Dialog.CurrentNode, 5);
		int cc;
		int sel_nation = sti(ssel);
		string tstr = XI_ConvertString(GetNationDescByType(sel_nation));
		HoistFlag(sel_nation);
		if (sel_nation == PERSONAL_NATION) tstr = "your";
		d.Text = DLG_TEXT[0] + tstr + DLG_TEXT[1];
// <-- KK
		Link.l1 = DLG_TEXT[2];
		Link.l1.go = "exit";
	}
	// RM <--
	
	if(npchar.quest.help == "done")
	{
		Diag.CurrentNode = "Help_Succesful";
		npchar.quest.help = "0";
	}
	if(npchar.quest.help == "failed")
	{
		Diag.CurrentNode = "Help_failed";
		npchar.quest.help = "0";
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
			Dialog.snd = "voice\RYBL\RYBL001";

			Diag.TempNode = "First time";
			d.Text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			Link.l1.go = "node_2";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "Exit";

		break;

		case "Node_2":
			Diag.TempNode = "Second Time";
			d.Text = "'" + GetMyShipNameShow(PChar) + "'. " + DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "Exit";
		break;

		case "Node_3":
			d.Text = DLG_TEXT[11] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "node_4";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "Exit";
		break;

		case "Node_4":
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Node_5";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "exit";
		break;

		case "Node_4a":
			d.Text = DLG_TEXT[18] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "Node_5a";
			Link.l2 = DLG_TEXT[21];
			Link.l2.go = "exit";
		break;
				
		case "Node_5":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Node_6";
			Link.l2 = DLG_TEXT[24];
			Link.l2.go = "exit";
		break;
		
		case "Node_5a":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Node_6a";
		break;
		
		case "Node_6":
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "Node_7";
		break;
		
		case "Node_6a":
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "Node_7a";
		break;
		
		case "Node_7":
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Node_8";
		break;
		
		case "Node_7a":
		    d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Node_14";
		break;

		case "Node_8":
			d.Text = DLG_TEXT[30] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Node_9";
			Link.l2 = DLG_TEXT[32];
			Link.l2.go = "node_10";
			Link.l3 = DLG_TEXT[33];
			Link.l3.go = "exit";
		break;

		case "Node_9":
			d.Text = DLG_TEXT[34] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Node_11";
			Link.l2 = DLG_TEXT[37];
			Link.l2.go = "node_12";
		break;

		case "Node_10":
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[38] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_13";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "exit";
		break;

		case "Node_11":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "node_13";
		break;

		case "Node_12":
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit";
			AddQuestRecord("fred_bob", 9);
		break;

		case "Node_13":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Node_13_1";
		break;

		case "Node_13_1":
			d.Text = DLG_TEXT[48];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "Node_13_2";
		break;
		
		case "Node_13_2":
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Exit";
			AddQuestRecord("fred_bob", 2);
		break;

		case "Second time":
			Dialog.snd1 = "voice\RYBL\RYBL012";
			Dialog.snd2 = "voice\RYBL\RYBL013";
			Dialog.snd3 = "voice\RYBL\RYBL014";
			d.Text = RandPhrase(DLG_TEXT[52] + GetMyName(Pchar) + DLG_TEXT[53], DLG_TEXT[54] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[55], DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[57], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "Node_4a";
			Link.l2 = DLG_TEXT[59];
			Link.l2.go = "exit";
		break;

		case "Node_14":
			d.Text = DLG_TEXT[60] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "Node_15";
			Link.l2 = DLG_TEXT[63];
			Link.l2.go = "node_16";
			Link.l3 = DLG_TEXT[64];
			Link.l3.go = "exit";
		break;

		case "Node_15":
			d.Text = DLG_TEXT[65] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "Node_17";
			Link.l2 = DLG_TEXT[68];
			Link.l2.go = "node_18";
		break;

		case "Node_16":
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[69] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "node_19";
			Link.l2 = DLG_TEXT[72];
			Link.l2.go = "exit";
		break;

		case "Node_17":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			d.Text = DLG_TEXT[73];
			Link.l1 = DLG_TEXT[74];
			Link.l1.go = "Node_13_1";
		break;

		case "Node_18":
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "Exit";
		break;

		case "Node_19":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			d.Text = DLG_TEXT[77];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "Node_13_1";
		break;

		case "Agreed_Help":
			Dialog.snd1 = "voice\RYBL\RYBL021";
			Dialog.snd2 = "voice\RYBL\RYBL022";
			Dialog.snd3 = "voice\RYBL\RYBL023";
			Diag.TempNode = "Agreed_help";
			d.Text = RandPhrase(DLG_TEXT[79] + GetMyName(Pchar) + DLG_TEXT[80], DLG_TEXT[81] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + GetMyName(PChar) + DLG_TEXT[82], DLG_TEXT[83] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[84], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3) + DLG_TEXT[85];
			Link.l1 = DLG_TEXT[86];
			Link.l1.go = "Node_20";
			Link.l2 = DLG_TEXT[87];
			Link.l2.go = "Node_13_1";
			Link.l3 = DLG_TEXT[88];
			Link.l3.go = "exit";
		break;

		case "Node_20":
			d.Text = DLG_TEXT[89] + GetMyName(Pchar) + DLG_TEXT[90];
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Node_21";
			Link.l2 = DLG_TEXT[92];
			Link.l2.go = "node_22";
		break;

		case "Node_21":
			d.Text = DLG_TEXT[93] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[94];
			Link.l1 = DLG_TEXT[95];
			Link.l1.go = "exit";
		break;

		case "Node_22":
			d.Text = DLG_TEXT[96] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "!";
			Link.l1 = DLG_TEXT[97];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[98];
			Link.l2.go = "exit";
		break;
		
		case "Node_23":
			d.Text = DLG_TEXT[99];
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[100];
				Link.l1.go = "node_24";
			}	
			else
			{
				Link.l1 = DLG_TEXT[101];
				Link.l1.go = "node_24";
			}
			Link.l2 = DLG_TEXT[102];
			Link.l2.go = "node_26";
			Link.l3 = DLG_TEXT[103];
			Link.l3.go = "node_27";
		break;
		
		case "Node_24":
			d.Text = DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "node_25";
		break;
		
		case "Node_25":
			d.Text = DLG_TEXT[106];
			Link.l1 = DLG_TEXT[107];
			Link.l1.go = "node_28";
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[108];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[109];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_26":
			d.Text = DLG_TEXT[110];
			Link.l1 = DLG_TEXT[111];
			Link.l1.go = "node_26_1";
		break;
		
		case "node_26_1":
			d.Text = DLG_TEXT[112];
			Link.l1 = DLG_TEXT[113];
			Link.l1.go = "node_29";
		break;
		
		case "Node_27":
			d.Text = DLG_TEXT[114];
			Link.l1 = DLG_TEXT[115];
			Link.l1.go = "node_30";
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[116];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[117];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_28":
			d.Text = DLG_TEXT[118];
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[119];
				Link.l1.go = "node_31";
			}	
			else
			{
				Link.l1 = DLG_TEXT[120];
				Link.l1.go = "node_31";
			}
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[121];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[122];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_29":
			d.Text = DLG_TEXT[123];
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[124];
				Link.l1.go = "node_31";
			}	
			else
			{
				Link.l1 = DLG_TEXT[125];
				Link.l1.go = "node_31";
			}
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[126];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[127];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_30":
			d.Text = DLG_TEXT[128] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[129]; 
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[130];
				Link.l1.go = "Node_23";
			}	
			else
			{
				Link.l1 = DLG_TEXT[131];
				Link.l1.go = "Node_23";
			}
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[132];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[133];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_31":
			d.Text = DLG_TEXT[134];
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[135];
				Link.l1.go = "node_32";
			}	
			else
			{
				Link.l1 = DLG_TEXT[136];
				Link.l1.go = "node_32";
			}
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[137];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[138];
				Link.l2.go = "exit";
			}
		break;
		
		case "Node_32":
			d.Text = DLG_TEXT[139] + GetMyName(Pchar) + DLG_TEXT[140];
			if(NPChar.quest.help == "hired")
			{
				Link.l1 = DLG_TEXT[141];
				Link.l1.go = "Node_23";
			}	
			else
			{
				Link.l1 = DLG_TEXT[142];
				Link.l1.go = "Node_23";
			}
			if(NPChar.quest.help == "hired")
			{
				Link.l2 = DLG_TEXT[143];
				Link.l2.go = "exit";
			}	
			else
			{
				Link.l2 = DLG_TEXT[144];
				Link.l2.go = "exit";
			}
		break;
		
		case "Help_Failed":
			Dialog.snd1 = "voice\RYBL\RYBL037";
			Dialog.snd2 = "voice\RYBL\RYBL038";
			Dialog.snd3 = "voice\RYBL\RYBL039";
			Diag.TempNode = "Common";
			d.Text = RandPhrase(DLG_TEXT[145] + PChar.name + "! " + DLG_TEXT[146] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".", DLG_TEXT[146] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + GetMyName(PChar) + DLG_TEXT[147], DLG_TEXT[148] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[149], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3) + DLG_TEXT[150];
			Link.l1 = DLG_TEXT[151];
			Link.l1.go = "Node_33";
			Link.l2 = DLG_TEXT[152];
			Link.l2.go = "exit";
			AddQuestRecord("fred_bob", 8);
		break;

		case "Node_33":
			d.Text = DLG_TEXT[153] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			Link.l1 = DLG_TEXT[154];
			Link.l1.go = "Node_18";
			AddQuestRecord("fred_bob", 8);
			Link.l2 = DLG_TEXT[155];
			Link.l2.go = "node_22";
			AddQuestRecord("fred_bob", 8);
		break;

		case "Help_succesful":
			Diag.TempNode = "Help_succesful";
			d.Text = DLG_TEXT[156];
			Link.l1 = DLG_TEXT[157];
			Link.l1.go = "Help_succesful_1";
			Link.l2 = DLG_TEXT[158];
			Link.l2.go = "exit";
		break;

		case "Help_succesful_1":
			Diag.TempNode = "common";
			d.Text = DLG_TEXT[159] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			Link.l1 = DLG_TEXT[160];
			Link.l1.go = "Help_succesful_2";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 750);
				AddPartyExpChar(pchar, "Sneak", 8);
			}
			else { AddPartyExp(pchar, 750); }
			GiveItem2Character(NPChar, "blade27");
			NPChar.equip.blade = "blade27";
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
			{
				GiveItem2Character(NPChar, "pistol1");
				NPChar.equip.gun = "pistol1";
			}
			else
			{
				GiveItem2Character(NPChar, "pistol1a");
				NPChar.equip.gun = "pistol1a";
			}

		     //JRH ammo mod --->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(NPchar, "gunpowder", 6);
				TakenItems(NPchar, "pistolbullets", 6);
			}
		     //JRH ammo mod <---

		break;

		case "Help_succesful_2":
			d.Text = DLG_TEXT[161];
			Link.l1 = DLG_TEXT[162];
			Link.l1.go = "Help_succesful_3";
		break;

		case "Help_succesful_3":
			d.Text = DLG_TEXT[163] + GetMyName(Pchar) + DLG_TEXT[164];
			Link.l1 = DLG_TEXT[165];
			Link.l1.go = "hire";
		break;
		
		case "hire":
			d.Text = DLG_TEXT[166] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "hire_2";
		break;
		
		case "hire_2":
			d.Text = DLG_TEXT[169] + GetMyName(Pchar) + DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "thanks";
		break;

		case "thanks":
			GiveItem2Character(Pchar,"Letter_Reward");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500);
			AddMoneyToCharacter(NPChar, 500);
			d.Text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "exit_hire";
		break;
		
		case "exit_hire":
			Diag.TempNode = "hired";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.quest.help = "hired";
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Fred Bob"));
			AddPassenger(Pchar, characterFromID("Fred Bob"), 0);
			AddQuestRecord("fred_bob", 7);
			CloseQuestHeader("fred_bob");
			ChangeCharacterAddressGroup(characterFromID("Estrella De Alencar"), "Muelle_church", "goto", "goto10");
		break;

		case "common":
			Diag.Tempnode = "common";
			d.Text = TimeGreeting() + DLG_TEXT[174];
			Link.l1 = DLG_TEXT[175];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[176];
			Link.l2.go = "Exit";
		break;
		
		// NK -->
		case "rations":
			if(!CheckAttribute(pchar,"Crewstatus.foodrations")) pchar.Crewstatus.foodrations = 1;
			if(!CheckAttribute(pchar,"Crewstatus.rumrations")) pchar.Crewstatus.rumrations = 2;
			if(sti(pchar.Crewstatus.foodrations) == 1) pchar.tempfr = "rfull";
			else pchar.tempfr = "rhalf";
			if(sti(pchar.Crewstatus.rumrations) == 1) pchar.temprr = "rdouble";
			else pchar.temprr = "rnormal";
// added by MAXIMUS [CheckAttribute only] -->
			int ourFood = 0;
			int ourRum = 0;
			if(CheckAttribute(pchar.Crewstatus,"foodused")) ourFood = stf(pchar.Crewstatus.foodused);
			if(CheckAttribute(pchar.Crewstatus,"rumused")) ourRum = stf(pchar.Crewstatus.rumused);
// added by MAXIMUS [CheckAttribute only] <--
			d.Text = DLG_TEXT[177] + XI_ConvertString(pchar.tempfr) + DLG_TEXT[178] + XI_ConvertString(pchar.temprr) + DLG_TEXT[179] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_WHEAT)) - ourFood) / (makefloat(GetSquadronTotalCrewQuantity(pchar)) * FOOD_PER_CREW / stf(pchar.Crewstatus.foodrations))) + DLG_TEXT[180] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_RUM)) - ourRum) / (makefloat(GetSquadronTotalCrewQuantity(pchar)) * FOOD_PER_CREW / stf(pchar.Crewstatus.rumrations))) + DLG_TEXT[181]; // KK
			//Link.l1 = "No.";
			//Link.l1.go = "Exit";
			//if(pchar.tempfr != "full" && pchar.temprr != "normal")
			{
				Link.l2 = DLG_TEXT[182];
				Link.l2.go = "R12";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "normal")
			{
				Link.l3 = DLG_TEXT[183];
				Link.l3.go = "R22";
			}
			//if(pchar.tempfr != "full" && pchar.temprr != "double")
			{
				Link.l4 = DLG_TEXT[184];
				Link.l4.go = "R11";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "double")
			{
				Link.l5 = DLG_TEXT[185];
				Link.l5.go = "R21";
			}
			DeleteAttribute(pchar,"tempfr");
			DeleteAttribute(pchar,"temprr");
		break;

		case "R12":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 2;

			d.Text = DLG_TEXT[186];
			Link.l1 = DLG_TEXT[187];
			Link.l1.go = "Exit";
		break;

		case "R22":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 2;

			d.Text = DLG_TEXT[188];
			Link.l1 = DLG_TEXT[187];
			Link.l1.go = "Exit";
		break;

		case "R11":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 1;

			d.Text = DLG_TEXT[189];
			Link.l1 = DLG_TEXT[187];
			Link.l1.go = "Exit";
		break;

		case "R21":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 1;

			d.Text = DLG_TEXT[190];

			Link.l1 = DLG_TEXT[187];
			Link.l1.go = "Exit";
		break;

		case "SalaryC":
			// DeathDaisy -->
			if(PChar.sex == "woman"){
				Preprocessor_Add("sir", XI_ConvertString("ma'am"));
			}
			else{
				Preprocessor_Add("sir", XI_ConvertString("sir"));
			}
			// DeathDaisy <--
			d.Text = DLG_TEXT[191];
			Link.l1 = DLG_TEXT[192];
			Link.l1.go = "Exit";
			if(sti(PChar.CrewStatus.explength) == 0)
			{
				d.Text = DLG_TEXT[193];
				Link.l2 = DLG_TEXT[194];
				Link.l2.go = "Salary";
			}
		break;

		case "ArticlesC":
			// DeathDaisy -->
			if(PChar.sex == "woman"){
				Preprocessor_Add("sir", XI_ConvertString("ma'am"));
			}
			else{
				Preprocessor_Add("sir", XI_ConvertString("sir"));
			}
			// DeathDaisy <--
			d.Text = DLG_TEXT[195];
			Link.l1 = DLG_TEXT[192];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[196];
			Link.l2.go = "Articles";
		break;

		case "Salary":
			d.Text = DLG_TEXT[197];
			Link.l1 = DLG_TEXT[198];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityTotalRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			PChar.articles = false;
		break;

		case "Articles":
			d.Text = DLG_TEXT[199];
			Link.l1 = DLG_TEXT[198];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityTotalRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			PChar.CrewStatus.explength = 0;
			PChar.articles = true;
		break;

		/*case "DonatetoParty":
			d.Text = "Aye aye. Put de gold ye be wantin' to donate down in yer sea chest in de cabin, den be a walkin' away. Den be goin' back an' pick it all up agin an' dat'll be puttin' it in de general fund. In de meantime, don't be exchangin' items wid nobody or nuttin' else first!";
			Link.l1 = "Very good, Mister Fred Bob. As you were.";
			Link.l1.go = "Exit";
			PChar.donatepartymoney = true;
		break;*/
// NK <--


		// RM -->
		case "flgchoice":
			d.Text = DLG_TEXT[200];
//			Link.l1 = "Our current colors.";
// KK -->
			if (GetCurrentFlag() != PERSONAL_NATION) {
				Link.l1 = DLG_TEXT[201] + GetNationDescByType(GetCurrentFlag()) + DLG_TEXT[202];
				Link.l1.go = "flag0" + PChar.nation;
			} else {
				Link.l1 = DLG_TEXT[203];
				Link.l1.go = "flag" + PERSONAL_NATION;
			}
// <-- KK
// KK -->
			if (GetCurrentFlag() != PIRATE) {
				Link.l2 = DLG_TEXT[204];
				Link.l2.go = "flag0" + PIRATE;
			}
// <-- KK
			string tempstr;
			for(int q = 0; q < NATIONS_QUANTITY; q++)
			{
				if(q==PIRATE) continue;
// KK -->
				if (GetCurrentFlag() == q) continue;
				if(GetRMRelation(PChar, q) >= REL_AMNESTY)
				{
					tempstr = "l" + (q+3);
					Link.(tempstr) = XI_ConvertString("4"+GetNationDescByType(q)) + DLG_TEXT[202];
					Link.(tempstr).go = "flag0"+q;
				}
			}
			if (GetCurrentFlag() != PERSONAL_NATION) {
				tempstr = "l" + (PERSONAL_NATION+3);
				Link.(tempstr) = DLG_TEXT[205];
				Link.(tempstr).go = "flag"+PERSONAL_NATION;
			}
// <-- KK
		break;
		// RM <--
			
		case "hired":
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[206];
// NK -->
			//if(Npchar.quest.officertype == OFFIC_TYPE_QMASTER)
			//{
				Link.l64 = DLG_TEXT[207];
				Link.l64.go = "rations";
			//}
			if(CheckAttribute(PChar, "articles") && sti(PChar.articles))
			{
				Link.l63 = DLG_TEXT[208];
				Link.l63.go = "SalaryC";
			}
			else
			{
				Link.l63 = DLG_TEXT[209];
				Link.l63.go = "ArticlesC";
			}
			/*if(GetCharacterWealth(PChar) > 0)
			{
				Link.l62 = "I'm going to donate some money to the expedition.";
				Link.l62.go = "DonatetoParty";
			}*/
// NK <--
			Link.l1 = DLG_TEXT[210];
			Link.l1.go = "Exit";								
			// NK -->
			Link.l15 = DLG_TEXT[211];
			Link.l15.go = "Difficulty";
			// NK <--
			Link.l2 = DLG_TEXT[212];
			Link.l2.go = "AsYouWish";		
			// boal 05.09.03 offecer need to go to abordage -->
			Link.l3 = DLG_TEXT[213];
			Link.l3.go = "Boal_Abordage";								
			Link.l4 = DLG_TEXT[214];
			Link.l4.go = "Boal_safeAbordage";
			Link.l5 = DLG_TEXT[215];
			Link.l5.go = "Boal_Stay";
			Link.l6 = DLG_TEXT[216];
			Link.l6.go = "Boal_Follow";
			// boal 05.09.03 offecer need to go to abordage <--
			// RM -->
			Link.l10 = DLG_TEXT[217];
			Link.l10.go = "flgchoice";
			// RM <--
			// NK -->
			if(PChar.location != "Tutorial_Deck")
			{
				Link.l11 = DLG_TEXT[218];
				Link.l11.go = "layupships";
			}
			Link.l65 = DLG_TEXT[219];
			Link.l65.go = "clothes";
			Link.l66 = DLG_TEXT[220];
			Link.l66.go = "Node_23";
		break;

		case "layupships":
			// NK - hate to do it, but I'm commenting this out for using KAM's func.
			DialogExit();
			LaunchKAMShipBerthing();
			/*bool lu = CheckAttribute(PChar,"oldship");
			if(!lu)
			{
				d.Text = "Hmmm... we ain't got no ship layed up, Captain.";
				Link.l2 = "Never mind.";
				Link.l2.go = "exit";
				Link.l1 = "We'll lay up my ship.";
				Link.l1.go = "LUShipC";
			}
			else
			{
				d.Text = "Hmm... we be havin' a " + XI_ConvertString(ShipsTypes[GetShipIndex(PChar.oldship.type)].SName) + " layed up at de moment, Captain. Watcha wanna do?";
				if(GetCharacterShipID(PChar) != SHIP_NOTUSED_TYPE_NAME)
				{
					Link.l2 = "Never mind.";
					Link.l2.go = "exit";
					Link.l1 = "We'll swap ships.";
					Link.l1.go = "LUSwapC";
				}
				else
				{
					Link.l2 = "Never mind.";
					Link.l2.go = "exit";
					Link.l1 = "We'll relaunch her.";
					Link.l1.go = "LULaunchC";
				}
			}*/
		break;
/*			
		case "LUSwap":
			d.Text = "Ye be sure, Captain? If'n de goods cain't fit in yer new flagship, they'll have to be sold befer leavin' port. Any extra crew will be scatterin' also."
			Link.l2 = "Never mind.";
			Link.l2.go = "exit";
			Link.l1 = "Yes."
			Link.l1.go = "LUSwapC";
		break;

		case "LUShip":
			d.Text = "Ye be sure, Captain? You'll be losin' every thang but de cannons from her, since we'll be havin' tew strip her down. The crew will be scatterin' also."
			Link.l2 = "Never mind.";
			Link.l2.go = "exit";
			Link.l1 = "Yes."
			Link.l1.go = "LUShipC";
		break;

		case "LULaunch":
			d.Text = "Ye be sure, Captain? You'll be needin' tew replenish her stores an' hire ye a new crew."
			Link.l2 = "Never mind.";
			Link.l2.go = "exit";
			Link.l1 = "Yes."
			Link.l1.go = "LULaunchC";
		break;
*/
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

			d.Text = DLG_TEXT[221];
			Link.l1 = DLG_TEXT[198];
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
			d.Text = DLG_TEXT[221];
			Link.l1 = DLG_TEXT[198];
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
				PChar.location.from_sea = PChar.location.old_from_sea;
				DeleteAttribute(PChar,"location.old_from_sea");
			}
			d.Text = DLG_TEXT[221];
			Link.l1 = DLG_TEXT[198];
			Link.l1.go = "exit";
		break;

		case "clothes":
			d.text = DLG_TEXT[261];
			Link.l0 = DLG_TEXT[262];
			Link.l0.go = "nochange";
			Link.l01 = DLG_TEXT[263];
			Link.l01.go = "fredbob";
			Link.l1 = DLG_TEXT[264];
			Link.l1.go = "injun";
			Link.l2 = DLG_TEXT[265];
			Link.l2.go = "blaze";
			Link.l3 = DLG_TEXT[266];
			Link.l3.go = "depp";
			Link.l4 = DLG_TEXT[267];
			Link.l4.go = "capitan1";
			Link.l5 = DLG_TEXT[268];
			Link.l5.go = "corsair1";
			Link.l6 = DLG_TEXT[269];
			Link.l6.go = "corsair1_1";
			Link.l7 = DLG_TEXT[270];
			Link.l7.go = "corsair1_2";
			Link.l8 = DLG_TEXT[271];
			Link.l8.go = "killer";
			Link.l9 = DLG_TEXT[272];
			Link.l9.go = "capitan"
			Link.l10 = DLG_TEXT[273];
			Link.l10.go = "pirat10";
			Link.l11 = DLG_TEXT[274];
			Link.l11.go = "storeman2";
			Link.l12 = DLG_TEXT[275];
			Link.l12.go = "pirat4";
			Link.l13 = DLG_TEXT[276];
			Link.l13.go = "sailor4";
			Link.l14 = DLG_TEXT[277];
			Link.l14.go = "black_corsair";
			Link.l15 = DLG_TEXT[278];
			Link.l15.go = "brodyaga";
			Link.l16 = DLG_TEXT[279];
			Link.l16.go = "researcher";
			Link.l17 = DLG_TEXT[280];
			Link.l17.go = "will";
			Link.l18 = DLG_TEXT[281];
			Link.l18.go = "Navy_off";
			Link.l19 = DLG_TEXT[282];
			Link.l19.go = "Navy_Office4";
			Link.l20 = DLG_TEXT[283];
			Link.l20.go = "corsair3";
			Link.l21 = DLG_TEXT[284];
			Link.l21.go = "corsair1_3";
			Link.l22 = DLG_TEXT[285];
			Link.l22.go = "blackman";
			Link.l23 = DLG_TEXT[286];
			Link.l23.go = "bocman3";
			Link.l24 = DLG_TEXT[287];
			Link.l24.go = "fawn";
			Link.l25 = DLG_TEXT[288];
			Link.l25.go = "shkiper";
		break;

		case "nochange":
			d.Text = DLG_TEXT[221];
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "fredbob":
			d.Text = DLG_TEXT[289];
			Pchar.model = "fredbob";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[290];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "injun":
			d.Text = DLG_TEXT[291] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + "!";
			Pchar.model = "mummy";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[292];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "blaze":
			d.Text = DLG_TEXT[293];
			Pchar.model = "blaze";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "depp":
			d.Text = DLG_TEXT[293];
			Pchar.model = "depp";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "capitan1":
			d.Text = DLG_TEXT[293];
			Pchar.model = "capitan1";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "corsair1":
			d.Text = DLG_TEXT[293];
			Pchar.model = "corsair1";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "corsair1_1":
			d.Text = DLG_TEXT[293];
			Pchar.model = "corsair1_1";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "corsair1_2":
			d.Text = DLG_TEXT[293];
			Pchar.model = "corsair1_2";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "killer":
			d.Text = DLG_TEXT[293];
			Pchar.model = "killer";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "capitan":
			d.Text = DLG_TEXT[293];
			Pchar.model = "capitan";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "pirat10":
			d.Text = DLG_TEXT[293];
			Pchar.model = "pirat10";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "storeman2":
			d.Text = DLG_TEXT[293];
			Pchar.model = "storeman2";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "pirat4":
			d.Text = DLG_TEXT[293];
			Pchar.model = "pirat4";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "sailor4":
			d.Text = DLG_TEXT[293];
			Pchar.model = "sailor4";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "black_corsair":
			d.Text = DLG_TEXT[293];
			Pchar.model = "black_corsair";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "brodyaga":
			d.Text = DLG_TEXT[293];
			Pchar.model = "brodyaga";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "researcher":
			d.Text = DLG_TEXT[293];
			Pchar.model = "researcher";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "will":
			d.Text = DLG_TEXT[293];
			Pchar.model = "will";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "Navy_off":
			d.Text = DLG_TEXT[293];
			Pchar.model = "Navy_off";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "Navy_Office4":
			d.Text = DLG_TEXT[293];
			Pchar.model = "Navy_Office4";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "corsair3":
			d.Text = DLG_TEXT[293];
			Pchar.model = "corsair3";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "corsair1_3":
			d.Text = DLG_TEXT[293];
			Pchar.model = "corsair1_3";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "blackman":
			d.Text = DLG_TEXT[293];
			Pchar.model = "blackman";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "bocman3":
			d.Text = DLG_TEXT[293];
			Pchar.model = "bocman3";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "fawn":
			d.Text = DLG_TEXT[293];
			Pchar.model = "fawn";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;

		case "shkiper":
			d.Text = DLG_TEXT[293];
			Pchar.model = "shkiper";
			facemaker(pchar);
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
			SendMessage(PChar, "lss", MSG_CHARACTER_SETMODEL, PChar.model, PChar.model.animation);
			ExecuteCharacterEquip(PChar);
		break;
// NK <--

		case "AsYouWish":
			//Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[222];
			Link.l1 = DLG_TEXT[223];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[224];
			Link.l2.go = "Exit_Fire";
		break;
		
		case "Exit_Fire":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.quest.help = "fired";
			AddDialogExitQuest("story_fred_bob_fired");
		break;
		
		case "Exit_Fire2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("story_fred_bob_fired3");
		break;
		
		case "come_back_fredbob":
			d.Text = DLG_TEXT[225] + GetMyName(Pchar) + DLG_TEXT[226];
			Link.l1 = DLG_TEXT[227];
			Link.l1.go = "Fired";
			Link.l2 = DLG_TEXT[228];
			Link.l2.go = "Exit_Fire2";
		break;
		
		case "come_back_fredbob2":
			d.Text = DLG_TEXT[225] + GetMyName(Pchar) + DLG_TEXT[229];
			Link.l1 = DLG_TEXT[230];
			Link.l1.go = "Fired";
			Link.l2 = DLG_TEXT[228];
			Link.l2.go = "Exit_Fire2";
		break;

		case "Fired":
			Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[231];
			Link.l1 = DLG_TEXT[232];
			Link.l1.go = "Fired2";
		break;
		
		case "Fired2":
			//NPChar.quest.officerprice = "1000"; // added by MAXIMUS
			NPChar.quest.officerprice = sti(NPChar.quest.officerprice) + 250; // added by Levis
			d.Text = DLG_TEXT[233];
			Link.l1 = DLG_TEXT[234];
			Link.l1.go = "Fired3";
			Link.l2 = DLG_TEXT[235];
			Link.l2.go = "Exit";
		break;	
		
		case "Fired3":
			//NPChar.quest.officerprice = "2000"; // added by MAXIMUS
			NPChar.quest.officerprice = sti(NPChar.quest.officerprice) + 250; // added by Levis
			d.Text = DLG_TEXT[236] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[237];
			Link.l1 = DLG_TEXT[238];
			Link.l1.go = "Fired4";
			Link.l2 = DLG_TEXT[239];
			Link.l2.go = "Exit";
		break;	
		
		case "Fired4":
			//NPChar.quest.officerprice = "2500"; // added by MAXIMUS
			NPChar.quest.officerprice = sti(NPChar.quest.officerprice) + 250; // added by Levis
			d.Text = DLG_TEXT[240] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[241];
			Link.l1 = DLG_TEXT[242];
			Link.l1.go = "Rehired";
			Link.l2 = DLG_TEXT[243];
			Link.l2.go = "Exit";
		break;	
		
		case "Rehired":
			d.Text = DLG_TEXT[244] + GetMyName(Pchar) + DLG_TEXT[245];
			Link.l1 = DLG_TEXT[246];
			Link.l1.go = "exit_hire2";
		break;	
		
		case "exit_hire2":
			Diag.TempNode = "hired";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.quest.help = "hired";
			SetOfficersIndex(Pchar, 2, GetCharacterIndex("Fred Bob"));
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2500);
			AddMoneyToCharacter(characterFromID("Fred Bob"), 2500);
		break;

		// NK -->
		case "Difficulty":
			d.Text = DLG_TEXT[247] + stringRet(GetSymbol(GetDifficultyName(GetDifficulty()),0) == "A" || GetSymbol(GetDifficultyName(GetDifficulty()),0) == DLG_TEXT[248], DLG_TEXT[251],DLG_TEXT[252]) + GetDifficultyName(GetDifficulty());
			if(GetShipCap()) { d.Text = d.Text + DLG_TEXT[253]; }
			else { d.Text = d.Text + DLG_TEXT[254]; }
			Link.l1 = stringRet(GetSymbol(GetDifficultyName(1),0) == "A" || GetSymbol(GetDifficultyName(1),0) == DLG_TEXT[248], DLG_TEXT[249], DLG_TEXT[250]) + GetDifficultyName(1) + ".";
			Link.l1.go = "diff1";
			Link.l2 = stringRet(GetSymbol(GetDifficultyName(2),0) == "A" || GetSymbol(GetDifficultyName(2),0) == DLG_TEXT[248], DLG_TEXT[249], DLG_TEXT[250]) + GetDifficultyName(2) + ".";
			Link.l2.go = "diff2";
			Link.l3 = stringRet(GetSymbol(GetDifficultyName(3),0) == "A" || GetSymbol(GetDifficultyName(3),0) == DLG_TEXT[248], DLG_TEXT[249], DLG_TEXT[250]) + GetDifficultyName(3) + ".";
			Link.l3.go = "diff3";
			Link.l4 = stringRet(GetSymbol(GetDifficultyName(4),0) == "A" || GetSymbol(GetDifficultyName(4),0) == DLG_TEXT[248], DLG_TEXT[249], DLG_TEXT[250]) + GetDifficultyName(4) + ".";
			Link.l4.go = "diff4";
			Link.l5 = DLG_TEXT[255];
			if(GetShipCap()) { Link.l5.go = "shipcapoff"; }
			else { Link.l5.go = "shipcapon"; }
		break;

		case "diff1":
			d.Text = DLG_TEXT[256];
			SetDifficulty(1);
			Link.l1 = "..."
			Link.l1.go = "Exit";
		break;

		case "diff2":
			d.Text = DLG_TEXT[256];
			SetDifficulty(2);
			Link.l1 = "..."
			Link.l1.go = "Exit";
		break;

		case "diff3":
			d.Text = DLG_TEXT[256];
			SetDifficulty(3);
			Link.l1 = "..."
			Link.l1.go = "Exit";
		break;

		case "diff4":
			d.Text = DLG_TEXT[256];
			SetDifficulty(4);
			Link.l1 = "..."
			Link.l1.go = "Exit";
		break;

		case "shipcapon":
			d.Text = DLG_TEXT[257];
			SetShipCap(true);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "shipcapoff":
			d.Text = DLG_TEXT[258];
			SetShipCap(false);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;
		// NK <--

        // boal 05.09.03 offecer need to go to abordage -->
		case "Boal_Abordage":
			Npchar.AbordageMode = makeint(1);
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[52] + PChar.name + "!";
			Link.l1 = DLG_TEXT[198];
			Link.l1.go = "Exit";
		break;

		case "Boal_safeAbordage":
			Npchar.AbordageMode = makeint(0);
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[259];
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "Boal_Stay":
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuest("Boal_LandEnc_OfficerStay");
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[52] + PChar.name + ".";
			Link.l1 = DLG_TEXT[260];
			Link.l1.go = "Exit";
		break;

		case "Boal_Follow":
			SetCharacterTask_FollowCharacter(Characters[GetCharacterIndex(Npchar.id)], PChar); // it works!!!
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[52] + PChar.name + ".";
			Link.l1 = DLG_TEXT[260];
			Link.l1.go = "Exit";
		break;
        // boal 05.09.03 offecer need to go to abordage <--
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}
