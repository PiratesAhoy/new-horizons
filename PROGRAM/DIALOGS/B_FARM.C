// ccc Buildingset, new file

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	string nr = NPChar.lastname;

	string buildingstr = NPChar.equip.blade;
	aref buildingref;
	Items_FindItem(buildingstr,&buildingref);

	string interiorstr = "simple furniture";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;

	int grgbonus = 0;

	int iDYear = sti(lcn.building.(nr).taxyear);
	int iDMonth = sti(lcn.building.(nr).taxMonth);
	int iDDay = sti(lcn.building.(nr).taxDay);
	int taxdays = GetPastTime("day", iDYear, iDMonth, iDDay, 1, GetDataYear(), GetDataMonth(), GetDataDay(), 1);
	int tax = 0;

	string adress;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ) adress = XI_ConvertString("my Squire");
	else
	{
		if(PChar.sex=="woman") adress = XI_ConvertString("m'lady");
		else adress = XI_ConvertString("Mister");
	}

	PlayStereoSound("ambient\town\dog1.wav");
	PlayStereoSound("ambient\town\owen.wav");
	
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
			Dialog.snd = "voice\PADI\PADI001";

			if(rand(100)<15) // chance for random attack, decrease last figure for fewer attacks
			{
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight	
        		PlayStereoSound("voice\Eng_m_a_070.wav");	
				Dialog.text = LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + DLG_TEXT[3]);
				link.l1 = DLG_TEXT[4];
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = DLG_TEXT[5];
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text = LinkRandPhrase(DLG_TEXT[6] + XI_ConvertString(buildingstr) + DLG_TEXT[7] + adress + "?", DLG_TEXT[8] + XI_ConvertString(buildingstr) + ", " + adress + DLG_TEXT[9], DLG_TEXT[10] + adress + DLG_TEXT[11] + XI_ConvertString(buildingstr) + "?");
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = DLG_TEXT[12];
					Link.l1.go = "infected";
				}
				Link.l2 = DLG_TEXT[121];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(DLG_TEXT[122], DLG_TEXT[123], DLG_TEXT[124]);
				Link.l4.go = "chat";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(taxdays>0)
					{
						link.l5 = DLG_TEXT[13] + taxdays + DLG_TEXT[14];
						if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
						{
							Link.l5.go = "tax";
						}
						else
						{
							Link.l5.go = "taxevasion";
						}
					}

					link.l6 = DLG_TEXT[15] + XI_ConvertString(buildingstr) + DLG_TEXT[16];
					link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
						link.l7 = DLG_TEXT[17];
						link.l7.go = "grenade";
					}

					link.l8 = DLG_TEXT[18];
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = DLG_TEXT[19];
					link.l9.go = "exit";
				}

				Link.l10 = DLG_TEXT[125];
				Link.l10.go = "exit";

				link.l11 = DLG_TEXT[20] + LinkRandPhrase(DLG_TEXT[21], DLG_TEXT[22], DLG_TEXT[23]);
				link.l11.go = "motion";

				link.l12 = DLG_TEXT[24];
				link.l12.go = "odd";

				link.l13 = DLG_TEXT[25] + NPchar.dialog.filename + DLG_TEXT[26];
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = DLG_TEXT[27];

			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = DLG_TEXT[29];
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = DLG_TEXT[27];

			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";	// link l1 exits the dialog

			// Here are some codelines that give you money, items, goods or experience. To activate them delete the comment slashes '//' in front of the code. You can change the amounts to your liking.

			// AddMoneyToCharacter(Pchar, 1000);

			// GiveItem2Character(Pchar, "Spyglass3");
			// GiveItem2Character(Pchar, "Jewelry5");
			// GiveItem2Character(Pchar, "Mineral3");
			// TakenItems(Pchar, "potion1", 3);

 			// AddCharacterGoods(pchar, GOOD_SANDAL, 10 );
			// AddCharacterGoods(pchar, GOOD_SILK, 10 );
			// AddCharacterGoods(pchar, GOOD_RUM, 20 );
			// AddCharacterGoods(pchar, GOOD_WHEAT, 20 );

			// AddPartyExp(PChar, 100 );
		break;	// end of case "your_dialog2"

// give grenade to building for selfdefense                
		case "grenade":
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade");
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// add interior
		case "interior":
			Dialog.text = DLG_TEXT[32] + XI_ConvertString("BS"+interiorstr) + DLG_TEXT[33] + XI_ConvertString(buildingstr) + DLG_TEXT[34] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[35] + pchar.money + DLG_TEXT[36] + Pchar.Ship.crew.quantity + DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "exit";
			Link.l5 = DLG_TEXT[39];
			Link.l5.go = "luxurious furniture";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
			Dialog.text = DLG_TEXT[40] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "erect";
		break;

		case "erect":
			aref interiornewref;
			Items_FindItem(npchar.interior,&interiornewref);
			planks = sti(interiornewref.building.planks);
			money = sti(interiornewref.building.money);
			crew = sti(interiornewref.building.crew);

			if(money > sti(pchar.money) || crew > sti(Pchar.Ship.crew.quantity) || planks > GetSquadronGoods(pchar,GOOD_PLANKS) )
			{
				Dialog.text = DLG_TEXT[42] + GetMyAddressForm(NPChar, PChar, ADDR_Polite, false, false) + DLG_TEXT[43] + XI_ConvertString("BS"+npchar.interior) + DLG_TEXT[44] + planks + DLG_TEXT[35] + money + DLG_TEXT[36] +crew+ DLG_TEXT[45] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[35] +pchar.money+ DLG_TEXT[36] +Pchar.Ship.crew.quantity+ DLG_TEXT[46];
				Link.l3 = DLG_TEXT[47];
				Link.l3.go = "exit";
			}
			else
			{
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;

				// take buildingresources
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1);
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(Pchar, -money);
				Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew;
				
				// store new interior
				lcn.building.(nr).interior = npchar.interior;
			}
		break;


// random attacks
		case "attack1":
			Dialog.text = DLG_TEXT[48];
			link.l1 = RandSwear() + DLG_TEXT[49];
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = DLG_TEXT[50];
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("rabBlack_1", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Sailors", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			npchar.tax = taxdays * 2;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = DLG_TEXT[51] + npchar.tax + DLG_TEXT[52] + npchar.tax + DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "wheat";
			link.l2 = DLG_TEXT[55];
			link.l2.go = "tobacco";
			link.l3 = DLG_TEXT[56] + npchar.tax + DLG_TEXT[57];
			link.l3.go = "economy";
		break;

		case "wheat":
			npchar.taxcrop = GOOD_WHEAT;
			Dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "tax2";
		break;

		case "tobacco":
			npchar.taxcrop = GOOD_TOBACCO;
			Dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "tax2";
		break;


		case "tax2":
			Dialog.text = RandSwear() + DLG_TEXT[61] + adress + DLG_TEXT[62] + npchar.tax + DLG_TEXT[63];
			link.l1 = LinkRandPhrase(DLG_TEXT[64], DLG_TEXT[65], DLG_TEXT[66]) + DLG_TEXT[67];
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase(DLG_TEXT[68], DLG_TEXT[69], DLG_TEXT[70]);
			link.l2.go = "taxhalf";
			link.l4 = DLG_TEXT[71];
			link.l4.go = "exit";
			link.l3 = DLG_TEXT[56] + npchar.tax + DLG_TEXT[72];
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[73], DLG_TEXT[74], DLG_TEXT[75]);
			link.l1 = LinkRandPhrase(DLG_TEXT[76], DLG_TEXT[77], DLG_TEXT[78]);
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase(DLG_TEXT[79], DLG_TEXT[80], DLG_TEXT[81]);
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfine"; break;
			}
		break;

		case "taxhalf":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax)/2);
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = DLG_TEXT[82] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
		break;

		case "taxfull":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[85], DLG_TEXT[86], DLG_TEXT[87]);
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text = RandSwear() + DLG_TEXT[89];
			link.l1 = LinkRandPhrase(DLG_TEXT[90], DLG_TEXT[91], DLG_TEXT[92]);
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[93], DLG_TEXT[94], DLG_TEXT[95]);
			link.l1 = LinkRandPhrase(DLG_TEXT[96], DLG_TEXT[97], DLG_TEXT[98]);
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
		break;

		case "taxfine":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[99], DLG_TEXT[100], DLG_TEXT[101]);
			link.l1 = DLG_TEXT[102] + npchar.tax + DLG_TEXT[103];
			link.l1.go = "exit";
		break;

// dismantling of this building
		case "dismantle":
			DialogExit();
			planks += sti(buildingref.building.planks);
			crew += sti(buildingref.building.crew);

			if(CheckAttribute(Npchar,"equip.gun"))
			{
				planks += sti(interiorref.building.planks);
				crew += sti(interiorref.building.crew);
			}
			AddCharacterGoods(pchar, GOOD_PLANKS, planks);
			AddCharacterCrew(pchar, crew);   // ccc mar06
			Lai_KillCharacter(npchar);
		break;

// info about modding                
		case "odd":
			Dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[106];
			link.l2.go = "odd2";
			link.l3 = DLG_TEXT[107];
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = DLG_TEXT[108] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[109];
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = DLG_TEXT[110] + NPchar.dialog.filename + DLG_TEXT[111] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "taxfull";
			link.l2 = DLG_TEXT[115];
			link.l2.go = "taxhalf";
			link.l3 = DLG_TEXT[116];
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(DLG_TEXT[117], DLG_TEXT[118], DLG_TEXT[119]);
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
		break;

// enc_resident stuff: healing, spending time etc. 
		case "chat":
			dialog.text = DLG_TEXT[126];
			Link.l4 = DLG_TEXT[125];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[127];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (GetTime() >= 22.0 || GetTime() < 10.0)
			{
				Link.l1 = DLG_TEXT[128];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = DLG_TEXT[129];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = DLG_TEXT[130];
			Link.l1 = DLG_TEXT[131];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35 || interiorstr=="luxurious furniture") {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = DLG_TEXT[132];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(DLG_TEXT[133], DLG_TEXT[134], DLG_TEXT[135]); 
			int winlink = rand(100) 
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(DLG_TEXT[136], DLG_TEXT[137], DLG_TEXT[138]);
				Link.l1.go = "exit recovered"
			}
			Link.l2 = LinkRandPhrase(DLG_TEXT[139], DLG_TEXT[140], DLG_TEXT[141]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(DLG_TEXT[142], DLG_TEXT[143], DLG_TEXT[144]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(DLG_TEXT[136], DLG_TEXT[137], DLG_TEXT[138]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = DLG_TEXT[145];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\Eng_m_a_013.wav");
			Log_SetStringToLog(TranslateString("","You chat on for hours and learn a lot."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\Eng_m_a_014.wav");
			Log_SetStringToLog(TranslateString("","You chat on for hours and learn a lot."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = DLG_TEXT[146];
			Link.l1 = LinkRandPhrase(DLG_TEXT[147], DLG_TEXT[148], DLG_TEXT[149]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog(TranslateString("","After 24hrs are you fit again, even stronger than before."));
			Log_SetStringToLog(TranslateString("","+ 1 max HP"));
			Log_SetStringToLog(TranslateString("","You have learned a lot about woundtreatment."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
		break;

		case "exit infected":
			Dialog.text = DLG_TEXT[146];
			Link.l1 = LinkRandPhrase(DLG_TEXT[147], DLG_TEXT[148], DLG_TEXT[149]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			if (GetTime() < 22.0 && GetTime() >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog(TranslateString("","You wake up feeling feverish."));
			Log_SetStringToLog(TranslateString("","Your wounds burn like fire!"));
		break;

// dialogexits
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // reward: reputation. Change figure to your liking

			pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}