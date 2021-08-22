void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
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

			switch (NPchar.id)
			{
				case "Antigua_guard1":
					//CB
					int CBgreeting = rand(2);
					switch (CBgreeting)
					{
						case 0: PlaySound("VOICE\ENGLISH\Maynard_hey_there.wav"); break;
						case 1: PlaySound("VOICE\ENGLISH\Maynard_steady_there.wav"); break;
						case 2: PlaySound("VOICE\ENGLISH\Maynard_very_well.wav"); break;
					}
				break;

				case "Antigua_guard2":
					//FZ
					int FZgreeting = rand(2);
					switch (FZgreeting)
					{
						case 0: PlaySound("VOICE\ENGLISH\Poe_well.wav"); break;
						case 1: PlaySound("VOICE\ENGLISH\Poe_go_on.wav"); break;
						case 2: PlaySound("VOICE\ENGLISH\Poe_ok.wav"); break;
					}
				break;
			
				case "bb_prison_officer":
					int off1greeting = rand(3);
					switch (off1greeting)
					{
						case 0: PlaySound("VOICE\ENGLISH\Eng_m_c_039.wav"); break;
						case 1: PlaySound("VOICE\ENGLISH\Eng_m_c_040.wav"); break;
						case 2: PlaySound("VOICE\ENGLISH\Eng_m_c_041.wav"); break;
						case 3: PlaySound("VOICE\ENGLISH\Eng_m_c_042.wav"); break;
					}
				break;
			
				int P2greeting = rand(3);
				switch (P2greeting)
				{
					case 0: PlaySound("VOICE\ENGLISH\Eng_m_b_039.wav"); break;
					case 1: PlaySound("VOICE\ENGLISH\Eng_m_b_040.wav"); break;
					case 2: PlaySound("VOICE\ENGLISH\Eng_m_b_043.wav"); break;
					case 3: PlaySound("VOICE\ENGLISH\Eng_m_b_044.wav"); break;
				}
			}

			int iPhrase = rand(10);
			
			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				break;
				
				case 1:
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				break;
				
				case 2:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				break;
				
				case 3:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				break;
				
				case 4:
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
				break;
				
				case 5:
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				break;
				
				case 6:
					dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				break;
				
				case 7:
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
				break;
				
				case 8:
					dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[17];
					link.l1.go = "exit";
				break;
				
				case 9:
					dialog.text = DLG_TEXT[18];
					link.l1 = DLG_TEXT[19];
					link.l1.go = "exit";
				break;
				
				case 10:
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "exit";
				break;
			}
		break;
	
		case "halt":
			PlaySound("VOICE\ENGLISH\Maynard_hey_there.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "halt1";
		break;
	
		case "halt1":
			PlaySound("VOICE\ENGLISH\Maynard_too_bad.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "halt2";
		break;

		case "halt2":
			PlaySound("VOICE\ENGLISH\Maynard_very_well.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "halt3";
		break;

		case "halt3":
			PlaySound("VOICE\ENGLISH\Maynard_steady_there.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "halt5";
		break;

		case "halt5":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Antigua_fort1");
		break;

		case "pass":
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "pass1";
		break;
		
		case "pass1":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Antigua_fort2");
		break;

		case "bb_prison_stop":
			PlaySound("VOICE\ENGLISH\Eng_m_c_042.wav");
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("bb_prison_stop1");
		break;

		case "bb_prison_stop3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_040.wav");
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "bb_prison_stop4";
		break;

		case "bb_prison_stop4":
			PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "bb_prison_stop5";
		break;

		case "bb_prison_stop5":
			PlaySound("VOICE\ENGLISH\Eng_m_c_059.wav");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "bb_prison_stop6";
		break;

		case "bb_prison_stop6":
			PlaySound("VOICE\ENGLISH\Eng_m_c_060.wav");
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "bb_prison_stop7";
		break;

		case "bb_prison_stop7":
			PlaySound("VOICE\ENGLISH\Eng_m_c_062.wav");
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit";
			AddDialogExitQuest("bb_prison_stop7");
		break;

	//-----------------------------------------------------------
		case "bb_prison2_tools":
			PlaySound("VOICE\ENGLISH\Eng_m_b_040.wav");
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("bb_prison2_tools_done");
		break
	//-----------------------------------------------------------	
		case "Took_finds_out":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("P2_guards_move");
		break;
	//-----------------------------------------------------------
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
