//#include "DIALOGS\Divers_dialog.h"

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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";		
                       AddDialogExitQuest("morro_topl");			
		break;

		case "begin_29":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "begin_30";

		break;

		case "begin_30":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";		
                       AddDialogExitQuest("morro_down11");			
		break;

		case "begin_31":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "begin_32";

		break;

		case "begin_32":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "begin_33";

		break;

		case "begin_33":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "begin_34";

		break;

		case "begin_34":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "begin_35";

		break;

		case "begin_35":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
                       AddDialogExitQuest("see_ortega_valet");		
		break;

		case "begin_36":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "begin_37";

		break;

		case "begin_37":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
                       AddDialogExitQuest("square_fight3");		
		break;

		case "begin_38":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "begin_39";

		break;

		case "begin_39":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "begin_40";

		break;

		case "begin_40":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                       AddDialogExitQuest("square_fight_lucia");		
		break;

		case "begin_41":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "begin_42";

		break;

		case "begin_42":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "begin_43";

		break;

		case "begin_43":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit";
                       AddDialogExitQuest("join_ortega_garden");		
		break;

		case "begin_44":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
                       AddDialogExitQuest("queiroz_ship");		
		break;

		case "begin_45":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "begin_46";

		break;

		case "begin_46":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "begin_47";

		break;

		case "begin_47":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "begin_48";

		break;

		case "begin_48":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "begin_49";

		break;

		case "begin_49":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
                      AddDialogExitQuest("elting_info_arrest");	
		break;

		case "begin_50":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "begin_51";
		break;

		case "begin_51":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                      AddDialogExitQuest("deck_san_martin6");	
		break;

		case "begin_52":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "exit";
                      AddDialogExitQuest("fight_yardarm6");	
		break;

		case "begin_53":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "exit";
                      AddDialogExitQuest("fight_yardarm_end");	
		break;

		case "begin_54":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
                      AddDialogExitQuest("outside_fort4");	
		break;

		case "begin_55":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
                      AddDialogExitQuest("outside_fort10");	
		break;

		case "begin_56":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
                      AddDialogExitQuest("outside_fort46");	
		break;

		case "begin_57":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "begin_58";
		break;

		case "begin_58":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "exit";
                      AddDialogExitQuest("outside_fort52");	
		break;		
       
               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
               break;
	}
}
