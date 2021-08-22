//#include "DIALOGS\Counterspy_dialog.h"
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

		case "Exit_FirstMetCounterspy":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Fem_JoinCounterSpy");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_meeting;
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
			
			dialog.snd = "Voice\COUN\COUN001";
			if(PChar.sex == "woman"){
				Preprocessor_Add("sir", XI_ConvertString("ma'am"));
			}
			else{
				Preprocessor_Add("sir", XI_ConvertString("sir"));
			}
			d.Text = DLG_TEXT[0] + Pchar.lastname + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Meeting_1";
		break;

		case "Meeting_1":
			dialog.snd = "Voice\COUN\COUN002";
			d.Text = DLG_TEXT[3] + GetMyName(NPChar) + DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Meeting_2";
		break;

		case "Meeting_2":
			dialog.snd = "Voice\COUN\COUN003";
			d.Text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Meeting_3";
		break;

		case "Meeting_3":
			Diag.TempNode = "Travelling";
				dialog.snd = "Voice\COUN\COUN004";
			d.Text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_FirstMetCounterspy";
		break;

		case "Travelling":
			dialog.snd = "Voice\COUN\COUN005";
			d.Text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Travelling_1";
		break;

		case "Travelling_1":
			Diag.TempNode = "Travelling";
			dialog.snd = "Voice\COUN\COUN006";
			d.Text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit";
		break;
		
		case "LooksLikeTrouble":
			dialog.snd = "Voice\COUN\COUN007";
			d.text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "exit";
		break;
		
		case "Met_Blaze":
			Dialog.defAni = "Sit_HeadonHand";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_HeadonHand";
			Dialog.cam = "1";
			

			Diag.TempNode = "LooksLikeTrouble";

			Pchar.quest.Story_2ndTask = "Second_task_in_progress";
			dialog.snd = "Voice\COUN\COUN008";
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go =  "Met_Blaze_1";
		break;


		case "Met_Blaze_1":
			dialog.snd = "Voice\COUN\COUN009";
			d.text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Met_Blaze_2";
		break;


		case "Met_Blaze_2":
			dialog.snd = "Voice\COUN\COUN010";
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Met_Blaze_3";
		break;


		case "Met_Blaze_3":
			dialog.snd = "Voice\COUN\COUN011";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Met_Blaze_4";
		break;

		case "Met_Blaze_4":
			AddQuestRecord("Story_2ndTask", 9);
			dialog.snd = "Voice\COUN\COUN012";
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			AddDialogExitQuest("Counterspy_Exit_fight");
		break;

		case "After_Fight":
			Diag.TempNode = "to_Shipyard";
			dialog.snd = "Voice\COUN\COUN013";
			d.Text = DLG_TEXT[26];
			Link.l1 =  DLG_TEXT[27];
			Link.l1.go =  "After_Fight_1";
		break;

		case "After_Fight_1":
			dialog.snd = "Voice\COUN\COUN014";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "After_Fight_2";
		break;

		case "After_Fight_2":
			dialog.snd = "Voice\COUN\COUN015";
			d.Text = DLG_TEXT[30] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[31])]) + DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "After_Fight_3";
		break;

		case "After_Fight_3":
			dialog.snd = "Voice\COUN\COUN016";
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			link.l1.go ="exit";
			AddDialogExitQuest("Counterspy_After_Fight_Exit");
		break;

		case "to_Shipyard":
			dialog.snd = "Voice\COUN\COUN017";
			Diag.Tempnode = "to_Shipyard";
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit";
		break;

		case "Officer_money":
			dialog.snd = "Voice\COUN\COUN018";
			Diag.Tempnode = "Ready_for_meeting";
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "Officer_money_1";
		break;

		case "Officer_money_1":
			dialog.snd = "Voice\COUN\COUN019";
			d.Text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Officer_money_2";
		break;


		case  "Officer_money_2":
			dialog.snd = "Voice\COUN\COUN020";
			d.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go= "Officer_money_3";
		break;


		case "Officer_money_3":
			dialog.snd = "Voice\COUN\COUN021";
			d.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "Officer_money_4";
		break;


		case "Officer_money_4":
			dialog.snd = "Voice\COUN\COUN022";
			d.Text =  DLG_TEXT[47] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[48])]) + DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			Link.l1.go = "Officer_money_5";
		break;

		case  "Officer_money_5":
			AddQuestRecord("Story_2ndTask",10);
			dialog.snd = "Voice\COUN\COUN023";
			d.Text = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[51])]) + DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
			AddDialogExitQuest("counterspy_Officer_money_exit");
		break;


		case  "Ready_for_meeting":
			dialog.snd = "Voice\COUN\COUN024";
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "Ready_for_meeting_1";
		break;


		case "Ready_for_meeting_1":
			dialog.snd = "Voice\COUN\COUN025";
			Diag.TempNode = "Go_to_meeting";
			d.Text = DLG_TEXT[57];
// KK -->
			if (GetNotCaptivePassengersQuantity(pchar) == 0) {
				Link.l1 = DLG_TEXT[58];
			} else {
				Link.l1 = DLG_TEXT[59];
			}
// <-- KK
			link.l1.go = "exit";
			AddDialogExitQuest("CounterSpy_Ready_for_meeting_exit");
		break;

		case "Go_to_meeting":
			dialog.snd = "Voice\COUN\COUN026";
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			link.l1.go = "exit";
		break;

		case "Talk_AfterTavern":
			Dialog.defAni = "Dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\COUN\COUN027";
			d.Text = DLG_TEXT[62] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[63])]) + DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65] + Characters[GetCharacterIndex(DLG_TEXT[66])].lastname + DLG_TEXT[67];
			Link.l1.go = "Talk_AfterTavern_1";
		break;

		case "Talk_AfterTavern_1":
			dialog.snd = "Voice\COUN\COUN028";
			d.Text = DLG_TEXT[68] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[69])]) + DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "Talk_AfterTavern_2";
		break;

		case "Talk_AfterTavern_2":
			dialog.snd = "Voice\COUN\COUN029";
			Diag.Tempnode = "Just_A_talk";
			Characters[GetCharacterIndex("Rabel Iverneau")].Dialog.CurrentNode = "Just_A_talk";
			d.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "exit";
			AddDialogExitQuest("CounterSpy_Talk_AfterTavern_exit");
		break;

		case "Just_a_talk":
			dialog.snd = "Voice\COUN\COUN030";
			Diag.Tempnode = "Just_A_talk";
			d.Text = DLG_TEXT[74];
			Link.l1 = DLG_TEXT[75];
			Link.l1.go = "Exit";
		break;
	}
}
