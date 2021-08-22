//#include "DIALOGS\Charles Vane_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


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

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckCharacterPerk(Pchar, "BasicDefence"))
				{
					PlaySound("VOICE\ENGLISH\pir_capR10.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
				else
				{
					PlaySound("VOICE\ENGLISH\pir_capR2.wav");
					LAi_SetStayType(CharacterFromID("pir_cap1"));
					LAi_SetActorType(CharacterFromID("pir_cap1"));
					LAi_ActorTurnToCharacter(characterFromID("pir_cap1"), Pchar);

					Pchar.perks.list.BasicDefence = true;
					Pchar.quest.Aperks = makeint(Pchar.quest.Aperks)-1;
					Dialog.text = DLG_TEXT[59];
					link.l1 = DLG_TEXT[60];
					link.l1.go = "exit";
					AddDialogExitQuest("perk_BasicDefence");
				}
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
				{
					if(CheckCharacterItem(Pchar,"jewelcross"))
					{
							PlaySound("VOICE\ENGLISH\pir_capR12.wav");
							Dialog.text = DLG_TEXT[99];
							link.l1 = DLG_TEXT[100];
							link.l1.go = "trade";
					}
					else
					{
							PlaySound("VOICE\ENGLISH\pir_capR10.wav");
							Dialog.text = DLG_TEXT[0];
							link.l1 = DLG_TEXT[1];
							link.l1.go = "exit";
					}
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\pir_capR10.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		break;

		case "who_are_you":
			PlaySound("VOICE\ENGLISH\pir_capR1.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "who_are_you2";
		break;
	
		case "who_are_you2":
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "who_are_you3";
		break;

		case "who_are_you3":
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			Diag.TempNode = "tell_your_story";
			LAi_SetStayType(CharacterFromID("pir_cap1"));
		break;

	//................................................................
		case "tell_your_story":
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("tell_your_story_done");
		break;
	//................................................................
		case "tell_your_story2":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("tell_your_story2_done");
		break;
	//................................................................
		case "tell_your_story3":
			PlaySound("VOICE\ENGLISH\pir_capR4.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("tell_your_story3_done");
		break;
	//................................................................
		case "what_to_do":
			PlaySound("VOICE\ENGLISH\pir_capR9.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("what_to_do_done");
		break;
	//................................................................
		case "medicine_talk":
			PlaySound("VOICE\ENGLISH\pir_capR6.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "medicine_talk2";
		break;

		case "medicine_talk2":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("medicine_talk2_done");
		break;
	//................................................................
		case "medicine_talk3":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "medicine_quest_no";
			link.l2 = DLG_TEXT[22];
			link.l2.go = "medicine_quest_greedy";
			link.l3 = DLG_TEXT[23];
			link.l3.go = "medicine_quest_nochoice";
			link.l4 = DLG_TEXT[24];
			link.l4.go = "medicine_quest_yes";
		break;

		case "medicine_quest_no":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("medicine_quest_no");
		break;

		case "medicine_quest_greedy":
			Pchar.quest.medicine_greedy = "done";
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "medicine_quest_greedy2";
		break;

		case "medicine_quest_greedy2":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			DeleteAttribute(Pchar, "items");//takes all incl fists
			GiveItem2Character(Pchar, "bladeX4");

			int gold;
			gold = GetCharacterMoney(Pchar);
			if(gold >= 100) 
			{
				PlaySound("INTERFACE\coins8.wav");
			}
			else
			{
				if(gold >= 10) 
				{
					PlaySound("INTERFACE\coins7.wav");
				}
			}
			else
			{
				if(gold >= 1) 
				{
					PlaySound("INTERFACE\coin_drop.wav");
				}
			}
			AddMoneyToCharacter(Pchar, -10000);

			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "medicine_quest_greedy3";
		break;

		case "medicine_quest_greedy3":
			GiveItem2Character(Pchar, "bladepickaxe2");
			GiveItem2Character(Pchar, "bladehammer");
			GiveItem2Character(Pchar, "bladeaxe4");
			GiveItem2Character(Pchar, "bladesaw");
			EquipCharacterByItem(Pchar, "bladesaw");

			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "medicine_talk4";
		break;

		case "medicine_talk4":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "medicine_quest_no";
			if(CheckAttribute(Pchar,"quest.medicine_greedy") && Pchar.quest.medicine_greedy == "not_yet")
			{
				link.l2 = DLG_TEXT[22];
				link.l2.go = "medicine_quest_greedy";
			}
			link.l3 = DLG_TEXT[23];
			link.l3.go = "medicine_quest_nochoice";
			link.l4 = DLG_TEXT[24];
			link.l4.go = "medicine_quest_yes";
		break;

		case "medicine_quest_nochoice":
			PlaySound("VOICE\ENGLISH\pir_capR7.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "medicine_quest_no";
			if(CheckAttribute(Pchar,"quest.medicine_greedy") && Pchar.quest.medicine_greedy == "not_yet")
			{
				link.l2 = DLG_TEXT[22];
				link.l2.go = "medicine_quest_greedy";
			}
			link.l3 = DLG_TEXT[23];
			link.l3.go = "medicine_quest_nochoice";
			link.l4 = DLG_TEXT[24];
			link.l4.go = "medicine_quest_yes";
		break;
	//....................................................................................
		case "medicine_quest_yes":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "medicine_quest_yes2";
		break;

		case "medicine_quest_yes2":
			if(CheckAttribute(Pchar,"quest.medicine_greedy") && Pchar.quest.medicine_greedy == "done")
			{
				Dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
				link.l1.go = "medicine_quest_yes3";
			}

			if(CheckAttribute(Pchar,"quest.medicine_greedy") && Pchar.quest.medicine_greedy == "not_yet")
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "pistol201");
				TakeItemFromCharacter(Pchar, "pistol202");
				TakeItemFromCharacter(Pchar, "pistol203");
				TakeItemFromCharacter(Pchar, "pistol204");
				TakeItemFromCharacter(Pchar, "pistol205");

				gold = GetCharacterMoney(Pchar);
				if(gold >= 100) 
				{
					PlaySound("INTERFACE\coins8.wav");
				}
				else
				{
					if(gold >= 10) 
					{
						PlaySound("INTERFACE\coins7.wav");
					}
				}
				else
				{
					if(gold >= 1) 
					{
						PlaySound("INTERFACE\coin_drop.wav");
					}
				}
				AddMoneyToCharacter(Pchar, -10000);

				Pchar.quest.medicine_greedy = "done";
				Dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "medicine_quest_yes2A";	//yes on the right way again
			}
		break;

		case "medicine_quest_yes2A":
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "medicine_quest_yes3";
		break;	

		case "medicine_quest_yes3":
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "medicine_quest_yes4";
		break;

		case "medicine_quest_yes4":
			PlaySound("VOICE\ENGLISH\pir_capR5.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("medicine_quest_yes4_done");
		break;

		case "church_captains":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "church_captains1";
		break;	

		case "church_captains1":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_sacristy");
		break;	

		case "Medicine_delivered":
			Locations[FindLocation("wr_church_outside")].reload.l1.disable = 1;
			Locations[FindLocation("wr_Cavern")].reload.l1.disable = 1;
			Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_ground_open";
			ChangeCharacterAddressGroup(CharacterFromID("pir_cap12"), "none", "", "");
			
			PlaySound("VOICE\ENGLISH\pir_capR4.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_sacristy_sit_down");
		break;

		case "return_items":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_sacristy_Rackham_items");
		break;

		case "perk_talk":
			PlaySound("VOICE\ENGLISH\pir_capR6.wav");
			if(CheckAttribute(Pchar,"quest.Tperks") && Pchar.quest.Tperks == 0)
			{
				Pchar.quest.sit_sacristy = "yes";	
			
				Dialog.text = DLG_TEXT[51];
				link.l1 = DLG_TEXT[52];
				link.l1.go = "monk_talk";		//continue to monk talk, prisoner talk, sash
			}
			else
			{
				Dialog.text = DLG_TEXT[53];
				link.l1 = DLG_TEXT[54];
				link.l1.go = "perk_talk1";
			}
		break;

		case "perk_talk1":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			switch(Pchar.quest.Tperks)
			{
				case "1":
					Dialog.text = DLG_TEXT[55];
					link.l1 = DLG_TEXT[58];
					link.l1.go = "exit";
				break;

				case "2":
					Dialog.text = DLG_TEXT[56];
					link.l1 = DLG_TEXT[58];
					link.l1.go = "exit";
				break;

				case "3":
					Dialog.text = DLG_TEXT[57];
					link.l1 = DLG_TEXT[58];
					link.l1.go = "exit";
				break;
			}
			AddDialogExitQuest("search_perks");
		break;

		case "monk_talk":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "monk_talk1";
		break;

		case "monk_talk1":
			PlaySound("VOICE\ENGLISH\pir_capR7.wav");
			Dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "monk_talk2";
		break;

		case "monk_talk2":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "prisoners_leave";
			//AddQuestRecord("Charles_Vanes_quest", "11");		//pдr what?
		break;

		case "prisoners_leave":
			PlaySound("VOICE\ENGLISH\pir_capR5.wav");
			Dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "exit";
			AddDialogExitQuest("prisoners_leave");
		break;

		case "red_outfits":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "sit", "sit4");//so he's not hiding Vane

			Dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "red_outfits1";
		break;

		case "red_outfits1":
			PlaySound("VOICE\ENGLISH\pir_capR4.wav");
			Dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "red_outfits2";
		break;

		case "red_outfits2":
			PlaySound("VOICE\ENGLISH\pir_capR6.wav");
			Dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "red_outfits3";
		break;

		case "red_outfits3":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "exit";
			AddDialogExitQuest("red_rolls_exchange");
		break;
	
		case "fire_cannon":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "sit", "sit4");//so he's not hiding Vane		

			Dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "fire_cannon2";
		break;

		case "fire_cannon2":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_fires_cannon2");
		break;

		case "cave_door":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box4");//so he's not hiding Vane		

			Dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "cave_door2";
		break;

		case "cave_door2":
			PlaySound("VOICE\ENGLISH\pir_capR5.wav");
			Dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "cave_door3";
		break;

		case "cave_door3":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "cave_door4";
		break;

		case "cave_door4":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "cave_door5";
		break;

		case "cave_door5":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("cave_door_done");
		break;

		case "who_took_the_coins":
			//PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
			
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "labouche");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "roberts");

			Dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
			AddDialogExitQuest("who_took_the_coins1");
		break;

		case "who_took_the_coins1":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "labouche");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "roberts");

			Dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			AddDialogExitQuest("who_took_the_coins8");
		break;

		case "who_took_the_coins2":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "stay_s11");

			Dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
			AddDialogExitQuest("who_took_the_coins13");
		break;

		case "who_took_the_coins3":
			PlaySound("VOICE\ENGLISH\Blaze_sigh.wav");
			Dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "excel_document";
		break;

		case "excel_document":
			PlaySound("VOICE\ENGLISH\pir_capR6.wav");			

			Dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "exit";
			AddDialogExitQuest("who_took_the_coins19");
		break;

		case "trade":
			LAi_QuestDelay("Vane_cross_check", 0.1);

			string	itmid;
		
			itmid = "fake_censer";
			if(CheckCharacterItem(Pchar,"fake_censer"))
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	
			}
			else
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 0.0;	
			}
		
			itmid = "fake_candelabre";
			if(CheckCharacterItem(Pchar,"fake_candelabre"))
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	
			}
			else
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 0.0;	
			}
		
			itmid = "fake_chalice";
			if(CheckCharacterItem(Pchar,"fake_chalice"))
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	
			}
			else
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 0.0;	
			}
		
			itmid = "jewelcross";
			if(CheckCharacterItem(Pchar,"jewelcross"))
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	
			}
			else
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 0.0;	
			}

			itmid = "fake_reliquary";
			if(CheckCharacterItem(Pchar,"fake_reliquary"))
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 1.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 1.25;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 1.25;	
			}
			else
			{
				NPChar.itemtrade.itemlist.items.(itmid).qty 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).price 	= 0.0;
				NPChar.itemtrade.itemlist.items.(itmid).fprice 	= 0.0;	
			}
		
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "scales":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_scales2");
		break;

		case "my_coins":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];

			if(CheckCharacterItem(Pchar,"coin1") || CheckCharacterItem(Pchar,"coin5") || CheckCharacterItem(Pchar,"coin8") 
			|| CheckCharacterItem(Pchar,"coin9") || CheckCharacterItem(Pchar,"coin11")  || CheckCharacterItem(Pchar,"coin13")
			|| CheckCharacterItem(Pchar,"coin14") || CheckCharacterItem(Pchar,"coin16") || CheckCharacterItem(Pchar,"coin4")
			|| CheckCharacterItem(Pchar,"coin4_bad"))
			{
				link.l1.go = "my_coins1";
			}
			else
			{
				link.l1.go = "exit";
				AddDialogExitQuest("Vane_no_coins");
			}			
		break;

		case "my_coins1":
			PlaySound("VOICE\ENGLISH\pir_capR9.wav");
			Dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_my_coins_returned");
		break;

		case "blue_cavern_open":
			Pchar.quest.Vane_ladder = "started";
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder3");
		break;

		case "different_tasks":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "different_tasks1";

			LAi_QuestDelay("pir_caps_hurrah", 2.0);
		break;

		case "different_tasks1":
			PlaySound("VOICE\ENGLISH\pir_capR4.wav");
			Dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder5");
		break;

		case "to_the_cavern":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder11");
		break;

		case "need_ladder":
			PlaySound("VOICE\ENGLISH\Blaze_sigh.wav");
			Dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder14");
		break;

		case "new_outfits":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder22");
		break;

		case "leave_ladder":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_ladder28");
		break;

		case "search_complex":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "search_complex1";
		break;

		case "search_complex1":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search4");
		break;

		case "Selkirk_ok":
			PlaySound("VOICE\ENGLISH\pir_capR9.wav");
			Dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search24");
		break;

		case "swim_to_galleon":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_at_port7");
		break;

		case "swim_to_galleon_&_shut_up":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_at_port9");
		break;

		case "search_farm":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_at_port20A");
		break;

		case "cannons_ready":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "cannons_ready1";
		break;

		case "cannons_ready1":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");
			Dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "cannons_ready2";
		break;

		case "cannons_ready2":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_at_corvette11");
		break;

		case "blaze_wounded":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			Dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "exit";
			AddDialogExitQuest("corvette_sniper9");
		break;

		case "galleon_search":
			PlaySound("VOICE\ENGLISH\pir_capR5.wav");
			Dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "exit";
			AddDialogExitQuest("galleon_search1");
		break;

		case "galleon_cut_loose":
			PlaySound("OBJECTS\SHIPCHARGE\gunner_warning.wav");

			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "look6");

			Dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "exit";
			AddDialogExitQuest("galleon_sinking11");
		break;

		case "take_corvette":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");

			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "look6");

			Dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "exit";
			AddDialogExitQuest("galleon_sinking26");
		break;

		case "bye_bye":
			PlaySound("VOICE\ENGLISH\pir_capR1.wav");

			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "moody");

			Dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "bye_bye1";
		break;

		case "bye_bye1":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");

			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "look7");

			Dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "bye_bye2";
		break;

		case "bye_bye2":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");

			Dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "exit";
			AddDialogExitQuest("goodbye_Vane_Pchar");
		break;

		case "bye_bye_loop":
			PlaySound("VOICE\ENGLISH\pir_capR2.wav");

			Dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "exit";
			AddDialogExitQuest("goodbye_Vane_loop");
		break;

		case "about_Richards4":
			PlaySound("VOICE\ENGLISH\pir_capR9.wav");

			Dialog.text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "about_Richards5";
		break;

		case "about_Richards5":
			PlaySound("VOICE\ENGLISH\pir_capR6.wav");

			Dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards5");
		break;

		case "about_Richards8":
			PlaySound("VOICE\ENGLISH\pir_capR12.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap18"));

			Dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards9");
		break;

		case "Rackham_sail":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap18"));
			LAi_ActorTurnToCharacter(characterFromID("pir_cap18"), NPChar);

			Dialog.text = DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion18");
		break;

		case "back_to_posts":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[163];
			link.l1 = DLG_TEXT[164];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion23");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
