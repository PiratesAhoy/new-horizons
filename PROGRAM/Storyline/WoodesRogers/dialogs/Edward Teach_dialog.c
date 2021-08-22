
void ProcessDialogEvent()
{
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
		break;

		if(Pchar.location == "BB_Hornigold_shore") ChangeCharacterAddressGroup(Pchar, "BB_Hornigold_shore", "goto", "bb4");
		if(Pchar.location == "BB_sloop") ChangeCharacterAddressGroup(Pchar, "BB_sloop", "quest", "listen");

		case "separate_way":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore3_A");
		break;
	
		case "keep_the_ship":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore6");
		break;

		case "gives_map":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore7_B");
		break;

		case "give_me_your_pistol":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore10");
		break;

		case "officers_over_here":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore17");
		break;

	//-----------------------------------------------------------------------------------------------

		case "Caesar1":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("fake_Caesar"));

			PlaySound("VOICE\ENGLISH\gr_Teach6.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_sloop6");
		break;

		case "Caesar2":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("fake_Caesar"));

			PlaySound("VOICE\ENGLISH\gr_Teach8.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_sloop8");
		break;

		case "Caesar3":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("fake_Caesar"));

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_sloop10");
		break;

		case "Caesar4":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("fake_Caesar"));

			PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_sloop19");
		break;

		case "Hands_please":
			LAi_ActorTurnToLocator(characterFromID("Teach"), "goto", "Teach_look");

			PlaySound("VOICE\ENGLISH\gr_Teach5.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene3");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_neutral_done");
		break;
	
		case "bribing":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			ChangeCharacterAddressGroup(characterFromID("Richards"), "BB_Eden_office", "goto", "richards");
			ChangeCharacterAddressGroup(characterFromID("bb_crew8"), "BB_Eden_office", "goto", "qm");
			ChangeCharacterAddressGroup(characterFromID("bb_crew5"), "BB_Eden_office", "goto", "gunner");

			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene17");
		break;

		case "bribing2":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene19");
		break;

		case "bribing4":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene21");
		break;
	
		case "bribing7":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene26");
		break;

		case "bribing9":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach8.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene31");
		break;

		case "bribing12":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene36");
		break;

		case "bribing14":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));
			LAi_ActorTurnToCharacter(characterFromID("bb_crew8"), characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach11.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene39");
		break;
	
		case "bribing15":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Knight"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Knight"));
			LAi_ActorTurnToCharacter(characterFromID("Knight"), characterFromID("Eden"));

			PlaySound("VOICE\ENGLISH\gr_Teach5.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene42");
		break;

		case "I_shot_you":
			LAi_SetPoorType(Pchar);
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Hands_shot_scene37");
		break;

		case "You_help_him":
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);
			LAi_SetActorType(characterFromID("Teach"));
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Bonnet"));
			PlaySound("VOICE\ENGLISH\pir_capR9.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "I_saved_him";
		break;

		case "I_saved_him":
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("Hands_shot_scene41");
		break;

		case "Teach_tavern":
			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
		//	PlaySound("VOICE\ENGLISH\Eden_so.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Teach_tavern1";
		break;

		case "Teach_tavern1":
			PlaySound("VOICE\ENGLISH\gr_Teach13.wav");
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Teach_tavern2";
		break;

		case "Teach_tavern2":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Teach_tavern3";
		break;

		case "Teach_tavern3":
			PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Teach_tavern4";
		break;

		case "Teach_tavern4":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Teach_tavern5";
		break;

		case "Teach_tavern5":
			PlaySound("VOICE\ENGLISH\gr_Teach14.wav");
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Teach_tavern6";
		break;

		case "Teach_tavern6":
			PlaySound("VOICE\ENGLISH\pir_capR4.wav");
			Dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Teach_tavern7";
		break;

		case "Teach_tavern7":
			PlaySound("VOICE\ENGLISH\gr_Teach12.wav");
			Dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Teach_tavern8";
		break;

		case "Teach_tavern8":
			AddQuestRecord("Blackbeards_tower","8");

			PlaySound("VOICE\ENGLISH\gr_Teach11.wav");
			Dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Teach_tavern9";
		break;

		case "Teach_tavern9":
			PlaySound("VOICE\ENGLISH\gr_Teach8.wav");
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("defoe_map15");
		break;

		case "Teach_tavern10":
			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("defoe_map20");
		break;

		case "Teach_tavern11":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "Teach_tavern12";
		break;

		case "Teach_tavern12":
			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			Dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("defoe_map25");
		break;

		case "babble_or_drink":
			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			Dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("Hands_shot_sceneB");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
