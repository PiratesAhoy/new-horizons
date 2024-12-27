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

	string adress, sound1, sound2;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = XI_ConvertString("my landlord");}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}
	
	// determine production based on interiortype
	tax = taxdays * 1;	// Reward, output of goods, you can change the figure before the ';' to your liking
	string prodstr = DLG_TEXT[0];
	int prodgood = -1;
	string prodname = "nothing";
	sound1 = "ambient\shipyard\hammer.wav";
	sound2 = "ambient\town\vehicle.wav";

	switch(interiorstr)
	{
		case "foundry":
		sound1 = "ambient\sea\squeak3.wav";
		sound2 = "objects\shipcharge\ship_onfire.wav";
		prodgood = GOOD_BALLS;
		tax = tax * 100;  // reward: change figure to change production of BALLS ONLY
		prodname = DLG_TEXT[1];
		prodstr = DLG_TEXT[2];
		break;

		case "dock":
		sound1 = "ambient\shipyard\hammer.wav";
		sound2 = "ambient\sea\sails2.wav";
		prodgood = GOOD_SAILCLOTH;
		tax = tax*3;  // reward: change figure to change production of SAILCLOTH ONLY
		prodname = DLG_TEXT[3];
		prodstr = DLG_TEXT[4];
		break;

		case "mine":
		sound1 = "nature\windmill.wav";
		prodname = DLG_TEXT[5];
		prodstr = DLG_TEXT[6];
		break;

		case "distillery":
		sound1 = "ambient\tavern\tinkle1.wav";
		prodgood = GOOD_RUM;
		tax = tax*2;  // reward: change figure to change production of RUM ONLY
		prodname = DLG_TEXT[7];
		prodstr = DLG_TEXT[8];
		break;

	}
	PlayStereoSound(sound1);
	PlayStereoSound(sound2);
	
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

		  if(bDisableFastReload || objLandInterface.data.riskAlarm==1)
		  {
			  Dialog.text = DLG_TEXT[9];
			  link.l1 = DLG_TEXT[10];
			  link.l1.go = "exit";
		  }
		  else
		  {
			if(rand(100)<15) // chance for random attack, decrease last figure for fewer attacks
			{
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight
				PlayStereoSound("voice\Eng_m_a_070.wav");
				Dialog.text = LinkRandPhrase(DLG_TEXT[11], DLG_TEXT[12], DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + DLG_TEXT[14]);
				link.l1 = DLG_TEXT[15];
				if(rand(100)>70) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = DLG_TEXT[16];
				link.l9.go = "exit";
			}
			else
			{
				Dialog.text = DLG_TEXT[17] + adress + DLG_TEXT[18] + prodstr;

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(interiorstr == "dock")
					{
						link.l14 = DLG_TEXT[19];
						link.l14.go = "repairfree";
					}
					if(taxdays>0 && interiorstr == "mine")
					{
						link.l14 = DLG_TEXT[20];
						link.l14.go = "taxmine";
					}

					if(taxdays>0 && prodname != "nothing" && interiorstr != "mine")
					{
						link.l5 = DLG_TEXT[21] + XI_ConvertString("BS"+interiorstr) + DLG_TEXT[22] + taxdays + DLG_TEXT[23];
						if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
						{Link.l5.go = "tax";}
						else{Link.l5.go = "taxevasion";}
					}

					link.l6 = DLG_TEXT[24] + XI_ConvertString(buildingstr) + DLG_TEXT[25];
					link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
						link.l7 = DLG_TEXT[26];
						link.l7.go = "grenade";
					}

					link.l8 = DLG_TEXT[27];
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					if(lcn.id == "Oxbay_port")
					{
						link.l114 = DLG_TEXT[28];
						link.l114.go = "explain";
					}
					link.l9 = DLG_TEXT[29];
					link.l9.go = "exit";
				}

				Link.l10 = DLG_TEXT[30];
				Link.l10.go = "exit";

				link.l11 = DLG_TEXT[31] + LinkRandPhrase(DLG_TEXT[32], DLG_TEXT[33], DLG_TEXT[34]);
				link.l11.go = "motion";

				link.l12 = DLG_TEXT[35];
				link.l12.go = "odd";

				link.l13 = DLG_TEXT[36] + NPchar.dialog.filename + DLG_TEXT[37];
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
		  }
		break;
                
		case "your_dialog":
			Dialog.text = DLG_TEXT[38];

			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = DLG_TEXT[40];
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = DLG_TEXT[38];

			link.l1 = DLG_TEXT[39];
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
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade");
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// add interior
		case "interior":
			Dialog.text = DLG_TEXT[43] + XI_ConvertString("BS"+interiorstr) + DLG_TEXT[44] + XI_ConvertString(buildingstr) + DLG_TEXT[45] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[46] + pchar.money + DLG_TEXT[47] + Pchar.Ship.crew.quantity + DLG_TEXT[48];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[50];
			Link.l2.go = "mine";
			Link.l21 = DLG_TEXT[51];
			Link.l21.go = "foundry";
			Link.l22 = DLG_TEXT[52];
			Link.l22.go = "distillery";
			Link.l23 = DLG_TEXT[53];
			Link.l23.go = "dock";
		break;

		case "mine":
			npchar.interior = "mine";
			Dialog.text = DLG_TEXT[54] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "erect";
		break;

		case "foundry":
			npchar.interior = "foundry";
			Dialog.text = DLG_TEXT[54] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "erect";
		break;

		case "distillery":
			npchar.interior = "distillery";
			Dialog.text = DLG_TEXT[54] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "erect";
		break;

		case "dock":
			npchar.interior = "dock";
			Dialog.text = DLG_TEXT[54] + XI_ConvertString("BS"+npchar.interior) + "?";
			Link.l2 = DLG_TEXT[55];
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
				Dialog.text = DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[57] + XI_ConvertString("BS"+npchar.interior) + DLG_TEXT[58] + planks + DLG_TEXT[46] + money + DLG_TEXT[47] +crew+ DLG_TEXT[59] + GetSquadronGoods(pchar,GOOD_PLANKS) + DLG_TEXT[46] +pchar.money+ DLG_TEXT[47] +Pchar.Ship.crew.quantity+ DLG_TEXT[60];
				Link.l3 = DLG_TEXT[61];
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
			Dialog.text = DLG_TEXT[62];
			link.l1 = RandSwear() + DLG_TEXT[63];
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = DLG_TEXT[64];
			link.l1 = RandSwear() + DLG_TEXT[65];
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Lower_Citizens", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards

		case "taxmine":
  			lcn.building.(nr).taxyear = GetDataYear();
  			lcn.building.(nr).taxMonth = GetDataMonth();
  			lcn.building.(nr).taxDay = GetDataDay();

				if(rand(100)<15) // punishment, chance for no jewels, decrease last figure for more success
				{	
					Dialog.text = DLG_TEXT[66] + adress + DLG_TEXT[67];
					link.l1 = RandSwear() + DLG_TEXT[68];
					link.l1.go = "exit";
				}
				else
				{
					if(rand(100)>50) {GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(3)) );}
					else{GiveItem2Character(PChar, "mineral"+ makeint(1 + rand(2)) );}

					Dialog.text = DLG_TEXT[69];
					link.l1 = DLG_TEXT[70];
					link.l1.go = "exit";
				}
		break;

		case "tax":
			npchar.tax = tax * 1;	// Reward goods, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = DLG_TEXT[71] + npchar.tax + " " + prodname + DLG_TEXT[72];
			link.l1 = LinkRandPhrase(DLG_TEXT[73], DLG_TEXT[74], DLG_TEXT[75]) + DLG_TEXT[76];
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase(DLG_TEXT[77], DLG_TEXT[78], DLG_TEXT[79]);
			link.l2.go = "taxhalf";
			link.l4 = DLG_TEXT[80];
			link.l4.go = "exit";
			link.l3 = DLG_TEXT[81] + npchar.tax + DLG_TEXT[82];
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking
			npchar.tax = tax * 1;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[83], DLG_TEXT[84], DLG_TEXT[85]);
			link.l1 = LinkRandPhrase(DLG_TEXT[86], DLG_TEXT[87], DLG_TEXT[88]);
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase(DLG_TEXT[89], DLG_TEXT[90], DLG_TEXT[91]);
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxforced"; break;
			}
		break;

		case "taxhalf":
      // next 3 lines reset taxdays to 0
      lcn.building.(nr).taxyear = GetDataYear();
      lcn.building.(nr).taxMonth = GetDataMonth();
      lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, prodgood, sti(npchar.tax)/2);
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = DLG_TEXT[92] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
		break;

		case "taxfull":
      // next 3 lines reset taxdays to 0
      lcn.building.(nr).taxyear = GetDataYear();
      lcn.building.(nr).taxMonth = GetDataMonth();
      lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, prodgood, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[95], DLG_TEXT[96], DLG_TEXT[97]);
			link.l1 = DLG_TEXT[98];
			link.l1.go = "exit";
		break;

		case "taxforced":
      // next 3 lines reset taxdays to 0
      lcn.building.(nr).taxyear = GetDataYear();
      lcn.building.(nr).taxMonth = GetDataMonth();
      lcn.building.(nr).taxDay = GetDataDay();
			tax = taxdays * 10;	// Reward rentmoney, you can change the figure before the ';' to your liking
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(Pchar, tax);
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[99], DLG_TEXT[100], DLG_TEXT[101]);
			link.l1 = DLG_TEXT[102] + tax + DLG_TEXT[103];
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			// next 3 lines reset taxdays to 0
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			tax = taxdays * 10;	// Reward rentmoney, you can change the figure before the ';' to your liking
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(Pchar, tax);
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("Lower_Citizens", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text = RandSwear() + DLG_TEXT[104];
			link.l1 = RandSwear() + DLG_TEXT[105];
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			// next 3 lines reset taxdays to 0
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[106], DLG_TEXT[107], DLG_TEXT[108]);
			link.l1 = LinkRandPhrase(DLG_TEXT[109], DLG_TEXT[110], DLG_TEXT[111]);
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 20);
			Lai_KillCharacter(NPchar);
		break;

// shiprepair
		case "repairfree":
		  if(taxdays>0)  
		  {
  			Dialog.text = DLG_TEXT[112];
  			link.l1 = DLG_TEXT[113];
  			link.l1.go = "repairfreeall";
  			link.l2 = DLG_TEXT[114];
  			link.l2.go = "repairfreerig";
  			link.l3 = DLG_TEXT[115];
  			link.l3.go = "exit";
			}
			else
		  {
  			Dialog.text = DLG_TEXT[116];
  			link.l1 = DLG_TEXT[117];
  			link.l1.go = "exit";
			}
		break;

		case "repairfreeall":
      WaitDate("", 0,0, 2,0,0);
		  PlaySound("ambient\shipyard\axe.wav");
		  PlaySound("ambient\shipyard\vehicle.wav"); 
		
		  if(rand(100)<50) // punishment, chance for major damage, decrease last figure for less disasters 
		  {
  			LAi_Fade("", "");
  			WaitDate("", 0,0,2,0,0);
  			RecalculateJumpTable();
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");

			pchar.ship.hp = GetCharacterShipHP(pchar) * (30+rand(20))/100; // 'repairs' hull to 30-50 %
		
    		pchar.ship.sp = GetCharacterShipSP(pchar);
    		DeleteAttribute(pchar,"ship.sails");
    		DeleteAttribute(pchar,"ship.masts");

  			lcn.building.(nr).taxyear = GetDataYear();
  			lcn.building.(nr).taxMonth = GetDataMonth();
  			lcn.building.(nr).taxDay = GetDataDay();
		    
			Dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[118], DLG_TEXT[119], DLG_TEXT[120]) + DLG_TEXT[121];
  			link.l2 = RandSwear() + DLG_TEXT[122];
  			link.l2.go = "exit";
			}
			else
			{
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;

  			LAi_Fade("", "");
  			WaitDate("", 0,0,2,0,0);
  			RecalculateJumpTable();
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");

  			lcn.building.(nr).taxyear = GetDataYear();
  			lcn.building.(nr).taxMonth = GetDataMonth();
  			lcn.building.(nr).taxDay = GetDataDay();

			pchar.ship.hp = GetCharacterShipHP(pchar) * (80+rand(20))/100; // reward, repairs hull to 80-100 %, delete '* (80+rand(20))/100' for always 100%
		
    		pchar.ship.sp = GetCharacterShipSP(pchar);
    		DeleteAttribute(pchar,"ship.sails");
    		DeleteAttribute(pchar,"ship.masts");
     		Logit(TranslateString("","Two days later most damage has been repaired."));
			}
		break;

		case "repairfreerig":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_Fade("", "");
			WaitDate("", 0,0,2,0,0);
			RecalculateJumpTable();
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav"); 

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
		
  			pchar.ship.sp = GetCharacterShipSP(pchar);
  			DeleteAttribute(pchar,"ship.sails");
  			DeleteAttribute(pchar,"ship.masts");
  			Logit(TranslateString("","Two days later your sails and rig are almost as new."));
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
			Dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[125];
			link.l2.go = "odd2";
			link.l3 = DLG_TEXT[126];
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = DLG_TEXT[127] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[128];
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = DLG_TEXT[129] + NPchar.dialog.filename + DLG_TEXT[130] + "'" +PA_INET+ "'.";
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "taxfull";
			link.l2 = DLG_TEXT[134];
			link.l2.go = "taxhalf";
			link.l3 = DLG_TEXT[135];
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(DLG_TEXT[136], DLG_TEXT[137], DLG_TEXT[138]);
			link.l1 = DLG_TEXT[139];
			link.l1.go = "exit";
		break;

		case "explain":
			Dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "explain2";
		break;

		case "explain2":
			Dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[144];
			link.l2.go = "explain3";
		break;

		case "explain3":  // PB: Buildings will disappear after leaving Oxbay, done in quests_common.c
			Dialog.text = RandSwear() + DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "Exit";
			pchar.quest.oxbay_port_earthquake.win_condition.l1 = "MapEnter";
			pchar.quest.oxbay_port_earthquake.win_condition = "oxbay_port_earthquake"; // PB: Add building removal option to ALL storylines
		break;

// dialogexits
		case "moraledrop":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
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