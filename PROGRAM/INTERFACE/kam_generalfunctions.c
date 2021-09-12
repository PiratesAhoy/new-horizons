string KAM_GetDefaultEmblemedSail(ref char)
{
	ref pchar = GetMainCharacter();
	int st = GetCharacterShipType(char);
	ref shref = GetShipByType(st);
	string tempstring;

// KK -->
	int selected_sails = DEFAULT_SAILS;
	if (selected_sails < 1) selected_sails--;

	// PB: Completely Rewritten -->

	// Default Sail Settings
	switch(selected_sails)
	{
		case 1: // Weathered, no emblems
			if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
				tempstring = "sail_weathered_plain.tga";
			else
				tempstring = "sail_weathered_common.tga";
		break;
		case 2: // Weathered, with emblems
			tempstring = "sail_weathered_nation" + char.nation + ".tga";
		break;
		case 3: // Pure White, no emblems
			if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
				tempstring = "sail_purewhite_plain.tga";
			else
				tempstring = "sail_purewhite_common.tga";
		break;
		case 4: // Pure White, with emblems
			tempstring = "sail_purewhite_nation" + char.nation + ".tga";
		break;
		// default, with emblems
			tempstring = "sail_whole_white_nation" + char.nation + ".tga";
	}

	// Additional Sail Settings
	switch(sti(char.nation))
	{
		case SPAIN:
			switch(selected_sails)
			{
				case 1: // Weathered, no emblems (historically accurate!)
					if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
						tempstring = "sail_weathered_nation" + char.nation + ".tga";
				break;
				case 3: // Pure White, no emblems (historically accurate!)
					if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
						tempstring = "sail_purewhite_nation" + char.nation + ".tga";
				break;
			}
		break;
		case PIRATE:
			switch(PIRATES_BLACK_SAILS)
			{
				case 1: // Plain Black
					tempstring = "sail_whole_black_plain.tga";
				break;
				case 2: // Emblemed Black
					if(IsCompanion(char))
					{
						if(!CheckAttribute(pchar,"piratesail")) pchar.piratesail = makeint(rand(QTY_LOGOSAILS_WHOLE_BLACK));
						char.piratesail = pchar.piratesail;
					}
					else
					{
						if(!CheckAttribute(char,"piratesail")) { char.piratesail = makeint(rand(QTY_LOGOSAILS_WHOLE_BLACK)); }
					}
					tempstring = "sail_whole_black_pirate" + sti(char.piratesail) + ".tga";
				break;
			}
		break;
		case PORTUGAL:
			switch(selected_sails)
			{
				case 1: // Weathered, no emblems (historically accurate!)
					if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
						tempstring = "sail_weathered_nation" + char.nation + ".tga";
				break;
				case 3: // Pure White, no emblems (historically accurate!)
					if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
						tempstring = "sail_purewhite_nation" + char.nation + ".tga";
				break;
			}
		break;
		case PERSONAL_NATION:
			switch(selected_sails)
			{
				case 1: // Weathered, no emblems - This case needed to prevent the default from showing on other settings
				break;
				case 2: // Weathered, with emblems
					tempstring = "sail_weathered_nation10.tga";
				break;
				case 3: // Pure White, no emblems - This case needed to prevent the default from showing on other settings
				break;
				case 4: // Pure White, with emblems
					tempstring = "sail_purewhite_nation10.tga";
				break;
				// default, with emblems
					tempstring = "sail_whole_white_nation10.tga";
			}
		break;
	}

	// PB: Completely Rewritten <--

	if (CheckAttribute(shref, "EmblemedSails.nationFileName")) {
		tempstring = shref.EmblemedSails.nationFileName;		// so if the ship has an emblemed sails type defined in ships_init.c, that takes precedence
	}
	if (!IsMainCharacter(char) && !IsCompanion(char) && CheckAttribute(char, "Ship.EmblemedSails.nationFileName")) {
		tempstring = char.Ship.EmblemedSails.nationFileName;
	}

	if (FindFile(GetResourceDirectory() + "Textures\ships\sails", "*.tga.tx", tempstring + ".tx") == "") return KAM_GetDefaultNormalSail(char); // KK
// <-- KK

	return tempstring;
}

string KAM_GetDefaultNormalSail(ref char)
{
	int st = GetCharacterShipType(char);
	ref shref = GetShipByType(st);
	string tempstring;

// KK -->
	ref pchar = GetMainCharacter();
	int selected_sails = DEFAULT_SAILS;
	if (selected_sails < 1) selected_sails--;

	// PB: Completely Rewritten -->

	switch(selected_sails)
	{
		case 1: // Weathered, no emblems
			tempstring = "sail_weathered_plain.tga";
		break;
		case 2: // Weathered, with emblems
			tempstring = "sail_weathered_plain.tga";
		break;
		case 3: // Pure White, no emblems
			tempstring = "sail_purewhite_plain.tga";
		break;
		case 4: // Pure White, with emblems
			tempstring = "sail_purewhite_plain.tga";
		break;
		// default, with emblems
			tempstring = "sail_whole_white_plain.tga";
	}

	// Additional Sail Settings
	switch(sti(char.nation))
	{
		case PIRATE:
			switch(PIRATES_BLACK_SAILS)
			{
				case 1: // Plain Black
					tempstring = "sail_whole_black_plain.tga";
				break;
				case 2: // Emblemed Black
					tempstring = "sail_whole_black_plain.tga";
				break;
			}
		break;
	}

	// PB: Completely Rewritten <--

	if (CheckAttribute(shref, "EmblemedSails.normalTex")) {
		tempstring = shref.EmblemedSails.normalTex;		// so if the ship has a normal sails type defined in ships_init.c (e.g. xebec br), that takes precedence
	}
	if (!IsMainCharacter(char) && !IsCompanion(char) && CheckAttribute(char, "Ship.EmblemedSails.normalTex")) {
		tempstring = char.Ship.EmblemedSails.normalTex;
	}
// <-- KK

	return tempstring;
}

