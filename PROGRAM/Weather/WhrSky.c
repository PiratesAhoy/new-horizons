object Sky;

void WhrDeleteSkyEnvironment()
{
	if (isEntity(&Sky))
	{
		DeleteClass(&Sky);
	}
	DeleteAttribute(&Sky,"");
}

// Mirsaneli add
void WhrCreateSkyEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aSky; makearef(aSky,aCurWeather.Sky);

	DeleteAttribute(&Sky,"");
	if (!isEntity(&Sky))
	{
		CreateEntity(&Sky,"Sky");
		LayerAddObject(SEA_REFLECTION,&Sky,1);
	}

	// ------------------------------------------------
	// Mirsaneli: Random hourly skies instead of fixed JRH cases
	// ------------------------------------------------
	string selectedSkyFolder;

	// pick a random folder set once
	switch(rand(3)) // adjust number to match how many sky folders you actually have
	{
		case 0: selectedSkyFolder = "skies"; break;
		case 1: selectedSkyFolder = "skies1"; break;
		case 2: selectedSkyFolder = "skies2"; break;
		case 3: selectedSkyFolder = "skies3"; break;
	}

	// get current hour and format folder string
	int hourInt = makeint(GetHour());
	string hourStr;
	if (hourInt == 0)      { hourStr = "24"; }
	else if (hourInt < 10){ hourStr = "0" + hourInt; }
	else                   { hourStr = "" + hourInt; }

	string sDir = "weather\\" + selectedSkyFolder + "\\" + hourStr + "\\";

	// assign to Sky
	Sky.Dir = sDir;
	Sky.Color = Whr_GetColor(aSky, "Color"); // keep color from weather file (or override if you want)

	// ------------------------------------------------
	// fallback: if special quest sky is defined, use that instead
	// ------------------------------------------------
	ref PChar = GetMainCharacter();
	if(CheckAttribute(Pchar,"quest.JRH_sky"))
	{
		switch(Pchar.quest.JRH_sky)
		{
			case "1_Bl": Sky.Dir = "weather\\skies\\1\\"; break;
			case "2_Rd": Sky.Dir = "weather\\skies\\2\\"; break;
			case "3_Pu": Sky.Dir = "weather\\skies\\3\\"; break;
			case "4_Rd": Sky.Dir = "weather\\skies\\4\\"; break;
			// ... (keep the rest of your custom quest overrides here)
		}
	}

	//Hammie -->
	string dir = Sky.Dir;
	DeleteAttribute(&Sky, "Dir");
	Sky.Dir.d1 = dir;
	Sky.Dir = dir;
	//<-- Hammie

	Sky.Angle = Whr_GetFloat(aSky,"Angle");
	Sky.RotateSpeed = Whr_GetFloat(aSky,"Rotate");
	Sky.Size = Whr_GetFloat(aSky,"Size");

	Sky.isDone = "";
}

void MoveSkyToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject(EXECUTE,&Sky);
	LayerDelObject(REALIZE,&Sky);
	LayerDelObject(SEA_EXECUTE,&Sky);
	LayerDelObject(SEA_REALIZE,&Sky);

	LayerAddObject(sExecuteLayer,&Sky,2);
	LayerAddObject(sRealizeLayer,&Sky,2);
}
