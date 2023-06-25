//Таблица слухов, и их состояние. "active" - слух включен в поле случаного выбора слуха, "passive" - слух исключен из поля
// NK -->
int MAX_RUMOURS = 0;
#define TOTAL_RUMOURS	256

object	Rumour[TOTAL_RUMOURS];

extern void SetStorylineRumours(ref i); // KK

void SetRumourDefaults(bool isreinit)
{
	int tmpLangFileID = LanguageOpenFile("rumour_strings.txt");
	// NK 04-08-30
	//save old states
	object oldstates;
	int i,j;
	string tmp;
	if(isreinit)
	{
		i = 0;
		for(j = 0; j < TOTAL_RUMOURS; j++)
		{
			if(CheckAttribute(&Rumour[j],"id"))
			{
				tmp = "r"+i;
				//GetAttribute method (unworking ATM): oldstates.savestates.(tmp) = Rumour[j].state;
				oldstates.(tmp).id = Rumour[j].id;
				oldstates.(tmp).state = Rumour[j].state;
				//trace(i + ": rumor " + Rumour[j].id + " has state " + Rumour[j].state);
				i++;
			}
		}
		oldstates.max = i;
	}
	//trace("total stated rumors: " + GetAttributesNum(oldstates));
	for(j = 0; j < TOTAL_RUMOURS; j++)
	{
		DeleteAttribute(&Rumour[j],"id"); // NK
		Rumour[j].text="";
		Rumour[j].state="inactive";
		Rumour[j].loc="";
		Rumour[j].chance = 0;
		Rumour[j].given = false;
	}

	//note most default chance are at 100. If you add a new rumor, you can experiment with a
	//chance of less than 100, for an uncommon rumor.
	//(trade rumors are 25)

	//if you give a rumor an ID it then counts as a quest rumor. If there are any quest rumors
	//available, and frnd() < QUESTRUM_CHANCE, POTC will be forced to choose one (even
	//if frnd()>, it may choose one normally...
	//if the qr hasn't been given yet, it's vs. QUESTRUM_UNGIVEN_CHANCE
	//also, if the rumor has an ID, you can set it active or inactive.
	//
	i = 0;
	//DEFAULT RUMOR:
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Nothing interesting happens lately. Life goes on smoothly. I wonder how long that'll last!");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100; //This one should always be in -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Come to think of it, I didn't really have any gossip.  I'm just so terribly, terribly lonely...");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100; // PB: No harm in variety
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"People say that some kind of aboriginal cemetery was found inside the Oxbay mine. A lot of bones, crockery, spikes and clay plates were found... but not a grain of gold!");
	Rumour[i].state = "active";
	Rumour[i].loc = "England";
	Rumour[i].chance = 35; //We should be sparse with this info -levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I tell you friend, piracy is a menace. They don't just steal your goods now, they steal your ship and sell their prisoners into slavery! If they don't kill them all first, of course. Why, I've heard they even use their prisoners for wagers! Gambling and piracy will be the death of our society, I tell you! Uh... you're not a pirate, are you?");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 50; //Lowered a bit -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Shh... well, friend, you looking for some good men or a good time? I hear there's an island way up north where the rum is cheap and the morals are cheaper... and there's always a few lads who'll sail through anything for a price.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Oxbay";
	Rumour[i].chance = 60; //Lowered a bit -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Why, I hear there are pirates on this very island, under our esteemed governor's very nose! Or under his chin, that is, or should I say chins. Anyhow, if you're looking for some things that... can't be bought in stores... or some lads who know better than to ask questions, that's where to look. But don't say I told you about it.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Douwesen";
	Rumour[i].chance = 70; //Lowered a bit -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Our governor is a fine gentleman, sir. Do you know he's already had three officials sent to prison for corruption? Used to be you'd run whenever you heard the soldiers coming... but now justice is a thing to be applauded, not feared. I hear he's already working on plans to clear out the vermin who live on the other end of the island...");
	Rumour[i].state = "active";
	Rumour[i].loc = "Conceicao";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"We live in a lawless age, captain. The jungles are swarming with villains, the seas are rife with pirates... What's an honest merchant to do? Hire an escort, I guess... And many are. Ask around in the tavern -- there's usually someone waiting for a brave captain to keep him safe.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 35; //we know this by now so not very likely it will show up -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, business as usual, captain. Which means piracy is rife as always. I hear our shopkeeper's looking for someone with a fast ship and plenty of grapeshot to carry his cargo.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 35; //We dont need this to happen that often -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, lord! Will our governor not do something about those gutless savages in the jungle whose only pastime is chasing down poor girls and having their way with them, and robbing travelers blind?! If I were younger I might do something myself... You learn a lot about swordfighting, beating up the refuse of humanity...");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 50; //Lowered a bit -Levis
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Have you heard about the latest form of pirate? This one walks on land, you see: he's called a loanshark, and he's worse than a leech. If you need quick money, great -- but God help you if you don't pay on time. My own brother, he once...");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 20; //Shouldn't be in there to often -Levis
	i++;
	Rumour[i].id = "Smuggle_TOR_start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear tell our shopkeeper, Mr. O'Reilly... Well, he's fallen on hard times and he takes a few more chances than he used to with the law. But for you, that might be a plus. I'm sure he'd be happy to meet a captain.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Redmond";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Toff";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, did you hear about poor Toff Oremans and his daughter? She took up with a pirate, which is bad enough... but now she's disappeared! Her father's inconsolable... you'll probably find him at the Douwesen tavern, drowning his sorrows away...");
	Rumour[i].state = "active";
	Rumour[i].loc = "Douwesen";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Clair_start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear tell Claire Larrouse arrived in the town recently. They say she is making up a crew for her new expedition. She's a famous captain and I'm sure anything she's involved in, gold is not far behind.");
	Rumour[i].state = "active";
	Rumour[i].loc = "IslaMuelle";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Ship_off_FDF";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, it is terrible! There's a commerce raider sitting right off our shores, just waiting for a juicy merchantman to snatch. The governor's been trying to find someone to deal with her once and for all... Perhaps you could help?");
	Rumour[i].state = "active";
	Rumour[i].loc = "FalaiseDeFleur";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Children_start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"The latest news? Why, everyone in the archipelago is talking about it! Children snatched from their cradles, a giant black ship more terrible than the devil himself sinking everything it meets... and even the priests in Redmond have heard about it! I hear it all started on Douwesen...");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Children_GreenChurch"
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, I hear the vicar's very worried about things over in Greenford... You look like a captain, perhaps you could help him?");
	Rumour[i].state = "active";
	Rumour[i].loc = "Redmond";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Church_woman_FDF";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, did you hear about that poor woman who lost her husband, and now is like to lose her son? The priest is very worried about her...");
	Rumour[i].state = "active";
	Rumour[i].loc = "FalaiseDeFleur";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Hitman_start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"We live in lawless times, captain. Not only are there pirates on the seas and raiders in the jungles, but also assassins in our very towns! It must stop, captain! Why, just the other day, at the tavern...");
	Rumour[i].state = "inactive";
	Rumour[i].loc = "Conceicao";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Lucas"; // KK
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, have you heard about poor Admiral da Saldanha? He comes all the way from Old Spain to the New World to be with his son... and he arrives to find his son missing! I am sure you would earn his undying gratitude, and that of the governor, if you could but help him.");
	Rumour[i].state = "active";
	Rumour[i].loc = "IslaMuelle";
	Rumour[i].chance = 100;
	i++;
	
	//Add hint for telescope by levis -->
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"People seem to agree that those who are generous to the church sometimes get rewarded with a very special gift. People are more divided on what this gift actually is.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100;
	i++;
	
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"People say someone went in the old church in Bridgetown but he never came out. I wonder what is keeping him there.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Oxbay";
	Rumour[i].chance = 100;
	i++;
	//levis <--

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I once talked to a drunk who said he found a hidden cave in Oxbay port.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Oxbay";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "crys_skull";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"It's alright for some people! That researcher who moved in almost next door to the governor of Santo Domingo. Odd fellow - interested in skulls, it's said.");
	Rumour[i].state = "active";
	Rumour[i].loc = "Hispaniola";
	Rumour[i].chance = 100;
	i++;

	if (IsBrothelEnabled()) {
		Rumour[i].text = LanguageConvertString(tmpLangFileID,"I heard tell of a house of ill repute in some towns: Quebradas Costillas, Charlestown, Pointe a Pitre, Eleuthera, Alice Town and Tortuga, to name a few. Keep away from establishments ran by devil as God's punishment will be severe!"); 
		Rumour[i].state = "active";
		Rumour[i].loc = "all";
		Rumour[i].chance = 50; //Doesn't have to be 100 -Levis
		i++;
	}

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"It is said an apothecary moved into Greenford. And if you like opium, there should be an opium den somewhere in Redmond...");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100; //This one should happen moreoften too
	i++;

    Rumour[i].text = LanguageConvertString(tmpLangFileID,"An old sailor told me he is considering retiring. The weather gets quite nasty in the colder months, storms and such. He said if he can't find a sturdier ship to sign on with before next autumn, he won't risk another stormy season at sea."); // Morgan Terror
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 50; //Lowered a bit -Levis
	i++;

    Rumour[i].text = LanguageConvertString(tmpLangFileID,"I heard a captain in the tavern say that he prefers winter weather to summer, despite the storms. In the summer, there is nary a breeze. Wonderful stuff in my opinion, but I'd imagine it'd be frustrating for a captain with a schedule to keep."); // Morgan Terror
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 50; //Lowered a bit -Levis
	i++;

    Rumour[i].text = LanguageConvertString(tmpLangFileID,"Hear about ol' Willie? Ran his brig across a mine in pitch darkness. Never seen again, just like me dad when he capsized. Sea's claimed many around here."); // Morgan Terror
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25; //Lowered a bit -Levis
	i++;

    Rumour[i].text = LanguageConvertString(tmpLangFileID,"Oh, you can see those storms coming from miles away in these parts. 30 knot wind's all it takes. I'd hate to be out at sea when that happens."); // Morgan Terror
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 75; //Lowered a bit -Levis
	i++;

    Rumour[i].text = LanguageConvertString(tmpLangFileID,"They say there's an island around these parts, somewhere to the south. Or southwest. Or maybe even southeast. In any case, it's supposedly filled with treasure, but the tricky bit's actually finding it."); // Morgan Terror
    Rumour[i].state = "active";
	Rumour[i].loc = "Cuba";
	Rumour[i].chance = 35; //Lowered a bit -Levis
	i++;
	
	//Added by Levis -->
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Recently a library has been opened on the island of Turks. No books yet.");
	if(ALLOW_LOCKED_PERKS) Rumour[i].text = LanguageConvertString(tmpLangFileID,"Recently a library has been opened on the island of Turks.");
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 80;
	i++;
	
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"A new trader has moved to Oranjestad. He seems to be from the spanish main and looks a bit different but for now he seems to be selling very familiar items. I hope someday soon he will sell some special items also.");
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 80;
	i++;
	
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"There seem to be new offices in Port Royal, Bridgetown and Willemstad. I wonder what these offices are for.");
    Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 80;
	i++;
	
	//Added by Levis <--

	//Levis disabled all trade rumours, names are old and won't have much use anymore after dynamic economy is implemented
	//start trade rumors, from Donalbane
	/*Rumour[i].text = LanguageConvertString(tmpLangFileID,"You can always make a pretty penny taking Rum from Oxbay to either Falaise de Fleur or Conceicao, provided you don't drink it all on the way there!");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I've heard old pirates say that the only things worth bringin' to Quebradas Costillas is Coffee from Douwesen and Clothing from Redmond.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;
	
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear a man can make money moving Fruit from Conceicao to Douwesen.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear there's money to be made in ferrying Leather and Fruit from Conceicao to Oxbay.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear there's profit to be made in shipping Cinnamon from Conceicao to Redmond.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear you can make a fortune shipping Sandal and Tobacco from Oxbay to Redmond.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I've seen men make fortunes in running Sandal and Cinnamon from Isla Muelle to Redmond.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I have an uncle who got rich running Clothing from Redmond to Falaise de Fleur.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 15;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Shrewd businessmen take Silk from Falaise de Fleur to Redmond.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"My brother, a merchant, says you can't go wrong ferrying Chocolate from Falaise de Fleur to Conceicao.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Don't let anyone tell you can't make money from carrying Coffee from Douwesen to Conceicao.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I hear moving Coppera from Douwesen to Redmond is a sure path to profit.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25;
	i++;

	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I've heard it said that ferrying Ebony from Isla Muelle to Falaise de Fleur is always a wise decision.");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 25;
	i++;*/

// KK -->
	LanguageCloseFile(tmpLangFileID);

	if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()), "*.*", "Rumour_Data.c") != "") {
		if (LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "Rumour_Data.c")) {
			SetStorylineRumours(&i);
			UnloadSegment(GetStorylinePath(FindCurrentStoryline()) + "Rumour_Data.c");
		}
	}
// <-- KK

	//end defined rumors
	MAX_RUMOURS = i;

	// Restore old states
	if(isreinit)
	{
		/*GetAttribute method, unworking ATM:
		aref tmpattr;
		makearef(tmpattr, oldstates.savestates);
		for(j=0; j < GetAttributesNum(tmpattr); j++)
		{
			Rumour[GetRumourIndex(GetAttributeName(GetAttributeN(tmpattr, j)))].state = GetAttributeValue(GetAttributeN(tmpattr, j));
			trace("rumor " + GetAttributeName(GetAttributeN(oldstates, j)) + " with state " + GetAttributeValue(GetAttributeN(tmpattr, j)) + "restored");
		}*/
		for(i = 0; i < sti(oldstates.max); i++)
		{
			tmp = "r" + i;
			Rumour[GetRumourIndex(oldstates.(tmp).id)].state = oldstates.(tmp).state;
			//trace("Restore " + i + ": rumor " + oldstates.(tmp).id + " had state " + oldstates.(tmp).state);
		}
	}
}
// NK <--
