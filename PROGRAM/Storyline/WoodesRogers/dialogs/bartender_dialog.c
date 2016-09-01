//#include "DIALOGS\bartender_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();


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
			Dialog.snd = "voice\THDI\THDI001";

			
			if(CheckCharacterItem(CharacterFromID("wr_man2"),"bladebucket"))
			{
				Dialog.text = DLG_TEXT[2];
				if(CheckAttribute(Pchar,"quest.bar_rum") && Pchar.quest.bar_rum == "0")
				{				
					link.l1 = DLG_TEXT[3];
					link.l1.go = "rum";
				}
				
				if(CheckAttribute(Pchar,"quest.bar_wine") && Pchar.quest.bar_wine == "0")
				{
					link.l2 = DLG_TEXT[4];
					link.l2.go = "wine";
				}

				if(CheckAttribute(Pchar,"quest.bar_beer") && Pchar.quest.bar_beer != "2")
				{
					link.l3 = DLG_TEXT[5];
					link.l3.go = "beer";
				}

				link.l4 = DLG_TEXT[6];
				link.l4.go = "water";

				//sound scheme ....
				if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "0")
				{
					PlaySound("VOICE\ENGLISH\Dut_m_a_025.wav");
				}
				if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "no_rum")
				{
					PlaySound("OBJECTS\DUEL\man_hit6.wav");
				}

				if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "bought_wine")
				{
					PlaySound("INTERFACE\button2.wav");
					PlaySound("INTERFACE\button2.wav");
				}
				if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "drank_beer")
				{
					PlaySound("AMBIENT\TAVERN\man5.wav");
				}
			}	
			else
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_031.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
		break;

		case "rum":
			Pchar.quest.bar_status = "no_rum";
			Pchar.quest.bar_rum = "1";
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "first time";
		break;	

		case "wine":
			Dialog.text = DLG_TEXT[9];
			if (makeint(pchar.money) >= 250)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "wine1";
				link.l2 = DLG_TEXT[13];
				link.l2.go = "first time";	//wine option remains
			}
			else
			{
				Pchar.quest.bar_wine = "1";	//means no more wine option
				link.l1 = DLG_TEXT[8];
				link.l1.go = "first time";
			}
		break;

		case "wine1":
			Pchar.quest.bar_status = "bought_wine";
			Pchar.quest.bar_wine = "1";
			Log_SetStringToLog("Wonder what kind of import that is!");
			GiveItem2Character(Pchar, "potionwine2");
			AddMoneyToCharacter(pchar, -250);
			PlaySound("INTERFACE\coins7.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "first time";	
		break;	

		case "beer":
			Dialog.text = DLG_TEXT[14];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "beer1";
				link.l2 = DLG_TEXT[18];
				link.l2.go = "first time";	//beer option remains
			}
			else
			{
				Pchar.quest.bar_status = "drank_no_beer";
				Pchar.quest.bar_beer = "2";	//means no more beer option
				link.l1 = DLG_TEXT[8];
				link.l1.go = "first time";
			}
		break;
	
		case "beer1":
			PlaySound("AMBIENT\TAVERN\man6.wav");
			Pchar.quest.bar_status = "drank_beer";
			AddMoneyToCharacter(pchar, -5);
			AddpartyExp(pchar, 10);
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "first time";
		break;

		case "water":
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "water1";
		break;

		case "water1":
			PlaySound("PEOPLE\step_dpwater.wav");
			PlaySound("PEOPLE\Jump_Counter.wav");

			RemoveCharacterEquip(CharacterFromID("wr_man2"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(CharacterFromID("wr_man2"), "bladebucket");
			RemoveCharacterEquip(CharacterFromID("wr_man2"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(CharacterFromID("wr_man2"), "pistolbucket");

		Pchar.quest.take_items_log = "2";
			GiveItem2Character(Pchar, "bladebucket");
			EquipCharacterByItem(Pchar, "bladebucket");
			GiveItem2Character(Pchar, "pistolbucket");
			EquipCharacterByItem(Pchar, "pistolbucket");
		DeleteAttribute(Pchar,"quest.take_items_log");

			ChangeCharacterAddressGroup(CharacterFromID("wr_man2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("wr_man2"), "wr_gunroom", "barmen", "stay");
			//removes the remaining bucket?

			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			//AddDialogExitQuest("wheel_check");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
