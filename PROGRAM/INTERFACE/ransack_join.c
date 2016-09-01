#define str1	"Enemy Surrendered"
#define str2	"surrendered men wishes"
#define str3	"to join your crew"

ref refMyCharacter;
ref refEnemyCharacter;

int nSurrenderedMen;
int nResultMorale;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansack";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS
	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),32,39,160,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,1.0); // PS

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),480,39,608,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,1.0); // PS

    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"MyName",refMyCharacter.name + " " + refMyCharacter.lastname,FONT_NORMAL,COLOR_NORMAL,162,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
	CreateString(TRUE,"String1",XI_ConvertString(str1),FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String2",nSurrenderedMen+" "+XI_ConvertString(str2),FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String3",XI_ConvertString(str3),FONT_NORMAL,COLOR_NORMAL,320,296,SCRIPT_ALIGN_CENTER,1.0);

    CreateImage("myFace","FACE128_"+refMyCharacter.FaceId,"face",164,39,292,167);
    CreateImage("enemyFace","FACE128_"+refEnemyCharacter.FaceId,"face",348,39,476,167);

	CreateImage("BeginMorale","MORALE",GetMoralePicture(sti(refMyCharacter.Ship.Crew.Morale)),56,282,184,410);
	CreateImage("FinishMorale","MORALE",GetMoralePicture(nResultMorale),472,282,600,410);
	CreateString(TRUE,"bMorale",refMyCharacter.Ship.Crew.Morale,FONT_NORMAL,COLOR_NORMAL,120,378,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"fMorale",nResultMorale,FONT_NORMAL,COLOR_NORMAL,536,378,SCRIPT_ALIGN_CENTER,1.0);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("AgreePress","AgreeProcess",0);
	SetEventHandler("RefusePress","RefuseProcess",0);
}

string GetMoralePicture(int morale)
{
	if(morale<33) return "low morale";
	if(morale<66) return "medium morale";
	return "high morale";
}

void SetVariable()
{
	int SurrenderedProcent = CalcCharacterSkill(refMyCharacter,SKILL_LEADERSHIP)*8 + 10 + rand(10);
	nSurrenderedMen = (sti(refEnemyCharacter.ship.Crew.Quantity)*SurrenderedProcent)/100;
	nResultMorale = 5+rand(80);
	nResultMorale = (nResultMorale*nSurrenderedMen + sti(refMyCharacter.Ship.Crew.Quantity)*sti(refMyCharacter.Ship.Crew.Morale))/(sti(refMyCharacter.Ship.Crew.Quantity)+nSurrenderedMen);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("AgreePress","AgreeProcess");
	DelEventHandler("RefusePress","RefuseProcess");

	interfaceResultCommand = RC_INTERFACE_RANSACK_JOIN_EXIT;
	EndCancelInterface(true);
}

void AgreeProcess()
{
	if(sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen>GetMaxCrewQuantity(&refMyCharacter)) // PRS3
	{
		nSurrenderedMen = GetMaxCrewQuantity(&refMyCharacter) - sti(refMyCharacter.ship.Crew.Quantity); // PRS3
	}
	refMyCharacter.ship.Crew.Quantity = sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen;
	refEnemyCharacter.ship.Crew.Quantity = sti(refEnemyCharacter.ship.Crew.Quantity) - nSurrenderedMen;
	refMyCharacter.ship.Crew.Morale = nResultMorale;
	ProcessCancelExit();
}

void RefuseProcess()
{
	refEnemyCharacter.ship.Crew.Quantity = nSurrenderedMen;
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
