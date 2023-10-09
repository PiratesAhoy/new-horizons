	
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
			if(makeint(Pchar.money) >= 500)
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
			PlaySound("VOICE\ENGLISH\gr_mistress_laugh.wav");
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];  
			link.l1.go = "password2";
		break;

		case "password2":	
			PlaySound("VOICE\ENGLISH\gm_crew12B.wav");		
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[61];   
			link.l1.go = "password3";
			AddQuestRecord("KR_cutlasses","2");
			if(CheckAttribute(Pchar,"BB_fort") && Pchar.BB_fort == "knowledge")
			{
				AddQuestRecord("KR_cutlasses","1");
			}
		break;

		case "password3":	
			PlaySound("VOICE\ENGLISH\gm_crew12E.wav");		
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];   
			link.l1.go = "password4";
		break;

		case "password4":	
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");		
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];   
			link.l1.go = "password5";
		break;

		case "password5":	
			PlaySound("VOICE\ENGLISH\gm_crew12K.wav");		
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];   
			link.l1.go = "password6";
		break;

		case "password6":	
			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];   
			link.l1.go = "password7";
		break;

		case "password7":	
			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");		
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];   
			link.l1.go = "password8";
		break;
		
		case "password8":	
			PlaySound("VOICE\ENGLISH\gm_crew12G.wav");		
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[36];   
			link.l1.go = "password9";
		break;

		case "password9":	
			PlaySound("OBJECTS\DUEL\woman_hit3.wav");	
			dialog.text = DLG_TEXT[37];

			if(CheckAttribute(Pchar,"BB_fort") && Pchar.BB_fort == "knowledge")
			{
				link.l1 = DLG_TEXT[38];  
				link.l1.go = "exit";
				AddDialogExitQuest("password_done");
			}
			else
			{
				link.l1 = DLG_TEXT[73];  
				link.l1.go = "password10";
			}
		break;

		case "password10":	
			PlaySound("VOICE\ENGLISH\gm_crew12B.wav");		
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[22];   
			link.l1.go = "exit";
			AddQuestRecord("KR_cutlasses","1");
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
			AddQuestRecord("KR_amulet","4");
			AddDialogExitQuest("chapel_monk_done");
		break;

		case "chapel_monk_neutral":	
			PlaySound("VOICE\ENGLISH\Beggar_spa.wav");	
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[75];  
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

		case "outside_shipyard":	
			int iPhrase = rand(3);
			switch (iPhrase)
			{
				case 0:
					PlaySound("VOICE\ENGLISH\Dut_m_a_043.wav");
				break;

				case 1:
					PlaySound("VOICE\ENGLISH\Dut_m_a_051.wav");	
				break;

				case 2:
					PlaySound("VOICE\ENGLISH\Dut_m_a_053.wav");	
				break;

				case 3:
					PlaySound("VOICE\ENGLISH\Dut_m_a_054.wav");	
				break;	
			}

			NPChar.dlgover = true;
			DialogExit();
		break;

	//Hilpershausen
		case "captain_where":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_032.wav");
			PlaySound("VOICE\ENGLISH\Dut_m_a_032.wav");		
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];  
			link.l1.go = "captain_where1";
		break;

		case "captain_where1":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_049.wav");		//was 033		
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona26");
		break;
	//Walter
		case "commanders_here":	
			PlaySound("VOICE\ENGLISH\jrh_5.wav");		
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona27");
		break;

	//Hilpershausen
		case "recognize_Pyle":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");		
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona28");
		break;

	//Walter earlier in Kristiania
		case "Kristiania_port":
			Pchar.talked_to_Walter = "yes";
			PlaySound("VOICE\ENGLISH\jrh_3.wav");		
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];  
			link.l1.go = "exit";
		break;

	//Walter
		case "talked_to_in_port":	
			PlaySound("VOICE\ENGLISH\jrh_8.wav");		
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];  
			link.l1.go = "ship_name";
		break;

		case "seen_in_port":	
			PlaySound("VOICE\ENGLISH\jrh_8.wav");		
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[88];  
			link.l1.go = "ship_name";
		break;

		case "ship_name":	
			PlaySound("VOICE\ENGLISH\jrh_6.wav");		
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona29");
		break;

	//Hilpershausen
		case "translate_please":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_067.wav");		
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona30");
		break;

	//Walter
		case "gatenhielm":	
			PlaySound("VOICE\ENGLISH\jrh_3.wav");		
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona35");
		break;

	//Hilpershausen
		case "foul_smell":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_006.wav");		
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona38");
		break;

	//Walter
		case "no_slaver":	
			PlaySound("VOICE\ENGLISH\jrh_6.wav");		
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona39");
		break;

	//Hilpershausen
		case "stolen_uniform":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_053.wav");	//was 025		
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona39_A");
		break;

		case "which_nation":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");		
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona40");
		break;

	//Walter
		case "LOM":	
			PlaySound("VOICE\ENGLISH\jrh_4.wav");			//step 1/3		
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];  
			link.l1.go = "LOM1";
		break;

		case "LOM1":	
			PlaySound("VOICE\ENGLISH\jrh_8.wav");			//step 2/3		
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];  
			link.l1.go = "LOM2";
		break;

		case "LOM2":	
			PlaySound("VOICE\ENGLISH\jrh_7.wav");			//step 3/3		
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona43");
		break;

	//Hilpershausen
		case "one_detail":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");		
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];  
			link.l1.go = "observer";
		break;

		case "observer":	
			PlaySound("VOICE\ENGLISH\Dut_m_a_037.wav");		
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona63");
		break;

	//Walter
		case "grenadier":	
			PlaySound("VOICE\ENGLISH\jrh_7.wav");		
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona64");
		break;

		case "got_document":	
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToCharacter(NPChar, characterFromID("Hilphershausen"));

			PlaySound("VOICE\ENGLISH\jrh_8.wav");		
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona66");
		break;

	//Hilpershausen
		case "give_document":
			GiveItem2Character(pchar, "LOM_swe");
			PlaySound("INTERFACE\paper.wav");

			PlaySound("VOICE\ENGLISH\Dut_m_a_026.wav");	
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];  
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona68");
		break;



		case "Exit":
			DialogExit();
		//	Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
