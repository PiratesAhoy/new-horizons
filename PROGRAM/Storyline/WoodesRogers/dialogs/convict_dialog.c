
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

			if(NPChar.id == "car_convict5") PlaySound("VOICE\ENGLISH\gm_crew7.wav");	//indian_bandit
			if(NPChar.id == "car_convict2") PlaySound("VOICE\ENGLISH\gm_crew16A.wav");	//hunter_bandit
			if(NPChar.id == "car_convict3") PlaySound("VOICE\ENGLISH\gm_crew1A.wav");	//deserter_us2	(swedish)					
			if(NPChar.id == "car_convict1") PlaySound("VOICE\ENGLISH\Thug.wav");		//white_trash1
			if(NPChar.id == "car_convict4") PlaySound("VOICE\ENGLISH\Barbossa01.wav");	//white_trash2
			if(NPChar.id == "car_convict6") PlaySound("VOICE\ENGLISH\pir_capP.wav");	//mystery_monk	(what are you doing here)
			 
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			Diag.TempNode = "First time";
		break;
	//Peter Blood
		case "doctor":
			PlaySound("VOICE\ENGLISH\ayay_captain.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck17");
		break;

		case "yes_doctor":
			PlaySound("VOICE\ENGLISH\pir_capB.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "yes_doctor1";
		break;

		case "yes_doctor1":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "yes_doctor2";
		break;

		case "yes_doctor2":
			PlaySound("VOICE\ENGLISH\pir_capP.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck18A");
		break;
		
		case "Blood":
			PlaySound("VOICE\ENGLISH\pir_capQ.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck21");
		break;

		case "hidden_face":
			PlaySound("VOICE\ENGLISH\gr_Richards.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck23");
		break;

		case "no_water":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck26");
		break;

	//Gunnar
		case "swedish_language":
			PlaySound("VOICE\ENGLISH\gm_crew1C.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck37");
		break;

	//Sergio
		case "italian":
			PlaySound("VOICE\ENGLISH\Ita_m_a_003.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "italian1";
		break;

		case "italian1":
			PlaySound("VOICE\ENGLISH\Ita_m_a_001.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona17");
		break;
	//Gunnar
		case "french_ship_name":
			PlaySound("VOICE\ENGLISH\gm_crew1A.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "french_ship_name1";
		break;

		case "french_ship_name1":
			PlaySound("VOICE\ENGLISH\gm_crew1B.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona34");
		break;

		case "privateer":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPChar, characterFromID("Walter"));
			LAi_SetActorType(characterFromID("Walter"));
			LAi_ActorTurnToCharacter(characterFromID("Walter"), NPChar);
			LAi_SetActorType(characterFromID("Hilphershausen"));
			LAi_ActorTurnToCharacter(characterFromID("Hilphershausen"), NPChar);


			PlaySound("VOICE\ENGLISH\gm_crew1C.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona37");
		break;

		case "neutral_Gunnar":
			PlaySound("VOICE\ENGLISH\gm_crew1C.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_Gunnar";
		break;

		case "neutral_Sergio":
			PlaySound("VOICE\ENGLISH\Ita_m_a_001.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_Sergio";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
