object Rain;

void WhrDeleteRainEnvironment()
{
	if (isEntity(&Rain))
	{
		DeleteClass(&Rain);
	}
	DeleteAttribute(&Rain,"");
}

void WhrCreateRainEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aRain; 	makearef(aRain,aCurWeather.Rain);
	aref aRainbow; 	makearef(aRainbow,aCurWeather.Rainbow);

	Rain.Clear = "";
	DeleteAttribute(&Rain,"");

	bWeatherIsRain = false;

	if (sti(aRain.NumDrops) == 0) return;

	if (!isEntity(&Rain))
	{
		CreateEntity(&Rain,"rain");
	}

	Rain.NumDrops = Whr_GetLong(aRain,"NumDrops");
	Rain.Color = Whr_GetColor(aRain,"Color");
	Rain.DropLength = Whr_GetFloat(aRain,"DropLength");
	Rain.Height = Whr_GetFloat(aRain,"Height");
	Rain.Radius = Whr_GetFloat(aRain,"Radius");
	Rain.Speed = Whr_GetFloat(aRain,"Speed");
	Rain.Jitter = Whr_GetFloat(aRain,"Jitter");
	Rain.WindSpeedJitter = Whr_GetFloat(aRain,"WindSpeedJitter");
	Rain.TimeBlend = Whr_GetLong(aRain,"TimeBlend");
	Rain.MaxBlend = Whr_GetLong(aRain,"MaxBlend");

	Rain.RainDrops.DropsNearNum = Whr_GetLong(aRain, "DropsNearNum");
	Rain.RainDrops.DropsFarNum = Whr_GetLong(aRain, "DropsFarNum");
	Rain.RainDrops.DropsNearRadius = Whr_GetFloat(aRain, "DropsNearRadius");
	Rain.RainDrops.DropsFarRadius = Whr_GetFloat(aRain, "DropsFarRadius");
	Rain.RainDrops.DropsLifeTime = Whr_GetFloat(aRain, "DropsLifeTime");
	Rain.RainDrops.DropsSize = Whr_GetFloat(aRain, "DropsSize");
	Rain.RainDrops.DropsColor = Whr_GetLong(aRain, "DropsColor");
	Rain.RainDrops.DropsTexture = Whr_GetString(aRain, "DropsTexture");

	Rain.Rainbow.Enable = Whr_GetLong(aRainbow,"Enable");
	Rain.Rainbow.Texture = Whr_GetString(aRainbow,"Texture");
	
	Rain.isDone = "";

	bWeatherIsRain = true;
}

void MoveRainToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject(EXECUTE,&Rain);
	LayerDelObject(REALIZE,&Rain);
	LayerDelObject(SEA_EXECUTE,&Rain);
	LayerDelObject(SEA_REALIZE,&Rain);

	LayerAddObject(sExecuteLayer, &Rain, 65537);
	LayerAddObject(sRealizeLayer, &Rain, 65537);
}
