object Scene;
object FreeCamera;

#define LOCATION_CAMERA "LocationCamera"
#define FREE_CAMERA "FreeCamera"
#define SHIP_CAMERA "SeaShipCamera"
#define DECK_CAMERA "SeaDeckCamera"

string CurrentShipCamera = SHIP_CAMERA;

void UpdateCamera()
{
	aref sceneRef;
	if (!FindEntity(&sceneRef, "Scene") ) {
		CreateEntity(&Scene, "Scene");
		LayerAddObject(EXECUTE, &Scene, 0);
		LayerAddObject(SEA_EXECUTE, &Scene, 0);
	}

	if (IsEntity(&FreeCamera) && Scene.Camera != FREE_CAMERA) {
		DeleteClass(&FreeCamera);
	}

	switch(Scene.camera) {
		case SHIP_CAMERA:
			SendMessage(&Scene, "si", "SetActiveCamera", &SeaShipCamera);
			CurrentShipCamera = SHIP_CAMERA;
		break;
		case FREE_CAMERA:
			if (!IsEntity(&FreeCamera) ) {
				CreateEntity(&FreeCamera, "Free_Camera");
			}
			SendMessage(&Scene, "si", "SetActiveCamera", &FreeCamera);
			CurrentShipCamera = FREE_CAMERA;
		break;
		case DECK_CAMERA:
			SendMessage(&Scene, "si", "SetActiveCamera", &SeaDeckCamera);
			CurrentShipCamera = DECK_CAMERA;
		break;
		// default:
			SendMessage(&Scene, "si", "SetActiveCamera", &locCamera);
		break;
	}
}

void SetActiveCamera(string camera)
{
	Scene.camera = camera;
	UpdateCamera();
}
