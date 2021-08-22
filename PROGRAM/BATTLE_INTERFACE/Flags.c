#define FLAG_ENSIGN    "E"
#define FLAG_PENNANT   "P"
#define FLAG_NONE      "N"

#define SHIP_FLAG      -2
#define SHIP_PENNANT   -3

int CurrentShip = 0;
int CurrentFlag = 0;
int ShipFlagsQuantity = -1;
bool bShipWithoutPennants = false;

#event_handler("GetRiggingData", "procGetRiggingData");
ref procGetRiggingData()
{
	int n;
	int retVal = 0;
	int locidx = FindLoadedLocation();
	bool PirateOverride = false;															// PB: For Pirate Flags on Forts and Ashore
	ref chr;
	ref PChar = GetMainCharacter();

	string datName = GetEventData();
	if (datName == "GetFlagTexNum") {
		n = GetEventData();
		n = GetEventData();
		if (n == SHIP_FLAG || n == SHIP_PENNANT) {
			if (locidx < 0)
				chr = GetCharacter(Ships[CurrentShip]);
			else
				chr = GetCharacter(iShips[CurrentShip]);
			if (ShipFlagsQuantity == -1) {
				ShipFlagsQuantity = GetShipFlagsQuantity(chr);
				bShipWithoutPennants = ShipWithoutPennants(chr);
				if (!bShipWithoutPennants) ShipFlagsQuantity *= 2;
				CurrentFlag = 0;
			}
			int pos = CurrentFlag;
			if (n == SHIP_PENNANT) {
				pos -= (ShipFlagsQuantity / 2);
			}
			string FlagType = GetShipFlagType(chr, pos);
			if (bShipWithoutPennants) {
				if (n == SHIP_PENNANT) FlagType = FLAG_ENSIGN;
				if (FlagType == FLAG_PENNANT) {
					n = SHIP_FLAG;
					FlagType = FLAG_ENSIGN;
				}
			}
			CurrentFlag++;
			if (FlagType == FLAG_NONE) {
				retVal = FLAGS_NULL_PICTURE_TEXTURE_INDEX;
				return &retVal;
			}
			if (FlagType == FLAG_ENSIGN && n == SHIP_PENNANT) {
				retVal = FLAGS_NULL_PICTURE_TEXTURE_INDEX;
				return &retVal;
			}
			if (FlagType == FLAG_PENNANT && n == SHIP_FLAG && bShipWithoutPennants == false) {
				retVal = FLAGS_NULL_PICTURE_TEXTURE_INDEX;
				return &retVal;
			}
		} else {
			chr = GetCharacter(n);
			if(CheckAttribute(Pchar,"special_flag") && Pchar.special_flag == "on")
			{ PirateOverride = false; }	 //JRH
			else PirateOverride = true;															// PB: For Pirate Flags on Forts and Ashore
		}
		n = sti(chr.nation);
		switch (n)
		{
			case HOLLAND:          retVal = 0;                                break;
			case ENGLAND:          retVal = 1;                                break;
			case FRANCE:           retVal = 2;                                break;
			case PORTUGAL:         retVal = 3;                                break;
			case SPAIN:            retVal = 4;                                break;
			case PIRATE:
				if(PirateOverride) retVal = 6;												// PB: For Pirate Flags on Forts and Ashore
				else	       retVal = GetPirateFlag(chr, &n);           break;
			case GUEST1_NATION:    retVal = 5;                                break;
			case GUEST2_NATION:    retVal = 7;                                break;		//JRH 7, was 6
			case PRIVATEER_NATION: retVal = GetPersonalFlag(chr, &n);         break;
			case UNKNOWN_NATION:   retVal = FLAGS_NULL_PICTURE_TEXTURE_INDEX; break;		//added by KAM		// changed after build 11 by KAM
			case NEUTRAL_NATION:   retVal = FLAGS_NULL_PICTURE_TEXTURE_INDEX; break;		//added by KAM
			case PERSONAL_NATION:  retVal = GetPersonalFlag(chr, &n);         break;
		}
	}
	return &retVal;
}

int GetShipFlagsQuantity(ref chr)
{
	int iShipType = GetCharacterShipType(chr);
	if (iShipType < 0 || iShipType == SHIP_NOTUSED) return 0;
	ref rShip; makeref(rShip, ShipsTypes[iShipType]);
	aref arShip; makearef(arShip, chr.Ship);
	if (!CheckAttribute(rShip, "Flags")) return 0;
	int ret = 0;
	aref arFlags; makearef(arFlags, rShip.Flags);
	int nMasts = GetAttributesNum(arFlags);
	for (int m = 0; m < nMasts; m++)
	{
		aref arFlag = GetAttributeN(arFlags, m);
		string sMast = GetAttributeName(arFlag);
		if (GetLocalShipAttrib(arShip, rShip, "Ship.Masts." +sMast) == "1") continue;
		ret += GetAttributesNum(arFlag);
	}
	return ret;
}

string GetShipFlagType(ref chr, int pos)
{
	int iShipType = GetCharacterShipType(chr);
	if (iShipType < 0 || iShipType == SHIP_NOTUSED) return FLAG_ENSIGN;
	aref arShip; makearef(arShip, chr.Ship);
	ref rShip; makeref(rShip, ShipsTypes[iShipType]);
	if (!CheckShipAttribute(arShip, rShip, "Flags")) return FLAG_ENSIGN;
	int n = 0;
	aref arMasts; makearef(arMasts, rShip.Flags);
	int nMasts = GetAttributesNum(arMasts);
	int m = 0;
	int i = 1;
	if (CheckAttribute(chr, "surrendered")) return FLAG_NONE; // Screwface: to fix the white flags
	while (i <= nMasts)
	{
		string sMast = "Mast" + m;
		if (CheckAttribute(chr, "Ship.Masts." + sMast) == true && GetLocalShipAttrib(arShip, rShip, "Ship.Masts." + sMast) == "1") {
			m++;
			continue;
		}
		if (!CheckShipAttribute(arShip, rShip, "Flags." + sMast)) {
			m++;
			continue;
		}
		i++;
		aref arFlags; makearef(arFlags, rShip.Flags.(sMast));
		int nFlags = GetAttributesNum(arFlags);
		for (int f = 1; f <= nFlags; f++)
		{
			string sFlag = "Flag" + f;
			if (!CheckShipAttribute(arShip, rShip, "Flags." + sMast + "." + sFlag)) continue;
			if (n == pos) return GetLocalShipAttrib(arShip, rShip, "Flags." + sMast + "." + sFlag);
			n++;
			m++;
		}
	}
	return FLAG_ENSIGN;
}

bool ShipWithoutPennants(ref chr)
{
	aref arShip; makearef(arShip, chr.Ship);
	ref rShip = GetShipByType(GetCharacterShipType(chr));
	if (CheckShipAttribute(arShip, rShip, "Flags.NoPennants")) return sti(GetLocalShipAttrib(arShip, rShip, "Flags.NoPennants"));
	return false;
}

void SetFortFlag(ref rModel)
{
	int i, idx, iNation;
	ref chr;
	ref Pchar = GetMaincharacter();
	if (!CheckAttribute(rModel, "fortcmdridx")) return;
	idx = sti(rModel.fortcmdridx);
	if (idx < 0) return;
	chr = GetCharacter(idx);
	SendMessage(&Flag, "li", MSG_FLAG_DEL_GROUP, &rModel);
	if (IsEntity(&MerchantFlag)) SendMessage(&MerchantFlag, "li", MSG_FLAG_DEL_GROUP, &rModel);
	for (i = 0; i < PIRATEFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PirateFlag[i])) SendMessage(&PirateFlag[i], "li", MSG_FLAG_DEL_GROUP, &rModel);
	}
	for (i = 0; i < PERSONALFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PersonalFlag[i])) SendMessage(&PersonalFlag[i], "li", MSG_FLAG_DEL_GROUP, &rModel);
	}
	SendMessage(&FortFlag, "li", MSG_FLAG_DEL_GROUP, &rModel);
	iNation = sti(chr.nation);
	switch (iNation) {

		//ok for red, ok for standard
		case PIRATE:
			//JRH:
			if(CheckAttribute(Pchar,"special_flag") && Pchar.special_flag == "on") 
			{
				GetPirateFlag(chr, &i);
				SendMessage(&PirateFlag[i], "lil", MSG_FLAG_INIT, &rModel, idx);
			}
			else SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &rModel, idx);
		break;
	
/*		case PRIVATEER_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &rModel, idx);
		break;*/
		case PERSONAL_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &rModel, idx);
		break;
		// default:
			SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &rModel, idx);
	}
}

void SetShipFlag(int chridx)
{
	if (chridx < 0) return;
	ref chr = GetCharacter(chridx);
	ref Pchar = GetMaincharacter();
	if (GetShipFlagsQuantity(chr) == 0 || CharacterIsDead(chr) == true || CheckAttribute(chr, "curshipnum") == false) return;
	int i = 0;
	int shippos = sti(chr.curshipnum);
	int ship_quantity = 0;
	if (FindLoadedLocation() >= 0)
		ship_quantity = locNumShips;
	else
		ship_quantity = iNumShips;
	int model_no = ShipModelrList[shippos];
	int next_model_no = -1;
	if (shippos < ship_quantity) {
		next_model_no = ShipModelrList[shippos + 1];
		if (next_model_no == -1) next_model_no = GetCurrentModelrNumber();
	}
	aref arModel;
	CurrentShip = shippos;
	ShipFlagsQuantity = -1;
	int iNation = sti(chr.nation);
	int j;
	if (FindClass(&arModel, "modelr")) {
		i++;
		while (FindClassNext(&arModel))
		{
			if (i >= model_no && i < next_model_no) {
				SendMessage(&Flag, "li", MSG_FLAG_DEL_GROUP, &arModel);
				if (IsEntity(&Pennant)) SendMessage(&Pennant, "li", MSG_FLAG_DEL_GROUP, &arModel);
				SendMessage(&MerchantFlag, "li", MSG_FLAG_DEL_GROUP, &arModel);
				if (IsEntity(&MerchantPennant)) SendMessage(&MerchantPennant, "li", MSG_FLAG_DEL_GROUP, &arModel);
				for (j = 0; j < PIRATEFLAGS_TEXTURES_QUANTITY; j++)
				{
					if (IsEntity(&PirateFlag[j])) SendMessage(&PirateFlag[j], "li", MSG_FLAG_DEL_GROUP, &arModel);
					if (IsEntity(&PiratePennant[j])) SendMessage(&PiratePennant[j], "li", MSG_FLAG_DEL_GROUP, &arModel);
				}
				for (j = 0; j < PERSONALFLAGS_TEXTURES_QUANTITY; j++)
				{
					if (IsEntity(&PersonalFlag[j])) SendMessage(&PersonalFlag[j], "li", MSG_FLAG_DEL_GROUP, &arModel);
					if (IsEntity(&PersonalPennant[j])) SendMessage(&PersonalPennant[j], "li", MSG_FLAG_DEL_GROUP, &arModel);
				}
				SendMessage(&FortFlag, "li", MSG_FLAG_DEL_GROUP, &arModel);
				switch (iNation) {
					case PIRATE:
						GetPirateFlag(chr, &j);
						SendMessage(&PirateFlag[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
						if (IsEntity(&PiratePennant[j])) SendMessage(&PiratePennant[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_PENNANT);
					break;
					case PRIVATEER_NATION:
						GetPersonalFlag(chr, &j);
						SendMessage(&PersonalFlag[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
						if (IsEntity(&PersonalPennant[j])) SendMessage(&PersonalPennant[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_PENNANT);
					break;
					case PERSONAL_NATION:
						GetPersonalFlag(chr, &j);
						SendMessage(&PersonalFlag[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
						if (IsEntity(&PersonalPennant[j])) SendMessage(&PersonalPennant[j], "lil", MSG_FLAG_INIT, &arModel, SHIP_PENNANT);
					break;
					case NEUTRAL_NATION:
						SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
					break;
					// default:
						if (IsEntity(&MerchantFlag) && IsShipMerchant(chr)) {
							SendMessage(&MerchantFlag, "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
							if (IsEntity(&MerchantPennant)) SendMessage(&MerchantPennant, "lil", MSG_FLAG_INIT, &arModel, SHIP_PENNANT);
						} else {
							SendMessage(&Flag, "lil", MSG_FLAG_INIT, &arModel, SHIP_FLAG);
							if (IsEntity(&Pennant)) SendMessage(&Pennant, "lil", MSG_FLAG_INIT, &arModel, SHIP_PENNANT);
						}
				}
			}
			if (next_model_no > -1 && i >= next_model_no) return;
			i++;
		}
	}
}

void SetTownFlag(ref loc, object mdl)
{
	int i, idx, iNation;
	string town;
	ref chr;
	ref Pchar = GetMaincharacter();
	if (!CheckAttribute(loc, "townsack")) return;
	SendMessage(&Flag, "li", MSG_FLAG_DEL_GROUP, &mdl);
	SendMessage(&MerchantFlag, "li", MSG_FLAG_DEL_GROUP, &mdl);
	for (i = 0; i < PIRATEFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PirateFlag[i])) SendMessage(&PirateFlag[i], "li", MSG_FLAG_DEL_GROUP, &mdl);
		if (IsEntity(&PiratePennant[i])) SendMessage(&PiratePennant[i], "li", MSG_FLAG_DEL_GROUP, &mdl);
	}
	for (i = 0; i < PERSONALFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PersonalFlag[i])) SendMessage(&PersonalFlag[i], "li", MSG_FLAG_DEL_GROUP, &mdl);
		if (IsEntity(&PersonalPennant[i])) SendMessage(&PersonalPennant[i], "li", MSG_FLAG_DEL_GROUP, &mdl);
	}
	SendMessage(&FortFlag, "li", MSG_FLAG_DEL_GROUP, &mdl);
	town = loc.townsack;
	iNation = GetTownNation(town);
	idx = GetTownGovernorIndex(town);
	if (idx < 0) idx = GetTownFortCommanderIndex(town, 0);
	if (idx < 0) idx = GetMainCharacterIndex();
	chr = GetCharacter(idx); // PB
	switch (iNation) {
		
		//ok for red, ok for standard
		case PIRATE:
			//JRH:
			if(CheckAttribute(Pchar,"special_flag") && Pchar.special_flag == "on") 
			{
				GetPirateFlag(chr, &i);
				SendMessage(&PirateFlag[i], "lil", MSG_FLAG_INIT, &mdl, idx);
			}
			else SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &mdl, idx);
		break;
		
/*		case PRIVATEER_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &mdl, idx);
		break;*/
		case PERSONAL_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &mdl, idx);
		break;
		// default:
			SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &mdl, idx);
	}
}

void RefreshFlags()
{
	if (FindLoadedLocation() >= 0 && locNumShips > 0) {
		SetEventHandler("frame", "BLI_SetFlags", 1);
		return;
	}
	if (bSeaActive && !bAbordageStarted) {
		SetEventHandler("frame", "BI_SetFlags", 1);
		return;
	}
}

// Screwface
void FlagsDelay()
{
	if (FindLoadedLocation() >= 0 && locNumShips > 0) {
		SetEventHandler("frame", "BLI_FlagsDelay", 1);
		return;
	}
	if (bSeaActive && !bAbordageStarted) {
		SetEventHandler("frame", "BI_FlagsDelay", 1);
		return;
	}
}

int GetPirateFlag(ref chr, int ntex)
{
	ntex = 0;
	// Use character-specific flag if available
	if (CheckAttribute(chr, "Flags.Pirate.texture")) ntex = sti(chr.Flags.Pirate.texture);
	if (CheckAttribute(chr, "Flags.Pirate")) return sti(chr.Flags.Pirate);
	if (IsCompanion(chr))
	{
		ref PChar = GetMainCharacter();
		ntex = sti(PChar.Flags.Pirate.texture);
		return sti(PChar.Flags.Pirate);
	}
	else
	{
		ref cmdr = Group_GetGroupCommander(GetGroupIDFromCharacter(chr));
		if (!CheckAttribute(cmdr, "Flags.Pirate") || !CheckAttribute(cmdr, "Flags.Pirate.texture")) {
			ntex = rand(PIRATEFLAGS_TEXTURES_QUANTITY - 2); //PW: -2 to disable last row in random encounters
			cmdr.Flags.Pirate.texture = ntex;
			cmdr.Flags.Pirate = rand(FLAGS_PICTURES_QUANTITY_PER_TEXTURE - 2); // PB: -2 to disable last column in random encounters
		}
		ntex = sti(cmdr.Flags.Pirate.texture);
		chr.Flags.Pirate.texture = ntex;
		chr.Flags.Pirate = sti(cmdr.Flags.Pirate);
		return sti(cmdr.Flags.Pirate);
	}
}

int GetPersonalFlag(ref chr, int ntex)
{
	// PB -->
	// Use character-specific flag if available
	if (CheckAttribute(chr, "Flags.Personal.texture")) ntex = sti(chr.Flags.Personal.texture);
	if (CheckAttribute(chr, "Flags.Personal")) return sti(chr.Flags.Personal);

	// Otherwise use the player's own flag
	ref PChar = GetMainCharacter();
	ntex = sti(PChar.Flags.Personal.texture);
	return sti(PChar.Flags.Personal);
	// PB <--
/*	ntex = 0;
	if(IsCompanion(chr))
	{
		ref PChar = GetMainCharacter();
		ntex = sti(PChar.Flags.Personal.texture);
		return sti(PChar.Flags.Personal);
	}
	else
	{
		if (CheckAttribute(chr, "Flags.Personal.texture")) ntex = sti(chr.Flags.Personal.texture);
		if (CheckAttribute(chr, "Flags.Personal")) return sti(chr.Flags.Personal);
		ref cmdr = Group_GetGroupCommander(GetGroupIDFromCharacter(chr));
		if (!CheckAttribute(cmdr, "Flags.Personal"))
		{
			ntex = rand(PERSONALFLAGS_TEXTURES_QUANTITY - 1);
			cmdr.Flags.Personal.texture = ntex;
			cmdr.Flags.Personal = rand(FLAGS_PICTURES_QUANTITY_PER_TEXTURE - 1);
			chr.Flags.Personal.texture = ntex;
			chr.Flags.Personal = sti(cmdr.Flags.Personal);
			return sti(chr.Flags.Personal);
		}
		ntex = sti(cmdr.Flags.Personal.texture);
		return sti(cmdr.Flags.Personal);
	}*/
}
