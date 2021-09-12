/* TIH -->
	Jul27'06
		Many adjustments to the handling of how much a ship costs. This was a complete mess.
		All costs are figured for tradeHigh in one spot for each type of cost now:
			Sail repair
			Hull repair
			Buy price
			Sell price
		Cargo goods are better handled if replaced ship with one that has smaller hold.

		RPG_STYLE mod:
		To add more fun to the system in regards to people who actually play the game as an rpg game.
		High class ships will not be sold to low level characters. They will gradually increase ability to purchase higher ships.
		Stolen or pirated ships are sold for MUCH less than sticker price.
		Previously bought ships can be sold back for negligable loss in cost (20% hit by default).
		Bought ships are removed from the shipyard list to prevent buying more of same ship (each ship is fairly unique).
		Sold ships are put back into the shipyard for future purchases (or dismissed due to town changes).
TIH <-- */

//Levis for optimalization
#define DEBUG_SHIPYARD_INTERFACE		0	//(bool) set to 1 for debug messages

// KK -->
#define SCREEN_REPAIR         0
#define SCREEN_CANNONS        1
#define SCREEN_SHIPUPGRADE    2
#define SCREEN_APPEARANCE     3

int CurrentScreen = SCREEN_REPAIR;
// <-- KK

#define ISHOW_MODE_VIEW       0
#define ISHOW_MODE_EMPTYVIEW  1
#define ISHOW_MODE_BUY        2
#define ISHOW_MODE_SELL       3
#define ISHOW_MODE_REPAIR     4
#define ISHOW_MODE_COMPANION  5
#define ISHOW_MODE_CHOOSE     6
#define ISHOW_MODE_SKILLS     7

int nShowMode = -1;

int	nCurSScrollNum = -1;
int	nCurFScrollNum = -1;
// KK -->
int nCurCScrollNum = -1;
int nCurSUScrollNum = -1;
int nCurAScrollNum = -1;
// <-- KK
int	nCurFourNum = -1;
aref arCurShip; // PRS3

string OldNodeName = "";
string sLogEntry = "Visited the local shipwright. ";

aref arShipList;

int nAllPassngerQuantity;

int nspRepair;
int nhpRepair;

bool removable = false;

string sPreviouseNode = "";

int nChrIdxForInfo = -1;

// NK -->
int gprice[4];
gprice[0] = -1;
gprice[1] = -1;
gprice[2] = -1;
gprice[3] = -1;
string sTownName = GetCurrentTownID(); // NK 04-09-08 //GetTownIDFromGroup(Stores[GetCharacterCurrentStore(GetMainCharacter())].group);
int nStoreMoney = GetTownGold(sTownName);

ref shipwright;
int daystowait = 0;
// NK <--

// KK -->
string tempship; // MAXIMUS interface MOD
string tempcannon; // MAXIMUS interface MOD
int tmpLangFileID; // MAXIMUS interface MOD
int cannonqtys[4]; // KK
int cannoniqty = 0; // KK
int topay = 0; // KK
// <-- KK

void InitInterface_R(string iniName,ref shipmaster)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("InitIterface_R");
	shipwright = &shipmaster; // NK
// KK -->
	if (!LAi_IsCapturedLocation) {
	  GameInterface.title = "";
		nStoreMoney = GetTownGold(sTownName);
  } else {
  	GameInterface.title = "titleRansack";
  	nStoreMoney = 0;
	}
// <-- KK
	makearef(arShipList,shipmaster.shipyard);

	FillFScroll();
	FillSScroll();
	FillFourImages();

// KK -->
	FillCannonsScroll();
	FillShipUpgradesScroll();
	FillShipAppearanceScroll();
	CurrentScreen = SCREEN_REPAIR;
	ref xi_refCharacter = GetMainCharacter();
	int cnCannonType = GetCaracterShipCannonsType(xi_refCharacter);
	if (cnCannonType != CANNON_TYPE_NONECANNON) {
		int i = 0;
		int j = 0;
		while (i < CANNON_TYPES_QUANTITY) {
			if (GetAttribute(&cannon[i], "TradeOff") == true && !VanderdeckenShipyard()) {
				i++;
				continue;
			}
			string attributeName = "pic" + (i + 1);
			if (CheckAttribute(&GameInterface, "scrollcannons." + attributeName + ".spec2") == true && GameInterface.scrollcannons.(attributeName).spec2 == true) {
				i++;
				continue;
			}
			if (cnCannonType == i) {
				GameInterface.scrollcannons.current = j;
				break;
			}
			i++;
			j++;
		}
	}
	nCurCScrollNum = -1;
	nCurSUScrollNum = -1;
	nCurAScrollNum = -1;
// <-- KK

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

// KK -->
	if (LAi_IsCapturedLocation) {
		//SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "BUY_BUTTON", 0, XI_ConvertString("Take"));
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "SELLSHIP_BUTTON", 0, XI_ConvertString("Leave"));
	}
// <-- KK

	// NK -->
	gprice[0] = -1;
	gprice[1] = -1;
	gprice[2] = -1;
	gprice[3] = -1;
	sTownName = GetCurrentTownID(); // NK 04-09-08 //GetTownIDFromGroup(Stores[GetCharacterCurrentStore(GetMainCharacter())].group);
	//rStoreTown = GetTownFromID(sTownName); // NK, add aref 05-04-15, this particular one 05-04-19.
	//nStoreMoney = GetTownGold(sTownName);
	CreateString(true, "ScreenTitle", "", FONT_TITLE, COLOR_NORMAL, 320, 6, SCRIPT_ALIGN_CENTER, 1.0); // KK
	CreateString(true,"Money",MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,175,409,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"SMoney",MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,465,409,SCRIPT_ALIGN_RIGHT,1.0);
	//CreateString(true,"Store",Stores[GetCharacterCurrentStore(GetMainCharacter())].group + ":",FONT_NORMAL,COLOR_MONEY,320,436,SCRIPT_ALIGN_CENTER,1.0);
	// NK -->
	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,195,SCRIPT_ALIGN_CENTER,1.0);

	// changed by KAM -->
	CreateString(true,"ShipClass","",FONT_NORMAL,COLOR_NORMAL,208,236,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"HullPoints","",FONT_NORMAL,COLOR_NORMAL,208,270,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Speed","",FONT_NORMAL,COLOR_NORMAL,208,304,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Maneuver","",FONT_NORMAL,COLOR_NORMAL,208,338,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Capacity","",FONT_NORMAL,COLOR_NORMAL,208,372,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MaxCrew","",FONT_NORMAL,COLOR_NORMAL,336,236,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MinCrew","",FONT_NORMAL,COLOR_NORMAL,336,270,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"CannonsQuantity","",FONT_NORMAL,COLOR_NORMAL,336,304,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MaxCaliber","",FONT_NORMAL,COLOR_NORMAL,336,338,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipCost","",FONT_NORMAL,COLOR_NORMAL,336,372,SCRIPT_ALIGN_LEFT,1.0);
	// <-- changed by KAM

	// TIH --> rpg_style
	CreateString(false,"NoBuyString","",FONT_NORMAL,COLOR_NORMAL,320,176,SCRIPT_ALIGN_CENTER,0.5);
	SetNodeUsing("NOBUYBOX1",false);
	SetNodeUsing("NOBUYBOX2",false);
	// TIH <--

	CreateString(false,"RepairAllCost","",FONT_NORMAL,COLOR_NORMAL,366,238,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"HullPercent","",FONT_NORMAL,COLOR_NORMAL,320,282,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"RepairHullCost","",FONT_NORMAL,COLOR_NORMAL,426,282,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"SailsPercent","",FONT_NORMAL,COLOR_NORMAL,320,326,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"RepairSailsCost","",FONT_NORMAL,COLOR_NORMAL,426,326,SCRIPT_ALIGN_LEFT,1.0);

	CreateString(false,"TradePrice","",FONT_NORMAL,COLOR_NORMAL,320,255,SCRIPT_ALIGN_LEFT,1.0);

	CreateString(false,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,320,200,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,368,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,368,SCRIPT_ALIGN_RIGHT,1.0);

//	CreateString(true,"Money",MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"","."),FONT_NORMAL,COLOR_MONEY,320,385,SCRIPT_ALIGN_CENTER,1.0);
	//CreateString(false,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,181,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"FireRange","",FONT_NORMAL,COLOR_NORMAL,400,226,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(false,"ReloadTime","",FONT_NORMAL,COLOR_NORMAL,400,246,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(false,"Gunpowder","",FONT_NORMAL,COLOR_NORMAL,400,266,SCRIPT_ALIGN_RIGHT,0.8);
	SetNodeUsing("CANNONPOWDER_STRINGS",false);
	CreateString(false,"CostFullLabel", "", FONT_NORMAL, COLOR_NORMAL, 170, 291, SCRIPT_ALIGN_LEFT, 0.8); // KK
	CreateString(false,"Cost","",FONT_NORMAL,COLOR_NORMAL,400,291,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(false,"CostUnit","",FONT_NORMAL,COLOR_NORMAL,400,316,SCRIPT_ALIGN_RIGHT,0.8); // MAXIMUS cannons MOD
	CreateString(false,"CannonWeight","",FONT_NORMAL,COLOR_NORMAL,400,336,SCRIPT_ALIGN_RIGHT,0.8); // PB: Cannon Weight
	// KK CreateString(true,"BuyQuantity","",FONT_NORMAL,COLOR_NORMAL,320,352,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS cannons MOD
	// KK CreateString(true,"RepairCannonsCost","",FONT_NORMAL,COLOR_NORMAL,426,282,SCRIPT_ALIGN_LEFT,1.0); // MAXIMUS cannons MOD
	CreateString(false,"HelpString","",FONT_NORMAL,COLOR_NORMAL,320,445,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD
	CreateString(false,"Installed","",FONT_NORMAL,COLOR_NORMAL,320,480,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD
	CreateString(false,"Installed_1","",FONT_NORMAL,COLOR_NORMAL,320,500,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD

// KK -->
	//CreateString(false, "ShipUpgradeName", "", FONT_NORMAL, COLOR_NORMAL, 320, 220, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(false, "ShipUpgradeTime", "", FONT_NORMAL, COLOR_NORMAL, 400, 270, SCRIPT_ALIGN_RIGHT, 0.8);
	CreateString(false, "ShipUpgradeOrRepaintCost", "", FONT_NORMAL, COLOR_NORMAL, 400, 315, SCRIPT_ALIGN_RIGHT, 0.8);
// KK <--
	SetSelectable("EXIT_BUTTON",true);

	ProcessFrame();
	SetNodeUsing("BOX",false);
	SetNodeUsing("BOX_RAMKA", false); // KK
	SetRepairData();
	ChangeScroll();// TIH cannon selection visual adjustment Jul12'06

// MAXIMUS cannons MOD -->
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REPAIR_YES_BUTTON",false);
	SetNodeUsing("REPAIR_NO_BUTTON",false);
	SetNewPicture("CAN_PIC", "interfaces\cannon.tga");
	SetNewPicture("CAN_PIC1", "interfaces\cannon.tga");
	SetNewPicture("CAN_PIC2", "interfaces\cannon.tga");
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);
// MAXIMUS cannons MOD <--

// KK -->
	SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
	SetNodeUsing("CANNONS_BUY_BUTTON", false);
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	SetNodeUsing("BACKCANNONSQTY", false);
	
	CreateString(false, "front_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 364, 233, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "leftarc_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 299, 272, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "rightarc_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 429, 272, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "back_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 364, 311, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "cannons_cost", "0", FONT_NORMAL, COLOR_NORMAL, 234, 360, SCRIPT_ALIGN_RIGHT, 0.8);

	SetScreen(SCREEN_REPAIR);
// <-- KK

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// KK -->
	/*SetEventHandler("MaxShipClassYes", "CheckMaxShipClassYes", 0);
	SetEventHandler("MaxShipClassNo", "CheckMaxShipClassNo", 0);
	SetEventHandler("FleetLevelYes", "CheckFleetLevelYes", 0);
	SetEventHandler("FleetLevelNo", "CheckFleetLevelNo", 0);*/
	SetEventHandler("InstallPress","ProcessInstall",0);
	//SetEventHandler("BuyPress","ProcessBuy",0);
//	SetEventHandler("InstallBuyPress","ProcessInstallAndBuy",0); // KK // LDH commented out as it was being called extra times - 09Feb09
	SetEventHandler("installSelect","ProcessInstallSelect",0);
	SetEventHandler("InstallSUPress", "ProcessInstallSU", 0);
	SetEventHandler("RepaintPress", "ProcessRepaint", 0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// MAXIMUS cannons MOD -->
	SetEventHandler("CancelPress","ProcessCancel",0);
	//SetEventHandler("RepairNo","ProcessRepair_no",0);
	//SetEventHandler("RepairYes","ProcessRepair_yes",0);
	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
// MAXIMUS cannons MOD <--
// <-- KK
}

void ProcessExit()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessExit");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if (cn < 0) return;

// KK -->
//		int Qty = GetCannonCurQuantity(GetCharacter(cn));
//		int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);
	bool temp = true;
	temp = temp && (cannonqtys[0] != GetCannonArcQty(GetCharacter(cn), 0));
	temp = temp && (cannonqtys[1] != GetCannonArcQty(GetCharacter(cn), 1));
	temp = temp && (cannonqtys[2] != GetCannonArcQty(GetCharacter(cn), 2));
	temp = temp && (cannonqtys[3] != GetCannonArcQty(GetCharacter(cn), 3));
// <-- KK

	if (!temp) { // KK
		DelEventHandler("InterfaceBreak","ProcessCancelExit");
		DelEventHandler("frame","ProcessFrame");
		DelEventHandler("exitCancel","ProcessCancelExit");
		DelEventHandler("ievnt_command","ProcessCommandExecute");
		/*DelEventHandler("MaxShipClassYes", "CheckMaxShipClassYes");
		DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
		DelEventHandler("FleetLevelYes", "CheckFleetLevelYes");
		DelEventHandler("FleetLevelNo", "CheckFleetLevelNo");*/
		DelEventHandler("InstallPress","ProcessInstall");
		//DelEventHandler("BuyPress","ProcessBuy"); // KK
//   		DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
		DelEventHandler("installSelect","ProcessInstallSelect");
		DelEventHandler("InstallSUPress", "ProcessInstallSU"); // KK
		DelEventHandler("RepaintPress", "ProcessRepaint"); // KK
		DelEventHandler("ievnt_command","ProcessCommandExecute");
		DelEventHandler("CancelPress","ProcessCancel");
		//DelEventHandler("RepairNo","ProcessRepair_no");
		//DelEventHandler("RepairYes","ProcessRepair_yes");
		DelEventHandler("ExitPress","ProcessExit");
		DelEventHandler("ExitNo","ProcessExit_no");
		DelEventHandler("ExitYes","ProcessExit_yes");

		interfaceResultCommand = RC_INTERFACE_SHIPYARD_EXIT;
		EndCancelInterface(true);
	} else {
		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("REPAIR_YES_BUTTON",true);
		SetNodeUsing("REPAIR_NO_BUTTON",true);
		SetNodeUsing("CAN_PIC1",true);
		SetNodeUsing("CAN_PIC2",true);
		SetCurrentNode("REPAIR_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "REPAIR_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "REPAIR_YES_BUTTON");

		SetFormatedText("TEXTWINDOW", TranslateString("", "Exit from cannons confirm"));
	}
}

void ProcessCancelExit()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessCancelExit");
	// NK -->
	if(nStoreMoney < 0) nStoreMoney = 0;
	if (!LAi_IsCapturedLocation) SetTownGold(sTownName, nStoreMoney); // KK
	gprice[0] = -1;
	gprice[1] = -1;
	gprice[2] = -1;
	gprice[3] = -1;
	// NK <--
	WriteNewLogEntry("Visited "+FindTownName(GetCurrentTownID()),sLogEntry,"Ship",true);
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
// KK -->
	/*DelEventHandler("MaxShipClassYes", "CheckMaxShipClassYes");
	DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
	DelEventHandler("FleetLevelYes", "CheckFleetLevelYes");
	DelEventHandler("FleetLevelNo", "CheckFleetLevelNo");*/
	DelEventHandler("InstallPress","ProcessInstall");
	//DelEventHandler("BuyPress","ProcessBuy"); // KK
//	DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
	DelEventHandler("installSelect","ProcessInstallSelect");
	DelEventHandler("InstallSUPress", "ProcessInstallSU"); // KK
	DelEventHandler("RepaintPress", "ProcessRepaint"); // KK
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("CancelPress","ProcessCancel");
	//DelEventHandler("RepairNo","ProcessRepair_no");
	//DelEventHandler("RepairYes","ProcessRepair_yes");
	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");
// <-- KK

	DoShipParametersClamp();

	interfaceResultCommand = RC_INTERFACE_SHIPYARD_EXIT;
	if(daystowait > 0) // NK do day-waiting after everything 05-07-08
	{
		WaitDate("", 0, 0, daystowait, 0, 0);
		PlaySound("ambient\shipyard\axe.wav");	//just earcandy :)
		PlaySound("ambient\shipyard\vehicle.wav");
		Log_SetStringToLog(TranslateString("", "Repairs are completed") + " " + daystowait + " " + XI_ConvertString("day") + stringret(daystowait > 1, XI_ConvertString("s"),"") + " " + LanguageConvertString(tmpLangFileID,"later."));
		LogIt(XI_ConvertString("Time") + ": " + GetStringTime(GetTime()));		// LDH 15Oct06 added time display
	}
	// NK <--
	EndCancelInterface(true);
	BLI_UpdateOfficers(); // KK
	if(tradeHigh==true) tradeHigh = false; // added by MAXIMUS [possibility to repair your ship by double price]
	if(CheckAttribute(GetMainCharacter(),"gained_repair_hull")) DeleteAttribute(GetMainCharacter(),"gained_repair_hull");
	if(CheckAttribute(GetMainCharacter(),"gained_repair_sail")) DeleteAttribute(GetMainCharacter(),"gained_repair_sail");
	if(CheckAttribute(GetMainCharacter(),"gained_repair_cannon")) DeleteAttribute(GetMainCharacter(),"gained_repair_cannon");
}

void ProcessExit_no()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessExit_no");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("REPAIR_YES_BUTTON",false);
	SetNodeUsing("REPAIR_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("CANNONSQUANTITY");
}

void ProcessExit_yes()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessExit_yes");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int Qty = GetCannonCurQuantity(GetCharacter(cn));
	int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);

	if(curQty>0)
	{
		ref curChr = GetCharacter(cn);
		int ourQty = 0;

		ourQty = sti(curChr.ship.Cannons.Borts.cannonf.curqty);
		curChr.ship.Cannons.Borts.cannonf.qty = ourQty;

		ourQty = sti(curChr.ship.Cannons.Borts.cannonb.curqty);
		curChr.ship.Cannons.Borts.cannonb.qty = ourQty;

		ourQty = sti(curChr.ship.Cannons.Borts.cannonl.curqty);
		curChr.ship.Cannons.Borts.cannonl.qty = ourQty;

		ourQty = sti(curChr.ship.Cannons.Borts.cannonr.curqty);
		curChr.ship.Cannons.Borts.cannonr.qty = ourQty;
	}
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	/*DelEventHandler("MaxShipClassYes", "CheckMaxShipClassYes");
	DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
	DelEventHandler("FleetLevelYes", "CheckFleetLevelYes");
	DelEventHandler("FleetLevelNo", "CheckFleetLevelNo");*/
	DelEventHandler("InstallPress","ProcessInstall");
	//DelEventHandler("BuyPress","ProcessBuy"); // KK
//	DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
	DelEventHandler("installSelect","ProcessInstallSelect");
	DelEventHandler("InstallSUPress", "ProcessInstallSU"); // KK
	DelEventHandler("RepaintPress", "ProcessRepaint"); // KK
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("CancelPress","ProcessCancel");
	//DelEventHandler("RepairNo","ProcessRepair_no");
	//DelEventHandler("RepairYes","ProcessRepair_yes");
	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");

	interfaceResultCommand = RC_INTERFACE_SHIPYARD_EXIT;
	EndCancelInterface(true);
	if(tradeHigh==true) tradeHigh = false; // added by MAXIMUS [possibility to repair your ship by double price]
}

void ProcessRepair_no()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessRepair_no");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("CANNONSQUANTITY");
}

void ProcessRepair_yes()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessRepair_yes");
	EnableString("Installed");
	EnableString("Installed_1");
	int ct = CANNON_TYPE_NONECANNON;
	tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return;
	ct = GetChoosedCannonType(); // KK

	ref curChr = GetCharacter(cn);
	int Qty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3]; // KK GetCannonCurQuantity(curChr);
	int curQty = sti(GetCannonQuantity(curChr)-Qty);
	int newQty = sti(GetMaxCannonQuantity(curChr)-GetCannonQuantity(curChr));
	int cost = BuyCannons(cn, GetChoosedCannonType(), curQty);

	AddMoneyToCharacter( GetMainCharacter(), 0 - cost );
	sLogEntry += "The shipwright agreed to repair the '"+curChr.ship.name+"' for the amount of "+cost+" pieces of gold. ";
	SetCharacterCannonType(curChr, GetChoosedCannonType());
	//MAXIMUS -->
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(GetMainCharacter(), "Repair", makeint(cost/sti(GetCannonCaliber(GetChoosedCannonType())*2)));
	}
	//MAXIMUS <--

  // KK int ourQty = 0;
  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonf.qty);
  curChr.ship.Cannons.Borts.cannonf.curqty = cannonqtys[0]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonb.qty);
  curChr.ship.Cannons.Borts.cannonb.curqty = cannonqtys[1]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonl.qty);
  curChr.ship.Cannons.Borts.cannonl.curqty = cannonqtys[2]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonr.qty);
  curChr.ship.Cannons.Borts.cannonr.curqty = cannonqtys[3]; // ourQty;

	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"",".");
	nCurCScrollNum = -1;

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("SCROLLCANNONS");

	SetNodeUsing("BOX",true);
	SetNodeUsing("BOX_RAMKA", true);
	SetNodeUsing("BOX1",true);
	SetNodeUsing("BOX1_RAMKA", true);

	GameInterface.strings.Installed = GetCannonName(ct) + " - " + curQty + XI_ConvertString("un") + ". " + " " + LanguageConvertString(tmpLangFileID,"have been installed");
	GameInterface.strings.Installed_1 = LanguageConvertString(tmpLangFileID,"on to the ship") + " " + GetCharShipName(GetCharacter(cn)) + "!";
	SetSelectable("INSTALL_BUTTON", false);
	SetSelectable("INSTALLBUY_BUTTON", false);
}

void ProcessFrame()
{
	//if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame");
	int cn;
	switch (CurrentScreen)
	{
		case SCREEN_REPAIR:
			//if(DEBUG_SHIPYARD_INTERFACE) trace("CASE: SCREEN_REPAIR");
			if(OldNodeName!=GetCurrentNode())
			{
				if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame: first switch");
				OldNodeName = GetCurrentNode();
				switch(OldNodeName)
				{
				case "SHIPSLIST":	nCurFourNum=-1; break;
				case "SCROLLITEMS":	nCurSScrollNum=-1; break;
				case "PASSENGERS":	nCurFScrollNum=-1; break;
				}
			}
			if(nCurFScrollNum!=sti(GameInterface.passengers.current))
			{
				if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame: first if");
				nCurFScrollNum = sti(GameInterface.passengers.current);
				UpdateFScrollData();
			}
			if(nCurSScrollNum!=sti(GameInterface.scrollitems.current))
			{
				if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame: second if");
				nCurSScrollNum = sti(GameInterface.scrollitems.current);
				UpdateSScrollData();
			}
			if(nCurFourNum!=sti(GameInterface.FourImage.current))
			{
				if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame: third if");
				nCurFourNum = sti(GameInterface.FourImage.current);
				UpdateFourData();
			}
		break;

		case SCREEN_CANNONS:
			//if(DEBUG_SHIPYARD_INTERFACE) trace("CASE: SCREEN_CANNONS");
			if(sti(GameInterface.scrollcannons.current)!=nCurCScrollNum)
			{
				nCurCScrollNum = sti(GameInterface.scrollcannons.current);
				ref rcann = GetCannonByType(GetChoosedCannonType());
				GameInterface.strings.FireRange = sti(rcann.FireRange)/3;	// LDH change feet to yards
				GameInterface.strings.ReloadTime = sti(rcann.ReloadTime);
				GameInterface.strings.Gunpowder = sti(rcann.Gunpowder);
				nCurFourNum = -1;
				EnableString("HelpString");
				SetNodeUsing("BOX1",true);
				SetNodeUsing("BOX1_RAMKA", true);
			}

			//int canbuymax = GetCanBuyQuantity(); //Levis shipyard optimalization, removed this because it wasn't used and called each ms
			//if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessFrame: canbuymax="+canbuymax);

			if(sti(GameInterface.FourImage.current)!=nCurFourNum)
			{
				nCurFourNum = sti(GameInterface.FourImage.current);
				//ref rcn = GetCannonByType(GetChoosedCannonType());
				EnableString("Installed");
				EnableString("Installed_1");
				ref refMyCh = GetMainCharacter();
				cn = GetCompanionIndex(refMyCh,nCurFourNum);
				if (cn==-1 || GetCharacterShipType(GetCharacter(cn)) == SHIP_NOTUSED) {
					SetSelectable("CANNONS_BUY_BUTTON",false);
					GameInterface.strings.ShipName = "";
					GameInterface.strings.Cost = "0";
				} else {
// KK -->
					cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
					cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
					cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
					cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
					cannoniqty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
					GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn));
// <-- KK

				// PB: Price calculation fixed -->
					topay = 0;
					int char_can = GetCaracterShipCannonsType(GetCharacter(cn));
					int sel_can = GetChoosedCannonType();
					if (char_can == sel_can)
					{
						GameInterface.strings.CostFullLabel = XI_ConvertString("CostFull") + " (" + sti(GetMaxCannonQuantity(GetCharacter(cn))-GetCannonQuantity(GetCharacter(cn))) +" "+ XI_ConvertString("un")+")"; // KK
						topay = BuyCannons(GetCharacter(cn), sel_can, GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn)));
					}
					else
					{
						GameInterface.strings.CostFullLabel = XI_ConvertString("CostFull") + " (" + GetMaxCannonQuantity(GetCharacter(cn)) +" "+ XI_ConvertString("un")+")"; // KK
						topay = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)));
						topay += BuyCannons(GetCharacter(cn), sel_can, GetMaxCannonQuantity(GetCharacter(cn)));
					}

					GameInterface.strings.Cost = topay;
					GameInterface.strings.CostUnit = BuyCannons(GetCharacter(cn), sel_can,1);
					GameInterface.strings.CannonWeight = GetCannonWeight(sel_can);
					DisableString("HelpString");
					SetNodeUsing("BOX1",false);
					SetNodeUsing("BOX1_RAMKA", false);
				}
				// PB: Price calculation fixed <--

				int isSelectable = CheckInstallEnable();
				SetSelectable("INSTALL_BUTTON",    isSelectable >  0);
				SetSelectable("INSTALLBUY_BUTTON", isSelectable == 2);
				// Screwface : You shouldn't be allowed to click on repair cannon button if you scroll other cannon types than YOURS
				// Otherwise the game allow you to change all your cannon set caliber by repairing a cannon with an other type and that's not good !!!
				if(GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType() && GetCaracterShipCannonsType(GetCharacter(cn)) != CANNON_TYPE_NONECANNON)
					SetSelectable("INSTALL_BUTTON", false);

				ChangeScroll();// TIH cannon selection visual adjustment Jul12'06
			}
		break;

		case SCREEN_SHIPUPGRADE:
			//if(DEBUG_SHIPYARD_INTERFACE) trace("CASE: SCREEN_SHIPUPGRADE");
			// Screwface
			if(nCurFourNum!=sti(GameInterface.FourImage.current))
			{
				nCurFourNum = sti(GameInterface.FourImage.current);
				cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum); // Screwface
				if (cn!=-1 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED)
				{
					FillShipUpgradesScroll();
					GameInterface.scrollshipupgrades.current = nCurSUScrollNum;
					SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "scrollshipupgrades", nCurSUScrollNum);
					SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "scrollshipupgrades");
					SetCurrentNode("scrollshipupgrades");
					RefreshScreen();
					GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn));
				}
			}
			// Screwface : end
			if (sti(GameInterface.scrollshipupgrades.current) != nCurSUScrollNum) {
				nCurSUScrollNum = sti(GameInterface.scrollshipupgrades.current);
				RefreshScreen();
			}
		break;

		case SCREEN_APPEARANCE:
			//if(DEBUG_SHIPYARD_INTERFACE) trace("CASE: SCREEN_APPEARANCE");
			if(nCurFourNum!=sti(GameInterface.FourImage.current))
			{
				nCurFourNum = sti(GameInterface.FourImage.current);
				cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum); // Screwface
				if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED)
				{
					FillShipAppearanceScroll();
					GameInterface.scrollshipappearance.current = nCurSUScrollNum; //sti(GameInterface.scrollshipappearance.current) + 1;
					SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "scrollshipappearance", nCurSUScrollNum);
					SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "scrollshipappearance");
					SetCurrentNode("scrollshipappearance");
					RefreshScreen();
					GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn));
				}
			}
			if (sti(GameInterface.scrollshipappearance.current) != nCurAScrollNum) {
				nCurAScrollNum = sti(GameInterface.scrollshipappearance.current);
				RefreshScreen();
			}
		break;
	}
}

void UpdateFourData()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateFourData");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	SetCharacterToInfoCharacter(cn);
	removable = true;
	if(cn<0)
	{
		if(nAllPassngerQuantity>0)
		{
			SetShowMode(ISHOW_MODE_COMPANION);
			SetCaptainButtonsEnable();
		}
		else
		{
			SetShowMode(ISHOW_MODE_EMPTYVIEW);
		}
		GameInterface.strings.ShipName = "";
	}
	else
	{
		removable = GetRemovable(GetCharacter(cn));
		if(CheckAttribute(GetCharacter(cn),"ship.name"))
		{
			GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn));
		}
		else
		{
			GameInterface.strings.ShipName = "";
		}
		if (GetCharacterShipType(GetCharacter(cn)) == SHIP_NOTUSED) // KK
		{
			SetShowMode(ISHOW_MODE_EMPTYVIEW);
		}
		else
		{
			SetShowMode(ISHOW_MODE_VIEW);
			makearef(arCurShip, Characters[cn].ship); // PRS3
			SetViewShipData(cn, GetSellPrice(nCurFourNum,"skipcargo"), 0); // TIH added handler Jul27'06 // PW: now "skipcargo"
		}
	}
}

void UpdateFScrollData()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateFScrollData");
	if(nAllPassngerQuantity<=0) return;
	SetCharacterToInfoCharacter( GetPassengerFromScroll(nCurFScrollNum) );
	SetShowMode(ISHOW_MODE_COMPANION);
	SetCaptainButtonsEnable();
}

void SetRepairData()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetRepairData");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if (cn < 0) return; // KK
	ref chref = GetCharacter(cn);
	int st = GetCharacterShipType(chref);
	makearef(arCurShip, chref.ship); // PRS3

	int hp = MakeInt(GetHullPercent(chref));
	int sp = MakeInt(GetSailPercent(chref));

	// TIH --> handled properly now  Jul27'06
	int hcost = GetHullRepairCost(chref, GetHullDamagePercent(nCurFourNum)); // KK
	int scost = GetSailRepairCost(chref, GetSailDamagePercent(nCurFourNum)); // KK
	int gcost = BuyCannons(chref, sti(chref.ship.cannons.type), GetCannonMaxQuantity(chref) - GetCannonQuantity(chref)); // PB
	// TIH <--

    GameInterface.strings.HullPercent = hp + "%";
    GameInterface.strings.SailsPercent = sp + "%";
    GameInterface.strings.RepairHullCost = hcost;
    GameInterface.strings.RepairSailsCost = scost;
    GameInterface.strings.RepairAllCost = MakeMoneyShow(hcost + scost + gcost,MONEY_SIGN,MONEY_DELIVER); // NK

	nhpRepair = hp;
	nspRepair = sp;
	SetRepairButtonSelected();
}

void SetRepairButtonSelected()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetRepairButtonSelected");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if (cn < 0) return; // KK
	ref chref = GetCharacter(cn);
	int st = GetCharacterShipType(chref);
	makearef(arCurShip, chref.ship); // PRS3

	int hp = MakeInt(GetHullPercent(chref));
	int sp = MakeInt(GetSailPercent(chref));

	// TIH --> handled properly now Jul27'06
	int hcost = GetHullRepairCost(chref, GetHullDamagePercent(nCurFourNum)); // KK
	int scost = GetSailRepairCost(chref, GetSailDamagePercent(nCurFourNum)); // KK
	int gcost = BuyCannons(chref, sti(chref.ship.cannons.type), GetCannonMaxQuantity(chref) - GetCannonQuantity(chref)); // PB
	// TIH <--

	SetSelectable("FIXALL_BUTTON",hp<100 || sp<100 || gcost>0);	// LDH 27Sep06
	SetSelectable("HULLQUANTITY",hp<100);
	SetSelectable("SAILSQUANTITY",sp<100);
	SetSelectable("REPAIR_OK",nhpRepair>hp || nspRepair>sp || gcost>0);	// LDH 27Sep06

	int color = COLOR_DESELECT;
	if(hp<100)	color = COLOR_NORMAL;
	GameInterface.strings.HullPercent = hp+"%";
//    CreateString(true,"HullPercent",hp+"%",FONT_NORMAL,color,320,282,SCRIPT_ALIGN_CENTER,1.0); // removed by MAXIMUS
	color = COLOR_DESELECT;
	if(sp<100)	color = COLOR_NORMAL;
	GameInterface.strings.SailsPercent = sp+"%";
//    CreateString(true,"SailsPercent",sp+"%",FONT_NORMAL,color,320,326,SCRIPT_ALIGN_CENTER,1.0); // removed by MAXIMUS

	string curNod = GetCurrentNode();
	if( curNod=="FIXALL_BUTTON" || curNod=="HULLQUANTITY" ||
		curNod=="SAILSQUANTITY" || curNod=="REPAIR_OK" )
	{
		Event("ievnt_command","ss","downstep",curNod);
	}
}

void SetViewShipData(int cn, int buyPrice, int Reduction) // modded to PRS3, adding the aref.
{
	//Levis define shipcost
	int shipCost = buyPrice - Reduction;
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetViewShipData");
// KK -->
	int tempnation = UNKNOWN_NATION;
	int shipType = -1;
	if (cn < 0)
		shipType = GetScrollShipType(nCurSScrollNum);
	else
		shipType = GetCharacterShipType(GetCharacter(cn));
// <-- KK
	ref shref = GetShipByType(shipType);

	GameInterface.strings.ShipClass       = sti(GetLocalShipAttrib(arCurShip, shref, "Class"));
	GameInterface.strings.HullPoints      = sti(GetLocalShipAttrib(arCurShip, shref, "HP"));
	GameInterface.strings.Speed           = FloatToString(stf(GetLocalShipAttrib(arCurShip, shref, "SpeedRate")),2);
	GameInterface.strings.Maneuver        = FloatToString(stf(GetLocalShipAttrib(arCurShip, shref, "TurnRate")),2);
	GameInterface.strings.Capacity        = sti(GetLocalShipAttrib(arCurShip, shref, "Capacity"));
	GameInterface.strings.MaxCrew         = sti(GetLocalShipAttrib(arCurShip, shref, "MaxCrew"));
	GameInterface.strings.MinCrew         = sti(GetLocalShipAttrib(arCurShip, shref, "MinCrew"));
	GameInterface.strings.CannonsQuantity = sti(GetLocalShipAttrib(arCurShip, shref, "CurCanQty")); //NK can qty 05-04-18 "CannonsQuantity"));
	GameInterface.strings.MaxCaliber      = sti(GetLocalShipAttrib(arCurShip, shref, "MaxCaliber"));
	GameInterface.strings.ShipCost        = MakeMoneyShow(shipCost,MONEY_SIGN,MONEY_DELIVER);
	if (CheckShipAttribute(arCurShip, shref, "Nation")) tempnation = GetLocalShipAttrib(arCurShip, shref, "Nation"); // PB

	bool hideNoBuy = true;
	// TIH --> rpg_style Jul27'06
	DisableString("NoBuyString");
	//SetNodeUsing("NOBUYBOX1",false);
	SetNodeUsing("NOBUYBOX2",false);
	GameInterface.strings.NoBuyString = "";
	if ( SY_RPG_STYLE ) {
		string attributeName = "pic" + (nCurSScrollNum+1);
		if ( CheckAttribute(GameInterface,"scrollitems."+(attributeName)+".skipsell") && GameInterface.scrollitems.(attributeName).skipsell==true ) {
			hideNoBuy = false;
			EnableString("NoBuyString");
			//SetNodeUsing("NOBUYBOX1",true);
			SetNodeUsing("NOBUYBOX2",true);
			// PB: Realistic Ship Purchase -->
			if( CheckAttribute(GameInterface,"scrollitems."+(attributeName)+".pirateship") && GameInterface.scrollitems.(attributeName).pirateship==true )
			{GameInterface.strings.NoBuyString = XI_ConvertString("Cannot Buy - Pirate Ship");}
			else
			{
				if( CheckAttribute(GameInterface,"scrollitems."+(attributeName)+".navyship") && GameInterface.scrollitems.(attributeName).navyship==true )
				{GameInterface.strings.NoBuyString = XI_ConvertString("Cannot Buy - Rank Too Low");}
				else
				{GameInterface.strings.NoBuyString = XI_ConvertString("Cannot Buy - Tier Too High");}
			}
			// PB: Realistic Ship Purchase <--
		}
	}
	
	//Levis: contraband checking
	if(nCurFourNum > -1)
	{
		if(cn > -1)
		{
			if(CheckForContraband(GetCharacter(cn)))
			{
				EnableString("NoBuyString");
				SetNodeUsing("NOBUYBOX2", true);
				GameInterface.strings.NoBuyString = "Cannot Buy - Contraband on board";
			}
		}
	}

	if(hideNoBuy)
	{
		//Levis shipyard optimalization added cost here so it doesn't have to be calculated again
		int buyEnable = IsMoneyForBuyEnable(buyPrice,Reduction);
		if(buyEnable > 0)
		{
			EnableString("NoBuyString");
			//SetNodeUsing("NOBUYBOX1", true);
			SetNodeUsing("NOBUYBOX2", true);
			if(buyEnable == 1)
				GameInterface.strings.NoBuyString = XI_ConvertString("Cannot Buy - Too expensive");
			else
				GameInterface.strings.NoBuyString = XI_ConvertString("Shipyard cannot afford your ship");
		}
	}

	// TIH <--

// KK -->
	if (tempnation >= 0 && tempnation < NATIONS_QUANTITY) {
		SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(tempnation) + ".tga");
		SetFormatedText("NATIONALDESIGN", XI_ConvertString("2"+Nations[tempnation].desc) + " " + XI_ConvertString("design"));
	} else {
		if(tempnation == PERSONAL_NATION)
		{
			SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(tempnation) + ".tga");
			SetFormatedText("NATIONALDESIGN", XI_ConvertString("Personal") + " " + XI_ConvertString("design"));
		}
		else
		{
			SetNewPicture("NATION", "interfaces\flags\Crest_Neutral.tga");
			SetFormatedText("NATIONALDESIGN", "Made in Singapore"); // PB: Was XI_ConvertString("Individual design")
		}
	}

	for (int i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
		string upgrade_group = "SHIP_UPGRADES";
		string upgrade = GetShipUpgradeID(i);
		bool hastun = false;
		if(GetCurrentNode() == "SHIPSLIST" && CheckTun(cn, upgrade)) hastun = true;
		aref tShip = GetScrollShipAttr(nCurSScrollNum);
		if(GetCurrentNode() != "SHIPSLIST" && CheckAttribute(tShip, "tune." + upgrade + ".on"))
		{
			if(tShip.tune.(upgrade).on == "1") hastun = true;
		}
		if(!hastun)
		{
			if (bNewInterface)
				upgrade_group = "ICONS_NEW";
			else
				upgrade_group = "ICONS";
			upgrade = "empty";
		}
		int shftx = 32 * makeint(2.0 * fmod(makefloat(i) * 2, 2.0));
		if (i >= (SHIPUPGRADES_QUANTITY / 2)) shftx += 32;
		int shfty = 30 * makeint(4.0 * fmod(makefloat(i), 4.0));
		CreateImage("Upgrade" + i + "_Picture", upgrade_group, upgrade, 428 + shftx, 285 + shfty, 458 + shftx, 313 + shfty);
	}
// <-- KK
}

void UpdateSScrollData()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateSScrollData");
	//unneeded, modified above func. makearef(arCurShip, GetScrollShipAttr(nCurSScrollNum)); // PRS3
	if (GetScrollShipType(nCurSScrollNum) == SHIP_NOTUSED) // KK
	{
		SetShowMode(ISHOW_MODE_EMPTYVIEW);
	}
	else
	{
		SetShowMode(ISHOW_MODE_VIEW);
		SetViewShipData(-1, GetBuyPrice(nCurSScrollNum) , GetSellPrice(nCurFourNum,"skipcargo"));
	}
}

void SetCurrentRepairButton()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetCurrentRepairButton");
	if(GetSelectable("FIXALL_BUTTON"))
	{
		SetCurrentNode("FIXALL_BUTTON");
	}
}

void AddCannon(string arcname)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("AddCannon");
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	int arc = 0;
	switch (arcname)
	{
		case "front_cannons_qty":
			arc = 0;
		break;
		case "rightarc_cannons_qty":
			arc = 1;
		break;
		case "back_cannons_qty":
			arc = 2;
		break;
		case "leftarc_cannons_qty":
			arc = 3;
		break;
	}

	int n = sti(GameInterface.strings.(arcname)) + 1;
	int total = sti(GameInterface.strings.front_cannons_qty) + sti(GameInterface.strings.rightarc_cannons_qty) + sti(GameInterface.strings.back_cannons_qty) + sti(GameInterface.strings.leftarc_cannons_qty) + 1;

	// PB: Price calculation fixed -->
	if( n <= GetCannonArcMaxQty(GetCharacter(cn), arc) )
	{
		if(GetCannonQuantity(GetCharacter(cn)) > total)		topay = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn))-total );
		else												topay = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), total-GetCannonQuantity(GetCharacter(cn)) );

		GameInterface.strings.(arcname) = n;
		GameInterface.strings.cannons_cost = MakeMoneyShow(topay, MONEY_SIGN, MONEY_DELIVER);

		SetSelectable("CANNONS_BUY_BUTTON", topay <= GetCharacterMoney(GetMainCharacter()) );
	}
	// PB: Price calculation fixed <--
}

void RemoveCannon(string arcname)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("RemoveCannons");
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	int arc = 0;
	switch (arcname)
	{
		case "front_cannons_qty":
			arc = 0;
		break;
		case "rightarc_cannons_qty":
			arc = 1;
		break;
		case "back_cannons_qty":
			arc = 2;
		break;
		case "leftarc_cannons_qty":
			arc = 3;
		break;
	}

	int n = sti(GameInterface.strings.(arcname)) - 1;
	int total = sti(GameInterface.strings.front_cannons_qty) + sti(GameInterface.strings.rightarc_cannons_qty) + sti(GameInterface.strings.back_cannons_qty) + sti(GameInterface.strings.leftarc_cannons_qty) - 1;

	// PB: Price calculation fixed -->
	if (n >= 0)
	{
		if(GetCannonQuantity(GetCharacter(cn)) > total)		topay = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn))-total );
		else												topay = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), total-GetCannonQuantity(GetCharacter(cn)) );

		GameInterface.strings.(arcname) = n;
		GameInterface.strings.cannons_cost = MakeMoneyShow(topay, MONEY_SIGN, MONEY_DELIVER);

		SetSelectable("CANNONS_BUY_BUTTON", topay <= GetCharacterMoney(GetMainCharacter()) );
	}
	// PB: Price calculation fixed <--
}

void ProcessCommandExecute()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessCommandExecute");
	int i,cn;
	ref mchr = GetMainCharacter();

	string comName = GetEventData();
	string nodName = GetEventData();

	if(DEBUG_SHIPYARD_INTERFACE) trace("nodName: "+nodName);
	switch(nodName)
	{
	case "SCROLLITEMS":
		if(comName=="activate")
		{
// KK -->
			ProcessBuyShip();
// <-- KK
		}
	break;

	case "PASSENGERS":
		if(comName=="activate" || comName=="downstep")
		{
			ProcessSelectCaptain(); // KK
		}
	break;

	case "SHIPSLIST":
		if(comName=="activate")
		{
			if (CurrentScreen == SCREEN_REPAIR && nShowMode != ISHOW_MODE_COMPANION) // KK
			{
				SetShowMode(ISHOW_MODE_CHOOSE);
				EnableChooseButtons();
				ChooseButtonTopSelect();
			} else {SelectCaptainButton();}
		}
	break;

	case "LEFTSCROLLBUTTON":
		switch(comName)
		{
			case "click":
// KK -->
				if (GetSelectable("SCROLLITEMS")) {
					SetCurrentNode("SCROLLITEMS");
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLITEMS",-1, 0,ACTION_LEFTSTEP);
				}
				if (GetSelectable("PASSENGERS")) {
					SetCurrentNode("PASSENGERS");
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PASSENGERS",-1, 0,ACTION_LEFTSTEP);
				}
				if (GetSelectable("SCROLLCANNONS")) {
					SetCurrentNode("SCROLLCANNONS");
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLCANNONS",-1, 0,ACTION_LEFTSTEP);
				}
				if (GetSelectable("SCROLLSHIPUPGRADES")) {
					SetCurrentNode("SCROLLSHIPUPGRADES");
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLSHIPUPGRADES",-1, 0,ACTION_LEFTSTEP);
				}
				if (GetSelectable("SCROLLSHIPAPPEARANCE")) {
					SetCurrentNode("SCROLLSHIPAPPEARANCE");
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLSHIPAPPEARANCE",-1, 0,ACTION_LEFTSTEP);
				}
// <-- KK
			break;
		}
	break;

	case "RIGHTSCROLLBUTTON":
		switch(comName)
		{
		case "click":
// KK -->
			if (GetSelectable("SCROLLITEMS")) {
				SetCurrentNode("SCROLLITEMS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLITEMS",-1, 0,ACTION_RIGHTSTEP);
			}
			if (GetSelectable("PASSENGERS")) {
				SetCurrentNode("PASSENGERS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PASSENGERS",-1, 0,ACTION_RIGHTSTEP);
			}
			if (GetSelectable("SCROLLCANNONS")) {
				SetCurrentNode("SCROLLCANNONS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLCANNONS",-1, 0,ACTION_RIGHTSTEP);
			}
			if (GetSelectable("SCROLLSHIPUPGRADES")) {
				SetCurrentNode("SCROLLSHIPUPGRADES");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLSHIPUPGRADES",-1, 0,ACTION_RIGHTSTEP);
			}
			if (GetSelectable("SCROLLSHIPAPPEARANCE")) {
				SetCurrentNode("SCROLLSHIPAPPEARANCE");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLSHIPAPPEARANCE",-1, 0,ACTION_RIGHTSTEP);
			}
// <-- KK
		break;
		}
	break;

	case "FIXALL_BUTTON":
		if(comName=="downstep")
		{
			if(GetSelectable("HULLQUANTITY"))
			{
				SetCurrentNode("HULLQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"HULLQUANTITY");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn>=0)
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				DoHullRepairToPercent(GetCharacter(cn),100);
				DoSailRepairToPercent(GetCharacter(cn),100);
				DoCannonRepair(GetCharacter(cn));	// LDH 27Sep06
				SetRepairData();
				SetCurrentNode("SHIPSLIST");
			}
		}
	break;

	case "HULLQUANTITY":
		switch(comName)
		{
		case "downstep":
			if(GetSelectable("SAILSQUANTITY"))
			{
				SetCurrentNode("SAILSQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"SAILSQUANTITY");
			}
		break;
		case "upstep":
			if(GetSelectable("FIXALL_BUTTON"))
			{
				SetCurrentNode("FIXALL_BUTTON");
			}
		break;
		case "rightstep":
			ChangeHullRepair(1);
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="HULLQUANTITY")
			{
				OldNodeName="HULLQUANTITY";
				SetCurrentNode("HULLQUANTITY");
			}
		break;
		case "leftstep":
			ChangeHullRepair(-1);
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="HULLQUANTITY")
			{
				OldNodeName="HULLQUANTITY";
				SetCurrentNode("HULLQUANTITY");
			}
		break;
		}
	break;

	case "SAILSQUANTITY":
		switch(comName)
		{
		case "downstep":
			if(GetSelectable("REPAIR_OK"))
			{
				SetCurrentNode("REPAIR_OK");
			}
			else
			{
				Event("ievnt_command","ss",comName,"REPAIR_OK");
			}
		break;
		case "upstep":
			if(GetSelectable("HULLQUANTITY"))
			{
				SetCurrentNode("HULLQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"HULLQUANTITY");
			}
		break;
		case "rightstep":
			ChangeSailRepair(1);
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="SAILSQUANTITY")
			{
				OldNodeName="SAILSQUANTITY";
				SetCurrentNode("SAILSQUANTITY");
			}
		break;
		case "leftstep":
			ChangeSailRepair(-1);
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="SAILSQUANTITY")
			{
				OldNodeName="SAILSQUANTITY";
				SetCurrentNode("SAILSQUANTITY");
			}
		break;
		}
	break;

	case "REPAIR_OK":
		switch(comName)
		{
		case "upstep":
			if(GetSelectable("SAILSQUANTITY"))
			{
				SetCurrentNode("SAILSQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"SAILSQUANTITY");
			}
		break;
		}
		if(comName=="activate" || comName=="click")
		{
			cn = GetCompanionIndex(mchr,nCurFourNum);
			if(cn>=0)
			{
				makearef(arCurShip, Characters[cn].ship); // PRS3
				DoHullRepairToPercent(GetCharacter(cn),nhpRepair);
				DoSailRepairToPercent(GetCharacter(cn),nspRepair);
				SetRepairData();
				if( !IsEnableRepairShip() ) {
					SetCurrentNode("SHIPSLIST");
				}
				else {
					SetCurrentNode("FIXALL_BUTTON");
				}
			}
		}
	break;

	case "CONFIRM_YES_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			switch (CurrentScreen)
			{
				case SCREEN_REPAIR:
					switch (nShowMode) {
						case ISHOW_MODE_SELL:
							DoSellShip("firecrew","includecargo");// TIH added handlers Jul27'06
						break;
						case ISHOW_MODE_BUY:
							DoBuyShip();
						break;
						case ISHOW_MODE_CHOOSE:
							UpdateCompanionCharacter();
							SetCurrentNode("SHIPSLIST");
							nShowMode = ISHOW_MODE_COMPANION;
						break;
					}
					BuyShipCancel();
					UpdateShipScroll();
					UpdateFourImages();
					SetCurrentNode("SHIPSLIST");
					nCurSScrollNum = -1;
					nCurFourNum = -1;
					SetShowMode(ISHOW_MODE_CHOOSE); // Screwface
				break;

				case SCREEN_CANNONS:
				break;
			}
		}
	break;

	case "CONFIRM_NO_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			switch (CurrentScreen)
			{
				case SCREEN_REPAIR:
					BuyShipCancel();
					UpdateShipScroll();
					UpdateFourImages();
					SetCurrentNode("SHIPSLIST");
					nCurSScrollNum = -1;
					nCurFourNum = -1;
					SetShowMode(ISHOW_MODE_CHOOSE); // Screwface
				break;
			}
		}
	break;

	case "CANCEL_BUTTON":
	break;

	case "SKILLINFO_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_SKILLS);
			SetSkillData();
			SetCurrentNode("SKILLS_IMAGES");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
		if(comName=="downstep")	{SetNextCaptainButton(nodName,false);}
	break;

	case "REMOVEC_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			FireCaptain();
			SetCurrentNode("SHIPSLIST");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
		if(comName=="downstep")	{SetNextCaptainButton(nodName,false);}
	break;

	case "SETC_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			UpdateCompanionCharacter();
			SetCurrentNode("SHIPSLIST");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
	break;

	/*case "BUY_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_VIEW);
			SetCurrentNode("SCROLLITEMS");
// KK -->
			//ProcessBuyShip();
// <-- KK
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;*/

	case "REPAIR_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_REPAIR);
			SetRepairData();
			SetCurrentRepairButton();
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

	case "SELLSHIP_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			// NK -->
// KK -->
			if (!LAi_IsCapturedLocation) {
				if(IsMoneyForSellEnable())
				{
					/*SetShowMode(ISHOW_MODE_SELL);
					SetCurrentNode("OK_BUTTON");
					makearef(arCurShip, Characters[GetCompanionIndex(mchr,nCurFourNum)].ship); // PRS3
					GameInterface.strings.TradePrice = MakeMoneyShow(GetSellPrice(nCurFourNum,"skipcargo"),MONEY_SIGN,MONEY_DELIVER);*/// TIH added handler Jul27'06 //PW was "includecargo" but would mask ship price so now skip even though currently commented out
					ProcessSellShip();
				}
			} else {
				DoSellShip("firecrew","includecargo");// TIH added handlers Jul27'06
				UpdateFourImages();
				UpdateShipScroll();
				SetCurrentNode("SHIPSLIST");
				nCurSScrollNum = -1;
				nCurFourNum = -1;
			}
// <-- KK
			// NK <--
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

	case "CHANGE_CAPTAIN":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_COMPANION);
			SetCaptainButtonsEnable();
			SetCurrentNode("PASSENGERS");
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

		case "BACK_BUTTON":
			SetShowMode(ISHOW_MODE_VIEW);
			SetCurrentNode("SHIPSLIST");
		break;

		case "INSTALL_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessInstall();
			}
		break;
// KK -->
		case "INSTALLBUY_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessInstallAndBuy();
			}
		break;
// <-- KK
		case "CANNONS_CANCEL_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessCancel();
			}
		break;

		case "CANNONS_BUY_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessBuyCannon();
			}
		break;

		case "FRONTCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("FRONTCANNONSQTY")) {
						SetCurrentNode("FRONTCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"FRONTCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("FRONTCANNONSQTY")) {
						SetCurrentNode("FRONTCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"FRONTCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("front_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("front_cannons_qty");
				break;
			}
		break;

		case "LEFTARCCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("LEFTARCCANNONSQTY")) {
						SetCurrentNode("LEFTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"LEFTARCCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("LEFTARCCANNONSQTY")) {
						SetCurrentNode("LEFTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"LEFTARCCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("leftarc_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("leftarc_cannons_qty");
				break;
			}
		break;

		case "RIGHTARCCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("RIGHTARCCANNONSQTY")) {
						SetCurrentNode("RIGHTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"RIGHTARCCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("RIGHTARCCANNONSQTY")) {
						SetCurrentNode("RIGHTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"RIGHTARCCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("rightarc_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("rightarc_cannons_qty");
				break;
			}
		break;

		case "BACKCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("BACKCANNONSQTY")) {
						SetCurrentNode("BACKCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"BACKCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("BACKCANNONSQTY")) {
						SetCurrentNode("BACKCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"BACKCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("back_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("back_cannons_qty");
				break;
			}
		break;

// KK -->
		case "I_REPAIR":
			SetScreen(SCREEN_REPAIR);
		break;

		case "I_CANNONS":
			SetScreen(SCREEN_CANNONS);
		break;

		case "I_SHIPUPGRADE":
			SetScreen(SCREEN_SHIPUPGRADE);
	break;

		case "I_APPEARANCE":
			SetScreen(SCREEN_APPEARANCE);
		break;
// <-- KK
	}
}

void SetShowMode(int newMode)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetShowMode");
	if(newMode==nShowMode) return;
	switch(nShowMode)
	{
	case ISHOW_MODE_VIEW:
		DisableString("ShipClass");
		DisableString("HullPoints");
		DisableString("Speed");
		DisableString("Maneuver");
		DisableString("Capacity");
		DisableString("MaxCrew");
		DisableString("MinCrew");
		DisableString("CannonsQuantity");
		DisableString("MaxCaliber");
		DisableString("ShipCost");
		DisableString("ShipName");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
		SetNodeUsing("MAINPICTURES",false);
		for (int i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
			string upgradepict = "Upgrade" + i + "_Picture";
			GameInterface.pictures.(upgradepict).pic = -1;
			GameInterface.pictures.(upgradepict).tex = -1;
		}
		SetNodeUsing("NATION", false);						// added by KAM
		SetNodeUsing("NATIONALDESIGN",false);				// added by KAM
		SetNodeUsing("BOX1", false);
		SetNodeUsing("BOX1_RAMKA", false);
		DisableString("HelpString");
	break;

	case ISHOW_MODE_EMPTYVIEW:
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
		DisableString("ShipName");
	break;

	case ISHOW_MODE_BUY:
		/*SetNodeUsing("BUYCONFIRM",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		DisableString("TradePrice");*/
// KK -->
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", true);
		SetSelectable("LEFTSCROLLBUTTON", true);
		SetSelectable("RIGHTSCROLLBUTTON", true);
		SetSelectable("I_CANNONS", true);
		SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
		SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());

		SetNodeUsing("CONFIRM_RECTANGLE", true);
		SetNodeUsing("TEXTWINDOW", true);
		SetNodeUsing("CONFIRM_YES_BUTTON", true);
		SetNodeUsing("CONFIRM_NO_BUTTON", true);
// <-- KK
	break;

	case ISHOW_MODE_SELL:
		SetNodeUsing("SELLCONFIRM",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		DisableString("TradePrice");
// KK -->
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", true);
		SetSelectable("LEFTSCROLLBUTTON", true);
		SetSelectable("RIGHTSCROLLBUTTON", true);
		SetSelectable("I_CANNONS", true);
		SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
		SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
// <-- KK
	break;

	case ISHOW_MODE_REPAIR:
		DisableString("RepairAllCost");
		DisableString("HullPercent");
		DisableString("RepairHullCost");
		DisableString("SailsPercent");
		DisableString("RepairSailsCost");
		DisableString("ShipName");

		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
		SetNodeUsing("REPAIRSTRINGS",false);
		SetNodeUsing("FIXALL_BUTTON",false);
		SetNodeUsing("HULLQUANTITY",false);
		SetNodeUsing("SAILSQUANTITY",false);
		SetNodeUsing("REPAIR_OK",false);
		SetNodeUsing("RECT_FIXALL_PRICE",false);
		SetNodeUsing("RECT_HULL_PRICE",false);
		SetNodeUsing("RECT_SAILS_PRICE",false);
		SetNodeUsing("RECT_SELL_PRICE",false);
		SetNodeUsing("REPAIRIMAGES",false);
// KK -->
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", true);
		SetSelectable("LEFTSCROLLBUTTON", true);
		SetSelectable("RIGHTSCROLLBUTTON", true);
		SetSelectable("I_CANNONS", true);
		SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
		SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
// <-- KK
	break;

	case ISHOW_MODE_COMPANION:
		DisableString("CharacterName");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
		SetNodeUsing("SCROLLITEMS",true);
		SetNodeUsing("PASSENGERS",false);
		SetNodeUsing("SKILLINFO_BUTTON",false);
		SetNodeUsing("REMOVEC_BUTTON",false);
		SetNodeUsing("SETC_BUTTON",false);
// KK -->
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", true);
		SetSelectable("LEFTSCROLLBUTTON", true);
		SetSelectable("RIGHTSCROLLBUTTON", true);
		SetSelectable("I_CANNONS", true);
		SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
		SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
// <-- KK
	break;

	case ISHOW_MODE_CHOOSE:
		//SetNodeUsing("BUY_BUTTON",false);
		SetNodeUsing("REPAIR_BUTTON",false);
		SetNodeUsing("SELLSHIP_BUTTON",false);
		SetNodeUsing("CHANGE_CAPTAIN",false);
// KK -->
		SetNodeUsing("BACK_BUTTON", false);
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", true);
		SetSelectable("LEFTSCROLLBUTTON", true);
		SetSelectable("RIGHTSCROLLBUTTON", true);
		SetSelectable("I_CANNONS", true);
		SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
		SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
// <-- KK
	break;

	case ISHOW_MODE_SKILLS:
		DisableString("CharacterName");
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
		SetNodeUsing("SKILLS_IMAGES",false);
		SetNodeUsing("SCROLLITEMS",true);
		SetNodeUsing("PASSENGERS",false);
	break;
	}

	nShowMode = newMode;
	switch(nShowMode)
	{
	case ISHOW_MODE_VIEW:
		EnableString("ShipClass");
		EnableString("HullPoints");
		EnableString("Speed");
		EnableString("Maneuver");
		EnableString("Capacity");
		EnableString("MaxCrew");
		EnableString("MinCrew");
		EnableString("CannonsQuantity");
		EnableString("MaxCaliber");
		EnableString("ShipCost");
		EnableString("ShipName");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", true);
		SetNodeUsing("MAINPICTURES",true);
		SetNodeUsing("NATION", true);						// added by KAM
		SetNodeUsing("NATIONALDESIGN",true);				// added by KAM
		SetNodeUsing("BOX1", false);
		SetNodeUsing("BOX1_RAMKA", false);
		DisableString("HelpString");
	break;

	case ISHOW_MODE_EMPTYVIEW:
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", true);
		EnableString("ShipName");
	break;

	case ISHOW_MODE_BUY:
		/*SetNodeUsing("BUYCONFIRM",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		EnableString("TradePrice");*/
// KK -->
		SetSelectable("SHIPSLIST", false);
		SetSelectable("SCROLLITEMS", false);
		SetSelectable("LEFTSCROLLBUTTON", false);
		SetSelectable("RIGHTSCROLLBUTTON", false);
		SetSelectable("I_CANNONS", false);
		SetSelectable("I_SHIPUPGRADE", false);
		SetSelectable("I_APPEARANCE", false);
// <-- KK
	break;

	case ISHOW_MODE_SELL:
		SetNodeUsing("SELLCONFIRM",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		EnableString("TradePrice");
// KK -->
		SetSelectable("SHIPSLIST", false);
		SetSelectable("SCROLLITEMS", false);
		SetSelectable("LEFTSCROLLBUTTON", false);
		SetSelectable("RIGHTSCROLLBUTTON", false);
		SetSelectable("I_CANNONS", false);
		SetSelectable("I_SHIPUPGRADE", false);
		SetSelectable("I_APPEARANCE", false);
// <-- KK
	break;

	case ISHOW_MODE_REPAIR:
		EnableString("RepairAllCost");
		EnableString("HullPercent");
		EnableString("RepairHullCost");
		EnableString("SailsPercent");
		EnableString("RepairSailsCost");
		EnableString("ShipName");

		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", true);
		SetNodeUsing("REPAIRSTRINGS",true);
		SetNodeUsing("FIXALL_BUTTON",true);
		SetNodeUsing("HULLQUANTITY",true);
		SetNodeUsing("SAILSQUANTITY",true);
		SetNodeUsing("REPAIR_OK",true);
		SetNodeUsing("RECT_FIXALL_PRICE",true);
		SetNodeUsing("RECT_HULL_PRICE",true);
		SetNodeUsing("RECT_SAILS_PRICE",true);
		SetNodeUsing("RECT_SELL_PRICE",true);
		SetNodeUsing("REPAIRIMAGES",true);
// KK -->
		SetSelectable("SHIPSLIST", false);
		SetSelectable("SCROLLITEMS", false);
		SetSelectable("LEFTSCROLLBUTTON", false);
		SetSelectable("RIGHTSCROLLBUTTON", false);
		SetSelectable("I_CANNONS", false);
		SetSelectable("I_SHIPUPGRADE", false);
		SetSelectable("I_APPEARANCE", false);
// <-- KK
	break;

	case ISHOW_MODE_COMPANION:
		EnableString("CharacterName");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", true);
		SetNodeUsing("SCROLLITEMS",false);
		SetNodeUsing("PASSENGERS",true);
		SetNodeUsing("SKILLINFO_BUTTON",true);
		SetNodeUsing("REMOVEC_BUTTON",true);
		SetNodeUsing("SETC_BUTTON",true);
// KK -->
		SetSelectable("SHIPSLIST", true);
		SetSelectable("SCROLLITEMS", false);
		SetSelectable("LEFTSCROLLBUTTON", false);
		SetSelectable("RIGHTSCROLLBUTTON", false);
		SetSelectable("I_CANNONS", false);
		SetSelectable("I_SHIPUPGRADE", false);
		SetSelectable("I_APPEARANCE", false);
		DisableString("NoBuyString"); // Screwface
		SetNodeUsing("NOBUYBOX2",false); // Screwface
// <-- KK
	break;

	case ISHOW_MODE_CHOOSE:
		sPreviouseNode = GetCurrentNode();
		//SetNodeUsing("BUY_BUTTON",true);
		SetNodeUsing("REPAIR_BUTTON",true);
		SetNodeUsing("SELLSHIP_BUTTON",true);
		SetNodeUsing("CHANGE_CAPTAIN",true);
// KK -->
		SetNodeUsing("BACK_BUTTON", true);
		SetSelectable("SHIPSLIST", false);
		SetSelectable("SCROLLITEMS", false);
		SetSelectable("LEFTSCROLLBUTTON", false);
		SetSelectable("RIGHTSCROLLBUTTON", false);
		SetSelectable("I_CANNONS", false);
		SetSelectable("I_SHIPUPGRADE", false);
		SetSelectable("I_APPEARANCE", false);
		DisableString("NoBuyString"); // Screwface
		SetNodeUsing("NOBUYBOX2",false); // Screwface
// <-- KK
	break;

	case ISHOW_MODE_SKILLS:
		EnableString("CharacterName");
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SHIPNAMETITLE_RAMKA", true);
		SetNodeUsing("SKILLS_IMAGES",true);
		SetNodeUsing("SCROLLITEMS",false);
		SetNodeUsing("PASSENGERS",true);
	break;
	}
}

void FillSScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillSScroll");
	nCurSScrollNum = -1;
	if(!CheckAttribute(&GameInterface,"scrollitems.current"))
		GameInterface.scrollitems.current = 0;

    string attributeName;
    string shipName;
	ref PChar = GetMainCharacter();
	GameInterface.scrollitems.BadPicture2 = "interfaces\blank_ship.tga";
// KK -->
	if (bNewInterface)
		GameInterface.scrollitems.ImagesGroup.t0 = "ICONS_NEW";
	else
		GameInterface.scrollitems.ImagesGroup.t0 = "ICONS";
// <-- KK
	GameInterface.scrollitems.ImagesGroup.t1 = "SHIPS16";
	GameInterface.scrollitems.ImagesGroup.t2 = "SHIPS1";
	GameInterface.scrollitems.ImagesGroup.t3 = "SHIPS2";
	GameInterface.scrollitems.ImagesGroup.t4 = "SHIPS3";
	GameInterface.scrollitems.ImagesGroup.t5 = "SHIPS4";
	GameInterface.scrollitems.ImagesGroup.t6 = "SHIPS5";

	// TIH --> sy_rpg_style selection visual adjustment Jul27'06
	if ( SY_RPG_STYLE ) {
		GameInterface.scrollitems.SpecTechniqueColor = argb(80,255,255,255);
		GameInterface.scrollitems.SpecTechniqueName = "iSpec1";
		float mcL = makefloat(GetLevel(GetMainCharacter()));
		int allowedClass = iclamp(1,9 , makeint( 9 - roundup(mcL / makefloat(SHIPYARD_RPG_LPC)) ));
		// for every SHIPYARD_RPG_LPC levels, they gain access to next class (8 is always available)
		if ( EnableLimitedShipClass() ) allowedClass = GetShipMinClassForCharacter(GetMainCharacter());
		if(DEBUG_SHIPYARD_INTERFACE) trace("SY player level "+mcL+" gains access to class "+allowedClass+" and below");
	}
	// TIH <--

	aref curref;
	int st; // PRS3
    for(int i=0;i<GetAttributesNum(arShipList);i++)
    {
		curref = GetAttributeN(arShipList,i);
		st = sti(GetAttributeValue(curref)); // PRS3
        attributeName = "pic" + (i+1);
		makearef(arCurShip, curref); // PRS3
        shipName = GetLocalShipAttrib(arCurShip, ShipsTypes[st],"SName"); // PRS3

        GameInterface.scrollitems.(attributeName).str1 = "#"+GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Class"); // PRS3
        GameInterface.scrollitems.(attributeName).str2 = shipName;
        GameInterface.scrollitems.(attributeName).img1 = "ship back";
        GameInterface.scrollitems.(attributeName).img2 = GetShipPicName(st); // PS
		GameInterface.scrollitems.(attributeName).tex1 = 0;
		GameInterface.scrollitems.(attributeName).tex2 = 1+GetShipTexture(st); // PS

		if (VanderdeckenShipyard()) continue; // KK

		// TIH --> sy_rpg_style selection visual adjustment Jul27'06
		if ( SY_RPG_STYLE && !LAi_IsCapturedLocation)
		{
			GameInterface.scrollitems.(attributeName).spec2 = allowedClass>sti(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Class"));
			GameInterface.scrollitems.(attributeName).skipsell = allowedClass>sti(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Class"));
		}
		// TIH <--

	// PB: Realistic Ship Purchase -->
		GameInterface.scrollitems.(attributeName).navyship = false;
		GameInterface.scrollitems.(attributeName).pirateship = false;
		if(REALISTIC_SHIP_PURCHASE && LAi_IsCapturedLocation == false)
		{
			if(GetCurrentLocationNation() == PIRATE)
			{
				if(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Nation") == PIRATE) GameInterface.scrollitems.(attributeName).pirateship = true;
				if(GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY || GetLetterOfMarqueQuantity() == 0) GameInterface.scrollitems.(attributeName).pirateship = false; // PB
			}
			else
			{
				if(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Type.War") == true && GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Type.Trade") == false && GetCurrentLocationNation() != PERSONAL_NATION)
				{
					switch(sti(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Class")))
					{
						case 1:
							if(RANK_FOR_FIRST_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_FIRST_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_FIRST_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 2:
							if(RANK_FOR_SECOND_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_SECOND_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_SECOND_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 3:
							if(RANK_FOR_THIRD_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_THIRD_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_THIRD_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 4:
							if(RANK_FOR_FOURTH_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_FOURTH_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_FOURTH_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 5:
							if(RANK_FOR_FIFTH_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_FIFTH_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_FIFTH_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 6:
							if(RANK_FOR_SIXTH_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_SIXTH_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_SIXTH_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 7:
							if(RANK_FOR_SEVENTH_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_SEVENTH_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_SEVENTH_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
						case 8:
							if(RANK_FOR_EIGHTH_RATE == 0 && !HaveLetterOfMarque(GetCurrentLocationNation()))
							{GameInterface.scrollitems.(attributeName).navyship = true;}

							if(RANK_FOR_EIGHTH_RATE > 0 && GetRank(GetMainCharacter(), GetCurrentLocationNation()) < RANK_FOR_EIGHTH_RATE)
							{GameInterface.scrollitems.(attributeName).navyship = true;}
							break;
					}
				}
			}
		}
		if(GameInterface.scrollitems.(attributeName).navyship)
		{
			GameInterface.scrollitems.(attributeName).spec2 = true;
			GameInterface.scrollitems.(attributeName).skipsell = true;
		}
		if(GameInterface.scrollitems.(attributeName).pirateship)
		{
			GameInterface.scrollitems.(attributeName).spec2 = true;
			GameInterface.scrollitems.(attributeName).skipsell = true;
		}
	// PB: Realistic Ship Purchase <--
    }

    GameInterface.scrollitems.ListSize = i+1;// TIH bugfix Jul27'06
	GameInterface.scrollitems.NotUsed = 5;
}

void FillFScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillFScroll");
	nCurFScrollNum = -1;// TIH bugfix
	DeleteAttribute(&GameInterface,"passengers");
    GameInterface.passengers.current = 0;
	GameInterface.passengers.NotUsed = 5;

	GameInterface.passengers.ImagesGroup.t0 = "EMPTYFACE";
	ref mchref = GetMainCharacter();
	FillFaceList( "passengers.ImagesGroup", mchref, 0 ); // officers
	FillFaceList( "passengers.ImagesGroup", mchref, 1 ); // companions
	FillFaceList( "passengers.ImagesGroup", mchref, 2 ); // passengers

	GameInterface.passengers.BadTex1 = 0;
// KK -->
	if (bNewInterface)
		GameInterface.passengers.BadPic1 = "emptyface_new";
	else
		GameInterface.passengers.BadPic1 = "emptyface";
// <-- KK

	ref charRef;
	string attributeName;
	nAllPassngerQuantity = 0;
	int cn = GetPassengerFromScroll(0);
	while(cn>=0)
	{
		attributeName = "pic" + (nAllPassngerQuantity+1);
		charRef = GetCharacter(cn);
		GameInterface.passengers.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers.(attributeName).tex1 = FindFaceGroupNum("passengers.ImagesGroup","FACE128_"+charRef.FaceID);
		nAllPassngerQuantity++;
		cn=GetPassengerFromScroll(nAllPassngerQuantity);
	}
	GameInterface.passengers.ListSize = nAllPassngerQuantity;
}

// KK -->
void FillShipUpgradesScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillShipUpgradesScroll");
	int i, idx;
	string attributeName;
	aref pRef;
	int cn = GetCompanionIndex(GetMainCharacter(), sti(GameInterface.FourImage.current));

	idx=0;
	GameInterface.scrollshipupgrades.ImagesGroup.t1 = "SHIP_UPGRADES";
	GameInterface.scrollshipupgrades.ImagesGroup.t2 = "INSTALLEDFLAG";
	GameInterface.scrollshipupgrades.SpecTechniqueColor = argb(90,255,255,255);
	GameInterface.scrollshipupgrades.SpecTechniqueName = "iSpec1";
	for (i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
		idx++;
		attributeName = "pic" + idx;
		string upgrade = GetShipUpgradeID(i);
		makearef(pRef,GameInterface.scrollshipupgrades.(attributeName));
		pRef.str1 = upgrade;
		pRef.img1 = upgrade;
		pRef.tex1 = 0;
		if (cn >= 0 && CheckTun(cn, upgrade) == true) {
			pRef.img2 = "installedflag";
			pRef.tex2 = 1;
		}
		else pRef.tex2 = 0; // Screwface
	}

	GameInterface.scrollshipupgrades.ListSize = idx;
	GameInterface.scrollshipupgrades.current = 0;

	//nCurSUScrollNum = 0;
}

void FillShipAppearanceScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillShipAppearanceScroll");
	int i, idx;
	string attributeName;
	aref pRef;
	int cn = GetCompanionIndex(GetMainCharacter(), sti(GameInterface.FourImage.current));
	string ShipModel = GetCharacterShipModel(GetCharacter(cn));

	// Screwface we need to clear the list
	makearef(pRef, GameInterface.scrollshipappearance);
	DeleteAttribute(pRef,"");

	idx=0;
	GameInterface.scrollshipappearance.BadPicture2 = "interfaces\blank_ship.tga";
	if (bNewInterface)
		GameInterface.scrollshipappearance.ImagesGroup.t0 = "ICONS_NEW";
	else
		GameInterface.scrollshipappearance.ImagesGroup.t0 = "ICONS";
	GameInterface.scrollshipappearance.ImagesGroup.t1 = "INSTALLEDFLAG";
	GameInterface.scrollshipappearance.ImagesGroup.t2 = "SHIPS16";
	GameInterface.scrollshipappearance.ImagesGroup.t3 = "SHIPS1";
	GameInterface.scrollshipappearance.ImagesGroup.t4 = "SHIPS2";
	GameInterface.scrollshipappearance.ImagesGroup.t5 = "SHIPS3";
	GameInterface.scrollshipappearance.ImagesGroup.t6 = "SHIPS4";
	GameInterface.scrollshipappearance.ImagesGroup.t7 = "SHIPS5";
	GameInterface.scrollshipappearance.SpecTechniqueColor = argb(90,255,255,255);
	GameInterface.scrollshipappearance.SpecTechniqueName = "iSpec1";
	for (i = 0; i < SHIP_TYPES_QUANTITY; i++) {
		ref rShip; makeref(rShip, ShipsTypes[i]);
		if (!CheckAttribute(rShip, "Model")) continue;
		if (ShipModel != rShip.Model) continue;
		idx++;
		attributeName = "pic" + idx;
		makearef(pRef, GameInterface.scrollshipappearance.(attributeName));
		pRef.str1 = "#" + rShip.Class;
		pRef.str2 = rShip.SName;
		pRef.img1 = "ship back";
		pRef.img2 = GetShipPicName(i);
		pRef.tex1 = 0;
		pRef.tex2 = 2 + GetShipTexture(i);
		if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) == i) {
			pRef.img3 = "installedflag";
			pRef.tex3 = 1;
		}
		else pRef.tex3 = 0; // Screwface
		pRef.Type = i;
	}

	GameInterface.scrollshipappearance.NotUsed = 5;
	GameInterface.scrollshipappearance.ListSize = idx;
	GameInterface.scrollshipappearance.current = 0;

	//nCurAScrollNum = 0;
}

string GetChoosedShipType()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetChoosedShipType");
	string AttributeName = "pic" + (sti(GameInterface.scrollshipappearance.current) + 1);
	if (!CheckAttribute(GameInterface, "scrollshipappearance." + AttributeName + ".Type")) return "";
	int iship = sti(GameInterface.scrollshipappearance.(AttributeName).Type);
	return ShipsTypes[iship].id;
}
// <-- KK

void FillCannonsScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillCannonsScroll");
	int i, idx;
	string attributeName;
    aref pRef;

// KK -->
	if (bNewInterface)
		GameInterface.scrollcannons.ImagesGroup.t1 = "ICONS_NEW";
	else
		GameInterface.scrollcannons.ImagesGroup.t1 = "ICONS";
// <-- KK
	idx=0;
	// KNB -->
	GameInterface.scrollcannons.ImagesGroup.t2 = "CANNONS";
	GameInterface.scrollcannons.ImagesGroup.t3 = "installedflag";	// TIH cannon selection visual adjustment Jul12'06
	GameInterface.scrollcannons.SpecTechniqueColor = argb(90,255,255,255);	// TIH cannon selection visual adjustment Jul12'06
	GameInterface.scrollcannons.SpecTechniqueName = "iSpec1";	// TIH cannon selection visual adjustment Jul12'06
	if(USE_REAL_CANNONS)
	{
		//GameInterface.scrollcannons.ImagesGroup.t2 = "KNBCANNONS";
		for(i=0; i<CANNON_TYPES_QUANTITY; i++)
		{
			if (GetAttribute(&cannon[i], "TradeOff") == true && !VanderdeckenShipyard())
				continue;

			idx++;
			attributeName = "pic" + idx;
			makearef(pRef,GameInterface.scrollcannons.(attributeName));
			switch(sti(cannon[i].type))
			{
				case CANNON_NAME_LONG:
					pRef.str1 = "Long Gun";
					pRef.img2 = "long"+cannon[i].caliber;
					pRef.img1 = "culverine back";  // all three are the same!
				break;
				case CANNON_NAME_CARRONADE:
					pRef.str1 = "Carronade";
					pRef.img2 = "carronade"+cannon[i].caliber;
					pRef.img1 = "cannon back";
				break;
			}
			pRef.str2 = "caliber"+cannon[i].caliber;
			pRef.cannon = i;
			pRef.tex1 = 0;
			pRef.tex2 = 1;
		}
	}
	// KNB <--
	else
	{
		//GameInterface.scrollcannons.ImagesGroup.t2 = "CANNONS";
		for(i=0; i<CANNON_TYPES_QUANTITY; i++)
		{
			idx++;
			attributeName = "pic" + idx;
	        makearef(pRef,GameInterface.scrollcannons.(attributeName));
			switch(sti(cannon[i].type))
			{
			case CANNON_NAME_CULVERINE:
				pRef.str1 = "Culverine";
				pRef.img2 = "culverine"+cannon[i].caliber;
				pRef.img1 = "culverine back";
				break;
			case CANNON_NAME_CANNON:
				pRef.str1 = "Cannon";
				pRef.img2 = "cannon"+cannon[i].caliber;
				pRef.img1 = "cannon back";
				break;
			case CANNON_NAME_SPECIAL_CANNON:
				pRef.str1 = "Cannon";
				pRef.img2 = "cannon"+cannon[i].caliber;
				pRef.img1 = "special cannon back";
				break;
			}
			pRef.cannon = i;
			pRef.str2 = "caliber"+cannon[i].caliber;
			pRef.tex1 = 0;
			pRef.tex2 = 1;
		}
	}

	GameInterface.scrollcannons.ListSize = idx;
	GameInterface.scrollcannons.current = 0;
}

// TIH --> cannon selection visual adjustment Jul12'06
void ChangeScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ChangeScroll");
    int i;
	int idx = 0;
    string attributeName;
    // do all these here, so they are not done each time in the loop below
	int  cn 				= GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int  cnCannonType 		= GetCaracterShipCannonsType(GetCharacter(cn));
	int  cnCannonMax 		= GetMaximumCaliber(GetCharacter(cn))
	bool cnCannonRemovable 	= GetRemovable(GetCharacter(cn));

	for(i=0; i<CANNON_TYPES_QUANTITY; i++)
	{
		// skip any that are not supposed to be visible
		if (GetAttribute(&cannon[i], "TradeOff") == true && !VanderdeckenShipyard())
			continue;

		idx++;
		attributeName = "pic" + idx;

		// if currently installed, then show so
		GameInterface.scrollcannons.(attributeName).img3 = "";
		GameInterface.scrollcannons.(attributeName).tex3 = 0;
		if ( cnCannonType == i) {
			GameInterface.scrollcannons.(attributeName).img3 = "installedflag";
			GameInterface.scrollcannons.(attributeName).tex3 = 2;
		}

		// set visible by default
		GameInterface.scrollcannons.(attributeName).spec2 = false;
		// set invisible for any of the following conditions
		if ( !cnCannonRemovable ) {
			GameInterface.scrollcannons.(attributeName).spec2 = true;
		}
		if ( cnCannonMax < GetCannonCaliber(i) && !VanderdeckenShipyard()) {
			GameInterface.scrollcannons.(attributeName).spec2 = true;
		}
	}
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLCANNONS",-1);
}
// TIH <--

void FillFourImages()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FillFourImages");
	nCurFourNum = -1;
	if(!CheckAttribute(&GameInterface,"FourImage.current"))
		GameInterface.FourImage.current = 0;

	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
// KK -->
	if (bNewInterface)
		GameInterface.FourImage.ImagesGroup.t0 = "ICONS_NEW";
	else
		GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
// <-- KK
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "SHIPS2";
	GameInterface.FourImage.ImagesGroup.t4 = "SHIPS3";
	GameInterface.FourImage.ImagesGroup.t5 = "SHIPS4";
	GameInterface.FourImage.ImagesGroup.t6 = "SHIPS5";
	GameInterface.FourImage.ImagesGroup.t7 = "EMPTYFACE";
	ref refMainCh = GetMainCharacter();
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 1 ); // companions
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 2 ); // passengers

	int i,cn,tmpShipType;
	string tmp1,tmp2,tmpStr;

    for(i=0; i<4; i++)
    {
		tmpStr = "pic"+(i+1);

		tmpShipType = SHIP_NOTUSED;
		cn = GetCompanionIndex(refMainCh,i);
		if(cn!=-1)	tmpShipType = GetCharacterShipType(GetCharacter(cn));
		GameInterface.FourImage.(tmpStr).selected = cn!=-1 || nAllPassngerQuantity>0;

		if(tmpShipType==SHIP_NOTUSED)
		{
			if(cn>=0)
			{
				GameInterface.FourImage.(tmpStr).img1 = GetFacePicName(GetCharacter(cn));
				GameInterface.FourImage.(tmpStr).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
				continue;
			}
			tmp1="";
			tmp2="";
		}
		else
		{
			ref baseShip = &ShipsTypes[tmpShipType];
			// PRS3 -->
			makearef(arCurShip, Characters[cn].ship);
			tmp1 = GetLocalShipAttrib(arCurShip, baseShip, "Class");
			tmp2 = GetLocalShipAttrib(arCurShip, baseShip, "SName");
			// PRS3 <--
		}

		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		GameInterface.FourImage.(tmpStr).img2		= GetShipPicName(tmpShipType); // PS
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= GetShipString(tmpShipType); //PS tempfix XI_ConvertString(tmp2);
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpShipType); // PS
    }
}

int GetScrollShipType(int scrollIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetScrollShipType");
	// PRS3 -->
	if(scrollIdx<0 || scrollIdx>=GetAttributesNum(arShipList))
	{
		makearef(arCurShip,NullCharacter);
		return SHIP_NOTUSED;
	}
	arCurShip = GetAttributeN(arShipList,scrollIdx);
	return sti(GetAttributeValue(GetAttributeN(arShipList,scrollIdx)));
}

// PRS3 -->
//should not be needed.
aref GetScrollShipAttr(int scrollIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetScrollShipAttr");
	if(scrollIdx<0 || scrollIdx>=GetAttributesNum(arShipList)) return &NullCharacter;
	return GetAttributeN(arShipList,scrollIdx);
}
// PRS3 <--

int GetPassengerFromScroll(int scrollIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetPassengerFromScroll");
	ref chref;
	ref mch = GetMainCharacter();
	int q = GetPassengersQuantity(mch);

	int i,idx,cn;
	idx = 0;
	for(i=0; i<q; i++)
	{
		cn = GetPassenger(mch,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			if(GetRemovable(chref))
			{
				if( !CheckAttribute(chref,"prisoned") || chref.prisoned=="0" )
				{
					if( CalcCharacterSkill(chref,SKILL_LEADERSHIP)>0 && CalcCharacterSkill(chref,SKILL_SAILING)>0 )
					{
						if(idx==scrollIdx) return cn;
						idx++;
					}
				}
			}
		}
	}
	return -1;
}

int GetBuyPrice(int scrollIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetBuyPrice");
	if (LAi_IsCapturedLocation) return 0; // KK
	int st = GetScrollShipType(scrollIdx);
	int price = MakeInt(GetScrollShipPriceByType(st) * GetCharPriceMod(GetMainCharacter(), PRICE_TYPE_BUY, true, true));
	price -= MakeInt((0.1 * GetTownCrewMorale(GetTownIDFromLocID(Locations[FindLoadedLocation()].id)) / (MORALE_MAX - MORALE_MIN)) * makefloat(GetCurrentLocationNation() == PERSONAL_NATION)); // KK
// changed by MAXIMUS [possibility to repair your ship by double price] -->
	if(tradeHigh==true) price *= 2; // NK now use central func 05-04-19
	//Levis take upgrades into account:
	//Set ship to shipowner to check tune prices
	shipwright.ship = "";
	aref toShip; makearef(toShip, shipwright.ship);
	aref fromShip = GetScrollShipAttr(scrollIdx);
	CopyAttributes(toShip, fromShip);
	shipwright.ship.type = GetShipID(st);
	shipwright.ship.idx = st;
	int _idx = GetCharacterIndex(shipwright.id);
	//Adding Cannons cause else the tunes don't know what to use
	if(USE_REAL_CANNONS) 	shipwright.ship.Cannons.Type = CANNON_TYPE_LONG_LBS4;
	else 					shipwright.ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	//Check the tune prices
	for (int i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
		string upgrade = GetShipUpgradeID(i);
		if(CheckAttribute(fromShip, "tune." + upgrade + ".on"))
		{
			if(fromShip.tune.(upgrade).on == "1") 
			{
				price += makeint(GetCostTun(_idx, upgrade, PRICE_TYPE_BUY) * 0.5); //If an upgrade is already applied, it will cost you only a percentage of the real price. This can be max of 50%
			}
		}
	}
	//Remove the ship again
	DeleteAttribute(shipwright,"ship");
	//Moved down just to be sure
	/*if(price<(GetCharPriceMod(GetMainCharacter(), PRICE_TYPE_BUY, true, true) * 0.05))
	{
		price = makeint(GetCharPriceMod(GetMainCharacter(), PRICE_TYPE_BUY, true, true) * 0.05 * Skillmult); //5% of shipprice is the minimum you will get.
	}*/
	return price;
// changed by MAXIMUS [possibility to repair your ship by double price] <--
}

// TIH --> combined functions to one with proper calls Jul27'06
int GetSellPrice(int fourIdx, string cargoHandler)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetSellPrice");
	ref PChar = GetMainCharacter();
	if (LAi_IsCapturedLocation) return 0; // KK
	int cn = GetCompanionIndex(PChar,fourIdx);
	if (cn<0) return 0;
	if (GetCharacterShipType(GetCharacter(cn)) == SHIP_NOTUSED) return 0; // KK
	makearef(arCurShip, Characters[cn].ship); // PRS3
	// KK int st = GetCharacterShipType(cn);
	int price = GetShipPriceByType(GetCharacter(cn)); // KK

	// LDH 26Nov05 moved back here so cargo doesn't take a hit on sales price.  You can sell cargo at the store for full price anyway.
	// Levis moved up here so the cannon price is taken into account properly
	float Charmod  = GetCharPriceMod(PChar, PRICE_TYPE_SELL, true, true);

	// PB: Method of acquiring ship influences sale price -->
	// Inspired by TIH's rpgstyle shipyard (Jul27'06)
	float sellMult = SHIPYARD_SHIP_SELL_MULT;																	// 0.30 with SY RPG Style OFF
	if ( SY_RPG_STYLE ) {
		switch (ShipAcquiredState(arCurShip))
		{
			case "bought":
				sellMult = SHIPYARD_BOUGHTSHIP_SELL_MULT;														// 0.90 for ship bought from a shipyard
				break;
			case "taken":
				if (ProfessionalNavyNation() == UNKNOWN_NATION)													// FOR PRIVATEERS:
					sellMult = SHIPYARD_PRIV_PRIZE_SELL_MULT;													// 0.50 for legal prize ship
				else																							// FOR NAVAL OFFICERS:
				{
					sellMult = SHIPYARD_NAVY_PRIZE_SELL_MULT;													// 0.20 for legal prize ship
					Charmod  = 1.0;																				// Levis: Professional Navy and LoM pay commission, but are not affected by skills
				}
				break;
			case "pirated":
				if (IsInServiceOf(PIRATE))	sellMult = SHIPYARD_BOUGHTSHIP_SELL_MULT;							// 0.90 for pirated ships if you have joined the pirates
				else						sellMult = SHIPYARD_PIRATEDSHIP_SELL_MULT;							// 0.10 for pirated ships if you haven't
				break;
		}
	}
	// PB: Method of acquiring ship influences sale price <--

	price = makeint(price * Charmod * sellMult); // TIH moved down here where it is SUPPOSED TO BE - NK now use central func 05-04-19
	
	int shipprice = price; //Levis used for if we have below 0 prices.
	
	//moved down so it isn't affected by the multiplier:
	price = price - GetSailRepairCost(GetCharacter(cn), GetSailDamagePercent(fourIdx)); // KK
	price = price - GetHullRepairCost(GetCharacter(cn), GetHullDamagePercent(fourIdx)); // KK
	
	//Levis take upgrades into account:
	string attributeName;
	int idx=0;
	for (int i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
		idx++;
		attributeName = "pic" + idx;
		string upgrade = GetShipUpgradeID(i);
		if (cn >= 0 && CheckTun(cn, upgrade) == true) {
			price += makeint(GetCostTun(cn, upgrade, PRICE_TYPE_SELL)/10); //If an upgrade is applied, you get a percentage of the real price. This can be max of 10%
		}
	}
	
	// TIH --> better accuracy to prevent price banging Jul27'06
	// prevents someone from buying a ship for a new captain, and turning around and selling
	// it for more than they just bought it for in the same interface session
	/*int baseCannonsType = CANNON_TYPE_NONECANNON;
	if(USE_REAL_CANNONS) 	baseCannonsType = CANNON_TYPE_LONG_LBS4;
	else 					baseCannonsType = CANNON_TYPE_CANNON_LBS12;
	// KK 
	price = price - GetCannonDeltaPrice(GetCharacter(cn), baseCannonsType, GetCannonQuantity(GetCharacter(cn)), GetCannonMaxQuantity(GetCharacter(cn)));
	// TIH <--*/
	
	price -= makeint(SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)))); //Levis just use the cannon sell price instead of the delta
	
	//Levis negative prices fix // PW: moved above cargo handler so you get cargo value plus minimum
	if(price<(shipprice * 0.05))
	{
		price = makeint(shipprice * 0.05); //5% of shipprice is the minimum you will get.
	}

	if ( cargoHandler == "includecargo" ) // TIH added handler Jul27'06
	{
		if(gprice[fourIdx] == -1)
		{
			gprice[fourIdx] = 0;
			// Viper - Add Cargo Value to Ship Price -->
			int p, tQuantity, Quantity, j ;	ref refStore;
			ref refCharacter = GetCharacter(cn);
			int curStoreIdx = GetCharacterCurrentStore(PChar);
			makeref (refStore, Stores[curStoreIdx]);
			for(i=0;i<GOODS_QUANTITY;i++)
			{
				// PW: Replacing Temp Fix -->
				p = 0;
				if( !GetStoreGoodsUsed(refStore,i) ) { continue; }
				tQuantity = GetCargoGoods(refCharacter,i);
				if( tQuantity==0 ) { continue; }
				int unitSize = sti(Goods[i].Units); //PW replacing --> Levis: TempFix
				Quantity = tQuantity/unitSize;
				for(j=0;j<Quantity;j++)
				{
					if (tradeLow==false) p += makeint(GetStoreGoodsPrice(&refStore, i, PRICE_TYPE_SELL, PChar, j)); //PW replacing //Levis: TempFix
					else p += makeint(GetStoreGoodsPrice(&refStore, i, PRICE_TYPE_SELL, PChar, j)/4*3);
				}

				gprice[fourIdx] += p;
				// PW: Replacing Temp Fix <--
			}
		}
		price += makeint(gprice[fourIdx]);
	}
	return price;
}

int GetSailDamagePercent(int fourIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetSailDamagePercent");
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return 0;
	return 100 - MakeInt(GetSailPercent(GetCharacter(cn)));
}

int GetHullDamagePercent(int fourIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetHullDamagePercent");
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return 0;
	return 100 - MakeInt(GetHullPercent(GetCharacter(cn)));
}

// KK -->
int GetScrollShipPriceByType(int st)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetScrollShipPriceByType");
	if(st==SHIP_NOTUSED) return 0;
	ref shref = GetShipByType(st);
	return sti(shref.price)*2; // PRS3
}
// <-- KK

// moved to cannons\cannons.c - NK 05-04-19 - int GetCannonPrice(int nCannonType)

int GetMyMoney()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetMyMoney");
	ref mychref = GetMainCharacter();
	return sti(mychref.Money);
}

//MAXIMUS -->
int GetExpDivider()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetExpDivider");
	aref curref = GetScrollShipAttr(nCurSScrollNum);
	int sc = sti(GetAttributeValue(curref));
	aref arCurShip; makearef(arCurShip, curref);
	int expDiv = sti(GetLocalShipAttrib(arCurShip, ShipsTypes[sc], "Class"));

	return expDiv;
}
//MAXIMUS <--

// TIH --> consolidated functions using proper calls instead Jul27'06
void DoSellShip(string crewHandler, string cargoHandler)
{
	int navycut = 0;
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoSellShip");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	int transferred_crew_quantity = 0;
	int residual_crew_quantity = 0;
	int cc = 0;
	int cmpidx;
	ref refChar;
	ref chref = GetCharacter(cn);
	int sellPrice = GetSellPrice(nCurFourNum,cargoHandler);
	// PW: navy officers get some personal wealth -->
	if (ShipAcquiredState(arCurShip) == "taken" && ProfessionalNavyNation() != UNKNOWN_NATION)
	{
		navycut = makeint(sellPrice * SHIPYARD_NAVY_WEALTH_MULT);
		AddWealthToCharacter(GetMainCharacter(), navycut);
	}
	AddMoneyToCharacter(GetMainCharacter(),sellPrice-navycut);
	// PW: navy officers get some personal wealth <--
	makearef(arCurShip, Characters[cn].ship); 
	ref		rShip = GetShipByID(arCurShip.Type);
	if(sellPrice != 0) sLogEntry += "Sold the '"+arCurShip.name+"', a "+XI_ConvertString(rShip.sname)+" for "+sellPrice+" pieces of gold. ";
	//MAXIMUS -->
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(GetMainCharacter(), "Commerce", makeint(sellPrice/sti(1000/GetExpDivider())));
		AddCharacterExpNSChar(shipwright, "Commerce", makeint(sellPrice/sti(1000/GetExpDivider())));
	}
	//MAXIMUS <--
	// NK -->
	if ( crewHandler == "firecrew" )
	{ // TIH added handler Jul27'06
// KK -->
		residual_crew_quantity = 0;
		transferred_crew_quantity = GetCrewQuantity(chref);
		for (cc = 0; cc < 4; cc++)
		{
			cmpidx = GetCompanionIndex(GetMainCharacter(), cc);
			if (cmpidx < 0 || cmpidx == cn) continue;
			refChar = GetCharacter(cmpidx);
			if (GetFreeCrewQuantity(refChar) < transferred_crew_quantity)
			{
				residual_crew_quantity = transferred_crew_quantity - GetFreeCrewQuantity(refChar);
				transferred_crew_quantity -= residual_crew_quantity;
			}
			AddCharacterCrew(refChar, transferred_crew_quantity);
		}
		if (residual_crew_quantity >= 0) SetTownCrewQuantity(sTownName, GetTownCrewQuantity(sTownName) + residual_crew_quantity); // NK 04-09-08 put fired crew in town
// <-- KK
	}
	nStoreMoney -= sellPrice;
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	// NK <--

	//Levis moved out of the if
	string lastSlot = GetAttributeName( GetAttributeN( arShipList, (GetAttributesNum(arShipList)-1) ) );
	string shipYardSlot = "ship" + ( sti( strcut(lastSlot, 4, strlen(lastSlot)-1) ) + 1);

	// TIH --> sy_rpg_style ship add to shipyard Jul27'06
	if ( SY_RPG_STYLE && CheckAttribute(chref,"ship.stats") ) {
		// since player sold a ship, add it to the shipyard listing

		arShipList.(shipYardSlot) = chref.ship.idx;
		arShipList.(shipYardSlot).stats = "";

		aref sto;
		aref sfrom;
		if(DEBUG_SHIPYARD_INTERFACE) trace("SY sell ship to shipyard, from idx: "+ chref.ship.idx +" to slot: "+shipYardSlot);
		makearef(sto, 	arShipList.(shipYardSlot).stats);
		makearef(sfrom, chref.ship.stats);
		CopyAttributes(sto, sfrom); //copy stats tree over
		//int PRIORnCurSScrollNum = nCurSScrollNum;// TIH save this to put it back after a sell (due to reset, baaaaaaad)
		//UpdateShipScroll();// refresh the listing
		//nCurSScrollNum = PRIORnCurSScrollNum;// TIH reset
	}
	// TIH <--

	DeleteAttribute(chref,"ship.sails");
	DeleteAttribute(chref,"ship.blots");
	chref.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
	chref.ship.idx = SHIP_NOTUSED; // PS for lookup
	DeleteAttribute(chref,"ship.stats"); // PRS3
//KB - Tuning ships - deleting tune attribute
	aref temparef;
	makearef(temparef,chref.ship);
	//Levis copy over tune tree
	if (CheckAttribute(temparef,"tune") ) {
		//arCurShip.tune = "";
		makearef(sto, 	arShipList.(shipYardSlot).tune);
		makearef(sfrom, temparef.tune);
		CopyAttributes(sto, sfrom);
		DeleteAttribute(temparef,"tune");
	}
// KB <---
	if ( CheckAttribute(chref,"ship.acquired") ) DeleteAttribute(chref,"ship.acquired");// TIH to remove this tag from the ship Jul27'06
	if ( cargoHandler == "includecargo" ) { // TIH added handler Jul27'06
		// Viper - Add Cargo Value to Ship Price -->
		int p, tQuantity;	ref refStore;
		ref refCharacter = GetCharacter(cn);
		int curStoreIdx = GetCharacterCurrentStore(GetMainCharacter());
		makeref (refStore, Stores[curStoreIdx]);
		//p = 0; // NK
		for(int i=0;i<GOODS_QUANTITY;i++)
		{
			if( !GetStoreGoodsUsed(refStore,i) ) { continue; }
			tQuantity = GetCargoGoods(refCharacter,i);
			if( tQuantity==0 ) { continue; }
			RemoveCharacterGoods(refCharacter,i,tQuantity);
			// NK -->
			//p += GetGoodPriceByType(&refStore, GetMainCharacter(), i, tQuantity, PRICE_TYPE_SELL);
			SetStoreGoods(refStore,i,GetStoreGoodsQuantity(refStore,i)+tQuantity);
		}
	}
	gprice[nCurFourNum] = -1;
}

/* depreciated Jul27'06
void DoSellShip2()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	ref chref = GetCharacter(cn);
	int sellPrice = GetSellPrice2(nCurFourNum);

	AddMoneyToCharacter(GetMainCharacter(),sellPrice);
	// NK -->
	nStoreMoney -= sellPrice;
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	gprice[nCurFourNum] = -1;
	// NK <--
	DeleteAttribute(chref,"ship.sails");
	DeleteAttribute(chref,"ship.blots");
	chref.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
	chref.ship.idx = SHIP_NOTUSED; // PS for lookup
	DeleteAttribute(chref,"ship.stats"); // PRS3
//KB - Tuning ships - deleting tune attribute
	aref temparef;
	makearef(temparef,chref.ship);
	if (CheckAttribute(temparef,"tune")) { DeleteAttribute(chref,"ship.tune"); }
// KB <---
}
*/

void DoBuyShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoBuyShip");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int st = GetScrollShipType(nCurSScrollNum); // PRS3 moved this line here

	// TIH --> fixed price bug Jul27'06
	int bPrice = GetBuyPrice(nCurSScrollNum);
	int sPrice = GetSellPrice(nCurFourNum,"skipcargo");
	int buyPrice = bPrice - sPrice;
	if ( IsMoneyForBuyEnable(bPrice, sPrice) > 0 ) return;
	// TIH <--

	ref chref = GetCharacter(cn);
	DoSellShip("keepcrew","keepcargo");// TIH keep any stuff around as we only swap ships (or add ship to companion) Jul27'06

	AddMoneyToCharacter(GetMainCharacter(),-bPrice); // PW was buyPrice ie the exchanged cost but you got the sell money as well
	sLogEntry += "Bought a new ship, the '"+GetMyShipName(chref)+"' for "+bPrice+" pieces of gold. "; // PW was buyPrice ie the exchanged cost but you got the sell money as well
	//MAXIMUS -->
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(GetMainCharacter(), "Commerce", makeint(buyPrice/sti(1000/GetExpDivider())));
		AddCharacterExpNSChar(shipwright, "Commerce", makeint(buyPrice/sti(1000/GetExpDivider())));
	}
	//MAXIMUS <--
  	// NK -->
  	nStoreMoney += bPrice;// PW was buyPrice ie the exchanged cost but you got the sell money as well
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	// NK <--
	if(st==SHIP_NOTUSED) return;

	ref brefShip = GetShipByType(st);

	chref.ship.type = GetShipID(st); // PS
	chref.ship.idx = st; // PS for lookup
	// PRS3 -->
	makearef(arCurShip, chref.ship);
	arCurShip.stats = "";
	//yes I know this is bloated. I just want to be sure it works.
	aref sto; makearef(sto, arCurShip.stats);
	aref stmp = GetScrollShipAttr(nCurSScrollNum);
	aref sfrom; makearef(sfrom, stmp.stats);
	CopyAttributes(sto, sfrom); //copy stats tree over
	// PRS3 <--
//KB - Tuning ships - copy tune tree over
	if (CheckAttribute(stmp,"tune") ) {
		arCurShip.tune = "";
		makearef(sto, arCurShip.tune);
		makearef(sfrom, stmp.tune);
		CopyAttributes(sto, sfrom);
		DeleteAttribute(stmp,"tune");
	}
// KB <---

	DeleteAttribute(chref,"ship.sails");
	DeleteAttribute(chref,"ship.blots");
	DeleteAttribute(chref,"ship.masts"); // NK
	chref.ship.sp = GetLocalShipAttrib(arCurShip, brefShip,"SP"); // PRS3
	chref.ship.hp = GetLocalShipAttrib(arCurShip, brefShip,"HP"); // PRS3
	chref.ship.acquired = "bought"; // TIH tag on how they acquired this ship (rpgstyle shipyard) Jul27'06
	DeleteAttribute(chref, "ship.cannons"); // delete cannons property to clear destroyable cannon state. 05-08-01
	if(USE_REAL_CANNONS) 	chref.ship.Cannons.Type = CANNON_TYPE_LONG_LBS4; // KNB
	else 					chref.ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12; // NK

	// TIH --> sy_rpg_style ship removal Jul27'06
	if ( SY_RPG_STYLE ) {
		// since player bought the ship, remove it from shipyard listing
		string boughtSlot = GetAttributeName( GetAttributeN( arShipList, nCurSScrollNum ) );
		if(DEBUG_SHIPYARD_INTERFACE) trace("SY buy ship, idx: "+ stmp +" slot: "+ boughtSlot);
		DeleteAttribute( arShipList, (boughtSlot) );
	}
	// TIH <--
}

void UpdateFourImages()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateFourImages");
/*	DeleteAttribute(&GameInterface,"FourImage");
	GameInterface.FourImage.current = nCurFourNum;
    FillFourImages();
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "SHIPSLIST", -1);
*/
	ref refMainCh = GetMainCharacter();

	int i,cn,tmpShipType;
	string tmp1,tmp2,tmpStr;

    for(i=0; i<4; i++)
    {
		tmpStr = "pic"+(i+1);
		DeleteAttribute(&GameInterface,"FourImage."+tmpStr);

		tmpShipType = SHIP_NOTUSED;
		cn = GetCompanionIndex(refMainCh,i);
		if(cn!=-1)	tmpShipType = GetCharacterShipType(GetCharacter(cn));
		GameInterface.FourImage.(tmpStr).selected = cn!=-1 || nAllPassngerQuantity>0;

		if(tmpShipType==SHIP_NOTUSED)
		{
			if(cn>=0)
			{
				GameInterface.FourImage.(tmpStr).img1 = GetFacePicName(GetCharacter(cn));
				GameInterface.FourImage.(tmpStr).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
				continue;
			}
			tmp1="";
			tmp2="";
		}
		else
		{
			ref baseShip = &ShipsTypes[tmpShipType];
			//tmp1 = baseShip.Class;
			//tmp2 = baseShip.SName; // PS
			// PRS3 -->
			makearef(arCurShip, Characters[cn].ship);
			tmp1 = GetLocalShipAttrib(arCurShip, baseShip, "Class");
			tmp2 = GetLocalShipAttrib(arCurShip, baseShip, "SName");
			// PRS3 <--
		}

		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		GameInterface.FourImage.(tmpStr).img2		= GetShipPicName(tmpShipType); // PS
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= GetShipString(tmpShipType); //PS tempfix XI_ConvertString(tmp2);;
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpShipType); // PS
    }

	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "SHIPSLIST", -1);
}

void UpdateShipScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateShipScroll");
	DeleteAttribute(&GameInterface,"scrollitems");
	GameInterface.scrollitems.current = nCurSScrollNum;
    FillSScroll();
    SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLITEMS",-1);
}

void UpdateFaceScroll()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateFaceScroll");
	nCurFScrollNum = -1;// TIH bugfix
	GameInterface.passengers.current = 0;// TIH bugfix
	// Delete old attributes
	int charQuantity = sti(GameInterface.passengers.ListSize);
	for(int i=0; i<charQuantity; i++)
	{
		attributeName = "passengers.pic" + (i+1);
		DeleteAttribute(&GameInterface, attributeName);
	}

	ref charRef;
	string attributeName;
	nAllPassngerQuantity = 0;
	int cn = GetPassengerFromScroll(0);
	while(cn>=0)
	{
		attributeName = "pic" + (nAllPassngerQuantity+1);
		charRef = GetCharacter(cn);
		GameInterface.passengers.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers.(attributeName).tex1 = FindFaceGroupNum("passengers.ImagesGroup","FACE128_"+charRef.FaceID);
		nAllPassngerQuantity++;
		cn=GetPassengerFromScroll(nAllPassngerQuantity);
	}
	GameInterface.passengers.ListSize = nAllPassngerQuantity;
	//if( nCurSScrollNum >= nAllPassngerQuantity ) nCurSScrollNum = nAllPassngerQuantity;// TIH bugfix
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"PASSENGERS",-1);
}

void UpdateCompanionCharacter()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("UpdateCompanionCharacter");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int nn = GetPassengerFromScroll(nCurFScrollNum);
	if(nn==cn) return;
	if(nn>=0 && GetRemovable(GetCharacter(nn))==false) return;

	if(nn<0)	{DoSellShip("firecrew","includecargo");}// TIH added handlers Jul27'06

	if( nn>=0 && cn>=0 )	ExchangeCharacterShip(GetCharacter(nn),GetCharacter(cn));

	if(nn>=0) RemovePassenger(GetMainCharacter(),GetCharacter(nn));
	SetCompanionIndex(GetMainCharacter(),nCurFourNum,nn);
	makearef(arCurShip, Characters[nn].ship); // PRS3
	// NK get back officers 05-04-18 -->
	if(cn>=0)
	{
		AddPassenger(GetMainCharacter(),GetCharacter(cn),false);
		int on;
		for(int i = 1; i < 4; i++)
		{
			on = SetOfficersIndex(GetCharacter(cn),i,-1);	// TIH remove the officer from the old captain, otherwise doubles get made
			if(on != -1) AddPassenger(GetMainCharacter(), GetCharacter(on), false);
		}
	}
	// NK <--

	UpdateFaceScroll();
	UpdateFourImages();
	UpdateShipScroll();// TIH update
}

void FireCaptain()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FireCaptain");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	// NK get back officers 05-04-18 -->
	int on;
	for(int i = 1; i < 4; i++)
	{
		on = SetOfficersIndex(GetCharacter(cn),i,-1);	// TIH remove the officer from the old captain, otherwise doubles get made
		if(on != -1) AddPassenger(GetMainCharacter(), GetCharacter(on), false);
	}
	// NK <--
	DoSellShip("firecrew","includecargo");// TIH added handlers Jul27'06

	SetCompanionIndex(GetMainCharacter(),nCurFourNum,-1);
	AddPassenger(GetMainCharacter(),GetCharacter(cn),false);

	UpdateFaceScroll();
	UpdateFourImages();
	UpdateShipScroll();// TIH update
}

void DoShipParametersClamp()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoShipParametersClamp");
	ref mchref = GetMainCharacter();
	ref chref;
	int i,cn,st,pq;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			st = GetCharacterShipType(chref);
			if(st==SHIP_NOTUSED)
			{
				ClampShipToEmpty(chref);
				if(i>0)
				{
					//JA22Nov06 remove companions officers -->
					int on;
					for(int j = 1; j < 4; j++)
						{
							on = SetOfficersIndex(chref,j,-1);
							if(on != -1) AddPassenger(mchref, GetCharacter(on), false);
						}
						// <-- JA
					SetCompanionIndex(mchref,i,-1);
					AddPassenger(mchref,chref,false);
				}
			}
			else {
				ClampShipToType(chref);
			}
		}
	}

	pq = GetPassengersQuantity(mchref);
	for(i=0; i<pq; i++)
	{
		cn = GetPassenger(mchref,i);
		if(cn>=0) {
			ClampShipToEmpty(GetCharacter(cn));
		}
	}
}

void ClampShipToEmpty(ref chref)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ClampShipToEmpty");
	string sname = "";
	if(CheckAttribute(chref,"ship.name")) {
		sname = chref.ship.name;
	}
	if( sti(chref.index)==GetMainCharacterIndex() )
	{
		if( CheckAttribute(chref,"location.from_sea") ) {
			if( !CheckAttribute(chref,"location.old_from_sea") ) {
				chref.location.old_from_sea = chref.location.from_sea;
			}
			chref.location.from_sea = "";
			SetFleetInTown(GetTownIDFromLocID(chref.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
		}
	}
	DeleteAttribute(chref,"ship");
	chref.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
	chref.ship.idx = SHIP_NOTUSED; // PS
	if(sname=="") {
		SetRandomNameToShip(chref);
	}
	else {
		chref.ship.name = sname;
	}
}

void ClampShipToType(ref chref)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ClampShipToType");
	//tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int i;
	int st = GetCharacterShipType(chref);
	ref base_ship = GetShipByType(st);
	aref arship; makearef(arship, chref.ship); // PRS3
	int mcrew = sti(GetLocalShipAttrib(arship, base_ship,"MaxCrew")); // PRS3

	if(GetCrewQuantity(chref)>mcrew)
	{
		SetTownCrewQuantity(sTownName, GetTownCrewQuantity(sTownName) + (GetCrewQuantity(chref) - mcrew)); // NK 04-09-08 put crew in town
		chref.Ship.Crew.Quantity = mcrew;
	}

	if(!CheckAttribute(chref,"Ship.Name"))
	{
		SetRandomNameToShip(chref);
	}

	int gq[GOODS_QUANTITY]; // NK
	string goods_id;

	chref.Ship.Pos.x = 0;
	chref.Ship.Pos.z = 0;
	chref.Ship.Ang = "";
	chref.Ship.Cannons.Borts = "";
	for(int ca = 0; ca < 4; ca++) { SetCannonArcQty(&chref, ca, GetCannonArcQty(&chref, ca)); } // NK cannon qty 05-04-18
	if(sti(chref.index) == GetMainCharacterIndex()) { chref.Ship.Cannons.Charge.Type = DEFAULT_CHARGE; }
	else { chref.Ship.Cannons.Charge.Type = GOOD_BALLS; } // NK 04-09-16 so player can choose default loadout
	if (!CheckAttribute(chref,"Ship.Cannons.Type")) { chref.Ship.Cannons.Type = MakeInt(base_ship.Cannon); }
	// NK 04-09-08 check town crew quantity -->
	if (!CheckAttribute(chref,"Ship.Crew.Morale"))	{ chref.Ship.Crew.Morale = GetTownCrewMorale(sTownName);	}
	int tmpcrew = 1; if(AUTOHIRECREW_ONCHANGESHIP) tmpcrew = mcrew;
	// NK add cost 05-04-18 -->
	int hcrew = 0;
	if(GetCrewQuantity(chref) < tmpcrew)
	{
		if(GetTownCrewQuantity(sTownName) >= mcrew - GetCrewQuantity(chref))
		{
			//SetTownCrewQuantity(sTownName, GetTownCrewQuantity(sTownName) - (mcrew - GetCrewQuantity(chref)));
			hcrew = mcrew - GetCrewQuantity(chref);

		}
		else
		{
			/*chref.Ship.Crew.Quantity += GetTownCrewQuantity(sTownName); // 04-10-25 OmegaRED
			SetTownCrewQuantity(sTownName, 0);*/
			hcrew = GetTownCrewQuantity(sTownName);
		}
		int ccost = GetCrewHireCost(GetMainCharacter());
		int pmoney = GetCharacterMoney(GetMainCharacter());
		if(hcrew * ccost > pmoney)
		{
			hcrew = pmoney / ccost;
		}
		AddMoneyToCharacter(GetMainCharacter(), -hcrew*ccost);		// this happens if you just LOOK at selling a ship LDH 26Nov06
		SetTownCrewQuantity(sTownName, GetTownCrewQuantity(sTownName) - hcrew);
		chref.Ship.Crew.Quantity = GetCrewQuantity(chref) + hcrew;
		// NK <--
	}
	// NK <--

	// loop through goods to see what existed in old ship
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(!CheckAttribute(Goods[i],"name")) continue; // NK
		goods_id = Goods[i].name;
		if( CheckAttribute(chref,"Ship.Cargo.Goods."+goods_id) )
		{
			gq[i] = sti(chref.Ship.Cargo.Goods.(goods_id));
		}
		else
		{
			gq[i] = 0;
		}
		chref.Ship.Cargo.Goods.(goods_id) = 0;
	}
	chref.Ship.Cargo.Load = 0;

	// loop through all the goods of the old ship, to see if they fit in the new ship - sell what doesnt fit
	int minnumdaysrations = 10;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		int oldq, pricediff, Quantity, j;
		pricediff = 0;
		int mcmoney = GetCharacterMoney(GetMainCharacter());
		ref cstore = &Stores[GetCharacterCurrentStore(GetMainCharacter())];
        if(FOOD_ON == 1 && i == GOOD_WHEAT && gq[i] < makeint(sti(chref.ship.crew.quantity) * FOOD_PER_CREW * minnumdaysrations))
		{
			oldq = gq[i];
			gq[i] = makeint(sti(chref.ship.crew.quantity) * FOOD_PER_CREW * minnumdaysrations); // 10 days worth of food in case of need.
		//	pricediff = GetGoodPriceByType(&cstore, GetMainCharacter(), i, gq[i] - oldq, PRICE_TYPE_BUY); // PW: calc to match store
			pricediff = GetStoreGoodsPrice(&cstore, i, PRICE_TYPE_BUY, GetMainCharacter(), gq[i] - oldq); // PW: calc to (roughly) match store ie same function call
			// TIH --> fixed this so it doesn't plumment the player into debt ! Jul27'06
			if(mcmoney > pricediff)
			{
				AddStoreGoods(&cstore, i, -1 * (gq[i] - oldq));
				nStoreMoney += pricediff;
				AddMoneyToCharacter(GetMainCharacter(), -pricediff);
				//MAXIMUS -->
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(GetMainCharacter(), "Commerce", makeint(pricediff/sti(1000/GetExpDivider())));
				}
				//MAXIMUS <--
				Log_SetStringToLog(TranslateString("","Not enough food! Your purser makes an emergency purchase of") + " " + (gq[i]-oldq) + " " + TranslateString("","days' rations for the crew of the") + " " + GetMyShipNameShow(chref) + " " + TranslateString("","for a cost of") + " " + pricediff + " " + TranslateString("","Gold") + ".");
			}
			else
			{
				gq[i] = oldq;
				Log_SetStringToLog(TranslateString("","You are low on food! Purser could not buy more because you are low on money!"));
			}
			// TIH <--
		}
		Fantom_SetCharacterGoods(chref, i, gq[i]); // changed from SetCharacterGoods() to this by NK 05-08-01
		// Do check
		oldq = GetCargoGoods(&chref, i);
    	// --> Swindler 05-10-16: only make emergency pursue when FOOD_ON
    	// TIH --> why on earth FOR??? changed this so it sells ANY over quantity good!!! grrrr Jul27'06
        //if(FOOD_ON == 1 && oldq < gq[i]) {
        if(oldq < gq[i]) {
			// sold some
			//PW: method changed to equate to store prices -->
			Quantity = (gq[i] - oldq)/sti( Goods[i].Units );
			for(j=0; j<Quantity; j++)
			{
				if(tradeLow==false) pricediff += makeint(GetStoreGoodsPrice(&cstore, i, PRICE_TYPE_SELL, GetMainCharacter(), j));
				else 	pricediff += makeint(GetStoreGoodsPrice(&cstore, i, PRICE_TYPE_SELL, GetMainCharacter(), j)/4*3);
			}
			// PW <--
			AddStoreGoods(&cstore, i, gq[i] - oldq);
			nStoreMoney -= pricediff;
			AddMoneyToCharacter(GetMainCharacter(), pricediff);
			//MAXIMUS -->
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(GetMainCharacter(), "Commerce", makeint(pricediff/sti(1000/GetExpDivider())));
			}
			//MAXIMUS <--
			Log_SetStringToLog(TranslateString("","Too little room! Your purser makes an emergency sale of") + " " + (gq[i]-oldq) + " " + TranslateString("","units of") + " " + XI_ConvertString(Goods[i].Name) + " " + TranslateString("","from the") + " " + GetMyShipNameShow(chref) + " " + TranslateString("","for a total of") + " " + pricediff + " " + TranslateString("","Gold") + ".");
		}
	}
	SetTownGold(sTownName, nStoreMoney); // PW: added because changes to store money from excess cargo were not saved on exiting shipyard
	if( sti(chref.index)==GetMainCharacterIndex() )
	{
		if( CheckAttribute(chref,"location.old_from_sea") ) {
			chref.location.from_sea = chref.location.old_from_sea;
			SetFleetInTown(GetTownIDFromLocID(chref.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			DeleteAttribute(chref,"location.old_from_sea");
		}
	}
	//LanguageCloseFile(tmpLangFileID);
}

void DoSailRepairToPercent(ref chref,int toPerc)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoSailRepairToPercent");
	ref mchref = GetMainCharacter();

	int cursp = MakeInt(GetSailPercent(chref));
	if(cursp>=toPerc) return;

	makearef(arCurShip, chref.ship); // PRS3

	// TIH --> proper way to handle this Jul27'06
	int sailRepairCost = GetSailRepairCost(chref, toPerc-cursp); // KK
	// TIH <--

	int nMyMoney = GetMyMoney();
	while(nMyMoney<sailRepairCost)
	{
		toPerc--;
		if(cursp>=toPerc) return;
		sailRepairCost = GetSailRepairCost(chref, toPerc-cursp); // KK
	}

	AddMoneyToCharacter(mchref,-sailRepairCost);
	sLogEntry += "Had the sails of the '"+arCurShip.name+"' repaired for "+sailRepairCost+" pieces of gold. ";

	// ccc feb05 shipyard waiting
	daystowait += 1+makeint(sqrt(sailRepairCost/1000));
	// ccc end

	// NK -->
	nStoreMoney += sailRepairCost;
	GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	// NK <--

	// LDH moved up so skill system can be used on repairs here - 25Feb09
	float fsail = MakeFloat(toPerc) - GetSailPercent(chref);
	ProcessSailRepair(chref,fsail);

	if(toPerc>=100)
	{
		chref.ship.sp = GetCharacterShipSP(chref);
		DeleteAttribute(chref,"ship.sails");
		DeleteAttribute(chref,"ship.masts");
	}
	else
	{
		chref.ship.sp = CalculateShipSP(chref);
	}

	SetFleetAtShipyard(); // KK
}

void DoHullRepairToPercent(ref chref,int toPerc)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoHullRepairToPercent");
	ref mchref = GetMainCharacter();

	int curhp = MakeInt(GetHullPercent(chref));
	if(curhp>=toPerc) return;
	makearef(arCurShip, chref.ship); // PRS3

	// TIH --> proper way to handle this Jul27'06
	int hullRepairCost = GetHullRepairCost(chref, toPerc-curhp); // KK
	// TIH <--

	int nMyMoney = GetMyMoney();
	while(nMyMoney<hullRepairCost)
	{
		toPerc--;
		if(curhp>=toPerc) return;
		hullRepairCost = GetHullRepairCost(chref, toPerc-curhp); // KK
	}

	AddMoneyToCharacter(mchref,-hullRepairCost);
	sLogEntry += "Had the hull of the '"+arCurShip.name+"' repaired for "+hullRepairCost+" pieces of gold. ";

	// ccc feb05 shipyard waiting
	daystowait += 1+makeint(sqrt(hullRepairCost/1000));
	// ccc end

	// NK -->
	nStoreMoney += hullRepairCost;
	GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	// NK <--

	// LDH moved up so skill system can be used on repairs here - 25Dec08
	float fhull = MakeFloat(toPerc) - GetHullPercent(chref);
	ProcessHullRepair(chref,fhull);

	if(toPerc==100)
	{
		chref.ship.hp = GetCharacterShipHP(chref);
		DeleteAttribute(chref,"ship.blots");
	}
	else
	{
		chref.ship.hp = GetCharacterShipHP(chref)*toPerc/100.0+0.01;
	}

	SetFleetAtShipyard(); // KK
}

// LDH --> 27Sep06
void DoCannonRepair(ref chref)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("DoCannonRepair");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int gunRepairCost = 0;
	if (cn>=0) gunRepairCost = BuyCannons(chref, sti(chref.ship.cannons.type), GetCannonMaxQuantity(chref) - GetCannonQuantity(chref)); // PB
	if (gunRepairCost == 0) return;
	if (LAi_IsCapturedLocation) gunRepairCost = 0; // KK
	if (GetMyMoney() >= gunRepairCost) // KK
	{
		RepairAllCannons(chref);
		ResetCannons(chref);
		AddMoneyToCharacter(GetMainCharacter(),-gunRepairCost);
		sLogEntry += "Had the cannons of the '"+arCurShip.name+"' repaired for "+gunRepairCost+" pieces of gold. ";
		nStoreMoney += gunRepairCost;
		GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),MONEY_SIGN,MONEY_DELIVER);
		GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
		if(AUTO_SKILL_SYSTEM)
		{
			if(!CheckAttribute(GetMainCharacter(),"gained_repair_cannon"))
			{
				AddPartyExpChar(GetMainCharacter(), "Repair", makeint(gunRepairCost/100));
				characters[GetMainCharacterIndex()].gained_repair_cannon = gunRepairCost;
			}
		}

		SetFleetAtShipyard(); // KK
	}
}
// LDH <--

// KK -->
void SetFleetAtShipyard()
{
	if (VanderdeckenShipyard()) return; // PB: Abort this if you're at Isla da Muerte
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetFleetAtShipyard");
	ref mchref = GetMainCharacter();
	ref rTown = GetCurrentTown();
	if (CheckAttribute(rTown, "boarding.l1")) {
		SetCharacterShipLocation(mchref, rTown.boarding.l1);
		mchref.location.from_sea = rTown.boarding.l1;
		PlaceFleetNearShore(mchref.location.from_sea);
	}
}
// <-- KK

void ChangeHullRepair(int delta)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ChangeHullRepair");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	makearef(arCurShip, Characters[cn].ship); // PRS3

	int newHP = nhpRepair + delta;
	if(newHP>100)
	{
		newHP = 100;
	}

	int curHP = MakeInt(GetHullPercent(GetCharacter(cn)));
	if(newHP<curHP)
	{
		newHP = curHP;
	}

	// TIH --> proper way to handle this Jul27'06
	int price = GetHullRepairCost(GetCharacter(cn), newHP-curHP); // KK
	// TIH <--

	while(GetMyMoney()<price)
	{
		newHP--;
		price = GetHullRepairCost(GetCharacter(cn), newHP-curHP); // KK
	}

	if(newHP==nhpRepair) return;
	nhpRepair = newHP;

    GameInterface.strings.HullPercent = nhpRepair + "%";
    GameInterface.strings.RepairHullCost = MakeMoneyShow(price,MONEY_SIGN,MONEY_DELIVER); // NK
}

void ChangeSailRepair(int delta)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ChangeSailRepair");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	makearef(arCurShip, Characters[cn].ship); // PRS3

	int newSP = nspRepair + delta;
	if(newSP>100)
	{
		newSP = 100;
	}

	int curSP = MakeInt(GetSailPercent(GetCharacter(cn)));
	if(newSP<curSP)
	{
		newSP = curSP;
	}

	// TIH --> proper way to handle this Jul27'06
	int price = GetSailRepairCost(GetCharacter(cn), newSP-curSP); // KK
	// TIH <--

	while(GetMyMoney()<price)
	{
		newSP--;
		price = GetSailRepairCost(GetCharacter(cn), newSP-curSP); // KK
	}

	if(newSP==nspRepair) return;
	nspRepair = newSP;

    GameInterface.strings.SailsPercent = nspRepair + "%";
    GameInterface.strings.RepairSailsCost = MakeMoneyShow(price,MONEY_SIGN,MONEY_DELIVER); // NK
}

void EnableChooseButtons()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("EnableChooseButtons");
	//SetNodeUsing( "BUY_BUTTON", IsEnableBuyShip() ); // KK
	//SetSelectable( "BUY_BUTTON", IsEnableBuyShip() );
	SetSelectable( "REPAIR_BUTTON", IsEnableRepairShip() );
	SetSelectable( "SELLSHIP_BUTTON", IsEnableSellShip() );
	SetSelectable( "CHANGE_CAPTAIN", IsEnableChangeCaptain() );
}

string GetNextChoose(string curChoose, bool bUpDirection)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetNextChoose");
	switch(curChoose)
	{
	/*	case "BUY_BUTTON":
			if(bUpDirection)	{return "";}
			else	{return "REPAIR_BUTTON";}
		break;*/
		case "SELLSHIP_BUTTON":
			if (bUpDirection) return "CHANGE_CAPTAIN"; else return "REPAIR_BUTTON";
		break;
		case "REPAIR_BUTTON":
			if (bUpDirection) return "SELLSHIP_BUTTON"; else return "CHANGE_CAPTAIN";
		break;
		case "CHANGE_CAPTAIN":
			if (bUpDirection) return "REPAIR_BUTTON"; else return "BACK_BUTTON";
		break;
		case "BACK_BUTTON":
			if (bUpDirection) return "CHANGE_CAPTAIN"; else return "SELLSHIP_BUTTON";
		break;
	}
}

void ChooseButtonTopSelect()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ChooseButtonTopSelect");
	string nextNode = "SELLSHIP_BUTTON";
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextChoose(nextNode, false);
	}
}

void ChooseButtonNextSelect(string chooseBtnName, bool bUpDirection)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ChooseButtonNextSelect");
	string nextNode = GetNextChoose(chooseBtnName, bUpDirection);
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextChoose(nextNode, bUpDirection);
	}
}

bool IsEnableBuyShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsEnableBuyShip");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if( !GetRemovable(chref) ) return false;
	if(	CheckForContraband(chref)) return false;
	ref pchar = GetMainCharacter();

	if (VanderdeckenShipyard()) return true;
	// TIH --> sy_rpg_style cannot buy outclassed ships Jul27'06
	if ( SY_RPG_STYLE ) {
		//int mcL = GetLevel(GetMainCharacter());
		//int allowedClass = iclamp(1,8 , makeint( 8 - roundup(mcL / SHIPYARD_RPG_LPC) ));
		// for every SHIPYARD_RPG_LPC levels, they gain access to next class (8 is always available)
		//if ( sti(GetLocalShipAttrib(arCurShip, ShipsTypes[st],"Class")) < allowedClass ) {
		//	return false;
		//}
		string attributeName = "pic" + (nCurSScrollNum+1);
		if ( CheckAttribute(GameInterface,"scrollitems."+(attributeName)+".skipsell") ) {
			if ( GameInterface.scrollitems.(attributeName).skipsell==true ) return false;
		}
	}
	// TIH <--
	return GetShipRemovable(chref);
}

bool IsEnableSellShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsEnableSellShip");
	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar,nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if(CheckForContraband(chref))
	{
		EnableString("HelpString");
		SetNodeUsing("BOX1",true);
		SetNodeUsing("BOX1_RAMKA", true);
		GameInterface.strings.HelpString = "Cannot Sell - Contraband on board";
		return false;
	}
	if(IsMainCharacter(chref) && ProfessionalNavyNation() != UNKNOWN_NATION && GetRank(PChar, GetServedNation()) < 10)
	{
		return false;
	}
	if( GetCharacterShipType(chref)==SHIP_NOTUSED ) return false;
	if(!GetRemovable(chref) ) return false;

// PB -->
	string SellButton = "Sell";
	makearef(arCurShip, Characters[cn].ship); // PRS3
	switch (ShipAcquiredState(arCurShip))
	{
		case "bought":	SellButton = "Sell Owned Ship";		break;
		case "taken":	SellButton = "Auction Prize Ship";	break;
		case "pirated":	SellButton = "Sell Pirated Ship";	break;
	}
	SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "SELLSHIP_BUTTON", 0, SellButton);
// PB <--

	return GetShipRemovable(chref);
}

bool IsEnableRepairShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsEnableRepairShip");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if( GetCharacterShipType(chref)==SHIP_NOTUSED ) return false;
	// LDH --> 27Sep06
	int gcost = 0;
	if (cn>=0) gcost = BuyCannons(chref, sti(chref.ship.cannons.type), GetCannonMaxQuantity(chref) - GetCannonQuantity(chref)); // PB
	// LDH <--

	// KK if( GetCharacterShipType(chref)==SHIP_NOTUSED ) return false;
	if( GetSailPercent(chref)>=100.0 && GetHullPercent(chref)>=100.0 && gcost==0 ) return false; // LDH 27Sep06
	return true;
}

bool IsEnableChangeCaptain()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsEnableChangeCaptain");
	if(nCurFourNum<1) return false;
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn>=0)
	{
		ref chref = GetCharacter(cn);
		if( !GetRemovable(chref) ) return false;
	}
	return true;
}

int IsMoneyForBuyEnable(int buyPrice, int sellPrice)
{
	int money 		= GetMyMoney(); //Levis shipyard optimalization now uses function
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsMoneyForBuyEnable");
	//int sellPrice 	= GetSellPrice(nCurFourNum,"skipcargo"); // TIH added handler Jul27'06 // Viper - dont add Cargo Value to Ship Price
	//int st 		= GetScrollShipType(nCurSScrollNum); // PRS3 moved line here// TIH not needed anymore because we use proper check now Jul27'06
	//int buyPrice 	= (GetBuyPrice(nCurSScrollNum)-sellPrice);//GetShipPriceByType(st);// TIH this wasn't using the proper check Jul27'06 //Levis Shipyard optimalization now uses previously defined sellprice
	if(money < (buyPrice - sellPrice)) return 1;
	if(nStoreMoney < sellPrice) return 2;
	return 0;
}

// NK -->
bool IsMoneyForSellEnable()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("IsMoneyForSellEnable");
	//int st = GetScrollShipType(nCurSScrollNum);// TIH not needed Jul27'06
	int sellPrice = GetSellPrice(nCurFourNum,"includecargo"); // TIH added handler Jul27'06 // Viper - Add Cargo Value to Ship Price
	if(sellPrice > nStoreMoney) return false;
	return true;
}
// NK <--

void SetCaptainButtonsEnable()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetCaptainButtonsEnable");
	bool bRemoveEnable = true;
	bool bSetEnable = true;

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0 || !GetRemovable(GetCharacter(cn)) )	bRemoveEnable = false;

	int nn = GetPassengerFromScroll(nCurFScrollNum);
	if(nn==cn)	bSetEnable = false;
	if( nn>=0 && !GetRemovable(GetCharacter(nn)) )	bSetEnable = false;
	if( nn<0 )	bSetEnable = false;

	SetSelectable("SKILLINFO_BUTTON", nChrIdxForInfo>=0);
	SetSelectable("REMOVEC_BUTTON", bRemoveEnable);
	SetSelectable("SETC_BUTTON", bSetEnable);
}

void SelectCaptainButton()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SelectCaptainButton");
	if( GetSelectable("SKILLINFO_BUTTON") ) {SetCurrentNode("SKILLINFO_BUTTON");}
	else
	{
		if( GetSelectable("REMOVEC_BUTTON") ) {SetCurrentNode("REMOVEC_BUTTON");}
		else
		{
			if( GetSelectable("SETC_BUTTON") ) {SetCurrentNode("SETC_BUTTON");}
			else {SetCurrentNode("PASSENGERS");}
		}
	}
}

string GetNextCaptainButton(string curNode, bool bUpDirection)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetNextCaptainButton");
	switch(curNode)
	{
	case "PASSENGERS":
		if(bUpDirection) {return "";}
		else {return "SKILLINFO_BUTTON";}
	break;

	case "SKILLINFO_BUTTON":
		if(bUpDirection) {return "PASSENGERS";}
		else {return "REMOVEC_BUTTON";}
	break;

	case "REMOVEC_BUTTON":
		if(bUpDirection) {return "SKILLINFO_BUTTON";}
		else {return "SETC_BUTTON";}
	break;

	case "SETC_BUTTON":
		if(bUpDirection) {return "REMOVEC_BUTTON";}
		else {return "";}
	break;
	}
	return "";
}

void SetNextCaptainButton(string curNode, bool bUpDirection)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetNextCaptainButton");
	string nextNode = GetNextCaptainButton(curNode, bUpDirection);
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextCaptainButton(nextNode, bUpDirection);
	}
	SetCurrentNode(curNode);
}

void SetSkillData()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetSkillData");
	if(nChrIdxForInfo<0)
	{
		GameInterface.strings.CharacterName = "";
		GameInterface.strings.skillLeadership = "0";
		GameInterface.strings.skillFencing = "0";
		GameInterface.strings.skillSailing = "0";
		GameInterface.strings.skillAccuracy = "0";
		GameInterface.strings.skillCannons = "0";
		GameInterface.strings.skillGrappling = "0";
		GameInterface.strings.skillRepair = "0";
		GameInterface.strings.skillDefence = "0";
		GameInterface.strings.skillCommerce = "0";
		GameInterface.strings.skillSneak = "0";
		return;
	}
	ref chref = GetCharacter(nChrIdxForInfo);
	GameInterface.strings.CharacterName   = GetCharacterFullName(chref.id) +" - " + XI_ConvertString("S"+chref.quest.officertype);
	GameInterface.strings.skillLeadership = CalcCharacterSkill(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing    = CalcCharacterSkill(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing    = CalcCharacterSkill(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy   = CalcCharacterSkill(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons    = CalcCharacterSkill(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling  = CalcCharacterSkill(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair     = CalcCharacterSkill(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence    = CalcCharacterSkill(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce   = CalcCharacterSkill(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak      = CalcCharacterSkill(chref,SKILL_SNEAK);
}

void SetCharacterToInfoCharacter(int nInfoChrIdx)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetCharacterToInfoCharacter");
	nChrIdxForInfo = nInfoChrIdx;
	if(nInfoChrIdx<0)
	{
		GameInterface.strings.CharacterName = "";
		return;
	}

	if(CheckAttribute(Characters[nInfoChrIdx],"quest.officertype")) GameInterface.strings.CharacterName = GetCharacterFullName(Characters[nInfoChrIdx].id) +" - " + XI_ConvertString("S"+Characters[nInfoChrIdx].quest.officertype);
	else GameInterface.strings.CharacterName = GetCharacterFullName(Characters[nInfoChrIdx].id) +" - " + XI_ConvertString("SComrade-In-Arms");
}

// KK -->
void ProcessBuyShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessBuyShip");
	ref mchr = GetMainCharacter();
	if(ProfessionalNavyNation() != UNKNOWN_NATION && GetRank(GetMainCharacter(), GetServedNation()) < 10)
	{
		return;
	}
	int st = GetScrollShipType(nCurSScrollNum);
	if (st < 0) return;
	//if (!LAi_IsCapturedLocation) {
		int bPrice = GetBuyPrice(nCurSScrollNum);
		int sPrice = GetSellPrice(nCurFourNum,"skipcargo");
		int buyPrice = bPrice - sPrice;
		if( IsEnableBuyShip() && IsMoneyForBuyEnable(bPrice, sPrice) == 0 && !LAi_IsCapturedLocation)
		{
			FreezeScreen(true);
			nShowMode = ISHOW_MODE_BUY;
			SetNodeUsing("CONFIRM_RECTANGLE", true);
			SetNodeUsing("TEXTWINDOW", true);
			SetNodeUsing("CONFIRM_YES_BUTTON", true);
			SetNodeUsing("CONFIRM_NO_BUTTON", true);
			SetNodeUsing("SHIPBUYSELL_PIC", true);
			SetCurrentNode("CONFIRM_YES_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");
			string text = "";
			string acquired = "";
			switch (ShipAcquiredState(arCurShip))
			{
				case "bought":	acquired = "owned ship ";		break;
				case "taken":	acquired = "auction prize ";	break;
				case "pirated":	acquired = "pirated ship ";		break;
			}

			if (EnableLimitedShipClass() && GetShipMinClassForCharacter(mchr) > sti(ShipsTypes[st].Class)) text = TranslateString("", "This officer has too low Leadership and Sailing skills to command this ship.") + GlobalStringConvert("newline");
			text += TranslateString("", "Buy this ship for") + " " + MakeMoneyShow(buyPrice,MONEY_SIGN,MONEY_DELIVER) + "?";
			if (sPrice>0) text += TranslateString("", " ") + GlobalStringConvert("newline") + acquired + "trade-in " + MakeMoneyShow(sPrice,MONEY_SIGN,MONEY_DELIVER) + "  new ship price " + MakeMoneyShow(bPrice,MONEY_SIGN,MONEY_DELIVER);
			SetFormatedText("TEXTWINDOW", text);
		}
	/*} else {
		DoBuyShip();
		UpdateFourImages();
		UpdateShipScroll();
		SetCurrentNode("SHIPSLIST");
		nCurSScrollNum = -1;
		nCurFourNum = -1;
	}*/ //Why would we want this? We can just add a check to set the buyprice to 0 right?
}

void BuyShipCancel()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("BuyShipCancel");
	nShowMode = ISHOW_MODE_VIEW;
	FreezeScreen(false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("CONFIRM_RECTANGLE", false);
	SetNodeUsing("TEXTWINDOW", false);
	SetNodeUsing("CONFIRM_YES_BUTTON", false);
	SetNodeUsing("CONFIRM_NO_BUTTON", false);
	SetNodeUsing("SHIPBUYSELL_PIC", false);
	SetNodeUsing("SKILL_PIC", false);
	SetCurrentNode("SCROLLITEMS");
}

void ProcessSellShip()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessSellShip");
	ref mchr = GetMainCharacter();
	int cn = GetCompanionIndex(mchr, nCurFourNum);
	if (cn < 0) return;
	makearef(arCurShip, Characters[cn].ship);
	int st = GetShipIndex(arCurShip.Type);
	if (st < 0) return;
	if (!LAi_IsCapturedLocation)
	{
		if( IsEnableSellShip() && IsMoneyForSellEnable())  // Sulan: fixed
		{
			FreezeScreen(true);
			nShowMode = ISHOW_MODE_SELL;
			SetNodeUsing("CONFIRM_RECTANGLE", true);
			SetNodeUsing("TEXTWINDOW", true);
			SetNodeUsing("CONFIRM_YES_BUTTON", true);
			SetNodeUsing("CONFIRM_NO_BUTTON", true);
			SetNodeUsing("SHIPBUYSELL_PIC", true);
			SetCurrentNode("CONFIRM_YES_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");
			int shipCost1 = GetSellPrice(nCurFourNum,"includecargo");
			string acquired = "";
			switch (ShipAcquiredState(arCurShip))
			{
				case "bought":	acquired = "owned ship ";		break;
				case "taken":	acquired = "auction prize ";	break;
				case "pirated":	acquired = "pirated ship ";		break;
			}
			string text = TranslateString("", "Sell this ") + acquired + "for" + " " + MakeMoneyShow(GetSellPrice(nCurFourNum,"includecargo"),MONEY_SIGN,MONEY_DELIVER) + "?" + GlobalStringConvert("newline") + "of which " + MakeMoneyShow(shipCost1 - gPrice[nCurFourNum],MONEY_SIGN,MONEY_DELIVER) + " is ship and " + MakeMoneyShow((gPrice[nCurFourNum]),MONEY_SIGN,MONEY_DELIVER) + " is cargo";
			SetFormatedText("TEXTWINDOW", text);
		}
		else
		{
			if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessSellShip - something went wrong."); // Sulan: just for debugging.
    	}
	} else {
		DoSellShip("firecrew","includecargo");
		UpdateFourImages();
		UpdateShipScroll();
		SetCurrentNode("SHIPSLIST");
		nCurSScrollNum = -1;
		nCurFourNum = -1;
	}
}

void ProcessSelectCaptain()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessSelectCaptain");
	if (EnableLimitedShipClass() && CheckFleetShips(true) && GetShipSkill(GetMainCharacter(), SKILL_LEADERSHIP) < FLEETCOMMAND_MIN_LEVEL) {
		FreezeScreen(true);
		nShowMode = ISHOW_MODE_CHOOSE;
		SetNodeUsing("CONFIRM_RECTANGLE", true);
		SetNodeUsing("TEXTWINDOW", true);
		SetNodeUsing("CONFIRM_YES_BUTTON", true);
		SetNodeUsing("CONFIRM_NO_BUTTON", true);
		SetNodeUsing("SKILL_PIC", true);
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");
		SetFormatedText("TEXTWINDOW", TranslateString("", "You can't command a fleet until reaching level") + " " + FLEETCOMMAND_MIN_LEVEL + " " + TranslateString("", "Leadership. Assign anyway?"));
	} else {
		SelectCaptainButton();
	}
}

/*void CheckFleetLevelYes()
{
	if (EnableLimitedShipClass()) {
		SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
		SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
		SetNodeUsing("MSC_TEXTWINDOW", false);
		SetNodeUsing("FLV_CONFIRM_YES_BUTTON", false);
		SetNodeUsing("FLV_CONFIRM_NO_BUTTON", false);
		SetNodeUsing("MSC_SKILL_PIC", false);
	}
	SelectCaptainButton();
}

void CheckFleetLevelNo()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
	SetNodeUsing("MSC_TEXTWINDOW", false);
	SetNodeUsing("FLV_CONFIRM_YES_BUTTON", false);
	SetNodeUsing("FLV_CONFIRM_NO_BUTTON", false);
	SetNodeUsing("MSC_SKILL_PIC", false);
	SetCurrentNode("SCROLLITEMS");
}*/

void ProcessInstall()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessInstall");
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) {
		SetSelectable("INSTALL_BUTTON", false);
		return;
	} else {
		SetSelectable("INSTALL_BUTTON", true);
	}

	cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
	cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
	cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
	cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
	cannoniqty = GetCannonCurQuantity(GetCharacter(cn));

	DisableString("FireRange");
	DisableString("ReloadTime");
	DisableString("Gunpowder");
	DisableString("CostFullLabel");
	DisableString("Cost");
	DisableString("CostUnit");
	DisableString("CannonWeight");
	//DisableString("RepairCannonsCost");
	SetNodeUsing("CANNONS_STRINGES", false);
	SetNodeUsing("CANNONPOWDER_STRINGS", false);
	SetNodeUsing("CANNONS_REPAIRIMAGES", false);
	SetNodeUsing("INSTALLBUY_BUTTON", false);
	SetNodeUsing("INSTALL_BUTTON", false);
	SetNodeUsing("CANNONLOCATIONS_STRINGS", true);
	SetNodeUsing("FRONTCANNONSQTY", true);
	EnableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", true);
	EnableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", true);
	EnableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", true);
	EnableString("back_cannons_qty");
	EnableString("cannons_cost");
	SetNodeUsing("CANNONS_CANCEL_BUTTON", true);
	SetNodeUsing("CANNONS_BUY_BUTTON", true);
	SetSelectable("SHIPSLIST", false);
	SetSelectable("SCROLLCANNONS", false);
	SetSelectable("LEFTSCROLLBUTTON", false);
	SetSelectable("RIGHTSCROLLCBUTTON", false);

	GameInterface.strings.front_cannons_qty = GetCannonArcQty(GetCharacter(cn), 0);
	GameInterface.strings.rightarc_cannons_qty = GetCannonArcQty(GetCharacter(cn), 1);
	GameInterface.strings.back_cannons_qty = GetCannonArcQty(GetCharacter(cn), 2);
	GameInterface.strings.leftarc_cannons_qty = GetCannonArcQty(GetCharacter(cn), 3);
	//GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + cannoniqty + XI_ConvertString("un")+".";
	GameInterface.strings.cannons_cost = MakeMoneyShow(0, MONEY_SIGN, MONEY_DELIVER);
	SetSelectable("I_REPAIR", false); // Screwface
	SetSelectable("I_SHIPUPGRADE", false);
	SetSelectable("I_APPEARANCE", false);
	topay = 0; // Screwface
}

void ProcessInstallAndBuy()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessInstallAndBuy");
	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if (cn < 0) {
		SetSelectable("INSTALLBUY_BUTTON", false);
		return;
	} else {
		SetSelectable("INSTALLBUY_BUTTON", true);
	}

	cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
	cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
	cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
	cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
	cannoniqty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];

	int gratio[4];
	int canbuymax = GetCanBuyQuantity();
//if(DEBUG_SHIPYARD_INTERFACE) trace("Install&Buy: canbuymax="+canbuymax);
	while (canbuymax > 0) {
		int mnguns = GetCannonArcMaxQty(GetCharacter(cn), 0);
		if (mnguns > 0)
			gratio[0] = makeint(makefloat(cannonqtys[0])/makefloat(mnguns) * 100);
		else
			gratio[0] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 1);
		if (mnguns > 0)
			gratio[1] = makeint(makefloat(cannonqtys[1])/makefloat(mnguns) * 100);
		else
			gratio[1] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 2);
		if (mnguns > 0)
			gratio[2] = makeint(makefloat(cannonqtys[2])/makefloat(mnguns) * 100);
		else
			gratio[2] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 3);
		if (mnguns > 0)
			gratio[3] = makeint(makefloat(cannonqtys[3])/makefloat(mnguns) * 100);
		else
			gratio[3] = 100;

		int mbort = 0;
		mnguns = gratio[mbort];
		for (int i = 1; i < 4; i++) {
			if (gratio[i] < mnguns) {
				mbort = i;
				mnguns = gratio[mbort];
			}
		}
//if(DEBUG_SHIPYARD_INTERFACE) trace("Install&Buy: mbort="+mbort+", canbuymax="+(canbuymax - 1));
		cannonqtys[mbort] = cannonqtys[mbort] + 1;
		cannoniqty++;
		canbuymax--;
	}
//if(DEBUG_SHIPYARD_INTERFACE) trace("Install&Buy: po petli: 0="+cannonqtys[0]+", 1="+cannonqtys[1]+", 2="+cannonqtys[2]+", 3="+cannonqtys[3]);

//if(DEBUG_SHIPYARD_INTERFACE) trace("topay="+topay)

	SetCannonArcQty(GetCharacter(cn), 0, cannonqtys[0]);
	SetCannonArcQty(GetCharacter(cn), 1, cannonqtys[1]);
	SetCannonArcQty(GetCharacter(cn), 2, cannonqtys[2]);
	SetCannonArcQty(GetCharacter(cn), 3, cannonqtys[3]);
	if (cannoniqty == 0)
		SetCharacterCannonType(GetCharacter(cn), CANNON_TYPE_NONECANNON);
	else
		SetCharacterCannonType(GetCharacter(cn), GetChoosedCannonType());

	AddMoneyToCharacter(PChar, 0 - topay);
	makearef(arCurShip, Characters[cn].ship);
	sLogEntry += "Installed new cannons on the '"+arCurShip.name+"' for "+topay+" pieces of gold. ";
	GameInterface.strings.money = MakeMoneyShow(makeint(GetCharacterMoney(PChar)), MONEY_SIGN, MONEY_DELIVER);
	GameInterface.strings.CostFullLabel = XI_ConvertString("CostFull") + " (" + 0 +" "+ XI_ConvertString("un")+")"; // PB
	GameInterface.strings.Cost = 0; // Screwface

	int isSelectable = CheckInstallEnable();
	SetSelectable("INSTALL_BUTTON",    isSelectable >  0);
	SetSelectable("INSTALLBUY_BUTTON", isSelectable == 2);
	// Screwface
	if(GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType() && GetCaracterShipCannonsType(GetCharacter(cn)) != CANNON_TYPE_NONECANNON)
		SetSelectable("INSTALL_BUTTON", false);
	// Screwface : End

	ChangeScroll();
}

void ProcessCancel()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessCancel");
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	DisableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	DisableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	DisableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", false);
	DisableString("back_cannons_qty");
	DisableString("cannons_cost");
	SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
	SetNodeUsing("CANNONS_BUY_BUTTON", false);

	SetNodeUsing("CANNONS_STRINGES", true);
	EnableString("FireRange");
	EnableString("ReloadTime");
	EnableString("Gunpowder");
	EnableString("CostFullLabel");
	EnableString("Cost");
	EnableString("CostUnit");
	EnableString("CannonWeight");
	//EnableString("RepairCannonsCost");
	if (CANNONPOWDER_MOD) SetNodeUsing("CANNONPOWDER_STRINGS", true);
	SetNodeUsing("CANNONS_REPAIRIMAGES", true);
	SetNodeUsing("INSTALLBUY_BUTTON", true);
	SetNodeUsing("INSTALL_BUTTON", true);
	SetCurrentNode("INSTALL_BUTTON");

	SetSelectable("SHIPSLIST", true);
	SetSelectable("SCROLLCANNONS", true);
	SetSelectable("LEFTSCROLLBUTTON", true);
	SetSelectable("RIGHTSCROLLCBUTTON", true);

	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	GameInterface.strings.CostFullLabel = XI_ConvertString("CostFull") + " (" + GetMaxCannonQuantity(GetCharacter(cn)) + " " + XI_ConvertString("un") + ")";
	//GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + cannoniqty + XI_ConvertString("un")+".";		
	SetSelectable("I_REPAIR", true); // Screwface
	SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
	SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
}

void ProcessBuyCannon()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessBuyCannon");
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	DisableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	DisableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	DisableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", false);
	DisableString("back_cannons_qty");
	DisableString("cannons_cost");
	SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
	SetNodeUsing("CANNONS_BUY_BUTTON", false);

	SetNodeUsing("CANNONS_STRINGES", true);
	EnableString("FireRange");
	EnableString("ReloadTime");
	EnableString("Gunpowder");
	EnableString("CostFullLabel");
	EnableString("Cost");
	EnableString("CostUnit");
	EnableString("CannonWeight");
	//EnableString("RepairCannonsCost");
	if (CANNONPOWDER_MOD) SetNodeUsing("CANNONPOWDER_STRINGS", true);
	SetNodeUsing("CANNONS_REPAIRIMAGES", true);
	SetNodeUsing("INSTALLBUY_BUTTON", true);
	SetNodeUsing("INSTALL_BUTTON", true);
	SetCurrentNode("SCROLLCANNONS");

	SetSelectable("SHIPSLIST", true);
	SetSelectable("SCROLLCANNONS", true);
	SetSelectable("LEFTSCROLLBUTTON", true);
	SetSelectable("RIGHTSCROLLCBUTTON", true);

	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if (cn < 0) return;

	SetCharacterCannonType(GetCharacter(cn), GetChoosedCannonType());
	cannonqtys[0] = sti(GameInterface.strings.front_cannons_qty);
	cannonqtys[1] = sti(GameInterface.strings.rightarc_cannons_qty);
	cannonqtys[2] = sti(GameInterface.strings.back_cannons_qty);
	cannonqtys[3] = sti(GameInterface.strings.leftarc_cannons_qty);
	//cannoniqty = GetCannonQuantity(GetCharacter(cn));

	SetCannonArcQty(GetCharacter(cn), 0, cannonqtys[0]);
	SetCannonArcQty(GetCharacter(cn), 1, cannonqtys[1]);
	SetCannonArcQty(GetCharacter(cn), 2, cannonqtys[2]);
	SetCannonArcQty(GetCharacter(cn), 3, cannonqtys[3]);
	cannoniqty=cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
	if (cannoniqty == 0)
	{
		SetCharacterCannonType(GetCharacter(cn), CANNON_TYPE_NONECANNON);
	}

	AddMoneyToCharacter(PChar, 0 - topay);
	makearef(arCurShip, Characters[cn].ship); 
	sLogEntry += "Installed new cannons on the '"+arCurShip.name+"' for "+topay+" pieces of gold. ";
	GameInterface.strings.money = MakeMoneyShow(makeint(GetCharacterMoney(PChar)), MONEY_SIGN, MONEY_DELIVER);

	// PB: Price calculation fixed -->
	GameInterface.strings.CostFullLabel = XI_ConvertString("CostFull") + " (" + sti(GetMaxCannonQuantity(GetCharacter(cn))-GetCannonQuantity(GetCharacter(cn))) +" "+ XI_ConvertString("un")+")"; // KK
	topay = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn)));
	GameInterface.strings.Cost = topay;
	// PB: Price calculation fixed <--

	int isSelectable = CheckInstallEnable();
	SetSelectable("INSTALL_BUTTON",    isSelectable >  0);
	SetSelectable("INSTALLBUY_BUTTON", isSelectable == 2);
	// Screwface
	if(GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType() && GetCaracterShipCannonsType(GetCharacter(cn)) != CANNON_TYPE_NONECANNON)
		SetSelectable("INSTALL_BUTTON", false);
	// Screwface : End
	ChangeScroll();
	SetSelectable("I_REPAIR", true); // Screwface
	SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
	SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
}
// <-- KK

string GetCharShipName(ref rCharacter)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetCharShipName");
	if( CheckAttribute(rCharacter,"Ship.Name") )	return rCharacter.Ship.Name;
	return SHIP_NAME_NOTUSED;
}

void SetCharacterCannonType(ref rCharacter,int nCannonType)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetCharacterCannonType");
	rCharacter.Ship.Cannons.Type = nCannonType;
}

// PB: Function completely rewritten -->
int CheckInstallEnable()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("CheckInstallEnable");
	// returns:
	// 0 = Cannons cannot be installed
	// 1 = Cannons can be installed individually only
	// 2 = Full set can be installed

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if (cn == -1) return 0;

	if (GetRemovable(GetCharacter(cn)) == false) {
		GameInterface.strings.HelpString = TranslateString("","Notown");
		return 0;
	}

	// Calculate money required to replace ALL cannons
	int curDelta = 0;
	if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) 
	{
		curDelta = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)));
		curDelta += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), GetMaxCannonQuantity(GetCharacter(cn)));
	}
	else
	{
		int gunsMissing = GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn));
		if (gunsMissing)
		{
			curDelta = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), gunsMissing);
		}
	}

	int canbuymax = GetCanBuyQuantity();

	if(GetChoosedCannonType() == GetCaracterShipCannonsType(GetCharacter(cn)))
	{
		if(GetCannonQuantity(GetCharacter(cn)) == GetCannonMaxQuantity(GetCharacter(cn)))
		{
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			SetNodeUsing("BOX1_RAMKA", true);
			GameInterface.strings.HelpString = TranslateString("","Installed");
			return 1;
		}
		else
		{
			if (GetCharacterMoney(GetMainCharacter()) >= curDelta)
			{
				EnableString("HelpString");
				SetNodeUsing("BOX1",true);
				SetNodeUsing("BOX1_RAMKA", true);
				GameInterface.strings.HelpString = TranslateString("","Adding");
				return 2;
			}
			else
			{
				if (GetCannonMaxQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn)) > canbuymax && canbuymax > 0)
				{
					EnableString("HelpString");
					SetNodeUsing("BOX1",true);
					SetNodeUsing("BOX1_RAMKA", true);
					GameInterface.strings.HelpString = TranslateString("", "CanBuyMax") + " " + canbuymax + " " + TranslateString("", "cannons.");
					return 1;
				}
				else
				{
					EnableString("HelpString");
					SetNodeUsing("BOX1",true);
					SetNodeUsing("BOX1_RAMKA", true);
					GameInterface.strings.HelpString = TranslateString("","Nomoney");
					return 1;
				}
			}
		}
	}
	else
	{
		if (GetMaximumCaliber(GetCharacter(cn)) < GetCannonCaliber(GetChoosedCannonType()) && !VanderdeckenShipyard())
		{
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			SetNodeUsing("BOX1_RAMKA", true);
			GameInterface.strings.HelpString = TranslateString("","Bigcaliber");
			return 0;
		}
		else
		{
			if (GetCannonMaxQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn)) > canbuymax && canbuymax > 0)
			{
				EnableString("HelpString");
				SetNodeUsing("BOX1",true);
				SetNodeUsing("BOX1_RAMKA", true);
				GameInterface.strings.HelpString = TranslateString("", "CanBuyMax") + " " + canbuymax + " " + TranslateString("", "cannons.");
				return 1;
			}
			else
			{
				if (GetCharacterMoney(GetMainCharacter()) < curDelta)
				{
					EnableString("HelpString");
					SetNodeUsing("BOX1",true);
					SetNodeUsing("BOX1_RAMKA", true);
					GameInterface.strings.HelpString = TranslateString("","Nomoney");
					return 0;
				}
				else
				{
					return 2;
				}
			}
		}
	}
}
// PB: Function completely rewritten <--

void ProcessInstallSelect()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessInstallSelect");
	if( GetSelectable("INSTALL_BUTTON") ) SetCurrentNode("INSTALL_BUTTON");
}

int GetChoosedCannonType()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetChoosedCannonType");
	string attributeName = "pic" + (nCurCScrollNum+1);
	if( !CheckAttribute(&GameInterface,"scrollcannons."+attributeName) ) return 0;
	return sti(GameInterface.scrollcannons.(attributeName).cannon);
}

// NK -- int GetCharacterMoney(ref rChr) moved to char_utilite and fixed.

// KK -->
int CalcCannonExchangeCost()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("CalcCannonExchangeCost");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return 0;

	int excost = 0;
	if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) excost = SellCannons(GetCharacter(cn), 1);
	excost += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), 1);
	return excost;
}

void ProcessInstallSU()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessInstallSU...");
	ref mainchar = GetMainCharacter();
	int currentupgrade = nCurSUScrollNum;
	int cn = GetCompanionIndex(mainchar, nCurFourNum);
	if (cn < 0) return;
	string upgrade = GetShipUpgradeID(nCurSUScrollNum);
	int cost = GetCostTun(cn, upgrade, PRICE_TYPE_BUY);
	if (CheckTun(cn, upgrade))
	{
		UnApplyTun(cn, upgrade,0); // PB: Getting money back is handled by the function itself, PW: boolean added for NOT berthing removal so it takes time in game
	}
	else
	{
		// Screwface It is not always the char who has upgrade applied who pay it, ex : for companions it's you 
		ApplyTun(cn, upgrade, GetTimeTun(cn, upgrade)); // Previously the cost was decreased TWO TIMES !!!!!
		mainchar.Money = GetCharacterMoney(mainchar) - cost;
		makearef(arCurShip, Characters[cn].ship); 
		sLogEntry += "Upgraded the '"+arCurShip.name+"' with new "+XI_ConvertString(upgrade)+" for "+cost+" pieces of gold. ";
	}
	if(DEBUG_SHIPYARD_INTERFACE) trace("check="+CheckTun(cn, upgrade));
//dumpattributes(mainchar);
	if(DEBUG_SHIPYARD_INTERFACE) trace(".."+mainchar.ship.tune.(upgrade).on);
	// Screwface
	nStoreMoney += cost;
	GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER);
	// Screwface
	//shipwright.Money = GetCharacterMoney(shipwright) + cost;//PW commented out: 4 lines above the money has already been put in the store money
	DeleteAttribute(&GameInterface, "scrollshipupgrades");
	FillShipUpgradesScroll();
	nCurSUScrollNum = currentupgrade;
	GameInterface.scrollshipupgrades.current = nCurSUScrollNum;
	SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "scrollshipupgrades", nCurSUScrollNum);
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "scrollshipupgrades");
	SetCurrentNode("scrollshipupgrades");
	RefreshScreen();
}

void ProcessRepaint()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("ProcessRepaint");
	ref mainchar = GetMainCharacter();
	int cn = GetCompanionIndex(mainchar, nCurFourNum);
	if (cn < 0) return;
	characters[cn].Ship.Type = GetChoosedShipType();
	int cost = 0;
	mainchar.Money = GetCharacterMoney(mainchar) - cost;
	shipwright.Money = GetCharacterMoney(shipwright) + cost;
	DeleteAttribute(&GameInterface, "scrollshipappearance");
	FillShipAppearanceScroll();
	GameInterface.scrollshipappearance.current = sti(GameInterface.scrollshipappearance.current) + 1;
	SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "scrollshipappearance", nCurSUScrollNum);
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "scrollshipappearance");
	SetCurrentNode("scrollshipappearance");
	RefreshScreen();
}

int GetCanBuyQuantity()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("GetCanBuyQuantity");
	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if(cn==-1) return 0;

	int cannon_exchange_cost = CalcCannonExchangeCost();
	if (cannon_exchange_cost < 0) cannon_exchange_cost = 0 - cannon_exchange_cost;
	int maxcannons = GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn));
	//if(DEBUG_SHIPYARD_INTERFACE) trace("1: GetMaxCannonQuantity="+GetMaxCannonQuantity(GetCharacter(cn))+", GetCannonQuantity="+GetCannonQuantity(GetCharacter(cn)));
	if (maxcannons == 0) return 0;
	int mcannons = maxcannons;
	if (cannon_exchange_cost != 0) mcannons = GetCharacterMoney(PChar) / cannon_exchange_cost;
	if (mcannons > maxcannons) mcannons = maxcannons;
	if (mcannons < 0) mcannons = 0;
	//if(DEBUG_SHIPYARD_INTERFACE) trace("GetCanBuyQuantity: mcannons="+mcannons+",maxcannons="+maxcannons+",cannon_exchange_cost="+cannon_exchange_cost);
	return mcannons;
}

void SetScreen(int iScreen)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("SetScreen");
	int cn;
	switch (CurrentScreen) {
		case SCREEN_REPAIR:
			SetNodeUsing("SCROLLITEMS", false);
			SetNodeUsing("PASSENGERS", false);
			SetNodeUsing("MAINPICTURES", false);
			SetNodeUsing("REPAIRSTRINGS", false);
			DisableString("ShipClass");
			DisableString("HullPoints");
			DisableString("Speed");
			DisableString("Maneuver");
			DisableString("Capacity");
			DisableString("MaxCrew");
			DisableString("MinCrew");
			DisableString("CannonsQuantity");
			DisableString("MaxCaliber");
			DisableString("ShipCost");
			SetNodeUsing("BOX1", false);
			SetNodeUsing("BOX1_RAMKA", false);
			DisableString("HelpString");
			//DisableString("ShipName");
			//SetNodeUsing("SHIPNAMETITLE",false);
			//SetNodeUsing("SHIPNAMETITLE_RAMKA", false);
			//SetNodeUsing("MAINPICTURES",false);
			for (int i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
				string upgradepict = "Upgrade" + i + "_Picture";
				GameInterface.pictures.(upgradepict).pic = -1;
				GameInterface.pictures.(upgradepict).tex = -1;
			}

			SetNodeUsing("NATION", false);						// added by KAM
			SetNodeUsing("NATIONALDESIGN",false);				// added by KAM
			// Screwface
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
		case SCREEN_CANNONS:
			SetNodeUsing("SCROLLCANNONS", false);
			SetNodeUsing("CANNONS_STRINGES", false);
			SetNodeUsing("CANNONPOWDER_STRINGS", false);
			SetNodeUsing("CANNONS_REPAIRIMAGES", false);
			DisableString("FireRange");
			DisableString("ReloadTime");
			DisableString("Gunpowder");
			DisableString("CostFullLabel");
			DisableString("Cost");
			DisableString("CostUnit");
			DisableString("CannonWeight");
			SetNodeUsing("INSTALLBUY_BUTTON", false);
			SetNodeUsing("INSTALL_BUTTON", false);
			SetNodeUsing("BOX1", false);
			SetNodeUsing("BOX1_RAMKA", false);
			DisableString("HelpString");
			// Screwface
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			// Screwface : End
		break;
		case SCREEN_SHIPUPGRADE:
			SetNodeUsing("SCROLLSHIPUPGRADES", false);
			//DisableString("ShipUpgradeName");
			SetNodeUsing("SHIPUPGRADE_DESCRIPTION", false);
			SetNodeUsing("SHIPUPGRADE_STRINGS", false);
			DisableString("ShipUpgradeTime");
			DisableString("ShipUpgradeOrRepaintCost");
			SetNodeUsing("CANNONS_REPAIRIMAGES", false);
			SetNodeUsing("INSTALLSU_BUTTON", false);
			// Screwface
			SetNodeUsing("BOX1", false);
			SetNodeUsing("BOX1_RAMKA", false);
			DisableString("HelpString");
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
		case SCREEN_APPEARANCE:
			SetNodeUsing("SCROLLSHIPAPPEARANCE", false);
			SetNodeUsing("SHIPAPPEARANCE_DESCRIPTION", false);
			DisableString("ShipUpgradeOrRepaintCost");
			SetNodeUsing("CANNONS_REPAIRIMAGES", false);
			SetNodeUsing("SHIPAPPEARANCE_STRINGS", false);
			SetNodeUsing("SHIPAPPEARANCE_BUTTON", false);
			// Screwface
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
	}
	CurrentScreen = iScreen;
	switch (iScreen) {
		case SCREEN_REPAIR:
			SetSelectable("I_REPAIR", false);
			SetSelectable("I_CANNONS", true);
			if (!VanderdeckenShipyard())
			{
				SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
				SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
			}
			else
			{
				SetSelectable("I_SHIPUPGRADE", false);
				SetSelectable("I_APPEARANCE", false);
			}
			GameInterface.strings.ScreenTitle = XI_ConvertString("titleShipyard");
			SetNodeUsing("SCROLLITEMS", true);
			SetNodeUsing("REPAIRSTRINGS", false);
			nShowMode = -1;
			UpdateSScrollData();
			// Screwface
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
		case SCREEN_CANNONS:
			SetSelectable("I_REPAIR", true);
			SetSelectable("I_CANNONS", false);
			SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
			SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
			GameInterface.strings.ScreenTitle = XI_ConvertString("titleCannons");
			SetNodeUsing("SCROLLCANNONS", true);
			SetNodeUsing("CANNONS_STRINGES", true);
			SetNodeUsing("CANNONPOWDER_STRINGS", true);
			SetNodeUsing("CANNONS_REPAIRIMAGES", true);
			EnableString("FireRange");
			EnableString("ReloadTime");
			if (CANNONPOWDER_MOD) EnableString("Gunpowder");
			EnableString("CostFullLabel");
			EnableString("Cost");
			EnableString("CostUnit");
			EnableString("CannonWeight");
			SetNodeUsing("INSTALLBUY_BUTTON", true);
			SetNodeUsing("INSTALL_BUTTON", true);
			SetNodeUsing("BOX1", true);
			SetNodeUsing("BOX1_RAMKA", true);
			EnableString("HelpString");
			SetCurrentNode("SCROLLCANNONS");
			// Screwface
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			// Screwface : End
		break;
		case SCREEN_SHIPUPGRADE:
			SetSelectable("I_REPAIR", true);
			SetSelectable("I_CANNONS", true);
			SetSelectable("I_SHIPUPGRADE", false);
			SetSelectable("I_APPEARANCE", !VanderdeckenShipyard());
			GameInterface.strings.ScreenTitle = XI_ConvertString("titleShipTuning");
			SetNodeUsing("SCROLLSHIPUPGRADES", true);
			string upgrade = GetShipUpgradeID(nCurSUScrollNum);
			//GameInterface.strings.ShipUpgradeName = XI_ConvertString(upgrade);
			SetFormatedText("SHIPUPGRADE_DESCRIPTION", TranslateString("", upgrade + "_desc"));
			//EnableString("ShipUpgradeName");
			SetNodeUsing("SHIPUPGRADE_DESCRIPTION", true);
			SetNodeUsing("SHIPUPGRADE_STRINGS", true);
			SetCurrentNode("SCROLLSHIPUPGRADES");
			cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
			if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED) {
				GameInterface.strings.ShipUpgradeTime = GetTimeTun(cn, upgrade);
				EnableString("ShipUpgradeTime");
				GameInterface.strings.ShipUpgradeOrRepaintCost = GetCostTun(cn, upgrade, PRICE_TYPE_BUY);
				EnableString("ShipUpgradeOrRepaintCost");
				SetNodeUsing("CANNONS_REPAIRIMAGES", true);
				// Screwface
				if(upgrade == "flushed" && !CheckTun(cn, upgrade) && GetCurrentLocationNation() != PIRATE)
				{
					SetSelectable("INSTALLSU_BUTTON", false);
					EnableString("HelpString");
					SetNodeUsing("BOX1",true);
					SetNodeUsing("BOX1_RAMKA", true);
					GameInterface.strings.HelpString = "Only available in Pirate Shipyards!";
				}
				else
				{
					if(GetCharacterMoney(GetMainCharacter()) >= GetCostTun(cn, upgrade, PRICE_TYPE_BUY))
					{
						SetSelectable("INSTALLSU_BUTTON", True);
						DisableString("HelpString");
						SetNodeUsing("BOX1",false);
						SetNodeUsing("BOX1_RAMKA", false);
					}
					else
					{
						SetSelectable("INSTALLSU_BUTTON", false);
						EnableString("HelpString");
						SetNodeUsing("BOX1",true);
						SetNodeUsing("BOX1_RAMKA", true);
						GameInterface.strings.HelpString = TranslateString("","Nomoney");
					}
					// Added by Levis to prevent exploit -->
					if(GetCannonQuantity(GetCharacter(cn)) < 1)
					{
						if(upgrade == "bcannons" || upgrade == "gchasers")
						{
							SetSelectable("INSTALLSU_BUTTON", false);
							EnableString("HelpString");
							SetNodeUsing("BOX1",true);
							SetNodeUsing("BOX1_RAMKA", true);
							GameInterface.strings.HelpString = TranslateString("","NoCannons");
						}
					}
					// Levis <--
					if(CheckTun(cn, upgrade)) 
					{
						EnableString("HelpString");
						SetNodeUsing("BOX1",true);
						SetNodeUsing("BOX1_RAMKA", true);
						if(upgrade != "rhull" && upgrade != "flushed")
						{
							SetSelectable("INSTALLSU_BUTTON", True);
							GameInterface.strings.HelpString = "Click Install to Remove the upgrade";
						}
						else
						{
							SetSelectable("INSTALLSU_BUTTON", false);
							GameInterface.strings.HelpString = "This upgrade can't be removed";
						}
					}
				}
				//if(GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED) SetSelectable("INSTALLSU_BUTTON", false);
				// Screwface : End
				SetNodeUsing("INSTALLSU_BUTTON", true);
			}
			// Screwface
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
		case SCREEN_APPEARANCE:
			SetSelectable("I_REPAIR", true);
			SetSelectable("I_CANNONS", true);
			SetSelectable("I_SHIPUPGRADE", !VanderdeckenShipyard());
			SetSelectable("I_APPEARANCE", false);
			GameInterface.strings.ScreenTitle = XI_ConvertString("titleAppearance");
			SetNodeUsing("SCROLLSHIPAPPEARANCE", true);
			SetNodeUsing("SHIPAPPEARANCE_DESCRIPTION", true);
			SetNodeUsing("SHIPAPPEARANCE_STRINGS", true);
			SetNodeUsing("SHIPAPPEARANCE_BUTTON", true);
			SetSelectable("SHIPAPPEARANCE_BUTTON",false);
			cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
			if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED) {
				int tmpLangFileID = LanguageOpenFile("ShipModels_descriptions.txt");
				string ShipID = GetChoosedShipType();
				string ShipDescription = LanguageConvertString(tmpLangFileID, ShipID + "_Descr");
				if(DEBUG)	ShipDescription = ShipID + ": " + ShipDescription;
				SetFormatedText("SHIPAPPEARANCE_DESCRIPTION", ShipDescription);
				LanguageCloseFile(tmpLangFileID);
			//	GameInterface.strings.ShipUpgradeOrRepaintCost = GetCostTun(cn, upgrade, PRICE_TYPE_BUY); // PB: What is this doing here?
				GameInterface.strings.ShipUpgradeOrRepaintCost = 0;
				EnableString("ShipUpgradeOrRepaintCost");
				SetNodeUsing("CANNONS_REPAIRIMAGES", true);
				SetSelectable("SHIPAPPEARANCE_BUTTON", GetCharacterShipID(GetCharacter(cn)) != ShipID);
			}
			// Screwface
			DisableString("NoBuyString");
			SetNodeUsing("NOBUYBOX2",false);
			GameInterface.strings.NoBuyString = "";
			SetNodeUsing("REPAIR_BUTTON",false);
			SetNodeUsing("SELLSHIP_BUTTON",false);
			SetNodeUsing("CHANGE_CAPTAIN",false);
			SetNodeUsing("BACK_BUTTON", false);
			EnableString("ShipName");
			DisableString("CharacterName");
			DisableString("skillLeadership");
			DisableString("skillFencing");
			DisableString("skillSailing");
			DisableString("skillAccuracy");
			DisableString("skillCannons");
			DisableString("skillGrappling");
			DisableString("skillRepair");
			DisableString("skillDefence");
			DisableString("skillCommerce");
			DisableString("skillSneak");
			SetNodeUsing("SKILLS_IMAGES",false);
			SetNodeUsing("PASSENGERS",false);
			SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
			SetNodeUsing("FRONTCANNONSQTY", false);
			DisableString("front_cannons_qty");
			SetNodeUsing("LEFTARCCANNONSQTY", false);
			DisableString("leftarc_cannons_qty");
			SetNodeUsing("RIGHTARCCANNONSQTY", false);
			DisableString("rightarc_cannons_qty");
			SetNodeUsing("BACKCANNONSQTY", false);
			DisableString("back_cannons_qty");
			DisableString("cannons_cost");
			SetNodeUsing("CANNONS_CANCEL_BUTTON", false);
			SetNodeUsing("CANNONS_BUY_BUTTON", false);
			// Screwface : End
		break;
	}
}

void RefreshScreen()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("RefreshScreen");
	int cn;
	switch (CurrentScreen)
	{
		case SCREEN_REPAIR:
		break;
		case SCREEN_CANNONS:
		break;
		case SCREEN_SHIPUPGRADE:
			//GameInterface.strings.ShipUpgradeName = XI_ConvertString(GetShipUpgradeID(nCurSUScrollNum));
			SetFormatedText("SHIPUPGRADE_DESCRIPTION", TranslateString("", (GetShipUpgradeID(nCurSUScrollNum) + "_desc")));
			cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
			if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED) {
				string upgrade = GetShipUpgradeID(nCurSUScrollNum);
				GameInterface.strings.ShipUpgradeTime = GetTimeTun(cn, upgrade);
				EnableString("ShipUpgradeTime");
				GameInterface.strings.ShipUpgradeOrRepaintCost = GetCostTun(cn, upgrade, PRICE_TYPE_BUY);
				EnableString("ShipUpgradeOrRepaintCost");
				SetNodeUsing("CANNONS_REPAIRIMAGES", true);
				/*if (!CheckTun(cn, upgrade)) {
					SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INSTALLSU_BUTTON", 0, XI_ConvertString("Install"));
					SetSelectable("INSTALLSU_BUTTON", GetCharacterMoney(GetMainCharacter()) >= GetCostTun(cn, upgrade, PRICE_TYPE_BUY));
				} else {
					SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INSTALLSU_BUTTON", 0, XI_ConvertString("Remove"));
					SetSelectable("INSTALLSU_BUTTON", upgrade != "rhull" && upgrade != "flushed" && GetCharacterMoney(GetMainCharacter()) >= GetCostTun(cn, upgrade, PRICE_TYPE_BUY));
				}*/
				// Screwface
				if(upgrade == "flushed" && !CheckTun(cn, upgrade) && GetCurrentLocationNation() != PIRATE)
				{
					SetSelectable("INSTALLSU_BUTTON", false);
					EnableString("HelpString");
					SetNodeUsing("BOX1",true);
					SetNodeUsing("BOX1_RAMKA", true);
					GameInterface.strings.HelpString = "Only available in Pirate Shipyards!";
				}
				else
				{
					if(GetCharacterMoney(GetMainCharacter()) >= GetCostTun(cn, upgrade, PRICE_TYPE_BUY))
					{
						SetSelectable("INSTALLSU_BUTTON", True);
						DisableString("HelpString");
						SetNodeUsing("BOX1",false);
						SetNodeUsing("BOX1_RAMKA", false);
					}
					else
					{
						SetSelectable("INSTALLSU_BUTTON", false);
						EnableString("HelpString");
						SetNodeUsing("BOX1",true);
						SetNodeUsing("BOX1_RAMKA", true);
						GameInterface.strings.HelpString = TranslateString("","Nomoney");
					}
					// Added by Levis to prevent exploit -->
					if(GetCannonQuantity(GetCharacter(cn)) < 1)
					{
						if(upgrade == "bcannons" || upgrade == "gchasers")
						{
							SetSelectable("INSTALLSU_BUTTON", false);
							EnableString("HelpString");
							SetNodeUsing("BOX1",true);
							SetNodeUsing("BOX1_RAMKA", true);
							GameInterface.strings.HelpString = TranslateString("","NoCannons");
						}
					}
					// Levis <--
					if(CheckTun(cn, upgrade))
					{
						EnableString("HelpString");
						SetNodeUsing("BOX1",true);
						SetNodeUsing("BOX1_RAMKA", true);
						if(upgrade != "rhull" && upgrade != "flushed")
						{
							SetSelectable("INSTALLSU_BUTTON", True);
							GameInterface.strings.HelpString = "Click Install to Remove the upgrade";
						}
						else
						{
							SetSelectable("INSTALLSU_BUTTON", false);
							GameInterface.strings.HelpString = "This upgrade can't be removed";
						}
					}
				}
				// Screwface : End
				SetNodeUsing("INSTALLSU_BUTTON", true);
			}
		break;
		case SCREEN_APPEARANCE:
			cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
			if (cn >= 0 && GetCharacterShipType(GetCharacter(cn)) != SHIP_NOTUSED) {
				int tmpLangFileID = LanguageOpenFile("ShipModels_descriptions.txt");
				string ShipID = GetChoosedShipType();
				string ShipDescription = LanguageConvertString(tmpLangFileID, ShipID + "_Descr");
				if(DEBUG)	ShipDescription = ShipID + ": " + ShipDescription;
				SetFormatedText("SHIPAPPEARANCE_DESCRIPTION", ShipDescription);
				LanguageCloseFile(tmpLangFileID);
				GameInterface.strings.ShipUpgradeOrRepaintCost = GetCostTun(cn, upgrade, PRICE_TYPE_BUY);
				EnableString("ShipUpgradeOrRepaintCost");
				SetNodeUsing("CANNONS_REPAIRIMAGES", true);
				SetSelectable("SHIPAPPEARANCE_BUTTON", GetCharacterShipID(GetCharacter(cn)) != ShipID);
			}
		break;
	}
}

void FreezeScreen(bool bSet)
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("FreezeScreen");
	bSet = !bSet;
	switch (CurrentScreen)
	{
		case SCREEN_REPAIR:
			SetSelectable("SHIPSLIST", bSet);
			SetSelectable("SCROLLITEMS", bSet);
			SetSelectable("LEFTSCROLLBUTTON", bSet);
			SetSelectable("RIGHTSCROLLBUTTON", bSet);
			SetSelectable("I_CANNONS", bSet);
			SetSelectable("I_SHIPUPGRADE", bSet);
			SetSelectable("I_APPEARANCE", bSet);
		break;
		case SCREEN_CANNONS:
		break;
		case SCREEN_SHIPUPGRADE:
		break;
		case SCREEN_APPEARANCE:
		break;
	}
}
// <-- KK

// PB -->
bool VanderdeckenShipyard()
{
	if(DEBUG_SHIPYARD_INTERFACE) trace("VanderdeckenShipyard");
	return Characters[GetMainCharacterIndex()].location == Characters[GetCharacterIndex("Hendrick Vanderdecken")].location;
}

string ShipAcquiredState(ref arCurShip)
{
	if (!CheckAttribute(arCurShip,"acquired")) arCurShip.acquired = "bought";
	return arCurShip.acquired;
}
// PB <--

//Levis -->
bool CheckForContraband(ref _refCharacter)
{
	if ( GetOfficersPerkUsing(GetMainCharacter(),"Trustworthy")) return false; // PB: Check officers too
	//if ( FindFirstContrabandGoods(GetMainCharacter()) != -1) return true;
	int i;
	int curIslandIdx = GetCharacterCurrentIsland(_refCharacter);
	ref CurIsland = GetIslandByIndex(curIslandIdx);
	aref islRef; makearef(islRef,CurIsland.Trade.Contraband);
	int n;
	for(i=0;i<GetAttributesNum(islRef);i++)
	{
		n = sti(GetAttributeValue(GetAttributeN(islRef,i)));
		if( GetCargoGoods(_refCharacter,n)>0 )
		{
			return true;
		}
	}
	return false;
}
//Levis <--