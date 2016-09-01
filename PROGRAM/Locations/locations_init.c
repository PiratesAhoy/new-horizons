extern void LocationInitShip(ref n);
extern void LocationInitBoarding(ref n);

void InitLocations()
{
	// NK rewrite this to check pchar attrib to see if we need to only init new locs. 05-07-15
	ref loc;
	int i, n;
	bool isstart = !CheckAttribute(GetMainCharacter(), "b12locsonly");
	DeleteAttribute(GetMainCharacter(), "b12locsonly");
	if(isstart)
	{
		for(i = 0; i < MAX_LOCATIONS; i++)
		{
			makeref(loc, Locations[i]);
			DeleteAttribute(loc, "");
			loc.id = "";
			loc.index = i;
			InitLocation(loc); // KK
		}

		ReloadProgressUpdate();

// KK -->
		//Init locations
		Locations[0].id = "none";
		n = 1;
		n = CreateGameLocations(n, "FalaiseDeFleur");		ReloadProgressUpdate();
		n = CreateGameLocations(n, "Redmond");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "IslaMuelle");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "Oxbay");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "QuebradasCostillas");	ReloadProgressUpdate();
		n = CreateGameLocations(n, "Douwesen");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Conceicao");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "KhaelRoa");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Cuba");					ReloadProgressUpdate();
		n = CreateGameLocations(n, "Hispaniola");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "Turks");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Cayman");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Guadeloupe");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "Antigua");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "SaintMartin");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "Curacao");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Eleuthera");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "Aruba");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "BattleRocks");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "IslaMona");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "Colombia");				ReloadProgressUpdate();
		n = CreateGameLocations(n, "IslaDeMuerte");			ReloadProgressUpdate();
		n = CreateGameLocations(n, "QuestLocations");		ReloadProgressUpdate();
		n = CreateGameLocations(n, "SideQuestLocations");	ReloadProgressUpdate(); // PB: Sidequests in other storylines

		Locations[0].IslandsList.Ship.begin = n;
		if (LoadSegment("Locations\init\Ship.c")) {
			LocationInitShip(&n);
			UnloadSegment("Locations\init\Ship.c");
		}
		Locations[0].IslandsList.Ship.end = n;
		ReloadProgressUpdate();
		Locations[0].IslandsList.Boarding.begin = n;
		if (LoadSegment("Locations\init\Boarding.c")) {
			LocationInitBoarding(&n);
			UnloadSegment("Locations\init\Boarding.c");
		}
		Locations[0].IslandsList.Boarding.end = n;
		ReloadProgressUpdate();
// <-- KK
	} else {
		n = nLocationsNum;
	} // NK

	// RobC/Alan_Smithee Blacksmiths -->
	n = CreateGameLocations(n, "AlanSmitheeLocations"); ReloadProgressUpdate();
	// <-- ditto

	n = CreateGameLocations(n, "CCCLocations"); ReloadProgressUpdate();
	n = CreateGameLocations(n, "CCCRandomLocations"); ReloadProgressUpdate();

	ReloadProgressUpdate(); // KK

	// Inez Dias -->
	n = LocationInitModLocations(n);
	// Inez Dias <--

	nLocationsNum = n;
	Trace("Number of locations: " + nLocationsNum);
	// NK add tailor shops here. 04-11-3
	// unneeded now that they are in loc inits themselves. 05-07-15
	/*CreateTailorsShop( "Oxbay", "Oxbay_town", "l20", "Oxbay_HouseInsideR9", "reload9", "back\oxss_");
        CreateTailorsShop( "Greenford", "Greenford_town", "l14", "Greenford_InsideHouseR28", "reload28", "back\grmh9_");
        CreateTailorsShop( "Redmond", "Redmond_town_04", "l8", "Redmond_HouseInsideR6", "door_6", "back\redmh4_");
        CreateTailorsShop( "Douwesen", "Douwesen_town", "l10", "Douwesen_HouseInsideR18", "reload18", "back\doulf1_");
        CreateTailorsShop( "Pirate Fort", "Pirate_Fort", "l4", "Douwesen_Pirate_HouseInsideR2", "reload2", "back\pifsh_");
        CreateTailorsShop( "Conceicao", "Conceicao_town", "l13", "Conceicao_HouseInsideR16", "reload16", "back\comh4_");
        CreateTailorsShop( "Isla Muelle", "Muelle_town_01", "l25", "Muelle_InsideHouseR26", "reload26", "back\mumh9_");
        CreateTailorsShop( "Falaise de Fleur", "Falaise_de_fleur_location_04", "l4", "Falause_de_fleur_InsideHouseR21", "locator21", "back\fflf1_");*/
		// NK <--

}

// Inez Dias -->
extern int InitModLocations();
object LocDirectory;

int LocationInitModLocations(int n)
{
	DeleteAttribute(&LocDirectory, "");

	ref pc = GetMainCharacter(); // KK
	LocDirectory.dir = "Program\\Locations\\init\\mods";
	LocDirectory.mask = "*.c";
	CreateEntity(&LocDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocDirectory);
	aref arList;
	makearef(arList, LocDirectory.filelist);
	for(int i = 0; i < GetAttributesNum(arList); i++)
	{
		aref arCur = GetAttributeN(arList, i);
		string fname = GetAttributeValue(arCur);
		string fullname = "locations\\init\\mods\\"+fname;  
		if(LoadSegment(fullname))
		{
			pc.numlocations = n; //Hack because we can't pass parameters to extern functions
			n = InitModLocations();
			DeleteAttribute(pc, "numlocations"); 
			UnloadSegment(fullname);
		}
		else
		{
			Log_SetStringToLog("There's an error in the location init code in" + " " + fname);
		}
	}
	return n; // KK 
}
// Inez Dias <--


// KK -->
void InitLocation(ref loc)
{
	if (!CheckAttribute(loc, "image")) loc.image = "sea.tga";
	if (!CheckAttribute(loc, "music")) loc.music = "enplav.ogg";
	if (!CheckAttribute(loc, "locators_radius.monsters")) loc.locators_radius.monsters = 0.6;	// ccc Nov05 Greater Oxbay
	if (!CheckAttribute(loc, "locators_radius.reload")) loc.locators_radius.reload = 1.0;
	if (!CheckAttribute(loc, "locators_radius.rld")) loc.locators_radius.rld = 1.0;
	if (!CheckAttribute(loc, "locators_radius.camdetector")) loc.locators_radius.camdetector = 1.0;
	if (!CheckAttribute(loc, "locators_radius.camera")) loc.locators_radius.camera = 0.3;
	if (!CheckAttribute(loc, "locators_radius.characters")) loc.locators_radius.characters = 0.5;
	if (!CheckAttribute(loc, "locators_radius.goto")) loc.locators_radius.goto = 0.5;
	if (!CheckAttribute(loc, "locators_radius.sit")) loc.locators_radius.sit = 0.5;
	if (!CheckAttribute(loc, "locators_radius.item")) loc.locators_radius.item = 0.5;
	if (!CheckAttribute(loc, "locators_radius.officers")) loc.locators_radius.officers = 0.5;
	if (!CheckAttribute(loc, "locators_radius.merchant")) loc.locators_radius.merchant = 1.0;
	if (!CheckAttribute(loc, "locators_radius.box")) loc.locators_radius.box = 1.0;
	if (!CheckAttribute(loc, "locators_radius.candles")) loc.locators_radius.candles = 0.1;
	if (!CheckAttribute(loc, "locators_radius.candles_p")) loc.locators_radius.candles_p = 0.1;		//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.candles_medium")) loc.locators_radius.candles_medium = 0.2;
	if (!CheckAttribute(loc, "locators_radius.chandeliers")) loc.locators_radius.chandeliers = 0.5;
	if (!CheckAttribute(loc, "locators_radius.heaters")) loc.locators_radius.heaters = 1.0;
	if (!CheckAttribute(loc, "locators_radius.torchlightes")) loc.locators_radius.torchlightes = 0.3;
	if (!CheckAttribute(loc, "locators_radius.torchlightes_o")) loc.locators_radius.torchlightes_o = 0.3;
	if (!CheckAttribute(loc, "locators_radius.torchlightes_p")) loc.locators_radius.torchlightes_p = 0.3;	//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.fonar")) loc.locators_radius.fonar = 0.4;
	if (!CheckAttribute(loc, "locators_radius.outside")) loc.locators_radius.outside = 2.0;
	if (!CheckAttribute(loc, "locators_radius.incas_light")) loc.locators_radius.incas_light = 0.8;
	if (!CheckAttribute(loc, "locators_radius.incas_sky")) loc.locators_radius.incas_sky = 1.0;
	if (!CheckAttribute(loc, "locators_radius.randitem")) loc.locators_radius.randitem = 1.5;
	if (!CheckAttribute(loc, "locators_radius.waitress")) loc.locators_radius.waitress = 1.0;
	if (!CheckAttribute(loc, "locators_radius.tables")) loc.locators_radius.tables = 0.5;
	if (!CheckAttribute(loc, "locators_radius.barmen")) loc.locators_radius.barmen = 1.0;
	if (!CheckAttribute(loc, "locators_radius.lamp")) loc.locators_radius.lamp = 0.2;
	if (!CheckAttribute(loc, "locators_radius.blueteleport")) loc.locators_radius.blueteleport = 0.2;
	if (!CheckAttribute(loc, "locators_radius.redteleport")) loc.locators_radius.redteleport = 0.2;
	if (!CheckAttribute(loc, "locators_radius.greenteleport")) loc.locators_radius.greenteleport = 0.2;
	if (!CheckAttribute(loc, "locators_radius.magsteleport")) loc.locators_radius.magsteleport = 0.2;
	if (!CheckAttribute(loc, "locators_radius.EncDetector")) loc.locators_radius.EncDetector = 8.0;
	if (!CheckAttribute(loc, "locators_radius.teleport")) loc.locators_radius.teleport = 1.0;
	if (!CheckAttribute(loc, "locators_radius.quest")) loc.locators_radius.quest = 0.5;			//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.quest_locator")) loc.locators_radius.quest_locator = 0.5;	//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.quest_lines")) loc.locators_radius.quest_lines = 0.5;		//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.quest_ships")) loc.locators_radius.quest_ships = 1.0;		//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.quest_ships_other")) loc.locators_radius.ships_other = 1.0;	//JRH for testing
	if (!CheckAttribute(loc, "locators_radius.patrol")) loc.locators_radius.patrol = 0.5;		//JRH

	//Day dynamic light
	if (!CheckAttribute(loc, "models.day.lights.candles")) loc.models.day.lights.candles = "candle";
	if (!CheckAttribute(loc, "models.day.lights.candles_medium")) loc.models.day.lights.candles_medium = "candelabrum";
	if (!CheckAttribute(loc, "models.day.lights.chandeliers")) loc.models.day.lights.chandeliers = "chandelier";
	if (!CheckAttribute(loc, "models.day.lights.heaters")) loc.models.day.lights.heaters = "heater";
	if (!CheckAttribute(loc, "models.day.lights.torchlightes")) loc.models.day.lights.torchlightes = "torchlight";		
	if (!CheckAttribute(loc, "models.day.lights.outside")) loc.models.day.lights.outside = "outside_day";
	if (!CheckAttribute(loc, "models.day.lights.incas_light")) loc.models.day.lights.incas_light = "incas";
	if (!CheckAttribute(loc, "models.day.lights.incas_sky")) loc.models.day.lights.incas_sky = "incasskyday";
	if (!CheckAttribute(loc, "models.day.lights.lamp")) loc.models.day.lights.lamp = "lamp";
	if (!CheckAttribute(loc, "models.day.lights.blueteleport")) loc.models.day.lights.blueteleport = "blueteleport";
	if (!CheckAttribute(loc, "models.day.lights.redteleport")) loc.models.day.lights.redteleport = "redteleport";
	if (!CheckAttribute(loc, "models.day.lights.greenteleport")) loc.models.day.lights.greenteleport = "greenteleport";
	if (!CheckAttribute(loc, "models.day.lights.magsteleport")) loc.models.day.lights.magsteleport = "magsteleport";

	//Night dynamic light
	if (!CheckAttribute(loc, "models.night.lights.candles")) loc.models.night.lights.candles = "candle";
	if (!CheckAttribute(loc, "models.night.lights.candles_medium")) loc.models.night.lights.candles_medium = "candelabrum";
	if (!CheckAttribute(loc, "models.night.lights.chandeliers")) loc.models.night.lights.chandeliers = "chandelier";
	if (!CheckAttribute(loc, "models.night.lights.heaters")) loc.models.night.lights.heaters = "heater";
	if (!CheckAttribute(loc, "models.night.lights.torchlightes")) loc.models.night.lights.torchlightes = "torchlight";
	if (!CheckAttribute(loc, "models.night.lights.torchlightes_o")) loc.models.night.lights.torchlightes_o = "torchlight";
	if (!CheckAttribute(loc, "models.night.lights.fonar")) loc.models.night.lights.fonar = "lamp";
	if (!CheckAttribute(loc, "models.night.lights.outside")) loc.models.night.lights.outside = "outside_night";		
	if (!CheckAttribute(loc, "models.night.lights.incas_light")) loc.models.night.lights.incas_light = "incas";
	if (!CheckAttribute(loc, "models.night.lights.incas_sky")) loc.models.night.lights.incas_sky = "incasskynight";
	if (!CheckAttribute(loc, "models.night.lights.lamp")) loc.models.night.lights.lamp = "lamp";
	if (!CheckAttribute(loc, "models.night.lights.blueteleport")) loc.models.night.lights.blueteleport = "blueteleport";
	if (!CheckAttribute(loc, "models.night.lights.redteleport")) loc.models.night.lights.redteleport = "redteleport";
	if (!CheckAttribute(loc, "models.night.lights.greenteleport")) loc.models.night.lights.greenteleport = "greenteleport";
	if (!CheckAttribute(loc, "models.night.lights.magsteleport")) loc.models.night.lights.magsteleport = "magsteleport";
}

int CreateGameLocations(int n, string name)
{
	string sl = GetStorylinePath(FindCurrentStoryline());
	string fname = name + ".c";
	string func = "LocationInit" + name;
	Locations[0].IslandsList.(name).begin = n;
	if (FindFile("PROGRAM\Locations\init", "*.c", fname) != "") {
		if (LoadSegment("Locations\init\" + fname)) {
			call func(&n);
			UnloadSegment("Locations\init\" + fname);
		}
	}
	if (FindFile("PROGRAM\" + sl + "Locations\init", "*.c", fname) != "") {
		if (LoadSegment(sl + "Locations\init\" + fname)) {
			call func(&n);
			UnloadSegment(sl + "Locations\init\" + fname);
		}
	}
	Locations[0].IslandsList.(name).end = n;
	return n;
}

void AddGameLocation(ref n, ref loc)
{
	if (!CheckAttribute(loc, "id")) return;
	int locidx = FindLocation(loc.id);
	ref location;
	if (locidx >= 0) {
		makeref(location, Locations[locidx]);
	} else {
		makeref(location, Locations[n]);
		locidx = n;
		n++;
	}
	DeleteAttribute(location, "");
	CopyAttributes(location, loc);
	location.index = locidx;
	InitLocation(location);
	DeleteAttribute(loc, "");
}
// <-- KK
