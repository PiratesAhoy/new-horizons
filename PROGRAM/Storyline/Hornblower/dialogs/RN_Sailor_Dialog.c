//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
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

			if(CheckQuestAttribute("Players_rank", "Midshipman"))
			{				
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2] + GetMyShipNameShow(PChar) +  DLG_TEXT[6];
				link.l1.go = "Continue Chatter Mishipman";
			}
			if(CheckQuestAttribute("Players_rank", "Lieutenant"))
			{				
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";
			}
			if(CheckQuestAttribute("Players_rank", "Commander"))
			{
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
			}
		break;

		case "Continue Chatter Mishipman":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[18];
			link.l2.go = "directions";
		break;

		case "directions":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Naval Yard";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "Naval HQ";
		break;

		case "Naval Yard":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "Naval HQ";
		break;

		case "Store":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "Naval HQ";
			link.l3 = DLG_TEXT[10];
			link.l3.go = "Naval Yard";
		break;

		case "Naval HQ":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[10];
			link.l3.go = "Naval Yard";
		break;

		case "Rifleman":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Rifleman2";
		break;

		case "Rifleman2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "Nail_up_house":
			PlaySound(voice_path + "Hornblwr06.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Nail_up_house2";
		break;

		case "Nail_up_house2":
			PlaySound(voice_path + "Hornblwr07.wav");
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Nail_up_house";
		break;

		case "Exit_Nail_up_house":
			AddDialogExitQuest("Maria_at_Greenford_Prison");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Debtors_Prison":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Debtors_Prison2";
		break;

		case "Debtors_Prison2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Debtors_Prison3";
		break;

		case "Debtors_Prison3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Debtors_Prison";
		break;

		case "Exit_Debtors_Prison":
			AddDialogExitQuest("Maria_debts_paid");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Debtors_Prison_soldier":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_Debtors_Prison_soldier";
		break;

		case "Exit_Debtors_Prison_soldier":
			Diag.CurrentNode = "Debtors_Prison_soldier";
			DialogExit();
		break;

		case "Found_the_battery":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_Found_the_battery";
		break;

		case "Exit_Found_the_battery":
			AddDialogExitQuest("Hotspur_underfire");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_rope":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "A_rope2";
		break;

		case "A_rope2":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "A_rope3";
		break;

		case "A_rope3":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit_A_rope";
		break;

		case "Exit_A_rope":
			AddDialogExitQuest("Another_Hotspur_visit");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}
