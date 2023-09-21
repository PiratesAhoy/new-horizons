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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " Boss ";}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}
	
	// determine production based on interiortype
	tax = taxdays * 1;	// Reward, output of goods, you can change the figure before the ';' to your liking
	string prodstr = " trying to turn this shabby little shack into a proper workshop. But without the proper equipment I'll never be able to manufacture something of worth or use."
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
		prodname = "cannonballs";
		prodstr = " casting cannonballs. Rather hot work, and dangerous as well with that blastfurnace being cobbled together from scrap parts.";
		break;

		case "dock":
		sound1 = "ambient\shipyard\hammer.wav";
		sound2 = "ambient\sea\sails2.wav";
		prodgood = GOOD_SAILCLOTH;
		tax = tax*3;  // reward: change figure to change production of SAILCLOTH ONLY
		prodname = " bales of sparesails";
		prodstr = " stitching sails and careening fishing boats.";
		break;

		case "mine":
		sound1 = "nature\windmill.wav";
		prodname = " tons of worthless sand";
		prodstr = " digging for precious stones and minerals. Very frustrating work sometimes, you can never predict what you'll find. IF we find something at all. Often we dig for weeks without success. And that mineshaft winding tower always causes trouble: the derrick is made of brittle driftwood which often cracks, and as you can see the winding rope has been ripped off.. AGAIN! That we can produce something of value now and then under such miserable working conditions is a miracle. ";
		break;

		case "distillery":
		sound1 = "ambient\tavern\tinkle1.wav";
		prodgood = GOOD_RUM;
		tax = tax*2;  // reward: change figure to change production of RUM ONLY
		prodname = "casks of rum";
		prodstr = " distilling rum. The finest and strongest in the whole Caribbean, burns like fire.. in the throat as well as in a lantern. And sometimes the whole distillery burns down as well cause the spirit's leaking out of the scrapyard tubes into the fire.. ";
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
			  Dialog.text = "Looks like You are busy? Finish your business first.";
			  link.l1 = "Certainly, I'll come soon.";
			  link.l1.go = "exit";
		  }
		  else
		  {
			if(rand(100)<15) // chance for random attack, decrease last figure for fewer attacks
			{
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight
				PlayStereoSound("voice\ENGLISH\Eng_m_a_070.wav");	
				Dialog.text =  LinkRandPhrase("Thanks to God that you came along! You can defend us against those brutes..", "Ahh, heaven sent you at a most crucial moment: we are about to come under attack. HELP US!", "Well met, I say, we desperately need a fighting " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " like you to ward off that raid...");
				link.l1 = "Hey, calm down! My, my, you are already stiff from fear... Now tell me what's going on here.";
				if(rand(100)>70) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Now, now, don't raise such a fuss because of some labour unrest. Use your tools to defend yourself, will you? I am busy managing the administration of this operation, and that task leaves me no time for union brawls!";
				link.l9.go = "exit";
			}
			else
			{
				Dialog.text =  "What? Oh, you.. Sorry, " + adress + ", I don't have much time for you. I am very busy" + prodstr;

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(interiorstr == "dock")
					{
						link.l14 = "Can you repair my ship?";
						link.l14.go = "repairfree";
					}
					if(taxdays>0 && interiorstr == "mine")
					{
						link.l14 = "How is the mining? Found anything of value lately?";
						link.l14.go = "taxmine";
					}

					if(taxdays>0 && prodname != "nothing" && interiorstr != "mine")
					{
						link.l5 = "Great to see that you are busily producing goods... for me. After all that's why I build this " + interiorstr + " for. So what have you achieved in the " + taxdays + " days since my last call?";
						if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
						{Link.l5.go = "tax";}
						else{Link.l5.go = "taxevasion";}
					}

					link.l6 = "Hmm, I wonder if this " + buildingstr + " can be improved.";
					link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
						link.l7 = "Listen, a lot of scoundrels scourge these islands, raiders that enjoy plunder, torture and rape. Maybe they come here, and in that case you need some last resort. Here, take this grenade...";
						link.l7.go = "grenade";
					}

					link.l8 = "I have no use for this construction anymore. Dismantle it, load the planks into our hold and report to the boatswain for shipduties.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					if(lcn.id == "Oxbay_port")
					{
						link.l114 = "What the hell happened to this beautiful location? Who spoiled the view by squeezing all these odd buildings into the port?";
						link.l114.go = "explain";
					}
					link.l9 = "Just passing by... ";
					link.l9.go = "exit";
				}

				Link.l10 = "Then I won't keep you from your work any longer. Goodbye.";
				Link.l10.go = "exit";

				link.l11 = "Hey, why do stand here so motionless? " + LinkRandPhrase("Have you swallowed a broomstick...", "Come on, relax a little...", "I expect a bit more activity from the inhabitants of my settlement, ya hear me?");
				link.l11.go = "motion";

				link.l12 = "Umm, excuse me, I don't want to be petty, but this 'building' looks a bit odd to me...";
				link.l12.go = "odd";

				link.l13 = "Hey, you there in front of the keyboard! This is a building that YOU created, so how about creating your own dialog as well? Just use Notepad to open the file program\dialogs\ " + NPchar.dialog.filename + " and overwrite this text with your own. Then follow the instructions in the comments.";
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
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
			Dialog.text = "...and if any scum dares to enter my.. err.. your estate, Squire, I'll blast them to kingdom come." ;
			link.l1 = "That's the spirit! Great to have such loyal subjects. But be careful who you blow up..";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// add interior
		case "interior":
			Dialog.text = "Oh, yes, we could replace the "+interiorstr+" we currently have in here if you want to give this " + buildingstr + " a new function. You just have to give us some of your "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" plankunits, "+ pchar.money +" gold and "+ Pchar.Ship.crew.quantity +" sailors. What are you thinking of?";
			Link.l1 = "Umm, I don'think I should invest even more here.";
			Link.l1.go = "exit";
			Link.l2 = "A mineshaft winding tower (turns a workshop into a jewelmine; 10 planks, 4000 G, 5Crw)";
			Link.l2.go = "mine";
			Link.l21 = "A cannonball foundry (turns a workshop into a foundry; 10 planks, 4000 G, 5Crw)";
			Link.l21.go = "foundry";
			Link.l22 = "A rum distillery (turns a workshop into a distillery; 10 planks, 4000 G, 5Crw)";
			Link.l22.go = "distillery";
			Link.l23 = "A careenage (turns a workshop into shipyard; 10 planks, 4000 G, 5Crw)";
			Link.l23.go = "dock";
		break;

		case "mine":
			npchar.interior = "mine";
			Dialog.text = "A " + npchar.interior + " ?";
			Link.l2 = "Right. My clerk will assign the necessary resources to you, and I expect that you finish the work till my next visit. See ya!";
			Link.l2.go = "erect";
		break;

		case "foundry":
			npchar.interior = "foundry";
			Dialog.text = "A " + npchar.interior + " ?";
			Link.l2 = "Right. My clerk will assign the necessary resources to you, and I expect that you finish the work till my next visit. See ya!";
			Link.l2.go = "erect";
		break;

		case "distillery":
			npchar.interior = "distillery";
			Dialog.text = "A " + npchar.interior + " ?";
			Link.l2 = "Right. My clerk will assign the necessary resources to you, and I expect that you finish the work till my next visit. See ya!";
			Link.l2.go = "erect";
		break;

		case "dock":
			npchar.interior = "dock";
			Dialog.text = "A " + npchar.interior + " ?";
			Link.l2 = "Right. My clerk will assign the necessary resources to you, and I expect that you finish the work till my next visit. See ya!";
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
				Dialog.text = "Umm, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", a " + npchar.interior + " requires " + planks + " planks, " + money + " Gold and "+crew+" men. But, as I said, we have only "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" plankunits, "+pchar.money+" G and "+Pchar.Ship.crew.quantity+" hands...";
				Link.l3 = "Oops.. a small..err.. Well, so you'll have to live on in this place as it is..";
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
			Dialog.text = "Too late! Here they come... the savage Akellani cannibals! Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + "These landlubbers are all paralysed with fear! Spoiled from landlife. Seems like I'll have to do the fighting without them.";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "The apprentices are rioting. Some hotheaded preacher put the stupid notion in their head that you exploit them...";
			link.l1 = RandSwear() + "What? Haven't I given them the chance to live in comfortable dry toolshacks instead of a damp and fetid shiphold? There is no gratitude on earth anymore! Well, I'll beat some gratitude out of them...";
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
			Ambush("Lower_Citizens",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
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
					Dialog.text =  "I hate to say it " + adress + " we found nothing of value, even though we sifted tons of sand and clay. Sorry for that, but this is a rather unpredictable business.";
					link.l1 = RandSwear() + "This mining is more game of chance than business. I hope that you'll have more success til my next visit.";
					link.l1.go = "exit";
				}
				else
				{
					if(rand(100)>50) {GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(3)) );}
					else{GiveItem2Character(PChar, "mineral"+ makeint(1 + rand(2)) );}

					Dialog.text =  "Oh, we had some luck this time and found a few gems. Here they are, you'd better put them into your purse right away.";
					link.l1 = "Hey, great, thanks a lot. Keep up the digging, and much luck";
					link.l1.go = "exit";
				}
		break;

		case "tax":
			npchar.tax = tax * 1;	// Reward goods, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = "Well, since your last 'call' we managed to stockpile " + tax + " " + prodname + ". I already contacted a prospective buyer, and the profits from this sale could be reinvested in this business." ;
			link.l1 = LinkRandPhrase("Reinvestment? I want a return on my capital! Shareholder value it is! ","What do you need money for? After all I provide you with all you need: protection, materials, work.. ","I'll take that.. err.. take care of that. I bet you would get cheated by your buyer anyway, so it is in your best interest if I arrange the sale for you.") +" Send the whole stuff to my ship.";
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Well done. I'll leave half of the goods to you. Use them wisely to increase your fortune. (And mine as well..)","So you worked hard, eh? As a reward for that I'll leave you half of the goods for your own account.(In the hope that you'll work even harder..)","Listen, I'll leave you half of this so that you can improve your living and working conditions. I want my estate to be a decent and happy place. (And an effective and profitable one..)");
			link.l2.go = "taxhalf";
			link.l4 = "That much? Umm, I must check if there is enough space in my ship for that. Would be a bit frustrating if the fruits of all your hard labor had to be dumped on the beach for lack of storage, eh?";
			link.l4.go = "exit";
			link.l3 = "Why " + npchar.tax + "? How does this add up? Can you enlighten me, please.";
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking
			npchar.tax = tax * 1;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, beggin your pardon, Mylord, but times have been hard for us lately: the yellow fever struck us one after the other and we were unable to work...", "I'm awfully sorry, Squire, but there is not a single coin left in my pocket: just the other night some thief stole all I had stored for you. You really should do more for the security of your estate...", "I hate to say it, Your Lordship, but the equipment you provided for us is just a heap of scrap. We were so busy fixing it that we couldn't manufacture anything.") ;
			link.l1 = LinkRandPhrase("Well, if things are really that hard for you I won't make them even harder: I'll let you off the hook, but only for this time. Cause I can't afford to show weakness too often, I can keep my crew only under control if they respect me as a tough guy.", "Allright, I'll accept your explanation this time. But the next time I don't want to hear any excuses again... After all the profits from this operation are supposed to support my ship, and the crew will not be pleased if they have to forfeit their bonus.", "Hmm, there is no point in killing the cow you want to milk, is there? I let you off the hook this time, but I expect that you resume production as soon as things run better for you. Though my crew will grumble that I'm too soft on you landlubbers.");
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Belay that whining, I have heard those empty excuses too often to believe them any longer. You'll pay a penalty of breach of contract if you can't deliver the goods you are supposed to produce.", "Well, according to our contract you have to pay compensation if you can't deliver...  Come on, this won't kill you... I only demand what's due to me, nothing more, but also nothing less.", "Shut up, you wailing embezzler! You probably sold the stuff on your own account, eh? Not with me, I'll confiscate your money. It's MINE anyway.");
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
			Dialog.text = "That's most generous of you, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". I'll tell everybody what a kind and caring employer you are, you can be sure of that!";
			link.l1 = "Oh, don't bother, I'm not so keen on my reputation. By the way, I grant you leave tonight. Why don't you go downtown, mingle with the townfolk, chat a lot... Have fun!";
			link.l1.go = "exit";
		break;

		case "taxfull":
      // next 3 lines reset taxdays to 0
      lcn.building.(nr).taxyear = GetDataYear();
      lcn.building.(nr).taxMonth = GetDataMonth();
      lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, prodgood, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Allright, you own this shop, so if you wan't to ruin it... But don't complain if you are soon without craftsmen cause we've starved...", "A bit shortsighted to squeeze a business dry just to increase the short term profit, if you ask me. But I assume you DON'T ask me, eh? Well, you shall have your shareholder value, even if you choke from it..", "You want to skim off the whole result of all our hard labor? Well, YOU tell that my.. err.. your workmen. And don't be surprised if some goods will fall into the sea on the way to your ship..") ;
			link.l1 = "Hmm, I wonder if it was a good idea to tarnish my reputation and stifle my craftmen's spirit of enterprise by taking it all. ";
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
			Dialog.text =  RandSwear() + LinkRandPhrase("Well, here, take your darned money. But don't complain if you are soon without craftsmen cause we've starved...", "Then I have no choice but to borrow the money for you from a loanshark. Means that I'll probably end up with a broken arm... in the BEST case...", "Allright, you leech, here, take this money which I had saved for my sick mother.") ;
			link.l1 = "Hmm, I wonder if it was a good idea to tarnish my reputation by insisting on these " + tax + " Gold ";
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
			Dialog.text = RandSwear() + "Well, here, take my money. I have no choice but to pay. But you don't do yourself a favour with your harshness, it will surely provoke a riot once the word spreads among your workers!";
			link.l1 =  RandSwear() + "Labor unrest on MY estate? I'll take care of that, believe me!";
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			// next 3 lines reset taxdays to 0
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text =  RandSwear() + LinkRandPhrase("Well, if you take my possessions from me I'll take your's from you as well! With one of YOUR grenades! Ironic, isn't it? My life is nothing but a bad farce...","You are my ruin! What am I supposed to live on? I'll starve! ... NO! I won't! I'll rather die fast, with a bang and not with a whimper! Where is my powderkeg?","You destroyed my life, you vampire! All that's left to me is this keg'o'rum... Beautiful strong rum, burns in your throat like hellfire... Hellfire, that's where you belong... YA HEAR ME, BLOODSUCKER? HELLFIRE YOU SHALL GET! Hehe, this spirit burns not only in the throat...");
			link.l1 = LinkRandPhrase("Oh, come on, now you REALLY overdramatise..","Hey, what are you up to? Careful, you may cause a fatal accident..","Allright, kill yourself if you like. Loosers like you can easily be replaced..");
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
  			Dialog.text = "Oh, yes, I'd be happy to help my employer, and of course it won't cost you anything. If your hands lend a hand we'll need only two days. Although.. well, we have only a small dock here, suitable for fishing boats and coastal vessels only. We can beach your ship and do some careening, caulking and replanking. But SHOULD some major part like keel or frame timbers be damaged we can do nothing about it. In some rare cases we may even increase the damage by disturbing the structure. " ;
  			link.l1 = "So it's a game of chance if I let you fuss with my hull, eh? Most of the time I get a decent repair for free, but sometimes I'll be worse of than before? Harumph.. I have to take that risk, I just don't have the time to sail to another yard. Go ahead, do your best, while I'll pray that your best is good enough.. ";
  			link.l1.go = "repairfreeall";
  			link.l2 = "But mending my rigging doesn't require any special equipment, does it? So fix that only, if you please, and leave the hull alone. ";
  			link.l2.go = "repairfreerig";
  			link.l3 = "Umm.. maybe I'd better take my ship to a PROPER shipwright. ";
  			link.l3.go = "exit";
			}
			else
		  {
  			Dialog.text = "Hmm.. I could.. if you hadn't just stripped us of all our materials and resources.. " ;
  			link.l1 = "Oh.. yes.. Well, I'll come back another day then. ";
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
		    
			Dialog.text = RandSwear() + LinkRandPhrase("Bad news, Mylord: several futtocks are rotten to the core. Probably the builders of this vessel used green wood for them. The plague on their thievish heads.", "I'm awfully sorry, Squire, ", "I hate to say it, Your Lordship, but you have cheated with this vessel: it's full of thieves' bolts. The bolts that hold the planks to the frame timbers are not made of expensive copper but of cheap coppercovered iron. So they are mostly corroded by now and in the next storm your planks will just pop off. Well, we just don't have so many copperbolts here, so") + " I'm afraid we don't have the resources to repair your ship here.";
  			link.l2 = RandSwear() + "I'd better take my ship to a PROPER shipwright. ";
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
     		Logit("Two days later most damage has been repaired.");
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
  			Logit("Two days later your sails and rig are almost as new.");
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
			Dialog.text = "Ah, you're telling me... I have to work with this 'odd' equipment all day long! All cobbled together from junkparts and driftwood. You can't go into that toolshack without smashing your forehead into some loose timbers. But the worst thing is that the walls are so cracked that people can walk right through them. How am I supposed to work if every oaf tramples right through my workplace? It's all the fault of the wretched architect who designed this, Couchcaptain Charles. That code nerd actually knows nothing about housemodels, he only stole some designs from Inez Diaz and placed them at the most impossible sites." ;
			link.l1 = "Hey, belay that wailing! Isn't an odd workshop better than none at all? Would you prefer to be unemployed? I for my part will enjoy the sights and features of my new buildings instead of wasting my time with nitpicking.";
			link.l1.go = "exit";
			link.l2 = "Instead of complaining about others you should get your own ass moving and tackle the problem yourself. What's the exact cause of this? I know something about modelling, maybe I can help?";
			link.l2.go = "odd2";
			link.l3 = "Never mind the looks, what I don't like is the economic part: the amount of goods and profits. And the frequency of attacks and events, the punishments..";
			link.l3.go = "tweaking";
		break;


		case "odd2":
			Dialog.text = "Any help would be most appreciated. Some of these buildingmodels could certainly do with a remodeling. The main problem is that these buildingmodels are not part of the locationmodel but items attached to stationary characters, like me. Therefore the walkpatch of the locationmodel -which prevents characters from walking through walls- doesn't cover these new buildings. What we need is a walkpatch around the buildingitems. Or around the characters to which the buildingitems are attached. If you know a solution for this post it at the PotC modding forum at "+PA_INET;
			link.l1 = "Ummm, I'll think about that...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "No need to gripe about that. You can tweak that yourself just by editing a textfile. For example here is how you can half my payments to you (hehe): Open the file 'program\dialogs\ " + NPchar.dialog.filename + " ' with a texteditor like notepad. Use the search function to search for the catchword 'reward'. This will lead you to a line similar to this: ' tax = taxdays * 1;	// Reward ...  '. Replace the '1' with '0.5' to half my payments. (Don't expect me to tell you how to RAISE them ;) ). Likewise you can tweak other things by searching for the catchwords 'chance' for eventchances, or 'punishment' for e.g. reputationlosses. The comment behind the '//' doubleslashes will tell you what the code before does. To disable the influence of reputation on revenue find the two lines with the comment '// reputationinfluence..' and delete them. If you need more info post at the PotC modding forum at "+PA_INET;
			link.l1 = "Hey, thanks for the hints. Sounds like modding is not that difficult, eh? Just requires some patience and dedication. But if I am able to manage playing this game I should also be able to tweak it a bit.";
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = "Allright, here is a little lesson on the socioeconomics of your estate: Every day your workers and tenants work on your estate, save their earnings or stockpile goods. How much they save and store depends very much on your behaviour: content people work more efficient, confident people save and store for the future and if you treat your people decently and show that you can protect them they more willing to yield money or goods to you. Otherwise they go slack, embezzle what should be yours or even revolt. A good measure is your reputiation: the higher your reputation the higher your revenue. And vice versa: the better your behaviour on your estate the higher your reputation. So you must learn to balance your immediate need for money and goods with the long term prosperity of your estate. Be strict when you must and generous when you can." ;
			link.l1 = "And you call that socioeconomics? Sounds more like voodoo economics to me. Or couch economics rather. What do you need savings for? After all I provide you with all you need: protection, housing, food, work.. So it's only fair that all your gold wanders in my.. err.. the communal coffers. That's what I call socioeconomics, learned that from a really clever guy called Marx!";
			link.l1.go = "taxfull";
			link.l2 = "I see.. Listen, I'll leave you half of your savings so that you can improve your living and working conditions. I want my estate to be a decent and happy place. (And an effective and profitable one..)";
			link.l2.go = "taxhalf";
			link.l3 = "I don't like this. I'd sacrifice this taxpayment for information on how to tweak this mod to my liking. All these events and influences just don't suit my playstyle.";
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Aww, I am so awed by your presence that I don't dare to move.", "Man, I've been working all day long, all my bones are aching, and I won't let you keep me from having a well earned rest.", "Would you believe it, I have to support the whole building. It will collapse if I move as much as my little finger...");
			link.l1 = "Psaw, allright, I understand... Goodbye.";
			link.l1.go = "exit";
		break;

		case "explain":
			Dialog.text = "The biggest real estate tycoon in town, Donald Dump, has recently made a fortune with his developement projects in the suburbs of #sOxbay# and #sGreenford#. And to promote his reputation he spent some of his profits on additional fortifications for this port, including a resplendent new renaissance gatehouse and a clocktower called 'Dump Tower'. True, much of this modern architecture looks a bit out of place here, but the cannon work well. If you want to see them in action you just have to attack me.. ";
			link.l1 = "I hate ostentatious real estate tycoons! Especially if they spoil the landscape with those always-the-same-looking prefab suburbs.";
			link.l1.go = "explain2";
		break;

		case "explain2":
			Dialog.text = "Oh, you should have a fresh look at the rebuilt suburbs now. Quite a change from the usual locations. And instead of griping about the real estate boom you could join it, develop your own settlements and cash in the various profits from rents, taxes and the goods that your farms and workshops produce. Yes, now you can erect your very own buildings, whereever you want. All you need is an officer, planks and money. Read all about it in the Building Kit readmefile in the Buildinfo folder!";
			link.l1 = "Hmm.. or I could built my private pirate hideout.. or my naval base.. or my own fortress, eh? QUITE a change from the usual!! Well, I'm afraid I have to go. Need to find some building ground..";
			link.l1.go = "exit";
			link.l2 = "Swell, but are those modern prefab buildings really sound? There are often earthquakes on these islands. Speaking of quakes, do you feel this faint rumbling under our our feet? Getting stronger and stronger..";
			link.l2.go = "explain3";
		break;

		case "explain3":  // PB: Buildings will disappear after leaving Oxbay, done in quests_common.c
			Dialog.text = RandSwear() + " That's really an earthquake!! But don't worry. Those new buildings are sound enough. They won't collapse. *To himself:* They won't collapse. *Starts mumbling to himself*";
			link.l1 = "Somehow you don't seem very confident about those buildings being strong enough. I wouldn't be surprised if they were ruins next time I come here!";
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
