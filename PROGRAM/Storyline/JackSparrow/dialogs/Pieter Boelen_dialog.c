//#include "DIALOGS\Pieter Boelen_dialog.h"

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

			if(CheckQuestAttribute("Turks_and_the_French", "talk_is_over"))
				{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[49] + PChar.lastname + DLG_TEXT[50];
			        link.l1 = DLG_TEXT[51];
				link.l1.go = "begin Turks with Boelen";
				} else{			
			
			if (makeint(pchar.rank) > 10 && PChar.quest.Turkshelp == "") 
			{
			if(CheckQuestAttribute("Turks_and_the_French", "powers_of_persuation"))
				{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[26];
			        link.l1 = DLG_TEXT[27] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[28];
				link.l1.go = "begin Turks with Norrington";
				} else{
			
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[2];
			        link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar);
				link.l1.go = "begin";
				}
			}
			else
			{
			if(CheckQuestAttribute("Turks_and_the_French", "powers_of_persuation"))
				{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[26];
			        link.l1 = DLG_TEXT[27] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[28];
				link.l1.go = "begin Turks with Norrington";
				} else{			
				dialog.snd = "Voice\CLLA\CLLA002";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";			
				}
					}
			}
			
			NextDiag.TempNode = "first time";
		break;

		case "begin":

			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "begin_2";
		break;

		case "begin_2":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "begin_3";

		break;

                case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "begin_4";

		break;

		case "begin_4":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_5";
			link.l2 = DLG_TEXT[13];
                        link.l2.go = "begin_7";
		break;
              
                case "begin_5":
			LAi_SetPlayerType(pchar);
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_6";
		break;

		case "begin_6":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Turks_start_search");
		break;

                
                case "begin_7":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Turks_search_refused");

		break;

               case "begin_8":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_9";
		break;
             
               case "begin_9":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("guetteur");
                        
                break;


               case "begin_10":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_11";

		break;

               case "begin_11":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("depart");
                        
                break;

    
               case "begin_12":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_13";
		break;

              case "begin_13":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_14";

		break;
       
               case "begin_14":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("gotoport");
                        
                 break;

               case "begin_15":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_16";
		break;
              
               case "begin_16":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("aurevoir");
                        
                 break;
				 
			case "begin Turks with Norrington":
			LAi_SetActorType(characterFromID("James Norrington"));			
			LAi_ActorGoToLocator(characterFromID("James Norrington"), "goto", "goto9", "", -1);			
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Turks_with_Norrington2";

			break;			
				 
			case "Turks_with_Norrington2":
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), Pchar);			
			dialog.text = DLG_TEXT[31] + PChar.lastname + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Turks_with_Norrington3";

			break;

			case "Turks_with_Norrington3":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Turks_with_Norrington4";

			break;

			case "Turks_with_Norrington4":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Turks_with_Norrington5";

			break;
	
			case "Turks_with_Norrington5":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Turks_with_Norrington6";

			break;
	
			case "Turks_with_Norrington6":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Turks_with_Norrington7";

			break;	

			case "Turks_with_Norrington7":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Turks_with_Norrington8";

			break;

			case "Turks_with_Norrington8":
			Lai_KillCharacter(characterFromID("James Norrington"));			
			dialog.text = DLG_TEXT[44] + PChar.lastname + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Turks_with_Norrington9";

			break;

			case "Turks_with_Norrington9":
			AddMoneyToCharacter(pchar, -100000);			
			pchar.quest.Turks_and_the_French = "talk_is_over";			
			AddDialogExitQuest("Discussion_with_Norrington");			
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";

			break;

			case "begin Turks with Boelen":
			pchar.quest.Turks_and_the_French = "turks quest again";			
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Turks_with_Boelen2";

			break;
			
			case "Turks_with_Boelen2":
			LAi_SetActorType(pchar);			
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "begin_7";
			link.l2 = DLG_TEXT[12];			
            link.l2.go = "begin_5";

			break;
			
              case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;

              
	}
}
