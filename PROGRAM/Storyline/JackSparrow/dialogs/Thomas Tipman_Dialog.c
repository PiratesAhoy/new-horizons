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
			Dialog.snd = "dialogs\0\009";

			PlaySound("VOICE\ENGLISH\Eng_m_c_079.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First time Cayman":
			PlaySound("VOICE\ENGLISH\Eng_m_c_083.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
		break;

		case "first time Redmond":
			PlaySound("VOICE\ENGLISH\Eng_m_c_002.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "first time Redmond2";
		break;

		case "first time Redmond2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "first time Redmond3";
		break;

		case "first time Redmond3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "first time Redmond4";
		break;

		case "first time Redmond4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "first time Redmond5";
			link.l2 = DLG_TEXT[12]
			link.l2.go = "Exit First time Redmond";
		break;

		case "first time Redmond5":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "first time Redmond6";
		break;

		case "first time Redmond6":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "first time Redmond7";
		break;

		case "first time Redmond7":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "first time Redmond8";
		break;

		case "first time Redmond8":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			//if(CheckQuestAttribute("Jacks_early_days", "Jacks_first_run_Beckett"))
			if (CheckQuestAttribute("Jacks_early_days", "Mings_First_run_Beckett"))
			{
			link.l1.go = "first time Redmond9";
			}else{
			link.l1.go = "Exit First time Redmond";
			}
		break;
		
// TALISMAN changed - Kell gives player this bit of map later on VVVVV

//		case "first time Redmond9":
//			dialog.text = DLG_TEXT[29]; 
//			link.l1 = DLG_TEXT[30];		
//			link.l1.go = "Exit First time RedmondXX";
//		break;
	
		case "first time Redmond9":
			dialog.text = DLG_TEXT[48]; 
			link.l1 = DLG_TEXT[49];		
			link.l1.go = "Exit First time RedmondXX";
		break;
		
// TALISMAN  ^^^^^^^^^^^^^^^^^^^		

		case "Exit First time Redmond":
			//SetQuestHeader("Hector Barbossa");
			//AddQuestRecord("Hector Barbossa",3);
			AddDialogExitQuest("Beckett_back_in_EITC_office2");
			AddQuestRecord("Pirate Lord", 3);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit First time RedmondXX":
//			GiveItem2Character(Pchar,"Map_Doc_3"); // TALISMAN - changed - Kell gives player this bit of map later.
			AddMoneyToCharacter(pchar, -100);
			//SetQuestHeader("Hector Barbossa");
			//AddQuestRecord("Hector Barbossa",1);
			AddQuestRecord("Pirate Lord", 3);   // TALISMAN was 2 - changed for not given bit of map see above
			if (GetAttribute(pchar, "Aztec") != "1")
			{
				SetQuestHeader("Aztec");
				pchar.aztec = "1";
			}
//			AddQuestRecord("Aztec", 1);
			AddQuestRecord("Aztec", 14); // TALISMAN - replacement QB entry
			
			AddDialogExitQuest("Beckett_back_in_EITC_office2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "First time Turks":
			PlaySound("VOICE\ENGLISH\Eng_m_c_065.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "First time Turks2";
		break;

		case "First time Turks2":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "First time Turks3";
		break;

		case "First time Turks3":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit First time Turks";
		break;

		case "Exit First time Turks":
			AddQuestRecord("Mystery Woman",11);
			AddDialogExitQuest("Do_Brock_search_again");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Join_for_Isla_Muelle":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Join_Isla_Muelle";		
		break;

		case "Join_Isla_Muelle":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Join_Isla_Muelle2";		
		break;

		case "Join_Isla_Muelle2":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Join_Isla_Muelle3";		
		break;

		case "Join_Isla_Muelle3":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_Join_Isla_Muelle";		
		break;

		case "Exit_Join_Isla_Muelle":
			AddMoneyToCharacter(pchar, -250);
			AddMoneyToCharacter(characterFromID("Thomas Tipman"), +250)
			AddDialogExitQuest("Now_go_to_Isla_Muelle");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;		
		break;

		case "Arrived_Isla Muelle":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Arrived_Muelle2";
		break;

		case "Arrived_Muelle2":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Arrived_Muelle3";
		break;

		case "Arrived_Muelle3":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_Arrived_Muelle";
		break;

		case "Tortuga Help":
			PlaySound("VOICE\ENGLISH\Eng_m_c_079.wav");
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
		break;

		case "Exit_Arrived_Muelle":
			AddDialogExitQuest("Search_in_Muelle");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;		
		break;
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


	}
}
