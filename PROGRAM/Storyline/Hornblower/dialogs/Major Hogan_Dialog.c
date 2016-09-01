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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First_conversation":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_conversation2";
		break;

		case "First_conversation2":
//			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First_conversation3";
		break;

		case "First_conversation3":
//			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "First_conversation4";
		break;

		case "First_conversation4":
//			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "First_conversation5";
		break;

		case "First_conversation5":
//			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "First_conversation6";
		break;

		case "First_conversation6":
//			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_First_conversation";
		break;

		case "Exit_First_conversation":
			AddDialogExitQuest("Teresa's_Bargain");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Second_conversation":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Second_conversation2";
		break;

		case "Second_conversation2":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Second_conversation3";
		break;

		case "Second_conversation3":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Second_conversation4";
		break;

		case "Second_conversation4":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Second_conversation5";
		break;

		case "Second_conversation5":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Second_conversation6";
		break;

		case "Second_conversation6":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Second_conversation7";
		break;

		case "Second_conversation7":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Second_conversation8";
		break;

		case "Second_conversation8":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Second_conversation9";
		break;

		case "Second_conversation9":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Second_conversation";
		break;

		case "Exit_Second_conversation":
			AddDialogExitQuest("Change_my_clothes");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Third_conversation":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Exit_Third_conversation";
		break;

		case "Exit_Third_conversation":
			AddDialogExitQuest("Dunnitt_sends Sharpe_off");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fourth_conversation":
//			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_Fourth_conversation";
		break;

		case "Exit_Fourth_conversation":
			AddDialogExitQuest("To_town_with_Teresa");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "looking_for_Wolfe":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "looking_for_Wolfe2";
		break;

		case "looking_for_Wolfe2":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "looking_for_Wolfe3";
		break;

		case "looking_for_Wolfe3":
			if(CheckQuestAttribute("know_about_Wolfe", "None"))
			{
				pchar.quest.know_about_Wolfe = "Hogan";
				SetQuestHeader("Hunt the Traitors");
				AddQuestRecord("Hunt the Traitors", 1);
			}
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";

			Group_CreateGroup("wolfes_Ship"); 
			Group_AddCharacter("wolfes_Ship", "Thomas Wolfe");
			Group_SetGroupCommander("wolfes_Ship", "Thomas Wolfe");
			Group_SetTaskAttack("wolfes_Ship",  PLAYER_GROUP, true);
			Group_LockTask("wolfes_Ship"); 
			Sea_LoginGroupNow("wolfes_Ship");
			characters[GetCharacterIndex("Thomas Wolfe")].nosurrender = 2;
			Group_SetAddress("wolfes_Ship", "FalaiseDeFleur", "Quest_Ships","Quest_Ship_9");
		break;
	}
}
