#define MAXFOG 20
#define FOGDECAY 2.0

void Whr_GenerateValues(int fogCheck){

// Screwface : Chance to have weather conditions degrade is according to the month and seasons in Caribbean
	int month = GetDataMonth();
	int rainrisk = 5;

	// trace("Month: " + month);
	switch(month)
	{
		case 1:  rainrisk = 10; break;
		case 2:  rainrisk = 5; break;
		case 3:  rainrisk = 5; break;
		case 4:  rainrisk = 5; break;
		case 5:  rainrisk = 15; break; // beginning of the wet season
		case 6:  rainrisk = 20; break;
		case 7:  rainrisk = 30; break;
		case 8:  rainrisk = 45; break;
		case 9:  rainrisk =100; break; // twister maximal risk
		case 10: rainrisk = 95; break; // twister maximal risk
		case 11: rainrisk = 35; break;
		case 12: rainrisk = 15; break; // dry season
	}
// Screwface : end

	if(rand(100) > (50 - windABallast)){
		if(fWeatherAngleOld <= PIm2 - rWindA){fWindA = fWeatherAngleOld + rWindA;}
		else{ fWindA = (fWeatherAngleOld + rWindA) - PIm2;}
		windABallast += (rWindA*5);
	}
	else{
		if(fWeatherAngleOld >= rWindA){ fWindA = fWeatherAngleOld - rWindA; }
		else{ fWindA = PIm2 - (rWindA - fWeatherAngleOld); }
		windABallast -= (rWindA*5);
		
	}
	
	if(rand(100) > (50 - rainBallast) && RAND(100) <= rainrisk){
		if(goldRain <= 100-rRain || (goldRain - rRain) < 0){wRain = goldRain + rRain; }
		else{ wRain = 100; }
		rainBallast += rRain;
	}
	else{
		if(goldRain >= rRain){ wRain = goldRain - rRain; }
		else{ wRain = 0; }
		rainBallast -= rRain;
	}
	
	if(fogCheck != 0){
		if(rand(100) > (50 - fogBallast)){
			if(goldFog <= (MAXFOG-rFog) || (goldFog - rFog) < 0){ goldFog = goldFog + rFog;}
			else{ goldFog = MAXFOG; }
			fogBallast += rFog;
		}
		else{
			if(goldFog >= rFog){ goldFog = goldFog - rFog;}
			else{ goldFog = 0; }
			fogBallast -= rFog;
		}
		if(wRain <= 60){
			if(goldFog >= 2){ fog = goldFog/FOGDECAY;}
			else{ fog = 0; }
		}
	}
	else{ fog = 0; }

	if(rand(100) > 50){
		if(oldWind <= 30-rWind || (oldWind - rWind) < 0){winds = oldWind + rWind;}
		else{ winds = 30; }
		windBallast += rWind;
	}
	else{
		if(oldWind >= rWind){winds = oldWind - rWind;}
		else{ winds = 0 };
		windBallast -= rWind;
	}
	// if (winds < 0) winds = 0;
	// if (winds < 5) winds = 15;	// LDH 12Feb09
	if (winds < 5) winds = 10;	// LDH 12Feb09

	//wRain = wRain + 20; // to test the coming of a storm
	//winds = 30;
	// screwface
	if(wRain >= 95)
	{
		WeatherParams.Storm = true;
	}
	if(wRain >= 98 && winds >= 28)
	{
		WeatherParams.tornado = true;
	}
	else 
	{
		WhrDeleteTornadoEnvironment();
	}
	// screwface : end
}
