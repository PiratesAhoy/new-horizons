#define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

#define IC_GOVERNOR  1
#define IC_FC        2

string oldCurNode = "";

int nCurScrollNum;
int nCurChar = IC_GOVERNOR;
ref _refCh;
string colony_name = "";
int govidx = -1;
int fcidx = -1;
bool hasGovernor = false;
bool hasFortCommandant = false;
int iTaxLevel = TAX_NORMAL;
bool bMyColony = false;

void InitInterface_RS(string iniName,ref _refCharacter, string _colony_name)
{
	_refCh = _refCharacter;
	colony_name = _colony_name;
	ref mc = GetMainCharacter();
	iTaxLevel = TAX_NORMAL;
	bMyColony = CheckAttribute(mc, "colony_capture") == false;

	if (bMyColony)
		GameInterface.title = "titleColonyManage";
	else
		GameInterface.title = "titleColonyCapture";

// KK -->
	GameInterface.RGOV.current = 0;
	GameInterface.RGOV.ImagesGroup.t0 = "EMPTYFACE";
	FillFaceList("RGOV.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList("RGOV.ImagesGroup", _refCh, 2 ); // passengers
	FillFaceList("RGOV.ImagesGroup", _refCh, 4 ); // governors
	FillFaceList("RGOV.ImagesGroup", _refCh, 5 ); // fort commanders
	GameInterface.RGOV.pic1.str1 = "";
	GameInterface.RGOV.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.RGOV.pic1.img1 = "emptyface_new";
	GameInterface.RGOV.pic1.tex1 = 0;
	GameInterface.RGOV.ListSize = 1;
	GameInterface.RGOV.NotUsed = 1;

	GameInterface.RFC.current = 0;
	GameInterface.RFC.ImagesGroup.t0 = "EMPTYFACE";
	FillFaceList("RFC.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList("RFC.ImagesGroup", _refCh, 2 ); // passengers
	FillFaceList("RFC.ImagesGroup", _refCh, 4 ); // governors
	FillFaceList("RFC.ImagesGroup", _refCh, 5 ); // fort commanders
	GameInterface.RFC.pic1.str1 = "";
	GameInterface.RFC.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.RFC.pic1.img1 = "emptyface_new";
	GameInterface.RFC.pic1.tex1 = 0;
	GameInterface.RFC.ListSize = 1;
	GameInterface.RFC.NotUsed = 1;
// <-- KK

	FillScroll();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	if (bMyColony) {
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "ASSIGNGOV_BUTTON", 0, XI_ConvertString("OK"));
		if (bNewInterface) SetNewPicture("BACKGROUND", "interfaces\background\port.tga");
		CreateString(true, "HelpText", XI_ConvertString("ManageHelpString"), FONT_NORMAL, COLOR_MONEY, 320, 478, SCRIPT_ALIGN_CENTER, 0.7);
		SetSelectable("RGOV", false);
		SetSelectable("RFC", false);
	}
	else
	{
		CreateString(true, "HelpText", XI_ConvertString("CaptureHelpString"), FONT_NORMAL, COLOR_RED_LIGHT, 320, 478, SCRIPT_ALIGN_CENTER, 0.7);
	}

	CreateString(true, "ColonyName", FindTownName(colony_name), FONT_SEADOGS, COLOR_NORMAL, 200, 198, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(true, "TaxationLevel", XI_GetTaxationLevelName(), FONT_NORMAL, COLOR_NORMAL, 530, 198, SCRIPT_ALIGN_CENTER, 1.0);
	govidx = GetTownGovernorIndex(colony_name);
	fcidx = GetTownFortCommanderIndex(colony_name, 0);
	hasGovernor = govidx != -1;
	hasFortCommandant = GetTownNumForts(colony_name) > 0;
	if (hasGovernor)
	{
		CreateString(true, "Governor", XI_ConvertString("Governor"), FONT_NORMAL, COLOR_NORMAL, 94, 390, SCRIPT_ALIGN_CENTER, 1.0);
		if (bMyColony)
		{
			GameInterface.RGOV.pic1.str1 = "#" + GetMySimpleName(GetCharacter(govidx));
			GameInterface.RGOV.pic1.img1 = GetFacePicName(GetCharacter(govidx));
			GameInterface.RGOV.pic1.tex1 = FindFaceGroupNum("RGOV.ImagesGroup", "FACE128_" + Characters[govidx].FaceID);
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "RGOV");
		}
		else
			govidx = -1;
	}
	else
		SetSelectable("RGOV", false);

	if (hasFortCommandant)
	{
		CreateString(true, "FortCommandant", XI_ConvertString("Fort Commandant"), FONT_NORMAL, COLOR_NORMAL, 546, 390, SCRIPT_ALIGN_CENTER, 1.0);
		if (bMyColony)
		{
			GameInterface.RFC.pic1.str1 = "#" + GetMySimpleName(GetCharacter(fcidx));
			GameInterface.RFC.pic1.img1 = GetFacePicName(GetCharacter(fcidx));
			GameInterface.RFC.pic1.tex1 = FindFaceGroupNum("RFC.ImagesGroup", "FACE128_" + Characters[fcidx].FaceID);
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "RFC");
		}
		else
			fcidx = -1;
	}
	else
		SetSelectable("RFC", false);

	if (hasGovernor)
		Event("PressGov");
	else
		Event("PressFC");

	SetCurrentNode("PASSENGERSLIST");

	CreateString(true,"skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,368,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,368,SCRIPT_ALIGN_RIGHT,1.0);


	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	if (!bMyColony) SetSelectable("ASSIGNGOV_BUTTON", false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	/* BEGIN MOD : Stone-D 01/08/2003 */
	SetEventHandler("PassengerDown","PassengerDown",0);
	SetEventHandler("AssignGov","ProcessAssignGov",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	/* END MOD : Stone-D 01/08/2003 */
// KK -->
	SetEventHandler("PressGov", "ProcessGovSelect", 0);
	SetEventHandler("PressFC", "ProcessFCSelect", 0);
	SetEventHandler("PressNone", "ProcessNoneSelect", 0);
	SetEventHandler("ColonyNameChange", "ProcessColonyNameChange", 0);
	SetEventHandler("KB_End","WriteName",0);
	SetEventHandler("KB_Update", "UpdateName", 0);
	SetEventHandler("NodeCancel", "ProcessNodeCancel", 0);
	SetEventHandler("IEvnt_MouseClick", "IProcMouseClick", 0);
	SetEventHandler("ChangeTaxLeft", "DoTaxChangeLeft", 0);
	SetEventHandler("ChangeTaxRight", "DoTaxChangeRight", 0);
// <-- KK
}

void FillScroll()
{
	int i;
	string faceName;
	string attributeName;
	string PsgAttrName;
	int _curCharIdx;
	ref _refCurChar;
	aref pRef;

	nCurScrollNum = -1;
	GameInterface.passengerslist.current = 0;
	makearef(pRef,_refCh.Fellows.Passengers);
	int nListSize = GetPassengersQuantity(_refCh);
	GameInterface.passengerslist.NotUsed = 5;
	//GameInterface.passengerslist.ListSize = nListSize;

	GameInterface.passengerslist.ImagesGroup.t0 = "EMPTYFACE";

	FillFaceList( "passengerslist.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 2 ); // passengers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 5 ); // fort commanders
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 4 ); // governors

	GameInterface.passengerslist.BadTex1 = 0;
// KK -->
	if (bNewInterface)
		GameInterface.passengerslist.BadPic1 = "emptyface_new";
	else
		GameInterface.passengerslist.BadPic1 = "emptyface";
// <-- KK

	for(i = 0; i < nListSize; i++)
	{
		attributeName = "pic" + (i+1);
		PsgAttrName = "id"+(i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		if (_curCharIdx != -1) {
			GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
			GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
			GameInterface.passengerslist.(attributeName).str1 = "#" + GetMySimpleName(GetCharacter(_curCharIdx));
		} else {
// KK -->
			if (bNewInterface)
				GameInterface.passengerslist.(attributeName).img1 = "emptyface_new";
			else
				GameInterface.passengerslist.(attributeName).img1 = "emptyface";
// <-- KK
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
	}
	GameInterface.passengerslist.ListSize = nListSize;
}

void ProcessFrame()
{
	string curName = GetCurrentNode();
	if(oldCurNode!=curName)
	{
		oldCurNode = curName;
		if(curName=="PASSENGERSLIST")
		{
			nCurScrollNum = -1;
		}
		Event("PressNone");
	}

	if(sti(GameInterface.passengerslist.current)!=nCurScrollNum)
	{
		DoScrollChange();
	}
}

void DoScrollChange()
{
	nCurScrollNum   = sti(GameInterface.passengerslist.current);

	ref chPsgn;
	int psgIdx = GetPassenger(_refCh,nCurScrollNum);
	if(psgIdx<0)
	{
		SetSumSkillData();
	}
	else
	{
		SetChrSkillData(GetCharacter(psgIdx));
	}
}

void ProcessCancelExit()
{
	ref mc = GetMainCharacter();

	if (CheckAttribute(mc, "colony_capture")) LAi_QuestDelay("ColonyCapture_ContinueDialog", 1.0);
	IDoExit(RC_INTERFACE_CAPTURE_COLONY_EXIT);
}

void ProcessAssignGov()
{
	ref refChar, rtmp, rIsland;
	ref mc = GetMainCharacter();
	aref artmp, arIslandReload;
	int chridx = -1;
	string chrid = "";
	object objtmp;

	if (!bMyColony) {
		if (hasGovernor == true && govidx != -1)		SetTownGovernor(colony_name, GetCharacter(govidx));
		if (hasFortCommandant == true && fcidx != -1)	SetTownFortCommander(colony_name, GetCharacter(fcidx));

		CaptureColony(colony_name, PERSONAL_NATION);
		DeleteAttribute(mc, "colony_capture");
	} else {
	// That's under developement, colony maintenance when it belongs to player
		/*ref refOfficer;
		if (hasGovernor == true && govidx != -1) {
			refMyChar = GetCharacter(govidx);
			refChar = GetTownGovernor(colony_name);
			refOfficer = GetCharacter(sti(refChar.OfficerIdx));
			makeref(rtmp, objtmp);
			CopyAttributes(rtmp, refOfficer);
		}*/
	}

	if (GameInterface.strings.ColonyName != FindTownName(colony_name)) {
		Towns[GetTownIndex(colony_name)].name = GameInterface.strings.ColonyName;
		Preprocessor_Delete(colony_name);
		Preprocessor_Save(colony_name, GameInterface.strings.ColonyName);
		rIsland = GetIslandByID(GetIslandIDFromTown(colony_name));
		makearef(arIslandReload, rIsland.reload);
		int num = GetAttributesNum(arIslandReload);
		int i = 0;
		for (i = 0; i < num; i++) {
			artmp = GetAttributeN(arIslandReload, i);
			if (CheckAttribute(artmp, "go") == true && CheckAttribute(GetTownFromID(colony_name), "boarding.l1") == true && artmp.go == Towns[GetTownIndex(colony_name)].boarding.l1) {
				artmp.label = TranslateString("", "#stown_name# Port");
				Preprocessor_Add("town_name", GameInterface.strings.ColonyName);
				artmp.label = PreprocessText(artmp.label);
				Preprocessor_Remove("town_name");
				break;
			}
		}
		if (hasFortCommandant == true) {
			refChar = GetTownFortCommander(colony_name, 0);
			//refChar.name = FindTownName(colony_name) + " " + XI_ConvertString("Fort");
			//refChar.old.name = refChar.name;
			for (i = 0; i < num; i++) {
				artmp = GetAttributeN(arIslandReload, i);
				if (CheckAttribute(artmp, "go") == true && CheckAttribute(artmp, "commander") == true && artmp.go == "BOARDING_Fort" && artmp.commander == refChar.id) {
					artmp.label = TranslateString("", "#stown_name# Fort");
					Preprocessor_Add("town_name", GameInterface.strings.ColonyName);
					artmp.label = PreprocessText(artmp.label);
					Preprocessor_Remove("town_name");
					break;
				}
			}
		}
		wdmSetIcon(colony_name, GameInterface.strings.ColonyName, -1);
	}

	Towns[GetTownIndex(colony_name)].tax = iTaxLevel;

	Event("exitCancel");
}

void PassengerDown()
{
}

void IDoExit(int exitCode)
{
	/* BEGIN MOD : Stone-D 01/08/2003 */
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("PassengerDown","PassengerDown");
	DelEventHandler("AssignGov","ProcessAssignGov");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	/* END MOD : Stone-D 01/08/2003 */

	// PB: Return your officers upon cancelling -->
	ref mc = GetMainCharacter();
	if (!bMyColony && CheckAttribute(mc, "colony_capture"))
	{
		if (govidx != -1)	AddPassenger(mc, GetCharacter(govidx), false);
		if (fcidx  != -1)	AddPassenger(mc, GetCharacter(fcidx) , false);
	}
	// PB: Return your officers upon cancelling <--

// KK -->
	DelEventHandler("PressGov", "ProcessGovSelect");
	DelEventHandler("PressFC", "ProcessFCSelect");
	DelEventHandler("PressNone", "ProcessNoneSelect");
	DelEventHandler("ColonyNameChange", "ProcessColonyNameChange");
	DelEventHandler("KB_End","WriteName"); // NK Keyboard
	DelEventHandler("KB_Update", "UpdateName");
	DelEventHandler("NodeCancel", "ProcessNodeCancel");
	DelEventHandler("IEvnt_MouseClick", "IProcMouseClick");
	DelEventHandler("ChangeTaxLeft", "DoTaxChangeLeft");
	DelEventHandler("ChangeTaxRight", "DoTaxChangeRight");

	interfaceResultCommand = exitCode;
	if (CheckAttribute(GetMainCharacter(), "ManageFromColoniesScreen")) {
		PostEvent("LaunchIAfterFrame", 1, "sl", "I_TRADEBOOK", 1);
		EndCancelInterface(false);
	} else {
		EndCancelInterface(true);
	}
// <-- KK
}

void SetSumSkillData()
{
	ref chref = _refCh;

	GameInterface.strings.skillLeadership = GetShipSkill(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing    = GetShipSkill(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing    = GetShipSkill(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy   = GetShipSkill(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons    = GetShipSkill(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling  = GetShipSkill(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair     = GetShipSkill(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence    = GetShipSkill(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce   = GetShipSkill(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak      = GetShipSkill(chref,SKILL_SNEAK);
}

void SetChrSkillData(ref chref)
{
	GameInterface.strings.skillLeadership = CalcCharacterSkill(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing    = CalcCharacterSkill(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing    = CalcCharacterSkill(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy   = CalcCharacterSkill(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons    = CalcCharacterSkill(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling  = CalcCharacterSkill(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair     = CalcCharacterSkill(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence    = CalcCharacterSkill(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce   = CalcCharacterSkill(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak      = CalcCharacterSkill(chref,SKILL_SNEAK);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
		case "PASSENGERSLIST":
			if(comName=="activate")
			{
				if (nCurChar == IC_GOVERNOR)
					XI_SetGovernor();
				else
					XI_SetFortCommandant();
			}
		break;
	}
}

/*void FillSelectedScroll()
{
	int i;
	string faceName;
	string attributeName;
	string PsgAttrName;
	int _curCharIdx;
	ref _refCurChar;
	aref pRef;

	nCurScrollNum = -1;
	GameInterface.passengerslist.current = 0;
	makearef(pRef,_refCh.Fellows.Passengers);
	int nListSize = GetNotCaptivePassengersQuantity(_refCh);
	nListSize = sti(GetPassengersQuantity(_refCh));
	GameInterface.passengerslist.NotUsed = 5;
	GameInterface.passengerslist.ListSize = nListSize;

	GameInterface.passengerslist.ImagesGroup.t0 = "EMPTYFACE";

	GameInterface.passengerslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.passengerslist.SpecTechniqueName = "iSpec1";

	//FillFaceList( "passengerslist.ImagesGroup", _refCh, 0 ); // officers
	//FillFaceList( "passengerslist.ImagesGroup", _refCh, 2 ); // passengers

	GameInterface.passengerslist.BadTex1 = 0;
	GameInterface.passengerslist.BadPic1 = "emptyface";

	int logined = 0;
	for(i=0; i<nListSize; i++)
	{
		attributeName = "pic" + (i+1);
		PsgAttrName = "id" + (i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		if(_curCharIdx!=-1)
		{
			if(!CheckAttribute(GetCharacter(_curCharIdx),"prisoned"))
			{
				attributeName = "pic" + (logined+1);
				PsgAttrName = "id" + (i+1);
				_curCharIdx = sti(pRef.(PsgAttrName));
				logined++;
				GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
				GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
				GameInterface.passengerslist.(attributeName).str1 = GetMySimpleName(GetCharacter(_curCharIdx));
			}
		}
		else
		{
			GameInterface.passengerslist.(attributeName).img1 = "emptyface";
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
	}
}*/

void ProcessColonyNameChange()
{
	if (bRMouseDown) return;
	SetNodeUsing("BOX", true);
	SetCurrentNode("BOX");
	KB_SetKeyboardMode(true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "BOX");
	KB_Prepare(GameInterface.strings.ColonyName);
}

void UpdateName()
{
	GameInterface.strings.ColonyName = KeyboardDisplayString;
}

void WriteName()
{
	if(KeyboardString != "")
	{
		GameInterface.strings.ColonyName = KeyboardString;
	}
	else
	{
		ProcessNodeCancel();
	}
	SetNodeUsing("BOX",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
}

void ProcessNodeCancel()
{
	GameInterface.strings.ColonyName = FindTownName(colony_name);
}

void ProcessGovSelect()
{
	if (hasGovernor) {
		if (govidx >= 0) SetChrSkillData(GetCharacter(govidx));
		//SetPictureBlind("GovFace", true, minBlindColor, maxBlindColor);
		SetCurrentNode("RGOV");
		nCurChar = IC_GOVERNOR;
	}
}

void ProcessFCSelect()
{
	if (hasFortCommandant) {
		if (fcidx >= 0) SetChrSkillData(GetCharacter(fcidx));
		//SetPictureBlind("FCFace", true, minBlindColor, maxBlindColor);
		SetCurrentNode("RFC");
		nCurChar = IC_FC;
	}
}

void ProcessNoneSelect()
{
	//if (hasGovernor) SetPictureBlind("GovFace", false, 0, 0);
	//if (hasFortCommandant) SetPictureBlind("FCFace", false, 0, 0);
}

void XI_SetGovernor()
{
	ref chPsgn;
	nCurScrollNum = sti(GameInterface.passengerslist.current);
	if (govidx != -1) {
		chPsgn = GetCharacter(govidx);
		AddPassenger(GetMainCharacter(), chPsgn, false);
		govidx = -1;
	}
	govidx = GetPassenger(_refCh, nCurScrollNum);
	if (govidx != -1) {
		chPsgn = GetCharacter(govidx);
		RemovePassenger(GetMainCharacter(), chPsgn);
		RefillScroll();
		GameInterface.RGOV.pic1.str1 = "#" + GetMySimpleName(chPsgn);
		GameInterface.RGOV.pic1.img1 = GetFacePicName(chPsgn);
		GameInterface.RGOV.pic1.tex1 = FindFaceGroupNum("RGOV.ImagesGroup", "FACE128_" + chPsgn.FaceID);
		SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "RGOV");
		SetCurrentNode("PASSENGERSLIST");
		if (hasFortCommandant == true && fcidx != -1)	SetSelectable("ASSIGNGOV_BUTTON", true);
		if (hasFortCommandant == false)					SetSelectable("ASSIGNGOV_BUTTON", true);
		if (IsCompanion(chPsgn))						SetSelectable("ASSIGNGOV_BUTTON", false); // PB: Cannot assign if character is companion - Check for governor
		if (IsCompanion(GetCharacter(fcidx)))			SetSelectable("ASSIGNGOV_BUTTON", false); // PB: Cannot assign if character is companion - Check for fort commander
	}
}

void XI_SetFortCommandant()
{
	ref chPsgn;
	nCurScrollNum = sti(GameInterface.passengerslist.current);
	if (fcidx != -1) {
		chPsgn = GetCharacter(fcidx);
		AddPassenger(GetMainCharacter(), chPsgn, false);
		fcidx = -1;
	}
	fcidx = GetPassenger(_refCh, nCurScrollNum);
	if (fcidx != -1) {
		chPsgn = GetCharacter(fcidx);
		RemovePassenger(GetMainCharacter(), chPsgn);
		RefillScroll();
		GameInterface.RFC.pic1.str1 = "#" + GetMySimpleName(chPsgn);
		GameInterface.RFC.pic1.img1 = GetFacePicName(chPsgn);
		GameInterface.RFC.pic1.tex1 = FindFaceGroupNum("RFC.ImagesGroup", "FACE128_" + chPsgn.FaceID);
		SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "RFC");
		SetCurrentNode("PASSENGERSLIST");
		if (hasGovernor == true && govidx != -1)		SetSelectable("ASSIGNGOV_BUTTON", true);
		if (hasGovernor == false)						SetSelectable("ASSIGNGOV_BUTTON", true);
		if (IsCompanion(chPsgn))						SetSelectable("ASSIGNGOV_BUTTON", false); // PB: Cannot assign if character is companion - Check for fort commander
		if (IsCompanion(GetCharacter(govidx)))			SetSelectable("ASSIGNGOV_BUTTON", false); // PB: Cannot assign if character is companion - Check for governor
	}
}

void RefillScroll()
{
	ref charRef;
	int charQuantity=0;
	string attributeName;
	int i;

	charQuantity = sti(GameInterface.passengerslist.ListSize);
	for (i = 0; i < charQuantity; i++) {
		attributeName = "passengerslist.pic" + (i+1);
		DeleteAttribute(&GameInterface, attributeName);
	}
	charQuantity = 0;
	i = 0;
	int psgIdx = GetNotCaptivePassenger(_refCh, i);
	while (psgIdx != -1) {
		if (psgIdx != govidx && psgIdx != fcidx) {
			charRef = GetCharacter(psgIdx);
			attributeName = "pic" + (charQuantity+1);
			GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(charRef);
			GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+charRef.FaceId);
			GameInterface.passengerslist.(attributeName).str1 = "#" + GetMySimpleName(charRef);
			charQuantity++;
		}
		i++;
		psgIdx = GetNotCaptivePassenger(_refCh, i);
	}
	GameInterface.passengerslist.ListSize = charQuantity;
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_REFRESH_SCROLL,"PASSENGERSLIST");
}

string XI_GetTaxationLevelName()
{
	string ret = "";
	switch (iTaxLevel) {
		case TAX_NONE:    ret = TranslateString("", "tax_none");    break;
		case TAX_LOW:     ret = TranslateString("", "tax_low");     break;
		case TAX_NORMAL:  ret = TranslateString("", "tax_normal");  break;
		case TAX_HIGH:    ret = TranslateString("", "tax_high");    break;
		case TAX_PLUNDER: ret = TranslateString("", "tax_plunder"); break;
	}
	return ret;
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if (nodName == "TAX_CHANGER") {
		if (btnCode == 0) Event("ChangeTaxLeft");
		if (btnCode == 1) Event("ChangeTaxRight");
	}
}

void DoTaxChangeLeft()
{
	if (iTaxLevel > TAX_NONE) {
		iTaxLevel--;
		GameInterface.strings.TaxationLevel = XI_GetTaxationLevelName();
	}
}

void DoTaxChangeRight()
{
	if (iTaxLevel < TAX_PLUNDER) {
		iTaxLevel++;
		GameInterface.strings.TaxationLevel = XI_GetTaxationLevelName();
	}
}
