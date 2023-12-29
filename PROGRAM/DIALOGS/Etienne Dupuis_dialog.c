//#include "DIALOGS\Etienne Dupuis_dialog.h"

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
			
			
			if (CheckAttribute(Pchar,"quest.santiago") && PChar.quest.santiago == "jail_2")
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[15];
			        link.l1 = DLG_TEXT[16];
				link.l1.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\CLLA\CLLA002";
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "begin";
			
			}
			if (CheckQuestAttribute("Santiago", "pipo"))
			{
			        dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[15];
			        link.l1 = DLG_TEXT[16];
				link.l1.go = "exit";			
		
			}
			if (CheckQuestAttribute("Santiago", "payer"))
			{
			        dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[15];
			        link.l1 = DLG_TEXT[16];
				link.l1.go = "exit";			
		
			}
			if (CheckQuestAttribute("Santiago", "impayer"))
			{
                                dialog.snd = "Voice\CLLA\CLLA005";
        			dialog.text = DLG_TEXT[17];
        			if (makeint(pchar.money >= 500))
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "begin_4";
			}
			else
			{
				link.l1 = DLG_TEXT[8];
				link.l1.go = "exit";					
			}

			}
		
			NextDiag.TempNode = "first time";
		break;

		case "begin":

			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
		break;

		case "begin_2":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_2_1";

		break;

		case "begin_2_1":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_3";

		break;
              
                case "begin_3":

                        dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[20];
			if (makeint(pchar.money >= 500))
			{
				link.l1 = DLG_TEXT[7];
				link.l1.go = "begin_4";
			}
			link.l2 = DLG_TEXT[8];
			link.l2.go = "exit";
			pchar.quest.santiago = "impayer";

		break;
              
		case "begin_4":
                        PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -500);
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			pchar.quest.santiago = "payer";
			locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 0;
			AddDialogExitQuest("txikimoi");
		
			
		break;
 
               case "begin_7":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_8";

		break;

               case "begin_8":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "begin_9";

		break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddQuestRecord("Santiago", 5);
			PChar.quest.santiago = "pipo";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.Santiago.win_condition = "plusinfo";
		break;

        case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
