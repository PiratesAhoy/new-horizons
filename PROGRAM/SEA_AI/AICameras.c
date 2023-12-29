object SeaCameras;
object SeaShipCamera;
object SeaDeckCamera;
aref Crosshair;
ref SeaShipCharacterForCamera;
bool bCanSwitchCameras = true;
bool bCameraOnMyShip = true; // KK

void DeleteSeaCamerasEnvironment()
{
	DeleteClass(&SeaShipCamera);
	DeleteClass(&SeaDeckCamera);
	DelEventHandler("SeaCameras_Switch", "SeaCameras_Switch");
	DelEventHandler(TELESCOPE_ACTIVE, "SeaCameras_TelescopeActive");
}

void CreateSeaCamerasEnvironment()
{
	bCanSwitchCameras = true;

	CreateEntity(&SeaCameras, "SEA_CAMERAS");
	CreateEntity(&SeaShipCamera, "SHIP_CAMERA");
	CreateEntity(&SeaDeckCamera, "DECK_CAMERA");

	FreeCamera.Perspective = 1.285;

	// Ship camera paramerets
	SeaShipCamera.Perspective = 1.285;
	SeaShipCamera.SensivityDistance = 1.0;
	SeaShipCamera.SensivityHeightAngle = 0.02;
	SeaShipCamera.SensivityHeightAngleOnShip = 0.005;
	SeaShipCamera.SensivityAzimuthAngle = 0.04;
	SeaShipCamera.MaxAngleX = 0.2;
	SeaShipCamera.MinAngleX = -1.4;
	SeaShipCamera.Distance = 69.0;
	SeaShipCamera.MinDistance = 25.0;
	SeaShipCamera.MaxDistance = 70.0;
	SeaShipCamera.MinHeightOnSea = 1.0;
	SeaShipCamera.MaxHeightOnShip = 16.0;
	SeaShipCamera.InvertMouseX = 1.0;
	SeaShipCamera.InvertMouseY = -1.0;

	// Deck camera paramerets
	SeaDeckCamera.Perspective = 1.285;
	SeaDeckCamera.SensivityDistance = 0.0065; // boocha - 0.01;

	SeaDeckCamera.SensivityHeightAngle = 0.0015;
	SeaDeckCamera.SensivityAzimuthAngle = 0.0015;
	SeaDeckCamera.StepUp = 0.5;
	SeaDeckCamera.StepMin = 0.01;
	SeaDeckCamera.h_max = 2.0;
	SeaDeckCamera.h_min = 0.5;
	SeaDeckCamera.h_step = 0.1;
	SeaDeckCamera.h_def = 1.6;
	SeaDeckCamera.MaxAngleX = 1.5;
	SeaDeckCamera.MinAngleX = -1.5;
	SeaDeckCamera.RockingX = 0.8;
	SeaDeckCamera.RockingZ = 0.8;

// KK (another approach - LDH's reincarnation caused CTD on majority of sea reloads) -->
	makearef(Crosshair,SeaCameras.Crosshair);

	if (DECK_VIEW_ON_SEAENTER && !bAbordageStarted && actLoadFlag == 0) {
		Scene.Camera = DECK_CAMERA;
		Crosshair.OutsideCamera = false;
	} else {
		Scene.Camera = SHIP_CAMERA;
		Crosshair.OutsideCamera = true;
	}
// <-- KK

	Crosshair.Texture = "crosshair\crosshair.tga";
	Crosshair.Size = 0.05;
	Crosshair.Technique = "Crosshair";
	Crosshair.SubTexX = 1;
	Crosshair.SubTexY = 1;
	Crosshair.Colors.Default = argb(0, 255, 255, 255);
	Crosshair.Colors.Enemy = argb(0, 255, 0, 0);
	Crosshair.Colors.Friend = argb(0, 0, 255, 0);
	Crosshair.Colors.Neutral = argb(0, 128, 128, 128);

	SendMessage(&AISea, "la", AI_MESSAGE_SET_CAMERAS_ATTRIBUTE, &SeaCameras);

	SetEventHandler("SeaCameras_Switch", "SeaCameras_Switch", 1);
	SetEventHandler(TELESCOPE_ACTIVE, "SeaCameras_TelescopeActive", 0);

	SeaShipCharacterForCamera = GetMainCharacter(); // KK
	// KK if (DECK_VIEW_ON_SEAENTER == 1) PostEvent("SeaCameras_Switch",250);	// LDH reinstated 13Mar09
}

void SeaCameras_TelescopeActive()
{
	int iTelescopeActive = GetEventData();
	if (iTelescopeActive)
	{
		bCanSwitchCameras = false;
		Crosshair.OutsideCamera = true;
	}
	else
	{
		bCanSwitchCameras = true;
		Crosshair.OutsideCamera = SeaCameras_isCameraOutside();
	}
}

void SeaCameras_Switch()
{
	if (!bCanSwitchCameras || !bCameraOnMyShip) return; // KK

	int bSwitch = false;
	switch (Scene.Camera)
	{
		case FREE_CAMERA:
			Scene.Camera = SHIP_CAMERA;
			Crosshair.OutsideCamera = true;
			PeopleOnShip.IsOnDeck = 0;
			bSwitch = true;
		break;
		case SHIP_CAMERA:
			if (!LAi_IsDead(&Characters[GetMainCharacterIndex()]))
			{
				Scene.Camera = DECK_CAMERA;
// KK -->
				if (GetCaracterShipCannonsType(GetMainCharacter()) != CANNON_TYPE_NONECANNON)
					Crosshair.OutsideCamera = false;
				else
					Crosshair.OutsideCamera = true;
// <-- KK
				PeopleOnShip.IsOnDeck = 0; //Keemo
				bSwitch = true;
			}
		break;
		case DECK_CAMERA:
			switch (GetTargetPlatform())
			{
				case "xbox": Scene.Camera = SHIP_CAMERA; break;
				case "pc":
					if(!ENABLE_FREE_CAMERA)	Scene.Camera = SHIP_CAMERA;
					else				Scene.Camera = FREE_CAMERA;
				break;
			}
			Crosshair.OutsideCamera = true;
			PeopleOnShip.IsOnDeck = 0;
			bSwitch = true;
		break;
	}
	if (bSwitch) {
		UpdateCamera();
	}
}

void SeaCameras_SetDieCamera()
{
	bool bOldCanSwitchCameras;
	if (Scene.Camera == DECK_CAMERA)
	{
		Crosshair.OutsideCamera = true;
		PeopleOnShip.IsOnDeck = 0;
		SetActiveCamera(SHIP_CAMERA);
	}
}

bool SeaCameras_isCameraOutside()
{
	if (Scene.Camera == SHIP_CAMERA) return true;
	if (Scene.Camera == FREE_CAMERA) return true;
	if (Scene.Camera == DECK_CAMERA) return false;
	return false;
}

void SeaCameras_SetShipForSeaCamera(object Character)
{
	bCameraOnMyShip = IsMainCharacter(&Character); // KK
	makeref(SeaShipCharacterForCamera, Character);
	SendMessage(&SeaShipCamera, "sa", "SetCharacter", SeaShipCharacterForCamera);
	SendMessage(&SeaDeckCamera, "sa", "SetCharacter", SeaShipCharacterForCamera);
	UpdateCamera();
}

// KK -->
void SeaCameras_SetNextShip()
{
	if (Scene.Camera == DECK_CAMERA) return;
	int curchridx = GetCharacterIndex(SeaShipCharacterForCamera.id);
	if (curchridx < 0) return;
	int i = 0;
	while (i < iNumShips) {
		if (Ships[i] == curchridx) break;
		i++;
	}
	i++;
	if (i >= iNumShips) i = 0;
	while (CharacterIsDead(&characters[Ships[i]])) {
		i++;
		if (i >= iNumShips) i = 0;
	}
	SeaCameras_SetShipForSeaCamera(&characters[Ships[i]]);
}

void SeaCameras_SetPreviousShip()
{
	if (Scene.Camera == DECK_CAMERA) return;
	int curchridx = GetCharacterIndex(SeaShipCharacterForCamera.id);
	if (curchridx < 0) return;
	int i = iNumShips - 1;
	while (i >= 0) {
		if (Ships[i] == curchridx) break;
		i--;
	}
	i--;
	if (i < 0) i = iNumShips - 1;
	while (CharacterIsDead(&Characters[Ships[i]])) {
		i--;
		if (i < 0) i = iNumShips - 1;
	}
	SeaCameras_SetShipForSeaCamera(&characters[Ships[i]]);
}

void SeaCameras_SetMyShip()
{
	SeaCameras_SetShipForSeaCamera(GetMainCharacter());
}
// <-- KK
