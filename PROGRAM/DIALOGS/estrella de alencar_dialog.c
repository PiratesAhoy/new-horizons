//#include "DIALOGS\estrella de alencar_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	ref PChar;
	PChar = GetMainCharacter();


	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
//			Dialog.snd = "voice\SYBO001\SYBO001";

			
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = pcharrepphrase(DLG_TEXT[2], DLG_TEXT[3]);
			link.l1.go = "Second time";
			NextDiag.TempNode = "Second time";
		break;

		case "Second time":
		
			if(CheckCharacterItem(Pchar,"estrella_token"))
				{
				dialog.Text = DLG_TEXT[4] + GetMyName(Pchar) + DLG_TEXT[5];
				if (CheckQuestAttribute("talk_to_armand", "talk"))
				{
					Link.l1 = DLG_TEXT[6];
					Link.l1.go = "report_node1";
				}
				else
				{
					Link.l2 = DLG_TEXT[7];
					Link.l2.go = "exit";
				}
			}
			else
			{
			Dialog.text = DLG_TEXT[8];
				if(CheckCharacterItem(Pchar,"Letter_Reward"))
				{
					link.l1 = DLG_TEXT[9];
					link.l1.go = "letter_yes";
				}
				else
				{
					link.l1 = DLG_TEXT[10];
					link.l1.go = "letter_no";
				}
			}					
		break;
		
		case "letter_yes":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "letter_reward";			
		break;

		case "letter_reward":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "help_estrella2";	
		break;
		
		case "letter_no":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "help_estrella";	
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit";		
		break;
				
		case "help_estrella":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19] + GetMySimpleName(Pchar) + DLG_TEXT[21] + GetMyShipNameShow(PChar) + DLG_TEXT[22];
			if(makeint(PChar.reputation)>=6)
			{
				Link.l1.go = "eda_node1";
			}
			else
			{
				Link.l1.go = "eda_node2";
			}
			link.l2 = DLG_TEXT[23];
			Link.l2.go = "exit";
		break;
		
		case "help_estrella2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25] + GetMySimpleName(Pchar) + DLG_TEXT[27] + GetMyShipNameShow(PChar) + DLG_TEXT[28];
			if(makeint(PChar.reputation)>=6)
			{
				Link.l1.go = "eda_node1";
			}
			else
			{
				Link.l1.go = "eda_node2";
			}
			link.l2 = DLG_TEXT[29];
			Link.l2.go = "exit";
		break;
		
		case "eda_node1":
			dialog.text = DLG_TEXT[30] + PChar.lastname + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32] + GetMyName(Pchar) + DLG_TEXT[33];
			if(CheckCharacterItem(Pchar,"Letter_Reward"))
			{
				Link.l1.go = "eda_node3";
			}
			else
			{
				Link.l1.go = "eda_node3a";
			}
		break;		
		
		case "eda_node2":
			dialog.text = DLG_TEXT[34] + PChar.lastname + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";			
		break;			
			
		case "eda_node3":
			dialog.text = DLG_TEXT[37] + GetMyName(Pchar) + DLG_TEXT[38];
			TakeItemFromCharacter(Pchar,"Letter_Reward");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 5000);
			link.l1 = DLG_TEXT[39];
			link.l1.go = "eda_node4";	
		break;
		
		case "eda_node3a":
			dialog.text = DLG_TEXT[40] + GetMyName(Pchar) + DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";			
		break;
		
		case "eda_node4":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "eda_node5";	
		break;
		
		case "eda_node5":
			dialog.text = DLG_TEXT[45] + GetMyName(Pchar) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "eda_node6";	
		break;
		
		case "eda_node6":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "eda_node7";	
		break;

		case "eda_node7":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "eda_node8";	
		break;		

		case "eda_node8":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "eda_node9";	
		break;	
		
		case "eda_node9":
			dialog.text = DLG_TEXT[54] + GetMyName(Pchar) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "eda_node10";	
		break;

		case "eda_node10":
			dialog.text = DLG_TEXT[57] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[58] + GetMyName(Pchar) + DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "eda_node11";	
		break;		

		case "eda_node11":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "eda_node12";	
		break;

		case "eda_node12":
			dialog.text = DLG_TEXT[63];
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 6924);
			link.l1 = DLG_TEXT[64];
			link.l1.go = "eda_node13";	
		break;

		case "eda_node13":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "eda_node14";	
		break;

		case "eda_node14":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "eda_node15";	
		break;

		case "eda_node15":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "eda_node16";	
		break;

		case "eda_node16":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "eda_node17";	
		break;

		case "eda_node17":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "eda_node18";	
		break;

		case "eda_node18":
			dialog.text = DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "eda_node19";	
		break;

		case "eda_node19":
			dialog.text = DLG_TEXT[78] + GetMyName(Pchar) + DLG_TEXT[79];
			GiveItem2Character(Pchar,"estrella_token");
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit_gotoQC";	
			AddQuestRecord("estrella", 1);
		break;
		
		case "exit_gotoQC":
			AddDialogExitQuest("Story_gotoQC");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "report_node1":
			dialog.text = DLG_TEXT[81];
			TakeItemFromCharacter(Pchar,"estrella_token");
			ChangeCharacterAddressGroup(characterFromID("Estrella Disguised"), "Muelle_town_01", "goto", "goto95");
			link.l1 = DLG_TEXT[82];
			link.l1.go = "report_node2";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1250);
				AddPartyExpChar(pchar, "Sneak", 13);
			}
			else { AddPartyExp(pchar, 1250); }
		break;
		
		case "report_node2":
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[83] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "report_node3";	
			ChangeCharacterReputation(pchar, +1);	
		break;		

		case "report_node3":
			dialog.text = DLG_TEXT[86] + GetMyName(Pchar) + DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "report_node4";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 5000);	
		break;	
		
		case "report_node4":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "report_node5";	
		break;			
		
		case "report_node5":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "report_node6";	
		break;			

		case "report_node6":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit_Estrella_Reload_to_IMGate";
			AddQuestRecord("estrella", 4);	
		break;
		
		case "exit_Estrella_Reload_to_IMGate":
			AddDialogExitQuest("Story_Estrella_Reload_to_IMGate");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
				
	}
}
