void Whr_SetAzmAng(){
/*
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar,"skyscheme")) pchar.skyscheme = 0;	// LDH 23Feb09 move this to a global variable later?
	int skyscheme = sti(pchar.skyscheme);

//	skyscheme = 0;		// if you want to test a specific sky scheme, set it here
*/
	// PURSEON ========Begin Moon Phases at night code===========>
	string widescreen = "";
	float screen_x = stf(showWindow.width);
	float screen_y = stf(showWindow.height);
	float screen_ratio = screen_x/screen_y;
	if(screen_ratio > 1.4){ widescreen = "\widescreen";}
	string moonpic = "weather\sun\glow" + widescreen + "\moonglowfull.tga";   //default in case moon state is not known
	switch (getMoonStateName(getMoonState())){
		case FULL_MOON:
			moonpic = "weather\sun\glow" + widescreen + "\moonglowfull.tga";
		break;
		case NEW_MOON:
			moonpic = "weather\sun\glow" + widescreen + "\moonglownew.tga";
		break;
		case QUARTER_ONE:
			moonpic = "weather\sun\glow" + widescreen + "\moonglowwaxc.tga";
		break;
		case QUARTER_TWO:
			moonpic = "weather\sun\glow" + widescreen + "\moonglowwax.tga";
		break;
		case QUARTER_THREE:
			moonpic = "weather\sun\glow" + widescreen + "\moonglowwan.tga";
		break;
		case QUARTER_FOUR:
			moonpic = "weather\sun\glow" + widescreen + "\moonglowwanc.tga";
		break;
	}
	switch( curTime ){
		case 0:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 0.6;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
		case 1:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 0.85;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;	
		case 2:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 1.1;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
		case 3:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 1.35;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
		case 4:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 1.6;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
		case 5:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 1.85;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.85;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;	
	// PURSEON ========End Moon Phases at night code===========>	
		case 6:
			Weathers.Lighting = "evening3";
			//Weathers.Lighting = "morning1";
			Weathers.Sun.AzimuthAngle = Degree2Radian(158.2);
			Weathers.Sun.HeightAngle = 0.01;
			Weathers.Sea.SunRoad.Start = 0.993;
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Rainbow.Enable = false;
			Weathers.Sky.Angle = 1.45;
			Weathers.Sky.Dir = "weather\skies\Converted\Twilight 1\\";		// LDH copied from hour 7 - 03May09
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 1.2;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 6\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 4\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 7:
			Weathers.Lighting = "evening3";
			//Weathers.Lighting = "morning1";
			Weathers.Sun.AzimuthAngle = Degree2Radian(162.4);
			Weathers.Sun.HeightAngle = 0.13;		// sunrise
			Weathers.Sky.Angle = -1.5;
			Weathers.Sky.Dir = "weather\skies\Converted\Twilight 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 1.2;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 6\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 4\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 8:
			Weathers.Lighting = "evening3";
			//Weathers.Lighting = "morning1";
			Weathers.Sun.AzimuthAngle = Degree2Radian(165.6);
			Weathers.Sun.HeightAngle = 0.267;
			Weathers.Sky.Angle = -1.5;
			Weathers.Sky.Dir = "weather\skies\Converted\Twilight 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 1.2;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 6\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 4\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 9:
			Weathers.Lighting = "day1";
			Weathers.LightingLm = "day";
			Weathers.InsideBack = "d";
			Weathers.Sun.AzimuthAngle = Degree2Radian(168.2);
			Weathers.Sun.HeightAngle = 0.405;
			Weathers.Sky.Angle = -1.5;
			Weathers.Sky.Dir = "weather\skies\Converted\Twilight 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 1.2;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 6\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 4\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
			if(wRain < 80){
				//maybe still a bit yellow? works alright.DeathDaisy
				Weathers.Sea.SunRoad.Color1 = argb(0,160,55,0);//changed from 0,160,55,0 which was too red for 9-10AM, both for the new sun and for realism.DeathDaisy
				Weathers.Sea.SunRoad.Color2 = argb(0,255,200,90);// 0,255,150,75.DeathDaisy
				Weathers.Sea.SunRoad.Power = 3.0;
				Weathers.Sea.SunRoad.Start = 0.99;
			}
		break;
		case 10:
			Weathers.Sun.AzimuthAngle = Degree2Radian(169.9);
			Weathers.Sun.HeightAngle = 0.545;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 2.3;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 2\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Angle = -1.8;
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 3\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 11:
			Weathers.Sun.AzimuthAngle = Degree2Radian(170.0);
			Weathers.Sun.HeightAngle = 0.686;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 2.3;
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 2\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Angle = -1.8;
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 3\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 12:
			Weathers.Sun.AzimuthAngle = Degree2Radian(160.8);
			Weathers.Sun.HeightAngle = 0.825;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 1\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 2\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 3\\";
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 13:
			Weathers.Sun.AzimuthAngle = Degree2Radian(19.6);
			Weathers.Sun.HeightAngle = 0.826;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 14:
			Weathers.Sun.AzimuthAngle = Degree2Radian(9.9);
			Weathers.Sun.HeightAngle = 0.688;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 15:
			Weathers.Sun.AzimuthAngle = Degree2Radian(10.0);
			Weathers.Sun.HeightAngle = 0.547;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
			}
			if(wRain >= 95){
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
				Weathers.LightingLm = "storm";
			}
		break;
		case 16:
			Weathers.Sun.AzimuthAngle = Degree2Radian(11.7);
			Weathers.Sun.HeightAngle = 0.407;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 17:
			Weathers.Sun.AzimuthAngle = Degree2Radian(17.5);
			Weathers.Sun.HeightAngle = 0.268;
			Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
			}
			if(wRain >= 95){
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 18:
			Weathers.Lighting = "day1";		// keep this
			Weathers.LightingLm = "day";	// keep this
			Weathers.InsideBack = "d";		// keep this
			//Weathers.Sun.Ambient = argb(0,100,90,80);				// LDH test 27Feb09
			Weathers.Sun.AzimuthAngle = Degree2Radian(21.6);
			Weathers.Sun.HeightAngle = 0.131;
			Weathers.Sky.Angle = -0.9;
			Weathers.Sky.Rotate = 135.0;
	/*
			switch (skyscheme)
			{
			case 0:
				Weathers.Sky.Dir = "weather\skies\4\\";				// LDH original red sky 09Feb09
				break;
			case 1:
				Weathers.Sky.Dir = "weather\skies\Converted\Blue 3\\";
				break;
			}
	*/
	//		Weathers.Sky.Dir = "weather\skies\Converted\Blue 1\\";		// LDH 24Feb09
			Weathers.Sky.Dir = "weather\skies\Converted\Sunset 2\\";	// LDH 28Feb09
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.LightingLm = "storm";
				Weathers.Sun.Glow.Enable = false;
				Weathers.Sun.Flare.Enable = false;
				Weathers.Sun.Overflow.Enable = false;
				Weathers.Sea.SunRoad.Start = 0.993;
				Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				Weathers.Sea.SunRoad.Power = 2.0;
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 1\\";
			}
			if(wRain >= 95){
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
				Weathers.LightingLm = "storm";
			}
		break;
		case 19:
			Weathers.Lighting = "day1";		// keep this
			Weathers.LightingLm = "day";	// keep this
			Weathers.InsideBack = "d";		// keep this
			Weathers.Sun.AzimuthAngle = Degree2Radian(21.6);
			Weathers.Sun.HeightAngle = 0.002;
			Weathers.Sky.Angle = -0.9;
			//Weathers.Sky.Dir = "weather\skies\Converted\Sunset 2\\";
			Weathers.Sky.Dir = "weather\skies\4\\"; //Armada: bring back original red sky for this hour
			if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 2.35;
				Weathers.Sky.Dir = "weather\skies\Converted\Sunset 1\\";
			}
			if(wRain >= 65 && wRain <95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 6\\";
			}
			if(wRain >= 95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 1\\";
			}
		break;
		case 20:
			Weathers.Lighting = "morning1";
			//Weathers.Lighting = "evening2";
			Weathers.LightingLm = "evening";
			Weathers.Sun.AzimuthAngle = Degree2Radian(0.0);
			Weathers.Sun.HeightAngle = 0.15;
			Weathers.Sun.Glow.Enable = false;
			Weathers.Sun.Flare.Enable = false;
			Weathers.Sea.SunRoad.Start = 0.993;
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Power = 2.0;
			Weathers.Sky.Angle = -0.9;
			Weathers.Sky.Dir = "weather\skies\4\\"; //Armada: was Sunset 2, but was too bright considering the sun has gone down
	/*		if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 2.35;
				Weathers.Sky.Dir = "weather\skies\Converted\Sunset 1\\";
			}*/
			if(wRain >= 65 && wRain <95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 6\\";
			}
			if(wRain >= 95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\"; //Armada: was Stormy 1, but that shows blue sky
			}
		break;
		case 21:
			Weathers.Lighting = "morning1";
			//Weathers.Lighting = "evening2";
			Weathers.LightingLm = "evening";
			Weathers.Sun.AzimuthAngle = Degree2Radian(0.0);
			Weathers.Sun.HeightAngle = 0.15;
			Weathers.Sun.Ambient = argb(0,33,23,33);
			Weathers.Sun.Glow.Enable = false;
			Weathers.Sun.Flare.Enable = false;
			Weathers.Sea.SunRoad.Start = 0.993;
			Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
			Weathers.Sea.SunRoad.Power = 2.0;
			Weathers.Sky.Angle = -0.9;
			Weathers.Sky.Dir = "weather\skies\Converted\Sunset 3\\"; //Armada
	/*		if(wRain >= 50 && wRain < 65){
				Weathers.Sky.Angle = 3.0;
				Weathers.Sky.Dir = "weather\skies\Converted\Sunset 3\\";
			}*/
			if(wRain >= 65 && wRain <95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 6\\";
			}
			if(wRain >= 95){
				Weathers.Sky.Angle = 1.8;
				Weathers.LightingLm = "storm";
				Weathers.Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			}
		break;
		case 22:
			Weathers.Sun.AzimuthAngle = Degree2Radian(327.0);
			Weathers.Sun.HeightAngle = 0.1;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 1.75;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65 ){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
		case 23:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = 0.35;
			Weathers.Sun.Ambient = argb(0,12,23,43);
			Weathers.Sun.Glow.Enable = true;
			Weathers.Sun.Glow.Dist = 3500.0; //Levis
			Weathers.Sun.Glow.Size = 150.0; //DeathDaisy
			Weathers.Sun.Glow.RotateSpeed = 0.0;
			Weathers.Sun.Glow.Texture = moonpic;
			Weathers.Sun.Glow.DecayTime = 4.0;
			Weathers.Sun.Glow.TechniqueNoZ = "sunglow_noz";
			Weathers.Sun.Glow.TechniqueZ = "sunglow_z";
			Weathers.Sun.Glow.Color = argb(0,235,245,255);
			Weathers.Sea.SunRoad.Color1 = argb(0,55,55,100);
			Weathers.Sea.SunRoad.Color2 = argb(0,255,255,255);
			Weathers.Sky.Angle = 2.0;
			Weathers.Sky.Dir = "weather\skies\Converted\Night 4\\";
			if(wRain >= 65 ){
				Weathers.Sky.Dir = "weather\skies\Converted\Overcast 7\\";
				if(wRain>=85){
					Weathers.Sun.Glow.Enable = false;
					Weathers.Sea.SunRoad.Color1 = argb(0,0,0,0);
					Weathers.Sea.SunRoad.Color2 = argb(0,0,0,0);
				}
			}
		break;
	}
//-----------------------------------------

	switch (Weathers.Sky.Dir)
	{
	/*
		case "weather\skies\4\\":			// LDH original red sky 09Feb09 - doesn't work well with lighting files used
			Weathers.SpecialSeaFog.Color = argb(0,79,41,38);
			Weathers.Fog.Color = argb(0,79,41,38);
			Weathers.Sun.Ambient = argb(0,128,80,80);
			break;
	*/
		case "weather\skies\Converted\Blue 1\\":
	//		Weathers.SpecialSeaFog.Color = argb(0,125,174,220);		// a bit green, maybe?
			Weathers.SpecialSeaFog.Color = argb(0,108,160,202);		// LDH use color for Blue3 - 26Feb09
			break;

		case "weather\skies\Converted\Blue 3\\":
			Weathers.SpecialSeaFog.Color = argb(0,108,160,202);
			break;

		case "weather\skies\Converted\Clouds 1\\":
			Weathers.SpecialSeaFog.Color = argb(0,114,154,176);		// LDH - 23Feb09
			break;

		case "weather\skies\Converted\Clouds 2\\":
			Weathers.SpecialSeaFog.Color = argb(0,114,154,176);		// LDH - 25Feb09
			break;

		case "weather\skies\Converted\Clouds 6\\":
			break;

		case "weather\skies\Converted\Night 3\\":
			break;

		case "weather\skies\Converted\Night 4\\":
			break;

		case "weather\skies\Converted\Night 5\\":
			break;

		case "weather\skies\Converted\Overcast 1\\":
			Weathers.SpecialSeaFog.Color = argb(0,152,152,155);
			break;

		case "weather\skies\Converted\Overcast 3\\":	// 10:00 - 13:59 rain 65-95
			Weathers.Fog.Color = argb(0,162,155,155);
			Weathers.SpecialSeaFog.Color = argb(0,162,162,155);
			break;

		case "weather\skies\Converted\Overcast 4\\":	// 07:00 - 09:59 rain  65-95
			Weathers.SpecialSeaFog.Color = argb(0,90,85,110);
			break;

		case "weather\skies\Converted\Overcast 5\\":
			break;

		case "weather\skies\Converted\Overcast 6\\":
	//		Weathers.SpecialSeaFog.Color = argb(0,76,60,65);
			break;

		case "weather\skies\Converted\Overcast 7\\":
			break;

		case "weather\skies\Converted\Stormy 1\\":
			break;

		case "weather\skies\Converted\Stormy 2\\":
			break;

		case "weather\skies\Converted\Sunset 1\\":
	//		Weathers.SpecialSeaFog.Color = argb(0,76,60,65);	// almost right, needs adjusting, a bit dark
			break;

		case "weather\skies\Converted\Sunset 2\\":		// 18:00 - 21:59
			if (curtime == 18) Weathers.SpecialSeaFog.Color = argb(0,110,100,105);	// LDH - 28Feb09
			if (curtime == 19) Weathers.SpecialSeaFog.Color = argb(0,78,65,66);		// LDH - 28Feb09
	//		Weathers.SpecialSeaFog.Color = argb(0,76,60,65);	// default for this time
			break;

		case "weather\skies\Converted\Sunset 3\\":		// 21:00 cloudy, could be more purple
			break;

		case "weather\skies\Converted\Twilight 1\\":	// 07:00 - 09:59
			Weathers.SpecialSeaFog.Color = argb(0,90,85,110);		// LDH - 28Feb09
			break;

		case "weather\skies\Converted\Twilight 2\\":	// 06:00
			Weathers.SpecialSeaFog.Color = argb(0,9,34,53);
			break;
	}

	// sun position based on Havana, May 16, 1690 - experimental 03Mar09
	switch (curTime)
	{
		case  6:
			Weathers.Sun.AzimuthAngle = Degree2Radian(160.0);
			Weathers.Sun.HeightAngle = Degree2Radian(2.0);
			break;
		case  7:
			Weathers.Sun.AzimuthAngle = Degree2Radian(165.0);
			Weathers.Sun.HeightAngle = Degree2Radian(15.0);
			break;
		case  8:
			Weathers.Sun.AzimuthAngle = Degree2Radian(170.0);
			Weathers.Sun.HeightAngle = Degree2Radian(28.0);
			break;
		case  9:
			Weathers.Sun.AzimuthAngle = Degree2Radian(175.0);
			Weathers.Sun.HeightAngle = Degree2Radian(42.0);
			break;
		case 10:
			Weathers.Sun.AzimuthAngle = Degree2Radian(180.0);
			Weathers.Sun.HeightAngle = Degree2Radian(56.0);
			break;
		case 11:
			Weathers.Sun.AzimuthAngle = Degree2Radian(187.0);
			Weathers.Sun.HeightAngle = Degree2Radian(70.0);
			break;
		case 12:
			Weathers.Sun.AzimuthAngle = Degree2Radian(213.0);
			Weathers.Sun.HeightAngle = Degree2Radian(83.0);
			break;
		case 13:
			Weathers.Sun.AzimuthAngle = Degree2Radian(335.0);
			Weathers.Sun.HeightAngle = Degree2Radian(81.0);
			break;
		case 14:
			Weathers.Sun.AzimuthAngle = Degree2Radian(355.0);
			Weathers.Sun.HeightAngle = Degree2Radian(68.0);
			break;
		case 15:
			Weathers.Sun.AzimuthAngle = Degree2Radian(1.0);
			Weathers.Sun.HeightAngle = Degree2Radian(54.0);
			break;
		case 16:
			Weathers.Sun.AzimuthAngle = Degree2Radian(6.0);
			Weathers.Sun.HeightAngle = Degree2Radian(40.0);
			break;
		case 17:
			Weathers.Sun.AzimuthAngle = Degree2Radian(11.0);
			Weathers.Sun.HeightAngle = Degree2Radian(27.0);
			break;
		case 18:
			Weathers.Sun.AzimuthAngle = Degree2Radian(16.0);
			Weathers.Sun.HeightAngle = Degree2Radian(13.0);
			break;
		case 19:
			Weathers.Sun.AzimuthAngle = Degree2Radian(21.0);
			Weathers.Sun.HeightAngle = Degree2Radian(0.1);
			break;
// default:
//		TraceAndLog("***** Hour was " + curTime);
	}
//TraceAndLog("Whr: AzimuthAngle = " + Radian2Degree(stf(Weathers.Sun.AzimuthAngle)) + ", HeightAngle = " + Radian2Degree(stf(Weathers.Sun.HeightAngle)));

	// modify SpecialSeaFog color for fog - 26Feb09

	int fogColor = sti(Weathers.SpecialSeaFog.color);
	int R = and(shr(fogColor, 16), 255);
	int G = and(shr(fogColor, 8), 255);
	int B = and(fogColor, 255);
//Trace("Original fog color = " + R + "," + G + "," + B);
	float avg = makefloat(R+G+B) / 3.0;		// average of R,G,B
	// adjust color to make it lighter
	avg *= 1.0 + stf(Weathers.SpecialSeaFog.Density)*100.0;	// fog of 0.001 gives 1.1 here
	// desaturate it a bit, makes fog more grey
	R = (avg*2.0 + R) / 3.0 + 0.5; if (R > 255) R = 255;
	G = (avg*2.0 + G) / 3.0 + 0.5; if (G > 255) G = 255;
	B = (avg*2.0 + B) / 3.0 + 0.5; if (B > 255) B = 255;
	Weathers.SpecialSeaFog.color = argb(0,R,G,B);
//Trace("Adjusted fog color = " + R + "," + G + "," + B);

}
