
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			
			if(CheckAttribute(Pchar,"quest.Dupin_work") && Pchar.quest.Dupin_work == "over")
			{
				PlaySound("VOICE\ENGLISH\Dupin_good_work.wav");
			}
			else  PlaySound("VOICE\ENGLISH\Dupin_help.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];

			if(CheckAttribute(Pchar,"quest.Dupin_pos") && Pchar.quest.Dupin_pos == "sit") 
			{ link.l1.go = "Exit_sit"; }
			if(CheckAttribute(Pchar,"quest.Dupin_pos") && Pchar.quest.Dupin_pos == "stay") 
			{ link.l1.go = "Exit_stay"; }
			
			Diag.TempNode = "first time";
		break;

		case "welcome":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sit2");
			PlaySound("VOICE\ENGLISH\Dupin_help.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "welcome1";
		break;

		case "welcome1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sit2");
			PlaySound("VOICE\ENGLISH\Dupin_know.wav");
			Dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "welcome2";
		break;

		case "welcome2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sit2");
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			Dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "welcome3";
		break;

		case "welcome3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sit2");
			PlaySound("VOICE\ENGLISH\Dupin_no_money.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "welcome4";
		break;

		case "welcome4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "sit2");
			PlaySound("VOICE\ENGLISH\Dupin_alright.wav");
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("Dupin_gives_kit");
		break;

	//------------------------------------------------------

		case "Dkit1_not_finished_yet":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("Dkit1_not_finished_yet");
		break;

		case "Dkit1_filled":
			PlaySound("VOICE\ENGLISH\Dupin_found_them.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			AddDialogExitQuest("Dupin_takes_kit");
		break;

		case "letter_A":
			PlaySound("VOICE\ENGLISH\Dupin_get_to_work.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "letter_A1";
		break;

		case "letter_A1":
			PlaySound("VOICE\ENGLISH\Dupin_help.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "letter_i_n";
		break;

		case "letter_i_n":
			AddQuestRecord("The_message","14");
			PlaySound("VOICE\ENGLISH\Dupin_alright.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "letter_i_n1";
		break;

		case "letter_i_n1":
			AddQuestRecord("The_message","15");
			PlaySound("VOICE\ENGLISH\Dupin_splendid.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit";
			AddDialogExitQuest("Dupin_checks_l_&_m_&_f");
		break;

		case "Dupin_letter_L":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			Dialog.text = DLG_TEXT[21];
			
			link.l1 = DLG_TEXT[22];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[25];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[26];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[27];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[28];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[29];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[30];
			link.l7.go = "Dupin_letter_M";
			link.l8 = DLG_TEXT[31];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[32];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[33];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[34];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[35];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[36];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[37];
			link.l14.go = "no_idea";
			link.l15 = DLG_TEXT[38];
			link.l15.go = "no_idea";
		break;

		case "no_idea":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("Dupin_checks_l_&_m_&_f");
		break;

		case "Dupin_letter_M":
	Pchar.quest.letter_L = "ok";
			AddQuestRecord("The_message","18");
			PlaySound("VOICE\ENGLISH\Dupin_alright.wav");
			Dialog.text = DLG_TEXT[39];
			
			link.l1 = DLG_TEXT[22];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[25];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[26];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[27];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[28];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[29];
			link.l6.go = "no_idea";
			link.l8 = DLG_TEXT[31];
			link.l8.go = "Dupin_letter_F";
			link.l9 = DLG_TEXT[32];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[33];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[34];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[35];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[36];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[37];
			link.l14.go = "no_idea";
			link.l15 = DLG_TEXT[38];
			link.l15.go = "no_idea";
		break;

		case "Dupin_letter_F":
			AddQuestRecord("The_message","19");
			PlaySound("VOICE\ENGLISH\Dupin_found_them.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Dupin_letter_Y";
		break;

		case "Dupin_letter_Y":
	Pchar.quest.letter_F = "ok";
			AddQuestRecord("The_message","16");
			PlaySound("VOICE\ENGLISH\Dupin_help.wav");
			Dialog.text = DLG_TEXT[42];
			
			link.l1 = DLG_TEXT[22];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[25];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[26];
			link.l3.go = "no_idea";
			link.l5 = DLG_TEXT[28];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[29];
			link.l6.go = "no_idea";
			link.l9 = DLG_TEXT[32];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[33];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[34];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[35];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[36];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[37];
			link.l14.go = "Dupin_letter_Y_ok";
			link.l15 = DLG_TEXT[38];
			link.l15.go = "no_idea";
		
		break;

		case "Dupin_letter_Y_ok":
			PlaySound("VOICE\ENGLISH\Dupin_good_work.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Dupin_exchange_papers";
		break;

		case "Dupin_exchange_papers":
			PlaySound("INTERFACE\paper.wav");
			TakenItems(Pchar, "crypto1", 1);
			TakenItems(NPchar, "crypto1", -1);
	
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Dupins_work_over";

			LAi_QuestDelay("Dupin_pardon", 1.5);
		break;

		case "Dupins_work_over":
			PlaySound("INTERFACE\paper.wav");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakenItems(Pchar, "bladecrypto_cl", -1);
			EquipCharacterByItem(Pchar, "bladeX4");
			TakenItems(NPchar, "bladecrypto_cl", 1);
			EquipCharacterByItem(NPchar, "bladecrypto_cl");

			LAi_QuestDelay("Dupin_good_day", 1.5);

			Pchar.quest.Dupin_work = "over";
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("Dupins_work_over");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_stay":
			LAi_SetStayType(NPchar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_sit":
			LAi_SetSitType(NPchar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
