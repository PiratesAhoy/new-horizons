void ProcessDialogEvent()
{
	ref PChar = GetMainCharacter();
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
					string ifEnemy = "";
					switch(PChar.EncNation)
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
				if(IsEntity(&worldMap)) { wdmReloadToSea(); }
				else
				{
					if(bSeaActive)
					{
						CreateEntity(&SeaFader, "fader");
						switch(NPChar.greeting)
						{
							case "land_ho": SetReloadImage(&SeaFader, "LandHo.tga"); break;
							case "sail_ho": SetReloadImage(&SeaFader, "SailHo.tga"); break;
						}
						SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
						Sea_ReloadStartDirect();
					}
				}
			DeleteAttribute(NPChar,"SailHo");
			}
			CreateEntity(&SeaFader, "fader");
			switch(NPChar.greeting)
			{
				case "land_ho": SetReloadImage(&SeaFader, "LandHo.tga"); break;
				case "sail_ho": SetReloadImage(&SeaFader, "SailHo.tga"); break;
			}
			SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
			Sea_ReloadStartDirect();
			ClearAttributes(PChar);
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
			ClearAttributes(PChar);
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
	if(CheckAttribute(GetMainCharacter(),"ShipEnc")) DeleteAttribute(GetMainCharacter(),"ShipEnc");
	if(!IsEntity(&worldMap)) { SendMessage(&BattleInterface,"ll",BI_SET_VISIBLE,true); }
}

void DialogDirectSailExit(ref char)
{
	if(dialogRun == false) return;
	DelEventHandler("frame", "DialogPlayGreeting");
	DeleteClass(&Dialog);
	if(FullDialogPath!="") UnloadSegment(FullDialogPath);
	if(PathDlgLngExtn!="") UnloadSegment(PathDlgLngExtn);
	ref mainChr = GetMainCharacter();
	if(dialogSelf == false)
	{
		LAi_Character_EndDialog(mainChr, char);
		LAi_Character_EndDialog(char, mainChr);
		SendMessage(mainChr, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
		DeleteAttribute(mainChr, "IsInDialog");
	}
	else
	{
		LAi_Character_EndDialog(char, char);
		SendMessage(char, "lsl", MSG_CHARACTER_EX_MSG, "InDialog", 0);
	}
	DeleteAttribute(GetMainCharacter(), "forcedlg");
	dialogRun = false;
	BLI_EnableShow();
	BLI_RefreshCommandMenu();
	PostEvent(EVENT_DIALOG_EXIT, 1, "l", sti(char.index));
}