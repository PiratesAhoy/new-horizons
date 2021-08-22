//#include "DIALOGS\Armand Delacroix_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	//DeathDaisy -->
	string Frere;
	string Ami;
	if(PChar.sex == "woman")
	{
		Frere = "ma sœur";
		Ami = "m'amie";
	}
	else
	{
		Frere = "mon frére";
		Ami = "mon ami";
	}
	Preprocessor_Add("smarmy", Frere); 
	Preprocessor_Add("friend", Ami);
	// DeathDaisy <--
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Äèàëîã ïåðâûé - ïåðâàÿ âñòðå÷à

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "Exit_GiveRum":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_SitAndDrinkWithDelacroix");
		break;
		
		case "Exit_Giddy":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
//			LAi_QuestDelay("stand_up", 0.001);
			LAi_SetPlayerType(Pchar); // GR
			AddDialogExitQuest("Story_SitAndDrinkWithDelacroix3");
		break;
		
		case "Exit_StageLeft":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Exit_StageLeft");
		break;
		
		case "First time":
			Dialog.defAni = "Sit_Right_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_2";
			Dialog.cam = "1";
			
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "First time_1";	
		break;

		case "First time_1":
			d.Text = RandSwear() +  DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Story_first talk";	
			pchar.quest.talk_to_armand = "talk";
		break;

		case "Story_first talk":
			Dialog.defAni = "Sit_Right_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÌÀ\VIÌÀ003";
			
			d.Text =  RandSwear() +  DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			Link.l1.go = "Node_2";	
		break;

		case "Node_2":
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "Node_3";
		break;

		case "Node_3":
			d.Text = DLG_TEXT[9] + GetAddressForm(ADDR_CIVIL, FRANCE, chrsex(PChar)) + DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Node_4";
		break;

		case "Node_4":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ006";
			d.Text = DLG_TEXT[12] + GetAddressForm(ADDR_CIVIL, FRANCE, chrsex(PChar)) + DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Node_5";
		break;

		case "Node_5":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ007";
			Diag.TempNode = "SitAndDrink";
			d.Text = DLG_TEXT[15]; 
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Exit_GiveRum";
		break;

		case "SitAndDrink":
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Look_Around";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÌÀ\VIÌÀ008";
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "Node_7";
		break;

		case "Node_7":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ009";
			d.Text = DLG_TEXT[19] + GetMyName(Pchar) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "node_8";
		break;
	
		case "Node_8":
			Preprocessor_Add("friend", FirstLetterUp(Ami));
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Node_9";
		break;
	
		case "Node_9":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ011";
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Node_10";
		break;

		case "Node_10":
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Node_11";
		break;

		case "Node_11":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ013";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Node_11a";			
		break;
		
		case "Node_11a":
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Node_12";
		break;

		case "Node_12":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ014";
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "Node_13";
		break;

		case "Node_13":
			d.Text = DLG_TEXT[34] + GetMyName(Pchar) + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Node_14";
		break;
		
		case "Node_14":
			Preprocessor_Add("smarmy", FirstLetterUp(Frere)); // DeathDaisy
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "Node_15";
		break;
		
		case "Node_15":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ018";
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "Node_16";
		break;
		
		case "Node_16":
			d.Text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Node_16a";
		break;
		
		case "Node_16a":
			d.Text = DLG_TEXT[43] + GetMyName(Pchar) + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "thanks";
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit_leave";
			AddQuestRecord("estrella", 2);
		break;
		
		case "thanks":
			string ThankYou = DLG_TEXT[47];
			switch(PChar.sex){
				case "woman":
					ThankYou = DLG_TEXT[71];
				break;
			}
			d.Text = ThankYou;
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "money";
		break;
		
		case "money":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ019";
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "risks";
		break;
		
		case "risks":
			d.Text = DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "risks_2";
		break;
		
		case "risks_2":
			Dialog.snd = "voice\VIÌÀ\VIÌÀ014";
			d.Text = DLG_TEXT[53] + GetMyName(Pchar) + DLG_TEXT[54];
			Link.l1 = DLG_TEXT[55];
			Link.l1.go = "risks_3";
		break;
		
		case "risks_3":
			d.Text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "exit_giddy";
		break;
		
		case "giddy":
			Dialog.tempNode = "giddy";
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "Node_17";
		break;
		
		case "Node_17":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "Node_18";
		break;
		
		case "Node_18":
			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "lasttalk";
		break;
	
		case "lasttalk":
			d.Text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "Exit_StageLeft";
			AddQuestRecord("estrella", 3);
		break;
		
		case "reunited_flight":
			d.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "reunited_flight2";
		break;

		case "reunited_flight2":
			d.Text = DLG_TEXT[68] + GetMyName(Pchar) + DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "exit_farewell";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 10000);
		break;
		
		case "exit_farewell":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_estrella_farewell");
		break;
		
		case "exit_leave":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Armand_refused");
		break;

		
		}
}

