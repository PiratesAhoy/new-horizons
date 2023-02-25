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
	PChar.storekeeper.Idx = -1;//MAXIMUS
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " my landlord ";}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}

	PlayStereoSound("ambient\town\cough.wav");
	PlayStereoSound("ambient\shop\sigh2.wav");

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
        		PlayStereoSound("voice\ENGLISH\Eng_m_a_070.wav");	
				Dialog.text =  LinkRandPhrase("Thanks to God that you came along! You can defend us against those brutes..", "Ahh, heaven sent you at a most crucial moment: we are about to come under attack. HELP US!", "Well met, I say, we desperately need a fighting " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " like you to ward off that raid...");
				link.l1 = "Hey, calm down! My, my, you are already stiff from fear... Now tell me what's going on here.";
				if(rand(100)>60) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Oh, come on, you are able to defend yourself, aren't you? I have important affairs to manage and don't want to be bothered with rustic villagebrawls!";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  LinkRandPhrase("Ah, our beloved squire visits his " + buildingstr + ". What can I do for you," + adress + "?" , "Welcome to my.. err.. YOUR " + buildingstr + " , " + adress + ", what is your desire?" , "Welcome, " + adress + ". What brings you to to my.. err.. YOUR " + buildingstr + "?");
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "Oh, I feel terrible! Fever, swollen limbs, darkening around my injuries... I fear I`ve got gangrene!";
					Link.l1.go = "infected";
				}
				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";
				
				if(interiorstr=="marketstall")
				{
        	link.l3 = "Nice display on the marketstalls outside. I'd like to have a look at your wares.";
				  link.l3.go = "shop";
        }

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{

	   			if(taxdays>0)
	   			{
  					link.l5 = "What do you think your landlord desires, eh? Your home was built at my expense, and I'd like to get some return on my investment, and the protection I offer you is not for love either. So I am here to collect taxes. How much have you earned during the " + taxdays + " days since the last payment?";
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
            {Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
					}

        	link.l6 = "Hmm, I wonder if this " + buildingstr + " can be improved.";
				  link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = "Listen, a lot of scoundrels scoure these islands, raiders that enjoy plunder, torture and rape. Maybe they come here, and in that case you need some last resort. Here, take this grenade...";
					link.l7.go = "grenade";
					}

					link.l8 = "I have no use for this construction anymore. Dismantle it, load the planks into our hold and report to the boatswain for shipduties.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = "Just passing by... ";
					link.l9.go = "exit";
				}

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

// add interior
		case "interior":
			Dialog.text = "Oh, yes, we could dump the "+interiorstr+" we currently have in here if you want to give this " + buildingstr + " a new function. You just have to give us some of your "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" plankunits, "+ pchar.money +" gold and "+ Pchar.Ship.crew.quantity +" sailors. What are you thinking of?";
			Link.l1 = "Umm, I don'think I should invest even more here.";
			Link.l1.go = "exit";
			Link.l8 = "A marketstall (turns house into tradepost, pays taxes; 5 planks, 5000 G, 3 hands)";
			Link.l8.go = "marketstall";
			Link.l5 = "Luxurious furniture (improves chance of successful woundtreatment in houses; 5 planks, 1000 G, 1 Crw)";
			Link.l5.go = "luxurious furniture";
		break;

		case "marketstall":
			npchar.interior = "marketstall";
			Dialog.text = "A " + npchar.interior + " ?";
			Link.l2 = "Right. My clerk will assign the necessary resources to you, and I expect that you finish the work till my next visit. See ya!";
			Link.l2.go = "erect";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
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
				Dialog.text = "Umm, Sir, a " + npchar.interior + " requires " + planks + " planks, " + money + " Gold and "+crew+" men. But, as I said, we have only "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" plankunits, "+pchar.money+" G and "+Pchar.Ship.crew.quantity+" hands...";
				Link.l3 = "Oops.. a small..err.. Well, so you'll have to live on in this place as it is..";
				Link.l3.go = "exit";
			}
			else
			{
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;

				// take buildingresources
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );
				PlayStereoSound("INTERFACE\took_item.wav");
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
			Dialog.text = "Too late! Here they come... Francisco Pizarro the Younger and his horde of maurading conquistadores! Lusting for blood, plunder and rape... Oh, if we had only more of those bastions, stockades, mines and cannon...";
			link.l1 = RandSwear() + "These landlubbers are all paralysed with fear! Spoiled from landlife. Seems like I'll have to do the fighting without them.";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + "What? " + taxdays + " days have already passed? Allright, I managed to save " + npchar.tax + " Gold," + adress ;
			link.l1 = LinkRandPhrase("Thank you, most obliged. Well, it was a pleasure to meet you but I must get on. Till next time *WINK* ","What do you need savings for? After all I provide you with all you need: protection, housing, food, work.. So it's only fair that all your gold wanders in my.. err.. the communal coffers.","I'll take that.. err.. take care of that. I bet you would waste it with drink and gambling anyway, so it is in your best interest if I hold your money in trust for you.");
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Well done. I'll leave half of it to you. Use it wisely to increase your fortune. (And mine as well..)","So you worked hard, eh? As a reward for that I'll leave you half it for your own account.(In the hope that you'll work even harder..)","Listen, I'll leave you half of this so that you can improve your living and working conditions. I want my estate to be a decent and happy place. (And an effective and profitable one..)");
			link.l2.go = "taxhalf";
			link.l3 = "Why " + npchar.tax + "? How does this add up? Can you enlighten me, please.";
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, beggin your pardon, Mylord, but times have been hard for us lately: the yellow fever struck us one after the other and we were unable to earn any money...", "I'm awfully sorry, Squire, but there is not a single coin left in my pocket: just the other night some thief stole all I had saved for you. You really should do more for the security of your estate...", "I hate to say it, Your Lordship, but we can hardly get by on your estate here: poor soil, bad climate and almost no trade mean that nobody here has much money to spend, and that in turn means that there is no money for us to earn. If you reduce the cashflow on your estate even more by taxation you'll make matters only worse...") ;
			link.l1 = LinkRandPhrase("Well, if things are really that hard for you I won't make them even harder: I'll remit your dues, but only for this time. Cause I can't afford to show weakness too often, I can keep my crew only under control if they respect me as a tough guy.", "Allright, let's skip THIS payment. But the next time I don't want to hear any excuses again... After all your dues are supposed to support my ship, and the crew will not be pleased if they have to forfeit their bonus.", "Hmm, there is no point in killing the cow you want to milk, is there? I let you off the hook this time, but I expect that you resume payment as soon as things run better for you. Though my crew will grumble that I'm too soft on you landlubbers.") + "";
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Belay that whining, I have heard those empty excuses too often to believe them any longer. You'll pay, here and now.", "Come on, don't exaggerate! This won't kill you... I only demand what's due to me, nothing more, but also nothing less.", "Shut up, you wailing squatter! You either deliver what our contract awards me or you'll sleep in the jungle tonight.");
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfull"; break;
			}
		break;

		case "taxhalf":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax)/2 );
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = "That's most generous of you, Sir. I'll tell everybody what a kind and caring landlord you are, you can be sure of that!";
			link.l1 = "Oh, don't bother, I'm not so keen on my reputation. By the way, I grant you leave tonight. Why don't you go downtown, mingle with the townfolk, chat a lot... Have fun!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Well, here, take your darned money. But don't complain if you are soon without tenants cause we've starved...", "Then I have no choice but to borrow the money for you from a loanshark. Means that I'll probably end up with a broken arm... in the BEST case...", "Allright, you leech, here, take this money which I had saved for my sick mother.") ;
			link.l1 = "Hmm, I wonder if it was a good idea to tarnish my reputation by insisting on these " + npchar.tax + " Gold ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Well, here, take your rack rent, you capitalist exploiterer. But be sure that the masked avangers of the revolutionary PLO will indict you in front of a people's tribunal for that! Proletarians of all islands, unite! Down with the military manufactural complex!";
			link.l1 = LinkRandPhrase("Don't unnerstand yer gob, but if ya pay I no care what ya say.","What? The Pirates Liberation Organization still exists? Hasn't our government claimed that the 'liberation' of the barbary states would exterminate them? Well, never believe those liars in the statehouse..","AARGH! The Pirates Liberation Organization! An insurgency on my very own estate!");
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
			Dialog.text = "No need to gripe about that. You can tweak that yourself just by editing a textfile. For example here is how you can half my payments to you (hehe): Open the file 'program\dialogs\ " + NPchar.dialog.filename + " ' with a texteditor like notepad. Use the search function to search for the catchword 'reward'. This will lead you to one or several lines similar to this: ' npchar.tax = taxdays * 10;	// Reward rentmoney,...  '. Replace the '10' with '5' to half my payments. (Don't expect me to tell you how to RAISE them ;) ). Likewise you can tweak other things by searching for the catchwords 'chance' for eventchances, or 'punishment' for e.g. reputationlosses. The comment behind the '//' doubleslashes will tell you what the code before does. To disable the influence of reputation on revenue find the two lines with the comment '// reputationinfluence..' and delete them. If you need more info post at the PotC modding forum at "+PA_INET;
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
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
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

// trading
		case "shop":
		  int quality = makeint(rand(8));
			NPChar.itemtrade.quality = quality;
			NPChar.itemtrade.tradetype = IT_TYPE_STALL;
			GiveItemToTrader(npchar);

			string qstr = "so so";
			if(quality>2)qstr = "quite good";
			if(quality>5)qstr = "booming";

			Dialog.Text = "Well, trade is "+ qstr +" here. The only goods we don't buy are ebony and coffee. The local plantations produce so much of that stuff that we can't make a profit by trading with that. So what do you need, cargo or personal items?";
			Link.l1 = "Cargo please.";
			Link.l1.go = "trade";
			Link.l2 = "Let's get personal.";
			Link.l2.go = "items";
		break;

		case "trade":
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(OXBAY_STORE);
		break;

		case "items":

			DialogExit();
			LaunchItemsTrade(NPChar);
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
