int Whr_GetColor(aref arRef, string sAttribute)
{
	return sti(arRef.(sAttribute));
}

float Whr_GetFloat(aref arRef, string sAttribute)
{
	string sTmpAttr = sAttribute + ".max";
	if (CheckAttribute(arRef,sTmpAttr))
	{
		float fMin = stf(arRef.(sAttribute).min);
		float fMax = stf(arRef.(sAttribute).max);
		return fMin + frnd() * (fMax - fMin);
	}
	return stf(arRef.(sAttribute));
}

int Whr_GetLong(aref arRef, string sAttribute)
{
	string sTmpAttr = sAttribute + ".max";
	if (CheckAttribute(arRef,sTmpAttr))
	{
		int iMin = sti(arRef.(sAttribute).min);
		int iMax = sti(arRef.(sAttribute).max);
		return iMin + rand(iMax - iMin - 1);
	}
	if (CheckAttribute(arRef, sAttribute))		// LDH added check  30 Mar09
	{
		return sti(arRef.(sAttribute));
	}
	return 0;
}

string Whr_GetString(aref arRef, string sAttribute)
{
	return arRef.(sAttribute);
}

void FixWeather(aref weather)
{
	if (!CheckAttribute(&weather, "Stars.Enable"))			{ weather.Stars.Enable = false; };
	if (!CheckAttribute(&weather, "Stars.Texture"))			{ weather.Stars.Texture = "weather\astronomy\stars.tga.tx"; };
	if (!CheckAttribute(&weather, "Stars.Color"))			{ weather.Stars.Color = argb(255,255,255,255); };
	if (!CheckAttribute(&weather, "Stars.Radius"))			{ weather.Stars.Radius = 2000.0; };
	if (!CheckAttribute(&weather, "Stars.Size"))			{ weather.Stars.Size = 15.0; };
	if (!CheckAttribute(&weather, "Stars.HeightFade"))		{ weather.Stars.HeightFade = 200.0; };
	if (!CheckAttribute(&weather, "Stars.SunFade"))			{ weather.Stars.SunFade = 1.0; };
	if (!CheckAttribute(&weather, "Stars.VisualMagnitude"))	{ weather.Stars.VisualMagnitude = 8.0; };

	if (!CheckAttribute(&weather, "Planets.Enable"))		{ weather.Planets.Enable = false; };
	if (!CheckAttribute(&weather, "Sounds.Sea.Postfix"))	{ weather.Sounds.Sea.Postfix = ""; };
	if (!CheckAttribute(&weather, "Sun.Moon"))				{ weather.Sun.Moon = false; };
	if (!CheckAttribute(&weather, "Sun.Reflection.Enable")) { weather.Sun.Reflection.Enable = false; }
	if (!CheckAttribute(&weather, "Lightning.Enable"))		{ weather.Lightning.Enable = false; };
	if (!CheckAttribute(&weather, "Rainbow.Enable"))		{ weather.Rainbow.Enable = false; };
	if (!CheckAttribute(&weather, "Rainbow.Texture"))		{ weather.Rainbow.Texture = "weather\rainbow\rainbow.tga.tx"; };

	if (!CheckAttribute(&weather, "Sun.Overflow.Enable"))	{ weather.Sun.Overflow.Enable = false; };
	if (!CheckAttribute(&weather, "Sun.Overflow.Texture"))	{ weather.Sun.Overflow.Texture = "weather\lightning\flash.tga.tx"; };
	if (!CheckAttribute(&weather, "Sun.Overflow.Color"))	{ weather.Sun.Overflow.Color = argb(255,25,25,25); };
	if (!CheckAttribute(&weather, "Sun.Overflow.Size"))		{ weather.Sun.Overflow.Size = 5500.0; };
	if (!CheckAttribute(&weather, "Sun.Overflow.Technique")){ weather.Sun.Overflow.Technique = "sunoverflow"; };
	if (!CheckAttribute(&weather, "Sun.Overflow.Start"))	{ weather.Sun.Overflow.Start = 0.7; };

	if (!CheckAttribute(&weather, "Rain.NumDrops"))			{ weather.Rain.NumDrops = 0; };
	if (!CheckAttribute(&weather, "Rain.Color"))			{ weather.Rain.Color = argb(0,73,73,73); };
	if (!CheckAttribute(&weather, "Rain.DropLength"))		{ weather.Rain.DropLength = 2.12; };
	if (!CheckAttribute(&weather, "Rain.Height"))			{ weather.Rain.Height = 30.0; };
	if (!CheckAttribute(&weather, "Rain.Radius"))			{ weather.Rain.Radius = 30.0; };
	if (!CheckAttribute(&weather, "Rain.Speed"))			{ weather.Rain.Speed = 18.0; };
	if (!CheckAttribute(&weather, "Rain.Jitter"))			{ weather.Rain.Jitter = 0.4; };
	if (!CheckAttribute(&weather, "Rain.WindSpeedJitter"))	{ weather.Rain.WindSpeedJitter = 0.5; };
	if (!CheckAttribute(&weather, "Rain.MaxBlend"))			{ weather.Rain.MaxBlend = 49; };
	if (!CheckAttribute(&weather, "Rain.TimeBlend"))		{ weather.Rain.TimeBlend = 2000; };

	if (!CheckAttribute(&weather, "Rain.DropsNearNum"))		{ weather.Rain.DropsNearNum = 500; };
	if (!CheckAttribute(&weather, "Rain.DropsFarNum"))		{ weather.Rain.DropsFarNum = 500; };
	if (!CheckAttribute(&weather, "Rain.DropsNearRadius"))	{ weather.Rain.DropsNearRadius = 25.0; };
	if (!CheckAttribute(&weather, "Rain.DropsFarRadius"))	{ weather.Rain.DropsFarRadius = 75.0; };
	if (!CheckAttribute(&weather, "Rain.DropsLifeTime"))	{ weather.Rain.DropsLifeTime = 0.25; };
	if (!CheckAttribute(&weather, "Rain.DropsSize"))		{ weather.Rain.DropsSize = 0.06; };
	if (!CheckAttribute(&weather, "Rain.DropsTexture"))		{ weather.Rain.DropsTexture = "weather\rain_drops.tga.tx"; };
	if (!CheckAttribute(&weather, "Rain.DropsColor"))		{ weather.Rain.DropsColor = argb(63,255,255,255); };

	if (!CheckAttribute(&weather, "Sea.GF2MX.Water.Color"))	{ weather.Sea.GF2MX.Sky.Color = argb(0,160,210,255); };
	if (!CheckAttribute(&weather, "Sea.GF2MX.Water.Color"))	{ weather.Sea.GF2MX.Water.Color = argb(0,25,55,80); };
	if (!CheckAttribute(&weather, "Sea.GF2MX.Bump.Tile"))	{ weather.Sea.GF2MX.Bump.Tile = 0.05; };
	if (!CheckAttribute(&weather, "Sea.GF2MX.Bump.AnimSpeed")) { weather.Sea.GF2MX.Bump.AnimSpeed = 7.0; };
	if (!CheckAttribute(&weather, "Sea.GF2MX.Bump.Dir"))	{ weather.Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\"; };

	if (!CheckAttribute(&weather, "Sea.Transparency"))		{ weather.Sea.Transparency = 0.9; };
	if (!CheckAttribute(&weather, "Sea.FrenelCoefficient"))	{ weather.Sea.FrenelCoefficient = 0.5; };
	if (!CheckAttribute(&weather, "Sea.WaterReflection"))	{ weather.Sea.WaterReflection = 0.9; };
	if (!CheckAttribute(&weather, "Sea.WaterAttenuation"))	{ weather.Sea.WaterAttenuation = 0.2; };
	if (!CheckAttribute(&weather, "Sea.Sky.Color"))			{ weather.Sea.Sky.Color = argb(0,190,190,190); };
	if (!CheckAttribute(&weather, "Sea.Water.Color"))		{ weather.Sea.Water.Color = argb(0,25,55,80); };
	if (!CheckAttribute(&weather, "Sea.Pena.Color"))		{ weather.Sea.Pena.Color = argb(0,175,175,155); };
	if (!CheckAttribute(&weather, "Sea.Bump.Dir"))			{ weather.Sea.Bump.Dir = "textures\weather\sea\bump_g3\"; };
	if (!CheckAttribute(&weather, "Sea.Bump.Tile"))			{ weather.Sea.Bump.Tile = 0.04; };
	if (!CheckAttribute(&weather, "Sea.Bump.Ang"))			{ weather.Sea.Bump.Ang = 0.0; };
	if (!CheckAttribute(&weather, "Sea.Bump.Speed"))		{ weather.Sea.Bump.Speed = 0.01; };
	if (!CheckAttribute(&weather, "Sea.Bump.AnimSpeed"))	{ weather.Sea.Bump.AnimSpeed = 15.0; };
	if (!CheckAttribute(&weather, "Sea.Bump.Scale"))		{ weather.Sea.Bump.Scale = 2.0; };

	if (!CheckAttribute(&weather, "Sea2.FoamEnable"))		{ weather.Sea2.FoamEnable = true; };
	if (!CheckAttribute(&weather, "Sea2.FoamK"))			{ weather.Sea2.FoamK = 0.1; };
	if (!CheckAttribute(&weather, "Sea2.FoamV"))			{ weather.Sea2.FoamV = 5.0; };
	if (!CheckAttribute(&weather, "Sea2.FoamUV"))			{ weather.Sea2.FoamUV = 0.05; };
	if (!CheckAttribute(&weather, "Sea2.FoamTexDisturb"))	{ weather.Sea2.FoamTexDisturb = 0.7; };

	if (!CheckAttribute(&weather, "Sea2.BumpScale"))	{ weather.Sea2.BumpScale = 0.05; };
	if (!CheckAttribute(&weather, "Sea2.WaterColor"))	{ weather.Sea2.WaterColor = argb(0, 25, 55, 80); };
	if (!CheckAttribute(&weather, "Sea2.SkyColor"))	{ weather.Sea2.SkyColor = argb(0, 205, 255, 255); };
	if (!CheckAttribute(&weather, "Sea2.Amp1"))	{ weather.Sea2.Amp1 =  7.0; };
	if (!CheckAttribute(&weather, "Sea2.AnimSpeed1"))	{ weather.Sea2.AnimSpeed1 =  2.0; };
	if (!CheckAttribute(&weather, "Sea2.Scale1"))	{ weather.Sea2.Scale1 =  0.30; };
	if (!CheckAttribute(&weather, "Sea2.MoveSpeed1"))	{ weather.Sea2.MoveSpeed1 =  "2.0, 0.0, 0.0"; };
	if (!CheckAttribute(&weather, "Sea2.Amp2"))	{ weather.Sea2.Amp2 =  1.1; };
	if (!CheckAttribute(&weather, "Sea2.AnimSpeed2"))	{ weather.Sea2.AnimSpeed2 =  19.0; };
	if (!CheckAttribute(&weather, "Sea2.Scale2"))	{ weather.Sea2.Scale2 =  3; };
	if (!CheckAttribute(&weather, "Sea2.MoveSpeed2"))	{ weather.Sea2.MoveSpeed2 =  "1.0, 0.0, 1.0"; };
	if (!CheckAttribute(&weather, "Sea2.PosShift"))	{ weather.Sea2.PosShift =  0.0; };
	if (!CheckAttribute(&weather, "Sea2.Reflection"))	{ weather.Sea2.Reflection =  0.9; };
	if (!CheckAttribute(&weather, "Sea2.Transparency"))	{ weather.Sea2.Transparency =  0.9; };
	if (!CheckAttribute(&weather, "Sea2.Attenuation"))	{ weather.Sea2.Attenuation =  0.3; };
	if (!CheckAttribute(&weather, "Sea2.Frenel"))	{ weather.Sea2.Frenel =  0.45; };
}
