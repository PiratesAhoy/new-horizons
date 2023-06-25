//#include "DIALOGS\Skull_dialog.h"

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
		// ----------------------------------- -иалог первый - первая вс=реча
		// ----------------- TALISMAN changes done to make Skull give piece of Treasure map to Player in Jack Sparrow Story
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

			NextDiag.TempNode = "first time";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			// NK -->
			if(GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY && HaveLetterOfMarque(PIRATE)) // PB: Added LoM check
			{
				dialog.text = "I'm busy.";
			}
			// NK <--
			if (GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY) // PB
			{
                if (GetLetterOfMarqueQuantity() == 0 && !HaveLetterOfMarque(PIRATE)) // PB
    			{
    				dialog.text = DLG_TEXT[34];
    				link.l1 = DLG_TEXT[35];
    				link.l1.go = "piratefun";
    				link.l2 = DLG_TEXT[36];
    				link.l2.go = "exit";
    			}
    		}

			if ( CheckQuestAttribute("Jacks_early_days","Words_from_Skull") )
			{
				dialog.text = DLG_TEXT[42];
				link.l1 = DLG_TEXT[43];
				link.l1.go = "Exit_Skull";
			}
			if ( CheckQuestAttribute("Jacks_early_days","More_Words_from_Skull") )
			{
				dialog.text = DLG_TEXT[44];
				link.l1 = DLG_TEXT[62];  // TALISMAN changed
				link.l1.go = "More_Skull";
			}
			if ( CheckQuestAttribute("Jacks_early_days","Ready_for_sea") )
			{
				dialog.text = DLG_TEXT[54];
				link.l1 = DLG_TEXT[55];
				link.l1.go = "Exit_for_sea";
			}
			if ( CheckQuestAttribute("Jacks_early_days","Try_to_join_Skull") )
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3] + GetMyFullName(Pchar) + DLG_TEXT[4];
				link.l1.go = "More_join_talk";
			}			
		break;

		case "piratefun": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "piratefun2";
			link.l2 = DLG_TEXT[39];
			link.l2.go = "exit";
			//AddDialogExitQuest("piratefun");
		break;

		case "piratefun2": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("piratefun");
		break;

//		case "More_Skull":    <---------Original replaced by TALISMAN
//			dialog.text = DLG_TEXT[46];
//			link.l1 = DLG_TEXT[47];
//			link.l1.go = "More_Skull2";
//		break;

		case "More_Skull":  // New cases by TALISMAN ---->
			int tmpdiamond = GetCharacterItem(pChar, "jewelry2");  
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[45];
			if (tmpdiamond <= 1)
			{
			link.l1.go = "More_SkullA";
			}
			if (tmpdiamond >= 2)
			{
			link.l1.go = "More_Skull2";
			}
		break;

		case "More_SkullA":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "More_SkullB";
		break;	 
		
		case "More_SkullB":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_for_Fight";
		break;  // <---- TALISMAN end of new case
			
		case "More_Skull2":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "More_Skull21";
		break;
		
		case "More_Skull21": // TALISMAN new case
		dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "More_Skull3";
		break;

		case "More_Skull3":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "More_Skull4";
		break;

		case "More_Skull4":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit";
			AddDialogExitQuest("Skull_not_Happy");
		break;

		case "More_join_talk":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "More_join_talk2";
		break;		
		
		case "More_join_talk2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "More_join_talk3";
		break;

		case "More_join_talk3":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "More_join_talk4";
		break;

		case "More_join_talk4":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "More_join_talk5";
		break;		

		case "More_join_talk5":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "More_join_talk6";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "Ready_for_Fight";
		break;
		
//		case "More_join_talk6":  < --- Original replaced by TALISMAN
//			if (makeint(pchar.money) <= 2099)
//			{
//			dialog.text = DLG_TEXT[16];
//			link.l1 = DLG_TEXT[19];
//			link.l1.go = "Exit_for_Fight";
//			}
//			if (makeint(pchar.money) >= 2100)
//			{
//			dialog.text = DLG_TEXT[17];
//			link.l1.go = "Exit_get_hostages";
//			AddMoneyToCharacter(pchar, -2100);			
//			}			
//		break;

		case "More_join_talk6":  // New Cases by TALISMAN --->
			int tmpjewel = GetCharacterItem(pChar, "jewelry2");  
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			if ((makeint(pchar.money) <= 2099) && (tmpjewel >= 2))
			{
			link.l1.go = "More_join_talk6c";
			}
			if ((makeint(pchar.money) <= 2099) && (tmpjewel <= 1))
			{
			link.l1.go = "More_join_talk6c";
			}
			if ((makeint(pchar.money) >= 2100) && (tmpjewel <= 1))
			{
			link.l1.go = "More_join_talk6d";
			}
			if ((makeint(pchar.money) >= 2100) && (tmpjewel >= 2))
			{
			link.l1.go = "More_join_talk6e";
			}
		break;
		
		case "More_join_talk6a":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "More_join_talk6b";
			AddMoneyToCharacter(pchar, -2100);
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
		break;
		
		case "More_join_talk6b":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_get_hostages";
		break;
		
		case "More_join_talk6c":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_for_Fight";
		break;
		
		case "More_join_talk6d":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_for_Fight";
		break;
		
		case "More_join_talk6e":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "More_join_talk6a";
		break; // <--- TALISMAN end
		
		case "Ready_for_fight":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_for_Fight";
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Skull":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Round_the_Room");
		break;

		case "Exit_for_sea":
			DialogExit();
			TakeItemFromCharacter(Pchar,"jewelry2"); // TALISMAN added
			TakeItemFromCharacter(Pchar,"jewelry2"); // TALISMAN added
			GiveItem2Character(Pchar,"Map_Doc_3");
			AddQuestRecord("Aztec", 8);
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Now_to_ships");
		break;
		
		case "Exit_get_hostages":
			DialogExit();
			GiveItem2Character(Pchar,"Map_Doc_3");  //TALISMAN added
			AddQuestRecord("Aztec", 8);             //TALISMAN added
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Now_find_Barbossa");
		break;

		case "Exit_for_Fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Fight_with_skull");
		break;		
	}
}
