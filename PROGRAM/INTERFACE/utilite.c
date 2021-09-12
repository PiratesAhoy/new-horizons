

native string LanguageGetLanguage();
native int LanguageOpenFile(string sFileName);
native void LanguageCloseFile(int idLngFile);
native string LanguageConvertString(int userLngFileID, string inStr);
native void LanguageSetLanguage(string sLanguageName);
native string XI_ConvertString(string inStr);
native int GlobalLngFileID();
native string LanguageGetFaderPic(string faderPicName);
native string DialogAssembleStr(string idStr, string paramStr);
native string DialogAddParamToStr(string oldParamStr, string paramID, string paramValue);

native void XI_SetColorCorrection(float fContrast, float fGamma, float fBrightness);
native void XI_SetMouseSensitivity( float fMouseXSens, float fMouseYSens );
native void XI_ControlMakeInvert(string sControlName, int bInvertState);

native void XI_MakeNode(string sIniFileName, string sNodeType, string sNodeName, int nPriority);
native void XI_DeleteNode(string sNodeName);
native bool XI_IsWindowEnable(string sWindowName);
native void XI_WindowShow(string sWindowName, int bShowStatus);
native void XI_WindowDisable(string sWindowName, int bDisableStatus);
native void XI_WindowAddNode(string sWindowName, string sNodeName);
native int XI_StoreNodeLocksWithOff();
native void XI_RestoreNodeLocks(int nStoreCode);
native bool XI_IsKeyPressed(string key_name); // key_name = {"shift","control","alt"}
native void XI_RegistryExitKey(string key_name);

#library "script_interface_functions"

// KK -->
#define TOOLTIP_FADER                   "Fader"
#define TOOLTIP_RECTANGLE               "Rectangle"
#define TOOLTIP_HEADER                  "Header"
#define TOOLTIP_TEXT                    "Text"
#define TOOLTIP_PICTURE                 "Picture"

#define CHECKBOXTYPE_TWOSELECT         2
#define CHECKBOXTYPE_THREESELECT       3

#define CHECKBOX_OFF                   0
#define CHECKBOX_SET                   1
#define CHECKBOX_UNSET                 2

#define TAB_HIDE                      -1
#define TAB_INACTIVE                   0
#define TAB_ACTIVE                     1
// <-- KK

void CreateImage(string AttrName,string imgListName,string imgName,int left,int top,int right,int bottom)
{
	GameInterface.pictures.(AttrName).tex = imgListName;
    GameInterface.pictures.(AttrName).pic = imgName;
    SendMessage(&GameInterface,"lslllll",MSG_INTERFACE_PLACE_IMAGE,AttrName,true,left,top,right,bottom);
}

void CreateAbsoluteImage(string AttrName,string imgListName,string imgName,int left,int top,int right,int bottom)
{
	GameInterface.pictures.(AttrName).tex = imgListName;
    GameInterface.pictures.(AttrName).pic = imgName;
    SendMessage(&GameInterface,"lslllll",MSG_INTERFACE_PLACE_IMAGE,AttrName,false,left,top,right,bottom);
}

// KK -->
void RemovePicture(string sPictureName)
{
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_PICTURE,sPictureName);
}
// <-- KK

void SetPictureBlind(string picName,bool blindFlag,int minCol,int maxCol)
{
	SendMessage(&GameInterface,"lslll",MSG_INTERFACE_SET_BLIND,picName,blindFlag,minCol,maxCol);
}

void CreateString(int enable,string strName, string strData, string fontName, int color, int x, int y, int alignment, float scale)
{
    GameInterface.strings.(strName) = strData;
    SendMessage(&GameInterface,"lssllllf",MSG_INTERFACE_CREATE_STRING, strName, fontName, color, x,y,alignment,scale);
    if(enable==FALSE)
    {
        SendMessage(&GameInterface,"ls", MSG_INTERFACE_DISABLE_STRING, strName);
    }
}

void DisableString(string strName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_DISABLE_STRING, strName);
}

void EnableString(string strName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_ENABLE_STRING, strName);
}

// KK -->
void RemoveString(string strName)
{
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_DELETE_STRING, strName);
}
// <-- KK

void ChangeStringColor(string strName, int newCol)
{
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_CHANGE_STR_COLOR,strName,newCol);
}

void SetNodeUsing(string nodeName,int bUsing)
{
    SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SET_NODE_USING, nodeName, bUsing);
}

void SetCurrentNode(string nodeName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_NEW_CURRENT_NODE,nodeName);
}
string GetCurrentNode()
{
	string retVal;
	SendMessage(&GameInterface,"le", MSG_INTERFACE_GET_CURRENT_NODE,&retVal);
	return retVal;
}

void ShowHelpString(string helpString)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_SETHELPSTRING, helpString);
}

string MakeMoneyShow(int moneyQuantity,string msign,string deliver)
{
	string moneyStr;
	int i,j;
	moneyStr="";
	while(moneyQuantity>999)
	{
		i = moneyQuantity/1000;
		j = moneyQuantity-i*1000;
		if(j>99)
		{
			moneyStr = deliver + j + moneyStr;
		}
		else
		{
			if(j>9)
			{
				moneyStr = deliver+"0" + j + moneyStr;
			}
			else
			{
				moneyStr = deliver+"00" + j + moneyStr;
			}
		}
		moneyQuantity = i;
	}
	moneyStr = msign+moneyQuantity+moneyStr;
	return moneyStr;
}

// NK -->
string ShowMoney(int money)
{
	return MakeMoneyShow(money, MONEY_SIGN, MONEY_DELIVER);
}

// moved here from ship.c and updated for KNB. 05-04-10
string GetCannonName(int ct)
{
	if(ct==CANNON_TYPE_NONECANNON)	return XI_ConvertString("NoneCannons");
	ref cref = GetCannonByType(ct);
	string cname, retVal;
	// KNB -->
	if(USE_REAL_CANNONS)
	{
		switch(sti(cref.type))
		{
			case CANNON_NAME_CARRONADE: cname = XI_ConvertString("Carronade"); break;
			cname = XI_ConvertString("Long Gun");
		}
	}
	// KNB <--
	else
	{
		if(cref.type==CANNON_NAME_CULVERINE)	cname = XI_ConvertString("Culverine");
		else	cname = XI_ConvertString("Cannon");
	}
	retVal = XI_ConvertString("caliber"+cref.caliber) + " " + cname;
	return retVal;
}

// NK <--
//MAXIMUS -->
void ChangePicture(string nodeName, string pictureFileName, int bUsing)
{
	if(bUsing) { SetNewPicture(nodeName, pictureFileName); }
}
//MAXIMUS <--
void SetNewPicture(string _NodeName,string _NewPictureFileName)
{
	SendMessage(&GameInterface,"lslls", MSG_INTERFACE_MSG_TO_NODE,_NodeName,2, false, _NewPictureFileName);
}

void SetNewVideoPicture(string _NodeName,string _NewVideoPicFileName)
{
	SendMessage(&GameInterface,"lslls", MSG_INTERFACE_MSG_TO_NODE,_NodeName,2, true, _NewVideoPicFileName);
}

void SetSelectable(string _NodeName,int _Selectable)
{
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SET_SELECTABLE, _NodeName, _Selectable);
	if(_NodeName=="EXIT_BUTTON")//MAXIMUS: for standard exit-button -->
	{
		if(_Selectable)
			ChangeStringColor("EXIT", COLOR_NORMAL);
		else
			ChangeStringColor("EXIT", COLOR_DESELECT);
	}//MAXIMUS <--
}
int GetSelectable(string _NodeName)
{
	return SendMessage(&GameInterface,"ls", MSG_INTERFACE_GET_SELECTABLE, _NodeName);
}

void SetClickable(string _NodeName, bool ClickStatus)
{
	SendMessage(&GameInterface,"lslll", MSG_INTERFACE_MSG_TO_NODE,_NodeName,-1,1, ClickStatus);
}
bool GetClickable(string _NodeName)
{
	return SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,_NodeName,-1,2);
}

void DelFromScroll(string nodeName,int pnum)
{
	int qn = sti(GameInterface.(nodeName).ListSize)-1;
	aref inar,outar;
	string attrName;
	for(int i=pnum; i<qn; i++)
	{
		attrName = "pic"+(i+1);
		makearef(inar,GameInterface.(nodeName).(attrName));
		attrName = "pic"+(i+2);
		makearef(outar,GameInterface.(nodeName).(attrName));
		CopyAttributes(inar,outar);
	}
	attrName = "pic"+(i+1);
	DeleteAttribute(&GameInterface,nodeName+"."+attrName);
	if(qn>=0) GameInterface.(nodeName).ListSize = qn;
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_DEL_SCROLLIMAGE, nodeName, pnum);
}

void AddToScroll(string nodeName,int pnum)
{
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_ADD_SCROLLIMAGE, nodeName, pnum);
}

// KK -->
/*void XI_SetQuestTitles(string nodName,aref questInfo,int topNum)
{
	SendMessage(&GameInterface,"lsal",MSG_INTERFACE_SET_TITLE_STRINGS,nodName,questInfo,topNum);
}*/
// <-- KK

// PS -->
string GetShipString(int stype)
{
	if(stype < 0) return "";
	if(stype >= SHIP_TYPES_QUANTITY_WITH_FORT) return ""; //also checks for st == SHIP_NOTUSED
	return ShipsTypes[stype].SName;
}

string GetShipPicName(int stype)
{
	if(stype == SHIP_NOTUSED) return SHIP_NOTUSED_TYPE_NAME;
	return ShipsTypes[stype].BigPic;
}

int GetShipTexture(int stype)
{
	if(stype < 0) return -1;
	if(stype >= SHIP_TYPES_QUANTITY_WITH_FORT) return -1; //also checks for st == SHIP_NOTUSED
	/*if(shipType=="Galeoth1") return 1;
	if(shipType=="Galeoth2") return 1;
	return 0;*/
	return sti(ShipsTypes[stype].BigPicTex);
}

string GetShipTextureName(int stype)
{
	if(stype < 0) return "";
	if(stype >= SHIP_TYPES_QUANTITY_WITH_FORT) return ""; //also checks for st == SHIP_NOTUSED
	/*if(shipType=="Galeoth1") return "SHIPS1";
	if(shipType=="Galeoth2") return "SHIPS1";
	return "SHIPS16";*/
	return ShipsTypes[stype].BigPicTexName;
}
// PS <--

string GetFaceGroupName(int charIdx)
{
	if(charIdx<0) {return "EMPTYFACE";}
	return "FACE128_"+Characters[charIdx].FaceID;
}

string GetFacePictureName(int charIdx)
{
// KK -->
	if(charIdx<0) {
		if (bNewInterface)
			return "EMPTYFACE_NEW";
		else
			return "EMPTYFACE";
	}
// <-- KK
	return "face";
}

// NK -->
int GetFacePicture(int idx)
{
	if(idx < 0) return -1; // NK 04-11
    // Scheffnow - bfd
	//return Characters[idx].faceID;
	if(CheckAttribute(Characters[idx],"faceID")) return sti(Characters[idx].faceID);
}

string GetFaceGroupNameFromFace(int Idx)
{
	if(Idx<0) {return "EMPTYFACE";}
	return "FACE128_"+Idx;
}

// NK <--

void SetFormatedText(string sNodeName, string sText)
{
	SendMessage(&GameInterface,"lss",MSG_INTERFACE_SET_FORMATEDTEXT,sNodeName,sText);
}

// Sulan: Formated Text with line breaks (\n) -->
void SetFormatedLogText(string sNodeName, string sText)
{
	string sParagraph;
	int breakPos;
	int nextPos;
	bool hasBreak;

	nextPos =0;
	hasBreak = false;
	breakPos = FindSubStr(sText,"\n",nextPos);

	while(breakPos>0)
	{
		hasBreak = true;        
		if((breakPos-1)>nextPos) sParagraph = strcut(sText, nextPos, breakPos-1);
		else sParagraph = "  ";      
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, sNodeName, 0, &sParagraph);
		nextPos = breakPos+2; 
		breakPos = FindSubStr(sText,"\n",nextPos);
	}
	if((strlen(sText)-1)>nextPos && hasBreak == true)
	{
		sParagraph = strcut(sText, nextPos, strlen(sText)-1);
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, sNodeName, 0, &sParagraph);
	}
	if(hasBreak == false)
	{
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, sNodeName, 0, &sText);
	} 
}
// <-- Sulan


//NK/Inez
string FloatToString(float fl,int nDigAfterPoint)
{
	float fmul = pow(10.0,nDigAfterPoint);
	fl = fl + 0.5/fmul;
	int p1 = makeint(fl);
	int p2 = makeint((fl-p1)*fmul);
     string minusstr = ""; if(fl < 0) minusstr = "-";
	return minusstr + abs(p1)+"."+abs(p2);
}

int GetStringWidth(string str, string fontID, float fScale)
{
	return SendMessage(&GameInterface, "lssf", MSG_INTERFACE_GET_STRWIDTH, str, fontID, fScale);
}

string GetItemPictureName(string itemName)
{
	aref arItm;
	if( Items_FindItem(itemName,&arItm)>=0 )
	{
		if( CheckAttribute(arItm,"picIndex") )
		{
			return	"itm"+sti(arItm.picIndex);
		}
	}
	return "cannon back";
}

string GetItemTextureName(string itemName)
{
	aref arItm;
	if( Items_FindItem(itemName,&arItm)>=0 )
	{
		if( CheckAttribute(arItm,"picTexture") )
		{
			return	arItm.picTexture;
		}
	}
	return "ICONS";
}

int GetItemPictureTexture(string accessString, string itemName)
{
	aref arItm,arGroup;
	makearef(arGroup,GameInterface.(accessString));
	string sTexName = "ICONS";

	if( Items_FindItem(itemName,&arItm)>=0 )
	{	if( CheckAttribute(arItm,"picTexture") )
		{	sTexName = arItm.picTexture;
		}
	}
	int q = GetAttributesNum(arGroup);
	for(int i=0; i<q; i++)
	{	if( GetAttributeValue(GetAttributeN(arGroup,i)) == sTexName )
		{	return i;
		}
	}
	return -1;
}

void FillImagesGroupForItems(aref arImgGrp)
{
	//Levis: Improved for performance
	int i,n,q;
	string stmp, stmp2;
	object objtmp;
	n = GetAttributesNum(arImgGrp)+1;
	for(i=0; i<ITEMS_QUANTITY; i++)
	{
		if( CheckAttribute( &Items[i], "picTexture" ) && Items[i].picTexture!="" )
		{
			stmp = Items[i].picTexture;
			if(!CheckAttribute(objtmp,stmp))
			{
				objtmp.(stmp) = true;
				stmp2 = "t"+n;
				arImgGrp.(stmp2) = stmp;
				n++;
			}
		}
	}
	/*q = GetAttributesNum(&objtmp);
	for(i=0; i<q; i++)
	{
		stmp = "t"+n;
		arImgGrp.(stmp) = GetAttributeName(GetAttributeN(&objtmp,i));
		n++;
	}*/
}

string GetFacePicName(ref chref)
{
	return "face";
}

void FillFaceList(string strAccess, ref chref, int fillCode)
{
	aref ar;
	makearef(ar, GameInterface.(strAccess));

	int n, cn, q;

	AddFaceGroup(strAccess,"FACE128_"+chref.faceID);

	if(fillCode==0) // officers
	{
		for(n=1; n<OFFICER_MAX; n++)
		{
			cn = GetOfficersIndex(chref,n);
			if( cn>=0 )
			{
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}

	if(fillCode==1) // companions
	{
		for(n=1; n<COMPANION_MAX; n++)
		{
			cn = GetCompanionIndex(chref,n);
			if( cn>=0 )
			{
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}

	if(fillCode==2) // passengers; Aconcagua: added 3 (2: all, 3 only non-prisoned ones) - 3 removed MM
	{
		q = GetNotCaptivePassengersQuantity(chref);
		for(n=0; n<q; n++)
		{
			cn = GetNotCaptivePassenger(chref,n);
			if( cn>=0 )
			{
				ref chr = &Characters[cn];
				if (!IsOfficer(chr) && !IsPrisoner(chr)) {
					if (CheckAttribute(chr, "faceID"))
					{
						AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
					}
					else
					{
						TraceAndLog("FillFaceList: Face ID missing for " + GetMySimpleName(chr));
						DumpAttributes(chr);
					}
				}
			}
		}
	}

	if(fillCode == 3) // passengers; Aconcagua: added 3 (2: all, 3 only non-prisoned ones) - 3 added MM
	{
		q = GetPassengersQuantity(chref);
		for(n=0; n<q; n++)
		{
			cn = GetPassenger(chref,n);
			if( cn>=0 && IsPrisoner(&Characters[cn])) {
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}

// KK -->
	if (fillCode == 4) // governors
	{
		q = TOWNS_QUANTITY;
		for (n = 0; n < q; n++)
		{
			cn = GetTownGovernorIndex(Towns[n].id);
			if (cn >= 0) AddFaceGroup(strAccess, "FACE128_" + Characters[cn].faceID);
		}
	}

	if (fillCode == 5) // fort commandants
	{
		q = TOWNS_QUANTITY;
		for (n = 0; n < q; n++)
		{
			int fq = GetTownNumForts(Towns[n].id);
			for (int f = 0; f < fq; f++)
			{
				cn = GetTownFortCommanderIndex(Towns[n].id, f);
				if (cn >= 0) AddFaceGroup(strAccess, "FACE128_" + Characters[cn].faceID);
			}
		}
	}
// <-- KK
}

void AddFaceGroup(string strAccess, string groupName)
{
	if( FindFaceGroupNum(strAccess,groupName)<0 )
	{
		aref ar;
		makearef(ar, GameInterface.(strAccess));
		string attrName = "t"+GetAttributesNum(ar);
		ar.(attrName) = groupName;
	}
}

int FindFaceGroupNum(string strAccess, string groupName)
{
	int n, q;
	aref aRoot, aCur;
	makearef(aRoot, GameInterface.(strAccess));

	q = GetAttributesNum(aRoot);
	for(n=0; n<q; n++)
	{
		aCur = GetAttributeN(aRoot,n);
		if( GetAttributeValue(aCur) == groupName ) return n;
	}

	return -1;
}

string GlobalStringConvert(string strID)
{
	return LanguageConvertString( GlobalLngFileID(), strID );
}

// added by MAXIMUS - changes strings to uppercase for using INTERFACE_TITLE with any strings in interfaces -->
void CreateStringCheckCase(int enable, string strName, string strData, string strFont, int color, int x, int y, int alignment, float scale, bool bTranslated)
{
	string strAlfa = "";
	for(int g=0; g<strlen(strData); g++)
	{
		if(strFont==FONT_TITLE)
		{
			if(bTranslated)
			{
				strAlfa += toupper(strcut(strData,g,g)); // KK
			}
			else strAlfa += touppereng(strcut(strData,g,g)); // KK
		}
		else strAlfa += strcut(strData,g,g);
	}
	CreateString(enable,strName,strAlfa,strFont,color,x,y,alignment,scale);
}
string StringCheckCase(string strData, string strFont, bool bTranslated)
{
	string strAlfa = "";
	for(int g=0; g<strlen(strData); g++)
	{
		if(strFont==FONT_TITLE)
		{
			if(bTranslated)
			{
				strAlfa += toupper(strcut(strData,g,g)); // KK
			}
			else strAlfa += touppereng(strcut(strData,g,g)); // KK
		}
		else strAlfa += strcut(strData,g,g);
	}
	if(strAlfa!="") 	return strAlfa;
	return strData;
}
// added by MAXIMUS - changes strings to uppercase for using INTERFACE_TITLE with any strings in interfaces <--

// KK -->
// MAXIMUS 30.06.2019: changed for giving TRANSLATED name to character ==>
void SetMainCharacterName(string newName)
{
	ref mChr = GetMainCharacter();
	int idx = FindCurrentStoryline();

	SetCharacterName(mChr, newName);

	if (CheckAttribute(mChr, "name")) mChr.name = GetTranslatedStoryLine(idx, mChr.name);
	if (CheckAttribute(mChr, "middlename")) mChr.middlename = GetTranslatedStoryLine(idx, mChr.middlename);
	if (CheckAttribute(mChr, "lastname")) mChr.lastname = GetTranslatedStoryLine(idx, mChr.lastname);}

void SetCharacterName(ref chr, string newName)
{
	chr.name = "";
	chr.old.name = "";
	chr.middlename = "";
	chr.old.middlename = "";
	chr.lastname = "";
	chr.old.lastname = "";
	bool bNamed = CheckAttribute(chr, "named");

	string part1 = "";
	string part2 = "";
	bool bRes = DivideString(newName, " ", &part1, &part2);
	if (part2 == "") {
		chr.lastname = newName;
		if(strcut(chr.lastname,0,0)==" ") chr.lastname = strRight(chr.lastname,strlen(chr.lastname)-1); //MAXIMUS: fix for some names, which somehow have space before first letter
		if(!bNamed) chr.old.lastname = chr.lastname;
		return;
	}
	chr.name = part1;
	if(strcut(chr.name,0,0)==" ") chr.name = strRight(chr.name,strlen(chr.name)-1);
	if(!bNamed) chr.old.name = chr.name;
	newName = part2;
	while (DivideString(newName, " ", &part1, &part2)) {
		if (part1 == "de" || part1 == "van" || part1 == "da" || part1 == "la" || part1 == "di" || part1 == "o" || part1 == "von") break;
			if (chr.middlename == "") chr.middlename = part1;
		else chr.middlename = chr.middlename + " " + part1;
		
		if(strcut(chr.middlename,0,0)==" ") chr.middlename = strRight(chr.middlename,strlen(chr.middlename)-1); //MAXIMUS: fix for some names, which somehow have space before first letter
		if(!bNamed) chr.old.middlename = chr.middlename;
		newName = part2;
	}
	chr.lastname = newName;
	if(strcut(chr.lastname,0,0)==" ") chr.lastname = strRight(chr.lastname,strlen(chr.lastname)-1); //MAXIMUS: fix for some names, which somehow have space before first letter
	if(!bNamed) chr.old.lastname = chr.lastname;
		if (CheckAttribute(chr, "middlename") == true && chr.middlename == "") {
		DeleteAttribute(chr, "middlename");
		if (CheckAttribute(chr, "old.middlename")) DeleteAttribute(chr, "old.middlename");
	}
}

string GetFlagPicName(int curNation)
{
	int ntexture = GetCurrentPeriod();
	string imageName;
	ref mchr = GetMainCharacter();
	curNation = GetFlagIndex(curNation);
	switch (curNation)
	{
		case PERSONAL_NATION:
			imageName = "Personal" + GetPersonalFlag(mchr, &ntexture);
		break;
		case PIRATE:
			imageName = "Pirate" + GetPirateFlag(mchr, &ntexture);
		break;
		case GUEST1_NATION:
			imageName = "Guest1";
		break;
		case GUEST2_NATION:
			imageName = "Guest2";
		break;
		// default:
			imageName = GetNationIDByType(curNation);
			if (hasSubStr(imageName, "unknown") == true || imageName == "no nation") imageName = "Personal" + GetPersonalFlag(mchr, &ntexture);
	}
	return imageName + ntexture;
}

string GetNationFlagImage(int nation)
{
	string nationpic = GetFlagPicName(nation);
	if(nation == PIRATE) nationpic = "Pirate00";
	return nationpic;
}

void InitToolTip()
{
	if (!CheckAttribute(&GameInterface, "ToolTip")) GameInterface.ToolTip = "";
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	DeleteAttribute(arToolTip, "");
	arToolTip.ImagesGroup.i0 = "";
	arToolTip.Fader.Node = "TOOLTIP_FADER";
	arToolTip.Rectangle.r0.Used = true;
	arToolTip.Rectangle.r0.Node = "TOOLTIP_RECTANGLE";
	arToolTip.Header.h0 = "";
	arToolTip.Header.h0.Used = false;
	arToolTip.Header.h0.Node = "TOOLTIP_HEADER";
	arToolTip.Text.t0 = "";
	arToolTip.Text.t0.Used = false;
	arToolTip.Text.t0.Node = "TOOLTIP_TEXT";
	arToolTip.Picture.p0 = "";
	arToolTip.Picture.p0.Used = false;
	arToolTip.BGPicture.p0 = "";
	arToolTip.BGPicture.p0.Used = false;
	arToolTip.Picture.p0.Node = "TOOLTIP_PICTURE";
	arToolTip.Image.i0 = "";
	arToolTip.Image.i0.Used = false;
	arToolTip.BGImage.i0 = "";
	arToolTip.BGImage.i0.Used = false;
	arToolTip.Image.i0.Node = "TOOLTIP_PICTURE";
	arToolTip.CurrentNode = "";
	arToolTip.Visible = false;
}

void ChangeDefaultToolTipNode(string nodetype, string nodename)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	if (nodetype == TOOLTIP_FADER) {
		if (!CheckAttribute(arToolTip, nodetype + ".Node")) return;
		arToolTip.(nodetype).Node = nodename;
	} else {
		string stype = "Text";
		switch (nodetype) {
			case TOOLTIP_RECTANGLE:
				stype = "Rectangle";
			break;
			case TOOLTIP_HEADER:
				stype = "Header";
			break;
			case TOOLTIP_PICTURE:
				stype = "Picture";
			break;
		}
		aref arNodeList; makearef(arNodeList, arToolTip.(stype));
		aref arNode = GetAttributeN(arNodeList, 0);
		arNode.Node = nodename;
		if (Nodetype == TOOLTIP_PICTURE) {
			makearef(arNodeList, arToolTip.Image);
			arNode = GetAttributeN(arNodeList, 0);
			arNode.Node = Nodename;
		}
	}
}

void AddToolTipNode(int Nodetype, string name)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
		string stype = "Text";
		switch (Nodetype) {
			case TOOLTIP_RECTANGLE:
				stype = "Rectangle";
			break;
			case TOOLTIP_HEADER:
				stype = "Header";
			break;
			case TOOLTIP_PICTURE:
				stype = "Picture";
			break;
		}
	aref arNodeList; makearef(arNodeList, arToolTip.(stype));
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == name) return;
	}
	string node = "";
	switch (Nodetype) {
		case TOOLTIP_RECTANGLE:
			node = "r" + inum;
			arNodeList.(node).Used = false;
			arNodeList.(node).Node = name;
		break;
		case TOOLTIP_HEADER:
			node = "h" + inum;
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
			arNodeList.(node).Node = name;
		break;
		case TOOLTIP_PICTURE:
			node = "p" + inum;
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
			arNodeList.(node).Node = name;
			makearef(arNodeList, arToolTip.BGPicture);
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
			node = "i" + inum;
			makearef(arNodeList, arToolTip.Image);
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
			arNodeList.(node).Node = name;
			makearef(arNodeList, arToolTip.BGImage);
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
		break;
		// default:
			node = "t" + inum;
			arNodeList.(node) = "";
			arNodeList.(node).Used = false;
			arNodeList.(node).Node = name;
	}
}

void SetToolTipRectangle(string Nodename)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Rectangle);
	if (Nodename == "") Nodename = arNodeList.r0.Node;
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename)
			arNode.Used = true;
		else
			arNode.Used = false;
	}
}

void SetToolTipHeader(string Nodename, string header)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Header);
	if (Nodename == "") Nodename = arNodeList.h0.Node;
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			string attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = header;
			arNode.Used = true;
		} else {
			arNode.Used = false;
		}
	}
}

void SetToolTipText(string Nodename, string text)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Text);
	if (Nodename == "") Nodename = arNodeList.t0.Node;
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			string attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = text;
			arNode.Used = true;
		}
	}
}

void AddToolTipPictureImageGroup(string igroup)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	if (arToolTip.ImagesGroup.i0 == "") {
		arToolTip.ImagesGroup.i0 = igroup;
		return;
	}
	aref ig; makearef(ig, GameInterface.ToolTip.ImagesGroup);
	int inum = GetAttributesNum(ig);
	string si = "i" + inum;
	arToolTip.ImagesGroup.(si) = igroup;
}

void SetToolTipPicture(string Nodename, string PicGroup, string Picture)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Picture);
	if (Nodename == "") Nodename = arNodeList.p0.Node;
	int inum = GetAttributesNum(arNodeList);
	string attrname = "";
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = Picture;
			arNode.Group = "";
			arNode.Used = true;
			attrname = GetAttributeName(arNode);
			aref arImgGrp; makearef(arImgGrp, arToolTip.ImagesGroup);
			int ignum = GetAttributesNum(arImgGrp);
			for (int j = 0; j < ignum; j++) {
				string si = "i" + j;
				if (arImgGrp.(si) == PicGroup) {
					arNode.Group = j;
					break;
				}
			}
			break;
		}
	}
}

void SetToolTipBackgroundPicture(string Nodename, string PicGroup, string Picture)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.BGPicture);
	if (Nodename == "") Nodename = arToolTip.Picture.p0.Node;
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			string attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = Picture;
			arNode.Group = "";
			arNode.Used = true;
			aref arImgGrp; makearef(arImgGrp, arToolTip.ImagesGroup);
			int ignum = GetAttributesNum(arImgGrp);
			for (int j = 0; j < ignum; j++) {
				string si = "i" + j;
				if (arImgGrp.(si) == PicGroup) {
					arNode.Group = j;
					break;
				}
			}
			break;
		}
	}
}

void SetToolTipImage(string Nodename, string tgafile)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Image);
	if (Nodename == "") Nodename = arNodeList.i0.Node;
	int inum = GetAttributesNum(arNodeList);
	string attrname = "";
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = tgafile;
			arNode.Used = true;
			break;
		}
	}
}

void SetToolTipBackgroundImage(string Nodename, string tgafile)
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.BGImage);
	if (Nodename == "") Nodename = arToolTip.Image.i0.Node;
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (arNode.Node == Nodename) {
			string attrname = GetAttributeName(arNode);
			arNodeList.(attrname) = tgafile;
			arNode.Used = true;
			break;
		}
	}
}

void ShowToolTip()
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);

	if (sti(arToolTip.Visible) == true) return;

	SetToolTip();

	arToolTip.CurrentNode = GetCurrentNode();

	SetNodeUsing(arToolTip.Fader.Node, true);

	int i, inum;
	aref arNodeList, arNode;
	makearef(arNodeList, arToolTip.Rectangle);
	inum = GetAttributesNum(arNodeList);
	for (i = 0; i < inum; i++) {
		arNode = GetAttributeN(arNodeList, i);
		if (sti(arNode.Used) == true) SetNodeUsing(arNode.Node, true);
	}

	makearef(arNodeList, arToolTip.Header);
	inum = GetAttributesNum(arNodeList);
	for (i = 0; i < inum; i++) {
		arNode = GetAttributeN(arNodeList, i);
		if (sti(arNode.Used) == true) {
			SetFormatedText(arNode.Node, GetAttributeValue(arNode));
			SetNodeUsing(arNode.Node, true);
		}
	}

	makearef(arNodeList, arToolTip.Text);
	inum = GetAttributesNum(arNodeList);
	for (i = 0; i < inum; i++) {
		arNode = GetAttributeN(arNodeList, i);
		if (sti(arNode.Used) == true) {
			SetFormatedText(arNode.Node, GetAttributeValue(arNode));
			SetNodeUsing(arNode.Node, true);
		}
	}

	aref arNodeBgList, arNodeBg;
	string img, tex, tooltip_pict, name, bgname;

	makearef(arNodeList, arToolTip.Image);
	makearef(arNodeBGList, arToolTip.BGImage);
	inum = GetAttributesNum(arNodeList);
	for (i = 0; i < inum; i++) {
		img = "";
		tex = "";
		arNode = GetAttributeN(arNodeList, i);
		arNodeBg = GetAttributeN(arNodeBgList, i);
		if (sti(arNode.Used) == false && sti(arNodeBg.Used) == false) continue;
		tooltip_pict = arNode.Node;
		name = GetAttributeValue(arNode);
		bgname = "";
		if (name != "") {
			arNodeBg = GetAttributeN(arNodeBgList, i);
			bgname = GetAttributeValue(arNodeBg);
			img = "BadPicture1";
			if (bgname != "") {
				img = "BadPicture2";
				GameInterface.(tooltip_pict).BadPicture1 = bgname;
				GameInterface.(tooltip_pict).pic1.img1 = "";
				GameInterface.(tooltip_pict).pic1.tex1 = -1;
			}
			GameInterface.(tooltip_pict).(img) = name;
			GameInterface.(tooltip_pict).pic1.(img) = "";
			GameInterface.(tooltip_pict).pic1.(tex) = -1;
		}
		SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, tooltip_pict);
		SetNodeUsing(tooltip_pict, true);
	}

	makearef(arNodeList, arToolTip.Picture);
	makearef(arNodeBGList, arToolTip.BGPicture);
	inum = GetAttributesNum(arNodeList);
	for (i = 0; i < inum; i++) {
		img = "";
		tex = "";
		arNode = GetAttributeN(arNodeList, i);
		arNodeBg = GetAttributeN(arNodeBgList, i);
		if (sti(arNode.Used) == false && sti(arNodeBg.Used) == false) continue;
		tooltip_pict = arNode.Node;
		name = GetAttributeValue(arNode);
		bgname = "";
		if (name != "" && arNode.Group != "") {
			img = "img1";
			tex = "tex1";
			bgname = GetAttributeValue(arNodeBg);
			if (bgname != "" && arNodeBg.Group != "") {
				img = "img2";
				tex = "tex2";
				GameInterface.(tooltip_pict).pic1.img1 = bgname;
				GameInterface.(tooltip_pict).pic1.tex1 = arNodeBg.Group;
			}
			GameInterface.(tooltip_pict).pic1.(img) = name;
			GameInterface.(tooltip_pict).pic1.(tex) = arNode.Group;
		}
		SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, tooltip_pict);
		SetNodeUsing(tooltip_pict, true);
	}

	arToolTip.Visible = true;
}

void HideToolTip()
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	if (sti(arToolTip.Visible) == true) {
		aref arNodeList, arNode, arNodeBgList, arNodeBg;
		makearef(arNodeList, arToolTip.Image);
		makearef(arNodeBgList, arToolTip.BGImage);
		int inum = GetAttributesNum(arNodeList);
		int i = 0;
		for (i = 0; i < inum; i++) {
			arNode = GetAttributeN(arNodeList, i);
			if (!CheckAttribute(arNode, "Node")) continue;
			arNode.Used = false;
			SetNodeUsing(arNode.Node, false);
			string name = GetAttributeName(arNode);
			arNodeList.(name) = "empty.tga";
			arNodeBg = GetAttributeN(arNodeBgList, i);
			name = GetAttributeName(arNodeBg);
			arNodeList.(name) = "empty.tga";
		}
		makearef(arNodeList, arToolTip.Picture);
		inum = GetAttributesNum(arNodeList);
		for (i = 0; i < inum; i++) {
			arNode = GetAttributeN(arNodeList, i);
			if (!CheckAttribute(arNode, "Node")) continue;
			arNode.Used = false;
			SetNodeUsing(arNode.Node, false);
		}
		makearef(arNodeList, arToolTip.Text);
		inum = GetAttributesNum(arNodeList);
		for (i = 0; i < inum; i++) {
			arNode = GetAttributeN(arNodeList, i);
			if (!CheckAttribute(arNode, "Node")) continue;
			arNode.Used = false;
			SetNodeUsing(arNode.Node, false);
		}
		makearef(arNodeList, arToolTip.Header);
		inum = GetAttributesNum(arNodeList);
		for (i = 0; i < inum; i++) {
			arNode = GetAttributeN(arNodeList, i);
			if (!CheckAttribute(arNode, "Node")) continue;
			SetNodeUsing(arNode.Node, false);
			if (sti(arNode.Used) == true) break;
		}
		makearef(arNodeList, arToolTip.Rectangle);
		inum = GetAttributesNum(arNodeList);
		for (i = 0; i < inum; i++) {
			arNode = GetAttributeN(arNodeList, i);
			if (!CheckAttribute(arNode, "Node")) continue;
			SetNodeUsing(arNode.Node, false);
			if (sti(arNode.Used) == true) break;
		}
		SetNodeUsing(arToolTip.Fader.Node, false);
		SetCurrentNode(arToolTip.CurrentNode);

		arToolTip.Visible = false;
	}
}

void SetToolTip()
{
	aref arToolTip; makearef(arToolTip, GameInterface.ToolTip);
	aref arNodeList; makearef(arNodeList, arToolTip.Picture);
	int inum = GetAttributesNum(arNodeList);
	for (int i = 0; i < inum; i++) {
		aref arNode = GetAttributeN(arNodeList, i);
		if (!CheckAttribute(arNode, "Node")) continue;
		string tooltip_pict = arNode.Node;
		DeleteAttribute(&GameInterface, tooltip_pict);
		GameInterface.(tooltip_pict).current = 0;
		GameInterface.(tooltip_pict).BadPicture1 = "empty.tga";
		GameInterface.(tooltip_pict).BadPicture2 = "empty.tga";
		aref arImgGrp; makearef(arImgGrp, arToolTip.ImagesGroup);
		int nnum = GetAttributesNum(arImgGrp);
		for (int n = 0; n < nnum; n++) {
			string t = "t" + n;
			string si = "i" + n;
			GameInterface.(tooltip_pict).ImagesGroup.(t) = arImgGrp.(si);
		}
		GameInterface.(tooltip_pict).pic1.img1 = "";
		GameInterface.(tooltip_pict).pic1.tex1 = 0;
		GameInterface.(tooltip_pict).pic1.img2 = "";
		GameInterface.(tooltip_pict).pic1.tex2 = 0;
		GameInterface.(tooltip_pict).ListSize = 0;
		GameInterface.(tooltip_pict).NotUsed = 1;
	}
}

void CreateCheckbox(string name, string label, string font, int color, int posx, int posy, float scale, int type, int init_state)
{
	string chk = ReturnCheckboxPic(init_state);
	CreateImage(name, "CHECKBOX", chk, posx, posy, posx + 18, posy + 18);
	GameInterface.CheckBox.(name).type = type;
	GameInterface.CheckBox.(name).state = init_state;
	GameInterface.CheckBox.(name).pos.x = posx;
	GameInterface.CheckBox.(name).pos.y = posy;
	GameInterface.CheckBox.(name).visible = true;
	GameInterface.CheckBox.(name).selectable = true;
	if (label != "") {
		CreateString(true, name, label, font, color, posx + 24, posy, SCRIPT_ALIGN_LEFT, scale);
		GameInterface.CheckBox.(name).label = label;
		GameInterface.CheckBox.(name).font = font;
		GameInterface.CheckBox.(name).color = color;
		GameInterface.CheckBox.(name).scale = scale;
	}
}

int GetCheckboxType(string name)
{
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".type")) return sti(GameInterface.CheckBox.(name).type);
	return -1;
}

void SetCheckboxLabelOffset(string name, int xoffset)
{
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".label")) {
		RemoveString(name);
		CreateString(true, name, GameInterface.CheckBox.(name).label, GameInterface.CheckBox.(name).font, sti(GameInterface.CheckBox.(name).color), sti(GameInterface.CheckBox.(name).pos.x) + xoffset + 24, sti(GameInterface.CheckBox.(name).pos.y), SCRIPT_ALIGN_LEFT, stf(GameInterface.CheckBox.(name).scale));
	}
}

void EnableCheckbox(string name)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name)) return;
	string chk = ReturnCheckboxPic(GetCheckbox(name));
	int posx = sti(GameInterface.CheckBox.(name).pos.x);
	int posy = sti(GameInterface.CheckBox.(name).pos.y);
	int color = 0;
	CreateImage(name, "CHECKBOX", chk, posx, posy, posx + 18, posy + 18);
	SetNodeUsing(name, true);
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".label")) {
		EnableString(name);
		color = sti(GameInterface.CheckBox.(name).color);
		if (IsCheckboxSelectable(name))
			ChangeStringColor(name, color);
		else
			ChangeStringColor(name, COLOR_DESELECT);
	}
	GameInterface.CheckBox.(name).visible = true;
	SetCheckboxSelectable(name, IsCheckboxSelectable(name));
}

void DisableCheckbox(string name)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name)) return;
	int posx = sti(GameInterface.CheckBox.(name).pos.x);
	int posy = sti(GameInterface.CheckBox.(name).pos.y);
	CreateImage(name, "", "", posx, posy, posx + 18, posy + 18);
	SetNodeUsing(name, false);
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".label")) DisableString(name);
	GameInterface.CheckBox.(name).visible = false;
}

bool IsCheckboxVisible(string name)
{
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".visible")) return sti(GameInterface.CheckBox.(name).visible);
	return true;
}

void SetCheckboxSelectable(string name, bool bset)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name)) return;
	string chk = ReturnCheckboxPic(GetCheckbox(name));
	int posx = sti(GameInterface.CheckBox.(name).pos.x);
	int posy = sti(GameInterface.CheckBox.(name).pos.y);
	int color = COLOR_DESELECT;
	if (bset && CheckAttribute(&GameInterface, "CheckBox." + name + ".color")) color = sti(GameInterface.CheckBox.(name).color);
	CreateImage(name, "CHECKBOX", chk, posx, posy, posx + 18, posy + 18);
	SetNodeUsing(name, bset);
	if (IsCheckboxVisible(name)) ChangeStringColor(name, color);
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".label")) EnableString(name);
	GameInterface.CheckBox.(name).selectable = bset;
}

bool IsCheckboxSelectable(string name)
{
	if (CheckAttribute(&GameInterface, "CheckBox." + name + ".selectable")) return sti(GameInterface.CheckBox.(name).selectable);
	return true;
}

void SetCheckbox(string name, int state)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name)) return;
	string chk = ReturnCheckboxPic(state);
	int posx = sti(GameInterface.CheckBox.(name).pos.x);
	int posy = sti(GameInterface.CheckBox.(name).pos.y);
	CreateImage(name, "CHECKBOX", chk, posx, posy, posx + 18, posy + 18);
	GameInterface.CheckBox.(name).state = state;
}

int GetCheckbox(string name)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name + ".state")) return CHECKBOX_OFF;
	return sti(GameInterface.CheckBox.(name).state);
}

string ReturnCheckboxPic(int state)
{
	string chk = "";
	switch (state)
	{
		case CHECKBOX_OFF:
			chk = "check_noncomplete";
		break;
		case CHECKBOX_SET:
			chk = "check_complete";
		break;
		case CHECKBOX_UNSET:
			chk = "check_unselect";
		break;
	}
	if (bNewInterface == true && chk != "") chk += "_new";
	return chk;
}

void DoCheckboxClick(string name)
{
	if (!CheckAttribute(&GameInterface, "CheckBox." + name)) return;
	int state = GetCheckbox(name);
	int type = GetCheckboxType(name);
	switch (state)
	{
		case CHECKBOX_OFF:
			SetCheckbox(name, CHECKBOX_SET);
		break;
		case CHECKBOX_SET:
			if (type == CHECKBOXTYPE_TWOSELECT)
				SetCheckbox(name, CHECKBOX_OFF);
			else
				SetCheckbox(name, CHECKBOX_UNSET);
		break;
		case CHECKBOX_UNSET:
			SetCheckbox(name, CHECKBOX_OFF);
		break;
	}
}

void SetTab(string name, string label, string font, int color, int posx0, int posy0, int posx1, int posy1, float scale, int iState, bool bSelectable)
{
	switch (iState)
	{
		case TAB_HIDE:
			RemovePicture(name);
			DisableString(name);
			SetNodeUsing(name, false);
			return;
		break;
		case TAB_ACTIVE:
			CreateImage(name, "ICONS", "selected tab", posx0, posy0, posx1, posy1);
		break;
		// default:
			CreateImage(name, "ICONS", "unselected tab", posx0, posy0, posx1, posy1);
	}
	bool bState = iState;
	if (bSelectable) {
		CreateString(true, name, label, font, color, posx0 + makeint(makefloat(posx1 - posx0) / 2.0), iretMin(posy0, posy1) + 2, SCRIPT_ALIGN_CENTER, scale);
		SetNodeUsing(name, bState);
	} else {
		CreateString(true, name, label, font, COLOR_DESELECT, posx0 + makeint(makefloat(posx1 - posx0) / 2.0), iretMin(posy0, posy1) + 2, SCRIPT_ALIGN_CENTER, scale);
		SetNodeUsing(name, false);
	}
}

void CreateTextbox(bool bEnable, string name, string node_inactive, string node_active1, string node_active2, string text, int posx, int posy, float scale)
{
	if (CheckAttribute(&GameInterface, "TextBox." + name)) DeleteAttribute(&GameInterface, "TextBox." + name);
	GameInterface.TextBox.(name).Text = text;
	aref arTextbox; makearef(arTextbox, GameInterface.TextBox.(name));
	arTextbox.Inactive = node_inactive;
	SetNodeUsing(node_inactive, true);
	arTextbox.Active1 = node_active1;
	SetNodeUsing(node_active1, false);
	if (node_active2 != "") {
		arTextbox.Active2 = node_active2;
		SetNodeUsing(node_active2, false);
	}
	SetNodeUsing(node_inactive, bEnable);
	CreateString(bEnable, name, text, FONT_SEADOGS, COLOR_NORMAL, posx, posy, SCRIPT_ALIGN_CENTER, scale);
}

void SetTextboxMaxCharacters(string name, int maxchars)
{
	if (maxchars <= 0) {
		if (CheckAttribute(&GameInterface, "TextBox." + name + ".maxchars")) DeleteAttribute(&GameInterface, "TextBox." + name + ".maxchars");
		return;
	}
	GameInterface.TextBox.(name).maxchars = maxchars;
}

void SetTextboxNumeric(string name)
{
	GameInterface.TextBox.(name).numeric = true;
}

void SetTextboxMinMax(string name, int minVal, int maxVal)
{
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	if (CheckAttribute(arTextbox, "numeric") == false || sti(arTextbox.numeric) == false) return;
	if (minVal < maxVal) arTextbox.minValue = minVal;
	if (maxVal > minVal) arTextbox.maxValue = maxVal;
}

void SetTextBoxReadOnly(string name, bool bReadOnly)
{
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	if (bReadOnly) {
		arTextbox.ReadOnly = true;
		ChangeStringColor(name, COLOR_DESELECT);
	} else {
		if (CheckAttribute(arTextbox, "ReadOnly")) DeleteAttribute(arTextbox, "ReadOnly");
		ChangeStringColor(name, COLOR_NORMAL);
	}
	SetNodeUsing(arTextbox.Active1, bReadOnly);
	if (CheckAttribute(arTextbox, "Active2")) SetNodeUsing(arTextbox.Active2, bReadOnly);
	SetNodeUsing(arTextbox.Inactive, !bReadOnly);
}

bool IsTextBoxReadOnly(string name)
{
	if (CheckAttribute(&GameInterface, "TextBox." + name + ".ReadOnly")) return sti(GameInterface.TextBox.(name).ReadOnly);
	return false;
}

void EnableTextbox(string name)
{
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	SetNodeUsing(arTextbox.Inactive, true);
	EnableString(name);
	SetTextBoxReadOnly(name, IsTextBoxReadOnly(name));
}

void DisableTextbox(string name)
{
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	SetNodeUsing(arTextbox.Inactive, false);
	SetNodeUsing(arTextbox.Active1, false);
	if (CheckAttribute(arTextbox, "Active2")) SetNodeUsing(arTextbox.Active2, false);
	DisableString(name);
}

void ActivateTextbox(string name)
{
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	GameInterface.TextBox.current = name;
	makearef(arTextbox, GameInterface.TextBox.(name));
	SetEventHandler("KB_Esc", "Textbox_Esc", 0);
	SetEventHandler("KB_End", "Textbox_Enter", 0);
	SetEventHandler("KB_Update", "Textbox_Update", 0);
	SetNodeUsing(arTextbox.Active1, true);
	if (CheckAttribute(arTextbox, "Active2")) SetNodeUsing(arTextbox.Active2, true);
	SetNodeUsing(arTextbox.Inactive, false);
	SendMessage(&GameInterface, "lls", MSG_INTERFACE_LOCK_NODE, 1, arTextbox.Active1);
	SetCurrentNode(arTextbox.Active1);
	arTextbox.Text = GameInterface.strings.(name);
	KB_SetKeyboardMode(true);
	KB_Prepare(GameInterface.strings.(name));
	Event("KB_Update");
}

void Textbox_Enter()
{
	Textbox_Write(true);
}

void Textbox_Esc()
{
	Textbox_Write(false);
}

void Textbox_Write(bool bAccept)
{
	int v;
	string name;
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox.current")) return;
	name = GameInterface.TextBox.current;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	if (GetCurrentNode() == arTextbox.Active1) {
		if (bAccept)
			GameInterface.strings.(name) = KeyboardString;
			GameInterface.strings.(name).named = true;
		else
			GameInterface.strings.(name) = arTextbox.text;
		if (CheckAttribute(arTextbox, "numeric") == true && KeyboardString != "") {
			if (CheckAttribute(arTextbox, "minValue")) {
				v = sti(arTextbox.minValue);
				if (sti(GameInterface.strings.(name)) < v) GameInterface.strings.(name) = arTextbox.text;
			}
			if (CheckAttribute(arTextbox, "maxValue")) {
				v = sti(arTextbox.maxValue);
				if (sti(GameInterface.strings.(name)) > v) GameInterface.strings.(name) = arTextbox.text;
			}
		}
		SetNodeUsing(arTextbox.Inactive, true);
		SetNodeUsing(arTextbox.Active1, false);
		if (CheckAttribute(arTextbox, "Active2")) SetNodeUsing(arTextbox.Active2, false);
		SendMessage(&GameInterface, "ll", MSG_INTERFACE_LOCK_NODE, 0);
		DelEventHandler("KB_Esc", "Textbox_Esc");
		DelEventHandler("KB_End", "Textbox_Enter");
		DelEventHandler("KB_Update", "Textbox_Update");
	}
}

void Textbox_Update()
{
	string name;
	aref arTextbox;
	if (!CheckAttribute(&GameInterface, "TextBox.current")) return;
	name = GameInterface.TextBox.current;
	if (!CheckAttribute(&GameInterface, "TextBox." + name)) return;
	makearef(arTextbox, GameInterface.TextBox.(name));
	if (GetCurrentNode() == arTextbox.Active1) GameInterface.strings.(name) = KeyboardDisplayString;
}
// <-- KK
