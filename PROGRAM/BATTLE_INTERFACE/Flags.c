#define FLAG_ENSIGN    "E"
#define FLAG_PENNANT   "P"
#define FLAG_NONE      "N"

#define SHIP_FLAG      -2
#define SHIP_PENNANT   -3

int CurrentShip = 0;
int CurrentFlag = 0;
int ShipFlagsQuantity = -1;
bool bShipWithoutPennants = false;


int gRiggingRetVal[2];
#event_handler("GetRiggingData", "procGetRiggingData");
ref procGetRiggingData()
{
	gRiggingRetVal[0] = 0;
	gRiggingRetVal[1] = 0;
	int n = 0;
	bool pirateOverride = false; // PB: For Pirate Flags on Forts and Ashore

	string datName = GetEventData();
	bool isTriangle = GetEventData() > 0;
	int nation = GetEventData();
	bool isSpecialFlag = GetEventData() > 0;
	aref rCharacter = GetMainCharacter();

	if (isSpecialFlag) {
		gRiggingRetVal[1] = 1;
	}

	if (datName == "GetShipFlagTexNum") {
		rCharacter = GetEventData();
	}

	if (datName == "GetTownFlagTexNum") {
		pirateOverride = true;
	}

	switch (nation)
	{
		case HOLLAND:          gRiggingRetVal[0] = 0;                                break;
		case ENGLAND:          gRiggingRetVal[0] = 1;                                break;
		case FRANCE:           gRiggingRetVal[0] = 2;                                break;
		case PORTUGAL:         gRiggingRetVal[0] = 3;                                break;
		case SPAIN:            gRiggingRetVal[0] = 4;                                break;
		case PIRATE:
		    if(pirateOverride) gRiggingRetVal[0] = 6; // PB: For Pirate Flags on Forts and Ashore
		    else               gRiggingRetVal[0] = GetPirateFlag(rCharacter, &n);    break;
		case GUEST1_NATION:    gRiggingRetVal[0] = 5;                                break;
		case GUEST2_NATION:    gRiggingRetVal[0] = 7;                                break; //JRH 7, was 6
		case PRIVATEER_NATION: gRiggingRetVal[0] = GetPersonalFlag(rCharacter, &n);  break;
		case UNKNOWN_NATION:   gRiggingRetVal[0] = FLAGS_NULL_PICTURE_TEXTURE_INDEX; break; //added by KAM		// changed after build 11 by KAM
		case NEUTRAL_NATION:   gRiggingRetVal[0] = 6; break; //added by KAM
		case PERSONAL_NATION:  gRiggingRetVal[0] = GetPersonalFlag(rCharacter, &n);  break;
	}

	return &gRiggingRetVal;
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
				SendMessage(&PirateFlag[i], "lil", MSG_FLAG_INIT, &rModel, iNation);
			}
			else SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &rModel, iNation);
		break;
	
/*		case PRIVATEER_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &rModel, iNation);
		break;*/
		case PERSONAL_NATION:
			GetPersonalFlag(chr, &i);
			SendMessage(&PersonalFlag[i], "lil", MSG_FLAG_INIT, &rModel, iNation);
		break;
		// default:
			SendMessage(&FortFlag, "lil", MSG_FLAG_INIT, &rModel, iNation);
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
			ntex = rand(PIRATEFLAGS_TEXTURES_QUANTITY - 3); //PW: -3 to disable last 2 rows in random encounters
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

ref GetCharacterFlagEntity(ref character) {
	int nation = sti(character.nation);
	int index = 0;

	bool found = false;
	ref result;

	switch(nation) {
		case PIRATE:
			GetPirateFlag(character, &index);
			index = sti(index);
			if (index < PIRATEFLAGS_TEXTURES_QUANTITY) {
				result = &PirateFlag[sti(index)];
				found = true;
			}
		break;
		case PERSONAL_NATION:
			GetPersonalFlag(character, &index);
			index = sti(index);
			if (index < PERSONALFLAGS_TEXTURES_QUANTITY) {
				result = &PersonalFlag[sti(index)];
				found = true;
			}
		break;
		case NEUTRAL_NATION:
			result = &Flag;
			found = true;
		break;
		if (IsShipMerchant(character) ) {
			result = &MerchantFlag;
			found = true;
		}
	}

	if (found && IsEntity(result) ) {
		return result;
	}
	return &Flag;
}
