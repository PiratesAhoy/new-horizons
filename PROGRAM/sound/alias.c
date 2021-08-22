object Sounds_Alias;
object Music_Alias;

extern void InitSounds();
extern void InitMusic();
extern void InitOptionalMusic();

extern void RegisterMusicScheme();
extern void RegisterOptionalMusicScheme();

void Alias_Init()
{
	string localization = LanguageGetLanguage();
	string music = GetMusicScheme();
	string sounds_file = "sound\alias\sounds_" + localization + ".c";
//	string music_file = "sound\alias\music_" + music + ".c";
	string music_file = "sound\alias\music_standard.c";
	int i = 0;

	DeleteAttribute(Sounds_Alias, "");
	DeleteAttribute(Music_Alias, "");

	if (FindFile("PROGRAM\sound\alias", "*.c", "sounds_" + localization + ".c") == "")
	{
		//trace("Alias_Init: Can't initialize "+ localization + " sounds, loading ENGLISH.");
		sounds_file = "sound\alias\sounds_english.c";
	}

/*
trace("Alias_Init: music = '" + music + "', attempting to find '" + "music_" + music + ".c'");
	if (FindFile("PROGRAM\sound\alias", "*.c", "music_" + music + ".c") == "")
	{
		//trace("Alias_Init: Can't initialize "+ music + " music, loading standard.");
		music_file = "sound\alias\music_standard.c";
	}
*/

	if (music != "standard")
	{
		if(DEBUGINFO) trace("Alias_Init: music = '" + music + "', attempting to find '" + "music_option_" + music + ".c'");
		if (FindFile("PROGRAM\sound\alias", "*.c", "music_option_" + music + ".c") != "")
		{
			music_file = "sound\alias\music_option_" + music + ".c";
		}
	}

	if(LoadSegment(sounds_file))
	{
		InitSounds();
		UnloadSegment(sounds_file);
	}

	if (LoadSegment("sound\alias\music_standard.c")) {
		RegisterMusicScheme();						// Common music attributes - default mod music, quest/storyline music
		InitMusic();
//		if ("sound\alias\music_standard.c" == music_file) InitMusic();
		if(DEBUGINFO) trace("Alias_Init: standard music loaded");
		UnloadSegment("sound\alias\music_standard.c");
	}
	aref musicfiles = GetFiles("PROGRAM\sound\alias", "music_option_*.c");	// Optional soundtracks
	int n = GetAttributesNum(musicfiles);
	if(DEBUGINFO) trace("Alias_Init: " + n + " optional soundtrack files detected");
	for (i = 0; i < n; i++) {
		aref arCur = GetAttributeN(musicfiles, i);
		string fname = GetAttributeValue(arCur);
		if(DEBUGINFO) trace("Alias_Init: file " + i + " = '" + fname + "'");
		if (fname == "music_standard.c") continue;
		if(DEBUGINFO) trace("Alias_Init: Attempting to load '" + "sound\alias\" + fname + "'");
		if (LoadSegment("sound\alias\" + fname))
		{
			RegisterOptionalMusicScheme();
			if(DEBUGINFO) trace("Alias_Init: fname = '" + fname + "', music_file = '" + music_file + "'"); 
			if ("sound\alias\" + fname == music_file)
			{
				InitOptionalMusic();
			}
			UnloadSegment("sound\alias\" + fname);
		}
	}
// dumpattributes(registered_music_schemes);
}
