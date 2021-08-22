
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

			PlaySound("VOICE\ENGLISH\Eng_m_c_005.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "2";
		break;
	
		case "2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_018.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "3";
		break;

		case "3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_001.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "4";
		break;

		case "4":
			PlaySound("VOICE\ENGLISH\Eng_m_c_003.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "5";
		break;

		case "5":
			PlaySound("VOICE\ENGLISH\Eng_m_c_055.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "6";
		break;

		case "6":
			PlaySound("VOICE\ENGLISH\Eng_m_c_031.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "7";
		break;
		
		case "7":
			PlaySound("VOICE\ENGLISH\Eng_m_c_002.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "8";
		break;

		case "8":
			PlaySound("VOICE\ENGLISH\Eng_m_c_026.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit_again";
			AddDialogExitQuest("Turks_mistress");
		break;
		
		case "again":
			PlaySound("VOICE\ENGLISH\Eng_m_c_004.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "again1";
		break;

		case "again1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_013.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit_neutral";
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\Eng_m_c_044.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit_neutral";
		break;

		case "Exit_again":
			DialogExit();
			Diag.CurrentNode = "again";
		break;

		case "Exit_neutral":
			DialogExit();
			Diag.CurrentNode = "neutral";
		break;
	}
}
