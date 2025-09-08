void WhrDeleteSeaEnvironment()
{
	DeleteAttribute(&Sea,"");
}

void WhrCreateSeaEnvironment()
{
	aref	aCurWeather = GetCurrentWeather();
	aref	aSea; makearef(aSea,aCurWeather.Sea);
	aref	aSea2; makearef(aSea2, aCurWeather.Sea2);
	aref	aCommon; makearef(aCommon, WhrCommonParams.Sea);

	FixWeather(aCurWeather);

	float fMaxSeaHeight = 2.0;

	if(REALISTIC_WAVES == 1)
	{
		fMaxSeaHeight = 0.0000001; //KiwisDoFly - 0.1 - the value is useless now! See the .c files in the Init folder.
	}

	if (CheckAttribute(&Sea,"MaxSeaHeight")) { fMaxSeaHeight = stf(Sea.MaxSeaHeight); }
	DeleteAttribute(&Sea,"");
	Sea.MaxSeaHeight = fMaxSeaHeight;

	Sea.Clear = "";

	Sea.Lights = aCurWeather.Lights;

	Sea.Transparency = Whr_GetFloat(aSea,"Transparency");
	Sea.FrenelCoefficient = Whr_GetFloat(aSea,"FrenelCoefficient");
	Sea.WaterReflection = Whr_GetFloat(aSea,"WaterReflection");
	Sea.WaterAttenuation = Whr_GetFloat(aSea,"WaterAttenuation");

	Sea.Sea2.BumpScale = Whr_GetFloat(aSea2, "BumpScale");

	switch (GetTargetPlatform()) 
	{
		case "xbox":	Sea.GridStep = 0.10;	break;
		case "pc":		Sea.GridStep = 0.10;	break;
	}
	Sea.LodScale = 4.0;
	Sea.MaxDim = 65536;
	Sea.MinDim = 128;
	Sea.Water.Color = Whr_GetColor(aSea,"Water.Color");

	Sea.Sun.Color = Whr_GetColor(aCurWeather,"Sun.Color");
	Sea.Sun.HeightAngle = Whr_GetFloat(aCurWeather,"Sun.HeightAngle");
	Sea.Sun.AzimuthAngle = Whr_GetFloat(aCurWeather,"Sun.AzimuthAngle");

	string sCurFog = Whr_GetCurrentFog();
	Sea.Fog.Color = Whr_GetColor(aCurWeather, sCurFog + ".Color");
	Sea.Fog.Enable = Whr_GetLong(aCurWeather, sCurFog + ".Enable");
	Sea.Fog.Start = Whr_GetFloat(aCurWeather, sCurFog + ".Start");
	Sea.Fog.Density = Whr_GetFloat(aCurWeather, sCurFog + ".Density");
	Sea.Fog.SeaDensity = Whr_GetFloat(aCurWeather, sCurFog + ".SeaDensity");
	
	Sea.Pena.Color = Whr_GetColor(aSea,"Pena.Color");
	Sea.Pena.DepthSmall = 20.0;
	Sea.Pena.DepthBig = 20.0;
	Sea.Pena.BigIslandMultiply = Whr_GetFloat(aCommon, "Pena.BigIslandMultiply");
	Sea.Pena.SmallIslandMultiply = Whr_GetFloat(aCommon, "Pena.SmallIslandMultiply");
	
	Sea.Bump.Dir = Whr_GetString(aSea, "Bump.Dir");
	Sea.Bump.Tile = Whr_GetFloat(aSea, "Bump.Tile");
	Sea.Bump.Ang = Whr_GetFloat(aSea, "Bump.Ang");
	Sea.Bump.Speed = Whr_GetFloat(aSea, "Bump.Speed");
	Sea.Bump.Scale = Whr_GetFloat(aSea, "Bump.Scale");
	Sea.Bump.AnimSpeed = Whr_GetFloat(aSea, "Bump.AnimSpeed");
	// 04-12-15 now always use 4, since we supply bump.zap - Sea.Bump.MipLevels = 1;
	Sea.Bump.MipLevels = 4; // Taghmon
	Sea.Bump.Size = 128;

	Sea.GF2MX.BumpDir = Whr_GetString(aSea, "GF2MX.Bump.Dir");
	Sea.GF2MX.BumpTile = Whr_GetFloat(aSea, "GF2MX.Bump.Tile");
	Sea.GF2MX.BumpAnimSpeed = Whr_GetFloat(aSea, "GF2MX.Bump.AnimSpeed");
	Sea.GF2MX.WaterColor = Whr_GetColor(aSea, "GF2MX.Water.Color");
	Sea.GF2MX.SkyColor = Whr_GetColor(aSea, "GF2MX.Sky.Color");

	Sea.GF3.BumpDir = Whr_GetString(aSea, "Bump.Dir");
	Sea.GF3.BumpTile = Whr_GetFloat(aSea, "Bump.Tile");
	Sea.GF3.BumpAnimSpeed = Whr_GetFloat(aSea, "Bump.AnimSpeed");
	Sea.GF3.WaterColor = Whr_GetColor(aSea, "Water.Color");
	Sea.GF3.SkyColor = Whr_GetColor(aSea, "Sky.Color");

	Sea.MaxVertices = 4000;
	Sea.MaxIndices = 5200;

	Sea.MaxWaveDistance = 768.0;

	// Sun road section
	Sea.Road.Start = Whr_GetFloat(aSea, "SunRoad.Start");
	Sea.Road.Color1 = Whr_GetColor(aSea, "SunRoad.Color1");
	Sea.Road.Color2 = Whr_GetColor(aSea, "SunRoad.Color2");
	Sea.Road.Power = Whr_GetFloat(aSea, "SunRoad.Power");

	if (CheckAttribute(aSea, "SunRoad.Special"))
	{
		Sea.Sun.HeightAngle = Whr_GetFloat(aSea, "SunRoad.Special.HeightAngle");
		Sea.Sun.AzimuthAngle = Whr_GetFloat(aSea, "SunRoad.Special.AzimuthAngle");
	}

	Sea.CubeMap.Size = 512;
	Sea.CubeMap.VectorsSize = 256;
	Sea.CubeMap.Format = "r5g6b5";

	Sea.Sky.Color = Whr_GetColor(aSea, "Sky.Color");

	// Advanced Sea initialize
	Sea.Sea2.WaterColor = Whr_GetColor(aSea2, "WaterColor");
	Sea.Sea2.SkyColor = Whr_GetColor(aSea2, "SkyColor");

	Sea.Sea2.Amp1 = Whr_GetFloat(aSea2, "Amp1");
	Sea.Sea2.AnimSpeed1 = Whr_GetFloat(aSea2, "AnimSpeed1");
	Sea.Sea2.Scale1 = Whr_GetFloat(aSea2, "Scale1");
	Sea.Sea2.MoveSpeed1 = Whr_GetString(aSea2, "MoveSpeed1");

	Sea.Sea2.Amp2 = Whr_GetFloat(aSea2, "Amp2");
	Sea.Sea2.AnimSpeed2 = Whr_GetFloat(aSea2, "AnimSpeed2");
	Sea.Sea2.Scale2 = Whr_GetFloat(aSea2, "Scale2");
	Sea.Sea2.MoveSpeed2 = Whr_GetString(aSea2, "MoveSpeed2");

	Sea.Sea2.PosShift = Whr_GetFloat(aSea2, "PosShift");

	Sea.Sea2.Reflection = Whr_GetFloat(aSea2, "Reflection");
	Sea.Sea2.Transparency = Whr_GetFloat(aSea2, "Transparency");
	Sea.Sea2.Attenuation = Whr_GetFloat(aSea2, "Attenuation");
	Sea.Sea2.Frenel = Whr_GetFloat(aSea2, "Frenel");

	// Sea.Sea2.SimpleSea = sti(InterfaceStates.SimpleSea);

	// Sea.Sea2.FoamEnable = false;

	// foam enable
	Sea.Sea2.FoamEnable = true;
	Sea.Sea2.FoamK = Whr_GetFloat(aSea2, "FoamK");
	Sea.Sea2.FoamV = Whr_GetFloat(aSea2, "FoamV");
	Sea.Sea2.FoamUV = Whr_GetFloat(aSea2, "FoamUV");
	Sea.Sea2.FoamTexDisturb = Whr_GetFloat(aSea2, "FoamTexDisturb");


	if(CheckAttribute(aSea2, "LodScale"))
        Sea.Sea2.LodScale = Whr_GetFloat(aSea2, "LodScale");
    if(CheckAttribute(aSea2, "GridStep"))
        Sea.Sea2.GridStep = Whr_GetFloat(aSea2, "GridStep");

	Sea.MaxSeaHeight = fMaxSeaHeight;
	Sea.isDone = "";

	// if (bSeaActive && !bAbordageStarted)
	// {
	// 	pchar.SystemInfo.ScaleSeaHeight = GetScaleSeaHeight();
	// }

	Sea.isDone = "";
}

