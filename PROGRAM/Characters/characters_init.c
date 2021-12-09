#include "characters\init\Other.c"
#include "characters\init\CommonQuest.c"
#include "characters\init\PostInit.c" // CHANGE THIS WHEN TOTAL_CHARACTERS IS UPPED!

// Set characters initial data

void CreateCharacters()
{
	//int tmpNameFileID = LanguageOpenFile("characters_names.txt");
 	ref ch;
	int n;
	string curskill;

	for(n=0; n<TOTAL_CHARACTERS; n++)
	{
		makeref(ch,Characters[n]);
		//DeleteAttribute(ch,"act");
		DeleteAttribute(ch,"");
		//Logic data
		ch.id = "0";
		ch.index = n;
		InitCharacter(ch); // KK
		// added by MAXIMUS [new skill-change] -->
//		if(AUTO_SKILL_SYSTEM)
//		{
//			ch.autoskills = 0;
//			InitAutoSkillsSystem(ch, false);
//		}
		// added by MAXIMUS [new skill-change] <--
	}

	ReloadProgressUpdate();

	makeref(ch,Characters[0]);		//Blaze Devlin

	SetMainCharacterName(CharFirstName); // PB
// MAXIMUS [choose character mod] -->
	ch.nation	= CharNation;
	ch.sex		= CharSex;
	ch.model	= CharModel;
	ch.model.animation	= CharAni;
	ch.difficulty = CharDifficulty;
// KK -->
	if (ch.sex == "woman")
		ch.model.height = WOMAN_HEIGHT;
	else
		ch.model.height = MAN_HEIGHT;
	ch.Flags.Pirate = CharPirateFlag;
	ch.Flags.Pirate.texture = CharPirateFlagTex;
	ch.Flags.Personal = CharPersonalFlag;
	ch.Flags.Personal.texture = CharPersonalFlagTex;
	// Sulan: initialize ship's log -->
	ch.shiplog.Date.log0 = GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay());
	ch.shiplog.Title.log0 = "New captain's log";
	ch.shiplog.Entry.log0 = "Purchased and started a new log book. The previous one went down to Davy Jones after a crew brawl in my cabin. I sent the first mate after the book, but neither him nor the book returned.";
	ch.shiplog.Category.log0 = "Personal";
	ch.shiplog.Visible.log0 = true;
	// <-- Sulan

// <-- KK
// MAXIMUS [choose character mod] <--

	ch.id		= "Blaze";

	ch.activity_begin = "0";
	ch.activity_end = "24";
	ch.luck = 4;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "blaze_dialog.c";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "START_MIN_LEVEL")) > 0 || CharPlayerType == PLAYER_TYPE_CASTAWAY)
		ch.rank 	= 1; // PB: Players can use the cheatmode for this
	else
		ch.rank 	= 5; // PB: Players can use the cheatmode for this
	ch.reputation = REPUTATION_NEUTRAL;
	ch.money = 1000; // PB: Players can use the cheatmode for this

	// PB: Apply Player Type -->
	for (int s = 0; s < 10; s++) {
		string skillname			= GetSkillName(s);
		ch.Skill.(skillname)		= CharSkills[s];
		if(AUTO_SKILL_SYSTEM)
		{
			ch.Skill.(skillname).bonus	= CharBonusSkills[s];
		}
	}
	GiveItem2Character(ch, "bladeX4");	// PB: Gives you your fists
	ch.PlayerType = CharPlayerType;		// PB: So this is stored and may still be used later
	switch(CharPlayerType)
	{
		case PLAYER_TYPE_ADVENTURER:
			switch(GetMySimpleOldName(ch))
			{
				case "Geralt of Rivia":
					ch.shiplog.Title.log0 = "Travelling Worlds";
					ch.shiplog.Entry.log0 = "Ciri and I were on the hunt for a 'dragon' that had killed five villagers. However we knew that our employer was most probably mistaken and that the monster was probably a Wyvern or something similar. When we went to investigate, we were surprised, although no dragon, the beast was still very dangerous, it was a Manticore, one of the most dangerous beasts the world has to offer. I had killed one of them in the past, but this time something was troubling me and i made a mistake. Ciri quickly grabbed me and teleported us to a different world, saving my life. But we were separated once more.";
					if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "witcher_steel+2");
					else			GiveItem2Character(ch, "witcher_steel");
				break;

				case "Dervia":
					ch.shiplog.Title.log0 = "My Introduction to the Caribbean";
					ch.shiplog.Entry.log0 = "Once a beautiful pirate captain, now a demoness. This all happened during my 'visit' on Cuba. The Spanish patrol found me and took their last breath, but I also was wounded heavily. I lost my consciousness at the governor's mansion and after I woke up, I was on a main square tied up. The people saw that I was awake and shouted to the executioner to cut off my head...and he did it. This is all really strange as after my death I found myself in a strange cave. There was a weird floating black orb and a white orb. I took the opportunity and touched the black one. A enormous and searing pain came through my body and I once again passed out. This time I woke up on Santiago main square where I was executed. My anger towards those Spanish lapdogs was so big that I burned the entire city myself, after that I continue my adventure and the Caribbean will cower before my might as I am the Angel of Death.";
					GiveItem2Character(ch, "bladerubysb");
				break;

				case "Avergorex":
					ch.shiplog.Title.log0 = "My First Arrival";
					ch.shiplog.Entry.log0 = "I spent my eternal life as a demon in the underworld, but this time someone has summoned me to this mortal world. They thought when they summon me by their stupid ritual, they will be rewarded with power, such foolishness. After I killed them, I took their belongings, their robes and weapons, especially MY sabre that I found on their leader, for now I should have a look around and see where this world will lead me.";
					GiveItem2Character(ch, "blade_ebony");
				break;

				// Default
				if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "bladeC2+2");
				else			GiveItem2Character(ch, "bladeC2");
			}
			GiveItem2Character(ch, "pistol5");
		break;
		case PLAYER_TYPE_AGENT:
			ch.shiplog.Entry.log0 = "Today I begin my new life as a ship’s captain. I have left the service of the crown and the life of a spy behind me once and for all. If I had any doubts about retiring from that line of work they ended with the episode in Madagascar. It was nothing short of a miracle that I wasn’t arrested and killed along with my counterparts from the other great powers. With my severance from the secret service I have purchased a vessel and made my way to the new world where, I hope, my past will not catch up with me.";
			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(ch, "bladeC6+2");
				if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1+3");
				else GiveItem2Character(ch, "pistol1a+3");
			}
			else
			{
				GiveItem2Character(ch, "bladeC6");
				if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
				else GiveItem2Character(ch, "pistol1a");
			}
		break;
		case PLAYER_TYPE_CORSAIR:
			ch.shiplog.Entry.log0 = "This is a truly momentous occasion. I have worked towards this since I went on account all those years back as a young, know-nothing scallywag with more spine than brains. The crew has elected me captain, replacing our departed leader who lost his head to a cannon ball during our last cruise. Bad for him, good for me. The old man was a good captain and ran a tight ship but I’ve always had my own ideas about how things should be done. Now I get to see if I’m right!";
			switch(GetMySimpleOldName(ch))
			{
				case "Blackbeard":
					GiveItem2Character(ch, "Blade_Triton");
				break;

				case "Piet Hein":
					GiveItem2Character(ch, "blade26");
					GiveItem2Character(ch, "luckydimeA");
				break;

				// default
				if (GetCurrentPeriod() < PERIOD_GOLDEN_AGE_OF_PIRACY)
				{
					if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "blade21+2");
					else					GiveItem2Character(ch, "blade21");
					GiveItem2Character(ch, "bladekit");	
				}
				else
				{
					if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "blade27+1");
					else					GiveItem2Character(ch, "blade27");
				}
			}
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "compass2");
			GiveItem2Character(ch, "clock1");
		break;
		case PLAYER_TYPE_ENGINEER:
			ch.shiplog.Entry.log0 = "I have spent most of my adult life on solid ground, as solid as a battlefields gets in any case, as a military engineer in the service of the crown. With my earnings I have decided to leave the army and invest in a ship. I have arrived in the Caribbean where they say enterprising captains with a solid vessel can do very well for themselves. We shall see. While I must confess that I am not much of a seaman yet, I am past the stage of turning green in poor weather and should pick the rest up quickly as I go.";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "book2");
			GiveItem2Character(ch, "book10");
			GiveItem2Character(ch, "book15");
		break;
		case PLAYER_TYPE_EXPLORER:
			ch.shiplog.Entry.log0 = "My mother always said I had the devil’s own luck but that I should learn not to push it too far. My last adventure up the Amazon charting the river for the Portuguese crown has driven that point home. Half the expedition dead of malaria and the rest roasted on spits by savage cannibals. On the bright side, his majesty’s representative was impressed by my harrowing tale and paid me the full expedition’s wages as I was the sole survivor. I have bought my own ship and will see what I can make of myself as a captain here in the new world.";
			if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "bladeC6+1");
			else			GiveItem2Character(ch, "bladeC6");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "compass3");
		break;
		case PLAYER_TYPE_GAMBLER:
			ch.shiplog.Entry.log0 = "I have always had the luck of the cards but this is a true windfall even by my own high standards! I am the proud new owner of a fully-outfitted sailing vessel. The old sea dog thought his four kings had me beat but my royal straight flush took the grin from his face fast enough. Ha! I didn’t even cheat. I was concerned the crew wouldn’t take kindly to the situation but it seems the old man’s bad luck had been rubbing off on them as well of late and there were no tears at the change in management.";
			GiveItem2Character(ch, "blade2");
			if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "pistol2+2");
			else					GiveItem2Character(ch, "pistol2");
			GiveItem2Character(ch, "jewelry6");
			ChangeSmugglerLiking(ch, 15); //add 15 to the default 50 -Levis
		break;
		case PLAYER_TYPE_GUNNER:
			ch.shiplog.Entry.log0 = "Ten long years I have spent in the navy over hot, roaring cannon. I’m half deaf and my body is riddled with grape shot and splinters but I have saved my wages diligently and today I am the proud owner of my own ship. I have a solid crew under my command who respect my time in service and the scars I carry. My days of shattered ships and drowning men may not be over but at least I’ll be pointing those guns where I choose now.";
			GiveItem2Character(ch, "blade1");
			if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "pistol5+2");
			else					GiveItem2Character(ch, "pistol5");
			GiveItem2Character(ch, "powderbarrel");
			GiveItem2Character(ch, "ammobag");
		break;
		case PLAYER_TYPE_MARINE:
			ch.shiplog.Entry.log0 = "Once I was a marine in the navy, but I managed to save my salary until I could afford a way out. Investing this in a new ship seems like a great way of giving me the freedom I've always wished for. So now here I am, ready to set sail on my first venture!";
			GiveItem2Character(ch, "blade11");
			GiveItem2Character(ch, "pistol2");
			ChangeSmugglerLiking(ch, -25); //substract 25 to the default 50 so you need to pay first -Levis
		break;
		case PLAYER_TYPE_MERCHANT:
			ch.shiplog.Entry.log0 = "I've worked long and hard for this day but it has finally come. The captain has retired to life ashore and sold me his interest in the ship. My own vessel! She is in good shape thanks to my care as first mate these last several years and I know what she and her crew can manage. I have said my last ‘Aye, sir' while standing on this deck. Now she goes where I tell her. It's good to be the captain!";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "spyglass2");
			GiveItem2Character(ch, "compass2");
			GiveItem2Character(ch, "clock1");
			if (CharFirstName == "Cutler Beckett" || HasSubStr(CharModel, "EITC")) GiveItem2Character(ch, "EITC_Passport");
			else
			{
				switch(sti(ch.nation))
				{
					case ENGLAND:	GiveItem2Character(ch, "Trade_PassportE"); break;
					case FRANCE:	GiveItem2Character(ch, "Trade_PassportF"); break;
					case SPAIN:	GiveItem2Character(ch, "Trade_PassportS"); break;
					case HOLLAND:	GiveItem2Character(ch, "Trade_PassportH"); break;
					case PORTUGAL:	GiveItem2Character(ch, "Trade_PassportP"); break;
					case PIRATE: break;	// Nothing - trade passports are not for pirates!
					GiveItem2Character(ch, "Trade_Passport");
				}
			}
		break;
		case PLAYER_TYPE_NAVAL_OFFICER:
			ch.shiplog.Entry.log0 = "Having joined the navy, it is now up to me to work myself up through the ranks.";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "spyglass2");
			GiveItem2Character(ch, "compass2");
			GiveItem2Character(ch, "clock1");
			ch.professionalnavy = CharNation; // PB: For Commissioned Naval Officers
			ChangeSmugglerLiking(ch, -35); //if you want to smuggle you shall first need to get their trust -Levis
		break;
		case PLAYER_TYPE_PHYSICIAN:
			ch.shiplog.Entry.log0 = "It was chance that brought me into naval service as a ship's surgeon on graduating medical college but, I must confess, the salt is in my blood now. I have been putting money away for years now, trying to decide whether to retire on it, perhaps setting up a private practice in some sleepy country hamlet, or invest it in a ship of my own. The transition to ship's captain is not an easy one but I am confident I've made the right choice for myself. Time will tell if I am right.";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "doctortoolkit");
			GiveItem2Character(ch, "microscope");
			TakeNItems(ch, "potion1", 10);
			TakeNItems(ch, "potion1",  5);
		break;
		case PLAYER_TYPE_QUARTERMASTER:
			ch.shiplog.Entry.log0 = "The loss of the captain and first officer to fever on the outset of our last voyage was difficult on the entire crew, not least of which myself, as I was put in the awkward position of taking command personally. All went rather smoothly however once the illness had run its course and, with the encouragement of the crew, I have decided to buy the ship outright from our employers and take over as captain permanently.";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "scales");
			GiveItem2Character(ch, "book2");
			GiveItem2Character(ch, "book3");
		break;
		case PLAYER_TYPE_REBEL:
			if(GetMySimpleOldName(ch) == "Hilda Sparre")
			{
				ch.shiplog.Title.log0 = "Arrived in the New World";
				ch.shiplog.Entry.log0 =  "That fool of a King and his predecessors would erode our rights, the rights of our blood tracing back to times immemorial. The realm was a bloody mess because the crown could not handle the finances of the realm. The new and growing number of lower nobles screaming for what was rightfully ours. 'Please, the war is so expensive, think of the realm'. Give them a finger and they take the whole hand. It had to stop. But it all went wrong so very fast.\n\n Me and some like-minded people I confided in had plans: Depose the King, push someone else's claim to the throne, someone who saw the worth of what we and our ancestors had done for the realm. But somehow the crown found us out. There is little doubt in my mind we were betrayed. A death sentence was a matter of fact.\n\n Thankfully I still had enough loyal friends and family that I could escape the country and get myself here to the New World. I am still hunted, Sweden's allies will not give me a warm welcome, and neither will her enemies. Their loss, I say. \n\nLo, I got myself a ship with what little wealth I had left, and now it is time to show my true mettle and prove that this noblewoman can claw her way back to greatness on her own merit. Time for adventure!";
				GiveItem2Character(ch, "clock1");
				if(ENABLE_WEAPONSMOD)
				{
					GiveItem2Character(ch, "bladeC2+1");
					GiveItem2Character(ch, "pistol2+1");
				}
				else
				{
					GiveItem2Character(ch, "bladeC2");
					GiveItem2Character(ch, "pistol2");
				}
			}
			else
			{
				ch.shiplog.Entry.log0 = "Ever since I was a child I have been restless and unable to tolerate injustice. I have fought in many wars across the old world and been on the losing side of all of them. I am without regret or apology however. I have stayed true to what I believe in and never compromised my integrity for coin or comfort. Still, I know when it is time to move on and so I have done just that. It is off to the new world for me. If I can't make Europe a better place perhaps there is still time to make the Americas one.";
			
				if(ENABLE_WEAPONSMOD)
				{
					GiveItem2Character(ch, "bladeC2+1");
					GiveItem2Character(ch, "PiratesPistol+1");
				}
				else
				{
					GiveItem2Character(ch, "bladeC2");
					GiveItem2Character(ch, "PiratesPistol");
				}
				GiveItem2Character(ch, "cheaparmor");
			}
		break;
		case PLAYER_TYPE_ROGUE:
			ch.shiplog.Entry.log0 = "Gads! I barely escaped Paris with my life but I managed it and have invested the lion's share of the proceeds into the acquisition of a ship. Not wanting to pay full price of course I managed to convince an unhappy crew to abscond with their vessel under my command with promise of treasure and freedom. It remains to be seen if I can deliver on that promise but I need to disappear from Europe and they say the new world is a fine place to disappear to.";
			GiveItem2Character(ch, "blade2");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "jewelry1");
			GiveItem2Character(ch, "jewelry2");
			GiveItem2Character(ch, "jewelry3");
			GiveItem2Character(ch, "jewelry4");
		break;
		case PLAYER_TYPE_SAILOR:
			ch.shiplog.Entry.log0 = "I have served on ships since I was a child in one form or another. Today however, for the first time, I walk out onto that deck as captain. It has been no mean feat to make my way up from a lowly deck hand to the owner of my own ship but I have arrived at last and mean to make the most of the opportunity. The crew is a fine lot and respect what I have accomplished. I mean to accomplish a good deal more before I am done.";
			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(ch, "blade27+1");
				GiveItem2Character(ch, "PiratesPistol+1");
			}
			else
			{
				GiveItem2Character(ch, "blade27");
				GiveItem2Character(ch, "PiratesPistol");
			}
			GiveItem2Character(ch, "compass1");
		break;
		case PLAYER_TYPE_SHIPWRIGHT:
			ch.shiplog.Entry.log0 = "Today is the day I take to the high seas as the captain of my own vessel. I have spent my life building ships only to watch they sail off into the distance with other men at their helm. No more! I have had my fill of life on the land and go now to find my destiny on a sturdy vessel designed and built with my own two hands. It is a glorious feeling of accomplishment and I cannot wait to see what tomorrow will bring.";
			GiveItem2Character(ch, "blade1");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
			GiveItem2Character(ch, "compass1");
			GiveItem2Character(ch, "book2");
			GiveItem2Character(ch, "book10");
			GiveItem2Character(ch, "book15");
		break;
		case PLAYER_TYPE_SMUGGLER:
			ch.shiplog.Entry.log0 = "The life of a smuggler is neither easy nor safe, as my former captain, now lingering in a Spanish dungeon will attest. It does pay well however and with my savings I have gotten our vessel out of impound and assumed the captaincy. The crew seems happy enough with the change in leadership as the old man's luck seemed to have ran out long ago and he was much too hot-tempered to make wises choices about who he did business with. His loss is my gain and I am looking forward to a long and profitable career.";
			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(ch, "bladeC6+1");
				GiveItem2Character(ch, "PiratesPistol+1");
			}
			else
			{
				GiveItem2Character(ch, "bladeC6");
				GiveItem2Character(ch, "PiratesPistol");
			}
			GiveItem2Character(ch, "compass1");
			ChangeSmugglerLiking(ch,25); //add 25 so you can ask about opium instantly. -Levis
		break;
		case PLAYER_TYPE_SOCIAL_CLIMBER:
			ch.shiplog.Entry.log0 = "I mean to go places in life and what better way to get there than as the captain of my own ship. The investment has been considerable but I expect it to pay for itself many times over before I am ready to move on to the next stage. Perhaps a noble title bought with gold and favors, or a fleet of sturdy vessels trading far and wide to fill my coffers with gold. The road will be long and treacherous to be sure but if there is one thing I have learned about myself is that I have what it takes to endure whatever I must to reach my goals.";
			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(ch, "bladeC30+2");
				GiveItem2Character(ch, "pistol2+2");
			}
			else
			{
				GiveItem2Character(ch, "bladeC30");
				GiveItem2Character(ch, "pistol2");
			}
			GiveItem2Character(ch, "jewelry7");
		break;
		case PLAYER_TYPE_SWORD_MASTER:
			if (GetMySimpleOldName(ch) == "Bohdan Aleskeevich Voronov" && ch.nation == PERSONAL_NATION)//MAXIMUS 08.05.2019: GetMySimpleName will return TRANSLATED name, so - for other langs this code will not work.
			{
				ch.shiplog.Entry.log0 = "Ten years since the death of our leader, Stenka Rasin, some of us have finally made it to the Caribbean. We have gathered our possessions and sold them to raise money to buy a ship. I have been chosen as the captain. Now we shall seek our fortune on the seas, and perhaps one day return to our beloved motherland.";
				if(ENABLE_WEAPONSMOD) GiveItem2Character(ch, "blade41+3");
				else GiveItem2Character(ch, "blade41");
			}
			else
			{
				ch.shiplog.Entry.log0 = "I have done well for myself training the well-to-do how to master the sword in personal combat. I have studied the great masters and imparted their wisdom to my own students in turn but I have frankly become bored of this quiet life. Besides, what true master of the martial arts hides behind walls away from the danger of angry steel? I have used my considerable savings to invest in a ship and decided to make my way to the Caribbean to seek adventure and an even greater fortune.";
				if(ENABLE_WEAPONSMOD)	GiveItem2Character(ch, "bladeC30+3");
				else					GiveItem2Character(ch, "bladeC30");
			}
			GiveItem2Character(ch, "goldarmor");
		break;
		case PLAYER_TYPE_CURSED:
			string curse_type = "general";
			if(HasSubStr(CharShipType, "Dutchman")) curse_type = "DavyJones";
			if(HasSubStr(CharShipType, "Mariana")) curse_type = "Orellana";

			if (curse_type != "Orellana")	// Don't give standard weapons to these specific characters, they'll get special weapons in their own sections
			{
				GiveItem2Character(ch, "blade4");
				if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
				else GiveItem2Character(ch, "pistol1a");
			}
			switch(curse_type)
			{
				case "DavyJones":
					ch.shiplog.Entry.log0 = "I have started a new logbook. The old one contained too many painful memories. This new one will soon be filled with records of fear and terror that I shall reign upon all those who dare cross me at sea!";
					GiveItem2Character(ch, "Davy_Chest");
					ch.boardingmodels = "Davycrew";
				break;

				case "Orellana":
					ch.shiplog.Entry.log0 = "Originally a Navy Officer, I was accused of treason by having a relationship with a privateer who had been taken prisoner by the Admiral during an attack. I was also arrested and tortured by the Inquisition. To save us, I made a pact with Padre Melquнades de Vбzquez. In exchange for a grace for me and my lover, I had to serve the Inquisition and extend its influence in the New World. I didn't know I had just sold my soul to the Devil at that time. Shortly after my first mission, my love succumbed to the Black Death and was the only victim. Realizing that the Demon had betrayed me, I decided to steal a ship and flee Cartagena to take my revenge on him. But the crew began to fall mysteriously ill and died quickly. Then strange events occurred, it was like moving shadows, or sinister whispers. Those who had escaped the disease were swept away by madness and killed each other or put an end to their day...";
					GiveItem2Character(ch, "Devil_Contract");
					GiveItem2Character(ch, "bldevil");
					GiveItem2Character(ch, "pistol27");
					ch.boardingmodels = "Ghost";
				break;

				case "general":
					ch.shiplog.Entry.log0 = "Perhaps we should not have been so greedy at Isla de Muerta as it turns out the treasure was cursed. The only way to lift it is to return 882 coins to the chest in the cave.";
					GiveItem2Character(ch, "aztec_compass");
					GiveItem2Character(ch, "cursedcoin");
					ch.gibbs = 1; // Removes Mr. Gibbs from the Tortuga Tavern
				break;
			}
		break;
		case PLAYER_TYPE_MILITARY:
			ch.shiplog.Entry.log0 = "I have fought in battles all across Europe and seen more men die than I have likely spoken to. The fact is, however, that the risk is too great and the rewards too small for my taste. So, looking for a new calling where I could put my particular set of skills to use, I have spent my life savings on a ship and made my way to the new world where they say a captain with a stout heart can make a name for themselves. If they don't mind the sight of a little blood that is and I, for one, never have.";
			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(ch, "blade19+1");
				GiveItem2Character(ch, "PiratesPistol+1");
			}
			else
			{
				GiveItem2Character(ch, "blade19");
				GiveItem2Character(ch, "PiratesPistol");
			}
			GiveItem2Character(ch, "commonarmor");
		break;
		case PLAYER_TYPE_CASTAWAY:
			ch.shiplog.Entry.log0 = "An old friend of the family has bought me passage on a ship bound for the New World. But whether he did that out of kindness or just to get rid of me, I do not know. I have never had much luck in Europe and the little I own in this world was safely stored in my cabin. It will be difficult to get on my feet, but I am determined to succeed at last!";
			// Deliberately no items
		break;
		case PLAYER_TYPE_CUSTOM:
			GiveItem2Character(ch, "blade4");
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) GiveItem2Character(ch, "pistol1");
			else GiveItem2Character(ch, "pistol1a");
		break;
		case PLAYER_TYPE_LAND_OWNER:
			ch.shiplog.Title.log0 = "Personal Diary";
			ch.shiplog.Entry.log0 = "Sullivan's Island, South Carolina. I have recently lost my fortune and am making a living collecting birds, flotsam and jetsam on the beach. I'm not doing too bad for myself, since I can still afford my little hut and have got my loyal servant to assist me. But I feel like something big is awaiting me!";
		break;
	}
	// PB: Apply Player Type <--

	ch.Ship.Type = CharShipType;
// KK -->
	if (CharShipType != SHIP_NOTUSED_TYPE_NAME) {
		ch.Ship.Name = CharShipName;
		// PRS3 -->
		ref rShip = GetShipByType(GetCharacterShipType(&ch));
		aref arship; makearef(arship, ch.ship);
		ch.ship.standard = true;
		arSetRandomStatsToShip(arship, sti(ch.ship.idx), sti(ch.nation)); // PB: No free upgrades on game start
		if(sti(GetStorylineVar(FindCurrentStoryline(), "LOCKED_CANNONS")) > 0)
			ch.Ship.Cannons.Type = CANNON_TYPE_LONG_LBS4;
		else
			ch.Ship.Cannons.Type = rShip.Cannon;
		ch.Ship.Cannons.Charge.Type = DEFAULT_CHARGE;
		// PRS3 <--
		ch.Ship.Stopped = true;
	} else {
		ch.Ship.Name = "";
	}
	//Levis set the officertype etc:
	ch.quest.officertype = GetCaptainType(ch);
	ResetHP(ch); // PB: To set HP correctly for different starting rank
	ch.experience = CalculateExperienceFromRank(sti(ch.rank)); // NK //Simplyfied by Levis
	if(CharPlayerType == PLAYER_TYPE_CUSTOM)
	{
		ch.skill.freeskill = sti(ch.rank) * ADD_SKILLPOINTS_PERLEVEL; // TIH changed to user configurable setting Nov14'06 // NK
	}
	else
	{
		ch.skill.freeskill = 0;
	}
	ch.perks.freepoints = sti(ch.rank); // NK
	SetCharSkillImportance(ch,1); //Levis make sure all skill importances are set right
// <-- KK
// MAXIMUS [choose character mod] <--

// KK -->
	ch.Soldier.m0 = "Offic_per";
	ch.Soldier.m1 = "Soldier_Per";
	ch.Soldier.m2 = "Soldier_Per2";
	ch.Soldier.m3 = "Soldier_Per3";
	ch.Soldier.m4 = "Soldier_Per4";
	ch.Soldier.m5 = "Soldier_Per5";
	ch.Soldier.m6 = "Soldier_Per6";
	ch.Soldier.m7 = "Soldier_Per" + (rand(4) + 2);

	ch.Boarder.Count = 12;
	ch.Boarder.m0 = NATHANIEL_BOARDER_0;
	ch.Boarder.m1 = NATHANIEL_BOARDER_1;
	ch.Boarder.m2 = NATHANIEL_BOARDER_2;
	ch.Boarder.m3 = NATHANIEL_BOARDER_3;
	ch.Boarder.m4 = NATHANIEL_BOARDER_4;
	ch.Boarder.m5 = NATHANIEL_BOARDER_5;
	ch.Boarder.m6 = NATHANIEL_BOARDER_6;
	ch.Boarder.m7 = NATHANIEL_BOARDER_7;
	ch.Boarder.m8 = NATHANIEL_BOARDER_8;
	ch.Boarder.m9 = NATHANIEL_BOARDER_9;
	ch.Boarder.m10 = NATHANIEL_BOARDER_10;
	ch.Boarder.m11 = NATHANIEL_BOARDER_11;
	ch.Boarder.Model = BOARDERMODEL;
	ch.Boarder.Index = BOARDER_INDEX;

	LAi_RemoveLoginTime(ch);
	GiveItem2Character(ch, "map");
// <-- KK

	//ch.Ship.Cannons.Type = CANNON_TYPE_TEST;
	ch.FaceId = 31;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";

	ch.quest.RelationAgentMet = "0";
	ch.quest.gambling = "0";
	ch.quest.friend_in_tavern = "";
	ch.quest.main_line = "0";
	ch.quest.killed.pirates = "0";
	ch.questchar = true;  // KK
	ch.maplegend = true;  // PB
	ch.flaglegend = true; // PB

	// PB: Treasure Quests -->
	ch.alwaysshowitems.Minersspade = true;
	ch.alwaysshowitems.Minerspick = true;
	// PB: Treasure Quests <--

	// PB: Shotgun Easter Egg -->
	ch.quest.clint_eastwood.win_condition.l1 = "location";
	ch.quest.clint_eastwood.win_condition.l1.location = "QC_Pirate_house";
	ch.quest.clint_eastwood.win_condition = "clint_eastwood";
	// PB: Shotgun Easter Egg <--

	// PB: Sword of Triton -->
	if(!CheckCharacterItem(ch, "Blade_Triton"))
	{
		ch.quest.blackbeard_shore.win_condition.l1 = "location";
		ch.quest.blackbeard_shore.win_condition.l1.location = "IslaDeMuerte_shore_03";
		ch.quest.blackbeard_shore.win_condition = "blackbeard_shore";
	}
	// PB: Sword of Triton <--

	// PB: Isla de Muerte -->
	if(sti(GetStorylineVar(FindCurrentStoryline(), "ISLA_DE_MUERTE")) > -1)
	{
		ch.quest.Muerte = "";
		ch.quest.Muerte_start.win_condition.l1 = "location";
		ch.quest.Muerte_start.win_condition.l1.character = ch.id;
		ch.quest.Muerte_start.win_condition.l1.location = "Tortuga_tavern";
		ch.quest.Muerte_start.win_condition = "Muerte_start";
	}
	// PB: Isla de Muerte <--

	// PB: Relations Tutorial -->
	ch.quest.Got_Relation_Book.win_condition.l1 = "item";
	ch.quest.Got_Relation_Book.win_condition.l1.character = ch.id;
	ch.quest.Got_Relation_Book.win_condition.l1.item = "relationbook";
	ch.quest.Got_Relation_Book.win_condition = "Got_Relation_Book";
	// PB: Relations Tutorial <--

	// GR: Pirate Tutorial -->
	ch.quest.Got_Pirate_Book.win_condition.l1 = "item";
	ch.quest.Got_Pirate_Book.win_condition.l1.character = ch.id;
	ch.quest.Got_Pirate_Book.win_condition.l1.item = "piratebook";
	ch.quest.Got_Pirate_Book.win_condition = "Got_Pirate_Book";
	// GR: Pirate Tutorial <--

/*	// Levis: Opium Smuggling -->
	ch.quest.Opium_set_first_ambush.win_condition.l1 = "item";
	ch.quest.Opium_set_first_ambush.win_condition.l1.character = ch.id;
	ch.quest.Opium_set_first_ambush.win_condition.l1.item = "opium";
	ch.quest.Opium_set_first_ambush.win_condition = "Opium_set_first_ambush";
	// Levis: Opium Smuggling <-- */

	// RM -->
	ch.wealth = 500; // PB: Players can use the cheatmode for this

	string sNat;
	for(int nat = 0; nat < NATIONS_QUANTITY; nat++) // KK
	{
		sNat = nat;
		ch.nations.(sNat).Rank = 0;
		ch.nations.(sNat).OldRank = 0;
	}
	ch.married = false;
	// RM <--
	ch.profile = GetCurrentProfile(GetStoryline(FindCurrentStoryline())); // PB: To be used in case this is lost
	ch.buildversion = BUILDVERSION; // 04-11-01 add build version, 05-03-25 set 12.2, 13; set back to 12.2 on 05-07-15
	ch.knbcannons = USE_REAL_CANNONS; // NK to handle KNB cannon switching 05-04-10

	ReloadProgressUpdate();
	// KK if(AUTO_SKILL_SYSTEM) InitAutoSkillsSystem(ch, false); // added by MAXIMUS [new skill-change]
	trace("Gauging: start NPC init");
	n = 1;
// KK -->
	n = CreateGameCharacters(n, "SideQuest"); ReloadProgressUpdate(); // PB: Initialize first so that all other files can override this
	n = CreateGameCharacters(n, "Officers"); ReloadProgressUpdate();  // PB: Initialize first so that all other files can override this
	n = CreateGameCharacters(n, "FalaiseDeFleur"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Redmond"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "IslaMuelle"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Oxbay"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Conceicao"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Douwesen"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "QuebradasCostillas"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Turks"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Hispaniola"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Cayman"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Guadeloupe"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Cuba"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Antigua"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "SaintMartin"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Aruba"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Curacao"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Eleuthera"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Colombia"); ReloadProgressUpdate();	
	n = CreateGameCharacters(n, "IslaMona"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Story"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "TempQuest"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "TempQuestEnemy"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "FortCommandants"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Usurers"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "StreetMerchants"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "StoreOwners"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "TActors"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "NK"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "Ship"); ReloadProgressUpdate();
	n = CreateGameCharacters(n, "DockyardOwners"); ReloadProgressUpdate(); // Estharos new file 
	n = CreateGameCharacters(n, "Taverns"); ReloadProgressUpdate(); // Estharos new file

	n = CreateCommonQuestCharacters(n);
	ReloadProgressUpdate();
// <-- KK
	trace("Gauging: done NPC init");
	// NK <--
// added by MAXIMUS -->
	/*n = CreateShipCharacters(n);
	ReloadProgressUpdate();*/
	CHARACTERS_QUANTITY = n; // NK 05-04-05 use int. // KK
	trace("::Completing characters initialisation - CHARACTERS_QUANTITY = "+CHARACTERS_QUANTITY+"::");
	ReloadProgressUpdate();
// added by MAXIMUS <--
	//Trace("NChar: " + n);

	CreateOtherCharacters();

	ReloadProgressUpdate();

	if(GetMainCharacterIndex()>=0)
	{
		SetMainCharacterIndex(GetMainCharacterIndex());
	}

	SetAllShipData(); // PB: If we make sure this is done FIRST, then it shouldn't need to occur in mid-game anymore
	SetAllFellows();  // PB: Just in case

		//Post init
	// do in PostInit()
	DoCharactersPostInit();
	/*for(n=0; n<TOTAL_CHARACTERS; n++)
		{
			// move to bottom as Character_PostInit(int n);
		}*/
	trace("Gauging: done second pass through char array");

	ReloadProgressUpdate();
	//LanguageCloseFile(tmpNameFileID);
}

void SetAllShipData()
{
	for(int i=0;i<CHARACTERS_QUANTITY;i++) // NK 05-04-05 use CHARACTERS_QUANTITY.
	{
		SetBaseShipData(GetCharacter(i));
	}
}

void SetAllFellows()
{
	ref rcc;
	for(int i=0;i<CHARACTERS_QUANTITY;i++) // NK 05-04-05 use CHARACTERS_QUANTITY
	{
		rcc = GetCharacter(i);
		if(CheckAttribute(rcc,"fellows"))
		{
			SetBaseFellows(rcc);
		}
	}
}

// KK -->
void InitCharacter(ref ch)
{
	if (!CheckAttribute(ch, "name")) {
		ch.name = "";
		ch.old.name = "";
	}
	if (!CheckAttribute(ch, "lastname")) {
		ch.lastname = "";
		ch.old.lastname = "";
	}
	if (!CheckAttribute(ch, "sex")) ch.sex = "man";
	//Model data
	if (!CheckAttribute(ch, "model")) ch.model = "none";
	if (!CheckAttribute(ch, "model.entity")) ch.model.entity = "NPCharacter";
	if (!CheckAttribute(ch, "model.animation")) ch.model.animation = "";
	//Address
	if (!CheckAttribute(ch, "location")) ch.location = "none";
	if (!CheckAttribute(ch, "location.group")) ch.location.group = "";
	if (!CheckAttribute(ch, "location.locator")) ch.location.locator = "";
	if (!CheckAttribute(ch, "location.from_sea")) ch.location.from_sea = "";
	//Ship data
	if (!CheckAttribute(ch, "Ship.Type")) ch.Ship.Type = SHIP_NOTUSED_TYPE_NAME;//SHIP_LUGGER; // PS
	//Quest data
	if (!CheckAttribute(ch, "Dialog.CurrentNode")) ch.Dialog.CurrentNode = "First time";
	if (!CheckAttribute(ch, "Dialog.TempNode")) ch.Dialog.TempNode = ch.Dialog.CurrentNode;
	if (!CheckAttribute(ch, "quest")) ch.quest = "True";
	if (!CheckAttribute(ch, "quest.meeting")) ch.quest.meeting = "0";
	//Misc data
	if (!CheckAttribute(ch, "nation")) ch.nation = ENGLAND;
	if (!CheckAttribute(ch, "freeskill")) ch.skill.freeskill = 0;
	if (!CheckAttribute(ch, "rank")) ch.rank = 1;
	if (!CheckAttribute(ch, "reputation")) ch.reputation = REPUTATION_NEUTRAL;
	// battle hp
	if (!CheckAttribute(ch, "headModel")) ch.headModel = "capitan";
	if (!CheckAttribute(ch, "location.stime") || !CheckAttribute(ch, "location.etime")) {
		float stime = 6.0;
		float etime = 21.98333;
		if (CheckAttribute(ch, "location.stime")) stime = stf(ch.location.stime);
		if (CheckAttribute(ch, "location.etime")) etime = stf(ch.location.etime);
		LAi_SetLoginTime(ch, stime, etime);
	}
	if (!CheckAttribute(ch, "chr_ai.hp") || !CheckAttribute(ch, "chr_ai.hp_max")) {
		float hp = LAI_DEFAULT_HP;
		float hp_max = LAI_DEFAULT_HP_MAX;
		if (CheckAttribute(ch, "chr_ai.hp")) hp = stf(ch.chr_ai.hp);
		if (CheckAttribute(ch, "chr_ai.hp_max")) hp_max = stf(ch.chr_ai.hp_max);
		LAi_SetHP(ch, hp, hp_max);
	}
	if (!CheckAttribute(ch, "AbordageMode")) ch.AbordageMode = 1; // boal 05.09.03 officer need to go to abordage
	if (!CheckAttribute(ch, "isSoldier")) ch.isSoldier = false;
}

int CreateGameCharacters(int n, string name)
{
	string sl = GetStorylinePath(FindCurrentStoryline());
	string fname = name + ".c";
	string func = "Create" + name + "Characters";
	if (FindFile("PROGRAM\Characters\init", "*.c", fname) != "") {
		if (LoadSegment("Characters\init\" + fname)) {
			call func(&n);
			UnloadSegment("Characters\init\" + fname);
		}
	}
	if (FindFile("PROGRAM\" + sl + "Characters\init", "*.c", fname) != "") {
		if (LoadSegment(sl + "Characters\init\" + fname)) {
			call func(&n);
			UnloadSegment(sl + "Characters\init\" + fname);
		}
	}
	return n;
}

void AddGameCharacter(ref n, ref ch)
{
	int chridx, iNation;
	string model;
	ref chr;
	if (!CheckAttribute(ch, "id")) return;
	chridx = GetCharacterIndex(ch.id);
	if (chridx >= 0) {
		makeref(chr, Characters[chridx]);
	} else {
		makeref(chr, Characters[n]);
		chridx = n;
		n++;
	}
	DeleteAttribute(chr, "");
	CopyAttributes(chr, ch);
	chr.index = chridx;
	InitCharacter(chr);
	DeleteAttribute(ch, "");
	if (!CheckAttribute(chr,"quest.officerprice")) chr.quest.officerprice = 0;//PB
	if (isSoldier(chr) != UNKNOWN_NATION) {
		chr.model.uniform = chr.model;
		iNation = sti(chr.nation);
		model = "m" + sti(chr.model);
		if (iNation >= 0 && iNation < NATIONS_QUANTITY) model = Nations[iNation].fantomModel.(model);
		if (iNation == PERSONAL_NATION) model = characters[GetMainCharacterIndex()].Soldier.(model);
		SetModel(chr, model, chr.sex, chr.sex, 0.0, false);
		GiveSoldierWeapon(chr, iNation);	// ARF: Update Soldier Weapons
		// Baste: Strong Soldiers -->
	//	chr.rank = 11+GetDifficulty()*3+rand(6*GetDifficulty());	// Landlubber: between 14 and 20 - Swashbuckler: between 23 and 47
		// Baste: Strong Soldiers <--*/
	}
	if (chr.name == "" && chr.lastname == "") {
		SetRandomNameToCharacter(chr);
		chr.old.name = "";
		chr.old.lastname = "";
	}
	//We want some more variance in characters so give them all a random level.
	if(sti(chr.rank) < 2) chr.rank = rand(12 + GetDifficulty()*3);
	if(sti(GetStorylineVar(FindCurrentStoryline(), "RESET_HP")) < 1) ResetHP(chr); // PB: To initialize HP for character level + HP bonus
}
// <-- KK
