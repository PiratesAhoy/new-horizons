// NK note this file is never used...
#include "globals.c"
#include "key_codes.h"
#include "store\goods.h"
#include "store\store.h"
#include "cannon\cannons.h"
#include "ship\ships.h"
#include "character\characters.h"
#include "interface\interface.h"

// include utilites section
#include "store\StoreUtilite.c"
#include "character\CharacterUtilite.c"

extern void InitGoods();
extern void InitStores();
extern void InitBaseCannons();
extern void InitBaseShipsTypes();
extern void InitCharacters();
extern void InitBaseInterfaces();
extern void CreateCharacters();

int bUseMain;
object Screen;

void Main()
{
	LoadSegment("init\initGoods.c");
	InitGoods();
	UnloadSegment("init\initGoods.c");

	LoadSegment("init\initStore.c");
	InitStores();
	UnloadSegment("init\initStore.c");

	LoadSegment("init\initBaseShips.c");
	InitBaseShipsTypes();
	UnloadSegment("init\initBaseShips.c");

	LoadSegment("init\initCharacters.c");
	InitCharacters();
	UnloadSegment("init\initCharacters.c");

	int tmplogs = LogsToggle;
	LogsToggle = LOGS_VERBOSE;

	LoadSegment("characters.c");
	CreateCharacters(); // NK createchar now is (bool). 05-04-07
	UnloadSegment("characters.c");
	LogsToggle = tmplogs;

	LoadSegment("init\BaseInterface.c");
	InitBaseInterfaces();
	UnloadSegment("init\BaseInterface.c");

	ScreenMake();

	bUseMain = TRUE;
	SetEventHandler("key_event","ProcessKeys",1);
}

#include "interface\interface.c"
void ProcessKeys()
{
	if(bUseMain==1000) return;
	if(bUseMain>0)
	{
		bUseMain--;
		return;
	}

	int n;
	float state;
	n = GetEventData();
	state = GetEventData();
	if(state != 0) return;

  switch(n)
  {
	  case BTN_START:
//	LoadSegment("interface\interface.c");
			if( MakeInt(Screen.Active)<STORE_QUANTITY )   LaunchStore(MakeInt(Screen.Active));
			if( MakeInt(Screen.Active)==(STORE_QUANTITY) ) LaunchShipyard();
			if( MakeInt(Screen.Active)==(STORE_QUANTITY+1) ) LaunchCannons();
			if( MakeInt(Screen.Active)==(STORE_QUANTITY+2) ) LaunchCharacter(GetMainCharacter());
			if( MakeInt(Screen.Active)==(STORE_QUANTITY+3) ) LaunchMainMenu();
			if( MakeInt(Screen.Active)==(STORE_QUANTITY+4) ) LaunchShipHold();
			if( MakeInt(Screen.Active)==(STORE_QUANTITY+5) ) LaunchHireCrew();
			bUseMain = 1000;
			Screen.Show = 0;
		break;
    case DPAD_UP:
			if (MakeInt(Screen.Show)>0) {
				if (MakeInt(Screen.Active)>0) {
					Screen.Active = MakeInt(Screen.Active)-1;
				}
			}
		break;
    case DPAD_DOWN:
			if (MakeInt(Screen.Show)>0) {
				if (MakeInt(Screen.Active)<(INTERFACE_QUANTITY-1)) {
					Screen.Active = MakeInt(Screen.Active)+1;
				}
			}
		break;
	}
}

void InterfaceDoExit()
{
//    UnloadSegment("interface\interface.c");
	bUseMain = 3;
	Screen.Show = 1;
}

extern void FillStoreNames();
void ScreenMake()
{
	CreateEntity(&Screen,"scriptscreen");
	Screen.Show = 1;
	Screen.StartLeftPos = 0;
	Screen.StartTopPos = 0;
	Screen.DeltaX = 30;
	Screen.DeltaY = 20;
	Screen.StartItem = 0;
	Screen.ItemQuantity = INTERFACE_QUANTITY;
	Screen.Active = 0;

	LoadSegment("store\storeName.c");
	FillStoreNames();
	UnloadSegment("store\storeName.c");

	int i;
	string attrName;
	for(i=0; i<STORE_QUANTITY; i++)
	{
		attrName = "store"+(i+1);
		Screen.StringsGroup.(attrName) = StoreName[i];
	}

	Screen.StringsGroup.shipyard = "Shipyard";
	Screen.StringsGroup.cannons = "Cannons";
	Screen.StringsGroup.character = "Character";
	Screen.StringsGroup.mainmenu = "Main menu";
	Screen.StringsGroup.Cargo = "Ship Hold";
	Screen.StringsGroup.Hire = "Hire Crew";
}
