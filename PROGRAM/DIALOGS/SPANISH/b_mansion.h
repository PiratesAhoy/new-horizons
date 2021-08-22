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
#include "DIALOGS\English\B_resident_text.h"

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
	
	if( !CheckAttribute(npchar, "enemynation") ) npchar.enemynation = FindEnemyNation2Character(GetMainCharacterIndex());
	int isnat = sti(Islands[GetCharacterCurrentIsland(Pchar)].smuggling_nation);
	string isnatname = GetNationNameByType(isnat);

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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " my landlord ";}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}
	
	ref chr;
	float x,y,z;
	
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
				PlayStereoSound("voice\ENGLISH\Eng_f_c_019.wav");
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if you accept the fight	
				Dialog.text =  LinkRandPhrase("Thanks to God that you came along! You can defend us against those brutes..", "Ahh, heaven sent you at a most crucial moment: we are about to come under attack. HELP US!", "Well met, I say, we desperately need a fighting " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " like you to ward of that raid...");
				link.l1 = LinkRandPhrase("Hey, calm down! My, my, you are already stiff from fear... Now tell me what's going on here.","Don't worry, whatever threat there is, I'll protect my proper.. err.. people. What is bothering you?","Shh.. Relax, you have nothing to fear as long as you are under my protection (and pay your dues). So what's up?");
				if(interiorstr=="boudoir")
				{
				  if(rand(100)>50 && IsBrothelEnabled()) {Link.l1.go = "gentry1";}
				  else{Link.l1.go = "monks1";}
				}				
				else
				{
				  if(rand(100)>70) {Link.l1.go = "Akellani";}
				  else{Link.l1.go = "commando";}
				}
				link.l9 = "Oh, come on, woman, don't make a fuss about some gossip you've heard, will you? I have important affairs to manage and don't want to be bothered with unfounded rumours!";
				link.l9.go = "exit";
			}
			else
			{	
        PlayStereoSound("voice\ENGLISH\Fre_f_a_005.wav");
				Dialog.text = "Heellloo, Captain. Soo nice to see you again..";
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "Oh, I feel terrible! Fever, swollen limbs, darkening around my injuries... I fear I`ve got gangrene!";
					Link.l1.go = "infected";
				}

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(interiorstr=="office")
					{
 				    link.l32 = "Yes, yes, thank you. Any visitors or messages for me?";
            link.l32.go = "office";
 				    link.l31 = "Heellloo, Mrs Moneycent. Soo nice to see YOU again! I am really glad that you and Q quit the Secret Service to work for my private agency.";
					  link.l31.go = "office1";
				  }

					if(interiorstr=="boudoir")
					{
	   				if(taxdays>0)
	   				{
  					link.l5 = "Heellloo sweatheart. I've come to cash in the dividends for my investment in your etablissement. How much have you earned during the " + taxdays + " days since the last payment?";
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
				  	{Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
 				    link.l32 = "I have a problem with my crew, and as you have a lot of.. err.. contact with sailors you may be able to help me.";
            link.l32.go = "crew";
					  link.l31 = "Heellloo 'Madame Monique' *WINK*. You've sure bought some fine furniture and embroidery with my money. I hope my investment wasn't wasted on unprofitable female frills and furbelows. Usually you need only a heap of straw to ply your trade. Which would also be much easier to clean than all this carpetry and velvet.";
            link.l31.go = "frills";
            }
				  }

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = "Listen, a lot of scoundrels scoure these islands, raiders that enjoy plunder, torture and rape. Maybe they come here, and in that case you need some last resort. Here, take this grenade...";
					link.l7.go = "grenade";
					}

					link.l8 = "I have no use for this construction anymore. Tell the hands which I detached to you to dismantle it, to load the planks into our hold and to report to the boatswain for shipduties.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = "Just passing by... ";
					link.l9.go = "exit";
				}

				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "Hey, why do stand here so motionless? " + LinkRandPhrase("Have you swallowed a broomstick...", "Come on, relax a little...", "I expect a bit more activity from the inhabitants of my settlement, ya hear me?");
				link.l11.go = "motion";

				link.l12 = "Umm, excuse me, I don't want to be petty, but this 'building' looks a bit odd to me...";
				link.l12.go = "odd";

				link.l13 = "Hey, you there in front of the keyboard! This is a building that YOU created, so how about creating your own dialog as well? Just use Notepad to open the file program\dialogs\ " + NPchar.dialog.filename + " and overwrite this text with your own. Then follow the instructions in the comments.";
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
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




// random attacks
		case "monks1":
			dialog.text = "Some obscure preacher has lately gathered a large fanatical sect on this island by preaching fire and brimstone. His latest theme is that our 'sinful behaviour' here is the cause of the latest outbreak of yellow fever. He has aroused a mob of his followers, and I fear they'll burn our etablissement down.";
			Link.l4 = "Oh, those types usually respect private property, don't want to ruin possible donators. And if they threaten you just play a charade of tearful repentence. Present them some naked flesh that they can flog a little, wow that you'll quit your sinful life and follow them EVERYWHERE. Those fire and brimstone hypocrites are keen on repenting girls, just play along and you'll be fine. As every politician can tell you it is better not cross religious pressure groups. And I just can't afford to be associated with you in public, so I'd better leave you now. God be with you.";
			Link.l4.go = "exit";
			Link.l1 = "I just can't stand it if so called devout christians abuse religion to cause misery to others. Those who bash others with the bible haven't really understood the lessons of the gospel!";
			Link.l1.go = "monks";
		break;

		case "monks":
			Dialog.text = "Oh, oh! Here they come... The 'Worshippers of the Purgatory', heads full of biblequotes and hate!";
			link.l1 = RandSwear() + "Well, I'll teach them the gospel my way!";
			link.l1.go = "exit_monks";
		break;

		case "Exit_monks":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("monks", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "gentry1":
			dialog.text = "The local country gentry has a big social event today: they go foxhunting. At least that's what they tell their wifes, but actually the whole mounted huntingparty comes here to spend the day with my girls. A perfect day out for all concerned, so far, but those depraved noblemen are very keen on violence and humilation. One of their favourite games is 'bitchhunting': a girl is chased into the jungle and then the whole mounted party goes after her with a pack of hounds. And when they catch her they humilate and abuse her with EVERYTHING that horsemen and hounds are equipped with, if you can imagine what I mean..";
			Link.l4 = "I'd better not imagine that or I won't be able to sleep tonight.. because of moral indignation of course! I'll teach those depraved noblemen a lesson. Every woman on my estate is to be treated with respect and courtesy, no matter what profession she has! ";
			Link.l4.go = "gentry";
			Link.l1 = "Sorry for that poor girl, but such are the risks of your profession, eh? I am sure that the gentlemen will pay well as compensation. And I just can't afford to offend the local society by spoiling their events. Tally ho!";
			Link.l1.go = "exit";
		break;

		case "gentry":
			Dialog.text = "Oh, oh! Here they come... The selfdeclared local gentry. Trying to enhance their social status by subjugation and abuse!";
			link.l1 = RandSwear() + "Well, I'll show them that their birth with a goldspoon in their mouths doesn't give them the right to treat common folk like dirt!";
			link.l1.go = "exit_gentry";
		break;

		case "Exit_gentry":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Rich_Citizens", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Akellani":
			Dialog.text = "Too late! Here they come... the savage Akellani cannibals! Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + "These landlubbers are all paralysed with fear! Spoiled from landlife. Seems like I'll have to do the fighting without them.";
			link.l1.go = "exit_akellani";
		break;

		case "Exit_akellani":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "commando":
			Dialog.text = "Oh, my goodness, you have provoked your archenemy " + GetNationNameByType(sti(npchar.enemynation)) + " one time too much! They sent a file of commando troops to exterminate you! " +  RandSwear() + " Commandos take no prisoners, they will kill us all!";
			link.l1 = RandSwear() + "So their soldiers are finally attacking me instead of standing by if I stroll into their towns? Must be a bunch of overmotivated newbies. They won't last long!";
			link.l1.go = "exit_commando";
		break;

		case "Exit_commando":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush(SelectSoldierModelByNation(sti(npchar.enemynation), "Soldier"),  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 50;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = "What? " + taxdays + " days have already passed? Allright, I managed to save " + npchar.tax + " Gold.";
			link.l1 = LinkRandPhrase("Thank you, most obliged. Well, it was a pleasure to meet you but I must get on. Till next time *WINK* ","What do you need savings for? After all I provide you with all you need: protection, housing, food, work.. So it's only fair that all your gold wanders in my.. err.. the communal coffers.","I'll take that.. err.. take care of that. Otherwise some pimp might try to force it out of your pocket, so it is in your best interest if a benevolent protector like me holds your money in trust for you.");
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Well done. I'll leave half of it to you. Use it wisely to increase your fortune. (And mine as well..)","So you worked hard, eh? As a reward for that I'll leave you half it for your own account.(In the hope that you'll work even harder..)","Listen, I'll leave you half of this so that you can buy fresh straw for the strawheap, and maybe some barrels of Doctor Maturin's Patent Poxpotion. I want my estate to be a clean and healthy place. (And an effective and profitable one..)");
			link.l2.go = "taxhalf";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 50;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, beggin your pardon, Mylord, but times have been hard for us lately: the pox struck us one after the other, we were unable to earn any money and had to spend a lot for quicksilver potions...", "I'm awfully sorry, Squire, but there is not a single coin left in my pocket: just the other night some thief stole all I had saved for you. You really should do more for the security of your estate...", "I hate to say it, Your Lordship, but some bullying pimp has already taken me.. err.. in his care. I tried to refuse but he's of the cruel kind. Here, look my broken arms...") ;
			link.l1 = LinkRandPhrase("Well, if things are really that hard for you I won't make them even harder: I'll remit your dues, but only for this time. Cause I can't afford to show weakness too often, I can keep my crew only under control if they respect me as a tough guy.", "Allright, let's skip THIS payment. But the next time I don't want to hear any excuses again... After all your dues are supposed to support my ship, and the crew will not be pleased if they have to forfeit their bonus.", "Hmm, there is no point in killing the cow you want to milk, is there? I let you off the hook this time, but I expect that you resume payment as soon as things run better for you. Though my crew will grumble that I'm too soft on you landlubbers.");
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Belay that whining, I have heard those empty excuses too often to believe them any longer. You'll pay, here and now.", "Come on, don't exaggerate! This won't kill you... I only demand what's due to me, nothing more, but also nothing less.", "Shut up, you wailing slut! You either deliver what our contract awards me or you'll work in the hold of a pirateship next.");
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfull"; break;
			}
		break;

		case "taxhalf":
			AddMoneytoCharacter(Pchar, sti(npchar.tax)/2 );
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = "That's most generous of you, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". I'll tell everybody what a kind and caring pim.. err.. protector you are, you can be sure of that!";
			link.l1 = "Oh, don't bother, I'm not so keen on my reputation. By the way, I grant you leave tonight. Why don't you go downtown, mingle with the townfolk, chat a lot... Have fun!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Well, here, take your darned money. But don't complain if you are soon without girls cause we've starved...", "Then I have no choice but to borrow the money for you from a loanshark. Means that I'll probably end up with another broken arm... in the BEST case...", "Allright, you leech, here, take this money which I had saved for my sick mother.") ;
			link.l1 = "Hmm, I wonder if it was a good idea to tarnish my reputation by insisting on these " + npchar.tax + " Gold ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("Liz1", 6+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Well, here, take your money, you mean pimp. But be sure that my sisters from the Women's Lib will get you for treating women like that!";
			link.l1 = RandSwear() + " I forgot that nowadays you just don't get away with being a chauvinist male pig! Well, Mistress, I sure deserve some punishment for my behaviour. Actually, I must confess, do I look forward to being punished by such beautiful hands like yours..";
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			Dialog.text =  RandSwear() + LinkRandPhrase("Well, if you take my possessions from me I'll take your's from you as well! With one of YOUR grenades! Ironic, isn't it? My life is nothing but a bad farce...","You are my ruin! What am I supposed to live on? I'll starve! ... NO! I won't! I'll rather die fast, with a bang and not with a whimper! Where is my powderkeg?","You destroyed my life, you vampire! All that's left to me is this keg'o'rum... Beautiful strong rum, burns in your throat like hellfire... Hellfire, that's where you belong... YA HEAR ME, BLOODSUCKER? HELLFIRE YOU SHALL GET! Hehe, this spirit burns not only in the throat...");
			link.l1 = LinkRandPhrase("Oh, come on, now you REALLY overdramatise..","Hey, what are you up to? Careful, you may cause a fatal accident..","Allright, kill yourself if you like. Loosers like you can easily be replaced..");
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
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
			Dialog.text = "Ah, you're telling me... I have to endure these 'oddities' of my home all day long! The worst thing is that the walls are so cracked that people can walk right through them. No darned privacy, not even in my own bed! It's all the fault of the wretched architect who designed this, Couchcaptain Charles. That code nerd actually knows nothing about housemodels, he only stole some designs from Inez Diaz and placed them at the most impossible sites." ;
			link.l1 = "Hey, belay that wailing! Isn't it better to have an odd home than no home at all? Would you prefer to sleep on the beach? I for my part will enjoy the sights and features of my new buildings instead of wasting my time with nitpicking.";
			link.l1.go = "exit";
			link.l2 = "Instead of complaining about others you should get your own ass moving and tackle the problem yourself. What's the exact cause of this? I know something about modelling, maybe I can help?";
			link.l2.go = "odd2";
			link.l3 = "Never mind the looks, what I don't like is the economic part: the amount of taxes and profits. And the frequency of attacks and events, the punishments..";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "Any help would be most appreciated. Some of these buildingmodels could certainly do with a remodeling. The main problem is that these buildingmodels are not part of the locationmodel but items attached to stationary characters, like me. Therefore the walkpatch of the locationmodel -which prevents characters from walking through walls- doesn't cover these new buildings. What we need is a walkpatch around the buildingitems. Or around the characters to which the buildingitems are attached. If you know a solution for this post it at the PotC modding forum at "+PA_INET;
			link.l1 = "Ummm, I'll think about that...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "No need to gripe about that. You can tweak that yourself just by editing a textfile. For example here is how you can half my payments to you (hehe): Open the file 'pirates of the caribbean\program\dialogs\ " + NPchar.dialog.filename + " ' with a texteditor like notepad. Use the search function to search for the catchword 'reward'. This will lead you to one or several lines similar to this: ' npchar.tax = taxdays * 10;	// Reward rentmoney,...  '. Replace the '10' with '5' to half my payments. (Don't expect me to tell you how to RAISE them ;) ). Likewise you can tweak other things by searching for the catchwords 'chance' for eventchances, or 'punishment' for e.g. reputationlosses. The comment behind the '//' doubleslashes will tell you what the code before does. To disable the influence of reputation on revenue find the two lines with the comment '// reputationinfluence..' and delete them. If you need more info post at the PotC modding forum at "+PA_INET;
			link.l1 = "Hey, thanks for the hints. Sounds like modding is not that difficult, eh? Just requires some patience and dedication. But if I am able to manage playing this game I should also be able to tweak it a bit.";
			link.l1.go = "exit";
		break;

		case "frills":
			Dialog.text = "Oh no, not yet another primitive pimp with no understanding for the art of refined erotic entertainment. Listen, our etablissement offers the sophisticated connoisseur various theme settings: our 'Red Velvet Dream'TM comfy cubicles have shelves with erotic literature and jars with exotic massageoil, or khat plants, or chests full of toys. The padded desk is for enacting office affairs, the potted trees for outdoor bondage (sorry for their poor state, leaves all flogged off..). Then we have the usual rug in front of the fireplace..." ;
			link.l1 = "Yes, yes, that is all very nice. What bothers the investor in me is that all those beautiful themesettings are EMPTY. How are you going to pay the dividends that you owe me without customers?";
			link.l1.go = "frills2";
		break;

		case "frills2":
			PlayStereoSound("ambient\shipyard\axe.wav");
			PlayStereoSound("nature\windmill.wav");
			PlayStereoSound("ambient\town\vehicle.wav");
			Dialog.text = "Well, true, there are not THAT many sophisticated connoisseurs on these islands. But those who show up now and then pay premium prices. And we still have a huge no-frills discount area in the attic above with dozens of hammocks for sailors and a huge strawheap for countryfolk. And I can assure that it is always busy, as you can hear." ;
			link.l5 = "Ah, THAT is the source of all that noise upstairs. And I had thought that there are carpenters reflooring the attic... Well, the conaser.. err.. coniss.. eh.. refined gentleman in me is of course offended by the fact that your primitive no frills section attracts much more folk than the first class. But the businessman in me is content to pocket the cash no matter how it has been made. How much have you made during the " + taxdays + " days since my last visit?";
  			if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
			{Link.l5.go = "tax";}
			else{Link.l5.go = "taxevasion";}
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Aww, I am so awed by your presence that I don't dare to move.", "Man, I've been working all day long, all my bones are aching, and I won't let you keep me from having a well earned rest.", "Would you believe it, I have to support the whole building. It will collapse if I move as much as my little finger...");
			link.l1 = "Psaw, allright, I understand... Goodbye.";
			link.l1.go = "exit";
		break;

// enc_resident stuff: healing, spending time etc. 
		case "chat":
			dialog.text = B_TEXT[17];
			Link.l4 = B_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 = B_TEXT[18];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				Link.l1 = B_TEXT[22];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = B_TEXT[23];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = B_TEXT[20];
			Link.l1 = B_TEXT[21];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35 || interiorstr=="luxurious furniture") {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = B_TEXT[24];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(B_TEXT[25], B_TEXT[26], B_TEXT[27]); 
			int winlink = rand(100) 
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l1.go = "exit recovered"
			}
			Link.l2 = LinkRandPhrase(B_TEXT[41], B_TEXT[42], B_TEXT[43]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(B_TEXT[44], B_TEXT[45], B_TEXT[46]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = B_TEXT[47];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\ENGLISH\Eng_m_a_013.wav");
			Log_SetStringToLog("You chat on for hours and learn a lot.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("You chat on for hours and learn a lot.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog("After 24hrs are you fit again, even stronger than before.");
			Log_SetStringToLog("+ 1 max HP");
			Log_SetStringToLog("You have learned a lot about woundtreatment.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus); }
		break;

		case "exit infected":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog("You wake up feeling feverish.");
			Log_SetStringToLog("Your wounds burn like fire!");
		break;



// boudoir
		case "crew":
			Dialog.text = "For sure, I know more about our sailors than their own mothers. Well, it's probably better that their mothers don't know THOSE sides of their sons. So what's the trouble with your mates?";
			Link.l1 = "I'd like to improve their mood and motivation. Could you organize an org.. err.. entertainment for them? I would sure cheer them up if they could.. er.. meet you and your girls. ";
			Link.l1.go = "orgy";
			Link.l2 = "I could do with more sailors, but I can't find any volunteers who'd join my ship. Really can't imagine why. After all I provide decent food, the maggots and weevils are all well spiced and boiled. There is one warm comfy hammock for every second man, and my mortality rate is only 42 percent.. per week. Now if that ain't well above average living conditions for jack tars..";
			Link.l2.go = "crimp";
		break;

		case "crimp":
			Dialog.text = "VOLUNTEERS?? Are you really that naive? Which ship nowadays can be manned with volunteers? The navy mans them by impressment, and merchants by crimping. I could easily crimp you a full crewcomplement. After a busy night we always have dozens of customers which are so exhausted and drunk that you could easily drag them to your ship without any resistance.";
			Link.l1 = "And before they regain consciousness my ship will be far away from shore, and being penniless and defenceless they'll have no choice but to submit to shipdiscipline. Grudgingly, no doubt, but the cat will motivate them for sure.. That's how most naval careers start these days. Allright, bring my crew up to full complement and I'll leave you the dividends that you owe me. See ya.";
			Link.l1.go = "crimp2";
			Link.l2 = "Umm, don't like the idea of having a bunch of demoralized crimped hands in my crew. Goodbye";
			Link.l2.go = "exit";
		break;

		case "crimp2":
		  pchar.ship.crew.morale=sti(pchar.ship.crew.morale)-30;  // reward: crew moral. Change figure to your liking
		  if(sti(pchar.ship.crew.morale)<11) pchar.ship.crew.morale=11;
	    SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "orgy":
			Dialog.text = "YOUR WHOLE CREW?? Whew, well, we are all well trained, and with some tricks and lotions we might stand that. But we won't be able to serve other customers for some time, so you'd have to compensate us for the loss of income.";
			Link.l1 = "Oh, it won't be that demanding. My mates haven't met a girl for weeks, so they won't.. er.. last long. Especially not in such beautiful.. er.. hands as yours. And as compensation I'll leave you the dividends that you owe me. And now I'd better leave before my hands show up. Once they are aroused and drunk no good looking human being is safe from them.. ";
			Link.l1.go = "orgy2";
			Link.l2 = "Umm, maybe it's cheaper if I just give them some money. Goodbye";
			Link.l2.go = "exit";
		break;

		case "orgy2":
		  pchar.ship.crew.morale=sti(pchar.ship.crew.morale)+10;  // reward: crew moral. Change figure to your liking
		  if(sti(pchar.ship.crew.morale)>99) pchar.ship.crew.morale=99;
	    PlaySound("OBJECTS\abordage\abordage_wining.wav");
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


// headquarter
		case "office1":
			Dialog.Text = "Oh, I am glad about my move as well. I was heartily sick of that old boy network in the Royal Secret Service. And the constant harassing by testosterone-flushed wannabe superagents got boring in the long run as well. No, I'm happier in your posh headquarter here. Though.. actually there are not many secret service missions yet, are there?";
 			link.l3 = "I'm afraid you are right, but I hope that one day this office will become the headquarter of a blooming private investigation agency. Our special agent Couchcaptain Charles has for a long time promised to acquire clandestine missions for us but hasn't delivered yet. That unreliable sleazy sneaker got entangled in some shady real estate deal and had to lie low for some time. So for the time being we must spend our time with more mundane affairs.";
			link.l3.go = "office";
		break;

		case "office":
		  if(taxdays>0)
	   	  {
			Dialog.Text = "A gentleman has called who claims that he is a diplomat and wants you to join the service of his sovereign, a slightly less distinguished guy would like to hire you as escort for his ship, and a rather shabby feller begs you to hire him. As officer. A representative of the neighbouring planters has come to pay tribute. And the good old Q has assembled some super secret special weapon again";
			Link.l1 = "Special weapons are always welcome, but Q's lectures on them aren't. I would like to get the toys without meeting him. Be a good secretary and fetch them for me, will you? Most obliged.";
			Link.l1.go = "weapons";
			if (sti(npchar.enemynation)!= -1 && sti(npchar.enemynation)!= PIRATE)
			{
			Link.l2 = "A diplomat? Who sent him?";
			Link.l2.go = "nations";
			}
			Link.l3 = "See the merchant with the escort mission in.";
			Link.l3.go = "convoy";
			Link.l4 = "Let's have a look at that wannabe officer.";
			Link.l4.go = "officer";
			Link.l5 = "Tribute? In words or in cash?";
			Link.l5.go = "Tribute";
			Link.l6 = "Oh, can't waste my time with nagging bores. Be a good secretary and get rid of them, will you? Most obliged.";
			Link.l6.go = "Exit skip tax";
			}
			else
			{
			Dialog.text = "No more appointments for today in my schedule. All earlier callers lost their patience meanwhile and have taken their leave. ";
			Link.l2 = "Oh, well, they'll probably be calling again tomorrow. Till then, see ya.";
			Link.l2.go = "exit";
        }
		break;


		case "Tribute":
			Dialog.text = "Well, that depends on you. Those planters have lately suffered a lot from raids by Akellani tribes. The Governor of this island says that " + isnatname + " can't spare any troops to protect the planters. So they have come to you for protection and ask you to become their representative.";
			Link.l1 = "Umm.. I fear " + isnatname + " will regard it as rebellion if we bypass the governor and elect our own representative. Be a good secretary and tell my neighbours politely that I must decline their generous offer.";
			Link.l1.go = "repdrop";

			Link.l2 = "About time that we show " + isnatname + " that they can't treat us like serfs. I am honoured to accept the title of elected representative, and I'll take care of those natives.";
			if(rand(100)<30)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "akellani";}
			else{Link.l2.go = "represent";}

			Link.l5 = "I don't care about titles and politics, I'm an honest privateer: tell those countrygents that my protection comes at a fair price: 500 Gold per day, payable from the day that my estate here was founded. And tell them that they'd better not decline that offer. If " + isnatname + " can't protect them from some savages it will not be able to protect them from me either, hehe.";
			Link.l5.go = "Tribute2";
		break;

		case "Tribute2":
			npchar.tax = taxdays*500;
			ChangeCharacterReputation(Pchar, -3);  // punishment: reputation. Change figure to your liking
			Dialog.text = npchar.tax + " Gold? May I remind you that the Colonial gentry cares a lot for society status and conventions. They may be offended by such a rash 'offer' from an upstart privateer.";
			Link.l2 = "Never mind, those snobs shall pay or I'll show them some common down-to-earth manners.";
			if(rand(100)<50)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "gentry";}
			else{Link.l2.go = "Exit pay tax";}
		break;


		case "weapons":
				LAi_Fade("", "");
			Dialog.text = "Here is all the highly explosive stuff that Q has made during the " + taxdays + " days since your last visit.";
			link.l1 = "Great. Be a good secretary and put all those deadly gadgets into my bag, will you? But for heavens sake be careful with those explosives..";
			if(rand(100)>20)    // chance for explosion, decrease last figure for fewer explosions 
      		{Link.l1.go = "weapons_got";}
			else{Link.l1.go = "explosion";}
		break;

		case "weapons_got":
 			 // ccc special weapons, SW assembly kit must be installed !
			TakenItems(Pchar, "bladeX1", rand(1));	
			TakenItems(Pchar, "bladeX2", rand(1));	
			TakenItems(Pchar, "bladeX3", rand(1));	
			TakenItems(Pchar, "pistolpdart", rand(taxdays));
			TakenItems(Pchar, "pistolgrenade", rand(taxdays));
			TakenItems(Pchar, "pistolgas", rand(taxdays));
			TakenItems(Pchar, "pistolrock", rand(taxdays));
			TakenItems(Pchar, "pistolstink", rand(taxdays));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "explosion":
		  Explosion(NPchar, 60);
		  lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


		case "nations":
			Dialog.text = GetNationRoyalByType(sti(npchar.enemynation)) + " of " + GetNationNameByType(sti(npchar.enemynation));
			link.l1 = "Bah, don't want to deal with those scheming knaves. Be a good secretary and get rid of that diplomat in a diplomatic way, will you? And could you tell me my schedule for today again? I just can't remember those petty administrative details..";
			if(rand(100)>30) {Link.l1.go = "office";}
			else{Link.l1.go = "commando";}
			Link.l2 = GetNationNameByType(sti(npchar.enemynation)) + "? Show him in, right now, please!";
			Link.l2.go = "nations2";
		break;

		case "nations2":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, false, false, 0.0, GetRandomModelForTypeSex(1, "Rich_Citizens", "man"), "", "");	
			chr.dialog.filename = "B_diplomat.c";
			LAi_SetStayType(chr);
			chr.nation = npchar.enemynation;
			chr.name = "Envoy from";
			chr.lastname = GetNationNameByType(sti(chr.nation));
  		GetCharacterPos(pchar, &x, &y, &z);
  		x = x+1;
  		TeleportCharacterToPos(chr, x, y, z);
  		Lai_SetActorType(chr);
  		LAi_ActorTurnToCharacter(chr, pchar);
  		LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;

		case "officer":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, true, true, 0.0, GetRandomModelForType(1, "Smugglers"), "", "");
			chr.dialog.filename = "Enc_officer_dialog.c";
			chr.dialog.CurrentNode = "Node_1";
			LAi_SetStayType(chr);
			GetCharacterPos(pchar, &x, &y, &z);
			x = x+1;
			TeleportCharacterToPos(chr, x, y, z);
		break;

		
		case "convoy":
	
			string iDay, iMonth;
			iDay = environment.date.day;
			iMonth = environment.date.month;
			string lastspeak_date = iday + " " + iMonth;
			npchar.work = lastspeak_date;

			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = "Umm, I'm afraid you have already more ships in your fleet than you can keep control of.";
				link.l1 = "You are right, more than four ships make a squadron rather unwieldy. So what were we talking about?";
				link.l1.go = "office";
			}
			else
			{
			  if (CheckQuestAttribute("generate_convoy_quest_progress", "begin"))
			  {
		  		dialog.text = "Umm, I'm afraid you have already an escorting contract with another merchant.";
		  		link.l1 = "Thank's for reminding me, after all I promised him my undivided attention and a speedy escort. Should set sail with him right away!";
		  		link.l1.go = "office";
        }else
			  {
		  		dialog.text = "He's on his way to this place, should be here any minute.";
		  		link.l1 = "Maybe I should walk out to meet him. Don't want him to get lost on shore already..";
		  		link.l1.go = "Exit skip tax";
		  		AddDialogExitQuest("prepare_for_convoy_quest");
				}
			}
		break;

// dialogexits
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // reward: reputation. Change figure to your liking

		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "repdrop":
			ChangeCharacterReputation(Pchar, -3);  // punishment: reputation. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "represent":
			ChangeCharacterReputation(Pchar, 6);  // reward: reputation. Change figure to your liking
			if (GetRMRelation(pchar, isnat) > REL_WAR) SetRMRelation(pchar, isnat, REL_WAR);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit skip tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit pay tax":
		  AddMoneytoCharacter(Pchar, sti(npchar.tax));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
