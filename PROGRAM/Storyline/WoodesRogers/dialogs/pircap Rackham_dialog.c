//#include "INTERFACE\itemstrade.c"
//JRH testing


//#include "DIALOGS\Arabella's guard_dialog.h"
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
			dialog.snd = "Voice\ARGU\ARGU001";

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				PlaySound("VOICE\ENGLISH\pir_capCC.wav");
				if(CheckCharacterPerk(Pchar, "Gunman"))
				{
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
				else
				{
					LAi_SetStayType(CharacterFromID("pir_cap18"));
					LAi_SetActorType(CharacterFromID("pir_cap18"));
					LAi_ActorTurnToCharacter(characterFromID("pir_cap18"), Pchar);

					Pchar.perks.list.Gunman = true;
					Pchar.quest.Aperks = makeint(Pchar.quest.Aperks)-1;
					Dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
					AddDialogExitQuest("perk_gunman");
				}
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
				{
					float u, v, w;
					GetCharacterPos(CharacterFromID("pir_cap18"), &u, &v, &w);
					CreateParticleSystem("stars_short" , u, v+1.7, w, 0.0, 0.0, 0.0, sti(20) );
					PlaySound("OBJECTS\VOICES\DEAD\male\dead4.wav");

					if(Pchar.location == "wr_church_inside")
					{
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"fake_candelabre"))
						{
							Dialog.text = DLG_TEXT[8];
							link.l1 = DLG_TEXT[9];
							link.l1.go = "trade";
						}
						else
						{
							Dialog.text = DLG_TEXT[0];
							link.l1 = DLG_TEXT[1];
							link.l1.go = "exit";
						}

					}
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\pir_capCC.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
		break;

		case "who_took_the_coins":
			//PlaySound("VOICE\ENGLISH\pir_capCC.wav");
			PlaySound("VOICE\ENGLISH\pir_capGGG.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("who_took_the_coins9");
		break;

		case "trade":
			//LAi_QuestDelay("Rackham_censer_check", 0.1);
			LAi_QuestDelay("Rackham_candelabre_check", 0.1);

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
		
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "kitchen_empty":
			PlaySound("VOICE\ENGLISH\pir_capCC.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search26");
		break;

		case "about_Richards":
			PlaySound("VOICE\ENGLISH\pir_capCC.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "about_Richards1";
		break;

		case "about_Richards1":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards2");
		break;

		case "about_Richards9":
			PlaySound("VOICE\ENGLISH\pir_capT.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards10");
		break;

		case "I_am":
			PlaySound("VOICE\ENGLISH\pir_capGGG.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap1"));

			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion11");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;
	}
}
