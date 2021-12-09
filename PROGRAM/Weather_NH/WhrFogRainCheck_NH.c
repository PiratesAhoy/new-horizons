#define FOGHEIGHTFACTOR 40.0

bool morningFogChecked = false; 
bool morningFog = false; 
int randomFog = 0; 

void Whr_FogRainCheck(){
//JL -------------------------------------------------------------

//  LDH more fog in mornings - 26Feb09


	int tempFog = fog;
	int theHour = GetHour();
	int fogchance = 0;

	trace("Fog value: " + fog + "weather hour: " + theHour);


	if (theHour <= 4 || theHour >= 10){
		morningFogChecked = false;
		morningFog = false;
	}
	if (theHour >= 5 && theHour <= 9){

		if (!morningFogChecked){
			fogchance = rand(100);
			morningFogChecked = true;
			randomFog = rand(6);
		}

		if (fogchance<65){
			morningFog = true;
		}else{
			morningFog = false;
		}

		if (morningfog){fog += 4 + randomFog - abs(theHour-7);}	// +8, 7, 6, 5, don't use random number here
	} 

//JRH -->
	ref PChar = GetMainCharacter();
	if(CheckAttribute(Pchar,"quest.JRH_rain"))
	{
		switch(Pchar.quest.JRH_rain)
		{
			case "Clear":
				wRain = 0;
				Fog = 0;
				//Log_SetStringToLog("JRH_rain = Clear");
				WhrDeleteRainEnvironment();			//JRH added june 2019	
			break;

			case "Cloudy":
				wRain = 60;
				//Log_SetStringToLog("JRH_rain = Cloudy");
			break;

			case "Overcast":
				wRain = 70;
				//Log_SetStringToLog("JRH_rain = Overcast");
			break;

			case "Rainy":
				wRain = 80;
				//Log_SetStringToLog("JRH_rain = Rainy");
			break;

			case  "Heavy Rain":
				wRain = 90;
				//Log_SetStringToLog("JRH_rain = Heavy Rain");
			break;

			case  "Stormy":
				wRain = 97;
			break;

			case "Heavy Storm":
				wRain = 100;
				Winds = 30;	// twisters start at minwind >= 28
			break;

			case  "Foggy":
				Fog = 15;		// produces fog density of 0.00375
				//Log_SetStringToLog("JRH_rain = Foggy");
			break;

			case  "Heavy Fog":
				Fog = 25;		// produces fog density of 0.00625
			break;

			case  "Black Pearl Fight":
				wRain = 90;
				Fog = 15;
			//	OWind = 25;
			break;

			case  "IslaDeMuerte":
				Fog = 80;		// produces fog density of 0.02
				//Log_SetStringToLog("JRH_rain = IslaDeMuerte");
			break;

			case  "Mine Fog 1":
				wRain = 0;
				Fog = 200;
				WeathersNH.Sea.Water.Color = argb(0,0,0,0);
			break;

			case  "Mine Fog 2":
				wRain = 0;
				Fog = 650;
				WeathersNH.Sea.Water.Color = argb(0,0,0,0);
			break;

			case  "Super Fog":
				Fog = 999;
			break;

			//Default
			//Log_SetStringToLog("JRH_rain = Default");
		}
	}
//<-- JRH
	WeathersNH.Lights = 0;

//  LDH more fog during rain - 26Feb09
	if (wRain > 75 && fog < 10) fog += (wRain-75);

	if (fog < MINIMUMFOG){fog=MINIMUMFOG}

	trace("Fog raincheck Fog: " + fog);

	WeathersNH.Fog.Enable = true;
	WeathersNH.Fog.Height = fog*fog*FOGHEIGHTFACTOR;				// LDH - 25Feb09
	WeathersNH.Fog.Start = 0.0;
	WeathersNH.Fog.Density = fog*FOGFACTOR;				// denser fog on land - 26Feb09
	WeathersNH.Fog.SeaDensity = fog*FOGFACTOR;
	WeathersNH.Fog.IslandDensity = fog*FOGFACTOR;
	WeathersNH.SpecialSeaFog.Enable = true;
	WeathersNH.SpecialSeaFog.Height = fog*fog*FOGHEIGHTFACTOR;			// LDH - 25Feb09
	WeathersNH.SpecialSeaFog.Start = 0.0;
	WeathersNH.SpecialSeaFog.Density = fog*FOGFACTOR;
	WeathersNH.SpecialSeaFog.SeaDensity = fog*FOGFACTOR;


// 	if ( fog >= MINIMUMFOG ){
// 		WeathersNH.Fog.Enable = true;
// 		WeathersNH.Fog.Height = (fog-4)*500.0*FOGHEIGHTFACTOR;				// LDH - 25Feb09
// 		WeathersNH.Fog.Start = 0.0;
// //		WeathersNH.Fog.Density = (fog*0.00025);
// 		WeathersNH.Fog.Density = (fog*0.0005)*FOGFACTOR;				// denser fog on land - 26Feb09
// 		WeathersNH.Fog.SeaDensity = (fog*0.00025)*FOGFACTOR;
// 		WeathersNH.Fog.IslandDensity = (fog*0.00025)*FOGFACTOR;
// 		WeathersNH.SpecialSeaFog.Enable = true;
// 		WeathersNH.SpecialSeaFog.Height = fog*400.0*FOGHEIGHTFACTOR;			// LDH - 25Feb09
// 		WeathersNH.SpecialSeaFog.Start = 0.0;
// 		WeathersNH.SpecialSeaFog.Density = (fog*0.00025)*FOGFACTOR;
// 		WeathersNH.SpecialSeaFog.SeaDensity = (fog*0.00025)*FOGFACTOR;
// 	}
// 	else{
// 		WeathersNH.Fog.Enable = true;
// 		WeathersNH.Fog.Height = 300.0*FOGHEIGHTFACTOR;
// 		WeathersNH.Fog.Start = 0.0;
// 		WeathersNH.Fog.Density = 0.001*FOGFACTOR;
// 		WeathersNH.Fog.SeaDensity = 0.001*FOGFACTOR;
// 		WeathersNH.Fog.IslandDensity = 0.001*FOGFACTOR;

// 		WeathersNH.SpecialSeaFog.Enable = true;
// 		WeathersNH.SpecialSeaFog.Height = 500.0*FOGHEIGHTFACTOR;
// 		WeathersNH.SpecialSeaFog.Start = 0.0;
// 		WeathersNH.SpecialSeaFog.Density = 0.001*FOGFACTOR;
// 		WeathersNH.SpecialSeaFog.SeaDensity = 0.001*FOGFACTOR;
		
// 	}

	if (fog > 10){
		WeathersNH.Lights = 1;
	}

	fog = tempFog;		// LDH 26Feb09

	WeathersNH.Rain = false;
	WeathersNH.Storm = false;
	WeathersNH.Tornado = false;
	WeathersNH.StormSky = false;
	bWeatherIsStorm = false;
	bWeatherIsRain = false;

	WeatherParams.Storm = false;
	WeatherParams.tornado = false;	

	WeathersNH.Rain.DropsNearNum = 500;
	WeathersNH.Rain.DropsFarNum = 500;
	WeathersNH.Rain.DropsNearRadius = 25.0;
	WeathersNH.Rain.DropsFarRadius = 75.0;
	WeathersNH.Rain.DropsLifeTime = 0.25;
	WeathersNH.Rain.DropsSize = 0.06;
	WeathersNH.Rain.DropsTexture = "weather\rain_drops.tga.tx";
	WeathersNH.Rain.DropsColor = argb(63,255,255,255);
	WeathersNH.Lightning.Enable = false;

	WeathersNH.Sun.Glow.Enable = true;
	WeathersNH.Sun.Flare.Enable = true;
	WeathersNH.Sun.Overflow.Enable = true;
	WeathersNH.Sun.Reflection.Enable = true;
	WeathersNH.Rainbow.Enable = false;

	if (wRain > 75)
	{
		WeatherParams.Rain = true;
		bWeatherIsRain = true; // screwface
		WeathersNH.Lightning.Enable = false;
		WeathersNH.Sky.Dir = "weather\skies\7\\";
		WeathersNH.Rain.NumDrops = ((wRain-75)*400);
		WeathersNH.Rain.Color = argb(0,73,73,73);
		WeathersNH.Rain.DropLength = (1.12);
		WeathersNH.Rain.Height = 30.0;
		WeathersNH.Rain.Radius = 30.0;
		WeathersNH.Rain.Speed = 12.0;
		WeathersNH.Rain.Jitter = 0.4;
		WeathersNH.Rain.WindSpeedJitter = (0.5);
		WeathersNH.Rain.MaxBlend = 75;
		WeathersNH.Rain.TimeBlend = 2000;

		if(theHour >= 5 && theHour < 23) {WeathersNH.Rainbow.Enable = true;}		//UZVER

		WeathersNH.Storm = false;
		WeathersNH.Sea.SunRoad.Power = 2.0;
		if(wRain > 80 && wRain < 85){
			WeathersNH.StormSky = true;
			WeathersNH.Rain.Speed = 14.0;
			WeathersNH.Rain.MaxBlend = 95;
			WeathersNH.Rain.DropLength = (1.5);
			WeathersNH.Lightning.Enable = false;
			WeathersNH.LightingLm = "storm";
			WeathersNH.Sea.SunRoad.Color1 = argb(0,0,0,0);
			WeathersNH.Sea.SunRoad.Color2 = argb(0,0,0,0);
			WeathersNH.Sea.Water.Color = argb(0,24,44,78);
			WeathersNH.Sky.Color = argb(0,220,220,255);
		}
		if(wRain >= 85 && wRain < 95){
			WeathersNH.Rain.Speed = 16.0;
			WeathersNH.Rain.MaxBlend = 115;
			WeathersNH.Rain.DropLength = (1.75);
			WeathersNH.Lightning.Enable = false;
			WeathersNH.Rainbow.Enable = false;
			WeathersNH.Sun.Glow.Enable = false;
			WeathersNH.Sun.Flare.Enable = false;
			WeathersNH.Sun.Overflow.Enable = false;
			WeathersNH.Sun.Reflection.Enable = false;
	        WeathersNH.LightingLm = "storm";
	        WeathersNH.InsideBack = "n";
			WeathersNH.Sea.SunRoad.Color1 = argb(0,0,0,0);
			WeathersNH.Sea.SunRoad.Color2 = argb(0,0,0,0);
			WeathersNH.Sea.Water.Color = argb(0,22,39,69);
			WeathersNH.Sky.Color = argb(0,210,210,255);
		}
		if(wRain >= 95){
			WeathersNH.StormSky = true;
			WeathersNH.Rain.Speed = 18.0;
			WeathersNH.Rain.MaxBlend = 129;
			WeathersNH.Rain.DropLength = (2.12);
			WeathersNH.Storm = true;
			WeatherParams.Storm = true;
			WeathersNH.Lights = 1;			
			bWeatherIsStorm = true;			
			WeathersNH.Lightning.Texture = "Weather\lightning\lightning_storm.tga.tx";
			WeathersNH.Lightning.FlickerTime = 32;
			WeathersNH.Lightning.SubTexX = 4;
			WeathersNH.Lightning.SubTexY = 1;
			WeathersNH.Lightning.ScaleX = 0.7;
			WeathersNH.Lightning.ScaleY = 1.0;
			WeathersNH.Lightning.Flash.Texture = "Weather\lightning\flash.tga.tx";
			WeathersNH.Lightning.Enable = true;
			WeathersNH.Sun.Glow.Enable = false;
			WeathersNH.Sun.Flare.Enable = false;
			WeathersNH.Sun.Overflow.Enable = false;
			WeathersNH.Sun.Reflection.Enable = false;
	        WeathersNH.LightingLm = "storm";
	        WeathersNH.InsideBack = "n";
			WeathersNH.Sea.SunRoad.Color1 = argb(0,0,0,0);
			WeathersNH.Sea.SunRoad.Color2 = argb(0,0,0,0);
			WeathersNH.Sea.Water.Color = argb(0,20,35,63);
			WeathersNH.Sky.Color = argb(0,200,200,255);
			WeathersNH.Rainbow.Enable = false;
			if(minwind >= 28){
				WeathersNH.Storm = true;
				WeathersNH.Tornado = true;
				WeatherParams.Storm = true;
				WeatherParams.tornado = true;
				if(!CheckAttribute(PChar, "skipWeatherLogs")) // PB
				// DeathDaisy added a string here instead off GetMyAddressForm, because I thought it would be weird if your crew called you Señor or similar
					string PCCaptainTitle;
					if(PChar.sex == "woman")
						PCCaptainTitle = "Ma'am";
					else
						PCCaptainTitle = "Sir";
					LogIt(PCCaptainTitle + ", she's coming onto blow!");
			}
		}
		WeathersNH.Rainbow.Texture = "weather\rainbow\rainbow.tga.tx;";
	}
	else
	{
		WeathersNH.Rain.NumDrops = 0;
		WeathersNH.Rain.Color = argb(0,73,73,73);
		WeathersNH.Rain.DropLength = 2.12;
		WeathersNH.Rain.Height = 30.0;
		WeathersNH.Rain.Radius = 30.0;
		WeathersNH.Rain.Speed = 18.0;
		WeathersNH.Rain.Jitter = 0.4;
		WeathersNH.Rain.WindSpeedJitter = 0.5;
		WeathersNH.Rain.MaxBlend = 49;
		WeathersNH.Rain.TimeBlend = 2000;

		WeathersNH.Rainbow.Enable = false;
		WeathersNH.Rainbow.Texture = "weather\rainbow\rainbow.tga.tx";
	}
}
