object SunGlow;

void WhrDeleteSunGlowEnvironment()
{
	if (isEntity(&SunGlow))
	{
		DeleteClass(&SunGlow);
	}
	DeleteAttribute(&SunGlow,"");
}

void WhrCreateSunGlowEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aSun;		makearef(aSun, aCurWeather.Sun);
	aref aGlow;		makearef(aGlow, aSun.Glow);
	aref aFlare;	makearef(aFlare, aSun.Flare);
	aref aOverflow;	makearef(aOverflow, aSun.Overflow);

	SunGlow.Clear = "";
	DeleteAttribute(&SunGlow,"");

	if (sti(aSun.Glow.Enable) == false && sti(aSun.Flare.Enable) == false)) return;

	// create sunglow
	if (!isEntity(&SunGlow))
	{
		CreateEntity(&SunGlow,"SunGlow");
		LayerAddObject("sea_reflection",&SunGlow,-1);
	}

	if (sti(aSun.Glow.Enable) != false)
	{
		SunGlow.Glow.Dist = Whr_GetFloat(aGlow,"Dist");
		SunGlow.Glow.Size = Whr_GetFloat(aGlow,"Size");
		SunGlow.Glow.Texture = Whr_GetString(aGlow,"Texture");
		SunGlow.Glow.Color = Whr_GetColor(aGlow,"Color");
		SunGlow.Glow.RotateSpeed = Whr_GetColor(aGlow,"RotateSpeed");
		SunGlow.Glow.DecayTime = Whr_GetColor(aGlow,"DecayTime");
		SunGlow.Glow.TechniqueZ = Whr_GetString(aGlow,"TechniqueZ");
		SunGlow.Glow.TechniqueNoZ = Whr_GetString(aGlow,"TechniqueNoZ");
	}

	if (sti(aSun.Flare.Enable) != false)
	{
		SunGlow.Flare.Dist = Whr_GetFloat(aFlare,"Dist");
		SunGlow.Flare.Technique = Whr_GetString(aFlare,"Technique");
		SunGlow.Flare.Scale = Whr_GetFloat(aFlare,"Scale");
		SunGlow.Flare.Texture = Whr_GetString(aFlare,"Texture");
		SunGlow.Flare.TexSizeX = Whr_GetString(aFlare,"TexSizeX");
		SunGlow.Flare.TexSizeY = Whr_GetString(aFlare,"TexSizeY");

		aref aFlares; makearef(aFlares,aSun.Flares);
		int iNumFlares = GetAttributesNum(aFlares);
		for (int i=0;i<iNumFlares;i++)
		{
			aref aFlareN = GetAttributeN(aFlares,i);
			string sTemp = "f" + i;
			SunGlow.Flares.(sTemp) = GetAttributeValue(aFlareN);
		}
	}

	if (sti(aSun.Overflow.Enable) != false)
	{
		SunGlow.Overflow.Texture = Whr_GetString(aOverflow,"Texture");
		SunGlow.Overflow.Technique = Whr_GetString(aOverflow,"Technique");
		SunGlow.Overflow.Size = Whr_GetFloat(aOverflow,"Size");
		SunGlow.Overflow.Color = Whr_GetColor(aOverflow,"Color");
		SunGlow.Overflow.Start = Whr_GetFloat(aOverflow,"Start");
	}

	SunGlow.isDone = true;
}

void MoveSunGlowToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject("execute",&SunGlow);
	LayerDelObject("realize",&SunGlow);
	LayerDelObject(SEA_EXECUTE,&SunGlow);
	LayerDelObject(SEA_REALIZE,&SunGlow);

	LayerAddObject(sExecuteLayer, &SunGlow, -2);
	LayerAddObject(sRealizeLayer, &SunGlow, -2);
}