
void InitInterface(string iniName)
{
	SetTimeScale(0.0);

	EngineLayersOffOn(true);

	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, iniName);

	SetEventHandler("ExecuteCheat", "ExecuteCheat", 0);

	SetEventHandler("InterfaceBreak", "ProcessCancelExit", 0);
	SetEventHandler("InterfaceCancel", "ProcessCancelExit", 0);
	SetEventHandler("exitCancel", "ProcessCancelExit", 0);
}

void ProcessCancelExit()
{
	DelEventHandler("ExecuteCheat", "ExecuteCheat");

	DelEventHandler("InterfaceBreak", "ProcessCancelExit");
	DelEventHandler("InterfaceCancel", "ProcessCancelExit");
	DelEventHandler("exitCancel", "ProcessCancelExit");

	SetTimeScale(1.0);
	EngineLayersOffOn(false);

	EndCancelInterface(true);
}

void ExecuteCheat()
{
	SeaCameras.Camera = "SeaFreeCamera";
	SeaCameras_UpdateCamera();

	ProcessCancelExit();
}
