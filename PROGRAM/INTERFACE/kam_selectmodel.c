int nCurScroll;
ref PChar;
ref XChar;
int tempCurrentModel;

bool ExitToCharInterface;	// added by KAM after build 11

string ReturnedModelID;
string ReturnedModelDesc;
string ReturnedModelAni;
string ReturnedModelSex;
float ReturnedModelHeight;


// ***********************************************************************************************************************************************************************************************************************************************************************************
//
// if you want to add new models to the select model interface, you need to add a case to the functions GetModelIDFromListNumber.
// YOU ALSO NEED TO INCREASE max_models!!!!!!!!!!!!!!!!
//
// ***********************************************************************************************************************************************************************************************************************************************************************************


int models_qty = 0;
int availmodels[MAX_MODELS];


string GetModelIDFromListNumber(int inum)
{
	inum--;
	bool valid = true;
	if(valid) inum = availmodels[inum];

	ReturnedModelID = Models[inum].model;
	ReturnedModelDesc = Models[inum].description;
	string cutStr = strcut(ReturnedModelID,strlen(ReturnedModelID)-3,strlen(ReturnedModelID)-1);//MAXIMUS: for AOP and armored models -->
	string ReturnedID = ReturnedModelID;
	if(cutStr=="_A1" || cutStr=="_A2" || cutStr=="_A3" || cutStr=="_A4") ReturnedID = strcut(ReturnedModelID, 0, strlen(ReturnedModelID)-4);
	ReturnedModelAni = Models[GetModelIndex(ReturnedID)].ani;//MAXIMUS: for AOP and armored models <--
	ReturnedModelSex = Models[inum].sex;
	ReturnedModelHeight = stf(Models[inum].height);

	return ReturnedModelID;
}


// ***********************************************************************************************************************************************************************************************************************************************************************************



void InitInterface(string iniName)
{
	int i,cn;
	string tempstring;
	string oldmodel;

	PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "DisableModelSelect")) return; // NK disable model select in tut 05-07-14

// added by KAM after build 11 -->
	if (CheckAttribute(PChar, "ChangeOutfitFromCharacterScreen"))
		ExitToCharInterface = true;
	else
		ExitToCharInterface = false;
// <-- added by KAM after build 11

	i = 0; // NK -- just in case.
	if(CheckAttribute(PChar, "kammodelselecttempattrib")) i = sti(PChar.kammodelselecttempattrib); // NK
	XChar = GetCharacter(i);
	// NK -->
	models_qty = 0;
	for(i = 0; i < OFFICER_MAX; i++) // set bought the models of pchar and officers
	{
		cn = GetOfficersIndex(PChar, "" + i);
		if(cn != -1)
		{
			oldmodel = Characters[cn].model;
			if(!DEBUG) PChar.clothes.(oldmodel) = true;
		}
	}
	//find what models are available by referencing bought clothes (pchar.clothes.*) with the models array
	for(i = 0; i <= MODEL_HIGH; i++)
	{
		//if(sti(Models[i].assigned))
		//{
			if(CheckAttribute(PChar,"clothes."+Models[i].model) || DEBUG)
			{
				availmodels[models_qty] = i;
				models_qty++;
				//trace(Models[i].model);
			}
		//}
	}
	//trace("total qty models: " + models_qty);
	// NK <--

	tempCurrentModel = 1;
	for (i=1; i<=models_qty; i++)
	{
		tempstring = GetModelIDFromListNumber(i);
		//trace("Current model slot " + tempstring);
		if (XChar.model == tempstring)
		{
			tempCurrentModel = i-1;
			//trace("matches, setting idx to " + (i-1));
		}
	}

	GameInterface.title = "titleKAMSelectCharacter";

	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"IslandName","",FONT_NORMAL,COLOR_NORMAL,320,193,SCRIPT_ALIGN_CENTER,1.0);

	SetSelectable("EXIT_BUTTON",true);
	KAM_UpdateDisplay();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.islandslist.current))
	{
		nCurScroll = sti(GameInterface.islandslist.current);
		KAM_UpdateDisplay();
	}
}

void KAM_UpdateDisplay()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	GameInterface.strings.IslandName = XI_ConvertString("Model") + " - " + GetModelIDFromListNumber(nCurScroll+1);
	SetFormatedText("TEXTWINDOW2","(" + LanguageConvertString(tmpLangFileID,"Choosing outfit for") + " " + XChar.name + " " + XChar.lastname + ")");		// changed after release of v11 by KAM
	tmpLangFileID = LanguageOpenFile("models_description.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,ReturnedModelDesc));
	LanguageCloseFile(tmpLangFileID);
}


void KAM_SetModel()
{
	SetModel(XChar, GetModelIDFromListNumber(nCurScroll+1), ReturnedModelAni, ReturnedModelSex, ReturnedModelHeight, true); // NK 4-30
	InterfaceStates.InstantExit = true;
	ProcessCancelExit();
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if (nodName == "USETHISCHARACTER_BUTTON")
	{
		if(comName=="activate" || comName=="click")
		{
			KAM_SetModel();
		}
	}
	if(nodName=="ISLANDSLIST" && comName=="activate") SetCurrentNode("USETHISCHARACTER_BUTTON");//MAXIMUS
}

void FillScroll()
{
	string attribname1;
	string attribname2;
	int loopnum;

	GameInterface.islandslist.NotUsed = 6;		// added after release of v11 by KAM

	//trace("fs qty: " + models_qty);
	for (loopnum=1; loopnum<=models_qty; loopnum++) // NK
	{
		attribname1 = "t" + loopnum;
		attribname2 = "pic" + loopnum;
		//trace("attr 1,2: " + attribname1 + "," + attribname2 + "; faceid " + GetCharacterFaceID(GetModelIDFromListNumber(loopnum)) + ", tex1: " + (loopnum-1));
		GameInterface.islandslist.ImagesGroup.(attribname1) = "FACE128_" + GetCharacterFaceID(GetModelIDFromListNumber(loopnum));
		GameInterface.islandslist.(attribname2).img1 = "face";
		GameInterface.islandslist.(attribname2).tex1 = loopnum - 1;
	}

// KK -->
	if (ExitToCharInterface)
	GameInterface.islandslist.current = tempCurrentModel;
	else
		GameInterface.islandslist.current = tempCurrentModel - 1;
// <-- KK
	GameInterface.islandslist.ListSize = models_qty;
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_KAM_SELECTMODEL_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");

    interfaceResultCommand = exitCode;

// MAXIMUS interface MOD -->
// KK -->
	if (ExitToCharInterface) {
    PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
    EndCancelInterface(false);
	} else {
		EndCancelInterface(true);
	}
// <-- KK
}
