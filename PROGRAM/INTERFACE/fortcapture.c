#define UNKNOWN_FORT_NAME	"UnknownFortName"

ref glob_captref;

void InitInterface_R(string iniName,ref captref)
{
	glob_captref = captref;
	ref mchref = GetMainCharacter();
	mchref.from_interface.fortCharacterIdx = captref.index;

	if(bAnimation) iniName = "RESOURCE\INI\NEW_INTERFACES\ANIMATION\fortcapture.ini";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"Exp","",FONT_NORMAL,COLOR_NORMAL,20,180,SCRIPT_ALIGN_LEFT,1.2);
    CreateString(true,"Booty","",FONT_NORMAL,COLOR_NORMAL,20,260,SCRIPT_ALIGN_LEFT,1.2);
	SetNodeUsing("VIDEOPIE",bAnimation);

	CalculateData(captref);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetSquadronCrewQuantityRatio(mchref, stf(mchref.ship.crew.quantity) / stf(mchref.befboardcrew)); // 04-09-22 so entire sqdrn's crew used on board fort, and now reset based on ratio.
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	interfaceResultCommand = RC_INTERFACE_FORTCAPTURE_EXIT;
    EndCancelInterface(true);
}

void CalculateData(ref chref)
{
	int nationType = sti(chref.nation);
	int nBooty = 25000;
	int nExp = 25000;
	string sColonyName = GetColonyNameFromCh(chref);
	// NK -->
	string TownName = sColonyName;
	ref ctown = GetTownFromID(TownName);
	int townsize = GetTownSize(TownName);
	int troops = GetTownNumTroops(TownName);
	if (!CheckAttribute(chref, "skipRM"))
	{
		UpdateRMRelation(GetMainCharacter(), nationType, makefloat(townsize+troops)/100.0);
	}
	nBooty = makeint(makefloat(GetTownGold(TownName)) * TOWN_GOLD_SACK_SCALAR * (0.75 + frand(0.25) + makefloat(GetShipSkill(GetMainCharacter(), SKILL_SNEAK)/20.0)));
	SetTownGold(TownName, GetTownGold(TownName) - nBooty);
	nExp = troops * 50;
	SetTownNumTroops(TownName, makeint(makefloat(troops) * SACK_TROOPS_DECREASE * (0.75 + frand(0.5))));
	// NK <--

	string	sGoodsName[8];
	int		nGoodsQnt[8];
	int nUsedGoods = FillGoodsFromIslands(GetIslandNameFromColony(chref.location),&sGoodsName,&nGoodsQnt);

	GameInterface.strings.Exp = XI_ConvertString("Experience Bonus") + ": " + nExp;
	GameInterface.strings.Booty = XI_ConvertString("Booty")+": "+ nBooty;
	string tmpStr = GameInterface.strings.Booty;
	int sw = GetStringWidth(tmpStr,FONT_NORMAL,1.2);
	if(sw>0)	CreateImage("money","icons","commerce skill icon", 32+sw, 260, 64+sw, 292);
	CreateImage("Blazonry", "NATIONS", GetFlagPicName(nationType), 70, 70, 148, 148); // KK
	CreateString(true,"ColonyName",XI_ConvertString("fort_" + sColonyName) + " (pop. " + townsize + ")",FONT_NORMAL,COLOR_NORMAL,160,95,SCRIPT_ALIGN_LEFT,1.2); // NK // KK

	if(bNewIcons==true)
	{
	if(nUsedGoods>0)
	{
		CreateImage( "goods1","GOODS_NEW",sGoodsName[0],34,296,98,360);
		CreateString(true,"goods1",nGoodsQnt[0]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>1)
	{
		CreateImage( "goods2","GOODS_NEW",sGoodsName[1],98,296,162,360);
		CreateString(true,"goods2",nGoodsQnt[1]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>2)
	{
		CreateImage( "goods3","GOODS_NEW",sGoodsName[2],162,296,226,360);
		CreateString(true,"goods3",nGoodsQnt[2]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>3)
	{
		CreateImage( "goods4","GOODS_NEW",sGoodsName[3],226,296,290,360);
		CreateString(true,"goods4",nGoodsQnt[3]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>4)
	{
		CreateImage( "goods5","GOODS_NEW",sGoodsName[4],34,378,98,442);
		CreateString(true,"goods5",nGoodsQnt[4]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>5)
	{
		CreateImage( "goods6","GOODS_NEW",sGoodsName[5],98,378,162,442);
		CreateString(true,"goods6",nGoodsQnt[5]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>6)
	{
		CreateImage( "goods7","GOODS_NEW",sGoodsName[6],162,378,226,442);
		CreateString(true,"goods7",nGoodsQnt[6]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>7)
	{
		CreateImage( "goods8","GOODS_NEW",sGoodsName[7],226,378,290,442);
		CreateString(true,"goods8",nGoodsQnt[7]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	}
	else
	{
	if(nUsedGoods>0)
	{
		CreateImage( "goods1","GOODS",sGoodsName[0],34,296,98,360);
		CreateString(true,"goods1",nGoodsQnt[0]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>1)
	{
		CreateImage( "goods2","GOODS",sGoodsName[1],98,296,162,360);
		CreateString(true,"goods2",nGoodsQnt[1]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>2)
	{
		CreateImage( "goods3","GOODS",sGoodsName[2],162,296,226,360);
		CreateString(true,"goods3",nGoodsQnt[2]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>3)
	{
		CreateImage( "goods4","GOODS",sGoodsName[3],226,296,290,360);
		CreateString(true,"goods4",nGoodsQnt[3]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>4)
	{
		CreateImage( "goods5","GOODS",sGoodsName[4],34,378,98,442);
		CreateString(true,"goods5",nGoodsQnt[4]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>5)
	{
		CreateImage( "goods6","GOODS",sGoodsName[5],98,378,162,442);
		CreateString(true,"goods6",nGoodsQnt[5]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>6)
	{
		CreateImage( "goods7","GOODS",sGoodsName[6],162,378,226,442);
		CreateString(true,"goods7",nGoodsQnt[6]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>7)
	{
		CreateImage( "goods8","GOODS",sGoodsName[7],226,378,290,442);
		CreateString(true,"goods8",nGoodsQnt[7]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	}

	if(AUTO_SKILL_SYSTEM)
	{
		AddCharacterExpChar(GetMainCharacter(), "Cannons", makeint(nExp/2));
		AddCharacterExpChar(GetMainCharacter(), "Grappling", makeint(nExp/2));
	}
	else { AddCharacterExp(GetMainCharacter(), nExp); }
	AddMoneyToCharacter(GetMainCharacter(),nBooty);
	i_RepairAllShips();
	SetTownSize(TownName, townsize * SACK_TOWN_DECREASE); // NK
}

string GetIslandNameFromColony(string colonyName)
{
	string islName = colonyName;
	if (CheckAttribute(Locations[FindLocation(colonyName)], "island")) islName = Locations[FindLocation(colonyName)].island; // KK // TIH typo fix Nov1'06
	if (islName == "Greenford") islName = "Oxbay";
	return islName;
}

int FillGoodsFromIslands(string islName,ref sGoodsName,ref nGoodsQuantity)
{
	int idxIsl = FindIsland(islName);
	if(idxIsl==-1) return 0;
	ref islRef = GetIslandByIndex(idxIsl);

	aref tmpRef;
	int i,nGoodsType,nAddGoods;
	int retVal=0;
	ref refGoods;

	int nFreeTypes = GOODS_QUANTITY;
	int tmpGoodsTypes[GOODS_QUANTITY]; // NK
	for(i=0; i<GOODS_QUANTITY; i++)	{tmpGoodsTypes[i] = 0;}
	tmpGoodsTypes[GOOD_BALLS] = -1;
	tmpGoodsTypes[GOOD_GRAPES] = -1;
	tmpGoodsTypes[GOOD_KNIPPELS] = -1;
	tmpGoodsTypes[GOOD_BOMBS] = -1;
	tmpGoodsTypes[GOOD_GUNPOWDER] = -1;
	nFreeTypes = nFreeTypes-5; // added by MAXIMUS [gunpowder mod]

	if( CheckAttribute(islRef,"Trade.Export") )
	{
		makearef(tmpRef,islRef.Trade.Export);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = 1;
		}
	}
	if( CheckAttribute(islRef,"Trade.Import") )
	{
		makearef(tmpRef,islRef.Trade.Import);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		}
	}
	if( CheckAttribute(islRef,"Trade.Contraband") )
	{
		makearef(tmpRef,islRef.Trade.Contraband);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		}
	}

	while(retVal<8)
	{
		if(nFreeTypes<=0) break;
		nGoodsType = Rand(GOODS_QUANTITY-1);
		while(tmpGoodsTypes[nGoodsType]<0)
		{
			nGoodsType++;
			if(nGoodsType>=GOODS_QUANTITY) nGoodsType = nGoodsType-GOODS_QUANTITY;
		}
		refGoods = GetGoodByType(nGoodsType);
		if(tmpGoodsTypes[nGoodsType]==1)	nAddGoods = (10+Rand(25))*sti(refGoods.Units);
		else	nAddGoods = (1+Rand(12))*sti(refGoods.Units);
		sGoodsName[retVal] = refGoods.Name;
		nGoodsQuantity[retVal] = nAddGoods;
		AddCharacterGoods(GetMainCharacter(),nGoodsType,nAddGoods);
		tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		retVal++;
	}

	return retVal;
}

string GetColonyNameFromCh(ref chref)
{
// KK -->
	/*aref fortReload = FindIslandReloadLocator(chref.location,chref.location.locator);
	if(CheckAttribute(fortReload,"FortName")) return fortReload.FortName;*/
	if (CheckAttribute(chref, "town")) return chref.town;
// <-- KK
	return UNKNOWN_FORT_NAME;
}

void i_RepairAllShips()
{
	ref chref;
	ref mchref = GetMainCharacter();

	int i,cn;

	for(i=0; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			chref.ship.hp = GetCharacterShipHP(chref);
			chref.ship.sp = GetCharacterShipSP(chref);
// added by MAXIMUS [full ship's repairing] -->
			chref.Ship.crew.quantity = GetMaxCrewQuantity(chref);
			SetCannonArcQty(chref, 0, GetCannonArcMaxQty(chref, 0));
			SetCannonArcQty(chref, 1, GetCannonArcMaxQty(chref, 1));
			SetCannonArcQty(chref, 2, GetCannonArcMaxQty(chref, 2));
			SetCannonArcQty(chref, 3, GetCannonArcMaxQty(chref, 3));
// added by MAXIMUS [full ship's repairing] <--
			DeleteAttribute(chref,"ship.sails");
			DeleteAttribute(chref,"ship.masts");
		}
	}
}
