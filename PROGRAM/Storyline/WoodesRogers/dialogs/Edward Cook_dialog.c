//#include "DIALOGS\Edward Cook_dialog.h"
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



			if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
			{
				switch(Pchar.quest.med_Cook)
				{
					case "no_chest":
						PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
						Pchar.quest.med_Selkirk = "friday_hint";
						
						Dialog.text = DLG_TEXT[42];
						link.l1 = DLG_TEXT[43];
						link.l1.go = "exit";
					break;
			
					case "chest":
						PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
						Pchar.quest.med_Selkirk = "friday_medicine";
						Pchar.quest.med_Friday = "medicine";
						Pchar.quest.med_Cook = "food_mission";

						if(CheckCharacterItem(Pchar,"pistolmdchest_F1"))
						{
							if(IsEquipCharacterByItem(Pchar, "pistolmdchest_F1"))
							{
								
							}
							else
							{
								RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
								EquipcharacterByItem(Pchar, "pistolmdchest_F1");
							}

							Dialog.text = DLG_TEXT[36];
							link.l1 = DLG_TEXT[37];
							link.l1.go = "food_mission";
						}

						if(CheckCharacterItem(Pchar,"pistolmdchest_F1_C"))
						{
							if(IsEquipCharacterByItem(Pchar, "pistolmdchest_F1_C"))
							{
								
							}
							else
							{
								RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
								EquipcharacterByItem(Pchar, "pistolmdchest_F1_C");
							}

							Dialog.text = DLG_TEXT[36];
							link.l1 = DLG_TEXT[37];
							link.l1.go = "food_mission";
						}
					break;
			
					case "food_mission":
						if(CheckCharacterItem(Pchar,"pistolfoodchest2") && CheckCharacterItem(Pchar,"2winebottles") 
							&& CheckCharacterItem(Pchar,"meat") && CheckCharacterItem(Pchar,"bread") 
							&& CheckCharacterItem(Pchar,"ale") && CheckCharacterItem(Pchar,"bladefish"))
						{
							PlaySound("VOICE\ENGLISH\Eng_m_c_012.wav");
							Pchar.quest.med_Cook = "long_queue";
							Dialog.text = DLG_TEXT[46];
							link.l1 = DLG_TEXT[47];
							link.l1.go = "food_delivery";
						}
						else
						{
							PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
							if(CheckAttribute(Pchar,"quest.med_Cook2") && Pchar.quest.med_Cook2 == "food_mission_given")
							{
								Dialog.text = DLG_TEXT[44];
								link.l1 = DLG_TEXT[45];
								link.l1.go = "exit";
							}
							else
							{
								Pchar.quest.med_Cook2 = "food_mission_given";
								Dialog.text = DLG_TEXT[44];
								link.l1 = DLG_TEXT[45];
								link.l1.go = "exit";
								AddDialogExitQuest("return_to_port1");
							}
						}
					break;
				
					case "collection":
						PlaySound("VOICE\ENGLISH\Eng_m_c_021.wav");
						Dialog.text = DLG_TEXT[50];
						link.l1 = DLG_TEXT[51];
						link.l1.go = "exit";
						AddDialogExitQuest("collection_picked_up");
					break;
				

					case "long_queue":
						PlaySound("VOICE\ENGLISH\Eng_m_c_040.wav");
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					break;

					//default:
					PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";

		 			return;
				}
				return;
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
	
			Diag.TempNode = "first time";
		break;

		case "fire_kits":
			PlaySound("VOICE\ENGLISH\Eng_m_c_009.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "fire_kits1";
		break;

		case "fire_kits1":
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("hint_fire_kits4");
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "bladetalk":
			Pchar.quest.wr_bladeA17 = "0";
			Pchar.quest.wr_bladeA4 = "0";
			Pchar.quest.wr_bladeA5 = "0";
			Pchar.quest.wr_bladeA2 = "0";
			PChar.not_that_blade = 0;
	
			PlaySound("VOICE\ENGLISH\Eng_m_c_039.wav");

			if (WEAPONSLOCKER == 1)
			{
				Dialog.text = DLG_TEXT[7];
			}
			else Dialog.text = DLG_TEXT[52];
		
			link.l1 = DLG_TEXT[8];
			link.l1.go = "bladetalk2";
		break;
	
		case "bladetalk2":
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			Diag.TempNode = "choose_blade";
			AddDialogExitQuest("bladetalk_over");	//in here fill weaponslocker
		break;
	
		case "choose_blade":
			if(CheckCharacterItem(Pchar,"bladeA17") || CheckCharacterItem(Pchar,"bladeA5") || CheckCharacterItem(Pchar,"bladeA11")
			|| CheckCharacterItem(Pchar,"bladeA4") || CheckCharacterItem(Pchar,"bladeA2")) 
			{
				Dialog.text = DLG_TEXT[53];
				link.l1.go = "exit";
				return;
			}

			Dialog.text = DLG_TEXT[11];
			if(CheckAttribute(Pchar,"quest.wr_bladeA17") && Pchar.quest.wr_bladeA17 == "0")
			{
				link.l1 = DLG_TEXT[12];
				link.l1.go = "try_blade1";
			}
			if(CheckAttribute(Pchar,"quest.wr_bladeA4") && Pchar.quest.wr_bladeA4 == "0")
			{
				link.l2 = DLG_TEXT[13];
				link.l2.go = "try_blade2";
			}
			link.l3 = DLG_TEXT[14];
			link.l3.go = "try_blade3";
			if(CheckAttribute(Pchar,"quest.wr_bladeA5") && Pchar.quest.wr_bladeA5 == "0")
			{
				link.l4 = DLG_TEXT[15];
				link.l4.go = "try_blade4";
			}
			if(CheckAttribute(Pchar,"quest.wr_bladeA2") && Pchar.quest.wr_bladeA2 == "0")
			{
				link.l5 = DLG_TEXT[16];
				link.l5.go = "try_blade5";
			}
		break;

		case "try_blade1":
			LAi_SetStayType(Pchar);
			Dialog.text = DLG_TEXT[17];		//long saber
			link.l1 = DLG_TEXT[18];				//I'll try it
			link.l1.go = "exit";	
			AddDialogExitQuest("try_blade1");		//bladeA17
		break;

		case "try_blade2":
			LAi_SetStayType(Pchar);
			Dialog.text = DLG_TEXT[23];		//cutlass
			link.l1 = DLG_TEXT[18];				//I'll try it
			link.l1.go = "exit";	
			AddDialogExitQuest("try_blade2");		//bladeA5
		break;

		case "try_blade3":
			LAi_SetStayType(Pchar);
			Dialog.text = DLG_TEXT[29];		//black rapier - the one you'll get!
			link.l1 = DLG_TEXT[18];				//I'll try it
			link.l1.go = "exit";	
			AddDialogExitQuest("try_blade3");		//bladeA11
		break;

		case "try_blade4":
			LAi_SetStayType(Pchar);
			Dialog.text = DLG_TEXT[25];		//red/yellow rapier
			link.l1 = DLG_TEXT[18];				//I'll try it
			link.l1.go = "exit";	
			AddDialogExitQuest("try_blade4");		//bladeA4
		break;

		case "try_blade5":
			LAi_SetStayType(Pchar);
			Dialog.text = DLG_TEXT[27];		//rapier with a cup
			link.l1 = DLG_TEXT[18];				//I'll try it
			link.l1.go = "exit";	
			AddDialogExitQuest("try_blade5");		//bladeA2
		break;

		case "decide_blade":
			PlaySound("VOICE\ENGLISH\Eng_m_c_012.wav");
			Dialog.text = DLG_TEXT[19];		//try another?
			link.l1 = DLG_TEXT[20];				//keep it

			if(CheckCharacterItem(Pchar,"bladeA17")) link.l1.go = "decide_blade1";
			if(CheckCharacterItem(Pchar,"bladeA5")) link.l1.go = "decide_blade2";
			if(CheckCharacterItem(Pchar,"bladeA11")) link.l1.go = "decide_blade3";
			if(CheckCharacterItem(Pchar,"bladeA4")) link.l1.go = "decide_blade4";
			if(CheckCharacterItem(Pchar,"bladeA2")) link.l1.go = "decide_blade5";
			
			if(CheckAttribute(Pchar,"not_that_blade") && Pchar.not_that_blade <= 3)
			{
				link.l2 = DLG_TEXT[21];				//look at other blades
				link.l2.go = "exit_wrong_blade";
			}
		break;

		case "decide_blade1":
			Pchar.quest.wr_bladeA17 = "1";
			PChar.not_that_blade = sti(PChar.not_that_blade) + 1;

			PlaySound("VOICE\ENGLISH\Eng_m_c_060.wav");
			Dialog.text = DLG_TEXT[22];		//my own blade
			link.l1 = DLG_TEXT[10];				//I'll pick a blade
			link.l1.go = "exit";
			AddDialogExitQuest("bladetalk_over");		
		break;

		case "decide_blade2":
			Pchar.quest.wr_bladeA4 = "1";
			PChar.not_that_blade = sti(PChar.not_that_blade) + 1;

			Dialog.text = DLG_TEXT[24];		//cutlass damaged
			link.l1 = DLG_TEXT[10];				//I'll pick a blade
			link.l1.go = "exit";
			AddDialogExitQuest("bladetalk_over");		
		break;

		case "decide_blade3":
			Dialog.text = DLG_TEXT[30];		//take the black rapier
			link.l1 = DLG_TEXT[31];				//I'll pick a blade - ?????
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("bladetalk_finished");		
		break;

		case "decide_blade4":
			Pchar.quest.wr_bladeA5 = "1";
			PChar.not_that_blade = sti(PChar.not_that_blade) + 1;

			Dialog.text = DLG_TEXT[26];		//red rapiers are finished
			link.l1 = DLG_TEXT[10];				//I'll pick a blade
			link.l1.go = "exit";
			AddDialogExitQuest("bladetalk_over");		
		break;

		case "decide_blade5":
			Pchar.quest.wr_bladeA2 = "1";
			PChar.not_that_blade = sti(PChar.not_that_blade) + 1;

			Dialog.text = DLG_TEXT[28];		//cup rapier for Cpt Johnson
			link.l1 = DLG_TEXT[10];				//I'll pick a blade
			link.l1.go = "exit";
			AddDialogExitQuest("bladetalk_over");		
		break;

		case "food_mission":
			PlaySound("VOICE\ENGLISH\Eng_m_c_012.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "food_mission1";
		break;

		case "food_mission1":
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("food_mission_given");
		break;

		case "food_delivery":
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("food_delivered");
		break;
	
		case "Exit_wrong_blade":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("bladetalk_over");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
