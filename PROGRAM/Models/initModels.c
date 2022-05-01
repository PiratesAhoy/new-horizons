//Estharos: Complete reassignment of all Models March-April, 2009
//Estharos: Rearange the code to match the GM viewer for easier search
//Estharos: Special thanks to Thomas the Terror, Sir Christopher Mings, The Lunatic Wolf, NK, Damski62, MAXIMUS, LHD, pirate_KK, CatalinaThePirate, Petros, Alan Smithee, Kazeite and PB for working on those codes (sorry if I miss anyone)
//MAXIMUS: IMPORTANT! Model, whose ID contains numbers, will not be shown in BuildSettingsModelsScroll
//MAXIMUS: if you want to add such model into BuildSettingsModelsScroll, use this attribute: model.skipcheck = true

void InitModels(bool isstart)
{
	int n;
	ref model;
	object tmpModel;

	int period = GetCurrentPeriod(); // PB

	for(n = 0; n < MAX_MODELS; n++)
	{
		makeref(model,Models[n]);
		DeleteAttribute(&model, ""); // NK just in case 05-07-02
		model.id = "blank";		// NK so we can use native finds.
		model.index		=  n;
		model.model		=  DEFAULT_MODEL;
		model.FaceId		= DEFAULT_FACEID;
		model.assigned	 =  false;
		model.description  =  "";
		model.minlevel	 =  0;
		model.minrank	  =  0;
		model.nation	   =  ALL_NATIONS;
		model.price		=  10;
		model.sex		  =  "man";
		model.ani		  =  "man";
		model.height	   =  1.8;
		model.iscombat = true;
	}
	DeleteAttribute(&ModelSubTypes,"");
	/*for(i = 0; i < 512; i++)
	{
		ref modeltype; makeref(modeltype, ModelTypes[i]);
		DeleteAttribute(&modeltype, "");
		//DeleteAttribute(&modeltype, "types");
		modeltype.id = "0";
		modeltype.index = i;
	}*/
	MODELTYPES_QUANTITY = 0;
	InitModelTypesArray();

	// Set model subtypes based on primary types. BE CAREFUL WITH SPELLING
	// Note the nation designations: they must be identical with Nations[<nation_idx>].name attribute, or BROKEN & ALL_NATIONS.
	// Note the chances. They are (previous item's chance) + (chance of this type) = (chance that we write for this type).
	// Thus the chances must end at 1.0.

	// Vagabonds
	ModelSubTypes.Vagabonds.Poor_Citizens = 0.1;
	ModelSubTypes.Vagabonds.Lower_Citizens = 0.45;
	ModelSubTypes.Vagabonds.Middle_Citizens = 0.60;
	ModelSubTypes.Vagabonds.Upper_Citizens = 0.65;
	ModelSubTypes.Vagabonds.Sailors = 0.97;
	ModelSubTypes.Vagabonds.Rich_Citizens = 1.0;

	// Bandits
	ModelSubTypes.Bandits.Poor_Citizens = 0.5;
	ModelSubTypes.Bandits.Sailors3 = 1; // 0.5 for this

	// Raiders
	ModelSubTypes.Raiders.Poor_Citizens = 0.35;
	ModelSubTypes.Raiders.Sailors = 0.55;
	ModelSubTypes.Raiders.Sailors3 = 0.75;
	ModelSubTypes.Raiders.Outlaws = 1;

	// Pirate_Citizens
	ModelSubTypes.Pirate_Citizens.Poor_Citizens = 0.15;
	ModelSubTypes.Pirate_Citizens.Lower_Citizens = 0.3;
	ModelSubTypes.Pirate_Citizens.Sailors = 0.7; //0.45; // about equal weighting to sailors and pirates, so we don't need to do sailors3
	//ModelSubTypes.Pirate_Citizens.Sailors3 = 0.7; // pirate sailors
	ModelSubTypes.Pirate_Citizens.Mates = 0.85; //0.75;
	//ModelSubTypes.Pirate_Citizens.Mates3 = 0.85; // pirate mates
	ModelSubTypes.Pirate_Citizens.Captains = 1.0; //0.9;
	//ModelSubTypes.Pirate_Citizens.Captains3 = 1; // pirate captains
	//ModelSubTypes.Pirate_Citizens.natmask = GetNationString(PIRATE); // if model can't be pirate, can't be used.
	// Smugglers = Pirate_Citizens for now...

	// Smugglers -- mostly pirate citizens, but with less chance for civilians. Use for Pirate Soldiers too?
	ModelSubTypes.Smugglers.Poor_Citizens = 0.1;
	ModelSubTypes.Smugglers.Lower_Citizens = 0.15;
	ModelSubTypes.Smugglers.Sailors = 0.65; //0.45;
	ModelSubTypes.Smugglers.Mates = 0.9; //0.75;
	ModelSubTypes.Smugglers.Captains = 1.0; //0.9;

	// Jungle women (i.e. for rapers encounter)
	ModelSubTypes.Jungle_Women.Lower_Citizens = 0.42;
	ModelSubTypes.Jungle_Women.Middle_Citizens = 0.72;
	ModelSubTypes.Jungle_Women.Upper_Citizens = 0.92;
	ModelSubTypes.Jungle_Women.Rich_Citizens = 1.0;
	
	// Jungle defector ( DeathDaisy: for revised rapers encounter)
	ModelSubTypes.Jungle_Defector.Poor_Citizens = 0.3;
	ModelSubTypes.Jungle_Defector.Lower_Citizens = 0.5;
	ModelSubTypes.Jungle_Defector.Sailors = 0.7;
	ModelSubTypes.Jungle_Defector.Mates = 1;

	// Start Model define section:
	MODEL_HIGH = 0;
	makeref(model, tmpModel);
	InitCharacterModel(model);

	//The code above this comment HAVE TO be before all model definitions.
	//Please insert new models after this comment.

	// High Sea Lass -->
	model.description =  "Hailing from Africa, she now seeks freedom in the New World.";
	model.id          =  "33_Affrica";
	model.FaceId      =  226;
	model.nation      =  ENGLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	AssignModelType(isstart, model, "women", 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description  =  "This lady may not swing her hips, but one fellow who implied she would not be all woman ended up impaled on her cutlass.";
	model.id	  =  "33_Blazie";
	model.FaceId	= 221;
	model.nation	  =  PIRATE;
	model.price	  =  2000;
	model.assigned	  =  true;
	model.sex	  =  "woman";
	model.ani	  =  "33_Blazie";
	model.height	  =  1.65;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// assign as captain only -->
	model.description =  "This platinum blonde is not one to mess with, for she is as cool as her icy eyes.";
	model.id       =  "33_Piratess10";
	model.FaceId	= 224;
	model.nation      =  PIRATE;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "33_Piratess10";
	model.height      =  1.75;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->   
	model.description =  "Piratess with a stylish purple coat.";
	model.id	= "HildaPiratess";
	model.FaceId	= 538;
	model.nation = FRANCE;
	if(SWEDEN_ALLOWED) model.nation = SWEDEN;
	model.price		= 2000;
	model.assigned	= true;
	model.sex		= "woman";
	model.ani		= "33_Piratess10";
	model.height	= 1.75;
	model.name		= "Hilda";
	model.lastname	= "Sparre";
	model.storytitle	= "The Road Back to Greatness";
	model.storytext	= "You are a noblewoman, part of Sweden's most ancient nobility, but the reign of Charles XI had come with ever diminishing power and privilege. Conspiring to take back what was lost, you instead found yourself on the run from a death sentence. With nowhere else to go and hunted by the state, you fled to the New World.";
	model.playertype	= PLAYER_TYPE_REBEL;
	model.difficulty	= DIFFICULTY_MARINER;
	model.Flags.Pirate	= 19;
	model.Flags.Personal = 43;
	model.ship		= "Lugger1";
	model.shipname	= "Kråkan";
	model.date.hour	= 7;
	model.date.day	= 24;
	model.date.month	= 10;
	model.date.year	= 1674;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only
	
	// no model assignment quest character -->
	model.description	=  "Ciri. Monster Hunter, dimension traveller and proud owner of a unicorn.";
	model.id			=  "CiriWitcher";
	model.FaceId		=  568;
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex			=  "woman";
	model.ani		=  "woman_sit";
	model.name 			=  "Ciri";
	model.lastname = "Riannon";
	model.shipname = "Little Horse";
	AddCharacterModel(model);
	// <-- no model assignment quest character
	
	model.description =  "His name was Geralt of Rivia, he was a Witcher, a professional monster slayer and the adoptive father of Ciri Riannon.";
	model.id	   =  "Geralt";
	model.FaceId	= 585;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Geralt";
	model.lastname = "of Rivia";
	model.Flags.Pirate = 0;
	model.Flags.Personal = 45;
	model.loadingScreen = "Quest_Geralt.tga";
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.storytitle = "Travelling Worlds";
	model.storytext = "Take the role of Geralt of Rivia, a Witcher. A mutant, trained to kill monsters since childhood. Thrust into a different world and separated from your loved ones, you now search for your daughter in the Caribbean. Whether you find her or not, is a mystery...";
	model.ship = "Lugger1";
	model.shipname = "Roach";
	model.date.day = 16;
	model.date.month = 6;
	model.date.year = 1754;
	AddCharacterModel(model);
	
	// DeathDaisy: Morgen - Quest Character
	model.description	=	"A pale witch in a black dress who probably does not get enough sleep.";
	model.id			=	"witchgirl";
	model.FaceId	= 540;
	model.nation	= FRANCE;
	model.price		= 5000;
	model.assigned	=	true;
	model.height	=	1.75;
	model.name = "Morgen";
	model.lastname = "le Fay";
	model.playertype	= PLAYER_TYPE_ADVENTURER;
	model.ship = "Tartane1";
	model.shipname = "Myrddin";
	model.sex	=	"woman";
	model.ani	=	"woman_sit";	
	AddCharacterModel(model);

	model.description = "This elegant green dress is studded with pearls and trimmed with lace.";
	model.id	= "Lady04_ab";
	model.FaceID	= 580;
	model.nation	= ENGLAND;
	model.price	= 10000;
	model.assigned	= true;
	model.sex	= "woman";
	model.ani	= "woman_ab_PoTC";
//	model.status	=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.height	= 1.75;
	model.ismansion		=  true;//Pretty woman, must be a governor's niece or wife
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "He's big, he's bad, and he can out-drink anyone!";
	model.id	=  "33_Ronal2";
	model.FaceId	= 225;
	model.nation	=  PIRATE;
	model.price	=  2000;
	model.assigned	=  true;
	model.ani	=  "33_Ronald";
	model.height	=  2.10;
	model.name	= "Ron";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "He's big, he's bad, but most of all he is loyal to those who deserve it.";
	model.id       =  "33_Ronald";
	model.FaceId	= 225;
	model.nation      =  PIRATE;
	model.price       =  1500;
	model.assigned    =  true;
	model.ani         =  "33_Ronald";
	model.height      =  2.10;
	model.name = "Ronald";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "A town girl that got a taste of adventure and threw her skirt aside to sail the seven seas.";
	model.id       =  "33_TG5D";
	model.FaceId	= 222;
	model.nation      =  ENGLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);
	// <-- High Sea Lass

	// TALISMAN - INSERTING MISSING ENTRIES --- >
	model.description =  "Forget the dreadlocks! Give me a ponytail, and a nicely goldtrimmed uniform of a British Admiral!";
	model.id	   =  "47_Admsparrow";
	model.FaceId	= 229;
	model.minlevel     =  16;
	model.minrank	 =  8;
	model.nation	  =  ENGLAND;
	model.price	   =  15000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the nicely goldtrimmed uniform of a British Admiral!";
	model.id	   =  "47_Blaze_brtadm";
	model.FaceId	= 229;
	model.minlevel     =  16;
	model.minrank	 =  8;
	model.nation	  =  ENGLAND;
	model.price	   =  15000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the nicely goldtrimmed uniform of a British Commodore!";
	model.id	   =  "47_Blaze_brtco";
	model.FaceId	= 227;
	model.minlevel     =  14;
	model.minrank	 =  7;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the nicely goldtrimmed uniform of a British Captain!";
	model.id	   =  "47_Blaze_brtcpt";
	model.FaceId	= 228;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the uniform of a British Naval Lieutenant.!";
	model.id	   =  "47_Blaze_brtlt";
	model.FaceId	= 227;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the uniform of a French Naval Officer!";
	model.id	   =  "47_Blaze_france";
	model.FaceId	= 16;
	model.nation	  =  FRANCE;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the uniform of a Spanish Naval Officer!";
	model.id	   =  "47_Blaze_spain";
	model.FaceId	= 16;
	model.nation	  =  SPAIN;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Forget the dreadlocks! Give me a ponytail, and the uniform of an EITC Officer!";
	model.id	   =  "47_Sparrow_Eitc_cpt";
	model.FaceId	= 356;
	model.nation	  =  ENGLAND;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Forget the dreadlocks! Give me a ponytail, and the uniform of an French Naval Officer!";
	model.id	   =  "47_Sparrow_france";
	model.FaceId	= 275;
	model.nation	  =  FRANCE;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the uniform of an EITC captain!";
	model.id	   =  "47Blaze_Eitc_cpt";
	model.FaceId	= 356;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Nathaniel has the uniform of an EITC lieutenant!";
	model.id	   =  "47Blaze_Eitc_lt";
	model.FaceId	= 355;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);
	// <----- TALISMAN - INSERTING MISSING ENTRIES

	model.description =  "Forget the dreadlocks! Give me a ponytail, and a nicely goldtrimmed uniform of a British Commodore!";
	model.id	   =  "47_Cosparrow";
	model.FaceId	= 227;
	model.minlevel     =  14;
	model.minrank	 =  7;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Forget the dreadlocks! Give me a ponytail, and a nice uniform of a British Captain!";
	model.id	   =  "47_Cptsparrow";
	model.FaceId	= 228;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Jack Sparrow in a goldtrimmed commodores uniform. Shiny!";
	model.id	   =  "47_Jack_brt_co";
	model.FaceId	= 357;
	model.minlevel     =  14;
	model.minrank	 =  7;
	model.nation	  =  ENGLAND;
	model.price	   =  1200;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Jack Sparrow in a nice british captains uniform. Looks real dashing!";
	model.id	   =  "47_Jack_brt_cpt";
	model.FaceId	= 356;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  700;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "Jack Sparrow as a young promising lieutenant.";
	model.id	   =  "47_Jack_brt_lt";
	model.FaceId	= 355;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  300;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "I feel a bit pale and skinny, and my dreadlocks are grey! Sorry mate, couldn't resist!";
	model.id	   =  "47_Jack_Skel";
	model.FaceId	= 232;
	model.nation	  =  PIRATE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AddCharacterModel(model);

	model.description =  "Forget the dreadlocks! Give me a ponytail, and a nice uniform of a British Lieutenant!";
	model.id	   =  "47_Ltsparrow";
	model.FaceId	= 229;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "I've ended up as a rum-potting deckhand that takes orders from pirates, have you anything that can express that?.";
	model.id	   =  "47_Norrington_Pirate";
	model.FaceId	= 230;
	model.nation	  =  PIRATE;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description = "Jack as a Spanish Captain";
	model.id 	= "47_Sparrow_spain";
	model.FaceId 	= 57;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  SPAIN;
	model.price 	= 4000;
	model.assigned 	= true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description = "Jack as an EITC Lieutenant";
	model.id 	= "47_Sparrow_Eitc_lt";
	model.FaceId 	= 57;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price 	= 4000;
	model.assigned 	= true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);

	model.description =  "Jack Sparrow as a young promising merchant captain. Looks like a real gentlemen to me.";
	model.id	   =  "47YoungJack";
	model.FaceId	= 358;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.difficulty = DIFFICULTY_MARINER;
	model.ship = "WickedWench";
	model.shipname = "Wicked Wench";
	model.Flags.Pirate = 6;
	model.Flags.Personal = 21;
	model.date.year = 1730;
	AddCharacterModel(model);

	// Hornblower Quest SJG -->
	model.description =  "I want to join the 95th and I can afford to buy a sergeancy.";
	model.id	   =  "SharpeS_Rif8_18";
	model.FaceId	= 449;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 95th and I can afford to buy a commission.";
	model.id	   =  "SharpeL_Rif7_18";
	model.FaceId	= 450;
	model.nation	  =  BROKEN;
	model.price	   =  3000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to be a major in the 95th and I can afford to buy a commission.";
	model.id	   =  "Dunnitt_Rif7_18";
	model.FaceId	= 451;
	model.nation	  =  BROKEN;
	model.price	   =  5000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 33rd.";
	model.id	   =  "Soldier_Eng7_18";
	model.FaceId	= 567;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 33rd.";
	model.id	   =  "HarperR_Eng3_18";
	model.FaceId	= 453;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 95th as an unruly rifleman.";
	model.id	   =  "Rifleman_Harper";
	model.FaceId	= 454;
	model.nation	  =  BROKEN;
	model.price	   =  800;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Higgins_Eng2_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "CooperR_Eng6_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Haggman_Eng5_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "HarrisRed_Eng5_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Mansfld_Eng6_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Perkins_Eng6_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95A3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95B3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95B4_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95C3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95D3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95E3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rifleman95F3_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RiflemanBake_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RiflemanPerk_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "TongueR_Eng6_18";
	model.FaceId	= 452;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 95th as a Sergeant.";
	model.id	   =  "Harper_Sergeant";
	model.FaceId	= 455;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a captaincy.";
	model.id	   =  "PellewX_18";
	model.FaceId	= 456;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a captaincy.";
	model.id	   =  "SawyerX_18";
	model.FaceId	= 457;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a sea captaincy.";
	model.id	   =  "Sawyer2_18";
	model.FaceId	= 458;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a captaincy.";
	model.id	   =  "KeeneCX_18";
	model.FaceId	= 459;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want a British Admirals uniform.";
	model.id	   =  "KeeneAD_18";
	model.FaceId	= 459;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a Colonel's Uniform.";
	model.id	   =  "WellR_eng_18";
	model.FaceId	= 460;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Hornblower.";
	model.id	   =  "brtmdsH_18";
	model.FaceId	= 461;
	model.minrank     =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "Horatio";
	model.lastname = "Hornblower";
	model.loadingScreen = "Quest_Hornblower.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 25;
	model.ship = "PO_Hoy";
	model.shipname = "Caroline";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 18;
	model.date.month = 6;
	model.date.year = 1798;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Hornblower.";
	model.id	   =  "brtH3rdLt_18";
	model.FaceId	= 462;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "Horatio";
	model.lastname = "Hornblower";
	model.loadingScreen = "Quest_Hornblower.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 25;
	model.ship = "FR_Sloop";
	model.shipname = "Le Rève";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 18;
	model.date.month = 6;
	model.date.year = 1798;
	AddCharacterModel(model);

	model.description =  "I want to look like Commander Hornblower.";
	model.id	   =  "brtHComdr_18";
	model.FaceId	= 463;
	model.minlevel     =  10;
	model.minrank     =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  3000;
	model.assigned	=  true;
	model.name = "Horatio";
	model.lastname = "Hornblower";
	model.loadingScreen = "Quest_Hornblower.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 25;
	model.ship = "HMS_Greyhound";
	model.shipname = "Atropos";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 18;
	model.date.month = 6;
	model.date.year = 1798;
	AddCharacterModel(model);

	model.description =  "I want to look like Captain Horatio Hornblower, R.N.";
	model.id	   =  "brtHCap_18";
	model.FaceId	= 463;
	model.minlevel     =  15;
	model.minrank     =  6;
	model.nation	  =  ENGLAND;
	model.price	   =  7000;
	model.assigned	=  true;
	model.name = "Horatio";
	model.lastname = "Hornblower";
	model.loadingScreen = "Quest_Hornblower.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 25;
	model.ship = "RN_Essex";
	model.shipname = "Lydia";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 18;
	model.date.month = 6;
	model.date.year = 1798;
	AddCharacterModel(model);

	model.description =  "I want to look like Lady Barbara Wellesley.";
	model.id	=  "Lady_Barbara_Wellesley";
	model.FaceId	= 117;
	model.nation	=  BROKEN;
	model.price	=  3000;
	model.assigned	=  true;
	model.sex	= "woman";
	model.ani	= "woman_ab_PoTC";
	model.height	= 1.75;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Bush.";
	model.id	   =  "BushLtn_18";
	model.FaceId	= 464;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Kennedy.";
	model.id	   =  "Kennedy_Md";
	model.FaceId	= 465;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Kennedy.";
	model.id	   =  "Kennedy_Lt";
	model.FaceId	= 466;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Simpson.";
	model.id	   =  "Simpson_18";
	model.FaceId	= 467;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Clayton.";
	model.id	   =  "Clayton_18";
	model.FaceId	= 468;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Wellard.";
	model.id	   =  "Wellard_18";
	model.FaceId	= 469;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Hammond.";
	model.id	   =  "JackHammond";
	model.FaceId	= 91;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Midshipman Hunter.";
	model.id	   =  "HunterM_18";
	model.FaceId	= 470;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Buckland.";
	model.id	   =  "Bucklnd_18";
	model.FaceId	= 471;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Bracegirdle.";
	model.id	   =  "Bracegrdle";
	model.FaceId	= 472;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Quelp.";
	model.id	   =  "LtQuelp_18";
	model.FaceId	= 473;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to look like Lieutenant Eccleston.";
	model.id	   =  "EcclestonH";
	model.FaceId	= 474;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want the other commanders outfit.";
	model.id	   =  "BracegrdlC";
	model.FaceId	= 475;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to join the 95th as a rifleman.";
	model.id	   =  "Rifleman95F3_18";
	model.FaceId	= 476;
	model.nation	  =  BROKEN;
	model.price	   =  800;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want a British Admirals uniform.";
	model.id	   =  "PellewA_18";
	model.FaceId	= 477;
	model.nation	  =  BROKEN;
	model.price	   =  5000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to be a captain in the 95th and I can afford to buy a commission.";
	model.id	   =  "Cmurray_Rif7_18";
	model.FaceId	= 478;
	model.nation	  =  BROKEN;
	model.price	   =  3000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want the Civilian Hornblower.";
	model.id	   =  "CivilianHB";
	model.FaceId	= 479;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase a tough captaincy.";
	model.id	   =  "Hammond_18";
	model.FaceId	= 480;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A Royal Navy Post-Captain's uniform.  Broke wore something like this when he stopped them singing Yankee Doodle dandee-oh.";
	model.id          =  "BrtcptH_18";
	model.FaceId      =  116;
	model.minlevel     =  12;
	model.minrank     =  6;
	model.nation      =  BROKEN;
	model.price       =  7000;
	model.assigned    =  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase Captain Foster's uniform.";
	model.id	   =  "Foster1_18";
	model.FaceId	= 481;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase Styles' uniform.";
	model.id	   =  "StylesHB";
	model.FaceId	= 118;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase Wolfe's uniform.";
	model.id	   =  "WolfHB";
	model.FaceId	= 115;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I wish to purchase Wolfe's uniform.";
	model.id	   =  "WolfFrench";
	model.FaceId	= 115;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I feel like Mr. Matthews today.";
	model.id	   =  "MatthewsHB";
	model.FaceId	= 483;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I feel like Mr. Oldroyd today.";
	model.id	   =  "OldroydHB";
	model.FaceId	= 88;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "I am descended from the Conquistadors and from Montezuma! You will call me El Supremo if you value your life!";
	model.id		=  "El_Supremo";
	model.FaceId		=  "482";
	model.nation		=  SPAIN;
	model.price		=  10000;
	model.assigned		=  true;
	model.name = "Don Julian";
	model.lastname = "Alvarado";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// <--- Hornblower Quest SJG

	// Petros -->
	model.description =  "Beauty with eyes as green as emeralds and hair as red as blood.";
	model.id       =  "50__Aine";
	model.FaceId	= 174;
	model.nation      =  HOLLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Aine";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "Don't let her beauty deceive you, she's a Pirate Captain.";
	model.id	=  "50_33_40Claire";
	model.FaceId	= 176;
	model.nation	=  PIRATE;
	model.price	=  2000;
	model.assigned	=  true;
	model.sex	=  "woman";
	model.ani	=  "man_woman_sit";
	model.height	=  1.75;
//	model.name = "Claire";
//	model.lastname = "Larrouse";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "As skilled with the sword as she is beautiful, they call her Borinqueña";
	model.id       =  "50_33Petra";
	model.FaceId	= 175;
	model.nation      =  SPAIN;
	model.price       =  2000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Petra";
	model.lastname = "Borinqueña";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description = "Here is a governor's daughter, who wants to go to sea.";
	model.id	  = "50_Becka";
	model.FaceId	  = 183;
	model.nation      =  HOLLAND;
	model.price       =  2000;
	model.sex         = "woman";
	model.ani         = "woman_sit";
	model.height      =  1.75;
	model.assigned    =  true;
	model.name = "Becka";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	= "A shopkeeper's daughter has run away to sea.";
	model.id		= "SabineM2";
	model.FaceId		= 539;
	model.nation		= FRANCE;
	model.price		= 2000;
	model.sex		= "woman";
	model.ani		= "woman_sit";
	model.height		= 1.75;
	model.assigned		= true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	= "A shopkeeper's daughter has run away to sea.";
	model.id		= "SabineM3";
	model.FaceId		= 593;
	model.nation		= SPAIN;
	model.price		= 2000;
	model.sex		= "woman";
	model.ani		= "woman_sit";
	model.height		= 1.75;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	model.assigned		= true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description = "I fight for the freedom of my land and the honour of my family.";
	model.id	  = "Teresa_Moreno";
	model.FaceId	  = 353;
	model.nation      =  PORTUGAL;
	model.price       =  2000;
	model.sex         = "woman";
	model.ani         = "woman_sit";
	model.height      =  1.75;
	model.assigned	=  true;
	model.storytitle = "La Aguja - The Needle";
	model.storytext = "The daughter of a wealthy landowner and one-time partisan, your family have been murdered by the French and you want revenge. You have risen to command of a partisan group, sometimes working with a British officer named Richard Sharpe. You even have a ship, formerly French, which changed hands several times before ending up in yours.";
	model.playertype  = PLAYER_TYPE_AGENT;
	model.name = "Teresa";
	model.lastname = "Moreno";
	model.ship = "FR_Sloop";
	model.shipname = 	"Le Rève";
	model.Flags.Pirate = 19;
	model.Flags.Personal = 3;
	model.date.year = 1798;
	AddCharacterModel(model);

	model.description = "Being a governor's daughter doesn't stop you from allying with pirates.";
	model.id	  = "lizswann";
	model.FaceId	  = 352;
	model.nation      =  PIRATE;
	model.price       =  2000;
	model.sex         = "woman";
	model.ani         = "woman_sit";
	model.height      =  1.75;
	model.assigned	=  true;
	model.storytitle = "Out of the Frying Pan...";
	model.storytext = "Born into a governor's family, you fell in with bad company in the form of Jack Sparrow and Will Turner. Never one to merely follow other people's lead, you now have a ship of your own. What will you do with her?";
	model.playertype  = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.name = "Elizabeth";
	model.lastname = "Swann";
	model.ship = "SloopBermuda";
	model.shipname = 	"Stingray";
	model.Flags.Pirate = 8;
	model.Flags.Personal = 1;
	model.date.year = 1750;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "An older pirate ... a meaner pirate ... a Pirate Boss!";
	model.id       =  "50_Boss1";
	model.FaceId	= 179;
	model.nation      =  PIRATE;
	model.price       =  2000;
	model.assigned    =  true;
	model.name = "Isenbrandt";
	model.lastname = "Jurcksen";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "A descendant of Spaniard and Carib, she knows the Caribbean well.";
	model.id       =  "50_India";
	model.FaceId	= 173;
	model.nation      =  SPAIN;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description = "Nobility, it is in her blood";
	model.id	  = "50_Petra2";
	model.FaceId	  = 181;
	model.nation      =  SPAIN;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
//	model.ani         =  "towngirl";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Petra";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description = "Rachel, of noble birth, and as sweet as her name.";
	model.id	  = "50_Rachel";
	model.FaceId	  = 180;
	model.nation      =  FRANCE;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
//	model.ani         =  "towngirl";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Rachel";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description = "Always running as if for his life... but from whom?";
	model.id	  = "50_Raoul";
	model.FaceId	  = 182;
	model.nation      =  ENGLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.name = "Raoul";
	model.lastname = "Rheims";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "Lived through a lot of pain, now I'm ready to give some.";
	model.id       =  "50Evl2in";
	model.FaceId	= 171;
	model.nation      =  PIRATE;
	model.price       =  2000;
	model.assigned    =  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "Sparrow got old, hit the bottle, and now look at him!";
	model.id       =  "50FatJack";
	model.FaceId	= 178;
	model.nation      =  ENGLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "Black boots, trousers, coat and hat with red trim, long grey hair and beard, and a very mean disposition that has increased with age.";
	model.id	   =  "50grey1";
	model.FaceId	= 159;
	model.nation	  =  PIRATE;
	model.price	   =  2000;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Would ye be want'n to hire a tomb raider?";
	model.id       =  "50LCroft";
	model.FaceId	= 172;
	model.nation      =  PIRATE;
	model.price       =  2000;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Lara";
	model.lastname = "Croft";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description =  "Have you met Orable's uncle, Elbaro?";
	model.id       =  "50M5";
	model.FaceId	= 177;
	model.nation      =  FRANCE;
	model.price       =  2000;
	model.assigned    =  true;
	model.name = "Elbaro";
	model.lastname = "Caron";
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AddCharacterModel(model);

	model.description	=  "I want to look like Roxanne Lalliere.";
	model.id		=  "Roxanne";	// Based on "9CATa_0", with new armour variants
	model.FaceId		=  283;
	model.nation		=  FRANCE;
	model.price		=  1000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Roxanne";
	model.lastname = "Lalliere";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.Flags.Pirate = 27;
	model.Flags.Personal = 40;
	model.ship = "FR_LightPinnace";
	model.shipname = "La Diablesse";
	model.date.year = 1660;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);

	// Taegan n Cat by Daede, with the help of Petros's 50_Becka model and Alan Smithee's Beatrise face and Original Akella Textures/Models -->
	// assign as captain only -->
	model.description	=  "I want something simple and practical, sturdy leather and steel like Catalina was known to wear.";
	model.id		=  "9CATa";
	model.FaceId		=  283;
	model.nation		=  FRANCE;
	model.price		=  1000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Catalina";
	model.lastname = "the Pirate";
	model.playertype = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description	=  "Catalina like simple and practical sturdy leather but without the cuirass.";
	model.id		=  "9CATa_0";
	model.FaceId		=  283;
	model.nation		=  PIRATE;
	model.price		=  500;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Catalina";
	model.lastname = "the Pirate";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Armor Mod -->
	/*model.description	=  "Simple and practical sturdy leather with Steel Cuirass.";
	model.id		=  "9CATa_A1";
	model.FaceId		=  "283";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "Simple and practical sturdy leather with Battle Cuirass.";
	model.id		=  "9CATa_A2";
	model.FaceId		=  "283";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "Simple and practical sturdy leather with Gold Cuirass.";
	model.id		=  "9CATa_A3";
	model.FaceId		=  "283";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	// --> Jack Sparrow - Reworked by Daede, based on Kodo Boon's Jack Sparrow and original Akella Textures/Models
	model.description	=  "I remember Jack Sparrow as a devil may care rogue bucaneer.";
	model.id		=  "9Ja";
	model.FaceId		=  270;
	model.nation		=  PIRATE;
	model.price		=  500;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype = PLAYER_TYPE_ROGUE;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a devil may care rogue bucaneer in a unadorned steel breastplate.";
	model.id		=  "9Ja_A1";
	model.FaceId		=  "270";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a devil may care rogue bucaneer in an engraved steel breastplate.";
	model.id		=  "9Ja_A2";
	model.FaceId		=  "270";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a devil may care rogue bucaneer in an intricate golden breastplate.";
	model.id		=  "9Ja_A3";
	model.FaceId		=  "270";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a clean cut privateer.";
	model.id		=  "9Jb";
	model.FaceId		=  271;
	model.nation		=  PIRATE;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a clean cut privateer in a unadorned steel breastplate.";
	model.id		=  "9Jb_A1";
	model.FaceId		=  "271";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a clean cut privateer in an engraved steel breastplate.";
	model.id		=  "9Jb_A2";
	model.FaceId		=  "271";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a clean cut privateer in an intricate golden breastplate.";
	model.id		=  "9Jb_A3";
	model.FaceId		=  "271";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	// assign as captain only -->
	model.description	=  "I remember Jack Sparrow as a swarthy bearded Pirate.";
	model.id		=  "9Jc";
	model.FaceId		=  272;
	model.nation		=  PIRATE;
	model.price		=  10000;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a swarthy bearded Pirate in a unadorned steel breastplate.";
	model.id		=  "9Jc_A1";
	model.FaceId		=  "272";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a swarthy bearded Pirate in an engraved steel breastplate.";
	model.id		=  "9Jc_A2";
	model.FaceId		=  "272";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a swarthy bearded Pirate in an intricate golden breastplate.";
	model.id		=  "9Jc_A3";
	model.FaceId		=  "272";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	// assign as captain only -->
	model.description	=  "I remember Jack Sparrow as a polished Officer.";
	model.id		=  "9Jd";
	model.FaceId		=  273;
	model.nation		=  PIRATE;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AssignModelType(isstart, model, "Captains", 1.0);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer in a unadorned steel breastplate.";
	model.id		=  "9Jd_A1";
	model.FaceId		=  "273";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer in an engraved steel breastplate.";
	model.id		=  "9Jd_A2";
	model.FaceId		=  "273";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer in an intricate golden breastplate.";
	model.id		=  "9Jd_A3";
	model.FaceId		=  "273";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a polished Officer of the English Navy.";
	model.id		=  "9JdEng";
	model.FaceId		=  274;
	model.nation		=  ENGLAND;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, ENGLAND);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer of the English Navy in a unadorned steel breastplate.";
	model.id		=  "9JdEng_A1";
	model.FaceId		=  "274";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the English Navy in an engraved steel breastplate.";
	model.id		=  "9JdEng_A2";
	model.FaceId		=  "274";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the English Navy in an intricate golden breastplate.";
	model.id		=  "9JdEng_A3";
	model.FaceId		=  "274";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a polished Officer of the French Navy.";
	model.id		=  "9JdFra";
	model.FaceId		=  275;
	model.nation		=  FRANCE;
	model.price		=  5000;
	model.assigned		=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, FRANCE);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description	=  "A French naval officer who bears merely a passing resemblance to a famous pirate.";
	model.id		=  "JBaptisteDuCasse";
	model.FaceId		=  95;
	model.nation		=  FRANCE;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Jean-Baptiste";
	model.lastname = "du Casse";
	model.storytitle = "War of the League of Augsburg";
	model.storytext = "Quite a colourful character, you are! History claims that you became a buccaneer, admiral and colonial administrator who served throughout the Atlantic World during the 17th and 18th centuries. Now at the beginning of your career as officer in the French navy, you are of course required to follow orders. However, your life is yours and you can make whatever choices you see fit.";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 23;
	model.ship = "BrigRoyal";
	model.shipname = "Magicienne";
	model.date.year = 1688;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer of the French Navy in a unadorned steel breastplate.";
	model.id		=  "9JdFra_A1";
	model.FaceId		=  "275";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the French Navy in an engraved steel breastplate.";
	model.id		=  "9JdFra_A2";
	model.FaceId		=  "275";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the French Navy in an intricate golden breastplate.";
	model.id		=  "9JdFra_A3";
	model.FaceId		=  "275";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Dutch Navy.";
	model.id		=  "9JdHol";
	model.FaceId		=  276;
	model.nation		=  HOLLAND;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Pieter";
	model.lastname = "Bloed";
	model.Flags.Pirate = 0;
	model.Flags.Personal = 9;
	model.ship = "NL_Amsterdam";
	model.shipname = "Amsterdam";
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	model.Flags.Pirate = 0;
	model.Flags.Personal = 13;
	model.date.month = 1;
	model.date.year = 1749;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, HOLLAND);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer of the Dutch Navy in a unadorned steel breastplate.";
	model.id		=  "9JdHol_A1";
	model.FaceId		=  "276";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Dutch Navy in an engraved steel breastplate.";
	model.id		=  "9JdHol_A2";
	model.FaceId		=  "276";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Dutch Navy in an intricate golden breastplate.";
	model.id		=  "9JdHol_A3";
	model.FaceId		=  "276";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Portuguese Navy.";
	model.id		=  "9JdPor";
	model.FaceId		=  277;
	model.nation		=  PORTUGAL;
	model.price		=  5000;
	model.assigned		=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PORTUGAL);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description	=  "A Portuguese naval officer who bears merely a passing resemblance to a famous pirate.";
	model.id		=  "FdeAlmeida";
	model.FaceId		=  96;
	model.nation		=  PORTUGAL;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Francisco";
	model.lastname = "de Almeida";
	model.storytitle = "The Portuguese Armada";
	model.storytext = "As was customary for men in your social circle, you joined the military at an early age. You have fought in conflicts in different parts of Morocco and Spain on the side of the Castilians. Now in the Caribbean, Spain is again your ally. But you never know what the future might bring!";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 27;
	model.ship = "Polacca_N";
	model.shipname = "Lebre";
	model.date.year = 1505;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer of the Portuguese Navy in a unadorned steel breastplate.";
	model.id		=  "9JdPor_A1";
	model.FaceId		=  "277";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Portuguese Navy in an engraved steel breastplate.";
	model.id		=  "9JdPor_A2";
	model.FaceId		=  "277";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Portuguese Navy in an intricate golden breastplate.";
	model.id		=  "9JdPor_A3";
	model.FaceId		=  "277";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Spanish Navy.";
	model.id		=  "9JdSpa";
	model.FaceId		=  278;
	model.nation		=  SPAIN;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, SPAIN);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "I remember Jack Sparrow as a polished Officer of the Spanish Navy in a unadorned steel breastplate.";
	model.id		=  "9JdSpa_A1";
	model.FaceId		=  "278";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Spanish Navy in an engraved steel breastplate.";
	model.id		=  "9JdSpa_A2";
	model.FaceId		=  "278";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "I remember Jack Sparrow as a polished Officer of the Spanish Navy in an intricate golden breastplate.";
	model.id		=  "9JdSpa_A3";
	model.FaceId		=  "278";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod
	// <-- Jack Sparrow - Reworked by Daede, based on Kodo Boon's Jack Sparrow and original Akella Textures/Models

	// Fun with Researcher by Daede, based on original Akella researcher model and texture -->
	// no model assignment quest character -->
	model.description	=  "A functional tradesman's uniform, ideal for Carpenters.";
	model.id		=  "9R_Carp";
	model.FaceId		=  284;
	model.nation		=  ENGLAND;
	model.price		=  500;
	model.assigned		=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description	=  "A functional tradesman's uniform, ideal for Doctors.";
	model.id		=  "9R_doct";
	model.FaceId		=  "285";
	model.nation		=  ENGLAND;
	model.price		=  500;
	model.assigned		=  true;
	model.playertype = PLAYER_TYPE_PHYSICIAN;
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description	=  "A functional tradesman's uniform, ideal for Gunners.";
	model.id		=  "9R_Gunn";
	model.FaceId		=  "286";
	model.nation		=  ENGLAND;
	model.price		=  500;
	model.assigned		=  true;
	model.playertype  = PLAYER_TYPE_GUNNER;
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "A functional tradesman's uniform, ideal for Pursers.";
	model.id		=  "9R_Purs";
	model.FaceId		=  "287";
	model.nation		=  ENGLAND;
	model.price		=  500;
	model.assigned		=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character
	// Fun with Researcher by Daede, based on original Akella researcher model and texture <--

	model.description	=  "A brocade long coat in Olive over Black vest and breeches in the naturalist style.";
	model.id		=  "9S_Nat";
	model.FaceId		=  288;
	model.nation		=  ENGLAND;
	model.price		=  1000;
	model.assigned		=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description	=  "A brocade long coat in Navy Blue over Black vest and breeches in the naturalist style.";
	model.id		=  "9S_Nav";
	model.FaceId		=  "289";
	model.nation		=  ENGLAND;
	model.price		=  1000;
	model.assigned		=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description	=  "A brocade long coat in Black over Brown vest and breeches in the naturalist style.";
	model.id		=  "9S_Pir";
	model.FaceId		=  "290";
	model.nation		=  PIRATE; // Estharos reassign April 12th, 2009
	model.price		=  1000;
	model.assigned		=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// Taegan n Cat by Daede, with the help of Petros's 50_Becka model and Alan Smithee's Beatrise face and Original Akella Textures/Models -->
	model.description	=  "How about a simple brown vest to fit my girlish figure.";
	model.id		=  "9Ta";
	model.FaceId		=  279;
	model.nation		=  PORTUGAL;
	model.price		=  500;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description	=  "Taegan's simple vest outfit but without the vest.";
	model.id		=  "9Ta_0";
	model.FaceId		=  279;
	model.nation		=  PORTUGAL;
	model.price		=  250;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "A simple brown vest with a Steel Cuirass.";
	model.id		=  "9Ta_A1";
	model.FaceId		=  "279";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A simple brown vest with a Battle Cuirass.";
	model.id		=  "9Ta_A2";
	model.FaceId		=  "279";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A simple brown vest with a Gold Cuirass.";
	model.id		=  "9Ta_A3";
	model.FaceId		=  "279";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "How about a presentable red waistcoat to fit my girlish figure.";
	model.id		=  "9Tb";
	model.FaceId		=  280;
	model.nation		=  PORTUGAL;
	model.price		=  1000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "Mates", 1.0);  //Not women for simple sailors. It causes animation bug in crewmember on shore mod.
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description	=  "Taegan's presentable waistcoat outfit but without the waistcoat.";
	model.id		=  "9Tb_0";
	model.FaceId		=  280;
	model.nation		=  PORTUGAL;
	model.price		=  500;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "A presentable red waistcoat with Steel Cuirass.";
	model.id		=  "9Tb_A1";
	model.FaceId		=  "280";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A presentable red waistcoat with Battle Cuirass.";
	model.id		=  "9Tb_A2";
	model.FaceId		=  "280";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A presentable red waistcoat with Gold Cuirass.";
	model.id		=  "9Tb_A3";
	model.FaceId		=  "280";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	// assign as captain only -->
	model.description	=  "How about a captain's coat to fit my girlish figure, black of course and throw in a matching hat.";
	model.id		=  "9Td";
	model.FaceId		=  281;
	model.nation		=  PIRATE;
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description	=  "Taegan's captain's coat outfit but without the coat.";
	model.id		=  "9Td_0";
	model.FaceId		=  281;
	model.nation		=  PIRATE;
	model.price		=  2500;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 0.2, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Armor Mod -->
	/*model.description	=  "A captain's coat, black with Steel Cuirass.";
	model.id		=  "9Td_A1";
	model.FaceId		=  "281";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A captain's coat, black with Battle Cuirass.";
	model.id		=  "9Td_A2";
	model.FaceId		=  "281";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);

	model.description	=  "A captain's coat, black with Gold Cuirass.";
	model.id		=  "9Td_A3";
	model.FaceId		=  "281";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "How about an elegant gown, perhaps a little revealing of my girlish figure.";
	model.id		=  "9Te";
	model.FaceId		=  282;
	model.nation		=  ENGLAND;
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	model.name = "Taegan";
	model.lastname = "Finch";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description	=  "An elegant and revealing gown with Steel Cuirass.";
	model.id		=  "9Te_A1";
	model.FaceId		=  "282";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  5000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	AddCharacterModel(model);

	model.description	=  "An elegant and revealing gown with Battle Cuirass.";
	model.id		=  "9Te_A2";
	model.FaceId		=  "282";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  10000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	AddCharacterModel(model);

	model.description	=  "An elegant and revealing gown with Gold Cuirass.";
	model.id		=  "9Te_A3";
	model.FaceId		=  "282";
	model.nation		=  BROKEN; // we autoassign it elsewhere
	model.price		=  15000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "What a fine suit this is, with it's Elizabethan collar and frills.  To wear it will be a feather in your cap!";
	model.id	   =  "admiral";
	model.FaceId	= 55;
	model.nation	  =  PORTUGAL;
	model.price	   =  10000;
	model.assigned	=  true;
	model.minlevel     =  16;
	model.minrank	 =  8;
//	model.name = "Joaquin";
//	model.lastname = "Da Saldanha";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	model.period = "" + PERIOD_EARLY_EXPLORERS + PERIOD_THE_SPANISH_MAIN;
	AddCharacterModel(model);

	model.description =  "A nobleman in red. And please add some sort of gold-coloured hanger thingey.";
	model.id	   =  "Albermal"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 192;
	model.nation	  =  ENGLAND;
	model.price	   =  8000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuro());
	AddCharacterModel(model);

	model.description =  "Amerigo Vieira, Master Swordsman! The best blade in the entire archipelago!";
	model.id	   =  "ancient";
	model.FaceId	= 321;
	model.nation	  =  PORTUGAL;
	model.price	   =  2000;
	model.assigned	=  true;
//	model.name = "Amerigo";
//	model.lastname = "Vieira";
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	AssignModelTypeNation(isstart, model, "Mates", 1.0, PORTUGAL);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CANNONEER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "A red monk's robe, bath robe, martial arts robe, magician's robe, whatever kind of robe you say it is!";
	model.id	   =  "Animists1";
	model.FaceId	= 140;
	model.nation	  =  PIRATE;
	model.price	   =  500;
	model.assigned	=  true;
	model.Flags.Pirate = 13;
	model.Flags.Personal = 37;
	model.storytitle = "Satanists";
	model.storytext = "After escaping the Maltese Order's destruction of your lair in Italy, you've fled to the Caribbean vowing for vengeance in the name of the Prince of Darkness...";
	model.playertype = PLAYER_TYPE_REBEL;
	model.name = "Dark";
	model.lastname = "Teacher";
	model.ship = "Frigate_Sat";
	model.shipname = "Mefisto";
	model.date.hour = 3;
	model.date.year = 1750;
	AssignModelType(isstart, model, "Animists", 1.0);
	AddCharacterModel(model);

	model.description =  "A red monk's robe will accent the mustache and goatee for an impression of menace!";
	model.id	   =  "Animists2";
	model.FaceId	= 141;
	model.nation	  =  BROKEN;
	model.price	   =  750;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Animists", 1.0);
	AddCharacterModel(model);

	model.description =  "A grey monk's robe perhaps from the far east!";
	model.id	   =  "Animists3";
	model.nation	  =  BROKEN;
	model.FaceId	= 142;
	model.price	   =  750;
	model.assigned	=  true;
	model.camouflage = true; // PB: Camouflage mod
	model.Flags.Pirate = 13;
	AssignModelType(isstart, model, "ScheffnowMonks", 1.0);
	AddCharacterModel(model);

	model.description =  "Estrella in disguise";
	model.id       =  "Animistse";
	model.FaceId	= 152;
	model.nation      =  BROKEN;
	model.price       =  1000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description	=  "Pretty woman, must be a governor's niece or wife";
	model.id			=  "AnnaDeLeiva";
	model.FaceId		=  350;
	model.nation		=  SPAIN;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.65;
	model.sex			=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.ismansion		=  true;//Pretty woman, must be a governor's niece or wife
	model.name = "Anna";
	model.lastname = "De Leiva";
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringSouthEuro());
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "";
	model.id	   =  "Apothecary";
	model.FaceId	= 106; // Estharos to be assign March 23, 2009 // TALISMAN was 26
	model.nation	  =  ENGLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "Stephen";
	model.lastname = "Maturin";
	model.playertype = PLAYER_TYPE_PHYSICIAN;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// For future quests -->
	model.description =  "I feel like an unlucky Spanish soldier. How about something like Arturo Campos ?";
	model.id	   =  "Arturo_Campos";
	model.FaceId	= 368;
	model.nation	  =  SPAIN;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Arturo";
	model.lastname = "Campos";
	AddCharacterModel(model);
	// For future quests <--

	model.description =  "Mateus Santos, at your service. Can I drop you somewhere?";
	model.id	   =  "Assassin";
	model.FaceId	= 317;
	model.nation	  =  SPAIN;
	model.price	   =  2500;
	model.assigned	=  true;
//	model.name = "Mateus";
//	model.lastname = "Santos";
	AddCharacterModel(model);

	model.description =  "For people wanting something more like Assassin's Creed.";
	model.id       =  "Assassin2";
	model.FaceId	= 448;
	model.nation      =  BROKEN;
	model.price       =  1000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "I'm feeling like a lucky master and commander today. Do you have anything to suit that?";
	model.id	   =  "Aubrey"; // From the Deringer skin pack
	model.FaceId	= 199;
	model.minlevel     =  10;
	model.minrank     =  5;
	model.nation	  =  ENGLAND;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Aubrey";
	model.storytitle = "Master & Commander";
	model.storytext = "Captain John 'Lucky Jack' Aubrey is set to cruise in the Caribbean with his new ship, HMS Surprise. Meet his good friend, naturalist, and ship's physician, Stephen Maturin, and influence the course of the war with France.";
	model.loadingScreen = "Character_JackAubrey.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 28;
	model.ship = "HMS_Surprise";
	model.shipname = "Surprise";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 26;
	model.date.month = 10;
	model.date.year = 1813;
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "Give me a navigator's outfit, pirate style.";
	model.id	   =  "BadV";  //  <-- Added by Cat
	model.FaceId	= 158;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
//	model.name = "Artois";
//	model.lastname = "Voysey";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Sir Christopher Mings:
	model.description	=  "They're more like guidelines...";
	model.id			=  "Barbossa";
	model.FaceId		=  78;
	model.nation		=  PIRATE;
	model.price			=  1000;
	model.assigned		=  true;
	model.name = "Hector";
	model.lastname = "Barbossa";
	model.storytitle = "The Curse of Cortés";
	model.storytext = "Pirate Lord of the Caspian Sea. Mutineer. And now finder of the lost treasure of Isla de Muerta. You are ready to make good use of your new-found wealth! But a nasty surprise lies in store for you...";
	model.playertype = PLAYER_TYPE_CURSED;
	model.ship = SHIP_CURSED;
	model.shipname = "Black Pearl";
	model.Flags.Pirate = 0;
	model.Flags.Personal = 11;
	model.date.hour = 22;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "They're more like guidelines...";
	model.id	  =  "Barbossa2";
	model.FaceId	  =  393;
	model.nation	  =  ENGLAND;
	model.price	  =  1000;
	model.assigned	  =  true;
	model.name	  = "Hector";
	model.lastname	  = "Barbossa";
	model.storytitle  = "On Stranger Tides";
	model.storytext	  = "Are your days of pirating truly behind you? Or do you serve the crown for your own ulterior motives?";
	model.playertype  = PLAYER_TYPE_CORSAIR;
	model.ship	  = "RN_Surprise";
	model.shipname	  = "Providence";
	model.Flags.Pirate = 0;
	model.Flags.Personal = 11;
	model.date.hour	  = 9;
	model.date.year	  = 1744;
	AddCharacterModel(model);

	model.description =  "Is it true what they say about redheads? Why don't you come here and find out, cur!";
	model.id	   =  "beatrise";
	model.FaceId	= 204;
	model.sex		 =  "woman";
	model.ani		 =  "man_woman_sit";
	model.height	  =  1.75;
	model.nation	  =  PORTUGAL;
	model.price	   =  1200;
	model.assigned	=  true;
	model.name = "Beatrise";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "Beatrice Devlin. In her original view.";
	model.id			=  "Beatrice";
	model.FaceId		=  293;
	model.nation		=  SPAIN;
	model.price			=  1000;
	model.assigned		=  true;
	model.height		=  1.7;
	model.sex			=  "woman";
//	model.ani			=  "Beatrice";
	model.ani		=  "woman_sit";
	model.name 			=  "Beatrice";
	model.lastname 		=  "Devlin";
	model.storytitle =  "Caribbean Tales";  // PB: Hide this one from Specific Characters because there is also a storyline?
	model.storytext  =  "Beatrice Devlin is fond of exploring the newly discovered West Indies. You are a free lass in a free world. Do you have what it takes to create a true Age of Pirates?";
	model.playertype = PLAYER_TYPE_EXPLORER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 11;
	model.Flags.Personal = 4;
	model.ship = "PO_CaravelR";
	model.shipname = "Quicksilver";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 25;
	model.date.month = 9;
	model.date.year = 1550;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "Beatrice's sister. Slightly younger, slightly sassier and it shows in the outfit.";
	model.id		=  "BeatriceA";
	model.FaceId		=  323;
	model.nation		=  PERSONAL_NATION;
	model.price		=  1000;
	model.assigned		=  true;
	model.height		=  1.7;
	model.sex		=  "woman";
//	model.ani		=  "Beatrice";
	model.ani		=  "woman_sit";
	model.name 		=  "Bonnie";
	model.lastname 		=  "Devlin";
	model.playertype 	= PLAYER_TYPE_EXPLORER;
	model.difficulty 	= DIFFICULTY_MARINER;
	model.Flags.Pirate 	= 5;
	model.Flags.Personal	= 43;
	model.ship		= "RN_Galeon_L";
	model.shipname		= "Quicksilver";
	model.date.hour		= 10;
	model.date.min		= 24;
	model.date.sec		= 42;
	model.date.day		= 1;
	model.date.month	= 4;
	model.date.year		= 1576;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "Bonnie Devlin after she dyed her hair and her clothes.";
	model.id		=  "BeatriceB";
	model.FaceId		=  602;
	model.nation		=  PERSONAL_NATION;
	model.price		=  1000;
	model.assigned		=  true;
	model.height		=  1.7;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.name 		=  "Bonnie";
	model.lastname 		=  "Devlin";
	model.playertype	= PLAYER_TYPE_ADVENTURER;
	model.difficulty	= DIFFICULTY_MARINER;
	model.Flags.Pirate	= 5;
	model.Flags.Personal	= 43;
	model.ship		= "RN_Galeon_L";
	model.shipname		= "Quicksilver";
	model.date.hour		= 10;
	model.date.min		= 24;
	model.date.sec		= 42;
	model.date.day		= 1;
	model.date.month	= 4;
	model.date.year		= 1576;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "A demoness who came from the underworld seeks an adventure in mortal world.";
	model.id		=  "Devillady";
	model.FaceId		=  607;
	model.nation		=  SPAIN;
	model.price		=  3000;
	model.assigned		=  true;
	model.height		=  1.7;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.name 		=  "Dervia";
	model.playertype	= PLAYER_TYPE_ADVENTURER;
	model.difficulty	= DIFFICULTY_SWASHBUCKLER;
	model.Flags.Pirate	= 5;
	model.Flags.Personal	= 43;
	model.date.hour		= 10;
	model.date.min		= 24;
	model.date.sec		= 42;
	model.date.day		= 1;
	model.date.month	= 4;
	model.date.year		= 1576;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "The undead monk who had many names for ages, decides to take up a sword and show his true nature into this cruel world.";
	model.id		=  "undeadmon";
	model.FaceId		=  608;
	model.nation		=  ENGLAND;
	model.price		=  3000;
	model.assigned		=  true;
	model.height		=  1.7;
	model.sex		=  "man";
	model.name 		=  "Avergorex";
	model.playertype	= PLAYER_TYPE_ADVENTURER;
	model.difficulty	= DIFFICULTY_SWASHBUCKLER;
	model.Flags.Pirate	= 5;
	model.Flags.Personal	= 43;
	model.ship = "tartane1";
	model.shipname		= "Devil";
	model.date.hour		= 10;
	model.date.min		= 24;
	model.date.sec		= 42;
	model.date.day		= 1;
	model.date.month	= 4;
	model.date.year		= 1750;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "Now then, I must have an ounce or two of that malapert blood from you!";
	model.id		=  "Beltro";
	model.FaceId		=  "184";
	model.nation		=  PIRATE;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Desmond Ray";
	model.lastname = "Beltrop";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description	=  "I'm gonna have yer guts for garters, Nicholas Sharp!";
	model.id		=  "Beltrop1";
	model.FaceId		=  "185";
	model.nation		=  PIRATE;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Desmond Ray";
	model.lastname = "Beltrop";
	AddCharacterModel(model);

	model.description	=  "Damn you, Mings! You didn't give me a neck!";
	model.id		=  "Beltrop1Beltrop2_1";
	model.FaceId		=  "185";
	model.nation		=  PIRATE;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Desmond Ray";
	model.lastname = "Beltrop";
	AssignModelTypeNation(isstart, model, "Rich_Citizens", 1.0, PIRATE);
	AddCharacterModel(model);

	// For future quests -->
	model.description =  "I feel like an unlucky Dutch Soldier. How about something like Berend De Voor ?";
	model.id	   =  "Berend_De_Voor";
	model.FaceId	= 369;
	model.nation	  =  HOLLAND;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Berend";
	model.lastname = "De Voor";
	AddCharacterModel(model);
	// For future quests <--

	// assign as captain only -->
	model.description =  "A young villain who seems to love kidnapping.";
	model.id	   =  "BillyBrock";
	model.FaceId	= 442;
	model.nation	  =  PIRATE;
	model.price	   =  500;
	model.assigned	=  true;
//	model.name = "Billy";
//	model.lastname = "Brock";
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "The young villain has become older, but still seems to love kidnapping.";
	model.id	   =  "BillyBrock2";
	model.FaceId	= 443;
	model.nation	  =  PIRATE;
	model.price	   =  500;
	model.assigned	=  true;
//	model.name = "Billy";
//	model.lastname = "Brock";
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "Bring a simple outfit that'll show off this nice black skin!";
	model.id	   =  "Black_Corsair";
	model.FaceId	= 0;
	model.nation	  =  PIRATE;
	model.price	   =  250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// no model assignment quest character -->
	model.description	=  "If I don't kill a man every now and then, they forget who I am.";
	model.id			=  "Blackbeard";
	model.FaceId		=  80;
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.name = "Blackbeard";
	model.storytitle = "No Quarter!";
	model.storytext = "With a one-of-a-kind ship, you are ready to terrorize the Caribbean. But you haven't earned your fame just yet. Are you ready to live up to your name and become the pirate all pirates fear?";
	model.nation = PIRATE;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	model.ship = "QueenAnnesRevenge";
	model.shipname = "Queen Anne's Revenge";
	model.Flags.Pirate = 20;
	model.Flags.Personal = 2;
	model.date.year = 1740;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Do you have a set of clothes suitable for a Moorish swashbuckler?";
	model.id	   =  "blackman";
	model.FaceId	= 46;
	model.nation	  =  SPAIN;
	model.price	   =  250;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	// BlackSmith's add by Estharos -->
	model.description =  "";
	model.id	   =  "blacksmith1";
	model.FaceId	= 284; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "blacksmith2";
	model.FaceId	= 286; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "blacksmith4";
	model.FaceId	= 5; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "blacksmith5";
	model.FaceId	= 165; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "blacksmith6";
	model.FaceId	= 321; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "blacksmith7";
	model.FaceId	= 46; // Estharos to be assign March 23, 2009
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- BlackSmith's add by Estharos

	model.description =  "Give me something with black trousers and vest, in the Russian style.";
	model.id	   =  "Blaze";
	model.FaceId	= 16;
	model.nation	  =  ENGLAND;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.difficulty = DIFFICULTY_LANDLUBBER;
	model.Flags.Pirate = 15;
	model.Flags.Personal = 14;
	model.ship = "LuggerVML";
	model.shipname = "Sea Horse";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 16;
	model.date.month = 4;
	model.date.year = 1750;
	AddCharacterModel(model);

	// Thomas the Terror -->
	model.description =  "Give me something with blue trousers and no vest, in the British Royal Navy style.";
	model.id	   =  "47_Blaze_brtmds";
	model.FaceId	= 16;
	model.nation	  =  BROKEN; // Upon promotion
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);
	// Thomas the Terror <--

	// Armor Mod -->
	/*model.description =  "Give me something with black trousers and a steel cuirass, in the Russian style.";
	model.id	   =  "Blaze_A1";
	model.FaceId	= "Blaze";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Give me something with black trousers and an engraved breastplate, in the Russian style.";
	model.id	   =  "Blaze_A2";
	model.FaceId	= "Blaze";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Give me something with black trousers and a gilded breastplate, in the Russian style.";
	model.id	   =  "Blaze_A3";
	model.FaceId	= "Blaze";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "Give me something with black trousers and vest, in the Russian style. But don't forget the razor!";
	model.id	   =  "Blaze_NB";
	model.FaceId	= 210;
	model.nation	  =  ENGLAND;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "Give me something with black trousers and a steel cuirass. But don't forget the razor!";
	model.id	   =  "Blaze_NB_A1";
	model.FaceId	= "Blaze_NB";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Give me something with black trousers and an engraved breastplate. But don't forget the razor!";
	model.id	   =  "Blaze_NB_A2";
	model.FaceId	= "Blaze_NB";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Give me something with black trousers and a gilded breastplate. But don't forget the razor!";
	model.id	   =  "Blaze_NB_A3";
	model.FaceId	= "Blaze_NB";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description = "From Russia with sword.";
	model.id	  = "aleskeevich";
	model.FaceId	= 268;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  300;
	model.assigned	=  true;
	model.storytitle = "The Cossack in the Caribbean";
	model.storytext = "A Cossack under the great Stenka Rasin, you have escaped after his death and come to the Caribbean seeking your fortune.";
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	model.name = "Bohdan";
   	model.middlename = "Aleskeevich";
	model.lastname = "Voronov";
	model.ship = "Polacca";
	model.shipname = "Babushka";
	model.Flags.Pirate = 12;
	model.Flags.Personal = 6;
	model.date.year = 1681;
	AddCharacterModel(model);

	model.description =  "Give me something cheap with a brown trousers and a vest, a simple red one.";
	model.id	   =  "Blaze4";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  300;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);

	model.description =  "An adventurer from the Italic peninsula, in search of glory in the Caribbean.";
	model.id	   =  "Sergio";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  300;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.name = "Sergio";
	model.lastname = "The SeaWolf";
	model.Flags.Personal = 4;
	AddCharacterModel(model);

        model.description =  "An adventurer from the Italic peninsula, in search of glory in the Caribbean.";
	model.id	   =  "Sergio1";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  400;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.name = "Sergio";
	model.lastname = "The SeaWolf";
	model.Flags.Personal = 4;
	AddCharacterModel(model);

	model.description =  "An adventurer from the Italic peninsula, in search of glory in the Caribbean.";
	model.id	   =  "Sergio2";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.name = "Sergio";
	model.lastname = "The SeaWolf";
	model.Flags.Personal = 4;
	AddCharacterModel(model);

	model.description =  "I have a somewhat black mood today, have you something that compliments that?";
	model.id	   =  "Blaze5";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  300;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);

	model.description =  "Give me something with blue trousers and vest, in red with blue accents.";
	model.id	   =  "Blaze6";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  450;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);

	model.description =  "Give me something with a fancy reddish jacket. And some shiny medallions.";
	model.id	   =  "Blaze7";
	model.FaceId	= 16;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);

	model.description =  "If ye be yearnin' t' be a Bilgemunky, this be yer outfit.";
	model.id	   =  "Bmunk";
	model.FaceId	= 153;
	model.nation	  =  PIRATE;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.price	   =  1000;
	model.name = "Bilgemunky";
	AssignModelType(isstart, model, "Skeletons", 1.0);
	AddCharacterModel(model);

	model.description =  "A stripped short sleeve shirt, light brown vest, and bandanna to accent the dark hair and beart. An eyepatch is probably called for, but I don't seem to see one...";
	model.id	   =  "bocman";
	model.FaceId	= 3;
	model.nation	  =  SPAIN;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "Such muscles require a roomy white shirt, open at the collar, and sideburns.";
	model.id	   =  "bocman1";
	model.FaceId	= 1;
	model.nation	  =  HOLLAND;
	model.price	   =  250;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "A stripped short sleeve shirt, light brown vest, and bandanna to accent the dark hair and beart. An eyepatch is probably called for, but I don't seem to see one...";
	model.id	   =  "bocman10";
	model.FaceId	= 40;
	model.nation	  =  PORTUGAL;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "A white sleeveless shirt, shaved head and beard for a real tough guy!  And SPEAKING of tough guy, there's a tattoo shop right around the corner that's running a special on facials...";
	model.id	   =  "bocman16";
	model.FaceId	= 56;
	model.nation	  =  FRANCE; // Estharos reassign April 5th, 2009
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "A white sleeveless shirt, shaved head and beard for a real tough guy!  And SPEAKING of tough guy, there's a tattoo shop right around the corner that's running a special on facials...";
	model.id	   =  "bocman17";
	model.FaceId	= 56;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "A white sleeveless shirt, shaved head and beard for a real tough guy!  And SPEAKING of tough guy, there's a tattoo shop right around the corner that's running a special on facials...";
	model.id	   =  "bocman18";
	model.FaceId	= 56;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "A most trustworthy and rum-drinking boatswain, please!";
	model.id	   =  "bocman2";
	model.FaceId	= 187;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.skipcheck	=  true;//MAXIMUS
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Oh, a simple pair of trowsers, a simple vest, and a bandanna.  A shirt? No, not in THIS heat!";
	model.id	   =  "bocman3";
	model.FaceId	= 2;
	model.nation	  =  PORTUGAL;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "A white sleeveless shirt, shaved head and beard for a real tough guy!  And SPEAKING of tough guy, there's a tattoo shop right around the corner that's running a special on facials...";
	model.id	   =  "bocman4";
	model.FaceId	= 56;
	model.nation	  =  FRANCE;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "A most trustworthy and rum-drinking boatswain, in blue vest!";
	model.id	   =  "bocman5";
	model.FaceId	= 187;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Such muscles require a roomy white shirt, open at the collar, and sideburns.";
	model.id	   =  "bocman8";
	model.FaceId	= 1;
	model.nation	  =  HOLLAND;
	model.price	   =  250;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "Did you ever hear of John Clifford Brin, best governor Tendales ever had?";
	model.id	   =  "Brin";
	model.FaceId	= 209;
	model.nation	  =  ENGLAND;
	model.price	   =  15000;
	model.assigned	=  true;
//	model.name = "John Clifford";
//	model.lastname = "Brin";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "What who is she!? Get your name straight woman!";
	model.id	   =  "Brinkley";
	model.FaceId	= 444;
	model.nation	  =  ENGLAND;
	model.sex			=  "woman";
//	model.ani        	=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.72;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Annabella";
	model.lastname = "Brinkley";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "I want to dress out like someone really, really poor. Don't ask me why.";
	model.id	   =  "brodyag1"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 198;
	model.price	   =  1;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Break out some rags that'll serve for masquerading as a bum!";
	model.id	   =  "brodyaga";
	model.FaceId	= 4;
	model.nation	  =  BROKEN;
	model.price	   =  1;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Wear this Royal Navy Admiral's uniform and drink good health to ol' Jervie";
	model.id          =  "brtadm1_18";
	model.FaceId      =  405;
	model.minlevel    =  16;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  9000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A Royal Navy Admiral's uniform, if you please. Midshipman, signal all my captains to repair aboard flag at six bells.";
	model.id          =  "brtadm2_18";
	model.FaceId      =  406;
	model.minlevel    =  16;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  9000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A Royal Navy Admiral's uniform, but leave out the wig if you please.";
	model.id          =  "brtadm3_18";
	model.FaceId      =  441;
	model.minlevel    =  16;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  9000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "The uniform of a young shaven commodore please.";
	model.id          =  "brtbath_18";
	model.FaceId      =  407;
	model.minlevel    =  14;
	model.minrank     =  7;
	model.nation      =  ENGLAND;
	model.price       =  10000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Royal Navy Post-Captain's uniform.  Broke wore something like this when he stopped them singing Yankee Doodle dandee-oh.";
	model.id          =  "brtcpt1_18";
	model.FaceId      =  408;
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Royal Navy Post-Captain's uniform.  Made for only the luckiest of jack-tars.";
	model.id          =  "brtcpt2_18";
	model.FaceId      =  409;
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Royal Navy Lieutenant's uniform.  This one looks like a red-headed Irishman.";
	model.id          =  "brtlut1_18";
	model.FaceId      =  410;
	model.minlevel    =  4;
	model.minrank     =  2;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Royal Navy Lieutenant's uniform. Hmm... reminds me of young Tom. Damn fine seaman, that lad. Very promising young officer";
	model.id          =  "brtlut2_18";
	model.FaceId      =  410;
	model.minlevel    =  4;
	model.minrank     =  2;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Royal Navy Lieutenant's uniform.  Do you fancy yourself a poet?";
	model.id          =  "brtlut3_18";
	model.FaceId      =  410;
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	model.name = "Jack";
	model.lastname = "Aubrey";
	model.storytext = "Captain John 'Lucky Jack' Aubrey is set to cruise in the Caribbean with his new ship, HMS Sophie. Meet his good friend, naturalist, and ship's physician, Stephen Maturin, and influence the course of the war with France.";
	model.loadingScreen = "Character_JackAubrey.tga";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 28;
	model.ship = "HMS_Sophie";
	model.shipname = "Sophie";
	model.date.year = 1798;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "Let's see how a midshipman's uniform will show off a young blonde baby-face!";
	model.id	   =  "brtmds1_18";
	model.FaceId	= 411;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "The usual kit for a midshipman will suffice for the moment.";
	model.id	   =  "brtmds2_18";
	model.FaceId	= 411;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "Get a fresh midshipman's uniform that shows promise for the future!";
	model.id	   =  "brtmds3_18";
	model.FaceId	= 411;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "Get a fresh midshipman's uniform that shows promise for the future!";
	model.id	   =  "brtmds4_18";
	model.FaceId	= 411;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, ENGLAND);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "An officer of His Majesty's Royal Marines";
	model.id          =  "brtoffic18";
	model.FaceId      =  99;
	model.nation      =  ENGLAND;
	model.price       =  4500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	// English Marines. JMV Textures with portraits and recoding by Jack Davidson -->
	model.description =  "A soldier of His Majesty's Royal Marines.  A Nice shaggy goatee too.";
	model.id          =  "BrtSol18_1";
	model.FaceId      =  99; // TALISMAN changed was 311
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	model.description =  "A soldier of His Majesty's Royal Marines... the facial hair makes you look older?";
	model.id          =  "BrtSol18_2";
	model.FaceId      =  99; // TALISMAN changed was 312
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	model.description =  "A soldier of His Majesty's Royal Marines.";
	model.id          =  "BrtSol18_3";
	model.FaceId      =  99; // TALISMAN changed was 313
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	model.description =  "A soldier of His Majesty's Royal Marines.  You look nice, why so sad?";
	model.id          =  "BrtSol18_4";
	model.FaceId      =  99; // TALISMAN changed was 314
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	model.description =  "A soldier of His Majesty's Royal Marines, but I think you lied about your age.";
	model.id          =  "BrtSol18_5";
	model.FaceId      =  99; // TALISMAN changed was 315
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);

	model.description =  "A soldier of His Majesty's Royal Marines.  You'll look like a right proper soldier in this uniform.";
	model.id          =  "BrtSol18_6";
	model.FaceId      =  99; // TALISMAN changed was 316
	model.nation      =  ENGLAND;
	model.price       =  1150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	AddCharacterModel(model);
	// English Marines. JMV Textures with portraits and recoding by Jack Davidson <--

	// For the assassin quest -->
	model.description =  "He is the officer of Johan Elting and an expert in weapons.";
	model.id	   =  "Buccaneer1";
	model.FaceId	= 413;
	model.nation	  =  PIRATE;
	model.assigned	=  true;
	model.name = "Chico";
	model.lastname = "Cois";
	AddCharacterModel(model);
	// <-- For the assassin quest

	model.description =  "A French-American pirate and privateer from the Gulf of Mexico, if you please.";
	model.id	   =  "Jean_Lafitte";
	model.FaceId	= 219;				//JRH
	model.nation	  =  FRANCE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Jean";
	model.lastname = "Lafitte";
	model.storytitle = "The Buccaneer";
	model.storytext = "A French smuggler friendly to the United States arrives in port. But will you abandon your profitable ventures to expand the might of the Americas in the Caribbean? Or perhaps join forces with one of the other nations? And how long will you be able to resist the lure of piracy?";
	model.playertype = PLAYER_TYPE_SMUGGLER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 19;
	model.Flags.Personal = 38;
	model.ship = "US_Hannah";
	model.shipname = "Goelette la Diligente";
	model.date.hour = 13;
	model.date.min = 20;
	model.date.sec = 33;
	model.date.day = 15;
	model.date.month = 3;
	model.date.year = 1813;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "One of Mateus Santo's Thugs, a little worse for wear and tear.";
	model.id	   =  "bugmanpirat14";
	model.FaceId	= 322;
	model.nation	  =  SPAIN;
	model.price	   =  100;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// assign as captain only -->
	model.description =  "Grey trousers, red leather boots, and a shirt that fits loose and will show off some muscles!  D'ye have an earing?";
	model.id	   =  "capitan";
	model.FaceId	= 5;
	model.nation	  =  PORTUGAL; // Estharos reassign April 6th, 2009
	model.price	   =  750;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// no model assignment quest character -->
	model.description =  "A nice black coat and hat, nothing too fancy or out of the ordinary.";
	model.id	   =  "capitan1";
	model.FaceId	= 6;
	model.nation	  =  HOLLAND;
	model.price	   =  2750;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// assign as captain only -->
	model.description = "That meddling boy will cower before the might of Captain James, er, Hand! Smee! Where the blazes are you, Smee!";
	model.id	   =  "capnhook";
	model.FaceId	= 202;
	model.nation	  =  PIRATE;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "James T.";
	model.lastname = "Hook";
	model.ship = "US_Interceptor";	// GR: was "HMS_Bounty". "US_Interceptor" is "Lady Washington", which played Hook's ship in "Once Upon a Time"
	model.shipname = "Jolly Roger";
	model.Flags.Pirate = 15;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <--assign as captain only

	model.description =  "Crew cut, grey trousers, red leather boots and a shirt that fits loose and will show off some muscles!";
	model.id          =  "capstan";
	model.FaceId	  = "301";
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelTypeNation(isstart, model, "Sailors", 0.5, ENGLAND);.
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "Crew cut, grey trousers, red leather boots and a shirt that fits loose and will show off some muscles!";
	model.id          =  "capstan1";
	model.FaceId	  = "301";
	model.nation      =  ENGLAND;
	model.price       =  5000;
	model.assigned    =  true;
	AddCharacterModel(model);

	model.description =  "Crew cut, grey trousers, dark brown leather boots, a shirt that fits loose, a waistcoat and sword belt and the kid gloves are off.";
	model.id          =  "capstan2";
	model.FaceId	  = "301";
	model.nation      =  ENGLAND;
	model.price       =  10000;
	model.assigned	   =  true;
	AddCharacterModel(model);

	model.description =  "Crew cut, grey trousers, dark leather gold trim boots and a shirt that fits loose, a waistcoat and headband, bare knuckled. He makes a good Pirate!";
	model.id          =  "capstan3";
	model.FaceId	  = "301";
	model.nation      =  ENGLAND;
	model.price       =  15000;
	model.assigned    =  true;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "This pirate resembles one famous pennyless French Captain";
	model.id	   =  "Captaine_Chevalle";
	model.FaceId	= 417;
	model.nation	  =  FRANCE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Captaine";
	model.lastname = "Chevalle";
	model.Flags.Pirate = 8;
	model.shipname = "Fancy";
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "A flashy red coat, trimmed with golden leafs. And on top of that, an Indian pattern bandana. Now I look like a real 'gentlemen' pirate!";
	model.id	   =  "CaptainTeague";
	model.FaceId	= 337;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Teague";
	model.lastname = "Sparrow";
	model.Flags.Pirate = 6;
	model.Flags.Personal = 22;
	model.date.hour = 20;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 9;
	model.date.month = 6;
	model.date.year = 1740;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Oh, a bandanna, white long-sleeved shirt, light vest, just the thing to blend into the crowds...";
	model.id	   =  "Chameleon";
	model.FaceId	= 7;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AddCharacterModel(model);

	model.description =  "A white, loose long-sleeved shirt worn open, a straw hat, and some fat resembles a successful fisherman!";
	model.id	   =  "chelovek";
	model.FaceId	= 63;
	model.price	   =  30;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "For hanging out on the beach, mon, a blue long-sleeved shirt, not buttons, and a straw hat!";
	model.id	   =  "Chelovek1";
	model.FaceId	= 64;
	model.price	   =  40;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description	=  "Am I worthy to sail under Captain Jack Sparrow?";
	model.id		=  "cnorrington";
	model.FaceId		=  "186";
	model.nation		=  ENGLAND;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "I feel like James Norrington today, I need a nice golden trimmed Commodore's uniform, and don't forget the wig.";
	model.id	   =  "Conorrington";
	model.FaceId	= 233;
	model.minlevel     =  14;
	model.minrank	 =  7;
	model.nation	  =  ENGLAND;
	model.price	   =  15000;
	model.assigned	=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.ship = "HMS_Dauntless";
	model.shipname = "Dauntless";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	// Andouce: PotC Film Officers -->
	model.description =  "A veteran of the British Royal Navy, now Captain, if you will.";
	model.id          =  "GrovesCpt";
	model.FaceId      =  375;
	model.minlevel    =  6;
	model.minrank     =  6;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Theodore";
	model.lastname = "Groves";
//	model.storytitle = "";
	model.storytext = "You have been placed in command of your very own ship. Will you live up to be that fine officer?";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "An experienced Lieutenant Commander of the British Royal Navy, if you will.";
	model.id          =  "Groves";
	model.FaceId      =  375;
	model.minlevel    =  4;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  6500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
//	model.storytitle = "Lieutenant Commander";
	model.storytext = "After the promotion of James Norrington, you have been placed in charge of HMS Interceptor. Will you continue to retain her status as the fastest ship in His Majesty's Navy, one of the finest of Port Royal?";
	model.name = "Theodore";
	model.lastname = "Groves";
	model.ranktitle = "Commander";
	model.ship = "HMS_Interceptor";
	model.shipname = "Interceptor";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A nice Lieutenant, who now serves the EITC.";
	model.id          =  "Groves_EITC";
	model.FaceId      =  376;
	model.minlevel    =  4;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  6500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
//	model.storytitle = "Second in Command";
	model.storytext = "Having served under Commodore Norrington and chasing menacing pirates across the seas, you now find yourself serving your nation, under different interests. Welcome to the East India trading Company, Lieutenant!";
	model.name = "Theodore";
	model.lastname = "Groves";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A prestigious Commodore of the British Royal Navy shall do nicely.";
	model.id          =  "GrovesC";
	model.FaceId      =  377;
	model.minlevel    =  7;
	model.minrank     =  7;
	model.nation      =  ENGLAND;
	model.price       =  10000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Theodore";
	model.lastname = "Groves";
//	model.storytitle = "";
	model.storytext = "You have finally managed to be recognised for all the years of chasing that ridiculed pirate, with Commodore Norrington. He has placed you in command of HMS Dauntless. Will you continue to uphold the legacy of this mighty ship?";
	model.ship = "HMS_Dauntless";
	model.shipname = "Dauntless";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "The uniform of a Rear Admiral of the British Royal Navy, resembling that of Mr. Groves.";
	model.id          =  "GrovesA";
	model.FaceId      =  378;
	model.minlevel    =  8;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  12500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Theodore";
	model.lastname = "Groves";
//	model.storytitle = "";
	model.storytext = "As newly promoted Admiral of the Fleet, you are now in charge of Port Royal's finest ships.";
	model.ship = "HMS_Dauntless";
	model.shipname = "Dauntless";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "The most loyal Lieutenant of the British Royal Navy you can get.";
	model.id          =  "Gillette";
	model.FaceId      =  374;
	model.minlevel    =  4;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  5000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Andrew";
	model.lastname = "Gillette";
//	model.storytitle = "The Loyal Lieutenant";
	model.storytext = "After seeing the threats that oppose the nation first hand, you accompanied Commodore Norrington and your trusty companion Lieutenant Groves on many adventures. Now you have been placed in charge of HMS Interceptor and given your own place in the Royal Navy's finest. While young in the service, shall you continue to uphold your duties?";
	model.ship = "HMS_Interceptor";
	model.shipname = "Interceptor";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A captain of the EITC resembling young Groves would suit me fine.";
	model.id          =  "GrovesCpt_EITC";
	model.FaceId      =  379;
	model.minlevel    =  6;
	model.minrank     =  6;
	model.nation      =  ENGLAND;
	model.price       =  7500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Theodore";
	model.lastname = "Groves";
	model.storytext = "You have been placed in command of your own ship. Will you continue to serve the interests of the East India Trading Company? Or will you perhaps look to make a name for yourself elsewhere?";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;

	model.description =  "Looks like young Gillette has been promoted to captain.";
	model.id          =  "GilletteCpt";
	model.FaceId      =  380;
	model.minlevel    =  6;
	model.minrank     =  6;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Andrew";
	model.lastname = "Gillette";
	model.storytext = "You are still a young captain now. Will you prove that you are capable of defending the nation? Will you join your colleagues in becoming one of Port Royal's most successful officers?";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A fine commodore, loyal and duty bound while still young.";
	model.id          =  "GilletteC";
	model.FaceId      =  381;
	model.minlevel    =  7;
	model.minrank     =  7;
	model.nation      =  ENGLAND;
	model.price       =  10000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Andrew";
	model.lastname = "Gillette";
	model.storytext = "Climbing up the ranks, you have succeeded in becoming a fine officer. Now you have been placed in charge of HMS Dauntless, once under the command of Commodore Norrington. Will you continue to uphold the legacy of this powerful and old friend?";
	model.ship = "HMS_Dauntless";
	model.shipname = "Dauntless";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "The uniform of a Rear Admiral of the British Royal Navy, resembling that of Mr. Gillette.";
	model.id          =  "GilletteA";
	model.FaceId      =  382;
	model.minlevel    =  8;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  12500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Andrew";
	model.lastname = "Gillette";
	model.storytext = "As newly promoted Admiral of the Fleet, you are now in charge of Port Royal's finest ships.";
	model.ship = "HMS_Dauntless";
	model.shipname = "Dauntless";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "The uniform of a fine admiral of the British Royal Navy, resembling that of the dashing James Norrington.";
	model.id          =  "ANorrington";
	model.FaceId      =  383;
	model.minlevel    =  10;
	model.minrank     =  8;
	model.nation      =  ENGLAND;
	model.price       =  12500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "James";
	model.lastname = "Norrington";
	model.storytext = "As newly promoted Admiral of the Fleet, you are now in charge of Port Royal's finest ships.";
	model.ship = "HMS_Endeavour";
	model.shipname = "Endeavour";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);
	// Andouce: PotC Film Officers <--

	// assign as captain only -->
	model.description =  "Your average naval officer's uniform, with red hose.";
	model.id	   =  "Corsair1";
	model.FaceId	= 10;
	model.nation	  =  PIRATE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, "Captains", 1.0);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "A uniform fitting for a French corsair, blue hose.";
	model.id	   =  "Corsair1_1";
	model.FaceId	= 11;
	model.nation	  =  FRANCE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "Something cheap, salty looking, worn, that the officer of a merchantman would wear.";
	model.id	   =  "Corsair1_2";
	model.FaceId	= 12;
	model.nation	  =  PIRATE;
	model.price	   =  650;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "Bring out a Moor's naval uniform!  A Moor, a Moor, are ye daft?!?";
	model.id	   =  "Corsair1_3";
	model.FaceId	= 59;
	model.nation	  =  FRANCE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Henri";
	model.lastname = "Caesar";
	model.storytitle =  "The Haitian Revolution";
	model.storytext  =  "Born to a slave family on Hispaniola, you joined the revolution to see your island become independent from France. Your search in support has led you to the Pirate Brotherhood on Nevis.";
	model.playertype  = PLAYER_TYPE_REBEL;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 23;
	model.ship = "Schooner50";
	model.shipname = "Black Caesar";
	model.Flags.Pirate = 8;
	model.Flags.Personal = 36;
	model.date.year = 1803;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "A very slick-looking officer's uniform. With a small beard, little moustache and red hair.";
	model.id	   =  "Corsair1_4"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= "193";
	model.nation	  =  PIRATE;
	model.price	   =  1200;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, "Captains", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "A white half-sleeved shirt, light vest, eyepatch, do something with the hair, sounds like Pirate Eye For The Straight Guy, doesn't it?";
	model.id	   =  "Corsair2";
	model.FaceId	= 13;
	model.nation	  =  PIRATE;
	model.price	   =  300;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "Orange pants, brown coat, a sash... and a pegged leg, an eyepatch and a hook.";
	model.id	   =  "Corsair3";
	model.FaceId	= 14;
	model.nation	  =  PIRATE;
	model.price	   =  450;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "Give me a good officer's costume. But forget the navy blue. This time, I want it in purple!";
	model.id	   =  "Corsair4"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 250;
	model.nation	  =  SPAIN;
	model.price	   =  1200;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, "Captains", 1.0);
	AddCharacterModel(model);
	// <-- assign as captain only

	// assign as captain only -->
	model.description =  "Your average captain's uniform. But make the colour slightly less vibrant!";
	model.id	   =  "Corsair5"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 251;
	model.nation	  =  PIRATE;
	model.price	   =  1200;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AssignModelType(isstart, model, "Captains", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "Charles Ardent, pirate. Hero or villain - the choice is yours.";
	model.id	   =  "Ardent"; // Based on "Corsair1_4" and "Corsair5" from the "Sea Legend is Back"
	model.FaceId	= 243;
	model.nation	  =  PIRATE;
	model.price	   =  1200;
	model.assigned	=  true;
	model.name = "Charles";
	model.lastname = "Ardent";
//	model.storytitle =  "A Pirate's Life For Me"; // PB: Hide this one from Specific Characters because there is also a storyline
	model.storytext  =  "The Caribbean in the Golden Age of Piracy offers many opportunities for those willing to seize them. As a pirate, seizing things is your business!";
	model.loadingScreen = "Quest_Ardent.tga";
	model.playertype  = PLAYER_TYPE_CORSAIR;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 15;
	model.ship = "Cutter1";
	model.shipname = "Fortune";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 31;
	model.date.month = 7;
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description =  "Helen Ardent, pirate. Heroine or villainess - the choice is yours.";
	model.id	   =  "Ardent_F"; // Based on "Daniell2"
	model.FaceId	= 245;
	model.nation	  =  PIRATE;
	model.price	   =  1200;
	model.assigned	=  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Helen";
	model.lastname = "Ardent";
//	model.storytitle =  "A Female Pirate's Life For Me"; // PB: Hide this one from Specific Characters because there is also a storyline
	model.storytext  =  "The Caribbean in the Golden Age of Piracy offers many opportunities for those willing to seize them. As a pirate, seizing things is your business!";
	model.loadingScreen = "Quest_Ardent.tga";
	model.playertype  = PLAYER_TYPE_CORSAIR;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 15;
	model.ship = "Cutter1";
	model.shipname = "Fortune";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 31;
	model.date.month = 7;
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description =  "Helen Ardent, with a pirate's hat and coat.";
	model.id	=  "ArdentF_3"; // Based on "Daniell2"
	model.FaceId	=  600;
	model.nation	=  PIRATE;
	model.price	=  1200;
	model.assigned	=  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Helen";
	model.lastname = "Ardent";
	model.loadingScreen = "Quest_Ardent.tga";
	model.playertype  = PLAYER_TYPE_CORSAIR;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 15;
	model.ship = "Cutter1";
	model.shipname = "Fortune";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 31;
	model.date.month = 7;
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description	= "Shave and a haircut - two grand. You'd hardly recognise Charles Ardent!"
	model.id		=  "ArdentM_2"; // Based on "Blaze_NB"
	model.FaceId		=  586;
	model.nation		=  BROKEN; // Assigned during story
	model.price		=  2000;
	model.assigned		=  true;
	model.name		= "Charles";
	model.lastname		= "Ardent";
	AddCharacterModel(model);

	model.description	=  "Helen Ardent - in a dress?";
	model.id		=  "ArdentF_2"; // Based on "towngirl4" with texture from AoP lady_5"
	model.FaceId		=  587;
	model.nation		=  BROKEN; // Assigned during story
	model.price		=  2400;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name		= "Helen";
	model.lastname		= "Ardent";
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	=  "This ornate dress with golden trimming is very suitable for the daughter of a governor.";
	model.id		=  "Lucia_1";
	model.FaceId		=  360;
	model.nation		=  SPAIN; // made buyable
	model.price		=  2000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	model.name		= "Lucia";
	model.lastname		= "de la Vega";
	model.storytext  =  "Doomed to an unhappy marriage, you fled with a pirate. Now you have your own ship, will you lead an honest life or has your time with the pirate changed you forever?";
	model.playertype  = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 12;
	model.Flags.Personal = 5;
	model.ship = "SP_CastelF";
	model.shipname = "Intrépido";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 14;
	model.date.month = 8;
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description	=  "This is what happens when a pirate lady gets hold of some silk and lace.";
	model.id		=  "lucia_2"; // Based on "50_33Petra"
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.FaceId		=  588;
	model.nation		=  BROKEN; // Assigned during story
	model.price		=  2000;
	model.assigned		=  true;
	AddCharacterModel(model);

	model.description	= "Lucia de la Vega incognito.";
	model.id		= "AnimistLucia";  // Based on "Animistse"
	model.FaceId		= 598;
	model.nation		= BROKEN; // Assigned during story
	model.price		= 1000;
	model.assigned		= true;
	AddCharacterModel(model);

	model.description	= "An elaborate costume befitting the son of a governor.";
	model.id		= "Edmundo";
	model.FaceId		= 246;
	model.nation		= SPAIN; // made buyable
	model.price		= 2000;
	model.assigned		= true;
	model.iscombat		= false;
	model.name = "Edmundo";
	model.lastname = "de la Vega";
	model.storytext  =  "Doomed to an unhappy marriage, you fled with a female pirate. Now you have your own ship, will you lead an honest life or has your time with the pirate changed you forever?";
	model.playertype  = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 12;
	model.Flags.Personal = 5;
	model.ship = "SP_CastelF";
	model.shipname = "Intrépido";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 14;
	model.date.month = 8;
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description	= "Edmundo de la Vega incognito.";
	model.id		= "AnimistEdmundo";  // Based on "Animist4A"
	model.FaceId		= 599;
	model.nation		= BROKEN; // Assigned during story
	model.price		= 1000;
	model.assigned		= true;
	AddCharacterModel(model);

	model.description =  "A gentleman like this has no time for vagabonds - and may not be quite the gentleman he appears!";
	model.id	=  "PiersDowning";
	model.FaceId	= 354;
	model.nation	=  FRANCE;
	model.price	=  15000;
	model.assigned	=  true;
	model.assigned	=  true;
	model.name	= "Piers";
	model.lastname = "Downing";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 15;
	model.ship = "SwedishIndiaman1";
	model.shipname = "Entreprenant";
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description =  "A high-ranking French naval officer and gentleman.";
	model.id	=  "Rousselet";
	model.FaceId	=  571;
	model.minlevel	=  8;
	model.minrank	=  6;
	model.nation	=  FRANCE;
	model.price	=  15000;
	model.assigned	=  true;
	model.height	=  1.85;
	model.sex	=  "man";
	model.ani	=  "Rousselet";
	model.status	=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name	= "François-Louis";
	model.lastname	= "Rousselet";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 18;
	model.Flags.Personal = 23;
	model.ship = "WallerPinnace";
	model.shipname = "Le Saint Louis";
	model.date.year = 1671;
	AddCharacterModel(model);

	model.description	=  "An intricately decorated brown outfit for a veteran adventurer.";
	model.id		=  "Montoya";
	model.FaceId		=  573;
	model.nation		=  SPAIN;
	model.price		=  5000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex		=  "man";
	model.ani		=  "Rousselet";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.playertype  	= PLAYER_TYPE_ADVENTURER;
	AddCharacterModel(model);

	model.description	=  "A purple dress with lace trim and a lot of jewellery. She must be very important, very rich, or both.";
	model.id		=  "MariaAntonia";
	model.FaceId		=  575;
	model.nation		=  HOLLAND; // made buyable
	model.price		=  20000;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		=  false;
	model.playertype	= PLAYER_TYPE_SOCIAL_CLIMBER;
	model.Flags.Pirate	= 9;
	model.Flags.Personal	= 44;
	AddCharacterModel(model);

	model.description =  "A distinguished look for an important person - a governor or admiral, perhaps.";
	model.id	   =  "hub_spa5"; // Based on "hub_spa2" with parts from others
	model.FaceId	= 574;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A wealthy man's dark green suit with gold buttons and a medallion.";
	model.id	   =  "hub_por2"; // Retexture of "hub_spa3" with face from "huber_por2"
	model.FaceId	= 576;
	model.nation	  =  PORTUGAL;
	model.price	   =  10000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_SOCIAL_CLIMBER;
	AddCharacterModel(model);

	model.description =  "Charles Ardent has 'borrowed' a Spanish uniform.";
	model.id	=  "Ardent_S"; // Based on "Offic_spa_17"
	model.FaceId	= 244;
	model.nation	=  BROKEN; // Assigned during story
	model.price	=  850;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Charles Ardent has 'borrowed' a French uniform.";
	model.id	=  "Ardent_Fr"; // Based on "Offic_Fra_17"
	model.FaceId	= 327;
	model.nation	=  BROKEN; // Assigned during story
	model.price	=  850;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Helen Ardent has 'borrowed' a Spanish uniform.";
	model.id	   =  "Ardent_SF"; // Based on "Offic_spa_17"
	model.FaceId	= 248;
	model.nation	  =  BROKEN; // Assigned during story
	model.price	   =  850;
	model.sex       =  "woman";
	model.height      =  1.75;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Helen Ardent has 'borrowed' a French uniform.";
	model.id	   =  "Ardent_FrF"; // Based on "Offic_Fra_17"
	model.FaceId	= 328;
	model.nation	  =  BROKEN; // Assigned during story
	model.price	   =  850;
	model.sex       =  "woman";
	model.height      =  1.75;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description	=  "A blue sleeveless shirt, beard and scar for a tough guy who has stayed alive for a long time and plans to keep doing it!";
	model.id		=  "Louwman";
	model.FaceId		= 577;
	model.nation		= PIRATE;
	model.price		= 400;
	model.assigned		= true;
	AddCharacterModel(model);

	model.description =  "I feel like James Norrington today, I need a fine Captain uniform. And don't forget the wig!";
	model.id	   =  "Cpnorrington";
	model.FaceId	= 234;
	model.minlevel     =  12;
	model.minrank	 =  6;
	model.nation	  =  ENGLAND;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.ship = "HMS_Surprise";
	model.shipname = "Amazon";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "I feel like Horatio Nelson today, I need a fine Captain uniform. And don't forget the wig!";
	model.id	   =  "Cpnnelson";
	model.FaceId	= 103;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Horatio";
	model.lastname = "Nelson";
	model.storytitle =  "Nelson's First Command";
	model.storytext  =  "As a commissioned officer in His Majesty's Royal Navy, Horatio has been recently appointed commander of the brig HMS Badger. Will Horatio let his talents be known and make his way into the history books?";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 19;
	model.Flags.Personal = 20;
	model.ship = "HMS_Speedy";
	model.shipname = "Badger";
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 8;
	model.date.month = 12;
	model.date.year = 1778;
	AddCharacterModel(model);

	model.description =  "A young lady in a green and gold shirt, with red hair and freckles.";
	model.id	   =  "Dan_TG3";
	model.FaceId	= 207;
	model.nation	  =  ENGLAND;
	model.sex		 =  "woman";
	model.ani		 =  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Danielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringNot(PIRATE));
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "A nice Caribbean complexion, white open-collared longsleeved shirt, green vest, pony-tail hair, look what it does for the curves!  Speaking of which...";
	model.id	   =  "Danblack";
	model.FaceId	= 154;
	model.nation	  =  SPAIN;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Danielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "This lass in black leather is hard to resist. But can she be trusted?";
	model.id    	  =  "Daniell1"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 195;
	model.nation      =  PIRATE;
	model.price       =  2500;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Danielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Mates", 1.0, PIRATE);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "The kind of lady no sailor can fail to fall in love with upon first sight.";
	model.id    	  =  "Daniell2"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 196;
	model.nation      =  ENGLAND;
	model.price       =  2500;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Danielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "Looking real good in her hot red outfit.";
	model.id    	  =  "Daniell3"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 197;
	model.nation      =  SPAIN;
	model.price       =  2500;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Danielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Rich_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "Golden decorations adorn this white blouse - what there is of it!";
	model.id    	  =  "Lukreci";	// Danielle retexture by Nita
	model.FaceId	  =  578;
	model.nation      =  PORTUGAL;
	model.price       =  3500;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Lucrezia";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "A white longsleeved shirt open at the collar, light vest, draw the hair back in a pony-tail, look what it does for the curves!  Speaking of which...";
	model.id	   =  "Danielle";
	model.FaceId	= 15;
	model.nation	  =  ENGLAND;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Danielle";
	model.lastname = "Greene";
	model.storytitle =  "A Lady Scorned";
	model.storytext  =  "After having your heart broken by a scoundrel named Nathaniel Hawk, you have sworn to never fall for another man again. And whoever said a woman cannot captain a ship? This is the Golden Age of Piracy and there is opportunity aplenty for all those willing to take their chance!";
	model.ship = "Schooner2";
	model.shipname = "Vertigo";
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	model.Flags.Pirate = 21;
	model.Flags.Personal = 5;
	model.date.year = 1738;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "I DO have the face for tentacleys!";
	model.id          =  "DavyJones";
	model.FaceId      =  76;
	model.nation      =  PIRATE;
	model.price       =  3000;
	model.assigned    =  true;
	model.height	  =  1.85;
	model.sex	  =  "man";
	model.ani	  =  "Rousselet";
	model.status	  =  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name	  = "Davy";
	model.lastname	  = "Jones";
	model.storytitle  = "Lord of the Sea";
	model.storytext	  = "Having fallen for the treacherous godess of the sea herself, you got your heart broken as a result. Now all you have left is a thirst for vengeance and a ship to be reckoned with! And... you've got a trick up your sleeve to bring terror upon all souls at sea.";
	model.ship	  = "CursedDutchman";
	model.shipname	  = "Flying Dutchman";
	model.playertype  = PLAYER_TYPE_CURSED;
	model.difficulty  = DIFFICULTY_MARINER;
	model.Flags.Pirate = 15;
	model.Flags.Personal = 12;
	model.date.hour = 10;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 18;
	model.date.month = 6;
	model.date.year = 1665;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Black loose trowsers, a light shirt, sash, bandanna, something that will compliment dreadlocks.";
	model.id	   =  "depp";
	model.FaceId	= 418;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.difficulty = DIFFICULTY_MARINER;
	model.ship = "BlackPearl";
	model.shipname = "Black Pearl";
	model.Flags.Pirate = 6;
	model.Flags.Personal = 22;
	model.date.hour = 20;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 9;
	model.date.month = 6;
	model.date.year = 1740;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "Black loose trowsers, a steel cuirass, sash, bandanna, something that will compliment dreadlocks.";
	model.id	   =  "depp_A1";
	model.FaceId	= "depp";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Black loose trowsers, an engraved breastplate, sash, bandanna, something that will compliment dreadlocks.";
	model.id	   =  "depp_A2";
	model.FaceId	= "depp";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Black loose trowsers, a gilded breastplate, sash, bandanna, something that will compliment dreadlocks.";
	model.id	   =  "depp_A3";
	model.FaceId	= "depp";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "A dirty shirt and a leaky boat aren't going to stop you from looking for an adventure.";
	model.id		=  "Anamaria";
	model.FaceId		=  361;
	model.nation		=  PIRATE;
	model.price		=  1500;
	model.assigned		=  true;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.name = "";
	model.lastname = "Anamaria";
	model.playertype = PLAYER_TYPE_SMUGGLER;	// was PLAYER_TYPE_ADVENTURER
	model.difficulty = DIFFICULTY_MARINER;
	model.ship = "Tartane50";
	model.shipname = "Jolly Mon";
	model.Flags.Pirate = 28;
	model.Flags.Personal = 3;
	model.date.hour = 20;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 9;
	model.date.month = 6;
	model.date.year = 1740;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "Blaze Devlin. In his original view.";
	model.id		=  "Devlin";
	model.FaceId		=  292;
	model.nation		=  SPAIN;
	model.price		=  1000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex		=  "man";
	model.ani		=  "Blaze";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name = "Blaze";
	model.lastname = "Devlin";
	model.storytitle =  "Age of Pirates";
	model.storytext  =  "Brother to another well-known character, Blaze Devlin is a corsair always on the hunt for treasure. But what Caribbean Tales lie in store for you? The choice is up to you!";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 6;
	model.ship = "Barque2";
	model.shipname = "Fool's Gold";
	model.date.hour = 21;
	model.date.min = 11;
	model.date.sec = 12;
	model.date.day = 11;
	model.date.month = 7;
	model.date.year = 1550;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// Armor Mod -->
	/*model.description =  "";
	model.id	  	  =  "Devlin_A1";
	model.FaceId	  =  "Devlin";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  1000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	  	  =  "Devlin_A2";
	model.FaceId	  =  "Devlin";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  4000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	  	  =  "Devlin_A3";
	model.FaceId	  =  "Devlin";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  15000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	  	  =  "Devlin_A4";
	model.FaceId	  =  "Devlin";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  25000;
	model.assigned	  =  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description	=  "The son of a French nobleman, who became a well known captain after coming to the Caribbean in quite hasty circumstances.";
	model.id		=  "Sharl";
	model.FaceId		=  595;
	model.nation		=  FRANCE;
	model.price		=  1000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex		=  "man";
	model.ani		=  "Blaze";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name = "Charles";
	model.lastname = "de Maure";
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "How about a nice young impressionable cabin boy type?";
	model.id       =  "Diller";
	model.FaceId	= 200;
	model.nation      =  SPAIN;
	model.price       =  1000;
	model.ani         =  "Diller";
	model.height      =  1.75;
	model.assigned	  =  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "How about a nice young impressionable Iberian cabin boy type?";
	model.id       =  "Jordano";
	model.FaceId	= 249;
	model.nation      =  SPAIN;
	model.price       =  1000;
	model.ani         =  "Diller";
	model.height      =  1.75;
	model.assigned	  =  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description	=  "Pretty woman, must be a governor's niece or wife";
	model.id			=  "Diz1";
	model.FaceId		=  350; // TALISMAN changed was 334
	model.nation		=  FRANCE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex			=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.ismansion		=  true;//Pretty woman, must be a governor's niece or wife
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	model.description	=  "Pretty woman, must be a governor's niece or wife";
	model.id			=  "Diz2";
	model.FaceId		=  350; // TALISMAN changed was 335
	model.nation		=  ENGLAND;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.72;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.ismansion		=  true;//Pretty woman, must be a governor's niece or wife
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgir51";
	model.FaceId		=  107;  // TALISMAN changed was 341
	model.nation		=  ENGLAND;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.70;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, ENGLAND);
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgir52";
	model.FaceId		=  168;// TALISMAN changed was 342
	model.nation		=  SPAIN;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.70;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, SPAIN);
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgir53";
	model.FaceId		=  168; // TALISMAN changed was 343
	model.nation		=  HOLLAND;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, HOLLAND);
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgirl1";
	model.FaceId		=  170; // TALISMAN changed was 344
	model.nation		=  ENGLAND;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex			=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, ENGLAND);
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgirl2";
	model.FaceId		=  108; // TALISMAN changed was 345
	model.nation		=  PORTUGAL;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.72;
	model.sex			=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, PORTUGAL);
	AddCharacterModel(model);

	model.description	=  "A woman who knows more about things than she appears to.";
	model.id			=  "Downgirl3";
	model.FaceId		=  170; // TALISMAN changed was 346
	model.nation		=  FRANCE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.78;
	model.sex			=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.isbrothel		=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.03, FRANCE);
	AddCharacterModel(model);

	model.description	=  "Have you a nice green dress like the one worn by the tavern girl in Cartagena?";
	model.id		=  "Jimena";	// Specifically for Cartagena tavern 2, not to appear randomly - GR
	model.FaceId		=  589;
	model.nation		=  SPAIN;
	model.price		=  8000;
	model.assigned		=  true;
	model.height		=  1.72;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	AddCharacterModel(model);

	model.description	=  "A dark red dress with blue sleeves and skirt marks its owner as a woman of wealth.";
	model.id		=  "lady1";	// Based on AoP "lady1" texture modified onto "towngirl5" model
	model.FaceId		=  359;
	model.nation		=  ENGLAND;
	model.price		=  8000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex		=  "woman";
//	model.ani			=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.name	= "Valerie";
	model.lastname = "Downing";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.Flags.Pirate = 1;
	model.Flags.Personal = 15;
	model.ship = "SwedishIndiaman1";
	model.shipname = "Entreprenant";
	model.date.year = 1691;
	AddCharacterModel(model);

	model.description	=  "This lady in a dark blue dress with yellow trimmings could be a governor's wife.";
	model.id		=  "lady3";	// Based on AoP "lady3" texture modified onto "towngirl7" model
	model.FaceId		=  330;
	model.nation		=  ENGLAND;
	model.price		=  8000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.ismansion		=  true;//Could be a governor's wife
	AddCharacterModel(model);

	model.description	=  "This light blue dress with white trimmings would suit any lady from a wealthy family.";
	model.id		=  "lady6";	// Based on AoP "lady6" texture modified onto "towngirl7" model
	model.FaceId		=  591;
	model.nation		=  ENGLAND;
	model.price		=  9000;
	model.assigned		=  true;
	model.height		=  1.75;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat		=  -1;
	model.ismansion		=  true;//Could be a governor's wife
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	// Thomas the Terror EITC officers -->
	model.description =  "A proud captain of the East India Trading Company Armed Escort Fleet uniform please. I know, it is a long title, but I am proud of it.";
	model.id          =  "Eitc_cpt1_47";
	model.FaceId      =  356; // TALISMAN changed was 305
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);

	model.description =  "A EITC Armed Escort Fleet Captain's uniform.  Made for only the luckiest of jack-tars.";
	model.id          =  "Eitc_cpt2_47";
	model.FaceId      =  356;  // TALISMAN changed was 306
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);

	model.description =  "A EITC Lieutenant's uniform.";
	model.id          =  "Eitc_lt1_47";
	model.FaceId      =  87; // TALISMAN changed was 307
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);

	model.description =  "A EITC Lieutenant's uniform. Hmm... reminds me of young Tom. Damn fine seaman, that lad. Very promising young officer";
	model.id          =  "Eitc_lt2_47";
	model.FaceId      =  87; // TALISMAN changed was 308
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);

	model.description =  "A EITC Lieutenant's uniform.  Do you fancy yourself a poet?";
	model.id          =  "Eitc_lt3_47";
	model.FaceId      =  87;  // TALISMAN changed was 309
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AddCharacterModel(model);
	// <-- Thomas the Terror EITC officers

	// GhostOfDeath91 EITC soldiers -->
	model.description =  "A proud officer of the EITC's own regiment.";
	model.id          =  "Offic_EITC";
	model.FaceId      =  572;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  2000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Officers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment, with long, dark sideburns.";
	model.id          =  "Soldier_EITC";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A fresh-faced young soldier of the EITC's own regiment.";
	model.id          =  "Soldier_EITC2";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment with a neatly trimmed moustache.";
	model.id          =  "Soldier_EITC3";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment. Have the barber trim the goatee!";
	model.id          =  "Soldier_EITC4";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment. The barber is just down the street.";
	model.id          =  "Soldier_EITC5";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment who takes as much care of his beard as his equipment.";
	model.id          =  "Soldier_EITC6";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);

	model.description =  "A soldier of the EITC's own regiment with fair hair and sideburns.";
	model.id          =  "Soldier_EITC7";
	model.FaceId      =  572;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelType(isstart, model, "Merchant_Soldiers", 1.0);
	AddCharacterModel(model);
	// <-- GhostOfDeath91 EITC soldiers

	// no model assignment quest character -->
	model.description	=  "Spanish grandee in the past, he was forced to leave the country. Hates englishmen and... friends betrayers.";
	model.id			=  "Espinosa";
	model.FaceId		=  324;
	model.nation		=  SPAIN;
	model.price			=  3700;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "Blaze";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name			= "Diego";
	model.lastname		= "de Espinosa"; // KK
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// Armor Mod -->
	/*model.description =  "Spanish grandee protected by a steel cuirass.";
	model.id	  	  =  "Espinosa_A1";
	model.FaceId	  =  "Espinosa";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  1000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "Spanish grandee protected by an engraved breastplate.";
	model.id	  	  =  "Espinosa_A2";
	model.FaceId	  =  "Espinosa";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  4000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "Spanish grandee protected by a gilded breastplate.";
	model.id	  	  =  "Espinosa_A3";
	model.FaceId	  =  "Espinosa";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  15000;
	model.assigned	  =  true;
	AddCharacterModel(model);

	model.description =  "Spanish grandee protected by an ornate breastplate.";
	model.id	  	  =  "Espinosa_A4";
	model.FaceId	  =  "Espinosa";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	  	  =  25000;
	model.assigned	  =  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	// no model assignment quest character -->
	model.description =  "I feel like a trader. But a shady one. How about a Buccaneer like Eugene Martin?";
	model.id	   =  "Eugene_Martin";
	model.FaceId	= 71;
	model.nation	  =  FRANCE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Eugene";
	model.lastname = "Martin";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "A light blue open-collared longsleeved shirt, brown vest, burgundy laced bodice, pony-tail hair, look what it does for the curves!  Speaking of which...";
	model.id	   =  "Fanielle";
	model.FaceId	= 155;
	model.nation	  =  ENGLAND;
	model.sex		=  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Fanielle";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description =  "How about just a brown vest, and no shirt, with all that weight and no hair it's probably warm enough...";
	model.id	   =  "fatman";
	model.FaceId	= 61;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "A white shirt and vest big enough to accommodate some heavy girth, and there is no need for a barber.";
	model.id	   =  "fatman1";
	model.FaceId	= 130;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Something that just cries out... Big Pirate... A striped shirt, red vest, and a mustache!";
	model.id	   =  "Fatman2";
	model.FaceId	= 62;
	model.nation	  =  SPAIN;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "With a heavy build, baldness, and some stubble a white shirt and a brown vest make one look like a successful, seasoned merchant.";
	model.id	   =  "Fatman2_1";
	model.FaceId	= 60;
	model.nation	  =  FRANCE;
	model.price	   =  250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "A sailor's dress uniform, maybe a little old, with room for a big guy.  And a watch-cap, please!";
	model.id	   =  "Fawn";
	model.FaceId	= 17;
	model.nation	  =  ENGLAND; // Estharos reassign April 8th, 2009
	model.price	   =  250;
	model.assigned	=  true;
	model.name = "Ralph";
	model.lastname = "Fawn";
	model.playertype = PLAYER_TYPE_SAILOR;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "For going fishing, a small brown vest, and a battered hat do the trick, no need for a shirt!";
	model.id	   =  "fisherman";
	model.FaceId	= 131;
	model.price	   =  40;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "The right thing for fishing is a small vest and a wide brimmed hat.  Tartanas are sold at the shipyard...";
	model.id	   =  "fisherman1";
	model.FaceId	= 132;
	model.price	   =  40;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "A straw hat and simple jacket are enough for a pirate captain. Perhaps even a Pirate King one day...";
	model.id	   =  "Monkey_D_Luffy";
	model.FaceId	= 329;
	model.nation	  =  PIRATE;
	model.price	   =  40;
	model.assigned	=  true;
//	model.storytitle = "One Piece";
	model.storytext = "Having eaten a magic fruit and narrowly avoided being eaten yourself, you now sail the seas in search of the One Piece. Can you rise to become a Pirate King?";
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	model.name = "Monkey";
   	model.middlename = "D.";
	model.lastname = "Luffy";
	model.ship = "BrigRoyal";
	model.shipname = "Going Merry";
	model.Flags.Pirate = 17;
	model.Flags.Personal = 13;
//	model.date.year = 1720;
	AddCharacterModel(model);

	// JMV's French officer models recoded by Jack Davidson using JMV's textures based on original Akella models -->
	model.description =  "An officer of His Majesty's infantry regiments";
	model.id          =  "fra_18_O";
	model.FaceId      =  101;
	model.nation      =  FRANCE;
	model.price       =  4500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A French Admiral's uniform. Oui, and send for my barber, s'il vous plait.";
	model.id          =  "fra_adm_18";
	model.FaceId      =  101;
	model.minlevel    =  16;
	model.minrank     =  8;
	model.nation      =  FRANCE;
	model.price       =  9000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A French Naval Commodore's uniform. Oui, C'est très bon.";
	model.id          =  "fra_cmd_18";
	model.FaceId      =  101;
	model.minlevel    =  14;
	model.minrank     =  7;
	model.nation      =  FRANCE;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A French Naval Captain's uniform. Oui, I think even my English cousins in Bath would approve";
	model.id          =  "fra_cpt_18";
	model.FaceId      =  101;
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  FRANCE;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, FRANCE);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A French Naval Captain's uniform. I only need a Corvette and a crew to compliment all this, monsieur!";
	model.id          =  "fra_cpt2_18";
	model.FaceId      =  101;
	model.minlevel    =  10;
	model.minrank     =  5;
	model.nation      =  FRANCE;
	model.price       =  7000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, FRANCE);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A French Naval Lieutenant's uniform, s'il vous plait. Young and bold indeed... but a buccaneer? No, you are surely mistaken, monsieur!";
	model.id          =  "fra_lut_18";
	model.FaceId      =  101;
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  FRANCE;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, FRANCE);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A French Naval Lieutenant's uniform, s'il vous plait. Blue and white from 'la mère' and 'rouge' from blood!";
	model.id          =  "fra_lut2_18";
	model.FaceId      =  101;
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  FRANCE;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, FRANCE);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A French Naval Lieutenant's uniform. And please leave the moustache as it is now, s'il vous plait.";
	model.id          =  "fra_lut3_18";
	model.FaceId      =  101;
	model.minlevel    =  6;
	model.minrank     =  3;
	model.nation      =  FRANCE;
	model.price       =  4000;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, FRANCE);	// ccc Feb06
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "Fred Bob the pirate!";
	model.id	   =  "FredBob";
	model.FaceId	= 151;
	model.nation	  =  BROKEN; // Unique
	model.price	   =  1000;
	model.assigned	=  true;
//	model.name = "Fred";
//	model.lastname = "Bob";
	AddCharacterModel(model);
	// <-- // no model assignment quest character

	// For the Bartolomeu o Portugues quest -->
	model.description =  "I feel like the Director of the Dutch West India Compagny. How about something like Gherarde de Jongh.";
	model.id	   =  "Gherarde_De_Jongh";
	model.FaceId	= 367;
	model.nation	  =  HOLLAND;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Gherarde";
	model.lastname = "de Jongh";
	AddCharacterModel(model);

	model.description	= "I want to look like Guibert Daudet.";
	model.id		= "Guibert_Daudet";
	model.FaceId		= 594;
	model.nation		= FRANCE;
	model.price		= 200;
	model.assigned		= true;
	model.name		= "Guibert";
	model.lastname		= "Daudet";
	AddCharacterModel(model);
	// <-- For the Bartolomeu o Portugues quest

	// assign as captain only -->
	model.description =  "Not even a missing eye can detract from this lady's... charms, which are sure to turn a few heads - before lopping them off!";
	model.id	   =  "girlpatch";
	model.FaceId	= 206;
	model.nation	  =  FRANCE;
	model.sex		 =  "woman";
//	model.ani		 =  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1500;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "If you want to know what the future holds for you, this woman can tell you - for a hand full of silver.";
	model.id	=  "gipsygirl";
	model.FaceId	= 581;
	model.nation	=  SPAIN;
	model.price	=  1600;
	model.height	=  1.75;
	model.sex	=  "woman";
//	model.ani =  "towngirl";
	model.ani	=  "woman_sit";
	model.assigned	=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AddCharacterModel(model);

	model.description =  "Phinneas Wake, the Gypsy Captain, has spent a long time prowling the Spanish Main... and has the scars to prove it!";
	model.id	   =  "gypsycaptain";
	model.FaceId	= 201;
	model.nation	  =  PORTUGAL;
	model.price	   =  1700;
	model.assigned	=  true;
	model.name = "Phinneas";
	model.lastname = "Wake";
	AddCharacterModel(model);

	model.description =  "A nice red coat and bandanna, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_1";
	model.FaceId	= 188;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "A nice red coat, bandanna and steel breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_1_A1";
	model.FaceId	= "GypsyCaptn_1";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, bandanna and engraved breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_1_A2";
	model.FaceId	= "GypsyCaptn_1";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, bandanna and gilded breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_1_A3";
	model.FaceId	= "GypsyCaptn_1";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A nice red coat and bandanna, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_2";
	model.FaceId	= 189;
	model.nation	  =  PORTUGAL;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "A nice red coat, bandanna and steel breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_2_A1";
	model.FaceId	= "GypsyCaptn_2";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, bandanna and engraved breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_2_A2";
	model.FaceId	= "GypsyCaptn_2";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, bandanna and gilded breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_2_A3";
	model.FaceId	= "GypsyCaptn_2";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A nice red coat and tricorn hat, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_3";
	model.FaceId	= 190;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "A nice red coat, tricorn hat and steel breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_3_A1";
	model.FaceId	= "GypsyCaptn_3";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, tricorn hat and engraved breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_3_A2";
	model.FaceId	= "GypsyCaptn_3";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice red coat, tricorn hat and gilded breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_3_A3";
	model.FaceId	= "GypsyCaptn_3";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A rich red coat and tricorn hat, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_4";
	model.FaceId	= 191;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "A rich red coat, tricorn hat and steel breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_4_A1";
	model.FaceId	= "GypsyCaptn_4";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A rich red coat, tricorn hat and engraved breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_4_A2";
	model.FaceId	= "GypsyCaptn_4";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A rich red coat, tricorn hat and gilded breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_4_A3";
	model.FaceId	= "GypsyCaptn_4";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A nice grey coat and bandanna, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_5";
	model.FaceId	= 373;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  75;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "A nice grey coat, bandanna and steel breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_5_A1";
	model.FaceId	= "GypsyCaptn_5";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice grey coat, bandanna and engraved breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_5_A2";
	model.FaceId	= "GypsyCaptn_5";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice grey coat, bandanna and gilded breastplate, that's the perfect outfit for a Portuguese Pirate.";
	model.id	   =  "GypsyCaptn_5_A3";
	model.FaceId	= "GypsyCaptn_5";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A perfect outfit for an infiltration mission in Spanish towns.";
	model.id	   =  "GypsyCaptn_6";
	model.FaceId	= 364;
	model.nation	  =  PORTUGAL;
	model.price	   =  500;
	model.assigned	=  true;
	model.camouflage = true; // PB: Camouflage mod
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	model.description =  "Everything is possible; even Bartolomeu wearing a Spanish uniform.";
	model.id	   =  "GypsyCaptn_7";
	model.FaceId	= 484;
	model.nation	  =  PORTUGAL;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	model.description =  "A Bartolomeu's outfit appropriated for big expeditions.";
	model.id	   =  "GypsyCaptn_8";
	model.FaceId	= 485;
	model.nation	  =  PORTUGAL;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	model.description =  "The perfect outfit for a marooned Bartolomeu.";
	model.id	   =  "GypsyCaptn_9";
	model.FaceId	= 112;
	model.nation	  =  PORTUGAL;
	model.price	   =  1;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);

	model.description =  "Bartolomeu o Portugues disguised in Spanish aristocrat; Everything is possible!";
	model.id	   =  "GypsyCaptn_10";
	model.FaceId	= 113;
	model.nation	  =  PORTUGAL;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);
	
	model.description =  "A perfect outfit for an infiltration mission in Spanish towns.";
	model.id	   =  "GypsyCaptn_11";
	model.ani		 =  "climb";	
	model.FaceId	= 364;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Bartolomeu";
	model.lastname = "o Portugues";
	model.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 4;
	model.Flags.Personal = 8;
	model.ship = "FastCaravel";
	model.shipname = "Santiago";
	model.date.hour = 9;
	model.date.min = 17;
	model.date.sec = 42;
	model.date.day = 22;
	model.date.month = 7;
	model.date.year = 1660;
	AddCharacterModel(model);	

	// Seb:
	model.description =  "Billions of Blue Blistering Barnacles! What do you mean 'I look drawn'? I'm as real as they come!";
	model.id	   =  "hadoque";
	model.FaceId	= 79;
	model.nation	  =  FRANCE;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "François";
	model.lastname = "de Hadoque";
	model.ship = "FR_Licorne";
	model.shipname = "La Licorne";
	AddCharacterModel(model);

	// For the Bartolomeu o Portugues quest -->
	model.description =  "I feel like a famous pirate. Henry Morgan will do.";
	model.id	   =  "Henry_Morgan";
	model.FaceId	= 73;
	model.nation	  =  PIRATE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Henry";
	model.lastname = "Morgan";
	model.ship = "RN_WarGalleon";
	model.shipname = "Jamaica Merchant";
	AddCharacterModel(model);
	// <-- For the Bartolomeu o Portugues quest
	
	// For a Family story quest -->
	model.description =  "A very wealthy-looking guy you could easily imagine to be a Spanish merchant.";
	model.id	   =  "FernandoSuarez";
	model.FaceId	= 584;
	model.nation	  =  SPAIN;
	model.price	   =  2750;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- For a Family story quest	

	model.description =  "An eldery beggar, who spent all his money on women and booze. But still a good poet!";
	model.id	   =  "HenryBeggar";
	model.FaceId	= 4;
	model.nation	  =  BROKEN;
	model.price	   =  1;
	model.assigned	=  true;
	model.name = "Henry";
	model.lastname = "the Beggar";
	AddCharacterModel(model);

	model.description =  "A very wealthy-looking guy you could easily imagine to be a governor.";
	model.id	   =  "hub_spa2"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 252;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "hub_spa3"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 253;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "A nice and colourful look for a very wealthy and important person.";
	model.id	   =  "hub_spa4"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 254;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "For the accomplished, successful, and corpulent Englishman, a big official blue coat.  Find someone who can powder the hair, too!";
	model.id	   =  "huber_eng";
	model.FaceId	= 45;
	model.nation	  =  ENGLAND;
	model.price	   =  9000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "huber_fra";
	model.FaceId	= 98;
	model.nation	  =  FRANCE;
	model.price	   =  15000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "Huber_Fra_17";
	model.FaceId	= 420;
	model.nation	  =  FRANCE;
	model.price	   =  15000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "Huber_Fra2_17";
	model.FaceId	= 421;
	model.nation	  =  FRANCE;
	model.price	   =  15000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "Huber_Fra3_17";
	model.FaceId	= 422;
	model.nation	  =  FRANCE;
	model.price	   =  15000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "Huber_Fra4_17";
	model.FaceId	= 423;
	model.nation	  =  FRANCE;
	model.price	   =  15000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "An Elizabethan collar and frills, dark vested suit, no hat, something that cries out Iberian distinction!";
	model.id	   =  "huber_por";
	model.FaceId	= 8;
	model.nation	  =  PORTUGAL;
	model.price	   =  12000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringSouthEuro());
	model.period = "" + PERIOD_EARLY_EXPLORERS + PERIOD_THE_SPANISH_MAIN;
	AddCharacterModel(model);

	model.description =  "An older, wealthy man with a white collar.";
	model.id	   =  "huber_por2"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 255;
	model.nation	  =  PORTUGAL;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "THIS kit has Elizabethan collars as well, a blue suit, and no hat is required to set of the latest fashion from Madrid!";
	model.id	   =  "Huber_spa";
	model.FaceId	= 92;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringSouthEuro());
	model.period = "" + PERIOD_EARLY_EXPLORERS + PERIOD_THE_SPANISH_MAIN;
	AddCharacterModel(model);

	model.description =  "A rich aristocrat in an elaborate green outfit.";
	model.id	   =  "huber_spa5"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 256;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	model.period = "" + PERIOD_EARLY_EXPLORERS + PERIOD_THE_SPANISH_MAIN;
	AddCharacterModel(model);

	model.description =  "A rich aristocrat with an elaborate black and silver outfit.";
	model.id	   =  "huber_spa6"; // Adapted from CoAS model Blood_TDM
	model.FaceId	= 336;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNot(PIRATE));
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Hol1_17";
	model.FaceId	= 424;
	model.nation	  =  HOLLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Hol2_17";
	model.FaceId	= 425;
	model.nation	  =  HOLLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Eng2_17";
	model.FaceId	= 419;
	model.nation	  =  ENGLAND;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Spa1_17";
	model.FaceId	= 427;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Spa2_17";
	model.FaceId	= 428;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Spa4_17";
	model.FaceId	= 429;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "An upper-class aristocrat with a very elaborate costume.";
	model.id	   =  "Huber_Por_17";
	model.FaceId	= 426; // TALISMAN changed was 427
	model.nation	  =  PORTUGAL;
	model.price	   =  10000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Rich_Citizens", 1.0); //Pirates too
	AddCharacterModel(model);

	model.description =  "This Admiral's uniform harkens to a more classic time, lending dignity and stateliness to any quarterdeck.";
	model.id	   =  "hugnt18";
	model.FaceId	= 89;
	model.minlevel     =  16;
	model.minrank	 =  8;
	model.nation	  =  FRANCE;
	model.price	   =  8000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AssignModelTypeNation(isstart, model, "Rich_Citizens", 1.0, PIRATE);
	AddCharacterModel(model);

	// Native (Indian's) -->
	model.description =  "A beautiful indian woman, which sailor couldn't fall in love with this Pocahontas?";
	model.id	   =  "Indian_girl1";
	model.FaceId	= 242;
	model.price	   =  100;
	model.height	  =  1.75;
	model.sex =  "woman";
//	model.ani =  "towngirl";
	model.ani		=  "woman_sit";
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "A woman from a native village, in traditional dress.";
	model.id	   =  "Indian_girl2";
	model.FaceId	= 596;
	model.price	   =  100;
	model.height	  =  1.75;
	model.sex =  "woman";
	model.ani		=  "woman_sit";
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "An elderly Indian.";
	model.id	   =  "Indian1";
	model.FaceId	= 240;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "A very natural look, a pack of native clothes would be good.";
	model.id	   =  "Indian1_1";
	model.FaceId	= 236;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "Clothes of a Caribbean indian.";
	model.id	   =  "Indian1_2";
	model.FaceId	= 237;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "Native is the word! Some Indians clothes.";
	model.id	   =  "Indian1_3";
	model.FaceId	= 238;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "Clothes of a Native Warrior.";
	model.id	   =  "Indian2";
	model.FaceId	= 239;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);

	model.description =  "An Indian Warrior.";
	model.id	   =  "Indian3";
	model.FaceId	= 241;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Indians", 1.0);
	AddCharacterModel(model);
	// <-- Native (Indian's)

	model.description =  "Dark blue loose trowsers, a light shirt, sash, bandanna, something that will compliment dreadlocks. And don't forget me effects!";
	model.id	   =  "Jack";
	model.FaceId	= 57;
	model.nation	  =  PIRATE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	model.playertype = PLAYER_TYPE_ADVENTURER;
	model.difficulty = DIFFICULTY_MARINER;
	model.ship = "UncursedPearl";
	model.shipname = "Black Pearl";
	model.Flags.Pirate = 6;
	model.Flags.Personal = 22;
	model.date.hour = 20;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 9;
	model.date.month = 6;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "The search for the chest is the search for the divine in all of us.";
	model.id	   =  "JGod";
	model.FaceId	= 83; // TALISMAN changed was 57
	model.nation	  =  PIRATE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Sparrow";
	AddCharacterModel(model);

	model.description =  "The best gunsmith in the Caribbean, if you please!";
	model.id	   =  "Jack_Rackham";
	model.FaceId	= 537; // TALISMAN changed was 60, JRH changed was 11
	model.nation	  =  PIRATE;
	model.price	   =  1500;
	model.assigned	=  true;
	model.name = "Jack";
	model.lastname = "Rackham";
	AddCharacterModel(model);

	// For future quests -->
	model.description =  "I feel like an unlucky English Soldier. How about something like Jeremy Tripper ?";
	model.id	   =  "Jeremy_Tripper";
	model.FaceId	= 371;
	model.nation	  =  ENGLAND;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Jeremy";
	model.lastname = "Tripper";
	AddCharacterModel(model);
	// For future quests <--

	model.description =  "Talk about the latest from Paris, a red striped-and-frilled coat, sash, NICE hat, and a 'do that a barber will take hours over!";
	model.id	   =  "LaCroix";
	model.FaceId	= 445;
	model.nation	  =  FRANCE;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Jean";
	model.lastname = "de la Croix";
	model.storytitle =  "Tales of a Chevalier";
	model.storytext  =  "A charming French nobleman with a rogue streak. Your latest endeavour left you several jewels richer and a Spanish lady somewhat distraught. Her brother challenged you to a duel at dawn to settle the score.";
	model.loadingScreen = "Character_LaCroix.tga";
	model.playertype = PLAYER_TYPE_ROGUE;
	model.difficulty = DIFFICULTY_MARINER;
	model.Flags.Pirate = 3
	model.Flags.Personal = 3;
	model.ship = "Schooner2";
	model.shipname = "Le Cheval Furieux";
	model.date.hour = 20;
	model.date.min = 24;
	model.date.sec = 42;
	model.date.day = 1;
	model.date.month = 3;
	model.date.year = 1690;
	AddCharacterModel(model);

	// For the assassin quest -->
	model.description =  "I feel like a famous mercenary. How about something like Johan Elting?";
	model.id	   =  "Johan_Elting";
	model.FaceId	= 412;
	model.nation	  =  HOLLAND;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Johan";
	model.lastname = "Elting";
	model.playertype = PLAYER_TYPE_MILITARY;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 2;
	model.Flags.Personal = 9;
	model.ship = "Barque4_47";
	model.shipname = "Neptunis";
	model.date.hour = 11;
	model.date.min = 43;
	model.date.sec = 12;
	model.date.day = 8;
	model.date.month = 10;
	model.date.year = 1665;
	AddCharacterModel(model);

	model.description =  "I feel like a famous mercenary. How about something like Johan Elting? But not too conspicuous.";
	model.id	   =  "Johan_Elting_b";
	model.FaceId	= 412;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.camouflage = true; // PB: Camouflage mod
	model.name = "Johan";
	model.lastname = "Elting";
	model.playertype = PLAYER_TYPE_MILITARY;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 2;
	model.Flags.Personal = 9;
	model.ship = "Barque4_47";
	model.shipname = "Neptunis";
	model.date.hour = 11;
	model.date.min = 43;
	model.date.sec = 12;
	model.date.day = 8;
	model.date.month = 10;
	model.date.year = 1665;
	AddCharacterModel(model);

	model.description =  "I feel like a famous mercenary. How about something like Johan Elting with his dark outfit?";
	model.id	   =  "Johan_Elting_c";
	model.FaceId	= 439;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Johan";
	model.lastname = "Elting";
	model.playertype = PLAYER_TYPE_MILITARY;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 2;
	model.Flags.Personal = 9;
	model.ship = "Barque4_47";
	model.shipname = "Neptunis";
	model.date.hour = 11;
	model.date.min = 43;
	model.date.sec = 12;
	model.date.day = 8;
	model.date.month = 10;
	model.date.year = 1665;
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "I feel like a famous mercenary. How about something like Johan Elting with his dark outfit and unadorned steel breastplate?";
	model.id	   =  "Johan_Elting_c_A1";
	model.FaceId	= 439;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I feel like a famous mercenary. How about something like Johan Elting with his dark outfit and engraved steel breastplate?";
	model.id	   =  "Johan_Elting_c_A2";
	model.FaceId	= 439;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I feel like a famous mercenary. How about something like Johan Elting with his dark outfit and intricate golden breastplate?";
	model.id	   =  "Johan_Elting_c_A3";
	model.FaceId	= 439;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "I feel like a famous mercenary. How about something like Johan Elting?";
	model.id	   =  "Johan_Elting_d";
	model.ani		 =  "climb";
	model.FaceId	= 412;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Johan";
	model.lastname = "Elting";
	model.playertype = PLAYER_TYPE_MILITARY;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 2;
	model.Flags.Personal = 9;
	model.ship = "Barque4_47";
	model.shipname = "Neptunis";
	model.date.hour = 11;
	model.date.min = 43;
	model.date.sec = 12;
	model.date.day = 8;
	model.date.month = 10;
	model.date.year = 1665;
	AddCharacterModel(model);

	// <-- For the assassin quest

	// For the Bartolomeu o Portugues quest -->
	model.description =  "Just the best Spanish swordsman in the archipelago.";
	model.id	   =  "Juan_Esteban";
	model.FaceId	= 366;
	model.nation	  =  SPAIN;
	model.price	   =  500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	model.name = "Juan";
	model.lastname = "Esteban";
	AddCharacterModel(model);
	// <-- For the Bartolomeu o Portugues quest

	model.description	=  "It's actually spelled, Conceição!";
	model.id		=  "Kieron";
	model.FaceId		=  10;
	model.nation		=  ENGLAND;
	model.price		=  1000;
	model.assigned		=  true;
	model.lastname = "Kieron";
	AssignModelType(isstart, model, "Captains", 1.0);
	AddCharacterModel(model);

	model.description =  "How about a simple pair of trousers and a loose fitting shirt like that white-haired fellow is wearing over there...";
	model.id	   =  "Killer";
	model.FaceId	= 18;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Sailors", 1.0); // left at 1.0 for pirates
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "Something downright swarthy, a shirt with long puffed sleeves, brown vest, and it's time to let the hair grow out some.";
	model.id	   =  "korsar";
	model.FaceId	= 19;
	model.nation	  =  PIRATE;
	model.price	   =  750;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "For the Caribe in us all, a shirt with long puffed sleeves, brown vest, and let the hair grow out some.";
	model.id	   =  "korsar1";
	model.FaceId	= 20;
	model.nation	  =  PIRATE;
	model.price	   =  850;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "An English woman's red coat and tricorner hat, perfect for hunting foxes... or worse. Sshh! did you hear un loup-garoup?";
	model.id	   =  "ladyinred";
	model.FaceId	= 205;
	model.nation	  =  ENGLAND;
	model.sex		 =  "woman";
	model.ani		 =  "woman_sit";
	model.height	  =  1.75;
	model.price	   =  1000;
	model.assigned	=  true;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuro());
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "This nice golden dress will so accentuate those lovely blonde curls so that no one would think of telling a blonde joke...";
	model.id	   =  "liz1";
	model.FaceId	= 160;
	model.nation	  =  PIRATE; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		=  "woman";
//	model.ani		=  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	model.name = "Elizabeth";
	model.lastname = "Swan";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	model.description =  "This red dress will ideally fit white laces and dark hair.";
	model.id	   =  "liz2";
	model.FaceId	= 333;  // TALISMAN changed was 160
	model.nation	  =  PIRATE; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		=  "woman";
//	model.ani		=  "woman";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringSouthEuro());
	AddCharacterModel(model);

	model.description	=  "An elaborate dress with lace trim, appropriate for a wealthy lady.";
	model.id		=  "liz3";
	model.FaceId		= 247;
	model.nation		=  SPAIN; // made buyable
	model.price		=  2000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "woman";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat		= false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringSouthEuro());
	AddCharacterModel(model);

	model.description =  "I feel like James Norrington today, I need a fine Lieutenant uniform.";
	model.id	   =  "Ltnorrington";
	model.FaceId	= 235;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  ENGLAND;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.storytitle = "A Fine Gentleman";
	model.storytext = "You intend to see to it that any man who sails under a pirate flag or wears a pirate brand gets what he deserves. But while you may be an ambitious young lieutenant in His Majesty's Navy, you do have your heart in the right place.";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.ship = "HMS_Interceptor";
	model.shipname = "Interceptor";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "This ornate engraved Spanish armor and suit will create quite a sensation in Isla Muelle!";
	model.id	   =  "Lucas"; // NK
	model.FaceId	= 21;
	model.nation	  =  SPAIN;
	model.price	   =  4500;
	model.assigned	=  true;
//	model.name = "Lucas";
//	model.lastname = "Da Saldanha";
	AddCharacterModel(model);

	model.description	= "A polished Spanish naval uniform, as worn by the son of an admiral.";
	model.id		= "Lucas2"; // GR: based on "9JdSpa", for use in later periods
	model.FaceId		= 569;
	model.nation		= SPAIN;
	model.price		= 5000;
	model.assigned		= true;
//	model.name		= "Lucas";
//	model.lastname		= "Da Saldanha";
	AddCharacterModel(model);

	model.description =  "This scarlet outfit, and the coiffure I'd recommend go with it, were made the height of fashion in the Mediterranean by that famous Maltese knight Sir Michael Jackson!";
	model.id	   =  "Maltese";
	model.FaceId	= 22;
	model.nation	  =  SPAIN;
	model.price	   =  6000;
	model.assigned	=  true;
//	model.name = "Jaoquin";
//	model.lastname = "De Masse";
	AssignModelType(isstart, model, "Maltese", 1.0);
	AddCharacterModel(model);

	model.description =  "Just a blue longsleeved shirt and black vest for that dark hair.";
	model.id	   =  "man1";
	model.FaceId	= 23;
	model.nation	  =  FRANCE;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description =  "How about something common, say a half-sleeved white shirt, black vest-coat, and let the hair grow longer.";
	model.id	   =  "man1_1";
	model.FaceId	= 24;
	model.nation	  =  HOLLAND;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Middle_Citizens", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "I'm thinking a common white shirt, vest, and let the hair down...";
	model.id	   =  "man1_2";
	model.FaceId	= 25;
	model.nation	  =  PORTUGAL;
	model.price	   =  100;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Middle_Citizens", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "White long-sleeved shirt, closed vest... Just the right thing to blend in well with the village idiots.";
	model.id	   =  "Man2";
	model.FaceId	= 26;
	model.nation	  =  HOLLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "Perhaps this nice Dutch ensemble of a stiff-collared white shirt, dark brown vest, and wide-brimmed hat will clash with a Mediterranean complexion, but you never know.";
	model.id	   =  "Man3";
	model.FaceId	= 27;
	model.nation	  =  HOLLAND;
	model.price	   =  750;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringNorthEuro());
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "How about a nice Dutch ensemble of a stiff-collared white shirt, light brown vest, and a Dutch wide-brimmed hat?";
	model.id	   =  "Man3_1";
	model.FaceId	= 28;
	model.nation	  =  HOLLAND;
	model.price	   =  850;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringNorthEuro());
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "This simple cotton ensemble consisting in the main of an open white shirt comes directly from Neanderthal's of London!";
	model.id	   =  "man4";
	model.FaceId	= 133;
	model.price	   =  30;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Just a simple tattered shirt to blend into the crowds with.  Unwanted attention may be... unwanted...";
	model.id	   =  "Man5";
	model.FaceId	= 134;
	model.price	   =  30;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "No pretensions, just a green open longsleeved shirt over blue pants, and a haircut and a mustache trim.";
	model.id	   =  "Man5_1";
	model.FaceId	= 135;
	model.nation	  =  PORTUGAL;
	model.price	   =  50;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "This simple dark vested suit cries out 'success' without crying it too loudly.";
	model.id	   =  "Man6";
	model.FaceId	= 29;
	model.nation	  =  PORTUGAL;
	model.price	   =  900;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "This simple dark vested suit cries out 'success' without crying it too loudly.";
	model.id	   =  "Man7";
	model.FaceId	= 431;
	model.nation	  =  ENGLAND;
	model.price	   =  900;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "This simple dark vested suit cries out 'success' without crying it too loudly.";
	model.id	   =  "Man8";
	model.FaceId	= 432;
	model.nation	  =  HOLLAND;
	model.price	   =  900;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "A humble man born in Vlissingen as son of a beer porter. Yet with the makings of greatness!";
	model.id	=  "DeRuyter";
	model.FaceId	= 109;
	model.minlevel	=  8;
	model.minrank	=  4;
	model.nation	=  HOLLAND;
	model.price	=  900;
	model.assigned	=  true;
	model.name	= "Michiel";
	model.lastname	= "de Ruyter";
	model.storytitle = "Bestevaêr";
	model.storytext = "Born as Michiel Adriaenszoon de Ruyter to a beer porter in Vlissingen, you are a humble man. However, the Anglo-Dutch Wars of the 17th century will give you plenty of opportunity for greatness!";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.ship	= "NL_NeptunusE";
	model.shipname	= "Neptunus";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 32;
	model.date.year	= 1652;
	AddCharacterModel(model);

	model.description =  "This simple dark vested suit cries out 'success' without crying it too loudly.";
	model.id	   =  "Man9";
	model.FaceId	= 433;
	model.nation	  =  SPAIN;
	model.price	   =  900;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "This simple dark vested suit cries out 'success' without crying it too loudly.";
	model.id	   =  "Man10";
	model.FaceId	= 430;
	model.nation	  =  FRANCE;
	model.price	   =  900;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0);
	AddCharacterModel(model);

	model.description =  "This nice dark suit is set off with a wonderful, frilly white shirt... A trip to an expensive barber will complete the effect!";
	model.id	   =  "Man6_1";
	model.FaceId	= 30;
	model.nation	  =  HOLLAND;
	model.price	   =  1100;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "Before the arrival of Henry Morgan, this old man was regarded as the pirate leader of Jamaica.";
	model.id	   =  "Mansveldt";
	model.FaceId	= 84;   // TALISMAN changed was 66
	model.nation	  =  PIRATE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Edwaert";
	model.lastname = "Mansveldt";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "A dark vest and a dark mask for the face for those with a dark mood and a dark heart.";
	model.id	   =  "mask";
	model.FaceId	= 136;
	model.price	   =  400;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Outlaws", 1.0);
	AddCharacterModel(model);

	model.description =  "This dark vest and mask holds such menace no one will notice the bald pate!";
	model.id	   =  "mask_2";
	model.FaceId	= 137;
	model.price	   =  450;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Outlaws", 1.0);
	AddCharacterModel(model);

	model.description =  "For those incognito moods, a dark vest and a highwaymans mask.";
	model.id	   =  "mask_3";
	model.FaceId	= 138;
	model.price	   =  350;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Outlaws", 1.0);
	AddCharacterModel(model);

	model.description =  "A shirt, a vest, a hat and a mask!  What skulking sticky-fingered thieving brigand could ask for more?";
	model.id	   =  "mask_4";
	model.FaceId	= 139;
	model.price	   =  500;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Outlaws", 1.0);
	AddCharacterModel(model);

	model.description =  "I feel like James Norrington today, I need a fine Midshipman uniform.";
	model.id	   =  "Mdnorrington";
	model.FaceId	= 186;
	model.minrank     =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "James";
	model.lastname = "Norrington";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.ship = "PO_Hoy";
	model.shipname = "Forester";
	model.Flags.Pirate = 23;
	model.Flags.Personal = 19;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description	=  "A very sharp looking model for an officer.";
	model.id		=  "Meigger";
	model.FaceId		=  99;
	model.nation		=  ENGLAND;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Meigger";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, ENGLAND);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "What business do you have with me?";
	model.id			=  "Modyford";
	model.FaceId		=  45;  // TALISMAN changed was 338
	model.nation		=  FRANCE;
	model.price			=  15000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "new_man";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name = "Thomas";
	model.lastname = "Modyford";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "";
	model.id	   =  "montbars";
	model.FaceId	= 487;
	model.nation	  = PIRATE;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Daniel";
	model.lastname = "Montbart";
	AddCharacterModel(model);

	model.description =  "Something from the Far East, and how about a haircut to go with it?";
	model.id	   =  "Mongol";
	model.FaceId	= 129;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "Have you ever heard of the Pirate Lord of Singapore?";
	model.id	   =  "SaoFeng";
	model.FaceId	= 104;
	model.nation = PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	model.name = "Sao";
	model.lastname = "Feng";
	model.storytitle =  "Crouching Tiger, Sailing Dragon";
	model.storytext  =  "Destined to become the Pirate Lord of Singapore and scourge of the South China Sea, you have just made your way to the Caribbean to make a name for yourself. Your uncommon type of ship may give you the leverage you need to become a successful pirate.";
	model.ship = "Empress";
	model.shipname = "Empress";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.Flags.Pirate = 32;
	model.Flags.Personal = 1;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description  =  "";
	model.id	  =  "SaoFeng_guard";
	model.FaceId	= 212;
	model.nation	  =  PIRATE;
	model.assigned	  =  true;
	model.sex	  =  "woman";
	model.ani	  =  "33_Blazie";
	model.height	  =  1.65;
	AddCharacterModel(model);

	model.description =  "This simple brown monk's garb would be accentuated by a monk's tonsure, if one can stand to go around that way.  But it would evoke trust everywhere!";
	model.id	   =  "monk";
	model.FaceId	= 143;
	model.nation	  =  BROKEN;
	model.price	   =  20;
	model.assigned	=  true;
	model.nogun = true;
	AssignModelType(isstart, model, "Monks", 1.0);
	AddCharacterModel(model);

	model.description =  "A brown monk's robe is one thing, but a tonsure is quite another!  A normal haircut and a hefty-healthy beard is much more to the point!";
	model.id	   =  "Monk2";
	model.FaceId	= 144;
	model.nation	  =  BROKEN;
	model.price	   =  20;
	model.assigned	=  true;
	model.nogun = true;
	AssignModelType(isstart, model, "Monks", 1.0);
	AddCharacterModel(model);

	model.description =  "For the small, severely malnourished monkey!";
	model.id	   =  "monkey";
	model.FaceId	= 257;
	model.ani   = "monkey";
	model.sex = "monkey";
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	model.noblade = true;
	model.nogun = true;
	AssignModelType(isstart, model, "Monkeys", 1.0);
	AddCharacterModel(model);

	// no assignment possible quest character -->
	model.description	=  "I feel like a famous pirate. Henry Morgan will do.";
	model.id			=  "Morgan";
	model.FaceId		=  340;
	model.nation		=  ENGLAND;
	model.price			=  15000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "new_man";
	model.status		=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name = "Henry";
	model.lastname = "Morgan";
	model.ship = "RN_WarGalleon";
	model.shipname = "Jamaica Merchant";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no assignment possible quest character -->
	model.description	=  "Your servant, sir. Do you want to fight a duel with me?";
	model.id			=  "MorrisWilliams";
	model.FaceId		=  332;
	model.nation		=  ENGLAND;
	model.price			=  1500;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "man";
	model.name = "Morris";
	model.lastname = "Williams";
	AddCharacterModel(model);
	// <-- no assignment possible quest character

	model.description =  "Camille Leone, a precious sight!";
	model.id	   =  "mowngirl5";
	model.FaceId	= 320;
	model.nation	  =  PORTUGAL;
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
//	model.name = "Camille";
//	model.lastname = "Leone";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Desiree Muerte, she seems awfully anxious to see if you enjoy your wine...";
	model.id	   =  "mowngirl7";
	model.FaceId	= 318;
	model.nation	  =  SPAIN;
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = true;
//	model.name = "Desiree";
//	model.lastname = "Muerte";
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "When there's true voodoo to do, and to do true voodoo you do the voodoo like a voodoo-doing fool, you do the voodoo in lieu of looking any other way!";
	model.id	   =  "mummy";
	model.FaceId	= 258;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.sex		= "skeleton"; // was Mummy
	model.ani		= "Man";
	AssignModelType(isstart, model, "Mummies", 1.0);
	AddCharacterModel(model);

	model.description =  "A lot of muscle, straight from Africa.";
	model.id	   =  "Napitan"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 194;
	model.nation	  =  SPAIN;
	model.price	   =  500;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description =  "For the person who wants to go native, the traditional garb of an Akellani.";
	model.id	   =  "Native";
	model.FaceId	= 259;
	model.assigned	=  true;
	model.sex		= "skeleton"; // was Mummy
	model.ani		= "Man";
	AssignModelType(isstart, model, "Natives", 1.0);
	AddCharacterModel(model);

	model.description =  "I feel like a Portuguese Marine with his musket. How about something like Augusto Queiroz ?";
	model.id	   =  "Navy_musket";
	model.FaceId	= 486;
	model.nation	  =  PORTUGAL;
	model.price	   =  470;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.name = "Augusto";
	model.lastname = "Queiroz";
	AddCharacterModel(model);

	model.description =  "Hmmm, d'ye have a British Royal Navy post captain's kit?";
	model.id	   =  "Navy_off";
	model.FaceId	= 6;
	model.minlevel     =  12;
	model.minrank =  6;
	model.nation	  =  ENGLAND;
	model.price	   =  4000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0); // later switch this to CAP?
	AddCharacterModel(model);

	model.description =  "Bring up a British Royal Navy Post captain's uniform, with some powder and a tie for the hair.";
	model.id	   =  "Navy_office4";
	model.FaceId	= 9;
	model.minlevel     =  12;
	model.minrank =  6;
	model.nation	  =  ENGLAND;
	model.price	   =  5000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AssignModelType(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0); // later switch this to CAP?
	AddCharacterModel(model);

	model.description =  "I feel like a Portuguese Marine. How about something like Lourenço Vaz ?";
	model.id	   =  "Navy_Portugal";
	model.FaceId	= 363;
	model.nation	  =  PORTUGAL;
	model.price	   =  470;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.name = "Lourenco";
	model.lastname = "Vaz";
	AddCharacterModel(model);

	model.description =  "I feel like a Portuguese Marine. How about something like Manuel Sousa ?";
	model.id	   =  "Navy_Portugal2";
	model.FaceId	= 362;
	model.nation	  =  PORTUGAL;
	model.price	   =  470;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.name = "Manuel";
	model.lastname = "Sousa";
	AddCharacterModel(model);

	model.description =  "This complete suit is designed for the gentleman who wants to look at home in the finest homes of Amsterdam.";
	model.id	   =  "Nobleman";
	model.FaceId	= 128;
	model.nation	  =  HOLLAND;
	model.price	   =  8000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);

	model.description =  "A noble (but rather fat) aristocrat in a blue outfit.";
	model.id	   =  "Nobleman2"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 260;
	model.nation	  =  HOLLAND;
	model.price	   =  8000;
	model.assigned	=  true;
	AssignModelTypeNatMask(isstart, model, "Rich_Citizens", 1.0, GetNationStringNorthEuroFr());
	AddCharacterModel(model);
	
	// Officer English -->
	model.description =  "Perhaps the uniform of an officer of the English Army is what is called for here!";
	model.id	   =  "Offic_eng_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  3000;
	model.assigned	=  true;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, ENGLAND);
	AddCharacterModel(model);

	model.description =  "Perhaps the uniform of an officer of the English Army is what is called for here!";
	model.id	   =  "Offic_eng_16";
	model.FaceId	= 344;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  3000;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, ENGLAND);
	AddCharacterModel(model);

	model.description =  "Perhaps the uniform of an officer of the English Army is what is called for here!";
	model.id	   =  "Offic_eng_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  3000;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, ENGLAND);
	AddCharacterModel(model);

	model.description =  "The uniform of British officer, straight from Caribbean islands.";
	model.id	   =  "Offic_eng_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  3000;
	model.assigned	=  true;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, ENGLAND);
	AddCharacterModel(model);
	// <-- Officer English

	model.description =  "This uniform suggests that it's wearer might be an officer of the King's Musketeers!  Surely a rapier is the appropriate blade to complete the effect!";
	model.id	   =  "Offic_fra_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, FRANCE);
	AddCharacterModel(model);

	model.description =  "This uniform suggests that it's wearer might be an officer of the King's Musketeers!  Surely a rapier is the appropriate blade to complete the effect!";
	model.id	   =  "Offic_fra_16";
	model.FaceId	= 343;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, FRANCE);
	AddCharacterModel(model);

	model.description =  "This uniform suggests that it's wearer might be an officer of the King's Musketeers!  Surely a rapier is the appropriate blade to complete the effect!";
	model.id	   =  "Offic_fra_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, FRANCE);
	AddCharacterModel(model);

	model.description =  "Blue uniform, together with red trouses and vest will give a bright signal that I'm an officer in service of France!";
	model.id	   =  "Offic_fra_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, FRANCE);
	AddCharacterModel(model);

	model.description =  "Blue uniform, together with red trouses and vest will give a bright signal that I'm an officer in service of France!";
	model.id	   =  "Offic_fra_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, FRANCE);
	AddCharacterModel(model);
	// <-- Officer French

	// Officer Dutch -->
	model.description =  "A soldier of Holland. Loyal and true.";
	model.id	   =  "Offic_hol_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, HOLLAND);
	AddCharacterModel(model);

	model.description =  "One of the more creative uniforms of any military, here is an armored breastplate, topped of with a most interesting stove-pipe hat!";
	model.id	   =  "Offic_hol_16";
	model.FaceId	= 346;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, HOLLAND);
	AddCharacterModel(model);

	model.description =  "A soldier of Holland. Loyal and true.";
	model.id	   =  "Offic_Hol_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, HOLLAND);
	AddCharacterModel(model);

	model.description =  "A soldier of Holland. Loyal and true.";
	model.id	   =  "Offic_hol_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, HOLLAND);
	AddCharacterModel(model);
	// <-- Officer Dutch

	model.description =  "This uniform suggests that it's wearer might be an officer of your Personal Musketeers! Surely a rapier is the appropriate blade to complete the effect!";
	model.id	   =  "Offic_per";
	model.FaceId	= 351;  // TALISMAN changed was 351
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  4000;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PERSONAL_NATION);
	AddCharacterModel(model);

	// Officer Portuguese -->
	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_15";
	model.FaceId	= 345;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);

	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);

	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);

	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);

	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);

	model.description =  "This outfit consists of a white longsleeved shirt covered with a nice engraved armored breastplate, with a Portuguese helmet to complete the equippage.";
	model.id	   =  "Offic_por_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  2100;
	model.assigned	=  true;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PORTUGAL);
	AddCharacterModel(model);
	// <-- Officer Portuguese

	// Officer Spanish -->
	model.description =  "An engraved steel breasplate dominates this outfit that includes a white shirt topped off with a Spanish helmet!";
	model.id	   =  "Offic_spa_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  2200;
	model.assigned	=  true;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SPAIN);
	AddCharacterModel(model);

	model.description =  "An engraved steel breasplate dominates this outfit that includes a white shirt topped off with a Spanish helmet!";
	model.id	   =  "Offic_spa_16";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  2200;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SPAIN);
	AddCharacterModel(model);

	model.description =  "An engraved steel breasplate dominates this outfit that includes a white shirt topped off with a Spanish helmet!";
	model.id	   =  "Offic_spa_17";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  2200;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SPAIN);
	AddCharacterModel(model);

	model.description =  "An Officer in his Majestey's Lancer Regiments.";
	model.id	   =  "Offic_spa_18";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  2200;
	model.assigned	=  true;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SPAIN);
	AddCharacterModel(model);

	model.description =  "A loyal Spanish Officer";
	model.id	   =  "Offic_spa_19";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  2200;
	model.assigned	=  true;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SPAIN);
	AddCharacterModel(model);
	// <-- Officer Spanish

	// Assassin Main Quest -->
	model.description =  "";
	model.id	   =  "Offic_fra2_16";
	model.FaceId	= 343;
	model.nation	  =  BROKEN;
	model.price	   =  4000;
	AddCharacterModel(model);

	model.description =  "An engraved steel breastplate dominates this outfit that includes a combination of a yellow and red Spanish officers uniform!";
	model.id	   =  "Offic_spa2_16";
	model.FaceId	= 414;
	model.nation	  =  BROKEN;
	model.price	   =  2200;
	model.assigned	=  true;
	AddCharacterModel(model);
	// Assassin Main Quest <--

	model.description =  "This white half-sleeved shirt, green vest and grey beard suggest a captain who's seen many a harbor.";
	model.id	   =  "Old_man1";
	model.FaceId	= 32;
	model.nation	  =  SPAIN;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description =  "A white half-sleeved shirt and brown vest suit the brown hair and beard pretty well!";
	model.id	   =  "Old_man2";
	model.FaceId	= 33;
	model.nation	  =  PORTUGAL;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description =  "This white half-sleeved shirt, green vest and grey beard suggest a captain who's seen many a harbor.";
	model.id	   =  "Old_man3";
	model.FaceId	= 434;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description =  "A white half-sleeved shirt and brown vest suit the brown hair and beard pretty well!";
	model.id	   =  "Old_man4";
	model.FaceId	= 435;
	model.nation	  =  HOLLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	model.description =  "A slightly older man, looking suspiciously like a cannoneer.";
	model.id	   =  "Old_mat1";
	model.FaceId	= 266;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_CARPENTER, 1.0);
	AddCharacterModel(model);

	model.description =  "A white longsleeved shirt, a vested dress, and a head covering are just the thing for a respectable woman who has seen a lot of life.";
	model.id	   =  "OldWoman";
	model.FaceId	= 161;
	model.assigned	=  true;
	model.nation	  =  PIRATE; // made buyable
	model.price	   =  1000;
	model.height	  =  1.75;
	model.sex =  "woman";
//	model.ani =  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat = false;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AddCharacterModel(model);

	model.description =  "A white longsleeved shirt, a vested dress, and a head covering are just the thing for a respectable woman who has seen a lot of life.";
	model.id	   =  "OldWoman1";
	model.FaceId	= 161;
	model.assigned	=  true;
	model.nation	  =  ENGLAND; // made buyable
	model.price	   =  1000;
	model.height	  =  1.75;
	model.sex =  "woman";
//	model.ani =  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat = false;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AddCharacterModel(model);

	model.description =  "A white longsleeved shirt, a vested dress, and a head covering are just the thing for a respectable woman who has seen a lot of life.";
	model.id	   =  "OldWoman2";
	model.FaceId	= 161;
	model.assigned	=  true;
	model.nation	  =  SPAIN; // made buyable
	model.price	   =  1000;
	model.height	  =  1.75;
	model.sex =  "woman";
//	model.ani =  "towngirl";
	model.ani		=  "woman_sit";
	model.iscombat = false;
	AssignModelType(isstart, model, "Middle_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AddCharacterModel(model);

	model.description =  "I hate anyone weilding worldly power. But I love the church. And fugitives.";
	model.id	   =  "PadreGerardo";
	model.FaceId	= 446;
	model.nation	  =  BROKEN;
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Padre";
	model.lastname = "Gerardo";
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "A blue shirt, dark hair, and most of all a black vest say that pirating is in the offing.";
	model.id	   =  "Pirat1";
	model.FaceId	= 93;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "A set of black boots, black trousers, long black coat, and a black hat big enough to keep my hair from getting bleached any more.  And no more blonde jokes...";
	model.id	   =  "pirat10";
	model.FaceId	= 65;
	model.nation	  =  PIRATE;
	model.price	   =  1500;
	model.assigned	=  true;
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "Don't cross me, mate!  Black boots, black trousers, long black coat, big black hat, black as me hair!  Black as me heart!";
	model.id	   =  "Pirat11";
	model.FaceId	= 53;
	model.nation	  =  PIRATE;
	model.price	   =  1600;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	// Armor Mod -->
	/*model.description =  "Don't cross me, mate!  Black boots, black trousers, long black coat with steel cuirass, big black hat, black as me hair!  Black as me heart!";
	model.id	   =  "Pirat11_A1";
	model.FaceId	= "Pirat11";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Don't cross me, mate!  Black boots, black trousers, long black coat with engraved breastplate, big black hat, black as me hair!  Black as me heart!";
	model.id	   =  "Pirat11_A2";
	model.FaceId	= "Pirat11";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Don't cross me, mate!  Black boots, black trousers, long black coat with gilded breastplate, big black hat, black as me hair!  Black as me heart!";
	model.id	   =  "Pirat11_A3";
	model.FaceId	= "Pirat11";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "They'll be thinking 'Oh shiver me timbers, it's a pirate!' when they see this dark vest and tricorner hat!";
	model.id	   =  "Pirat12";
	model.FaceId	= 123;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, ENGLAND);
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "He doesn't nescessarily look evil, but this is not a person you would want to cross.";
	model.id	   =  "Pirat13"; // From the "Sea Legend is Back" (SLiB) add-on
	model.FaceId	= 261;
	model.nation	  =  PIRATE;
	model.price	   =  500;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "He doesn't nescessarily look evil, but this is not a person you would want to cross.";
	model.id	   =  "Pirat15";
	model.FaceId	= 440;
	model.nation	  =  PIRATE; // Estharos reassign April 12th, 2009
	model.price	   =  500;
	model.assigned	=  true;
	model.name = "Nicholas";
	model.lastname = "Butcher";
	AddCharacterModel(model);

	// Armor Mod -->
	/*model.description =  "He doesn't nescessarily look evil, but this is not a person you would want to cross.";
	model.id	   =  "Pirat15_A1";
	model.FaceId	= 440;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "He doesn't nescessarily look evil, but this is not a person you would want to cross.";
	model.id	   =  "Pirat15_A2";
	model.FaceId	= 440;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "He doesn't nescessarily look evil, but this is not a person you would want to cross.";
	model.id	   =  "Pirat15_A3";
	model.FaceId	= 440;
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "A dirty shirt, a dark vest and a bandanna set this off for a perfectly piratical picture.";
	model.id	   =  "Pirat2";
	model.FaceId	= 121;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CARPENTER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "A white shirt, dark coat and dark tricorne hat.  What more could a pirate want?  Hooks, parrots, and peg-leg not included.";
	model.id	   =  "Pirat3";
	model.FaceId	= 122;
	model.nation	  =  PIRATE;
	model.price	   =  300;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Mates", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_FIRSTMATE, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Break out something that suits a Portuguese swordsman, an simple outfit with a bandanna on top!";
	model.id	   =  "Pirat4";
	model.FaceId	= 54;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CARPENTER, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CANNONEER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "They'll be thinking 'Oh shiver me timbers, it's a pirate!' when they see this dark vest and tricorner hat!";
	model.id	   =  "Pirat5";
	model.FaceId	= 123;
	model.nation	  =  PIRATE;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Let's try it without a shirt under the vest, and a bandanna, what do you say?";
	model.id	   =  "Pirat6";
	model.FaceId	= 124;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CANNONEER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Let's try it without a shirt under the vest, and a bandanna, but without the beard, what do you say?";
	model.id	   =  "Pirat7";
	model.FaceId	= 125;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CARPENTER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Let's try it without a shirt under the vest, and a bandanna, but without hair, what do you say?";
	model.id	   =  "Pirat8";
	model.FaceId	= 126;
	model.nation	  =  PIRATE;
	model.price	   =  150;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Sailors", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CANNONEER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "Hmmm, thinkin' pirate here, so a white half-sleeved shirt, dark vest, dark hair, and an eyepatch!";
	model.id	   =  "Pirat9";
	model.FaceId	= 127;
	model.nation	  =  PIRATE;
	model.price	   =  200;
	model.assigned	=  true;
	AssignModelTypeNation(isstart, model, "Mates", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0, PIRATE);
	AssignModelTypeNation(isstart, model, OFFIC_TYPE_CANNONEER, 1.0, PIRATE);
	AddCharacterModel(model);

	model.description =  "A sailor in green. Why? He shouldn't draw attention to himself in dense jungles!";
	model.id	   =  "Pirtt7";
	model.FaceId	= 267;
	model.nation	  =  HOLLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description =  "What this is is a cassock and a surplice, worn by priests and bishops of the Catholic Church, the Anglican Church... and I guess by anyone who jolly well just wants to wear one!";
	model.id	   =  "Priest";
	model.FaceId	= 145;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	model.nogun = true;
	AssignModelType(isstart, model, "Priests", 1.0);
	AssignModelType(isstart, model, "Maltese", 0.15);
	AddCharacterModel(model);

	model.description =  "This is the very outfit worn by that nice priest, bishop, well, whatever the head guy is at the church of Isla Muelle!  And if he thinks it's HIS his, just remember where it came from.";
	model.id	   =  "Priest_spa";
	model.FaceId	= 146;
	model.nation	  =  BROKEN;
	model.price	   =  1000;
	model.assigned	=  true;
	model.nogun = true;
	AssignModelType(isstart, model, "Priests", 1.0);
	AssignModelType(isstart, model, "Maltese", 0.15);
	AddCharacterModel(model);

	model.description	=  "Beggar. Must be in a jail or in some cargo hold like a slave";
	model.id			=  "prison_3";
	model.FaceId		=  126; // TALISMAN changed was 347
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "man";
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description	=  "Beggar. Must be in a jail or in some cargo hold like a slave";
	model.id			=  "prison_4";
	model.FaceId		=  148; // TALISMAN changed was 348
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "man";
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description	=  "Beggar. Must be in a jail or in some cargo hold like a slave";
	model.id			=  "prison_5";
	model.FaceId		=  147; // TALISMAN changed was 349
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.85;
	model.sex			=  "man";
	model.ani			=  "man";
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Cheap clothes won't protect you from the sun darkening your skin... severely!";
	model.id	   =  "rabBlack";
	model.FaceId	= 147;
	model.price	   =  2;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "One might carefully consider wearing more fashionable clothes than these, since there are some who are dressed this way that can't come and go as freely as might otherwise be...";
	model.id	   =  "rabBlack_1";
	model.FaceId	= 148;
	model.price	   =  2;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "Cheap clothes won't protect you from the sun darkening your skin... severely!";
	model.id	   =  "rabBlack_2";
	model.FaceId	= 436;
	model.price	   =  2;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "One might carefully consider wearing more fashionable clothes than these, since there are some who are dressed this way that can't come and go as freely as might otherwise be...";
	model.id	   =  "rabBlack_3";
	model.FaceId	= 437;
	model.price	   =  2;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	// For future quests -->
	model.description =  "I feel like an unlucky French Soldier. How about something like Rabel Chardon ?";
	model.id	   =  "Rabel_Chardon";
	model.FaceId	= 370;
	model.nation	  =  FRANCE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Rabel";
	model.lastname = "Chardon";
	AddCharacterModel(model);
	// For future quests <--

	model.description =  "It might be that these clothes cry out 'Poor White Trash', but you can't beat the price!  Perhaps for a special occasion they might even be preferred!  For a mugging, for instance.";
	model.id	   =  "rabWhite";
	model.FaceId	= 149;
	model.price	   =  2;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	model.description =  "One DOES save money buying just an old hat, but you can't get into the better taverns...";
	model.id	   =  "rabwhite1";
	model.FaceId	= 150;
	model.assigned	=  true;
	model.isprisoner	=  true;//Beggar. Must be in a jail or in some cargo hold like a slave
	AssignModelType(isstart, model, "Poor_Citizens", 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "A sallow-looking pirate with a bald head and a belligerent homunculus.";
	model.id	   =  "Pintel";
	model.FaceId	= 214;
	model.nation	  =  ENGLAND;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Pintel";
	model.lastname = "";
	AddCharacterModel(model);

	model.description =  "It's a mythical creature... I can call it what I like.";
	model.id	   =  "Ragetti";
	model.FaceId	= 85; // TALISMAN changed was 13
	model.nation	  =  ENGLAND;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Ragetti";
	model.lastname = "";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "Trousers, shirt, cut a little slim.  Oh, and an apron, and don't you bloody laugh!";
	model.id	   =  "Researcher";
	model.FaceId	= 34;
	model.minlevel	 =  12;
	model.nation	  =  AMERICA; // Estharos reassign March 18th, 2009
	model.price	   =  350;
	model.assigned	=  true;
	model.name = "Robert";
	model.lastname = "Fulton";
	model.storytitle = "Age of Steam";
	model.storytext = "Born on a farm in Little Britain, Pennsylvania, on November 14, 1765, you have spent the past ten years developing a new type of ship. Your latest creation is battle-ready and equipped both with regular sails, but also a new design engine. It is time to take her out for sea trials.";
	model.playertype = PLAYER_TYPE_ENGINEER;
	model.ship = "US_SteamFrigate";
	model.shipname = "Demologos";
	model.Flags.Pirate = 12;
	model.Flags.Personal = 33;
	model.date.day = 29;
	model.date.month = 10;
	model.date.year = 1814;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "I feel like a famous pirate. Roche Brasiliano will do.";
	model.id	   =  "Roche";
	model.FaceId	= 365;
	model.nation	  =  PIRATE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Roche";
	model.lastname = "Brasiliano";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "This sailor has a grey jacket with golden trim and leather shoulder patches. And who needs a beard when you have sideburns like that?";
	model.id	   =  "Almeida";
	model.FaceId	= 582;
	model.nation	  =  PORTUGAL;
	model.price	   =  1200;
	model.assigned	=  true;
	model.ani	=  "Rousselet";
	model.status	=  "C_III"; // added as an identifier, for assigning another animation to the new models
	model.name = "José";
	model.middlename = "Joaquím";
	model.lastname = "Almeida";
	model.storytitle = "Rustic Sea Wolf";
	model.storytext = "I left my Portuguese home in the Azores for America in 1796 at the age of 19. I worked as a merchant for a while but now with the outbreak of war I have turned privateer (includes sidequest specific to this character)";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.ship = "US_Schooner47";
	model.shipname = "Caroline";
	model.Flags.Pirate = 24;
	model.Flags.Personal = 35;
	model.date.month = 6;
	model.date.year = 1812;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, GetNationStringSouthEuro());
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "A stripped short sleeve shirt, light brown vest, and bandanna to accent the dark hair and beart. An eyepatch is probably called for, but I don't seem to see one...";
	model.id	   =  "Sailor";
	model.FaceId	= 3;
	model.nation	  =  SPAIN;
	model.price	   =  100;
	model.assigned	=  true;
	model.name = "José";
	model.lastname = "Gaspar";
	model.storytitle = "The Legend of Gasparilla";
	model.storytext = "Eventually becoming the last of the Buccaneers, rumours surrounding your life have been scarce. Most say you were born in Spain in 1756 and served in the Spanish Navy. Whatever may be the truth, you worked yourself up from a lowly position until you gained command of a ship of your own. It is time to make a name for yourself in the waters south of Florida!";
	model.playertype = PLAYER_TYPE_SAILOR;
	model.Flags.Pirate = 18;
	model.Flags.Personal = 3;
	model.ship = "SloopBermuda";
	model.shipname = "Gasparilla";
	model.date.year = 1783;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Shirt, vest, bandanna... typical sailor.";
	model.id	   =  "Sailor1";
	model.FaceId	= 35;
	model.nation	  =  PORTUGAL;
	model.price	   =  100;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Open long white shirt, with a sash-belt.  Just screams 'sailor!', doesn't it?";
	model.id	   =  "sailor10";
	model.FaceId	= 39;
	model.nation	  =  PORTUGAL;
	model.price	   =  120;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Oh, a simple pair of trowsers, a simple vest, and a bandanna.  A shirt? No, not in THIS heat!";
	model.id	   =  "Sailor13";
	model.FaceId	= 2;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	model.description =  "Open long white shirt, with a sash-belt.  Just screams 'sailor!', doesn't it?";
	model.id	   =  "sailor15";
	model.FaceId	= 39;
	model.price	   =  120;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Open long white shirt, with a sash-belt.  Just screams 'sailor!', doesn't it?";
	model.id	   =  "Sailor16";
	model.FaceId	= 40;
	model.price	   =  100;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Oh, a simple pair of trowsers, a simple vest, and a bandanna.  A shirt? No, not in THIS heat!";
	model.id	   =  "Sailor19";
	model.FaceId	= 2;
	model.nation	  =  ENGLAND;
	model.price	   =  200;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelTypeNatMask(isstart, model, "Sailors", 1.0, BitNot(GetNationStringSouthEuro()));
	AssignModelType(isstart, model, OFFIC_TYPE_CANNONEER, 1.0);
	AddCharacterModel(model);

	model.description =  "Now, a sailor's kit!  White shirt, brown vest, head bandanna, and a date with a barber!";
	model.id	   =  "Sailor2";
	model.FaceId	= 36;
	model.price	   =  100;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Lookin fer yet another variation on the 'sailor' theme?";
	model.id	   =  "Sailor3";
	model.FaceId	= 37;
	model.price	   =  150;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AddCharacterModel(model);

	model.description =  "Nah, bring out a different outfit, with a bandanna to match.";
	model.id	   =  "Sailor4";
	model.FaceId	= 38;
	model.price	   =  80;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AddCharacterModel(model);

	model.description =  "Open long white shirt, with a sash-belt.  Just screams 'sailor!', doesn't it?";
	model.id	   =  "sailor5";
	model.FaceId	= 39;
	model.price	   =  120;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "White shirt, vest, and let's stick a bandanna over some nice long golden locks!";
	model.id	   =  "Sailor6";
	model.FaceId	= 40;
	model.price	   =  100;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_ABORDAGE, 1.0);
	AddCharacterModel(model);

	model.description =  "Retro French soldier look, but with a renegade flair, and a red bandana to top it off.";
	model.id	   =  "sailor7";
	model.FaceId	= 157;
	model.nation	  =  FRANCE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_BOATSWAIN, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "This old seadog hails from the Northern Waters.";
	model.id          =  "Salt";
	model.FaceId      =  77;
	model.nation      =  PIRATE;
	model.price       =  1500;
	model.assigned    =  true;
	model.name = "Old";
	model.lastname = "Salt";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "A very wealthy-looking guy you could easily imagine to be a Vice-Admiral of the Spanish Navy.";
	model.id	   =  "Salvadore";
	model.FaceId	= 415;
	model.minlevel	 =  18;
	model.minrank	 =  9;
	model.nation	  =  SPAIN;
	model.price	   =  10000;
	model.assigned	=  true;
	model.name = "Salvadore";
	model.lastname = "Benavides";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "Now here, mate, we have a nice white collared shirt over a light blue long formal coat with cuffed sleeves.  Clean shaven, brown short hair, you look competent and successful!";
	model.id	   =  "searcher";
	model.FaceId	= 97;
	model.nation	  =  FRANCE;
	model.price	   =  600;
	model.assigned	=  true;
	AssignModelType(isstart, model, OFFIC_TYPE_DOCTOR, 1.0);
	AddCharacterModel(model);

	// assign as captain only -->
	model.description =  "An officer's uniform in blue and gold, just back from fighting rebels.";
	model.id	   =  "searcher_navy";
	model.FaceId	= 208;
	model.nation	  =  ENGLAND;
	model.price	   =  500;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_REBEL;
	AssignModelType(isstart, model, "Captains", 1.0);
	AddCharacterModel(model);
	// <-- assign as captain only

	// For future quests -->
	model.description =  "I feel like an unlucky Portuguese Soldier. How about something like Serafino Masarenhas ?";
	model.id	   =  "Serafino_Masarenhas";
	model.FaceId	= 372;
	model.nation	  = PORTUGAL;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Serafino";
	model.lastname = "Masarenhas";
	AddCharacterModel(model);
	// For future quests <--

	// assign as captain only -->
	model.description =  "A uniform for a merchant ship captain, with a red sash tied to the side.  It doesn't have to be new, but bring out the old-fashioned peaked hat.";
	model.id	   =  "shkiper";
	model.FaceId	= 66;
	model.nation	  =  PORTUGAL;
	model.price	   =  450;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MERCHANT;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);
	// <-- assign as captain only

	model.description =  "Your first basic collection of animated old bones.";
	model.id	   =  "Skel1";
	model.FaceId	= 262;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Skeletons", 1.0);
	AddCharacterModel(model);

	model.description =  "Your second basic collection of animated old bones.";
	model.id	   =  "Skel2";
	model.FaceId	= 263;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Skeletons", 1.0);
	AddCharacterModel(model);

	model.description =  "Your third basic collection of animated old bones.";
	model.id	   =  "Skel3";
	model.FaceId	= 264;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Skeletons", 1.0);
	AddCharacterModel(model);

	model.description =  "Your fourth basic collection of animated old bones.";
	model.id	   =  "Skel4";
	model.FaceId	= 265;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Skeletons", 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "I keep a couple of extra guns just for company...";
	model.id		=  "Skull";
	model.FaceId		=  74;
	model.nation		=  PIRATE;
	model.price		=  1000;
	model.assigned		=  true;
	model.name = "Skull";
	model.lastname = "";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// Soldier English -->
	model.description =  "Your basic English Army or Marine uniform under a strong jaw and a mustache.";
	model.id	   =  "Soldier_Eng_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English Army or Marine uniform, and have the barber trim the goatee!";
	model.id	   =  "Soldier_Eng2_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English land forces uniform with a blonde mustache and hair.";
	model.id	   =  "Soldier_Eng3_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Here is a uniform of the English Army or Marines, and the barber is waiting down the street.";
	model.id	   =  "Soldier_Eng4_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical English soldier's kit.";
	model.id	   =  "Soldier_Eng5_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English uniform of the Army or the Marines.  It's similarity to other such packages is explained by the term 'uniform'...";
	model.id	   =  "Soldier_Eng6_15";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Your basic English Army or Marine uniform under a strong jaw and a mustache.";
	model.id	   =  "Soldier_Eng_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English Army or Marine uniform, and have the barber trim the goatee!";
	model.id	   =  "Soldier_Eng2_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English land forces uniform with a blonde mustache and hair.";
	model.id	   =  "Soldier_Eng3_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Here is a uniform of the English Army or Marines, and the barber is waiting down the street.";
	model.id	   =  "Soldier_Eng4_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical English soldier's kit.";
	model.id	   =  "Soldier_Eng5_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English uniform of the Army or the Marines.  It's similarity to other such packages is explained by the term 'uniform'...";
	model.id	   =  "Soldier_Eng6_16";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Your basic English Army or Marine uniform under a strong jaw and a mustache.";
	model.id	   =  "Soldier_Eng_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English Army or Marine uniform, and have the barber trim the goatee!";
	model.id	   =  "Soldier_Eng2_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English land forces uniform with a blonde mustache and hair.";
	model.id	   =  "Soldier_Eng3_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Here is a uniform of the English Army or Marines, and the barber is waiting down the street.";
	model.id	   =  "Soldier_Eng4_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical English soldier's kit.";
	model.id	   =  "Soldier_Eng5_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "An English uniform of the Army or the Marines.  It's similarity to other such packages is explained by the term 'uniform'...";
	model.id	   =  "Soldier_Eng6_17";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.playertype  = PLAYER_TYPE_MARINE;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform.";
	model.id	   =  "Soldier_Eng_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform 2.";
	model.id	   =  "Soldier_Eng2_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform 3.";
	model.id	   =  "Soldier_Eng3_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform 4.";
	model.id	   =  "Soldier_Eng4_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform 5.";
	model.id	   =  "Soldier_Eng5_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical english red-coat uniform 6.";
	model.id	   =  "Soldier_Eng6_18";
	model.FaceId	= 99;
	model.minrank	 =  1;
	model.nation	  =  ENGLAND;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier English

	// Soldier French -->
	model.description =  "The kit of a soldier of France, complimented by long dark hair and a goatee.";
	model.id	   =  "Soldier_Fra_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France, without the common goatee.";
	model.id	   =  "Soldier_Fra2_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France who...  looks like... many other soldiers of France.";
	model.id	   =  "Soldier_Fra3_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This fresh-faced occupant of the uniform of the Army of France could well resemble one M'seur D'Artagnan of another place and time!";
	model.id	   =  "Soldier_Fra4_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Uniform, French Army, one each.";
	model.id	   =  "Soldier_Fra5_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This uniform of a soldier of France seems... shorter than others like it.";
	model.id	   =  "Soldier_Fra6_15";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The kit of a soldier of France, complimented by long dark hair and a goatee.";
	model.id	   =  "Soldier_Fra_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France, without the common goatee.";
	model.id	   =  "Soldier_Fra2_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France who...  looks like... many other soldiers of France.";
	model.id	   =  "Soldier_Fra3_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This fresh-faced occupant of the uniform of the Army of France could well resemble one M'seur D'Artagnan of another place and time!";
	model.id	   =  "Soldier_Fra4_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Uniform, French Army, one each.";
	model.id	   =  "Soldier_Fra5_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This uniform of a soldier of France seems... shorter than others like it.";
	model.id	   =  "Soldier_Fra6_16";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 1.";
	model.id	   =  "Soldier_Fra_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 2.";
	model.id	   =  "Soldier_Fra2_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 3.";
	model.id	   =  "Soldier_Fra3_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 4.";
	model.id	   =  "Soldier_Fra4_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 5.";
	model.id	   =  "Soldier_Fra5_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 6.";
	model.id	   =  "Soldier_Fra6_17";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 1.";
	model.id	   =  "Soldier_Fra_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 2.";
	model.id	   =  "Soldier_Fra2_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 3.";
	model.id	   =  "Soldier_Fra3_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 4.";
	model.id	   =  "Soldier_Fra4_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 5.";
	model.id	   =  "Soldier_Fra5_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical french uniform 6.";
	model.id	   =  "Soldier_Fra6_18";
	model.FaceId	= 101;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The kit of a soldier of France, complimented by long dark hair and a goatee.";
	model.id	   =  "Soldier_Fra_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France, without the common goatee.";
	model.id	   =  "Soldier_Fra2_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a soldier of France who...  looks like... many other soldiers of France.";
	model.id	   =  "Soldier_Fra3_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This fresh-faced occupant of the uniform of the Army of France could well resemble one M'seur D'Artagnan of another place and time!";
	model.id	   =  "Soldier_Fra4_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Uniform, French Army, one each.";
	model.id	   =  "Soldier_Fra5_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.period = "" + PERIOD_NAPOLEONIC;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This uniform of a soldier of France seems... shorter than others like it.";
	model.id	   =  "Soldier_Fra6_19";
	model.FaceId	= 111;
	model.minrank	 =  1;
	model.nation	  =  FRANCE;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier French

	// Soldier Dutch -->
	model.description =  "A typical Dutch uniform 1.";
	model.id	   =  "Soldier_Hol_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 2.";
	model.id	   =  "Soldier_Hol2_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 3.";
	model.id	   =  "Soldier_Hol3_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 4.";
	model.id	   =  "Soldier_Hol4_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 5.";
	model.id	   =  "Soldier_Hol5_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 6.";
	model.id	   =  "Soldier_Hol6_15";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 1.";
	model.id	   =  "Soldier_Hol_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 2.";
	model.id	   =  "Soldier_Hol2_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 3.";
	model.id	   =  "Soldier_Hol3_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 4.";
	model.id	   =  "Soldier_Hol4_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 5.";
	model.id	   =  "Soldier_Hol5_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 6.";
	model.id	   =  "Soldier_Hol6_17";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 1.";
	model.id	   =  "Soldier_Hol_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 2.";
	model.id	   =  "Soldier_Hol2_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 3.";
	model.id	   =  "Soldier_Hol3_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 4.";
	model.id	   =  "Soldier_Hol4_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 5.";
	model.id	   =  "Soldier_Hol5_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 6.";
	model.id	   =  "Soldier_Hol6_16";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 1.";
	model.id	   =  "Soldier_Hol_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 2.";
	model.id	   =  "Soldier_Hol2_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 3.";
	model.id	   =  "Soldier_Hol3_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 4.";
	model.id	   =  "Soldier_Hol4_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 5.";
	model.id	   =  "Soldier_Hol5_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical Dutch uniform 6.";
	model.id	   =  "Soldier_Hol6_18";
	model.FaceId	= 105;
	model.minrank	 =  1;
	model.nation	  =  HOLLAND;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier Dutch 

	// Soldier Personal
	model.description =  "The kit of a Personal soldier, complimented by long dark hair and a goatee.";
	model.id	   =  "Soldier_Per";
	model.FaceId	= 369;  // TALISMAN changed was  352
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a Personal soldier, without the common goatee.";
	model.id	   =  "Soldier_Per2";
	model.FaceId	= 369; // TALISMAN changed was 353
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a Personal soldier who...  looks like... many other Personal soldiers.";
	model.id	   =  "Soldier_Per3";
	model.FaceId	= 369;  // TALISMAN changed was 354
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This fresh-faced occupant of the uniform of your Personal Army could well resemble one M'seur D'Artagnan of another place and time!";
	model.id	   =  "Soldier_Per4";
	model.FaceId	= 369; // TALISMAN changed was 355
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Uniform, Personal Army, one each.";
	model.id	   =  "Soldier_Per5";
	model.FaceId	= 369; // TALISMAN changed was 356
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This uniform of a Personal soldier seems... shorter than others like it.";
	model.id	   =  "Soldier_Per6";
	model.FaceId	= 369;  // TALISMAN changed was 357
	model.minrank	 =  1;
	model.nation	  =  PERSONAL_NATION;
	model.price	   =  1250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier Personal

	// Soldier Portuguese
	model.description =  "The breastplane and helm of a mustachioed soldier of the land that will be Portugal.";
	model.id	   =  "Soldier_Por_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With soldiers such as wear this armor Portugal will RULE THE SEAS!";
	model.id	   =  "Soldier_Por4_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "1 suit of armor last worn by a Portuguese soldier.  Slightly dented.";
	model.id	   =  "Soldier_Por5_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A clean-shaven fresh-faced bright-eyed bushy-tailed soldier for the... whatever is called Portugal!";
	model.id	   =  "Soldier_Por6_15";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The breastplane and helm of a mustachioed soldier of the land that will be Portugal.";
	model.id	   =  "Soldier_Por_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With soldiers such as wear this armor Portugal will RULE THE SEAS!";
	model.id	   =  "Soldier_Por4_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "1 suit of armor last worn by a Portuguese soldier.  Slightly dented.";
	model.id	   =  "Soldier_Por5_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A clean-shaven fresh-faced bright-eyed bushy-tailed soldier for the... whatever is called Portugal!";
	model.id	   =  "Soldier_Por6_16";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por1172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With soldiers such as wear this armor Portugal will RULE THE SEAS!";
	model.id	   =  "Soldier_Por4172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por5172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por6172";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por4_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por5_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por6_17";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por4_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por5_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por6_18";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The gear of a Portuguese military SWORDS-MAN...";
	model.id	   =  "Soldier_Por2_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por3_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por4_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por5_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform of a man in the service of arms for Portugal.";
	model.id	   =  "Soldier_Por6_19";
	model.FaceId	= 120;
	model.minrank	 =  1;
	model.nation	  =  PORTUGAL;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier Potuguese

	// Soldier Spanish -->
	model.description =  "Plain, or smooth, or cheap breastplate, with a Spanish metal helmet.  Compliment that with a goatee, and you're talking one tough Spanish-looking adventurer!";
	model.id	   =  "Soldier_Spa_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This is the gear of the Conquistador, whose sun has not fully yet risen over the Archipelago!";
	model.id	   =  "Soldier_Spa2_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform and gear of a soldier of Spain.";
	model.id	   =  "Soldier_Spa3_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With a beard and this breastplate and Spanish helm, the image of seasoned soldiering is complete.";
	model.id	   =  "Soldier_Spa4_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A Clean-shaven Spanish Conquistador is a fresh Spanish Conquistador!";
	model.id	   =  "Soldier_Spa5_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa6_15";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_EARLY_EXPLORERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Plain, or smooth, or cheap breastplate, with a Spanish metal helmet.  Compliment that with a goatee, and you're talking one tough Spanish-looking adventurer!";
	model.id	   =  "Soldier_Spa_16";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This is the gear of the Conquistador, whose sun has not fully yet risen over the Archipelago!";
	model.id	   =  "Soldier_Spa2_16";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform and gear of a soldier of Spain.";
	model.id	   =  "Soldier_Spa3_16";
	model.FaceId	= 102;// TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With a beard and this breastplate and Spanish helm, the image of seasoned soldiering is complete.";
	model.id	   =  "Soldier_Spa4_16";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A Clean-shaven Spanish Conquistador is a fresh Spanish Conquistador!";
	model.id	   =  "Soldier_Spa5_16";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa6_16";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Plain, or smooth, or cheap breastplate, with a Spanish metal helmet.  Compliment that with a goatee, and you're talking one tough Spanish-looking adventurer!";
	model.id	   =  "Soldier_Spa_17";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This is the gear of the Conquistador, whose sun has not fully yet risen over the Archipelago!";
	model.id	   =  "Soldier_Spa2_17";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform and gear of a soldier of Spain.";
	model.id	   =  "Soldier_Spa3_17";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With a beard and this breastplate and Spanish helm, the image of seasoned soldiering is complete.";
	model.id	   =  "Soldier_Spa4_17";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A Clean-shaven Spanish Conquistador is a fresh Spanish Conquistador!";
	model.id	   =  "Soldier_Spa5_17";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa6_17";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Plain, or smooth, or cheap breastplate, with a Spanish metal helmet.  Compliment that with a goatee, and you're talking one tough Spanish-looking adventurer!";
	model.id	   =  "Soldier_Spa_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This is the gear of the Conquistador, whose sun has not fully yet risen over the Archipelago!";
	model.id	   =  "Soldier_Spa2_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform and gear of a soldier of Spain.";
	model.id	   =  "Soldier_Spa3_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With a beard and this breastplate and Spanish helm, the image of seasoned soldiering is complete.";
	model.id	   =  "Soldier_Spa4_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A Clean-shaven Spanish Conquistador is a fresh Spanish Conquistador!";
	model.id	   =  "Soldier_Spa5_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa6_18";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Plain, or smooth, or cheap breastplate, with a Spanish metal helmet.  Compliment that with a goatee, and you're talking one tough Spanish-looking adventurer!";
	model.id	   =  "Soldier_Spa_19";
	model.FaceId	= 102; // TALISMAN changed was 91
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  110;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "This is the gear of the Conquistador, whose sun has not fully yet risen over the Archipelago!";
	model.id	   =  "Soldier_Spa2_19";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "The uniform and gear of a soldier of Spain.";
	model.id	   =  "Soldier_Spa3_19";
	model.FaceId	= 102;  // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "With a beard and this breastplate and Spanish helm, the image of seasoned soldiering is complete.";
	model.id	   =  "Soldier_Spa4_19";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A Clean-shaven Spanish Conquistador is a fresh Spanish Conquistador!";
	model.id	   =  "Soldier_Spa5_19";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa6_19";
	model.FaceId	= 102; // TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "Yet another in a series of ensembles intended for a Spanish soldier.  The breastplate may be hot, and bad for swimming, but against a sword it can be quite welcome!";
	model.id	   =  "Soldier_Spa7_19";
	model.FaceId	= 102;// TALISMAN changed was 110
	model.minrank	 =  1;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier Spanish

	// Soldier USA -->
	model.description =  "A typical American soldier's kit.";
	model.id	   =  "Soldier_USA_18";
	model.FaceId	= 75;
	model.minrank	 =  1;
	model.nation	  =  AMERICA;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical American soldier's kit.";
	model.id	   =  "Soldier_USA2_18";
	model.FaceId	= 75;
	model.minrank	 =  1;
	model.nation	  =  AMERICA;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical American soldier's kit.";
	model.id	   =  "Soldier_USA3_18";
	model.FaceId	= 75;
	model.minrank	 =  1;
	model.nation	  =  AMERICA;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical American soldier's kit.";
	model.id	   =  "Soldier_USA4_18";
	model.FaceId	= 75;
	model.minrank	 =  1;
	model.nation	  =  AMERICA;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "A typical American soldier's kit.";
	model.id	   =  "Soldier_USA5_18";
	model.FaceId	= 75;
	model.minrank	 =  1;
	model.nation	  =  AMERICA;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);
	// <-- Soldier USA

	// JMV's Spanish officer models recoded by Jack Davidson using JMV's textures based on original Akella models -->
	model.description =  "A Spanish Naval Admiral's uniform.";
	model.id	   =  "spa_adm_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minlevel     =  16;
	model.minrank	=  8;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description	= "A distinguished Spanish admiral with many years of service - and medals to prove it.";
	model.id		= "spa_adm_18_2";	// GR: Spanish admiral for use in "Missing Son" sidequest in late periods
	model.FaceId		= 570;
	model.nation		= SPAIN;
	model.price		= 8500;
	model.minlevel		= 16;
	model.minrank		= 8;
	model.assigned		= true;
	model.playertype	= PLAYER_TYPE_NAVAL_OFFICER;
	model.period		= "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Captain's uniform.";
	model.id          =  "spa_cpt_18";
	model.FaceId      =  110;
	model.minlevel     =  10;
	model.minrank	=  5;
	model.nation      =  SPAIN;
	model.price       =  6150;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Captain's uniform.";
	model.id	   =  "spa_cpt1_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minlevel     =  10;
	model.minrank	=  5;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Captain's uniform.";
	model.id	   =  "spa_cpt2_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minlevel     =  10;
	model.minrank	=  5;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Lieutenant's uniform.";
	model.id          =  "spa_lut_18";
	model.FaceId      =  110;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation      =  SPAIN;
	model.price       =  3850;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Lieutenant's uniform.";
	model.id	   =  "spa_lut1_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minlevel     =  6;
	model.minrank	=  3;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Lieutenant's uniform.";
	model.id	   =  "spa_lut2_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minlevel     =  6;
	model.minrank	=  3;
	model.assigned	=  true;
	model.name = "Carrera";
	model.lastname = "de la Vega";
	model.storytitle = "The Might of Spain";
	model.storytext = "Ever since the Spanish set foot in the New World, others have tried and succeeded in taking more land away from them. But as recently promoted lieutenant in His Most Catholic Majesty's navy, you intend to see that Spain reclaims its rightful place in the world!";
	model.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 4;
	model.ship = "Galeoth1";
	model.shipname = "San Jeronimo";
	model.date.year = 1813;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Midshipman's uniform.";
	model.id	   =  "spa_mds1_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minrank	=  1;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "A Spanish Naval Midshipman's uniform.";
	model.id	   =  "spa_mds2_18";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  850;
	model.minrank	=  1;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_COLONIAL_POWERS + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, SPAIN);	// ccc Feb06
	AddCharacterModel(model);
	// <-- JMV's Spanish officer models recoded by Jack Davidson using JMV's textures based on original Akella models

	model.description	= "A Spanish Admiral bearing with pride the scars of many battles.";
	model.id		= "spa_Lezo";
	model.FaceId		= 609;
	model.nation		= SPAIN;
	model.price		= 9500;
	model.minlevel		= 8;
	model.minrank		= 9;	// Not strictly accurate, Blas de Lezo was Teniente General by 1739, but setting him to rank 9 allows the player to earn a promotion
	model.assigned		= true;
	model.name		= "Blas";
	model.lastname		= "de Lezo";
	model.storytitle	= "The Defender of Cartagena";
	model.storytext		= "Blas de Lezo started his naval career in 1701 at age twelve, serving France and Spain during the War of Spanish Succession. Never afraid to be under fire, by 1714 he had lost a leg, an eye, and the use of an arm, scars he wore as badges of honor. Despite his injuries he led a successful career and is now in command of the naval forces of Cartagena de Indias.";
	model.playertype	= PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate	= 23;
	model.Flags.Personal	= 27;
	model.ship		= "PO_Poseidon";
	model.shipname		= "Conquistador";
	model.date.day		= 1;
	model.date.month	= 3;
	model.date.year		= 1740;
	model.period		= "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AddCharacterModel(model);	

	// Assassin Main Quest -->
	model.description =  "";
	model.id	   =  "Spy1";
	model.FaceId	= 344;
	model.nation	  =  BROKEN;
	model.price	   =  3000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Spy2";
	model.FaceId	= 344;
	model.nation	  =  BROKEN;
	model.price	   =  3000;
	model.assigned	=  true;
	AddCharacterModel(model);
	// Assassin Main Quest <--

	// no model assignment quest character -->
	model.description =  "And so... we go to war!";
	model.id	   =  "Sri_Sumbhajee";
	model.FaceId	= 438;
	model.nation	  =  PIRATE;
	model.price	   =  5000;
	model.assigned	=  true;
	model.name = "Sri";
	model.lastname = "Sumbhajee";
	model.Flags.Pirate = 31;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Sri_Sumbhajee_aid";
	model.FaceId	= 213;
	model.nation = PIRATE;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "Ah, now here is the fine blue, somewhat large suit, black hat with blue band, and fitting accompaniments adding to the very image of a successful mercantile magnate!";
	model.id	   =  "storeman";
	model.FaceId	= 42;
	model.nation	  =  HOLLAND;
	model.price	   =  1150;
	model.assigned	=  true;
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "A suit in brown, from the hat to the coat and boots, and it had better have some room around the middle, if you get my drift...";
	model.id	   =  "Storeman2";
	model.FaceId	= 43;
	model.nation	  =  ENGLAND; // Estharos reassign April 9th, 2009
	model.price	   =  1050;
	model.assigned	=  true;
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "It has been torture, trapped in this single form, cut off from the sea.";
	model.id			=  "TiaDalma";
	model.FaceId		=  114;
	model.nation		=  PIRATE;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.90;
	model.sex			=  "woman";
	model.ani			=  "TiaDalma";
	model.name = "Tia";
	model.lastname = "Dalma";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description	=  "";
	model.id			=  "ThomasLinch";
	model.FaceId		=  331;
	model.nation		=  HOLLAND;
	model.price			=  5000;
	model.assigned		=  true;
	model.height		=  1.90;
	model.sex			=  "man";
	model.ani			=  "man";
	model.name = "Thomas";
	model.lastname = "Lynch";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "This nice dress compliments the blonde hair to create a beautiful picture of the nice town girl.";
	model.id	   =  "towngirl1";
	model.FaceId	= 52;
	model.nation	  =  FRANCE; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.1, PIRATE);
	AddCharacterModel(model);

	model.description =  "This dress is designed to nicely accent black hair for the urban lass.";
	model.id	   =  "towngirl1_1";
	model.FaceId	= 162;
	model.nation	  =  ENGLAND; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.1, PIRATE);
	AddCharacterModel(model);

	model.description =  "This fine dress is a perfect match for the dark eyes and hair of a girl from warm lands.";
	model.id	   =  "towngirl1_2";
	model.FaceId	= 269;
	model.nation	  =  PORTUGAL; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.1, PIRATE);
	AddCharacterModel(model);

	model.description	= "This gold and red dress should turn a few heads in any Spanish town.";
	model.id		= "towngirl1_3";
	model.FaceId		= 583;
	model.nation		= SPAIN; // made buyable
	model.price		= 1000;
	model.assigned		= true;
	model.sex		= "woman";
//	model.ani		= "towngirl";
	model.ani		= "woman_sit";
	model.height		=  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Upper_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.1, PIRATE);
	AddCharacterModel(model);

	model.description =  "In this set of clothes one would be forgiven if they were taken for a Dutch girl.";
	model.id	   =  "towngirl2";
	model.FaceId	= 163;
	model.nation	  =  FRANCE; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.05, PIRATE);
	AddCharacterModel(model);

	model.description =  "This blue accented dress and it's head covering will be pleasant in the Caribbean sun.";
	model.id	   =  "towngirl2_1";
	model.FaceId	= 164;
	model.nation	  =  PORTUGAL; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Upper_Citizens", 0.05, PIRATE);
	AddCharacterModel(model);

	model.description =  "Bonnets are coming back into fashion, and this outfit is at the forefront of that fashion trend.";
	model.id	   =  "towngirl3";
	model.FaceId	= 165;
	model.nation	  =  HOLLAND; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Middle_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Middle_Citizens", 0.03, PIRATE);
	AddCharacterModel(model);

	model.description =  "Yet another ensemble with a headress.  You'd think women don't wash their hair anymore...";
	model.id	   =  "towngirl3_1";
	model.FaceId	= 166;
	model.nation	  =  PORTUGAL; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Middle_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Middle_Citizens", 0.07, PIRATE);
	AddCharacterModel(model);

	model.description =  "This dress looks quite at home on the voluptuous body of the healthy and fit aristocratic woman, with a daring neckline designed to show just how healthy she is!";
	model.id	   =  "towngirl4";
	model.FaceId	= 167;
	model.nation	  =  SPAIN; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Rich_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Rich_Citizens", 0.1, PIRATE);
	AddCharacterModel(model);

	model.description =  "This tastefully simple outfit will be quite appropriate in any town in the Archipelago.";
	model.id	   =  "towngirl5";
	model.FaceId	= 168;
	model.nation	  =  FRANCE; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.2, PIRATE);
	AddCharacterModel(model);

	model.description =  "The blonde ringlets appearing from underneath this Dutch bonnet are the perfect adornment to a lady's dress.";
	model.id	   =  "towngirl6";
	model.FaceId	= 169;
	model.nation	  =  HOLLAND; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Lower_Citizens", 1.0, GetNationStringNorthEuroFr());
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.07, PIRATE);
	AddCharacterModel(model);

	model.description =  "This dress, with it's nice and alluring bodice compliment a head full of fiery red hair.";
	model.id	   =  "towngirl7";
	model.FaceId	= 170;
	model.nation	  =  ENGLAND; // made buyable
	model.price	   =  1000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelType(isstart, model, "Lower_Citizens", 1.0);
	AssignModelTypeNation(isstart, model, "Lower_Citizens", 0.05, PIRATE);
	AddCharacterModel(model);

	model.description =  "This dress features a light, cool upper; an elaborate brown bodice; and a green skirt to finish.";
	model.id	   =  "towngirl7_2";
	model.FaceId		= 579;
	model.nation		=  SPAIN; // made buyable
	model.price		=  1000;
	model.assigned		=  true;
	model.sex		=  "woman";
//	model.ani		=  "towngirl";
	model.ani		=  "woman_sit";
	model.height		=  1.75;
	model.iscombat = false;
	AssignModelType(isstart, model, "women", 1.0);
	AssignModelTypeNatMask(isstart, model, "Middle_Citizens", 1.0, GetNationStringSouthEuro());
	AssignModelTypeNation(isstart, model, "Middle_Citizens", 0.05, PIRATE);
	AddCharacterModel(model);

	model.description	= "A low-cut, dark red dress capped with a dark bonnet.";
	model.id	   	= "Rose"; // CoAS model by Nita
	model.FaceId		= 615;
	model.nation		= PIRATE;
	model.price		= 1500;
	model.name		= "Rose";
	model.assigned		= true;
	model.sex		= "woman";
	model.ani		= "woman_ab_PoTC";
	model.height	  	= 1.75;
	model.iscombat		= false;
	AssignModelType(isstart, model, "women", 1.0);
	AddCharacterModel(model);

// JMV's USA officer models recoded by Jack Davidson using JMV's textures based on original Akella models -->
	model.description =  "A lieutenant in the service of the United States of America!";
	model.id	   =  "USA_lut_18";
	model.FaceId	= 75;
	model.minlevel     =  6;
	model.minrank	 =  3;
	model.nation	  =  AMERICA;
	model.price	   =  1500;
	model.assigned	=  true;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, AMERICA);	// ccc Feb06
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, AMERICA);
	AddCharacterModel(model);

	model.description =  "A captain in the service of the United States of America!";
	model.id	   =  "USA_cpt_18";
	model.FaceId	= 75;
	model.minlevel     =  10;
	model.minrank	 =  5;
	model.nation	  =  AMERICA;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.name = "Josiah";
	model.lastname = "Peabody";
//	model.storytitle =  "The Captain from Connecticut"; // PB: Hide this one from Specific Characters because of John Paul Jones
	model.storytext  =  "Play the exploits of a typical U.S. Frigate cruising at sea during the War of 1812. Its captain, Josiah Peabody, demonstrates the revolutionary virtues of a new democracy fighting for its survival against an overwhelmingly superior British Navy.";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 2;
	model.Flags.Personal = 33;
	model.ship = "RN_Surprise";
	model.shipname = "Delaware";
	model.date.year = 1812;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, AMERICA);	// ccc Feb06
	AddCharacterModel(model);

	model.description =  "An admiral in the service of the United States of America!";
	model.id	   =  "USA_adm_18";
	model.FaceId	= 75;
	model.minlevel     =  16;
	model.minrank	 =  8;
	model.nation = AMERICA;
	model.price	   =  1500;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.period = "" + PERIOD_REVOLUTIONS + PERIOD_NAPOLEONIC;
	AssignModelTypeNation(isstart, model, "navy", 1.0, AMERICA);	// ccc Feb06
	AddCharacterModel(model);

//JRH-->
	model.description =  "A lieutenant in the service of the United States of America!";
	model.id	   =  "JP_Jones_lut";
	model.FaceId	= 223;
	model.nation	  =  AMERICA;
	model.assigned	=  true;
	model.name = "John";
	model.middlename = "Paul";
	model.lastname = "Jones";
	model.storytitle =  "The American Revolution";
	model.storytext  =  "Born in Scotland in 1742, your career at sea began at age 13, and by 21 you were the captain of a ship sailing between the West Indies and British ports. You joined the Continental navy for the American Revolution and have just been promoted to lieutenant. However, you have not yet begun to fight. The real battle for independence is yet to come!";
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 39;
	model.ship = "USS_Enterprise";
	model.shipname = "Enterprise";
	model.date.year = 1776;
	AddCharacterModel(model);

	model.description =  "A captain in the service of the United States of America!";
	model.id	   =  "JP_Jones_cpt";
	model.FaceId	= 220;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "An admiral in the service of the United States of America!";
	model.id	   =  "JP_Jones_adm";
	model.FaceId	= 218;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//<--JRH

	model.description =  "";
	model.id	   =  "Vanderdecken";
	model.FaceId	= 317;
	model.nation	  =  BROKEN;
	model.price	   =  2000;
	model.assigned	=  true;
//	model.name = "Hendrick";
//	model.lastname = "Vanderdecken";
	AddCharacterModel(model);

	model.description =  "Vito Leone, a seemingly harmless old gentleman, but is everything entirely as it seems?";
	model.id	   =  "Vito";
	model.FaceId	= 319;
	model.nation	  =  PORTUGAL;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "Vito";
	model.lastname = "Leone";
	AssignModelType(isstart, model, "Upper_Citizens", 1.0);
	AssignModelType(isstart, model, "Elderly", 1.0);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description	=  "Matey, yer seen-all, hard face can tell: You FINALLY earned a captains hat,and a decorative earring.";
	model.id		=  "wf1blaze";
	model.FaceId		=  "291";
	model.nation		=  PIRATE;
	model.price		=  5000;
	model.assigned		=  true;
	model.name = "Nathaniel";
	model.lastname = "Hawk";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	model.description =  "A nice little brown outfit, with a hat pinned up on the side, like Will Turner the swordsmith was wearing at the dock the other day!";
	model.id	  =  "will";
	model.FaceId	  = 58;
	model.nation	  = ENGLAND;
	model.price	  = 850;
	model.assigned	  = true;
	model.storytitle  = "A Second Calling";
	model.storytext	  = "After coming to terms with the truth about your father, you've decided it's time to retire from the smith and embrace the life of a sailor.";
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	model.name	  = "Will";
	model.lastname	  = "Turner";
	model.ship	  = "lugger4";
	model.shipname	  = "Miranda";
	model.Flags.Pirate   = 22;
	model.Flags.Personal = 15;
	model.date.year	  = 1750;
	AddCharacterModel(model);

	model.description = "A long black coat over a dark red shirt, like Will Turner on the Flying Dutchman.";
	model.id	  = "WillTurner2";
	model.FaceId	  = 616;
	model.nation	  = PIRATE;
	model.price	  = 850;
	model.assigned	  = true;
	model.storytitle  = "A Touch of Destiny";
	model.storytext	  = "Cursed for killing Davy Jones, you are now captain of the renewed Flying Dutchman. You are tasked to ferry the souls of the dead to the next world. But surely that can wait! For now, you have to become familiar with the tasks of Captain. What you do after that is up to you.";
	model.playertype  = PLAYER_TYPE_SWORD_MASTER;
	model.name	  = "Will";
	model.lastname	  = "Turner";
	model.ship	  = "FlyingDutchman";
	model.shipname	  = "Flying Dutchman";
	model.Flags.Pirate   = 22;
	model.Flags.Personal = 15;
	model.date.year	  = 1750;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description = "A black coat and grey shirt, like Bootstrap Bill without the fishy bits.";
	model.id	  = "BootstrapBill";
	model.FaceID	  = 617;
	model.nation	  = PIRATE;
	model.price	  = 600;
	model.assigned	  = true;
	model.name	  = "Bootstrap Bill";
	model.lastname	  = "Turner";
	model.playertype = PLAYER_TYPE_SAILOR;
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "Death is only the beginning.";
	model.id          =  "Orellana";
	model.FaceId      =  590;
	model.nation      =  SPAIN;
	model.price       =  5000;
	model.assigned    =  true;
	model.name = "Ricardo";
	model.lastname = "Orellana";
	model.loadingScreen = "Quest_Devil.tga";
	model.storytitle = "The Devil's Ship";
	model.storytext = "You made a pact with the Devil to save you and your love from certain death in exchange for your soul. The demon betrays you by taking away everything you cared about. With your heart full of rage and revenge, you sow death in your path with the help of your cursed ship.";
	model.ship = "CursedMariana";
	model.shipname = "La Mariana";
	model.playertype = PLAYER_TYPE_CURSED;
	model.Flags.Pirate = 29;
	model.Flags.Personal = 46;
	model.date.hour = 22;
	model.date.year = 1715;
	AddCharacterModel(model);
	
	// Armor Mod -->
	/*model.description =  "A nice little brown outfit, with a hat pinned up on the side and a steel cuirass, like Will Turner the swordsmith was wearing at the dock the other day!";
	model.id	   =  "will_A1";
	model.FaceId	= "will";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice little brown outfit, with a hat pinned up on the side and an engraved breastplate, like Will Turner the swordsmith was wearing at the dock the other day!";
	model.id	   =  "will_A2";
	model.FaceId	= "will";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A nice little brown outfit, with a hat pinned up on the side and a gilded breastplate, like Will Turner the swordsmith was wearing at the dock the other day!";
	model.id	   =  "will_A3";
	model.FaceId	= "will";
	model.nation	  =  BROKEN; // we autoassign it elsewhere
	model.price	   =  15000;
	model.assigned	=  true;
	AddCharacterModel(model);*/
	// <-- Armor Mod

	model.description =  "This dark outfit, with it's vest and pinned hat, was intended for an adventurer.";
	model.id	   =  "will_2";
	model.FaceId	= 44;
	model.nation	  =  ENGLAND;
	model.price	   =  250;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	AssignModelType(isstart, model, "Mates", 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_NAVIGATOR, 1.0);
	AssignModelType(isstart, model, OFFIC_TYPE_QMASTER, 1.0);
	AddCharacterModel(model);

	model.description =  "Give me an outfit suitable for an adventurer, but this time, make it a bit more evil.";
	model.id	   =  "will_3";
	model.FaceId	= 156;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_ADVENTURER;
	AddCharacterModel(model);

	// TALISMAN - INSERTING MISSING ENTRIES --- >
	model.description =  "Black boots, trousers, long grey hair and beard, and a very mean disposition that has increased with age.";
	model.id	   =  "50Grey2";
	model.FaceId	= 53;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Watch your back, you do not want to meet him in the jungle!";
	model.id	   =  "Andrew_Parson";
	model.FaceId	= 135;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Andrew";
	model.lastname = "Parson";
	AddCharacterModel(model);

	model.description =  "Passionate, jealous and dangerous - stay away from his lover if you want to live!";
	model.id	   =  "armdelfra";
	model.FaceId	= 31;
	model.nation	  =  PIRATE;
	model.price	   =  2000;
	model.assigned	=  true;
//	model.name = "Armand";
//	model.lastname = "Delacroix";
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_Farmer";
	model.FaceId	= 63;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_girl";
	model.FaceId	= 160;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_invisible";
	model.FaceId	= 100;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_man";
	model.FaceId	= 135;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_soldier";
	model.FaceId	= 9;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am invisible - you can't see me!";
	model.id	   =  "B_worker";
	model.FaceId	= 34;
	model.nation	  =  BROKEN;
	model.price	   =  50;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I want to take control of my world and build myself an empire!";
	model.id	   =  "CouchCaptainCharles";
	model.FaceId	= 179;
	model.nation	  =  PIRATE;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Couchcaptain";
	model.lastname = "Charles";
	AddCharacterModel(model);

	model.description =  "It is nothing personal, it is just good business.";
	model.id	   =  "Cutler_Beckett";
	model.FaceId	= 82;
	model.nation	  =  ENGLAND;
	model.price	   =  2000;
	model.assigned	=  true;
	model.name = "Cutler";
	model.lastname = "Beckett";
	model.storytitle = "Just Good Business";
	model.storytext = "As head of the East India Trading Company, you are in charge of one of the largest ships in the Caribbean. But you are a merchant first of all, and an unscrupulous one at that! Which means that the task of being captain is one you are not quite familiar with.";
	model.ship = "HMS_Endeavour";
	model.shipname = 	"Endeavour";
	model.playertype = PLAYER_TYPE_MERCHANT;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 24;
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description	=  "Half man, half lobster - one of Davy Jones' crew.";
	model.id		=  "Penrod";
	model.FaceId		= 610;
	model.nation		= CURSED;
	model.assigned		= true;
	model.camouflage	= true; // PB: Everyone is Enemy
	model.sex		= "skeleton";
	model.height		= 1.85;
	model.ani		= "Rousselet";
	model.status		= "C_III"; // added as an identifier, for assigning another animation to the new models
//	AssignModelType(isstart, model, "Davycrew", 1.0);	// Cancel this so he can't appear as random deck crew
	AddCharacterModel(model);

	model.description	= "Half man, half hammerhead shark - one of Davy Jones' crew.";
	model.id		=  "Maccus";
	model.FaceId		= 611;
	model.nation		= CURSED;
	model.assigned		= true;
	model.camouflage	= true; // PB: Everyone is Enemy
	model.sex		= "skeleton";
	model.height		= 1.85;
	model.ani		= "Rousselet";
	model.status		= "C_III"; // added as an identifier, for assigning another animation to the new models
//	AssignModelType(isstart, model, "Davycrew", 1.0);	// Cancel this so he can't appear as random deck crew
	AddCharacterModel(model);

	model.description	= "Half man, half shellfish - one of Davy Jones' crew.";
	model.id		= "Palafico";
	model.FaceId		= 612;
	model.nation		= CURSED;
	model.assigned		= true;
	model.camouflage	= true; // PB: Everyone is Enemy
	model.sex		= "skeleton";
	model.height		= 1.85;
	model.ani		= "Rousselet";
	model.status		= "C_III"; // added as an identifier, for assigning another animation to the new models
//	AssignModelType(isstart, model, "Davycrew", 1.0);	// Cancel this so he can't appear as random deck crew
	AddCharacterModel(model);

	model.description	= "Half man, half shellfish - one of Davy Jones' crew.";
	model.id		= "Hadras";
	model.FaceId		= 613;
	model.nation		= CURSED;
	model.assigned		= true;
	model.camouflage	= true; // PB: Everyone is Enemy
	model.sex		= "skeleton";
	model.height		= 1.85;
	model.ani		= "Rousselet";
	model.status		= "C_III"; // added as an identifier, for assigning another animation to the new models
//	AssignModelType(isstart, model, "Davycrew", 1.0);	// Cancel this so he can't appear as random deck crew
	AddCharacterModel(model);

	model.description =  "Your first basic collection of animated old bones covered in seaweed.";
	model.id	   =  "davy1";
	model.FaceId	= 262;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Davycrew", 1.0);
	AddCharacterModel(model);

	model.description =  "Your second basic collection of animated old bones covered in seaweed.";
	model.id	   =  "davy2";
	model.FaceId	= 263;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Davycrew", 1.0);
	AddCharacterModel(model);

	model.description =  "Your third basic collection of animated old bones covered in seaweed.";
	model.id	   =  "davy3";
	model.FaceId	= 264;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Davycrew", 1.0);
	AddCharacterModel(model);

	model.description =  "Your fourth basic collection of animated old bones covered in seaweed.";
	model.id	   =  "davy4";
	model.FaceId	= 265;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Davycrew", 1.0);
	AddCharacterModel(model);

	model.description =  "Your fifth basic collection of animated old bones covered in seaweed.";
	model.id	   =  "davy5";
	model.FaceId	= 153;
	model.nation	  =  CURSED;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Davycrew", 1.0);
	AddCharacterModel(model);

	model.description =  "A very strange collection of animated bones, was it ever human.";
	model.id	   =  "Skelt";
	model.FaceId	= 265;
	model.nation	  =  CURSED;
	model.price	   =  5000;
	model.assigned	=  true;
	model.camouflage = true; // PB: Everyone is Enemy
	model.sex		 =  "skeleton";
	model.ani		 =  "man"; // was skeleton
	AssignModelType(isstart, model, "Ghost", 1.0);
	AddCharacterModel(model);

	model.description =  "I need to kill a lot of people, but very quietly!";
	model.id	   =  "DO_Assasin1";
	model.FaceId	= 139;
	model.nation	  =  SPAIN;
	model.price	   =  2500;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "You have business with me, senor?";
	model.id	   =  "Francisco_Cruz";
	model.FaceId	= 36;
	model.nation	  =  SPAIN;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Francisco";
	model.lastname = "Cruz";
	AddCharacterModel(model);

	model.description =  "I fight for the glory of France.";
	model.id	   =  "Gener_fra_16";
	model.FaceId	= 416;
	model.nation	  =  FRANCE;
	model.price	   =  5000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "This dress looks quite at home on the voluptuous body of the healthy and fit aristocratic woman, with a daring neckline designed to show just how healthy she is!";
	model.id	   =  "imgovwife";
	model.FaceId	= 167;
	model.nation	  =  SPAIN; // made buyable
	model.price	   =  5000;
	model.assigned	=  true;
	model.sex		 =  "woman";
//	model.ani		 =  "towngirl";
	model.ani		=  "woman_sit";
	model.height	  =  1.75;
	model.iscombat = false;
//	model.name = "Estrella";
//	model.lastname = "de Alencar";
	AddCharacterModel(model);

	model.description =  "You have business with me, senor? Are you sure?";
	model.id	   =  "Leonardo_Corrales";
	model.FaceId	= 27;
	model.nation	  =  SPAIN;
	model.price	   =  1000;
	model.assigned	=  true;
//	model.name = "Leonardo";
//	model.lastname = "Corrales";
	AddCharacterModel(model);

	model.description =  "You would be unwise to pick a fight with me!";
	model.id	   =  "Merciless_Mark";
	model.FaceId	= 65;
	model.nation	  =  PIRATE;
	model.price	   =  1000;
	model.assigned	=  true;
	model.name = "Merciless";
	model.lastname = "Mark";
	AddCharacterModel(model);

	model.description =  "For the person who wants to rule the natives, the traditional garb of an Akellani.";
	model.id	   =  "Native_Chief";
	model.FaceId	= 259;
	model.assigned	=  true;
	model.sex		= "skeleton"; // was Mummy
	model.ani		= "Man";
	AddCharacterModel(model);

	model.description =  "A soldier of France. Loyal and true.";
	model.id	   =  "Offi_fra77";
	model.FaceId	= 101;
	model.nation	  =  FRANCE;
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A soldier of England. Loyal and true sometimes.";
	model.id	   =  "Offic_en77";
	model.FaceId	= 99;
	model.nation	  =  ENGLAND;
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A soldier of Spain. Loyal and true.";
	model.id	   =  "offic_sp77";
	model.FaceId	= 102; // TALISMAN changed was 86
	model.nation	  =  SPAIN;
	model.price	   =  4000;
	model.assigned	=  true;
	model.period = "" + PERIOD_NAPOLEONIC;
	AddCharacterModel(model);

	model.description =  "A soldier of Spain. Loyal and true.";
	model.id	   =  "Offic_spa47";
	model.FaceId	= 110;
	model.nation	  =  SPAIN;
	model.price	   =  4000;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "A life on the ocean waves. A sailors life for me.";
	model.id	   =  "Sailor14";
	model.FaceId	= 54;
	model.price	   =  150;
	model.assigned	=  true;
	model.playertype = PLAYER_TYPE_SAILOR;
	AssignModelType(isstart, model, "Sailors", 1.0);
	AddCharacterModel(model);

	model.description =  "Can't stand Beckett. He is just not a gentleman. Let me sleep on the problem.";
	model.id	   =  "SirChristopherMings";
	model.FaceId	= 128;
	model.nation	  =  PIRATE;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Sir Christopher";
	model.lastname = "Mings";
	AddCharacterModel(model);

	model.description =  "Do you think I sell inferior goods and charge exorbitant prices? That is a damnable lie, sir!";
	model.id	   =  "storeman1";
	model.FaceId	= 42;
	model.nation	  =  HOLLAND;
	model.price	   =  1150;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Surrender your ship or surrender your life.";
	model.id	   =  "Terror";
	model.FaceId	= 202;
	model.nation	  =  PIRATE;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Morgan";
	model.lastname = "Terror";
	AddCharacterModel(model);

	model.description =  "Just because I dress well don't think I won't slit your throat if I have to.";
	model.id	   =  "Thomas_the_Terror";
	model.FaceId	= 371;
	model.nation	  =  PIRATE;
	model.price	   =  2500;
	model.assigned	=  true;
	model.name = "Thomas the";
	model.lastname = "Terror";
	AddCharacterModel(model);

	model.description = "A nice little brown outfit, to wear while I learn to be hide my deviousness!";
	model.id	  = "Young_Beckett";
	model.FaceId	  = 81;
	model.nation	  = ENGLAND;
	model.price	  = 2500;
	model.assigned	  = true;
	model.name	  = "Cutler";
	model.lastname	  = "Beckett";
	model.ship	  = "HMS_Bounty";
	model.shipname	  = "Lindesfarne";
	model.playertype  = PLAYER_TYPE_MERCHANT;
	model.Flags.Pirate = 23;
	model.Flags.Personal = 24;
	model.date.year = 1740;
	AddCharacterModel(model);
	//<---- TALISMAN - INSERTING MISSING ENTRIES

	model.description = "The rusty, blood-splattered hook of Captain Uziah Wurmwoode has slit open more than a few gullets in its day, while this rotting wooden leg was formed from the corpse of a burnt galleon... and this pesky eyepatch simply WILL NOT stay on!";
	model.id	   =  "wurmwoode";
	model.FaceId	= 203;
	model.nation	  =  PIRATE;
	model.price	   =  1800;
	model.assigned	=  true;
	model.name = "Uziah";
	model.lastname = "Wurmwoode";
	AssignModelTypeNation(isstart, model, "Captains", 1.0, PIRATE);
	AddCharacterModel(model);

	// no model assignment quest character -->
	model.description =  "The best friend of Bartolomeu o Portugues: A faithful comrade.";
	model.id	   =  "Emilio1";
	model.FaceId	= 70;
	model.nation	  =  PORTUGAL;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Emilio";
	model.lastname = "Soares";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// no model assignment quest character -->
	model.description =  "The best friend of Bartolomeu o Portugues: A faithful comrade.";
	model.id	   =  "Emilio2";
	model.FaceId	= 70;
	model.nation	  =  PIRATE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Emilio";
	model.lastname = "Soares";
	AddCharacterModel(model);
	// <-- no model assignment quest character

	// For the Bartolomeu o Portugues quest -->
	model.description =  "I feel like a dangerous pirate. How about something like Francois L'Ollonais?";
	model.id	   =  "Francois_L'Ollenais";
	model.FaceId	= 72;
	model.nation	  =  PIRATE;
	model.price	   =  470;
	model.assigned	=  true;
	model.name = "Francois";
	model.lastname = "L'Ollenais";
	model.ship = "FR_Derfflinger";
	model.shipname = 	"Saint-Jean";
	AddCharacterModel(model);
	// <-- For the Bartolomeu o Portugues quest

	// JRMM officers
	model.description =  "A fancy captain's uniform in navy blue with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMCpt";
	model.FaceId      =  553;
	model.minlevel     =  10;
	model.minrank     =  5;
	model.nation      =  ENGLAND;
	model.price       =  1500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);

	model.description =  "A fancy first mate's uniform in navy blue with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMCmd"; 
	model.FaceId      =  554;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  1500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);

	model.description =  "A fancy second mate's uniform in navy blue with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMLcm";
	model.FaceId      =  555;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  1500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);

	model.description =  "A fancy lieutenant's uniform in navy blue with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMLt1";
	model.FaceId      =  556;
	model.minrank     =  3;
	model.minlevel     =  6;
	model.nation      =  ENGLAND;
	model.price       =  1500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);

	model.description =  "Another fancy lieutenant's uniform in navy blue with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMLt2";
	model.FaceId      =  557;
	model.minlevel     =  6;
	model.minrank     =  3;
	model.nation      =  ENGLAND;
	model.price       =  1500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_NAVAL_OFFICER;
	AddCharacterModel(model);

	model.description =  "A navy blue coat with gold trim, black hat, and black spats.";
	model.id          =  "47_JRMMSub";
	model.FaceId      =  558;
	model.minrank     =  1;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	model.name = "Julian";
	model.lastname = "McAllister";
	model.storytitle =  "Brave Black Flag";
	model.storytext  =  "You have led a mutiny against your cruel captain who meant to kill a group of your countrymen taken as pirates. Now, on the run and marked as a traitor, you must decide what path to follow. Your actions have earned you the respect of the Brotherhood of Pirates. Will you join them under the brave black flag?";
	model.loadingScreen = "Character_BraveBlackFlag.tga";
	model.playertype = PLAYER_TYPE_REBEL;
	model.difficulty = DIFFICULTY_SEADOG;
	model.Flags.Pirate = 5;
	model.Flags.Personal = 30;
	model.ship = "BrigRoyal";
	model.shipname = "Defiance";
	model.date.hour = 13;
	model.date.min = 20;
	model.date.sec = 33;
	model.date.day = 14;
	model.date.month = 5;
	model.date.year = 1682;
	AddCharacterModel(model);

	model.description =  "A navy blue coat with gold trim, black hat, black spats, and a black chest belt.";
	model.id          =  "Corsair1_J";
	model.FaceId      =  559;
	model.nation      =  ENGLAND;
	model.price       =  500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AddCharacterModel(model);

	model.description =  "A sharp looking black captain's uniform.";
	model.id          =  "Corsair2_J";
	model.FaceId      =  560;
	model.nation      =  ENGLAND;
	model.price       =  500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AddCharacterModel(model);

	model.description =  "A typical captain's uniform with blue stockings and blonde hair.";
	model.id          =  "Corsair3_J";
	model.FaceId      =  561;
	model.nation      =  ENGLAND;
	model.price       =  500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AddCharacterModel(model);

	model.description =  "A typical captain's uniform but with black pants and a nicer vest.";
	model.id          =  "Corsair4_J";
	model.FaceId      =  562;
	model.nation      =  ENGLAND;
	model.price       =  500;
	model.assigned    =  true;
	model.playertype  = PLAYER_TYPE_CORSAIR;
	AddCharacterModel(model);

	model.description =  "A proper piratin' outfit with a vest and bandanna.  Yarr!";
	model.id          =  "CapJRMM";
	model.FaceId      =  563;
	model.nation      =  ENGLAND;
	model.price       =  1000;
	model.assigned    =  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "indian_trader";
	model.FaceId	= 564;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "I am a Pirate Lord, and you are nothing!";
	model.id	   =  "Villanueva";
	model.FaceId	= 215;
	model.nation	  =  PIRATE;
	model.price       =  2500;
	model.assigned	=  true;
	model.name = "Eduardo";
	model.lastname = "Villanueva";
	model.Flags.Pirate = 5;
	model.ship = "SP_Neptunus";
	model.shipname = "Sargento";
	model.date.year = 1740;
	AddCharacterModel(model);

	model.description =  "An aristocratic fancy French lady, but one with a shady past...";
	model.id    	  =  "Milady";
	model.FaceId	  = 216;
	model.nation      =  FRANCE;
	model.price       =  2500;
	model.assigned    =  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Milady";
	model.lastname = "de Winter";
	model.storytitle = "Spy and Assassin";
	model.storytext = "You are a woman who is cunning, relentless, resourceful, amoral and dangerous. Tasked with causing harm to your nations' enemies by whatever means necessary, you will stop at nothing to fulfil that purpose.";
	model.playertype = PLAYER_TYPE_AGENT;
	model.Flags.Pirate = 34;
	model.Flags.Personal = 41;
	model.ship = "FR_CastelF";
	model.shipname = "Athos";
	model.date.hour = 20;
	model.date.month = 11;
	model.date.year = 1625;
	AddCharacterModel(model);

	model.description =  "An aristocratic fancy French lady, but one with a shady past, who doesn't want to be seen...";
	model.id    	  =  "Milady2";
	model.FaceId	  = 216;
	model.nation      =  FRANCE;
	model.price       =  3000;
	model.assigned    =  true;
//	model.camouflage  =  true; // For sneaking around while being a spy or assassin, disabled for now because it makes everyone hostile
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	model.height      =  1.75;
	model.name = "Milady";
	model.lastname = "de Winter";
	model.playertype = PLAYER_TYPE_AGENT;
	model.Flags.Pirate = 34;
	model.Flags.Personal = 41;
	model.ship = "FR_CastelF";
	model.shipname = "Athos";
	model.date.hour = 20;
	model.date.month = 11;
	model.date.year = 1625;
	AddCharacterModel(model);

	model.description = "A French aristocrat with a dark outfit and a darker temperament.";
	model.id    	  = "Rochefort";
	model.FaceID	  = 325;
	model.nation	  = FRANCE;
	model.assigned	  = true;
	model.name	  = "Comte";
	model.lastname	  = "de Rochefort";
	model.playertype  = PLAYER_TYPE_AGENT;
	model.Flags.Pirate = 19;
	model.Flags.Personal = 5;
	model.date.year	  = 1625;
	AddCharacterModel(model);

 // JRH quest -->
	//mainchar black monk portraits
	model.description =  "";
	model.id	   =  "Animist4A";
	model.FaceId	= 294;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male & female dirty pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4B";
	model.FaceId	= 295;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar female black monk portraits
	model.description =  "";
	model.id	   =  "Animistsf";
	model.FaceId	= 296;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M";
	model.FaceId	= 298;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male red bandana, pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_C";
	model.FaceId	= 309;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------
	//mainchar male, trousers/skirt + blaze portraits, no waistcoat, no socks!
	model.description =  "";
	model.id	   =  "BlazePira4M_WL";
	model.FaceId	= 16;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male, trousers/skirt + blaze portraits, no waistcoat!
	model.description =  "";
	model.id	   =  "BlazePira4M_WT";
	model.FaceId	= 16;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------
	//mainchar male red bandana, trousers/skirt + pirat4 portraits, no waistcoat!
	model.description =  "";
	model.id	   =  "Pira4M_WT";
	model.FaceId	= 309;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male red bandana, trousers/skirt + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_CT";
	model.FaceId	= 309;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------
	//mainchar male pirat3 hat + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_H";
	model.FaceId	= 297;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HT";
	model.FaceId	= 312;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTU";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, rope + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTU_r";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, rope, (chain) + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTU_cr";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, sash, rope, (chain) + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS_cr";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, sash + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, sash + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS_r2";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, sash, phorn + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS_ph";
	model.FaceId	= 302;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------------------------------------------------
	//mainchar male pirat3 hat, trousers/skirt, uniform, sash, belt + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS_b";
	model.FaceId	= 304;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 hat, trousers/skirt, uniform, sash, belt, ammobag + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_HTUS_a";
	model.FaceId	= 304;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------------------------------------------------
	//mainchar male pirat3 trousers/skirt, uniform, sash, + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_TUS";
	model.FaceId	= 308;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 trousers/skirt, uniform, sash, belt + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_TUS_b";
	model.FaceId	= 311;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male pirat3 trousers/skirt, uniform, sash, belt, ammobag + pirat4 portraits
	model.description =  "";
	model.id	   =  "Pira4M_TUS_a";
	model.FaceId	= 311;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//-------------------------------------------------------------------------------------------------------------
	//mainchar male hat, red monk portraits
	model.description =  "";
	model.id	   =  "PriestRedM";
	model.FaceId	= 313;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male hat, belt red monk portraits
	model.description =  "";
	model.id	   =  "PriestRedM_b";
	model.FaceId	= 315;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male hat, belt, ammobag red monk portraits
	model.description =  "";
	model.id	   =  "PriestRedM_a";
	model.FaceId	= 315;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male hat, red rolls of cloth red monk portraits
	model.description =  "";
	model.id	   =  "PriestRedM_cloth";
	model.FaceId	= 315;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
	//mainchar male red Shkiper
	model.description =  "";
	model.id	   =  "ShkiperM_U";
	model.FaceId	= 299;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male red Shkiper, hat
	model.description =  "";
	model.id	   =  "ShkiperM_UH";
	model.FaceId	= 303;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
	//mainchar male red Shkiper, belt
	model.description =  "";
	model.id	   =  "ShkiperM_U_b";
	model.FaceId	= 342;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male red Shkiper, hat, belt
	model.description =  "";
	model.id	   =  "ShkiperM_UH_b";
	model.FaceId	= 348;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
	//mainchar male red Shkiper, belt, ammobag
	model.description =  "";
	model.id	   =  "ShkiperM_U_a";
	model.FaceId	= 342;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//mainchar male red Shkiper, hat, belt, ammobag
	model.description =  "";
	model.id	   =  "ShkiperM_UH_a";
	model.FaceId	= 348;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
	//Caroline K
	model.description =  "";
	model.id	   =  "Caroline_K";
	model.FaceId	= 310;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	model.sex         =  "woman";
	model.ani         =  "woman_sit";
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Caroline_officer";
	model.FaceId	= 310;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Claire Voyant
	model.description =  "";
	model.id	   =  "OldWomanPriest";
	model.FaceId	= 305;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Woodes Rogers
	model.description =  "";
	model.id	   =  "Woodes_Rogers";
	model.FaceId	= 307;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
	model.description =  "";
	model.id	   =  "Howard_Pyle";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_1";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_2";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_3";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_4";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_5";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_b";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_a";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_hat";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_hat_b";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Howard_Pyle_hat_a";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "invisible";
	model.FaceId	= 488;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "invisible2";
	model.FaceId	= "606";		//invisible icon
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animist4B";
	model.FaceId	= 489;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animist4C";
	model.FaceId	= 490;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Monk4";
	model.FaceId	= 491;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Sk3Pri";
	model.FaceId	= 492;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "W1_Natalia";
	model.FaceId	= 493;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "W2_Serena";
	model.FaceId	= 494;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "W4_Celia";
	model.FaceId	= 495;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "W5_barwench";
	model.FaceId	= 496;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "landlady_private";
	model.FaceId	= 496;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Blowhorn_monk";
	model.FaceId	= 62;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RNSail01HB";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RNSail02HB";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RNSail03HB";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RNSail04HB";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "RNSail05HB";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

//.......................................................................................
//Rogers officers
	model.description =  "";
	model.id	   =  "wr_aub";
	model.FaceId	= 497;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir13";
	model.FaceId	= 498;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cor4";
	model.FaceId	= 499;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_bri";
	model.FaceId	= 500;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_boc5";
	model.FaceId	= 501;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_voy";
	model.FaceId	= 502;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_voy2";
	model.FaceId	= 502;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_voy3";
	model.FaceId	= 502;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_bochat";
	model.FaceId	= 503;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_oman1X";
	model.FaceId	= 504;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
//Rogers crew
	model.description =  "";
	model.id	   =  "wr_raoul";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_omat1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_prt7";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_rabbl";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_blcor";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_sail4";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_sail7";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_snav";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_oman1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_boc1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_boc4";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cha";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cor1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cor3";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fat2";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fralut";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fsh";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_hubspa";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_kor";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mong";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_nap";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_grey";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir2";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir4";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fatj";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir7";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_wll3";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_sol6f77";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_solhol";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_boc3";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_bry1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_chv1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cor1_1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_cor1_3";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fsh1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_fwn";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_kor1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_man2";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_man3";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_oman2";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir5";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_sail1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_hubport";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_kill";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_18_1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_hubspa5";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_solspa4";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_vito";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_9SNat";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_evl2";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_blm";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_Ron";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_ltnorr";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_man4";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_man5_1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_pir9";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_will";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_bucc1";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_boc16";
	model.FaceId	= 505;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//guncrew
	model.description =  "";
	model.id	   =  "guncrew_1";
	model.FaceId	= 530;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "guncrew_2";
	model.FaceId	= 531;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "guncrew_3";
	model.FaceId	= 532;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "guncrew_4";
	model.FaceId	= 533;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//Rogers former crew
	model.description =  "";
	model.id	   =  "wr_dead1";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead2";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead3";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead4";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead5";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead6";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead7";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead8";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead9";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead10";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead11";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_dead12";
	model.FaceId	= 508;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_no_head1";
	model.FaceId	= 509;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_no_head2";
	model.FaceId	= 509;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_no_head3";
	model.FaceId	= 509;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
	model.description =  "";
	model.id	   =  "Grandma_Rogers";
	model.FaceId	= 506;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Grandma_boss";
	model.FaceId	= 506;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dave_Edna";
	model.FaceId	= 273;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dave_clerk";
	model.FaceId	= 273;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dave_officer";
	model.FaceId	= 273;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Selkirk_officer";
	model.FaceId	= 150;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rabwhite1Priest";
	model.FaceId	= 150;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Friday_officer";
	model.FaceId	= 148;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_black";
	model.FaceId	= 148;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Daniel_Defoe";
	model.FaceId	= 34;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "prisoner_Defoe";
	model.FaceId	= 34;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
	model.description =  "";
	model.id	   =  "prisoner_Laurence_Wellman";
	model.FaceId	= 27;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "prisoner_Sarah_Fitter";
	model.FaceId	= 166;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "prisoner_Silehard";
	model.FaceId	= 45;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "prisoner_wr_bri";
	model.FaceId	= 500;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Nickerson_poor";
	model.FaceId	= 54;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
	model.description =  "";
	model.id	   =  "Skel2_body";
	model.FaceId	= 263;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//crypt mummies
	model.description =  "";
	model.id	   =  "wr_mummy1";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy2";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy3";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy4";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy5";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy6";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy7";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy8";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "wr_mummy9";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//pir_caps
	model.description =  "";
	model.id	   =  "pir_cap1";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap2";
	model.FaceId	= 510;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap3";
    model.FaceId	= 514;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap4";
	model.FaceId	= 59;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap5";
	model.FaceId	= 14;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap6";
	model.FaceId	= 10;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap7";
	model.FaceId	= 131;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap8";
	model.FaceId	= 98;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap9";
	model.FaceId	= 127;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap10";
	model.FaceId	= 3;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap11";
	model.FaceId	= 129;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap12";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap13";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap14";
	model.FaceId	= 123;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap15";
	model.FaceId	= 32;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap16";
	model.FaceId	= 511;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap17";
    model.FaceId	= 515;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap18";
   	model.FaceId	= 516;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap19";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap20";
	model.FaceId	= 177;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap21";
   	model.FaceId	= 517;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap22";
	model.FaceId	= 44;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap23";
	model.FaceId	= 54;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap24";
   	model.FaceId	= 518;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap25";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap26";
	model.FaceId	= 206;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap27";
    model.FaceId	= 519;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap28";
	model.FaceId	= 28;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap29";
	model.FaceId	= 19;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap30";
	model.FaceId	= 513;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap31";
    model.FaceId	= 512;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap32A";
	model.FaceId	= 33;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//pir_caps as red monks
	model.description =  "";
	model.id	   =  "pir_cap1_cloth";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap1_red";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap1_redC";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap1_redC_M";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap1_redC_MD";
	model.FaceId	= 225;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap8_red_M";
	model.FaceId	= 98;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap8_red_MD";
	model.FaceId	= 98;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap16_red_M";
	model.FaceId	= 511;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap16_red_MD";
	model.FaceId	= 511;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap18_red_M";
	model.FaceId	= 516;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap18_red_MD";
	model.FaceId	= 516;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap23_red_M";
	model.FaceId	= 54;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "pir_cap23_red_MD";
	model.FaceId	= 54;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_black";
	model.FaceId	= 148;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Rabwhite1Priest";
	model.FaceId	= 150;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_M";
	model.FaceId	= 534;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_M_black";
	model.FaceId	= 534;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_MD1";
	model.FaceId	= 534;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists1_MD2";
	model.FaceId	= 534;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//----------------------------------------------
//gm_crew officers
	//boatswain
	model.description =  "";
	model.id	   =  "gm_crew1";
	model.FaceId	= 314;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//doctor
	model.description =  "";
	model.id	   =  "gm_crew4";
	model.FaceId	= 316;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//big fighter
	model.description =  "";
	model.id	   =  "gm_crew5";
	model.FaceId	= 326;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//carpenter
	model.description =  "";
	model.id	   =  "gm_crew3";
	model.FaceId	= 334;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//gunner
	model.description =  "";
	model.id	   =  "gm_crew10";
	model.FaceId	= 335;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//spanish fighter
	model.description =  "";
	model.id	   =  "gm_crew11";
	model.FaceId	= 349;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//quartermaster
	model.description =  "";
	model.id	   =  "gm_crew18";
	model.FaceId	= 341;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//first mate
	model.description =  "";
	model.id	   =  "gm_crew20";
	model.FaceId	= 338;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//navigator
	model.description =  "";
	model.id	   =  "gm_crew22";
	model.FaceId	= 339;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
//gm_crew
	//cannons
	model.description =  "";
	model.id	   =  "gm_crew13";
	model.FaceId	= 520;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//cannons
	model.description =  "";
	model.id	   =  "gm_crew23";
	model.FaceId	= 520;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//accuracy
	model.description =  "";
	model.id	   =  "gm_crew12";
	model.FaceId	= 521;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//sailing
	model.description =  "";
	model.id	   =  "gm_crew14";
	model.FaceId	= 522;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//sailing
	model.description =  "";
	model.id	   =  "gm_crew21";
	model.FaceId	= 522;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//grappling
	model.description =  "";
	model.id	   =  "gm_crew15";
	model.FaceId	= 523;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//grappling
	model.description =  "";
	model.id	   =  "gm_crew16";
	model.FaceId	= 523;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//leadership
	model.description =  "";
	model.id	   =  "gm_crew17";
	model.FaceId	= 524;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//defence
	model.description =  "";
	model.id	   =  "gm_crew19";
	model.FaceId	= 525;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//repair
	model.description =  "";
	model.id	   =  "gm_crew2";
	model.FaceId	= 526;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//fencing
	model.description =  "";
	model.id	   =  "gm_crew6";
	model.FaceId	= 527;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//fencing
	model.description =  "";
	model.id	   =  "gm_crew7";
	model.FaceId	= 527;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//luck
	model.description =  "";
	model.id	   =  "gm_crew8";
	model.FaceId	= 528;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//commerce
	model.description =  "";
	model.id	   =  "gm_crew9";
	model.FaceId	= 529;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
//.......................................................................................
//Blackbeard
	//Israel Hands
	model.description =  "";
	model.id	   =  "bb_Hands1";
	model.FaceId	= 535;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Israel Hands, one leg
	model.description =  "";
	model.id	   =  "bb_Hands2";
	model.FaceId	= 535;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Israel Hands, one leg english officer
	model.description =  "";
	model.id	   =  "bb_Hands2_officer";
	model.FaceId	= 535;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);


	//Richards
	model.description =  "";
	model.id	   =  "bb_Richards";
	model.FaceId	= 394;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Pell
	model.description =  "";
	model.id	   =  "bb_Pell";
	model.FaceId	= 400;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Pell, english officer
	model.description =  "";
	model.id	   =  "bb_Pell_officer";
	model.FaceId	= 400;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Pell prisoner
	model.description =  "";
	model.id	   =  "bb_Pell_prisoner";
	model.FaceId	= 401;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//capJRMM as english soldier
	model.description =  "";
	model.id          =  "bb_qm_soldier";
	model.FaceId      =  563;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Edward Teach
	model.description =  "";
	model.id	   =  "bb_Teach1";
	model.FaceId	= 536;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "bb_Teach2";
	model.FaceId	= 536;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "bb_Teach3";
	model.FaceId	= 536;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Edward Teach head
	model.description =  "";
	model.id	   =  "bb_Teach1_head";
	model.FaceId	= 544;		//skull & bones
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Caesar
	model.description =  "";
	model.id	   =  "bb_Caesar";
	model.FaceId	= 597;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//JRH
	model.description =  "";
	model.id	   =  "jrh";
	model.FaceId	= 537;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Caesar as black servant
	model.description =  "";
	model.id	   =  "black_servant2";
	model.FaceId	= 597;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//the other black servant
	model.description =  "";
	model.id	   =  "black_servant1";
	model.FaceId	= 321;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Charles Eden
	model.description =  "";
	model.id	   =  "bb_Eden";
	model.FaceId	= 319;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Tobias Knight
	model.description =  "";
	model.id	   =  "bb_Knight";
	model.FaceId	= 185;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//white nuns
	model.description =  "";
	model.id	   =  "Animistsg";
	model.FaceId	= 395;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//white abbess
	model.description =  "";
	model.id	   =  "Animistsh";
	model.FaceId	= 396;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Monk6";
	model.FaceId	= 397;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Monk7";
	model.FaceId	= 398;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Monk8";
	model.FaceId	= 399;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

//GOLDBUG
	//William Legrand
	model.description =  "";
	model.id	   =  "William Legrand";
	model.FaceId	= 119;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//William Legrand with a rope
	model.description =  "";
	model.id	   =  "William Legrand2";
	model.FaceId	= 119;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//William Legrand with a bag (with a compass)
	model.description =  "";
	model.id	   =  "William Legrand3";
	model.FaceId	= 119;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//William Legrand with a sack
	model.description =  "";
	model.id	   =  "William Legrand_sack";
	model.FaceId	= 119;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//William Legrand with hat in the air
	model.description =  "";
	model.id	   =  "William Legrand_hat";
	model.FaceId	= 119;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Jupiter
	model.description =  "";
	model.id	   =  "Jupiter";
	model.FaceId	= 384;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Jupiter
	model.description =  "";
	model.id	   =  "Jupiter_sack";
	model.FaceId	= 384;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Jupiter
	model.description =  "";
	model.id	   =  "Jupiter_sails";
	model.FaceId	= 384;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Edgar Allan Poe
	model.description =  "";
	model.id	   =  "Edgar Allan Poe";
	model.FaceId	= 541;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Edgar Allan Poe
	model.description =  "";
	model.id	   =  "Edgar Allan Poe_sack";
	model.FaceId	= 541;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Edgar Allan Poe
	model.description =  "";
	model.id	   =  "Poe_private";
	model.FaceId	= 541;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//medicine woman
	model.description =  "";
	model.id	   =  "medicine_woman";
	model.FaceId	= 542;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Auguste Dupin
	model.description =  "";
	model.id	   =  "Auguste Dupin";
	model.FaceId	= 543;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Axel von Fersen
	model.description =  "";
	model.id	   =  "Axel von Fersen";
	model.FaceId	= 545;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Lieutenant G
	model.description =  "";
	model.id	   =  "lieutenant_G";
	model.FaceId	= 40;
	model.nation	  =  BROKEN;		
	model.assigned	=  true;
	AddCharacterModel(model);

	//Moultrie hotel
	model.description =  "";
	model.id	   =  "Mou_12";
	model.FaceId	= 160;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Moultrie restaurant
	model.description =  "";
	model.id	   =  "Mou_19";
	model.FaceId	= 26;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	//Moultrie store
	model.description =  "";
	model.id	   =  "Mou_9";
	model.FaceId	= 548;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh1";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh2";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh3";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh4";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh5";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh6";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_USA_jrh7";
	model.FaceId	= 75;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Captain Kidd";
	model.FaceId	= 549;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "priest_inq";
	model.FaceId	= 551;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
	
	model.description =  "";
	model.id	   =  "inquisition_priest";
	model.FaceId	= 550;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "inquisition_monk1";
	model.FaceId	= 551;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "inquisition_monk2";
	model.FaceId	= 551;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "inquisition_monk3";
	model.FaceId	= 551;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "inquisition_monk4";
	model.FaceId	= 551;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animist_Elting";
	model.FaceId	= 552;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon1";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon2";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon3";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon4";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon5";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "maroon_girl";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "indian_bandit";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "hunter_bandit";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);


	model.description =  "";
	model.id	   =  "deserter_us1";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "deserter_us2";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "white_trash1";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "white_trash2";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "mystery_monk";
	model.FaceId	= 507;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Arthur Gordon Pym";
	model.FaceId	= 94;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);
	
	model.description =  "";
	model.id	   =  "Peter_Blood";
	model.FaceId	= 565;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "The outfit of a tall, blond, moustached and handsome Dutch corsair, if you please.";
	model.id	   =  "Laurens_de_Graaf";
	model.FaceId	= 566;
	model.nation	  =  HOLLAND;
	model.assigned	=  true;
	model.name = "Laurens";
	model.lastname = "de Graaf";
	model.storytitle = "Scourge of the West";
	model.storytext = "'A great and mischievous pirate' according to Henry Morgan and thought to be the Devil in person by some Spaniards, this Dutch corsair is ready to wreak havoc on the Caribbean!";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.ship = "PiratBrig50";
	model.shipname = "Wapen van Hoorn";
	model.Flags.Pirate = 3;
	model.Flags.Personal = 10;
	model.date.month = 10;
	model.date.year = 1682;
	AddCharacterModel(model);

	// PB: Piet Hein Character Addition Tutorial -->
	model.description	= "A Dutch admiral and privateer for the Dutch Republic during the Eighty Years' War. The first and the last to capture a large part of a Spanish treasure fleet from America.";
	model.id		= "Piet_Hein";
	model.FaceId		=  592;
	model.nation		=  HOLLAND;
	model.price		=  11509524;				// guilders of booty in gold, silver, and other expensive trade goods
	model.assigned		=  true;
	model.name		= "Piet";
	//model.middlename	= "Pieterszoon";
	model.lastname		= "Hein";
	model.storytitle	= "De Zilvervloot";			// http://www.goudenboekjes.nl/product/de-zilvervloot-piet-hein
	model.storytext		= "'We hebben een flinke reis voor de boeg. We gaan zout halen. In Afrika.' Dat is Piet's eerste kennismaking met de zee en het harde leven van de zeelieden. Jaren later krijgt Piet Hein een eigen schip. Wat zal hij doen? Nieuw land ontdekken? Handel drijven? Of... de Spaanse zilvervloot veroveren?";
	model.playertype	=  PLAYER_TYPE_CORSAIR;		// start with Letter of Marque/Kapersbrief
	model.difficulty	=  DIFFICULTY_LANDLUBBER;	// fun for the kids!
	model.ship		= "NL_NeptunusE";			// 
	model.shipname		= "Neptunus";				// in 1618, when he was captain of the Neptunus, both he and his ship were pressed into service by the Republic of Venice.
	model.Flags.Pirate	=     1;					// former PiratesAhoy! logo seems fitting
	model.Flags.Personal	=     9;					// flag of my dear 'ol Amsterdam
	model.date.day		=     8;					// my birthday
	model.date.month	=    10;					// because why not?
	model.date.year		=  1626;					// Smack-dab in the middle of The Spanish Main period
	AddCharacterModel(model);
	// PB: Piet Hein Character Addition Tutorial <--

	model.description	= "Where did he come from? Where will he go?  Where did he come from, Cotton-Eye - no, that can't be right...";
	model.id		= "DrakeStranton";
	model.FaceID		= 614;
	model.nation		= PIRATE;
	model.assigned		= true;
	model.name		= "Drake";
	model.lastname		= "Stranton";
	model.loadingScreen	= "Quest_StrantonFamily.tga";  // Nita+BJ+PB
	model.storytitle	= "Cursed Vengeance";
	model.storytext		= "Go on an adventure of treasure and betrayal, bloodshed and vengeance. A time when the pirate had the upper hand and got the girl, the treasure and conquered his enemies. What you may think about a pirate's life will be challenged to the extreme as they live, love, and die as only a pirate can! Based on the novel by Brent Jackson.";
	model.playertype	= PLAYER_TYPE_CORSAIR;
	model.ship		= "Brig_20_Gun1_181";
	model.shipname		= "Phantom";
	model.Flags.Pirate	= 5;
	model.Flags.Personal	= 37;
	model.date.day		= 10;
	model.date.month	= 12;
	model.date.year		= 1721;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie1";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie2";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie3";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie4";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie5";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "zombie6";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie1";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie2";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie3";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie4";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie5";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Skel_zombie6";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "Now take Sir Francis Drake, the Spanish all despised him. But to the British, he's a hero and they idolised him!";
	model.id	   =  "FrancisDrake";
	model.FaceId	= 211;
	model.nation      =  ENGLAND;
	model.assigned	=  true;
	model.name = "Francis";
	model.lastname = "Drake";
	model.storytitle = "Disturb us, Lord";
	model.storytext = "'It isn't that life ashore is distasteful to me. But life at sea is better.' As privateer in the service of queen Elizabeth I of England and with the Spanish owning nearly the entire Caribbean, it is your job to make life as difficult as possible for the Dons.";
	model.playertype = PLAYER_TYPE_CORSAIR;
	model.ship = "GoldenHind";
	model.shipname = "Golden Hind";
	model.Flags.Pirate = 8;
	model.Flags.Pirate = 33;
	model.Flags.Personal = 37;
	model.date.month = 9;
	model.date.year = 1578;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Offic_Swe_16";
	model.FaceId	= 390;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SWEDEN);
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe2_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe3_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe4_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe5_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe6_16";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_THE_SPANISH_MAIN;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Offic_Swe_18";
	model.FaceId	= 390;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SWEDEN);
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Offic_Swe2_18";
	model.FaceId	= 391;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Grenadier_Swe_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe2_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe3_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe4_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe5_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe6_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe7_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe8_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe9_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe10_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe11_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe12_18";
	model.FaceId	= 217;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe13_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Swe14_18";
	model.FaceId	= 217;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
	model.playertype  = PLAYER_TYPE_MILITARY;
	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
	AssignModelTypeNation(isstart, model, "Soldiers", 1.0, sti(model.nation));
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe2_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe3_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe4_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe5_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe6_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe7_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe8_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Gunner_Swe9_18";
	model.FaceId	= 391;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe_18";
	model.FaceId	= 390;
	model.minrank	 =  1;
	model.nation	  =  SWEDEN;
	model.assigned	=  true;
//	model.period = "" + PERIOD_GOLDEN_AGE_OF_PIRACY + PERIOD_COLONIAL_POWERS;
//	AssignModelTypeNation(isstart, model, "Land_Officers", 1.0, SWEDEN);
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe2_18";
	model.FaceId	= 390;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe3_18";
	model.FaceId	= 390;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe4_18";
	model.FaceId	= 390;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe5_18";
	model.FaceId	= 390;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Dragoon_Swe6_18";
	model.FaceId	= 390;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "french_surgeon1";
	model.FaceId	= 385;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "french_surgeon2";
	model.FaceId	= 385;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "french_surgeon3";
	model.FaceId	= 385;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "french_surgeon4";
	model.FaceId	= 385;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Malta2";
	model.FaceId	= 386;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "WhiteKnight";
	model.FaceId	= 387;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Soldier_Malta1";
	model.FaceId	= 388;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Maltese2";
	model.FaceId	= 24;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animist_Maltese";
	model.FaceId	= 389;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Louis_Arot";
	model.FaceId	= 132;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Cardinal";
	model.FaceId	= 145;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "postman";
	model.FaceId	= 392;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "offic_eng2_17";
	model.FaceId	= 99;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "devil";
	model.FaceId	= 402;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "conquistador";
	model.FaceId	= 544;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "SkelZ";
	model.FaceId	= 403;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Animists3_empty";
	model.FaceId	= 601;				//was 544
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Ron_L";
	model.FaceId	= 603;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "Reg_L";
	model.FaceId	= 604;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);

	model.description =  "";
	model.id	   =  "bouncer";
	model.FaceId	= 605;
	model.nation	  =  BROKEN;
	model.assigned	=  true;
	AddCharacterModel(model);



    //<-- JRH

	//The code below this comment HAVE TO be after all model definitions.
	//Please insert new models before this comment.
//	n--;
	// NK <--
//	int i;
//	Trace("----------PostSort--------------------------------------");
//	for(i = 0; i <= MODEL_HIGH; i++)
//	{
//	   Trace("Nation: " + i + " - "  + Models[i].nation + " - " + Models[i].model);
//	}
}

//MAXIMUS: -->
string GetPrisonersModels()
{
	string prList = "";
	for (int i=0; i<MODEL_HIGH; i++)
	{
		if (CheckAttribute(&Models[i], "isprisoner") == true && sti(Models[i].isprisoner) == true)
		{
			prList = StoreString(prList, Models[i].id);
		}
	}
	return prList;
}

string GetMansionModels()
{
	string prList = "";
	for (int i=0; i < MODEL_HIGH; i++)
	{
		if (CheckAttribute(&Models[i], "ismansion") == true && sti(Models[i].ismansion) == true)
		{
			prList = StoreString(prList, Models[i].id);
		}
	}
	return prList;
}

string GetBrothelModels()
{
	string prList = "";
	for (int i=0; i<MODEL_HIGH; i++)
	{
		if (CheckAttribute(&Models[i], "isbrothel") == true && sti(Models[i].isbrothel) == true)
		{
			prList = StoreString(prList, Models[i].id);
		}
	}
	return prList;
}
//MAXIMUS: <--

// modeltypes lookup array init
// do it this way rather than for loop, for speed.
void InitModelTypesArray()
{
	ClearModelTypeSlotDirect(0);
	ClearModelTypeSlotDirect(1);
	ClearModelTypeSlotDirect(2);
	ClearModelTypeSlotDirect(3);
	ClearModelTypeSlotDirect(4);
	ClearModelTypeSlotDirect(5);
	ClearModelTypeSlotDirect(6);
	ClearModelTypeSlotDirect(7);
	ClearModelTypeSlotDirect(8);
	ClearModelTypeSlotDirect(9);
	ClearModelTypeSlotDirect(10);
	ClearModelTypeSlotDirect(11);
	ClearModelTypeSlotDirect(12);
	ClearModelTypeSlotDirect(13);
	ClearModelTypeSlotDirect(14);
	ClearModelTypeSlotDirect(15);
	ClearModelTypeSlotDirect(16);
	ClearModelTypeSlotDirect(17);
	ClearModelTypeSlotDirect(18);
	ClearModelTypeSlotDirect(19);
	ClearModelTypeSlotDirect(20);
	ClearModelTypeSlotDirect(21);
	ClearModelTypeSlotDirect(22);
	ClearModelTypeSlotDirect(23);
	ClearModelTypeSlotDirect(24);
	ClearModelTypeSlotDirect(25);
	ClearModelTypeSlotDirect(26);
	ClearModelTypeSlotDirect(27);
	ClearModelTypeSlotDirect(28);
	ClearModelTypeSlotDirect(29);
	ClearModelTypeSlotDirect(30);
	ClearModelTypeSlotDirect(31);
	ClearModelTypeSlotDirect(32);
	ClearModelTypeSlotDirect(33);
	ClearModelTypeSlotDirect(34);
	ClearModelTypeSlotDirect(35);
	ClearModelTypeSlotDirect(36);
	ClearModelTypeSlotDirect(37);
	ClearModelTypeSlotDirect(38);
	ClearModelTypeSlotDirect(39);
	ClearModelTypeSlotDirect(40);
	ClearModelTypeSlotDirect(41);
	ClearModelTypeSlotDirect(42);
	ClearModelTypeSlotDirect(43);
	ClearModelTypeSlotDirect(44);
	ClearModelTypeSlotDirect(45);
	ClearModelTypeSlotDirect(46);
	ClearModelTypeSlotDirect(47);
	ClearModelTypeSlotDirect(48);
	ClearModelTypeSlotDirect(49);
	ClearModelTypeSlotDirect(50);
	ClearModelTypeSlotDirect(51);
	ClearModelTypeSlotDirect(52);
	ClearModelTypeSlotDirect(53);
	ClearModelTypeSlotDirect(54);
	ClearModelTypeSlotDirect(55);
	ClearModelTypeSlotDirect(56);
	ClearModelTypeSlotDirect(57);
	ClearModelTypeSlotDirect(58);
	ClearModelTypeSlotDirect(59);
	ClearModelTypeSlotDirect(60);
	ClearModelTypeSlotDirect(61);
	ClearModelTypeSlotDirect(62);
	ClearModelTypeSlotDirect(63);
	ClearModelTypeSlotDirect(64);
	ClearModelTypeSlotDirect(65);
	ClearModelTypeSlotDirect(66);
	ClearModelTypeSlotDirect(67);
	ClearModelTypeSlotDirect(68);
	ClearModelTypeSlotDirect(69);
	ClearModelTypeSlotDirect(70);
	ClearModelTypeSlotDirect(71);
	ClearModelTypeSlotDirect(72);
	ClearModelTypeSlotDirect(73);
	ClearModelTypeSlotDirect(74);
	ClearModelTypeSlotDirect(75);
	ClearModelTypeSlotDirect(76);
	ClearModelTypeSlotDirect(77);
	ClearModelTypeSlotDirect(78);
	ClearModelTypeSlotDirect(79);
	ClearModelTypeSlotDirect(80);
	ClearModelTypeSlotDirect(81);
	ClearModelTypeSlotDirect(82);
	ClearModelTypeSlotDirect(83);
	ClearModelTypeSlotDirect(84);
	ClearModelTypeSlotDirect(85);
	ClearModelTypeSlotDirect(86);
	ClearModelTypeSlotDirect(87);
	ClearModelTypeSlotDirect(88);
	ClearModelTypeSlotDirect(89);
	ClearModelTypeSlotDirect(90);
	ClearModelTypeSlotDirect(91);
	ClearModelTypeSlotDirect(92);
	ClearModelTypeSlotDirect(93);
	ClearModelTypeSlotDirect(94);
	ClearModelTypeSlotDirect(95);
	ClearModelTypeSlotDirect(96);
	ClearModelTypeSlotDirect(97);
	ClearModelTypeSlotDirect(98);
	ClearModelTypeSlotDirect(99);
	ClearModelTypeSlotDirect(100);
	ClearModelTypeSlotDirect(101);
	ClearModelTypeSlotDirect(102);
	ClearModelTypeSlotDirect(103);
	ClearModelTypeSlotDirect(104);
	ClearModelTypeSlotDirect(105);
	ClearModelTypeSlotDirect(106);
	ClearModelTypeSlotDirect(107);
	ClearModelTypeSlotDirect(108);
	ClearModelTypeSlotDirect(109);
	ClearModelTypeSlotDirect(110);
	ClearModelTypeSlotDirect(111);
	ClearModelTypeSlotDirect(112);
	ClearModelTypeSlotDirect(113);
	ClearModelTypeSlotDirect(114);
	ClearModelTypeSlotDirect(115);
	ClearModelTypeSlotDirect(116);
	ClearModelTypeSlotDirect(117);
	ClearModelTypeSlotDirect(118);
	ClearModelTypeSlotDirect(119);
	ClearModelTypeSlotDirect(120);
	ClearModelTypeSlotDirect(121);
	ClearModelTypeSlotDirect(122);
	ClearModelTypeSlotDirect(123);
	ClearModelTypeSlotDirect(124);
	ClearModelTypeSlotDirect(125);
	ClearModelTypeSlotDirect(126);
	ClearModelTypeSlotDirect(127);
	ClearModelTypeSlotDirect(128);
	ClearModelTypeSlotDirect(129);
	ClearModelTypeSlotDirect(130);
	ClearModelTypeSlotDirect(131);
	ClearModelTypeSlotDirect(132);
	ClearModelTypeSlotDirect(133);
	ClearModelTypeSlotDirect(134);
	ClearModelTypeSlotDirect(135);
	ClearModelTypeSlotDirect(136);
	ClearModelTypeSlotDirect(137);
	ClearModelTypeSlotDirect(138);
	ClearModelTypeSlotDirect(139);
	ClearModelTypeSlotDirect(140);
	ClearModelTypeSlotDirect(141);
	ClearModelTypeSlotDirect(142);
	ClearModelTypeSlotDirect(143);
	ClearModelTypeSlotDirect(144);
	ClearModelTypeSlotDirect(145);
	ClearModelTypeSlotDirect(146);
	ClearModelTypeSlotDirect(147);
	ClearModelTypeSlotDirect(148);
	ClearModelTypeSlotDirect(149);
	ClearModelTypeSlotDirect(150);
	ClearModelTypeSlotDirect(151);
	ClearModelTypeSlotDirect(152);
	ClearModelTypeSlotDirect(153);
	ClearModelTypeSlotDirect(154);
	ClearModelTypeSlotDirect(155);
	ClearModelTypeSlotDirect(156);
	ClearModelTypeSlotDirect(157);
	ClearModelTypeSlotDirect(158);
	ClearModelTypeSlotDirect(159);
	ClearModelTypeSlotDirect(160);
	ClearModelTypeSlotDirect(161);
	ClearModelTypeSlotDirect(162);
	ClearModelTypeSlotDirect(163);
	ClearModelTypeSlotDirect(164);
	ClearModelTypeSlotDirect(165);
	ClearModelTypeSlotDirect(166);
	ClearModelTypeSlotDirect(167);
	ClearModelTypeSlotDirect(168);
	ClearModelTypeSlotDirect(169);
	ClearModelTypeSlotDirect(170);
	ClearModelTypeSlotDirect(171);
	ClearModelTypeSlotDirect(172);
	ClearModelTypeSlotDirect(173);
	ClearModelTypeSlotDirect(174);
	ClearModelTypeSlotDirect(175);
	ClearModelTypeSlotDirect(176);
	ClearModelTypeSlotDirect(177);
	ClearModelTypeSlotDirect(178);
	ClearModelTypeSlotDirect(179);
	ClearModelTypeSlotDirect(180);
	ClearModelTypeSlotDirect(181);
	ClearModelTypeSlotDirect(182);
	ClearModelTypeSlotDirect(183);
	ClearModelTypeSlotDirect(184);
	ClearModelTypeSlotDirect(185);
	ClearModelTypeSlotDirect(186);
	ClearModelTypeSlotDirect(187);
	ClearModelTypeSlotDirect(188);
	ClearModelTypeSlotDirect(189);
	ClearModelTypeSlotDirect(190);
	ClearModelTypeSlotDirect(191);
	ClearModelTypeSlotDirect(192);
	ClearModelTypeSlotDirect(193);
	ClearModelTypeSlotDirect(194);
	ClearModelTypeSlotDirect(195);
	ClearModelTypeSlotDirect(196);
	ClearModelTypeSlotDirect(197);
	ClearModelTypeSlotDirect(198);
	ClearModelTypeSlotDirect(199);
	ClearModelTypeSlotDirect(200);
	ClearModelTypeSlotDirect(201);
	ClearModelTypeSlotDirect(202);
	ClearModelTypeSlotDirect(203);
	ClearModelTypeSlotDirect(204);
	ClearModelTypeSlotDirect(205);
	ClearModelTypeSlotDirect(206);
	ClearModelTypeSlotDirect(207);
	ClearModelTypeSlotDirect(208);
	ClearModelTypeSlotDirect(209);
	ClearModelTypeSlotDirect(210);
	ClearModelTypeSlotDirect(211);
	ClearModelTypeSlotDirect(212);
	ClearModelTypeSlotDirect(213);
	ClearModelTypeSlotDirect(214);
	ClearModelTypeSlotDirect(215);
	ClearModelTypeSlotDirect(216);
	ClearModelTypeSlotDirect(217);
	ClearModelTypeSlotDirect(218);
	ClearModelTypeSlotDirect(219);
	ClearModelTypeSlotDirect(220);
	ClearModelTypeSlotDirect(221);
	ClearModelTypeSlotDirect(222);
	ClearModelTypeSlotDirect(223);
	ClearModelTypeSlotDirect(224);
	ClearModelTypeSlotDirect(225);
	ClearModelTypeSlotDirect(226);
	ClearModelTypeSlotDirect(227);
	ClearModelTypeSlotDirect(228);
	ClearModelTypeSlotDirect(229);
	ClearModelTypeSlotDirect(230);
	ClearModelTypeSlotDirect(231);
	ClearModelTypeSlotDirect(232);
	ClearModelTypeSlotDirect(233);
	ClearModelTypeSlotDirect(234);
	ClearModelTypeSlotDirect(235);
	ClearModelTypeSlotDirect(236);
	ClearModelTypeSlotDirect(237);
	ClearModelTypeSlotDirect(238);
	ClearModelTypeSlotDirect(239);
	ClearModelTypeSlotDirect(240);
	ClearModelTypeSlotDirect(241);
	ClearModelTypeSlotDirect(242);
	ClearModelTypeSlotDirect(243);
	ClearModelTypeSlotDirect(244);
	ClearModelTypeSlotDirect(245);
	ClearModelTypeSlotDirect(246);
	ClearModelTypeSlotDirect(247);
	ClearModelTypeSlotDirect(248);
	ClearModelTypeSlotDirect(249);
	ClearModelTypeSlotDirect(250);
	ClearModelTypeSlotDirect(251);
	ClearModelTypeSlotDirect(252);
	ClearModelTypeSlotDirect(253);
	ClearModelTypeSlotDirect(254);
	ClearModelTypeSlotDirect(255);
	ClearModelTypeSlotDirect(256);
	ClearModelTypeSlotDirect(257);
	ClearModelTypeSlotDirect(258);
	ClearModelTypeSlotDirect(259);
	ClearModelTypeSlotDirect(260);
	ClearModelTypeSlotDirect(261);
	ClearModelTypeSlotDirect(262);
	ClearModelTypeSlotDirect(263);
	ClearModelTypeSlotDirect(264);
	ClearModelTypeSlotDirect(265);
	ClearModelTypeSlotDirect(266);
	ClearModelTypeSlotDirect(267);
	ClearModelTypeSlotDirect(268);
	ClearModelTypeSlotDirect(269);
	ClearModelTypeSlotDirect(270);
	ClearModelTypeSlotDirect(271);
	ClearModelTypeSlotDirect(272);
	ClearModelTypeSlotDirect(273);
	ClearModelTypeSlotDirect(274);
	ClearModelTypeSlotDirect(275);
	ClearModelTypeSlotDirect(276);
	ClearModelTypeSlotDirect(277);
	ClearModelTypeSlotDirect(278);
	ClearModelTypeSlotDirect(279);
	ClearModelTypeSlotDirect(280);
	ClearModelTypeSlotDirect(281);
	ClearModelTypeSlotDirect(282);
	ClearModelTypeSlotDirect(283);
	ClearModelTypeSlotDirect(284);
	ClearModelTypeSlotDirect(285);
	ClearModelTypeSlotDirect(286);
	ClearModelTypeSlotDirect(287);
	ClearModelTypeSlotDirect(288);
	ClearModelTypeSlotDirect(289);
	ClearModelTypeSlotDirect(290);
	ClearModelTypeSlotDirect(291);
	ClearModelTypeSlotDirect(292);
	ClearModelTypeSlotDirect(293);
	ClearModelTypeSlotDirect(294);
	ClearModelTypeSlotDirect(295);
	ClearModelTypeSlotDirect(296);
	ClearModelTypeSlotDirect(297);
	ClearModelTypeSlotDirect(298);
	ClearModelTypeSlotDirect(299);
	ClearModelTypeSlotDirect(300);
	ClearModelTypeSlotDirect(301);
	ClearModelTypeSlotDirect(302);
	ClearModelTypeSlotDirect(303);
	ClearModelTypeSlotDirect(304);
	ClearModelTypeSlotDirect(305);
	ClearModelTypeSlotDirect(306);
	ClearModelTypeSlotDirect(307);
	ClearModelTypeSlotDirect(308);
	ClearModelTypeSlotDirect(309);
	ClearModelTypeSlotDirect(310);
	ClearModelTypeSlotDirect(311);
	ClearModelTypeSlotDirect(312);
	ClearModelTypeSlotDirect(313);
	ClearModelTypeSlotDirect(314);
	ClearModelTypeSlotDirect(315);
	ClearModelTypeSlotDirect(316);
	ClearModelTypeSlotDirect(317);
	ClearModelTypeSlotDirect(318);
	ClearModelTypeSlotDirect(319);
	ClearModelTypeSlotDirect(320);
	ClearModelTypeSlotDirect(321);
	ClearModelTypeSlotDirect(322);
	ClearModelTypeSlotDirect(323);
	ClearModelTypeSlotDirect(324);
	ClearModelTypeSlotDirect(325);
	ClearModelTypeSlotDirect(326);
	ClearModelTypeSlotDirect(327);
	ClearModelTypeSlotDirect(328);
	ClearModelTypeSlotDirect(329);
	ClearModelTypeSlotDirect(330);
	ClearModelTypeSlotDirect(331);
	ClearModelTypeSlotDirect(332);
	ClearModelTypeSlotDirect(333);
	ClearModelTypeSlotDirect(334);
	ClearModelTypeSlotDirect(335);
	ClearModelTypeSlotDirect(336);
	ClearModelTypeSlotDirect(337);
	ClearModelTypeSlotDirect(338);
	ClearModelTypeSlotDirect(339);
	ClearModelTypeSlotDirect(340);
	ClearModelTypeSlotDirect(341);
	ClearModelTypeSlotDirect(342);
	ClearModelTypeSlotDirect(343);
	ClearModelTypeSlotDirect(344);
	ClearModelTypeSlotDirect(345);
	ClearModelTypeSlotDirect(346);
	ClearModelTypeSlotDirect(347);
	ClearModelTypeSlotDirect(348);
	ClearModelTypeSlotDirect(349);
	ClearModelTypeSlotDirect(350);
	ClearModelTypeSlotDirect(351);
	ClearModelTypeSlotDirect(352);
	ClearModelTypeSlotDirect(353);
	ClearModelTypeSlotDirect(354);
	ClearModelTypeSlotDirect(355);
	ClearModelTypeSlotDirect(356);
	ClearModelTypeSlotDirect(357);
	ClearModelTypeSlotDirect(358);
	ClearModelTypeSlotDirect(359);
	ClearModelTypeSlotDirect(360);
	ClearModelTypeSlotDirect(361);
	ClearModelTypeSlotDirect(362);
	ClearModelTypeSlotDirect(363);
	ClearModelTypeSlotDirect(364);
	ClearModelTypeSlotDirect(365);
	ClearModelTypeSlotDirect(366);
	ClearModelTypeSlotDirect(367);
	ClearModelTypeSlotDirect(368);
	ClearModelTypeSlotDirect(369);
	ClearModelTypeSlotDirect(370);
	ClearModelTypeSlotDirect(371);
	ClearModelTypeSlotDirect(372);
	ClearModelTypeSlotDirect(373);
	ClearModelTypeSlotDirect(374);
	ClearModelTypeSlotDirect(375);
	ClearModelTypeSlotDirect(376);
	ClearModelTypeSlotDirect(377);
	ClearModelTypeSlotDirect(378);
	ClearModelTypeSlotDirect(379);
	ClearModelTypeSlotDirect(380);
	ClearModelTypeSlotDirect(381);
	ClearModelTypeSlotDirect(382);
	ClearModelTypeSlotDirect(383);
	ClearModelTypeSlotDirect(384);
	ClearModelTypeSlotDirect(385);
	ClearModelTypeSlotDirect(386);
	ClearModelTypeSlotDirect(387);
	ClearModelTypeSlotDirect(388);
	ClearModelTypeSlotDirect(389);
	ClearModelTypeSlotDirect(390);
	ClearModelTypeSlotDirect(391);
	ClearModelTypeSlotDirect(392);
	ClearModelTypeSlotDirect(393);
	ClearModelTypeSlotDirect(394);
	ClearModelTypeSlotDirect(395);
	ClearModelTypeSlotDirect(396);
	ClearModelTypeSlotDirect(397);
	ClearModelTypeSlotDirect(398);
	ClearModelTypeSlotDirect(399);
	ClearModelTypeSlotDirect(400);
	ClearModelTypeSlotDirect(401);
	ClearModelTypeSlotDirect(402);
	ClearModelTypeSlotDirect(403);
	ClearModelTypeSlotDirect(404);
	ClearModelTypeSlotDirect(405);
	ClearModelTypeSlotDirect(406);
	ClearModelTypeSlotDirect(407);
	ClearModelTypeSlotDirect(408);
	ClearModelTypeSlotDirect(409);
	ClearModelTypeSlotDirect(410);
	ClearModelTypeSlotDirect(411);
	ClearModelTypeSlotDirect(412);
	ClearModelTypeSlotDirect(413);
	ClearModelTypeSlotDirect(414);
	ClearModelTypeSlotDirect(415);
	ClearModelTypeSlotDirect(416);
	ClearModelTypeSlotDirect(417);
	ClearModelTypeSlotDirect(418);
	ClearModelTypeSlotDirect(419);
	ClearModelTypeSlotDirect(420);
	ClearModelTypeSlotDirect(421);
	ClearModelTypeSlotDirect(422);
	ClearModelTypeSlotDirect(423);
	ClearModelTypeSlotDirect(424);
	ClearModelTypeSlotDirect(425);
	ClearModelTypeSlotDirect(426);
	ClearModelTypeSlotDirect(427);
	ClearModelTypeSlotDirect(428);
	ClearModelTypeSlotDirect(429);
	ClearModelTypeSlotDirect(430);
	ClearModelTypeSlotDirect(431);
	ClearModelTypeSlotDirect(432);
	ClearModelTypeSlotDirect(433);
	ClearModelTypeSlotDirect(434);
	ClearModelTypeSlotDirect(435);
	ClearModelTypeSlotDirect(436);
	ClearModelTypeSlotDirect(437);
	ClearModelTypeSlotDirect(438);
	ClearModelTypeSlotDirect(439);
	ClearModelTypeSlotDirect(440);
	ClearModelTypeSlotDirect(441);
	ClearModelTypeSlotDirect(442);
	ClearModelTypeSlotDirect(443);
	ClearModelTypeSlotDirect(444);
	ClearModelTypeSlotDirect(445);
	ClearModelTypeSlotDirect(446);
	ClearModelTypeSlotDirect(447);
	ClearModelTypeSlotDirect(448);
	ClearModelTypeSlotDirect(449);
	ClearModelTypeSlotDirect(450);
	ClearModelTypeSlotDirect(451);
	ClearModelTypeSlotDirect(452);
	ClearModelTypeSlotDirect(453);
	ClearModelTypeSlotDirect(454);
	ClearModelTypeSlotDirect(455);
	ClearModelTypeSlotDirect(456);
	ClearModelTypeSlotDirect(457);
	ClearModelTypeSlotDirect(458);
	ClearModelTypeSlotDirect(459);
	ClearModelTypeSlotDirect(460);
	ClearModelTypeSlotDirect(461);
	ClearModelTypeSlotDirect(462);
	ClearModelTypeSlotDirect(463);
	ClearModelTypeSlotDirect(464);
	ClearModelTypeSlotDirect(465);
	ClearModelTypeSlotDirect(466);
	ClearModelTypeSlotDirect(467);
	ClearModelTypeSlotDirect(468);
	ClearModelTypeSlotDirect(469);
	ClearModelTypeSlotDirect(470);
	ClearModelTypeSlotDirect(471);
	ClearModelTypeSlotDirect(472);
	ClearModelTypeSlotDirect(473);
	ClearModelTypeSlotDirect(474);
	ClearModelTypeSlotDirect(475);
	ClearModelTypeSlotDirect(476);
	ClearModelTypeSlotDirect(477);
	ClearModelTypeSlotDirect(478);
	ClearModelTypeSlotDirect(479);
	ClearModelTypeSlotDirect(480);
	ClearModelTypeSlotDirect(481);
	ClearModelTypeSlotDirect(482);
	ClearModelTypeSlotDirect(483);
	ClearModelTypeSlotDirect(484);
	ClearModelTypeSlotDirect(485);
	ClearModelTypeSlotDirect(486);
	ClearModelTypeSlotDirect(487);
	ClearModelTypeSlotDirect(488);
	ClearModelTypeSlotDirect(489);
	ClearModelTypeSlotDirect(490);
	ClearModelTypeSlotDirect(491);
	ClearModelTypeSlotDirect(492);
	ClearModelTypeSlotDirect(493);
	ClearModelTypeSlotDirect(494);
	ClearModelTypeSlotDirect(495);
	ClearModelTypeSlotDirect(496);
	ClearModelTypeSlotDirect(497);
	ClearModelTypeSlotDirect(498);
	ClearModelTypeSlotDirect(499);
	ClearModelTypeSlotDirect(500);
	ClearModelTypeSlotDirect(501);
	ClearModelTypeSlotDirect(502);
	ClearModelTypeSlotDirect(503);
	ClearModelTypeSlotDirect(504);
	ClearModelTypeSlotDirect(505);
	ClearModelTypeSlotDirect(506);
	ClearModelTypeSlotDirect(507);
	ClearModelTypeSlotDirect(508);
	ClearModelTypeSlotDirect(509);
	ClearModelTypeSlotDirect(510);
	ClearModelTypeSlotDirect(511);
	ClearModelTypeSlotDirect(512);
	ClearModelTypeSlotDirect(513);
	ClearModelTypeSlotDirect(514);
	ClearModelTypeSlotDirect(515);
	ClearModelTypeSlotDirect(516);
	ClearModelTypeSlotDirect(517);
	ClearModelTypeSlotDirect(518);
	ClearModelTypeSlotDirect(519);
	ClearModelTypeSlotDirect(520);
	ClearModelTypeSlotDirect(521);
	ClearModelTypeSlotDirect(522);
	ClearModelTypeSlotDirect(523);
	ClearModelTypeSlotDirect(524);
	ClearModelTypeSlotDirect(525);
	ClearModelTypeSlotDirect(526);
	ClearModelTypeSlotDirect(527);
	ClearModelTypeSlotDirect(528);
	ClearModelTypeSlotDirect(529);
	ClearModelTypeSlotDirect(530);
	ClearModelTypeSlotDirect(531);
	ClearModelTypeSlotDirect(532);
	ClearModelTypeSlotDirect(533);
	ClearModelTypeSlotDirect(534);
	ClearModelTypeSlotDirect(535);
	ClearModelTypeSlotDirect(536);
	ClearModelTypeSlotDirect(537);
	ClearModelTypeSlotDirect(538);
	ClearModelTypeSlotDirect(539);
	ClearModelTypeSlotDirect(540);
	ClearModelTypeSlotDirect(541);
	ClearModelTypeSlotDirect(542);
	ClearModelTypeSlotDirect(543);
	ClearModelTypeSlotDirect(544);
	ClearModelTypeSlotDirect(545);
	ClearModelTypeSlotDirect(546);
	ClearModelTypeSlotDirect(547);
	ClearModelTypeSlotDirect(548);
	ClearModelTypeSlotDirect(549);
	ClearModelTypeSlotDirect(550);
	ClearModelTypeSlotDirect(551);
	ClearModelTypeSlotDirect(552);
	ClearModelTypeSlotDirect(553);
	ClearModelTypeSlotDirect(554);
	ClearModelTypeSlotDirect(555);
	ClearModelTypeSlotDirect(556);
	ClearModelTypeSlotDirect(557);
	ClearModelTypeSlotDirect(558);
	ClearModelTypeSlotDirect(559);
	ClearModelTypeSlotDirect(560);
	ClearModelTypeSlotDirect(561);
	ClearModelTypeSlotDirect(562);
	ClearModelTypeSlotDirect(563);
	ClearModelTypeSlotDirect(564);
	ClearModelTypeSlotDirect(565);
	ClearModelTypeSlotDirect(566);
	ClearModelTypeSlotDirect(567);
	ClearModelTypeSlotDirect(568);
	ClearModelTypeSlotDirect(569);
	ClearModelTypeSlotDirect(570);
	ClearModelTypeSlotDirect(571);
	ClearModelTypeSlotDirect(572);
	ClearModelTypeSlotDirect(573);
	ClearModelTypeSlotDirect(574);
	ClearModelTypeSlotDirect(575);
	ClearModelTypeSlotDirect(576);
	ClearModelTypeSlotDirect(577);
	ClearModelTypeSlotDirect(578);
	ClearModelTypeSlotDirect(579);
	ClearModelTypeSlotDirect(580);
	ClearModelTypeSlotDirect(581);
	ClearModelTypeSlotDirect(582);
	ClearModelTypeSlotDirect(583);
	ClearModelTypeSlotDirect(584);
	ClearModelTypeSlotDirect(585);
	ClearModelTypeSlotDirect(586);
	ClearModelTypeSlotDirect(587);
	ClearModelTypeSlotDirect(588);
	ClearModelTypeSlotDirect(589);
	ClearModelTypeSlotDirect(590);
	ClearModelTypeSlotDirect(591);
	ClearModelTypeSlotDirect(592);
	ClearModelTypeSlotDirect(593);
	ClearModelTypeSlotDirect(594);
	ClearModelTypeSlotDirect(595);
	ClearModelTypeSlotDirect(596);
	ClearModelTypeSlotDirect(597);
	ClearModelTypeSlotDirect(598);
	ClearModelTypeSlotDirect(599);
	ClearModelTypeSlotDirect(600);
	ClearModelTypeSlotDirect(601);
	ClearModelTypeSlotDirect(602);
	ClearModelTypeSlotDirect(603);
	ClearModelTypeSlotDirect(604);
	ClearModelTypeSlotDirect(605);
	ClearModelTypeSlotDirect(606);
	ClearModelTypeSlotDirect(607);
	ClearModelTypeSlotDirect(608);
	ClearModelTypeSlotDirect(609);
	ClearModelTypeSlotDirect(610);
	ClearModelTypeSlotDirect(611);
	ClearModelTypeSlotDirect(612);
	ClearModelTypeSlotDirect(613);
	ClearModelTypeSlotDirect(614);
	ClearModelTypeSlotDirect(615);
	ClearModelTypeSlotDirect(616);
	ClearModelTypeSlotDirect(617);
	ClearModelTypeSlotDirect(618);
	ClearModelTypeSlotDirect(619);
	ClearModelTypeSlotDirect(620);
	ClearModelTypeSlotDirect(621);
	ClearModelTypeSlotDirect(622);
	ClearModelTypeSlotDirect(623);
	ClearModelTypeSlotDirect(624);
	ClearModelTypeSlotDirect(625);
	ClearModelTypeSlotDirect(626);
	ClearModelTypeSlotDirect(627);
	ClearModelTypeSlotDirect(628);
	ClearModelTypeSlotDirect(629);
	ClearModelTypeSlotDirect(630);
	ClearModelTypeSlotDirect(631);
	ClearModelTypeSlotDirect(632);
	ClearModelTypeSlotDirect(633);
	ClearModelTypeSlotDirect(634);
	ClearModelTypeSlotDirect(635);
	ClearModelTypeSlotDirect(636);
	ClearModelTypeSlotDirect(637);
	ClearModelTypeSlotDirect(638);
	ClearModelTypeSlotDirect(639);
	ClearModelTypeSlotDirect(640);
	ClearModelTypeSlotDirect(641);
	ClearModelTypeSlotDirect(642);
	ClearModelTypeSlotDirect(643);
	ClearModelTypeSlotDirect(644);
	ClearModelTypeSlotDirect(645);
	ClearModelTypeSlotDirect(646);
	ClearModelTypeSlotDirect(647);
	ClearModelTypeSlotDirect(648);
	ClearModelTypeSlotDirect(649);
	ClearModelTypeSlotDirect(650);
	ClearModelTypeSlotDirect(651);
	ClearModelTypeSlotDirect(652);
	ClearModelTypeSlotDirect(653);
	ClearModelTypeSlotDirect(654);
	ClearModelTypeSlotDirect(655);
	ClearModelTypeSlotDirect(656);
	ClearModelTypeSlotDirect(657);
	ClearModelTypeSlotDirect(658);
	ClearModelTypeSlotDirect(659);
	ClearModelTypeSlotDirect(660);
	ClearModelTypeSlotDirect(661);
	ClearModelTypeSlotDirect(662);
	ClearModelTypeSlotDirect(663);
	ClearModelTypeSlotDirect(664);
	ClearModelTypeSlotDirect(665);
	ClearModelTypeSlotDirect(666);
	ClearModelTypeSlotDirect(667);
	ClearModelTypeSlotDirect(668);
	ClearModelTypeSlotDirect(669);
	ClearModelTypeSlotDirect(670);
	ClearModelTypeSlotDirect(671);
	ClearModelTypeSlotDirect(672);
	ClearModelTypeSlotDirect(673);
	ClearModelTypeSlotDirect(674);
	ClearModelTypeSlotDirect(675);
	ClearModelTypeSlotDirect(676);
	ClearModelTypeSlotDirect(677);
	ClearModelTypeSlotDirect(678);
	ClearModelTypeSlotDirect(679);
	ClearModelTypeSlotDirect(680);
	ClearModelTypeSlotDirect(681);
	ClearModelTypeSlotDirect(682);
	ClearModelTypeSlotDirect(683);
	ClearModelTypeSlotDirect(684);
	ClearModelTypeSlotDirect(685);
	ClearModelTypeSlotDirect(686);
	ClearModelTypeSlotDirect(687);
	ClearModelTypeSlotDirect(688);
	ClearModelTypeSlotDirect(689);
	ClearModelTypeSlotDirect(690);
	ClearModelTypeSlotDirect(691);
	ClearModelTypeSlotDirect(692);
	ClearModelTypeSlotDirect(693);
	ClearModelTypeSlotDirect(694);
	ClearModelTypeSlotDirect(695);
	ClearModelTypeSlotDirect(696);
	ClearModelTypeSlotDirect(697);
	ClearModelTypeSlotDirect(698);
	ClearModelTypeSlotDirect(699);
	ClearModelTypeSlotDirect(700);
	ClearModelTypeSlotDirect(701);
	ClearModelTypeSlotDirect(702);
	ClearModelTypeSlotDirect(703);
	ClearModelTypeSlotDirect(704);
	ClearModelTypeSlotDirect(705);
	ClearModelTypeSlotDirect(706);
	ClearModelTypeSlotDirect(707);
	ClearModelTypeSlotDirect(708);
	ClearModelTypeSlotDirect(709);
	ClearModelTypeSlotDirect(710);
	ClearModelTypeSlotDirect(711);
	ClearModelTypeSlotDirect(712);
	ClearModelTypeSlotDirect(713);
	ClearModelTypeSlotDirect(714);
	ClearModelTypeSlotDirect(715);
	ClearModelTypeSlotDirect(716);
	ClearModelTypeSlotDirect(717);
	ClearModelTypeSlotDirect(718);
	ClearModelTypeSlotDirect(719);
	ClearModelTypeSlotDirect(720);
	ClearModelTypeSlotDirect(721);
	ClearModelTypeSlotDirect(722);
	ClearModelTypeSlotDirect(723);
	ClearModelTypeSlotDirect(724);
	ClearModelTypeSlotDirect(725);
	ClearModelTypeSlotDirect(726);
	ClearModelTypeSlotDirect(727);
	ClearModelTypeSlotDirect(728);
	ClearModelTypeSlotDirect(729);
	ClearModelTypeSlotDirect(730);
	ClearModelTypeSlotDirect(731);
	ClearModelTypeSlotDirect(732);
	ClearModelTypeSlotDirect(733);
	ClearModelTypeSlotDirect(734);
	ClearModelTypeSlotDirect(735);
	ClearModelTypeSlotDirect(736);
	ClearModelTypeSlotDirect(737);
	ClearModelTypeSlotDirect(738);
	ClearModelTypeSlotDirect(739);
	ClearModelTypeSlotDirect(740);
	ClearModelTypeSlotDirect(741);
	ClearModelTypeSlotDirect(742);
	ClearModelTypeSlotDirect(743);
	ClearModelTypeSlotDirect(744);
	ClearModelTypeSlotDirect(745);
	ClearModelTypeSlotDirect(746);
	ClearModelTypeSlotDirect(747);
	ClearModelTypeSlotDirect(748);
	ClearModelTypeSlotDirect(749);
	ClearModelTypeSlotDirect(750);
	ClearModelTypeSlotDirect(751);
	ClearModelTypeSlotDirect(752);
	ClearModelTypeSlotDirect(753);
	ClearModelTypeSlotDirect(754);
	ClearModelTypeSlotDirect(755);
	ClearModelTypeSlotDirect(756);
	ClearModelTypeSlotDirect(757);
	ClearModelTypeSlotDirect(758);
	ClearModelTypeSlotDirect(759);
	ClearModelTypeSlotDirect(760);
	ClearModelTypeSlotDirect(761);
	ClearModelTypeSlotDirect(762);
	ClearModelTypeSlotDirect(763);
	ClearModelTypeSlotDirect(764);
	ClearModelTypeSlotDirect(765);
	ClearModelTypeSlotDirect(766);
	ClearModelTypeSlotDirect(767);
	ClearModelTypeSlotDirect(768);
	ClearModelTypeSlotDirect(769);
	ClearModelTypeSlotDirect(770);
	ClearModelTypeSlotDirect(771);
	ClearModelTypeSlotDirect(772);
	ClearModelTypeSlotDirect(773);
	ClearModelTypeSlotDirect(774);
	ClearModelTypeSlotDirect(775);
	ClearModelTypeSlotDirect(776);
	ClearModelTypeSlotDirect(777);
	ClearModelTypeSlotDirect(778);
	ClearModelTypeSlotDirect(779);
	ClearModelTypeSlotDirect(780);
	ClearModelTypeSlotDirect(781);
	ClearModelTypeSlotDirect(782);
	ClearModelTypeSlotDirect(783);
	ClearModelTypeSlotDirect(784);
	ClearModelTypeSlotDirect(785);
	ClearModelTypeSlotDirect(786);
	ClearModelTypeSlotDirect(787);
	ClearModelTypeSlotDirect(788);
	ClearModelTypeSlotDirect(789);
	ClearModelTypeSlotDirect(790);
	ClearModelTypeSlotDirect(791);
	ClearModelTypeSlotDirect(792);
	ClearModelTypeSlotDirect(793);
	ClearModelTypeSlotDirect(794);
	ClearModelTypeSlotDirect(795);
	ClearModelTypeSlotDirect(796);
	ClearModelTypeSlotDirect(797);
	ClearModelTypeSlotDirect(798);
	ClearModelTypeSlotDirect(799);
	ClearModelTypeSlotDirect(800);
	ClearModelTypeSlotDirect(801);
	ClearModelTypeSlotDirect(802);
	ClearModelTypeSlotDirect(803);
	ClearModelTypeSlotDirect(804);
	ClearModelTypeSlotDirect(805);
	ClearModelTypeSlotDirect(806);
	ClearModelTypeSlotDirect(807);
	ClearModelTypeSlotDirect(808);
	ClearModelTypeSlotDirect(809);
	ClearModelTypeSlotDirect(810);
	ClearModelTypeSlotDirect(811);
	ClearModelTypeSlotDirect(812);
	ClearModelTypeSlotDirect(813);
	ClearModelTypeSlotDirect(814);
	ClearModelTypeSlotDirect(815);
	ClearModelTypeSlotDirect(816);
	ClearModelTypeSlotDirect(817);
	ClearModelTypeSlotDirect(818);
	ClearModelTypeSlotDirect(819);
	ClearModelTypeSlotDirect(820);
	ClearModelTypeSlotDirect(821);
	ClearModelTypeSlotDirect(822);
	ClearModelTypeSlotDirect(823);
	ClearModelTypeSlotDirect(824);
	ClearModelTypeSlotDirect(825);
	ClearModelTypeSlotDirect(826);
	ClearModelTypeSlotDirect(827);
	ClearModelTypeSlotDirect(828);
	ClearModelTypeSlotDirect(829);
	ClearModelTypeSlotDirect(830);
	ClearModelTypeSlotDirect(831);
	ClearModelTypeSlotDirect(832);
	ClearModelTypeSlotDirect(833);
	ClearModelTypeSlotDirect(834);
	ClearModelTypeSlotDirect(835);
	ClearModelTypeSlotDirect(836);
	ClearModelTypeSlotDirect(837);
	ClearModelTypeSlotDirect(838);
	ClearModelTypeSlotDirect(839);
	ClearModelTypeSlotDirect(840);
	ClearModelTypeSlotDirect(841);
	ClearModelTypeSlotDirect(842);
	ClearModelTypeSlotDirect(843);
	ClearModelTypeSlotDirect(844);
	ClearModelTypeSlotDirect(845);
	ClearModelTypeSlotDirect(846);
	ClearModelTypeSlotDirect(847);
	ClearModelTypeSlotDirect(848);
	ClearModelTypeSlotDirect(849);
	ClearModelTypeSlotDirect(850);
	ClearModelTypeSlotDirect(851);
	ClearModelTypeSlotDirect(852);
	ClearModelTypeSlotDirect(853);
	ClearModelTypeSlotDirect(854);
	ClearModelTypeSlotDirect(855);
	ClearModelTypeSlotDirect(856);
	ClearModelTypeSlotDirect(857);
	ClearModelTypeSlotDirect(858);
	ClearModelTypeSlotDirect(859);
	ClearModelTypeSlotDirect(860);
	ClearModelTypeSlotDirect(861);
	ClearModelTypeSlotDirect(862);
	ClearModelTypeSlotDirect(863);
	ClearModelTypeSlotDirect(864);
	ClearModelTypeSlotDirect(865);
	ClearModelTypeSlotDirect(866);
	ClearModelTypeSlotDirect(867);
	ClearModelTypeSlotDirect(868);
	ClearModelTypeSlotDirect(869);
	ClearModelTypeSlotDirect(870);
	ClearModelTypeSlotDirect(871);
	ClearModelTypeSlotDirect(872);
	ClearModelTypeSlotDirect(873);
	ClearModelTypeSlotDirect(874);
	ClearModelTypeSlotDirect(875);
	ClearModelTypeSlotDirect(876);
	ClearModelTypeSlotDirect(877);
	ClearModelTypeSlotDirect(878);
	ClearModelTypeSlotDirect(879);
	ClearModelTypeSlotDirect(880);
	ClearModelTypeSlotDirect(881);
	ClearModelTypeSlotDirect(882);
	ClearModelTypeSlotDirect(883);
	ClearModelTypeSlotDirect(884);
	ClearModelTypeSlotDirect(885);
	ClearModelTypeSlotDirect(886);
	ClearModelTypeSlotDirect(887);
	ClearModelTypeSlotDirect(888);
	ClearModelTypeSlotDirect(889);
	ClearModelTypeSlotDirect(890);
	ClearModelTypeSlotDirect(891);
	ClearModelTypeSlotDirect(892);
	ClearModelTypeSlotDirect(893);
	ClearModelTypeSlotDirect(894);
	ClearModelTypeSlotDirect(895);
	ClearModelTypeSlotDirect(896);
	ClearModelTypeSlotDirect(897);
	ClearModelTypeSlotDirect(898);
	ClearModelTypeSlotDirect(899);
	ClearModelTypeSlotDirect(900);
	ClearModelTypeSlotDirect(901);
	ClearModelTypeSlotDirect(902);
	ClearModelTypeSlotDirect(903);
	ClearModelTypeSlotDirect(904);
	ClearModelTypeSlotDirect(905);
	ClearModelTypeSlotDirect(906);
	ClearModelTypeSlotDirect(907);
	ClearModelTypeSlotDirect(908);
	ClearModelTypeSlotDirect(909);
	ClearModelTypeSlotDirect(910);
	ClearModelTypeSlotDirect(911);
	ClearModelTypeSlotDirect(912);
	ClearModelTypeSlotDirect(913);
	ClearModelTypeSlotDirect(914);
	ClearModelTypeSlotDirect(915);
	ClearModelTypeSlotDirect(916);
	ClearModelTypeSlotDirect(917);
	ClearModelTypeSlotDirect(918);
	ClearModelTypeSlotDirect(919);
	ClearModelTypeSlotDirect(920);
	ClearModelTypeSlotDirect(921);
	ClearModelTypeSlotDirect(922);
	ClearModelTypeSlotDirect(923);
	ClearModelTypeSlotDirect(924);
	ClearModelTypeSlotDirect(925);
	ClearModelTypeSlotDirect(926);
	ClearModelTypeSlotDirect(927);
	ClearModelTypeSlotDirect(928);
	ClearModelTypeSlotDirect(929);
	ClearModelTypeSlotDirect(930);
	ClearModelTypeSlotDirect(931);
	ClearModelTypeSlotDirect(932);
	ClearModelTypeSlotDirect(933);
	ClearModelTypeSlotDirect(934);
	ClearModelTypeSlotDirect(935);
	ClearModelTypeSlotDirect(936);
	ClearModelTypeSlotDirect(937);
	ClearModelTypeSlotDirect(938);
	ClearModelTypeSlotDirect(939);
	ClearModelTypeSlotDirect(940);
	ClearModelTypeSlotDirect(941);
	ClearModelTypeSlotDirect(942);
	ClearModelTypeSlotDirect(943);
	ClearModelTypeSlotDirect(944);
	ClearModelTypeSlotDirect(945);
	ClearModelTypeSlotDirect(946);
	ClearModelTypeSlotDirect(947);
	ClearModelTypeSlotDirect(948);
	ClearModelTypeSlotDirect(949);
	ClearModelTypeSlotDirect(950);
	ClearModelTypeSlotDirect(951);
	ClearModelTypeSlotDirect(952);
	ClearModelTypeSlotDirect(953);
	ClearModelTypeSlotDirect(954);
	ClearModelTypeSlotDirect(955);
	ClearModelTypeSlotDirect(956);
	ClearModelTypeSlotDirect(957);
	ClearModelTypeSlotDirect(958);
	ClearModelTypeSlotDirect(959);
	ClearModelTypeSlotDirect(960);
	ClearModelTypeSlotDirect(961);
	ClearModelTypeSlotDirect(962);
	ClearModelTypeSlotDirect(963);
	ClearModelTypeSlotDirect(964);
	ClearModelTypeSlotDirect(965);
	ClearModelTypeSlotDirect(966);
	ClearModelTypeSlotDirect(967);
	ClearModelTypeSlotDirect(968);
	ClearModelTypeSlotDirect(969);
	ClearModelTypeSlotDirect(970);
	ClearModelTypeSlotDirect(971);
	ClearModelTypeSlotDirect(972);
	ClearModelTypeSlotDirect(973);
	ClearModelTypeSlotDirect(974);
	ClearModelTypeSlotDirect(975);
	ClearModelTypeSlotDirect(976);
	ClearModelTypeSlotDirect(977);
	ClearModelTypeSlotDirect(978);
	ClearModelTypeSlotDirect(979);
	ClearModelTypeSlotDirect(980);
	ClearModelTypeSlotDirect(981);
	ClearModelTypeSlotDirect(982);
	ClearModelTypeSlotDirect(983);
	ClearModelTypeSlotDirect(984);
	ClearModelTypeSlotDirect(985);
	ClearModelTypeSlotDirect(986);
	ClearModelTypeSlotDirect(987);
	ClearModelTypeSlotDirect(988);
	ClearModelTypeSlotDirect(989);
	ClearModelTypeSlotDirect(990);
	ClearModelTypeSlotDirect(991);
	ClearModelTypeSlotDirect(992);
	ClearModelTypeSlotDirect(993);
	ClearModelTypeSlotDirect(994);
	ClearModelTypeSlotDirect(995);
	ClearModelTypeSlotDirect(996);
	ClearModelTypeSlotDirect(997);
	ClearModelTypeSlotDirect(998);
	ClearModelTypeSlotDirect(999);
	ClearModelTypeSlotDirect(1000);
	ClearModelTypeSlotDirect(1001);
	ClearModelTypeSlotDirect(1002);
	ClearModelTypeSlotDirect(1003);
	ClearModelTypeSlotDirect(1004);
	ClearModelTypeSlotDirect(1005);
	ClearModelTypeSlotDirect(1006);
	ClearModelTypeSlotDirect(1007);
	ClearModelTypeSlotDirect(1008);
	ClearModelTypeSlotDirect(1009);
	ClearModelTypeSlotDirect(1010);
	ClearModelTypeSlotDirect(1011);
	ClearModelTypeSlotDirect(1012);
	ClearModelTypeSlotDirect(1013);
	ClearModelTypeSlotDirect(1014);
	ClearModelTypeSlotDirect(1015);
	ClearModelTypeSlotDirect(1016);
	ClearModelTypeSlotDirect(1017);
	ClearModelTypeSlotDirect(1018);
	ClearModelTypeSlotDirect(1019);
	ClearModelTypeSlotDirect(1020);
	ClearModelTypeSlotDirect(1021);
	ClearModelTypeSlotDirect(1022);
	ClearModelTypeSlotDirect(1023);
}
