	
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

			if(CheckAttribute(Pchar,"Kr_quest") && Pchar.Kr_quest != "")
			{
				switch(Pchar.Kr_quest)
				{
					case "BB_tower":
						if(NPChar.sex == "man")
						{
							PlaySound("VOICE\ENGLISH\Dut_m_a_021.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");

						dialog.text = DLG_TEXT[8];
						link.l1 = DLG_TEXT[9];  
						link.l1.go = "BB_tower1";
					break;

					case "items_needed":
						if(NPChar.sex == "man")
						{
							PlaySound("VOICE\ENGLISH\Dut_m_a_068.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");

						dialog.text = DLG_TEXT[10];
						link.l1 = DLG_TEXT[11];  
						link.l1.go = "items_needed1";
					break;

					case "salute":
						if(NPChar.sex == "man")
						{
							PlaySound("VOICE\ENGLISH\alarm1.wav");
						}
						else PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");

						dialog.text = DLG_TEXT[35];
						link.l1 = DLG_TEXT[36];  
						link.l1.go = "exit";
					break;

					case "6_locations":
						if(NPChar.sex == "man")
						{
							PlaySound("VOICE\ENGLISH\Dut_m_a_004.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");

						dialog.text = DLG_TEXT[18];
						link.l1 = DLG_TEXT[19];  
						link.l1.go = "6_locations1";
					break;

					
				}
			}
		break;
	//----------------------------------------------------------------
		case "BB_tower1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_001.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];  
			link.l1.go = "BB_tower2";
		break;

		case "BB_tower2":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");
		
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "BB_tower3";
		break;

		case "BB_tower3":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_025.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "BB_tower4";			
		break;

		case "BB_tower4":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
		
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "exit";
		break;

		case "items_needed1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_021.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");

			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];  
			link.l1.go = "items_needed2";
		break;

		case "items_needed2":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");

			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];  
			link.l1.go = "items_needed3";
		break;

		case "items_needed3":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_067.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");

			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];  
			link.l1.go = "exit";
		//	AddDialogExitQuest("items_needed_done");
		break;

		case "6_locations1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");

			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];  
			link.l1.go = "townhall";
			link.l2 = DLG_TEXT[22];  
			link.l2.go = "fort";
			link.l3 = DLG_TEXT[23];  
			link.l3.go = "shipyard";
			link.l4 = DLG_TEXT[24];  
			link.l4.go = "church";
			link.l5 = DLG_TEXT[25];  
			link.l5.go = "tailor";
			link.l6 = DLG_TEXT[26];  
			link.l6.go = "red_house";
		break;
		
		case "townhall":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_001.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");
	
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];  
			link.l1.go = "townhall1";
		break;

		case "townhall1":	
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");

			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];  
			link.l1.go = "townhall2";
		break;

		case "townhall2":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "exit";
		break;

		case "fort":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			}
			else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");

			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];  
			link.l1.go = "exit";
		break;

		case "shipyard":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_004.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
	
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];  
			link.l1.go = "shipyard1";
		break;

		case "shipyard1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "exit";
		break;

		case "church":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_004.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
	
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];  
			link.l1.go = "church1";
		break;

		case "church1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "exit";
		break;

		case "tailor":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_004.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
	
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];  
			link.l1.go = "tailor1";
		break;

		case "tailor1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "exit";
		break;

		case "red_house":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_004.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
	
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "red_house1";
		break;

		case "red_house1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "red_house1";
		break;

		case "red_house2":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");
	
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
		break;


		case "Exit":
			DialogExit();
		//	Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
