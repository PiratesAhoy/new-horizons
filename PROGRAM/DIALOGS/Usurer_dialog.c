void ProcessDialogEvent()
{
	if(GetMusicScheme() == "PGMUS") SetMusicNoPause("music_divide"); // PG // KK
	int LoanSum, LoanInterest, LoanPeriod, LoanResult, iPastMonths, DepositSum, DepositInterest, DepositResult, i;
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;	
	string NPC_Area;
	float NPC_INVEST_RATE = 0.1;	// If you deposit money, the loanshark invests this much of it into local business...
	int NPChar_Investment;		// ... and this is the amount invested
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	NPC_Area = GetTownIDFromLocID(Npchar.location);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

	
		case "LoanGranted_exit":
			Diag.CurrentNode = Diag.TempNode;

		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, makeint(Pchar.Quest.Loans.(NPC_Area).Sum));
			// Pagliarini -->
			Pchar.Quest.Loans.(NPC_Area).TotalSum = makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum) + makeint(Pchar.Quest.Loans.(NPC_Area).Sum);
			Log_SetStringToLog(XI_ConvertString("Total Loan") + " " + makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum));
			int iLoanAmount = sti(Pchar.Quest.Loans.(NPC_Area).TotalSum);
			//Pagliarini <--
			Pchar.Quest.Loans.(NPC_Area) = true;
			Pchar.Quest.Loans.(NPC_Area).StartDay = getDataDay();
			Pchar.Quest.Loans.(NPC_Area).StartMonth = getDataMonth();
			Pchar.Quest.Loans.(NPC_Area).StartYear = getDataYear();
			Pchar.Quest.Loans.(NPC_Area).StartTime = getTime();

			PChar.quest.(NPC_Area).win_condition.l1 = "Timer";
			PChar.quest.(NPC_Area).win_condition.l1.date.day = GetAddingDataDay(0, sti(PChar.Quest.Loans.(NPC_Area).Period), 0);
			PChar.quest.(NPC_Area).win_condition.l1.date.month = GetAddingDataMonth(0, sti(PChar.Quest.Loans.(NPC_Area).Period), 0);
			PChar.quest.(NPC_Area).win_condition.l1.date.year = GetAddingDataYear(0, sti(PChar.Quest.Loans.(NPC_Area).Period), 0);
			PChar.quest.(NPC_Area).win_condition = "Loans_" + (NPC_Area); // KK
			
// KK -->
			Preprocessor_AddQuestData("town", FindTownName(NPC_Area));
			Preprocessor_AddQuestData("island", FindIslandName(GetIslandIDFromTown(NPC_Area)));
			Preprocessor_AddQuestData("ammount", iLoanAmount);
			Preprocessor_AddQuestData("deadline", GetHumanDate(sti(Pchar.quest.(NPC_Area).win_condition.l1.date.year), sti(Pchar.quest.(NPC_Area).win_condition.l1.date.month), sti(Pchar.quest.(NPC_Area).win_condition.l1.date.day))); 
			Preprocessor_AddQuestData("loanshark", GetMySimpleName(NPChar));

			WriteNewLogEntry("Visited "+FindTownName(GetCurrentTownID()),"I was desperate enough to borrow some money from the local loanshark. Now I have to return "+iLoanAmount+" plus interest to "+GetMySimpleName(NPChar)+" by "+GetHumanDate(sti(Pchar.quest.(NPC_Area).win_condition.l1.date.year), sti(Pchar.quest.(NPC_Area).win_condition.l1.date.month), sti(Pchar.quest.(NPC_Area).win_condition.l1.date.day))+".","Ship",true);

			switch (GetTownIDFromLocID(Npchar.location))
			{
				case "Redmond":
					i = 1;
				break;

				case "Oxbay":
					i = 2;
				break;

				case "Greenford":
					i = 3;
				break;

				case "Eleuthera":
					i = 4;
				break;

				case "Alice":
					i = 5;
				break;

				case "Falaise de Fleur":
					i = 6;
				break;

				case "Conceicao":
					i = 7;
				break;

				case "Douwesen":
					i = 8;
				break;

				case "Isla Muelle":
					i = 9;
				break;

				case "Quebradas Costillas":
					i = 10;
				break;

				case "Tortuga":
					i = 11;
				break;

				case "Oranjestad":
					i = 12;
				break;

				case "Willemstad":
					i = 13;
				break;

				case "Turks":
					i = 14;
				break;

				case "Santo Domingo":
					i = 15;
				break;
			}
			DeleteQuestHeader("Loan");
			SetQuestHeader("Loan");
			AddQuestRecord("Loan", i);

			Preprocessor_Remove("town");
			Preprocessor_Remove("island"); // PB
			Preprocessor_Remove("ammount");
			Preprocessor_Remove("deadline");
			Preprocessor_Remove("loanshark");
// <-- KK
			pchar.loan = "true";      //REMOVE WHEN IT WORKS PROP

			DialogExit();

		break;

		case "Deposit_exit":
			Diag.CurrentNode = Diag.TempNode;			
			
		//	DepositSum = -DepositSum;
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -(makeint(Pchar.Quest.Deposits.(NPC_Area).Sum)));
			NPChar_Investment = makeint(sti(Pchar.Quest.Deposits.(NPC_Area).Sum) * NPC_INVEST_RATE);
			SetTownGold(NPC_Area, GetTownGold(NPC_Area) + NPChar_Investment); // GR: Some of deposit invested into town gold
			switch (GetTownEconomy(GetTownFromID(NPC_Area)))
			{
				case TOWN_ECONOMY_STARVING:
					if (NPChar_Investment > 20000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1);
					if (NPChar_Investment > 200000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1);
				break;
				case TOWN_ECONOMY_STRUGGLING:
					if (NPChar_Investment > 100000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1);
					if (NPChar_Investment > 1000000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1);
				break;
				case TOWN_ECONOMY_SURVIVING: if (NPChar_Investment > 750000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1); break;
				case TOWN_ECONOMY_PROSPERING: if (NPChar_Investment > 2000000) AdjustTownEconomy(GetTownFromID(NPC_Area), 1); break;
				// No entry for TOWN_ECONOMY_WEALTHY as that's the maximum economy level!
			}
			Pchar.Quest.Deposits.(NPC_Area) = true;
			Pchar.Quest.Deposits.(NPC_Area).StartDay = getDataDay();
			Pchar.Quest.Deposits.(NPC_Area).StartMonth = getDataMonth();
			Pchar.Quest.Deposits.(NPC_Area).StartYear = getDataYear();
			Pchar.Quest.Deposits.(NPC_Area).StartTime = getTime();
			DialogExit();
			WriteNewLogEntry("Visited "+FindTownName(GetCurrentTownID()),"I deposited some money at the local loanshark. "+GetMySimpleName(NPChar)+" promised a good interest for my "+makeint(Pchar.Quest.Deposits.(NPC_Area).Sum)+" pieces of gold.","Ship",true);      
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			// Pagliarini -->
			// LDH fix for CheckAttribute error 10Sep06
			if (CheckAttribute(Pchar, "Quest.Loans." + NPC_Area + ".TotalSum") && makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum) > 0 )
			{
				Log_SetStringToLog(XI_ConvertString("Debt") + " " + makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum));
			}
			else
			{
				/*switch (GetTownIDFromLocID(Npchar.location))
				{
					case "Redmond":
						i = 1;
					break;

					case "Oxbay":
						i = 2;
					break;

					case "Greenford":
						i = 3;
					break;

					case "Eleuthera":
						i = 4;
					break;

					case "Alice":
						i = 5;
					break;

					case "Falaise de Fleur":
						i = 6;
					break;

					case "Conceicao":
						i = 7;
					break;

					case "Douwesen":
						i = 8;
					break;

					case "Isla Muelle":
						i = 9;
					break;

					case "Quebradas Costillas":
						i = 10;
					break;

					case "Tortuga":
						i = 11;
					break;

					case "Oranjestad":
						i = 12;
					break;

					case "Willemstad":
						i = 13;
					break;
				}	*/
				if (GetAttribute(pchar, "Loan") != "true")
				{
					DeleteQuestHeader("Loan");
					//DeleteQuestRecord("Loan", i);
					DeleteAttribute(Pchar, "quest.Loans." + (NPC_Area));
					DeleteAttribute(Pchar, "quest." + (NPC_Area));		// LDH - removes the indicator that you owe money to this loanshark.
				}
			};
			// Pagliarini <--
			DeleteAttribute(Pchar, "quest.Deposits." + (NPC_Area));
		break;

		case "exit_NoChange":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			// LDH various fixes for odd dialogs 11Sep06
			if(NPChar.quest.meeting == "0")
			{
				NPChar.quest.meeting = 1; 
				Dialog.snd1 = "voice\USDI\USDI001";
				Dialog.snd2 = "voice\USDI\USDI002";
				Dialog.snd3 = "voice\USDI\USDI003";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0], DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6], DLG_TEXT[7] + GetMyRespectfullyName(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10]);
				Link.l1.go = "meeting";
			}
			else
			{
					Dialog.snd1 = "voice\USDI\USDI004";
					Dialog.snd2 = "voice\USDI\USDI005";
					Dialog.snd3 = "voice\USDI\USDI006";
					d.Text = RandPhrase(DLG_TEXT[11] + GetMyRespectfullyName(PChar) + DLG_TEXT[12], TimeGreeting() + DLG_TEXT[13], DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_IMPTITLE, false, false) + DLG_TEXT[15], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
					Link.l1 = LinkRandPhrase(DLG_TEXT[16], DLG_TEXT[17], DLG_TEXT[18]);
					Link.l1.go = "loan";	
					if(makeint(Pchar.money) >= 100)
					{
						Link.l2 = LinkRandPhrase(DLG_TEXT[19], DLG_TEXT[20], DLG_TEXT[21]);
						Link.l2.go = "deposit";				
					}
					Link.l3 = DLG_TEXT[22] + GetMyName(NPChar) + DLG_TEXT[23];
					Link.l3.go = "exit";

				if(CheckAttribute(Pchar, "Quest.Loans." + (NPC_Area)) && makeint(Pchar.Quest.Loans.(NPC_Area)) == true)
				{
					iPastMonths = GetPastTime("Month", makeint(Pchar.Quest.Loans.(NPC_Area).StartYear),makeint(Pchar.Quest.Loans.(NPC_Area).StartMonth),makeint(Pchar.Quest.Loans.(NPC_Area).StartDay), makefloat(Pchar.Quest.Loans.(NPC_Area).StartTime), getDataYear(),getDataMonth(),GetDataDay(), GetTime());
					// Pagliarini -->
					//Pchar.Quest.Loans.(NPC_Area).Result = makeint(Pchar.Quest.Loans.(NPC_Area).Sum) + ((makeint(Pchar.Quest.Loans.(NPC_Area).Sum)/100)*makeint(Pchar.Quest.Loans.(NPC_Area).Interest))*iPastMonths;
					Pchar.Quest.Loans.(NPC_Area).Result = makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum) + ((makeint(Pchar.Quest.Loans.(NPC_Area).TotalSum)/100)*makeint(Pchar.Quest.Loans.(NPC_Area).Interest))*iPastMonths;
					// Pagliarini <--

					Dialog.snd1 = "voice\USDI\USDI007";
					Dialog.snd2 = "voice\USDI\USDI008";
					Dialog.snd3 = "voice\USDI\USDI009";

					d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[24] + GetMyName(Pchar) + DLG_TEXT[25] + Pchar.Quest.Loans.(NPC_Area).Result + DLG_TEXT[26], DLG_TEXT[27] + Pchar.Quest.Loans.(NPC_Area).Result + DLG_TEXT[28], DLG_TEXT[29] + GetMyAddressForm(NPChar, PChar, ADDR_IMPTITLE, false, false) + DLG_TEXT[30] + Pchar.Quest.Loans.(NPC_Area).Result + DLG_TEXT[31], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
					if(makeint(PChar.money) >= makeint(Pchar.Quest.Loans.(NPC_Area).Result))
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[32], DLG_TEXT[33], DLG_TEXT[34]);
						Link.l1.go = "loan_return";				
					}					
					Link.l2 = LinkRandPhrase(DLG_TEXT[35], DLG_TEXT[36] + GetMyName(NPChar) + DLG_TEXT[37], DLG_TEXT[38]);
					Link.l2.go = "Loan_Remind";
					Link.l3 = DLG_TEXT[39];
					Link.l3.go = "exit_NoChange";

				}									
				if(CheckAttribute(Pchar, "Quest.Deposits." + (NPC_Area)) && makeint(Pchar.Quest.Deposits.(NPC_Area)) == true)
				{
					iPastMonths = GetPastTime("Month", makeint(Pchar.Quest.Deposits.(NPC_Area).StartYear),makeint(Pchar.Quest.Deposits.(NPC_Area).StartMonth),makeint(Pchar.Quest.Deposits.(NPC_Area).StartDay), makefloat(Pchar.Quest.Deposits.(NPC_Area).StartTime), getDataYear(),getDataMonth(),GetDataDay(), GetTime());
					Pchar.Quest.Deposits.(NPC_Area).Result = makeint(Pchar.Quest.Deposits.(NPC_Area).Sum) + ((makeint(Pchar.Quest.Deposits.(NPC_Area).Sum)/100)*makeint(Pchar.Quest.Deposits.(NPC_Area).Interest))*iPastMonths;
					Dialog.snd1 = "voice\USDI\USDI010";
					Dialog.snd2 = "voice\USDI\USDI011";
					Dialog.snd3 = "voice\USDI\USDI012";
					d.Text = RandPhrase(DLG_TEXT[40] + GetMyName(Pchar) + DLG_TEXT[41], TimeGreeting() + DLG_TEXT[42], DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_IMPTITLE, false, false) + DLG_TEXT[44], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
					Link.l1 = LinkRandPhrase(DLG_TEXT[45], DLG_TEXT[46], DLG_TEXT[47]);
					Link.l1.go = "Deposit_return";									
					Link.l2 = DLG_TEXT[48] + GetMyName(NPChar) + DLG_TEXT[49];
					Link.l2.go = "exit_NoChange";
					Link.l3 = DLG_TEXT[50];
					Link.l3.go = "exit_NoChange";
				}
// NK -->
				if(CheckAttribute(Pchar, "CrewStatus.explength") && CheckAttribute(PChar,"articles") && sti(PChar.articles)/* && sti(Pchar.CrewStatus.explength) > NORMAL_EXP_LENGTH /2*/)
				{
					Link.l4 = DLG_TEXT[144];
					Link.l4.go = "divide_choose";
				}
// NK <--
			}
		break;

		case "Meeting":
			Dialog.snd1 = "voice\USDI\USDI013";
			Dialog.snd2 = "voice\USDI\USDI014";
			Dialog.snd3 = "voice\USDI\USDI015";
			d.Text = RandPhrase(DLG_TEXT[51] + GetMyFullName(NPChar) + DLG_TEXT[52], DLG_TEXT[53] + GetMyFullName(NPChar) + DLG_TEXT[54], DLG_TEXT[55] + GetMyFullName(NPChar) + DLG_TEXT[56], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[57], DLG_TEXT[58], DLG_TEXT[59]);
			Link.l1.go = "loan";
			if(makeint(Pchar.money) >= 100)
			{
				Link.l2 = LinkRandPhrase(DLG_TEXT[60], DLG_TEXT[61], DLG_TEXT[62]);
				Link.l2.go = "deposit";				
			}
			Link.l3 = DLG_TEXT[63] + GetMyName(NPChar) + DLG_TEXT[64];
			Link.l3.go = "exit";
// NK -->
			if(CheckAttribute(Pchar, "CrewStatus.explength") && CheckAttribute(PChar,"articles") && sti(PChar.articles)/* && sti(Pchar.CrewStatus.explength) > NORMAL_EXP_LENGTH /2*/)
			{
				Link.l4 = DLG_TEXT[144];
				Link.l4.go = "divide_choose";
			}
// NK <--			
		break;

		case "loan":
			Dialog.snd = "voice\USDI\USDI016";
			d.Text = DLG_TEXT[65];
			Link.l1 = DLG_TEXT[66];
			Link.l1.go = "Small";
			Link.l2 = DLG_TEXT[67];
			Link.l2.go = "Medium";
			Link.l3 = DLG_TEXT[68];
			Link.l3.go = "Large";
		break;

		case "small":
			Pchar.Quest.Loans.(NPC_Area).Sum = 500*makeint(Pchar.rank);
// Diamond -->
			if (iRealismMode>1) // KK
			{
				if (makeint(Pchar.rank) <= 20)			
				{
					Pchar.Quest.Loans.(NPC_Area).Sum = (500*(2*makeint(Pchar.rank)))/20;
				}
			}
// Diamond <--
			Dialog.snd = "voice\USDI\USDI017";
			d.Text = DLG_TEXT[69] + Pchar.Quest.loans.(NPC_Area).sum + DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "Interest";
			Link.l2 = DLG_TEXT[72];
			Link.l2.go = "Loan";
			Link.l3 = DLG_TEXT[73];
			Link.l3.go = "Exit";
		break;

		case "Medium":
			Pchar.Quest.Loans.(NPC_Area).Sum = 1500*makeint(Pchar.rank);
// Diamond -->
			if (iRealismMode>1) // KK
			{
				if (makeint(Pchar.rank) <= 20)			
				{
				Pchar.Quest.Loans.(NPC_Area).Sum = (1500*(2*makeint(Pchar.rank)))/20;
				}
			}
// Diamond <--
			Dialog.snd = "voice\USDI\USDI018";
			d.Text = DLG_TEXT[74] + Pchar.Quest.Loans.(NPC_Area).sum + DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "Interest";
			Link.l2 = DLG_TEXT[77];
			Link.l2.go = "Loan";
			Link.l3 = DLG_TEXT[78];
			Link.l3.go = "Exit";
		break;

		case "Large":
			Pchar.Quest.Loans.(NPC_Area).Sum = 3000*makeint(Pchar.rank);
// Diamond -->
			if (iRealismMode>1) // KK
			{
				if (makeint(Pchar.rank) <= 20)			
				{
				Pchar.Quest.Loans.(NPC_Area).Sum = (3000*(2*makeint(Pchar.rank)))/20;
				}
			}
// Diamond <--
			Dialog.snd = "voice\USDI\USDI019";
			d.Text = DLG_TEXT[79] + Pchar.Quest.Loans.(NPC_Area).sum + DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "Interest";
			Link.l2 = DLG_TEXT[82];
			Link.l2.go = "Loan";
			Link.l3 = DLG_TEXT[83];
			Link.l3.go = "Exit";
		break;

		case "Interest":
			Pchar.Quest.Loans.(NPC_Area).Interest = 11 - CalcCharacterSkill(PChar,SKILL_COMMERCE); // NK
			Dialog.snd = "voice\USDI\USDI020";
			d.Text = Pchar.Quest.Loans.(NPC_Area).Interest + DLG_TEXT[84]; 
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "Period";
			Link.l3 = DLG_TEXT[86];
			Link.l3.go = "Exit";
		break;

		case "Period":
			Pchar.Quest.Loans.(NPC_Area).Period = makeint(makeint(Pchar.reputation)/20) + 1;			
			Dialog.snd = "voice\USDI\USDI021";
			d.Text =  DLG_TEXT[87] + GetMyName(Pchar) + DLG_TEXT[88] + Pchar.Quest.Loans.(NPC_Area).Period + DLG_TEXT[89]; 
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "LoanGranted";
			Link.l3 = DLG_TEXT[91];
			Link.l3.go = "Exit";
		break;


		case "LoanGranted":
			Dialog.snd = "voice\USDI\USDI022";
			d.Text = DLG_TEXT[92];
			Link.l1 = DLG_TEXT[93];
			Link.l1.go = "LoanGranted_exit";
		break;

		case "Loan_Remind":
			Dialog.snd = "voice\USDI\USDI023";
			d.Text = DLG_TEXT[94];
			Link.l1 = DLG_TEXT[95];
			Link.l1.go = "exit_NoChange";
		break;

		case "loan_return":
			PlayStereoSound("INTERFACE\took_item.wav");
			addMoneyToCharacter(Pchar, -(makeint(Pchar.Quest.Loans.(NPC_Area).Result)));
			DeleteAttribute(PChar, "quest.loans." + (NPC_Area)); 
			pchar.loan = "false";			//REMOVE THIS WHEN WORK PROP
			//unpaid_usurers mod --->
			if(CheckAttribute(NPchar, "is_mad")) 
			{
				DeleteAttribute(NPchar, "is_mad");
				Pchar.mad_usurer = makeint(Pchar.mad_usurer) - 1;
			}
			//unpaid_usurers mod <---

			Dialog.snd1 = "voice\USDI\USDI024";
			Dialog.snd2 = "voice\USDI\USDI025";
			Dialog.snd3 = "voice\USDI\USDI026";
			d.Text = RandPhrase(DLG_TEXT[96], DLG_TEXT[97],  DLG_TEXT[98] + GetMyAddressForm(NPChar, PChar, ADDR_IMPTITLE, false, false) + DLG_TEXT[99], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[100], DLG_TEXT[101], DLG_TEXT[102]);
			Link.l1.go = "loan";
			if(makeint(PChar.money) >= 100)
			{
				Link.l2 = LinkRandPhrase(DLG_TEXT[103], DLG_TEXT[104], DLG_TEXT[105]);
				Link.l2.go = "deposit";				
			}
			Link.l3 = DLG_TEXT[106] + GetMyName(NPChar) + DLG_TEXT[107];
			Link.l3.go = "exit";
		break;

		case "deposit":
			Dialog.snd1 = "voice\USDI\USDI027";
			Dialog.snd2 = "voice\USDI\USDI028";
			Dialog.snd3 = "voice\USDI\USDI029";
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[108], DLG_TEXT[109], DLG_TEXT[110], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = DLG_TEXT[111] + makeint(makeint(PChar.money)/40)*10 + DLG_TEXT[112];
			Link.l1.go = "quarter";
			Link.l2 = DLG_TEXT[113] + makeint(makeint(PChar.money)/20)*10 + DLG_TEXT[114];
			Link.l2.go = "half";
			Link.l3 = DLG_TEXT[169] + makeint(makeint(PChar.money)*0.75/10)*10 + DLG_TEXT[170];	// LDH 21Apr09
			Link.l3.go = "most";
			Link.l4 = DLG_TEXT[115] + makeint(makeint(PChar.money)/10)*10 + DLG_TEXT[116];
			Link.l4.go = "All";
		break;

		case "quarter":
			Pchar.Quest.Deposits.(NPC_Area).Interest = CalcCharacterSkill(PChar,SKILL_COMMERCE) + 1; // NK
			Pchar.Quest.Deposits.(NPC_Area).Sum = makeint(makeint(PChar.money)/40)*10;
			Dialog.snd = "voice\USDI\USDI030";
			d.Text = DLG_TEXT[117] + Pchar.Quest.Deposits.(NPC_Area).Interest + DLG_TEXT[118];
			Link.l1 = DLG_TEXT[119];
			Link.l1.go = "Deposit_placed";
			Link.l2 = DLG_TEXT[120];
			Link.l2.go = "Deposit";
			Link.l3 = DLG_TEXT[121];
			Link.l3.go = "Exit";
		break;

		case "half":
			Pchar.Quest.Deposits.(NPC_Area).Interest = CalcCharacterSkill(PChar,SKILL_COMMERCE) + 1; // NK
			Pchar.Quest.Deposits.(NPC_Area).Sum = makeint(makeint(PChar.money)/20)*10;
			Dialog.snd = "voice\USDI\USDI031";
			d.Text = DLG_TEXT[122] + Pchar.Quest.Deposits.(NPC_Area).Interest + DLG_TEXT[123];
			Link.l1 = DLG_TEXT[124];
			Link.l1.go = "Deposit_placed";
			Link.l2 = DLG_TEXT[125];
			Link.l2.go = "Deposit";
			Link.l3 = DLG_TEXT[126];
			Link.l3.go = "Exit";
		break;

		case "most":							// LDH 21Apr09
			Pchar.Quest.Deposits.(NPC_Area).Interest = CalcCharacterSkill(PChar,SKILL_COMMERCE) + 1; // NK
			Pchar.Quest.Deposits.(NPC_Area).Sum = makeint(makeint(PChar.money)*0.75/10)*10;
			Dialog.snd = "voice\USDI\USDI032";
			d.Text = DLG_TEXT[127] + Pchar.Quest.Deposits.(NPC_Area).Interest + DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "Deposit_placed";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "Deposit";
			Link.l3 = DLG_TEXT[131];
			Link.l3.go = "Exit";		
		break;

		case "All":
			Pchar.Quest.Deposits.(NPC_Area).Interest = CalcCharacterSkill(PChar,SKILL_COMMERCE) + 1; // NK
			Pchar.Quest.Deposits.(NPC_Area).Sum = makeint(makeint(PChar.money)/10)*10;
			Dialog.snd = "voice\USDI\USDI032";
			d.Text = DLG_TEXT[127] + Pchar.Quest.Deposits.(NPC_Area).Interest + DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "Deposit_placed";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "Deposit";
			Link.l3 = DLG_TEXT[131];
			Link.l3.go = "Exit";		
		break;

// NK -->
		case "divide_choose":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "divide_only_money";
			link.l2 = DLG_TEXT[157];
			link.l2.go = "divide_new_expedition";
		break;

		case "divide_only_money":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[158] + DLG_TEXT[159] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[160] +
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[161] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[162] + DLG_TEXT[163] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[164];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "divide2";
			Link.l2 = DLG_TEXT[151];
			Link.l2.go = "Exit_noChange";
		break;

		case "divide_new_expedition":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[165] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[146] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[147] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[148] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[149];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "divide1";
			Link.l2 = DLG_TEXT[151];
			Link.l2.go = "Exit_noChange";
		break;

/*		case "divide":
			Dialog.snd = "voice\USDI\USDI034";
			// LDH fix for odd money display 10Sep06
			d.Text = DLG_TEXT[145] + MakeMoneyShow(GetCrewShare(PChar),MONEY_SIGN,MONEY_DELIVER)+ DLG_TEXT[146] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[147] + MakeMoneyShow(makeint(GetPersonalShareC(PChar)*(0.75 + makefloat(GetFoodEver()) * 0.25)),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[148] + MakeMoneyShow(makeint(makefloat(GetCharacterMoney(PChar)) * LEFTOVER_SHARE),MONEY_SIGN,MONEY_DELIVER) + DLG_TEXT[149];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "divide1";
			Link.l2 = DLG_TEXT[151];
			Link.l2.go = "Exit_noChange";
		break; */

		case "divide1":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[152] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[153];
			Link.l1 = DLG_TEXT[154];
			Link.l1.go = "Exit_noChange";
			DividePlunder(PChar, true);
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

		case "divide2":		// GR: same as "divide1" but without the delay
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[166] + 
			GetCrewShareName(GetCrewShareRatioC(PChar)) + DLG_TEXT[167];
			Link.l1 = DLG_TEXT[168];
			Link.l1.go = "Exit_noChange";
			DividePlunder(PChar, false);
		break;
// NK <--

		case "Deposit_placed":
			Dialog.snd = "voice\USDI\USDI033";
			d.Text = DLG_TEXT[132];
			Link.l1 = DLG_TEXT[133];			
			Link.l1.go = "Deposit_Exit";		
		break;

		case "Deposit_return":
			Dialog.snd = "voice\USDI\USDI034";
			d.Text = DLG_TEXT[134] + Pchar.Quest.Deposits.(NPC_Area).Result + DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];			
			Link.l1.go = "Deposit_return_1";		
			Link.l2 = DLG_TEXT[137];			
			Link.l2.go = "Exit_noChange";		
		break;

		case "Deposit_return_1":
			PlayStereoSound("INTERFACE\took_item.wav");
			addMoneyToCharacter(Pchar, makeint(Pchar.Quest.Deposits.(NPC_Area).Result));
			DeleteAttribute(PChar,"quest.deposits." + (NPC_Area));
			Dialog.snd = "voice\USDI\USDI035";
			d.Text = DLG_TEXT[138];			
			Link.l1 = DLG_TEXT[139];			
			Link.l1.go = "Exit";		
		break;

		case "DeadMotherfucker":
			Dialog.Tempnode = "DeadMotherFucker_1";
			Dialog.snd = "voice\USDI\USDI035";
			d.Text = DLG_TEXT[140];			
			Link.l1 = DLG_TEXT[141];			
			Link.l1.go = "Exit";		
		break;

		case "DeadMotherFucker_1":			
			Dialog.snd = "voice\USDI\USDI035";
			d.Text = DLG_TEXT[142];			
			Link.l1 = DLG_TEXT[143];			
			Link.l1.go = "Exit";		
		break;


		}
}

