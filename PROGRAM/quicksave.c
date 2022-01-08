

// dchaley -->

void QS_CreateScrshot()
{
	object scrshoter;
	CreateEntity(&scrshoter,"scrshoter");
	scrshoter.SavePath = DEFAULT_PATH;
	if(bSeaActive && !bAbordageStarted) { LayerAddObject(SEA_REALIZE,&scrshoter,-1); }
	else { LayerAddObject(REALIZE, &scrshoter,-1); }
}

void QS_DoPresave()
{
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,"quicksave"); // NK delete old qsave to fix order problems. 05-04-18
	int pic1, pic2, pic3, pic4;
	string timeStr;
	string tmpStr;
	
	pic1 = GetFacePicture(GetOfficersIndex(GetMainCharacter(),0)); // NK
	pic2 = GetFacePicture(GetOfficersIndex(GetMainCharacter(),1)); // NK
	pic3 = GetFacePicture(GetOfficersIndex(GetMainCharacter(),2)); // NK
	pic4 = GetFacePicture(GetOfficersIndex(GetMainCharacter(),3)); // NK


	tmpStr = "";
	timeStr = "quicksave";
	SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, "quicksave", &timeStr);
	SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, "", &tmpStr);
	
	
	EnableString("SaveName");
	GameInterface.strings.SaveName = timeStr + " " + tmpStr;

	
	GameInterface.pictures.face1.pic = GetFacePictureName(sti(pic1));
	GameInterface.pictures.face1.tex = GetFaceGroupNameFromFace(sti(pic1)); // NK

	GameInterface.pictures.face2.pic = GetFacePictureName(sti(pic2));
	GameInterface.pictures.face2.tex = GetFaceGroupNameFromFace(sti(pic2)); // NK

	GameInterface.pictures.face3.pic = GetFacePictureName(sti(pic3));
	GameInterface.pictures.face3.tex = GetFaceGroupNameFromFace(sti(pic3)); // NK

	GameInterface.pictures.face4.pic = GetFacePictureName(sti(pic4));
	GameInterface.pictures.face4.tex = GetFaceGroupNameFromFace(sti(pic4)); // NK
}

extern void FindScrshotClass(); //save_load.c

void ProcessQuicksave()
{
	DelEventHandler("makescrshot","ProcessQuicksave");
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	Log_SetStringToLog(TranslateString("","Quicksaving..."));

	UnloadSegment("INTERFACE/save_load.c");
	LoadSegment("INTERFACE/save_load.c");

	QS_CreateScrshot();
	FindScrshotClass();
	//FillScroll();

	// Some init stuff...
	QS_DoPresave();
	
	string curSave = "quicksave";

	ref PChar = GetMainCharacter();
	string locLabel = PChar.location;
	
	int locidx = FindLocation(PChar.location);
	
// KK -->
	if( locidx>=0 && CheckAttribute(&Locations[locidx],"id.label") ) { 
		if (CheckAttribute(Locations[locidx], "townsack")) {
			Preprocessor_Add("town_name", FindTownName(Locations[locidx].townsack));
			Preprocessor_Add("island_name", FindIslandName(GetIslandIDFromTown(Locations[locidx].townsack)));
		}
		locLabel = PreprocessText(Locations[locidx].id.label);
		Preprocessor_Remove("town_name");
		Preprocessor_Remove("island_name");
	} else {
		locLabel = "Open Sea";
	}
// <-- KK
	
	string sSaveDescriber = locLabel + "@" +
	GetFacePicture(GetOfficersIndex(PChar,0)) + "@" +
	GetFacePicture(GetOfficersIndex(PChar,1)) + "@" +
	GetFacePicture(GetOfficersIndex(PChar,2)) + "@" +
	GetFacePicture(GetOfficersIndex(PChar,3)) + "@" +
	GetStringTime(GetTime()) + "  " + 
	GetStringDate( GetDataYear(), GetDataMonth(), GetDataDay() ) + "@" + IS_SGV;

	qsLocationStr = locLabel;
	qsPic1 = GetFacePicture(GetOfficersIndex(PChar,0));
	qsPic2 = GetFacePicture(GetOfficersIndex(PChar,1));
	qsPic3 = GetFacePicture(GetOfficersIndex(PChar,2));
	qsPic4 = GetFacePicture(GetOfficersIndex(PChar,3));
	qsTimeStr = GetStringTime(GetTime()) + "  " + GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay());
	qsSgvStr = IS_SGV;

	SetEventHandler("evntSave","SaveGame",1);

	if(!CheckAttribute(&GameInterface, "SavePath")) GameInterface.SavePath = DEFAULT_PATH;

	if( GetTargetPlatform()=="pc" ) {
		PostEvent("evntSave",0,"ss", GameInterface.SavePath + "\\" + curSave, sSaveDescriber);
	} else {
		PostEvent("evntSave",0,"ss", curSave, sSaveDescriber);
		Event("DoInfoShower","sl","save game",true);
	}

	
	DeleteEntitiesByType("scrshoter");

	UnloadSegment("INTERFACE/save_load.c");

	postevent("FindQuicksave_event", 1000) // added by MAXIMUS for correct viewing quicksaving status
//	Log_SetStringToLog("...done!");	
	//LanguageCloseFile(tmpLangFileID);
}

// added by MAXIMUS for correct viewing quicksaving status -->
#event_handler("FindQuicksave_event", "FindQuicksave")
void FindQuicksave()
{
    object LocDirectory;
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	DeleteAttribute(&LocDirectory, "");

	LocDirectory.dir = DEFAULT_PATH;
	LocDirectory.mask = "*";
	CreateEntity(&LocDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocDirectory);
	
	aref arList;
	makearef(arList, LocDirectory.filelist);

	for(int i = 0; i < GetAttributesNum(arList); i++)
	{
		aref arCur = GetAttributeN(arList, i);
		string fname = GetAttributeValue(arCur);
		if(fname != "quicksave") continue;
		string fullname = LocDirectory.dir+"\\"+fname;
		if(fullname == LocDirectory.dir+"\\quicksave") Log_SetStringToLog(TranslateString("","...done!"));
	    else Log_SetStringToLog(TranslateString("","...error quicksaving!"));
	}
}
// added by MAXIMUS for correct viewing quicksaving status <--

void ProcessQuickload()
{
	// this is for the most part borrowed from save_load.c
	string sCurSave = "quicksave";

// added by MAXIMUS for excluding error with loading nonexistent quicksave -->
    object LocDirectory;
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	DeleteAttribute(&LocDirectory, "");

	LocDirectory.dir = DEFAULT_PATH;
	LocDirectory.mask = "*";
	CreateEntity(&LocDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocDirectory);
	aref arList;
	makearef(arList, LocDirectory.filelist);
	for(int i = 0; i < GetAttributesNum(arList); i++)
	{
		aref arCur = GetAttributeN(arList, i);
		string fname = GetAttributeValue(arCur);
		if(fname=="quicksave")
		{
		      ResetSound();

		      SetEventHandler("evntLoad","LoadGame",1);
	
		      if(GetTargetPlatform()=="pc") { PostEvent("evntLoad",0,"s", LocDirectory.dir + "\\" + sCurSave); }
		      else { PostEvent("evntLoad",0,"s",sCurSave); }
		      Event("evntPreLoad");
		}
		else Log_SetStringToLog(TranslateString("","You haven't the file 'quicksave'!"));
		//LanguageCloseFile(tmpLangFileID);
	}
// added by MAXIMUS for excluding error with loading nonexistent quicksave <--
}
// dchaley <--


