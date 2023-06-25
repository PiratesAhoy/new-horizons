
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
			
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			if(Pchar.model == "William Legrand") 
			{
				Dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
			}	
			if(Pchar.model == "Jupiter") 		
			{
				if(Pchar.location == "Moultrie_restaurant")
				{
					LAi_SetActorType(NPchar);
					LAi_ActorTurnToCharacter(NPchar, PChar);
				} 

				if(CheckAttribute(Pchar,"quest.Jupiter_bug_mission") && Pchar.quest.Jupiter_bug_mission == "on")
				{
					Pchar.quest.Jupiter_bug_mission = "off";
					Dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "return_goldbug";
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.Jupiter_bug_mission") && Pchar.quest.Jupiter_bug_mission == "spyglass")
					{
						Dialog.text = DLG_TEXT[63];
						link.l1 = DLG_TEXT[64];
						link.l1.go = "exit";
						AddDialogExitQuest("about_flag_done1");
					}
				}
				else
				{
					Dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit_restaurant";
				}
			}

			Diag.TempNode = "first time";
		break;

		case "borrow_goldbug":
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "borrow_goldbug2";
		break;

		case "borrow_goldbug2":
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "borrow_goldbug3";
		break;

		case "borrow_goldbug3":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("G_takes_bug");
		break;

		case "return_goldbug":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit_restaurant";
			AddDialogExitQuest("G_returns_bug");
		break;

		case "key7":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload7");
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "key7_1";
		break;

		case "key7_1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload7");
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "key7_2";
		break;

		case "key7_2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload7");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "key7_3";
		break;

		case "key7_3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload7");
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "key7_4";
		break;

		case "key7_4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload7");
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("key7_given");
		break;

		case "med_bag":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("no_idea_done");
		break;

		case "book53":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("no_idea_done");
		break;

		case "letter_E":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[29];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[31];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[32];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[33];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[34];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[35];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[36];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[37];
			link.l10.go = "letter_T";
			link.l11 = DLG_TEXT[38];
			link.l11.go = "no_idea";

			link.l12 = DLG_TEXT[39];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[40];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[41];
			link.l14.go = "no_idea";
			link.l15 = DLG_TEXT[42];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[43];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[44];
			link.l17.go = "no_idea";
			link.l18 = DLG_TEXT[45];
			link.l18.go = "no_idea";
			link.l19 = DLG_TEXT[46];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[47];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[48];
			link.l21.go = "no_idea";
		break;

		case "no_idea":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_have_to_try.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("no_idea_done");
		break;
	
		case "letter_T":
	Pchar.quest.letter_E = "ok";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_good_work.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[29];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[31];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[32];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[33];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[34];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[35];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[36];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[37];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[38];
			link.l11.go = "no_idea";

			link.l12 = DLG_TEXT[39];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[40];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[41];
			link.l14.go = "no_idea";
			link.l15 = DLG_TEXT[42];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[43];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[44];
			link.l17.go = "letter_H";
			link.l18 = DLG_TEXT[45];
			link.l18.go = "no_idea";
			link.l19 = DLG_TEXT[46];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[47];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[48];
			link.l21.go = "no_idea";
		break;

		case "letter_H":
	Pchar.quest.letter_T = "ok";

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_you_could.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[29];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[31];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[32];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[33];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[34];
			link.l7.go = "H_ok";
			link.l8 = DLG_TEXT[35];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[36];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[37];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[38];
			link.l11.go = "no_idea";

			link.l12 = DLG_TEXT[39];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[40];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[41];
			link.l14.go = "no_idea";
			link.l15 = DLG_TEXT[42];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[43];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[44];
			link.l17.go = "no_idea";
			link.l18 = DLG_TEXT[45];
			link.l18.go = "no_idea";
			link.l19 = DLG_TEXT[46];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[47];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[48];
			link.l21.go = "no_idea";
		break;
	
		case "H_ok":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "return_book52";
		break;

		case "return_book52":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto5");
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			AddDialogExitQuest("THE_ok");
		break;

		case "about_flag":
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "about_flag1";
		break;

		case "about_flag1":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "about_flag2";
		break;

		case "about_flag2":
			PlaySound("VOICE\ENGLISH\G_have_to_try.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			AddDialogExitQuest("about_flag_done");
		break;

		case "visit3":
			Pchar.quest.Fort_visit = "neutral";
			PlaySound("VOICE\ENGLISH\G_hey_now.wav");
			Dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			AddDialogExitQuest("visit3_done");
		break;

		case "visit3_A":
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "visit3_B";
		break;

		case "visit3_B":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			Dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "visit3_C";
		break;

		case "visit3_C":
			PlaySound("VOICE\ENGLISH\G_have_to_try.wav");
			Dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "visit3_D";
		break;

		case "visit3_D":
			PlaySound("VOICE\ENGLISH\G_you_could.wav");
			Dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "visit3_E";
		break;

		case "visit3_E":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			Dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "visit3_F";
		break;

		case "visit3_F":
			PlaySound("VOICE\ENGLISH\G_tell_you_what.wav");
			Dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("visit3_F_done");
		break;


		case "Exit_restaurant":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			
			ChangeCharacterAddressGroup(NPchar, "Moultrie_restaurant", "sit", "sit1");
			LAi_SetSitType(NPchar);
		break;

		case "Exit":
			Pchar.Lhouse_box1 = "free";
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
