
void ProcessDialogEvent()
{
	aref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makearef(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

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

			string crewid;
			crewid = NPChar.id;
			switch(crewid)
			{
		//...............................................................
		//9 OFFICERS
				case "gm_crew1":
					PlaySound("VOICE\ENGLISH\gm_crew1A.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "boatswain";
				break;

				case "gm_crew3":
					PlaySound("VOICE\ENGLISH\Eng_m_a_031.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "carpenter";
				break;

				case "gm_crew4":
					PlaySound("VOICE\ENGLISH\gm_crew4A.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "doctor";
				break;

				case "gm_crew5":
					PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "fighter_big";
				break;

				case "gm_crew10":
					PlaySound("VOICE\ENGLISH\Fre_m_c_004.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "gunner";
				break;

				case "gm_crew11":
					PlaySound("VOICE\ENGLISH\gm_crew11B.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "fighter_spanish";
				break;

				case "gm_crew18":
					PlaySound("VOICE\ENGLISH\gm_crew18A.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "quartermaster";
				break;

				case "gm_crew20":
					PlaySound("VOICE\ENGLISH\Por_m_b_027.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "first_mate";
				break;

				case "gm_crew22":
					PlaySound("VOICE\ENGLISH\gm_crew22A.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "navigator";
				break;
		//...............................................................
		//14 SAILORS
				case "gm_crew2":
					PlaySound("VOICE\ENGLISH\gm_crew2A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "sailmaker";
				break;

				case "gm_crew6":
					PlaySound("OBJECTS\DUEL\man_hit1.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "warrior1";
				break;

				case "gm_crew7":
					PlaySound("VOICE\ENGLISH\gm_crew7.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "warrior2";
				break;

				case "gm_crew8":
					PlaySound("VOICE\ENGLISH\gm_crew8A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "boy";
				break;

				case "gm_crew9":
					PlaySound("VOICE\ENGLISH\gm_crew9A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "trader";
				break;

				case "gm_crew12":
					PlaySound("VOICE\ENGLISH\gm_crew12A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "girl";
				break;

				case "gm_crew13":
					PlaySound("VOICE\ENGLISH\gm_crew13A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "marine";
				break;
		
				case "gm_crew14":
					PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "barrelmaker";
				break;

				case "gm_crew15":
					PlaySound("VOICE\ENGLISH\gm_crew15A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "executioner";
				break;

				case "gm_crew16":
					PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "buccaneer";
				break;

				case "gm_crew17":
					PlaySound("VOICE\ENGLISH\Fre_m_b_067.wav");
					PlaySound("VOICE\ENGLISH\Fre_m_b_067.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[53];
					link.l1.go = "monk";
				break;

				case "gm_crew19":
					PlaySound("VOICE\ENGLISH\Dut_m_a_068.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "butcher";
				break;

				case "gm_crew21":
					PlaySound("VOICE\ENGLISH\gm_crew21A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "musician";
				break;

				case "gm_crew23":
					PlaySound("VOICE\ENGLISH\gm_crew23A.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "musketeer";
				break;
		
				
			}
			
			Diag.TempNode = "first time";
		break;
	//--------------------------------------------------------
		case "boatswain":
	//1
			PlaySound("VOICE\ENGLISH\gm_crew1B.wav");
			Dialog.text = DLG_TEXT[13];		
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "boatswain1";
		break;

		case "boatswain1":
			PlaySound("VOICE\ENGLISH\gm_crew1C.wav");
			Dialog.text = DLG_TEXT[7];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";			
			AddDialogExitQuest("gm_crew1_convincing_pchar");
		break;

		case "boatswain2":
			PlaySound("VOICE\ENGLISH\gm_crew1B.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";							
		break;
	//--------------------------------------------------------
		case "sailmaker":
	//2
			PlaySound("VOICE\ENGLISH\gm_crew2B.wav");
			Dialog.text = DLG_TEXT[17];		
			link.l1 = DLG_TEXT[20];			
			link.l1.go = "sailmaker1";
		break;

		case "sailmaker1":
			PlaySound("VOICE\ENGLISH\gm_crew2A.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "carpenter":
	//3
			PlaySound("VOICE\ENGLISH\Eng_m_a_028.wav");
			Dialog.text = DLG_TEXT[5];		
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "carpenter1";
		break;

		case "carpenter1":
			PlaySound("VOICE\ENGLISH\Eng_m_a_029.wav");
			Dialog.text = DLG_TEXT[19];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew3_convincing_pchar");
		break;

		case "carpenter2":
			PlaySound("VOICE\ENGLISH\Eng_m_a_031.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "doctor":
	//4
			PlaySound("VOICE\ENGLISH\gm_crew4B.wav");
			Dialog.text = DLG_TEXT[22];		
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "doctor1";
		break;

		case "doctor1":
			PlaySound("VOICE\ENGLISH\gm_crew4C.wav");
			Dialog.text = DLG_TEXT[24];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew4_convincing_pchar");
		break;

		case "doctor2":
			PlaySound("VOICE\ENGLISH\gm_crew4D.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "fighter_big":
	//5
			PlaySound("VOICE\ENGLISH\gm_crew5B.wav");
			Dialog.text = DLG_TEXT[25];		
			link.l1 = DLG_TEXT[26];			
			link.l1.go = "fighter_big1";
		break;

		case "fighter_big1":
			PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			Dialog.text = DLG_TEXT[27];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew5_convincing_pchar");
		break;

		case "fighter_big2":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "warrior1":
	//6
			PlaySound("OBJECTS\DUEL\reload1.wav");
			Dialog.text = DLG_TEXT[28];		
			link.l1 = DLG_TEXT[29];			
			link.l1.go = "warrior1_A";
		break;

		case "warrior1_A":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[30];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "warrior2":
	//7
			CreateParticleSystem("gunfire" , -2.2, 0.0, -2.8, 0.0, 0.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , -2.2, 0.3, -2.5, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\DUEL\pistol_musket.wav");
			Dialog.text = DLG_TEXT[28];		
			link.l1 = DLG_TEXT[29];			
			link.l1.go = "warrior2_A";
		break;

		case "warrior2_A":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[30];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "boy":
	//8
			PlaySound("VOICE\ENGLISH\gm_crew8B.wav");
			Dialog.text = DLG_TEXT[31];		
			link.l1 = DLG_TEXT[32];			
			link.l1.go = "boy1";
		break;

		case "boy1":
			PlaySound("VOICE\ENGLISH\gm_crew8C.wav");
			Dialog.text = DLG_TEXT[33];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "trader":
	//9
			PlaySound("VOICE\ENGLISH\gm_crew9B.wav");
			Dialog.text = DLG_TEXT[34];		
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "trader1";
		break;

		case "trader1":
			PlaySound("VOICE\ENGLISH\gm_crew9C.wav");
			Dialog.text = DLG_TEXT[49];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "gunner":
	//10
			PlaySound("VOICE\ENGLISH\Fre_m_c_015.wav");
			Dialog.text = DLG_TEXT[8];		
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "gunner1";
		break;

		case "gunner1":
			PlaySound("VOICE\ENGLISH\Fre_m_c_007.wav");
			Dialog.text = DLG_TEXT[10];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew10_convincing_pchar");
		break;

		case "gunner2":
			PlaySound("VOICE\ENGLISH\Fre_m_c_003.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "fighter_spanish":
	//11
			PlaySound("VOICE\ENGLISH\gm_crew11A.wav");
			Dialog.text = DLG_TEXT[36];		
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "fighter_spanish1";
		break;

		case "fighter_spanish1":
			PlaySound("VOICE\ENGLISH\gm_crew11C.wav");
			Dialog.text = DLG_TEXT[37];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew11_convincing_pchar");
		break;

		case "fighter_spanish2":
			PlaySound("VOICE\ENGLISH\gm_crew11A.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "girl":
	//12
			PlaySound("VOICE\ENGLISH\gm_crew12B.wav");
			Dialog.text = DLG_TEXT[38];		
			link.l1 = DLG_TEXT[58];			
			link.l1.go = "girl1";
		break;

		case "girl1":
			PlaySound("VOICE\ENGLISH\gm_crew12C.wav");
			Dialog.text = DLG_TEXT[35];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "marine":
	//13
			PlaySound("VOICE\ENGLISH\gm_crew13B.wav");
			Dialog.text = DLG_TEXT[11];		
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "marine1";
		break;

		case "marine1":
			PlaySound("VOICE\ENGLISH\gm_crew13A.wav");
			Dialog.text = DLG_TEXT[10];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "barrelmaker":
	//14
			PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
			Dialog.text = DLG_TEXT[54];		
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "barrelmaker1";
		break;

		case "barrelmaker1":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[19];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "executioner":
	//15
			PlaySound("VOICE\ENGLISH\gm_crew15B.wav");
			Dialog.text = DLG_TEXT[39];		
			link.l1 = DLG_TEXT[14];			
			link.l1.go = "executioner1";
		break;

		case "executioner1":
			PlaySound("VOICE\ENGLISH\gm_crew15A.wav");
			Dialog.text = DLG_TEXT[15];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "buccaneer":
	//16
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			Dialog.text = DLG_TEXT[40];		
			link.l1 = DLG_TEXT[59];			
			link.l1.go = "buccaneer1";
		break;

		case "buccaneer1":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[60];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "monk":
	//17
			PlaySound("VOICE\ENGLISH\Fre_m_b_071.wav");
			PlaySound("VOICE\ENGLISH\Fre_m_b_071.wav");
			Dialog.text = DLG_TEXT[52];		
			link.l1 = DLG_TEXT[41];			
			link.l1.go = "monk1";
		break;

		case "monk1":
			PlaySound("VOICE\ENGLISH\Fre_m_b_070.wav");
			PlaySound("VOICE\ENGLISH\Fre_m_b_070.wav");
			Dialog.text = DLG_TEXT[61];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "quartermaster":
	//18
			PlaySound("VOICE\ENGLISH\gm_crew18B.wav");
			Dialog.text = DLG_TEXT[16];		
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "quartermaster1";
		break;

		case "quartermaster1":
			PlaySound("VOICE\ENGLISH\gm_crew18C.wav");
			Dialog.text = DLG_TEXT[7];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew18_convincing_pchar");
		break;

		case "quartermaster2":
			PlaySound("VOICE\ENGLISH\gm_crew18D.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "butcher":
	//19
			PlaySound("VOICE\ENGLISH\Dut_m_a_005.wav");
			Dialog.text = DLG_TEXT[43];		
			link.l1 = DLG_TEXT[44];			
			link.l1.go = "butcher1";
		break;

		case "butcher1":
			PlaySound("VOICE\ENGLISH\Dut_m_a_025.wav");
			Dialog.text = DLG_TEXT[45];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "first_mate":
	//20
			PlaySound("VOICE\ENGLISH\Por_m_b_030.wav");
			Dialog.text = DLG_TEXT[46];		
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "first_mate1";
		break;

		case "first_mate1":
			PlaySound("VOICE\ENGLISH\Por_m_b_026.wav");
			Dialog.text = DLG_TEXT[47];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew20_convincing_pchar");
		break;

		case "first_mate2":
			PlaySound("VOICE\ENGLISH\Por_m_b_029.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "musician":
	//21
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[62];			//was 48		
			link.l1 = DLG_TEXT[26];			
			link.l1.go = "musician1";
		break;

		case "musician1":
			PlaySound("INTERFACE\violin.wav");
			Dialog.text = DLG_TEXT[63];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "navigator":
	//22
			PlaySound("VOICE\ENGLISH\gm_crew22B.wav");
			Dialog.text = DLG_TEXT[50];		
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "navigator1";
		break;

		case "navigator1":
			PlaySound("VOICE\ENGLISH\gm_crew22C.wav");
			Dialog.text = DLG_TEXT[51];		
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
			AddDialogExitQuest("gm_crew22_convincing_pchar");
		break;

		case "navigator2":
			PlaySound("VOICE\ENGLISH\gm_crew22A.wav");
			Dialog.text = DLG_TEXT[57];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit_gm_officer_hired";					
		break;
	//--------------------------------------------------------
		case "musketeer":
	//23
			PlaySound("VOICE\ENGLISH\gm_crew23B.wav");
			Dialog.text = DLG_TEXT[12];		
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "musketeer1";
		break;

		case "musketeer1":
			PlaySound("VOICE\ENGLISH\gm_crew23A.wav");
			Dialog.text = DLG_TEXT[10];		
			link.l1 = DLG_TEXT[56];							
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[4];			
			link.l2.go = "exit_gm_sailor_hired";
		break;
	//--------------------------------------------------------
		case "exit_gm_officer_hired":
			AddPassenger(Pchar, NPchar, 0);
			
			NPchar.Dialog.Filename = "Enc_Officer_dialog.c";
			NPchar.Dialog.CurrentNode = "Hired";
		ChangeCharacterAddressGroup(NPchar, "none", "", "");

			Pchar.quest.gm_officers = makeint(Pchar.quest.gm_officers)-1;

			crewid = NPChar.id;
			switch(crewid)
			{
					case "gm_crew1":
						Pchar.quest.gm_chosen_officer = "gm_crew1";
					break;

					case "gm_crew3":
						Pchar.quest.gm_chosen_officer = "gm_crew3";
					break;

					case "gm_crew4":
						Pchar.quest.gm_chosen_officer = "gm_crew4";
					break;

					case "gm_crew5":
						Pchar.quest.gm_chosen_officer = "gm_crew5";
					break;

					case "gm_crew10":
						Pchar.quest.gm_chosen_officer = "gm_crew10";
					break;

					case "gm_crew11":
						Pchar.quest.gm_chosen_officer = "gm_crew11";
					break;

					case "gm_crew18":
						Pchar.quest.gm_chosen_officer = "gm_crew18";
					break;

					case "gm_crew20":
						Pchar.quest.gm_chosen_officer = "gm_crew20";
					break;

					case "gm_crew22":
						Pchar.quest.gm_chosen_officer = "gm_crew22";
					break;
			}	

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("gm_officers_complete");
		break;

		case "exit_gm_sailor_hired":
			crewid = NPChar.id;
			switch(crewid)
			{
				case "gm_crew2":
					Pchar.skill.Repair = makeint(Pchar.skill.Repair) + 1;
				break;

				case "gm_crew6":
					Pchar.skill.Fencing = makeint(Pchar.skill.Fencing) + 1;

					if(makeint(PChar.skill.Fencing)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew7"), "none", "", "");		
				break;

				case "gm_crew7":
					Pchar.skill.Fencing = makeint(Pchar.skill.Fencing) + 1;

					if(makeint(PChar.skill.Fencing)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew6"), "none", "", "");
				break;

				case "gm_crew8":
					Pchar.skill.Sneak = makeint(Pchar.skill.Sneak) + 1;
				break;

				case "gm_crew9":
					Pchar.skill.Commerce = makeint(Pchar.skill.Commerce) + 1;
				break;

				case "gm_crew12":
					Pchar.skill.Accuracy = makeint(Pchar.skill.Accuracy) + 1;
				break;

				case "gm_crew13":
					Pchar.skill.Cannons = makeint(Pchar.skill.Cannons) + 1;

					if(makeint(PChar.skill.Cannons)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew23"), "none", "", "");
				break;
		
				case "gm_crew14":
					Pchar.skill.Sailing = makeint(Pchar.skill.Sailing) + 1;
					
					if(makeint(PChar.skill.Sailing)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew21"), "none", "", "");
				break;

				case "gm_crew15":
					Pchar.skill.Grappling = makeint(Pchar.skill.Grappling) + 1;
					
					if(makeint(PChar.skill.Grappling)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew16"), "none", "", "");
				break;

				case "gm_crew16":
					Pchar.skill.Grappling = makeint(Pchar.skill.Grappling) + 1;
					
					if(makeint(PChar.skill.Grappling)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew15"), "none", "", "");
				break;

				case "gm_crew17":
					Pchar.skill.Leadership = makeint(Pchar.skill.Leadership) + 1;
				break;

				case "gm_crew19":
					Pchar.skill.Defence = makeint(Pchar.skill.Defence) + 1;
				break;

				case "gm_crew21":
					Pchar.skill.Sailing = makeint(Pchar.skill.Sailing) + 1;
					
					if(makeint(PChar.skill.Sailing)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew14"), "none", "", "");
				break;

				case "gm_crew23":
					Pchar.skill.Cannons = makeint(Pchar.skill.Cannons) + 1;

					if(makeint(PChar.skill.Cannons)>9)
					ChangeCharacterAddressGroup(characterFromID("gm_crew13"), "none", "", "");
				break;
			}

			ChangeCharacterAddressGroup(NPchar, "none", "", "");

			Pchar.quest.gm_sailors = makeint(Pchar.quest.gm_sailors)-1;
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("gm_sailors_complete");
		break;

		case "defoe_letter":
			//gm_crew8

			PlaySound("VOICE\ENGLISH\gm_crew8A.wav");
			PlaySound("VOICE\ENGLISH\gm_crew8A.wav");
			Dialog.text = DLG_TEXT[64];		
			link.l1 = DLG_TEXT[65];			
			link.l1.go = "defoe_letter1";
		break;

		case "defoe_letter1":
			//gm_crew8

			PlaySound("VOICE\ENGLISH\gm_crew8C.wav");
			PlaySound("VOICE\ENGLISH\gm_crew8C.wav");
			PlaySound("INTERFACE\paper_small.wav");
			Dialog.text = DLG_TEXT[66];		
			link.l1 = DLG_TEXT[67];			
			link.l1.go = "exit_messenger";
			AddDialogExitQuest("defoe_letter_given");
		break;

		case "neutral":
			crewid = NPChar.id;
			switch(crewid)
			{
		//...............................................................
		//9 OFFICERS
				case "gm_crew1":
					PlaySound("VOICE\ENGLISH\gm_crew1A.wav");
				break;

				case "gm_crew3":
					PlaySound("VOICE\ENGLISH\Eng_m_a_031.wav");
				break;

				case "gm_crew4":
					PlaySound("VOICE\ENGLISH\gm_crew4A.wav");
				break;

				case "gm_crew5":
					PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
				break;

				case "gm_crew10":
					PlaySound("VOICE\ENGLISH\Fre_m_c_004.wav");
				break;

				case "gm_crew11":
					PlaySound("VOICE\ENGLISH\gm_crew11B.wav");
				break;

				case "gm_crew18":
					PlaySound("VOICE\ENGLISH\gm_crew18A.wav");
				break;

				case "gm_crew20":
					PlaySound("VOICE\ENGLISH\Por_m_b_027.wav");
				break;

				case "gm_crew22":
					PlaySound("VOICE\ENGLISH\gm_crew22A.wav");
				break;
			}
			Dialog.text = DLG_TEXT[68];
			link.l1.go = "exit_messenger";
			Diag.TempNode = "neutral";
		break;

		case "Exit_messenger":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit":
			LAi_SetGuardianType(NPchar);

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
