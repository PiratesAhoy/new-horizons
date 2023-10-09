//#include "DIALOGS\William Dampier_dialog.h"
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
			
			if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
			{
				switch(Pchar.quest.med_Dampier)
				{
					case "start":
						//first time
						PlaySound("VOICE\ENGLISH\Fre_m_a_045.wav");
						Dialog.text = DLG_TEXT[26];
						link.l1 = DLG_TEXT[27];

						if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
							|| CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS") ) 
						{
							link.l1.go = "open_back";
						}
						else link.l1.go = "bring_the_chest";
					break;

					case "next_times":
						PlaySound("VOICE\ENGLISH\Fre_m_c_035.wav");
						if(CheckCharacterItem(Pchar,"mdchest_B2"))
						{
							//Dampier has already opened the back of medicine chest
							Dialog.text = DLG_TEXT[32];
							link.l1 = DLG_TEXT[33];
							link.l1.go = "tailor_hint_repeat";	
						}
						else
						{
							if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
								|| CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS") ) 
							{
								PlaySound("OBJECTS\DUEL\sabre_sh.wav");
								GiveItem2Character(Pchar, "mdchest_B2");
								Dialog.text = DLG_TEXT[30];
								link.l1 = DLG_TEXT[31];
								link.l1.go = "open_back2";
								LAi_QuestDelay("open_back_tailor_hint1", 1.0);
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[37];
							link.l1 = DLG_TEXT[38];
							link.l1.go = "exit";
						}
					break;
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_m_c_076.wav");

				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "navigator":
			PlaySound("VOICE\ENGLISH\dampier_sailorboy.wav");
	
			int curcrew = GetCrewQuantity(Pchar);
			int maxcrew = GetMaxCrewQuantity(Pchar);

			if(curcrew < maxcrew) 
			{
				SetCrewQuantity(Pchar, 1000);
				Dialog.text = DLG_TEXT[39];
			}
			else Dialog.text = DLG_TEXT[7];
	
			link.l1 = DLG_TEXT[8];
			link.l1.go = "navigator2";
		break;
	
		case "navigator2":
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "navigator3";
		break;
		
		case "navigator3":
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "navigator4";
		break;

		case "navigator4":
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("dampier_mission");
		break;

		case "book_repaired":
			PlaySound("VOICE\ENGLISH\dampier_sailorboy.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "book_repaired1";
		break;

		case "book_repaired1":
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			AddDialogExitQuest("glasses");
		break;

		case "repair_the_book":
	//		GiveItem2Character(Pchar, "book31");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("returned_to_library_dampier");//checkpoint library
		break;

		case "return_the_book":
			PlaySound("VOICE\ENGLISH\Fre_m_c_035.wav");
			GiveItem2Character(Pchar, "book31");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "return_the_book1";
		break;

		case "return_the_book1":
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "return_the_book2";
		break;

		case "return_the_book2":
			PlaySound("VOICE\ENGLISH\dampier_sailorboy.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("3dialogs_over");
		break;
	//.......................................................................
		case "open_back":
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "open_back1";
		break;

		case "open_back1":
			PlaySound("OBJECTS\DUEL\sabre_sh.wav");
			GiveItem2Character(Pchar, "mdchest_B2");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "open_back2";
			LAi_QuestDelay("open_back_tailor_hint1", 1.0);
		break;

		case "open_back2":
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "tailor_hint";
		break;

		case "tailor_hint":
			Pchar.quest.med_Dampier = "next_times";
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("open_back_tailor_hint");
		break;
	//.......................................................................
		case "bring_the_chest":
			Pchar.quest.med_Dampier = "next_times";
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
		break;
	//.......................................................................
		case "tailor_hint_repeat":
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;
	//.......................................................................
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
