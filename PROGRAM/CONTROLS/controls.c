
#event_handler("frame","procUpdateControlKeyGroup");

#include "CONTROLS\DefaultControls.h" // TIH - Default key control settings file for easy user editing. Nov17'06 // KK

// control flags
#define USE_AXIS_AS_BUTTON				1
#define USE_AXIS_AS_INVERSEBUTTON		2
#define INVERSE_CONTROL					4

string curKeyGroupName = "";
object objControlsState;

bool bKeyboardEnabled = false; // NK 05-07-21
bool bKeyboardShift = false; // ditto
bool bKeyboardControl = false; // MAXIMUS
bool bKeyboardAlt = false;
string KeyboardString = ""; // NK ditto
// KK -->
string KeyboardStringLeft = "";
string KeyboardStringRight = "";
string KeyboardDisplayString = "";
bool bKeyboardOverwriteMode = false;
bool bLMouseDown = false;
bool bRMouseDown = false;
bool bAltDialogControls = false;
object TmpControlsList;
// <-- KK

extern void ExternControlsInit(bool bFirst);
extern void ExternInitKeyCodes(); // NK 05-07-21

void ControlsInit(string sPlatformName,bool bFirst)
{
	DeleteAttribute(&objControlsState,"");

	string initFileName = "";

	if(sPlatformName=="xbox")	initFileName = "controls\init_xbox.c";
	if(sPlatformName=="pc")		initFileName = "controls\init_pc.c";

	if(initFileName=="")
	{
		trace("Can`t init controls because not right platform");
		return;
	}

	if(LoadSegment(initFileName))
	{
		ExternControlsInit(bFirst);
		UnloadSegment(initFileName);
	}
	else
	{
		trace("Can`t init controls because not loaded segment "+initFileName);
		return;
	}
}

void RestoreKeysFromOptions(aref arControlsRoot)
{
	if( GetTargetPlatform()=="xbox" )
	{
		ControlsInit("xbox",false);
		return;
	}
	aref arRootKey,arKey;
	int nGroupQ,nKeyQ, i,j, state,ctrlCode,keyCode;
	string ctrlName,grName;

	nGroupQ = GetAttributesNum(arControlsRoot);

	for(i=0; i<nGroupQ; i++)
	{
		arRootKey = GetAttributeN(arControlsRoot,i);
		grName = GetAttributeName(arRootKey);
		nKeyQ = GetAttributesNum(arRootKey);
		for(j=0; j<nKeyQ; j++)
		{
			arKey = GetAttributeN(arRootKey,j);
			state = 0;
			if(CheckAttribute(arKey,"state"))
			{
				state = sti(arKey.state);
			}

			ctrlName = GetAttributeName(arKey);
			keyCode = CI_GetKeyCode(GetAttributeValue(arKey));
			CI_CreateAndSetControls( grName, ctrlName, keyCode, state, true );
		}
	}

	RunControlsContainers();
}

void CI_CreateContainer( string groupName, string containerName, float containerVal )
{
	objControlsContainer.(containerName) = containerVal;
	CI_CreateAndSetControls(groupName, containerName, -1, 0, false);
	DoControlInvisible(groupName, containerName);
}

void AddToContainer(string groupName, string containerName, string controlName, int KeyCode, int controlState, bool inverse )
{
	float fVal = objControlsContainer.(containerName);
	string keyName = CI_GetKeyName(KeyCode);
	if( CheckAttribute(&objControlsState,"key_codes."+keyName+".stick") &&
		sti(objControlsState.key_codes.(keyName).stick)==true )
	{
		fVal /= 15.0;
	}
	if(inverse) fVal = -fVal;
	objControlsContainer.(containerName).(controlName) = fVal;
	CI_CreateAndSetControls(groupName, controlName, KeyCode, controlState, false);
	DoControlInvisible(groupName, controlName);
}

void DoControlInvisible(string groupName, string controlName)
{
	if( CheckAttribute(&objControlsState,"keygroups."+groupName+"."+controlName) )
	{
		objControlsState.keygroups.(groupName).(controlName).invisible = true;
	}
}

// NK create control only, no map 05-07-21
// returns true if control already exists
bool CI_CreateControlOnly(string controlName)
{
	bool rb = true;
	if( !CheckAttribute(&objControlsState,"map.controls."+controlName) )
	{
		rb = false;
		objControlsState.map.controls.(controlName) = CreateControl(controlName);
	}
	return rb;
}

// KEYBOARD INPUT SECTION 05-07-21

// allow turn off keyboard via event. This is done via ENTER or ESCAPE
#event_handler("KB_end", "KB_Turnoff");
void KB_TurnOff()
{
	KB_SetKeyboardMode(false);
}


// returns true if mode changed
bool KB_SetKeyboardMode(bool onoff)
{
	if(onoff && !bKeyboardEnabled)
	{
		PlaySound("interface\notebook.wav");
		// Screwface
		int idx = sti(GlobalSettings.Storyline);
		CurrentStoryline = idx;
		string storyline = GetStoryline(CurrentStoryline);
		CurrentProfile = GetCurrentProfile(storyline);
		//stringlen = Globalsettings.profile.(storyline).len;
		InitGlobalOptions();
		ref gopt; makeref(gopt, GlobalSettings);
		ReadMainOptions(&gopt);
		gopt.Storyline = CurrentStoryline;
		gopt.profile.(storyline) = CurrentProfile;
		//gopt.profile.(storyline).len = stringlen;
		WriteMainOptions(gopt);
		// Screwface : End
		
		bKeyboardEnabled = true;
		bKeyboardShift = false;
		bKeyboardControl = false;
		bKeyboardAlt = false;
		DeleteAttribute(&objControlsState,"");
		if(LoadSegment("controls\init_pc.c"))
		{
			ExternInitKeyCodes();
			UnloadSegment("controls\init_pc.c");
		}
		//ControlsInit(GetTargetPlatform(), false);
		objControlsState.keys.key_8 = "NK_KB_back"; // try to remap back
		objControlsState.keys.key_27 = "NK_KB_esc";
		objControlsState.keys.key_32 = "NK_Key_ ";
		objControlsState.keys.key_13 = "NK_KB_enter";

		CI_CreateAndSetControls( "", "IAllCancel", -1, 0, true); // try to unmap back
		CI_CreateAndSetControls( "", "ICancel", -1, 0, true);
		CI_CreateAndSetControls( "", "IAction", -1, 0, true );
		CI_CreateAndSetControls( "", "IStartButton", -1, 0, true);
// changed by MAXIMUS for typing on Russian -->
		string typeLanguage = GetInterfaceLanguageName(GetKeyboardLayout()); // KK
		if(CheckAttribute(GameInterface,"tempLang")) typeLanguage = GameInterface.tempLang;
		ResetKeyboardCharacters(typeLanguage);// MAXIMUS: 16.10.2006
		// KK -->
		switch (typeLanguage) {
			case "Russian":
				CI_CreateAndSetControls("", "NK_Key_а", CI_GetKeyCode("Key_f"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_б", CI_GetKeyCode("VK_OEM_COMMA"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_в", CI_GetKeyCode("Key_d"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_г", CI_GetKeyCode("Key_u"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_д", CI_GetKeyCode("Key_l"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_е", CI_GetKeyCode("Key_t"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ё", CI_GetKeyCode("VK_OEM_3"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ж", CI_GetKeyCode("VK_OEM_1"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_з", CI_GetKeyCode("Key_p"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_и", CI_GetKeyCode("Key_b"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_й", CI_GetKeyCode("Key_q"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_к", CI_GetKeyCode("Key_r"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_л", CI_GetKeyCode("Key_k"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_м", CI_GetKeyCode("Key_v"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_н", CI_GetKeyCode("Key_y"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_о", CI_GetKeyCode("Key_j"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_п", CI_GetKeyCode("Key_g"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_р", CI_GetKeyCode("Key_h"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_с", CI_GetKeyCode("Key_c"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_т", CI_GetKeyCode("Key_n"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_у", CI_GetKeyCode("Key_e"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ф", CI_GetKeyCode("Key_a"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_х", CI_GetKeyCode("VK_OEM_4"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ц", CI_GetKeyCode("Key_w"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ч", CI_GetKeyCode("Key_x"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ш", CI_GetKeyCode("Key_i"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_щ", CI_GetKeyCode("Key_o"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ы", CI_GetKeyCode("Key_s"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ъ", CI_GetKeyCode("VK_OEM_6"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_э", CI_GetKeyCode("VK_OEM_7"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ь", CI_GetKeyCode("Key_m"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_ю", CI_GetKeyCode("VK_OEM_PERIOD"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_я", CI_GetKeyCode("KEY_z"), 0, false);

				CI_CreateAndSetControls( "", "NK_Key_.", CI_GetKeyCode("VK_OEM_2"), 0, false);
			break;
			// default:
				CI_CreateAndSetControls("", "NK_Key_a", CI_GetKeyCode("KEY_a"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_b", CI_GetKeyCode("KEY_b"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_c", CI_GetKeyCode("KEY_c"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_d", CI_GetKeyCode("KEY_d"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_e", CI_GetKeyCode("KEY_e"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_f", CI_GetKeyCode("KEY_f"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_g", CI_GetKeyCode("KEY_g"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_h", CI_GetKeyCode("KEY_h"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_i", CI_GetKeyCode("KEY_i"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_j", CI_GetKeyCode("KEY_j"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_k", CI_GetKeyCode("KEY_k"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_l", CI_GetKeyCode("KEY_l"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_m", CI_GetKeyCode("KEY_m"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_n", CI_GetKeyCode("KEY_n"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_o", CI_GetKeyCode("KEY_o"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_p", CI_GetKeyCode("KEY_p"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_q", CI_GetKeyCode("KEY_q"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_r", CI_GetKeyCode("KEY_r"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_s", CI_GetKeyCode("KEY_s"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_t", CI_GetKeyCode("KEY_t"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_u", CI_GetKeyCode("KEY_u"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_v", CI_GetKeyCode("KEY_v"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_w", CI_GetKeyCode("KEY_w"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_x", CI_GetKeyCode("KEY_x"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_y", CI_GetKeyCode("KEY_y"), 0, false);
				CI_CreateAndSetControls("", "NK_Key_z", CI_GetKeyCode("KEY_z"), 0, false);

				CI_CreateAndSetControls( "", "NK_KEY_;", CI_GetKeyCode("VK_OEM_1"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_/", CI_GetKeyCode("VK_OEM_2"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_`", CI_GetKeyCode("VK_OEM_3"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_[", CI_GetKeyCode("VK_OEM_4"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_\\", CI_GetKeyCode("VK_OEM_5"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_]", CI_GetKeyCode("VK_OEM_6"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_'", CI_GetKeyCode("VK_OEM_7"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_DOT", CI_GetKeyCode("VK_OEM_PERIOD"), 0, false);
				CI_CreateAndSetControls( "", "NK_KEY_,", CI_GetKeyCode("VK_OEM_COMMA"), 0, false);
				CI_CreateAndSetControls( "", "NK_Key_=", CI_GetKeyCode("VK_EQUAL"), 0, false);
		}
// <-- KK

		CI_CreateAndSetControls("", "NK_Key_0", CI_GetKeyCode("KEY_0"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_1", CI_GetKeyCode("KEY_1"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_2", CI_GetKeyCode("KEY_2"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_3", CI_GetKeyCode("KEY_3"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_4", CI_GetKeyCode("KEY_4"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_5", CI_GetKeyCode("KEY_5"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_6", CI_GetKeyCode("KEY_6"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_7", CI_GetKeyCode("KEY_7"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_8", CI_GetKeyCode("KEY_8"), 0, false);
		CI_CreateAndSetControls("", "NK_Key_9", CI_GetKeyCode("KEY_9"), 0, false);

		CI_CreateAndSetControls( "", "NK_KB_Shift_on", CI_GetKeyCode("VK_SHIFT"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_Shift_off", CI_GetKeyCode("VK_SHIFT"), INVERSE_CONTROL, false);

// KK: Used to get special symbols for multilingual support: <diacritical character> = ALT + <letter> -->
		CI_CreateAndSetControls( "", "NK_KB_Alt_on", CI_GetKeyCode("VK_ALT"), 0, true );
		CI_CreateAndSetControls( "", "NK_KB_Alt_off", CI_GetKeyCode("VK_ALT"), INVERSE_CONTROL, true );
// <-- KK
//MAXIMUS -->
		CI_CreateAndSetControls( "", "NK_KB_Control_on", CI_GetKeyCode("VK_CONTROL"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_Control_off", CI_GetKeyCode("VK_CONTROL"), INVERSE_CONTROL, false);
//MAXIMUS <--
		//CI_CreateAndSetControls( "", "NK_KB_space", CI_GetKeyCode("VK_SPACE"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_enter", CI_GetKeyCode("VK_RETURN"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_esc", CI_GetKeyCode("VK_ESCAPE"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_back", CI_GetKeyCode("VK_BACK"), 0, false);

// KK -->
		CI_CreateAndSetControls( "", "NK_KB_del", CI_GetKeyCode("VK_DELETE"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_ins", CI_GetKeyCode("VK_INSERT"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_home", CI_GetKeyCode("VK_HOME"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_end", CI_GetKeyCode("VK_END"), 0, false);

		CI_CreateAndSetControls( "", "NK_NP_0", CI_GetKeyCode("VK_NUMPAD0"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_1", CI_GetKeyCode("VK_NUMPAD1"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_2", CI_GetKeyCode("VK_NUMPAD2"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_3", CI_GetKeyCode("VK_NUMPAD3"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_4", CI_GetKeyCode("VK_NUMPAD4"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_5", CI_GetKeyCode("VK_NUMPAD5"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_6", CI_GetKeyCode("VK_NUMPAD6"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_7", CI_GetKeyCode("VK_NUMPAD7"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_8", CI_GetKeyCode("VK_NUMPAD8"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_9", CI_GetKeyCode("VK_NUMPAD9"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_,", CI_GetKeyCode("VK_DECIMAL"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_+", CI_GetKeyCode("VK_ADD"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_-", CI_GetKeyCode("VK_SUBTRACT"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_*", CI_GetKeyCode("VK_MULTIPLY"), 0, false);
		CI_CreateAndSetControls( "", "NK_NP_/", CI_GetKeyCode("VK_DIVIDE"), 0, false);

		CI_CreateAndSetControls( "", "NK_KB_caps", CI_GetKeyCode("VK_CAPITAL"), 0, false);

		CI_CreateAndSetControls( "", "NK_KB_left", CI_GetKeyCode("VK_LEFT"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_right", CI_GetKeyCode("VK_RIGHT"), 0, false);
// <-- KK
		/*CI_CreateAndSetControls( "", "NK_KB_up", CI_GetKeyCode("VK_UP"), 0, false);
		CI_CreateAndSetControls( "", "NK_KB_down", CI_GetKeyCode("VK_DOWN"), 0, false);*/

		//CI_CreateAndSetControls( "", "NK_KB_decimal", CI_GetKeyCode("VK_DECIMAL"), 0, false);

		CI_CreateAndSetControls( "", "NK_Key_ ", CI_GetKeyCode("VK_SPACE"), 0, false);
		CI_CreateAndSetControls( "", "NK_Key_-", CI_GetKeyCode("VK_OEM_MINUS"), 0, false);
		CI_CreateAndSetControls( "", "NK_Key_=", CI_GetKeyCode("VK_OEM_PLUS"), 0, false);
// changed by MAXIMUS for typing on Russian <--
		return true;
	}
	else
	{
		if(!onoff && bKeyboardEnabled)
		{
			PlaySound("interface\cancel.wav");
			bKeyboardEnabled = false;
			bKeyboardShift = false;
			bKeyboardControl = false;
			bKeyboardAlt = false;
			bKeyboardOverwriteMode = false; // KK
			ControlsInit(GetTargetPlatform(), false);
			SaveGlobalOptions(); // Screwface : was LoadGlobalOptions();
			if (IsEntity(&GameInterface)) SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0); // KK
			return true;
		}
	}
	return false;
}

void KB_AddCharacter(string c)
{
	string sTmp = ""; // KK
	//trace("adding character " + c);
// changed by MAXIMUS and KK for typing in Russian and Polish -->
	if (CheckAttribute(&GameInterface, "TextBox.current")) {
		sTmp = GameInterface.TextBox.current;
		if (CheckAttribute(&GameInterface, "TextBox." + sTmp + ".maxchars") == true && strlen(KeyboardDisplayString) == sti(GameInterface.TextBox.(sTmp).maxchars) + 1) return;
		if (CheckAttribute(&GameInterface, "TextBox." + sTmp + ".numeric") == true && sti(GameInterface.TextBox.(sTmp).numeric) == true) {
			if (c == "-") {
				if (strlen(KeyboardStringLeft) > 0 || getSymbol(KeyboardStringRight, 0) == "-") return;
			} else {
				if (!isDigit(&c, 0)) return;
			}
		}
	}
	PlaySound("interface\Ok.wav");
	sTmp = GetInterfaceLanguageName(GetKeyboardLayout());
	if(CheckAttribute(GameInterface,"tempLang")) sTmp = GameInterface.tempLang;
	switch (sTmp) {
		case "Russian":
			if(bKeyboardShift) KeyboardStringLeft += toupperrus(c);
			else KeyboardStringLeft += c;
		break;
		case "French":
			if(bKeyboardAlt) c = GetDiacriticalChar(c, "French");
			if(bKeyboardShift) KeyboardStringLeft += toupperfra(c);
			else KeyboardStringLeft += c;
		break;
		case "German":
			if(bKeyboardAlt) c = GetDiacriticalChar(c, "German");
			if(bKeyboardShift) KeyboardStringLeft += toupperger(c);
			else KeyboardStringLeft += c;
		break;
		case "Spanish":
			if(bKeyboardAlt) c = GetDiacriticalChar(c, "Spanish");
			if(bKeyboardShift) KeyboardStringLeft += toupperspa(c);
			else KeyboardStringLeft += c;
		break;
		case "Polish":
			if(bKeyboardAlt) c = GetDiacriticalChar(c, "Polish");
			if(bKeyboardShift) KeyboardStringLeft += toupperpol(c);
			else KeyboardStringLeft += c;
		break;
		// default:
			if(bKeyboardShift) KeyboardStringLeft += touppereng(c);
			else KeyboardStringLeft += c;
	}
	if (bKeyboardOverwriteMode == true && KeyboardStringRight != "" && c != "") {
		if (strlen(KeyboardStringRight) > 1)
			KeyboardStringRight = strcut(KeyboardStringRight, 1, strlen(KeyboardStringRight) - 1);
		else
			KeyboardStringRight = "";
	}
	KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol() + KeyboardStringRight;
	KeyboardString = KeyboardStringLeft + KeyboardStringRight;
// changed by MAXIMUS and KK for typing in Russian and Polish <--
}

// true if did remove character
bool KB_RemoveCharacter()
{
	//trace("removing char, string was <<" + KeyboardString + ">>");
// KK -->
	int len = strlen(KeyboardStringLeft);
	if(len < 1 || KeyboardStringLeft == "") return false; // just in case...
	PlaySound("interface\button1.wav");
	if (len > 2) {
		KeyboardStringLeft = strcut(KeyboardStringLeft, 0, len-2);
	} else {
		if (len > 1) {
			KeyboardStringLeft = GetSymbol(KeyboardStringLeft, 0);
		} else {
			KeyboardStringLeft = "";
		}
	}
	//trace("new string is <<" + KeyboardString + ">>");
	KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol() + KeyboardStringRight;
	KeyboardString = KeyboardStringLeft + KeyboardStringRight;
// <-- KK
	return true;
}
// NK <--

// KK -->
bool KB_DeleteCharacter()
{
	int len = strlen(KeyboardStringRight);
	if(len < 1 || KeyboardStringRight == "") return false; // just in case...
	PlaySound("interface\button1.wav");
	if (len > 2) {
		KeyboardStringRight = strcut(KeyboardStringRight, 1, len-1);
	} else {
		if (len > 1) {
			KeyboardStringRight = GetSymbol(KeyboardStringRight, 1);
		} else {
			KeyboardStringRight = "";
		}
	}
	KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol() + KeyboardStringRight;
	KeyboardString = KeyboardStringLeft + KeyboardStringRight;
	return true;
}

void KB_CursorLeft()
{
	if (KeyboardStringLeft != "") {
		int len = strlen(KeyboardStringLeft);
		KeyboardStringRight = GetSymbol(KeyboardStringLeft, len - 1) + KeyboardStringRight;
		if (len > 1)
			KeyboardStringLeft = strcut(KeyboardStringLeft, 0, len - 2);
		else
			KeyboardStringLeft = "";
		KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol() + KeyboardStringRight;
		KeyboardString = KeyboardStringLeft + KeyboardStringRight;
	}
}

void KB_CursorRight()
{
	if (KeyboardStringRight != "") {
		int len = strlen(KeyboardStringRight);
		KeyboardStringLeft += GetSymbol(KeyboardStringRight, 0);
		if (len > 1)
			KeyboardStringRight = strcut(KeyboardStringRight, 1, len - 1);
		else
			KeyboardStringRight = "";
		KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol() + KeyboardStringRight;
		KeyboardString = KeyboardStringLeft + KeyboardStringRight;
	}
}

void KB_CursorHome()
{
	KeyboardStringRight = KeyboardStringLeft + KeyboardStringRight;
	KeyboardStringLeft = "";
	KeyboardDisplayString = GetCursorSymbol() + KeyboardStringRight;
	KeyboardString = KeyboardStringRight;
}

void KB_CursorEnd()
{
	KeyboardStringLeft += KeyboardStringRight;
	KeyboardStringRight = "";
	KeyboardDisplayString = KeyboardStringLeft + GetCursorSymbol();
	KeyboardString = KeyboardStringLeft;
}

void KB_Prepare(string gistr)
{
	KeyboardString = gistr;
	KeyboardStringLeft = KeyboardString;
	KeyboardStringRight = "";
	KeyboardDisplayString = KeyboardString + GetCursorSymbol();
}
// <-- KK

string CI_CreateAndSetControls( string groupName, string controlName, int keyCode, int controlState, bool bRemappingEnable )
{
	if(controlName=="") return "";
	string retString = "";

	if( !CheckAttribute(&objControlsState,"map.controls."+controlName) )
	{
		objControlsState.map.controls.(controlName) = CreateControl(controlName);
	}
	int cntrlCode = sti(objControlsState.map.controls.(controlName));

	if(keyCode>=0)
	{
		string keyName = "key_" + keyCode;
		objControlsState.map.keys.(keyName) = controlName;
	}
	MapControl(cntrlCode,keyCode);

	if(keyCode<0 && controlState==0)
	{
		controlState = USE_AXIS_AS_BUTTON;
	}

	if(controlState!=-1)
	{	SetControlFlags(cntrlCode,controlState);
	}
	else
	{	controlState=0;
	}

	if(groupName!="")
	{
		if( CheckAttribute(&objControlsState,"keygroups."+groupName+"."+controlName) )
		{	retString = objControlsState.keygroups.(groupName).(controlName);
		}
		else
		{	objControlsState.keygroups.(groupName).(controlName) = "";
		}
		SetControlsByKey(controlName,CI_GetKeyName(keyCode),controlState);
		objControlsState.keygroups.(groupName).(controlName).remapping = bRemappingEnable;
	}

	return retString;
}

void SetControlsByKey(string controlName, string keyName, int state)
{
	int i,nGQ;
	aref arKGRoot, arKG;

	makearef(arKGRoot,objControlsState.keygroups);
	nGQ = GetAttributesNum(arKGRoot);

	for(i=0; i<nGQ; i++)
	{
		arKG = GetAttributeN(arKGRoot,i);
		if( CheckAttribute(arKG,controlName) )
		{	arKG.(controlName) = keyName;
			arKG.(controlName).state = state;
		}
	}
}

void MapControlToGroup(string controlName,string groupName)
{
	// Найдем использование контрола
	int i,nRootSize;
	aref arRoot,arGroup;

	makearef(arRoot,objControlsState.keygroups);
	nRootSize = GetAttributesNum(arRoot);

	for(i=0; i<nRootSize; i++)
	{
		arGroup = GetAttributeN(arRoot,i);
		if( CheckAttribute(arGroup,controlName) )
		{
			objControlsState.keygroups.(groupName).(controlName) = arGroup.(controlName);
			objControlsState.keygroups.(groupName).(controlName).state = arGroup.(controlName).state;
			if( CheckAttribute(arGroup,controlName+".invisible") ) {
				objControlsState.keygroups.(groupName).(controlName).invisible = arGroup.(controlName).invisible;
			}
			if( CheckAttribute(arGroup,controlName+".remapping") ) {
				objControlsState.keygroups.(groupName).(controlName).remapping = arGroup.(controlName).remapping;
			}
			return;
		}
	}
}

int CI_GetKeyCode(string keyName)
{
	if( CheckAttribute(&objControlsState,"key_codes."+keyName) )
	{	return sti(objControlsState.key_codes.(keyName));
	}

	trace("Can`t key named as: " + keyName);
	return -1;
}

string CI_GetKeyName(int code)
{
	aref arKeys,arCur;
	makearef(arKeys,objControlsState.key_codes);
	int nq = GetAttributesNum(arKeys);

	for(int i=0; i<nq; i++)
	{
		arCur = GetAttributeN(arKeys,i);
		if( sti(GetAttributeValue(arCur)) == code )
		{	return GetAttributeName(arCur);
		}
	}

	return "";
}

int ControlNameToCode(string cname)
{
	if( CheckAttribute(&objControlsState,"map.controls."+cname) )
	{	return sti(objControlsState.map.controls.(cname));
	}
	return -1;
}

#event_handler("evntUpdateDialogControls", "procUpdateControlKeyGroup");
void procUpdateControlKeyGroup()
{
	string newCurGroup = GetCurControlGroup();
	if(curKeyGroupName==newCurGroup) return;

	FreezeGroupControls(curKeyGroupName,true);
	FreezeGroupControls(newCurGroup,false);
	curKeyGroupName = newCurGroup;
}

string GetCurControlGroup()
{
	if( IsEntity(&aviVideoObj) ) return "VideoPlayer";
	if( bRunHelpChooser ) return "HelpChooser";

	if( CheckAttribute(InterfaceStates, "Launched") && sti(InterfaceStates.Launched) == true ) return "MainInterface";

	if( DialogRun ) return "DialogControls";

	if(IsEntity(&worldMap)) return "WorldMapControls";

	if(bSeaActive && !bAbordageStarted)
	{
		if( CheckAttribute(&BattleInterface,"ComState") && sti(BattleInterface.ComState) != 0 )
			return "BattleInterfaceControls";

		if( SeaCameras.Camera == "SeaDeckCamera" )	{ return "Sailing1Pers"; }
		else { return "Sailing3Pers"; }
	}

	if( CheckAttribute(&objLandInterface,"ComState") && sti(objLandInterface.ComState) != 0 )
		return "BattleInterfaceControls";

	ref mchref = GetMainCharacter();
	if( SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"IsFightMode") != 0 )
		return "FightModeControls";

	return "PrimaryLand";
}

void FreezeGroupControls(string grName, bool bFreeze)
{
	if(grName=="")
	{
		AllControlsFreeze(bFreeze);
		return;
	}
	if( !CheckAttribute(&objControlsState,"keygroups."+grName) ) return;

	int i,nq;
	aref arKeyRoot, arKey;

	makearef(arKeyRoot,objControlsState.keygroups.(grName));
	nq = GetAttributesNum(arKeyRoot);
	for(i=0; i<nq; i++)
	{
		arKey = GetAttributeN(arKeyRoot,i);
		LockControl(GetAttributeName(arKey),bFreeze);
	}
}

void AllControlsFreeze(bool bFreeze)
{
	int i,ngq, j,ncq;
	aref arRoot,arGroup;

	makearef(arRoot,objControlsState.keygroups);
	ngq = GetAttributesNum(arRoot);

	for(i=0; i<ngq; i++)
	{
		arGroup = GetAttributeN(arRoot,i);
		ncq = GetAttributesNum(arGroup);
		for(j=0; j<ncq; j++)
		{
			LockControl(GetAttributeName(GetAttributeN(arGroup,j)),bFreeze);
		}
	}
}

object objControlsContainer;
void RunControlsContainers()
{
	//CreateEntity(&objControlsContainer,"controls_container");
	//LayerAddObject("iExecute",&objControlsContainer,1);
}

void ControlsMakeInvert()
{
	int bInvert;
	bool bAllInvert = false;
	if( CheckAttribute(&InterfaceStates,"InvertCameras") && sti(InterfaceStates.InvertCameras)==true ) {
		bAllInvert = true;
	}

	aref arRoot, arCur;
	makearef(arRoot,objControlsState.Inverting);
	int q = GetAttributesNum(arRoot);
	for(int n=0; n<q; n++)
	{
		arCur = GetAttributeN(arRoot,n);
		if(bAllInvert) {bInvert = !sti(GetAttributeValue(arCur));}
		else {bInvert = sti(GetAttributeValue(arCur));}
		XI_ControlMakeInvert( GetAttributeName(arCur), bInvert );
	}
}

void SetControlForInverting(string controlName, bool invertState)
{
	objControlsState.Inverting.(controlName) = invertState;
}

void SetRealMouseSensitivity()
{
	float fRealMouseXSens = 1.0;
	float fRealMouseYSens = 1.0;

	float fx = 0.5;
	float fy = 0.5;
	if( CheckAttribute(InterfaceStates,"mouse.x_sens") )
		fx = stf(InterfaceStates.mouse.x_sens);
	if( CheckAttribute(InterfaceStates,"mouse.y_sens") )
		fy = stf(InterfaceStates.mouse.y_sens);

	if(fx<=0.5) {fRealMouseXSens = 0.5 + fx;}
	else {fRealMouseXSens = fx*2.0;}
	if(fy<=0.5) {fRealMouseYSens = 0.5 + fy;}
	else {fRealMouseYSens = fy*2.0;}

	XI_SetMouseSensitivity( fRealMouseXSens, fRealMouseYSens );
}

// KK -->
void SwitchDialogControls()
{
	if (bAltDialogControls) {
		CI_CreateAndSetControls( "DialogControls", "DlgAction", CI_GetKeyCode(CTL_DIALOG_SELECT_ALT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgUp", CI_GetKeyCode(CTL_DIALOG_CHOICE_UP_ALT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgDown", CI_GetKeyCode(CTL_DIALOG_CHOICE_DOWN_ALT), 0, false );

		CI_CreateAndSetControls( "DialogControls", "DlgActionAlt", CI_GetKeyCode(CTL_DIALOG_SELECT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgUpAlt", CI_GetKeyCode(CTL_DIALOG_CHOICE_UP), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgDownAlt", CI_GetKeyCode(CTL_DIALOG_CHOICE_DOWN), 0, false );
	} else {
		CI_CreateAndSetControls( "DialogControls", "DlgAction", CI_GetKeyCode(CTL_DIALOG_SELECT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgUp", CI_GetKeyCode(CTL_DIALOG_CHOICE_UP), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgDown", CI_GetKeyCode(CTL_DIALOG_CHOICE_DOWN), 0, false );

		CI_CreateAndSetControls( "DialogControls", "DlgActionAlt", CI_GetKeyCode(CTL_DIALOG_SELECT_ALT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgUpAlt", CI_GetKeyCode(CTL_DIALOG_CHOICE_UP_ALT), 0, false );
		CI_CreateAndSetControls( "DialogControls", "DlgDownAlt", CI_GetKeyCode(CTL_DIALOG_CHOICE_DOWN_ALT), 0, false );
	}
	bAltDialogControls = !bAltDialogControls;
}

void SaveControls()
{
	aref arControls; makearef(arControls, GlobalSettings.controls);
	ref rTmpControlsList; makeref(rTmpControlsList, TmpControlsList);
	DeleteAttribute(rTmpControlsList, "");
	CopyAttributes(rTmpControlsList, arControls);
}

void RestoreControls()
{
	aref arControls; makearef(arControls, GlobalSettings.controls);
	ref rTmpControlsList; makeref(rTmpControlsList, TmpControlsList);
	CopyAttributes(arControls, rTmpControlsList);
	DeleteAttribute(rTmpControlsList, "");
}
// <-- KK
