//#include "DIALOGS\Woodes Rogers_dialog.h"
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

			if(CheckAttribute(Pchar,"quest.wr_quest1"))
			{
		/*
				if(Pchar.quest.wr_quest1 == "medicine_chest")
				{
					PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");
					dialog.text = DLG_TEXT[114];
					link.l1 = DLG_TEXT[115];
					link.l1.go = "exit";
					AddDialogExitQuest("dampier_hint_done");
				}
		*/
				if(Pchar.quest.wr_quest1 == "balcony_talk1")
				{
					PlaySound("VOICE\ENGLISH\gr_WR_offer1.wav");
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
					Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH1";
					AddDialogExitQuest("WR_wait_soon1");
				}

				if(Pchar.quest.wr_quest1 == "balcony_talk2")
				{
					PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
					AddDialogExitQuest("WR_gone_soon2");
				}

				if(Pchar.quest.wr_quest1 == "balcony_talk3")
				{
					PlaySound("VOICE\ENGLISH\gr_WR_neutr.wav");
					Pchar.quest.wr_quest1 = "dont_repeat_talk3";		//repeat is off
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "Exit";
					AddDialogExitQuest("WR_after_dialog3");
				}

				if(Pchar.quest.wr_quest1 == "no_balcony_talk")
				{
					//don't talk please
				}

				if(Pchar.quest.wr_quest1 == "just_greeting")
				{
					PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");
					dialog.text = DLG_TEXT[134];
					link.l1 = DLG_TEXT[135];
					link.l1.go = "Exit";
				}
			}
			else
			{
				int greeting = rand(2);
				switch (greeting)
				{
					case 0:
						PlaySound("VOICE\ENGLISH\gr_WR_host1.wav");
					break;

					case 1:
						PlaySound("VOICE\ENGLISH\gr_WR_host2.wav");
					break;

					case 2:
						PlaySound("VOICE\ENGLISH\gr_WR_host3.wav");
					break;
				}
					
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "Exit";
			}
		break;
//---------------------------------------------------------------------------------------------
		case "Dampier_hint":
			PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "exit";
			AddDialogExitQuest("dampier_hint_done");
		break;

		case "balcony_talk1A":
			PlaySound("VOICE\ENGLISH\gr_WR_friend4.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "balcony_talk1B";
		break;

		case "balcony_talk1B":
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "balcony_talk1C";
		break;

		case "balcony_talk1C":
			PlaySound("VOICE\ENGLISH\gr_WR_friend5.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "balcony_talk1D";
		break;

		case "balcony_talk1D":
			PlaySound("VOICE\ENGLISH\gr_WR_offer2.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "balcony_talk1E";
		break;

		case "balcony_talk1E":
		//	PlaySound("VOICE\ENGLISH\gr_WR_offer1.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "balcony_talk1F";
		break;

		case "balcony_talk1F":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "balcony_talk1G";
		break;

		case "balcony_talk1G":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "balcony_talk1H";
		break;

		case "balcony_talk1H":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "balcony_talk1J";
		break;

		case "balcony_talk1J":
			PlaySound("VOICE\ENGLISH\gr_WR_host4.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "balcony_talk1K";
		break;

		case "balcony_talk1K":
			PlaySound("VOICE\ENGLISH\gr_WR_offer3.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "balcony_talk1L";
		break;

		case "balcony_talk1L":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "balcony_talk1M";
		break;

		case "balcony_talk1M":
			PlaySound("VOICE\ENGLISH\gr_WR_offer4.wav");	
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "balcony_talk1N";
		break;

		case "balcony_talk1N":
			PlaySound("VOICE\ENGLISH\gr_WR_friend5.wav");
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "balcony_talk1O";
		break;

		case "balcony_talk1O":
			PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");	
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("balcony_talk1_over");
		break;

		case "balcony_talk2A":
			PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");			
			dialog.text = DLG_TEXT[6];							
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
			AddDialogExitQuest("balcony_talk2_over");
		break;

		case "back_in_redmond":
			PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");		
			dialog.text = DLG_TEXT[34];							
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
			AddDialogExitQuest("back_in_redmond8");
		break;

		case "mission1":
			PlaySound("VOICE\ENGLISH\gr_WR_offer2.wav");			
			dialog.text = DLG_TEXT[36];							
			link.l1 = DLG_TEXT[37];
			link.l1.go = "mission1_A";
		break;

		case "mission1_A":
			dialog.text = DLG_TEXT[38];							
			link.l1 = DLG_TEXT[39];
			link.l1.go = "mission1_B";
		break;

		case "mission1_B":
			dialog.text = DLG_TEXT[40];							
			link.l1 = DLG_TEXT[41];
			link.l1.go = "mission1_C";
		break;

		case "mission1_C":
			PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");			
			dialog.text = DLG_TEXT[42];							
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("mission1_given");
		break;

		case "piece_of_land":
			Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH2";//window F3 visible & open
			Locations[FindLocation("wr_residence")].reload.l3.disable = 0;//window now open
			Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
			Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
			locations[FindLocation("wr_library")].type = "Rogers_repair_residence";
			locations[FindLocation("Tavern_storeroom")].type = "repair_house";
			Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH3";//with planks

			PlaySound("VOICE\ENGLISH\gr_WR_offer3.wav");
			dialog.text = DLG_TEXT[44];							
			link.l1 = DLG_TEXT[45];
			link.l1.go = "piece_of_land2";
		break;

		case "piece_of_land2":
			dialog.text = DLG_TEXT[46];							
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("piece_of_land");
		break;

		case "mission2":
			PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");			
			dialog.text = DLG_TEXT[48];							
			link.l1 = DLG_TEXT[49];
			link.l1.go = "mission2_A";
		break;

		case "mission2_A":
			dialog.text = DLG_TEXT[50];							
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("mission2_given");
		break;
//pдr
		case "terrace":
			PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");
			dialog.text = DLG_TEXT[52];							
			link.l1 = DLG_TEXT[53];
			link.l1.go = "terrace_A";
		break;

		case "terrace_A":
			dialog.text = DLG_TEXT[54];							
			link.l1 = DLG_TEXT[55];
			link.l1.go = "terrace_B";
		break;

		case "terrace_B":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			dialog.text = DLG_TEXT[56];							
			link.l1 = DLG_TEXT[57];
			link.l1.go = "terrace_C";
		break;

		case "terrace_C":
			dialog.text = DLG_TEXT[58];							
			link.l1 = DLG_TEXT[59];
			if(CheckCharacterItem(Pchar,"bladepickaxe1"))
			{
				link.l1.go = "exit";
				AddDialogExitQuest("terrace_dialog");
			}
			else
			{
				link.l1.go = "terrace_D";
			}
		break;

		case "terrace_D":
			PlaySound("VOICE\ENGLISH\gr_WR_friend4.wav");
			dialog.text = DLG_TEXT[140];							
			link.l1 = DLG_TEXT[141];
			link.l1.go = "exit";
			AddDialogExitQuest("terrace_dialog");

			
		break;

		case "mission4":
			PlaySound("VOICE\ENGLISH\gr_WR_friend4.wav");
			dialog.text = DLG_TEXT[60];							
			link.l1 = DLG_TEXT[61];
			link.l1.go = "mission4_A";
		break;

		case "mission4_A":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			dialog.text = DLG_TEXT[62];							
			link.l1 = DLG_TEXT[63];
			link.l1.go = "mission4_B";
		break;

		case "mission4_B":
			PlaySound("VOICE\ENGLISH\gr_WR_friend5.wav");
			dialog.text = DLG_TEXT[64];							
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("mission4_given");
		break;

		case "gunroom":
			PlaySound("VOICE\ENGLISH\gr_WR_friend1.wav");
			dialog.text = DLG_TEXT[66];							
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("wr_gunroom_done");
		break;

		case "molasses":
			PlaySound("VOICE\ENGLISH\gr_WR_friend2.wav");
			dialog.text = DLG_TEXT[68];							
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("book25_check");
		break;

		case "3more_books":
			PlaySound("VOICE\ENGLISH\gr_WR_offer3.wav");
			TakeItemFromCharacter(Pchar, "book31");
			dialog.text = DLG_TEXT[70];							
			link.l1 = DLG_TEXT[71];
			link.l1.go = "3more_books1";
		break;

		case "3more_books1":
			dialog.text = DLG_TEXT[72];							
			link.l1 = DLG_TEXT[73];
			link.l1.go = "3more_books2";
		break;

		case "3more_books2":
			dialog.text = DLG_TEXT[74];							
			link.l1 = DLG_TEXT[75];
			link.l1.go = "3more_books3";
		break;

		case "3more_books3":
			dialog.text = DLG_TEXT[76];							
			link.l1 = DLG_TEXT[77];
			link.l1.go = "3more_books4";
		break;

		case "3more_books4":
			dialog.text = DLG_TEXT[78];							
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
			AddDialogExitQuest("3more_books_done");
		break;

		case "mission5":
			PlaySound("VOICE\ENGLISH\gr_WR_offer4.wav");
			TakeItemFromCharacter(Pchar, "book24");
			dialog.text = DLG_TEXT[80];							
			link.l1 = DLG_TEXT[81];
			link.l1.go = "mission5_A";
		break;

		case "mission5_A":
			dialog.text = DLG_TEXT[82];							
			link.l1 = DLG_TEXT[83];
			link.l1.go = "mission5_B";
		break;

		case "mission5_B":
			dialog.text = DLG_TEXT[84];							
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			AddDialogExitQuest("mission5_given");
		break;

		case "mission6":
			PlaySound("VOICE\ENGLISH\gr_WR_offer2.wav");
			dialog.text = DLG_TEXT[86];							
			link.l1 = DLG_TEXT[87];
			link.l1.go = "mission6_A";
		break;

		case "mission6_A":
			dialog.text = DLG_TEXT[88];							
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit";
			AddDialogExitQuest("mission6_given");
		break;
	
		case "terrace_04":
			PlaySound("VOICE\ENGLISH\gr_WR_offer3.wav");
			dialog.text = DLG_TEXT[90];							
			link.l1 = DLG_TEXT[91];
			link.l1.go = "terrace_04_A";
		break;

		case "terrace_04_A":
			dialog.text = DLG_TEXT[92];							
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
			AddDialogExitQuest("get_drunk");	
		break;

		case "unlock_cell":
			dialog.text = DLG_TEXT[94];							
			link.l1 = DLG_TEXT[95];
			link.l1.go = "exit";
			AddDialogExitQuest("cell_door_is_opened");
		break;

		case "getting_angry":
			PlaySound("VOICE\ENGLISH\gr_WR_host4.wav");
			dialog.text = DLG_TEXT[96];							
			link.l1 = DLG_TEXT[97];
			link.l1.go = "getting_angry1";
		break;

		case "getting_angry1":
			PlaySound("VOICE\ENGLISH\gr_WR_host5.wav");
			dialog.text = DLG_TEXT[98];							
			link.l1 = DLG_TEXT[99];
			link.l1.go = "getting_angry2";
		break;

		case "getting_angry2":
			PlaySound("VOICE\ENGLISH\gr_WR_host6.wav");
			dialog.text = DLG_TEXT[100];							
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
			AddDialogExitQuest("angry_and_gone");
		break;

		case "medicine_quest":
			PlaySound("VOICE\ENGLISH\gr_WR_host7.wav");
			dialog.text = DLG_TEXT[102];							
			link.l1 = DLG_TEXT[103];
			link.l1.go = "medicine_quest1";
		break;
		
		case "medicine_quest1":
			dialog.text = DLG_TEXT[104];							
			link.l1 = DLG_TEXT[105];
			link.l1.go = "medicine_quest2";
		break;

		case "medicine_quest2":
			dialog.text = DLG_TEXT[106];							
			link.l1 = DLG_TEXT[107];
			link.l1.go = "medicine_quest3";
		break;

		case "medicine_quest3":
			GiveItem2Character(Pchar, "medicine_list");
			dialog.text = DLG_TEXT[108];							
			link.l1 = DLG_TEXT[109];
			link.l1.go = "medicine_quest4";
		break;

		case "medicine_quest4":
			PlaySound("VOICE\ENGLISH\gr_WR_friend5.wav");
			dialog.text = DLG_TEXT[110];							
			link.l1 = DLG_TEXT[111];
			link.l1.go = "medicine_quest5";
		break;

		case "medicine_quest5":
			dialog.text = DLG_TEXT[112];							
			link.l1 = DLG_TEXT[113];
			link.l1.go = "exit";
			AddDialogExitQuest("medicine_quest_given");
		break;

		case "attack_carpenter":
			PlaySound("VOICE\ENGLISH\gr_WR_host6.wav");
			LAi_SetActorType(CharacterFromID("Woodes Rogers"));
			LAi_ActorRunToLocator(characterFromID("Woodes Rogers"), "goto", "goto6", "", 2.0);
			dialog.text = DLG_TEXT[116];							
			link.l1 = DLG_TEXT[117];
			link.l1.go = "exit";
			AddDialogExitQuest("attack_carpenter");
		break;

		case "ready_for_Vane_yet":
			PlaySound("VOICE\ENGLISH\gr_WR_offer1.wav");
			dialog.text = DLG_TEXT[118];			
			link.l1 = DLG_TEXT[119];
			link.l1.go = "ready_for_Vane_yet1";
		break;

		case "ready_for_Vane_yet1":
			PlaySound("VOICE\ENGLISH\gr_WR_friend4.wav");
			if(CheckCharacterItem(Pchar,"bladesurgcan3_r") && CheckCharacterItem(Pchar,"leeches") && CheckCharacterItem(Pchar,"prescriptions") && CheckCharacterItem(Pchar,"rolls_of_bandages"))
			{
				dialog.text = DLG_TEXT[120];
				link.l1 = DLG_TEXT[122];
				link.l1.go = "ready_for_Vane_yet2";
			}
			else
			{
				dialog.text = DLG_TEXT[121];
				link.l1 = DLG_TEXT[122];
				link.l1.go = "ready_for_Vane_yet2";
				link.l2 = DLG_TEXT[123];
				link.l2.go = "collect_more_drugs";
			}			
		break;

		case "ready_for_Vane_yet2":
			PlaySound("VOICE\ENGLISH\gr_WR_friend3.wav");
			dialog.text = DLG_TEXT[124];			
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
			AddDialogExitQuest("info_last_reward");
			AddDialogExitQuest("teleport_to_tartane");
		break;

		case "collect_more_drugs":
			Pchar.quest.wr_quest1 = "just_greeting";
			PlaySound("VOICE\ENGLISH\gr_WR_friend3.wav");
			dialog.text = DLG_TEXT[124];			
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
			AddDialogExitQuest("info_last_reward");
			AddDialogExitQuest("collect_more_drugs");
		break;

		case "Spotswood_talk":
			PlaySound("VOICE\ENGLISH\gr_WR_friend4.wav");
			dialog.text = DLG_TEXT[126];			
			link.l1 = DLG_TEXT[127];
			link.l1.go = "Spotswood_talk1";
		break;

		case "Spotswood_talk1":
			dialog.text = DLG_TEXT[128];			
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Spotswood_talk2";
		break;

		case "Spotswood_talk2":
			PlaySound("VOICE\ENGLISH\gr_WR_offer2.wav");
			dialog.text = DLG_TEXT[130];			
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";
			AddDialogExitQuest("Spotswood_talk_done");
		break;

		case "officers_no_problems":
			PlaySound("VOICE\ENGLISH\gr_WR_host4.wav");
			dialog.text = DLG_TEXT[132];			
			link.l1 = DLG_TEXT[133];
			link.l1.go = "exit";
			AddDialogExitQuest("officers_no_problems_done");
		break;
	
		case "Exit":
			Pchar.quest.wr_quest1 = "just_greeting";//repeat is off
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
