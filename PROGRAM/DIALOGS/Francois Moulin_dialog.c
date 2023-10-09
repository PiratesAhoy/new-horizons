//#include "DIALOGS\Franзois Moulin_dialog.h"

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

	Preprocessor_Add("AntoineChamfort", GetMySimpleName(CharacterFromID("Antoine Chamfort")));
	Preprocessor_Add("Chamfort", GetMyLastName(CharacterFromID("Antoine Chamfort")));

	
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
			
			if (PChar.quest.Missingman == "voirmoulin") 
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[2];
			        link.l1 = DLG_TEXT[3];
				link.l1.go = "begin";
                        }
			else
			{
				dialog.snd = "Voice\CLLA\CLLA002";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			
			}
			
			NextDiag.TempNode = "first time";
		break;

                case "begin":

			dialog.snd = "Voice\CLLA\CLLA003";
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

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_4";
			
		break;
              
                case "begin_4":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_5";
		break;

                case "begin_5":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_6";
		break;

               case "begin_6":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_7";
		break;

               case "begin_7":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_8";
		break;



		case "begin_8":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("directionlefort");
		break;

                case "begin_9":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";
		break;

                case "begin_10":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_11";
		break;

                
                case "begin_11":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("retourprince");

		break;

                case "begin_12":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_13";
                        link.l2 = DLG_TEXT[24];
			link.l2.go = "begin_14";
		break;

                case "begin_13":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("justebijou");

		break;
                
                case "begin_14":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("lesdeuxchoses");

		break;
               
                case "begin_15":

			Dialog.Text = DLG_TEXT[25];
	                Link.l1 = DLG_TEXT[26];
		        Link.l1.go = "exit";
			
		break;
              

              
              case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;

              
	}
}
