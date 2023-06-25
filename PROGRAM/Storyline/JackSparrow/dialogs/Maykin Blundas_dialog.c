//#include "DIALOGS\Maykin Bundas_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First_meet_Blundas":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];			
			link.l1.go = "First_meet_Blundas2";
			pchar.talkingblundas = true; // PB
		break;

		case "First_meet_Blundas2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "First_meet_Blundas3";
		break;

		case "First_meet_Blundas3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];			
			link.l1.go = "First_meet_Blundas4";
		break;

		case "First_meet_Blundas4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "First_meet_Blundas5";
		break;

		case "First_meet_Blundas5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "First_meet_Blundas6";			
		break;

		case "First_meet_Blundas6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Wont_join_Blundas";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "Going_to_join_Blundas";
		break;

		case "Wont_join_Blundas":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];			
			link.l1.go = "Exit_first_meet";
		break;

		case "Blundas_for_Skulls":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];			
			link.l1.go = "Blundas_for_Skulls2TEMP";// TEMP fix till quest written
		break;

		case "Blundas_for_Skulls2":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];			
			link.l1.go = "Blundas_for_Skulls3";
		break;

		case "Blundas_for_Skulls3":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];			
			link.l1.go = "Blundas_for_Skulls4";
		break;

		case "Blundas_for_Skulls4":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];			
			link.l1.go = "Blundas_for_Skulls5";
		break;

		case "Blundas_for_Skulls5":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];			
			link.l1.go = "Blundas_for_Skulls6";
		break;

		case "Blundas_for_Skulls6":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];			
			link.l1.go = "Exit_for_Skulls";
		break;
		
		case "Exit_first_meet":
			DeleteAttribute(pchar,"talkingblundas"); // PB
			AddDialogExitQuest("having_met_Blundas");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Going_to_join_Blundas":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "Exit_join_Blundas";
		break;		

		case "Exit_join_Blundas":
			LAi_SetActorType(characterFromID("Maykin Blundas"));		
			AddDialogExitQuest("will_join_Blundas");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_for_Skulls":
			LAi_SetOfficerType(characterFromID("Maykin Blundas"));		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;
		
		case "Exit":		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;		
//Temp quest end till quest written
		case "Blundas_for_Skulls2TEMP":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Blundas_for_Skulls3TEMP";
		break;

		case "Blundas_for_Skulls3TEMP":
			PlayStereoSound("INTERFACE\took_item.wav");
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_Blundas_for_SkullsTEMP";
		break;

		case "Exit_Blundas_for_SkullsTEMP":
			LAi_SetActorType(characterFromID("Maykin Blundas"));
			AddDialogExitQuest("TEMP_Blundas_Finish");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

