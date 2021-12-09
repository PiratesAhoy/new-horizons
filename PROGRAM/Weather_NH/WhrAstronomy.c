object Astronomy;

#define ASTRONOMYDEBUG 0
#define PLANETSCALE 1.25
#define STARCOLORBLEND 0.1

void WhrDeleteAstronomyEnvironment()
{
	if (isEntity(&Astronomy))
	{
		DeleteClass(&Astronomy);
	}
	DeleteAttribute(&Astronomy, "");
}

void WhrCreateAstronomyEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aStars;	makearef(aStars, aCurWeather.Stars);
	aref aPlanets;	makearef(aPlanets, aCurWeather.Planets);

	DeleteAttribute(&Astronomy, "");

	if (!isEntity(&Astronomy))
	{
		CreateEntity(&Astronomy, "Astronomy");
		//LayerAddObject("sea_reflection", &Astronomy, -1);
	}
	Astronomy.TimeScale = 1.0;

	//#20191020-01
	FillStars(aStars);

	/*Astronomy.Planets.Enable = Whr_GetLong(aPlanets, "Enable");
	if (sti(Astronomy.Planets.Enable))
	{
		Astronomy.Planets.Scale = 1.0;
		Astronomy.Planets.Speed = 10.0;
	}*/

	Astronomy.Planets.Planet.Mercury.Distance = 0.38710;
	Astronomy.Planets.Planet.Mercury.Speed = 48.8;
	Astronomy.Planets.Planet.Mercury.Inclination = 7.0;
	Astronomy.Planets.Planet.Mercury.Diameter = 4870.0;
	Astronomy.Planets.Planet.Mercury.Scale = 10.0;
	Astronomy.Planets.Planet.Mercury.Mag.Min = 1.3;
	Astronomy.Planets.Planet.Mercury.Mag.Max = -1.0;

	Astronomy.Planets.Planet.Venus.Distance = 0.72333;
	Astronomy.Planets.Planet.Venus.Speed = 35.0;
	Astronomy.Planets.Planet.Venus.Inclination = 3.39;
	Astronomy.Planets.Planet.Venus.Diameter = 12100.0;
	Astronomy.Planets.Planet.Venus.Scale = 1.0;
	Astronomy.Planets.Planet.Venus.Mag.Min = -3.0;
	Astronomy.Planets.Planet.Venus.Mag.Max = -4.3;

	Astronomy.Planets.Planet.Mars.Distance = 1.52363;
	Astronomy.Planets.Planet.Mars.Speed = 24.4;
	Astronomy.Planets.Planet.Mars.Inclination =  1.85;
	Astronomy.Planets.Planet.Mars.Diameter = 6670.0;
	Astronomy.Planets.Planet.Mars.Scale = 3.0;
	Astronomy.Planets.Planet.Mars.Mag.Min = 1.6;
	Astronomy.Planets.Planet.Mars.Mag.Max = -2.8;

	Astronomy.Planets.Planet.Jupiter.Distance = 5.20441;
	Astronomy.Planets.Planet.Jupiter.Speed = 13.06;
	Astronomy.Planets.Planet.Jupiter.Inclination = 1.30;
	Astronomy.Planets.Planet.Jupiter.Diameter = 143760.0;
	Astronomy.Planets.Planet.Jupiter.Mag.Min = -1.9;
	Astronomy.Planets.Planet.Jupiter.Mag.Max = -2.2;

	Astronomy.Planets.Planet.Saturn.Distance = 9.58378;
	Astronomy.Planets.Planet.Saturn.Speed = 9.65;
	Astronomy.Planets.Planet.Saturn.Inclination = 2.49;
	Astronomy.Planets.Planet.Saturn.Diameter = 120420.0;
	Astronomy.Planets.Planet.Saturn.Scale = 4.0;
	Astronomy.Planets.Planet.Saturn.Mag.Min = 1.5;
	Astronomy.Planets.Planet.Saturn.Mag.Max = -0.4;

	Astronomy.Planets.Planet.Uranus.Distance = 19.18722;
	Astronomy.Planets.Planet.Uranus.Speed = 6.78;
	Astronomy.Planets.Planet.Uranus.Inclination = 0.77;
	Astronomy.Planets.Planet.Uranus.Diameter = 51300.0;
	Astronomy.Planets.Planet.Uranus.Scale = 10.0;
	Astronomy.Planets.Planet.Uranus.Mag.Min = 6.0;
	Astronomy.Planets.Planet.Uranus.Mag.Max = 5.4;

	//Astronomy.Planets.Planet.Neptune.Distance = 30.02090;
	//Astronomy.Planets.Planet.Neptune.Speed = 5.42;
	//Astronomy.Planets.Planet.Neptune.Inclination = 1.77;
	//Astronomy.Planets.Planet.Neptune.Diameter = 49500.0;
	//Astronomy.Planets.Planet.Neptune.Scale = 15.0;
	//Astronomy.Planets.Planet.Neptune.Mag.Min = 7.7;
	//Astronomy.Planets.Planet.Neptune.Mag.Max = 7.6;

	//Astronomy.Planets.Planet.Pluto.Distance = 39.23107;
	//Astronomy.Planets.Planet.Pluto.Speed = 4.73;
	//Astronomy.Planets.Planet.Pluto.Inclination = 17.2;
	//Astronomy.Planets.Planet.Pluto.Diameter = 2324.0;
	//Astronomy.Planets.Planet.Pluto.Mag.Min = 14.3;
	//Astronomy.Planets.Planet.Pluto.Mag.Max = 14.3;

	Astronomy.isDone = true;
}
//#20191020-01
void FillStars(ref aStars)
{
    if(!IsEntity(&Astronomy)) return;

	if (ASTRONOMYDEBUG) Trace("Astronomy enable: " + Whr_GetLong(aStars, "Enable"));

    Astronomy.Stars.Enable = Whr_GetLong(aStars, "Enable");
	if (sti(Astronomy.Stars.Enable))
	{
		Astronomy.Stars.Catalog = "hic.dat";
		Astronomy.Stars.Texture = Whr_GetString(aStars, "Texture");
		if (ASTRONOMYDEBUG) Trace("Astronomy Texture: " + Whr_GetString(Astronomy, "Stars.Texture"));		
		Astronomy.Stars.Color = Whr_GetColor(aStars, "Color");
		if (ASTRONOMYDEBUG) Trace("Astronomy Color: " + Whr_GetColor(Astronomy, "Stars.Color"));		
		Astronomy.Stars.Radius = Whr_GetFloat(aStars, "Radius");
		if (ASTRONOMYDEBUG) Trace("Astronomy Radius: " + Whr_GetFloat(Astronomy, "Stars.Radius"));		
		Astronomy.Stars.Size = Whr_GetFloat(aStars, "Size");
		if (ASTRONOMYDEBUG) Trace("Astronomy Size: " + Whr_GetFloat(Astronomy, "Stars.Size"));		
		Astronomy.Stars.HeightFade = Whr_GetFloat(aStars, "HeightFade");
		if (ASTRONOMYDEBUG) Trace("Astronomy HeightFade: " + Whr_GetFloat(Astronomy, "Stars.HeightFade"));		
		Astronomy.Stars.SunFade = Whr_GetFloat(aStars, "SunFade");
		if (ASTRONOMYDEBUG) Trace("Astronomy SunFade: " + Whr_GetFloat(Astronomy, "Stars.SunFade"));		

		Astronomy.Stars.VisualMagnitude = Whr_GetFloat(aStars, "VisualMagnitude");
		if (ASTRONOMYDEBUG) Trace("Astronomy VisualMagnitude: " + Whr_GetFloat(Astronomy, "Stars.VisualMagnitude"));		
		Astronomy.Stars.TelescopeMagnitude = 10.0;

		Astronomy.Stars.TextureX = 4;
		Astronomy.Stars.TextureY = 4;

		Astronomy.Stars.Spectr.W = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 150, 243, 220));
		Astronomy.Stars.Spectr.O = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 150, 243, 220));
		Astronomy.Stars.Spectr.B = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 226, 244, 223));
		Astronomy.Stars.Spectr.A = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 255, 243, 213));
		Astronomy.Stars.Spectr.F = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 255, 243, 170));
		Astronomy.Stars.Spectr.G = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 255, 244, 123));
		Astronomy.Stars.Spectr.K = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 255, 187, 117));
		Astronomy.Stars.Spectr.M = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 249, 142, 117));
		Astronomy.Stars.Spectr.L = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 223, 142, 117));
		Astronomy.Stars.Spectr.T = Whr_BlendColor( STARCOLORBLEND, argb(0, 255, 255, 255), argb(0, 209, 155, 123));

		
	}
	FillAstronomyFadeValue();
}

void FillAstronomyFadeValue()
{
	Astronomy.Planets.Enable = Whr_GetLong(&Weathers[iCurWeatherNum],"Planets.Enable");
	if (sti(Astronomy.Planets.Enable))
	{
		Astronomy.Planets.Scale = PLANETSCALE;
		Astronomy.Planets.Speed = 10.0;

		Astronomy.Planets.FadeValue = 1.0;
		if( iBlendWeatherNum<0 || Whr_GetLong(&Weathers[iBlendWeatherNum],"Planets.Enable") ) {
			Astronomy.Planets.FadeStartTime = -1.0;
		} else {
			Astronomy.Planets.FadeStartTime = makefloat(sti(Environment.Time)) + 0.2;
		}
		Astronomy.Planets.FadeTime = -0.2;
	} else {
		Astronomy.Planets.Scale = PLANETSCALE;
		Astronomy.Planets.Speed = 10.0;

		Astronomy.Planets.FadeValue = 0.0;
		if( iBlendWeatherNum>=0 && Whr_GetLong(&Weathers[iBlendWeatherNum],"Planets.Enable") ) {
			Astronomy.Planets.FadeStartTime = makefloat(sti(Environment.Time)) + 0.6;
		} else {
			Astronomy.Planets.FadeStartTime = -1.0;
		}
		Astronomy.Planets.FadeTime = 0.2;
	}
	Astronomy.Stars.Enable = Whr_GetLong(&Weathers[iCurWeatherNum], "Stars.Enable");
	if (ASTRONOMYDEBUG) Trace("FillAstronomy enable: " + Whr_GetLong(Astronomy, "Stars.Enable"));
	if (sti(Astronomy.Stars.Enable))
	{
		Astronomy.Stars.Radius = Whr_GetFloat(&Weathers[iCurWeatherNum], "Stars.Radius");
		if (ASTRONOMYDEBUG) Trace("FillAstronomy Radius: " + Whr_GetFloat(Astronomy, "Stars.Radius"));		
		Astronomy.Stars.HeightFade = Whr_GetFloat(&Weathers[iCurWeatherNum], "Stars.HeightFade");

		Astronomy.Stars.FadeValue = 1.0;
		if( iBlendWeatherNum<0 || Whr_GetLong(&Weathers[iBlendWeatherNum],"Stars.Enable") ) {
			Astronomy.Stars.FadeStartTime = -1.0;
		} else {
			Astronomy.Stars.FadeStartTime = makefloat(sti(Environment.Time)) + 0.2;
		}
		Astronomy.Stars.FadeTime = -0.2;
		if (ASTRONOMYDEBUG) Trace("FillAstronomy FadeStartTime: " + Whr_GetFloat(Astronomy, "Stars.FadeStartTime"));		
		if (ASTRONOMYDEBUG) Trace("FillAstronomy FadeTime: " + Whr_GetFloat(Astronomy, "Stars.FadeTime"));		
		
	}
	else
	{
		Astronomy.Stars.FadeValue = 0.0;
		if( iBlendWeatherNum>=0 && Whr_GetLong(&Weathers[iBlendWeatherNum],"Stars.Enable") ) {
			Astronomy.Stars.FadeStartTime = makefloat(sti(Environment.Time)) + 0.6;
		} else {
			Astronomy.Stars.FadeStartTime = -1.0;
		}
		Astronomy.Stars.FadeTime = 0.2;
	}

	if (ASTRONOMYDEBUG) Trace("FillAstronomy done"));
}

void MoveAstronomyToLayers(string sExecuteLayer, string sRealizeLayer)
{
	// LayerDelObject("execute", &Astronomy);
	// LayerDelObject("realize", &Astronomy);
	// LayerDelObject(SEA_EXECUTE, &Astronomy);
	// LayerDelObject(SEA_REALIZE, &Astronomy);

	// LayerAddObject(sExecuteLayer, &Astronomy, -1);
	// LayerAddObject(sRealizeLayer, &Astronomy, 2);
}
