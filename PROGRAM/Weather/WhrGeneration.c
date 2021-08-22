#include "Weather\Init\WhrSetAzmAng.c"
#include "Weather\Init\WhrInitValues.c"
#include "Weather\Init\WhrGenerateValues.c"
#include "Weather\Init\WhrFogRainCheck.c"
#include "Weather\Init\WhrDebugInfo.c"

void Whr_ResetOvrd(){
	OWeatherAngle = -50.0;
	OWABallast = -50.0;
	OFog = -50;
	OFBallast = -50;
	ORain = -50;
	ORBallast = -50;
	OWind = -50;
	OWBallast = -50;
	gWeatherOvrd = false;
}

void Whr_Generator(){
// ====================================================================
// JL - Less Random Weather Generator -- hopefully
// ====================================================================

	//Traceandlog("WhrInit.c : Whr_Generator() called -- gWeatherInit: " +gWeatherInit); //JL - Figuring out this weather system
	bool bWhrTornado = false;
	bool bWhrStorm = false;
	if(gWeatherInit == 1){
		goldRain = rand(100);
		goldFog = rand(20);
//		oldWind = rand(30);
		oldWind = rand(25) + 5;		// LDH 09Feb09
		fWeatherAngleOld = frand(PIm2);
		gWeatherInit = 0;
		fogBallast = 0; 
		rainBallast = 0; 
		windBallast = 0; 
		windABallast = 0;
		Trace(" !gWeatherInit Whr_Generator() - Initialized ");
	}

	//Logit("BugTracker - goldFog: " + goldFog + " goldRain: " + goldRain + " oldWind: " + oldWind + " gWeatherInit: " + gWeatherInit);
	curTime = MakeInt(GetHour()); //Causing problems
	bWeatherIsStorm = false; // screwface
	bWeatherIsRain = false; // screwface

	rWind = rand(MAX_WINDCHANGE);
	rFog = rand(MAX_FOGCHANGE); 
	rRain = rand(MAX_RAINCHANGE);
	rWindA = frand(MAX_ANGLECHANGE);
	
	Whr_GenerateValues(FREE_FOG);
	
	//--Testing Settings--------------------------------------------------------
	
	//wRain = 66;
	//fog = 20;
	//curTime = 6;
	//winds = 16;
	//rainBallast = 20;

	//--Testing Settings--------------------------------------------------------
	
	if(gWeatherOvrd){
		if(oWeatherAngle != -50.0){fWindA = OWeatherAngle;	}
		if(OWABallast != -50.0){windABallast = OWABallast; }
		if(OFog != -50){fog = OFog;}
		if(OFBallast != - 50){fogBallast = OFBallast;}
		if(ORain != -50){wRain = ORain;}
		if(ORBallast != -50){rainBallast = ORBallast;}
		if(OWind != -50){winds = OWind;}
		if(OWBallast != -50){windBallast = OWBallast;}
		Whr_ResetOvrd();
	}
	
	if (CheckAttribute(&WeatherParams,"Storm")) { bWhrStorm = sti(WeatherParams.Storm); } 
	if (CheckAttribute(&WeatherParams,"Tornado")) { bWhrTornado = sti(WeatherParams.Tornado); } 
	WeatherParams.Storm = false;
	WeatherParams.Tornado = false;
	
	if(bWhrStorm){
		wRain = 95;
		winds = 25;
		windBallast = 10;
		rainBallast = 10;
		fog = 75; //Armada
		//Weathers.Fog.Color = argb(0,33,40,50);
		bWeatherIsStorm = true; // screwface
	}
	if(bWhrTornado){
		wRain = 100;
		winds = 30;
		windBallast = 20;
		rainBallast = 20;
		fog = 75; //Armada
		//Weathers.Fog.Color = argb(0,33,40,50);
	}
	btornado = bWhrTornado; //screwface
	bstorm = bWhrStorm; //screwface
	
	goldRain = wRain;	
	goldFog = fog;
	oldWind = winds;
	fWeatherAngleOld = fWindA;
	
	if(windABallast >=  MAX_ABALLAST || windABallast <= -MAX_ABALLAST ){ windABallast = 0;}
	if(rainBallast  >=  MAX_RBALLAST )                                 { rainBallast = -MAX_RBALLAST;}
	if(rainBallast  <= -MAX_RBALLAST )                                 { rainBallast =  MAX_RBALLAST;}
	if(windBallast  >=  MAX_WBALLAST )                                 { windBallast = -MAX_WBALLAST;}
	if(windBallast  <= -MAX_WBALLAST )                                 { windBallast =  MAX_WBALLAST;}
	if(fogBallast   >=  MAX_FBALLAST )                                 { fogBallast  = -MAX_FBALLAST;}
	if(fogBallast   <= -MAX_FBALLAST )                                 { fogBallast  =  MAX_FBALLAST;}
	
	if(wRain >= 85 && winds <= 10){ windBallast = 15;}
	if(winds <= 25 && wRain >= 90){ rainBallast = -15;}
	if(fog > 0 && curTime >= 7 && curTime <= 20 && wRain <= 75){fogBallast = -30;}
	if(fogBallast < 0 && curTime > 20 || curTime < 7){fogBallast = 0;}
	if(fogBallast < 0 && curTime >= 7 && curTime <=20 && wRain > 75){fogBallast = 0;}
	
	minwind = winds - rand(2);
	maxwind = winds + rand(2);
	if(minwind < 5){minwind = 5;}	// LDH up from 0 - 12Feb09
	if(maxwind > 30){maxwind = 30;}
	if(minwind > maxwind){ minwind = maxwind; } // JL - Temporary catch all for weird wind bug
	
	Whr_InitGValues(); //Setup generic values based on ToD
	Whr_FogRainCheck();	 //Set wRain and fog values
	Whr_SetAzmAng(); //Setup specific values for azimuth and angle and sky loaded

	// NK & Mith-->
	// LDH fixes - 16Mar09
	string direction1, direction2, direction3;

	fSeaA = PIm2 - fWindA;
	if (fSeaA >= (3.0 * PId2))
	{
		fSeaB = (fSeaA + PId2 - PIm2);
	}
	else
	{
		fSeaB = fSeaA + PId2;
	}
	Weathers.Wind.Angle = fWindA;
	Weathers.Wind.Speed.Min = minwind;
	Weathers.Wind.Speed.Max = maxwind;

	direction1 = fts(fSeaB, 4);
	direction2 = fts((fSeaB + (PId2 / 2.0)), 4);
	direction3 = fts((fSeaB - (PId2 / 2.0)), 4);

	float myWind = maxwind;
	if (maxwind > 25.0 && !bWhrStorm && !bWhrTornado)
		myWind = 25.0;

	float windStrength1 = myWind / 26.0;
	float windStrength2 = myWind / 30.0;
	float windStrength3 = myWind / 28.0;

	string seaStrength1 = f2s(windStrength1, 4);
	string seaStrength2 = f2s(windStrength2, 4);
	string seaStrength3 = f2s(windStrength3, 4);

	string waveSpeed = "-78.0";
	if(REALISTIC_WAVES == 1)
	{
		// Note on the piece of code below: each line, numbered 1, 2 and 3, are each separate "generators" of waves,
		// each controlling the different aspects of the harmonics model. 
		// The first line controls the height, direction and speed of the wave.
		// The second line controls the direction, speed and height of the entire surface.
		// The third line controls the direction, height and speed of each wave.
		// The value changed is "waveLength#" 
		// (waveLength1 is equal to 20 right now, wavelength2 is equal to 0.01, and wavelength3 is equal to 10).
		// For example, setting the second and third line to 0.01 (minimum value) while keeping the first line as the
		// same number would make the waves go in a single direction, without changing shape or breaking.
		// Setting all numbers for "generators" to an equal value would create perfect harmonic waves.
		// If you are not satisfied with the waves in this mod, please modify the values that right now say "20", "0.01" and "10" 

		Weathers.Sea.Harmonics.h1 = direction1 + ",20.0," + seaStrength1 + ",80.87," + waveSpeed;
		Weathers.Sea.Harmonics.h2 = direction2 + ",0.01," + seaStrength2 + ",82.28," + waveSpeed;
		Weathers.Sea.Harmonics.h3 = direction3 + ",10.0," + seaStrength3 + ",82.28," + waveSpeed;
		if(bWhrStorm) //screwface
		{
			 // screwface
			if(bSeaActive && !ownDeckStarted())
			{
				iStormLockSeconds = 60;
				Seafoam.storm = "true";
				//bstorm = true;
				// Build 13 fog - Armada -> (fog effects changed and moved to lines 85 and 94)
				/*Weathers.Fog.Enable = true;
				Weathers.Fog.Height = 500.0;
				Weathers.Fog.Start = 0.0;
				Weathers.Fog.Density = 10.0;
				Weathers.Fog.SeaDensity = 0.019;
				Weathers.Fog.Color = argb(0,33,40,50);*/
				// Build 13 fog - Armada <-
				Weathers.Sea.Sky.Color = argb(0,255,255,255);
				//Weathers.Sea.Water.Color = argb(0,0,0,10);
				//Weathers.Sea.Pena.Color = argb(0,100,100,100);
				//Weathers.Sea.Bump.Tile = 0.07;
				Weathers.Sea.Bump.Ang = 2.0;
				Weathers.Sea.Bump.Speed = 0.01;
				Weathers.Sea.Bump.AnimSpeed = 23.0;
				Weathers.Sea.Bump.Scale = 2.0;
				Weathers.Sea.Harmonics.h1 = "0.0,10.0,0.1202,80.87,-68.00";
				Weathers.Sea.Harmonics.h2 = "1.57,10.0,2.1002,82.28,88.00";
				Weathers.Sea.Harmonics.h3 = "0.47,7.0,2.2002,82.28,68.00";
				//Weathers.Sea.Harmonics.h4 = "0.27,47.0,0.0502,82.28,288.00"; //
				//Weathers.Sea.Harmonics.h5 = "1.27,57.0,0.0702,82.28,188.00";
				Weathers.Sea.Harmonics.h6 = "2.27,57.0,0.0302,82.28,88.00";
				//Weathers.Sea.Harmonics.h7 = "2.27,37.0,0.1402,82.28,188.00";
				//Weathers.Sea.Harmonics.h8 = "2.77,17.0,0.0502,82.28,288.00";
				//Weathers.Sea.Harmonics.h9 = "1.77,17.0,0.1002,82.28,188.00";
				Weathers.Sea.Harmonics.h10 = "1.0,14.0,0.5002,82.28,28.00"; //
				if(Characters[GetMainCharacterIndex()].location !="")
				{
					Sea.MaxSeaHeight = 50.0;
				}
			}
		}
		else
		{
			if(bSeaActive && !ownDeckStarted())
			{
				Seafoam.storm = "false";
				//bstorm = false;
				if(Characters[GetMainCharacterIndex()].location !="")
				{
					//if(stf(Sea.MaxSeaHeight)!=3.0) {Sea.MaxSeaHeight = 3.0;traceandlog("waves heights restored");}
					float Maxheights = (wrain + winds) - 70;
					if(maxheights<3) Sea.MaxSeaHeight = 3.0;
					else Sea.MaxSeaHeight = Maxheights;
					if(wrain < 75) Sea.MaxSeaHeight = 3.0;
					//traceandlog("waves heights : " + Sea.MaxSeaHeight);	
				}
			}
		} //screwface : end
	}
	else
	{
		float wave1 = 5  + windStrength2 * 3;
		float wave2 = 10 + windStrength1 * 3;
		float wave3 = 10 + windStrength3 * 3;

		string waveLength1 = f2s(wave1, 4);
		string waveLength2 = f2s(wave2, 4);
		string waveLength3 = f2s(wave3, 4);

		Weathers.Sea.Harmonics.h1 = direction1 + "," + waveLength1 + "," + seaStrength1 + ",0," + waveSpeed;
		Weathers.Sea.Harmonics.h2 = direction2 + "," + waveLength2 + "," + seaStrength2 + ",0," + waveSpeed;
		Weathers.Sea.Harmonics.h3 = direction3 + "," + waveLength3 + "," + seaStrength3 + ",0," + waveSpeed;
	}

//	Whr_DebugInfo();
}


string f2s(float fl,int nDigAfterPoint)
{
	float fmul = pow(10.0,nDigAfterPoint);
	fl = fl + 0.5/fmul;
	int p1 = makeint(fl);
	int p2 = makeint((fl-p1)*fmul);
	if (p1 == 0 && p2 == 0) return fts(fl,nDigAfterPoint);
	string minusstr = ""; if(fl < 0) minusstr = "-";
	string decimal = "0000000000" + abs(p2);
	decimal = strRight(decimal,nDigAfterPoint);
	string retval = minusstr + abs(p1) + "." + decimal;
	while (strRight(retval,1) == "0") retval = strLeft(retval, strLen(retval)-1);
	if (strRight(retval,1) == ".")    retval = strLeft(retval, strLen(retval)-1);
	return retval;
}
