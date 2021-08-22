// JRH fake dialog for slaves

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

	string guardid;
	guardid = NPChar.id;

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Г„ГЁГ Г«Г®ГЈ ГЇГҐГ°ГўГ»Г© - ГЇГҐГ°ГўГ Гї ГўГ±ГІГ°ГҐГ·Г 
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

			switch(guardid)
			{
				case "car_slave1":
					PlaySound("VOICE\ENGLISH\Beggar_01.wav");		//dead
				break;

				case "car_slave2":
					PlaySound("VOICE\ENGLISH\guncrew_2.wav");
				break;

				case "car_slave3":
					PlaySound("VOICE\ENGLISH\Por_m_a_004.wav");
				break;

				case "car_slave4":
					PlaySound("VOICE\ENGLISH\Eden_yeah.wav");
				break;

				case "car_slave5":
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				break;

				case "car_slave6":
					PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");		//dead
				break;

				case "car_slave7":
					PlaySound("OBJECTS\DUEL\man_attack5.wav");
				break;

				case "car_slave8":
					PlaySound("VOICE\ENGLISH\FredBob.wav");
				break;

				case "car_slave9":
					PlaySound("AMBIENT\JAIL\sigh.wav");
				break;

				case "car_slave10":
					PlaySound("VOICE\ENGLISH\Poe_well.wav");
				break;

				case "car_slave11":
					PlaySound("VOICE\ENGLISH\Mateus Santos1.wav");	
				break;

				case "car_slave12":
					PlaySound("VOICE\ENGLISH\guncrew_3.wav");
				break;

				case "car_slave13":
					PlaySound("VOICE\ENGLISH\Dut_m_a_003.wav");		//dead
				break;

				case "car_slave14":
					PlaySound("VOICE\ENGLISH\pir_capFF.wav");		//dead
				break;

				case "car_slave15":
					PlaySound("VOICE\ENGLISH\guncrew_4.wav");
				break;

				case "car_slave16":
					PlaySound("AMBIENT\JAIL\sigh2.wav");
				break;

				case "car_slave17":
					PlaySound("VOICE\ENGLISH\Eng_m_a_001.wav");
				break;

				case "car_slave18":
					PlaySound("VOICE\ENGLISH\pir_capFF.wav");
				break;

				case "car_slave19":
					PlaySound("VOICE\ENGLISH\Fre_m_a_003.wav");		//dead
				break;

				case "car_slave20":
					PlaySound("VOICE\ENGLISH\pir_capP.wav");
				break;

				case "car_slave21":
					PlaySound("VOICE\ENGLISH\Spa_m_a_001.wav");
				break;

				case "car_slave22":
					PlaySound("VOICE\ENGLISH\Dupin_alright.wav");
				break;

				case "car_slave23":
					PlaySound("VOICE\ENGLISH\jrh_6.wav");
				break;

				case "car_slave24":
					PlaySound("VOICE\ENGLISH\Thug.wav");
				break;

				case "car_slave25":
					PlaySound("VOICE\ENGLISH\Poe_well.wav");
				break;

				case "car_slave26":
					PlaySound("OBJECTS\DUEL\man_hit1.wav");
				break;

				case "car_slave27":
					PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
				break;

				case "car_slave28":
					PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
				break;
			}

			Diag.TempNode = "First time";
			DialogExit();
		break;	

		case "FredBob_here":
			PlaySound("VOICE\ENGLISH\FredBob.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AdddialogExitQuest("explore_corvette34_B");
		break;	

		case "Prince_here":
			PlaySound("VOICE\ENGLISH\Por_m_a_004.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AdddialogExitQuest("explore_corvette34_C");
		break;	

	//musician
		case "priest_spanish":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "musician";
		break;

		case "musician":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "musician1";
		break;

		case "musician1":
			PlaySound("VOICE\ENGLISH\guncrew_4.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AdddialogExitQuest("Pyle_to_wdeck38");
		break;

		case "soldier_volunteer":
			PlaySound("VOICE\ENGLISH\Eden_well.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AdddialogExitQuest("Pyle_to_Mona16");
		break;

		case "switch_outfits":
			PlaySound("VOICE\ENGLISH\Mateus Santos1.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AdddialogExitQuest("Pyle_to_Mona18");
		break;		
			
		case "worthless_uniform":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "worthless_uniform1";
		break;

		case "worthless_uniform1":
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AdddialogExitQuest("Pyle_to_Mona39_AA");
		break;

		case "neutral_soldier":
			//car_slave10

			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_soldier";
		break;

		case "neutral_priest":
			//car_slave11

			PlaySound("VOICE\ENGLISH\Eden_well.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_priest";
		break;

		case "neutral_musician":
			//car_slave27

			PlaySound("INTERFACE\violin.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_musician";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;



	
	}
}