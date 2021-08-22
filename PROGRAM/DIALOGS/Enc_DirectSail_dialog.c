void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			PlaySound(NPChar.greeting);
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			switch(NPChar.greeting)
			{
				case "land_ho":
					string toIsland = "";
					if(CheckAttribute(NPChar,"directsail.toisland")) { toIsland = DLG_TEXT[6] + LanguageConvertString(tmpLangFileID, NPChar.directsail.toisland) + "."; }
					Dialog.Text = DLG_TEXT[0] + toIsland;
					Link.l1 = DLG_TEXT[2] + DLG_TEXT[3];
					Link.l1.go = "Engage";
				break;
				case "sail_ho":
					ref PChar = GetMainCharacter();
					CalculateInfoData();
					string ifEnemy = "";
					switch(GetNationRelation2MainCharacter(sti(PChar.directsail.Encnation)))
					{
						case RELATION_ENEMY: ifEnemy = DLG_TEXT[4]; break;
						case RELATION_FRIEND: ifEnemy = DLG_TEXT[10]; break;
						case RELATION_NEUTRAL: ifEnemy = DLG_TEXT[11]; break;
					}
					Dialog.Text = PChar.EncInfo;
					Link.l1 = DLG_TEXT[2] + ifEnemy;
					Link.l1.go = "Engage";
					if(sti(PChar.CanEscape)>0)
					{
						Link.l2 = DLG_TEXT[5];
						Link.l2.go = "Exit";
					}
				break;
			}
			NextDiag.TempNode = "First time";
		break;

		case "Engage":
			PlaySound("clear_for_action");
			NextDiag.CurrentNode = NextDiag.TempNode;
			if(CheckAttribute(NPChar,"SailHo"))
			{
				if(CheckAttribute(NPChar,"DirectSail.messenger"))
				{
					if(IsEntity(&worldMap)) { wdmReloadToSea(); }
					else
					{
						if(bSeaActive)
						{
							CreateEntity(&SeaFader, "fader");
							switch(NPChar.greeting)
							{
								case "land_ho": SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("LandHo.tga")); break; // KK
								case "sail_ho": SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("SailHo.tga")); break; // KK
							}
							SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
							Sea_ReloadStartDirect();
						}
					}
				}
				DeleteAttribute(NPChar,"SailHo");
			}
			if(CheckAttribute(NPChar,"DirectSail.messenger"))
			{
				CreateEntity(&SeaFader, "fader");
				switch(NPChar.greeting)
				{
					case "land_ho": SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("LandHo.tga")); break; // KK
					case "sail_ho": SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("SailHo.tga")); break; // KK
				}
				SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
				Sea_ReloadStartDirect();
			}
			ClearAttributes(NPChar);
			DialogDirectSailExit(NPChar);
			if(CheckAttribute(GetMainCharacter(),"ShipEnc")) { DeleteAttribute(GetMainCharacter(),"ShipEnc"); }
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			if(CheckAttribute(NPChar,"SailHo"))
			{
				if(CheckAttribute(GetMainCharacter(),"ShipEnc")) { DeleteAttribute(GetMainCharacter(),"ShipEnc"); }
				DeleteAttribute(NPChar,"SailHo");
			}
			if(CheckAttribute(NPChar,"DirectSail.messenger")) { DeleteAttribute(NPChar,"DirectSail"); }
			if(CheckAttribute(GetMainCharacter(),"DirectSail")) { DeleteAttribute(GetMainCharacter(),"DirectSail"); }
			ClearAttributes(NPChar);
			DialogDirectSailExit(NPChar);
			if(CheckAttribute(GetMainCharacter(),"ShipEnc")) { DeleteAttribute(GetMainCharacter(),"ShipEnc"); }
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}

void ClearAttributes(ref NPChar)
{
	if(CheckAttribute(NPChar,"old.model"))
	{
		NPChar.model = NPChar.old.model;
		DeleteAttribute(NPChar,"old.model");
		Facemaker(NPChar);
	}
	if(CheckAttribute(NPChar,"old.name"))
	{
		NPChar.name = NPChar.old.name;
		DeleteAttribute(NPChar,"old.name");
	}
	if(CheckAttribute(NPChar,"old.lastname"))
	{
		NPChar.lastname = NPChar.old.lastname;
		DeleteAttribute(NPChar,"old.lastname");
	}
	if(CheckAttribute(NPChar,"old.Dialog.Filename"))
	{
		NPChar.Dialog.Filename = NPChar.old.Dialog.Filename;
		DeleteAttribute(NPChar,"old.Dialog.Filename");
	}
	if(CheckAttribute(NPChar,"old.Dialog.Currentnode"))
	{
		NPChar.Dialog.Currentnode = NPChar.old.Dialog.Currentnode;
		DeleteAttribute(NPChar,"old.Dialog.Currentnode");
	}
	if(CheckAttribute(NPChar,"old.disableDlg"))
	{
		NPChar.disableDlg = sti(NPChar.old.disableDlg);
		DeleteAttribute(NPChar,"old.disableDlg");
	}
	if(CheckAttribute(NPChar,"old.greeting"))
	{
		NPChar.greeting = NPChar.old.greeting;
		DeleteAttribute(NPChar,"old.greeting");
	}
	if(CheckAttribute(NPChar,"IsFantom") && NPChar.IsFantom==true) { DeleteCharacter(NPChar); }
	if(CheckAttribute(GetMainCharacter(),"SailHo")) { DeleteAttribute(GetMainCharacter(),"SailHo"); }
	aref curChar;
	makearef(curChar,NPChar.directsail);
	if(CheckAttribute(curChar,"DirectEncounter")) { DeleteAttribute(curChar,"DirectEncounter"); }
	makearef(curChar,characters[GetMainCharacterIndex()].directsail);
	if(CheckAttribute(curChar,"DirectEncounter")) { DeleteAttribute(curChar,"DirectEncounter"); }
	if(CheckAttribute(curChar,"directsail.Encnation")) { DeleteAttribute(curChar,"directsail.Encnation"); }
	if(!IsEntity(&worldMap)) { SendMessage(&BattleInterface,"ll",BI_SET_VISIBLE,true); }
}

void CalculateInfoData()
{
	float EncSpeed = 1.0;
	ref mainCh = GetMainCharacter();
	mainCh.ShipEnc = "none";
	mainCh.EncInfo = InfoReloadToSea(mainCh);
	mainCh.CanEscape = 0;

	float modifier = 1.0;
	if(checkAttribute(mainCh,"Perks.List.ShipSpeedUp")) { if(sti(mainCh.Perks.List.ShipSpeedUp)) modifier += 0.2; }
	if(checkAttribute(mainCh,"Perks.List.ShipTurnRateUp")) { if(sti(mainCh.Perks.List.ShipTurnRateUp)) modifier += 0.15; }
	if(checkAttribute(mainCh,"Perks.List.SailingProfessional")) { if(sti(mainCh.Perks.List.SailingProfessional)) modifier += 0.65; }
	ref MyShipType = GetShipByType(GetCharacterShipType(mainCh));
	aref arship; makearef(arship, mainCh.ship);
	float SpeedMod = stf(GetLocalShipAttrib(arship, MyShipType, "SpeedRate")) / 12 / EncSpeed;
	float sailmod = sqrt(GetShipSkill(mainCh, SKILL_SAILING)) * 16 * modifier * SpeedMod;
	if(GetNationRelation2MainCharacter(sti(mainCh.directsail.Encnation))==RELATION_ENEMY)
	{
		if( rand(100) / (sqrt(CalcCharacterSkill(mainCh, SKILL_SNEAK)) * 3.2) > sailmod ) { mainCh.CanEscape = 0; }
		else { mainCh.CanEscape = 1; }
	}
}

string InfoReloadToSea(ref mc)
{
	if(!CheckAttribute(mc,"directsail.DirectEncounter")) { DirectEncounter(0.0, false); mc.directsail.DirectEncounter = true; }
	if(!CheckAttribute(mc,"directsail.Idx")) return "";
	if(!CheckAttribute(mc,"directsail.Num")) return "";
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string strInfo = "";
	float EncSpeed = 1.0;
	//Encounters
	ref rEncounter;
	int isShipEncounterType = 0;
	int numEncounters = sti(mc.directsail.Num);
	string EncShipsNum = sti(mc.directsail.RealEncounterType);
	for(int i = 0; i < numEncounters; i++)
	{
		if(numEncounters>0)
		{
			isShipEncounterType++;
			if(isShipEncounterType>1)
			{
				if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum))
				{
					strInfo = strInfo + " " + XI_ConvertString("vs.") + " ";
				}
			}
			if(SAILHO_INFOLEVEL>=1)
			{
				 if(isShipEncounterType==1) {
				/*if(isShipEncounterType>1) { strInfo = LanguageConvertString(tmpLangFileID,"Sail Ho! There's a battle up ahead sir, it looks like") + " " + strInfo; }
				else {*/ strInfo = LanguageConvertString(tmpLangFileID,"Sail Ho! It looks like") + " "; }//}
			}
			rEncounter = Group_GetGroupByIndex(sti(mc.directsail.Idx));

			switch(sti(mc.directsail.RealEncounterType))
	       	{
				case 0:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"merchants"); }
					EncSpeed = 0.65;
				break;
				case 1:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"merchants with a light escort"); }
					EncSpeed = 0.7;
				break;
				case 2:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a single merchant with heavy escort"); }
					EncSpeed = 0.75;
				break;
				case 3:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a small patrol"); }
					EncSpeed = 0.95;
				break;
				case 4:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"warships"); }
					EncSpeed = 0.75;
				break;
				case 5:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"warships"); }
					EncSpeed = 0.95;
				break;
				case 6:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + DLG_TEXT[9]; }
					EncSpeed = 0.85;
				break;
				case 7:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a rag-tag bunch"); }
					EncSpeed = 0.75;
				break;
				case 8:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a group of merchants"); }
					EncSpeed = 0.6;
				break;
				case 9:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"an escorted group of merchants"); }
					EncSpeed = 0.7;
				break;
				case 10:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a convoy"); }
					EncSpeed = 0.75;
				break;
				case 11:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a large patrol"); }
					EncSpeed = 0.9;
				break;
				case 12:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a small fleet"); }
					EncSpeed = 0.8;
				break;
				case 13:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a battle fleet"); }
					EncSpeed = 0.65;
				break;
				case 14:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a rag-tag bunch"); }
					EncSpeed = 0.85;
				break;
				case 15:
					if(!CheckAttribute(mc,"directsail.RealEncounterType."+EncShipsNum)) { mc.directsail.RealEncounterType.(EncShipsNum) = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"a scratch patrol"); }
					EncSpeed = 0.75;
				break;
					if(!CheckAttribute(mc,"directsail.RealEncounterType.default")) { mc.directsail.RealEncounterType.default = true; strInfo = strInfo + LanguageConvertString(tmpLangFileID,"ships"); }
	        }
			if(SAILHO_INFOLEVEL >=2 && isShipEncounterType==1)
			{
				if(sti(mc.directsail.Encnation) != PIRATE) { strInfo = strInfo + " " + LanguageConvertString(tmpLangFileID,"flying the colors of") + " " + XI_ConvertString("3"+Nations[sti(mc.directsail.Encnation)].Name); }
				else { strInfo = strInfo + " " + LanguageConvertString(tmpLangFileID,"flying the Jolly Roger"); }
			}
			if(mc.ShipEnc != "enemy")
			{
				if(GetNationRelation2MainCharacter(sti(mc.directsail.Encnation)) == RELATION_ENEMY) { mc.ShipEnc = "enemy"; }
				else { mc.ShipEnc = "ship"; }
			}
		}
		else { strInfo += "."; }
	}
	if(isShipEncounterType>1)
	{
		string shipsAmount = DLG_TEXT[7];
		if(isShipEncounterType>4) { shipsAmount = DLG_TEXT[8]; }
		strInfo += ", " + isShipEncounterType + shipsAmount;
	}
	if(SAILHO_INFOLEVEL<1)
	{
		/*if(isShipEncounterType>1) { strInfo = LanguageConvertString(tmpLangFileID,"Sail Ho! And gunfire, there's a battle up ahead!"); }
		else {*/ strInfo = LanguageConvertString(tmpLangFileID,"Sail Ho!"); //}
	}
	DeleteAttribute(mc,"Enemy");
	aref DSreal; makearef(DSreal, mc.directsail.RealEncounterType);
	if(CheckAttribute(DSreal, EncShipsNum)) { DeleteAttribute(DSreal, EncShipsNum); }
	if(CheckAttribute(DSreal, "default")) { DeleteAttribute(DSreal, "default"); }
	LanguageCloseFile(tmpLangFileID);
	return strInfo;
}

void DialogDirectSailExit(ref char)
{
	//Если диалога уже не ведётся, выйдем
	if(dialogRun == false) return;
	DelEventHandler("frame", "DialogPlayGreeting");
	//Освобождаем ресурсы
	DeleteClass(&Dialog);
	if(FullDialogPath!="") UnloadSegment(FullDialogPath);
	if(PathDlgLngExtn!="") UnloadSegment(PathDlgLngExtn);
	if(dialogSelf == false)
	{
		//Ссылка на главного персонажа
		ref mainChr = GetMainCharacter();
		//Отметим, что персонажи освободились от диалога
		LAi_Character_EndDialog(mainChr, char);
		LAi_Character_EndDialog(char, mainChr);
		SendMessage(mainChr, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		DeleteAttribute(mainChr, "IsInDialog");
	}else{
		LAi_Character_EndDialog(char, char);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
	}
	DeleteAttribute(GetMainCharacter(), "forcedlg");
	dialogRun = false;
	//Сообщим об окончании диалога
	PostEvent(EVENT_DIALOG_EXIT, 1, "l", sti(char.index));
}
