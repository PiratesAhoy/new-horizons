
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
			
			PlaySound("VOICE\ENGLISH\jrh_5.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_stay";
			
			Diag.TempNode = "first time";
		break;

		case "start":
			PlaySound("VOICE\ENGLISH\jrh_5.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "start1";
		break;

		case "start1":
			PlaySound("VOICE\ENGLISH\jrh_4.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Fersen_letter_V";
		break;

		case "Fersen_letter_V":
			PlaySound("VOICE\ENGLISH\jrh_6.wav");
			Dialog.text = DLG_TEXT[4];
			
			link.l1 = DLG_TEXT[5];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[8];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[9];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[10];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[11];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[12];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[13];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[14];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[15];
			link.l9.go = "Fersen_letter_B";
			link.l10 = DLG_TEXT[16];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[17];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[18];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[19];
			link.l13.go = "no_idea";
		break;

		case "no_idea":
			PlaySound("VOICE\ENGLISH\jrh_2.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("Fersen_checks_v_&_b_&_p_&_c");
		break;

		case "Fersen_letter_B":
	Pchar.quest.letter_V = "ok";
			AddQuestRecord("The_message","20");
			PlaySound("VOICE\ENGLISH\jrh_4.wav");
			Dialog.text = DLG_TEXT[20];
			
			link.l1 = DLG_TEXT[5];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[8];
			link.l2.go = "Fersen_letter_P";
			link.l3 = DLG_TEXT[9];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[10];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[11];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[12];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[13];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[14];
			link.l8.go = "no_idea";
			link.l10 = DLG_TEXT[16];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[17];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[18];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[19];
			link.l13.go = "no_idea";
		break;

		case "Fersen_letter_P":
	Pchar.quest.letter_B = "ok";
			AddQuestRecord("The_message","21");
			PlaySound("VOICE\ENGLISH\jrh_7.wav");
			Dialog.text = DLG_TEXT[21];
			
			link.l1 = DLG_TEXT[5];
			link.l1.go = "no_idea";
			
			link.l3 = DLG_TEXT[9];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[10];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[11];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[12];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[13];
			link.l7.go = "Fersen_letter_C";
			link.l8 = DLG_TEXT[14];
			link.l8.go = "no_idea";
			link.l10 = DLG_TEXT[16];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[17];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[18];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[19];
			link.l13.go = "no_idea";
		break;

		case "Fersen_letter_C":
	Pchar.quest.letter_P = "ok";
			AddQuestRecord("The_message","22");
			PlaySound("VOICE\ENGLISH\jrh_8.wav");
			Dialog.text = DLG_TEXT[22];
			
			link.l1 = DLG_TEXT[5];
			link.l1.go = "no_idea";
			
			link.l3 = DLG_TEXT[9];
			link.l3.go = "Fersen_all_letters_ok";
			link.l4 = DLG_TEXT[10];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[11];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[12];
			link.l6.go = "no_idea";
			link.l8 = DLG_TEXT[14];
			link.l8.go = "no_idea";
			link.l10 = DLG_TEXT[16];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[17];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[18];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[19];
			link.l13.go = "no_idea";
		break;

		case "Fersen_all_letters_ok":
	Pchar.quest.letter_C = "ok";
			AddQuestRecord("The_message","23");
			PlayStereoSound("Ambient\SEASHORE\fanfare.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_stay";

			AddDialogExitQuest("Fersens_work_over");
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
