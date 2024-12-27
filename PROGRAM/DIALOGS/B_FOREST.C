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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = XI_ConvertString("my Squire");}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}

	PlayStereoSound("ambient\shipyard\axe.wav");
	PlayStereoSound("ambient\shipyard\saw.wav");
	
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


				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{

	   			if(taxdays>0)
	   			{
  					link.l5 = DLG_TEXT[12] + taxdays + DLG_TEXT[13];
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
            {Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
					}


					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = DLG_TEXT[14];
					link.l7.go = "grenade";
					}

					link.l8 = DLG_TEXT[15];
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = DLG_TEXT[16];
					link.l9.go = "exit";
				}

				Link.l10 = DLG_TEXT[17];
				Link.l10.go = "exit";

				link.l11 = DLG_TEXT[18] + LinkRandPhrase(DLG_TEXT[19], DLG_TEXT[20], DLG_TEXT[21]);
				link.l11.go = "motion";

				link.l12 = DLG_TEXT[22];
				link.l12.go = "odd";

				link.l13 = DLG_TEXT[23] + NPchar.dialog.filename + DLG_TEXT[24];
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
		break;

		case "your_dialog":
			Dialog.text = DLG_TEXT[25];

			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = DLG_TEXT[27];
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"

		case "your_dialog2":
			Dialog.text = DLG_TEXT[25];

			link.l1 = DLG_TEXT[26];
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
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade");
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// add interior NOT USED FOR FOREST NOW!
		case "interior":
			Dialog.text = DLG_TEXT[30] + XI_ConvertString("BS"+interiorstr) + DLG_TEXT[31] + XI_ConvertString(buildingstr) + DLG_TEXT[32] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[33] + pchar.money + DLG_TEXT[34] + Pchar.Ship.crew.quantity + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "exit";
			Link.l5 = DLG_TEXT[37];
			Link.l5.go = "luxurious furniture";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
			Dialog.text = DLG_TEXT[38] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[39];
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
				Dialog.text = DLG_TEXT[40] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[41] + XI_ConvertString("BS"+npchar.interior) + DLG_TEXT[42] + planks + DLG_TEXT[33] + money + DLG_TEXT[34] +crew+ DLG_TEXT[43] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[33] +pchar.money+ DLG_TEXT[34] +Pchar.Ship.crew.quantity+ DLG_TEXT[44];
				Link.l3 = DLG_TEXT[45];
				Link.l3.go = "exit";
			}
			else
			{
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;

				// take buildingresources
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(Pchar, -money);
				Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew;
				
				// store new interior
				lcn.building.(nr).interior = npchar.interior;
			}
		break;


// random attacks
		case "attack1":
			Dialog.text = DLG_TEXT[46];
			link.l1 = RandSwear() + DLG_TEXT[47];
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = DLG_TEXT[48];
			link.l1 = RandSwear() + DLG_TEXT[49];
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("rabBlack", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Poor_citizens", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			npchar.tax = taxdays * 2;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = DLG_TEXT[50] + npchar.tax + DLG_TEXT[51] + npchar.tax + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "planks";
			link.l2 = DLG_TEXT[54];
			link.l2.go = "ebony";
			link.l3 = DLG_TEXT[55] + npchar.tax + DLG_TEXT[56];
			link.l3.go = "economy";
		break;

		case "planks":
			npchar.taxcrop = GOOD_PLANKS;
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "tax2";
		break;

		case "ebony":
			npchar.taxcrop = GOOD_EBONY;
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
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
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[72], DLG_TEXT[73], DLG_TEXT[74]);
			link.l1 = LinkRandPhrase(DLG_TEXT[75], DLG_TEXT[76], DLG_TEXT[77]);
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase(DLG_TEXT[78], DLG_TEXT[79], DLG_TEXT[80]);
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 2: link.l2.go = "taxrevolt"; break;
			case 3: link.l2.go = "taxsuicide"; break;
			link.l2.go = "taxfine"; break;
			}
		break;

		case "taxhalf":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax)/2);
			ChangeCharacterReputation(Pchar, 1);	// reward: reputation. Change figure to your liking
			Dialog.text = DLG_TEXT[81] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
		break;

		case "taxfull":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);	// punishment: reputationdrop. Change figure to your liking
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[84], DLG_TEXT[85], DLG_TEXT[86]);
			link.l1 = DLG_TEXT[87];
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);	// punishment: reputationdrop. Change figure to your liking
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + DLG_TEXT[88];
			link.l1 = LinkRandPhrase(DLG_TEXT[89], DLG_TEXT[90], DLG_TEXT[91]);
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[92], DLG_TEXT[93], DLG_TEXT[94]);
			link.l1 = LinkRandPhrase(DLG_TEXT[95], DLG_TEXT[96], DLG_TEXT[97]);
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
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[98], DLG_TEXT[99], DLG_TEXT[100]);
			link.l1 = DLG_TEXT[101] + npchar.tax + DLG_TEXT[102];
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
			Dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[105];
			link.l2.go = "odd2";
			link.l3 = DLG_TEXT[106];
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = DLG_TEXT[107] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[108];
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = DLG_TEXT[109] + NPchar.dialog.filename + DLG_TEXT[110] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "taxfull";
			link.l2 = DLG_TEXT[114];
			link.l2.go = "taxhalf";
			link.l3 = DLG_TEXT[115];
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(DLG_TEXT[116], DLG_TEXT[117], DLG_TEXT[118]);
			link.l1 = DLG_TEXT[119];
			link.l1.go = "exit";
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