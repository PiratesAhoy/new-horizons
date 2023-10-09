//#include "DIALOGS\Txiki Pijuan_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string current_date = iday + " " + iMonth;
	if(!CheckAttribute(npchar,"speak_date")) npchar.speak_date = current_date;

	ref PChar = GetMainCharacter();

	
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

			if(npchar.speak_date == current_date)
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = LinkRandPhrase(DLG_TEXT[40], DLG_TEXT[41], DLG_TEXT[42]);
				link.l1 = DLG_TEXT[43];
				link.l1.go = "exit";
			}
			else
			{
				if (PChar.quest.santiago == "payer") 
				{
					dialog.snd = "Voice\CLLA\CLLA001";
					dialog.text = DLG_TEXT[2];
			        link.l1 = DLG_TEXT[3];
					link.l1.go = "begin_2";
				}
				else
				{
					dialog.snd = "Voice\CLLA\CLLA002";
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
				if (CheckQuestAttribute("Santiago", "pipo"))
				{
					dialog.snd = "Voice\CLLA\CLLA001";
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";			
				}
			}
			NextDiag.TempNode = "first time";
		break;

		case "begin_2":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";

		break;
              
               case "begin_3":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";

		break;

               case "begin_4":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";

		break;

               case "begin_5":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_6";

		break;

               case "begin_6":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_7";

		break;

               case "begin_7":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";

		break;

               case "begin_8":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_9";

		break;


               case "begin_9":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";

		break;


               case "begin_10":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_11";

		break;


               case "begin_11":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_12";

		break;


               case "begin_12":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddQuestRecord("Santiago", "5");           
                        PChar.quest.santiago = "pipo";
                        Characters[GetCharacterIndex("Etienne Dupuis")].dialog.currentnode = "begin_7";
                    
                 break;

               case "begin_14":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "begin_15";

		break;

               case "begin_15":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "begin_16";

		break;

               case "begin_16":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("infobarto");

                 break;

               case "begin_17":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "begin_18";

		break;

               case "begin_18":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "begin_19";

		break;

               case "begin_19":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddQuestRecord("Santiago", "10");
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l3.disable = 0;
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l5.disable = 0;
		

		break;

               case "begin_20":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "begin_21";
		

		break;

               case "begin_21":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit_hired";

		break;


		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_hired":
			DialogExit();
			LAi_SetPlayerType (Pchar);
			NPChar.dialog.filename = "Enc_Officer_dialog.c";
			NPChar.dialog.CurrentNode = "hired";
			AddDialogExitQuest("adieurox");
			
		break;
	}
}
