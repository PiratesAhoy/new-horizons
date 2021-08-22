//#include "DIALOGS\Daniel Defoe_dialog.h"
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

		if(CheckAttribute(Pchar,"quest.defoes_cabin") && Pchar.quest.defoes_cabin == "talk_over")
		{
			PlaySound("VOICE\ENGLISH\defoe_again.wav");	
			NPChar.dlgover = true;
			Diag.TempNode = "First time";
			DialogExit();
		}
		else
		{

			if (pchar.location == "wr_chapel")
			{
				PlaySound("VOICE\ENGLISH\defoe_meet.wav");
				Dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "exit";
			}
			else
			{
				if(pchar.location == "wr_animists")
				{
					if(CheckAttribute(Pchar,"quest.prisoner_Silehard") && Pchar.quest.prisoner_Silehard == "gone") 
					{
						if(CheckAttribute(Pchar,"quest.mine_bomb2") && Pchar.quest.mine_bomb2 == "placed") 
						{
							if(CheckAttribute(Pchar,"quest.Defoe_sledge") && Pchar.quest.Defoe_sledge == "no") 
							{
								PlaySound("VOICE\ENGLISH\defoe_sorry.wav");
								Dialog.text = DLG_TEXT[14];
								link.l1 = DLG_TEXT[15];
								link.l1.go = "stay_in_prison";
							}
							else
							{
								Pchar.quest.Defoe_sledge = "no";
								LAi_SetStayType(NPChar);
								ChangeCharacterAddressGroup(NPchar, "wr_animists", "goto", "staybed");
								LAi_SetActorType(NPChar);
								LAi_ActorTurnToCharacter(NPchar, Pchar);
								LAi_SetActorType(PChar);
								LAi_ActorTurnToCharacter(Pchar, NPchar);

								PlaySound("VOICE\ENGLISH\defoe_psst.wav");
								Dialog.text = DLG_TEXT[24];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
								AddDialogExitQuest("Defoe_sledge");
							}
						}
						else
						{
							PlaySound("VOICE\ENGLISH\defoe_sorry.wav");
							Dialog.text = DLG_TEXT[14];
							link.l1 = DLG_TEXT[15];
							link.l1.go = "stay_in_prison";
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\defoe_sorry.wav");
						Dialog.text = DLG_TEXT[14];
						link.l1 = DLG_TEXT[15];
						link.l1.go = "stay_in_prison";
					}
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\defoe_meet.wav");
				Dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		}
		break;

		case "start":
			PlaySound("VOICE\ENGLISH\defoe_welcome.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("gunroom_Rogers");
		break;

		case "rum":
			PlaySound("VOICE\ENGLISH\defoe_feast.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("rum_check");
		break;
	
		case "rum_check":
			if(CheckAttribute(Pchar,"quest.molasses_check") && Pchar.quest.molasses_check == 1)
			{
				PlaySound("VOICE\ENGLISH\defoe_sorry.wav");
				Pchar.quest.wr_defoe = "incognito";
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
				ChangeCharacterAddressGroup(Pchar, "wr_gunroom", "goto", "goto9");
				AddDialogExitQuest("Rogers_molasses");
			}
			else
			{
				PlaySound("VOICE\ENGLISH\defoe_psst.wav");
				Dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				ChangeCharacterAddressGroup(Pchar, "wr_gunroom", "goto", "goto9");
				AddDialogExitQuest("rum_check");
			}
		break;

		case "light_fire":
			PlaySound("VOICE\ENGLISH\defoe_meet.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("light_fire");
		break;

		case "get_some_wood":
			PlaySound("VOICE\ENGLISH\defoe_again.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("light_fire");
		break;

		case "wheel_check":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
				Dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				AddDialogExitQuest("wheel_check");
		break;

		case "incognito":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "stay_in_prison":
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
		break;

		case "food_talk":
			PlaySound("VOICE\ENGLISH\defoe_leave.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "food_talk1";
		break;

		case "food_talk1":
			PlaySound("VOICE\ENGLISH\defoe_hero.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "food_talk2";
		break;

		case "food_talk2":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Defoe_food_talk_done");
		break;

		case "visit_before":
			PlaySound("VOICE\ENGLISH\defoe_welcome.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "visit_before1";
		break;

		case "visit_before1":
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe3");
		break;

		case "book_thief":
			PlaySound("VOICE\ENGLISH\defoe_work.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe5");
		break;

		case "woodes_rogers":
			PlaySound("VOICE\ENGLISH\defoe_meet.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "woodes_rogers1";
		break;

		case "woodes_rogers1":
			PlaySound("VOICE\ENGLISH\defoe_deal.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "woodes_rogers2";
		break;

		case "woodes_rogers2":
			PlaySound("VOICE\ENGLISH\defoe_work.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe10");
		break;

		case "warning":
			PlaySound("VOICE\ENGLISH\defoe_again.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe13");
		break;

		case "open_shipyard":
			PlaySound("VOICE\ENGLISH\defoe_hero.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "open_shipyard1";
		break;

		case "open_shipyard1":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "open_shipyard2";
		break;

		case "open_shipyard2":
			PlaySound("VOICE\ENGLISH\defoe_work.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port2");
		break;

		case "shipyard_key":
			PlaySound("INTERFACE\took_item.wav");
			LAi_SetActorType(CharacterFromID("Defoe"));
			LAi_ActorTurnToCharacter(characterFromID("Defoe"), characterFromID("Claire Voyant"));
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port10");
		break;

		case "ironic_key":
			PlaySound("VOICE\ENGLISH\defoe_sorry.wav");
			LAi_SetActorType(CharacterFromID("Defoe"));
			LAi_ActorTurnToCharacter(characterFromID("Defoe"), characterFromID("Claire Voyant"));
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port12");
		break;

		case "Hgold_story":
			PlaySound("VOICE\ENGLISH\defoe_feast.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map15");
		break;

		case "Bellamys_story":
			PlaySound("VOICE\ENGLISH\defoe_meet.wav");
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Bellamys_story1";
		break;

		case "Bellamys_story1":
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore");
		break;

		case "Spotswood_Maynard":
			PlaySound("VOICE\ENGLISH\defoe_work.wav");
			Dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map23");
		break;

		case "sloop3":
			PlaySound("VOICE\ENGLISH\defoe_work.wav");
			Dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop4");
		break;

		case "sloop5":
			PlaySound("VOICE\ENGLISH\defoe_deal.wav");
			Dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop6");
		break;

		case "sloop7":
			PlaySound("VOICE\ENGLISH\defoe_leave.wav");
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop8");
		break;

		case "sloop9":
			PlaySound("VOICE\ENGLISH\defoe_again.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop10");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
