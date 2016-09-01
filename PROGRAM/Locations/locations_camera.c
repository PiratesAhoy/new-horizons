#define LOCCAMERA_FOLLOW	1
#define LOCCAMERA_TOPOS		2
#define LOCCAMERA_FREE		3
#define LOCCAMERA_FIRST		4	// PB: Control Camera Behaviour
#define LOCCAMERA_TRANS		5	// PB: Control Camera Behaviour

int locCameraCurMode;
bool locCameraEnableSpecialMode;
bool locCameraEnableFree;

void locCameraInit()
{
	locCameraEnableFree = FREE_CAMERA;
	locCameraEnableSpecialMode = false;
	//locCameraEnableFree = true;
	locCameraCurMode = LOCCAMERA_FOLLOW;
}

// PB: Check Camera Behaviour -->
string CurrentCameraMode()
{
	switch(locCameraCurMode)
	{
		case LOCCAMERA_FOLLOW:
			return "LOCCAMERA_FOLLOW";
		break;
		case LOCCAMERA_FREE:
			return "LOCCAMERA_FREE";
		break;
		case LOCCAMERA_FIRST:
			return "LOCCAMERA_FIRST";
		break;
		case LOCCAMERA_TRANS:
			return "LOCCAMERA_TRANS";
		break;
	}
}
// PB: Check Camera Behaviour <--

//Set camera follow mode
bool locCameraFollow()
{
	if(IsEntity(locCamera) == 0) return false;
	bool res = SendMessage(&locCamera, "l", MSG_CAMERA_FOLLOW);
	// PB: Control Camera Behaviour -->
	if(locCameraCurMode == LOCCAMERA_FREE)	locCameraCurMode = LOCCAMERA_FIRST;
	else									locCameraCurMode = LOCCAMERA_FOLLOW;
	//LogIt("locCameraCurMode = " + CurrentCameraMode());
	// PB: Control Camera Behaviour <--
	return res;
}

// a simple virtual sailor -->
bool locCameraRight(ref Character)
{
	float a,b,c,locx,locy,locz,x,y,z,ay,d,e,f;
	ref pchar = GetMainCharacter();
	GetCharacterPos(pchar, &a, &b, &c);
	GetCharacterPos(Character, &x, &y, &z);
	locy = b / 2.0 + y / 2.0 + 1.5; 
	d = abs(a - x);
	e = abs(c - z);
	GetCharacterAy(pchar, &ay);
	f = ay + PId2;
	locx = a / 3.0 + 2.0 * x / 3.0 + sin(f) * (d + e) * 1.5;
	locz = c / 3.0 + 2.0 * z / 3.0 + cos(f) * (d + e) * 1.5;
	locCameraToPos(locx, locy, locz, true);
	return true;
}

bool locCameraLeft(ref Character)
{
	float a,b,c,locx,locy,locz,x,y,z,ay,d,e,f;
	ref pchar = GetMainCharacter();
	GetCharacterPos(pchar, &a, &b, &c);
	GetCharacterPos(Character, &x, &y, &z);
	locy = b / 2.0 + y / 2.0 + 1.5; 
	d = abs(a - x);
	e = abs(c - z);
	GetCharacterAy(pchar, &ay);
	f = ay - PId2;
	locx = a / 3.0 + 2.0 * x / 3.0 + sin(f) * (d + e) * 1.5;
	locz = c / 3.0 + 2.0 * z / 3.0 + cos(f) * (d + e) * 1.5;
	locCameraToPos(locx, locy, locz, true);
	return true;
}
// a simple virtual sailor <--

//Set camera toPos mode
bool locCameraToPos(float x, float y, float z, bool isTeleport)
{
	if(IsEntity(locCamera) == 0) return false;
	if(locCameraEnableFree == true) return true;
	bool res = SendMessage(&locCamera, "lfffl", MSG_CAMERA_TOPOS, x, y, z, isTeleport);
	locCameraCurMode = LOCCAMERA_TOPOS;
	return res;
}

//Set camera move mode (speed meter per second)
bool locCameraFree()
{
	if(IsEntity(locCamera) == 0) return false;
	bool res = SendMessage(&locCamera, "l", MSG_CAMERA_FREE);
	// PB: Control Camera Behaviour -->
	if(locCameraCurMode == LOCCAMERA_FOLLOW)	locCameraCurMode = LOCCAMERA_FREE;
	else										locCameraCurMode = LOCCAMERA_TRANS;
	//LogIt("locCameraCurMode = " + CurrentCameraMode());
	// PB: Control Camera Behaviour <--
	return res;
}

//
bool locCameraLock(float ax)
{
	if(IsEntity(locCamera) == 0) return false;
	bool res = SendMessage(&locCamera, "lf", MSG_CAMERA_MOVE, ax);
	return res;
}


void locCameraSleep(bool isSleep)
{
	SendMessage(&locCamera, "ll", MSG_CAMERA_SLEEP, isSleep);
}

void locCameraSwitch()
{
	// PB: Control Camera Behaviour -->
	// This is now handled in seadogs.c
/*	if(locCameraEnableFree == false) return;
	string controlName = GetEventData();
	if(controlName != "ChrCamCameraSwitch") return;
	if(locCameraCurMode != LOCCAMERA_FREE)
	{
		locCameraFree();
	}else{
		locCameraFollow();
	}*/
	// PB: Control Camera Behaviour -->
}

void locCameraSetSpecialMode(bool isEnable)
{
	locCameraEnableSpecialMode = isEnable;
}

#event_handler("EventGetSpecialMode", "locCameraGetSpecialMode");
int locCameraGetSpecialMode()
{
	if(GetTargetPlatform() == "PC") return false;
	return locCameraEnableSpecialMode;
}
