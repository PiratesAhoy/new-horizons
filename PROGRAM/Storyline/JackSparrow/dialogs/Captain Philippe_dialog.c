//#include "DIALOGS\Captain Maximus_dialog.h"
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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;
// TALISMAN - replaced with new explanation of where bit of map came from --->
//		
//		case "Get_ready_for_Isla_de_Muerte":
//			dialog.text = DLG_TEXT[2];
//			link.l1 = DLG_TEXT[3];
//			link.l1.go = "Get_ready_for_Isla_de_Muerte2";
//		break;

		case "Get_ready_for_Isla_de_Muerte":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Get_ready_for_Isla_de_MuerteA";
		break;
		
		case "Get_ready_for_Isla_de_MuerteA":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Get_ready_for_Isla_de_Muerte2";
		break;

//// TALISMAN end <-----		

		case "Get_ready_for_Isla_de_Muerte2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Get_ready_for_Isla_de_Muerte3";
		break;
		
		case "Get_ready_for_Isla_de_Muerte3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Get_ready_for_Isla_de_Muerte";
			Locations[FindLocation("IslaDeMuerte_shore_01")].reload.l2.disable = 0;
		break;

		case "Move_the_Treasure_to_XXXXX":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Move_the_Treasure_to_XXXXX2";
		break;

		case "Move_the_Treasure_to_XXXXX2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Move_the_Treasure_to_XXXXX";
		break;

		case "Report_on_the_Doctor":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Report_on_the_Doctor2";
		break;

		case "Report_on_the_Doctor2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Report_on_the_Doctor3";
		break;

		case "Report_on_the_Doctor3":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Report_on_the_Doctor";
		break;

		case "Exit_Report_on_the_Doctor":
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			//GiveItem2Character(Pchar,"Map_Doc_4");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Go_Find_my_Ship");
		break;

		case "Exit_Get_ready_for_Isla_de_Muerte":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Maximus_Philippe_to_Isla_de_Meurte");
		break;

		case "Exit_Move_the_Treasure_to_XXXXX":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Maximus_Philippe_to_XXXXX");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
