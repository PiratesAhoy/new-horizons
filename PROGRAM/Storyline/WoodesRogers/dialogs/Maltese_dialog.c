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

			switch(NPChar.id)
			{
				case "Maltese_red2":
					//surgeon 
					PlaySound("VOICE\ENGLISH\Dupin_help.wav"); 
					dialog.text = DLG_TEXT[33];
					link.l1 = DLG_TEXT[34];
					link.l1.go = "exit";
				break;

				case "Maltese_black":
					//chaplain
					PlaySound("VOICE\ENGLISH\pir_capLL.wav"); 
					dialog.text = DLG_TEXT[35];
					link.l1 = DLG_TEXT[36];
					link.l1.go = "exit";
				break;

				case "Maltese_knight":
					//white knight
					PlaySound("VOICE\ENGLISH\gr_Richards.wav"); 
					dialog.text = DLG_TEXT[37];
					link.l1 = DLG_TEXT[38];
					link.l1.go = "exit";
				break;

				case "Maltese_green":
					//officer
					PlaySound("VOICE\ENGLISH\pir_capKK.wav"); 
					dialog.text = DLG_TEXT[39];
					link.l1 = DLG_TEXT[40];
					link.l1.go = "exit";
				break;
			}	
		break;

		case "start_mission":
			PlaySound("VOICE\ENGLISH\Fre_m_b_002.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "start_mission1";
		break;

		case "start_mission1":
			PlaySound("VOICE\ENGLISH\Fre_m_b_001.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "start_mission2";
		break;

		case "start_mission2":
			PlaySound("VOICE\ENGLISH\Fre_m_b_021.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "start_mission3";
		break;

		case "start_mission3":
			PlaySound("VOICE\ENGLISH\Fre_m_b_035.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "start_mission4";
		break;

		case "start_mission4":
			PlaySound("VOICE\ENGLISH\Fre_m_b_007.wav");
			PlaySound("AMBIENT\JAIL\chains2.wav");
			GiveItem2Character(Pchar, "bladekeyring");
			EquipCharacterByItem(Pchar, "bladekeyring");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "start_mission5";			
		break;

		case "start_mission5":
			PlaySound("VOICE\ENGLISH\Fre_m_b_006.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit_clerk";
			AddDialogExitQuest("start_Maltains_dialog_done");
			AddDialogExitQuest("Malta_items1");
		break;

		case "got_all_books":
			PlaySound("VOICE\ENGLISH\Fre_m_b_072.wav");
			dialog.text = DLG_TEXT[10];
			if(CheckCharacterItem(Pchar,"book63") && CheckCharacterItem(Pchar,"book64") && CheckCharacterItem(Pchar,"book65")
			&& CheckCharacterItem(Pchar,"book66") && CheckCharacterItem(Pchar,"book67") && CheckCharacterItem(Pchar,"book68"))
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "got_all_books1";
			}
			else 
			{	link.l1 = DLG_TEXT[12];
				link.l1.go = "exit_clerk";
				AddDialogExitQuest("start_Maltains_dialog_done");
			}
		break;

		case "got_all_books1":
			PlaySound("VOICE\ENGLISH\Fre_m_b_032.wav");
			if(IsEquipCharacterByItem(Pchar, "bladekeyring")) 
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladeX4");
			}
			TakeItemFromCharacter(pchar, "bladekeyring");		
			TakeItemFromCharacter(pchar, "book63"); TakeItemFromCharacter(pchar, "book64"); TakeItemFromCharacter(pchar, "book65");
			TakeItemFromCharacter(pchar, "book66"); TakeItemFromCharacter(pchar, "book67"); TakeItemFromCharacter(pchar, "book68");
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit_clerk";
			AddDialogExitQuest("got_all_books_done");
		break;

		case "prison_info":
			PlaySound("VOICE\ENGLISH\Eng_m_a_005.wav");
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "prison_info1";
		break;

		case "prison_info1":
			PlaySound("VOICE\ENGLISH\Eng_m_a_042.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "prison_info2";
		break;

		case "prison_info2":
			PlaySound("VOICE\ENGLISH\Eng_m_a_003.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "prison_info3";
		break;

		case "prison_info3":
			PlaySound("VOICE\ENGLISH\Eng_m_a_059.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "prison_info4";
		break;

		case "prison_info4":
			PlaySound("VOICE\ENGLISH\Eng_m_a_004.wav");
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];			
			link.l1.go = "prison_info5";
		break;

		case "prison_info5":
			PlaySound("VOICE\ENGLISH\Eng_m_a_001.wav");
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "prison_info6";
		break;

		case "prison_info6":
			PlaySound("VOICE\ENGLISH\Eng_m_a_002.wav");
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[46];	
			link.l1.go = "prison_info7";		
		break;

		case "prison_info7":
			PlaySound("VOICE\ENGLISH\Eng_m_a_001.wav");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "prison_info8";
		break;

		case "prison_info8":
			PlaySound("VOICE\ENGLISH\Eng_m_a_003.wav");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "prison_info9";
		break;

		case "prison_info9":
			PlaySound("VOICE\ENGLISH\Eng_m_a_006.wav");
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "prison_info10";
		break;

		case "prison_info10":
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit_governor";
			AddDialogExitQuest("prison_info_done");
		break;

		case "neutral_clerk":
			PlaySound("VOICE\ENGLISH\Fre_m_b_011.wav");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit_clerk";
			AddDialogExitQuest("neutral_clerk_repeat");
		break;

		case "neutral_governor":
			PlaySound("VOICE\ENGLISH\Eng_m_a_004.wav");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit_governor";
			AddDialogExitQuest("neutral_governor_repeat");
		break;

		case "exit":
			LAi_SetPlayerType(Pchar);
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_clerk":
			LAi_SetPlayerType(Pchar);
			LAi_SetSitType(characterFromID("Maltese_red1"));
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_governor":
			LAi_SetPlayerType(Pchar);
			LAi_SetSitType(characterFromID("Maltese_governor"));
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
