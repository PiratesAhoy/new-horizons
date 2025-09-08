void Whr_InitGValues()
{
	// Sea colours adjusted to compensate for the Intel fix, which disables reflections. Armada
	bool IntelCard = FindFile("", "*.txt", "IntelCard.txt") != "");
	
	// Mirsaneli add: random sea presets
	float fWind = winds; // <-- make sure this is defined in scope
	string sPreset = WhrGetSeaPresetFromWind();
	WhrSetSeaPreset(&Weathers, fWind, sPreset);
	Whr_SetWaterColor();

	if ( curTime >= 10 && curTime < 18)
	{
		Weathers.id = "Blue Sky";
		Weathers.Hour.Min = 10;
		Weathers.Hour.Max = 17;
		Weathers.Lighting = "day1";
		Weathers.LightingLm = "day";
		Weathers.InsideBack = "d";

		Weathers.Sky.Dir = "weather\\skies\\Converted\\Blue 3\\";
		Weathers.Sky.Color = argb(0,255,255,255);
		Weathers.Sky.Angle = 0.0;
		
		Weathers.Sun.Color = argb(0,160,120,98);
		Weathers.Sun.Ambient = argb(0,100,90,80);
		Weathers.Sun.AzimuthAngle = Degree2Radian(90.0);
		Weathers.Sun.HeightAngle = 0.95;

		Weathers.Sun.Glow.Enable = true;
		Weathers.Sun.Overflow.Enable = false;
		Weathers.Sun.Overflow.Texture = "Weather\\lightning\\flash.tga";
		Weathers.Sun.Overflow.Color = argb(0, 100, 100, 100);
		Weathers.Sun.Overflow.Size = 5500.0;
		Weathers.Sun.Overflow.Technique = "sunoverflow";
		Weathers.Sun.Overflow.Start = 0.7;

		Weathers.Sun.Flare.Enable = true;

		Weathers.Sea2.GF2MX.Sky.Color = argb(0,100,150,195);
		Weathers.Sea2.GF2MX.Water.Color = argb(0,0,5,10);
		Weathers.Sea2.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea2.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea2.GF2MX.Bump.Dir = "weather\\sea\\bump_g2mx\\";

		/*
		Weathers.Sea2.Transparency = 0.2;
		Weathers.Sea2.FrenelCoefficient = 0.3;
		Weathers.Sea2.WaterReflection = 0.8;
		Weathers.Sea2.WaterAttenuation = 0.4;
		Weathers.Sea2.Sky.Color = argb(0,240,240,240);
		*/

		Weathers.Sea2.Pena.Color = argb(0,200,200,200);

		Weathers.Sea2.Bump.Dir = "resource\\textures\\weather\\sea\\bump_g3\\"; 
		Weathers.Sea2.Bump.Tile = 0.05;
		Weathers.Sea2.Bump.Ang = 0.0;
		Weathers.Sea2.Bump.Speed = 0.01;
		Weathers.Sea2.Bump.AnimSpeed = 20.0;
		Weathers.Sea2.Bump.Scale = 2.0;

		Weathers.Sea2.SunRoad.Start = 0.99;
		Weathers.Sea2.SunRoad.Color1 = argb(0,128,55,0);
		Weathers.Sea2.SunRoad.Color2 = argb(0,255,200,150);
		Weathers.Sea2.SunRoad.Power = 0.25;

		if(Whr_IsStorm()){
			Weathers.Fog.Color = argb(0,162,152,155);
			Weathers.SpecialSeaFog.Color = argb(0,60,50,57);
		}
		else{
			Weathers.Fog.Color = argb(0,162,152,155);
			Weathers.SpecialSeaFog.Color = argb(0,100,150,195);
		}
		Weathers.Lights = false;
		Weathers.Night = false;
	}

	if ( curTime >= 18 && curTime < 22)
	{
		Weathers.id = "Red Sky";
		Weathers.Hour.Min = 18;
		Weathers.Hour.Max = 21;
		Weathers.Lighting = "evening2";
		Weathers.LightingLm = "evening";
		Weathers.InsideBack = "e";

		Weathers.Sky.Dir = "weather\skies\Converted\Sunset 1\\"; // Using converted textures AoP
		Weathers.Sky.Color = argb(0,255,255,255);
		Weathers.Sky.Angle = 2.2;

		Weathers.Sun.Color = argb(0,255,141,55);
//		Weathers.Sun.Ambient = argb(0,66,33,33);
//		Weathers.Sun.Ambient = argb(0,128,80,80);		// LDH 22Feb09
		Weathers.Sun.Ambient = argb(0,70,60,65);		// LDH test 23Feb09
		Weathers.Sun.AzimuthAngle = Degree2Radian(180.0);
		Weathers.Sun.HeightAngle = 0.20;

		Weathers.Sun.Glow.Enable = true;

		Weathers.Sun.Overflow.Enable = false;	// this is never set to true
		Weathers.Sun.Overflow.Texture = "Weather\lightning\flash.tga";
		//Weathers.Sun.Overflow.Texture = "weather\sun\overflow\overflow.tga";
		Weathers.Sun.Overflow.Color = argb(0, 255, 255, 255);
		Weathers.Sun.Overflow.Size = 5500.0;
		Weathers.Sun.Overflow.Technique = "sunoverflow";
		Weathers.Sun.Overflow.Start = 0.84;

		Weathers.Sun.Flare.Enable = true;

		Weathers.Sea2.GF2MX.Sky.Color = argb(0,70,40,30);
		Weathers.Sea2.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea2.GF2MX.Bump.Tile = 0.05; //0.04
		Weathers.Sea2.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea2.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		/*
		Weathers.Sea2.Transparency = 0.2; //0.4
		Weathers.Sea2.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea2.WaterReflection = 0.8; //0.7
		Weathers.Sea2.WaterAttenuation = 0.4; //0.8
		Weathers.Sea2.Sky.Color = argb(0,255,255,255);
		*/
		
//		Weathers.Sea2.Pena.Color = argb(0,255,100,70);
		Weathers.Sea2.Pena.Color = argb(0,200,200,200);		// LDH 02Mar09 0,70,50,50

		Weathers.Sea2.Bump.Dir = "resource\textures\weather\sea\bump_g3\\";
		Weathers.Sea2.Bump.Tile = 0.05; //0.04
		Weathers.Sea2.Bump.Ang = 0.0; //1.0
		Weathers.Sea2.Bump.Speed = 0.01;
		Weathers.Sea2.Bump.AnimSpeed = 20.0;
		Weathers.Sea2.Bump.Scale = 2.0;

		Weathers.Sea2.SunRoad.Start = 0.99;
		Weathers.Sea2.SunRoad.Color1 = argb(0,255,88,44);
		Weathers.Sea2.SunRoad.Color2 = argb(0,255,200,55);
		Weathers.Sea2.SunRoad.Power = 3.0;

//		Weathers.Fog.Color = argb(0,123,83,71);
//		Weathers.SpecialSeaFog.Color = argb(0,123,83,71);	// default
		Weathers.Fog.Color = argb(0,76,60,65);				// LDH test 23Feb09
		Weathers.SpecialSeaFog.Color = argb(0,76,60,65);	// LDH test 23Feb09
		Weathers.Lights = false;
		Weathers.Night = false;
	}

	if ( curTime >= 22 && curTime < 24)
	{
		Weathers.id = "Moon Night";
		Weathers.Hour.Min = 22;
		Weathers.Hour.Max = 23;
		Weathers.Lighting = "night1";
		Weathers.LightingLm = "storm";
		Weathers.InsideBack = "n";

		Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\"; //Using converted textures AoP
		Weathers.Sky.Color = argb(0,200,200,255);
		Weathers.Sky.Angle = 1.45;

		Weathers.Sun.Color = argb(0,170,195,255);
		Weathers.Sun.Ambient = argb(0,12,23,33);
		Weathers.Sun.AzimuthAngle = Degree2Radian(0.0);
		Weathers.Sun.HeightAngle = 0.15;

		Weathers.Sun.Glow.Enable = false;

		Weathers.Sun.Overflow.Enable = false;

		Weathers.Sun.Flare.Enable = false;

		Weathers.Sea2.GF2MX.Sky.Color = argb(0,29,30,47);
		Weathers.Sea2.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea2.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea2.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea2.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		/*
		Weathers.Sea2.Transparency = 0.2; //0.4
		Weathers.Sea2.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea2.WaterReflection = 0.8; //0.7
		Weathers.Sea2.WaterAttenuation = 0.4; //0.8
		Weathers.Sea2.Sky.Color = argb(0,200,200,255);
		*/
		
		Weathers.Sea2.Pena.Color = argb(0,200,200,200); //0,50,50,80

		Weathers.Sea2.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea2.Bump.Tile = 0.05;
		Weathers.Sea2.Bump.Ang = 0.0;
		Weathers.Sea2.Bump.Speed = 0.01;
		Weathers.Sea2.Bump.AnimSpeed = 15.0;
		Weathers.Sea2.Bump.Scale = 2.0;

		Weathers.Sea2.SunRoad.Start = 0.995;
		Weathers.Sea2.SunRoad.Color1 = argb(0,55,55,100);
		Weathers.Sea2.SunRoad.Color2 = argb(0,255,255,255);
		Weathers.Sea2.SunRoad.Power = 3.0;

		Weathers.Fog.Color = argb(0,11,11,22);
		Weathers.SpecialSeaFog.Color = argb(0,11,11,22);
		Weathers.Lights = true;
		Weathers.Night = true;
		Weathers.Rainbow.Enable = false;
	}

	if ( curTime >= 0 && curTime < 6)
	{
		Weathers.id = "Moonless Night";
		Weathers.Hour.Min = 0;
		Weathers.Hour.Max = 5;
		Weathers.Lighting = "night1";
		Weathers.LightingLm = "storm";
		Weathers.InsideBack = "n";

		Weathers.Sky.Dir = "weather\skies\Converted\Night 3\\"; //Using converted textures AoP
		Weathers.Sky.Color = argb(0,200,200,255);
		Weathers.Sky.Angle = 0.06;

		Weathers.Sun.Color = argb(0,170,195,255);
		Weathers.Sun.Ambient = argb(0,12,23,33);
		Weathers.Sun.AzimuthAngle = Degree2Radian(0.0);
		Weathers.Sun.HeightAngle = 0.15;

		Weathers.Sun.Glow.Enable = false;

		Weathers.Sun.Overflow.Enable = false;

		Weathers.Sun.Flare.Enable = false;

		Weathers.Sea2.GF2MX.Sky.Color = argb(0,29,30,47);
		Weathers.Sea2.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea2.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea2.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea2.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		Weathers.Sea2.Transparency = 0.2; //0.4
		Weathers.Sea2.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea2.WaterReflection = 0.8; //0.7
		Weathers.Sea2.WaterAttenuation = 0.4; //0.8
		Weathers.Sea2.Sky.Color = argb(0,200,200,255);

		Weathers.Sea2.Pena.Color = argb(0,200,200,200); //0,50,50,80

		Weathers.Sea2.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea2.Bump.Tile = 0.05;
		Weathers.Sea2.Bump.Ang = 0.0;
		Weathers.Sea2.Bump.Speed = 0.01;
		Weathers.Sea2.Bump.AnimSpeed = 15.0;
		Weathers.Sea2.Bump.Scale = 2.0;

		Weathers.Sea2.SunRoad.Start = 0.995;
		Weathers.Sea2.SunRoad.Color1 = argb(0,55,55,100);
		Weathers.Sea2.SunRoad.Color2 = argb(0,255,255,255);
		Weathers.Sea2.SunRoad.Power = 3.0;

		Weathers.Fog.Color = argb(0,11,11,22);
		Weathers.SpecialSeaFog.Color = argb(0,11,11,22);
		Weathers.Lights = true;
		Weathers.Night = true;
		Weathers.Rainbow.Enable = false;
	}

	if ( curTime >= 6 && curTime < 10)
	{
		Weathers.id = "Morning";
		Weathers.Hour.Min = 6;
		Weathers.Hour.Max = 9;
		Weathers.Lighting = "morning1";
		Weathers.LightingLm = "mn";
		Weathers.InsideBack = "m";

		Weathers.Sky.Dir = "weather\skies\Converted\Twilight 1\\"; //Using converted textures AoP
		Weathers.Sky.Color = argb(0,255,255,255);
		Weathers.Sky.Angle = 0.0;
		
		Weathers.Sun.Color = argb(0,255,208,200);
		Weathers.Sun.Ambient = argb(0,55,44,33); //0,55,44,44
		Weathers.Sun.AzimuthAngle = Degree2Radian(350);
		Weathers.Sun.HeightAngle = 0.21;

		Weathers.Sun.Glow.Enable = true;

		Weathers.Sun.Overflow.Enable = false;

		Weathers.Sun.Flare.Enable = true;

		Weathers.Sea2.GF2MX.Sky.Color = argb(0,255,230,220);
		Weathers.Sea2.GF2MX.Water.Color = argb(0,0,5,10); //0,15,12,10
		Weathers.Sea2.GF2MX.Bump.Tile = 0.05; //0.06
		Weathers.Sea2.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea2.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		/*
		Weathers.Sea2.Transparency = 0.2;
		Weathers.Sea2.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea2.WaterReflection = 0.8; //0.7
		Weathers.Sea2.WaterAttenuation = 0.4; //0.8
		Weathers.Sea2.Sky.Color = argb(0,255,255,255);
		*/
		
		Weathers.Sea2.Pena.Color = argb(0,200,200,200); //0,55,55,55

		Weathers.Sea2.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea2.Bump.Tile = 0.05; //0.06
		Weathers.Sea2.Bump.Ang = 0.0;
		Weathers.Sea2.Bump.Speed = 0.01;
		Weathers.Sea2.Bump.AnimSpeed = 23.0;
		Weathers.Sea2.Bump.Scale = 2.0;

		Weathers.Sea2.SunRoad.Start = 0.97;
		Weathers.Sea2.SunRoad.Color1 = argb(0,255,100,0); //changed from 0,255,55,44, was much too red for the new sun.DeathDaisy
		Weathers.Sea2.SunRoad.Color2 = argb(0,255,200,55); //changed from 0,255,100,0, ditto.DeathDaisy
		Weathers.Sea2.SunRoad.Power = 3.0;

		Weathers.Fog.Color = argb(0,162,152,155);
//		Weathers.SpecialSeaFog.Color = argb(0,162,152,155);
		Weathers.SpecialSeaFog.Color = argb(0,60,50,57);	// LDH Better lighting for this hour 18Feb09
		Weathers.Lights = false;
		Weathers.Night = false;
	}

	if (sti(Weathers.Sun.Flare.Enable) == true)
	{
		Weathers.Sun.Flare.Texture = "weather\sun\flare\allflares.tga";
		Weathers.Sun.Flare.Dist = 3500.0;
		Weathers.Sun.Flare.TexSizeX = 2;
		Weathers.Sun.Flare.TexSizeY = 2;
		Weathers.Sun.Flare.Technique = "sunflare";
		Weathers.Sun.Flare.Scale = 2.0;
		Weathers.Sun.Flares.f1 = "1.0,200.0,0,0x0F0F0F";
		Weathers.Sun.Flares.f2 = "0.9,20.0,1,0x0F0F0F";
		Weathers.Sun.Flares.f3 = "0.8,30.0,2,0x0F0F0F";
		Weathers.Sun.Flares.f4 = "0.6,150.0,0,0x0F0F0F";
		Weathers.Sun.Flares.f5 = "0.5,50.0,0,0x0F0F0F";
		Weathers.Sun.Flares.f6 = "0.4,100.0,1,0x0F0F0F";
		Weathers.Sun.Flares.f7 = "0.3,200.0,0,0x0F0F0F";
		Weathers.Sun.Flares.f8 = "0.2,200.0,0,0x0F0F0F";
	}

	if (sti(Weathers.Sun.Glow.Enable) == true)
	{
		Weathers.Sun.Glow.Dist = 3500.0;
		Weathers.Sun.Glow.Size = 1250.0;
		Weathers.Sun.Glow.RotateSpeed = 1.0;
		Weathers.Sun.Glow.GlowTexture = "weather\sun\glow\sunglow.tga";
		Weathers.Sun.Glow.DecayTime = 8.0;
		Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
		Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
		Weathers.Sun.Glow.Color = argb(0,255,255,255);
	}

	Weathers.Storm = false;
	Weathers.Tornado = false;
	if (rand(50) > 25){	Weathers.Shark = true;	}
	else { Weathers.Shark = false; }

	Weathers.Shadow.Density.Head = argb(255,96,96,96);
	Weathers.Shadow.Density.Foot = argb(255,96,96,64);

	Weathers.Lightning.Enable = false;
	Weathers.Lightning.Texture = "Weather\lightning\lightning.tga";
	Weathers.Lightning.FlickerTime = 32;
	Weathers.Lightning.SubTexX = 1;
	Weathers.Lightning.SubTexY = 1;

	Weathers.Sky.Size = 1000.0;
	Weathers.Sky.Rotate = 0.0;
	Weathers.Sky.Rotate.Min = -0.001;
	Weathers.Sky.Rotate.Max = 0.001;
}

// -------------------------------------------------------------
// Mett: настройки моря
// заготовки на разные типы волнения:
// штиль, лёгкий бриз, бриз, умеренный бриз, сильный бриз, шторм
// -------------------------------------------------------------

// Code borrowed from mett_top -->
string WhrGetSeaPresetFromWind()
{
	ref mchr = GetMainCharacter();
	string sLocation = mchr.location;
	string sPreset = "calm";
	if(winds > 7.0) sPreset = "light_breeze";
	if(winds > 12.0) sPreset = "long_waves";
	if(winds > 15.0) sPreset = "breeze";
	if(winds > 20.0) sPreset = "moderate_breeze";
	if(winds > 24.0) sPreset = "strong_breeze";
	if(winds > 27.0) sPreset = "strong wind";
	if(CheckAttribute(&WeatherParams, "Storm") && sti(WeatherParams.Storm) == 1) sPreset = "storm";
	if(FindLocation(sLocation) != -1){
		if (winds > 10.0) sPreset = "strong_breeze_land";
		else{
			sPreset = "light_breeze_land";
		}
	}
	return sPreset;
}

void WhrSetSeaPreset(ref Weathers, float fWind, string sPreset)
{
	Sea.MaxSeaDistance= 8000.0;
	float SeaAmp = 0.0;

	switch(sPreset)
	
	{
			case "calm": //штиль 0
				SeaAmp = fWind * 0.6 + 1; // 4*х+х=3

				Weathers.Sea2.Amp1 = SeaAmp;	// 1.0			
		        Weathers.Sea2.AnimSpeed1 = 1.0;			
		        Weathers.Sea2.Scale1 = 1.25;				
		        Weathers.Sea2.MoveSpeed1 = "1.5, 0.0, 1.5";	

		        Weathers.Sea2.Amp2 = 1.25;					
		        Weathers.Sea2.AnimSpeed2 = 1.25;				
		        Weathers.Sea2.Scale2 = 2.0;					
		        Weathers.Sea2.MoveSpeed2 = "-1.5, 0.0, -1.5";
				
				Weathers.Sea2.FoamK = 0.15;//яркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = 3.0;////высота с которой начинаетс§ пена
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
				
			break;

			case "light_breeze": //лёгкий бриз 1
			    SeaAmp = fWind * 0.4 + 1;  
				
				Weathers.Sea2.Amp1 = SeaAmp; // 4.0
		        Weathers.Sea2.AnimSpeed1 = 1.25;
		        Weathers.Sea2.Scale1 = 0.6;
		        Weathers.Sea2.MoveSpeed1 = "0.0, 0.0, 2.0";

		        Weathers.Sea2.Amp2 = 2.0;
		        Weathers.Sea2.AnimSpeed2 = 2.0;
		        Weathers.Sea2.Scale2 = 1.5;
		        Weathers.Sea2.MoveSpeed2 = "-2.0, 0.0, 0.0";

				Weathers.Sea2.FoamK = 0.4;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = SeaAmp * 0.85;//высота с которой начинаетс§ пена
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
				
			break;

			case "breeze":	//бриз 2 8.15
			    SeaAmp = fWind * 0.60 + 1;  
				
				Weathers.Sea2.Amp1 = SeaAmp; // 8.0
		        Weathers.Sea2.AnimSpeed1 = 1.5;
		        Weathers.Sea2.Scale1 = 0.35;
		        Weathers.Sea2.MoveSpeed1 = "0.0, 0.0, 3.0";

		        Weathers.Sea2.Amp2 = 3.0;
		        Weathers.Sea2.AnimSpeed2 = 3.0;
		        Weathers.Sea2.Scale2 = 1.25;
		        Weathers.Sea2.MoveSpeed2 = "1.0, 0.0, 1.0";

				Weathers.Sea2.FoamK = 0.25;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = SeaAmp * 0.8;//высота с которой начинаетс§ пена 6.0
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
					
			break;

			case "moderate_breeze":	//бриз 3
			    SeaAmp = fWind * 0.75 + 1;  
				
				Weathers.Sea2.Amp1 = SeaAmp; // 12.0 - 9.25
		        Weathers.Sea2.AnimSpeed1 = 1.65;
		        Weathers.Sea2.Scale1 = 0.25;
		        Weathers.Sea2.MoveSpeed1 = "0.0, 0.0, 4.0";

		        Weathers.Sea2.Amp2 = 3.5;
		        Weathers.Sea2.AnimSpeed2 = 3.5;
		        Weathers.Sea2.Scale2 = 1.15;
		        Weathers.Sea2.MoveSpeed2 = "0.0, 0.0, 1.0";
				
				Weathers.Sea2.FoamK = 0.25;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = SeaAmp * 0.75;//высота с которой начинаетс§ пена 8.0
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
				
			break;

			case "strong_breeze"://ветрено 4
			    SeaAmp = fWind * 0.85 + 1;  
				
				Weathers.Sea2.Amp1 = SeaAmp; // 16.0 - 13
		        Weathers.Sea2.AnimSpeed1 = 1.75;
		        Weathers.Sea2.Scale1 = 0.20;
		        Weathers.Sea2.MoveSpeed1 = "0.0, 0.0, 5.0";

		        Weathers.Sea2.Amp2 = 4.0;
		        Weathers.Sea2.AnimSpeed2 = 4.0;
		        Weathers.Sea2.Scale2 = 1.0;
		        Weathers.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";

				Weathers.Sea2.FoamK = 0.15; //§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = SeaAmp * 0.7; //высота с которой начинаетс§ пена 10.5
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves

			break;
			
            case "strong wind"://ветрено 5 17.5 - 20
			    SeaAmp = fWind * 1.55 + 1;  
				
				Weathers.Sea2.Amp1 = SeaAmp; // 32.0 - 28.0
		        Weathers.Sea2.AnimSpeed1 = 3.75;
		        Weathers.Sea2.Scale1 = 0.125;
		        Weathers.Sea2.MoveSpeed1 = "8.0, 0.0, 0.0";

		        Weathers.Sea2.Amp2 = 6.0;
		        Weathers.Sea2.AnimSpeed2 = 6.0;
		        Weathers.Sea2.Scale2 = 0.75;
		        Weathers.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";

				Weathers.Sea2.FoamK = 0.15;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = SeaAmp * 0.65;//высота с которой начинаетс§ пена 21.0
				Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves

			break;
			
			case "storm"://шторм 5
				
				Weathers.Sea2.Amp1 = 64.0;
		        Weathers.Sea2.AnimSpeed1 = 4.25;
		        Weathers.Sea2.Scale1 = 0.075;
 		        Weathers.Sea2.MoveSpeed1 = "8.0, 0.0, 0.0";

		        Weathers.Sea2.Amp2 = 9.0;
		        Weathers.Sea2.AnimSpeed2 = 8.0;
		        Weathers.Sea2.Scale2 = 0.5;
		        Weathers.Sea2.MoveSpeed2 = "12.0, 0.0, 0.0";

				Weathers.Sea2.FoamK = 0.05;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Weathers.Sea2.FoamV = 42.0;//высота с которой начинаетс§ пена
				Weathers.Sea2.FoamUV = 0.3; //тайлинг пены
				Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Weathers.Sea2.Reflection = 0.35;
	            Weathers.Sea2.Transparency = 0.25;
	            Weathers.Sea2.Frenel = 0.3;
	            Weathers.Sea2.Attenuation = 0.2 + 5 * 0.05;
			    Weathers.Sea2.WaterColor = argb(0, 10, 25, 40);
				Weathers.Sea2.BumpScale = 0.03; // size of the bump
				Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves 
				
			break;
			
		case "light_breeze_land":	//лёгкий ветер суша
			Weathers.Sea2.Amp1 = 0.5;
			Weathers.Sea2.AnimSpeed1 = 1.0;
			Weathers.Sea2.Scale1 = 1.75;
			Weathers.Sea2.MoveSpeed1 = "0.5, 0.0, 0.0";

			Weathers.Sea2.Amp2 = 0.5;
			Weathers.Sea2.AnimSpeed2 = 1.0;
			Weathers.Sea2.Scale2 = 1.75;
			Weathers.Sea2.MoveSpeed2 = "0.0, 0.0, -0.5";

			Weathers.Sea2.FoamV = 5.0;
			Weathers.Sea2.FoamK = 0.0;
			Weathers.Sea2.FoamUV = 0.3;
			Weathers.Sea2.FoamTexDisturb = 0.7;
			
			Weathers.Sea2.BumpScale = 0.03; // size of the bump
			Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
		break;

		case "strong_breeze_land": //сильный ветер суша
			Weathers.Sea2.Amp1 = 3.0;
			Weathers.Sea2.AnimSpeed1 = 1.0;
			Weathers.Sea2.Scale1 = 2.5;
			Weathers.Sea2.MoveSpeed1 = "0.5, 0.0, 0.0";

			Weathers.Sea2.Amp2 = 3.0;
			Weathers.Sea2.AnimSpeed2 = 1.0;
			Weathers.Sea2.Scale2 = 2.5;
			Weathers.Sea2.MoveSpeed2 = "0.0, 0.0, -0.5";

			Weathers.Sea2.FoamV = 0.8;
			Weathers.Sea2.FoamK = 0.15;
			Weathers.Sea2.FoamUV = 0.5;
			Weathers.Sea2.FoamTexDisturb = 0.5;
            
			Weathers.Sea2.BumpScale = 0.03; // size of the bump
			Weathers.Sea2.PosShift = 1.4; //	sharpness of the waves
        break;	
			
		case "long_waves": 	
			Weathers.Sea2.Sea2.Amp1 = 17.0; //амплитуда 1 волны
			Weathers.Sea2.Sea2.AnimSpeed1 = 0.5; //скорость анимации
			Weathers.Sea2.Sea2.Scale1 = 0.17 //размеры волны9
			Weathers.Sea2.Sea2.MoveSpeed1 = "0.0, 0.0, 8.0"; //скорость движени¤

			Weathers.Sea2.Sea2.Amp2 = 1.5;
			Weathers.Sea2.Sea2.AnimSpeed2 = 0.0;
			Weathers.Sea2.Sea2.Scale2 = 2.0;
			Weathers.Sea2.Sea2.MoveSpeed2 = "4.0, 0.0, 4.0";	

			Weathers.Sea2.Wind.Angle = 2.0;
			Weathers.Sea2.Wind.Speed.Min = 6.5;
			Weathers.Sea2.Wind.Speed.Max = 10.0;
			
			Weathers.Sea2.FoamK = 0.15;//яркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
			Weathers.Sea2.FoamV = 3.0;////высота с которой начинаетс§ пена
			Weathers.Sea2.FoamUV = 0.4; //тайлинг пены
			Weathers.Sea2.FoamTexDisturb = 0.5;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0
			Weathers.Sea2.Sea2.BumpScale = 0.1; //
			Weathers.Sea2.Sea2.PosShift = 0.5; //остроконечность волн
        break;		
	}
	
	SM_ModifyLightness();
		
	// Log_TestInfo("WhrSetSeaPreset: выбран пресет " + sPreset);
}	
	
void SM_ModifyLightness()
{
	float lightIntencity = SM_CurrentHourToLightIntencity();
	int r, g, b;
		
	r = 255;
	g = 255;
	b = 255;
	
	r = makeint(r * lightIntencity);
	g = makeint(g * lightIntencity);
	b = makeint(b * lightIntencity);
	
	aref weather = GetCurrentWeather();
	
	weather.Sky.Color = argb(0, r, g, b);
	Weather.Sky.Color = weather.Sky.Color;
	
	weather.Sun.Reflection.Size = 100 + 500 * lightIntencity;
	
	// Log_TestInfo("SM_ModifyLightness: выбрано значение " + lightIntencity);
}	

// конвертор часов в интенсивность освещения (2 часа ночи - самый чёрный час, интенсивность 0; 14 часов - самый яркий час, интенсивность 1)
float SM_HourToLightIntencity(float hour)
{
	return abs(abs((hour - 14) / 12) - 1);
}

// тоже самое, только для текущего часа
float SM_CurrentHourToLightIntencity()
{
	return SM_HourToLightIntencity(GetHour());
}
// Code borrowed from mett_top <--

// Mirsaneli -->
void Whr_SetWaterColor()
{
	// float fTime = GetTime();

	// Morning (6–10)
	if (curTime >= 6.0 && curTime < 10.0) 
	{
		switch(rand(4)) // 0 or 1
		{
			case 0:
				Weathers.Sea2.WaterColor = argb(0, 0, 30, 60);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
				Weathers.Sea2.Reflection = 0.7;
				Weathers.Sea2.Transparency = 0.5;
				Weathers.Sea2.Frenel = 0.7;
				Weathers.Sea2.Attenuation = 0.3;
			break;
			case 1:
				Weathers.Sea2.WaterColor = argb(0, 45, 80, 90);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
				Weathers.Sea2.Reflection = 0.8;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.7;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 2:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.8;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 3:
				Weathers.Sea2.WaterColor = argb(0, 10, 55, 100);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.5;
				Weathers.Sea2.Frenel = 0.08;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 4:
				Weathers.Sea2.WaterColor = argb(0, 10, 55, 100);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.5;
				Weathers.Sea2.Frenel = 0.08;
				Weathers.Sea2.Attenuation = 0.2;
			break;
		}
	}
	// Day (10–18)
	else if (curTime >= 10.0 && curTime < 18.0) 
	{
		switch(rand(5)) // 0 or 1
		{
			case 0:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.2;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 1:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 155, 205, 205);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.8;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 2:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 115, 205, 205);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.7;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 3:
				Weathers.Sea2.WaterColor = argb(0, 0, 60, 84);
				Weathers.Sea2.SkyColor   = argb(0, 205, 200, 200);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.7;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 4:
				Weathers.Sea2.WaterColor = argb(0, 45, 80, 90);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
				Weathers.Sea2.Reflection = 0.8;
				Weathers.Sea2.Transparency = 0.1;
				Weathers.Sea2.Frenel = 0.6;
				Weathers.Sea2.Attenuation = 0.2;
			break;
			case 5:
				Weathers.Sea2.WaterColor = argb(0, 10, 55, 100);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
				Weathers.Sea2.Reflection = 0.6;
				Weathers.Sea2.Transparency = 0.5;
				Weathers.Sea2.Frenel = 0.08;
				Weathers.Sea2.Attenuation = 0.2;
			break;
		}
	}
	// Sunset (18–21)
	else if (curTime >= 18.0 && curTime < 21.0) 
	{
		switch(rand(2)) // 0 or 1
		{
			case 0:
				Weathers.Sea2.WaterColor = argb(0, 45, 80, 90);
				Weathers.Sea2.SkyColor   = argb(0, 255, 255, 255);
			break;
			case 1:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
			break;
			case 2:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
			break;
		}
	}
	// Evening (21–0)
	else if (curTime >= 21.0 && curTime < 0.0) 
	{
		switch(rand(2)) // 0 or 1
		{
			case 0:
				Weathers.Sea2.WaterColor = argb(0, 20, 65, 90);
				Weathers.Sea2.SkyColor   = argb(0, 205, 205, 205);
			break;
			case 1:
				Weathers.Sea2.WaterColor = argb(0, 20, 30, 40);
				Weathers.Sea2.SkyColor   = argb(0, 155, 155, 155);
			break;
			case 2:
				Weathers.Sea2.WaterColor = argb(0, 0, 10, 30);
				Weathers.Sea2.SkyColor   = argb(0, 175, 175, 175);
			break;
		}
	}
	// Night (0–6)
	else 
	{
		switch(rand(2)) // 0 or 1
		{
			case 0:
				Weathers.Sea2.WaterColor = argb(0, 0, 0, 15);
				Weathers.Sea2.SkyColor   = argb(0, 175, 175, 175);
			break;
			case 1:
				Weathers.Sea2.WaterColor = argb(0, 0, 0, 25);
				Weathers.Sea2.SkyColor   = argb(0, 175, 175, 175);
			break;
			case 2:
				Weathers.Sea2.WaterColor = argb(0, 0, 0, 40);
				Weathers.Sea2.SkyColor   = argb(0, 175, 175, 175);
			break;
		}
	}
}
// Mirsaneli <--