//#include "DIALOGS\Job Anderson_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
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
			
			if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
			{
				PlaySound("VOICE\ENGLISH\Spa_m_a_026.wav");
				Dialog.text = DLG_TEXT[48];
				link.l1 = DLG_TEXT[49];
				link.l1.go = "exit";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			
			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "crew_level_up":
			PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");

			int wheat1 = GetSquadronGoods(Pchar, GOOD_WHEAT);
			int rum1 = GetSquadronGoods(Pchar, GOOD_RUM);

			RemoveCharacterGoods(Pchar, GOOD_WHEAT, makeint(makefloat(GetCrewQuantity(Pchar)) * FOOD_PER_CREW * WHEAT_DAYS));
			RemoveCharacterGoods(Pchar, GOOD_RUM, makeint(makefloat(GetCrewQuantity(Pchar)) * FOOD_PER_CREW * RUM_DAYS));

			AddCharacterGoods(Pchar, GOOD_WHEAT, makeint(makefloat(GetCrewQuantity(Pchar)) * FOOD_PER_CREW * WHEAT_DAYS));
			AddCharacterGoods(Pchar, GOOD_RUM, makeint(makefloat(GetCrewQuantity(Pchar)) * FOOD_PER_CREW * RUM_DAYS));			

			int wheat2 = GetSquadronGoods(Pchar, GOOD_WHEAT);
			int rum2 = GetSquadronGoods(Pchar, GOOD_RUM);
			
			if(wheat2 > wheat1 && rum2 > rum1)
			{
				Dialog.text = DLG_TEXT[50];
			}
			else
			{
				if(wheat2 > wheat1)
				{
					Dialog.text = DLG_TEXT[52];
				}
			}
			else
			{
				if(rum2 > rum1)
				{
					Dialog.text = DLG_TEXT[51];
				}
			}
			else Dialog.text = DLG_TEXT[7];

			link.l1 = DLG_TEXT[8];
			link.l1.go = "crew_level_up2";
		break;

		case "crew_level_up2":
			if (CheckAttribute(Pchar, "ship.crew.morale")) Pchar.ship.crew.morale = MORALE_MAX;
			PlaySound("OBJECTS\ABORDAGE\abordage_wining.wav");
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "mine";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "mine_no_thanks";			
		break;

		case "mine":
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "mine1";
		break;

		case "mine1":
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "mine2";
		break;

		case "mine2":
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "mine3";
		break;

		case "mine3":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "mine4_first_time";
		break;

		case "mine4_first_time":
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "mine5_first_time";
		break;

		case "mine5_first_time":
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "mine5_first_time_rum";
		//	link.l1.go = "exit";
		//	AddDialogExitQuest("mine_no_money_first_time");
		break;

		case "mine5_first_time_rum":
			PlaySound("VOICE\ENGLISH\Spa_m_a_026.wav");
			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			AddDialogExitQuest("mine_no_money_first_time");
		break;

	//....................................................................
		case "mine4_repeat":
			PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "mine5_repeat";
		break;

		case "mine5_repeat":
			Dialog.text = DLG_TEXT[22];
			if(CheckCharacterItem(Pchar, "jewelry5"))
			{
				TakeItemFromCharacter(Pchar, "jewelry5");
				link.l1 = DLG_TEXT[23];
				link.l1.go = "mine6";
			}
			else
			{
				link.l1 = DLG_TEXT[24];
				link.l1.go = "exit";
				AddDialogExitQuest("mine_no_money_repeat");
			}	
		break;

		case "mine6":
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "mine7";
		break;

		case "mine7":
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "mine8";
		break;

		case "mine8":
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "mine9";
		break;

		case "mine9":
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "mine10";
		break;

		case "mine10":
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			AddDialogExitQuest("mine_open");
		break;

		case "mine11":
			PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "mine";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "mine_no_thanks";	
		break;
		
		case "mine_no_thanks":
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			AddDialogExitQuest("mine_no_thanks");
		break;
	//....................................................................
		case "switch_room":
			PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "switch_room1";
		break;

		case "switch_room1":
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("switch_room_open");
		break;
	//....................................................................
		case "mine_exit":
			PlaySound("VOICE\ENGLISH\Spa_m_a_054.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "mine_exit1";
		break;

		case "mine_exit1":
			PlaySound("OBJECTS\DUEL\sword_fallen.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladepickaxe2");
			TakeItemFromCharacter(Pchar, "bladehammer");
			TakeItemFromCharacter(Pchar, "bladeaxe4");
			TakeItemFromCharacter(Pchar, "bladesaw");
			if(CheckCharacterItem(Pchar,"bladeA11"))
			{
				EquipCharacterByItem(Pchar, "bladeA11");
			}
			else EquipCharacterByItem(Pchar, "bladeX4");
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			EquipCharacterbyItem(Pchar, "pistol206");

			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "mine_exit2";
		break;

		case "mine_exit2":
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("mine_exit_done");
		break;
	//....................................................................
		case "food_keys":
			if(CheckCharacterItem(Pchar,"key15"))
			{
				PlaySound("VOICE\ENGLISH\Spa_m_a_024.wav");
			}
			else
			{
				PlaySound("INTERFACE\took_item.flac");
				GiveItem2Character(Pchar, "key15");
				Pchar.quest.med_Anderson = "food_keys_done";	
				
				NPChar.dlgover = true;
				DialogExit();
				AddDialogExitQuest("food_keys_given");	
			}
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
