//#include "DIALOGS\Church crew_dialog.h"
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

			PlaySound("VOICE\ENGLISH\Eng_f_c_020.wav");

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
			{
				if(CheckAttribute(Pchar, "quest.coin_collection") && Pchar.quest.coin_collection == "7")
				{
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				}
				else
				{
					if(CheckCharacterItem(NPchar,"coin5") || CheckCharacterItem(NPchar,"coin6"))
					{
						dialog.text = DLG_TEXT[2];
						link.l1 = DLG_TEXT[3];
						link.l1.go = "coins";
					}
					else
					{
						dialog.text = DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
						link.l1.go = "exit";
					}
				}
			}
			else
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		break;

		case "coins":
			string	itmid;
		
			itmid = "coin5";
			if(CheckCharacterItem(NPchar,"coin5"))
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
		
			itmid = "coin6";
			if(CheckCharacterItem(NPchar,"coin6"))
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

			LAi_QuestDelay("coins_collection_check", 0.1);
		break;

		case "about_Richards6":
			PlaySound3D("INTERFACE\bubbles2.wav", 24.0, 2.7, 0.0);
			Pchar.Vane_boiling_bubbles = "yes";

			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "about_Richards7";
		break;

		case "about_Richards7":
			PlaySound("VOICE\ENGLISH\Eng_f_c_017.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards8");
		break;

		case "about_Richards10":
			PlaySound3D("INTERFACE\steam1.wav", 24.0, 2.7, -9.0);
			PlaySound3D("INTERFACE\steam1.wav", 24.0, 2.7, -9.0);
			Pchar.Vane_boiling_steam = "yes";

			PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "about_Richards11";
		break;

		case "about_Richards11":
			AddQuestRecord("Richards","3");

			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_Richards11");
		break;

		case "Rackham1":
			PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom2.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap18"));

			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion6");
		break;

		case "Rackham2":
			PlaySound("VOICE\ENGLISH\gm_crew12A.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap1"));

			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion13");
		break;

		case "Rackham3":
			PlaySound("VOICE\ENGLISH\gm_crew12B.wav");
			LAi_ActorTurnToCharacter(NPChar, characterFromID("pir_cap18"));
			LAi_ActorTurnToCharacter(characterFromID("pir_cap18"), NPChar);

			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_rum_explosion16");
		break;


		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
