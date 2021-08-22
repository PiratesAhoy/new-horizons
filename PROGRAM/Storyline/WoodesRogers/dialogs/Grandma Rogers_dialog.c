//#include "DIALOGS\Grandma Rogers_dialog.h"
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
				

			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty == 3)
			{
				PlaySound("VOICE\ENGLISH\grandma_7.wav");	
				Dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "map";

				Diag.TempNode = "first time";
				return;
			}

			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				PlaySound("VOICE\ENGLISH\grandma_7.wav");	
				Dialog.text = DLG_TEXT[39];
				
				link.l0 = DLG_TEXT[61];
				link.l0.go = "exit_sit";

				if(CheckAttribute(Pchar,"quest.booty_money") && Pchar.quest.booty_money == "no")
				{
					link.l1 = DLG_TEXT[41];
					link.l1.go = "money";
				}
				if(CheckAttribute(Pchar,"quest.booty_bladeA5") && Pchar.quest.booty_bladeA5 == "no")
				{
					link.l2 = DLG_TEXT[42];
					link.l2.go = "bladeA5";
				}
				if(CheckAttribute(Pchar,"quest.booty_uniform") && Pchar.quest.booty_uniform == "no")
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "uniform";
				}
				if(CheckAttribute(Pchar,"quest.booty_spyglass3") && Pchar.quest.booty_spyglass3 == "no")
				{
					link.l4 = DLG_TEXT[43];
					link.l4.go = "spyglass3";
				}
				if(CheckAttribute(Pchar,"quest.booty_sewing_kit") && Pchar.quest.booty_sewing_kit == "no")
				{
					link.l5 = DLG_TEXT[44];
					link.l5.go = "sewing_kit";
				}
				if(CheckAttribute(Pchar,"quest.booty_tobacco") && Pchar.quest.booty_tobacco == "no")
				{
					link.l6 = DLG_TEXT[45];
					link.l6.go = "tobacco";
				}
				if(CheckAttribute(Pchar,"quest.booty_folding_knife") && Pchar.quest.booty_folding_knife == "no")
				{
					link.l7 = DLG_TEXT[46];
					link.l7.go = "folding_knife";
				}
				if(CheckAttribute(Pchar,"quest.booty_compass1") && Pchar.quest.booty_compass1 == "no")
				{
					link.l8 = DLG_TEXT[47];
					link.l8.go = "compass1";
				}
				if(CheckAttribute(Pchar,"quest.booty_pistoltinderbox") && Pchar.quest.booty_pistoltinderbox == "no")
				{
					link.l9 = DLG_TEXT[48];
					link.l9.go = "pistoltinderbox";
				}
				if(CheckAttribute(Pchar,"quest.booty_sextant") && Pchar.quest.booty_sextant == "no")
				{
					link.l10 = DLG_TEXT[49];
					link.l10.go = "sextant";
				}
				if(CheckAttribute(Pchar,"quest.booty_tin_jug") && Pchar.quest.booty_tin_jug == "no")
				{
					link.l11 = DLG_TEXT[50];
					link.l11.go = "tin_jug";
				}
				if(CheckAttribute(Pchar,"quest.booty_pistol9") && Pchar.quest.booty_pistol9 == "no")
				{
					link.l12 = DLG_TEXT[51];
					link.l12.go = "pistol9";
				}
				if(CheckAttribute(Pchar,"quest.booty_silver_bar") && Pchar.quest.booty_silver_bar == "no")
				{
					link.l13 = DLG_TEXT[52];
					link.l13.go = "silver_bar";
				}
				if(CheckAttribute(Pchar,"quest.booty_clock1") && Pchar.quest.booty_clock1 == "no")
				{
					link.l14 = DLG_TEXT[53];
					link.l14.go = "clock1";
				}
				if(CheckAttribute(Pchar,"quest.booty_foreign_items") && Pchar.quest.booty_foreign_items == "no")
				{
					link.l15 = DLG_TEXT[54];
					link.l15.go = "foreign_items";
				}
				if(CheckAttribute(Pchar,"quest.booty_drawing_kit") && Pchar.quest.booty_drawing_kit == "no")
				{
					link.l16 = DLG_TEXT[55];
					link.l16.go = "drawing_kit";
				}
				if(CheckAttribute(Pchar,"quest.booty_strange_shells") && Pchar.quest.booty_strange_shells == "no")
				{
					link.l17 = DLG_TEXT[56];
					link.l17.go = "strange_shells";
				}	
			
				Diag.TempNode = "first time";
				return;
			}

			if(CheckAttribute(Pchar,"quest.med_grandma") && Pchar.quest.med_grandma == "hint_Gunn")
			{
				PlaySound("VOICE\ENGLISH\grandma_1.wav");
				Dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "hint_Gunn1";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\grandma_1.wav");

				if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
				{
					Dialog.text = DLG_TEXT[13];
					link.l1 = DLG_TEXT[14];
					link.l1.go = "port_hint";
				}
				else
				{

					Dialog.text = DLG_TEXT[78];
					link.l1 = DLG_TEXT[79];
					link.l1.go = "exit";

					Diag.TempNode = "first time";
					return;
				}
			} 
			
			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "reputation":
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "reputation2";
		break;

		case "reputation2":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "reputation3";
		break;

		case "reputation3":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			AddDialogExitQuest("reputation_up");
		break;

		case "port_hint":
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "port_hint1";
		break;

		case "port_hint1":
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			AddDialogExitQuest("port_hint_done");
		break;

		case "hint_Gunn1":
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			LAi_SetCitizenType(characterFromID("grandma"));
			AddDialogExitQuest("gunner_hint_done");
		break;

		case "throw_pistols":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "throw_pistols1";
		break;

		case "throw_pistols1":
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "throw_pistols2";
		break;

		case "throw_pistols2":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("throw_pistols_done");
		break;

		case "shop_fight":
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "shop_fight1";
		break;

		case "shop_fight1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
			AddDialogExitQuest("shop_fight_done");
		break;

		case "stay_in_shop":
			PlaySound("VOICE\ENGLISH\grandma_5.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			AddDialogExitQuest("stay_in_shop_done");
		break;

		case "divide_the_booty":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "divide_the_booty1";
		break;

		case "divide_the_booty1":
			Pchar.quest.grandma_booty = 3; 
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_sit1");
		break;
//---------------------------------------------------------------------------------
		case "map":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_map");
		break;

		case "money":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_money = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_money");
		break;

		case "bladeA5":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_bladeA5 = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_bladeA5");
		break;

		case "uniform":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.booty_uniform = "yes";
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_sit2");
		break;

		case "spyglass3":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_spyglass3 = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_spyglass3");
		break;

		case "sewing_kit":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.booty_sewing_kit = "yes";
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_sit2");
		break;

		case "tobacco":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.booty_tobacco = "yes";
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_sit2");
		break;

		case "folding_knife":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_folding_knife = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_folding_knife");
		break;

		case "compass1":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_compass1 = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_compass1");
		break;

		case "pistoltinderbox":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_pistoltinderbox = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_pistoltinderbox");
		break;

		case "sextant":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_sextant = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_sextant");
		break;

		case "tin_jug":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_tin_jug = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_tin_jug");
		break;

		case "pistol9":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_pistol9");
		break;

		case "silver_bar":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_silver_bar = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_silver_bar");
		break;

		case "clock1":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_clock1 = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_clock1");
		break;

		case "foreign_items":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_foreign_items = "yes";
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[68];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_foreign_items");
		break;

		case "drawing_kit":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_drawing_kit = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_drawing_kit");
		break;

		case "strange_shells":
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), PChar);
			Pchar.quest.grandma_booty = makeint(Pchar.quest.grandma_booty)-1;
			Pchar.quest.booty_strange_shells = "yes";
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[69];
			if(CheckAttribute(Pchar,"quest.grandma_booty") && Pchar.quest.grandma_booty >= 1)
			{
				link.l1 = DLG_TEXT[70];
			}
			else link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_booty_strange_shells");
		break;
//---------------------------------------------------------------------------------
		case "future_plans":
			PlaySound("VOICE\ENGLISH\grandma_5.wav");
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToLocator(CharacterFromID("grandma"), "reload", "reload1");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans0");
		break;

		case "skip_ships":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), characterFromID("Dave Edna"));
			LAi_SetActorType(CharacterFromID("wench3"));
			LAi_ActorTurnToCharacter(characterFromID("wench3"), characterFromID("Dave Edna"));
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans3");
		break;

		case "Minerva_store":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), characterFromID("wench3"));
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans7");
		break;
	//--------------------------------------------------------------------------------
		case "farm_sloop":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "farm_sloop1";
		break;

		case "farm_sloop1":
			PlaySound("VOICE\ENGLISH\grandma_5.wav");
			Dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "farm_sloop2";
		break;

		case "farm_sloop2":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans9");
		break;
	//--------------------------------------------------------------------------------
		case "Claire_crew":
			PlaySound("VOICE\ENGLISH\grandma_5.wav");
			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToLocator(CharacterFromID("grandma"), "reload", "reload1");
			LAi_SetActorType(CharacterFromID("wench3"));
			LAi_ActorTurnToLocator(CharacterFromID("wench3"), "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Minerva"));
			LAi_ActorTurnToLocator(CharacterFromID("Minerva"), "reload", "reload1");
			Dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans11");
		break;

		case "choose_officers":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_crew_lines");
		break;

		case "examine_Hgold_map":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map1");
		break;

		case "treasure_map":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map11");
		break;

		case "notebook":
			TakeItemFromCharacter(Pchar, "notebook");
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map14");
		break;

		case "6_map_pieces":
			PlaySound("VOICE\ENGLISH\grandma_5.wav");
			Dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map24");
		break;
	//--------------------------------------------------------------------------------
		case "finale":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "treasure";	//was finale1
		break;
	//-----------------------------------------------------------
		case "treasure":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "treasure1";
		break;

		case "treasure1":
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_cheer1");
		break;

		case "treasure2":
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_cheer2");
		break;

		case "treasure3":
			PlaySound("VOICE\ENGLISH\grandma_yell2.wav");
			Dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_boo1");
		break;
	//-----------------------------------------------------------
		case "finale1":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_group");
		break;

		case "finale1_A":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "exit";
			AddDialogExitQuest("monkey_protest");
		break;

		case "finale2":
			PlaySound("VOICE\ENGLISH\grandma_6.wav");
			Dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "finale3";
		break;

		case "finale3":
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "finale4";
		break;

		case "finale4":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_platina");
		break;

		case "finale5":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "exit";
			AddDialogExitQuest("the_very_end");
		break;

	
	//---------------------------------------------------------------------------------
		case "Exit_sit":
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			LAi_SetSitType(CharacterFromID("grandma"));
			ChangeCharacterAddressGroup(characterFromID("Grandma"), "ck_drawing_room", "sit", "sit1");

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
