
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

			if(NPChar.id == "maroon1") PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			if(NPChar.id == "maroon2") PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			if(NPChar.id == "maroon3") PlaySound("VOICE\ENGLISH\pir_capP.wav");
			if(NPChar.id == "maroon4") PlaySound("VOICE\ENGLISH\pir_capQ.wav");			
			if(NPChar.id == "maroon5") PlaySound("VOICE\ENGLISH\pir_capC.wav");						
			if(NPChar.id == "maroon_girl") PlaySound("VOICE\ENGLISH\gm_crew12A.wav");
			if(NPChar.id == "indian_bandit") PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			if(NPChar.id == "hunter_bandit") PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			if(NPChar.id == "deserter_us1") PlaySound("VOICE\ENGLISH\pir_capI.wav");
			if(NPChar.id == "deserter_us2") PlaySound("VOICE\ENGLISH\pir_capM.wav");					
			if(NPChar.id == "white_trash1") PlaySound("VOICE\ENGLISH\gr_Richards.wav");
			if(NPChar.id == "white_trash2") PlaySound("VOICE\ENGLISH\pir_capAAA.wav");
			if(NPChar.id == "mystery_monk") PlaySound("VOICE\ENGLISH\pir_capB.wav");	
			 
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";

			Diag.TempNode = "First time";
		break;

		case "return1":
			PlaySound("VOICE\ENGLISH\pir_capF.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "return1_A";
		break;

		case "return1_A":
			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "return1_B";
		break;

		case "return1_B":
			PlaySound("VOICE\ENGLISH\pir_capBB.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("maroon_stop1");
		break;

		case "return1_C":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("maroon_stop3");
		break;

		case "pay_or_die":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "pay_or_die1";
		break;

		case "pay_or_die1":
			PlaySound("VOICE\ENGLISH\pir_capCC.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "pay_or_die2";
		break;

		case "pay_or_die2":
			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("hidden_maroons6");
		break;	

		case "stay_or_die":
			PlaySound("VOICE\ENGLISH\pir_capBB.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("hidden_maroons7C");
		break;					

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
