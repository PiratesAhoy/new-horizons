
void InitInterface(string iniName)
{
	SetTimeScale(0.0);

	EngineLayersOffOn(true);

	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, iniName);

	SetEventHandler("InterfaceBreak", "ProcessCancelExit", 0);
	SetEventHandler("InterfaceCancel", "ProcessCancelExit", 0);
	SetEventHandler("exitCancel", "ProcessCancelExit", 0);

	SetEventHandler("EnableFreeCamera", "EnableFreeCamera", 0);
	SetEventHandler("SpawnFleet", "SpawnFleet", 0);

	bool in_sailing_mode = bSeaActive;

	SetSelectable("BTN_FREE_CAMERA", in_sailing_mode);
	SetSelectable("BTN_SPAWN_FLEET", in_sailing_mode && iNumShips <= 1);
}

void ProcessCancelExit()
{
	DelEventHandler("EnableFreeCamera", "EnableFreeCamera");
	DelEventHandler("SpawnFleet", "SpawnFleet");

	DelEventHandler("InterfaceBreak", "ProcessCancelExit");
	DelEventHandler("InterfaceCancel", "ProcessCancelExit");
	DelEventHandler("exitCancel", "ProcessCancelExit");

	interfaceResultCommand = RC_INTERFACE_DO_NOTHING;

	SetTimeScale(1.0);
	EngineLayersOffOn(false);

	EndCancelInterface(true);
}

void EnableFreeCamera()
{
	SeaCameras.Camera = "SeaFreeCamera";
	SeaCameras_UpdateCamera();

	ProcessCancelExit();
}

void SpawnFleet()
{
	while (iNumShips < MAX_SHIPS_ON_SEA) {
		float ay = 0;
		DirectEncounter(ay);
	}

	ProcessCancelExit();
}
