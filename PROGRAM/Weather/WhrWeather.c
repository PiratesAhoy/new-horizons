#include "weather\WhrUtils.c"
#include "weather\WhrLightning.c"
#include "weather\WhrRain.c"
#include "weather\WhrSea.c"
#include "weather\WhrSky.c"
#include "weather\WhrSun.c"
#include "weather\WhrTornado.c"
#include "weather\WhrGeneration.c"

#define WIND_NORMAL_POWER		30.0 // NK

//#define MAX_WEATHERS			804	// Old Mithrandir values
#define MAX_WEATHERS			384

float fWeatherAngleOld, fWeatherSpeedOld;
int fogBallast, rainBallast, windBallast;
float windABallast;
int goldRain, goldFog, oldWind;
int gWeatherInit = 1;
int curTime, minwind, maxwind;
int wRain = 0;
int winds = 0;
int fog = 0;
int rWind, rRain, rFog;
float fWindA = 0.0;
float rWindA = 0.0;
float fSeaA;
float fSeaB;

// Values for overriding weather or setting it
// ----------------DO NOT CHANGE THESE VALUES HERE------------------------
float OWeatherAngle = -50.0;		 //Value between 0.0 and PIm2 - Determines the wind angle
float OWABallast = -50.0;			 //Value between 0.0 and the MAX defined in InternalSettings.h
int OFog = -50; 					 //Value between 0 and 20 - Determines fog density
int OFBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
int ORain = -50;					 //Value between 0 and 100 - Determines rain density and storm occurance
int ORBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
int OWind = -50;					 //Value between 0 and 30 - Determines the Wind speed
int OWBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
bool gWeatherOvrd = false;			 //This is the bool checked by the weather system, set to to if you've changed one of the above variables
//To set specific weather set the desired variables to the desired values in your code and set gWeatherOvrd to true the system takes care of the rest


object	Weather, WeatherParams, WhrCommonParams;
int		iNextWeatherNum = -1;
int		iCurWeatherNum = -1;
int		iCurWeatherHour = -1;
bool	bCurWeatherStorm = false;
int		iTotalNumWeathers = 0;
string	sLightingPath = "day";
string	sLmLightingPath = "day";
string	sInsideBack = "";
int	sNewExecuteLayer, sNewRealizeLayer;
string	sCurrentFog;
float	fWeatherDelta = 0.0;
float	fWeatherAngle, fWeatherSpeed;
float	fFogDensity;
int		iShadowDensity[2];
bool	bWeatherLoaded = false;
bool	bWeatherIsNight = false;
bool	bWeatherIsLight = false;
bool	bWeatherIsRain = false;
bool	bWeatherIsStorm = false;

object Weathers;

extern int InitWeather();

#event_handler("EWhr_GetWindAngle", "Whr_GetWindAngle");
#event_handler("EWhr_GetWindSpeed", "Whr_GetWindSpeed");
#event_handler("EWhr_GetShadowDensity", "Whr_GetShadowDensity");
#event_handler("EWhr_GetFogDensity", "Whr_GetFogDensity");

void SetNextWeather(string sWeatherID)
{
//	Traceandlog("SetNextWeather Called: " +sWeatherID);

	string sWeather = sWeatherID;
	if (sWeatherID == "Blue Sky" || sWeatherID == "Moon Night") sWeather = "Clear";
	if (sWeatherID == "Day Storm")								sWeather = "Heavy Storm";

	switch (sWeather)
	{
	case  "Clear":
		Orain = 0;
		ORBallast = 0;
		OFog = 0;
		gWeatherOvrd = true;	// LDH make new weather in CreateWeatherEnvironment 17Feb09
		break;

	case  "Cloudy":
		Orain = 60;		// clouds start at 50, overcast starts at 65
		gWeatherOvrd = true;
		break;

	case  "Overcast":
		Orain = 70;		// overcast starts at 65, rain starts at 75
		gWeatherOvrd = true;
		break;

	case  "Rainy":
		Orain = 80;		// rain starts at 75, storm starts at 95
		gWeatherOvrd = true;
		break;

	case  "Heavy Rain":
		Orain = 90;		// rain starts at 75, storm starts at 95
		gWeatherOvrd = true;
		break;

	case  "Stormy":		// this produces lightning
		Orain = 97;		// storm starts at 95
		OWind = 25;		// twisters start at minwind >= 28
		gWeatherOvrd = true;
		break;

	case "Heavy Storm":	// this produces twisters, "Day Storm"
		Orain = 100;	// storm starts at 95
		ORBallast = 15;
		OWind = 30;		// twisters start at minwind >= 28
		OWBallast = 15;
		gWeatherOvrd = true;
		break;

	case  "Foggy":
		OFog = 15;		// produces fog density of 0.00375
		gWeatherOvrd = true;
		break;

	case  "Heavy Fog":
		OFog = 25;		// produces fog density of 0.00625
		gWeatherOvrd = true;
		break;

	case  "Black Pearl Fight":
		Orain = 90;
		OFog = 15;
		OWind = 25;
		gWeatherOvrd = true;
		break;

	case  "IslaDeMuerte":
		OFog = 80;		// produces fog density of 0.02
		gWeatherOvrd = true;
		break;

	case  "Super Fog":
		OFog = 999;
		gWeatherOvrd = true;
		break;

	case  "Alcove":
		// still needs to be implemented, see special.c
//		gWeatherOvrd = true;
		break;

//	default:

		Trace("Whr: Error: SetNextWeather called with unknown weatherID: " + sWeatherID);
	}

// LDH <--
}

// call this with sDir = "" to use old wind direction
// call this with speed < 0 to use old wind speed
void SetNextWind(string sDir, int speed)
{
	int dir = -1;
	switch (sDir)
	{
	case "N":	dir =  0; break;
	case "NNE":	dir =  1; break;
	case "NE": 	dir =  2; break;
	case "ENE":	dir =  3; break;
	case "E":  	dir =  4; break;
	case "ESE":	dir =  5; break;
	case "SE": 	dir =  6; break;
	case "SSE":	dir =  7; break;
	case "S":  	dir =  8; break;
	case "SSW":	dir =  9; break;
	case "SW": 	dir = 10; break;
	case "WSW":	dir = 11; break;
	case "W":  	dir = 12; break;
	case "WNW":	dir = 13; break;
	case "NW": 	dir = 14; break;
	case "NNW":	dir = 15; break;
	}
	if (dir != -1)
	{
		OWeatherAngle = Degree2Radian(dir*22.5);
		gWeatherOvrd = true;
	}
	if (speed >= 0)
	{
		OWind = iclamp(5,30,speed);
		gWeatherOvrd = true;
	}
}

void WeatherInit()
{
	DeleteAttribute(&WeatherParams,"");

	if (LoadSegment("weather\WhrInit.c"))
	{
		iTotalNumWeathers = InitWeather();
		UnloadSegment("weather\WhrInit.c");
	}
}

void DeleteWeatherEnvironment()
{
	if (isEntity(&Weather))
	{
		DeleteClass(&Weather);
	}
	DeleteAttribute(&Weather,"");
	WeatherParams.Tornado = false;
	//DeleteAttribute(&WeatherParams,"");

	WhrDeleteRainEnvironment();
	WhrDeleteSkyEnvironment();
	WhrDeleteSunGlowEnvironment();
	WhrDeleteLightningEnvironment();
	WhrDeleteTornadoEnvironment();
	WhrDeleteSeaEnvironment();

	DelEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor");
	DelEventHandler("frame","Whr_OnWindChange");

	bWeatherLoaded = false;
}

aref GetCurrentWeather()
{
	aref arWeather;
	makearef(arWeather,Weathers);
	return arWeather;
}

void CreateWeatherEnvironment()
{
	ref pchar = GetMainCharacter();
	DeleteAttribute(&Weather,"");
	if (!isEntity(&Weather))
	{
		CreateEntity(&Weather, "Weather");
	}
	//WeatherParams.Tornado = false;
	iNextWeatherNum = 0;
//	iCurWeatherNum = 0;		// LDH this isn't used so we're using it as the last day the weather updated

	// LDH 20Feb09 -->
	int theDay = GetDayOfYear(GetDataYear(), GetDataMonth(), GetDataDay());
	if (iCurWeatherNum > theDay) iCurWeatherNum = theDay;	// for end of year. Not quite right, but will work.
	if (iabs(theDay - iCurWeatherNum) > 1 && !gWeatherOvrd)
	{
		Trace("** Whr: CreateWeatherEnvironment - iCurWeatherNum = " + iCurWeatherNum + ", theDay = " + theDay);
		gWeatherInit = 1;	// new weather if we spend more than a day in one location, for example the shipyard getting repairs
	}
	iCurWeatherNum = theDay;
	// LDH <--

	// LDH 17Feb09 -->
	int theHour = MakeInt(GetHour());
	Trace("** Whr: CreateWeatherEnvironment - iCurWeatherhour = " + iCurWeatherhour + ", theHour = " + theHour);
	if (iCurWeatherhour != theHour || gWeatherOvrd || gWeatherInit || CheckAttribute(&WeatherParams, "update"))
	{
		if (theHour != 0 && iabs(iCurWeatherhour-theHour) > 1 && !gWeatherOvrd)
			gWeatherInit = 1;	// all new weather if enough time passes
		Whr_Generator();
		iCurWeatherHour = theHour;
		if(CheckAttribute(&WeatherParams, "update")) DeleteAttribute(&WeatherParams, "update"); // screwface
		// PB: Slow down game to normal speed when you are caught in irons -->
		// But only ONCE after the weather change and not ALL the time
		pchar.timescale_reset = true;
		// PB: Slow down game to normal speed when you are caught in irons <--
	}
	// LDH <--

	aref aCurWeather = GetCurrentWeather(); // Returns reference to weather generated

	sLightingPath = Whr_GetString(aCurWeather,"Lighting");
	sLmLightingPath = Whr_GetString(aCurWeather,"LightingLm");
	sInsideBack = Whr_GetString(aCurWeather,"InsideBack");
	bWeatherIsNight = Whr_GetLong(aCurWeather,"Night");
	bWeatherIsLight = Whr_GetLong(aCurWeather,"Lights");
	Weather.Wind.Angle = Whr_GetFloat(aCurWeather,"Wind.Angle");
	Weather.Wind.Speed = Whr_GetFloat(aCurWeather,"Wind.Speed");

	sCurrentFog = "Fog";
	if (bSeaActive)
	{
		if (CheckAttribute(aCurWeather, "SpecialSeaFog")) { sCurrentFog = "SpecialSeaFog"; }
	}

	string sCurFog = Whr_GetCurrentFog();
	Weather.Fog.Enable = Whr_GetLong(aCurWeather, sCurFog + ".Enable");
	Weather.Fog.Start = Whr_GetFloat(aCurWeather, sCurFog + ".Start");
	Weather.Fog.Density = Whr_GetFloat(aCurWeather, sCurFog + ".Density");
	Weather.Fog.Color = Whr_GetColor(aCurWeather, sCurFog + ".Color");

	Weather.Sun.Color = Whr_GetColor(aCurWeather,"Sun.Color");
	Weather.Sun.HeightAngle = Whr_GetFloat(aCurWeather,"Sun.HeightAngle");
	Weather.Sun.AzimuthAngle = Whr_GetFloat(aCurWeather,"Sun.AzimuthAngle");
	Weather.Sun.Ambient = Whr_GetColor(aCurWeather,"Sun.Ambient");

	Weather.isDone = "";

	SetEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor",0);
	SetEventHandler("frame","Whr_OnWindChange",0);

	fFogDensity = stf(Weather.Fog.Density);

	fWeatherDelta = 0.0;
	fWeatherAngle = stf(Weather.Wind.Angle);
	fWeatherSpeed = stf(Weather.Wind.Speed);

	WhrCreateRainEnvironment();
	WhrCreateSunGlowEnvironment();
	WhrCreateLightningEnvironment();
	WhrCreateSkyEnvironment();
	WhrCreateSeaEnvironment();
	if(wRain >= 98) { WhrCreateTornadoEnvironment(); } // JL FLAG -----

	Particles.windpower = 0.05 * Clampf(Whr_GetWindSpeed() / WIND_NORMAL_POWER);
	Particles.winddirection.x = sin(Whr_GetWindAngle());
	Particles.winddirection.z = cos(Whr_GetWindAngle());

	bWeatherLoaded = true;

	// PB: Only show this if you've actually got a compass -->
	// FlayedOne
	bool ShowWindLog = false;
	string logstr = "";
	string compasstype = CheckCharacterEquipByGroup(pchar, COMPASS_ITEM_TYPE);
	if (winds == 0)			logstr = TranslateString("", "The air is calm");
	if (winds > 0 && winds <= 2)	logstr = TranslateString("", "There are light airs");
	if (winds > 2 && winds <= 6)	logstr = TranslateString("", "There is a light breeze");
	if (winds > 6 && winds <=10)	logstr = TranslateString("", "There is a gentle breeze");
	if (winds >10 && winds <=15)	logstr = TranslateString("", "There is a moderate breeze");
	if (winds >15 && winds <=20)	logstr = TranslateString("", "There is a fresh breeze");
	if (winds >20 && winds <=27)	logstr = TranslateString("", "There is a strong breeze");
	if (winds >27)			logstr = TranslateString("", "There is a near gale");

	if (winds>0)
	{
		switch (compasstype)
		{
			case "compass1":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + logstr;
					break;
					logstr = logstr + " " + TranslateString("wind_from_the", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)));
				}
			break;
			case "compass2":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + TranslateString("", "Wind is from the") + " " + TranslateString("", "wind_at") + " " +  winds + " " + TranslateString("", "kts");
					break;
					logstr = TranslateString("Wind is from the", "") + " " + TranslateString(GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)), "") + " " + TranslateString("", "wind_at") + " " + winds + " " + TranslateString("", "kts");
				}
			break;
			case "compass3":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + TranslateString("", "Wind is from the") + " " + TranslateString("", "wind_at") + " " +  winds + " " + TranslateString("", "kts");
					break;
					logstr = TranslateString("Wind is from the", "") + " " + TranslateString(GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)), "") + " " + TranslateString("", "wind_at") + " " + winds + " " + TranslateString("", "kts");
				}
			break;
			// In Russian translation, "Wind is from the" translates to "wind"
		}
	}
	if(bSeaActive && compasstype == "")			ShowWindLog = true;
	if(CheckAttribute(PChar, "skipWeatherLogs"))		ShowWindLog = false;
	if(ShowWindLog)						LogIt(logstr);

	if(pchar.location != "" && Pchar.location != "error")
	{
		if(findlocation(Pchar.location)>0)
		{
			ref loc = &locations[findlocation(Pchar.location)];

			// Only show this in ports, on shores and ship decks
			if(GetAttribute(loc, "type") == "seashore")	ShowWindLog = true;
			if(GetAttribute(loc, "type") == "port")		ShowWindLog = true;
			if(GetAttribute(loc, "type") == "own_deck")	ShowWindLog = true;
			if(ShowWindLog)								LogIt(logstr);
	// PB: Only show this if you've actually got a compass <--

	// Screwface : For Lagoon color mod
			if(loc.environment.sea == "true" && wRain<75 && aCurWeather.id == "Blue Sky")
			{
				if(loc.type == "seashore")
				{
					Sea.GF3.WaterColor = argb(0,124,202,215);
					Sea.GF3.SkyColor = argb(0,109,185,240);
					Sea.WaterAttenuation = 0.3;
				}
				if (ownDeckStarted() && GetCharacterShipType(Pchar) != SHIP_NOTUSED) // PB: Prevent error message
				{
					if(Locations[FindLocation(GetCharacterShipLocation(Pchar))].type == "seashore")
					{
						Sea.GF3.WaterColor = argb(0,124,202,215);
						Sea.GF3.SkyColor = argb(0,109,185,240);
						Sea.WaterAttenuation = 0.3;
					}
				}
			}
			// PB: Swamps (yellow) -->
			if(CheckAttribute(loc, "environment.swamp") && loc.environment.swamp == "true")
			{
				Sea.GF3.WaterColor = argb(0,160,116,33);
				Sea.GF3.SkyColor = argb(0,179,187,6);
			}
			// PB: Swamps <--

			// JRH: Swamps (light green) -->
			if(CheckAttribute(loc, "environment.swamp2") && loc.environment.swamp2 == "true")
			{
				Sea.GF3.WaterColor = argb(100,100,100,100);
				Sea.GF3.SkyColor = argb(0,179,187,6);
			}
			// JRH: Swamps <--

			// JRH: Sewer (brown) -->
			if(CheckAttribute(loc, "environment.sewer") && loc.environment.sewer == "true")
			{
				Sea.GF3.WaterColor = argb(0,100,25,50);
				Sea.GF3.SkyColor = argb(0,179,187,6);
			}
			// JRH: Sewer <--
		}
		else
		{
			string island = pchar.location;
			int li = Findisland(island);
			if(li >= 0)
			{
				//logit("island : " + island);
				//logit("weather : " + aCurWeather.id);
				if(CheckAttribute(Pchar,"Ship.Pos.save"))
				{
					pchar.Ship.Pos.x = MakeFloat(pchar.Ship.Pos.save.x);
					pchar.Ship.Pos.z = MakeFloat(pchar.Ship.Pos.save.z);
					DeleteAttribute(Pchar,"Ship.Pos.save");
				}
				float psX = MakeFloat(pchar.Ship.Pos.x);
				float psZ = MakeFloat(pchar.Ship.Pos.z);
				//logit("Ship pos x : " + MakeFloat(pchar.Ship.Pos.x));
				//logit("Ship pos z : " + MakeFloat(pchar.Ship.Pos.z));
				float isR = 450.0;
				aref rl;
				makearef(rl, Islands[li].reload);
				int num = GetAttributesNum(rl);
				for(int j = 0; j < num; j++)
				{
					string tempattrname = GetAttributeName(GetAttributeN(rl,j));
					if (CheckAttribute(rl, tempattrname+".x"))
					{
						//logit("locator : " + GetAttributeName(GetAttributeN(rl,j)));
						float ix = stf(rl.(tempattrname).x);
						float iz = stf(rl.(tempattrname).z);
						if(aCurWeather.id == "Blue Sky")
						{
							if(wRain < 75)
							{
								if(GetDistance2D(psX, psZ, ix, iz) <= isR && Locations[FindLocation(rl.(tempattrname).go)].type =="seashore")
								{
									Sea.GF3.WaterColor = argb(0,124,202,215);
									Sea.GF3.SkyColor = argb(0,109,185,240);
									Sea.WaterAttenuation = 0.3;
									If(!Checkattribute(rl, tempattrname+".inlagoon")) rl.(tempattrname).inlagoon = 1;
									break;
								}
								else
								{
									Sea.GF3.WaterColor = aCurWeather.Sea.Water.Color;
									Sea.GF3.SkyColor = aCurWeather.Sea.Sky.Color;
									Sea.WaterAttenuation = aCurWeather.Sea.WaterAttenuation
									if(CheckAttribute(rl, tempattrname+".inlagoon")) DeleteAttribute(rl, tempattrname+".inlagoon");
								}
							}
							else
							{
								Sea.GF3.WaterColor = aCurWeather.Sea.Water.Color;
								Sea.GF3.SkyColor = aCurWeather.Sea.Sky.Color;
								Sea.WaterAttenuation = aCurWeather.Sea.WaterAttenuation
							}
						}
					}
				}
			}
		}
	} //Screwface : end
}

void Whr_UpdateWeather(bool reinit_weather) // NK 04-09-21
{
	// LDH cleanup 16Feb09
//	Traceandlog("Whr_UpdateWeather start weather update " + "Time: " + GetStringTime(GetTime()) +" reinit: " +reinit_weather);	// LDH 05Sep06 trace for CTD

	if(reinit_weather) WeatherInit(); // NK 04-09-21
	CreateWeatherEnvironment();
	MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);

	trace("Whr_UpdateWeather finish weather update");

	if(bSeaActive && !ownDeckStarted())
	{
		PlayStereoSound("nature\wind_sea4.wav"); // squall i.e. weatherchange
		DirectsailCheck(true);	//  triggers change to other island and ship encounters, necessary to run here
	}
}

// LDH no longer used 16Feb09
void Whr_LoadNextWeather(int nPlus)
{
/*
	WeatherInit();

	iCurWeatherHour = MakeInt(GetHour());
	iCurWeatherNum = iCurWeatherNum + nPlus;

	if (iCurWeatherNum < 0)
	{
		iCurWeatherNum = iTotalNumWeathers - 1;
	}
	if (iCurWeatherNum >= iTotalNumWeathers)
	{
		iCurWeatherNum = 0;
	}

	if (CheckAttribute(&Weathers, "Skip"))
	{
		if (sti(Weathers.skip))
		{
			Whr_LoadNextWeather(nPlus);
			return;
		}
	}

	CreateWeatherEnvironment();
	MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);

	aref	aCurWeather = GetCurrentWeather();
	iCurWeatherHour = sti(aCurWeather.Hour.Min);

	SetCurrentTime(iCurWeatherHour, 0);

	Island.LightingPath = GetLightingPath();
*/
}

void Whr_OnWindChange()
{
	float fDeltaTime = MakeFloat(GetDeltaTime()) * 0.001;
	fWeatherDelta = fWeatherDelta + fDeltaTime;
	float fSpd = fWeatherSpeed + (fWeatherSpeed / 6.0) * 0.1 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));
	float fAng = fWeatherAngle + 0.02 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));
	Weather.Wind.Angle = fAng;
	Weather.Wind.Speed = fSpd;
}

int Whr_OnCalcFogColor()
{
	int		iAlpha, iColor;
	float	x, y, z;
	aref	aCurWeather = GetCurrentWeather();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	iAlpha = 255 - MakeInt(255.0 * Clampf(y / stf(aCurWeather.(sCurrentFog).Height)));

	int iFogColor = sti(Weather.Fog.Color);
	iColor = or(shl(iAlpha, 24), iFogColor);
	return iColor;
}

void CreateWeather(string sExecuteLayer, string sRealizeLayer)
{
	CreateWeatherEnvironment();
	MoveWeatherToLayers(sExecuteLayer, sRealizeLayer);
}

void DeleteWeather()
{
	DeleteWeatherEnvironment();
}

void MoveWeatherToLayers(int sExecuteLayer, int sRealizeLayer)
{
	LayerDelObject(EXECUTE,&Weather);
	LayerDelObject(REALIZE,&Weather);
	LayerDelObject(SEA_EXECUTE,&Weather);
	LayerDelObject(SEA_REALIZE,&Weather);

	sNewExecuteLayer = sExecuteLayer;
	sNewRealizeLayer = sRealizeLayer;

	LayerAddObject(sExecuteLayer,&Weather,1000000);
	LayerAddObject(sRealizeLayer,&Weather,65530);

	MoveRainToLayers(sExecuteLayer, sRealizeLayer);
	MoveLightningToLayers(sExecuteLayer, sRealizeLayer);
	MoveSkyToLayers(sExecuteLayer, sRealizeLayer);
	MoveSunGlowToLayers(sExecuteLayer, sRealizeLayer);
}

float Whr_GetFogDensity() { return fFogDensity; }

float Whr_GetWindAngle()
{
	if (!CheckAttribute(Weather,"Wind.Angle")) { return 0.0; }
	return stf(Weather.Wind.Angle);
}

float Whr_GetWindSpeed()
{
	if (!CheckAttribute(Weather,"Wind.Speed")) { return 0.0; }
	return stf(Weather.Wind.Speed);
}

ref Whr_GetShadowDensity()
{
	aref	aCurWeather = GetCurrentWeather();

	iShadowDensity[0] = argb(255,96,96,96);
	iShadowDensity[1] = argb(255,96,96,64);

	if (bWeatherLoaded)
	{
		iShadowDensity[0] = Whr_GetColor(aCurWeather,"Shadow.Density.Head");
		iShadowDensity[1] = Whr_GetColor(aCurWeather,"Shadow.Density.Foot");
	}

	return &iShadowDensity;
}

string	Whr_GetCurrentFog() { return sCurrentFog; }

string	Whr_GetInsideBack() { return sInsideBack; }
string	GetLightingPath()	{ return sLightingPath; }
string	GetLmLightingPath() { return sLmLightingPath; }

bool	Whr_IsDay() { return !bWeatherIsNight; };
bool	Whr_IsNight() { return bWeatherIsNight; };
bool	Whr_IsLight() { return bWeatherIsLight; };
bool	Whr_IsRain() { return bWeatherIsRain; }
bool	Whr_IsStorm() { return bWeatherIsStorm; }
bool	Whr_IsFog() { return stf(Weathers.Fog.SeaDensity)>0.01; }
