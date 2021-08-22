void relations_init()
{
	int iNation1, iNation2, n, nnum, irel;
	string sNation1, sNation2;
	ref PChar = GetMainCharacter();
	ref rPeriod;
	aref arRelations, arNation1, arNation2;

	makeref(rPeriod, Periods[GetCurrentPeriod()]);

	trace("running qcase beg");

	// Set Nation Relations
	if (CheckAttribute(rPeriod, "Relations")) {
		makearef(arRelations, rPeriod.Relations);
		for (iNation1 = 0; iNation1 < NATIONS_QUANTITY; iNation1++)
		{
			SetNationRelationBoth(iNation1, iNation1, RELATION_FRIEND);							// PB: Set all nations friendly to themselves
			if (iNation1 != PIRATE) SetNationRelationBoth(iNation1, PIRATE, RELATION_ENEMY);	// PB: Set the pirates hostile to everyone, but themselves
			sNation1 = GetNationIDByType(iNation1);
			if (!CheckAttribute(arRelations, sNation1)) continue;
			makearef(arNation1, arRelations.(sNation1));
			nnum = GetAttributesNum(arNation1);
			for (n = 0; n < nnum; n++)
			{
				arNation2 = GetAttributeN(arNation1, n);
				sNation2 = GetAttributeName(arNation2);
				iNation2 = GetNationTypeByID(sNation2);
				irel = sti(GetAttributeValue(arNation2));
				SetNationRelationBoth(iNation1, iNation2, irel);
			}
		}
	}
}
