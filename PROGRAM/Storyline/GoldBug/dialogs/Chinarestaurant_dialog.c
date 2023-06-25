//#include "DIALOGS\Redmond Soldier_dialog.h"
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
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			

			PlaySound("VOICE\ENGLISH\chinese_chatting.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "GP_standard":
			PlaySound("VOICE\ENGLISH\chinese_chatting.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "GP_standard_1";
		break;

		case "GP_standard_1":
			PlaySound("VOICE\ENGLISH\chinese_sorry.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "GP_standard_2";
		break;

		case "GP_standard_2":
			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("we_do_the_job");
		break;

		case "GP_standard_3":
			PlaySound("VOICE\ENGLISH\chinese_need.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "GP_standard_4";
		break;

		case "GP_standard_4":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("we_do_the_job_yes");
		break;

		case "GP_standard_5":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "GP_standard_6";
		break;
	
		case "GP_standard_6":
			PlaySound("VOICE\ENGLISH\chinese_need.wav");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("go_to_the_mill");
		break;
	//--------------------------------------------------------------------
		case "GP_standard_7":
			AddQuestRecord("Gunpowder","4");
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "GP_standard_8";
		break;
		
		case "GP_standard_8":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("go_to_the_mill2");
		break;
	//--------------------------------------------------------------------
		case "GP_standard_1_produced":
			//pchar has produced both "bladebarrel_gpS" and "pistolbarrel_gpS"

			if(!IsEquipCharacterByItem(Pchar, "bladebarrel_gpS"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladebarrel_gpS");
			}

			if(!IsEquipCharacterByItem(Pchar, "pistolbarrel_gpS"))
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "pistolbarrel_gpS");
			}

			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "key27";
		break;

		case "key27":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolbarrel_gpS" );
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebarrel_gpS" );

			GiveItem2Character(characterFromID("the_chinese"), "bladebarrel_gpS");
			EquipCharacterByItem(characterFromID("the_chinese"), "bladebarrel_gpS");
			GiveItem2Character(characterFromID("the_chinese"), "pistolbarrel_gpS");
			EquipCharacterByItem(characterFromID("the_chinese"), "pistolbarrel_gpS");

			PlaySound("VOICE\ENGLISH\chinese_sorry.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("key27_done");
		break;
	//------------------------------------------------------------------------------------------------
		case "GP_standard_2_produced":
			//pchar has produced both "bladebarrel_gpS" and "pistolbarrel_gpS"

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolbarrel_gpS" );
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebarrel_gpS" );

			GiveItem2Character(characterFromID("the_chinese"), "bladebarrel_gpS");
			EquipCharacterByItem(characterFromID("the_chinese"), "bladebarrel_gpS");
			GiveItem2Character(characterFromID("the_chinese"), "pistolbarrel_gpS");
			EquipCharacterByItem(characterFromID("the_chinese"), "pistolbarrel_gpS");

			DeleteQuestHeader("Gunpowder");

			PlaySound("VOICE\ENGLISH\chinese_chatting.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "GP_standard_2_produced_A";
		break;
	
		case "GP_standard_2_produced_A":
			PlaySound("PEOPLE\gunpowder.wav");
			TakenItems(Pchar, "gunpowder", 6);
			TakenItems(characterFromID("Jupiter"), "gunpowder", 6);
			Pchar.quest.Legrands_gunpowder = "6";
			Pchar.quest.Jupiter_gunpowder = "6";

			PlaySound("VOICE\ENGLISH\chinese_sorry.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "GP_standard_2_produced_B";
		break;

		case "GP_standard_2_produced_B":
			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];

			if(CheckCharacterItem(Pchar,"doc2A") || CheckCharacterItem(Pchar,"doc2B") || CheckCharacterItem(Pchar,"doc2C") || CheckCharacterItem(Pchar,"doc2D"))
			{
				link.l1.go = "GP_standard_2_produced_C";
			}
			else link.l1.go = "red_folder";
		break;
	//-----------------------------------------------------------------------
		case "red_folder":
			PlaySound("VOICE\ENGLISH\chinese_sorry.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("search_red_folder");
		break;

		case "found_red_folder":
			PlaySound("INTERFACE\paper.wav");
			PlaySound("VOICE\ENGLISH\chinese_need.wav");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "GP_standard_2_produced_D";
		break;
	//-----------------------------------------------------------------------
		case "GP_standard_2_produced_C":
			PlaySound("INTERFACE\paper.wav");
			PlaySound("VOICE\ENGLISH\chinese_need.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "GP_standard_2_produced_D";
		break;

		case "GP_standard_2_produced_D":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("gp_standard_2_done");
		break;
	//------------------------------------------------------------------------------------------------

		case "search_restaurant":
			PlaySound("VOICE\ENGLISH\chinese_chatting.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "search_restaurant1";
		break;

		case "search_restaurant1":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("search_restaurant_done");
		break;
	//-------------------------------------------------------------------------------------------------
		case "GP_fireworks":
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolbarrel_gpF" );
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebarrel_gpF" );

			GiveItem2Character(NPchar, "bladebarrel_gpF");
			EquipCharacterByItem(NPchar, "bladebarrel_gpF");
			GiveItem2Character(NPchar, "pistolbarrel_gpF");
			EquipCharacterByItem(NPchar, "pistolbarrel_gpF");

			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "GP_fireworks1";
		break;
			
		case "GP_fireworks1":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("GP_fireworks_done");
		break;

		case "in_fireworks_lab":
			PlaySound("VOICE\ENGLISH\chinese_look_around.wav");
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_done");
		break;

		case "in_fireworks_lab_gp":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "randitem", "randitem13");
			PlaySound("VOICE\ENGLISH\chinese_need.wav");
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_gp_done");
		break;

		case "in_fireworks_lab_paper":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "chinese2");
			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_paper_done");
		break;

		case "in_fireworks_lab_glue":
			PlaySound("VOICE\ENGLISH\chinese_sorry.wav");
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_glue_done");
		break;

		case "in_fireworks_lab_rockets":
			PlaySound("VOICE\ENGLISH\chinese_chatting.wav");
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_rockets_done");
		break;

		case "in_fireworks_return_stuff":
			PlaySound("VOICE\ENGLISH\chinese_samples.wav");
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			AddDialogExitQuest("in_fireworks_lab_return_stuff_done");
		break;
	}
}
