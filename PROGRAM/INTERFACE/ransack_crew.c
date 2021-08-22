#define str1	"Enemy Surrendered"
#define str2	"You must choose the destiny"
#define str3_1	"of"
#define str3_2  "surrendered men"

ref refMyCharacter;
ref refEnemyCharacter;

int nSurrenderedMen;
int nCompanionIndex;
int nResultMorale;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	PlayStereoSound("OBJECTS\ABORDAGE\abordage.wav");
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansackShip";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS
	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),32,39,160,167);
    CreateImage("myFace","FACE128_"+refMyCharacter.FaceId,"face",164,39,292,167);
    CreateString(true,"MyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,1.0); // PS
    CreateString(true,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
// changed by MAXIMUS -->
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,162,170,SCRIPT_ALIGN_CENTER,1.0);
    if(CheckAttribute(refMyCharacter,"firstname")==true) GameInterface.strings.MyName = refMyCharacter.name + " " + refMyCharacter.firstname + " " + refMyCharacter.lastname;
    else GameInterface.strings.MyName = refMyCharacter.name + " " + refMyCharacter.lastname;
// changed by MAXIMUS <--

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),480,39,608,167);
	
	CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
	CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
	
    CreateString(true,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,1.0); // PS
    CreateString(true,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(true,"String1",XI_ConvertString(str1),FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"String2",XI_ConvertString(str2),FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"String3",XI_ConvertString(str3_1)+" "+nSurrenderedMen+" "+XI_ConvertString(str3_2),FONT_NORMAL,COLOR_NORMAL,320,296,SCRIPT_ALIGN_CENTER,1.0);

// added by MAXIMUS -->
	CreateImage("BeginMorale","MORALE",GetMoralePicture(sti(refMyCharacter.Ship.Crew.Morale)),56,282,184,410);
	CreateImage("FinishMorale","MORALE",GetMoralePicture(nResultMorale),472,282,600,410);
	CreateString(TRUE,"bMorale",refMyCharacter.Ship.Crew.Morale,FONT_NORMAL,COLOR_NORMAL,120,378,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"fMorale",nResultMorale,FONT_NORMAL,COLOR_NORMAL,536,378,SCRIPT_ALIGN_CENTER,1.0);
// added by MAXIMUS <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("KillPress","KillProcess",0);
	SetEventHandler("SlavesPress","SlavesProcess",0);
	SetEventHandler("CrewPress","CrewProcess",0);
}

// added by MAXIMUS -->
string GetMoralePicture(int morale)
{
	if(morale<33) return "low morale";
	if(morale<66) return "medium morale";
	return "high morale";
}

void SetVariable()
{
	nSurrenderedMen = sti(refEnemyCharacter.Ship.Crew.Quantity);
	nResultMorale = 5+rand(80);
	nResultMorale = (nResultMorale*nSurrenderedMen + sti(refMyCharacter.Ship.Crew.Quantity)*sti(refMyCharacter.Ship.Crew.Morale))/(sti(refMyCharacter.Ship.Crew.Quantity)+nSurrenderedMen);
}
// added by MAXIMUS <--

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("KillPress","KillProcess");
	DelEventHandler("SlavesPress","SlavesProcess");
	DelEventHandler("CrewPress","CrewProcess");

	interfaceResultCommand = RC_INTERFACE_RANSACK_CREW_EXIT;
	EndCancelInterface(true);
}

void KillProcess()
{
	refEnemyCharacter.Ship.Crew.Quantity = 0;
	PlayStereoSound("OBJECTS\ABORDAGE\abordage_loosing.wav");
	ProcessCancelExit();
}

void SlavesProcess()
{
	ProcessCancelExit();
}

void CrewProcess()
{
	if(sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen>GetMaxCrewQuantity(&refMyCharacter)) // PRS3
	{
		refMyCharacter.ship.Crew.Quantity = GetMaxCrewQuantity(&refMyCharacter);
		refEnemyCharacter.ship.Crew.Quantity = sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen - GetMaxCrewQuantity(&refMyCharacter);
	}
	else
	{
		refMyCharacter.ship.Crew.Quantity = sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen;
		refEnemyCharacter.ship.Crew.Quantity = 0;
	}
	PlayStereoSound("OBJECTS\ABORDAGE\abordage_wining.wav");
	ProcessCancelExit();
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}
