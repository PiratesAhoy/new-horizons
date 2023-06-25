
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
	SetEventHandler("ExecuteCommand3", "ExecuteCommand3", 0);

	bool in_sailing_mode = bSeaActive;

	SetSelectable("BTN_FREE_CAMERA", in_sailing_mode);
	SetSelectable("BTN_SPAWN_FLEET", in_sailing_mode && iNumShips <= 1);
	SetSelectable("BTN_3", IsNearEnemy());
}

void ProcessCancelExit()
{
	DelEventHandler("EnableFreeCamera", "EnableFreeCamera");
	DelEventHandler("SpawnFleet", "SpawnFleet");
	DelEventHandler("ExecuteCommand3", "ExecuteCommand3");

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

void ExecuteCommand3()
{
	ref PChar = GetMainCharacter();
	ref findCh;
	float radius = 1000.0;
	int num = FindNearCharacters(PChar, radius, -1.0, -1.0, 0.001, false, false);
	for(int j = 0; j < num; j++)	// the following loop runs for each near character
	{
		int cidx = sti(chrFindNearCharacters[j].index);	// defines near character as idx
		if(cidx == PChar.index) continue;
		if(cidx < 0) continue;
		findCh = &characters[cidx];
		if(!LAi_group_IsEnemy(PChar, findCh)) continue;
		Lai_KillCharacter(findCh);
		break;
	}
	if (!IsNearEnemy()) {
		SetSelectable("BTN_3", false);
		ProcessCancelExit();
	}
}

bool IsNearEnemy()
{
	ref PChar = GetMainCharacter();
	int enemy_count = FindNearEnemies(PChar, 1000.0, false);
	return enemy_count > 0;
}
