object Sounds_Alias;
object Music_Alias;

extern void InitSounds();
extern void InitMusic();

extern void RegisterMusicScheme();

void Alias_Init()
{
	string localization = LanguageGetLanguage();
	string music = GetMusicScheme();
	string sounds_file = "sound\alias\sounds_" + localization + ".c";
	string music_file = "sound\alias\music_" + music + ".c";
	int i = 0;

	DeleteAttribute(Sounds_Alias, "");
	DeleteAttribute(Music_Alias, "");

	if (FindFile("PROGRAM\sound\alias", "*.c", "sounds_" + localization + ".c") == "") {
		//trace("Alias_Init: Can't initialize "+ localization + " sounds, loading ENGLISH.");
		sounds_file = "sound\alias\sounds_english.c";
	}

	if (FindFile("PROGRAM\sound\alias", "*.c", "music_" + music + ".c") == "") {
		//trace("Alias_Init: Can't initialize "+ music + " music, loading standard.");
		music_file = "sound\alias\music_standard.c";
	}

	if(LoadSegment(sounds_file))
	{
		InitSounds();
		UnloadSegment(sounds_file);
	}

	if (LoadSegment("sound\alias\music_standard.c")) {
		RegisterMusicScheme();
		if ("sound\alias\music_standard.c" == music_file) InitMusic();
		UnloadSegment("sound\alias\music_standard.c");
	}
	aref musicfiles = GetFiles("PROGRAM\sound\alias", "music_*.c");
	int n = GetAttributesNum(musicfiles);
	for (i = 0; i < n; i++) {
		aref arCur = GetAttributeN(musicfiles, i);
		string fname = GetAttributeValue(arCur);
		if (fname == "music_standard.c") continue;
		if (LoadSegment("sound\alias\" + fname)) {
			RegisterMusicScheme();
			if ("sound\alias\" + fname == music_file) InitMusic();
			UnloadSegment("sound\alias\" + fname);
		}
	}
}
