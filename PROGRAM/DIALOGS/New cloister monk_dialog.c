
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
			
			if(NPchar.id == "NC_monkL")
			{
				PlaySound("AMBIENT\CRYPT\daemon2.wav");
				PlaySound("AMBIENT\CRYPT\daemon2.wav");
				dialog.text = DLG_TEXT[25];
				link.l9 = DLG_TEXT[26];
				link.l9.go = "exit";
			}
			else
			{	
				if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_001.wav"); }
				else { PlaySound("VOICE\ENGLISH\Spa_m_a_001.wav"); }
				dialog.text = DLG_TEXT[0];
				if(pchar.location != "new_cloister_chapel")
				{
					link.l1 = DLG_TEXT[1];
					link.l1.go = "chapel";
				}
				link.l2 = DLG_TEXT[2];
				link.l2.go = "crypt";
				if(pchar.location != "new_cloister_inside")
				{
					link.l3 = DLG_TEXT[3];
					link.l3.go = "inside";
				}
				link.l4 = DLG_TEXT[4];
				link.l4.go = "stone_circle";
				if(pchar.location != "new_cloister_graveyard")
				{
					link.l5 = DLG_TEXT[5];
					link.l5.go = "graveyard";
				}
				link.l6 = DLG_TEXT[21];
				link.l6.go = "distillery";
				if(!CheckAttribute(Pchar,"cartagena_library") || Pchar.cartagena_library != "open")
				{
					link.l7 = DLG_TEXT[6];
					link.l7.go = "library";
				}
				link.l8 = DLG_TEXT[7];
				link.l8.go = "look_around";
			}
		break;

                case "chapel":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_060.wav"); }
			else { PlaySound("VOICE\ENGLISH\Spa_m_a_060.wav"); PlaySound("VOICE\ENGLISH\Spa_m_a_060.wav"); }
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "crypt":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Por_m_b_008.wav"); }
			else { PlaySound("VOICE\ENGLISH\Por_m_a_008.wav"); }
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
		break;

		case "inside":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_062.wav"); }
			else { PlaySound("VOICE\ENGLISH\Spa_m_a_062.wav"); }
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;
              
		case "stone_circle":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_003.wav"); }
			else { PlaySound("VOICE\ENGLISH\Spa_m_a_003.wav"); }
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;

		case "graveyard":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Por_m_b_007.wav"); }
			else { PlaySound("VOICE\ENGLISH\Por_m_a_007.wav"); }
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "distillery":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_026.wav"); }
			else { PlaySound("VOICE\ENGLISH\Spa_m_a_026.wav"); }
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "library":
			if (CharPlayerType == PLAYER_TYPE_ENGINEER)
			{
				if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_064.wav"); }
				else { PlaySound("VOICE\ENGLISH\Spa_m_a_064.wav"); PlaySound("VOICE\ENGLISH\Spa_m_a_064.wav"); }
				AddQuestRecord("Beginning_Engineer", "3");
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "exit";
			}
			else
			{
				if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Spa_m_b_004.wav"); }
				else { PlaySound("VOICE\ENGLISH\Spa_m_a_004.wav"); }
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit";
			}
		break;

		case "look_around":
			if(NPchar.id == "NC_monk3") { PlaySound("VOICE\ENGLISH\Por_m_b_034.wav"); }
			else { PlaySound("VOICE\ENGLISH\Por_m_a_034.wav"); }
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "map":
			PlaySound("VOICE\ENGLISH\Spa_m_b_063.wav");
			dialog.text = DLG_TEXT[27];
			link.l10 = DLG_TEXT[28];		
			link.l10.go = "map0";
		break;

		case "map0":
			PlaySound("VOICE\ENGLISH\Spa_m_b_016.wav");
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "map1";
		break;

		case "map1":
			PlaySound("VOICE\ENGLISH\Spa_m_b_004.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "map2";
		break;

		case "map2":
			PlaySound("INTERFACE\paper.wav");
			TakeItemFromCharacter(Pchar, "engineer_letter1");
			TakeItemFromCharacter(Pchar, "engineer_letter2");
			TakeItemFromCharacter(Pchar, "engineer_letter3");
			GiveItem2Character(Pchar, "mapCartagena_Library");

			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "map3";
		break;

		case "map3":
			PlaySound("VOICE\ENGLISH\Spa_m_b_003.wav");
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "map4";
		break;

		case "map4":
			PlaySound("VOICE\ENGLISH\Spa_m_b_032.wav");
			AddQuestRecord("Beginning_Engineer", "4");
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("cartagena_cloister_open");
		break;

	//NC_monkL
		case "change":
			PlaySound("AMBIENT\CRYPT\daemon2.wav");
			PlaySound("AMBIENT\CRYPT\daemon2.wav");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "change1";
		break;

		case "change1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead4.wav");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "change2";
		break;

		case "change2":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");
			PlaySound("AMBIENT\CRYPT\daemon1.wav");
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "change3";
		break;

		case "change3":
			LAi_SetImmortal(pchar, true);
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "change4";
		break;

		case "change4":
			PlaySound("AMBIENT\CRYPT\daemon2.wav");
			PlaySound("AMBIENT\CRYPT\daemon2.wav");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "change5";
		break;

		case "change5":
			PlaySound("VOICE\ENGLISH\zombie3.wav");
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "change6";
		break;

		case "change6":
			PlaySound("VOICE\ENGLISH\zombie2.wav");
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("librarian_change7");
		break;

                case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

              
	}
}
