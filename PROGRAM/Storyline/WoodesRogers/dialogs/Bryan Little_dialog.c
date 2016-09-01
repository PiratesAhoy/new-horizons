//#include "DIALOGS\Tom Morgan_dialog.h"
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
			
			PlaySound("VOICE\ENGLISH\Por_m_b_035.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "Morgan_shiprepair":
			PlaySound("VOICE\ENGLISH\Por_m_b_010.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Morgan_shiprepair1";
		break;

		case "Morgan_shiprepair1":
			PlaySound("VOICE\ENGLISH\Por_m_b_025.wav");
			float hpp = GetHullPercent(Pchar);
			float spp = GetSailPercent(Pchar);
	
			if(hpp < 100.0 && spp < 100.0)
			{
				//Log_SetStringToLog("hull is damaged");
				//Log_SetStringToLog("sails are damaged");

				Pchar.ship.hp = GetCharacterShipHP(Pchar);	
				DeleteAttribute(Pchar,"ship.blots");
				Pchar.ship.sp = GetCharacterShipSP(Pchar);
				DeleteAttribute(Pchar,"ship.sails");
				DeleteAttribute(Pchar,"ship.masts");

				Dialog.text = DLG_TEXT[10];
			}
			else
			{
				if(hpp < 100.0)
				{
					//Log_SetStringToLog("hull is damaged");

					Pchar.ship.hp = GetCharacterShipHP(Pchar);	
					DeleteAttribute(Pchar,"ship.blots");

					Dialog.text = DLG_TEXT[11];
				}
			}
			else
			{
				if(spp < 100.0)
				{
					//Log_SetStringToLog("sails are damaged");					

					Pchar.ship.sp = GetCharacterShipSP(Pchar);
					DeleteAttribute(Pchar,"ship.sails");
					DeleteAttribute(Pchar,"ship.masts");

					Dialog.text = DLG_TEXT[12];
				}
			}
			else
			{
				//Log_SetStringToLog("no damage");

				Dialog.text = DLG_TEXT[9];
			}
		
			link.l1 = DLG_TEXT[13];
			link.l1.go = "planks_and_cloth";
		break;

		case "planks_and_cloth":
			int planks1 = GetSquadronGoods(Pchar, GOOD_PLANKS);
			int sailcloth1 = GetSquadronGoods(Pchar, GOOD_SAILCLOTH);

			RemoveCharacterGoods(Pchar, GOOD_PLANKS, makeint(makefloat(GetCharacterShipHP(Pchar)) * PLANKS_PER) );
			RemoveCharacterGoods(Pchar, GOOD_SAILCLOTH, makeint(makefloat(GetCharacterShipHP(Pchar)) * SAIL_PER) );
			
			AddCharacterGoods(Pchar, GOOD_PLANKS, makeint(makefloat(GetCharacterShipHP(Pchar)) * PLANKS_PER) );
			AddCharacterGoods(Pchar, GOOD_SAILCLOTH, makeint(makefloat(GetCharacterShipHP(Pchar)) * SAIL_PER) );
			
			int planks2 = GetSquadronGoods(Pchar, GOOD_PLANKS);
			int sailcloth2 = GetSquadronGoods(Pchar, GOOD_SAILCLOTH);

			if(planks2 > planks1 && sailcloth2 > sailcloth1)
			{
				Dialog.text = DLG_TEXT[14];
			}
			else
			{
				if(planks2 > planks1)
				{
					Dialog.text = DLG_TEXT[24];
				}
			}
			else
			{
				if(sailcloth2 > sailcloth1)
				{
					Dialog.text = DLG_TEXT[25];
				}
			}
			else Dialog.text = DLG_TEXT[28];

			link.l1 = DLG_TEXT[29];
			link.l1.go = "repair_chest_intro";
		break;
	
		case "repair_chest_intro":
			if(CheckCharacterItem(Pchar,"pistolmdchest_F5C") || CheckCharacterItem(Pchar,"pistolmdchest_F5C_C") 
				|| CheckCharacterItem(Pchar,"pistolmdchest_F5C_S") || CheckCharacterItem(Pchar,"pistolmdchest_F5C_CS") )
			{
				PlaySound("VOICE\ENGLISH\Por_m_b_042.wav");
				Dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "repair_chest";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Por_m_b_049.wav");
				Dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "exit";
				AddDialogExitQuest("carpenter_go_get_the_chest");
			}
		break;
	
		case "repair_chest":
			PlaySound("VOICE\ENGLISH\Por_m_b_034.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("carpenter_repairs_chest");
		break;

		case "chest_repaired":
			PlaySound("VOICE\ENGLISH\Por_m_b_035.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "chest_repaired1";
		break;
	
		case "chest_repaired1":
			PlaySound("VOICE\ENGLISH\Por_m_b_043.wav");		//was 034
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("carpenter_returns_chest");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
