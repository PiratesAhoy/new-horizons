	
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
			Dialog.snd = "voice\PADI\PADI001";

			if(NPChar.id == "french_surgeon2")
			{
				if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
				{
					PlaySound("VOICE\ENGLISH\fre_m_a_076.wav");			
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];  
					link.l1.go = "exit";
					AddDialogExitQuest("leave_french_surgeon2"); 
				}
				else
				{
					PlaySound("VOICE\ENGLISH\fre_m_a_001.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "french_surgeon2_A";
				}
			}
			if(NPChar.id == "french_surgeon3")
			{
				if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
				{
					PlaySound("VOICE\ENGLISH\fre_m_b_049.wav");			
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];  
					link.l1.go = "exit";
					AddDialogExitQuest("leave_french_surgeon3"); 
				}
				else
				{
					PlaySound("VOICE\ENGLISH\fre_m_b_020.wav");
					Dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "french_surgeon3_A";
				}
			}
			if(NPChar.id == "french_surgeon1")
			{
				if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
				{
					PlaySound("VOICE\ENGLISH\fre_m_c_008.wav");		
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];  
					link.l1.go = "exit";
					AddDialogExitQuest("leave_french_surgeon1"); 
				}
				else
				{
					PlaySound("VOICE\ENGLISH\fre_m_c_011.wav");
					Dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					link.l1.go = "french_surgeon1_A";
				}
			}
			if(NPChar.id == "french_surgeon4")
			{
				PlaySound("VOICE\ENGLISH\Dupin_help.wav");		
				dialog.text = DLG_TEXT[44];
				link.l1 = DLG_TEXT[45];  
				link.l1.go = "french_surgeon4_A";
			}
			if(NPChar.id == "fake_Ogeron")
			{
				if(CheckAttribute(Pchar, "Tgovernor") && Pchar.Tgovernor == "yes")
				{
					PlaySound("VOICE\ENGLISH\fre_m_c_049.wav");		
					dialog.text = DLG_TEXT[42];
					link.l1 = DLG_TEXT[11];  
					link.l1.go = "exit";
					AddDialogExitQuest("leave_french_surgeon4");
				}
				else
				{
					PlaySound("VOICE\ENGLISH\fre_m_c_042.wav");		
					dialog.text = DLG_TEXT[40];
					link.l1 = DLG_TEXT[41];  
					link.l1.go = "Ogeron_A";
				}
			}
		break;

	//----------------------------------------------------------------
		case "french_surgeon2_A":
			PlaySound("VOICE\ENGLISH\fre_m_a_018.wav");			
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "french_surgeon2_B";
		break;
	
		case "french_surgeon2_B":
			PlaySound("VOICE\ENGLISH\fre_m_a_010.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "french_surgeon2_C";
		break;

		case "french_surgeon2_C":
			PlaySound("VOICE\ENGLISH\fre_m_a_038.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "french_surgeon2_D";
		break;
	
		case "french_surgeon2_D":
			PlaySound("VOICE\ENGLISH\fre_m_a_072.wav");			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "french_surgeon2_E";
		break;

		case "french_surgeon2_E":
			PlaySound("VOICE\ENGLISH\fre_m_a_076.wav");			
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("leave_french_surgeon2"); 
		break;
	//----------------------------------------------------------------
		case "french_surgeon3_A":
			PlaySound("VOICE\ENGLISH\fre_m_b_035.wav");			
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];  
			link.l1.go = "french_surgeon3_B";
		break;
		
		case "french_surgeon3_B":
			PlaySound("VOICE\ENGLISH\fre_m_b_052.wav");				
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];  
			link.l1.go = "french_surgeon3_C";
		break;

		case "french_surgeon3_C":
			PlaySound("VOICE\ENGLISH\fre_m_b_072.wav");				
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];  
			link.l1.go = "french_surgeon3_D";
		break;
	
		case "french_surgeon3_D":
			PlaySound("VOICE\ENGLISH\fre_m_b_007.wav");				
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];  
			link.l1.go = "french_surgeon3_E";
		break;

		case "french_surgeon3_E":
			PlaySound("VOICE\ENGLISH\fre_m_b_003.wav");				
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];  
			link.l1.go = "french_surgeon3_F";
		break;

		case "french_surgeon3_F":
			PlaySound("VOICE\ENGLISH\fre_m_b_049.wav");				
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("leave_french_surgeon3"); 
		break;
	//----------------------------------------------------------------
		case "french_surgeon1_A":
			PlaySound("VOICE\ENGLISH\fre_m_c_004.wav");			
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];  
			link.l1.go = "french_surgeon1_B";
		break;
		
		case "french_surgeon1_B":
			PlaySound("VOICE\ENGLISH\fre_m_c_057.wav");			
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];  
			link.l1.go = "french_surgeon1_C";
		break;

		case "french_surgeon1_C":
			PlaySound("VOICE\ENGLISH\fre_m_c_035.wav");			
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];  
			link.l1.go = "french_surgeon1_D";
		break;
	
		case "french_surgeon1_D":
			PlaySound("VOICE\ENGLISH\fre_m_c_003.wav");			
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];  
			link.l1.go = "french_surgeon1_E";
		break;

		case "french_surgeon1_E":
			PlaySound("VOICE\ENGLISH\fre_m_c_032.wav");			
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];  
			link.l1.go = "french_surgeon1_F";
		break;

		case "french_surgeon1_F":
			PlaySound("VOICE\ENGLISH\fre_m_c_075.wav");			
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];  
			link.l1.go = "french_surgeon1_G";
		break;

		case "french_surgeon1_G":
			PlaySound("VOICE\ENGLISH\fre_m_c_005.wav");		
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];  
			link.l1.go = "french_surgeon1_H";
		break;

		case "french_surgeon1_H":
			PlaySound("VOICE\ENGLISH\fre_m_c_008.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("leave_french_surgeon1");
		break;




	//----------------------------------------------------------------

		case "Ogeron_A":
			PlaySound("VOICE\ENGLISH\fre_m_c_043.wav");		
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];  
			link.l1.go = "exit";
			AddDialogExitQuest("Ogeron_done"); 
		break;

	//----------------------------------------------------------------

		case "french_surgeon4_A":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");			
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];  
			link.l1.go = "french_surgeon4_B";
		break;

		case "french_surgeon4_B":
			PlaySound("VOICE\ENGLISH\Dupin_alright.wav");			
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];  
			link.l1.go = "french_surgeon4_C";
		break;

		case "french_surgeon4_C":
			PlaySound("VOICE\ENGLISH\Dupin_know.wav");			
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];  
			link.l1.go = "french_surgeon4_D";
		break;

		case "french_surgeon4_D":
			PlaySound("VOICE\ENGLISH\Dupin_safari.wav");			
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];  
			link.l1.go = "french_surgeon4_E";
		break;

		case "french_surgeon4_E":
			PlaySound("VOICE\ENGLISH\Dupin_jungle.wav");			
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];  
			link.l1.go = "french_surgeon4_F";
		break;

		case "french_surgeon4_F":
			PlaySound("VOICE\ENGLISH\Dupin_good_day.wav");			
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];  
			link.l1.go = "exit";
			AddDialogExitQuest("leave_french_surgeon4");
		break;
			
		case "Exit":
			DialogExit();
		//	Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
