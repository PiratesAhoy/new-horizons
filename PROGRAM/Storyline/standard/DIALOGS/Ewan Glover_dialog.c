//#include "DIALOGS\Ewan Glover_dialog.h"
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

		case "Exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "Goodbye_Exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Ewan_goodbye_exit");
		break;

		case "Exit_business":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Ewan_exit_business");
		break;
			
		case "Exit_to_tavern":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("prepare_Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "Exit_need_some_walk":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Ewan_Exit_need_some_walk");
		break;

		case "Once Again_Exit_Join":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Ewan_Glover_exit_join");
		break;
	
		case "exit_no join":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();			
		break;
		
		case "Exit_Join":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Ewan_Glover_exit_join");
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			
			dialog.snd = "Voice\EWGL\EWGL001";	
			d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[1] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[2])]) + DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + Characters[GetCharacterIndex(DLG_TEXT[6])].name  + DLG_TEXT[7];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			dialog.snd = "Voice\EWGL\EWGL002";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9] +  GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[10])]) + DLG_TEXT[11];
			Link.l1.go = "Node_2";
		break;

		case "Node_2":
			dialog.snd = "Voice\EWGL\EWGL003";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "node_3";
		break;
			

		case "Node_3":
			if(SetCompanionIndex(Pchar, -1, GetCharacterIndex("Ewan Glover")) == GetCharacterIndex("Ewan Glover"));
			{
				Diag.TempNode = "Once Again";
				dialog.snd = "Voice\EWGL\EWGL004";
				d.Text = DLG_TEXT[14] + GetMyName(Pchar) + DLG_TEXT[15];
				Link.l1 = DLG_TEXT[16];
				Link.l1.go = "Node_4";
			}
			else
			{
				Diag.TempNode = "Second Time";
				AddQuestRecord("Story_2ndTask",2);
				dialog.snd = "Voice\EWGL\EWGL005";
				d.Text = DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "Exit_join";
			}

		break;


		case  "Node_4":
			dialog.snd = "Voice\EWGL\EWGL006";
			d.text = DLG_TEXT[19] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[20])]) + DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "Exit_no Join";
		break;


		case "Second Time":
			dialog.snd = "Voice\EWGL\EWGL007";
			d.Text =  DLG_TEXT[23] + GetMyName(Pchar) + DLG_TEXT[24]; 
			Link.l1 = DLG_TEXT[25];
			Link.l1.go =  "exit";
			AddDialogExitQuest("ewan_glover_Exit_to_port_of_Redmond");
		break;
		
		case "Once Again":
			dialog.snd = "Voice\EWGL\EWGL008";
			d.Text = DLG_TEXT[26] + GetMyName(Pchar) + DLG_TEXT[27];
			if(SetCompanionIndex(Pchar, -1, GetCharacterIndex("Ewan Glover")) == GetCharacterIndex("Ewan Glover"));
			{
				Diag.TempNode = "Once Again";
				Link.l1 = DLG_TEXT[28];
				Link.l1.go = "Once Again_1";
			}				
			else
			{
				Diag.TempNode = "Second Time";
				Link.l1 =  DLG_TEXT[29];		
				Link.l1.go = "Once Again_2";
			}
		break;

		case "Once Again_1":
			dialog.snd = "Voice\EWGL\EWGL009";
			d.text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go= "exit";
			AddDialogExitQuest("Ewan_Once_Again_exit_no_join");
		break;

		case "Once Again_2":
			dialog.snd = "Voice\EWGL\EWGL010";
			d.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			Link.l1.go = "exit";
			AddDialogExitQuest("Ewan_Glover_exit_join");
		break;

		case "Are_you_ready":
			AddDialogExitQuest("Story_Wilfred_go_to_shore");
			if (makeint(Environment.time) > 22.00 || makeint(environment.time) <6.00)
			{
				dialog.snd = "Voice\EWGL\EWGL011";
				d.Text = DLG_TEXT[34];
				Link.l1 = DLG_TEXT[35];
				Link.l1.go =  "Exit_business";
			}
			else
			{
				dialog.snd = "Voice\EWGL\EWGL012";
				d.Text = DLG_TEXT[36] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[37];
				Link.l1 = DLG_TEXT[38];
				Link.l1.go = "Exit_to_tavern";
				Link.l2 = DLG_TEXT[39];
				Link.l2.go = "Are_you_ready_1";
			}
		break;

		case "Are_You_ready_1":
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition.l1 = "locator";
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition.l1.location = "Redmond_tavern";
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition.l1.locatorgroup = "reload";
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition.l1.locator = "Reload1";
			Pchar.quest.Story_Glover_to_tavern_on_Greenford.win_condition = "Story_Glover_to_tavern_on_Greenford";	
			//Pchar.quest.Story_Glover_to_tavern_on_Greenford.fail_condition = "Story_Glover_to_tavern_on_Greenford";	
			dialog.snd = "Voice\EWGL\EWGL013";
			d.text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit_need_some_walk";
		break;

		case "CameToGreenford":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "dialogs\0\009";
			Diag.TempNode = "CameToGreenford";
			dialog.snd = "Voice\EWGL\EWGL014";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "Exit";
		break;

		case "Talk_in_tavern":
			Dialog.defAni = "";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			Dialog.cam = "1";

			dialog.snd = "Voice\EWGL\EWGL015";
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Talk_In_Tavern_1";
		break;


		case "Talk_In_Tavern_1":
			dialog.snd = "Voice\EWGL\EWGL016";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Talk_in_tavern_2";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go =  "Exit_business";
		break;


		case "Talk_in_tavern_2":
			dialog.snd = "Voice\EWGL\EWGL017";
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Talk_in_tavern_3";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "Exit_business";
		break;


		case "Talk_in_tavern_3":
			dialog.snd = "Voice\EWGL\EWGL018";
			d.text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "Talk_in_Tavern_4";
		break;


		case "Talk_in_tavern_4":
			dialog.snd = "Voice\EWGL\EWGL019";
			d.Text = DLG_TEXT[54];
			Link.l1 = DLG_TEXT[55];
			Link.l1.go= "Talk_in_Tavern_5";
		break;


		case "Talk_in_Tavern_5":
			dialog.snd = "Voice\EWGL\EWGL020";
			d.Text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "Talk_in_Tavern_6";
		break;

		case "Talk_in_Tavern_6":
			dialog.snd = "Voice\EWGL\EWGL021";
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go =  "Exit_business";
		break;

		case "Are_you_ready_again":
			Dialog.defAni = "";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\EWGL\EWGL022";
			d.Text = DLG_TEXT[60] + GetMyName(Pchar) + DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "Exit";
			AddDialogExitQuest("prepare_Story_ReloadedtoGreenfordTavernWithGlover_1");
		break;
	
		case "Goodbye":
			dialog.snd = "Voice\EWGL\EWGL023";
			d.text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go =  "Goodbye_1";
		break;

		case "Goodbye_1":
			dialog.snd = "Voice\EWGL\EWGL024";
			d.Text = DLG_TEXT[65] + GetMyName(Pchar) + DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67] + GetMyName(NPChar) + DLG_TEXT[68];
			Link.l1.go = "Goodbye_exit";
		break;
		
		case "CameToOxbay_shore":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			
			Diag.TempNode = "CameToGreenford";
			
			dialog.snd = "Voice\EWGL\EWGL025";
			d.Text = DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "Exit";
		break;

	}

}


