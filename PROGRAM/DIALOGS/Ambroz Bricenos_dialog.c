//#include "DIALOGS\Ambroz Bricenos_dialog.h"
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
	
	Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy


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
			
			dialog.snd = "Voice\AMBR\AMBR001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(PChar.quest.Hitman == "goto_mateus")
			{
				dialog.snd = "Voice\AMBR\AMBR002";
				dialog.text = DLG_TEXT[2]+ Characters[GetCharacterIndex(DLG_TEXT[3])].lastname +DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Exit";

			}
			if(PChar.quest.Hitman == "mark_ambroz")
			{
				dialog.snd = "Voice\AMBR\AMBR003";
				dialog.text = DLG_TEXT[6]+ Characters[GetCharacterIndex(DLG_TEXT[7])].lastname +DLG_TEXT[8];
				link.l1 = DLG_TEXT[9]+ Characters[GetCharacterIndex(DLG_TEXT[10])].lastname +DLG_TEXT[11];
				link.l1.go = "pity";
				link.l2 = DLG_TEXT[12]+ Characters[GetCharacterIndex(DLG_TEXT[13])].lastname +DLG_TEXT[14];
				link.l2.go = "pity";


			}

		break;

		case "wetjob":
			dialog.snd = "Voice\AMBR\AMBR004";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "wetjob1";
			link.l2 = DLG_TEXT[17];
			link.l2.go = "refused";

		break;

		case "refused":
			dialog.snd = "Voice\AMBR\AMBR005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "wetjob1";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "Exit_refused";
		break;

		case "wetjob1":
			dialog.snd = "Voice\AMBR\AMBR007";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "wetjob2";
			link.l2 = DLG_TEXT[23];
			link.l2.go = "Exit_refused";
		break;

		case "wetjob2":
			dialog.snd = "Voice\AMBR\AMBR008";
			dialog.text = DLG_TEXT[24]+ Characters[GetCharacterIndex(DLG_TEXT[25])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[26])].lastname +DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "wetjob3";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "Exit_refused";
		break;

		case "wetjob3":
			dialog.snd = "Voice\AMBR\AMBR009";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_hit_start";
		break;

		case "pity":
			dialog.snd = "Voice\AMBR\AMBR010";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33]+ Characters[GetCharacterIndex(DLG_TEXT[34])].lastname +DLG_TEXT[35];
			link.l1.go = "kill";
			link.l2 = DLG_TEXT[36];
			link.l2.go = "cash";
			link.l3 = DLG_TEXT[37];
			link.l3.go = "spare";
		break;

		case "cash":
			ChangeCharacterReputation(pchar, -10);
		    PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 1500);
			dialog.snd = "Voice\AMBR\AMBR011";
			dialog.text = DLG_TEXT[38];
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "Exit_spare";
			}
			link.l2 = DLG_TEXT[40];
			link.l2.go = "kill";
		break;

		case "spare":
			dialog.snd = "Voice\AMBR\AMBR012";
			dialog.text = DLG_TEXT[41];
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l1 = DLG_TEXT[42];
				link.l1.go = "Exit_spare";
			}
			link.l2 = DLG_TEXT[43];
			link.l2.go = "kill";
		break;

		case "kill":
			dialog.snd = "Voice\AMBR\AMBR013";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Exit_kill";
		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

		case "Exit_refused":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_refused_Ambroz");

		break;

		case "Exit_hit_start":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_start1");

		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -10);

			AddDialogExitQuest("Hit_kill_Ambroz");

		break;

		case "Exit_spare":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, 5);

			AddDialogExitQuest("Hit_spared_Ambroz");

		break;

	}
}
