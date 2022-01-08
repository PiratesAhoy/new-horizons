object Sky;

void WhrDeleteSkyEnvironment()
{
	if (isEntity(&Sky))
	{
		DeleteClass(&Sky);
	}
	DeleteAttribute(&Sky,"");
}

void WhrCreateSkyEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aSky; makearef(aSky,aCurWeather.Sky);

	DeleteAttribute(&Sky,"");
	if (!isEntity(&Sky))
	{
		CreateEntity(&Sky,"Sky");
		LayerAddObject(SEA_REFLECTION,&Sky,1);
	}

    //JRH -->
	ref PChar = GetMainCharacter();

	if(CheckAttribute(Pchar,"quest.JRH_sky"))
	{
		switch(Pchar.quest.JRH_sky)
		{
			case "1_Bl":
				Sky.Dir = "weather\skies\1\\";
			break;

			case "2_Rd":
				Sky.Dir = "weather\skies\2\\";
			break;

			case "3_Pu":
				Sky.Dir = "weather\skies\3\\";
			break;

			case "4_Rd":
				Sky.Dir = "weather\skies\4\\";
			break;

			case "5_Gr":
				Sky.Dir = "weather\skies\5\\";
			break;

			case "6_Ni":
				Sky.Dir = "weather\skies\6\\";
			break;

			case "7_Gr":
				Sky.Dir = "weather\skies\7\\";
			break;

			case "8_Bl":
				Sky.Dir = "weather\skies\8\\";
			break;

			case "C_Bl1":
				Sky.Dir = "weather\skies\Converted\Blue 1\\";
			break;

			case "C_Cl1":
				Sky.Dir = "weather\skies\Converted\Clouds 1\\";
			break;

			case "C_Cl2":
				Sky.Dir = "weather\skies\Converted\Clouds 2\\";
			break;

			case "C_Cl3":
				Sky.Dir = "weather\skies\Converted\Clouds 3\\";
			break;

			case "C_Cl5":
				Sky.Dir = "weather\skies\Converted\Clouds 5\\";
			break;

			case "C_Cl6":
				Sky.Dir = "weather\skies\Converted\Clouds 6\\";
			break;

			case "C_Ni1":
				Sky.Dir = "weather\skies\Converted\Night 1\\";
				Sky.Color = argb(0,200,200,255);
			break;

			case "C_Ni2":
				Sky.Dir = "weather\skies\Converted\Night 2\\";
				Sky.Color = argb(0,200,200,255);
			break;

			case "C_Ni3":
				Sky.Dir = "weather\skies\Converted\Night 3\\";
			break;

			case "C_Ni4":
				Sky.Dir = "weather\skies\Converted\Night 4\\";
				Log_SetStringToLog("JRH_sky = Night 4");
			break;

			case "C_Ni5":
				Sky.Dir = "weather\skies\Converted\Night 5\\";
			break;

			case "C_Ov1":
				Sky.Dir = "weather\skies\Converted\Overcast 1\\";
			break;

			case "C_Ov2":
				Sky.Dir = "weather\skies\Converted\Overcast 2\\";
			break;

			case "C_Ov3":
				Sky.Dir = "weather\skies\Converted\Overcast 3\\";
			break;

			case "C_Ov4":
				Sky.Dir = "weather\skies\Converted\Overcast 4\\";
			break;

			case "C_Ov5":
				Sky.Dir = "weather\skies\Converted\Overcast 5\\";
			break;

			case "C_Ov6":
				Sky.Dir = "weather\skies\Converted\Overcast 6\\";
			break;

			case "C_Ov7":
				Sky.Dir = "weather\skies\Converted\Overcast 7\\";
			break;

			case "C_St1":
				Sky.Dir = "weather\skies\Converted\Stormy 1\\";
			break;

			case "C_St2":
				Sky.Dir = "weather\skies\Converted\Stormy 2\\";
			break;

			case "C_Su1":
				Sky.Dir = "weather\skies\Converted\Sunset 1\\";
			break;

			case "C_Su2":
				Sky.Dir = "weather\skies\Converted\Sunset 2\\";
			break;

			case "C_Su3":
				Sky.Dir = "weather\skies\Converted\Sunset 3\\";
			break;

			case "C_Su8":
				Sky.Dir = "weather\skies\Converted\Sunset 8\\";
			break;

			case "C_Tw1":
				Sky.Dir = "weather\skies\Converted\Twilight 1\\";
			break;

			case "C_Tw2":
				Sky.Dir = "weather\skies\Converted\Twilight 2\\";
			break;

			//Default
			Sky.Dir = Whr_GetString(aSky,"Dir");
			Sky.Color = Whr_GetColor(aSky,"Color");
		}
	}
	else
	{
		Sky.Dir = Whr_GetString(aSky,"Dir");
		Sky.Color = Whr_GetColor(aSky,"Color");
	}
    //<-- JRH

	Sky.Angle = Whr_GetFloat(aSky,"Angle");
	Sky.RotateSpeed = Whr_GetFloat(aSky,"Rotate");
	Sky.Size = Whr_GetFloat(aSky,"Size");

	Sky.isDone = "";
}

void MoveSkyToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject(EXECUTE,&Sky);
	LayerDelObject(REALIZE,&Sky);
	LayerDelObject(SEA_EXECUTE,&Sky);
	LayerDelObject(SEA_REALIZE,&Sky);

	LayerAddObject(sExecuteLayer,&Sky,2);
	LayerAddObject(sRealizeLayer,&Sky,2);
}
