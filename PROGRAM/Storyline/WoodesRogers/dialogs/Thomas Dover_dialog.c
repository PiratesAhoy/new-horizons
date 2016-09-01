//#include "DIALOGS\Thomas Dover_dialog.h"
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
			
			if(CheckCharacterItem(Pchar,"book35"))
			{
				PlaySound("VOICE\ENGLISH\Eng_m_a_040.wav");
				Dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "chain";
			}
			elseЁ
			{
				if(CheckAttribute(Pchar,"quest.med_Dover"))
				{
					switch(Pchar.quest.med_Dover)
					{
						case "bring_empty_bottles":
							PlaySound("VOICE\ENGLISH\Eng_m_a_011.wav");
							Dialog.text = DLG_TEXT[15];
							link.l1 = DLG_TEXT[16];
							link.l1.go = "bring_empty_bottles2";
						break;
				
						case "got_empty_bottles":
							if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
				    				|| CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS"))
							{
								PlaySound("AMBIENT\SHOP\noise4.wav");
								PlaySound("INTERFACE\button2.wav");
								PlaySound("INTERFACE\button2.wav");
								GiveItem2Character(Pchar, "Mercury_bottles");
								TakeItemFromCharacter(Pchar, "empty_bottles");
								GiveItem2Character(Pchar, "filled_medium_drawer");
								Dialog.text = DLG_TEXT[19];
								link.l1 = DLG_TEXT[20];
								link.l1.go = "got_empty_bottles2";
							}
							else
							{
								PlaySound("VOICE\ENGLISH\Eng_m_a_011.wav");
								Dialog.text = DLG_TEXT[25];
								link.l1 = DLG_TEXT[26];
								link.l1.go = "exit";
							}
						break;
				
						case "neutral":
							PlaySound("VOICE\ENGLISH\Eng_m_a_011.wav");
							Dialog.text = DLG_TEXT[0];
							link.l1 = DLG_TEXT[1];
							link.l1.go = "exit";
						break;
					}
				}
			}
			
			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "doctor":
			PlaySound("VOICE\ENGLISH\Eng_m_a_008.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "doctor2";
		break;
	
		case "doctor2":
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";			
			AddDialogExitQuest("back_in_redmond9");
		break;

		case "bandages":
			TakeNItems(Pchar, "Medical1", 2);
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";			
			AddDialogExitQuest("back_in_redmond11");
		break;

		case "hint_green_door":
			PlaySound("VOICE\ENGLISH\Eng_m_a_010.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "hint_green_door2";
		break;

		case "hint_green_door2":
			PlaySound("VOICE\ENGLISH\Eng_m_a_011.wav");
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "hint_green_door3";
		break;

		case "hint_green_door3":
			PlaySound("VOICE\ENGLISH\Eng_m_a_009.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			Diag.TempNode = "hint_green_door3";
		break;

		case "chain":
			PlaySound("VOICE\ENGLISH\Eng_m_a_010.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			AddDialogExitQuest("chain");
		break;

		case "bring_empty_bottles2":
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			if(CheckAttribute(Pchar,"quest.med_Dover2") && Pchar.quest.med_Dover2 == "inside_tailors")
			{
			
			} 
			else AddDialogExitQuest("bring_empty_bottles");
		break;

		case "got_empty_bottles2":
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "got_empty_bottles3";
		break;

		case "got_empty_bottles3":
			Pchar.quest.med_Dover = "neutral";
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("got_mercury_bottles");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
