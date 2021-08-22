#define str1	"Enemy Surrendered"
#define str2	"choose the destiny of"
#define str3	"surrendered captain"

ref refMyCharacter;
ref refEnemyCharacter;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	//PlayStereoSound("OBJECTS\ABORDAGE\abordage.wav");
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansackShip";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS
	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),32,39,160,167); // PS CreateImage("myShip","SHIPS",shipRef.name,32,39,160,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,1.0); // PS
// changed by MAXIMUS -->
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,162,170,SCRIPT_ALIGN_CENTER,1.0);
    if(CheckAttribute(refMyCharacter,"firstname")==true) GameInterface.strings.MyName = refMyCharacter.name + " " + refMyCharacter.firstname + " " + refMyCharacter.lastname;
    else GameInterface.strings.MyName = refMyCharacter.name + " " + refMyCharacter.lastname;
// changed by MAXIMUS <--

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),480,39,608,167); // PS CreateImage("enemyShip","SHIPS",shipRef.name,480,39,608,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,1.0); // PS
    CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS

    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String1",XI_ConvertString(str1),FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String2",XI_ConvertString(str2),FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String3",XI_ConvertString(str3)+" - "+refEnemyCharacter.Name+" "+refEnemyCharacter.LastName,FONT_NORMAL,COLOR_NORMAL,320,296,SCRIPT_ALIGN_CENTER,1.0);

    CreateImage("myFace","FACE128_"+refMyCharacter.FaceId,"face",164,39,292,167);
    CreateImage("enemyFace","FACE128_"+refEnemyCharacter.FaceId,"face",348,39,476,167);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("KillPress","KillProcess",0);
	SetEventHandler("CapturePress","CaptureProcess",0);
}

void SetVariable()
{
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("KillPress","KillProcess");
	DelEventHandler("CapturePress","CaptureProcess");

	interfaceResultCommand = RC_INTERFACE_RANSACK_CAPTAIN_EXIT;
	EndCancelInterface(true);
}

void KillProcess()
{
	PlayStereoSound("OBJECTS\DUEL\pistol_small.wav");
	PlayStereoSound("OBJECTS\VOICES\DEAD\male\dead8.wav");
	ProcessCancelExit();
}

void CaptureProcess()
{
// added by MAXIMUS -->
	ref prisoner;
	makeref(prisoner,Characters[CHARACTERS_QUANTITY]);
	CHARACTERS_QUANTITY++;
		if(prisoner.id != "0")
		{
			int i = FindBlankCharSlot();
			CHARACTERS_QUANTITY = i+1;
			makeref(prisoner, Characters[i]);
		}
	if(CheckAttribute(refEnemyCharacter,"name")) prisoner.name								= refEnemyCharacter.name;
	if(CheckAttribute(refEnemyCharacter,"lastname")) prisoner.lastname						= refEnemyCharacter.lastname;
	if(CheckAttribute(refEnemyCharacter,"model")) prisoner.model							= refEnemyCharacter.model;
	if(CheckAttribute(refEnemyCharacter,"sex")) prisoner.sex								= refEnemyCharacter.sex;
	if(CheckAttribute(refEnemyCharacter,"model.animation")) prisoner.model.animation		= refEnemyCharacter.model.animation;
	facemaker(prisoner);
	if(CheckAttribute(refEnemyCharacter,"id")) prisoner.id									= "Captived_captain_"+CHARACTERS_QUANTITY;
	if(CheckAttribute(refEnemyCharacter,"reputation")) prisoner.reputation					= refEnemyCharacter.reputation;
	if(CheckAttribute(refEnemyCharacter,"experience")) prisoner.experience					= refEnemyCharacter.experience;
	if(CheckAttribute(refEnemyCharacter,"nation")) prisoner.nation							= refEnemyCharacter.nation;
	if(CheckAttribute(refEnemyCharacter,"rank")) prisoner.rank								= refEnemyCharacter.rank;
	if(CheckAttribute(refEnemyCharacter,"money")) prisoner.money							= sti(refEnemyCharacter.money);
	if(CheckAttribute(refEnemyCharacter,"quest.officertype")) prisoner.quest.officertype	= refEnemyCharacter.quest.officertype;

	prisoner.offgen = true;
	prisoner.officer = true;
	bool gennew = true;
	string tmpstr = prisoner.quest.officertype;
	/*switch(tmpstr)
	{
		case OFFIC_TYPE_BOATSWAIN: gennew = false; break;
		case OFFIC_TYPE_CANNONEER: gennew = false; break;
		case OFFIC_TYPE_QMASTER: gennew = false; break;
		case OFFIC_TYPE_NAVIGATOR: gennew = false; break;
		case OFFIC_TYPE_FIRSTMATE: gennew = false; break;
		case OFFIC_TYPE_CARPENTER: gennew = false; break;
		case OFFIC_TYPE_DOCTOR: gennew = false; break;
		case OFFIC_TYPE_ABORDAGE: gennew = false; break;
	}*/
	gennew = UsableOfficer(prisoner); //Levis
	if(!gennew)
	{
		/*switch(Rand(7))
		{
			case 0: prisoner.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
			case 1: prisoner.quest.officertype = OFFIC_TYPE_CANNONEER; break;
			case 2: prisoner.quest.officertype = OFFIC_TYPE_QMASTER; break;
			case 3: prisoner.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
			case 4: prisoner.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
			case 5: prisoner.quest.officertype = OFFIC_TYPE_CARPENTER; break;
			case 6: prisoner.quest.officertype = OFFIC_TYPE_DOCTOR; break;
			case 7: prisoner.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
		}*/
		prisoner.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
		LAi_Create_Officer(rand(8), &prisoner);
	}
	else { prisoner.quest.officertype = tmpstr; }

	// Aconcagua: 
	// do not apply the officer type class here
	// this will make sure that GetEffectiveSkill will return 1 for all skills.

	// TODO: do we have to calculate the modifier value???
	// suppose no, as char should not have items modifying skills...

	prisoner.quest.officerprice = makeint((sti(refMyCharacter.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10);
	LAi_NPC_Equip(prisoner, sti(refMyCharacter.rank), true, 0.5);

	if (IsCharacterEquipByGroup(refEnemyCharacter,BLADE_ITEM_TYPE))
	{
        string blade = GetCharacterEquipByGroup(refEnemyCharacter,BLADE_ITEM_TYPE);
        RemoveCharacterEquip(refEnemyCharacter, BLADE_ITEM_TYPE);
        TakeItemFromCharacter(refEnemyCharacter, blade);
        GiveItem2Character(refMyCharacter, blade);
	}
	if (IsCharacterEquipByGroup(refEnemyCharacter,GUN_ITEM_TYPE))
	{
        string gun = GetCharacterEquipByGroup(refEnemyCharacter,GUN_ITEM_TYPE);
        RemoveCharacterEquip(refEnemyCharacter, GUN_ITEM_TYPE);
        TakeItemFromCharacter(refEnemyCharacter, gun);
        GiveItem2Character(refMyCharacter, gun);
	}
	if (IsCharacterEquipByGroup(refEnemyCharacter,ARMOR_ITEM_TYPE))
	{
        string armor = GetCharacterEquipByGroup(refEnemyCharacter,ARMOR_ITEM_TYPE);
        RemoveCharacterEquip(refEnemyCharacter, ARMOR_ITEM_TYPE);
        TakeItemFromCharacter(refEnemyCharacter, armor);
        GiveItem2Character(refMyCharacter, armor);
	}
// added by MAXIMUS <--

	refEnemyCharacter.prisoned = true;
	AddPassenger(refMyCharacter,prisoner,true);
	PlayStereoSound("AMBIENT\JAIL\jail_door2.wav");
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
