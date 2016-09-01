//#include "DIALOGS\Weatherby Swann_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);


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

			if(CheckQuestAttribute("henry_talk", "Norrington_to_be_pirate"))
			{
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "French_attack_plan_continues";
			}			
			if(CheckQuestAttribute("henry_talk", "not_taking_Interceptor"))
			{
			dialog.text = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "An_unholy_alliance2";
			}
			if(CheckQuestAttribute("henry_talk", "Swann_and_French_attack_plan"))
			{
			dialog.text = DLG_TEXT[15] + pchar.lastname;
			link.l1 = DLG_TEXT[16];
			link.l1.go = "French_attack_plan2";
			}
			else
			{
			d.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "speak1";
			}
		break;

		case "speak1":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar);
			link.l1.go = "exitSwann1";
		break;

		case "speak2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "speak3";
		break;

		case "speak3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "speak4";
		break;

		case "speak4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "speak5";
		break;

		case "speak5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "speak6";
		break;

		case "speak6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "speak7";
		break;

		case "speak7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "speak8";
		break;

		case "speak8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "speak10";
		break;

		case "speak10":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "speak11";
		break;

		case "speak11":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exitfirst";
		break;

		case "exitfirst":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			AddDialogExitQuest("go_to_fight_Slave_Traders");
			DialogExit();
			Diag.CurrentNode = "speaktoTiaagain";
		break;

		case "the_prison_scene":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\THDI\THDI001";

			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exitSwann2";
		break;

		case "Following_Elizabeth":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exitSwann3";
		break;

		case "speakagain2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "speakagain3";
		break;

		case "speakagain3":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "speakagain4";
		break;

		case "speakagain4":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "speakagain5";
		break;

		case "speakagain5":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "speakagain6";
		break;

		case "speakagain6":
			AddMoneyToCharacter(pchar, -500);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "speakagain7";
		break;

		case "speakagain7":
			GiveItem2Character(Pchar,"Compass3");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "speakagain8";
		break;

		case "speakagain8":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit2";
			AddQuestRecord("And_now_Beckett_and_Beckett", "6");
		break;

		case "An_unholy_alliance":
			dialog.text = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "An_unholy_alliance2";
		break;		

		case "An_unholy_alliance2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "An_unholy_alliance3";
		break;

		case "An_unholy_alliance3":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "An_unholy_alliance4";
		break;

		case "An_unholy_alliance4":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "An_unholy_alliance5";
		break;

		case "An_unholy_alliance5":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "An_unholy_allianceexit";
		break;

		case "French_attack_plan2":
			dialog.text = DLG_TEXT[17] + pchar.lastname + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "French_attack_plan3";		
		break;
		
		case "French_attack_plan3":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "French_attack_plan4";		
		break;

		case "French_attack_plan4":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "French_attack_plan5";		
		break;

		case "French_attack_plan5":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "French_attack_plan6";		
		break;

		case "French_attack_plan6":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit_French_attack_plan";		
		break;

		case "French_attack_plan_continues":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "French_attack_plan_continues2";
		break;

		case "French_attack_plan_continues2":		
			dialog.text = DLG_TEXT[34] + pchar.lastname + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "French_attack_plan_continues3";		
		break;

		case "French_attack_plan_continues3":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "French_attack_plan_continues4";		
		break;

		case "French_attack_plan_continues4":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit_French_attack_plan_continues";		
		break;
		
		case "Exit":
			DialogExit();
			Diag.CurrentNode = "First time";

		break;

		case "exitSwann1":
			AddDialogExitQuest("Escape_to_Shipyard_at_Redmond"); // ("Swann_put_me_in_prison");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;

		case "exitSwann2":
			AddDialogExitQuest("Norrington_once_more"); // ("Swann_put_me_in_prison");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;	

		case "exitSwann3":
			AddDialogExitQuest("The_final_escape"); // ("Swann_put_me_in_prison");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;
		
		case "An_unholy_allianceexit":
			AddDialogExitQuest("Swann_Norrington_Beckett");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;

		case "exit_French_attack_plan":
			pchar.quest.henry_talk = "Norrington_and_French_attack_plan";		
			AddDialogExitQuest("Swann_Norrington_Player");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;		
		
		case "exit_French_attack_plan_continues":
			AddMoneyToCharacter(pchar, 300000);		
			pchar.quest.henry_talk = "Norrington_and_French_attack_plan";		
			AddDialogExitQuest("Norrington_As_A_Pirate");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;
		
		
	}
}
