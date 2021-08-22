void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	int winlink;	//ccc
	int pickgold;

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			int maxChance = 13;

			bool disAllow8 = false;
			bool disAllow10 = false;
			bool disAllow12 = false;

			if (CheckAttribute(PChar, "treasureloc"))														{disallow12 = true;}
			if (ModelIsType(NPChar.model, "poor_citizens") || ModelIsType(NPChar.model, "Lower_Citizens"))	{disallow10 = true;}
			else																							{disallow8  = true;}

 			// Aconcagua: special handling for female officers, simplified by PB
			if (NPChar.sex == "woman" && rand(100) >= FEMALE_OFFICER_PERCENTAGE)
				disallow10 = true;

			bool calcNew = true;
			int chance;
			while(calcNew)
			{
				chance = Rand(maxChance);
				calcNew = false;
				if(disallow8)
				{
					if(chance == 8 || chance == 9)
						calcNew = true;
				}
				if(disallow10 && chance == 10)
				{
					calcNew = true;
				}
				if(disallow12 && chance == 12)
					calcNew = true;
			}

			switch(chance)
			{
				case 0:						// advice
					d.Text = DLG_TEXT[0]; 
					Link.l1 = DLG_TEXT[1];
					Link.l1.go = "skeletons";
					Link.l2 = DLG_TEXT[2];
					Link.l2.go = "exit";
				break;

				case 1:						// recognized or advice
					// ccc Dec 05 You are recognized for your pirating actions
					if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE)	// PB: Link this to acting as a pirate
					{
						d.Text = DLG_TEXT[294];
						Link.l1 = RandSwear() + DLG_TEXT[295];
						Link.l1.go = "alarm";
					}
					else
					{
						d.Text = DLG_TEXT[3];
						Link.l1 = DLG_TEXT[4];
						Link.l1.go = "police";
						Link.l2 = DLG_TEXT[5];
						Link.l2.go = "exit";
					}	// ccc hoist flag end
				break;

				case 2:						// advice
					d.Text = DLG_TEXT[6];
					Link.l1 = DLG_TEXT[7];
					Link.l1.go = "health";
					Link.l2 = DLG_TEXT[8];
					Link.l2.go = "exit";
				break;

				case 3:						// advice
					d.Text = DLG_TEXT[9];
					Link.l1 = DLG_TEXT[10];
					Link.l1.go = "tavern";
					Link.l2 = DLG_TEXT[11];
					Link.l2.go = "exit";
				break;

				case 4:						// advice
					d.Text = DLG_TEXT[12];
					Link.l1 = DLG_TEXT[13];
					Link.l1.go = "officer";
					Link.l2 = DLG_TEXT[14];
					Link.l2.go = "exit";
				break;

				case 5:						// advice
					d.Text = DLG_TEXT[15];
					Link.l1 = DLG_TEXT[16];
					Link.l1.go = "shipyard";
					Link.l2 = DLG_TEXT[17];
					Link.l2.go = "exit";
				break;

				case 6:						// normal merchant
					d.Text = DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "torg";
					Link.l2 = DLG_TEXT[20];
					Link.l2.go = "exit_once_more";
				break;

				case 7:						// bandage
					d.Text = DLG_TEXT[21];
					Link.l2 = DLG_TEXT[23];
					Link.l2.go = "exit_once_more_bandage";
					if(sti(PChar.money) >= 120)
					{
						Link.l1 = DLG_TEXT[22];
						Link.l1.go = "bandage";
					}
				break;

				case 8:						// beggar
					d.Text = DLG_TEXT[24];
					Link.l1 = DLG_TEXT[25];
					Link.l1.go = "reput";
					Link.l2 = DLG_TEXT[26];
					Link.l2.go = "exit_out";
				break;

				case 9:						// beggar or skill
					if (1 < Rand(20))
					{
						switch(Rand(1))
						{
							case 0:						// beggar
								if (PChar.sex == "woman") Preprocessor_Add("title", XI_ConvertString("Madam"));
								else Preprocessor_Add("title", XI_ConvertString("Sir"));
								Preprocessor_Add("person", XI_ConvertString(NPChar.sex));
								d.Text = DLG_TEXT[27];
								Link.l1 = DLG_TEXT[28];
								Link.l1.go = "beg";
								Link.l2 = DLG_TEXT[29];
								Link.l2.go = "exit_out";
							break;

							case 1:						// beggar
								Preprocessor_Add("title", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
								Preprocessor_Add("person", XI_ConvertString(NPChar.sex));
								d.Text = DLG_TEXT[30];
								Link.l1 = DLG_TEXT[31];
								Link.l1.go = "beg";
								Link.l2 = DLG_TEXT[32];
								Link.l2.go = "exit_out";
							break;
						}
					}
					else
					{									// skill
						d.Text = DLG_TEXT[33];
						Link.l1 = DLG_TEXT[34];
						Link.l1.go = "skill";
						Link.l2 = DLG_TEXT[35];
						Link.l2.go = "exit_out";
					}
				break;
				
				case 10:
					// NK increase skillmaster to 5% of the time-->
					if (UsableOfficer(NPChar) && 11 < Rand(19))		// officer, PB: Only for REAL officers
					{
						d.Text = DLG_TEXT[36];
						if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
						{
							Link.l1 = DLG_TEXT[37];
							Link.l1.go = "enlist_me";
						}
						Link.l2 = DLG_TEXT[38];
						Link.l2.go = "exit_out";
					}
					else
					{									// skill
						d.Text = DLG_TEXT[33];
						Link.l1 = DLG_TEXT[34];
						Link.l1.go = "skill";
						Link.l2 = DLG_TEXT[35];
						Link.l2.go = "exit_out";
					}
					// NK <--
				break;

				case 11:					// advice
					d.Text = DLG_TEXT[39];
					Link.l1 = DLG_TEXT[40];
					Link.l1.go = "masters";
					Link.l2 = DLG_TEXT[41];
					Link.l2.go = "exit";
				break;

				case 12:						// treasure map
					// further reduce the chance of these people
					if(rand(100)<80) {
						d.text = DLG_TEXT[279];
						link.l1 = DLG_TEXT[280];
						link.l1.go = "why";
						link.l2 = DLG_TEXT[281];
						link.l2.go = "exit_out";
					} else {									// I can't talk to you right now, then randomizes again
						d.Text = DLG_TEXT[14];
						Link.l1 = DLG_TEXT[304];
						Link.l1.go = "hqitemseller_busy";
					}
				break;

				// TIH --> highquality item seller Jul29'06
				case 13:										// high quality merchant
					// further reduce the chance of these people
					if(rand(100)<80) {
						d.Text = DLG_TEXT[297];
						Link.l1 = DLG_TEXT[298];
						Link.l1.go = "hqitemseller_look";
						Link.l2 = DLG_TEXT[299];
						Link.l2.go = "hqitemseller_exit";
					} else {									// I can't talk to you right now, then randomizes again
						d.Text = DLG_TEXT[14];
						Link.l1 = DLG_TEXT[304];
						Link.l1.go = "hqitemseller_busy";
					}
				break;
				// TIH <--
			}
			//ccc CR apr01 ->
			if(COASTRAIDER_CHANCE > 0 && AUTOCREATE_CR == 0)		
			{
				if(rand(100)<30)
				{
					Link.l3 = LinkRandPhrase(DLG_TEXT[270], DLG_TEXT[271], DLG_TEXT[272]);
					Link.l3.go = "coastraiders";
				}
				else
				{
					Link.l3 = LinkRandPhrase(DLG_TEXT[270], DLG_TEXT[271], DLG_TEXT[272]);
					Link.l3.go = "NOraiders";
				}
			}
			//ccc CR apr01 <-
		break;

		// ccc CR ->
		case "coastraiders":
			d.text = LinkRandPhrase(DLG_TEXT[273], DLG_TEXT[274], DLG_TEXT[275]);
			link.l1 = LinkRandPhrase(DLG_TEXT[276], DLG_TEXT[277], DLG_TEXT[278]);
			link.l1.go = "exit";
			string islandstr = Islands[GetCharacterCurrentIsland(PChar)].id;
			SetCoastTraffic(islandstr);
			if (NPChar.sex == "man") NPChar.greeting = "Gr_PiratesInPort_m";
		break;

		case "NOraiders":
			d.text = DLG_TEXT[230];
			link.l1 = LinkRandPhrase(DLG_TEXT[276], DLG_TEXT[277], DLG_TEXT[278]);
			link.l1.go = "exit";
		break;
		// ccc CR <-

		case "skeletons":
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "exit";
		break;

		case "police":
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "police1";
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "police1":
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";
		break;

		case "health":
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "health1";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "exit";
		break;

		case "health1":
			d.Text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "exit";
		break;

		case "tavern":
			d.Text = DLG_TEXT[54];
			Link.l1 = DLG_TEXT[55];
			Link.l1.go = "exit";
		break;

		case "officer":
			d.Text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "exit";
		break;

		case "shipyard":
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "exit";
		break;

		case "masters":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "exit";
		break;

		case "torg":
			NPChar.itemtrade.tradetype = IT_TYPE_SNEAKY; // TIH properly set the trader type

			if (NPChar.quest.Meeting != lastspeak_date)
			{
				GiveItemToTrader(NPChar);
				NPChar.quest.Meeting = lastspeak_date;
			}

			Diag.CurrentNode = "once_more";
			DialogExit();

			LaunchItemsTrade(NPChar);
		break;

		// TIH --> high quality item seller Jul29'06
		// sells one (maybe two) very high quality items to the player
		// will not BUY anything, and will not talk to the player again about it
		// do not use minlevel as this is already a rare encounter for the player
		case "hqitemseller_look":
			NPChar.itemtrade.tradetype = IT_TYPE_SNEAKY;

			bool 	gotItem = false;
			bool 	noMore 	= false;
			ref 	itm;
			string	itmid;
			int		randomIdx = 0;
			int		validItemIdxsCount = 0;
			int		validItemIdxs[MAX_ITEMS];
			int 	i;

			// loop though and find only the SPECIAL items
			for(i = FIRST_TRADE_ITEM; i < ITEMS_QUANTITY; i++) {
				makeref(itm, Items[i]);

				if (!CheckAttribute(itm,"sneaky") ) continue;

				validItemIdxs[validItemIdxsCount] = i;
				validItemIdxsCount++;
			}

			// now possibly add more than one item for sell
			while ( !gotItem ) {
				randomIdx = validItemIdxs[rand(validItemIdxsCount-1)];
				makeref(itm, Items[randomIdx]);
				TakeNItems(&NPChar, itm.id, 1);// only one per item
				// add some special info for this, as it wont show up for trade otherwise
				itmid = itm.id;
				NPChar.itemtrade.rareseller = true;
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;	// premium
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;	// premium
				NPChar.itemtrade.itemlist.items.(itmid).quality = 10;	// premium
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	// premium
				// 50% chance to try to add a second item
				if ( (rand(100)<25) ) gotItem = true;// we will only do one
			}

			Diag.CurrentNode = "hqitemseller_nomore";
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
		case "hqitemseller_nomore":
			if (PChar.sex == "woman") 	d.Text = DLG_TEXT[300] + DLG_TEXT[302] + DLG_TEXT[303];
			else 						d.Text = DLG_TEXT[300] + DLG_TEXT[301] + DLG_TEXT[303];
			Link.l1 = DLG_TEXT[304];
			Link.l1.go = "hqitemseller_exit";
		break;
		case "hqitemseller_exit":
			Diag.CurrentNode = "hqitemseller_nomore";
			DialogExit();
		break;
		case "hqitemseller_busy":
			Diag.CurrentNode = "First time";// so if you talk to them again, it chooses a different approach
			DialogExit();
		break;
		// TIH <--

		case "bandage":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -120);
			GiveItem2Character(PChar, "medical1");
			Diag.CurrentNode = "once_more_bandage";
			DialogExit();
		break;

		case "restore_health":
			LAi_SetCurHP(PChar, LAi_GetCharacterMaxHP(PChar));
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;

		case "reput":
			Preprocessor_Add("person", XI_ConvertString(NPChar.sex));
			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit_out";
			Link.l2 = DLG_TEXT[64];
			Link.l2.go = "exit1";
		break;

		case "beg":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -10);
			switch (Rand(2))
			{
					case 0:
						d.Text = DLG_TEXT[65];
						Link.l1 = DLG_TEXT[66];
						Link.l1.go = "restore_health";
					break;

					case 1:
						d.Text = DLG_TEXT[67];
						Link.l1 = DLG_TEXT[68];
						Link.l1.go = "item";
					break;

					case 2:
						Preprocessor_Add("person", XI_ConvertString(PChar.sex));
						d.Text = DLG_TEXT[69];
						Link.l1 = DLG_TEXT[70];
						Link.l1.go = "exit_than";
					break;
			}
		break;

		case "item":
			int ranpick = 1 + Rand(15);// 1 to 16
			GiveItem2Character(PChar, "indian"+ranpick);
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;

		case "enlist_me":
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			d.Text = DLG_TEXT[292];
			Link.l1 = DLG_TEXT[293];
			Link.l1.go = "exit_change_dlg";
			NPChar.offgen = true;
			NPChar.officer = true;
// MAXIMUS interface MOD -->
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
			}*/
			//Levis let's use the unique types you can get from the enc_walker.
			NPChar.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
			LAi_Create_Officer(rand(8), &NPChar); //so that these officers are better than tavern ones.
			PChar.newofficerid = NPChar.id;//MAXIMUS
// MAXIMUS interface MOD <--
		break;

		case "skill":
			switch (Rand(7))
			{
				case 0:
					d.Text = DLG_TEXT[74];
					if(makeint(PChar.skill.Fencing)>9)
					{
						Link.l1 = DLG_TEXT[75];
						Link.l1.go = "exit_Fencing";
					}
					else
					{
						Link.l1 = DLG_TEXT[76];
						Link.l1.go = "Fencing";
					}
					if(makeint(PChar.skill.Defence)>9)
					{
						Link.l1 = DLG_TEXT[77];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l2 = DLG_TEXT[78];
						Link.l2.go = "Defence";
					}
					Link.l3 = DLG_TEXT[79];
					Link.l3.go = "exit_Fencing";
				break;

				case 1:
					d.Text = DLG_TEXT[80];
					if(makeint(PChar.skill.Leadership)>9)
					{
						Link.l1 = DLG_TEXT[81];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[82];
						Link.l1.go = "Leadership";
					}
					Link.l2 = DLG_TEXT[83];
					Link.l2.go = "exit_Leadership";
				break;

				case 2:
					d.Text = DLG_TEXT[84];
					if(makeint(PChar.skill.Sailing)>9)
					{
						Link.l1 = DLG_TEXT[85];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[86];
						Link.l1.go = "Sailing";
					}
					Link.l2 = DLG_TEXT[87];
					Link.l2.go = "exit_Sailing";
				break;

				case 3:
					d.Text = DLG_TEXT[88];
					if(makeint(PChar.skill.Accuracy)>9)
					{
						Link.l1 = DLG_TEXT[89];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[90];
						Link.l1.go = "Accuracy";
					}
					Link.l2 = DLG_TEXT[91];
					Link.l2.go = "exit_Accuracy";
				break;

				case 4:
					d.Text = DLG_TEXT[92];
					if(makeint(PChar.skill.Cannons)>9)
					{
						Link.l1 = DLG_TEXT[93];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[94];
						Link.l1.go = "Cannons";

					}
					Link.l2 = DLG_TEXT[95];
					Link.l2.go = "exit_Cannons";
				break;

				case 5:
					d.Text = DLG_TEXT[96];
					if(makeint(PChar.skill.Grappling)>9)
					{
						Link.l1 = DLG_TEXT[97];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[98];
						Link.l1.go = "Grappling";
					}
					Link.l2 = DLG_TEXT[99];
					Link.l2.go = "exit_Grappling";
				break;

				case 6:
					d.Text = DLG_TEXT[100];
					if(makeint(PChar.skill.Repair)>9)
					{
						Link.l1 = DLG_TEXT[101];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[102];
						Link.l1.go = "Repair";
					}
					Link.l2 = DLG_TEXT[103];
					Link.l2.go = "exit_Repair";
				break;
	
				case 7:
					d.Text = DLG_TEXT[104];
					if(makeint(PChar.skill.Commerce)>9)
					{
						Link.l1 = DLG_TEXT[105];
						Link.l1.go = "exit_out";
					}
					else
					{
						Link.l1 = DLG_TEXT[106];
						Link.l1.go = "Commerce";
					}
					Link.l2 = DLG_TEXT[107];
					Link.l2.go = "exit_Commerce";
				break;
			}
		break;

		case "Fencing":
			NPChar.sum = (sti(PChar.skill.Fencing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[108] + NPChar.sum + DLG_TEXT[109];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[110];
				Link.l1.go = "exit_Fencing";		
			}
			else
			{
				Link.l1 = DLG_TEXT[111];
				Link.l1.go = "Fencing1";
				Link.l2 = DLG_TEXT[112];
				Link.l2.go = "exit_Fencing";
			}
		break;

		case "Fencing2":
			NPChar.sum = (sti(PChar.skill.Fencing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[113] + NPChar.sum + DLG_TEXT[114];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[115];
				Link.l1.go = "exit_Fencing";		
			}
			else
			{
				Link.l1 = DLG_TEXT[116];
				Link.l1.go = "Fencing1";
				Link.l2 = DLG_TEXT[117];
				Link.l2.go = "exit_Fencing";
			}
		break;

		case "Fencing1":
			NPChar.sum = (sti(PChar.skill.Fencing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Fencing", Rand(sti(PChar.skill.Fencing)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Fencing = makeint(PChar.skill.Fencing) + 1; }
			//PChar.skill.Fencing = makeint(PChar.skill.Fencing) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Fencing",CalculateSkillExperienceFromRank(sti(Pchar.skill.Fencing)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("fencing"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Defence":
			NPChar.sum = (sti(PChar.skill.Defence) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[118] + NPChar.sum + DLG_TEXT[119];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[120];
				Link.l1.go = "exit_Defence";		
			}
			else
			{
				Link.l1 = DLG_TEXT[121];
				Link.l1.go = "Defence1";
				Link.l2 = DLG_TEXT[122];
				Link.l2.go = "exit_Defence";
			}
		break;

		case "Defence2":
			NPChar.sum = (sti(PChar.skill.Defence) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[123] + NPChar.sum + DLG_TEXT[124];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[125];
				Link.l1.go = "exit_Defence";		
			}
			else
			{
				Link.l1 = DLG_TEXT[126];
				Link.l1.go = "Defence1";
				Link.l2 = DLG_TEXT[127];
				Link.l2.go = "exit_Defence";
			}
		break;

		case "Defence1":
			NPChar.sum = (sti(PChar.skill.Defence) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Defence", Rand(sti(PChar.skill.Defence)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Defence = makeint(PChar.skill.Defence) + 1; }
			//PChar.skill.Defence = makeint(PChar.skill.Defence) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Defence",CalculateSkillExperienceFromRank(sti(Pchar.skill.Defence)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("Defence"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Leadership":
			NPChar.sum = (sti(PChar.skill.Leadership) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[128] + NPChar.sum + DLG_TEXT[129];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[130];
				Link.l1.go = "exit_Leadership";		
			}
			else
			{
				Link.l1 = DLG_TEXT[131];
				Link.l1.go = "Leadership1";
				Link.l2 = DLG_TEXT[132];
				Link.l2.go = "exit_Leadership";
			}
		break;

		case "Leadership2":
			NPChar.sum = (sti(PChar.skill.Leadership) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[133] + NPChar.sum + DLG_TEXT[134];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[135];
				Link.l1.go = "exit_Leadership";		
			}
			else
			{
				Link.l1 = DLG_TEXT[136];
				Link.l1.go = "Leadership1";
				Link.l2 = DLG_TEXT[137];
				Link.l2.go = "exit_Leadership";
			}
		break;

		case "Leadership1":
			NPChar.sum = (sti(PChar.skill.Leadership) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Leadership", Rand(sti(PChar.skill.Leadership)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Leadership = makeint(PChar.skill.Leadership) + 1; }
			//PChar.skill.Leadership = makeint(PChar.skill.Leadership) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Leadership",CalculateSkillExperienceFromRank(sti(Pchar.skill.Leadership)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("leadership"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Sailing":
			NPChar.sum = (sti(PChar.skill.Sailing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[138] + NPChar.sum + DLG_TEXT[139];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[140];
				Link.l1.go = "exit_Sailing";		
			}
			else
			{
				Link.l1 = DLG_TEXT[141];
				Link.l1.go = "Sailing1";
				Link.l2 = DLG_TEXT[142];
				Link.l2.go = "exit_Sailing";
			}
		break;

		case "Sailing2":
			NPChar.sum = (sti(PChar.skill.Sailing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[143] + NPChar.sum + DLG_TEXT[144];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[145];
				Link.l1.go = "exit_Sailing";		
			}
			else
			{
				Link.l1 = DLG_TEXT[146];
				Link.l1.go = "Sailing1";
				Link.l2 = DLG_TEXT[147];
				Link.l2.go = "exit_Sailing";
			}
		break;

		case "Sailing1":
			NPChar.sum = (sti(PChar.skill.Sailing) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Sailing", Rand(sti(PChar.skill.Sailing)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Sailing = makeint(PChar.skill.Sailing) + 1; }
			//PChar.skill.Sailing = makeint(PChar.skill.Sailing) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Sailing",CalculateSkillExperienceFromRank(sti(Pchar.skill.Sailing)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, - sti(NPChar.sum));
			GotSkill("sailing"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Accuracy":
			NPChar.sum = (sti(PChar.skill.Accuracy) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[148] + NPChar.sum + DLG_TEXT[149];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[150];
				Link.l1.go = "exit_Accuracy";		
			}
			else
			{
				Link.l1 = DLG_TEXT[151];
				Link.l1.go = "Accuracy1";
				Link.l2 = DLG_TEXT[152];
				Link.l2.go = "exit_Accuracy";
			}
		break;

		case "Accuracy2":
			NPChar.sum = (sti(PChar.skill.Accuracy) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[153] + NPChar.sum + DLG_TEXT[154];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[155];
				Link.l1.go = "exit_Accuracy";		
			}
			else
			{
				Link.l1 = DLG_TEXT[156];
				Link.l1.go = "Accuracy1";
				Link.l2 = DLG_TEXT[157];
				Link.l2.go = "exit_Accuracy";
			}
		break;

		case "Accuracy1":
			NPChar.sum = (sti(PChar.skill.Accuracy) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Accuracy", Rand(sti(PChar.skill.Accuracy)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Accuracy = makeint(PChar.skill.Accuracy) + 1; }
			//PChar.skill.Accuracy = makeint(PChar.skill.Accuracy) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Accuracy",CalculateSkillExperienceFromRank(sti(Pchar.skill.Accuracy)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("accuracy"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Cannons":
			NPChar.sum = (sti(PChar.skill.Cannons) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[158] + NPChar.sum + DLG_TEXT[159];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[160];
				Link.l1.go = "exit_Cannons";		
			}
			else
			{
				Link.l1 = DLG_TEXT[161];
				Link.l1.go = "Cannons1";
				Link.l2 = DLG_TEXT[162];
				Link.l2.go = "exit_Cannons";
			}
		break;

		case "Cannons2":
			NPChar.sum = (sti(PChar.skill.Cannons) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[163] + NPChar.sum + DLG_TEXT[164];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[165];
				Link.l1.go = "exit_Cannons";		
			}
			else
			{
				Link.l1 = DLG_TEXT[166];
				Link.l1.go = "Cannons1";
				Link.l2 = DLG_TEXT[167];
				Link.l2.go = "exit_Cannons";
			}
		break;

		case "Cannons1":
			NPChar.sum = (sti(PChar.skill.Cannons) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Cannons", Rand(sti(PChar.skill.Cannons)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Cannons = makeint(PChar.skill.Cannons) + 1; }
			//PChar.skill.Cannons = makeint(PChar.skill.Cannons) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Cannons",CalculateSkillExperienceFromRank(sti(Pchar.skill.Cannons)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("gunnery"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Grappling":
			NPChar.sum = (sti(PChar.skill.Grappling) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[168] + NPChar.sum + DLG_TEXT[169];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[170];
				Link.l1.go = "exit_Grappling";		
			}
			else
			{
				Link.l1 = DLG_TEXT[171];
				Link.l1.go = "Grappling1";
				Link.l2 = DLG_TEXT[172];
				Link.l2.go = "exit_Grappling";
			}
		break;

		case "Grappling2":
			NPChar.sum = (sti(PChar.skill.Grappling) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[173] + NPChar.sum + DLG_TEXT[174];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[175];
				Link.l1.go = "exit_Grappling";		
			}
			else
			{
				Link.l1 = DLG_TEXT[176];
				Link.l1.go = "Grappling1";
				Link.l2 = DLG_TEXT[177];
				Link.l2.go = "exit_Grappling";
			}
		break;

		case "Grappling1":
			NPChar.sum = (sti(PChar.skill.Grappling) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Grappling", Rand(sti(PChar.skill.Grappling)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Grappling = makeint(PChar.skill.Grappling) + 1; }
			//PChar.skill.Grappling = makeint(PChar.skill.Grappling) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Grappling",CalculateSkillExperienceFromRank(sti(Pchar.skill.Grappling)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("grappling"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Repair":
			NPChar.sum = (sti(PChar.skill.Repair) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[178] + NPChar.sum + DLG_TEXT[179];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[180];
				Link.l1.go = "exit_Repair";		
			}
			else
			{
				Link.l1 = DLG_TEXT[181];
				Link.l1.go = "Repair1";
				Link.l2 = DLG_TEXT[182];
				Link.l2.go = "exit_Repair";
			}
		break;

		case "Repair2":
			NPChar.sum = (sti(PChar.skill.Repair) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[183] + NPChar.sum + DLG_TEXT[184];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[185];
				Link.l1.go = "exit_Repair";		
			}
			else
			{
				Link.l1 = DLG_TEXT[186];
				Link.l1.go = "Repair1";
				Link.l2 = DLG_TEXT[187];
				Link.l2.go = "exit_Repair";
			}
		break;

		case "Repair1":
			NPChar.sum = (sti(PChar.skill.Repair) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Repair", Rand(sti(PChar.skill.Repair)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Repair = makeint(PChar.skill.Repair) + 1; }
			//PChar.skill.Repair = makeint(PChar.skill.Repair) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Repair",CalculateSkillExperienceFromRank(sti(Pchar.skill.Repair)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("repair"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "Commerce":
			NPChar.sum = (sti(PChar.skill.Commerce) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[188] + NPChar.sum + DLG_TEXT[189];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[190];
				Link.l1.go = "exit_Commerce";		
			}
			else
			{
				Link.l1 = DLG_TEXT[191];
				Link.l1.go = "Commerce1";
				Link.l2 = DLG_TEXT[192];
				Link.l2.go = "exit_Commerce";
			}
		break;

		case "Commerce2":
			NPChar.sum = (sti(PChar.skill.Commerce) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
			d.Text = DLG_TEXT[193] + NPChar.sum + DLG_TEXT[194];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				Link.l1 = DLG_TEXT[195];
				Link.l1.go = "exit_Commerce";		
			}
			else
			{
				Link.l1 = DLG_TEXT[196];
				Link.l1.go = "Commerce1";
				Link.l2 = DLG_TEXT[197];
				Link.l2.go = "exit_Commerce";
			}
		break;

		case "Commerce1":
			NPChar.sum = (sti(PChar.skill.Commerce) + 1) * intret(AUTO_SKILL_SYSTEM, 10000, 1000);
//			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(GetMainCharacter(), "Commerce", Rand(sti(PChar.skill.Commerce)+1)*5000); }// MAXIMUS - new skillup system
//			else { PChar.skill.Commerce = makeint(PChar.skill.Commerce) + 1; }
			//PChar.skill.Commerce = makeint(PChar.skill.Commerce) + 1;		// LDH reverted 03Feb09
			AddXPtoSkill(Pchar,"Commerce",CalculateSkillExperienceFromRank(sti(Pchar.skill.Commerce)+1)); //Levis
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -sti(NPChar.sum));
			GotSkill("commerce"); // ccc apr11
			Diag.CurrentNode = "get_out";
			DialogExit();
			DeleteAttribute(NPChar, "NPChar.sum");
		break;

		case "thanx":
			if (NPChar.sex == "woman") NPChar.greeting = "Gr_Distinguished_f";		// LDH 18Mar09
			else NPChar.greeting = "Gr_Distinguished_m";
			d.Text = DLG_TEXT[198];
			Link.l1 = DLG_TEXT[199];
			Link.l1.go = "exit_than";
		break;

		case "once_more_bandage":
			d.Text = DLG_TEXT[200];
			Link.l2 = DLG_TEXT[202];
			Link.l2.go = "exit_once_more_bandage";
			if(sti(PChar.money) >= 120)
			{
				Link.l1 = DLG_TEXT[201];
				Link.l1.go = "bandage";
			}
		break;

		case "once_more":
			d.Text = DLG_TEXT[203];
			Link.l1 = DLG_TEXT[204];
			Link.l1.go = "torg";
			Link.l2 = DLG_TEXT[205];
			Link.l2.go = "exit_once_more";
		break;

		case "get_out":
			if(NPChar.sex == "man") NPChar.greeting = "Gr_GetOut_m";
			d.Text = DLG_TEXT[206];
			Link.l2 = DLG_TEXT[207];
			Link.l2.go = "exit_out";
		break;

		case "got_officer":
			d.Text = DLG_TEXT[208];
			Link.l2 = DLG_TEXT[209];
			Link.l2.go = "exit_off";
		break;

		case "sovet":
			d.Text = DLG_TEXT[210];
			Link.l1 = DLG_TEXT[211];
			Link.l1.go = "advises";
			Link.l2 = DLG_TEXT[212];
			Link.l2.go = "exit";
		break;

		case "advises":
			switch(Rand(6))
			{	
				case 0:
					d.Text = DLG_TEXT[213];
					Link.l1 = DLG_TEXT[214];
					Link.l1.go = "exit";
				break;

				case 1:
					d.Text = DLG_TEXT[215];
					Link.l1 = DLG_TEXT[216];
					Link.l1.go = "police1";
					Link.l2 = DLG_TEXT[217];
					Link.l2.go = "exit";
				break;

				case 2:
					d.Text = DLG_TEXT[218];
					Link.l1 = DLG_TEXT[219];
					Link.l1.go = "health1";
					Link.l2 = DLG_TEXT[220];
					Link.l2.go = "exit";
				break;

				case 3:
					d.Text = DLG_TEXT[221];
					Link.l1 = DLG_TEXT[222];
					Link.l1.go = "exit";
				break;

				case 4:
					d.Text = DLG_TEXT[223];
					Link.l1 = DLG_TEXT[224];
					Link.l1.go = "exit";
				break;

				case 5:
					d.Text = DLG_TEXT[225];
					Link.l1 = DLG_TEXT[226];
					Link.l1.go = "exit";
				break;

				case 6:
					d.Text = DLG_TEXT[227];
					Link.l1 = DLG_TEXT[228];
					Link.l1.go = "exit";
				break;
			}
		break;

		//ccc pickpocket ->
		case "pursegot":
			d.Text = DLG_TEXT[263];
			Link.l1 = DLG_TEXT[264];
			Link.l1.go = "exit_out";
			Link.l2 = DLG_TEXT[265];
			Link.l2.go = "open";
		break;

		case "open":
			switch(Rand(2))
			{	
			    ref mc = GetMainCharacter();
				case 0:
					Diag.CurrentNode = "get_out";
					DialogExit();
					PlaySound("INTERFACE\took_item.wav");
					int win=100+rand(3000); 
					AddMoneyToCharacter(PChar, win);
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You got") + " " + win + " " + LanguageConvertString(tmpLangFileID,"gold."));
					if(AUTO_SKILL_SYSTEM) { AddPartyExPChar(PChar, "Sneak", makeint(win/4)); }
					else { AddPartyExp(PChar, win/4); }
				break;

				case 1:
					Diag.CurrentNode = "get_out";
					DialogExit();
					LAi_QuestDelay("God_hit_us", 0.1);
					PlaySound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
					if(mc.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom4.wav");
					else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Boobytrapped") + "!");
					LAi_ApplyCharacterDamage(PChar, 10);
					if(AUTO_SKILL_SYSTEM) { AddPartyExPChar(PChar, "Sneak", 1500); }
					else { AddPartyExp(PChar, 1500); }
					if(sti(LAi_GetCharacterHP(PChar))<20) Lai_KillCharacter(PChar);
				break;

				case 2:
					Diag.CurrentNode = "get_out";
					DialogExit();
					PChar.chr_ai.poison = 20+rand(50-sti(PChar.skill.Sneak)-sti(PChar.skill.defence) );
					PlaySound("OBJECTS\DUEL\man_hit6.wav");
					Log_SetStringToLog(XI_ConvertString("Poisoned") + "!");
				break;
			}
		break;

		case "alarm":
			if (NPChar.sex == "man") NPChar.greeting = "Gr_alarm_m";
			else NPChar.greeting = "Gr_alarm_f";
			LAi_CharacterPlaySound(NPChar, NPChar.greeting);
			PlaySound("AMBIENT\TOWN\Alarm.wav");//MAXIMUS: town's alarm-bell
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation(GetCurrentCitizenGroup(), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // ccc Dec 05 alerts locals
			Ambush("Soldiers", 4, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, ""); // 4 cops attack you

			ChangeCharacterReputation(PChar, -3);
			Diag.CurrentNode = "get_out";
			DialogExit();
		break;

		case "stolen":
			Preprocessor_Add("money", NPChar.pickgold);
			if (NPChar.sex == "man") NPChar.greeting = "Gr_stolen_m";
			else NPChar.greeting = "Gr_stolen_f";
			d.text = LinkRandPhrase(DLG_TEXT[231], DLG_TEXT[232], DLG_TEXT[233]);
			winlink=rand(100); 
			if(winlink>=50) 
			{
				Link.l1 = LinkRandPhrase(DLG_TEXT[237], DLG_TEXT[238], DLG_TEXT[239]);
				if(rand(100)+sti(PChar.skill.Sneak)>25) {Link.l1.go = "moneyback";}
				else{Link.l1.go = "nomoney";}
			}
			Link.l2 = LinkRandPhrase(DLG_TEXT[234], DLG_TEXT[235], DLG_TEXT[236]);
			if(rand(100)+sti(PChar.skill.Sneak)>80) {Link.l2.go = "moneydouble";}
			else{Link.l2.go = "nomoney";}

			Link.l3 = LinkRandPhrase(DLG_TEXT[240], DLG_TEXT[241], DLG_TEXT[242]);
			if(rand(100)+sti(PChar.skill.leadership)>35) {Link.l3.go = "moneydouble";}
			else{Link.l3.go = "nomoney";}

			if(winlink<50) 
			{
				Link.l4 = LinkRandPhrase(DLG_TEXT[237], DLG_TEXT[238], DLG_TEXT[239]);
				if(rand(100)+sti(PChar.skill.Sneak)>=30) {Link.l4.go = "moneyback";}
				else{Link.l4.go = "nomoney";}
			}
		break;

		case "nomoney":
			if (NPChar.sex == "man") NPChar.greeting = "Gr_nomoney_m";
			else NPChar.greeting = "Gr_nomoney_f";
			LAi_CharacterPlaySound(NPChar, NPChar.greeting);
			d.Text = DLG_TEXT[243];
			Link.l2 = DLG_TEXT[244];
			Link.l2.go = "exit_out";
		break;

		case "moneydouble":
			PlayStereoSound("INTERFACE\took_item.wav");
			if (CheckAttribute(NPChar, "pickgold"))
			{
				// Aconcagua: use pickgold stored at "stolen" instead of whole money
				pickgold = sti(NPChar.pickgold);
				AddMoneyToCharacter(PChar, pickgold);
				// Aconcagua: need to take money from char, too -> attacking afterwards does not double stolen money!
				AddMoneyToCharacter(NPChar, -pickgold);
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You got") + " " +  NPChar.pickgold + " " + XI_ConvertString("gold."));
				if(AUTO_SKILL_SYSTEM) { AddPartyExPChar(PChar, "Sneak", 100+pickgold/4)); }
				else { AddPartyExp(PChar, 100+pickgold/4)); }
				DeleteAttribute(NPChar, "pickgold");	// GR: "pickgold" is checked in "stunned_dialog.c" so you don't lose rep for mugging a pickpocket.  Lose rep if you mug him after he gives your money back.
			}
			d.Text = DLG_TEXT[248];
			Link.l2 = LinkRandPhrase(DLG_TEXT[249], DLG_TEXT[250], DLG_TEXT[251]);
			Link.l2.go = "exit_outrep";
			Link.l3 = LinkRandPhrase(DLG_TEXT[252], DLG_TEXT[253], DLG_TEXT[254]);
			Link.l3.go = "jewel";
		break;

		case "jewel":
			GiveItem2Character(PChar, "jewelry"+(1+rand(15)));
			if(rand(100)+sti(PChar.skill.leadership)<50)
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"The thief spreads the news"));
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"that you receive stolen goods."));
				ChangeCharacterReputation(PChar, -5);
			}
			Diag.CurrentNode = "get_out";
			DialogExit();
		break;

		case "moneyback":
			if(rand(100)>30)
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				// Aconcagua: this seems what was originally intended by KK when calculating FakeMoney at "stolen"
				// what was the intention of reducing the stolen money, however?
				// PB: I have no clue, so let's get rid of it
				pickgold = sti(NPChar.pickgold); // PB: was - 'Rand(200) - 100'
				AddMoneyToCharacter(PChar, pickgold);
				// Aconcagua: so now, leave nothing to the character -> no sense in adding afterwards
				NPChar.money = 0;
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You got") + " " + pickgold + " " + XI_ConvertString("gold."));
				if(AUTO_SKILL_SYSTEM) { AddPartyExPChar(PChar, "Sneak", 100+makeint(pickgold/4))); }
				else { AddPartyExp(PChar, 100+makeint(pickgold/4))); }
				DeleteAttribute(NPChar, "pickgold");	// GR: "pickgold" is checked in "stunned_dialog.c" so you don't lose rep for mugging a pickpocket.  Lose rep if you mug him after he gives your money back.
				d.Text = DLG_TEXT[245];
				Link.l1 = DLG_TEXT[247];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[246];
				Link.l2.go = "exit_out";
			}
			else
			{
				// Aconcagua: only needed for experience; originally (KK), FakeMoney was used, but no sense in reducing exp here
				pickgold = sti(NPChar.pickgold);
				// Aconcagua: TODO: is this intended??? (possibly: -> see winlink at "stolen")
				GiveItem2Character(PChar, "jewelry"+(1+rand(15)));

				// Aconcagua: lets assume he is really a runner as told in [266]...
				// Aconcagua: TODO: should we?
				// if(Rand(100) < xxx)
				// {
				//	NPChar.money = sti(NPChar.money) - pickgold;
				// 	NPChar.pickgold = 0;
				//	// Aconcagua: TODO: do we need an extra dialog then?
				// }
				if(AUTO_SKILL_SYSTEM) { AddPartyExPChar(PChar, "Sneak", 100+makeint(pickgold/2))); }
				else { AddPartyExp(PChar, 100+makeint(pickgold/2))); }
				d.Text = DLG_TEXT[266];
				Link.l2 = DLG_TEXT[268];
				Link.l2.go = "jewel";
				Link.l3 = DLG_TEXT[267];
				if(rand(100)+sti(PChar.skill.leadership)>50) {Link.l3.go = "moneydouble";}
				else{Link.l3.go = "nomoney";}
			}
		break;

		case "donation":
			if(GetCharacterReputation(PChar) < REPUTATION_VERYGOOD) // GR: Only get the change if you're less than Dashing
			{
				ChangeCharacterReputation(PChar, 2);
			}
			PlayStereoSound("INTERFACE\took_item.wav");
			// TIH --> to prevent giving all your money back to the bastard! Aug29''06
			int donationSum = 50 + rand(300);
			if ( sti(PChar.money) < donationSum ) donationSum = makeint(sti(PChar.money) / 2);
			AddMoneytoCharacter(PChar, -donationSum);
			AddMoneytoCharacter(NPChar, donationSum);
			// TIH <--
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;
		//ccc pickpocket <-

		//SCREWFACE : RANDOM TREASURE QUEST GENERATOR---------------------------------------
		case "why":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			d.text = DLG_TEXT[282];
			link.l1 = DLG_TEXT[283];
			link.l1.go = "why_2";
		break;

		case "why_2":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			d.text = DLG_TEXT[284];
			link.l1 = DLG_TEXT[285];
			link.l1.go = "why_3";
		break;

		case "why_3":
			d.text = DLG_TEXT[286] + DLG_TEXT[287]);
			link.l1 = DLG_TEXT[288];
			link.l1.go = "tell_price";
		break;

		case "tell_price":
			NPChar.skill.sneak = rand(makeint(PChar.skill.sneak));
			NPChar.sum = makeint((sti(NPChar.skill.sneak) + 1) * rand(50000));
		//	sum = 10;// DEBUG OVERRIDE
			d.text = NPChar.sum + DLG_TEXT[289];
			if(makeint(PChar.money) < sti(NPChar.sum))
			{
				link.l1 = DLG_TEXT[291];
				link.l1.go = "exit_out";
			}
			else
			{
				link.l1 = DLG_TEXT[290];
				link.l1.go = "accept_secret";
				link.l2 = DLG_TEXT[291];
				link.l2.go = "exit_out";
			}
		break;

		case "accept_secret":
			Diag.CurrentNode = "get_out";
			DialogExit();
			GenerateTreasureQuest();
			AddMoneyToCharacter(PChar, -sti(NPChar.sum));
			PlayStereoSound("INTERFACE\took_item.wav");
			DeleteAttribute(NPChar, "sum");
			PChar.treasuremap = true; // PB: For blinking "X Marks the Spot"
			LaunchPelagoMap();
		break;
		// SCREWFACE END-------------------------------------------------------------

		case "exit_Fencing":
			Diag.CurrentNode = "Fencing2";
			DialogExit();
		break;

		case "exit_Defence":
			Diag.CurrentNode = "Defence2";
			DialogExit();
		break;

		case "exit_Leadership":
			Diag.CurrentNode = "Leadership2";
			DialogExit();
		break;

		case "exit_Sailing":
			Diag.CurrentNode = "Sailing2";
			DialogExit();
		break;

		case "exit_Accuracy":
			Diag.CurrentNode = "Accuracy2";
			DialogExit();
		break;

		case "exit_Cannons":
			Diag.CurrentNode = "Cannons2";
			DialogExit();
		break;

		case "exit_Grappling":
			Diag.CurrentNode = "Grappling2";
			DialogExit();
		break;

		case "exit_Repair":
			Diag.CurrentNode = "Repair2";
			DialogExit();
		break;

		case "exit_Commerce":
			Diag.CurrentNode = "Commerce2";
			DialogExit();
		break;

		case "exit":
			//ccc pickpocket -->
			int pickch=rand(100)+sti(PChar.skill.sneak) + NO_THEFT;
			if (pickch<=30)
			{
				// Aconcagua: slightly changed calculation of pickgold (no negative pickgold possible if PChar.money too little)
				pickgold = sti(PChar.rank) * 1000;
				int leftover = 10 + Rand(30);
				int money = makeint(PChar.money);
				if(money <= leftover)
				{
					DialogExit();
					break;
				}
				if(money - leftover < pickgold)
				pickgold = money - leftover;
				if(GetDifficulty() < DIFFICULTY_SEADOG) // PB: You shouldn't be notified when you get pick-pocketed
					PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(PChar, -pickgold);
				// Aconcagua: add pickgold -> on fighting/stealing, get char's money, too
				AddMoneyToCharacter(NPChar, pickgold);
				// Aconcagua: need to remember for getting back correct amount
				NPChar.pickgold = pickgold;
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"This meeting has really lightened you...")); //NO typo!
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExPChar(PChar, "Leadership", 20+Rand(40));
					AddPartyExPChar(PChar, "Sneak", 20+Rand(40));
				}
				else { AddPartyExp(PChar, 20+Rand(40)); }
				Diag.CurrentNode="stolen";
				DialogExit();
			}
			else
			{ 
				if (pickch>30&&pickch<60)			
				{
					PlaySound("INTERFACE\took_item.wav");
					d.text = DLG_TEXT[255]; 
					winlink=rand(100); 
					if (winlink>=50) 
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[260], DLG_TEXT[261], DLG_TEXT[262]);
						if(rand(100)+(sti(PChar.skill.Sneak)*3)>20){Link.l1.go = "pursegot";}
						else{Link.l1.go = "alarm";}
					}
					Link.l2 = DLG_TEXT[256];
					Link.l2.go = "exit_outrep";
					Link.l3 = LinkRandPhrase(DLG_TEXT[257], DLG_TEXT[258], DLG_TEXT[259]);
					Link.l3.go = "alarm";
					if(winlink<50) 
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[260], DLG_TEXT[261], DLG_TEXT[262]);
						if(rand(100)+(sti(PChar.skill.Sneak)*3)>20){Link.l1.go = "pursegot";}
						else{Link.l1.go = "alarm";}
					}
				}
				else
				{
					Diag.CurrentNode = "sovet";
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"This meeting has really enlightened you..."));
					if(AUTO_SKILL_SYSTEM)
					{
						AddPartyExPChar(PChar, "Leadership", 20+Rand(40));
						AddPartyExPChar(PChar, "Sneak", 20+Rand(40));
					}
					else { AddPartyExp(PChar, 20+Rand(40)); }
					DialogExit();
				}
			}
		break;

		case "exit_outrep":
			if (NPChar.sex == "woman") NPChar.greeting = "Gr_Distinguished_f";	// LDH 18Mar09
			else NPChar.greeting = "Gr_Distinguished_m";		// My, what a distinguished young man
			LAi_CharacterPlaySound(NPChar, NPChar.greeting);
			if(GetCharacterReputation(PChar) < REPUTATION_GOOD) // GR: Only get the increase if you're less than Matey
			{
				ChangeCharacterReputation(PChar, 1);
			}
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;
		//ccc pickpocket <-

		case "exit1":
			if (NPChar.sex == "woman") NPChar.greeting = "Gr_Distinguished_f";	// LDH 18Mar09
			else NPChar.greeting = "Gr_Distinguished_m";
			LAi_CharacterPlaySound(NPChar, NPChar.greeting);
			if(GetCharacterReputation(PChar) < REPUTATION_GOOD) // GR: Only get the increase if you're less than Matey
			{
				ChangeCharacterReputation(PChar, 1); //ccc from 3
			}
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -20);
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;

		case "exit_out":
			Diag.CurrentNode = "get_out";
			DialogExit();
		break;

		case "exit_once_more":
			Diag.CurrentNode = "once_more";
			DialogExit();
		break;

		case "exit_once_more_bandage":
			Diag.CurrentNode = "once_more_bandage";
			DialogExit();
		break;
		
		case "exit_than":
			Diag.CurrentNode = "thanx";
			DialogExit();
		break;

		case "exit_off":
			Diag.CurrentNode = "got_officer";
			DialogExit();
		break;

		// NK -->
		case "exit_change_dlg":
			Diag.CurrentNode = "Node_1";
			DialogExit();
			// DialogMain(characterFromID(PChar.newofficerid));//MAXIMUS //Levis: Creates CTD
			PChar.quest.hire_enc_walker = NPChar.id;
			AddDialogExitQuest("LandEnc Talk to player about hireing");
			DeleteAttribute(PChar,"newofficerid");//MAXIMUS
		break;
		// NK <--
	}
	LanguageCloseFile(tmpLangFileID);
}
