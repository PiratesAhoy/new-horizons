// ccc Buildingset, new file	
/*
ccc Dec06:
Unlike most other files in this folder this one contains not only a textarray but code and English text merged.

The buildingset has recently been messed up by the attempt to localize my original all-English dialogfiles. 
Instead of spending weeks with fixing and testing the new files I restored my original files. 
However, the localization project has changed the structure of PotC for good : 
Upon loading a  "x-dialog.c" codefile the program now automatically includes a  "x-dialog.h" text array file from the dialogs\english subfolder(or from the Russian folder if you use that language). 
There the dialogtext is supposed to be.

However, I prefer to have code AND plain text in one file, for 3 reasons:
-It is much easier to write
-You have much less bugs with not matching texts
-It is much easier to read and understand the file for debuggers and people who would like to change it
The last point is especially important for me cause the Buildingset is supposed to be a tool for people who want to start modding.
That's why I stick to the original "code plus English text" dialogfiles.

As a concession to the localization project I put these files NOT into the \dialogs rootfolder but into the \dialogs\English subfolder.
So if you want to translate this dialog you can simply copy the "code plus English text" into the subfolder for your language and translate the English text there.
That will certainly be less work and trouble than messing up my files again. 
Not mention the work and trouble that the debuging always causes.
*/
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " Commander, Sir, ";}else{adress = "";}

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
				Dialog.text = adress + LinkRandPhrase(" hostile forces sighted. Form up for defence.", " enemy movements in our sector! Beat to quarters!", "Suspicious movements at our perimeter, man battlestations!");

				link.l1 = "A detailed report, Marine, NOW.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Leave me alone with that, that's YOUR job! After all that's what I hired you for: as cannonfodd.. er.. cannonfeeder. I have no time anyway: must hurry back to my safe white house, don my bomberjacket and deliver some toughsounding quips to the electorate..";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  "Report " + buildingstr + " manned and ready for battle ," + adress + " all quiet in this sector.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "We withdraw from this position. Tear down this " + buildingstr + ", load the planks into our hold and report to the Sergeant of my Marines for shipduties.";
					link.l1.go = "dismantle";

					link.l21 = "I need a safe place to store some of my treasure and equipment, and this olde keep looks like a VERY safe place. Can you keep some stuff for me here?";
					link.l21.go = "items";
					link.l22 = "I'd like to have a word about my possessions with that Ole Creeper fellow.";
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = "I wonder if it makes sense to position a gun here.";	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = "Marine, I have a special task for you: Here, take this grenade, and if the enemy should break trough and storm this position...";
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Just passing by... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Very good, Marine, carry on.";
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "Who the hell designed this maze of masonry? Can't take a step here without smashing my head into some vault or pillar..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = "Hey, why do stand here so motionless? " + LinkRandPhrase("Have you swallowed a broomstick...", "Come on, relax a little... AT EASE!", "I expect a bit more activity from my marines, ya hear me?");
				link.l5.go = "motion";

				link.l9 = "Hey, you there in front of the keyboard! This is a building that YOU created, so how about creating your own dialog as well? Just use Notepad to open the file program\dialogs\ " + NPchar.dialog.filename + " and overwrite this text with your own. Then follow the instructions in the comments.";
				link.l9.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l9. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = "Overwrite this with the dialogtext of the NPC." ;

			link.l1 = "Text of the player dialogoption link.l1 which ends the dialog ";
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = "Text of the player dialogoption link.l2 which leads to another exchange ";
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = "Overwrite this with the dialogtext of the NPC." ;

			link.l1 = "Text of the player dialogoption link.l1 which ends the dialog";
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
			Dialog.text = "...I'll blast them to kingdom come. I know my duty, Commander!" ;
			link.l1 = "That's the spirit, Marine! With your sense of duty you'll soon become corporal. (..if you live that long..)";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// give cannon to building for selfdefense                
		case "cannon":
			Dialog.text = "Absolutely, Sir! A cannon down here covering the entrance could blast any intruder to kingdom come." ;	// ccc feb06
			link.l1 = "Maybe, but I don't want to spend even more money here.";	// ccc feb06
			link.l1.go = "exit";

			link.l2 = "Here are 5000 Gold, can you.. err.. obtain a proper gun with that?";
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "Yes, Sir, I know the mastersergeant of the local magazine quite well. For 5000 Gold he'd sell his whole ordinance. Just give me a few hours." ;
			link.l1 = "That's the spirit, Marine! With your understanding of logistics you'll soon become corporal. (..if you live that long..)";
			link.l1.go = "exit";
		break;

// load itemkeeper                
		case "items":
		  if(taxdays>0 && rand(100)<120) // chance for random jewel, increase last figure for	more jewels	  
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase("Ah, speaking of valuables, that reminds me that I found a piece of jewelry in the old catacombs below this keep. I was pis.. err.. patroling down there when I noticed a fresh crevice in one of the walls. Behind that I found an old burial chamber, and amongst some old bones there was this little gem blinking at me, as if inviting me to take it. But on second thought I realized that ", "By the way, I have an addition to your possessions: this piece of jewelry. Found it yesterday when clearing away some debris from a recently collapsed wall. Among the stones there was a broken urn, ashes, bonesplinters, teeth.. AND this beautiful gem. Of course ", "Before you deal with your inventory you can add this piece of jewelry to it. Yesterday I was clearing the burialchamber in the keep's former chapel -to make room there for ru.. err.. ammunition storage- when this shining object fell out of a heap of bones I was carrying. Right into my lap, like a gift from heaven. Or Hades rather. By rights ")  + "it belongs to you as you are now the owner of this estate. So I'd rather hand it over to you lest the curse of it's dead owner falls on me." ;
  			link.l1 = "(Curse of it's dead owner? Yikes!) Oh no, keep it for yourself. After all you deserve a reward for your honesty and loyalty, Marine! With your sense of honesty you'll soon become corporal. (..if you live that long..)";
  			link.l1.go = "reward";
  			link.l2 = "Curse? Superstitious rubbish! You want to scare me into leaving you that gem, eh? Not with me, hand it over to your commander. NOW! ";
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = "Aye, Sir, I'll call the Keeper of this Donjon. By the way, his ways are a bit a bit oldfash.. err.. traditional, has been living in this ancient Tower too long, if you ask me. But exactly that traditional attitude makes him a most reliable Keeper for your treasure. You can give him anything for safekeeping and be sure that he will give it back to you whenever you want it." ;
  			link.l1 = "I hope so. Now where is that medievil factotum?";
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(15)) );
		  if(rand(100)<20) // chance of poisoning, decrease last figure for	less poisoning	  
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit("Curse? A plaguevictims grave? Whatever, you suddenly feel terribly sick!");
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
  			Dialog.text = "Aye, Sir, your wish is my command. By the way, what about a little.. err.. reward? Wouldn't it be good for your troops' morale if honest loyal soldiers were rewarded?" ;
  			link.l1 = "Insolent bastard! Veiled demands? How dare you! Enough of that, I want to deal with my treasues. NOW!";
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // reward: reputation. Change figure to your liking
			Dialog.text = "That's most generous of you, Sir. I'll tell everybody what a kind and caring commander you are, you can be sure of that!";
			link.l1 = "Oh, don't bother, I'm not so keen on my reputation. By the way, I grant you leave tonight. Why don't you go downtown, mingle with the townfolk, chat a lot... And now back to MY treasure, if you please.";
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
			Dialog.text = "Savage Akellani cannibals approaching, Sir! Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + " Attention, soldier! Hold this position whatever happens. Keep up firing, don't let the enemy draw you into close combat. I will take care of the bladework...",
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "Francisco Pizarro the Younger and his horde of maurading conquistadores approaching, Sir! Lusting for blood, plunder and rape... Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + " Attention, soldier! Hold this position whatever happens. Keep up firing, don't let the enemy draw you into close combat. I will take care of the bladework...",
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
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
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
			Dialog.text = "Well, true, the design of this tower is antiquated. The Pentagonal Keep was invented during Norman times, when scaling and simple siege machines were the main threat for a fortification. The massive vaults were designed to withstand battering rams and undermining, so the lower storeys here are almost completely filled with masonry and offer no space for accomodation. The invention of gunpowder has made this architecture obsolete. Nowadays these towers are often used as prison or for storing valuables, cause that's what they were designed for in the first place: keeping people from getting in. Or out." ;
			link.l1 = "Ummm, in that regard it's a very successful design: I find it very difficult to get in or out without smashing into some wall.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Sir, we always stand to attention in a superiors presence. That's the drill, and the drill is everything.", "I have my eye on a suspicious target, and I don't want too loose it. 'Keep your aim, never flinch, never blink' our drillseargeant used to say.", "First rule of camouflage: movement attracts attention. So never move if you don't have to.");
			link.l1 = "Allright, I understand... Carry on.";
			link.l1.go = "exit";
		break;


// dialogexits

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
