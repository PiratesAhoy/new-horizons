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

			if(rand(100)<30) // chance for random attack, decrease last figure for fewer attacks
			{
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				Dialog.text = adress + LinkRandPhrase(" hostile forces sighted. Form up for defence.", " enemy movements in our sector! Beat to quarters!", "Suspicious movements at our perimeter, man battlestations!");

				link.l1 = "A detailed report, Marine, NOW.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Leave me alone with that, that's YOUR job! After all that's what I hired you for: as cannonfodd.. er.. cannonfeeder. I have no time anyway: must hurry back to my safe white house, don my bomberjacket and deliver some toughsounding quips to the electorate..";
				link.l9.go = "exit";
			}
			else
			{
				PlayStereoSound("objects\duel\reload2.wav");
	      		PlayStereoSound("voice\ENGLISH\Eng_m_c_044.wav");
				Dialog.text =  "Report " + buildingstr + " manned and ready for battle ," + adress + " all quiet in this sector.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "We withdraw from this position. Dismantle this " + buildingstr + ", load the planks into our hold and report to the Sergeant of my Marines for shipduties.";
					link.l1.go = "dismantle";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l21 = "This fortification would look much more formidable with a cannon. Not to mention the increase in firepower. Here, Marine, take these 5000 gold and obtain a gun for your position.";
					link.l21.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l22 = "Marine, I have a special task for you: Here, take this grenade, and if the enemy should break trough and storm this position...";
					link.l22.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Just passing by... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Very good, Marine, carry on.";
				Link.l4.go = "exit";

				link.l6 = "Soldier, isn't this fortification too low and too weak to stop an assault?";
				link.l6.go = "odd";

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

		case "cannon":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "Yes, Sir, I know the mastersergeant of the local magazine quite well. For 5000 Gold he'd sell his whole ordinance. Just give me a few hours." ;
			link.l1 = "That's the spirit, Marine! With your understanding of logistics you'll soon become corporal. (..if you live that long..)";
			link.l1.go = "exit";
		break;


// random attacks
		case "attack1":
			Dialog.text = "Savage Akellani cannibals approaching, Sir! Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + " Attention, soldier! Hold this position whatever happens. Keep up firing, don't let the enemy draw you into close combat. I will take care of the bladework...";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "Francisco Pizarro the Younger and his horde of maurading conquistadores approaching, Sir! Lusting for blood, plunder and rape... Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + " Attention, soldier! Hold this position whatever happens. Keep up firing, don't let the enemy draw you into close combat. I will take care of the bladework...";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Soldier_Spa2_15",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
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
			if(buildingstr == "bastion")
			{
				Dialog.text = "Too low? Sounds like you have the same oldfashioned views on military architecture like those Russian stonemasons who build all those medievil townwalls and skyscraper forts around here. But the invention of gunpowder has made high crenellated walls obsolete. The low profile of this bastion offers siege artillery less of a target. Never mind that enemy infantry may be able to scale low embrasures, as long as our artillery continues to fire they won't live long." ;
			} else {
				Dialog.text = "Umm, well, all decent wood goes into the shipyards, so we had to build this stockade from brittle trunks and driftwood. True, there are gaps wide enough that an enemy can squeeze trough. But as long as our artillery continues to fire they won't live long afterwards.";
			}
			link.l2 = "So artillery is the key to everything? How can I deploy my cannons in the best way?";
			link.l2.go = "odd2";
		break;

		case "odd2":
			Dialog.text = "Group several fortifications with cannon together so that they can support each other, but not so close that they all come under attack at the same time. In the front line a strong bastion that takes the brunt of the attack, and behind that cheaper stockades which can fire at the attackers occupied with the bastion. But be careful that none of your men gets into the line of fire. At long range our shells kill everyone near the target. Keep out of the fight completely or stay close to the guns where our aim is better." ;
			link.l1 = "Ummm, I'm not sure if I can afford that... But thanks for the lecture on 17th century fortifications.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Sir, we always stand to attention in a superiors presence. That's the drill, and the drill is everything.", "I have my eye on a suspicious target, and I don't want too loose it. 'Keep your aim, never flinch, never blink' our drillseargeant used to say.", "First rule of camouflage: movement attracts attention. So never move if you don't have to.");
			link.l1 = "Allright, I understand... Carry on.";
			link.l1.go = "exit";
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
