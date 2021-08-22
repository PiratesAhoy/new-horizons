ref procGetSailTextureData()
{
	int st,i,sq;
	ref shref, char;
	aref arEmbl,arSail;
	string attrName;

	int chrIdx = GetEventData();
	if (chrIdx < 0) return &NullCharacter; // KK
	char = GetCharacter(chrIdx);
	ref PChar = GetMainCharacter();

	st = GetCharacterShipType(char);
	shref = GetShipByType(st);

	DeleteAttribute(&BI_objRetValue,"");
	BI_objRetValue.normalTex = "ships\sails\sail_whole_white_plain.tga"; // KK

	string nationFileName = "ships\sails\sail_whole_white_plain.tga"; // KK
	string tmpStr;

	if(chrIdx>=0)
	{
		// PB: Rewritten for Cursed Coins -->
		int UseSails = 0;
		if(IsCompanion(char))
		{
			if(CheckAttribute(PChar, "EmblemedSails"))																UseSails = 1;	// Player Emblemed Sails
			if(CheckAttribute(shref, "EmblemedSails") && !HasSubStr(shref.EmblemedSails.normalTex, "petros"))		UseSails = 0;	// Ship Emblemed Sails
		}
		if(IsMainCharacter(char))
		{
			if(CheckAttribute(char, "EmblemedSails"))																UseSails = 1;	// Player Emblemed Sails
		}
		if(CheckCharacterItem(char,"cursedcoin") && GetCursedCoinCount()>0)
		{
			if(sti(GetAttribute(char, "curseddays")) > 20)															UseSails = 2;	// If cursed, override above
		}

		switch(UseSails)
		{
			case 0: // Use Default Sails (ship-dependent)
				BI_objRetValue.normalTex	= "Ships\Sails\" + KAM_GetDefaultNormalSail(char);
				nationFileName				= "Ships\Sails\" + KAM_GetDefaultEmblemedSail(char);
			break;
			case 1: // Use Player Emblemed Sails
				BI_objRetValue.normalTex	= PChar.EmblemedSails.normalTex;
				nationFileName				= PChar.EmblemedSails.nationFileName;
			break;
			case 2: // Use Own Cursed Sails
				BI_objRetValue.normalTex	= "Ships\Sails\" + GetCharacterCursedSails(char);
				nationFileName				= "Ships\Sails\" + GetCharacterCursedSails(char);
			break;
		}
		// PB: Rewritten for Cursed Coins <--

		if(st!=SHIP_NOTUSED)
		{
			makearef(arEmbl,shref.GeraldSails);						// actually sets the texture of each individual sail -->
			sq = GetAttributesNum(arEmbl);
			for(i=0; i<sq; i++)
			{
				arSail = GetAttributeN(arEmbl,i);
				attrName = GetAttributeName(arSail);
				tmpStr = GetAttributeValue(arSail);
				if(tmpStr=="1")	{BI_objRetValue.(attrName) = nationFileName;}
				else	{BI_objRetValue.(attrName) = tmpStr;}				// <--
			}
		}
	}

	return &BI_objRetValue;
}
