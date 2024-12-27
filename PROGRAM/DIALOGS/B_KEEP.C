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

	string interiorstr = "";
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = XI_ConvertString("Commander");}else{adress = "";}

	PlayStereoSound("ambient\jail\chains.wav");
	PlayStereoSound("ambient\cave\drop5.wav");
	
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

			if(rand(100)<10) // chance for random attack, decrease last figure for fewer attacks
			{
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight	
				Dialog.text = adress + LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]);

				link.l1 = DLG_TEXT[3];
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = DLG_TEXT[4];
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text = DLG_TEXT[5] + XI_ConvertString(buildingstr) + DLG_TEXT[6] + adress + DLG_TEXT[7];

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = DLG_TEXT[8] + XI_ConvertString(buildingstr) + DLG_TEXT[9];
					link.l1.go = "dismantle";

					link.l21 = DLG_TEXT[10];
					link.l21.go = "items";
					link.l22 = DLG_TEXT[11];
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = DLG_TEXT[12];	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = DLG_TEXT[13];
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = DLG_TEXT[14];
					link.l1.go = "exit";
				}

				Link.l4 = DLG_TEXT[15];
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "Who the hell designed this maze of masonry? Can't take a step here without smashing my head into some vault or pillar..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = DLG_TEXT[16] + LinkRandPhrase(DLG_TEXT[17], DLG_TEXT[18], DLG_TEXT[19]);
				link.l5.go = "motion";

				link.l9 = DLG_TEXT[20] + NPchar.dialog.filename + DLG_TEXT[21];
				link.l9.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l9. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = DLG_TEXT[22];

			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = DLG_TEXT[24];
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = DLG_TEXT[22];

			link.l1 = DLG_TEXT[23];
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
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade");
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// give cannon to building for selfdefense                
		case "cannon":
			Dialog.text = DLG_TEXT[27] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[28];	// ccc feb06
			link.l1 = DLG_TEXT[29];	// ccc feb06
			link.l1.go = "exit";

			link.l2 = DLG_TEXT[30];
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = DLG_TEXT[31] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
		break;

// load itemkeeper                
		case "items":
		  if(taxdays>0 && rand(100)<120) // chance for random jewel, increase last figure for more jewels	  
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase(DLG_TEXT[34], DLG_TEXT[35], DLG_TEXT[36]) + DLG_TEXT[37];
  			link.l1 = DLG_TEXT[38];
  			link.l1.go = "reward";
  			link.l2 = DLG_TEXT[39];
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = DLG_TEXT[40] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[41];
  			link.l1 = DLG_TEXT[42];
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry" + makeint(1 + rand(15)) );
		  if(rand(100)<20) // chance of poisoning, decrease last figure for	less poisoning	  
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit(TranslateString("","PlaguevictimsGrave"));
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
  			Dialog.text = DLG_TEXT[40] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[43];
  			link.l1 = DLG_TEXT[44];
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // reward: reputation. Change figure to your liking
			Dialog.text = DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "items";
		break;

		case "items2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ref chr = characterFromID("B_keeper");
			string locator = LAi_FindRandomLocator("reload");
			float x,y,z;
	  	   	ChangeCharacterAddressGroup(chr, pchar.location, "reload", locator);
  			GetCharacterPos(pchar, &x, &y, &z);
  			x = x+1;
  			TeleportCharacterToPos(chr, x, y, z);
  			Lai_SetActorType(chr);
  			LAi_ActorTurnToCharacter(chr, pchar);
  			LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;

// random attacks
		case "attack1":
			Dialog.text = DLG_TEXT[48] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[49];
			link.l1 = RandSwear() + DLG_TEXT[50];
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = DLG_TEXT[51] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[52];
			link.l1 = RandSwear() + DLG_TEXT[50];
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("native", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Soldier_Spa2", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
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
			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(DLG_TEXT[55], DLG_TEXT[56], DLG_TEXT[57]);
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
		break;

// dialogexits
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}