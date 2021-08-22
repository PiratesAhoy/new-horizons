//#include "DIALOGS\gunner Ben Gunn_dialog.h"
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

			PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");

			if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
			{
				if(CheckAttribute(Pchar,"quest.med_Dave") && Pchar.quest.med_Dave == "violin")
				{
					Dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "violin1";
				}
				else
				{
					Dialog.text = DLG_TEXT[35];
					link.l1 = DLG_TEXT[36];
					link.l1.go = "exit";
				}
			}
			else
			{
				Dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
				link.l1.go = "exit";
		
			}

			Diag.TempNode = "first time";
		break;

		case "shop_closed":
			PlaySound("VOICE\ENGLISH\Dave_Edna_7.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "shop_closed1";
		break;
	
		case "shop_closed1":
			PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "shop_closed2";
		break;
	
		case "shop_closed2":
			PlaySound("VOICE\ENGLISH\Dave_Edna_8.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("key9");
		break;
	
		case "Selkirk_hint":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Selkirk_hint1";
		break;

		case "Selkirk_hint1":
			PlaySound("VOICE\ENGLISH\Dave_Edna_3.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("Dave_Edna_hint_Selkirk1");
		break;

		case "chest_hint":
			PlaySound("VOICE\ENGLISH\Dave_Edna_1.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "chest_hint1";
		break;
	
		case "chest_hint1":
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("chest_hint_done");
		break;
			
		case "violin1":
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "violin2";
		break;

		case "violin2":
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "violin3";
		break;

		case "violin3":
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "violin4";
		break;

		case "violin4":
			//offer first time
			Dialog.text = DLG_TEXT[18];
			if (makeint(pchar.money) >= 2000)
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "violin5";
			}
			else
			{
				link.l2 = DLG_TEXT[20];
				link.l2.go = "exit";
				Diag.TempNode = "violin6";
			}
		break;

		case "violin5": 
			Pchar.quest.med_Dave = "violin_bought";
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("violin_bought");
		break;

		case "violin6": 
			//offer next times
			Dialog.text = DLG_TEXT[16];
			if (makeint(pchar.money) >= 2000)
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "violin5";
			}
			else
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "exit";
				Diag.TempNode = "violin6";
			}
		break;

		case "shop_pistol20":
			PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("shop_pistol20_given");
		break;

		case "sell_blades":
			PlaySound("VOICE\ENGLISH\Dave_Edna_1.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "sell_blades1";
		break;

		case "sell_blades1":
			PlaySound("VOICE\ENGLISH\Dave_Edna_6.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("sell_blades_done");
		break;

		case "bad_officers":
			PlaySound("VOICE\ENGLISH\Dave_Edna_3.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("bad_officers_done");
		break;

		case "ship_not_equipped":
			PlaySound("VOICE\ENGLISH\Dave_Edna_3.wav");
			LAi_SetStayType(CharacterFromID("Dave Edna"));
			ChangeCharacterAddressGroup(characterFromID("Dave Edna"), "ck_drawing_room", "goto", "stay4");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans2");
		break;

		case "sell_Hgold_map":
			PlaySound("VOICE\ENGLISH\Dave_Edna_1.wav");
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map13A");		//was 14
		break;

		case "La_Concorde":
			PlaySound("VOICE\ENGLISH\Dave_Edna_6.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map21");
		break;

		case "FH_painting":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("grandma"));
			LAi_SetActorType(characterFromID("grandma"));
			LAi_ActorTurnToCharacter(characterFromID("grandma"), NPchar);
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "FH_painting1";
		break;

		case "FH_painting1":
			PlaySound("VOICE\ENGLISH\G_good_work.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "FH_painting2";
		break;

		case "FH_painting2":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_cheer3");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
