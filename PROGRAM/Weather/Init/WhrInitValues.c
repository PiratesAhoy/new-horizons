void Whr_InitGValues()
{
	// Sea colours adjusted to compensate for the Intel fix, which disables reflections. Armada
	bool IntelCard = FindFile("", "*.txt", "IntelCard.txt") != "");

    if ( curTime >= 10 && curTime < 18)
	{
		Weathers.id = "Blue Sky";
		Weathers.Hour.Min = 10;
		Weathers.Hour.Max = 17;
		Weathers.Lighting = "day1";
		Weathers.LightingLm = "day";
		Weathers.InsideBack = "d";

		Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\"; // Using AoP Sky Textures
		Weathers.Sky.Color = argb(0,255,255,255);
		Weathers.Sky.Angle = 0.0;
		
		Weathers.Sun.Color = argb(0,160,120,98);
		Weathers.Sun.Ambient = argb(0,100,90,80);
		Weathers.Sun.AzimuthAngle = Degree2Radian(90.0);
		Weathers.Sun.HeightAngle = 0.95;

		Weathers.Sun.Glow.Enable = true;

		Weathers.Sun.Overflow.Enable = false;	// this is never set to true, washes out view if you look into the sun
		Weathers.Sun.Overflow.Texture = "Weather\lightning\flash.tga";
		//Weathers.Sun.Overflow.Texture = "weather\sun\overflow\overflow.tga";
		Weathers.Sun.Overflow.Color = argb(0, 100, 100, 100);
		Weathers.Sun.Overflow.Size = 5500.0;
		Weathers.Sun.Overflow.Technique = "sunoverflow";
		Weathers.Sun.Overflow.Start = 0.7;

		Weathers.Sun.Flare.Enable = true;

		Weathers.Sea.GF2MX.Sky.Color = argb(0,100,150,195); //0,160,210,255
		Weathers.Sea.GF2MX.Water.Color = argb(0,0,5,10);
		Weathers.Sea.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\";

		Weathers.Sea.Transparency = 0.2; // This is about right for the most realistic effect. Armada
		Weathers.Sea.FrenelCoefficient = 0.3; //0.5  A lower number makes the water more 'shiny', but possibly too oily? Armada
		Weathers.Sea.WaterReflection = 0.8; // This is about right for the most realistic effect. Armada
		Weathers.Sea.WaterAttenuation = 0.4; //0.9  A lower number reduces the colour intensity of the water. Armada
		Weathers.Sea.Sky.Color = argb(0,240,240,240); //0,255,255,255
		if(IntelCard)
			Weathers.Sea.Water.Color = argb(0,45,90,158); //0,30,55,100
		else
			Weathers.Sea.Water.Color = argb(0,0,35,90); //0,30,55,100 Deep blue to resemble real Caribbean. Armada
		Weathers.Sea.Pena.Color = argb(0,200,200,200); //0,55,55,55

		Weathers.Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea.Bump.Tile = 0.05; //0.06
		Weathers.Sea.Bump.Ang = 0.0;
		Weathers.Sea.Bump.Speed = 0.01;
		Weathers.Sea.Bump.AnimSpeed = 20.0; //23.0 Too fast? Armada
		Weathers.Sea.Bump.Scale = 2.0;

		Weathers.Sea.SunRoad.Start = 0.99;
		Weathers.Sea.SunRoad.Color1 = argb(0,128,55,0);
		Weathers.Sea.SunRoad.Color2 = argb(0,255,200,150);
		Weathers.Sea.SunRoad.Power = 0.25;	// is this correct?

		if(Whr_IsStorm()){
		Weathers.Fog.Color = argb(0,162,152,155);
		Weathers.SpecialSeaFog.Color = argb(0,60,50,57);
		}
		else{
		Weathers.Fog.Color = argb(0,162,152,155);
		// Weathers.SpecialSeaFog.Color = argb(0,162,152,155);		// LDH this is way too light 20Feb09
		Weathers.SpecialSeaFog.Color = argb(0,100,150,195);		//0,125,174,220 LDH sky color 21Feb09
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

		Weathers.Sea.GF2MX.Sky.Color = argb(0,70,40,30);
		Weathers.Sea.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea.GF2MX.Bump.Tile = 0.05; //0.04
		Weathers.Sea.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		Weathers.Sea.Transparency = 0.2; //0.4
		Weathers.Sea.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea.WaterReflection = 0.8; //0.7
		Weathers.Sea.WaterAttenuation = 0.4; //0.8
		Weathers.Sea.Sky.Color = argb(0,255,255,255);
		if(IntelCard)
			Weathers.Sea.Water.Color = argb(0,62,81,102); //0,30,42,55 //25,55,80
		else
			Weathers.Sea.Water.Color = argb(0,0,35,90); //0,30,42,55 //25,55,80
//		Weathers.Sea.Pena.Color = argb(0,255,100,70);
		Weathers.Sea.Pena.Color = argb(0,200,200,200);		// LDH 02Mar09 0,70,50,50

		Weathers.Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\\";
		Weathers.Sea.Bump.Tile = 0.05; //0.04
		Weathers.Sea.Bump.Ang = 0.0; //1.0
		Weathers.Sea.Bump.Speed = 0.01;
		Weathers.Sea.Bump.AnimSpeed = 20.0;
		Weathers.Sea.Bump.Scale = 2.0;

		Weathers.Sea.SunRoad.Start = 0.99;
		Weathers.Sea.SunRoad.Color1 = argb(0,255,88,44);
		Weathers.Sea.SunRoad.Color2 = argb(0,255,200,55);
		Weathers.Sea.SunRoad.Power = 3.0;

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

		Weathers.Sea.GF2MX.Sky.Color = argb(0,29,30,47);
		Weathers.Sea.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		Weathers.Sea.Transparency = 0.2; //0.4
		Weathers.Sea.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea.WaterReflection = 0.8; //0.7
		Weathers.Sea.WaterAttenuation = 0.4; //0.8
		Weathers.Sea.Sky.Color = argb(0,200,200,255);
		if(IntelCard)
			Weathers.Sea.Water.Color = argb(0,25,34,43); //0,22,28,36
		else
			Weathers.Sea.Water.Color = argb(0,0,35,90); //0,22,28,36
		Weathers.Sea.Pena.Color = argb(0,200,200,200); //0,50,50,80

		Weathers.Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea.Bump.Tile = 0.05;
		Weathers.Sea.Bump.Ang = 0.0;
		Weathers.Sea.Bump.Speed = 0.01;
		Weathers.Sea.Bump.AnimSpeed = 15.0;
		Weathers.Sea.Bump.Scale = 2.0;

		Weathers.Sea.SunRoad.Start = 0.995;
		Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
		Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
		Weathers.Sea.SunRoad.Power = 3.0;

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

		Weathers.Sea.GF2MX.Sky.Color = argb(0,29,30,47);
		Weathers.Sea.GF2MX.Water.Color = argb(0,0,5,10); //0,0,0,0
		Weathers.Sea.GF2MX.Bump.Tile = 0.05;
		Weathers.Sea.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		Weathers.Sea.Transparency = 0.2; //0.4
		Weathers.Sea.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea.WaterReflection = 0.8; //0.7
		Weathers.Sea.WaterAttenuation = 0.4; //0.8
		Weathers.Sea.Sky.Color = argb(0,200,200,255);
		if(IntelCard)
			Weathers.Sea.Water.Color = argb(0,25,34,43); //0,20,28,36
		else
			Weathers.Sea.Water.Color = argb(0,0,35,90); //0,20,28,36
		Weathers.Sea.Pena.Color = argb(0,200,200,200); //0,50,50,80

		Weathers.Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea.Bump.Tile = 0.05;
		Weathers.Sea.Bump.Ang = 0.0;
		Weathers.Sea.Bump.Speed = 0.01;
		Weathers.Sea.Bump.AnimSpeed = 15.0;
		Weathers.Sea.Bump.Scale = 2.0;

		Weathers.Sea.SunRoad.Start = 0.995;
		Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
		Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
		Weathers.Sea.SunRoad.Power = 3.0;

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

		Weathers.Sea.GF2MX.Sky.Color = argb(0,255,230,220);
		Weathers.Sea.GF2MX.Water.Color = argb(0,0,5,10); //0,15,12,10
		Weathers.Sea.GF2MX.Bump.Tile = 0.05; //0.06
		Weathers.Sea.GF2MX.Bump.AnimSpeed = 7.0;
		Weathers.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\\"; 

		Weathers.Sea.Transparency = 0.2;
		Weathers.Sea.FrenelCoefficient = 0.3; //0.7
		Weathers.Sea.WaterReflection = 0.8; //0.7
		Weathers.Sea.WaterAttenuation = 0.4; //0.8
		Weathers.Sea.Sky.Color = argb(0,255,255,255);
		if(IntelCard)
			Weathers.Sea.Water.Color = argb(0,101,126,180); //0,30,42,55
		else
			Weathers.Sea.Water.Color = argb(0,0,35,90); //0,30,42,55
		Weathers.Sea.Pena.Color = argb(0,200,200,200); //0,55,55,55

		Weathers.Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\\"; 
		Weathers.Sea.Bump.Tile = 0.05; //0.06
		Weathers.Sea.Bump.Ang = 0.0;
		Weathers.Sea.Bump.Speed = 0.01;
		Weathers.Sea.Bump.AnimSpeed = 23.0;
		Weathers.Sea.Bump.Scale = 2.0;

		Weathers.Sea.SunRoad.Start = 0.97;
		Weathers.Sea.SunRoad.Color1 = argb(0,255,100,0); //changed from 0,255,55,44, was much too red for the new sun.DeathDaisy
		Weathers.Sea.SunRoad.Color2 = argb(0,255,200,55); //changed from 0,255,100,0, ditto.DeathDaisy
		Weathers.Sea.SunRoad.Power = 3.0;

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
		string widescreen = "";
		float screen_x = stf(showWindow.width);
		float screen_y = stf(showWindow.height);
		float screen_ratio = screen_x/screen_y;
		if(screen_ratio > 1.4){ widescreen = "\widescreen";}
		
		Weathers.Sun.Glow.Dist = 3500.0;
		Weathers.Sun.Glow.Size = 1250.0;
		Weathers.Sun.Glow.RotateSpeed = 1.0;
		Weathers.Sun.Glow.Texture = "weather\sun\glow" + widescreen + "\sunglow.tga";
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
