// DEFINES
#define MUSIC_CHANGE_TIME	3000
#define MUSIC_SILENCE_TIME	135	// silent time between music in seconds - changed from float milliseconds to int seconds - 14Feb09
#define SOUNDS_FADE_TIME	200

// KK -->
object registered_music_schemes;
int music_scheme = 0;
// <-- KK

#event_handler ("LoadSceneSound", "LoadSceneSound")
// PLAY
int Play3DSound(string name, float x, float y, float z)
{
	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, false, 0, x, y, z);
}

int Play3DSoundCached(string name, float x, float y, float z)
{
	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, true, 0, x, y, z);
}

int Play3DSoundComplex(string name, float x, float y, float z, bool bLooped, bool bCached)
{
	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, bLooped, bCached, 0, x, y, z);
}

int PlayStereoSound(string name)
{
	InitSound();
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, Sound_GetName(name), SOUND_WAV_STEREO, VOLUME_FX, false, false, false);
}

int PlayStereoSoundLooped(string name)
{
	InitSound();
	return SendMessage(Sound,"lsllll",MSG_SOUND_PLAY, Sound_GetName(name), SOUND_WAV_STEREO, VOLUME_FX, false, true, false);
}

int PlayStereoSoundLooped_JustCache(string name)
{
	InitSound();
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, Sound_GetName(name), SOUND_WAV_STEREO, VOLUME_FX, true, true, false);
}

int PlayStereoOGG(string name)
{
	//if(PGMUS && HasSubStr(name,"pgmus")) name = name + "_PGMUS"; // NK so PGMUS doesn't require two ini files. 04-09-17. 04-11-03 fixed.
	// redo musicscheme detection 05-04-29
	// KK if(!HasSubStr(name, GetMusicScheme())) name += GetMusicScheme();
	// NK <--
	InitSound();
// KK -->
	if (!CheckAttribute(Music_Alias, name)) return -1;
	aref MusicRef; makearef(MusicRef, Music_Alias.(name));
	int num = GetAttributesNum(MusicRef);
	string lnode = "f" + (rand(num - 1) + 1);
	string music_name = MusicRef.(lnode).name;
	// LDH this should be VOLUME_MUSIC but since it's used to alert the player we'll leave it at VOLUME_FX in case music is turned off
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, music_name, SOUND_MP3_STEREO, VOLUME_FX, false, false, false);
// <-- KK
}
//MAXIMUS -->
void PlayLocatorSound(ref loc, string group, string name, string snd, float up)
{
	if(group=="" || name=="" || snd=="") return;
	if(FindLoadedLocation()==-1) return;
	if(!CheckAttribute(loc,"locators."+group+"."+name)) return;

	float x, y, z;
	x = stf(loc.locators.(group).(name).x);
	y = stf(loc.locators.(group).(name).y)+up;
	z = stf(loc.locators.(group).(name).z);
	Play3DSound(snd, x, y, z);
}
//MAXIMUS <--
// OTHER METHODS
void StopSound(int id,int fade)
{
	InitSound();
	//Trace("StopSound : "+id);
	SendMessage(Sound,"lll",MSG_SOUND_STOP,id,fade);
}

void ResumeSound(int id,int fade)
{
	InitSound();
	//Trace("ResumeSound : "+id);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME,id,fade);
}

void ReleaseSound(int id)
{
	InitSound();
	//Trace("ReleaseSound : "+id);
	SendMessage(Sound,"ll",MSG_SOUND_RELEASE,id);
}

// SOUND SCHEMES
void ResetSoundScheme()
{
	InitSound();
	//Trace("ResetSoundScheme");
	SendMessage(Sound,"l",MSG_SOUND_SCHEME_RESET);
}

void SetSoundScheme(string schemeName)
{
	InitSound();
	//Trace("SetSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_SET,schemeName);
}

void AddSoundScheme(string schemeName)
{
	InitSound();
	//Trace("AddSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_ADD,schemeName);
}

void SetWeatherScheme(string scheme)
{
	if (Whr_IsStorm())
	{
		AddSoundScheme(scheme+"_storm");
		PlayStereoSoundLooped("rain_storm");
	}
	else
	{
		if (Whr_IsRain())
		{
			AddSoundScheme(scheme+"_rain");
			PlayStereoSoundLooped("rain");
		}
		else
		{
			AddSoundScheme(scheme);
		}
	}
}

void SetTimeScheme(string scheme)
{
	if (Whr_IsNight())
	{
		AddSoundScheme(scheme+"_night");
	}
	else
	{
		AddSoundScheme(scheme+"_day");
	}
}

void SetSchemeForLocation(ref loc)
{
	//GO <---
	int rainSoundID;
	int windSoundID;
	int waterSoundID;
	int water2SoundID;
	int shipSoundID;
	int ship2SoundID;
	//GO --->

	if(CheckAttribute(loc,"type"))
	{
		ResetSoundScheme();
		int logined = 0;
		if(LAi_numloginedcharacters>1)
		{
			for(int login=0; login<LAi_numloginedcharacters; login++)
			{
				if(LAi_loginedcharacters[login]<0 || GetMainCharacterIndex()==LAi_loginedcharacters[login]) continue;
				if(!IsOfficer(GetCharacter(LAi_loginedcharacters[login]))) { logined++; }
			}
		}
		switch (loc.type)
		{
		case "port":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			//a simple virtual sailor change -->
			int location_or_nation;
			if(CheckAttribute(loc,"townsack"))
				location_or_nation=GettownNation(loc.townsack);
			else
				location_or_nation=GetLocationNation(loc);
// KK -->
			switch(location_or_nation) {
				case ENGLAND: SetMusicAlarm("music_eng_town"); break;
				case FRANCE: SetMusicAlarm("music_fra_town"); break;
				case SPAIN: SetMusicAlarm("music_spa_town"); break;
				case PIRATE: SetMusicAlarm("music_pir_town"); break;
				case HOLLAND: SetMusicAlarm("music_hol_town"); break;
				case PORTUGAL: SetMusicAlarm("music_por_town"); break;
				case GUEST1_NATION: // DeathDaisy: added swedish music
					if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
						SetMusicAlarm("music_swe_town"); 
					} else{	SetMusicAlarm("music_usa_town"); }
				break;
				case PERSONAL_NATION:	SetMusicAlarm("music_personal_town"); 
							if(HasSubStr(loc.id,"Kristiania"  )) SetMusicAlarm("Rogers_gunroom"); 	//JRH for Spanish part of Kristiania
				break; // DeathDaisy: added music for personal colonies
			}
// <-- KK
			//a simple virtual sailor change <--
			break;
		case "town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			//a simple virtual sailor change -->
			if(CheckAttribute(loc,"townsack"))
				location_or_nation=GettownNation(loc.townsack);
			else
				location_or_nation=GetLocationNation(loc);
// KK -->
			switch(location_or_nation)
			{
				case ENGLAND:  SetMusicAlarm("music_eng_town"); break;
				case FRANCE:   SetMusicAlarm("music_fra_town"); break;
				case SPAIN:    SetMusicAlarm("music_spa_town"); break;
				case PIRATE:   SetMusicAlarm("music_pir_town"); break;
				case HOLLAND:  SetMusicAlarm("music_hol_town"); break;
				case PORTUGAL: SetMusicAlarm("music_por_town"); break;
				case GUEST1_NATION: // DeathDaisy: added swedish music
					if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
						SetMusicAlarm("music_swe_town"); 
					} else{	SetMusicAlarm("music_usa_town"); }
				break;
				//case AMERICA:  SetMusicAlarm("music_usa_town"); break;
				case PERSONAL_NATION:
					//SetMusicAlarm("music_eng_town");										//placeholder, doesn't work without it
					SetMusicAlarm("music_personal_town"); // DeathDaisy: added music for personal colonies
					if(HasSubStr(loc.id,"Nueva_Suecia")) SetMusicAlarm("Rogers_gunroom"); 	//JRH for Spanish part of Kristiania
					if(HasSubStr(loc.id,"Kristiania"  )) SetMusicAlarm("music_swe_town"); 	//JRH for Swedish part of Kristiania
				break;
			}
// <-- KK
			//a simple virtual sailor change <--
			break;
		case "canyon":					// LDH added 11Apr09
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_jungle");
			break;
		case "jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_jungle");
			break;
		case "KR_jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_indian");
			break;
// KK -->
		case "den":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			if(CheckAttribute(loc,"id") && loc.id == "GB_Charleston_opium")
			{
				SetMusicAlarm("blue_cavern");	//JRH
			}
			else SetMusicAlarm("music_pir_town");
			break;
// <-- KK
		case "KhaelRoa":
			SetSoundScheme("cave");
			SetMusicAlarm("music_coridor");
			break;
		case "seashore"://changed by MAXIMUS -[for some locations, such as QC]->
			if(CheckAttribute(loc,"townsack")) location_or_nation = GettownNation(loc.townsack);
			else location_or_nation = -1;
			if(location_or_nation==PIRATE)
			{
				SetSoundScheme("port");
				SetTimeScheme("land");
				SetWeatherScheme("seashore_weather");
				SetMusicAlarm("music_pir_town");
			}
			else
			{
				ResetSoundScheme();
				SetTimeScheme("land");
				SetWeatherScheme("seashore_weather");
				SetMusicAlarm("music_jungle");
			}
			break;//changed by MAXIMUS <-[for some locations, such as QC]-
		case "seashore_jungle":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("music_jungle");
			break;//JRH for Turks Fort
		case "cave":
			SetSoundScheme("cave");
			SetMusicAlarm("music_coridor");
			break;
		case "inca_temple":
			SetSoundScheme("inca_temple");
			SetMusicAlarm("music_coridor");
			break;
		case "house":
			SetSoundScheme("house");
			SetMusicAlarm("music_house");
			break;
		case "tavern":
			//a simple virtual sailor change -->
			SetSoundScheme("tavern");
			if (CheckAttribute(loc,"townsack"))
				location_or_nation=GettownNation(loc.townsack);
			else
				location_or_nation=GetLocationNation(loc);
// KK -->
			switch (location_or_nation) {
				case ENGLAND: SetMusicAlarm("music_tavern"); break;
				case FRANCE: SetMusicAlarm("music_tavern"); break;
				case SPAIN: SetMusicAlarm("music_tavern"); break;
				case PIRATE: SetMusicAlarm("music_tavern_pirate"); break;
				case HOLLAND: SetMusicAlarm("music_tavern"); break;
				case PORTUGAL: SetMusicAlarm("music_tavern"); break;
				case GUEST1_NATION: SetMusicAlarm("music_tavern"); break;
				case PERSONAL_NATION: SetMusicAlarm("music_tavern_personal"); break;
			}
// <-- KK
			//a simple virtual sailor change <--
// JRH -->
			if(CheckAttribute(loc,"id") && loc.id == "GB_Charleston_town_tavern") SetMusicAlarm("Rogers_gunroom");
			if(CheckAttribute(loc,"id") && loc.id == "GB_Charleston_port_tavern") SetMusicAlarm("music_tavern_pirate");
			if(CheckAttribute(loc,"id") && loc.id == "NS_hidden_town_Tavern") SetMusicAlarm("Rogers_crew");
// <-- JRH
			break;
// Levis: Casino -->			
		case "casino":
			SetSoundScheme("tavern");
			SetMusicAlarm("music_casino");
			break;
// Levis: Casino <---
		case "shop":
			SetSoundScheme("shop");
			SetMusicAlarm("music_shop");
			break;
// JRH -->
		case "indian_shop":
			SetSoundScheme("shop");
			SetMusicAlarm("indian_theme");
			break;
// <-- JRH
		case "residence":
			SetSoundScheme("residence");
			//a simple virtual sailor change -->
			if(CheckAttribute(loc,"townsack"))
				location_or_nation=GettownNation(loc.townsack);
			else
				location_or_nation=GetLocationNation(loc);
// KK -->
			switch(location_or_nation) {
				case ENGLAND: SetMusicAlarm("music_english_governor"); break;//changed by MAXIMUS -->
				case FRANCE: SetMusicAlarm("music_french_governor"); break;
				case SPAIN: SetMusicAlarm("music_spanish_governor"); break;
				case PIRATE: SetMusicAlarm("music_pirate_governor"); break;
				case HOLLAND: SetMusicAlarm("music_dutch_governor"); break;
				case PORTUGAL: SetMusicAlarm("music_portugal_governor"); break;//changed by MAXIMUS <--
				case GUEST1_NATION: // DeathDaisy: added swedish music
					if(GetCurrentPeriod() > PERIOD_EARLY_EXPLORERS && GetCurrentPeriod() < PERIOD_REVOLUTIONS){
							SetMusicAlarm("music_swedish_governor"); 
					} else{	SetMusicAlarm("music_american_governor"); }
				break;
				//case AMERICA: SetMusicAlarm("music_american_governor"); break;
				case PERSONAL_NATION:	SetMusicAlarm("music_personal_governor"); break; // DeathDaisy: added music for personal governor
			}
			//SetMusicAlarm("music_gubernator");
// <-- KK
			//a simple virtual sailor change <--
			break;
		case "church":
			SetSoundScheme("church");
			SetMusicAlarm("music_church");
			break;
//JRH -->
		case "Turks_church":
			SetSoundScheme("Pym_tower");
			SetMusicAlarm("music_Turks_church");
			break;

		case "Kristiania_church":
			SetSoundScheme("church");
			SetMusicAlarm("Vane_temple");
			break;
//<-- JRH
		case "jail":
			SetSoundScheme("jail");
			SetMusicAlarm("music_dungeon");
//			PlayStereoSoundLooped("AMBIENT\JAIL\JailAmb.wav");		// LDH removed, messes up all sound in jail - 11Apr09
			break;
		case "deck":
			SetSoundScheme("deck");
			SetMusicAlarm("music_abordage");		// LDH was "music_house" - 10Apr09
			break;
		case "dungeon":				//ccc -->
			SetSoundScheme("music_dungeon");
			SetMusicAlarm("music_dungeon");
			break;
			// ccc <--

//JRH -->
		case "brothel_QC":
			SetSoundScheme("brothel_QC");
			SetMusicAlarm("music_brothel_QC");
			break;
		case "brothel_room_QC":
			SetSoundScheme("house");
			SetMusicAlarm("music_brothel_room_QC");
			break;
		case "brothel_shop":
			SetSoundScheme("shop");
			SetMusicAlarm("music_brothel_shop");
			break;
		case "silent_town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "repair_town":
			SetSoundScheme("repair_town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_house");
			break;
		case "silent_repair_town":
			SetSoundScheme("repair_town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "blues_town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_blues");
			break;
		case "blues_port":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("music_blues");
			break;
		case "silent_jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "very_silent_jungle":
		//	SetSoundScheme("jungle");		//no birds etc
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "repair_house":
			SetSoundScheme("repair_house");
			SetMusicAlarm("Rogers_neutral");
			break;
		case "jungle_pirates":
			SetSoundScheme("jungle_pirates");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "Rogers_residence":
			SetSoundScheme("residence");
			SetMusicAlarm("Rogers_residence");
			break;
		case "Rogers_private":
			SetSoundScheme("house");
			SetMusicAlarm("Rogers_private");
			break;
		case "Rogers_corridor":
			SetSoundScheme("cave2");
			SetMusicAlarm("Rogers_private");
			break;
		case "Rogers_shop":
			SetSoundScheme("shop");
			SetMusicAlarm("Rogers_shop");
			break;
		case "Rogers_study":
			SetSoundScheme("residence");
			SetMusicAlarm("Rogers_study");
			break;
		case "Rogers_cellar":
			SetSoundScheme("shop");
			SetMusicAlarm("Rogers_cellar");
			break;
		case "Rogers_repair_residence":
			SetSoundScheme("repair_house");
			SetMusicAlarm("Rogers_residence");
			break;
		case "Rogers_crew":
			SetSoundScheme("tavern");
			SetMusicAlarm("Rogers_crew");
			break;
		case "Rogers_gunroom":
			SetSoundScheme("tavern");
			SetMusicAlarm("Rogers_gunroom");
			break;
		case "Rogers_neutral":
			//quiet music for non-Roger's rooms
			SetSoundScheme("house");
			SetMusicAlarm("Rogers_neutral");
			break;
		case "silent_shipyard":
			//used in QC shipyard berore brothel_shop music
			SetSoundScheme("silent_shipyard");
			SetMusicAlarm("silence");
			break;
		case "silent_loghouse":
			//used in Loghouse
			SetSoundScheme("silent_loghouse");
			SetMusicAlarm("silence");
			break;
		case "Rogers_jail":
			SetSoundScheme("jail");
			SetMusicAlarm("Rogers_cellar");
			break;
		case "Rogers_mine":
			SetSoundScheme("inca_temple");
			SetMusicAlarm("Rogers_mine");
			break;
		case "Blackbeard_house":
			SetSoundScheme("house");
			SetMusicAlarm("Blackbeard_scene");
			break;
		case "Blackbeard_party":
			SetSoundScheme("tavern");
			SetMusicAlarm("Blackbeard_scene");
			break;
		case "Blackbeard_shore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Blackbeard_scene");
			break;
		case "Hornblower_port":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Hornblower_start");
			break;
		case "Haggman_sings":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Sharpe_verse8");
			break;
		case "Ardent_cabin":
			SetSoundScheme("deck");
			SetMusicAlarm("Ardent_start");
			break;
		case "Ardent_finale_town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Ardent_end");
			break;
		case "Ardent_finale_sea":
			SetSoundScheme("deck");
			SetMusicAlarm("Ardent_end");
			break;
		case "Murphy_house":
			SetSoundScheme("residence");
			SetMusicAlarm("murphy_tribute");
			break;
        case "San_Felipe_fort":
	        ResetSoundScheme();
	        SetTimeScheme("land");
	        SetWeatherScheme("seashore_weather");
	        SetMusicAlarm("San_Felipe_scene");
	        break;
		case "blue_cavern":
			SetSoundScheme("cave2");
			SetMusicAlarm("blue_cavern");
			break;
		case "silent_cave_seashore":
			//used in swamp_grot
			SetSoundScheme("cave_seashore");
			SetMusicAlarm("silence");
			break;
		case "Vane_jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Vane_outside");
			break;
		case "Vane_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Vane_outside");
			break;
		case "Vane_church":
			SetSoundScheme("shop");
			SetMusicAlarm("Vane_church");
			break;
		case "Vane_church_tavern":
			SetSoundScheme("tavern");
			SetMusicAlarm("Vane_church");
			break;
		case "Vane_chapel":
			SetSoundScheme("shop");
			SetMusicAlarm("Vane_chapel");
			break;
		case "Vane_temple":
			SetSoundScheme("cave2");
			SetMusicAlarm("Vane_temple");
			break;
		case "Vane_silent_temple":
			SetSoundScheme("cave2");
			SetMusicAlarm("silence");
			break;
		case "Vane_towers":
			SetSoundScheme("shop");
			SetMusicAlarm("Vane_towers");
			break;
		case "Claire_house":
			SetSoundScheme("house");
			SetMusicAlarm("Claire_theme");
			break;
		case "Claire_outside":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("distant_seashore");	
			SetMusicAlarm("Claire_theme");
			break;
		case "Defoe_cabin":
			SetSoundScheme("house");
			SetMusicAlarm("Defoe_theme");
			break;
		case "party":
			SetSoundScheme("tavern");
			SetMusicAlarm("silence");
			break;
		case "crypt":
			SetSoundScheme("crypt");
			SetMusicAlarm("silence");
			break;
		case "military":
			SetSoundScheme("residence");
			SetMusicAlarm("military");
			break;
		case "prison_ships":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("prison_ships");
			break;
		case "indian_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("indian_theme");
			break;
		case "rush_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("rush_seashore");
			break;
		case "attack_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("attack_seashore");
			break;
		case "silent_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			break;
		case "silent_distant_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("distant_seashore");
			break;
		case "silent_cabin":
			SetSoundScheme("below_deck");
			SetMusicAlarm("silence");
			break;
		case "silent_deck":
			SetSoundScheme("below_deck");
			SetMusicAlarm("silence");
			SetWeatherScheme("distant_seashore");
			break;
		case "silent_sneaking_deck":
			SetSoundScheme("below_deck");
			SetMusicAlarm("night_sneaking");
			SetWeatherScheme("distant_seashore");
			break;
		case "Rogers_ships":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Rogers_ships");
			break;
		case "galleon_open":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Rogers_galleon");
			break;
		case "corvette_closed":
			SetSoundScheme("shop");
			SetMusicAlarm("Rogers_corvette");
			break;
		case "galleon_closed":
			SetSoundScheme("shop");
			SetMusicAlarm("Rogers_galleon");
			break;
		case "choir":
			SetSoundScheme("shop");
			SetMusicAlarm("choir");
			break;
		case "angels_choir":
			SetSoundScheme("silent_location");
			SetMusicAlarm("choir");
			break;
		case "Estate_sneaking":
			SetSoundScheme("house");
			SetMusicAlarm("night_sneaking");
			break;
		case "Swe_inside":
			SetSoundScheme("shop");
			SetMusicAlarm("Swe_inside");
			break;
		case "burning_cave":
			SetSoundScheme("crypt2");
			SetMusicAlarm("burning_cave");
			break;
		case "silent_burning_cave":
			SetSoundScheme("crypt2");
			SetMusicAlarm("silence");
			break;
	// GOLDBUG -->
	
		case "Charleston_port":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Charleston_port");
			break;
		case "Sullivan_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Sullivan_seashore");
			break;
		case "Sullivan_jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Sullivan_jungle");
			break;
		case "Legrands_house":
			SetSoundScheme("house");
			SetMusicAlarm("Legrands_house");
			break;
		case "Fort_Moultrie":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Fort_Moultrie");
			break;
		case "Fort_Moultrie_barracks":
			SetSoundScheme("tavern");
			SetMusicAlarm("Fort_Moultrie_barracks");
			break;
		case "Fort_Moultrie_village":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Fort_Moultrie_village");
			break;
		case "Fort_Moultrie_inside":
			SetSoundScheme("house");
			SetMusicAlarm("Fort_Moultrie_village");
			break;
		case "Empty_Moultrie_village":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "Moultrie_restaurant":
			SetSoundScheme("tavern");
			SetMusicAlarm("Charleston_brothel");
			break;
		case "indian_jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("indian_theme");
			break;
		case "Charleston_town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			if(Whr_IsStorm() || Whr_IsRain())
			{
				SetMusicAlarm("silence");
			}
			else 
			{ 
				SetMusicAlarm("Charleston_town");
			}
			break;
	/*	case "Charleston_brothel":
			SetSoundScheme("brothel_QC");
			SetMusicAlarm("Charleston_brothel");
			break;	*/
		case "silent_repair":
			SetSoundScheme("repair_house");
			SetMusicAlarm("silence");
			break;
		case "Plantation":
			if (Whr_IsNight())
			{
				SetSoundScheme("jungle");
			}
			else 
			{
				SetSoundScheme("town");
			}
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Plantation");
			break;
		case "night_sneaking":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("night_sneaking");
			break;
		case "deserted_seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("Rogers_mine");
			break;
		case "deserted_mountains":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Rogers_mine");
			break;
		case "Chinese_garden":
			if(Whr_IsStorm() || Whr_IsRain())
			{
				ResetSoundScheme();
			}
			else 
			{
				if (Whr_IsNight())
				{
					SetSoundScheme("town");
				}
				else 
				{
					SetSoundScheme("Chinese_garden");
				}
			}
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "Cloister_garden":
			if(Whr_IsStorm() || Whr_IsRain())
			{
				ResetSoundScheme();
			}
			else 
			{
				if (Whr_IsNight())
				{
					SetSoundScheme("jungle");
				}
				else 
				{
					SetSoundScheme("Cloister_garden");
				}
			}
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("silence");
			break;
		case "Estate_garden":
			if(Whr_IsStorm() || Whr_IsRain())
			{
				ResetSoundScheme();
			}
			else 
			{
				if (Whr_IsNight())
				{
					SetSoundScheme("town");
				}
				else 
				{
					SetSoundScheme("Chinese_garden");
				}
			}
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("Rogers_study");
			break;
		case "Chinese_restaurant":
			SetSoundScheme("tavern");
			SetMusicAlarm("Chinese_restaurant");
			break;
		case "silent_residence":
			SetSoundScheme("residence");
			SetMusicAlarm("silence");
			break;
		case "Pym_tower":
			SetSoundScheme("Pym_tower");
			SetMusicAlarm("silence");
			break;
		case "Poe_home":
			SetSoundScheme("residence");
			SetMusicAlarm("Poe_home");
			break;

	// <-- GOLDBUG
	// DEVLIN -->
		case "OP_celtic":
			SetSoundScheme("cave");
			SetMusicAlarm("OP_celtic");
			break;
		case "OP_road":
			SetSoundScheme("jungle");
			SetMusicAlarm("OP_road");
			break;
		case "OP_village":
			SetSoundScheme("jungle");
			SetMusicAlarm("OP_village");
			break;
		case "OP_wood":
			SetSoundScheme("jungle");
			SetMusicAlarm("OP_wood");
			break;
                case "yohoho_tavern":
                        SetSoundScheme("tavern");
                        SetMusicAlarm("music_yohoho");
                        break;
	//<-- DEVLIN
	// CARTAGENA -->
		case "inquisition":
			SetSoundScheme("inquisition");
			SetMusicAlarm("silence");
			break;
	//<-- CARTAGENA
// JRH <--

// added by MAXIMUS -->
		case "brothel":
			SetSoundScheme("brothel");
			if(CheckAttribute(loc,"id") && loc.id == "GB_Charleston_brothel1")
			{
				SetSoundScheme("brothel_QC");
				SetMusicAlarm("Charleston_brothel");	//JRH
			}
			else
			{ 
				SetMusicAlarm("music_brothel_QC");

				switch(GetAttribute(loc,"id"))
				{
					case "QC_brothel":		// brothel looks like a tavern, crowded, this is where people go for a good time
						PlayStereoSoundLooped("AMBIENT\BROTHEL\razg_001.wav");
						PlayStereoSoundLooped("AMBIENT\BROTHEL\razg_002.wav");
						PlayStereoSoundLooped("AMBIENT\BROTHEL\razg_004.wav");
						PlayStereoSoundLooped("AMBIENT\BROTHEL\Brothel_00" + (rand(3)+1) + ".wav");
					break;

					case "Charlestown_Brothel":	// quiet, everyone who wants a party is round at Pirate Settlement
						PlayStereoSoundLooped("brothel_talks");
						PlayStereoSoundLooped("brothel");
					break;

					// Everywhere else: somewhere in between
					PlayStereoSoundLooped("AMBIENT\BROTHEL\razg_00" + (rand(3)+1) + ".wav");
					PlayStereoSoundLooped("AMBIENT\BROTHEL\Brothel_00" + (rand(3)+1) + ".wav");
				}
			}
			break;
		case "brothel_room":
			SetSoundScheme("room");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\muhi_001.wav");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\vorkovanie_001.wav");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\vorkovanie_002.wav");
			break;
		case "opium_room":
			SetSoundScheme("room");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\muhi_001.wav");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\muhi_002.wav");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\muhi_003.wav");
			PlayStereoSoundLooped("AMBIENT\BROTHEL\silent_talks.wav");
			break;
		case "treasure_cave":
			SetSoundScheme("cave");
			SetMusicAlarm("music_treasure_cave");
			break;
		case "own_deck":
			SetSoundScheme("own_deck");
			if(Whr_IsStorm())
			{
			    if(HasSubStr(loc.id,"ShipDeck"))
				{
					rainSoundID = PlayStereoSoundLooped_JustCache("rain_storm");
					SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
					SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
				}
			    windSoundID = PlayStereoSoundLooped_JustCache("water_sea_storm");
			    SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, windSoundID, 0.45);
			    SendMessage(Sound,"lll",MSG_SOUND_RESUME, windSoundID, 0);
			}
			else
			{
			    if(Whr_IsRain())
			    {
			        if(HasSubStr(loc.id,"ShipDeck"))
					{
						rainSoundID = PlayStereoSoundLooped("rain");
						SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
						SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
					}
			        waterSoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, waterSoundID, 0.6);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, waterSoundID, 0);
			    }
			    else
			    {
			        water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.35);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
			    }
			}
			if(HasSubStr(loc.id,"ShipDeck"))
			{
				if(bSeaActive && !bCanEnterToLand)
				{
					shipSoundID = PlayStereoSoundLooped_JustCache("squeak_sea");
					SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, shipSoundID, 0.45);
					SendMessage(Sound,"lll",MSG_SOUND_RESUME, shipSoundID, 0);

					ship2SoundID = PlayStereoSoundLooped_JustCache("sails_ambient");
					SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, ship2SoundID, 0.45);
					SendMessage(Sound,"lll",MSG_SOUND_RESUME, ship2SoundID, 0);
				}
				if(bCanEnterToLand)
				{
					shipSoundID = PlayStereoSoundLooped_JustCache("squeak_sea");
					SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, shipSoundID, 0.35);
					SendMessage(Sound,"lll",MSG_SOUND_RESUME, shipSoundID, 0);

					if(!Whr_IsStorm() && !Whr_IsRain() && !Whr_IsNight())
					{
						ship2SoundID = PlayStereoSoundLooped_JustCache("NATURE\seagulls2.wav");
						SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, ship2SoundID, 0.45);
						SendMessage(Sound,"lll",MSG_SOUND_RESUME, ship2SoundID, 0);
					}
				}
			}
			if(Whr_IsNight())		SetMusicAlarm("music_night_sailing");
			else
			{
				if(Whr_IsFog())		SetMusicAlarm("music_fog_sailing");
				else				SetMusicAlarm("music_day_sailing");
			}
			break;
		case "ship":
			SetSoundScheme("ship");
			if(Whr_IsStorm())
			{
				if(HasSubStr(loc.id,"ShipDeck"))
				{
					rainSoundID = PlayStereoSoundLooped_JustCache("rain_storm");
					SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
					SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
				}
			    windSoundID = PlayStereoSoundLooped_JustCache("water_sea_storm");
			    SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, windSoundID, 0.45);
			    SendMessage(Sound,"lll",MSG_SOUND_RESUME, windSoundID, 0);
			}
			else
			{
			    if(Whr_IsRain())
			    {
			        if(HasSubStr(loc.id,"ShipDeck"))
					{
						rainSoundID = PlayStereoSoundLooped("rain");
						SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
						SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
					}
			        waterSoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, waterSoundID, 0.6);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, waterSoundID, 0);
			    }
			    else
			    {
			        water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.35);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
			    }
			}
			if(HasSubStr(loc.id,"ShipDeck")) break;
			if(Whr_IsNight()) SetMusicAlarm("music_night_sailing");
			else
			{
			    if(logined>=2)
				{
					PlayStereoSoundLooped("shipyard");
				}
				if(Whr_IsFog())		SetMusicAlarm("music_fog_sailing");
				else				SetMusicAlarm("music_day_sailing");
			}
			break;
		case "crew":
			if(!Whr_IsNight() && logined>=2) SetSoundScheme("tavern");
			else SetSoundScheme("crew");
			if (Whr_IsStorm())
			{
			    windSoundID = PlayStereoSoundLooped_JustCache("water_sea_storm");
			    SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, windSoundID, 0.45);
			    SendMessage(Sound,"lll",MSG_SOUND_RESUME, windSoundID, 0);
			}
			else
			{
			    if (Whr_IsRain())
			    {
			        waterSoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, waterSoundID, 0.6);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, waterSoundID, 0);
			    }
			    else
			    {
			        water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
			        SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.35);
			        SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
			    }
			}
			if(Whr_IsNight())		SetMusicAlarm("music_night_sailing");
			else
			{
				if(Whr_IsFog())		SetMusicAlarm("music_fog_sailing");
				else				SetMusicAlarm("music_day_sailing");
			}
			break;
// added by MAXIMUS <--
		}
	}
	if(!CheckAttribute(loc,"soundskip")) SetStaticSounds(loc);// MAXIMUS: strange, but StaticSounds not works in AOP locations. I'm wondering - all was OK with these locations
}

void SetStaticSounds(ref loc)
{
	if(!IsEntity(loc)) return;
	if(!CheckAttribute(loc, "locators.sound")) return;

	aref locatorGroup; makearef(locatorGroup, loc.locators.sound);
	int locatorCount = GetAttributesNum(locatorGroup);
	if(locatorCount <= 0) return;

	for(int i=0; i<locatorCount; i++)
	{
		aref locator = GetAttributeN(locatorGroup, i);
		string locatorName = GetAttributeName(locator);
		string LocatorType = locatorName;
		while (isDigit(locatorType, strLen(locatorType)-1)) locatorType = strLeft(locatorType, strLen(locatorType)-1);	// LDH 19Mar09
//TraceAndLog("SetStaticSounds: locatorName = " + locatorName + ", locatorType = " + locatorType);	// LDH test 26Mar09
		if (locatorType=="tree") continue;	// LDH we don't have a tree sound defined - 19Mar09
		SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, locatorType, SOUND_WAV_3D, VOLUME_FX, false, true, true, 0, stf(locator.x), stf(locator.y), stf(locator.z));//MAXIMUS
	}
}

// LDH no longer used, music set in SetSchemeForLocation() - 10Apr09
void SetSchemeForAbordage()
{
	return;		// bypass the function
	ResetSoundScheme();
	SetMusic("music_abordage"); // KK
	ResumeAllSounds();
}

void SetSchemeForSea()
{
	ResetSoundScheme();

	AddSoundScheme("sea");
	if (Whr_IsStorm())
	{
		AddSoundScheme("sea_weather_storm");
		int rainSoundID = PlayStereoSoundLooped_JustCache("rain_storm");
		SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
		int windSoundID = PlayStereoSoundLooped_JustCache("water_sea_storm");
		SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, windSoundID, 0.45);
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, windSoundID, 0);
		SetMusic("music_storm");
	}
	else
	{
		// LDH to get night sailing music when you're sailing - 20Jan09
		// if we're not using night music, use this line instead of the section below
//		SetMusic("music_day_sailing");

		// LDH set night music properly - 11Feb09
		ref pchar = GetMainCharacter();
		bool musicdone = false;
		// PB & GR: check for attributes for custom music at sea
		if (CheckAttribute(PChar, "seabattlemusic") && sti(pchar.Ship.POS.Mode) == SHIP_WAR)
		{
			SetMusic(PChar.seabattlemusic);
			musicdone = true;
		}
		if (CheckAttribute(PChar, "seamusic") && sti(pchar.Ship.POS.Mode) != SHIP_WAR)
		{
			SetMusicAlarm(PChar.seamusic);
			musicdone = true;
		}
		if (!musicdone)
		{
			// LDH 30Mar09
			if (sti(pchar.Ship.POS.Mode) == SHIP_WAR) // PB: !bMapEnter doesn't have the same effect
				SetMusic("music_sea_battle");
			else
			{
				if(Whr_IsNight())		SetMusicAlarm("music_night_sailing");
				else
				{
					if(Whr_IsFog())		SetMusicAlarm("music_fog_sailing");
						else				SetMusicAlarm("music_day_sailing");
				}
			}
		}

		if (Whr_IsRain())
		{
			AddSoundScheme("sea_weather_rain");
			PlayStereoSoundLooped("rain");
			int waterSoundID = PlayStereoSoundLooped_JustCache("water_sea");
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, waterSoundID, 0.6);
			SendMessage(Sound,"lll",MSG_SOUND_RESUME, waterSoundID, 0);
		}
		else
		{
			AddSoundScheme("sea_weather");
			int water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.35);
			SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
		}
	}
	ResumeAllSounds();
}

void SetSchemeForMap()
{
	ResetSoundScheme();
	AddSoundScheme("sea_map");
	SetMusic("music_map");
	ResumeAllSounds();

	int water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
	SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.05);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
}

// MUSIC
int musicID = 0;
int oldMusicID = 0;
string musicName = "";
string oldMusicName = "";
// NK 04-09-09
// to set music with no pause in music
void SetMusicNoPause(string name)
{
	//bugfix 04-12-11 was not handling PGMUS correctly.
	// KKstring n2 = name;
	// KK if(name != musicName && name + GetMusicScheme() != musicName) SetMusic(n2); // 05-04-29 fix music handling
	SetMusic(name); // KK
}
// NK <--
void SetMusic(string name)
{
	// KK if(!HasSubStr(name, GetMusicScheme())) name += GetMusicScheme(); // redo music handling 05-04-29
	InitSound();
	Trace("SETTING MUSIC: "+name);
	if (name == "") return;			// LDH 30Mar09
	if (name == musicName)
	{
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
		return;
	}

	//Trace("SetMusic : "+name);
	if (oldMusicID)
	{
		SendMessage(Sound,"ll",MSG_SOUND_RELEASE, oldMusicID);
	}

	if (musicID)
	{
		SendMessage(Sound,"lll",MSG_SOUND_STOP, musicID, MUSIC_CHANGE_TIME);
		oldMusicID = musicID;
	}

	int silenceTime = MUSIC_SILENCE_TIME;	// LDH - 180 seconds gives 1:45 to 3:15 - 12Feb09
	if (name == "music_sea_battle") silenceTime = 30;	// LDH 13Feb09
// KK -->
	string music_name;
	int midx = -1;
	if (strRight(name, 4) == ".ogg")
	{
		music_name = name;
	}
	else
	{
		//midx = FindMusic(name);

		bool bExist = CheckAttribute(Music_Alias, name);
		if (!bExist) return;
		aref MusicRef; makearef(MusicRef, Music_Alias.(name));
		int num = GetAttributesNum(MusicRef);
		if (num == 0) return;

		// LDH cycle through all the music intead of selecting at random - 13Feb09
		int musicnumber = 1;
		if (num > 1)
		{
			ref pchar = GetMainCharacter();
			if (!CheckAttribute(pchar, "musicnumber."+name))
//				musicnumber = 1;
				musicnumber = rand(num-1)+1;	// LDH 07Apr09
			else
				musicnumber = sti(pchar.musicnumber.(name)) + 1;
			if (musicnumber > num) musicnumber = 1;
			pchar.musicnumber.(name) = musicnumber;
		}

		aref MusicNode = GetAttributeN(MusicRef, musicnumber-1);
		music_name = MusicNode.name;

//		string lnode = "f" + musicnumber;
//		string lnode = "l" + (rand(num - 1) + 1);	// the above code replaces this

//		music_name = MusicRef.(lnode).name;

//TraceAndLog("MUSIC: scheme = " + name + ", name = " + music_name + ", (" + musicnumber + " of " + num + ")");	// LDH 13Feb09
	}

	musicID = SendMessage(Sound,"lslllllll",MSG_SOUND_PLAY, music_name, SOUND_MP3_STEREO, VOLUME_MUSIC, true, true, false, MUSIC_CHANGE_TIME, silenceTime*1000);
	if (musicID == 0)	// LDH 24Mar09
	{
//Trace("****** Set music got musicID of zero, would have reset all sound volumes *******");
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, 0, 0);		// LDH resume all sounds immediately - 26Mar09
	}
	else
	{
		if (bExist && CheckAttribute(Music_Alias, name + ".Volume"))
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, musicID, stf(Music_Alias.(name).Volume));
		else
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, musicID, 0.55);
// <-- KK
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, MUSIC_CHANGE_TIME);
	}

	oldMusicName = musicName;
	musicName = name;
}

void FadeOutMusic(int _time)
{
	if (musicID)
	{
		StopSound(musicID,_time);
		musicID = 0;
		musicName = "";
	}
}

// RELOAD
void PauseAllSounds()
{
	Trace("PauseAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_STOP, 0, SOUNDS_FADE_TIME);
}

void ResumeAllSounds()
{
	Trace("ResumeAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
}

// OLD VERSIONS
int PlaySoundDist3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

int PlaySoundLoc3D(string name, float x, float y, float z)
{
	return Play3DSoundCached(name, x,y,z);
}

int PlaySound3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

int PlaySound(string name)
{
	return PlayStereoSound(name);
}

int PlaySoundComplex(string sSoundName, bool bSimpleCache, bool bLooped, bool bCached, int iFadeTime)
{
	return SendMessage(Sound,"lsllllll",MSG_SOUND_PLAY,VOLUME_FX,sSoundName,SOUND_WAV_3D,bSimpleCache,bLooped,bCached,iFadeTime);
}

void StopMusic()
{
}

void PlayMusic(string n)
{
}
//--------------------------------------------------------------------
// Sound Section
//--------------------------------------------------------------------
object Sound;

int alarmed = 0;
int oldAlarmed = 0;
bool seaAlarmed = false;
bool oldSeaAlarmed = false;
void SetMusicAlarm(string name)
{
	//ASVS --->
	if(ENABLE_PLAYING_MAINTHEME) {
		ref pchar = GetMainCharacter();
		float seuil = 0.0;
		string main_theme_name;

		if(CheckAttribute(pchar, "main_theme")) {
			seuil = stf(pchar.main_theme.value)*0.01;
			main_theme_name = pchar.main_theme.musicname;
		}
		//Trace("ASVS, seuil is " + seuil + ", and maintheme name is " + main_theme_name);
		if(main_theme_name != "" && frnd() < seuil)	{
			SetMusic(main_theme_name);
		} else {
			if (alarmed == 0) SetMusic(name);
			else SetMusic("music_bitva");
		}
	} else {
		if (alarmed == 0) {
			SetMusic(name);
		} else {
// KK -->
			if (!bAbordageStarted)
				SetMusic("music_bitva");
			else
				SetSchemeForAbordage();
// <-- KK
		}
	}
	//ASVS <---

	if (alarmed == 0)
	{
//Trace("SetMusicAlarm: NORMAL: oldMusicName = " + oldMusicName + ", musicName = " + musicName);
		SetMusic(name);
	}
	else
	{
//Trace("SetMusicAlarm: ALARMED: oldMusicName = " + oldMusicName + ", musicName = " + musicName);
		oldMusicName = name;			// LDH so proper music gets restored after alarm - 08Apr09
		SetMusic("music_bitva");
	}
}

void Sound_OnAllarm()
{
	Sound_OnAlarm(GetEventData());
}

void Sound_OnAlarm(bool _alarmed)
{
	alarmed = _alarmed;
	if (alarmed == oldAlarmed)
		return;

	if (alarmed != 0)
	{ //alarm on!
// KK -->
		if (!bAbordageStarted)
			SetMusic("music_bitva");
		else
			SetSchemeForAbordage();
// <-- KK
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldAlarmed = alarmed;
}

void Sound_OnSeaAlarm(bool _seaAlarmed)
{
	ref PChar = GetMainCharacter();
	seaAlarmed = _seaAlarmed;
	if (seaAlarmed == oldSeaAlarmed)
		return;

	if (seaAlarmed)
	{ //alarm on!
		if (CheckAttribute(PChar, "seabattlemusic"))
		{
			SetMusic(PChar.seabattlemusic);
		}
		else
		{
			SetMusic("music_sea_battle");
		}
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldSeaAlarmed = seaAlarmed;
}

void InitSound()
{
	//Trace("InitSound");
	if (!IsEntity(&Sound))
	{
		CreateEntity(&Sound, "Sound");
		SetEventHandler("eventAllarm", "Sound_OnAllarm", 0);
	}
}

void ResetSound()
{
	ResetSoundScheme();
	StopSound(0,0);
	ReleaseSound(0);
	musicName = "";
	oldMusicName = "";
}

void LoadSceneSound()
{
	int i = FindLoadedLocation();
// KK -->
	if (i != -1) {
		SetSchemeForLocation(&Locations[i]);
	} else {
		if (bSeaActive) SetSchemeForSea();
	}
// <-- KK
}

// KK -->
string GetMusicSchemeName(int musNum)
{
	string retVal = "Standard";
	ref rms; makeref(rms, registered_music_schemes);
	string lnode = "l" + musNum;
	if (CheckAttribute(rms, lnode)) {
		if (CheckDirectory("RESOURCE\Sounds\MUSIC\\" + rms.(lnode).resdir, "*.ogg") > 0) retVal = rms.(lnode).name;
	}
	return retVal;
}

string GetMusicScheme()
{
	string retVal = "Standard";
	ref rms; makeref(rms, registered_music_schemes);
	string lnode = "l" + music_scheme;
	if (CheckAttribute(rms, lnode)) {
		if (CheckDirectory("RESOURCE\Sounds\MUSIC\\" + rms.(lnode).resdir, "*.ogg") > 0) retVal = rms.(lnode).id;
	}
	return retVal;
}

string GetMusicSchemeResDir()
{
	string retVal = "";
	ref rms; makeref(rms, registered_music_schemes);
	string lnode = "l" + music_scheme;
	if (CheckAttribute(rms, lnode + ".resdir")) retVal = rms.(lnode).resdir;
	return retVal;
}

int GetMusicSchemeCount()
{
	ref rms; makeref(rms, registered_music_schemes);
	return GetAttributesNum(rms);
}

void UpdateSound()
{
trace("UpdateSound: musicName = '" + musicName + "'");
	string mid = musicName;
	if (!CheckAttribute(&Globalsettings, "nomusicinterrupt")) ResetSound(); //MAXIMUS 02.05.2019: for preventing music interruption in main menu
	Alias_Init();
	SetMusic(mid);
}

string Sound_GetName(string name)
{
	if (GetSymbol(name, 0) != "#") return name;
	name = strRight(name, strlen(name) - 1);

	aref SoundsRef;
	string aliasName = "Sounds_Alias";
	if (!CheckAttribute(Sounds_Alias, name)) {
		aliasName = aliasName+"."+name;
		traceandlog("WARNING: sound "+name+" ("+aliasName+") not exist, or not properly added into alias");
		return "INTERFACE\notebook.wav";
	}
	makearef(SoundsRef, Sounds_Alias.(name));

	int num = GetAttributesNum(SoundsRef);
	string lnode = "f"  + (rand(num - 1) + 1);
	if(!CheckAttribute(SoundsRef, lnode))// MAXIMUS: FOR TESTING -->
	{
		aliasName = aliasName+"."+name+".f"+lnode+".name";
		traceandlog("WARNING: sound "+name+" ("+aliasName+") not exist, or not properly added into alias");
		return "INTERFACE\notebook.wav";
	}
	// MAXIMUS: FOR TESTING <--
	return SoundsRef.(lnode).name;
}

//MAXIMUS: -[Will not reset sounds and music, only a dialog. Also a greeting will be played as 3D]->
void PlayGreeting(ref refChar)
{
	LAi_CharacterPlaySound(refChar, refChar.greeting);
//	PlayVoice(refChar, refChar.greeting);
}
// <-- KK
//MAXIMUS: <-[Will not reset sounds and music, only a dialog. Also a greeting will be played as 3D]-

// LDH Plays 3D sound at dialog volume - 18Mar09
int PlayVoice(ref chr, string name)
{
//TraceAndLog("PlayVoice: " + name);

	float x,y,z;
	GetCharacterPos(chr,&x,&y,&z);

	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_SPEECH, false, false, false, 0, x, y, z);
//	return Play3DSound(refChar.greeting, x, y, z);				// plays soundFX volume with range attenuation
//	return PlayStereoSound(Sound_GetName(refChar.greeting));	// plays soundFX volume at full volume

}

// LDH Plays 3D sound at soundFX volume - 19Mar09
int PlayCharacterSound(ref chr, string name)
{
//TraceAndLog("PlayCharacterSound: " + name);

	float x, y, z;
	int ret;

	if (!isMainCharacter(chr) && GetCharacterPos(chr, &x, &y, &z))
		ret = Play3DSound(name, x, y, z);
	else
		ret = PlayStereoSound(name);
	return ret;
}

//ASVS --->
void Change_MainThemeMusic_Chance(float value)
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar, "main_theme.value")) Trace("Pchar doesn't have some main_theme.value attribute.");
	else
	{
		float z = stf(pchar.main_theme.value);
		z = z + value;
		if(z < 0)  z =  0;
		if(z > 33) z = 33;
		pchar.main_theme.value = z;
	}
}
//ASVS <---
