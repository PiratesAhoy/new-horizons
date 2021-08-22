object Animals;

void CreateAnimals(ref Location)
{
	if (!IsEntity(Animals))
		CreateEntity(&Animals, "Animals");

	float midX, midY, midZ;
	SendMessage(Location, "lseee", MSG_LOCATION_EX_MSG, "GetPatchMiddlePos", &midX, &midY, &midZ);
	Animals.midY = midY;

	aref locator_group;
	aref locator;
	int n;
	int num;
	
	//DumpAttributes(Location);

	SendMessage(Animals, "l", MSG_ANIMALS_BUTTERFLIES_HIDE);
	SendMessage(Animals, "l", MSG_ANIMALS_FISHSCHOOLS_HIDE);
	SendMessage(Animals, "l", MSG_ANIMALS_SEAGULLS_HIDE);

	if (!Whr_IsRain() /*&& !Whr_IsNight() && !Whr_IsStorm() && (Location.environment.sea == "true") && (Location.environment.weather == "true")*/)
	{
		if (!Whr_IsNight())
		{
			if (!Whr_IsStorm())
			{
				// seagulls
				if(CheckAttribute(Location, "locators") && (Location.environment.weather == "true"))
				{
					SendMessage(Animals, "l", MSG_ANIMALS_SEAGULLS_SHOW);
					if(CheckAttribute(Location, "locators.seagull"))
					{
						makearef(locator_group, location.locators.seagull);
						num = GetAttributesNum(locator_group);
						for(n = 0; n < num; n++)
						{
							locator = GetAttributeN(locator_group, n);
							SendMessage(Animals, "lfff", MSG_ANIMALS_SEAGULLS_ADD, stf(locator.x), stf(locator.y), stf(locator.z));
						}
					}
				}

				// butterflies
				if (HasSubStr(Location.type, "jungle") || HasSubStr(Location.type, "garden")) // Screwface & JRH for KR jungle support for animals
				{
					SendMessage(Animals, "l", MSG_ANIMALS_BUTTERFLIES_SHOW);
				}
			}
		}
	}
	
	bool crtAnimals;

	if(CheckAttribute(Location, "type"))
	{
		if((Location.type == "jungle") || (Location.type == "KR_Jungle") || (Location.type == "Den")) // KK
		{
			//????
			if(rand(100) < 80)
			{
				crtAnimals = true;
				if(!IsDay()) crtAnimals = false;
				if(Whr_GetWindSpeed() > 10.0) crtAnimals = false;
				if(Whr_IsRain()) crtAnimals = false;
				if(Whr_IsStorm()) crtAnimals = false;
				if(Whr_GetFogDensity() > 0.008) crtAnimals = false;
				if(crtAnimals)
				{
					SendMessage(Location, "ls", MSG_LOCATION_EX_MSG, "AddEagle");
				}
			}
			//???????
			if(rand(100) < 95)
			{
				crtAnimals = true;
				if(Whr_IsStorm()) crtAnimals = false;
				if(Whr_GetFogDensity() > 0.008) crtAnimals = false;
				if(Whr_GetWindSpeed() > 10.0) crtAnimals = false;
				if(crtAnimals)
				{
					SendMessage(Location, "ls", MSG_LOCATION_EX_MSG, "AddLizards");
				}
			}
			//?????
			if(rand(100) < 50)
			{
				if(IsDay())
				{
					if(rand(100) < 50)
					{
						SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 1 + rand(2));
					}
				}else{
					SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 1 + rand(4));
				}
			}
		}
		if(Location.type == "Dungeon")
		{
			//?????
			if(rand(100) < 95)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 16 + rand(16));
			}
		}
		if(Location.type == "jail")
		{
			//?????
			if(rand(100) < 75)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 1 + rand(3));
			}
		}
		if(Location.type == "town")
		{
			//?????
			if(rand(100) < 35)
			{
				crtAnimals = true;
				if(Whr_IsStorm()) crtAnimals = false;
				if(Whr_GetFogDensity() > 0.008) crtAnimals = false;
				if(Whr_GetWindSpeed() > 10.0) crtAnimals = false;
				if(crtAnimals)
				{
					if(IsDay())
					{
						SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 1 + rand(2));
					}else{
						SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 2 + rand(4));
					}
				}
			}
		}
//JRH -->
		if(Location.id == "Tortuga_port")
		{
			crtAnimals = true;
		//	if(Whr_IsStorm()) crtAnimals = false;
			if(crtAnimals)
			{
				if(IsDay())
				{
						SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 20 + rand(5));
				}else{
						SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 25 + rand(10));
				}
			}
		}
		else
		{
			if(HasSubStr(Location.id,"Tortuga"))
			{
				if(Location.type != "jail")
				{
					SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(2));
				}
			}
		}
	
		if(Location.id == "Oranjestad_store_02")
		{
			crtAnimals = true;
			if(crtAnimals)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 1);
			}
		}
	
		if(Location.id == "Legrands_attic")
		{
			crtAnimals = true;
			if(crtAnimals)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 2);
			}
		}

		if(Location.id == "Turks_wreck_shore")
		{
			crtAnimals = true;
			if(crtAnimals)
			{
				if(IsDay())
				{
					SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 50 + rand(5));
				}else{
					SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 60 + rand(10));
				}
			}
		}

		if(Location.id == "BB_crypt2_2")
		{
			crtAnimals = true;
			if(crtAnimals)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 200);
			}
		}

		if(Location.id == "BB_abbey_cell")
		{
			crtAnimals = true;
			if(crtAnimals)
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 50);
			}
		}

		if(Location.id == "BB_prison_alcove")
		{
			crtAnimals = true;
			if(crtAnimals) SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 2000);
		}

		if(Location.id == "BB_prison")
		{
			crtAnimals = true;
			if(crtAnimals) SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 10);
		}

		if(Location.id == "BB_prison2")
		{
			crtAnimals = true;
			if(crtAnimals) 
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 300);
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddLizards", 100);
			}
		}

		if(Location.id == "BB_lower_cave")
		{
			crtAnimals = true;
			if(crtAnimals) SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 5);
		}

		if(Location.id == "BB_burning_cave")
		{
			crtAnimals = true;
			if(crtAnimals) 
			{
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", 600);
				SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddLizards", 400);
			}
		}

		if(Location.id == "BB_careen_holdP")
		{
			crtAnimals = true;
			if(crtAnimals) SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(4) + rand(4));
		}
//<-- JRH	
	}
//JRH -->

	//changed by MAXIMUS, completed by JRH -->
	bool bAdd = false;
	if(CheckAttribute(LOCATION, "boarding") && LOCATION.boarding=="true")) bAdd = true;
	if(CheckAttribute(LOCATION, "fastreload") && LOCATION.fastreload=="ship") bAdd = true;
	if(CheckAttribute(LOCATION, "rats") && LOCATION.rats=="true")) bAdd = true;	//JRH
	if(bAdd && CheckAttribute(LOCATION, "models.always.l1"))
	{
		string LOCATIONName = LOCATION.models.always.l1;
		if(LOCATIONName=="CeresSmithy") LOCATIONName = "hold";
		if(LOCATIONName=="deck2") LOCATIONName = "deck1";
		if(LOCATIONName=="camp_deck" || LOCATIONName=="cap" || LOCATIONName=="tut_deck" || LOCATIONName=="cabin01" || LOCATIONName=="cabin02" || LOCATIONName=="cabin03" 
		|| LOCATIONName=="udeck" || LOCATIONName=="deckBig" || LOCATIONName=="deckLowVSBig" || LOCATIONName=="deckLowVSMedium" || LOCATIONName=="deckMediumVSBig"
		|| LOCATIONName=="ShipyardPirates") LOCATIONName = "capmd";
		if(LOCATIONName=="qdeck" || LOCATIONName=="deckLow" || LOCATIONName=="deckMedium" || LOCATIONName=="mh6") LOCATIONName = "capsm";

		switch(LOCATIONName)
		{
			case "hold": SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(8) + rand(8)); break;
			case "deck1": SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(4) + rand(4)); break;
			case "capmd": SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(2)); break;
			case "capsm": SendMessage(Location, "lsl", MSG_LOCATION_EX_MSG, "AddRats", rand(1)); break;
		}
	}

}

void CreateSeaAnimals()
{
	if (!IsEntity(Animals))
	{
		CreateEntity(&Animals, "Animals");
		LayerAddObject(SEA_EXECUTE, &Animals, 77);
		LayerAddObject(SEA_REALIZE, &Animals, 77);
	}

	Animals.midY = 0.0;

	SendMessage(Animals, "l", MSG_ANIMALS_BUTTERFLIES_HIDE);
	SendMessage(Animals, "l", MSG_ANIMALS_FISHSCHOOLS_SHOW);
	SendMessage(Animals, "l", MSG_ANIMALS_SEAGULLS_HIDE);

	if (!Whr_IsRain())
	{
		if (!Whr_IsNight())
		{
			if (!Whr_IsStorm())
			{
				SendMessage(Animals, "l", MSG_ANIMALS_SEAGULLS_SHOW);
				SendMessage(Animals, "lfff", MSG_ANIMALS_SEAGULLS_ADD, 0.0, 0.0, 0.0);
			}
		}
	}

}

void DeleteAnimals()
{
	if (IsEntity(Animals))
		DeleteClass(Animals);
}

