#include "Weather_NH\WhrGenerateValues_NH.c"
#include "Weather_NH\WhrFogRainCheck_NH.c"
#include "Weather_NH\WhrDebugInfo_NH.c"

#define GENERATIONDEBUG 0
#define RANDOMDEBUG 1

#define WIND2WAVESPEED 0.25
#define WIND2WAVELENGTH 6.0
#define WIND2AMPLITUDE 0.3

#define RAIN2AMPLITUDE 2.0
#define RAIN2WIND 1.0

#define WIND2WAVELENGTH2 1.5
#define WIND2AMPLITUDE2 0.1
#define WIND2BUMPSCALE 1.0
#define WIND2FOAMV 0.175

#define AMPLITUDERANDOM 0.4
#define SCALERANDOM 0.4
#define FOAMRANDOM 0.025

#define NIGHTCOLORBLEND 6.0

#define SHORECOLORDISTANCE 20.0

#define MINIMUMFOG 2
#define FOGFACTOR 0.0003
#define FOG2TRANSPARENCY 150.0


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

void Whr_Generator(int iHour){
// ====================================================================
// JL - Less Random Weather Generator -- hopefully
// ====================================================================

	bool bWhrTornado = false;
	bool bWhrStorm = false;
	
	if(gWeatherInit == 1){
		goldRain = rand(100);
		goldFog = rand(20);
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
	curTime = iHour; //Causing problems
	bWeatherIsStorm = false; // screwface
	bWeatherIsRain = false; // screwface

	rWind = rand(MAX_WINDCHANGE);
	rFog = rand(MAX_FOGCHANGE); 
	rRain = rand(MAX_RAINCHANGE);
	rWindA = frand(MAX_ANGLECHANGE);
	
	Whr_GenerateValues(FREE_FOG);
	
	//--Testing Settings--------------------------------------------------------
	
	// wRain = 0;
	// fog = 20;
	//curTime = 6;
	// winds = 30;
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
		fog = 30;
		bWeatherIsStorm = true; // screwface
	}
	if(bWhrTornado){
		wRain = 100;
		winds = 30;
		windBallast = 20;
		rainBallast = 20;
		fog = 40;
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
	if(fog > 0 && curTime >= 6 && curTime <= 22 && wRain <= 60){fogBallast = -30;}
	if(fogBallast < 0 && curTime > 22 || curTime < 6){fogBallast = 0;}
	if(fogBallast < 0 && curTime >= 6 && curTime <=22 && wRain > 60){fogBallast = 0;}
	
	minwind = winds - rand(2);
	maxwind = winds + rand(2);
	if(minwind < 5){minwind = 5;}	// LDH up from 0 - 12Feb09
	if(maxwind > 30){maxwind = 30;}
	if(minwind > maxwind){ minwind = maxwind; } // JL - Temporary catch all for weird wind bug
	
	// Whr_InitGValues(); //Setup generic values based on ToD
	Whr_FogRainCheck();	 //Set wRain and fog values

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
	WeathersNH.Wind.Angle = fWindA;
	WeathersNH.Wind.Speed.Min = minwind;
	WeathersNH.Wind.Speed.Max = maxwind;
	float seaWindSpeed = Whr_GetFloat(WeathersNH,"Wind.Speed");
	WeathersNH.Wind.seaWindSpeed = seaWindSpeed;

	// trace("winds: " + winds + " Realized winds" + seaWindSpeed);

	float effectiveRain = (wRain-70)*RAIN2WIND;
	if (effectiveRain < 0) effectiveRain = 0;

	// Bupmscale the sea grainyness
	float bumpscale = 0.04 + frnd()*0.075;
	WeathersNH.Sea2.BumpScale = bumpscale;
	WeathersNH.Sea2.PosShift = 1.0;

	// Wave amplitude
	float Amp1rand = 2.0*(frnd()-0.5)*AMPLITUDERANDOM + 1.0;
	float Amp1 = (4.0 + WIND2AMPLITUDE*(seaWindSpeed*Amp1rand + RAIN2AMPLITUDE*effectiveRain));
	WeathersNH.Sea2.Amp1 = Amp1;
	WeathersNH.Sea2.AnimSpeed1 = 4.0;

	// Wave Length
	float Scale1rand = 2.0*(frnd()-0.5)*SCALERANDOM + 1.0;
	float scale1 = WIND2WAVELENGTH/(seaWindSpeed + effectiveRain);
	if (scale1 > 1.0) {scale1 = 1.0;}
	scale1 = scale1*Scale1rand; 
	WeathersNH.Sea2.Scale1 = scale1;


	string waveSpeedX = f2s(-WIND2WAVESPEED*(seaWindSpeed + effectiveRain)*sin(fWindA), 2);
	string waveSpeedZ = f2s(-WIND2WAVESPEED*(seaWindSpeed + effectiveRain)*cos(fWindA), 2);
	WeathersNH.Sea2.MoveSpeed1 = waveSpeedX + ", 0.0, " + waveSpeedZ;

	// Amplitude 2
	float Amp2rand = 2.0*(frnd()-0.5)*AMPLITUDERANDOM + 1.0;
	float Amp2 = 1 + WIND2AMPLITUDE*WIND2AMPLITUDE2*(seaWindSpeed + effectiveRain);
	WeathersNH.Sea2.Amp2 = Amp2*Amp2rand;
	WeathersNH.Sea2.AnimSpeed2 = 4.0;

	// Wavelength 2
	float Scale2rand = 2.0*(frnd()-0.5)*SCALERANDOM + 1.0;
	WeathersNH.Sea2.Scale2 = WIND2WAVELENGTH*WIND2WAVELENGTH2/(seaWindSpeed + effectiveRain)*Scale2rand;


	// float randomDir = frnd()*PI;
	// trace("random dir: " + randomDir);
	string waveSpeed2X = f2s(-WIND2WAVESPEED*WIND2WAVELENGTH2*(seaWindSpeed + effectiveRain)*sin(fWindA), 2);
	string waveSpeed2Z = f2s(-WIND2WAVESPEED*WIND2WAVELENGTH2*(seaWindSpeed + effectiveRain)*cos(fWindA), 2);
	WeathersNH.Sea2.MoveSpeed2 = waveSpeed2X + ", 0.0, " + waveSpeed2Z;

	// Foam properties
	float foamrand = 2.0*(frnd()-0.5)*FOAMRANDOM;
	WeathersNH.Sea2.FoamV = Amp1*(0.6 + foamrand);
	WeathersNH.Sea2.FoamK = 0.1 - 0.05*effectiveRain/RAIN2WIND/25.0;
	WeathersNH.Sea2.FoamUV = scale1*2.0;
	WeathersNH.Sea2.FoamTexDisturb = 0.2;

	// Sea properties
	WeathersNH.Sea2.Attenuation = 0.2;

	float fblend = 0;
	float fblend2 = 0;

	float transparency  = 0.5;

	// Evening

	if (curTime>=18 || curTime<=22)
	{
		fblend = 0.3;
	}	
	if (curTime==23 || curTime==5)
	{
		fblend = 0.75;
	}
	// Morning
	if (curTime>=6 || curTime<=10)
	{
		fblend = 0.3;
	}
	// Night
	if (curTime <=4)
	{
		fblend = 1;
		transparency = 0;
	}



	// Apply fog and rain to transparency
	effectiveRain = (wRain-70)/30.0;
	if (effectiveRain < 0) effectiveRain = 0;

	float fog2trans = (Whr_GetFloat(WeathersNH, "Fog.SeaDensity")-MINIMUMFOG*FOGFACTOR)*FOG2TRANSPARENCY + effectiveRain;
	transparency = transparency - fog2trans;
	trace("Fog to transparency: " + fog2trans);

	if (transparency < 0) transparency = 0.0;
	if (fog2trans > 1) fog2trans = 1.0;

	// Create blending constant for water color and fog color
	fblend2 = 0.40 - fog2trans;


	// Assume that the water is shore water	
	int WaterColor = waterColor_shore();

	// Darken and make opaque it for evening and night
	int darkWater = argb(0,28,28,28);
	int grayWater = argb(0,100,100,100);

	WaterColor = Whr_BlendColor( fog2trans*0.8, WaterColor, grayWater);

	// Correct it, if it open sea
	float closestdist = 0.0;
	if (CheckAttribute(worldMap, "directsail1.closestdist")){
		if (RANDOMDEBUG) trace("weather Char location: " + pchar.location + " closest island: " + worldMap.closestisland + "Closest distance: " + worldMap.directsail1.closestdist);
		closestdist = worldMap.directsail1.closestdist;
		if (RANDOMDEBUG) trace("closestdist: " + closestdist + "conditional: " + SHORECOLORDISTANCE);
	}else{
		if (RANDOMDEBUG) trace("weather Char location: " + pchar.location);
	}	

	int darkgrayWater = argb(0,20,20,20);
	if (pchar.location == WDM_NONE_ISLAND || closestdist > SHORECOLORDISTANCE)
	{
		WaterColor = waterColor_openSea();
		WaterColor = Whr_BlendColor( fog2trans*0.8, WaterColor, darkgrayWater);		
	}else{
		// If not open sea reduce the amount of water color and fog color
		fog2trans = (Whr_GetFloat(WeathersNH, "Fog.SeaDensity")-MINIMUMFOG*FOGFACTOR)*FOG2TRANSPARENCY + effectiveRain;
		transparency = 1.2 - fog2trans;
		if (transparency < 0) transparency = 0.0;
		if (fog2trans > 1) fog2trans = 1.0;		
		fblend2 = fblend2 - 0.05;
	}


	WaterColor = Whr_BlendColor( fblend, WaterColor, darkWater);
	WeathersNH.Sea2.WaterColor = WaterColor;
	WeathersNH.Sea2.Transparency = transparency;

	// Apply fog to Frenel and Reflection
	WeathersNH.Sea2.Frenel = 0.25 + frnd()*0.25;
	WeathersNH.Sea2.Reflection = 0.8 + frnd()*0.25 - fog2trans*0.5;

	// Stars and planets
	WeathersNH.Planets.enable = false;
	WeathersNH.Stars.Enable = false;

	WeathersNH.Stars.Texture = "weather\astronomy\stars.tga.tx";
	WeathersNH.Stars.Color = argb(0, 255, 255, 255);
	WeathersNH.Stars.Radius = 2000.0;
	WeathersNH.Stars.HeightFade = 200.0;
	WeathersNH.Stars.SunFade = 1.0;
	float starSize = 30.0;
	float VisualMagnitude = 15;

	// Determine the skybox to use
	string skydir;

	trace("CurTime: " + curTime);
	// Night
	if (curTime >= 1 && curTime <= 3 ) {
		skydir = skydir_night();
		WeathersNH.Planets.enable = true;
		WeathersNH.Stars.Enable = true;	
	}

	//Twilight
	if (curTime==23 || curTime==5) {
		skydir = skydir_twilight1();
		VisualMagnitude = 5.0;
		starSize = 20.0;
		WeathersNH.Sun.Flare.Enable = false;			
		WeathersNH.Sun.Overflow.Enable = false;			
	}
	if (curTime==0 || curTime==4) {
		skydir = skydir_twilight2();
		VisualMagnitude = 10.0;
		starSize = 25.0;
		WeathersNH.Sun.Flare.Enable = false;			
		WeathersNH.Sun.Overflow.Enable = false;			
	}
	if (curTime==23 || curTime==0 || curTime==4 || curTime==5){
		if (wRain > 80) {skydir_night();}
		WeathersNH.Planets.enable = true;
		WeathersNH.Stars.Enable = true;
		WeathersNH.Sun.Flare.Enable = false;			
		WeathersNH.Sun.Overflow.Enable = false;
		}

	if (wRain >60){
		WeathersNH.Planets.enable = false;
		WeathersNH.Stars.Enable = false;			
	}

	// Morning day and afternoon
	if (curTime == 6 && curTime == 22 ) {
		WeathersNH.Planets.enable = true;	
	}
	if (curTime >= 6 && curTime <= 10 ) {skydir = skydir_morningAFternoon();}
	if (curTime >= 18 && curTime <= 22 ) {skydir = skydir_morningAFternoon();}
	// Hand picked sunset skybox sometimes (currently 20%)
	if (curTime == 22 || curTime == 6) {
		if (rand(100)<20){skydir = "weather\skies\22\";}
	}

	if (curTime >= 11 && curTime <= 17 ) {skydir = skydir_day();}

	if (curTime >= 6 && curTime <= 22 && wRain >60 ) {skydir = skydir_day_overcast();}

	WeathersNH.Sky.Dir = skydir;

	if (RANDOMDEBUG) Trace("Sky.Dir generation: " + Whr_GetString(WeathersNH, "Sky.Dir"));

	// Blend fog between day and night
	int lightfog = argb(0,160,160,180);
	int darkfog = argb(0,0,0,0);


	int fogcolor = Whr_BlendColor(fblend, lightfog, darkfog);
	
	// Tint it with the water color
	if (fblend2<0.0) fblend2 = 0.0;
	fogcolor = Whr_BlendColor(fblend2, fogcolor, WaterColor);

	// Sky color including dawn and dusk

	// Light brightness
	int darkSky = argb(0,60,60,60);
	int lightSky = argb(0,255,255,255);
	int SkyColor = Whr_BlendColor(fblend, lightSky, darkSky);
	

	int dawnduskfogcolor;
	int dawnDuskSky;
	// Dawn or dusk fogs and sun color
	if (!morningFog){
		if (curTime == 22 || curTime == 6)
		{
			dawndusk_fog(&dawnduskfogcolor, &dawnDuskSky);
			fogcolor = Whr_BlendColor(fog2trans, dawnduskfogcolor, fogcolor);
			SkyColor = Whr_BlendColor(fog2trans, dawnDuskSky, SkyColor);
			WeathersNH.Fog.Height = Whr_GetFloat(WeathersNH, "Fog.Height") + 1000.0;
			WeathersNH.SpecialSeaFog.Height = Whr_GetFloat(WeathersNH, "SpecialSeaFog.Height") + 1000.0;
		} 
	}

	WeathersNH.Sea2.SkyColor = SkyColor;
	WeathersNH.Fog.Color = fogColor;
	WeathersNH.SpecialSeaFog.Color = fogColor;

	// if (RANDOMDEBUG) Whr_DebugInfo();


	WeathersNH.Stars.Size = starSize + frnd()*15.0;
	WeathersNH.Stars.VisualMagnitude = VisualMagnitude;	


	WeathersNH.Night = false;
	if (curTime <= 5 || curTime==23) {WeathersNH.Night = true;}

	// New moon reflection
	if (getMoonState() == NEW_MOON){
		if (curTime <= 5 || curTime==23){
			WeathersNH.Sun.Reflection.Enable = false;
			WeathersNH.Sun.Overflow.Enable = false;		}
	}

	if (GENERATIONDEBUG){

		trace("WeathersNH.Sea2.Amp:" + WeathersNH.Sea2.Amp1 + ", " + WeathersNH.Sea2.Amp2);
		trace("WeathersNH.Sea2.AnimSpeed:" + WeathersNH.Sea2.AnimSpeed1+ ", " + WeathersNH.Sea2.AnimSpeed2);
		trace("WeathersNH.Sea2.Scale:" + WeathersNH.Sea2.Scale1 + ", " + WeathersNH.Sea2.Scale2);
		trace("WeathersNH.Sea2.MoveSpeed:" + WeathersNH.Sea2.MoveSpeed1 + ", " + WeathersNH.Sea2.MoveSpeed2);

		trace("WeathersNH.Sea2.FoamV:" + WeathersNH.Sea2.FoamV);
		trace("WeathersNH.Sea2.FoamK:" + WeathersNH.Sea2.FoamK);
		trace("WeathersNH.Sea2.FoamUV:" + WeathersNH.Sea2.FoamUV);
		trace("WeathersNH.Sea2.FoamTexDisturb:" + WeathersNH.Sea2.FoamTexDisturb);


		
	}

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

//--------------------------------------------------------------------------------
// Sky randomizers (Quiet-Sun)

string skydir_twilight1()
{

	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = 0; //rand(1);
	if (RANDOMDEBUG) Trace("skydir_twilight random number: " + skyNumber);

	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\23\";
        break;
	}

	return skydirr;
}

string skydir_twilight2()
{

	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = rand(2);
	if (RANDOMDEBUG) Trace("skydir_twilight2 random number: " + skyNumber);

	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\01\";
        break;
    case 1:
        skydirr = "weather\skies\05\";
        break;
    case 2:
        skydirr = "weather\skies\24\";
        break;
	}

	return skydirr;
}

string skydir_morningAFternoon()
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = rand(3);
	if (RANDOMDEBUG) Trace("skydir_morningAFternoon random number: " + skyNumber);

	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\07\";
        break;
    case 1:
        skydirr = "weather\skies\08\";
        break;
    case 2:
        skydirr = "weather\skies\09\";
        break;
    case 3:
        skydirr = "weather\skies\20\";
        break;
	}

	return skydirr;
}

string skydir_day()
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = rand(3);
	if (RANDOMDEBUG) Trace("skydir_day random number: " + skyNumber);

	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\10\";
        break;
    case 1:
        skydirr = "weather\skies\13\";
        break;
    case 2:
        skydirr = "weather\skies\16\";
        break;
    case 3:
        skydirr = "weather\skies\18\";
        break;
	}

	return skydirr;
}

string skydir_night()
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = 0;  // Zero for a single option
	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\03\";
        break;
	}

	return skydirr;
}


string skydir_day_overcast()
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int skyNumber = rand(3);
	if (RANDOMDEBUG) Trace("skydir_day_overcast random number: " + skyNumber);
	
	string skydirr;
	switch(skyNumber)
    {
    case 0:
        skydirr = "weather\skies\storm1\";
        break;
    case 1:
        skydirr = "weather\skies\storm2\";
        break;
    case 2:
        skydirr = "weather\skies\storm3\";
        break;
    case 3:
        skydirr = "weather\skies\storm4\";
        break;		
	}

	return skydirr;
}

//--------------------------------------------------------------------------------
// Color randomizers (Quiet-Sun)

int waterColor_shore()
{

	// Random number for the case, if you add more colors be sure to match the number of cases
	int colorNumber = rand(6);
	if (RANDOMDEBUG) Trace("waterColor_shore random number: " + colorNumber);

	int waterColor;
	switch(colorNumber)
    {
    case 0:
        waterColor = argb(0,0,145,137);
        break;
    case 1:
        waterColor = argb(0,2,147,153);
        break;
    case 2:
        waterColor = argb(0,2,147,153);
        break;
    case 3:
        waterColor = argb(0,8,144,177);
        break;
    case 4:
        waterColor = argb(0,5,138,181);
        break;
    case 5:
        waterColor = argb(0,12,134,183);
        break;
    case 6:
        waterColor = argb(0,94,123,151);
        break;
	}

	return waterColor;
}


int waterColor_openSea()
{

	// Random number for the case, if you add more colors be sure to match the number of cases
	int colorNumber = rand(11);
	if (RANDOMDEBUG) Trace("waterColor_openSea random number: " + colorNumber);

	int waterColor;
	switch(colorNumber)
    {
    case 0:
        waterColor = argb(0,25,55,80);
        break;
    case 1:
        waterColor = argb(0,23,84,128);
        break;
    case 2:
        waterColor = argb(0,70,95,120);
        break;
    case 3:
        waterColor = argb(0,33,49,73);
        break;
    case 4:
        waterColor = argb(0,11,53,64);
        break;
    case 5:
        waterColor = argb(0,50,70,90);
        break;
    case 6:
        waterColor = argb(0,45,80,90);
        break;
    case 7:
        waterColor = argb(0,20,65,90);
        break;
    case 8:
        waterColor = argb(0,60,95,110);
        break;
    case 9:
        waterColor = argb(0,55,85,95);
        break;
    case 10:
        waterColor = argb(0,2,77,141);
        break;
    case 11:
        waterColor = argb(0,7,84,103);
        break;
	}

	return waterColor;
}


//--------------------------------------------------------------------------------
// Dawn/dusk randomizers (Quiet-Sun)

void dawndusk_fog(ref dawnDuskFogColor, ref dawnDuskskyColor)
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int fogNumber = rand(1);
	if (RANDOMDEBUG) Trace("dawndusk_fog random number: " + fogNumber);

	switch(fogNumber)
    {
    case 0:
        // dawnDuskFogColor = argb(0,143,68,58);
        dawnDuskFogColor = argb(0,153,113,107);
		dawnDuskskyColor = argb(0,255,221,179);
        break;
    case 1:
        dawnDuskFogColor = argb(0,85,85,105);
		dawnDuskskyColor = argb(0,216,216,255);
        break;
	}

}