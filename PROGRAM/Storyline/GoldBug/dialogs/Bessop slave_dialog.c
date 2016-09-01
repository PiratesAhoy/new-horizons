//#include "DIALOGS\Redmond Soldier_dialog.h"
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
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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

			if(NPChar.id == "m_slave1") PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			if(NPChar.id == "m_slave2") PlaySound("VOICE\ENGLISH\FredBob.wav");
			if(NPChar.id == "m_slave3") PlaySound("VOICE\ENGLISH\gr_Richards.wav");			

			if(NPChar.id == "m_slave1" || NPChar.id == "m_slave2" || NPChar.id == "m_slave3")
			{
				int malephrase = rand(2);
				switch (malephrase)
				{
					case 0:
						dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
					break;

					case 1:
						dialog.text = DLG_TEXT[2];
						link.l1 = DLG_TEXT[3];
					break;

					case 2:
						dialog.text = DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
					break;
				}

				link.l1.go = "exit";	
			}

			if(NPChar.id == "f_slave1")
			{
				if(CheckAttribute(Pchar,"quest.bessop_barracks") && Pchar.quest.bessop_barracks == "yes")
				{
					PlaySound("VOICE\ENGLISH\black_witch_what.wav");
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				}
				else
				{
					PlaySound("VOICE\ENGLISH\black_witch_ehh.wav");
					Pchar.quest.bessop_barracks = "yes";
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "hostel_sketch";
				}
			}

			if(NPChar.id == "f_slave2")
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_004.wav");	
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exit";
			}
		break;

		case "hostel_sketch":
			PlaySound("VOICE\ENGLISH\black_witch_what.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "hostel_sketch1";
		break;

		case "hostel_sketch1":
			AddQuestRecord("Bishop's_Hostel", "1");
			PlaySound("VOICE\ENGLISH\black_witch_ahh.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "hostel_sketch2";
		break;

		case "hostel_sketch2":
			PlaySound("VOICE\ENGLISH\black_witch_ehh.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "hostel_sketch3";
		break;

		case "hostel_sketch3":
			PlaySound("VOICE\ENGLISH\black_witch_yah.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "hostel_sketch3";
			AddDialogExitQuest("trade_med_bag");
		break;
	
	//-------------------------------------------------------------------

		case "hostel_sketch4":
			AddQuestRecord("Bishop's_Hostel", "2");
			PlaySound("VOICE\ENGLISH\black_witch_ehh.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "hostel_sketch5";
		break;

		case "hostel_sketch5":
			PlaySound("VOICE\ENGLISH\black_witch_what.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "hostel_sketch6";
		break;

		case "hostel_sketch6":
			AddQuestRecord("Bishop's_Hostel", "3");
			PlaySound("VOICE\ENGLISH\black_witch_ehh.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "hostel_sketch7";
		break;

		case "hostel_sketch7":
			PlaySound("VOICE\ENGLISH\black_witch_yah.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "hostel_sketch8";
		break;

		case "hostel_sketch8":
			AddQuestRecord("Bishop's_Hostel", "4");
			PlaySound("VOICE\ENGLISH\black_witch_ahh.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "hostel_sketch9";
		break;

		case "hostel_sketch9":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "hostel_sketch10";
		break;

		case "hostel_sketch10":
			PlaySound("VOICE\ENGLISH\black_witch_what.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("bird_backside");
		break;

	//-------------------------------------------------------------------
	
		case "hostel_sketch11":
			PlaySound("VOICE\ENGLISH\black_witch_yah.wav");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];


			if(Pchar.chr_ai.hp < Pchar.chr_ai.hp_max)
			{
				link.l1.go = "bandages";
			}
			else
			{
				link.l1.go = "exit";
				AddDialogExitQuest("witch_is_drawing_done");
			}
		break;

		case "bandages":
			GiveItem2Character(Pchar, "medical1");
			PlaySound("VOICE\ENGLISH\black_witch_what.wav");
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("witch_is_drawing_done");
		break;
	}
}
