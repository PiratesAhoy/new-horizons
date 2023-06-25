//#include "DIALOGS\Octave Fabre_dialog.h"

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
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			

                if (PChar.quest.Firstcontact == "oldadmiral")
			{
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "begin_1";	
			}
		break;
                 
                case "begin_1":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
						Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_2";
               break;
                
                case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_3";
		break;

                case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_4";
		break;
               
                case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			SetNextWeather("Day Storm");
			AddDialogExitQuest("pap_storm");
		break;

//PB: Small Chest -->
		case "Smallchest":
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Smallchest2";
		break;

		case "Smallchest2":
			Dialog.Text = DLG_TEXT[20];
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				Link.l1 = GetDataDay() + " " + GetMonthName(GetDataMonth()) + " " + GetDataYear() + DLG_TEXT[22];
			}
			else
			{
				Link.l1 = GetDataDay() + " " + GetMonthName(GetDataMonth()) + " " + GetDataYear() + DLG_TEXT[21];
			}
			Link.l1.go = "exit";
			AddDialogExitQuest("jela");
		break;
//PB: Small Chest <--
              
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
