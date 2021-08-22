	
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
		/*
			string charid;
			charid = NPChar.id;
			switch(charid)
			{
				case "Kristiania_shipyard_owner":


				break;


			}
		*/

		break;
	//----------------------------------------------------------------
		case "locked_shipyard":
			PlaySound("VOICE\ENGLISH\Dut_m_a_006.wav");			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];  
			link.l1.go = "locked_shipyard1";
		break;

		case "locked_shipyard1":
			PlaySound("VOICE\ENGLISH\Dut_m_a_010.wav");		
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "locked_shipyard2";
		break;

		case "locked_shipyard2":
			PlaySound("VOICE\ENGLISH\Dut_m_a_007.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "locked_shipyard3";			
		break;

		case "locked_shipyard3":
			PlaySound("VOICE\ENGLISH\Dut_m_a_044.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "exit";
			AddDialogExitQuest("NS_locked_shipyard_done");
		break;
	//----------------------------------------------------------------
		case "end_auction":
			PlaySound("VOICE\ENGLISH\Dut_m_a_067.wav");	//was 027		
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "exit";
			AddDialogExitQuest("end_auction_done");
		break;
	//----------------------------------------------------------------
		case "auction_over":
			PlaySound("VOICE\ENGLISH\Dut_m_a_068.wav");		
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];  
			link.l1.go = "exit";
		break;
	//----------------------------------------------------------------
		case "items_list":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");	
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "items_list1";
		break;

		case "items_list1":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_006.wav");	
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];  
			link.l1.go = "items_list2";
		break;

		case "items_list2":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");	
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];  
			link.l1.go = "items_list3";
		break;

		case "items_list3":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_021.wav");	
			dialog.text = DLG_TEXT[16];
			if(makeint(Pchar.money) >= 4000)
			{
				link.l1 = DLG_TEXT[17];  
				link.l1.go = "items_list4";
			}
			else
			{
				link.l2 = DLG_TEXT[18];  
				link.l2.go = "exit";
				AddDialogExitQuest("items_list_no_noney");
			}
		break;

		case "items_list4":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_066.wav");	
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];  
			link.l1.go = "exit";
			AddDialogExitQuest("items_list_done");
		break;

		case "thief":	
			PlaySound("VOICE\ENGLISH\gm_crew12A.wav");	
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];  
			link.l1.go = "thief1";
		break;

		case "thief1":	
			PlaySound("VOICE\ENGLISH\gm_crew12F.wav");		
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];  
			link.l1.go = "thief2";
		break;
		
		case "thief2":	
			PlaySound("VOICE\ENGLISH\gm_crew12C.wav");	
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];  
			link.l1.go = "thief3";
		break;

		case "thief3":	
			PlaySound("VOICE\ENGLISH\gm_crew12D.wav");	
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];  
			link.l1.go = "exit";
			AddDialogExitQuest("thief_done");
		break;

		case "password":	
			PlaySound("VOICE\ENGLISH\gm_crew12A.wav");	
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];  
			link.l1.go = "password1";
		break;

		case "password1":	
			PlaySound("VOICE\ENGLISH\gm_crew12E.wav");	
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];  
			link.l1.go = "password2";
		break;

		case "password2":	
			PlaySound("VOICE\ENGLISH\gm_crew12B.wav");		
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];  
			link.l1.go = "password3";
		break;

		case "password3":	
			PlaySound("OBJECTS\DUEL\woman_hit3.wav");	
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];  
			link.l1.go = "exit";
			AddDialogExitQuest("password_done");
		break;

		case "anna_helena_neutral":	
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");	
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];  
			link.l1.go = "exit";
			AddDialogExitQuest("password_done");
		break;
			
		case "monk_neutral":
			if(NPchar.id == "Kr_priest3") PlaySound("VOICE\ENGLISH\Ita_m_a_004.wav");	
			if(NPchar.id == "Kr_priest4") PlaySound("VOICE\ENGLISH\Ita_m_a_001.wav");
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[22];  
			link.l1.go = "exit";
		break;

		case "priest_neutral":	
			if(NPchar.id == "Kr_priest1") PlaySound("VOICE\ENGLISH\Spa_m_b_064.wav");	
			if(NPchar.id == "Kr_priest2") PlaySound("VOICE\ENGLISH\Spa_m_b_060.wav");	
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[22];  
			link.l1.go = "exit";
		break;

		case "cardinal_neutral":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_054.wav");	
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];  
			link.l1.go = "exit";
		break;

		case "where_is_he":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_047.wav");	
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[51];  
			link.l1.go = "where_is_he1";
		break;

		case "where_is_he1":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_001.wav");	
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[43];  
			link.l1.go = "where_is_he2";
		break;

		case "where_is_he2":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_063.wav");	
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];  
			link.l1.go = "where_is_he3";
		break;

		case "where_is_he3":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");	
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];  
			link.l1.go = "where_is_he4";
		break;

		case "where_is_he4":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");	
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];  
			link.l1.go = "exit";
			AddDialogExitQuest("where_is_he_done");
		break;

		case "chapel_monk":	
			PlaySound("VOICE\ENGLISH\Beggar_01.wav");	
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];  
			link.l1.go = "exit";
		break;

		case "townhall_neutral":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_001.wav");		
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];  
			link.l1.go = "townhall_neutral1";
		break;

		case "townhall_neutral1":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");		
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];  
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
		//	Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
