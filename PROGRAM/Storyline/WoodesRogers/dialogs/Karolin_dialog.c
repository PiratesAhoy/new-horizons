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

			string crewid;
			crewid = NPChar.id;
			switch(crewid)
			{
				case "Kri_soldier_1": PlaySound("VOICE\ENGLISH\Dupin_good_day.wav"); break;
				case "Kri_soldier_2": PlaySound("VOICE\ENGLISH\gm_crew5A.wav"); break;
				case "Kri_soldier_3": PlaySound("VOICE\ENGLISH\pir_capLL.wav"); break;
				case "Kri_soldier_4": PlaySound("VOICE\ENGLISH\pir_capP.wav"); break;
				case "Kri_soldier_5": PlaySound("VOICE\ENGLISH\gr_Richards.wav"); break;
				case "Kri_soldier_6": PlaySound("VOICE\ENGLISH\Dut_m_a_008.wav"); break;
				case "Kri_soldier_7": PlaySound("VOICE\ENGLISH\Desmond Ray Beltrop.wav"); break;
				case "Kri_soldier_8": PlaySound("VOICE\ENGLISH\Spa_m_a_029.wav"); break;
				case "Kri_soldier_9": PlaySound("VOICE\ENGLISH\gm_crew1B.wav"); break;
				case "Kri_soldier_10": PlaySound("VOICE\ENGLISH\Spa_m_b_031.wav"); break;
				case "Kri_soldier_11": PlaySound("VOICE\ENGLISH\Dut_m_a_032.wav"); break;
				case "Kri_soldier_12": PlaySound("VOICE\ENGLISH\gm_crew7.wav"); break;

			case "Kri_soldier_13": PlaySound("VOICE\ENGLISH\jrh_3.wav"); break;
			case "Kri_soldier_14": PlaySound("VOICE\ENGLISH\gm_crew1C.wav"); break;
				
			case "Kri_gunner_1": PlaySound("VOICE\ENGLISH\gm_crew1A.wav"); break;
				case "Kri_gunner_2": PlaySound("VOICE\ENGLISH\Spa_m_a_031.wav"); break;
				case "Kri_gunner_3": PlaySound("VOICE\ENGLISH\gr_friday4.wav"); break;
				case "Kri_gunner_4": PlaySound("VOICE\ENGLISH\Spa_m_b_032.wav"); break;
				case "Kri_gunner_5": PlaySound("VOICE\ENGLISH\defoe_psst.wav"); break;
				case "Kri_gunner_6": PlaySound("VOICE\ENGLISH\Dut_m_a_035.wav"); break;

			case "Kri_gunner_7": PlaySound("VOICE\ENGLISH\Dut_m_a_023.wav"); break;
			case "Kri_gunner_8": PlaySound("VOICE\ENGLISH\pir_capMMM.wav"); break;

				case "Kri_dragoon_1": PlaySound("VOICE\ENGLISH\Bolitho3.wav"); break;
				case "Kri_dragoon_2": PlaySound("VOICE\ENGLISH\Spa_m_b_030.wav"); break;
				case "Kri_dragoon_3": PlaySound("VOICE\ENGLISH\pir_capKK.wav"); break;
				case "Kri_dragoon_4": PlaySound("VOICE\ENGLISH\gm_crew12A.wav"); break;

			case "Kri_dragoon_5": PlaySound("VOICE\ENGLISH\Dut_m_a_043.wav"); break;
			case "Kri_dragoon_6": PlaySound("VOICE\ENGLISH\Dut_m_a_025.wav"); break;
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

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
