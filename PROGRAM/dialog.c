#include "dialog_func.c"


#define EVENT_DIALOG_START		"evntDialogStart"
#define EVENT_DIALOG_EXIT		"evntDialogExit"

#event_handler("dlgReady", "StartDialogWithMainCharacter");
#event_handler("EmergencyDialogExit","DialogExit");

extern void ProcessDialogEvent();

bool dialogDisable = false;
object	Dialog;
ref		CharacterRef;
int		DialogFilesLoaded = -1; //Levis
bool	dialogRun = false;
bool	dialogSelf = false;
bool	FightDisable; // PB
bool	DIALOG_DEBUG = false; //Levis

//Инициализация
void DialogsInit()
{
	Quest_Init();				//Инициализация начального состояния слухов и информации об NPC ------- Ренат
}

//Начать диалог
bool DialogMain(ref Character)
{
	//Add the debug dialog files for everyone
	Character.Dialog.Filename.Debug = "Debug.c";
	if(CheckAttribute(Character, "condition") && Character.condition=="reload") return false;//MAXIMUS: prevents from dialogs start during reload -->
	if(CheckAttribute(GetMainCharacter(), "condition") && Characters[GetMainCharacterIndex()].condition=="reload") return false;//MAXIMUS: prevents from dialogs start during reload <--
	//Если диалог запущен, выходим
	if(dialogRun != false) return false;
	//Ссылка на главного персонажа
	ref mainChr = GetMainCharacter();
	//Если когото не заведено, выходим
	if(!IsEntity(mainChr)) return false;
	if(!IsEntity(Character)) return false;
	if(LAi_IsDead(mainChr)) return false;
	if(LAi_IsDead(Character)) return false;
	//Проверим на существование текущего нода
	if(!CheckAttribute(Character, "Dialog.CurrentNode"))
	{
		Trace("Dialog: Character <" + Character.id + "> can't have field Dialog.CurrentNode, exit from dialog!")
		return false;
	}
	//Если персонаж не готов говорить выходим
	if(!LAi_Character_CanDialog(mainChr, Character)) return false;
	//Если персонаж не готов говорить выходим
	if(!LAi_Character_CanDialog(Character, mainChr)) return false;
// added by MAXIMUS -->
	if(CheckAttribute(Character,"corpse"))//MAXIMUS: was [if(Character.Dialog.Filename == "corpse_dialog.c")]
	{//MAXIMUS: dialog with Maltese-corpse will be started by looting only -->
		bool bMaltese = false;
		if(CheckAttribute(Character,"lootDialog")) { bMaltese = true; }
		//Levis: Removed to make CORPSEMODE = 2 Working
		/*if(!bMaltese)
		{
			Log_SetStringToLog(TranslateString("","Gamlet"));
			return false;
		}*/
	}//MAXIMUS: dialog with Maltese-corpse will be started by looting only <--
// added by MAXIMUS <--
	//Сохраняем ссыклу на того с кем говорим
	CharacterRef = Character;
	LoadAllDialogFiles(Character); //Added by Levis for better dialogs
	// Попытка загрузить текст дилога
	/*if( !LoadDialogFiles(Character.Dialog.Filename) ) {
		// имеем ошибочный диалог
		if( !LoadDialogFiles("error_dialog.c") ) {
			return false;
		}
	}*/ //Removed by Levis
	//Можем начинать диалог
	dialogRun = true;
	dialogSelf = false;
	LAi_Character_StartDialog(mainChr, Character);
	LAi_Character_StartDialog(Character, mainChr);
	if(CheckAttribute(Character,"corpse")==true) mainChr.IsInDialog = 1;		// LDH - To prevent corpses from disappearing while talking to them
// PB: No fights during dialog -->
	FightDisable = false;
	if(!CheckAttribute( &Locations[FindLocation(mainChr.location)],"noFight" )) {LAi_LocationFightDisable(&Locations[FindLocation(mainChr.location)], true);}
	// if LocationFightDisable is not on, set LocationFightDisable on
	else {FightDisable = true;}
	// if LocationFightDisable is already on, set FightDisable true so that LocationFightDisable will remain on after the dialog is closed
// PB: No fights during dialog <--

// ccc building kit, keeps first person view for building dialogs
	if(Character.chr_ai.type != LAI_TYPE_BUILDING) SendMessage(mainChr, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 1);
	SendMessage(Character, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 1);
	//Запускаем диалог
	//Trace("Dialog: dialog path for character <" + Character.id + "> = " + FullDialogPath);
	Dialog.CurrentNode = CharacterRef.Dialog.CurrentNode;
	startDialogMainCounter = 0;
	SetEventHandler("frame", "StartDialogMain", 1);
//	SetTimeScale(0.0);
	return true;
}

int startDialogMainCounter = 0;

void StartDialogMain()
{
	float size;

	if(CheckAttribute(CharacterRef, "condition") && CharacterRef.condition=="reload") return;//MAXIMUS: prevents from dialogs start during reload -[here too (to be sure)]->
	if(CheckAttribute(GetMainCharacter(), "condition") && Characters[GetMainCharacterIndex()].condition=="reload") return;//MAXIMUS: prevents from dialogs start during reload <--

	startDialogMainCounter++;
	if(startDialogMainCounter < 3) return;

	if (DIALOG_CAMERA > 0.0) {
		size = 3.0 + DIALOG_CAMERA;
		loadedLocation = &Locations[FindLoadedLocation()];
		if(HasSubStr(loadedLocation.id,"Tutorial_Deck") || HasSubStr(loadedLocation.id,"Seadog")) size = 0.8+DIALOG_CAMERA;
		if(CheckAttribute(loadedLocation,"models.back") || HasSubStr(loadedLocation.id,"House")) size = 0.5+DIALOG_CAMERA;
		if(HasSubStr(loadedLocation.id,"Cabin")) size = 0.3 + DIALOG_CAMERA;
		if(HasSubStr(loadedLocation.id,"Small")) size = 0.2 + DIALOG_CAMERA;
		if(CheckAttribute(CharacterRef,"chr_ai.type") && CharacterRef.chr_ai.type==LAI_TYPE_LAY) size = 0.2+DIALOG_CAMERA;
		DialogCamera(GetMainCharacter(), size, true);
	}
	if (DIALOG_CAMERA < 0.0) {
		DialogCamera(GetMainCharacter(), 0.0, true);
	}

	DelEventHandler("frame", "StartDialogMain");

// KK -->
	if (bNewInterface)
		CreateEntity(&Dialog, "dialg2");
	else
		CreateEntity(&Dialog, "dialog");
// KK <--

	Log_SetActiveAction("Nothing");//MAXIMUS
	LogsVisible(false); // KK
	Dialog.headModel = CharacterRef.headModel; // KK
	if(FindFile("resource\models\Heads", "*.gm", CharacterRef.headModel + ".gm") == "")
	{
		if(CharacterRef.headModel!="h_"+CharacterRef.Model) CharacterRef.headModel = "h_"+CharacterRef.Model;//MAXIMUS: prevents some errors (I'm wondering: sometimes we have models-names, like 23iu432523h)
//		else Dialog.headModel = "h_Skel4";//MAXIMUS: temporary (for excluding errors). Maybe someone can make heads???
	}
	Dialog.gender = CharacterRef.sex;

	DeleteAttribute(&Dialog,"Links");
	DeleteAttribute(&Dialog,"Text");

// KK -->
	SetEventHandler("PlayDialogGreeting", "DialogPlayGreeting", 0);
	if (CheckAttribute(CharacterRef, "greeting") == true && CharacterRef.greeting != "") {
		PostEvent("PlayDialogGreeting", 100.0);
	}
// <-- KK

	// PB: Overwrite Name -->
	string name = CharacterRef.name;
	string lastname = CharacterRef.lastname;
	CharacterRef.name = GetMyFormalName(CharacterRef); // PB: Fill in missing first names
	CharacterRef.lastname = "";
	// PB: Overwrite Name <--

	object persRef = GetCharacterModel(Characters[GetMainCharacterIndex()]);
	SendMessage(&Dialog, "lii", 0, &Characters[GetMainCharacterIndex()], &persRef);

	object charRef = GetCharacterModel(Characters[makeint(CharacterRef.index)]);
	SendMessage(&Dialog, "lii", 1, &Characters[makeint(CharacterRef.index)], &charRef);

	// PB: Restore Name -->
	CharacterRef.name = name;
	CharacterRef.lastname = lastname;
	// PB: Restore Name <--

	LayerCreate("realize",1);
	LayerSetRealize("realize",1);
	LayerAddObject("realize",Dialog,-256);
	Set_inDialog_Attributes();
//	ProcessDialogText(); // a simple virtual sailor

	// NK 05-07-19 fix for corpses, where segment unloaded before following event handlers can execute.
	if (CheckAttribute(CharacterRef, "dlgover")) {
		DeleteAttribute(&CharacterRef, "dlgover");
	} else {
		SetEventHandler("DialogEvent","ProcessDialogText",0);
	//SetEventHandler("DialogCancel","DialogExit",0);

		Event("DialogEvent");
		Event(EVENT_DIALOG_START,"");
	} // FYI this will hide the BLI. NK 05-07-19
	ResetTimeToNormal();//MAXIMUS
}

// KK -->
#event_handler("PlayDialogGreeting", "DialogPlayGreeting");
void DialogPlayGreeting()
{
	DelEventHandler("PlayDialogGreeting", "DialogPlayGreeting");
	Dialog.greeting = "Gr_none";		// this causes a fixed length dialog animation with no sound
	PlayGreeting(CharacterRef);			// play the greeting explicitly rather than letting the dialog engine do it - 19Mar09
}
// <-- KK

// a simple virtual sailor --->
// at the begining of the dialog, use directly Dialog.Mood = whatever you want (smile, angry, afraid.)
// If you want to change head expression again during the same dialog, use the Change_Mood(whatever) command
// Whatever being normal, smile, angry or afraid.
void Change_Mood(ref mood)
{
		Dialog.Mood = mood;
		Dialog.headModel = CharacterRef.headModel;
		Trace("Head expression was asked to be reseted for " + mood + " expression.");
}
// <--- a simple virtual sailor

//Начать диалог с самим собой
void SelfDialog(ref Character)
{
	//Если диалог запущен, выходим
	if(dialogRun != false) return; //MAXIMUS: void function return value (was "return false")
	//Если когото не заведено, выходим
	if(!IsEntity(Character) && !CheckAttribute(Character,"SailHo") && !CheckAttribute(Character,"DirectSail.messenger")) return false;//changed by MAXIMUS: for new "Sail Ho" and DirectSail-Mod
	//Проверим на существование текущего нода
	if(!CheckAttribute(Character, "Dialog.CurrentNode"))
	{
		Trace("SelfDialog: Character <" + Character.id + "> can't have field Dialog.CurrentNode, exit from dialog!")
		return false;
	}
	//Сохраняем ссылку на того с кем говорим
	CharacterRef = Character;
	LoadAllDialogFiles(Character); //Added by Levis for better dialogs
 	// Попытка загрузить текст дилога
	/*if(!LoadDialogFiles(Character.Dialog.Filename))
	{
		// имеем ошибочный диалог
		if(!LoadDialogFiles("error_dialog.c")) return; //MAXIMUS: void function return value (was "return false")
	}*/ //Removed by Levis
	//Если персонаж не готов говорить выходим
	LAi_Character_CanDialog(Character, Character);
	//Можем начинать диалог
	dialogRun = true;
	dialogSelf = true;
	SendMessage(Character, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 1);
	//Запускаем диалог
	Dialog.CurrentNode = CharacterRef.Dialog.CurrentNode;
	//Trace("SelfDialog: dialog path for self character <" + Character.id + "> = " + FullDialogPath);
// KK -->
	if (bNewInterface)
		CreateEntity(&Dialog, "dialg2");
	else
		CreateEntity(&Dialog, "dialog");
// <-- KK
	Log_SetActiveAction("Nothing");//MAXIMUS
	LogsVisible(false); // KK
	Dialog.headModel = CharacterRef.headModel; // KK
	if (FindFile("resource\models\Heads", "*.gm", CharacterRef.headModel + ".gm") == "")
	{
		if(CharacterRef.headModel!="h_"+CharacterRef.Model) CharacterRef.headModel = "h_"+CharacterRef.Model;//MAXIMUS: prevents some errors (I'm wondering: sometimes we have models-names, like 23iu432523h)
//		else Dialog.headModel = "h_Skel4";//MAXIMUS: temporary (for excluding errors). Maybe someone can make heads???
	}
	Dialog.gender = Character.sex;

	// PB: Overwrite Name -->
	string name = CharacterRef.name;
	string lastname = CharacterRef.lastname;
	CharacterRef.name = GetMyFormalName(CharacterRef); // PB: Fill in missing first names
	CharacterRef.lastname = "";
	// PB: Overwrite Name <--

	object persRef = GetCharacterModel(Characters[GetMainCharacterIndex()]);
	SendMessage(&Dialog, "lii", 0, Character, &persRef);
	SendMessage(&Dialog, "lii", 1, Character, &persRef);

	// PB: Restore Name -->
	CharacterRef.name = name;
	CharacterRef.lastname = lastname;
	// PB: Restore Name <--

//changed by MAXIMUS: for new "Sail Ho" and DirectSail-Mod -->
	if(!bSeaActive)
	{
		LayerCreate("realize",1);
		LayerSetRealize("realize",1);
	}
	if(bSeaActive && !IsEntity(&worldMap)) {
		LogsVisible(false); // KK
		LayerAddObject(SEA_EXECUTE, Dialog, -256);
		LayerAddObject(SEA_REALIZE, Dialog, -256);
	} else {
		LayerAddObject("realize",Dialog,-256);
	}
//changed by MAXIMUS: for new "Sail Ho" and DirectSail-Mod <--
	Set_inDialog_Attributes();
	//ProcessDialogEvent(); // a simple virtual sailor Jan 09 //Removed by Levis

	SetEventHandler("DialogEvent","ProcessDialogText",0);
	//SetEventHandler("DialogCancel","DialogExit",0);

	Event("DialogEvent"); //Added by Levis
	Event(EVENT_DIALOG_START,"");
	ResetTimeToNormal();//MAXIMUS
}

//Закончить диалог
void DialogExit()
{
	//Check if all dialog files are closed
	If(DialogFilesLoaded > -1)
	{
		UnloadDialogFileByIndex(DialogFilesLoaded);
	}
	//Ссылка на главного персонажа
	ref mainChr = GetMainCharacter(); // KK
	//Если диалога уже не ведётся, выйдем
	if(dialogRun == false) return;
	//DelEventHandler("PlayDialogGreeting", "DialogPlayGreeting"); // KK
	DelEventHandler("DialogEvent","ProcessDialogText"); // KK
	//Освобождаем ресурсы
	DeleteClass(&Dialog);
	/*if(FullDialogPath!="") UnloadSegment(FullDialogPath);
	if(PathDlgLngExtn!="") UnloadSegment(PathDlgLngExtn);*/ //Removed by Levis
	if(dialogSelf == false)
	{
		//Отметим, что персонажи освободились от диалога
		LAi_Character_EndDialog(mainChr, CharacterRef);
		LAi_Character_EndDialog(CharacterRef, mainChr);
		SendMessage(mainChr, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		SendMessage(CharacterRef, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		DeleteAttribute(mainChr, "IsInDialog");	// LDH - Used for problems with corpses disappearing.
	}else{
		LAi_Character_EndDialog(CharacterRef, CharacterRef);
		SendMessage(CharacterRef, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
	}
	DeleteAttribute(GetMainCharacter(), "forcedlg"); // NK 05-07-13 to allow for dlg in fight mode
	dialogRun = false;
	dialogSelf = false; //Added by Levis to fix exit
	//Сообщим об окончании диалога
	PostEvent(EVENT_DIALOG_EXIT, 1, "l", sti(CharacterRef.index));
	// PB: No fights during dialog -->
	if(FightDisable == false) {LAi_LocationFightDisable(&Locations[FindLocation(mainChr.location)], false);}
	// if FightDisable has not been set true, set LocationFightDisable off again (resets original LocationFightDisable setting from before the dialog)
	// PB: No fights during dialog <--
	locCameraFollow(); //a simple virtual sailor
	ClearScreenShoter();//MAXIMUS: used for QuickSave
	LogsVisible(true); // KK
	CheckReloadAction(mainChr, "");
	if (CheckAttribute(mainChr, "BoxName.update")) DeleteAttribute(mainChr, "BoxName.update");
	if (CheckAttribute(mainChr, "activeItem.update")) DeleteAttribute(mainChr, "activeItem.update");
	CheckCharacterAction();
}

//Это событие приходит от Player
void StartDialogWithMainCharacter()
{
	// NK disable this to allow dlg in boarding 05-07-12 - if(LAi_IsBoardingProcess()) return;
	if(dialogDisable) return;
	//С кем хотим говорить
	int person = GetEventData();
	//Сими с собой не беседуем
	if(person == GetMainCharacterIndex()) return;
	//С непрогруженными персонажами не беседуем
	if(!IsEntity(&Characters[person])) return;
	//Начинаем диалог
	DialogMain(&Characters[person]);
	//Trace("Dialog: start dialog " + person + " whith main character");
}

// Levis Improved Dialog system -->
// Main Functions
void LoadAllDialogFiles(ref Character)
{
	//First make sure no old dialog files are present
	DeleteAttribute(CharacterRef,"LoadedDialog");
	if(DIALOG_DEBUG) Trace("Dialog: Load all files for Character: " + Character.ID);
	//Here we store the dialog files in another place so if they get changed it won't affect the dialog flow untill the dialog is closed.
	int i, dn;
	aref SubDialog, MainDialog;
	makearef(MainDialog,Character.Dialog.Filename);
	dn = GetAttributesNum(MainDialog);
	//First we check for the main dialog file.
	string DFile = GetAttributeValue(MainDialog);
	//Store it
	Character.LoadedDialog.Filename = DFile;
	if(DIALOG_DEBUG) Trace("Dialog: Stored " + DFile + " in Filename");
	//Now do it for all extra files
	for(i=0; i<dn; i++)
	{
		SubDialog = GetAttributeN(MainDialog,i);
		DFile = GetAttributeValue(SubDialog);
		//Add the filepath and store it
		string Filename = "Filename"+i;
		Character.LoadedDialog.(Filename) = DFile;
		if(DIALOG_DEBUG) Trace("Dialog: Stored " + DFile + " in " + Filename);
	}
	//Levis add attribute for easy checking when dialog started
	Character.Dialog.Lines = 0;
}

void ProcessAllDialogEvent(ref Character)
{
	if(DIALOG_DEBUG) Trace("Dialog: Process all files for Character: " + Character.ID + " Current Node: " + Dialog.CurrentNode);
	//Here we open all dialog files so dialog options are stored
	int i, dn;
	string DFile, DPath;
	aref DialogFile, ParentDialog;
	makearef(ParentDialog,Character.LoadedDialog);
	dn = GetAttributesNum(ParentDialog);
	if(DIALOG_DEBUG) Trace("Dialog: Number of dialog files = " + dn);
	//Little bit of cleaning up
	if(CheckAttribute(&Dialog,"PreLinks")) DeleteAttribute(&Dialog,"PreLinks");
	//Check the files
	for(i=0; i<dn; i++)
	{
		DialogFile = GetAttributeN(ParentDialog,i);
		DFile = GetAttributeValue(DialogFile);
		DPath = LoadDialogFile(DFile);
		//Only process if there is a file, just to be sure.
		if(DPath != "")
		{
			DialogFilesLoaded = i;
			if(DIALOG_DEBUG) Trace("Dialog: Start Process");
			ProcessDialogEvent();
			//Make sure links aren't overwritten unless specified.
			ProcessLinks(dn, i);
			if(DIALOG_DEBUG) Trace("Dialog: Process Done");
			//Check if the dialog is already closed because of dialog exit, else close it.
			if(DialogFilesLoaded > -1)
			{
				UnloadDialogFile(DPath, DFile);
				DialogFilesLoaded = -1;
			}
		}
	}
	//Levis add attribute for easy checking where we are in the dialog
	Character.Dialog.Lines = sti(Character.Dialog.Lines) + 1;
}

void UnloadDialogFileByIndex(int index)
{
	//Here we open all dialog files so dialog options are stored
	string DFile, DPath;
	aref DialogFile, ParentDialog;
	makearef(ParentDialog,CharacterRef.LoadedDialog);
	//Check the files
	DialogFile = GetAttributeN(ParentDialog,index);
	DFile = GetAttributeValue(DialogFile);
	// Get the Dialog path
	DPath = GetStorylinePath(FindCurrentStoryline()) + "dialogs\";
	//Check if there is a storyline file else take the normal one
	if (FindFile("PROGRAM\\" + DPath, "*.c", DFile) == "") {
		DPath = "dialogs\";
	}
	//Close it
	UnloadDialogFile(DPath, DFile);
	if(DIALOG_DEBUG) Trace("Dialog: Closed " + DFile + " because dialog ended");
	DialogFilesLoaded = -1;
}

void UnloadDialogFile(string sDialogDir, string dialogFile)
{
	if(sDialogDir != "")
	{
		//Unload the c file
		string DPath = sDialogDir + dialogFile;
		UnloadSegment(DPath);
		//Get the language file and unloaded
		string Lfile = GetLanguageFile(dialogFile);
		UnloadSegment(Lfile);
		if(DIALOG_DEBUG) Trace("Dialog: Unloaded dialog " + DPath + " Language " + Lfile);
	}
}

string LoadDialogFile(string dialogFile) //Changed to string by levis
{
	//Check if the file is valid (moved check up front by levis)
	int iTmp = strlen(dialogFile);
	if(iTmp<3)
	{
		Trace("Dialog: Missing dialog file by length: " + dialogFile);
		return "";
	}
	// Get the Dialog path
	string sDialogDir = GetStorylinePath(FindCurrentStoryline()) + "dialogs\"; // KK
	string FullDialogPath = sDialogDir + dialogFile; // KK
	string sLanguageDir = LanguageGetLanguage(); // KK
	//Check if there is a storyline file else take the normal one
	if (FindFile("PROGRAM\\" + sDialogDir, "*.c", dialogFile) == "") {
		sDialogDir = "dialogs\";
		FullDialogPath = sDialogDir + dialogFile;
	}
	//Load the language file
	string Lfile = GetLanguageFile(dialogFile);
	bool HasLfile = true;
	if( !LoadSegment(Lfile))
	{
		Trace("Dialog: Missing dialog language file for: " + FullDialogPath);
		HasLfile = false;
	}
	//Load the dialog file
	if( !LoadSegment(FullDialogPath) )
	{
		Trace("Dialog: Missing dialog file: " + FullDialogPath);
		//If no dialog file then unload the languagefile
		if(HasLfile) { UnloadSegment(Lfile); }
		return "";
	}
	if(DIALOG_DEBUG) Trace("Dialog: Loaded dialog " + FullDialogPath + " Language " + Lfile);
	return sDialogDir;
}

// Utils
void ProcessLinks(int maxfiles,int curfile)
{
	if(DIALOG_DEBUG) Trace("Dialog: Start Processing Links");
	//This function sorts the links so they aren't overwritten unless specified.
	aref links; makearef(links, Dialog.Links);
	int lnum = GetAttributesNum(links);
	for (int l = 0; l < lnum; l++) {
		string curlink = GetAttributeName(GetAttributeN(links, l));
		string action = strcut(curlink,0,0);
		string link = strcut(curlink,1,strlen(curlink)-1);
		string newlink;
		//If action is l this is a normal link and it should be added. Options from added files should be placed above default options.
		//If action is a then it should overwrite the link in place, or be placed at that absolute spot
		switch(action)
		{
			case "l":
				newlink = action + link + curfile;
				Dialog.PreLinks.(newlink) = Dialog.Links.(curlink);
				Dialog.PreLinks.(newlink).go = Dialog.Links.(curlink).go;
			break;
			
			case "a":
				newlink = "l" + link + 1; //1 should always be the mainfile
				Dialog.PreLinks.(newlink) = Dialog.Links.(curlink);
				Dialog.PreLinks.(newlink).go = Dialog.Links.(curlink).go;
				if(DIALOG_DEBUG) Trace("Dialog: Dialog option " + "l" + link + " replaced");
			break;
		}
	}
	if(DIALOG_DEBUG) Trace("Dialog: Done Processing Links");
	DeleteAttribute(&Dialog,"Links");
}

string SortLinks()
{
	//This function returns the lowest link and removes it from the options
	aref links; makearef(links, Dialog.PreLinks);
	int lnum = GetAttributesNum(links);
	int curlow = 9999;
	string lowest;
	for (int l = 0; l < lnum; l++) {
		string curlink = GetAttributeName(GetAttributeN(links, l));
		int link = sti(strcut(curlink,1,strlen(curlink)-1));
		if(curlow>link) 
		{
			curlow = link;
			lowest = curlink;
		}
	}
	//Return the lowest link and store it in the sorted links. Then remove it from the processed links.
	if(DIALOG_DEBUG) Trace("Dialog: Link " + lowest + " is the lowest link");
	Dialog.SortLinks.(lowest) = Dialog.PreLinks.(lowest);
	Dialog.SortLinks.(lowest).go = Dialog.PreLinks.(lowest).go;
	DeleteAttribute(&Dialog,"PreLinks."+lowest);
	return lowest;
}

string GetLanguageFile(string dialogFile)
{
	//Get the language file
	int iTmp = strlen(dialogFile);
	string DialogTextFile = strcut(dialogFile,0,iTmp-2) + "h";
	string sLanguageDir = LanguageGetLanguage();
	// PB: Check for storyline .h file even if there is no accompanying .c file -->
	string sDialogDir = GetStorylinePath(FindCurrentStoryline()) + "dialogs\";
	//MAXIMUS 27.05.2019: checks for localized dialog. If not - the english one (default) will loaded ==>
	string PathDlgLngExtn = "";
	if (FindFile("PROGRAM\" + sDialogDir + sLanguageDir, "*.h", DialogTextFile) == "") {
		if(FindFile("PROGRAM\DIALOGS\" + sLanguageDir, "*.h", DialogTextFile) == "") {
			if(FindFile("PROGRAM\" + sDialogDir + "ENGLISH\", "*.h", DialogTextFile) == "") {
				if(FindFile("PROGRAM\DIALOGS\ENGLISH\", "*.h", DialogTextFile) != "") {
					PathDlgLngExtn = "DIALOGS\ENGLISH\" + DialogTextFile;
				}
			}
			else {
				PathDlgLngExtn = sDialogDir + "ENGLISH\" + DialogTextFile;
			}
		}
		else {
			PathDlgLngExtn = "DIALOGS\" + sLanguageDir + "\" + DialogTextFile;
		}
	}
	else
	{
	//Check if there is a storyline file else take the normal one
		PathDlgLngExtn = sDialogDir + sLanguageDir + "\" + DialogTextFile;
	}//MAXIMUS 27.05.2019: <==
	// PB: Check for storyline .h file even if there is no accompanying .c file <--
	return PathDlgLngExtn;
}

// Levis Improved Dialog system <--

// Old dialog technique, removed by Levis
/*bool LoadDialogFiles(string dialogFile)
{
	string  FullDialogPath;
	string	PathDlgLngExtn;
	// Get the Dialog path
	string sDialogDir = GetStorylinePath(FindCurrentStoryline()) + "dialogs\"; // KK
	FullDialogPath = sDialogDir + dialogFile; // KK
	string sLanguageDir = LanguageGetLanguage(); // KK
	//Check if the file is valid
	int iTmp = strlen(dialogFile);
	if(iTmp<3)
	{
		Trace("Dialog: Missing dialog file by lenght: " + dialogFile);
		return false;
	}
	//Open the language file
// KK -->
	if (FindFile("PROGRAM\\" + sDialogDir, "*.c", dialogFile) == "") {
		sDialogDir = "dialogs\";
		FullDialogPath = sDialogDir + dialogFile;
	}

	string DialogTextFile = strcut(dialogFile,0,iTmp-2) + "h";
	PathDlgLngExtn = sDialogDir + sLanguageDir + "\" + DialogTextFile;

	bool retVal = false;
	if (FindFile("PROGRAM\" + sDialogDir + sLanguageDir, "*.h", DialogTextFile) == "") {
		//Trace("LoadDialogFiles: Missing PROGRAM\" + sLanguageDir + "\" + DialogTextFile + " language file - loading ENGLISH.");
		sLanguageDir = "dialogs\ENGLISH";
		PathDlgLngExtn = sLanguageDir + "\" + DialogTextFile;
		if (FindFile("PROGRAM\" + sLanguageDir, "*.h", DialogTextFile)) {
			PathDlgLngExtn = "";
			return false;
		}
		retVal = LoadSegment(PathDlgLngExtn);
	} else {
		retVal = LoadSegment(PathDlgLngExtn);
	}
// <-- KK
	//Unload if not found
	if( !LoadSegment(FullDialogPath) )
	{
		Trace("Dialog: Missing dialog file: " + FullDialogPath);
		retVal = false;
		UnloadSegment(PathDlgLngExtn);
	} else {
		if(!retVal) {
			retVal = true;
			PathDlgLngExtn = "";
		}
	}

	return retVal;
}*/

// KK -->
string GetHostileNations(int iNation)
{
	int nat = 0;
	int ellen = 0;
	string elist = "";
	string st = "";
	for (nat = 0; nat < NATIONS_QUANTITY; nat++) {
		if (nat != PIRATE && GetNationRelation(iNation, nat) == RELATION_ENEMY) elist += nat;
	}
	if (elist != "") {
		ellen = strlen(elist);
		st = XI_ConvertString(GetNationNameByType(sti(strcut(elist, 0, 0))));
		for (nat = 1; nat < ellen - 1; nat++)
			st += ", " + XI_ConvertString(GetNationNameByType(sti(strcut(elist, nat, nat))));
		if (ellen > 1) st += " " + XI_ConvertString("and") + " " + XI_ConvertString(GetNationNameByType(sti(strcut(elist, ellen - 1, ellen - 1))));
	}
	return st;
}

int LotHostileNation(int iNation)
{
	// PB: Rewritten to avoid infinite loop -->
	int nat;
	int num = 0;
	
	string hostileNations = "";
	for(nat=0; nat<NATIONS_QUANTITY; nat++)
	{
		if(GetNationRelation(iNation, nat) != RELATION_ENEMY) continue;
		string tmpNat = nat;
		hostileNations = StoreString(hostileNations,tmpNat);
		num++;
	}
	if (num > 0)	nat = sti(GetRandSubString(hostileNations));
	else			nat = PIRATE;
	return nat;
	// PB: Rewritten to avoid infinite loop <--
}

string RouteForGood(int our_town_idx, int good)
{
	if (our_town_idx < 0 || good < 0) return "nowhere";
	float dist = 0.0;
	int curtown = -1;
	for (int n = 0; n < TOWNS_QUANTITY; n++) {
		if (n == our_town_idx) continue;
		if (Towns[n].id == "Smugglers Lair") continue;
		if (GetTownStoreIndex(Towns[n].id) == -1) continue;
		if (!CheckAttribute(Islands[FindIsland(Towns[n].island)], "Trade.Import")) continue;
		aref import;
		makearef(import, Islands[FindIsland(Towns[n].island)].Trade.Import);
		int i = 1;
		string id = "id" + i;
		while (CheckAttribute(import, id)) {
			if (sti(import.(id)) == good) {
				float cdist = GetTownDistance2D(GetTownByIndex(n), GetTownByIndex(our_town_idx));
				if (cdist < dist || dist == 0.) {
					dist = cdist;
					curtown = n;
				}
				break;
			}
			i++;
			id = "id" + i;
		}
	}
	if (curtown >= 0) return FindTownName(Towns[curtown].id);
	return "nowhere";
}

void FindProfitableRoute(ref good1, ref town1, ref good2, ref town2)
{
	good1 = "";
	town1 = "";
	good2 = "";
	town2 = "";
	string our_town_id = GetCurrentTownID();
	if (!TownExist(our_town_id)) return;
	int our_town_idx = GetTownIndex(our_town_id);
	if (our_town_idx == -1) return;
	if (!CheckAttribute(Islands[FindIsland(Towns[our_town_idx].island)], "Trade.Export")) return;
	aref export;
	makearef(export, Islands[FindIsland(Towns[our_town_idx].island)].Trade.Export);
	int n = 0;
	string id = "id" + (n + 1);
	while (CheckAttribute(export, id)) {
		n++;
		id = "id" + (n + 1);
	}
	n--;
	int idx1 = Rand(n) + 1;
	int idx2 = idx1;
	while (idx2 == idx1) idx2 = Rand(n) + 1;
	id = "id" + idx1;
	int good = sti(export.(id));
	good1 = XI_ConvertString(Goods[good].Name);
	town1 = RouteForGood(our_town_idx, good);
	id = "id" + idx2;
	good = sti(export.(id));
	good2 = XI_ConvertString(Goods[good].Name);
	town2 = RouteForGood(our_town_idx, good);
}

void ProcessDialogText()
{
	//ProcessDialogEvent(); //Removed by Levis
	ProcessAllDialogEvent(CharacterRef); //Added by Levis

	Dialog.Text = PreprocessText(Dialog.Text);
	aref links;
	makearef(links, Dialog.PreLinks); //Changed to prelinks (used to be links) by levis
	int lnum = GetAttributesNum(links);
	for (int l = 0; l < lnum; l++) {
		string curlink = SortLinks(); //Changed by Levis
		Dialog.Links.(curlink) = PreprocessText(Dialog.SortLinks.(curlink)); //Changed by Levis
		Dialog.Links.(curlink).go = Dialog.SortLinks.(curlink).go; //Added by Levis
	}
	DeleteAttribute(&Dialog,"SortLinks"); //Added by Levis
	Preprocessor_Clear(false);
}
// <-- KK

//MAXIMUS -->
void DialogCorpseExit(ref char)
{
	//Если диалога уже не ведётся, выйдем
	if(dialogRun == false) return;
	DelEventHandler("frame", "DialogPlayGreeting");
	//Освобождаем ресурсы
	DeleteClass(&Dialog);
	/*if(FullDialogPath!="") UnloadSegment(FullDialogPath);
	if(PathDlgLngExtn!="") UnloadSegment(PathDlgLngExtn);*/ //Removed by Levis
	if(dialogSelf == false)
	{
		//Ссылка на главного персонажа
		ref mainChr = GetMainCharacter();
		//Отметим, что персонажи освободились от диалога
		LAi_Character_EndDialog(mainChr, char);
		LAi_Character_EndDialog(char, mainChr);
		SendMessage(mainChr, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		DeleteAttribute(mainChr, "IsInDialog");
	}else{
		LAi_Character_EndDialog(char, char);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
	}
	DeleteAttribute(GetMainCharacter(), "forcedlg");
	dialogRun = false;
	dialogSelf = false; //Added by Levis to fix exit
	//Сообщим об окончании диалога
	PostEvent(EVENT_DIALOG_EXIT, 1, "l", sti(char.index));
	// PB -->
	locCameraFollow(); //a simple virtual sailor
	ClearScreenShoter();//MAXIMUS: used for QuickSave
	LogsVisible(true); // KK
	CheckReloadAction(mainChr, "");
	if (CheckAttribute(mainChr, "BoxName.update")) DeleteAttribute(mainChr, "BoxName.update");
	if (CheckAttribute(mainChr, "activeItem.update")) DeleteAttribute(mainChr, "activeItem.update");
	CheckCharacterAction();
	// PB <--
	if(FightDisable == false) {LAi_LocationFightDisable(&Locations[FindLocation(mainChr.location)], false);}
	ClearScreenShoter();//MAXIMUS: used for QuickSave
	if(DIALOG_CAMERA>0.0) locCameraFollow();//MAXIMUS
}
//MAXIMUS <--
