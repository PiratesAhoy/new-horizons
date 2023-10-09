	
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
						if(CheckAttribute(Pchar,"BB_tower") )
						{
							if(Pchar.BB_tower == "info1" || Pchar.BB_tower == "info2")
							{
								link.l1.go = "exit";
							}
						}
						else link.l1.go = "BB_tower1";
					break;

					case "items_needed":
						if(NPChar.sex == "man")
						{
							PlaySound("VOICE\ENGLISH\Dut_m_a_068.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");

						if(CheckAttribute(Pchar,"BB_items") && Pchar.BB_items == "info1")
						{
							dialog.text = DLG_TEXT[12];
							link.l1 = DLG_TEXT[17];  
							link.l1.go = "exit";
						}
						else
						{
							dialog.text = DLG_TEXT[10];
							link.l1 = DLG_TEXT[11];  
							link.l1.go = "items_needed1";
						}
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

			Pchar.BB_tower = "info1";
			AddDialogExitQuest("BB_tower_info1");
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
			Pchar.BB_items = "info1";
			AddDialogExitQuest("BB_tower_info5");
		break;

		case "6_locations1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");

			dialog.text = DLG_TEXT[20];
			if(CheckAttribute(Pchar, "Kr_password") && Pchar.Kr_password == "known")
			{
				//if got the letter and password no need for info about townhall

			}
			else
			{
				if(CheckAttribute(Pchar,"BB_TH") && Pchar.BB_TH == "knowledge2")
				{

				}
				else
				{
					link.l1 = DLG_TEXT[21];  
					link.l1.go = "townhall";
				}
			}

			if(CheckAttribute(Pchar, "Kr_password") && Pchar.Kr_password == "known")
			{

			}
			else
			{
				if(CheckAttribute(Pchar,"BB_fort") && Pchar.BB_fort == "knowledge")
				{
					link.l2 = DLG_TEXT[22];
					link.l2.go = "fort"; 
				}
				else
				{
					link.l2 = DLG_TEXT[52];
					link.l2.go = "fort"; 
				}
			}
			
			if(CheckAttribute(Pchar, "BB_shya") && Pchar.BB_shya == "knowledge")
			{

			}
			else
			{
				link.l3 = DLG_TEXT[23];  
				link.l3.go = "shipyard";
			}

			if(CheckAttribute(Pchar, "BB_churches") && Pchar.BB_churches == "knowledge")
			{

			}
			else
			{
				link.l4 = DLG_TEXT[24];  
				link.l4.go = "church";
			}

			if(CheckAttribute(Pchar, "BB_tailor") && Pchar.BB_tailor == "knowledge")
			{

			}
			else
			{
				link.l5 = DLG_TEXT[25];  
				link.l5.go = "tailor";
			}

			if(CheckAttribute(Pchar,"BB_RH_exit") && Pchar.BB_RH_exit == "knowledge")
			{

			}
			else
			{
				link.l6 = DLG_TEXT[26];  
				link.l6.go = "red_house";
			}

			link.l7 = DLG_TEXT[54];  
			link.l7.go = "exit";
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
			if(CheckAttribute(Pchar,"BB_TH") && Pchar.BB_TH == "knowledge")
			{
				link.l1 = DLG_TEXT[28];  
				link.l1.go = "exit";
				Pchar.BB_TH = "knowledge2";
				AddDialogExitQuest("KR_letter_info2");
			}
			else
			{
				link.l1 = DLG_TEXT[32];  	//skip this one if TH is known 
				link.l1.go = "townhall2";
			}
		break;

		case "townhall2":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[27];	//skip this one if TH is known 
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "exit";
			Pchar.BB_TH = "knowledge2";
			AddDialogExitQuest("KR_letter_info1");
		break;

		case "fort":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			}
			else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");

			if(CheckAttribute(Pchar,"BB_fort") && Pchar.BB_fort == "knowledge")
			{
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];  
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[53];
				link.l1 = DLG_TEXT[28];  
				link.l1.go = "exit";
				Pchar.BB_fort = "knowledge";
				AddQuestRecord("KR_cutlasses","1");
			}
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
			Pchar.BB_shya = "knowledge";
			AddQuestRecord("KR_flagchest","1");
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
			AddQuestRecord("KR_amulet","1");
			AddQuestRecord("KR_amulet","2");
			Pchar.BB_churches = "knowledge";
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
			AddQuestRecord("KR_tricorn","1");
			AddQuestRecord("KR_tricorn","2");
			Pchar.BB_tailor = "knowledge";

			SetLocatorRadius(locations[FindLocation("Nueva_Suecia_upper_town")], "quest", "see_oriel", 1.5);
			Locations[FindLocation("Nueva_Suecia_upper_town")].locators_radius.quest.see_oriel = 1.5;
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
			AddQuestRecord("KR_logbook","1");
		break;

		case "red_house1":
			if(NPChar.sex == "man")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			}
			else PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
	
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "red_house2";
			AddQuestRecord("KR_logbook","2");
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
			AddQuestRecord("KR_logbook","4");
			Pchar.BB_RH_exit = "knowledge";
		break;

		case "Exit":
			DialogExit();
		//	Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
