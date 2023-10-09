void Whr_FogRainCheck(){
//JL -------------------------------------------------------------

//  LDH more fog in mornings - 26Feb09
	int tempFog = fog;
	int theHour = GetHour();
	if (theHour >= 6 && theHour < 10) fog += 14-theHour;	// +8, 7, 6, 5, don't use random number here

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
				Weathers.Sea.Water.Color = argb(0,0,0,0);
			break;

			case  "Mine Fog 2":
				wRain = 0;
				Fog = 650;
				Weathers.Sea.Water.Color = argb(0,0,0,0);
			break;

			case  "Super Fog":
				Fog = 999;
			break;

			//Default
			//Log_SetStringToLog("JRH_rain = Default");
		}
	}
//<-- JRH

//  LDH more fog during rain - 26Feb09
	if (wRain > 75 && fog < 10) fog += (wRain-75)/2;

	if ( fog >= 5 ){
		Weathers.Fog.Enable = true;
		Weathers.Fog.Height = (fog-4)*500.0;				// LDH - 25Feb09
		Weathers.Fog.Start = 0.0;
//		Weathers.Fog.Density = (fog*0.00025);
		Weathers.Fog.Density = (fog*0.0005);				// denser fog on land - 26Feb09
		Weathers.Fog.SeaDensity = (fog*0.00025);
		Weathers.SpecialSeaFog.Enable = true;
		Weathers.SpecialSeaFog.Height = fog*400.0;			// LDH - 25Feb09
		Weathers.SpecialSeaFog.Start = 0.0;
		Weathers.SpecialSeaFog.Density = (fog*0.00025);
		Weathers.SpecialSeaFog.SeaDensity = (fog*0.00025);
	}
	else{
		Weathers.Fog.Enable = true;
		Weathers.Fog.Height = 300.0;
		Weathers.Fog.Start = 0.0;
		Weathers.Fog.Density = 0.001;
		Weathers.Fog.SeaDensity = 0.001;

		Weathers.SpecialSeaFog.Enable = true;
		Weathers.SpecialSeaFog.Height = 1500.0;
		Weathers.SpecialSeaFog.Start = 0.0;
		Weathers.SpecialSeaFog.Density = 0.001;
		Weathers.SpecialSeaFog.SeaDensity = 0.001;
	}

	fog = tempFog;		// LDH 26Feb09

	if (wRain > 75)
	{
		bWeatherIsRain = true; // screwface
		Weathers.Lightning.Enable = false;
		Weathers.Sky.Dir = "weather\skies\7\\";
		Weathers.Rain.NumDrops = ((wRain-75)*400);
		Weathers.Rain.Color = argb(0,73,73,73);
		Weathers.Rain.DropLength = (1.12);
		Weathers.Rain.Height = 30.0;
		Weathers.Rain.Radius = 30.0;
		Weathers.Rain.Speed = 12.0;
		Weathers.Rain.Jitter = 0.4;
		Weathers.Rain.WindSpeedJitter = (0.5);
		Weathers.Rain.MaxBlend = 75;
		Weathers.Rain.TimeBlend = 2000;
		Weathers.Storm = false;
		Weathers.Sea.SunRoad.Power = 2.0;
		if(wRain > 80 && wRain < 85){
			Weathers.Rain.Speed = 14.0;
			Weathers.Rain.MaxBlend = 95;
			Weathers.Rain.DropLength = (1.5);
			Weathers.Lightning.Enable = false;
			if(theHour >= 6 && theHour < 20) {Weathers.Rainbow.Enable = true;}		//UZVER
			Weathers.LightingLm = "storm";
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Sea.Water.Color = argb(0,24,44,78);
			Weathers.Sky.Color = argb(0,220,220,255);
		}
		if(wRain >= 85 && wRain < 95){
			Weathers.Rain.Speed = 16.0;
			Weathers.Rain.MaxBlend = 115;
			Weathers.Rain.DropLength = (1.75);
			Weathers.Lightning.Enable = false;
			Weathers.Rainbow.Enable = false;
			Weathers.Sun.Glow.Enable = false;
			Weathers.Sun.Flare.Enable = false;
			Weathers.Sun.Overflow.Enable = false;
			Weathers.Lights = false;
	        Weathers.LightingLm = "storm";
	        Weathers.InsideBack = "n";
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Sea.Water.Color = argb(0,22,39,69);
			Weathers.Sky.Color = argb(0,210,210,255);
		}
		if(wRain >= 95){
			Weathers.Rain.Speed = 18.0;
			Weathers.Rain.MaxBlend = 129;
			Weathers.Rain.DropLength = (2.12);
			Weathers.Storm = true;
			Weathers.Lightning.Texture = "Weather\lightning\lightning_storm.tga";
			Weathers.Lightning.FlickerTime = 32;
			Weathers.Lightning.SubTexX = 4;
			Weathers.Lightning.SubTexY = 1;
			Weathers.Lightning.ScaleX = 0.7;
			Weathers.Lightning.ScaleY = 1.0;
			Weathers.Lightning.Flash.Texture = "Weather\lightning\flash.tga";
			Weathers.Lightning.Enable = true;
			Weathers.Sun.Glow.Enable = false;
			Weathers.Sun.Flare.Enable = false;
			Weathers.Sun.Overflow.Enable = false;
	        Weathers.LightingLm = "storm";
	        Weathers.InsideBack = "n";
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Sea.Water.Color = argb(0,20,35,63);
			Weathers.Sky.Color = argb(0,200,200,255);
			Weathers.Rainbow.Enable = false;
			if(minwind >= 28){
				Weathers.Storm = true;
				Weathers.Tornado = true;
				Weathers.Lights = false;
				if(!CheckAttribute(PChar, "skipWeatherLogs")) // PB
				// DeathDaisy added a string here instead off GetMyAddressForm, because I thought it would be weird if your crew called you Señor or similar
					string PCCaptainTitle;
					if(PChar.sex == "woman")
						PCCaptainTitle = FirstLetterUp(XI_ConvertString("ma'am"));
					else
						PCCaptainTitle = FirstLetterUp(XI_ConvertString("sir"));
					LogIt(PCCaptainTitle + ", " + TranslateString("","she's coming onto blow!"));
			}
		}
		Weathers.Rainbow.Texture = "weather\rainbow\rainbow.tga";
	}
	else
	{
		Weathers.Rain.NumDrops = 0;
		Weathers.Rain.Color = argb(0,73,73,73);
		Weathers.Rain.DropLength = 2.12;
		Weathers.Rain.Height = 30.0;
		Weathers.Rain.Radius = 30.0;
		Weathers.Rain.Speed = 18.0;
		Weathers.Rain.Jitter = 0.4;
		Weathers.Rain.WindSpeedJitter = 0.5;
		Weathers.Rain.MaxBlend = 49;
		Weathers.Rain.TimeBlend = 2000;

		Weathers.Rainbow.Enable = false;
		Weathers.Rainbow.Texture = "weather\rainbow\rainbow.tga";
	}
}
