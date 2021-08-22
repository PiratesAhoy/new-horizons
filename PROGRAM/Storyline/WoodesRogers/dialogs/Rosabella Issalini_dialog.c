//#include "DIALOGS\Rosabella Issalini_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			if(CheckAttribute(Pchar,"quest.prescriptions") && Pchar.quest.prescriptions == "no")
			{
				PlaySound("VOICE\ENGLISH\gr_Rosabella1.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "prescriptions";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Rosabella") && Pchar.quest.Rosabella == "first_meeting")
				{
					Pchar.quest.Rosabella = "repeat";
					PlaySound("VOICE\ENGLISH\gr_Rosabella2.wav");
					dialog.text = DLG_TEXT[32];
					link.l1 = DLG_TEXT[33];
					link.l1.go = "exit";
				}
				else
				{
			    		PlaySound("VOICE\ENGLISH\gr_Rosabella3.wav");
					dialog.text = DLG_TEXT[30];
					link.l1 = DLG_TEXT[31];
					link.l1.go = "exit";
				}
			}
			Diag.TempNode = "First Time";
		break;

		case "prescriptions":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "prescriptions1";
		break;

		case "prescriptions1":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "prescriptions2";
		break;

		case "prescriptions2":
			Pchar.quest.prescriptions = "yes";

			if(CheckCharacterItem(Pchar,"bladesurgcan3"))
			{
				TakeItemFromCharacter(Pchar, "bladesurgcan3"); 			
				GiveItem2Character(Pchar, "bladesurgcan3_r");
				GiveItem2Character(Pchar, "prescriptions");
				if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
				{

				}
				else EquipCharacterByItem(Pchar, "bladesurgcan3_r");
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladesurgcan2"))
				{
					TakeItemFromCharacter(Pchar, "bladesurgcan2"); 			
					GiveItem2Character(Pchar, "bladesurgcan2_r");
					GiveItem2Character(Pchar, "prescriptions");
					if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
					{

					}
					else EquipCharacterByItem(Pchar, "bladesurgcan2_r");					
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladesurgcan"))
				{
					TakeItemFromCharacter(Pchar, "bladesurgcan"); 			
					GiveItem2Character(Pchar, "bladesurgcan_r");
					GiveItem2Character(Pchar, "prescriptions");
					if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
					{

					}
					else EquipCharacterByItem(Pchar, "bladesurgcan_r");
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladesurgery3"))
				{
					TakeItemFromCharacter(Pchar, "bladesurgery3"); 			
					GiveItem2Character(Pchar, "bladesurgery3_r");
					GiveItem2Character(Pchar, "prescriptions");
					if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
					{

					}
					else EquipCharacterByItem(Pchar, "bladesurgery3_r");
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladesurgery2"))
				{
					TakeItemFromCharacter(Pchar, "bladesurgery2"); 			
					GiveItem2Character(Pchar, "bladesurgery2_r");
					GiveItem2Character(Pchar, "prescriptions");
					if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
					{

					}
					else EquipCharacterByItem(Pchar, "bladesurgery2_r");
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladesurgery"))
				{
					TakeItemFromCharacter(Pchar, "bladesurgery"); 			
					GiveItem2Character(Pchar, "bladesurgery_r");
					GiveItem2Character(Pchar, "prescriptions");
					if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
					{

					}
					else EquipCharacterByItem(Pchar, "bladesurgery_r");
				}
			}
			else
			{
				GiveItem2Character(Pchar, "bladeprescriptions");
				if(IsEquipCharacterByItem(Pchar, "bladefish") || IsEquipCharacterByItem(Pchar, "bladeviolin"))
				{

				}
				else EquipCharacterByItem(Pchar, "bladeprescriptions");
			}

			AddQuestRecord("Extra_drugs", "5");

			if(CheckAttribute(Pchar,"quest.collect_more_drugs") && Pchar.quest.collect_more_drugs == "yes")
			{
				LAi_QuestDelay("all_extra_drugs_check", 0.1);
			}

			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "exit":
			if(CheckAttribute(Pchar,"quest.crew_gold") && Pchar.quest.crew_gold == "placed")
			{
				//do nothing
			}
			else
			{
				locations[FindLocation(Pchar.location)].box4.items.jewelry5 = 1;
				locations[FindLocation(Pchar.location)].box4.money = 346;
				Pchar.quest.crew_gold = "placed";
				AddDialogExitQuest("crew_hatch_lock_rosabella");
			}
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}