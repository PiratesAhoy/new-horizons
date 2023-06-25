//#include "DIALOGS\fake_apothecary_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";
		
			if(CheckAttribute(Pchar,"quest.med_apothecary") && Pchar.quest.med_apothecary == "port_royal")
			{
				Dialog.text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "port_royal1";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.med_apothecary") && Pchar.quest.med_apothecary == "no_dialog")
				{
					PlaySound("PEOPLE\air_violin.wav");
					DialogExit();				//this skips blank dialog
					Diag.CurrentNode = Diag.TempNode;	
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
				    || CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS"))
				{
					if(CheckCharacterItem(Pchar,"bladeviolin"))
					{
						Dialog.text = DLG_TEXT[10];
						Link.l1 = DLG_TEXT[11];
						Link.l1.go = "exit";
						Pchar.quest.med_apothecary = "no_dialog";
						AddDialogExitQuest("violin_delivered");
					}
					else
					{
						Dialog.text = DLG_TEXT[8];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit";
						Diag.TempNode = "first time";
					}
				}
				else
				{
					if(CheckCharacterItem(Pchar,"bladeviolin"))
					{
						Dialog.text = DLG_TEXT[12];
						Link.l1 = DLG_TEXT[13];
						Link.l1.go = "violin_but_no_chest1";

					}
					else
					{
						Dialog.text = DLG_TEXT[8];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit";
						Diag.TempNode = "first time";
					}
				}
			}			
		break;

		case "port_royal1":
			Dialog.text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "port_royal2";
		break;

		case "port_royal2":
			Dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "port_royal3";
		break;

		case "port_royal3":
			Dialog.text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "port_royal4";
		break;

		case "port_royal4":
			Pchar.quest.med_apothecary = "something_else";
			Dialog.text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("violin_mission");
		break;

		case "violin_but_no_chest1":
			Dialog.text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "exit";
			Diag.TempNode = "first time";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
